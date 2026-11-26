# Session reset records

The reset gate at `004030b0` supplies the receiver in ECX and a callee-popped payload pointer to `0040e3b0`. The parent initializes the count, reciprocal and two ranges inside a 0x34c-byte object. The record walker at `0040e440` stores each pointer, advances by the original byte length and writes the inline tail pointer for type 5 when the flag's low byte is nonzero. An unrecognized record has a zero-byte span and still increments the count.

The caller pushes the address of [the comparator](original-index-supplement.json) at `0040e40a`. It subtracts the two 32-bit keys with x86 wraparound. The recovered parent uses the existing original sort and x87 scalar owners. After sorting it reloads the count and stores the single-precision reciprocal with the original x87 sequence.

Native attempt `007` passed 120 comparisons per optimization level and detected three mutations. Both paths use the Run369 sort. The oracle executes all three original bodies. Checks include full receiver and payload bytes, untouched pointers and guard words, up to 100 entries, mixed record lengths, the flag's low byte, wrapped span and comparison arithmetic, and reciprocal bits. The accepted parent domain requires a writable, adequately sized payload and room for every collected pointer. Live race state remains untested.
