# Player reset dispatcher

`004110a0` copies the primary player table into two nine-word mirrors, then calls `00410730` once for each primary and secondary player. The copy latches the initial primary bound. Each callback can change subsequent loop bounds. The first secondary index uses the final primary count from the preceding path. See [verified storage and call sites](scope-evidence.json).

Native attempt `005` compares the relocated 131-byte original at both optimization levels. Ten cases per level include empty and negative primary counts, nine primary slots, 128 secondary slots and callback-induced growth or shrinkage. Six mutations were detected. The player initialization performed by `00410730` remains open.
