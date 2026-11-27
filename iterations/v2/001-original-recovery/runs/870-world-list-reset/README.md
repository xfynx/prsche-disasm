# World list reset

The original at `00479dd0..00479e81` reads the world pointer at `00628b74`. For each 0x50-byte row it walks the nested 0x14-byte records backwards, releases the pointer at +8 then +4, releases the array header, and clears the row's list pointer. It reloads the second pointer after the first release and the world row count after each reset. The row callback receives ECX and four callee-popped arguments, including the unchanged word at +0x34.

[Native attempt 005](native-config.json) compared complete rows and release traces in 25 cases per optimization level. The fixture covers empty and populated lists, callback mutations, and raw argument bits including signed zero, infinity and NaNs. Four mutations were detected. The fixture bounds the number and extent of allocated records; live world allocation remains open.
