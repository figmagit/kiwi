var assert = require('assert')
var kiwi = require(__dirname + '/../js/kiwi')
var fs = require('fs')

var schemaText = fs.readFileSync(__dirname + '/test-schema.kiwi', 'utf8')
var schema = kiwi.compileSchema(kiwi.parseSchema(schemaText))

it('struct bool', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeBoolStruct({ x: i })), Buffer(o))
    assert.deepEqual(schema.decodeBoolStruct(new Uint8Array(o)), { x: i })
  }

  check(false, [0])
  check(true, [1])
})

it('struct byte', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeByteStruct({ x: i })), Buffer(o))
    assert.deepEqual(schema.decodeByteStruct(new Uint8Array(o)), { x: i })
  }

  check(0x00, [0x00])
  check(0x01, [0x01])
  check(0x7f, [0x7f])
  check(0x80, [0x80])
  check(0xff, [0xff])
})

it('struct uint', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeUintStruct({ x: i })), Buffer(o))
    assert.deepEqual(schema.decodeUintStruct(new Uint8Array(o)), { x: i })
  }

  check(0x00, [0x00])
  check(0x01, [0x01])
  check(0x02, [0x02])
  check(0x7f, [0x7f])
  check(0x80, [0x80, 0x01])
  check(0x81, [0x81, 0x01])
  check(0x100, [0x80, 0x02])
  check(0x101, [0x81, 0x02])
  check(0x17f, [0xff, 0x02])
  check(0x180, [0x80, 0x03])
  check(0x1ff, [0xff, 0x03])
  check(0x200, [0x80, 0x04])
  check(0x7fff, [0xff, 0xff, 0x01])
  check(0x8000, [0x80, 0x80, 0x02])
  check(0x7fffffff, [0xff, 0xff, 0xff, 0xff, 0x07])
  check(0x80000000, [0x80, 0x80, 0x80, 0x80, 0x08])
})

it('struct int', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeIntStruct({ x: i })), Buffer(o))
    assert.deepEqual(schema.decodeIntStruct(new Uint8Array(o)), { x: i })
  }

  check(0x00, [0x00])
  check(-0x01, [0x01])
  check(0x01, [0x02])
  check(-0x02, [0x03])
  check(0x02, [0x04])
  check(-0x3f, [0x7d])
  check(0x3f, [0x7e])
  check(-0x40, [0x7f])
  check(0x40, [0x80, 0x01])
  check(-0x3fff, [0xfd, 0xff, 0x01])
  check(0x3fff, [0xfe, 0xff, 0x01])
  check(-0x4000, [0xff, 0xff, 0x01])
  check(0x4000, [0x80, 0x80, 0x02])
  check(-0x3fffffff, [0xfd, 0xff, 0xff, 0xff, 0x07])
  check(0x3fffffff, [0xfe, 0xff, 0xff, 0xff, 0x07])
  check(-0x40000000, [0xff, 0xff, 0xff, 0xff, 0x07])
  check(0x40000000, [0x80, 0x80, 0x80, 0x80, 0x08])
  check(-0x7fffffff, [0xfd, 0xff, 0xff, 0xff, 0x0f])
  check(0x7fffffff, [0xfe, 0xff, 0xff, 0xff, 0x0f])
  check(-0x80000000, [0xff, 0xff, 0xff, 0xff, 0x0f])
})

it('struct uint64', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeUint64Struct({ x: i })), Buffer(o))
    assert.deepEqual(schema.decodeUint64Struct(new Uint8Array(o)), { x: i })
  }

  check("0", [0x00])
  check("1", [0x01])
  check("2", [0x02])
  check("127", [0x7f])
  check("128", [0x80, 0x01])
  check("129", [0x81, 0x01])
  check("256", [0x80, 0x02])
  check("257", [0x81, 0x02])
  check("383", [0xff, 0x02])
  check("384", [0x80, 0x03])
  check("511", [0xff, 0x03])
  check("512", [0x80, 0x04])
  check("32767", [0xff, 0xff, 0x01])
  check("32768", [0x80, 0x80, 0x02])
  check("2147483647", [0xff, 0xff, 0xff, 0xff, 0x07])
  check("2147483648", [0x80, 0x80, 0x80, 0x80, 0x08])
  check("18446744073709551615", [0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff])
})

it('struct int64', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeInt64Struct({ x: i })), Buffer(o))
    assert.deepEqual(schema.decodeInt64Struct(new Uint8Array(o)), { x: i })
  }

  check("0", [0x00])
  check("-1", [0x01])
  check("1", [0x02])
  check("-2", [0x03])
  check("2", [0x04])
  check("63", [0x7e])
  check("-63", [0x7d])
  check("-64", [0x7f])
  check("64", [0x80, 0x01])
  check("-16383", [0xfd, 0xff, 0x01])
  check("16383", [0xfe, 0xff, 0x01])
  check("-16384", [0xff, 0xff, 0x01])
  check("16384", [0x80, 0x80, 0x02])
  check("-1073741823", [0xfd, 0xff, 0xff, 0xff, 0x07])
  check("1073741823", [0xfe, 0xff, 0xff, 0xff, 0x07])
  check("-1073741824", [0xff, 0xff, 0xff, 0xff, 0x07])
  check("1073741824", [0x80, 0x80, 0x80, 0x80, 0x08])
  check("-2147483647", [0xfd, 0xff, 0xff, 0xff, 0x0f])
  check("2147483647", [0xfe, 0xff, 0xff, 0xff, 0x0f])
  check("-2147483648", [0xff, 0xff, 0xff, 0xff, 0x0f])
  check("9223372036854775807", [0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff])
  check("-9223372036854775808", [0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff])
})

it('struct float', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeFloatStruct({ x: i })), Buffer(o))
    assert.deepEqual(
      JSON.stringify(schema.decodeFloatStruct(new Uint8Array(o))),
      JSON.stringify({ x: i }),
    )
  }

  check(0, [0])
  check(1, [127, 0, 0, 0])
  check(-1, [127, 1, 0, 0])
  check(3.1415927410125732, [128, 182, 31, 146])
  check(-3.1415927410125732, [128, 183, 31, 146])
  check(Infinity, [255, 0, 0, 0])
  check(-Infinity, [255, 1, 0, 0])
  check(NaN, [255, 0, 0, 128])
})

it('struct string', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeStringStruct({ x: i })), Buffer(o))
    assert.deepEqual(schema.decodeStringStruct(new Uint8Array(o)), { x: i })
  }

  check('', [0])
  check('abc', [97, 98, 99, 0])
  check('🙉🙈🙊', [240, 159, 153, 137, 240, 159, 153, 136, 240, 159, 153, 138, 0])
})

it('struct compound', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeCompoundStruct(i)), Buffer(o))
    assert.deepEqual(schema.decodeCompoundStruct(new Uint8Array(o)), i)
  }

  check({ x: 0, y: 0 }, [0, 0])
  check({ x: 1, y: 2 }, [1, 2])
  check({ x: 12345, y: 54321 }, [185, 96, 177, 168, 3])
})

it('struct nested', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeNestedStruct(i)), Buffer(o))
    assert.deepEqual(schema.decodeNestedStruct(new Uint8Array(o)), i)
  }

  check({ a: 0, b: { x: 0, y: 0 }, c: 0 }, [0, 0, 0, 0])
  check({ a: 1, b: { x: 2, y: 3 }, c: 4 }, [1, 2, 3, 4])
  check({ a: 534, b: { x: 12345, y: 54321 }, c: 321 }, [150, 4, 185, 96, 177, 168, 3, 193, 2])
})

it('message bool', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeBoolMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeBoolMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: false }, [1, 0, 0])
  check({ x: true }, [1, 1, 0])
})

it('message byte', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeByteMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeByteMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: 234 }, [1, 234, 0])
})

it('struct byte array', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeByteArrayStruct(i)), Buffer(o))
    assert.deepEqual(schema.decodeByteArrayStruct(new Uint8Array(o)), i)
  }

  check({ x: new Uint8Array() }, [0])
  check({ x: new Uint8Array([4, 5, 6]) }, [3, 4, 5, 6])
})

it('message uint', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeUintMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeUintMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: 12345678 }, [1, 206, 194, 241, 5, 0])
})

it('message int', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeIntMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeIntMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: 12345678 }, [1, 156, 133, 227, 11, 0])
})

it('message uint64', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeUint64Message(i)), Buffer(o))
    assert.deepEqual(schema.decodeUint64Message(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: "1234567898" }, [1, 218, 133, 216, 204, 4, 0])
})

it('message int64', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeInt64Message(i)), Buffer(o))
    assert.deepEqual(schema.decodeInt64Message(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: "-1"}, [1, 1, 0])
  check({ x: "1234567898" }, [1, 180, 139, 176, 153, 9, 0])
})

// Input is bigint and output is array of bytes in bytebuffer
function writeVarInt64Alt(value) {
  value = BigInt(value)
  let byteBuff = [1]
  value = (value << 1n) ^ (value >> 63n)
  var byteCount = 0
  while (true) {
    if (byteCount < 8) {
      var byte = Number(value & 127n)
      value >>= 7n
    } else {
      var byte = Number(value & 255n)
      byteBuff.push(byte)
      break
    }
    byteBuff.push((value != 0) ? byte | 128 : byte)
    byteCount += 1
    if (value == 0) {
      break
    }
  }
  byteBuff.push(0)
  return byteBuff
}

it('int64 string readVarInt64 check', function () {
  function check(o) {
    assert.deepEqual(schema.decodeInt64Message(new Uint8Array(o)), readVarInt64Alt(o))
  }
  // input is byte buffer, output is bigint
  function readVarInt64Alt(bytesArr) {
    let value = 0n
    let shift = 0n
    let i = 1
    if ( bytesArr.length == 1 ) return {}
    do {
      var byte = BigInt(bytesArr[i])
      if (shift < 56) {
        value |= (byte & 127n) << shift
      } else {
        value |= (byte & 255n) << shift
        break
      }
      shift += 7n
      i += 1
    } while (byte & 128n)
    value = value & 1n ? ~(value >> 1n) : value >> 1n
    return { x: (value >> 0n).toString() }
  }

  let x = 1n
  for (var i = 0; i < 63; i++) {
    check(writeVarInt64Alt(x.toString()))
    check(writeVarInt64Alt((-1n*x).toString()))
    check(writeVarInt64Alt((x-1n).toString()))
    check(writeVarInt64Alt((-1n*(x-1n)).toString()))
    x = x << 1n
  }
  check(writeVarInt64Alt("-9223372036854775808"))
  check(writeVarInt64Alt("9223372036854775807"))
})

it('int64 string write check', function () {
  function check(i) {
    assert.deepEqual(Buffer(schema.encodeInt64Message(i)), Buffer(writeVarInt64Alt(i["x"])))
  }

  let x = 1n
  for (var i = 0; i < 63; i++) {
    check({ x: x.toString() })
    check({ x: (-1n*x).toString() })
    check({ x: (x-1n).toString() })
    check({ x: (-1n*(x-1n)).toString() })
    x = x << 1n
  }
  check({ x: "-9223372036854775808" })
  check({ x: "9223372036854775807" })
})

it('message float', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeFloatMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeFloatMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: 3.1415927410125732 }, [1, 128, 182, 31, 146, 0])
})

it('message string', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeStringMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeStringMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: '' }, [1, 0, 0])
  check({ x: '🙉🙈🙊' }, [1, 240, 159, 153, 137, 240, 159, 153, 136, 240, 159, 153, 138, 0, 0])
})

it('message compound', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeCompoundMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeCompoundMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: 123 }, [1, 123, 0])
  check({ y: 234 }, [2, 234, 1, 0])
  check({ x: 123, y: 234 }, [1, 123, 2, 234, 1, 0])
  check({ y: 234, x: 123 }, [1, 123, 2, 234, 1, 0])
})

it('message nested', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeNestedMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeNestedMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ a: 123, c: 234 }, [1, 123, 3, 234, 1, 0])
  check({ b: { x: 5, y: 6 } }, [2, 1, 5, 2, 6, 0, 0])
  check({ b: { x: 5 }, c: 123 }, [2, 1, 5, 0, 3, 123, 0])
  check({ c: 123, b: { x: 5, y: 6 }, a: 234 }, [1, 234, 1, 2, 1, 5, 2, 6, 0, 3, 123, 0])
})

it('struct bool array', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeBoolArrayStruct({ x: i })), Buffer(o))
    assert.deepEqual(schema.decodeBoolArrayStruct(new Uint8Array(o)), { x: i })
  }

  check([], [0])
  check([true, false], [2, 1, 0])
})

it('message bool array', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeBoolArrayMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeBoolArrayMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: [] }, [1, 0, 0])
  check({ x: [true, false] }, [1, 2, 1, 0, 0])
})

it('recursive message', function () {
  function check(i, o) {
    assert.deepEqual(Buffer(schema.encodeRecursiveMessage(i)), Buffer(o))
    assert.deepEqual(schema.decodeRecursiveMessage(new Uint8Array(o)), i)
  }

  check({}, [0])
  check({ x: {} }, [1, 0, 0])
  check({ x: { x: {} } }, [1, 1, 0, 0, 0])
})

it('binary schema', function () {
  var compiledSchema = kiwi.compileSchema(
    kiwi.decodeBinarySchema(kiwi.encodeBinarySchema(kiwi.parseSchema(schemaText))),
  )

  function check(message) {
    assert.deepEqual(
      Buffer(schema.encodeNestedMessage(message)),
      Buffer(compiledSchema.encodeNestedMessage(message)),
    )
  }

  check({ a: 1, c: 4 })
  check({ a: 1, b: {}, c: 4 })
  check({ a: 1, b: { x: 2, y: 3 }, c: 4 })
})

var largeSchemaText = fs.readFileSync(__dirname + '/test-schema-large.kiwi', 'utf8')
var largeSchema = kiwi.compileSchema(kiwi.parseSchema(largeSchemaText))

it('struct with many fields', function () {
  var object = {}
  for (var i = 0; i < 130; i++) object['f' + i] = i

  var encoded = largeSchema.encodeStruct(object)
  assert.deepEqual(object, largeSchema.decodeStruct(encoded))
})

it('message with many fields', function () {
  var object = {}
  for (var i = 0; i < 130; i++) object['f' + i] = i

  var encoded = largeSchema.encodeMessage(object)
  assert.deepEqual(object, largeSchema.decodeMessage(encoded))
})

it('message with deprecated fields', function () {
  var nonDeprecated = {
    a: 1,
    b: 2,
    c: [3, 4, 5],
    d: [6, 7, 8],
    e: { x: 123 },
    f: { x: 234 },
    g: 9,
  }

  var deprecated = {
    a: 1,
    c: [3, 4, 5],
    e: { x: 123 },
    g: 9,
  }

  assert.deepEqual(
    schema.decodeDeprecatedMessage(schema.encodeNonDeprecatedMessage(nonDeprecated)),
    deprecated,
  )
  assert.deepEqual(
    schema.decodeNonDeprecatedMessage(schema.encodeDeprecatedMessage(nonDeprecated)),
    deprecated,
  )
})

it('schema round trip', function () {
  var parsed = kiwi.parseSchema(schemaText)
  var schemaText2 = kiwi.prettyPrintSchema(parsed)
  var parsed2 = kiwi.parseSchema(schemaText2)

  function deleteLocations(ast) {
    ast.definitions.forEach(function (definition) {
      delete definition.line
      delete definition.column
      definition.fields.forEach(function (field) {
        delete field.line
        delete field.column
      })
    })
  }

  deleteLocations(parsed)
  deleteLocations(parsed2)

  assert.deepEqual(parsed, parsed2)
})

var dedupSchemaText = fs.readFileSync(__dirname + '/test-schema-dedup.kiwi', 'utf8')
var dedupSchema = kiwi.compileSchema(kiwi.parseSchema(dedupSchemaText), ['DuplicatedSuperMessage', 'DuplicatedMessage', 'DuplicatedStruct'])

function countUniqueRefsOfType(obj, typeName) {
  // Assumes objects have field 'name' giving the typeName to be filtered
  var counts = new Map()
  function countHelper(o) {
    if (typeof o !== 'object') {
      return
    }
    if (o.name === typeName) {
      if (!counts.has(o)) {
        counts.set(o, 0)
      }
      counts.set(o, counts.get(o) + 1)
    }
    for (var [key, value] of Object.entries(o)) {
      countHelper(value)
    }
  }
  countHelper(obj)
  return counts.size
}

it('deduplicated structs', function () {
  var superSuperMessage = {}
  superSuperMessage.name = 'SuperSuperMessage'
  var values = [1111, 2222, 3333, 4444, 5555]
  var numDuplications = 10
  // <values.length> unique DuplicatedStruct, each gets duplicated numDuplications times
  superSuperMessage.dsArr = []
  for (var v = 0; v < values.length; v++) {
    for (var i = 0; i < numDuplications; i++) {
      var ds = { name: 'DuplicatedStruct' }
      for (var j = 0; j < 3; j++) {
        ds['f' + j] = values[v]
      }
      superSuperMessage.dsArr.push(ds)
    }
  }
  // count unique BEFORE deduplicated decode
  assert.deepEqual(
    countUniqueRefsOfType(superSuperMessage, 'DuplicatedStruct'),
    values.length * numDuplications,
  )
  var encoded = dedupSchema.encodeSuperSuperMessage(superSuperMessage)
  var decoded = dedupSchema.decodeSuperSuperMessage(encoded, dedupSchema.makeDedupCache())
  assert.deepEqual(superSuperMessage, decoded)
  // count unique AFTER deduplicated decode
  assert.deepEqual(countUniqueRefsOfType(decoded, 'DuplicatedStruct'), values.length)
})

it('deduplicated messages', function () {
  var superSuperMessage = {}
  superSuperMessage.name = 'SuperSuperMessage'
  var values = [1111, 2222, 3333, 4444, 5555]
  var numDuplications = 10
  // <values.length> unique DuplicatedMessage, each gets duplicated numDuplications times
  superSuperMessage.dmArr = []
  for (var v = 0; v < values.length; v++) {
    for (var i = 0; i < numDuplications; i++) {
      var dm = { name: 'DuplicatedMessage' }
      for (var j = 0; j < 3; j++) {
        dm['f' + j] = values[v]
      }
      superSuperMessage.dmArr.push(dm)
    }
  }
  // count unique BEFORE deduplicated decode
  assert.deepEqual(
    countUniqueRefsOfType(superSuperMessage, 'DuplicatedMessage'),
    values.length * numDuplications,
  )
  var encoded = dedupSchema.encodeSuperSuperMessage(superSuperMessage)
  var decoded = dedupSchema.decodeSuperSuperMessage(encoded, dedupSchema.makeDedupCache())
  assert.deepEqual(superSuperMessage, decoded)
  // count unique AFTER deduplicated decode
  assert.deepEqual(countUniqueRefsOfType(decoded, 'DuplicatedMessage'), values.length)
})

it('deduplicated messages with possibly nested structs and messages', function () {
  var superSuperMessage = {}
  superSuperMessage.name = 'SuperSuperMessage'
  var values = [1111, 2222, 3333, 4444, 5555]
  var dsDuplications = 30
  var dmDuplications = 20
  var dsmDuplications = 10
  // <values.length> unique DuplicatedStruct, each gets duplicated dsDuplications times
  superSuperMessage.dsArr = []
  for (var v = 0; v < values.length; v++) {
    for (var i = 0; i < dsDuplications; i++) {
      var ds = { name: 'DuplicatedStruct' }
      for (var j = 0; j < 3; j++) {
        ds['f' + j] = values[v]
      }
      superSuperMessage.dsArr.push(ds)
    }
  }
  // <values.length> unique DuplicatedMessage, each gets duplicated dmDuplications times
  superSuperMessage.dmArr = []
  for (var v = 0; v < values.length; v++) {
    for (var i = 0; i < dmDuplications; i++) {
      var dm = { name: 'DuplicatedMessage' }
      for (var j = 0; j < 3; j++) {
        dm['f' + j] = values[v]
      }
      superSuperMessage.dmArr.push(dm)
    }
  }
  // <values.length> unique DuplicatedSuperMessage, each gets duplicated dsmDuplications times
  superSuperMessage.dsmArr = []
  for (var v = 0; v < values.length; v++) {
    for (var i = 0; i < dsmDuplications; i++) {
      var dsm = { name: 'DuplicatedSuperMessage' }
      dsm['m'] = { name: 'Message' }
      dsm['s'] = { name: 'Struct' }
      for (var j = 0; j < 3; j++) {
        dsm['m']['f' + j] = values[v]
        dsm['s']['f' + j] = values[v]
      }
      superSuperMessage.dsmArr.push(dsm)
    }
  }
  // count unique BEFORE deduplicated decode
  assert.deepEqual(
    countUniqueRefsOfType(superSuperMessage, 'DuplicatedStruct'),
    values.length * dsDuplications,
  )
  assert.deepEqual(
    countUniqueRefsOfType(superSuperMessage, 'DuplicatedMessage'),
    values.length * dmDuplications,
  )
  assert.deepEqual(
    countUniqueRefsOfType(superSuperMessage, 'DuplicatedSuperMessage'),
    values.length * dsmDuplications,
  )
  var encoded = dedupSchema.encodeSuperSuperMessage(superSuperMessage)
  var decoded = dedupSchema.decodeSuperSuperMessage(encoded, dedupSchema.makeDedupCache())
  assert.deepEqual(superSuperMessage, decoded)
  // count unique AFTER deduplicated decode
  assert.deepEqual(countUniqueRefsOfType(decoded, 'DuplicatedStruct'), values.length)
  assert.deepEqual(countUniqueRefsOfType(decoded, 'DuplicatedMessage'), values.length)
  assert.deepEqual(countUniqueRefsOfType(decoded, 'DuplicatedSuperMessage'), values.length)
})

function countUniqueNonEmptyArraysOfType(obj, typeName) {
  // Assumes objects have field 'name' giving the typeName to be filtered
  var counts = new Map()
  function countHelper(o) {
    if (typeof o !== 'object') {
      return
    }
    if (o.constructor.name !== 'Array') {
      for (var [key, value] of Object.entries(o)) {
        countHelper(value)
      }
      return
    }
    if (o.length === 0) {
      return
    }
    if (o[0].name === typeName) {
      if (!counts.has(o)) {
        counts.set(o, 0)
      }
      counts.set(o, counts.get(o) + 1)
    }
    for (var i = 0; i < o.length; i++) {
      countHelper(o[i])
    }
  }
  countHelper(obj)
  return counts.size
}

var dedupSchemaWithArrays = kiwi.compileSchema(kiwi.parseSchema(dedupSchemaText), ['DuplicatedMessage[]', 'DuplicatedStruct[]'])

it('messages with deduplicated struct arrays and message arrays', function () {
  var superSuperMessage = {}
  superSuperMessage.name = 'SuperSuperMessage'
  var arrayLengths = [1, 2, 5]
  var dsArrDuplications = 30
  var dmArrDuplications = 20
  superSuperMessage.smwdaArr = []
  // <arrayLengths.length> unique DuplicatedStruct[], each gets duplicated dsArrDuplications times as a SuperMessageWithDuplicatedArrays
  for (var l = 0; l < arrayLengths.length; l++) {
    var len = arrayLengths[l]
    for (var i = 0; i < dsArrDuplications; i++) {
      var smwda = { name: 'SuperMessageWithDuplicatedArrays' }
      smwda.dsArr = []
      for (var j = 0; j < len; j++) {
        // doesn't matter what we store to DuplicatedStruct cuz we're de-duping arrays, not array items
        var ds = { name: 'DuplicatedStruct' }
        for (var f = 0; f < 3; f++) {
          ds['f' + f] = 0x1337
        }
        smwda.dsArr.push(ds)
      }
      superSuperMessage.smwdaArr.push(smwda)
    }
  }
  // <arrayLengths.length> unique DuplicatedMessage[], each gets duplicated dmArrDuplications times as a SuperMessageWithDuplicatedArrays
  for (var l = 0; l < arrayLengths.length; l++) {
    var len = arrayLengths[l]
    for (var i = 0; i < dmArrDuplications; i++) {
      var smwda = { name: 'SuperMessageWithDuplicatedArrays' }
      smwda.dmArr = []
      for (var j = 0; j < len; j++) {
        // doesn't matter what we store to DuplicatedMessage cuz we're de-duping arrays, not array items
        var dm = { name: 'DuplicatedMessage' }
        for (var f = 0; f < 3; f++) {
          dm['f' + f] = 0x1337
        }
        smwda.dmArr.push(dm)
      }
      superSuperMessage.smwdaArr.push(smwda)
    }
  }
  // count unique BEFORE deduplicated decode
  assert.deepEqual(
    countUniqueNonEmptyArraysOfType(superSuperMessage, 'DuplicatedStruct'),
    arrayLengths.length * dsArrDuplications,
  )
  assert.deepEqual(
    countUniqueNonEmptyArraysOfType(superSuperMessage, 'DuplicatedMessage'),
    arrayLengths.length * dmArrDuplications,
  )
  var encoded = dedupSchemaWithArrays.encodeSuperSuperMessage(superSuperMessage)
  var decoded = dedupSchemaWithArrays.decodeSuperSuperMessage(encoded, dedupSchemaWithArrays.makeDedupCache())
  assert.deepEqual(superSuperMessage, decoded)
  // count unique AFTER deduplicated decode
  assert.deepEqual(countUniqueNonEmptyArraysOfType(decoded, 'DuplicatedStruct'), arrayLengths.length)
  assert.deepEqual(countUniqueNonEmptyArraysOfType(decoded, 'DuplicatedMessage'), arrayLengths.length)
})
