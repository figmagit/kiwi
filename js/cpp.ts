import { Schema, Definition, Field } from './schema'
import { error, quote } from './util'

function cppType(definitions: { [name: string]: Definition }, field: Field, isArray: boolean): string {
  let type

  switch (field.type) {
    case 'bool':
      type = 'bool'
      break
    case 'byte':
      type = 'uint8_t'
      break
    case 'int':
      type = 'int32_t'
      break
    case 'uint':
      type = 'uint32_t'
      break
    case 'int64':
      type = 'int64_t'
      break
    case 'uint64':
      type = 'uint64_t'
      break
    case 'float':
      type = 'float'
      break
    case 'string':
      type = 'kiwi::String'
      break

    default: {
      let definition = definitions[field.type!]

      if (!definition) {
        error(`Invalid type ${quote(field.type!)} for field ${quote(field.name)}`, field.line, field.column)
      }

      type = definition.name
      break
    }
  }

  if (isArray) {
    type = `kiwi::Array<${type}>`
  }

  return type
}

function cppFieldName(field: Field): string {
  return '_data_' + field.name
}

function cppFlagIndex(i: number): number {
  return i >> 5
}

function cppFlagMask(i: number): string {
  return `(1 << ${i % 32})`
}

function cppIsFieldPointer(definitions: { [name: string]: Definition }, field: Field): boolean {
  return !field.isArray && field.type! in definitions && definitions[field.type!].kind !== 'ENUM'
}

function cppEncodeValue(definitions: { [name: string]: Definition }, field: Field, value: string): string {
  switch (field.type) {
    case 'bool':
      return `_wb.writeBool(${value});`
    case 'byte':
      return `_wb.writeByte(${value});`
    case 'int':
      return `_wb.writeVarInt(${value});`
    case 'uint':
      return `_wb.writeVarUint(${value});`
    case 'int64':
      return `_wb.writeVarInt64(${value});`
    case 'uint64':
      return `_wb.writeVarUint64(${value});`
    case 'float':
      return `_wb.writeVarFloat(${value});`
    case 'string':
      return `_wb.writeString(${value}.c_str());`
    default: {
      let type = definitions[field.type!]

      if (!type) {
        error(`Invalid type ${quote(field.type!)} for field ${quote(field.name)}`, field.line, field.column)
      } else if (type.kind === 'ENUM') {
        return `_wb.writeVarUint(static_cast<uint32_t>(${value}));`
      } else {
        return `if (!${value}${cppIsFieldPointer(definitions, field) ? '->' : '.'}encode(_wb)) return false;`
      }
    }
  }
}

function cppDecodeValue(definitions: { [name: string]: Definition }, field: Field, value: string): string {
  let isPointer = cppIsFieldPointer(definitions, field)

  switch (field.type) {
    case 'bool':
      return `_bb.readBool(${value})`
    case 'byte':
      return `_bb.readByte(${value})`
    case 'int':
      return `_bb.readVarInt(${value})`
    case 'uint':
      return `_bb.readVarUint(${value})`
    case 'int64':
      return `_bb.readVarInt64(${value})`
    case 'uint64':
      return `_bb.readVarUint64(${value})`
    case 'float':
      return `_bb.readVarFloat(${value})`
    case 'string':
      return `_bb.readString(${value}, _pool)`
    default: {
      let type = definitions[field.type!]

      if (!type) {
        error(`Invalid type ${quote(field.type!)} for field ${quote(field.name)}`, field.line, field.column)
      } else if (type.kind === 'ENUM') {
        return `_bb.readVarUint(reinterpret_cast<uint32_t &>(${value}))`
      } else {
        return `${value + (isPointer ? '->' : '.')}decode(_bb, _pool, _schema)`
      }
    }
  }
}

// Sort fields by size. For structs this is a more memory efficient way to order members.
function sortFields(fields: Field[]): Field[] {
  let sizes: { [type: string]: number } = { bool: 1, byte: 1, int: 4, uint: 4, float: 4 }
  return fields.slice().sort(function (a, b) {
    let sizeA = (!a.isArray && sizes[a.type!]) || 8
    let sizeB = (!b.isArray && sizes[b.type!]) || 8
    if (sizeA !== sizeB) return sizeB - sizeA
    return fields.indexOf(a) - fields.indexOf(b) // Make sure the sort is stable
  })
}

function cppDeclaration(definition: Definition, definitions: { [name: string]: Definition }, copyable: boolean): string[] {
  const fields = definition.fields
  const cpp: string[] = []

  cpp.push(`class ${definition.name} {`)
  cpp.push('public:')

  // This may not actually be used, so silence warnings about "Private fields '_flags' is not used"
  cpp.push(`  ${definition.name}() { (void)_flags; }`)

  if (!copyable) {
    cpp.push(`  ${definition.name}(const ${definition.name}&) = delete;`)
    cpp.push(`  ${definition.name}& operator=(const ${definition.name}&) = delete;`)
  }

  cpp.push(`  ${definition.name}(${definition.name}&&) = default;`)
  cpp.push(`  ${definition.name}& operator=(${definition.name}&&) = default;`)
  cpp.push('')

  if (copyable) {
    cpp.push(`  ${definition.name} copy() const;`)
    cpp.push('')
  }

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]

    if (field.isDeprecated) {
      continue
    }

    let name = cppFieldName(field)
    let type = cppType(definitions, field, field.isArray)

    cpp.push(`  ${type} *${field.name}();`)
    cpp.push(`  const ${type} *${field.name}() const;`)

    if (cppIsFieldPointer(definitions, field)) {
      cpp.push(`  void set_${field.name}(${type} *value);`)
    } else if (field.isArray) {
      cpp.push(`  ${type} &set_${field.name}(kiwi::MemoryPool &pool, uint32_t count);`)
    } else {
      cpp.push(`  void set_${field.name}(const ${type} &value);`)
    }

    cpp.push('')
  }

  cpp.push('  bool encode(kiwi::WriteBuffer &wb) const;')
  cpp.push('  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);')
  cpp.push('')
  cpp.push('private:')

  if (copyable) {
    cpp.push(`  ${definition.name}(const ${definition.name}&) = default;`)
    cpp.push(`  ${definition.name}& operator=(const ${definition.name}&) = default;`)
  }

  cpp.push(`  uint32_t _flags[${(fields.length + 31) >> 5}] = {};`)

  // Sort fields by size since that makes the resulting struct smaller
  let sortedFields = sortFields(fields)

  let indent = '  '
  for (let j = 0; j < sortedFields.length; j++) {
    let field = sortedFields[j]

    if (field.isDeprecated) {
      continue
    }

    let name = cppFieldName(field)
    let type = cppType(definitions, field, field.isArray)

    if (cppIsFieldPointer(definitions, field)) {
      cpp.push(indent + `${type} *${name} = {};`)
    } else {
      cpp.push(indent + `${type} ${name} = {};`)
    }
  }

  cpp.push('};')
  cpp.push('')
  return cpp
}

// Declares the given message using a sparse implementation. The sparse implementation
// conserves memory for message types that define many fields, but only use a few of them.
// In the original, non-sparse implementation, each field is declared as a member of the message
// class and uses some memory. Something like:
//
// class NonSparseMessage {
// ...
// private:
//   bool _data_bool = {};
//   Enum _data_enum = {};
// }
//
// The sparse implementation stores initialized fields in a sorted array, so we don't allocate memory
// for uninitialized fields. Fields are stored using the SparseFields data type. It looks like this:
//
// class SparseMessage {
// ...
// private:
//   union Field {
//     bool _data_bool = {};
//     Enum _data_enum = {};
//   };
//   kiwi::SparseFields<Field> _fields = {};
// }
//
// SparseFields is an array where each element has an index and a value. The index matches the id of the field
// in the schema and the value is a union of all possible message types.
//
// Implementation details:
// - Individual fields use more memory in the sparse implementation, because fields are stored in a union. The
//   size of the union is the maximum size of any one field. The memory savings come from the fact that we don't
//   allocate memory for uninitialized fields
// - SparseFields is sorted to allow for faster look ups in getters
// - SparseFields is growable and uses a kiwi::MemoryPool as a backing store. Every operation that adds a field
//   needs to take a MemoryPool as input.
// - Getters for sparse message types return optionals instead of raw pointers. This is so we don't have to expose
//   pointers to values in SparseFields, which might get sorted.
//
// To use the sparse implementation for a message pass the --cpp-sparse flag to the kiwi compiler.
function cppSparseDeclaration(definition: Definition, definitions: { [name: string]: Definition }, copyable: boolean): string[] {
  const fields = definition.fields
  const cpp: string[] = []
  cpp.push(`class ${definition.name} {`)
  cpp.push('public:')

  // This may not actually be used, so silence warnings about "Private fields '_flags' is not used"
  cpp.push(`  ${definition.name}() { (void)_flags; }`)
  cpp.push(`  ${definition.name}(const ${definition.name}&) = delete;`)
  cpp.push(`  ${definition.name}& operator=(const ${definition.name}&) = delete;`)
  cpp.push(`  ${definition.name}(${definition.name}&&) = default;`)
  cpp.push(`  ${definition.name}& operator=(${definition.name}&&) = default;`)
  cpp.push('')

  if (copyable) {
    cpp.push(`  ${definition.name} copy(kiwi::MemoryPool& pool) const;`)
    cpp.push('')
  }

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]

    if (field.isDeprecated) {
      continue
    }

    let name = cppFieldName(field)
    let type = cppType(definitions, field, field.isArray)
    let isPointer = cppIsFieldPointer(definitions, field)

    if (isPointer) {
      cpp.push(`  ${type} *${field.name}();`)
      cpp.push(`  const ${type} *${field.name}() const;`)
    } else {
      cpp.push(`  kiwi::Optional<${type}> ${field.name}() const;`)
    }

    if (cppIsFieldPointer(definitions, field)) {
      cpp.push(`  void set_${field.name}(kiwi::MemoryPool &pool, ${type} *value);`)
    } else if (field.isArray) {
      cpp.push(`  ${type} &set_${field.name}(kiwi::MemoryPool &pool, uint32_t count);`)
    } else {
      cpp.push(`  void set_${field.name}(kiwi::MemoryPool &pool, const ${type} &value);`)
    }

    cpp.push('')
  }

  cpp.push('  bool encode(kiwi::WriteBuffer &wb) const;')
  // TODO: Eventually this will become the default.
  cpp.push('  bool encode2(kiwi::WriteBuffer &wb) const;')
  cpp.push('  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);')
  cpp.push('')
  cpp.push('private:')
  cpp.push(`  uint32_t _flags[${(fields.length + 31) >> 5}] = {};`)

  // Sort fields to match ordering in dense implementation
  let sortedFields = sortFields(fields)

  cpp.push(`  union Field {`)
  cpp.push(`  public:`)
  // This equality impl allows us to TypeID() these fields, as necessary for memory accounting,
  // but we otherwise never test these for equality.
  cpp.push(`    bool operator==(const Field&) const { return false; }`)
  let indent = '    '

  for (let j = 0; j < sortedFields.length; j++) {
    let field = sortedFields[j]

    if (field.isDeprecated) {
      continue
    }

    let name = cppFieldName(field)
    let type = cppType(definitions, field, field.isArray)

    if (cppIsFieldPointer(definitions, field)) {
      cpp.push(indent + `${type} *${name};`)
    } else {
      cpp.push(indent + `${type} ${name};`)
    }
  }

  cpp.push(`  };`)
  // An array containing every field which is initialized for this message. Each element in the
  // array has an index and a field value. The index matches the field id defined in the schema.
  // The index is used to sort the fields for faster lookups. The field value is a union.
  cpp.push(`  kiwi::SparseFields<Field> _fields;`)
  cpp.push(`  friend std::hash<Field>;`)
  cpp.push('};')
  cpp.push('')
  return cpp
}

function cppGetSetImplementation(definition: Definition, definitions: { [name: string]: Definition }, copyable: boolean): string[] {
  const fields = definition.fields
  const cpp: string[] = []

  if (copyable) {
    cpp.push(`inline ${definition.name} ${definition.name}::copy() const {`)
    cpp.push(`  ${definition.name} clone = *this;`)
    cpp.push(`  return clone;`)
    cpp.push('}')
    cpp.push('')
  }

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]
    let name = cppFieldName(field)
    let type = cppType(definitions, field, field.isArray)
    let flagIndex = cppFlagIndex(j)
    let flagMask = cppFlagMask(j)

    if (field.isDeprecated) {
      continue
    }

    let setFlag = `_flags[${flagIndex}] |= ${flagMask}`
    let checkFlag = `_flags[${flagIndex}] & ${flagMask}`

    if (cppIsFieldPointer(definitions, field)) {
      cpp.push(`inline ${type} *${definition.name}::${field.name}() {`)
      cpp.push(`  return ${name};`)
      cpp.push('}')
      cpp.push('')

      cpp.push(`inline const ${type} *${definition.name}::${field.name}() const {`)
      cpp.push(`  return ${name};`)
      cpp.push('}')
      cpp.push('')

      cpp.push(`inline void ${definition.name}::set_${field.name}(${type} *value) {`)
      cpp.push(`  ${name} = value;`)
      cpp.push('}')
      cpp.push('')
    } else if (field.isArray) {
      cpp.push(`inline ${type} *${definition.name}::${field.name}() {`)
      cpp.push(`  return ${checkFlag} ? &${name} : nullptr;`)
      cpp.push('}')
      cpp.push('')

      cpp.push(`inline const ${type} *${definition.name}::${field.name}() const {`)
      cpp.push(`  return ${checkFlag} ? &${name} : nullptr;`)
      cpp.push('}')
      cpp.push('')

      cpp.push(`inline ${type} &${definition.name}::set_${field.name}(kiwi::MemoryPool &pool, uint32_t count) {`)
      cpp.push(`  ${setFlag}; return ${name} = pool.array<${cppType(definitions, field, false)}>(count);`)
      cpp.push('}')
      cpp.push('')
    } else {
      cpp.push(`inline ${type} *${definition.name}::${field.name}() {`)
      cpp.push(`  return ${checkFlag} ? &${name} : nullptr;`)
      cpp.push('}')
      cpp.push('')

      cpp.push(`inline const ${type} *${definition.name}::${field.name}() const {`)
      cpp.push(`  return ${checkFlag} ? &${name} : nullptr;`)
      cpp.push('}')
      cpp.push('')

      cpp.push(`inline void ${definition.name}::set_${field.name}(const ${type} &value) {`)
      cpp.push(`  ${setFlag}; ${name} = value;`)
      cpp.push('}')
      cpp.push('')
    }
  }

  return cpp
}

function cppEncodeImplementation(definition: Definition, definitions: { [name: string]: Definition }): string[] {
  const fields = definition.fields
  const cpp: string[] = []

  cpp.push(`bool ${definition.name}::encode(kiwi::WriteBuffer &_wb) const {`)

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]

    if (field.isDeprecated) {
      continue
    }

    let indent = '  '

    if (definition.kind === 'STRUCT') {
      cpp.push(`  if (${field.name}() == nullptr) return false;`)
    } else {
      cpp.push(`  if (${field.name}() != nullptr) {`)
      indent = '    '
    }

    let name = cppFieldName(field)
    let value = field.isArray ? '_it' : name
    let code = cppEncodeValue(definitions, field, value)

    if (definition.kind === 'MESSAGE') {
      cpp.push(indent + `_wb.writeVarUint(${field.value});`)
    }

    if (field.isArray) {
      cpp.push(indent + `_wb.writeVarUint(${name}.size());`)
      cpp.push(indent + `for (const ${cppType(definitions, field, false)} &_it : ${name}) ${code}`)
    } else {
      cpp.push(indent + code)
    }

    if (definition.kind !== 'STRUCT') {
      cpp.push('  }')
    }
  }

  if (definition.kind === 'MESSAGE') {
    cpp.push('  _wb.writeVarUint(0);')
  }

  cpp.push('  return true;')
  cpp.push('}')
  cpp.push('')
  return cpp
}

function cppDecodeImplementation(definition: Definition, definitions: { [name: string]: Definition }): string[] {
  const fields = definition.fields
  const cpp: string[] = []

  cpp.push(`bool ${definition.name}::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {`)

  for (let j = 0; j < fields.length; j++) {
    if (fields[j].isArray) {
      cpp.push('  uint32_t count;')
      break
    }
  }

  if (definition.kind === 'MESSAGE') {
    cpp.push('  while (true) {')
    cpp.push('    uint32_t type;')
    cpp.push('    if (!_bb.readVarUint(type)) return false;')
    cpp.push('    switch (type) {')
    cpp.push('      case 0:')
    cpp.push('        return true;')
  }

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]
    let name = cppFieldName(field)
    let value = field.isArray ? '_it' : name
    let isPointer = cppIsFieldPointer(definitions, field)
    let code = cppDecodeValue(definitions, field, value)
    let type = cppType(definitions, field, false)

    let flagIndex = cppFlagIndex(j)
    let flagMask = cppFlagMask(j)
    let setFlag = `_flags[${flagIndex}] |= ${flagMask}`

    let indent = '  '

    if (definition.kind === 'MESSAGE') {
      cpp.push(`      case ${field.value}: {`)
      indent = '        '
    }

    if (field.isArray) {
      cpp.push(indent + 'if (!_bb.readVarUint(count)) return false;')
      if (field.isDeprecated) {
        if (field.type === 'byte') {
          cpp.push(indent + `if (!_bb.skipCount(count)) return false;`)
        } else {
          cpp.push(indent + `for (${type} &_it : _pool.array<${type}>(count)) if (!${code}) return false;`)
        }
      } else {
        if (field.type === 'byte') {
          cpp.push(indent + `if (!_bb.readByteArray(set_${field.name}(_pool, count).data(), count)) return false;`)
        } else {
          cpp.push(indent + `for (${type} &_it : set_${field.name}(_pool, count)) if (!${code}) return false;`)
        }
      }
    } else {
      if (field.isDeprecated) {
        if (isPointer) {
          cpp.push(indent + `${type} *${name} = _pool.allocate<${type}>();`)
        } else {
          cpp.push(indent + `${type} ${name} = {};`)
        }

        cpp.push(indent + `if (!${code}) return false;`)
      } else {
        if (isPointer) {
          cpp.push(indent + `${name} = _pool.allocate<${type}>();`)
        }

        cpp.push(indent + `if (!${code}) return false;`)

        if (!isPointer) {
          cpp.push(indent + `set_${field.name}(${name});`)
        }
      }
    }

    if (definition.kind === 'MESSAGE') {
      cpp.push('        break;')
      cpp.push('      }')
    }
  }

  if (definition.kind === 'MESSAGE') {
    cpp.push('      default: {')
    cpp.push(`        if (!_schema || !_schema->skip${definition.name}Field(_bb, type)) return false;`)
    cpp.push('        break;')
    cpp.push('      }')
    cpp.push('    }')
    cpp.push('  }')
  } else {
    cpp.push('  return true;')
  }

  cpp.push('}')
  cpp.push('')
  return cpp
}

function cppSparseGetSetImplementation(definition: Definition, definitions: { [name: string]: Definition }, copyable: boolean): string[] {
  const fields = definition.fields
  const cpp: string[] = []

  if (copyable) {
    cpp.push(`inline ${definition.name} ${definition.name}::copy(kiwi::MemoryPool& pool) const {`)
    cpp.push(`  ${definition.name} clone;`)
    cpp.push(`  clone._fields = _fields.copy(pool);`)
    cpp.push(`  memcpy(clone._flags, _flags, sizeof(_flags));`)
    cpp.push(`  return clone;`)
    cpp.push('}')
    cpp.push('')
  }

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]
    let name = cppFieldName(field)
    let type = cppType(definitions, field, field.isArray)
    let flagIndex = cppFlagIndex(j)
    let flagMask = cppFlagMask(j)

    if (field.isDeprecated) {
      continue
    }

    let setFlag = `_flags[${flagIndex}] |= ${flagMask}`
    let checkFlag = `_flags[${flagIndex}] & ${flagMask}`
    let isPointer = cppIsFieldPointer(definitions, field)

    // We return optionals for primitives, strings, and arrays. Eventually we may want to use
    // something like OptRef for returning raw pointers as well. It's important that we return
    // optionals instead of pointers in the sparse implementation because elements in the fields
    // array can get sorted, invalidating any held pointers.
    if (isPointer) {
      cpp.push(`inline ${type} *${definition.name}::${field.name}() {`)
      cpp.push(`  if (!(${checkFlag})) return nullptr;`)
      cpp.push(`  Field* field = _fields.getField(${field.value});`)
      cpp.push(`  return field ? ${isPointer ? '' : '&'}field->${name} : nullptr;`)
      cpp.push('}')
      cpp.push('')

      cpp.push(`inline const ${type} *${definition.name}::${field.name}() const {`)
      cpp.push(`  if (!(${checkFlag})) return nullptr;`)
      cpp.push(`  const Field* field = _fields.getField(${field.value});`)
      cpp.push(`  return field ? ${isPointer ? '' : '&'}field->${name} : nullptr;`)
      cpp.push('}')
      cpp.push('')
    } else {
      cpp.push(`inline kiwi::Optional<${type}> ${definition.name}::${field.name}() const {`)
      cpp.push(`  if (!(${checkFlag})) return std::nullopt;`)
      cpp.push(`  const Field* field = _fields.getField(${field.value});`)
      cpp.push(`  return field ? kiwi::Optional<${type}>(field->${name}) : std::nullopt;`)
      cpp.push('}')
      cpp.push('')
    }

    // Every sparse setter needs to take a MemoryPool as input. If the field has not yet been initialized
    // we need to add a new element to SparseFields, which may require growing the underlying array. Any
    // pointers to values in SparseFields could be invalidated by this operation.
    if (cppIsFieldPointer(definitions, field)) {
      cpp.push(`inline void ${definition.name}::set_${field.name}(kiwi::MemoryPool &pool, ${type} *value) {`)
    } else if (field.isArray) {
      cpp.push(`inline ${type} &${definition.name}::set_${field.name}(kiwi::MemoryPool &pool, uint32_t count) {`)
      cpp.push(`  ${type} value = pool.array<${cppType(definitions, field, false)}>(count);`)
    } else {
      cpp.push(`inline void ${definition.name}::set_${field.name}(kiwi::MemoryPool &pool, const ${type} &value) {`)
    }

    cpp.push(`  if (${checkFlag}) {`)
    // Update existing field
    cpp.push(`    Field* field = _fields.getField(${field.value});`)
    cpp.push(`    field->${name} = value;`)
    if (field.isArray) {
      cpp.push(`    return field->${name};`)
    }
    cpp.push(`  } else {`)
    cpp.push(`    ${setFlag};`)
    // Add new field
    if (field.isArray) {
      cpp.push(`    return _fields.addField({${field.value}, Field{.${name} = value}}, pool)->field.${name};`)
    } else {
      cpp.push(`    _fields.addField({${field.value}, Field{.${name} = value}}, pool);`)
    }

    cpp.push(`  }`)
    cpp.push('}')
    cpp.push('')
  }
  return cpp
}

function cppSparseEncodeImplementation(definition: Definition, definitions: { [name: string]: Definition }): string[] {
  const fields = definition.fields
  const cpp: string[] = []

  cpp.push(`bool ${definition.name}::encode(kiwi::WriteBuffer &_wb) const {`)

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]

    if (field.isDeprecated) {
      continue
    }

    let type = cppType(definitions, field, field.isArray)
    let isPointer = cppIsFieldPointer(definitions, field)
    let returnType
    if (isPointer) {
      returnType = `${type}*`
    } else {
      returnType = `kiwi::Optional<${type}>`
    }

    let name = cppFieldName(field)
    cpp.push(`  const ${returnType} ${name} = ${field.name}();`)
    cpp.push(`  if (${name}) {`)
    if (isPointer) {
      cpp.push(`    const ${cppType(definitions, field, field.isArray)}* _data = ${name};`)
    } else {
      cpp.push(`    const ${cppType(definitions, field, field.isArray)}& _data = *${name};`)
    }

    let indent = '    '
    name = '_data'
    let value = field.isArray ? '_it' : name
    let code = cppEncodeValue(definitions, field, value)

    cpp.push(indent + `_wb.writeVarUint(${field.value});`)

    if (field.isArray) {
      cpp.push(indent + `_wb.writeVarUint(${name}.size());`)
      cpp.push(indent + `for (const ${cppType(definitions, field, false)} &_it : ${name}) ${code}`)
    } else {
      cpp.push(indent + code)
    }

    cpp.push('  }')
  }

  cpp.push('  _wb.writeVarUint(0);')
  cpp.push('  return true;')
  cpp.push('}')
  cpp.push('')

  // Optimized implementation. After a period of validation this will become the default.
  cpp.push(`bool ${definition.name}::encode2(kiwi::WriteBuffer &_wb) const {`)

  cpp.push('  for (auto* it = _fields.begin(); it != _fields.end(); it++) {')
  cpp.push('    uint32_t index = it->index;')
  cpp.push('    const Field& field = it->field;')
  cpp.push(`    _wb.writeVarUint(index);`)
  cpp.push('    switch (index) {')
  let indent = '      '

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]

    if (field.isDeprecated) {
      continue
    }

    let type = cppType(definitions, field, field.isArray)
    let isPointer = cppIsFieldPointer(definitions, field)
    let name = cppFieldName(field)
    let value = field.isArray ? '_it' : name
    let code = cppEncodeValue(definitions, field, value)
    cpp.push(indent + `case ${field.value}: {`)
    cpp.push(indent + `  const ${type}${isPointer ? '*' : '&'} ${name} = field.${name};`)

    if (field.isArray) {
      cpp.push(indent + `  _wb.writeVarUint(${name}.size());`)
      cpp.push(indent + `  for (const ${cppType(definitions, field, false)} &_it : ${name}) ${code}`)
    } else {
      cpp.push(indent + '  ' + code)
    }

    cpp.push(indent + `  break;`)
    cpp.push(indent + `}`)
  }

  cpp.push('      default: {')
  cpp.push(`        continue;`)
  cpp.push('      }')
  cpp.push('    }')
  cpp.push('  }')

  cpp.push('  _wb.writeVarUint(0);')
  cpp.push('  return true;')

  cpp.push('}')
  cpp.push('')

  return cpp
}

function cppSparseDecodeImplementation(definition: Definition, definitions: { [name: string]: Definition }): string[] {
  const fields = definition.fields
  const cpp: string[] = []
  cpp.push(`bool ${definition.name}::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {`)

  for (let j = 0; j < fields.length; j++) {
    if (fields[j].isArray) {
      cpp.push('  uint32_t count;')
      break
    }
  }

  // Allocate fields in a vector before moving them into the MemoryPool.
  // We don't know how much space we need until we decode all of the fields.
  // There are likely more efficient ways of doing this, like putting a static
  // array on the stack, to avoid incurring many heap allocations on every decode call.
  cpp.push(`  std::vector<kiwi::SparseFields<Field>::Element> tempFields;`)

  cpp.push('  while (true) {')
  cpp.push('    uint32_t type;')
  cpp.push('    if (!_bb.readVarUint(type)) return false;')
  cpp.push('    switch (type) {')
  cpp.push('      case 0: {')
  cpp.push('        _fields = kiwi::SparseFields<Field>(tempFields.data(), tempFields.size(), _pool);')
  cpp.push('        return true;')
  cpp.push('      }')

  for (let j = 0; j < fields.length; j++) {
    let field = fields[j]
    let name = cppFieldName(field)
    let value = field.isArray ? '_it' : name
    let isPointer = cppIsFieldPointer(definitions, field)
    let code = cppDecodeValue(definitions, field, value)
    let type = cppType(definitions, field, false)

    let flagIndex = cppFlagIndex(j)
    let flagMask = cppFlagMask(j)
    let setFlag = `_flags[${flagIndex}] |= ${flagMask}`

    cpp.push(`      case ${field.value}: {`)
    let indent = '        '

    if (field.isArray) {
      cpp.push(indent + 'if (!_bb.readVarUint(count)) return false;')
      if (field.isDeprecated) {
        if (field.type === 'byte') {
          cpp.push(indent + `if (!_bb.skipCount(count)) return false;`)
        } else {
          cpp.push(indent + `for (${type} &_it : _pool.array<${type}>(count)) if (!${code}) return false;`)
        }
      } else {
        cpp.push(indent + `${setFlag};`)
        cpp.push(indent + `${cppType(definitions, field, true)} ${name} = _pool.array<${type}>(count);`)
        if (field.type === 'byte') {
          cpp.push(indent + `if (!_bb.readByteArray(${name}.data(), count)) return false;`)
        } else {
          cpp.push(indent + `for (${type} &_it : ${name}) if (!${code}) return false;`)
        }
        cpp.push(indent + `tempFields.push_back({${field.value}, Field{.${name} = ${name}}});`)
      }
    } else {
      if (isPointer) {
        cpp.push(indent + `${type}* ${name} = _pool.allocate<${type}>();`)
      } else {
        cpp.push(indent + `${type} ${name} = {};`)
      }

      cpp.push(indent + `if (!${code}) return false;`)

      if (!field.isDeprecated) {
        cpp.push(indent + `${setFlag};`)
        cpp.push(indent + `tempFields.push_back({${field.value}, Field{.${name} = ${name}}});`)
      }
    }

    cpp.push('        break;')
    cpp.push('      }')
  }

  cpp.push('      default: {')
  cpp.push(`        if (!_schema || !_schema->skip${definition.name}Field(_bb, type)) return false;`)
  cpp.push('        break;')
  cpp.push('      }')
  cpp.push('    }')
  cpp.push('  }')
  cpp.push('}')
  cpp.push('')
  return cpp
}

// The generator makes these three passes over the declarations.
enum Pass {
  // Emits code like `class Foo;`
  ForwardDeclarations,
  // Emits code like `class Foo { void method(); }`
  Declarations,
  // Emits getters and setters, which we inline for performance reasons
  Inlined,
  // Emits code like `void Foo::method() { ... }`
  Implementations,
}

export function compileSchemaCPP(schema: Schema, sparseMessages: string[], copyableMessages: string[]): string {
  let definitions: { [name: string]: Definition } = {}
  for (const definition of schema.definitions) {
    definitions[definition.name] = definition
  }

  for (const sparseMessage of sparseMessages) {
    if (!(sparseMessage in definitions)) {
      error(`Requesting sparse implementation for ${quote(sparseMessage)} which is not defined in the schema`, 0, 0)
    }
  }

  let cpp: string[] = []

  cpp.push('#include "kiwi.h"')
  cpp.push('')

  if (schema.package !== null) {
    cpp.push(`namespace ${schema.package} {`)
    cpp.push('')
    cpp.push(`#ifndef INCLUDE_${schema.package.toUpperCase()}_H`)
    cpp.push(`#define INCLUDE_${schema.package.toUpperCase()}_H`)
    cpp.push('')
  }

  cpp.push('class BinarySchema {')
  cpp.push('public:')
  cpp.push('  bool parse(kiwi::ByteBuffer &bb);')
  cpp.push('  const kiwi::BinarySchema &underlyingSchema() const { return _schema; }')

  for (let i = 0; i < schema.definitions.length; i++) {
    let definition = schema.definitions[i]
    if (definition.kind === 'MESSAGE') {
      cpp.push(`  bool skip${definition.name}Field(kiwi::ByteBuffer &bb, uint32_t id) const;`)
    }
  }

  cpp.push('')
  cpp.push('private:')
  cpp.push('  kiwi::BinarySchema _schema;')

  for (let i = 0; i < schema.definitions.length; i++) {
    let definition = schema.definitions[i]
    if (definition.kind === 'MESSAGE') {
      cpp.push(`  uint32_t _index${definition.name} = 0;`)
    }
  }

  cpp.push('};')
  cpp.push('')

  for (let i = 0; i < schema.definitions.length; i++) {
    let definition = schema.definitions[i]

    if (definition.kind === 'ENUM') {
      cpp.push(`enum class ${definition.name} : uint32_t {`)
      for (let j = 0; j < definition.fields.length; j++) {
        let field = definition.fields[j]
        cpp.push(`  ${field.name} = ${field.value},`)
      }
      cpp.push('};')
      cpp.push('')
    } else if (definition.kind !== 'STRUCT' && definition.kind !== 'MESSAGE') {
      error(`Invalid definition kind ${quote(definition.kind)}`, definition.line, definition.column)
    }
  }

  for (const pass of [Pass.ForwardDeclarations, Pass.Declarations, Pass.Inlined, Pass.Implementations]) {
    let newline = false

    if (pass === Pass.Implementations) {
      if (schema.package !== null) {
        if (sparseMessages.length > 0) {
          // Generate a no-op std::hash implementations for the fields of any sparse messages.
          // This allows us to TypeID() these fields, as necessary for memory accounting,
          // but we otherwise never hash these.
          cpp.push(`}  // namespace ${schema.package}`)

          for (const msg of sparseMessages) {
            cpp.push(`template<>`)
            cpp.push(`struct std::hash<${schema.package}::${msg}::Field> {`)
            cpp.push(`  size_t operator()(const ${schema.package}::${msg}::Field& msg) const {`)
            cpp.push(`    return 0;`)
            cpp.push(`  }`)
            cpp.push(`};`)
          }

          cpp.push(`namespace ${schema.package} {`)
        }

        cpp.push(`#endif  // INCLUDE_${schema.package.toUpperCase()}_H`)
      }

      cpp.push('#ifdef IMPLEMENT_SCHEMA_H')
      cpp.push('')

      cpp.push('bool BinarySchema::parse(kiwi::ByteBuffer &bb) {')
      cpp.push('  if (!_schema.parse(bb)) return false;')

      for (let i = 0; i < schema.definitions.length; i++) {
        let definition = schema.definitions[i]
        if (definition.kind === 'MESSAGE') {
          cpp.push(`  _schema.findDefinition("${definition.name}", _index${definition.name});`)
        }
      }

      cpp.push('  return true;')
      cpp.push('}')
      cpp.push('')

      for (let i = 0; i < schema.definitions.length; i++) {
        let definition = schema.definitions[i]

        if (definition.kind === 'MESSAGE') {
          cpp.push(`bool BinarySchema::skip${definition.name}Field(kiwi::ByteBuffer &bb, uint32_t id) const {`)
          cpp.push(`  return _schema.skipField(bb, _index${definition.name}, id);`)
          cpp.push('}')
          cpp.push('')
        }
      }
    }

    for (let i = 0; i < schema.definitions.length; i++) {
      let definition = schema.definitions[i]

      if (definition.kind === 'ENUM') {
        continue
      }

      let fields = definition.fields
      let sparse = sparseMessages.includes(definition.name)

      if (sparse && definition.kind !== 'MESSAGE') {
        let message = `Type ${quote(definition.name)} cannot be declared as sparse. `
        message += `${quote(definition.name)} is type ${quote(definition.kind)}, but needs to be a MESSAGE.`
        error(message, definition.line, definition.column)
      }

      if (pass === Pass.ForwardDeclarations) {
        cpp.push(`class ${definition.name};`)
        newline = true
      } else if (pass === Pass.Declarations) {
        if (sparse) {
          cpp = cpp.concat(cppSparseDeclaration(definition, definitions, copyableMessages.includes(definition.name)))
        } else {
          cpp = cpp.concat(cppDeclaration(definition, definitions, copyableMessages.includes(definition.name)))
        }
      } else if (pass === Pass.Inlined) {
        if (sparse) {
          cpp = cpp.concat(cppSparseGetSetImplementation(definition, definitions, copyableMessages.includes(definition.name)))
        } else {
          cpp = cpp.concat(cppGetSetImplementation(definition, definitions, copyableMessages.includes(definition.name)))
        }
      } else {
        if (sparse) {
          cpp = cpp.concat(cppSparseEncodeImplementation(definition, definitions))
          cpp = cpp.concat(cppSparseDecodeImplementation(definition, definitions))
        } else {
          cpp = cpp.concat(cppEncodeImplementation(definition, definitions))
          cpp = cpp.concat(cppDecodeImplementation(definition, definitions))
        }
      }
    }

    if (pass === Pass.Implementations) {
      cpp.push('#endif  // IMPLEMENT_SCHEMA_H')
      cpp.push('')
    } else if (newline) cpp.push('')
  }

  if (schema.package !== null) {
    cpp.push(`}  // namespace ${schema.package}`)
    cpp.push('')
  }

  return cpp.join('\n')
}
