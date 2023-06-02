var test_dedup = exports || test_dedup || {}, exports;
test_dedup.ByteBuffer = test_dedup.ByteBuffer || require("kiwi-schema").ByteBuffer;

test_dedup["decodeStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["name"] = bb.readString();
  result["f0"] = bb.readVarInt();
  result["f1"] = bb.readVarInt();
  result["f2"] = bb.readVarInt();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test_dedup["encodeStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["name"];
  if (value != null) {
    bb.writeString(value);
  } else {
    throw new Error("Missing required field \"name\"");
  }

  var value = message["f0"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"f0\"");
  }

  var value = message["f1"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"f1\"");
  }

  var value = message["f2"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"f2\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test_dedup["hashStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readString();
  hasher.readVarInt();
  hasher.readVarInt();
  hasher.readVarInt();
  return;
};

test_dedup["decodeDuplicatedStruct"] = function(bb, optDedupCache) {
  var dedupKey = null;
  if (!!optDedupCache) {
    if (!(optDedupCache instanceof this.HashTable)) {
      throw new Error("optDedupCache must be instance of HashTable");
    }
    // lookahead with hasher then reference result with dedup cache
    var hasher = new this.Hasher(bb.getNewWindowFromRight());
    this["hashDuplicatedStruct"](hasher);
    dedupKey = { hash: hasher.value(), data: hasher.windowToUint8Array(), defName: "DuplicatedStruct" };
    var cachedResult = optDedupCache.get(dedupKey, null);
    if (cachedResult !== null) {
      bb.extendWindowTo(hasher.bb());
      return cachedResult;
    }
  }
  var result = {};
  if (!(bb instanceof this.ByteBuffer)) {
    bb = new this.ByteBuffer(bb);
  }

  result["name"] = bb.readString();
  result["f0"] = bb.readVarInt();
  result["f1"] = bb.readVarInt();
  result["f2"] = bb.readVarInt();
  return dedupKey !== null ? optDedupCache.set(dedupKey, result) : result;
};

test_dedup["encodeDuplicatedStruct"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["name"];
  if (value != null) {
    bb.writeString(value);
  } else {
    throw new Error("Missing required field \"name\"");
  }

  var value = message["f0"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"f0\"");
  }

  var value = message["f1"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"f1\"");
  }

  var value = message["f2"];
  if (value != null) {
    bb.writeVarInt(value);
  } else {
    throw new Error("Missing required field \"f2\"");
  }

  if (isTopLevel) return bb.toUint8Array();
};

test_dedup["hashDuplicatedStruct"] = function(hasher) {
  var result = {};
  if (!(hasher instanceof this.Hasher)) {
    throw new Error("Expected Hasher");
  }

  hasher.readString();
  hasher.readVarInt();
  hasher.readVarInt();
  hasher.readVarInt();
  return;
};

test_dedup["decodeMessage"] = function(bb, optDedupCache) {
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
      result["name"] = bb.readString();
      break;

    case 2:
      result["f0"] = bb.readVarInt();
      break;

    case 3:
      result["f1"] = bb.readVarInt();
      break;

    case 4:
      result["f2"] = bb.readVarInt();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["encodeMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["f0"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarInt(value);
  }

  var value = message["f1"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarInt(value);
  }

  var value = message["f2"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test_dedup["hashMessage"] = function(hasher) {
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

    case 2:
      hasher.readVarInt();
      break;

    case 3:
      hasher.readVarInt();
      break;

    case 4:
      hasher.readVarInt();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["decodeDuplicatedMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  if (!!optDedupCache) {
    if (!(optDedupCache instanceof this.HashTable)) {
      throw new Error("optDedupCache must be instance of HashTable");
    }
    // lookahead with hasher then reference result with dedup cache
    var hasher = new this.Hasher(bb.getNewWindowFromRight());
    this["hashDuplicatedMessage"](hasher);
    dedupKey = { hash: hasher.value(), data: hasher.windowToUint8Array(), defName: "DuplicatedMessage" };
    var cachedResult = optDedupCache.get(dedupKey, null);
    if (cachedResult !== null) {
      bb.extendWindowTo(hasher.bb());
      return cachedResult;
    }
  }
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
      result["name"] = bb.readString();
      break;

    case 2:
      result["f0"] = bb.readVarInt();
      break;

    case 3:
      result["f1"] = bb.readVarInt();
      break;

    case 4:
      result["f2"] = bb.readVarInt();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["encodeDuplicatedMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["f0"];
  if (value != null) {
    bb.writeVarUint(2);
    bb.writeVarInt(value);
  }

  var value = message["f1"];
  if (value != null) {
    bb.writeVarUint(3);
    bb.writeVarInt(value);
  }

  var value = message["f2"];
  if (value != null) {
    bb.writeVarUint(4);
    bb.writeVarInt(value);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test_dedup["hashDuplicatedMessage"] = function(hasher) {
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

    case 2:
      hasher.readVarInt();
      break;

    case 3:
      hasher.readVarInt();
      break;

    case 4:
      hasher.readVarInt();
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["decodeDuplicatedSuperMessage"] = function(bb, optDedupCache) {
  var dedupKey = null;
  if (!!optDedupCache) {
    if (!(optDedupCache instanceof this.HashTable)) {
      throw new Error("optDedupCache must be instance of HashTable");
    }
    // lookahead with hasher then reference result with dedup cache
    var hasher = new this.Hasher(bb.getNewWindowFromRight());
    this["hashDuplicatedSuperMessage"](hasher);
    dedupKey = { hash: hasher.value(), data: hasher.windowToUint8Array(), defName: "DuplicatedSuperMessage" };
    var cachedResult = optDedupCache.get(dedupKey, null);
    if (cachedResult !== null) {
      bb.extendWindowTo(hasher.bb());
      return cachedResult;
    }
  }
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
      result["name"] = bb.readString();
      break;

    case 2:
      result["m"] = this["decodeMessage"](bb, optDedupCache || null);
      break;

    case 3:
      result["s"] = this["decodeStruct"](bb, optDedupCache || null);
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["encodeDuplicatedSuperMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["m"];
  if (value != null) {
    bb.writeVarUint(2);
    this["encodeMessage"](value, bb);
  }

  var value = message["s"];
  if (value != null) {
    bb.writeVarUint(3);
    this["encodeStruct"](value, bb);
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test_dedup["hashDuplicatedSuperMessage"] = function(hasher) {
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

    case 2:
      this["hashMessage"](hasher);
      break;

    case 3:
      this["hashStruct"](hasher);
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["decodeSuperMessageWithDuplicatedArrays"] = function(bb, optDedupCache) {
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
      result["name"] = bb.readString();
      break;

    case 2:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeDuplicatedMessage"](bb, optDedupCache || null);
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["dmArr"] = values;
      break;

    case 3:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeDuplicatedStruct"](bb, optDedupCache || null);
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["dsArr"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["encodeSuperMessageWithDuplicatedArrays"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["dmArr"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeDuplicatedMessage"](value, bb);
    }
  }

  var value = message["dsArr"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeDuplicatedStruct"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test_dedup["hashSuperMessageWithDuplicatedArrays"] = function(hasher) {
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

    case 2:
      var length = hasher.readVarUint();
      while (length-- > 0) this["hashDuplicatedMessage"](hasher);
      break;

    case 3:
      var length = hasher.readVarUint();
      while (length-- > 0) this["hashDuplicatedStruct"](hasher);
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["decodeSuperSuperMessage"] = function(bb, optDedupCache) {
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
      result["name"] = bb.readString();
      break;

    case 2:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeDuplicatedStruct"](bb, optDedupCache || null);
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["dsArr"] = values;
      break;

    case 3:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeDuplicatedMessage"](bb, optDedupCache || null);
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["dmArr"] = values;
      break;

    case 4:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeDuplicatedSuperMessage"](bb, optDedupCache || null);
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["dsmArr"] = values;
      break;

    case 5:
      var arrayDedupKey = null;
      var values = null;
      if (values === null) {
        var length = bb.readVarUint();
        var values = Array(length);
        for (var i = 0; i < length; i++) values[i] = this["decodeSuperMessageWithDuplicatedArrays"](bb, optDedupCache || null);
        if (arrayDedupKey !== null) { optDedupCache.set(arrayDedupKey, values); }
      }
      result["smwdaArr"] = values;
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};

test_dedup["encodeSuperSuperMessage"] = function(message, bb) {
  var isTopLevel = !bb;
  if (isTopLevel) bb = new this.ByteBuffer();

  var value = message["name"];
  if (value != null) {
    bb.writeVarUint(1);
    bb.writeString(value);
  }

  var value = message["dsArr"];
  if (value != null) {
    bb.writeVarUint(2);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeDuplicatedStruct"](value, bb);
    }
  }

  var value = message["dmArr"];
  if (value != null) {
    bb.writeVarUint(3);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeDuplicatedMessage"](value, bb);
    }
  }

  var value = message["dsmArr"];
  if (value != null) {
    bb.writeVarUint(4);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeDuplicatedSuperMessage"](value, bb);
    }
  }

  var value = message["smwdaArr"];
  if (value != null) {
    bb.writeVarUint(5);
    var values = value, n = values.length;
    bb.writeVarUint(n);
    for (var i = 0; i < n; i++) {
      value = values[i];
      this["encodeSuperMessageWithDuplicatedArrays"](value, bb);
    }
  }
  bb.writeVarUint(0);

  if (isTopLevel) return bb.toUint8Array();
};

test_dedup["hashSuperSuperMessage"] = function(hasher) {
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

    case 2:
      var length = hasher.readVarUint();
      while (length-- > 0) this["hashDuplicatedStruct"](hasher);
      break;

    case 3:
      var length = hasher.readVarUint();
      while (length-- > 0) this["hashDuplicatedMessage"](hasher);
      break;

    case 4:
      var length = hasher.readVarUint();
      while (length-- > 0) this["hashDuplicatedSuperMessage"](hasher);
      break;

    case 5:
      var length = hasher.readVarUint();
      while (length-- > 0) this["hashSuperMessageWithDuplicatedArrays"](hasher);
      break;

    default:
      throw new Error("Attempted to parse invalid message");
    }
  }
};
