let int32 = new Int32Array(1)
let float32 = new Float32Array(int32.buffer)

export class ByteBuffer {
  private _data: Uint8Array
  private _start: number
  private _index: number
  length: number

  constructor(data?: Uint8Array) {
    if (data && !(data instanceof Uint8Array)) {
      throw new Error('Must initialize a ByteBuffer with a Uint8Array')
    }
    this._data = data || new Uint8Array(256)
    this._index = 0
    this._start = 0
    this.length = data ? data.length : 0
  }

  extendWindowTo(bb: ByteBuffer): void {
    this._index = bb._index
  }

  getNewWindowFromRight(): ByteBuffer {
    const bb = new ByteBuffer(this._data)
    bb._index = this._index
    bb._start = this._index
    return bb
  }

  windowToUint8Array(): Uint8Array {
    return this._data.subarray(this._start, this._index)
  }

  toUint8Array(): Uint8Array {
    return this._data.subarray(0, this.length)
  }

  ////////////////////////////////////////////////
  // All `read` methods below extend the window
  // by the size of the type being read
  ////////////////////////////////////////////////

  readByte(): number {
    if (this._index + 1 > this._data.length) {
      throw new Error('Index out of bounds')
    }
    return this._data[this._index++]
  }

  readByteArray(): Uint8Array {
    let length = this.readVarUint()
    let start = this._index
    let end = start + length
    if (end > this._data.length) {
      throw new Error('Read array out of bounds')
    }
    this._index = end
    // Copy into a new array instead of just creating another view.
    let result = new Uint8Array(length)
    result.set(this._data.subarray(start, end))
    return result
  }

  readVarFloat(): number {
    let index = this._index
    let data = this._data
    let length = data.length

    // Optimization: use a single byte to store zero
    if (index + 1 > length) {
      throw new Error('Index out of bounds')
    }
    let first = data[index]
    if (first === 0) {
      this._index = index + 1
      return 0
    }

    // Endian-independent 32-bit read
    if (index + 4 > length) {
      throw new Error('Index out of bounds')
    }
    let bits = first | (data[index + 1] << 8) | (data[index + 2] << 16) | (data[index + 3] << 24)
    this._index = index + 4

    // Move the exponent back into place
    bits = (bits << 23) | (bits >>> 9)

    // Reinterpret as a floating-point number
    int32[0] = bits
    return float32[0]
  }

  readVarUint(): number {
    let value = 0
    let shift = 0
    do {
      var byte = this.readByte()
      value |= (byte & 127) << shift
      shift += 7
    } while (byte & 128 && shift < 35)
    return value >>> 0
  }

  readVarInt(): number {
    let value = this.readVarUint() | 0
    return value & 1 ? ~(value >>> 1) : value >>> 1
  }

  private readVarUint64Bin(): string {
    let byteCount = 0
    let binStr = ''
    do {
      var byte = this.readByte()
      if (byteCount < 8) {
        let tempBin = ((byte & 127) >>> 0).toString(2)
        binStr = (byte & 128 ? tempBin.padStart(7, '0') : tempBin) + binStr
      } else {
        binStr = byte.toString(2) + binStr
        break
      }
      byteCount += 1
    } while (byte & 128)
    return binStr
  }

  readVarUint64(): string {
    return this.convertBase(this.readVarUint64Bin(), 2, 10)
  }

  // see encoding strategy at writeVarInt64()– this function does the opposite
  readVarInt64(): string {
    let binValue = this.readVarUint64Bin()
    if (binValue.slice(-1) == '1') {
      let binArr = this.parseToDigitsArray(binValue.slice(0, -1), 2)
      binArr = this.add(binArr, [1], 2)
      return '-' + this.convertBase(this.parseFromDigitsArray(binArr, 2), 2, 10)
    } else {
      return this.convertBase(binValue.slice(0, -1), 2, 10)
    }
  }

  readString(): string {
    let result = ''

    while (true) {
      let codePoint

      // Decode UTF-8
      let a = this.readByte()
      if (a < 0xc0) {
        codePoint = a
      } else {
        let b = this.readByte()
        if (a < 0xe0) {
          codePoint = ((a & 0x1f) << 6) | (b & 0x3f)
        } else {
          let c = this.readByte()
          if (a < 0xf0) {
            codePoint = ((a & 0x0f) << 12) | ((b & 0x3f) << 6) | (c & 0x3f)
          } else {
            let d = this.readByte()
            codePoint = ((a & 0x07) << 18) | ((b & 0x3f) << 12) | ((c & 0x3f) << 6) | (d & 0x3f)
          }
        }
      }

      // Strings are null-terminated
      if (codePoint === 0) {
        break
      }

      // Encode UTF-16
      if (codePoint < 0x10000) {
        result += String.fromCharCode(codePoint)
      } else {
        codePoint -= 0x10000
        result += String.fromCharCode((codePoint >> 10) + 0xd800, (codePoint & ((1 << 10) - 1)) + 0xdc00)
      }
    }

    return result
  }

  private _growBy(amount: number): void {
    if (this.length + amount > this._data.length) {
      let data = new Uint8Array((this.length + amount) << 1)
      data.set(this._data)
      this._data = data
    }
    this.length += amount
  }

  writeByte(value: number): void {
    let index = this.length
    this._growBy(1)
    this._data[index] = value
  }

  writeByteArray(value: Uint8Array): void {
    this.writeVarUint(value.length)
    let index = this.length
    this._growBy(value.length)
    this._data.set(value, index)
  }

  writeVarFloat(value: number): void {
    let index = this.length

    // Reinterpret as an integer
    float32[0] = value
    let bits = int32[0]

    // Move the exponent to the first 8 bits
    bits = (bits >>> 23) | (bits << 9)

    // Optimization: use a single byte to store zero and denormals (check for an exponent of 0)
    if ((bits & 255) === 0) {
      this.writeByte(0)
      return
    }

    // Endian-independent 32-bit write
    this._growBy(4)
    let data = this._data
    data[index] = bits
    data[index + 1] = bits >> 8
    data[index + 2] = bits >> 16
    data[index + 3] = bits >> 24
  }

  writeVarUint(value: number): void {
    do {
      let byte = value & 127
      value >>>= 7
      this.writeByte(value ? byte | 128 : byte)
    } while (value)
  }

  writeVarInt(value: number): void {
    this.writeVarUint((value << 1) ^ (value >> 31))
  }

  private writeVarUint64Helper(binValue: string): void {
    if (!binValue) {
      return
    }
    var byteCount = 0
    do {
      if (byteCount < 8) {
        var byte = parseInt(binValue.slice(-7), 2)
        binValue = binValue.slice(0, -7)
      } else {
        var byte = parseInt(binValue.slice(-8), 2)
        binValue = binValue.slice(0, -8)
        this.writeByte(byte)
        break
      }
      this.writeByte(binValue ? byte | 128 : byte)
      byteCount += 1
    } while (binValue)
  }

  writeVarUint64(value: string): void {
    value = this.cleanNumericString(value)
    let binValue = this.convertBase(value, 10, 2)
    this.writeVarUint64Helper(binValue)
  }

  // Given a binary string, this subtract 1 and return result
  private subtractOne(digits: string): string {
    let borrow = 1
    const result = digits.split('').map(Number)
    for (let i = result.length - 1; i >= 0; i--) {
      if (result[i] < borrow) {
        result[i] = 1
      } else {
        result[i]--
        borrow = 0
        break
      }
    }
    return result.join('').replace(/^0+/, '') // Removes extra prefixed zeroes
  }

  private cleanNumericString(value: string): string {
    let numericString = ''
    for (let i = 0; i < value.length; i++) {
      const char = value.charAt(i)
      if ((char >= '0' && char <= '9') || (i === 0 && char === '-')) {
        numericString += char
      }
    }
    return numericString
  }

  // Variable length encoding is done as follows
  // Move the sign bit to the RHS
  // If value is negative, flip all the bits (except sign bit) and subtract 2 (to skip over the sign bit on the right)
  writeVarInt64(value: string): void {
    value = this.cleanNumericString(value)
    if (value == '') {
      return // FLAG error
    }
    if (value[0] != '-') {
      var binValue = this.convertBase(value, 10, 2) + '0'
    } else {
      var binValue = this.convertBase(value.slice(1), 10, 2)
      if (binValue == '0' || binValue == '') {
        this.writeVarUint64('0')
        return
      }
      binValue = this.subtractOne(binValue) + '1'
    }
    this.writeVarUint64Helper(binValue)
  }

  // add(), multiplyByNumber(), parseToDigitsArray(), parseFromDigitsArray(), are all helper functions for convertBase()
  private add(x: number[], y: number[], base: number): number[] {
    const z: number[] = []
    const n = Math.max(x.length, y.length)
    let carry = 0
    let i = 0
    while (i < n || carry) {
      const xi = i < x.length ? x[i] : 0
      const yi = i < y.length ? y[i] : 0
      const zi = carry + xi + yi
      z.push(zi % base)
      carry = Math.floor(zi / base)
      i++
    }
    return z
  }

  private multiplyByNumber(num: number, x: number[], base: number): number[] {
    if (num < 0) return []
    if (num === 0) return []

    let result: number[] = []
    let power = x
    while (true) {
      if (num & 1) {
        result = this.add(result, power, base)
      }
      num = num >> 1
      if (num === 0) break
      power = this.add(power, power, base)
    }

    return result
  }

  private parseToDigitsArray(str: string, base: number): number[] {
    const digits = str.toString().split('')
    const ary: number[] = []
    for (let i = digits.length - 1; i >= 0; i--) {
      const n = parseInt(digits[i], base)
      if (isNaN(n)) return []
      ary.push(n)
    }
    return ary
  }

  private parseFromDigitsArray(arr: number[], base: number): string {
    let out = ''
    for (let i = arr.length - 1; i >= 0; i--) {
      out += arr[i].toString(base)
    }
    return out
  }

  // Used to help convert numerical strings between bases.
  // This is a necessary step when encoding 64bit int js strings into a byte buffer
  private convertBase(str: string, fromBase: number, toBase: number): string {
    const digits = this.parseToDigitsArray(str, fromBase)
    if (digits === null) return ''

    let outArray: number[] = [0]
    let power: number[] = [1]
    for (let i = 0; i < digits.length; i++) {
      if (digits[i]) {
        outArray = this.add(outArray, this.multiplyByNumber(digits[i], power, toBase), toBase)
      }
      power = this.multiplyByNumber(fromBase, power, toBase)
    }
    return this.parseFromDigitsArray(outArray, toBase)
  }

  writeString(value: string): void {
    let codePoint

    for (let i = 0; i < value.length; i++) {
      // Decode UTF-16
      let a = value.charCodeAt(i)
      if (i + 1 === value.length || a < 0xd800 || a >= 0xdc00) {
        codePoint = a
      } else {
        let b = value.charCodeAt(++i)
        codePoint = (a << 10) + b + (0x10000 - (0xd800 << 10) - 0xdc00)
      }

      // Strings are null-terminated
      if (codePoint === 0) {
        throw new Error('Cannot encode a string containing the null character')
      }

      // Encode UTF-8
      if (codePoint < 0x80) {
        this.writeByte(codePoint)
      } else {
        if (codePoint < 0x800) {
          this.writeByte(((codePoint >> 6) & 0x1f) | 0xc0)
        } else {
          if (codePoint < 0x10000) {
            this.writeByte(((codePoint >> 12) & 0x0f) | 0xe0)
          } else {
            this.writeByte(((codePoint >> 18) & 0x07) | 0xf0)
            this.writeByte(((codePoint >> 12) & 0x3f) | 0x80)
          }
          this.writeByte(((codePoint >> 6) & 0x3f) | 0x80)
        }
        this.writeByte((codePoint & 0x3f) | 0x80)
      }
    }

    // Strings are null-terminated
    this.writeByte(0)
  }
}
