/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 31799f8af882488343b98b243900522c73775fdfd213aa613ddc80fd3656f817 */

/* VA 10001000 */

int FUN_10001000(void)

{
  byte *pbVar1;
  int iVar2;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  puStack_c = &LAB_10032029;
  local_10 = ExceptionList;
  local_8 = 0;
  local_18 = -1;
  local_14 = 0;
  ExceptionList = &local_10;
  do {
    if (DAT_10041574 <= local_14) {
LAB_1000106e:
      local_8 = 0xffffffff;
      FUN_1002b168((int *)&stack0x00000004);
      ExceptionList = local_10;
      return local_18;
    }
    pbVar1 = (byte *)FUN_10002180((undefined4 *)&stack0x00000004);
    iVar2 = FUN_10002190(&DAT_10040d58 + local_14 * 0x3c,pbVar1);
    if (iVar2 == 0) {
      local_18 = local_14;
      goto LAB_1000106e;
    }
    local_14 = local_14 + 1;
  } while( true );
}



/* VA 10001094 */

undefined4 __cdecl TDSETUP_Init(LPCSTR param_1)

{
  bool bVar1;
  void *pvVar2;
  int *piVar3;
  undefined3 extraout_var;
  uint *puVar4;
  byte *pbVar5;
  int local_418;
  int local_414;
  undefined1 local_40d [1029];
  undefined4 local_8;

                    /* 0x1094  21  TDSETUP_Init */
  FUN_1002b2a5(&DAT_100416f4,param_1);
  pbVar5 = &DAT_1003a0b0;
  pvVar2 = (void *)FUN_1002a079();
  bVar1 = FUN_10002230(pvVar2,pbVar5);
  local_40d[0] = bVar1;
  FUN_1002b168(&local_414);
  if ((local_40d._0_4_ & 0xff) != 0) {
    FUN_100021d0((int *)&DAT_100416f4);
    piVar3 = (int *)FUN_1002a0f5();
    FUN_1002b255(&DAT_100416f4,piVar3);
    FUN_1002b168(&local_418);
  }
  TDSETUP_GetRegisteredTableVersion(&DAT_100416ec);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_Init____s__1003a0b4);
  }
  local_8 = FUN_10002780(0x100406b0);
  bVar1 = FUN_10002210((int *)&DAT_100416e8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    puVar4 = (uint *)FUN_10002180((undefined4 *)&DAT_100416e8);
    FUN_1001f150((uint *)(local_40d + 1),puVar4);
    TDSETUP_SetCurrentRenderer(local_40d + 1);
  }
  else {
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_Init__Setting_Default_1003a0c8);
    }
    TDSETUP_SetDefault();
  }
  return local_8;
}



/* VA 100011cd */

undefined4 __cdecl TDSETUP_GetProductName(uint *param_1)

{
  bool bVar1;
  int *extraout_EAX;
  uint *puVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  int local_10;
  undefined1 *local_c;
  int local_8;

                    /* 0x11cd  12  TDSETUP_GetProductName */
  FUN_10002250(&local_8);
  local_c = &stack0xffffffe4;
  FUN_1002aedd(&stack0xffffffe4,(int *)&DAT_100416f4);
  FUN_1000a448(&local_10);
  FUN_1002b255(&local_8,extraout_EAX);
  FUN_1002b168(&local_10);
  puVar2 = (uint *)FUN_10002180(&local_8);
  FUN_1001f150(param_1,puVar2);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetProductName____s__1003a0e8);
  }
  bVar1 = FUN_10002210(&local_8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_1002b168(&local_8);
    uVar3 = 0;
  }
  else {
    FUN_1002b168(&local_8);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* VA 1000127c */

undefined4 __cdecl TDSETUP_GetProductKey(uint *param_1)

{
  bool bVar1;
  int *piVar2;
  uint *puVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  int local_10;
  undefined1 *local_c;
  int local_8;

                    /* 0x127c  11  TDSETUP_GetProductKey */
  FUN_10002250(&local_8);
  local_c = &stack0xffffffe4;
  FUN_1002aedd(&stack0xffffffe4,(int *)&DAT_100416f4);
  piVar2 = FUN_10004080(&local_10);
  FUN_1002b255(&local_8,piVar2);
  FUN_1002b168(&local_10);
  puVar3 = (uint *)FUN_10002180(&local_8);
  FUN_1001f150(param_1,puVar3);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetProductKey____s__1003a108);
  }
  bVar1 = FUN_10002210(&local_8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_1002b168(&local_8);
    uVar4 = 0;
  }
  else {
    FUN_1002b168(&local_8);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



/* VA 1000132b */

undefined4 __cdecl TDSETUP_GetLanguage(uint *param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  int local_8;

                    /* 0x132b  9  TDSETUP_GetLanguage */
  FUN_10002250(&local_8);
  uVar1 = FUN_10009cc6(&local_8);
  puVar2 = (uint *)FUN_10002180(&local_8);
  FUN_1001f150(param_1,puVar2);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetLanguage___d____s_1003a128);
  }
  FUN_1002b168(&local_8);
  return uVar1;
}



/* VA 100013a0 */

undefined4 TDSETUP_ForceWriteCards(void)

{
  undefined4 uVar1;

                    /* 0x13a0  3  TDSETUP_ForceWriteCards */
  uVar1 = DAT_100416fc;
  DAT_100416fc = 1;
  if (DAT_100416f8 != (int *)0x0) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_ForceWriteCards_1003a148);
  }
  FUN_1000a9c4();
  DAT_100416fc = uVar1;
  return 0;
}



/* VA 100013f0 */

undefined4 __cdecl TDSETUP_GetRenderOptions(uint *param_1)

{
  uint *puVar1;
  size_t sVar2;
  int local_c;
  uint *local_8;

                    /* 0x13f0  14  TDSETUP_GetRenderOptions */
  local_8 = param_1;
  FUN_1001f150(param_1,(uint *)&DAT_100406a0);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetRenderOptions_START_1003a164);
  }
  for (local_c = 0; local_c < DAT_10041574; local_c = local_c + 1) {
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetRenderOptions___s_1003a184);
    }
    puVar1 = (uint *)FUN_10002180((undefined4 *)(&DAT_10040d58 + local_c * 0x3c));
    FUN_1001f160(local_8,puVar1);
    sVar2 = _strlen((char *)local_8);
    local_8 = (uint *)((int)local_8 + sVar2 + 1);
    *(undefined1 *)local_8 = 0;
  }
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetRenderOptions_END_1003a1a4);
  }
  return 0;
}



/* VA 100014ee */

undefined4 __cdecl TDSETUP_GetInUseRenderer(uint *param_1)

{
  int *piVar1;
  uint *puVar2;
  int local_c;
  int local_8;

                    /* 0x14ee  6  TDSETUP_GetInUseRenderer */
  FUN_10002250(&local_8);
  piVar1 = FUN_100087c8(&local_c);
  FUN_1002b255(&local_8,piVar1);
  FUN_1002b168(&local_c);
  puVar2 = (uint *)FUN_10002180(&local_8);
  FUN_1001f150(param_1,puVar2);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetInUseRenderer___s_1003a1c4);
  }
  FUN_1002b168(&local_8);
  return 0;
}



/* VA 1000156d */

undefined4 __cdecl TDSETUP_GetCurrentRenderer(uint *param_1)

{
  uint *puVar1;

                    /* 0x156d  4  TDSETUP_GetCurrentRenderer */
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetCurrentRenderer___s_1003a1e4);
  }
  puVar1 = (uint *)FUN_10002180(&DAT_100416dc);
  FUN_1001f150(param_1,puVar1);
  return 0;
}



/* VA 100015b7 */

undefined4 __cdecl TDSETUP_SetCurrentRenderer(byte *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_14;
  int local_10;
  undefined1 *local_c;
  int local_8;

                    /* 0x15b7  26  TDSETUP_SetCurrentRenderer */
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetCurrentRenderer___s_1003a208);
  }
  local_c = &stack0xffffffe8;
  FUN_1002b1d6(&stack0xffffffe8,(LPCSTR)param_1);
  local_8 = FUN_10001000();
  if (local_8 == -1) {
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetCurrentRenderer__TDSE_1003a260);
    }
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = FUN_10002190(&DAT_100416e8,param_1);
    if (iVar1 == 0) {
      piVar2 = FUN_100087c8(&local_10);
      FUN_1002b255(&DAT_100416dc,piVar2);
      FUN_1002b168(&local_10);
      piVar2 = FUN_10008992(&local_14);
      FUN_1002b255(&DAT_100416e4,piVar2);
      FUN_1002b168(&local_14);
      if (*(int *)(&DAT_10040d68 + local_8 * 0x3c) == 99) {
        DAT_100416e0 = 99;
      }
      else {
        DAT_100416e0 = FUN_10008c04();
      }
    }
    else {
      FUN_1002b2a5(&DAT_100416dc,(LPCSTR)param_1);
      DAT_100416e0 = *(uint *)(&DAT_10040d68 + local_8 * 0x3c);
      iVar1 = FUN_10002270((int)(&DAT_10040d74 + local_8 * 0x3c));
      if (iVar1 != 0) {
        FUN_1002b2a5(&DAT_100416e4,s_640x480_1003a228);
      }
    }
    DAT_100416f0 = *(undefined4 *)(&DAT_10040d6c + local_8 * 0x3c);
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetCurrentRenderer__TDSE_1003a230);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* VA 1000172d */

undefined4 __cdecl TDSETUP_GetResolutionOptions(uint *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  size_t sVar5;
  undefined4 uVar6;
  int local_14;
  uint *local_c;

                    /* 0x172d  15  TDSETUP_GetResolutionOptions */
  local_c = param_1;
  FUN_1001f150(param_1,(uint *)&DAT_100406a1);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetResolutionOptions_STA_1003a28c);
  }
  FUN_1002aedd(&stack0xffffffe0,&DAT_100416dc);
  iVar1 = FUN_10001000();
  if (iVar1 < 0) {
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetResolutionOptions_END_1003a300);
    }
    uVar6 = 0xfffffffe;
  }
  else {
    iVar2 = FUN_10002270((int)(&DAT_10040d74 + iVar1 * 0x3c));
    if (iVar2 < 1) {
      FUN_1001f160(param_1,(uint *)s_640x480_1003a2d4);
      FUN_1002b2a5(&DAT_100416e4,(LPCSTR)param_1);
      sVar5 = _strlen((char *)param_1);
      *(undefined1 *)((int)param_1 + sVar5 + 1) = 0;
    }
    else {
      for (local_14 = 0; local_14 < iVar2; local_14 = local_14 + 1) {
        puVar3 = FUN_1002a846(&DAT_10040d74 + iVar1 * 0x3c,local_14);
        if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
          FUN_10002290((int)puVar3);
          FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetResolutionOptions___s_1003a2b0);
        }
        puVar3 = (undefined4 *)FUN_10002290((int)puVar3);
        puVar4 = (uint *)FUN_10002180(puVar3);
        FUN_1001f160(local_c,puVar4);
        sVar5 = _strlen((char *)local_c);
        local_c = (uint *)((int)local_c + sVar5 + 1);
        *(undefined1 *)local_c = 0;
      }
    }
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetResolutionOptions_END_1003a2dc);
    }
    uVar6 = 0;
  }
  return uVar6;
}



/* VA 10001907 */

undefined4 __cdecl TDSETUP_GetCurrentResolution(uint *param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;

                    /* 0x1907  5  TDSETUP_GetCurrentResolution */
  FUN_1002aedd(&stack0xfffffff0,&DAT_100416dc);
  iVar1 = FUN_10001000();
  if (iVar1 < 0) {
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetCurrentResolution__TD_1003a348);
    }
    uVar3 = 0xfffffffe;
  }
  else {
    puVar2 = (uint *)FUN_10002180(&DAT_100416e4);
    FUN_1001f150(param_1,puVar2);
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetCurrentResolution___s_1003a324);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* VA 100019a6 */

int __cdecl TDSETUP_SetCurrentResolution(byte *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int local_18;
  int local_10;
  int local_c;
  int local_8;

                    /* 0x19a6  27  TDSETUP_SetCurrentResolution */
  local_8 = -2;
  FUN_10002250(&local_10);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetCurrentResolution___s_1003a384);
  }
  FUN_1002aedd(&stack0xffffffd8,&DAT_100416dc);
  local_c = FUN_10001000();
  if (local_c < 0) {
    local_8 = -1;
  }
  else {
    iVar1 = FUN_10002270((int)(&DAT_10040d74 + local_c * 0x3c));
    if (0 < iVar1) {
      for (local_18 = 0; local_18 < iVar1; local_18 = local_18 + 1) {
        puVar2 = FUN_1002a846(&DAT_10040d74 + local_c * 0x3c,local_18);
        piVar3 = (int *)FUN_10002290((int)puVar2);
        FUN_1002b255(&local_10,piVar3);
        iVar4 = FUN_100022b0(&local_10,param_1);
        if (iVar4 == 0) {
          FUN_1002b255(&DAT_100416e4,&local_10);
          local_8 = 0;
          break;
        }
      }
    }
  }
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    if (local_8 == 0) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetCurrentResolution__TD_1003a3a8);
    }
    else {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetCurrentResolution__TD_1003a3d8);
    }
  }
  iVar1 = local_8;
  FUN_1002b168(&local_10);
  return iVar1;
}



/* VA 10001afc */

undefined4 __cdecl TDSETUP_GetTripleBufferOption(int *param_1)

{
  undefined4 local_8;

                    /* 0x1afc  20  TDSETUP_GetTripleBufferOption */
  if (DAT_100416e0 == 99) {
    *param_1 = 99;
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetTripleBufferOption__T_1003a408);
    }
    local_8 = 0xfffffffe;
  }
  else {
    *param_1 = DAT_100416e0;
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetTripleBufferOption____1003a448);
    }
    local_8 = 0;
  }
  return local_8;
}



/* VA 10001b8b */

int __cdecl TDSETUP_SetTripleBufferOption(int param_1)

{
  int local_8;

                    /* 0x1b8b  29  TDSETUP_SetTripleBufferOption */
  if (DAT_100416e0 == 99) {
    local_8 = -2;
  }
  else {
    DAT_100416e0 = param_1;
    local_8 = 0;
  }
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    if (local_8 == -2) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetTripleBufferOption__T_1003a46c);
    }
    else {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetTripleBufferOption____1003a4ac);
    }
  }
  return local_8;
}



/* VA 10001c03 */

undefined4 TDSETUP_SetDefault(void)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  uint local_40c [257];
  int local_8;

                    /* 0x1c03  28  TDSETUP_SetDefault */
  local_8 = 0;
  FUN_1002b255(&DAT_100416dc,(int *)&DAT_10040d58);
  puVar1 = (uint *)FUN_10002180(&DAT_100416dc);
  FUN_1001f150(local_40c,puVar1);
  DAT_100416e0 = *(undefined4 *)(&DAT_10040d68 + local_8 * 0x3c);
  iVar2 = FUN_10002270((int)(&DAT_10040d74 + local_8 * 0x3c));
  if (iVar2 == 0) {
    FUN_1002b2a5(&DAT_100416e4,s_640x480_1003a4d0);
  }
  else {
    piVar3 = (int *)FUN_100022f0((int)(&DAT_10040d74 + local_8 * 0x3c));
    FUN_1002b255(&DAT_100416e4,piVar3);
  }
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SetDefault___s___d___s_1003a4d8);
  }
  TDSETUP_SaveSettings();
  TDSETUP_SetCurrentRenderer((byte *)local_40c);
  return 0;
}



/* VA 10001cea */

undefined4 TDSETUP_TestPerformance(void)

{
                    /* 0x1cea  30  TDSETUP_TestPerformance */
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_TestPerformance__TDSETUP_1003a4f8);
  }
  return 0xffffffff;
}



/* VA 10001d17 */

undefined4 __cdecl TDSETUP_GetShowTestButton(undefined4 *param_1)

{
                    /* 0x1d17  18  TDSETUP_GetShowTestButton */
  *param_1 = DAT_10041598;
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetShowTestButton___d_1003a524);
  }
  return 0;
}



/* VA 10001d55 */

undefined4 TDSETUP_SaveSettings(void)

{
  int iVar1;
  undefined4 uVar2;

                    /* 0x1d55  25  TDSETUP_SaveSettings */
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SaveSettings___s_1003a544);
  }
  FUN_1002aedd(&stack0xffffffec,&DAT_100416dc);
  iVar1 = FUN_10001000();
  if (iVar1 < 0) {
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SaveSettings__TDSETUP_FA_1003a588);
    }
    uVar2 = 0xffffffff;
  }
  else {
    FUN_1002aedd(&stack0xffffffec,&DAT_100416e4);
    FUN_10008d91(iVar1,DAT_100416e0);
    FUN_1002b255(&DAT_100416e8,&DAT_100416dc);
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_SaveSettings__TDSETUP_SU_1003a560);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 10001e31 */

undefined4 __cdecl TDSETUP_RemoveRegistryEntries(LPCSTR param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_c [4];
  undefined1 *local_8;

                    /* 0x1e31  24  TDSETUP_RemoveRegistryEntries */
  local_8 = auStack_c;
  FUN_1002b1d6(auStack_c,param_1);
  iVar1 = FUN_100093cc();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* VA 10001e5b */

undefined4 __cdecl TDSETUP_Debug(int param_1)

{
                    /* 0x1e5b  1  TDSETUP_Debug */
  if (DAT_100416fc != param_1) {
    DAT_100416fc = param_1;
    if (DAT_100416f8 != (FILE *)0x0) {
      FUN_1001f240((int *)DAT_100416f8,(byte *)s_DEBUG_CLOSED_1003a5b0);
      FUN_1001f4d4(DAT_100416f8);
    }
    if ((DAT_100416fc != 0) &&
       (DAT_100416f8 = (FILE *)FUN_1001f4c1(s_C__test_txt_1003a5c0,&DAT_1003a5be),
       DAT_100416f8 == (FILE *)0x0)) {
      DAT_100416fc = 0;
      return 0xffffffff;
    }
  }
  return 0;
}



/* VA 10001ed8 */

undefined4 TDSETUP_Release(void)

{
                    /* 0x1ed8  23  TDSETUP_Release */
  if (DAT_100416f8 != (FILE *)0x0) {
    FUN_1001f240((int *)DAT_100416f8,(byte *)s_TDSETUP_Release_1003a5cc);
    FUN_1001f4d4(DAT_100416f8);
    DAT_100416f8 = (FILE *)0x0;
  }
  return 0;
}



/* VA 10001f14 */

undefined4 __cdecl TDSETUP_GetRegisteredTableVersion(int *param_1)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 *puVar3;
  short local_164;
  undefined4 local_162 [64];
  char *local_60;
  HKEY local_5c;
  DWORD local_58;
  int local_54;
  undefined4 local_50;
  uint local_4c [17];
  REGSAM local_8;

                    /* 0x1f14  13  TDSETUP_GetRegisteredTableVersion */
  local_60 = s_SOFTWARE_Electronic_Arts_3DSetup_1003a5e0;
  local_164 = DAT_100406a2;
  puVar3 = local_162;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  local_58 = 0x100;
  local_54 = 0;
  local_50 = 0;
  local_8 = FUN_10002753();
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,local_60,0,local_8,&local_5c);
  if (LVar1 == 0) {
    FUN_1001f150(local_4c,(uint *)s_Version_1003a604);
    LVar1 = RegQueryValueExA(local_5c,(LPCSTR)local_4c,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_164,
                             &local_58);
    if (LVar1 == 0) {
      local_54 = (int)local_164;
    }
    else {
      local_50 = 0xffffffff;
    }
    RegCloseKey(local_5c);
  }
  else {
    local_50 = 0xffffffff;
  }
  *param_1 = local_54;
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetRegisteredTableVersio_1003a60c);
  }
  return local_50;
}



/* VA 1000202b */

undefined4 __cdecl TDSETUP_GetInternalTableVersion(undefined4 *param_1)

{
                    /* 0x202b  7  TDSETUP_GetInternalTableVersion */
  *param_1 = DAT_1003a6bc;
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetInternalTableVersion__1003a640);
  }
  return 0;
}



/* VA 10002069 */

undefined4 __cdecl TDSETUP_GetOriginalTableVersion(undefined4 *param_1)

{
                    /* 0x2069  10  TDSETUP_GetOriginalTableVersion */
  *param_1 = DAT_100416ec;
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetOriginalTableVersion__1003a668);
  }
  return 0;
}



/* VA 100020a7 */

undefined4 __cdecl TDSETUP_GetKnownCard(undefined4 *param_1)

{
                    /* 0x20a7  8  TDSETUP_GetKnownCard */
  *param_1 = DAT_100416f0;
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_TDSETUP_GetKnownCard___d_1003a690);
  }
  return 0;
}



/* VA 100020e5 */

undefined4 TDSETUP_DebugTable(void)

{
  int iVar1;

                    /* 0x20e5  2  TDSETUP_DebugTable */
  iVar1 = DAT_100416fc;
  TDSETUP_Debug(1);
  FUN_10002d14();
  TDSETUP_Debug(iVar1);
  return 0;
}



/* VA 10002112 */

undefined4 __cdecl TDSETUP_GetShowTripleBufferOption(undefined4 *param_1)

{
                    /* 0x2112  19  TDSETUP_GetShowTripleBufferOption */
  *param_1 = DAT_1004159c;
  return 0;
}



/* VA 10002124 */

undefined4 __cdecl TDSETUP_GetShowResolutionsOption(undefined4 *param_1)

{
                    /* 0x2124  17  TDSETUP_GetShowResolutionsOption */
  *param_1 = DAT_10041594;
  return 0;
}



/* VA 10002136 */

undefined4 __cdecl TDSETUP_IsSupportedCard(undefined4 *param_1)

{
  int iVar1;
  undefined1 auStack_10 [4];
  undefined1 *local_c;

                    /* 0x2136  22  TDSETUP_IsSupportedCard */
  local_c = auStack_10;
  FUN_1002aedd(auStack_10,&DAT_100416dc);
  iVar1 = FUN_10001000();
  *param_1 = *(undefined4 *)(&DAT_10040d70 + iVar1 * 0x3c);
  return 0;
}



/* VA 1000216e */

undefined4 __cdecl TDSETUP_GetShowDefaultOption(undefined4 *param_1)

{
                    /* 0x216e  16  TDSETUP_GetShowDefaultOption */
  *param_1 = DAT_100415a0;
  return 0;
}



/* VA 10002180 */

undefined4 __fastcall FUN_10002180(undefined4 *param_1)

{
  return *param_1;
}



/* VA 10002190 */

void __thiscall FUN_10002190(void *this,byte *param_1)

{
  FUN_100021b0(*(byte **)this,param_1);
  return;
}



/* VA 100021b0 */

void __cdecl FUN_100021b0(byte *param_1,byte *param_2)

{
  FUN_1001f09a(param_1,param_2);
  return;
}



/* VA 100021d0 */

undefined4 __fastcall FUN_100021d0(int *param_1)

{
  int iVar1;

  iVar1 = FUN_100021f0(param_1);
  return *(undefined4 *)(iVar1 + 4);
}



/* VA 100021f0 */

int __fastcall FUN_100021f0(int *param_1)

{
  return *param_1 + -0xc;
}



/* VA 10002210 */

bool __fastcall FUN_10002210(int *param_1)

{
  int iVar1;

  iVar1 = FUN_100021f0(param_1);
  return *(int *)(iVar1 + 4) == 0;
}



/* VA 10002230 */

bool FUN_10002230(void *param_1,byte *param_2)

{
  int iVar1;

  iVar1 = FUN_10002190(param_1,param_2);
  return (bool)('\x01' - (iVar1 != 0));
}



/* VA 10002250 */

undefined4 * __fastcall FUN_10002250(undefined4 *param_1)

{
  *param_1 = PTR_DAT_1003d148;
  return param_1;
}



/* VA 10002270 */

undefined4 __fastcall FUN_10002270(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* VA 10002290 */

int FUN_10002290(int param_1)

{
  return param_1 + 8;
}



/* VA 100022b0 */

void __thiscall FUN_100022b0(void *this,byte *param_1)

{
  FUN_100022d0(*(void **)this,param_1);
  return;
}



/* VA 100022d0 */

void __cdecl FUN_100022d0(void *param_1,byte *param_2)

{
  FUN_1001f2fb(param_1,param_1,param_2);
  return;
}



/* VA 100022f0 */

int __fastcall FUN_100022f0(int param_1)

{
  return *(int *)(param_1 + 4) + 8;
}



/* VA 10002310 */

void FUN_10002310(void)

{
  FUN_1000231f();
  FUN_1000232e();
  return;
}



/* VA 1000231f */

void FUN_1000231f(void)

{
  FUN_1001de20(0x100406b0);
  return;
}



/* VA 1000232e */

void FUN_1000232e(void)

{
  FUN_1001f5cf(FUN_10002340);
  return;
}



/* VA 10002340 */

void FUN_10002340(void)

{
  FUN_1001dd10(0x100406b0);
  return;
}



/* VA 1000234f */

void FUN_1000234f(void)

{
  BOOL BVar1;
  _OSVERSIONINFOA local_a4;

  FUN_1001f150((uint *)&DAT_10041708,(uint *)s_Unknown_1003a6c0);
  _memset(&local_a4,0,0x9c);
  local_a4.dwOSVersionInfoSize = 0x9c;
  BVar1 = GetVersionExA(&local_a4);
  if (BVar1 == 0) {
    local_a4.dwOSVersionInfoSize = 0x94;
    BVar1 = GetVersionExA(&local_a4);
    if (BVar1 == 0) {
      return;
    }
  }
  DAT_10041700 = 0;
  if (local_a4.dwPlatformId == 0) {
    FUN_1001f150((uint *)&DAT_10041708,(uint *)s_Microsoft_Win32s_1003a714);
  }
  else if (local_a4.dwPlatformId == 1) {
    if ((local_a4.dwMajorVersion < 4) || (local_a4.dwMinorVersion < 0x5a)) {
      if ((local_a4.dwMajorVersion < 5) &&
         ((local_a4.dwMajorVersion != 4 || (local_a4.dwMinorVersion == 0)))) {
        FUN_1001f150((uint *)&DAT_10041708,(uint *)s_Windows_95_1003a708);
      }
      else {
        FUN_1001f150((uint *)&DAT_10041708,(uint *)s_Windows_98_1003a6fc);
      }
    }
    else {
      FUN_1001f150((uint *)&DAT_10041708,(uint *)s_Windows_ME_1003a6f0);
    }
  }
  else if (local_a4.dwPlatformId == 2) {
    DAT_10041700 = 1;
    if (local_a4.dwMajorVersion < 5) {
      FUN_1001f150((uint *)&DAT_10041708,(uint *)s_Windows_NT_1003a6c8);
    }
    if (4 < local_a4.dwMajorVersion) {
      if (local_a4.dwMinorVersion == 0) {
        FUN_1001f150((uint *)&DAT_10041708,(uint *)s_Windows_2000_1003a6e0);
      }
      else {
        FUN_1001f150((uint *)&DAT_10041708,(uint *)s_Windows_XP_1003a6d4);
      }
    }
  }
  return;
}



/* VA 100024d8 */

void FUN_100024d8(void)

{
  HANDLE pvVar1;
  DWORD DVar2;
  BOOL BVar3;
  HANDLE *ppvVar4;
  HANDLE local_70;
  undefined4 local_6c;
  undefined4 local_68;
  HLOCAL local_64;
  BOOL local_60;
  PSID local_5c;
  _PRIVILEGE_SET local_58;
  DWORD local_44;
  DWORD local_40;
  GENERIC_MAPPING local_3c;
  DWORD local_2c;
  _SID_IDENTIFIER_AUTHORITY local_28;
  PACL local_20;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_100343e0;
  puStack_10 = &LAB_1001f834;
  pvStack_14 = ExceptionList;
  local_2c = 0x14;
  local_20 = (PACL)0x0;
  local_5c = (PSID)0x0;
  local_60 = 0;
  local_64 = (HLOCAL)0x0;
  local_28.Value[0] = '\0';
  local_28.Value[1] = '\0';
  local_28.Value[2] = '\0';
  local_28.Value[3] = '\0';
  local_28.Value[4] = '\0';
  local_28.Value[5] = '\x05';
  local_8 = 0;
  ExceptionList = &pvStack_14;
  ImpersonateSelf(SecurityImpersonation);
  ppvVar4 = &local_70;
  BVar3 = 0;
  DVar2 = 8;
  pvVar1 = GetCurrentThread();
  BVar3 = OpenThreadToken(pvVar1,DVar2,BVar3,ppvVar4);
  if (BVar3 == 0) {
    DVar2 = GetLastError();
    if (DVar2 != 0x3f0) goto LAB_10002700;
    ppvVar4 = &local_70;
    DVar2 = 8;
    pvVar1 = GetCurrentProcess();
    BVar3 = OpenProcessToken(pvVar1,DVar2,ppvVar4);
    if (BVar3 == 0) goto LAB_10002700;
  }
  BVar3 = AllocateAndInitializeSid(&local_28,'\x02',0x20,0x220,0,0,0,0,0,0,&local_5c);
  if (((BVar3 != 0) && (local_64 = LocalAlloc(0x40,0x14), local_64 != (HLOCAL)0x0)) &&
     (BVar3 = InitializeSecurityDescriptor(local_64,1), BVar3 != 0)) {
    DVar2 = GetLengthSid(local_5c);
    local_40 = DVar2 + 0x10;
    local_20 = LocalAlloc(0x40,local_40);
    if ((local_20 != (PACL)0x0) && (BVar3 = InitializeAcl(local_20,local_40,2), BVar3 != 0)) {
      local_6c = 3;
      BVar3 = AddAccessAllowedAce(local_20,2,3,local_5c);
      if ((BVar3 != 0) && (BVar3 = SetSecurityDescriptorDacl(local_64,1,local_20,0), BVar3 != 0)) {
        SetSecurityDescriptorGroup(local_64,local_5c,0);
        SetSecurityDescriptorOwner(local_64,local_5c,0);
        BVar3 = IsValidSecurityDescriptor(local_64);
        if (BVar3 != 0) {
          local_68 = 1;
          local_3c.GenericRead = 1;
          local_3c.GenericWrite = 2;
          local_3c.GenericExecute = 0;
          local_3c.GenericAll = 3;
          BVar3 = AccessCheck(local_64,local_70,1,&local_3c,&local_58,&local_2c,&local_44,&local_60)
          ;
          if (BVar3 == 0) {
            GetLastError();
            FUN_1001f7e8((byte *)s_AccessCheck___failed_with_error___1003a728);
          }
          else {
            RevertToSelf();
          }
        }
      }
    }
  }
LAB_10002700:
  local_8 = 0xffffffff;
  FUN_1000270e();
  FUN_1000273f();
  return;
}



/* VA 1000270e */

void FUN_1000270e(void)

{
  int unaff_EBP;

  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    LocalFree(*(HLOCAL *)(unaff_EBP + -0x1c));
  }
  if (*(int *)(unaff_EBP + -0x60) != 0) {
    LocalFree(*(HLOCAL *)(unaff_EBP + -0x60));
  }
  if (*(int *)(unaff_EBP + -0x58) != 0) {
    FreeSid(*(PSID *)(unaff_EBP + -0x58));
  }
  return;
}



/* VA 1000273f */

undefined4 FUN_1000273f(void)

{
  int unaff_EBP;

  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return *(undefined4 *)(unaff_EBP + -0x5c);
}



/* VA 10002753 */

undefined4 FUN_10002753(void)

{
  undefined4 local_8;

  local_8 = 0xf003f;
  if ((DAT_10041700 != '\0') && (DAT_1003a6b8 == 0)) {
    local_8 = 0x20019;
  }
  return local_8;
}



/* VA 10002780 */

undefined4 __fastcall FUN_10002780(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined3 extraout_var;
  int *extraout_EAX;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar4;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined1 *local_3c;
  undefined4 local_38;
  int local_34;
  undefined1 *local_30;
  int local_2c;
  undefined4 local_28;
  LPCSTR local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_100322d6;
  local_10 = ExceptionList;
  local_20 = 0;
  ExceptionList = &local_10;
  FUN_10002250(&local_1c);
  local_8 = 0;
  FUN_1000234f();
  if (DAT_10041700 != '\0') {
    DAT_1003a6b8 = FUN_100024d8();
  }
  *(undefined4 *)(param_1 + 0xee8) = 0;
  *(undefined4 *)(param_1 + 0xeec) = 1;
  *(undefined4 *)(param_1 + 0xef0) = 1;
  *(undefined4 *)(param_1 + 0xefc) = 0;
  *(undefined4 *)(param_1 + 0xed8) = 0;
  *(undefined4 *)(param_1 + 0xee4) = 1;
  *(undefined4 *)(param_1 + 0xf00) = 0;
  *(undefined4 *)(param_1 + 0xf10) = 0;
  *(undefined4 *)(param_1 + 0xed0) = 0;
  *(undefined4 *)(param_1 + 0xed4) = 0;
  *(undefined4 *)(param_1 + 0xec8) = 1;
  *(undefined4 *)(param_1 + 0xecc) = 1;
  *(undefined4 *)(param_1 + 0xed0) = 1;
  if (DAT_100416fc == 0) {
    DAT_100416f8 = (int *)0x0;
  }
  else {
    DAT_100416f8 = (int *)FUN_1001f4c1(s_c__test_txt_1003a750,&DAT_1003a74e);
    if (DAT_100416f8 == (int *)0x0) {
      FUN_10030703(s_Can_t_open__C__test_txt__for_wri_1003a778,0,0);
    }
    else {
      FUN_1001f240(DAT_100416f8,(byte *)s_3DSetup_Table_Version___d_1003a75c);
    }
  }
  *(undefined4 *)(param_1 + 0xec4) = 0;
  uVar2 = FUN_10003eeb();
  *(undefined4 *)(param_1 + 0xf04) = uVar2;
  if (*(int *)(param_1 + 0xf04) == 3) {
    *(undefined4 *)(param_1 + 0xf08) = 1;
  }
  else {
    uVar2 = FUN_10003fc2();
    *(undefined4 *)(param_1 + 0xf08) = uVar2;
  }
  if (*(int *)(param_1 + 0xf08) == 0) {
    *(undefined4 *)(param_1 + 0xef4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0xef4) = 1;
  }
  local_14 = FUN_1000a9c4();
  if (local_14 == 1) {
    *(undefined4 *)(param_1 + 0xef8) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0xef8) = 0;
  }
  local_30 = &stack0xffffff44;
  FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
  piVar3 = FUN_10004080(&local_34);
  local_8._0_1_ = 1;
  FUN_1002b255((void *)(param_1 + 0xf1c),piVar3);
  local_8._0_1_ = 0;
  FUN_1002b168(&local_34);
  bVar1 = FUN_10002210((int *)(param_1 + 0xf1c));
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = FUN_10009cc6(&local_1c);
    *(undefined4 *)(param_1 + 0xf14) = uVar2;
    local_3c = &stack0xffffff44;
    FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
    FUN_1000a448(&local_40);
    local_8._0_1_ = 2;
    FUN_1002b255((void *)(param_1 + 0x1028),extraout_EAX);
    local_8._0_1_ = 0;
    FUN_1002b168(&local_40);
    bVar1 = FUN_10002210((int *)(param_1 + 0x1028));
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      FUN_10002250(&local_18);
      local_8 = CONCAT31(local_8._1_3_,3);
      local_24 = (LPCSTR)FUN_1001f90c((uchar *)s_THRASH_DRIVERNAME_1003a7a0);
      if (local_24 != (LPCSTR)0x0) {
        SetEnvironmentVariableA(s_THRASH_DRIVERNAME_1003a7b4,(LPCSTR)0x0);
      }
      piVar3 = FUN_100087c8(&local_48);
      local_8._0_1_ = 4;
      FUN_1002b255((void *)(param_1 + 0x1038),piVar3);
      local_8._0_1_ = 3;
      FUN_1002b168(&local_48);
      bVar1 = FUN_10002210((int *)(param_1 + 0x1038));
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        *(undefined4 *)(param_1 + 0xf0c) = 0;
        FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
        local_14 = FUN_10004d08();
        FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
        FUN_10004ad3();
        FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
        FUN_1000591d();
      }
      else {
        FUN_10002250(&local_2c);
        local_8 = CONCAT31(local_8._1_3_,5);
        *(undefined4 *)(param_1 + 0xf0c) = 1;
        FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
        local_28 = FUN_10004d08();
        FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
        FUN_100093cc();
        FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
        FUN_10004ad3();
        FUN_1002aedd(&stack0xffffff44,(int *)(param_1 + 0x1044));
        FUN_1000591d();
        iVar4 = FUN_10002270(param_1 + 0x6c4);
        if (iVar4 == 0) {
          FUN_1002b2a5(&local_2c,s_640x480_1003a7c8);
        }
        else {
          piVar3 = (int *)FUN_100022f0(param_1 + 0x6c4);
          FUN_1002b255(&local_2c,piVar3);
        }
        FUN_1002aedd(&stack0xffffff44,&local_2c);
        FUN_10008d91(0,0);
        local_8._0_1_ = 3;
        FUN_1002b168(&local_2c);
      }
      if (local_24 != (LPCSTR)0x0) {
        SetEnvironmentVariableA(s_THRASH_DRIVERNAME_1003a7d0,local_24);
      }
      if (DAT_100416fc != 0) {
        FUN_10002d14();
      }
      uVar2 = local_20;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168(&local_18);
      local_8 = 0xffffffff;
      FUN_1002b168(&local_1c);
    }
    else {
      local_20 = 0xffffffff;
      local_44 = 0xffffffff;
      local_8 = 0xffffffff;
      FUN_1002b168(&local_1c);
      uVar2 = local_44;
    }
  }
  else {
    local_20 = 0xffffffff;
    local_38 = 0xffffffff;
    local_8 = 0xffffffff;
    FUN_1002b168(&local_1c);
    uVar2 = local_38;
  }
  ExceptionList = local_10;
  return uVar2;
}



/* VA 10002d14 */

undefined4 FUN_10002d14(void)

{
  undefined4 uVar1;
  HKEY pHVar2;
  LSTATUS LVar3;
  int *piVar4;
  LPCSTR pCVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_15c4;
  int local_15c0;
  undefined4 local_15bc;
  LPCSTR local_15b8;
  int local_15b4;
  undefined1 local_15b0 [2];
  undefined4 auStackY_15ae [64];
  HKEY local_14ac;
  undefined1 local_14a8 [2];
  undefined4 auStackY_14a6 [63];
  int local_13a8;
  undefined4 local_13a4;
  uint local_13a0 [65];
  HKEY local_129c;
  HKEY local_1298;
  int local_1294;
  undefined1 local_1290 [2];
  undefined4 auStackY_128e [63];
  DWORD local_1190;
  HKEY local_118c;
  undefined1 local_1188 [2];
  undefined4 auStackY_1186 [63];
  undefined2 local_1088;
  undefined4 local_1086 [64];
  HKEY local_f84;
  int local_f80;
  int local_f7c;
  undefined4 local_f78;
  int local_f74;
  int local_f70;
  int local_f6c;
  uint *local_f68;
  char *local_f64;
  char *local_f60;
  int local_f5c;
  undefined2 local_f58;
  undefined4 local_f56;
  int aiStackY_554 [129];
  int local_350;
  int local_34c;
  undefined2 local_348;
  undefined4 local_346 [64];
  char *local_244;
  uint local_240;
  char *local_23c;
  uint local_238 [65];
  DWORD local_134;
  undefined2 local_130;
  undefined4 local_12e [54];
  undefined4 uStackY_54;
  HKEY pHVar8;
  char *pcVar9;
  char *pcVar10;
  HKEY__ HVar11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1003230d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001fa90();
  local_f68 = (uint *)s_SOFTWARE_Electronic_Arts_3DSetup_1003a7e4;
  local_f64 = s_SOFTWARE_Electronic_Arts_3DSetup_1003a808;
  local_240 = DAT_1004180c;
  local_14ac = (HKEY)(uint)DAT_10041812;
  _local_1188 = CONCAT22((undefined2)auStackY_1186[0],DAT_10041814);
  puVar7 = (undefined4 *)(local_1188 + 2);
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  _local_14a8 = CONCAT22((undefined2)auStackY_14a6[0],DAT_10041816);
  puVar7 = (undefined4 *)(local_14a8 + 2);
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  _local_15b0 = (char *)CONCAT22((undefined2)auStackY_15ae[0],DAT_10041818);
  puVar7 = (undefined4 *)(local_15b0 + 2);
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  _local_1290 = (char *)CONCAT22((undefined2)auStackY_128e[0],DAT_1004181a);
  puVar7 = (undefined4 *)(local_1290 + 2);
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  local_1088 = DAT_1004181c;
  puVar7 = local_1086;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  local_348 = DAT_1004181e;
  puVar7 = local_346;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  local_f58 = DAT_10041820;
  puVar7 = &local_f56;
  for (iVar6 = 0x280; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  *(undefined1 *)((int)puVar7 + 2) = 0;
  local_130 = DAT_10041822;
  puVar7 = local_12e;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  FUN_10002250((undefined4 *)&stack0xffffffd0);
  local_8 = 0;
  local_134 = 0x100;
  local_1190 = 4;
  local_f78 = 0;
  local_13a4 = 0;
  local_1294 = 0;
  pHVar2 = (HKEY)FUN_10002753();
  if (DAT_100416f8 == (int *)0x0) {
    local_15bc = 0xffffffff;
    local_8 = 0xffffffff;
    FUN_1002b168((int *)&stack0xffffffd0);
    ExceptionList = local_10;
    return local_15bc;
  }
  if (DAT_100416f8 != (int *)0x0) {
    FUN_1001f240(DAT_100416f8,(byte *)s_Scanning_for_Duplicates_in_Regis_1003a834);
  }
  if (((DAT_100415b4 < 1) || (DAT_100415a4 == 0)) || (DAT_100415a8 == 0)) {
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,(byte *)s_Can_t_scan_OS_incompatible_1003ad8c);
    }
  }
  else {
    LVar3 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)local_f68,0,(REGSAM)pHVar2,&local_f84);
    if (LVar3 != 0) {
      FUN_10002250(&local_15b4);
      local_8._0_1_ = 1;
      FormatMessageA(0x1300,(LPCVOID)0x0,0,0x400,(LPSTR)&local_15b8,0,(va_list *)0x0);
      FUN_1002b2a5(&local_15b4,local_15b8);
      piVar4 = (int *)FUN_1002b3b1();
      local_8._0_1_ = 2;
      FUN_1002b255(&local_15b4,piVar4);
      local_8._0_1_ = 1;
      FUN_1002b168(&local_15c0);
      piVar4 = (int *)FUN_1002b3b1();
      local_8._0_1_ = 3;
      FUN_1002b255(&local_15b4,piVar4);
      local_8._0_1_ = 1;
      FUN_1002b168(&local_15c4);
      iVar6 = 0;
      pHVar2 = (HKEY)0x0;
      pCVar5 = (LPCSTR)FUN_10002180(&local_15b4);
      FUN_10030703(pCVar5,(UINT)pHVar2,iVar6);
      LocalFree(local_15b8);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168(&local_15b4);
      local_8 = 0xffffffff;
      FUN_1002b168((int *)&stack0xffffffd0);
      ExceptionList = local_10;
      return 0xfffffffe;
    }
    local_134 = 0x100;
    LVar3 = RegQueryValueExA(local_f84,s_Cards_1003a88c,(LPDWORD)0x0,(LPDWORD)0x0,local_1188,
                             &local_134);
    if (LVar3 != 0) {
      FUN_10030703(s_Error__Could_not_read_number_of_3_1003a894,0,0);
      local_8 = 0xffffffff;
      FUN_1002b168((int *)&stack0xffffffd0);
      ExceptionList = local_10;
      return 0xfffffffd;
    }
    local_350 = _local_1188;
    pHVar8 = pHVar2;
    LVar3 = RegOpenKeyExA((HKEY)0x80000001,local_f64,0,(REGSAM)pHVar2,(PHKEY)&stack0xffffffe4);
    if (LVar3 != 0) {
      FUN_10030703(s_Error__Could_not_read_sort_order_1003a8cc,0,0);
      local_8 = 0xffffffff;
      FUN_1002b168((int *)&stack0xffffffd0);
      ExceptionList = local_10;
      return 0xfffffffc;
    }
    for (local_f7c = 1; local_f7c <= local_350; local_f7c = local_f7c + 1) {
      FUN_1001fa34((undefined1 *)&local_240,&DAT_1003a908);
      FUN_1001f160(&local_240,(uint *)&DAT_10041824);
      pHVar8 = (HKEY)&stack0xffffffe0;
      HVar11.unused = 0;
      LVar3 = RegQueryValueExA(pHVar8,(LPCSTR)&local_240,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)pHVar8,
                               &local_1190);
      if (LVar3 != 0) {
        FUN_10030703(s_Error_in_reading_sort_order__1003a90c,0,0);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0xffffffd0);
        ExceptionList = local_10;
        return 0xfffffffb;
      }
      aiStackY_554[local_f7c] = HVar11.unused;
      local_f74 = HVar11.unused;
    }
    RegCloseKey(pHVar8);
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,(byte *)s_Sort_Order__1003a92c);
    }
    for (local_f7c = 1; local_f7c <= local_350; local_f7c = local_f7c + 1) {
      local_1294 = 0;
      if (DAT_100416f8 != (int *)0x0) {
        FUN_1001f240(DAT_100416f8,&DAT_1003a93c);
      }
    }
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,&DAT_1003a942);
    }
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,(byte *)s_Check_for_gaps__1003a944);
    }
    for (local_f7c = 1; local_f7c <= local_350; local_f7c = local_f7c + 1) {
      local_1294 = 0;
      for (local_f6c = 0; local_f6c < local_350; local_f6c = local_f6c + 1) {
        if (aiStackY_554[local_f6c + 1] == local_f7c) {
          FUN_1001f240(DAT_100416f8,&DAT_1003a958);
          local_1294 = 1;
          break;
        }
      }
      if ((DAT_100416f8 != (int *)0x0) && (local_1294 == 0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_<**_d_NOT_FOUND>_1003a960);
      }
    }
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,&DAT_1003a972);
    }
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,(byte *)s_Scan_for_invalid_sort_data_1003a974);
    }
    for (local_f6c = 0; local_f6c < local_350; local_f6c = local_f6c + 1) {
      if (aiStackY_554[local_f6c + 1] < 1) {
        FUN_1001f240(DAT_100416f8,(byte *)s___d____TOO_SMALL__d_1003a990);
        break;
      }
      if (local_350 < aiStackY_554[local_f6c + 1]) {
        FUN_1001f240(DAT_100416f8,(byte *)s___d____TOO_BIG__d_1003a9a8);
        break;
      }
    }
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,&DAT_1003a9bc);
    }
    for (local_13a8 = 0; local_13a8 < local_350; local_13a8 = local_13a8 + 1) {
      FUN_1001f150(local_13a0,local_f68);
      FUN_1001f160(local_13a0,(uint *)s__Card_1003a9c0);
      FUN_1001fa34((undefined1 *)&local_240,&DAT_1003a9c8);
      FUN_1001f160(&local_240,(uint *)&DAT_10041826);
      FUN_1001f160(local_13a0,&local_240);
      LVar3 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)local_13a0,0,(REGSAM)pHVar2,&local_129c);
      if (LVar3 != 0) {
        FUN_10030703(s_Error__Could_not_open__Cards__re_1003a9cc,0,0);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0xffffffd0);
        ExceptionList = local_10;
        return 0xfffffffa;
      }
      local_134 = 0x100;
      LVar3 = RegQueryValueExA(local_129c,&DAT_1003a9f8,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_348
                               ,&local_134);
      if (LVar3 != 0) {
        FUN_10030703(s_Error__Could_not_get__Name__regi_1003aa00,0,0);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0xffffffd0);
        ExceptionList = local_10;
        return 0xfffffff9;
      }
      local_134 = 4;
      LVar3 = RegQueryValueExA(local_129c,s_Types_1003aa2c,(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)&local_14ac,&local_134);
      if (LVar3 != 0) {
        FUN_10030703(s_Error__Could_not_get__Types__reg_1003aa34,0,0);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0xffffffd0);
        ExceptionList = local_10;
        return 0xfffffff8;
      }
      pHVar8 = local_14ac;
      for (local_f5c = 0; local_f5c < (int)pHVar8; local_f5c = local_f5c + 1) {
        FUN_1001f150(local_238,local_13a0);
        FUN_1001f160(local_238,(uint *)s__Type_1003aa64);
        FUN_1001fa34((undefined1 *)&local_240,&DAT_1003aa6c);
        FUN_1001f160(&local_240,(uint *)&DAT_10041828);
        FUN_1001f160(local_238,&local_240);
        LVar3 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)local_238,0,(REGSAM)pHVar2,&local_118c);
        if (LVar3 != 0) {
          FUN_10030703(s_Error__Could_not_open__Types__re_1003aa70,0,0);
          local_8 = 0xffffffff;
          FUN_1002b168((int *)&stack0xffffffd0);
          ExceptionList = local_10;
          return 0xfffffff7;
        }
        local_134 = 0x100;
        LVar3 = RegQueryValueExA(local_118c,s_VendorID_1003aa9c,(LPDWORD)0x0,(LPDWORD)0x0,local_14a8
                                 ,&local_134);
        if (LVar3 != 0) {
          FUN_10030703(s_Error__Could_not_get__VendorID__r_1003aaa8,0,0);
          local_8 = 0xffffffff;
          FUN_1002b168((int *)&stack0xffffffd0);
          ExceptionList = local_10;
          return 0xfffffff6;
        }
        local_f70 = _local_14a8;
        local_134 = 0x100;
        LVar3 = RegQueryValueExA(local_118c,s_DeviceID1_1003aad8,(LPDWORD)0x0,(LPDWORD)0x0,
                                 local_15b0,&local_134);
        if ((LVar3 != 0) &&
           (LVar3 = RegQueryValueExA(local_118c,s_DeviceID_1003aae4,(LPDWORD)0x0,(LPDWORD)0x0,
                                     local_15b0,&local_134), LVar3 != 0)) {
          FUN_10030703(s_Error__Could_not_get__DeviceID1__1003aaf0,0,0);
          local_8 = 0xffffffff;
          FUN_1002b168((int *)&stack0xffffffd0);
          ExceptionList = local_10;
          return 0xfffffff5;
        }
        local_244 = _local_15b0;
        local_134 = 0x100;
        pHVar8 = local_118c;
        LVar3 = RegQueryValueExA(local_118c,s_DeviceID2_1003ab24,(LPDWORD)0x0,(LPDWORD)0x0,
                                 local_1290,&local_134);
        pcVar9 = _local_1290;
        if (LVar3 != 0) {
          pcVar9 = local_244;
        }
        for (local_23c = local_244; (int)local_23c <= (int)pcVar9; local_23c = local_23c + 1) {
          for (local_1298 = (HKEY)0x0; (int)local_1298 < local_350;
              local_1298 = (HKEY)((int)&local_1298->unused + 1)) {
            FUN_1001f150(local_13a0,local_f68);
            FUN_1001f160(local_13a0,(uint *)s__Card_1003ab30);
            FUN_1001fa34((undefined1 *)&local_240,&DAT_1003ab38);
            FUN_1001f160(&local_240,(uint *)&DAT_1004182a);
            FUN_1001f160(local_13a0,&local_240);
            LVar3 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)local_13a0,0,(REGSAM)pHVar2,&local_129c);
            if (LVar3 != 0) {
              FUN_10030703(s_Error__Could_not_open__Cards__re_1003ab3c,0,0);
              local_8 = 0xffffffff;
              FUN_1002b168((int *)&stack0xffffffd0);
              ExceptionList = local_10;
              return 0xfffffff4;
            }
            local_134 = 0x100;
            LVar3 = RegQueryValueExA(local_129c,&DAT_1003ab68,(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)&local_1088,&local_134);
            if (LVar3 != 0) {
              FUN_10030703(s_Error__Could_not_get__Name__regi_1003ab70,0,0);
              local_8 = 0xffffffff;
              FUN_1002b168((int *)&stack0xffffffd0);
              ExceptionList = local_10;
              return 0xfffffff3;
            }
            local_134 = 4;
            pcVar9 = s_Types_1003ab9c;
            LVar3 = RegQueryValueExA(local_129c,s_Types_1003ab9c,(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)&local_14ac,&local_134);
            if (LVar3 != 0) {
              FUN_10030703(s_Error__Could_not_get__Types__reg_1003aba4,0,0);
              local_8 = 0xffffffff;
              FUN_1002b168((int *)&stack0xffffffd0);
              ExceptionList = local_10;
              return 0xfffffff2;
            }
            pHVar8 = local_14ac;
            for (local_34c = 0; local_34c < (int)pHVar8; local_34c = local_34c + 1) {
              FUN_1001f150(local_238,local_13a0);
              FUN_1001f160(local_238,(uint *)s__Type_1003abd4);
              FUN_1001fa34((undefined1 *)&local_240,&DAT_1003abdc);
              FUN_1001f160(&local_240,(uint *)&DAT_1004182c);
              FUN_1001f160(local_238,&local_240);
              LVar3 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)local_238,0,(REGSAM)pHVar2,&local_118c)
              ;
              if (LVar3 != 0) {
                FUN_10030703(s_Error__Could_not_open__Types__re_1003abe0,0,0);
                local_8 = 0xffffffff;
                FUN_1002b168((int *)&stack0xffffffd0);
                ExceptionList = local_10;
                return 0xfffffff1;
              }
              local_134 = 0x100;
              pcVar9 = s_VendorID_1003ac0c;
              pHVar8 = local_118c;
              LVar3 = RegQueryValueExA(local_118c,s_VendorID_1003ac0c,(LPDWORD)0x0,(LPDWORD)0x0,
                                       local_14a8,&local_134);
              if (LVar3 != 0) {
                FUN_10030703(s_Error__Could_not_get__VendorID__r_1003ac18,0,0);
                local_8 = 0xffffffff;
                FUN_1002b168((int *)&stack0xffffffd0);
                ExceptionList = local_10;
                return 0xfffffff0;
              }
              local_f80 = _local_14a8;
              if ((_local_14a8 == 0) &&
                 (iVar6 = _strcmp((char *)&local_1088,s_Software_Renderer_1003ac48), iVar6 != 0)) {
                FUN_1001f240(DAT_100416f8,(byte *)s_VendorID_is_zero___s__1003ac5c);
                break;
              }
              local_134 = 0x100;
              LVar3 = RegQueryValueExA(local_118c,s_DeviceID1_1003ac74,(LPDWORD)0x0,(LPDWORD)0x0,
                                       local_15b0,&local_134);
              if ((LVar3 != 0) &&
                 (LVar3 = RegQueryValueExA(local_118c,s_DeviceID_1003ac80,(LPDWORD)0x0,(LPDWORD)0x0,
                                           local_15b0,&local_134), LVar3 != 0)) {
                FUN_10030703(s_Error__Could_not_get__DeviceID1__1003ac8c,0,0);
                local_8 = 0xffffffff;
                FUN_1002b168((int *)&stack0xffffffd0);
                ExceptionList = local_10;
                return 0xffffffef;
              }
              local_134 = 0x100;
              pcVar10 = (char *)0x0;
              pcVar9 = s_DeviceID2_1003acc0;
              pHVar8 = local_118c;
              LVar3 = RegQueryValueExA(local_118c,s_DeviceID2_1003acc0,(LPDWORD)0x0,(LPDWORD)0x0,
                                       local_1290,&local_134);
              local_f60 = pcVar10;
              if (LVar3 == 0) {
                local_f60 = _local_1290;
              }
              if ((((local_f70 == local_f80) && ((int)pcVar10 <= (int)local_23c)) &&
                  ((int)local_23c <= (int)local_f60)) &&
                 (iVar6 = _strcmp((char *)&local_348,(char *)&local_1088), iVar6 != 0)) {
                local_13a4 = 1;
                pcVar9 = (char *)aiStackY_554[(int)((int)&local_1298->unused + 1)];
                uStackY_54 = 0x10003e61;
                pHVar8 = local_1298;
                FUN_1001f240(DAT_100416f8,(byte *)s_Duplicate_Match__<sort__d>__d____1003acd0);
                break;
              }
            }
          }
        }
      }
    }
  }
  if (DAT_100416f8 != (int *)0x0) {
    FUN_1001f240(DAT_100416f8,(byte *)s_End_of_Scan_1003ada8);
  }
  uVar1 = local_13a4;
  local_8 = 0xffffffff;
  FUN_1002b168((int *)&stack0xffffffd0);
  ExceptionList = local_10;
  return uVar1;
}



/* VA 10003eeb */

/* WARNING: Removing unreachable block (ram,0x10003fb4) */

undefined4 FUN_10003eeb(void)

{
  BOOL BVar1;
  _OSVERSIONINFOA local_ac;
  undefined4 local_8;

  _memset(&local_ac,0,0x9c);
  local_ac.dwOSVersionInfoSize = 0x9c;
  BVar1 = GetVersionExA(&local_ac);
  if (BVar1 == 0) {
    local_ac.dwOSVersionInfoSize = 0x94;
    BVar1 = GetVersionExA(&local_ac);
    if (BVar1 == 0) {
      return 0xffffffff;
    }
  }
  if (local_ac.dwPlatformId == 2) {
    if (local_ac.dwMajorVersion < 5) {
      if (local_ac.dwMajorVersion == 4) {
        local_8 = 0xfffffffd;
      }
      else {
        local_8 = 0xfffffffe;
      }
    }
    else {
      local_8 = 3;
    }
  }
  else if (local_ac.dwMinorVersion < 10) {
    local_8 = 1;
  }
  else {
    local_8 = 2;
  }
  return local_8;
}



/* VA 10003fc2 */

undefined4 FUN_10003fc2(void)

{
  BOOL BVar1;
  LPVOID local_24;
  DWORD local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  char *local_10;
  undefined *local_c;
  DWORD local_8;

  local_10 = s_ddraw_dll_1003adb8;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = GetFileVersionInfoSizeA(s_ddraw_dll_1003adb8,&local_20);
  if (local_8 != 0) {
    local_c = _malloc(local_8);
    if (local_c != (undefined *)0x0) {
      BVar1 = GetFileVersionInfoA(local_10,local_20,local_8,local_c);
      if (BVar1 != 0) {
        BVar1 = VerQueryValueA(local_c,&DAT_1003adc2,&local_24,(PUINT)0x0);
        if (BVar1 != 0) {
          local_1c = *(uint *)((int)local_24 + 8) >> 0x10;
          local_18 = *(uint *)((int)local_24 + 8) & 0xffff;
          if ((3 < local_1c) && (5 < local_18)) {
            local_14 = 1;
          }
        }
      }
      FUN_1001fabf(local_c);
    }
  }
  return local_14;
}



/* VA 10004080 */

void * __cdecl FUN_10004080(void *param_1)

{
  bool bVar1;
  LPCSTR pCVar2;
  int iVar3;
  undefined3 extraout_var;
  void *pvVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  int local_68;
  int local_64;
  int local_60;
  undefined1 local_59 [5];
  int local_54;
  CStdioFile local_50 [20];
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c [5];
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_100323a3;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_1002b3b1();
  local_8._0_1_ = 2;
  FUN_1002b3b1();
  local_8._0_1_ = 4;
  FUN_1002b168((int *)(local_59 + 1));
  FUN_1002b1d6(&local_14,s_RegistryKey__1003add4);
  local_8._0_1_ = 5;
  local_54 = 0;
  FUN_1002b651((undefined4 *)local_50);
  local_8._0_1_ = 6;
  FUN_1001e150(local_2c,0,0xffffffff,(LPCSTR)0x0);
  local_8._0_1_ = 7;
  FUN_10002250(&local_3c);
  local_8._0_1_ = 8;
  FUN_10002250(&local_38);
  local_8._0_1_ = 9;
  FUN_10002250(&local_34);
  local_8._0_1_ = 10;
  FUN_10002250(&local_18);
  local_8._0_1_ = 0xb;
  puVar7 = local_2c;
  uVar6 = 0;
  pCVar2 = (LPCSTR)FUN_10002180(&local_30);
  iVar3 = FUN_1002b6c6(local_50,pCVar2,uVar6,(int)puVar7);
  if (iVar3 != 0) {
    while ((bVar1 = FUN_1002b8a9(local_50,&local_3c), CONCAT31(extraout_var,bVar1) != 0 &&
           (local_54 == 0))) {
      pbVar8 = &DAT_1003ade2;
      pvVar4 = (void *)FUN_1002a0f5();
      local_8._0_1_ = 0xc;
      bVar1 = FUN_10002230(pvVar4,pbVar8);
      local_59[0] = bVar1;
      local_8._0_1_ = 0xb;
      FUN_1002b168(&local_60);
      if ((local_59._0_4_ & 0xff) == 0) {
        FUN_100021d0(&local_14);
        piVar5 = (int *)FUN_1002a0f5();
        local_8._0_1_ = 0xd;
        FUN_1002b255(&local_18,piVar5);
        local_8._0_1_ = 0xb;
        FUN_1002b168(&local_64);
        pbVar8 = (byte *)FUN_10002180(&local_14);
        iVar3 = FUN_100022b0(&local_18,pbVar8);
        if (iVar3 == 0) {
          local_54 = 1;
          FUN_1002b255(&local_38,&local_3c);
        }
      }
    }
    if (local_54 == 0) {
      FUN_10030703(s_Error__Invalid_3dsetup_ini___Reg_1003ade4,0,0);
      FUN_1002b0f3(&local_34);
    }
    else {
      FUN_100021d0(&local_38);
      FUN_100021d0(&local_14);
      piVar5 = (int *)FUN_1002a079();
      local_8._0_1_ = 0xe;
      FUN_1002b255(&local_34,piVar5);
      local_8._0_1_ = 0xb;
      FUN_1002b168(&local_68);
    }
    FUN_1002b9f6((int)local_50);
  }
  FUN_1002aedd(param_1,&local_34);
  local_8._0_1_ = 10;
  FUN_1002b168(&local_18);
  local_8._0_1_ = 9;
  FUN_1002b168(&local_34);
  local_8._0_1_ = 8;
  FUN_1002b168(&local_38);
  local_8._0_1_ = 7;
  FUN_1002b168(&local_3c);
  local_8._0_1_ = 6;
  FUN_1001e260(local_2c);
  local_8._0_1_ = 5;
  CStdioFile::~CStdioFile(local_50);
  local_8._0_1_ = 4;
  FUN_1002b168(&local_14);
  local_8._0_1_ = 1;
  FUN_1002b168(&local_30);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168((int *)&stack0x00000008);
  ExceptionList = local_10;
  return param_1;
}



/* VA 10004343 */

undefined4 FUN_10004343(int param_1,void *param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int local_8;

  FUN_10002250(&local_8);
  FUN_1002a515(&local_8,(byte *)s__dx_d_1003ae10);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_EnumModes___4d_x_4d_x_3d_1003ae18);
  }
  puVar2 = (undefined4 *)0x0;
  pbVar1 = (byte *)FUN_10002180(&local_8);
  puVar2 = FUN_1002a86c(param_2,pbVar1,puVar2);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(uint *)(param_1 + 0x54) < DAT_1003a6b0) {
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_REJECTED___INSUFFICENT_COLOURS_1003ae3c);
      }
    }
    else {
      AddTail(param_2,&local_8);
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_ADDED_1003ae34);
      }
    }
  }
  else if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_REJECTED___RESOLUTION_ALREADY_AV_1003ae5c);
  }
  FUN_1002b168(&local_8);
  return 1;
}



/* VA 10004473 */

undefined4 FUN_10004473(int param_1)

{
  char *_Str2;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint local_e3c;
  int *local_e38;
  undefined4 local_e34;
  uint local_e30;
  int local_cb0;
  undefined1 local_cac [512];
  CHAR local_aac [520];
  int local_8a4;
  int local_8a0;
  undefined1 local_884 [28];
  int local_868;
  undefined1 local_864 [512];
  char local_664 [520];
  undefined4 local_45c;
  undefined4 local_458;
  int local_438;
  undefined1 local_434;
  undefined4 local_433;
  int *local_8;

  local_e38 = (int *)0x0;
  local_434 = 0;
  puVar3 = &local_433;
  for (iVar2 = 0x109; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  FUN_10002250(&local_438);
  FUN_1002a6aa(local_884,10);
  local_868 = 0;
  local_cb0 = DirectDrawCreate(param_1,&local_8,0);
  if (local_cb0 == 0) {
    local_cb0 = (**(code **)*local_8)(local_8,&DAT_100343ec,&local_e38);
    if (local_cb0 == 0) {
      iVar2 = 0;
      if (local_868 == 0) {
        _memset(&local_e34,0,0x17c);
        local_e34 = 0x17c;
        local_e30 = 0;
        (**(code **)(*local_e38 + 0x2c))(local_e38,&local_e34,0);
        local_e3c = (uint)((local_e30 & 1) != 0);
        if ((DAT_100416f8 != (int *)0x0) && (local_e3c != 0)) {
          FUN_1001f240(DAT_100416f8,(byte *)s_DIRECTX__D3D_detected_1003ae88);
        }
        local_cb0 = (**(code **)(*local_e38 + 0x6c))(local_e38,local_864,0);
        local_cb0 = (**(code **)(*local_e38 + 0x6c))(local_e38,local_cac,1);
        if (DAT_100416f8 != (int *)0x0) {
          FUN_1001f240(DAT_100416f8,(byte *)s_DIRECTX__lpDriverDescription_____1003aea0);
        }
        if ((local_8a4 == 0) && (local_8a0 == 0)) {
          if (DAT_100416f8 != (int *)0x0) {
            FUN_1001f240(DAT_100416f8,(byte *)s_REJECTED__Vendor_ID_and_Device_I_1003aee8);
          }
          FUN_1002a71e();
          FUN_1002b168(&local_438);
          return 1;
        }
        if (DAT_10041570 == 0) {
          if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
            FUN_1001f240(DAT_100416f8,(byte *)s_Primary_device_found_1003af14);
          }
          DAT_10041570 = 1;
          FUN_1002b2a5(&DAT_100416d4,local_aac);
          FUN_1002b2a5(&DAT_100406b4 + DAT_10041568 * 100,local_aac);
          *(int *)(&DAT_100406b8 + DAT_10041568 * 100) = local_8a4;
          *(int *)(&DAT_100406bc + DAT_10041568 * 100) = local_8a0;
          *(int *)(&DAT_100406c0 + DAT_10041568 * 100) = DAT_10041568;
          *(undefined4 *)(&DAT_100406ec + DAT_10041568 * 100) = 0;
          *(undefined4 *)(&DAT_100406f0 + DAT_10041568 * 100) = 0;
          *(uint *)(&DAT_100406b0 + DAT_10041568 * 100) = local_e3c;
          FUN_1002a6e9((int)(&DAT_100406f8 + DAT_10041568 * 100));
          (**(code **)(*local_e38 + 0x20))
                    (local_e38,2,0,&DAT_100406f8 + DAT_10041568 * 100,FUN_10004343);
          DAT_10041568 = DAT_10041568 + 1;
          iVar2 = local_cb0;
        }
        else {
          _Str2 = (char *)FUN_10002180((undefined4 *)&DAT_100416d4);
          iVar2 = _strcmp(local_664,_Str2);
          if (iVar2 == 0) {
            if ((DAT_1004156c == 0) || (param_1 == 0)) {
              iVar2 = local_cb0;
              if (param_1 != 0) {
                if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                  FUN_1001f240(DAT_100416f8,(byte *)s_Primary_device_found__lpGUID__1003af2c);
                }
                DAT_1004156c = 1;
                iVar2 = local_cb0;
              }
            }
            else {
              if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                FUN_1001f240(DAT_100416f8,(byte *)s_similar_to_primary_device_1003af4c);
              }
              FUN_1002b2a5(&DAT_100406b4 + DAT_10041568 * 100,local_664);
              *(undefined4 *)(&DAT_100406b8 + DAT_10041568 * 100) = local_45c;
              *(undefined4 *)(&DAT_100406bc + DAT_10041568 * 100) = local_458;
              *(int *)(&DAT_100406c0 + DAT_10041568 * 100) = DAT_10041568;
              *(undefined4 *)(&DAT_100406ec + DAT_10041568 * 100) = 0;
              *(undefined4 *)(&DAT_100406f0 + DAT_10041568 * 100) = 0;
              *(uint *)(&DAT_100406b0 + DAT_10041568 * 100) = local_e3c;
              FUN_1002a6e9((int)(&DAT_100406f8 + DAT_10041568 * 100));
              (**(code **)(*local_e38 + 0x20))
                        (local_e38,2,0,&DAT_100406f8 + DAT_10041568 * 100,FUN_10004343);
              DAT_10041568 = DAT_10041568 + 1;
              iVar2 = local_cb0;
            }
          }
          else {
            if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
              FUN_1001f240(DAT_100416f8,(byte *)s_not_primary_device_1003af68);
            }
            FUN_1002b2a5(&DAT_100406b4 + DAT_10041568 * 100,local_664);
            *(undefined4 *)(&DAT_100406b8 + DAT_10041568 * 100) = local_45c;
            *(undefined4 *)(&DAT_100406bc + DAT_10041568 * 100) = local_458;
            *(int *)(&DAT_100406c0 + DAT_10041568 * 100) = DAT_10041568;
            *(undefined4 *)(&DAT_100406ec + DAT_10041568 * 100) = 0;
            *(undefined4 *)(&DAT_100406f0 + DAT_10041568 * 100) = 0;
            *(uint *)(&DAT_100406b0 + DAT_10041568 * 100) = local_e3c;
            FUN_1002a6e9((int)(&DAT_100406f8 + DAT_10041568 * 100));
            (**(code **)(*local_e38 + 0x20))
                      (local_e38,2,0,&DAT_100406f8 + DAT_10041568 * 100,FUN_10004343);
            DAT_10041568 = DAT_10041568 + 1;
            iVar2 = local_cb0;
          }
        }
      }
      local_cb0 = iVar2;
      if (local_8 != (int *)0x0) {
        local_cb0 = (**(code **)(*local_8 + 8))(local_8);
      }
      if (local_e38 != (int *)0x0) {
        local_cb0 = (**(code **)(*local_e38 + 8))(local_e38);
      }
      FUN_1002a71e();
      FUN_1002b168(&local_438);
      uVar1 = 1;
    }
    else {
      FUN_1002a71e();
      FUN_1002b168(&local_438);
      uVar1 = 0;
    }
  }
  else {
    FUN_1002a71e();
    FUN_1002b168(&local_438);
    uVar1 = 0;
  }
  return uVar1;
}



/* VA 10004ad3 */

void FUN_10004ad3(void)

{
  int local_138;
  undefined1 local_134 [28];
  CHAR local_118 [260];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_100323cb;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_10002250(&local_14);
  local_8._0_1_ = 1;
  FUN_1002a6aa(local_134,10);
  local_8 = CONCAT31(local_8._1_3_,2);
  DAT_10041568 = 0;
  DAT_1004156c = 0;
  DAT_10041570 = 0;
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_ATTACHED_SECONDARY_DEVICES_1003af7c);
  }
  DirectDrawEnumerateExA(FUN_10004473,0,1);
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_ATTACHED_NO_DISPLAY_DEVICES_1003af98);
  }
  DirectDrawEnumerateExA(FUN_10004473,0,4);
  if (DAT_100416fc != 0) {
    FUN_1001fa34(local_118,(byte *)s_num_cards____d_1003afb8);
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,&DAT_1003afc8);
    }
    for (local_138 = 0; local_138 < DAT_10041568; local_138 = local_138 + 1) {
      FUN_1002b255(&local_14,(int *)(&DAT_100406b4 + local_138 * 100));
      FUN_1001fa34(local_118,(byte *)s_bIsD3D___d__VendorID__0x_04x__De_1003afcc);
      FUN_1002b4f8(&local_14,local_118);
      if (DAT_100416f8 != (int *)0x0) {
        FUN_1001f240(DAT_100416f8,&DAT_1003b00c);
      }
    }
    if (DAT_100416f8 != (int *)0x0) {
      FUN_1001f240(DAT_100416f8,(byte *)s_______________________1003b010);
    }
  }
  local_8._0_1_ = 1;
  FUN_1002a71e();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168(&local_14);
  local_8 = 0xffffffff;
  FUN_1002b168((int *)&stack0x00000004);
  ExceptionList = local_10;
  return;
}



/* VA 10004d08 */

undefined4 FUN_10004d08(void)

{
  bool bVar1;
  LPCSTR pCVar2;
  int iVar3;
  int *piVar4;
  undefined3 extraout_var;
  void *pvVar5;
  undefined4 uVar6;
  void *this;
  void *this_00;
  void *this_01;
  void *this_02;
  void *this_03;
  void *this_04;
  void *this_05;
  void *this_06;
  void *this_07;
  void *this_08;
  void *this_09;
  void *this_10;
  uint uVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  int local_84;
  int local_80;
  int local_7c;
  undefined1 local_75 [5];
  int local_70;
  int local_6c;
  CStdioFile local_68 [20];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44 [5];
  undefined4 local_30 [5];
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_1003245c;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_1002b3b1();
  local_8._0_1_ = 1;
  FUN_1002b3b1();
  local_8._0_1_ = 3;
  FUN_1002b168(&local_70);
  FUN_1002b1d6(&local_48,s_ListType__1003b038);
  local_8._0_1_ = 4;
  FUN_1002a92e(local_44);
  local_8._0_1_ = 5;
  local_6c = 0;
  FUN_1002b651((undefined4 *)local_68);
  local_8._0_1_ = 6;
  FUN_1001e150(local_30,0,0xffffffff,(LPCSTR)0x0);
  local_8._0_1_ = 7;
  FUN_10002250(&local_54);
  local_8._0_1_ = 8;
  FUN_10002250(&local_1c);
  local_8._0_1_ = 9;
  FUN_10002250(&local_18);
  local_8._0_1_ = 10;
  FUN_10002250(&local_14);
  local_8._0_1_ = 0xb;
  Add(local_44,s_ListType__1003b044);
  Add(local_44,s_3Dfx__1003b050);
  Add(local_44,&DAT_1003b058);
  Add(local_44,s_3Dfx_D3D__1003b060);
  Add(local_44,s_3Dfx_TB__1003b06c);
  Add(local_44,s_D3D_TB__1003b078);
  Add(local_44,s_Test__1003b080);
  Add(local_44,s_TB_Button__1003b088);
  Add(local_44,s_CARD_ALL_1003b094);
  Add(local_44,s_Hide_Resolutions__1003b0a0);
  Add(local_44,s_3Dfx_DXOnly__1003b0b4);
  Add(local_44,s_Default_Button__1003b0c4);
  DAT_1004158c = 99;
  DAT_10041590 = 99;
  puVar8 = local_30;
  uVar7 = 0;
  pCVar2 = (LPCSTR)FUN_10002180(&local_4c);
  iVar3 = FUN_1002b6c6(local_68,pCVar2,uVar7,(int)puVar8);
  if (iVar3 == 0) {
    FUN_10030703(s_Error__Could_not_open_3dsetup_in_1003b1d0,0,0);
    local_8._0_1_ = 10;
    FUN_1002b168(&local_14);
    local_8._0_1_ = 9;
    FUN_1002b168(&local_18);
    local_8._0_1_ = 8;
    FUN_1002b168(&local_1c);
    local_8._0_1_ = 7;
    FUN_1002b168(&local_54);
    local_8._0_1_ = 6;
    FUN_1001e260(local_30);
    local_8._0_1_ = 5;
    CStdioFile::~CStdioFile(local_68);
    local_8._0_1_ = 4;
    FUN_1002a961();
    local_8._0_1_ = 3;
    FUN_1002b168(&local_48);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1002b168(&local_4c);
    local_8 = 0xffffffff;
    FUN_1002b168((int *)&stack0x00000004);
    uVar6 = 0;
  }
  else {
    local_50 = 0;
    while (iVar3 = FUN_1001e2c0((int)local_44), local_50 < iVar3) {
      local_6c = 0;
      FUN_1001e350((int *)local_68);
      piVar4 = FUN_1001e2e0(local_44,local_75 + 1,local_50);
      local_8._0_1_ = 0xc;
      FUN_1002b255(&local_48,piVar4);
      local_8._0_1_ = 0xb;
      FUN_1002b168((int *)(local_75 + 1));
      do {
        do {
          bVar1 = FUN_1002b8a9(local_68,&local_54);
          if ((CONCAT31(extraout_var,bVar1) == 0) || (local_6c != 0)) goto LAB_10005010;
          pbVar9 = &DAT_1003b0d4;
          pvVar5 = (void *)FUN_1002a0f5();
          local_8._0_1_ = 0xd;
          bVar1 = FUN_10002230(pvVar5,pbVar9);
          local_75[0] = bVar1;
          local_8._0_1_ = 0xb;
          FUN_1002b168(&local_7c);
        } while ((local_75._0_4_ & 0xff) != 0);
        FUN_100021d0(&local_48);
        piVar4 = (int *)FUN_1002a0f5();
        local_8._0_1_ = 0xe;
        FUN_1002b255(&local_14,piVar4);
        local_8._0_1_ = 0xb;
        FUN_1002b168(&local_80);
        pbVar9 = (byte *)FUN_10002180(&local_48);
        iVar3 = FUN_100022b0(&local_14,pbVar9);
      } while (iVar3 != 0);
      local_6c = 1;
      FUN_1002b255(&local_1c,&local_54);
LAB_10005010:
      if (local_6c == 0) {
        bVar1 = FUN_10002230(&local_48,(byte *)s_ListType__1003b0d8);
        if (bVar1) {
          DAT_10041578 = 1;
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_3Dfx__1003b0e4);
        if (bVar1) {
          DAT_1004157c = 1;
        }
        bVar1 = FUN_10002230(&local_48,&DAT_1003b0ec);
        if (bVar1) {
          DAT_10041580 = 1;
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_3Dfx_D3D__1003b0f4);
        if (bVar1) {
          DAT_10041584 = 0;
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_3Dfx_TB__1003b100);
        if (bVar1) {
          DAT_1004158c = 0;
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_D3D_TB__1003b10c);
        if (bVar1) {
          DAT_10041590 = 0;
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_Test__1003b114);
        if (bVar1) {
          DAT_10041598 = 0;
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_TB_Button__1003b11c);
        if (bVar1) {
          DAT_1004159c = 1;
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_Default_Button__1003b128);
        if (bVar1) {
          DAT_100415a0 = 1;
        }
      }
      else {
        FUN_100021d0(&local_1c);
        FUN_100021d0(&local_48);
        piVar4 = (int *)FUN_1002a079();
        local_8._0_1_ = 0xf;
        FUN_1002b255(&local_18,piVar4);
        local_8._0_1_ = 0xb;
        FUN_1002b168(&local_84);
        bVar1 = FUN_10002230(&local_48,(byte *)s_ListType__1003b138);
        if (bVar1) {
          bVar1 = FUN_10002230(&local_18,(byte *)s_Include_1003b144);
          if (bVar1) {
            DAT_10041578 = 0;
          }
          else {
            DAT_10041578 = 1;
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_3Dfx__1003b14c);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this,pbVar9);
          if (iVar3 == 0) {
            DAT_1004157c = 0;
          }
          else {
            DAT_1004157c = 1;
          }
        }
        bVar1 = FUN_10002230(&local_48,&DAT_1003b154);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_00,pbVar9);
          if (iVar3 == 0) {
            DAT_10041580 = 0;
          }
          else {
            DAT_10041580 = 1;
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_3Dfx_D3D__1003b15c);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_01,pbVar9);
          if (iVar3 == 0) {
            DAT_10041584 = 0;
          }
          else {
            DAT_10041584 = 1;
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_3Dfx_TB__1003b168);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_02,pbVar9);
          if (iVar3 == 0) {
            DAT_1004158c = 0;
          }
          else {
            pbVar9 = (byte *)FUN_10002180(&local_18);
            iVar3 = FUN_1001fd6d(this_03,pbVar9);
            if (iVar3 == 1) {
              DAT_1004158c = 1;
            }
            else {
              DAT_1004158c = 99;
            }
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_D3D_TB__1003b174);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_04,pbVar9);
          if (iVar3 == 0) {
            DAT_10041590 = 0;
          }
          else {
            pbVar9 = (byte *)FUN_10002180(&local_18);
            iVar3 = FUN_1001fd6d(this_05,pbVar9);
            if (iVar3 == 1) {
              DAT_10041590 = 1;
            }
            else {
              DAT_10041590 = 99;
            }
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_Test__1003b17c);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_06,pbVar9);
          if (iVar3 == 0) {
            DAT_10041598 = 0;
          }
          else {
            DAT_10041598 = 1;
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_TB_Button__1003b184);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_07,pbVar9);
          if (iVar3 == 0) {
            DAT_1004159c = 0;
          }
          else {
            DAT_1004159c = 1;
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_Hide_Resolutions__1003b190);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_08,pbVar9);
          if (iVar3 == 1) {
            DAT_10041594 = 0;
          }
          else {
            DAT_10041594 = 1;
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_3Dfx_DXOnly__1003b1a4);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_09,pbVar9);
          if (iVar3 == 1) {
            DAT_10041588 = 1;
          }
          else {
            DAT_10041588 = 0;
          }
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_CARD_ALL_1003b1b4);
        if (bVar1) {
          FUN_1002aedd(&stack0xffffff3c,&local_1c);
          FUN_10005639();
        }
        bVar1 = FUN_10002230(&local_48,(byte *)s_Default_Button__1003b1c0);
        if (bVar1) {
          pbVar9 = (byte *)FUN_10002180(&local_18);
          iVar3 = FUN_1001fd6d(this_10,pbVar9);
          if (iVar3 == 0) {
            DAT_100415a0 = 0;
          }
          else {
            DAT_100415a0 = 1;
          }
        }
      }
      local_50 = local_50 + 1;
    }
    FUN_1002b9f6((int)local_68);
    local_8._0_1_ = 10;
    FUN_1002b168(&local_14);
    local_8._0_1_ = 9;
    FUN_1002b168(&local_18);
    local_8._0_1_ = 8;
    FUN_1002b168(&local_1c);
    local_8._0_1_ = 7;
    FUN_1002b168(&local_54);
    local_8._0_1_ = 6;
    FUN_1001e260(local_30);
    local_8._0_1_ = 5;
    CStdioFile::~CStdioFile(local_68);
    local_8._0_1_ = 4;
    FUN_1002a961();
    local_8._0_1_ = 3;
    FUN_1002b168(&local_48);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1002b168(&local_4c);
    local_8 = 0xffffffff;
    FUN_1002b168((int *)&stack0x00000004);
    uVar6 = 1;
  }
  ExceptionList = local_10;
  return uVar6;
}



/* VA 10005639 */

void FUN_10005639(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int *piVar3;
  void *this;
  void *this_00;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_100324b7;
  local_10 = ExceptionList;
  local_8 = 0;
  local_1c = 0;
  ExceptionList = &local_10;
  FUN_10002250(&local_14);
  local_8._0_1_ = 1;
  FUN_10002250(&local_20);
  local_8._0_1_ = 2;
  local_24 = FUN_1002a18f(&stack0x00000004,&DAT_1003b1f4);
  if (-1 < local_24) {
    puVar1 = (undefined4 *)FUN_10029fc0(&local_28);
    local_8._0_1_ = 3;
    pbVar2 = (byte *)FUN_10002180(puVar1);
    DAT_1003a6b0 = FUN_1001fd6d(this,pbVar2);
    local_8._0_1_ = 2;
    FUN_1002b168(&local_28);
  }
  local_24 = FUN_1002a18f(&stack0x00000004,&DAT_1003b1f8);
  if (-1 < local_24) {
    puVar1 = (undefined4 *)FUN_10029fc0(&local_2c);
    local_8._0_1_ = 4;
    pbVar2 = (byte *)FUN_10002180(puVar1);
    DAT_1003a6b4 = FUN_1001fd6d(this_00,pbVar2);
    local_8._0_1_ = 2;
    FUN_1002b168(&local_2c);
  }
  local_24 = FUN_1002a18f(&stack0x00000004,&DAT_1003b200);
  if (-1 < local_24) {
    FUN_1002b255(&local_14,(int *)&stack0x00000004);
    while (local_1c == 0) {
      local_24 = FUN_1002a18f(&local_14,&DAT_1003b204);
      if (local_24 < 0) {
        local_1c = 1;
      }
      else {
        piVar3 = (int *)FUN_10029fc0(&local_30);
        local_8._0_1_ = 5;
        FUN_1002b255(&local_14,piVar3);
        local_8._0_1_ = 2;
        FUN_1002b168(&local_30);
        local_18 = FUN_1002b5ce(&local_14,0x20);
        if (local_18 < 0) {
          piVar3 = (int *)FUN_10029fc0(&local_34);
          local_8._0_1_ = 6;
          FUN_1002b255(&local_20,piVar3);
          local_8._0_1_ = 2;
          FUN_1002b168(&local_34);
          AddTail(&DAT_1004154c,&local_20);
          local_1c = 1;
          if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
            FUN_1001f240(DAT_100416f8,(byte *)s_ALL_ADD_Resolution___s_1003b208);
          }
        }
        else {
          piVar3 = (int *)FUN_10029fe3();
          local_8._0_1_ = 7;
          FUN_1002b255(&local_20,piVar3);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1002b168(&local_38);
          if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
            FUN_1001f240(DAT_100416f8,(byte *)s_ALL_ADD_Resolution___s_1003b220);
          }
          AddTail(&DAT_1004154c,&local_20);
          piVar3 = (int *)FUN_10029fc0(&local_3c);
          local_8._0_1_ = 8;
          FUN_1002b255(&local_14,piVar3);
          local_8._0_1_ = 2;
          FUN_1002b168(&local_3c);
        }
      }
    }
  }
  local_8._0_1_ = 1;
  FUN_1002b168(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168(&local_14);
  local_8 = 0xffffffff;
  FUN_1002b168((int *)&stack0x00000004);
  ExceptionList = local_10;
  return;
}



/* VA 1000591d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000591d(void)

{
  bool bVar1;
  REGSAM samDesired;
  LSTATUS LVar2;
  int *piVar3;
  int *piVar4;
  undefined3 extraout_var;
  int iVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int *extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  HKEY extraout_ECX_08;
  HKEY extraout_ECX_09;
  int extraout_ECX_10;
  int extraout_ECX_11;
  int extraout_ECX_12;
  HKEY extraout_ECX_13;
  int extraout_ECX_14;
  HKEY extraout_ECX_15;
  int extraout_ECX_16;
  int extraout_ECX_17;
  undefined4 extraout_ECX_18;
  int extraout_ECX_19;
  HKEY extraout_ECX_20;
  int extraout_ECX_21;
  undefined4 extraout_ECX_22;
  HKEY extraout_ECX_23;
  undefined4 *puVar6;
  undefined2 local_14b0;
  undefined4 auStackY_14ae [64];
  uint local_13ac;
  undefined1 local_13a8 [2];
  undefined4 auStackY_13a6 [63];
  int local_12a8;
  int local_12a4;
  uint local_12a0 [64];
  HKEY local_11a0;
  int local_119c;
  int local_1198;
  undefined4 local_1194;
  undefined1 local_1190 [2];
  undefined4 auStackY_118e [64];
  DWORD local_108c;
  HKEY local_1088;
  int local_1084;
  undefined1 local_1080 [2];
  undefined4 auStackY_107e [63];
  undefined2 local_f80;
  undefined4 local_f7e [64];
  HKEY local_e7c;
  undefined4 local_e78;
  uint *local_e74;
  uint *local_e70;
  HKEY local_e6c;
  undefined2 local_e68;
  undefined4 local_e66;
  int local_45c [129];
  uint local_258;
  int local_254;
  uint local_250 [67];
  DWORD local_144;
  int *local_140;
  int local_13c;
  undefined2 local_138;
  undefined4 local_136 [64];
  int local_34;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  uint *lpValueName;
  HKEY pHVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_1003260b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001fa90();
  local_8 = 0;
  local_e70 = (uint *)s_SOFTWARE_Electronic_Arts_3DSetup_1003b238;
  local_e6c = (HKEY)s_SOFTWARE_Electronic_Arts_3DSetup_1003b25c;
  local_250[0] = DAT_10041830;
  local_13ac = (uint)DAT_10041836;
  _local_1080 = CONCAT22((undefined2)auStackY_107e[0],DAT_10041838);
  puVar6 = (undefined4 *)(local_1080 + 2);
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  _local_13a8 = CONCAT22((undefined2)auStackY_13a6[0],DAT_1004183a);
  puVar6 = (undefined4 *)(local_13a8 + 2);
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  _local_14b0 = CONCAT22((undefined2)auStackY_14ae[0],DAT_1004183c);
  puVar6 = auStackY_14ae;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  _local_1190 = (int *)CONCAT22((undefined2)auStackY_118e[0],DAT_1004183e);
  puVar6 = (undefined4 *)(local_1190 + 2);
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  local_f80 = DAT_10041840;
  puVar6 = local_f7e;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  local_e68 = DAT_10041842;
  puVar6 = &local_e66;
  for (iVar5 = 0x280; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  local_138 = DAT_10041844;
  puVar6 = local_136;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  FUN_10002250(&local_34);
  local_8._0_1_ = 1;
  local_144 = 0x100;
  local_108c = 4;
  local_45c[0] = 0;
  local_e78 = 0;
  samDesired = FUN_10002753();
  iVar5 = extraout_ECX;
  if (((0 < DAT_100415b4) && (DAT_100415a4 != 0)) && (DAT_100415a8 != 0)) {
    LVar2 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)local_e70,0,samDesired,&local_e7c);
    if (LVar2 != 0) {
      FUN_10030703(s_Error__Could_not_open_3D_Data_re_1003b288,0,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168(&local_34);
      local_8 = 0xffffffff;
      FUN_1002b168((int *)&stack0x00000004);
      ExceptionList = local_10;
      return 0xffffffff;
    }
    LVar2 = RegQueryValueExA(local_e7c,s_Cards_1003b2b4,(LPDWORD)0x0,(LPDWORD)0x0,local_1080,
                             &local_144);
    if (LVar2 != 0) {
      FUN_10030703(s_Error__Could_not_read_number_of_3_1003b2bc,0,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168(&local_34);
      local_8 = 0xffffffff;
      FUN_1002b168((int *)&stack0x00000004);
      ExceptionList = local_10;
      return 0xfffffffe;
    }
    local_1198 = _local_1080;
    pHVar10 = local_e6c;
    LVar2 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)local_e6c,0,samDesired,(PHKEY)&stack0xffffffdc);
    if (LVar2 != 0) {
      FUN_10030703(s_Error__Could_not_read_sort_order_1003b2f4,0,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168(&local_34);
      local_8 = 0xffffffff;
      FUN_1002b168((int *)&stack0x00000004);
      ExceptionList = local_10;
      return 0xfffffffd;
    }
    for (local_13c = 1; local_13c <= local_1198; local_13c = local_13c + 1) {
      FUN_1001fa34((undefined1 *)local_250,&DAT_1003b330);
      FUN_1001f160(local_250,(uint *)&DAT_10041846);
      pHVar10 = (HKEY)0x0;
      lpValueName = local_250;
      LVar2 = RegQueryValueExA((HKEY)0x0,(LPCSTR)lpValueName,(LPDWORD)0x0,(LPDWORD)0x0,
                               &stack0xffffffd8,&local_108c);
      if (LVar2 != 0) {
        FUN_10030703(s_Error_in_reading_sort_order__1003b334,0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1002b168(&local_34);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0x00000004);
        ExceptionList = local_10;
        return 0xfffffffc;
      }
      local_45c[local_13c] = (int)lpValueName;
      local_e74 = lpValueName;
    }
    RegCloseKey(pHVar10);
    local_12a4 = 0;
    iVar5 = extraout_ECX_00;
    for (local_13c = 0; local_13c < local_1198; local_13c = local_13c + 1) {
      FUN_1001f150(local_12a0,local_e70);
      FUN_1001f160(local_12a0,(uint *)s__Card_1003b354);
      FUN_1001fa34((undefined1 *)local_250,&DAT_1003b35c);
      FUN_1001f160(local_250,(uint *)&DAT_10041848);
      FUN_1001f160(local_12a0,local_250);
      LVar2 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)local_12a0,0,samDesired,&local_11a0);
      if (LVar2 != 0) {
        FUN_10030703(s_Error__Could_not_open__Cards__re_1003b360,0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1002b168(&local_34);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0x00000004);
        ExceptionList = local_10;
        return 0xfffffffb;
      }
      local_144 = 0x100;
      LVar2 = RegQueryValueExA(local_11a0,&DAT_1003b38c,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_f80
                               ,&local_144);
      if (LVar2 != 0) {
        FUN_10030703(s_Error__Could_not_get__Name__regi_1003b394,0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1002b168(&local_34);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0x00000004);
        ExceptionList = local_10;
        return 0xfffffffa;
      }
      local_144 = 0xa05;
      LVar2 = RegQueryValueExA(local_11a0,s_Module_1003b3c0,(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)&local_e68,&local_144);
      if (LVar2 != 0) {
        FUN_10030703(s_Error__Could_not_get__Module__re_1003b3c8,0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1002b168(&local_34);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0x00000004);
        ExceptionList = local_10;
        return 0xfffffff9;
      }
      local_144 = 0x100;
      LVar2 = RegQueryValueExA(local_11a0,s_Group_1003b3f8,(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)&local_138,&local_144);
      if (LVar2 != 0) {
        FUN_10030703(s_Error__Could_not_get__Group__reg_1003b400,0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1002b168(&local_34);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0x00000004);
        ExceptionList = local_10;
        return 0xfffffff8;
      }
      local_144 = 4;
      LVar2 = RegQueryValueExA(local_11a0,s_Types_1003b430,(LPDWORD)0x0,(LPDWORD)0x0,
                               (LPBYTE)&local_13ac,&local_144);
      if (LVar2 != 0) {
        FUN_10030703(s_Error__Could_not_get__Types__reg_1003b438,0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1002b168(&local_34);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0x00000004);
        ExceptionList = local_10;
        return 0xfffffff7;
      }
      local_258 = local_13ac;
      for (piVar12 = (int *)0x0; (int)piVar12 < (int)local_258; piVar12 = (int *)((int)piVar12 + 1))
      {
        if (local_45c[0] == 0) {
          FUN_1001f150(local_250 + 2,local_12a0);
          FUN_1001f160(local_250 + 2,(uint *)s__Type_1003b468);
          FUN_1001fa34((undefined1 *)local_250,&DAT_1003b470);
          FUN_1001f160(local_250,(uint *)&DAT_1004184a);
          FUN_1001f160(local_250 + 2,local_250);
          LVar2 = RegOpenKeyExA((HKEY)0x80000001,(LPCSTR)(local_250 + 2),0,samDesired,&local_1088);
          if (LVar2 != 0) {
            FUN_10030703(s_Error__Could_not_open__Types__re_1003b474,0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_1002b168(&local_34);
            local_8 = 0xffffffff;
            FUN_1002b168((int *)&stack0x00000004);
            ExceptionList = local_10;
            return 0xfffffff6;
          }
          local_144 = 0x100;
          LVar2 = RegQueryValueExA(local_1088,s_VendorID_1003b4a0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   local_13a8,&local_144);
          if (LVar2 != 0) {
            FUN_10030703(s_Error__Could_not_get__VendorID__r_1003b4ac,0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_1002b168(&local_34);
            local_8 = 0xffffffff;
            FUN_1002b168((int *)&stack0x00000004);
            ExceptionList = local_10;
            return 0xfffffff5;
          }
          local_1084 = _local_13a8;
          local_144 = 0x100;
          LVar2 = RegQueryValueExA(local_1088,s_DeviceID1_1003b4dc,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)&local_14b0,&local_144);
          if ((LVar2 != 0) &&
             (LVar2 = RegQueryValueExA(local_1088,s_DeviceID_1003b4e8,(LPDWORD)0x0,(LPDWORD)0x0,
                                       (LPBYTE)&local_14b0,&local_144), LVar2 != 0)) {
            FUN_10030703(s_Error__Could_not_get__DeviceID1__1003b4f4,0,0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_1002b168(&local_34);
            local_8 = 0xffffffff;
            FUN_1002b168((int *)&stack0x00000004);
            ExceptionList = local_10;
            return 0xfffffff4;
          }
          local_144 = 0x100;
          piVar12 = (int *)local_1190;
          piVar7 = (int *)0x10006254;
          LVar2 = RegQueryValueExA(local_1088,s_DeviceID2_1003b528,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)piVar12,&local_144);
          local_140 = piVar7;
          if (LVar2 == 0) {
            local_140 = _local_1190;
          }
          for (pcVar8 = (char *)0x0; (int)pcVar8 < DAT_10041568; pcVar8 = (char *)((int)pcVar8 + 1))
          {
            local_119c = 0;
            local_250[1] = 0;
            local_1194 = 0;
            if (((local_1084 == *(int *)(&DAT_100406b8 + (int)pcVar8 * 100)) &&
                ((int)piVar7 <= *(int *)(&DAT_100406bc + (int)pcVar8 * 100))) &&
               (*(int *)(&DAT_100406bc + (int)pcVar8 * 100) <= (int)local_140)) {
              if (local_1084 == 0x121a) {
                if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                  FUN_1001f240(DAT_100416f8,(byte *)s_>>>>>>>>>>>>>>>3dfx_Card_Detecte_1003b534);
                }
                local_119c = 1;
              }
              if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                pcVar8 = s_MATCH___DEVICE_ENTRY__d__Vendor__1003b558;
                local_34 = 0x10006379;
                piVar7 = DAT_100416f8;
                FUN_1001f240(DAT_100416f8,(byte *)s_MATCH___DEVICE_ENTRY__d__Vendor__1003b558);
              }
              local_250[1] = 1;
              if ((local_119c == 0) || (DAT_10041588 == 0)) {
                FUN_1002b2a5(&DAT_100406c4 + (int)pcVar8 * 100,(LPCSTR)&local_e68);
              }
              else {
                FUN_1002b2a5(&DAT_100406c4 + (int)pcVar8 * 100,&DAT_1003b5a8);
              }
              FUN_1002b2a5(&DAT_100406c8 + (int)pcVar8 * 100,(LPCSTR)&local_138);
              *(undefined4 *)(&DAT_100406cc + (int)pcVar8 * 100) = DAT_1003a6b4;
              if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                FUN_1001f240(DAT_100416f8,(byte *)s_Setting_TB_value_to_CARD_ALL_s_d_1003b5ac);
              }
              piVar12 = (int *)((int)pcVar8 * 100);
              piVar12[0x40101bb] = 0;
              *(undefined4 *)(&DAT_100406f0 + (int)pcVar8 * 100) = 1;
              piVar4 = &local_12a8;
              FUN_1002aedd(&stack0xffffffe4,(int *)&stack0x00000004);
              local_8._0_1_ = 2;
              piVar3 = extraout_ECX_01;
              FUN_1002b1d6(&stack0xffffffe0,(LPCSTR)&local_f80);
              local_8._0_1_ = 1;
              iVar5 = FUN_1000731c(piVar3,piVar12,piVar4);
              if (iVar5 == 0) {
                piVar3 = FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
                local_8._0_1_ = 3;
                piVar12 = (int *)pcVar8;
                pHVar10 = (HKEY)FUN_1002aedd(&stack0xffffffe0,
                                             (int *)(&DAT_100406b4 + (int)pcVar8 * 100));
                local_8._0_1_ = 4;
                pcVar8 = (char *)0x10006511;
                FUN_1002b1d6(&stack0xffffffdc,(LPCSTR)&local_f80);
                local_8._0_1_ = 1;
                FUN_1000742e((int)pHVar10,piVar3,(int)piVar12);
                local_1194 = 1;
              }
              local_254 = 0;
              if (((local_1084 == 0x121a) || (local_1084 == 0x1142)) || (local_1084 == 0x20d9)) {
                if ((0 < *(int *)(&DAT_100406bc + (int)pcVar8 * 100)) &&
                   (*(int *)(&DAT_100406bc + (int)pcVar8 * 100) < 3)) {
                  local_254 = 1;
                }
                if ((0x643c < *(int *)(&DAT_100406bc + (int)pcVar8 * 100)) &&
                   (*(int *)(&DAT_100406bc + (int)pcVar8 * 100) < 0x643e)) {
                  local_254 = 1;
                }
                if ((0x8625 < *(int *)(&DAT_100406bc + (int)pcVar8 * 100)) &&
                   (*(int *)(&DAT_100406bc + (int)pcVar8 * 100) < 0x8627)) {
                  local_254 = 1;
                }
              }
              if (((local_119c != 0) && (DAT_10041584 != 0)) && (local_254 == 0)) {
                FUN_1002b2a5(&local_34,(LPCSTR)&local_f80);
                FUN_1002b4f8(&local_34,s__D3D__1003b5d4);
                piVar12 = extraout_ECX_02;
                if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                  FUN_1001f240(DAT_100416f8,(byte *)s__s___3dfx_card_detect_AND_3dfxD3_1003b5dc);
                  FUN_1001f240(DAT_100416f8,(byte *)s_TDSetup_nNumDetectedCards____d_D_1003b614);
                  piVar12 = extraout_ECX_03;
                }
                piVar4 = &local_12a8;
                FUN_1002aedd(&stack0xffffffe4,(int *)&stack0x00000004);
                local_8._0_1_ = 5;
                uVar11 = extraout_ECX_04;
                FUN_1002aedd(&stack0xffffffe0,&local_34);
                local_8._0_1_ = 1;
                iVar5 = FUN_1000731c(uVar11,piVar12,piVar4);
                if (iVar5 == 0) {
                  if (local_12a8 == 0) {
                    piVar4 = &local_12a8;
                    piVar12 = extraout_ECX_05;
                    FUN_1002aedd(&stack0xffffffe4,(int *)&stack0x00000004);
                    local_8._0_1_ = 8;
                    uVar11 = extraout_ECX_06;
                    FUN_1002b1d6(&stack0xffffffe0,(LPCSTR)&local_f80);
                    local_8._0_1_ = 1;
                    iVar5 = FUN_1000731c(uVar11,piVar12,piVar4);
                    if (iVar5 == 0) {
                      piVar4 = FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
                      local_8._0_1_ = 9;
                      piVar12 = (int *)pcVar8;
                      pHVar10 = (HKEY)FUN_1002aedd(&stack0xffffffe0,
                                                   (int *)(&DAT_100406b4 + (int)pcVar8 * 100));
                      local_8._0_1_ = 10;
                      pcVar8 = (char *)0x10006844;
                      FUN_1002b1d6(&stack0xffffffdc,(LPCSTR)&local_f80);
                      local_8._0_1_ = 1;
                      FUN_100077f7((int)pHVar10,piVar4,(int)piVar12);
                    }
                  }
                  else {
                    piVar4 = FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
                    local_8._0_1_ = 6;
                    piVar12 = (int *)pcVar8;
                    pHVar10 = (HKEY)FUN_1002aedd(&stack0xffffffe0,
                                                 (int *)(&DAT_100406b4 + (int)pcVar8 * 100));
                    local_8._0_1_ = 7;
                    pcVar8 = (char *)0x10006753;
                    FUN_1002b1d6(&stack0xffffffdc,(LPCSTR)&local_f80);
                    local_8._0_1_ = 1;
                    FUN_100077f7((int)pHVar10,piVar4,(int)piVar12);
                  }
                }
                piVar3 = (int *)0x1;
                local_1194 = 1;
              }
              if (((*(int *)(&DAT_100406b0 + (int)pcVar8 * 100) == 1) && (local_119c != 0)) &&
                 ((piVar3 == (int *)0x0 && (DAT_10041584 != 0)))) {
                if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                  FUN_1001f240(DAT_100416f8,(byte *)s__s__Card_is_D3D_1003b64c);
                }
                FUN_1002b2a5(&local_34,(LPCSTR)&local_f80);
                FUN_1002b4f8(&local_34,s__D3D__1003b660);
                piVar12 = &local_12a8;
                piVar4 = piVar12;
                FUN_1002aedd(&stack0xffffffe4,(int *)&stack0x00000004);
                local_8._0_1_ = 0xb;
                uVar11 = extraout_ECX_07;
                FUN_1002aedd(&stack0xffffffe0,&local_34);
                local_8._0_1_ = 1;
                iVar5 = FUN_1000731c(uVar11,piVar12,piVar4);
                if (iVar5 == 0) {
                  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                    FUN_1001f240(DAT_100416f8,(byte *)s_Added__s_to_card_list_1003b668);
                  }
                  FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
                  local_8._0_1_ = 0xc;
                  piVar4 = (int *)pcVar8;
                  piVar12 = (int *)pcVar8;
                  FUN_1002aedd(&stack0xffffffe0,(int *)(&DAT_100406b4 + (int)pcVar8 * 100));
                  local_8._0_1_ = 0xd;
                  pcVar8 = (char *)0x100069ec;
                  pHVar10 = extraout_ECX_08;
                  FUN_1002b1d6(&stack0xffffffdc,(LPCSTR)&local_f80);
                  local_8._0_1_ = 1;
                  FUN_100077f7((int)pHVar10,piVar4,(int)piVar12);
                  local_1194 = 1;
                }
              }
              local_12a4 = local_12a4 + 1;
            }
          }
        }
      }
      iVar5 = local_12a4;
      if (local_12a4 == DAT_10041568) break;
    }
    for (iVar9 = 0; iVar9 < DAT_10041568; iVar9 = iVar9 + 1) {
      local_1194 = 0;
      iVar5 = iVar9 * 100;
      if (*(int *)(&DAT_100406f0 + iVar5) == 0) {
        if ((DAT_1004157c != 0) && (*(int *)(&DAT_100406b8 + iVar9 * 100) == 0x121a)) {
          if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
            FUN_1001f240(DAT_100416f8,(byte *)s_Adding_Unknown_3Dfx___s__1003b680);
          }
          FUN_1002b2a5(&DAT_100406c4 + iVar9 * 100,s_voodoo2_1003b69c);
          FUN_1002b2a5(&DAT_100406c8 + iVar9 * 100,&DAT_1003b6a4);
          *(undefined4 *)(&DAT_100406ec + iVar9 * 100) = 0;
          *(undefined4 *)(&DAT_100406f0 + iVar9 * 100) = 0;
          *(undefined4 *)(&DAT_100406cc + iVar9 * 100) = DAT_1004158c;
          if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
            FUN_1001f240(DAT_100416f8,(byte *)s_Setting_TB_value_to_value_set_in_1003b6ac);
          }
          FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
          local_8._0_1_ = 0xe;
          iVar5 = iVar9;
          iVar13 = iVar9;
          FUN_1002aedd(&stack0xffffffe0,(int *)(&DAT_100406b4 + iVar9 * 100));
          local_8._0_1_ = 0xf;
          iVar9 = 0x10006bbd;
          pHVar10 = extraout_ECX_09;
          FUN_1002b1d6(&stack0xffffffdc,s_Unknown_3Dfx_1003b6d8);
          local_8._0_1_ = 1;
          FUN_1000742e((int)pHVar10,iVar5,iVar13);
          local_1194 = 1;
          iVar5 = extraout_ECX_10;
        }
        if ((DAT_10041580 != 0) && (iVar5 = iVar9 * 100, *(int *)(&DAT_100406b0 + iVar5) != 0)) {
          if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
            FUN_1001f240(DAT_100416f8,(byte *)s_Adding_Unknown_D3D___s__1003b6e8);
            iVar5 = extraout_ECX_11;
          }
          iVar13 = *(int *)(&DAT_100406b8 + iVar9 * 100);
          if (iVar13 < 0x121b) {
            if (iVar13 == 0x121a) {
              if (DAT_10041584 != 0) {
                FUN_1002b255(&local_34,(int *)(&DAT_100406b4 + iVar9 * 100));
                FUN_1002b4f8(&local_34,s__D3D__1003b704);
                if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                  FUN_1001f240(DAT_100416f8,(byte *)s__s___b3DfxD3D_and_bUnknown3DfxSu_1003b70c);
                }
                FUN_1002b2a5(&DAT_100406c4 + iVar9 * 100,&DAT_1003b738);
                FUN_1002b2a5(&DAT_100406c8 + iVar9 * 100,&DAT_1003b73c);
                *(undefined4 *)(&DAT_100406cc + iVar9 * 100) = DAT_10041590;
                *(undefined4 *)(&DAT_100406ec + iVar9 * 100) = 0;
                *(undefined4 *)(&DAT_100406f0 + iVar9 * 100) = 1;
                if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                  FUN_1001f240(DAT_100416f8,(byte *)s_Setting_TB_value_to_value_set_in_1003b740);
                }
                piVar12 = FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
                local_8._0_1_ = 0x10;
                iVar5 = DAT_10041568;
                pHVar10 = (HKEY)FUN_1002aedd(&stack0xffffffe0,(int *)(&DAT_100406b4 + iVar9 * 100));
                local_8._0_1_ = 0x11;
                iVar9 = 0x10006dde;
                FUN_1002b1d6(&stack0xffffffdc,s_Unknown_D3D_1003b76c);
                local_8._0_1_ = 1;
                FUN_100077f7((int)pHVar10,piVar12,iVar5);
                iVar5 = extraout_ECX_12;
              }
            }
            else {
              if ((iVar13 == 0x1002) || (iVar13 == 0x10de)) goto LAB_10006df5;
LAB_10006eff:
              FUN_1002b2a5(&DAT_100406c4 + iVar9 * 100,&DAT_1003b7b8);
              FUN_1002b2a5(&DAT_100406c8 + iVar9 * 100,&DAT_1003b7bc);
              *(undefined4 *)(&DAT_100406cc + iVar9 * 100) = DAT_10041590;
              if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                FUN_1001f240(DAT_100416f8,(byte *)s_Setting_TB_value_to_value_set_in_1003b7c0);
              }
              *(undefined4 *)(&DAT_100406ec + iVar9 * 100) = 0;
              *(undefined4 *)(&DAT_100406f0 + iVar9 * 100) = 0;
              FUN_1002b2a5(&DAT_100406b4 + iVar9 * 100,s_D3D_Device_1003b7ec);
              piVar12 = FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
              local_8._0_1_ = 0x14;
              iVar5 = iVar9;
              FUN_1002b1d6(&stack0xffffffe0,s_D3D_Device_1003b7f8);
              local_8._0_1_ = 0x15;
              iVar9 = 0x10007000;
              pHVar10 = extraout_ECX_15;
              FUN_1002b1d6(&stack0xffffffdc,s_Unknown_D3D_1003b804);
              local_8._0_1_ = 1;
              FUN_100077f7((int)pHVar10,piVar12,iVar5);
              iVar5 = extraout_ECX_16;
            }
          }
          else {
            if (iVar13 != 0x12d2) goto LAB_10006eff;
LAB_10006df5:
            FUN_1002b2a5(&DAT_100406c4 + iVar9 * 100,&DAT_1003b778);
            FUN_1002b2a5(&DAT_100406c8 + iVar9 * 100,&DAT_1003b77c);
            *(undefined4 *)(&DAT_100406cc + iVar9 * 100) = DAT_10041590;
            if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
              FUN_1001f240(DAT_100416f8,(byte *)s_Setting_TB_value_to_value_set_in_1003b780);
            }
            *(undefined4 *)(&DAT_100406ec + iVar9 * 100) = 0;
            *(undefined4 *)(&DAT_100406f0 + iVar9 * 100) = 1;
            FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
            local_8._0_1_ = 0x12;
            iVar5 = iVar9;
            iVar13 = iVar9;
            FUN_1002aedd(&stack0xffffffe0,(int *)(&DAT_100406b4 + iVar9 * 100));
            local_8._0_1_ = 0x13;
            iVar9 = 0x10006ee8;
            pHVar10 = extraout_ECX_13;
            FUN_1002b1d6(&stack0xffffffdc,s_Unknown_D3D_1003b7ac);
            local_8._0_1_ = 1;
            FUN_100077f7((int)pHVar10,iVar5,iVar13);
            iVar5 = extraout_ECX_14;
          }
        }
      }
    }
  }
  if (((DAT_100415b4 == 3) &&
      (bVar1 = FUN_1001da65(), iVar5 = extraout_ECX_17, CONCAT31(extraout_var,bVar1) != 0)) &&
     (DAT_10041588 == 0)) {
    piVar12 = &local_12a8;
    piVar7 = piVar12;
    FUN_1002aedd(&stack0xffffffe4,(int *)&stack0x00000004);
    local_8._0_1_ = 0x16;
    uVar11 = extraout_ECX_18;
    FUN_1002b1d6(&stack0xffffffe0,s_Glide_Device_1003b810);
    local_8._0_1_ = 1;
    iVar9 = FUN_1000731c(uVar11,piVar12,piVar7);
    iVar5 = extraout_ECX_19;
    if (iVar9 == 0) {
      FUN_1002b2a5(&DAT_10040c90,s_Glide_Device_1003b820);
      _DAT_10040c9c = 0;
      FUN_1002b2a5(&DAT_10040ca0,s_voodoo2_1003b830);
      FUN_1002b2a5(&DAT_10040ca4,&DAT_1003b838);
      _DAT_10040ca8 = DAT_1003a6b4;
      _DAT_10040ccc = 1;
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_Setting_TB_value_to_value_set_in_1003b840);
      }
      piVar12 = FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
      local_8._0_1_ = 0x17;
      iVar5 = 0xf;
      FUN_1002b1d6(&stack0xffffffe0,s_Glide_Device_1003b878);
      local_8._0_1_ = 0x18;
      pHVar10 = extraout_ECX_20;
      FUN_1002b1d6(&stack0xffffffdc,s_Glide_Device_1003b888);
      local_8._0_1_ = 1;
      FUN_1000742e((int)pHVar10,piVar12,iVar5);
      iVar5 = extraout_ECX_21;
    }
  }
  piVar12 = &local_12a8;
  FUN_1002aedd(&stack0xffffffe4,(int *)&stack0x00000004);
  local_8._0_1_ = 0x19;
  uVar11 = extraout_ECX_22;
  FUN_1002b1d6(&stack0xffffffe0,s_Software_Renderer_1003b898);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar5 = FUN_1000731c(uVar11,iVar5,piVar12);
  if (iVar5 == 0) {
    FUN_1002b2a5(&DAT_10040cf4,s_Software_Renderer_1003b8ac);
    _DAT_10040d00 = 0;
    FUN_1002b2a5(&DAT_10040d04,s_softdraw_1003b8c0);
    FUN_1002b2a5(&DAT_10040d08,s_Software_1003b8cc);
    _DAT_10040d0c = DAT_1003a6b4;
    _DAT_10040d30 = 1;
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_Setting_TB_value_to_value_set_in_1003b8d8);
    }
    piVar12 = FUN_1002aedd(&stack0xffffffe8,(int *)&stack0x00000004);
    local_8._0_1_ = 0x1a;
    iVar5 = 0x10;
    FUN_1002b1d6(&stack0xffffffe0,s_Software_Renderer_1003b910);
    local_8._0_1_ = 0x1b;
    pHVar10 = extraout_ECX_23;
    FUN_1002b1d6(&stack0xffffffdc,s_Software_Renderer_1003b924);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_1000742e((int)pHVar10,piVar12,iVar5);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_1002b168(&local_34);
  local_8 = 0xffffffff;
  FUN_1002b168((int *)&stack0x00000004);
  ExceptionList = local_10;
  return 0;
}



/* VA 1000731c */

undefined4 __cdecl FUN_1000731c(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;

  puStack_c = &LAB_10032639;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  bVar1 = FUN_10002230(&param_1,(byte *)s_Software_Renderer_1003b938);
  if (bVar1) {
    puVar5 = &local_14;
    puVar4 = param_3;
    puVar6 = param_3;
    piVar2 = FUN_1002aedd(&stack0xffffffa8,&param_2);
    local_8._0_1_ = 2;
    iVar3 = DAT_10041568;
    FUN_1002b1d6(&stack0xffffffa0,s_Software_1003b94c);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10007b05(piVar2,iVar3,puVar4,puVar5,puVar6);
  }
  else {
    puVar5 = &local_14;
    puVar4 = param_3;
    puVar6 = param_3;
    piVar2 = FUN_1002aedd(&stack0xffffffa8,&param_2);
    local_8._0_1_ = 3;
    iVar3 = DAT_10041568;
    FUN_1002aedd(&stack0xffffffa0,&param_1);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10007b05(piVar2,iVar3,puVar4,puVar5,puVar6);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_1002b168(&param_1);
  local_8 = 0xffffffff;
  FUN_1002b168(&param_2);
  ExceptionList = local_10;
  return local_14;
}



/* VA 1000742e */

void __cdecl FUN_1000742e(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28 [5];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_10032682;
  local_10 = ExceptionList;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_10002250(&local_34);
  local_8._0_1_ = 3;
  FUN_1002a92e(local_28);
  local_8._0_1_ = 4;
  bVar1 = FUN_10002230(&param_1,(byte *)s_Software_Renderer_1003b958);
  if (bVar1) {
    puVar3 = &local_38;
    puVar7 = &local_2c;
    puVar8 = puVar3;
    piVar2 = FUN_1002aedd(&stack0xffffff90,(int *)&stack0x00000010);
    local_8._0_1_ = 5;
    iVar5 = param_3;
    FUN_1002b1d6(&stack0xffffff88,s_Software_1003b96c);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_10007b05(piVar2,iVar5,puVar3,puVar7,puVar8);
  }
  else {
    puVar3 = &local_38;
    puVar7 = &local_2c;
    puVar8 = puVar7;
    FUN_1002aedd(&stack0xffffff90,(int *)&stack0x00000010);
    local_8._0_1_ = 6;
    iVar5 = param_3;
    iVar6 = param_3;
    FUN_1002aedd(&stack0xffffff88,&param_1);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_10007b05(iVar5,iVar6,puVar7,puVar8,puVar3);
  }
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_<*******************************_1003b978);
    FUN_1001f240(DAT_100416f8,(byte *)s_AddCardToUserList____s____d__Des_1003b9b0);
  }
  FUN_1002b255(&DAT_10040d5c + DAT_10041574 * 0x3c,&param_1);
  FUN_1002b255(&DAT_10040d58 + DAT_10041574 * 0x3c,&param_2);
  *(undefined4 *)(&DAT_10040d54 + DAT_10041574 * 0x3c) =
       *(undefined4 *)(&DAT_100406c0 + param_3 * 100);
  FUN_1002b255(&DAT_10040d60 + DAT_10041574 * 0x3c,(int *)(&DAT_100406c4 + param_3 * 100));
  FUN_1002b255(&DAT_10040d64 + DAT_10041574 * 0x3c,(int *)(&DAT_100406c8 + param_3 * 100));
  *(undefined4 *)(&DAT_10040d68 + DAT_10041574 * 0x3c) =
       *(undefined4 *)(&DAT_100406cc + param_3 * 100);
  *(undefined4 *)(&DAT_10040d6c + DAT_10041574 * 0x3c) =
       *(undefined4 *)(&DAT_100406f0 + param_3 * 100);
  *(undefined4 *)(&DAT_10040d70 + DAT_10041574 * 0x3c) =
       *(undefined4 *)(&DAT_100406f4 + param_3 * 100);
  local_14 = FUN_10002270((int)(&DAT_100406d0 + param_3 * 100));
  if (((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) && (local_14 == 0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_AddCardToUserList__No_detected_r_1003b9dc);
  }
  for (local_30 = 0; local_30 < local_14; local_30 = local_30 + 1) {
    puVar3 = FUN_1002a846(&DAT_100406d0 + param_3 * 100,local_30);
    piVar2 = (int *)FUN_10002290((int)puVar3);
    FUN_1002b255(&local_34,piVar2);
    puVar3 = (undefined4 *)0x0;
    pbVar4 = (byte *)FUN_10002180(&local_34);
    puVar3 = FUN_1002a86c(&DAT_10040d74 + DAT_10041574 * 0x3c,pbVar4,puVar3);
    if (puVar3 == (undefined4 *)0x0) {
      AddTail(&DAT_10040d74 + DAT_10041574 * 0x3c,&local_34);
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_AddCardToUserList__Resolutions___1003ba08);
      }
    }
    else if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_AddCardToUserList__Didn_t_add__s_1003ba2c);
    }
  }
  *(undefined4 *)(&DAT_100406ec + param_3 * 100) = 1;
  DAT_10041574 = DAT_10041574 + 1;
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s__________________________________1003ba60);
  }
  local_8._0_1_ = 3;
  FUN_1002a961();
  local_8._0_1_ = 2;
  FUN_1002b168(&local_34);
  local_8._0_1_ = 1;
  FUN_1002b168(&param_1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168(&param_2);
  local_8 = 0xffffffff;
  FUN_1002b168((int *)&stack0x00000010);
  ExceptionList = local_10;
  return;
}



/* VA 100077f7 */

void __cdecl FUN_100077f7(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_100326b9;
  local_10 = ExceptionList;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_10002250(&local_20);
  local_8._0_1_ = 3;
  puVar1 = &local_24;
  puVar6 = &local_18;
  puVar7 = puVar6;
  FUN_1002aedd(&stack0xffffffb8,(int *)&stack0x00000010);
  local_8._0_1_ = 4;
  iVar4 = param_3;
  iVar5 = param_3;
  FUN_1002aedd(&stack0xffffffb0,&param_1);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10007b05(iVar4,iVar5,puVar6,puVar7,puVar1);
  FUN_1002b4f8(&param_2,s__D3D__1003ba98);
  if (DAT_100416f8 != (int *)0x0) {
    FUN_1001f240(DAT_100416f8,(byte *)s_AddD3DCardToUserList____s____d__D_1003baa0);
  }
  FUN_1002b255(&DAT_10040d5c + DAT_10041574 * 0x3c,&param_1);
  FUN_1002b255(&DAT_10040d58 + DAT_10041574 * 0x3c,&param_2);
  *(undefined4 *)(&DAT_10040d54 + DAT_10041574 * 0x3c) =
       *(undefined4 *)(&DAT_100406c0 + param_3 * 100);
  FUN_1002b2a5(&DAT_10040d60 + DAT_10041574 * 0x3c,&DAT_1003bacc);
  FUN_1002b2a5(&DAT_10040d64 + DAT_10041574 * 0x3c,&DAT_1003bad0);
  *(undefined4 *)(&DAT_10040d68 + DAT_10041574 * 0x3c) =
       *(undefined4 *)(&DAT_100406cc + param_3 * 100);
  *(undefined4 *)(&DAT_10040d6c + DAT_10041574 * 0x3c) =
       *(undefined4 *)(&DAT_100406f0 + param_3 * 100);
  *(undefined4 *)(&DAT_10040d70 + DAT_10041574 * 0x3c) =
       *(undefined4 *)(&DAT_100406f4 + param_3 * 100);
  local_14 = FUN_10002270((int)(&DAT_100406d0 + param_3 * 100));
  if (((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) && (local_14 == 0)) {
    FUN_1001f240(DAT_100416f8,(byte *)s_AddCardToUserList__No_detected_r_1003bad4);
  }
  for (local_1c = 0; local_1c < local_14; local_1c = local_1c + 1) {
    puVar1 = FUN_1002a846(&DAT_100406d0 + param_3 * 100,local_1c);
    piVar2 = (int *)FUN_10002290((int)puVar1);
    FUN_1002b255(&local_20,piVar2);
    puVar1 = (undefined4 *)0x0;
    pbVar3 = (byte *)FUN_10002180(&local_20);
    puVar1 = FUN_1002a86c(&DAT_10040d74 + DAT_10041574 * 0x3c,pbVar3,puVar1);
    if (puVar1 == (undefined4 *)0x0) {
      AddTail(&DAT_10040d74 + DAT_10041574 * 0x3c,&local_20);
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_AddD3DCardToUserList__Resolution_1003bb00);
      }
    }
    else if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_AddD3DCardToUserList__didn_t_add_1003bb28);
    }
  }
  *(undefined4 *)(&DAT_100406ec + param_3 * 100) = 1;
  DAT_10041574 = DAT_10041574 + 1;
  local_8._0_1_ = 2;
  FUN_1002b168(&local_20);
  local_8._0_1_ = 1;
  FUN_1002b168(&param_1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168(&param_2);
  local_8 = 0xffffffff;
  FUN_1002b168((int *)&stack0x00000010);
  ExceptionList = local_10;
  return;
}



/* VA 10007b05 */

undefined4 __cdecl
FUN_10007b05(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  bool bVar2;
  LPCSTR pCVar3;
  int iVar4;
  undefined3 extraout_var;
  void *pvVar5;
  int *piVar6;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined1 *puVar7;
  uint uVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  int local_108;
  undefined1 *local_104;
  undefined1 *local_100;
  int local_fc;
  undefined1 *local_f8;
  undefined1 *local_f4;
  int local_f0;
  undefined1 *local_ec;
  undefined1 *local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  undefined1 local_bd [5];
  int local_b8;
  undefined1 local_b1 [5];
  CStdioFile local_ac [20];
  int local_98;
  int local_94;
  int *local_90;
  undefined4 local_8c;
  undefined1 local_88 [28];
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  uint local_54;
  undefined4 local_50 [5];
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_10032852;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_1002b3b1();
  local_8._0_1_ = 2;
  FUN_1002b3b1();
  local_8._0_1_ = 4;
  FUN_1002b168((int *)(local_b1 + 1));
  FUN_1002b651((undefined4 *)local_ac);
  local_8._0_1_ = 5;
  FUN_1001e150(local_50,0,0xffffffff,(LPCSTR)0x0);
  local_8._0_1_ = 6;
  local_6c = 0;
  FUN_1002b1d6(&local_3c,s_CARD__1003bb70);
  local_8._0_1_ = 7;
  FUN_10002250(&local_98);
  local_8._0_1_ = 8;
  FUN_10002250(&local_94);
  local_8._0_1_ = 9;
  FUN_10002250(&local_58);
  local_8._0_1_ = 10;
  FUN_10002250(&local_68);
  local_8._0_1_ = 0xb;
  FUN_10002250(&local_1c);
  local_8._0_1_ = 0xc;
  FUN_10002250(&local_64);
  local_8._0_1_ = 0xd;
  FUN_1002a6aa(local_88,10);
  local_8._0_1_ = 0xe;
  FUN_1002b3b1();
  local_8._0_1_ = 0xf;
  FUN_1002b3b1();
  local_8._0_1_ = 0x10;
  FUN_1002b3b1();
  local_8._0_1_ = 0x11;
  FUN_1002b3b1();
  local_8._0_1_ = 0x12;
  FUN_1002b3b1();
  local_8._0_1_ = 0x13;
  FUN_10002250(&local_24);
  local_8._0_1_ = 0x14;
  FUN_1002a6e9((int)local_88);
  *param_4 = 0;
  *param_5 = 0;
  FUN_1002a6e9((int)(&DAT_100406d0 + param_2 * 100));
  *(undefined4 *)(&DAT_100406f4 + param_2 * 100) = 1;
  FUN_1002b51f(&local_3c,&param_1);
  puVar11 = local_50;
  uVar8 = 0;
  pCVar3 = (LPCSTR)FUN_10002180(&local_20);
  iVar4 = FUN_1002b6c6(local_ac,pCVar3,uVar8,(int)puVar11);
  if (iVar4 != 0) {
    while ((bVar2 = FUN_1002b8a9(local_ac,&local_98), CONCAT31(extraout_var,bVar2) != 0 &&
           (local_6c == 0))) {
      pbVar9 = &DAT_1003bbc8;
      pvVar5 = (void *)FUN_1002a0f5();
      local_8._0_1_ = 0x15;
      bVar2 = FUN_10002230(pvVar5,pbVar9);
      local_b1[0] = bVar2;
      local_8._0_1_ = 0x14;
      FUN_1002b168(&local_b8);
      if ((local_b1._0_4_ & 0xff) == 0) {
        FUN_1002b255(&local_94,&local_98);
        local_18 = FUN_1002a18f(&local_94,&DAT_1003bbca);
        if (-1 < local_18) {
          piVar6 = (int *)FUN_1002a0f5();
          local_8._0_1_ = 0x16;
          FUN_1002b255(&local_94,piVar6);
          local_8._0_1_ = 0x14;
          FUN_1002b168((int *)(local_bd + 1));
        }
        while( true ) {
          pbVar9 = &DAT_1003bbcc;
          pvVar5 = (void *)FUN_1002a079();
          local_8._0_1_ = 0x17;
          bVar2 = FUN_10002230(pvVar5,pbVar9);
          local_bd[0] = bVar2;
          local_8._0_1_ = 0x14;
          FUN_1002b168(&local_c4);
          if ((local_bd._0_4_ & 0xff) == 0) break;
          FUN_100021d0(&local_94);
          piVar6 = (int *)FUN_1002a0f5();
          local_8._0_1_ = 0x18;
          FUN_1002b255(&local_94,piVar6);
          local_8._0_1_ = 0x14;
          FUN_1002b168(&local_c8);
        }
        bVar2 = FUN_1001e370(&local_94,&local_30);
        if (bVar2) {
          FUN_100021d0(&local_30);
          piVar6 = (int *)FUN_1002a0f5();
          local_8._0_1_ = 0x19;
          FUN_1002b255(&local_24,piVar6);
          local_8._0_1_ = 0x14;
          FUN_1002b168(&local_cc);
          pbVar9 = (byte *)FUN_10002180(&local_24);
          iVar4 = FUN_100022b0(&local_30,pbVar9);
          if (iVar4 == 0) {
            FUN_1002b255(&local_3c,&local_30);
          }
        }
        bVar2 = FUN_1001e370(&local_94,&local_28);
        if (bVar2) {
          FUN_100021d0(&local_28);
          piVar6 = (int *)FUN_1002a0f5();
          local_8._0_1_ = 0x1a;
          FUN_1002b255(&local_24,piVar6);
          local_8._0_1_ = 0x14;
          FUN_1002b168(&local_d0);
          pbVar9 = (byte *)FUN_10002180(&local_24);
          iVar4 = FUN_100022b0(&local_28,pbVar9);
          if (iVar4 == 0) {
            FUN_1002b255(&local_3c,&local_28);
          }
          else {
            FUN_100021d0(&local_14);
            piVar6 = (int *)FUN_1002a0f5();
            local_8._0_1_ = 0x1b;
            FUN_1002b255(&local_24,piVar6);
            local_8._0_1_ = 0x14;
            FUN_1002b168(&local_d4);
            pbVar9 = (byte *)FUN_10002180(&local_24);
            iVar4 = FUN_100022b0(&local_14,pbVar9);
            if (iVar4 == 0) {
              FUN_1002b255(&local_3c,&local_28);
            }
            else {
              FUN_100021d0(&local_14);
              piVar6 = (int *)FUN_1002a0f5();
              local_8._0_1_ = 0x1c;
              FUN_1002b255(&local_24,piVar6);
              local_8._0_1_ = 0x14;
              FUN_1002b168(&local_d8);
              pbVar9 = (byte *)FUN_10002180(&local_24);
              iVar4 = FUN_100022b0(&local_14,pbVar9);
              if (iVar4 == 0) {
                FUN_1002b255(&local_3c,&local_28);
              }
            }
          }
        }
        bVar2 = FUN_1001e370(&local_94,&local_2c);
        if (bVar2) {
          FUN_100021d0(&local_2c);
          piVar6 = (int *)FUN_1002a0f5();
          local_8._0_1_ = 0x1d;
          FUN_1002b255(&local_24,piVar6);
          local_8._0_1_ = 0x14;
          FUN_1002b168(&local_dc);
          pbVar9 = (byte *)FUN_10002180(&local_24);
          iVar4 = FUN_100022b0(&local_2c,pbVar9);
          if (iVar4 == 0) {
            FUN_1002b255(&local_3c,&local_2c);
          }
          else {
            FUN_100021d0(&local_34);
            piVar6 = (int *)FUN_1002a0f5();
            local_8._0_1_ = 0x1e;
            FUN_1002b255(&local_24,piVar6);
            local_8._0_1_ = 0x14;
            FUN_1002b168(&local_e0);
            pbVar9 = (byte *)FUN_10002180(&local_24);
            iVar4 = FUN_100022b0(&local_34,pbVar9);
            if (iVar4 == 0) {
              FUN_1002b255(&local_3c,&local_2c);
            }
            else {
              FUN_100021d0(&local_34);
              piVar6 = (int *)FUN_1002a0f5();
              local_8._0_1_ = 0x1f;
              FUN_1002b255(&local_24,piVar6);
              local_8._0_1_ = 0x14;
              FUN_1002b168(&local_e4);
              pbVar9 = (byte *)FUN_10002180(&local_24);
              iVar4 = FUN_100022b0(&local_34,pbVar9);
              if (iVar4 == 0) {
                FUN_1002b255(&local_3c,&local_2c);
              }
            }
          }
        }
        pbVar9 = (byte *)FUN_10002180(&local_3c);
        iVar4 = FUN_100022b0(&local_94,pbVar9);
        if (iVar4 == 0) {
          local_6c = 1;
          local_e8 = &stack0xfffffe4c;
          FUN_1002b1d6(&stack0xfffffe4c,&DAT_1003bbd0);
          local_8._0_1_ = 0x20;
          local_ec = &stack0xfffffe48;
          FUN_1002aedd(&stack0xfffffe48,&local_98);
          local_8._0_1_ = 0x14;
          piVar6 = FUN_10009652(&local_f0);
          local_8._0_1_ = 0x21;
          FUN_1002b255(&local_58,piVar6);
          local_8._0_1_ = 0x14;
          FUN_1002b168(&local_f0);
          local_f4 = &stack0xfffffe4c;
          FUN_1002b1d6(&stack0xfffffe4c,&DAT_1003bbd4);
          local_8._0_1_ = 0x22;
          local_f8 = &stack0xfffffe48;
          FUN_1002aedd(&stack0xfffffe48,&local_98);
          local_8._0_1_ = 0x14;
          piVar6 = FUN_10009652(&local_fc);
          local_8._0_1_ = 0x23;
          FUN_1002b255(&local_68,piVar6);
          local_8._0_1_ = 0x14;
          FUN_1002b168(&local_fc);
          local_100 = &stack0xfffffe4c;
          FUN_1002b1d6(&stack0xfffffe4c,&DAT_1003bbd8);
          local_8._0_1_ = 0x24;
          local_104 = &stack0xfffffe48;
          FUN_1002aedd(&stack0xfffffe48,&local_98);
          local_8._0_1_ = 0x14;
          piVar6 = FUN_10009652(&local_108);
          local_8._0_1_ = 0x25;
          FUN_1002b255(&local_1c,piVar6);
          local_8._0_1_ = 0x14;
          FUN_1002b168(&local_108);
          iVar4 = FUN_1002a18f(&local_98,s__UNSUPPORTED_1003bbe0);
          local_54 = (uint)(iVar4 == -1);
          *(uint *)(&DAT_100406f4 + param_2 * 100) = local_54;
          puVar7 = local_88;
          iVar4 = param_2;
          puVar10 = puVar7;
          FUN_1002aedd(&stack0xfffffe44,&local_98);
          FUN_100097d7(puVar7,iVar4,puVar10);
          bVar2 = FUN_10002210(&local_58);
          if (CONCAT31(extraout_var_00,bVar2) == 0) {
            FUN_1002b255(&DAT_100406c4 + param_2 * 100,&local_58);
          }
          bVar2 = FUN_10002210(&local_68);
          if (CONCAT31(extraout_var_01,bVar2) == 0) {
            FUN_1002b255(&DAT_100406c8 + param_2 * 100,&local_68);
          }
          bVar2 = FUN_10002210(&local_1c);
          if (CONCAT31(extraout_var_02,bVar2) == 0) {
            bVar2 = FUN_10002230(&local_1c,&DAT_1003bbee);
            if (bVar2) {
              *(undefined4 *)(&DAT_100406cc + param_2 * 100) = 1;
            }
            else {
              bVar2 = FUN_10002230(&local_1c,&DAT_1003bbf0);
              if (bVar2) {
                *(undefined4 *)(&DAT_100406cc + param_2 * 100) = 0;
              }
              else {
                *(undefined4 *)(&DAT_100406cc + param_2 * 100) = 99;
              }
            }
          }
          else {
            *(undefined4 *)(&DAT_100406cc + param_2 * 100) = DAT_1003a6b4;
          }
          if (DAT_10041578 == 0) {
            local_8c = 1;
          }
          else {
            iVar4 = FUN_1002a18f(&local_98,&DAT_1003bbf4);
            if ((iVar4 < 0) && (iVar4 = FUN_1002a18f(&local_98,&DAT_1003bbf8), iVar4 < 0)) {
              *param_4 = 1;
              local_8c = 0;
            }
            else {
              *param_5 = 1;
              *param_4 = 0;
              local_8c = 1;
            }
          }
        }
        else {
          local_8c = 0;
        }
      }
    }
    FUN_1002b9f6((int)local_ac);
  }
  local_38 = FUN_10002270(0x1004154c);
  if (0 < local_38) {
    for (local_5c = 0; local_5c < local_38; local_5c = local_5c + 1) {
      local_90 = FUN_1002a846(&DAT_1004154c,local_5c);
      piVar6 = (int *)FUN_10002290((int)local_90);
      FUN_1002b255(&local_64,piVar6);
      puVar11 = (undefined4 *)0x0;
      pbVar9 = (byte *)FUN_10002180(&local_64);
      puVar11 = FUN_1002a86c(&DAT_100406f8 + param_2 * 100,pbVar9,puVar11);
      if (puVar11 != (undefined4 *)0x0) {
        AddTail(&DAT_100406d0 + param_2 * 100,&local_64);
      }
    }
  }
  local_60 = FUN_10002270((int)local_88);
  if (0 < local_60) {
    for (local_5c = 0; local_5c < local_60; local_5c = local_5c + 1) {
      local_90 = FUN_1002a846(local_88,local_5c);
      piVar6 = (int *)FUN_10002290((int)local_90);
      FUN_1002b255(&local_64,piVar6);
      puVar11 = (undefined4 *)0x0;
      pbVar9 = (byte *)FUN_10002180(&local_64);
      local_90 = FUN_1002a86c(&DAT_100406d0 + param_2 * 100,pbVar9,puVar11);
      if (local_90 != (int *)0x0) {
        FUN_1002a80f(&DAT_100406d0 + param_2 * 100,local_90);
      }
    }
  }
  uVar1 = local_8c;
  local_8._0_1_ = 0x13;
  FUN_1002b168(&local_24);
  local_8._0_1_ = 0x12;
  FUN_1002b168(&local_14);
  local_8._0_1_ = 0x11;
  FUN_1002b168(&local_28);
  local_8._0_1_ = 0x10;
  FUN_1002b168(&local_34);
  local_8._0_1_ = 0xf;
  FUN_1002b168(&local_2c);
  local_8._0_1_ = 0xe;
  FUN_1002b168(&local_30);
  local_8._0_1_ = 0xd;
  FUN_1002a71e();
  local_8._0_1_ = 0xc;
  FUN_1002b168(&local_64);
  local_8._0_1_ = 0xb;
  FUN_1002b168(&local_1c);
  local_8._0_1_ = 10;
  FUN_1002b168(&local_68);
  local_8._0_1_ = 9;
  FUN_1002b168(&local_58);
  local_8._0_1_ = 8;
  FUN_1002b168(&local_94);
  local_8._0_1_ = 7;
  FUN_1002b168(&local_98);
  local_8._0_1_ = 6;
  FUN_1002b168(&local_3c);
  local_8._0_1_ = 5;
  FUN_1001e260(local_50);
  local_8._0_1_ = 4;
  CStdioFile::~CStdioFile(local_ac);
  local_8._0_1_ = 1;
  FUN_1002b168(&local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168(&param_1);
  local_8 = 0xffffffff;
  FUN_1002b168(&param_3);
  ExceptionList = local_10;
  return uVar1;
}



/* VA 100087c8 */

void * __cdecl FUN_100087c8(void *param_1)

{
  int *piVar1;
  LPCSTR lpSubKey;
  int iVar2;
  undefined4 *puVar3;
  DWORD ulOptions;
  REGSAM samDesired;
  HKEY *phkResult;
  int local_234;
  undefined2 local_230;
  undefined4 local_22e [64];
  int local_12c;
  undefined2 local_128;
  undefined4 local_126 [63];
  int local_28;
  LSTATUS local_24;
  HKEY local_20;
  BYTE *local_1c;
  DWORD local_18;
  REGSAM local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10032897;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1002b1d6(&local_12c,s_SOFTWARE__1003bbfc);
  local_8 = 1;
  local_128 = DAT_1004184c;
  puVar3 = local_126;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  local_230 = DAT_1004184e;
  puVar3 = local_22e;
  for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  local_1c = (BYTE *)&local_230;
  local_18 = 0x100;
  FUN_10002250(&local_28);
  local_8._0_1_ = 2;
  local_14 = FUN_10002753();
  FUN_1002b0f3(&local_28);
  piVar1 = (int *)FUN_1002b34b();
  local_8._0_1_ = 3;
  FUN_1002b255(&local_12c,piVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1002b168(&local_234);
  phkResult = &local_20;
  ulOptions = 0;
  samDesired = local_14;
  lpSubKey = (LPCSTR)FUN_10002180(&local_12c);
  local_24 = RegOpenKeyExA((HKEY)0x80000002,lpSubKey,ulOptions,samDesired,phkResult);
  local_24 = RegQueryValueExA(local_20,s_3D_Device_Description_1003bc08,(LPDWORD)0x0,(LPDWORD)0x0,
                              (LPBYTE)&local_128,&local_18);
  if (local_24 == 0) {
    FUN_1002b2a5(&local_28,(LPCSTR)&local_128);
  }
  else {
    local_24 = RegSetValueExA(local_20,s_3D_Device_Description_1003bc20,0,1,local_1c,4);
    FUN_1002b0f3(&local_28);
  }
  RegCloseKey(local_20);
  FUN_1002aedd(param_1,&local_28);
  local_8._0_1_ = 1;
  FUN_1002b168(&local_28);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168(&local_12c);
  ExceptionList = local_10;
  return param_1;
}



/* VA 10008992 */

void * __cdecl FUN_10008992(void *param_1)

{
  int *piVar1;
  LPCSTR pCVar2;
  undefined4 *puVar3;
  int iVar4;
  DWORD DVar5;
  REGSAM RVar6;
  UINT UVar7;
  HKEY *ppHVar8;
  int local_238;
  int local_234;
  undefined2 local_230;
  undefined4 local_22e [64];
  int local_12c;
  undefined2 local_128;
  undefined4 local_126 [63];
  LSTATUS local_28;
  HKEY local_24;
  undefined2 *local_20;
  DWORD local_1c;
  int local_18;
  REGSAM local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_100328e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1002b1d6(&local_12c,s_SOFTWARE__1003bc38);
  local_8 = 1;
  local_128 = DAT_10041850;
  puVar3 = local_126;
  for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  local_230 = DAT_10041852;
  puVar3 = local_22e;
  for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  local_20 = &local_230;
  local_1c = 0x100;
  FUN_10002250(&local_18);
  local_8._0_1_ = 2;
  local_14 = FUN_10002753();
  piVar1 = (int *)FUN_1002b34b();
  local_8._0_1_ = 3;
  FUN_1002b255(&local_12c,piVar1);
  local_8._0_1_ = 2;
  FUN_1002b168(&local_234);
  ppHVar8 = &local_24;
  DVar5 = 0;
  RVar6 = local_14;
  pCVar2 = (LPCSTR)FUN_10002180(&local_12c);
  local_28 = RegOpenKeyExA((HKEY)0x80000002,pCVar2,DVar5,RVar6,ppHVar8);
  if (local_28 != 0) {
    ppHVar8 = &local_24;
    DVar5 = 0;
    RVar6 = local_14;
    pCVar2 = (LPCSTR)FUN_10002180(&local_12c);
    local_28 = RegOpenKeyExA((HKEY)0x80000002,pCVar2,DVar5,RVar6,ppHVar8);
    if (local_28 != 0) {
      iVar4 = 0;
      UVar7 = 0;
      puVar3 = (undefined4 *)FUN_1002b425();
      local_8._0_1_ = 4;
      pCVar2 = (LPCSTR)FUN_10002180(puVar3);
      FUN_10030703(pCVar2,UVar7,iVar4);
      local_8._0_1_ = 2;
      FUN_1002b168(&local_238);
      FUN_10029f8c(param_1,-1,1);
      local_8._0_1_ = 1;
      FUN_1002b168(&local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168(&local_12c);
      ExceptionList = local_10;
      return param_1;
    }
  }
  local_28 = RegQueryValueExA(local_24,s_Thrash_Resolution_1003bc74,(LPDWORD)0x0,(LPDWORD)0x0,
                              (LPBYTE)&local_128,&local_1c);
  if (local_28 == 0) {
    FUN_1002b2a5(&local_18,(LPCSTR)&local_128);
  }
  else {
    FUN_1002b2a5(&local_18,s_640x480_1003bc88);
  }
  RegCloseKey(local_24);
  FUN_1002aedd(param_1,&local_18);
  local_8._0_1_ = 1;
  FUN_1002b168(&local_18);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168(&local_12c);
  ExceptionList = local_10;
  return param_1;
}



/* VA 10008c04 */

uint FUN_10008c04(void)

{
  uint uVar1;
  LPCSTR pCVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  REGSAM RVar5;
  UINT UVar6;
  HKEY *ppHVar7;
  int iVar8;
  int local_38;
  int local_34;
  uint local_30;
  LSTATUS local_2c;
  uint local_28;
  HKEY local_24;
  BYTE local_20 [4];
  DWORD local_1c;
  BYTE *local_18;
  REGSAM local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10032904;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1002b1d6(&local_34,s_SOFTWARE__1003bc90);
  local_8 = 0;
  local_28 = (uint)DAT_10041854;
  local_20[0] = '\0';
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  local_18 = local_20;
  local_1c = 4;
  local_14 = FUN_10002753();
  FUN_1002b51f(&local_34,(undefined4 *)&DAT_100415cc);
  ppHVar7 = &local_24;
  DVar4 = 0;
  RVar5 = local_14;
  pCVar2 = (LPCSTR)FUN_10002180(&local_34);
  local_2c = RegOpenKeyExA((HKEY)0x80000002,pCVar2,DVar4,RVar5,ppHVar7);
  if (local_2c != 0) {
    ppHVar7 = &local_24;
    DVar4 = 0;
    RVar5 = local_14;
    pCVar2 = (LPCSTR)FUN_10002180(&local_34);
    local_2c = RegOpenKeyExA((HKEY)0x80000002,pCVar2,DVar4,RVar5,ppHVar7);
    if (local_2c != 0) {
      iVar8 = 0;
      UVar6 = 0;
      puVar3 = (undefined4 *)FUN_1002b425();
      local_8._0_1_ = 1;
      pCVar2 = (LPCSTR)FUN_10002180(puVar3);
      FUN_10030703(pCVar2,UVar6,iVar8);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168(&local_38);
      local_8 = 0xffffffff;
      FUN_1002b168(&local_34);
      ExceptionList = local_10;
      return 0xffffffff;
    }
  }
  local_2c = RegQueryValueExA(local_24,s_Triple_Buffer_1003bccc,(LPDWORD)0x0,(LPDWORD)0x0,
                              (LPBYTE)&local_28,&local_1c);
  if (local_2c == 0) {
    local_30 = local_28;
    local_2c = 0;
  }
  else {
    local_2c = RegSetValueExA(local_24,s_Triple_Buffer_1003bcdc,0,4,local_18,4);
    local_30 = 99;
  }
  RegCloseKey(local_24);
  uVar1 = local_30;
  local_8 = 0xffffffff;
  FUN_1002b168(&local_34);
  ExceptionList = local_10;
  return uVar1;
}



/* VA 10008d91 */

undefined4 __cdecl FUN_10008d91(int param_1,uint param_2)

{
  undefined1 uVar1;
  bool bVar2;
  LPCSTR pCVar3;
  undefined4 *puVar4;
  uint *puVar5;
  size_t sVar6;
  int iVar7;
  DWORD DVar8;
  REGSAM RVar9;
  UINT UVar10;
  HKEY *ppHVar11;
  int local_140;
  undefined4 local_13c;
  undefined1 local_138 [2];
  undefined4 local_136 [64];
  int local_34;
  int local_30;
  HKEY local_2c;
  LSTATUS local_28;
  int local_24;
  HKEY local_20;
  uint local_1c;
  BYTE *local_18;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_1003293e;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_1002b1d6(&local_34,s_SOFTWARE__1003bcec);
  local_8._0_1_ = 1;
  local_138 = (undefined1  [2])DAT_10041856;
  puVar4 = local_136;
  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  FUN_10002250(&local_30);
  local_8._0_1_ = 2;
  FUN_10002250(&local_24);
  local_8._0_1_ = 3;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 3;
  if ((DAT_10041700 == '\0') || (iVar7 = FUN_100024d8(), uVar1 = (undefined1)local_8, iVar7 != 0)) {
    local_8._0_1_ = uVar1;
    FUN_1002b51f(&local_34,(undefined4 *)&DAT_100415cc);
    ppHVar11 = &local_20;
    RVar9 = 0xf003f;
    DVar8 = 0;
    pCVar3 = (LPCSTR)FUN_10002180(&local_34);
    local_28 = RegOpenKeyExA((HKEY)0x80000002,pCVar3,DVar8,RVar9,ppHVar11);
    if (local_28 != 0) {
      ppHVar11 = &local_20;
      RVar9 = 0xf003f;
      DVar8 = 0;
      pCVar3 = (LPCSTR)FUN_10002180(&local_34);
      local_28 = RegOpenKeyExA((HKEY)0x80000002,pCVar3,DVar8,RVar9,ppHVar11);
      if (local_28 != 0) {
        iVar7 = 0;
        UVar10 = 0;
        puVar4 = (undefined4 *)FUN_1002b425();
        local_8._0_1_ = 4;
        pCVar3 = (LPCSTR)FUN_10002180(puVar4);
        FUN_10030703(pCVar3,UVar10,iVar7);
        local_8._0_1_ = 3;
        FUN_1002b168(&local_140);
        local_8._0_1_ = 2;
        FUN_1002b168(&local_24);
        local_8._0_1_ = 1;
        FUN_1002b168(&local_30);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1002b168(&local_34);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0x0000000c);
        ExceptionList = local_10;
        return 0xffffffff;
      }
    }
    puVar5 = (uint *)FUN_10002180((undefined4 *)(&DAT_10040d58 + param_1 * 0x3c));
    FUN_1001f150((uint *)local_138,puVar5);
    local_18 = local_138;
    sVar6 = _strlen(local_138);
    local_28 = RegSetValueExA(local_20,s_3D_Device_Description_1003bd28,0,1,local_18,sVar6);
    puVar5 = (uint *)FUN_10002180((undefined4 *)(&DAT_10040d5c + param_1 * 0x3c));
    FUN_1001f150((uint *)local_138,puVar5);
    FUN_1002b2a5(&local_30,local_138);
    local_18 = local_138;
    sVar6 = _strlen(local_138);
    local_28 = RegSetValueExA(local_20,s_3D_Card_1003bd40,0,1,local_18,sVar6);
    puVar5 = (uint *)FUN_10002180((undefined4 *)(&DAT_10040d60 + param_1 * 0x3c));
    FUN_1001f150((uint *)local_138,puVar5);
    local_18 = local_138;
    sVar6 = _strlen(local_138);
    local_28 = RegSetValueExA(local_20,s_Thrash_Driver_1003bd48,0,1,local_18,sVar6);
    puVar5 = (uint *)FUN_10002180((undefined4 *)(&DAT_10040d64 + param_1 * 0x3c));
    FUN_1001f150((uint *)local_138,puVar5);
    FUN_1002b2a5(&local_24,local_138);
    local_18 = local_138;
    sVar6 = _strlen(local_138);
    local_28 = RegSetValueExA(local_20,s_Group_1003bd58,0,1,local_18,sVar6);
    bVar2 = FUN_10002230(&local_30,(byte *)s_PowerVR_1003bd60);
    if ((bVar2) && (bVar2 = FUN_10002230(&local_24,&DAT_1003bd68), bVar2)) {
      DAT_100415ac = 1;
    }
    else {
      DAT_100415ac = 0;
    }
    local_1c = *(uint *)(&DAT_10040d54 + param_1 * 0x3c);
    local_14 = &local_1c;
    local_28 = RegSetValueExA(local_20,s_D3D_Device_1003bd6c,0,4,(BYTE *)local_14,4);
    if (*(int *)(&DAT_10040d68 + param_1 * 0x3c) == 99) {
      local_1c = 0;
    }
    else if (DAT_100415bc == 1) {
      local_1c = *(uint *)(&DAT_10040d68 + param_1 * 0x3c);
    }
    else {
      local_1c = param_2;
    }
    local_14 = &local_1c;
    local_28 = RegSetValueExA(local_20,s_Triple_Buffer_1003bd78,0,4,(BYTE *)local_14,4);
    bVar2 = FUN_10002230(&DAT_10040d5c + param_1 * 0x3c,(byte *)s_Software_Renderer_1003bd88);
    local_1c = (uint)!bVar2;
    local_14 = &local_1c;
    local_28 = RegSetValueExA(local_20,s_Hardware_Acceleration_1003bd9c,0,4,(BYTE *)local_14,4);
    puVar5 = (uint *)FUN_10002180((undefined4 *)&stack0x0000000c);
    FUN_1001f150((uint *)local_138,puVar5);
    local_18 = local_138;
    sVar6 = _strlen(local_138);
    local_28 = RegSetValueExA(local_20,s_Thrash_Resolution_1003bdb4,0,1,local_18,sVar6);
    RegCloseKey(local_20);
    if ((DAT_100415c0 != 0) && (DAT_100415ac == 0)) {
      FUN_1002b255(&local_24,(int *)(&DAT_10040d64 + param_1 * 0x3c));
      bVar2 = FUN_10002230(&local_24,&DAT_1003bdc8);
      if (bVar2) {
        FUN_1002b2a5(&local_34,s_SOFTWARE_PowerVR_PCX1_2_HWINI_PV_1003bdcc);
        ppHVar11 = &local_20;
        RVar9 = 0xf003f;
        DVar8 = 0;
        pCVar3 = (LPCSTR)FUN_10002180(&local_34);
        local_28 = RegOpenKeyExA((HKEY)0x80000002,pCVar3,DVar8,RVar9,ppHVar11);
        if (local_28 == 0) {
          FUN_1001f150((uint *)local_138,(uint *)&DAT_1003bdf2);
          local_18 = local_138;
          local_28 = RegSetValueExA(local_20,s_EnableHAL_1003bdf4,0,1,local_18,4);
        }
        RegCloseKey(local_20);
      }
    }
    if (DAT_100415ac != 0) {
      FUN_1002b2a5(&local_34,s_SOFTWARE_PowerVR_PCX1_2_HWINI_PV_1003be00);
      ppHVar11 = &local_2c;
      RVar9 = 0xf003f;
      DVar8 = 0;
      pCVar3 = (LPCSTR)FUN_10002180(&local_34);
      local_28 = RegOpenKeyExA((HKEY)0x80000002,pCVar3,DVar8,RVar9,ppHVar11);
      if (local_28 == 0) {
        FUN_1001f150((uint *)local_138,(uint *)&DAT_1003be26);
        local_18 = local_138;
        local_28 = RegSetValueExA(local_2c,s_EnableHAL_1003be28,0,1,local_18,4);
      }
      RegCloseKey(local_2c);
    }
    local_8._0_1_ = 2;
    FUN_1002b168(&local_24);
    local_8._0_1_ = 1;
    FUN_1002b168(&local_30);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1002b168(&local_34);
    local_8 = 0xffffffff;
    FUN_1002b168((int *)&stack0x0000000c);
    local_13c = 0;
  }
  else {
    local_13c = 0xfffffffe;
    local_8._0_1_ = 2;
    FUN_1002b168(&local_24);
    local_8._0_1_ = 1;
    FUN_1002b168(&local_30);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1002b168(&local_34);
    local_8 = 0xffffffff;
    FUN_1002b168((int *)&stack0x0000000c);
  }
  ExceptionList = local_10;
  return local_13c;
}



/* VA 100093cc */

undefined4 FUN_100093cc(void)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  LPCSTR pCVar3;
  undefined4 uVar4;
  DWORD DVar5;
  REGSAM RVar6;
  HKEY *ppHVar7;
  int local_30;
  undefined1 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  LSTATUS local_1c;
  int local_18;
  HKEY local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_1003297e;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_1002b1d6(&local_24,s_SOFTWARE__1003be34);
  local_8._0_1_ = 1;
  FUN_10002250(&local_20);
  local_8._0_1_ = 2;
  FUN_10002250(&local_18);
  local_8._0_1_ = 3;
  FUN_10002250(&local_28);
  local_8._0_1_ = 4;
  local_2c = &stack0xffffffb4;
  FUN_1002aedd(&stack0xffffffb4,(int *)&stack0x00000004);
  piVar2 = FUN_10004080(&local_30);
  local_8._0_1_ = 5;
  FUN_1002b255(&local_28,piVar2);
  local_8._0_1_ = 4;
  FUN_1002b168(&local_30);
  bVar1 = FUN_10002210(&local_28);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_1002b51f(&local_24,&local_28);
    ppHVar7 = &local_14;
    RVar6 = 0xf003f;
    DVar5 = 0;
    pCVar3 = (LPCSTR)FUN_10002180(&local_24);
    local_1c = RegOpenKeyExA((HKEY)0x80000002,pCVar3,DVar5,RVar6,ppHVar7);
    if (local_1c != 0) {
      ppHVar7 = &local_14;
      RVar6 = 0xf003f;
      DVar5 = 0;
      pCVar3 = (LPCSTR)FUN_10002180(&local_24);
      local_1c = RegOpenKeyExA((HKEY)0x80000002,pCVar3,DVar5,RVar6,ppHVar7);
      if (local_1c != 0) {
        local_8._0_1_ = 3;
        FUN_1002b168(&local_28);
        local_8._0_1_ = 2;
        FUN_1002b168(&local_18);
        local_8._0_1_ = 1;
        FUN_1002b168(&local_20);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1002b168(&local_24);
        local_8 = 0xffffffff;
        FUN_1002b168((int *)&stack0x00000004);
        ExceptionList = local_10;
        return 0;
      }
    }
    local_1c = RegDeleteValueA(local_14,s_3D_Device_Description_1003be40);
    local_1c = RegDeleteValueA(local_14,s_3D_Card_1003be58);
    local_1c = RegDeleteValueA(local_14,s_Thrash_Driver_1003be60);
    local_1c = RegDeleteValueA(local_14,s_Group_1003be70);
    local_1c = RegDeleteValueA(local_14,s_D3D_Device_1003be78);
    local_1c = RegDeleteValueA(local_14,s_Triple_Buffer_1003be84);
    local_1c = RegDeleteValueA(local_14,s_Hardware_Acceleration_1003be94);
    local_1c = RegDeleteValueA(local_14,s_Thrash_Resolution_1003beac);
    local_8._0_1_ = 3;
    FUN_1002b168(&local_28);
    local_8._0_1_ = 2;
    FUN_1002b168(&local_18);
    local_8._0_1_ = 1;
    FUN_1002b168(&local_20);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1002b168(&local_24);
    local_8 = 0xffffffff;
    FUN_1002b168((int *)&stack0x00000004);
    uVar4 = 0;
  }
  else {
    local_8._0_1_ = 3;
    FUN_1002b168(&local_28);
    local_8._0_1_ = 2;
    FUN_1002b168(&local_18);
    local_8._0_1_ = 1;
    FUN_1002b168(&local_20);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1002b168(&local_24);
    local_8 = 0xffffffff;
    FUN_1002b168((int *)&stack0x00000004);
    uVar4 = 0xffffffff;
  }
  ExceptionList = local_10;
  return uVar4;
}



/* VA 10009652 */

void * __cdecl FUN_10009652(void *param_1)

{
  char *pcVar1;
  int *piVar2;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_100329de;
  local_10 = ExceptionList;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_10002250(&local_14);
  local_8._0_1_ = 3;
  FUN_10002250(&local_24);
  local_8._0_1_ = 4;
  pcVar1 = (char *)FUN_10002180((undefined4 *)&stack0x0000000c);
  local_20 = FUN_1002a18f(&stack0x00000008,pcVar1);
  if (local_20 < 1) {
    FUN_1002b0f3(&local_24);
  }
  else {
    local_1c = FUN_100021d0((int *)&stack0x0000000c);
    piVar2 = (int *)FUN_10029fc0(&local_28);
    local_8._0_1_ = 5;
    FUN_1002b255(&local_14,piVar2);
    local_8._0_1_ = 4;
    FUN_1002b168(&local_28);
    local_18 = FUN_1002b5ce(&local_14,0x20);
    if (local_18 < 0) {
      piVar2 = (int *)FUN_10029fc0(&local_2c);
      local_8._0_1_ = 6;
      FUN_1002b255(&local_24,piVar2);
      local_8._0_1_ = 4;
      FUN_1002b168(&local_2c);
    }
    else {
      piVar2 = (int *)FUN_10029fe3();
      local_8._0_1_ = 7;
      FUN_1002b255(&local_24,piVar2);
      local_8._0_1_ = 4;
      FUN_1002b168(&local_30);
    }
  }
  FUN_1002aedd(param_1,&local_24);
  local_8._0_1_ = 3;
  FUN_1002b168(&local_24);
  local_8._0_1_ = 2;
  FUN_1002b168(&local_14);
  local_8._0_1_ = 1;
  FUN_1002b168((int *)&stack0x00000008);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168((int *)&stack0x0000000c);
  ExceptionList = local_10;
  return param_1;
}



/* VA 100097d7 */

void __cdecl FUN_100097d7(undefined4 param_1,int param_2,void *param_3)

{
  int *piVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_10032a54;
  local_10 = ExceptionList;
  local_8 = 0;
  local_20 = 0;
  ExceptionList = &local_10;
  FUN_10002250(&local_14);
  local_8._0_1_ = 1;
  FUN_10002250(&local_28);
  local_8._0_1_ = 2;
  FUN_10002250(&local_30);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_1002a6e9((int)param_3);
  local_20 = 0;
  local_2c = FUN_1002a18f(&param_1,&DAT_1003bec0);
  if (0 < local_2c) {
    FUN_1002b255(&local_14,&param_1);
    while (local_20 == 0) {
      local_2c = FUN_1002a18f(&local_14,&DAT_1003bec4);
      if (local_2c < 0) {
        local_20 = 1;
      }
      else {
        piVar1 = (int *)FUN_10029fc0(&local_38);
        local_8._0_1_ = 4;
        FUN_1002b255(&local_14,piVar1);
        local_8._0_1_ = 3;
        FUN_1002b168(&local_38);
        local_1c = FUN_1002b5ce(&local_14,0x20);
        if (local_1c < 0) {
          piVar1 = (int *)FUN_10029fc0(&local_3c);
          local_8._0_1_ = 5;
          FUN_1002b255(&local_28,piVar1);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_1002b168(&local_3c);
          FUN_1002b609(&local_28);
          AddTail(&DAT_100406d0 + param_2 * 100,&local_28);
          local_20 = 1;
        }
        else {
          piVar1 = (int *)FUN_10029fe3();
          local_8._0_1_ = 6;
          FUN_1002b255(&local_28,piVar1);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_1002b168(&local_40);
          FUN_1002b609(&local_28);
          if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
            FUN_1001f240(DAT_100416f8,(byte *)s_CARD_ADD_resolution__s_1003bec8);
          }
          AddTail(&DAT_100406d0 + param_2 * 100,&local_28);
          piVar1 = (int *)FUN_10029fc0(&local_44);
          local_8._0_1_ = 7;
          FUN_1002b255(&local_14,piVar1);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_1002b168(&local_44);
        }
      }
    }
  }
  local_2c = FUN_1002a18f(&param_1,&DAT_1003bee0);
  if (0 < local_2c) {
    local_20 = 0;
    FUN_1002b255(&local_14,&param_1);
    while (local_20 == 0) {
      local_18 = FUN_10002270((int)(&DAT_100406d0 + param_2 * 100));
      local_2c = FUN_1002a18f(&local_14,&DAT_1003bee8);
      if (local_2c < 0) {
        local_20 = 1;
      }
      else {
        piVar1 = (int *)FUN_10029fc0(&local_48);
        local_8._0_1_ = 8;
        FUN_1002b255(&local_14,piVar1);
        local_8._0_1_ = 3;
        FUN_1002b168(&local_48);
        local_1c = FUN_1002b5ce(&local_14,0x20);
        if (local_1c < 0) {
          piVar1 = (int *)FUN_10029fc0(&local_4c);
          local_8._0_1_ = 9;
          FUN_1002b255(&local_28,piVar1);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_1002b168(&local_4c);
          FUN_1002b609(&local_28);
          AddTail(param_3,&local_28);
          for (local_24 = 0; local_24 < local_18; local_24 = local_24 + 1) {
            puVar3 = (undefined4 *)0x0;
            pbVar2 = (byte *)FUN_10002180(&local_28);
            local_34 = FUN_1002a86c(&DAT_100406d0 + param_2 * 100,pbVar2,puVar3);
            if (local_34 != (int *)0x0) {
              if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
                FUN_1001f240(DAT_100416f8,(byte *)s_Removing_excluded_resolution___s_1003bef0);
              }
              FUN_1002a80f(&DAT_100406d0 + param_2 * 100,local_34);
              local_24 = local_18;
            }
          }
          local_20 = 1;
        }
        else {
          piVar1 = (int *)FUN_10029fe3();
          local_8._0_1_ = 10;
          FUN_1002b255(&local_28,piVar1);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_1002b168(&local_50);
          FUN_1002b609(&local_28);
          AddTail(param_3,&local_28);
          puVar3 = (undefined4 *)0x0;
          pbVar2 = (byte *)FUN_10002180(&local_28);
          local_34 = FUN_1002a86c(&DAT_100406d0 + param_2 * 100,pbVar2,puVar3);
          if (local_34 != (int *)0x0) {
            if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
              FUN_1001f240(DAT_100416f8,(byte *)s_Removing_excluded_resolution___s_1003bf14);
            }
            FUN_1002a80f(&DAT_100406d0 + param_2 * 100,local_34);
            local_24 = local_18;
          }
          piVar1 = (int *)FUN_10029fc0(&local_54);
          local_8._0_1_ = 0xb;
          FUN_1002b255(&local_14,piVar1);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_1002b168(&local_54);
        }
      }
    }
  }
  local_8._0_1_ = 2;
  FUN_1002b168(&local_30);
  local_8._0_1_ = 1;
  FUN_1002b168(&local_28);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168(&local_14);
  local_8 = 0xffffffff;
  FUN_1002b168(&param_1);
  ExceptionList = local_10;
  return;
}



/* VA 10009cc6 */

undefined4 __cdecl FUN_10009cc6(void *param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  LPCSTR pCVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  DWORD DVar8;
  REGSAM RVar9;
  HKEY *ppHVar10;
  char *pcVar11;
  int local_260;
  int local_25c;
  uint local_255;
  undefined1 uStack_251;
  int local_250;
  int local_24c;
  int local_248;
  LSTATUS local_244;
  HKEY local_240;
  DWORD local_23c;
  int local_238;
  int local_234;
  undefined2 local_230;
  undefined4 local_22e [63];
  int local_130;
  undefined4 local_12c;
  undefined2 local_128;
  undefined4 local_126 [64];
  HKEY local_24;
  int local_20 [2];
  LSTATUS local_18;
  REGSAM local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10032abb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1002b1d6(local_20,s_Software__1003bf38);
  local_8 = 0;
  local_128 = DAT_10041858;
  puVar7 = local_126;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  local_20[1] = 0x100;
  local_14 = FUN_10002753();
  local_12c = 2;
  FUN_1002b2a5(param_1,s_English_1003bf44);
  piVar3 = (int *)FUN_1002b34b();
  local_8._0_1_ = 1;
  FUN_1002b255(local_20,piVar3);
  local_8._0_1_ = 0;
  FUN_1002b168(&local_248);
  ppHVar10 = &local_24;
  DVar8 = 0;
  RVar9 = local_14;
  pCVar4 = (LPCSTR)FUN_10002180(local_20);
  local_18 = RegOpenKeyExA((HKEY)0x80000002,pCVar4,DVar8,RVar9,ppHVar10);
  if (local_18 != 0) {
    ppHVar10 = &local_24;
    DVar8 = 0;
    RVar9 = local_14;
    pCVar4 = (LPCSTR)FUN_10002180(local_20);
    local_18 = RegOpenKeyExA((HKEY)0x80000002,pCVar4,DVar8,RVar9,ppHVar10);
    if (local_18 != 0) {
      FUN_1002b34b();
      local_8._0_1_ = 2;
      piVar3 = (int *)FUN_1002b3b1();
      local_8._0_1_ = 3;
      FUN_1002b255(local_20,piVar3);
      local_8._0_1_ = 2;
      FUN_1002b168(&local_250);
      local_8._0_1_ = 0;
      FUN_1002b168(&local_24c);
      ppHVar10 = &local_24;
      DVar8 = 0;
      RVar9 = local_14;
      pCVar4 = (LPCSTR)FUN_10002180(local_20);
      local_18 = RegOpenKeyExA((HKEY)0x80000002,pCVar4,DVar8,RVar9,ppHVar10);
      if (local_18 != 0) {
        ppHVar10 = &local_24;
        DVar8 = 0;
        RVar9 = local_14;
        pCVar4 = (LPCSTR)FUN_10002180(local_20);
        local_18 = RegOpenKeyExA((HKEY)0x80000002,pCVar4,DVar8,RVar9,ppHVar10);
        if (local_18 != 0) {
          local_255._1_3_ = (undefined3)local_12c;
          uStack_251 = (undefined1)((uint)local_12c >> 0x18);
          local_8 = 0xffffffff;
          FUN_1002b168(local_20);
          ExceptionList = local_10;
          return CONCAT13(uStack_251,local_255._1_3_);
        }
      }
    }
  }
  local_18 = RegQueryValueExA(local_24,s_Language_1003bf54,(LPDWORD)0x0,(LPDWORD)0x0,
                              (LPBYTE)&local_128,(LPDWORD)(local_20 + 1));
  if (local_18 == 0) {
    FUN_1002b2a5(param_1,(LPCSTR)&local_128);
    bVar2 = FUN_10002230(param_1,(byte *)s_French_1003bf68);
    if (bVar2) {
      local_12c = 3;
    }
    else {
      bVar2 = FUN_10002230(param_1,(byte *)s_German_1003bf70);
      if (bVar2) {
        local_12c = 4;
      }
      else {
        bVar2 = FUN_10002230(param_1,(byte *)s_Italian_1003bf78);
        if (bVar2) {
          local_12c = 5;
        }
        else {
          bVar2 = FUN_10002230(param_1,(byte *)s_Spanish_1003bf80);
          if (bVar2) {
            local_12c = 6;
          }
          else {
            bVar2 = FUN_10002230(param_1,(byte *)s_Swedish_1003bf88);
            if (bVar2) {
              local_12c = 7;
            }
            else {
              bVar2 = FUN_10002230(param_1,(byte *)s_Finnish_1003bf90);
              if (bVar2) {
                local_12c = 8;
              }
              else {
                bVar2 = FUN_10002230(param_1,(byte *)s_Dutch_1003bf98);
                if (bVar2) {
                  local_12c = 9;
                }
                else {
                  bVar2 = FUN_10002230(param_1,(byte *)s_Danish_1003bfa0);
                  if (bVar2) {
                    local_12c = 10;
                  }
                  else {
                    bVar2 = FUN_10002230(param_1,(byte *)s_Brazilian_Portuguese_1003bfa8);
                    if (bVar2) {
                      local_12c = 0xb;
                    }
                    else {
                      bVar2 = FUN_10002230(param_1,(byte *)s_PortBraz_1003bfc0);
                      if (bVar2) {
                        local_12c = 0xb;
                      }
                      else {
                        bVar2 = FUN_10002230(param_1,(byte *)s_PortBrzl_1003bfcc);
                        if (bVar2) {
                          local_12c = 0xb;
                        }
                        else {
                          bVar2 = FUN_10002230(param_1,(byte *)s_Czech_1003bfd8);
                          if (bVar2) {
                            local_12c = 0xc;
                          }
                          else {
                            bVar2 = FUN_10002230(param_1,(byte *)s_Greek_1003bfe0);
                            if (bVar2) {
                              local_12c = 0xd;
                            }
                            else {
                              bVar2 = FUN_10002230(param_1,(byte *)s_Hebrew_1003bfe8);
                              if (bVar2) {
                                local_12c = 0xe;
                              }
                              else {
                                bVar2 = FUN_10002230(param_1,(byte *)s_Russian_1003bff0);
                                if (bVar2) {
                                  local_12c = 0xf;
                                }
                                else {
                                  bVar2 = FUN_10002230(param_1,(byte *)s_Korean_1003bff8);
                                  if (bVar2) {
                                    local_12c = 0x10;
                                  }
                                  else {
                                    bVar2 = FUN_10002230(param_1,(byte *)s_Japanese_1003c000);
                                    if (bVar2) {
                                      local_12c = 0x11;
                                    }
                                    else {
                                      bVar2 = FUN_10002230(param_1,(byte *)
                                                  s_Chinese__Simplified__1003c00c);
                                      if (bVar2) {
                                        local_12c = 0x12;
                                      }
                                      else {
                                        bVar2 = FUN_10002230(param_1,(byte *)
                                                  s_Chinese__Traditional__1003c024);
                                        if (bVar2) {
                                          local_12c = 0x13;
                                        }
                                        else {
                                          pcVar11 = s_English_1003c03c;
                                          pvVar5 = (void *)FUN_1002a0f5();
                                          local_8._0_1_ = 4;
                                          bVar2 = FUN_10002230(pvVar5,(byte *)pcVar11);
                                          local_255 = CONCAT31(local_255._1_3_,bVar2);
                                          local_8._0_1_ = 0;
                                          FUN_1002b168(&local_25c);
                                          if ((local_255 & 0xff) != 0) {
                                            FUN_10002250(&local_238);
                                            local_8._0_1_ = 5;
                                            local_230 = DAT_1004185a;
                                            puVar7 = local_22e;
                                            for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
                                              *puVar7 = 0;
                                              puVar7 = puVar7 + 1;
                                            }
                                            *(undefined2 *)puVar7 = 0;
                                            local_23c = 0x100;
                                            local_234 = 0;
                                            FUN_10002250(&local_130);
                                            local_8._0_1_ = 6;
                                            FUN_1002b2a5(&local_238,
                                                         s_Control_Panel_International_1003c044);
                                            ppHVar10 = &local_240;
                                            DVar8 = 0;
                                            RVar9 = local_14;
                                            pCVar4 = (LPCSTR)FUN_10002180(&local_238);
                                            local_244 = RegOpenKeyExA((HKEY)0x80000001,pCVar4,DVar8,
                                                                      RVar9,ppHVar10);
                                            if (local_244 == 0) {
                                              local_244 = RegQueryValueExA(local_240,
                                                                           s_Locale_1003c060,
                                                                           (LPDWORD)0x0,(LPDWORD)0x0
                                                                           ,(LPBYTE)&local_230,
                                                                           &local_23c);
                                              if (local_244 == 0) {
                                                FUN_1002b2a5(&local_130,(LPCSTR)&local_230);
                                                piVar3 = (int *)FUN_1002a079();
                                                local_8._0_1_ = 7;
                                                FUN_1002b255(&local_130,piVar3);
                                                local_8._0_1_ = 6;
                                                FUN_1002b168(&local_260);
                                                bVar2 = FUN_10002230(&local_130,&DAT_1003c068);
                                                if ((bVar2) ||
                                                   (bVar2 = FUN_10002230(&local_130,&DAT_1003c070),
                                                   bVar2)) {
                                                  local_234 = 1;
                                                }
                                              }
                                              RegCloseKey(local_240);
                                            }
                                            if (local_234 == 0) {
                                              local_12c = 1;
                                            }
                                            else {
                                              local_12c = 2;
                                            }
                                            local_8._0_1_ = 5;
                                            FUN_1002b168(&local_130);
                                            local_8._0_1_ = 0;
                                            FUN_1002b168(&local_238);
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    local_12c = 2;
    FUN_1002b2a5(param_1,s_English_1003bf60);
  }
  RegCloseKey(local_24);
  uVar1 = local_12c;
  local_8 = 0xffffffff;
  FUN_1002b168(local_20);
  ExceptionList = local_10;
  return uVar1;
}



/* VA 1000a448 */

/* WARNING: Variable defined which should be unmapped: param_1 */

void * __cdecl FUN_1000a448(void *param_1)

{
  bool bVar1;
  LPCSTR pCVar2;
  int iVar3;
  undefined3 extraout_var;
  void *pvVar4;
  int *piVar5;
  undefined3 extraout_var_00;
  uint uVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  int local_7c;
  int local_78;
  int local_74;
  undefined1 local_6d [5];
  int local_68;
  undefined1 local_61 [5];
  int local_5c;
  CStdioFile local_58 [20];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30 [5];
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_10032b63;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  FUN_1002b3b1();
  local_8._0_1_ = 2;
  FUN_1002b3b1();
  local_8._0_1_ = 4;
  FUN_1002b168((int *)(local_61 + 1));
  FUN_1002b1d6(&local_14,s_Product__1003c088);
  local_8._0_1_ = 5;
  local_5c = 0;
  FUN_1002b651((undefined4 *)local_58);
  local_8._0_1_ = 6;
  FUN_1001e150(local_30,0,0xffffffff,(LPCSTR)0x0);
  local_8._0_1_ = 7;
  FUN_10002250(&local_44);
  local_8._0_1_ = 8;
  FUN_10002250(&local_3c);
  local_8._0_1_ = 9;
  FUN_10002250(&local_40);
  local_8._0_1_ = 10;
  FUN_10002250(&local_1c);
  local_8._0_1_ = 0xb;
  local_18 = 0;
  puVar7 = local_30;
  uVar6 = 0;
  pCVar2 = (LPCSTR)FUN_10002180(&local_34);
  iVar3 = FUN_1002b6c6(local_58,pCVar2,uVar6,(int)puVar7);
  if (iVar3 == 0) {
    FUN_10030703(s_Error__Could_not_open_data_file__1003c0c4,0,0);
    FUN_1002b0f3(&local_40);
    FUN_10029f8c(param_1,-2,1);
    local_8._0_1_ = 10;
    FUN_1002b168(&local_1c);
    local_8._0_1_ = 9;
    FUN_1002b168(&local_40);
    local_8._0_1_ = 8;
    FUN_1002b168(&local_3c);
    local_8._0_1_ = 7;
    FUN_1002b168(&local_44);
    local_8._0_1_ = 6;
    FUN_1001e260(local_30);
    local_8._0_1_ = 5;
    CStdioFile::~CStdioFile(local_58);
    local_8._0_1_ = 4;
    FUN_1002b168(&local_14);
    local_8._0_1_ = 1;
    FUN_1002b168(&local_34);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1002b168((int *)&stack0x00000008);
  }
  else {
    while ((bVar1 = FUN_1002b8a9(local_58,&local_44), CONCAT31(extraout_var,bVar1) != 0 &&
           (local_5c == 0))) {
      pbVar8 = &DAT_1003c092;
      pvVar4 = (void *)FUN_1002a0f5();
      local_8._0_1_ = 0xc;
      bVar1 = FUN_10002230(pvVar4,pbVar8);
      local_61[0] = bVar1;
      local_8._0_1_ = 0xb;
      FUN_1002b168(&local_68);
      if ((local_61._0_4_ & 0xff) == 0) {
        FUN_100021d0(&local_14);
        piVar5 = (int *)FUN_1002a0f5();
        local_8._0_1_ = 0xd;
        FUN_1002b255(&local_1c,piVar5);
        local_8._0_1_ = 0xb;
        FUN_1002b168((int *)(local_6d + 1));
        pbVar8 = (byte *)FUN_10002180(&local_14);
        iVar3 = FUN_100022b0(&local_1c,pbVar8);
        if (iVar3 == 0) {
          local_5c = 1;
          FUN_1002b255(&local_3c,&local_44);
        }
      }
    }
    if ((local_5c == 0) && (local_18 == 1)) {
      FUN_1001e350((int *)local_58);
      FUN_1002b2a5(&local_14,s_Product__1003c094);
      while ((bVar1 = FUN_1002b8a9(local_58,&local_44), CONCAT31(extraout_var_00,bVar1) != 0 &&
             (local_5c == 0))) {
        pbVar8 = &DAT_1003c09e;
        pvVar4 = (void *)FUN_1002a0f5();
        local_8._0_1_ = 0xe;
        bVar1 = FUN_10002230(pvVar4,pbVar8);
        local_6d[0] = bVar1;
        local_8._0_1_ = 0xb;
        FUN_1002b168(&local_74);
        if ((local_6d._0_4_ & 0xff) == 0) {
          FUN_100021d0(&local_14);
          piVar5 = (int *)FUN_1002a0f5();
          local_8._0_1_ = 0xf;
          FUN_1002b255(&local_1c,piVar5);
          local_8._0_1_ = 0xb;
          FUN_1002b168(&local_78);
          pbVar8 = (byte *)FUN_10002180(&local_14);
          iVar3 = FUN_100022b0(&local_1c,pbVar8);
          if (iVar3 == 0) {
            local_5c = 1;
            FUN_1002b255(&local_3c,&local_44);
          }
        }
      }
    }
    if (local_5c == 0) {
      FUN_10030703(s_Error__Invalid_data_file___Produ_1003c0a0,0,0);
      FUN_1002b0f3(&local_40);
      FUN_10029f8c(param_1,-1,1);
      local_8._0_1_ = 10;
      FUN_1002b168(&local_1c);
      local_8._0_1_ = 9;
      FUN_1002b168(&local_40);
      local_8._0_1_ = 8;
      FUN_1002b168(&local_3c);
      local_8._0_1_ = 7;
      FUN_1002b168(&local_44);
      local_8._0_1_ = 6;
      FUN_1001e260(local_30);
      local_8._0_1_ = 5;
      CStdioFile::~CStdioFile(local_58);
      local_8._0_1_ = 4;
      FUN_1002b168(&local_14);
      local_8._0_1_ = 1;
      FUN_1002b168(&local_34);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168((int *)&stack0x00000008);
    }
    else {
      local_38 = FUN_1002a16d(&local_3c,0x3d);
      piVar5 = (int *)FUN_10029fc0(&local_7c);
      local_8._0_1_ = 0x10;
      FUN_1002b255(&local_40,piVar5);
      local_8._0_1_ = 0xb;
      FUN_1002b168(&local_7c);
      FUN_1002b9f6((int)local_58);
      FUN_1002aedd(param_1,&local_40);
      local_8._0_1_ = 10;
      FUN_1002b168(&local_1c);
      local_8._0_1_ = 9;
      FUN_1002b168(&local_40);
      local_8._0_1_ = 8;
      FUN_1002b168(&local_3c);
      local_8._0_1_ = 7;
      FUN_1002b168(&local_44);
      local_8._0_1_ = 6;
      FUN_1001e260(local_30);
      local_8._0_1_ = 5;
      CStdioFile::~CStdioFile(local_58);
      local_8._0_1_ = 4;
      FUN_1002b168(&local_14);
      local_8._0_1_ = 1;
      FUN_1002b168(&local_34);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1002b168((int *)&stack0x00000008);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



/* VA 1000a96b */

int __cdecl FUN_1000a96b(undefined4 param_1)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int local_10;

  local_10 = 0;
  hModule = LoadLibraryA(s_d3dtest_dll_1003c0e8);
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,s_D3DTEST_TestCard_1003c0f4);
    if (pFVar1 != (FARPROC)0x0) {
      local_10 = (*pFVar1)(param_1,0x3f000000);
    }
    FreeLibrary(hModule);
  }
  return local_10;
}



/* VA 1001da65 */

bool FUN_1001da65(void)

{
  bool bVar1;
  FARPROC pFVar2;
  int local_14;
  int local_10;
  HMODULE local_c;
  FARPROC local_8;

  bVar1 = false;
  local_8 = (FARPROC)0x0;
  local_c = (HMODULE)0x0;
  local_14 = 0;
  local_10 = 0;
  local_c = LoadLibraryA(s_glide3x_dll_1003d024);
  if (local_c == (HMODULE)0x0) {
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_Glide3x_dll_NOT_found_1003d10c);
    }
    bVar1 = false;
  }
  else {
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      FUN_1001f240(DAT_100416f8,(byte *)s_Glide3x_dll_found_1003d030);
    }
    local_8 = GetProcAddress(local_c,s__grGet_12_1003d044);
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      if (local_8 == (FARPROC)0x0) {
        FUN_1001f240(DAT_100416f8,(byte *)s_grGet_not_found_1003d060);
      }
      else {
        FUN_1001f240(DAT_100416f8,(byte *)s_grGet_found_1003d050);
      }
    }
    pFVar2 = GetProcAddress(local_c,s__grGetString_4_1003d074);
    if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
      if (local_8 == (FARPROC)0x0) {
        FUN_1001f240(DAT_100416f8,(byte *)s_grGetString_not_found_1003d098);
      }
      else {
        FUN_1001f240(DAT_100416f8,(byte *)s_grGetString_found_1003d084);
      }
    }
    if ((local_8 != (FARPROC)0x0) && (pFVar2 != (FARPROC)0x0)) {
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_about_to_call_grGetString_1003d0b0);
        FUN_1001fdc8(DAT_100416f8);
      }
      DAT_100406a8 = (*pFVar2)(0xa4);
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_version___s_1003d0cc);
        FUN_1001fdc8(DAT_100416f8);
      }
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_about_to_call_grGet_1003d0dc);
        FUN_1001fdc8(DAT_100416f8);
      }
      local_10 = (*local_8)(0xf,4,&local_14);
      bVar1 = 0 < local_14;
      if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
        FUN_1001f240(DAT_100416f8,(byte *)s_3dfx_boards_found____d_1003d0f4);
      }
    }
    FreeLibrary(local_c);
  }
  if ((DAT_100416fc != 0) && (DAT_100416f8 != (int *)0x0)) {
    if (bVar1) {
      FUN_1001f240(DAT_100416f8,(byte *)s_Glide_Detected_1003d124);
    }
    else {
      FUN_1001f240(DAT_100416f8,(byte *)s_Glide_Unavailable_1003d134);
    }
  }
  return bVar1;
}



/* VA 1001dd10 */

void __fastcall FUN_1001dd10(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_100320e3;
  local_10 = ExceptionList;
  local_8 = 9;
  ExceptionList = &local_10;
  FUN_1002b168((int *)(param_1 + 0x1044));
  local_8._0_1_ = 8;
  FUN_1002b168((int *)(param_1 + 0x1038));
  local_8._0_1_ = 7;
  FUN_1002b168((int *)(param_1 + 0x1034));
  local_8._0_1_ = 6;
  FUN_1002b168((int *)(param_1 + 0x102c));
  local_8._0_1_ = 5;
  FUN_1002b168((int *)(param_1 + 0x1028));
  local_8._0_1_ = 4;
  FUN_1002b168((int *)(param_1 + 0x1024));
  local_8._0_1_ = 3;
  FUN_1002b168((int *)(param_1 + 0xf20));
  local_8._0_1_ = 2;
  FUN_1002b168((int *)(param_1 + 0xf1c));
  local_8._0_1_ = 1;
  FUN_1002a71e();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1001f610(param_1 + 0x6a4,0x3c,0x22,FUN_1001dfc0);
  local_8 = 0xffffffff;
  FUN_1001f610(param_1,100,0x11,FUN_1001df40);
  ExceptionList = local_10;
  return;
}



/* VA 1001de20 */

int __fastcall FUN_1001de20(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10032193;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001f704(param_1,100,0x11,FUN_1001e040);
  local_8 = 0;
  FUN_1001f704(param_1 + 0x6a4,0x3c,0x22,FUN_1001e0d0);
  local_8._0_1_ = 1;
  FUN_1002a6aa((void *)(param_1 + 0xe9c),10);
  local_8._0_1_ = 2;
  FUN_10002250((undefined4 *)(param_1 + 0xf1c));
  local_8._0_1_ = 3;
  FUN_10002250((undefined4 *)(param_1 + 0xf20));
  local_8._0_1_ = 4;
  FUN_10002250((undefined4 *)(param_1 + 0x1024));
  local_8._0_1_ = 5;
  FUN_10002250((undefined4 *)(param_1 + 0x1028));
  local_8._0_1_ = 6;
  FUN_10002250((undefined4 *)(param_1 + 0x102c));
  local_8._0_1_ = 7;
  FUN_10002250((undefined4 *)(param_1 + 0x1034));
  local_8._0_1_ = 8;
  FUN_10002250((undefined4 *)(param_1 + 0x1038));
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_10002250((undefined4 *)(param_1 + 0x1044));
  ExceptionList = local_10;
  return param_1;
}



/* VA 1001df40 */

void __fastcall FUN_1001df40(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_100321d0;
  local_10 = ExceptionList;
  local_8 = 3;
  ExceptionList = &local_10;
  FUN_1002a71e();
  local_8._0_1_ = 2;
  FUN_1002a71e();
  local_8._0_1_ = 1;
  FUN_1002b168((int *)(param_1 + 0x18));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168((int *)(param_1 + 0x14));
  local_8 = 0xffffffff;
  FUN_1002b168((int *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}



/* VA 1001dfc0 */

void __fastcall FUN_1001dfc0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;

  puStack_c = &LAB_10032210;
  local_10 = ExceptionList;
  local_8 = 3;
  ExceptionList = &local_10;
  FUN_1002a71e();
  local_8._0_1_ = 2;
  FUN_1002b168((int *)(param_1 + 0x10));
  local_8._0_1_ = 1;
  FUN_1002b168((int *)(param_1 + 0xc));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1002b168((int *)(param_1 + 8));
  local_8 = 0xffffffff;
  FUN_1002b168((int *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}



/* VA 1001e040 */

int __fastcall FUN_1001e040(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10032250;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002250((undefined4 *)(param_1 + 4));
  local_8 = 0;
  FUN_10002250((undefined4 *)(param_1 + 0x14));
  local_8._0_1_ = 1;
  FUN_10002250((undefined4 *)(param_1 + 0x18));
  local_8._0_1_ = 2;
  FUN_1002a6aa((void *)(param_1 + 0x20),10);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_1002a6aa((void *)(param_1 + 0x48),10);
  ExceptionList = local_10;
  return param_1;
}



/* VA 1001e0d0 */

int __fastcall FUN_1001e0d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10032290;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002250((undefined4 *)(param_1 + 4));
  local_8 = 0;
  FUN_10002250((undefined4 *)(param_1 + 8));
  local_8._0_1_ = 1;
  FUN_10002250((undefined4 *)(param_1 + 0xc));
  local_8._0_1_ = 2;
  FUN_10002250((undefined4 *)(param_1 + 0x10));
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_1002a6aa((void *)(param_1 + 0x20),10);
  ExceptionList = local_10;
  return param_1;
}



/* VA 1001e150 */

undefined4 * __thiscall
FUN_1001e150(void *this,undefined4 param_1,undefined4 param_2,LPCSTR param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &LAB_10032b85;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1002ba61((int)this);
  local_8 = 0;
  FUN_10002250((undefined4 *)((int)this + 0x10));
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined ***)this = &PTR_LAB_100344b4;
  *(undefined4 *)((int)this + 8) = param_1;
  *(undefined4 *)((int)this + 0xc) = param_2;
  FUN_1002b2a5((void *)((int)this + 0x10),param_3);
  ExceptionList = local_10;
  return this;
}



/* VA 1001e1d0 */

void FUN_1001e1d0(void)

{
  return;
}



/* VA 1001e1e0 */

void FUN_1001e1e0(void)

{
  FUN_1001e200();
  return;
}



/* VA 1001e200 */

void FUN_1001e200(void)

{
  return;
}



/* VA 1001e210 */

undefined4 * __thiscall FUN_1001e210(void *this,uint param_1)

{
  FUN_1001e260(this);
  if ((param_1 & 1) != 0) {
    FUN_1001e240(this);
  }
  return this;
}



/* VA 1001e240 */

void FUN_1001e240(undefined *param_1)

{
  FUN_1002becb(param_1);
  return;
}



/* VA 1001e260 */

void __fastcall FUN_1001e260(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;

  puStack_c = &LAB_10032b99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_LAB_100344b4;
  local_8 = 0;
  FUN_1002b168(param_1 + 4);
  local_8 = 0xffffffff;
  FUN_1001e1e0();
  ExceptionList = local_10;
  return;
}



/* VA 1001e2c0 */

undefined4 __fastcall FUN_1001e2c0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



/* VA 1001e2e0 */

void * __thiscall FUN_1001e2e0(void *this,void *param_1,int param_2)

{
  FUN_1002aedd(param_1,(int *)(*(int *)((int)this + 4) + param_2 * 4));
  return param_1;
}



/* VA 1001e320 */

/* Library Function - Multiple Matches With Same Base Name
    public: int __thiscall CArray<int,int>::Add(int)
    public: int __thiscall CArray<unsigned int,unsigned int>::Add(unsigned int)
    public: int __thiscall CArray<long,long>::Add(long)
    public: int __thiscall CArray<unsigned long,unsigned long>::Add(unsigned long)
     29 names - too many to list

   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

int __thiscall Add(void *this,LPCSTR param_1)

{
  int iVar1;

  iVar1 = *(int *)((int)this + 8);
  FUN_1002ab0a(this,iVar1,param_1);
  return iVar1;
}



/* VA 1001e350 */

void __fastcall FUN_1001e350(int *param_1)

{
  (**(code **)(*param_1 + 0x28))(0,0);
  return;
}



/* VA 1001e370 */

bool FUN_1001e370(void *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  int iVar2;

  pbVar1 = (byte *)FUN_10002180(param_2);
  iVar2 = FUN_10002190(param_1,pbVar1);
  return (bool)('\x01' - (iVar2 != 0));
}



/* VA 1001e38e */

void DirectDrawCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001e38e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawCreate();
  return;
}



/* VA 1001e394 */

void DirectDrawEnumerateExA(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001e394. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawEnumerateExA();
  return;
}



/* VA 1001e39a */

BOOL VerQueryValueA(LPCVOID pBlock,LPCSTR lpSubBlock,LPVOID *lplpBuffer,PUINT puLen)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x1001e39a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = VerQueryValueA(pBlock,lpSubBlock,lplpBuffer,puLen);
  return BVar1;
}



/* VA 1001e3a0 */

BOOL GetFileVersionInfoA(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x1001e3a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetFileVersionInfoA(lptstrFilename,dwHandle,dwLen,lpData);
  return BVar1;
}



/* VA 1001e3a6 */

DWORD GetFileVersionInfoSizeA(LPCSTR lptstrFilename,LPDWORD lpdwHandle)

{
  DWORD DVar1;

                    /* WARNING: Could not recover jumptable at 0x1001e3a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetFileVersionInfoSizeA(lptstrFilename,lpdwHandle);
  return DVar1;
}



/* VA 1001e3ac */

int FUN_1001e3ac(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;

  if (param_2 != 1) {
    if (param_2 == 0) {
      iVar3 = FUN_1003147e();
      if (*(int **)(iVar3 + 4) != (int *)0x0) {
        (**(code **)(**(int **)(iVar3 + 4) + 0x68))();
      }
      FUN_1002c032();
      FUN_1002c03b(0xffffffff);
      FUN_10031f04();
      FUN_1003115d(param_1,1);
    }
    else if (param_2 == 3) {
      FUN_1002c032();
      FUN_1002c03b(0xffffffff);
      FUN_1002bf4a();
    }
    return 1;
  }
  param_2 = 0;
  iVar3 = FUN_1003124c();
  uVar1 = *(undefined4 *)(iVar3 + 8);
  iVar4 = FUN_10031503(param_1,0,&DAT_100343fc,0);
  if (iVar4 != 0) {
    iVar4 = FUN_1003147e();
    piVar2 = *(int **)(iVar4 + 4);
    if ((piVar2 == (int *)0x0) || (iVar4 = (**(code **)(*piVar2 + 0x50))(), iVar4 != 0)) {
      *(undefined4 *)(iVar3 + 8) = uVar1;
      FUN_10031147(param_1);
      param_2 = 1;
      goto LAB_1001e413;
    }
    (**(code **)(*piVar2 + 0x68))();
  }
  FUN_10031f04();
LAB_1001e413:
  *(undefined4 *)(iVar3 + 8) = uVar1;
  return param_2;
}



/* VA 1001e4a3 */

undefined4 FUN_1001e4a3(void)

{
  CWinThread *pCVar1;
  undefined4 uVar2;

  pCVar1 = AfxGetThread();
  if (pCVar1 != (CWinThread *)0x0) {
    uVar2 = (**(code **)(*(int *)pCVar1 + 0x74))();
    return uVar2;
  }
  return 0;
}



/* VA 1001e4c6 */

undefined4 * __thiscall FUN_1001e4c6(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_1002ba6b(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_LAB_10034550;
  return this;
}



/* VA 1001e4f0 */

undefined4 * __thiscall FUN_1001e4f0(void *this,byte param_1)

{
  FUN_1001e50c(this);
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1001e50c */

void __fastcall FUN_1001e50c(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_10034550;
  return;
}



/* VA 1001e513 */

undefined4 * __thiscall FUN_1001e513(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_1002ba6b(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_LAB_10034568;
  return this;
}



/* VA 1001e53d */

undefined4 * __thiscall FUN_1001e53d(void *this,byte param_1)

{
  FUN_1001e559(this);
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1001e559 */

void __fastcall FUN_1001e559(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_10034568;
  return;
}



/* VA 1001e560 */

undefined * __thiscall FUN_1001e560(void *this,byte param_1)

{
  FUN_1001e57c();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1001e57c */

void FUN_1001e57c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_100345e4;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_1002c259((int)extraout_ECX);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_1002ace5();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1002ace5();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1001e5c5 */

undefined4 * __thiscall FUN_1001e5c5(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
  return this;
}



/* VA 1001e5ed */

void __fastcall FUN_1001e5ed(int param_1)

{
  FUN_1001e601(param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  return;
}



/* VA 1001e601 */

void __fastcall FUN_1001e601(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  FUN_1002abbf(*(undefined4 **)(param_1 + 8));
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  return;
}



/* VA 1001e629 */

int * FUN_1001e629(void)

{
  int iVar1;
  int *piVar2;
  int *extraout_ECX;
  int iVar3;
  int unaff_EBP;

  FUN_10020434();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  EnterCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 4));
  if (extraout_ECX[3] == 0) {
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar1 = FUN_1002ab9f(extraout_ECX + 2,extraout_ECX[1],iVar3);
    iVar3 = extraout_ECX[1];
    piVar2 = (int *)((iVar3 + -1) * *extraout_ECX + 4 + iVar1);
    if (-1 < iVar3 + -1) {
      do {
        *piVar2 = extraout_ECX[3];
        extraout_ECX[3] = (int)piVar2;
        piVar2 = (int *)((int)piVar2 - *extraout_ECX);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  piVar2 = (int *)extraout_ECX[3];
  extraout_ECX[3] = *piVar2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 4));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar2;
}



/* VA 1001e6a2 */

void Catch_1001e6a2(void)

{
  int unaff_EBP;

  LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 0x10));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}



/* VA 1001e6b8 */

void __thiscall FUN_1001e6b8(void *this,undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
    *param_1 = *(undefined4 *)((int)this + 0xc);
    *(undefined4 **)((int)this + 0xc) = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
  }
  return;
}



/* VA 1001e6e4 */

int __thiscall FUN_1001e6e4(void *this,undefined1 param_1)

{
  if (*(uint *)((int)this + 0x28) < *(int *)((int)this + 0x24) + 1U) {
    FUN_1002fc25((int)this);
  }
  **(undefined1 **)((int)this + 0x24) = param_1;
  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 1;
  return (int)this;
}



/* VA 1001e707 */

int __thiscall FUN_1001e707(void *this,undefined2 param_1)

{
  if (*(uint *)((int)this + 0x28) < *(int *)((int)this + 0x24) + 2U) {
    FUN_1002fc25((int)this);
  }
  **(undefined2 **)((int)this + 0x24) = param_1;
  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 2;
  return (int)this;
}



/* VA 1001e72e */

int __thiscall FUN_1001e72e(void *this,undefined4 param_1)

{
  if (*(uint *)((int)this + 0x28) < *(int *)((int)this + 0x24) + 4U) {
    FUN_1002fc25((int)this);
  }
  **(undefined4 **)((int)this + 0x24) = param_1;
  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 4;
  return (int)this;
}



/* VA 1001e754 */

void * __thiscall FUN_1001e754(void *this,undefined1 *param_1)

{
  if (*(uint *)((int)this + 0x28) < *(int *)((int)this + 0x24) + 1U) {
    FUN_1002fca1(this,(*(int *)((int)this + 0x24) - *(uint *)((int)this + 0x28)) + 1);
  }
  *param_1 = **(undefined1 **)((int)this + 0x24);
  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 1;
  return this;
}



/* VA 1001e783 */

void * __thiscall FUN_1001e783(void *this,undefined2 *param_1)

{
  if (*(uint *)((int)this + 0x28) < *(int *)((int)this + 0x24) + 2U) {
    FUN_1002fca1(this,(*(int *)((int)this + 0x24) - *(uint *)((int)this + 0x28)) + 2);
  }
  *param_1 = **(undefined2 **)((int)this + 0x24);
  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 2;
  return this;
}



/* VA 1001e7b6 */

void * __thiscall FUN_1001e7b6(void *this,undefined4 *param_1)

{
  if (*(uint *)((int)this + 0x28) < *(int *)((int)this + 0x24) + 4U) {
    FUN_1002fca1(this,(*(int *)((int)this + 0x24) - *(uint *)((int)this + 0x28)) + 4);
  }
  *param_1 = **(undefined4 **)((int)this + 0x24);
  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 4;
  return this;
}



/* VA 1001e7e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1001e7e8(void)

{
  HMODULE hModule;
  bool bVar1;

  if (DAT_100435e8 == 0) {
    hModule = GetModuleHandleA("USER32");
    if ((((hModule != (HMODULE)0x0) &&
         (_DAT_100435d0 = GetProcAddress(hModule,"GetSystemMetrics"), _DAT_100435d0 != (FARPROC)0x0)
         ) && (DAT_100435d4 = GetProcAddress(hModule,"MonitorFromWindow"),
              DAT_100435d4 != (FARPROC)0x0)) &&
       (((DAT_100435d8 = GetProcAddress(hModule,"MonitorFromRect"), DAT_100435d8 != (FARPROC)0x0 &&
         (_DAT_100435dc = GetProcAddress(hModule,"MonitorFromPoint"), _DAT_100435dc != (FARPROC)0x0)
         ) && ((_DAT_100435e4 = GetProcAddress(hModule,"EnumDisplayMonitors"),
               _DAT_100435e4 != (FARPROC)0x0 &&
               (DAT_100435e0 = GetProcAddress(hModule,"GetMonitorInfoA"),
               DAT_100435e0 != (FARPROC)0x0)))))) {
      DAT_100435e8 = 1;
      return true;
    }
    _DAT_100435d0 = (FARPROC)0x0;
    DAT_100435d4 = (FARPROC)0x0;
    DAT_100435d8 = (FARPROC)0x0;
    _DAT_100435dc = (FARPROC)0x0;
    DAT_100435e0 = (FARPROC)0x0;
    _DAT_100435e4 = (FARPROC)0x0;
    DAT_100435e8 = 1;
    bVar1 = false;
  }
  else {
    bVar1 = DAT_100435e0 != (FARPROC)0x0;
  }
  return bVar1;
}



/* VA 1001e8c0 */

undefined4 FUN_1001e8c0(int *param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  int iVar3;

  bVar1 = FUN_1001e7e8();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (((param_2 & 3) == 0) &&
       ((((param_1[2] < 1 || (param_1[3] < 1)) || (iVar3 = GetSystemMetrics(0), iVar3 <= *param_1))
        || (iVar3 = GetSystemMetrics(1), iVar3 <= param_1[1])))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x12340042;
    }
    return uVar2;
  }
  uVar2 = (*DAT_100435d8)(param_1,param_2);
  return uVar2;
}



/* VA 1001e916 */

/* Library Function - Single Match
    _xMonitorFromWindow@8

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release
   __stdcall xMonitorFromWindow,8 */

undefined4 xMonitorFromWindow(HWND param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  BOOL BVar3;
  int iVar4;
  WINDOWPLACEMENT local_30;

  bVar1 = FUN_1001e7e8();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if ((param_2 & 3) == 0) {
      BVar3 = IsIconic(param_1);
      if (BVar3 == 0) {
        iVar4 = GetWindowRect(param_1,&local_30.rcNormalPosition);
      }
      else {
        iVar4 = GetWindowPlacement(param_1,&local_30);
      }
      if (iVar4 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_1001e8c0(&local_30.rcNormalPosition.left,param_2);
      }
    }
    else {
      uVar2 = 0x12340042;
    }
  }
  else {
    uVar2 = (*DAT_100435d4)(param_1,param_2);
  }
  return uVar2;
}



/* VA 1001e981 */

undefined4 FUN_1001e981(int param_1,uint *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  BOOL BVar3;
  uint uVar4;
  uint local_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;

  bVar1 = FUN_1001e7e8();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if ((((param_1 == 0x12340042) && (param_2 != (uint *)0x0)) && (0x27 < *param_2)) &&
       (BVar3 = SystemParametersInfoA(0x30,0,&local_14,0), BVar3 != 0)) {
      param_2[1] = 0;
      param_2[2] = 0;
      uVar4 = GetSystemMetrics(0);
      param_2[3] = uVar4;
      uVar4 = GetSystemMetrics(1);
      param_2[5] = local_14;
      param_2[6] = uStack_10;
      param_2[7] = uStack_c;
      param_2[8] = uStack_8;
      uVar2 = 1;
      param_2[4] = uVar4;
      param_2[9] = 1;
      if (0x47 < *param_2) {
        lstrcpyA((LPSTR)(param_2 + 10),"DISPLAY");
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = (*DAT_100435e0)(param_1,param_2);
  }
  return uVar2;
}



/* VA 1001ea14 */

/* Library Function - Single Match
    public: class CWnd * __thiscall CWnd::GetOwner(void)const

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

CWnd * __thiscall CWnd::GetOwner(CWnd *this)

{
  CWnd *pCVar1;

  if (*(int *)(this + 0x20) == 0) {
    GetParent(*(HWND *)(this + 0x1c));
  }
  pCVar1 = FUN_1002d53a();
  return pCVar1;
}



/* VA 1001ea46 */

void FUN_1001ea46(void)

{
  FUN_1003147e();
  FUN_1002ce8d();
  return;
}



/* VA 1001ea53 */

undefined * __thiscall FUN_1001ea53(void *this,byte param_1)

{
  FUN_1001ea6f();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1001ea6f */

void FUN_1001ea6f(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_10034de0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002b168(extraout_ECX + 3);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1001ea9b */

undefined * __thiscall FUN_1001ea9b(void *this,byte param_1)

{
  FUN_1001eab7();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1001eab7 */

void FUN_1001eab7(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_10034e4c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002f908((int)extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1001eae0 */

undefined4 * __thiscall FUN_1001eae0(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_1002ba6b(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_LAB_10035070;
  return this;
}



/* VA 1001eb0a */

undefined4 * __thiscall FUN_1001eb0a(void *this,byte param_1)

{
  FUN_1001eb26(this);
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1001eb26 */

void __fastcall FUN_1001eb26(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_10035070;
  return;
}



/* VA 1001eb2d */

undefined4 * __thiscall FUN_1001eb2d(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_1002ba6b(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_LAB_10035088;
  return this;
}



/* VA 1001eb57 */

undefined4 * __thiscall FUN_1001eb57(void *this,byte param_1)

{
  FUN_1001eb73(this);
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1001eb73 */

void __fastcall FUN_1001eb73(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_10035088;
  return;
}



/* VA 1001eb7a */

undefined * __thiscall FUN_1001eb7a(void *this,byte param_1)

{
  FUN_1001eb96();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1001eb96 */

void FUN_1001eb96(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_10034fd8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_100305d8((int)extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1001ebff */

void __thiscall
FUN_1001ebff(void *this,int param_1,int param_2,UINT param_3,RECT *param_4,LPCSTR param_5,
            UINT param_6,INT *param_7)

{
  ExtTextOutA(*(HDC *)((int)this + 4),param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* VA 1001ec24 */

int * __thiscall
FUN_1001ec24(void *this,int *param_1,int param_2,int param_3,LPCSTR param_4,int param_5,int param_6,
            INT *param_7,int param_8)

{
  LONG LVar1;

  LVar1 = TabbedTextOutA(*(HDC *)((int)this + 4),param_2,param_3,param_4,param_5,param_6,param_7,
                         param_8);
  param_1[1] = (int)(short)((uint)LVar1 >> 0x10);
  *param_1 = (int)(short)LVar1;
  return param_1;
}



/* VA 1001ec78 */

void __thiscall
FUN_1001ec78(void *this,int param_1,GRAYSTRINGPROC param_2,LPARAM param_3,int param_4,int param_5,
            int param_6,int param_7,int param_8)

{
  HBRUSH hBrush;

  hBrush = (HBRUSH)0x0;
  if (param_1 != 0) {
    hBrush = *(HBRUSH *)(param_1 + 4);
  }
  GrayStringA(*(HDC *)((int)this + 4),hBrush,param_2,param_3,param_4,param_5,param_6,param_7,param_8
             );
  return;
}



/* VA 1001ecc4 */

void FUN_1001ecc4(undefined *UNRECOVERED_JUMPTABLE)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x1001ecef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* VA 1001ecf8 */

void FUN_1001ecf8(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x1001ecfd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* VA 1001ecff */

void FUN_1001ecff(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x1001ed04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* VA 1001ed06 */

void FUN_1001ed06(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;

  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x1001ed2e,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}



/* VA 1001ed55 */

undefined4 __cdecl
FUN_1001ed55(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;

  uVar1 = FUN_1002232a(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,'\0');
  return uVar1;
}



/* VA 1001ed8b */

undefined4 __cdecl
FUN_1001ed8b(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  void *local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_10 = param_2;
  local_14 = FUN_1001eddf;
  local_8 = param_4 + 1;
  local_c = param_1;
  local_18 = ExceptionList;
  ExceptionList = &local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  ExceptionList = local_18;
  return uVar1;
}



/* VA 1001eddf */

void __cdecl FUN_1001eddf(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_1002232a(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,'\0');
  return;
}



/* VA 1001ee04 */

undefined4 __cdecl
FUN_1001ee04(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;

  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = FUN_1001eeba;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x1001ee8c;
  local_2c = ExceptionList;
  ExceptionList = &local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_10022c01();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 != 0) {
    *local_2c = *(undefined4 *)ExceptionList;
  }
  ExceptionList = local_2c;
  return 0;
}



/* VA 1001eeba */

undefined4 __cdecl FUN_1001eeba(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;

  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_1002232a(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_1001ed06(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x1001ef24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}



/* VA 1001ef2f */

int __cdecl FUN_1001ef2f(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;

  uVar5 = *(uint *)(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 0x10);
  uVar4 = uVar5;
  uVar3 = uVar5;
  while (uVar2 = uVar4, -1 < param_2) {
    if (uVar5 == 0xffffffff) {
      FUN_10022d69();
    }
    uVar5 = uVar5 - 1;
    if (((*(int *)(iVar1 + 4 + uVar5 * 0x14) < param_3) &&
        (param_3 <= *(int *)(iVar1 + uVar5 * 0x14 + 8))) || (uVar4 = uVar2, uVar5 == 0xffffffff)) {
      param_2 = param_2 + -1;
      uVar4 = uVar5;
      uVar3 = uVar2;
    }
  }
  uVar5 = uVar5 + 1;
  *param_4 = uVar5;
  *param_5 = uVar3;
  if ((*(uint *)(param_1 + 0xc) < uVar3) || (uVar3 < uVar5)) {
    FUN_10022d69();
  }
  return iVar1 + uVar5 * 0x14;
}



/* VA 1001efac */

/* Library Function - Single Match
    __global_unwind2

   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x1001efc4,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



/* VA 1001efee */

/* Library Function - Single Match
    __local_unwind2

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;

  iStack_10 = param_1;
  puStack_18 = &LAB_1001efcc;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_1001f082();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}



/* VA 1001f056 */

/* Library Function - Single Match
    __abnormal_termination

   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;

  iVar1 = 0;
  if ((*(undefined1 **)((int)ExceptionList + 4) == &LAB_1001efcc) &&
     (*(int *)((int)ExceptionList + 8) == *(int *)(*(int *)((int)ExceptionList + 0xc) + 0xc))) {
    iVar1 = 1;
  }
  return iVar1;
}



/* VA 1001f079 */

/* Library Function - Single Match
    __NLG_Notify1

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;

  DAT_1003d6e0 = param_1;
  DAT_1003d6dc = in_EAX;
  DAT_1003d6e4 = unaff_EBP;
  return;
}



/* VA 1001f082 */

void FUN_1001f082(void)

{
  undefined4 in_EAX;
  int unaff_EBP;

  DAT_1003d6e0 = *(undefined4 *)(unaff_EBP + 8);
  DAT_1003d6dc = in_EAX;
  DAT_1003d6e4 = unaff_EBP;
  return;
}



/* VA 1001f09a */

int __cdecl FUN_1001f09a(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;

  if (DAT_10044d6c == 0) {
    iVar3 = _strcmp((char *)param_1,(char *)param_2);
  }
  else {
    FUN_10022e54(0x19);
    pbVar5 = param_2;
    do {
      param_2._0_2_ = (ushort)*param_1;
      pbVar7 = param_1 + 1;
      if ((*(byte *)((int)&DAT_10044e80 + (ushort)param_2 + 1) & 4) != 0) {
        bVar1 = *pbVar7;
        if (bVar1 == 0) {
          param_2._0_2_ = 0;
        }
        else {
          pbVar7 = param_1 + 2;
          param_2._0_2_ = CONCAT11(*param_1,bVar1);
        }
      }
      bVar1 = *pbVar5;
      uVar4 = (ushort)bVar1;
      pbVar6 = pbVar5 + 1;
      if ((*(byte *)((int)&DAT_10044e80 + bVar1 + 1) & 4) != 0) {
        bVar2 = *pbVar6;
        if (bVar2 == 0) {
          uVar4 = 0;
        }
        else {
          pbVar6 = pbVar5 + 2;
          uVar4 = CONCAT11(bVar1,bVar2);
        }
      }
      if ((ushort)param_2 != uVar4) {
        FUN_10022eb5(0x19);
        return (-(uint)(uVar4 < (ushort)param_2) & 2) - 1;
      }
      pbVar5 = pbVar6;
      param_1 = pbVar7;
    } while ((ushort)param_2 != 0);
    FUN_10022eb5(0x19);
    iVar3 = 0;
  }
  return iVar3;
}



/* VA 1001f150 */

uint * __cdecl FUN_1001f150(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;

  puVar4 = param_1;
  while (((uint)param_2 & 3) != 0) {
    bVar1 = (byte)*param_2;
    uVar3 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_1001f238;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_1001f238:
        *(byte *)puVar4 = (byte)uVar3;
        return param_1;
      }
      if ((char)(uVar3 >> 8) == '\0') {
        *(short *)puVar4 = (short)uVar3;
        return param_1;
      }
      if ((uVar3 & 0xff0000) == 0) {
        *(short *)puVar4 = (short)uVar3;
        *(byte *)((int)puVar4 + 2) = 0;
        return param_1;
      }
      if ((uVar3 & 0xff000000) == 0) {
        *puVar4 = uVar3;
        return param_1;
      }
    }
    *puVar4 = uVar3;
    puVar4 = puVar4 + 1;
  } while( true );
}



/* VA 1001f160 */

uint * __cdecl FUN_1001f160(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;

  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_1001f17c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_1001f1af;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x1001f1cb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_1001f17c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x1001f1cb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x1001f1cb;
    }
  }
LAB_1001f1af:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x1001f1cb:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_1001f238:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_1001f238;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}



/* VA 1001f240 */

int __cdecl FUN_1001f240(int *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;

  FUN_10022f86((uint)param_1);
  iVar1 = FUN_1002302a(param_1);
  iVar2 = FUN_100230e1(param_1,param_2,(undefined4 *)&stack0x0000000c);
  FUN_100230b7(iVar1,param_1);
  FUN_10022fd8((uint)param_1);
  return iVar2;
}



/* VA 1001f280 */

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
    if (((uint)puVar2 & 3) == 0) goto LAB_1001f2a0;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_1001f2d3:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_1001f2a0:
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
  goto LAB_1001f2d3;
}



/* VA 1001f2fb */

uint __thiscall FUN_1001f2fb(void *this,byte *param_1,byte *param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  ushort uVar6;
  ushort uVar7;
  byte *local_10;
  byte *local_c;
  byte local_8;
  byte local_7;

  if (DAT_10044d6c == 0) {
    uVar2 = FUN_10023b10(this,param_1,param_2);
  }
  else {
    FUN_10022e54(0x19);
    local_10 = param_2 + -1;
    local_c = param_1 + -1;
    do {
      uVar2 = (uint)*param_1;
      pbVar5 = param_1 + 1;
      pbVar1 = local_c + 1;
      if ((*(byte *)((int)&DAT_10044e80 + uVar2 + 1) & 4) == 0) {
        param_1 = pbVar5;
        local_c = pbVar1;
        if ((*(byte *)((int)&DAT_10044e80 + uVar2 + 1) & 0x10) == 0x10) {
          uVar2 = (uint)(byte)(&DAT_10044d80)[uVar2];
        }
      }
      else if (*pbVar5 == 0) {
        uVar2 = 0;
        param_1 = pbVar5;
        local_c = pbVar1;
      }
      else {
        iVar4 = FUN_100238eb(DAT_10044f84,0x200,(char *)pbVar1,2,(LPWSTR)&local_8,2,DAT_10044d54,1);
        if (iVar4 == 1) {
          uVar2 = (uint)local_8;
        }
        else {
          if (iVar4 != 2) goto LAB_1001f45f;
          uVar2 = (uint)local_8 * 0x100 + (uint)local_7;
        }
        param_1 = param_1 + 2;
        local_c = local_c + 2;
      }
      uVar3 = (uint)*param_2;
      uVar6 = (ushort)*param_2;
      pbVar5 = param_2 + 1;
      pbVar1 = local_10 + 1;
      if ((*(byte *)((int)&DAT_10044e80 + uVar3 + 1) & 4) == 0) {
        param_2 = pbVar5;
        local_10 = pbVar1;
        if ((*(byte *)((int)&DAT_10044e80 + uVar3 + 1) & 0x10) == 0x10) {
          uVar6 = (ushort)(byte)(&DAT_10044d80)[uVar3];
        }
      }
      else if (*pbVar5 == 0) {
        uVar6 = 0;
        param_2 = pbVar5;
        local_10 = pbVar1;
      }
      else {
        iVar4 = FUN_100238eb(DAT_10044f84,0x200,(char *)pbVar1,2,(LPWSTR)&local_8,2,DAT_10044d54,1);
        if (iVar4 == 1) {
          uVar6 = (ushort)local_8;
        }
        else {
          if (iVar4 != 2) {
LAB_1001f45f:
            FUN_10022eb5(0x19);
            return 0x7fffffff;
          }
          uVar6 = (ushort)local_8 * 0x100 + (ushort)local_7;
        }
        param_2 = param_2 + 2;
        local_10 = local_10 + 2;
      }
      uVar7 = (ushort)uVar2;
      if (uVar7 != uVar6) {
        FUN_10022eb5(0x19);
        return (-(uint)(uVar6 < uVar7) & 2) - 1;
      }
    } while (uVar7 != 0);
    FUN_10022eb5(0x19);
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 1001f490 */

undefined4 * __cdecl FUN_1001f490(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  puVar1 = FUN_10023d50();
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = FUN_10023be0(param_1,param_2,param_3,puVar1);
  FUN_10022fd8((uint)puVar1);
  return puVar2;
}



/* VA 1001f4c1 */

void __cdecl FUN_1001f4c1(LPCSTR param_1,char *param_2)

{
  FUN_1001f490(param_1,param_2,0x40);
  return;
}



/* VA 1001f4d4 */

undefined4 __cdecl FUN_1001f4d4(FILE *param_1)

{
  undefined4 uVar1;

  uVar1 = 0xffffffff;
  if ((param_1->_flag & 0x40) == 0) {
    FUN_10022f86((uint)param_1);
    uVar1 = __fclose_lk(param_1);
    FUN_10022fd8((uint)param_1);
  }
  else {
    param_1->_flag = 0;
  }
  return uVar1;
}



/* VA 1001f505 */

/* Library Function - Single Match
    __fclose_lk

   Library: Visual Studio 2003 Release */

undefined4 __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;

  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_1001fe25((int *)param_1);
    __freebuf(param_1);
    iVar1 = FUN_10023e18(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      FUN_1001fabf(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}



/* VA 1001f551 */

undefined4 __cdecl FUN_1001f551(undefined4 param_1)

{
  byte *pbVar1;
  SIZE_T SVar2;

  FUN_100222fe();
  pbVar1 = (byte *)FUN_1002168e(DAT_10044d50);
  if (pbVar1 < DAT_10044d4c + (4 - (int)DAT_10044d50)) {
    SVar2 = FUN_1002168e(DAT_10044d50);
    pbVar1 = FUN_10023f23(DAT_10044d50,(uint *)(SVar2 + 0x10));
    if (pbVar1 == (byte *)0x0) {
      param_1 = 0;
      goto LAB_1001f5c6;
    }
    DAT_10044d4c = pbVar1 + ((int)DAT_10044d4c - (int)DAT_10044d50 >> 2) * 4;
    DAT_10044d50 = pbVar1;
  }
  *(undefined4 *)DAT_10044d4c = param_1;
  DAT_10044d4c = DAT_10044d4c + 4;
LAB_1001f5c6:
  FUN_10022307();
  return param_1;
}



/* VA 1001f5cf */

int __cdecl FUN_1001f5cf(undefined4 param_1)

{
  int iVar1;

  iVar1 = FUN_1001f551(param_1);
  return (iVar1 != 0) - 1;
}



/* VA 1001f610 */

void FUN_1001f610(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_100350a0;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*(code *)param_4)();
  }
  local_8 = 0xffffffff;
  FUN_1001f678();
  ExceptionList = local_14;
  return;
}



/* VA 1001f678 */

void FUN_1001f678(void)

{
  int unaff_EBP;

  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    FUN_1001f690(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(int *)(unaff_EBP + 0x10),*(undefined **)(unaff_EBP + 0x14));
  }
  return;
}



/* VA 1001f690 */

void FUN_1001f690(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_100350b0;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*(code *)param_4)();
  }
  ExceptionList = local_14;
  return;
}



/* VA 1001f704 */

void FUN_1001f704(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_100350c0;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  for (local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
    (*(code *)param_4)();
  }
  local_8 = 0xffffffff;
  FUN_1001f76e();
  ExceptionList = local_14;
  return;
}



/* VA 1001f76e */

void FUN_1001f76e(void)

{
  int unaff_EBP;

  if (*(int *)(unaff_EBP + -0x20) == 0) {
    FUN_1001f690(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                 *(int *)(unaff_EBP + -0x1c),*(undefined **)(unaff_EBP + 0x18));
  }
  return;
}



/* VA 1001f790 */

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



/* VA 1001f7e8 */

int __cdecl FUN_1001f7e8(byte *param_1)

{
  int iVar1;
  int iVar2;

  FUN_10022fb5(1,0x1003db38);
  iVar1 = FUN_1002302a((undefined4 *)&DAT_1003db38);
  iVar2 = FUN_100230e1((int *)&DAT_1003db38,param_1,(undefined4 *)&stack0x00000008);
  FUN_100230b7(iVar1,(int *)&DAT_1003db38);
  FUN_10023007(1,0x1003db38);
  return iVar2;
}



/* VA 1001f8f1 */

void FUN_1001f8f1(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



/* VA 1001f90c */

int __cdecl FUN_1001f90c(uchar *param_1)

{
  int iVar1;

  FUN_10022e54(0xc);
  iVar1 = FUN_1001f92d(param_1);
  FUN_10022eb5(0xc);
  return iVar1;
}



/* VA 1001f92d */

int __cdecl FUN_1001f92d(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;

  if (((DAT_10044d44 != 0) &&
      ((DAT_100438ac != (int *)0x0 ||
       (((DAT_100438b4 != 0 && (iVar1 = FUN_10024291(), iVar1 == 0)) && (DAT_100438ac != (int *)0x0)
        ))))) && (piVar3 = DAT_100438ac, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {
        return *piVar3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}



/* VA 1001f9b0 */

/* Library Function - Single Match
    _strcmp

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;

  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_1001f9f4;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_1001f9c0;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_1001f9f4;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_1001f9f4;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_1001f9c0:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)_Str2[2];
    if (bVar4 != _Str2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_1001f9f4:
  return (uint)bVar5 * -2 + 1;
}



/* VA 1001fa34 */

int __cdecl FUN_1001fa34(undefined1 *param_1,byte *param_2)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;

  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_100230e1((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_100242ff(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}



/* VA 1001fa90 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1001fa90(void)

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



/* VA 1001fabf */

void __cdecl FUN_1001fabf(undefined *param_1)

{
  uint *puVar1;
  int local_2c;
  uint *local_28;
  uint local_24;
  uint *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_100350d0;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  if (param_1 == (undefined *)0x0) {
    return;
  }
  if (DAT_10043d24 == 3) {
    ExceptionList = &local_14;
    FUN_10022e54(9);
    local_8 = 0;
    local_20 = (uint *)FUN_100246d9((int)param_1);
    if (local_20 != (uint *)0x0) {
      FUN_10024704(local_20,(int)param_1);
    }
    local_8 = 0xffffffff;
    FUN_1001fb29();
    puVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (DAT_10043d24 != 2) goto LAB_1001fb8b;
    ExceptionList = &local_14;
    FUN_10022e54(9);
    local_8 = 1;
    local_28 = (uint *)FUN_10025434(param_1,&local_2c,&local_24);
    if (local_28 != (uint *)0x0) {
      FUN_1002548b(local_2c,local_24,(byte *)local_28);
    }
    local_8 = 0xffffffff;
    FUN_1001fb81();
    puVar1 = local_28;
  }
  if (puVar1 != (uint *)0x0) {
    ExceptionList = local_14;
    return;
  }
LAB_1001fb8b:
  HeapFree(DAT_10043d20,0,param_1);
  ExceptionList = local_14;
  return;
}



/* VA 1001fb29 */

void FUN_1001fb29(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 1001fb81 */

void FUN_1001fb81(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 1001fba8 */

/* Library Function - Single Match
    _malloc

   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;

  pvVar1 = __nh_malloc(_Size,DAT_10043944);
  return pvVar1;
}



/* VA 1001fbba */

/* Library Function - Single Match
    __nh_malloc

   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;

  if (_Size < 0xffffffe1) {
    do {
      pvVar1 = (void *)FUN_1001fbe6((uint *)_Size);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_100258a5(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}



/* VA 1001fbe6 */

void __cdecl FUN_1001fbe6(uint *param_1)

{
  int *piVar1;
  uint dwBytes;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_100350e8;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  if (DAT_10043d24 == 3) {
    ExceptionList = &local_14;
    if (param_1 <= DAT_10043d1c) {
      ExceptionList = &local_14;
      FUN_10022e54(9);
      local_8 = 0;
      piVar1 = FUN_10024a2d(param_1);
      local_8 = 0xffffffff;
      FUN_1001fc4d();
      if (piVar1 != (int *)0x0) {
        ExceptionList = local_14;
        return;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    if (DAT_10043d24 == 2) {
      if (param_1 == (uint *)0x0) {
        dwBytes = 0x10;
      }
      else {
        dwBytes = (int)param_1 + 0xfU & 0xfffffff0;
      }
      ExceptionList = &local_14;
      if (dwBytes <= DAT_1003fdcc) {
        ExceptionList = &local_14;
        FUN_10022e54(9);
        local_8 = 1;
        piVar1 = FUN_100254d0(dwBytes >> 4);
        local_8 = 0xffffffff;
        FUN_1001fcac();
        if (piVar1 != (int *)0x0) {
          ExceptionList = local_14;
          return;
        }
      }
      goto LAB_1001fcc5;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  dwBytes = (int)param_1 + 0xfU & 0xfffffff0;
LAB_1001fcc5:
  HeapAlloc(DAT_10043d20,0,dwBytes);
  ExceptionList = local_14;
  return;
}



/* VA 1001fc4d */

void FUN_1001fc4d(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 1001fcac */

void FUN_1001fcac(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 1001fce2 */

int __thiscall FUN_1001fce2(void *this,byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;

  while( true ) {
    if (DAT_1003ffdc < 2) {
      uVar1 = (byte)PTR_DAT_1003fdd0[(uint)*param_1 * 2] & 8;
      this = PTR_DAT_1003fdd0;
    }
    else {
      puVar6 = (undefined *)0x8;
      uVar1 = FUN_100258c0(this,(uint)*param_1,8);
      this = puVar6;
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar1 = (uint)*param_1;
  pbVar5 = param_1 + 1;
  if ((uVar1 == 0x2d) || (uVar4 = uVar1, uVar1 == 0x2b)) {
    uVar4 = (uint)*pbVar5;
    pbVar5 = param_1 + 2;
  }
  iVar3 = 0;
  while( true ) {
    if (DAT_1003ffdc < 2) {
      uVar2 = (byte)PTR_DAT_1003fdd0[uVar4 * 2] & 4;
    }
    else {
      puVar6 = (undefined *)0x4;
      uVar2 = FUN_100258c0(this,uVar4,4);
      this = puVar6;
    }
    if (uVar2 == 0) break;
    iVar3 = (uVar4 - 0x30) + iVar3 * 10;
    uVar4 = (uint)*pbVar5;
    pbVar5 = pbVar5 + 1;
  }
  if (uVar1 == 0x2d) {
    iVar3 = -iVar3;
  }
  return iVar3;
}



/* VA 1001fd6d */

void __thiscall FUN_1001fd6d(void *this,byte *param_1)

{
  FUN_1001fce2(this,param_1);
  return;
}



/* VA 1001fd78 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fd78(void)

{
  void *extraout_ECX;

  FUN_1001fd90();
  _DAT_10043834 = FUN_100259c4();
  FUN_10025974(extraout_ECX);
  return;
}



/* VA 1001fd90 */

void FUN_1001fd90(void)

{
  PTR___fptrap_1003fff4 = &LAB_10025a47;
  PTR___fptrap_1003fff0 = __cfltcvt;
  PTR___fptrap_1003fff8 = __fassign;
  PTR___fptrap_1003fffc = FUN_100259ed;
  PTR___fptrap_10040000 = &LAB_10025a95;
  PTR___fptrap_10040004 = __cfltcvt;
  return;
}



/* VA 1001fdc8 */

int __cdecl FUN_1001fdc8(int *param_1)

{
  int iVar1;

  if (param_1 == (int *)0x0) {
    iVar1 = FUN_1001fe8a(0);
    return iVar1;
  }
  FUN_10022f86((uint)param_1);
  iVar1 = FUN_1001fdf7(param_1);
  FUN_10022fd8((uint)param_1);
  return iVar1;
}



/* VA 1001fdf7 */

int __cdecl FUN_1001fdf7(int *param_1)

{
  int iVar1;

  iVar1 = FUN_1001fe25(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_10025e13(param_1[4]);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}



/* VA 1001fe25 */

undefined4 __cdecl FUN_1001fe25(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;

  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    if (0 < (int)uVar3) {
      uVar1 = FUN_10025ea6(param_1[4],(char *)param_1[2],uVar3);
      if (uVar1 == uVar3) {
        if ((param_1[3] & 0x80U) != 0) {
          param_1[3] = param_1[3] & 0xfffffffd;
        }
      }
      else {
        param_1[3] = param_1[3] | 0x20;
        uVar2 = 0xffffffff;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar2;
}



/* VA 1001fe8a */

int __cdecl FUN_1001fe8a(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;

  iVar3 = 0;
  iVar5 = 0;
  FUN_10022e54(2);
  iVar4 = 0;
  if (0 < DAT_10044d40) {
    do {
      iVar2 = *(int *)(DAT_10043d28 + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_10022fb5(iVar4,iVar2);
        piVar1 = *(int **)(DAT_10043d28 + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_1001fdf7(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_1001fdf7(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_10023007(iVar4,*(int *)(DAT_10043d28 + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_10044d40);
  }
  FUN_10022eb5(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}



/* VA 1001ff2e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001ff2e(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;

  if (param_2 == 1) {
    DAT_10043890 = GetVersion();
    iVar1 = FUN_1002458c(1);
    if (iVar1 != 0) {
      _DAT_1004389c = DAT_10043890 >> 8 & 0xff;
      _DAT_10043898 = DAT_10043890 & 0xff;
      DAT_10043890 = DAT_10043890 >> 0x10;
      _DAT_10043894 = _DAT_10043898 * 0x100 + _DAT_1004389c;
      iVar1 = FUN_10022b7c();
      if (iVar1 != 0) {
        DAT_10044f88 = GetCommandLineA();
        DAT_1004383c = FUN_100265ac();
        FUN_10026096();
        FUN_1002635f();
        FUN_100262a6();
        FUN_1002220c();
        DAT_10043838 = DAT_10043838 + 1;
        goto LAB_10020001;
      }
      FUN_100245e9();
    }
LAB_1001ff8e:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_10043838 < 1) goto LAB_1001ff8e;
      DAT_10043838 = DAT_10043838 + -1;
      if (DAT_100438c8 == 0) {
        FUN_1002224a();
      }
      FUN_10026252();
      FUN_10022bd0();
      FUN_100245e9();
    }
    else if (param_2 == 3) {
      FUN_10022c68((undefined *)0x0);
    }
LAB_10020001:
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 10020007 */

int entry(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = param_2;
  iVar2 = DAT_10043838;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_1002004f;
    if ((DAT_10044f8c != (code *)0x0) &&
       (iVar2 = (*DAT_10044f8c)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_1001ff2e(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_1002004f:
  iVar2 = FUN_1001e3ac(param_1,param_2);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_1001ff2e(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_1001ff2e(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_10044f8c != (code *)0x0) {
      iVar2 = (*DAT_10044f8c)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}



/* VA 100200a4 */

/* Library Function - Single Match
    __amsg_exit

   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_10043844 == 1) || ((DAT_10043844 == 0 && (DAT_10043848 == 1)))) {
    FUN_100266de();
  }
  FUN_10026717(param_1);
  (*(code *)PTR___exit_1003d704)(0xff);
  return;
}



/* VA 100200e0 */

undefined4 * __cdecl FUN_100200e0(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_10020297_caseD_2;
        case 3:
          goto switchD_10020297_caseD_3;
        }
        goto switchD_10020297_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_10020297_caseD_0;
      case 1:
        goto switchD_10020297_caseD_1;
      case 2:
        goto switchD_10020297_caseD_2;
      case 3:
        goto switchD_10020297_caseD_3;
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
              goto switchD_10020297_caseD_2;
            case 3:
              goto switchD_10020297_caseD_3;
            }
            goto switchD_10020297_caseD_1;
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
              goto switchD_10020297_caseD_2;
            case 3:
              goto switchD_10020297_caseD_3;
            }
            goto switchD_10020297_caseD_1;
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
              goto switchD_10020297_caseD_2;
            case 3:
              goto switchD_10020297_caseD_3;
            }
            goto switchD_10020297_caseD_1;
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
switchD_10020297_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_10020297_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_10020297_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_10020297_caseD_0:
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
        goto switchD_10020115_caseD_2;
      case 3:
        goto switchD_10020115_caseD_3;
      }
      goto switchD_10020115_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_10020115_caseD_0;
    case 1:
      goto switchD_10020115_caseD_1;
    case 2:
      goto switchD_10020115_caseD_2;
    case 3:
      goto switchD_10020115_caseD_3;
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
            goto switchD_10020115_caseD_2;
          case 3:
            goto switchD_10020115_caseD_3;
          }
          goto switchD_10020115_caseD_1;
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
            goto switchD_10020115_caseD_2;
          case 3:
            goto switchD_10020115_caseD_3;
          }
          goto switchD_10020115_caseD_1;
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
            goto switchD_10020115_caseD_2;
          case 3:
            goto switchD_10020115_caseD_3;
          }
          goto switchD_10020115_caseD_1;
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
switchD_10020115_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_10020115_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_10020115_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_10020115_caseD_0:
  return param_1;
}



/* VA 10020415 */

int __cdecl FUN_10020415(short *param_1)

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



/* VA 10020434 */

void FUN_10020434(void)

{
  undefined1 auStack_c [12];

  ExceptionList = auStack_c;
  return;
}



/* VA 10020453 */

byte * __cdecl FUN_10020453(byte *param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;

  if (DAT_10044d6c == 0) {
    pbVar2 = (byte *)_strchr((char *)param_1,param_2);
  }
  else {
    FUN_10022e54(0x19);
    while( true ) {
      bVar1 = *param_1;
      uVar3 = (uint)bVar1;
      if (bVar1 == 0) break;
      if ((*(byte *)((int)&DAT_10044e80 + uVar3 + 1) & 4) == 0) {
        pbVar2 = param_1;
        if (param_2 == uVar3) break;
      }
      else {
        pbVar2 = param_1 + 1;
        if (param_1[1] == 0) {
          FUN_10022eb5(0x19);
          return (byte *)0x0;
        }
        if (param_2 == CONCAT11(bVar1,param_1[1])) {
          FUN_10022eb5(0x19);
          return param_1;
        }
      }
      param_1 = pbVar2 + 1;
    }
    FUN_10022eb5(0x19);
    pbVar2 = (byte *)(~-(uint)(param_2 != uVar3) & (uint)param_1);
  }
  return pbVar2;
}



/* VA 100204ea */

byte * __cdecl FUN_100204ea(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;

  FUN_10022e54(0x19);
  pbVar2 = param_1;
  bVar4 = *param_1;
  pbVar5 = param_1;
  do {
    if (bVar4 == 0) {
      FUN_10022eb5(0x19);
      return pbVar2;
    }
    bVar4 = *pbVar5;
    bVar1 = *(byte *)((int)&DAT_10044e80 + bVar4 + 1);
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 0x10) == 0x10) {
        bVar4 = (&DAT_10044d80)[bVar4];
      }
      *pbVar5 = bVar4;
    }
    else {
      iVar3 = FUN_100238eb(DAT_10044f84,0x100,(char *)pbVar5,2,(LPWSTR)&param_1,2,DAT_10044d54,1);
      if (iVar3 == 0) {
        FUN_10022eb5(0x19);
        return (byte *)0x0;
      }
      *pbVar5 = (byte)param_1;
      if (1 < iVar3) {
        pbVar5 = pbVar5 + 1;
        *pbVar5 = (byte)((uint)param_1 >> 8);
      }
    }
    pbVar5 = pbVar5 + 1;
    bVar4 = *pbVar5;
  } while( true );
}



/* VA 10020574 */

byte * __cdecl FUN_10020574(byte *param_1)

{
  byte *pbVar1;

  pbVar1 = param_1 + 1;
  if ((*(byte *)((int)&DAT_10044e80 + *param_1 + 1) & 4) != 0) {
    pbVar1 = param_1 + 2;
  }
  return pbVar1;
}



/* VA 10020590 */

undefined4 * __cdecl FUN_10020590(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_10020747_caseD_2;
        case 3:
          goto switchD_10020747_caseD_3;
        }
        goto switchD_10020747_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_10020747_caseD_0;
      case 1:
        goto switchD_10020747_caseD_1;
      case 2:
        goto switchD_10020747_caseD_2;
      case 3:
        goto switchD_10020747_caseD_3;
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
              goto switchD_10020747_caseD_2;
            case 3:
              goto switchD_10020747_caseD_3;
            }
            goto switchD_10020747_caseD_1;
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
              goto switchD_10020747_caseD_2;
            case 3:
              goto switchD_10020747_caseD_3;
            }
            goto switchD_10020747_caseD_1;
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
              goto switchD_10020747_caseD_2;
            case 3:
              goto switchD_10020747_caseD_3;
            }
            goto switchD_10020747_caseD_1;
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
switchD_10020747_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_10020747_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_10020747_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_10020747_caseD_0:
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
        goto switchD_100205c5_caseD_2;
      case 3:
        goto switchD_100205c5_caseD_3;
      }
      goto switchD_100205c5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_100205c5_caseD_0;
    case 1:
      goto switchD_100205c5_caseD_1;
    case 2:
      goto switchD_100205c5_caseD_2;
    case 3:
      goto switchD_100205c5_caseD_3;
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
            goto switchD_100205c5_caseD_2;
          case 3:
            goto switchD_100205c5_caseD_3;
          }
          goto switchD_100205c5_caseD_1;
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
            goto switchD_100205c5_caseD_2;
          case 3:
            goto switchD_100205c5_caseD_3;
          }
          goto switchD_100205c5_caseD_1;
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
            goto switchD_100205c5_caseD_2;
          case 3:
            goto switchD_100205c5_caseD_3;
          }
          goto switchD_100205c5_caseD_1;
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
switchD_100205c5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_100205c5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_100205c5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_100205c5_caseD_0:
  return param_1;
}



/* VA 100208c5 */

byte * __cdecl FUN_100208c5(byte *param_1,char *param_2)

{
  byte *pbVar1;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;

  if (DAT_10044d6c == 0) {
    pbVar1 = (byte *)_strstr((char *)param_1,param_2);
  }
  else {
    sVar2 = _strlen(param_2);
    sVar3 = _strlen((char *)param_1);
    pbVar1 = param_1 + (sVar3 - sVar2);
    for (; (*param_1 != 0 && (param_1 <= pbVar1)); param_1 = FUN_10020574(param_1)) {
      pcVar4 = param_2;
      if (*param_1 != 0) {
        do {
          if ((*pcVar4 == '\0') || (pcVar4[(int)param_1 - (int)param_2] != *pcVar4)) break;
          pcVar4 = pcVar4 + 1;
        } while (pcVar4[(int)param_1 - (int)param_2] != '\0');
      }
      if (*pcVar4 == '\0') {
        return param_1;
      }
    }
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}



/* VA 1002093b */

byte * __cdecl FUN_1002093b(byte *param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  bool bVar6;

  pbVar5 = (byte *)0x0;
  if (DAT_10044d6c == 0) {
    pbVar5 = (byte *)_strrchr((char *)param_1,param_2);
  }
  else {
    FUN_10022e54(0x19);
    do {
      bVar4 = *param_1;
      if ((*(byte *)((int)&DAT_10044e80 + bVar4 + 1) & 4) == 0) {
        bVar6 = param_2 == bVar4;
LAB_10020996:
        pbVar3 = param_1;
        if (bVar6) {
          pbVar5 = param_1;
        }
      }
      else {
        bVar1 = param_1[1];
        pbVar3 = param_1 + 1;
        if (bVar1 == 0) {
          bVar6 = pbVar5 == (byte *)0x0;
          param_1 = pbVar3;
          bVar4 = bVar1;
          goto LAB_10020996;
        }
        uVar2 = CONCAT11(bVar4,bVar1);
        bVar4 = bVar1;
        if (param_2 == uVar2) {
          pbVar5 = param_1;
        }
      }
      param_1 = pbVar3 + 1;
    } while (bVar4 != 0);
    FUN_10022eb5(0x19);
  }
  return pbVar5;
}



/* VA 100209ad */

int __cdecl FUN_100209ad(undefined1 *param_1,byte *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;

  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_100230e1((int *)&local_24,param_2,param_3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_100242ff(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}



/* VA 100209fe */

char __cdecl FUN_100209fe(byte *param_1)

{
  return ((*(byte *)((int)&DAT_10044e80 + *param_1 + 1) & 4) != 0) + '\x01';
}



/* VA 10020a14 */

int __cdecl FUN_10020a14(byte *param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;

  if (param_3 == 0) {
    return 0;
  }
  if (DAT_10044d6c == 0) {
    iVar3 = _strncmp((char *)param_1,(char *)param_2,param_3);
    return iVar3;
  }
  FUN_10022e54(0x19);
  pbVar5 = param_2;
  sVar2 = param_3;
  do {
    param_3 = sVar2 - 1;
    param_2._0_2_ = (ushort)*param_1;
    pbVar7 = param_1 + 1;
    if ((*(byte *)((int)&DAT_10044e80 + (ushort)param_2 + 1) & 4) == 0) {
LAB_10020a95:
      bVar1 = *pbVar5;
      uVar4 = (uint)(ushort)bVar1;
      pbVar6 = pbVar5 + 1;
      if ((*(byte *)((int)&DAT_10044e80 + (ushort)bVar1 + 1) & 4) != 0) {
        if (param_3 != 0) {
          param_3 = sVar2 - 2;
          if (*pbVar6 != 0) {
            uVar4 = (uint)CONCAT11(bVar1,*pbVar6);
            pbVar6 = pbVar5 + 2;
            goto LAB_10020ac2;
          }
        }
        uVar4 = 0;
      }
    }
    else {
      if (param_3 != 0) {
        bVar1 = *pbVar7;
        if (bVar1 == 0) {
          param_2._0_2_ = 0;
        }
        else {
          pbVar7 = param_1 + 2;
          param_2._0_2_ = CONCAT11(*param_1,bVar1);
        }
        goto LAB_10020a95;
      }
      uVar4 = (uint)*pbVar5;
      param_2._0_2_ = 0;
      pbVar6 = pbVar5;
      if ((*(byte *)((int)&DAT_10044e80 + uVar4 + 1) & 4) != 0) {
LAB_10020af4:
        FUN_10022eb5(0x19);
        return 0;
      }
    }
LAB_10020ac2:
    if ((ushort)param_2 != (ushort)uVar4) {
      FUN_10022eb5(0x19);
      return (-(uint)((ushort)uVar4 < (ushort)param_2) & 2) - 1;
    }
    if (((ushort)param_2 == 0) || (pbVar5 = pbVar6, param_1 = pbVar7, sVar2 = param_3, param_3 == 0)
       ) goto LAB_10020af4;
  } while( true );
}



/* VA 10020b03 */

uint __cdecl FUN_10020b03(void *param_1)

{
  BOOL BVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined4 local_8;

  if (param_1 < (void *)0x100) {
    if (1 < DAT_1003ffdc) {
      uVar2 = FUN_100258c0(param_1,(int)param_1,4);
      return uVar2;
    }
    return (byte)PTR_DAT_1003fdd0[(int)param_1 * 2] & 4;
  }
  local_8 = 0;
  uVar3 = SUB41(param_1,0);
  uVar2 = (uint)param_1 >> 8;
  param_1 = (void *)CONCAT13(uVar3,CONCAT12((char)uVar2,param_1._0_2_));
  if (DAT_10044d6c != 0) {
    BVar1 = FUN_10026b18(1,(LPCSTR)((int)&param_1 + 2),2,(LPWORD)&local_8,DAT_10044d54,DAT_10044f84,
                         1);
    if (((BVar1 != 0) && (local_8._2_2_ == 0)) && ((local_8 & 4) != 0)) {
      return 1;
    }
  }
  return 0;
}



/* VA 10020b92 */

void __fastcall FUN_10020b92(undefined4 *param_1)

{
  *param_1 = &type_info::vftable;
  FUN_10022e54(0x1b);
  if ((undefined *)param_1[1] != (undefined *)0x0) {
    FUN_1001fabf((undefined *)param_1[1]);
  }
  FUN_10022eb5(0x1b);
  return;
}



/* VA 10020bbb */

undefined4 * __thiscall FUN_10020bbb(void *this,byte param_1)

{
  FUN_10020b92(this);
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 10020bd7 */

uint FUN_10020bd7(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int local_8;
  int local_4;

  uVar4 = 0xffffffff;
  FUN_10022e54(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_10043c00;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          FUN_10022e54(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          FUN_10022eb5(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          uVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (uVar4 != 0xffffffff) goto LAB_10020ce9;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0x10043cff < (int)piVar3) goto LAB_10020ce9;
  }
  puVar2 = _malloc(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_10043d00 = DAT_10043d00 + 0x20;
    (&DAT_10043c00)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_10043c00)[local_8];
    }
    uVar4 = local_8 << 5;
    FUN_10020ede(uVar4);
  }
LAB_10020ce9:
  FUN_10022eb5(0x12);
  return uVar4;
}



/* VA 10020cfa */

undefined4 __cdecl FUN_10020cfa(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;
  DWORD nStdHandle;

  if (param_1 < DAT_10043d00) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_10043c00)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_10043848 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_10020d53;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_10020d53:
      *(HANDLE *)((&DAT_10043c00)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_10020fd2();
  *pDVar1 = 9;
  pDVar1 = FUN_10020fdb();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* VA 10020d76 */

undefined4 __cdecl FUN_10020d76(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;

  if (param_1 < DAT_10043d00) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_10043c00)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_10043848 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_10020dd2;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_10020dd2:
      *(undefined4 *)((&DAT_10043c00)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_10020fd2();
  *pDVar2 = 9;
  pDVar2 = FUN_10020fdb();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 10020df5 */

undefined4 __cdecl FUN_10020df5(uint param_1)

{
  DWORD *pDVar1;

  if ((param_1 < DAT_10043d00) &&
     ((*(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_10043c00)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_10020fd2();
  *pDVar1 = 9;
  pDVar1 = FUN_10020fdb();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* VA 10020e37 */

uint __cdecl FUN_10020e37(HANDLE param_1,uint param_2)

{
  DWORD DVar1;
  uint uVar2;
  DWORD *pDVar3;
  byte bVar4;

  bVar4 = 0;
  if ((param_2 & 8) != 0) {
    bVar4 = 0x20;
  }
  if ((param_2 & 0x4000) != 0) {
    bVar4 = bVar4 | 0x80;
  }
  if ((param_2 & 0x80) != 0) {
    bVar4 = bVar4 | 0x10;
  }
  DVar1 = GetFileType(param_1);
  if (DVar1 == 0) {
    DVar1 = GetLastError();
    FUN_10020f5f(DVar1);
  }
  else {
    if (DVar1 == 2) {
      bVar4 = bVar4 | 0x40;
    }
    else if (DVar1 == 3) {
      bVar4 = bVar4 | 8;
    }
    uVar2 = FUN_10020bd7();
    if (uVar2 != 0xffffffff) {
      FUN_10020cfa(uVar2,param_1);
      *(byte *)((&DAT_10043c00)[(int)uVar2 >> 5] + 4 + (uVar2 & 0x1f) * 0x24) = bVar4 | 1;
      FUN_10020f3d(uVar2);
      return uVar2;
    }
    pDVar3 = FUN_10020fd2();
    *pDVar3 = 0x18;
    pDVar3 = FUN_10020fdb();
    *pDVar3 = 0;
  }
  return 0xffffffff;
}



/* VA 10020ede */

void __cdecl FUN_10020ede(uint param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_10043c00)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_10022e54(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_10022eb5(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_10043c00)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}



/* VA 10020f3d */

void __cdecl FUN_10020f3d(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_10043c00)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



/* VA 10020f5f */

void __cdecl FUN_10020f5f(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;

  pDVar1 = FUN_10020fdb();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_1003d728;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_10020fd2();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x1003d72c);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x1003d890);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_10020fd2();
    *pDVar1 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    pDVar1 = FUN_10020fd2();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_10020fd2();
  *pDVar1 = 0x16;
  return;
}



/* VA 10020fd2 */

DWORD * FUN_10020fd2(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_10022c01();
  return pDVar1 + 2;
}



/* VA 10020fdb */

DWORD * FUN_10020fdb(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_10022c01();
  return pDVar1 + 3;
}



/* VA 10020fe4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_10020fe4(uint param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined4 *puVar7;

  if (((DAT_10043d00 <= param_1) ||
      (bVar3 = true,
      (*(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) == 0)) ||
     (puVar7 = FUN_10023d50(), puVar7 == (undefined4 *)0x0)) {
    return (undefined4 *)0x0;
  }
  cVar1 = *param_2;
  if (cVar1 != 'a') {
    if (cVar1 == 'r') {
      puVar7[3] = 1;
      goto LAB_1002104a;
    }
    if (cVar1 != 'w') {
      puVar7 = (undefined4 *)0x0;
      goto LAB_100210c6;
    }
  }
  puVar7[3] = 2;
LAB_1002104a:
  puVar7[3] = puVar7[3] | DAT_10043a5c;
  bVar2 = bVar3;
  bVar4 = false;
  bVar6 = false;
LAB_1002105a:
  bVar5 = bVar6;
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) goto LAB_100210b9;
  bVar6 = bVar5;
  if (cVar1 == '+') {
    if ((puVar7[3] & 0x80) == 0) {
      puVar7[3] = puVar7[3] & 0xfffffffc | 0x80;
      goto LAB_1002105a;
    }
  }
  else {
    if (cVar1 == 'b') {
LAB_1002109a:
      bVar6 = bVar3;
      if (bVar5) goto LAB_100210ac;
      goto LAB_1002105a;
    }
    if (cVar1 == 'c') {
      if (bVar4) goto LAB_100210ac;
      *(byte *)((int)puVar7 + 0xd) = *(byte *)((int)puVar7 + 0xd) | 0x40;
      bVar4 = bVar3;
      goto LAB_1002105a;
    }
    if (cVar1 == 'n') {
      if (bVar4) goto LAB_100210ac;
      *(byte *)((int)puVar7 + 0xd) = *(byte *)((int)puVar7 + 0xd) & 0xbf;
      bVar4 = bVar3;
      goto LAB_1002105a;
    }
    if (cVar1 == 't') goto LAB_1002109a;
  }
LAB_100210ac:
  bVar2 = false;
  bVar6 = bVar5;
  goto LAB_1002105a;
LAB_100210b9:
  _DAT_10043930 = _DAT_10043930 + 1;
  puVar7[4] = param_1;
LAB_100210c6:
  FUN_10022fd8((uint)puVar7);
  return puVar7;
}



/* VA 100210d7 */

void __cdecl FUN_100210d7(uint param_1)

{
  uint uVar1;
  undefined *puVar2;

  FUN_10022f86(param_1);
  uVar1 = *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffcf;
  if (uVar1 == 0xffffffff) {
    puVar2 = &DAT_10040008;
  }
  else {
    puVar2 = (undefined *)((&DAT_10043c00)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 0x24);
  }
  puVar2[4] = puVar2[4] & 0xfd;
  FUN_10022fd8(param_1);
  return;
}



/* VA 10021118 */

uint __cdecl FUN_10021118(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;

  FUN_10022f86((uint)param_4);
  uVar1 = FUN_10021147(param_1,param_2,param_3,param_4);
  FUN_10022fd8((uint)param_4);
  return uVar1;
}



/* VA 10021147 */

uint __cdecl FUN_10021147(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;

  piVar1 = param_4;
  pcVar6 = (char *)(param_2 * param_3);
  if (pcVar6 == (char *)0x0) {
    param_3 = 0;
  }
  else {
    pcVar5 = param_1;
    param_1 = pcVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((*(ushort *)(piVar1 + 3) & 0x10c) == 0) ||
         (pcVar2 = (char *)piVar1[1], pcVar2 == (char *)0x0)) {
        if (param_1 < param_4) {
          uVar4 = FUN_10026c61(piVar1);
          if (uVar4 == 0xffffffff) goto LAB_10021223;
          *pcVar5 = (char)uVar4;
          param_4 = (int *)piVar1[6];
          pcVar5 = pcVar5 + 1;
          param_1 = param_1 + -1;
        }
        else {
          pcVar2 = param_1;
          if (param_4 != (int *)0x0) {
            pcVar2 = param_1 + -((uint)param_1 % (uint)param_4);
          }
          iVar3 = FUN_10026d3d(piVar1[4],pcVar5,pcVar2);
          if (iVar3 == 0) {
            piVar1[3] = piVar1[3] | 0x10;
LAB_10021223:
            return (uint)((int)pcVar6 - (int)param_1) / param_2;
          }
          if (iVar3 == -1) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_10021223;
          }
          param_1 = param_1 + -iVar3;
          pcVar5 = pcVar5 + iVar3;
        }
      }
      else {
        pcVar7 = param_1;
        if (pcVar2 <= param_1) {
          pcVar7 = pcVar2;
        }
        FUN_100200e0((undefined4 *)pcVar5,(undefined4 *)*piVar1,(uint)pcVar7);
        param_1 = param_1 + -(int)pcVar7;
        piVar1[1] = piVar1[1] - (int)pcVar7;
        *piVar1 = (int)(pcVar7 + *piVar1);
        pcVar5 = pcVar5 + (int)pcVar7;
      }
    } while (param_1 != (char *)0x0);
  }
  return param_3;
}



/* VA 1002122f */

uint __cdecl FUN_1002122f(char *param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;

  FUN_10022f86((uint)param_4);
  uVar1 = FUN_1002125e(param_1,param_2,param_3,param_4);
  FUN_10022fd8((uint)param_4);
  return uVar1;
}



/* VA 1002125e */

uint __cdecl FUN_1002125e(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;

  piVar1 = param_4;
  piVar6 = (int *)(param_2 * param_3);
  if (piVar6 == (int *)0x0) {
    param_3 = 0;
  }
  else {
    piVar5 = piVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((piVar1[3] & 0x108U) == 0) || (piVar7 = (int *)piVar1[1], piVar7 == (int *)0x0)) {
        if (param_4 <= piVar5) {
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_1001fe25(piVar1), iVar2 != 0)) {
LAB_1002135f:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          piVar7 = piVar5;
          if (param_4 != (int *)0x0) {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_10025ea6(piVar1[4],param_1,(uint)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_1002135f;
          }
          goto LAB_10021316;
        }
        uVar4 = FUN_100242ff((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_1002135f;
        param_1 = param_1 + 1;
        param_4 = (int *)piVar1[6];
        piVar5 = (int *)((int)piVar5 - 1);
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        piVar3 = piVar5;
        if (piVar7 <= piVar5) {
          piVar3 = piVar7;
        }
        FUN_100200e0((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_10021316:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}



/* VA 10021368 */

int __cdecl FUN_10021368(char *param_1,int *param_2)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;

  sVar1 = _strlen(param_1);
  FUN_10022f86((uint)param_2);
  iVar2 = FUN_1002302a(param_2);
  uVar3 = FUN_1002125e(param_1,1,sVar1,param_2);
  FUN_100230b7(iVar2,param_2);
  FUN_10022fd8((uint)param_2);
  return (uVar3 == sVar1) - 1;
}



/* VA 100213b6 */

char * __cdecl FUN_100213b6(char *param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  uint uVar2;
  char *pcVar3;

  if (param_2 < 1) {
    param_1 = (char *)0x0;
  }
  else {
    FUN_10022f86((uint)param_3);
    pcVar3 = param_1;
    do {
      param_2 = param_2 + -1;
      if (param_2 == 0) break;
      piVar1 = param_3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 0) {
        uVar2 = FUN_10026c61(param_3);
      }
      else {
        uVar2 = (uint)*(byte *)*param_3;
        *param_3 = (byte *)*param_3 + 1;
      }
      if (uVar2 == 0xffffffff) {
        if (pcVar3 == param_1) {
          param_1 = (char *)0x0;
          goto LAB_1002140a;
        }
        break;
      }
      *pcVar3 = (char)uVar2;
      pcVar3 = pcVar3 + 1;
    } while ((char)uVar2 != '\n');
    *pcVar3 = '\0';
LAB_1002140a:
    FUN_10022fd8((uint)param_3);
  }
  return param_1;
}



/* VA 10021418 */

int __cdecl FUN_10021418(char *param_1)

{
  int iVar1;

  FUN_10022f86((uint)param_1);
  iVar1 = FUN_1002143a(param_1);
  FUN_10022fd8((uint)param_1);
  return iVar1;
}



/* VA 1002143a */

int __cdecl FUN_1002143a(char *param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  DWORD *pDVar4;
  char *pcVar5;
  DWORD DVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int local_c;
  DWORD local_8;

  pcVar8 = param_1;
  uVar1 = *(uint *)(param_1 + 0x10);
  if (*(int *)(param_1 + 4) < 0) {
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  local_8 = FUN_10026f7b(uVar1,0,1);
  if ((int)local_8 < 0) {
LAB_100214c8:
    local_c = -1;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xc);
    if ((uVar2 & 0x108) == 0) {
      return local_8 - *(int *)(param_1 + 4);
    }
    pcVar5 = *(char **)param_1;
    pcVar7 = *(char **)(param_1 + 8);
    local_c = (int)pcVar5 - (int)pcVar7;
    if ((uVar2 & 3) == 0) {
      if ((uVar2 & 0x80) == 0) {
        pDVar4 = FUN_10020fd2();
        *pDVar4 = 0x16;
        goto LAB_100214c8;
      }
    }
    else {
      pcVar9 = pcVar7;
      if ((*(byte *)((&DAT_10043c00)[(int)uVar1 >> 5] + 4 + (uVar1 & 0x1f) * 0x24) & 0x80) != 0) {
        for (; pcVar9 < pcVar5; pcVar9 = pcVar9 + 1) {
          if (*pcVar9 == '\n') {
            local_c = local_c + 1;
          }
        }
      }
    }
    if (local_8 != 0) {
      if ((param_1[0xc] & 1U) != 0) {
        if (*(int *)(param_1 + 4) == 0) {
          local_c = 0;
        }
        else {
          pcVar5 = pcVar5 + (*(int *)(param_1 + 4) - (int)pcVar7);
          iVar10 = (uVar1 & 0x1f) * 0x24;
          if ((*(byte *)(iVar10 + 4 + (&DAT_10043c00)[(int)uVar1 >> 5]) & 0x80) != 0) {
            DVar6 = FUN_10026f7b(uVar1,0,2);
            if (DVar6 == local_8) {
              pcVar7 = *(char **)(param_1 + 8);
              pcVar9 = pcVar5 + (int)pcVar7;
              param_1 = pcVar5;
              for (; pcVar7 < pcVar9; pcVar7 = pcVar7 + 1) {
                if (*pcVar7 == '\n') {
                  param_1 = param_1 + 1;
                }
              }
              bVar3 = pcVar8[0xd] & 0x20;
            }
            else {
              FUN_10026f7b(uVar1,local_8,0);
              pcVar8 = (char *)0x200;
              if ((((char *)0x200 < pcVar5) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)(param_1 + 0xc) & 0x400) != 0)) {
                pcVar8 = *(char **)(param_1 + 0x18);
              }
              bVar3 = *(byte *)(iVar10 + 4 + (&DAT_10043c00)[(int)uVar1 >> 5]) & 4;
              param_1 = pcVar8;
            }
            pcVar5 = param_1;
            if (bVar3 != 0) {
              pcVar5 = param_1 + 1;
            }
          }
          param_1 = pcVar5;
          local_8 = local_8 - (int)param_1;
        }
      }
      local_c = local_c + local_8;
    }
  }
  return local_c;
}



/* VA 1002159b */

int __cdecl FUN_1002159b(int *param_1,int param_2,DWORD param_3)

{
  int iVar1;

  FUN_10022f86((uint)param_1);
  iVar1 = FUN_100215c7(param_1,param_2,param_3);
  FUN_10022fd8((uint)param_1);
  return iVar1;
}



/* VA 100215c7 */

int __cdecl FUN_100215c7(int *param_1,int param_2,DWORD param_3)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  DWORD *pDVar4;

  if (((param_1[3] & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    pDVar4 = FUN_10020fd2();
    *pDVar4 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = FUN_1002143a((char *)param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    FUN_1001fe25(param_1);
    uVar1 = param_1[3];
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      param_1[3] = uVar1 & 0xfffffffc;
    }
    DVar3 = FUN_10026f7b(param_1[4],param_2,param_3);
    iVar2 = (DVar3 != 0xffffffff) - 1;
  }
  return iVar2;
}



/* VA 10021654 */

/* Library Function - Single Match
    __CxxThrowException@8

   Library: Visual Studio 2003 Release */

void __CxxThrowException_8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD *pDVar2;
  DWORD *pDVar3;
  DWORD local_24 [4];
  DWORD local_14;
  ULONG_PTR local_10;
  undefined4 local_c;
  undefined4 local_8;

  pDVar2 = &DAT_10035108;
  pDVar3 = local_24;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pDVar3 = *pDVar2;
    pDVar2 = pDVar2 + 1;
    pDVar3 = pDVar3 + 1;
  }
  local_c = param_1;
  local_8 = param_2;
  RaiseException(local_24[0],local_24[1],local_14,&local_10);
  return;
}



/* VA 1002168e */

SIZE_T __cdecl FUN_1002168e(undefined *param_1)

{
  byte *pbVar1;
  SIZE_T SVar2;
  undefined4 local_30;
  byte *local_2c;
  uint local_28;
  SIZE_T local_24;
  byte *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_10035128;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  if (DAT_10043d24 == 3) {
    ExceptionList = &local_14;
    FUN_10022e54(9);
    local_8 = 0;
    local_20 = (byte *)FUN_100246d9((int)param_1);
    if (local_20 != (byte *)0x0) {
      local_24 = *(int *)(param_1 + -4) - 9;
    }
    SVar2 = local_24;
    local_8 = 0xffffffff;
    FUN_100216f8();
    pbVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (DAT_10043d24 != 2) goto LAB_1002174c;
    ExceptionList = &local_14;
    FUN_10022e54(9);
    local_8 = 1;
    local_2c = (byte *)FUN_10025434(param_1,&local_30,&local_28);
    if (local_2c != (byte *)0x0) {
      local_24 = (uint)*local_2c << 4;
    }
    SVar2 = local_24;
    local_8 = 0xffffffff;
    FUN_10021773();
    pbVar1 = local_2c;
  }
  if (pbVar1 != (byte *)0x0) {
    ExceptionList = local_14;
    return SVar2;
  }
LAB_1002174c:
  SVar2 = HeapSize(DAT_10043d20,0,param_1);
  ExceptionList = local_14;
  return SVar2;
}



/* VA 100216f8 */

void FUN_100216f8(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 10021773 */

void FUN_10021773(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 1002177c */

uint * __cdecl FUN_1002177c(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;

  if (param_1 != (uint *)0x0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = _malloc(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      puVar2 = FUN_1001f150(puVar2,param_1);
      return puVar2;
    }
  }
  return (uint *)0x0;
}



/* VA 100217a7 */

undefined4 __cdecl FUN_100217a7(UINT param_1)

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
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;

  FUN_10022e54(0x19);
  CodePage = FUN_10021954(param_1);
  if (CodePage != DAT_10044d54) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_1003d8a0;
LAB_100217e4:
      if (*pUVar5 != CodePage) goto code_r0x100217e8;
      local_8 = 0;
      puVar15 = &DAT_10044e80;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x1003d8b0);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_1003d898)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_10044e80 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      DAT_10044d6c = 1;
      DAT_10044d54 = CodePage;
      DAT_10044f84 = FUN_1002199e(CodePage);
      DAT_10044d60 = *(undefined4 *)(iVar12 + 0x1003d8a4);
      DAT_10044d64 = *(undefined4 *)(iVar12 + 0x1003d8a8);
      DAT_10044d68 = *(undefined4 *)(iVar12 + 0x1003d8ac);
      goto LAB_10021938;
    }
    goto LAB_10021933;
  }
  goto LAB_100217ce;
code_r0x100217e8:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x1003d98f < (int)pUVar5) goto code_r0x100217f3;
  goto LAB_100217e4;
code_r0x100217f3:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_10044f84 = 0;
    puVar15 = &DAT_10044e80;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_10044d6c = 0;
      DAT_10044d54 = CodePage;
    }
    else {
      DAT_10044d54 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_10044e80 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_10044e80 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_10044f84 = FUN_1002199e(CodePage);
      DAT_10044d6c = 1;
    }
    DAT_10044d60 = 0;
    DAT_10044d64 = 0;
    DAT_10044d68 = 0;
  }
  else {
    if (DAT_1004384c == 0) {
      uVar14 = 0xffffffff;
      goto LAB_10021945;
    }
LAB_10021933:
    FUN_100219d1();
  }
LAB_10021938:
  FUN_100219fa();
LAB_100217ce:
  uVar14 = 0;
LAB_10021945:
  FUN_10022eb5(0x19);
  return uVar14;
}



/* VA 10021954 */

UINT __cdecl FUN_10021954(UINT param_1)

{
  UINT UVar1;
  bool bVar2;

  if (param_1 == 0xfffffffe) {
    DAT_1004384c = 1;
                    /* WARNING: Could not recover jumptable at 0x1002196e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    UVar1 = GetOEMCP();
    return UVar1;
  }
  if (param_1 == 0xfffffffd) {
    DAT_1004384c = 1;
                    /* WARNING: Could not recover jumptable at 0x10021983. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    UVar1 = GetACP();
    return UVar1;
  }
  bVar2 = param_1 == 0xfffffffc;
  if (bVar2) {
    param_1 = DAT_10043a7c;
  }
  DAT_1004384c = (uint)bVar2;
  return param_1;
}



/* VA 1002199e */

undefined4 __cdecl FUN_1002199e(int param_1)

{
  if (param_1 == 0x3a4) {
    return 0x411;
  }
  if (param_1 == 0x3a8) {
    return 0x804;
  }
  if (param_1 == 0x3b5) {
    return 0x412;
  }
  if (param_1 != 0x3b6) {
    return 0;
  }
  return 0x404;
}



/* VA 100219d1 */

void FUN_100219d1(void)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = &DAT_10044e80;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_10044d54 = 0;
  DAT_10044d6c = 0;
  DAT_10044f84 = 0;
  DAT_10044d60 = 0;
  DAT_10044d64 = 0;
  DAT_10044d68 = 0;
  return;
}



/* VA 100219fa */

void FUN_100219fa(void)

{
  byte *pbVar1;
  BOOL BVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 uVar8;
  BYTE *pBVar9;
  CHAR *pCVar10;
  WORD local_518 [256];
  WCHAR local_318 [128];
  WCHAR local_218 [128];
  CHAR local_118 [256];
  _cpinfo local_18;

  BVar2 = GetCPInfo(DAT_10044d54,&local_18);
  if (BVar2 == 1) {
    uVar3 = 0;
    do {
      local_118[uVar3] = (CHAR)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    local_118[0] = ' ';
    if (local_18.LeadByte[0] != 0) {
      pBVar9 = local_18.LeadByte + 1;
      do {
        uVar3 = (uint)local_18.LeadByte[0];
        if (uVar3 <= *pBVar9) {
          uVar5 = (*pBVar9 - uVar3) + 1;
          uVar6 = uVar5 >> 2;
          pCVar10 = local_118 + uVar3;
          while (uVar6 != 0) {
            uVar6 = uVar6 - 1;
            builtin_memcpy(pCVar10,"    ",4);
            pCVar10 = pCVar10 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pCVar10 = ' ';
            pCVar10 = pCVar10 + 1;
          }
        }
        local_18.LeadByte[0] = pBVar9[1];
        pBVar9 = pBVar9 + 2;
      } while (local_18.LeadByte[0] != 0);
    }
    FUN_10026b18(1,local_118,0x100,local_518,DAT_10044d54,DAT_10044f84,0);
    FUN_100238eb(DAT_10044f84,0x100,local_118,0x100,local_218,0x100,DAT_10044d54,0);
    FUN_100238eb(DAT_10044f84,0x200,local_118,0x100,local_318,0x100,DAT_10044d54,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_10044e80 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_10021b06;
        }
        (&DAT_10044d80)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_10044e80 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_10021b06:
        (&DAT_10044d80)[uVar3] = uVar8;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    do {
      if ((uVar3 < 0x41) || (0x5a < uVar3)) {
        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
          pbVar1 = (byte *)((int)&DAT_10044e80 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_10021b50;
        }
        (&DAT_10044d80)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_10044e80 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_10021b50:
        (&DAT_10044d80)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}



/* VA 10021b7f */

void FUN_10021b7f(void)

{
  if (DAT_10044d48 == 0) {
    FUN_100217a7(0xfffffffd);
    DAT_10044d48 = 1;
  }
  return;
}



/* VA 10021ba0 */

/* Library Function - Single Match
    _memcmp

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  bool bVar9;

  if (_Size != 0) {
    if ((((uint)_Buf1 | (uint)_Buf2) & 3) == 0) {
      uVar2 = _Size & 3;
      uVar5 = _Size >> 2;
      bVar9 = false;
      puVar7 = _Buf1;
      puVar8 = _Buf2;
      if (uVar5 != 0) {
        do {
          _Buf1 = puVar7;
          _Buf2 = puVar8;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          _Buf2 = puVar8 + 1;
          _Buf1 = puVar7 + 1;
          bVar9 = *puVar7 == *puVar8;
          puVar7 = _Buf1;
          puVar8 = _Buf2;
        } while (bVar9);
        if (!bVar9) {
          uVar2 = *(uint *)((int)_Buf1 + -4);
          uVar5 = *(uint *)((int)_Buf2 + -4);
          bVar9 = (byte)uVar2 < (byte)uVar5;
          if ((((byte)uVar2 == (byte)uVar5) &&
              (bVar4 = (byte)(uVar2 >> 8), bVar6 = (byte)(uVar5 >> 8), bVar9 = bVar4 < bVar6,
              bVar4 == bVar6)) &&
             (bVar4 = (byte)(uVar2 >> 0x10), bVar6 = (byte)(uVar5 >> 0x10), bVar9 = bVar4 < bVar6,
             bVar4 == bVar6)) {
            bVar9 = (byte)(uVar2 >> 0x18) < (byte)(uVar5 >> 0x18);
          }
          goto LAB_10021c1a;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)_Buf1;
        uVar1 = *(uint *)_Buf2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_10021c1a:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_10021c1a;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_10021c1a;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((_Size & 1) == 0) goto LAB_10021bcd;
      bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
      if (*(byte *)_Buf1 != *(byte *)_Buf2) goto LAB_10021c1a;
      _Buf1 = (void *)((int)_Buf1 + 1);
      _Buf2 = (void *)((int)_Buf2 + 1);
      for (_Size = _Size - 1; _Size != 0; _Size = _Size - 2) {
LAB_10021bcd:
        bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
        if ((*(byte *)_Buf1 != *(byte *)_Buf2) ||
           (bVar9 = *(byte *)((int)_Buf1 + 1) < *(byte *)((int)_Buf2 + 1),
           *(byte *)((int)_Buf1 + 1) != *(byte *)((int)_Buf2 + 1))) goto LAB_10021c1a;
        _Buf2 = (void *)((int)_Buf2 + 2);
        _Buf1 = (void *)((int)_Buf1 + 2);
      }
    }
  }
  return 0;
}



/* VA 10021c4c */

undefined * FUN_10021c4c(undefined *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  SIZE_T dwBytes;
  int local_30;
  byte *local_2c;
  int *local_28;
  uint *local_24;
  undefined *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_10035140;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  if (param_2 < 0xffffffe1) {
    if (DAT_10043d24 == 3) {
      ExceptionList = &local_14;
      FUN_10022e54(9);
      local_8 = 0;
      local_24 = (uint *)FUN_100246d9((int)param_1);
      if (((local_24 != (uint *)0x0) && (local_20 = (undefined *)0x0, param_2 <= DAT_10043d1c)) &&
         (iVar1 = FUN_10024ee2(local_24,(int)param_1,param_2), iVar1 != 0)) {
        local_20 = param_1;
      }
      local_8 = 0xffffffff;
      FUN_10021cde();
      if (local_24 == (uint *)0x0) {
        puVar2 = (undefined *)FUN_10021d7c();
        return puVar2;
      }
    }
    else {
      if (DAT_10043d24 == 2) {
        if (param_2 == 0) {
          param_2 = 1;
        }
        dwBytes = param_2 + 0xf & 0xfffffff0;
        ExceptionList = &local_14;
        FUN_10022e54(9);
        local_8 = 1;
        local_2c = (byte *)FUN_10025434(param_1,&local_30,(uint *)&local_28);
        if (local_2c != (byte *)0x0) {
          local_20 = (undefined *)0x0;
          if ((dwBytes <= DAT_1003fdcc) &&
             (iVar1 = FUN_100257fc(local_30,local_28,local_2c,param_2 + 0xf >> 4), iVar1 != 0)) {
            local_20 = param_1;
          }
          __local_unwind2((int)&local_14,-1);
          ExceptionList = local_14;
          return local_20;
        }
        local_8 = 0xffffffff;
        FUN_10021d73();
        if (local_2c != (byte *)0x0) {
          ExceptionList = local_14;
          return local_20;
        }
      }
      else {
        if (param_2 == 0) {
          param_2 = 1;
        }
        dwBytes = param_2 + 0xf & 0xfffffff0;
        ExceptionList = &local_14;
      }
      local_20 = HeapReAlloc(DAT_10043d20,0x10,param_1,dwBytes);
    }
  }
  else {
    local_20 = (undefined *)0x0;
  }
  ExceptionList = local_14;
  return local_20;
}



/* VA 10021cde */

void FUN_10021cde(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 10021d73 */

void FUN_10021d73(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 10021d7c */

undefined4 FUN_10021d7c(void)

{
  LPVOID pvVar1;
  int unaff_EBP;
  int unaff_ESI;

  if (unaff_ESI == 0) {
    unaff_ESI = 1;
  }
  pvVar1 = HeapReAlloc(DAT_10043d20,0x10,*(LPVOID *)(unaff_EBP + 8),unaff_ESI + 0xfU & 0xfffffff0);
  *(LPVOID *)(unaff_EBP + -0x1c) = pvVar1;
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return *(undefined4 *)(unaff_EBP + -0x1c);
}



/* VA 10021db0 */

void __cdecl FUN_10021db0(int *param_1)

{
  FUN_10021dbe(param_1,1);
  return;
}



/* VA 10021dbe */

int __cdecl FUN_10021dbe(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;

  piVar6 = param_1;
  uVar3 = param_1[5];
  if ((0x44 < (int)uVar3) && ((int)uVar3 < 0x8c)) {
    iVar5 = param_1[4];
    if ((iVar5 < 0) || (0xb < iVar5)) {
      uVar3 = uVar3 + iVar5 / 0xc;
      iVar5 = iVar5 % 0xc;
      param_1[4] = iVar5;
      if (iVar5 < 0) {
        uVar3 = uVar3 - 1;
        param_1[4] = iVar5 + 0xc;
      }
      if ((int)uVar3 < 0x45) {
        return -1;
      }
      if (0x8b < (int)uVar3) {
        return -1;
      }
    }
    iVar5 = *(int *)(&DAT_10040230 + param_1[4] * 4);
    if (((uVar3 & 3) == 0) && (1 < param_1[4])) {
      iVar5 = iVar5 + 1;
    }
    iVar4 = uVar3 * 0x16d + -0x63df + iVar5 + ((int)(uVar3 - 1) >> 2);
    iVar1 = param_1[3];
    iVar5 = iVar4 + iVar1;
    if (iVar4 < 0) {
      if ((iVar1 < 0) && (-1 < iVar5)) {
        return -1;
      }
    }
    else if ((-1 < iVar1) && (iVar5 < 0)) {
      return -1;
    }
    iVar4 = iVar5 * 0x18;
    if (iVar5 == 0 || iVar4 / iVar5 == 0x18) {
      iVar1 = param_1[2];
      iVar5 = iVar1 + iVar4;
      if (iVar4 < 0) {
        if ((iVar1 < 0) && (-1 < iVar5)) {
          return -1;
        }
      }
      else if ((-1 < iVar1) && (iVar5 < 0)) {
        return -1;
      }
      iVar4 = iVar5 * 0x3c;
      if (iVar5 == 0 || iVar4 / iVar5 == 0x3c) {
        iVar1 = param_1[1];
        iVar5 = iVar1 + iVar4;
        if (iVar4 < 0) {
          if ((iVar1 < 0) && (-1 < iVar5)) {
            return -1;
          }
        }
        else if ((-1 < iVar1) && (iVar5 < 0)) {
          return -1;
        }
        iVar4 = iVar5 * 0x3c;
        if (iVar5 == 0 || iVar4 / iVar5 == 0x3c) {
          iVar5 = *param_1;
          param_1 = (int *)(iVar5 + iVar4);
          if (iVar4 < 0) {
            if ((iVar5 < 0) && (-1 < (int)param_1)) {
              return -1;
            }
          }
          else if ((-1 < iVar5) && ((int)param_1 < 0)) {
            return -1;
          }
          if (param_2 == 0) {
            piVar2 = FUN_10021fa2((int *)&param_1);
            if (piVar2 != (int *)0x0) goto LAB_10021f8f;
          }
          else {
            FUN_100271f4();
            param_1 = (int *)((int)param_1 + DAT_10040148);
            piVar2 = FUN_100220ac((int *)&param_1);
            if (piVar2 != (int *)0x0) {
              iVar5 = piVar6[8];
              if ((0 < iVar5) || ((iVar5 < 0 && (0 < piVar2[8])))) {
                param_1 = (int *)((int)param_1 + DAT_10040150);
                piVar2 = FUN_100220ac((int *)&param_1);
              }
LAB_10021f8f:
              for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
                *piVar6 = *piVar2;
                piVar2 = piVar2 + 1;
                piVar6 = piVar6 + 1;
              }
              return (int)param_1;
            }
          }
        }
      }
    }
  }
  return -1;
}



/* VA 10021fa2 */

int * __cdecl FUN_10021fa2(int *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;

  iVar4 = *param_1;
  bVar1 = false;
  pDVar2 = FUN_10022c01();
  if (iVar4 < 0) {
    return (int *)0x0;
  }
  if (pDVar2[0x10] == 0) {
    pvVar3 = _malloc(0x24);
    pDVar2[0x10] = (DWORD)pvVar3;
    piVar5 = (int *)&DAT_10043868;
    if (pvVar3 == (void *)0x0) goto LAB_10021fdc;
  }
  piVar5 = (int *)pDVar2[0x10];
LAB_10021fdc:
  iVar8 = iVar4 % 0x7861f80;
  iVar4 = (iVar4 / 0x7861f80) * 4;
  iVar6 = iVar4 + 0x46;
  iVar9 = iVar8;
  if (0x1e1337f < iVar8) {
    iVar9 = iVar8 + -0x1e13380;
    iVar6 = iVar4 + 0x47;
    if (0x1e1337f < iVar9) {
      iVar9 = iVar8 + -0x3c26700;
      iVar6 = iVar4 + 0x48;
      if (iVar9 < 0x1e28500) {
        bVar1 = true;
      }
      else {
        iVar6 = iVar4 + 0x49;
        iVar9 = iVar8 + -0x5a4ec00;
      }
    }
  }
  piVar5[5] = iVar6;
  piVar10 = (int *)&DAT_100401fc;
  piVar5[7] = iVar9 / 0x15180;
  if (!bVar1) {
    piVar10 = (int *)&DAT_10040230;
  }
  iVar4 = 1;
  piVar7 = piVar10;
  while (piVar7 = piVar7 + 1, *piVar7 < piVar5[7]) {
    iVar4 = iVar4 + 1;
  }
  piVar5[4] = iVar4 + -1;
  piVar5[3] = piVar5[7] - piVar10[iVar4 + -1];
  piVar5[6] = (*param_1 / 0x15180 + 4) % 7;
  piVar5[2] = (iVar9 % 0x15180) / 0xe10;
  iVar4 = (iVar9 % 0x15180) % 0xe10;
  piVar5[1] = iVar4 / 0x3c;
  piVar5[8] = 0;
  *piVar5 = iVar4 % 0x3c;
  return piVar5;
}



/* VA 100220ac */

int * __cdecl FUN_100220ac(int *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;

  piVar2 = param_1;
  if (*param_1 < 0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_100271f4();
    iVar3 = *piVar2;
    if ((iVar3 < 0x3f481) || (0x7ffc0b7e < iVar3)) {
      piVar2 = FUN_10021fa2(piVar2);
      bVar1 = FUN_100274a9(piVar2);
      iVar3 = *piVar2;
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        iVar3 = iVar3 - DAT_10040150;
      }
      param_1 = (int *)(iVar3 - DAT_10040148);
      iVar3 = (int)param_1 % 0x3c;
      *piVar2 = iVar3;
      if (iVar3 < 0) {
        *piVar2 = iVar3 + 0x3c;
        param_1 = param_1 + -0xf;
      }
      param_1 = (int *)((int)param_1 / 0x3c + piVar2[1]);
      iVar3 = (int)param_1 % 0x3c;
      piVar2[1] = iVar3;
      if (iVar3 < 0) {
        piVar2[1] = iVar3 + 0x3c;
        param_1 = param_1 + -0xf;
      }
      param_1 = (int *)((int)param_1 / 0x3c + piVar2[2]);
      iVar3 = (int)param_1 % 0x18;
      piVar2[2] = iVar3;
      if (iVar3 < 0) {
        piVar2[2] = iVar3 + 0x18;
        param_1 = param_1 + -6;
      }
      iVar3 = (int)param_1 / 0x18;
      if (iVar3 < 1) {
        if (-1 < iVar3) {
          return piVar2;
        }
        piVar2[6] = (piVar2[6] + 7 + iVar3) % 7;
        piVar2[3] = piVar2[3] + iVar3;
        if (piVar2[3] < 1) {
          piVar2[5] = piVar2[5] + -1;
          piVar2[3] = piVar2[3] + 0x1f;
          piVar2[7] = 0x16c;
          piVar2[4] = 0xb;
          return piVar2;
        }
      }
      else {
        piVar2[6] = (piVar2[6] + iVar3) % 7;
        piVar2[3] = piVar2[3] + iVar3;
      }
      piVar2[7] = piVar2[7] + iVar3;
    }
    else {
      param_1 = (int *)(iVar3 - DAT_10040148);
      piVar2 = FUN_10021fa2((int *)&param_1);
      if ((DAT_1004014c != 0) && (bVar1 = FUN_100274a9(piVar2), CONCAT31(extraout_var,bVar1) != 0))
      {
        param_1 = (int *)((int)param_1 - DAT_10040150);
        piVar2 = FUN_10021fa2((int *)&param_1);
        piVar2[8] = 1;
      }
    }
  }
  return piVar2;
}



/* VA 1002220c */

void FUN_1002220c(void)

{
  if (PTR_FUN_1003d6f8 != (undefined *)0x0) {
    (*(code *)PTR_FUN_1003d6f8)();
  }
  FUN_10022310((undefined4 *)&DAT_1003a078,(undefined4 *)&DAT_1003a08c);
  FUN_10022310((undefined4 *)&DAT_1003a000,(undefined4 *)&DAT_1003a074);
  return;
}



/* VA 10022239 */

/* Library Function - Single Match
    __exit

   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_10022259(_Code,1,0);
  return;
}



/* VA 1002224a */

void FUN_1002224a(void)

{
  FUN_10022259(0,0,1);
  return;
}



/* VA 10022259 */

void __cdecl FUN_10022259(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;

  FUN_100222fe();
  if (DAT_100438cc == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_100438c8 = 1;
  DAT_100438c4 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_10044d50 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_10044d4c - 4), DAT_10044d50 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_10044d50 <= puVar1);
    }
    FUN_10022310((undefined4 *)&DAT_1003a090,(undefined4 *)&DAT_1003a098);
  }
  FUN_10022310((undefined4 *)&DAT_1003a09c,(undefined4 *)&DAT_1003a0a4);
  if (param_3 == 0) {
    DAT_100438cc = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_10022307();
  return;
}



/* VA 100222fe */

void FUN_100222fe(void)

{
  FUN_10022e54(0xd);
  return;
}



/* VA 10022307 */

void FUN_10022307(void)

{
  FUN_10022eb5(0xd);
  return;
}



/* VA 10022310 */

void __cdecl FUN_10022310(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* VA 1002232a */

undefined4 __cdecl
FUN_1002232a(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,char param_8)

{
  code *pcVar1;
  undefined4 uVar2;

  if (*param_5 != 0x19930520) {
    FUN_10022d69();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_100223c5(param_1,param_2,param_3,param_4,(int)param_5,param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_1002267f((int)param_2,param_4,(int)param_5,-1);
  }
  return 1;
}



/* VA 100223c5 */

void __cdecl
FUN_100223c5(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            char param_6,int param_7,PVOID param_8)

{
  byte *pbVar1;
  bool bVar2;
  DWORD *pDVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;

  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_10022d69();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_10022c01();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_10022c01();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_10022c01();
      param_3 = pDVar3[0x1c];
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar2 = FUN_100277b6(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_10022d69();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_1002254d;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_10022d69();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_1001ef2f(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_10022aa1((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; iVar5 = local_14, 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_10022622(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_1002271d(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                iVar5 = local_14;
                goto LAB_1002252d;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
        }
LAB_1002252d:
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_1002254d:
  if (param_6 == '\0') {
    FUN_10022578(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_10022d08();
  return;
}



/* VA 10022578 */

void __cdecl
FUN_10022578(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_c;
  uint local_8;

  pDVar1 = FUN_10022c01();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_1001ee04(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_1001ef2f(param_5,param_7,param_6,&local_8,&local_c);
  for (; local_8 < local_c; local_8 = local_8 + 1) {
    if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
      iVar4 = piVar3[3] * 0x10 + piVar3[4];
      iVar2 = *(int *)(iVar4 + -0xc);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        FUN_1002271d(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                     piVar3,param_7,param_8);
      }
    }
    piVar3 = piVar3 + 5;
  }
  return;
}



/* VA 10022622 */

undefined4 __cdecl FUN_10022622(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_10022679:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_10022653:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_10022679;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_10022653;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 1002267f */

void __cdecl FUN_1002267f(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_10035280;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_10022d69();
    }
    local_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  ExceptionList = local_14;
  return;
}



/* VA 1002271d */

void __cdecl
FUN_1002271d(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;

  if (param_7 != (byte *)0x0) {
    FUN_100228dd((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  FUN_1001ed06(param_10,param_1);
  FUN_1002267f((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_10022798((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_1001ecc4(UNRECOVERED_JUMPTABLE);
  }
  return;
}



/* VA 10022798 */

undefined4 __cdecl
FUN_10022798(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_10035290;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_10022c01();
  FUN_10022c01();
  pDVar1 = FUN_10022c01();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_10022c01();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_1001ed8b(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_10022865();
  ExceptionList = local_14;
  return uVar2;
}



/* VA 10022865 */

void FUN_10022865(void)

{
  DWORD *pDVar1;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;

  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_10022c01();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_10022c01();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (*(int *)(unaff_EBP + -0x2c) != 0)))) {
    __abnormal_termination();
    FUN_10022aa1((int)unaff_EDI);
  }
  return;
}



/* VA 100228dd */

void __cdecl FUN_100228dd(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 *puVar4;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  uint uVar5;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_100352a8;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  if (*(int *)(param_3 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_3 + 4) + 8) == '\0') {
    return;
  }
  if (*(int *)(param_3 + 8) == 0) {
    return;
  }
  piVar1 = (int *)(*(int *)(param_3 + 8) + 0xc + param_2);
  local_8 = 0;
  if ((*param_3 & 8) == 0) {
    if ((*param_4 & 1) == 0) {
      if (*(int *)(param_4 + 0x18) == 0) {
        ExceptionList = &local_14;
        bVar2 = FUN_100277b6(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
           (bVar2 = FUN_100277d2(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
          uVar5 = *(uint *)(param_4 + 0x14);
          puVar4 = (undefined4 *)FUN_10022b08(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_10020590(piVar1,puVar4,uVar5);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        bVar2 = FUN_100277b6(*(void **)(param_1 + 0x18),1);
        if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
            (bVar2 = FUN_100277d2(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
           (bVar2 = FUN_100277ee(*(FARPROC *)(param_4 + 0x18)), CONCAT31(extraout_var_07,bVar2) != 0
           )) {
          if ((*param_4 & 4) != 0) {
            FUN_10022b08(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_1001ecff(piVar1,*(undefined **)(param_4 + 0x18));
            ExceptionList = local_14;
            return;
          }
          FUN_10022b08(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
          FUN_1001ecf8(piVar1,*(undefined **)(param_4 + 0x18));
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      bVar2 = FUN_100277b6(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
         (bVar2 = FUN_100277d2(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
        FUN_10020590(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar3 = *piVar1;
        if (iVar3 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_1002296b;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    bVar2 = FUN_100277b6(*(void **)(param_1 + 0x18),1);
    if ((CONCAT31(extraout_var,bVar2) != 0) &&
       (bVar2 = FUN_100277d2(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
      iVar3 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar3;
LAB_1002296b:
      iVar3 = FUN_10022b08(iVar3,(int *)(param_4 + 8));
      *piVar1 = iVar3;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_10022d69();
  ExceptionList = local_14;
  return;
}



/* VA 10022aa1 */

void __cdecl FUN_10022aa1(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_100352b8;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    ExceptionList = &local_14;
    FUN_1001ecf8(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  ExceptionList = local_14;
  return;
}



/* VA 10022b08 */

int __cdecl FUN_10022b08(int param_1,int *param_2)

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



/* VA 10022b30 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;

  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}



/* VA 10022b7c */

undefined4 FUN_10022b7c(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  FUN_10022dbf();
  DAT_1003da50 = TlsAlloc();
  if (DAT_1003da50 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_100270b7(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_1003da50,lpTlsValue);
      if (BVar1 != 0) {
        FUN_10022bee((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}



/* VA 10022bd0 */

void FUN_10022bd0(void)

{
  FUN_10022de8();
  if (DAT_1003da50 != 0xffffffff) {
    TlsFree(DAT_1003da50);
    DAT_1003da50 = 0xffffffff;
  }
  return;
}



/* VA 10022bee */

void __cdecl FUN_10022bee(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_100400c0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



/* VA 10022c01 */

DWORD * FUN_10022c01(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_1003da50);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_100270b7(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_1003da50,lpTlsValue);
      if (BVar1 != 0) {
        FUN_10022bee((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_10022c5c;
      }
    }
    __amsg_exit(0x10);
  }
LAB_10022c5c:
  SetLastError(dwErrCode);
  return lpTlsValue;
}



/* VA 10022c68 */

void __cdecl FUN_10022c68(undefined *param_1)

{
  if (DAT_1003da50 != 0xffffffff) {
    if ((param_1 != (undefined *)0x0) ||
       (param_1 = TlsGetValue(DAT_1003da50), param_1 != (undefined *)0x0)) {
      if (*(undefined **)(param_1 + 0x24) != (undefined *)0x0) {
        FUN_1001fabf(*(undefined **)(param_1 + 0x24));
      }
      if (*(undefined **)(param_1 + 0x28) != (undefined *)0x0) {
        FUN_1001fabf(*(undefined **)(param_1 + 0x28));
      }
      if (*(undefined **)(param_1 + 0x30) != (undefined *)0x0) {
        FUN_1001fabf(*(undefined **)(param_1 + 0x30));
      }
      if (*(undefined **)(param_1 + 0x38) != (undefined *)0x0) {
        FUN_1001fabf(*(undefined **)(param_1 + 0x38));
      }
      if (*(undefined **)(param_1 + 0x40) != (undefined *)0x0) {
        FUN_1001fabf(*(undefined **)(param_1 + 0x40));
      }
      if (*(undefined **)(param_1 + 0x44) != (undefined *)0x0) {
        FUN_1001fabf(*(undefined **)(param_1 + 0x44));
      }
      if (*(undefined **)(param_1 + 0x50) != &DAT_100400c0) {
        FUN_1001fabf(*(undefined **)(param_1 + 0x50));
      }
      FUN_1001fabf(param_1);
    }
    TlsSetValue(DAT_1003da50,(LPVOID)0x0);
    return;
  }
  return;
}



/* VA 10022d08 */

void FUN_10022d08(void)

{
  DWORD *pDVar1;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_100352c8;
  puStack_10 = &LAB_1001f834;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  pDVar1 = FUN_10022c01();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_10022c01();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
  FUN_10027806();
  return;
}



/* VA 10022d69 */

void FUN_10022d69(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_100352e0;
  puStack_10 = &LAB_1001f834;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_1003da54 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_1003da54)();
  }
  local_8 = 0xffffffff;
  FUN_10022d08();
  return;
}



/* VA 10022dbf */

void FUN_10022dbf(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1003da9c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1003da8c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1003da7c);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1003da5c);
  return;
}



/* VA 10022de8 */

void FUN_10022de8(void)

{
  undefined **ppuVar1;

  ppuVar1 = (undefined **)&DAT_1003da58;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_1003da9c)) && (ppuVar1 != &PTR_DAT_1003da8c)) &&
       ((ppuVar1 != &PTR_DAT_1003da7c && (ppuVar1 != &PTR_DAT_1003da5c)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_1001fabf(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x1003db18);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1003da7c);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1003da8c);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1003da9c);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1003da5c);
  return;
}



/* VA 10022e54 */

void __cdecl FUN_10022e54(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;

  piVar1 = &DAT_1003da58 + param_1;
  if ((&DAT_1003da58)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_10022e54(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_1001fabf((undefined *)lpCriticalSection);
    }
    FUN_10022eb5(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}



/* VA 10022eb5 */

void __cdecl FUN_10022eb5(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_1003da58)[param_1]);
  return;
}



/* VA 10022f86 */

void __cdecl FUN_10022f86(uint param_1)

{
  if ((0x1003db17 < param_1) && (param_1 < 0x1003dd79)) {
    FUN_10022e54(((int)(param_1 + 0xeffc24e8) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 10022fb5 */

void __cdecl FUN_10022fb5(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_10022e54(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 10022fd8 */

void __cdecl FUN_10022fd8(uint param_1)

{
  if ((0x1003db17 < param_1) && (param_1 < 0x1003dd79)) {
    FUN_10022eb5(((int)(param_1 + 0xeffc24e8) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 10023007 */

void __cdecl FUN_10023007(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_10022eb5(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 1002302a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1002302a(undefined4 *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  void *pvVar4;

  bVar2 = FUN_1002789e(param_1[4]);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  if (param_1 == (undefined4 *)&DAT_1003db38) {
    iVar3 = 0;
  }
  else {
    if (param_1 != (undefined4 *)&DAT_1003db58) {
      return 0;
    }
    iVar3 = 1;
  }
  _DAT_10043930 = _DAT_10043930 + 1;
  if ((*(ushort *)(param_1 + 3) & 0x10c) != 0) {
    return 0;
  }
  if ((&DAT_10043934)[iVar3] == 0) {
    pvVar4 = _malloc(0x1000);
    (&DAT_10043934)[iVar3] = pvVar4;
    if (pvVar4 == (void *)0x0) {
      param_1[2] = param_1 + 5;
      *param_1 = param_1 + 5;
      param_1[6] = 2;
      param_1[1] = 2;
      goto LAB_100230a6;
    }
  }
  uVar1 = (&DAT_10043934)[iVar3];
  param_1[6] = 0x1000;
  param_1[2] = uVar1;
  *param_1 = uVar1;
  param_1[1] = 0x1000;
LAB_100230a6:
  *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x1102;
  return 1;
}



/* VA 100230b7 */

void __cdecl FUN_100230b7(int param_1,int *param_2)

{
  if ((param_1 != 0) && ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0)) {
    FUN_1001fe25(param_2);
    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) & 0xee;
    param_2[6] = 0;
    *param_2 = 0;
    param_2[2] = 0;
  }
  return;
}



/* VA 100230e1 */

int __cdecl FUN_100230e1(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  uint uVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  undefined4 uVar5;
  short *psVar6;
  int *piVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined1 local_24c [511];
  undefined1 local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  CHAR local_3c [4];
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  char local_1a;
  char local_19;
  int local_18;
  int local_14;
  undefined1 *local_10;
  WCHAR *local_c;
  uint local_8;

  local_34 = 0;
  bVar9 = *param_2;
  local_10 = (undefined1 *)0x0;
  local_18 = 0;
  pbVar1 = param_2;
  do {
    if ((bVar9 == 0) || (param_2 = pbVar1 + 1, local_18 < 0)) {
      return local_18;
    }
    if (((char)bVar9 < ' ') || ('x' < (char)bVar9)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(byte *)((int)&PTR_LAB_100352d8 + (int)(char)bVar9) & 0xf;
    }
    local_34 = (int)(char)(&DAT_100352f8)[uVar2 * 8 + local_34] >> 4;
    switch(local_34) {
    case 0:
switchD_1002314f_caseD_0:
      local_28 = 0;
      if ((PTR_DAT_1003fdd0[(uint)bVar9 * 2 + 1] & 0x80) != 0) {
        FUN_10023822((int)(char)bVar9,param_1,&local_18);
        bVar9 = *param_2;
        param_2 = pbVar1 + 2;
      }
      FUN_10023822((int)(char)bVar9,param_1,&local_18);
      break;
    case 1:
      local_14 = -1;
      local_38 = 0;
      local_2c = 0;
      local_24 = 0;
      local_20 = 0;
      local_8 = 0;
      local_28 = 0;
      break;
    case 2:
      if (bVar9 == 0x20) {
        local_8 = local_8 | 2;
      }
      else if (bVar9 == 0x23) {
        local_8 = local_8 | 0x80;
      }
      else if (bVar9 == 0x2b) {
        local_8 = local_8 | 1;
      }
      else if (bVar9 == 0x2d) {
        local_8 = local_8 | 4;
      }
      else if (bVar9 == 0x30) {
        local_8 = local_8 | 8;
      }
      break;
    case 3:
      if (bVar9 == 0x2a) {
        local_24 = FUN_100238c0((int *)&param_3);
        if (local_24 < 0) {
          local_8 = local_8 | 4;
          local_24 = -local_24;
        }
      }
      else {
        local_24 = (char)bVar9 + -0x30 + local_24 * 10;
      }
      break;
    case 4:
      local_14 = 0;
      break;
    case 5:
      if (bVar9 == 0x2a) {
        local_14 = FUN_100238c0((int *)&param_3);
        if (local_14 < 0) {
          local_14 = -1;
        }
      }
      else {
        local_14 = (char)bVar9 + -0x30 + local_14 * 10;
      }
      break;
    case 6:
      if (bVar9 == 0x49) {
        if ((*param_2 != 0x36) || (pbVar1[2] != 0x34)) {
          local_34 = 0;
          goto switchD_1002314f_caseD_0;
        }
        param_2 = pbVar1 + 3;
        local_8 = local_8 | 0x8000;
      }
      else if (bVar9 == 0x68) {
        local_8 = local_8 | 0x20;
      }
      else if (bVar9 == 0x6c) {
        local_8 = local_8 | 0x10;
      }
      else if (bVar9 == 0x77) {
        local_8 = local_8 | 0x800;
      }
      break;
    case 7:
      pWVar4 = local_c;
      if ((char)bVar9 < 'h') {
        if ((char)bVar9 < 'e') {
          if ((char)bVar9 < 'Y') {
            if (bVar9 == 0x58) {
LAB_10023560:
              local_30 = 7;
LAB_10023567:
              local_10 = (undefined1 *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_100235d1;
            }
            if (bVar9 != 0x43) {
              if ((bVar9 != 0x45) && (bVar9 != 0x47)) {
                if (bVar9 == 0x53) {
                  if ((local_8 & 0x830) == 0) {
                    local_8 = local_8 | 0x800;
                  }
                  goto LAB_1002330e;
                }
                goto LAB_100236eb;
              }
              local_38 = 1;
              bVar9 = bVar9 + 0x20;
              goto LAB_1002336f;
            }
            if ((local_8 & 0x830) == 0) {
              local_8 = local_8 | 0x800;
            }
LAB_1002339c:
            if ((local_8 & 0x810) == 0) {
              uVar5 = FUN_100238c0((int *)&param_3);
              local_24c[0] = (char)uVar5;
              local_10 = (undefined1 *)0x1;
            }
            else {
              uVar5 = FUN_100238dd((int *)&param_3);
              local_10 = (undefined1 *)FUN_100278c7(local_24c,(WCHAR)uVar5);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar4 = (WCHAR *)local_24c;
          }
          else if (bVar9 == 0x5a) {
            psVar6 = (short *)FUN_100238c0((int *)&param_3);
            if ((psVar6 == (short *)0x0) ||
               (pWVar4 = *(WCHAR **)(psVar6 + 2), pWVar4 == (WCHAR *)0x0)) {
              local_c = (WCHAR *)PTR_DAT_1003dd98;
              pWVar4 = (WCHAR *)PTR_DAT_1003dd98;
              goto LAB_100234e1;
            }
            if ((local_8 & 0x800) == 0) {
              local_28 = 0;
              local_10 = (undefined1 *)(int)*psVar6;
            }
            else {
              local_28 = 1;
              local_10 = (undefined1 *)((uint)(int)*psVar6 >> 1);
            }
          }
          else {
            if (bVar9 == 99) goto LAB_1002339c;
            if (bVar9 == 100) goto LAB_100235c6;
          }
        }
        else {
LAB_1002336f:
          local_8 = local_8 | 0x40;
          pWVar4 = (WCHAR *)local_24c;
          if (local_14 < 0) {
            local_14 = 6;
          }
          else if ((local_14 == 0) && (bVar9 == 0x67)) {
            local_14 = 1;
          }
          local_4c = *param_3;
          local_48 = param_3[1];
          param_3 = param_3 + 2;
          local_c = pWVar4;
          (*(code *)PTR___fptrap_1003fff0)(&local_4c,local_24c,(int)(char)bVar9,local_14,local_38);
          uVar2 = local_8 & 0x80;
          if ((uVar2 != 0) && (local_14 == 0)) {
            (*(code *)PTR___fptrap_1003fffc)(local_24c);
          }
          if ((bVar9 == 0x67) && (uVar2 == 0)) {
            (*(code *)PTR___fptrap_1003fff4)(local_24c);
          }
          if (local_24c[0] == '-') {
            local_8 = local_8 | 0x100;
            pWVar4 = (WCHAR *)(local_24c + 1);
            local_c = pWVar4;
          }
LAB_100234e1:
          local_10 = (undefined1 *)_strlen((char *)pWVar4);
          pWVar4 = local_c;
        }
      }
      else {
        if (bVar9 == 0x69) {
LAB_100235c6:
          local_8 = local_8 | 0x40;
        }
        else {
          if (bVar9 == 0x6e) {
            piVar7 = (int *)FUN_100238c0((int *)&param_3);
            if ((local_8 & 0x20) == 0) {
              *piVar7 = local_18;
            }
            else {
              *(undefined2 *)piVar7 = (undefined2)local_18;
            }
            local_2c = 1;
            break;
          }
          if (bVar9 == 0x6f) {
            local_10 = (undefined1 *)0x8;
            if ((local_8 & 0x80) != 0) {
              local_8 = local_8 | 0x200;
            }
            goto LAB_100235d1;
          }
          if (bVar9 == 0x70) {
            local_14 = 8;
            goto LAB_10023560;
          }
          if (bVar9 == 0x73) {
LAB_1002330e:
            iVar10 = local_14;
            if (local_14 == -1) {
              iVar10 = 0x7fffffff;
            }
            pWVar3 = (WCHAR *)FUN_100238c0((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              pWVar4 = pWVar3;
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_1003dd98;
                pWVar4 = (WCHAR *)PTR_DAT_1003dd98;
              }
              for (; (iVar10 != 0 && ((char)*pWVar3 != '\0')); pWVar3 = (WCHAR *)((int)pWVar3 + 1))
              {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar3 - (int)pWVar4);
            }
            else {
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_1003dd9c;
              }
              local_28 = 1;
              for (pWVar4 = pWVar3; (iVar10 != 0 && (*pWVar4 != L'\0')); pWVar4 = pWVar4 + 1) {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar4 - (int)pWVar3 >> 1);
              pWVar4 = pWVar3;
            }
            goto LAB_100236eb;
          }
          if (bVar9 != 0x75) {
            if (bVar9 != 0x78) goto LAB_100236eb;
            local_30 = 0x27;
            goto LAB_10023567;
          }
        }
        local_10 = (undefined1 *)0xa;
LAB_100235d1:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar2 = FUN_100238c0((int *)&param_3);
              uVar13 = (ulonglong)uVar2;
              goto LAB_10023624;
            }
            uVar2 = FUN_100238c0((int *)&param_3);
          }
          else if ((local_8 & 0x40) == 0) {
            uVar2 = FUN_100238c0((int *)&param_3);
            uVar2 = uVar2 & 0xffff;
          }
          else {
            uVar5 = FUN_100238c0((int *)&param_3);
            uVar2 = (uint)(short)uVar5;
          }
          uVar13 = (ulonglong)(int)uVar2;
        }
        else {
          uVar13 = FUN_100238cd((int *)&param_3);
        }
LAB_10023624:
        iVar10 = (int)(uVar13 >> 0x20);
        if ((((local_8 & 0x40) != 0) && (iVar10 == 0 || (longlong)uVar13 < 0)) &&
           ((longlong)uVar13 < 0)) {
          local_8 = local_8 | 0x100;
          uVar13 = CONCAT44(-(iVar10 + (uint)((int)uVar13 != 0)),-(int)uVar13);
        }
        uVar2 = (uint)(uVar13 >> 0x20);
        uVar15 = uVar13 & 0xffffffff;
        if ((local_8 & 0x8000) == 0) {
          uVar2 = 0;
        }
        if (local_14 < 0) {
          local_14 = 1;
        }
        else {
          local_8 = local_8 & 0xfffffff7;
        }
        if ((int)uVar13 == 0 && uVar2 == 0) {
          local_20 = 0;
        }
        local_c = (WCHAR *)&local_4d;
        while( true ) {
          uVar11 = (uint)uVar15;
          iVar10 = local_14 + -1;
          if ((local_14 < 1) && (uVar11 == 0 && uVar2 == 0)) break;
          local_40 = (int)local_10 >> 0x1f;
          local_44 = (uint)local_10;
          local_14 = iVar10;
          uVar14 = __aullrem(uVar11,uVar2,(uint)local_10,local_40);
          iVar10 = (int)uVar14 + 0x30;
          uVar15 = __aulldiv(uVar11,uVar2,local_44,local_40);
          uVar2 = (uint)(uVar15 >> 0x20);
          if (0x39 < iVar10) {
            iVar10 = iVar10 + local_30;
          }
          pWVar4 = (WCHAR *)((int)local_c + -1);
          *(char *)local_c = (char)iVar10;
          local_c = pWVar4;
        }
        iVar8 = -(int)local_c;
        local_10 = &local_4d + iVar8;
        pWVar4 = (WCHAR *)((int)local_c + 1);
        local_14 = iVar10;
        if (((local_8 & 0x200) != 0) &&
           ((*(char *)pWVar4 != '0' || (local_10 == (undefined1 *)0x0)))) {
          *(char *)local_c = '0';
          local_10 = (undefined1 *)((int)&local_4c + iVar8);
          pWVar4 = local_c;
        }
      }
LAB_100236eb:
      local_c = pWVar4;
      uVar2 = local_8;
      if (local_2c == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) == 0) goto LAB_10023723;
              local_1a = ' ';
            }
            else {
              local_1a = '+';
            }
          }
          else {
            local_1a = '-';
          }
          local_20 = 1;
        }
LAB_10023723:
        iVar10 = (local_24 - local_20) - (int)local_10;
        if ((local_8 & 0xc) == 0) {
          FUN_10023857(0x20,iVar10,param_1,&local_18);
        }
        FUN_10023888(&local_1a,local_20,param_1,&local_18);
        if (((uVar2 & 8) != 0) && ((uVar2 & 4) == 0)) {
          FUN_10023857(0x30,iVar10,param_1,&local_18);
        }
        if ((local_28 == 0) || (puVar12 = local_10, pWVar4 = local_c, (int)local_10 < 1)) {
          FUN_10023888((char *)local_c,(int)local_10,param_1,&local_18);
        }
        else {
          do {
            puVar12 = puVar12 + -1;
            iVar8 = FUN_100278c7(local_3c,*pWVar4);
            if (iVar8 < 1) break;
            FUN_10023888(local_3c,iVar8,param_1,&local_18);
            pWVar4 = pWVar4 + 1;
          } while (puVar12 != (undefined1 *)0x0);
        }
        if ((local_8 & 4) != 0) {
          FUN_10023857(0x20,iVar10,param_1,&local_18);
        }
      }
    }
    bVar9 = *param_2;
    pbVar1 = param_2;
  } while( true );
}



/* VA 10023822 */

void __cdecl FUN_10023822(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;

  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_100242ff(param_1,param_2);
  }
  else {
    *(undefined1 *)*param_2 = (undefined1)param_1;
    *param_2 = *param_2 + 1;
    uVar2 = param_1 & 0xff;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}



/* VA 10023857 */

void __cdecl FUN_10023857(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_10023822(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 10023888 */

void __cdecl FUN_10023888(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;

  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_10023822((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 100238c0 */

undefined4 __cdecl FUN_100238c0(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}



/* VA 100238cd */

undefined8 __cdecl FUN_100238cd(int *param_1)

{
  *param_1 = *param_1 + 8;
  return *(undefined8 *)(*param_1 + -8);
}



/* VA 100238dd */

undefined4 __cdecl FUN_100238dd(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}



/* VA 100238eb */

int __cdecl
FUN_100238eb(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_10035378;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_1004393c == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_1004393c = 2;
    }
    else {
      DAT_1004393c = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_100280fb(param_3,param_4);
  }
  if (DAT_1004393c == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_1004393c == 1) {
    if (param_7 == 0) {
      param_7 = DAT_10043a7c;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_1001fa90();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((param_2 & 0x400) == 0) {
            local_8 = 1;
            FUN_1001fa90();
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x3c) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,
                                 (LPWSTR)&stack0xffffffc4,iVar2);
            if (iVar1 == 0) {
              ExceptionList = local_14;
              return 0;
            }
            if (param_6 == 0) {
              param_6 = 0;
              param_5 = (LPWSTR)0x0;
            }
            iVar2 = WideCharToMultiByte(param_7,0x220,(LPCWSTR)&stack0xffffffc4,iVar2,(LPSTR)param_5
                                        ,param_6,(LPCSTR)0x0,(LPBOOL)0x0);
            iVar1 = iVar2;
          }
          else {
            if (param_6 == 0) {
              ExceptionList = local_14;
              return iVar2;
            }
            if (param_6 < iVar2) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,param_5,param_6);
          }
          if (iVar1 != 0) {
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* VA 10023b10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_10023b10(void *this,byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  uint uVar8;
  uint uVar9;
  uint uVar7;

  iVar2 = _DAT_10043bf8;
  if (DAT_10043a6c == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_10023b5e;
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
LAB_10023b5e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_10043bf8 = _DAT_10043bf8 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_10043bf4;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_10043bf8 = iVar2;
      FUN_10022e54(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_10023bbf;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_10027ae4(this,uVar8);
      uVar7 = FUN_10027ae4(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_10023bbf:
    if (uVar9 == 0) {
      LOCK();
      _DAT_10043bf8 = _DAT_10043bf8 + -1;
      UNLOCK();
    }
    else {
      FUN_10022eb5(0x13);
    }
  }
  return uVar7;
}



/* VA 10023be0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_10023be0(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;

  bVar4 = false;
  bVar3 = false;
  cVar1 = *param_2;
  if (cVar1 == 'a') {
    uVar5 = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      uVar5 = 0;
      uVar6 = DAT_10043a5c | 1;
      goto LAB_10023c21;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_10043a5c | 2;
LAB_10023c21:
  bVar2 = true;
LAB_10023c24:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_10027baf(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_10043930 = _DAT_10043930 + 1;
    param_4[3] = uVar6;
    param_4[1] = 0;
    *param_4 = 0;
    param_4[2] = 0;
    param_4[7] = 0;
    param_4[4] = uVar5;
    return param_4;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((uVar5 & 0x1000) == 0) {
        uVar5 = uVar5 | 0x1000;
        goto LAB_10023c24;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_10023c24;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_10023c24;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_10023c24;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_10023c24;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_10023d04;
      uVar5 = uVar5 | 0x8000;
      goto LAB_10023c24;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_10023c24;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_10023d04;
        uVar5 = uVar5 | 0x4000;
        goto LAB_10023c24;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_10023c24;
      }
    }
  }
LAB_10023d04:
  bVar2 = false;
  goto LAB_10023c24;
}



/* VA 10023d50 */

undefined4 * FUN_10023d50(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;

  puVar4 = (undefined4 *)0x0;
  FUN_10022e54(2);
  iVar3 = 0;
  if (0 < DAT_10044d40) {
    do {
      iVar1 = *(int *)(DAT_10043d28 + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(iVar3 + DAT_10043d28) = pvVar2;
        if (*(int *)(iVar3 + DAT_10043d28) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_10043d28) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_10043d28) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_10043d28);
LAB_10023df4:
          if (puVar4 != (undefined4 *)0x0) {
            puVar4[4] = 0xffffffff;
            puVar4[1] = 0;
            puVar4[3] = 0;
            puVar4[2] = 0;
            *puVar4 = 0;
            puVar4[7] = 0;
          }
        }
        break;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
        FUN_10022fb5(iVar3,iVar1);
        iVar1 = *(int *)(DAT_10043d28 + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_10043d28 + iVar3 * 4);
          goto LAB_10023df4;
        }
        FUN_10023007(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_10044d40);
  }
  FUN_10022eb5(2);
  return puVar4;
}



/* VA 10023e18 */

undefined4 __cdecl FUN_10023e18(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_10043d00) &&
     ((*(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10020ede(param_1);
    uVar1 = FUN_10023e75(param_1);
    FUN_10020f3d(param_1);
    return uVar1;
  }
  pDVar2 = FUN_10020fd2();
  *pDVar2 = 9;
  pDVar2 = FUN_10020fdb();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 10023e75 */

undefined4 __cdecl FUN_10023e75(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;

  iVar1 = FUN_10020df5(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_10020df5(2);
      iVar2 = FUN_10020df5(1);
      if (iVar2 == iVar1) goto LAB_10023ec3;
    }
    hObject = (HANDLE)FUN_10020df5(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_10023ec5;
    }
  }
LAB_10023ec3:
  DVar4 = 0;
LAB_10023ec5:
  FUN_10020d76(param_1);
  *(undefined1 *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_10020f5f(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



/* VA 10023ef8 */

/* Library Function - Single Match
    __freebuf

   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_1001fabf(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}



/* VA 10023f23 */

byte * __cdecl FUN_10023f23(byte *param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  byte *pbVar3;
  int local_3c;
  uint *local_38;
  byte *local_34;
  int *local_30;
  uint *local_2c;
  byte *local_28;
  uint *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_10035390;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  pbVar3 = (byte *)0x0;
  if (param_1 == (byte *)0x0) {
    ExceptionList = &local_14;
    pbVar3 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      ExceptionList = &local_14;
      FUN_1001fabf(param_1);
    }
    else {
      ExceptionList = &local_14;
      if (DAT_10043d24 == 3) {
        do {
          local_28 = (byte *)0x0;
          if (param_2 < (uint *)0xffffffe1) {
            FUN_10022e54(9);
            local_8 = 0;
            local_2c = (uint *)FUN_100246d9((int)param_1);
            if (local_2c != (uint *)0x0) {
              if (param_2 <= DAT_10043d1c) {
                iVar1 = FUN_10024ee2(local_2c,(int)param_1,(int)param_2);
                if (iVar1 == 0) {
                  local_28 = (byte *)FUN_10024a2d(param_2);
                  if (local_28 != (byte *)0x0) {
                    local_24 = (uint *)(*(int *)(param_1 + -4) - 1);
                    puVar2 = local_24;
                    if (param_2 <= local_24) {
                      puVar2 = param_2;
                    }
                    FUN_100200e0((undefined4 *)local_28,(undefined4 *)param_1,(uint)puVar2);
                    local_2c = (uint *)FUN_100246d9((int)param_1);
                    FUN_10024704(local_2c,(int)param_1);
                  }
                }
                else {
                  local_28 = param_1;
                }
              }
              if (local_28 == (byte *)0x0) {
                if (param_2 == (uint *)0x0) {
                  param_2 = (uint *)0x1;
                }
                param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
                local_28 = HeapAlloc(DAT_10043d20,0,(SIZE_T)param_2);
                if (local_28 != (byte *)0x0) {
                  local_24 = (uint *)(*(int *)(param_1 + -4) - 1);
                  puVar2 = local_24;
                  if (param_2 <= local_24) {
                    puVar2 = param_2;
                  }
                  FUN_100200e0((undefined4 *)local_28,(undefined4 *)param_1,(uint)puVar2);
                  FUN_10024704(local_2c,(int)param_1);
                }
              }
            }
            local_8 = 0xffffffff;
            FUN_100240ae();
            if (local_2c == (uint *)0x0) {
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              local_28 = HeapReAlloc(DAT_10043d20,0,param_1,(SIZE_T)param_2);
            }
          }
          if (local_28 != (byte *)0x0) {
            ExceptionList = local_14;
            return local_28;
          }
          if (DAT_10043944 == (byte *)0x0) {
            ExceptionList = local_14;
            return (byte *)0x0;
          }
          iVar1 = FUN_100258a5(param_2);
        } while (iVar1 != 0);
      }
      else {
        ExceptionList = &local_14;
        if (DAT_10043d24 == 2) {
          ExceptionList = &local_14;
          if (param_2 < (uint *)0xffffffe1) {
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x10;
              ExceptionList = &local_14;
            }
            else {
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              ExceptionList = &local_14;
            }
          }
          do {
            local_28 = pbVar3;
            if (param_2 < (uint *)0xffffffe1) {
              FUN_10022e54(9);
              local_8 = 1;
              pbVar3 = (byte *)FUN_10025434(param_1,&local_3c,(uint *)&local_30);
              local_34 = pbVar3;
              if (pbVar3 == (byte *)0x0) {
                local_28 = HeapReAlloc(DAT_10043d20,0,param_1,(SIZE_T)param_2);
              }
              else {
                if (param_2 < DAT_1003fdcc) {
                  iVar1 = FUN_100257fc(local_3c,local_30,pbVar3,(uint)param_2 >> 4);
                  if (iVar1 == 0) {
                    local_28 = (byte *)FUN_100254d0((uint)param_2 >> 4);
                    if (local_28 != (byte *)0x0) {
                      local_38 = (uint *)((uint)*pbVar3 << 4);
                      puVar2 = local_38;
                      if (param_2 <= local_38) {
                        puVar2 = param_2;
                      }
                      FUN_100200e0((undefined4 *)local_28,(undefined4 *)param_1,(uint)puVar2);
                      FUN_1002548b(local_3c,(int)local_30,pbVar3);
                    }
                  }
                  else {
                    local_28 = param_1;
                  }
                }
                if ((local_28 == (byte *)0x0) &&
                   (local_28 = HeapAlloc(DAT_10043d20,0,(SIZE_T)param_2), local_28 != (byte *)0x0))
                {
                  local_38 = (uint *)((uint)*pbVar3 << 4);
                  puVar2 = local_38;
                  if (param_2 <= local_38) {
                    puVar2 = param_2;
                  }
                  FUN_100200e0((undefined4 *)local_28,(undefined4 *)param_1,(uint)puVar2);
                  FUN_1002548b(local_3c,(int)local_30,pbVar3);
                }
              }
              local_8 = 0xffffffff;
              FUN_100241fc();
            }
            if (local_28 != pbVar3) {
              ExceptionList = local_14;
              return local_28;
            }
            if (DAT_10043944 == pbVar3) {
              ExceptionList = local_14;
              return local_28;
            }
            iVar1 = FUN_100258a5(param_2);
          } while (iVar1 != 0);
        }
        else {
          do {
            pbVar3 = (byte *)0x0;
            if (param_2 < (uint *)0xffffffe1) {
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              pbVar3 = HeapReAlloc(DAT_10043d20,0,param_1,(SIZE_T)param_2);
            }
            if (pbVar3 != (byte *)0x0) {
              ExceptionList = local_14;
              return pbVar3;
            }
            if (DAT_10043944 == (byte *)0x0) {
              ExceptionList = local_14;
              return (byte *)0x0;
            }
            iVar1 = FUN_100258a5(param_2);
          } while (iVar1 != 0);
        }
      }
    }
    pbVar3 = (byte *)0x0;
  }
  ExceptionList = local_14;
  return pbVar3;
}



/* VA 100240ae */

void FUN_100240ae(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 100241fc */

void FUN_100241fc(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 10024252 */

/* Library Function - Single Match
    __mbsnbicoll

   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;

  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = FUN_10027e7e(DAT_10044f84,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_10044d54);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}



/* VA 10024291 */

undefined4 FUN_10024291(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  uint *lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;

  lpWideCharStr = (LPCWSTR)*DAT_100438b4;
  puVar2 = DAT_100438b4;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (uint *)0x0)) ||
       (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*puVar2,-1,(LPSTR)lpMultiByteStr,_Size,(LPCSTR)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_10028126(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}



/* VA 100242ff */

uint __cdecl FUN_100242ff(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  byte bVar5;
  undefined3 extraout_var;
  undefined *puVar6;
  int *piVar7;

  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_1002440b:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_1002440b;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_1003db38 && (piVar4 != (int *)&DAT_1003db58)) ||
        (bVar5 = FUN_1002789e(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_1002836c(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_10025ea6(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_10040008;
        }
        else {
          puVar6 = (undefined *)((&DAT_10043c00)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_10026f7b(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_10025ea6(uVar2,pcVar3,(uint)piVar7);
      }
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
    if (param_2 == piVar7) {
      return param_1 & 0xff;
    }
    piVar4[3] = piVar4[3] | 0x20;
  }
  return 0xffffffff;
}



/* VA 10024417 */

void __cdecl FUN_10024417(undefined4 *param_1)

{
  int iVar1;
  HMODULE pHVar2;

  *param_1 = 0;
  pHVar2 = GetModuleHandleA((LPCSTR)0x0);
  if (((short)pHVar2->unused == 0x5a4d) && (iVar1 = pHVar2[0xf].unused, iVar1 != 0)) {
    *(undefined1 *)param_1 = *(undefined1 *)((int)&pHVar2[6].unused + iVar1 + 2);
    *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)&pHVar2[6].unused + iVar1 + 3);
  }
  return;
}



/* VA 10024444 */

int FUN_10024444(void)

{
  char cVar1;
  byte bVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  byte *this;
  byte unaff_BL;
  char local_1230 [4240];
  char local_1a0 [260];
  DWORD local_9c;
  uint local_98;
  DWORD local_8c;
  CHAR aCStackY_18 [4];

  FUN_1001fa90();
  local_9c = 0x94;
  BVar3 = GetVersionExA((LPOSVERSIONINFOA)&local_9c);
  if (((BVar3 == 0) || (local_8c != 2)) || (local_98 < 5)) {
    aCStackY_18[0] = -0x62;
    aCStackY_18[1] = 'D';
    aCStackY_18[2] = '\x02';
    aCStackY_18[3] = '\x10';
    DVar4 = GetEnvironmentVariableA("__MSVCRT_HEAP_SELECT",local_1230,0x1090);
    if (DVar4 != 0) {
      pcVar7 = local_1230;
      while (local_1230[0] != '\0') {
        cVar1 = *pcVar7;
        if (('`' < cVar1) && (cVar1 < '{')) {
          *pcVar7 = cVar1 + -0x20;
        }
        pcVar7 = pcVar7 + 1;
        local_1230[0] = *pcVar7;
      }
      aCStackY_18[0] = -0x24;
      aCStackY_18[1] = 'D';
      aCStackY_18[2] = '\x02';
      aCStackY_18[3] = '\x10';
      iVar5 = _strncmp("__GLOBAL_HEAP_SELECTED",local_1230,0x16);
      if (iVar5 == 0) {
        pcVar7 = local_1230;
      }
      else {
        aCStackY_18[0] = -2;
        aCStackY_18[1] = 'D';
        aCStackY_18[2] = '\x02';
        aCStackY_18[3] = '\x10';
        GetModuleFileNameA((HMODULE)0x0,local_1a0,0x104);
        pcVar7 = local_1a0;
        while (local_1a0[0] != '\0') {
          cVar1 = *pcVar7;
          if (('`' < cVar1) && (cVar1 < '{')) {
            *pcVar7 = cVar1 + -0x20;
          }
          pcVar7 = pcVar7 + 1;
          local_1a0[0] = *pcVar7;
        }
        pcVar7 = _strstr(local_1230,local_1a0);
      }
      if ((pcVar7 != (char *)0x0) && (pcVar7 = _strchr(pcVar7,0x2c), pcVar7 != (char *)0x0)) {
        pbVar6 = (byte *)(pcVar7 + 1);
        bVar2 = *pbVar6;
        this = pbVar6;
        while (bVar2 != 0) {
          if (*this == 0x3b) {
            *this = 0;
          }
          else {
            this = this + 1;
          }
          bVar2 = *this;
        }
        builtin_memcpy(aCStackY_18,"dE\x02\x10",4);
        iVar5 = FUN_100283b0(this,pbVar6,(int *)0x0,(void *)0xa);
        if (iVar5 == 2) {
          return 2;
        }
        if (iVar5 == 3) {
          return 3;
        }
        if (iVar5 == 1) {
          return 1;
        }
      }
    }
    FUN_10024417((undefined4 *)&stack0xfffffff8);
    iVar5 = 3 - (uint)(unaff_BL < 6);
  }
  else {
    iVar5 = 1;
  }
  return iVar5;
}



/* VA 1002458c */

undefined4 __cdecl FUN_1002458c(int param_1)

{
  undefined **ppuVar1;

  DAT_10043d20 = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_10043d20 != (HANDLE)0x0) {
    DAT_10043d24 = FUN_10024444();
    if (DAT_10043d24 == 3) {
      ppuVar1 = (undefined **)FUN_10024691(0x3f8);
    }
    else {
      if (DAT_10043d24 != 2) {
        return 1;
      }
      ppuVar1 = FUN_100251d8();
    }
    if (ppuVar1 != (undefined **)0x0) {
      return 1;
    }
    HeapDestroy(DAT_10043d20);
  }
  return 0;
}



/* VA 100245e9 */

void FUN_100245e9(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined **ppuVar3;

  if (DAT_10043d24 == 3) {
    iVar1 = 0;
    if (0 < DAT_10043d14) {
      puVar2 = (undefined4 *)((int)DAT_10043d18 + 0xc);
      do {
        VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
        VirtualFree((LPVOID)*puVar2,0,0x8000);
        HeapFree(DAT_10043d20,0,(LPVOID)puVar2[1]);
        puVar2 = puVar2 + 5;
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_10043d14);
    }
    HeapFree(DAT_10043d20,0,DAT_10043d18);
  }
  else if (DAT_10043d24 == 2) {
    ppuVar3 = &PTR_LOOP_1003dda8;
    do {
      if (ppuVar3[4] != (undefined *)0x0) {
        VirtualFree(ppuVar3[4],0,0x8000);
      }
      ppuVar3 = (undefined **)*ppuVar3;
    } while (ppuVar3 != &PTR_LOOP_1003dda8);
  }
  HeapDestroy(DAT_10043d20);
  return;
}



/* VA 10024691 */

undefined4 __cdecl FUN_10024691(undefined4 param_1)

{
  DAT_10043d18 = HeapAlloc(DAT_10043d20,0,0x140);
  if (DAT_10043d18 == (LPVOID)0x0) {
    return 0;
  }
  DAT_10043d10 = 0;
  DAT_10043d14 = 0;
  DAT_10043d0c = DAT_10043d18;
  DAT_10043d1c = param_1;
  DAT_10043d04 = 0x10;
  return 1;
}



/* VA 100246d9 */

uint __cdecl FUN_100246d9(int param_1)

{
  uint uVar1;

  uVar1 = DAT_10043d18;
  while( true ) {
    if (DAT_10043d18 + DAT_10043d14 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}



/* VA 10024704 */

void __cdecl FUN_10024704(uint *param_1,int param_2)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_8;

  uVar5 = param_1[4];
  puVar12 = (uint *)(param_2 + -4);
  uVar14 = param_2 - param_1[3] >> 0xf;
  piVar3 = (int *)(uVar14 * 0x204 + 0x144 + uVar5);
  uVar13 = *puVar12;
  local_8 = uVar13 - 1;
  if ((local_8 & 1) == 0) {
    uVar6 = *(uint *)(local_8 + (int)puVar12);
    uVar7 = *(uint *)(param_2 + -8);
    if ((uVar6 & 1) == 0) {
      uVar9 = ((int)uVar6 >> 4) - 1;
      if (0x3f < uVar9) {
        uVar9 = 0x3f;
      }
      if (*(int *)((int)puVar12 + uVar13 + 3) == *(int *)((int)puVar12 + uVar13 + 7)) {
        if (uVar9 < 0x20) {
          pcVar1 = (char *)(uVar9 + 4 + uVar5);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 & 0x1f));
          puVar10 = (uint *)(uVar5 + 0x44 + uVar14 * 4);
          *puVar10 = *puVar10 & uVar9;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar9;
          }
        }
        else {
          pcVar1 = (char *)(uVar9 + 4 + uVar5);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 - 0x20 & 0x1f));
          puVar10 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);
          *puVar10 = *puVar10 & uVar9;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar9;
          }
        }
      }
      local_8 = local_8 + uVar6;
      *(undefined4 *)(*(int *)((int)puVar12 + uVar13 + 7) + 4) =
           *(undefined4 *)((int)puVar12 + uVar13 + 3);
      *(undefined4 *)(*(int *)((int)puVar12 + uVar13 + 3) + 8) =
           *(undefined4 *)((int)puVar12 + uVar13 + 7);
    }
    puVar10 = (uint *)(((int)local_8 >> 4) - 1);
    if ((uint *)0x3f < puVar10) {
      puVar10 = (uint *)0x3f;
    }
    puVar11 = param_1;
    if ((uVar7 & 1) == 0) {
      puVar12 = (uint *)((int)puVar12 - uVar7);
      puVar11 = (uint *)(((int)uVar7 >> 4) - 1);
      if ((uint *)0x3f < puVar11) {
        puVar11 = (uint *)0x3f;
      }
      local_8 = local_8 + uVar7;
      puVar10 = (uint *)(((int)local_8 >> 4) - 1);
      if ((uint *)0x3f < puVar10) {
        puVar10 = (uint *)0x3f;
      }
      if (puVar11 != puVar10) {
        if (puVar12[1] == puVar12[2]) {
          if (puVar11 < (uint *)0x20) {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 & 0x1f));
            puVar2 = (uint *)(uVar5 + 0x44 + uVar14 * 4);
            *puVar2 = *puVar2 & uVar13;
            pcVar1 = (char *)((int)puVar11 + uVar5 + 4);
            *pcVar1 = *pcVar1 + -1;
            if (*pcVar1 == '\0') {
              *param_1 = *param_1 & uVar13;
            }
          }
          else {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 - 0x20 & 0x1f));
            puVar2 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);
            *puVar2 = *puVar2 & uVar13;
            pcVar1 = (char *)((int)puVar11 + uVar5 + 4);
            *pcVar1 = *pcVar1 + -1;
            if (*pcVar1 == '\0') {
              param_1[1] = param_1[1] & uVar13;
            }
          }
        }
        *(uint *)(puVar12[2] + 4) = puVar12[1];
        *(uint *)(puVar12[1] + 8) = puVar12[2];
      }
    }
    if (((uVar7 & 1) != 0) || (puVar11 != puVar10)) {
      puVar12[1] = piVar3[(int)puVar10 * 2 + 1];
      puVar12[2] = (uint)(piVar3 + (int)puVar10 * 2);
      (piVar3 + (int)puVar10 * 2)[1] = (int)puVar12;
      *(uint **)(puVar12[1] + 8) = puVar12;
      if (puVar12[1] == puVar12[2]) {
        cVar4 = *(char *)((int)puVar10 + uVar5 + 4);
        *(char *)((int)puVar10 + uVar5 + 4) = cVar4 + '\x01';
        bVar8 = (byte)puVar10;
        if (puVar10 < (uint *)0x20) {
          if (cVar4 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar10 = (uint *)(uVar5 + 0x44 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 & 0x1f);
        }
        else {
          if (cVar4 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar10 = (uint *)(uVar5 + 0xc4 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
      }
    }
    *puVar12 = local_8;
    *(uint *)((local_8 - 4) + (int)puVar12) = local_8;
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      if (DAT_10043d10 != (uint *)0x0) {
        VirtualFree((LPVOID)(DAT_10043d08 * 0x8000 + DAT_10043d10[3]),0x8000,0x4000);
        DAT_10043d10[2] = DAT_10043d10[2] | 0x80000000U >> ((byte)DAT_10043d08 & 0x1f);
        *(undefined4 *)(DAT_10043d10[4] + 0xc4 + DAT_10043d08 * 4) = 0;
        *(char *)(DAT_10043d10[4] + 0x43) = *(char *)(DAT_10043d10[4] + 0x43) + -1;
        if (*(char *)(DAT_10043d10[4] + 0x43) == '\0') {
          DAT_10043d10[1] = DAT_10043d10[1] & 0xfffffffe;
        }
        if (DAT_10043d10[2] == 0xffffffff) {
          VirtualFree((LPVOID)DAT_10043d10[3],0,0x8000);
          HeapFree(DAT_10043d20,0,(LPVOID)DAT_10043d10[4]);
          FUN_10020590(DAT_10043d10,DAT_10043d10 + 5,
                       (DAT_10043d14 * 0x14 - (int)DAT_10043d10) + -0x14 + DAT_10043d18);
          DAT_10043d14 = DAT_10043d14 + -1;
          if (DAT_10043d10 < param_1) {
            param_1 = param_1 + -5;
          }
          DAT_10043d0c = DAT_10043d18;
        }
      }
      DAT_10043d10 = param_1;
      DAT_10043d08 = uVar14;
    }
  }
  return;
}



/* VA 10024a2d */

int * __cdecl FUN_10024a2d(uint *param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint local_10;
  uint local_c;
  int local_8;

  puVar8 = DAT_10043d18 + DAT_10043d14 * 5;
  uVar6 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar7 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  bVar5 = (byte)iVar7;
  param_1 = DAT_10043d0c;
  if (iVar7 < 0x20) {
    local_10 = 0xffffffff >> (bVar5 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    local_c = 0xffffffff >> (bVar5 - 0x20 & 0x1f);
    local_10 = 0;
  }
  for (; (param_1 < puVar8 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  puVar11 = DAT_10043d18;
  if (param_1 == puVar8) {
    for (; (puVar11 < DAT_10043d0c && ((puVar11[1] & local_c) == 0 && (*puVar11 & local_10) == 0));
        puVar11 = puVar11 + 5) {
    }
    param_1 = puVar11;
    if (puVar11 == DAT_10043d0c) {
      for (; (puVar11 < puVar8 && (puVar11[2] == 0)); puVar11 = puVar11 + 5) {
      }
      puVar12 = DAT_10043d18;
      param_1 = puVar11;
      if (puVar11 == puVar8) {
        for (; (puVar12 < DAT_10043d0c && (puVar12[2] == 0)); puVar12 = puVar12 + 5) {
        }
        param_1 = puVar12;
        if ((puVar12 == DAT_10043d0c) && (param_1 = FUN_10024d36(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar7 = FUN_10024de7((int)param_1);
      *(int *)param_1[4] = iVar7;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar4 = (int *)param_1[4];
  local_8 = *piVar4;
  if ((local_8 == -1) ||
     ((piVar4[local_8 + 0x31] & local_c) == 0 && (piVar4[local_8 + 0x11] & local_10) == 0)) {
    local_8 = 0;
    puVar8 = (uint *)(piVar4 + 0x11);
    if ((piVar4[0x31] & local_c) == 0 && (piVar4[0x11] & local_10) == 0) {
      do {
        puVar11 = puVar8 + 0x21;
        local_8 = local_8 + 1;
        puVar8 = puVar8 + 1;
      } while ((*puVar11 & local_c) == 0 && (local_10 & *puVar8) == 0);
    }
  }
  iVar7 = 0;
  piVar2 = piVar4 + local_8 * 0x81 + 0x51;
  local_10 = piVar4[local_8 + 0x11] & local_10;
  if (local_10 == 0) {
    local_10 = piVar4[local_8 + 0x31] & local_c;
    iVar7 = 0x20;
  }
  for (; -1 < (int)local_10; local_10 = local_10 << 1) {
    iVar7 = iVar7 + 1;
  }
  piVar10 = (int *)piVar2[iVar7 * 2 + 1];
  iVar9 = *piVar10 - uVar6;
  iVar14 = (iVar9 >> 4) + -1;
  if (0x3f < iVar14) {
    iVar14 = 0x3f;
  }
  DAT_10043d0c = param_1;
  if (iVar14 != iVar7) {
    if (piVar10[1] == piVar10[2]) {
      if (iVar7 < 0x20) {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 & 0x1f));
        piVar4[local_8 + 0x11] = uVar13 & piVar4[local_8 + 0x11];
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar13;
        }
      }
      else {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 - 0x20 & 0x1f));
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] & uVar13;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar13;
        }
      }
    }
    *(int *)(piVar10[2] + 4) = piVar10[1];
    *(int *)(piVar10[1] + 8) = piVar10[2];
    if (iVar9 == 0) goto LAB_10024cf3;
    piVar10[1] = piVar2[iVar14 * 2 + 1];
    piVar10[2] = (int)(piVar2 + iVar14 * 2);
    (piVar2 + iVar14 * 2)[1] = (int)piVar10;
    *(int **)(piVar10[1] + 8) = piVar10;
    if (piVar10[1] == piVar10[2]) {
      cVar3 = *(char *)(iVar14 + 4 + (int)piVar4);
      bVar5 = (byte)iVar14;
      if (iVar14 < 0x20) {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar5 & 0x1f);
        }
        piVar4[local_8 + 0x11] = piVar4[local_8 + 0x11] | 0x80000000U >> (bVar5 & 0x1f);
      }
      else {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
        }
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar9 != 0) {
    *piVar10 = iVar9;
    *(int *)(iVar9 + -4 + (int)piVar10) = iVar9;
  }
LAB_10024cf3:
  piVar10 = (int *)((int)piVar10 + iVar9);
  *piVar10 = uVar6 + 1;
  *(uint *)((int)piVar10 + (uVar6 - 4)) = uVar6 + 1;
  iVar7 = *piVar2;
  *piVar2 = iVar7 + 1;
  if (((iVar7 == 0) && (param_1 == DAT_10043d10)) && (local_8 == DAT_10043d08)) {
    DAT_10043d10 = (uint *)0x0;
  }
  *piVar4 = local_8;
  return piVar10 + 1;
}



/* VA 10024d36 */

undefined4 * FUN_10024d36(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;

  if (DAT_10043d14 == DAT_10043d04) {
    pvVar2 = HeapReAlloc(DAT_10043d20,0,DAT_10043d18,(DAT_10043d04 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_10043d04 = DAT_10043d04 + 0x10;
    DAT_10043d18 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_10043d18 + DAT_10043d14 * 0x14);
  pvVar2 = HeapAlloc(DAT_10043d20,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_10043d14 = DAT_10043d14 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_10043d20,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}



/* VA 10024de7 */

int __cdecl FUN_10024de7(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  LPVOID pvVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *lpAddress;

  iVar3 = *(int *)(param_1 + 0x10);
  iVar9 = 0;
  for (iVar4 = *(int *)(param_1 + 8); -1 < iVar4; iVar4 = iVar4 << 1) {
    iVar9 = iVar9 + 1;
  }
  iVar8 = 0x3f;
  iVar4 = iVar9 * 0x204 + 0x144 + iVar3;
  iVar5 = iVar4;
  do {
    *(int *)(iVar5 + 8) = iVar5;
    *(int *)(iVar5 + 4) = iVar5;
    iVar5 = iVar5 + 8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  lpAddress = (int *)(iVar9 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar6 == (LPVOID)0x0) {
    iVar9 = -1;
  }
  else {
    if (lpAddress <= lpAddress + 0x1c00) {
      piVar7 = lpAddress + 4;
      do {
        piVar7[-2] = -1;
        piVar7[0x3fb] = -1;
        piVar7[-1] = 0xff0;
        *piVar7 = (int)(piVar7 + 0x3ff);
        piVar7[1] = (int)(piVar7 + -0x401);
        piVar7[0x3fa] = 0xff0;
        piVar1 = piVar7 + 0x3fc;
        piVar7 = piVar7 + 0x400;
      } while (piVar1 <= lpAddress + 0x1c00);
    }
    *(int **)(iVar4 + 0x1fc) = lpAddress + 3;
    lpAddress[5] = iVar4 + 0x1f8;
    *(int **)(iVar4 + 0x200) = lpAddress + 0x1c03;
    lpAddress[0x1c04] = iVar4 + 0x1f8;
    *(undefined4 *)(iVar3 + 0x44 + iVar9 * 4) = 0;
    *(undefined4 *)(iVar3 + 0xc4 + iVar9 * 4) = 1;
    cVar2 = *(char *)(iVar3 + 0x43);
    *(char *)(iVar3 + 0x43) = cVar2 + '\x01';
    if (cVar2 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar9 & 0x1f));
  }
  return iVar9;
}



/* VA 10024ee2 */

undefined4 __cdecl FUN_10024ee2(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_c;

  uVar5 = param_1[4];
  uVar12 = param_3 + 0x17U & 0xfffffff0;
  uVar10 = param_2 - param_1[3] >> 0xf;
  iVar3 = uVar10 * 0x204 + 0x144 + uVar5;
  iVar6 = *(int *)(param_2 + -4);
  iVar9 = iVar6 + -1;
  uVar13 = *(uint *)(iVar6 + -5 + param_2);
  iVar6 = iVar6 + -5 + param_2;
  if (iVar9 < (int)uVar12) {
    if (((uVar13 & 1) != 0) || ((int)(uVar13 + iVar9) < (int)uVar12)) {
      return 0;
    }
    local_c = ((int)uVar13 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar7 = *puVar7 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar7 = *puVar7 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
    *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
    iVar6 = uVar13 + (iVar9 - uVar12);
    if (0 < iVar6) {
      uVar13 = (iVar6 >> 4) - 1;
      iVar9 = param_2 + -4 + uVar12;
      if (0x3f < uVar13) {
        uVar13 = 0x3f;
      }
      iVar3 = iVar3 + uVar13 * 8;
      *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iVar3 + 4);
      *(int *)(iVar9 + 8) = iVar3;
      *(int *)(iVar3 + 4) = iVar9;
      *(int *)(*(int *)(iVar9 + 4) + 8) = iVar9;
      if (*(int *)(iVar9 + 4) == *(int *)(iVar9 + 8)) {
        cVar4 = *(char *)(uVar13 + 4 + uVar5);
        *(char *)(uVar13 + 4 + uVar5) = cVar4 + '\x01';
        bVar8 = (byte)uVar13;
        if (uVar13 < 0x20) {
          if (cVar4 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        }
        else {
          if (cVar4 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          bVar8 = bVar8 - 0x20;
        }
        *puVar7 = *puVar7 | 0x80000000U >> (bVar8 & 0x1f);
      }
      piVar2 = (int *)(param_2 + -4 + uVar12);
      *piVar2 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar2) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar12 + 1;
    *(uint *)(param_2 + -8 + uVar12) = uVar12 + 1;
  }
  else if ((int)uVar12 < iVar9) {
    param_3 = iVar9 - uVar12;
    *(uint *)(param_2 + -4) = uVar12 + 1;
    piVar2 = (int *)(param_2 + -4 + uVar12);
    uVar11 = (param_3 >> 4) - 1;
    piVar2[-1] = uVar12 + 1;
    if (0x3f < uVar11) {
      uVar11 = 0x3f;
    }
    if ((uVar13 & 1) == 0) {
      uVar12 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
        if (uVar12 < 0x20) {
          pcVar1 = (char *)(uVar12 + 4 + uVar5);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar7 = *puVar7 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar12;
          }
        }
        else {
          pcVar1 = (char *)(uVar12 + 4 + uVar5);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar7 = *puVar7 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar12;
          }
        }
      }
      *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
      *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
      param_3 = param_3 + uVar13;
      uVar11 = (param_3 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
    }
    iVar6 = iVar3 + uVar11 * 8;
    piVar2[1] = *(int *)(iVar3 + 4 + uVar11 * 8);
    piVar2[2] = iVar6;
    *(int **)(iVar6 + 4) = piVar2;
    *(int **)(piVar2[1] + 8) = piVar2;
    if (piVar2[1] == piVar2[2]) {
      cVar4 = *(char *)(uVar11 + 4 + uVar5);
      *(char *)(uVar11 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar11;
      if (uVar11 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        bVar8 = bVar8 - 0x20;
      }
      *puVar7 = *puVar7 | 0x80000000U >> (bVar8 & 0x1f);
    }
    *piVar2 = param_3;
    *(int *)(param_3 + -4 + (int)piVar2) = param_3;
  }
  return 1;
}



/* VA 100251d8 */

undefined ** FUN_100251d8(void)

{
  bool bVar1;
  int *lpAddress;
  LPVOID pvVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined **lpMem;

  if (DAT_1003ddb8 == -1) {
    lpMem = &PTR_LOOP_1003dda8;
  }
  else {
    lpMem = HeapAlloc(DAT_10043d20,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (int *)0x0) {
    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar2 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_1003dda8) {
        if (PTR_LOOP_1003dda8 == (undefined *)0x0) {
          PTR_LOOP_1003dda8 = (undefined *)&PTR_LOOP_1003dda8;
        }
        if (PTR_LOOP_1003ddac == (undefined *)0x0) {
          PTR_LOOP_1003ddac = (undefined *)&PTR_LOOP_1003dda8;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_1003dda8;
        lpMem[1] = PTR_LOOP_1003ddac;
        PTR_LOOP_1003ddac = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[5] = (undefined *)(lpAddress + 0x100000);
      ppuVar3 = lpMem + 6;
      lpMem[3] = (undefined *)(lpMem + 0x26);
      lpMem[4] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)ppuVar3;
      iVar4 = 0;
      do {
        bVar1 = 0xf < iVar4;
        iVar4 = iVar4 + 1;
        *ppuVar3 = (undefined *)((bVar1 - 1 & 0xf1) - 1);
        ppuVar3[1] = (undefined *)0xf1;
        ppuVar3 = ppuVar3 + 2;
      } while (iVar4 < 0x400);
      _memset(lpAddress,0,0x10000);
      for (; lpAddress < lpMem[4] + 0x10000; lpAddress = lpAddress + 0x400) {
        *(undefined1 *)(lpAddress + 0x3e) = 0xff;
        *lpAddress = (int)(lpAddress + 2);
        lpAddress[1] = 0xf0;
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &PTR_LOOP_1003dda8) {
    HeapFree(DAT_10043d20,0,lpMem);
  }
  return (undefined **)0x0;
}



/* VA 1002531c */

void __cdecl FUN_1002531c(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_1003fdc8 == param_1) {
    PTR_LOOP_1003fdc8 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_1003dda8) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_10043d20,0,param_1);
    return;
  }
  DAT_1003ddb8 = 0xffffffff;
  return;
}



/* VA 10025372 */

void __cdecl FUN_10025372(int param_1)

{
  BOOL BVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  int local_8;

  ppuVar4 = (undefined **)PTR_LOOP_1003ddac;
  do {
    ppuVar5 = ppuVar4;
    if (ppuVar4[4] != (undefined *)0xffffffff) {
      local_8 = 0;
      ppuVar5 = ppuVar4 + 0x804;
      iVar3 = 0x3ff000;
      do {
        if (*ppuVar5 == (undefined *)0xf0) {
          BVar1 = VirtualFree(ppuVar4[4] + iVar3,0x1000,0x4000);
          if (BVar1 != 0) {
            *ppuVar5 = (undefined *)0xffffffff;
            DAT_10043940 = DAT_10043940 + -1;
            if (((undefined **)ppuVar4[3] == (undefined **)0x0) || (ppuVar5 < ppuVar4[3])) {
              ppuVar4[3] = (undefined *)ppuVar5;
            }
            local_8 = local_8 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar3 = iVar3 + -0x1000;
        ppuVar5 = ppuVar5 + -2;
      } while (-1 < iVar3);
      ppuVar5 = (undefined **)ppuVar4[1];
      if ((local_8 != 0) && (ppuVar4[6] == (undefined *)0xffffffff)) {
        ppuVar2 = ppuVar4 + 8;
        iVar3 = 1;
        do {
          if (*ppuVar2 != (undefined *)0xffffffff) break;
          iVar3 = iVar3 + 1;
          ppuVar2 = ppuVar2 + 2;
        } while (iVar3 < 0x400);
        if (iVar3 == 0x400) {
          FUN_1002531c(ppuVar4);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_1003ddac) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}



/* VA 10025434 */

int __cdecl FUN_10025434(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined **ppuVar1;
  uint uVar2;

  ppuVar1 = &PTR_LOOP_1003dda8;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &PTR_LOOP_1003dda8) {
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



/* VA 1002548b */

void __cdecl FUN_1002548b(int param_1,int param_2,byte *param_3)

{
  int *piVar1;

  piVar1 = (int *)(param_1 + 0x18 + (param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  *piVar1 = *piVar1 + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_10043940 = DAT_10043940 + 1, DAT_10043940 == 0x20)) {
    FUN_10025372(0x10);
  }
  return;
}



/* VA 100254d0 */

/* WARNING: Type propagation algorithm not settling */

int * __cdecl FUN_100254d0(uint param_1)

{
  uint *puVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  undefined **ppuVar6;
  int *piVar7;
  uint *puVar8;
  undefined **ppuVar9;
  int local_8;

  piVar7 = (int *)PTR_LOOP_1003fdc8;
  do {
    if (piVar7[4] != -1) {
      puVar8 = (uint *)piVar7[2];
      piVar4 = (int *)(((int)puVar8 + (-0x18 - (int)piVar7) >> 3) * 0x1000 + piVar7[4]);
      if (puVar8 < piVar7 + 0x806) {
        do {
          if (((int)param_1 <= (int)*puVar8) && (param_1 < puVar8[1])) {
            piVar5 = (int *)FUN_100256d8(piVar4,*puVar8,param_1);
            if (piVar5 != (int *)0x0) goto LAB_1002559b;
            puVar8[1] = param_1;
          }
          puVar8 = puVar8 + 2;
          piVar4 = piVar4 + 0x400;
        } while (puVar8 < piVar7 + 0x806);
      }
      puVar1 = (uint *)piVar7[2];
      piVar4 = (int *)piVar7[4];
      for (puVar8 = (uint *)(piVar7 + 6); puVar8 < puVar1; puVar8 = puVar8 + 2) {
        if (((int)param_1 <= (int)*puVar8) && (param_1 < puVar8[1])) {
          piVar5 = (int *)FUN_100256d8(piVar4,*puVar8,param_1);
          if (piVar5 != (int *)0x0) {
LAB_1002559b:
            PTR_LOOP_1003fdc8 = (undefined *)piVar7;
            *puVar8 = *puVar8 - param_1;
            piVar7[2] = (int)puVar8;
            return piVar5;
          }
          puVar8[1] = param_1;
        }
        piVar4 = piVar4 + 0x400;
      }
    }
    piVar7 = (int *)*piVar7;
    if (piVar7 == (int *)PTR_LOOP_1003fdc8) {
      ppuVar9 = &PTR_LOOP_1003dda8;
      while ((ppuVar9[4] == (undefined *)0xffffffff || (ppuVar9[3] == (undefined *)0x0))) {
        ppuVar9 = (undefined **)*ppuVar9;
        if (ppuVar9 == &PTR_LOOP_1003dda8) {
          ppuVar9 = FUN_100251d8();
          if (ppuVar9 == (undefined **)0x0) {
            return (int *)0x0;
          }
          piVar7 = (int *)ppuVar9[4];
          *(char *)(piVar7 + 2) = (char)param_1;
          PTR_LOOP_1003fdc8 = (undefined *)ppuVar9;
          *piVar7 = (int)piVar7 + param_1 + 8;
          piVar7[1] = 0xf0 - param_1;
          ppuVar9[6] = ppuVar9[6] + -(param_1 & 0xff);
          return piVar7 + 0x40;
        }
      }
      ppuVar2 = (undefined **)ppuVar9[3];
      local_8 = 0;
      piVar7 = (int *)(ppuVar9[4] + ((int)ppuVar2 + (-0x18 - (int)ppuVar9) >> 3) * 0x1000);
      puVar3 = *ppuVar2;
      ppuVar6 = ppuVar2;
      for (; (puVar3 == (undefined *)0xffffffff && (local_8 < 0x10)); local_8 = local_8 + 1) {
        ppuVar6 = ppuVar6 + 2;
        puVar3 = *ppuVar6;
      }
      piVar4 = VirtualAlloc(piVar7,local_8 << 0xc,0x1000,4);
      if (piVar4 != piVar7) {
        return (int *)0x0;
      }
      _memset(piVar7,local_8 << 0xc,0);
      ppuVar6 = ppuVar2;
      if (0 < local_8) {
        piVar4 = piVar7 + 1;
        do {
          *(undefined1 *)(piVar4 + 0x3d) = 0xff;
          piVar4[-1] = (int)(piVar4 + 1);
          *piVar4 = 0xf0;
          *ppuVar6 = (undefined *)0xf0;
          ppuVar6[1] = (undefined *)0xf1;
          piVar4 = piVar4 + 0x400;
          ppuVar6 = ppuVar6 + 2;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      for (; (ppuVar6 < ppuVar9 + 0x806 && (*ppuVar6 != (undefined *)0xffffffff));
          ppuVar6 = ppuVar6 + 2) {
      }
      PTR_LOOP_1003fdc8 = (undefined *)ppuVar9;
      ppuVar9[3] = (undefined *)(-(uint)(ppuVar6 < ppuVar9 + 0x806) & (uint)ppuVar6);
      *(char *)(piVar7 + 2) = (char)param_1;
      ppuVar9[2] = (undefined *)ppuVar2;
      *ppuVar2 = *ppuVar2 + -param_1;
      piVar7[1] = piVar7[1] - param_1;
      *piVar7 = (int)piVar7 + param_1 + 8;
      return piVar7 + 0x40;
    }
  } while( true );
}



/* VA 100256d8 */

int __cdecl FUN_100256d8(int *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;

  pbVar2 = (byte *)*param_1;
  pbVar1 = (byte *)(param_1 + 0x3e);
  bVar3 = (byte)param_3;
  if ((uint)param_1[1] < param_3) {
    pbVar6 = pbVar2;
    if (pbVar2[param_1[1]] != 0) {
      pbVar6 = pbVar2 + param_1[1];
    }
    while( true ) {
      while( true ) {
        if (pbVar1 <= pbVar6 + param_3) {
          pbVar6 = (byte *)(param_1 + 2);
          while( true ) {
            while( true ) {
              if (pbVar2 <= pbVar6) {
                return 0;
              }
              if (pbVar1 <= pbVar6 + param_3) {
                return 0;
              }
              if (*pbVar6 == 0) break;
              pbVar6 = pbVar6 + *pbVar6;
            }
            uVar5 = 1;
            pbVar4 = pbVar6;
            while (pbVar4 = pbVar4 + 1, *pbVar4 == 0) {
              uVar5 = uVar5 + 1;
            }
            if (param_3 <= uVar5) break;
            param_2 = param_2 - uVar5;
            pbVar6 = pbVar4;
            if (param_2 < param_3) {
              return 0;
            }
          }
          if (pbVar6 + param_3 < pbVar1) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            param_1[1] = 0;
            *param_1 = (int)(param_1 + 2);
          }
          *pbVar6 = bVar3;
          pbVar2 = pbVar6 + 8;
          goto LAB_100257eb;
        }
        if (*pbVar6 == 0) break;
        pbVar6 = pbVar6 + *pbVar6;
      }
      uVar5 = 1;
      pbVar4 = pbVar6;
      while (pbVar4 = pbVar4 + 1, *pbVar4 == 0) {
        uVar5 = uVar5 + 1;
      }
      if (param_3 <= uVar5) break;
      if (pbVar6 == pbVar2) {
        param_1[1] = uVar5;
        pbVar6 = pbVar4;
      }
      else {
        param_2 = param_2 - uVar5;
        pbVar6 = pbVar4;
        if (param_2 < param_3) {
          return 0;
        }
      }
    }
    if (pbVar6 + param_3 < pbVar1) {
      *param_1 = (int)(pbVar6 + param_3);
      param_1[1] = uVar5 - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    *pbVar6 = bVar3;
    pbVar2 = pbVar6 + 8;
  }
  else {
    *pbVar2 = bVar3;
    if (pbVar2 + param_3 < pbVar1) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    pbVar2 = pbVar2 + 8;
  }
LAB_100257eb:
  return (int)pbVar2 * 0x10 + (int)param_1 * -0xf;
}



/* VA 100257fc */

undefined4 __cdecl FUN_100257fc(int param_1,int *param_2,byte *param_3,uint param_4)

{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;

  uVar6 = (uint)*param_3;
  piVar2 = (int *)(param_1 + 0x18 + ((int)param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  if (param_4 < uVar6) {
    *param_3 = (byte)param_4;
    *piVar2 = *piVar2 + (uVar6 - param_4);
    piVar2[1] = 0xf1;
  }
  else {
    if (param_4 <= uVar6) {
      return 0;
    }
    pbVar1 = param_3 + param_4;
    if (param_2 + 0x3e < pbVar1) {
      return 0;
    }
    for (pbVar4 = param_3 + uVar6; (pbVar4 < pbVar1 && (*pbVar4 == 0)); pbVar4 = pbVar4 + 1) {
    }
    if (pbVar4 != pbVar1) {
      return 0;
    }
    *param_3 = (byte)param_4;
    if ((param_3 <= (byte *)*param_2) && ((byte *)*param_2 < pbVar1)) {
      if (pbVar1 < param_2 + 0x3e) {
        iVar5 = 0;
        *param_2 = (int)pbVar1;
        bVar3 = *pbVar1;
        while (bVar3 == 0) {
          iVar5 = iVar5 + 1;
          bVar3 = pbVar1[iVar5];
        }
        param_2[1] = iVar5;
      }
      else {
        param_2[1] = 0;
        *param_2 = (int)(param_2 + 2);
      }
    }
    *piVar2 = *piVar2 + (uVar6 - param_4);
  }
  return 1;
}



/* VA 100258a5 */

undefined4 __cdecl FUN_100258a5(undefined4 param_1)

{
  int iVar1;

  if (DAT_10043948 != (code *)0x0) {
    iVar1 = (*DAT_10043948)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* VA 100258c0 */

uint __thiscall FUN_100258c0(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;

  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_1003fdd0 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_1003fdd0[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_10026b18(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}



/* VA 10025974 */

void __fastcall FUN_10025974(void *param_1)

{
  FUN_10028601(param_1,0x10000,0x30000);
  return;
}



/* VA 10025986 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10025986(void)

{
  if (_DAT_100353d8 < _DAT_100353e0 - (_DAT_100353e0 / _DAT_100353e8) * _DAT_100353e8) {
    return 1;
  }
  return 0;
}



/* VA 100259c4 */

void FUN_100259c4(void)

{
  HMODULE hModule;
  FARPROC pFVar1;

  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  FUN_10025986();
  return;
}



/* VA 100259ed */

void __cdecl FUN_100259ed(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *this;
  uint uVar3;
  undefined *puVar4;

  this = (undefined *)(int)*param_1;
  uVar3 = FUN_10027a75((uint)this);
  if (uVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_1003ffdc < 2) {
        uVar3 = (byte)PTR_DAT_1003fdd0[*param_1 * 2] & 4;
        this = PTR_DAT_1003fdd0;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = FUN_100258c0(this,(int)*param_1,4);
        this = puVar4;
      }
    } while (uVar3 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_1003ffe0;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}



/* VA 10025aad */

/* Library Function - Single Match
    __fassign

   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  void *in_ECX;
  void *local_c;
  void *local_8;

  if (flag != 0) {
    local_c = in_ECX;
    local_8 = in_ECX;
    FUN_10028ac4(in_ECX,(uint *)&local_c,(byte *)number);
    *(void **)argument = local_c;
    *(void **)(argument + 4) = local_8;
    return;
  }
  FUN_10028af1(in_ECX,(uint *)&number,(byte *)number);
  *(char **)argument = number;
  return;
}



/* VA 10025aeb */

undefined1 * __cdecl FUN_10025aeb(undefined8 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint local_2c [6];
  int local_14 [4];

  FUN_10028b95((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),local_14,local_2c);
  FUN_10028b1e(param_2 + (uint)(0 < param_3) + (uint)(local_14[0] == 0x2d),param_3 + 1,(int)local_14
              );
  FUN_10025b4c(param_2,param_3,param_4,local_14,'\0');
  return param_2;
}



/* VA 10025b4c */

undefined1 * __cdecl
FUN_10025b4c(undefined1 *param_1,int param_2,int param_3,int *param_4,char param_5)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint *puVar3;
  int iVar4;

  if (param_5 != '\0') {
    FUN_10025dee(param_1 + (*param_4 == 0x2d),(uint)(0 < param_2));
  }
  puVar1 = param_1;
  if (*param_4 == 0x2d) {
    *param_1 = 0x2d;
    puVar1 = param_1 + 1;
  }
  puVar2 = puVar1;
  if (0 < param_2) {
    puVar2 = puVar1 + 1;
    *puVar1 = puVar1[1];
    *puVar2 = DAT_1003ffe0;
  }
  puVar3 = FUN_1001f150((uint *)(puVar2 + param_2 + (uint)(param_5 == '\0')),(uint *)"e+000");
  if (param_3 != 0) {
    *(undefined1 *)puVar3 = 0x45;
  }
  if (*(char *)param_4[3] != '0') {
    iVar4 = param_4[1] + -1;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      *(undefined1 *)((int)puVar3 + 1) = 0x2d;
    }
    if (99 < iVar4) {
      *(char *)((int)puVar3 + 2) = *(char *)((int)puVar3 + 2) + (char)(iVar4 / 100);
      iVar4 = iVar4 % 100;
    }
    if (9 < iVar4) {
      *(char *)((int)puVar3 + 3) = *(char *)((int)puVar3 + 3) + (char)(iVar4 / 10);
      iVar4 = iVar4 % 10;
    }
    *(char *)(puVar3 + 1) = (char)puVar3[1] + (char)iVar4;
  }
  return param_1;
}



/* VA 10025c0e */

char * __cdecl FUN_10025c0e(undefined8 *param_1,char *param_2,size_t param_3)

{
  uint local_2c [6];
  int local_14;
  int local_10;

  FUN_10028b95((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  FUN_10028b1e(param_2 + (local_14 == 0x2d),local_10 + param_3,(int)&local_14);
  FUN_10025c63(param_2,param_3,&local_14,'\0');
  return param_2;
}



/* VA 10025c63 */

char * __cdecl FUN_10025c63(char *param_1,size_t param_2,int *param_3,char param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;

  iVar1 = param_3[1];
  if ((param_4 != '\0') && (iVar1 - 1U == param_2)) {
    iVar2 = *param_3;
    param_1[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = '0';
    (param_1 + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = '\0';
  }
  pcVar3 = param_1;
  if (*param_3 == 0x2d) {
    *param_1 = '-';
    pcVar3 = param_1 + 1;
  }
  if (param_3[1] < 1) {
    FUN_10025dee(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + param_3[1];
  }
  if (0 < (int)param_2) {
    FUN_10025dee(pcVar3,1);
    *pcVar3 = DAT_1003ffe0;
    iVar1 = param_3[1];
    if (iVar1 < 0) {
      if ((param_4 != '\0') || (-iVar1 <= (int)param_2)) {
        param_2 = -iVar1;
      }
      FUN_10025dee(pcVar3 + 1,param_2);
      _memset(pcVar3 + 1,0x30,param_2);
    }
  }
  return param_1;
}



/* VA 10025d0a */

void __cdecl FUN_10025d0a(undefined8 *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint local_2c [6];
  int local_14;
  int local_10;

  FUN_10028b95((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  iVar1 = local_10 + -1;
  FUN_10028b1e(param_2 + (local_14 == 0x2d),param_3,(int)&local_14);
  local_10 = local_10 + -1;
  if ((local_10 < -4) || ((int)param_3 <= local_10)) {
    FUN_10025b4c(param_2,param_3,param_4,&local_14,'\x01');
  }
  else {
    pcVar2 = param_2 + (local_14 == 0x2d);
    if (iVar1 < local_10) {
      do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    FUN_10025c63(param_2,param_3,&local_14,'\x01');
  }
  return;
}



/* VA 10025d9d */

/* Library Function - Single Match
    __cfltcvt

   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *pcVar1;
  undefined1 *puVar2;

  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    puVar2 = FUN_10025aeb(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      pcVar1 = FUN_10025c0e(arg,buffer,format);
      return (errno_t)pcVar1;
    }
    puVar2 = (undefined1 *)FUN_10025d0a(arg,buffer,format,precision);
  }
  return (errno_t)puVar2;
}



/* VA 10025dee */

void __cdecl FUN_10025dee(char *param_1,int param_2)

{
  size_t sVar1;

  if (param_2 != 0) {
    sVar1 = _strlen(param_1);
    FUN_10020590((undefined4 *)(param_1 + param_2),(undefined4 *)param_1,sVar1 + 1);
  }
  return;
}



/* VA 10025e13 */

undefined4 __cdecl FUN_10025e13(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;

  if (DAT_10043d00 <= param_1) {
LAB_10025e94:
    pDVar3 = FUN_10020fd2();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_10025e94;
  FUN_10020ede(param_1);
  if ((*(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_10020df5(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_10025e89;
    pDVar3 = FUN_10020fdb();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_10020fd2();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_10025e89:
  FUN_10020f3d(param_1);
  return uVar5;
}



/* VA 10025ea6 */

int __cdecl FUN_10025ea6(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_10043d00) &&
     ((*(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10020ede(param_1);
    iVar1 = FUN_10025f0b(param_1,param_2,param_3);
    FUN_10020f3d(param_1);
    return iVar1;
  }
  pDVar2 = FUN_10020fd2();
  *pDVar2 = 9;
  pDVar2 = FUN_10020fdb();
  *pDVar2 = 0;
  return -1;
}



/* VA 10025f0b */

int __cdecl FUN_10025f0b(DWORD param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  BOOL BVar6;
  DWORD *pDVar7;
  char local_418 [1028];
  int local_14;
  DWORD local_10;
  DWORD local_c;
  char *local_8;

  local_c = 0;
  local_14 = 0;
  if (param_3 == 0) {
LAB_10025f24:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_10043c00 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_10026fe0(param_1,0,2);
    }
    if ((*(byte *)((undefined4 *)(*piVar1 + iVar4) + 1) & 0x80) == 0) {
      BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),param_2,param_3,&local_10,(LPOVERLAPPED)0x0);
      if (BVar6 == 0) {
        param_1 = GetLastError();
      }
      else {
        local_c = local_10;
        param_1 = 0;
      }
LAB_10025ff3:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_10026065;
      if (param_1 == 5) {
        pDVar7 = FUN_10020fd2();
        *pDVar7 = 9;
        pDVar7 = FUN_10020fdb();
        *pDVar7 = 5;
      }
      else {
        FUN_10020f5f(param_1);
      }
    }
    else {
      local_8 = param_2;
      param_1 = 0;
      if (param_3 != 0) {
        do {
          pcVar5 = local_418;
          do {
            if (param_3 <= (uint)((int)local_8 - (int)param_2)) break;
            pcVar2 = local_8 + 1;
            cVar3 = *local_8;
            local_8 = pcVar2;
            if (cVar3 == '\n') {
              local_14 = local_14 + 1;
              *pcVar5 = '\r';
              pcVar5 = pcVar5 + 1;
            }
            *pcVar5 = cVar3;
            pcVar5 = pcVar5 + 1;
          } while ((int)pcVar5 - (int)local_418 < 0x400);
          BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),local_418,(int)pcVar5 - (int)local_418,
                            &local_10,(LPOVERLAPPED)0x0);
          if (BVar6 == 0) {
            param_1 = GetLastError();
            goto LAB_10025ff3;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_10025ff3;
        } while( true );
      }
LAB_10026065:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_10025f24;
      pDVar7 = FUN_10020fd2();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_10020fdb();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}



/* VA 10026096 */

void FUN_10026096(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  UINT *pUVar5;
  int iVar6;
  uint uVar7;
  UINT UVar8;
  UINT UVar9;
  _STARTUPINFOA local_4c;
  byte *local_8;

  puVar2 = _malloc(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_10043d00 = 0x20;
  DAT_10043c00 = puVar2;
  for (; puVar2 < DAT_10043c00 + 0x120; puVar2 = puVar2 + 9) {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = 0xffffffff;
    puVar2[2] = 0;
    *(undefined1 *)((int)puVar2 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    UVar8 = *(UINT *)local_4c.lpReserved2;
    pUVar5 = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_8 = (byte *)((int)pUVar5 + UVar8);
    if (0x7ff < (int)UVar8) {
      UVar8 = 0x800;
    }
    UVar9 = UVar8;
    if ((int)DAT_10043d00 < (int)UVar8) {
      puVar2 = &DAT_10043c04;
      do {
        puVar3 = _malloc(0x480);
        UVar9 = DAT_10043d00;
        if (puVar3 == (undefined4 *)0x0) break;
        DAT_10043d00 = DAT_10043d00 + 0x20;
        *puVar2 = puVar3;
        puVar1 = puVar3;
        for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
          *(undefined1 *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          puVar3[2] = 0;
          *(undefined1 *)((int)puVar3 + 5) = 10;
          puVar1 = (undefined4 *)*puVar2;
        }
        puVar2 = puVar2 + 1;
        UVar9 = UVar8;
      } while ((int)DAT_10043d00 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar9) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_10043c00)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
          *puVar2 = *(undefined4 *)local_8;
          *(byte *)(puVar2 + 1) = (byte)*pUVar5;
        }
        local_8 = local_8 + 4;
        uVar7 = uVar7 + 1;
        pUVar5 = (UINT *)((int)pUVar5 + 1);
      } while ((int)uVar7 < (int)UVar9);
    }
  }
  iVar6 = 0;
  do {
    puVar2 = DAT_10043c00 + iVar6 * 9;
    if (DAT_10043c00[iVar6 * 9] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *puVar2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 8;
          }
          goto LAB_1002623b;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_1002623b:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_10043d00);
      return;
    }
  } while( true );
}



/* VA 10026252 */

void FUN_10026252(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;

  puVar1 = &DAT_10043c00;
  do {
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      if (uVar2 < uVar2 + 0x480) {
        lpCriticalSection = (LPCRITICAL_SECTION)(uVar2 + 0xc);
        do {
          if (lpCriticalSection[-1].SpinCount != 0) {
            DeleteCriticalSection(lpCriticalSection);
          }
          uVar2 = uVar2 + 0x24;
          lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[1].OwningThread;
        } while (uVar2 < *puVar1 + 0x480);
      }
      FUN_1001fabf((undefined *)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x10043d00);
  return;
}



/* VA 100262a6 */

void FUN_100262a6(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;

  if (DAT_10044d48 == 0) {
    FUN_10021b7f();
  }
  iVar5 = 0;
  for (puVar6 = DAT_1004383c; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  DAT_100438ac = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_1004383c;
  puVar6 = DAT_1004383c;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_1001f150((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_1001fabf((undefined *)DAT_1004383c);
  DAT_1004383c = (uint *)0x0;
  *puVar3 = 0;
  DAT_10044d44 = 1;
  return;
}



/* VA 1002635f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002635f(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;

  if (DAT_10044d48 == 0) {
    FUN_10021b7f();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_1004394c,0x104);
  _DAT_100438bc = &DAT_1004394c;
  pbVar2 = &DAT_1004394c;
  if (*DAT_10044f88 != 0) {
    pbVar2 = DAT_10044f88;
  }
  FUN_100263f8(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_100263f8(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_100438a4 = puVar1;
  _DAT_100438a0 = local_8 + -1;
  return;
}



/* VA 100263f8 */

void __cdecl FUN_100263f8(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;

  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    while( true ) {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      if (((*(byte *)((int)&DAT_10044e80 + bVar1 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
        pbVar4 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      param_1 = pbVar4;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
      }
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar4 == 0x22) {
      pbVar4 = param_1 + 2;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar4 = param_1 + 1;
      if ((*(byte *)((int)&DAT_10044e80 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_100264a3;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_100264a3:
      pbVar4 = pbVar4 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar2 = false;
  puVar7 = param_2;
  while (*pbVar4 != 0) {
    for (; (*pbVar4 == 0x20 || (*pbVar4 == 9)); pbVar4 = pbVar4 + 1) {
    }
    if (*pbVar4 == 0) break;
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = param_3;
      puVar7 = puVar7 + 1;
      param_2 = puVar7;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar3 = true;
      uVar6 = 0;
      for (; *pbVar4 == 0x5c; pbVar4 = pbVar4 + 1) {
        uVar6 = uVar6 + 1;
      }
      if (*pbVar4 == 0x22) {
        pbVar5 = pbVar4;
        if ((uVar6 & 1) == 0) {
          if ((!bVar2) || (pbVar5 = pbVar4 + 1, pbVar4[1] != 0x22)) {
            bVar3 = false;
            pbVar5 = pbVar4;
          }
          bVar2 = !bVar2;
          puVar7 = param_2;
        }
        uVar6 = uVar6 >> 1;
        pbVar4 = pbVar5;
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar4;
      if ((bVar1 == 0) || ((!bVar2 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_10044e80 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_10044e80 + bVar1 + 1) & 4) != 0) {
            *param_3 = bVar1;
            param_3 = param_3 + 1;
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      pbVar4 = pbVar4 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



/* VA 100265ac */

LPSTR FUN_100265ac(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  size_t _Size;
  LPSTR pCVar6;
  char *pcVar7;
  LPWCH lpWideCharStr;
  LPCH pCVar9;
  LPSTR local_8;
  char *pcVar8;

  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_10043a50 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_10043a50 = 1;
LAB_10026603:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (LPSTR)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      local_8 = (LPSTR)0x0;
      if (((_Size != 0) && (pCVar6 = _malloc(_Size), pCVar6 != (LPSTR)0x0)) &&
         (iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar6,_Size,(LPCSTR)0x0,(LPBOOL)0x0),
         local_8 = pCVar6, iVar5 == 0)) {
        FUN_1001fabf(pCVar6);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_10043a50 = 2;
  }
  else {
    if (DAT_10043a50 == 1) goto LAB_10026603;
    if (DAT_10043a50 != 2) {
      return (LPSTR)0x0;
    }
  }
  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {
    return (LPSTR)0x0;
  }
  cVar1 = *pCVar9;
  pcVar7 = pCVar9;
  while (cVar1 != '\0') {
    do {
      pcVar8 = pcVar7;
      pcVar7 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar8 + 2;
    cVar1 = *pcVar7;
  }
  pCVar6 = _malloc((size_t)(pcVar7 + (1 - (int)pCVar9)));
  if (pCVar6 == (LPSTR)0x0) {
    pCVar6 = (LPSTR)0x0;
  }
  else {
    FUN_100200e0((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}



/* VA 100266de */

void FUN_100266de(void)

{
  if ((DAT_10043844 == 1) || ((DAT_10043844 == 0 && (DAT_10043848 == 1)))) {
    FUN_10026717(0xfc);
    if (DAT_10043a54 != (code *)0x0) {
      (*DAT_10043a54)();
    }
    FUN_10026717(0xff);
  }
  return;
}



/* VA 10026717 */

void __cdecl FUN_10026717(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  uint *_Dest;
  undefined1 auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_1a8 [65];
  uint local_a4 [40];

  iVar5 = 0;
  pDVar2 = &DAT_10040030;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x100400c0);
  if (param_1 == (&DAT_10040030)[iVar5 * 2]) {
    if ((DAT_10043844 == 1) || ((DAT_10043844 == 0 && (DAT_10043848 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x10040034);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_1001f150(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_1001f150(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_1001f160(local_a4,_Dest);
      FUN_1001f160(local_a4,(uint *)&DAT_100356dc);
      FUN_1001f160(local_a4,*(uint **)(iVar5 * 8 + 0x10040034));
      auStackY_1e3._3_4_ = 0x1002683b;
      FUN_10028cb0(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}



/* VA 10026880 */

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



/* VA 10026940 */

byte * __cdecl FUN_10026940(byte *param_1,byte *param_2)

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
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = param_1;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    param_1 = pbVar2 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return pbVar2;
}



/* VA 10026980 */

/* Library Function - Single Match
    __strrev

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl __strrev(char *_Str)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;

  iVar2 = -1;
  pcVar3 = _Str;
  do {
    pcVar4 = pcVar3;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar4;
  } while (cVar1 != '\0');
  if (iVar2 != -2) {
    pcVar4 = pcVar4 + -2;
    for (pcVar3 = _Str; pcVar3 < pcVar4; pcVar3 = pcVar3 + 1) {
      cVar1 = *pcVar3;
      *pcVar3 = *pcVar4;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + -1;
    }
  }
  return _Str;
}



/* VA 100269b0 */

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
LAB_10026a23:
        return _Str + -1;
      }
      if (*pcVar10 != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') goto LAB_10026a23;
      pcVar2 = pcVar10 + 1;
      pcVar8 = pcVar8 + 2;
      pcVar10 = pcVar10 + 2;
    } while (*pcVar1 == *pcVar2);
  } while( true );
}



/* VA 10026a30 */

int __cdecl FUN_10026a30(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
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
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar2;
    }
    param_1 = param_1 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) != 0);
  return iVar2;
}



/* VA 10026a70 */

int __cdecl FUN_10026a70(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
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
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar2;
    }
    param_1 = param_1 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return iVar2;
}



/* VA 10026ab0 */

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



/* VA 10026ae0 */

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



/* VA 10026b18 */

BOOL __cdecl
FUN_10026b18(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  undefined1 *puVar1;
  BOOL BVar2;
  int iVar3;
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_10035718;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_10043a58;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_10043a58 == 0) {
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    iVar3 = 1;
    puVar1 = local_1c;
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,"",1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  DAT_10043a58 = iVar3;
  if (DAT_10043a58 != 2) {
    if (DAT_10043a58 == 1) {
      if (param_5 == 0) {
        param_5 = DAT_10043a7c;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        FUN_1001fa90();
        local_1c = &stack0xffffffc8;
        _memset(&stack0xffffffc8,0,iVar3 * 2);
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,(LPWSTR)&stack0xffffffc8,iVar3),
           iVar3 != 0)) {
          BVar2 = GetStringTypeW(param_1,(LPCWSTR)&stack0xffffffc8,iVar3,param_4);
          ExceptionList = local_14;
          return BVar2;
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_6 == 0) {
    param_6 = DAT_10043a6c;
  }
  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}



/* VA 10026c61 */

uint __cdecl FUN_10026c61(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;

  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) == 0) {
      param_1[3] = uVar2 | 1;
      if ((uVar2 & 0x10c) == 0) {
        FUN_1002836c(param_1);
      }
      else {
        *param_1 = param_1[2];
      }
      iVar3 = FUN_10026d3d(param_1[4],(char *)param_1[2],(char *)param_1[6]);
      param_1[1] = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((param_1[3] & 0x82) == 0) {
          uVar2 = param_1[4];
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_10040008;
          }
          else {
            puVar4 = (undefined *)((&DAT_10043c00)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
          }
          if ((puVar4[4] & 0x82) == 0x82) {
            param_1[3] = param_1[3] | 0x2000;
          }
        }
        if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
          param_1[6] = 0x1000;
        }
        param_1[1] = iVar3 + -1;
        bVar1 = *(byte *)*param_1;
        *param_1 = (byte *)*param_1 + 1;
        return (uint)bVar1;
      }
      param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
      param_1[1] = 0;
    }
    else {
      param_1[3] = uVar2 | 0x20;
    }
  }
  return 0xffffffff;
}



/* VA 10026d3d */

int __cdecl FUN_10026d3d(uint param_1,char *param_2,char *param_3)

{
  int iVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_10043d00) &&
     ((*(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10020ede(param_1);
    iVar1 = FUN_10026da2(param_1,param_2,param_3);
    FUN_10020f3d(param_1);
    return iVar1;
  }
  pDVar2 = FUN_10020fd2();
  *pDVar2 = 9;
  pDVar2 = FUN_10020fdb();
  *pDVar2 = 0;
  return -1;
}



/* VA 10026da2 */

int __cdecl FUN_10026da2(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  BOOL BVar5;
  DWORD DVar6;
  DWORD *pDVar7;
  char *pcVar8;
  int iVar9;
  DWORD local_10;
  char *local_c;
  char local_5;

  local_c = (char *)0x0;
  if (param_3 != (char *)0x0) {
    piVar1 = &DAT_10043c00 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_10043c00)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
        param_3 = param_3 + -1;
        *param_2 = cVar3;
        pcVar8 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined1 *)(*piVar1 + 5 + iVar9) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),pcVar8,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          pDVar7 = FUN_10020fd2();
          *pDVar7 = 9;
          pDVar7 = FUN_10020fdb();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_10020f5f(DVar6);
        }
        return -1;
      }
      bVar4 = *(byte *)(*piVar1 + 4 + iVar9);
      if ((bVar4 & 0x80) == 0) {
        return (int)local_c + local_10;
      }
      if ((local_10 == 0) || (*param_2 != '\n')) {
        bVar4 = bVar4 & 0xfb;
      }
      else {
        bVar4 = bVar4 | 4;
      }
      *(byte *)(*piVar1 + 4 + iVar9) = bVar4;
      param_3 = param_2;
      local_c = param_2 + (int)local_c + local_10;
      pcVar8 = param_2;
      if (param_2 < local_c) {
        do {
          cVar3 = *param_3;
          if (cVar3 == '\x1a') {
            pbVar2 = (byte *)(*piVar1 + 4 + iVar9);
            bVar4 = *pbVar2;
            if ((bVar4 & 0x40) == 0) {
              *pbVar2 = bVar4 | 2;
            }
            break;
          }
          if (cVar3 == '\r') {
            if (param_3 < local_c + -1) {
              if (param_3[1] == '\n') {
                param_3 = param_3 + 2;
                goto LAB_10026f2d;
              }
              *pcVar8 = '\r';
              pcVar8 = pcVar8 + 1;
              param_3 = param_3 + 1;
            }
            else {
              param_3 = param_3 + 1;
              BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),&local_5,1,&local_10,(LPOVERLAPPED)0x0);
              if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_10026f47:
                *pcVar8 = '\r';
LAB_10026f4a:
                pcVar8 = pcVar8 + 1;
              }
              else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_10026f2d:
                  *pcVar8 = '\n';
                  goto LAB_10026f4a;
                }
                FUN_10026fe0(param_1,-1,1);
                if (local_5 != '\n') goto LAB_10026f47;
              }
              else {
                if (local_5 == '\n') goto LAB_10026f2d;
                *pcVar8 = '\r';
                pcVar8 = pcVar8 + 1;
                *(char *)(*piVar1 + 5 + iVar9) = local_5;
              }
            }
          }
          else {
            *pcVar8 = cVar3;
            pcVar8 = pcVar8 + 1;
            param_3 = param_3 + 1;
          }
        } while (param_3 < local_c);
      }
      return (int)pcVar8 - (int)param_2;
    }
  }
  return 0;
}



/* VA 10026f7b */

DWORD __cdecl FUN_10026f7b(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_10043d00) &&
     ((*(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10020ede(param_1);
    DVar1 = FUN_10026fe0(param_1,param_2,param_3);
    FUN_10020f3d(param_1);
    return DVar1;
  }
  pDVar2 = FUN_10020fd2();
  *pDVar2 = 9;
  pDVar2 = FUN_10020fdb();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 10026fe0 */

DWORD __cdecl FUN_10026fe0(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;

  hFile = (HANDLE)FUN_10020df5(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_10020fd2();
    *pDVar2 = 9;
  }
  else {
    DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
    if (DVar3 == 0xffffffff) {
      uVar4 = GetLastError();
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 == 0) {
      pbVar1 = (byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_10020f5f(uVar4);
  }
  return 0xffffffff;
}



/* VA 10027053 */

int FUN_10027053(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;

  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    iVar3 = FUN_10022d08();
    return iVar3;
  }
  if ((DAT_10043a60 != (FARPROC)0x0) &&
     (bVar2 = FUN_100277ee(DAT_10043a60), CONCAT31(extraout_var,bVar2) != 0)) {
    iVar3 = (*DAT_10043a60)(param_1);
    return iVar3;
  }
  return 0;
}



/* VA 100270b7 */

int * __cdecl FUN_100270b7(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *_Size;
  int *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_10035728;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  puVar2 = (uint *)(param_1 * param_2);
  puVar3 = puVar2;
  ExceptionList = &local_14;
  if (puVar2 < (uint *)0xffffffe1) {
    if (puVar2 == (uint *)0x0) {
      puVar3 = (uint *)0x1;
    }
    puVar3 = (uint *)((int)puVar3 + 0xfU & 0xfffffff0);
    ExceptionList = &local_14;
  }
  do {
    local_24 = (int *)0x0;
    if (puVar3 < (uint *)0xffffffe1) {
      if (DAT_10043d24 == 3) {
        if (puVar2 <= DAT_10043d1c) {
          FUN_10022e54(9);
          local_8 = 0;
          local_24 = FUN_10024a2d(puVar2);
          local_8 = 0xffffffff;
          FUN_10027150();
          _Size = puVar2;
          if (local_24 == (int *)0x0) goto LAB_100271a4;
LAB_10027193:
          _memset(local_24,0,(size_t)_Size);
        }
LAB_1002719f:
        if (local_24 != (int *)0x0) {
          ExceptionList = local_14;
          return local_24;
        }
      }
      else {
        if ((DAT_10043d24 != 2) || (DAT_1003fdcc < puVar3)) goto LAB_1002719f;
        FUN_10022e54(9);
        local_8 = 1;
        local_24 = FUN_100254d0((uint)puVar3 >> 4);
        local_8 = 0xffffffff;
        FUN_100271d9();
        _Size = puVar3;
        if (local_24 != (int *)0x0) goto LAB_10027193;
      }
LAB_100271a4:
      local_24 = HeapAlloc(DAT_10043d20,8,(SIZE_T)puVar3);
    }
    if (local_24 != (int *)0x0) {
      ExceptionList = local_14;
      return local_24;
    }
    if (DAT_10043944 == 0) {
      ExceptionList = local_14;
      return (int *)0x0;
    }
    iVar1 = FUN_100258a5(puVar3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return (int *)0x0;
    }
  } while( true );
}



/* VA 10027150 */

void FUN_10027150(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 100271d9 */

void FUN_100271d9(void)

{
  FUN_10022eb5(9);
  return;
}



/* VA 100271f4 */

void FUN_100271f4(void)

{
  if (DAT_10043b40 == 0) {
    FUN_10022e54(0xb);
    if (DAT_10043b40 == 0) {
      FUN_10027222();
      DAT_10043b40 = DAT_10043b40 + 1;
    }
    FUN_10022eb5(0xb);
  }
  return;
}



/* VA 10027222 */

void FUN_10027222(void)

{
  char cVar1;
  char cVar2;
  uint *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  void *this;
  uint *_Source;
  int local_8;

  FUN_10022e54(0xc);
  DAT_100401f0 = 0xffffffff;
  DAT_100401e0 = 0xffffffff;
  DAT_10043a88 = 0;
  _Str1 = (uint *)FUN_1001f92d("TZ");
  if (_Str1 == (uint *)0x0) {
    FUN_10022eb5(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_10043a90);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_10040148 = (void *)(DAT_10043a90 * 0x3c);
    DAT_10043a88 = 1;
    if (DAT_10043ad6 != 0) {
      DAT_10040148 = (void *)((int)DAT_10040148 + DAT_10043ae4 * 0x3c);
    }
    if ((DAT_10043b2a == 0) || (DAT_10043b38 == 0)) {
      DAT_1004014c = 0;
      DAT_10040150 = 0;
    }
    else {
      DAT_1004014c = 1;
      DAT_10040150 = (DAT_10043b38 - DAT_10043ae4) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_10043a7c,0x220,(LPCWSTR)&DAT_10043a94,-1,PTR_DAT_100401d4,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_100401d4 = 0;
    }
    else {
      PTR_DAT_100401d4[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_10043a7c,0x220,(LPCWSTR)&DAT_10043ae8,-1,PTR_DAT_100401d8,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_100401d8[0x3f] = 0;
      return;
    }
LAB_10027493:
    *PTR_DAT_100401d8 = 0;
  }
  else {
    if (((char)*_Str1 != '\0') &&
       ((DAT_10043b3c == (uint *)0x0 ||
        (iVar4 = _strcmp((char *)_Str1,(char *)DAT_10043b3c), iVar4 != 0)))) {
      FUN_1001fabf((undefined *)DAT_10043b3c);
      sVar5 = _strlen((char *)_Str1);
      DAT_10043b3c = _malloc(sVar5 + 1);
      if (DAT_10043b3c != (uint *)0x0) {
        FUN_1001f150(DAT_10043b3c,_Str1);
        FUN_10022eb5(0xc);
        _strncpy(PTR_DAT_100401d4,(char *)_Str1,3);
        _Source = (uint *)((int)_Str1 + 3);
        PTR_DAT_100401d4[3] = 0;
        cVar1 = *(char *)_Source;
        if (cVar1 == '-') {
          _Source = _Str1 + 1;
        }
        iVar4 = FUN_1001fce2(this,(byte *)_Source);
        DAT_10040148 = (void *)(iVar4 * 0xe10);
        for (; (cVar2 = (char)*_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
            _Source = (uint *)((int)_Source + 1)) {
        }
        if ((char)*_Source == ':') {
          _Source = (uint *)((int)_Source + 1);
          iVar4 = FUN_1001fce2(DAT_10040148,(byte *)_Source);
          DAT_10040148 = (void *)((int)DAT_10040148 + iVar4 * 0x3c);
          for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
              _Source = (uint *)((int)_Source + 1)) {
          }
          if ((char)*_Source == ':') {
            _Source = (uint *)((int)_Source + 1);
            iVar4 = FUN_1001fce2(DAT_10040148,(byte *)_Source);
            DAT_10040148 = (void *)((int)DAT_10040148 + iVar4);
            for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
                _Source = (uint *)((int)_Source + 1)) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_10040148 = (void *)-(int)DAT_10040148;
        }
        DAT_1004014c = (int)(char)*_Source;
        if (DAT_1004014c != 0) {
          _strncpy(PTR_DAT_100401d8,(char *)_Source,3);
          PTR_DAT_100401d8[3] = 0;
          return;
        }
        goto LAB_10027493;
      }
    }
    FUN_10022eb5(0xc);
  }
  return;
}



/* VA 100274a9 */

bool __cdecl FUN_100274a9(int *param_1)

{
  bool bVar1;

  FUN_10022e54(0xb);
  bVar1 = FUN_100274ca(param_1);
  FUN_10022eb5(0xb);
  return bVar1;
}



/* VA 100274ca */

bool __cdecl FUN_100274ca(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;

  if (DAT_1004014c != 0) {
    uVar5 = param_1[5];
    if ((uVar5 != DAT_100401e0) || (uVar5 != DAT_100401f0)) {
      if (DAT_10043a88 == 0) {
        FUN_10027676(1,1,uVar5,4,1,0,0,2,0,0,0);
        FUN_10027676(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_10043b28 != 0) {
          uVar6 = (uint)DAT_10043b2e;
          uVar3 = 0;
          uVar4 = 0;
        }
        else {
          uVar3 = (uint)DAT_10043b2c;
          uVar6 = 0;
          uVar4 = (uint)DAT_10043b2e;
        }
        FUN_10027676(1,(uint)(DAT_10043b28 == 0),uVar5,(uint)DAT_10043b2a,uVar4,uVar3,uVar6,
                     (uint)DAT_10043b30,(uint)DAT_10043b32,(uint)DAT_10043b34,(uint)DAT_10043b36);
        if (DAT_10043ad4 != 0) {
          uVar6 = (uint)DAT_10043ada;
          uVar3 = 0;
          uVar4 = 0;
          uVar5 = param_1[5];
        }
        else {
          uVar3 = (uint)DAT_10043ad8;
          uVar6 = 0;
          uVar4 = (uint)DAT_10043ada;
          uVar5 = param_1[5];
        }
        FUN_10027676(0,(uint)(DAT_10043ad4 == 0),uVar5,(uint)DAT_10043ad6,uVar4,uVar3,uVar6,
                     (uint)DAT_10043adc,(uint)DAT_10043ade,(uint)DAT_10043ae0,(uint)DAT_10043ae2);
      }
    }
    iVar1 = param_1[7];
    if (DAT_100401e4 < DAT_100401f4) {
      if ((DAT_100401e4 <= iVar1) && (iVar1 <= DAT_100401f4)) {
        if ((DAT_100401e4 < iVar1) && (iVar1 < DAT_100401f4)) {
          return true;
        }
LAB_10027642:
        iVar2 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar1 == DAT_100401e4) {
          return DAT_100401e8 <= iVar2;
        }
        return iVar2 < DAT_100401f8;
      }
    }
    else {
      if (iVar1 < DAT_100401f4) {
        return true;
      }
      if (DAT_100401e4 < iVar1) {
        return true;
      }
      if ((iVar1 <= DAT_100401f4) || (DAT_100401e4 <= iVar1)) goto LAB_10027642;
    }
  }
  return false;
}



/* VA 10027676 */

void __cdecl
FUN_10027676(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;

  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = (&DAT_100401f8)[param_4];
    }
    else {
      iVar1 = *(int *)(&DAT_1004022c + param_4 * 4);
    }
    iVar2 = (int)(param_3 * 0x16d + -0x63db + iVar1 + 1 + ((int)(param_3 - 1) >> 2)) % 7;
    if (param_6 < iVar2) {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&DAT_100401fc + param_4 * 4);
      }
      else {
        iVar2 = *(int *)(&DAT_10040230 + param_4 * 4);
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = (&DAT_100401f8)[param_4];
    }
    else {
      iVar1 = *(int *)(&DAT_1004022c + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_100401e0 = param_3;
    DAT_100401e8 = ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000 + param_11;
    DAT_100401e4 = iVar1;
  }
  else {
    DAT_100401f8 = ((param_8 * 0x3c + param_9) * 0x3c + DAT_10040150 + param_10) * 1000 + param_11;
    if (DAT_100401f8 < 0) {
      DAT_100401f8 = DAT_100401f8 + 86400000;
      DAT_100401f4 = iVar1 + -1;
    }
    else {
      DAT_100401f4 = iVar1;
      if (86399999 < DAT_100401f8) {
        DAT_100401f8 = DAT_100401f8 + -86400000;
        DAT_100401f4 = iVar1 + 1;
      }
    }
    DAT_100401f0 = param_3;
  }
  return;
}



/* VA 100277b6 */

bool __cdecl FUN_100277b6(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;

  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}



/* VA 100277d2 */

bool __cdecl FUN_100277d2(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;

  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}



/* VA 100277ee */

bool __cdecl FUN_100277ee(FARPROC param_1)

{
  BOOL BVar1;

  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}



/* VA 10027806 */

void FUN_10027806(void)

{
  FUN_10026717(10);
  FUN_10028e3e((DWORD *)0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* VA 1002789e */

byte __cdecl FUN_1002789e(uint param_1)

{
  if (DAT_10043d00 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}



/* VA 100278c7 */

int __cdecl FUN_100278c7(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;

  InterlockedIncrement((LONG *)&DAT_10043bf8);
  bVar2 = DAT_10043bf4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_10043bf8);
    FUN_10022e54(0x13);
  }
  iVar1 = FUN_10027920(param_1,param_2);
  if (bVar2) {
    FUN_10022eb5(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_10043bf8);
  }
  return iVar1;
}



/* VA 10027920 */

int __cdecl FUN_10027920(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  DWORD *pDVar2;

  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_10043a6c == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_10043a7c,0x220,&param_2,1,lpMultiByteStr,DAT_1003ffdc,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  pDVar2 = FUN_10020fd2();
  *pDVar2 = 0x2a;
  return -1;
}



/* VA 10027990 */

/* Library Function - Single Match
    __aulldiv

   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

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



/* VA 10027a00 */

/* Library Function - Single Match
    __aullrem

   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

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



/* VA 10027a75 */

uint __cdecl FUN_10027a75(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;

  if (DAT_10043a6c == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_10043bf8);
    bVar1 = DAT_10043bf4 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_10043bf8);
      this = (void *)0x13;
      FUN_10022e54(0x13);
    }
    param_1 = FUN_10027ae4(this,param_1);
    if (bVar1) {
      FUN_10022eb5(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_10043bf8);
    }
  }
  return param_1;
}



/* VA 10027ae4 */

uint __thiscall FUN_10027ae4(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;

  uVar1 = param_1;
  if (DAT_10043a6c == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      uVar1 = param_1 + 0x20;
    }
  }
  else {
    iVar3 = 1;
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_1003ffdc < 2) {
        uVar2 = (byte)PTR_DAT_1003fdd0[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_100258c0(this,param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_1003fdd0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_100238eb(DAT_10043a6c,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}



/* VA 10027baf */

uint __cdecl FUN_10027baf(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  DWORD *pDVar4;
  HANDLE hFile;
  DWORD DVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  byte local_5;

  bVar8 = (param_2 & 0x80) == 0;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar8) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)bVar8;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_10043bd8 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) goto LAB_10027cb3;
    local_10 = 0xc0000000;
  }
  if (param_3 == 0x10) {
    local_14 = 0;
  }
  else if (param_3 == 0x20) {
    local_14 = 1;
  }
  else if (param_3 == 0x30) {
    local_14 = 2;
  }
  else {
    if (param_3 != 0x40) goto LAB_10027cb3;
    local_14 = 3;
  }
  uVar2 = param_2 & 0x700;
  if (uVar2 < 0x401) {
    if ((uVar2 == 0x400) || (uVar2 == 0)) {
      local_c = 3;
    }
    else if (uVar2 == 0x100) {
      local_c = 4;
    }
    else {
      if (uVar2 == 0x200) goto LAB_10027ccd;
      if (uVar2 != 0x300) goto LAB_10027cb3;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_10027ccd:
        local_c = 5;
        goto LAB_10027cdd;
      }
      if (uVar2 != 0x700) {
LAB_10027cb3:
        pDVar4 = FUN_10020fd2();
        *pDVar4 = 0x16;
        pDVar4 = FUN_10020fdb();
        *pDVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_10027cdd:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_1004388c & param_4 & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((param_2 & 0x40) != 0) {
    uVar2 = uVar2 | 0x4000000;
    local_10 = CONCAT13(local_10._3_1_,0x10000);
  }
  if ((param_2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = FUN_10020bd7();
  if (uVar3 == 0xffffffff) {
    pDVar4 = FUN_10020fd2();
    *pDVar4 = 0x18;
    pDVar4 = FUN_10020fdb();
    *pDVar4 = 0;
    return 0xffffffff;
  }
  hFile = CreateFileA(param_1,local_10,local_14,&local_20,local_c,uVar2,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar5 = GetFileType(hFile);
    if (DVar5 != 0) {
      if (DVar5 == 2) {
        local_5 = local_5 | 0x40;
      }
      else if (DVar5 == 3) {
        local_5 = local_5 | 8;
      }
      FUN_10020cfa(uVar3,hFile);
      iVar7 = (uVar3 & 0x1f) * 0x24;
      param_1._3_1_ = local_5 & 0x48;
      *(byte *)((&DAT_10043c00)[(int)uVar3 >> 5] + 4 + iVar7) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        local_14 = FUN_10026fe0(uVar3,-1,2);
        if (local_14 == 0xffffffff) {
          pDVar4 = FUN_10020fdb();
          if (*pDVar4 == 0x83) goto LAB_10027e57;
        }
        else {
          param_3 = param_3 & 0xffffff;
          iVar6 = FUN_10026da2(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
          if ((((iVar6 != 0) || (param_3._3_1_ != '\x1a')) ||
              (iVar6 = FUN_10028ffd(uVar3,local_14), iVar6 != -1)) &&
             (DVar5 = FUN_10026fe0(uVar3,0,0), DVar5 != 0xffffffff)) goto LAB_10027e57;
        }
        FUN_10023e18(uVar3);
        uVar2 = 0xffffffff;
      }
      else {
LAB_10027e57:
        uVar2 = uVar3;
        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {
          pbVar1 = (byte *)((&DAT_10043c00)[(int)uVar3 >> 5] + 4 + iVar7);
          *pbVar1 = *pbVar1 | 0x20;
        }
      }
      goto LAB_10027e70;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  FUN_10020f5f(DVar5);
  uVar2 = 0xffffffff;
LAB_10027e70:
  FUN_10020f3d(uVar3);
  return uVar2;
}



/* VA 10027e7e */

int __cdecl
FUN_10027e7e(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
            UINT param_7)

{
  undefined1 *puVar1;
  int iVar2;
  BOOL BVar3;
  BYTE *pBVar4;
  int iVar5;
  _cpinfo local_40;
  undefined1 *local_2c;
  PCNZWCH local_28;
  int local_24;
  int local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_10035788;
  puStack_10 = &LAB_1001f834;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffb0;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffb0;
  if (DAT_10043b50 == 0) {
    ExceptionList = &local_14;
    iVar2 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar2 == 0) {
      iVar2 = CompareStringA(0,0,"",1,"",1);
      if (iVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_10043b50 = 2;
      puVar1 = local_1c;
    }
    else {
      DAT_10043b50 = 1;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  if (0 < param_4) {
    param_4 = FUN_100280fb((char *)param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_100280fb((char *)param_5,param_6);
  }
  if (DAT_10043b50 == 2) {
    iVar2 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
    ExceptionList = local_14;
    return iVar2;
  }
  if (DAT_10043b50 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_10043a7c;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        ExceptionList = local_14;
        return 2;
      }
      if (1 < param_6) {
        ExceptionList = local_14;
        return 1;
      }
      if (1 < param_4) {
        ExceptionList = local_14;
        return 3;
      }
      BVar3 = GetCPInfo(param_7,&local_40);
      if (BVar3 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (0 < param_4) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 3;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 3;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_3) && (*param_3 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 3;
      }
      if (0 < param_6) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 1;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 1;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_5) && (*param_5 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 1;
      }
    }
    local_20 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);
    if (local_20 != 0) {
      local_8 = 0;
      FUN_1001fa90();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x50) &&
         (local_28 = (PCNZWCH)&stack0xffffffb0, local_1c = &stack0xffffffb0,
         iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,(LPWSTR)&stack0xffffffb0,
                                     local_20), iVar2 != 0)) {
        iVar2 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          local_8 = 1;
          local_24 = iVar2;
          FUN_1001fa90();
          local_8 = 0xffffffff;
          if ((&stack0x00000000 != (undefined1 *)0x50) &&
             (local_2c = &stack0xffffffb0, local_1c = &stack0xffffffb0,
             iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,(LPWSTR)&stack0xffffffb0,
                                         iVar2), iVar5 != 0)) {
            iVar2 = CompareStringW(param_1,param_2,local_28,local_20,(PCNZWCH)&stack0xffffffb0,iVar2
                                  );
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* VA 100280fb */

int __cdecl FUN_100280fb(char *param_1,int param_2)

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



/* VA 10028126 */

undefined4 __cdecl FUN_10028126(uint *param_1,int param_2)

{
  byte *pbVar1;
  uint *puVar2;
  int iVar3;
  byte *pbVar4;
  size_t sVar5;
  uint *lpName;
  byte *pbVar6;
  bool bVar7;

  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar2 = (uint *)FUN_10020453((byte *)param_1,0x3d);
  if (puVar2 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar2) {
    return 0xffffffff;
  }
  bVar7 = *(byte *)((int)puVar2 + 1) == 0;
  if (DAT_100438ac == DAT_100438b0) {
    DAT_100438ac = (byte *)FUN_10028305((int *)DAT_100438ac);
  }
  if (DAT_100438ac == (byte *)0x0) {
    if ((param_2 == 0) || (DAT_100438b4 == (undefined4 *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_100438ac = _malloc(4);
      if (DAT_100438ac == (byte *)0x0) {
        return 0xffffffff;
      }
      pbVar4 = DAT_100438ac + 1;
      pbVar6 = DAT_100438ac + 2;
      pbVar1 = DAT_100438ac + 3;
      DAT_100438ac[0] = 0;
      *pbVar4 = 0;
      *pbVar6 = 0;
      *pbVar1 = 0;
      if (DAT_100438b4 == (undefined4 *)0x0) {
        DAT_100438b4 = _malloc(4);
        if (DAT_100438b4 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_100438b4 = 0;
      }
    }
    else {
      iVar3 = FUN_10024291();
      if (iVar3 != 0) {
        return 0xffffffff;
      }
    }
  }
  pbVar4 = DAT_100438ac;
  iVar3 = FUN_100282ad((uchar *)param_1,(int)puVar2 - (int)param_1);
  if ((iVar3 < 0) || (*(int *)pbVar4 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    pbVar4 = FUN_10023f23(pbVar4,(uint *)(iVar3 * 4 + 8));
    if (pbVar4 == (byte *)0x0) {
      return 0xffffffff;
    }
    *(uint **)(pbVar4 + iVar3 * 4) = param_1;
    pbVar6 = pbVar4 + iVar3 * 4 + 4;
    pbVar6[0] = 0;
    pbVar6[1] = 0;
    pbVar6[2] = 0;
    pbVar6[3] = 0;
  }
  else {
    if (!bVar7) {
      *(uint **)(pbVar4 + iVar3 * 4) = param_1;
      goto LAB_1002825a;
    }
    pbVar6 = pbVar4 + iVar3 * 4;
    FUN_1001fabf(*(undefined **)(pbVar4 + iVar3 * 4));
    for (; *(int *)pbVar6 != 0; pbVar6 = pbVar6 + 4) {
      iVar3 = iVar3 + 1;
      *(int *)pbVar6 = *(int *)(pbVar6 + 4);
    }
    pbVar4 = FUN_10023f23(pbVar4,(uint *)(iVar3 << 2));
    if (pbVar4 == (byte *)0x0) goto LAB_1002825a;
  }
  DAT_100438ac = pbVar4;
LAB_1002825a:
  if (param_2 != 0) {
    sVar5 = _strlen((char *)param_1);
    lpName = _malloc(sVar5 + 2);
    if (lpName != (uint *)0x0) {
      FUN_1001f150(lpName,param_1);
      pbVar4 = (byte *)(((int)lpName - (int)param_1) + (int)puVar2);
      *pbVar4 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar7 & (uint)(pbVar4 + 1)));
      FUN_1001fabf((undefined *)lpName);
    }
  }
  return 0;
}



/* VA 100282ad */

int __cdecl FUN_100282ad(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;

  _Str2 = (uchar *)*DAT_100438ac;
  piVar2 = DAT_100438ac;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_100438ac >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    _Str2 = (uchar *)piVar2[1];
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_100438ac >> 2;
}



/* VA 10028305 */

undefined4 * __cdecl FUN_10028305(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint *puVar4;
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
    puVar3 = _malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    puVar4 = (uint *)*param_1;
    puVar6 = puVar3;
    while (puVar4 != (uint *)0x0) {
      param_1 = param_1 + 1;
      puVar4 = FUN_1002177c(puVar4);
      *puVar6 = puVar4;
      puVar6 = puVar6 + 1;
      puVar4 = (uint *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}



/* VA 1002836c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002836c(undefined4 *param_1)

{
  void *pvVar1;

  _DAT_10043930 = _DAT_10043930 + 1;
  pvVar1 = _malloc(0x1000);
  param_1[2] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    param_1[3] = param_1[3] | 4;
    param_1[2] = param_1 + 5;
    param_1[6] = 2;
  }
  else {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return;
}



/* VA 100283b0 */

void __thiscall FUN_100283b0(void *this,byte *param_1,int *param_2,void *param_3)

{
  FUN_100283c7(this,param_1,param_2,param_3,0);
  return;
}



/* VA 100283c7 */

void * __thiscall FUN_100283c7(void *this,byte *param_1,int *param_2,void *param_3,uint param_4)

{
  byte *pbVar1;
  void *pvVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  DWORD *pDVar6;
  void *this_00;
  byte bVar7;
  undefined *puVar8;
  void *local_c;
  byte *local_8;

  local_c = (void *)0x0;
  bVar7 = *param_1;
  pbVar1 = param_1;
  while( true ) {
    local_8 = pbVar1 + 1;
    if (DAT_1003ffdc < 2) {
      uVar3 = (byte)PTR_DAT_1003fdd0[(uint)bVar7 * 2] & 8;
      this = PTR_DAT_1003fdd0;
    }
    else {
      puVar8 = (undefined *)0x8;
      uVar3 = FUN_100258c0(this,(uint)bVar7,8);
      this = puVar8;
    }
    if (uVar3 == 0) break;
    bVar7 = *local_8;
    pbVar1 = local_8;
  }
  if (bVar7 == 0x2d) {
    param_4 = param_4 | 2;
LAB_10028422:
    bVar7 = *local_8;
    local_8 = pbVar1 + 2;
  }
  else if (bVar7 == 0x2b) goto LAB_10028422;
  if ((((int)param_3 < 0) || (param_3 == (void *)0x1)) || (0x24 < (int)param_3)) {
    if (param_2 != (int *)0x0) {
      *param_2 = (int)param_1;
    }
    return (void *)0x0;
  }
  this_00 = (void *)0x10;
  if (param_3 == (void *)0x0) {
    if (bVar7 != 0x30) {
      param_3 = (void *)0xa;
      goto LAB_1002848c;
    }
    if ((*local_8 != 0x78) && (*local_8 != 0x58)) {
      param_3 = (void *)0x8;
      goto LAB_1002848c;
    }
    param_3 = (void *)0x10;
  }
  if (((param_3 == (void *)0x10) && (bVar7 == 0x30)) && ((*local_8 == 0x78 || (*local_8 == 0x58))))
  {
    bVar7 = local_8[1];
    local_8 = local_8 + 2;
  }
LAB_1002848c:
  pvVar4 = (void *)(0xffffffff / ZEXT48(param_3));
  do {
    uVar3 = (uint)bVar7;
    if (DAT_1003ffdc < 2) {
      uVar5 = (byte)PTR_DAT_1003fdd0[uVar3 * 2] & 4;
    }
    else {
      pvVar2 = (void *)0x4;
      uVar5 = FUN_100258c0(this_00,uVar3,4);
      this_00 = pvVar2;
    }
    if (uVar5 == 0) {
      if (DAT_1003ffdc < 2) {
        uVar3 = *(ushort *)(PTR_DAT_1003fdd0 + uVar3 * 2) & 0x103;
      }
      else {
        uVar3 = FUN_100258c0(this_00,uVar3,0x103);
      }
      if (uVar3 == 0) {
LAB_10028538:
        local_8 = local_8 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (int *)0x0) {
            local_8 = param_1;
          }
          local_c = (void *)0x0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && ((void *)0x80000000 < local_c)) ||
                  (((param_4 & 2) == 0 && ((void *)0x7fffffff < local_c)))))))) {
          pDVar6 = FUN_10020fd2();
          *pDVar6 = 0x22;
          if ((param_4 & 1) == 0) {
            local_c = (void *)(((param_4 & 2) != 0) + 0x7fffffff);
          }
          else {
            local_c = (void *)0xffffffff;
          }
        }
        if (param_2 != (int *)0x0) {
          *param_2 = (int)local_8;
        }
        if ((param_4 & 2) == 0) {
          return local_c;
        }
        return (void *)-(int)local_c;
      }
      uVar3 = FUN_10029122((int)(char)bVar7);
      this_00 = (void *)(uVar3 - 0x37);
    }
    else {
      this_00 = (void *)((char)bVar7 + -0x30);
    }
    if (param_3 <= this_00) goto LAB_10028538;
    if ((local_c < pvVar4) ||
       ((local_c == pvVar4 && (this_00 <= (void *)(0xffffffff % ZEXT48(param_3)))))) {
      local_c = (void *)((int)local_c * (int)param_3 + (int)this_00);
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
    }
    bVar7 = *local_8;
    local_8 = local_8 + 1;
  } while( true );
}



/* VA 100285cc */

uint __thiscall FUN_100285cc(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;

  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_10028617(local_8);
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_100286a9(uVar1);
  return uVar1;
}



/* VA 10028601 */

void __thiscall FUN_10028601(void *this,uint param_1,uint param_2)

{
  FUN_100285cc(this,param_1,param_2 & 0xfff7ffff);
  return;
}



/* VA 10028617 */

uint __cdecl FUN_10028617(uint param_1)

{
  uint uVar1;
  uint uVar2;

  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 != 0) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
    else if (uVar2 == 0x800) {
      uVar1 = uVar1 | 0x200;
    }
    else if (uVar2 == 0xc00) {
      uVar1 = uVar1 | 0x300;
    }
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}



/* VA 100286a9 */

uint __cdecl FUN_100286a9(uint param_1)

{
  uint uVar1;
  uint uVar2;

  uVar1 = (uint)((param_1 & 0x10) != 0);
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((param_1 & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1 & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = param_1 & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((param_1 & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((param_1 & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}



/* VA 10028732 */

undefined4 __cdecl FUN_10028732(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;

  if ((*(uint *)(param_1 + (param_2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f)))
      != 0) {
    return 0;
  }
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    piVar1 = (int *)(param_1 + iVar2 * 4);
    do {
      if (*piVar1 != 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}



/* VA 1002877b */

void __cdecl FUN_1002877b(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;

  puVar3 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = FUN_1002925d(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_1002925d(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}



/* VA 100287d1 */

undefined4 __cdecl FUN_100287d1(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_8;

  local_8 = 0;
  puVar1 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  bVar3 = 0x1f - (char)(param_2 % 0x20);
  if (((*puVar1 & 1 << (bVar3 & 0x1f)) != 0) &&
     (iVar2 = FUN_10028732(param_1,param_2 + 1), iVar2 == 0)) {
    local_8 = FUN_1002877b(param_1,param_2 + -1);
  }
  *puVar1 = *puVar1 & -1 << (bVar3 & 0x1f);
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);
    for (iVar4 = 3 - iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}



/* VA 1002885d */

void __cdecl FUN_1002885d(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;

  iVar1 = param_1 - (int)param_2;
  iVar2 = 3;
  do {
    *(undefined4 *)(iVar1 + (int)param_2) = *param_2;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



/* VA 10028878 */

void __cdecl FUN_10028878(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



/* VA 10028884 */

undefined4 __cdecl FUN_10028884(int *param_1)

{
  int iVar1;

  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 3);
  return 1;
}



/* VA 1002889f */

void __cdecl FUN_1002889f(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_8;

  local_8 = 3;
  iVar2 = (int)param_2 / 0x20;
  iVar5 = (int)param_2 % 0x20;
  param_2 = 0;
  bVar3 = (byte)iVar5;
  puVar6 = param_1;
  do {
    uVar1 = *puVar6;
    *puVar6 = uVar1 >> (bVar3 & 0x1f) | param_2;
    puVar6 = puVar6 + 1;
    param_2 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  iVar5 = 2;
  iVar4 = 8;
  do {
    if (iVar5 < iVar2) {
      *(undefined4 *)(iVar4 + (int)param_1) = 0;
    }
    else {
      *(undefined4 *)(iVar4 + (int)param_1) = *(undefined4 *)(iVar4 + iVar2 * -4 + (int)param_1);
    }
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + -4;
  } while (-1 < iVar4);
  return;
}



/* VA 1002892c */

undefined4 __cdecl FUN_1002892c(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_1c [3];
  uint local_10;
  uint local_c;
  int local_8;

  uVar1 = param_1[5];
  local_10 = *(uint *)(param_1 + 3);
  local_c = *(uint *)(param_1 + 1);
  uVar3 = uVar1 & 0x7fff;
  iVar4 = uVar3 - 0x3fff;
  local_8 = (uint)*param_1 << 0x10;
  if (iVar4 == -0x3fff) {
    iVar4 = 0;
    iVar2 = FUN_10028884((int *)&local_10);
    if (iVar2 != 0) {
LAB_10028a58:
      uVar5 = 0;
      goto LAB_10028a5a;
    }
    FUN_10028878(&local_10);
  }
  else {
    FUN_1002885d((int)local_1c,&local_10);
    iVar2 = FUN_100287d1((int)&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar4 = uVar3 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar4 < iVar2 - param_3[2]) {
      FUN_10028878(&local_10);
    }
    else {
      if (iVar2 < iVar4) {
        if (*param_3 <= iVar4) {
          FUN_10028878(&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_1002889f(&local_10,param_3[3]);
          iVar4 = param_3[5] + *param_3;
          uVar5 = 1;
          goto LAB_10028a5a;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar4 = param_3[5] + iVar4;
        FUN_1002889f(&local_10,param_3[3]);
        goto LAB_10028a58;
      }
      FUN_1002885d((int)&local_10,local_1c);
      FUN_1002889f(&local_10,iVar2 - iVar4);
      FUN_100287d1((int)&local_10,param_3[2]);
      FUN_1002889f(&local_10,param_3[3] + 1);
    }
  }
  iVar4 = 0;
  uVar5 = 2;
LAB_10028a5a:
  local_10 = iVar4 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (param_3[4] == 0x40) {
    param_2[1] = local_10;
    *param_2 = local_c;
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_10;
  }
  return uVar5;
}



/* VA 10028a98 */

void __cdecl FUN_10028a98(ushort *param_1,uint *param_2)

{
  FUN_1002892c(param_1,param_2,(int *)&DAT_10040370);
  return;
}



/* VA 10028aae */

void __cdecl FUN_10028aae(ushort *param_1,uint *param_2)

{
  FUN_1002892c(param_1,param_2,(int *)&DAT_10040388);
  return;
}



/* VA 10028ac4 */

void __thiscall FUN_10028ac4(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];

  FUN_100293fe(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_10028a98(local_10,param_1);
  return;
}



/* VA 10028af1 */

void __thiscall FUN_10028af1(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];

  FUN_100293fe(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_10028aae(local_10,param_1);
  return;
}



/* VA 10028b1e */

void __cdecl FUN_10028b1e(char *param_1,int param_2,int param_3)

{
  char *_Str;
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  char cVar5;

  pcVar1 = param_1;
  pcVar4 = *(char **)(param_3 + 0xc);
  _Str = param_1 + 1;
  *param_1 = '0';
  pcVar2 = _Str;
  if (0 < param_2) {
    param_1 = (char *)param_2;
    param_2 = 0;
    do {
      cVar5 = *pcVar4;
      if (cVar5 == '\0') {
        cVar5 = '0';
      }
      else {
        pcVar4 = pcVar4 + 1;
      }
      *pcVar2 = cVar5;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != (char *)0x0);
  }
  *pcVar2 = '\0';
  if ((-1 < param_2) && ('4' < *pcVar4)) {
    while (pcVar2 = pcVar2 + -1, *pcVar2 == '9') {
      *pcVar2 = '0';
    }
    *pcVar2 = *pcVar2 + '\x01';
  }
  if (*pcVar1 == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  }
  else {
    sVar3 = _strlen(_Str);
    FUN_10020590((undefined4 *)pcVar1,(undefined4 *)_Str,sVar3 + 1);
  }
  return;
}



/* VA 10028b95 */

int * __cdecl FUN_10028b95(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 in_stack_ffffffbc;
  undefined2 uVar4;
  short local_2c;
  char local_2a;
  uint local_28 [6];
  uint local_10;
  uint uStack_c;
  undefined2 uStack_8;

  uVar4 = (undefined2)((uint)in_stack_ffffffbc >> 0x10);
  FUN_10028bf1(&local_10,&param_1);
  iVar3 = FUN_100298cf(local_10,uStack_c,CONCAT22(uVar4,uStack_8),0x11,0,&local_2c);
  puVar2 = param_4;
  piVar1 = param_3;
  param_3[2] = iVar3;
  *param_3 = (int)local_2a;
  param_3[1] = (int)local_2c;
  FUN_1001f150(param_4,local_28);
  piVar1[3] = (int)puVar2;
  return piVar1;
}



/* VA 10028bf1 */

void __cdecl FUN_10028bf1(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;

  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  uVar2 = *param_2;
  local_8 = 0x80000000;
  if (uVar3 == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    iVar4 = 0x3c01;
    local_8 = 0;
  }
  else if (uVar3 == 0x7ff) {
    iVar4 = 0x7fff;
  }
  else {
    iVar4 = uVar3 + 0x3c00;
  }
  local_8 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  param_1[1] = local_8;
  *param_1 = uVar2 << 0xb;
  while ((local_8 & 0x80000000) == 0) {
    local_8 = *param_1 >> 0x1f | local_8 * 2;
    *param_1 = *param_1 * 2;
    param_1[1] = local_8;
    iVar4 = iVar4 + 0xffff;
  }
  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | (ushort)iVar4;
  return;
}



/* VA 10028ca7 */

/* Library Function - Single Match
    __fptrap

   Library: Visual Studio 2003 Release */

void __cdecl __fptrap(void)

{
  __amsg_exit(2);
  return;
}



/* VA 10028cb0 */

int __cdecl FUN_10028cb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;

  iVar1 = 0;
  if (DAT_10043b54 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_10043b54 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_10043b54 != (FARPROC)0x0) {
        DAT_10043b58 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_10043b5c = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_10028cff;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_10028cff:
    if (DAT_10043b58 != (FARPROC)0x0) {
      iVar1 = (*DAT_10043b58)();
      if ((iVar1 != 0) && (DAT_10043b5c != (FARPROC)0x0)) {
        iVar1 = (*DAT_10043b5c)(iVar1);
      }
    }
    iVar1 = (*DAT_10043b54)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}



/* VA 10028d40 */

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
        goto joined_r0x10028d7e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_10028dbb;
        goto LAB_10028e29;
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
joined_r0x10028e25:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_10028e29:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_10028dbb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x10028e25;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x10028e25;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x10028e25;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x10028d7e:
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
LAB_10028dbb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* VA 10028e3e */

undefined4 __cdecl FUN_10028e3e(DWORD *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  DWORD local_10;
  DWORD local_c;

  bVar1 = false;
  if (param_1 == (DWORD *)0x2) {
    puVar7 = &DAT_10043bc4;
    pcVar6 = DAT_10043bc4;
LAB_10028ec4:
    bVar1 = true;
    FUN_10022e54(1);
    pDVar2 = param_1;
  }
  else {
    if (((param_1 != (DWORD *)0x4) && (param_1 != (DWORD *)0x8)) && (param_1 != (DWORD *)0xb)) {
      if (param_1 == (DWORD *)0xf) {
        puVar7 = &DAT_10043bd0;
        pcVar6 = DAT_10043bd0;
      }
      else if (param_1 == (DWORD *)0x15) {
        puVar7 = &DAT_10043bc8;
        pcVar6 = DAT_10043bc8;
      }
      else {
        if (param_1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        puVar7 = &DAT_10043bcc;
        pcVar6 = DAT_10043bcc;
      }
      goto LAB_10028ec4;
    }
    pDVar2 = FUN_10022c01();
    uVar3 = FUN_10028fc0((int)param_1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    FUN_10022eb5(1);
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      FUN_10022eb5(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == (DWORD *)0x8) || (param_1 == (DWORD *)0xb)) || (param_1 == (DWORD *)0x4)) {
    local_c = pDVar2[0x15];
    pDVar2[0x15] = 0;
    if (param_1 == (DWORD *)0x8) {
      local_10 = pDVar2[0x16];
      pDVar2[0x16] = 0x8c;
      goto LAB_10028f38;
    }
  }
  else {
LAB_10028f38:
    if (param_1 == (DWORD *)0x8) {
      if (DAT_10040138 < DAT_1004013c + DAT_10040138) {
        iVar4 = DAT_10040138 * 0xc;
        iVar5 = DAT_10040138;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_1004013c + DAT_10040138);
      }
      goto LAB_10028f76;
    }
  }
  *puVar7 = 0;
LAB_10028f76:
  if (bVar1) {
    FUN_10022eb5(1);
  }
  if (param_1 == (DWORD *)0x8) {
    (*pcVar6)(8,pDVar2[0x16]);
  }
  else {
    (*pcVar6)(param_1);
    if ((param_1 != (DWORD *)0xb) && (param_1 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar2[0x15] = local_c;
  if (param_1 == (DWORD *)0x8) {
    pDVar2[0x16] = local_10;
  }
  return 0;
}



/* VA 10028fc0 */

uint __cdecl FUN_10028fc0(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;

  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_10040144 * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_10040144 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 10028ffd */

int __cdecl FUN_10028ffd(uint param_1,int param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  DWORD *pDVar6;
  HANDLE hFile;
  BOOL BVar7;
  int iVar8;
  uint uVar9;
  char local_1008 [4064];
  undefined4 uStackY_28;

  FUN_1001fa90();
  iVar8 = 0;
  DVar1 = FUN_10026fe0(param_1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = FUN_10026fe0(param_1,0,2), DVar2 == 0xffffffff)) {
    iVar8 = -1;
  }
  else {
    uVar9 = param_2 - DVar2;
    if ((int)uVar9 < 1) {
      if ((int)uVar9 < 0) {
        FUN_10026fe0(param_1,param_2,0);
        hFile = (HANDLE)FUN_10020df5(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar8 = (BVar7 != 0) - 1;
        if (iVar8 == -1) {
          pDVar6 = FUN_10020fd2();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = FUN_10020fdb();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x1002906a;
      iVar3 = FUN_10029c71(param_1,0x8000);
      do {
        uVar4 = 0x1000;
        if ((int)uVar9 < 0x1000) {
          uVar4 = uVar9;
        }
        iVar5 = FUN_10025f0b(param_1,local_1008,uVar4);
        if (iVar5 == -1) {
          pDVar6 = FUN_10020fdb();
          if (*pDVar6 == 5) {
            pDVar6 = FUN_10020fd2();
            *pDVar6 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        uVar9 = uVar9 - iVar5;
      } while (0 < (int)uVar9);
      FUN_10029c71(param_1,iVar3);
    }
    FUN_10026fe0(param_1,DVar1,0);
  }
  return iVar8;
}



/* VA 10029122 */

uint __cdecl FUN_10029122(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;

  if (DAT_10043a6c == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_10043bf8);
    bVar1 = DAT_10043bf4 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_10043bf8);
      this = (void *)0x13;
      FUN_10022e54(0x13);
    }
    param_1 = FUN_10029191(this,param_1);
    if (bVar1) {
      FUN_10022eb5(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_10043bf8);
    }
  }
  return param_1;
}



/* VA 10029191 */

uint __thiscall FUN_10029191(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;

  uVar1 = param_1;
  if (DAT_10043a6c == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      uVar1 = param_1 - 0x20;
    }
  }
  else {
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_1003ffdc < 2) {
        uVar2 = (byte)PTR_DAT_1003fdd0[param_1 * 2] & 2;
      }
      else {
        uVar2 = FUN_100258c0(this,param_1,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_1003fdd0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
      iVar3 = 1;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_100238eb(DAT_10043a6c,0x200,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}



/* VA 1002925d */

undefined4 __cdecl FUN_1002925d(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;

  uVar2 = 0;
  uVar1 = param_1 + param_2;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}



/* VA 1002927e */

/* Library Function - Single Match
    ___add_12

   Library: Visual Studio 2003 Release */

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;

  iVar1 = FUN_1002925d(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_1002925d(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_1002925d(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_1002925d(param_1[2],param_2[2],param_1 + 2);
  return;
}



/* VA 100292dc */

void __cdecl FUN_100292dc(uint *param_1)

{
  uint uVar1;
  uint uVar2;

  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] << 1 | uVar2 >> 0x1f;
  return;
}



/* VA 1002930a */

void __cdecl FUN_1002930a(uint *param_1)

{
  uint uVar1;

  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}



/* VA 10029337 */

void __cdecl FUN_10029337(char *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;

  puVar1 = param_3;
  local_8 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      local_14 = *puVar1;
      local_10 = puVar1[1];
      local_c = puVar1[2];
      FUN_100292dc(puVar1);
      FUN_100292dc(puVar1);
      ___add_12(puVar1,&local_14);
      FUN_100292dc(puVar1);
      local_10 = 0;
      local_c = 0;
      local_14 = (uint)*param_1;
      ___add_12(puVar1,&local_14);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  while (puVar1[2] == 0) {
    puVar1[2] = puVar1[1] >> 0x10;
    local_8 = local_8 + 0xfff0;
    puVar1[1] = *puVar1 >> 0x10 | puVar1[1] << 0x10;
    *puVar1 = *puVar1 << 0x10;
  }
  while ((puVar1[2] & 0x8000) == 0) {
    FUN_100292dc(puVar1);
    local_8 = local_8 + 0xffff;
  }
  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_8;
  return;
}



/* VA 100293fe */

undefined4 __thiscall
FUN_100293fe(void *this,ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  char local_60 [23];
  char local_49;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  byte *local_3e;
  ushort local_3a;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint local_8;

  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (byte *)0x0;
  local_c = 0;
  local_18 = 0;
  pbVar8 = param_3;
  while( true ) {
    bVar6 = *pbVar8;
    this = (void *)CONCAT31((int3)((uint)this >> 8),bVar6);
    if ((((bVar6 != 0x20) && (bVar6 != 9)) && (bVar6 != 10)) && (bVar6 != 0xd)) break;
    pbVar8 = pbVar8 + 1;
  }
  iVar1 = 4;
  iVar9 = 0;
  iVar5 = local_14;
LAB_10029455:
  local_14 = iVar5;
  pbVar7 = pbVar8;
  iVar5 = 1;
  bVar6 = *pbVar7;
  pbVar8 = pbVar7 + 1;
  iVar2 = local_14;
  switch(iVar9) {
  case 0:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_10029472:
      local_14 = iVar2;
      iVar9 = 3;
      goto LAB_10029697;
    }
    if (bVar6 == DAT_1003ffe0) goto LAB_10029481;
    if (bVar6 == 0x2b) {
      local_2c = 0;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else if (bVar6 == 0x2d) {
      local_2c = 0x8000;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_10029771;
    }
    goto LAB_10029455;
  case 1:
    local_14 = 1;
    if (('0' < (char)bVar6) && (iVar2 = iVar5, (char)bVar6 < ':')) goto LAB_10029472;
    iVar9 = iVar1;
    if (bVar6 != DAT_1003ffe0) {
      iVar9 = iVar5;
      if ((bVar6 == 0x2b) || (iVar9 = local_14, bVar6 == 0x2d)) goto LAB_10029506;
      iVar9 = iVar5;
      local_14 = iVar5;
      if (bVar6 != 0x30) goto LAB_100294df;
    }
    goto LAB_10029455;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_10029472;
    if (bVar6 == DAT_1003ffe0) {
LAB_10029481:
      iVar9 = 5;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      pbVar7 = param_3;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_10029776;
    }
    goto LAB_10029455;
  case 3:
    local_14 = iVar5;
    while( true ) {
      if (DAT_1003ffdc < 2) {
        uVar3 = (byte)PTR_DAT_1003fdd0[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_1003fdd0;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_100258c0(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      else {
        local_c = local_c + 1;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    iVar9 = iVar1;
    iVar5 = local_14;
    if (bVar6 != DAT_1003ffe0) goto LAB_100295f3;
    goto LAB_10029455;
  case 4:
    local_14 = 1;
    local_28 = 1;
    iVar9 = iVar5;
    if (local_8 == 0) {
      while (iVar5 = local_28, iVar9 = local_14, bVar6 == 0x30) {
        local_c = local_c + -1;
        bVar6 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      }
    }
    while( true ) {
      local_14 = iVar9;
      local_28 = iVar5;
      if (DAT_1003ffdc < 2) {
        uVar3 = (byte)PTR_DAT_1003fdd0[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_1003fdd0;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_100258c0(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      iVar5 = local_28;
      iVar9 = local_14;
    }
LAB_100295f3:
    iVar9 = local_14;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {
LAB_10029506:
      local_14 = iVar9;
      iVar9 = 0xb;
      pbVar8 = pbVar8 + -1;
      iVar5 = local_14;
    }
    else {
LAB_100294df:
      if (((char)bVar6 < 'D') ||
         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_10029771;
      iVar9 = 6;
      iVar5 = local_14;
    }
    goto LAB_10029455;
  case 5:
    local_28 = iVar5;
    if (DAT_1003ffdc < 2) {
      uVar3 = (byte)PTR_DAT_1003fdd0[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_1003fdd0;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_100258c0(this,(uint)bVar6,4);
      this = pbVar7;
    }
    iVar9 = iVar1;
    pbVar7 = param_3;
    if (uVar3 != 0) goto LAB_10029697;
    goto LAB_10029776;
  case 6:
    pbVar7 = pbVar7 + -1;
    this = pbVar7;
    param_3 = pbVar7;
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == 0x2b) goto LAB_100296cc;
      if (bVar6 == 0x2d) goto LAB_100296c0;
      if (bVar6 != 0x30) goto LAB_10029776;
LAB_10029665:
      iVar9 = 8;
      iVar5 = local_14;
      goto LAB_10029455;
    }
    break;
  case 7:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      pbVar7 = param_3;
      if (bVar6 == 0x30) goto LAB_10029665;
      goto LAB_10029776;
    }
    break;
  case 8:
    local_24 = 1;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_10029771;
    break;
  case 9:
    local_24 = 1;
    pbVar7 = (byte *)0x0;
    goto LAB_100296f7;
  default:
    goto switchD_10029461_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      if (bVar6 == 0x2b) {
LAB_100296cc:
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      else {
        param_3 = pbVar7;
        if (bVar6 != 0x2d) goto LAB_10029776;
LAB_100296c0:
        local_1c = -1;
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      goto LAB_10029455;
    }
    iVar9 = 10;
    pbVar8 = pbVar7;
switchD_10029461_caseD_a:
    pbVar7 = pbVar8;
    iVar5 = local_14;
    if (iVar9 != 10) goto LAB_10029455;
    goto LAB_10029776;
  }
  iVar9 = 9;
LAB_10029697:
  pbVar8 = pbVar8 + -1;
  iVar5 = local_14;
  goto LAB_10029455;
LAB_100296f7:
  if (DAT_1003ffdc < 2) {
    uVar3 = (byte)PTR_DAT_1003fdd0[(uint)bVar6 * 2] & 4;
    this = PTR_DAT_1003fdd0;
  }
  else {
    pbVar10 = (byte *)0x4;
    uVar3 = FUN_100258c0(this,(uint)bVar6,4);
    this = pbVar10;
  }
  if (uVar3 == 0) goto LAB_10029741;
  this = (void *)(int)(char)bVar6;
  pbVar7 = (byte *)((int)this + (int)pbVar7 * 10 + -0x30);
  if (0x1450 < (int)pbVar7) goto LAB_10029739;
  bVar6 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  goto LAB_100296f7;
LAB_10029739:
  pbVar7 = (byte *)0x1451;
LAB_10029741:
  while( true ) {
    local_20 = pbVar7;
    if (DAT_1003ffdc < 2) {
      uVar3 = (byte)PTR_DAT_1003fdd0[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_1003fdd0;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_100258c0(this,(uint)bVar6,4);
      this = pbVar7;
    }
    if (uVar3 == 0) break;
    bVar6 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar7 = local_20;
  }
LAB_10029771:
  pbVar7 = pbVar8 + -1;
LAB_10029776:
  *param_2 = (int)pbVar7;
  if (local_14 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
    local_18 = 4;
    goto LAB_10029884;
  }
  pcVar4 = local_10;
  if (0x18 < local_8) {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    pcVar4 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
  }
  else {
    while (pcVar4 = pcVar4 + -1, *pcVar4 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_10029337(local_60,local_8,(uint *)&local_44);
    pbVar8 = local_20;
    if (local_1c < 0) {
      pbVar8 = (byte *)-(int)local_20;
    }
    pbVar8 = pbVar8 + local_c;
    if (local_24 == 0) {
      pbVar8 = pbVar8 + param_5;
    }
    if (local_28 == 0) {
      pbVar8 = pbVar8 + -param_6;
    }
    if ((int)pbVar8 < 0x1451) {
      if (-0x1451 < (int)pbVar8) {
        FUN_10029ef2((int *)&local_44,(uint)pbVar8,param_4);
        param_3 = (byte *)CONCAT22(uStack_40,uStack_42);
        goto LAB_10029809;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (ushort)param_3;
    local_3e = param_3;
    local_44 = local_3a;
  }
LAB_10029809:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44 = 0;
      local_3a = 0;
      local_3e = (byte *)0x0;
      param_3 = (byte *)0x0;
      local_18 = 1;
    }
  }
  else {
    param_3 = (byte *)0x0;
    local_3a = 0x7fff;
    local_3e = (byte *)0x80000000;
    local_44 = 0;
    local_18 = 2;
  }
LAB_10029884:
  *(byte **)(param_1 + 3) = local_3e;
  *(byte **)(param_1 + 1) = param_3;
  param_1[5] = local_3a | (ushort)local_2c;
  *param_1 = local_44;
  return local_18;
}



/* VA 100298cf */

undefined4 __cdecl
FUN_100298cf(uint param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  uint uVar2;
  short *psVar3;
  char cVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined4 local_12;
  undefined4 local_e;
  undefined1 local_a;
  char cStack_9;
  undefined4 local_8;

  psVar3 = param_6;
  uVar5 = param_3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_8 = 1;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 != 0) || (param_2 != 0)) || (param_1 != 0)) {
    if ((short)uVar5 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_100299c4;
          pcVar11 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_100299c4:
            pcVar11 = "1#QNAN";
            goto LAB_100299c9;
          }
          pcVar11 = "1#IND";
        }
        FUN_1001f150((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 5;
      }
      else {
        pcVar11 = "1#SNAN";
LAB_100299c9:
        FUN_1001f150((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 6;
      }
      return 0;
    }
    local_14 = 0;
    local_a = (undefined1)uVar5;
    cStack_9 = (char)(uVar5 >> 8);
    sVar8 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                   0x10);
    local_e = param_2;
    local_12 = param_1;
    FUN_10029ef2((int *)&local_14,-(int)sVar8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar8 = sVar8 + 1;
      FUN_10029cd2((int *)&local_14,(int *)&local_20);
    }
    *psVar3 = sVar8;
    iVar10 = param_4;
    if (((param_5 & 1) == 0) || (iVar10 = param_4 + sVar8, 0 < param_4 + sVar8)) {
      if (0x15 < iVar10) {
        iVar10 = 0x15;
      }
      iVar9 = CONCAT11(cStack_9,local_a) - 0x3ffe;
      local_a = 0;
      cStack_9 = '\0';
      param_6 = (short *)0x8;
      do {
        FUN_100292dc((uint *)&local_14);
        param_6 = (short *)((int)param_6 + -1);
      } while (param_6 != (short *)0x0);
      if (iVar9 < 0) {
        param_6 = (short *)0x0;
        for (uVar5 = -iVar9 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
          FUN_1002930a((uint *)&local_14);
        }
      }
      param_4 = iVar10 + 1;
      psVar6 = psVar3 + 2;
      param_6 = psVar6;
      uVar5 = local_12;
      uVar2 = local_e;
      if (0 < param_4) {
        do {
          local_e._2_2_ = (undefined2)(uVar2 >> 0x10);
          local_e._0_2_ = (undefined2)uVar2;
          local_12._2_2_ = (undefined2)(uVar5 >> 0x10);
          local_12._0_2_ = (undefined2)uVar5;
          param_1 = CONCAT22((undefined2)local_12,local_14);
          param_2 = CONCAT22((undefined2)local_e,local_12._2_2_);
          param_3 = CONCAT13(cStack_9,CONCAT12(local_a,local_e._2_2_));
          local_12 = uVar5;
          local_e = uVar2;
          FUN_100292dc((uint *)&local_14);
          FUN_100292dc((uint *)&local_14);
          ___add_12((uint *)&local_14,&param_1);
          FUN_100292dc((uint *)&local_14);
          cVar4 = cStack_9;
          cStack_9 = '\0';
          psVar6 = (short *)((int)param_6 + 1);
          param_4 = param_4 + -1;
          *(char *)param_6 = cVar4 + '0';
          param_6 = psVar6;
          uVar5 = local_12;
          uVar2 = local_e;
        } while (param_4 != 0);
      }
      psVar7 = psVar6 + -1;
      psVar1 = psVar3 + 2;
      if ('4' < *(char *)((int)psVar6 + -1)) {
        for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
          if ((char)*psVar7 != '9') {
            if (psVar1 <= psVar7) goto LAB_10029b21;
            break;
          }
          *(char *)psVar7 = '0';
        }
        psVar7 = (short *)((int)psVar7 + 1);
        *psVar3 = *psVar3 + 1;
LAB_10029b21:
        *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_10029b23:
        cVar4 = ((char)psVar7 - (char)psVar3) + -3;
        *(char *)((int)psVar3 + 3) = cVar4;
        *(undefined1 *)(cVar4 + 4 + (int)psVar3) = 0;
        return local_8;
      }
      for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
        if ((char)*psVar7 != '0') {
          if (psVar1 <= psVar7) goto LAB_10029b23;
          break;
        }
      }
      *psVar3 = 0;
      *(undefined1 *)(psVar3 + 1) = 0x20;
      *(undefined1 *)((int)psVar3 + 3) = 1;
      *(char *)psVar1 = '0';
      goto LAB_10029b59;
    }
  }
  *psVar3 = 0;
  *(undefined1 *)(psVar3 + 1) = 0x20;
  *(undefined1 *)((int)psVar3 + 3) = 1;
  *(undefined1 *)(psVar3 + 2) = 0x30;
LAB_10029b59:
  *(undefined1 *)((int)psVar3 + 5) = 0;
  return 1;
}



/* VA 10029b70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10029b70(byte *param_1,char *param_2,void *param_3)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  void *this;
  uint uVar7;
  bool bVar8;
  uint uVar9;

  iVar2 = _DAT_10043bf8;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_10043a6c == 0) {
      do {
        bVar3 = *param_1;
        cVar1 = *param_2;
        uVar4 = CONCAT11(bVar3,cVar1);
        if (bVar3 == 0) break;
        uVar4 = CONCAT11(bVar3,cVar1);
        uVar7 = (uint)uVar4;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar7 = (uint)CONCAT11(bVar3 + 0x20,cVar1);
        }
        uVar4 = (ushort)uVar7;
        bVar3 = (byte)uVar7;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar4 = (ushort)CONCAT31((int3)(uVar7 >> 8),bVar3 + 0x20);
        }
        bVar3 = (byte)(uVar4 >> 8);
        bVar8 = bVar3 < (byte)uVar4;
        if (bVar3 != (byte)uVar4) goto LAB_10029bcf;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_10029bcf:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_10043bf8 = _DAT_10043bf8 + 1;
      UNLOCK();
      bVar8 = 0 < DAT_10043bf4;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_10043bf8 = iVar2;
        FUN_10022e54(0x13);
      }
      uVar9 = (uint)bVar8;
      uVar5 = 0;
      uVar7 = 0;
      do {
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_1);
        uVar7 = CONCAT31((int3)(uVar7 >> 8),*param_2);
        if ((uVar5 == 0) || (uVar7 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar7 = FUN_10027ae4(param_3,uVar7);
        uVar5 = FUN_10027ae4(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_10029c45;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_10029c45:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_10043bf8 = _DAT_10043bf8 + -1;
        UNLOCK();
      }
      else {
        FUN_10022eb5(0x13);
      }
    }
  }
  return uVar6;
}



/* VA 10029c71 */

int __cdecl FUN_10029c71(uint param_1,int param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  byte bVar3;

  bVar1 = *(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      pDVar2 = FUN_10020fd2();
      *pDVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&DAT_10043c00)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}



/* VA 10029cd2 */

void __cdecl FUN_10029cd2(int *param_1,int *param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  ushort uVar11;
  byte local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  short local_24;
  undefined2 uStack_22;
  undefined2 local_20;
  undefined1 uStack_1e;
  byte bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  ushort *local_c;
  short *local_8;

  piVar5 = param_2;
  piVar4 = param_1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  uVar7 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar10 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar11 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar6 = (ushort)uVar7;
  piVar1 = (int *)(uVar10 + uVar7);
  if (((uVar6 < 0x7fff) && (uVar9 = (ushort)uVar10, uVar9 < 0x7fff)) && ((ushort)piVar1 < 0xbffe)) {
    if ((ushort)piVar1 < 0x3fc0) {
LAB_10029d75:
      piVar4[2] = 0;
      piVar4[1] = 0;
      *piVar4 = 0;
      return;
    }
    if (((uVar6 != 0) || (piVar1 = (int *)((int)piVar1 + 1), (param_1[2] & 0x7fffffffU) != 0)) ||
       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {
      param_1 = piVar1;
      if (((uVar9 == 0) && (param_1 = (int *)((int)param_1 + 1), (param_2[2] & 0x7fffffffU) == 0))
         && ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_10029d75;
      local_14 = 0;
      local_8 = &local_24;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_c = (ushort *)(local_14 * 2 + (int)piVar4);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = param_2;
          do {
            iVar8 = FUN_1002925d(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
                                 (uint *)(local_8 + -2));
            if (iVar8 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (0 < (int)param_2);
      param_1 = (int *)((int)param_1 + 0xc002);
      if ((short)(ushort)param_1 < 1) {
LAB_10029e29:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          iVar8 = -(int)(short)(ushort)param_1;
          param_1._0_2_ = (ushort)param_1 + (short)iVar8;
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_1002930a((uint *)&local_28);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          FUN_100292dc((uint *)&local_28);
          param_1 = (int *)((int)param_1 + 0xffff);
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_10029e29;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (sVar2 = CONCAT11(bStack_1d,uStack_1e), iVar3 = CONCAT22(local_20,uStack_22),
         iVar8 = CONCAT22(local_24,uStack_26),
         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,uStack_26) == -1) {
          iVar8 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              param_1._0_2_ = (ushort)param_1 + 1;
              sVar2 = -0x8000;
              iVar3 = 0;
              iVar8 = 0;
            }
            else {
              sVar2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              iVar3 = 0;
              iVar8 = 0;
            }
          }
          else {
            sVar2 = CONCAT11(bStack_1d,uStack_1e);
            iVar3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          iVar8 = CONCAT22(local_24,uStack_26) + 1;
          sVar2 = CONCAT11(bStack_1d,uStack_1e);
          iVar3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint)iVar8 >> 0x10);
      uStack_26 = (undefined2)iVar8;
      local_20 = (undefined2)((uint)iVar3 >> 0x10);
      uStack_22 = (undefined2)iVar3;
      bStack_1d = (byte)((ushort)sVar2 >> 8);
      uStack_1e = (undefined1)sVar2;
      if (0x7ffe < (ushort)param_1) goto LAB_10029ed2;
      uVar6 = (ushort)param_1 | uVar11;
      *(undefined2 *)piVar4 = uStack_26;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_10029ed2:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}



/* VA 10029ef2 */

void __cdecl FUN_10029ef2(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 uStack_a;
  int iStack_8;

  iVar3 = 0x10040380;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      iVar3 = 0x100404e0;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      iVar3 = iVar3 + 0x54;
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar1;
      if (uVar2 != 0) {
        piVar4 = (int *)(iVar3 + uVar2 * 0xc);
        if (0x7fff < *(ushort *)(iVar3 + uVar2 * 0xc)) {
          local_10 = (undefined2)*piVar4;
          local_e._0_2_ = (undefined2)((uint)*piVar4 >> 0x10);
          local_e._2_2_ = (undefined2)piVar4[1];
          uStack_a = (undefined2)((uint)piVar4[1] >> 0x10);
          iStack_8 = piVar4[2];
          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;
          piVar4 = (int *)&local_10;
        }
        FUN_10029cd2(param_1,piVar4);
      }
    }
  }
  return;
}



/* VA 10029f6e */

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x10029f6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}



/* VA 10029f74 */

short GetFileTitleA(LPCSTR param_1,LPSTR Buf,WORD cchSize)

{
  short sVar1;

                    /* WARNING: Could not recover jumptable at 0x10029f74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = GetFileTitleA(param_1,Buf,cchSize);
  return sVar1;
}



/* VA 10029f7a */

BOOL ClosePrinter(HANDLE hPrinter)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x10029f7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ClosePrinter(hPrinter);
  return BVar1;
}



/* VA 10029f80 */

LONG DocumentPropertiesA(HWND hWnd,HANDLE hPrinter,LPSTR pDeviceName,PDEVMODEA pDevModeOutput,
                        PDEVMODEA pDevModeInput,DWORD fMode)

{
  LONG LVar1;

                    /* WARNING: Could not recover jumptable at 0x10029f80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = DocumentPropertiesA(hWnd,hPrinter,pDeviceName,pDevModeOutput,pDevModeInput,fMode);
  return LVar1;
}



/* VA 10029f86 */

BOOL OpenPrinterA(LPSTR pPrinterName,LPHANDLE phPrinter,LPPRINTER_DEFAULTSA pDefault)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x10029f86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = OpenPrinterA(pPrinterName,phPrinter,pDefault);
  return BVar1;
}



/* VA 10029f8c */

undefined4 * __thiscall FUN_10029f8c(void *this,char param_1,size_t param_2)

{
  *(undefined **)this = PTR_DAT_1003d148;
  if (0 < (int)param_2) {
    FUN_1002afd5(this,param_2);
    _memset(*(void **)this,(int)param_1,param_2);
  }
  return this;
}



/* VA 10029fc0 */

undefined4 FUN_10029fc0(undefined4 param_1)

{
  FUN_10029fe3();
  return param_1;
}



/* VA 10029fe3 */

undefined4 FUN_10029fe3(void)

{
  uint uVar1;
  uint uVar2;
  int *this;
  int iVar3;
  int unaff_EBP;

  FUN_10020434();
  iVar3 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  uVar2 = *(uint *)(unaff_EBP + 0x10);
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  uVar1 = *(uint *)(*this + -8);
  if ((int)uVar1 < (int)(iVar3 + uVar2)) {
    uVar2 = uVar1 - iVar3;
  }
  if ((int)uVar1 < iVar3) {
    uVar2 = 0;
  }
  if ((iVar3 == 0) && (uVar2 == uVar1)) {
    FUN_1002aedd(*(void **)(unaff_EBP + 8),this);
  }
  else {
    *(undefined **)(unaff_EBP + 0xc) = PTR_DAT_1003d148;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_1002b192(this,(undefined4 *)(unaff_EBP + 0xc),uVar2,iVar3,0);
    FUN_1002aedd(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    FUN_1002b168((int *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



/* VA 1002a079 */

undefined4 FUN_1002a079(void)

{
  int iVar1;
  undefined4 uVar2;
  int *this;
  uint uVar3;
  int unaff_EBP;

  FUN_10020434();
  uVar3 = *(uint *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  iVar1 = *this;
  if ((int)uVar3 < *(int *)(iVar1 + -8)) {
    *(undefined **)(unaff_EBP + 0xc) = PTR_DAT_1003d148;
    iVar1 = *(int *)(iVar1 + -8);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_1002b192(this,(undefined4 *)(unaff_EBP + 0xc),uVar3,iVar1 - uVar3,0);
    FUN_1002aedd(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    FUN_1002b168((int *)(unaff_EBP + 0xc));
    uVar2 = *(undefined4 *)(unaff_EBP + 8);
  }
  else {
    FUN_1002aedd(*(void **)(unaff_EBP + 8),this);
    uVar2 = *(undefined4 *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 1002a0f5 */

undefined4 FUN_1002a0f5(void)

{
  uint uVar1;
  undefined4 uVar2;
  int *this;
  int unaff_EBP;

  FUN_10020434();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  if ((int)uVar1 < *(int *)(*this + -8)) {
    *(undefined **)(unaff_EBP + 0xc) = PTR_DAT_1003d148;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_1002b192(this,(undefined4 *)(unaff_EBP + 0xc),uVar1,0,0);
    FUN_1002aedd(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    FUN_1002b168((int *)(unaff_EBP + 0xc));
    uVar2 = *(undefined4 *)(unaff_EBP + 8);
  }
  else {
    FUN_1002aedd(*(void **)(unaff_EBP + 8),this);
    uVar2 = *(undefined4 *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 1002a16d */

int __thiscall FUN_1002a16d(void *this,byte param_1)

{
  byte *pbVar1;
  int iVar2;

  pbVar1 = FUN_1002093b(*(byte **)this,(uint)param_1);
  if (pbVar1 == (byte *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = (int)pbVar1 - *(int *)this;
  }
  return iVar2;
}



/* VA 1002a18f */

void __thiscall FUN_1002a18f(void *this,char *param_1)

{
  FUN_1002a19d(this,param_1,0);
  return;
}



/* VA 1002a19d */

int __thiscall FUN_1002a19d(void *this,char *param_1,int param_2)

{
  byte *pbVar1;

  if ((param_2 <= *(int *)(*(int *)this + -8)) &&
     (pbVar1 = FUN_100208c5((byte *)(*(int *)this + param_2),param_1), pbVar1 != (byte *)0x0)) {
    return (int)pbVar1 - *(int *)this;
  }
  return -1;
}



/* VA 1002a1c8 */

void __thiscall FUN_1002a1c8(void *this,byte *param_1,size_t *param_2)

{
  size_t *psVar1;
  size_t *psVar2;
  byte bVar3;
  char cVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  undefined3 extraout_var;
  byte *pbVar8;
  size_t sVar9;
  size_t sVar10;
  uint local_10;
  int local_c;
  size_t local_8;

  psVar1 = param_2;
  local_c = 0;
  pbVar5 = param_1;
  do {
    if (*pbVar5 == 0) {
      FUN_1002b537(this,local_c);
      FUN_100209ad(*(undefined1 **)this,param_1,psVar1);
      FUN_1002b586(this,-1);
      return;
    }
    if (*pbVar5 == 0x25) {
      pbVar8 = pbVar5;
      pbVar5 = FUN_10020574(pbVar5);
      bVar3 = *pbVar5;
      if (bVar3 == 0x25) goto LAB_1002a4cd;
      sVar10 = 0;
      local_8 = 0;
      if (bVar3 == 0) {
LAB_1002a250:
        local_8 = FUN_1001fd6d(pbVar8,pbVar5);
        while ((*pbVar5 != 0 && (uVar6 = FUN_10020b03((void *)(int)(char)*pbVar5), uVar6 != 0))) {
          pbVar5 = FUN_10020574(pbVar5);
        }
      }
      else {
        do {
          if (bVar3 == 0x23) {
            local_c = local_c + 2;
          }
          else if (bVar3 == 0x2a) {
            local_8 = *param_2;
            param_2 = param_2 + 1;
          }
          else if ((((bVar3 != 0x2d) && (bVar3 != 0x2b)) && (bVar3 != 0x30)) && (bVar3 != 0x20))
          break;
          pbVar8 = pbVar5;
          pbVar5 = FUN_10020574(pbVar5);
          bVar3 = *pbVar5;
        } while (bVar3 != 0);
        if (local_8 == 0) goto LAB_1002a250;
      }
      sVar9 = 0;
      if (*pbVar5 == 0x2e) {
        pbVar8 = pbVar5;
        pbVar5 = FUN_10020574(pbVar5);
        if (*pbVar5 == 0x2a) {
          sVar9 = *param_2;
          pbVar5 = FUN_10020574(pbVar5);
          param_2 = param_2 + 1;
        }
        else {
          sVar9 = FUN_1001fd6d(pbVar8,pbVar5);
          while ((*pbVar5 != 0 && (uVar6 = FUN_10020b03((void *)(int)(char)*pbVar5), uVar6 != 0))) {
            pbVar5 = FUN_10020574(pbVar5);
          }
        }
      }
      psVar2 = param_2;
      local_10 = 0;
      iVar7 = FUN_10020a14(pbVar5,&DAT_10034408,3);
      if (iVar7 == 0) {
        pbVar5 = pbVar5 + 3;
        local_10 = 0x40000;
      }
      else {
        bVar3 = *pbVar5;
        if (((bVar3 != 0x46) && (bVar3 != 0x4c)) && (bVar3 != 0x4e)) {
          if (bVar3 == 0x68) {
            local_10 = 0x10000;
          }
          else {
            if (bVar3 != 0x6c) goto LAB_1002a321;
            local_10 = 0x20000;
          }
        }
        pbVar5 = FUN_10020574(pbVar5);
      }
LAB_1002a321:
      uVar6 = (int)(char)*pbVar5 | local_10;
      if ((int)uVar6 < 0x10064) {
        if ((uVar6 == 0x10063) || (uVar6 == 0x43)) {
LAB_1002a3ec:
          sVar10 = 2;
        }
        else {
          if (uVar6 == 0x53) goto LAB_1002a3d5;
          if (uVar6 == 99) goto LAB_1002a3ec;
          if (uVar6 != 0x73) {
            if (uVar6 == 0x10043) goto LAB_1002a3ec;
            if (uVar6 != 0x10053) goto LAB_1002a371;
          }
LAB_1002a3f5:
          if ((LPCSTR)*param_2 == (LPCSTR)0x0) goto LAB_1002a403;
          sVar10 = lstrlenA((LPCSTR)*param_2);
LAB_1002a40f:
          param_2 = param_2 + 1;
          if ((int)sVar10 < 1) {
            sVar10 = 1;
          }
          if (sVar10 == 0) goto LAB_1002a371;
        }
LAB_1002a421:
        param_2 = psVar2 + 1;
        if ((sVar9 != 0) && ((int)sVar9 <= (int)sVar10)) {
          sVar10 = sVar9;
        }
        if ((int)sVar10 <= (int)local_8) {
          sVar10 = local_8;
        }
      }
      else {
        if (uVar6 == 0x10073) goto LAB_1002a3f5;
        if (uVar6 == 0x20043) goto LAB_1002a3ec;
        if (uVar6 == 0x20053) {
LAB_1002a3d5:
          if ((short *)*param_2 != (short *)0x0) {
            sVar10 = FUN_10020415((short *)*param_2);
            goto LAB_1002a40f;
          }
LAB_1002a403:
          sVar10 = 6;
          goto LAB_1002a421;
        }
        if (uVar6 == 0x20063) goto LAB_1002a3ec;
        if (uVar6 == 0x20073) goto LAB_1002a3d5;
LAB_1002a371:
        bVar3 = *pbVar5;
        if ((char)bVar3 < 'j') {
          if (bVar3 == 0x69) goto LAB_1002a4b8;
          if (bVar3 == 0x47) goto LAB_1002a482;
          if ((bVar3 == 0x58) || (bVar3 == 100)) goto LAB_1002a4b8;
          if (bVar3 == 0x65) {
LAB_1002a482:
            param_2 = param_2 + 2;
            sVar10 = 0x80;
            goto LAB_1002a4ab;
          }
          if (bVar3 != 0x66) {
            if (bVar3 != 0x67) goto LAB_1002a4c8;
            goto LAB_1002a482;
          }
          FUN_1001fa90();
          param_2 = param_2 + 2;
          FUN_1001fa34(&stack0xffffffdc,(byte *)"%*.*f");
          local_8 = _strlen(&stack0xffffffdc);
        }
        else {
          if (bVar3 == 0x6e) {
            param_2 = param_2 + 1;
            goto LAB_1002a4c8;
          }
          if (bVar3 == 0x6f) {
LAB_1002a4b8:
            if ((local_10 & 0x40000) == 0) goto LAB_1002a4a4;
            param_2 = param_2 + 2;
          }
          else {
            if (bVar3 != 0x70) {
              if ((bVar3 != 0x75) && (bVar3 != 0x78)) goto LAB_1002a4c8;
              goto LAB_1002a4b8;
            }
LAB_1002a4a4:
            param_2 = param_2 + 1;
          }
          sVar10 = 0x20;
LAB_1002a4ab:
          local_8 = local_8 + sVar9;
          if ((int)local_8 < (int)sVar10) goto LAB_1002a4c8;
        }
        sVar10 = local_8;
      }
LAB_1002a4c8:
      local_c = local_c + sVar10;
    }
    else {
LAB_1002a4cd:
      cVar4 = FUN_100209fe(pbVar5);
      local_c = local_c + CONCAT31(extraout_var,cVar4);
    }
    pbVar5 = FUN_10020574(pbVar5);
  } while( true );
}



/* VA 1002a515 */

void __cdecl FUN_1002a515(void *param_1,byte *param_2)

{
  FUN_1002a1c8(param_1,param_2,(size_t *)&stack0x0000000c);
  return;
}



/* VA 1002a528 */

/* Library Function - Single Match
    public: void __thiscall CSimpleException::InitString(void)

   Library: Visual Studio 2015 Release */

void __thiscall CSimpleException::InitString(CSimpleException *this)

{
  int iVar1;

  *(undefined4 *)(this + 0xc) = 1;
  iVar1 = FUN_1002c342(*(UINT *)(this + 0x94),(LPSTR)(this + 0x14),0x80);
  *(uint *)(this + 0x10) = (uint)(iVar1 != 0);
  return;
}



/* VA 1002a594 */

void FUN_1002a594(void)

{
  undefined *local_8;

  local_8 = &DAT_100419c0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_8,&DAT_10036fa0);
}



/* VA 1002a5ad */

void FUN_1002a5ad(void)

{
  undefined *local_8;

  local_8 = &DAT_10041928;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_8,&DAT_10036fe8);
}



/* VA 1002a5c6 */

undefined4 * __thiscall
FUN_1002a5c6(void *this,int param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_8;

  local_28 = param_6;
  local_24 = param_5;
  local_20 = param_4;
  local_1c = param_3;
  local_18 = param_2 + -1;
  local_14 = param_1 + -0x76c;
  local_8 = param_7;
  uVar1 = FUN_10021db0(&local_28);
  *(undefined4 *)this = uVar1;
  return this;
}



/* VA 1002a612 */

undefined4 * __thiscall FUN_1002a612(void *this,ushort *param_1,undefined4 param_2)

{
  if (*param_1 < 0x76c) {
    *(undefined4 *)this = 0;
  }
  else {
    FUN_1002a5c6(&param_1,(uint)*param_1,(uint)param_1[1],(uint)param_1[3],(uint)param_1[4],
                 (uint)param_1[5],(uint)param_1[6],param_2);
    *(ushort **)this = param_1;
  }
  return this;
}



/* VA 1002a65e */

undefined4 * __thiscall FUN_1002a65e(void *this,FILETIME *param_1,undefined4 param_2)

{
  BOOL BVar1;
  _SYSTEMTIME local_1c;
  _FILETIME local_c;

  BVar1 = FileTimeToLocalFileTime(param_1,&local_c);
  if ((BVar1 != 0) && (BVar1 = FileTimeToSystemTime(&local_c,&local_1c), BVar1 != 0)) {
    FUN_1002a612(&param_1,&local_1c.wYear,param_2);
    *(FILETIME **)this = param_1;
    return this;
  }
  *(undefined4 *)this = 0;
  return this;
}



/* VA 1002a6aa */

void __thiscall FUN_1002a6aa(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_1003441c;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* VA 1002a6cd */

undefined * __thiscall FUN_1002a6cd(void *this,byte param_1)

{
  FUN_1002a71e();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1002a6e9 */

void __fastcall FUN_1002a6e9(int param_1)

{
  undefined4 *puVar1;

  for (puVar1 = *(undefined4 **)(param_1 + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    FUN_1002b168(puVar1 + 2);
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_1002abbf(*(undefined4 **)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* VA 1002a71e */

void FUN_1002a71e(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_1003441c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002a6e9((int)extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002a747 */

undefined4 * __thiscall FUN_1002a747(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;

  if (*(int *)((int)this + 0x10) == 0) {
    iVar1 = FUN_1002ab9f((undefined4 *)((int)this + 0x14),*(int *)((int)this + 0x18),0xc);
    iVar3 = *(int *)((int)this + 0x18);
    puVar2 = (undefined4 *)(iVar1 + -8 + iVar3 * 0xc);
    if (-1 < iVar3 + -1) {
      do {
        *puVar2 = *(undefined4 *)((int)this + 0x10);
        *(undefined4 **)((int)this + 0x10) = puVar2;
        puVar2 = puVar2 + -3;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  puVar2 = *(undefined4 **)((int)this + 0x10);
  *(undefined4 *)((int)this + 0x10) = *puVar2;
  puVar2[1] = param_1;
  *puVar2 = param_2;
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  FUN_100200e0(puVar2 + 2,&PTR_DAT_1003d148,4);
  return puVar2;
}



/* VA 1002a7b2 */

/* Library Function - Multiple Matches With Same Base Name
    protected: void __thiscall CMapStringToOb::FreeAssoc(struct CMapStringToOb::CAssoc *)
    protected: void __thiscall CMapStringToPtr::FreeAssoc(struct CMapStringToPtr::CAssoc *)

   Library: Visual Studio 2003 Release */

void __thiscall FreeAssoc(void *this,undefined4 *param_1)

{
  int *piVar1;

  FUN_1002b168(param_1 + 2);
  *param_1 = *(undefined4 *)((int)this + 0x10);
  piVar1 = (int *)((int)this + 0xc);
  *piVar1 = *piVar1 + -1;
  *(undefined4 **)((int)this + 0x10) = param_1;
  if (*piVar1 == 0) {
    FUN_1002a6e9((int)this);
  }
  return;
}



/* VA 1002a7db */

/* Library Function - Multiple Matches With Same Base Name
    public: struct __POSITION * __thiscall CStringList::AddTail(class ATL::CStringT<char,class
   StrTraitMFC<char,class ATL::ChTraitsCRT<char> > > const &)
    public: struct __POSITION * __thiscall CStringList::AddTail(class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > const &)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

undefined4 * __thiscall AddTail(void *this,int *param_1)

{
  undefined4 *puVar1;

  puVar1 = FUN_1002a747(this,*(undefined4 *)((int)this + 8),0);
  FUN_1002b255(puVar1 + 2,param_1);
  if (*(undefined4 **)((int)this + 8) == (undefined4 *)0x0) {
    *(undefined4 **)((int)this + 4) = puVar1;
  }
  else {
    **(undefined4 **)((int)this + 8) = puVar1;
  }
  *(undefined4 **)((int)this + 8) = puVar1;
  return puVar1;
}



/* VA 1002a80f */

void __thiscall FUN_1002a80f(void *this,int *param_1)

{
  if (param_1 == *(int **)((int)this + 4)) {
    *(int *)((int)this + 4) = *param_1;
  }
  else {
    *(int *)param_1[1] = *param_1;
  }
  if (param_1 == *(int **)((int)this + 8)) {
    *(int *)((int)this + 8) = param_1[1];
  }
  else {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  FreeAssoc(this,param_1);
  return;
}



/* VA 1002a846 */

undefined4 * __thiscall FUN_1002a846(void *this,int param_1)

{
  undefined4 *puVar1;

  if ((param_1 < *(int *)((int)this + 0xc)) && (-1 < param_1)) {
    puVar1 = *(undefined4 **)((int)this + 4);
    for (; param_1 != 0; param_1 = param_1 + -1) {
      puVar1 = (undefined4 *)*puVar1;
    }
  }
  else {
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}



/* VA 1002a86c */

undefined4 * __thiscall FUN_1002a86c(void *this,byte *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;

  if (param_2 == (undefined4 *)0x0) {
    puVar2 = *(undefined4 **)((int)this + 4);
  }
  else {
    puVar2 = (undefined4 *)*param_2;
  }
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = FUN_1001f09a((byte *)puVar2[2],param_1);
    if (iVar1 == 0) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return puVar2;
}



/* VA 1002a8a1 */

void FUN_1002a8a1(void)

{
  void *this;
  void *pvVar1;
  void *this_00;
  int unaff_EBP;
  undefined4 *puVar2;

  FUN_10020434();
  this = *(void **)(unaff_EBP + 8);
  if ((~*(uint *)((int)this + 0x14) & 1) == 0) {
    pvVar1 = FUN_1002fd91(this);
    *(undefined **)(unaff_EBP + 8) = PTR_DAT_1003d148;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    for (; pvVar1 != (void *)0x0; pvVar1 = (void *)((int)pvVar1 + -1)) {
      FUN_1002f9ee(this,(undefined4 *)(unaff_EBP + 8));
      AddTail(this_00,(int *)(unaff_EBP + 8));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_1002b168((int *)(unaff_EBP + 8));
  }
  else {
    FUN_1002fd63(this,*(uint *)((int)this_00 + 0xc));
    for (puVar2 = *(undefined4 **)((int)this_00 + 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      FUN_1002f91e(this,puVar2 + 2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002a92e */

void __fastcall FUN_1002a92e(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_100345bc;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  return;
}



/* VA 1002a945 */

undefined * __thiscall FUN_1002a945(void *this,byte param_1)

{
  FUN_1002a961();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1002a961 */

void FUN_1002a961(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_100345bc;
  iVar1 = extraout_ECX[2];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002a99f((int *)extraout_ECX[1],iVar1);
  FUN_1002becb((undefined *)extraout_ECX[1]);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002a99f */

void __cdecl FUN_1002a99f(int *param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_1002b168(param_1);
    param_1 = param_1 + 1;
  }
  return;
}



/* VA 1002a9c1 */

void __thiscall FUN_1002a9c1(void *this,int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;

  if (param_2 != -1) {
    *(int *)((int)this + 0x10) = param_2;
  }
  if (param_1 == 0) {
    FUN_1002a99f(*(int **)((int)this + 4),*(int *)((int)this + 8));
    FUN_1002becb(*(undefined **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)((int)this + 8) = 0;
    return;
  }
  iVar3 = *(int *)((int)this + 4);
  if (iVar3 == 0) {
    puVar2 = FUN_1002bea2(param_1 << 2);
    *(undefined4 **)((int)this + 4) = puVar2;
    FUN_1002aade(puVar2,param_1);
    *(int *)((int)this + 0xc) = param_1;
LAB_1002aa23:
    *(int *)((int)this + 8) = param_1;
    return;
  }
  if (param_1 <= *(int *)((int)this + 0xc)) {
    iVar1 = *(int *)((int)this + 8);
    if (iVar1 < param_1) {
      FUN_1002aade((undefined4 *)(iVar3 + iVar1 * 4),param_1 - iVar1);
    }
    else if (param_1 < iVar1) {
      FUN_1002a99f((int *)(iVar3 + param_1 * 4),iVar1 - param_1);
    }
    goto LAB_1002aa23;
  }
  iVar3 = *(int *)((int)this + 0x10);
  if (iVar3 != 0) goto LAB_1002aa85;
  iVar3 = *(int *)((int)this + 8) / 8;
  if (3 < iVar3) {
    if (0x400 < iVar3) {
      iVar3 = 0x400;
      goto LAB_1002aa85;
    }
    if (3 < iVar3) goto LAB_1002aa85;
  }
  iVar3 = 4;
LAB_1002aa85:
  param_2 = iVar3 + *(int *)((int)this + 0xc);
  if (param_2 <= param_1) {
    param_2 = param_1;
  }
  puVar2 = FUN_1002bea2(param_2 << 2);
  FUN_100200e0(puVar2,*(undefined4 **)((int)this + 4),*(int *)((int)this + 8) << 2);
  FUN_1002aade(puVar2 + *(int *)((int)this + 8),param_1 - *(int *)((int)this + 8));
  FUN_1002becb(*(undefined **)((int)this + 4));
  *(undefined4 **)((int)this + 4) = puVar2;
  *(int *)((int)this + 8) = param_1;
  *(int *)((int)this + 0xc) = param_2;
  return;
}



/* VA 1002aade */

void __cdecl FUN_1002aade(undefined4 *param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_100200e0(param_1,&PTR_DAT_1003d148,4);
    param_1 = param_1 + 1;
  }
  return;
}



/* VA 1002ab0a */

void __thiscall FUN_1002ab0a(void *this,int param_1,LPCSTR param_2)

{
  if (*(int *)((int)this + 8) <= param_1) {
    FUN_1002a9c1(this,param_1 + 1,-1);
  }
  FUN_1002b2a5((void *)(*(int *)((int)this + 4) + param_1 * 4),param_2);
  return;
}



/* VA 1002ab36 */

void __thiscall FUN_1002ab36(void *this,void *param_1)

{
  void *pvVar1;
  int iVar2;

  if ((~*(uint *)((int)param_1 + 0x14) & 1) == 0) {
    pvVar1 = FUN_1002fd91(param_1);
    FUN_1002a9c1(this,(int)pvVar1,-1);
    iVar2 = 0;
    if (0 < *(int *)((int)this + 8)) {
      do {
        FUN_1002f9ee(param_1,(undefined4 *)(*(int *)((int)this + 4) + iVar2 * 4));
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)((int)this + 8));
    }
  }
  else {
    FUN_1002fd63(param_1,*(uint *)((int)this + 8));
    iVar2 = 0;
    if (0 < *(int *)((int)this + 8)) {
      do {
        FUN_1002f91e(param_1,(int *)(*(int *)((int)this + 4) + iVar2 * 4));
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)((int)this + 8));
    }
  }
  return;
}



/* VA 1002ab9f */

void FUN_1002ab9f(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;

  puVar1 = FUN_1002bea2(param_2 * param_3 + 4);
  *puVar1 = *param_1;
  *param_1 = puVar1;
  return;
}



/* VA 1002abbf */

void __fastcall FUN_1002abbf(undefined4 *param_1)

{
  undefined4 *puVar1;

  while (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    FUN_1002becb((undefined *)param_1);
    param_1 = puVar1;
  }
  return;
}



/* VA 1002abd5 */

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall CObList::RemoveAll(void)
    public: void __thiscall CPtrList::RemoveAll(void)

   Library: Visual Studio 2015 Release */

void __fastcall RemoveAll(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_1002abbf(*(undefined4 **)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* VA 1002abf5 */

void __thiscall FUN_1002abf5(void *this,undefined4 *param_1)

{
  int *piVar1;

  *param_1 = *(undefined4 *)((int)this + 0x10);
  piVar1 = (int *)((int)this + 0xc);
  *piVar1 = *piVar1 + -1;
  *(undefined4 **)((int)this + 0x10) = param_1;
  if (*piVar1 == 0) {
    RemoveAll((int)this);
  }
  return;
}



/* VA 1002ac0e */

int __fastcall FUN_1002ac0e(void *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;

  piVar1 = *(int **)((int)param_1 + 4);
  iVar2 = *piVar1;
  iVar3 = piVar1[2];
  *(int *)((int)param_1 + 4) = iVar2;
  if (iVar2 == 0) {
    *(undefined4 *)((int)param_1 + 8) = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  FUN_1002abf5(param_1,piVar1);
  return iVar3;
}



/* VA 1002ac32 */

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall CMap<void *,void *,void *,void *>::CMap<void *,void *,void *,void *>(int)
    public: __thiscall CMap<class ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class
   ATL::ChTraitsOS<wchar_t> > >,wchar_t const *,void *,void *>::CMap<class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsOS<wchar_t> > >,wchar_t const
   *,void *,void *>(int)

   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __thiscall CMap<>(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_10034d94;
  *(undefined4 *)((int)this + 8) = 0x11;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* VA 1002ac59 */

undefined * __thiscall FUN_1002ac59(void *this,byte param_1)

{
  FUN_1002ace5();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1002ac75 */

void __thiscall FUN_1002ac75(void *this,int param_1,int param_2)

{
  void *_Dst;

  if (*(undefined **)((int)this + 4) != (undefined *)0x0) {
    FUN_1002becb(*(undefined **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if (param_2 != 0) {
    _Dst = FUN_1002bea2(param_1 << 2);
    *(void **)((int)this + 4) = _Dst;
    _memset(_Dst,0,param_1 << 2);
  }
  *(int *)((int)this + 8) = param_1;
  return;
}



/* VA 1002acba */

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall CMapPtrToPtr::RemoveAll(void)
    public: void __thiscall CMapPtrToWord::RemoveAll(void)
    public: void __thiscall CMapWordToOb::RemoveAll(void)
    public: void __thiscall CMapWordToPtr::RemoveAll(void)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __fastcall RemoveAll(int param_1)

{
  if (*(undefined **)(param_1 + 4) != (undefined *)0x0) {
    FUN_1002becb(*(undefined **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_1002abbf(*(undefined4 **)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* VA 1002ace5 */

void FUN_1002ace5(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_10034d94;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  RemoveAll((int)extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002ad0e */

void __fastcall FUN_1002ad0e(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;

  if (*(int *)(param_1 + 0x10) == 0) {
    iVar2 = FUN_1002ab9f((undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 0x18),0xc);
    iVar4 = *(int *)(param_1 + 0x18);
    puVar3 = (undefined4 *)(iVar2 + -8 + iVar4 * 0xc);
    if (-1 < iVar4 + -1) {
      do {
        *puVar3 = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = puVar3;
        puVar3 = puVar3 + -3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  uVar1 = *puVar3;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  puVar3[1] = 0;
  puVar3[2] = 0;
  return;
}



/* VA 1002ad5b */

void __thiscall FUN_1002ad5b(void *this,undefined4 *param_1)

{
  int *piVar1;

  *param_1 = *(undefined4 *)((int)this + 0x10);
  piVar1 = (int *)((int)this + 0xc);
  *piVar1 = *piVar1 + -1;
  *(undefined4 **)((int)this + 0x10) = param_1;
  if (*piVar1 == 0) {
    RemoveAll((int)this);
  }
  return;
}



/* VA 1002ad74 */

undefined4 * __thiscall FUN_1002ad74(void *this,uint param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;

  uVar2 = (param_1 >> 4) % *(uint *)((int)this + 8);
  *param_2 = uVar2;
  if (*(int *)((int)this + 4) != 0) {
    for (puVar1 = *(undefined4 **)(*(int *)((int)this + 4) + uVar2 * 4); puVar1 != (undefined4 *)0x0
        ; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[1] == param_1) {
        return puVar1;
      }
    }
  }
  return (undefined4 *)0x0;
}



/* VA 1002ada6 */

undefined4 __thiscall FUN_1002ada6(void *this,uint param_1)

{
  undefined4 *puVar1;

  if (*(int *)((int)this + 4) != 0) {
    for (puVar1 = *(undefined4 **)
                   (*(int *)((int)this + 4) + ((param_1 >> 4) % *(uint *)((int)this + 8)) * 4);
        puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[1] == param_1) {
        return puVar1[2];
      }
    }
  }
  return 0;
}



/* VA 1002add9 */

undefined4 * __thiscall FUN_1002add9(void *this,uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;

  uVar1 = param_1;
  puVar2 = FUN_1002ad74(this,param_1,&param_1);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)((int)this + 4) == 0) {
      FUN_1002ac75(this,*(int *)((int)this + 8),1);
    }
    puVar2 = (undefined4 *)FUN_1002ad0e((int)this);
    puVar2[1] = uVar1;
    *puVar2 = *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4);
    *(undefined4 **)(*(int *)((int)this + 4) + param_1 * 4) = puVar2;
  }
  return puVar2 + 2;
}



/* VA 1002ae29 */

undefined4 __thiscall FUN_1002ae29(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;

  iVar1 = *(int *)((int)this + 4);
  if (iVar1 != 0) {
    uVar4 = (param_1 >> 4) % *(uint *)((int)this + 8);
    puVar2 = *(undefined4 **)(iVar1 + uVar4 * 4);
    puVar5 = (undefined4 *)(iVar1 + uVar4 * 4);
    while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {
      if (puVar3[1] == param_1) {
        *puVar5 = *puVar3;
        FUN_1002ad5b(this,puVar3);
        return 1;
      }
      puVar5 = puVar3;
      puVar2 = (undefined4 *)*puVar3;
    }
  }
  return 0;
}



/* VA 1002ae6b */

void __thiscall FUN_1002ae6b(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;

  piVar3 = (int *)*param_1;
  if (piVar3 == (int *)0xffffffff) {
    uVar4 = 0;
    if (*(uint *)((int)this + 8) != 0) {
      piVar1 = *(int **)((int)this + 4);
      do {
        piVar3 = (int *)*piVar1;
        if (piVar3 != (int *)0x0) break;
        uVar4 = uVar4 + 1;
        piVar1 = piVar1 + 1;
      } while (uVar4 < *(uint *)((int)this + 8));
    }
  }
  iVar5 = *piVar3;
  if (iVar5 == 0) {
    uVar4 = *(uint *)((int)this + 8);
    uVar2 = ((uint)piVar3[1] >> 4) % uVar4 + 1;
    if (uVar2 < uVar4) {
      piVar1 = (int *)(*(int *)((int)this + 4) + uVar2 * 4);
      do {
        iVar5 = *piVar1;
        if (iVar5 != 0) break;
        uVar2 = uVar2 + 1;
        piVar1 = piVar1 + 1;
      } while (uVar2 < uVar4);
    }
  }
  *param_1 = iVar5;
  *param_2 = piVar3[1];
  *param_3 = piVar3[2];
  return;
}



/* VA 1002aedd */

int * __thiscall FUN_1002aedd(void *this,int *param_1)

{
  int iVar1;

  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) < 0) {
    *(undefined **)this = PTR_DAT_1003d148;
    FUN_1002b2a5(this,(LPCSTR)*param_1);
  }
  else {
    *(int *)this = iVar1;
    InterlockedIncrement((LONG *)(iVar1 + -0xc));
  }
  return this;
}



/* VA 1002af1a */

void FUN_1002af1a(void)

{
  FUN_1001e5c5(&DAT_100418f8,0x50,0x40);
  return;
}



/* VA 1002af29 */

void FUN_1002af29(void)

{
  FUN_1001f5cf(&LAB_1002af35);
  return;
}



/* VA 1002af49 */

void FUN_1002af49(void)

{
  FUN_1001e5c5(&DAT_100418d0,0x90,0x40);
  return;
}



/* VA 1002af5b */

void FUN_1002af5b(void)

{
  FUN_1001f5cf(&LAB_1002af67);
  return;
}



/* VA 1002af7b */

void FUN_1002af7b(void)

{
  FUN_1001e5c5(&DAT_100418a8,0x110,0x40);
  return;
}



/* VA 1002af8d */

void FUN_1002af8d(void)

{
  FUN_1001f5cf(&LAB_1002af99);
  return;
}



/* VA 1002afad */

void FUN_1002afad(void)

{
  FUN_1001e5c5(&DAT_10041880,0x210,0x40);
  return;
}



/* VA 1002afbf */

void FUN_1002afbf(void)

{
  FUN_1001f5cf(&LAB_1002afcb);
  return;
}



/* VA 1002afd5 */

void __thiscall FUN_1002afd5(void *this,int param_1)

{
  int *piVar1;
  int iVar2;

  if (param_1 == 0) {
    *(undefined **)this = PTR_DAT_1003d148;
  }
  else {
    iVar2 = 0x40;
    if ((((param_1 < 0x41) || (iVar2 = 0x80, param_1 < 0x81)) || (iVar2 = 0x100, param_1 < 0x101))
       || (iVar2 = 0x200, param_1 < 0x201)) {
      piVar1 = FUN_1001e629();
      piVar1[2] = iVar2;
    }
    else {
      piVar1 = FUN_1002bea2(param_1 + 0xd);
      piVar1[2] = param_1;
    }
    *piVar1 = 1;
    *(undefined1 *)((int)piVar1 + param_1 + 0xc) = 0;
    piVar1[1] = param_1;
    *(int **)this = piVar1 + 3;
  }
  return;
}



/* VA 1002b057 */

void __fastcall FUN_1002b057(undefined4 *param_1)

{
  int iVar1;
  undefined *this;

  iVar1 = param_1[2];
  if (iVar1 == 0x40) {
    this = &DAT_100418f8;
  }
  else if (iVar1 == 0x80) {
    this = &DAT_100418d0;
  }
  else if (iVar1 == 0x100) {
    this = &DAT_100418a8;
  }
  else {
    if (iVar1 != 0x200) {
      FUN_1002becb((undefined *)param_1);
      return;
    }
    this = &DAT_10041880;
  }
  FUN_1001e6b8(this,param_1);
  return;
}



/* VA 1002b09f */

void __fastcall FUN_1002b09f(int *param_1)

{
  LONG LVar1;

  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_1003d14c) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      FUN_1002b057((undefined4 *)(*param_1 + -0xc));
    }
    *param_1 = (int)PTR_DAT_1003d148;
  }
  return;
}



/* VA 1002b0d0 */

void FUN_1002b0d0(LONG *param_1)

{
  LONG LVar1;

  if (param_1 != (LONG *)PTR_DAT_1003d14c) {
    LVar1 = InterlockedDecrement(param_1);
    if (LVar1 < 1) {
      FUN_1002b057(param_1);
    }
  }
  return;
}



/* VA 1002b0f3 */

void __fastcall FUN_1002b0f3(int *param_1)

{
  if (*(int *)(*param_1 + -8) != 0) {
    if (-1 < *(int *)(*param_1 + -0xc)) {
      FUN_1002b09f(param_1);
      return;
    }
    FUN_1002b2a5(param_1,&DAT_10041920);
  }
  return;
}



/* VA 1002b111 */

void __fastcall FUN_1002b111(int *param_1)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)*param_1;
  if (1 < (int)puVar1[-3]) {
    FUN_1002b09f(param_1);
    FUN_1002afd5(param_1,puVar1[-2]);
    FUN_100200e0((undefined4 *)*param_1,puVar1,puVar1[-2] + 1);
  }
  return;
}



/* VA 1002b13f */

void __thiscall FUN_1002b13f(void *this,int param_1)

{
  if ((1 < *(int *)(*(int *)this + -0xc)) || (*(int *)(*(int *)this + -4) < param_1)) {
    FUN_1002b09f(this);
    FUN_1002afd5(this,param_1);
  }
  return;
}



/* VA 1002b168 */

void __fastcall FUN_1002b168(int *param_1)

{
  LONG LVar1;

  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_1003d14c) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      FUN_1002b057((undefined4 *)(*param_1 + -0xc));
    }
  }
  return;
}



/* VA 1002b192 */

void __thiscall FUN_1002b192(void *this,undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  if (param_4 + param_2 == 0) {
    *param_1 = PTR_DAT_1003d148;
  }
  else {
    FUN_1002afd5(param_1,param_4 + param_2);
    FUN_100200e0((undefined4 *)*param_1,(undefined4 *)(*(int *)this + param_3),param_2);
  }
  return;
}



/* VA 1002b1d6 */

undefined4 * __thiscall FUN_1002b1d6(void *this,LPCSTR param_1)

{
  uint uVar1;

  *(undefined **)this = PTR_DAT_1003d148;
  if (param_1 != (LPCSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_1002c2be((uint)param_1 & 0xffff);
    }
    else {
      uVar1 = lstrlenA(param_1);
      if (uVar1 != 0) {
        FUN_1002afd5(this,uVar1);
        FUN_100200e0(*(undefined4 **)this,(undefined4 *)param_1,uVar1);
      }
    }
  }
  return this;
}



/* VA 1002b228 */

void __thiscall FUN_1002b228(void *this,uint param_1,undefined4 *param_2)

{
  FUN_1002b13f(this,param_1);
  FUN_100200e0(*(undefined4 **)this,param_2,param_1);
  *(uint *)(*(int *)this + -8) = param_1;
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return;
}



/* VA 1002b255 */

int * __thiscall FUN_1002b255(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;

  puVar1 = *(undefined4 **)this;
  puVar2 = (undefined4 *)*param_1;
  if (puVar1 != puVar2) {
    if ((((int)puVar1[-3] < 0) && (puVar1 + -3 != (undefined4 *)PTR_DAT_1003d14c)) ||
       ((int)puVar2[-3] < 0)) {
      FUN_1002b228(this,puVar2[-2],puVar2);
    }
    else {
      FUN_1002b09f(this);
      iVar3 = *param_1;
      *(int *)this = iVar3;
      InterlockedIncrement((LONG *)(iVar3 + -0xc));
    }
  }
  return this;
}



/* VA 1002b2a5 */

void * __thiscall FUN_1002b2a5(void *this,LPCSTR param_1)

{
  uint uVar1;

  if (param_1 == (LPCSTR)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = lstrlenA(param_1);
  }
  FUN_1002b228(this,uVar1,(undefined4 *)param_1);
  return this;
}



/* VA 1002b2cc */

undefined4 * __thiscall FUN_1002b2cc(void *this,LPCWSTR param_1)

{
  int iVar1;

  if (param_1 == (LPCWSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_10020415(param_1);
  }
  FUN_1002b13f(this,iVar1 * 2);
  FUN_1002b61b(*(LPSTR *)this,param_1,iVar1 * 2 + 1);
  FUN_1002b586(this,-1);
  return this;
}



/* VA 1002b30d */

void __thiscall
FUN_1002b30d(void *this,uint param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  if (param_1 + param_3 != 0) {
    FUN_1002afd5(this,param_1 + param_3);
    FUN_100200e0(*(undefined4 **)this,param_2,param_1);
    FUN_100200e0((undefined4 *)(*(int *)this + param_1),param_4,param_3);
  }
  return;
}



/* VA 1002b34b */

undefined4 FUN_1002b34b(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int unaff_EBP;

  FUN_10020434();
  puVar3 = PTR_DAT_1003d148;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined **)(unaff_EBP + -0x10) = puVar3;
  puVar1 = (undefined4 *)**(undefined4 **)(unaff_EBP + 0x10);
  puVar2 = (undefined4 *)**(undefined4 **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_1002b30d((void *)(unaff_EBP + -0x10),puVar2[-2],puVar2,puVar1[-2],puVar1);
  FUN_1002aedd(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_1002b168((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



/* VA 1002b3b1 */

undefined4 FUN_1002b3b1(void)

{
  undefined *puVar1;
  uint uVar2;
  int unaff_EBP;

  FUN_10020434();
  puVar1 = PTR_DAT_1003d148;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = lstrlenA(*(LPCSTR *)(unaff_EBP + 0x10));
  }
  FUN_1002b30d((void *)(unaff_EBP + -0x10),((undefined4 *)**(undefined4 **)(unaff_EBP + 0xc))[-2],
               (undefined4 *)**(undefined4 **)(unaff_EBP + 0xc),uVar2,
               *(undefined4 **)(unaff_EBP + 0x10));
  FUN_1002aedd(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_1002b168((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



/* VA 1002b425 */

undefined4 FUN_1002b425(void)

{
  undefined *puVar1;
  uint uVar2;
  int unaff_EBP;

  FUN_10020434();
  puVar1 = PTR_DAT_1003d148;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = lstrlenA(*(LPCSTR *)(unaff_EBP + 0xc));
  }
  FUN_1002b30d((void *)(unaff_EBP + -0x10),uVar2,*(undefined4 **)(unaff_EBP + 0xc),
               ((undefined4 *)**(undefined4 **)(unaff_EBP + 0x10))[-2],
               (undefined4 *)**(undefined4 **)(unaff_EBP + 0x10));
  FUN_1002aedd(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_1002b168((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



/* VA 1002b499 */

void __thiscall FUN_1002b499(void *this,uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;

  if (param_1 != 0) {
    puVar1 = *(undefined4 **)this;
    if (((int)puVar1[-3] < 2) && ((int)(puVar1[-2] + param_1) <= (int)puVar1[-1])) {
      FUN_100200e0((undefined4 *)(puVar1[-2] + (int)puVar1),param_2,param_1);
      *(int *)(*(int *)this + -8) = *(int *)(*(int *)this + -8) + param_1;
      *(undefined1 *)(*(int *)(*(int *)this + -8) + *(int *)this) = 0;
    }
    else {
      FUN_1002b30d(this,puVar1[-2],puVar1,param_1,param_2);
      FUN_1002b0d0(puVar1 + -3);
    }
  }
  return;
}



/* VA 1002b4f8 */

void * __thiscall FUN_1002b4f8(void *this,LPCSTR param_1)

{
  uint uVar1;

  if (param_1 == (LPCSTR)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = lstrlenA(param_1);
  }
  FUN_1002b499(this,uVar1,(undefined4 *)param_1);
  return this;
}



/* VA 1002b51f */

void * __thiscall FUN_1002b51f(void *this,undefined4 *param_1)

{
  FUN_1002b499(this,((undefined4 *)*param_1)[-2],(undefined4 *)*param_1);
  return this;
}



/* VA 1002b537 */

int __thiscall FUN_1002b537(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;

  puVar1 = *(undefined4 **)this;
  if ((1 < (int)puVar1[-3]) || ((int)puVar1[-1] < param_1)) {
    iVar2 = puVar1[-2];
    if (param_1 < iVar2) {
      param_1 = iVar2;
    }
    FUN_1002afd5(this,param_1);
    FUN_100200e0(*(undefined4 **)this,puVar1,iVar2 + 1);
    *(int *)(*(int *)this + -8) = iVar2;
    FUN_1002b0d0(puVar1 + -3);
  }
  return *(int *)this;
}



/* VA 1002b586 */

void __thiscall FUN_1002b586(void *this,int param_1)

{
  FUN_1002b111(this);
  if (param_1 == -1) {
    param_1 = lstrlenA(*(LPCSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return;
}



/* VA 1002b5ae */

int __thiscall FUN_1002b5ae(void *this,int param_1)

{
  FUN_1002b537(this,param_1);
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return *(int *)this;
}



/* VA 1002b5ce */

void __thiscall FUN_1002b5ce(void *this,byte param_1)

{
  FUN_1002b5dc(this,param_1,0);
  return;
}



/* VA 1002b5dc */

int __thiscall FUN_1002b5dc(void *this,byte param_1,int param_2)

{
  byte *pbVar1;

  if ((param_2 < *(int *)(*(int *)this + -8)) &&
     (pbVar1 = FUN_10020453((byte *)(*(int *)this + param_2),(uint)param_1), pbVar1 != (byte *)0x0))
  {
    return (int)pbVar1 - *(int *)this;
  }
  return -1;
}



/* VA 1002b609 */

void __fastcall FUN_1002b609(int *param_1)

{
  FUN_1002b111(param_1);
  FUN_100204ea((byte *)*param_1);
  return;
}



/* VA 1002b61b */

int __cdecl FUN_1002b61b(LPSTR param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;

  if ((param_3 == 0) && (param_1 != (LPSTR)0x0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = WideCharToMultiByte(0,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    if (0 < iVar1) {
      param_1[iVar1 + -1] = '\0';
    }
  }
  return iVar1;
}



/* VA 1002b651 */

undefined4 * __fastcall FUN_1002b651(undefined4 *param_1)

{
  FUN_1002c3d5(param_1);
  param_1[4] = 0;
  *param_1 = &PTR_LAB_10034450;
  return param_1;
}



/* VA 1002b667 */

/* Library Function - Single Match
    public: virtual void * __thiscall CStdioFile::`scalar deleting destructor'(unsigned int)

   Library: Visual Studio 2003 Release */

void * __thiscall CStdioFile::_scalar_deleting_destructor_(CStdioFile *this,uint param_1)

{
  ~CStdioFile(this);
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1002b683 */

/* Library Function - Single Match
    public: virtual __thiscall CStdioFile::~CStdioFile(void)

   Library: Visual Studio 2003 Release */

void __thiscall CStdioFile::~CStdioFile(CStdioFile *this)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_10034450;
  iVar1 = extraout_ECX[4];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar1 != 0) && (extraout_ECX[2] != 0)) {
    FUN_1002b9f6((int)extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1002c42a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002b6c6 */

undefined4 __thiscall FUN_1002b6c6(void *this,LPCSTR param_1,uint param_2,int param_3)

{
  int iVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  DWORD *pDVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;

  iVar1 = param_3;
  *(undefined4 *)((int)this + 0x10) = 0;
  DVar2 = FUN_1002c4e7(this,param_1,param_2 & 0xffffbfff,param_3);
  if (DVar2 == 0) {
    return 0;
  }
  if ((param_2 & 0x1000) == 0) {
    if ((param_2 & 1) != 0) goto LAB_1002b704;
    iVar7 = 1;
    param_3 = CONCAT31(param_3._1_3_,0x72);
    if ((param_2 & 2) == 0) goto LAB_1002b716;
  }
  else {
    if ((param_2 & 0x2000) == 0) {
      param_3 = CONCAT31(param_3._1_3_,0x77);
    }
    else {
LAB_1002b704:
      param_3 = CONCAT31(param_3._1_3_,0x61);
    }
    iVar7 = 1;
    if ((param_2 & 1) != 0) goto LAB_1002b716;
  }
  param_3._0_2_ = CONCAT11(0x2b,(undefined1)param_3);
  iVar7 = 2;
LAB_1002b716:
  uVar6 = 0x4000;
  if ((param_2 & 0x8000) == 0) {
    *(undefined1 *)((int)&param_3 + iVar7) = 0x74;
  }
  else {
    *(undefined1 *)((int)&param_3 + iVar7) = 0x62;
    uVar6 = 0;
  }
  *(undefined1 *)((int)&param_3 + iVar7 + 1) = 0;
  uVar6 = FUN_10020e37(*(HANDLE *)((int)this + 4),uVar6);
  if (uVar6 != 0xffffffff) {
    puVar3 = FUN_10020fe4(uVar6,(char *)&param_3);
    *(undefined4 **)((int)this + 0x10) = puVar3;
  }
  if (*(int *)((int)this + 0x10) == 0) {
    if (iVar1 != 0) {
      pDVar4 = FUN_10020fdb();
      *(DWORD *)(iVar1 + 0xc) = *pDVar4;
      pDVar4 = FUN_10020fdb();
      uVar5 = FUN_1002bc0a(*pDVar4);
      *(undefined4 *)(iVar1 + 8) = uVar5;
    }
    FUN_1002c743((int)this);
    return 0;
  }
  return 1;
}



/* VA 1002b806 */

void __thiscall FUN_1002b806(void *this,char *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = FUN_1002122f(param_1,1,param_2,*(int **)((int)this + 0x10));
  if (uVar1 != param_2) {
    FUN_10020fdb();
    FUN_1002bb9f();
  }
  return;
}



/* VA 1002b839 */

void __thiscall FUN_1002b839(void *this,char *param_1)

{
  int iVar1;

  iVar1 = FUN_10021368(param_1,*(int **)((int)this + 0x10));
  if (iVar1 == -1) {
    FUN_10020fdb();
    FUN_1002bb9f();
  }
  return;
}



/* VA 1002b864 */

char * __thiscall FUN_1002b864(void *this,char *param_1,int param_2)

{
  char *pcVar1;

  pcVar1 = FUN_100213b6(param_1,param_2,*(undefined4 **)((int)this + 0x10));
  if ((pcVar1 == (char *)0x0) && ((*(byte *)(*(uint *)((int)this + 0x10) + 0xc) & 0x10) == 0)) {
    FUN_100210d7(*(uint *)((int)this + 0x10));
    FUN_10020fdb();
    FUN_1002bb9f();
  }
  return pcVar1;
}



/* VA 1002b8a9 */

bool __thiscall FUN_1002b8a9(void *this,int *param_1)

{
  char *lpString;
  char *pcVar1;
  int iVar2;
  int iVar3;

  FUN_1002b2a5(param_1,&DAT_10041920);
  lpString = (char *)FUN_1002b537(param_1,0x80);
  while( true ) {
    pcVar1 = FUN_100213b6(lpString,0x81,*(undefined4 **)((int)this + 0x10));
    FUN_1002b586(param_1,-1);
    if (pcVar1 == (char *)0x0) break;
    iVar2 = lstrlenA(lpString);
    if ((iVar2 < 0x80) || (lpString[iVar2 + -1] == '\n')) goto LAB_1002b93c;
    iVar2 = *(int *)(*param_1 + -8);
    iVar3 = FUN_1002b537(param_1,iVar2 + 0x80);
    lpString = (char *)(iVar3 + iVar2);
  }
  if ((*(byte *)(*(uint *)((int)this + 0x10) + 0xc) & 0x10) == 0) {
    FUN_100210d7(*(uint *)((int)this + 0x10));
    FUN_10020fdb();
    FUN_1002bb9f();
  }
LAB_1002b93c:
  iVar3 = FUN_1002b537(param_1,0);
  iVar2 = *(int *)(*param_1 + -8);
  if ((iVar2 != 0) && (*(char *)(iVar2 + -1 + iVar3) == '\n')) {
    FUN_1002b5ae(param_1,iVar2 + -1);
  }
  return pcVar1 != (char *)0x0;
}



/* VA 1002b96c */

void __thiscall FUN_1002b96c(void *this,int param_1,DWORD param_2)

{
  int iVar1;

  iVar1 = FUN_1002159b(*(int **)((int)this + 0x10),param_1,param_2);
  if (iVar1 != 0) {
    FUN_10020fdb();
    FUN_1002bb9f();
  }
  FUN_10021418(*(char **)((int)this + 0x10));
  return;
}



/* VA 1002b9a4 */

int __fastcall FUN_1002b9a4(int param_1)

{
  int iVar1;

  iVar1 = FUN_10021418(*(char **)(param_1 + 0x10));
  if (iVar1 == -1) {
    FUN_10020fdb();
    FUN_1002bb9f();
  }
  return iVar1;
}



/* VA 1002b9ce */

void __fastcall FUN_1002b9ce(int param_1)

{
  int iVar1;

  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    iVar1 = FUN_1001fdc8(*(int **)(param_1 + 0x10));
    if (iVar1 != 0) {
      FUN_10020fdb();
      FUN_1002bb9f();
    }
  }
  return;
}



/* VA 1002b9f6 */

void __fastcall FUN_1002b9f6(int param_1)

{
  int iVar1;

  iVar1 = 0;
  if (*(FILE **)(param_1 + 0x10) != (FILE *)0x0) {
    iVar1 = FUN_1001f4d4(*(FILE **)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (iVar1 != 0) {
    FUN_10020fdb();
    FUN_1002bb9f();
  }
  return;
}



/* VA 1002ba2c */

void __fastcall FUN_1002ba2c(int param_1)

{
  if ((*(FILE **)(param_1 + 0x10) != (FILE *)0x0) && (*(int *)(param_1 + 8) != 0)) {
    FUN_1001f4d4(*(FILE **)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



/* VA 1002ba61 */

void __fastcall FUN_1002ba61(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}



/* VA 1002ba6b */

void __thiscall FUN_1002ba6b(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  return;
}



/* VA 1002ba77 */

void __fastcall FUN_1002ba77(int *param_1)

{
  if ((0 < param_1[1]) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(1);
  }
  return;
}



/* VA 1002ba89 */

void __thiscall FUN_1002ba89(void *this,UINT param_1)

{
  int iVar1;
  CHAR local_208 [512];
  int local_8;

  iVar1 = (**(code **)(*(int *)this + 0xc))(local_208,0x200,&local_8);
  if (iVar1 == 0) {
    FUN_1003073b();
  }
  else {
    FUN_10030703(local_208,param_1,local_8);
  }
  return;
}



/* VA 1002bade */

void FUN_1002bade(uint param_1)

{
  if (param_1 != 0) {
    FUN_1002bc0a(param_1);
    FUN_1002bb9f();
  }
  return;
}



/* VA 1002baff */

undefined4 FUN_1002baff(void)

{
  int extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  if (*(int **)(unaff_EBP + 0x10) != (int *)0x0) {
    **(int **)(unaff_EBP + 0x10) = *(int *)(extraout_ECX + 8) + 0xf1a0;
  }
  *(undefined **)(unaff_EBP + -0x10) = PTR_DAT_1003d148;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002aedd((void *)(unaff_EBP + 0x10),(int *)(extraout_ECX + 0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (*(int *)(*(int *)(unaff_EBP + 0x10) + -8) == 0) {
    FUN_1002c2be(0xf006);
  }
  FUN_10030975((int *)(unaff_EBP + -0x10),*(int *)(extraout_ECX + 8) + 0xf1a0);
  lstrcpynA(*(LPSTR *)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_1002b168((int *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1002b168((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}



/* VA 1002bb9f */

void FUN_1002bb9f(void)

{
  LPCSTR pCVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_EBP;

  FUN_10020434();
  puVar3 = FUN_1002bea2(0x14);
  *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_1002ba61((int)puVar3);
    puVar3[4] = PTR_DAT_1003d148;
    pCVar1 = *(LPCSTR *)(unaff_EBP + 0x10);
    puVar3[2] = *(undefined4 *)(unaff_EBP + 8);
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *puVar3 = &PTR_LAB_100344b4;
    puVar3[3] = uVar2;
    FUN_1002b2a5(puVar3 + 4,pCVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 **)(unaff_EBP + -0x10) = puVar3;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x10,&DAT_10037088);
}



/* VA 1002bc0a */

undefined4 FUN_1002bc0a(uint param_1)

{
  int iVar1;

  if (0x10b < param_1) {
    if (param_1 == 0x3e3) {
      return 10;
    }
    if (param_1 == 0x3e4) {
      return 10;
    }
    if (param_1 == 0x3e5) {
      return 10;
    }
    if (param_1 == 999) {
      return 5;
    }
    return 1;
  }
  if (param_1 == 0x10b) {
    return 3;
  }
  if (param_1 < 0x3f) {
    if (param_1 == 0x3e) {
      return 8;
    }
    if (param_1 < 0x1a) {
      if (param_1 == 0x19) {
        return 9;
      }
      switch(param_1) {
      case 0:
        return 0;
      default:
        return 1;
      case 2:
      case 6:
      case 0x12:
        goto LAB_1002bd0c;
      case 3:
      case 0xf:
      case 0x11:
        goto LAB_1002bd0c;
      case 4:
        return 4;
      case 5:
      case 0xc:
      case 0x13:
LAB_1002bd0c:
        return 5;
      case 0xb:
LAB_1002bd0c:
        return 6;
      case 0x10:
        return 7;
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
LAB_1002bd0c:
        return 10;
      case 0x18:
        return 9;
      }
    }
    if (0x27 < param_1) {
      switch(param_1) {
      case 0x34:
      case 0x35:
      case 0x37:
        goto LAB_1002bd0c;
      case 0x36:
      case 0x3a:
        goto LAB_1002bd0c;
      default:
        return 1;
      case 0x39:
      case 0x3b:
        goto LAB_1002bd0c;
      case 0x3c:
        goto LAB_1002bd0c;
      }
    }
    if (param_1 == 0x27) {
      return 0xd;
    }
    if (0x20 < param_1) {
      if (param_1 == 0x21) {
        return 0xc;
      }
      if (param_1 == 0x22) {
        return 3;
      }
      if (param_1 == 0x24) {
        return 4;
      }
      if (param_1 == 0x26) {
        return 0xe;
      }
      return 1;
    }
    if (param_1 == 0x20) {
      return 0xb;
    }
    if (param_1 == 0x1a) {
      return 6;
    }
    if (param_1 == 0x1b) {
      return 9;
    }
    iVar1 = param_1 - 0x1d;
    if (iVar1 == 0) {
      return 5;
    }
LAB_1002bc82:
    if (iVar1 == 1) {
      return 9;
    }
  }
  else {
    if (param_1 < 0x6c) {
      if (param_1 == 0x6b) {
LAB_1002bd0c:
        return 2;
      }
      if (0x47 < param_1) {
        if (param_1 == 0x50) {
          return 5;
        }
        if (param_1 == 0x52) {
          return 5;
        }
        if (param_1 == 0x55) {
          return 3;
        }
        if (param_1 != 0x56) {
          if (param_1 == 0x58) {
            return 10;
          }
          return 1;
        }
        return 5;
      }
      if (param_1 == 0x47) {
        return 5;
      }
      if (param_1 == 0x40) {
        return 5;
      }
      if (param_1 == 0x41) {
        return 5;
      }
      if (param_1 == 0x42) {
        return 6;
      }
      if (param_1 == 0x43) {
        return 3;
      }
      iVar1 = param_1 - 0x44;
      if (iVar1 == 0) {
        return 4;
      }
    }
    else {
      if (param_1 < 0x91) {
        if (param_1 == 0x90) {
          return 3;
        }
        if (param_1 < 0x76) {
          if (param_1 == 0x75) {
            return 10;
          }
          if (param_1 == 0x6c) {
            return 0xc;
          }
          if (param_1 == 0x6f) {
            return 3;
          }
          if (param_1 == 0x70) {
            return 0xd;
          }
          if (param_1 == 0x71) {
            return 4;
          }
          if (param_1 != 0x72) {
            return 1;
          }
          return 6;
        }
        if (param_1 == 0x7b) {
          return 3;
        }
        if (param_1 == 0x7c) {
          return 3;
        }
        if (param_1 == 0x7d) {
          return 3;
        }
        iVar1 = param_1 - 0x83;
        if (iVar1 == 0) {
          return 9;
        }
        goto LAB_1002bc82;
      }
      if (param_1 < 0xb7) {
        if (param_1 == 0xb6) {
          return 6;
        }
        if (param_1 == 0x91) {
          return 7;
        }
        if (param_1 == 0x9a) {
          return 3;
        }
        if (param_1 != 0xa1) {
          if (param_1 == 0xa7) {
            return 0xc;
          }
          if (param_1 == 0xaa) {
            return 5;
          }
          return 1;
        }
        return 3;
      }
      if (param_1 == 0xb7) {
        return 5;
      }
      if (param_1 == 0xbf) {
        return 6;
      }
      if (param_1 == 0xc1) {
        return 6;
      }
      iVar1 = param_1 - 0xce;
      if (iVar1 == 0) {
        return 3;
      }
    }
    if (iVar1 == 2) {
LAB_1002bd0c:
      return 3;
    }
  }
  return 1;
}



/* VA 1002be88 */

undefined4 FUN_1002be88(void)

{
  FUN_1002a594();
  return 0;
}



/* VA 1002be90 */

undefined * FUN_1002be90(undefined *param_1)

{
  undefined *puVar1;

  puVar1 = PTR_FUN_1003d360;
  PTR_FUN_1003d360 = param_1;
  return puVar1;
}



/* VA 1002bea2 */

void * __cdecl FUN_1002bea2(size_t param_1)

{
  void *pvVar1;
  int iVar2;

  while( true ) {
    pvVar1 = _malloc(param_1);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (PTR_FUN_1003d360 == (undefined *)0x0) break;
    iVar2 = (*(code *)PTR_FUN_1003d360)(param_1);
    if (iVar2 == 0) {
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}



/* VA 1002becb */

void __cdecl FUN_1002becb(undefined *param_1)

{
  FUN_1001fabf(param_1);
  return;
}



/* VA 1002bed6 */

/* Library Function - Single Match
    class CWinThread * __stdcall AfxGetThread(void)

   Library: Visual Studio 1998 Release */

CWinThread * AfxGetThread(void)

{
  int iVar1;
  CWinThread *pCVar2;

  iVar1 = FUN_100314a4();
  pCVar2 = *(CWinThread **)(iVar1 + 4);
  if (pCVar2 == (CWinThread *)0x0) {
    iVar1 = FUN_1003147e();
    pCVar2 = *(CWinThread **)(iVar1 + 4);
  }
  return pCVar2;
}



/* VA 1002beeb */

void FUN_1002beeb(void)

{
  int iVar1;
  DWORD dwThreadId;
  HHOOK pHVar2;
  int iVar3;

  iVar1 = FUN_1003147e();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    iVar1 = FUN_1003124c();
    dwThreadId = GetCurrentThreadId();
    pHVar2 = SetWindowsHookExA(-1,(HOOKPROC)&LAB_1002bfda,(HINSTANCE)0x0,dwThreadId);
    *(HHOOK *)(iVar1 + 0x30) = pHVar2;
    iVar1 = FUN_100310c7();
    if (*(int *)(iVar1 + 0x14) != 0) {
      iVar3 = FUN_1003147e();
      (**(code **)(iVar1 + 0x14))(*(undefined4 *)(iVar3 + 8));
    }
    FUN_10031005(&DAT_100435ec,&LAB_10030aee);
  }
  return;
}



/* VA 1002bf4a */

void FUN_1002bf4a(void)

{
  int iVar1;
  int unaff_EBP;

  FUN_10020434();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002c032();
  FUN_1002c03b(0xffffffff);
  if (*(int *)(unaff_EBP + 8) == 0) {
    iVar1 = FUN_1003107c((int *)&DAT_10041a9c);
    if ((iVar1 != 0) && (*(int **)(iVar1 + 0xcc) != (int *)0x0)) {
      (**(code **)(**(int **)(iVar1 + 0xcc) + 0x58))();
      if (*(int **)(iVar1 + 0xcc) != (int *)0x0) {
        (**(code **)(**(int **)(iVar1 + 0xcc) + 4))(1);
      }
      *(undefined4 *)(iVar1 + 0xcc) = 0;
    }
  }
  if (DAT_10041a60 != (void *)0x0) {
    FUN_10030fac(DAT_10041a60,*(int *)(unaff_EBP + 8),0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002bfcc */

undefined4 Catch_1002bfcc(void)

{
  int unaff_EBP;

  FUN_1002ba77(*(int **)(unaff_EBP + -0x14));
  return 0x1002bfbb;
}



/* VA 1002c032 */

void FUN_1002c032(void)

{
  int iVar1;

  iVar1 = FUN_100314a4();
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
  return;
}



/* VA 1002c03b */

bool FUN_1002c03b(SIZE_T param_1)

{
  int iVar1;
  int iVar2;
  CWinThread *pCVar3;
  int iVar4;
  SIZE_T SVar5;
  void *pvVar6;

  iVar1 = FUN_100314a4();
  if ((*(int *)(iVar1 + 0x10) != 0) &&
     (iVar2 = *(int *)(iVar1 + 0x10) + -1, *(int *)(iVar1 + 0x10) = iVar2, iVar2 == 0)) {
    if (param_1 != 0) {
      if (param_1 != 0xffffffff) {
        pCVar3 = AfxGetThread();
        if ((pCVar3 != (CWinThread *)0x0) && (*(code **)(pCVar3 + 0x54) != (code *)0x0)) {
          (**(code **)(pCVar3 + 0x54))(0,0);
        }
      }
      FUN_1002c259(*(int *)(iVar1 + 0x20));
      FUN_1002c259(*(int *)(iVar1 + 0x1c));
      FUN_1002c259(*(int *)(iVar1 + 0x18));
      FUN_1002c259(*(int *)(iVar1 + 0x14));
      FUN_1002c259(*(int *)(iVar1 + 0x24));
    }
    iVar2 = FUN_1003147e();
    iVar2 = *(int *)(iVar2 + 4);
    iVar4 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
    if (iVar2 != 0) {
      if (*(undefined **)(iVar4 + 0xc) != (undefined *)0x0) {
        SVar5 = FUN_1002168e(*(undefined **)(iVar4 + 0xc));
        if (*(uint *)(iVar2 + 0xb8) <= SVar5) goto LAB_1002c126;
      }
      if (*(int *)(iVar2 + 0xb8) != 0) {
        param_1 = 0;
        if (*(undefined **)(iVar4 + 0xc) != (undefined *)0x0) {
          param_1 = FUN_1002168e(*(undefined **)(iVar4 + 0xc));
          FUN_1001fabf(*(undefined **)(iVar4 + 0xc));
        }
        pvVar6 = _malloc(*(size_t *)(iVar2 + 0xb8));
        *(void **)(iVar4 + 0xc) = pvVar6;
        if ((pvVar6 == (void *)0x0) && (param_1 != 0)) {
          pvVar6 = _malloc(param_1);
          *(void **)(iVar4 + 0xc) = pvVar6;
        }
      }
    }
  }
LAB_1002c126:
  return *(int *)(iVar1 + 0x10) != 0;
}



/* VA 1002c135 */

undefined4 * FUN_1002c135(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  CMap<>(extraout_ECX + 1,10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CMap<>(extraout_ECX + 8,4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_100345e4;
  FUN_1002ac75(extraout_ECX + 8,7,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0xf] = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x10] = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[0x11] = *(undefined4 *)(unaff_EBP + 0x10);
  return extraout_ECX;
}



/* VA 1002c19a */

int FUN_1002c19a(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  int extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  uVar1 = *(uint *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (uVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_1002ada6((void *)(extraout_ECX + 4),uVar1);
    if (iVar3 == 0) {
      iVar3 = FUN_1002ada6((void *)(extraout_ECX + 0x20),uVar1);
      if (iVar3 == 0) {
        puVar4 = FUN_1002be90(&LAB_1002ff27);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined **)(unaff_EBP + 8) = puVar4;
        iVar3 = FUN_1002c369();
        if (iVar3 == 0) {
          FUN_1002a594();
        }
        piVar5 = FUN_1002add9((void *)(extraout_ECX + 0x20),uVar1);
        puVar4 = *(undefined **)(unaff_EBP + 8);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *piVar5 = iVar3;
        FUN_1002be90(puVar4);
        iVar2 = *(int *)(extraout_ECX + 0x40);
        *(uint *)(iVar2 + iVar3) = uVar1;
        if (*(int *)(extraout_ECX + 0x44) == 2) {
          *(uint *)(iVar2 + iVar3 + 4) = uVar1;
        }
      }
      else {
        iVar2 = *(int *)(extraout_ECX + 0x40);
        *(uint *)(iVar2 + iVar3) = uVar1;
        if (*(int *)(extraout_ECX + 0x44) == 2) {
          *(uint *)(iVar2 + iVar3 + 4) = uVar1;
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}



/* VA 1002c248 */

void Catch_1002c248(void)

{
  int unaff_EBP;

  FUN_1002be90(*(undefined **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}



/* VA 1002c259 */

void __fastcall FUN_1002c259(int param_1)

{
  undefined4 *puVar1;
  int local_10;
  int local_c;
  int *local_8;

  if (param_1 != 0) {
    local_c = -(uint)(*(int *)(param_1 + 0x2c) != 0);
    if (local_c != 0) {
      do {
        FUN_1002ae6b((void *)(param_1 + 0x20),&local_c,&local_10,(int *)&local_8);
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x40) + (int)local_8);
        *puVar1 = 0;
        if (*(int *)(param_1 + 0x44) == 2) {
          puVar1[1] = 0;
        }
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 4))(1);
        }
      } while (local_c != 0);
    }
    RemoveAll(param_1 + 0x20);
  }
  return;
}



/* VA 1002c2be */

bool FUN_1002c2be(UINT param_1)

{
  int iVar1;
  LPSTR pCVar2;
  int iVar3;
  int iVar4;
  CHAR local_108 [256];
  void *local_8;

  iVar1 = FUN_1002c342(param_1,local_108,0x100);
  if (0x100U - iVar1 < 3) {
    iVar3 = 0x100;
    do {
      iVar4 = iVar3 + 0x100;
      iVar1 = iVar4;
      pCVar2 = (LPSTR)FUN_1002b537(local_8,iVar3 + 0xff);
      iVar1 = FUN_1002c342(param_1,pCVar2,iVar1);
      iVar3 = iVar4;
    } while (iVar4 - iVar1 < 3);
    FUN_1002b586(local_8,-1);
  }
  else {
    FUN_1002b2a5(local_8,local_108);
  }
  return 0 < iVar1;
}



/* VA 1002c342 */

void FUN_1002c342(UINT param_1,LPSTR param_2,int param_3)

{
  int iVar1;

  iVar1 = FUN_1003147e();
  iVar1 = LoadStringA(*(HINSTANCE *)(iVar1 + 0xc),param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = '\0';
  }
  return;
}



/* VA 1002c369 */

undefined4 FUN_1002c369(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  uVar2 = 0;
  iVar1 = *(int *)(extraout_ECX + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (iVar1 != 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar2 = (**(code **)(extraout_ECX + 0xc))();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 1002c3a1 */

undefined4 Catch_1002c3a1(void)

{
  int unaff_EBP;

  FUN_1002ba77(*(int **)(unaff_EBP + -0x18));
  return 0x1002c38f;
}



/* VA 1002c3af */

void FUN_1002c3af(int param_1)

{
  int iVar1;

  iVar1 = FUN_1003147e();
  FUN_1003176c(0);
  FUN_10030b39((void *)(iVar1 + 0x1c),param_1);
  FUN_100317dc(0);
  return;
}



/* VA 1002c3d5 */

void __fastcall FUN_1002c3d5(undefined4 *param_1)

{
  param_1[3] = PTR_DAT_1003d148;
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  *param_1 = &PTR_LAB_1003465c;
  return;
}



/* VA 1002c3ef */

undefined * __thiscall FUN_1002c3ef(void *this,byte param_1)

{
  FUN_1002c42a();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1002c40b */

void __thiscall FUN_1002c40b(void *this,undefined4 param_1)

{
  *(undefined **)((int)this + 0xc) = PTR_DAT_1003d148;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined ***)this = &PTR_LAB_1003465c;
  *(undefined4 *)((int)this + 4) = param_1;
  return;
}



/* VA 1002c42a */

void FUN_1002c42a(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_1003465c;
  iVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if ((iVar1 != -1) && (extraout_ECX[2] != 0)) {
    FUN_1002c702((int)extraout_ECX);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_1002b168(extraout_ECX + 3);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002c472 */

int * __fastcall FUN_1002c472(HANDLE param_1)

{
  void *this;
  int *piVar1;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  HANDLE hSourceHandle;
  HANDLE *lpTargetHandle;
  DWORD DVar2;
  BOOL BVar3;
  DWORD dwOptions;
  HANDLE local_8;

  local_8 = param_1;
  this = FUN_1002bea2(0x10);
  if (this == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_1002c40b(this,0xffffffff);
  }
  dwOptions = 2;
  BVar3 = 0;
  lpTargetHandle = &local_8;
  DVar2 = 0;
  hTargetProcessHandle = GetCurrentProcess();
  hSourceHandle = *(HANDLE *)((int)param_1 + 4);
  hSourceProcessHandle = GetCurrentProcess();
  BVar3 = DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,
                          DVar2,BVar3,dwOptions);
  if (BVar3 == 0) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(1);
    }
    DVar2 = GetLastError();
    FUN_1002bade(DVar2);
  }
  piVar1[1] = (int)local_8;
  piVar1[2] = *(int *)((int)param_1 + 8);
  return piVar1;
}



/* VA 1002c4e7 */

DWORD __thiscall FUN_1002c4e7(void *this,LPCSTR param_1,uint param_2,int param_3)

{
  uint uVar1;
  HANDLE pvVar2;
  undefined4 uVar3;
  DWORD DVar4;
  DWORD DVar5;
  DWORD dwCreationDisposition;
  DWORD dwShareMode;
  CHAR local_114 [260];
  _SECURITY_ATTRIBUTES local_10;

  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0xffffffff;
  FUN_1002b0f3((int *)((int)this + 0xc));
  FUN_1002c813();
  FUN_1002b2a5((int *)((int)this + 0xc),local_114);
  DVar5 = 0;
  uVar1 = param_2 & 3;
  if (uVar1 == 0) {
    DVar5 = 0x80000000;
  }
  else if (uVar1 == 1) {
    DVar5 = 0x40000000;
  }
  else if (uVar1 == 2) {
    DVar5 = 0xc0000000;
  }
  uVar1 = param_2 & 0x70;
  DVar4 = 1;
  if ((uVar1 != 0) && (uVar1 != 0x10)) {
    dwShareMode = DVar4;
    if (uVar1 == 0x20) goto LAB_1002c57e;
    if (uVar1 == 0x30) {
      dwShareMode = 2;
      goto LAB_1002c57e;
    }
    if (uVar1 == 0x40) {
      dwShareMode = 3;
      goto LAB_1002c57e;
    }
  }
  dwShareMode = 0;
LAB_1002c57e:
  local_10.lpSecurityDescriptor = (LPVOID)0x0;
  local_10.bInheritHandle = ~(param_2 & 0xffff7fff) >> 7 & 1;
  local_10.nLength = 0xc;
  if ((param_2 & 0x1000) == 0) {
    dwCreationDisposition = 3;
  }
  else {
    dwCreationDisposition = (-(uint)((param_2 & 0x2000) != 0) & 2) + 2;
  }
  pvVar2 = CreateFileA(param_1,DVar5,dwShareMode,&local_10,dwCreationDisposition,0x80,(HANDLE)0x0);
  if (pvVar2 == (HANDLE)0xffffffff) {
    if (param_3 != 0) {
      DVar5 = GetLastError();
      *(DWORD *)(param_3 + 0xc) = DVar5;
      uVar3 = FUN_1002bc0a(DVar5);
      *(undefined4 *)(param_3 + 8) = uVar3;
      FUN_1002b2a5((void *)(param_3 + 0x10),param_1);
    }
    DVar4 = 0;
  }
  else {
    *(HANDLE *)((int)this + 4) = pvVar2;
    *(undefined4 *)((int)this + 8) = 1;
  }
  return DVar4;
}



/* VA 1002c604 */

DWORD __thiscall FUN_1002c604(void *this,LPVOID param_1,DWORD param_2)

{
  BOOL BVar1;
  DWORD DVar2;

  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    BVar1 = ReadFile(*(HANDLE *)((int)this + 4),param_1,param_2,&param_2,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_1002bade(DVar2);
    }
  }
  return param_2;
}



/* VA 1002c63e */

void __thiscall FUN_1002c63e(void *this,LPCVOID param_1,DWORD param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD DVar3;

  DVar1 = param_2;
  if (param_2 != 0) {
    BVar2 = WriteFile(*(HANDLE *)((int)this + 4),param_1,param_2,&param_2,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
      FUN_1002bade(DVar3);
    }
    if (param_2 != DVar1) {
      FUN_1002bb9f();
    }
  }
  return;
}



/* VA 1002c702 */

void __fastcall FUN_1002c702(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  bool bVar3;

  bVar3 = false;
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0xffffffff) {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 4));
    bVar3 = BVar1 == 0;
  }
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_1002b0f3((int *)(param_1 + 0xc));
  if (bVar3) {
    DVar2 = GetLastError();
    FUN_1002bade(DVar2);
  }
  return;
}



/* VA 1002c743 */

void __fastcall FUN_1002c743(int param_1)

{
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0xffffffff) {
    CloseHandle(*(HANDLE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  FUN_1002b0f3((int *)(param_1 + 0xc));
  return;
}



/* VA 1002c7b5 */

void __thiscall FUN_1002c7b5(void *this,undefined4 param_1)

{
  BOOL BVar1;
  DWORD DVar2;

  (**(code **)(*(int *)this + 0x28))(param_1,0);
  BVar1 = SetEndOfFile(*(HANDLE *)((int)this + 4));
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_1002bade(DVar2);
  }
  return;
}



/* VA 1002c7e1 */

undefined4 __fastcall FUN_1002c7e1(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;

  uVar1 = (**(code **)(*param_1 + 0x28))(0,1);
  uVar2 = (**(code **)(*param_1 + 0x28))(0,2);
  (**(code **)(*param_1 + 0x28))(uVar1,0);
  return uVar2;
}



/* VA 1002c813 */

undefined4 FUN_1002c813(void)

{
  LPSTR lpBuffer;
  DWORD DVar1;
  undefined4 uVar2;
  BOOL BVar3;
  HANDLE hFindFile;
  int unaff_EBP;

  FUN_10020434();
  lpBuffer = *(LPSTR *)(unaff_EBP + 8);
  DVar1 = GetFullPathNameA(*(LPCSTR *)(unaff_EBP + 0xc),0x104,lpBuffer,(LPSTR *)(unaff_EBP + -0x14))
  ;
  if (DVar1 == 0) {
    lstrcpynA(lpBuffer,*(LPCSTR *)(unaff_EBP + 0xc),0x104);
    uVar2 = 0;
  }
  else {
    *(undefined **)(unaff_EBP + 8) = PTR_DAT_1003d148;
    uVar2 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_1002c8e3(lpBuffer,(void *)(unaff_EBP + 8));
    BVar3 = GetVolumeInformationA
                      (*(LPCSTR *)(unaff_EBP + 8),(LPSTR)0x0,0,(LPDWORD)0x0,
                       (LPDWORD)(unaff_EBP + -0x18),(LPDWORD)(unaff_EBP + -0x10),(LPSTR)0x0,0);
    if (BVar3 != 0) {
      if ((*(byte *)(unaff_EBP + -0x10) & 2) == 0) {
        CharUpperA(lpBuffer);
      }
      if ((*(byte *)(unaff_EBP + -0x10) & 4) == 0) {
        hFindFile = FindFirstFileA(*(LPCSTR *)(unaff_EBP + 0xc),
                                   (LPWIN32_FIND_DATAA)(unaff_EBP + -0x158));
        if (hFindFile != (HANDLE)0xffffffff) {
          FindClose(hFindFile);
          lstrcpyA(*(LPSTR *)(unaff_EBP + -0x14),(LPCSTR)(unaff_EBP + -300));
        }
      }
      uVar2 = 1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_1002b168((int *)(unaff_EBP + 8));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 1002c8e3 */

void FUN_1002c8e3(LPCSTR param_1,void *param_2)

{
  byte *lpString1;
  byte *pbVar1;
  byte bVar2;

  lpString1 = (byte *)FUN_1002b537(param_2,0x104);
  _memset(lpString1,0,0x104);
  lstrcpynA((LPSTR)lpString1,param_1,0x104);
  bVar2 = *lpString1;
  pbVar1 = lpString1;
  while ((bVar2 != 0 &&
         (((bVar2 != 0x5c && (bVar2 != 0x2f)) || ((pbVar1[1] != 0x5c && (pbVar1[1] != 0x2f))))))) {
    pbVar1 = FUN_10020574(pbVar1);
    bVar2 = *pbVar1;
  }
  if (*pbVar1 == 0) {
    bVar2 = *lpString1;
    while (((bVar2 != 0 && (bVar2 != 0x5c)) && (bVar2 != 0x2f))) {
      lpString1 = FUN_10020574(lpString1);
      bVar2 = *lpString1;
    }
  }
  else {
    for (lpString1 = pbVar1 + 2;
        ((bVar2 = *lpString1, bVar2 != 0 && (bVar2 != 0x5c)) && (bVar2 != 0x2f));
        lpString1 = FUN_10020574(lpString1)) {
    }
    if (*lpString1 == 0) goto LAB_1002c964;
    do {
      lpString1 = FUN_10020574(lpString1);
LAB_1002c964:
      bVar2 = *lpString1;
    } while (((bVar2 != 0) && (bVar2 != 0x5c)) && (bVar2 != 0x2f));
  }
  if (*lpString1 != 0) {
    lpString1[1] = 0;
  }
  FUN_1002b586(param_2,-1);
  return;
}



/* VA 1002c9a9 */

int FUN_1002c9a9(byte *param_1,LPSTR param_2,int param_3)

{
  short sVar1;
  int iVar2;
  CHAR *Buf;
  CHAR local_108 [260];

  Buf = param_2;
  if (param_2 == (LPSTR)0x0) {
    Buf = local_108;
    param_3 = 0x104;
  }
  sVar1 = GetFileTitleA((LPCSTR)param_1,Buf,(WORD)param_3);
  if (sVar1 == 0) {
    if (param_2 == (LPSTR)0x0) {
      iVar2 = lstrlenA(Buf);
      iVar2 = iVar2 + 1;
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = FUN_10031683(param_1,param_2,param_3);
  }
  return iVar2;
}



/* VA 1002c9ff */

undefined4 FUN_1002c9ff(void)

{
  LPSTR pCVar1;
  void *this;
  int unaff_EBP;
  int iVar2;

  FUN_10020434();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_1002cb32(this,(int *)(unaff_EBP + -300));
  *(undefined **)(unaff_EBP + -0x10) = PTR_DAT_1003d148;
  iVar2 = 0x100;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  pCVar1 = (LPSTR)FUN_1002b537((void *)(unaff_EBP + -0x10),0x100);
  FUN_10031683((byte *)(unaff_EBP + -0x11a),pCVar1,iVar2);
  FUN_1002b586((void *)(unaff_EBP + -0x10),-1);
  FUN_1002aedd(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_1002b168((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



/* VA 1002ca81 */

undefined4 FUN_1002ca81(void)

{
  LPSTR pCVar1;
  void *this;
  int unaff_EBP;
  int iVar2;

  FUN_10020434();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_1002cb32(this,(int *)(unaff_EBP + -300));
  *(undefined **)(unaff_EBP + -0x10) = PTR_DAT_1003d148;
  iVar2 = 0x100;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  pCVar1 = (LPSTR)FUN_1002b537((void *)(unaff_EBP + -0x10),0x100);
  FUN_1002c9a9((byte *)(unaff_EBP + -0x11a),pCVar1,iVar2);
  FUN_1002b586((void *)(unaff_EBP + -0x10),-1);
  FUN_1002aedd(*(void **)(unaff_EBP + 8),(int *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_1002b168((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



/* VA 1002cb03 */

void * __thiscall FUN_1002cb03(void *this,void *param_1)

{
  int local_120 [4];
  CHAR local_10e [262];
  undefined4 local_8;

  local_8 = 0;
  FUN_1002cb32(this,local_120);
  FUN_1002b1d6(param_1,local_10e);
  return param_1;
}



/* VA 1002cb32 */

undefined4 __thiscall FUN_1002cb32(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  int *piVar6;
  _FILETIME local_1c;
  _FILETIME local_14;
  _FILETIME local_c;

  piVar2 = param_1;
  _memset(param_1,0,0x118);
  lstrcpynA((LPSTR)((int)piVar2 + 0x12),*(LPCSTR *)((int)this + 0xc),0x104);
  if (*(HANDLE *)((int)this + 4) == (HANDLE)0xffffffff) {
LAB_1002cc02:
    uVar5 = 1;
  }
  else {
    BVar3 = GetFileTime(*(HANDLE *)((int)this + 4),&local_c,&local_14,&local_1c);
    if (BVar3 != 0) {
      DVar4 = GetFileSize(*(HANDLE *)((int)this + 4),(LPDWORD)0x0);
      piVar2[3] = DVar4;
      if (DVar4 != 0xffffffff) {
        if (*(int *)(*(LPCSTR *)((int)this + 0xc) + -8) == 0) {
LAB_1002cba6:
          *(undefined1 *)(piVar2 + 4) = 0;
        }
        else {
          DVar4 = GetFileAttributesA(*(LPCSTR *)((int)this + 0xc));
          if (DVar4 == 0xffffffff) goto LAB_1002cba6;
          *(char *)(piVar2 + 4) = (char)DVar4;
        }
        piVar6 = FUN_1002a65e(&param_1,&local_c,0xffffffff);
        *piVar2 = *piVar6;
        piVar6 = FUN_1002a65e(&param_1,&local_14,0xffffffff);
        piVar2[2] = *piVar6;
        piVar6 = FUN_1002a65e(&param_1,&local_1c,0xffffffff);
        iVar1 = *piVar6;
        piVar2[1] = iVar1;
        if (*piVar2 == 0) {
          *piVar2 = iVar1;
        }
        if (piVar2[2] == 0) {
          piVar2[2] = piVar2[1];
        }
        goto LAB_1002cc02;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}



/* VA 1002cc0c */

void __fastcall FUN_1002cc0c(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* VA 1002cc26 */

void FUN_1002cc26(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *(int *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    (**(code **)(iVar1 + 0x1c))(extraout_ECX);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002cc51 */

uint FUN_1002cc51(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined *param_4,
                 undefined4 *param_5,uint param_6,undefined4 *param_7)

{
  uint uVar1;

  uVar1 = 1;
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = param_1;
    param_7[1] = param_4;
    return 1;
  }
  if (param_6 < 0x29) {
    if (param_6 == 0x28) {
      (*(code *)param_4)(param_2,param_5[1],*param_5);
      return 1;
    }
    if (param_6 == 2) {
LAB_1002cd03:
      uVar1 = (*(code *)param_4)(param_2);
      return uVar1;
    }
    if (param_6 == 0xc) {
      (*(code *)param_4)();
      return 1;
    }
    if (param_6 != 0xd) {
      if (param_6 == 0x23) {
        uVar1 = (*(code *)param_4)();
        return uVar1;
      }
      if (param_6 != 0x26) {
        if (param_6 != 0x27) {
          return 0;
        }
        uVar1 = (*(code *)param_4)(param_5[1],*param_5);
        return uVar1;
      }
      (*(code *)param_4)(param_5[1],*param_5);
      return 1;
    }
LAB_1002cd0e:
    (*(code *)param_4)(param_2);
  }
  else {
    if (param_6 == 0x29) {
      uVar1 = (*(code *)param_4)(param_2,param_5[1],*param_5);
      return uVar1;
    }
    if (param_6 == 0x2c) {
      (*(code *)param_4)(param_5);
    }
    else {
      if (param_6 != 0x2d) {
        param_2 = param_5;
        if (param_6 != 0x2e) {
          if (param_6 != 0x2f) {
            return 0;
          }
          goto LAB_1002cd03;
        }
        goto LAB_1002cd0e;
      }
      (*(code *)param_4)(param_5,param_2);
    }
    uVar1 = (uint)(param_5[7] == 0);
    param_5[7] = 0;
  }
  return uVar1;
}



/* VA 1002cd58 */

uint __thiscall
FUN_1002cd58(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  void *_Buf1;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  AFX_MSGMAP_ENTRY *pAVar4;
  uint uVar5;
  int *piVar6;

  if (param_2 == 0xfffffffe) {
    iVar1 = FUN_1003147e();
    uVar2 = (**(code **)(**(int **)(iVar1 + 0x1038) + 4))(this,param_1,param_3,param_4);
    return uVar2;
  }
  if (param_2 == 0xfffffffd) {
    param_2 = 0;
    _Buf1 = (void *)param_3[0xc];
    puVar3 = (undefined4 *)(**(code **)(*(int *)this + 0x2c))();
    do {
      if (puVar3 == (undefined4 *)0x0) {
        return param_2;
      }
      if (param_2 != 0) {
        return param_2;
      }
      piVar6 = (int *)puVar3[1];
      while ((((undefined4 *)piVar6[1] != (undefined4 *)0x0 && (piVar6[2] != 0)) && (param_2 == 0)))
      {
        if (param_1 == (undefined4 *)piVar6[1]) {
          if (_Buf1 == (void *)0x0) {
            iVar1 = *piVar6;
          }
          else {
            if ((void *)*piVar6 == (void *)0x0) goto LAB_1002cdfb;
            iVar1 = _memcmp(_Buf1,(void *)*piVar6,0x10);
          }
          if (iVar1 == 0) {
            param_2 = 1;
            param_3[1] = piVar6[2];
          }
        }
LAB_1002cdfb:
        piVar6 = piVar6 + 3;
      }
      puVar3 = (undefined4 *)*puVar3;
    } while( true );
  }
  if (param_2 != 0xffffffff) {
    uVar2 = param_2 & 0xffff;
    uVar5 = param_2 >> 0x10;
    param_2 = uVar2;
    if (uVar5 != 0) goto LAB_1002ce20;
  }
  uVar5 = 0x111;
LAB_1002ce20:
  puVar3 = (undefined4 *)(**(code **)(*(int *)this + 0x28))();
  while( true ) {
    if (puVar3 == (undefined4 *)0x0) {
      return 0;
    }
    pAVar4 = AfxFindMessageEntry((AFX_MSGMAP_ENTRY *)puVar3[1],uVar5,param_2,(uint)param_1);
    if (pAVar4 != (AFX_MSGMAP_ENTRY *)0x0) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  uVar2 = FUN_1002cc51(this,param_1,param_2,*(undefined **)(pAVar4 + 0x14),param_3,
                       *(uint *)(pAVar4 + 0x10),param_4);
  return uVar2;
}



/* VA 1002ce78 */

void FUN_1002ce78(void)

{
  int iVar1;

  iVar1 = FUN_1003147e();
  (**(code **)(**(int **)(iVar1 + 4) + 0x90))(1);
  return;
}



/* VA 1002ce8d */

void FUN_1002ce8d(void)

{
  int iVar1;

  iVar1 = FUN_1003147e();
  (**(code **)(**(int **)(iVar1 + 4) + 0x90))(0xffffffff);
  return;
}



/* VA 1002cec9 */

/* Library Function - Single Match
    public: __thiscall CCmdUI::CCmdUI(void)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __thiscall CCmdUI::CCmdUI(CCmdUI *this)

{
  *(undefined ***)this = &PTR_FUN_100347a8;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}



/* VA 1002ceef */

void __thiscall FUN_1002ceef(void *this,int param_1)

{
  int iVar1;
  HWND pHVar2;
  void *pvVar3;

  if (*(int *)((int)this + 0xc) == 0) {
    if (param_1 == 0) {
      iVar1 = *(int *)((int)this + 0x14);
      pHVar2 = GetFocus();
      if (pHVar2 == *(HWND *)(iVar1 + 0x1c)) {
        GetParent(*(HWND *)(iVar1 + 0x1c));
        pvVar3 = FUN_1002d53a();
        pHVar2 = (HWND)0x0;
        if (*(int *)((int)this + 0x14) != 0) {
          pHVar2 = *(HWND *)(*(int *)((int)this + 0x14) + 0x1c);
        }
        GetNextDlgTabItem(*(HWND *)((int)pvVar3 + 0x1c),pHVar2,0);
        pvVar3 = FUN_1002d53a();
        FUN_1002f692((int)pvVar3);
      }
    }
    FUN_1002f66b(*(void **)((int)this + 0x14),param_1);
  }
  else {
    if (*(int *)((int)this + 0x10) != 0) {
      return;
    }
    EnableMenuItem(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),
                   (-(uint)(param_1 != 0) & 0xfffffffd) + 3 | 0x400);
  }
  *(undefined4 *)((int)this + 0x18) = 1;
  return;
}



/* VA 1002cf7f */

void __thiscall FUN_1002cf7f(void *this,WPARAM param_1)

{
  uint uVar1;

  if (*(int *)((int)this + 0xc) == 0) {
    uVar1 = SendMessageA(*(HWND *)(*(int *)((int)this + 0x14) + 0x1c),0x87,0,0);
    if ((uVar1 & 0x2000) != 0) {
      SendMessageA(*(HWND *)(*(int *)((int)this + 0x14) + 0x1c),0xf1,param_1,0);
    }
  }
  else if (*(int *)((int)this + 0x10) == 0) {
    CheckMenuItem(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),
                  (uint)CONCAT11(4,-(param_1 != 0) & 8));
  }
  return;
}



/* VA 1002cfe1 */

void __thiscall FUN_1002cfe1(void *this,int param_1)

{
  (**(code **)(*(int *)this + 4))(param_1 != 0);
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x10) == 0)) {
    if ((DAT_10043648 == (HBITMAP)0x0) && (FUN_10031803(), DAT_10043648 == (HBITMAP)0x0)) {
      return;
    }
    SetMenuItemBitmaps(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),0x400,
                       (HBITMAP)0x0,DAT_10043648);
  }
  return;
}



/* VA 1002d037 */

void __thiscall FUN_1002d037(void *this,LPCSTR param_1)

{
  UINT UVar1;

  if (*(int *)((int)this + 0xc) == 0) {
    FUN_1002fe80(*(HWND *)(*(int *)((int)this + 0x14) + 0x1c),param_1);
  }
  else if (*(int *)((int)this + 0x10) == 0) {
    UVar1 = GetMenuState(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),0x400);
    ModifyMenuA(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),
                UVar1 & 0xfffff6fb | 0x400,*(UINT_PTR *)((int)this + 4),param_1);
  }
  return;
}



/* VA 1002d0ae */

void FUN_1002d0ae(void)

{
  FUN_1002d1da(&DAT_10043590,0);
  return;
}



/* VA 1002d0bb */

void FUN_1002d0bb(void)

{
  FUN_1001f5cf(&LAB_1002d0c7);
  return;
}



/* VA 1002d0ec */

void FUN_1002d0ec(void)

{
  FUN_1002d1da(&DAT_10043550,1);
  return;
}



/* VA 1002d0f9 */

void FUN_1002d0f9(void)

{
  FUN_1001f5cf(&LAB_1002d105);
  return;
}



/* VA 1002d12a */

void FUN_1002d12a(void)

{
  FUN_1002d1da(&DAT_10043510,0xffffffff);
  return;
}



/* VA 1002d137 */

void FUN_1002d137(void)

{
  FUN_1001f5cf(&LAB_1002d143);
  return;
}



/* VA 1002d168 */

void FUN_1002d168(void)

{
  FUN_1002d1da(&DAT_100434d0,0xfffffffe);
  return;
}



/* VA 1002d175 */

void FUN_1002d175(void)

{
  FUN_1001f5cf(&LAB_1002d181);
  return;
}



/* VA 1002d19c */

undefined4 * __fastcall FUN_1002d19c(undefined4 *param_1)

{
  FUN_1002cc0c((int)param_1);
  *param_1 = &PTR_LAB_10034bb0;
  _memset(param_1 + 7,0,0x20);
  return param_1;
}



/* VA 1002d1be */

/* Library Function - Single Match
    public: virtual void * __thiscall CWnd::`scalar deleting destructor'(unsigned int)

   Library: Visual Studio 2003 Release */

void * __thiscall CWnd::_scalar_deleting_destructor_(CWnd *this,uint param_1)

{
  ~CWnd(this);
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 1002d1da */

undefined4 * __thiscall FUN_1002d1da(void *this,undefined4 param_1)

{
  FUN_1002cc0c((int)this);
  *(undefined ***)this = &PTR_LAB_10034bb0;
  _memset((undefined4 *)((int)this + 0x1c),0,0x20);
  *(undefined4 *)((int)this + 0x1c) = param_1;
  return this;
}



/* VA 1002d206 */

void FUN_1002d206(int param_1,LPRECT param_2,undefined4 *param_3)

{
  undefined4 uVar1;

  GetWindowRect(*(HWND *)(param_1 + 0x1c),param_2);
  uVar1 = FUN_1002f5cd(param_1);
  *param_3 = uVar1;
  return;
}



/* VA 1002d229 */

void FUN_1002d229(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  tagRECT local_14;

  if (((((param_3 & 0x10000000) == 0) &&
       (uVar1 = FUN_1002f5cd((int)param_1), (uVar1 & 0x50000000) == 0)) &&
      (GetWindowRect((HWND)param_1[7],&local_14), *param_2 == local_14.left)) &&
     (param_2[1] == local_14.top)) {
    GetWindow((HWND)param_1[7],4);
    pvVar2 = FUN_1002d53a();
    if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_1002f650((int)pvVar2), iVar3 != 0)) {
      return;
    }
    iVar3 = (**(code **)(*param_1 + 0xac))();
    if (iVar3 != 0) {
      FUN_1002f058(param_1,0);
    }
  }
  return;
}



/* VA 1002d2a2 */

void FUN_1002d2a2(int param_1,WPARAM param_2,int param_3)

{
  uint uVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 local_c;
  undefined4 local_8;

  uVar1 = FUN_1002f5cd(param_1);
  if ((uVar1 & 0x40000000) == 0) {
    pvVar2 = FUN_1002e9b3(param_1);
    pvVar3 = FUN_1002e9b3(param_3);
    if (pvVar2 != pvVar3) {
      local_c = *(undefined4 *)(param_1 + 0x1c);
      if (param_3 == 0) {
        local_8 = 0;
      }
      else {
        local_8 = *(undefined4 *)(param_3 + 0x1c);
      }
      SendMessageA(*(HWND *)((int)pvVar2 + 0x1c),0x36e,param_2,(LPARAM)&local_c);
    }
  }
  return;
}



/* VA 1002d303 */

undefined4 FUN_1002d303(int param_1,int param_2,int param_3)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;

  if (((param_2 == -2) && (((param_3 == 0x201 || (param_3 == 0x207)) || (param_3 == 0x204)))) &&
     (pvVar1 = FUN_1002e9b3(param_1), pvVar1 != (void *)0x0)) {
    GetLastActivePopup(*(HWND *)((int)pvVar1 + 0x1c));
    pvVar1 = FUN_1002d53a();
    if (pvVar1 != (void *)0x0) {
      GetForegroundWindow();
      pvVar2 = FUN_1002d53a();
      if ((pvVar1 != pvVar2) && (iVar3 = FUN_1002f650((int)pvVar1), iVar3 != 0)) {
        SetForegroundWindow(*(HWND *)((int)pvVar1 + 0x1c));
        return 1;
      }
    }
  }
  return 0;
}



/* VA 1002d379 */

undefined4 FUN_1002d379(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *puVar6;

  FUN_10020434();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  iVar2 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  puVar5 = (undefined4 *)(iVar2 + 0x34);
  puVar6 = (undefined4 *)(unaff_EBP + -0x40);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(unaff_EBP + 0x10);
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(unaff_EBP + 0x14);
  uVar3 = *(undefined4 *)(unaff_EBP + 0x18);
  *(int *)(iVar2 + 0x38) = iVar4;
  *(undefined4 *)(iVar2 + 0x40) = uVar3;
  if ((iVar4 == 2) && ((int *)piVar1[0xd] != (int *)0x0)) {
    (**(code **)(*(int *)piVar1[0xd] + 0x5c))(0);
  }
  *(undefined4 *)(unaff_EBP + 8) = 0;
  if (iVar4 == 0x110) {
    FUN_1002d206((int)piVar1,(LPRECT)(unaff_EBP + -0x24),(undefined4 *)(unaff_EBP + 8));
  }
  uVar3 = (**(code **)(*piVar1 + 0x98))
                    (iVar4,*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18));
  *(undefined4 *)(unaff_EBP + 0x18) = uVar3;
  if (iVar4 == 0x110) {
    FUN_1002d229(piVar1,(int *)(unaff_EBP + -0x24),*(uint *)(unaff_EBP + 8));
    uVar3 = FUN_1002d44d();
    return uVar3;
  }
  uVar3 = *(undefined4 *)(unaff_EBP + 0x18);
  puVar5 = (undefined4 *)(unaff_EBP + -0x40);
  puVar6 = (undefined4 *)(iVar2 + 0x34);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 1002d423 */

undefined * Catch_1002d423(void)

{
  CWinThread *pCVar1;
  undefined4 uVar2;
  int unaff_EBP;

  pCVar1 = AfxGetThread();
  uVar2 = (**(code **)(*(int *)pCVar1 + 0x6c))
                    (*(undefined4 *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x14) + 0x34);
  *(undefined4 *)(unaff_EBP + 0x18) = uVar2;
  FUN_1002ba77(*(int **)(unaff_EBP + 0xc));
  return &DAT_1002d44a;
}



/* VA 1002d44d */

undefined4 FUN_1002d44d(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar3;
  undefined4 *puVar4;

  uVar1 = *(undefined4 *)(unaff_EBP + 0x18);
  puVar3 = (undefined4 *)(unaff_EBP + -0x40);
  puVar4 = (undefined4 *)(unaff_EBX + 0x34);
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}



/* VA 1002d46c */

int FUN_1002d46c(void)

{
  int iVar1;
  LONG LVar2;
  DWORD DVar3;

  iVar1 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  LVar2 = GetMessageTime();
  *(LONG *)(iVar1 + 0x44) = LVar2;
  DVar3 = GetMessagePos();
  *(int *)(iVar1 + 0x48) = (int)(short)DVar3;
  *(int *)(iVar1 + 0x4c) = (int)(short)(DVar3 >> 0x10);
  return iVar1 + 0x34;
}



/* VA 1002d4a1 */

void __fastcall FUN_1002d4a1(int *param_1)

{
  int iVar1;

  iVar1 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  (**(code **)(*param_1 + 0xa0))
            (*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
             *(undefined4 *)(iVar1 + 0x40));
  return;
}



/* VA 1002d4c8 */

undefined4 FUN_1002d4c8(void)

{
  int iVar1;
  undefined *puVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int unaff_EBP;

  FUN_10020434();
  iVar1 = FUN_100314a4();
  if ((*(int *)(iVar1 + 0x14) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    puVar2 = FUN_1002be90(&LAB_1002ff27);
    pvVar3 = FUN_1002bea2(0x48);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_1002c135();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 **)(iVar1 + 0x14) = puVar4;
    FUN_1002be90(puVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(iVar1 + 0x14);
}



/* VA 1002d53a */

void * FUN_1002d53a(void)

{
  int iVar1;
  void *this;

  iVar1 = FUN_1002d4c8();
  this = (void *)FUN_1002c19a();
  FUN_1002f6b3(this,iVar1);
  return this;
}



/* VA 1002d561 */

undefined4 FUN_1002d561(uint param_1)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_1002d4c8();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_1002ada6((void *)(iVar1 + 4),param_1);
  }
  return uVar2;
}



/* VA 1002d57f */

bool __thiscall FUN_1002d57f(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;

  if (param_1 != 0) {
    iVar1 = FUN_1002d4c8();
    *(uint *)((int)this + 0x1c) = param_1;
    puVar2 = FUN_1002add9((void *)(iVar1 + 4),param_1);
    *puVar2 = this;
    FUN_1002f6b3(this,iVar1);
  }
  return param_1 != 0;
}



/* VA 1002d5b8 */

/* Library Function - Single Match
    public: struct HWND__ * __thiscall CWnd::Detach(void)

   Library: Visual Studio */

HWND__ * __thiscall CWnd::Detach(CWnd *this)

{
  HWND__ *pHVar1;
  int iVar2;

  pHVar1 = *(HWND__ **)(this + 0x1c);
  if (pHVar1 != (HWND__ *)0x0) {
    iVar2 = FUN_1002d4c8();
    if (iVar2 != 0) {
      FUN_1002ae29((void *)(iVar2 + 4),*(uint *)(this + 0x1c));
    }
    *(undefined4 *)(this + 0x1c) = 0;
  }
  *(undefined4 *)(this + 0x38) = 0;
  return pHVar1;
}



/* VA 1002d5e6 */

undefined4 FUN_1002d5e6(uint param_1,int param_2)

{
  undefined4 uVar1;

  if (param_2 == 0x360) {
    uVar1 = 1;
  }
  else {
    FUN_1002d561(param_1);
    uVar1 = FUN_1002d379();
  }
  return uVar1;
}



/* VA 1002d615 */

undefined * FUN_1002d615(void)

{
  return FUN_1002d5e6;
}



/* VA 1002d61b */

undefined4 FUN_1002d61b(void)

{
  HWND hWnd;
  ATOM nAtom;
  HANDLE pvVar1;
  int *piVar2;
  LRESULT LVar3;
  void *pvVar4;
  int iVar5;
  void *pvVar6;
  int unaff_EBP;
  bool bVar7;

  FUN_10020434();
  hWnd = *(HWND *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffb4;
  pvVar1 = GetPropA(hWnd,"AfxOldWndProc423");
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(HANDLE *)(unaff_EBP + -0x18) = pvVar1;
  iVar5 = *(int *)(unaff_EBP + 0xc);
  bVar7 = true;
  if (iVar5 == 6) {
    pvVar4 = FUN_1002d53a();
    pvVar6 = FUN_1002d53a();
    FUN_1002d2a2((int)pvVar6,*(WPARAM *)(unaff_EBP + 0x10),(int)pvVar4);
LAB_1002d71f:
    if (!bVar7) goto LAB_1002d6ac;
  }
  else {
    if (iVar5 == 0x20) {
      pvVar4 = FUN_1002d53a();
      iVar5 = FUN_1002d303((int)pvVar4,(int)*(short *)(unaff_EBP + 0x14),
                           *(uint *)(unaff_EBP + 0x14) >> 0x10);
      bVar7 = iVar5 == 0;
      goto LAB_1002d71f;
    }
    if (iVar5 == 0x82) {
      SetWindowLongA(hWnd,-4,*(LONG *)(unaff_EBP + -0x18));
      RemovePropA(hWnd,"AfxOldWndProc423");
      nAtom = GlobalFindAtomA("AfxOldWndProc423");
      GlobalDeleteAtom(nAtom);
    }
    else if (iVar5 == 0x110) {
      piVar2 = FUN_1002d53a();
      FUN_1002d206((int)piVar2,(LPRECT)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x1c));
      LVar3 = CallWindowProcA(*(WNDPROC *)(unaff_EBP + -0x18),hWnd,0x110,
                              *(WPARAM *)(unaff_EBP + 0x10),*(LPARAM *)(unaff_EBP + 0x14));
      *(LRESULT *)(unaff_EBP + -0x14) = LVar3;
      FUN_1002d229(piVar2,(int *)(unaff_EBP + -0x30),*(uint *)(unaff_EBP + -0x1c));
      goto LAB_1002d6ac;
    }
  }
  LVar3 = CallWindowProcA(*(WNDPROC *)(unaff_EBP + -0x18),hWnd,*(UINT *)(unaff_EBP + 0xc),
                          *(WPARAM *)(unaff_EBP + 0x10),*(LPARAM *)(unaff_EBP + 0x14));
  *(LRESULT *)(unaff_EBP + -0x14) = LVar3;
LAB_1002d6ac:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



/* VA 1002d73e */

undefined4 Catch_1002d73e(void)

{
  CWinThread *pCVar1;
  undefined4 uVar2;
  int unaff_EBP;

  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + 0x14);
  pCVar1 = AfxGetThread();
  uVar2 = (**(code **)(*(int *)pCVar1 + 0x6c))(*(undefined4 *)(unaff_EBP + -0x20),unaff_EBP + -0x4c)
  ;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_1002ba77(*(int **)(unaff_EBP + -0x20));
  return 0x1002d6ac;
}



/* VA 1002d77a */

undefined4 FUN_1002d77a(undefined4 param_1,int param_2,HDC param_3,HWND param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;

  iVar1 = FUN_100310c7();
  if (((*(HANDLE *)(iVar1 + 4) != (HANDLE)0x0) &&
      ((((param_2 == 0x135 || (param_2 == 0x136)) || (param_2 == 0x138)) ||
       ((param_2 == 0x137 || (param_2 == 0x134)))))) &&
     (iVar2 = FUN_1002efe3(param_3,param_4,param_2 + -0x132,*(HANDLE *)(iVar1 + 4),
                           *(COLORREF *)(iVar1 + 8)), iVar2 != 0)) {
    return *(undefined4 *)(iVar1 + 4);
  }
  uVar3 = FUN_1002d61b();
  return uVar3;
}



/* VA 1002d7f6 */

LRESULT FUN_1002d7f6(int param_1,HWND param_2,int *param_3)

{
  int *this;
  LRESULT LVar1;
  int iVar2;
  DWORD DVar3;
  int *lpString1;
  int iVar4;
  LONG *pLVar5;
  undefined *puVar6;
  undefined *puVar7;
  HANDLE hData;
  HANDLE pvVar8;
  code *dwNewLong;
  int local_14 [2];
  uint local_c;
  int local_8;

  local_8 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  if (param_1 != 3) {
    LVar1 = CallNextHookEx(*(HHOOK *)(local_8 + 0x2c),param_1,(WPARAM)param_2,(LPARAM)param_3);
    return LVar1;
  }
  this = *(int **)(local_8 + 0x14);
  iVar4 = *param_3;
  iVar2 = FUN_1003147e();
  local_c = (uint)*(byte *)(iVar2 + 0x14);
  if ((this == (int *)0x0) && (((*(byte *)(iVar4 + 0x23) & 0x40) != 0 || (local_c != 0))))
  goto LAB_1002d9bf;
  if (DAT_10043670 != 0) {
    DVar3 = GetClassLongA(param_2,-0x1a);
    if ((DVar3 & 0x10000) != 0) goto LAB_1002d9bf;
    lpString1 = *(int **)(iVar4 + 0x28);
    if ((short)((uint)lpString1 >> 0x10) == 0) {
      local_14[0] = CONCAT31(local_14[0]._1_3_,(byte)local_14[0] & (byte)((uint)lpString1 >> 0x10));
      GlobalGetAtomNameA(*(ATOM *)(iVar4 + 0x28),(LPSTR)local_14,5);
      lpString1 = local_14;
    }
    iVar4 = lstrcmpiA((LPCSTR)lpString1,"ime");
    if (iVar4 == 0) goto LAB_1002d9bf;
  }
  if (this == (int *)0x0) {
    hData = (HANDLE)GetWindowLongA(param_2,-4);
    if ((hData != (HANDLE)0x0) &&
       (pvVar8 = GetPropA(param_2,"AfxOldWndProc423"), pvVar8 == (HANDLE)0x0)) {
      SetPropA(param_2,"AfxOldWndProc423",hData);
      pvVar8 = GetPropA(param_2,"AfxOldWndProc423");
      if (pvVar8 == hData) {
        GlobalAddAtomA("AfxOldWndProc423");
        dwNewLong = FUN_1002d77a;
        if (*(int *)(local_8 + 0x28) == 0) {
          dwNewLong = FUN_1002d61b;
        }
        SetWindowLongA(param_2,-4,(LONG)dwNewLong);
      }
    }
    goto LAB_1002d9bf;
  }
  FUN_1002d57f(this,(uint)param_2);
  (**(code **)(*this + 0x50))();
  pLVar5 = (LONG *)(**(code **)(*this + 0x80))();
  iVar4 = DAT_100435f0;
  if ((((DAT_10043654 == 0) && (local_c == 0)) && (DAT_100435f0 != 0)) &&
     ((*(int *)(DAT_100435f0 + 0x20) != 0 && (local_14[0] = FUN_1002d379(), local_14[0] != 0)))) {
    puVar6 = FUN_1002d615();
    puVar7 = (undefined *)GetWindowLongA(param_2,-4);
    (**(code **)(iVar4 + 0x20))(param_2,local_14[0]);
    if (puVar7 != puVar6) {
      puVar7 = (undefined *)SetWindowLongA(param_2,-4,(LONG)puVar6);
LAB_1002d953:
      *pLVar5 = (LONG)puVar7;
    }
  }
  else {
    puVar6 = FUN_1002d615();
    puVar7 = (undefined *)SetWindowLongA(param_2,-4,(LONG)puVar6);
    if (puVar7 != puVar6) goto LAB_1002d953;
  }
  *(undefined4 *)(local_8 + 0x14) = 0;
LAB_1002d9bf:
  iVar4 = local_8;
  LVar1 = CallNextHookEx(*(HHOOK *)(local_8 + 0x2c),3,(WPARAM)param_2,(LPARAM)param_3);
  if (local_c != 0) {
    UnhookWindowsHookEx(*(HHOOK *)(iVar4 + 0x2c));
    *(undefined4 *)(iVar4 + 0x2c) = 0;
  }
  return LVar1;
}



/* VA 1002d9ec */

void FUN_1002d9ec(int param_1)

{
  int iVar1;
  DWORD dwThreadId;
  HHOOK pHVar2;

  iVar1 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  if (*(int *)(iVar1 + 0x14) != param_1) {
    if (*(int *)(iVar1 + 0x2c) == 0) {
      dwThreadId = GetCurrentThreadId();
      pHVar2 = SetWindowsHookExA(5,FUN_1002d7f6,(HINSTANCE)0x0,dwThreadId);
      *(HHOOK *)(iVar1 + 0x2c) = pHVar2;
      if (pHVar2 == (HHOOK)0x0) {
        FUN_1002a594();
      }
    }
    *(int *)(iVar1 + 0x14) = param_1;
  }
  return;
}



/* VA 1002da38 */

undefined4 FUN_1002da38(void)

{
  int iVar1;
  int iVar2;

  iVar1 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  iVar2 = FUN_1003147e();
  if ((*(char *)(iVar2 + 0x14) != '\0') && (*(HHOOK *)(iVar1 + 0x2c) != (HHOOK)0x0)) {
    UnhookWindowsHookEx(*(HHOOK *)(iVar1 + 0x2c));
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  if (*(int *)(iVar1 + 0x14) != 0) {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    return 0;
  }
  return 1;
}



/* VA 1002da7a */

bool __thiscall
FUN_1002da7a(void *this,DWORD param_1,LPCSTR param_2,LPCSTR param_3,DWORD param_4,int param_5,
            int param_6,int param_7,int param_8,HWND param_9,HMENU param_10,LPVOID param_11)

{
  int iVar1;
  HWND pHVar2;
  bool bVar3;
  LPVOID local_34;
  HINSTANCE local_30;
  HMENU local_2c;
  HWND local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  DWORD local_14;
  LPCSTR local_10;
  LPCSTR local_c;
  DWORD local_8;

  local_8 = param_1;
  local_c = param_2;
  local_10 = param_3;
  local_14 = param_4;
  local_18 = param_5;
  local_1c = param_6;
  local_20 = param_7;
  local_24 = param_8;
  local_28 = param_9;
  local_2c = param_10;
  iVar1 = FUN_1003147e();
  local_30 = *(HINSTANCE *)(iVar1 + 8);
  local_34 = param_11;
  iVar1 = (**(code **)(*(int *)this + 0x5c))(&local_34);
  if (iVar1 == 0) {
    (**(code **)(*(int *)this + 0xa4))();
    bVar3 = false;
  }
  else {
    FUN_1002d9ec((int)this);
    pHVar2 = CreateWindowExA(local_8,local_c,local_10,local_14,local_18,local_1c,local_20,local_24,
                             local_28,local_2c,local_30,local_34);
    iVar1 = FUN_1002da38();
    if (iVar1 == 0) {
      (**(code **)(*(int *)this + 0xa4))();
    }
    bVar3 = pHVar2 != (HWND)0x0;
  }
  return bVar3;
}



/* VA 1002db40 */

undefined4 FUN_1002db40(int param_1)

{
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_1002f2f0(1);
    *(char **)(param_1 + 0x28) = "AfxWnd42s";
  }
  return 1;
}



/* VA 1002db60 */

void __thiscall
FUN_1002db60(void *this,LPCSTR param_1,LPCSTR param_2,uint param_3,int *param_4,int param_5,
            HMENU param_6,LPVOID param_7)

{
  HWND pHVar1;

  if (param_5 == 0) {
    pHVar1 = (HWND)0x0;
  }
  else {
    pHVar1 = *(HWND *)(param_5 + 0x1c);
  }
  FUN_1002da7a(this,0,param_1,param_2,param_3 | 0x40000000,*param_4,param_4[1],param_4[2] - *param_4
               ,param_4[3] - param_4[1],pHVar1,param_6,param_7);
  return;
}



/* VA 1002dbac */

/* Library Function - Single Match
    public: virtual __thiscall CWnd::~CWnd(void)

   Library: Visual Studio 2003 Release */

void __thiscall CWnd::~CWnd(CWnd *this)

{
  int iVar1;
  CWnd *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(CWnd **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined ***)extraout_ECX = &PTR_LAB_10034bb0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((((*(int *)(extraout_ECX + 0x1c) != 0) && (extraout_ECX != (CWnd *)&DAT_10043590)) &&
      (extraout_ECX != (CWnd *)&DAT_10043550)) &&
     ((extraout_ECX != (CWnd *)&DAT_10043510 && (extraout_ECX != (CWnd *)&DAT_100434d0)))) {
    FUN_1002dd6a(extraout_ECX);
  }
  if (*(int **)(extraout_ECX + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(extraout_ECX + 0x34) + 4))(1);
  }
  iVar1 = *(int *)(extraout_ECX + 0x38);
  if ((iVar1 != 0) && (*(CWnd **)(iVar1 + 0x24) == extraout_ECX)) {
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1002cc26();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002dc28 */

void __fastcall FUN_1002dc28(int *param_1)

{
  if ((int *)param_1[0xd] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xd] + 4))(1);
  }
  param_1[0xd] = 0;
  FUN_1002d4a1(param_1);
  return;
}



/* VA 1002dc46 */

void __fastcall FUN_1002dc46(CWnd *param_1)

{
  bool bVar1;
  CWinThread *pCVar2;
  int iVar3;
  undefined3 extraout_var;
  LONG LVar4;
  LONG LVar5;
  int *piVar6;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;

  pCVar2 = AfxGetThread();
  if (pCVar2 == (CWinThread *)0x0) goto LAB_1002dc91;
  if (*(CWnd **)(pCVar2 + 0x1c) == param_1) {
    iVar3 = FUN_1003147e();
    if (*(char *)(iVar3 + 0x14) == '\0') {
      iVar3 = FUN_1003147e();
      if (pCVar2 == *(CWinThread **)(iVar3 + 4)) {
        bVar1 = FUN_1003098c();
        if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_1002dc86;
      }
      AfxPostQuitMessage(0);
    }
LAB_1002dc86:
    *(undefined4 *)(pCVar2 + 0x1c) = 0;
  }
  if (*(CWnd **)(pCVar2 + 0x20) == param_1) {
    *(undefined4 *)(pCVar2 + 0x20) = 0;
  }
LAB_1002dc91:
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x30) + 0x50))();
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(int **)(param_1 + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x34) + 4))(1);
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  if (((byte)param_1[0x24] & 1) != 0) {
    iVar3 = FUN_1003124c();
    iVar3 = *(int *)(iVar3 + 0xcc);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x1c) != 0)) {
      _memset(&local_30,0,0x2c);
      local_28 = *(undefined4 *)(param_1 + 0x1c);
      local_30 = 0x28;
      local_2c = 1;
      local_24 = local_28;
      SendMessageA(*(HWND *)(iVar3 + 0x1c),0x405,0,(LPARAM)&local_30);
    }
  }
  LVar4 = GetWindowLongA(*(HWND *)(param_1 + 0x1c),-4);
  FUN_1002d4a1((int *)param_1);
  LVar5 = GetWindowLongA(*(HWND *)(param_1 + 0x1c),-4);
  if (LVar5 == LVar4) {
    piVar6 = (int *)(**(code **)(*(int *)param_1 + 0x80))();
    if (*piVar6 != 0) {
      SetWindowLongA(*(HWND *)(param_1 + 0x1c),-4,*piVar6);
    }
  }
  CWnd::Detach(param_1);
  (**(code **)(*(int *)param_1 + 0xa4))();
  return;
}



/* VA 1002dd6a */

BOOL __fastcall FUN_1002dd6a(CWnd *param_1)

{
  int iVar1;
  BOOL BVar2;

  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  iVar1 = FUN_1002d4c8();
  iVar1 = FUN_1002ada6((void *)(iVar1 + 4),*(uint *)(param_1 + 0x1c));
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    BVar2 = DestroyWindow(*(HWND *)(param_1 + 0x1c));
  }
  else {
    BVar2 = (**(code **)(**(int **)(param_1 + 0x38) + 0x50))();
  }
  if (iVar1 == 0) {
    CWnd::Detach(param_1);
  }
  return BVar2;
}



/* VA 1002ddb7 */

void __thiscall FUN_1002ddb7(void *this,UINT param_1,WPARAM param_2,LPARAM param_3)

{
  int *piVar1;
  WNDPROC lpPrevWndFunc;

  lpPrevWndFunc = *(WNDPROC *)((int)this + 0x28);
  if (lpPrevWndFunc == (WNDPROC)0x0) {
    piVar1 = (int *)(**(code **)(*(int *)this + 0x80))();
    lpPrevWndFunc = (WNDPROC)*piVar1;
    if (lpPrevWndFunc == (WNDPROC)0x0) {
      DefWindowProcA(*(HWND *)((int)this + 0x1c),param_1,param_2,param_3);
      return;
    }
  }
  CallWindowProcA(lpPrevWndFunc,*(HWND *)((int)this + 0x1c),param_1,param_2,param_3);
  return;
}



/* VA 1002de02 */

undefined4 __thiscall FUN_1002de02(void *this,undefined4 param_1)

{
  int iVar1;

  iVar1 = FUN_1003147e();
  if (*(code **)(iVar1 + 0x1034) != (code *)0x0) {
    (**(code **)(iVar1 + 0x1034))(param_1,this);
  }
  return 0;
}



/* VA 1002de78 */

uint __thiscall FUN_1002de78(void *this,LONG param_1,LONG param_2,uint *param_3)

{
  HWND hWnd;
  uint uVar1;
  uint uVar2;

  hWnd = FUN_1002fe0b(*(HWND *)((int)this + 0x1c),param_1,param_2);
  if (hWnd == (HWND)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = GetDlgCtrlID(hWnd);
    uVar1 = uVar1 & 0xffff;
    if ((param_3 != (uint *)0x0) && (0x27 < *param_3)) {
      uVar2 = *(uint *)((int)this + 0x1c);
      param_3[1] = param_3[1] | 1;
      param_3[9] = 0xffffffff;
      param_3[2] = uVar2;
      param_3[3] = (uint)hWnd;
      uVar2 = SendMessageA(hWnd,0x87,0,0);
      if ((uVar2 & 0x2000) == 0) {
        param_3[1] = param_3[1] | 0x80000002;
      }
    }
  }
  return uVar1;
}



/* VA 1002dee9 */

void __thiscall FUN_1002dee9(void *this,undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;

  if (*param_2 == 1) {
    piVar1 = (int *)FUN_1002f8c0(param_2[5]);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(param_2);
      return;
    }
  }
  else {
    iVar2 = FUN_1002eb29();
    if (iVar2 != 0) {
      return;
    }
  }
  FUN_1002d4a1(this);
  return;
}



/* VA 1002df26 */

undefined4 __thiscall FUN_1002df26(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;

  iVar1 = FUN_1002eb29();
  if (iVar1 == 0) {
    param_2 = FUN_1002d4a1(this);
  }
  return param_2;
}



/* VA 1002df70 */

void * __thiscall FUN_1002df70(void *this,undefined4 param_1,void *param_2)

{
  int iVar1;

  if ((param_2 == (void *)0x0) || (iVar1 = FUN_1002eafc(param_2,&param_2), iVar1 == 0)) {
    param_2 = (void *)FUN_1002d4a1(this);
  }
  return param_2;
}



/* VA 1002e076 */

undefined4 FUN_1002e076(void)

{
  WNDCLASSA *lpWndClass;
  ATOM AVar1;
  BOOL BVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;

  FUN_10020434();
  lpWndClass = *(WNDCLASSA **)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  BVar2 = GetClassInfoA(lpWndClass->hInstance,lpWndClass->lpszClassName,
                        (LPWNDCLASSA)(unaff_EBP + -0x38));
  if (BVar2 == 0) {
    AVar1 = RegisterClassA(lpWndClass);
    if (AVar1 == 0) {
      uVar3 = 0;
      goto LAB_1002e0f6;
    }
    iVar4 = FUN_1003147e();
    if (*(char *)(iVar4 + 0x14) != '\0') {
      FUN_1003176c(1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar4 = FUN_1003147e();
      lstrcatA((LPSTR)(iVar4 + 0x34),lpWndClass->lpszClassName);
      *(undefined1 *)(unaff_EBP + 10) = 10;
      *(undefined1 *)(unaff_EBP + 0xb) = 0;
      lstrcatA((LPSTR)(iVar4 + 0x34),(LPCSTR)(unaff_EBP + 10));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_100317dc(1);
    }
  }
  uVar3 = 1;
LAB_1002e0f6:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 1002e107 */

void Catch_1002e107(void)

{
  FUN_100317dc(1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}



/* VA 1002e15d */

void FUN_1002e15d(void)

{
  int iVar1;
  void *pvVar2;
  HWND hWnd;
  BOOL BVar3;
  int *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  iVar1 = FUN_1003147e();
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar1 + 4);
  FUN_1003147e();
  FUN_1002ce78();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = (**(code **)(iVar1 + 0xb0))();
  if (iVar1 != 0) {
    (**(code **)(*extraout_ECX + 0xf0))();
  }
  SendMessageA((HWND)extraout_ECX[7],0x1f,0,0);
  FUN_1002ea54((HWND)extraout_ECX[7],0x1f,0,0,1,1);
  pvVar2 = FUN_1002e9b3((int)extraout_ECX);
  SendMessageA(*(HWND *)((int)pvVar2 + 0x1c),0x1f,0,0);
  FUN_1002ea54(*(HWND *)((int)pvVar2 + 0x1c),0x1f,0,0,1,1);
  hWnd = GetCapture();
  if (hWnd != (HWND)0x0) {
    SendMessageA(hWnd,0x1f,0,0);
  }
  BVar3 = WinHelpA(*(HWND *)((int)pvVar2 + 0x1c),*(LPCSTR *)(*(int *)(unaff_EBP + -0x10) + 0x8c),
                   *(UINT *)(unaff_EBP + 0xc),*(ULONG_PTR *)(unaff_EBP + 8));
  if (BVar3 == 0) {
    FUN_1003073b();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1003147e();
  FUN_1002ce8d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1002e245 */

/* Library Function - Single Match
    struct AFX_MSGMAP_ENTRY const * __stdcall AfxFindMessageEntry(struct AFX_MSGMAP_ENTRY const
   *,unsigned int,unsigned int,unsigned int)

   Library: Visual Studio */

AFX_MSGMAP_ENTRY *
AfxFindMessageEntry(AFX_MSGMAP_ENTRY *param_1,uint param_2,uint param_3,uint param_4)

{
  while( true ) {
    if (*(int *)(param_1 + 0x10) == 0) {
      return (AFX_MSGMAP_ENTRY *)0x0;
    }
    if ((((param_2 == *(uint *)param_1) && (param_3 == *(uint *)(param_1 + 4))) &&
        (*(uint *)(param_1 + 8) <= param_4)) && (param_4 <= *(uint *)(param_1 + 0xc))) break;
    param_1 = param_1 + 0x18;
  }
  return param_1;
}



/* VA 1002e285 */

undefined4 __thiscall
FUN_1002e285(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_8;

  local_8 = 0;
  iVar1 = (**(code **)(*(int *)this + 0x9c))(param_1,param_2,param_3,&local_8);
  if (iVar1 == 0) {
    local_8 = (**(code **)(*(int *)this + 0xa0))(param_1,param_2,param_3);
  }
  return local_8;
}



/* VA 1002e2c9 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_1002e2c9(void)

{
  short sVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  AFX_MSGMAP_ENTRY *pAVar6;
  DWORD DVar7;
  uint *puVar8;
  void *pvVar9;
  int *extraout_ECX;
  uint *puVar10;
  uint uVar11;
  code *pcVar12;
  int unaff_EBP;
  short sVar13;
  undefined4 uVar14;

  FUN_10020434();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar2 = *(int *)(unaff_EBP + 8);
  if (iVar2 == 0x111) {
    iVar2 = (**(code **)(*extraout_ECX + 0x78))
                      (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
    if (iVar2 != 0) {
LAB_1002e71f:
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      goto switchD_1002e49d_caseD_26;
    }
LAB_1002e452:
    uVar14 = 0;
    goto LAB_1002e454;
  }
  if (iVar2 == 0x4e) {
    if (**(int **)(unaff_EBP + 0x10) != 0) {
      iVar2 = (**(code **)(*extraout_ECX + 0x7c))
                        (*(undefined4 *)(unaff_EBP + 0xc),*(int **)(unaff_EBP + 0x10),
                         unaff_EBP + -0x10);
LAB_1002e322:
      if (iVar2 != 0) goto switchD_1002e49d_caseD_26;
    }
    goto LAB_1002e452;
  }
  puVar8 = *(uint **)(unaff_EBP + 0x10);
  if (iVar2 == 6) {
    pvVar3 = FUN_1002d53a();
    FUN_1002d2a2((int)extraout_ECX,*(WPARAM *)(unaff_EBP + 0xc),(int)pvVar3);
  }
  sVar13 = (short)puVar8;
  if ((iVar2 == 0x20) &&
     (iVar2 = FUN_1002d303((int)extraout_ECX,(int)sVar13,(uint)puVar8 >> 0x10), iVar2 != 0))
  goto LAB_1002e71f;
  uVar4 = (**(code **)(*extraout_ECX + 0x28))();
  *(uint *)(unaff_EBP + -0x14) = uVar4;
  uVar11 = uVar4 & 0x1ff ^ *(uint *)(unaff_EBP + 8) & 0x1ff;
  FUN_1003176c(7);
  uVar4 = *(uint *)(unaff_EBP + 8);
  iVar2 = uVar11 * 0xc;
  iVar5 = *(int *)(unaff_EBP + -0x14);
  if ((uVar4 != *(uint *)(&DAT_10041ca8 + uVar11 * 0xc)) ||
     (iVar5 != *(int *)(&DAT_10041cb0 + iVar2))) {
    *(uint *)(&DAT_10041ca8 + iVar2) = uVar4;
    *(int *)(&DAT_10041cb0 + iVar2) = iVar5;
    if (iVar5 != 0) {
      while( true ) {
        if (uVar4 < 0xc000) {
          pAVar6 = AfxFindMessageEntry(*(AFX_MSGMAP_ENTRY **)(iVar5 + 4),uVar4,0,0);
          *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar6;
          if (pAVar6 != (AFX_MSGMAP_ENTRY *)0x0) {
            *(AFX_MSGMAP_ENTRY **)(&DAT_10041cac + iVar2) = pAVar6;
            FUN_100317dc(7);
            iVar2 = *(int *)(unaff_EBP + 0x10);
            goto LAB_1002e472;
          }
        }
        else {
          pAVar6 = AfxFindMessageEntry(*(AFX_MSGMAP_ENTRY **)(iVar5 + 4),0xc000,0,0);
          *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar6;
          if (pAVar6 != (AFX_MSGMAP_ENTRY *)0x0) {
            while( true ) {
              if (**(int **)(pAVar6 + 0x10) == *(int *)(unaff_EBP + 8)) {
                *(AFX_MSGMAP_ENTRY **)(&DAT_10041cac + iVar2) = pAVar6;
                FUN_100317dc(7);
                iVar2 = *(int *)(unaff_EBP + 0x10);
                goto LAB_1002e755;
              }
              pAVar6 = AfxFindMessageEntry(pAVar6 + 0x18,0xc000,0,0);
              *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar6;
              if (pAVar6 == (AFX_MSGMAP_ENTRY *)0x0) break;
              pAVar6 = *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10);
            }
          }
        }
        iVar5 = **(int **)(unaff_EBP + -0x14);
        *(int *)(unaff_EBP + -0x14) = iVar5;
        if (iVar5 == 0) break;
        iVar5 = *(int *)(unaff_EBP + -0x14);
        uVar4 = *(uint *)(unaff_EBP + 8);
      }
    }
    *(undefined4 *)(&DAT_10041cac + iVar2) = 0;
    FUN_100317dc(7);
    goto LAB_1002e452;
  }
  iVar2 = *(int *)(&DAT_10041cac + iVar2);
  *(int *)(unaff_EBP + 0x10) = iVar2;
  FUN_100317dc(7);
  if (iVar2 == 0) goto LAB_1002e452;
  if (0xbfff < *(uint *)(unaff_EBP + 8)) {
LAB_1002e755:
    pcVar12 = *(code **)(iVar2 + 0x14);
switchD_1002e49d_caseD_a:
    pvVar3 = *(void **)(unaff_EBP + 0xc);
    goto LAB_1002e75c;
  }
LAB_1002e472:
  iVar5 = *(int *)(unaff_EBP + 0x10);
  pcVar12 = *(code **)(iVar2 + 0x14);
  iVar2 = *(int *)(iVar5 + 0x10);
  if (*(int *)(iVar5 + 8) == 0x1a) {
    DVar7 = GetVersion();
    iVar5 = *(int *)(unaff_EBP + 0x10);
    iVar2 = (-(uint)((byte)DVar7 < 4) & 0xfffffff0) + 0x2f;
  }
  sVar1 = (short)((uint)puVar8 >> 0x10);
  switch(iVar2) {
  case 1:
    puVar8 = (uint *)FUN_10030120();
    goto LAB_1002e5ad;
  case 2:
    puVar8 = *(uint **)(unaff_EBP + 0xc);
    goto LAB_1002e5ad;
  case 3:
  case 8:
    uVar4 = (uint)puVar8 >> 0x10;
    pvVar3 = (void *)(int)sVar13;
    pvVar9 = FUN_1002d53a();
    goto LAB_1002e5c8;
  case 4:
    FUN_1003007e((undefined4 *)(unaff_EBP + -0x24));
    uVar4 = puVar8[1];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(uint *)(unaff_EBP + -0x20) = uVar4;
    FUN_1002d19c((undefined4 *)(unaff_EBP + -0x60));
    uVar4 = *puVar8;
    uVar11 = puVar8[2];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(uint *)(unaff_EBP + -0x44) = uVar4;
    iVar2 = FUN_1002d561(uVar4);
    if (iVar2 == 0) {
      if ((extraout_ECX[0xd] != 0) &&
         (iVar2 = FUN_1002ada6((void *)(extraout_ECX[0xd] + 0x20),*(uint *)(unaff_EBP + -0x44)),
         iVar2 != 0)) {
        *(int *)(unaff_EBP + -0x28) = iVar2;
      }
      iVar2 = unaff_EBP + -0x60;
    }
    uVar14 = (*pcVar12)(unaff_EBP + -0x24,iVar2,uVar11);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar14;
    CWnd::~CWnd((CWnd *)(unaff_EBP + -0x60));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    goto LAB_1002e583;
  case 5:
    FUN_1003007e((undefined4 *)(unaff_EBP + -0x24));
    uVar4 = puVar8[2];
    *(uint *)(unaff_EBP + -0x20) = puVar8[1];
    *(undefined4 *)(unaff_EBP + -4) = 2;
    uVar14 = (*pcVar12)(unaff_EBP + -0x24,uVar4);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar14;
LAB_1002e583:
    FUN_10030166();
    break;
  case 6:
    uVar4 = *(uint *)(unaff_EBP + 0xc) >> 0x10;
    pvVar3 = FUN_1002d53a();
    goto LAB_1002e5c3;
  case 7:
    puVar8 = (uint *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    pvVar3 = (void *)(uint)*(ushort *)(unaff_EBP + 0xc);
    goto LAB_1002e75c;
  case 9:
  case 0x2a:
LAB_1002e5ad:
    uVar14 = (*pcVar12)(puVar8);
LAB_1002e760:
    *(undefined4 *)(unaff_EBP + -0x10) = uVar14;
    break;
  case 10:
  case 0x21:
    goto switchD_1002e49d_caseD_a;
  case 0xb:
    uVar4 = FUN_1002f8ab();
    pvVar3 = (void *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
LAB_1002e5c3:
    pvVar9 = (void *)(uint)*(ushort *)(unaff_EBP + 0xc);
LAB_1002e5c8:
    uVar14 = (*pcVar12)(pvVar9,pvVar3,uVar4);
    goto LAB_1002e760;
  case 0xc:
    (*pcVar12)();
    break;
  case 0xd:
    puVar8 = *(uint **)(unaff_EBP + 0xc);
    goto LAB_1002e6ec;
  case 0xe:
  case 0x12:
  case 0x25:
  case 0x2f:
    goto LAB_1002e6cc;
  case 0xf:
    puVar8 = (uint *)(int)sVar1;
    pvVar3 = (void *)(int)sVar13;
    goto LAB_1002e6cf;
  case 0x10:
  case 0x11:
    puVar10 = (uint *)((uint)puVar8 >> 0x10);
    pvVar3 = (void *)((uint)puVar8 & 0xffff);
    goto LAB_1002e70d;
  case 0x13:
    puVar10 = FUN_1002d53a();
    pvVar3 = FUN_1002d53a();
    pvVar9 = (void *)(uint)((uint *)extraout_ECX[7] == puVar8);
    goto LAB_1002e711;
  case 0x14:
    puVar8 = (uint *)FUN_10030120();
    goto LAB_1002e6ec;
  case 0x15:
    puVar8 = (uint *)FUN_1002f8ab();
    goto LAB_1002e6ec;
  case 0x16:
    puVar10 = (uint *)((uint)puVar8 >> 0x10);
    pvVar3 = (void *)((uint)puVar8 & 0xffff);
    pvVar9 = (void *)FUN_1002f8ab();
    goto LAB_1002e711;
  case 0x17:
    goto LAB_1002e653;
  case 0x18:
    puVar10 = (uint *)((uint)puVar8 >> 0x10);
    pvVar3 = (void *)((uint)puVar8 & 0xffff);
    goto LAB_1002e66f;
  case 0x19:
    pvVar3 = (void *)(int)sVar13;
    puVar10 = (uint *)(int)sVar1;
LAB_1002e66f:
    pvVar9 = FUN_1002d53a();
    goto LAB_1002e711;
  case 0x1a:
    pvVar3 = FUN_1002d53a();
    goto LAB_1002e6cf;
  case 0x1b:
    puVar8 = FUN_1002d53a();
LAB_1002e6cc:
    pvVar3 = *(void **)(unaff_EBP + 0xc);
    goto LAB_1002e6cf;
  case 0x1c:
    puVar10 = (uint *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    pvVar3 = FUN_1002d53a();
    goto LAB_1002e6f9;
  case 0x1d:
  case 0x1e:
    pvVar3 = (void *)(int)(short)*(undefined4 *)(unaff_EBP + 0xc);
    iVar2 = *(int *)(iVar5 + 0x10);
    *(void **)(unaff_EBP + 8) = pvVar3;
    puVar8 = (uint *)(int)(short)((uint)*(undefined4 *)(unaff_EBP + 0xc) >> 0x10);
    *(uint **)(unaff_EBP + 0xc) = puVar8;
    if (iVar2 == 0x1d) {
      puVar10 = FUN_1002d53a();
      pvVar3 = *(void **)(unaff_EBP + 0xc);
      pvVar9 = *(void **)(unaff_EBP + 8);
      goto LAB_1002e711;
    }
LAB_1002e6cf:
    (*pcVar12)(pvVar3,puVar8);
    break;
  case 0x1f:
  case 0x24:
    goto LAB_1002e6ec;
  case 0x20:
  case 0x2b:
    (*pcVar12)(*(undefined4 *)(unaff_EBP + 0xc),puVar8);
    goto LAB_1002e71f;
  case 0x22:
    pvVar3 = (void *)(int)sVar13;
    puVar8 = (uint *)(int)sVar1;
    goto LAB_1002e75c;
  case 0x23:
    uVar14 = (*pcVar12)();
    goto LAB_1002e760;
  case 0x2c:
LAB_1002e653:
    puVar8 = FUN_1002d53a();
LAB_1002e6ec:
    (*pcVar12)(puVar8);
    break;
  case 0x2d:
    pvVar3 = FUN_1002d53a();
LAB_1002e75c:
    uVar14 = (*pcVar12)(pvVar3,puVar8);
    goto LAB_1002e760;
  case 0x2e:
    iVar2 = (*pcVar12)(*(undefined2 *)(unaff_EBP + 0xc),*(uint *)(unaff_EBP + 0xc) >> 0x10,
                       (uint)puVar8 & 0xffff,(uint)puVar8 >> 0x10);
    *(int *)(unaff_EBP + -0x10) = iVar2;
    goto LAB_1002e322;
  case 0x30:
    pvVar3 = (void *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    puVar10 = puVar8;
LAB_1002e6f9:
    pvVar9 = (void *)(uint)*(ushort *)(unaff_EBP + 0xc);
    goto LAB_1002e711;
  case 0x31:
    pvVar3 = (void *)(int)sVar13;
    puVar10 = (uint *)(int)sVar1;
LAB_1002e70d:
    pvVar9 = *(void **)(unaff_EBP + 0xc);
LAB_1002e711:
    (*pcVar12)(pvVar9,pvVar3,puVar10);
  }
switchD_1002e49d_caseD_26:
  if (*(undefined4 **)(unaff_EBP + 0x14) != (undefined4 *)0x0) {
    **(undefined4 **)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -0x10);
  }
  uVar14 = 1;
LAB_1002e454:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar14;
}



/* VA 1002e83b */

CCmdUI * __fastcall FUN_1002e83b(CCmdUI *param_1)

{
  CCmdUI::CCmdUI(param_1);
  *(undefined ***)param_1 = &PTR_LAB_10034c70;
  *(undefined4 *)(param_1 + 0x28) = 1;
  return param_1;
}



/* VA 1002e868 */

undefined4 __thiscall FUN_1002e868(void *this,uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  CCmdUI local_30 [4];
  uint local_2c;
  int local_8;

  uVar3 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (param_2 == 0) {
    if (uVar3 == 0) {
      return 0;
    }
    FUN_1002e83b(local_30);
    local_2c = uVar3;
    (**(code **)(*(int *)this + 0xc))(uVar3,0xffffffff,local_30,0);
    if (local_8 != 0) {
      param_1 = 0;
LAB_1002e8ac:
      uVar1 = (**(code **)(*(int *)this + 0xc))(uVar3,param_1,0,0);
      return uVar1;
    }
  }
  else {
    iVar2 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
    if ((*(int *)(iVar2 + 0xb8) != *(int *)((int)this + 0x1c)) &&
       (iVar2 = FUN_1002eb29(), iVar2 == 0)) {
      if (uVar3 == 0) {
        return 0;
      }
      goto LAB_1002e8ac;
    }
  }
  return 1;
}



/* VA 1002e8f4 */

undefined4 __thiscall
FUN_1002e8f4(void *this,undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 *local_c;
  uint local_8;

  local_8 = GetDlgCtrlID((HWND)*param_2);
  local_8 = local_8 & 0xffff;
  uVar1 = param_2[2];
  iVar2 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  if ((*(int *)(iVar2 + 0xb8) != *(int *)((int)this + 0x1c)) && (iVar2 = FUN_1002eb29(), iVar2 == 0)
     ) {
    local_10 = param_3;
    local_c = param_2;
    uVar3 = (**(code **)(*(int *)this + 0xc))(local_8,uVar1 & 0xffff | 0x4e0000,&local_10,0);
    return uVar3;
  }
  return 1;
}



/* VA 1002e96e */

/* Library Function - Single Match
    struct HWND__ * __stdcall AfxGetParentOwner(struct HWND__ *)

   Library: Visual Studio 2003 Release */

HWND__ * AfxGetParentOwner(HWND__ *param_1)

{
  CWnd *pCVar1;
  uint uVar2;
  HWND__ *pHVar3;

  pCVar1 = (CWnd *)FUN_1002d561((uint)param_1);
  if (pCVar1 == (CWnd *)0x0) {
    uVar2 = GetWindowLongA(param_1,-0x10);
    if ((uVar2 & 0x40000000) == 0) {
      pHVar3 = GetWindow(param_1,4);
    }
    else {
      pHVar3 = GetParent(param_1);
    }
  }
  else {
    pCVar1 = CWnd::GetOwner(pCVar1);
    pHVar3 = (HWND__ *)0x0;
    if (pCVar1 != (CWnd *)0x0) {
      pHVar3 = *(HWND__ **)(pCVar1 + 0x1c);
    }
  }
  return pHVar3;
}



/* VA 1002e9b3 */

void * __fastcall FUN_1002e9b3(int param_1)

{
  HWND__ *pHVar1;
  void *pvVar2;

  if ((param_1 != 0) && (pHVar1 = *(HWND__ **)(param_1 + 0x1c), pHVar1 != (HWND__ *)0x0)) {
    do {
      pHVar1 = AfxGetParentOwner(pHVar1);
    } while (pHVar1 != (HWND__ *)0x0);
    pvVar2 = FUN_1002d53a();
    return pvVar2;
  }
  return (void *)0x0;
}



/* VA 1002e9db */

void * FUN_1002e9db(HWND param_1,int param_2,int param_3)

{
  HWND pHVar1;
  HWND pHVar2;
  void *pvVar3;

  pHVar1 = GetDlgItem(param_1,param_2);
  if (pHVar1 != (HWND)0x0) {
    pHVar2 = GetTopWindow(pHVar1);
    if ((pHVar2 != (HWND)0x0) &&
       (pvVar3 = FUN_1002e9db(pHVar1,param_2,param_3), pvVar3 != (void *)0x0)) {
      return pvVar3;
    }
    if (param_3 == 0) {
      pvVar3 = FUN_1002d53a();
      return pvVar3;
    }
    pvVar3 = (void *)FUN_1002d561((uint)pHVar1);
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
  }
  pHVar1 = GetTopWindow(param_1);
  while( true ) {
    if (pHVar1 == (HWND)0x0) {
      return (void *)0x0;
    }
    pvVar3 = FUN_1002e9db(pHVar1,param_2,param_3);
    if (pvVar3 != (void *)0x0) break;
    pHVar1 = GetWindow(pHVar1,2);
  }
  return pvVar3;
}



/* VA 1002ea54 */

void FUN_1002ea54(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4,int param_5,int param_6)

{
  HWND hWnd;
  int iVar1;
  HWND pHVar2;

  for (hWnd = GetTopWindow(param_1); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)) {
    if (param_6 == 0) {
      SendMessageA(hWnd,param_2,param_3,param_4);
    }
    else {
      iVar1 = FUN_1002d561((uint)hWnd);
      if (iVar1 != 0) {
        FUN_1002d379();
      }
    }
    if (param_5 != 0) {
      pHVar2 = GetTopWindow(hWnd);
      if (pHVar2 != (HWND)0x0) {
        FUN_1002ea54(hWnd,param_2,param_3,param_4,param_5,param_6);
      }
    }
  }
  return;
}



/* VA 1002ead1 */

void __thiscall FUN_1002ead1(void *this,LPRECT param_1,int param_2)

{
  uint dwExStyle;
  DWORD dwStyle;
  BOOL bMenu;

  dwExStyle = FUN_1002f5e7((int)this);
  if (param_2 == 0) {
    dwExStyle = dwExStyle & 0xfffffdff;
  }
  bMenu = 0;
  dwStyle = FUN_1002f5cd((int)this);
  AdjustWindowRectEx(param_1,dwStyle,bMenu,dwExStyle);
  return;
}



/* VA 1002eafc */

void __thiscall FUN_1002eafc(void *this,undefined4 param_1)

{
  int iVar1;

  iVar1 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  (**(code **)(*(int *)this + 0xa8))
            (*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
             *(undefined4 *)(iVar1 + 0x40),param_1);
  return;
}



/* VA 1002eb29 */

undefined4 FUN_1002eb29(void)

{
  HWND hWnd;
  int iVar1;
  void *this;
  HWND pHVar2;
  undefined4 uVar3;
  int unaff_EBP;

  FUN_10020434();
  iVar1 = FUN_1002d4c8();
  if (iVar1 != 0) {
    hWnd = *(HWND *)(unaff_EBP + 8);
    this = (void *)FUN_1002ada6((void *)(iVar1 + 4),(uint)hWnd);
    if (this != (void *)0x0) {
      uVar3 = FUN_1002eafc(this,*(undefined4 *)(unaff_EBP + 0xc));
      goto LAB_1002ebbd;
    }
    pHVar2 = GetParent(hWnd);
    iVar1 = FUN_1002ada6((void *)(iVar1 + 4),(uint)pHVar2);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x34) != 0)) {
      iVar1 = FUN_1002ada6((void *)(*(int *)(iVar1 + 0x34) + 0x20),(uint)hWnd);
      if (iVar1 != 0) {
        FUN_1002d1da((void *)(unaff_EBP + -0x48),hWnd);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(int *)(unaff_EBP + -0x10) = iVar1;
        uVar3 = FUN_1002eafc((void *)(unaff_EBP + -0x48),*(undefined4 *)(unaff_EBP + 0xc));
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        CWnd::~CWnd((CWnd *)(unaff_EBP + -0x48));
        goto LAB_1002ebbd;
      }
    }
  }
  uVar3 = 0;
LAB_1002ebbd:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 1002ebcd */

uint __thiscall FUN_1002ebcd(void *this,uint param_1,int *param_2,int param_3,int *param_4)

{
  LRESULT LVar1;
  uint uVar2;

  if (*(int *)((int)this + 0x38) == 0) {
    uVar2 = FUN_1002ec28(this,param_1,param_2,param_3,param_4);
  }
  else {
    LVar1 = SendMessageA(*(HWND *)((int)this + 0x1c),param_1 + 0x2000,(WPARAM)param_2,param_3);
    if (((param_1 < 0x132) || (0x138 < param_1)) || (uVar2 = 0, LVar1 != 0)) {
      if (param_4 != (int *)0x0) {
        *param_4 = LVar1;
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* VA 1002ec28 */

uint __thiscall FUN_1002ec28(void *this,uint param_1,int *param_2,int param_3,int *param_4)

{
  uint uVar1;
  int *local_c;
  int local_8;

  if (param_1 < 0x112) {
    if (param_1 == 0x111) {
      uVar1 = FUN_1002cd58(this,(undefined4 *)0x0,(uint)param_2 >> 0x10 | 0xbd110000,
                           (undefined4 *)0x0,(undefined4 *)0x0);
      if (uVar1 == 0) {
        return 0;
      }
      if (param_4 != (int *)0x0) {
        *param_4 = 1;
        return 1;
      }
      return 1;
    }
    if (0x2a < param_1) {
      if ((param_1 < 0x30) || (param_1 == 0x39)) goto LAB_1002ecbc;
      if (param_1 == 0x4e) {
        local_c = param_4;
        local_8 = param_3;
        uVar1 = FUN_1002cd58(this,(undefined4 *)0x0,*(uint *)(param_3 + 8) & 0xffff | 0xbc4e0000,
                             &local_c,(undefined4 *)0x0);
        return uVar1;
      }
    }
  }
  else if ((0x113 < param_1) && ((param_1 < 0x116 || (param_1 == 0x210)))) {
LAB_1002ecbc:
    uVar1 = FUN_1002e2c9();
    return uVar1;
  }
  if ((0x131 < param_1) && (param_1 < 0x139)) {
    local_8 = param_1 - 0x132;
    local_c = param_2;
    uVar1 = FUN_1002e2c9();
    if (*param_4 != 0) {
      return uVar1;
    }
  }
  return 0;
}



/* VA 1002ed5f */

void __fastcall FUN_1002ed5f(int *param_1)

{
  int iVar1;
  CWinThread *pCVar2;
  uint uVar3;

  iVar1 = FUN_1003147e();
  if ((*(int *)(iVar1 + 4) != 0) && (*(int **)(*(int *)(iVar1 + 4) + 0x1c) == param_1)) {
    FUN_1002f6f0(0x100435f8);
  }
  iVar1 = FUN_1003147e();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    pCVar2 = AfxGetThread();
    if (pCVar2 != (CWinThread *)0x0) {
      pCVar2 = AfxGetThread();
      if (*(int **)(pCVar2 + 0x1c) == param_1) {
        iVar1 = FUN_100310c7();
        if (*(code **)(iVar1 + 0x1c) != (code *)0x0) {
          (**(code **)(iVar1 + 0x1c))();
        }
      }
    }
  }
  uVar3 = FUN_1002f5cd((int)param_1);
  if ((uVar3 & 0x40000000) == 0) {
    FUN_1002ea54((HWND)param_1[7],0x15,0,0,1,1);
  }
  FUN_1002d4a1(param_1);
  return;
}



/* VA 1002eddc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_1002eddc(CWnd *param_1)

{
  int iVar1;
  CWinThread *pCVar2;

  iVar1 = FUN_1003147e();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    iVar1 = FUN_100310c7();
    pCVar2 = AfxGetThread();
    if (pCVar2 != (CWinThread *)0x0) {
      pCVar2 = AfxGetThread();
      if ((*(CWnd **)(pCVar2 + 0x1c) == param_1) && (*(code **)(iVar1 + 0x24) != (code *)0x0)) {
        (**(code **)(iVar1 + 0x24))();
      }
    }
  }
  _DAT_10041ca4 = 0;
  CWnd::OnDisplayChange(param_1,0,0);
  return;
}



/* VA 1002ee2f */

/* Library Function - Multiple Matches With Same Base Name
    protected: void __thiscall CWnd::OnDevModeChange(char *)
    protected: void __thiscall CWnd::OnDevModeChange(wchar_t *)

   Library: Visual Studio 2003 Release */

void __thiscall OnDevModeChange(void *this,LPSTR param_1)

{
  void *this_00;
  int iVar1;
  uint uVar2;

  iVar1 = FUN_1003147e();
  this_00 = *(void **)(iVar1 + 4);
  if ((this_00 != (void *)0x0) && (*(void **)((int)this_00 + 0x1c) == this)) {
    FUN_1002f78c(this_00,param_1);
  }
  uVar2 = FUN_1002f5cd((int)this);
  if ((uVar2 & 0x40000000) == 0) {
    iVar1 = FUN_1002d46c();
    FUN_1002ea54(*(HWND *)((int)this + 0x1c),*(UINT *)(iVar1 + 4),*(WPARAM *)(iVar1 + 8),
                 *(LPARAM *)(iVar1 + 0xc),1,1);
  }
  return;
}



/* VA 1002ee7a */

undefined4 __fastcall FUN_1002ee7a(int *param_1)

{
  SHORT SVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;

  uVar2 = FUN_1002f5cd((int)param_1);
  if (((((uVar2 & 0x40000000) == 0) && (iVar3 = FUN_1001e4a3(), iVar3 != 0)) &&
      (SVar1 = GetKeyState(0x10), -1 < SVar1)) &&
     ((SVar1 = GetKeyState(0x11), -1 < SVar1 && (SVar1 = GetKeyState(0x12), -1 < SVar1)))) {
    SendMessageA(*(HWND *)(iVar3 + 0x1c),0x111,0xe146,0);
    return 1;
  }
  uVar4 = FUN_1002d4a1(param_1);
  return uVar4;
}



/* VA 1002eede */

/* Library Function - Single Match
    protected: long __thiscall CWnd::OnDisplayChange(unsigned int,long)

   Library: Visual Studio 2003 Release */

long __thiscall CWnd::OnDisplayChange(CWnd *this,uint param_1,long param_2)

{
  CWnd *pCVar1;
  uint uVar2;
  int iVar3;
  long lVar4;

  pCVar1 = (CWnd *)FUN_1001e4a3();
  if (pCVar1 == this) {
    FUN_1002f734(0x100435f8);
  }
  uVar2 = FUN_1002f5cd((int)this);
  if ((uVar2 & 0x40000000) == 0) {
    iVar3 = FUN_1002d46c();
    FUN_1002ea54(*(HWND *)(this + 0x1c),*(UINT *)(iVar3 + 4),*(WPARAM *)(iVar3 + 8),
                 *(LPARAM *)(iVar3 + 0xc),1,1);
  }
  lVar4 = FUN_1002d4a1((int *)this);
  return lVar4;
}



/* VA 1002ef27 */

undefined4 __thiscall FUN_1002ef27(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;

  iVar1 = FUN_1002eb29();
  if (iVar1 == 0) {
    param_2 = FUN_1002d4a1(this);
  }
  return param_2;
}



/* VA 1002ef51 */

void __thiscall FUN_1002ef51(void *this,undefined4 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;

  if ((param_3 != (void *)0x0) && (iVar1 = FUN_1002eafc(param_3,0), iVar1 != 0)) {
    return;
  }
  FUN_1002d4a1(this);
  return;
}



/* VA 1002ef72 */

void __fastcall FUN_1002ef72(int *param_1)

{
  BOOL BVar1;
  tagMSG local_20;

  while( true ) {
    BVar1 = PeekMessageA(&local_20,(HWND)0x0,0x121,0x121,1);
    if (BVar1 == 0) break;
    DispatchMessageA(&local_20);
  }
  FUN_1002d4a1(param_1);
  return;
}



/* VA 1002efbc */

void * __thiscall FUN_1002efbc(void *this,undefined4 param_1,void *param_2)

{
  int iVar1;

  iVar1 = FUN_1002eafc(param_2,&param_2);
  if (iVar1 == 0) {
    param_2 = (void *)FUN_1002d4a1(this);
  }
  return param_2;
}



/* VA 1002efe3 */

undefined4 FUN_1002efe3(HDC param_1,HWND param_2,int param_3,HANDLE param_4,COLORREF param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined1 local_10 [4];
  COLORREF local_c;

  if ((((param_1 == (HDC)0x0) || (param_4 == (HANDLE)0x0)) || (param_3 == 1)) ||
     ((param_3 == 0 || (param_3 == 5)))) {
LAB_1002f052:
    uVar2 = 0;
  }
  else {
    if (param_3 == 2) {
      bVar1 = FUN_1002fdc1(param_2,2);
      if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_1002f052;
    }
    GetObjectA(param_4,0xc,local_10);
    SetBkColor(param_1,local_c);
    if (param_5 == 0xffffffff) {
      param_5 = GetSysColor(8);
    }
    SetTextColor(param_1,param_5);
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 1002f058 */

void __thiscall FUN_1002f058(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  HWND pHVar3;
  int iVar4;
  HWND pHVar5;
  uint *puVar6;
  uint local_64 [5];
  RECT local_50;
  tagRECT local_3c;
  tagRECT local_2c;
  tagRECT local_1c;
  void *local_c;
  uint local_8;

  local_c = this;
  local_8 = FUN_1002f5cd((int)this);
  if (param_1 == 0) {
    if ((local_8 & 0x40000000) == 0) {
      pHVar5 = GetWindow(*(HWND *)((int)this + 0x1c),4);
    }
    else {
      pHVar5 = GetParent(*(HWND *)((int)this + 0x1c));
    }
    if ((pHVar5 != (HWND)0x0) &&
       (pHVar3 = (HWND)SendMessageA(pHVar5,0x36b,0,0), pHVar3 != (HWND)0x0)) {
      pHVar5 = pHVar3;
    }
  }
  else {
    pHVar5 = *(HWND *)(param_1 + 0x1c);
  }
  GetWindowRect(*(HWND *)((int)this + 0x1c),&local_2c);
  if ((local_8 & 0x40000000) == 0) {
    if ((pHVar5 != (HWND)0x0) &&
       ((uVar1 = GetWindowLongA(pHVar5,-0x10), (uVar1 & 0x10000000) == 0 ||
        ((uVar1 & 0x20000000) != 0)))) {
      pHVar5 = (HWND)0x0;
    }
    local_64[0] = 0x28;
    if (pHVar5 == (HWND)0x0) {
      iVar2 = FUN_1001e4a3();
      pHVar5 = (HWND)0x0;
      if (iVar2 != 0) {
        pHVar5 = *(HWND *)(iVar2 + 0x1c);
      }
      puVar6 = local_64;
      iVar2 = xMonitorFromWindow(pHVar5,1);
      FUN_1001e981(iVar2,puVar6);
      CopyRect(&local_3c,&local_50);
      CopyRect(&local_1c,&local_50);
    }
    else {
      GetWindowRect(pHVar5,&local_3c);
      puVar6 = local_64;
      iVar2 = xMonitorFromWindow(pHVar5,2);
      FUN_1001e981(iVar2,puVar6);
      CopyRect(&local_1c,&local_50);
    }
  }
  else {
    pHVar3 = GetParent(*(HWND *)((int)this + 0x1c));
    GetClientRect(pHVar3,&local_1c);
    GetClientRect(pHVar5,&local_3c);
    MapWindowPoints(pHVar5,pHVar3,(LPPOINT)&local_3c,2);
  }
  iVar2 = (local_3c.left + local_3c.right) / 2 - (local_2c.right - local_2c.left) / 2;
  iVar4 = (local_3c.top + local_3c.bottom) / 2 - (local_2c.bottom - local_2c.top) / 2;
  if ((local_1c.left <= iVar2) &&
     (local_1c.left = iVar2, local_1c.right < (local_2c.right - local_2c.left) + iVar2)) {
    local_1c.left = (local_1c.right - local_2c.right) + local_2c.left;
  }
  if ((local_1c.top <= iVar4) &&
     (local_1c.top = iVar4, local_1c.bottom < (local_2c.bottom - local_2c.top) + iVar4)) {
    local_1c.top = (local_2c.top - local_2c.bottom) + local_1c.bottom;
  }
  FUN_1002f601(local_c,0,local_1c.left,local_1c.top,-1,-1,0x15);
  return;
}



/* VA 1002f238 */

/* Library Function - Multiple Matches With Same Base Name
    int __stdcall _AfxRegisterWithIcon(struct tagWNDCLASSA *,char const *,unsigned int)
    int __stdcall _AfxRegisterWithIcon(struct tagWNDCLASSW *,wchar_t const *,unsigned int)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void AfxRegisterWithIcon(int param_1,undefined4 param_2,ushort param_3)

{
  int iVar1;
  HICON pHVar2;

  *(undefined4 *)(param_1 + 0x24) = param_2;
  iVar1 = FUN_1003147e();
  pHVar2 = LoadIconA(*(HINSTANCE *)(iVar1 + 0xc),(LPCSTR)(uint)param_3);
  *(HICON *)(param_1 + 0x14) = pHVar2;
  if (pHVar2 == (HICON)0x0) {
    pHVar2 = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    *(HICON *)(param_1 + 0x14) = pHVar2;
  }
  FUN_1002e076();
  return;
}



/* VA 1002f279 */

uint FUN_1002f279(undefined4 param_1,uint param_2)

{
  HMODULE pHVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  int iVar3;
  uint uVar4;

  pHVar1 = GetModuleHandleA("COMCTL32.DLL");
  hModule = LoadLibraryA("COMCTL32.DLL");
  uVar4 = 0;
  if (hModule != (HMODULE)0x0) {
    pFVar2 = GetProcAddress(hModule,"InitCommonControlsEx");
    uVar4 = 0;
    if (pFVar2 == (FARPROC)0x0) {
      if ((param_2 & 0x3fc0) == param_2) {
        InitCommonControls();
        uVar4 = 0x3fc0;
      }
    }
    else {
      iVar3 = (*pFVar2)(param_1);
      if ((iVar3 != 0) && (uVar4 = param_2, pHVar1 == (HMODULE)0x0)) {
        InitCommonControls();
        uVar4 = param_2 | 0x3fc0;
      }
    }
    FreeLibrary(hModule);
  }
  return uVar4;
}



/* VA 1002f2f0 */

bool FUN_1002f2f0(uint param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_38;
  code *local_34;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  char *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_8 = FUN_1003147e();
  param_1 = param_1 & ~*(uint *)(local_8 + 0x18);
  if (param_1 == 0) {
    cVar1 = '\x01';
  }
  else {
    uVar4 = 0;
    _memset(&local_38,0,0x28);
    local_34 = DefWindowProcA_exref;
    iVar2 = FUN_1003147e();
    local_28 = *(undefined4 *)(iVar2 + 8);
    local_20 = DAT_10043638;
    local_10 = 8;
    if ((param_1 & 1) != 0) {
      local_38 = 0xb;
      local_14 = "AfxWnd42s";
      iVar2 = FUN_1002e076();
      if (iVar2 != 0) {
        uVar4 = 1;
      }
    }
    if ((param_1 & 0x20) != 0) {
      local_38 = local_38 | 0x8b;
      local_14 = "AfxOleControl42s";
      iVar2 = FUN_1002e076();
      if (iVar2 != 0) {
        uVar4 = uVar4 | 0x20;
      }
    }
    if ((param_1 & 2) != 0) {
      local_38 = 0;
      local_14 = "AfxControlBar42s";
      local_1c = 0x10;
      iVar2 = FUN_1002e076();
      if (iVar2 != 0) {
        uVar4 = uVar4 | 2;
      }
    }
    if ((param_1 & 4) != 0) {
      local_38 = 8;
      local_1c = 0;
      iVar2 = AfxRegisterWithIcon((int)&local_38,"AfxMDIFrame42s",0x7a01);
      if (iVar2 != 0) {
        uVar4 = uVar4 | 4;
      }
    }
    if ((param_1 & 8) != 0) {
      local_38 = 0xb;
      local_1c = 6;
      iVar2 = AfxRegisterWithIcon((int)&local_38,"AfxFrameOrView42s",0x7a02);
      if (iVar2 != 0) {
        uVar4 = uVar4 | 8;
      }
    }
    if ((param_1 & 0x10) != 0) {
      local_c = 0xff;
      uVar3 = FUN_1002f279(&local_10,0x3fc0);
      uVar4 = uVar4 | uVar3;
      param_1 = param_1 & 0xffffc03f;
    }
    if ((param_1 & 0x40) != 0) {
      local_c = 0x10;
      uVar3 = FUN_1002f279(&local_10,0x40);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x80) != 0) {
      local_c = 2;
      uVar3 = FUN_1002f279(&local_10,0x80);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x100) != 0) {
      local_c = 8;
      uVar3 = FUN_1002f279(&local_10,0x100);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x200) != 0) {
      local_c = 0x20;
      uVar3 = FUN_1002f279(&local_10,0x200);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x400) != 0) {
      local_c = 1;
      uVar3 = FUN_1002f279(&local_10,0x400);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x800) != 0) {
      local_c = 0x40;
      uVar3 = FUN_1002f279(&local_10,0x800);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x1000) != 0) {
      local_c = 4;
      uVar3 = FUN_1002f279(&local_10,0x1000);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x2000) != 0) {
      local_c = 0x80;
      uVar3 = FUN_1002f279(&local_10,0x2000);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x4000) != 0) {
      local_c = 0x800;
      uVar3 = FUN_1002f279(&local_10,0x4000);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x8000) != 0) {
      local_c = 0x400;
      uVar3 = FUN_1002f279(&local_10,0x8000);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x10000) != 0) {
      local_c = 0x200;
      uVar3 = FUN_1002f279(&local_10,0x10000);
      uVar4 = uVar4 | uVar3;
    }
    if ((param_1 & 0x20000) != 0) {
      local_c = 0x100;
      uVar3 = FUN_1002f279(&local_10,0x20000);
      uVar4 = uVar4 | uVar3;
    }
    *(uint *)(local_8 + 0x18) = *(uint *)(local_8 + 0x18) | uVar4;
    if ((*(uint *)(local_8 + 0x18) & 0x3fc0) == 0x3fc0) {
      uVar4 = uVar4 | 0x10;
      *(uint *)(local_8 + 0x18) = *(uint *)(local_8 + 0x18) | 0x10;
    }
    cVar1 = '\x01' - ((uVar4 & param_1) != param_1);
  }
  return (bool)cVar1;
}



/* VA 1002f5a7 */

void __cdecl FUN_1002f5a7(undefined4 *param_1)

{
  FUN_1001e6b8(&DAT_100434a8,param_1);
  return;
}



/* VA 1002f5cd */

void __fastcall FUN_1002f5cd(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    GetWindowLongA(*(HWND *)(param_1 + 0x1c),-0x10);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1002f5e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0x70))();
  return;
}



/* VA 1002f5e7 */

void __fastcall FUN_1002f5e7(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    GetWindowLongA(*(HWND *)(param_1 + 0x1c),-0x14);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1002f5fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0x74))();
  return;
}



/* VA 1002f601 */

void __thiscall
FUN_1002f601(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,UINT param_6)

{
  HWND hWndInsertAfter;

  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    hWndInsertAfter = (HWND)0x0;
    if (param_1 != 0) {
      hWndInsertAfter = *(HWND *)(param_1 + 0x1c);
    }
    SetWindowPos(*(HWND *)((int)this + 0x1c),hWndInsertAfter,param_2,param_3,param_4,param_5,param_6
                );
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x9c))
              (param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}



/* VA 1002f650 */

void __fastcall FUN_1002f650(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    IsWindowEnabled(*(HWND *)(param_1 + 0x1c));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1002f665. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0xa4))();
  return;
}



/* VA 1002f66b */

void __thiscall FUN_1002f66b(void *this,BOOL param_1)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    EnableWindow(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0xa8))(param_1);
  }
  return;
}



/* VA 1002f692 */

void __fastcall FUN_1002f692(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    SetFocus(*(HWND *)(param_1 + 0x1c));
    FUN_1002d53a();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x1002f6ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0xac))();
  return;
}



/* VA 1002f6b3 */

void __thiscall FUN_1002f6b3(void *this,int param_1)

{
  HWND pHVar1;
  int iVar2;

  if ((this != (void *)0x0) && (*(int *)((int)this + 0x38) == 0)) {
    pHVar1 = GetParent(*(HWND *)((int)this + 0x1c));
    iVar2 = FUN_1002ada6((void *)(param_1 + 4),(uint)pHVar1);
    if ((iVar2 != 0) && (*(int **)(iVar2 + 0x34) != (int *)0x0)) {
      (**(code **)(**(int **)(iVar2 + 0x34) + 0x8c))(this);
    }
  }
  return;
}



/* VA 1002f6f0 */

void __fastcall FUN_1002f6f0(int param_1)

{
  DWORD DVar1;
  HBRUSH pHVar2;

  DVar1 = GetSysColor(0xf);
  *(DWORD *)(param_1 + 0x28) = DVar1;
  DVar1 = GetSysColor(0x10);
  *(DWORD *)(param_1 + 0x2c) = DVar1;
  DVar1 = GetSysColor(0x14);
  *(DWORD *)(param_1 + 0x30) = DVar1;
  DVar1 = GetSysColor(0x12);
  *(DWORD *)(param_1 + 0x34) = DVar1;
  DVar1 = GetSysColor(6);
  *(DWORD *)(param_1 + 0x38) = DVar1;
  pHVar2 = GetSysColorBrush(0xf);
  *(HBRUSH *)(param_1 + 0x24) = pHVar2;
  pHVar2 = GetSysColorBrush(6);
  *(HBRUSH *)(param_1 + 0x20) = pHVar2;
  return;
}



/* VA 1002f734 */

void __fastcall FUN_1002f734(int param_1)

{
  int iVar1;
  HDC hdc;

  iVar1 = GetSystemMetrics(0xb);
  *(int *)(param_1 + 8) = iVar1;
  iVar1 = GetSystemMetrics(0xc);
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 0x68) == 0) {
    FUN_10031b0f();
  }
  else {
    FUN_10031adf();
  }
  hdc = GetDC((HWND)0x0);
  iVar1 = GetDeviceCaps(hdc,0x58);
  *(int *)(param_1 + 0x18) = iVar1;
  iVar1 = GetDeviceCaps(hdc,0x5a);
  *(int *)(param_1 + 0x1c) = iVar1;
  ReleaseDC((HWND)0x0,hdc);
  return;
}



/* VA 1002f78c */

void __thiscall FUN_1002f78c(void *this,LPSTR param_1)

{
  LPVOID pvVar1;
  int iVar2;
  BOOL BVar3;
  SIZE_T dwBytes;
  HGLOBAL hMem;
  PDEVMODEA pDevModeOutput;
  LONG LVar4;
  void *local_8;

  if (*(HGLOBAL *)((int)this + 0x98) != (HGLOBAL)0x0) {
    local_8 = this;
    pvVar1 = GlobalLock(*(HGLOBAL *)((int)this + 0x98));
    iVar2 = lstrcmpA((LPCSTR)((uint)*(ushort *)((int)pvVar1 + 2) + (int)pvVar1),param_1);
    if (iVar2 == 0) {
      BVar3 = OpenPrinterA(param_1,&local_8,(LPPRINTER_DEFAULTSA)0x0);
      if (BVar3 != 0) {
        if (*(HGLOBAL *)((int)this + 0x94) != (HGLOBAL)0x0) {
          FUN_1002fef1(*(HGLOBAL *)((int)this + 0x94));
        }
        dwBytes = DocumentPropertiesA((HWND)0x0,local_8,param_1,(PDEVMODEA)0x0,(PDEVMODEA)0x0,0);
        hMem = GlobalAlloc(0x42,dwBytes);
        *(HGLOBAL *)((int)this + 0x94) = hMem;
        pDevModeOutput = GlobalLock(hMem);
        LVar4 = DocumentPropertiesA((HWND)0x0,local_8,param_1,pDevModeOutput,(PDEVMODEA)0x0,2);
        if (LVar4 != 1) {
          FUN_1002fef1(*(HGLOBAL *)((int)this + 0x94));
          *(undefined4 *)((int)this + 0x94) = 0;
        }
        ClosePrinter(local_8);
      }
    }
  }
  return;
}



/* VA 1002f839 */

undefined4 FUN_1002f839(void)

{
  int iVar1;
  undefined *puVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int unaff_EBP;

  FUN_10020434();
  iVar1 = FUN_100314a4();
  if ((*(int *)(iVar1 + 0x18) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    puVar2 = FUN_1002be90(&LAB_1002ff27);
    pvVar3 = FUN_1002bea2(0x48);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_1002c135();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 **)(iVar1 + 0x18) = puVar4;
    FUN_1002be90(puVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(iVar1 + 0x18);
}



/* VA 1002f8ab */

void FUN_1002f8ab(void)

{
  FUN_1002f839();
  FUN_1002c19a();
  return;
}



/* VA 1002f8c0 */

undefined4 FUN_1002f8c0(uint param_1)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_1002f839();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_1002ada6((void *)(iVar1 + 4),param_1);
  }
  return uVar2;
}



/* VA 1002f8de */

/* Library Function - Multiple Matches With Same Base Name
    public: void * __thiscall CGdiObject::Detach(void)
    public: struct _IMAGELIST * __thiscall CImageList::Detach(void)
    public: struct HMENU__ * __thiscall CMenu::Detach(void)

   Library: Visual Studio */

int __fastcall Detach(int param_1)

{
  int iVar1;
  int iVar2;

  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = FUN_1002f839();
    if (iVar2 != 0) {
      FUN_1002ae29((void *)(iVar2 + 4),*(uint *)(param_1 + 4));
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return iVar1;
}



/* VA 1002f908 */

BOOL __fastcall FUN_1002f908(int param_1)

{
  HMENU hMenu;
  BOOL BVar1;

  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  hMenu = (HMENU)Detach(param_1);
  BVar1 = DestroyMenu(hMenu);
  return BVar1;
}



/* VA 1002f91e */

void * FUN_1002f91e(void *param_1,int *param_2)

{
  int iVar1;

  iVar1 = *(int *)(*param_2 + -8);
  if (iVar1 < 0xff) {
    FUN_1001e6e4(param_1,(char)iVar1);
  }
  else if (iVar1 < 0xfffe) {
    FUN_1001e6e4(param_1,0xff);
    FUN_1001e707(param_1,*(undefined2 *)(*param_2 + -8));
  }
  else {
    FUN_1001e6e4(param_1,0xff);
    FUN_1001e707(param_1,0xffff);
    FUN_1001e72e(param_1,*(undefined4 *)(*param_2 + -8));
  }
  FUN_1002fb95(param_1,(undefined4 *)*param_2,((undefined4 *)*param_2)[-2]);
  return param_1;
}



/* VA 1002f997 */

uint FUN_1002f997(void *param_1)

{
  uint local_c;
  undefined4 local_8;

  FUN_1001e754(param_1,(undefined1 *)((int)&local_8 + 3));
  if (local_8._3_1_ == 0xff) {
    FUN_1001e783(param_1,(undefined2 *)&local_8);
    if ((short)local_8 == -2) {
      local_c = 0xffffffff;
    }
    else if ((short)local_8 == -1) {
      FUN_1001e7b6(param_1,&local_c);
    }
    else {
      local_c = local_8 & 0xffff;
    }
  }
  else {
    local_c = (uint)local_8._3_1_;
  }
  return local_c;
}



/* VA 1002f9ee */

void * FUN_1002f9ee(void *param_1,undefined4 *param_2)

{
  LPCWSTR pWVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint local_8;

  local_8 = FUN_1002f997(param_1);
  bVar5 = local_8 == 0xffffffff;
  if (bVar5) {
    local_8 = FUN_1002f997(param_1);
  }
  uVar3 = (uint)bVar5;
  uVar4 = (uVar3 + 1) * local_8;
  if (local_8 == 0) {
    FUN_1002b5ae(param_2,0);
  }
  else {
    FUN_1002b5ae(param_2,uVar4 + uVar3);
    uVar2 = FUN_1002fa86(param_1,(undefined4 *)*param_2,uVar4);
    if (uVar2 != uVar4) {
      FUN_10030019();
    }
    if (uVar3 != 0) {
      pWVar1 = (LPCWSTR)*param_2;
      pWVar1[local_8] = L'\0';
      *param_2 = PTR_DAT_1003d148;
      FUN_1002b2cc(param_2,pWVar1);
      FUN_1002b057((undefined4 *)(pWVar1 + -6));
    }
  }
  return param_1;
}



/* VA 1002fa86 */

int __thiscall FUN_1002fa86(void *this,undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_c;
  undefined4 local_8;

  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    uVar4 = *(int *)((int)this + 0x28) - (int)*(undefined4 **)((int)this + 0x24);
    if (param_2 < uVar4) {
      uVar4 = param_2;
    }
    FUN_100200e0(param_1,*(undefined4 **)((int)this + 0x24),uVar4);
    *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + uVar4;
    param_1 = (undefined4 *)((int)param_1 + uVar4);
    uVar4 = param_2 - uVar4;
    if (uVar4 != 0) {
      iVar1 = uVar4 - uVar4 % *(uint *)((int)this + 0x1c);
      local_c = 0;
      local_8 = iVar1;
      do {
        iVar2 = (**(code **)(**(int **)((int)this + 0x20) + 0x34))(param_1,local_8);
        param_1 = (undefined4 *)((int)param_1 + iVar2);
        local_c = local_c + iVar2;
        local_8 = local_8 - iVar2;
        if (iVar2 == 0) break;
      } while (local_8 != 0);
      uVar4 = uVar4 - local_c;
      if (local_c == iVar1) {
        uVar5 = 0;
        if (*(int *)((int)this + 8) == 0) {
          local_8 = uVar4;
          if (uVar4 <= *(uint *)((int)this + 0x1c)) {
            local_8 = *(uint *)((int)this + 0x1c);
          }
          local_c = *(int *)((int)this + 0x2c);
          do {
            iVar1 = (**(code **)(**(int **)((int)this + 0x20) + 0x34))(local_c,local_8);
            local_c = local_c + iVar1;
            local_8 = local_8 - iVar1;
            uVar5 = uVar5 + iVar1;
            if ((iVar1 == 0) || (local_8 == 0)) break;
          } while (uVar5 < uVar4);
          puVar3 = *(undefined4 **)((int)this + 0x2c);
          *(undefined4 **)((int)this + 0x24) = puVar3;
          *(uint *)((int)this + 0x28) = (int)puVar3 + uVar5;
        }
        else {
          (**(code **)(**(int **)((int)this + 0x20) + 0x50))
                    (0,*(undefined4 *)((int)this + 0x1c),(undefined4 *)((int)this + 0x2c),
                     (int)this + 0x28);
          puVar3 = *(undefined4 **)((int)this + 0x2c);
          *(undefined4 **)((int)this + 0x24) = puVar3;
        }
        uVar5 = *(int *)((int)this + 0x28) - (int)puVar3;
        if (uVar4 < uVar5) {
          uVar5 = uVar4;
        }
        FUN_100200e0(param_1,puVar3,uVar5);
        *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + uVar5;
        uVar4 = uVar4 - uVar5;
      }
    }
    iVar1 = param_2 - uVar4;
  }
  return iVar1;
}



/* VA 1002fb95 */

void __thiscall FUN_1002fb95(void *this,undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;

  if (param_2 != 0) {
    uVar2 = *(int *)((int)this + 0x28) - (int)*(undefined4 **)((int)this + 0x24);
    if (param_2 < uVar2) {
      uVar2 = param_2;
    }
    FUN_100200e0(*(undefined4 **)((int)this + 0x24),param_1,uVar2);
    *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + uVar2;
    uVar1 = param_2 - uVar2;
    if (uVar1 != 0) {
      FUN_1002fc25((int)this);
      iVar3 = uVar1 - uVar1 % *(uint *)((int)this + 0x1c);
      (**(code **)(**(int **)((int)this + 0x20) + 0x38))((int)param_1 + uVar2,iVar3);
      if (*(int *)((int)this + 8) != 0) {
        (**(code **)(**(int **)((int)this + 0x20) + 0x50))
                  (1,*(undefined4 *)((int)this + 0x1c),(undefined4 *)((int)this + 0x2c),
                   (int)this + 0x28);
        *(undefined4 *)((int)this + 0x24) = *(undefined4 *)((int)this + 0x2c);
      }
      FUN_100200e0(*(undefined4 **)((int)this + 0x24),(undefined4 *)((int)param_1 + uVar2 + iVar3),
                   uVar1 - iVar3);
      *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + (uVar1 - iVar3);
    }
  }
  return;
}



/* VA 1002fc25 */

void __fastcall FUN_1002fc25(int param_1)

{
  int iVar1;
  int iVar2;

  if ((*(byte *)(param_1 + 0x14) & 1) == 0) {
    iVar1 = *(int *)(param_1 + 0x24);
    iVar2 = *(int *)(param_1 + 0x2c);
    if (*(int *)(param_1 + 8) == 0) {
      if (iVar1 != iVar2) {
        (**(code **)(**(int **)(param_1 + 0x20) + 0x38))(iVar2,iVar1 - iVar2);
      }
    }
    else {
      if (iVar1 != iVar2) {
        (**(code **)(**(int **)(param_1 + 0x20) + 0x50))(2,iVar1 - iVar2,0,0);
      }
      (**(code **)(**(int **)(param_1 + 0x20) + 0x50))
                (1,*(undefined4 *)(param_1 + 0x1c),(undefined4 *)(param_1 + 0x2c),param_1 + 0x28);
    }
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x2c);
  }
  else {
    if (*(int *)(param_1 + 0x28) != *(int *)(param_1 + 0x24)) {
      (**(code **)(**(int **)(param_1 + 0x20) + 0x28))
                (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x28),1);
    }
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x28);
  }
  return;
}



/* VA 1002fca1 */

void __thiscall FUN_1002fca1(void *this,uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_8;

  puVar1 = *(undefined4 **)((int)this + 0x24);
  local_8 = *(int *)((int)this + 0x28) - (int)puVar1;
  uVar2 = param_1 + local_8;
  if (*(int *)((int)this + 8) == 0) {
    puVar3 = *(undefined4 **)((int)this + 0x2c);
    if (puVar3 < puVar1) {
      if (0 < (int)local_8) {
        FUN_10020590(puVar3,puVar1,local_8);
        puVar3 = *(undefined4 **)((int)this + 0x2c);
        *(undefined4 **)((int)this + 0x24) = puVar3;
        *(int *)((int)this + 0x28) = (int)puVar3 + local_8;
      }
      iVar5 = *(int *)((int)this + 0x1c) - local_8;
      iVar6 = local_8 + (int)puVar3;
      do {
        iVar4 = (**(code **)(**(int **)((int)this + 0x20) + 0x34))(iVar6,iVar5);
        local_8 = local_8 + iVar4;
        iVar6 = iVar6 + iVar4;
        iVar5 = iVar5 - iVar4;
        if ((iVar4 == 0) || (iVar5 == 0)) break;
      } while (local_8 < param_1);
      *(int *)((int)this + 0x24) = *(int *)((int)this + 0x2c);
      *(uint *)((int)this + 0x28) = *(int *)((int)this + 0x2c) + local_8;
    }
  }
  else {
    if (local_8 != 0) {
      (**(code **)(**(int **)((int)this + 0x20) + 0x28))(-local_8,1);
    }
    (**(code **)(**(int **)((int)this + 0x20) + 0x50))
              (0,*(undefined4 *)((int)this + 0x1c),(undefined4 *)((int)this + 0x2c),
               (int *)((int)this + 0x28));
    *(undefined4 *)((int)this + 0x24) = *(undefined4 *)((int)this + 0x2c);
  }
  if ((uint)(*(int *)((int)this + 0x28) - *(int *)((int)this + 0x24)) < uVar2) {
    FUN_10030019();
  }
  return;
}



/* VA 1002fd63 */

void __thiscall FUN_1002fd63(void *this,uint param_1)

{
  if (param_1 < 0xffff) {
    FUN_1001e707(this,(short)param_1);
  }
  else {
    FUN_1001e707(this,0xffff);
    FUN_1001e72e(this,param_1);
  }
  return;
}



/* VA 1002fd91 */

void * __fastcall FUN_1002fd91(void *param_1)

{
  void *local_c;
  undefined4 uStack_8;

  local_c = param_1;
  uStack_8 = param_1;
  FUN_1001e783(param_1,(undefined2 *)((int)&uStack_8 + 2));
  if (uStack_8._2_2_ == 0xffff) {
    FUN_1001e7b6(param_1,&local_c);
  }
  else {
    local_c = (void *)(uint)uStack_8._2_2_;
  }
  return local_c;
}



/* VA 1002fdc1 */

bool FUN_1002fdc1(HWND param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  CHAR local_10 [12];

  if ((param_1 != (HWND)0x0) && (uVar1 = GetWindowLongA(param_1,-0x10), (uVar1 & 0xf) == param_2)) {
    GetClassNameA(param_1,local_10,10);
    iVar2 = lstrcmpiA(local_10,"combobox");
    return (bool)('\x01' - (iVar2 != 0));
  }
  return false;
}



/* VA 1002fe0b */

HWND FUN_1002fe0b(HWND param_1,LONG param_2,LONG param_3)

{
  POINT pt;
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  UINT uCmd;
  tagRECT local_14;

  ClientToScreen(param_1,(LPPOINT)&param_2);
  uCmd = 5;
  do {
    param_1 = GetWindow(param_1,uCmd);
    if (param_1 == (HWND)0x0) {
      return (HWND)0x0;
    }
    iVar1 = GetDlgCtrlID(param_1);
    if (((short)iVar1 != -1) && (uVar2 = GetWindowLongA(param_1,-0x10), (uVar2 & 0x10000000) != 0))
    {
      GetWindowRect(param_1,&local_14);
      pt.y = param_3;
      pt.x = param_2;
      BVar3 = PtInRect(&local_14,pt);
      if (BVar3 != 0) {
        return param_1;
      }
    }
    uCmd = 2;
  } while( true );
}



/* VA 1002fe80 */

void FUN_1002fe80(HWND param_1,LPCSTR param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  CHAR local_104 [256];

  uVar1 = lstrlenA(param_2);
  if (((uVar1 < 0x101) && (uVar2 = GetWindowTextA(param_1,local_104,0x100), uVar2 == uVar1)) &&
     (iVar3 = lstrcmpA(local_104,param_2), iVar3 == 0)) {
    return;
  }
  SetWindowTextA(param_1,param_2);
  return;
}



/* VA 1002fed8 */

void FUN_1002fed8(undefined4 *param_1)

{
  if ((HGDIOBJ)*param_1 != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)*param_1);
    *param_1 = 0;
  }
  return;
}



/* VA 1002fef1 */

void FUN_1002fef1(HGLOBAL param_1)

{
  UINT UVar1;
  uint uVar2;

  if (param_1 != (HGLOBAL)0x0) {
    UVar1 = GlobalFlags(param_1);
    for (uVar2 = UVar1 & 0xff; uVar2 != 0; uVar2 = uVar2 - 1) {
      GlobalUnlock(param_1);
    }
    GlobalFree(param_1);
  }
  return;
}



/* VA 10030019 */

void FUN_10030019(void)

{
  undefined4 uVar1;
  LPCSTR pCVar2;
  undefined4 *puVar3;
  int unaff_EBP;

  FUN_10020434();
  puVar3 = FUN_1002bea2(0x10);
  *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_1002ba61((int)puVar3);
    puVar3[3] = PTR_DAT_1003d148;
    uVar1 = *(undefined4 *)(unaff_EBP + 8);
    pCVar2 = *(LPCSTR *)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *puVar3 = &PTR_LAB_10034de0;
    puVar3[2] = uVar1;
    FUN_1002b2a5(puVar3 + 3,pCVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 **)(unaff_EBP + -0x10) = puVar3;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x10,&DAT_100377d0);
}



/* VA 1003007e */

void __fastcall FUN_1003007e(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_10034f60;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}



/* VA 10030092 */

undefined * __thiscall FUN_10030092(void *this,byte param_1)

{
  FUN_10030166();
  if ((param_1 & 1) != 0) {
    FUN_1002becb(this);
  }
  return this;
}



/* VA 100300ae */

undefined4 FUN_100300ae(void)

{
  int iVar1;
  undefined *puVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int unaff_EBP;

  FUN_10020434();
  iVar1 = FUN_100314a4();
  if ((*(int *)(iVar1 + 0x1c) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    puVar2 = FUN_1002be90(&LAB_1002ff27);
    pvVar3 = FUN_1002bea2(0x48);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_1002c135();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 **)(iVar1 + 0x1c) = puVar4;
    FUN_1002be90(puVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(iVar1 + 0x1c);
}



/* VA 10030120 */

void FUN_10030120(void)

{
  FUN_100300ae();
  FUN_1002c19a();
  return;
}



/* VA 10030135 */

/* Library Function - Single Match
    public: struct HDC__ * __thiscall CDC::Detach(void)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

HDC__ * __thiscall CDC::Detach(CDC *this)

{
  HDC__ *pHVar1;
  int iVar2;

  pHVar1 = *(HDC__ **)(this + 4);
  if (pHVar1 != (HDC__ *)0x0) {
    iVar2 = FUN_100300ae();
    if (iVar2 != 0) {
      FUN_1002ae29((void *)(iVar2 + 4),*(uint *)(this + 4));
    }
  }
  (**(code **)(*(int *)this + 0x14))();
  *(undefined4 *)(this + 4) = 0;
  return pHVar1;
}



/* VA 10030166 */

void FUN_10030166(void)

{
  HDC__ *hdc;
  CDC *this;
  int unaff_EBP;

  FUN_10020434();
  *(CDC **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_10034f60;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(this + 4) != 0) {
    hdc = CDC::Detach(this);
    DeleteDC(hdc);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 100301ba */

int __fastcall FUN_100301ba(int param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    iVar2 = SaveDC(*(HDC *)(param_1 + 8));
  }
  if (*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) {
    iVar1 = SaveDC(*(HDC *)(param_1 + 4));
    if (iVar1 != 0) {
      iVar2 = -1;
    }
  }
  return iVar2;
}



/* VA 100301eb */

int __thiscall FUN_100301eb(void *this,int param_1)

{
  int iVar1;
  BOOL BVar2;

  iVar1 = 1;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    iVar1 = RestoreDC(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if ((iVar1 != 0) && (BVar2 = RestoreDC(*(HDC *)((int)this + 8),param_1), BVar2 != 0)) {
      return 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* VA 10030229 */

void __thiscall FUN_10030229(void *this,int param_1)

{
  HGDIOBJ h;

  h = GetStockObject(param_1);
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SelectObject(*(HDC *)((int)this + 4),h);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SelectObject(*(HDC *)((int)this + 8),h);
  }
  FUN_10030599();
  return;
}



/* VA 10030265 */

void __thiscall FUN_10030265(void *this,int param_1)

{
  HGDIOBJ pvVar1;

  pvVar1 = (HGDIOBJ)0x0;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    if (param_1 != 0) {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    SelectObject(*(HDC *)((int)this + 4),pvVar1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if (param_1 == 0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    SelectObject(*(HDC *)((int)this + 8),pvVar1);
  }
  FUN_10030599();
  return;
}



/* VA 100302ab */

COLORREF __thiscall FUN_100302ab(void *this,COLORREF param_1)

{
  COLORREF CVar1;

  CVar1 = 0xffffffff;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    CVar1 = SetBkColor(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    CVar1 = SetBkColor(*(HDC *)((int)this + 8),param_1);
  }
  return CVar1;
}



/* VA 100302da */

COLORREF __thiscall FUN_100302da(void *this,COLORREF param_1)

{
  COLORREF CVar1;

  CVar1 = 0xffffffff;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    CVar1 = SetTextColor(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    CVar1 = SetTextColor(*(HDC *)((int)this + 8),param_1);
  }
  return CVar1;
}



/* VA 10030309 */

int __thiscall FUN_10030309(void *this,int param_1)

{
  int iVar1;

  iVar1 = 0;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    iVar1 = SetMapMode(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    iVar1 = SetMapMode(*(HDC *)((int)this + 8),param_1);
  }
  return iVar1;
}



/* VA 10030337 */

void __thiscall FUN_10030337(void *this,int *param_1,int param_2,int param_3)

{
  tagPOINT local_c;

  local_c.x = (LONG)this;
  local_c.y = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SetViewportOrgEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SetViewportOrgEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.x;
  param_1[1] = local_c.y;
  return;
}



/* VA 10030383 */

void __thiscall FUN_10030383(void *this,int *param_1,int param_2,int param_3)

{
  tagPOINT local_c;

  local_c.x = (LONG)this;
  local_c.y = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    OffsetViewportOrgEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    OffsetViewportOrgEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.x;
  param_1[1] = local_c.y;
  return;
}



/* VA 100303cf */

void __thiscall FUN_100303cf(void *this,int *param_1,int param_2,int param_3)

{
  tagSIZE local_c;

  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SetViewportExtEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SetViewportExtEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}



/* VA 1003041b */

void __thiscall
FUN_1003041b(void *this,int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  tagSIZE local_c;

  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    ScaleViewportExtEx(*(HDC *)((int)this + 4),param_2,param_3,param_4,param_5,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    ScaleViewportExtEx(*(HDC *)((int)this + 8),param_2,param_3,param_4,param_5,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}



/* VA 10030473 */

void __thiscall FUN_10030473(void *this,int *param_1,int param_2,int param_3)

{
  tagSIZE local_c;

  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SetWindowExtEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SetWindowExtEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}



/* VA 100304bf */

void __thiscall
FUN_100304bf(void *this,int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  tagSIZE local_c;

  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    ScaleWindowExtEx(*(HDC *)((int)this + 4),param_2,param_3,param_4,param_5,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    ScaleWindowExtEx(*(HDC *)((int)this + 8),param_2,param_3,param_4,param_5,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}



/* VA 10030527 */

undefined4 FUN_10030527(void)

{
  int iVar1;
  undefined *puVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int unaff_EBP;

  FUN_10020434();
  iVar1 = FUN_100314a4();
  if ((*(int *)(iVar1 + 0x20) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    puVar2 = FUN_1002be90(&LAB_1002ff27);
    pvVar3 = FUN_1002bea2(0x48);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_1002c135();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 **)(iVar1 + 0x20) = puVar4;
    FUN_1002be90(puVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(iVar1 + 0x20);
}



/* VA 10030599 */

void FUN_10030599(void)

{
  FUN_10030527();
  FUN_1002c19a();
  return;
}



/* VA 100305ae */

/* Library Function - Multiple Matches With Same Base Name
    public: void * __thiscall CGdiObject::Detach(void)
    public: struct _IMAGELIST * __thiscall CImageList::Detach(void)
    public: struct HMENU__ * __thiscall CMenu::Detach(void)

   Library: Visual Studio */

int __fastcall Detach(int param_1)

{
  int iVar1;
  int iVar2;

  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = FUN_10030527();
    if (iVar2 != 0) {
      FUN_1002ae29((void *)(iVar2 + 4),*(uint *)(param_1 + 4));
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return iVar1;
}



/* VA 100305d8 */

BOOL __fastcall FUN_100305d8(int param_1)

{
  HGDIOBJ ho;
  BOOL BVar1;

  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  ho = (HGDIOBJ)Detach(param_1);
  BVar1 = DeleteObject(ho);
  return BVar1;
}



/* VA 100305ee */

void FUN_100305ee(undefined4 param_1)

{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)FUN_1001e4a3();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xb0))();
    if ((iVar2 != 0) && ((int *)piVar1[0x1a] != (int *)0x0)) {
      (**(code **)(*(int *)piVar1[0x1a] + 100))(param_1);
    }
  }
  return;
}



/* VA 1003061c */

int __thiscall FUN_1003061c(void *this,LPCSTR param_1,UINT param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  CHAR *lpCaption;
  CHAR local_118 [260];
  void *local_14;
  HWND local_10;
  int local_c;
  HWND local_8;

  local_14 = this;
  FUN_100305ee(0);
  local_10 = FUN_10030794((HWND)0x0,&local_8);
  if (((local_10 == (HWND)0x0) ||
      (piVar1 = (int *)SendMessageA(local_8,0x376,0,0), piVar1 == (int *)0x0)) &&
     (piVar1 = (int *)0x0, this != (void *)0x0)) {
    piVar1 = (int *)((int)this + 0x9c);
  }
  local_c = 0;
  if ((piVar1 != (int *)0x0) && (local_c = *piVar1, param_3 != 0)) {
    *piVar1 = param_3 + 0x30000;
  }
  if (((param_2 & 0xf0) == 0) &&
     ((uVar2 = param_2 & 0xf, uVar2 < 2 || ((2 < uVar2 && (uVar2 < 5)))))) {
    param_2 = param_2 | 0x30;
  }
  if (this == (void *)0x0) {
    lpCaption = local_118;
    GetModuleFileNameA((HMODULE)0x0,local_118,0x104);
  }
  else {
    lpCaption = *(CHAR **)((int)this + 0x78);
  }
  iVar3 = MessageBoxA(local_10,param_1,lpCaption,param_2);
  if (piVar1 != (int *)0x0) {
    *piVar1 = local_c;
  }
  if (local_8 != (HWND)0x0) {
    EnableWindow(local_8,1);
  }
  FUN_100305ee(1);
  return iVar3;
}



/* VA 10030703 */

void FUN_10030703(LPCSTR param_1,UINT param_2,int param_3)

{
  int iVar1;

  iVar1 = FUN_1003147e();
  if (*(int **)(iVar1 + 4) == (int *)0x0) {
    FUN_1003061c((void *)0x0,param_1,param_2,param_3);
  }
  else {
    (**(code **)(**(int **)(iVar1 + 4) + 0x8c))(param_1,param_2,param_3);
  }
  return;
}



/* VA 1003073b */

undefined4 FUN_1003073b(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;

  FUN_10020434();
  *(undefined **)(unaff_EBP + -0x10) = PTR_DAT_1003d148;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002c2be(*(UINT *)(unaff_EBP + 8));
  iVar1 = *(int *)(unaff_EBP + 0x10);
  if (iVar1 == -1) {
    iVar1 = *(int *)(unaff_EBP + 8);
  }
  uVar2 = FUN_10030703(*(LPCSTR *)(unaff_EBP + -0x10),*(UINT *)(unaff_EBP + 0xc),iVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1002b168((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 10030794 */

HWND FUN_10030794(HWND param_1,undefined4 *param_2)

{
  HWND hWnd;
  int iVar1;
  HWND pHVar2;
  HWND hWnd_00;
  BOOL BVar3;
  uint uVar4;
  HWND hWnd_01;

  hWnd_01 = param_1;
  if (param_1 != (HWND)0x0) goto LAB_1003080d;
  iVar1 = FUN_10030830();
  if ((iVar1 == 0) && (iVar1 = FUN_1001e4a3(), iVar1 == 0)) {
    hWnd_01 = (HWND)0x0;
    pHVar2 = hWnd_01;
    hWnd_00 = hWnd_01;
  }
  else {
    for (hWnd_01 = *(HWND *)(iVar1 + 0x1c); pHVar2 = hWnd_01, hWnd_00 = hWnd_01,
        hWnd_01 != (HWND)0x0; hWnd_01 = GetParent(hWnd_01)) {
LAB_1003080d:
      uVar4 = GetWindowLongA(hWnd_01,-0x10);
      pHVar2 = hWnd_01;
      hWnd_00 = hWnd_01;
      if ((uVar4 & 0x40000000) == 0) break;
    }
  }
  while (hWnd = pHVar2, hWnd != (HWND)0x0) {
    pHVar2 = GetParent(hWnd);
    hWnd_01 = hWnd;
  }
  if ((param_1 == (HWND)0x0) && (hWnd_00 != (HWND)0x0)) {
    hWnd_00 = GetLastActivePopup(hWnd_00);
  }
  if (param_2 != (undefined4 *)0x0) {
    if (((hWnd_01 == (HWND)0x0) || (BVar3 = IsWindowEnabled(hWnd_01), BVar3 == 0)) ||
       (hWnd_01 == hWnd_00)) {
      *param_2 = 0;
    }
    else {
      *param_2 = hWnd_01;
      EnableWindow(hWnd_01,0);
    }
  }
  return hWnd_00;
}



/* VA 10030830 */

undefined4 FUN_10030830(void)

{
  int iVar1;

  iVar1 = FUN_1003124c();
  return *(undefined4 *)(iVar1 + 0xc4);
}



/* VA 1003083c */

void FUN_1003083c(int *param_1,UINT param_2,int param_3,int param_4)

{
  int iVar1;
  byte local_104 [256];

  iVar1 = FUN_1002c342(param_2,(LPSTR)local_104,0x100);
  if (iVar1 != 0) {
    FUN_10030876(param_1,local_104,param_3,param_4);
  }
  return;
}



/* VA 10030876 */

void FUN_10030876(int *param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  LPCSTR pCVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;

  iVar5 = 0;
  bVar1 = *param_2;
  pbVar6 = param_2;
  while (bVar1 != 0) {
    if (*pbVar6 == 0x25) {
      bVar1 = pbVar6[1];
      if (((char)bVar1 < '0') || ('9' < (char)bVar1)) {
        if (((char)bVar1 < 'A') || ('Z' < (char)bVar1)) goto LAB_100308cf;
        if ((char)bVar1 < ':') goto LAB_100308ad;
        iVar4 = (char)bVar1 + -0x38;
      }
      else {
LAB_100308ad:
        iVar4 = (char)bVar1 + -0x31;
      }
      pbVar6 = pbVar6 + 2;
      if (param_4 <= iVar4) goto LAB_100308de;
      pCVar3 = *(LPCSTR *)(param_3 + iVar4 * 4);
      if (pCVar3 != (LPCSTR)0x0) {
        iVar4 = lstrlenA(pCVar3);
        iVar5 = iVar5 + iVar4;
      }
    }
    else {
LAB_100308cf:
      if ((*(byte *)((int)&DAT_10044e80 + *pbVar6 + 1) & 4) != 0) {
        iVar5 = iVar5 + 1;
        pbVar6 = pbVar6 + 1;
      }
      pbVar6 = pbVar6 + 1;
LAB_100308de:
      iVar5 = iVar5 + 1;
    }
    bVar1 = *pbVar6;
  }
  pbVar6 = (byte *)FUN_1002b537(param_1,iVar5);
  do {
    while( true ) {
      if (*param_2 == 0) {
        FUN_1002b586(param_1,(int)pbVar6 - *param_1);
        return;
      }
      bVar1 = *param_2;
      if (bVar1 == 0x25) break;
LAB_1003094c:
      if ((*(byte *)((int)&DAT_10044e80 + bVar1 + 1) & 4) != 0) {
        *pbVar6 = bVar1;
        pbVar6 = pbVar6 + 1;
        param_2 = param_2 + 1;
      }
      *pbVar6 = *param_2;
      pbVar6 = pbVar6 + 1;
      param_2 = param_2 + 1;
    }
    bVar2 = param_2[1];
    if (((char)bVar2 < '0') || ('9' < (char)bVar2)) {
      if (((char)bVar2 < 'A') || ('Z' < (char)bVar2)) goto LAB_1003094c;
      if ((char)bVar2 < ':') goto LAB_1003091c;
      iVar5 = (char)bVar2 + -0x38;
    }
    else {
LAB_1003091c:
      iVar5 = (char)bVar2 + -0x31;
    }
    param_2 = param_2 + 2;
    if (iVar5 < param_4) {
      pCVar3 = *(LPCSTR *)(param_3 + iVar5 * 4);
      if (pCVar3 != (LPCSTR)0x0) {
        lstrcpyA((LPSTR)pbVar6,pCVar3);
        iVar5 = lstrlenA((LPCSTR)pbVar6);
        pbVar6 = pbVar6 + iVar5;
      }
    }
    else {
      *pbVar6 = 0x3f;
      pbVar6 = pbVar6 + 1;
    }
  } while( true );
}



/* VA 10030975 */

void FUN_10030975(int *param_1,UINT param_2)

{
  FUN_1003083c(param_1,param_2,(int)&stack0x0000000c,1);
  return;
}



/* VA 1003098c */

bool FUN_1003098c(void)

{
  int iVar1;

  iVar1 = FUN_1003147e();
  return *(int *)(iVar1 + 0x2c) == 0;
}



/* VA 100309e1 */

void FUN_100309e1(void)

{
  FUN_1001e4c6(&DAT_100419c0,0,0xf023);
  return;
}



/* VA 100309f3 */

void FUN_100309f3(void)

{
  FUN_1001f5cf(&LAB_100309ff);
  return;
}



/* VA 10030a19 */

void FUN_10030a19(void)

{
  FUN_1001e513(&DAT_10041928,0,0xf021);
  return;
}



/* VA 10030a2b */

void FUN_10030a2b(void)

{
  FUN_1001f5cf(&LAB_10030a37);
  return;
}



/* VA 10030b03 */

HLOCAL __thiscall FUN_10030b03(void *this,byte param_1)

{
  FUN_100319f7();
  if ((param_1 & 1) != 0) {
    FUN_10030bb0(this);
  }
  return this;
}



/* VA 10030b1e */

HLOCAL __thiscall FUN_10030b1e(void *this,byte param_1)

{
  FUN_10031a38();
  if ((param_1 & 1) != 0) {
    FUN_10030bb0(this);
  }
  return this;
}



/* VA 10030b39 */

void __thiscall FUN_10030b39(void *this,int param_1)

{
  *(undefined4 *)(*(int *)((int)this + 4) + param_1) = *(undefined4 *)this;
  *(int *)this = param_1;
  return;
}



/* VA 10030b4c */

undefined4 __thiscall FUN_10030b4c(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar3 = *(int *)this;
  if (iVar3 == 0) {
    return 0;
  }
  if (iVar3 == param_1) {
    *(undefined4 *)this = *(undefined4 *)(*(int *)((int)this + 4) + param_1);
  }
  else {
    if (iVar3 == 0) {
      return 0;
    }
    iVar1 = *(int *)((int)this + 4);
    do {
      iVar2 = *(int *)(iVar1 + iVar3);
      if (iVar2 == param_1) break;
      iVar3 = iVar2;
    } while (iVar2 != 0);
    if (iVar3 == 0) {
      return 0;
    }
    *(undefined4 *)(iVar1 + iVar3) = *(undefined4 *)(iVar1 + param_1);
  }
  return 1;
}



/* VA 10030b92 */

HLOCAL FUN_10030b92(SIZE_T param_1)

{
  HLOCAL pvVar1;

  pvVar1 = LocalAlloc(0x40,param_1);
  if (pvVar1 == (HLOCAL)0x0) {
    FUN_1002a594();
  }
  return pvVar1;
}



/* VA 10030bb0 */

void FUN_10030bb0(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    LocalFree(param_1);
  }
  return;
}



/* VA 10030bc4 */

DWORD * __fastcall FUN_10030bc4(DWORD *param_1)

{
  DWORD DVar1;

  param_1[5] = 0;
  param_1[6] = 0;
  param_1[6] = 4;
  param_1[1] = 0;
  param_1[2] = 1;
  param_1[3] = 0;
  param_1[4] = 0;
  DVar1 = TlsAlloc();
  *param_1 = DVar1;
  if (DVar1 == 0xffffffff) {
    FUN_1002a594();
  }
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  return param_1;
}



/* VA 10030c06 */

void __fastcall FUN_10030c06(DWORD *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  HGLOBAL hMem;

  if (*param_1 != 0xffffffff) {
    TlsFree(*param_1);
  }
  puVar2 = (undefined4 *)param_1[5];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    FUN_10030f13(param_1,puVar2,0);
    puVar2 = puVar1;
  }
  if ((LPCVOID)param_1[4] != (LPCVOID)0x0) {
    hMem = GlobalHandle((LPCVOID)param_1[4]);
    GlobalUnlock(hMem);
    GlobalFree(hMem);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  return;
}



/* VA 10030c5d */

int __fastcall FUN_10030c5d(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  byte *pbVar2;
  HGLOBAL pvVar3;
  HGLOBAL hMem;
  LPVOID pvVar4;
  int iVar5;
  int iVar6;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
  EnterCriticalSection(lpCriticalSection);
  iVar5 = *(int *)(param_1 + 4);
  iVar6 = *(int *)(param_1 + 8);
  if ((iVar5 <= iVar6) || ((*(byte *)(*(int *)(param_1 + 0x10) + iVar6 * 8) & 1) != 0)) {
    iVar6 = 1;
    if (1 < iVar5) {
      pbVar2 = *(byte **)(param_1 + 0x10);
      do {
        pbVar2 = pbVar2 + 8;
        if ((*pbVar2 & 1) == 0) break;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar5);
      if (iVar6 < iVar5) goto LAB_10030d42;
    }
    iVar5 = iVar5 + 0x20;
    if (*(LPCVOID *)(param_1 + 0x10) == (LPCVOID)0x0) {
      pvVar3 = GlobalAlloc(0x2002,iVar5 * 8);
    }
    else {
      pvVar3 = GlobalHandle(*(LPCVOID *)(param_1 + 0x10));
      GlobalUnlock(pvVar3);
      pvVar3 = GlobalReAlloc(pvVar3,iVar5 * 8,0x2002);
    }
    if (pvVar3 == (HGLOBAL)0x0) {
      hMem = GlobalHandle(*(LPCVOID *)(param_1 + 0x10));
      GlobalLock(hMem);
      LeaveCriticalSection(lpCriticalSection);
      FUN_1002a594();
    }
    pvVar4 = GlobalLock(pvVar3);
    _memset((void *)((int)pvVar4 + *(int *)(param_1 + 4) * 8),0,
            (*(int *)(param_1 + 4) * 0x1fffffff + iVar5) * 8);
    *(LPVOID *)(param_1 + 0x10) = pvVar4;
    *(int *)(param_1 + 4) = iVar5;
  }
LAB_10030d42:
  if (*(int *)(param_1 + 0xc) <= iVar6) {
    *(int *)(param_1 + 0xc) = iVar6 + 1;
  }
  puVar1 = (uint *)(*(int *)(param_1 + 0x10) + iVar6 * 8);
  *puVar1 = *puVar1 | 1;
  *(int *)(param_1 + 8) = iVar6 + 1;
  LeaveCriticalSection(lpCriticalSection);
  return iVar6;
}



/* VA 10030d6f */

void __thiscall FUN_10030d6f(void *this,int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;

  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  for (iVar2 = *(int *)((int)this + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    if (param_1 < *(int *)(iVar2 + 8)) {
      puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0xc) + param_1 * 4);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      *(undefined4 *)(*(int *)(iVar2 + 0xc) + param_1 * 4) = 0;
    }
  }
  puVar1 = (uint *)(*(int *)((int)this + 0x10) + param_1 * 8);
  *puVar1 = *puVar1 & 0xfffffffe;
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  return;
}



/* VA 10030dcc */

void __thiscall FUN_10030dcc(void *this,int param_1,int param_2)

{
  undefined4 *lpTlsValue;
  HLOCAL pvVar1;
  int *piVar2;

  lpTlsValue = TlsGetValue(*(DWORD *)this);
  if (lpTlsValue == (undefined4 *)0x0) {
    lpTlsValue = FUN_10030b92(0x10);
    if (lpTlsValue == (undefined4 *)0x0) {
      lpTlsValue = (undefined4 *)0x0;
    }
    else {
      *lpTlsValue = &PTR_FUN_100345dc;
    }
    lpTlsValue[2] = 0;
    lpTlsValue[3] = 0;
    piVar2 = lpTlsValue + 2;
    EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
    FUN_10030b39((void *)((int)this + 0x14),(int)lpTlsValue);
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  }
  else {
    piVar2 = lpTlsValue + 2;
    if ((param_1 < *piVar2) || (param_2 == 0)) goto LAB_10030ea3;
  }
  if ((HLOCAL)lpTlsValue[3] == (HLOCAL)0x0) {
    pvVar1 = LocalAlloc(0,*(int *)((int)this + 0xc) << 2);
  }
  else {
    pvVar1 = LocalReAlloc((HLOCAL)lpTlsValue[3],*(int *)((int)this + 0xc) << 2,2);
  }
  lpTlsValue[3] = pvVar1;
  if (pvVar1 == (HLOCAL)0x0) {
    FUN_1002a594();
  }
  _memset((void *)(lpTlsValue[3] + *piVar2 * 4),0,
          (*piVar2 * 0x3fffffff + *(int *)((int)this + 0xc)) * 4);
  *piVar2 = *(int *)((int)this + 0xc);
  TlsSetValue(*(DWORD *)this,lpTlsValue);
LAB_10030ea3:
  *(int *)(lpTlsValue[3] + param_1 * 4) = param_2;
  return;
}



/* VA 10030eb6 */

HLOCAL __thiscall FUN_10030eb6(void *this,byte param_1)

{
  FUN_10030ed1();
  if ((param_1 & 1) != 0) {
    FUN_10030bb0(this);
  }
  return this;
}



/* VA 10030ed1 */

void FUN_10030ed1(void)

{
  return;
}



/* VA 10030ed2 */

void __thiscall FUN_10030ed2(void *this,undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;

  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  iVar2 = 1;
  if (1 < *(int *)((int)this + 0xc)) {
    do {
      pbVar1 = (byte *)(*(int *)((int)this + 0x10) + iVar2 * 8);
      if ((*(int *)(*(int *)((int)this + 0x10) + 4 + iVar2 * 8) == 0) && ((*pbVar1 & 1) != 0)) {
        *(undefined4 *)(pbVar1 + 4) = param_1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 0xc));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  return;
}



/* VA 10030f13 */

void __thiscall FUN_10030f13(void *this,undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;

  iVar3 = 1;
  bVar2 = true;
  if (1 < (int)param_1[2]) {
    do {
      if ((param_2 == 0) || (*(int *)(*(int *)((int)this + 0x10) + 4 + iVar3 * 8) == param_2)) {
        puVar1 = *(undefined4 **)(param_1[3] + iVar3 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(param_1[3] + iVar3 * 4) = 0;
      }
      else if (*(int *)(param_1[3] + iVar3 * 4) != 0) {
        bVar2 = false;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[2]);
    if (!bVar2) {
      return;
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  FUN_10030b4c((void *)((int)this + 0x14),(int)param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  LocalFree((HLOCAL)param_1[3]);
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
  }
  TlsSetValue(*(DWORD *)this,(LPVOID)0x0);
  return;
}



/* VA 10030fac */

void __thiscall FUN_10030fac(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  if (param_2 == 0) {
    puVar2 = TlsGetValue(*(DWORD *)this);
    if (puVar2 != (undefined4 *)0x0) {
      FUN_10030f13(this,puVar2,param_1);
    }
  }
  else {
    puVar2 = *(undefined4 **)((int)this + 0x14);
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar2[1];
      FUN_10030f13(this,puVar2,param_1);
      puVar2 = puVar1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  return;
}



/* VA 10031005 */

/* WARNING: Removing unreachable block (ram,0x1003102c) */

int __thiscall FUN_10031005(void *this,undefined *param_1)

{
  int iVar1;
  LPVOID pvVar2;

  if (*(int *)this == 0) {
    if (DAT_10041a60 == (DWORD *)0x0) {
      DAT_10041a60 = FUN_10030bc4((DWORD *)&DAT_10041a64);
    }
    iVar1 = FUN_10030c5d((int)DAT_10041a60);
    *(int *)this = iVar1;
  }
  iVar1 = *(int *)this;
  pvVar2 = TlsGetValue(*DAT_10041a60);
  if ((pvVar2 == (LPVOID)0x0) || (*(int *)((int)pvVar2 + 8) <= iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)((int)pvVar2 + 0xc) + iVar1 * 4);
  }
  if (iVar1 == 0) {
    iVar1 = (*(code *)param_1)();
    FUN_10030dcc(DAT_10041a60,*(int *)this,iVar1);
  }
  return iVar1;
}



/* VA 1003107c */

undefined4 __fastcall FUN_1003107c(int *param_1)

{
  int iVar1;
  LPVOID pvVar2;

  iVar1 = *param_1;
  if ((iVar1 != 0) && (DAT_10041a60 != (DWORD *)0x0)) {
    pvVar2 = TlsGetValue(*DAT_10041a60);
    if ((pvVar2 != (LPVOID)0x0) && (iVar1 < *(int *)((int)pvVar2 + 8))) {
      return *(undefined4 *)(*(int *)((int)pvVar2 + 0xc) + iVar1 * 4);
    }
  }
  return 0;
}



/* VA 100310a9 */

void __fastcall FUN_100310a9(int *param_1)

{
  if ((*param_1 != 0) && (DAT_10041a60 != (void *)0x0)) {
    FUN_10030d6f(DAT_10041a60,*param_1);
  }
  *param_1 = 0;
  return;
}



/* VA 100310c7 */

int FUN_100310c7(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (*extraout_ECX == 0) {
    FUN_1003176c(0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*extraout_ECX == 0) {
      iVar1 = (**(code **)(unaff_EBP + 8))();
      *extraout_ECX = iVar1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_100317dc(0x10);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *extraout_ECX;
}



/* VA 10031112 */

void Catch_10031112(void)

{
  FUN_100317dc(0x10);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}



/* VA 10031147 */

void FUN_10031147(undefined4 param_1)

{
  if (DAT_10041a60 != (void *)0x0) {
    FUN_10030ed2(DAT_10041a60,param_1);
  }
  return;
}



/* VA 1003115d */

void FUN_1003115d(int param_1,int param_2)

{
  if (DAT_10041a60 != (void *)0x0) {
    FUN_10030fac(DAT_10041a60,param_1,param_2);
  }
  return;
}



/* VA 10031177 */

void FUN_10031177(void)

{
  DAT_10041a5c = DAT_10041a5c + 1;
  return;
}



/* VA 100311a6 */

void __fastcall FUN_100311a6(undefined4 *param_1)

{
  param_1[0x35] = 0xffffffff;
  param_1[0x41] = 0xffffffff;
  *param_1 = &PTR_FUN_100345ec;
  return;
}



/* VA 100311bd */

HLOCAL __thiscall FUN_100311bd(void *this,byte param_1)

{
  FUN_100311d8();
  if ((param_1 & 1) != 0) {
    FUN_10030bb0(this);
  }
  return this;
}



/* VA 100311d8 */

void FUN_100311d8(void)

{
  int *piVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_100345ec;
  piVar1 = (int *)extraout_ECX[0x33];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x58))();
    if ((int *)extraout_ECX[0x33] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x33] + 4))(1);
    }
  }
  if ((HHOOK)extraout_ECX[0xc] != (HHOOK)0x0) {
    UnhookWindowsHookEx((HHOOK)extraout_ECX[0xc]);
  }
  if ((HHOOK)extraout_ECX[0xb] != (HHOOK)0x0) {
    UnhookWindowsHookEx((HHOOK)extraout_ECX[0xb]);
  }
  if ((undefined *)extraout_ECX[3] != (undefined *)0x0) {
    FUN_1001fabf((undefined *)extraout_ECX[3]);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1003124c */

void FUN_1003124c(void)

{
  FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  return;
}



/* VA 10031266 */

void FUN_10031266(void)

{
  return;
}



/* VA 10031267 */

void FUN_10031267(void)

{
  FUN_1001f5cf(&LAB_10031273);
  return;
}



/* VA 1003127d */

void __thiscall FUN_1003127d(void *this,undefined1 param_1)

{
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x103c) = 0;
  *(undefined4 *)((int)this + 0x1040) = 0;
  *(undefined4 *)((int)this + 0x104c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1050) = 0;
  *(undefined4 *)((int)this + 0x1064) = 0;
  *(undefined4 *)((int)this + 0x1068) = 0;
  *(undefined ***)this = &PTR_FUN_100345f4;
  *(undefined4 *)((int)this + 0x28) = 0x1c;
  *(undefined4 *)((int)this + 0x20) = 0x14;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined1 *)((int)this + 0x14) = param_1;
  *(undefined4 *)((int)this + 0x30) = 1;
  *(undefined4 *)((int)this + 0x1040) = 0x18;
  return;
}



/* VA 100312e0 */

HLOCAL __thiscall FUN_100312e0(void *this,byte param_1)

{
  FUN_100312fb();
  if ((param_1 & 1) != 0) {
    FUN_10030bb0(this);
  }
  return this;
}



/* VA 100312fb */

void FUN_100312fb(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_100345f4;
  puVar1 = (undefined4 *)extraout_ECX[0x411];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  if ((int *)extraout_ECX[0x41b] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0x41b] + 0xc))(extraout_ECX + 0x412);
    if ((int *)extraout_ECX[0x41b] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x41b] + 4))(1);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_100310a9(extraout_ECX + 0x41c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031370 */

void __fastcall thunk_FUN_100310a9(int *param_1)

{
  if ((*param_1 != 0) && (DAT_10041a60 != (void *)0x0)) {
    FUN_10030d6f(DAT_10041a60,*param_1);
  }
  *param_1 = 0;
  return;
}



/* VA 10031375 */

void __fastcall FUN_10031375(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_100345fc;
  param_1[3] = 0x54;
  param_1[10] = FUN_1002be88;
  return;
}



/* VA 10031394 */

HLOCAL __thiscall FUN_10031394(void *this,byte param_1)

{
  FUN_100313af();
  if ((param_1 & 1) != 0) {
    FUN_10030bb0(this);
  }
  return this;
}



/* VA 100313af */

void FUN_100313af(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 *extraout_ECX;
  void *pvVar3;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_100345fc;
  puVar1 = (undefined4 *)extraout_ECX[5];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  if ((undefined4 *)extraout_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[6])(1);
  }
  if ((undefined4 *)extraout_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[7])(1);
  }
  if ((undefined4 *)extraout_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[8])(1);
  }
  if ((undefined4 *)extraout_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[9])(1);
  }
  pvVar3 = (void *)extraout_ECX[0xe];
  if (pvVar3 != (void *)0x0) {
    while (*(int *)((int)pvVar3 + 0xc) != 0) {
      puVar2 = (undefined *)FUN_1002ac0e(pvVar3);
      FUN_1002becb(puVar2);
      pvVar3 = (void *)extraout_ECX[0xe];
    }
  }
  if ((int *)extraout_ECX[0xc] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0xc] + 4))(1);
  }
  if ((int *)extraout_ECX[0xd] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0xd] + 4))(1);
  }
  if ((int *)extraout_ECX[0xe] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0xe] + 4))(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031467 */

void FUN_10031467(void)

{
  return;
}



/* VA 10031468 */

void FUN_10031468(void)

{
  FUN_1001f5cf(&LAB_10031474);
  return;
}



/* VA 1003147e */

void FUN_1003147e(void)

{
  int iVar1;

  iVar1 = FUN_10031005(&DAT_10041a9c,&LAB_10030a41);
  if (*(int *)(iVar1 + 4) == 0) {
    FUN_100310c7();
  }
  return;
}



/* VA 100314a4 */

void FUN_100314a4(void)

{
  int iVar1;

  iVar1 = FUN_1003147e();
  FUN_10031005((void *)(iVar1 + 0x1070),&LAB_10030aa8);
  return;
}



/* VA 100314e3 */

HLOCAL __thiscall FUN_100314e3(void *this,byte param_1)

{
  thunk_FUN_100312fb();
  if ((param_1 & 1) != 0) {
    FUN_10030bb0(this);
  }
  return this;
}



/* VA 100314fe */

void thunk_FUN_100312fb(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_100345f4;
  puVar1 = (undefined4 *)extraout_ECX[0x411];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  if ((int *)extraout_ECX[0x41b] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0x41b] + 0xc))(extraout_ECX + 0x412);
    if ((int *)extraout_ECX[0x41b] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x41b] + 4))(1);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_100310a9(extraout_ECX + 0x41c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031503 */

undefined4 FUN_10031503(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  UINT UVar1;
  int iVar2;

  UVar1 = SetErrorMode(0);
  SetErrorMode(UVar1 | 0x8001);
  iVar2 = FUN_1003147e();
  *(undefined4 *)(iVar2 + 8) = param_1;
  *(undefined4 *)(iVar2 + 0xc) = param_1;
  iVar2 = FUN_1003147e();
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x68) = param_1;
    *(undefined4 *)(iVar2 + 0x6c) = param_2;
    *(undefined4 *)(iVar2 + 0x70) = param_3;
    *(undefined4 *)(iVar2 + 0x74) = param_4;
    FUN_10031566(iVar2);
  }
  iVar2 = FUN_1003147e();
  if (*(char *)(iVar2 + 0x14) == '\0') {
    FUN_1002beeb();
  }
  return 1;
}



/* VA 10031566 */

void __fastcall FUN_10031566(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint local_310 [64];
  uint local_210 [65];
  uint local_10c [65];
  byte *local_8;

  iVar2 = FUN_1003147e();
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0x68);
  GetModuleFileNameA(*(HMODULE *)(param_1 + 0x68),(LPSTR)local_210,0x104);
  local_8 = FUN_1002093b((byte *)local_210,0x2e);
  *local_8 = 0;
  FUN_10031683((byte *)local_210,(LPSTR)local_10c,0x104);
  if (*(int *)(param_1 + 0x88) == 0) {
    puVar3 = FUN_1002177c(local_10c);
    *(uint **)(param_1 + 0x88) = puVar3;
  }
  if (*(int *)(param_1 + 0x78) == 0) {
    iVar4 = FUN_1002c342(0xe000,(LPSTR)local_310,0x100);
    if (iVar4 == 0) {
      puVar3 = *(uint **)(param_1 + 0x88);
    }
    else {
      puVar3 = local_310;
    }
    puVar3 = FUN_1002177c(puVar3);
    *(uint **)(param_1 + 0x78) = puVar3;
  }
  pbVar1 = local_8;
  *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x78);
  if (*(int *)(param_1 + 0x8c) == 0) {
    lstrcpyA((LPSTR)local_8,".HLP");
    puVar3 = FUN_1002177c(local_210);
    *(uint **)(param_1 + 0x8c) = puVar3;
    *pbVar1 = 0;
  }
  if (*(int *)(param_1 + 0x90) == 0) {
    lstrcatA((LPSTR)local_10c,".INI");
    puVar3 = FUN_1002177c(local_10c);
    *(uint **)(param_1 + 0x90) = puVar3;
  }
  return;
}



/* VA 10031683 */

int FUN_10031683(byte *param_1,LPSTR param_2,int param_3)

{
  byte bVar1;
  byte *lpString2;
  int iVar2;

  lpString2 = param_1;
  for (; *param_1 != 0; param_1 = FUN_10020574(param_1)) {
    bVar1 = *param_1;
    if (((bVar1 == 0x5c) || (bVar1 == 0x2f)) || (bVar1 == 0x3a)) {
      lpString2 = FUN_10020574(param_1);
    }
  }
  if (param_2 == (LPSTR)0x0) {
    iVar2 = lstrlenA((LPCSTR)lpString2);
    iVar2 = iVar2 + 1;
  }
  else {
    lstrcpynA(param_2,(LPCSTR)lpString2,param_3);
    iVar2 = 0;
  }
  return iVar2;
}



/* VA 100316d9 */

int FUN_100316d9(void)

{
  DWORD DVar1;

  if (DAT_10041c9c == 0) {
    DAT_10041c9c = 1;
    DVar1 = GetVersion();
    if (((byte)DVar1 < 4) && ((DVar1 & 0x80000000) != 0)) {
      DAT_10041c98 = 1;
    }
    else {
      DAT_10041c98 = 0;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_10041ae8);
    }
  }
  return DAT_10041c9c;
}



/* VA 1003171e */

void FUN_1003171e(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;

  if ((DAT_10041c9c != 0) && (DAT_10041c9c = DAT_10041c9c + -1, DAT_10041c98 == 0)) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_10041ae8);
    piVar1 = &DAT_10041aa0;
    lpCriticalSection = (LPCRITICAL_SECTION)&DAT_10041b00;
    do {
      if (*piVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        *piVar1 = *piVar1 + -1;
      }
      lpCriticalSection = lpCriticalSection + 1;
      piVar1 = piVar1 + 1;
    } while ((int)lpCriticalSection < 0x10041c98);
  }
  return;
}



/* VA 1003176c */

void FUN_1003176c(int param_1)

{
  int *piVar1;

  if (DAT_10041c9c == 0) {
    FUN_100316d9();
  }
  if (DAT_10041c98 == 0) {
    piVar1 = &DAT_10041aa0 + param_1;
    if ((&DAT_10041aa0)[param_1] == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10041ae8);
      if (*piVar1 == 0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)(&DAT_10041b00 + param_1 * 0x18));
        *piVar1 = *piVar1 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10041ae8);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_10041b00 + param_1 * 0x18));
  }
  return;
}



/* VA 100317dc */

void FUN_100317dc(int param_1)

{
  if (DAT_10041c98 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_10041b00 + param_1 * 0x18));
  }
  return;
}



/* VA 10031803 */

void FUN_10031803(void)

{
  byte bVar1;
  LONG LVar2;
  uint uVar3;
  undefined1 *puVar4;
  int nWidth;
  int iVar5;
  int iVar6;
  undefined1 local_94 [132];
  int local_10;
  int local_c;
  byte *local_8;

  LVar2 = GetMenuCheckMarkDimensions();
  nWidth = (int)(short)LVar2;
  local_10 = (int)(short)((uint)LVar2 >> 0x10);
  if (0x20 < nWidth) {
    nWidth = 0x20;
  }
  iVar5 = nWidth + 0xf >> 4;
  iVar6 = ((nWidth + -4) / 2 + iVar5 * 0x10) - nWidth;
  if (0xc < iVar6) {
    iVar6 = 0xc;
  }
  if (0x20 < local_10) {
    local_10 = 0x20;
  }
  _memset(local_94,0xff,0x80);
  local_8 = &DAT_100346d4;
  local_c = 5;
  puVar4 = local_94 + (local_10 + -6 >> 1) * iVar5 * 2;
  do {
    bVar1 = *local_8;
    uVar3 = (uint)local_8 >> 0x10;
    local_8 = local_8 + 1;
    uVar3 = ~(CONCAT22((short)uVar3,(ushort)bVar1) << ((byte)iVar6 & 0x1f));
    puVar4[1] = (char)uVar3;
    *puVar4 = (char)(uVar3 >> 8);
    puVar4 = puVar4 + iVar5 * 2;
    local_c = local_c + -1;
  } while (local_c != 0);
  DAT_10043648 = CreateBitmap(nWidth,local_10,1,1,local_94);
  if (DAT_10043648 == (HBITMAP)0x0) {
    DAT_10043648 = LoadBitmapA((HINSTANCE)0x0,(LPCSTR)0x7fe3);
  }
  return;
}



/* VA 100318e3 */

void FUN_100318e3(void)

{
  undefined4 *puVar1;
  int unaff_EBP;

  FUN_10020434();
  puVar1 = FUN_1002bea2(0x3c);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_1002d19c(puVar1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 1003195b */

CWnd * __thiscall FUN_1003195b(void *this,byte param_1)

{
  CWnd::~CWnd(this);
  if ((param_1 & 1) != 0) {
    FUN_1001e6b8(&DAT_100434a8,this);
  }
  return this;
}



/* VA 1003197b */

void __thiscall CWnd::~CWnd(CWnd *this)

{
  int iVar1;
  CWnd *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(CWnd **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined ***)extraout_ECX = &PTR_LAB_10034bb0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((((*(int *)(extraout_ECX + 0x1c) != 0) && (extraout_ECX != (CWnd *)&DAT_10043590)) &&
      (extraout_ECX != (CWnd *)&DAT_10043550)) &&
     ((extraout_ECX != (CWnd *)&DAT_10043510 && (extraout_ECX != (CWnd *)&DAT_100434d0)))) {
    FUN_1002dd6a(extraout_ECX);
  }
  if (*(int **)(extraout_ECX + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(extraout_ECX + 0x34) + 4))(1);
  }
  iVar1 = *(int *)(extraout_ECX + 0x38);
  if ((iVar1 != 0) && (*(CWnd **)(iVar1 + 0x24) == extraout_ECX)) {
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1002cc26();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031990 */

void FUN_10031990(void)

{
  FUN_1001e5c5(&DAT_100434a8,0x3c,0x40);
  return;
}



/* VA 1003199f */

void FUN_1003199f(void)

{
  FUN_1001f5cf(&LAB_100319ab);
  return;
}



/* VA 100319f7 */

void FUN_100319f7(void)

{
  code *pcVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_100345cc;
  pcVar1 = (code *)extraout_ECX[4];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(0);
  }
  if ((HMODULE)extraout_ECX[2] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)extraout_ECX[2]);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031a38 */

void FUN_10031a38(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_100345d4;
  iVar2 = DAT_100435f0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar2 != 0) && (pcVar1 = *(code **)(iVar2 + 0x18), pcVar1 != (code *)0x0)) {
    (*pcVar1)(extraout_ECX);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031a78 */

void FUN_10031a78(void)

{
  return;
}



/* VA 10031a79 */

void FUN_10031a79(void)

{
  FUN_1001f5cf(&LAB_10031a85);
  return;
}



/* VA 10031a99 */

void FUN_10031a99(void)

{
  return;
}



/* VA 10031a9a */

void FUN_10031a9a(void)

{
  FUN_1001f5cf(&LAB_10031aa6);
  return;
}



/* VA 10031abf */

void FUN_10031abf(void)

{
  FUN_10031b31(0x100435f8);
  return;
}



/* VA 10031ac9 */

void FUN_10031ac9(void)

{
  FUN_1001f5cf(&LAB_10031ad5);
  return;
}



/* VA 10031adf */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10031adf(void)

{
  if (DAT_10043654 != 0) {
    _DAT_100435f8 = GetSystemMetrics(2);
    _DAT_100435f8 = _DAT_100435f8 + 1;
    _DAT_100435fc = GetSystemMetrics(3);
    _DAT_100435fc = _DAT_100435fc + 1;
    _DAT_10043660 = 1;
  }
  return;
}



/* VA 10031b0f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10031b0f(void)

{
  _DAT_100435f8 = GetSystemMetrics(2);
  _DAT_100435fc = GetSystemMetrics(3);
  _DAT_10043660 = 0;
  return;
}



/* VA 10031b31 */

int __fastcall FUN_10031b31(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  HCURSOR pHVar3;
  int iVar4;

  DVar2 = GetVersion();
  *(DWORD *)(param_1 + 0x54) = (DVar2 >> 8 & 0xff) + (DVar2 & 0xff) * 0x100;
  *(DWORD *)(param_1 + 0x58) = DVar2 >> 0x1f;
  uVar1 = (uint)(3 < (byte)DVar2);
  *(uint *)(param_1 + 0x5c) = uVar1;
  *(uint *)(param_1 + 0x60) = 1 - uVar1;
  *(uint *)(param_1 + 100) = uVar1;
  *(undefined4 *)(param_1 + 0x68) = 0;
  if (uVar1 != 0) {
    DVar2 = GetProcessVersion(0);
    *(uint *)(param_1 + 0x68) = (uint)(0x3ffff < DVar2);
  }
  FUN_1002f734(param_1);
  *(undefined4 *)(param_1 + 0x24) = 0;
  FUN_1002f6f0(param_1);
  pHVar3 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  *(HCURSOR *)(param_1 + 0x3c) = pHVar3;
  pHVar3 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  *(HCURSOR *)(param_1 + 0x40) = pHVar3;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  iVar4 = (*(int *)(param_1 + 0x5c) != 0) + 1;
  *(int *)(param_1 + 0x10) = iVar4;
  *(int *)(param_1 + 0x14) = iVar4;
  return param_1;
}



/* VA 10031bd8 */

void __fastcall FUN_10031bd8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_10034df8;
  return;
}



/* VA 10031be1 */

HLOCAL __thiscall FUN_10031be1(void *this,byte param_1)

{
  FUN_10031fc3();
  if ((param_1 & 1) != 0) {
    FUN_10030bb0(this);
  }
  return this;
}



/* VA 10031c06 */

void FUN_10031c06(void)

{
  return;
}



/* VA 10031c07 */

void FUN_10031c07(void)

{
  FUN_1001f5cf(&LAB_10031c13);
  return;
}



/* VA 10031c1d */

bool FUN_10031c1d(void)

{
  UINT CodePage;
  _cpinfo *lpCPInfo;
  _cpinfo local_18;

  lpCPInfo = &local_18;
  CodePage = GetOEMCP();
  GetCPInfo(CodePage,lpCPInfo);
  return 1 < local_18.MaxCharSize;
}



/* VA 10031c8c */

undefined4 * __thiscall FUN_10031c8c(void *this,byte param_1)

{
  FUN_10031cac();
  if ((param_1 & 1) != 0) {
    FUN_1001e6b8(&DAT_10043680,this);
  }
  return this;
}



/* VA 10031cac */

void FUN_10031cac(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_10034e4c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002f908((int)extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031ce5 */

void FUN_10031ce5(void)

{
  FUN_1001e5c5(&DAT_10043680,8,0x40);
  return;
}



/* VA 10031cf4 */

void FUN_10031cf4(void)

{
  FUN_1001f5cf(&LAB_10031d00);
  return;
}



/* VA 10031d2b */

void FUN_10031d2b(void)

{
  FUN_1001eae0(&DAT_10043748,0,0xf022);
  return;
}



/* VA 10031d3d */

void FUN_10031d3d(void)

{
  FUN_1001f5cf(&LAB_10031d49);
  return;
}



/* VA 10031d63 */

void FUN_10031d63(void)

{
  FUN_1001eb2d(&DAT_100436b0,0,0xf024);
  return;
}



/* VA 10031d75 */

void FUN_10031d75(void)

{
  FUN_1001f5cf(&LAB_10031d81);
  return;
}



/* VA 10031dee */

undefined4 * __thiscall FUN_10031dee(void *this,byte param_1)

{
  thunk_FUN_10030166();
  if ((param_1 & 1) != 0) {
    FUN_1001e6b8(&DAT_10043808,this);
  }
  return this;
}



/* VA 10031e0e */

void thunk_FUN_10030166(void)

{
  HDC__ *hdc;
  CDC *this;
  int unaff_EBP;

  FUN_10020434();
  *(CDC **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_10034f60;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(this + 4) != 0) {
    hdc = CDC::Detach(this);
    DeleteDC(hdc);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031e35 */

undefined4 * __thiscall FUN_10031e35(void *this,byte param_1)

{
  FUN_10031e55();
  if ((param_1 & 1) != 0) {
    FUN_1001e6b8(&DAT_100437e0,this);
  }
  return this;
}



/* VA 10031e55 */

void FUN_10031e55(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_10034fd8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_100305d8((int)extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031e8e */

void FUN_10031e8e(void)

{
  FUN_1001e5c5(&DAT_10043808,0x10,0x40);
  return;
}



/* VA 10031e9d */

void FUN_10031e9d(void)

{
  FUN_1001f5cf(&LAB_10031ea9);
  return;
}



/* VA 10031ece */

void FUN_10031ece(void)

{
  FUN_1001e5c5(&DAT_100437e0,8,0x40);
  return;
}



/* VA 10031edd */

void FUN_10031edd(void)

{
  FUN_1001f5cf(&LAB_10031ee9);
  return;
}



/* VA 10031f04 */

void FUN_10031f04(void)

{
  code *pcVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *lpClassName;

  iVar2 = FUN_1003147e();
  FUN_1003176c(1);
  lpClassName = (byte *)(iVar2 + 0x34);
  while (*lpClassName != 0) {
    pbVar3 = FUN_10020453(lpClassName,10);
    *pbVar3 = 0;
    iVar4 = FUN_1003147e();
    UnregisterClassA((LPCSTR)lpClassName,*(HINSTANCE *)(iVar4 + 8));
    lpClassName = pbVar3 + 1;
  }
  *(byte *)(iVar2 + 0x34) = 0;
  FUN_100317dc(1);
  iVar2 = FUN_1003147e();
  if ((*(int *)(iVar2 + 4) != 0) &&
     (pcVar1 = *(code **)(*(int *)(iVar2 + 4) + 0x54), pcVar1 != (code *)0x0)) {
    (*pcVar1)(1,0);
  }
  iVar2 = FUN_1003124c();
  if (*(int **)(iVar2 + 0xcc) != (int *)0x0) {
    iVar4 = (**(code **)(**(int **)(iVar2 + 0xcc) + 0xb8))();
    if (iVar4 != 0) {
      *(undefined4 *)(iVar2 + 0xcc) = 0;
    }
  }
  iVar4 = FUN_1003147e();
  if (*(char *)(iVar4 + 0x14) == '\0') {
    if (*(HHOOK *)(iVar2 + 0x30) != (HHOOK)0x0) {
      UnhookWindowsHookEx(*(HHOOK *)(iVar2 + 0x30));
      *(undefined4 *)(iVar2 + 0x30) = 0;
    }
    if (*(HHOOK *)(iVar2 + 0x2c) != (HHOOK)0x0) {
      UnhookWindowsHookEx(*(HHOOK *)(iVar2 + 0x2c));
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
  }
  return;
}



/* VA 10031fc3 */

void FUN_10031fc3(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;

  FUN_10020434();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_10034df8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1002fed8(extraout_ECX + 1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



/* VA 10031ff0 */

/* Library Function - Single Match
    void __stdcall AfxPostQuitMessage(int)

   Library: Visual Studio 1998 Release */

void AfxPostQuitMessage(int param_1)

{
  CWinThread *pCVar1;

  pCVar1 = AfxGetThread();
  if ((pCVar1 != (CWinThread *)0x0) && (*(code **)(pCVar1 + 0x54) != (code *)0x0)) {
    (**(code **)(pCVar1 + 0x54))(1,1);
  }
  PostQuitMessage(param_1);
  return;
}



/* VA 10032020 */

void Unwind_10032020(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 10032040 */

void Unwind_10032040(void)

{
  int unaff_EBP;

  FUN_1001f610(*(undefined4 *)(unaff_EBP + -0x10),100,0x11,FUN_1001df40);
  return;
}



/* VA 10032053 */

void Unwind_10032053(void)

{
  int unaff_EBP;

  FUN_1001f610(*(int *)(unaff_EBP + -0x10) + 0x6a4,0x3c,0x22,FUN_1001dfc0);
  return;
}



/* VA 1003206b */

void Unwind_1003206b(void)

{
  FUN_1002a71e();
  return;
}



/* VA 1003207a */

void Unwind_1003207a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0xf1c));
  return;
}



/* VA 10032089 */

void Unwind_10032089(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0xf20));
  return;
}



/* VA 10032098 */

void Unwind_10032098(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x1024));
  return;
}



/* VA 100320a7 */

void Unwind_100320a7(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x1028));
  return;
}



/* VA 100320b6 */

void Unwind_100320b6(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x102c));
  return;
}



/* VA 100320c5 */

void Unwind_100320c5(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x1034));
  return;
}



/* VA 100320d4 */

void Unwind_100320d4(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x1038));
  return;
}



/* VA 100320f0 */

void Unwind_100320f0(void)

{
  int unaff_EBP;

  FUN_1001f610(*(undefined4 *)(unaff_EBP + -0x10),100,0x11,FUN_1001df40);
  return;
}



/* VA 10032103 */

void Unwind_10032103(void)

{
  int unaff_EBP;

  FUN_1001f610(*(int *)(unaff_EBP + -0x10) + 0x6a4,0x3c,0x22,FUN_1001dfc0);
  return;
}



/* VA 1003211b */

void Unwind_1003211b(void)

{
  FUN_1002a71e();
  return;
}



/* VA 1003212a */

void Unwind_1003212a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0xf1c));
  return;
}



/* VA 10032139 */

void Unwind_10032139(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0xf20));
  return;
}



/* VA 10032148 */

void Unwind_10032148(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x1024));
  return;
}



/* VA 10032157 */

void Unwind_10032157(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x1028));
  return;
}



/* VA 10032166 */

void Unwind_10032166(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x102c));
  return;
}



/* VA 10032175 */

void Unwind_10032175(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x1034));
  return;
}



/* VA 10032184 */

void Unwind_10032184(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x1038));
  return;
}



/* VA 100321a0 */

void Unwind_100321a0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



/* VA 100321ac */

void Unwind_100321ac(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



/* VA 100321b8 */

void Unwind_100321b8(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



/* VA 100321c4 */

void Unwind_100321c4(void)

{
  FUN_1002a71e();
  return;
}



/* VA 100321e0 */

void Unwind_100321e0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



/* VA 100321ec */

void Unwind_100321ec(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



/* VA 100321f8 */

void Unwind_100321f8(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



/* VA 10032204 */

void Unwind_10032204(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



/* VA 10032220 */

void Unwind_10032220(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



/* VA 1003222c */

void Unwind_1003222c(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



/* VA 10032238 */

void Unwind_10032238(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



/* VA 10032244 */

void Unwind_10032244(void)

{
  FUN_1002a71e();
  return;
}



/* VA 10032260 */

void Unwind_10032260(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



/* VA 1003226c */

void Unwind_1003226c(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



/* VA 10032278 */

void Unwind_10032278(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



/* VA 10032284 */

void Unwind_10032284(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



/* VA 100322a0 */

void Unwind_100322a0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x18));
  return;
}



/* VA 100322a9 */

void Unwind_100322a9(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 100322b2 */

void Unwind_100322b2(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x3c));
  return;
}



/* VA 100322bb */

void Unwind_100322bb(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x14));
  return;
}



/* VA 100322c4 */

void Unwind_100322c4(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x44));
  return;
}



/* VA 100322cd */

void Unwind_100322cd(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x28));
  return;
}



/* VA 100322e0 */

void Unwind_100322e0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x2c));
  return;
}



/* VA 100322e9 */

void Unwind_100322e9(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x15b0));
  return;
}



/* VA 100322f5 */

void Unwind_100322f5(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x15bc));
  return;
}



/* VA 10032301 */

void Unwind_10032301(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x15c0));
  return;
}



/* VA 10032317 */

void Unwind_10032317(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 10032320 */

void Unwind_10032320(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x54));
  return;
}



/* VA 10032329 */

void Unwind_10032329(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x2c));
  return;
}



/* VA 10032332 */

void Unwind_10032332(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 1003233b */

void Unwind_1003233b(void)

{
  int unaff_EBP;

  CStdioFile::~CStdioFile((CStdioFile *)(unaff_EBP + -0x4c));
  return;
}



/* VA 10032344 */

void Unwind_10032344(void)

{
  int unaff_EBP;

  FUN_1001e260((undefined4 *)(unaff_EBP + -0x28));
  return;
}



/* VA 1003234d */

void Unwind_1003234d(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x38));
  return;
}



/* VA 10032356 */

void Unwind_10032356(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x34));
  return;
}



/* VA 1003235f */

void Unwind_1003235f(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 10032368 */

void Unwind_10032368(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x14));
  return;
}



/* VA 10032371 */

void Unwind_10032371(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x5c));
  return;
}



/* VA 1003237a */

void Unwind_1003237a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x60));
  return;
}



/* VA 10032383 */

void Unwind_10032383(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -100));
  return;
}



/* VA 1003238c */

void Unwind_1003238c(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x68) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
  }
  return;
}



/* VA 100323ad */

void Unwind_100323ad(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 100323b6 */

void Unwind_100323b6(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 100323bf */

void Unwind_100323bf(void)

{
  FUN_1002a71e();
  return;
}



/* VA 100323d5 */

void Unwind_100323d5(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 100323de */

void Unwind_100323de(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x6c));
  return;
}



/* VA 100323e7 */

void Unwind_100323e7(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x48));
  return;
}



/* VA 100323f0 */

void Unwind_100323f0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x44));
  return;
}



/* VA 100323f9 */

void Unwind_100323f9(void)

{
  FUN_1002a961();
  return;
}



/* VA 10032402 */

void Unwind_10032402(void)

{
  int unaff_EBP;

  CStdioFile::~CStdioFile((CStdioFile *)(unaff_EBP + -100));
  return;
}



/* VA 1003240b */

void Unwind_1003240b(void)

{
  int unaff_EBP;

  FUN_1001e260((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



/* VA 10032414 */

void Unwind_10032414(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x50));
  return;
}



/* VA 1003241d */

void Unwind_1003241d(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x18));
  return;
}



/* VA 10032426 */

void Unwind_10032426(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x14));
  return;
}



/* VA 1003242f */

void Unwind_1003242f(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032438 */

void Unwind_10032438(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x70));
  return;
}



/* VA 10032441 */

void Unwind_10032441(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x78));
  return;
}



/* VA 1003244a */

void Unwind_1003244a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x7c));
  return;
}



/* VA 10032453 */

void Unwind_10032453(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x80));
  return;
}



/* VA 10032466 */

void Unwind_10032466(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 1003246f */

void Unwind_1003246f(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032478 */

void Unwind_10032478(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x1c));
  return;
}



/* VA 10032481 */

void Unwind_10032481(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x24));
  return;
}



/* VA 1003248a */

void Unwind_1003248a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x28));
  return;
}



/* VA 10032493 */

void Unwind_10032493(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x2c));
  return;
}



/* VA 1003249c */

void Unwind_1003249c(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 100324a5 */

void Unwind_100324a5(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x34));
  return;
}



/* VA 100324ae */

void Unwind_100324ae(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x38));
  return;
}



/* VA 100324c1 */

void Unwind_100324c1(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 100324ca */

void Unwind_100324ca(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 100324d3 */

void Unwind_100324d3(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x14e0));
  return;
}



/* VA 100324df */

void Unwind_100324df(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x14e8));
  return;
}



/* VA 100324eb */

void Unwind_100324eb(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x14ec));
  return;
}



/* VA 100324f7 */

void Unwind_100324f7(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x14f4));
  return;
}



/* VA 10032503 */

void Unwind_10032503(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x14fc));
  return;
}



/* VA 1003250f */

void Unwind_1003250f(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1500));
  return;
}



/* VA 1003251b */

void Unwind_1003251b(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1508));
  return;
}



/* VA 10032527 */

void Unwind_10032527(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1510));
  return;
}



/* VA 10032533 */

void Unwind_10032533(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1514));
  return;
}



/* VA 1003253f */

void Unwind_1003253f(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x151c));
  return;
}



/* VA 1003254b */

void Unwind_1003254b(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1524));
  return;
}



/* VA 10032557 */

void Unwind_10032557(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1528));
  return;
}



/* VA 10032563 */

void Unwind_10032563(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1530));
  return;
}



/* VA 1003256f */

void Unwind_1003256f(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1534));
  return;
}



/* VA 1003257b */

void Unwind_1003257b(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x153c));
  return;
}



/* VA 10032587 */

void Unwind_10032587(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1540));
  return;
}



/* VA 10032593 */

void Unwind_10032593(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1548));
  return;
}



/* VA 1003259f */

void Unwind_1003259f(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x154c));
  return;
}



/* VA 100325ab */

void Unwind_100325ab(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1554));
  return;
}



/* VA 100325b7 */

void Unwind_100325b7(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1558));
  return;
}



/* VA 100325c3 */

void Unwind_100325c3(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1560));
  return;
}



/* VA 100325cf */

void Unwind_100325cf(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1568));
  return;
}



/* VA 100325db */

void Unwind_100325db(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x156c));
  return;
}



/* VA 100325e7 */

void Unwind_100325e7(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1574));
  return;
}



/* VA 100325f3 */

void Unwind_100325f3(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x157c));
  return;
}



/* VA 100325ff */

void Unwind_100325ff(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x1580));
  return;
}



/* VA 10032615 */

void Unwind_10032615(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 1003261e */

void Unwind_1003261e(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 10032627 */

void Unwind_10032627(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x18));
  return;
}



/* VA 10032630 */

void Unwind_10032630(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x20));
  return;
}



/* VA 10032643 */

void Unwind_10032643(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0x14));
  return;
}



/* VA 1003264c */

void Unwind_1003264c(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 10032655 */

void Unwind_10032655(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 1003265e */

void Unwind_1003265e(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 10032667 */

void Unwind_10032667(void)

{
  FUN_1002a961();
  return;
}



/* VA 10032670 */

void Unwind_10032670(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x3c));
  return;
}



/* VA 10032679 */

void Unwind_10032679(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x44));
  return;
}



/* VA 1003268c */

void Unwind_1003268c(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0x14));
  return;
}



/* VA 10032695 */

void Unwind_10032695(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 1003269e */

void Unwind_1003269e(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 100326a7 */

void Unwind_100326a7(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x1c));
  return;
}



/* VA 100326b0 */

void Unwind_100326b0(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0x28));
  return;
}



/* VA 100326c3 */

void Unwind_100326c3(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0x10));
  return;
}



/* VA 100326cc */

void Unwind_100326cc(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 100326d5 */

void Unwind_100326d5(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xac));
  return;
}



/* VA 100326e1 */

void Unwind_100326e1(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x1c));
  return;
}



/* VA 100326ea */

void Unwind_100326ea(void)

{
  int unaff_EBP;

  CStdioFile::~CStdioFile((CStdioFile *)(unaff_EBP + -0xa8));
  return;
}



/* VA 100326f6 */

void Unwind_100326f6(void)

{
  int unaff_EBP;

  FUN_1001e260((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



/* VA 100326ff */

void Unwind_100326ff(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x38));
  return;
}



/* VA 10032708 */

void Unwind_10032708(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x94));
  return;
}



/* VA 10032714 */

void Unwind_10032714(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x90));
  return;
}



/* VA 10032720 */

void Unwind_10032720(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x54));
  return;
}



/* VA 10032729 */

void Unwind_10032729(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -100));
  return;
}



/* VA 10032732 */

void Unwind_10032732(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x18));
  return;
}



/* VA 1003273b */

void Unwind_1003273b(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x60));
  return;
}



/* VA 10032744 */

void Unwind_10032744(void)

{
  FUN_1002a71e();
  return;
}



/* VA 10032750 */

void Unwind_10032750(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x2c));
  return;
}



/* VA 10032759 */

void Unwind_10032759(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x28));
  return;
}



/* VA 10032762 */

void Unwind_10032762(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 1003276b */

void Unwind_1003276b(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x24));
  return;
}



/* VA 10032774 */

void Unwind_10032774(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 1003277d */

void Unwind_1003277d(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x20));
  return;
}



/* VA 10032786 */

void Unwind_10032786(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xb4));
  return;
}



/* VA 10032792 */

void Unwind_10032792(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xb8));
  return;
}



/* VA 1003279e */

void Unwind_1003279e(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xc0));
  return;
}



/* VA 100327aa */

void Unwind_100327aa(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xc4));
  return;
}



/* VA 100327b6 */

void Unwind_100327b6(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -200));
  return;
}



/* VA 100327c2 */

void Unwind_100327c2(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xcc));
  return;
}



/* VA 100327ce */

void Unwind_100327ce(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xd0));
  return;
}



/* VA 100327da */

void Unwind_100327da(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xd4));
  return;
}



/* VA 100327e6 */

void Unwind_100327e6(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xd8));
  return;
}



/* VA 100327f2 */

void Unwind_100327f2(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xdc));
  return;
}



/* VA 100327fe */

void Unwind_100327fe(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xe0));
  return;
}



/* VA 1003280a */

void Unwind_1003280a(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0xe4));
  return;
}



/* VA 10032816 */

void Unwind_10032816(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xec));
  return;
}



/* VA 10032822 */

void Unwind_10032822(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0xf0));
  return;
}



/* VA 1003282e */

void Unwind_1003282e(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0xf8));
  return;
}



/* VA 1003283a */

void Unwind_1003283a(void)

{
  int unaff_EBP;

  FUN_1002b168(*(int **)(unaff_EBP + -0xfc));
  return;
}



/* VA 10032846 */

void Unwind_10032846(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x104));
  return;
}



/* VA 1003285c */

void Unwind_1003285c(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x128));
  return;
}



/* VA 10032868 */

void Unwind_10032868(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x24));
  return;
}



/* VA 10032871 */

void Unwind_10032871(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x230));
  return;
}



/* VA 1003287d */

void Unwind_1003287d(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x234) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
  }
  return;
}



/* VA 100328a1 */

void Unwind_100328a1(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x128));
  return;
}



/* VA 100328ad */

void Unwind_100328ad(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x14));
  return;
}



/* VA 100328b6 */

void Unwind_100328b6(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x230));
  return;
}



/* VA 100328c2 */

void Unwind_100328c2(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x234));
  return;
}



/* VA 100328ce */

void Unwind_100328ce(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x238) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
  }
  return;
}



/* VA 100328f2 */

void Unwind_100328f2(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 100328fb */

void Unwind_100328fb(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x34));
  return;
}



/* VA 1003290e */

void Unwind_1003290e(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0x10));
  return;
}



/* VA 10032917 */

void Unwind_10032917(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 10032920 */

void Unwind_10032920(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x2c));
  return;
}



/* VA 10032929 */

void Unwind_10032929(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x20));
  return;
}



/* VA 10032932 */

void Unwind_10032932(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x13c));
  return;
}



/* VA 10032948 */

void Unwind_10032948(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 10032951 */

void Unwind_10032951(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x20));
  return;
}



/* VA 1003295a */

void Unwind_1003295a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x1c));
  return;
}



/* VA 10032963 */

void Unwind_10032963(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x14));
  return;
}



/* VA 1003296c */

void Unwind_1003296c(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x24));
  return;
}



/* VA 10032975 */

void Unwind_10032975(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x2c));
  return;
}



/* VA 10032988 */

void Unwind_10032988(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0x10));
  return;
}



/* VA 10032991 */

void Unwind_10032991(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 1003299a */

void Unwind_1003299a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 100329a3 */

void Unwind_100329a3(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x20));
  return;
}



/* VA 100329ac */

void Unwind_100329ac(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x24));
  return;
}



/* VA 100329b5 */

void Unwind_100329b5(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x28));
  return;
}



/* VA 100329be */

void Unwind_100329be(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x2c));
  return;
}



/* VA 100329c7 */

void Unwind_100329c7(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
  }
  return;
}



/* VA 100329e8 */

void Unwind_100329e8(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 100329f1 */

void Unwind_100329f1(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 100329fa */

void Unwind_100329fa(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x24));
  return;
}



/* VA 10032a03 */

void Unwind_10032a03(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x2c));
  return;
}



/* VA 10032a0c */

void Unwind_10032a0c(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x34));
  return;
}



/* VA 10032a15 */

void Unwind_10032a15(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x38));
  return;
}



/* VA 10032a1e */

void Unwind_10032a1e(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x3c));
  return;
}



/* VA 10032a27 */

void Unwind_10032a27(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x40));
  return;
}



/* VA 10032a30 */

void Unwind_10032a30(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x44));
  return;
}



/* VA 10032a39 */

void Unwind_10032a39(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x48));
  return;
}



/* VA 10032a42 */

void Unwind_10032a42(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x4c));
  return;
}



/* VA 10032a4b */

void Unwind_10032a4b(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x50));
  return;
}



/* VA 10032a5e */

void Unwind_10032a5e(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x1c));
  return;
}



/* VA 10032a67 */

void Unwind_10032a67(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x244));
  return;
}



/* VA 10032a73 */

void Unwind_10032a73(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x248));
  return;
}



/* VA 10032a7f */

void Unwind_10032a7f(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x24c));
  return;
}



/* VA 10032a8b */

void Unwind_10032a8b(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -600));
  return;
}



/* VA 10032a97 */

void Unwind_10032a97(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x234));
  return;
}



/* VA 10032aa3 */

void Unwind_10032aa3(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -300));
  return;
}



/* VA 10032aaf */

void Unwind_10032aaf(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x25c));
  return;
}



/* VA 10032ac5 */

void Unwind_10032ac5(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 10032ace */

void Unwind_10032ace(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x5c));
  return;
}



/* VA 10032ad7 */

void Unwind_10032ad7(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x30));
  return;
}



/* VA 10032ae0 */

void Unwind_10032ae0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032ae9 */

void Unwind_10032ae9(void)

{
  int unaff_EBP;

  CStdioFile::~CStdioFile((CStdioFile *)(unaff_EBP + -0x54));
  return;
}



/* VA 10032af2 */

void Unwind_10032af2(void)

{
  int unaff_EBP;

  FUN_1001e260((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



/* VA 10032afb */

void Unwind_10032afb(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x40));
  return;
}



/* VA 10032b04 */

void Unwind_10032b04(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x38));
  return;
}



/* VA 10032b0d */

void Unwind_10032b0d(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x3c));
  return;
}



/* VA 10032b16 */

void Unwind_10032b16(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x18));
  return;
}



/* VA 10032b1f */

void Unwind_10032b1f(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -100));
  return;
}



/* VA 10032b28 */

void Unwind_10032b28(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x68));
  return;
}



/* VA 10032b31 */

void Unwind_10032b31(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x70));
  return;
}



/* VA 10032b3a */

void Unwind_10032b3a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x74));
  return;
}



/* VA 10032b43 */

void Unwind_10032b43(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x7c) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
  }
  return;
}



/* VA 10032b5a */

void Unwind_10032b5a(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x78));
  return;
}



/* VA 10032b70 */

void Unwind_10032b70(void)

{
  FUN_1001e1e0();
  return;
}



/* VA 10032b79 */

void Unwind_10032b79(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



/* VA 10032b90 */

void Unwind_10032b90(void)

{
  FUN_1001e1e0();
  return;
}



/* VA 10032ba4 */

void Unwind_10032ba4(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032bac */

void Unwind_10032bac(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



/* VA 10032bd0 */

void Unwind_10032bd0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032bd8 */

void Unwind_10032bd8(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



/* VA 10032bfc */

void Unwind_10032bfc(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032c04 */

void Unwind_10032c04(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



/* VA 10032c28 */

void Unwind_10032c28(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



/* VA 10032c3f */

void Unwind_10032c3f(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 10032c54 */

void Unwind_10032c54(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



/* VA 10032c6b */

void Unwind_10032c6b(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 10032c80 */

void Unwind_10032c80(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



/* VA 10032c97 */

void Unwind_10032c97(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0xc));
  return;
}



/* VA 10032cac */

void Unwind_10032cac(void)

{
  FUN_1001e200();
  return;
}



/* VA 10032cc0 */

void Unwind_10032cc0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 10032cd4 */

void Unwind_10032cd4(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032ce8 */

void Unwind_10032ce8(void)

{
  FUN_1002c42a();
  return;
}



/* VA 10032cfc */

void Unwind_10032cfc(void)

{
  int unaff_EBP;

  FUN_10030bb0(*(HLOCAL *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032d10 */

void Unwind_10032d10(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032d18 */

void Unwind_10032d18(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0x10));
  return;
}



/* VA 10032d2c */

void Unwind_10032d2c(void)

{
  int unaff_EBP;

  FUN_1001e240(*(undefined **)(unaff_EBP + -0x14));
  return;
}



/* VA 10032d35 */

void Unwind_10032d35(void)

{
  FUN_1001e1e0();
  return;
}



/* VA 10032d3d */

void Unwind_10032d3d(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x14) + 0x10));
  return;
}



/* VA 10032d54 */

void Unwind_10032d54(void)

{
  FUN_1001e200();
  return;
}



/* VA 10032d74 */

void Unwind_10032d74(void)

{
  int unaff_EBP;

  FUN_10030bb0(*(HLOCAL *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032d94 */

void Unwind_10032d94(void)

{
  FUN_1002ace5();
  return;
}



/* VA 10032d9f */

void Unwind_10032d9f(void)

{
  FUN_1002ace5();
  return;
}



/* VA 10032dc0 */

void Unwind_10032dc0(void)

{
  FUN_1002ace5();
  return;
}



/* VA 10032dcb */

void Unwind_10032dcb(void)

{
  FUN_1002ace5();
  return;
}



/* VA 10032de0 */

void Unwind_10032de0(void)

{
  return;
}



/* VA 10032df4 */

void Unwind_10032df4(void)

{
  return;
}



/* VA 10032dfc */

void Unwind_10032dfc(void)

{
  int unaff_EBP;

  thunk_FUN_100310a9((int *)(*(int *)(unaff_EBP + -0x10) + 0x1070));
  return;
}



/* VA 10032e14 */

void Unwind_10032e14(void)

{
  return;
}



/* VA 10032e40 */

void Unwind_10032e40(void)

{
  FUN_1001e200();
  return;
}



/* VA 10032e48 */

void Unwind_10032e48(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



/* VA 10032e60 */

void Unwind_10032e60(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 8));
  return;
}



/* VA 10032e74 */

void Unwind_10032e74(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032e7c */

void Unwind_10032e7c(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



/* VA 10032ea0 */

void Unwind_10032ea0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032ea8 */

void Unwind_10032ea8(void)

{
  int unaff_EBP;

  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    FUN_1002b168(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



/* VA 10032ecc */

void Unwind_10032ecc(void)

{
  FUN_1001e200();
  return;
}



/* VA 10032eec */

void Unwind_10032eec(void)

{
  int unaff_EBP;

  FUN_1002becb(*(undefined **)(unaff_EBP + 8));
  return;
}



/* VA 10032f0c */

void Unwind_10032f0c(void)

{
  FUN_1002cc26();
  return;
}



/* VA 10032f2c */

void Unwind_10032f2c(void)

{
  FUN_1001ea46();
  return;
}



/* VA 10032f40 */

void Unwind_10032f40(void)

{
  FUN_10030166();
  return;
}



/* VA 10032f48 */

void Unwind_10032f48(void)

{
  int unaff_EBP;

  CWnd::~CWnd((CWnd *)(unaff_EBP + -0x60));
  return;
}



/* VA 10032f50 */

void Unwind_10032f50(void)

{
  FUN_10030166();
  return;
}



/* VA 10032f64 */

void Unwind_10032f64(void)

{
  int unaff_EBP;

  CWnd::~CWnd((CWnd *)(unaff_EBP + -0x48));
  return;
}



/* VA 10032f78 */

void Unwind_10032f78(void)

{
  int unaff_EBP;

  FUN_1001e240(*(undefined **)(unaff_EBP + -0x10));
  return;
}



/* VA 10032f8c */

void Unwind_10032f8c(void)

{
  int unaff_EBP;

  FUN_1002f5a7(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* VA 10032fa0 */

void Unwind_10032fa0(void)

{
  int unaff_EBP;

  FUN_10030bb0(*(HLOCAL *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032fb4 */

void Unwind_10032fb4(void)

{
  return;
}



/* VA 10032fc8 */

void Unwind_10032fc8(void)

{
  return;
}



/* VA 10032fdc */

void Unwind_10032fdc(void)

{
  FUN_1001e200();
  return;
}



/* VA 10032ff0 */

void Unwind_10032ff0(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + -0x10));
  return;
}



/* VA 10032ff8 */

void Unwind_10032ff8(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(unaff_EBP + 0x10));
  return;
}



/* VA 1003300c */

void Unwind_1003300c(void)

{
  int unaff_EBP;

  FUN_1001e240(*(undefined **)(unaff_EBP + -0x14));
  return;
}



/* VA 10033015 */

void Unwind_10033015(void)

{
  FUN_1001e1e0();
  return;
}



/* VA 1003301d */

void Unwind_1003301d(void)

{
  int unaff_EBP;

  FUN_1002b168((int *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



/* VA 10033034 */

void Unwind_10033034(void)

{
  FUN_1001e1e0();
  return;
}



/* VA 10033048 */

void Unwind_10033048(void)

{
  return;
}



/* VA 1003305c */

void Unwind_1003305c(void)

{
  int unaff_EBP;

  FUN_1002becb(*(undefined **)(unaff_EBP + 8));
  return;
}



/* VA 10033070 */

void Unwind_10033070(void)

{
  FUN_1001e200();
  return;
}



/* VA 10033084 */

void Unwind_10033084(void)

{
  FUN_1001e200();
  return;
}



/* VA 10033098 */

void Unwind_10033098(void)

{
  int unaff_EBP;

  FUN_1002becb(*(undefined **)(unaff_EBP + 8));
  return;
}



/* VA 100330ac */

void Unwind_100330ac(void)

{
  FUN_1001e200();
  return;
}



/* VA 100330c0 */

void Unwind_100330c0(void)

{
  int unaff_EBP;

  FUN_1002becb(*(undefined **)(unaff_EBP + 8));
  return;
}



/* VA 100330d4 */

void Unwind_100330d4(void)

{
  FUN_1001e200();
  return;
}



/* VA 100330e8 */

void Unwind_100330e8(void)

{
  FUN_1001e200();
  return;
}
