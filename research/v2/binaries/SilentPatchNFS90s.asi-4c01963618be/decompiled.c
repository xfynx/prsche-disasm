/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 4c01963618be1e78375f16d8f71aebd90438b49921c97c938edef364534566cb */

/* VA 10001010 */

void __fastcall FUN_10001010(undefined4 *param_1)

{
  BOOL BVar1;

  BVar1 = InitOnceComplete((LPINIT_ONCE)*param_1,param_1[1],(LPVOID)0x0);
  if (BVar1 != 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 100011c0 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InitializeASI(void)

{
  byte bVar1;
  code *pcVar2;
  HMODULE pHVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  bool bVar11;
  DWORD local_c;
  uint local_8;

                    /* 0x11c0  2  InitializeASI */
  LOCK();
  iVar4 = DAT_1001a3c0;
  if (DAT_1001a3c0 == 0) {
    DAT_1001a3c0 = 1;
    iVar4 = 0;
  }
  UNLOCK();
  if (iVar4 != 0) {
    return;
  }
  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  pHVar3 = GetModuleHandleW((LPCWSTR)0x0);
  piVar9 = (int *)((int)&pHVar3->unused + *(int *)((int)&pHVar3[0x20].unused + pHVar3[0xf].unused));
  iVar4 = piVar9[3];
  pcVar2 = GetCommandLineA_exref;
  do {
    GetCommandLineA_exref = pcVar2;
    if (iVar4 == 0) {
      DAT_1001a3fc = *(undefined4 *)pcVar2;
      DAT_1001a400 = pcVar2[4];
      DAT_1001a3f8 = pcVar2;
      VirtualProtect(pcVar2,5,0x40,&local_c);
      *pcVar2 = (code)0xe9;
      *(int *)(pcVar2 + 1) = (int)&UNK_100011ec - (int)(pcVar2 + 1);
      VirtualProtect(pcVar2,5,local_c,&local_c);
      return;
    }
    iVar4 = FUN_10007cbf((byte *)((int)&pHVar3->unused + piVar9[3]),(byte *)"KERNEL32.DLL");
    if (iVar4 == 0) {
      iVar4 = *piVar9;
      if (iVar4 == 0) {
        iVar4 = 0;
        piVar10 = (int *)((int)&pHVar3->unused + piVar9[4]);
        pcVar2 = (code *)*piVar10;
        while (pcVar2 != (code *)0x0) {
          if (pcVar2 == GetCommandLineA_exref) {
            piVar10 = piVar10 + iVar4;
            goto LAB_10001171;
          }
          iVar8 = iVar4 + 1;
          iVar4 = iVar4 + 1;
          pcVar2 = (code *)piVar10[iVar8];
        }
      }
      else {
        local_c = (int)&pHVar3->unused + iVar4;
        iVar8 = 0;
        iVar4 = *(int *)((int)&pHVar3->unused + iVar4);
        while (iVar4 != 0) {
          pcVar5 = "GetCommandLineA";
          pbVar7 = (byte *)((int)&pHVar3->unused + iVar4 + 2);
          do {
            bVar1 = *pbVar7;
            bVar11 = bVar1 < (byte)*pcVar5;
            if (bVar1 != *pcVar5) {
LAB_100010c0:
              uVar6 = -(uint)bVar11 | 1;
              goto LAB_100010c5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar7[1];
            bVar11 = bVar1 < (byte)pcVar5[1];
            if (bVar1 != pcVar5[1]) goto LAB_100010c0;
            pbVar7 = pbVar7 + 2;
            pcVar5 = pcVar5 + 2;
          } while (bVar1 != 0);
          uVar6 = 0;
LAB_100010c5:
          if (uVar6 == 0) {
            piVar10 = (int *)((int)&pHVar3[iVar8].unused + piVar9[4]);
LAB_10001171:
            VirtualProtect(piVar10,4,4,&local_c);
            DAT_1001a3f8 = (code *)*piVar10;
            *piVar10 = (int)FUN_10001270;
            VirtualProtect(piVar10,4,local_c,&local_c);
            return;
          }
          iVar8 = iVar8 + 1;
          iVar4 = *(int *)(local_c + iVar8 * 4);
        }
      }
    }
    iVar4 = piVar9[8];
    piVar9 = piVar9 + 5;
    pcVar2 = GetCommandLineA_exref;
  } while( true );
}



/* VA 100011e0 */

undefined4 GetBuildNumber(void)

{
                    /* 0x11e0  1  GetBuildNumber */
  return 0x100;
}



/* VA 100011f0 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_100011f0(void)

{
  uint *lpAddress;
  undefined1 auStack_1c [4];
  uint local_18;
  undefined1 local_14;
  DWORD local_10;
  uint local_c;

  lpAddress = DAT_1001a3f8;
  local_c = DAT_10019008 ^ (uint)auStack_1c;
  local_18 = DAT_1001a3fc;
  local_14 = DAT_1001a400;
  VirtualProtect(DAT_1001a3f8,5,0x40,&local_10);
  FUN_10007600(lpAddress,&local_18,5);
  VirtualProtect(lpAddress,5,local_10,&local_10);
  FUN_10001270();
  return;
}



/* VA 10001270 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_10001270(void)

{
  uint uVar1;
  BOOL BVar2;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10010aed;
  local_10 = ExceptionList;
  uVar1 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  BVar2 = InitOnceBeginInitialize((LPINIT_ONCE)&DAT_1001a3c4,0,&local_18,(LPVOID *)0x0);
  if (BVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  if (local_18 != 0) {
    local_8 = 0;
    FUN_10002960();
    local_8 = 0xffffffff;
    BVar2 = InitOnceComplete((LPINIT_ONCE)&DAT_1001a3c4,0,(LPVOID)0x0);
    if (BVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      _abort();
    }
  }
  (*DAT_1001a3f8)(uVar1);
  ExceptionList = local_10;
  return;
}



/* VA 10001320 */

undefined4 * __thiscall FUN_10001320(void *this,int param_1)

{
  int *piVar1;

  piVar1 = (int *)((int)this + 4);
  *(undefined ***)this = std::exception::vftable;
  piVar1[0] = 0;
  piVar1[1] = 0;
  ___std_exception_copy((int *)(param_1 + 4),piVar1);
  return this;
}



/* VA 10001350 */

char * __fastcall FUN_10001350(int param_1)

{
  char *pcVar1;

  pcVar1 = "Unknown exception";
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    pcVar1 = *(char **)(param_1 + 4);
  }
  return pcVar1;
}



/* VA 10001360 */

undefined4 * __thiscall FUN_10001360(void *this,byte param_1)

{
  *(undefined ***)this = std::exception::vftable;
  ___std_exception_destroy((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    FUN_10004f47(this);
  }
  return this;
}



/* VA 100013b0 */

undefined4 * __fastcall FUN_100013b0(undefined4 *param_1)

{
  *(undefined8 *)(param_1 + 1) = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}



/* VA 100013d0 */

void FUN_100013d0(void)

{
  int local_10 [3];

  FUN_100013b0(local_10);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_100179e8);
}



/* VA 100013f0 */

undefined4 * __thiscall FUN_100013f0(void *this,int param_1)

{
  int *piVar1;

  piVar1 = (int *)((int)this + 4);
  *(undefined ***)this = std::exception::vftable;
  piVar1[0] = 0;
  piVar1[1] = 0;
  ___std_exception_copy((int *)(param_1 + 4),piVar1);
  *(undefined ***)this = std::bad_array_new_length::vftable;
  return this;
}



/* VA 10001430 */

undefined4 * __thiscall FUN_10001430(void *this,int param_1)

{
  int *piVar1;

  piVar1 = (int *)((int)this + 4);
  *(undefined ***)this = std::exception::vftable;
  piVar1[0] = 0;
  piVar1[1] = 0;
  ___std_exception_copy((int *)(param_1 + 4),piVar1);
  *(undefined ***)this = std::bad_alloc::vftable;
  return this;
}



/* VA 10001470 */

void FUN_10001470(void)

{
  code *pcVar1;

  FUN_10004ad9("string too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* VA 10001480 */

void __fastcall FUN_10001480(int *param_1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;

  pvVar1 = (LPVOID)param_1[0xc];
  if (pvVar1 != (LPVOID)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (param_1[0xe] - (int)pvVar1 & 0xfffffffcU)) &&
       (pvVar2 = *(LPVOID *)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2))))
    goto LAB_10001553;
    FUN_10004f47(pvVar2);
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
  }
  if (0xf < (uint)param_1[0xb]) {
    pvVar1 = (LPVOID)param_1[6];
    pvVar2 = pvVar1;
    if ((0xfff < param_1[0xb] + 1U) &&
       (pvVar2 = *(LPVOID *)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2))))
    goto LAB_10001553;
    FUN_10004f47(pvVar2);
  }
  param_1[10] = 0;
  param_1[0xb] = 0xf;
  *(undefined1 *)(param_1 + 6) = 0;
  if (0xf < (uint)param_1[5]) {
    pvVar1 = (LPVOID)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < param_1[5] + 1U) &&
       (pvVar2 = *(LPVOID *)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2)))) {
LAB_10001553:
                    /* WARNING: Subroutine does not return */
      FUN_100080b4();
    }
    FUN_10004f47(pvVar2);
  }
  param_1[4] = 0;
  param_1[5] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}



/* VA 10001560 */

undefined4 * __fastcall
FUN_10001560(undefined4 *param_1,undefined4 param_2,char *param_3,int param_4)

{
  undefined4 *puVar1;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;

  puStack_18 = &LAB_10010b2d;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  puVar1 = param_1 + 6;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[5] = 0xf;
  *(undefined1 *)param_1 = 0;
  *puVar1 = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0xf;
  *(undefined1 *)puVar1 = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  param_1[0x10] = param_2;
  param_1[0x11] = 0;
  local_14 = 0;
  FUN_100043e0(param_1,puVar1,param_3,param_4);
  ExceptionList = local_1c;
  return param_1;
}



/* VA 10001630 */

void __fastcall thunk_FUN_10001480(int *param_1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;

  pvVar1 = (LPVOID)param_1[0xc];
  if (pvVar1 != (LPVOID)0x0) {
    pvVar2 = pvVar1;
    if ((0xfff < (param_1[0xe] - (int)pvVar1 & 0xfffffffcU)) &&
       (pvVar2 = *(LPVOID *)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2))))
    goto LAB_10001553;
    FUN_10004f47(pvVar2);
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
  }
  if (0xf < (uint)param_1[0xb]) {
    pvVar1 = (LPVOID)param_1[6];
    pvVar2 = pvVar1;
    if ((0xfff < param_1[0xb] + 1U) &&
       (pvVar2 = *(LPVOID *)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2))))
    goto LAB_10001553;
    FUN_10004f47(pvVar2);
  }
  param_1[10] = 0;
  param_1[0xb] = 0xf;
  *(undefined1 *)(param_1 + 6) = 0;
  if (0xf < (uint)param_1[5]) {
    pvVar1 = (LPVOID)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < param_1[5] + 1U) &&
       (pvVar2 = *(LPVOID *)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2)))) {
LAB_10001553:
                    /* WARNING: Subroutine does not return */
      FUN_100080b4();
    }
    FUN_10004f47(pvVar2);
  }
  param_1[4] = 0;
  param_1[5] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}



/* VA 10001640 */

undefined4 * __thiscall FUN_10001640(void *this,char *param_1,int param_2)

{
  undefined4 *puVar1;
  HMODULE pHVar2;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;

  local_14 = 0xffffffff;
  puStack_18 = &LAB_10010b5d;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  pHVar2 = GetModuleHandleW((LPCWSTR)0x0);
  puVar1 = (undefined4 *)((int)this + 0x18);
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined1 *)this = 0;
  *puVar1 = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0xf;
  *(undefined1 *)puVar1 = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined1 *)((int)this + 0x3c) = 0;
  *(HMODULE *)((int)this + 0x40) = pHVar2;
  *(undefined4 *)((int)this + 0x44) = 0;
  local_14 = 0;
  FUN_100043e0(this,puVar1,param_1,param_2);
  ExceptionList = local_1c;
  return this;
}



/* VA 10001720 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_10001720(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  DWORD local_c;
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  for (puVar1 = (undefined4 *)*param_1; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1)
  {
    VirtualProtect((LPVOID)puVar1[3],puVar1[2],puVar1[1],&local_c);
  }
  puVar1 = (undefined4 *)*param_1;
  *param_1 = 0;
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    FUN_10004f47(puVar1);
    puVar1 = puVar2;
  }
  return;
}



/* VA 10001790 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_10001790(void *this,int param_1,uint param_2)

{
  DWORD flNewProtect;
  undefined4 *puVar1;
  uint uVar2;
  _MEMORY_BASIC_INFORMATION local_34;
  DWORD local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10010b8d;
  local_10 = ExceptionList;
  local_14 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      VirtualQuery((LPCVOID)(param_1 + uVar2),&local_34,0x1c);
      if (((local_34.State == 0x1000) && ((local_34.Type & 0x1000000) != 0)) &&
         ((local_34.Protect & 0xcc) == 0)) {
        flNewProtect = 4;
        if ((local_34.Protect & 0x30) != 0) {
          flNewProtect = 0x40;
        }
        VirtualProtect(local_34.BaseAddress,local_34.RegionSize,flNewProtect,&local_18);
        local_8 = 0;
        puVar1 = operator_new(0x10);
        puVar1[1] = local_34.Protect;
        puVar1[2] = local_34.RegionSize;
        puVar1[3] = local_34.BaseAddress;
        *puVar1 = *(undefined4 *)this;
        *(undefined4 **)this = puVar1;
        local_8 = 0xffffffff;
      }
      uVar2 = uVar2 + local_34.RegionSize;
    } while (uVar2 < param_2);
  }
  ExceptionList = local_10;
  return;
}



/* VA 10001890 */

uint * __fastcall FUN_10001890(uint *param_1,uint *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;

  iVar2 = (int)param_2 - (int)param_1 >> 1;
  if (1 < iVar2) {
    uVar3 = *param_1 & 0xffff;
    if ((*param_1 & 0xffffffdf) - 0x3a0041 < 0x1a) {
      param_1 = param_1 + 1;
    }
    else if ((uVar3 == 0x5c) || (uVar3 == 0x2f)) {
      if (iVar2 < 4) {
        if (iVar2 < 3) goto joined_r0x1000195f;
      }
      else if ((((*(short *)((int)param_1 + 6) == 0x5c) || (*(short *)((int)param_1 + 6) == 0x2f))
               && ((iVar2 == 4 || (((short)param_1[2] != 0x5c && ((short)param_1[2] != 0x2f)))))) &&
              ((((sVar1 = *(short *)((int)param_1 + 2), sVar1 == 0x5c || (sVar1 == 0x2f)) &&
                (((short)param_1[1] == 0x3f || ((short)param_1[1] == 0x2e)))) ||
               ((sVar1 == 0x3f && ((short)param_1[1] == 0x3f)))))) {
        param_1 = (uint *)((int)param_1 + 6);
        goto joined_r0x1000195f;
      }
      if ((((*(short *)((int)param_1 + 2) == 0x5c) || (*(short *)((int)param_1 + 2) == 0x2f)) &&
          ((short)param_1[1] != 0x5c)) &&
         (((short)param_1[1] != 0x2f && (param_1 = (uint *)((int)param_1 + 6), param_1 != param_2)))
         ) {
        while ((short)*param_1 != 0x5c) {
          if (((short)*param_1 == 0x2f) ||
             (param_1 = (uint *)((int)param_1 + 2), param_1 == param_2)) break;
        }
      }
    }
  }
joined_r0x1000195f:
  for (; (param_1 != param_2 && (((short)*param_1 == 0x5c || ((short)*param_1 == 0x2f))));
      param_1 = (uint *)((int)param_1 + 2)) {
  }
  return param_1;
}



/* VA 10001980 */

uint * __thiscall FUN_10001980(void *this,uint *param_1)

{
  uint *puVar1;
  int iVar2;
  code *pcVar3;
  uint *puVar4;
  uint *puVar5;
  void *pvVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  puStack_c = &LAB_10010bc0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
    local_14 = *(uint **)this;
  }
  puVar7 = (uint *)((int)local_14 + *(int *)((int)this + 0x10) * 2);
  puVar4 = FUN_10001890(local_14,puVar7);
  for (puVar9 = puVar7;
      ((puVar4 != puVar9 && (*(short *)((int)puVar9 + -2) != 0x5c)) &&
      (*(short *)((int)puVar9 + -2) != 0x2f)); puVar9 = (uint *)((int)puVar9 + -2)) {
  }
  puVar4 = (uint *)FUN_10004b20(puVar9,puVar7,0x3a);
  puVar7 = puVar4;
  if ((puVar9 != puVar4) && (puVar1 = (uint *)((int)puVar4 + -2), puVar9 != puVar1)) {
    puVar5 = puVar4 + -1;
    if (*(short *)puVar1 == 0x2e) {
      if ((puVar9 != puVar5) || ((short)*puVar5 != 0x2e)) {
        puVar7 = puVar1;
      }
    }
    else {
      for (; (puVar7 = puVar4, puVar9 != puVar5 && (puVar7 = puVar5, (short)*puVar5 != 0x2e));
          puVar5 = (uint *)((int)puVar5 + -2)) {
      }
    }
  }
  uVar8 = (int)puVar7 - (int)local_14 >> 1;
  if (*(uint *)((int)this + 0x10) < uVar8) {
    FUN_10003eb0();
    pcVar3 = (code *)swi(3);
    puVar7 = (uint *)(*pcVar3)();
    return puVar7;
  }
  pvVar6 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
    pvVar6 = *(void **)this;
  }
  *(uint *)((int)this + 0x10) = uVar8;
  *(undefined2 *)((int)pvVar6 + uVar8 * 2) = 0;
  local_8 = 0xffffffff;
  if (param_1[4] != 0) {
    puVar7 = param_1;
    if (7 < param_1[5]) {
      puVar7 = (uint *)*param_1;
    }
    if ((short)*puVar7 != 0x2e) {
      uVar8 = *(uint *)((int)this + 0x10);
      if (uVar8 < *(uint *)((int)this + 0x14)) {
        *(uint *)((int)this + 0x10) = uVar8 + 1;
        pvVar6 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar6 = *(void **)this;
        }
        *(undefined4 *)((int)pvVar6 + uVar8 * 2) = 0x2e;
      }
      else {
        local_14 = (uint *)((uint)local_14 & 0xffffff00);
        FUN_10003f50(this,uVar8,local_14,0x2e);
      }
    }
  }
  uVar8 = param_1[4];
  if (7 < param_1[5]) {
    param_1 = (uint *)*param_1;
  }
  iVar2 = *(int *)((int)this + 0x10);
  if ((uint)(*(int *)((int)this + 0x14) - iVar2) < uVar8) {
    local_14 = (uint *)((uint)local_14 & 0xffffff00);
    FUN_100040b0(this,uVar8,local_14,param_1,uVar8);
  }
  else {
    *(uint *)((int)this + 0x10) = uVar8 + iVar2;
    pvVar6 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar6 = *(void **)this;
    }
    FUN_10007600((uint *)((int)pvVar6 + iVar2 * 2),param_1,uVar8 * 2);
    *(undefined2 *)((int)pvVar6 + (uVar8 + iVar2) * 2) = 0;
  }
  ExceptionList = local_10;
  return this;
}



/* VA 10001b30 */

uint * __thiscall FUN_10001b30(void *this,uint *param_1)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;

  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  uVar1 = *(uint *)((int)this + 0x10);
  if (7 < *(uint *)((int)this + 0x14)) {
    this = *(void **)this;
  }
  if (uVar1 < 0x7fffffff) {
    param_1[5] = 7;
    if (uVar1 < 8) {
      param_1[4] = uVar1;
      FUN_10007600(param_1,this,0x10);
      return param_1;
    }
    uVar5 = uVar1 | 7;
    if (uVar5 < 0x7fffffff) {
      if (uVar5 < 10) {
        uVar5 = 10;
      }
      if (uVar5 + 1 < 0x80000000) {
        uVar2 = (uVar5 + 1) * 2;
        if (uVar2 < 0x1000) {
          if (uVar2 == 0) {
            puVar4 = (uint *)0x0;
          }
          else {
            puVar4 = operator_new(uVar2);
          }
          goto LAB_10001c01;
        }
        goto LAB_10001bcf;
      }
    }
    else {
      uVar5 = 0x7ffffffe;
      uVar2 = 0xfffffffe;
LAB_10001bcf:
      if (uVar2 < uVar2 + 0x23) {
        pvVar3 = operator_new(uVar2 + 0x23);
        if (pvVar3 != (void *)0x0) {
          puVar4 = (uint *)((int)pvVar3 + 0x23U & 0xffffffe0);
          puVar4[-1] = (uint)pvVar3;
LAB_10001c01:
          *param_1 = (uint)puVar4;
          param_1[4] = uVar1;
          param_1[5] = uVar5;
          FUN_10007600(puVar4,this,uVar1 * 2 + 2);
          return param_1;
        }
        goto LAB_10001c32;
      }
    }
    FUN_100013d0();
  }
  FUN_10001470();
LAB_10001c32:
                    /* WARNING: Subroutine does not return */
  FUN_100080b4();
}



/* VA 10001c40 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void * __thiscall FUN_10001c40(void *this,void *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined1 auStack_1c [4];
  uint *local_18;
  uint local_c;

  local_c = DAT_10019008 ^ (uint)auStack_1c;
  puVar5 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
    puVar5 = *(uint **)this;
  }
  puVar4 = (uint *)((int)puVar5 + *(int *)((int)this + 0x10) * 2);
  local_18 = puVar4;
  puVar2 = FUN_10001890(puVar5,puVar4);
  for (puVar5 = puVar4;
      ((puVar2 != puVar5 && (*(short *)((int)puVar5 + -2) != 0x5c)) &&
      (*(short *)((int)puVar5 + -2) != 0x2f)); puVar5 = (uint *)((int)puVar5 + -2)) {
  }
  puVar2 = (uint *)FUN_10004b20(puVar5,puVar4,0x3a);
  puVar4 = puVar2;
  if ((puVar5 != puVar2) && (puVar1 = (uint *)((int)puVar2 + -2), puVar5 != puVar1)) {
    puVar3 = puVar2 + -1;
    if (*(short *)puVar1 == 0x2e) {
      if ((puVar5 != puVar3) || ((short)*puVar3 != 0x2e)) {
        puVar4 = puVar1;
      }
    }
    else {
      for (; (puVar4 = puVar2, puVar5 != puVar3 && (puVar4 = puVar3, (short)*puVar3 != 0x2e));
          puVar3 = (uint *)((int)puVar3 + -2)) {
      }
    }
  }
  local_18 = (uint *)((uint)local_18 & 0xffffff00);
  FUN_100042d0(param_1,local_18,puVar5,(int)puVar4 - (int)puVar5 >> 1);
  return param_1;
}



/* VA 10001d10 */

void __fastcall FUN_10001d10(int *param_1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;

  if (7 < (uint)param_1[5]) {
    pvVar1 = (LPVOID)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < param_1[5] * 2 + 2U) &&
       (pvVar2 = *(LPVOID *)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      FUN_100080b4();
    }
    FUN_10004f47(pvVar2);
  }
  param_1[4] = 0;
  param_1[5] = 7;
  *(undefined2 *)param_1 = 0;
  return;
}



/* VA 10001d70 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_10001d70(void)

{
  undefined1 uVar1;
  HMODULE hModule;
  void *this;
  uint *this_00;
  UINT UVar2;
  LPCWSTR ***ppppWVar3;
  LPCWSTR ***ppppWVar4;
  LPVOID pvVar5;
  bool bVar6;
  WCHAR *lpFilename;
  DWORD nSize;
  LPVOID local_298 [5];
  uint local_284;
  LPVOID local_280 [4];
  undefined4 local_270;
  uint local_26c;
  uint local_268;
  LPVOID local_264 [5];
  uint local_250;
  LPCWSTR **local_24c [4];
  undefined4 local_23c;
  uint local_238;
  LPCWSTR **local_234 [4];
  undefined4 local_224;
  uint local_220;
  WCHAR local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10010c11;
  local_10 = ExceptionList;
  local_14 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  nSize = 0x104;
  lpFilename = local_21c;
  hModule = GetModuleHandleW((LPCWSTR)0x0);
  GetModuleFileNameW(hModule,lpFilename,nSize);
  local_268 = local_268 & 0xffffff00;
  FUN_10004260(local_264,(uint *)local_21c,local_268);
  local_8 = 0;
  this = FUN_10001c40(local_264,local_280);
  local_8._0_1_ = 1;
  FUN_10001b30(this,(uint *)local_24c);
  local_8._0_1_ = 3;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 3;
  if (7 < local_26c) {
    pvVar5 = local_280[0];
    if (0xfff < local_26c * 2 + 2) {
      pvVar5 = *(LPVOID *)((int)local_280[0] + -4);
      if (0x1f < (uint)((int)local_280[0] + (-4 - (int)pvVar5))) {
        local_8._0_1_ = uVar1;
                    /* WARNING: Subroutine does not return */
        FUN_100080b4();
      }
    }
    FUN_10004f47(pvVar5);
  }
  local_270 = 0;
  local_268 = local_268 & 0xffffff00;
  local_26c = 7;
  local_280[0] = (LPVOID)((uint)local_280[0] & 0xffff0000);
  FUN_100042a0(local_298,local_268);
  local_8 = CONCAT31(local_8._1_3_,4);
  this_00 = FUN_10001980(local_264,(uint *)local_298);
  FUN_10001b30(this_00,(uint *)local_234);
  if (7 < local_284) {
    pvVar5 = local_298[0];
    if (0xfff < local_284 * 2 + 2) {
      pvVar5 = *(LPVOID *)((int)local_298[0] + -4);
      if (0x1f < (uint)((int)local_298[0] + (-4 - (int)pvVar5))) goto LAB_10002079;
    }
    FUN_10004f47(pvVar5);
  }
  ppppWVar4 = local_234;
  if (7 < local_220) {
    ppppWVar4 = (LPCWSTR ***)local_234[0];
  }
  ppppWVar3 = local_24c;
  if (7 < local_238) {
    ppppWVar3 = (LPCWSTR ***)local_24c[0];
  }
  UVar2 = GetPrivateProfileIntW((LPCWSTR)ppppWVar3,L"SingleProcAffinity",-1,(LPCWSTR)ppppWVar4);
  if ((UVar2 == 0xffffffff) || (UVar2 == 0)) {
    bVar6 = false;
  }
  else {
    ppppWVar4 = local_234;
    if (7 < local_220) {
      ppppWVar4 = (LPCWSTR ***)local_234[0];
    }
    ppppWVar3 = local_24c;
    if (7 < local_238) {
      ppppWVar3 = (LPCWSTR ***)local_24c[0];
    }
    UVar2 = GetPrivateProfileIntW((LPCWSTR)ppppWVar3,L"SilentPatchAffinity",-1,(LPCWSTR)ppppWVar4);
    bVar6 = UVar2 != 0;
  }
  if (7 < local_220) {
    ppppWVar4 = (LPCWSTR ***)local_234[0];
    if (0xfff < local_220 * 2 + 2) {
      ppppWVar4 = (LPCWSTR ***)local_234[0][-1];
      if (0x1f < (uint)((int)local_234[0] + (-4 - (int)ppppWVar4))) goto LAB_10002079;
    }
    FUN_10004f47(ppppWVar4);
  }
  local_224 = 0;
  local_220 = 7;
  local_234[0] = (LPCWSTR **)((uint)local_234[0] & 0xffff0000);
  if (7 < local_238) {
    ppppWVar4 = (LPCWSTR ***)local_24c[0];
    if (0xfff < local_238 * 2 + 2) {
      ppppWVar4 = (LPCWSTR ***)local_24c[0][-1];
      if (0x1f < (uint)((int)local_24c[0] + (-4 - (int)ppppWVar4))) goto LAB_10002079;
    }
    FUN_10004f47(ppppWVar4);
  }
  local_23c = 0;
  local_238 = 7;
  local_24c[0] = (LPCWSTR **)((uint)local_24c[0] & 0xffff0000);
  if (7 < local_250) {
    pvVar5 = local_264[0];
    if (0xfff < local_250 * 2 + 2) {
      pvVar5 = *(LPVOID *)((int)local_264[0] + -4);
      if (0x1f < (uint)((int)local_264[0] + (-4 - (int)pvVar5))) {
LAB_10002079:
                    /* WARNING: Subroutine does not return */
        FUN_100080b4();
      }
    }
    FUN_10004f47(pvVar5);
  }
  ExceptionList = local_10;
  return bVar6;
}



/* VA 10002090 */

HANDLE FUN_10002090(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   uint param_5,undefined4 param_6)

{
  HANDLE hThread;

  hThread = (HANDLE)(*DAT_1001a3d0)(param_1,param_2,param_3,param_4,param_5 | 4,param_6);
  if ((hThread != (HANDLE)0x0) && (SetThreadAffinityMask(hThread,DAT_1001a3bc), (param_5 & 4) == 0))
  {
    ResumeThread(hThread);
  }
  return hThread;
}



/* VA 100020e0 */

void FUN_100020e0(void)

{
  DWORD_PTR dwThreadAffinityMask;
  HANDLE hThread;

  dwThreadAffinityMask = DAT_1001a3bc;
  hThread = GetCurrentThread();
  SetThreadAffinityMask(hThread,dwThreadAffinityMask);
  (*DAT_1001a3c8)();
  return;
}



/* VA 10002110 */

void FUN_10002110(void)

{
  DWORD_PTR dwThreadAffinityMask;
  HANDLE hThread;

  dwThreadAffinityMask = DAT_1001a3bc;
  hThread = GetCurrentThread();
  SetThreadAffinityMask(hThread,dwThreadAffinityMask);
  (*DAT_1001a3cc)();
  return;
}



/* VA 10002150 */

void FUN_10002150(void)

{
  DAT_1001a3e0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,1,(LPCWSTR)0x0);
  (*DAT_1001a3b8)();
  return;
}



/* VA 10002180 */

void FUN_10002180(void)

{
  SetEvent(DAT_1001a3e0);
  return;
}



/* VA 100021a0 */

void FUN_100021a0(void)

{
  WaitForSingleObject(DAT_1001a3e0,0xffffffff);
  CloseHandle(DAT_1001a3e0);
  return;
}



/* VA 100021f0 */

int FUN_100021f0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;

  iVar1 = (**(code **)(*param_1 + 0x10))(param_1,3,param_3,param_4,1);
  if (-1 < iVar1) {
    iVar2 = (**(code **)(*param_1 + 0x10))(param_1,4,param_3,param_4,1);
    iVar1 = 0;
    if (iVar2 < 0) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}



/* VA 10002240 */

undefined4 * __fastcall FUN_10002240(undefined4 *param_1,HWND param_2)

{
  uint uVar1;
  BOOL BVar2;
  HANDLE hMem;
  uint *puVar3;
  uint *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  puStack_c = &LAB_10010c5e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[5] = 0xf;
  *(undefined1 *)param_1 = 0;
  local_8 = 0;
  BVar2 = IsClipboardFormatAvailable(1);
  if (BVar2 != 0) {
    BVar2 = OpenClipboard(param_2);
    if (BVar2 != 0) {
      hMem = GetClipboardData(1);
      if (hMem != (HANDLE)0x0) {
        puVar3 = GlobalLock(hMem);
        if (puVar3 != (uint *)0x0) {
          puVar4 = puVar3;
          do {
            uVar1 = *puVar4;
            puVar4 = (uint *)((int)puVar4 + 1);
          } while ((char)uVar1 != '\0');
          FUN_10003d80(param_1,puVar3,(int)puVar4 - ((int)puVar3 + 1));
          GlobalUnlock(hMem);
        }
      }
      CloseClipboard();
    }
  }
  ExceptionList = local_10;
  return param_1;
}



/* VA 10002320 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10002320(HWND param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  LPVOID local_24 [5];
  uint local_10;
  HWND local_c;
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  if (param_2 != 0x102) {
    if ((param_2 == 0x113) && ((LPVOID *)param_3 == &DAT_10019860)) {
      FUN_100024b0(&local_c);
    }
LAB_10002488:
    uVar2 = (*DAT_1001a3d4)(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  if (param_3 != (undefined4 *)0x16) goto LAB_10002488;
  piVar1 = FUN_10002240(local_24,param_1);
  if ((LPVOID *)piVar1 != &DAT_10019860) {
    if (0xf < DAT_10019874) {
      pvVar3 = DAT_10019860;
      if (0xfff < DAT_10019874 + 1) {
        pvVar3 = *(LPVOID *)((int)DAT_10019860 + -4);
        if (0x1f < (uint)((int)DAT_10019860 + (-4 - (int)pvVar3))) goto LAB_100024a7;
      }
      FUN_10004f47(pvVar3);
    }
    DAT_10019860 = (LPVOID)*piVar1;
    iRam10019864 = piVar1[1];
    iRam10019868 = piVar1[2];
    iRam1001986c = piVar1[3];
    _DAT_10019870 = *(undefined8 *)(piVar1 + 4);
    piVar1[4] = 0;
    piVar1[5] = 0xf;
    *(undefined1 *)piVar1 = 0;
  }
  if (0xf < local_10) {
    pvVar3 = local_24[0];
    if (0xfff < local_10 + 1) {
      pvVar3 = *(LPVOID *)((int)local_24[0] + -4);
      if (0x1f < (uint)((int)local_24[0] + (-4 - (int)pvVar3))) {
LAB_100024a7:
                    /* WARNING: Subroutine does not return */
        FUN_100080b4();
      }
    }
    FUN_10004f47(pvVar3);
  }
  if (DAT_10019870 != 0) {
    SetTimer(param_1,0x10019860,0x23,(TIMERPROC)0x0);
    FUN_100024b0(&local_c);
    return 0;
  }
  KillTimer(param_1,0x10019860);
  return 0;
}



/* VA 100024b0 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL __fastcall FUN_100024b0(undefined4 *param_1)

{
  uint *puVar1;
  BOOL BVar2;
  int iVar3;
  ulonglong uVar4;

  puVar1 = (uint *)&DAT_10019860;
  if (0xf < DAT_10019874) {
    puVar1 = DAT_10019860;
  }
  SendMessageA((HWND)*param_1,0x102,(int)(char)*puVar1,1);
  puVar1 = (uint *)&DAT_10019860;
  if (0xf < DAT_10019874) {
    puVar1 = DAT_10019860;
  }
  iVar3 = DAT_10019870 - (uint)(DAT_10019870 != 0);
  uVar4 = FUN_10007600(puVar1,(uint *)((int)puVar1 + (uint)(DAT_10019870 != 0)),iVar3 + 1);
  BVar2 = (BOOL)uVar4;
  DAT_10019870 = iVar3;
  if (iVar3 == 0) {
    BVar2 = KillTimer((HWND)*param_1,0x10019860);
  }
  return BVar2;
}



/* VA 10002580 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_10002580(HWND param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  char cVar3;
  char ****ppppcVar4;
  undefined1 auStack_2c [4];
  char ***local_28;
  char ***local_24 [4];
  int local_14;
  uint local_10;
  uint local_c;

  local_c = DAT_10019008 ^ (uint)auStack_2c;
  if (param_2 == 0x102) {
    if (param_3 == 0x16) {
      cVar3 = '\0';
      FUN_10002240(local_24,param_1);
      ppppcVar4 = local_24;
      if (0xf < local_10) {
        ppppcVar4 = (char ****)local_24[0];
      }
      local_28 = (char ***)((int)ppppcVar4 + local_14);
      if (ppppcVar4 != (char ****)local_28) {
        do {
          cVar1 = *(char *)ppppcVar4;
          if (cVar3 == cVar1) {
            SendMessageA(param_1,0x102,2,1);
          }
          SendMessageA(param_1,0x102,(int)cVar1,1);
          ppppcVar4 = (char ****)((int)ppppcVar4 + 1);
          cVar3 = cVar1;
        } while (ppppcVar4 != (char ****)local_28);
      }
      if (0xf < local_10) {
        ppppcVar4 = (char ****)local_24[0];
        if ((0xfff < local_10 + 1) &&
           (ppppcVar4 = (char ****)local_24[0][-1],
           (char *)0x1f < (char *)((int)local_24[0] + (-4 - (int)ppppcVar4)))) {
                    /* WARNING: Subroutine does not return */
          FUN_100080b4();
        }
        FUN_10004f47(ppppcVar4);
      }
      return 0;
    }
  }
  else if ((param_2 == 8) && (DAT_1001a3dc != (void *)0x0)) {
    _memset(DAT_1001a3dc,0,0x80);
  }
  uVar2 = (*DAT_1001a3d4)(param_1,param_2,param_3,param_4);
  return uVar2;
}



/* VA 100026c0 */

void FUN_100026c0(int param_1)

{
  undefined4 *puVar1;

  puVar1 = DAT_1001a3d8;
  DAT_1001a3d4 = *(undefined4 *)(param_1 + 4);
  *(code **)(param_1 + 4) = FUN_10002580;
                    /* WARNING: Could not recover jumptable at 0x100026e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)();
  return;
}



/* VA 100026f0 */

void __fastcall FUN_100026f0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  code *pcVar3;

  (*DAT_1001a3e8)();
  puVar2 = DAT_1001a3e4;
  uVar1 = param_1;
  if (DAT_1001a3e4 != (undefined4 *)0x0) {
    uVar1 = *DAT_1001a3e4;
    pcVar3 = (code *)*DAT_1001a3f0;
    if (pcVar3 == (code *)0x0) {
      pcVar3 = (code *)*DAT_1001a3ec;
    }
    DAT_1001a3e4 = (undefined4 *)param_1;
    (*pcVar3)(uVar1);
    pcVar3 = (code *)*DAT_1001a3f0;
    if (pcVar3 == (code *)0x0) {
      pcVar3 = (code *)*DAT_1001a3ec;
    }
    (*pcVar3)(puVar2);
    uVar1 = DAT_1001a3e4;
  }
  DAT_1001a3e4 = (undefined4 *)uVar1;
  return;
}



/* VA 10002740 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_10002740(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uStack_114;
  int local_104 [18];
  int local_bc [18];
  int local_74 [19];
  undefined4 *local_28;
  undefined4 *local_24;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  DWORD local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10010ca3;
  local_10 = ExceptionList;
  uStack_114 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_114;
  ExceptionList = &local_10;
  local_18 = uStack_114;
  DVar3 = (*(code *)*DAT_1001a3f4)(param_1);
  if (DVar3 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  local_8 = 0;
  local_1c = DVar3;
  puVar4 = FUN_10001560(local_74,DVar3,"FF 15 ? ? ? ? 83 C4 04 FF 74 24",0x1f);
  local_8._0_1_ = 1;
  FUN_10004550(puVar4,1);
  if (puVar4[0xd] - (int)puVar4[0xc] >> 2 != 1) {
    local_1d = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)&local_1d,&DAT_100179bc);
  }
  local_28 = (undefined4 *)(*(int *)puVar4[0xc] + 2);
  local_8._0_1_ = 0;
  FUN_10001480(local_74);
  puVar4 = FUN_10001560(local_bc,DVar3,"A1 ? ? ? ? 56 85 C0 74 04 FF D0",0x1f);
  local_8._0_1_ = 2;
  FUN_10004550(puVar4,1);
  if (puVar4[0xd] - (int)puVar4[0xc] >> 2 != 1) {
    local_1e = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)&local_1e,&DAT_100179bc);
  }
  local_24 = (undefined4 *)(*(int *)puVar4[0xc] + 1);
  local_8._0_1_ = 0;
  FUN_10001480(local_bc);
  puVar4 = FUN_10001560(local_104,DVar3,"8B 4D 08 E8 ? ? ? ? A1",0x16);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10004550(puVar4,1);
  if (puVar4[0xd] - (int)puVar4[0xc] >> 2 == 1) {
    iVar2 = *(int *)puVar4[0xc];
    FUN_10001480(local_104);
    DAT_1001a3ec = *local_28;
    DAT_1001a3f0 = *local_24;
    VirtualProtect((LPVOID)(iVar2 + 3),5,0x40,&local_1c);
    piVar1 = (int *)(iVar2 + 4);
    DAT_1001a3e8 = *(int *)(iVar2 + 4) + 4 + (int)piVar1;
    *piVar1 = (int)&UNK_100026ec - (int)piVar1;
    VirtualProtect((LPVOID)(iVar2 + 3),5,local_1c,&local_1c);
    uVar5 = FUN_100028ef();
    return uVar5;
  }
  local_1f = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)&local_1f,&DAT_100179bc);
}



/* VA 100028e6 */

undefined * Catch_100028e6(void)

{
  return &DAT_100028ec;
}



/* VA 100028ef */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_100028ef(void)

{
  int unaff_EBP;

  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10002960 */

void FUN_10002960(void)

{
  byte bVar1;
  code *pcVar2;
  DWORD_PTR dwThreadAffinityMask;
  HMODULE pHVar3;
  int iVar4;
  undefined8 *puVar5;
  HANDLE pvVar6;
  BOOL BVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  HMODULE pHVar13;
  uint uVar14;
  bool bVar15;
  uint uStack_14c;
  int aiStack_13c [18];
  int aiStack_f4 [21];
  undefined1 uStack_9e;
  undefined1 uStack_9d;
  undefined1 auStack_9c [2];
  undefined1 auStack_9a [18];
  HMODULE local_88;
  int local_80 [19];
  undefined8 *local_34;
  DWORD local_30;
  undefined8 *local_2c;
  ULONG_PTR local_28 [2];
  undefined8 *local_20 [2];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10010e25;
  local_10 = ExceptionList;
  uStack_14c = DAT_10019008 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_14c;
  ExceptionList = &local_10;
  local_18 = uStack_14c;
  pHVar3 = GetModuleHandleW((LPCWSTR)0x0);
  local_88 = pHVar3;
  local_2c = operator_new(8);
  *local_2c = 0;
  *(undefined4 *)local_2c = 0;
  local_8 = 1;
  uVar14 = 0;
  *(undefined1 *)((int)local_2c + 4) = 0;
  iVar4 = pHVar3[0xf].unused;
  local_34 = (undefined8 *)(uint)*(ushort *)((int)&pHVar3[1].unused + iVar4 + 2);
  pcVar11 = (char *)((int)&pHVar3[6].unused +
                    iVar4 + (uint)*(ushort *)((int)&pHVar3[5].unused + iVar4));
  puVar5 = local_2c;
  pHVar3 = local_88;
  if (local_34 != (undefined8 *)0x0) {
    do {
      iVar4 = _strncmp(pcVar11,".text",8);
      pHVar3 = local_88;
      if (iVar4 == 0) {
        FUN_10001790(local_2c,(int)&local_88->unused + *(int *)(pcVar11 + 0xc),
                     *(uint *)(pcVar11 + 8));
        *(undefined1 *)((int)local_2c + 4) = 1;
        puVar5 = local_2c;
        break;
      }
      uVar14 = uVar14 + 1;
      pcVar11 = pcVar11 + 0x28;
      puVar5 = local_2c;
    } while (uVar14 < local_34);
  }
  local_8 = 2;
  if (*(char *)((int)puVar5 + 4) == '\0') {
    local_2c = puVar5;
    puVar5 = operator_new(4);
    *(undefined4 *)puVar5 = 0;
    *(undefined4 *)puVar5 = 0;
    local_8 = CONCAT31(local_8._1_3_,4);
    local_20[0] = puVar5;
    FUN_10001790(puVar5,(int)pHVar3,*(uint *)((int)&pHVar3[0x14].unused + pHVar3[0xf].unused));
    local_28[0] = 0;
    local_34 = puVar5;
    FUN_10003c30(local_28);
  }
  else {
    local_2c = (undefined8 *)0x0;
    local_34 = puVar5;
  }
  FUN_10003cb0(&local_2c);
  local_8 = 5;
  pHVar3 = GetModuleHandleW((LPCWSTR)0x0);
  piVar10 = (int *)((int)&pHVar3->unused + *(int *)((int)&pHVar3[0x20].unused + pHVar3[0xf].unused))
  ;
  iVar4 = piVar10[3];
  do {
    local_88 = (HMODULE)piVar10;
    if (iVar4 == 0) {
LAB_10002b57:
      bVar15 = FUN_10001d70();
      if (bVar15) {
        pvVar6 = GetCurrentProcess();
        BVar7 = GetProcessAffinityMask(pvVar6,(PDWORD_PTR)local_20,local_28);
        if ((BVar7 != 0) && (uVar14 = local_28[0] - 1 & local_28[0], uVar14 != 0)) {
          DAT_1001a3bc = ~uVar14 & local_28[0];
          SetProcessAffinityMask(pvVar6,local_28[0]);
          dwThreadAffinityMask = DAT_1001a3bc;
          pvVar6 = GetCurrentThread();
          SetThreadAffinityMask(pvVar6,dwThreadAffinityMask);
          local_8._0_1_ = 6;
          puVar8 = FUN_10001640(local_80,"50 31 D2 B8 ? ? ? ? E8 ? ? ? ? 8B 86 A4 00 00 00",0x30);
          local_8 = CONCAT31(local_8._1_3_,7);
          FUN_10004550(puVar8,1);
          if (puVar8[0xd] - (int)puVar8[0xc] >> 2 != 1) {
            auStack_9a[0] = 0;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8((int *)auStack_9a,&DAT_100179bc);
          }
          iVar4 = *(int *)puVar8[0xc];
          FUN_10001480(local_80);
          DAT_1001a3c8 = *(undefined4 *)(iVar4 + 4);
          *(code **)(iVar4 + 4) = FUN_100020e0;
          local_8 = 5;
          FUN_10002e91();
          return;
        }
      }
      local_8._0_1_ = 0xc;
      puVar8 = FUN_10001640(local_80,"89 86 A4 00 00 00 E8 ? ? ? ? 89 86 AC 00 00 00",0x2e);
      local_8._0_1_ = 0xd;
      FUN_10004550(puVar8,1);
      if (puVar8[0xd] - (int)puVar8[0xc] >> 2 != 1) {
        auStack_9c[0] = 0;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8((int *)auStack_9c,&DAT_100179bc);
      }
      local_20[0] = *(undefined8 **)puVar8[0xc];
      local_8._0_1_ = 0xc;
      FUN_10001480(local_80);
      puVar8 = FUN_10001640(aiStack_13c,"8B 86 A4 00 00 00 E8 ? ? ? ? 89 F0",0x22);
      local_8._0_1_ = 0xe;
      FUN_10004550(puVar8,1);
      if (puVar8[0xd] - (int)puVar8[0xc] >> 2 != 1) {
        uStack_9d = 0;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8((int *)&uStack_9d,&DAT_100179bc);
      }
      local_28[0] = *(ULONG_PTR *)puVar8[0xc];
      local_8._0_1_ = 0xc;
      FUN_10001480(aiStack_13c);
      puVar8 = FUN_10001640(aiStack_f4,"31 C0 E8 ? ? ? ? BF 01 00 00 00 31 ED",0x25);
      local_8 = CONCAT31(local_8._1_3_,0xf);
      FUN_10004550(puVar8,1);
      if (puVar8[0xd] - (int)puVar8[0xc] >> 2 != 1) {
        uStack_9e = 0;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8((int *)&uStack_9e,&DAT_100179bc);
      }
      iVar4 = *(int *)puVar8[0xc];
      FUN_10001480(aiStack_f4);
      piVar10 = (int *)((int)local_20[0] + 7);
      DAT_1001a3b8 = *piVar10 + 4 + (int)piVar10;
      *piVar10 = (int)&UNK_1000214c - (int)piVar10;
      local_8 = 5;
      *(int *)(local_28[0] + 7) = 0x1000219c - (int)(local_28[0] + 7);
      piVar10 = (int *)(iVar4 + 3);
      *piVar10 = 0x1000217c - (int)piVar10;
      FUN_10002fed();
      return;
    }
    iVar4 = FUN_10007cbf((byte *)((int)&pHVar3->unused + piVar10[3]),(byte *)"user32.dll");
    pHVar13 = (HMODULE)piVar10;
    if (iVar4 == 0) {
      iVar4 = *piVar10;
      if (iVar4 == 0) {
        iVar4 = 0;
        piVar10 = (int *)((int)&pHVar3->unused + piVar10[4]);
        pcVar2 = (code *)*piVar10;
        while (pcVar2 != (code *)0x0) {
          if (pcVar2 == keybd_event_exref) {
            piVar10 = piVar10 + iVar4;
            goto LAB_10002c24;
          }
          iVar12 = iVar4 + 1;
          iVar4 = iVar4 + 1;
          pcVar2 = (code *)piVar10[iVar12];
        }
      }
      else {
        local_28[0] = (int)&pHVar3->unused + iVar4;
        iVar12 = 0;
        iVar4 = *(int *)((int)&pHVar3->unused + iVar4);
        while (pHVar13 = local_88, iVar4 != 0) {
          pcVar11 = "keybd_event";
          pbVar9 = (byte *)((int)&pHVar3->unused + iVar4 + 2);
          do {
            bVar1 = *pbVar9;
            bVar15 = bVar1 < (byte)*pcVar11;
            if (bVar1 != *pcVar11) {
LAB_10002b20:
              uVar14 = -(uint)bVar15 | 1;
              goto LAB_10002b25;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar9[1];
            bVar15 = bVar1 < (byte)pcVar11[1];
            if (bVar1 != pcVar11[1]) goto LAB_10002b20;
            pbVar9 = pbVar9 + 2;
            pcVar11 = pcVar11 + 2;
          } while (bVar1 != 0);
          uVar14 = 0;
LAB_10002b25:
          if (uVar14 == 0) {
            piVar10 = (int *)((int)&pHVar3[iVar12].unused + local_88[4].unused);
LAB_10002c24:
            VirtualProtect(piVar10,4,4,&local_30);
            *piVar10 = (int)&DAT_10002950;
            VirtualProtect(piVar10,4,local_30,&local_30);
            goto LAB_10002b57;
          }
          iVar12 = iVar12 + 1;
          iVar4 = *(int *)(local_28[0] + iVar12 * 4);
        }
      }
    }
    piVar10 = &pHVar13[5].unused;
    iVar4 = pHVar13[8].unused;
  } while( true );
}



/* VA 10002c76 */

undefined1 * Catch_10002c76(void)

{
  return &LAB_10002c7c;
}



/* VA 10002ce4 */

undefined * Catch_10002ce4(void)

{
  return &DAT_10002cea;
}



/* VA 10002e91 */

void FUN_10002e91(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int *piVar4;
  int unaff_EBP;
  code *unaff_EDI;

  pcVar2 = SetProcessAffinityMask_exref;
  (*unaff_EDI)(SetProcessAffinityMask_exref,5,0x40,unaff_EBP + -0x24);
  *pcVar2 = (code)0xe9;
  *(int *)(pcVar2 + 1) = 0x1000207c - (int)(pcVar2 + 1);
  (*unaff_EDI)(pcVar2,5,*(undefined4 *)(unaff_EBP + -0x24),unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  puVar3 = FUN_10001640((void *)(unaff_EBP + -0x7c),"89 86 A4 00 00 00 E8 ? ? ? ? 89 86 AC 00 00 00"
                        ,0x2e);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10004550(puVar3,1);
  if (puVar3[0xd] - (int)puVar3[0xc] >> 2 != 1) {
    *(undefined1 *)(unaff_EBP + -0x98) = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)(unaff_EBP + -0x98),&DAT_100179bc);
  }
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)puVar3[0xc];
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_10001480((int *)(unaff_EBP + -0x7c));
  puVar3 = FUN_10001640((void *)(unaff_EBP + -0x138),"8B 86 A4 00 00 00 E8 ? ? ? ? 89 F0",0x22);
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_10004550(puVar3,1);
  if (puVar3[0xd] - (int)puVar3[0xc] >> 2 == 1) {
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)puVar3[0xc];
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    FUN_10001480((int *)(unaff_EBP + -0x138));
    puVar3 = FUN_10001640((void *)(unaff_EBP + -0xf0),"31 C0 E8 ? ? ? ? BF 01 00 00 00 31 ED",0x25);
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    FUN_10004550(puVar3,1);
    if (puVar3[0xd] - (int)puVar3[0xc] >> 2 == 1) {
      iVar1 = *(int *)puVar3[0xc];
      FUN_10001480((int *)(unaff_EBP + -0xf0));
      piVar4 = (int *)(*(int *)(unaff_EBP + -0x1c) + 7);
      DAT_1001a3b8 = *piVar4 + 4 + (int)piVar4;
      *piVar4 = (int)&UNK_1000214c - (int)piVar4;
      piVar4 = (int *)(*(int *)(unaff_EBP + -0x24) + 7);
      *(undefined4 *)(unaff_EBP + -4) = 5;
      *piVar4 = 0x1000219c - (int)piVar4;
      piVar4 = (int *)(iVar1 + 3);
      *piVar4 = 0x1000217c - (int)piVar4;
      FUN_10002fed();
      return;
    }
    *(undefined1 *)(unaff_EBP + -0x9a) = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)(unaff_EBP + -0x9a),&DAT_100179bc);
  }
  *(undefined1 *)(unaff_EBP + -0x99) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x99),&DAT_100179bc);
}



/* VA 10002fda */

undefined * Catch_10002fda(void)

{
  return &DAT_10002fe0;
}



/* VA 10002fed */

void FUN_10002fed(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  int *piVar3;

  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  puVar2 = FUN_10001640((void *)(unaff_EBP + -0xf0),"8B 10 50 FF 52 28 89 C2 85 C0 0F 85",0x23);
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  FUN_10004550(puVar2,1);
  if (puVar2[0xd] - (int)puVar2[0xc] >> 2 != 1) {
    *(undefined1 *)(unaff_EBP + -0x9b) = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)(unaff_EBP + -0x9b),&DAT_100179bc);
  }
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)puVar2[0xc];
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_10001480((int *)(unaff_EBP + -0xf0));
  puVar2 = FUN_10001640((void *)(unaff_EBP + -0x138),"89 CB C1 E3 04",0xe);
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  FUN_10004550(puVar2,1);
  if (puVar2[0xd] - (int)puVar2[0xc] >> 2 == 1) {
    puVar1 = *(undefined1 **)puVar2[0xc];
    FUN_10001480((int *)(unaff_EBP + -0x138));
    *(undefined4 *)(unaff_EBP + -4) = 5;
    *(undefined1 *)(*(int *)(unaff_EBP + -0x1c) + 0xb) = 0x88;
    *puVar1 = 0xe8;
    piVar3 = (int *)(puVar1 + 1);
    *piVar3 = 0x100021cc - (int)piVar3;
    FUN_100030af();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x9c) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x9c),&DAT_100179bc);
}



/* VA 1000309c */

undefined * Catch_1000309c(void)

{
  return &DAT_100030a2;
}



/* VA 100030af */

void FUN_100030af(void)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;

  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"8B 90 ? ? ? ? D3 E7 09 FA 89 90",0x1f);
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    iVar1 = *(int *)this[0xc];
    *(undefined1 *)(unaff_EBP + -4) = 0x15;
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *(undefined4 *)(unaff_EBP + -0x28) = 0x90909042;
    *(undefined4 *)(iVar1 + 6) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_10003122();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x9d) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x9d),&DAT_100179bc);
}



/* VA 1000310f */

undefined * Catch_1000310f(void)

{
  return &DAT_10003115;
}



/* VA 10003122 */

void FUN_10003122(void)

{
  uint *puVar1;
  undefined4 *this;
  int unaff_EBP;

  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"85 C0 74 16 83 F8 01 74 10 3D 57 00 07 80",0x29);
  *(undefined1 *)(unaff_EBP + -4) = 0x19;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    puVar1 = *(uint **)this[0xc];
    *(undefined1 *)(unaff_EBP + -4) = 0x18;
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *(undefined4 *)(unaff_EBP + -0x1c) = 0xe8c1d0f7;
    *(undefined2 *)(unaff_EBP + -0x18) = 0xc31f;
    FUN_10007600(puVar1,(uint *)(unaff_EBP + -0x1c),6);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_100031a4();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x85) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x85),&DAT_100179bc);
}



/* VA 10003191 */

undefined * Catch_10003191(void)

{
  return &DAT_10003197;
}



/* VA 100031a4 */

void FUN_100031a4(void)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;

  *(undefined1 *)(unaff_EBP + -4) = 0x1b;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"FF 51 28 85 C0 0F 84 ? ? ? ? 31 D2 8B 4D FC",0x2b
                     );
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    iVar1 = *(int *)this[0xc];
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *(undefined1 *)(iVar1 + 6) = 0x8d;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_1000320a();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x86) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x86),&DAT_100179bc);
}



/* VA 100031f7 */

undefined * Catch_100031f7(void)

{
  return &DAT_100031fd;
}



/* VA 1000320a */

void FUN_1000320a(void)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;

  *(undefined1 *)(unaff_EBP + -4) = 0x1e;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"83 7D F4 00 0F 84 ? ? ? ? 89 1D",0x1f);
  *(undefined1 *)(unaff_EBP + -4) = 0x1f;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    iVar1 = *(int *)this[0xc];
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *(undefined1 *)(iVar1 + 5) = 0x8d;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_10003270();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x87) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x87),&DAT_100179bc);
}



/* VA 1000325d */

undefined * Catch_1000325d(void)

{
  return &DAT_10003263;
}



/* VA 10003270 */

void FUN_10003270(void)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;

  *(undefined1 *)(unaff_EBP + -4) = 0x21;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"FF 52 64 85 C0 74 ? 3D 1E 00 07 80",0x22);
  *(undefined1 *)(unaff_EBP + -4) = 0x22;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    iVar1 = *(int *)this[0xc];
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *(undefined1 *)(iVar1 + 5) = 0x7d;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_100032d6();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x88) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x88),&DAT_100179bc);
}



/* VA 100032c3 */

undefined * Catch_100032c3(void)

{
  return &DAT_100032c9;
}



/* VA 100032d6 */

void FUN_100032d6(void)

{
  undefined1 *puVar1;
  undefined4 *this;
  int unaff_EBP;
  int *piVar2;

  *(undefined1 *)(unaff_EBP + -4) = 0x24;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"8B 7D F4 85 FF 74 ? 81 7D F4 1E 00 07 80",0x28);
  *(undefined1 *)(unaff_EBP + -4) = 0x25;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    puVar1 = *(undefined1 **)this[0xc];
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *puVar1 = 0xe8;
    piVar2 = (int *)(puVar1 + 1);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    *piVar2 = (int)&UNK_100021dc - (int)piVar2;
    FUN_10003348();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x89) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x89),&DAT_100179bc);
}



/* VA 10003335 */

undefined * Catch_10003335(void)

{
  return &DAT_1000333b;
}



/* VA 10003348 */

void FUN_10003348(void)

{
  uint *puVar1;
  undefined4 *this;
  int unaff_EBP;

  *(undefined1 *)(unaff_EBP + -4) = 0x27;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"B8 01 00 00 00 5F 5E 5B C2 18 00",0x20);
  *(undefined1 *)(unaff_EBP + -4) = 0x28;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    puVar1 = *(uint **)this[0xc];
    *(undefined1 *)(unaff_EBP + -4) = 0x27;
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x9090c031;
    *(undefined1 *)(unaff_EBP + -0x18) = 0x90;
    FUN_10007600(puVar1,(uint *)(unaff_EBP + -0x1c),5);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_100033c8();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x8a) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x8a),&DAT_100179bc);
}



/* VA 100033b5 */

undefined * Catch_100033b5(void)

{
  return &DAT_100033bb;
}



/* VA 100033c8 */

void FUN_100033c8(void)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;

  *(undefined1 *)(unaff_EBP + -4) = 0x2a;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),
                      "83 E3 01 E8 ? ? ? ? EB ? B8 01 00 00 00 5D 5F 5E 5B C2 18 00",0x3c);
  *(undefined1 *)(unaff_EBP + -4) = 0x2b;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    iVar1 = *(int *)this[0xc];
    *(undefined1 *)(unaff_EBP + -4) = 0x2a;
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x9090c031;
    *(undefined1 *)(unaff_EBP + -0x18) = 0x90;
    FUN_10007600((uint *)(iVar1 + 10),(uint *)(unaff_EBP + -0x1c),5);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_1000344b();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x8b) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x8b),&DAT_100179bc);
}



/* VA 10003438 */

undefined * Catch_10003438(void)

{
  return &DAT_1000343e;
}



/* VA 1000344b */

void FUN_1000344b(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *this;
  int unaff_EBP;

  *(undefined1 *)(unaff_EBP + -4) = 0x2d;
  _memset((void *)(unaff_EBP + -0x7c),0,0x48);
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"5F 5E B8 01 00 00 00 5B C2 18 00",0x20);
  *(undefined1 *)(unaff_EBP + -4) = 0x2e;
  FUN_10004550(this,2);
  if ((int)(this[0xd] - this[0xc]) >> 2 == 2) {
    *(undefined4 *)(unaff_EBP + -0x6c) = 0;
    *(undefined4 *)(unaff_EBP + -0x7c) = 0;
    *(undefined4 *)(unaff_EBP + -0x78) = 0;
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
    *(undefined4 *)(unaff_EBP + -0x70) = 0;
    *(undefined4 *)(unaff_EBP + -0x68) = 0;
    uVar1 = this[1];
    uVar2 = this[2];
    uVar3 = this[3];
    *(undefined4 *)(unaff_EBP + -0x7c) = *this;
    *(undefined4 *)(unaff_EBP + -0x78) = uVar1;
    *(undefined4 *)(unaff_EBP + -0x74) = uVar2;
    *(undefined4 *)(unaff_EBP + -0x70) = uVar3;
    *(undefined8 *)(unaff_EBP + -0x6c) = *(undefined8 *)(this + 4);
    this[4] = 0;
    this[5] = 0xf;
    *(undefined1 *)this = 0;
    *(undefined4 *)(unaff_EBP + -100) = 0;
    *(undefined4 *)(unaff_EBP + -0x60) = 0;
    *(undefined4 *)(unaff_EBP + -0x5c) = 0;
    *(undefined4 *)(unaff_EBP + -0x58) = 0;
    *(undefined4 *)(unaff_EBP + -0x54) = 0;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    uVar1 = this[7];
    uVar2 = this[8];
    uVar3 = this[9];
    *(undefined4 *)(unaff_EBP + -100) = this[6];
    *(undefined4 *)(unaff_EBP + -0x60) = uVar1;
    *(undefined4 *)(unaff_EBP + -0x5c) = uVar2;
    *(undefined4 *)(unaff_EBP + -0x58) = uVar3;
    *(undefined8 *)(unaff_EBP + -0x54) = *(undefined8 *)(this + 10);
    this[10] = 0;
    this[0xb] = 0xf;
    *(undefined1 *)(this + 6) = 0;
    uVar1 = this[0xc];
    uVar2 = this[0xe];
    uVar3 = this[0xd];
    this[0xe] = 0;
    this[0xd] = 0;
    this[0xc] = 0;
    *(undefined4 *)(unaff_EBP + -0x4c) = uVar1;
    *(undefined4 *)(unaff_EBP + -0x48) = uVar3;
    *(undefined4 *)(unaff_EBP + -0x44) = uVar2;
    *(undefined1 *)(unaff_EBP + -0x40) = *(undefined1 *)(this + 0xf);
    *(undefined4 *)(unaff_EBP + -0x3c) = this[0x10];
    *(undefined4 *)(unaff_EBP + -0x38) = this[0x11];
    *(undefined1 *)(unaff_EBP + -4) = 0x30;
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    FUN_10003ec0((void *)(unaff_EBP + -0x7c),unaff_EBP + -0x81);
    FUN_10001480((int *)(unaff_EBP + -0x7c));
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_10003586();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x8c) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x8c),&DAT_100179bc);
}



/* VA 10003573 */

undefined * Catch_10003573(void)

{
  return &DAT_10003579;
}



/* VA 10003586 */

void FUN_10003586(void)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;
  int *piVar2;

  *(undefined1 *)(unaff_EBP + -4) = 0x32;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"56 52 89 74 24 0C 8B 08",0x17);
  *(undefined1 *)(unaff_EBP + -4) = 0x33;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    iVar1 = *(int *)this[0xc];
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    *(undefined2 *)(iVar1 + 2) = 0xe890;
    piVar2 = (int *)(iVar1 + 4);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    *piVar2 = (int)&UNK_1000222c - (int)piVar2;
    FUN_10003608();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x8d) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x8d),&DAT_100179bc);
}



/* VA 100035f5 */

undefined * Catch_100035f5(void)

{
  return &DAT_100035fb;
}



/* VA 10003608 */

void FUN_10003608(void)

{
  uint *puVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  int unaff_EBP;

  BVar2 = GetModuleHandleExW(2,L"nfs2se.p",(HMODULE *)(unaff_EBP + -0x80));
  if (BVar2 == 0) {
    *(undefined1 *)(unaff_EBP + -4) = 0x3b;
    puVar3 = FUN_10001640((void *)(unaff_EBP + -0xf0),"BA ? ? ? ? 8B 3D ? ? ? ? 31 C9 89 04 24",0x27
                         );
    *(undefined1 *)(unaff_EBP + -4) = 0x3c;
    FUN_10004550(puVar3,1);
    if (puVar3[0xd] - (int)puVar3[0xc] >> 2 == 1) {
      FUN_100037a4((int *)puVar3[0xc]);
      return;
    }
    *(undefined1 *)(unaff_EBP + -0x90) = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)(unaff_EBP + -0x90),&DAT_100179bc);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0x35;
  puVar3 = FUN_10001640((void *)(unaff_EBP + -0xf0),"E9 ? ? ? ? ? ? ? ? ? 75 6B 68 F0 00 00 00",0x29
                       );
  *(undefined1 *)(unaff_EBP + -4) = 0x36;
  FUN_10004550(puVar3,1);
  if (puVar3[0xd] - (int)puVar3[0xc] >> 2 == 1) {
    puVar1 = *(uint **)puVar3[0xc];
    *(undefined1 *)(unaff_EBP + -4) = 0x35;
    FUN_10001480((int *)(unaff_EBP + -0xf0));
    BVar2 = GetModuleHandleExW(6,(LPCWSTR)(*(int *)((int)puVar1 + 1) + 5 + (int)puVar1),
                               (HMODULE *)(unaff_EBP + -0x1c));
    if ((BVar2 != 0) && (*(int *)(unaff_EBP + -0x80) == *(int *)(unaff_EBP + -0x1c))) {
      *(undefined4 *)(unaff_EBP + -0x24) = 0x83525153;
      *(undefined1 *)(unaff_EBP + -0x20) = 0x3d;
      FUN_10007600(puVar1,(uint *)(unaff_EBP + -0x24),5);
      *(undefined4 *)((int)puVar1 + 0x1b) = 0xf1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 5;
    FUN_100036d4();
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x8e) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x8e),&DAT_100179bc);
}



/* VA 100036c1 */

undefined * Catch_100036c1(void)

{
  return &DAT_100036c7;
}



/* VA 100036d4 */

void FUN_100036d4(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined2 *puVar3;
  code *unaff_EDI;

  *(undefined1 *)(unaff_EBP + -4) = 0x38;
  puVar2 = FUN_10001560((undefined4 *)(unaff_EBP + -0xf0),*(undefined4 *)(unaff_EBP + -0x80),
                        "83 39 00 74 07 FE C0",0x14);
  *(undefined1 *)(unaff_EBP + -4) = 0x39;
  FUN_10004550(puVar2,1);
  if (puVar2[0xd] - (int)puVar2[0xc] >> 2 != 1) {
    *(undefined1 *)(unaff_EBP + -0x8f) = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)(unaff_EBP + -0x8f),&DAT_100179bc);
  }
  iVar1 = *(int *)puVar2[0xc];
  *(undefined1 *)(unaff_EBP + -4) = 0x38;
  FUN_10001480((int *)(unaff_EBP + -0xf0));
  *(undefined2 *)(unaff_EBP + -0x84) = 0x7501;
  puVar3 = (undefined2 *)(iVar1 + 2);
  (*unaff_EDI)(puVar3,2,0x40,unaff_EBP + -0x24);
  *puVar3 = *(undefined2 *)(unaff_EBP + -0x84);
  (*unaff_EDI)(puVar3,2,*(undefined4 *)(unaff_EBP + -0x24),unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 5;
  *(undefined1 *)(unaff_EBP + -4) = 0x3b;
  puVar2 = FUN_10001640((void *)(unaff_EBP + -0xf0),"BA ? ? ? ? 8B 3D ? ? ? ? 31 C9 89 04 24",0x27);
  *(undefined1 *)(unaff_EBP + -4) = 0x3c;
  FUN_10004550(puVar2,1);
  if (puVar2[0xd] - (int)puVar2[0xc] >> 2 == 1) {
    FUN_100037a4((int *)puVar2[0xc]);
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x90),&DAT_100179bc);
}



/* VA 1000379e */

undefined4 Catch_1000379e(void)

{
  return 0x1000375c;
}



/* VA 100037a4 */

void __fastcall FUN_100037a4(int *param_1)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;

  iVar1 = *param_1;
  FUN_10001480((int *)(unaff_EBP + -0xf0));
  DAT_1001a3d4 = *(undefined4 *)(iVar1 + 1);
  *(code **)(iVar1 + 1) = FUN_10002320;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  *(undefined1 *)(unaff_EBP + -4) = 0x3e;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"C7 45 ? ? ? ? ? 89 75 CC FF 35",0x1e);
  *(undefined1 *)(unaff_EBP + -4) = 0x3f;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    FUN_10003808((int *)this[0xc]);
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x91) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x91),&DAT_100179bc);
}



/* VA 10003802 */

undefined4 Catch_10003802(void)

{
  return 0x100037c0;
}



/* VA 10003808 */

void __fastcall FUN_10003808(int *param_1)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;

  iVar1 = *param_1;
  FUN_10001480((int *)(unaff_EBP + -0xf0));
  DAT_1001a3d4 = *(undefined4 *)(iVar1 + 3);
  *(code **)(iVar1 + 3) = FUN_10002580;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  *(undefined1 *)(unaff_EBP + -4) = 0x41;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),
                      "B9 0B 00 00 00 BE ? ? ? ? A1 ? ? ? ? 8B 15 ? ? ? ? 31 FF",0x38);
  *(undefined1 *)(unaff_EBP + -4) = 0x42;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    FUN_1000386c((int *)this[0xc]);
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x92) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x92),&DAT_100179bc);
}



/* VA 10003866 */

undefined4 Catch_10003866(void)

{
  return 0x10003824;
}



/* VA 1000386c */

void __fastcall FUN_1000386c(int *param_1)

{
  int iVar1;
  undefined4 *this;
  int unaff_EBP;

  iVar1 = *param_1;
  FUN_10001480((int *)(unaff_EBP + -0xf0));
  DAT_1001a3d4 = *(undefined4 *)(iVar1 + 6);
  *(code **)(iVar1 + 6) = FUN_10002580;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  *(undefined1 *)(unaff_EBP + -4) = 0x44;
  this = FUN_10001640((void *)(unaff_EBP + -0xf0),"89 44 24 50 FF 15 ? ? ? ? 66 85 C0",0x22);
  *(undefined1 *)(unaff_EBP + -4) = 0x45;
  FUN_10004550(this,1);
  if (this[0xd] - (int)this[0xc] >> 2 == 1) {
    FUN_100038d0((int *)this[0xc]);
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x93) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x93),&DAT_100179bc);
}



/* VA 100038ca */

undefined4 Catch_100038ca(void)

{
  return 0x10003888;
}



/* VA 100038d0 */

void __fastcall FUN_100038d0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_EBP;

  iVar1 = *param_1;
  FUN_10001480((int *)(unaff_EBP + -0xf0));
  DAT_1001a3d8 = *(undefined4 *)(iVar1 + 6);
  *(undefined ***)(iVar1 + 6) = &PTR_FUN_10019878;
  *(undefined1 *)(unaff_EBP + -4) = 0x46;
  puVar2 = FUN_10001640((void *)(unaff_EBP + -0xf0),"68 ? ? ? ? E8 ? ? ? ? 8B 54 24 28 8B 44 24 20",
                        0x2d);
  *(undefined1 *)(unaff_EBP + -4) = 0x47;
  FUN_10004550(puVar2,1);
  if (puVar2[0xd] - (int)puVar2[0xc] >> 2 != 1) {
    *(undefined1 *)(unaff_EBP + -0x94) = 0;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)(unaff_EBP + -0x94),&DAT_100179bc);
  }
  iVar1 = *(int *)puVar2[0xc];
  FUN_10001480((int *)(unaff_EBP + -0xf0));
  DAT_1001a3dc = *(undefined4 *)(iVar1 + 1);
  *(undefined4 *)(unaff_EBP + -4) = 5;
  *(undefined1 *)(unaff_EBP + -4) = 0x4a;
  puVar2 = FUN_10001640((void *)(unaff_EBP + -0xf0),"8B 35 ? ? ? ? 83 C4 0C 8D 4C 24 14",0x22);
  *(undefined1 *)(unaff_EBP + -4) = 0x4b;
  FUN_10004550(puVar2,1);
  if (puVar2[0xd] - (int)puVar2[0xc] >> 2 == 1) {
    FUN_10003988((int *)puVar2[0xc]);
    return;
  }
  *(undefined1 *)(unaff_EBP + -0x95) = 0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)(unaff_EBP + -0x95),&DAT_100179bc);
}



/* VA 1000397c */

undefined4 Catch_1000397c(void)

{
  return 0x1000393a;
}



/* VA 10003982 */

undefined4 Catch_10003982(void)

{
  return 0x1000393a;
}



/* VA 10003988 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_10003988(int *param_1)

{
  int iVar1;
  int unaff_EBP;

  iVar1 = *param_1;
  FUN_10001480((int *)(unaff_EBP + -0xf0));
  DAT_1001a3f4 = *(undefined4 *)(iVar1 + 2);
  *(undefined ***)(iVar1 + 2) = &PTR_FUN_1001987c;
  FUN_10003c30((undefined4 *)(unaff_EBP + -0x30));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 100039c8 */

undefined4 Catch_100039c8(void)

{
  return 0x100039a4;
}



/* VA 10003c30 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_10003c30(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD local_c;
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2
        ) {
      VirtualProtect((LPVOID)puVar2[3],puVar2[2],puVar2[1],&local_c);
    }
    puVar2 = (undefined4 *)*puVar1;
    *puVar1 = 0;
    while (puVar2 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)*puVar2;
      FUN_10004f47(puVar2);
      puVar2 = puVar3;
    }
    FUN_10004f47(puVar1);
  }
  return;
}



/* VA 10003cb0 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_10003cb0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD local_c;
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2
        ) {
      VirtualProtect((LPVOID)puVar2[3],puVar2[2],puVar2[1],&local_c);
    }
    puVar2 = (undefined4 *)*puVar1;
    *puVar1 = 0;
    while (puVar2 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)*puVar2;
      FUN_10004f47(puVar2);
      puVar2 = puVar3;
    }
    FUN_10004f47(puVar1);
  }
  return;
}



/* VA 10003d30 */

void __fastcall FUN_10003d30(int *param_1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;

  if (0xf < (uint)param_1[5]) {
    pvVar1 = (LPVOID)*param_1;
    pvVar2 = pvVar1;
    if ((0xfff < param_1[5] + 1U) &&
       (pvVar2 = *(LPVOID *)((int)pvVar1 + -4), 0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar2)))) {
                    /* WARNING: Subroutine does not return */
      FUN_100080b4();
    }
    FUN_10004f47(pvVar2);
  }
  param_1[4] = 0;
  param_1[5] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}



/* VA 10003d80 */

uint * __thiscall FUN_10003d80(void *this,uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  LPVOID pvVar3;
  code *pcVar4;
  uint uVar5;
  void *pvVar6;
  uint *puVar7;
  LPVOID pvVar8;
  uint uVar9;

  uVar2 = *(uint *)((int)this + 0x14);
  if (param_2 <= uVar2) {
    puVar7 = this;
    if (0xf < uVar2) {
      puVar7 = *(uint **)this;
    }
    *(uint *)((int)this + 0x10) = param_2;
    FUN_10007600(puVar7,param_1,param_2);
    *(undefined1 *)(param_2 + (int)puVar7) = 0;
    return this;
  }
  if (0x7fffffff < param_2) {
    FUN_10001470();
LAB_10003ea9:
    FUN_100013d0();
    pcVar4 = (code *)swi(3);
    puVar7 = (uint *)(*pcVar4)();
    return puVar7;
  }
  uVar9 = param_2 | 0xf;
  if ((uVar9 < 0x80000000) && (uVar2 <= 0x7fffffff - (uVar2 >> 1))) {
    uVar5 = (uVar2 >> 1) + uVar2;
    if (uVar9 < uVar5) {
      uVar9 = uVar5;
    }
    uVar1 = uVar9 + 1;
    if (0xfff < uVar1) {
      uVar5 = uVar9 + 0x24;
      if (uVar5 <= uVar1) goto LAB_10003ea9;
      goto LAB_10003e19;
    }
    if (uVar1 == 0) {
      puVar7 = (uint *)0x0;
    }
    else {
      puVar7 = operator_new(uVar1);
    }
  }
  else {
    uVar9 = 0x7fffffff;
    uVar5 = 0x80000023;
LAB_10003e19:
    pvVar6 = operator_new(uVar5);
    if (pvVar6 == (void *)0x0) goto LAB_10003e9f;
    puVar7 = (uint *)((int)pvVar6 + 0x23U & 0xffffffe0);
    puVar7[-1] = (uint)pvVar6;
  }
  *(uint *)((int)this + 0x10) = param_2;
  *(uint *)((int)this + 0x14) = uVar9;
  FUN_10007600(puVar7,param_1,param_2);
  *(undefined1 *)(param_2 + (int)puVar7) = 0;
  if (0xf < uVar2) {
    pvVar3 = *(LPVOID *)this;
    pvVar8 = pvVar3;
    if ((0xfff < uVar2 + 1) &&
       (pvVar8 = *(LPVOID *)((int)pvVar3 + -4), 0x1f < (uint)((int)pvVar3 + (-4 - (int)pvVar8)))) {
LAB_10003e9f:
                    /* WARNING: Subroutine does not return */
      FUN_100080b4();
    }
    FUN_10004f47(pvVar8);
  }
  *(uint **)this = puVar7;
  return this;
}



/* VA 10003eb0 */

void FUN_10003eb0(void)

{
  code *pcVar1;

  FUN_10004af9("invalid string position");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* VA 10003ec0 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x10003f16) */
/* WARNING: Removing unreachable block (ram,0x10003f4a) */

undefined4 __thiscall FUN_10003ec0(void *this,undefined4 param_1)

{
  int *piVar1;
  uint local_20;
  undefined1 local_1c;
  int *local_18;
  uint local_c;

  local_c = DAT_10019008 ^ (uint)&local_20;
  FUN_10004550(this,-1);
  local_18 = *(int **)((int)this + 0x34);
  piVar1 = *(int **)((int)this + 0x30);
  if (piVar1 != local_18) {
    do {
      local_20 = 0x9090c031;
      local_1c = 0x90;
      FUN_10007600((uint *)(*piVar1 + 2),&local_20,5);
      piVar1 = piVar1 + 1;
    } while (piVar1 != local_18);
  }
  return param_1;
}



/* VA 10003f50 */

uint * __thiscall FUN_10003f50(void *this,undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;

  iVar1 = *(int *)((int)this + 0x10);
  if (iVar1 == 0x7ffffffe) {
LAB_100040a2:
    FUN_10001470();
  }
  else {
    uVar2 = *(uint *)((int)this + 0x14);
    uVar7 = iVar1 + 1U | 7;
    if (uVar7 < 0x7fffffff) {
      if (0x7ffffffe - (uVar2 >> 1) < uVar2) {
        uVar7 = 0x7ffffffe;
        uVar4 = 0xfffffffe;
        goto LAB_10003fc4;
      }
      uVar4 = (uVar2 >> 1) + uVar2;
      if (uVar7 < uVar4) {
        uVar7 = uVar4;
      }
      if (0x7fffffff < uVar7 + 1) goto LAB_1000409d;
      uVar4 = (uVar7 + 1) * 2;
      if (0xfff < uVar4) goto LAB_10003fc4;
      if (uVar4 == 0) {
        puVar6 = (uint *)0x0;
      }
      else {
        puVar6 = operator_new(uVar4);
      }
    }
    else {
      uVar7 = 0x7ffffffe;
      uVar4 = 0xfffffffe;
LAB_10003fc4:
      if (uVar4 + 0x23 <= uVar4) {
LAB_1000409d:
        FUN_100013d0();
        goto LAB_100040a2;
      }
      pvVar5 = operator_new(uVar4 + 0x23);
      if (pvVar5 == (void *)0x0) goto LAB_100040a7;
      puVar6 = (uint *)((int)pvVar5 + 0x23U & 0xffffffe0);
      puVar6[-1] = (uint)pvVar5;
    }
    *(uint *)((int)this + 0x14) = uVar7;
    uVar7 = iVar1 * 2;
    *(int *)((int)this + 0x10) = iVar1 + 1;
    if (uVar2 < 8) {
      FUN_10007600(puVar6,this,uVar7);
      *(undefined2 *)(uVar7 + (int)puVar6) = param_3;
      *(undefined2 *)(uVar7 + 2 + (int)puVar6) = 0;
      *(uint **)this = puVar6;
      return this;
    }
    puVar3 = *(uint **)this;
    FUN_10007600(puVar6,puVar3,iVar1 * 2);
    *(undefined2 *)(iVar1 * 2 + (int)puVar6) = param_3;
    *(undefined2 *)(iVar1 * 2 + 2 + (int)puVar6) = 0;
    puVar8 = puVar3;
    if ((uVar2 * 2 + 2 < 0x1000) ||
       (puVar8 = (uint *)puVar3[-1], (uint)((int)puVar3 + (-4 - (int)puVar8)) < 0x20)) {
      FUN_10004f47(puVar8);
      *(uint **)this = puVar6;
      return this;
    }
  }
LAB_100040a7:
                    /* WARNING: Subroutine does not return */
  FUN_100080b4();
}



/* VA 100040b0 */

uint * __thiscall FUN_100040b0(void *this,uint param_1,undefined4 param_2,uint *param_3,int param_4)

{
  undefined2 *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  void *pvVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;

  iVar2 = *(int *)((int)this + 0x10);
  if (0x7ffffffeU - iVar2 < param_1) {
LAB_10004226:
    FUN_10001470();
  }
  else {
    uVar3 = *(uint *)((int)this + 0x14);
    uVar8 = iVar2 + param_1 | 7;
    if (uVar8 < 0x7fffffff) {
      if (0x7ffffffe - (uVar3 >> 1) < uVar3) {
        uVar8 = 0x7ffffffe;
        uVar5 = 0xfffffffe;
        goto LAB_10004131;
      }
      uVar5 = (uVar3 >> 1) + uVar3;
      if (uVar8 < uVar5) {
        uVar8 = uVar5;
      }
      if (0x7fffffff < uVar8 + 1) goto LAB_10004221;
      uVar5 = (uVar8 + 1) * 2;
      if (0xfff < uVar5) goto LAB_10004131;
      if (uVar5 == 0) {
        puVar7 = (uint *)0x0;
      }
      else {
        puVar7 = operator_new(uVar5);
      }
    }
    else {
      uVar8 = 0x7ffffffe;
      uVar5 = 0xfffffffe;
LAB_10004131:
      if (uVar5 + 0x23 <= uVar5) {
LAB_10004221:
        FUN_100013d0();
        goto LAB_10004226;
      }
      pvVar6 = operator_new(uVar5 + 0x23);
      if (pvVar6 == (void *)0x0) goto LAB_1000422b;
      puVar7 = (uint *)((int)pvVar6 + 0x23U & 0xffffffe0);
      puVar7[-1] = (uint)pvVar6;
    }
    *(uint *)((int)this + 0x10) = iVar2 + param_1;
    *(uint *)((int)this + 0x14) = uVar8;
    uVar8 = iVar2 * 2;
    puVar1 = (undefined2 *)((int)puVar7 + (param_4 + iVar2) * 2);
    if (uVar3 < 8) {
      FUN_10007600(puVar7,this,uVar8);
      FUN_10007600((uint *)(uVar8 + (int)puVar7),param_3,param_4 * 2);
      *puVar1 = 0;
      *(uint **)this = puVar7;
      return this;
    }
    puVar4 = *(uint **)this;
    FUN_10007600(puVar7,puVar4,uVar8);
    FUN_10007600((uint *)(uVar8 + (int)puVar7),param_3,param_4 * 2);
    *puVar1 = 0;
    puVar9 = puVar4;
    if ((uVar3 * 2 + 2 < 0x1000) ||
       (puVar9 = (uint *)puVar4[-1], (uint)((int)puVar4 + (-4 - (int)puVar9)) < 0x20)) {
      FUN_10004f47(puVar9);
      *(uint **)this = puVar7;
      return this;
    }
  }
LAB_1000422b:
                    /* WARNING: Subroutine does not return */
  FUN_100080b4();
}



/* VA 10004240 */

void __fastcall FUN_10004240(int param_1)

{
  if (*(LPVOID *)(param_1 + 4) != (LPVOID)0x0) {
    FUN_10004f47(*(LPVOID *)(param_1 + 4));
  }
  return;
}



/* VA 10004260 */

void * __fastcall FUN_10004260(void *param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  uint *puVar2;

  puVar2 = param_2;
  do {
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 2);
  } while ((short)uVar1 != 0);
  FUN_100042d0(param_1,param_3,param_2,(int)puVar2 - ((int)param_2 + 2) >> 1);
  return param_1;
}



/* VA 100042a0 */

void * __thiscall FUN_100042a0(void *this,undefined4 param_1)

{
  FUN_100042d0(this,param_1,(uint *)L".ini",4);
  return this;
}



/* VA 100042d0 */

uint * __thiscall FUN_100042d0(void *this,undefined4 param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  uint uVar4;

  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  if (param_3 < 0x7fffffff) {
    *(undefined4 *)((int)this + 0x14) = 7;
    if (param_3 < 8) {
      *(uint *)((int)this + 0x10) = param_3;
      FUN_10007600(this,param_2,param_3 * 2);
      *(undefined2 *)(param_3 * 2 + (int)this) = 0;
      return this;
    }
    uVar4 = param_3 | 7;
    if (uVar4 < 0x7fffffff) {
      if (uVar4 < 10) {
        uVar4 = 10;
      }
      if (uVar4 + 1 < 0x80000000) {
        uVar1 = (uVar4 + 1) * 2;
        if (uVar1 < 0x1000) {
          if (uVar1 == 0) {
            puVar3 = (uint *)0x0;
          }
          else {
            puVar3 = operator_new(uVar1);
          }
          goto LAB_100043a2;
        }
        goto LAB_10004370;
      }
    }
    else {
      uVar4 = 0x7ffffffe;
      uVar1 = 0xfffffffe;
LAB_10004370:
      if (uVar1 < uVar1 + 0x23) {
        pvVar2 = operator_new(uVar1 + 0x23);
        if (pvVar2 != (void *)0x0) {
          puVar3 = (uint *)((int)pvVar2 + 0x23U & 0xffffffe0);
          puVar3[-1] = (uint)pvVar2;
LAB_100043a2:
          *(uint *)((int)this + 0x14) = uVar4;
          *(uint **)this = puVar3;
          *(uint *)((int)this + 0x10) = param_3;
          FUN_10007600(puVar3,param_2,param_3 * 2);
          *(undefined2 *)(param_3 * 2 + (int)puVar3) = 0;
          return this;
        }
        goto LAB_100043d6;
      }
    }
    FUN_100013d0();
  }
  FUN_10001470();
LAB_100043d6:
                    /* WARNING: Subroutine does not return */
  FUN_100080b4();
}



/* VA 100043e0 */

void __fastcall FUN_100043e0(undefined4 *param_1,undefined4 *param_2,char *param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 uVar8;
  uint local_20;
  uint local_1c;
  uint local_14;
  uint local_10;

  pcVar3 = param_3 + param_4;
  uVar6 = 0;
  do {
    if (param_3 == pcVar3) {
      return;
    }
    cVar1 = *param_3;
    if (cVar1 != ' ') {
      if (cVar1 == '?') {
        uVar5 = param_1[4];
        if (uVar5 < (uint)param_1[5]) {
          param_1[4] = uVar5 + 1;
          puVar4 = param_1;
          if (0xf < (uint)param_1[5]) {
            puVar4 = (undefined4 *)*param_1;
          }
          *(undefined2 *)((int)puVar4 + uVar5) = 0;
        }
        else {
          local_10 = local_10 & 0xffffff00;
          FUN_10004720(param_1,uVar5,local_10,0);
        }
        uVar5 = param_2[4];
        if (uVar5 < (uint)param_2[5]) {
          param_2[4] = uVar5 + 1;
          puVar4 = param_2;
          if (0xf < (uint)param_2[5]) {
            puVar4 = (undefined4 *)*param_2;
          }
          *(undefined2 *)((int)puVar4 + uVar5) = 0;
        }
        else {
          local_14 = local_14 & 0xffffff00;
          uVar8 = 0;
          uVar7 = local_14;
LAB_1000452e:
          FUN_10004720(param_2,uVar5,uVar7,uVar8);
        }
      }
      else if (((('/' < cVar1) && (cVar1 < ':')) || (('@' < cVar1 && (cVar1 < 'G')))) ||
              ((byte)(cVar1 + 0x9fU) < 6)) {
        if ((byte)(cVar1 + 0xbfU) < 6) {
          bVar2 = cVar1 - 0x37;
        }
        else if ((byte)(cVar1 + 0x9fU) < 6) {
          bVar2 = cVar1 + 0xa9;
        }
        else {
          bVar2 = cVar1 - 0x30;
        }
        if ((char)(uVar6 >> 8) == '\0') {
          uVar6 = (uint)CONCAT11(1,bVar2 << 4);
        }
        else {
          uVar5 = param_1[4];
          bVar2 = (byte)uVar6 | bVar2;
          uVar6 = (uint)bVar2;
          if (uVar5 < (uint)param_1[5]) {
            param_1[4] = uVar5 + 1;
            puVar4 = param_1;
            if (0xf < (uint)param_1[5]) {
              puVar4 = (undefined4 *)*param_1;
            }
            *(byte *)((int)puVar4 + uVar5) = bVar2;
            *(undefined1 *)((int)puVar4 + uVar5 + 1) = 0;
          }
          else {
            local_1c = local_1c & 0xffffff00;
            FUN_10004720(param_1,uVar5,local_1c,bVar2);
          }
          uVar5 = param_2[4];
          if ((uint)param_2[5] <= uVar5) {
            local_20 = local_20 & 0xffffff00;
            uVar8 = 0xff;
            uVar7 = local_20;
            goto LAB_1000452e;
          }
          param_2[4] = uVar5 + 1;
          puVar4 = param_2;
          if (0xf < (uint)param_2[5]) {
            puVar4 = (undefined4 *)*param_2;
          }
          *(undefined2 *)((int)puVar4 + uVar5) = 0xff;
        }
      }
    }
    param_3 = param_3 + 1;
  } while( true );
}



/* VA 10004550 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_10004550(void *this,int param_1)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  undefined1 auStack_434 [4];
  int local_430;
  uint local_42c;
  void *local_428;
  void *local_424;
  int local_420;
  uint local_41c;
  int local_418;
  int local_414;
  int local_410 [257];
  uint local_c;

  local_c = DAT_10019008 ^ (uint)auStack_434;
  if (*(char *)((int)this + 0x3c) == '\0') {
    uVar8 = *(uint *)((int)this + 0x40);
    if ((uVar8 == 0) || (local_42c = *(int *)((int)this + 0x44), local_42c == 0)) {
      iVar3 = *(int *)(uVar8 + 0x3c) + uVar8;
      uVar8 = uVar8 + *(int *)(iVar3 + 0x2c);
      local_42c = *(int *)(iVar3 + 0x1c) + uVar8;
    }
    local_428 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
      local_428 = *(void **)this;
    }
    piVar4 = (int *)((int)this + 0x18);
    if (*(uint *)((int)this + 0x2c) < 0x10) {
      iVar3 = *(int *)((int)this + 0x28);
      local_430 = (int)piVar4;
    }
    else {
      local_430 = *piVar4;
      iVar3 = *(int *)((int)this + 0x28);
      piVar4 = (int *)*piVar4;
    }
    if (iVar3 == 0) {
LAB_100045f1:
      local_420 = -1;
    }
    else {
      iVar5 = -1;
      if (iVar3 + -1 != -1) {
        iVar5 = iVar3 + -1;
      }
      pcVar6 = (char *)((int)piVar4 + iVar5);
      cVar1 = *pcVar6;
      while (cVar1 == -1) {
        if ((int *)pcVar6 == piVar4) goto LAB_100045f1;
        pcVar6 = pcVar6 + -1;
        cVar1 = *pcVar6;
      }
      local_420 = (int)pcVar6 - (int)piVar4;
    }
    local_414 = 0;
    if (local_420 == -1) {
      local_420 = -1;
    }
    local_424 = this;
    if (local_420 == 0) {
      _memset(local_410,0,0x400);
    }
    else {
      piVar4 = local_410;
      for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar4 = local_420;
        piVar4 = piVar4 + 1;
      }
    }
    local_418 = *(int *)((int)this + 0x28);
    iVar3 = 0;
    if (0 < local_418) {
      do {
        if (local_410[*(byte *)((int)local_428 + iVar3)] < iVar3) {
          local_410[*(byte *)((int)local_428 + iVar3)] = iVar3;
        }
        iVar3 = iVar3 + 1;
        this = local_424;
      } while (iVar3 < local_418);
    }
    local_42c = local_42c - local_418;
    if (uVar8 <= local_42c) {
      local_418 = local_418 + -1;
      do {
        if (-1 < local_418) {
          pbVar7 = (byte *)(local_430 + local_418);
          local_414 = (int)local_428 - local_430;
          iVar3 = local_418;
          do {
            this = local_424;
            if (pbVar7[local_414] != (pbVar7[uVar8 - local_430] & *pbVar7)) {
              iVar5 = 1;
              if (1 < iVar3 - local_410[*(byte *)(iVar3 + uVar8)]) {
                iVar5 = iVar3 - local_410[*(byte *)(iVar3 + uVar8)];
              }
              uVar8 = uVar8 + iVar5;
              goto LAB_100046f6;
            }
            pbVar7 = pbVar7 + -1;
            iVar3 = iVar3 + -1;
          } while (-1 < iVar3);
        }
        puVar2 = *(uint **)((int)this + 0x34);
        if (puVar2 == *(uint **)((int)this + 0x38)) {
          local_41c = uVar8;
          FUN_10004860((void *)((int)this + 0x30),puVar2,&local_41c);
        }
        else {
          *puVar2 = uVar8;
          *(int *)((int)this + 0x34) = *(int *)((int)this + 0x34) + 4;
        }
        if (*(int *)((int)this + 0x34) - *(int *)((int)this + 0x30) >> 2 == param_1) break;
        uVar8 = uVar8 + 1;
LAB_100046f6:
      } while (uVar8 <= local_42c);
    }
    *(undefined1 *)((int)this + 0x3c) = 1;
  }
  return;
}



/* VA 10004720 */

uint * __thiscall FUN_10004720(void *this,undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;

  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 == 0x7fffffff) {
    FUN_10001470();
LAB_1000484b:
    FUN_100013d0();
    goto LAB_10004850;
  }
  uVar2 = *(uint *)((int)this + 0x14);
  uVar7 = uVar1 + 1 | 0xf;
  if ((uVar7 < 0x80000000) && (uVar2 <= 0x7fffffff - (uVar2 >> 1))) {
    uVar6 = uVar2 + (uVar2 >> 1);
    if (uVar7 < uVar6) {
      uVar7 = uVar6;
    }
    uVar6 = uVar7 + 1;
    if (0xfff < uVar6) {
      uVar4 = uVar7 + 0x24;
      if (uVar4 <= uVar6) goto LAB_1000484b;
      goto LAB_1000475d;
    }
    if (uVar6 == 0) {
      puVar9 = (uint *)0x0;
    }
    else {
      puVar9 = operator_new(uVar6);
    }
  }
  else {
    uVar7 = 0x7fffffff;
    uVar4 = 0x80000023;
LAB_1000475d:
    pvVar5 = operator_new(uVar4);
    if (pvVar5 == (void *)0x0) goto LAB_10004850;
    puVar9 = (uint *)((int)pvVar5 + 0x23U & 0xffffffe0);
    puVar9[-1] = (uint)pvVar5;
  }
  *(uint *)((int)this + 0x10) = uVar1 + 1;
  *(uint *)((int)this + 0x14) = uVar7;
  if (uVar2 < 0x10) {
    FUN_10007600(puVar9,this,uVar1);
    *(undefined1 *)((int)puVar9 + uVar1) = param_3;
    *(undefined1 *)((int)puVar9 + uVar1 + 1) = 0;
    *(uint **)this = puVar9;
    return this;
  }
  puVar3 = *(uint **)this;
  FUN_10007600(puVar9,puVar3,uVar1);
  *(undefined1 *)((int)puVar9 + uVar1) = param_3;
  *(undefined1 *)((int)puVar9 + uVar1 + 1) = 0;
  puVar8 = puVar3;
  if ((uVar2 + 1 < 0x1000) ||
     (puVar8 = (uint *)puVar3[-1], (uint)((int)puVar3 + (-4 - (int)puVar8)) < 0x20)) {
    FUN_10004f47(puVar8);
    *(uint **)this = puVar9;
    return this;
  }
LAB_10004850:
                    /* WARNING: Subroutine does not return */
  FUN_100080b4();
}



/* VA 10004860 */

uint * __thiscall FUN_10004860(void *this,uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  LPVOID pvVar5;
  int iVar6;
  void *pvVar7;
  LPVOID pvVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;

  iVar3 = *(int *)this;
  iVar6 = *(int *)((int)this + 4) - iVar3 >> 2;
  if (iVar6 != 0x3fffffff) {
    uVar1 = iVar6 + 1;
    uVar9 = *(int *)((int)this + 8) - iVar3 >> 2;
    if (uVar9 <= 0x3fffffff - (uVar9 >> 1)) {
      uVar9 = (uVar9 >> 1) + uVar9;
      uVar10 = uVar1;
      if (uVar1 <= uVar9) {
        uVar10 = uVar9;
      }
      if (uVar10 < 0x40000000) {
        uVar9 = uVar10 * 4;
        if (uVar9 < 0x1000) {
          if (uVar9 == 0) {
            puVar11 = (uint *)0x0;
          }
          else {
            puVar11 = operator_new(uVar9);
          }
        }
        else {
          if (uVar9 + 0x23 <= uVar9) goto LAB_100049a7;
          pvVar7 = operator_new(uVar9 + 0x23);
          if (pvVar7 == (void *)0x0) goto LAB_100049b1;
          puVar11 = (uint *)((int)pvVar7 + 0x23U & 0xffffffe0);
          puVar11[-1] = (uint)pvVar7;
        }
        puVar2 = puVar11 + ((int)param_1 - iVar3 >> 2);
        *puVar2 = *param_2;
        puVar4 = *(uint **)this;
        if (param_1 == *(uint **)((int)this + 4)) {
          FUN_10007600(puVar11,puVar4,(int)*(uint **)((int)this + 4) - (int)puVar4);
        }
        else {
          FUN_10007600(puVar11,puVar4,(int)param_1 - (int)puVar4);
          FUN_10007600(puVar2 + 1,param_1,*(int *)((int)this + 4) - (int)param_1);
        }
        pvVar5 = *(LPVOID *)this;
        if (pvVar5 == (LPVOID)0x0) {
LAB_1000498a:
          *(uint **)this = puVar11;
          *(uint **)((int)this + 4) = puVar11 + uVar1;
          *(uint **)((int)this + 8) = puVar11 + uVar10;
          return puVar2;
        }
        pvVar8 = pvVar5;
        if (((*(int *)((int)this + 8) - (int)pvVar5 & 0xfffffffcU) < 0x1000) ||
           (pvVar8 = *(LPVOID *)((int)pvVar5 + -4), (uint)((int)pvVar5 + (-4 - (int)pvVar8)) < 0x20)
           ) {
          FUN_10004f47(pvVar8);
          goto LAB_1000498a;
        }
        goto LAB_100049b1;
      }
    }
LAB_100049a7:
    FUN_100013d0();
  }
  FUN_100049c0();
LAB_100049b1:
                    /* WARNING: Subroutine does not return */
  FUN_100080b4();
}



/* VA 100049c0 */

void FUN_100049c0(void)

{
  code *pcVar1;

  FUN_10004ad9("vector too long");
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* VA 100049cb */

void __cdecl _abort(void)

{
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 100049d0 */

undefined4 * __fastcall FUN_100049d0(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[1] = "bad allocation";
  *param_1 = std::bad_alloc::vftable;
  return param_1;
}



/* VA 100049e8 */

/* Library Function - Single Match
    public: __thiscall std::exception::exception(char const * const)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

exception * __thiscall std::exception::exception(exception *this,char *param_1)

{
  char *local_c;
  undefined1 local_8;
  undefined3 uStack_7;

  local_c = param_1;
  _local_8 = CONCAT31((int3)((uint)this >> 8),1);
  *(undefined ***)this = vftable;
  *(int *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  ___std_exception_copy((int *)&local_c,(int *)(this + 4));
  return this;
}



/* VA 10004a1d */

undefined4 * __thiscall FUN_10004a1d(void *this,int param_1)

{
  FUN_10001320(this,param_1);
  *(undefined ***)this = std::length_error::vftable;
  return this;
}



/* VA 10004a38 */

exception * __thiscall FUN_10004a38(void *this,char *param_1)

{
  std::exception::exception(this,param_1);
  *(undefined ***)this = std::length_error::vftable;
  return this;
}



/* VA 10004a57 */

undefined4 * __thiscall FUN_10004a57(void *this,int param_1)

{
  FUN_10001320(this,param_1);
  *(undefined ***)this = std::logic_error::vftable;
  return this;
}



/* VA 10004a72 */

undefined4 * __thiscall FUN_10004a72(void *this,int param_1)

{
  FUN_10001320(this,param_1);
  *(undefined ***)this = std::out_of_range::vftable;
  return this;
}



/* VA 10004a8d */

exception * __thiscall FUN_10004a8d(void *this,char *param_1)

{
  std::exception::exception(this,param_1);
  *(undefined ***)this = std::out_of_range::vftable;
  return this;
}



/* VA 10004aac */

undefined4 * __thiscall FUN_10004aac(void *this,byte param_1)

{
  *(undefined ***)this = std::exception::vftable;
  ___std_exception_destroy((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    FUN_10004f47(this);
  }
  return this;
}



/* VA 10004ad9 */

void FUN_10004ad9(char *param_1)

{
  int local_10 [3];

  FUN_10004a38(local_10,param_1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_10017340);
}



/* VA 10004af9 */

void FUN_10004af9(char *param_1)

{
  int local_10 [3];

  FUN_10004a8d(local_10,param_1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_1001737c);
}



/* VA 10004b20 */

undefined1 (*) [32]
FUN_10004b20(undefined1 (*param_1) [32],undefined1 (*param_2) [32],short param_3)

{
  int iVar1;
  ushort uVar2;
  undefined1 auVar3 [32];
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [32];

  uVar6 = (int)param_2 - (int)param_1;
  if (((uVar6 & 0xffffffe0) != 0) && ((DAT_10019004 >> 5 & 1) != 0)) {
    puVar5 = *param_1;
    auVar7 = vpunpcklwd_avx(ZEXT416((uint)(int)param_3),ZEXT416((uint)(int)param_3));
    auVar7 = vpshufd_avx(auVar7,0);
    auVar8._16_16_ = auVar7;
    auVar8._0_16_ = auVar7;
    do {
      auVar3 = vpcmpeqw_avx2(auVar8,*param_1);
      uVar4 = (uint)(SUB321(auVar3 >> 7,0) & 1) | (uint)(SUB321(auVar3 >> 0xf,0) & 1) << 1 |
              (uint)(SUB321(auVar3 >> 0x17,0) & 1) << 2 | (uint)(SUB321(auVar3 >> 0x1f,0) & 1) << 3
              | (uint)(SUB321(auVar3 >> 0x27,0) & 1) << 4 |
              (uint)(SUB321(auVar3 >> 0x2f,0) & 1) << 5 | (uint)(SUB321(auVar3 >> 0x37,0) & 1) << 6
              | (uint)(SUB321(auVar3 >> 0x3f,0) & 1) << 7 |
              (uint)(SUB321(auVar3 >> 0x47,0) & 1) << 8 | (uint)(SUB321(auVar3 >> 0x4f,0) & 1) << 9
              | (uint)(SUB321(auVar3 >> 0x57,0) & 1) << 10 |
              (uint)(SUB321(auVar3 >> 0x5f,0) & 1) << 0xb |
              (uint)(SUB321(auVar3 >> 0x67,0) & 1) << 0xc |
              (uint)(SUB321(auVar3 >> 0x6f,0) & 1) << 0xd |
              (uint)(SUB321(auVar3 >> 0x77,0) & 1) << 0xe | (uint)SUB321(auVar3 >> 0x7f,0) << 0xf |
              (uint)(SUB321(auVar3 >> 0x87,0) & 1) << 0x10 |
              (uint)(SUB321(auVar3 >> 0x8f,0) & 1) << 0x11 |
              (uint)(SUB321(auVar3 >> 0x97,0) & 1) << 0x12 |
              (uint)(SUB321(auVar3 >> 0x9f,0) & 1) << 0x13 |
              (uint)(SUB321(auVar3 >> 0xa7,0) & 1) << 0x14 |
              (uint)(SUB321(auVar3 >> 0xaf,0) & 1) << 0x15 |
              (uint)(SUB321(auVar3 >> 0xb7,0) & 1) << 0x16 | (uint)SUB321(auVar3 >> 0xbf,0) << 0x17
              | (uint)(SUB321(auVar3 >> 199,0) & 1) << 0x18 |
              (uint)(SUB321(auVar3 >> 0xcf,0) & 1) << 0x19 |
              (uint)(SUB321(auVar3 >> 0xd7,0) & 1) << 0x1a |
              (uint)(SUB321(auVar3 >> 0xdf,0) & 1) << 0x1b |
              (uint)(SUB321(auVar3 >> 0xe7,0) & 1) << 0x1c |
              (uint)(SUB321(auVar3 >> 0xef,0) & 1) << 0x1d |
              (uint)(SUB321(auVar3 >> 0xf7,0) & 1) << 0x1e | (uint)(byte)(auVar3[0x1f] >> 7) << 0x1f
      ;
      if (uVar4 != 0) {
        iVar1 = 0;
        for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1 | 0x80000000) {
          iVar1 = iVar1 + 1;
        }
        return (undefined1 (*) [32])(*param_1 + iVar1);
      }
      param_1 = param_1 + 1;
    } while (param_1 != (undefined1 (*) [32])(puVar5 + (uVar6 & 0xffffffe0)));
    uVar6 = uVar6 & 0x1f;
  }
  if (((uVar6 & 0xfffffff0) != 0) && ((DAT_10019004 >> 1 & 1) != 0)) {
    puVar5 = *param_1;
    do {
      auVar7._0_2_ = -(ushort)(*(short *)*param_1 == param_3);
      auVar7._2_2_ = -(ushort)(*(short *)(*param_1 + 2) == param_3);
      auVar7._4_2_ = -(ushort)(*(short *)(*param_1 + 4) == param_3);
      auVar7._6_2_ = -(ushort)(*(short *)(*param_1 + 6) == param_3);
      auVar7._8_2_ = -(ushort)(*(short *)(*param_1 + 8) == param_3);
      auVar7._10_2_ = -(ushort)(*(short *)(*param_1 + 10) == param_3);
      auVar7._12_2_ = -(ushort)(*(short *)(*param_1 + 0xc) == param_3);
      auVar7._14_2_ = -(ushort)(*(short *)(*param_1 + 0xe) == param_3);
      uVar2 = (ushort)(SUB161(auVar7 >> 7,0) & 1) | (ushort)(SUB161(auVar7 >> 0xf,0) & 1) << 1 |
              (ushort)(SUB161(auVar7 >> 0x17,0) & 1) << 2 |
              (ushort)(SUB161(auVar7 >> 0x1f,0) & 1) << 3 |
              (ushort)(SUB161(auVar7 >> 0x27,0) & 1) << 4 |
              (ushort)(SUB161(auVar7 >> 0x2f,0) & 1) << 5 |
              (ushort)(SUB161(auVar7 >> 0x37,0) & 1) << 6 |
              (ushort)(SUB161(auVar7 >> 0x3f,0) & 1) << 7 |
              (ushort)(SUB161(auVar7 >> 0x47,0) & 1) << 8 |
              (ushort)(SUB161(auVar7 >> 0x4f,0) & 1) << 9 |
              (ushort)(SUB161(auVar7 >> 0x57,0) & 1) << 10 |
              (ushort)(SUB161(auVar7 >> 0x5f,0) & 1) << 0xb |
              (ushort)(SUB161(auVar7 >> 0x67,0) & 1) << 0xc |
              (ushort)(SUB161(auVar7 >> 0x6f,0) & 1) << 0xd |
              (ushort)((byte)(auVar7._14_2_ >> 7) & 1) << 0xe | auVar7._14_2_ & 0x8000;
      if (uVar2 != 0) {
        iVar1 = 0;
        if (uVar2 != 0) {
          for (; (uVar2 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
          }
        }
        return (undefined1 (*) [32])(*param_1 + iVar1);
      }
      param_1 = (undefined1 (*) [32])(*param_1 + 0x10);
    } while (param_1 != (undefined1 (*) [32])(puVar5 + (uVar6 & 0xfffffff0)));
  }
  for (; (param_1 != param_2 && (*(short *)*param_1 != param_3));
      param_1 = (undefined1 (*) [32])(*param_1 + 2)) {
  }
  return param_1;
}



/* VA 10004bef */

/* WARNING: This is an inlined function */

void __fastcall __security_check_cookie(uintptr_t _StackCookie)

{
  if (_StackCookie == DAT_10019008) {
    return;
  }
  FUN_100054d7();
  return;
}



/* VA 10004bfd */

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __cdecl operator_new(uint param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  void *pvVar2;
  int aiStack_10 [2];

  do {
    aiStack_10[1] = 0x10004c17;
    pvVar2 = (void *)FUN_10008235(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    bVar1 = FUN_100081b2(param_1);
  } while (CONCAT31(extraout_var,bVar1) != 0);
  if (param_1 != 0xffffffff) {
    pvVar2 = (void *)FUN_100055d1();
    return pvVar2;
  }
  FUN_100013b0(aiStack_10);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(aiStack_10,&DAT_100179e8);
}



/* VA 10004c2d */

/* Library Function - Single Match
    struct _IMAGE_SECTION_HEADER * __cdecl find_pe_section(unsigned char * const,unsigned int)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_IMAGE_SECTION_HEADER * __cdecl find_pe_section(uchar *param_1,uint param_2)

{
  int iVar1;
  _IMAGE_SECTION_HEADER *p_Var2;
  _IMAGE_SECTION_HEADER *p_Var3;

  iVar1 = *(int *)(param_1 + 0x3c);
  p_Var2 = (_IMAGE_SECTION_HEADER *)
           (param_1 + (uint)*(ushort *)(param_1 + iVar1 + 0x14) + iVar1 + 0x18);
  p_Var3 = p_Var2 + *(ushort *)(param_1 + iVar1 + 6);
  while( true ) {
    if (p_Var2 == p_Var3) {
      return (_IMAGE_SECTION_HEADER *)0x0;
    }
    if ((p_Var2->VirtualAddress <= param_2) &&
       (param_2 < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) break;
    p_Var2 = p_Var2 + 1;
  }
  return p_Var2;
}



/* VA 10004c71 */

/* Library Function - Single Match
    ___scrt_acquire_startup_lock

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 ___scrt_acquire_startup_lock(void)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;

  bVar2 = ___scrt_is_ucrt_dll_in_use();
  if (CONCAT31(extraout_var,bVar2) != 0) {
    while( true ) {
      iVar3 = 0;
      LOCK();
      iVar1 = *(int *)((int)Self + 4);
      if (DAT_100199a4 != 0) {
        iVar3 = DAT_100199a4;
        iVar1 = DAT_100199a4;
      }
      DAT_100199a4 = iVar1;
      UNLOCK();
      if (iVar3 == 0) break;
      if (*(int *)((int)Self + 4) == iVar3) {
        return CONCAT31((int3)((uint)iVar3 >> 8),1);
      }
    }
  }
  return 0;
}



/* VA 10004ca3 */

/* Library Function - Single Match
    ___scrt_dllmain_after_initialize_c

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 ___scrt_dllmain_after_initialize_c(void)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;

  bVar1 = ___scrt_is_ucrt_dll_in_use();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar3 = FUN_100055ee();
    uVar4 = FUN_100089bb(iVar3);
    if (uVar4 != 0) {
      return uVar4 & 0xffffff00;
    }
    uVar2 = thunk_FUN_100089c6();
  }
  else {
    uVar2 = FUN_100052db();
  }
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}



/* VA 10004cce */

bool FUN_10004cce(void)

{
  undefined4 uVar1;

  uVar1 = FUN_10004da5(0);
  return (char)uVar1 != '\0';
}



/* VA 10004cdc */

/* Library Function - Single Match
    ___scrt_dllmain_crt_thread_attach

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined1 ___scrt_dllmain_crt_thread_attach(void)

{
  bool bVar1;

  bVar1 = ___vcrt_thread_attach();
  if (bVar1) {
    bVar1 = FUN_1000902e();
    if (bVar1) {
      return 1;
    }
    ___vcrt_thread_detach();
  }
  return 0;
}



/* VA 10004cfb */

/* Library Function - Single Match
    ___scrt_dllmain_crt_thread_detach

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined1 ___scrt_dllmain_crt_thread_detach(void)

{
  FUN_10009039();
  ___vcrt_thread_detach();
  return 1;
}



/* VA 10004d08 */

/* Library Function - Single Match
    ___scrt_dllmain_exception_filter

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
___scrt_dllmain_exception_filter
          (undefined4 param_1,int param_2,undefined4 param_3,undefined *param_4,int param_5,
          undefined4 param_6)

{
  bool bVar1;
  undefined3 extraout_var;

  bVar1 = ___scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) == 0) && (param_2 == 1)) {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1,0,param_3);
    (*(code *)param_4)();
  }
  __seh_filter_dll(param_5,param_6);
  return;
}



/* VA 10004d3c */

void FUN_10004d3c(void)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;

  bVar1 = ___scrt_is_ucrt_dll_in_use();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_10008e84();
    return;
  }
  iVar2 = FUN_100086b4();
  if (iVar2 != 0) {
    return;
  }
  FUN_100084db(0,0,1);
  return;
}



/* VA 10004d5f */

void FUN_10004d5f(void)

{
  ___acrt_uninitialize_critical();
  FUN_10005f56();
  return;
}



/* VA 10004d6c */

/* Library Function - Single Match
    ___scrt_initialize_crt

   Library: Visual Studio 2019 Release */

uint __cdecl ___scrt_initialize_crt(int param_1)

{
  uint uVar1;
  undefined4 uVar2;

  if (param_1 == 0) {
    DAT_100199a8 = 1;
  }
  FUN_100052db();
  uVar1 = ___vcrt_initialize();
  if ((char)uVar1 != '\0') {
    uVar2 = ___acrt_initialize();
    if ((char)uVar2 != '\0') {
      return CONCAT31((int3)((uint)uVar2 >> 8),1);
    }
    uVar1 = ___vcrt_uninitialize('\0');
  }
  return uVar1 & 0xffffff00;
}



/* VA 10004da5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10004da5(int param_1)

{
  bool bVar1;
  undefined4 in_EAX;
  undefined3 extraout_var;
  uint uVar3;
  int iVar2;

  if (DAT_100199a9 != '\0') {
    return CONCAT31((int3)((uint)in_EAX >> 8),1);
  }
  if ((param_1 != 0) && (param_1 != 1)) {
                    /* WARNING: Subroutine does not return */
    FUN_100055fe();
  }
  bVar1 = ___scrt_is_ucrt_dll_in_use();
  iVar2 = CONCAT31(extraout_var,bVar1);
  if ((iVar2 == 0) || (param_1 != 0)) {
    DAT_100199ac = 0xffffffff;
    _DAT_100199b0 = 0xffffffff;
    _DAT_100199b4 = 0xffffffff;
    _DAT_100199b8 = 0xffffffff;
    _DAT_100199bc = 0xffffffff;
    _DAT_100199c0 = 0xffffffff;
LAB_10004e18:
    DAT_100199a9 = '\x01';
    uVar3 = CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  else {
    uVar3 = __initialize_onexit_table(&DAT_100199ac);
    if (uVar3 == 0) {
      uVar3 = __initialize_onexit_table((int *)&DAT_100199b8);
      iVar2 = 0;
      if (uVar3 == 0) goto LAB_10004e18;
    }
    uVar3 = uVar3 & 0xffffff00;
  }
  return uVar3;
}



/* VA 10004e2c */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    ___scrt_is_nonwritable_in_current_image

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint __cdecl ___scrt_is_nonwritable_in_current_image(int param_1)

{
  _IMAGE_SECTION_HEADER *p_Var1;
  void *local_14;

  p_Var1 = (_IMAGE_SECTION_HEADER *)0x5a4d;
  if ((((IMAGE_DOS_HEADER_10000000.e_magic == (char  [2])0x5a4d) &&
       (p_Var1 = (_IMAGE_SECTION_HEADER *)IMAGE_DOS_HEADER_10000000.e_lfanew,
       *(int *)(IMAGE_DOS_HEADER_10000000.e_lfanew + 0x10000000) == 0x4550)) &&
      (*(short *)((int)IMAGE_DOS_HEADER_10000000.e_res_4_ + (IMAGE_DOS_HEADER_10000000.e_lfanew - 4)
                 ) == 0x10b)) &&
     ((p_Var1 = find_pe_section((uchar *)&IMAGE_DOS_HEADER_10000000,param_1 + 0xf0000000),
      p_Var1 != (_IMAGE_SECTION_HEADER *)0x0 && (-1 < (int)p_Var1->Characteristics)))) {
    ExceptionList = local_14;
    return CONCAT31((int3)((uint)p_Var1 >> 8),1);
  }
  ExceptionList = local_14;
  return (uint)p_Var1 & 0xffffff00;
}



/* VA 10004ec0 */

/* Library Function - Single Match
    ___scrt_release_startup_lock

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl ___scrt_release_startup_lock(char param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;

  bVar2 = ___scrt_is_ucrt_dll_in_use();
  iVar1 = DAT_100199a4;
  iVar3 = CONCAT31(extraout_var,bVar2);
  if ((iVar3 != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_100199a4 = 0;
    UNLOCK();
    iVar3 = iVar1;
  }
  return iVar3;
}



/* VA 10004edd */

/* Library Function - Single Match
    ___scrt_uninitialize_crt

   Library: Visual Studio 2019 Release */

undefined4 __cdecl ___scrt_uninitialize_crt(char param_1,char param_2)

{
  undefined4 in_EAX;

  if ((DAT_100199a8 == '\0') || (param_2 == '\0')) {
    ___acrt_uninitialize(param_1);
    in_EAX = ___vcrt_uninitialize(param_1);
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



/* VA 10004f05 */

/* Library Function - Single Match
    __onexit

   Library: Visual Studio 2019 Release */

_onexit_t __cdecl __onexit(_onexit_t _Func)

{
  int iVar1;

  if (DAT_100199ac == -1) {
    iVar1 = __crt_atexit();
  }
  else {
    iVar1 = __register_onexit_function();
  }
  return (_onexit_t)(~-(uint)(iVar1 != 0) & (uint)_Func);
}



/* VA 10004f32 */

/* Library Function - Single Match
    _atexit

   Library: Visual Studio 2019 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;

  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



/* VA 10004f47 */

void __cdecl FUN_10004f47(LPVOID param_1)

{
  thunk_FUN_10009118(param_1);
  return;
}



/* VA 10004f55 */

undefined4 * __thiscall FUN_10004f55(void *this,byte param_1)

{
  *(undefined ***)this = type_info::vftable;
  if ((param_1 & 1) != 0) {
    FUN_10004f47(this);
  }
  return this;
}



/* VA 10004f78 */

/* Library Function - Single Match
    int __stdcall dllmain_crt_dispatch(struct HINSTANCE__ * const,unsigned long,void * const)

   Library: Visual Studio 2019 Release */

int dllmain_crt_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  byte bVar1;
  uint uVar2;
  undefined3 extraout_var;

  if (param_2 == 0) {
    bVar1 = FUN_100050d2(param_3 != (void *)0x0);
    uVar2 = CONCAT31(extraout_var,bVar1);
  }
  else if (param_2 == 1) {
    uVar2 = FUN_10004fcb(param_1,param_3);
  }
  else {
    if (param_2 == 2) {
      bVar1 = ___scrt_dllmain_crt_thread_attach();
    }
    else {
      if (param_2 != 3) {
        return 1;
      }
      bVar1 = ___scrt_dllmain_crt_thread_detach();
    }
    uVar2 = (uint)bVar1;
  }
  return uVar2;
}



/* VA 10004fcb */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

undefined4 __cdecl FUN_10004fcb(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  void *local_14;

  uVar4 = ___scrt_initialize_crt(0);
  if ((char)uVar4 != '\0') {
    ___scrt_acquire_startup_lock();
    bVar2 = true;
    if (DAT_100199a0 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100055fe();
    }
    DAT_100199a0 = 1;
    bVar3 = FUN_10004cce();
    if (bVar3) {
      FUN_10005862();
      FUN_1000581b();
      FUN_1000583f();
      iVar5 = __initterm_e((undefined4 *)&DAT_10011180,(undefined4 *)&DAT_10011190);
      if ((iVar5 == 0) && (uVar4 = ___scrt_dllmain_after_initialize_c(), (char)uVar4 != '\0')) {
        FUN_10009083((undefined4 *)&DAT_10011174,(undefined4 *)&DAT_1001117c);
        DAT_100199a0 = 2;
        bVar2 = false;
      }
    }
    FUN_100050ae();
    if (!bVar2) {
      piVar6 = (int *)FUN_1000585c();
      if ((*piVar6 != 0) &&
         (uVar4 = ___scrt_is_nonwritable_in_current_image((int)piVar6), (char)uVar4 != '\0')) {
        pcVar1 = (code *)*piVar6;
        (*(code *)PTR_guard_check_icall_1001116c)(param_1,2,param_2);
        (*pcVar1)();
      }
      DAT_100199c4 = DAT_100199c4 + 1;
      ExceptionList = local_14;
      return 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* VA 100050ae */

void FUN_100050ae(void)

{
  int unaff_EBP;

  ___scrt_release_startup_lock((char)*(undefined4 *)(unaff_EBP + -0x1d));
  return;
}



/* VA 100050d2 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

byte __cdecl FUN_100050d2(char param_1)

{
  uint uVar1;
  byte bVar2;
  undefined4 local_14;

  if (DAT_100199c4 < 1) {
    bVar2 = 0;
  }
  else {
    DAT_100199c4 = DAT_100199c4 + -1;
    ___scrt_acquire_startup_lock();
    if (DAT_100199a0 != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_100055fe();
    }
    FUN_10004d3c();
    __scrt_uninitialize_type_info();
    FUN_1000588e();
    DAT_100199a0 = 0;
    FUN_10005167();
    uVar1 = ___scrt_uninitialize_crt(param_1,'\0');
    bVar2 = -((uVar1 & 0xff) != 0) & 1;
    FUN_10005174();
  }
  ExceptionList = local_14;
  return bVar2;
}



/* VA 10005167 */

void FUN_10005167(void)

{
  int unaff_EBP;

  ___scrt_release_startup_lock((char)*(undefined4 *)(unaff_EBP + -0x20));
  return;
}



/* VA 10005174 */

void FUN_10005174(void)

{
  FUN_10004d5f();
  return;
}



/* VA 10005182 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    int __cdecl dllmain_dispatch(struct HINSTANCE__ * const,unsigned long,void * const)

   Library: Visual Studio 2019 Release */

int __cdecl dllmain_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  void *local_14;

  if ((param_2 == 0) && (DAT_100199c4 < 1)) {
    ExceptionList = local_14;
    return 0;
  }
  if ((param_2 == 1) || (param_2 == 2)) {
    iVar1 = dllmain_raw(param_1,param_2,param_3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    iVar1 = dllmain_crt_dispatch(param_1,param_2,param_3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return 0;
    }
  }
  iVar1 = FUN_10005815();
  if ((param_2 == 1) && (iVar1 == 0)) {
    FUN_10005815();
    FUN_100050d2(param_3 != (void *)0x0);
    dllmain_raw(param_1,0,param_3);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar2 = dllmain_crt_dispatch(param_1,param_2,param_3);
    iVar1 = 0;
    if (iVar2 != 0) {
      iVar1 = dllmain_raw(param_1,param_2,param_3);
    }
  }
  ExceptionList = local_14;
  return iVar1;
}



/* VA 1000528d */

/* Library Function - Single Match
    int __stdcall dllmain_raw(struct HINSTANCE__ * const,unsigned long,void * const)

   Library: Visual Studio 2019 Release */

int dllmain_raw(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  undefined *puVar1;
  int iVar2;

  puVar1 = PTR_10011214;
  if (PTR_10011214 == (undefined *)0x0) {
    iVar2 = 1;
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1,param_2,param_3);
    iVar2 = (*(code *)puVar1)();
  }
  return iVar2;
}



/* VA 100052b8 */

void entry(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  if (param_2 == 1) {
    ___security_init_cookie();
  }
  dllmain_dispatch(param_1,param_2,param_3);
  return;
}



/* VA 100052db */

/* WARNING: Removing unreachable block (ram,0x1000534a) */
/* WARNING: Removing unreachable block (ram,0x1000530e) */
/* WARNING: Removing unreachable block (ram,0x100053c2) */

undefined4 FUN_100052db(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined8 uVar4;
  BOOL BVar5;
  uint uVar6;
  uint uVar7;
  uint in_XCR0;
  uint local_18;
  uint local_14;

  DAT_100199c8 = 0;
  DAT_10019004 = DAT_10019004 | 1;
  BVar5 = IsProcessorFeaturePresent(10);
  uVar6 = DAT_10019004;
  if (BVar5 != 0) {
    piVar1 = (int *)cpuid_basic_info(0);
    puVar2 = (uint *)cpuid_Version_info(1);
    uVar7 = puVar2[3];
    if (((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) &&
       (((((uVar6 = *puVar2 & 0xfff3ff0, uVar6 == 0x106c0 || (uVar6 == 0x20660)) ||
          (uVar6 == 0x20670)) || ((uVar6 == 0x30650 || (uVar6 == 0x30660)))) || (uVar6 == 0x30670)))
       ) {
      DAT_100199cc = DAT_100199cc | 1;
    }
    if (*piVar1 < 7) {
      local_14 = 0;
    }
    else {
      iVar3 = cpuid_Extended_Feature_Enumeration_info(7);
      local_14 = *(uint *)(iVar3 + 4);
      if ((local_14 & 0x200) != 0) {
        DAT_100199cc = DAT_100199cc | 2;
      }
    }
    DAT_100199c8 = 1;
    uVar6 = DAT_10019004 | 2;
    if ((uVar7 & 0x100000) != 0) {
      uVar6 = DAT_10019004 | 6;
      DAT_100199c8 = 2;
      if (((uVar7 & 0x8000000) != 0) && ((uVar7 & 0x10000000) != 0)) {
        uVar4 = xinuse(0);
        local_18 = in_XCR0 & (uint)uVar4;
        if ((local_18 & 6) == 6) {
          DAT_100199c8 = 3;
          uVar6 = DAT_10019004 | 0xe;
          if ((local_14 & 0x20) != 0) {
            DAT_100199c8 = 5;
            uVar6 = DAT_10019004 | 0x2e;
            if (((local_14 & 0xd0030000) == 0xd0030000) && ((local_18 & 0xe0) == 0xe0)) {
              DAT_10019004 = DAT_10019004 | 0x6e;
              DAT_100199c8 = 6;
              uVar6 = DAT_10019004;
            }
          }
        }
      }
    }
  }
  DAT_10019004 = uVar6;
  return 0;
}



/* VA 100054af */

void __cdecl FUN_100054af(_EXCEPTION_POINTERS *param_1)

{
  HANDLE hProcess;
  UINT uExitCode;

  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



/* VA 100054d7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100054d7(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  uint extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  longlong lVar9;
  undefined4 unaff_retaddr;

  uVar2 = IsProcessorFeaturePresent(0x17);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  lVar9 = (ulonglong)extraout_EDX << 0x20;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    lVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_10019ac8 = (undefined4)((ulonglong)lVar9 >> 0x20);
  _DAT_10019ad0 = (undefined4)lVar9;
  _DAT_10019ae0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_10019ae4 = &stack0x00000004;
  _DAT_10019a20 = 0x10001;
  _DAT_100199d0 = 0xc0000409;
  _DAT_100199d4 = 1;
  _DAT_100199e0 = 1;
  DAT_100199e4 = 2;
  _DAT_100199dc = unaff_retaddr;
  _DAT_10019aac = in_GS;
  _DAT_10019ab0 = in_FS;
  _DAT_10019ab4 = in_ES;
  _DAT_10019ab8 = in_DS;
  _DAT_10019abc = unaff_EDI;
  _DAT_10019ac0 = unaff_ESI;
  _DAT_10019ac4 = unaff_EBX;
  _DAT_10019acc = uVar3;
  _DAT_10019ad4 = unaff_EBP;
  DAT_10019ad8 = unaff_retaddr;
  _DAT_10019adc = in_CS;
  _DAT_10019ae8 = in_SS;
  FUN_100054af((_EXCEPTION_POINTERS *)&PTR_DAT_10011218);
  return;
}



/* VA 100055d1 */

void FUN_100055d1(void)

{
  int local_10 [3];

  FUN_100049d0(local_10);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_10017308);
}



/* VA 100055ee */

undefined4 FUN_100055ee(void)

{
  return 1;
}



/* VA 100055f2 */

/* Library Function - Single Match
    ___scrt_is_ucrt_dll_in_use

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool ___scrt_is_ucrt_dll_in_use(void)

{
  return DAT_1001a408 != 0;
}



/* VA 100055fe */

void FUN_100055fe(void)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  undefined4 local_328 [39];
  EXCEPTION_RECORD local_5c;
  _EXCEPTION_POINTERS local_c;

  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  FUN_10005719();
  _memset(local_328,0,0x2cc);
  local_328[0] = 0x10001;
  _memset(&local_5c,0,0x50);
  local_5c.ExceptionCode = 0x40000015;
  local_5c.ExceptionFlags = 1;
  BVar2 = IsDebuggerPresent();
  local_c.ExceptionRecord = &local_5c;
  local_c.ContextRecord = (PCONTEXT)local_328;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  LVar3 = UnhandledExceptionFilter(&local_c);
  if ((LVar3 == 0) && (BVar2 != 1)) {
    FUN_10005719();
  }
  return;
}



/* VA 10005719 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10005719(void)

{
  _DAT_10019cec = 0;
  return;
}



/* VA 10005730 */

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_2 */
/* Library Function - Single Match
    __SEH_prolog4

   Library: Visual Studio */

void __cdecl __SEH_prolog4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];

  iVar1 = -param_2;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + iVar1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10019008 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



/* VA 10005775 */

/* guard_check_icall */

void __cdecl guard_check_icall(void)

{
  return;
}



/* VA 10005778 */

void __cdecl thunk_FUN_10009118(LPVOID param_1)

{
  FUN_10009f36(param_1);
  return;
}



/* VA 1000577d */

/* Library Function - Single Match
    ___get_entropy

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint ___get_entropy(void)

{
  DWORD DVar1;
  LARGE_INTEGER local_18;
  _FILETIME local_10;
  uint local_8;

  local_10.dwLowDateTime = 0;
  local_10.dwHighDateTime = 0;
  GetSystemTimeAsFileTime(&local_10);
  local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
  DVar1 = GetCurrentThreadId();
  local_8 = local_8 ^ DVar1;
  DVar1 = GetCurrentProcessId();
  local_8 = local_8 ^ DVar1;
  QueryPerformanceCounter(&local_18);
  return local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
}



/* VA 100057ca */

/* Library Function - Single Match
    ___security_init_cookie

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___security_init_cookie(void)

{
  if ((DAT_10019008 == 0xbb40e64e) || ((DAT_10019008 & 0xffff0000) == 0)) {
    DAT_10019008 = ___get_entropy();
    if (DAT_10019008 == 0xbb40e64e) {
      DAT_10019008 = 0xbb40e64f;
    }
    else if ((DAT_10019008 & 0xffff0000) == 0) {
      DAT_10019008 = DAT_10019008 | (DAT_10019008 | 0x4711) << 0x10;
    }
  }
  DAT_1001900c = ~DAT_10019008;
  return;
}



/* VA 10005815 */

undefined4 FUN_10005815(void)

{
  return 1;
}



/* VA 1000581b */

void FUN_1000581b(void)

{
  InitializeSListHead((PSLIST_HEADER)&DAT_10019cf0);
  return;
}



/* VA 10005827 */

/* Library Function - Single Match
    void __cdecl __scrt_uninitialize_type_info(void)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __scrt_uninitialize_type_info(void)

{
  ___std_type_info_destroy_list((PSLIST_HEADER)&DAT_10019cf0);
  return;
}



/* VA 10005833 */

undefined * FUN_10005833(void)

{
  return &DAT_10019cf8;
}



/* VA 10005839 */

undefined * FUN_10005839(void)

{
  return &DAT_10019d00;
}



/* VA 1000583f */

void FUN_1000583f(void)

{
  uint *puVar1;

  puVar1 = (uint *)FUN_10005833();
  *puVar1 = *puVar1 | 0x24;
  puVar1[1] = puVar1[1];
  puVar1 = (uint *)FUN_10005839();
  *puVar1 = *puVar1 | 2;
  puVar1[1] = puVar1[1];
  return;
}



/* VA 1000585c */

undefined * FUN_1000585c(void)

{
  return &DAT_1001a404;
}



/* VA 10005862 */

/* WARNING: Removing unreachable block (ram,0x10005872) */
/* WARNING: Removing unreachable block (ram,0x10005873) */
/* WARNING: Removing unreachable block (ram,0x10005879) */
/* WARNING: Removing unreachable block (ram,0x10005883) */
/* WARNING: Removing unreachable block (ram,0x1000588a) */

void FUN_10005862(void)

{
  return;
}



/* VA 1000588e */

/* WARNING: Removing unreachable block (ram,0x1000589e) */
/* WARNING: Removing unreachable block (ram,0x1000589f) */
/* WARNING: Removing unreachable block (ram,0x100058a5) */
/* WARNING: Removing unreachable block (ram,0x100058af) */
/* WARNING: Removing unreachable block (ram,0x100058b6) */

void FUN_1000588e(void)

{
  return;
}



/* VA 100058ba */

void __cdecl
FUN_100058ba(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            int param_6)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint local_8;

  uVar1 = *(uint *)(param_5 + 0xc);
  uVar3 = uVar1;
  uVar4 = uVar1;
  if (-1 < param_6) {
    piVar2 = (int *)(uVar1 * 0x14 + *(int *)(param_5 + 0x10) + 8);
    local_8 = uVar1;
    do {
      if (uVar3 == 0xffffffff) goto LAB_10005924;
      uVar3 = uVar3 - 1;
      if (((piVar2[-6] < param_3) && (param_3 <= piVar2[-5])) || (uVar3 == 0xffffffff)) {
        param_6 = param_6 + -1;
        uVar4 = local_8;
        local_8 = uVar3;
      }
      piVar2 = piVar2 + -5;
    } while (-1 < param_6);
  }
  if ((uVar4 <= uVar1) && (uVar3 + 1 <= uVar4)) {
    param_1[3] = uVar4;
    *param_1 = param_2;
    param_1[1] = uVar3 + 1;
    param_1[2] = param_2;
    return;
  }
LAB_10005924:
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 1000592a */

undefined4 __cdecl
FUN_1000592a(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_1c;
  code *local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_14 = (uint)&local_1c ^ DAT_10019008;
  local_10 = param_2;
  local_8 = param_4 + 1;
  local_18 = FUN_10005b00;
  local_c = param_1;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_1c;
  return uVar1;
}



/* VA 10005987 */

undefined4 __cdecl
FUN_10005987(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *local_44;
  code *local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined1 *local_24;
  int local_20;
  int *local_1c;
  undefined4 local_18;
  code *local_14;
  undefined *local_10;
  undefined4 local_c;
  code *local_8;

  local_24 = &stack0xfffffffc;
  local_28 = &stack0xffffffb8;
  if (param_1 == (int *)0x123) {
    *param_2 = 0x10005a51;
    local_c = 1;
  }
  else {
    local_40 = FID_conflict_TranslatorGuardHandler;
    local_3c = DAT_10019008 ^ (uint)&local_44;
    local_38 = param_5;
    local_34 = param_2;
    local_30 = param_6;
    local_2c = param_7;
    local_20 = 0;
    local_44 = ExceptionList;
    ExceptionList = &local_44;
    iVar1 = __filter_x86_sse2_floating_point_exception_default(*param_1);
    *param_1 = iVar1;
    local_c = 1;
    local_1c = param_1;
    local_18 = param_3;
    iVar1 = ___vcrt_getptd();
    local_8 = *(code **)(iVar1 + 8);
    local_10 = PTR_guard_check_icall_1001116c;
    (*(code *)PTR_guard_check_icall_1001116c)();
    local_14 = local_8;
    (*local_8)(*param_1,&local_1c);
    local_c = 0;
    if (local_20 != 0) {
      *local_44 = *(undefined4 *)ExceptionList;
    }
    ExceptionList = local_44;
  }
  return local_c;
}



/* VA 10005a7d */

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x10005aa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}



/* VA 10005aad */

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  void *pvVar1;

  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x10005ad7,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}



/* VA 10005b00 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl FUN_10005b00(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3)

{
  FUN_10006cbb(param_1,*(EHRegistrationNode **)(param_2 + 0x10),param_3,(void *)0x0,
               *(_s_FuncInfo **)(param_2 + 0xc),*(int *)(param_2 + 0x14),param_2,'\0');
  return;
}



/* VA 10005b31 */

/* Library Function - Single Match
    __CreateFrameInfo

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 * __cdecl __CreateFrameInfo(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;

  *param_1 = param_2;
  iVar1 = ___vcrt_getptd();
  param_1[1] = *(undefined4 *)(iVar1 + 0x24);
  iVar1 = ___vcrt_getptd();
  *(undefined4 **)(iVar1 + 0x24) = param_1;
  return param_1;
}



/* VA 10005b55 */

void __cdecl FUN_10005b55(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;

  iVar2 = ___vcrt_getptd();
  if (param_1 == *(int *)(iVar2 + 0x24)) {
    uVar1 = *(undefined4 *)(param_1 + 4);
    iVar2 = ___vcrt_getptd();
    *(undefined4 *)(iVar2 + 0x24) = uVar1;
  }
  else {
    iVar2 = ___vcrt_getptd();
    iVar2 = *(int *)(iVar2 + 0x24);
    do {
      piVar3 = (int *)(iVar2 + 4);
      iVar2 = *piVar3;
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        _abort();
      }
    } while (param_1 != iVar2);
    *piVar3 = *(int *)(param_1 + 4);
  }
  return;
}



/* VA 10005b9d */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Different Base Names
    enum _EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(struct EHExceptionRecord *,struct
   TranslatorGuardRN *,void *,void *)
    __TranslatorGuardHandler

   Libraries: Visual Studio 2012 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __cdecl
FID_conflict_TranslatorGuardHandler
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3)

{
  undefined4 uVar1;
  code *local_8;

  if ((*(uint *)(param_1 + 4) & 0x66) != 0) {
    *(undefined4 *)(param_2 + 0x24) = 1;
    return 1;
  }
  FUN_10006cbb(param_1,*(EHRegistrationNode **)(param_2 + 0x10),param_3,(void *)0x0,
               *(_s_FuncInfo **)(param_2 + 0xc),*(int *)(param_2 + 0x14),
               *(EHRegistrationNode **)(param_2 + 0x18),'\x01');
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames(param_2,param_1);
  }
  FUN_10005987((int *)0x123,&local_8,0,0,0,0,0);
                    /* WARNING: Could not recover jumptable at 0x10005c32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*local_8)();
  return uVar1;
}



/* VA 10005c3a */

/* Library Function - Multiple Matches With Different Base Names
    ___CxxFrameHandler
    ___CxxFrameHandler2
    ___CxxFrameHandler3

   Library: Visual Studio */

undefined4 __cdecl
FID_conflict____CxxFrameHandler3
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4)

{
  _s_FuncInfo *in_EAX;
  undefined4 uVar1;

  uVar1 = FUN_10006cbb(param_1,param_2,param_3,param_4,in_EAX,0,(EHRegistrationNode *)0x0,'\0');
  return uVar1;
}



/* VA 10005c70 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    ___DestructExceptionObject

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___DestructExceptionObject(int *param_1)

{
  byte *pbVar1;
  int *piVar2;
  code *pcVar3;
  void *local_14;

  if ((((param_1 != (int *)0x0) && (*param_1 == -0x1f928c9d)) && (param_1[4] == 3)) &&
     ((((param_1[5] == 0x19930520 || (param_1[5] == 0x19930521)) || (param_1[5] == 0x19930522)) &&
      (pbVar1 = (byte *)param_1[7], pbVar1 != (byte *)0x0)))) {
    if (*(void **)(pbVar1 + 4) == (void *)0x0) {
      if (((*pbVar1 & 0x10) != 0) && (piVar2 = *(int **)param_1[6], piVar2 != (int *)0x0)) {
        pcVar3 = *(code **)(*piVar2 + 8);
        (*(code *)PTR_guard_check_icall_1001116c)(piVar2);
        (*pcVar3)();
      }
    }
    else {
      _CallMemberFunction0((void *)param_1[6],*(void **)(pbVar1 + 4));
    }
  }
  ExceptionList = local_14;
  return;
}



/* VA 10005d11 */

/* Library Function - Single Match
    void __stdcall _CallMemberFunction0(void * const,void * const)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _CallMemberFunction0(void *param_1,void *param_2)

{
  (*param_2)();
  return;
}



/* VA 10005d1e */

undefined4 __cdecl FUN_10005d1e(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;

  if ((((param_2 != '\0') && (piVar1 = (int *)*param_1, *piVar1 == -0x1f928c9d)) && (piVar1[4] == 3)
      ) && (((piVar1[5] == 0x19930520 || (piVar1[5] == 0x19930521)) || (piVar1[5] == 0x19930522))))
  {
    iVar2 = ___vcrt_getptd();
    *(int **)(iVar2 + 0x10) = piVar1;
    iVar2 = param_1[1];
    iVar3 = ___vcrt_getptd();
    *(int *)(iVar3 + 0x14) = iVar2;
                    /* WARNING: Subroutine does not return */
    FUN_100090dc();
  }
  return 0;
}



/* VA 10005d76 */

/* Library Function - Single Match
    __IsExceptionObjectToBeDestroyed

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __cdecl __IsExceptionObjectToBeDestroyed(int param_1)

{
  int *piVar1;
  int iVar2;

  iVar2 = ___vcrt_getptd();
  piVar1 = *(int **)(iVar2 + 0x24);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 1;
    }
    if (*piVar1 == param_1) break;
    piVar1 = (int *)piVar1[1];
  }
  return 0;
}



/* VA 10005d9c */

/* Library Function - Single Match
    ___AdjustPointer

   Library: Visual Studio 2019 Release */

int __cdecl ___AdjustPointer(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;

  iVar1 = param_2[1];
  iVar2 = *param_2 + param_1;
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(iVar1 + param_1) + param_2[2]) + iVar1;
  }
  return iVar2;
}



/* VA 10005dc1 */

undefined4 __cdecl FUN_10005dc1(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;

  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1fbcbcae) || (*piVar1 == -0x1fbcb0b3)) {
    iVar3 = ___vcrt_getptd();
    if (0 < *(int *)(iVar3 + 0x18)) {
      iVar3 = ___vcrt_getptd();
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -1;
    }
  }
  else if (*piVar1 == -0x1f928c9d) {
    iVar3 = ___vcrt_getptd();
    *(int **)(iVar3 + 0x10) = piVar1;
    uVar2 = param_1[1];
    iVar3 = ___vcrt_getptd();
    *(undefined4 *)(iVar3 + 0x14) = uVar2;
                    /* WARNING: Subroutine does not return */
    FUN_100090dc();
  }
  return 0;
}



/* VA 10005e17 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

void Unwind_10005e17(void)

{
  code *pcVar1;
  __acrt_ptd *p_Var2;

  p_Var2 = FUN_10009958();
  pcVar1 = *(code **)(p_Var2 + 0xc);
  if (pcVar1 != (code *)0x0) {
    (*(code *)PTR_guard_check_icall_1001116c)();
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 10005e1c */

/* Library Function - Single Match
    ___std_exception_copy

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___std_exception_copy(int *param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;

  if (((char)param_1[1] == '\0') || (pcVar4 = (char *)*param_1, pcVar4 == (char *)0x0)) {
    *param_2 = *param_1;
    *(undefined1 *)(param_2 + 1) = 0;
  }
  else {
    pcVar1 = pcVar4 + 1;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    pcVar3 = (char *)FUN_10008235((SIZE_T)(pcVar4 + (1 - (int)pcVar1)));
    if (pcVar3 != (char *)0x0) {
      FUN_10009133(pcVar3,(int)(pcVar4 + (1 - (int)pcVar1)),*param_1);
      *param_2 = (int)pcVar3;
      *(undefined1 *)(param_2 + 1) = 1;
    }
    FUN_10009118((LPVOID)0x0);
  }
  return;
}



/* VA 10005e7f */

/* Library Function - Single Match
    ___std_exception_destroy

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___std_exception_destroy(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_10009118((LPVOID)*param_1);
  }
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



/* VA 10005e9e */

/* Library Function - Single Match
    __CxxThrowException@8

   Library: Visual Studio 2019 Release */

void __CxxThrowException_8(int *param_1,byte *param_2)

{
  int iVar1;
  code *pcVar2;
  ULONG_PTR UVar3;
  ULONG_PTR local_10;
  int *local_c;
  byte *local_8;

  UVar3 = 0x19930520;
  if (param_2 != (byte *)0x0) {
    if ((*param_2 & 0x10) != 0) {
      iVar1 = *(int *)(*param_1 + -4);
      pcVar2 = *(code **)(iVar1 + 0x20);
      param_2 = *(byte **)(iVar1 + 0x18);
      (*(code *)PTR_guard_check_icall_1001116c)((int *)(*param_1 + -4));
      (*pcVar2)();
      if (param_2 == (byte *)0x0) goto LAB_10005ee5;
    }
    if ((*param_2 & 8) != 0) {
      UVar3 = 0x1994000;
    }
  }
LAB_10005ee5:
  local_c = param_1;
  local_10 = UVar3;
  local_8 = param_2;
  RaiseException(0xe06d7363,1,3,&local_10);
  return;
}



/* VA 10005f0a */

/* Library Function - Single Match
    ___vcrt_initialize

   Library: Visual Studio 2019 Release */

uint ___vcrt_initialize(void)

{
  uint uVar1;
  undefined4 uVar2;

  uVar1 = ___vcrt_initialize_locks();
  if ((char)uVar1 != '\0') {
    uVar2 = ___vcrt_initialize_ptd();
    if ((char)uVar2 != '\0') {
      return CONCAT31((int3)((uint)uVar2 >> 8),1);
    }
    uVar1 = ___vcrt_uninitialize_locks();
  }
  return uVar1 & 0xffffff00;
}



/* VA 10005f29 */

/* Library Function - Single Match
    ___vcrt_thread_attach

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

bool ___vcrt_thread_attach(void)

{
  LPVOID pvVar1;

  pvVar1 = ___vcrt_getptd_noexit();
  return pvVar1 != (LPVOID)0x0;
}



/* VA 10005f34 */

/* Library Function - Single Match
    ___vcrt_thread_detach

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined1 ___vcrt_thread_detach(void)

{
  ___vcrt_freeptd((undefined *)0x0);
  return 1;
}



/* VA 10005f3f */

/* Library Function - Single Match
    ___vcrt_uninitialize

   Library: Visual Studio 2019 Release */

undefined4 __cdecl ___vcrt_uninitialize(char param_1)

{
  undefined4 in_EAX;

  if (param_1 == '\0') {
    ___vcrt_uninitialize_ptd();
    in_EAX = ___vcrt_uninitialize_locks();
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



/* VA 10005f56 */

undefined4 FUN_10005f56(void)

{
  undefined4 uVar1;

  uVar1 = ___vcrt_uninitialize_ptd();
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}



/* VA 10005f60 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    _ValidateLocalCookies

   Library: Visual Studio 2019 Release */

void _ValidateLocalCookies(void)

{
  return;
}



/* VA 10005fa0 */

/* Library Function - Single Match
    __except_handler4

   Library: Visual Studio 2019 Release */

undefined4 __cdecl __except_handler4(PEXCEPTION_RECORD param_1,PVOID param_2,int param_3)

{
  uint uVar1;
  code *pcVar2;
  undefined *puVar3;
  DWORD DVar4;
  int iVar5;
  BOOL BVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  PEXCEPTION_RECORD local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  uint local_c;
  char local_5;

  local_5 = '\0';
  local_10 = 1;
  DVar4 = __filter_x86_sse2_floating_point_exception_default(param_1->ExceptionCode);
  param_1->ExceptionCode = DVar4;
  iVar8 = (int)param_2 + 0x10;
  local_c = *(uint *)((int)param_2 + 8) ^ DAT_10019008;
  local_14 = iVar8;
  _ValidateLocalCookies();
  ___except_validate_context_record(param_3);
  uVar9 = *(uint *)((int)param_2 + 0xc);
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    local_20 = param_1;
    local_1c = param_3;
    *(PEXCEPTION_RECORD **)((int)param_2 + -4) = &local_20;
    if (uVar9 == 0xfffffffe) {
      return local_10;
    }
    do {
      iVar5 = uVar9 * 3 + 4;
      uVar1 = *(uint *)(local_c + iVar5 * 4);
      local_18 = local_c + iVar5 * 4;
      if (*(undefined **)(local_18 + 4) != (undefined *)0x0) {
        iVar5 = _EH4_CallFilterFunc(*(undefined **)(local_18 + 4));
        local_5 = '\x01';
        if (iVar5 < 0) {
          local_10 = 0;
          goto LAB_10006064;
        }
        if (0 < iVar5) {
          if (((param_1->ExceptionCode == 0xe06d7363) &&
              (PTR____DestructExceptionObject_1001122c != (undefined *)0x0)) &&
             (BVar6 = __IsNonwritableInCurrentImage((PBYTE)&PTR____DestructExceptionObject_1001122c)
             , puVar3 = PTR____DestructExceptionObject_1001122c, BVar6 != 0)) {
            (*(code *)PTR_guard_check_icall_1001116c)(param_1,1);
            (*(code *)puVar3)();
            iVar8 = local_14;
          }
          _EH4_GlobalUnwind2(param_2,param_1);
          if (*(uint *)((int)param_2 + 0xc) != uVar9) {
            _EH4_LocalUnwind((int)param_2,uVar9,iVar8,&DAT_10019008);
          }
          *(uint *)((int)param_2 + 0xc) = uVar1;
          _ValidateLocalCookies();
          _EH4_TransferToHandler(*(undefined **)(local_18 + 8));
          pcVar2 = (code *)swi(3);
          uVar7 = (*pcVar2)();
          return uVar7;
        }
      }
      uVar9 = uVar1;
    } while (uVar1 != 0xfffffffe);
    if (local_5 == '\0') {
      return local_10;
    }
  }
  else {
    if (uVar9 == 0xfffffffe) {
      return local_10;
    }
    _EH4_LocalUnwind((int)param_2,0xfffffffe,iVar8,&DAT_10019008);
  }
LAB_10006064:
  _ValidateLocalCookies();
  return local_10;
}



/* VA 10006100 */

/* Library Function - Single Match
    _memset

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  int iVar1;
  undefined1 *puVar2;
  int *piVar3;

  if (_Size == 0) {
    return _Dst;
  }
  iVar1 = (_Val & 0xffU) * 0x1010101;
  piVar3 = _Dst;
  if (0x20 < _Size) {
    if (0x7f < _Size) {
      puVar2 = _Dst;
      if ((DAT_100199cc >> 1 & 1) != 0) {
        for (; _Size != 0; _Size = _Size - 1) {
          *puVar2 = (char)iVar1;
          puVar2 = puVar2 + 1;
        }
        return _Dst;
      }
      if ((DAT_10019004 >> 1 & 1) == 0) goto joined_r0x1000620b;
      *(int *)_Dst = iVar1;
      *(int *)((int)_Dst + 4) = iVar1;
      *(int *)((int)_Dst + 8) = iVar1;
      *(int *)((int)_Dst + 0xc) = iVar1;
      piVar3 = (int *)((int)_Dst + 0x10U & 0xfffffff0);
      _Size = (int)_Dst + (_Size - (int)piVar3);
      if (0x80 < _Size) {
        do {
          *piVar3 = iVar1;
          piVar3[1] = iVar1;
          piVar3[2] = iVar1;
          piVar3[3] = iVar1;
          piVar3[4] = iVar1;
          piVar3[5] = iVar1;
          piVar3[6] = iVar1;
          piVar3[7] = iVar1;
          piVar3[8] = iVar1;
          piVar3[9] = iVar1;
          piVar3[10] = iVar1;
          piVar3[0xb] = iVar1;
          piVar3[0xc] = iVar1;
          piVar3[0xd] = iVar1;
          piVar3[0xe] = iVar1;
          piVar3[0xf] = iVar1;
          piVar3[0x10] = iVar1;
          piVar3[0x11] = iVar1;
          piVar3[0x12] = iVar1;
          piVar3[0x13] = iVar1;
          piVar3[0x14] = iVar1;
          piVar3[0x15] = iVar1;
          piVar3[0x16] = iVar1;
          piVar3[0x17] = iVar1;
          piVar3[0x18] = iVar1;
          piVar3[0x19] = iVar1;
          piVar3[0x1a] = iVar1;
          piVar3[0x1b] = iVar1;
          piVar3[0x1c] = iVar1;
          piVar3[0x1d] = iVar1;
          piVar3[0x1e] = iVar1;
          piVar3[0x1f] = iVar1;
          piVar3 = piVar3 + 0x20;
          _Size = _Size - 0x80;
        } while ((_Size & 0xffffff00) != 0);
        goto LAB_100061d0;
      }
    }
    if ((DAT_10019004 >> 1 & 1) != 0) {
LAB_100061d0:
      if (0x1f < _Size) {
        do {
          *piVar3 = iVar1;
          piVar3[1] = iVar1;
          piVar3[2] = iVar1;
          piVar3[3] = iVar1;
          piVar3[4] = iVar1;
          piVar3[5] = iVar1;
          piVar3[6] = iVar1;
          piVar3[7] = iVar1;
          piVar3 = piVar3 + 8;
          _Size = _Size - 0x20;
        } while (0x1f < _Size);
        if ((_Size & 0x1f) == 0) {
          return _Dst;
        }
      }
      piVar3 = (int *)((int)piVar3 + (_Size - 0x20));
      *piVar3 = iVar1;
      piVar3[1] = iVar1;
      piVar3[2] = iVar1;
      piVar3[3] = iVar1;
      piVar3[4] = iVar1;
      piVar3[5] = iVar1;
      piVar3[6] = iVar1;
      piVar3[7] = iVar1;
      return _Dst;
    }
  }
joined_r0x1000620b:
  for (; (_Size & 3) != 0; _Size = _Size - 1) {
    *(char *)piVar3 = (char)iVar1;
    piVar3 = (int *)((int)piVar3 + 1);
  }
  if ((_Size & 4) != 0) {
    *piVar3 = iVar1;
    piVar3 = piVar3 + 1;
    _Size = _Size - 4;
  }
  for (; (_Size & 0xfffffff8) != 0; _Size = _Size - 8) {
    *piVar3 = iVar1;
    piVar3[1] = iVar1;
    piVar3 = piVar3 + 2;
  }
  return _Dst;
}



/* VA 1000625a */

/* Library Function - Single Match
    ___std_type_info_compare

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint __cdecl ___std_type_info_compare(int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;

  if (param_1 != param_2) {
    pbVar3 = (byte *)(param_2 + 5);
    pbVar2 = (byte *)(param_1 + 5);
    do {
      bVar1 = *pbVar2;
      bVar4 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_1000628f:
        return -(uint)bVar4 | 1;
      }
      if (bVar1 == 0) {
        return 0;
      }
      bVar1 = pbVar2[1];
      bVar4 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_1000628f;
      pbVar2 = pbVar2 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
  }
  return 0;
}



/* VA 10006296 */

/* Library Function - Single Match
    ___std_type_info_destroy_list

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___std_type_info_destroy_list(PSLIST_HEADER param_1)

{
  _SINGLE_LIST_ENTRY *p_Var1;
  PSINGLE_LIST_ENTRY p_Var2;

  p_Var2 = InterlockedFlushSList(param_1);
  while (p_Var2 != (PSINGLE_LIST_ENTRY)0x0) {
    p_Var1 = p_Var2->Next;
    FUN_10009118(p_Var2);
    p_Var2 = p_Var1;
  }
  return;
}



/* VA 100062b9 */

/* Library Function - Single Match
    ___vcrt_freefls@4

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___vcrt_freefls_4(undefined *param_1)

{
  if ((param_1 != (undefined *)0x0) && (param_1 != &DAT_10019d0c)) {
    FUN_10009118(param_1);
  }
  return;
}



/* VA 100062d5 */

/* Library Function - Single Match
    ___vcrt_freeptd

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___vcrt_freeptd(undefined *param_1)

{
  if (DAT_10019010 != 0xffffffff) {
    if (param_1 == (undefined *)0x0) {
      param_1 = (undefined *)___vcrt_FlsGetValue(DAT_10019010);
    }
    ___vcrt_FlsSetValue(DAT_10019010,(LPVOID)0x0);
    ___vcrt_freefls_4(param_1);
  }
  return;
}



/* VA 1000630b */

/* Library Function - Single Match
    ___vcrt_getptd

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___vcrt_getptd(void)

{
  code *pcVar1;
  LPVOID pvVar2;
  int iVar3;
  BOOL BVar4;

  pvVar2 = ___vcrt_getptd_noexit();
  if (pvVar2 != (LPVOID)0x0) {
    return;
  }
  iVar3 = ___acrt_get_sigabrt_handler();
  if (iVar3 != 0) {
    FUN_1000934c(0x16);
  }
  if ((DAT_10019030 & 2) != 0) {
    BVar4 = IsProcessorFeaturePresent(0x17);
    if (BVar4 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)();
    }
    ___acrt_call_reportfault(3,0x40000015,1);
  }
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* VA 10006319 */

/* Library Function - Single Match
    ___vcrt_getptd_noexit

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID ___vcrt_getptd_noexit(void)

{
  DWORD dwErrCode;
  LPVOID pvVar1;
  int iVar2;
  LPVOID pvVar3;
  LPVOID pvVar4;

  if (DAT_10019010 == 0xffffffff) {
    return (LPVOID)0x0;
  }
  dwErrCode = GetLastError();
  pvVar1 = (LPVOID)___vcrt_FlsGetValue(DAT_10019010);
  if (pvVar1 == (LPVOID)0xffffffff) {
LAB_10006359:
    pvVar1 = (LPVOID)0x0;
    goto LAB_1000639f;
  }
  if (pvVar1 != (LPVOID)0x0) goto LAB_1000639f;
  iVar2 = ___vcrt_FlsSetValue(DAT_10019010,(LPVOID)0xffffffff);
  if (iVar2 == 0) goto LAB_10006359;
  pvVar3 = (LPVOID)FUN_1000918d(1,0x28);
  if (pvVar3 == (LPVOID)0x0) {
LAB_10006381:
    ___vcrt_FlsSetValue(DAT_10019010,(LPVOID)0x0);
    pvVar1 = (LPVOID)0x0;
    pvVar4 = pvVar3;
  }
  else {
    iVar2 = ___vcrt_FlsSetValue(DAT_10019010,pvVar3);
    if (iVar2 == 0) goto LAB_10006381;
    pvVar4 = (LPVOID)0x0;
    pvVar1 = pvVar3;
  }
  FUN_10009118(pvVar4);
LAB_1000639f:
  SetLastError(dwErrCode);
  return pvVar1;
}



/* VA 100063ab */

/* Library Function - Single Match
    ___vcrt_initialize_ptd

   Library: Visual Studio 2019 Release */

uint ___vcrt_initialize_ptd(void)

{
  uint uVar1;
  int iVar2;

  uVar1 = ___vcrt_FlsAlloc(___vcrt_freefls_4);
  DAT_10019010 = uVar1;
  if (uVar1 != 0xffffffff) {
    iVar2 = ___vcrt_FlsSetValue(uVar1,&DAT_10019d0c);
    if (iVar2 != 0) {
      return CONCAT31((int3)((uint)iVar2 >> 8),1);
    }
    uVar1 = ___vcrt_uninitialize_ptd();
  }
  return uVar1 & 0xffffff00;
}



/* VA 100063de */

/* Library Function - Single Match
    ___vcrt_uninitialize_ptd

   Library: Visual Studio 2019 Release */

undefined4 ___vcrt_uninitialize_ptd(void)

{
  DWORD DVar1;

  DVar1 = DAT_10019010;
  if (DAT_10019010 != 0xffffffff) {
    DVar1 = ___vcrt_FlsFree(DAT_10019010);
    DAT_10019010 = 0xffffffff;
  }
  return CONCAT31((int3)(DVar1 >> 8),1);
}



/* VA 100063f9 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

char __cdecl FUN_100063f9(int param_1,uint *param_2,uint *param_3,byte *param_4)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  uint *puVar4;
  void *local_14;

  pcVar2 = DAT_10019d08;
  if (((param_3[1] == 0) || (*(char *)(param_3[1] + 8) == '\0')) ||
     ((param_3[2] == 0 && (-1 < (int)*param_3)))) {
    ExceptionList = local_14;
    return '\0';
  }
  uVar3 = *param_3;
  if (-1 < (int)uVar3) {
    param_2 = (uint *)((int)param_2 + param_3[2] + 0xc);
  }
  if ((((char)uVar3 < '\0') && ((*param_4 & 0x10) != 0)) && (DAT_10019d08 != (code *)0x0)) {
    (*(code *)PTR_guard_check_icall_1001116c)();
    uVar3 = (*pcVar2)();
  }
  else {
    if ((uVar3 & 8) == 0) {
      if ((*param_4 & 1) == 0) {
        iVar1 = *(int *)(param_1 + 0x18);
        if (*(int *)(param_4 + 0x18) == 0) {
          if ((iVar1 != 0) && (param_2 != (uint *)0x0)) {
            uVar3 = *(uint *)(param_4 + 0x14);
            puVar4 = (uint *)___AdjustPointer(iVar1,(int *)(param_4 + 8));
            FUN_10007600(param_2,puVar4,uVar3);
            ExceptionList = local_14;
            return '\0';
          }
        }
        else if ((iVar1 != 0) && (param_2 != (uint *)0x0)) {
          ExceptionList = local_14;
          return ((*param_4 & 4) != 0) + '\x01';
        }
        goto LAB_10006531;
      }
      if ((*(int *)(param_1 + 0x18) == 0) || (param_2 == (uint *)0x0)) goto LAB_10006531;
      FUN_10007600(param_2,*(uint **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
      if (*(int *)(param_4 + 0x14) != 4) {
        ExceptionList = local_14;
        return '\0';
      }
      if (*param_2 == 0) {
        ExceptionList = local_14;
        return '\0';
      }
      uVar3 = *param_2;
      goto LAB_100064c0;
    }
    uVar3 = *(uint *)(param_1 + 0x18);
  }
  if ((uVar3 == 0) || (param_2 == (uint *)0x0)) {
LAB_10006531:
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  *param_2 = uVar3;
LAB_100064c0:
  uVar3 = ___AdjustPointer(uVar3,(int *)(param_4 + 8));
  *param_2 = uVar3;
  ExceptionList = local_14;
  return '\0';
}



/* VA 10006537 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    void __cdecl BuildCatchObjectInternal<class __FrameHandler3>(struct EHExceptionRecord *,void
   *,struct _s_HandlerType const *,struct _s_CatchableType const *)

   Library: Visual Studio 2019 Release */

void __cdecl
BuildCatchObjectInternal<__FrameHandler3>
          (EHExceptionRecord *param_1,void *param_2,_s_HandlerType *param_3,
          _s_CatchableType *param_4)

{
  char cVar1;
  undefined3 extraout_var;
  void *pvVar2;
  void *pvVar3;
  void *local_14;

  pvVar3 = param_2;
  if (-1 < (int)param_3->adjectives) {
    pvVar3 = (void *)((int)param_2 + param_3->dispCatchObj + 0xc);
  }
  cVar1 = FUN_100063f9((int)param_1,param_2,&param_3->adjectives,(byte *)param_4);
  if (CONCAT31(extraout_var,cVar1) == 1) {
    pvVar2 = (void *)___AdjustPointer(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
    _CallMemberFunction1(pvVar3,*(void **)(param_4 + 0x18),pvVar2);
  }
  else if (CONCAT31(extraout_var,cVar1) == 2) {
    pvVar2 = (void *)___AdjustPointer(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
    _CallMemberFunction2(pvVar3,*(void **)(param_4 + 0x18),pvVar2,1);
  }
  ExceptionList = local_14;
  return;
}



/* VA 100065d0 */

/* Library Function - Single Match
    void __cdecl CatchIt<class __FrameHandler3>(struct EHExceptionRecord *,struct EHRegistrationNode
   *,struct _CONTEXT *,void *,struct _s_FuncInfo const *,struct _s_HandlerType const *,struct
   _s_CatchableType const *,struct _s_TryBlockMapEntry const *,int,struct EHRegistrationNode
   *,unsigned char,unsigned char)

   Library: Visual Studio 2019 Release */

void __cdecl
CatchIt<__FrameHandler3>
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,_s_HandlerType *param_6,_s_CatchableType *param_7,
          _s_TryBlockMapEntry *param_8,int param_9,EHRegistrationNode *param_10,uchar param_11,
          uchar param_12)

{
  void *pvVar1;

  if (param_7 != (_s_CatchableType *)0x0) {
    BuildCatchObjectInternal<__FrameHandler3>(param_1,param_2,param_6,param_7);
  }
  if (param_10 == (EHRegistrationNode *)0x0) {
    param_10 = param_2;
  }
  _UnwindNestedFrames(param_10,param_1);
  FUN_10006f86(param_2,param_4,param_5,param_8->tryLow);
  __FrameHandler3::SetState(param_2,param_5,param_8->tryHigh + 1);
  pvVar1 = (void *)FUN_10006d16((int)param_1,(int)param_2,param_3,param_5,param_6->addressOfHandler,
                                param_9,0x100);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,param_2);
  }
  return;
}



/* VA 10006650 */

void __cdecl
FUN_10006650(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            _s_FuncInfo *param_5,uchar param_6,int param_7,EHRegistrationNode *param_8)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  __ehstate_t *p_Var8;
  _s_TryBlockMapEntry *p_Var9;
  int *piVar10;
  _s_TryBlockMapEntry local_68;
  _s_HandlerType local_54;
  int *local_44;
  int *local_40 [2];
  int *local_38;
  _s_FuncInfo *local_34;
  undefined4 local_30;
  int *local_2c;
  int local_28;
  int *local_24;
  int local_20;
  uint local_1c;
  HandlerType *local_18;
  int local_14;
  int *local_10;
  int local_c;
  _CONTEXT *local_8;

  local_14 = 0;
  local_1c = local_1c & 0xffffff00;
  local_c = __FrameHandler3::GetCurrentState(param_2,param_4,param_5);
  if ((local_c < -1) || (param_5->maxState <= local_c)) goto LAB_100069ef;
  if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
     ((((*(int *)(param_1 + 0x14) == 0x19930520 || (*(int *)(param_1 + 0x14) == 0x19930521)) ||
       (*(int *)(param_1 + 0x14) == 0x19930522)) && (iVar7 = 0, *(int *)(param_1 + 0x1c) == 0)))) {
    iVar2 = ___vcrt_getptd();
    if (*(int *)(iVar2 + 0x10) == 0) {
      return;
    }
    iVar2 = ___vcrt_getptd();
    param_1 = *(EHExceptionRecord **)(iVar2 + 0x10);
    iVar2 = ___vcrt_getptd();
    local_1c = CONCAT31(local_1c._1_3_,1);
    local_8 = *(_CONTEXT **)(iVar2 + 0x14);
    if ((param_1 == (EHExceptionRecord *)0x0) ||
       ((((*(int *)param_1 == -0x1f928c9d && (*(int *)(param_1 + 0x10) == 3)) &&
         ((*(int *)(param_1 + 0x14) == 0x19930520 ||
          ((*(int *)(param_1 + 0x14) == 0x19930521 || (*(int *)(param_1 + 0x14) == 0x19930522))))))
        && (*(int *)(param_1 + 0x1c) == 0)))) goto LAB_100069ef;
    iVar2 = ___vcrt_getptd();
    if (*(int *)(iVar2 + 0x1c) != 0) {
      iVar2 = ___vcrt_getptd();
      local_10 = *(int **)(iVar2 + 0x1c);
      iVar2 = ___vcrt_getptd();
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      uVar3 = FUN_1000706e((int)param_1,local_10);
      piVar6 = local_10;
      if ((char)uVar3 == '\0') {
        if (0 < *local_10) {
          do {
            bVar1 = type_info::operator==
                              (*(type_info **)(iVar7 + 4 + piVar6[1]),
                               (type_info *)&std::bad_exception::RTTI_Type_Descriptor);
            if (bVar1) {
              ___DestructExceptionObject((int *)param_1);
              FUN_10006cdf(local_40);
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8((int *)local_40,&DAT_10017544);
            }
            iVar7 = iVar7 + 0x10;
            local_14 = local_14 + 1;
          } while (local_14 < *piVar6);
        }
        goto LAB_1000698e;
      }
    }
  }
  else {
    local_8 = param_3;
  }
  local_34 = param_5;
  local_30 = 0;
  if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
     ((*(int *)(param_1 + 0x14) == 0x19930520 ||
      ((*(int *)(param_1 + 0x14) == 0x19930521 || (*(int *)(param_1 + 0x14) == 0x19930522)))))) {
    if (param_5->nTryBlocks != 0) {
      FUN_100058ba(&local_44,&local_34,local_c,param_4,(int)param_5,param_7);
      local_2c = local_44;
      local_10 = local_40[0];
      if (local_40[0] < local_38) {
        local_20 = (int)local_40[0] * 0x14;
        piVar6 = local_40[0];
        do {
          iVar2 = local_c;
          p_Var8 = (__ehstate_t *)(*(int *)(*local_2c + 0x10) + local_20);
          p_Var9 = &local_68;
          local_10 = piVar6;
          for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
            p_Var9->tryLow = *p_Var8;
            p_Var8 = p_Var8 + 1;
            p_Var9 = (_s_TryBlockMapEntry *)&p_Var9->tryHigh;
          }
          if (((local_68.tryLow <= iVar2) && (iVar2 <= local_68.tryHigh)) &&
             (local_14 = 0, local_68.nCatches != 0)) {
            pbVar5 = *(byte **)(param_1 + 0x1c);
            local_28 = **(int **)(pbVar5 + 0xc);
            local_24 = *(int **)(pbVar5 + 0xc) + 1;
            local_18 = local_68.pHandlerArray;
            do {
              local_54.adjectives = local_18->adjectives;
              local_54.pType = local_18->pType;
              local_54.dispCatchObj = local_18->dispCatchObj;
              local_54.addressOfHandler = local_18->addressOfHandler;
              piVar10 = local_24;
              piVar6 = local_10;
              for (iVar7 = local_28; local_10 = piVar6, 0 < iVar7; iVar7 = iVar7 + -1) {
                iVar2 = FID_conflict____TypeMatch((byte *)&local_54,(byte *)*piVar10,pbVar5);
                if (iVar2 != 0) {
                  CatchIt<__FrameHandler3>
                            (param_1,param_2,local_8,param_4,param_5,&local_54,
                             (_s_CatchableType *)*piVar10,&local_68,param_7,param_8,(uchar)local_1c,
                             param_6);
                  piVar6 = local_10;
                  goto LAB_100068d9;
                }
                pbVar5 = *(byte **)(param_1 + 0x1c);
                piVar10 = piVar10 + 1;
                piVar6 = local_10;
              }
              local_14 = local_14 + 1;
              local_18 = local_18 + 1;
            } while (local_14 != local_68.nCatches);
          }
LAB_100068d9:
          piVar6 = (int *)((int)piVar6 + 1);
          local_20 = local_20 + 0x14;
          local_10 = piVar6;
        } while (piVar6 < local_38);
      }
    }
    if (param_6 != '\0') {
      ___DestructExceptionObject((int *)param_1);
    }
    if (0x19930520 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff)) {
      uVar4 = (uint)param_5->EHFlags >> 2;
      if (param_5->pESTypeList == (ESTypeList *)0x0) {
        if (((uVar4 & 1) != 0) && (param_7 == 0)) {
LAB_10006932:
          iVar7 = ___vcrt_getptd();
          *(EHExceptionRecord **)(iVar7 + 0x10) = param_1;
          iVar7 = ___vcrt_getptd();
          *(_CONTEXT **)(iVar7 + 0x14) = local_8;
LAB_1000698e:
                    /* WARNING: Subroutine does not return */
          FUN_100090dc();
        }
      }
      else {
        if ((uVar4 & 1) != 0) goto LAB_10006932;
        uVar3 = FUN_1000706e((int)param_1,&param_5->pESTypeList->nCount);
        if ((char)uVar3 == '\0') {
          iVar7 = ___vcrt_getptd();
          *(EHExceptionRecord **)(iVar7 + 0x10) = param_1;
          iVar7 = ___vcrt_getptd();
          *(_CONTEXT **)(iVar7 + 0x14) = local_8;
          if (param_8 == (EHRegistrationNode *)0x0) {
            param_8 = param_2;
          }
          _UnwindNestedFrames(param_8,param_1);
          __FrameHandler3::FrameUnwindToEmptyState(param_2,param_4,param_5);
          uVar3 = FUN_1000712b((int)param_5);
          FUN_10006ee5(uVar3);
          goto LAB_100069ef;
        }
      }
    }
  }
  else if (param_5->nTryBlocks != 0) {
    if (param_6 != '\0') goto LAB_100069ef;
    FUN_100069f5(param_1,param_2,local_8,param_4,param_5,local_c,param_7,param_8);
  }
  iVar7 = ___vcrt_getptd();
  if (*(int *)(iVar7 + 0x1c) == 0) {
    return;
  }
LAB_100069ef:
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 100069f5 */

void __cdecl
FUN_100069f5(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            _s_FuncInfo *param_5,int param_6,int param_7,EHRegistrationNode *param_8)

{
  int iVar1;
  PVOID pvVar2;
  _s_HandlerType *p_Var3;
  uint uVar4;
  __ehstate_t *p_Var5;
  _s_TryBlockMapEntry *p_Var6;
  _s_TryBlockMapEntry local_3c;
  int *local_28;
  uint local_24;
  uint local_1c;
  _s_FuncInfo *local_18;
  undefined4 local_14;
  int *local_10;
  int local_c;
  uint local_8;

  if (*(int *)param_1 != -0x7ffffffd) {
    iVar1 = ___vcrt_getptd();
    if (*(int *)(iVar1 + 8) != 0) {
      pvVar2 = EncodePointer((PVOID)0x0);
      iVar1 = ___vcrt_getptd();
      if ((((*(PVOID *)(iVar1 + 8) != pvVar2) && (*(int *)param_1 != -0x1fbcb0b3)) &&
          (*(int *)param_1 != -0x1fbcbcae)) &&
         (iVar1 = FUN_10005987((int *)param_1,(undefined4 *)param_2,param_3,param_4,param_5,param_7,
                               param_8), iVar1 != 0)) {
        return;
      }
    }
    local_18 = param_5;
    local_14 = 0;
    if (param_5->nTryBlocks == 0) {
                    /* WARNING: Subroutine does not return */
      _abort();
    }
    FUN_100058ba(&local_28,&local_18,param_6,param_4,(int)param_5,param_7);
    local_10 = local_28;
    if (local_24 < local_1c) {
      local_c = local_24 * 0x14;
      uVar4 = local_24;
      do {
        p_Var5 = (__ehstate_t *)(*(int *)(*local_10 + 0x10) + local_c);
        p_Var6 = &local_3c;
        local_8 = uVar4;
        for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
          p_Var6->tryLow = *p_Var5;
          p_Var5 = p_Var5 + 1;
          p_Var6 = (_s_TryBlockMapEntry *)&p_Var6->tryHigh;
        }
        if ((local_3c.tryLow <= param_6) && (param_6 <= local_3c.tryHigh)) {
          p_Var3 = local_3c.pHandlerArray + local_3c.nCatches + -1;
          if (((p_Var3->pType == (TypeDescriptor *)0x0) ||
              (*(char *)&p_Var3->pType[1].pVFTable == '\0')) && ((p_Var3->adjectives & 0x40) == 0))
          {
            CatchIt<__FrameHandler3>
                      (param_1,param_2,param_3,param_4,param_5,p_Var3,(_s_CatchableType *)0x0,
                       &local_3c,param_7,param_8,'\x01','\0');
            uVar4 = local_8;
          }
        }
        uVar4 = uVar4 + 1;
        local_c = local_c + 0x14;
      } while (uVar4 < local_1c);
    }
  }
  return;
}



/* VA 10006b2b */

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl TypeMatchHelper<struct _s_HandlerType const >(struct _s_HandlerType const *,struct
   _s_CatchableType const *,struct _s_ThrowInfo const *)
    int __cdecl TypeMatchHelper<class __FrameHandler3>(struct _s_HandlerType const *,struct
   _s_CatchableType const *,struct _s_ThrowInfo const *)
    ___TypeMatch

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __cdecl FID_conflict____TypeMatch(byte *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  bool bVar7;

  iVar2 = *(int *)(param_1 + 4);
  if (((iVar2 == 0) || (pbVar5 = (byte *)(iVar2 + 8), *pbVar5 == 0)) ||
     (((*param_1 & 0x80) != 0 && ((*param_2 & 0x10) != 0)))) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
    if (iVar2 != *(int *)(param_2 + 4)) {
      pbVar3 = (byte *)(*(int *)(param_2 + 4) + 8);
      do {
        bVar1 = *pbVar5;
        bVar7 = bVar1 < *pbVar3;
        if (bVar1 != *pbVar3) {
LAB_10006b7c:
          uVar4 = -(uint)bVar7 | 1;
          goto LAB_10006b81;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar7 = bVar1 < pbVar3[1];
        if (bVar1 != pbVar3[1]) goto LAB_10006b7c;
        pbVar5 = pbVar5 + 2;
        pbVar3 = pbVar3 + 2;
      } while (bVar1 != 0);
      uVar4 = 0;
LAB_10006b81:
      if (uVar4 != 0) {
        return 0;
      }
    }
    if ((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
       ((((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)) &&
        (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))))) {
      uVar6 = 1;
    }
  }
  return uVar6;
}



/* VA 10006bb9 */

/* Library Function - Single Match
    enum _EXCEPTION_DISPOSITION __cdecl __InternalCxxFrameHandler<class __FrameHandler3>(struct
   EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT *,void *,struct _s_FuncInfo const
   *,int,struct EHRegistrationNode *,unsigned char)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_EXCEPTION_DISPOSITION __cdecl
__InternalCxxFrameHandler<__FrameHandler3>
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7,uchar param_8)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  _EXCEPTION_DISPOSITION _Var4;

  ___except_validate_context_record((int)param_3);
  iVar2 = ___vcrt_getptd();
  if ((((*(int *)(iVar2 + 0x20) != 0) || (*(int *)param_1 == -0x1f928c9d)) ||
      (*(int *)param_1 == -0x7fffffda)) ||
     (((param_5->magicNumber_and_bbtFlags & 0x1fffffff) < 0x19930522 ||
      ((param_5->EHFlags & 1) == 0)))) {
    if (((byte)param_1[4] & 0x66) == 0) {
      if (((param_5->nTryBlocks != 0) ||
          ((uVar3 = param_5->magicNumber_and_bbtFlags & 0x1fffffff, 0x19930520 < uVar3 &&
           (param_5->pESTypeList != (ESTypeList *)0x0)))) ||
         ((0x19930521 < uVar3 && (((uint)param_5->EHFlags >> 2 & 1) != 0)))) {
        if ((((*(int *)param_1 == -0x1f928c9d) && (2 < *(uint *)(param_1 + 0x10))) &&
            (0x19930522 < *(uint *)(param_1 + 0x14))) &&
           (pcVar1 = *(code **)(*(int *)(param_1 + 0x1c) + 8), pcVar1 != (code *)0x0)) {
          (*(code *)PTR_guard_check_icall_1001116c)
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
          _Var4 = (*pcVar1)();
          return _Var4;
        }
        FUN_10006650(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7);
      }
    }
    else if ((param_5->maxState != 0) && (param_6 == 0)) {
      __FrameHandler3::FrameUnwindToEmptyState(param_2,param_4,param_5);
    }
  }
  return 1;
}



/* VA 10006cbb */

void __cdecl
FUN_10006cbb(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            _s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7,uchar param_8)

{
  __InternalCxxFrameHandler<__FrameHandler3>
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* VA 10006cc4 */

undefined4 * __thiscall FUN_10006cc4(void *this,int param_1)

{
  FUN_10001320(this,param_1);
  *(undefined ***)this = std::bad_exception::vftable;
  return this;
}



/* VA 10006cdf */

undefined4 * __fastcall FUN_10006cdf(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[1] = "bad exception";
  *param_1 = std::bad_exception::vftable;
  return param_1;
}



/* VA 10006cf7 */

/* Library Function - Single Match
    public: bool __thiscall type_info::operator==(class type_info const &)const

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __thiscall type_info::operator==(type_info *this,type_info *param_1)

{
  uint uVar1;

  uVar1 = ___std_type_info_compare((int)(this + 4),(int)(param_1 + 4));
  return (bool)('\x01' - (uVar1 != 0));
}



/* VA 10006d16 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

undefined4 __cdecl
FUN_10006d16(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_34;
  undefined4 local_20;
  void *local_14;
  undefined4 uStack_c;
  undefined *local_8;

  local_8 = &DAT_10017488;
  uStack_c = 0x10006d22;
  local_20 = param_5;
  local_44 = 0;
  local_34 = *(undefined4 *)(param_2 + -4);
  local_38 = __CreateFrameInfo(local_50,*(undefined4 *)(param_1 + 0x18));
  iVar1 = ___vcrt_getptd();
  local_3c = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = ___vcrt_getptd();
  local_40 = *(undefined4 *)(iVar1 + 0x14);
  iVar1 = ___vcrt_getptd();
  *(int *)(iVar1 + 0x10) = param_1;
  iVar1 = ___vcrt_getptd();
  *(undefined4 *)(iVar1 + 0x14) = param_3;
  local_48 = 1;
  local_8 = (undefined *)0x1;
  uVar2 = FUN_1000592a(param_2,param_4,param_5,param_6,param_7);
  local_8 = (undefined *)0xfffffffe;
  local_48 = 0;
  local_20 = uVar2;
  FUN_10006e69();
  ExceptionList = local_14;
  return uVar2;
}



/* VA 10006e69 */

void FUN_10006e69(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;

  *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + -4) = *(undefined4 *)(unaff_EBP + -0x30);
  FUN_10005b55(*(int *)(unaff_EBP + -0x34));
  iVar1 = ___vcrt_getptd();
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(unaff_EBP + -0x38);
  iVar1 = ___vcrt_getptd();
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(unaff_EBP + -0x3c);
  if ((((*unaff_ESI == -0x1f928c9d) && (unaff_ESI[4] == 3)) &&
      ((unaff_ESI[5] == 0x19930520 || ((unaff_ESI[5] == 0x19930521 || (unaff_ESI[5] == 0x19930522)))
       ))) && ((*(int *)(unaff_EBP + -0x40) == 0 && (unaff_EBX != 0)))) {
    iVar1 = __IsExceptionObjectToBeDestroyed(unaff_ESI[6]);
    if (iVar1 != 0) {
      ___DestructExceptionObject(unaff_ESI);
    }
  }
  return;
}



/* VA 10006ee5 */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10006ee5(undefined4 param_1)

{
  int iVar1;

  iVar1 = ___vcrt_getptd();
  if (*(int *)(iVar1 + 0x1c) == 0) {
    FUN_100075b8();
    iVar1 = ___vcrt_getptd();
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8((int *)0x0,(byte *)0x0);
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 10006f05 */

void Catch_All_10006f05(void)

{
  int iVar1;
  int unaff_EBP;

  iVar1 = ___vcrt_getptd();
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(unaff_EBP + 8);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8((int *)0x0,(byte *)0x0);
}



/* VA 10006f24 */

/* Library Function - Single Match
    int __cdecl ExFilterRethrow(struct _EXCEPTION_POINTERS *)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl ExFilterRethrow(_EXCEPTION_POINTERS *param_1)

{
  PEXCEPTION_RECORD pEVar1;
  int iVar2;

  pEVar1 = param_1->ExceptionRecord;
  if ((((pEVar1->ExceptionCode == 0xe06d7363) && (pEVar1->NumberParameters == 3)) &&
      ((pEVar1->ExceptionInformation[0] == 0x19930520 ||
       ((pEVar1->ExceptionInformation[0] == 0x19930521 ||
        (pEVar1->ExceptionInformation[0] == 0x19930522)))))) &&
     (pEVar1->ExceptionInformation[2] == 0)) {
    iVar2 = ___vcrt_getptd();
    *(undefined4 *)(iVar2 + 0x20) = 1;
    return 1;
  }
  return 0;
}



/* VA 10006f6e */

/* Library Function - Single Match
    public: static void __cdecl __FrameHandler3::FrameUnwindToEmptyState(struct EHRegistrationNode
   *,void *,struct _s_FuncInfo const *)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
__FrameHandler3::FrameUnwindToEmptyState
          (EHRegistrationNode *param_1,void *param_2,_s_FuncInfo *param_3)

{
  FUN_10006f86(param_1,param_2,param_3,-1);
  return;
}



/* VA 10006f86 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

void __cdecl
FUN_10006f86(EHRegistrationNode *param_1,void *param_2,_s_FuncInfo *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;

  iVar1 = __FrameHandler3::GetCurrentState(param_1,param_2,param_3);
  iVar2 = ___vcrt_getptd();
  *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
  while (iVar2 = iVar1, iVar2 != param_4) {
    if ((iVar2 < 0) || (param_3->maxState <= iVar2)) goto LAB_10007068;
    iVar1 = param_3->pUnwindMap[iVar2].toState;
    if (param_3->pUnwindMap[iVar2].action != (action *)0x0) {
      __FrameHandler3::SetState(param_1,param_3,iVar1);
      __CallSettingFrame_12(param_3->pUnwindMap[iVar2].action,param_1,0x103);
    }
  }
  FUN_10007054();
  if (iVar2 == param_4) {
    __FrameHandler3::SetState(param_1,param_3,iVar2);
    ExceptionList = local_14;
    return;
  }
LAB_10007068:
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 10007054 */

void FUN_10007054(void)

{
  int iVar1;

  iVar1 = ___vcrt_getptd();
  if (0 < *(int *)(iVar1 + 0x18)) {
    iVar1 = ___vcrt_getptd();
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
  }
  return;
}



/* VA 1000706e */

undefined4 __cdecl FUN_1000706e(int param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  int iVar4;
  int *piVar5;
  undefined1 uVar6;
  int iVar7;
  int local_c;
  int local_8;

  if (param_2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  iVar7 = *param_2;
  uVar6 = 0;
  if (0 < iVar7) {
    local_8 = 0;
    pbVar1 = *(byte **)(param_1 + 0x1c);
    piVar5 = *(int **)(pbVar1 + 0xc);
    iVar2 = *piVar5;
    in_EAX = piVar5 + 1;
    uVar6 = 0;
    do {
      if (0 < iVar2) {
        iVar3 = param_2[1];
        piVar5 = in_EAX;
        local_c = iVar2;
        do {
          iVar4 = FID_conflict____TypeMatch((byte *)(iVar3 + local_8),(byte *)*piVar5,pbVar1);
          if (iVar4 != 0) {
            uVar6 = 1;
            break;
          }
          local_c = local_c + -1;
          piVar5 = piVar5 + 1;
        } while (0 < local_c);
      }
      local_8 = local_8 + 0x10;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),uVar6);
}



/* VA 10007108 */

/* Library Function - Single Match
    void __stdcall _CallMemberFunction1(void * const,void * const,void * const)

   Library: Visual Studio 2019 Release */

void _CallMemberFunction1(void *param_1,void *param_2,void *param_3)

{
  (*param_2)(param_3);
  return;
}



/* VA 10007118 */

/* Library Function - Single Match
    void __stdcall _CallMemberFunction2(void * const,void * const,void * const,int)

   Library: Visual Studio 2019 Release */

void _CallMemberFunction2(void *param_1,void *param_2,void *param_3,int param_4)

{
  (*param_2)(param_3,param_4);
  return;
}



/* VA 1000712b */

undefined4 __cdecl FUN_1000712b(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}



/* VA 10007140 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12

   Library: Visual Studio */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;

  pcVar1 = (code *)FUN_10007b80(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  FUN_10007b80(param_3);
  return;
}



/* VA 1000718c */

/* Library Function - Single Match
    ___except_validate_context_record

   Library: Visual Studio 2019 Release */

void __cdecl ___except_validate_context_record(int param_1)

{
  code *pcVar1;

  if ((code *)PTR_guard_check_icall_1001116c != guard_check_icall) {
    if ((*(uint *)(param_1 + 0xc4) < *(uint *)((int)Self + 8)) ||
       (*(uint *)((int)Self + 4) < *(uint *)(param_1 + 0xc4))) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)();
    }
  }
  return;
}



/* VA 100071bc */

/* Library Function - Single Match
    ___vcrt_initialize_locks

   Library: Visual Studio 2019 Release */

undefined4 ___vcrt_initialize_locks(void)

{
  int iVar1;
  uint uVar2;
  LPCRITICAL_SECTION p_Var3;

  p_Var3 = (LPCRITICAL_SECTION)&DAT_10019d34;
  uVar2 = 0;
  do {
    iVar1 = ___vcrt_InitializeCriticalSectionEx(p_Var3,4000,0);
    if (iVar1 == 0) {
      uVar2 = ___vcrt_uninitialize_locks();
      return uVar2 & 0xffffff00;
    }
    DAT_10019d4c = DAT_10019d4c + 1;
    uVar2 = uVar2 + 0x18;
    p_Var3 = p_Var3 + 1;
  } while (uVar2 < 0x18);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}



/* VA 100071f8 */

/* Library Function - Single Match
    ___vcrt_uninitialize_locks

   Library: Visual Studio 2019 Release */

undefined4 ___vcrt_uninitialize_locks(void)

{
  undefined4 in_EAX;
  undefined4 extraout_EAX;
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;

  if (DAT_10019d4c != 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_10019d1c + DAT_10019d4c * 0x18);
    iVar1 = DAT_10019d4c;
    do {
      DeleteCriticalSection(lpCriticalSection);
      DAT_10019d4c = DAT_10019d4c + -1;
      lpCriticalSection = lpCriticalSection + -1;
      iVar1 = iVar1 + -1;
      in_EAX = extraout_EAX;
    } while (iVar1 != 0);
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



/* VA 10007230 */

void __cdecl FUN_10007230(uint *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvStack_28;
  undefined1 *puStack_24;
  uint local_20;
  uint uStack_1c;
  int iStack_18;
  uint *puStack_14;

  puStack_14 = param_1;
  iStack_18 = param_2;
  uStack_1c = param_3;
  puStack_24 = &LAB_100072d0;
  pvStack_28 = ExceptionList;
  local_20 = DAT_10019008 ^ (uint)&pvStack_28;
  ExceptionList = &pvStack_28;
  while( true ) {
    uVar2 = *(uint *)(param_2 + 0xc);
    if ((uVar2 == 0xfffffffe) || ((param_3 != 0xfffffffe && (uVar2 <= param_3)))) break;
    puVar1 = (undefined4 *)((*(uint *)(param_2 + 8) ^ *param_1) + 0x10 + uVar2 * 0xc);
    *(undefined4 *)(param_2 + 0xc) = *puVar1;
    if (puVar1[1] == 0) {
      __NLG_Notify(0x101);
      FUN_10007bb0();
    }
  }
  ExceptionList = pvStack_28;
  return;
}



/* VA 10007320 */

/* Library Function - Single Match
    @_EH4_CallFilterFunc@8

   Library: Visual Studio 2019 Release
   __fastcall _EH4_CallFilterFunc,8 */

void __fastcall _EH4_CallFilterFunc(undefined *param_1)

{
  (*(code *)param_1)();
  return;
}



/* VA 10007340 */

/* Library Function - Single Match
    @_EH4_TransferToHandler@8

   Library: Visual Studio 2019 Release
   __fastcall _EH4_TransferToHandler,8 */

void __fastcall _EH4_TransferToHandler(undefined *UNRECOVERED_JUMPTABLE)

{
  __NLG_Notify(1);
                    /* WARNING: Could not recover jumptable at 0x10007357. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* VA 10007360 */

/* Library Function - Single Match
    @_EH4_GlobalUnwind2@8

   Library: Visual Studio 2019 Release
   __fastcall _EH4_GlobalUnwind2,8 */

void __fastcall _EH4_GlobalUnwind2(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  RtlUnwind(param_1,(PVOID)0x10007375,param_2,(PVOID)0x0);
  return;
}



/* VA 10007380 */

/* Library Function - Single Match
    @_EH4_LocalUnwind@16

   Library: Visual Studio 2019 Release
   __fastcall _EH4_LocalUnwind,16 */

void __fastcall _EH4_LocalUnwind(int param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  FUN_10007230(param_4,param_1,param_2);
  return;
}



/* VA 10007397 */

FARPROC __cdecl FUN_10007397(int param_1,LPCSTR param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  FARPROC pFVar4;
  HMODULE hLibModule;

  piVar1 = (int *)(&DAT_10019d98 + param_1 * 4);
  pFVar4 = (FARPROC)*piVar1;
  if (pFVar4 == (FARPROC)0xffffffff) {
    pFVar4 = (FARPROC)0x0;
  }
  else if (pFVar4 == (FARPROC)0x0) {
    for (; param_3 != param_4; param_3 = param_3 + 1) {
      iVar3 = *param_3;
      hLibModule = *(HMODULE *)(&DAT_10019d8c + iVar3 * 4);
      if (hLibModule == (HMODULE)0x0) {
        hLibModule = try_load_library_from_system_directory
                               ((wchar_t *)(&PTR_u_api_ms_win_core_fibers_l1_1_1_10011c04)[iVar3]);
        piVar2 = (int *)(&DAT_10019d8c + iVar3 * 4);
        if (hLibModule != (HINSTANCE__ *)0x0) {
          LOCK();
          iVar3 = *piVar2;
          *piVar2 = (int)hLibModule;
          UNLOCK();
          if (iVar3 != 0) {
            FreeLibrary(hLibModule);
          }
          goto LAB_10007420;
        }
        LOCK();
        *piVar2 = -1;
        UNLOCK();
      }
      else if (hLibModule != (HMODULE)0xffffffff) {
LAB_10007420:
        pFVar4 = GetProcAddress(hLibModule,param_2);
        if (pFVar4 != (FARPROC)0x0) {
          LOCK();
          *piVar1 = (int)pFVar4;
          UNLOCK();
          return pFVar4;
        }
        break;
      }
    }
    LOCK();
    *piVar1 = -1;
    UNLOCK();
    pFVar4 = (FARPROC)0x0;
  }
  return pFVar4;
}



/* VA 10007437 */

/* Library Function - Single Match
    struct HINSTANCE__ * __cdecl try_load_library_from_system_directory(wchar_t const * const)

   Library: Visual Studio 2019 Release */

HINSTANCE__ * __cdecl try_load_library_from_system_directory(wchar_t *param_1)

{
  HINSTANCE__ *pHVar1;
  DWORD DVar2;
  int iVar3;
  HMODULE pHVar4;

  pHVar1 = LoadLibraryExW(param_1,(HANDLE)0x0,0x800);
  if (pHVar1 == (HMODULE)0x0) {
    DVar2 = GetLastError();
    if (DVar2 == 0x57) {
      iVar3 = _wcsncmp(param_1,L"api-ms-",7);
      if (iVar3 != 0) {
        pHVar4 = LoadLibraryExW(param_1,(HANDLE)0x0,0);
        return pHVar4;
      }
    }
    pHVar1 = (HINSTANCE__ *)0x0;
  }
  return pHVar1;
}



/* VA 10007482 */

/* Library Function - Single Match
    ___vcrt_FlsAlloc

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___vcrt_FlsAlloc(undefined4 param_1)

{
  FARPROC pFVar1;

  pFVar1 = FUN_10007397(0,"FlsAlloc",(int *)&DAT_10011cac,(int *)"FlsAlloc");
  if (pFVar1 != (FARPROC)0x0) {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1);
    (*pFVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x100074b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsAlloc();
  return;
}



/* VA 100074bd */

/* Library Function - Single Match
    ___vcrt_FlsFree

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___vcrt_FlsFree(DWORD param_1)

{
  FARPROC pFVar1;

  pFVar1 = FUN_10007397(1,"FlsFree",(int *)&DAT_10011cc0,(int *)"FlsFree");
  if (pFVar1 == (FARPROC)0x0) {
    TlsFree(param_1);
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)();
    (*pFVar1)();
  }
  return;
}



/* VA 100074f8 */

/* Library Function - Single Match
    ___vcrt_FlsGetValue

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___vcrt_FlsGetValue(DWORD param_1)

{
  FARPROC pFVar1;

  pFVar1 = FUN_10007397(2,"FlsGetValue",(int *)&DAT_10011cd0,(int *)"FlsGetValue");
  if (pFVar1 == (FARPROC)0x0) {
    TlsGetValue(param_1);
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)();
    (*pFVar1)();
  }
  return;
}



/* VA 10007533 */

/* Library Function - Single Match
    ___vcrt_FlsSetValue

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___vcrt_FlsSetValue(DWORD param_1,LPVOID param_2)

{
  FARPROC pFVar1;

  pFVar1 = FUN_10007397(3,"FlsSetValue",(int *)&DAT_10011ce4,(int *)"FlsSetValue");
  if (pFVar1 == (FARPROC)0x0) {
    TlsSetValue(param_1,param_2);
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)();
    (*pFVar1)();
  }
  return;
}



/* VA 10007571 */

/* Library Function - Single Match
    ___vcrt_InitializeCriticalSectionEx

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
___vcrt_InitializeCriticalSectionEx(LPCRITICAL_SECTION param_1,DWORD param_2,undefined4 param_3)

{
  FARPROC pFVar1;

  pFVar1 = FUN_10007397(4,"InitializeCriticalSectionEx",(int *)&DAT_10011cf8,
                        (int *)"InitializeCriticalSectionEx");
  if (pFVar1 == (FARPROC)0x0) {
    InitializeCriticalSectionAndSpinCount(param_1,param_2);
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1,param_2,param_3);
    (*pFVar1)();
  }
  return;
}



/* VA 100075b8 */

void FUN_100075b8(void)

{
  code *pcVar1;
  int iVar2;

  iVar2 = ___vcrt_getptd();
  pcVar1 = *(code **)(iVar2 + 4);
  if (pcVar1 != (code *)0x0) {
    (*(code *)PTR_guard_check_icall_1001116c)();
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_100090dc();
}



/* VA 100075d5 */

/* Library Function - Single Match
    public: static int __cdecl __FrameHandler3::GetCurrentState(struct EHRegistrationNode *,void
   *,struct _s_FuncInfo const *)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl
__FrameHandler3::GetCurrentState(EHRegistrationNode *param_1,void *param_2,_s_FuncInfo *param_3)

{
  if (param_3->maxState < 0x81) {
    return (int)(char)param_1[8];
  }
  return *(int *)(param_1 + 8);
}



/* VA 100075f2 */

/* Library Function - Single Match
    public: static void __cdecl __FrameHandler3::SetState(struct EHRegistrationNode *,struct
   _s_FuncInfo const *,int)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __FrameHandler3::SetState(EHRegistrationNode *param_1,_s_FuncInfo *param_2,int param_3)

{
  *(int *)(param_1 + 8) = param_3;
  return;
}



/* VA 10007600 */

ulonglong __cdecl FUN_10007600(uint *param_1,uint *param_2,uint param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
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
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint *puVar49;
  undefined4 *puVar50;
  undefined4 *puVar51;
  undefined4 *puVar52;
  undefined4 *puVar53;
  uint *puVar54;
  uint uVar55;
  ulonglong uVar56;

  if ((param_2 < param_1) && (param_1 < (uint *)(param_3 + (int)param_2))) {
    puVar50 = (undefined4 *)((int)param_2 + param_3);
    puVar52 = (undefined4 *)((int)param_1 + param_3);
    uVar47 = param_3;
    uVar48 = param_3;
    if (0x1f < param_3) {
      if ((DAT_10019004 >> 1 & 1) == 0) {
        if (((uint)puVar52 & 3) != 0) {
          uVar47 = (uint)puVar52 & 3;
          param_3 = param_3 - uVar47;
          do {
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            puVar50 = (undefined4 *)((int)puVar50 + -1);
            puVar52 = (undefined4 *)((int)puVar52 - 1);
            uVar47 = uVar47 - 1;
            uVar48 = 0;
          } while (uVar47 != 0);
        }
        uVar47 = param_3;
        if (0x1f < param_3) {
          uVar47 = param_3 >> 2;
          while( true ) {
            if (uVar47 == 0) break;
            uVar47 = uVar47 - 1;
            puVar52[-1] = puVar50[-1];
            puVar50 = puVar50 + -1;
            puVar52 = puVar52 + -1;
          }
          switch(param_3 & 3) {
          case 0:
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 1:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 2:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            *(undefined1 *)((int)puVar52 - 2) = *(undefined1 *)((int)puVar50 + -2);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 3:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            *(undefined1 *)((int)puVar52 - 2) = *(undefined1 *)((int)puVar50 + -2);
            *(undefined1 *)((int)puVar52 - 3) = *(undefined1 *)((int)puVar50 + -3);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          }
        }
      }
      else {
        while (puVar51 = puVar50, puVar53 = puVar52, ((uint)puVar52 & 0xf) != 0) {
          puVar50 = (undefined4 *)((int)puVar50 + -1);
          puVar52 = (undefined4 *)((int)puVar52 + -1);
          *(undefined1 *)puVar52 = *(undefined1 *)puVar50;
          uVar47 = uVar47 - 1;
        }
        do {
          puVar50 = puVar51;
          puVar52 = puVar53;
          if (uVar47 < 0x80) break;
          puVar50 = puVar51 + -0x20;
          puVar52 = puVar53 + -0x20;
          uVar3 = puVar51[-0x1f];
          uVar4 = puVar51[-0x1e];
          uVar5 = puVar51[-0x1d];
          uVar6 = puVar51[-0x1c];
          uVar7 = puVar51[-0x1b];
          uVar8 = puVar51[-0x1a];
          uVar9 = puVar51[-0x19];
          uVar10 = puVar51[-0x18];
          uVar11 = puVar51[-0x17];
          uVar12 = puVar51[-0x16];
          uVar13 = puVar51[-0x15];
          uVar14 = puVar51[-0x14];
          uVar15 = puVar51[-0x13];
          uVar16 = puVar51[-0x12];
          uVar17 = puVar51[-0x11];
          uVar18 = puVar51[-0x10];
          uVar19 = puVar51[-0xf];
          uVar20 = puVar51[-0xe];
          uVar21 = puVar51[-0xd];
          uVar22 = puVar51[-0xc];
          uVar23 = puVar51[-0xb];
          uVar24 = puVar51[-10];
          uVar25 = puVar51[-9];
          uVar26 = puVar51[-8];
          uVar27 = puVar51[-7];
          uVar28 = puVar51[-6];
          uVar29 = puVar51[-5];
          uVar30 = puVar51[-4];
          uVar31 = puVar51[-3];
          uVar32 = puVar51[-2];
          uVar33 = puVar51[-1];
          *puVar52 = *puVar50;
          puVar53[-0x1f] = uVar3;
          puVar53[-0x1e] = uVar4;
          puVar53[-0x1d] = uVar5;
          puVar53[-0x1c] = uVar6;
          puVar53[-0x1b] = uVar7;
          puVar53[-0x1a] = uVar8;
          puVar53[-0x19] = uVar9;
          puVar53[-0x18] = uVar10;
          puVar53[-0x17] = uVar11;
          puVar53[-0x16] = uVar12;
          puVar53[-0x15] = uVar13;
          puVar53[-0x14] = uVar14;
          puVar53[-0x13] = uVar15;
          puVar53[-0x12] = uVar16;
          puVar53[-0x11] = uVar17;
          puVar53[-0x10] = uVar18;
          puVar53[-0xf] = uVar19;
          puVar53[-0xe] = uVar20;
          puVar53[-0xd] = uVar21;
          puVar53[-0xc] = uVar22;
          puVar53[-0xb] = uVar23;
          puVar53[-10] = uVar24;
          puVar53[-9] = uVar25;
          puVar53[-8] = uVar26;
          puVar53[-7] = uVar27;
          puVar53[-6] = uVar28;
          puVar53[-5] = uVar29;
          puVar53[-4] = uVar30;
          puVar53[-3] = uVar31;
          puVar53[-2] = uVar32;
          puVar53[-1] = uVar33;
          uVar47 = uVar47 - 0x80;
          puVar51 = puVar50;
          puVar53 = puVar52;
        } while ((uVar47 & 0xffffff80) != 0);
        puVar51 = puVar50;
        puVar53 = puVar52;
        if (0x1f < uVar47) {
          do {
            puVar50 = puVar51 + -8;
            puVar52 = puVar53 + -8;
            uVar3 = puVar51[-7];
            uVar4 = puVar51[-6];
            uVar5 = puVar51[-5];
            uVar6 = puVar51[-4];
            uVar7 = puVar51[-3];
            uVar8 = puVar51[-2];
            uVar9 = puVar51[-1];
            *puVar52 = *puVar50;
            puVar53[-7] = uVar3;
            puVar53[-6] = uVar4;
            puVar53[-5] = uVar5;
            puVar53[-4] = uVar6;
            puVar53[-3] = uVar7;
            puVar53[-2] = uVar8;
            puVar53[-1] = uVar9;
            uVar47 = uVar47 - 0x20;
            puVar51 = puVar50;
            puVar53 = puVar52;
          } while ((uVar47 & 0xffffffe0) != 0);
        }
      }
    }
    for (; (uVar47 & 0xfffffffc) != 0; uVar47 = uVar47 - 4) {
      puVar52 = puVar52 + -1;
      puVar50 = puVar50 + -1;
      *puVar52 = *puVar50;
    }
    for (; uVar47 != 0; uVar47 = uVar47 - 1) {
      puVar52 = (undefined4 *)((int)puVar52 - 1);
      puVar50 = (undefined4 *)((int)puVar50 + -1);
      *(undefined1 *)puVar52 = *(undefined1 *)puVar50;
    }
    return CONCAT44(uVar48,param_1);
  }
  uVar47 = param_3;
  puVar54 = param_1;
  if (0x1f < param_3) {
    if (param_3 < 0x80) {
      if ((DAT_10019004 >> 1 & 1) != 0) {
LAB_10007acd:
        if (uVar47 == 0) goto LAB_10007b30;
        for (uVar48 = uVar47 >> 5; param_3 = 0, uVar48 != 0; uVar48 = uVar48 - 1) {
          uVar55 = param_2[1];
          uVar2 = param_2[2];
          uVar34 = param_2[3];
          uVar35 = param_2[4];
          uVar36 = param_2[5];
          uVar37 = param_2[6];
          uVar38 = param_2[7];
          *puVar54 = *param_2;
          puVar54[1] = uVar55;
          puVar54[2] = uVar2;
          puVar54[3] = uVar34;
          puVar54[4] = uVar35;
          puVar54[5] = uVar36;
          puVar54[6] = uVar37;
          puVar54[7] = uVar38;
          param_2 = param_2 + 8;
          puVar54 = puVar54 + 8;
        }
        goto LAB_10007afb;
      }
joined_r0x1000782d:
      for (; ((uint)puVar54 & 3) != 0; puVar54 = (uint *)((int)puVar54 + 1)) {
        *(char *)puVar54 = (char)*param_2;
        param_3 = param_3 - 1;
        param_2 = (uint *)((int)param_2 + 1);
      }
    }
    else {
      if ((DAT_100199cc >> 1 & 1) != 0) {
        for (; uVar47 != 0; uVar47 = uVar47 - 1) {
          *(char *)puVar54 = (char)*param_2;
          param_2 = (uint *)((int)param_2 + 1);
          puVar54 = (uint *)((int)puVar54 + 1);
        }
        return CONCAT44(param_3,param_1);
      }
      if (((((uint)param_1 ^ (uint)param_2) & 0xf) == 0) && ((DAT_10019004 >> 1 & 1) != 0)) {
        if (((uint)param_2 & 0xf) != 0) {
          uVar48 = 0x10 - ((uint)param_2 & 0xf);
          param_3 = param_3 - uVar48;
          for (uVar47 = uVar48 & 3; uVar47 != 0; uVar47 = uVar47 - 1) {
            *(char *)puVar54 = (char)*param_2;
            param_2 = (uint *)((int)param_2 + 1);
            puVar54 = (uint *)((int)puVar54 + 1);
          }
          for (uVar48 = uVar48 >> 2; uVar48 != 0; uVar48 = uVar48 - 1) {
            *puVar54 = *param_2;
            param_2 = param_2 + 1;
            puVar54 = puVar54 + 1;
          }
        }
        uVar47 = param_3 & 0x7f;
        for (uVar48 = param_3 >> 7; param_3 = 0, uVar48 != 0; uVar48 = uVar48 - 1) {
          uVar55 = param_2[1];
          uVar2 = param_2[2];
          uVar34 = param_2[3];
          uVar35 = param_2[4];
          uVar36 = param_2[5];
          uVar37 = param_2[6];
          uVar38 = param_2[7];
          uVar39 = param_2[8];
          uVar40 = param_2[9];
          uVar41 = param_2[10];
          uVar42 = param_2[0xb];
          uVar43 = param_2[0xc];
          uVar44 = param_2[0xd];
          uVar45 = param_2[0xe];
          uVar46 = param_2[0xf];
          *puVar54 = *param_2;
          puVar54[1] = uVar55;
          puVar54[2] = uVar2;
          puVar54[3] = uVar34;
          puVar54[4] = uVar35;
          puVar54[5] = uVar36;
          puVar54[6] = uVar37;
          puVar54[7] = uVar38;
          puVar54[8] = uVar39;
          puVar54[9] = uVar40;
          puVar54[10] = uVar41;
          puVar54[0xb] = uVar42;
          puVar54[0xc] = uVar43;
          puVar54[0xd] = uVar44;
          puVar54[0xe] = uVar45;
          puVar54[0xf] = uVar46;
          uVar55 = param_2[0x11];
          uVar2 = param_2[0x12];
          uVar34 = param_2[0x13];
          uVar35 = param_2[0x14];
          uVar36 = param_2[0x15];
          uVar37 = param_2[0x16];
          uVar38 = param_2[0x17];
          uVar39 = param_2[0x18];
          uVar40 = param_2[0x19];
          uVar41 = param_2[0x1a];
          uVar42 = param_2[0x1b];
          uVar43 = param_2[0x1c];
          uVar44 = param_2[0x1d];
          uVar45 = param_2[0x1e];
          uVar46 = param_2[0x1f];
          puVar54[0x10] = param_2[0x10];
          puVar54[0x11] = uVar55;
          puVar54[0x12] = uVar2;
          puVar54[0x13] = uVar34;
          puVar54[0x14] = uVar35;
          puVar54[0x15] = uVar36;
          puVar54[0x16] = uVar37;
          puVar54[0x17] = uVar38;
          puVar54[0x18] = uVar39;
          puVar54[0x19] = uVar40;
          puVar54[0x1a] = uVar41;
          puVar54[0x1b] = uVar42;
          puVar54[0x1c] = uVar43;
          puVar54[0x1d] = uVar44;
          puVar54[0x1e] = uVar45;
          puVar54[0x1f] = uVar46;
          param_2 = param_2 + 0x20;
          puVar54 = puVar54 + 0x20;
        }
        goto LAB_10007acd;
      }
      if (((DAT_100199cc & 1) == 0) || (((uint)param_1 & 3) != 0)) goto joined_r0x1000782d;
      if (((uint)param_2 & 3) == 0) {
        if (((uint)param_1 >> 2 & 1) != 0) {
          uVar47 = *param_2;
          param_3 = param_3 - 4;
          param_2 = param_2 + 1;
          *param_1 = uVar47;
          param_1 = param_1 + 1;
        }
        if (((uint)param_1 >> 3 & 1) != 0) {
          uVar1 = *(undefined8 *)param_2;
          param_3 = param_3 - 8;
          param_2 = param_2 + 2;
          *(undefined8 *)param_1 = uVar1;
          param_1 = param_1 + 2;
        }
        if (((uint)param_2 & 7) == 0) {
          puVar54 = param_2 + -2;
          uVar47 = *param_2;
          uVar48 = param_2[1];
          do {
            puVar49 = puVar54;
            uVar34 = puVar49[4];
            uVar35 = puVar49[5];
            param_3 = param_3 - 0x30;
            uVar36 = puVar49[6];
            uVar37 = puVar49[7];
            uVar38 = puVar49[8];
            uVar39 = puVar49[9];
            uVar55 = puVar49[0xe];
            uVar2 = puVar49[0xf];
            uVar40 = puVar49[10];
            uVar41 = puVar49[0xb];
            uVar42 = puVar49[0xc];
            uVar43 = puVar49[0xd];
            *param_1 = uVar47;
            param_1[1] = uVar48;
            param_1[2] = uVar34;
            param_1[3] = uVar35;
            param_1[4] = uVar36;
            param_1[5] = uVar37;
            param_1[6] = uVar38;
            param_1[7] = uVar39;
            param_1[8] = uVar40;
            param_1[9] = uVar41;
            param_1[10] = uVar42;
            param_1[0xb] = uVar43;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar55;
            uVar48 = uVar2;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xe;
        }
        else if (((uint)param_2 >> 3 & 1) == 0) {
          puVar54 = param_2 + -1;
          uVar47 = *param_2;
          uVar48 = param_2[1];
          uVar55 = param_2[2];
          do {
            puVar49 = puVar54;
            uVar36 = puVar49[4];
            param_3 = param_3 - 0x30;
            uVar37 = puVar49[5];
            uVar38 = puVar49[6];
            uVar39 = puVar49[7];
            uVar40 = puVar49[8];
            uVar2 = puVar49[0xd];
            uVar34 = puVar49[0xe];
            uVar35 = puVar49[0xf];
            uVar41 = puVar49[9];
            uVar42 = puVar49[10];
            uVar43 = puVar49[0xb];
            uVar44 = puVar49[0xc];
            *param_1 = uVar47;
            param_1[1] = uVar48;
            param_1[2] = uVar55;
            param_1[3] = uVar36;
            param_1[4] = uVar37;
            param_1[5] = uVar38;
            param_1[6] = uVar39;
            param_1[7] = uVar40;
            param_1[8] = uVar41;
            param_1[9] = uVar42;
            param_1[10] = uVar43;
            param_1[0xb] = uVar44;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar2;
            uVar48 = uVar34;
            uVar55 = uVar35;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xd;
        }
        else {
          puVar54 = param_2 + -3;
          uVar47 = *param_2;
          do {
            puVar49 = puVar54;
            uVar55 = puVar49[4];
            uVar2 = puVar49[5];
            uVar34 = puVar49[6];
            param_3 = param_3 - 0x30;
            uVar35 = puVar49[7];
            uVar36 = puVar49[8];
            uVar37 = puVar49[9];
            uVar38 = puVar49[10];
            uVar48 = puVar49[0xf];
            uVar39 = puVar49[0xb];
            uVar40 = puVar49[0xc];
            uVar41 = puVar49[0xd];
            uVar42 = puVar49[0xe];
            *param_1 = uVar47;
            param_1[1] = uVar55;
            param_1[2] = uVar2;
            param_1[3] = uVar34;
            param_1[4] = uVar35;
            param_1[5] = uVar36;
            param_1[6] = uVar37;
            param_1[7] = uVar38;
            param_1[8] = uVar39;
            param_1[9] = uVar40;
            param_1[10] = uVar41;
            param_1[0xb] = uVar42;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar48;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xf;
        }
        for (; 0xf < param_3; param_3 = param_3 - 0x10) {
          uVar47 = *puVar49;
          uVar48 = puVar49[1];
          uVar55 = puVar49[2];
          uVar2 = puVar49[3];
          puVar49 = puVar49 + 4;
          *param_1 = uVar47;
          param_1[1] = uVar48;
          param_1[2] = uVar55;
          param_1[3] = uVar2;
          param_1 = param_1 + 4;
        }
        if ((param_3 >> 2 & 1) != 0) {
          uVar47 = *puVar49;
          param_3 = param_3 - 4;
          puVar49 = puVar49 + 1;
          *param_1 = uVar47;
          param_1 = param_1 + 1;
        }
        if ((param_3 >> 3 & 1) != 0) {
          param_3 = param_3 - 8;
          *(undefined8 *)param_1 = *(undefined8 *)puVar49;
        }
                    /* WARNING: Could not recover jumptable at 0x10007825. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar56 = (*(code *)(&switchD_10007855::switchdataD_10007864)[param_3])();
        return uVar56;
      }
    }
    uVar47 = param_3;
    if (0x1f < param_3) {
      for (uVar47 = param_3 >> 2; uVar47 != 0; uVar47 = uVar47 - 1) {
        *puVar54 = *param_2;
        param_2 = param_2 + 1;
        puVar54 = puVar54 + 1;
      }
      switch(param_3 & 3) {
      case 0:
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 1:
        *(char *)puVar54 = (char)*param_2;
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 2:
        *(char *)puVar54 = (char)*param_2;
        *(undefined1 *)((int)puVar54 + 1) = *(undefined1 *)((int)param_2 + 1);
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 3:
        *(char *)puVar54 = (char)*param_2;
        *(undefined1 *)((int)puVar54 + 1) = *(undefined1 *)((int)param_2 + 1);
        *(undefined1 *)((int)puVar54 + 2) = *(undefined1 *)((int)param_2 + 2);
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      }
    }
  }
LAB_10007afb:
  if ((uVar47 & 0x1f) != 0) {
    for (uVar48 = (uVar47 & 0x1f) >> 2; uVar48 != 0; uVar48 = uVar48 - 1) {
      param_3 = *param_2;
      *puVar54 = param_3;
      puVar54 = puVar54 + 1;
      param_2 = param_2 + 1;
    }
    for (uVar47 = uVar47 & 3; uVar47 != 0; uVar47 = uVar47 - 1) {
      *(char *)puVar54 = (char)*param_2;
      param_2 = (uint *)((int)param_2 + 1);
      puVar54 = (uint *)((int)puVar54 + 1);
    }
  }
LAB_10007b30:
  return CONCAT44(param_3,param_1);
}



/* VA 10007b80 */

undefined4 __fastcall FUN_10007b80(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;

  DAT_10019028 = param_1;
  DAT_10019024 = in_EAX;
  DAT_1001902c = unaff_EBP;
  return in_EAX;
}



/* VA 10007b90 */

/* Library Function - Single Match
    __NLG_Notify

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __NLG_Notify(ulong param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;

  DAT_10019028 = param_1;
  DAT_10019024 = in_EAX;
  DAT_1001902c = unaff_EBP;
  return;
}



/* VA 10007bb0 */

void FUN_10007bb0(void)

{
  code *in_EAX;

  (*in_EAX)();
  return;
}



/* VA 10007bc0 */

/* Library Function - Single Match
    _abort

   Library: Visual Studio 2019 Release */

void __cdecl _abort(void)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;

  iVar2 = ___acrt_get_sigabrt_handler();
  if (iVar2 != 0) {
    FUN_1000934c(0x16);
  }
  if ((DAT_10019030 & 2) != 0) {
    BVar3 = IsProcessorFeaturePresent(0x17);
    if (BVar3 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)();
    }
    ___acrt_call_reportfault(3,0x40000015,1);
  }
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* VA 10007c04 */

int * __thiscall FUN_10007c04(void *this,int *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined *puVar3;
  __acrt_ptd *p_Var4;
  undefined *puVar5;

  *(undefined1 *)((int)this + 0xc) = 0;
  piVar1 = (int *)((int)this + 4);
  if (param_1 == (int *)0x0) {
    puVar3 = PTR_PTR_10019108;
    puVar5 = PTR_DAT_1001910c;
    if (DAT_10019f08 != 0) {
      p_Var4 = FUN_10009958();
      *(__acrt_ptd **)this = p_Var4;
      *piVar1 = *(int *)(p_Var4 + 0x4c);
      *(int *)((int)this + 8) = *(int *)(p_Var4 + 0x48);
      FUN_10009c43((int)p_Var4,piVar1);
      FUN_10009ca1(*(int *)this,(int *)((int)this + 8));
      uVar2 = *(uint *)(*(int *)this + 0x350);
      if ((uVar2 & 2) != 0) {
        return this;
      }
      *(uint *)(*(int *)this + 0x350) = uVar2 | 2;
      *(undefined1 *)((int)this + 0xc) = 1;
      return this;
    }
  }
  else {
    puVar3 = (undefined *)*param_1;
    puVar5 = (undefined *)param_1[1];
  }
  *piVar1 = (int)puVar3;
  *(undefined **)((int)this + 8) = puVar5;
  return this;
}



/* VA 10007c86 */

void __cdecl FUN_10007c86(byte *param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;

  do {
    uVar1 = (uint)*param_1;
    param_1 = param_1 + 1;
    if (uVar1 - 0x41 < 0x1a) {
      uVar1 = uVar1 + 0x20;
    }
    uVar2 = (uint)*param_2;
    param_2 = param_2 + 1;
    if (uVar2 - 0x41 < 0x1a) {
      uVar2 = uVar2 + 0x20;
    }
  } while ((uVar1 == uVar2) && (uVar1 != 0));
  return;
}



/* VA 10007cbf */

int __cdecl FUN_10007cbf(byte *param_1,byte *param_2)

{
  __acrt_ptd *p_Var1;
  int iVar2;

  if (DAT_10019f08 != 0) {
    iVar2 = FUN_10007d08(param_1,param_2,(int *)0x0);
    return iVar2;
  }
  if ((param_1 != (byte *)0x0) && (param_2 != (byte *)0x0)) {
    iVar2 = FUN_10007c86(param_1,param_2);
    return iVar2;
  }
  p_Var1 = FUN_100095db();
  *(undefined4 *)p_Var1 = 0x16;
  FUN_100080a4();
  return 0x7fffffff;
}



/* VA 10007d08 */

int __cdecl FUN_10007d08(byte *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  __acrt_ptd *p_Var2;
  int iVar3;
  uint uVar4;
  int local_14;
  int local_10;
  char local_8;

  if (param_1 == (byte *)0x0) {
    p_Var2 = FUN_100095db();
    *(undefined4 *)p_Var2 = 0x16;
    FUN_100080a4();
    iVar3 = 0x7fffffff;
  }
  else if (param_2 == (byte *)0x0) {
    p_Var2 = FUN_100095db();
    *(undefined4 *)p_Var2 = 0x16;
    FUN_100080a4();
    iVar3 = 0x7fffffff;
  }
  else {
    FUN_10007c04(&local_14,param_3);
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      uVar4 = (uint)*(byte *)((uint)bVar1 + *(int *)(local_10 + 0x94));
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar3 = uVar4 - *(byte *)((uint)bVar1 + *(int *)(local_10 + 0x94));
      if (iVar3 != 0) break;
    } while (uVar4 != 0);
    if (local_8 != '\0') {
      *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
    }
  }
  return iVar3;
}



/* VA 10007d98 */

undefined4 * __thiscall FUN_10007d98(void *this,undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;

  *(undefined1 *)((int)this + 0x14) = 0;
  *(undefined4 *)this = 0;
  *(undefined1 *)((int)this + 8) = 0;
  *(undefined1 *)((int)this + 0x1c) = 0;
  *(undefined1 *)((int)this + 0x24) = 0;
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = PTR_PTR_10019108;
    puVar2 = PTR_DAT_1001910c;
    if (DAT_10019f08 != 0) {
      return this;
    }
  }
  else {
    puVar1 = (undefined *)*param_1;
    puVar2 = (undefined *)param_1[1];
  }
  *(undefined1 *)((int)this + 0x14) = 1;
  *(undefined **)((int)this + 0x10) = puVar2;
  *(undefined **)((int)this + 0xc) = puVar1;
  return this;
}



/* VA 10007de0 */

void __fastcall FUN_10007de0(int *param_1)

{
  int iVar1;
  int iVar2;

  if ((char)param_1[5] == '\x02') {
    *(uint *)(*param_1 + 0x350) = *(uint *)(*param_1 + 0x350) & 0xfffffffd;
  }
  if ((char)param_1[7] != '\0') {
    iVar1 = param_1[6];
    iVar2 = FUN_10007e8b(param_1);
    *(int *)(iVar2 + 0x10) = iVar1;
  }
  if ((char)param_1[9] != '\0') {
    iVar1 = param_1[8];
    iVar2 = FUN_10007e8b(param_1);
    *(int *)(iVar2 + 0x14) = iVar1;
  }
  return;
}



/* VA 10007e1c */

undefined4 __fastcall FUN_10007e1c(int param_1)

{
  DWORD dwErrCode;

  if (*(char *)(param_1 + 8) == '\0') {
    dwErrCode = GetLastError();
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 8) = 1;
    SetLastError(dwErrCode);
    return 0;
  }
  return *(undefined4 *)(param_1 + 4);
}



/* VA 10007e45 */

__acrt_ptd * __fastcall FUN_10007e45(undefined4 *param_1)

{
  int iVar1;
  __acrt_ptd *p_Var2;
  undefined4 *local_8;

  local_8 = param_1;
  local_8 = (undefined4 *)GetLastError();
  if (*(char *)(param_1 + 2) == '\0') {
    iVar1 = 0;
    *(undefined1 *)(param_1 + 2) = 1;
    param_1[1] = 0;
  }
  else {
    iVar1 = param_1[1];
  }
  p_Var2 = FUN_10009b5a(&local_8,iVar1);
  *param_1 = p_Var2;
  SetLastError((DWORD)local_8);
  return p_Var2;
}



/* VA 10007e8b */

int __fastcall FUN_10007e8b(int *param_1)

{
  __acrt_ptd *p_Var1;

  if (*param_1 == 0) {
    p_Var1 = FUN_10007e45(param_1);
    if (p_Var1 == (__acrt_ptd *)0x0) {
                    /* WARNING: Subroutine does not return */
      _abort();
    }
  }
  return *param_1;
}



/* VA 10007ea8 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    ___acrt_call_reportfault

   Library: Visual Studio 2019 Release */

void __cdecl ___acrt_call_reportfault(int param_1,DWORD param_2,DWORD param_3)

{
  BOOL BVar1;
  LONG LVar2;
  _EXCEPTION_POINTERS local_32c;
  EXCEPTION_RECORD local_324;
  undefined4 local_2d4 [39];

  if (param_1 != -1) {
    FUN_10005719();
  }
  _memset(&local_324,0,0x50);
  _memset(local_2d4,0,0x2cc);
  local_32c.ExceptionRecord = &local_324;
  local_32c.ContextRecord = (PCONTEXT)local_2d4;
  local_2d4[0] = 0x10001;
  local_324.ExceptionCode = param_2;
  local_324.ExceptionFlags = param_3;
  BVar1 = IsDebuggerPresent();
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  LVar2 = UnhandledExceptionFilter(&local_32c);
  if (((LVar2 == 0) && (BVar1 == 0)) && (param_1 != -1)) {
    FUN_10005719();
  }
  return;
}



/* VA 10007fe1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10007fe1(undefined4 param_1)

{
  _DAT_10019db0 = param_1;
  return;
}



/* VA 10007ff0 */

void __cdecl
FUN_10007ff0(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  int local_2c [10];

  FUN_10007d98(local_2c,(undefined4 *)0x0);
  FUN_10008027(param_1,param_2,param_3,param_4,param_5,local_2c);
  FUN_10007de0(local_2c);
  return;
}



/* VA 10008027 */

void __cdecl
FUN_10008027(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5,
            int *param_6)

{
  __acrt_ptd *p_Var1;
  int iVar2;
  byte bVar3;
  code *pcVar4;

  p_Var1 = (__acrt_ptd *)*param_6;
  if (((p_Var1 == (__acrt_ptd *)0x0) &&
      (p_Var1 = FUN_10007e45(param_6), p_Var1 == (__acrt_ptd *)0x0)) ||
     (pcVar4 = *(code **)(p_Var1 + 0x35c), pcVar4 == (code *)0x0)) {
    iVar2 = FUN_10007e1c((int)param_6);
    bVar3 = (byte)DAT_10019008 & 0x1f;
    pcVar4 = (code *)((*(uint *)(&DAT_10019db0 + iVar2 * 4) ^ DAT_10019008) >> bVar3 |
                     (*(uint *)(&DAT_10019db0 + iVar2 * 4) ^ DAT_10019008) << 0x20 - bVar3);
    if (pcVar4 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson(param_1,param_2,param_3,param_4,param_5);
    }
  }
  (*(code *)PTR_guard_check_icall_1001116c)(param_1,param_2,param_3,param_4,param_5);
  (*pcVar4)();
  return;
}



/* VA 100080a4 */

void FUN_100080a4(void)

{
  FUN_10007ff0((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  return;
}



/* VA 100080b4 */

void FUN_100080b4(void)

{
  FUN_10007ff0((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}



/* VA 100080d1 */

/* Library Function - Single Match
    __invoke_watson

   Library: Visual Studio 2019 Release */

void __cdecl
__invoke_watson(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  code *pcVar1;
  BOOL BVar2;
  HANDLE hProcess;
  UINT uExitCode;

  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  ___acrt_call_reportfault(2,0xc0000417,1);
  uExitCode = 0xc0000417;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



/* VA 10008110 */

/* Library Function - Single Match
    _strncmp

   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;

  if (_MaxCount != 0) {
    iVar3 = (int)_Str1 - (int)_Str2;
    do {
      if (((uint)_Str2 & 3) == 0) {
        while ((((uint)(iVar3 + (int)_Str2) & 0xfff) < 0xffd &&
               (uVar2 = *(uint *)(iVar3 + (int)_Str2), uVar2 == *(uint *)_Str2))) {
          bVar4 = _MaxCount < 4;
          _MaxCount = _MaxCount - 4;
          if (bVar4 || _MaxCount == 0) {
            return 0;
          }
          _Str2 = (char *)((int)_Str2 + 4);
          if ((~uVar2 & uVar2 + 0xfefefeff & 0x80808080) != 0) {
            return 0;
          }
        }
      }
      bVar1 = *(byte *)(iVar3 + (int)_Str2);
      if (bVar1 != (byte)*(uint *)_Str2) {
        return -(uint)(bVar1 < (byte)*(uint *)_Str2) | 1;
      }
      if (bVar1 == 0) {
        return 0;
      }
      _Str2 = (char *)((int)_Str2 + 1);
      bVar4 = _MaxCount != 0;
      _MaxCount = _MaxCount - 1;
    } while (bVar4 && _MaxCount != 0);
  }
  return 0;
}



/* VA 10008188 */

uint __cdecl FUN_10008188(uint param_1)

{
  byte bVar1;

  bVar1 = (byte)DAT_10019008 & 0x1f;
  return (param_1 ^ DAT_10019008) >> bVar1 | (param_1 ^ DAT_10019008) << 0x20 - bVar1;
}



/* VA 100081a3 */

void __cdecl FUN_100081a3(undefined4 param_1)

{
  DAT_10019db4 = param_1;
  return;
}



/* VA 100081b2 */

bool __cdecl FUN_100081b2(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  bool bVar3;

  pcVar1 = (code *)FUN_100081de();
  if (pcVar1 == (code *)0x0) {
    bVar3 = false;
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1);
    iVar2 = (*pcVar1)();
    bVar3 = iVar2 != 0;
  }
  return bVar3;
}



/* VA 100081de */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

uint FUN_100081de(void)

{
  uint uVar1;
  undefined4 local_14;

  ___acrt_lock(0);
  uVar1 = FUN_10008188(DAT_10019db4);
  FUN_1000822c();
  ExceptionList = local_14;
  return uVar1;
}



/* VA 1000822c */

void FUN_1000822c(void)

{
  ___acrt_unlock(0);
  return;
}



/* VA 10008235 */

void FUN_10008235(SIZE_T param_1)

{
  __malloc_base(param_1);
  return;
}



/* VA 10008240 */

/* Library Function - Single Match
    __seh_filter_dll

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __cdecl __seh_filter_dll(int param_1,undefined4 param_2)

{
  undefined4 uVar1;

  if (param_1 != -0x1f928c9d) {
    return 0;
  }
  uVar1 = FUN_10008260(0xe06d7363,param_2);
  return uVar1;
}



/* VA 10008260 */

undefined4 __cdecl FUN_10008260(uint param_1,undefined4 param_2)

{
  uint *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  __acrt_ptd *p_Var5;
  undefined4 uVar6;
  uint *puVar7;
  uint *puVar8;

  p_Var5 = FUN_10009aa9();
  if (p_Var5 != (__acrt_ptd *)0x0) {
    puVar1 = *(uint **)p_Var5;
    for (puVar7 = puVar1; puVar7 != puVar1 + 0x24; puVar7 = puVar7 + 3) {
      if (*puVar7 == param_1) {
        if (puVar7 == (uint *)0x0) {
          return 0;
        }
        pcVar2 = (code *)puVar7[2];
        if (pcVar2 == (code *)0x0) {
          return 0;
        }
        if (pcVar2 == (code *)0x5) {
          puVar7[2] = 0;
          return 1;
        }
        if (pcVar2 != (code *)0x1) {
          uVar3 = *(undefined4 *)(p_Var5 + 4);
          *(undefined4 *)(p_Var5 + 4) = param_2;
          if (puVar7[1] == 8) {
            for (puVar8 = puVar1 + 9; puVar8 != puVar1 + 0x24; puVar8 = puVar8 + 3) {
              puVar8[2] = 0;
            }
            uVar4 = *(undefined4 *)(p_Var5 + 8);
            uVar6 = uVar4;
            if (*puVar7 < 0xc0000092) {
              if (*puVar7 == 0xc0000091) {
                uVar6 = 0x84;
              }
              else if (*puVar7 == 0xc000008d) {
                uVar6 = 0x82;
              }
              else if (*puVar7 == 0xc000008e) {
                uVar6 = 0x83;
              }
              else if (*puVar7 == 0xc000008f) {
                uVar6 = 0x86;
              }
              else {
                if (*puVar7 != 0xc0000090) goto LAB_10008374;
                uVar6 = 0x81;
              }
LAB_10008371:
              *(undefined4 *)(p_Var5 + 8) = uVar6;
            }
            else {
              if (*puVar7 == 0xc0000092) {
                uVar6 = 0x8a;
                goto LAB_10008371;
              }
              if (*puVar7 == 0xc0000093) {
                uVar6 = 0x85;
                goto LAB_10008371;
              }
              if (*puVar7 == 0xc00002b4) {
                uVar6 = 0x8e;
                goto LAB_10008371;
              }
              if (*puVar7 == 0xc00002b5) {
                uVar6 = 0x8d;
                goto LAB_10008371;
              }
            }
LAB_10008374:
            (*(code *)PTR_guard_check_icall_1001116c)(8,uVar6);
            (*pcVar2)();
            *(undefined4 *)(p_Var5 + 8) = uVar4;
          }
          else {
            puVar7[2] = 0;
            (*(code *)PTR_guard_check_icall_1001116c)(puVar7[1]);
            (*pcVar2)();
          }
          *(undefined4 *)(p_Var5 + 4) = uVar3;
        }
        return 0xffffffff;
      }
    }
  }
  return 0;
}



/* VA 100083a6 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_03b1d95aef87969028cfba75ccab2455>,class <lambda_6e4b09c48022b2350581041d5f6b0c4c> &,class
   <lambda_22bdf7517842c4b3e53723af5aa32b9e> >(class <lambda_03b1d95aef87969028cfba75ccab2455>
   &&,class <lambda_6e4b09c48022b2350581041d5f6b0c4c> &,class
   <lambda_22bdf7517842c4b3e53723af5aa32b9e> &&)
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_4fdada1b837b2abbf20876fac97688ad>,class <lambda_b57350f2640456a0859d250846f69caf> &,class
   <lambda_eed5e4f92b5b7d55fa22c48c484aaa54> >(class <lambda_4fdada1b837b2abbf20876fac97688ad>
   &&,class <lambda_b57350f2640456a0859d250846f69caf> &,class
   <lambda_eed5e4f92b5b7d55fa22c48c484aaa54> &&)
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_ceb1ee4838e85a9d631eb091e2fbe199>,class <lambda_ae742caa10f662c28703da3d2ea5e57e> &,class
   <lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> >(class <lambda_ceb1ee4838e85a9d631eb091e2fbe199>
   &&,class <lambda_ae742caa10f662c28703da3d2ea5e57e> &,class
   <lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> &&)

   Library: Visual Studio 2019 Release */

void operator()<>(int *param_1,undefined4 *param_2)

{
  undefined4 local_14;

  ___acrt_lock(*param_1);
  FUN_100083f3(param_2);
  FUN_100083e7();
  ExceptionList = local_14;
  return;
}



/* VA 100083e7 */

void FUN_100083e7(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 100083f3 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

void __fastcall FUN_100083f3(undefined4 *param_1)

{
  code *pcVar1;
  void *local_14;

  if (DAT_10019dc0 != '\0') {
    ExceptionList = local_14;
    return;
  }
  LOCK();
  DAT_10019db8 = 1;
  UNLOCK();
  if (*(int *)*param_1 == 0) {
    if (DAT_10019dbc != DAT_10019008) {
      pcVar1 = (code *)FUN_10008188(DAT_10019dbc);
      (*(code *)PTR_guard_check_icall_1001116c)(0,0,0);
      (*pcVar1)();
    }
  }
  else if (*(int *)*param_1 != 1) goto LAB_10008464;
  FUN_10008e84();
LAB_10008464:
  if (*(int *)*param_1 == 0) {
    FUN_10009083((undefined4 *)&DAT_10011194,(undefined4 *)&DAT_100111a4);
  }
  FUN_10009083((undefined4 *)&DAT_100111a8,(undefined4 *)&DAT_100111ac);
  if (*(int *)param_1[1] == 0) {
    DAT_10019dc0 = '\x01';
    *(undefined1 *)param_1[2] = 1;
  }
  ExceptionList = local_14;
  return;
}



/* VA 100084db */

void __cdecl FUN_100084db(UINT param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  undefined4 *local_28;
  int *local_24;
  undefined1 *local_20;
  int local_1c [2];
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10010e6c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_3 == 0) {
    uVar2 = FUN_100085a3();
    if ((char)uVar2 != '\0') {
      FUN_100085fe(param_1);
    }
  }
  local_28 = &param_2;
  local_11 = 0;
  local_24 = &param_3;
  local_20 = &local_11;
  local_8 = 0;
  local_1c[1] = 2;
  local_1c[0] = 2;
  operator()<>(local_1c,&local_28);
  if (param_3 != 0) {
    ExceptionList = local_10;
    return;
  }
  FUN_10008572(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* VA 10008572 */

void FUN_10008572(UINT param_1)

{
  char cVar1;
  HANDLE hProcess;
  UINT uExitCode;

  cVar1 = FUN_100085e5();
  if (cVar1 != '\0') {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  FUN_100085fe(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



/* VA 100085a3 */

uint FUN_100085a3(void)

{
  HMODULE pHVar1;
  int *piVar2;

  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 != (HMODULE)0x0) && ((short)pHVar1->unused == 0x5a4d)) &&
      (piVar2 = (int *)((int)&pHVar1->unused + pHVar1[0xf].unused), *piVar2 == 0x4550)) &&
     ((pHVar1 = (HMODULE)0x10b, (short)piVar2[6] == 0x10b && (0xe < (uint)piVar2[0x1d])))) {
    return CONCAT31(1,piVar2[0x3a] != 0);
  }
  return (uint)pHVar1 & 0xffffff00;
}



/* VA 100085e5 */

char FUN_100085e5(void)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;

  bVar1 = FUN_10009eb2();
  if (CONCAT31(extraout_var,bVar1) != 1) {
    uVar2 = FUN_10009e8d();
    return '\x01' - ((char)uVar2 != '\0');
  }
  return '\0';
}



/* VA 100085fe */

void __cdecl FUN_100085fe(undefined4 param_1)

{
  uint uVar1;
  BOOL BVar2;
  FARPROC pFVar3;
  HMODULE local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;

  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10010e89;
  local_10 = ExceptionList;
  uVar1 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (HMODULE)0x0;
  BVar2 = GetModuleHandleExW(0,L"mscoree.dll",&local_14);
  if (BVar2 != 0) {
    pFVar3 = GetProcAddress(local_14,"CorExitProcess");
    if (pFVar3 != (FARPROC)0x0) {
      (*(code *)PTR_guard_check_icall_1001116c)(param_1,uVar1);
      (*pFVar3)();
    }
  }
  if (local_14 != (HMODULE)0x0) {
    FreeLibrary(local_14);
  }
  ExceptionList = local_10;
  return;
}



/* VA 10008680 */

void __cdecl FUN_10008680(undefined4 param_1)

{
  DAT_10019dbc = param_1;
  return;
}



/* VA 1000869e */

/* Library Function - Single Match
    __exit

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __exit(int _Code)

{
  FUN_100084db(_Code,2,0);
  return;
}



/* VA 100086b4 */

undefined4 FUN_100086b4(void)

{
  return DAT_10019db8;
}



/* VA 100086bb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_100086bb(int param_1)

{
  int *piVar1;
  int iVar2;
  __acrt_ptd *p_Var3;
  int *piVar4;
  byte *pbVar5;
  uint local_10;
  int *local_c;
  uint local_8;

  if (param_1 == 0) {
    iVar2 = 0;
  }
  else if ((param_1 == 2) || (param_1 == 1)) {
    ___acrt_initialize_multibyte();
    ___acrt_GetModuleFileNameA((HMODULE)0x0,&DAT_10019dc8,0x104);
    _DAT_1001a078 = &DAT_10019dc8;
    if ((DAT_1001a088 == (byte *)0x0) || (pbVar5 = DAT_1001a088, *DAT_1001a088 == 0)) {
      pbVar5 = &DAT_10019dc8;
    }
    local_8 = 0;
    local_10 = 0;
    FUN_100087f8(pbVar5,(undefined4 *)0x0,(byte *)0x0,(int *)&local_8,(int *)&local_10);
    piVar4 = ___acrt_allocate_buffer_for_argv(local_8,local_10,1);
    if (piVar4 == (int *)0x0) {
      p_Var3 = FUN_100095db();
      iVar2 = 0xc;
      *(undefined4 *)p_Var3 = 0xc;
    }
    else {
      FUN_100087f8(pbVar5,piVar4,(byte *)(piVar4 + local_8),(int *)&local_8,(int *)&local_10);
      if (param_1 != 1) {
        local_c = (int *)0x0;
        iVar2 = FUN_1000a793(piVar4,&local_c);
        piVar1 = local_c;
        if (iVar2 == 0) {
          _DAT_1001a07c = 0;
          iVar2 = *local_c;
          while (iVar2 != 0) {
            local_c = local_c + 1;
            _DAT_1001a07c = _DAT_1001a07c + 1;
            iVar2 = *local_c;
          }
          local_c = (int *)0x0;
          _DAT_1001a080 = piVar1;
          FUN_10009f36((LPVOID)0x0);
          iVar2 = 0;
        }
        else {
          FUN_10009f36(local_c);
        }
        local_c = (int *)0x0;
        FUN_10009f36(piVar4);
        return iVar2;
      }
      _DAT_1001a07c = local_8 - 1;
      iVar2 = 0;
      _DAT_1001a080 = piVar4;
    }
    FUN_10009f36((LPVOID)0x0);
  }
  else {
    p_Var3 = FUN_100095db();
    iVar2 = 0x16;
    *(undefined4 *)p_Var3 = 0x16;
    FUN_100080a4();
  }
  return iVar2;
}



/* VA 100087f8 */

void __cdecl FUN_100087f8(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;

  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  bVar1 = false;
  bVar2 = false;
  do {
    if (*param_1 == 0x22) {
      bVar1 = !bVar1;
      bVar3 = 0x22;
      pbVar6 = param_1 + 1;
      bVar2 = bVar1;
    }
    else {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar3 = *param_1;
      pbVar6 = param_1 + 1;
      iVar5 = FUN_1000b1e9(bVar3);
      if (iVar5 != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar3 == 0) {
        pbVar6 = pbVar6 + -1;
        goto LAB_10008887;
      }
    }
    param_1 = pbVar6;
  } while ((bVar2) || ((bVar3 != 0x20 && (bVar3 != 9))));
  if (param_3 != (byte *)0x0) {
    param_3[-1] = 0;
  }
LAB_10008887:
  bVar1 = false;
  while (bVar3 = *pbVar6, bVar3 != 0) {
    while ((bVar3 == 0x20 || (bVar3 == 9))) {
      pbVar6 = pbVar6 + 1;
      bVar3 = *pbVar6;
    }
    if (bVar3 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar2 = true;
      uVar4 = 0;
      for (; *pbVar6 == 0x5c; pbVar6 = pbVar6 + 1) {
        uVar4 = uVar4 + 1;
      }
      if (*pbVar6 == 0x22) {
        if ((uVar4 & 1) == 0) {
          if ((bVar1) && (pbVar6[1] == 0x22)) {
            pbVar6 = pbVar6 + 1;
          }
          else {
            bVar2 = false;
            bVar1 = !bVar1;
          }
        }
        uVar4 = uVar4 >> 1;
      }
      while (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar3 = *pbVar6;
      if ((bVar3 == 0) || ((!bVar1 && ((bVar3 == 0x20 || (bVar3 == 9)))))) break;
      if (bVar2) {
        if (param_3 != (byte *)0x0) {
          *param_3 = bVar3;
          param_3 = param_3 + 1;
        }
        iVar5 = FUN_1000b1e9(*pbVar6);
        if (iVar5 != 0) {
          pbVar6 = pbVar6 + 1;
          *param_5 = *param_5 + 1;
          if (param_3 != (byte *)0x0) {
            *param_3 = *pbVar6;
            param_3 = param_3 + 1;
          }
        }
        *param_5 = *param_5 + 1;
      }
      pbVar6 = pbVar6 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



/* VA 1000896c */

/* Library Function - Single Match
    ___acrt_allocate_buffer_for_argv

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID __cdecl ___acrt_allocate_buffer_for_argv(uint param_1,uint param_2,uint param_3)

{
  LPVOID pvVar1;

  if ((param_1 < 0x3fffffff) && (param_2 < (uint)(0xffffffff / (ulonglong)param_3))) {
    if (param_2 * param_3 < ~(param_1 * 4)) {
      pvVar1 = __calloc_base(param_1 * 4 + param_2 * param_3,1);
      FUN_10009f36((LPVOID)0x0);
      return pvVar1;
    }
  }
  return (LPVOID)0x0;
}



/* VA 100089bb */

void __cdecl FUN_100089bb(int param_1)

{
  FUN_100086bb(param_1);
  return;
}



/* VA 100089c6 */

undefined4 FUN_100089c6(void)

{
  LPSTR pCVar1;
  undefined4 *puVar2;
  undefined4 uVar3;

  if (DAT_10019ed0 != (undefined4 *)0x0) {
    return 0;
  }
  ___acrt_initialize_multibyte();
  pCVar1 = FUN_1000b40f();
  if (pCVar1 == (LPSTR)0x0) {
    FUN_10009f36((LPVOID)0x0);
    return 0xffffffff;
  }
  puVar2 = FUN_10008a20(pCVar1);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
    DAT_10019ed0 = puVar2;
    DAT_10019edc = puVar2;
  }
  FUN_10009f36((LPVOID)0x0);
  FUN_10009f36(pCVar1);
  return uVar3;
}



/* VA 10008a20 */

undefined4 * __cdecl FUN_10008a20(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *local_8;

  iVar5 = 0;
  cVar1 = *param_1;
  pcVar4 = param_1;
  while (cVar1 != '\0') {
    if (cVar1 != '=') {
      iVar5 = iVar5 + 1;
    }
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    cVar1 = *pcVar4;
  }
  puVar2 = __calloc_base(iVar5 + 1,4);
  local_8 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    FUN_10009f36((LPVOID)0x0);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    for (; *param_1 != '\0'; param_1 = param_1 + (int)pcVar4) {
      pcVar4 = param_1;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar4 = pcVar4 + (1 - (int)(param_1 + 1));
      if (*param_1 != '=') {
        pcVar3 = __calloc_base((uint)pcVar4,1);
        if (pcVar3 == (char *)0x0) {
          free_environment<>(puVar2);
          FUN_10009f36((LPVOID)0x0);
          FUN_10009f36((LPVOID)0x0);
          return (undefined4 *)0x0;
        }
        iVar5 = FUN_10009133(pcVar3,(int)pcVar4,(int)param_1);
        if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        *local_8 = pcVar3;
        local_8 = local_8 + 1;
        FUN_10009f36((LPVOID)0x0);
      }
    }
    FUN_10009f36((LPVOID)0x0);
  }
  return puVar2;
}



/* VA 10008b02 */

/* Library Function - Multiple Matches With Same Base Name
    void __cdecl free_environment<char>(char * * const)
    void __cdecl free_environment<wchar_t>(wchar_t * * const)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl free_environment<>(undefined4 *param_1)

{
  LPVOID pvVar1;
  undefined4 *puVar2;

  if (param_1 != (undefined4 *)0x0) {
    pvVar1 = (LPVOID)*param_1;
    puVar2 = param_1;
    while (pvVar1 != (LPVOID)0x0) {
      FUN_10009f36(pvVar1);
      puVar2 = puVar2 + 1;
      pvVar1 = (LPVOID)*puVar2;
    }
    FUN_10009f36(param_1);
  }
  return;
}



/* VA 10008b31 */

/* Library Function - Multiple Matches With Same Base Name
    void __cdecl uninitialize_environment_internal<char>(char * * &)
    void __cdecl uninitialize_environment_internal<wchar_t>(wchar_t * * &)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl uninitialize_environment_internal<>(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != DAT_10019edc) {
    free_environment<>((undefined4 *)*param_1);
  }
  return;
}



/* VA 10008b4c */

/* Library Function - Multiple Matches With Same Base Name
    void __cdecl uninitialize_environment_internal<char>(char * * &)
    void __cdecl uninitialize_environment_internal<wchar_t>(wchar_t * * &)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl uninitialize_environment_internal<>(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != DAT_10019ed8) {
    free_environment<>((undefined4 *)*param_1);
  }
  return;
}



/* VA 10008b67 */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10008b67(void)

{
  uninitialize_environment_internal<>(&DAT_10019ed0);
  uninitialize_environment_internal<>((undefined4 *)&DAT_10019ed4);
  free_environment<>(DAT_10019edc);
  free_environment<>(DAT_10019ed8);
  return;
}



/* VA 10008bb8 */

undefined4 thunk_FUN_100089c6(void)

{
  LPSTR pCVar1;
  undefined4 *puVar2;
  undefined4 uVar3;

  if (DAT_10019ed0 != (undefined4 *)0x0) {
    return 0;
  }
  ___acrt_initialize_multibyte();
  pCVar1 = FUN_1000b40f();
  if (pCVar1 == (LPSTR)0x0) {
    FUN_10009f36((LPVOID)0x0);
    return 0xffffffff;
  }
  puVar2 = FUN_10008a20(pCVar1);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
    DAT_10019ed0 = puVar2;
    DAT_10019edc = puVar2;
  }
  FUN_10009f36((LPVOID)0x0);
  FUN_10009f36(pCVar1);
  return uVar3;
}



/* VA 10008bbd */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_69a2805e680e0e292e8ba93315fe43a8>,class <lambda_f03950bc5685219e0bcd2087efbe011e> &,class
   <lambda_03fcd07e894ec930e3f35da366ca99d6> >(class <lambda_69a2805e680e0e292e8ba93315fe43a8>
   &&,class <lambda_f03950bc5685219e0bcd2087efbe011e> &,class
   <lambda_03fcd07e894ec930e3f35da366ca99d6> &&)

   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<<lambda_69a2805e680e0e292e8ba93315fe43a8>,<lambda_f03950bc5685219e0bcd2087efbe011e>&,<lambda_03fcd07e894ec930e3f35da366ca99d6>_>
          (__crt_seh_guarded_call<int> *this,<lambda_69a2805e680e0e292e8ba93315fe43a8> *param_1,
          <lambda_f03950bc5685219e0bcd2087efbe011e> *param_2,
          <lambda_03fcd07e894ec930e3f35da366ca99d6> *param_3)

{
  int iVar1;
  undefined4 local_14;

  ___acrt_lock(*(int *)param_1);
  iVar1 = <lambda_f03950bc5685219e0bcd2087efbe011e>::operator()(param_2);
  FUN_10008c0c();
  ExceptionList = local_14;
  return iVar1;
}



/* VA 10008c0c */

void FUN_10008c0c(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 10008c18 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_8e746cf0007f6ed984d6f78af1fec997>,class <lambda_22ebabd17bc4fa466a2aca6d8deb888d> &,class
   <lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e> >(class <lambda_8e746cf0007f6ed984d6f78af1fec997>
   &&,class <lambda_22ebabd17bc4fa466a2aca6d8deb888d> &,class
   <lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e> &&)

   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<<lambda_8e746cf0007f6ed984d6f78af1fec997>,<lambda_22ebabd17bc4fa466a2aca6d8deb888d>&,<lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e>_>
          (__crt_seh_guarded_call<int> *this,<lambda_8e746cf0007f6ed984d6f78af1fec997> *param_1,
          <lambda_22ebabd17bc4fa466a2aca6d8deb888d> *param_2,
          <lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e> *param_3)

{
  int iVar1;
  undefined4 local_14;

  ___acrt_lock(*(int *)param_1);
  iVar1 = FUN_10008c92((undefined4 *)param_2);
  FUN_10008c67();
  ExceptionList = local_14;
  return iVar1;
}



/* VA 10008c67 */

void FUN_10008c67(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 10008c73 */

uint __cdecl FUN_10008c73(uint param_1)

{
  byte bVar1;

  bVar1 = 0x20 - ((byte)DAT_10019008 & 0x1f) & 0x1f;
  return (param_1 >> bVar1 | param_1 << 0x20 - bVar1) ^ DAT_10019008;
}



/* VA 10008c92 */

undefined4 __fastcall FUN_10008c92(undefined4 *param_1)

{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  byte bVar6;
  void *pvVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;

  puVar3 = *(uint **)*param_1;
  if (puVar3 == (uint *)0x0) {
LAB_10008d8c:
    uVar5 = 0xffffffff;
  }
  else {
    bVar6 = (byte)DAT_10019008 & 0x1f;
    puVar10 = (uint *)((puVar3[1] ^ DAT_10019008) >> bVar6 |
                      (puVar3[1] ^ DAT_10019008) << 0x20 - bVar6);
    puVar8 = (uint *)((puVar3[2] ^ DAT_10019008) >> bVar6 |
                     (puVar3[2] ^ DAT_10019008) << 0x20 - bVar6);
    pvVar7 = (void *)((*puVar3 ^ DAT_10019008) >> bVar6 | (*puVar3 ^ DAT_10019008) << 0x20 - bVar6);
    pvVar2 = pvVar7;
    if (puVar10 == puVar8) {
      uVar9 = (int)puVar8 - (int)pvVar7 >> 2;
      uVar4 = 0x200;
      if (uVar9 < 0x201) {
        uVar4 = uVar9;
      }
      uVar4 = uVar4 + uVar9;
      if (uVar4 == 0) {
        uVar4 = 0x20;
      }
      if (uVar4 < uVar9) {
LAB_10008d0a:
        uVar4 = uVar9 + 4;
        pvVar2 = __recalloc_base(pvVar7,uVar4,4);
        FUN_10009f36((LPVOID)0x0);
        if (pvVar2 == (LPVOID)0x0) goto LAB_10008d8c;
      }
      else {
        pvVar2 = __recalloc_base(pvVar7,uVar4,4);
        FUN_10009f36((LPVOID)0x0);
        if (pvVar2 == (LPVOID)0x0) goto LAB_10008d0a;
      }
      uVar1 = DAT_10019008;
      puVar8 = (uint *)((int)pvVar2 + uVar4 * 4);
      puVar10 = (uint *)((int)pvVar2 + uVar9 * 4);
      for (puVar3 = puVar10; puVar3 != puVar8; puVar3 = puVar3 + 1) {
        *puVar3 = uVar1;
      }
    }
    uVar4 = FUN_10008c73(*(uint *)param_1[1]);
    *puVar10 = uVar4;
    uVar4 = FUN_10008c73((uint)pvVar2);
    **(uint **)*param_1 = uVar4;
    uVar4 = FUN_10008c73((uint)(puVar10 + 1));
    *(uint *)(*(int *)*param_1 + 4) = uVar4;
    uVar4 = FUN_10008c73((uint)puVar8);
    *(uint *)(*(int *)*param_1 + 8) = uVar4;
    uVar5 = 0;
  }
  return uVar5;
}



/* VA 10008d94 */

/* Library Function - Single Match
    public: int __thiscall <lambda_f03950bc5685219e0bcd2087efbe011e>::operator()(void)const

   Library: Visual Studio 2019 Release */

int __thiscall
<lambda_f03950bc5685219e0bcd2087efbe011e>::operator()
          (<lambda_f03950bc5685219e0bcd2087efbe011e> *this)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  sbyte sVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;

  uVar1 = DAT_10019008;
  puVar9 = (uint *)**(int **)this;
  if (puVar9 == (uint *)0x0) {
    iVar2 = -1;
  }
  else {
    uVar6 = DAT_10019008 & 0x1f;
    sVar5 = (sbyte)uVar6;
    puVar8 = (uint *)((*puVar9 ^ DAT_10019008) >> sVar5 | (*puVar9 ^ DAT_10019008) << 0x20 - sVar5);
    puVar9 = (uint *)((puVar9[1] ^ DAT_10019008) >> sVar5 |
                     (puVar9[1] ^ DAT_10019008) << 0x20 - sVar5);
    if ((puVar8 != (uint *)0x0) &&
       (uVar3 = DAT_10019008, puVar10 = puVar9, puVar8 != (uint *)0xffffffff)) {
      while (puVar9 = puVar9 + -1, puVar8 <= puVar9) {
        if (*puVar9 != uVar1) {
          uVar3 = *puVar9 ^ uVar3;
          *puVar9 = uVar1;
          (*(code *)PTR_guard_check_icall_1001116c)();
          (*(code *)(uVar3 >> (sbyte)uVar6 | uVar3 << 0x20 - (sbyte)uVar6))();
          uVar6 = DAT_10019008 & 0x1f;
          uVar3 = *(uint *)**(int **)this ^ DAT_10019008;
          sVar5 = (sbyte)uVar6;
          puVar7 = (uint *)(uVar3 >> sVar5 | uVar3 << 0x20 - sVar5);
          uVar3 = ((uint *)**(int **)this)[1] ^ DAT_10019008;
          puVar4 = (uint *)(uVar3 >> sVar5 | uVar3 << 0x20 - sVar5);
          uVar3 = DAT_10019008;
          if ((puVar7 != puVar8) || (puVar4 != puVar10)) {
            puVar9 = puVar4;
            puVar10 = puVar4;
            puVar8 = puVar7;
          }
        }
      }
      if (puVar8 != (uint *)0xffffffff) {
        FUN_10009f36(puVar8);
        uVar3 = DAT_10019008;
      }
      *(uint *)**(undefined4 **)this = uVar3;
      *(uint *)(**(int **)this + 4) = uVar3;
      *(uint *)(**(int **)this + 8) = uVar3;
    }
    iVar2 = 0;
  }
  return iVar2;
}



/* VA 10008e6e */

/* Library Function - Single Match
    __crt_atexit

   Library: Visual Studio 2019 Release */

void __crt_atexit(void)

{
  __register_onexit_function();
  return;
}



/* VA 10008e84 */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10008e84(void)

{
  undefined4 local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  __crt_seh_guarded_call<int> local_11 [9];
  undefined4 local_8;
  undefined4 uStack_4;

  uStack_4 = 0x10;
  local_1c = &stack0x00000004;
  local_8 = 0;
  local_18 = 2;
  local_20 = 2;
  __crt_seh_guarded_call<int>::
  operator()<<lambda_69a2805e680e0e292e8ba93315fe43a8>,<lambda_f03950bc5685219e0bcd2087efbe011e>&,<lambda_03fcd07e894ec930e3f35da366ca99d6>_>
            (local_11,(<lambda_69a2805e680e0e292e8ba93315fe43a8> *)&local_20,
             (<lambda_f03950bc5685219e0bcd2087efbe011e> *)&local_1c,
             (<lambda_03fcd07e894ec930e3f35da366ca99d6> *)&local_18);
  return;
}



/* VA 10008ec2 */

/* Library Function - Single Match
    __initialize_onexit_table

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __cdecl __initialize_onexit_table(int *param_1)

{
  int iVar1;

  iVar1 = DAT_10019008;
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (*param_1 == param_1[2]) {
    *param_1 = DAT_10019008;
    param_1[1] = iVar1;
    param_1[2] = iVar1;
  }
  return 0;
}



/* VA 10008eeb */

/* Library Function - Single Match
    __register_onexit_function

   Library: Visual Studio 2019 Release */

void __register_onexit_function(void)

{
  undefined1 *local_18;
  undefined1 *local_14;
  undefined4 local_10;
  undefined4 local_c;
  __crt_seh_guarded_call<int> local_5;

  local_18 = &stack0x00000004;
  local_14 = &stack0x00000008;
  local_c = 2;
  local_10 = 2;
  __crt_seh_guarded_call<int>::
  operator()<<lambda_8e746cf0007f6ed984d6f78af1fec997>,<lambda_22ebabd17bc4fa466a2aca6d8deb888d>&,<lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e>_>
            (&local_5,(<lambda_8e746cf0007f6ed984d6f78af1fec997> *)&local_10,
             (<lambda_22ebabd17bc4fa466a2aca6d8deb888d> *)&local_18,
             (<lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e> *)&local_c);
  return;
}



/* VA 10008f87 */

/* Library Function - Single Match
    _uninitialize_allocated_memory

   Library: Visual Studio 2019 Release */

undefined1 __cdecl uninitialize_allocated_memory(void)

{
  <lambda_af42a3ee9806e9a7305d451646e05244> local_5;

  <lambda_af42a3ee9806e9a7305d451646e05244>::operator()
            (&local_5,(__crt_multibyte_data **)&DAT_1001a06c);
  return 1;
}



/* VA 10008fee */

/* Library Function - Single Match
    public: void __thiscall <lambda_af42a3ee9806e9a7305d451646e05244>::operator()(struct
   __crt_multibyte_data * &)const

   Library: Visual Studio 2019 Release */

void __thiscall
<lambda_af42a3ee9806e9a7305d451646e05244>::operator()
          (<lambda_af42a3ee9806e9a7305d451646e05244> *this,__crt_multibyte_data **param_1)

{
  int iVar1;

  LOCK();
  iVar1 = *(int *)*param_1 + -1;
  *(int *)*param_1 = iVar1;
  UNLOCK();
  if ((iVar1 == 0) && (*param_1 != (__crt_multibyte_data *)&DAT_10019118)) {
    FUN_10009f36(*param_1);
    *param_1 = (__crt_multibyte_data *)&DAT_10019118;
  }
  return;
}



/* VA 1000901c */

/* Library Function - Single Match
    ___acrt_initialize

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_initialize(void)

{
  ___acrt_execute_initializers(&PTR_LAB_10011de8,&DAT_10011e68);
  return;
}



/* VA 1000902e */

bool FUN_1000902e(void)

{
  __acrt_ptd *p_Var1;

  p_Var1 = FUN_10009aa9();
  return p_Var1 != (__acrt_ptd *)0x0;
}



/* VA 10009039 */

undefined1 FUN_10009039(void)

{
  ___acrt_freeptd();
  return 1;
}



/* VA 10009041 */

/* Library Function - Single Match
    ___acrt_uninitialize

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined1 __cdecl ___acrt_uninitialize(char param_1)

{
  undefined1 uVar1;

  if (param_1 != '\0') {
    if (DAT_1001a384 != 0) {
      __flushall();
    }
    return 1;
  }
  uVar1 = ___acrt_execute_uninitializers(0x10011de8,0x10011e68);
  return uVar1;
}



/* VA 10009071 */

/* Library Function - Single Match
    ___acrt_uninitialize_critical

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 ___acrt_uninitialize_critical(void)

{
  undefined4 uVar1;

  uVar1 = ___acrt_uninitialize_ptd();
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}



/* VA 10009083 */

void __cdecl FUN_10009083(undefined4 *param_1,undefined4 *param_2)

{
  code *pcVar1;

  for (; param_1 != param_2; param_1 = param_1 + 1) {
    pcVar1 = (code *)*param_1;
    if (pcVar1 != (code *)0x0) {
      (*(code *)PTR_guard_check_icall_1001116c)();
      (*pcVar1)();
    }
  }
  return;
}



/* VA 100090ae */

/* Library Function - Single Match
    __initterm_e

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl __initterm_e(undefined4 *param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;

  do {
    if (param_1 == param_2) {
      return 0;
    }
    pcVar1 = (code *)*param_1;
    if (pcVar1 != (code *)0x0) {
      (*(code *)PTR_guard_check_icall_1001116c)();
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    param_1 = param_1 + 1;
  } while( true );
}



/* VA 100090dc */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

void FUN_100090dc(void)

{
  code *pcVar1;
  __acrt_ptd *p_Var2;

  p_Var2 = FUN_10009958();
  pcVar1 = *(code **)(p_Var2 + 0xc);
  if (pcVar1 != (code *)0x0) {
    (*(code *)PTR_guard_check_icall_1001116c)();
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 10009118 */

void __cdecl FUN_10009118(LPVOID param_1)

{
  FUN_10009f36(param_1);
  return;
}



/* VA 10009133 */

undefined4 __cdecl FUN_10009133(char *param_1,int param_2,int param_3)

{
  char cVar1;
  __acrt_ptd *p_Var2;
  char *pcVar3;
  undefined4 uStack_10;

  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    if (param_3 != 0) {
      pcVar3 = param_1;
      do {
        cVar1 = pcVar3[param_3 - (int)param_1];
        *pcVar3 = cVar1;
        pcVar3 = pcVar3 + 1;
        if (cVar1 == '\0') {
          return 0;
        }
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      *param_1 = '\0';
      p_Var2 = FUN_100095db();
      uStack_10 = 0x22;
      goto LAB_10009159;
    }
    *param_1 = '\0';
  }
  p_Var2 = FUN_100095db();
  uStack_10 = 0x16;
LAB_10009159:
  *(undefined4 *)p_Var2 = uStack_10;
  FUN_100080a4();
  return uStack_10;
}



/* VA 1000918d */

void FUN_1000918d(uint param_1,uint param_2)

{
  __calloc_base(param_1,param_2);
  return;
}



/* VA 100091a0 */

void __fastcall FUN_100091a0(int *param_1)

{
  int iVar1;

  iVar1 = FUN_10007e8b(param_1);
  param_1[3] = *(int *)(iVar1 + 0x4c);
  param_1[4] = *(int *)(iVar1 + 0x48);
  FUN_10009c70(iVar1,param_1 + 3,param_1[1]);
  FUN_10009cce(iVar1,param_1 + 4,param_1[1]);
  if ((*(uint *)(iVar1 + 0x350) & 2) == 0) {
    *(uint *)(iVar1 + 0x350) = *(uint *)(iVar1 + 0x350) | 2;
    *(undefined1 *)(param_1 + 5) = 2;
  }
  return;
}



/* VA 100091fb */

/* Library Function - Single Match
    _wcsncmp

   Library: Visual Studio 2019 Release */

int __cdecl _wcsncmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  if (_MaxCount != 0) {
    for (; ((_MaxCount = _MaxCount - 1, _MaxCount != 0 && (*_Str1 != L'\0')) && (*_Str1 == *_Str2));
        _Str1 = _Str1 + 1) {
      _Str2 = _Str2 + 1;
    }
    return (uint)(ushort)*_Str1 - (uint)(ushort)*_Str2;
  }
  return 0;
}



/* VA 10009235 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

uint FUN_10009235(int *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 local_14;

  ___acrt_lock(*param_1);
  bVar1 = (byte)DAT_10019008 & 0x1f;
  uVar2 = DAT_10019f00 ^ DAT_10019008;
  FUN_10009291();
  ExceptionList = local_14;
  return uVar2 >> bVar1 | uVar2 << 0x20 - bVar1;
}



/* VA 10009291 */

void FUN_10009291(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 1000929d */

/* Library Function - Single Match
    void (__cdecl** __cdecl get_global_action_nolock(int))(int)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_void_int ** __cdecl get_global_action_nolock(int param_1)

{
  if (param_1 == 2) {
    return (_func_void_int **)&DAT_10019ef8;
  }
  if (param_1 != 6) {
    if (param_1 == 0xf) {
      return (_func_void_int **)&DAT_10019f04;
    }
    if (param_1 == 0x15) {
      return (_func_void_int **)&DAT_10019efc;
    }
    if (param_1 != 0x16) {
      return (_func_void_int **)0x0;
    }
  }
  return (_func_void_int **)&DAT_10019f00;
}



/* VA 100092df */

/* Library Function - Single Match
    struct __crt_signal_action_t * __cdecl siglookup(int,struct __crt_signal_action_t * const)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

__crt_signal_action_t * __cdecl siglookup(int param_1,__crt_signal_action_t *param_2)

{
  __crt_signal_action_t *p_Var1;

  p_Var1 = param_2 + DAT_10011db0 * 0xc;
  while( true ) {
    if (param_2 == p_Var1) {
      return (__crt_signal_action_t *)0x0;
    }
    if (*(int *)(param_2 + 4) == param_1) break;
    param_2 = param_2 + 0xc;
  }
  return param_2;
}



/* VA 10009307 */

/* Library Function - Single Match
    ___acrt_get_sigabrt_handler

   Library: Visual Studio 2019 Release */

void ___acrt_get_sigabrt_handler(void)

{
  int local_10 [3];

  local_10[1] = 3;
  local_10[0] = 3;
  FUN_10009235(local_10);
  return;
}



/* VA 1000932e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000932e(undefined4 param_1)

{
  _DAT_10019ef8 = param_1;
  _DAT_10019efc = param_1;
  DAT_10019f00 = param_1;
  _DAT_10019f04 = param_1;
  return;
}



/* VA 1000934c */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

undefined4 __cdecl FUN_1000934c(int param_1)

{
  bool bVar1;
  __crt_signal_action_t *p_Var2;
  code *pcVar3;
  __acrt_ptd *p_Var4;
  int iVar5;
  int iVar6;
  __acrt_ptd *p_Var7;
  undefined4 local_38;
  int local_34;
  void *local_14;

  p_Var7 = (__acrt_ptd *)0x0;
  local_38 = 0;
  bVar1 = true;
  if (param_1 < 0xc) {
    if (param_1 != 0xb) {
      if (param_1 == 2) goto LAB_100093d5;
      if (param_1 != 4) {
        if (param_1 == 6) goto LAB_100093d5;
        if (param_1 != 8) goto LAB_100093a8;
      }
    }
    p_Var7 = FUN_10009aa9();
    if (p_Var7 == (__acrt_ptd *)0x0) {
      ExceptionList = local_14;
      return 0xffffffff;
    }
    p_Var2 = siglookup(param_1,*(__crt_signal_action_t **)p_Var7);
    if (p_Var2 == (__crt_signal_action_t *)0x0) {
LAB_100093a8:
      p_Var7 = FUN_100095db();
      *(undefined4 *)p_Var7 = 0x16;
      FUN_100080a4();
      ExceptionList = local_14;
      return 0xffffffff;
    }
    p_Var2 = p_Var2 + 8;
    bVar1 = false;
  }
  else {
    if (((param_1 != 0xf) && (param_1 != 0x15)) && (param_1 != 0x16)) goto LAB_100093a8;
LAB_100093d5:
    p_Var2 = (__crt_signal_action_t *)get_global_action_nolock(param_1);
  }
  local_34 = 0;
  if (bVar1) {
    ___acrt_lock(3);
  }
  pcVar3 = *(code **)p_Var2;
  if (bVar1) {
    pcVar3 = (code *)FUN_10008188((uint)pcVar3);
  }
  if (pcVar3 == (code *)0x1) goto LAB_10009496;
  if (pcVar3 == (code *)0x0) {
    if (bVar1) {
      ___acrt_unlock(3);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {
    local_34 = *(int *)(p_Var7 + 4);
    *(int *)(p_Var7 + 4) = 0;
    if (param_1 == 8) {
      p_Var4 = FUN_10009958();
      local_38 = *(undefined4 *)(p_Var4 + 8);
      p_Var4 = FUN_10009958();
      *(undefined4 *)(p_Var4 + 8) = 0x8c;
      goto LAB_10009465;
    }
  }
  else {
LAB_10009465:
    if (param_1 == 8) {
      iVar5 = DAT_10011db4 * 0xc + *(int *)p_Var7;
      iVar6 = DAT_10011db8 * 0xc + iVar5;
      for (; iVar5 != iVar6; iVar5 = iVar5 + 0xc) {
        *(undefined4 *)(iVar5 + 8) = 0;
      }
      goto LAB_10009496;
    }
  }
  *(uint *)p_Var2 = DAT_10019008;
LAB_10009496:
  FUN_100094d6();
  if (pcVar3 != (code *)0x1) {
    if (param_1 == 8) {
      p_Var4 = FUN_10009958();
      (*(code *)PTR_guard_check_icall_1001116c)(8,*(undefined4 *)(p_Var4 + 8));
      (*pcVar3)();
    }
    else {
      (*(code *)PTR_guard_check_icall_1001116c)(param_1);
      (*pcVar3)();
      if ((param_1 != 0xb) && (param_1 != 4)) {
        ExceptionList = local_14;
        return 0;
      }
    }
    *(int *)(p_Var7 + 4) = local_34;
    if (param_1 == 8) {
      p_Var7 = FUN_10009958();
      *(undefined4 *)(p_Var7 + 8) = local_38;
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* VA 100094d6 */

void FUN_100094d6(void)

{
  char unaff_BL;

  if (unaff_BL != '\0') {
    ___acrt_unlock(3);
  }
  return;
}



/* VA 1000953e */

/* Library Function - Multiple Matches With Different Base Names
    ___acrt_errno_from_os_error
    __get_errno_from_oserr

   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

int __cdecl FID_conflict____acrt_errno_from_os_error(ulong param_1)

{
  uint uVar1;

  uVar1 = 0;
  do {
    if (param_1 == (&DAT_10011e68)[uVar1 * 2]) {
      return *(int *)(&UNK_10011e6c + uVar1 * 8);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x2d);
  if (param_1 - 0x13 < 0x12) {
    return 0xd;
  }
  return (-(uint)(0xe < param_1 - 0xbc) & 0xe) + 8;
}



/* VA 10009581 */

/* Library Function - Single Match
    ___acrt_errno_map_os_error

   Library: Visual Studio 2019 Release */

void __cdecl ___acrt_errno_map_os_error(ulong param_1)

{
  __acrt_ptd *p_Var1;
  int iVar2;

  p_Var1 = FUN_100095c8();
  *(ulong *)p_Var1 = param_1;
  iVar2 = FID_conflict____acrt_errno_from_os_error(param_1);
  p_Var1 = FUN_100095db();
  *(int *)p_Var1 = iVar2;
  return;
}



/* VA 100095a4 */

void __cdecl FUN_100095a4(ulong param_1,int param_2)

{
  int iVar1;

  *(undefined1 *)(param_2 + 0x24) = 1;
  *(ulong *)(param_2 + 0x20) = param_1;
  iVar1 = FID_conflict____acrt_errno_from_os_error(param_1);
  *(undefined1 *)(param_2 + 0x1c) = 1;
  *(int *)(param_2 + 0x18) = iVar1;
  return;
}



/* VA 100095c8 */

__acrt_ptd * FUN_100095c8(void)

{
  __acrt_ptd *p_Var1;

  p_Var1 = FUN_10009aa9();
  if (p_Var1 == (__acrt_ptd *)0x0) {
    return (__acrt_ptd *)&DAT_10019044;
  }
  return p_Var1 + 0x14;
}



/* VA 100095db */

__acrt_ptd * FUN_100095db(void)

{
  __acrt_ptd *p_Var1;

  p_Var1 = FUN_10009aa9();
  if (p_Var1 == (__acrt_ptd *)0x0) {
    return (__acrt_ptd *)&DAT_10019040;
  }
  return p_Var1 + 0x10;
}



/* VA 100095ee */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_15ade71b0218206bbe3333a0c9b79046>,class <lambda_da44e0f8b0f19ba52fefafb335991732> &,class
   <lambda_207f2d024fc103971653565357d6cd41> >(class <lambda_15ade71b0218206bbe3333a0c9b79046>
   &&,class <lambda_da44e0f8b0f19ba52fefafb335991732> &,class
   <lambda_207f2d024fc103971653565357d6cd41> &&)

   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<<lambda_15ade71b0218206bbe3333a0c9b79046>,<lambda_da44e0f8b0f19ba52fefafb335991732>&,<lambda_207f2d024fc103971653565357d6cd41>_>
          (__crt_seh_guarded_call<void> *this,<lambda_15ade71b0218206bbe3333a0c9b79046> *param_1,
          <lambda_da44e0f8b0f19ba52fefafb335991732> *param_2,
          <lambda_207f2d024fc103971653565357d6cd41> *param_3)

{
  undefined4 local_14;

  ___acrt_lock(*(int *)param_1);
  LOCK();
  **(int **)(**(int **)param_2 + 0x48) = **(int **)(**(int **)param_2 + 0x48) + 1;
  UNLOCK();
  FUN_10009634();
  ExceptionList = local_14;
  return;
}



/* VA 10009634 */

void FUN_10009634(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 10009640 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_38edbb1296d33220d7e4dd0ed76b244a>,class <lambda_5ce1d447e08cb34b2473517608e21441> &,class
   <lambda_fb385d3da700c9147fc39e65dd577a8c> >(class <lambda_38edbb1296d33220d7e4dd0ed76b244a>
   &&,class <lambda_5ce1d447e08cb34b2473517608e21441> &,class
   <lambda_fb385d3da700c9147fc39e65dd577a8c> &&)

   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<<lambda_38edbb1296d33220d7e4dd0ed76b244a>,<lambda_5ce1d447e08cb34b2473517608e21441>&,<lambda_fb385d3da700c9147fc39e65dd577a8c>_>
          (__crt_seh_guarded_call<void> *this,<lambda_38edbb1296d33220d7e4dd0ed76b244a> *param_1,
          <lambda_5ce1d447e08cb34b2473517608e21441> *param_2,
          <lambda_fb385d3da700c9147fc39e65dd577a8c> *param_3)

{
  int iVar1;
  int *piVar2;
  void *local_14;

  ___acrt_lock(*(int *)param_1);
  piVar2 = *(int **)(**(int **)param_2 + 0x48);
  if (piVar2 != (int *)0x0) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = iVar1 + -1;
    UNLOCK();
    if ((iVar1 + -1 == 0) && (piVar2 != (int *)&DAT_10019118)) {
      FUN_10009f36(piVar2);
    }
  }
  FUN_1000969f();
  ExceptionList = local_14;
  return;
}



/* VA 1000969f */

void FUN_1000969f(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 100096ab */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_6affb1475c98b40b75cdec977db92e3c>,class <lambda_b8d4b9c228a6ecc3f80208dbb4b4a104> &,class
   <lambda_608742c3c92a14382c1684fc64f96c88> >(class <lambda_6affb1475c98b40b75cdec977db92e3c>
   &&,class <lambda_b8d4b9c228a6ecc3f80208dbb4b4a104> &,class
   <lambda_608742c3c92a14382c1684fc64f96c88> &&)

   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<<lambda_6affb1475c98b40b75cdec977db92e3c>,<lambda_b8d4b9c228a6ecc3f80208dbb4b4a104>&,<lambda_608742c3c92a14382c1684fc64f96c88>_>
          (__crt_seh_guarded_call<void> *this,<lambda_6affb1475c98b40b75cdec977db92e3c> *param_1,
          <lambda_b8d4b9c228a6ecc3f80208dbb4b4a104> *param_2,
          <lambda_608742c3c92a14382c1684fc64f96c88> *param_3)

{
  undefined4 local_14;

  ___acrt_lock(*(int *)param_1);
  replace_current_thread_locale_nolock
            ((__acrt_ptd *)**(undefined4 **)param_2,(__crt_locale_data *)0x0);
  FUN_100096f4();
  ExceptionList = local_14;
  return;
}



/* VA 100096f4 */

void FUN_100096f4(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 10009700 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_a7e850c220f1c8d1e6efeecdedd162c6>,class <lambda_46720907175c18b6c9d2717bc0d2d362> &,class
   <lambda_9048902d66e8d99359bc9897bbb930a8> >(class <lambda_a7e850c220f1c8d1e6efeecdedd162c6>
   &&,class <lambda_46720907175c18b6c9d2717bc0d2d362> &,class
   <lambda_9048902d66e8d99359bc9897bbb930a8> &&)

   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<<lambda_a7e850c220f1c8d1e6efeecdedd162c6>,<lambda_46720907175c18b6c9d2717bc0d2d362>&,<lambda_9048902d66e8d99359bc9897bbb930a8>_>
          (__crt_seh_guarded_call<void> *this,<lambda_a7e850c220f1c8d1e6efeecdedd162c6> *param_1,
          <lambda_46720907175c18b6c9d2717bc0d2d362> *param_2,
          <lambda_9048902d66e8d99359bc9897bbb930a8> *param_3)

{
  void *local_14;

  ___acrt_lock(*(int *)param_1);
  replace_current_thread_locale_nolock
            ((__acrt_ptd *)**(undefined4 **)param_2,
             *(__crt_locale_data **)**(undefined4 **)(param_2 + 4));
  FUN_1000974e();
  ExceptionList = local_14;
  return;
}



/* VA 1000974e */

void FUN_1000974e(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 1000975a */

/* Library Function - Single Match
    void __cdecl construct_ptd(struct __acrt_ptd * const,struct __crt_locale_data * * const)

   Library: Visual Studio 2019 Release */

void __cdecl construct_ptd(__acrt_ptd *param_1,__crt_locale_data **param_2)

{
  undefined4 local_18;
  __acrt_ptd **local_14;
  __acrt_ptd **local_10;
  __crt_locale_data ***local_c;
  __crt_seh_guarded_call<void> local_5;

  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined **)param_1 = &DAT_10011d20;
  *(undefined4 *)(param_1 + 0x350) = 1;
  *(undefined **)(param_1 + 0x48) = &DAT_10019118;
  *(undefined2 *)(param_1 + 0x6c) = 0x43;
  *(undefined2 *)(param_1 + 0x172) = 0x43;
  *(undefined4 *)(param_1 + 0x34c) = 0;
  local_14 = &param_1;
  local_c = (__crt_locale_data ***)0x5;
  local_18 = 5;
  __crt_seh_guarded_call<void>::
  operator()<<lambda_15ade71b0218206bbe3333a0c9b79046>,<lambda_da44e0f8b0f19ba52fefafb335991732>&,<lambda_207f2d024fc103971653565357d6cd41>_>
            (&local_5,(<lambda_15ade71b0218206bbe3333a0c9b79046> *)&local_18,
             (<lambda_da44e0f8b0f19ba52fefafb335991732> *)&local_14,
             (<lambda_207f2d024fc103971653565357d6cd41> *)&local_c);
  local_10 = &param_1;
  local_c = &param_2;
  local_18 = 4;
  local_14 = (__acrt_ptd **)0x4;
  __crt_seh_guarded_call<void>::
  operator()<<lambda_a7e850c220f1c8d1e6efeecdedd162c6>,<lambda_46720907175c18b6c9d2717bc0d2d362>&,<lambda_9048902d66e8d99359bc9897bbb930a8>_>
            (&local_5,(<lambda_a7e850c220f1c8d1e6efeecdedd162c6> *)&local_14,
             (<lambda_46720907175c18b6c9d2717bc0d2d362> *)&local_10,
             (<lambda_9048902d66e8d99359bc9897bbb930a8> *)&local_18);
  return;
}



/* VA 100097f3 */

/* Library Function - Single Match
    void __stdcall destroy_fls(void *)

   Library: Visual Studio 2019 Release */

void destroy_fls(void *param_1)

{
  if (param_1 != (void *)0x0) {
    destroy_ptd(param_1);
    FUN_10009f36(param_1);
  }
  return;
}



/* VA 10009814 */

/* Library Function - Single Match
    void __cdecl destroy_ptd(struct __acrt_ptd * const)

   Library: Visual Studio 2019 Release */

void __cdecl destroy_ptd(__acrt_ptd *param_1)

{
  undefined4 local_14;
  __acrt_ptd **local_10;
  undefined4 local_c;
  __crt_seh_guarded_call<void> local_5;

  if (*(undefined **)param_1 != &DAT_10011d20) {
    FUN_10009f36(*(undefined **)param_1);
  }
  FUN_10009f36(*(LPVOID *)(param_1 + 0x3c));
  FUN_10009f36(*(LPVOID *)(param_1 + 0x30));
  FUN_10009f36(*(LPVOID *)(param_1 + 0x34));
  FUN_10009f36(*(LPVOID *)(param_1 + 0x38));
  FUN_10009f36(*(LPVOID *)(param_1 + 0x28));
  FUN_10009f36(*(LPVOID *)(param_1 + 0x2c));
  FUN_10009f36(*(LPVOID *)(param_1 + 0x40));
  FUN_10009f36(*(LPVOID *)(param_1 + 0x44));
  FUN_10009f36(*(LPVOID *)(param_1 + 0x360));
  local_10 = &param_1;
  local_c = 5;
  local_14 = 5;
  __crt_seh_guarded_call<void>::
  operator()<<lambda_38edbb1296d33220d7e4dd0ed76b244a>,<lambda_5ce1d447e08cb34b2473517608e21441>&,<lambda_fb385d3da700c9147fc39e65dd577a8c>_>
            (&local_5,(<lambda_38edbb1296d33220d7e4dd0ed76b244a> *)&local_14,
             (<lambda_5ce1d447e08cb34b2473517608e21441> *)&local_10,
             (<lambda_fb385d3da700c9147fc39e65dd577a8c> *)&local_c);
  local_10 = &param_1;
  local_14 = 4;
  local_c = 4;
  __crt_seh_guarded_call<void>::
  operator()<<lambda_6affb1475c98b40b75cdec977db92e3c>,<lambda_b8d4b9c228a6ecc3f80208dbb4b4a104>&,<lambda_608742c3c92a14382c1684fc64f96c88>_>
            (&local_5,(<lambda_6affb1475c98b40b75cdec977db92e3c> *)&local_c,
             (<lambda_b8d4b9c228a6ecc3f80208dbb4b4a104> *)&local_10,
             (<lambda_608742c3c92a14382c1684fc64f96c88> *)&local_14);
  return;
}



/* VA 100098e1 */

/* Library Function - Single Match
    void __cdecl replace_current_thread_locale_nolock(struct __acrt_ptd * const,struct
   __crt_locale_data * const)

   Library: Visual Studio 2019 Release */

void __cdecl replace_current_thread_locale_nolock(__acrt_ptd *param_1,__crt_locale_data *param_2)

{
  undefined **ppuVar1;

  if (*(int *)(param_1 + 0x4c) != 0) {
    ___acrt_release_locale_ref(*(int *)(param_1 + 0x4c));
    ppuVar1 = *(undefined ***)(param_1 + 0x4c);
    if (((ppuVar1 != DAT_10019f0c) && (ppuVar1 != &PTR_DAT_10019050)) &&
       (ppuVar1[3] == (undefined *)0x0)) {
      ___acrt_free_locale((int)ppuVar1);
    }
  }
  *(__crt_locale_data **)(param_1 + 0x4c) = param_2;
  if (param_2 != (__crt_locale_data *)0x0) {
    ___acrt_add_locale_ref((int)param_2);
  }
  return;
}



/* VA 1000992c */

/* Library Function - Single Match
    ___acrt_freeptd

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_freeptd(void)

{
  void *pvVar1;

  if ((DAT_10019048 != 0xffffffff) &&
     (pvVar1 = (void *)___acrt_FlsGetValue_4(DAT_10019048), pvVar1 != (void *)0x0)) {
    ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
    destroy_fls(pvVar1);
  }
  return;
}



/* VA 10009958 */

__acrt_ptd * FUN_10009958(void)

{
  DWORD dwErrCode;
  uint uVar1;
  int iVar2;
  __acrt_ptd *p_Var3;
  __acrt_ptd *p_Var4;

  dwErrCode = GetLastError();
  if ((DAT_10019048 == 0xffffffff) || (uVar1 = ___acrt_FlsGetValue_4(DAT_10019048), uVar1 == 0)) {
    iVar2 = ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0xffffffff);
    if (iVar2 == 0) {
      p_Var3 = (__acrt_ptd *)0x0;
    }
    else {
      p_Var3 = __calloc_base(1,0x364);
      if (p_Var3 == (__acrt_ptd *)0x0) {
        ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
        p_Var4 = (__acrt_ptd *)0x0;
      }
      else {
        iVar2 = ___acrt_FlsSetValue_8(DAT_10019048,p_Var3);
        if (iVar2 != 0) {
          construct_ptd(p_Var3,(__crt_locale_data **)&DAT_10019f0c);
          FUN_10009f36((LPVOID)0x0);
          goto LAB_100099fd;
        }
        ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
        p_Var4 = p_Var3;
      }
      p_Var3 = (__acrt_ptd *)0x0;
      FUN_10009f36(p_Var4);
    }
  }
  else {
    p_Var3 = (__acrt_ptd *)(-(uint)(uVar1 != 0xffffffff) & uVar1);
  }
LAB_100099fd:
  SetLastError(dwErrCode);
  if (p_Var3 == (__acrt_ptd *)0x0) {
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  return p_Var3;
}



/* VA 10009a13 */

__acrt_ptd * FUN_10009a13(void)

{
  __acrt_ptd *p_Var1;
  int iVar2;

  if ((DAT_10019048 == 0xffffffff) ||
     (p_Var1 = (__acrt_ptd *)___acrt_FlsGetValue_4(DAT_10019048), p_Var1 == (__acrt_ptd *)0x0)) {
    iVar2 = ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0xffffffff);
    if (iVar2 != 0) {
      p_Var1 = __calloc_base(1,0x364);
      if (p_Var1 == (__acrt_ptd *)0x0) {
        ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
      }
      else {
        iVar2 = ___acrt_FlsSetValue_8(DAT_10019048,p_Var1);
        if (iVar2 != 0) {
          construct_ptd(p_Var1,(__crt_locale_data **)&DAT_10019f0c);
          FUN_10009f36((LPVOID)0x0);
          return p_Var1;
        }
        ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
      }
      FUN_10009f36(p_Var1);
    }
  }
  else if (p_Var1 != (__acrt_ptd *)0xffffffff) {
    return p_Var1;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 10009aa9 */

__acrt_ptd * FUN_10009aa9(void)

{
  DWORD dwErrCode;
  uint uVar1;
  int iVar2;
  __acrt_ptd *p_Var3;
  __acrt_ptd *p_Var4;

  dwErrCode = GetLastError();
  if ((DAT_10019048 == 0xffffffff) || (uVar1 = ___acrt_FlsGetValue_4(DAT_10019048), uVar1 == 0)) {
    iVar2 = ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0xffffffff);
    if (iVar2 == 0) {
      p_Var3 = (__acrt_ptd *)0x0;
    }
    else {
      p_Var3 = __calloc_base(1,0x364);
      if (p_Var3 == (__acrt_ptd *)0x0) {
        ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
        p_Var4 = (__acrt_ptd *)0x0;
      }
      else {
        iVar2 = ___acrt_FlsSetValue_8(DAT_10019048,p_Var3);
        if (iVar2 != 0) {
          construct_ptd(p_Var3,(__crt_locale_data **)&DAT_10019f0c);
          FUN_10009f36((LPVOID)0x0);
          goto LAB_10009b4e;
        }
        ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
        p_Var4 = p_Var3;
      }
      p_Var3 = (__acrt_ptd *)0x0;
      FUN_10009f36(p_Var4);
    }
  }
  else {
    p_Var3 = (__acrt_ptd *)(-(uint)(uVar1 != 0xffffffff) & uVar1);
  }
LAB_10009b4e:
  SetLastError(dwErrCode);
  return p_Var3;
}



/* VA 10009b5a */

__acrt_ptd * __cdecl FUN_10009b5a(undefined4 param_1,int param_2)

{
  __acrt_ptd *p_Var1;
  int iVar2;
  __acrt_ptd *p_Var3;

  p_Var3 = (__acrt_ptd *)0x0;
  if ((DAT_10019048 == 0xffffffff) ||
     (p_Var1 = (__acrt_ptd *)___acrt_FlsGetValue_4(DAT_10019048), p_Var1 == (__acrt_ptd *)0x0)) {
    iVar2 = ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0xffffffff);
    if (iVar2 == 0) {
      return (__acrt_ptd *)0x0;
    }
    p_Var1 = __calloc_base(1,0x364);
    if (p_Var1 == (__acrt_ptd *)0x0) {
      ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
      p_Var1 = (__acrt_ptd *)0x0;
    }
    else {
      iVar2 = ___acrt_FlsSetValue_8(DAT_10019048,p_Var1);
      if (iVar2 != 0) {
        construct_ptd(p_Var1,(__crt_locale_data **)&DAT_10019f0c);
        FUN_10009f36((LPVOID)0x0);
        goto LAB_10009bee;
      }
      ___acrt_FlsSetValue_8(DAT_10019048,(LPVOID)0x0);
    }
    FUN_10009f36(p_Var1);
  }
  else {
    if (p_Var1 == (__acrt_ptd *)0xffffffff) {
      return (__acrt_ptd *)0x0;
    }
LAB_10009bee:
    p_Var3 = p_Var1 + param_2 * 0x364;
  }
  return p_Var3;
}



/* VA 10009c29 */

/* Library Function - Single Match
    ___acrt_uninitialize_ptd

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 ___acrt_uninitialize_ptd(void)

{
  DWORD DVar1;

  DVar1 = DAT_10019048;
  if (DAT_10019048 != 0xffffffff) {
    DVar1 = ___acrt_FlsFree_4(DAT_10019048);
    DAT_10019048 = 0xffffffff;
  }
  return CONCAT31((int3)(DVar1 >> 8),1);
}



/* VA 10009c43 */

void __cdecl FUN_10009c43(int param_1,int *param_2)

{
  int iVar1;

  if ((*param_2 != DAT_10019f0c) && ((*(uint *)(param_1 + 0x350) & DAT_100196e0) == 0)) {
    iVar1 = FUN_1000c453();
    *param_2 = iVar1;
  }
  return;
}



/* VA 10009c70 */

void __cdecl FUN_10009c70(int param_1,int *param_2,int param_3)

{
  int iVar1;

  if ((*param_2 != (&DAT_10019f0c)[param_3]) && ((*(uint *)(param_1 + 0x350) & DAT_100196e0) == 0))
  {
    iVar1 = FUN_1000c453();
    *param_2 = iVar1;
  }
  return;
}



/* VA 10009ca1 */

void __cdecl FUN_10009ca1(int param_1,int *param_2)

{
  int iVar1;

  if ((*param_2 != DAT_1001a06c) && ((*(uint *)(param_1 + 0x350) & DAT_100196e0) == 0)) {
    iVar1 = FUN_1000af00();
    *param_2 = iVar1;
  }
  return;
}



/* VA 10009cce */

void __cdecl FUN_10009cce(int param_1,int *param_2,int param_3)

{
  int iVar1;

  if ((*param_2 != (&DAT_1001a06c)[param_3]) && ((*(uint *)(param_1 + 0x350) & DAT_100196e0) == 0))
  {
    iVar1 = FUN_1000af00();
    *param_2 = iVar1;
  }
  return;
}



/* VA 10009cff */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_e5124f882df8998aaf41531e079ba474>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36> &,class
   <lambda_e25ca0880e6ef98be67edffd8c599615> >(class <lambda_e5124f882df8998aaf41531e079ba474>
   &&,class <lambda_3e16ef9562a7dcce91392c22ab16ea36> &,class
   <lambda_e25ca0880e6ef98be67edffd8c599615> &&)

   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<<lambda_e5124f882df8998aaf41531e079ba474>,<lambda_3e16ef9562a7dcce91392c22ab16ea36>&,<lambda_e25ca0880e6ef98be67edffd8c599615>_>
          (__crt_seh_guarded_call<void> *this,<lambda_e5124f882df8998aaf41531e079ba474> *param_1,
          <lambda_3e16ef9562a7dcce91392c22ab16ea36> *param_2,
          <lambda_e25ca0880e6ef98be67edffd8c599615> *param_3)

{
  undefined **ppuVar1;
  int *piVar2;
  void *local_14;

  ___acrt_lock(*(int *)param_1);
  for (piVar2 = &DAT_10019f0c; piVar2 != &DAT_10019f10; piVar2 = piVar2 + 1) {
    if ((undefined **)*piVar2 != &PTR_DAT_10019050) {
      ppuVar1 = __updatetlocinfoEx_nolock(piVar2,&PTR_DAT_10019050);
      *piVar2 = (int)ppuVar1;
    }
  }
  FUN_10009d61();
  ExceptionList = local_14;
  return;
}



/* VA 10009d61 */

void FUN_10009d61(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 10009d6d */

undefined4 FUN_10009d6d(void)

{
  undefined4 uVar1;

  uVar1 = DAT_10019f08;
  LOCK();
  DAT_10019f08 = 1;
  UNLOCK();
  return uVar1;
}



/* VA 10009d78 */

/* Library Function - Single Match
    ___acrt_uninitialize_locale

   Library: Visual Studio 2019 Release */

void ___acrt_uninitialize_locale(void)

{
  undefined4 local_10;
  undefined4 local_c;
  __crt_seh_guarded_call<void> local_5;

  local_c = 4;
  local_10 = 4;
  __crt_seh_guarded_call<void>::
  operator()<<lambda_e5124f882df8998aaf41531e079ba474>,<lambda_3e16ef9562a7dcce91392c22ab16ea36>&,<lambda_e25ca0880e6ef98be67edffd8c599615>_>
            (&local_5,(<lambda_e5124f882df8998aaf41531e079ba474> *)&local_10,
             (<lambda_3e16ef9562a7dcce91392c22ab16ea36> *)&local_5,
             (<lambda_e25ca0880e6ef98be67edffd8c599615> *)&local_c);
  return;
}



/* VA 10009de0 */

/* Library Function - Single Match
    ___acrt_lock

   Library: Visual Studio 2019 Release */

void __cdecl ___acrt_lock(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_10019f10 + param_1 * 6));
  return;
}



/* VA 10009df7 */

undefined4 FUN_10009df7(void)

{
  undefined4 in_EAX;
  undefined4 extraout_EAX;
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;

  if (DAT_1001a060 != 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_10019ef8 + DAT_1001a060 * 0x18);
    iVar1 = DAT_1001a060;
    do {
      DeleteCriticalSection(lpCriticalSection);
      DAT_1001a060 = DAT_1001a060 + -1;
      lpCriticalSection = lpCriticalSection + -1;
      iVar1 = iVar1 + -1;
      in_EAX = extraout_EAX;
    } while (iVar1 != 0);
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



/* VA 10009e28 */

/* Library Function - Single Match
    ___acrt_unlock

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___acrt_unlock(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_10019f10 + param_1 * 6));
  return;
}



/* VA 10009e3f */

/* Library Function - Single Match
    __malloc_base

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID __cdecl __malloc_base(SIZE_T param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  LPVOID pvVar3;
  __acrt_ptd *p_Var4;

  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      pvVar3 = HeapAlloc(DAT_1001a174,0,param_1);
      if (pvVar3 != (LPVOID)0x0) {
        return pvVar3;
      }
      iVar2 = FUN_1000c8b5();
    } while ((iVar2 != 0) && (bVar1 = FUN_100081b2(param_1), CONCAT31(extraout_var,bVar1) != 0));
  }
  p_Var4 = FUN_100095db();
  *(undefined4 *)p_Var4 = 0xc;
  return (LPVOID)0x0;
}



/* VA 10009e8d */

uint FUN_10009e8d(void)

{
  return *(uint *)(*(int *)((int)Self + 0x30) + 0x68) >> 8 & 0xffffff01;
}



/* VA 10009e9f */

uint FUN_10009e9f(void)

{
  return *(uint *)(*(int *)(*(int *)((int)Self + 0x30) + 0x10) + 8) >> 0x1f;
}



/* VA 10009eb2 */

bool FUN_10009eb2(void)

{
  uint uVar1;
  int local_8;

  local_8 = 0;
  uVar1 = FUN_10009e9f();
  if ((char)uVar1 == '\0') {
    FUN_1000b6ba(&local_8);
  }
  return local_8 != 1;
}



/* VA 10009ed9 */

/* Library Function - Single Match
    __calloc_base

   Library: Visual Studio 2019 Release */

LPVOID __cdecl __calloc_base(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  LPVOID pvVar3;
  __acrt_ptd *p_Var4;
  SIZE_T dwBytes;

  if ((param_1 == 0) || (param_2 <= 0xffffffe0 / param_1)) {
    dwBytes = param_1 * param_2;
    if (dwBytes == 0) {
      dwBytes = 1;
    }
    do {
      pvVar3 = HeapAlloc(DAT_1001a174,8,dwBytes);
      if (pvVar3 != (LPVOID)0x0) {
        return pvVar3;
      }
      iVar2 = FUN_1000c8b5();
    } while ((iVar2 != 0) && (bVar1 = FUN_100081b2(dwBytes), CONCAT31(extraout_var,bVar1) != 0));
  }
  p_Var4 = FUN_100095db();
  *(undefined4 *)p_Var4 = 0xc;
  return (LPVOID)0x0;
}



/* VA 10009f36 */

void __cdecl FUN_10009f36(LPVOID param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  __acrt_ptd *p_Var4;

  if (param_1 != (LPVOID)0x0) {
    BVar1 = HeapFree(DAT_1001a174,0,param_1);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      iVar3 = FID_conflict____acrt_errno_from_os_error(DVar2);
      p_Var4 = FUN_100095db();
      *(int *)p_Var4 = iVar3;
    }
  }
  return;
}



/* VA 10009f70 */

uint __cdecl FUN_10009f70(uint param_1,uint param_2)

{
  if (param_1 < param_2) {
    return 0xffffffff;
  }
  return (uint)(param_2 < param_1);
}



/* VA 10009f88 */

/* Library Function - Single Match
    int __cdecl __acrt_convert_wcs_mbs_cp<char,wchar_t,class
   <lambda_62f6974d9771e494a5ea317cc32e971c>,struct
   __crt_win32_buffer_internal_dynamic_resizing>(char const * const,class
   __crt_win32_buffer<wchar_t,struct __crt_win32_buffer_internal_dynamic_resizing> &,class
   <lambda_62f6974d9771e494a5ea317cc32e971c> const &,unsigned int)

   Library: Visual Studio 2019 Release */

int __cdecl
__acrt_convert_wcs_mbs_cp<char,wchar_t,<lambda_62f6974d9771e494a5ea317cc32e971c>,__crt_win32_buffer_internal_dynamic_resizing>
          (char *param_1,
          __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> *param_2,
          <lambda_62f6974d9771e494a5ea317cc32e971c> *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  __acrt_ptd *p_Var4;

  if (param_1 == (char *)0x0) {
    __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::_deallocate(param_2);
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  else {
    if (*param_1 != '\0') {
      uVar2 = FUN_1000b2b2(param_4,9,param_1,-1,(LPWSTR)0x0,0);
      if (uVar2 != 0) {
        if ((*(uint *)(param_2 + 0xc) < uVar2) &&
           (iVar1 = __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::
                    allocate(param_2,uVar2), iVar1 != 0)) {
          return iVar1;
        }
        iVar1 = FUN_1000b2b2(param_4,9,param_1,-1,*(LPWSTR *)(param_2 + 8),*(int *)(param_2 + 0xc));
        if (iVar1 != 0) {
          *(int *)(param_2 + 0x10) = iVar1 + -1;
          return 0;
        }
      }
      DVar3 = GetLastError();
      ___acrt_errno_map_os_error(DVar3);
      p_Var4 = FUN_100095db();
      return *(int *)p_Var4;
    }
    if ((*(int *)(param_2 + 0xc) == 0) &&
       (iVar1 = __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::allocate
                          (param_2,1), iVar1 != 0)) {
      return iVar1;
    }
    **(undefined2 **)(param_2 + 8) = 0;
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  return 0;
}



/* VA 1000a03a */

int __cdecl
FUN_1000a03a(LPCWSTR param_1,
            __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> *param_2,
            undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  __acrt_ptd *p_Var4;

  if (param_1 == (LPCWSTR)0x0) {
    __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::_deallocate(param_2);
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  else {
    if (*param_1 != L'\0') {
      uVar2 = FUN_1000b36c(param_4,0,param_1,-1,(LPSTR)0x0,0,0,(undefined4 *)0x0);
      if (uVar2 == 0) {
        DVar3 = GetLastError();
        ___acrt_errno_map_os_error(DVar3);
        p_Var4 = FUN_100095db();
        return *(int *)p_Var4;
      }
      if ((*(uint *)(param_2 + 0xc) < uVar2) && (iVar1 = allocate(param_2,uVar2), iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = FUN_1000a5f5(param_4,param_1,*(LPSTR *)(param_2 + 8),*(int *)(param_2 + 0xc));
      if (iVar1 == 0) {
        DVar3 = GetLastError();
        ___acrt_errno_map_os_error(DVar3);
        p_Var4 = FUN_100095db();
        return *(int *)p_Var4;
      }
      *(int *)(param_2 + 0x10) = iVar1 + -1;
      return 0;
    }
    if ((*(int *)(param_2 + 0xc) == 0) && (iVar1 = allocate(param_2,1), iVar1 != 0)) {
      return iVar1;
    }
    **(undefined1 **)(param_2 + 8) = 0;
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  return 0;
}



/* VA 1000a100 */

/* Library Function - Single Match
    int __cdecl __acrt_mbs_to_wcs_cp<struct __crt_win32_buffer_internal_dynamic_resizing>(char const
   * const,class __crt_win32_buffer<wchar_t,struct __crt_win32_buffer_internal_dynamic_resizing>
   &,unsigned int)

   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

int __cdecl
__acrt_mbs_to_wcs_cp<__crt_win32_buffer_internal_dynamic_resizing>
          (char *param_1,
          __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> *param_2,
          uint param_3)

{
  int iVar1;
  <lambda_62f6974d9771e494a5ea317cc32e971c> local_5;

  iVar1 = __acrt_convert_wcs_mbs_cp<char,wchar_t,<lambda_62f6974d9771e494a5ea317cc32e971c>,__crt_win32_buffer_internal_dynamic_resizing>
                    (param_1,param_2,&local_5,param_3);
  return iVar1;
}



/* VA 1000a11d */

int __cdecl FUN_1000a11d(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  __acrt_ptd *p_Var2;
  uchar *puVar3;
  int iVar4;
  LPVOID pvVar5;
  char *pcVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int *local_24;
  int *local_20;
  undefined4 local_1c;
  int local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  undefined4 local_8;

  if (param_2 == (undefined4 *)0x0) {
    p_Var2 = FUN_100095db();
    iVar4 = 0x16;
    *(undefined4 *)p_Var2 = 0x16;
    FUN_100080a4();
  }
  else {
    *param_2 = 0;
    local_1c = 0;
    local_20 = (int *)0x0;
    local_24 = (int *)0x0;
    pcVar6 = (char *)*param_1;
    piVar9 = local_24;
    while (local_24 = piVar9, pcVar6 != (char *)0x0) {
      uVar7 = (uint)local_8 >> 0x18;
      local_8 = (char *)CONCAT13((char)uVar7,0x3f2a);
      puVar3 = (uchar *)_strpbrk(pcVar6,(char *)&local_8);
      if (puVar3 == (uchar *)0x0) {
        iVar4 = FUN_1000a29a((char *)*param_1,0,0,(int *)&local_24);
      }
      else {
        iVar4 = FUN_1000a34b((uchar *)*param_1,puVar3,(int *)&local_24);
      }
      if (iVar4 != 0) goto LAB_1000a204;
      param_1 = param_1 + 1;
      piVar9 = local_24;
      pcVar6 = (char *)*param_1;
    }
    uVar7 = ((int)local_20 - (int)piVar9 >> 2) + 1;
    local_c = (char *)0x0;
    for (piVar8 = piVar9; piVar8 != local_20; piVar8 = piVar8 + 1) {
      pcVar6 = (char *)*piVar8;
      local_10 = pcVar6 + 1;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      local_c = pcVar6 + (int)(local_c + (1 - (int)local_10));
    }
    pvVar5 = ___acrt_allocate_buffer_for_argv(uVar7,(uint)local_c,1);
    piVar8 = local_20;
    if (pvVar5 == (LPVOID)0x0) {
      FUN_10009f36((LPVOID)0x0);
      iVar4 = -1;
LAB_1000a204:
      ~argument_list<>(&local_24);
    }
    else {
      local_8 = (char *)((int)pvVar5 + uVar7 * 4);
      local_14 = local_8;
      if (piVar9 != local_20) {
        local_18 = (int)pvVar5 - (int)piVar9;
        do {
          local_10 = (char *)*piVar9;
          pcVar6 = local_10 + 1;
          do {
            cVar1 = *local_10;
            local_10 = local_10 + 1;
          } while (cVar1 != '\0');
          local_10 = local_10 + (1 - (int)pcVar6);
          iVar4 = FUN_1000ce65(local_8,(int)(local_14 + ((int)local_c - (int)local_8)),*piVar9,
                               (int)local_10);
          if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          *(char **)(local_18 + (int)piVar9) = local_8;
          piVar9 = piVar9 + 1;
          local_8 = local_8 + (int)local_10;
        } while (piVar9 != piVar8);
      }
      *param_2 = pvVar5;
      FUN_10009f36((LPVOID)0x0);
      ~argument_list<>(&local_24);
      iVar4 = 0;
    }
  }
  return iVar4;
}



/* VA 1000a29a */

int __cdecl FUN_1000a29a(char *param_1,int param_2,uint param_3,int *param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;

  pcVar4 = param_1;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + (1 - (int)(param_1 + 1));
  if ((char *)~param_3 < pcVar4) {
    iVar3 = 0xc;
  }
  else {
    pcVar5 = pcVar4 + param_3 + 1;
    pcVar2 = __calloc_base((uint)pcVar5,1);
    if (param_3 != 0) {
      iVar3 = FUN_1000ce65(pcVar2,(int)pcVar5,param_2,param_3);
      if (iVar3 != 0) goto LAB_1000a33e;
    }
    iVar3 = FUN_1000ce65(pcVar2 + param_3,(int)pcVar5 - param_3,(int)param_1,(int)pcVar4);
    if (iVar3 != 0) {
LAB_1000a33e:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    iVar3 = expand_if_necessary(param_4);
    if (iVar3 == 0) {
      *(char **)param_4[1] = pcVar2;
      iVar3 = 0;
      param_4[1] = param_4[1] + 4;
    }
    else {
      FUN_10009f36(pcVar2);
    }
    FUN_10009f36((LPVOID)0x0);
  }
  return iVar3;
}



/* VA 1000a34b */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl FUN_1000a34b(uchar *param_1,uchar *param_2,int *param_3)

{
  uchar uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  HANDLE hFindFile;
  int iVar5;
  char *pcVar6;
  BOOL BVar7;
  undefined4 local_290;
  undefined4 local_28c;
  LPVOID local_288;
  undefined4 local_284;
  undefined4 local_280;
  char local_27c;
  undefined4 local_278;
  undefined4 local_274;
  LPVOID local_270;
  undefined4 local_26c;
  undefined4 local_268;
  char local_264;
  int *local_260;
  uchar local_259;
  _WIN32_FIND_DATAW local_258;
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  local_260 = param_3;
  for (; (((param_2 != param_1 && (uVar1 = *param_2, uVar1 != '/')) && (uVar1 != '\\')) &&
         (uVar1 != ':')); param_2 = __mbsdec(param_1,param_2)) {
  }
  local_259 = *param_2;
  if ((local_259 == ':') && (param_2 != param_1 + 1)) {
    iVar3 = FUN_1000a29a((char *)param_1,0,0,local_260);
  }
  else {
    if ((local_259 == '/') || ((local_259 == '\\' || (bVar2 = 0, local_259 == ':')))) {
      bVar2 = 1;
    }
    local_290 = 0;
    local_28c = 0;
    local_288 = (LPVOID)0x0;
    local_284 = 0;
    local_280 = 0;
    local_27c = '\0';
    uVar4 = __acrt_get_utf8_acp_compatibility_codepage();
    iVar3 = __acrt_mbs_to_wcs_cp<__crt_win32_buffer_internal_dynamic_resizing>
                      ((char *)param_1,
                       (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> *)
                       &local_290,uVar4);
    hFindFile = FindFirstFileExW((LPCWSTR)(~-(uint)(iVar3 != 0) & (uint)local_288),
                                 FindExInfoStandard,&local_258,FindExSearchNameMatch,(LPVOID)0x0,0);
    if (hFindFile == (HANDLE)0xffffffff) {
      iVar3 = FUN_1000a29a((char *)param_1,0,0,local_260);
      if (local_27c != '\0') {
        FUN_10009f36(local_288);
      }
    }
    else {
      iVar3 = local_260[1] - *local_260 >> 2;
      do {
        local_278 = 0;
        local_274 = 0;
        local_270 = (LPVOID)0x0;
        local_26c = 0;
        local_268 = 0;
        local_264 = '\0';
        uVar4 = __acrt_get_utf8_acp_compatibility_codepage();
        iVar5 = FUN_1000a03a(local_258.cFileName,
                             (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>
                              *)&local_278,&local_259,uVar4);
        pcVar6 = (char *)(~-(uint)(iVar5 != 0) & (uint)local_270);
        if (((*pcVar6 != '.') ||
            ((pcVar6[1] != '\0' && ((pcVar6[1] != '.' || (pcVar6[2] != '\0')))))) &&
           (iVar5 = FUN_1000a29a(pcVar6,(int)param_1,
                                 -(uint)bVar2 & (uint)(param_2 + (1 - (int)param_1)),local_260),
           iVar5 != 0)) {
          if (local_264 != '\0') {
            FUN_10009f36(local_270);
          }
          FindClose(hFindFile);
          if (local_27c == '\0') {
            return iVar5;
          }
          FUN_10009f36(local_288);
          return iVar5;
        }
        if (local_264 != '\0') {
          FUN_10009f36(local_270);
        }
        BVar7 = FindNextFileW(hFindFile,&local_258);
      } while (BVar7 != 0);
      iVar5 = local_260[1] - *local_260 >> 2;
      if (iVar3 != iVar5) {
        _qsort((void *)(*local_260 + iVar3 * 4),iVar5 - iVar3,4,FUN_10009f70);
      }
      FindClose(hFindFile);
      if (local_27c != '\0') {
        FUN_10009f36(local_288);
      }
      iVar3 = 0;
    }
  }
  return iVar3;
}



/* VA 1000a5d0 */

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall `anonymous namespace'::argument_list<char>::~argument_list<char>(void)
    public: __thiscall `anonymous namespace'::argument_list<char>::~argument_list<char>(void)
    public: __thiscall `anonymous namespace'::argument_list<wchar_t>::~argument_list<wchar_t>(void)
    public: __thiscall `anonymous namespace'::argument_list<wchar_t>::~argument_list<wchar_t>(void)

   Library: Visual Studio 2015 Release */

void __fastcall ~argument_list<>(undefined4 *param_1)

{
  undefined4 *puVar1;

  for (puVar1 = (undefined4 *)*param_1; puVar1 != (undefined4 *)param_1[1]; puVar1 = puVar1 + 1) {
    FUN_10009f36((LPVOID)*puVar1);
  }
  FUN_10009f36((LPVOID)*param_1);
  return;
}



/* VA 1000a5f5 */

void FUN_1000a5f5(uint param_1,LPCWSTR param_2,LPSTR param_3,int param_4)

{
  FUN_1000b36c(param_1,0,param_2,-1,param_3,param_4,0,(undefined4 *)0x0);
  return;
}



/* VA 1000a619 */

/* Library Function - Single Match
    unsigned int __cdecl __acrt_get_utf8_acp_compatibility_codepage(void)

   Library: Visual Studio 2019 Release */

uint __cdecl __acrt_get_utf8_acp_compatibility_codepage(void)

{
  int iVar1;
  uint uVar2;
  int local_14;
  int local_10;
  char local_8;

  FUN_10007c04(&local_14,(int *)0x0);
  uVar2 = 0xfde9;
  if (*(int *)(local_10 + 8) != 0xfde9) {
    iVar1 = ___acrt_AreFileApisANSI_0();
    uVar2 = 0;
    if (iVar1 == 0) {
      uVar2 = 1;
    }
  }
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return uVar2;
}



/* VA 1000a658 */

/* Library Function - Single Match
    private: void __thiscall __crt_win32_buffer<wchar_t,struct
   __crt_win32_buffer_internal_dynamic_resizing>::_deallocate(void)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __thiscall
__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::_deallocate
          (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> *this)

{
  if (this[0x14] != (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>)0x0) {
    FUN_10009f36(*(LPVOID *)(this + 8));
    this[0x14] = (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>)0x0;
  }
  return;
}



/* VA 1000a672 */

/* Library Function - Multiple Matches With Same Base Name
    public: int __thiscall __crt_win32_buffer<char,struct
   __crt_win32_buffer_internal_dynamic_resizing>::allocate(unsigned int)
    public: int __thiscall __crt_win32_buffer<char,struct
   __crt_win32_buffer_public_dynamic_resizing>::allocate(unsigned int)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __thiscall allocate(void *this,uint param_1)

{
  int iVar1;

  __crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::_deallocate(this);
  iVar1 = __crt_win32_buffer_internal_dynamic_resizing::allocate
                    ((void **)((int)this + 8),param_1,this);
  if (iVar1 == 0) {
    *(undefined1 *)((int)this + 0x14) = 1;
    iVar1 = 0;
    *(uint *)((int)this + 0xc) = param_1;
  }
  else {
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined1 *)((int)this + 0x14) = 0;
  }
  return iVar1;
}



/* VA 1000a6ae */

/* Library Function - Single Match
    public: int __thiscall __crt_win32_buffer<wchar_t,struct
   __crt_win32_buffer_internal_dynamic_resizing>::allocate(unsigned int)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __thiscall
__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>::allocate
          (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing> *this,
          uint param_1)

{
  int iVar1;

  _deallocate(this);
  iVar1 = __crt_win32_buffer_internal_dynamic_resizing::allocate
                    ((void **)(this + 8),param_1 * 2,(__crt_win32_buffer_empty_debug_info *)this);
  if (iVar1 == 0) {
    this[0x14] = (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>)0x1;
    iVar1 = 0;
    *(uint *)(this + 0xc) = param_1;
  }
  else {
    *(undefined4 *)(this + 0xc) = 0;
    this[0x14] = (__crt_win32_buffer<wchar_t,__crt_win32_buffer_internal_dynamic_resizing>)0x0;
  }
  return iVar1;
}



/* VA 1000a6ed */

/* Library Function - Single Match
    public: static int __cdecl __crt_win32_buffer_internal_dynamic_resizing::allocate(void * *
   const,unsigned int,class __crt_win32_buffer_empty_debug_info const &)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl
__crt_win32_buffer_internal_dynamic_resizing::allocate
          (void **param_1,uint param_2,__crt_win32_buffer_empty_debug_info *param_3)

{
  LPVOID pvVar1;

  pvVar1 = __malloc_base(param_2);
  *param_1 = pvVar1;
  return (-(uint)(pvVar1 != (LPVOID)0x0) & 0xfffffff4) + 0xc;
}



/* VA 1000a70c */

/* Library Function - Multiple Matches With Same Base Name
    private: int __thiscall `anonymous namespace'::argument_list<char>::expand_if_necessary(void)
    private: int __thiscall `anonymous namespace'::argument_list<wchar_t>::expand_if_necessary(void)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __fastcall expand_if_necessary(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  uint uVar4;

  if (param_1[1] == param_1[2]) {
    if (*param_1 == 0) {
      pvVar3 = __calloc_base(4,4);
      *param_1 = (int)pvVar3;
      FUN_10009f36((LPVOID)0x0);
      iVar1 = *param_1;
      if (iVar1 != 0) {
        param_1[1] = iVar1;
        param_1[2] = iVar1 + 0x10;
        goto LAB_1000a71a;
      }
    }
    else {
      uVar4 = param_1[2] - *param_1 >> 2;
      if (uVar4 < 0x80000000) {
        pvVar3 = __recalloc_base((void *)*param_1,uVar4 * 2,4);
        if (pvVar3 == (LPVOID)0x0) {
          uVar2 = 0xc;
        }
        else {
          *param_1 = (int)pvVar3;
          param_1[1] = (int)((int)pvVar3 + uVar4 * 4);
          param_1[2] = (int)((int)pvVar3 + uVar4 * 8);
          uVar2 = 0;
        }
        FUN_10009f36((LPVOID)0x0);
        return uVar2;
      }
    }
    uVar2 = 0xc;
  }
  else {
LAB_1000a71a:
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 1000a793 */

void __cdecl FUN_1000a793(undefined4 *param_1,undefined4 *param_2)

{
  FUN_1000a11d(param_1,param_2);
  return;
}



/* VA 1000a79e */

int __cdecl FUN_1000a79e(LPCWSTR param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  __acrt_ptd *p_Var4;

  if (param_1 == (LPCWSTR)0x0) {
    FUN_1000a887(param_2);
    iVar1 = 0;
  }
  else if (*param_1 == L'\0') {
    if ((*(int *)(param_2 + 0xc) != 0) || (iVar1 = allocate(param_2), iVar1 == 0)) {
      **(undefined1 **)(param_2 + 8) = 0;
      iVar1 = 0;
      *(undefined4 *)(param_2 + 0x10) = 0;
    }
  }
  else {
    uVar2 = FUN_1000b36c(param_4,0,param_1,-1,(LPSTR)0x0,0,0,(undefined4 *)0x0);
    if (uVar2 == 0) {
      DVar3 = GetLastError();
      ___acrt_errno_map_os_error(DVar3);
      p_Var4 = FUN_100095db();
      iVar1 = *(int *)p_Var4;
    }
    else if ((uVar2 <= *(uint *)(param_2 + 0xc)) || (iVar1 = allocate(param_2), iVar1 == 0)) {
      iVar1 = FUN_1000a5f5(param_4,param_1,*(LPSTR *)(param_2 + 8),*(int *)(param_2 + 0xc));
      if (iVar1 == 0) {
        DVar3 = GetLastError();
        ___acrt_errno_map_os_error(DVar3);
        p_Var4 = FUN_100095db();
        iVar1 = *(int *)p_Var4;
      }
      else {
        *(int *)(param_2 + 0x10) = iVar1 + -1;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* VA 1000a860 */

/* Library Function - Multiple Matches With Same Base Name
    public: int __thiscall __crt_win32_buffer<char,struct
   __crt_win32_buffer_no_resizing>::allocate(unsigned int)
    public: int __thiscall __crt_win32_buffer<wchar_t,struct
   __crt_win32_buffer_no_resizing>::allocate(unsigned int)

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

undefined4 __fastcall allocate(int param_1)

{
  __acrt_ptd *p_Var1;

  if (*(char *)(param_1 + 0x14) != '\0') {
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  p_Var1 = FUN_100095db();
  *(undefined4 *)p_Var1 = 0x22;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  return 0x22;
}



/* VA 1000a887 */

void __fastcall FUN_1000a887(int param_1)

{
  if (*(char *)(param_1 + 0x14) != '\0') {
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* VA 1000a89b */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    ___acrt_GetModuleFileNameA

   Library: Visual Studio 2019 Release */

undefined4 __cdecl ___acrt_GetModuleFileNameA(HMODULE param_1,undefined4 param_2,undefined4 param_3)

{
  DWORD DVar1;
  uint uVar2;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined1 local_21c;
  undefined1 local_215;
  WCHAR local_214 [262];
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  DVar1 = GetModuleFileNameW(param_1,local_214,0x105);
  if (DVar1 == 0) {
    DVar1 = GetLastError();
    ___acrt_errno_map_os_error(DVar1);
    local_220 = 0;
  }
  else {
    local_220 = 0;
    local_230 = param_2;
    local_22c = param_3;
    local_228 = param_2;
    local_224 = param_3;
    local_21c = 0;
    uVar2 = __acrt_get_utf8_acp_compatibility_codepage();
    FUN_1000a79e(local_214,(int)&local_230,&local_215,uVar2);
  }
  return local_220;
}



/* VA 1000a93c */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_ceb1ee4838e85a9d631eb091e2fbe199>,class <lambda_ae742caa10f662c28703da3d2ea5e57e> &,class
   <lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> >(class <lambda_ceb1ee4838e85a9d631eb091e2fbe199>
   &&,class <lambda_ae742caa10f662c28703da3d2ea5e57e> &,class
   <lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> &&)

   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<<lambda_ceb1ee4838e85a9d631eb091e2fbe199>,<lambda_ae742caa10f662c28703da3d2ea5e57e>&,<lambda_cd08b5d6af4937fe54fc07d0c9bf6b37>_>
          (__crt_seh_guarded_call<void> *this,<lambda_ceb1ee4838e85a9d631eb091e2fbe199> *param_1,
          <lambda_ae742caa10f662c28703da3d2ea5e57e> *param_2,
          <lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> *param_3)

{
  undefined4 local_14;

  ___acrt_lock(*(int *)param_1);
  <lambda_ae742caa10f662c28703da3d2ea5e57e>::operator()(param_2);
  FUN_1000a97d();
  ExceptionList = local_14;
  return;
}



/* VA 1000a97d */

void FUN_1000a97d(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 1000a989 */

/* Library Function - Single Match
    public: void __thiscall <lambda_ae742caa10f662c28703da3d2ea5e57e>::operator()(void)const

   Library: Visual Studio 2019 Release */

void __thiscall
<lambda_ae742caa10f662c28703da3d2ea5e57e>::operator()
          (<lambda_ae742caa10f662c28703da3d2ea5e57e> *this)

{
  int iVar1;

  _memcpy_s(DAT_1001a064,0x101,(void *)(*(int *)(**(int **)this + 0x48) + 0x18),0x101);
  _memcpy_s(DAT_1001a068,0x100,(void *)(*(int *)(**(int **)this + 0x48) + 0x119),0x100);
  LOCK();
  iVar1 = **(int **)**(undefined4 **)(this + 4) + -1;
  **(int **)**(undefined4 **)(this + 4) = iVar1;
  UNLOCK();
  if ((iVar1 == 0) && (*(undefined **)**(undefined4 **)(this + 4) != &DAT_10019118)) {
    FUN_10009f36(*(LPVOID *)**(undefined4 **)(this + 4));
  }
  *(undefined4 *)**(undefined4 **)(this + 4) = *(undefined4 *)(**(int **)this + 0x48);
  LOCK();
  **(int **)(**(int **)this + 0x48) = **(int **)(**(int **)this + 0x48) + 1;
  UNLOCK();
  return;
}



/* VA 1000aa0c */

/* Library Function - Single Match
    wchar_t const * __cdecl CPtoLocaleName(int)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

wchar_t * __cdecl CPtoLocaleName(int param_1)

{
  if (param_1 == 0x3a4) {
    return (wchar_t *)PTR_u_ja_JP_10012490;
  }
  if (param_1 == 0x3a8) {
    return (wchar_t *)PTR_u_zh_CN_10012494;
  }
  if (param_1 == 0x3b5) {
    return (wchar_t *)PTR_u_ko_KR_10012498;
  }
  if (param_1 != 0x3b6) {
    return (wchar_t *)0x0;
  }
  return (wchar_t *)PTR_u_zh_TW_1001249c;
}



/* VA 1000aa4a */

/* Library Function - Single Match
    int __cdecl getSystemCP(int)

   Library: Visual Studio 2019 Release */

int __cdecl getSystemCP(int param_1)

{
  int local_14;
  int local_10;
  char local_8;

  FUN_10007c04(&local_14,(int *)0x0);
  DAT_1001a070 = 0;
  if (param_1 == -2) {
    DAT_1001a070 = 1;
    param_1 = GetOEMCP();
  }
  else if (param_1 == -3) {
    DAT_1001a070 = 1;
    param_1 = GetACP();
  }
  else if (param_1 == -4) {
    DAT_1001a070 = 1;
    param_1 = *(UINT *)(local_10 + 8);
  }
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return param_1;
}



/* VA 1000aabb */

void __cdecl FUN_1000aabb(int param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  _memset((void *)(param_1 + 0x18),0,0x101);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x21c) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  do {
    *(undefined1 *)(param_1 + 0x18 + iVar1) = (&DAT_10019130)[iVar1];
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x101);
  do {
    *(undefined1 *)(param_1 + 0x119 + iVar2) = (&DAT_10019231)[iVar2];
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x100);
  return;
}



/* VA 1000ab1e */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl FUN_1000ab1e(int param_1)

{
  char cVar1;
  byte bVar2;
  BOOL BVar3;
  uint uVar4;
  byte *pbVar5;
  BYTE *pBVar6;
  int iVar7;
  int iVar8;
  _cpinfo local_71c;
  WORD local_708 [512];
  WCHAR local_308 [128];
  WCHAR local_208 [128];
  CHAR local_108 [256];
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(param_1 + 4) == 0xfde9) ||
     (BVar3 = GetCPInfo(*(UINT *)(param_1 + 4),&local_71c), BVar3 == 0)) {
    pbVar5 = (byte *)(param_1 + 0x19);
    do {
      if (pbVar5 + (-0x5a - param_1) < (byte *)0x1a) {
        *pbVar5 = *pbVar5 | 0x10;
        cVar1 = (char)pbVar5 + ' ';
LAB_1000ac9a:
        bVar2 = cVar1 + (char)(-0x19 - param_1);
      }
      else {
        if (pbVar5 + (-0x7a - param_1) < (byte *)0x1a) {
          *pbVar5 = *pbVar5 | 0x20;
          cVar1 = (char)pbVar5 + -0x20;
          goto LAB_1000ac9a;
        }
        bVar2 = 0;
      }
      pbVar5[0x100] = bVar2;
      pbVar5 = pbVar5 + 1;
    } while (pbVar5 + (-0x19 - param_1) < (byte *)0x100);
  }
  else {
    iVar8 = 0x100;
    uVar4 = 0;
    do {
      local_108[uVar4] = (CHAR)uVar4;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
    pBVar6 = local_71c.LeadByte;
    local_108[0] = ' ';
    while (local_71c.LeadByte[0] != 0) {
      bVar2 = pBVar6[1];
      for (uVar4 = (uint)local_71c.LeadByte[0]; (uVar4 <= bVar2 && (uVar4 < 0x100));
          uVar4 = uVar4 + 1) {
        local_108[uVar4] = ' ';
      }
      pBVar6 = pBVar6 + 2;
      local_71c.LeadByte[0] = *pBVar6;
    }
    FUN_1000c794((int *)0x0,1,local_108,0x100,local_708,*(uint *)(param_1 + 4),0);
    ___acrt_LCMapStringA
              ((int *)0x0,*(wchar_t **)(param_1 + 0x21c),0x100,local_108,0x100,local_208,0x100,
               *(uint *)(param_1 + 4),0);
    ___acrt_LCMapStringA
              ((int *)0x0,*(wchar_t **)(param_1 + 0x21c),0x200,local_108,0x100,local_308,0x100,
               *(uint *)(param_1 + 4),0);
    pbVar5 = (byte *)(param_1 + 0x19);
    iVar7 = 0;
    do {
      if ((local_708[iVar7] & 1) == 0) {
        if ((local_708[iVar7] & 2) == 0) {
          bVar2 = 0;
        }
        else {
          *pbVar5 = *pbVar5 | 0x20;
          bVar2 = *(byte *)((int)local_308 + iVar7);
        }
      }
      else {
        *pbVar5 = *pbVar5 | 0x10;
        bVar2 = *(byte *)((int)local_208 + iVar7);
      }
      iVar7 = iVar7 + 1;
      pbVar5[0x100] = bVar2;
      pbVar5 = pbVar5 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  return;
}



/* VA 1000acc3 */

int __cdecl FUN_1000acc3(int param_1,char param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  __acrt_ptd *p_Var4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_248 [137];
  int *local_24;
  undefined4 **local_20;
  int local_1c;
  __crt_seh_guarded_call<void> local_15;
  undefined4 *local_14;

  FUN_1000ae18(param_3,param_4);
  local_1c = getSystemCP(param_1);
  if (local_1c == *(int *)(*(int *)(param_3 + 0x48) + 4)) {
    iVar2 = 0;
  }
  else {
    puVar3 = __malloc_base(0x220);
    iVar2 = local_1c;
    local_14 = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      FUN_10009f36((LPVOID)0x0);
      iVar2 = -1;
    }
    else {
      puVar6 = *(undefined4 **)(param_3 + 0x48);
      puVar7 = local_248;
      for (iVar5 = 0x88; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar6 = local_248;
      puVar7 = puVar3;
      for (iVar5 = 0x88; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      *puVar3 = 0;
      iVar2 = FUN_1000af13(iVar2,(int)puVar3);
      if (iVar2 == -1) {
        p_Var4 = FUN_100095db();
        *(undefined4 *)p_Var4 = 0x16;
        FUN_10009f36(local_14);
        iVar2 = -1;
      }
      else {
        if (param_2 == '\0') {
          FUN_10009d6d();
        }
        piVar1 = *(int **)(param_3 + 0x48);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if ((iVar5 == 1) && (*(undefined **)(param_3 + 0x48) != &DAT_10019118)) {
          FUN_10009f36(*(LPVOID *)(param_3 + 0x48));
        }
        *local_14 = 1;
        *(undefined4 **)(param_3 + 0x48) = local_14;
        if ((*(uint *)(param_3 + 0x350) & DAT_100196e0) == 0) {
          local_24 = &param_3;
          local_20 = &param_4;
          local_1c = 5;
          local_14 = (undefined4 *)0x5;
          __crt_seh_guarded_call<void>::
          operator()<<lambda_ceb1ee4838e85a9d631eb091e2fbe199>,<lambda_ae742caa10f662c28703da3d2ea5e57e>&,<lambda_cd08b5d6af4937fe54fc07d0c9bf6b37>_>
                    (&local_15,(<lambda_ceb1ee4838e85a9d631eb091e2fbe199> *)&local_14,
                     (<lambda_ae742caa10f662c28703da3d2ea5e57e> *)&local_24,
                     (<lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> *)&local_1c);
          if (param_2 != '\0') {
            PTR_DAT_1001910c = (undefined *)*param_4;
          }
        }
        FUN_10009f36((LPVOID)0x0);
      }
    }
  }
  return iVar2;
}



/* VA 1000ae18 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

void FUN_1000ae18(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;

  if (((*(uint *)(param_1 + 0x350) & DAT_100196e0) == 0) || (*(int *)(param_1 + 0x4c) == 0)) {
    ___acrt_lock(5);
    piVar2 = *(int **)(param_1 + 0x48);
    if (piVar2 != (int *)*param_2) {
      if (piVar2 != (int *)0x0) {
        LOCK();
        iVar1 = *piVar2;
        *piVar2 = iVar1 + -1;
        UNLOCK();
        if ((iVar1 + -1 == 0) && (piVar2 != (int *)&DAT_10019118)) {
          FUN_10009f36(piVar2);
        }
      }
      piVar2 = (int *)*param_2;
      *(int **)(param_1 + 0x48) = piVar2;
      LOCK();
      *piVar2 = *piVar2 + 1;
      UNLOCK();
    }
    FUN_1000ae97();
  }
  else {
    piVar2 = *(int **)(param_1 + 0x48);
  }
  if (piVar2 != (int *)0x0) {
    FUN_1000aea0();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 1000ae97 */

void FUN_1000ae97(void)

{
  ___acrt_unlock(5);
  return;
}



/* VA 1000aea0 */

void FUN_1000aea0(void)

{
  int unaff_EBP;

  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}



/* VA 1000aeb8 */

/* Library Function - Single Match
    ___acrt_initialize_multibyte

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 ___acrt_initialize_multibyte(void)

{
  int in_EAX;
  __acrt_ptd *p_Var1;

  if (DAT_1001a074 == '\0') {
    DAT_1001a06c = &DAT_10019118;
    DAT_1001a068 = &DAT_10019440;
    DAT_1001a064 = &DAT_10019338;
    p_Var1 = FUN_10009a13();
    in_EAX = FUN_1000acc3(-3,'\x01',(int)p_Var1,&DAT_1001a06c);
    DAT_1001a074 = '\x01';
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



/* VA 1000af00 */

void FUN_1000af00(void)

{
  __acrt_ptd *p_Var1;

  p_Var1 = FUN_10009958();
  FUN_1000ae18((int)p_Var1,&DAT_1001a06c);
  return;
}



/* VA 1000af13 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __cdecl FUN_1000af13(int param_1,int param_2)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  wchar_t *pwVar7;
  int iVar8;
  byte *pbVar9;
  undefined2 *puVar10;
  byte *pbVar11;
  undefined2 *puVar12;
  byte *pbVar13;
  uint uVar14;
  int local_20;
  _cpinfo local_1c;
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  uVar3 = getSystemCP(param_1);
  if (uVar3 == 0) {
LAB_1000b100:
    FUN_1000aabb(param_2);
    return 0;
  }
  uVar14 = 0;
  uVar4 = 0;
  local_20 = 0;
  do {
    if (*(uint *)((int)&DAT_10019548 + uVar4) == uVar3) {
      _memset((void *)(param_2 + 0x18),0,0x101);
      pbVar11 = (byte *)(local_20 * 0x30 + 0x10019558);
      do {
        bVar1 = *pbVar11;
        pbVar9 = pbVar11;
        while ((bVar1 != 0 && (pbVar9[1] != 0))) {
          uVar4 = (uint)*pbVar9;
          if (uVar4 <= pbVar9[1]) {
            pbVar13 = (byte *)(param_2 + 0x19 + uVar4);
            do {
              if (0xff < uVar4) break;
              *pbVar13 = *pbVar13 | (&DAT_10019540)[uVar14];
              uVar4 = uVar4 + 1;
              pbVar13 = pbVar13 + 1;
            } while (uVar4 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar1 = *pbVar9;
        }
        uVar14 = uVar14 + 1;
        pbVar11 = pbVar11 + 8;
      } while (uVar14 < 4);
      *(uint *)(param_2 + 4) = uVar3;
      *(undefined4 *)(param_2 + 8) = 1;
      pwVar7 = CPtoLocaleName(uVar3);
      *(wchar_t **)(param_2 + 0x21c) = pwVar7;
      puVar10 = (undefined2 *)(param_2 + 0xc);
      puVar12 = (undefined2 *)(local_20 * 0x30 + 0x1001954c);
      iVar8 = 6;
      do {
        uVar2 = *puVar12;
        puVar12 = puVar12 + 1;
        *puVar10 = uVar2;
        puVar10 = puVar10 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      goto LAB_1000b0f8;
    }
    local_20 = local_20 + 1;
    uVar4 = uVar4 + 0x30;
  } while (uVar4 < 0xf0);
  if ((uVar3 == 65000) || (BVar5 = IsValidCodePage(uVar3 & 0xffff), BVar5 == 0)) {
    return 0xffffffff;
  }
  if (uVar3 == 0xfde9) {
    *(undefined4 *)(param_2 + 4) = 0xfde9;
    *(undefined4 *)(param_2 + 0x21c) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined2 *)(param_2 + 0x1c) = 0;
  }
  else {
    BVar5 = GetCPInfo(uVar3,&local_1c);
    if (BVar5 == 0) {
      if (DAT_1001a070 == 0) {
        return 0xffffffff;
      }
      goto LAB_1000b100;
    }
    _memset((void *)(param_2 + 0x18),0,0x101);
    *(uint *)(param_2 + 4) = uVar3;
    *(undefined4 *)(param_2 + 0x21c) = 0;
    if (local_1c.MaxCharSize == 2) {
      pBVar6 = local_1c.LeadByte;
      while ((local_1c.LeadByte[0] != 0 && (bVar1 = pBVar6[1], bVar1 != 0))) {
        uVar3 = (uint)*pBVar6;
        if (uVar3 <= bVar1) {
          pbVar11 = (byte *)(param_2 + 0x19 + uVar3);
          iVar8 = (bVar1 - uVar3) + 1;
          do {
            *pbVar11 = *pbVar11 | 4;
            pbVar11 = pbVar11 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        pBVar6 = pBVar6 + 2;
        local_1c.LeadByte[0] = *pBVar6;
      }
      pbVar11 = (byte *)(param_2 + 0x1a);
      iVar8 = 0xfe;
      do {
        *pbVar11 = *pbVar11 | 8;
        pbVar11 = pbVar11 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      pwVar7 = CPtoLocaleName(*(int *)(param_2 + 4));
      *(wchar_t **)(param_2 + 0x21c) = pwVar7;
      uVar14 = 1;
    }
  }
  *(uint *)(param_2 + 8) = uVar14;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
LAB_1000b0f8:
  FUN_1000ab1e(param_2);
  return 0;
}



/* VA 1000b118 */

/* Library Function - Single Match
    _memcpy_s

   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

errno_t __cdecl _memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  __acrt_ptd *p_Var2;

  if (_MaxCount == 0) {
    eVar1 = 0;
  }
  else if (_Dst == (void *)0x0) {
    p_Var2 = FUN_100095db();
    eVar1 = 0x16;
    *(undefined4 *)p_Var2 = 0x16;
    FUN_100080a4();
  }
  else if ((_Src == (void *)0x0) || (_DstSize < _MaxCount)) {
    _memset(_Dst,0,_DstSize);
    if (_Src == (void *)0x0) {
      p_Var2 = FUN_100095db();
      eVar1 = 0x16;
    }
    else {
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      p_Var2 = FUN_100095db();
      eVar1 = 0x22;
    }
    *(errno_t *)p_Var2 = eVar1;
    FUN_100080a4();
  }
  else {
    FUN_10007600(_Dst,_Src,_MaxCount);
    eVar1 = 0;
  }
  return eVar1;
}



/* VA 1000b199 */

undefined4 __cdecl FUN_1000b199(int *param_1,byte param_2,uint param_3,byte param_4)

{
  undefined4 uVar1;
  int local_14;
  int *local_10;
  int local_c;
  char local_8;

  FUN_10007c04(&local_14,param_1);
  if (((*(byte *)(local_c + 0x19 + (uint)param_2) & param_4) == 0) &&
     ((param_3 == 0 || ((param_3 & *(ushort *)(*local_10 + (uint)param_2 * 2)) == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return uVar1;
}



/* VA 1000b1e9 */

void __cdecl FUN_1000b1e9(byte param_1)

{
  FUN_1000b199((int *)0x0,param_1,0,4);
  return;
}



/* VA 1000b21a */

uint __cdecl FUN_1000b21a(uint param_1,uint param_2)

{
  int iVar1;

  if (param_1 < 0xdead) {
    if (param_1 == 0xdeac) {
      return 0;
    }
    if (param_1 < 0xc434) {
      if (param_1 == 0xc433) {
        return 0;
      }
      if (param_1 == 0x2a) {
        return 0;
      }
      if (param_1 == 0xc42c) {
        return 0;
      }
      if (param_1 == 0xc42d) {
        return 0;
      }
      if (param_1 == 0xc42e) {
        return 0;
      }
      iVar1 = param_1 - 0xc431;
      goto LAB_1000b251;
    }
    if (param_1 == 0xc435) {
      return 0;
    }
    if (param_1 == 0xd698) goto LAB_1000b2aa;
    iVar1 = param_1 - 0xdeaa;
  }
  else {
    if (0xdeb1 < param_1) {
      if (param_1 == 0xdeb2) {
        return 0;
      }
      if (param_1 == 0xdeb3) {
        return 0;
      }
      if (param_1 == 65000) {
        return 0;
      }
      if (param_1 != 0xfde9) {
        return param_2;
      }
LAB_1000b2aa:
      return param_2 & 8;
    }
    if (param_1 == 0xdeb1) {
      return 0;
    }
    if (param_1 == 0xdead) {
      return 0;
    }
    if (param_1 == 0xdeae) {
      return 0;
    }
    iVar1 = param_1 - 0xdeaf;
  }
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = iVar1 + -1;
LAB_1000b251:
  if (iVar1 == 0) {
    return 0;
  }
  return param_2;
}



/* VA 1000b2b2 */

void __cdecl
FUN_1000b2b2(uint param_1,uint param_2,LPCSTR param_3,int param_4,LPWSTR param_5,int param_6)

{
  uint dwFlags;

  dwFlags = FUN_1000b21a(param_1,param_2);
  MultiByteToWideChar(param_1,dwFlags,param_3,param_4,param_5,param_6);
  return;
}



/* VA 1000b2dc */

uint __cdecl FUN_1000b2dc(uint param_1,uint param_2)

{
  int iVar1;
  bool bVar2;

  if (param_1 < 0xdead) {
    if (param_1 == 0xdeac) {
      return 0;
    }
    if (param_1 < 0xc434) {
      if (param_1 == 0xc433) {
        return 0;
      }
      if (param_1 == 0x2a) {
        return 0;
      }
      if (param_1 == 0xc42c) {
        return 0;
      }
      if (param_1 == 0xc42d) {
        return 0;
      }
      if (param_1 == 0xc42e) {
        return 0;
      }
      iVar1 = param_1 - 0xc431;
      goto LAB_1000b35c;
    }
    if (param_1 == 0xc435) {
      return 0;
    }
    if (param_1 == 0xd698) {
      return 0;
    }
    iVar1 = param_1 - 0xdeaa;
    bVar2 = iVar1 == 0;
  }
  else if (param_1 < 0xdeb2) {
    if (param_1 == 0xdeb1) {
      return 0;
    }
    if (param_1 == 0xdead) {
      return 0;
    }
    if (param_1 == 0xdeae) {
      return 0;
    }
    iVar1 = param_1 - 0xdeaf;
    bVar2 = iVar1 == 0;
  }
  else {
    if (param_1 == 0xdeb2) {
      return 0;
    }
    if (param_1 == 0xdeb3) {
      return 0;
    }
    iVar1 = param_1 - 65000;
    bVar2 = iVar1 == 0;
  }
  if (bVar2) {
    return 0;
  }
  iVar1 = iVar1 + -1;
LAB_1000b35c:
  if (iVar1 == 0) {
    return 0;
  }
  return param_2 & 0xffffff7f;
}



/* VA 1000b36c */

void __cdecl
FUN_1000b36c(uint param_1,uint param_2,LPCWSTR param_3,int param_4,LPSTR param_5,int param_6,
            uint param_7,undefined4 *param_8)

{
  bool bVar1;
  uint dwFlags;
  UINT CodePage;

  if ((param_1 == 65000) || (param_1 == 0xfde9)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  dwFlags = FUN_1000b2dc(param_1,param_2);
  if ((bVar1) && (param_8 != (undefined4 *)0x0)) {
    *param_8 = 0;
  }
  WideCharToMultiByte(CodePage,dwFlags,param_3,param_4,param_5,param_6,
                      (LPCSTR)(~-(uint)bVar1 & param_7),(LPBOOL)(~-(uint)bVar1 & (uint)param_8));
  return;
}



/* VA 1000b3d8 */

/* Library Function - Single Match
    wchar_t const * __cdecl find_end_of_double_null_terminated_sequence(wchar_t const * const)

   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

wchar_t * __cdecl find_end_of_double_null_terminated_sequence(wchar_t *param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;

  wVar1 = *param_1;
  while (wVar1 != L'\0') {
    pwVar2 = param_1;
    do {
      wVar1 = *pwVar2;
      pwVar2 = pwVar2 + 1;
    } while (wVar1 != L'\0');
    param_1 = param_1 + ((int)pwVar2 - (int)(param_1 + 1) >> 1) + 1;
    wVar1 = *param_1;
  }
  return param_1 + 1;
}



/* VA 1000b40f */

LPSTR FUN_1000b40f(void)

{
  LPWCH pWVar1;
  wchar_t *pwVar2;
  int iVar3;
  SIZE_T SVar4;
  LPSTR pCVar5;

  pWVar1 = GetEnvironmentStringsW();
  pCVar5 = (LPSTR)0x0;
  if (pWVar1 != (LPWCH)0x0) {
    pwVar2 = find_end_of_double_null_terminated_sequence(pWVar1);
    iVar3 = (int)pwVar2 - (int)pWVar1 >> 1;
    SVar4 = FUN_1000b36c(0,0,pWVar1,iVar3,(LPSTR)0x0,0,0,(undefined4 *)0x0);
    if (SVar4 == 0) {
      FreeEnvironmentStringsW(pWVar1);
      pCVar5 = (LPSTR)0x0;
    }
    else {
      pCVar5 = __malloc_base(SVar4);
      if (pCVar5 == (LPSTR)0x0) {
        FUN_10009f36((LPVOID)0x0);
        FreeEnvironmentStringsW(pWVar1);
        pCVar5 = (LPSTR)0x0;
      }
      else {
        iVar3 = FUN_1000b36c(0,0,pWVar1,iVar3,pCVar5,SVar4,0,(undefined4 *)0x0);
        if (iVar3 == 0) {
          FUN_10009f36(pCVar5);
          pCVar5 = (LPSTR)0x0;
        }
        else {
          FUN_10009f36((LPVOID)0x0);
        }
        FreeEnvironmentStringsW(pWVar1);
      }
    }
  }
  return pCVar5;
}



/* VA 1000b4af */

/* Library Function - Single Match
    __recalloc_base

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID __cdecl __recalloc_base(void *param_1,uint param_2,uint param_3)

{
  __acrt_ptd *p_Var1;
  LPVOID pvVar2;
  size_t sVar3;
  uint uVar4;

  if ((param_2 == 0) || (param_3 <= 0xffffffe0 / param_2)) {
    if (param_1 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = FID_conflict___msize_base(param_1);
    }
    uVar4 = param_2 * param_3;
    pvVar2 = __realloc_base(param_1,uVar4);
    if ((pvVar2 != (LPVOID)0x0) && (sVar3 < uVar4)) {
      _memset((void *)((int)pvVar2 + sVar3),0,uVar4 - sVar3);
    }
  }
  else {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 0xc;
    pvVar2 = (LPVOID)0x0;
  }
  return pvVar2;
}



/* VA 1000b51c */

/* Library Function - Single Match
    int (__stdcall*__cdecl try_get_AreFileApisANSI(void))(void)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_int * __cdecl try_get_AreFileApisANSI(void)

{
  FARPROC pFVar1;

  pFVar1 = FUN_1000b635(0,"AreFileApisANSI",(int *)&DAT_100129dc,(int *)"AreFileApisANSI");
  return (_func_int *)pFVar1;
}



/* VA 1000b536 */

/* Library Function - Multiple Matches With Different Base Names
    int (__stdcall*__cdecl try_get_CompareStringEx(void))(wchar_t const *,unsigned long,wchar_t
   const *,int,wchar_t const *,int,struct _nlsversioninfo *,void *,long)
    int (__stdcall*__cdecl try_get_LCMapStringEx(void))(wchar_t const *,unsigned long,wchar_t const
   *,int,wchar_t *,int,struct _nlsversioninfo *,void *,long)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void FID_conflict_try_get_LCMapStringEx(void)

{
  FUN_1000b635(0x11,"LCMapStringEx",(int *)&DAT_100129f8,(int *)"LCMapStringEx");
  return;
}



/* VA 1000b550 */

/* Library Function - Single Match
    unsigned long (__stdcall*__cdecl try_get_LocaleNameToLCID(void))(wchar_t const *,unsigned long)

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_ulong_wchar_t_ptr_ulong * __cdecl try_get_LocaleNameToLCID(void)

{
  _func_ulong_wchar_t_ptr_ulong *p_Var1;

  p_Var1 = (_func_ulong_wchar_t_ptr_ulong *)
           FUN_1000b635(0x13,"LocaleNameToLCID",(int *)&DAT_10012a10,(int *)"LocaleNameToLCID");
  return p_Var1;
}



/* VA 1000b56a */

HMODULE __cdecl FUN_1000b56a(int *param_1,int *param_2)

{
  int iVar1;
  LPCWSTR lpLibFileName;
  HMODULE pHVar2;
  DWORD DVar3;
  int iVar4;

  do {
    if (param_1 == param_2) {
      return (HMODULE)0x0;
    }
    iVar1 = *param_1;
    pHVar2 = (HMODULE)(&DAT_1001a090)[iVar1];
    if (pHVar2 == (HMODULE)0x0) {
      lpLibFileName = (LPCWSTR)(&PTR_u_api_ms_win_core_datetime_l1_1_1_100124d0)[iVar1];
      pHVar2 = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0x800);
      if ((pHVar2 != (HMODULE)0x0) ||
         ((((DVar3 = GetLastError(), DVar3 == 0x57 &&
            (iVar4 = _wcsncmp(lpLibFileName,L"api-ms-",7), iVar4 != 0)) &&
           (iVar4 = _wcsncmp(lpLibFileName,L"ext-ms-",7), iVar4 != 0)) &&
          (pHVar2 = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0), pHVar2 != (HMODULE)0x0)))) {
        LOCK();
        iVar4 = (&DAT_1001a090)[iVar1];
        (&DAT_1001a090)[iVar1] = pHVar2;
        UNLOCK();
        if (iVar4 == 0) {
          return pHVar2;
        }
        FreeLibrary(pHVar2);
        return pHVar2;
      }
      LOCK();
      (&DAT_1001a090)[iVar1] = 0xffffffff;
      UNLOCK();
    }
    else if (pHVar2 != (HMODULE)0xffffffff) {
      return pHVar2;
    }
    param_1 = param_1 + 1;
  } while( true );
}



/* VA 1000b635 */

FARPROC __cdecl FUN_1000b635(int param_1,LPCSTR param_2,int *param_3,int *param_4)

{
  uint *puVar1;
  HMODULE hModule;
  uint uVar2;
  byte bVar3;
  FARPROC pFVar4;

  puVar1 = &DAT_1001a0e8 + param_1;
  bVar3 = (byte)DAT_10019008 & 0x1f;
  pFVar4 = (FARPROC)((*puVar1 ^ DAT_10019008) >> bVar3 | (*puVar1 ^ DAT_10019008) << 0x20 - bVar3);
  if (pFVar4 == (FARPROC)0xffffffff) {
    pFVar4 = (FARPROC)0x0;
  }
  else if (pFVar4 == (FARPROC)0x0) {
    hModule = FUN_1000b56a(param_3,param_4);
    if ((hModule == (HMODULE)0x0) ||
       (pFVar4 = GetProcAddress(hModule,param_2), pFVar4 == (FARPROC)0x0)) {
      bVar3 = 0x20 - ((byte)DAT_10019008 & 0x1f) & 0x1f;
      LOCK();
      *puVar1 = (0xffffffffU >> bVar3 | -1 << 0x20 - bVar3) ^ DAT_10019008;
      UNLOCK();
      pFVar4 = (FARPROC)0x0;
    }
    else {
      uVar2 = FUN_10008c73((uint)pFVar4);
      LOCK();
      *puVar1 = uVar2;
      UNLOCK();
    }
  }
  return pFVar4;
}



/* VA 1000b6ba */

int FUN_1000b6ba(undefined4 param_1)

{
  FARPROC pFVar1;
  int iVar2;

  pFVar1 = FUN_1000b635(0x19,"AppPolicyGetProcessTerminationMethod",(int *)&DAT_10012a2c,
                        (int *)"AppPolicyGetProcessTerminationMethod");
  if (pFVar1 == (FARPROC)0x0) {
    iVar2 = -0x3ffffddb;
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)(0xfffffffa,param_1);
    iVar2 = (*pFVar1)();
  }
  return iVar2;
}



/* VA 1000b6fa */

/* Library Function - Single Match
    ___acrt_AreFileApisANSI@0

   Library: Visual Studio 2019 Release */

int ___acrt_AreFileApisANSI_0(void)

{
  _func_int *p_Var1;
  int iVar2;

  p_Var1 = try_get_AreFileApisANSI();
  if (p_Var1 != (_func_int *)0x0) {
    (*(code *)PTR_guard_check_icall_1001116c)();
    iVar2 = (*p_Var1)();
    return iVar2;
  }
  return 1;
}



/* VA 1000b719 */

/* Library Function - Single Match
    ___acrt_FlsAlloc@4

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsAlloc_4(undefined4 param_1)

{
  FARPROC pFVar1;

  pFVar1 = FUN_1000b635(0x1f,"FlsAlloc",(int *)&DAT_10012a58,(int *)&DAT_10012a60);
  if (pFVar1 == (FARPROC)0x0) {
    TlsAlloc();
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1);
    (*pFVar1)();
  }
  return;
}



/* VA 1000b758 */

/* Library Function - Single Match
    ___acrt_FlsFree@4

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsFree_4(DWORD param_1)

{
  FARPROC pFVar1;

  pFVar1 = FUN_1000b635(0x20,"FlsFree",(int *)&DAT_10012a60,(int *)&DAT_10012a68);
  if (pFVar1 != (FARPROC)0x0) {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1);
    (*pFVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1000b791. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsFree(param_1);
  return;
}



/* VA 1000b797 */

/* Library Function - Single Match
    ___acrt_FlsGetValue@4

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsGetValue_4(DWORD param_1)

{
  FARPROC pFVar1;

  pFVar1 = FUN_1000b635(0x21,"FlsGetValue",(int *)&DAT_10012a68,(int *)&DAT_10012a70);
  if (pFVar1 != (FARPROC)0x0) {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1);
    (*pFVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1000b7d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsGetValue(param_1);
  return;
}



/* VA 1000b7d6 */

/* Library Function - Single Match
    ___acrt_FlsSetValue@8

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsSetValue_8(DWORD param_1,LPVOID param_2)

{
  FARPROC pFVar1;

  pFVar1 = FUN_1000b635(0x22,"FlsSetValue",(int *)&DAT_10012a70,(int *)&DAT_10012a78);
  if (pFVar1 != (FARPROC)0x0) {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1,param_2);
    (*pFVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1000b812. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsSetValue(param_1,param_2);
  return;
}



/* VA 1000b818 */

/* Library Function - Single Match
    ___acrt_InitializeCriticalSectionEx@12

   Library: Visual Studio 2019 Release */

void ___acrt_InitializeCriticalSectionEx_12
               (LPCRITICAL_SECTION param_1,DWORD param_2,undefined4 param_3)

{
  FARPROC pFVar1;

  pFVar1 = FUN_1000b635(0xf,"InitializeCriticalSectionEx",(int *)&DAT_100129f0,(int *)&DAT_100129f8)
  ;
  if (pFVar1 == (FARPROC)0x0) {
    InitializeCriticalSectionAndSpinCount(param_1,param_2);
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1,param_2,param_3);
    (*pFVar1)();
  }
  return;
}



/* VA 1000b863 */

/* Library Function - Multiple Matches With Different Base Names
    ___acrt_CompareStringEx@36
    ___acrt_LCMapStringEx@36

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void FID_conflict____acrt_CompareStringEx_36
               (wchar_t *param_1,DWORD param_2,LPCWSTR param_3,int param_4,LPWSTR param_5,
               int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  code *pcVar1;
  LCID Locale;

  pcVar1 = (code *)FID_conflict_try_get_LCMapStringEx();
  if (pcVar1 == (code *)0x0) {
    Locale = ___acrt_LocaleNameToLCID_8(param_1,0);
    LCMapStringW(Locale,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)
              (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    (*pcVar1)();
  }
  return;
}



/* VA 1000b8c0 */

/* Library Function - Single Match
    ___acrt_LocaleNameToLCID@8

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_LocaleNameToLCID_8(wchar_t *param_1,ulong param_2)

{
  _func_ulong_wchar_t_ptr_ulong *p_Var1;

  p_Var1 = try_get_LocaleNameToLCID();
  if (p_Var1 == (_func_ulong_wchar_t_ptr_ulong *)0x0) {
    ___acrt_DownlevelLocaleNameToLCID((ushort *)param_1);
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)();
    (*p_Var1)(param_1,param_2);
  }
  return;
}



/* VA 1000b905 */

/* Library Function - Single Match
    ___acrt_uninitialize_winapi_thunks

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined1 __cdecl ___acrt_uninitialize_winapi_thunks(char param_1)

{
  int *piVar1;

  if (param_1 == '\0') {
    piVar1 = &DAT_1001a090;
    do {
      if (*piVar1 != 0) {
        if (*piVar1 != -1) {
          FreeLibrary((HMODULE)*piVar1);
        }
        *piVar1 = 0;
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 != &DAT_1001a0e8);
  }
  return 1;
}



/* VA 1000b956 */

/* Library Function - Single Match
    void __cdecl initialize_inherited_file_handles_nolock(void)

   Library: Visual Studio 2019 Release */

void __cdecl initialize_inherited_file_handles_nolock(void)

{
  byte bVar1;
  HANDLE hFile;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  _STARTUPINFOW local_4c;
  undefined4 *local_8;

  GetStartupInfoW(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((uint *)local_4c.lpReserved2 != (uint *)0x0)) {
    uVar4 = *(uint *)local_4c.lpReserved2;
    local_8 = (undefined4 *)((int)local_4c.lpReserved2 + uVar4 + 4);
    if (0x1fff < (int)uVar4) {
      uVar4 = 0x2000;
    }
    ___acrt_lowio_ensure_fh_exists(uVar4);
    if ((int)DAT_1001a378 < (int)uVar4) {
      uVar4 = DAT_1001a378;
    }
    uVar5 = 0;
    if (uVar4 != 0) {
      do {
        hFile = (HANDLE)*local_8;
        if ((((hFile != (HANDLE)0xffffffff) && (hFile != (HANDLE)0xfffffffe)) &&
            (bVar1 = *(byte *)(uVar5 + 4 + (int)local_4c.lpReserved2), (bVar1 & 1) != 0)) &&
           (((bVar1 & 8) != 0 || (DVar2 = GetFileType(hFile), DVar2 != 0)))) {
          iVar3 = (uVar5 & 0x3f) * 0x38 + (&DAT_1001a178)[(int)uVar5 >> 6];
          *(undefined4 *)(iVar3 + 0x18) = *local_8;
          *(undefined1 *)(iVar3 + 0x28) = *(undefined1 *)(uVar5 + 4 + (int)local_4c.lpReserved2);
        }
        uVar5 = uVar5 + 1;
        local_8 = local_8 + 1;
      } while (uVar5 != uVar4);
    }
  }
  return;
}



/* VA 1000ba0c */

void FUN_1000ba0c(void)

{
  HANDLE hFile;
  int iVar1;
  uint uVar2;
  DWORD DVar3;

  uVar2 = 0;
  do {
    iVar1 = (uVar2 & 0x3f) * 0x38 + (&DAT_1001a178)[(int)uVar2 >> 6];
    if ((*(int *)(iVar1 + 0x18) == -1) || (*(int *)(iVar1 + 0x18) == -2)) {
      *(undefined1 *)(iVar1 + 0x28) = 0x81;
      if (uVar2 == 0) {
        DVar3 = 0xfffffff6;
      }
      else if (uVar2 == 1) {
        DVar3 = 0xfffffff5;
      }
      else {
        DVar3 = 0xfffffff4;
      }
      hFile = GetStdHandle(DVar3);
      if ((hFile != (HANDLE)0xffffffff) && (hFile != (HANDLE)0x0)) {
        DVar3 = GetFileType(hFile);
        if (DVar3 != 0) {
          *(HANDLE *)(iVar1 + 0x18) = hFile;
          if ((DVar3 & 0xff) == 2) {
            *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) | 0x40;
          }
          else if ((DVar3 & 0xff) == 3) {
            *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) | 8;
          }
          goto LAB_1000baae;
        }
      }
      *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) | 0x40;
      *(undefined4 *)(iVar1 + 0x18) = 0xfffffffe;
      if (DAT_1001a384 != 0) {
        *(undefined4 *)(*(int *)(DAT_1001a384 + uVar2 * 4) + 0x10) = 0xfffffffe;
      }
    }
    else {
      *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) | 0x80;
    }
LAB_1000baae:
    uVar2 = uVar2 + 1;
    if (uVar2 == 3) {
      return;
    }
  } while( true );
}



/* VA 1000bb13 */

void FUN_1000bb13(void)

{
  ___acrt_unlock(7);
  return;
}



/* VA 1000bb48 */

/* Library Function - Single Match
    ___acrt_execute_initializers

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __cdecl ___acrt_execute_initializers(undefined4 *param_1,undefined4 *param_2)

{
  code *pcVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;

  puVar2 = param_1;
  if (param_1 != param_2) {
    do {
      pcVar1 = (code *)*puVar2;
      if (pcVar1 != (code *)0x0) {
        (*(code *)PTR_guard_check_icall_1001116c)();
        in_EAX = (undefined4 *)(*pcVar1)();
        if ((char)in_EAX == '\0') break;
      }
      puVar2 = puVar2 + 2;
    } while (puVar2 != param_2);
    if (puVar2 != param_2) {
      if (puVar2 != param_1) {
        puVar2 = puVar2 + -1;
        do {
          if ((puVar2[-1] != 0) && (pcVar1 = (code *)*puVar2, pcVar1 != (code *)0x0)) {
            (*(code *)PTR_guard_check_icall_1001116c)(0);
            (*pcVar1)();
          }
          in_EAX = puVar2 + -1;
          puVar2 = puVar2 + -2;
        } while (in_EAX != param_1);
      }
      return (uint)in_EAX & 0xffffff00;
    }
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



/* VA 1000bbb0 */

/* Library Function - Single Match
    ___acrt_execute_uninitializers

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined1 __cdecl ___acrt_execute_uninitializers(int param_1,int param_2)

{
  code *pcVar1;

  for (; param_1 != param_2; param_2 = param_2 + -8) {
    pcVar1 = *(code **)(param_2 + -4);
    if (pcVar1 != (code *)0x0) {
      (*(code *)PTR_guard_check_icall_1001116c)(0);
      (*pcVar1)();
    }
  }
  return 1;
}



/* VA 1000bbe1 */

bool FUN_1000bbe1(void)

{
  byte bVar1;

  bVar1 = (byte)DAT_10019008 & 0x1f;
  return (DAT_1001a37c ^ DAT_10019008) >> bVar1 != 0 ||
         (DAT_1001a37c ^ DAT_10019008) << 0x20 - bVar1 != 0;
}



/* VA 1000bbfe */

void __cdecl FUN_1000bbfe(undefined4 param_1)

{
  DAT_1001a37c = param_1;
  return;
}



/* VA 1000bc0d */

undefined4 __cdecl FUN_1000bc0d(undefined4 param_1)

{
  undefined4 uVar1;
  byte bVar2;
  code *pcVar3;

  bVar2 = (byte)DAT_10019008 & 0x1f;
  pcVar3 = (code *)((DAT_1001a37c ^ DAT_10019008) >> bVar2 |
                   (DAT_1001a37c ^ DAT_10019008) << 0x20 - bVar2);
  if (pcVar3 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    (*(code *)PTR_guard_check_icall_1001116c)(param_1);
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}



/* VA 1000bc43 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_2866be3712abc81a800a822484c830d8>,class <lambda_39ca0ed439415581b5b15c265174cece> &,class
   <lambda_2b24c74d71094a6cd0cb82e44167d71b> >(class <lambda_2866be3712abc81a800a822484c830d8>
   &&,class <lambda_39ca0ed439415581b5b15c265174cece> &,class
   <lambda_2b24c74d71094a6cd0cb82e44167d71b> &&)

   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<<lambda_2866be3712abc81a800a822484c830d8>,<lambda_39ca0ed439415581b5b15c265174cece>&,<lambda_2b24c74d71094a6cd0cb82e44167d71b>_>
          (__crt_seh_guarded_call<void> *this,<lambda_2866be3712abc81a800a822484c830d8> *param_1,
          <lambda_39ca0ed439415581b5b15c265174cece> *param_2,
          <lambda_2b24c74d71094a6cd0cb82e44167d71b> *param_3)

{
  undefined4 uVar1;
  int iVar2;
  void *local_14;

  __lock_file(*(FILE **)param_1);
  uVar1 = FUN_1000bdc8(**(int **)param_2,*(int **)(param_2 + 4));
  if (((char)uVar1 != '\0') &&
     ((**(char **)(param_2 + 8) != '\0' || ((*(uint *)(**(int **)param_2 + 0xc) >> 1 & 1) != 0)))) {
    iVar2 = FUN_1000be85((FILE *)**(undefined4 **)param_2);
    if (iVar2 == -1) {
      **(undefined4 **)(param_2 + 0xc) = 0xffffffff;
    }
    else {
      **(int **)(param_2 + 4) = **(int **)(param_2 + 4) + 1;
    }
  }
  FUN_1000bcc3();
  ExceptionList = local_14;
  return;
}



/* VA 1000bcc3 */

void FUN_1000bcc3(void)

{
  int unaff_EBP;

  __unlock_file((FILE *)**(undefined4 **)(unaff_EBP + 0x10));
  return;
}



/* VA 1000bccf */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_2cc53f568c5a2bb6f192f930a45d44ea>,class <lambda_ab61a845afdef5b7c387490eaf3616ee> &,class
   <lambda_c2ffc0b7726aa6be21d5f0026187e748> >(class <lambda_2cc53f568c5a2bb6f192f930a45d44ea>
   &&,class <lambda_ab61a845afdef5b7c387490eaf3616ee> &,class
   <lambda_c2ffc0b7726aa6be21d5f0026187e748> &&)

   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<<lambda_2cc53f568c5a2bb6f192f930a45d44ea>,<lambda_ab61a845afdef5b7c387490eaf3616ee>&,<lambda_c2ffc0b7726aa6be21d5f0026187e748>_>
          (__crt_seh_guarded_call<void> *this,<lambda_2cc53f568c5a2bb6f192f930a45d44ea> *param_1,
          <lambda_ab61a845afdef5b7c387490eaf3616ee> *param_2,
          <lambda_c2ffc0b7726aa6be21d5f0026187e748> *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int *local_30;
  int local_2c;
  int local_28;
  int local_24;
  __crt_seh_guarded_call<void> local_1d [9];
  void *local_14;
  undefined4 uStack_c;
  undefined *local_8;

  local_8 = &DAT_10017850;
  uStack_c = 0x1000bcdb;
  ___acrt_lock(*(int *)param_1);
  local_8 = (undefined *)0x0;
  piVar1 = DAT_1001a384 + DAT_1001a380;
  for (piVar3 = DAT_1001a384; local_30 = piVar3, piVar3 != piVar1; piVar3 = piVar3 + 1) {
    local_24 = *piVar3;
    uVar2 = FUN_1000bdc8(local_24,*(int **)param_2);
    if ((char)uVar2 != '\0') {
      local_34 = *(undefined4 *)(param_2 + 8);
      local_38 = *(undefined4 *)(param_2 + 4);
      local_3c = *(undefined4 *)param_2;
      local_40 = &local_24;
      local_28 = local_24;
      local_2c = local_24;
      operator()<<lambda_2866be3712abc81a800a822484c830d8>,<lambda_39ca0ed439415581b5b15c265174cece>&,<lambda_2b24c74d71094a6cd0cb82e44167d71b>_>
                (local_1d,(<lambda_2866be3712abc81a800a822484c830d8> *)&local_2c,
                 (<lambda_39ca0ed439415581b5b15c265174cece> *)&local_40,
                 (<lambda_2b24c74d71094a6cd0cb82e44167d71b> *)&local_28);
    }
  }
  local_8 = (undefined *)0xfffffffe;
  FUN_1000bd6f();
  ExceptionList = local_14;
  return;
}



/* VA 1000bd6f */

void FUN_1000bd6f(void)

{
  int unaff_EBP;

  ___acrt_unlock(**(int **)(unaff_EBP + 0x10));
  return;
}



/* VA 1000bd7b */

/* Library Function - Single Match
    int __cdecl common_flush_all(bool)

   Library: Visual Studio 2019 Release */

int __cdecl common_flush_all(bool param_1)

{
  int *local_24;
  bool *local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  __crt_seh_guarded_call<void> local_5;

  local_c = 0;
  local_24 = &local_c;
  local_10 = 0;
  local_20 = &param_1;
  local_1c = &local_10;
  local_14 = 8;
  local_18 = 8;
  __crt_seh_guarded_call<void>::
  operator()<<lambda_2cc53f568c5a2bb6f192f930a45d44ea>,<lambda_ab61a845afdef5b7c387490eaf3616ee>&,<lambda_c2ffc0b7726aa6be21d5f0026187e748>_>
            (&local_5,(<lambda_2cc53f568c5a2bb6f192f930a45d44ea> *)&local_18,
             (<lambda_ab61a845afdef5b7c387490eaf3616ee> *)&local_24,
             (<lambda_c2ffc0b7726aa6be21d5f0026187e748> *)&local_14);
  if (param_1 == false) {
    local_c = local_10;
  }
  return local_c;
}



/* VA 1000bdc8 */

uint __cdecl FUN_1000bdc8(int param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;

  piVar1 = (int *)0x0;
  if (param_1 != 0) {
    piVar1 = (int *)(*(uint *)(param_1 + 0xc) >> 0xd);
    if (((uint)piVar1 & 1) != 0) {
      uVar2 = FUN_1000bdf9(*(uint *)(param_1 + 0xc));
      if ((char)uVar2 != '\0') {
        return CONCAT31((int3)(uVar2 >> 8),1);
      }
      *param_2 = *param_2 + 1;
      piVar1 = param_2;
    }
  }
  return (uint)piVar1 & 0xffffff00;
}



/* VA 1000bdf9 */

uint __cdecl FUN_1000bdf9(uint param_1)

{
  undefined3 uVar1;

  uVar1 = (undefined3)((param_1 & 0xffffff03) >> 8);
  if (((char)(param_1 & 0xffffff03) == '\x02') && ((param_1 & 0xc0) != 0)) {
    return CONCAT31(uVar1,1);
  }
  return CONCAT31(uVar1,(char)(param_1 >> 0xb)) & 0xffffff01;
}



/* VA 1000be1c */

undefined4 __cdecl FUN_1000be1c(FILE *param_1,int *param_2)

{
  int *piVar1;
  uint *puVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;

  piVar1 = &param_1->_flag;
  if ((((byte)*piVar1 & 3) == 2) && ((*piVar1 & 0xc0U) != 0)) {
    puVar2 = (uint *)param_1->_cnt;
    uVar5 = (int)param_1->_ptr - (int)puVar2;
    param_1->_ptr = (char *)puVar2;
    param_1->_base = (char *)0x0;
    if (0 < (int)uVar5) {
      pcVar3 = (char *)__fileno(param_1);
      uVar4 = FUN_1000de03(pcVar3,puVar2,uVar5,param_2);
      if (uVar5 != uVar4) {
        LOCK();
        *piVar1 = *piVar1 | 0x10;
        UNLOCK();
        return 0xffffffff;
      }
      if (((uint)*piVar1 >> 2 & 1) != 0) {
        LOCK();
        *piVar1 = *piVar1 & 0xfffffffd;
        UNLOCK();
      }
    }
  }
  return 0;
}



/* VA 1000be85 */

int __cdecl FUN_1000be85(FILE *param_1)

{
  int iVar1;
  int iVar2;
  int local_2c [10];

  iVar2 = 0;
  FUN_10007d98(local_2c,(undefined4 *)0x0);
  if (param_1 == (FILE *)0x0) {
    iVar2 = common_flush_all(false);
    goto LAB_1000bedc;
  }
  iVar1 = FUN_1000be1c(param_1,local_2c);
  if (iVar1 == 0) {
    if (((uint)param_1->_flag >> 0xb & 1) == 0) goto LAB_1000bedc;
    iVar1 = __fileno(param_1);
    iVar1 = __commit(iVar1);
    if (iVar1 == 0) goto LAB_1000bedc;
  }
  iVar2 = -1;
LAB_1000bedc:
  FUN_10007de0(local_2c);
  return iVar2;
}



/* VA 1000beea */

/* Library Function - Single Match
    __flushall

   Library: Visual Studio 2019 Release */

int __cdecl __flushall(void)

{
  int iVar1;

  iVar1 = common_flush_all(true);
  return iVar1;
}



/* VA 1000c008 */

/* Library Function - Single Match
    __lock_file

   Library: Visual Studio 2019 Release */

void __cdecl __lock_file(FILE *_File)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}



/* VA 1000c01c */

/* Library Function - Single Match
    __unlock_file

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __unlock_file(FILE *_File)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}



/* VA 1000c030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_1000c030(LPWSTR param_1,byte *param_2,uint param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;

  if ((param_2 == (byte *)0x0) || (param_3 == 0)) {
    _DAT_1001a390 = 0;
    _DAT_1001a394 = 0;
  }
  else {
    if (*param_2 != 0) {
      if ((char)param_4[5] == '\0') {
        FUN_100091a0(param_4);
      }
      piVar1 = (int *)param_4[3];
      uVar2 = piVar1[2];
      if (uVar2 == 0xfde9) {
        uVar2 = FUN_1000e2aa(param_1,param_2,param_3,(uint *)&DAT_1001a390,(int)param_4);
        if (-1 < (int)uVar2) {
          return uVar2;
        }
      }
      else {
        if (piVar1[0x2a] == 0) {
          if (param_1 != (LPWSTR)0x0) {
            *param_1 = (ushort)*param_2;
          }
          return 1;
        }
        if (*(short *)(*piVar1 + (uint)*param_2 * 2) < 0) {
          iVar3 = *(int *)(param_4[3] + 4);
          if ((((1 < iVar3) && (iVar3 <= (int)param_3)) &&
              (iVar3 = FUN_1000b2b2(uVar2,9,(LPCSTR)param_2,iVar3,param_1,
                                    (uint)(param_1 != (LPWSTR)0x0)), iVar3 != 0)) ||
             ((*(uint *)(param_4[3] + 4) <= param_3 && (param_2[1] != 0)))) {
            return *(uint *)(param_4[3] + 4);
          }
        }
        else {
          iVar3 = FUN_1000b2b2(uVar2,9,(LPCSTR)param_2,1,param_1,(uint)(param_1 != (LPWSTR)0x0));
          if (iVar3 != 0) {
            return 1;
          }
        }
        *(undefined1 *)(param_4 + 7) = 1;
        param_4[6] = 0x2a;
      }
      return 0xffffffff;
    }
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
  }
  return 0;
}



/* VA 1000c163 */

/* Library Function - Single Match
    __fileno

   Library: Visual Studio */

int __cdecl __fileno(FILE *_File)

{
  __acrt_ptd *p_Var1;

  if (_File == (FILE *)0x0) {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 0x16;
    FUN_100080a4();
    return -1;
  }
  return _File->_file;
}



/* VA 1000c18a */

/* Library Function - Single Match
    ___acrt_add_locale_ref

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___acrt_add_locale_ref(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;

  LOCK();
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  UNLOCK();
  piVar1 = *(int **)(param_1 + 0x7c);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  piVar1 = *(int **)(param_1 + 0x84);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  piVar1 = *(int **)(param_1 + 0x80);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  puVar2 = (undefined4 *)(param_1 + 0x28);
  iVar3 = 6;
  do {
    if (((undefined *)puVar2[-2] != &DAT_10019110) &&
       (piVar1 = (int *)*puVar2, piVar1 != (int *)0x0)) {
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    if ((puVar2[-3] != 0) && (piVar1 = (int *)puVar2[-1], piVar1 != (int *)0x0)) {
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    puVar2 = puVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  ___acrt_locale_add_lc_time_reference(*(undefined ***)(param_1 + 0x9c));
  return;
}



/* VA 1000c207 */

/* Library Function - Single Match
    ___acrt_free_locale

   Library: Visual Studio 2019 Release */

void __cdecl ___acrt_free_locale(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_8;

  if ((((*(undefined ***)(param_1 + 0x88) != (undefined **)0x0) &&
       (*(undefined ***)(param_1 + 0x88) != &PTR_DAT_100196e8)) &&
      (*(int **)(param_1 + 0x7c) != (int *)0x0)) && (**(int **)(param_1 + 0x7c) == 0)) {
    piVar1 = *(int **)(param_1 + 0x84);
    if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
      FUN_10009f36(piVar1);
      ___acrt_locale_free_monetary(*(int *)(param_1 + 0x88));
    }
    piVar1 = *(int **)(param_1 + 0x80);
    if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
      FUN_10009f36(piVar1);
      ___acrt_locale_free_numeric(*(int **)(param_1 + 0x88));
    }
    FUN_10009f36(*(LPVOID *)(param_1 + 0x7c));
    FUN_10009f36(*(LPVOID *)(param_1 + 0x88));
  }
  if ((*(int **)(param_1 + 0x8c) != (int *)0x0) && (**(int **)(param_1 + 0x8c) == 0)) {
    FUN_10009f36((LPVOID)(*(int *)(param_1 + 0x90) + -0xfe));
    FUN_10009f36((LPVOID)(*(int *)(param_1 + 0x94) + -0x80));
    FUN_10009f36((LPVOID)(*(int *)(param_1 + 0x98) + -0x80));
    FUN_10009f36(*(LPVOID *)(param_1 + 0x8c));
  }
  ___acrt_locale_free_lc_time_if_unreferenced(*(undefined ***)(param_1 + 0x9c));
  puVar2 = (undefined4 *)(param_1 + 0xa0);
  local_8 = 6;
  puVar3 = (undefined4 *)(param_1 + 0x28);
  do {
    if ((((undefined *)puVar3[-2] != &DAT_10019110) &&
        (piVar1 = (int *)*puVar3, piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
      FUN_10009f36(piVar1);
      FUN_10009f36((LPVOID)*puVar2);
    }
    if (((puVar3[-3] != 0) && (piVar1 = (int *)puVar3[-1], piVar1 != (int *)0x0)) && (*piVar1 == 0))
    {
      FUN_10009f36(piVar1);
    }
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 4;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  FUN_10009f36((LPVOID)param_1);
  return;
}



/* VA 1000c34f */

/* Library Function - Single Match
    ___acrt_locale_add_lc_time_reference

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined * __cdecl ___acrt_locale_add_lc_time_reference(undefined **param_1)

{
  undefined **ppuVar1;
  undefined *puVar2;

  if ((param_1 != (undefined **)0x0) && (param_1 != &PTR_DAT_10011fd0)) {
    LOCK();
    ppuVar1 = param_1 + 0x2c;
    puVar2 = *ppuVar1;
    *ppuVar1 = *ppuVar1 + 1;
    UNLOCK();
    return puVar2 + 1;
  }
  return (undefined *)0x7fffffff;
}



/* VA 1000c378 */

/* Library Function - Single Match
    ___acrt_locale_free_lc_time_if_unreferenced

   Library: Visual Studio 2019 Release */

void __cdecl ___acrt_locale_free_lc_time_if_unreferenced(undefined **param_1)

{
  if (((param_1 != (undefined **)0x0) && (param_1 != &PTR_DAT_10011fd0)) &&
     (param_1[0x2c] == (undefined *)0x0)) {
    ___acrt_locale_free_time(param_1);
    FUN_10009f36(param_1);
  }
  return;
}



/* VA 1000c3a9 */

/* Library Function - Single Match
    ___acrt_locale_release_lc_time_reference

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined * __cdecl ___acrt_locale_release_lc_time_reference(undefined **param_1)

{
  undefined **ppuVar1;
  undefined *puVar2;

  if ((param_1 != (undefined **)0x0) && (param_1 != &PTR_DAT_10011fd0)) {
    LOCK();
    ppuVar1 = param_1 + 0x2c;
    puVar2 = *ppuVar1;
    *ppuVar1 = *ppuVar1 + -1;
    UNLOCK();
    return puVar2 + -1;
  }
  return (undefined *)0x7fffffff;
}



/* VA 1000c3d2 */

/* Library Function - Single Match
    ___acrt_release_locale_ref

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___acrt_release_locale_ref(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;

  if (param_1 != 0) {
    LOCK();
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
    UNLOCK();
    piVar1 = *(int **)(param_1 + 0x7c);
    if (piVar1 != (int *)0x0) {
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    piVar1 = *(int **)(param_1 + 0x84);
    if (piVar1 != (int *)0x0) {
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    piVar1 = *(int **)(param_1 + 0x80);
    if (piVar1 != (int *)0x0) {
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    piVar1 = *(int **)(param_1 + 0x8c);
    if (piVar1 != (int *)0x0) {
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    puVar2 = (undefined4 *)(param_1 + 0x28);
    iVar3 = 6;
    do {
      if (((undefined *)puVar2[-2] != &DAT_10019110) &&
         (piVar1 = (int *)*puVar2, piVar1 != (int *)0x0)) {
        LOCK();
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if ((puVar2[-3] != 0) && (piVar1 = (int *)puVar2[-1], piVar1 != (int *)0x0)) {
        LOCK();
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      puVar2 = puVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    ___acrt_locale_release_lc_time_reference(*(undefined ***)(param_1 + 0x9c));
  }
  return;
}



/* VA 1000c453 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

int FUN_1000c453(void)

{
  __acrt_ptd *p_Var1;
  undefined **ppuVar2;
  int iVar3;
  void *pvStack_14;

  p_Var1 = FUN_10009958();
  if (((*(uint *)(p_Var1 + 0x350) & DAT_100196e0) != 0) &&
     (iVar3 = *(int *)(p_Var1 + 0x4c), iVar3 != 0)) {
    ExceptionList = pvStack_14;
    return iVar3;
  }
  ___acrt_lock(4);
  ppuVar2 = __updatetlocinfoEx_nolock((int *)(p_Var1 + 0x4c),DAT_10019f0c);
  FUN_1000c4b3();
  if (ppuVar2 != (undefined **)0x0) {
    iVar3 = FUN_1000c4bc();
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 1000c4b3 */

void FUN_1000c4b3(void)

{
  ___acrt_unlock(4);
  return;
}



/* VA 1000c4bc */

void FUN_1000c4bc(void)

{
  int unaff_EBP;

  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}



/* VA 1000c4d4 */

/* Library Function - Single Match
    __updatetlocinfoEx_nolock

   Library: Visual Studio 2019 Release */

undefined ** __cdecl __updatetlocinfoEx_nolock(int *param_1,undefined **param_2)

{
  undefined **ppuVar1;

  if ((param_2 == (undefined **)0x0) || (param_1 == (int *)0x0)) {
    param_2 = (undefined **)0x0;
  }
  else {
    ppuVar1 = (undefined **)*param_1;
    if (ppuVar1 != param_2) {
      *param_1 = (int)param_2;
      ___acrt_add_locale_ref((int)param_2);
      if (((ppuVar1 != (undefined **)0x0) &&
          (___acrt_release_locale_ref((int)ppuVar1), ppuVar1[3] == (undefined *)0x0)) &&
         (ppuVar1 != &PTR_DAT_10019050)) {
        ___acrt_free_locale((int)ppuVar1);
      }
    }
  }
  return param_2;
}



/* VA 1000c524 */

/* Library Function - Single Match
    ___acrt_locale_free_monetary

   Library: Visual Studio 2019 Release */

void __cdecl ___acrt_locale_free_monetary(int param_1)

{
  if (param_1 != 0) {
    if (*(undefined **)(param_1 + 0xc) != PTR_DAT_100196f4) {
      FUN_10009f36(*(undefined **)(param_1 + 0xc));
    }
    if (*(undefined **)(param_1 + 0x10) != PTR_DAT_100196f8) {
      FUN_10009f36(*(undefined **)(param_1 + 0x10));
    }
    if (*(undefined **)(param_1 + 0x14) != PTR_DAT_100196fc) {
      FUN_10009f36(*(undefined **)(param_1 + 0x14));
    }
    if (*(undefined **)(param_1 + 0x18) != PTR_DAT_10019700) {
      FUN_10009f36(*(undefined **)(param_1 + 0x18));
    }
    if (*(undefined **)(param_1 + 0x1c) != PTR_DAT_10019704) {
      FUN_10009f36(*(undefined **)(param_1 + 0x1c));
    }
    if (*(undefined **)(param_1 + 0x20) != PTR_DAT_10019708) {
      FUN_10009f36(*(undefined **)(param_1 + 0x20));
    }
    if (*(undefined **)(param_1 + 0x24) != PTR_DAT_1001970c) {
      FUN_10009f36(*(undefined **)(param_1 + 0x24));
    }
    if (*(undefined **)(param_1 + 0x38) != PTR_DAT_10019720) {
      FUN_10009f36(*(undefined **)(param_1 + 0x38));
    }
    if (*(undefined **)(param_1 + 0x3c) != PTR_DAT_10019724) {
      FUN_10009f36(*(undefined **)(param_1 + 0x3c));
    }
    if (*(undefined **)(param_1 + 0x40) != PTR_DAT_10019728) {
      FUN_10009f36(*(undefined **)(param_1 + 0x40));
    }
    if (*(undefined **)(param_1 + 0x44) != PTR_DAT_1001972c) {
      FUN_10009f36(*(undefined **)(param_1 + 0x44));
    }
    if (*(undefined **)(param_1 + 0x48) != PTR_DAT_10019730) {
      FUN_10009f36(*(undefined **)(param_1 + 0x48));
    }
    if (*(undefined **)(param_1 + 0x4c) != PTR_DAT_10019734) {
      FUN_10009f36(*(undefined **)(param_1 + 0x4c));
    }
  }
  return;
}



/* VA 1000c622 */

/* Library Function - Single Match
    ___acrt_locale_free_numeric

   Library: Visual Studio 2019 Release */

void __cdecl ___acrt_locale_free_numeric(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if ((undefined *)*param_1 != PTR_DAT_100196e8) {
      FUN_10009f36((undefined *)*param_1);
    }
    if ((undefined *)param_1[1] != PTR_DAT_100196ec) {
      FUN_10009f36((undefined *)param_1[1]);
    }
    if ((undefined *)param_1[2] != PTR_DAT_100196f0) {
      FUN_10009f36((undefined *)param_1[2]);
    }
    if ((undefined *)param_1[0xc] != PTR_DAT_10019718) {
      FUN_10009f36((undefined *)param_1[0xc]);
    }
    if ((undefined *)param_1[0xd] != PTR_DAT_1001971c) {
      FUN_10009f36((undefined *)param_1[0xd]);
    }
  }
  return;
}



/* VA 1000c68b */

void __cdecl FUN_1000c68b(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;

  puVar1 = param_1 + param_2;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    FUN_10009f36((LPVOID)*param_1);
  }
  return;
}



/* VA 1000c6b0 */

/* Library Function - Single Match
    ___acrt_locale_free_time

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___acrt_locale_free_time(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_1000c68b(param_1,7);
    FUN_1000c68b(param_1 + 7,7);
    FUN_1000c68b(param_1 + 0xe,0xc);
    FUN_1000c68b(param_1 + 0x1a,0xc);
    FUN_1000c68b(param_1 + 0x26,2);
    FUN_10009f36((LPVOID)param_1[0x28]);
    FUN_10009f36((LPVOID)param_1[0x29]);
    FUN_10009f36((LPVOID)param_1[0x2a]);
    FUN_1000c68b(param_1 + 0x2d,7);
    FUN_1000c68b(param_1 + 0x34,7);
    FUN_1000c68b(param_1 + 0x3b,0xc);
    FUN_1000c68b(param_1 + 0x47,0xc);
    FUN_1000c68b(param_1 + 0x53,2);
    FUN_10009f36((LPVOID)param_1[0x55]);
    FUN_10009f36((LPVOID)param_1[0x56]);
    FUN_10009f36((LPVOID)param_1[0x57]);
    FUN_10009f36((LPVOID)param_1[0x58]);
  }
  return;
}



/* VA 1000c794 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BOOL __cdecl
FUN_1000c794(int *param_1,DWORD param_2,LPCSTR param_3,int param_4,LPWORD param_5,uint param_6,
            int param_7)

{
  uint uVar1;
  undefined4 *puVar2;
  int cchSrc;
  LPCWSTR lpSrcStr;
  BOOL BVar3;
  int local_20;
  int local_1c;
  char local_14;
  int local_10;
  uint local_c;
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  FUN_10007c04(&local_20,param_1);
  if (param_6 == 0) {
    param_6 = *(uint *)(local_1c + 8);
  }
  BVar3 = 0;
  local_10 = FUN_1000b2b2(param_6,(uint)(param_7 != 0) * 8 + 1,param_3,param_4,(LPWSTR)0x0,0);
  if (local_10 == 0) goto LAB_1000c871;
  local_c = local_10 * 2;
  uVar1 = -(uint)(local_c < local_c + 8) & local_c + 8;
  if (uVar1 == 0) {
    lpSrcStr = (LPCWSTR)0x0;
  }
  else if (uVar1 < 0x401) {
    puVar2 = (undefined4 *)&stack0xffffffd4;
    lpSrcStr = (LPCWSTR)&stack0xffffffd4;
    if (&stack0x00000000 != (undefined1 *)0x2c) {
LAB_1000c82c:
      lpSrcStr = (LPCWSTR)(puVar2 + 2);
      if (lpSrcStr != (LPCWSTR)0x0) {
        _memset(lpSrcStr,0,local_c);
        cchSrc = FUN_1000b2b2(param_6,1,param_3,param_4,lpSrcStr,local_10);
        if (cchSrc != 0) {
          BVar3 = GetStringTypeW(param_2,lpSrcStr,cchSrc,param_5);
        }
      }
    }
  }
  else {
    puVar2 = __malloc_base(uVar1);
    lpSrcStr = (LPCWSTR)0x0;
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0xdddd;
      goto LAB_1000c82c;
    }
  }
  FUN_1000c895((int)lpSrcStr);
LAB_1000c871:
  if (local_14 != '\0') {
    *(uint *)(local_20 + 0x350) = *(uint *)(local_20 + 0x350) & 0xfffffffd;
  }
  return BVar3;
}



/* VA 1000c895 */

void __cdecl FUN_1000c895(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + -8) == 0xdddd)) {
    FUN_10009f36((int *)(param_1 + -8));
  }
  return;
}



/* VA 1000c8b5 */

undefined4 FUN_1000c8b5(void)

{
  return DAT_1001a3a0;
}



/* VA 1000c8c0 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    _qsort

   Library: Visual Studio 2019 Release */

void __cdecl
_qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,_PtFuncCompare *_PtFuncCompare)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  __acrt_ptd *p_Var3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  size_t sVar10;
  undefined1 *puVar11;
  void *in_stack_fffffec8;
  void *pvVar12;
  undefined1 *local_11c;
  undefined1 *local_110;
  undefined1 *local_108;
  undefined1 *local_100;
  undefined4 auStack_f8 [30];
  undefined4 auStack_80 [30];
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  local_108 = _Base;
  if ((((_Base == (void *)0x0) && (_NumOfElements != 0)) || (_SizeOfElements == 0)) ||
     (_PtFuncCompare == (_PtFuncCompare *)0x0)) {
    p_Var3 = FUN_100095db();
    *(undefined4 *)p_Var3 = 0x16;
    FUN_100080a4();
  }
  else {
    local_11c = (undefined1 *)0x0;
    if (1 < _NumOfElements) {
      puVar7 = (undefined1 *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
LAB_1000c942:
      while (uVar4 = (uint)((int)puVar7 - (int)local_108) / _SizeOfElements + 1, 8 < uVar4) {
        iVar5 = (uVar4 >> 1) * _SizeOfElements;
        puVar8 = local_108 + iVar5;
        puVar11 = local_108;
        puVar9 = puVar8;
        (*(code *)PTR_guard_check_icall_1001116c)();
        pvVar12 = (void *)0x1000ca2a;
        iVar6 = (*_PtFuncCompare)(puVar11,puVar9);
        if ((0 < iVar6) && (sVar10 = _SizeOfElements, puVar11 = puVar8, local_108 != puVar8)) {
          do {
            uVar2 = puVar11[-iVar5];
            puVar11[-iVar5] = *puVar11;
            *puVar11 = uVar2;
            sVar10 = sVar10 - 1;
            puVar11 = puVar11 + 1;
          } while (sVar10 != 0);
        }
        puVar11 = local_108;
        puVar9 = puVar7;
        (*(code *)PTR_guard_check_icall_1001116c)();
        iVar5 = (*_PtFuncCompare)(puVar11,puVar9);
        if ((0 < iVar5) && (sVar10 = _SizeOfElements, puVar11 = puVar7, local_108 != puVar7)) {
          do {
            puVar9 = puVar11 + 1;
            uVar2 = puVar9[(int)(local_108 + (-1 - (int)puVar7))];
            puVar9[(int)(local_108 + (-1 - (int)puVar7))] = *puVar11;
            *puVar11 = uVar2;
            sVar10 = sVar10 - 1;
            puVar11 = puVar9;
          } while (sVar10 != 0);
        }
        (*(code *)PTR_guard_check_icall_1001116c)(puVar8);
        iVar5 = (*_PtFuncCompare)(in_stack_fffffec8,pvVar12);
        local_110 = local_108;
        local_100 = puVar7;
        if ((0 < iVar5) && (sVar10 = _SizeOfElements, puVar11 = puVar7, puVar8 != puVar7)) {
          do {
            puVar9 = puVar11 + 1;
            uVar2 = puVar9[(int)(puVar8 + (-1 - (int)puVar7))];
            puVar9[(int)(puVar8 + (-1 - (int)puVar7))] = *puVar11;
            *puVar11 = uVar2;
            sVar10 = sVar10 - 1;
            puVar11 = puVar9;
          } while (sVar10 != 0);
        }
LAB_1000cb53:
        if (local_110 < puVar8) {
          do {
            local_110 = local_110 + _SizeOfElements;
            if (puVar8 <= local_110) goto LAB_1000cba0;
            pvVar12 = (void *)0x1000cb7a;
            (*(code *)PTR_guard_check_icall_1001116c)(local_110,puVar8);
            iVar5 = (*_PtFuncCompare)(in_stack_fffffec8,pvVar12);
            puVar11 = local_100;
          } while (iVar5 < 1);
        }
        else {
LAB_1000cba0:
          do {
            local_110 = local_110 + _SizeOfElements;
            puVar11 = local_100;
            if (puVar7 < local_110) break;
            pvVar12 = (void *)0x1000cbb0;
            (*(code *)PTR_guard_check_icall_1001116c)(local_110,puVar8);
            iVar5 = (*_PtFuncCompare)(in_stack_fffffec8,pvVar12);
          } while (iVar5 < 1);
        }
        do {
          local_100 = puVar11;
          puVar11 = local_100 + -_SizeOfElements;
          if (puVar11 <= puVar8) break;
          pvVar12 = (void *)0x1000cbfe;
          (*(code *)PTR_guard_check_icall_1001116c)(puVar11,puVar8);
          iVar5 = (*_PtFuncCompare)(in_stack_fffffec8,pvVar12);
        } while (0 < iVar5);
        if (local_110 <= puVar11) {
          puVar9 = puVar11;
          sVar10 = _SizeOfElements;
          if (puVar11 != local_110) {
            do {
              puVar1 = puVar9 + 1;
              uVar2 = puVar1[(int)(local_110 + (-1 - (int)puVar11))];
              puVar1[(int)(local_110 + (-1 - (int)puVar11))] = *puVar9;
              *puVar9 = uVar2;
              sVar10 = sVar10 - 1;
              puVar9 = puVar1;
            } while (sVar10 != 0);
          }
          local_100 = puVar11;
          if (puVar8 == puVar11) {
            puVar8 = local_110;
          }
          goto LAB_1000cb53;
        }
        if (puVar8 < local_100) {
          do {
            local_100 = local_100 + -_SizeOfElements;
            if (local_100 <= puVar8) goto LAB_1000ccc0;
            pvVar12 = (void *)0x1000cc96;
            (*(code *)PTR_guard_check_icall_1001116c)(local_100,puVar8);
            iVar5 = (*_PtFuncCompare)(in_stack_fffffec8,pvVar12);
          } while (iVar5 == 0);
        }
        else {
LAB_1000ccc0:
          do {
            local_100 = local_100 + -_SizeOfElements;
            if (local_100 <= local_108) break;
            pvVar12 = (void *)0x1000ccd6;
            (*(code *)PTR_guard_check_icall_1001116c)(local_100,puVar8);
            iVar5 = (*_PtFuncCompare)(in_stack_fffffec8,pvVar12);
          } while (iVar5 == 0);
        }
        local_11c = puVar7;
        if ((int)local_100 - (int)local_108 < (int)puVar7 - (int)local_110) goto LAB_1000cd4a;
        if (local_108 < local_100) {
          auStack_80[(int)puVar7] = local_108;
          auStack_f8[(int)puVar7] = local_100;
          local_11c = puVar7 + 1;
        }
        local_108 = local_110;
        if (puVar7 <= local_110) goto LAB_1000cd83;
      }
      for (; puVar11 = local_108, puVar8 = local_108, local_108 < puVar7;
          puVar7 = puVar7 + -_SizeOfElements) {
        while (puVar8 = puVar8 + _SizeOfElements, puVar8 <= puVar7) {
          pvVar12 = (void *)0x1000c97d;
          (*(code *)PTR_guard_check_icall_1001116c)(puVar8,puVar11);
          iVar5 = (*_PtFuncCompare)(in_stack_fffffec8,pvVar12);
          if (0 < iVar5) {
            puVar11 = puVar8;
          }
        }
        if (puVar11 != puVar7) {
          puVar8 = puVar7;
          sVar10 = _SizeOfElements;
          do {
            uVar2 = puVar8[(int)puVar11 - (int)puVar7];
            (puVar8 + 1)[((int)puVar11 - (int)puVar7) + -1] = *puVar8;
            *puVar8 = uVar2;
            sVar10 = sVar10 - 1;
            puVar8 = puVar8 + 1;
          } while (sVar10 != 0);
        }
      }
      goto LAB_1000cd83;
    }
  }
  return;
LAB_1000cd4a:
  if (local_110 < puVar7) {
    auStack_80[(int)puVar7] = local_110;
    auStack_f8[(int)puVar7] = puVar7;
    local_11c = puVar7 + 1;
  }
  puVar7 = local_100;
  if (local_100 <= local_108) {
LAB_1000cd83:
    local_11c = local_11c + -1;
    if ((int)local_11c < 0) {
      return;
    }
    local_108 = (undefined1 *)auStack_80[(int)local_11c];
    puVar7 = (undefined1 *)auStack_f8[(int)local_11c];
  }
  goto LAB_1000c942;
}



/* VA 1000cdae */

undefined4 __cdecl FUN_1000cdae(char *param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  __acrt_ptd *p_Var2;
  char *pcVar3;
  int iVar4;
  undefined4 uStack_18;
  int local_8;

  if (param_4 == 0) {
    if (param_1 == (char *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_1000cde7:
      if (param_2 != 0) {
        if (param_4 == 0) {
          *param_1 = '\0';
          return 0;
        }
        if (param_3 != 0) {
          local_8 = param_4;
          pcVar3 = param_1;
          iVar4 = param_2;
          if (param_4 == -1) {
            do {
              cVar1 = pcVar3[param_3 - (int)param_1];
              *pcVar3 = cVar1;
              pcVar3 = pcVar3 + 1;
              if (cVar1 == '\0') {
                return 0;
              }
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            iVar4 = 0;
          }
          else {
            do {
              cVar1 = pcVar3[param_3 - (int)param_1];
              *pcVar3 = cVar1;
              pcVar3 = pcVar3 + 1;
              if (cVar1 == '\0') {
                return 0;
              }
              iVar4 = iVar4 + -1;
            } while ((iVar4 != 0) && (local_8 = local_8 + -1, local_8 != 0));
            if (local_8 == 0) {
              *pcVar3 = '\0';
            }
          }
          if (iVar4 != 0) {
            return 0;
          }
          if (param_4 == -1) {
            param_1[param_2 + -1] = '\0';
            return 0x50;
          }
          *param_1 = '\0';
          p_Var2 = FUN_100095db();
          uStack_18 = 0x22;
          goto LAB_1000cdd4;
        }
        *param_1 = '\0';
      }
    }
  }
  else if (param_1 != (char *)0x0) goto LAB_1000cde7;
  p_Var2 = FUN_100095db();
  uStack_18 = 0x16;
LAB_1000cdd4:
  *(undefined4 *)p_Var2 = uStack_18;
  FUN_100080a4();
  return uStack_18;
}



/* VA 1000ce65 */

void __cdecl FUN_1000ce65(char *param_1,int param_2,int param_3,int param_4)

{
  FUN_1000cdae(param_1,param_2,param_3,param_4);
  return;
}



/* VA 1000ce70 */

/* Library Function - Single Match
    _strpbrk

   Library: Visual Studio */

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



/* VA 1000ceb0 */

/* Library Function - Single Match
    __mbsdec

   Library: Visual Studio 2019 Release */

uchar * __cdecl __mbsdec(uchar *_Start,uchar *_Pos)

{
  uchar *puVar1;

  puVar1 = __mbsdec_l(_Start,_Pos,(_locale_t)0x0);
  return puVar1;
}



/* VA 1000cec7 */

/* Library Function - Single Match
    __mbsdec_l

   Library: Visual Studio 2019 Release */

uchar * __cdecl __mbsdec_l(uchar *_Start,uchar *_Pos,_locale_t _Locale)

{
  __acrt_ptd *p_Var1;
  byte *pbVar2;
  int local_14 [2];
  int local_c;
  char local_8;

  if (_Start == (uchar *)0x0) {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 0x16;
    FUN_100080a4();
    return (uchar *)0x0;
  }
  if (_Pos == (uchar *)0x0) {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 0x16;
    FUN_100080a4();
  }
  else if (_Start < _Pos) {
    FUN_10007c04(local_14,(int *)_Locale);
    pbVar2 = _Pos + -1;
    if (*(int *)(local_c + 8) != 0) {
      do {
        pbVar2 = pbVar2 + -1;
        if (pbVar2 < _Start) break;
      } while ((*(byte *)(*pbVar2 + 0x19 + local_c) & 4) != 0);
      pbVar2 = _Pos + (-1 - ((int)_Pos - (int)pbVar2 & 1U));
    }
    if (local_8 == '\0') {
      return pbVar2;
    }
    *(uint *)(local_14[0] + 0x350) = *(uint *)(local_14[0] + 0x350) & 0xfffffffd;
    return pbVar2;
  }
  return (uchar *)0x0;
}



/* VA 1000cf54 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
FUN_1000cf54(int *param_1,wchar_t *param_2,uint param_3,char *param_4,int param_5,LPWSTR param_6,
            int param_7,uint param_8,int param_9)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  LPCWSTR pWVar5;
  LPCWSTR pWVar6;

  iVar3 = param_5;
  if (0 < param_5) {
    iVar1 = ___strncnt(param_4,param_5);
    iVar3 = iVar1 + 1;
    if (param_5 <= iVar1) {
      iVar3 = iVar1;
    }
  }
  if (param_8 == 0) {
    param_8 = *(uint *)(*param_1 + 8);
  }
  iVar1 = FUN_1000b2b2(param_8,(uint)(param_9 != 0) * 8 + 1,param_4,iVar3,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = iVar1 * 2 + 8;
  uVar2 = -(uint)((uint)(iVar1 * 2) < uVar2) & uVar2;
  if (uVar2 == 0) {
    pWVar5 = (LPCWSTR)0x0;
  }
  else if (uVar2 < 0x401) {
    puVar4 = (undefined4 *)&stack0xffffffe8;
    pWVar5 = (LPCWSTR)&stack0xffffffe8;
    if (&stack0x00000000 != (undefined1 *)0x18) {
LAB_1000d007:
      pWVar5 = (LPCWSTR)(puVar4 + 2);
      if (((pWVar5 != (LPCWSTR)0x0) &&
          (iVar3 = FUN_1000b2b2(param_8,1,param_4,iVar3,pWVar5,iVar1), iVar3 != 0)) &&
         (iVar3 = FID_conflict____acrt_CompareStringEx_36
                            (param_2,param_3,pWVar5,iVar1,(LPWSTR)0x0,0,0,0,0), iVar3 != 0)) {
        if ((param_3 & 0x400) == 0) {
          uVar2 = iVar3 * 2 + 8;
          uVar2 = -(uint)((uint)(iVar3 * 2) < uVar2) & uVar2;
          if (uVar2 == 0) {
            pWVar6 = (LPCWSTR)0x0;
          }
          else if (uVar2 < 0x401) {
            puVar4 = (undefined4 *)&stack0xffffffe8;
            pWVar6 = (LPCWSTR)&stack0xffffffe8;
            if (&stack0x00000000 != (undefined1 *)0x18) {
LAB_1000d0c8:
              pWVar6 = (LPCWSTR)(puVar4 + 2);
              if ((pWVar6 != (LPCWSTR)0x0) &&
                 (iVar1 = FID_conflict____acrt_CompareStringEx_36
                                    (param_2,param_3,pWVar5,iVar1,pWVar6,iVar3,0,0,0), iVar1 != 0))
              {
                if (param_7 == 0) {
                  param_7 = 0;
                  param_6 = (LPWSTR)0x0;
                }
                iVar3 = FUN_1000b36c(param_8,0,pWVar6,iVar3,(LPSTR)param_6,param_7,0,
                                     (undefined4 *)0x0);
                if (iVar3 != 0) {
                  FUN_1000c895((int)pWVar6);
                  goto LAB_1000d128;
                }
              }
            }
          }
          else {
            puVar4 = __malloc_base(uVar2);
            pWVar6 = (LPCWSTR)0x0;
            if (puVar4 != (undefined4 *)0x0) {
              *puVar4 = 0xdddd;
              goto LAB_1000d0c8;
            }
          }
          FUN_1000c895((int)pWVar6);
        }
        else if ((param_7 == 0) ||
                ((iVar3 <= param_7 &&
                 (iVar3 = FID_conflict____acrt_CompareStringEx_36
                                    (param_2,param_3,pWVar5,iVar1,param_6,param_7,0,0,0), iVar3 != 0
                 )))) goto LAB_1000d128;
      }
    }
  }
  else {
    puVar4 = __malloc_base(uVar2);
    pWVar5 = (LPCWSTR)0x0;
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = 0xdddd;
      goto LAB_1000d007;
    }
  }
  iVar3 = 0;
LAB_1000d128:
  FUN_1000c895((int)pWVar5);
  return iVar3;
}



/* VA 1000d143 */

/* Library Function - Single Match
    ___acrt_LCMapStringA

   Library: Visual Studio 2019 Release */

void __cdecl
___acrt_LCMapStringA
          (int *param_1,wchar_t *param_2,uint param_3,char *param_4,int param_5,LPWSTR param_6,
          int param_7,uint param_8,int param_9)

{
  int local_14;
  int local_10 [2];
  char local_8;

  FUN_10007c04(&local_14,param_1);
  FUN_1000cf54(local_10,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return;
}



/* VA 1000d19b */

/* Library Function - Multiple Matches With Different Base Names
    __msize
    __msize_base

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

size_t __cdecl FID_conflict___msize_base(void *_Memory)

{
  __acrt_ptd *p_Var1;
  SIZE_T SVar2;

  if (_Memory == (void *)0x0) {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 0x16;
    FUN_100080a4();
    return 0xffffffff;
  }
  SVar2 = HeapSize(DAT_1001a174,0,_Memory);
  return SVar2;
}



/* VA 1000d1ce */

/* Library Function - Single Match
    __realloc_base

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID __cdecl __realloc_base(LPVOID param_1,uint param_2)

{
  bool bVar1;
  LPVOID pvVar2;
  __acrt_ptd *p_Var3;
  int iVar4;
  undefined3 extraout_var;

  if (param_1 == (LPVOID)0x0) {
    pvVar2 = __malloc_base(param_2);
  }
  else {
    if (param_2 == 0) {
      FUN_10009f36(param_1);
    }
    else {
      if (param_2 < 0xffffffe1) {
        do {
          pvVar2 = HeapReAlloc(DAT_1001a174,0,param_1,param_2);
          if (pvVar2 != (LPVOID)0x0) {
            return pvVar2;
          }
          iVar4 = FUN_1000c8b5();
        } while ((iVar4 != 0) && (bVar1 = FUN_100081b2(param_2), CONCAT31(extraout_var,bVar1) != 0))
        ;
      }
      p_Var3 = FUN_100095db();
      *(undefined4 *)p_Var3 = 0xc;
    }
    pvVar2 = (LPVOID)0x0;
  }
  return pvVar2;
}



/* VA 1000d237 */

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl GetTableIndexFromLocaleName(wchar_t const *)
    int __cdecl ATL::_AtlGetTableIndexFromLocaleName(wchar_t const *)
    _GetTableIndexFromLocaleName

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __cdecl FID_conflict_GetTableIndexFromLocaleName(ushort *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  iVar4 = 0;
  iVar2 = 0xe3;
  do {
    iVar3 = (iVar2 + iVar4) / 2;
    iVar1 = FUN_1000e3f5(param_1,*(ushort **)(&UNK_100141a0 + iVar3 * 8),0x55);
    if (iVar1 == 0) {
      return *(undefined4 *)(&UNK_100141a4 + iVar3 * 8);
    }
    if (iVar1 < 0) {
      iVar2 = iVar3 + -1;
    }
    else {
      iVar4 = iVar3 + 1;
    }
  } while (iVar4 <= iVar2);
  return 0xffffffff;
}



/* VA 1000d287 */

/* Library Function - Single Match
    ___acrt_DownlevelLocaleNameToLCID

   Library: Visual Studio 2019 Release */

undefined4 __cdecl ___acrt_DownlevelLocaleNameToLCID(ushort *param_1)

{
  uint uVar1;

  if (param_1 != (ushort *)0x0) {
    uVar1 = FID_conflict_GetTableIndexFromLocaleName(param_1);
    if ((-1 < (int)uVar1) && (uVar1 < 0xe4)) {
      return *(undefined4 *)(&DAT_10013080 + uVar1 * 8);
    }
  }
  return 0;
}



/* VA 1000d2b3 */

/* Library Function - Single Match
    ___acrt_lowio_create_handle_array

   Library: Visual Studio 2019 Release */

undefined4 * ___acrt_lowio_create_handle_array(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = __calloc_base(0x40,0x38);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else if (puVar2 != puVar2 + 0x380) {
    puVar3 = puVar2 + 8;
    do {
      ___acrt_InitializeCriticalSectionEx_12((LPCRITICAL_SECTION)(puVar3 + -8),4000,0);
      puVar3[-2] = 0xffffffff;
      *(byte *)((int)puVar3 + 0xd) = *(byte *)((int)puVar3 + 0xd) & 0xf8;
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar1 = puVar3 + 6;
      puVar3[2] = 0xa0a0000;
      *(undefined1 *)(puVar3 + 3) = 10;
      *(undefined4 *)((int)puVar3 + 0xe) = 0;
      *(undefined1 *)((int)puVar3 + 0x12) = 0;
      puVar3 = puVar3 + 0xe;
    } while (puVar1 != puVar2 + 0x380);
  }
  FUN_10009f36((LPVOID)0x0);
  return puVar2;
}



/* VA 1000d32e */

/* Library Function - Single Match
    ___acrt_lowio_destroy_handle_array

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___acrt_lowio_destroy_handle_array(LPCRITICAL_SECTION param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;

  if (param_1 != (LPCRITICAL_SECTION)0x0) {
    for (lpCriticalSection = param_1;
        lpCriticalSection != (LPCRITICAL_SECTION)&param_1[0x95].RecursionCount;
        lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[2].RecursionCount) {
      DeleteCriticalSection(lpCriticalSection);
    }
    FUN_10009f36(param_1);
  }
  return;
}



/* VA 1000d363 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    ___acrt_lowio_ensure_fh_exists

   Library: Visual Studio 2019 Release */

undefined4 __cdecl ___acrt_lowio_ensure_fh_exists(uint param_1)

{
  __acrt_ptd *p_Var1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  void *local_14;

  if (param_1 < 0x2000) {
    uVar4 = 0;
    ___acrt_lock(7);
    iVar5 = 0;
    iVar3 = DAT_1001a378;
    while (iVar3 <= (int)param_1) {
      if ((&DAT_1001a178)[iVar5] == 0) {
        puVar2 = ___acrt_lowio_create_handle_array();
        (&DAT_1001a178)[iVar5] = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          uVar4 = 0xc;
          break;
        }
        iVar3 = DAT_1001a378 + 0x40;
        DAT_1001a378 = iVar3;
      }
      iVar5 = iVar5 + 1;
    }
    FUN_1000d3f8();
  }
  else {
    p_Var1 = FUN_100095db();
    uVar4 = 9;
    *(undefined4 *)p_Var1 = 9;
    FUN_100080a4();
  }
  ExceptionList = local_14;
  return uVar4;
}



/* VA 1000d3f8 */

void FUN_1000d3f8(void)

{
  ___acrt_unlock(7);
  return;
}



/* VA 1000d401 */

void __cdecl FUN_1000d401(uint param_1)

{
  EnterCriticalSection
            ((LPCRITICAL_SECTION)((param_1 & 0x3f) * 0x38 + (&DAT_1001a178)[(int)param_1 >> 6]));
  return;
}



/* VA 1000d424 */

/* Library Function - Single Match
    ___acrt_lowio_unlock_fh

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___acrt_lowio_unlock_fh(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)((param_1 & 0x3f) * 0x38 + (&DAT_1001a178)[(int)param_1 >> 6]));
  return;
}



/* VA 1000d447 */

undefined4 __cdecl FUN_1000d447(uint param_1)

{
  int iVar1;
  __acrt_ptd *p_Var2;
  int iVar3;
  DWORD nStdHandle;

  if ((-1 < (int)param_1) && (param_1 < DAT_1001a378)) {
    iVar3 = (param_1 & 0x3f) * 0x38;
    if (((*(byte *)(iVar3 + 0x28 + (&DAT_1001a178)[param_1 >> 6]) & 1) != 0) &&
       (*(int *)(iVar3 + 0x18 + (&DAT_1001a178)[param_1 >> 6]) != -1)) {
      iVar1 = FUN_1000e460();
      if (iVar1 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1000d4ad;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_1000d4ad:
      *(undefined4 *)((&DAT_1001a178)[param_1 >> 6] + 0x18 + iVar3) = 0xffffffff;
      return 0;
    }
  }
  p_Var2 = FUN_100095db();
  *(undefined4 *)p_Var2 = 9;
  p_Var2 = FUN_100095c8();
  *(undefined4 *)p_Var2 = 0;
  return 0xffffffff;
}



/* VA 1000d4d8 */

undefined4 __cdecl FUN_1000d4d8(uint param_1)

{
  __acrt_ptd *p_Var1;
  int iVar2;

  if (param_1 == 0xfffffffe) {
    p_Var1 = FUN_100095c8();
    *(undefined4 *)p_Var1 = 0;
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_1001a378)) {
      iVar2 = (param_1 & 0x3f) * 0x38;
      if ((*(byte *)((&DAT_1001a178)[param_1 >> 6] + 0x28 + iVar2) & 1) != 0) {
        return *(undefined4 *)((&DAT_1001a178)[param_1 >> 6] + 0x18 + iVar2);
      }
    }
    p_Var1 = FUN_100095c8();
    *(undefined4 *)p_Var1 = 0;
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 9;
    FUN_100080a4();
  }
  return 0xffffffff;
}



/* VA 1000d542 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

undefined4 FUN_1000d542(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  HANDLE hFile;
  BOOL BVar2;
  DWORD DVar3;
  __acrt_ptd *p_Var4;
  undefined4 uVar5;
  void *local_14;

  uVar5 = 0;
  FUN_1000d401(*param_1);
  uVar1 = *(uint *)*param_2;
  if ((*(byte *)((&DAT_1001a178)[(int)uVar1 >> 6] + 0x28 + (uVar1 & 0x3f) * 0x38) & 1) != 0) {
    hFile = (HANDLE)FUN_1000d4d8(uVar1);
    BVar2 = FlushFileBuffers(hFile);
    if (BVar2 != 0) goto LAB_1000d5b2;
    DVar3 = GetLastError();
    p_Var4 = FUN_100095c8();
    *(DWORD *)p_Var4 = DVar3;
  }
  p_Var4 = FUN_100095db();
  *(undefined4 *)p_Var4 = 9;
  uVar5 = 0xffffffff;
LAB_1000d5b2:
  FUN_1000d5d8();
  ExceptionList = local_14;
  return uVar5;
}



/* VA 1000d5d8 */

void FUN_1000d5d8(void)

{
  int unaff_EBP;

  ___acrt_lowio_unlock_fh(**(uint **)(unaff_EBP + 0x10));
  return;
}



/* VA 1000d5e4 */

/* Library Function - Single Match
    __commit

   Library: Visual Studio 2019 Release */

int __cdecl __commit(int _FileHandle)

{
  __acrt_ptd *p_Var1;
  int iVar2;
  uint local_14;
  int *local_10;
  int local_c;

  if (_FileHandle == -2) {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 9;
  }
  else {
    if (((-1 < _FileHandle) && ((uint)_FileHandle < DAT_1001a378)) &&
       ((*(byte *)((&DAT_1001a178)[_FileHandle >> 6] + 0x28 + (_FileHandle & 0x3fU) * 0x38) & 1) !=
        0)) {
      local_10 = &_FileHandle;
      local_c = _FileHandle;
      local_14 = _FileHandle;
      iVar2 = FUN_1000d542(&local_14,&local_10);
      return iVar2;
    }
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 9;
    FUN_100080a4();
  }
  return -1;
}



/* VA 1000d661 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

DWORD * __cdecl FUN_1000d661(DWORD *param_1,uint param_2,uint *param_3,int param_4,int *param_5)

{
  undefined1 *puVar1;
  byte bVar2;
  ushort uVar3;
  byte *pbVar4;
  BOOL BVar5;
  DWORD DVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  UINT local_70;
  uint *local_6c;
  HANDLE local_68;
  uint *local_64;
  uint *local_60;
  undefined2 local_5c [2];
  uint *local_58;
  int local_54;
  uint local_50;
  byte *local_4c;
  int local_48;
  undefined4 local_44;
  int *local_40;
  uint *local_3c;
  uint local_38;
  char local_31;
  uint *local_30;
  CHAR local_2c [8];
  undefined1 local_24;
  undefined1 local_23;
  uint local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;

  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10010ee0;
  local_10 = ExceptionList;
  local_1c[2] = DAT_10019008 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = (param_2 & 0x3f) * 0x38;
  local_48 = (int)param_2 >> 6;
  local_64 = param_3;
  local_40 = param_5;
  local_68 = *(HANDLE *)(local_54 + 0x18 + (&DAT_1001a178)[local_48]);
  local_58 = (uint *)(param_4 + (int)param_3);
  local_70 = GetConsoleOutputCP();
  if ((char)param_5[5] == '\0') {
    FUN_100091a0(param_5);
  }
  local_74 = *(int *)(param_5[3] + 8);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_30 = local_64;
  if (local_58 <= local_64) {
    ExceptionList = local_10;
    return param_1;
  }
  local_4c = (byte *)0x0;
  iVar8 = local_54;
  do {
    iVar9 = 0;
    local_31 = (char)*local_30;
    local_44 = 0;
    local_38 = 1;
    if (local_74 == 0xfde9) {
      local_4c = (byte *)((&DAT_1001a178)[local_48] + 0x2e + iVar8);
      pbVar4 = local_4c;
      local_38 = iVar9;
      do {
        if (*pbVar4 == 0) break;
        local_38 = local_38 + 1;
        pbVar4 = pbVar4 + 1;
      } while ((int)local_38 < 5);
      iVar8 = (int)local_58 - (int)local_30;
      if ((int)local_38 < 1) {
        local_50 = (int)(char)(&DAT_10019740)[(byte)*local_30] + 1;
        if (iVar8 < (int)local_50) {
          if (0 < iVar8) {
            do {
              *(undefined1 *)((&DAT_1001a178)[local_48] + local_54 + 0x2e + iVar9) =
                   *(undefined1 *)(iVar9 + (int)local_30);
              iVar9 = iVar9 + 1;
            } while (iVar9 < iVar8);
          }
          goto LAB_1000d9b8;
        }
        local_84 = 0;
        local_80 = 0;
        local_38 = (local_50 == 4) + 1;
        local_3c = local_30;
        iVar9 = FUN_1000e2ed(&local_84,(ushort *)&local_44,&local_3c,local_38,&local_84,
                             (int)local_40);
        iVar8 = local_54;
      }
      else {
        local_3c = (uint *)((int)(char)(&DAT_10019740)[*local_4c] + 1);
        local_50 = (int)local_3c - local_38;
        pbVar4 = local_4c;
        if (iVar8 < (int)local_50) {
          if (0 < iVar8) {
            do {
              puVar1 = (undefined1 *)(iVar9 + (int)local_30);
              iVar7 = (&DAT_1001a178)[local_48] + local_54 + iVar9;
              iVar9 = iVar9 + 1;
              *(undefined1 *)(iVar7 + 0x2e + local_38) = *puVar1;
            } while (iVar9 < iVar8);
          }
LAB_1000d9b8:
          param_1[1] = param_1[1] + iVar8;
          ExceptionList = local_10;
          return param_1;
        }
        do {
          *(byte *)((int)local_1c + iVar9) = *pbVar4;
          iVar9 = iVar9 + 1;
          pbVar4 = pbVar4 + 1;
        } while (iVar9 < (int)local_38);
        if (0 < (int)local_50) {
          FUN_10007600((uint *)((int)local_1c + local_38),local_30,local_50);
        }
        iVar8 = local_54;
        iVar9 = 0;
        do {
          *(undefined1 *)((&DAT_1001a178)[local_48] + local_54 + 0x2e + iVar9) = 0;
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)local_38);
        local_6c = local_1c;
        local_7c = 0;
        local_78 = 0;
        local_38 = (local_3c == (uint *)0x4) + 1;
        iVar9 = FUN_1000e2ed(&local_7c,(ushort *)&local_44,&local_6c,local_38,&local_7c,
                             (int)local_40);
      }
      if (iVar9 == -1) {
        ExceptionList = local_10;
        return param_1;
      }
      local_30 = (uint *)((int)local_30 + (local_50 - 1));
    }
    else {
      local_50 = (&DAT_1001a178)[local_48];
      bVar2 = *(byte *)(local_50 + 0x2d + iVar8);
      if ((bVar2 & 4) == 0) {
        if (*(short *)(*(int *)local_40[3] + (uint)(byte)*local_30 * 2) < 0) {
          local_3c = (uint *)((int)local_30 + 1);
          if (local_58 <= local_3c) {
            *(char *)(local_50 + 0x2e + iVar8) = (char)*local_30;
            pbVar4 = (byte *)((&DAT_1001a178)[local_48] + 0x2d + iVar8);
            *pbVar4 = *pbVar4 | 4;
            param_1[1] = (DWORD)(local_4c + 1);
            ExceptionList = local_10;
            return param_1;
          }
          uVar11 = FUN_1000c030((LPWSTR)&local_44,(byte *)local_30,2,local_40);
          local_30 = local_3c;
          if (uVar11 == 0xffffffff) {
            ExceptionList = local_10;
            return param_1;
          }
          goto LAB_1000d8df;
        }
        uVar11 = 1;
        puVar10 = local_30;
      }
      else {
        uVar3 = CONCAT11(bVar2,*(undefined1 *)(local_50 + 0x2e + iVar8)) & 0xfbff;
        local_24 = (undefined1)uVar3;
        local_23 = (undefined1)*local_30;
        *(char *)(local_50 + 0x2d + iVar8) = (char)(uVar3 >> 8);
        uVar11 = 2;
        puVar10 = (uint *)&local_24;
      }
      uVar11 = FUN_1000c030((LPWSTR)&local_44,(byte *)puVar10,uVar11,local_40);
      if (uVar11 == 0xffffffff) {
        ExceptionList = local_10;
        return param_1;
      }
    }
LAB_1000d8df:
    local_30 = (uint *)((int)local_30 + 1);
    local_3c = (uint *)FUN_1000b36c(local_70,0,(LPCWSTR)&local_44,local_38,local_2c,5,0,
                                    (undefined4 *)0x0);
    if (local_3c == (uint *)0x0) {
      ExceptionList = local_10;
      return param_1;
    }
    BVar5 = WriteFile(local_68,local_2c,(DWORD)local_3c,(LPDWORD)&local_60,(LPOVERLAPPED)0x0);
    if (BVar5 == 0) {
LAB_1000d9ff:
      DVar6 = GetLastError();
      *param_1 = DVar6;
      ExceptionList = local_10;
      return param_1;
    }
    local_4c = (byte *)((param_1[2] - (int)local_64) + (int)local_30);
    param_1[1] = (DWORD)local_4c;
    if (local_60 < local_3c) {
      ExceptionList = local_10;
      return param_1;
    }
    if (local_31 == '\n') {
      local_5c[0] = 0xd;
      BVar5 = WriteFile(local_68,local_5c,1,(LPDWORD)&local_60,(LPOVERLAPPED)0x0);
      if (BVar5 == 0) goto LAB_1000d9ff;
      if (local_60 == (uint *)0x0) {
        ExceptionList = local_10;
        return param_1;
      }
      param_1[2] = param_1[2] + 1;
      param_1[1] = param_1[1] + 1;
      local_4c = (byte *)param_1[1];
    }
    if (local_58 <= local_30) {
      ExceptionList = local_10;
      return param_1;
    }
  } while( true );
}



/* VA 1000da28 */

/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_double_translated_unicode_nolock(char
   const * const,unsigned int)

   Library: Visual Studio 2019 Release */

char * __cdecl write_double_translated_unicode_nolock(char *param_1,uint param_2)

{
  wchar_t _WCh;
  wchar_t wVar1;
  wint_t wVar2;
  wchar_t *pwVar3;
  DWORD DVar4;
  int in_stack_0000000c;

  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  pwVar3 = (wchar_t *)(in_stack_0000000c + param_2);
  while( true ) {
    if (pwVar3 <= param_2) {
      return param_1;
    }
    _WCh = *(wchar_t *)param_2;
    wVar1 = __putwch_nolock(_WCh);
    if (wVar1 != _WCh) break;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 2;
    if (_WCh == L'\n') {
      wVar2 = __putwch_nolock(L'\r');
      if (wVar2 != 0xd) break;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    param_2 = param_2 + 2;
  }
  DVar4 = GetLastError();
  *(DWORD *)param_1 = DVar4;
  return param_1;
}



/* VA 1000da90 */

bool __cdecl FUN_1000da90(uint param_1,int *param_2)

{
  byte bVar1;
  undefined3 extraout_var;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  DWORD local_8;

  bVar1 = FUN_1000e21b(param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar4 = (int)param_1 >> 6;
    iVar3 = (param_1 & 0x3f) * 0x38;
    if (*(char *)((&DAT_1001a178)[iVar4] + 0x28 + iVar3) < '\0') {
      if ((char)param_2[5] == '\0') {
        FUN_100091a0(param_2);
      }
      if ((*(int *)(param_2[3] + 0xa8) != 0) ||
         (*(char *)((&DAT_1001a178)[iVar4] + 0x29 + iVar3) != '\0')) {
        BVar2 = GetConsoleMode(*(HANDLE *)((&DAT_1001a178)[iVar4] + 0x18 + iVar3),&local_8);
        return BVar2 != 0;
      }
    }
  }
  return false;
}



/* VA 1000db0d */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_text_ansi_nolock(int,char const *
   const,unsigned int)

   Library: Visual Studio 2019 Release */

int __cdecl write_text_ansi_nolock(int param_1,char *param_2,uint param_3)

{
  char cVar1;
  char *hFile;
  BOOL BVar2;
  DWORD DVar3;
  char *pcVar4;
  char *pcVar5;
  int in_stack_00000010;
  char *local_140c;
  char local_1408 [5120];
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  hFile = *(char **)((&DAT_1001a178)[(int)param_2 >> 6] + 0x18 + ((uint)param_2 & 0x3f) * 0x38);
  pcVar4 = (char *)(in_stack_00000010 + param_3);
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  local_140c = hFile;
  do {
    if (pcVar4 <= param_3) {
      return param_1;
    }
    pcVar5 = local_1408;
    do {
      if (pcVar4 <= param_3) break;
      cVar1 = *(char *)param_3;
      param_3 = param_3 + 1;
      if (cVar1 == '\n') {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        *pcVar5 = '\r';
        pcVar5 = pcVar5 + 1;
      }
      *pcVar5 = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (pcVar5 < local_1408 + 0x13ff);
    BVar2 = WriteFile(hFile,local_1408,(DWORD)(pcVar5 + -(int)local_1408),(LPDWORD)&local_140c,
                      (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      *(DWORD *)param_1 = DVar3;
      return param_1;
    }
    *(int *)(param_1 + 4) = (int)(local_140c + *(int *)(param_1 + 4));
    if (local_140c < pcVar5 + -(int)local_1408) {
      return param_1;
    }
  } while( true );
}



/* VA 1000dbe8 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_text_utf16le_nolock(int,char const *
   const,unsigned int)

   Library: Visual Studio 2019 Release */

int __cdecl write_text_utf16le_nolock(int param_1,char *param_2,uint param_3)

{
  short sVar1;
  BOOL BVar2;
  DWORD DVar3;
  short *psVar4;
  short *psVar5;
  int in_stack_00000010;
  uint local_1410;
  HANDLE local_140c;
  short local_1408 [2560];
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  local_140c = *(HANDLE *)
                ((&DAT_1001a178)[(int)param_2 >> 6] + 0x18 + ((uint)param_2 & 0x3f) * 0x38);
  psVar4 = (short *)(in_stack_00000010 + param_3);
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  do {
    if (psVar4 <= param_3) {
      return param_1;
    }
    psVar5 = local_1408;
    do {
      if (psVar4 <= param_3) break;
      sVar1 = *(short *)param_3;
      param_3 = param_3 + 2;
      if (sVar1 == 10) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 2;
        *psVar5 = 0xd;
        psVar5 = psVar5 + 1;
      }
      *psVar5 = sVar1;
      psVar5 = psVar5 + 1;
    } while (psVar5 < local_1408 + 0x9ff);
    BVar2 = WriteFile(local_140c,local_1408,(int)psVar5 - (int)local_1408,&local_1410,
                      (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      *(DWORD *)param_1 = DVar3;
      return param_1;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + local_1410;
    if (local_1410 < (uint)((int)psVar5 - (int)local_1408)) {
      return param_1;
    }
  } while( true );
}



/* VA 1000dcd1 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_text_utf8_nolock(int,char const *
   const,unsigned int)

   Library: Visual Studio 2019 Release */

int __cdecl write_text_utf8_nolock(int param_1,char *param_2,uint param_3)

{
  WCHAR WVar1;
  WCHAR *pWVar2;
  uint uVar3;
  BOOL BVar4;
  DWORD DVar5;
  uint uVar6;
  WCHAR *pWVar7;
  int in_stack_00000010;
  DWORD local_1418;
  HANDLE local_1414;
  WCHAR *local_1410;
  CHAR local_140c [3416];
  WCHAR local_6b4 [854];
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  local_1414 = *(HANDLE *)
                ((&DAT_1001a178)[(int)param_2 >> 6] + 0x18 + ((uint)param_2 & 0x3f) * 0x38);
  local_1410 = (WCHAR *)(in_stack_00000010 + param_3);
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  pWVar7 = (WCHAR *)param_3;
  if (param_3 < local_1410) {
    do {
      pWVar2 = local_6b4;
      do {
        if (local_1410 <= pWVar7) break;
        WVar1 = *pWVar7;
        pWVar7 = pWVar7 + 1;
        if (WVar1 == L'\n') {
          *pWVar2 = L'\r';
          pWVar2 = pWVar2 + 1;
        }
        *pWVar2 = WVar1;
        pWVar2 = pWVar2 + 1;
      } while (pWVar2 < local_6b4 + 0x354);
      uVar3 = FUN_1000b36c(0xfde9,0,local_6b4,(int)pWVar2 - (int)local_6b4 >> 1,local_140c,0xd55,0,
                           (undefined4 *)0x0);
      if (uVar3 == 0) {
LAB_1000ddea:
        DVar5 = GetLastError();
        *(DWORD *)param_1 = DVar5;
        return param_1;
      }
      uVar6 = 0;
      if (uVar3 != 0) {
        do {
          BVar4 = WriteFile(local_1414,local_140c + uVar6,uVar3 - uVar6,&local_1418,
                            (LPOVERLAPPED)0x0);
          if (BVar4 == 0) goto LAB_1000ddea;
          uVar6 = uVar6 + local_1418;
        } while (uVar6 < uVar3);
      }
      *(uint *)(param_1 + 4) = (int)pWVar7 - param_3;
    } while (pWVar7 < local_1410);
  }
  return param_1;
}



/* VA 1000de03 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

int __cdecl FUN_1000de03(char *param_1,uint *param_2,uint param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  void *local_14;

  if (param_1 == (char *)0xfffffffe) {
    *(undefined1 *)(param_4 + 9) = 1;
    param_4[8] = 0;
    *(undefined1 *)(param_4 + 7) = 1;
    param_4[6] = 9;
  }
  else {
    if (((int)param_1 < 0) || (DAT_1001a378 <= param_1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      iVar2 = ((uint)param_1 & 0x3f) * 0x38;
      if ((*(byte *)((&DAT_1001a178)[(int)param_1 >> 6] + 0x28 + iVar2) & 1) != 0) {
        FUN_1000d401((uint)param_1);
        iVar3 = -1;
        if ((*(byte *)(iVar2 + 0x28 + (&DAT_1001a178)[(int)param_1 >> 6]) & 1) == 0) {
          *(undefined1 *)(param_4 + 7) = 1;
          param_4[6] = 9;
          *(undefined1 *)(param_4 + 9) = 1;
          param_4[8] = 0;
        }
        else {
          iVar3 = FUN_1000df14(param_1,param_2,param_3,param_4);
        }
        FUN_1000df0c();
        ExceptionList = local_14;
        return iVar3;
      }
    }
    *(undefined1 *)(param_4 + 9) = 1;
    param_4[8] = 0;
    *(undefined1 *)(param_4 + 7) = 1;
    param_4[6] = 9;
    FUN_10008027((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_4);
  }
  ExceptionList = local_14;
  return -1;
}



/* VA 1000df0c */

void FUN_1000df0c(void)

{
  uint unaff_EDI;

  ___acrt_lowio_unlock_fh(unaff_EDI);
  return;
}



/* VA 1000df14 */

int __cdecl FUN_1000df14(char *param_1,uint *param_2,uint param_3,int *param_4)

{
  bool bVar1;
  DWORD *pDVar2;
  BOOL BVar3;
  DWORD DVar4;
  DWORD local_34 [5];
  DWORD local_20;
  int local_1c;
  int local_18;
  char *local_14;
  uint local_10;
  uint *local_c;
  char local_5;

  local_14 = param_1;
  local_c = param_2;
  local_10 = param_3;
  if (param_3 == 0) {
    return 0;
  }
  if (param_2 == (uint *)0x0) {
LAB_1000df40:
    *(undefined1 *)(param_4 + 9) = 1;
    param_4[8] = 0;
    *(undefined1 *)(param_4 + 7) = 1;
    param_4[6] = 0x16;
    FUN_10008027((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_4);
    return -1;
  }
  local_18 = (int)param_1 >> 6;
  local_1c = ((uint)param_1 & 0x3f) * 0x38;
  local_5 = *(char *)(local_1c + 0x29 + (&DAT_1001a178)[local_18]);
  if (((local_5 == '\x02') || (local_5 == '\x01')) && ((~param_3 & 1) == 0)) goto LAB_1000df40;
  if ((*(byte *)(local_1c + 0x28 + (&DAT_1001a178)[local_18]) & 0x20) != 0) {
    FUN_1000e4e9((uint)param_1,0,0,(PLARGE_INTEGER)0x2,(int)param_4);
  }
  DVar4 = 0;
  local_34[3] = 0;
  bVar1 = FUN_1000da90((uint)local_14,param_4);
  if (bVar1) {
    if (local_5 == '\0') {
      pDVar2 = FUN_1000d661(local_34,(uint)local_14,local_c,local_10,param_4);
    }
    else {
      if ((local_5 != '\x01') && (local_5 != '\x02')) goto LAB_1000e0c7;
      pDVar2 = (DWORD *)write_double_translated_unicode_nolock((char *)local_34,(uint)local_c);
    }
  }
  else if (*(char *)((&DAT_1001a178)[local_18] + 0x28 + local_1c) < '\0') {
    if (local_5 == '\0') {
      pDVar2 = (DWORD *)write_text_ansi_nolock((int)local_34,local_14,(uint)local_c);
    }
    else if (local_5 == '\x01') {
      pDVar2 = (DWORD *)write_text_utf8_nolock((int)local_34,local_14,(uint)local_c);
    }
    else {
      if (local_5 != '\x02') goto LAB_1000e0c7;
      pDVar2 = (DWORD *)write_text_utf16le_nolock((int)local_34,local_14,(uint)local_c);
    }
  }
  else {
    local_34[0] = 0;
    local_34[1] = 0;
    local_34[2] = 0;
    BVar3 = WriteFile(*(HANDLE *)((&DAT_1001a178)[local_18] + 0x18 + local_1c),local_c,local_10,
                      local_34 + 1,(LPOVERLAPPED)0x0);
    if (BVar3 == 0) {
      local_34[0] = GetLastError();
    }
    pDVar2 = local_34;
  }
  DVar4 = *pDVar2;
  local_34[3] = DVar4;
  local_34[4] = pDVar2[1];
  local_20 = pDVar2[2];
  if (local_34[4] != 0) {
    return local_34[4] - local_20;
  }
LAB_1000e0c7:
  if (DVar4 != 0) {
    if (DVar4 == 5) {
      *(undefined1 *)(param_4 + 7) = 1;
      param_4[6] = 9;
      *(undefined1 *)(param_4 + 9) = 1;
      param_4[8] = 5;
      return -1;
    }
    FUN_100095a4(DVar4,(int)param_4);
    return -1;
  }
  if (((*(byte *)((&DAT_1001a178)[local_18] + 0x28 + local_1c) & 0x40) != 0) &&
     ((char)*local_c == '\x1a')) {
    return 0;
  }
  *(undefined1 *)(param_4 + 7) = 1;
  param_4[6] = 0x1c;
  *(undefined1 *)(param_4 + 9) = 1;
  param_4[8] = 0;
  return -1;
}



/* VA 1000e130 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

int FUN_1000e130(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_14;

  local_20 = 0;
  ___acrt_lock(8);
  for (iVar2 = 3; iVar2 != DAT_1001a380; iVar2 = iVar2 + 1) {
    iVar1 = *(int *)(DAT_1001a384 + iVar2 * 4);
    if (iVar1 != 0) {
      if ((*(uint *)(iVar1 + 0xc) >> 0xd & 1) != 0) {
        iVar1 = FUN_1000e65e(*(FILE **)(DAT_1001a384 + iVar2 * 4));
        if (iVar1 != -1) {
          local_20 = local_20 + 1;
        }
      }
      DeleteCriticalSection((LPCRITICAL_SECTION)(*(int *)(DAT_1001a384 + iVar2 * 4) + 0x20));
      FUN_10009f36(*(LPVOID *)(DAT_1001a384 + iVar2 * 4));
      *(undefined4 *)(DAT_1001a384 + iVar2 * 4) = 0;
    }
  }
  FUN_1000e1d2();
  ExceptionList = local_14;
  return local_20;
}



/* VA 1000e1d2 */

void FUN_1000e1d2(void)

{
  ___acrt_unlock(8);
  return;
}



/* VA 1000e1db */

/* Library Function - Single Match
    ___acrt_stdio_free_buffer_nolock

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___acrt_stdio_free_buffer_nolock(undefined4 *param_1)

{
  uint *puVar1;

  puVar1 = param_1 + 3;
  if (((*puVar1 >> 0xd & 1) != 0) && ((*puVar1 >> 6 & 1) != 0)) {
    FUN_10009f36((LPVOID)param_1[1]);
    LOCK();
    *puVar1 = *puVar1 & 0xfffffebf;
    UNLOCK();
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = 0;
  }
  return;
}



/* VA 1000e21b */

byte __cdecl FUN_1000e21b(uint param_1)

{
  __acrt_ptd *p_Var1;

  if (param_1 == 0xfffffffe) {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_1001a378)) {
      return *(byte *)((&DAT_1001a178)[param_1 >> 6] + 0x28 + (param_1 & 0x3f) * 0x38) & 0x40;
    }
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 9;
    FUN_100080a4();
  }
  return 0;
}



/* VA 1000e271 */

/* Library Function - Single Match
    _fegetround

   Library: Visual Studio 2019 Release */

void __cdecl fegetround(void)

{
  uint uVar1;

  uVar1 = ___acrt_fenv_get_control();
  ___acrt_fenv_get_common_round_control(uVar1);
  return;
}



/* VA 1000e27e */

char FUN_1000e27e(char *param_1)

{
  char cVar1;

  if (*param_1 == '\0') {
    cVar1 = '\x01';
  }
  else if (param_1[1] == '\0') {
    cVar1 = '\x02';
  }
  else {
    cVar1 = (param_1[2] != '\0') + '\x03';
  }
  return cVar1;
}



/* VA 1000e2aa */

uint __cdecl FUN_1000e2aa(undefined2 *param_1,byte *param_2,uint param_3,uint *param_4,int param_5)

{
  uint uVar1;
  uint local_8;

  uVar1 = FUN_1000eaf2(&local_8,param_2,param_3,param_4,param_5);
  if (uVar1 < 5) {
    if (0xffff < local_8) {
      local_8 = 0xfffd;
    }
    if (param_1 != (undefined2 *)0x0) {
      *param_1 = (short)local_8;
    }
  }
  return uVar1;
}



/* VA 1000e2ed */

int __thiscall
FUN_1000e2ed(void *this,ushort *param_1,undefined4 *param_2,uint param_3,uint *param_4,int param_5)

{
  char cVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  void *pvVar3;
  ushort *puVar4;
  int iVar5;
  byte *pbVar6;
  void *local_c;
  void *pvStack_8;

  pbVar6 = (byte *)*param_2;
  local_c = this;
  pvStack_8 = this;
  puVar4 = param_1;
  if (param_1 == (ushort *)0x0) {
    iVar5 = 0;
    cVar1 = FUN_1000e27e((char *)pbVar6);
    uVar2 = CONCAT31(extraout_var_00,cVar1);
    while (uVar2 = FUN_1000eaf2((uint *)0x0,pbVar6,uVar2,param_4,param_5), uVar2 != 0xffffffff) {
      if (uVar2 == 0) {
        return iVar5;
      }
      if (uVar2 == 4) {
        iVar5 = iVar5 + 1;
      }
      pbVar6 = pbVar6 + uVar2;
      iVar5 = iVar5 + 1;
      cVar1 = FUN_1000e27e((char *)pbVar6);
      uVar2 = CONCAT31(extraout_var_01,cVar1);
    }
    *(undefined1 *)(param_5 + 0x1c) = 1;
    *(undefined4 *)(param_5 + 0x18) = 0x2a;
    iVar5 = -1;
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      cVar1 = FUN_1000e27e((char *)pbVar6);
      uVar2 = FUN_1000eaf2((uint *)&local_c,pbVar6,CONCAT31(extraout_var,cVar1),param_4,param_5);
      if (uVar2 == 0xffffffff) {
        *param_2 = pbVar6;
        *(undefined1 *)(param_5 + 0x1c) = 1;
        *(undefined4 *)(param_5 + 0x18) = 0x2a;
        return -1;
      }
      if (uVar2 == 0) {
        pbVar6 = (byte *)0x0;
        *puVar4 = 0;
        break;
      }
      pvVar3 = local_c;
      if ((void *)0xffff < local_c) {
        if (param_3 < 2) break;
        local_c = (void *)((int)local_c + -0x10000);
        param_3 = param_3 - 1;
        *puVar4 = (ushort)((uint)local_c >> 10) | 0xd800;
        puVar4 = puVar4 + 1;
        pvVar3 = (void *)((uint)local_c & 0x3ff | 0xdc00);
      }
      *puVar4 = (ushort)pvVar3;
      pbVar6 = pbVar6 + uVar2;
      puVar4 = puVar4 + 1;
    }
    iVar5 = (int)puVar4 - (int)param_1 >> 1;
    *param_2 = pbVar6;
  }
  return iVar5;
}



/* VA 1000e3f5 */

int __cdecl FUN_1000e3f5(ushort *param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;

  if (param_3 != 0) {
    do {
      uVar1 = (uint)*param_1;
      param_1 = param_1 + 1;
      if (uVar1 - 0x41 < 0x1a) {
        uVar1 = uVar1 + 0x20;
      }
      uVar2 = (uint)*param_2;
      param_2 = param_2 + 1;
      if (uVar2 - 0x41 < 0x1a) {
        uVar2 = uVar2 + 0x20;
      }
    } while (((uVar1 - uVar2 == 0) && (uVar1 != 0)) && (param_3 = param_3 + -1, param_3 != 0));
    return uVar1 - uVar2;
  }
  return 0;
}



/* VA 1000e444 */

/* Library Function - Single Match
    ___strncnt

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___strncnt(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;

  iVar2 = 0;
  cVar1 = *param_1;
  while ((cVar1 != '\0' && (iVar2 != param_2))) {
    iVar2 = iVar2 + 1;
    cVar1 = param_1[iVar2];
  }
  return;
}



/* VA 1000e460 */

undefined4 FUN_1000e460(void)

{
  return DAT_1001a3a4;
}



/* VA 1000e466 */

undefined8 __cdecl
FUN_1000e466(uint param_1,undefined4 param_2,undefined4 param_3,PLARGE_INTEGER param_4,int param_5)

{
  byte *pbVar1;
  LARGE_INTEGER liDistanceToMove;
  HANDLE hFile;
  BOOL BVar2;
  DWORD DVar3;
  DWORD unaff_EDI;
  uint local_c;
  uint local_8;

  hFile = (HANDLE)FUN_1000d4d8(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    *(undefined1 *)(param_5 + 0x1c) = 1;
    *(undefined4 *)(param_5 + 0x18) = 9;
  }
  else {
    liDistanceToMove.s.HighPart = (LONG)&local_c;
    liDistanceToMove.s.LowPart = param_3;
    BVar2 = SetFilePointerEx(hFile,liDistanceToMove,param_4,unaff_EDI);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      FUN_100095a4(DVar3,param_5);
    }
    else if ((local_c & local_8) != 0xffffffff) {
      pbVar1 = (byte *)((&DAT_1001a178)[(int)param_1 >> 6] + 0x28 + (param_1 & 0x3f) * 0x38);
      *pbVar1 = *pbVar1 & 0xfd;
      goto LAB_1000e4e5;
    }
  }
  local_c = 0xffffffff;
  local_8 = 0xffffffff;
LAB_1000e4e5:
  return CONCAT44(local_8,local_c);
}



/* VA 1000e4e9 */

undefined8 __cdecl
FUN_1000e4e9(uint param_1,undefined4 param_2,undefined4 param_3,PLARGE_INTEGER param_4,int param_5)

{
  undefined8 uVar1;

  uVar1 = FUN_1000e466(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}



/* VA 1000e507 */

/* Library Function - Single Match
    __putwch_nolock

   Library: Visual Studio 2019 Release */

wint_t __cdecl __putwch_nolock(wchar_t _WCh)

{
  bool bVar1;
  undefined3 extraout_var;
  BOOL BVar2;
  DWORD local_8;

  bVar1 = ___dcrt_lowio_ensure_console_output_initialized();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    BVar2 = ___dcrt_write_console(&_WCh,1,&local_8);
    if (BVar2 != 0) {
      return _WCh;
    }
  }
  return 0xffff;
}



/* VA 1000e539 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

undefined4 __cdecl FUN_1000e539(FILE *param_1,int *param_2)

{
  undefined4 uVar1;
  void *local_14;

  if (param_1 == (FILE *)0x0) {
    *(undefined1 *)(param_2 + 7) = 1;
    param_2[6] = 0x16;
    FUN_10008027((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_2);
  }
  else {
    if (((uint)param_1->_flag >> 0xc & 1) == 0) {
      __lock_file(param_1);
      uVar1 = FUN_1000e5d0(param_1,param_2);
      FUN_1000e5c8();
      ExceptionList = local_14;
      return uVar1;
    }
    __acrt_stdio_free_stream();
  }
  ExceptionList = local_14;
  return 0xffffffff;
}



/* VA 1000e5c8 */

void FUN_1000e5c8(void)

{
  FILE *unaff_ESI;

  __unlock_file(unaff_ESI);
  return;
}



/* VA 1000e5d0 */

undefined4 __cdecl FUN_1000e5d0(FILE *param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;

  if (param_1 == (FILE *)0x0) {
    *(undefined1 *)(param_2 + 7) = 1;
    param_2[6] = 0x16;
    FUN_10008027((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_2);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0xffffffff;
    if (((uint)param_1->_flag >> 0xd & 1) != 0) {
      uVar1 = FUN_1000be1c(param_1,param_2);
      ___acrt_stdio_free_buffer_nolock(&param_1->_ptr);
      uVar2 = __fileno(param_1);
      iVar3 = FUN_1000ee4c(uVar2,param_2);
      if (iVar3 < 0) {
        uVar1 = 0xffffffff;
      }
      else if (param_1->_tmpfname != (char *)0x0) {
        FUN_10009f36(param_1->_tmpfname);
        param_1->_tmpfname = (char *)0x0;
      }
    }
    __acrt_stdio_free_stream(param_1);
  }
  return uVar1;
}



/* VA 1000e65e */

undefined4 __cdecl FUN_1000e65e(FILE *param_1)

{
  undefined4 uVar1;
  int local_2c [10];

  FUN_10007d98(local_2c,(undefined4 *)0x0);
  uVar1 = FUN_1000e539(param_1,local_2c);
  FUN_10007de0(local_2c);
  return uVar1;
}



/* VA 1000e8bd */

uint __cdecl FUN_1000e8bd(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;

  uVar4 = 0;
  uVar1 = (ushort)param_1 & 0x8040;
  if (uVar1 == 0x8000) {
    uVar3 = 0xc00;
  }
  else if (uVar1 == 0x40) {
    uVar3 = 0x800;
  }
  else {
    uVar3 = 0x400;
    if (uVar1 != 0x8040) {
      uVar3 = 0;
    }
  }
  uVar2 = param_1 & 0x6000;
  if (uVar2 != 0) {
    if (uVar2 == 0x2000) {
      uVar4 = 0x100;
    }
    else if (uVar2 == 0x4000) {
      uVar4 = 0x200;
    }
    else if (uVar2 == 0x6000) {
      uVar4 = 0x300;
    }
  }
  return (((param_1 & 0x400 | (param_1 >> 2 & 0x400 | param_1 & 0x800) >> 2) >> 2 | param_1 & 0x200)
          >> 3 | param_1 & 0x180) >> 3 | uVar3 | uVar4;
}



/* VA 1000e96d */

uint __cdecl FUN_1000e96d(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_8;

  local_8 = 0x1000;
  uVar2 = 0;
  if ((param_1 & 0x300) == 0) {
    local_8 = 0x2000;
  }
  else if ((param_1 & 0x300) != 0x200) {
    local_8 = 0;
  }
  uVar1 = param_1 & 0xc00;
  if (uVar1 != 0) {
    if (uVar1 == 0x400) {
      uVar2 = 0x100;
    }
    else if (uVar1 == 0x800) {
      uVar2 = 0x200;
    }
    else if (uVar1 == 0xc00) {
      uVar2 = 0x300;
    }
  }
  return (param_1 & 4 | (param_1 & 2) << 3) * 2 |
         ((param_1 >> 2 & 8 | param_1 & 0x10) >> 2 | param_1 & 8) >> 1 | (param_1 & 1) << 4 |
         (param_1 & 0x1000) << 2 | local_8 | uVar2;
}



/* VA 1000ea1a */

/* Library Function - Single Match
    ___acrt_fenv_get_common_round_control

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint __cdecl ___acrt_fenv_get_common_round_control(uint param_1)

{
  uint uVar1;

  uVar1 = param_1 >> 0xe & 0x300;
  if (uVar1 != (param_1 >> 0x16 & 0x300)) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* VA 1000ea3c */

/* Library Function - Single Match
    ___acrt_fenv_get_control

   Library: Visual Studio 2019 Release */

uint ___acrt_fenv_get_control(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  ushort in_FPUControlWord;
  ushort local_24 [14];
  uint local_8;

  puVar4 = local_24;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar4[0] = 0;
    puVar4[1] = 0;
    puVar4 = puVar4 + 2;
  }
  local_24[0] = in_FPUControlWord;
  uVar1 = FUN_1000e96d(in_FPUControlWord & 7999);
  if (DAT_100199c8 < 1) {
    uVar3 = 0;
  }
  else {
    local_8 = MXCSR;
    uVar3 = MXCSR & 0xffc0;
  }
  uVar3 = FUN_1000e8bd(uVar3);
  return uVar3 | ((((uVar3 & 0x3f) << 2 | uVar3 & 0xffffff00) << 6 | uVar1 & 0x3f) << 2 |
                 uVar1 & 0x300) << 0xe | uVar1;
}



/* VA 1000eabc */

undefined4 __cdecl FUN_1000eabc(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  param_2[1] = 0;
  return param_1;
}



/* VA 1000ead0 */

undefined4 __cdecl FUN_1000ead0(undefined4 *param_1,int param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_2 + 0x1c) = 1;
  *(undefined4 *)(param_2 + 0x18) = 0x2a;
  return 0xffffffff;
}



/* VA 1000eaf2 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint __cdecl FUN_1000eaf2(uint *param_1,byte *param_2,uint param_3,uint *param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  byte bVar5;
  byte *pbVar6;
  uint *local_1c;
  byte local_16;
  byte local_15;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_8 = DAT_10019008 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  if (param_4 == (uint *)0x0) {
    param_4 = &DAT_1001a3a8;
  }
  if (param_2 == (byte *)0x0) {
    param_3 = 1;
    local_1c = (uint *)0x0;
    pbVar6 = &DAT_1001168e;
LAB_1000eb51:
    if (*(short *)((int)param_4 + 6) == 0) {
      bVar5 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      if (-1 < (char)bVar5) {
        if (local_1c != (uint *)0x0) {
          *local_1c = (uint)bVar5;
        }
        return (uint)(bVar5 != 0);
      }
      if ((bVar5 & 0xe0) == 0xc0) {
        uVar3 = (uint)CONCAT11(2,bVar5);
      }
      else if ((bVar5 & 0xf0) == 0xe0) {
        uVar3 = (uint)CONCAT11(3,bVar5);
      }
      else {
        if ((bVar5 & 0xf8) != 0xf0) goto LAB_1000ec8c;
        uVar3 = (uint)CONCAT11(4,bVar5);
      }
      local_15 = (byte)(uVar3 >> 8);
      puVar4 = (uint *)((1 << (7 - local_15 & 0x1f)) - 1U & uVar3 & 0xff);
      uVar3 = CONCAT31((int3)(uVar3 >> 8),local_15);
LAB_1000ebdb:
      uVar1 = uVar3 & 0xff;
      if (uVar1 < param_3) {
        param_3 = uVar1;
      }
      uVar2 = (int)pbVar6 - (int)param_2;
      while (uVar2 < param_3) {
        local_16 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        uVar2 = uVar2 + 1;
        uVar3 = CONCAT31((int3)(uVar3 >> 8),local_15);
        if ((local_16 & 0xc0) != 0x80) goto LAB_1000ec8c;
        puVar4 = (uint *)((int)puVar4 << 6 | local_16 & 0x3f);
      }
      bVar5 = (byte)(uVar3 >> 8);
      if (param_3 < uVar1) {
        *(ushort *)(param_4 + 1) = (ushort)bVar5;
        *param_4 = (uint)puVar4;
        *(ushort *)((int)param_4 + 6) = (ushort)(byte)((char)uVar3 - (char)param_3);
        goto LAB_1000eb46;
      }
      if (((puVar4 < (uint *)0xd800) || ((uint *)0xdfff < puVar4)) && (puVar4 < (uint *)0x110000)) {
        local_14 = 0x80;
        local_10 = 0x800;
        local_c = 0x10000;
        if ((&local_1c)[bVar5] <= puVar4) {
          if (local_1c != (uint *)0x0) {
            *local_1c = (uint)puVar4;
          }
          uVar3 = FUN_1000eabc(-(uint)(puVar4 != (uint *)0x0) & uVar1,param_4);
          return uVar3;
        }
      }
    }
    else {
      bVar5 = (byte)param_4[1];
      local_15 = *(byte *)((int)param_4 + 6);
      uVar3 = (uint)CONCAT11(bVar5,local_15);
      puVar4 = (uint *)*param_4;
      if ((((byte)(bVar5 - 2) < 3) && (local_15 != 0)) && (local_15 < bVar5)) goto LAB_1000ebdb;
    }
LAB_1000ec8c:
    uVar3 = FUN_1000ead0(param_4,param_5);
  }
  else {
    pbVar6 = param_2;
    if (param_3 != 0) goto LAB_1000eb51;
LAB_1000eb46:
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}



/* VA 1000ecb0 */

/* Library Function - Single Match
    ___ascii_strnicmp

   Library: Visual Studio */

int __cdecl ___ascii_strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;

  iVar5 = 0;
  if (_MaxCount != 0) {
    do {
      bVar2 = *_Str1;
      cVar1 = *_Str2;
      uVar3 = CONCAT11(bVar2,cVar1);
      if (bVar2 == 0) break;
      uVar3 = CONCAT11(bVar2,cVar1);
      uVar4 = (uint)uVar3;
      if (cVar1 == '\0') break;
      _Str1 = _Str1 + 1;
      _Str2 = _Str2 + 1;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar4 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
      }
      uVar3 = (ushort)uVar4;
      bVar2 = (byte)uVar4;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar3 = (ushort)CONCAT31((int3)(uVar4 >> 8),bVar2 + 0x20);
      }
      bVar2 = (byte)(uVar3 >> 8);
      bVar6 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) goto LAB_1000ed01;
      _MaxCount = _MaxCount - 1;
    } while (_MaxCount != 0);
    iVar5 = 0;
    bVar2 = (byte)(uVar3 >> 8);
    bVar6 = bVar2 < (byte)uVar3;
    if (bVar2 != (byte)uVar3) {
LAB_1000ed01:
      iVar5 = -1;
      if (!bVar6) {
        iVar5 = 1;
      }
    }
  }
  return iVar5;
}



/* VA 1000ed11 */

/* Library Function - Single Match
    void __cdecl __dcrt_lowio_initialize_console_output(void)

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __cdecl __dcrt_lowio_initialize_console_output(void)

{
  DAT_10019840 = CreateFileW(L"CONOUT$",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  return;
}



/* VA 1000ed30 */

/* Library Function - Single Match
    ___dcrt_lowio_ensure_console_output_initialized

   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

bool ___dcrt_lowio_ensure_console_output_initialized(void)

{
  if (DAT_10019840 == -2) {
    __dcrt_lowio_initialize_console_output();
  }
  return DAT_10019840 != -1;
}



/* VA 1000ed4f */

/* Library Function - Multiple Matches With Different Base Names
    ___dcrt_terminate_console_input
    ___dcrt_terminate_console_output

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void FID_conflict____dcrt_terminate_console_output(void)

{
  if ((DAT_10019840 != (HANDLE)0xffffffff) && (DAT_10019840 != (HANDLE)0xfffffffe)) {
    CloseHandle(DAT_10019840);
  }
  return;
}



/* VA 1000ed66 */

/* Library Function - Single Match
    ___dcrt_write_console

   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

BOOL __cdecl ___dcrt_write_console(void *param_1,DWORD param_2,LPDWORD param_3)

{
  BOOL BVar1;
  DWORD DVar2;

  BVar1 = WriteConsoleW(DAT_10019840,param_1,param_2,param_3,(LPVOID)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 == 6) {
      FID_conflict____dcrt_terminate_console_output();
      __dcrt_lowio_initialize_console_output();
      BVar1 = WriteConsoleW(DAT_10019840,param_1,param_2,param_3,(LPVOID)0x0);
    }
  }
  return BVar1;
}



/* VA 1000edbb */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */

undefined4 FUN_1000edbb(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_14;

  FUN_1000d401(*param_1);
  uVar1 = *(uint *)*param_2;
  iVar2 = param_2[1];
  if ((*(byte *)((&DAT_1001a178)[(int)uVar1 >> 6] + 0x28 + (uVar1 & 0x3f) * 0x38) & 1) == 0) {
    *(undefined1 *)(iVar2 + 0x1c) = 1;
    *(undefined4 *)(iVar2 + 0x18) = 9;
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = FUN_1000eeef(uVar1,iVar2);
  }
  FUN_1000ee40();
  ExceptionList = local_14;
  return uVar3;
}



/* VA 1000ee40 */

void FUN_1000ee40(void)

{
  int unaff_EBP;

  ___acrt_lowio_unlock_fh(**(uint **)(unaff_EBP + 0x10));
  return;
}



/* VA 1000ee4c */

undefined4 __cdecl FUN_1000ee4c(uint param_1,int *param_2)

{
  undefined4 uVar1;
  uint *local_18;
  int *local_14;
  uint local_10;
  uint local_c;

  if (param_1 == 0xfffffffe) {
    param_2[8] = 0;
    *(undefined1 *)(param_2 + 9) = 1;
    *(undefined1 *)(param_2 + 7) = 1;
    param_2[6] = 9;
  }
  else {
    if (((-1 < (int)param_1) && (param_1 < DAT_1001a378)) &&
       ((*(byte *)((&DAT_1001a178)[(int)param_1 >> 6] + 0x28 + (param_1 & 0x3f) * 0x38) & 1) != 0))
    {
      local_18 = &param_1;
      local_c = param_1;
      local_14 = param_2;
      local_10 = param_1;
      uVar1 = FUN_1000edbb(&local_10,&local_18);
      return uVar1;
    }
    *(undefined1 *)(param_2 + 9) = 1;
    param_2[8] = 0;
    *(undefined1 *)(param_2 + 7) = 1;
    param_2[6] = 9;
    FUN_10008027((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0,param_2);
  }
  return 0xffffffff;
}



/* VA 1000eeef */

undefined4 __cdecl FUN_1000eeef(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  undefined4 uVar4;
  DWORD DVar5;

  iVar1 = FUN_1000d4d8(param_1);
  if (iVar1 != -1) {
    if (((param_1 == 1) && ((*(byte *)(DAT_1001a178 + 0x98) & 1) != 0)) ||
       ((param_1 == 2 && ((*(byte *)(DAT_1001a178 + 0x60) & 1) != 0)))) {
      iVar1 = FUN_1000d4d8(2);
      iVar2 = FUN_1000d4d8(1);
      if (iVar2 == iVar1) goto LAB_1000ef05;
    }
    hObject = (HANDLE)FUN_1000d4d8(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar5 = GetLastError();
      goto LAB_1000ef57;
    }
  }
LAB_1000ef05:
  DVar5 = 0;
LAB_1000ef57:
  FUN_1000d447(param_1);
  *(undefined1 *)((&DAT_1001a178)[(int)param_1 >> 6] + 0x28 + (param_1 & 0x3f) * 0x38) = 0;
  if (DVar5 == 0) {
    uVar4 = 0;
  }
  else {
    FUN_100095a4(DVar5,param_2);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



/* VA 1000ef8f */

/* Library Function - Single Match
    void __cdecl __acrt_stdio_free_stream(class __crt_stdio_stream)

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl __acrt_stdio_free_stream(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  LOCK();
  param_1[3] = 0;
  UNLOCK();
  return;
}



/* VA 1000efe0 */

void FUN_1000efe0(void)

{
  float10 in_ST0;

  FUN_1000effe((double)in_ST0);
  return;
}



/* VA 1000effe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_1000effe(double param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  undefined1 in_XMM0 [16];
  double dVar8;
  double dVar9;
  double dVar10;
  double local_c;

  iVar4 = 0;
  while( true ) {
    uVar2 = (uint)(ushort)(in_XMM0._6_2_ >> 4);
    dVar6 = (double)(in_XMM0._0_8_ & (ulonglong)_DAT_10015160 | (ulonglong)DAT_100151d0);
    dVar7 = (double)(in_XMM0._0_8_ & _UNK_10015168 | _UNK_100151d8);
    uVar1 = SUB82(_DAT_10015180 + dVar6,0) & 0x7f0;
    dVar10 = (double)(_UNK_10015198 & (ulonglong)dVar7);
    dVar9 = (double)(_DAT_10015190 & (ulonglong)dVar6) * *(double *)(&DAT_100157a0 + uVar1) -
            _DAT_10015170;
    dVar6 = (dVar6 - (double)(_DAT_10015190 & (ulonglong)dVar6)) *
            *(double *)(&DAT_100157a0 + uVar1);
    dVar8 = (dVar7 - dVar10) * *(double *)(&UNK_100157a8 + uVar1);
    dVar7 = dVar6 + dVar9;
    in_XMM0._8_8_ = dVar8 + (dVar10 * *(double *)(&UNK_100157a8 + uVar1) - _UNK_10015178);
    uVar3 = uVar2 - 1;
    if (uVar3 < 0x7fe) {
      iVar4 = (uVar2 - 0x3ff) + iVar4;
      dVar10 = (double)iVar4;
      iVar5 = 0;
      if (uVar1 + iVar4 * 0x400 == 0) {
        iVar5 = 0x10;
      }
      return (float10)(((_UNK_10015228 * in_XMM0._8_8_ + _UNK_10015238) * in_XMM0._8_8_ +
                       _UNK_10015248) * in_XMM0._8_8_ * in_XMM0._8_8_ +
                       ((_DAT_10015220 * dVar7 + _DAT_10015230) * dVar7 + _DAT_10015240) *
                       dVar7 * dVar7 * dVar7 * dVar7 * dVar7 + _DAT_10015250 * dVar7 +
                       *(double *)(&UNK_10015398 + uVar1) + dVar10 * _UNK_100151a8 +
                       (double)((ulonglong)dVar8 & *(ulonglong *)(&UNK_100151b8 + iVar5)) +
                      *(double *)(&DAT_10015390 + uVar1) + dVar9 + dVar10 * _DAT_100151a0 +
                      (double)((ulonglong)dVar6 & *(ulonglong *)(&DAT_100151b0 + iVar5)));
    }
    local_c = (double)-(ulonglong)(_DAT_100151e0 == param_1);
    if (SUB82(local_c,0) != 0) break;
    if (uVar3 != 0xffffffff) {
      if (uVar3 < 0x7ff) {
        if (DAT_100151d0 ==
            (double)((ulonglong)param_1 & (ulonglong)_DAT_10015160 | (ulonglong)DAT_100151d0)) {
          return (float10)_DAT_10015208;
        }
        iVar4 = 0x3e9;
        local_c = _DAT_10015160;
      }
      else if (((uVar2 & 0x7ff) < 0x7ff) ||
              (SUB84(param_1,0) == 0 && ((ulonglong)param_1 & 0xfffff00000000) == 0)) {
        local_c = -NAN;
        iVar4 = 9;
      }
      else {
        iVar4 = 0x3e9;
      }
      goto LAB_1000f20a;
    }
    in_XMM0._0_8_ = param_1 * DAT_100151f0;
    iVar4 = -0x34;
  }
  iVar4 = 8;
  local_c = DAT_10015200;
LAB_1000f20a:
  ___libm_error_support(&param_1,&param_1,&local_c,iVar4);
  return (float10)local_c;
}



/* VA 1000f870 */

float10 __fastcall
FUN_1000f870(undefined4 param_1,int param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float10 in_ST0;
  int local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  undefined4 local_10;
  double dStack_c;

  local_14 = param_7;
  local_10 = param_8;
  dStack_c = (double)in_ST0;
  uStack_1c = param_5;
  uStack_18 = param_6;
  uStack_20 = param_1;
  FUN_1000fdac(param_2,&local_24,&param_3);
  return (float10)dStack_c;
}



/* VA 1000f887 */

/* Library Function - Single Match
    __startOneArgErrorHandling

   Library: Visual Studio */

float10 __fastcall
__startOneArgErrorHandling
          (undefined4 param_1,int param_2,ushort param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  float10 in_ST0;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  double local_c;

  local_c = (double)in_ST0;
  local_1c = param_5;
  local_18 = param_6;
  local_20 = param_1;
  FUN_1000fdac(param_2,&local_24,&param_3);
  return (float10)local_c;
}



/* VA 1000f8c3 */

/* Library Function - Single Match
    ___libm_error_support

   Library: Visual Studio 2019 Release */

void __cdecl
___libm_error_support(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,int param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  __acrt_ptd *p_Var4;
  undefined4 local_24;
  char *local_20;
  undefined8 local_1c;
  undefined8 local_14;
  undefined8 local_c;

  if (DAT_1001a3b4 == 0) {
    pcVar2 = FUN_1000bc0d;
  }
  else {
    pcVar2 = DecodePointer(DAT_1001a40c);
  }
  if (0x1a < param_4) {
    if (param_4 != 0x1b) {
      if (param_4 == 0x1c) {
        local_20 = "pow";
      }
      else if (param_4 == 0x31) {
        local_20 = "sqrt";
      }
      else if (param_4 == 0x3a) {
        local_20 = "acos";
      }
      else {
        if (param_4 != 0x3d) {
          if ((param_4 != 1000) && (param_4 != 0x3e9)) {
            return;
          }
          uVar1 = *param_1;
          goto LAB_1000f9cb;
        }
        local_20 = "asin";
      }
      goto LAB_1000fa2b;
    }
    local_24 = 2;
LAB_1000fa71:
    local_20 = "pow";
    goto LAB_1000fa78;
  }
  if (param_4 == 0x1a) {
    uVar1 = 0x3ff0000000000000;
LAB_1000f9cb:
    *param_3 = uVar1;
    return;
  }
  if (0xe < param_4) {
    if (param_4 == 0xf) {
      local_20 = "exp";
    }
    else {
      if (param_4 == 0x18) {
        local_24 = 3;
        goto LAB_1000fa71;
      }
      if (param_4 != 0x19) {
        return;
      }
      local_20 = "pow";
    }
    local_24 = 4;
    local_1c = *param_1;
    local_14 = *param_2;
    local_c = *param_3;
    (*(code *)PTR_guard_check_icall_1001116c)(&local_24);
    (*pcVar2)();
    goto LAB_1000faae;
  }
  if (param_4 == 0xe) {
    local_24 = 3;
    local_20 = "exp";
  }
  else {
    if (param_4 != 2) {
      if (param_4 == 3) {
        local_20 = "log";
      }
      else {
        if (param_4 == 8) {
          local_24 = 2;
          local_20 = "log10";
          goto LAB_1000fa78;
        }
        if (param_4 != 9) {
          return;
        }
        local_20 = "log10";
      }
LAB_1000fa2b:
      local_24 = 1;
      local_1c = *param_1;
      local_14 = *param_2;
      local_c = *param_3;
      (*(code *)PTR_guard_check_icall_1001116c)(&local_24);
      iVar3 = (*pcVar2)();
      if (iVar3 == 0) {
        p_Var4 = FUN_100095db();
        *(undefined4 *)p_Var4 = 0x21;
      }
      goto LAB_1000faae;
    }
    local_24 = 2;
    local_20 = "log";
  }
LAB_1000fa78:
  local_1c = *param_1;
  local_14 = *param_2;
  local_c = *param_3;
  (*(code *)PTR_guard_check_icall_1001116c)(&local_24);
  iVar3 = (*pcVar2)();
  if (iVar3 == 0) {
    p_Var4 = FUN_100095db();
    *(undefined4 *)p_Var4 = 0x22;
  }
LAB_1000faae:
  *param_3 = local_c;
  return;
}



/* VA 1000fab7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_1000fab7(double param_1)

{
  double dVar1;
  byte bVar2;
  uint uVar3;
  undefined3 extraout_var;
  float10 fVar5;
  uint uVar6;
  int iVar4;

  uVar3 = __ctrlfp();
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    bVar2 = FUN_10010736(SUB84(param_1,0),(uint)((ulonglong)param_1 >> 0x20));
    iVar4 = CONCAT31(extraout_var,bVar2);
    if (((iVar4 == 1) || (iVar4 == 2)) || (iVar4 == 3)) {
      __ctrlfp();
      dVar1 = param_1;
LAB_1000fb6f:
      return (float10)dVar1;
    }
    dVar1 = _DAT_10015370 + param_1;
    uVar6 = 8;
  }
  else {
    fVar5 = __frnd(param_1);
    dVar1 = (double)fVar5;
    if (((float10)param_1 == fVar5) || ((uVar3 & 0x20) != 0)) {
      __ctrlfp();
      goto LAB_1000fb6f;
    }
    dVar1 = (double)fVar5;
    uVar6 = 0x10;
  }
  fVar5 = __except1(uVar6,0xc,param_1,dVar1,uVar3);
  return fVar5;
}



/* VA 1000fb75 */

int FUN_1000fb75(void)

{
  short in_FPUStatusWord;

  return (int)in_FPUStatusWord;
}



/* VA 1000fb86 */

/* Library Function - Single Match
    __ctrlfp

   Library: Visual Studio 2019 Release */

int __ctrlfp(void)

{
  short in_FPUControlWord;

  return (int)in_FPUControlWord;
}



/* VA 1000fbb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fbb0(void)

{
  return;
}



/* VA 1000fc09 */

int FUN_1000fc09(void)

{
  short in_FPUStatusWord;

  return (int)in_FPUStatusWord;
}



/* VA 1000fc19 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000fc19(double param_1)

{
  uint uVar1;
  float10 fVar2;
  float10 fVar3;

  uVar1 = __fpclass(param_1);
  if ((uVar1 & 0x90) == 0) {
    fVar2 = __frnd(param_1);
    if ((float10)param_1 == fVar2) {
      fVar2 = (float10)param_1 * (float10)_DAT_10015bb0;
      fVar3 = __frnd((double)fVar2);
      if ((float10)(double)fVar2 != fVar3) {
        return 1;
      }
      return 2;
    }
  }
  return 0;
}



/* VA 1000fc81 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000fc81(int param_1,int param_2,int param_3,int param_4,undefined8 *param_5)

{
  double dVar1;
  double dVar2;
  int iVar3;

  dVar1 = ABS((double)CONCAT44(param_2,param_1));
  dVar2 = _DAT_10015d40;
  if (param_4 == 0x7ff00000) {
    if (param_3 == 0) {
      if ((dVar1 <= 1.0) && (dVar2 = 1.0, dVar1 < 1.0)) {
        dVar2 = 0.0;
      }
      goto LAB_1000fda6;
    }
  }
  else if ((param_4 == -0x100000) && (param_3 == 0)) {
    if (dVar1 <= 1.0) {
      dVar2 = 1.0;
      if (dVar1 < 1.0) {
        dVar2 = _DAT_10015d40;
      }
    }
    else {
      dVar2 = 0.0;
    }
    goto LAB_1000fda6;
  }
  if (param_2 == 0x7ff00000) {
    if (param_1 != 0) {
      return 0;
    }
    if (((double)CONCAT44(param_4,param_3) <= 0.0) &&
       (dVar2 = 0.0, 0.0 <= (double)CONCAT44(param_4,param_3))) {
      dVar2 = 1.0;
    }
  }
  else {
    if (param_2 != -0x100000) {
      return 0;
    }
    if (param_1 != 0) {
      return 0;
    }
    iVar3 = FUN_1000fc19((double)CONCAT44(param_4,param_3));
    if ((double)CONCAT44(param_4,param_3) <= 0.0) {
      if (0.0 <= (double)CONCAT44(param_4,param_3)) {
        dVar2 = 1.0;
      }
      else {
        dVar2 = 0.0;
        if (iVar3 == 1) {
          dVar2 = _DAT_10015d50;
        }
      }
    }
    else {
      dVar2 = _DAT_10015d40;
      if (iVar3 == 1) {
        dVar2 = -_DAT_10015d40;
      }
    }
  }
LAB_1000fda6:
  *param_5 = dVar2;
  return 0;
}



/* VA 1000fdac */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl FUN_1000fdac(int param_1,int *param_2,ushort *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  uint local_94;
  uint local_90 [12];
  undefined8 local_60;
  uint local_50;
  uint local_14;

  local_14 = DAT_10019008 ^ (uint)&stack0xfffffff0;
  local_94 = (uint)*param_3;
  iVar2 = *param_2;
  if (iVar2 == 1) {
LAB_1000fe1a:
    uVar3 = 8;
  }
  else if (iVar2 == 2) {
    uVar3 = 4;
  }
  else if (iVar2 == 3) {
    uVar3 = 0x11;
  }
  else if (iVar2 == 4) {
    uVar3 = 0x12;
  }
  else {
    if (iVar2 == 5) goto LAB_1000fe1a;
    if ((iVar2 == 7) || (iVar2 != 8)) goto LAB_1000fe76;
    uVar3 = 0x10;
  }
  bVar1 = FUN_1000ffd2(uVar3,(double *)(param_2 + 6),local_94);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_60 = *(undefined8 *)(param_2 + 4);
      local_50 = local_50 & 0xffffffe3 | 3;
    }
    else {
      local_50 = local_50 & 0xfffffffe;
    }
    __raise_exc(local_90,&local_94,uVar3,param_1,(uint *)(param_2 + 2),(uint *)(param_2 + 6));
  }
LAB_1000fe76:
  __ctrlfp();
  if (((*param_2 != 8) && (bVar1 = FUN_1000bbe1(), bVar1)) &&
     (iVar2 = FUN_1000bc0d(param_2), iVar2 != 0)) {
    return;
  }
  FUN_10010566(*param_2);
  return;
}



/* VA 1000febc */

/* Library Function - Single Match
    __frnd

   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2019 Release */

float10 __cdecl __frnd(double param_1)

{
  return (float10)ROUND(param_1);
}



/* VA 1000fed0 */

/* Library Function - Single Match
    __errcode

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl __errcode(uint param_1)

{
  undefined4 uStack_8;

  if ((param_1 & 0x20) == 0) {
    if ((param_1 & 8) != 0) {
      return 1;
    }
    if ((param_1 & 4) == 0) {
      if ((param_1 & 1) == 0) {
        return (param_1 & 2) * 2;
      }
      uStack_8 = 3;
    }
    else {
      uStack_8 = 2;
    }
  }
  else {
    uStack_8 = 5;
  }
  return uStack_8;
}



/* VA 1000ff04 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    __except1

   Library: Visual Studio 2015 Release */

float10 __cdecl __except1(uint param_1,int param_2,undefined8 param_3,double param_4,uint param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  float10 fVar3;
  uint local_90 [16];
  uint local_50;
  uint local_14;

  local_14 = DAT_10019008 ^ (uint)&stack0xfffffff0;
  bVar1 = FUN_1000ffd2(param_1,&param_4,param_5);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    local_50 = local_50 & 0xfffffffe;
    __raise_exc_ex(local_90,&param_5,param_1,param_2,(uint *)&param_3,(uint *)&param_4,0);
  }
  iVar2 = __errcode(param_1);
  bVar1 = FUN_1000bbe1();
  if ((bVar1) && (iVar2 != 0)) {
    fVar3 = FUN_10010597(iVar2,param_2,(int)param_3,(int)((ulonglong)param_3 >> 0x20),0,0,
                         SUB84(param_4,0),(int)((ulonglong)param_4 >> 0x20));
  }
  else {
    FUN_10010566(iVar2);
    __ctrlfp();
    fVar3 = (float10)param_4;
  }
  return fVar3;
}



/* VA 1000ffd2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl FUN_1000ffd2(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  double dVar2;
  byte bVar3;
  bool bVar4;
  double dVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float10 fVar9;
  uint local_24;
  byte bStack_20;
  undefined1 uStack_1f;
  ushort uStack_1e;
  int local_18;
  double local_14;
  uint local_c;
  bool local_7;
  char local_6;
  byte local_5;

  uVar8 = param_1 & 0x1f;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_1000fbb0();
    uVar8 = param_1 & 0x17;
    goto LAB_10010231;
  }
  if ((param_1 & param_3 & 4) != 0) {
    FUN_1000fbb0();
    uVar8 = param_1 & 0x1b;
    goto LAB_10010231;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) == 0) || ((param_3 & 0x10) == 0)) goto LAB_10010231;
    dVar2 = *param_2;
    uVar8 = param_1 >> 4 & 1;
    local_c = uVar8;
    if (dVar2 == 0.0) {
LAB_10010225:
      FUN_1000fbb0();
    }
    else {
      fVar9 = (float10)FUN_10010637(SUB84(dVar2,0),(uint)((ulonglong)dVar2 >> 0x20),&local_18);
      local_18 = local_18 + -0x600;
      dVar2 = (double)fVar9;
      local_24 = SUB84(dVar2,0);
      bStack_20 = (byte)((ulonglong)dVar2 >> 0x20);
      uStack_1f = (undefined1)((ulonglong)dVar2 >> 0x28);
      uStack_1e = (ushort)((ulonglong)dVar2 >> 0x30);
      if (local_18 < -0x432) {
        fVar9 = (float10)0 * fVar9;
        uVar8 = 1;
      }
      else {
        local_5 = fVar9 < (float10)0;
        uStack_1e = uStack_1e & 0xf | 0x10;
        bVar4 = false;
        local_7 = false;
        local_6 = '\0';
        if (local_18 < -0x3fd) {
          local_18 = -0x3fd - local_18;
          local_6 = '\0';
          do {
            uVar7 = local_24 & 1;
            if ((uVar7 != 0) && (uVar8 == 0)) {
              uVar8 = 1;
            }
            if (local_6 != '\0') {
              bVar4 = true;
            }
            local_24 = local_24 >> 1;
            local_6 = (char)uVar7;
            if ((bStack_20 & 1) != 0) {
              local_24 = local_24 | 0x80000000;
            }
            uVar7 = CONCAT22(uStack_1e,CONCAT11(uStack_1f,bStack_20)) >> 1;
            bStack_20 = (byte)uVar7;
            uStack_1f = (undefined1)(uVar7 >> 8);
            uStack_1e = uStack_1e >> 1;
            local_18 = local_18 + -1;
            local_c = uVar8;
            local_7 = bVar4;
          } while (local_18 != 0);
        }
        local_14 = (double)CONCAT26(uStack_1e,CONCAT15(uStack_1f,CONCAT14(bStack_20,local_24)));
        fVar9 = (float10)local_14;
        if ((bool)local_5) {
          fVar9 = -fVar9;
          local_14 = (double)fVar9;
          dVar2 = (double)fVar9;
          local_24 = SUB84(dVar2,0);
          bStack_20 = (byte)((ulonglong)dVar2 >> 0x20);
          uStack_1f = (undefined1)((ulonglong)dVar2 >> 0x28);
          uStack_1e = (ushort)((ulonglong)dVar2 >> 0x30);
        }
        if ((local_6 != '\0') || (uVar8 = local_c, local_7)) {
          iVar6 = fegetround();
          uVar8 = local_c;
          if (iVar6 == 0) {
            if (local_6 == '\0') goto LAB_10010212;
            if (local_7 == false) {
              bVar3 = (byte)local_24 & 1;
              goto LAB_10010201;
            }
          }
          else {
            bVar3 = local_5;
            if (iVar6 != 0x100) {
              if (iVar6 != 0x200) goto LAB_10010212;
              bVar3 = local_5 ^ 1;
            }
LAB_10010201:
            if (bVar3 == 0) {
LAB_10010212:
              fVar9 = (float10)local_14;
              goto LAB_10010218;
            }
          }
          iVar6 = CONCAT22(uStack_1e,CONCAT11(uStack_1f,bStack_20)) + (uint)(0xfffffffe < local_24);
          bStack_20 = (byte)iVar6;
          uStack_1f = (undefined1)((uint)iVar6 >> 8);
          uStack_1e = (ushort)((uint)iVar6 >> 0x10);
          fVar9 = (float10)(double)CONCAT26(uStack_1e,
                                            CONCAT15(uStack_1f,CONCAT14(bStack_20,local_24 + 1)));
        }
      }
LAB_10010218:
      *param_2 = (double)fVar9;
      if (uVar8 != 0) goto LAB_10010225;
    }
    uVar8 = param_1 & 0x1d;
    goto LAB_10010231;
  }
  FUN_1000fbb0();
  uVar8 = param_3 & 0xc00;
  dVar2 = _DAT_10015d40;
  dVar5 = _DAT_10015d40;
  if (uVar8 == 0) {
    dVar1 = *param_2;
joined_r0x10010073:
    if (dVar1 <= 0.0) {
      dVar2 = -dVar5;
    }
    *param_2 = dVar2;
  }
  else {
    if (uVar8 == 0x400) {
      dVar1 = *param_2;
      dVar2 = _DAT_10015d48;
      goto joined_r0x10010073;
    }
    dVar5 = _DAT_10015d48;
    if (uVar8 == 0x800) {
      dVar1 = *param_2;
      goto joined_r0x10010073;
    }
    if (uVar8 == 0xc00) {
      dVar1 = *param_2;
      dVar2 = _DAT_10015d48;
      goto joined_r0x10010073;
    }
  }
  uVar8 = param_1 & 0x1e;
LAB_10010231:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_1000fbb0();
    uVar8 = uVar8 & 0xffffffef;
  }
  return uVar8 == 0;
}



/* VA 10010252 */

/* Library Function - Single Match
    __raise_exc

   Library: Visual Studio 2015 Release */

void __cdecl
__raise_exc(uint *param_1,uint *param_2,uint param_3,int param_4,uint *param_5,uint *param_6)

{
  __raise_exc_ex(param_1,param_2,param_3,param_4,param_5,param_6,0);
  return;
}



/* VA 10010275 */

/* Library Function - Single Match
    __raise_exc_ex

   Library: Visual Studio 2015 Release */

void __cdecl
__raise_exc_ex(uint *param_1,uint *param_2,uint param_3,int param_4,uint *param_5,uint *param_6,
              int param_7)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  DWORD dwExceptionCode;

  puVar1 = param_2;
  param_1[1] = 0;
  dwExceptionCode = 0xc000000d;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 & 0x10) != 0) {
    dwExceptionCode = 0xc000008f;
    param_1[1] = param_1[1] | 1;
  }
  if ((param_3 & 2) != 0) {
    dwExceptionCode = 0xc0000093;
    param_1[1] = param_1[1] | 2;
  }
  if ((param_3 & 1) != 0) {
    dwExceptionCode = 0xc0000091;
    param_1[1] = param_1[1] | 4;
  }
  if ((param_3 & 4) != 0) {
    dwExceptionCode = 0xc000008e;
    param_1[1] = param_1[1] | 8;
  }
  if ((param_3 & 8) != 0) {
    dwExceptionCode = 0xc0000090;
    param_1[1] = param_1[1] | 0x10;
  }
  param_1[2] = param_1[2] ^ (~(*param_2 << 4) ^ param_1[2]) & 0x10;
  param_1[2] = param_1[2] ^ (~(*param_2 * 2) ^ param_1[2]) & 8;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 1) ^ param_1[2]) & 4;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 3) ^ param_1[2]) & 2;
  param_1[2] = param_1[2] ^ (~(*param_2 >> 5) ^ param_1[2]) & 1;
  uVar3 = FUN_1000fc09();
  puVar2 = param_6;
  if ((uVar3 & 1) != 0) {
    param_1[3] = param_1[3] | 0x10;
  }
  if ((uVar3 & 4) != 0) {
    param_1[3] = param_1[3] | 8;
  }
  if ((uVar3 & 8) != 0) {
    param_1[3] = param_1[3] | 4;
  }
  if ((uVar3 & 0x10) != 0) {
    param_1[3] = param_1[3] | 2;
  }
  if ((uVar3 & 0x20) != 0) {
    param_1[3] = param_1[3] | 1;
  }
  uVar3 = *puVar1 & 0xc00;
  if (uVar3 == 0) {
    *param_1 = *param_1 & 0xfffffffc;
  }
  else {
    if (uVar3 == 0x400) {
      uVar3 = *param_1 & 0xfffffffd | 1;
    }
    else {
      if (uVar3 != 0x800) {
        if (uVar3 == 0xc00) {
          *param_1 = *param_1 | 3;
        }
        goto LAB_100103d7;
      }
      uVar3 = *param_1 & 0xfffffffe | 2;
    }
    *param_1 = uVar3;
  }
LAB_100103d7:
  uVar3 = *puVar1 & 0x300;
  if (uVar3 == 0) {
    uVar3 = *param_1 & 0xffffffeb | 8;
LAB_1001040d:
    *param_1 = uVar3;
  }
  else {
    if (uVar3 == 0x200) {
      uVar3 = *param_1 & 0xffffffe7 | 4;
      goto LAB_1001040d;
    }
    if (uVar3 == 0x300) {
      *param_1 = *param_1 & 0xffffffe3;
    }
  }
  *param_1 = *param_1 ^ (param_4 << 5 ^ *param_1) & 0x1ffe0;
  param_1[8] = param_1[8] | 1;
  if (param_7 == 0) {
    param_1[8] = param_1[8] & 0xffffffe3 | 2;
    *(undefined8 *)(param_1 + 4) = *(undefined8 *)param_5;
    param_1[0x18] = param_1[0x18] | 1;
    param_1[0x18] = param_1[0x18] & 0xffffffe3 | 2;
    *(undefined8 *)(param_1 + 0x14) = *(undefined8 *)param_6;
  }
  else {
    param_1[8] = param_1[8] & 0xffffffe1;
    param_1[4] = *param_5;
    param_1[0x18] = param_1[0x18] | 1;
    param_1[0x18] = param_1[0x18] & 0xffffffe1;
    param_1[0x14] = *param_6;
  }
  FUN_1000fb75();
  RaiseException(dwExceptionCode,0,1,(ULONG_PTR *)&param_1);
  if ((param_1[2] & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  if ((param_1[2] & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  if ((param_1[2] & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  if ((param_1[2] & 2) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
  }
  if ((param_1[2] & 1) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  uVar3 = *param_1 & 3;
  if (uVar3 == 0) {
    *puVar1 = *puVar1 & 0xfffff3ff;
  }
  else {
    if (uVar3 == 1) {
      uVar3 = *puVar1 & 0xfffff7ff | 0x400;
    }
    else {
      if (uVar3 != 2) {
        if (uVar3 == 3) {
          *puVar1 = *puVar1 | 0xc00;
        }
        goto LAB_1001051e;
      }
      uVar3 = *puVar1 & 0xfffffbff | 0x800;
    }
    *puVar1 = uVar3;
  }
LAB_1001051e:
  uVar3 = *param_1 >> 2 & 7;
  if (uVar3 == 0) {
    uVar3 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else {
    if (uVar3 != 1) {
      if (uVar3 == 2) {
        *puVar1 = *puVar1 & 0xfffff3ff;
      }
      goto LAB_1001054f;
    }
    uVar3 = *puVar1 & 0xfffff3ff | 0x200;
  }
  *puVar1 = uVar3;
LAB_1001054f:
  if (param_7 == 0) {
    *(undefined8 *)puVar2 = *(undefined8 *)(param_1 + 0x14);
  }
  else {
    *puVar2 = param_1[0x14];
  }
  return;
}



/* VA 10010566 */

void __cdecl FUN_10010566(int param_1)

{
  __acrt_ptd *p_Var1;

  if (param_1 == 1) {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 0x21;
  }
  else if ((param_1 == 2) || (param_1 == 3)) {
    p_Var1 = FUN_100095db();
    *(undefined4 *)p_Var1 = 0x22;
    return;
  }
  return;
}



/* VA 10010597 */

float10 __cdecl
FUN_10010597(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;

  iVar1 = 0;
  do {
    if ((&DAT_10015bb8)[iVar1 * 2] == param_2) {
      local_20 = *(int *)(&UNK_10015bbc + iVar1 * 8);
      if (local_20 != 0) {
        local_1c = param_3;
        local_18 = param_4;
        local_14 = param_5;
        local_10 = param_6;
        local_c = param_7;
        local_24 = param_1;
        uStack_8 = param_8;
        __ctrlfp();
        iVar1 = FUN_1000bc0d(&local_24);
        if (iVar1 == 0) {
          FUN_10010566(param_1);
        }
        return (float10)(double)CONCAT44(uStack_8,local_c);
      }
      goto LAB_100105b7;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1d);
  local_20 = 0;
LAB_100105b7:
  __ctrlfp();
  FUN_10010566(param_1);
  return (float10)(double)CONCAT44(param_8,param_7);
}



/* VA 10010637 */

void __cdecl FUN_10010637(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  double dVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;

  dVar2 = (double)CONCAT17(param_2._3_1_,
                           CONCAT16(param_2._2_1_,CONCAT24((undefined2)param_2,param_1)));
  if (dVar2 == 0.0) {
    iVar4 = 0;
  }
  else if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    iVar4 = -0x3fd;
    uVar3 = param_2;
    if ((param_2 & 0x100000) == 0) {
      do {
        uVar1 = uVar3 * 2;
        param_2._0_2_ = (undefined2)uVar1;
        uVar3 = uVar1;
        if (param_1 < 0) {
          uVar3 = uVar1 | 1;
          param_2._0_2_ = (undefined2)uVar3;
        }
        param_1 = param_1 * 2;
        iVar4 = iVar4 + -1;
      } while ((uVar1 & 0x100000) == 0);
      param_2 = CONCAT22((short)(uVar1 >> 0x10),(undefined2)param_2);
    }
    uVar5 = (ushort)(param_2 >> 0x10) & 0xffef;
    param_2._2_1_ = (undefined1)uVar5;
    param_2._3_1_ = (byte)(uVar5 >> 8);
    if (dVar2 < 0.0) {
      param_2._3_1_ = param_2._3_1_ | 0x80;
    }
    __set_exp(CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((undefined2)param_2,param_1))),
              0);
  }
  else {
    __set_exp(dVar2,0);
    iVar4 = (param_2 >> 0x14 & 0x7ff) - 0x3fe;
  }
  *param_3 = iVar4;
  return;
}



/* VA 10010709 */

/* Library Function - Single Match
    __set_exp

   Library: Visual Studio 2019 Release */

float10 __cdecl __set_exp(undefined8 param_1,short param_2)

{
  undefined8 local_c;

  local_c = (double)CONCAT26((param_2 + 0x3fe) * 0x10 | param_1._6_2_ & 0x800f,(int6)param_1);
  return (float10)local_c;
}



/* VA 10010736 */

byte __cdecl FUN_10010736(int param_1,uint param_2)

{
  byte bVar1;

  if (param_2 == 0x7ff00000) {
    if (param_1 == 0) {
      return 1;
    }
  }
  else if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    bVar1 = 3;
  }
  else {
    if ((param_2._2_2_ & 0x7ff8) != 0x7ff0) {
      return 0;
    }
    if ((param_2 & 0x7ffff) == 0) {
      return -(param_1 != 0) & 4;
    }
    bVar1 = 4;
  }
  return bVar1;
}



/* VA 10010799 */

/* Library Function - Single Match
    __fpclass

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl __fpclass(double _X)

{
  byte bVar1;
  undefined3 extraout_var;
  int iVar2;

  if ((_X._6_2_ & 0x7ff0) == 0x7ff0) {
    bVar1 = FUN_10010736(_X._0_4_,(uint)((ulonglong)_X >> 0x20));
    iVar2 = CONCAT31(extraout_var,bVar1);
    if (iVar2 == 1) {
      return 0x200;
    }
    if (iVar2 == 2) {
      iVar2 = 4;
    }
    else {
      if (iVar2 != 3) {
        return 1;
      }
      iVar2 = 2;
    }
    return iVar2;
  }
  if ((((ulonglong)_X & 0x7ff0000000000000) == 0) &&
     ((((ulonglong)_X & 0xfffff00000000) != 0 || (_X._0_4_ != 0)))) {
    return (-(uint)(((ulonglong)_X & 0x8000000000000000) != 0) & 0xffffff90) + 0x80;
  }
  if (_X == 0.0) {
    return (-(uint)(((ulonglong)_X & 0x8000000000000000) != 0) & 0xffffffe0) + 0x40;
  }
  return (-(uint)(((ulonglong)_X & 0x8000000000000000) != 0) & 0xffffff08) + 0x100;
}



/* VA 10010840 */

/* Library Function - Single Match
    __FindPESection

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

PIMAGE_SECTION_HEADER __cdecl __FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;

  uVar3 = 0;
  iVar1 = *(int *)(pImageBase + 0x3c);
  p_Var2 = (PIMAGE_SECTION_HEADER)
           (pImageBase + *(ushort *)(pImageBase + iVar1 + 0x14) + 0x18 + iVar1);
  if (*(ushort *)(pImageBase + iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) &&
         (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



/* VA 10010890 */

/* Library Function - Single Match
    __IsNonwritableInCurrentImage

   Library: Visual Studio 2019 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  bool bVar1;
  undefined3 extraout_var;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;

  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_10019008 ^ 0x10017950;
  ExceptionList = &local_14;
  local_8 = 0;
  bVar1 = FUN_10010950((short *)&IMAGE_DOS_HEADER_10000000);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    p_Var2 = __FindPESection((PBYTE)&IMAGE_DOS_HEADER_10000000,(DWORD_PTR)(pTarget + -0x10000000));
    if (p_Var2 != (PIMAGE_SECTION_HEADER)0x0) {
      ExceptionList = local_14;
      return ~(p_Var2->Characteristics >> 0x1f) & 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* VA 10010950 */

bool __cdecl FUN_10010950(short *param_1)

{
  if ((*param_1 == 0x5a4d) && (*(int *)(*(int *)(param_1 + 0x1e) + (int)param_1) == 0x4550)) {
    return (short)((int *)(*(int *)(param_1 + 0x1e) + (int)param_1))[6] == 0x10b;
  }
  return false;
}



/* VA 10010981 */

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __EH_epilog3

   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __EH_epilog3(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;

  ExceptionList = (void *)unaff_EBP[-3];
  *unaff_EBP = unaff_retaddr;
  return;
}



/* VA 10010995 */

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */
/* Library Function - Single Match
    __EH_prolog3

   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __cdecl __EH_prolog3(int param_1)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];

  iVar1 = -param_1;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + iVar1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10019008 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



/* VA 100109c8 */

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */
/* Library Function - Single Match
    __EH_prolog3_catch

   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __cdecl __EH_prolog3_catch(int param_1)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];

  iVar1 = -param_1;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + iVar1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10019008 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



/* VA 10010a00 */

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16

   Library: Visual Studio */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;

  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



/* VA 10010a16 */

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_8

   Library: Visual Studio */

uint __alloca_probe_8(void)

{
  uint in_EAX;
  uint uVar1;

  uVar1 = 4 - in_EAX & 7;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



/* VA 10010a30 */

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __chkstk

   Library: Visual Studio 2019 Release */

void __alloca_probe(void)

{
  undefined1 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_retaddr;
  undefined1 auStack_4 [4];

  puVar2 = (undefined4 *)((int)&stack0x00000000 - (int)in_EAX & ~-(uint)(&stack0x00000000 < in_EAX))
  ;
  for (puVar1 = (undefined4 *)((uint)auStack_4 & 0xfffff000); puVar2 < puVar1;
      puVar1 = puVar1 + -0x400) {
  }
  *puVar2 = unaff_retaddr;
  return;
}



/* VA 10010a60 */

/* Library Function - Single Match
    __filter_x86_sse2_floating_point_exception_default

   Library: Visual Studio 2019 Release */

int __cdecl __filter_x86_sse2_floating_point_exception_default(int param_1)

{
  uint uVar1;

  if ((DAT_100199c8 < 1) || ((param_1 != -0x3ffffd4c && (param_1 != -0x3ffffd4b)))) {
    return param_1;
  }
  uVar1 = MXCSR ^ 0x3f;
  if ((uVar1 & 0x81) != 0) {
    if ((uVar1 & 0x204) == 0) {
      return -0x3fffff72;
    }
    if ((uVar1 & 0x102) != 0) {
      if ((uVar1 & 0x408) == 0) {
        return -0x3fffff6f;
      }
      if ((uVar1 & 0x810) != 0) {
        if ((uVar1 & 0x1020) != 0) {
          return param_1;
        }
        return -0x3fffff71;
      }
      return -0x3fffff6d;
    }
  }
  return -0x3fffff70;
}



/* VA 10010ae0 */

void Unwind_10010ae0(void)

{
  int unaff_EBP;

  FUN_10001010((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



/* VA 10010b20 */

void Unwind_10010b20(void)

{
  int unaff_EBP;

  FUN_10001480(*(int **)(unaff_EBP + -0x14));
  return;
}



/* VA 10010b50 */

void Unwind_10010b50(void)

{
  int unaff_EBP;

  FUN_10001480(*(int **)(unaff_EBP + -0x14));
  return;
}



/* VA 10010b80 */

void Unwind_10010b80(void)

{
  int unaff_EBP;

  FUN_10004240(unaff_EBP + -0x3c);
  return;
}



/* VA 10010be0 */

void Unwind_10010be0(void)

{
  int unaff_EBP;

  FUN_10001d10((int *)(unaff_EBP + -0x260));
  return;
}



/* VA 10010beb */

void Unwind_10010beb(void)

{
  int unaff_EBP;

  FUN_10001d10((int *)(unaff_EBP + -0x27c));
  return;
}



/* VA 10010bf6 */

void Unwind_10010bf6(void)

{
  int unaff_EBP;

  FUN_10001d10((int *)(unaff_EBP + -0x248));
  return;
}



/* VA 10010c01 */

void Unwind_10010c01(void)

{
  int unaff_EBP;

  FUN_10001d10((int *)(unaff_EBP + -0x294));
  return;
}



/* VA 10010c40 */

void Unwind_10010c40(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003d30(*(int **)(unaff_EBP + -0x18));
    return;
  }
  return;
}



/* VA 10010c80 */

void Unwind_10010c80(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0x70));
  return;
}



/* VA 10010c88 */

void Unwind_10010c88(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xb8));
  return;
}



/* VA 10010c93 */

void Unwind_10010c93(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0x100));
  return;
}



/* VA 10010cd0 */

void Unwind_10010cd0(void)

{
  int unaff_EBP;

  FUN_10004f47(*(LPVOID *)(unaff_EBP + -0x28));
  return;
}



/* VA 10010cdf */

void Unwind_10010cdf(void)

{
  int unaff_EBP;

  FUN_10001720(*(undefined4 **)(unaff_EBP + -0x28));
  return;
}



/* VA 10010ce7 */

void Unwind_10010ce7(void)

{
  int unaff_EBP;

  FUN_10003cb0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



/* VA 10010cef */

void Unwind_10010cef(void)

{
  int unaff_EBP;

  FUN_10004f47(*(LPVOID *)(unaff_EBP + -0x1c));
  return;
}



/* VA 10010cfe */

void Unwind_10010cfe(void)

{
  int unaff_EBP;

  FUN_10001720(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



/* VA 10010d06 */

void Unwind_10010d06(void)

{
  int unaff_EBP;

  FUN_10003c30((undefined4 *)(unaff_EBP + -0x30));
  return;
}



/* VA 10010d0e */

void Unwind_10010d0e(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0x7c));
  return;
}



/* VA 10010d16 */

void Unwind_10010d16(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0x7c));
  return;
}



/* VA 10010d1e */

void Unwind_10010d1e(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0x7c));
  return;
}



/* VA 10010d26 */

void Unwind_10010d26(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0x138));
  return;
}



/* VA 10010d31 */

void Unwind_10010d31(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d3c */

void Unwind_10010d3c(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d47 */

void Unwind_10010d47(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0x138));
  return;
}



/* VA 10010d52 */

void Unwind_10010d52(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d5d */

void Unwind_10010d5d(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d68 */

void Unwind_10010d68(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d73 */

void Unwind_10010d73(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d7e */

void Unwind_10010d7e(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d89 */

void Unwind_10010d89(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d94 */

void Unwind_10010d94(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010d9f */

void Unwind_10010d9f(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010daa */

void Unwind_10010daa(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010db5 */

void Unwind_10010db5(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0x7c));
  return;
}



/* VA 10010dbd */

void Unwind_10010dbd(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010dc8 */

void Unwind_10010dc8(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010dd3 */

void Unwind_10010dd3(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010dde */

void Unwind_10010dde(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010de9 */

void Unwind_10010de9(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010df4 */

void Unwind_10010df4(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010dff */

void Unwind_10010dff(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010e0a */

void Unwind_10010e0a(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}



/* VA 10010e15 */

void Unwind_10010e15(void)

{
  int unaff_EBP;

  thunk_FUN_10001480((int *)(unaff_EBP + -0xf0));
  return;
}
