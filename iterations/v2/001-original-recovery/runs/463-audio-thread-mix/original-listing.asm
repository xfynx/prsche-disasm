; new-original-body
0058f8e0  e80beaffff  call 0x58e2f0
0058f8e5  e806000000  call 0x58f8f0
0058f8ea  e911eaffff  jmp 0x58e300
; new-original-body
0058f8f0  a160d76a00  mov eax, dword ptr [0x6ad760]
0058f8f5  83ec2c  sub esp, 0x2c
0058f8f8  56  push esi
0058f8f9  33f6  xor esi, esi
0058f8fb  3bc6  cmp eax, esi
0058f8fd  0f84ac020000  je 0x58fbaf
0058f903  a168d76a00  mov eax, dword ptr [0x6ad768]
0058f908  8d542410  lea edx, [esp + 0x10]
0058f90c  52  push edx
0058f90d  50  push eax
0058f90e  8b08  mov ecx, dword ptr [eax]
0058f910  ff5124  call dword ptr [ecx + 0x24]
0058f913  8a442410  mov al, byte ptr [esp + 0x10]
0058f917  a802  test al, 2
0058f919  0f857f020000  jne 0x58fb9e
0058f91f  833df4ef6a0064  cmp dword ptr [0x6aeff4], 0x64
0058f926  0f8f72020000  jg 0x58fb9e
0058f92c  a801  test al, 1
0058f92e  a168d76a00  mov eax, dword ptr [0x6ad768]
0058f933  0f8450020000  je 0x58fb89
0058f939  8b08  mov ecx, dword ptr [eax]
0058f93b  6884d76a00  push 0x6ad784
0058f940  56  push esi
0058f941  50  push eax
0058f942  ff5110  call dword ptr [ecx + 0x10]
0058f945  85c0  test eax, eax
0058f947  0f8562020000  jne 0x58fbaf
0058f94d  a184d76a00  mov eax, dword ptr [0x6ad784]
0058f952  8a0de4486b00  mov cl, byte ptr [0x6b48e4]
0058f958  53  push ebx
0058f959  8b1ddc486b00  mov ebx, dword ptr [0x6b48dc]
0058f95f  d1f8  sar eax, 1
0058f961  55  push ebp
0058f962  57  push edi
0058f963  84c9  test cl, cl
0058f965  750b  jne 0x58f972
0058f967  8bcb  mov ecx, ebx
0058f969  99  cdq
0058f96a  81e1ff000000  and ecx, 0xff
0058f970  f7f9  idiv ecx
0058f972  8b0d88d76a00  mov ecx, dword ptr [0x6ad788]
0058f978  8b3db4d76a00  mov edi, dword ptr [0x6ad7b4]
0058f97e  25f0ffff00  and eax, 0xfffff0
0058f983  3bc1  cmp eax, ecx
0058f985  a384d76a00  mov dword ptr [0x6ad784], eax
0058f98a  7c06  jl 0x58f992
0058f98c  8bd0  mov edx, eax
0058f98e  2bd1  sub edx, ecx
0058f990  eb06  jmp 0x58f998
0058f992  8bd7  mov edx, edi
0058f994  2bd1  sub edx, ecx
0058f996  03d0  add edx, eax
0058f998  8b2d80d76a00  mov ebp, dword ptr [0x6ad780]
0058f99e  03ea  add ebp, edx
0058f9a0  3bc1  cmp eax, ecx
0058f9a2  892d80d76a00  mov dword ptr [0x6ad780], ebp
0058f9a8  7508  jne 0x58f9b2
0058f9aa  ff05f4ef6a00  inc dword ptr [0x6aeff4]
0058f9b0  eb06  jmp 0x58f9b8
0058f9b2  8935f4ef6a00  mov dword ptr [0x6aeff4], esi
0058f9b8  8b158cd76a00  mov edx, dword ptr [0x6ad78c]
0058f9be  8b0d90d76a00  mov ecx, dword ptr [0x6ad790]
0058f9c4  8d2c01  lea ebp, [ecx + eax]
0058f9c7  81e5f0ff0f00  and ebp, 0xffff0
0058f9cd  3bef  cmp ebp, edi
0058f9cf  896c2414  mov dword ptr [esp + 0x14], ebp
0058f9d3  7c06  jl 0x58f9db
0058f9d5  2bef  sub ebp, edi
0058f9d7  896c2414  mov dword ptr [esp + 0x14], ebp
0058f9db  3bea  cmp ebp, edx
0058f9dd  7c0c  jl 0x58f9eb
0058f9df  8bcd  mov ecx, ebp
0058f9e1  2bca  sub ecx, edx
0058f9e3  33f6  xor esi, esi
0058f9e5  894c2424  mov dword ptr [esp + 0x24], ecx
0058f9e9  eb0a  jmp 0x58f9f5
0058f9eb  8bcf  mov ecx, edi
0058f9ed  8bf5  mov esi, ebp
0058f9ef  2bca  sub ecx, edx
0058f9f1  894c2424  mov dword ptr [esp + 0x24], ecx
0058f9f5  89742428  mov dword ptr [esp + 0x28], esi
0058f9f9  03f1  add esi, ecx
0058f9fb  8d4ff0  lea ecx, [edi - 0x10]
0058f9fe  3bf1  cmp esi, ecx
0058fa00  7c09  jl 0x58fa0b
0058fa02  830590d76a0010  add dword ptr [0x6ad790], 0x10
0058fa09  ebb3  jmp 0x58f9be
0058fa0b  8a0d78d76a00  mov cl, byte ptr [0x6ad778]
0058fa11  84c9  test cl, cl
0058fa13  7516  jne 0x58fa2b
0058fa15  e8b6020000  call 0x58fcd0
0058fa1a  8b158cd76a00  mov edx, dword ptr [0x6ad78c]
0058fa20  a184d76a00  mov eax, dword ptr [0x6ad784]
0058fa25  8b1ddc486b00  mov ebx, dword ptr [0x6b48dc]
0058fa2b  a388d76a00  mov dword ptr [0x6ad788], eax
0058fa30  8d442424  lea eax, [esp + 0x24]
0058fa34  89442410  mov dword ptr [esp + 0x10], eax
0058fa38  c744241802000000  mov dword ptr [esp + 0x18], 2
0058fa40  8b4c2410  mov ecx, dword ptr [esp + 0x10]
0058fa44  8b39  mov edi, dword ptr [ecx]
0058fa46  85ff  test edi, edi
0058fa48  0f8405010000  je 0x58fb53
0058fa4e  8b0d7cd76a00  mov ecx, dword ptr [0x6ad77c]
0058fa54  a0e4486b00  mov al, byte ptr [0x6b48e4]
0058fa59  03cf  add ecx, edi
0058fa5b  84c0  test al, al
0058fa5d  890d7cd76a00  mov dword ptr [0x6ad77c], ecx
0058fa63  7447  je 0x58faac
0058fa65  33f6  xor esi, esi
0058fa67  84db  test bl, bl
0058fa69  766c  jbe 0x58fad7
0058fa6b  8d2c3f  lea ebp, [edi + edi]
0058fa6e  eb06  jmp 0x58fa76
0058fa70  8b158cd76a00  mov edx, dword ptr [0x6ad78c]
0058fa76  8b04b568d76a00  mov eax, dword ptr [esi*4 + 0x6ad768]
0058fa7d  6a00  push 0
0058fa7f  6a00  push 0
0058fa81  8d5c2428  lea ebx, [esp + 0x28]
0058fa85  8b08  mov ecx, dword ptr [eax]
0058fa87  6a00  push 0
0058fa89  53  push ebx
0058fa8a  8d5cb43c  lea ebx, [esp + esi*4 + 0x3c]
0058fa8e  53  push ebx
0058fa8f  03d2  add edx, edx
0058fa91  55  push ebp
0058fa92  52  push edx
0058fa93  50  push eax
0058fa94  ff512c  call dword ptr [ecx + 0x2c]
0058fa97  a1dc486b00  mov eax, dword ptr [0x6b48dc]
0058fa9c  46  inc esi
0058fa9d  25ff000000  and eax, 0xff
0058faa2  3bf0  cmp esi, eax
0058faa4  7cca  jl 0x58fa70
0058faa6  8b6c2414  mov ebp, dword ptr [esp + 0x14]
0058faaa  eb2b  jmp 0x58fad7
0058faac  8bcb  mov ecx, ebx
0058faae  6a00  push 0
0058fab0  6a00  push 0
0058fab2  8d5c2428  lea ebx, [esp + 0x28]
0058fab6  6a00  push 0
0058fab8  53  push ebx
0058fab9  a168d76a00  mov eax, dword ptr [0x6ad768]
0058fabe  8d5c243c  lea ebx, [esp + 0x3c]
0058fac2  53  push ebx
0058fac3  81e1ff000000  and ecx, 0xff
0058fac9  8b30  mov esi, dword ptr [eax]
0058facb  8bdf  mov ebx, edi
0058facd  d3e3  shl ebx, cl
0058facf  d3e2  shl edx, cl
0058fad1  53  push ebx
0058fad2  52  push edx
0058fad3  50  push eax
0058fad4  ff562c  call dword ptr [esi + 0x2c]
0058fad7  8d4c242c  lea ecx, [esp + 0x2c]
0058fadb  57  push edi
0058fadc  51  push ecx
0058fadd  e8de000000  call 0x58fbc0
0058fae2  a0e4486b00  mov al, byte ptr [0x6b48e4]
0058fae7  83c408  add esp, 8
0058faea  84c0  test al, al
0058faec  743a  je 0x58fb28
0058faee  8b1ddc486b00  mov ebx, dword ptr [0x6b48dc]
0058faf4  33f6  xor esi, esi
0058faf6  84db  test bl, bl
0058faf8  7651  jbe 0x58fb4b
0058fafa  03ff  add edi, edi
0058fafc  8b04b568d76a00  mov eax, dword ptr [esi*4 + 0x6ad768]
0058fb03  8b4cb42c  mov ecx, dword ptr [esp + esi*4 + 0x2c]
0058fb07  6a00  push 0
0058fb09  6a00  push 0
0058fb0b  8b10  mov edx, dword ptr [eax]
0058fb0d  57  push edi
0058fb0e  51  push ecx
0058fb0f  50  push eax
0058fb10  ff524c  call dword ptr [edx + 0x4c]
0058fb13  8b1ddc486b00  mov ebx, dword ptr [0x6b48dc]
0058fb19  46  inc esi
0058fb1a  8bd3  mov edx, ebx
0058fb1c  81e2ff000000  and edx, 0xff
0058fb22  3bf2  cmp esi, edx
0058fb24  7cd6  jl 0x58fafc
0058fb26  eb23  jmp 0x58fb4b
0058fb28  8a0ddc486b00  mov cl, byte ptr [0x6b48dc]
0058fb2e  a168d76a00  mov eax, dword ptr [0x6ad768]
0058fb33  d3e7  shl edi, cl
0058fb35  8b4c242c  mov ecx, dword ptr [esp + 0x2c]
0058fb39  8b10  mov edx, dword ptr [eax]
0058fb3b  6a00  push 0
0058fb3d  6a00  push 0
0058fb3f  57  push edi
0058fb40  51  push ecx
0058fb41  50  push eax
0058fb42  ff524c  call dword ptr [edx + 0x4c]
0058fb45  8b1ddc486b00  mov ebx, dword ptr [0x6b48dc]
0058fb4b  33d2  xor edx, edx
0058fb4d  89158cd76a00  mov dword ptr [0x6ad78c], edx
0058fb53  8b4c2410  mov ecx, dword ptr [esp + 0x10]
0058fb57  8b442418  mov eax, dword ptr [esp + 0x18]
0058fb5b  83c104  add ecx, 4
0058fb5e  48  dec eax
0058fb5f  894c2410  mov dword ptr [esp + 0x10], ecx
0058fb63  89442418  mov dword ptr [esp + 0x18], eax
0058fb67  0f85d3feffff  jne 0x58fa40
0058fb6d  a084486b00  mov al, byte ptr [0x6b4884]
0058fb72  892d8cd76a00  mov dword ptr [0x6ad78c], ebp
0058fb78  5f  pop edi
0058fb79  5d  pop ebp
0058fb7a  84c0  test al, al
0058fb7c  5b  pop ebx
0058fb7d  7430  je 0x58fbaf
0058fb7f  e83cfbffff  call 0x58f6c0
0058fb84  5e  pop esi
0058fb85  83c42c  add esp, 0x2c
0058fb88  c3  ret
0058fb89  8b10  mov edx, dword ptr [eax]
0058fb8b  6a01  push 1
0058fb8d  56  push esi
0058fb8e  56  push esi
0058fb8f  50  push eax
0058fb90  ff5230  call dword ptr [edx + 0x30]
0058fb93  8935f4ef6a00  mov dword ptr [0x6aeff4], esi
0058fb99  5e  pop esi
0058fb9a  83c42c  add esp, 0x2c
0058fb9d  c3  ret
0058fb9e  a168d76a00  mov eax, dword ptr [0x6ad768]
0058fba3  50  push eax
0058fba4  8b08  mov ecx, dword ptr [eax]
0058fba6  ff5150  call dword ptr [ecx + 0x50]
0058fba9  8935f4ef6a00  mov dword ptr [0x6aeff4], esi
0058fbaf  5e  pop esi
0058fbb0  83c42c  add esp, 0x2c
0058fbb3  c3  ret
; accepted-original-reused-composition
0058e2f0  6800186b00  push 0x6b1800
0058e2f5  ff1578205b00  call dword ptr [0x5b2078]
0058e2fb  c3  ret
; accepted-original-reused-composition
0058e300  6800186b00  push 0x6b1800
0058e305  ff156c205b00  call dword ptr [0x5b206c]
0058e30b  c3  ret
