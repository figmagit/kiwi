import { Schema, Definition } from './schema'
import { ByteBuffer } from './bb'
import { Hasher } from './hasher'
import { HashTable } from './hashtable'
import { error, quote } from './util'

// prettier-ignore
function compileDecode(
  definition: Definition,
  definitions: { [name: string]: Definition },
  nonArrayDefinitionsToDedup: string[],
  arrayDefinitionsToDedup: string[],
): string {
  let lines: string[] = []
  let indent = '  '

  lines.push('function(bb, optDedupCache) {')
  // If definition is in the list of de-duplicable non-array definitions, emit logic
  // to hash and retrieve it from `optDedupCache` optionally given at runtime
  lines.push('  var dedupKey = null;')
  if (nonArrayDefinitionsToDedup.includes(definition.name)) {
    lines.push('  if (!!optDedupCache) {')
    lines.push('    if (!(optDedupCache instanceof this.HashTable)) {')
    lines.push('      throw new Error("optDedupCache must be instance of HashTable");')
    lines.push('    }')
    lines.push('    // lookahead with hasher then reference result with dedup cache')
    lines.push('    var hasher = new this.Hasher(bb.getNewWindowFromRight());')
    lines.push(`    this[${quote('hash' + definition.name)}](hasher);`)
    lines.push(`    dedupKey = { hash: hasher.value(), data: hasher.windowToUint8Array(), defName: ${quote(definition.name)} };`)
    lines.push('    var cachedResult = optDedupCache.get(dedupKey, null);')
    lines.push('    if (cachedResult !== null) {')
    // cache hit. skip past what the hasher read
    lines.push('      bb.extendWindowTo(hasher.bb());')
    lines.push('      return cachedResult;')
    lines.push('    }')
    lines.push('  }')
  }
  lines.push('  var result = {};')
  lines.push('  if (!(bb instanceof this.ByteBuffer)) {')
  lines.push('    bb = new this.ByteBuffer(bb);')
  lines.push('  }')
  lines.push('')

  if (definition.kind === 'MESSAGE') {
    lines.push('  while (true) {')
    lines.push('  var x = bb.readVarUint();')
    lines.push('    switch (x) {')
    lines.push('    case 0:')
    lines.push('      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;')
    lines.push('')
    indent = '      '
  }

  for (let i = 0; i < definition.fields.length; i++) {
    let field = definition.fields[i]
    let decodeOne: string
    let hashOne: string // currently only used for de-duping array fields

    switch (field.type) {
      case 'bool': {
        decodeOne = '!!bb.readByte()'
        hashOne = '!!hasher.readByte()'
        break
      }

      case 'byte': {
        decodeOne = 'bb.readByte()' // only used if not array
        hashOne = 'hasher.readByte()'
        break
      }

      case 'int': {
        decodeOne = 'bb.readVarInt()'
        hashOne = 'hasher.readVarInt()'
        break
      }

      case 'uint': {
        decodeOne = 'bb.readVarUint()'
        hashOne = 'hasher.readVarUint()'
        break
      }

      case 'int64': {
        decodeOne = 'bb.readVarInt64()'
        hashOne = 'hasher.readVarInt64()'
        break
      }

      case 'uint64': {
        decodeOne = 'bb.readVarUint64()'
        hashOne = 'hasher.readVarUint64()'
        break
      }

      case 'float': {
        decodeOne = 'bb.readVarFloat()'
        hashOne = 'hasher.readVarFloat()'
        break
      }

      case 'string': {
        decodeOne = 'bb.readString()'
        hashOne = 'hasher.readString()'
        break
      }

      default: {
        let type = definitions[field.type!]
        if (!type) {
          error(
            `Invalid type ${quote(field.type!)} for field ${quote(field.name)}`,
            field.line,
            field.column,
          )
        } else if (type.kind === 'ENUM') {
          decodeOne = `this[${quote(type.name)}][bb.readVarUint()]`
          hashOne = `this[${quote(type.name)}][hasher.readVarUint()]`
        } else {
          decodeOne = `this[${quote('decode' + type.name)}](bb, optDedupCache || null)`
          hashOne = `this[${quote('hash' + type.name)}](hasher)`
        }
      }
    }

    if (definition.kind === 'MESSAGE') {
      lines.push(`    case ${field.value}:`)
    }

    if (field.isArray) {
      if (field.isDeprecated) {
        if (field.type === 'byte') {
          lines.push(indent + 'bb.readByteArray();')
        } else {
          lines.push(indent + 'var length = bb.readVarUint();')
          lines.push(indent + `while (length-- > 0) ${decodeOne};`)
        }
      } else {
        if (field.type === 'byte') {
          lines.push(indent + `result[${quote(field.name)}] = bb.readByteArray();`)
        } else {
          // If definition is in the list of de-duplicable array definitions, emit logic
          // to hash and retrieve it from `optDedupCache` optionally given at runtime
          lines.push(indent + 'var arrayDedupKey = null;')
          lines.push(indent + 'var values = null;')
          if (arrayDefinitionsToDedup.includes(field.type!)) {
            lines.push(indent + 'if (!!optDedupCache) {')
            lines.push(indent + '  // lookahead with hasher then reference result with dedup cache')
            lines.push(indent + '  var hasher = new this.Hasher(bb.getNewWindowFromRight());')
            lines.push(indent + '  var length = hasher.readVarUint();')
            lines.push(indent + `  for (var i = 0; i < length; i++) ${hashOne};`)
            lines.push(indent + `  arrayDedupKey = { hash: hasher.value(), data: hasher.windowToUint8Array(), defName: ${quote(field.type + "[]")} };`)
            lines.push(indent + '  var cachedResult = optDedupCache.get(arrayDedupKey, null);')
            lines.push(indent + '  if (cachedResult !== null) {')
            lines.push(indent + '    bb.extendWindowTo(hasher.bb());')
            lines.push(indent + '    values = cachedResult;')
            lines.push(indent + '  }')
            lines.push(indent + '}')
          }
          lines.push(indent + 'if (values === null) {')
          lines.push(indent + '  var length = bb.readVarUint();')
          lines.push(indent + '  var values = Array(length);')
          lines.push(indent + `  for (var i = 0; i < length; i++) values[i] = ${decodeOne};`)
          lines.push(indent + '  if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }')
          lines.push(indent + '}')
          lines.push(indent + `result[${quote(field.name)}] = values;`)
        }
      }
    } else {
      if (field.isDeprecated) {
        lines.push(indent + `${decodeOne};`)
      } else {
        // de-duplication of non-array fields is handled when calling into the
        // generated `decode<DefinitionName>` function
        lines.push(indent + `result[${quote(field.name)}] = ${decodeOne};`)
      }
    }

    if (definition.kind === 'MESSAGE') {
      lines.push('      break;')
      lines.push('')
    }
  }

  if (definition.kind === 'MESSAGE') {
    lines.push('    default:')
    lines.push('      throw new Error("Attempted to parse invalid message");')
    lines.push('    }')
    lines.push('  }')
  } else {
    lines.push('  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;')
  }

  lines.push('}')

  return lines.join('\n')
}

function compileHash(definition: Definition, definitions: { [name: string]: Definition }): string {
  let lines: string[] = []
  let indent = '  '

  lines.push('function(hasher) {')
  lines.push('  var result = {};')
  lines.push('  if (!(hasher instanceof this.Hasher)) {')
  lines.push('    throw new Error("Expected Hasher");')
  lines.push('  }')
  lines.push('')

  if (definition.kind === 'MESSAGE') {
    lines.push('  while (true) {')
    lines.push('    switch (hasher.readVarUint()) {')
    lines.push('    case 0:')
    lines.push('      return;')
    lines.push('')
    indent = '      '
  }

  for (let i = 0; i < definition.fields.length; i++) {
    let field = definition.fields[i]
    let code: string

    switch (field.type) {
      case 'bool': {
        code = 'hasher.readByte()'
        break
      }

      case 'byte': {
        code = 'hasher.readByte()'
        break
      }

      case 'int': {
        code = 'hasher.readVarInt()'
        break
      }

      case 'uint': {
        code = 'hasher.readVarUint()'
        break
      }

      case 'int64': {
        code = 'hasher.readVarInt64()'
        break
      }

      case 'uint64': {
        code = 'hasher.readVarUint64()'
        break
      }

      case 'float': {
        code = 'hasher.readVarFloat()'
        break
      }

      case 'string': {
        code = 'hasher.readString()'
        break
      }

      default: {
        let type = definitions[field.type!]
        if (!type) {
          error(`Invalid type ${quote(field.type!)} for field ${quote(field.name)}`, field.line, field.column)
        } else if (type.kind === 'ENUM') {
          code = 'hasher.readVarUint()'
        } else {
          code = `this[${quote('hash' + type.name)}](hasher)`
        }
      }
    }

    if (definition.kind === 'MESSAGE') {
      lines.push(`    case ${field.value}:`)
    }

    if (field.isArray) {
      if (field.type === 'byte') {
        lines.push(indent + 'hasher.readByteArray();')
      } else {
        lines.push(indent + 'var length = hasher.readVarUint();')
        lines.push(indent + `while (length-- > 0) ${code};`)
      }
    } else {
      lines.push(indent + `${code};`)
    }

    if (definition.kind === 'MESSAGE') {
      lines.push('      break;')
      lines.push('')
    }
  }

  if (definition.kind === 'MESSAGE') {
    lines.push('    default:')
    lines.push('      throw new Error("Attempted to parse invalid message");')
    lines.push('    }')
    lines.push('  }')
  } else {
    lines.push('  return;')
  }

  lines.push('}')

  return lines.join('\n')
}

function compileEncode(definition: Definition, definitions: { [name: string]: Definition }): string {
  let lines: string[] = []

  lines.push('function(message, bb) {')
  lines.push('  var isTopLevel = !bb;')
  lines.push('  if (isTopLevel) bb = new this.ByteBuffer();')

  for (let j = 0; j < definition.fields.length; j++) {
    let field = definition.fields[j]
    let code: string

    if (field.isDeprecated) {
      continue
    }

    switch (field.type) {
      case 'bool': {
        code = 'bb.writeByte(value);'
        break
      }

      case 'byte': {
        code = 'bb.writeByte(value);' // only used if not array
        break
      }

      case 'int': {
        code = 'bb.writeVarInt(value);'
        break
      }

      case 'uint': {
        code = 'bb.writeVarUint(value);'
        break
      }

      case 'int64': {
        code = 'bb.writeVarInt64(value);'
        break
      }

      case 'uint64': {
        code = 'bb.writeVarUint64(value);'
        break
      }

      case 'float': {
        code = 'bb.writeVarFloat(value);'
        break
      }

      case 'string': {
        code = 'bb.writeString(value);'
        break
      }

      default: {
        let type = definitions[field.type!]
        if (!type) {
          throw new Error(`Invalid type ${quote(field.type!)} for field ${quote(field.name)}`)
        } else if (type.kind === 'ENUM') {
          code = `var encoded = this[${quote(type.name)}][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + ${quote(
            ' for enum ' + quote(type.name),
          )}); bb.writeVarUint(encoded);`
        } else {
          code = `this[${quote('encode' + type.name)}](value, bb);`
        }
      }
    }

    lines.push('')
    lines.push(`  var value = message[${quote(field.name)}];`)
    lines.push('  if (value != null) {') // Comparing with null using "!=" also checks for undefined

    if (definition.kind === 'MESSAGE') {
      lines.push(`    bb.writeVarUint(${field.value});`)
    }

    if (field.isArray) {
      if (field.type === 'byte') {
        lines.push('    bb.writeByteArray(value);')
      } else {
        lines.push('    var values = value, n = values.length;')
        lines.push('    bb.writeVarUint(n);')
        lines.push('    for (var i = 0; i < n; i++) {')
        lines.push('      value = values[i];')
        lines.push(`      ${code}`)
        lines.push('    }')
      }
    } else {
      lines.push(`    ${code}`)
    }

    if (definition.kind === 'STRUCT') {
      lines.push('  } else {')
      lines.push(`    throw new Error(${quote('Missing required field ' + quote(field.name))});`)
    }

    lines.push('  }')
  }

  // A field id of zero is reserved to indicate the end of the message
  if (definition.kind === 'MESSAGE') {
    lines.push('  bb.writeVarUint(0);')
  }

  lines.push('')
  lines.push('  if (isTopLevel) return bb.toUint8Array();')
  lines.push('}')

  return lines.join('\n')
}

export function compileSchemaJS(schema: Schema, nonArrayDefinitionsToDedup: string[], arrayDefinitionsToDedup: string[]): string {
  let definitions: { [name: string]: Definition } = {}
  let name = schema.package
  let js: string[] = []

  if (name !== null) {
    js.push(`var ${name} = exports || ${name} || {}, exports;`)
  } else {
    js.push('var exports = exports || {};')
    name = 'exports'
  }

  js.push(`${name}.ByteBuffer = ${name}.ByteBuffer || require("kiwi-schema").ByteBuffer;`)

  for (let i = 0; i < schema.definitions.length; i++) {
    let definition = schema.definitions[i]
    definitions[definition.name] = definition
  }

  for (let i = 0; i < schema.definitions.length; i++) {
    let definition = schema.definitions[i]

    switch (definition.kind) {
      case 'ENUM': {
        let value: any = {}
        for (let j = 0; j < definition.fields.length; j++) {
          let field = definition.fields[j]
          value[field.name] = field.value
          value[field.value] = field.name
        }
        js.push(`${name}[${quote(definition.name)}] = ${JSON.stringify(value, null, 2)};`)
        break
      }

      case 'STRUCT':
      case 'MESSAGE': {
        js.push('')
        js.push(`${name}[${quote('decode' + definition.name)}] = ${compileDecode(definition, definitions, nonArrayDefinitionsToDedup, arrayDefinitionsToDedup)};`)
        js.push('')
        js.push(`${name}[${quote('encode' + definition.name)}] = ${compileEncode(definition, definitions)};`)
        js.push('')
        js.push(`${name}[${quote('hash' + definition.name)}] = ${compileHash(definition, definitions)};`)
        break
      }

      default: {
        error('Invalid definition kind ' + quote(definition.kind), definition.line, definition.column)
        break
      }
    }
  }

  js.push('')
  return js.join('\n')
}

type DedupCacheKey = {
  hash: number
  data: Uint8Array
  defName: string
}

function isDataEqual(a: Uint8Array, b: Uint8Array): boolean {
  if (a.length !== b.length) {
    return false
  }
  for (let i = 0; i < a.length; i++) {
    if (a[i] !== b[i]) {
      return false
    }
  }
  return true
}

export function compileSchema(schema: Schema, definitionsToDedupDecode?: string[]): any {
  let result = {
    ByteBuffer: ByteBuffer,
    Hasher: Hasher,
    HashTable: HashTable,
    makeDedupCache: () =>
      new HashTable<DedupCacheKey, any>(
        (cacheKey) => cacheKey.hash,
        (a, b) => a.defName === b.defName && isDataEqual(a.data, b.data),
      ),
  }

  // filter for definitions without "[]" at end
  let nonArrayDefinitionsToDedup: string[] = []

  // filter for definitions with "[]" at end, but then snip off the "[]" before using
  let arrayDefinitionsToDedup: string[] = []
  if (!!definitionsToDedupDecode) {
    nonArrayDefinitionsToDedup = definitionsToDedupDecode.filter((ident) => !!ident.match(/^[A-Za-z_][A-Za-z0-9_]*$/))
    arrayDefinitionsToDedup = definitionsToDedupDecode.filter((ident) => !!ident.match(/^[A-Za-z_][A-Za-z0-9_]*\[\]$/)).map((fullName) => fullName.slice(0, fullName.length - 2))
    if (arrayDefinitionsToDedup.length + nonArrayDefinitionsToDedup.length !== definitionsToDedupDecode.length) {
      console.warn('Some definitions to dedup are invalid identifiers, skipping...')
    }
  }
  new Function('exports', compileSchemaJS(schema, nonArrayDefinitionsToDedup, arrayDefinitionsToDedup))(result)
  return result
}
