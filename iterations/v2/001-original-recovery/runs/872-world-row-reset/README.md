# World row initialization

`00478d90..00478e46` first stores the incoming word at row offset +0x34, then copies three vectors one word at a time. This order matters when inputs overlap the row, as they do in the world reset caller. The routine computes twice the squared difference between the first and third X components in x87, rounds the result to binary32, and calls the existing square-root routine at `005327d0`. It stores the radius at +0x30 and initializes the remaining fields of the 80-byte row.

[Native attempt 003](native-config.json) passed 192 cases per optimization level. The fixture executes the original row body and original square-root bytes, and compares the full row, guard words, stack cleanup and x87 stack depth for distinct and overlapping inputs. It covers zero, subnormal and extreme finite coordinates, and preserves the separate +0x34 word bit for bit. The shared build binds Run821's square-root provider. Four mutations were detected.
