# Scene records and coordinate samplers

`00459260..00459504` obtains two route samples, clears selected fields of two emitter records and initializes their active entries. The original comparison treats an unordered x87 result as equal. Changed samples recompute a count using the current x87 rounding mode and the original intermediate float store. The final emitter callback receives the second sample followed by the first.

Three samplers at `00459510`, `00459560` and `004595b0` share the original integer seed update, scale and offset calculation. They return unrounded values in ST0. The first record inlines these operations in the binary; the second calls all three. The recovered parent stores each result to a 32-bit float at the same boundary. Run851 owns the RNG words, Run468 the binary scale, Run700 the stage pointer, Run786 the flare table accessor and Run821 the unit-random provider.

[Native attempt 004](native-config.json) passed 1,024 cases per optimization level, including direct comparisons of all ten bytes of each x87 return in four rounding modes. Parent checks cover the two full record buffers, aliased records, RNG progression and call order. Four mutations were detected. Original route getters `0045cfd0` and `0045d000` and emitter reset `004581a0` remain external.
