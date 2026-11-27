# Scene emitter reset

`004581a0` clears four vectors, calls the existing table reset at `004580e0`, and updates the emitter's threshold flag and cached count. Its x87 comparisons treat unordered inputs differently on the gate and count branches. Changed counts pass through both the current rounding mode and the original truncation routine. For each active slot the caller sets its flag, places the particle, and reloads the count.

`004583f0` makes two ordered unit-random draws. It rounds the first scaled offset before making the second draw, writes the three coordinates, then reloads each stored float for the final addition. The [native config](native-config.json) pins the parent, placement function, original table reset and conversion bytes. The shared game uses the Run821 and Run522 providers for these calls.

Native attempt 001 passed 768 full-emitter comparisons per optimization level and detected five mutations. Fixtures cover values around both thresholds, stale and unchanged counts, unordered samples, four rounding modes, random draw count and order, and all untouched emitter bytes. The matrix uses valid slot counts; live particle rendering remains open.
