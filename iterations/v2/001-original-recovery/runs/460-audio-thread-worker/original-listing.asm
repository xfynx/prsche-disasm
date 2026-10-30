0058f880  a081486b00  mov al, byte ptr [0x6b4881]
0058f885  84c0  test al, al
0058f887  7442  je 0x58f8cb
0058f889  56  push esi
0058f88a  8b350c225b00  mov esi, dword ptr [0x5b220c]
0058f890  a13c4a6b00  mov eax, dword ptr [0x6b4a3c]
0058f895  85c0  test eax, eax
0058f897  7402  je 0x58f89b
0058f899  ffd0  call eax
0058f89b  e840000000  call 0x58f8e0
0058f8a0  a1404a6b00  mov eax, dword ptr [0x6b4a40]
0058f8a5  85c0  test eax, eax
0058f8a7  7402  je 0x58f8ab
0058f8a9  ffd0  call eax
0058f8ab  33c0  xor eax, eax
0058f8ad  a0e1486b00  mov al, byte ptr [0x6b48e1]
0058f8b2  50  push eax
0058f8b3  ffd6  call esi
0058f8b5  a081486b00  mov al, byte ptr [0x6b4881]
0058f8ba  84c0  test al, al
0058f8bc  75d2  jne 0x58f890
0058f8be  c60580486b0000  mov byte ptr [0x6b4880], 0
0058f8c5  33c0  xor eax, eax
0058f8c7  5e  pop esi
0058f8c8  c20400  ret 4
0058f8cb  c60580486b0000  mov byte ptr [0x6b4880], 0
0058f8d2  33c0  xor eax, eax
0058f8d4  c20400  ret 4
