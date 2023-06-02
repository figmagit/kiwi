// HashTable
//
// This is a hashtable with generic keys and values and where the keys must have
// a *number* hash!
//
// Hashing/bucketing logic is all implemented manually.

export type HashPair<A, B> = {
  key: A
  value: B
}

export class HashTable<K, V> {
  private _buckets: Map<number, HashPair<K, V>[]>
  private _hash: (key: K) => number
  private _equals: (a: K, b: K) => boolean

  constructor(hash: (key: K) => number, equals: (a: K, b: K) => boolean) {
    this._buckets = new Map<number, HashPair<K, V>[]>()
    this._hash = hash
    this._equals = equals
  }

  get(key: K, defaultValue: V): V {
    let hash = this._hash(key)
    let bucket = this._buckets.get(hash)
    if (bucket !== void 0) {
      for (let i = 0; i < bucket.length; ++i) {
        const pair = bucket[i]
        if (this._equals(key, pair.key)) {
          return pair.value
        }
      }
    }
    return defaultValue
  }

  set(key: K, value: V): V {
    let hash = this._hash(key)
    let bucket = this._buckets.get(hash)
    if (bucket === void 0) {
      bucket = []
      this._buckets.set(hash, bucket)
    }
    for (let i = 0; i < bucket.length; ++i) {
      let pair = bucket[i]
      if (this._equals(key, pair.key)) {
        pair.value = value
        return value
      }
    }
    bucket.push({ key, value })
    return value
  }

  remove(key: K): void {
    let hash = this._hash(key)
    let bucket = this._buckets.get(hash)
    if (bucket !== void 0) {
      for (let i = 0; i < bucket.length; ++i) {
        if (this._equals(key, bucket[i].key)) {
          bucket.splice(i, 1)
          if (bucket.length === 0) {
            this._buckets.delete(hash)
          }
          break
        }
      }
    }
  }
}
