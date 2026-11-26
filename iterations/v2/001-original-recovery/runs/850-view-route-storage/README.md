# Run850 route registry and camera storage

Porsche.exe 0040f258..0040f265 indexes 005e8c00 with the count at 005e8bfc
and increments the count. The next table starts at 005e8c24. These 40 bytes
lie beyond the raw .data extent in the loader-zeroed tail. Run693 owned the
nine pointer slots. The audio reset (004a6e30) and FE reset (00413ea0)
expected the count and slots in one dword array. All three now share the
10-word definition. The proof covers valid slot indices 0 through 8 at the
tested endpoints and interior index. Behavior past the table remains open.

004640b0 also writes 005cf620/624/628, the first three dwords of preset 1
in the Run849 table at 005cf610. It now updates that row in place. The
unchanged reader at 004618b0 consumes the same table. Run693's separate
camera vector is superseded. The fixture checks the raw PE initializer,
the selected route object and the adjacent preset flags and registry count.

Native attempt 001 passed 130 original comparisons per optimization. Both
the wrong-preset and count-clobber controls diverged. Live scene and audio
device behavior remain open.
