var test = exports || test || {}, exports;
test.ByteBuffer = test.ByteBuffer || require("kiwi-schema").ByteBuffer;
test["Enum"] = {
  "100": "A",
  "200": "B",
  "A": 100,
  "B": 200
};

test["decodeEnumStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = this["Enum"][bb.readVarUint()];
  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = this["Enum"][bb.readVarUint()];
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["y"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeEnumStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var encoded = this["Enum"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"Enum\""); bb.writeVarUint(encoded);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  var value = message["y"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      var encoded = this["Enum"][value]; if (encoded === void 0) throw new Error("Invalid value " + JSON.stringify(value) + " for enum \"Enum\""); bb.writeVarUint(encoded);
    }
  } else {
    throw new Error("Missing required field \"y\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashEnumStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readVarUint();
  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarUint();
  return;
};

test["decodeBoolStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = !!bb.readByte();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeBoolStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeByte(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashBoolStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readByte();
  return;
};

test["decodeByteStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readByte();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeByteStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeByte(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashByteStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readByte();
  return;
};

test["decodeIntStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readVarInt();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeIntStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashIntStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readVarInt();
  return;
};

test["decodeUintStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readVarUint();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeUintStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashUintStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readVarUint();
  return;
};

test["decodeInt64Struct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readVarInt64();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeInt64Struct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarInt64(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashInt64Struct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readVarInt64();
  return;
};

test["decodeUint64Struct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readVarUint64();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeUint64Struct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint64(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashUint64Struct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readVarUint64();
  return;
};

test["decodeFloatStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readVarFloat();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeFloatStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashFloatStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readVarFloat();
  return;
};

test["decodeStringStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readString();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeStringStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeString(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashStringStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readString();
  return;
};

test["decodeCompoundStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readVarUint();
  result["y"] = bb.readVarUint();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeCompoundStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  var value = message["y"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"y\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashCompoundStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readVarUint();
  hasher.readVarUint();
  return;
};

test["decodeNestedStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["a"] = bb.readVarUint();
  result["b"] = this["decodeCompoundStruct"](bb, optDedupCache || null);
  result["c"] = bb.readVarUint();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeNestedStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["a"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"a\"");
  }

  var value = message["b"];
  if (value != null) {
    this["encodeCompoundStruct"](value, bb);
  } else {
    throw new Error("Missing required field \"b\"");
  }

  var value = message["c"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"c\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashNestedStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readVarUint();
  this["hashCompoundStruct"](hasher);
  hasher.readVarUint();
  return;
};

test["decodeBoolMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = !!bb.readByte();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeBoolMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeByte(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashBoolMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readByte();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeByteMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readByte();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeByteMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeByte(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashByteMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readByte();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeIntMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readVarInt();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeIntMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashIntMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarInt();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeUintMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeUintMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashUintMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeInt64Message"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readVarInt64();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeInt64Message"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarInt64(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashInt64Message"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarInt64();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeUint64Message"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readVarUint64();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeUint64Message"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint64(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashUint64Message"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarUint64();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeFloatMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readVarFloat();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeFloatMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarFloat(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashFloatMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarFloat();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeStringMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readString();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeStringMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashStringMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readString();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeCompoundMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readVarUint();
      break;

    case 2:
      result["y"] = bb.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeCompoundMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["y"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarUint(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashCompoundMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarUint();
      break;

    case 2:
      hasher.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeNestedMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["a"] = bb.readVarUint();
      break;

    case 2:
      result["b"] = this["decodeCompoundMessage"](bb, optDedupCache || null);
      break;

    case 3:
      result["c"] = bb.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeNestedMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["a"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["b"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeCompoundMessage"](value, bb);
  }

  var value = message["c"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarUint(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashNestedMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarUint();
      break;

    case 2:
      this["hashCompoundMessage"](hasher);
      break;

    case 3:
      hasher.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeBoolArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = !!bb.readByte();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["x"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeBoolArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeByte(value);
    }
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashBoolArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readByte();
  return;
};

test["decodeByteArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["x"] = bb.readByteArray();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeByteArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeByteArray(value);
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashByteArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readByteArray();
  return;
};

test["decodeIntArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarInt();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["x"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeIntArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt(value);
    }
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashIntArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarInt();
  return;
};

test["decodeUintArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["x"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeUintArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashUintArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarUint();
  return;
};

test["decodeInt64ArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarInt64();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["x"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeInt64ArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt64(value);
    }
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashInt64ArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarInt64();
  return;
};

test["decodeUint64ArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarUint64();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["x"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeUint64ArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint64(value);
    }
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashUint64ArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarUint64();
  return;
};

test["decodeFloatArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarFloat();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["x"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeFloatArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarFloat(value);
    }
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashFloatArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarFloat();
  return;
};

test["decodeStringArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readString();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["x"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeStringArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeString(value);
    }
  } else {
    throw new Error("Missing required field \"x\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashStringArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readString();
  return;
};

test["decodeCompoundArrayStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["x"] = values;
  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["y"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeCompoundArrayStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  } else {
    throw new Error("Missing required field \"x\"");
  }

  var value = message["y"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  } else {
    throw new Error("Missing required field \"y\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashCompoundArrayStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarUint();
  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarUint();
  return;
};

test["decodeBoolArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = !!bb.readByte();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["x"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeBoolArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeByte(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashBoolArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readByte();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeByteArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = bb.readByteArray();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeByteArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeByteArray(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashByteArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readByteArray();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeIntArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarInt();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["x"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeIntArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashIntArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarInt();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeUintArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["x"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeUintArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashUintArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeInt64ArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarInt64();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["x"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeInt64ArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt64(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashInt64ArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarInt64();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeUint64ArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarUint64();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["x"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeUint64ArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint64(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashUint64ArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarUint64();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeFloatArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarFloat();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["x"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeFloatArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarFloat(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashFloatArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarFloat();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeStringArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readString();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["x"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeStringArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeString(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashStringArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readString();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeCompoundArrayMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["x"] = values;
      break;

    case 2:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["y"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeCompoundArrayMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  }

  var value = message["y"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashCompoundArrayMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarUint();
      break;

    case 2:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeRecursiveMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["x"] = this["decodeRecursiveMessage"](bb, optDedupCache || null);
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeRecursiveMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["x"];
  if (value != null) {
    bb.writeVarUint(1);
    this["encodeRecursiveMessage"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashRecursiveMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      this["hashRecursiveMessage"](hasher);
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeNonDeprecatedMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["a"] = bb.readVarUint();
      break;

    case 2:
      result["b"] = bb.readVarUint();
      break;

    case 3:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["c"] = values;
      break;

    case 4:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["d"] = values;
      break;

    case 5:
      result["e"] = this["decodeByteStruct"](bb, optDedupCache || null);
      break;

    case 6:
      result["f"] = this["decodeByteStruct"](bb, optDedupCache || null);
      break;

    case 7:
      result["g"] = bb.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeNonDeprecatedMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["a"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["b"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarUint(value);
  }

  var value = message["c"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  }

  var value = message["d"];
  if (value != null) {
    bb.writeVarUint(4);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  }

  var value = message["e"];
  if (value != null) {
    bb.writeVarUint(5);
    this["encodeByteStruct"](value, bb);
  }

  var value = message["f"];
  if (value != null) {
    bb.writeVarUint(6);
    this["encodeByteStruct"](value, bb);
  }

  var value = message["g"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeVarUint(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashNonDeprecatedMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarUint();
      break;

    case 2:
      hasher.readVarUint();
      break;

    case 3:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarUint();
      break;

    case 4:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarUint();
      break;

    case 5:
      this["hashByteStruct"](hasher);
      break;

    case 6:
      this["hashByteStruct"](hasher);
      break;

    case 7:
      hasher.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeDeprecatedMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  while (true) {
  var x = bb.readVarUint();
    switch (x) {
    case 0:
      return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;

    case 1:
      result["a"] = bb.readVarUint();
      break;

    case 2:
      bb.readVarUint();
      break;

    case 3:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["c"] = values;
      break;

    case 4:
      var length = bb.readVarUint();
      while (length-- > 0) bb.readVarUint();
      break;

    case 5:
      result["e"] = this["decodeByteStruct"](bb, optDedupCache || null);
      break;

    case 6:
      this["decodeByteStruct"](bb, optDedupCache || null);
      break;

    case 7:
      result["g"] = bb.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["encodeDeprecatedMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["a"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeVarUint(value);
  }

  var value = message["c"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  }

  var value = message["e"];
  if (value != null) {
    bb.writeVarUint(5);
    this["encodeByteStruct"](value, bb);
  }

  var value = message["g"];
  if (value != null) {
    bb.writeVarUint(7);
    bb.writeVarUint(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test["hashDeprecatedMessage"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  while (true) {
    switch (hasher.readVarUint()) {
    case 0:
      return;

    case 1:
      hasher.readVarUint();
      break;

    case 2:
      hasher.readVarUint();
      break;

    case 3:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarUint();
      break;

    case 4:
      var length = hasher.readVarUint();
      while (length-- > 0) hasher.readVarUint();
      break;

    case 5:
      this["hashByteStruct"](hasher);
      break;

    case 6:
      this["hashByteStruct"](hasher);
      break;

    case 7:
      hasher.readVarUint();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test["decodeSortedStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["a1"] = !!bb.readByte();
  result["b1"] = bb.readByte();
  result["c1"] = bb.readVarInt();
  result["d1"] = bb.readVarUint();
  result["e1"] = bb.readVarFloat();
  result["f1"] = bb.readString();
  result["a2"] = !!bb.readByte();
  result["b2"] = bb.readByte();
  result["c2"] = bb.readVarInt();
  result["d2"] = bb.readVarUint();
  result["e2"] = bb.readVarFloat();
  result["f2"] = bb.readString();
  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = !!bb.readByte();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["a3"] = values;
  result["b3"] = bb.readByteArray();
  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarInt();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["c3"] = values;
  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarUint();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["d3"] = values;
  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readVarFloat();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["e3"] = values;
  var arrayDedupKey = null;
  var values = null;
  if (values === null) {
    var length = bb.readVarUint();
    var values = Array(length);
    for (var i = 0; i < length; i++) values[i] = bb.readString();
    if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
  }
  result["f3"] = values;
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test["encodeSortedStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["a1"];
  if (value != null) {
    bb.writeByte(value);
  } else {
    throw new Error("Missing required field \"a1\"");
  }

  var value = message["b1"];
  if (value != null) {
    bb.writeByte(value);
  } else {
    throw new Error("Missing required field \"b1\"");
  }

  var value = message["c1"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"c1\"");
  }

  var value = message["d1"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"d1\"");
  }

  var value = message["e1"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"e1\"");
  }

  var value = message["f1"];
  if (value != null) {
    bb.writeString(value);
  } else {
    throw new Error("Missing required field \"f1\"");
  }

  var value = message["a2"];
  if (value != null) {
    bb.writeByte(value);
  } else {
    throw new Error("Missing required field \"a2\"");
  }

  var value = message["b2"];
  if (value != null) {
    bb.writeByte(value);
  } else {
    throw new Error("Missing required field \"b2\"");
  }

  var value = message["c2"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"c2\"");
  }

  var value = message["d2"];
  if (value != null) {
    bb.writeVarUint(value);
  } else {
    throw new Error("Missing required field \"d2\"");
  }

  var value = message["e2"];
  if (value != null) {
    bb.writeVarFloat(value);
  } else {
    throw new Error("Missing required field \"e2\"");
  }

  var value = message["f2"];
  if (value != null) {
    bb.writeString(value);
  } else {
    throw new Error("Missing required field \"f2\"");
  }

  var value = message["a3"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeByte(value);
    }
  } else {
    throw new Error("Missing required field \"a3\"");
  }

  var value = message["b3"];
  if (value != null) {
    bb.writeByteArray(value);
  } else {
    throw new Error("Missing required field \"b3\"");
  }

  var value = message["c3"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarInt(value);
    }
  } else {
    throw new Error("Missing required field \"c3\"");
  }

  var value = message["d3"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarUint(value);
    }
  } else {
    throw new Error("Missing required field \"d3\"");
  }

  var value = message["e3"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeVarFloat(value);
    }
  } else {
    throw new Error("Missing required field \"e3\"");
  }

  var value = message["f3"];
  if (value != null) {
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      bb.writeString(value);
    }
  } else {
    throw new Error("Missing required field \"f3\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test["hashSortedStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readByte();
  hasher.readByte();
  hasher.readVarInt();
  hasher.readVarUint();
  hasher.readVarFloat();
  hasher.readString();
  hasher.readByte();
  hasher.readByte();
  hasher.readVarInt();
  hasher.readVarUint();
  hasher.readVarFloat();
  hasher.readString();
  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readByte();
  hasher.readByteArray();
  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarInt();
  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarUint();
  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readVarFloat();
  var length = hasher.readVarUint();
  while (length-- > 0) hasher.readString();
  return;
};
