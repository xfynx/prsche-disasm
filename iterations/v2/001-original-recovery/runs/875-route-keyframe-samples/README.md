# Route keyframe samples

The two route getters load a cursor from +0x48 and a signed track position from +0x50. The common lookup at `0045a560` maintains two cached indices into 0x30-byte keys. It searches on a cache miss using `0045a540`, wraps at the last key, and uses the canonical road length from `00628bc0` for signed distances. Equal indices or equal positions return one. Neither getter clamps the interpolation weight.

Each getter rounds the lookup's ST0 weight to binary32, reloads the cursor, and interpolates the field at +0x20 or +0x18. The two interpolation leaves return their unrounded sums in ST0. All six indexed bodies and their hashes are in the [native config](native-config.json).

Native attempt 003 passed 12,672 comparisons at each optimization level. Tests compare the entire cursor and all ten bytes of the x87 return for cache hits, misses, repeated positions, wraparound and four rounding modes. They use valid key storage and a positive road length. Five mutations were detected. Earlier attempts retained normal passes and exposed ambiguous mutation anchors.
