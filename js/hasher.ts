import { ByteBuffer } from './bb'

class HashHelper {
  private _float: Float32Array
  private _int: Int32Array
  private _value: number

  constructor() {
    this._float = new Float32Array(1)
    this._int = new Int32Array(this._float.buffer)
    this._value = 0
  }

  reset(): void {
    this._value = 0
  }

  value(): number {
    return this._value
  }

  hashStr(value: string) {
    for (var i = 0; i < value.length; ++i) {
      this.hashI(value.codePointAt(i) || 0)
    }
  }

  hashBool(value: boolean) {
    this.hashI(value ? 1 : 0)
  }

  hashBytes(bytes: Uint8Array) {
    for (var i = 0; i < bytes.length; ++i) {
      this.hashI(bytes[i])
    }
  }

  hashF(value: number) {
    this._float[0] = value
    this._value = this._combine(this._value, this._int[0])
  }

  hashI(value: number) {
    this._value = this._combine(this._value, value)
  }

  // `a` and `b` must be both ints
  private _combine(a: number, b: number): number {
    return b + 0x9e3779b9 + (a << 6) + (a >> 2)
  }
}

export class Hasher {
  private _helper: HashHelper
  private _bb: ByteBuffer
  constructor(bb: ByteBuffer) {
    this._helper = new HashHelper()
    this._bb = bb
  }

  bb(): ByteBuffer {
    return this._bb
  }

  windowToUint8Array(): Uint8Array {
    return this._bb.windowToUint8Array()
  }

  value(): number {
    return this._helper.value()
  }

  readByte(): number {
    const res = this._bb.readByte()
    this._helper.hashI(res)
    return res
  }

  readByteArray(): Uint8Array {
    const res = this._bb.readByteArray()
    this._helper.hashBytes(res)
    return res
  }

  readVarFloat(): number {
    const res = this._bb.readVarFloat()
    this._helper.hashF(res)
    return res
  }

  // This is used for field indices and array lengths when reading
  readVarUint(): number {
    const res = this._bb.readVarUint()
    this._helper.hashI(res)
    return res
  }

  readVarInt(): number {
    const res = this._bb.readVarInt()
    this._helper.hashI(res)
    return res
  }

  readVarUint64(): string {
    const res = this._bb.readVarUint64()
    this._helper.hashStr(res)
    return res
  }

  readVarInt64(): string {
    const res = this._bb.readVarInt64()
    this._helper.hashStr(res)
    return res
  }

  readString(): string {
    const res = this._bb.readString()
    this._helper.hashStr(res)
    return res
  }
}
