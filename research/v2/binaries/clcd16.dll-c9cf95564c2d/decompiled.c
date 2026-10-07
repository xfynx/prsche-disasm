/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 c9cf95564c2d5a57a89832f127a9e4d8ca3628be45277f75e38e22d91821afa0 */

/* VA 1000:0034 */

void FUN_1000_0034(undefined2 param_1)

{
  Ordinal_651(param_1);
  return;
}



/* VA 1000:005a */

/* WARNING: Removing unreachable block (ram,0x10000070) */
/* WARNING: Removing unreachable block (ram,0x10000077) */

undefined2 __stdcall16far WEP(void)

{
  return 1;
}



/* VA 1000:0096 */

undefined2 __stdcall16far FUN_1000_0096(void)

{
  return 1;
}



/* VA 1000:00be */

undefined2 * __cdecl16far FUN_1000_00be(undefined2 *param_1,undefined1 param_2,uint param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;

  if (param_3 != 0) {
    iVar6 = (int)((ulong)param_1 >> 0x10);
    uVar2 = -(int)(undefined2 *)param_1;
    uVar4 = 0;
    uVar3 = param_3;
    if (uVar2 != 0) {
      uVar3 = (uVar2 - param_3 & -(uint)(uVar2 < param_3)) + param_3;
      uVar4 = param_3 - uVar3;
    }
    puVar5 = (undefined2 *)param_1;
    for (uVar2 = uVar3 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar1 = CONCAT11(param_2,param_2);
    }
    for (uVar3 = (uint)((uVar3 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
      puVar1 = puVar5;
      puVar5 = (undefined2 *)((int)puVar5 + 1);
      *(undefined1 *)puVar1 = param_2;
    }
    if (uVar4 != 0) {
      for (uVar3 = uVar4 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar1 = CONCAT11(param_2,param_2);
      }
      for (uVar4 = (uint)((uVar4 & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
        puVar1 = puVar5;
        puVar5 = (undefined2 *)((int)puVar5 + 1);
        *(undefined1 *)puVar1 = param_2;
      }
    }
  }
  return (undefined2 *)param_1;
}



/* VA 1000:0106 */

void __cdecl16far FUN_1000_0106(void)

{
  uint in_CX;
  uint uVar1;

  for (uVar1 = in_CX & 0xff; uVar1 != 0; uVar1 = uVar1 - 1) {
  }
  return;
}



/* VA 1000:0112 */

undefined2 * __cdecl16far FUN_1000_0112(undefined2 *param_1,undefined2 *param_2,int param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;

  if (param_3 != 0) {
    iVar8 = (int)((ulong)param_2 >> 0x10);
    puVar5 = (undefined2 *)param_2;
    iVar7 = (int)((ulong)param_1 >> 0x10);
    puVar6 = (undefined2 *)param_1;
    while( true ) {
      uVar3 = ~(uint)puVar6;
      uVar3 = ((param_3 - 1U) - uVar3 & -(uint)(param_3 - 1U < uVar3)) + uVar3;
      uVar4 = ~(uint)puVar5;
      uVar3 = (uVar3 - uVar4 & -(uint)(uVar3 < uVar4)) + uVar4 + 1;
      param_3 = param_3 - uVar3;
      for (uVar4 = uVar3 >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
        puVar2 = puVar6;
        puVar6 = puVar6 + 1;
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar2 = *puVar1;
      }
      for (uVar3 = (uint)((uVar3 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
        puVar2 = puVar6;
        puVar6 = (undefined2 *)((int)puVar6 + 1);
        puVar1 = puVar5;
        puVar5 = (undefined2 *)((int)puVar5 + 1);
        *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
      }
      if (param_3 == 0) break;
      if (puVar5 == (undefined2 *)0x0) {
        iVar8 = iVar8 + 0x34;
      }
      if (puVar6 == (undefined2 *)0x0) {
        iVar7 = iVar7 + 0x34;
      }
    }
  }
  return (undefined2 *)param_1;
}



/* VA 1000:0170 */

undefined2 * __cdecl16far FUN_1000_0170(undefined2 *param_1,undefined1 param_2,uint param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;

  if (param_3 != 0) {
    iVar6 = (int)((ulong)param_1 >> 0x10);
    uVar2 = -(int)(undefined2 *)param_1;
    uVar4 = 0;
    uVar3 = param_3;
    if (uVar2 != 0) {
      uVar3 = (uVar2 - param_3 & -(uint)(uVar2 < param_3)) + param_3;
      uVar4 = param_3 - uVar3;
    }
    puVar5 = (undefined2 *)param_1;
    for (uVar2 = uVar3 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar1 = CONCAT11(param_2,param_2);
    }
    for (uVar3 = (uint)((uVar3 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
      puVar1 = puVar5;
      puVar5 = (undefined2 *)((int)puVar5 + 1);
      *(undefined1 *)puVar1 = param_2;
    }
    if (uVar4 != 0) {
      for (uVar3 = uVar4 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar1 = CONCAT11(param_2,param_2);
      }
      for (uVar4 = (uint)((uVar4 & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
        puVar1 = puVar5;
        puVar5 = (undefined2 *)((int)puVar5 + 1);
        *(undefined1 *)puVar1 = param_2;
      }
    }
  }
  return (undefined2 *)param_1;
}



/* VA 1000:01fc */

void __cdecl16far entry(void)

{
  code *pcVar1;
  int iVar2;
  int in_CX;
  undefined2 in_BX;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_CS;
  undefined2 uVar3;
  undefined2 uVar4;

  DAT_1008_0126 = 0x1008;
  uVar3 = unaff_CS;
  DAT_1008_0124 = unaff_DI;
  DAT_1008_0128 = in_CX;
  DAT_1008_012a = in_BX;
  DAT_1008_012c = unaff_SI;
  if (in_CX != 0) {
    uVar3 = 0x1010;
    iVar2 = LOCALINIT(unaff_CS,in_CX,0);
    if (iVar2 == 0) {
      return;
    }
  }
  LOCKSEGMENT(uVar3,0xffff);
  uVar4 = 0x23a;
  uVar3 = GETVERSION(0x1010);
  DAT_1008_014a = CONCAT11((char)uVar3,(char)((uint)uVar3 >> 8));
  if ((DAT_1000_01b8 & 1) == 0) {
    pcVar1 = (code *)swi(0x21);
    DAT_1008_014e = (*pcVar1)();
  }
  else {
    uVar4 = 0x1000;
    DAT_1008_014e = DOS3CALL(0x1000);
  }
  DAT_1008_014c = CONCAT11((char)DAT_1008_014e,(char)((uint)DAT_1008_014e >> 8));
  if ((DAT_1000_01b8 & 1) == 0) {
    DAT_1008_0151 = 0;
  }
  FUN_1000_02b6(uVar4);
  FUN_1000_03ea();
  DAT_1008_012e = DAT_1008_012e + '\x01';
  FUN_1000_039a(DAT_1008_016a,DAT_1008_016c,DAT_1008_016e,DAT_1008_0170,DAT_1008_0172);
  return;
}



/* VA 1000:029e */

undefined2 __stdcall16far FUN_1000_029e(void)

{
  return 1;
}



/* VA 1000:02b6 */

void __cdecl16far FUN_1000_02b6(void)

{
  int unaff_BP;
  int iVar1;
  bool bVar2;
  undefined2 uVar3;

  iVar1 = unaff_BP + 1;
  uVar3 = 0x1008;
  if (DAT_1008_0198 != 0) {
    bVar2 = false;
    (*DAT_1008_0196)();
    if (bVar2) {
      FUN_1000_0482();
      return;
    }
  }
  FUN_1000_0386(uVar3,iVar1);
  FUN_1000_0386();
  FUN_1000_0386();
  return;
}



/* VA 1000:02fe */

undefined2 __cdecl16far FUN_1000_02fe(void)

{
  DAT_1008_017b = 1;
  FUN_1000_0386();
  FUN_1000_0386();
  FUN_1000_0386();
  FUN_1000_0386();
  FUN_1000_07d8();
  FUN_1000_0498();
  return 0x100;
}



/* VA 1000:0386 */

void __cdecl16near FUN_1000_0386(void)

{
  int *piVar1;
  int *unaff_SI;
  int *unaff_DI;
  int *piVar2;

  while (unaff_SI < unaff_DI) {
    piVar2 = unaff_DI + -2;
    piVar1 = unaff_DI + -1;
    unaff_DI = piVar2;
    if (*piVar2 != 0 || *piVar1 != 0) {
      (*(code *)*piVar2)();
    }
  }
  return;
}



/* VA 1000:039a */

void __cdecl16far FUN_1000_039a(void)

{
  FUN_1000_029e(DAT_1008_012a,DAT_1008_012c,DAT_1008_0128,DAT_1008_0126,DAT_1008_0124);
  return;
}



/* VA 1000:03c6 */

void __cdecl16far FUN_1000_03c6(void)

{
  FUN_1000_04d1(0xfc);
  FUN_1000_04d1(0xff);
  return;
}



/* VA 1000:03ea */

void __cdecl16far FUN_1000_03ea(void)

{
  char cVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  char *pcVar11;
  undefined2 *puVar12;

  uVar10 = GETDOSENVIRONMENT();
  iVar4 = (int)((ulong)uVar10 >> 0x10);
  if ((int)uVar10 != 0) {
    iVar4 = 0;
  }
  iVar7 = 0;
  pcVar8 = (char *)0x0;
  iVar3 = -1;
  if (iVar4 != 0) {
    cVar1 = *(char *)0x0;
    while (cVar1 != '\0') {
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar11 = pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (*pcVar11 != '\0');
      iVar7 = iVar7 + 1;
      pcVar11 = pcVar8;
      pcVar8 = pcVar8 + 1;
      cVar1 = *pcVar11;
    }
  }
  pcVar11 = (char *)FUN_1000_0534();
  uVar5 = (undefined2)((ulong)pcVar11 >> 0x10);
  pcVar9 = (char *)pcVar11;
  puVar12 = (undefined2 *)FUN_1000_0534();
  uVar6 = (undefined2)((ulong)puVar12 >> 0x10);
  DAT_1008_0170 = (undefined2 *)puVar12;
  pcVar8 = (char *)0x0;
  for (; DAT_1008_0172 = (undefined2)((ulong)puVar12 >> 0x10), puVar2 = (undefined2 *)puVar12,
      iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar2 = pcVar9;
    puVar2[1] = uVar5;
    do {
      pcVar11 = pcVar8;
      pcVar8 = pcVar8 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar9;
      pcVar9 = pcVar9 + 1;
      *pcVar11 = cVar1;
      puVar12 = (undefined2 *)CONCAT22(DAT_1008_0172,puVar2 + 2);
    } while (cVar1 != '\0');
  }
  *puVar2 = 0;
  puVar2[1] = 0;
  return;
}



/* VA 1000:0482 */

void FUN_1000_0482(void)

{
  FUN_1000_04f2();
  return;
}



/* VA 1000:0488 */

undefined2 __cdecl16far FUN_1000_0488(void)

{
  undefined2 unaff_SS;

  if (___EXPORTEDSTUB != (code)0xb8) {
    return unaff_SS;
  }
  return uRam10000563;
}



/* VA 1000:0498 */

void __cdecl16near FUN_1000_0498(void)

{
  return;
}



/* VA 1000:049a */

int * __stdcall16far FUN_1000_049a(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;

  piVar3 = (int *)&DAT_1008_01aa;
  do {
    piVar1 = piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar3;
    if ((*piVar1 == param_1) || (piVar4 = (int *)0x0, *piVar1 == -1)) {
      return piVar4;
    }
    iVar2 = -1;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      piVar1 = piVar3;
      piVar3 = (int *)((int)piVar3 + 1);
    } while ((char)*piVar1 != '\0');
  } while( true );
}



/* VA 1000:04d1 */

undefined2 __stdcall16far FUN_1000_04d1(void)

{
  return 0x1008;
}



/* VA 1000:04f2 */

void FUN_1000_04f2(void)

{
  char *pcVar1;
  undefined2 in_AX;
  char *pcVar2;
  int iVar3;
  int in_CX;
  int iVar4;
  undefined2 uVar5;
  char *pcVar6;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined4 uVar7;
  undefined2 uVar8;

  uVar5 = in_AX;
  FUN_1000_03c6();
  FUN_1000_04d1(in_AX);
  pcVar2 = (char *)FUN_1000_049a(uVar5);
  uVar5 = 0;
  if (pcVar2 != (char *)0x0) {
    iVar3 = 9;
    if (*pcVar2 == 'M') {
      iVar3 = 0xf;
    }
    pcVar2 = pcVar2 + iVar3;
    unaff_ES = 0x1008;
    in_CX = 0x22;
    pcVar6 = pcVar2;
    do {
      if (in_CX == 0) break;
      in_CX = in_CX + -1;
      pcVar1 = pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar1 != '\r');
    pcVar6[-1] = '\0';
  }
  uVar8 = 0;
  FATALAPPEXIT(unaff_CS,pcVar2,0x1008);
  uVar7 = FATALEXIT(0x1010,0xff,uVar8);
  uVar8 = DAT_1008_0180;
  iVar4 = (int)((ulong)uVar7 >> 0x10);
  LOCK();
  DAT_1008_0180 = 0x1000;
  UNLOCK();
  iVar3 = FUN_1000_06af((int)uVar7,uVar8,in_CX,unaff_ES,uVar5);
  DAT_1008_0180 = uVar8;
  if (iVar4 != 0 || iVar3 != 0) {
    return;
  }
  FUN_1000_04f2();
  return;
}



/* VA 1000:0534 */

void __cdecl16near FUN_1000_0534(void)

{
  undefined2 uVar1;
  int iVar2;
  int in_DX;

  uVar1 = DAT_1008_0180;
  LOCK();
  DAT_1008_0180 = 0x1000;
  UNLOCK();
  iVar2 = FUN_1000_06af();
  DAT_1008_0180 = uVar1;
  if (in_DX != 0 || iVar2 != 0) {
    return;
  }
  FUN_1000_04f2();
  return;
}



/* VA 1000:0562 */

undefined2 __cdecl16far ___EXPORTEDSTUB(void)

{
  return 0;
}



/* VA 1000:0576 */

void __cdecl16near FUN_1000_0576(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int in_CX;
  uint uVar5;
  int iVar6;
  int in_BX;
  uint *unaff_SI;
  undefined2 *puVar7;
  bool bVar8;

  if ((*(byte *)(in_BX + 2) & 1) != 0) {
    FUN_1000_066d();
    if ((*unaff_SI & 1) != 0) {
      in_CX = (in_CX - *unaff_SI) + -1;
    }
    uVar4 = *(uint *)(in_BX + 4);
    if (uVar4 != 0) {
      if (!CARRY2(in_CX + 2U,uVar4)) {
        uVar2 = FUN_1000_0488();
        uVar4 = *(uint *)&DAT_1008_0180;
        if (uVar4 == 0x1000) goto LAB_1000_05c8;
        uVar5 = 0x8000;
        while (uVar4 <= uVar5) {
          uVar5 = uVar5 >> 1;
          if (uVar5 == 0) goto LAB_1000_05e1;
        }
        if (uVar5 < 8) goto LAB_1000_05e1;
        uVar4 = uVar5 << 1;
        goto LAB_1000_05c8;
      }
      uVar5 = 0xfff0;
      if (in_CX + 2U + uVar4 == 0) {
        while( true ) {
          bVar8 = false;
          iVar3 = FUN_1000_0607();
          if (!bVar8) break;
          if (uVar5 == 0xfff0) {
            return;
          }
LAB_1000_05e1:
          uVar4 = 0x10;
LAB_1000_05c8:
          uVar5 = ~(uVar4 - 1);
        }
        iVar6 = iVar3 - *(int *)(in_BX + 4);
        *(int *)(in_BX + 4) = iVar3;
        *(undefined2 *)(in_BX + 10) = unaff_SI;
        piVar1 = (int *)*(int *)(in_BX + 0xc);
        *piVar1 = iVar6 + -1;
        puVar7 = (undefined2 *)((int)piVar1 + iVar6);
        *puVar7 = 0xfffe;
        *(undefined2 *)(in_BX + 0xc) = puVar7;
      }
    }
  }
  return;
}



/* VA 1000:0607 */

void __cdecl16near FUN_1000_0607(void)

{
  int in_AX;
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  int in_BX;
  long lVar4;
  int iVar5;
  int iVar6;

  if ((*(byte *)(in_BX + 2) & 4) != 0) {
LAB_1000_0662:
    FUN_1000_04f2();
    return;
  }
  iVar5 = *(int *)(in_BX + 6);
  uVar3 = 0;
  if (in_AX == 0) {
    if ((DAT_1000_01b8 & 0x10) != 0) {
      return;
    }
    uVar3 = 1;
  }
  uVar1 = 0x2002;
  if ((DAT_1000_01b8 & 1) == 0) {
    uVar1 = 0x2020;
  }
  iVar6 = iVar5;
  iVar2 = GLOBALREALLOC(0x1000,uVar1,in_AX,uVar3);
  if (iVar2 != 0) {
    if ((iVar2 != iVar5) || (lVar4 = GLOBALSIZE(0x1010,iVar5,iVar6), lVar4 == 0))
    goto LAB_1000_0662;
    if ((*(byte *)(iVar5 + 2) & 4) != 0) {
      *(int *)(iVar5 + -2) = in_BX + -1;
    }
  }
  return;
}



/* VA 1000:066d */

void __cdecl16near FUN_1000_066d(void)

{
  int in_BX;
  uint *puVar1;

  puVar1 = (uint *)*(undefined2 *)(in_BX + 10);
  if (puVar1 == (uint *)*(undefined2 *)(in_BX + 0xc)) {
    puVar1 = (uint *)*(undefined2 *)(in_BX + 8);
  }
  while( true ) {
    if (*puVar1 == 0xfffe) break;
    puVar1 = (uint *)((int)puVar1 + (*puVar1 & 0xfffe) + 2);
  }
  return;
}



/* VA 1000:06af */

undefined2 __cdecl16far FUN_1000_06af(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_BX;
  uint uVar3;
  code *pcVar4;
  undefined2 unaff_CS;
  undefined2 uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  undefined4 uVar9;
  uint uVar10;

  uVar5 = 0x1008;
  do {
    if (param_1 < 0xffe7) {
      bVar7 = false;
      if (*(int *)((int)(undefined4 *)&DAT_1008_0186 + 2) != 0) {
        pcVar4 = (code *)0x7e6;
        while( true ) {
          uVar3 = *(uint *)&DAT_1008_0190;
          uVar6 = (uint)((ulong)*(undefined4 *)&DAT_1008_018a >> 0x10);
          in_BX = (int)*(undefined4 *)&DAT_1008_018a;
          uVar10 = uVar6;
          do {
            do {
              unaff_CS = 0x1000;
              uVar9 = (*pcVar4)();
              if (!bVar7) {
                if (pcVar4 == (code *)0x7e6) goto LAB_1000_0720;
                goto LAB_1000_071d;
              }
              puVar1 = (undefined4 *)(in_BX + 0xe);
              in_BX = (int)*puVar1;
              bVar7 = uVar6 < uVar3;
              bVar8 = uVar6 != uVar3;
              uVar6 = (uint)((ulong)*puVar1 >> 0x10);
            } while (bVar8);
            uVar3 = *(uint *)((int)*(undefined4 *)&DAT_1008_018a + 0x14);
            uVar6 = (uint)((ulong)*(undefined4 *)&DAT_1008_0186 >> 0x10);
            in_BX = (int)*(undefined4 *)&DAT_1008_0186;
            bVar7 = uVar6 < uVar10;
            bVar8 = uVar6 != uVar10;
            uVar10 = uVar6;
          } while (bVar8);
          bVar7 = pcVar4 < (code *)0x576;
          if (pcVar4 == (code *)0x576) break;
          pcVar4 = (code *)0x576;
        }
      }
      FUN_1000_0756();
      if (!bVar7) {
LAB_1000_071d:
        uVar9 = FUN_1000_07e6();
LAB_1000_0720:
        *(undefined2 *)((int)(undefined4 *)&DAT_1008_018a + 2) = (int)((ulong)uVar9 >> 0x10);
        *(int *)&DAT_1008_018a = in_BX;
        return (int)uVar9;
      }
    }
    if (*(int *)&DAT_1008_0184 == 0 && *(int *)&DAT_1008_0182 == 0) {
      return 0;
    }
    iVar2 = (*(code *)*(undefined2 *)&DAT_1008_0182)(unaff_CS,param_1);
    if (iVar2 == 0) {
      return 0;
    }
  } while( true );
}



/* VA 1000:0756 */

void __cdecl16near FUN_1000_0756(void)

{
  int iVar1;
  int in_CX;
  int iVar2;
  uint uVar3;
  int unaff_DI;
  undefined4 uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;

  uVar3 = in_CX + 0x1019U & 0xf000;
  iVar2 = 0;
  if (uVar3 == 0) {
    if ((DAT_1000_01b8 & 0x10) != 0) {
      return;
    }
    iVar2 = 1;
  }
  uVar6 = 0;
  uVar7 = DAT_1000_01b8;
  iVar1 = GLOBALALLOC(0x1000,uVar3,iVar2);
  if (iVar1 != 0) {
    if ((uVar6 & 1) != 0) {
      iVar2 = iVar1;
      uVar4 = GLOBALLOCK(0x1010,iVar1,iVar1,uVar7);
      iVar1 = (int)((ulong)uVar4 >> 0x10);
      if (((int)uVar4 != 0) || (iVar1 == 0)) goto LAB_1000_07cd;
    }
    lVar5 = GLOBALSIZE(0x1010,iVar1);
    if (lVar5 == 0) {
LAB_1000_07cd:
      FUN_1000_04f2();
      return;
    }
    *(int *)0x6 = iVar2;
    *(undefined2 *)0x2 = *(undefined2 *)(unaff_DI + 0xc);
    FUN_1000_088c();
    FUN_1000_08c0();
  }
  return;
}



/* VA 1000:07d8 */

void __cdecl16near FUN_1000_07d8(void)

{
  FUN_1000_0862();
  return;
}



/* VA 1000:07e6 */

uint * __cdecl16near FUN_1000_07e6(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int in_CX;
  uint uVar4;
  int in_BX;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;

  uVar4 = in_CX + 1U & 0xfffe;
  puVar7 = (uint *)*(undefined2 *)(in_BX + 10);
  puVar5 = (uint *)*(undefined2 *)(in_BX + 0xc);
  do {
    while( true ) {
      puVar1 = puVar7 + 1;
      uVar3 = *puVar7;
      puVar6 = puVar1;
      if ((uVar3 & 1) != 0) {
        while( true ) {
          uVar2 = uVar3 - 1;
          if (uVar4 <= uVar2) {
            *puVar7 = uVar4;
            puVar7 = puVar1;
            if (uVar2 != uVar4) {
              *(int *)((int)puVar1 + uVar4) = (uVar2 - uVar4) + -1;
              puVar7 = (uint *)((int)((int)puVar1 + uVar4) - uVar4);
            }
            *(int *)(in_BX + 10) = (int)puVar7 + uVar4;
            return puVar1;
          }
          if (CARRY2((uint)puVar1,uVar2)) goto LAB_1000_083f;
          puVar6 = (uint *)((int)puVar1 + uVar2) + 1;
          uVar3 = *(uint *)((int)puVar1 + uVar2);
          if ((uVar3 & 1) == 0) break;
          uVar3 = uVar3 + uVar2 + 2;
          *puVar7 = uVar3;
        }
      }
      if (puVar6 + -1 < puVar5) break;
      if (((uint)puVar5 & 1) != 0) goto LAB_1000_083f;
      puVar7 = (uint *)*(undefined2 *)(in_BX + 8);
      if ((uint *)*(undefined2 *)(in_BX + 10) == puVar7) goto LAB_1000_083f;
      puVar5 = (uint *)((int)*(undefined2 *)(in_BX + 10) + -1);
    }
    puVar7 = (uint *)((int)puVar6 + uVar3);
  } while (!CARRY2((uint)puVar6,uVar3));
LAB_1000_083f:
  puVar7 = (uint *)*(undefined2 *)(in_BX + 8);
  *(undefined2 *)(in_BX + 10) = puVar7;
  return puVar7;
}



/* VA 1000:0862 */

void __cdecl16near FUN_1000_0862(void)

{
  undefined4 *puVar1;
  undefined4 *in_BX;
  int iVar2;
  undefined2 unaff_ES;
  int iVar3;
  undefined2 unaff_CS;
  int iVar4;

  iVar3 = (int)((ulong)*in_BX >> 0x10);
  iVar2 = (int)*in_BX;
  while (iVar3 != 0) {
    iVar4 = *(int *)(iVar2 + 6);
    puVar1 = (undefined4 *)(iVar2 + 0xe);
    iVar2 = iVar4;
    GLOBALUNLOCK(unaff_CS,iVar4,iVar4,(int)((ulong)*puVar1 >> 0x10),(int)*puVar1);
    unaff_CS = 0x1010;
    iVar3 = iVar4;
    GLOBALFREE(0x1010);
  }
  return;
}



/* VA 1000:088c */

void __cdecl16near FUN_1000_088c(void)

{
  int *piVar1;
  int in_AX;
  undefined2 *in_BX;
  undefined2 *puVar2;

  in_BX[2] = in_AX + (int)in_BX;
  puVar2 = (undefined2 *)(in_AX + (int)in_BX + -2);
  piVar1 = in_BX + 0xb;
  *puVar2 = 0xfffe;
  in_BX[6] = puVar2;
  *piVar1 = in_AX + -0x19;
  *in_BX = 0x1008;
  in_BX[4] = piVar1;
  in_BX[5] = piVar1;
  in_BX[7] = 0;
  in_BX[8] = 0;
  in_BX[9] = 0;
  in_BX[10] = 0;
  return;
}



/* VA 1000:08c0 */

void __cdecl16near FUN_1000_08c0(void)

{
  int in_BX;
  int iVar1;
  int *unaff_DI;
  undefined2 unaff_ES;
  undefined2 uVar2;

  if (unaff_DI[1] == 0) {
    unaff_DI[1] = 0x1008;
    *unaff_DI = in_BX;
  }
  else {
    uVar2 = (undefined2)((ulong)*(undefined4 *)(unaff_DI + 4) >> 0x10);
    iVar1 = (int)*(undefined4 *)(unaff_DI + 4);
    *(undefined2 *)(iVar1 + 0x10) = 0x1008;
    *(int *)(iVar1 + 0xe) = in_BX;
    *(undefined2 *)(in_BX + 0x14) = uVar2;
    *(int *)(in_BX + 0x12) = iVar1;
  }
  unaff_DI[5] = 0x1008;
  unaff_DI[4] = in_BX;
  unaff_DI[3] = 0x1008;
  unaff_DI[2] = in_BX;
  return;
}



/* VA 1000:0900 */

bool __stdcall16far DLLENTRYPOINT(void)

{
  int iVar1;

  iVar1 = FUN_1000_0034();
  return iVar1 != 0;
}



/* VA 1000:092e */

bool __stdcall16far SETPMVECTOR_IF(undefined2 *param_1,undefined2 *param_2,byte param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_CS;
  bool bVar3;
  long lVar4;
  long lVar5;
  undefined2 uVar6;
  undefined2 uVar7;

  uVar7 = 0x1008;
  if ((*(byte *)(param_3 + 0x21) & 2) != 0) {
    param_3 = param_3 - 0x20;
  }
  if ((byte)(param_3 + 0xbf) < 0x1a) {
    uVar6 = 0;
    lVar4 = GLOBALDOSALLOC(unaff_CS,5);
    uVar1 = (undefined2)lVar4;
    if (lVar4 != 0) {
      FUN_1000_00be(0,uVar1,0,5,uVar6,uVar7);
      *(undefined1 *)0x0 = 6;
      uVar6 = 0;
      lVar5 = GLOBALDOSALLOC(0x1000,0x1c);
      uVar7 = (undefined2)lVar5;
      if (lVar5 != 0) {
        FUN_1000_00be(0,uVar7,0,0x1c,uVar6);
        *(undefined1 *)0x0 = 0x1c;
        *(undefined1 *)0x2 = 3;
        *(undefined2 *)0xe = 0;
        *(undefined2 *)&THK_THUNKDATA16 = (int)((ulong)lVar4 >> 0x10);
        *(undefined2 *)0x12 = 5;
        bVar3 = false;
        iVar2 = FUN_1000_1258(0,(int)((ulong)lVar5 >> 0x10),param_3 + 0xbf);
        if (iVar2 != 0) {
          bVar3 = (*(byte *)0x4 & 0x83) == 1;
          if (bVar3) {
            uVar6 = *(undefined2 *)0x3;
            *param_2 = *(undefined2 *)0x1;
            ((undefined2 *)param_2)[1] = uVar6;
          }
          *param_1 = *(undefined2 *)0x3;
        }
        GLOBALDOSFREE(0x1000,uVar1);
        GLOBALDOSFREE(0x1010,uVar7);
        return bVar3;
      }
      GLOBALDOSFREE(0x1010,uVar1);
    }
  }
  return false;
}



/* VA 1000:0a5c */

void __stdcall16far SETIDT_IF(undefined2 param_1,undefined2 param_2,undefined1 param_3)

{
  SETRMINTS_IF(param_1,param_2,2,CONCAT11(0x10,param_3));
  return;
}



/* VA 1000:0a7c */

void __stdcall16far GETIDT_IF(undefined2 param_1,undefined2 param_2,undefined1 param_3)

{
  SETRMINTS_IF(param_1,param_2,0,CONCAT11(0x10,param_3));
  return;
}



/* VA 1000:0a9c */

void __stdcall16far GETRMINTS_IF(undefined2 param_1,undefined2 param_2,undefined1 param_3)

{
  SETRMINTS_IF(param_1,param_2,5,CONCAT11(0x10,param_3));
  return;
}



/* VA 1000:0abc */

bool __stdcall16far SETRMINTS_IF(undefined2 *param_1,undefined1 param_2,byte param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_CS;
  bool bVar3;
  long lVar4;
  long lVar5;
  undefined2 uVar6;
  undefined2 uVar7;

  uVar7 = 0x1008;
  if ((*(byte *)(param_3 + 0x21) & 2) != 0) {
    param_3 = param_3 - 0x20;
  }
  if ((byte)(param_3 + 0xbf) < 0x1a) {
    uVar6 = 0;
    lVar4 = GLOBALDOSALLOC(unaff_CS,1);
    uVar1 = (undefined2)lVar4;
    if (lVar4 != 0) {
      FUN_1000_00be(0,uVar1,0,1,uVar6,uVar7);
      *(undefined1 *)0x0 = param_2;
      uVar6 = 0;
      lVar5 = GLOBALDOSALLOC(0x1000,0x1c);
      uVar7 = (undefined2)lVar5;
      if (lVar5 != 0) {
        FUN_1000_00be(0,uVar7,0,0x1c,uVar6);
        *(undefined1 *)0x0 = 0x1c;
        *(undefined1 *)0x2 = 0xc;
        *(undefined2 *)0xe = 0;
        *(undefined2 *)&THK_THUNKDATA16 = (int)((ulong)lVar4 >> 0x10);
        *(undefined2 *)0x12 = 1;
        bVar3 = false;
        iVar2 = FUN_1000_1258(0,(int)((ulong)lVar5 >> 0x10),param_3 + 0xbf);
        if (iVar2 != 0) {
          bVar3 = (*(byte *)0x4 & 0x83) == 1;
          *param_1 = *(undefined2 *)0x3;
        }
        GLOBALDOSFREE(0x1000,uVar1);
        GLOBALDOSFREE(0x1010,uVar7);
        return bVar3;
      }
      GLOBALDOSFREE(0x1010,uVar1);
    }
  }
  return false;
}



/* VA 1000:0bd2 */

undefined2 __stdcall16far
SETVECTORS_IF(char param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,byte param_6)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_CS;
  undefined4 uVar4;
  long lVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 local_c;

  uVar7 = 0x1008;
  if ((*(byte *)(param_6 + 0x21) & 2) != 0) {
    param_6 = param_6 - 0x20;
  }
  if ((byte)(param_6 + 0xbf) < 0x1a) {
    iVar3 = (-(uint)(param_1 == '\0') & 0xfed0) + 0x930;
    uVar6 = 0;
    uVar4 = GLOBALDOSALLOC(unaff_CS,iVar3);
    uVar1 = (undefined2)uVar4;
    FUN_1000_00be(0,uVar1,0,iVar3,uVar6,uVar7);
    uVar6 = 0;
    lVar5 = GLOBALDOSALLOC(0x1000,0x1b);
    uVar7 = (undefined2)lVar5;
    if (lVar5 != 0) {
      FUN_1000_00be(0,uVar7,0,0x1b,uVar6);
      *(undefined1 *)0x0 = 0x1b;
      *(undefined1 *)0x2 = 0x80;
      *(undefined2 *)0xe = 0;
      *(undefined2 *)&THK_THUNKDATA16 = (int)((ulong)uVar4 >> 0x10);
      *(undefined1 *)0xd = 0;
      *(undefined2 *)0x12 = 1;
      *(undefined2 *)0x14 = param_4;
      *(undefined2 *)0x16 = param_5;
      *(char *)0x18 = param_1;
      local_c = 0;
      iVar2 = FUN_1000_1258(0,(int)((ulong)lVar5 >> 0x10),param_6 + 0xbf);
      if ((iVar2 != 0) && ((*(byte *)0x4 & 0x83) == 1)) {
        FUN_1000_0112(param_2,param_3,0,uVar1,iVar3);
        local_c = 1;
      }
      GLOBALDOSFREE(0x1000,uVar1);
      GLOBALDOSFREE(0x1010,uVar7);
      return local_c;
    }
    GLOBALDOSFREE(0x1010,0);
  }
  return 0;
}



/* VA 1000:0d06 */

int __stdcall16far
GETPMVECTOR_IF(int param_1,int param_2,uint param_3,uint param_4,int param_5,byte param_6)

{
  undefined2 unaff_CS;
  undefined2 uVar1;
  bool bVar2;
  long lVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int local_18;
  undefined2 local_a;
  uint local_6;

  uVar5 = 0x1008;
  if ((*(byte *)(param_6 + 0x21) & 2) != 0) {
    param_6 = param_6 - 0x20;
  }
  if (((((byte)(param_6 + 0xbf) < 0x1a) && (param_2 != 0 || param_1 != 0)) && (param_3 != 0)) &&
     (param_3 < 0x141)) {
    uVar4 = 0;
    uVar1 = 0x1010;
    lVar3 = GLOBALDOSALLOC(unaff_CS,0x800);
    if (lVar3 != 0) {
      local_a = 0;
      bVar2 = false;
      for (local_6 = 0; (!bVar2 && (local_6 < param_3)); local_6 = local_6 + 1) {
        uVar1 = 0x1000;
        local_18 = FUN_1000_11d0(0,(int)((ulong)lVar3 >> 0x10),local_6 + param_4,
                                 param_5 + (uint)CARRY2(local_6,param_4),param_6 + 0xbf);
        if (local_18 == 0) break;
        uVar1 = 0x1000;
        FUN_1000_0112(local_a + param_1,param_2,0,(int)lVar3,0x800);
        bVar2 = 0xfffe < local_6;
        local_a = (uint)(byte)(local_a._1_1_ + 8) << 8;
      }
      GLOBALDOSFREE(uVar1,(int)lVar3,uVar4,uVar5);
      return local_18;
    }
  }
  return 0;
}



/* VA 1000:0dfe */

bool __stdcall16far GETV86VECTOR_IF(undefined2 *param_1,undefined2 *param_2,byte param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_CS;
  bool bVar3;
  long lVar4;
  long lVar5;
  undefined2 uVar6;
  undefined2 uVar7;

  uVar7 = 0x1008;
  if ((*(byte *)(param_3 + 0x21) & 2) != 0) {
    param_3 = param_3 - 0x20;
  }
  if ((byte)(param_3 + 0xbf) < 0x1a) {
    uVar6 = 0;
    lVar4 = GLOBALDOSALLOC(unaff_CS,5);
    uVar1 = (undefined2)lVar4;
    if (lVar4 != 0) {
      FUN_1000_00be(0,uVar1,0,5,uVar6,uVar7);
      *(undefined1 *)0x0 = 8;
      uVar6 = 0;
      lVar5 = GLOBALDOSALLOC(0x1000,0x1c);
      uVar7 = (undefined2)lVar5;
      if (lVar5 != 0) {
        FUN_1000_00be(0,uVar7,0,0x1c,uVar6);
        *(undefined1 *)0x0 = 0x1c;
        *(undefined1 *)0x2 = 3;
        *(undefined2 *)0xe = 0;
        *(undefined2 *)&THK_THUNKDATA16 = (int)((ulong)lVar4 >> 0x10);
        *(undefined2 *)0x12 = 5;
        bVar3 = false;
        iVar2 = FUN_1000_1258(0,(int)((ulong)lVar5 >> 0x10),param_3 + 0xbf);
        if (iVar2 != 0) {
          bVar3 = (*(byte *)0x4 & 0x83) == 1;
          if (bVar3) {
            uVar6 = *(undefined2 *)0x3;
            *param_2 = *(undefined2 *)0x1;
            ((undefined2 *)param_2)[1] = uVar6;
          }
          *param_1 = *(undefined2 *)0x3;
        }
        GLOBALDOSFREE(0x1000,uVar1);
        GLOBALDOSFREE(0x1010,uVar7);
        return bVar3;
      }
      GLOBALDOSFREE(0x1010,uVar1);
    }
  }
  return false;
}



/* VA 1000:0f2c */

bool __stdcall16far SETV86VECTOR_IF(undefined2 *param_1,int *param_2,byte param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_CS;
  bool bVar4;
  long lVar5;
  long lVar6;
  undefined2 uVar7;
  undefined2 uVar8;

  uVar8 = 0x1008;
  uVar3 = (undefined2)((ulong)param_2 >> 0x10);
  ((int *)param_2)[1] = 0;
  *param_2 = 0;
  if ((*(byte *)(param_3 + 0x21) & 2) != 0) {
    param_3 = param_3 - 0x20;
  }
  if ((byte)(param_3 + 0xbf) < 0x1a) {
    uVar7 = 0;
    lVar5 = GLOBALDOSALLOC(unaff_CS,7);
    uVar1 = (undefined2)lVar5;
    if (lVar5 != 0) {
      FUN_1000_00be(0,uVar1,0,7,uVar7,uVar8);
      *(undefined1 *)0x0 = 10;
      uVar7 = 0;
      lVar6 = GLOBALDOSALLOC(0x1000,0x1c);
      uVar8 = (undefined2)lVar6;
      if (lVar6 != 0) {
        FUN_1000_00be(0,uVar8,0,0x1c,uVar7);
        *(undefined1 *)0x0 = 0x1c;
        *(undefined1 *)0x2 = 3;
        *(undefined2 *)0xe = 0;
        *(undefined2 *)&THK_THUNKDATA16 = (int)((ulong)lVar5 >> 0x10);
        *(undefined2 *)0x12 = 7;
        bVar4 = false;
        iVar2 = FUN_1000_1258(0,(int)((ulong)lVar6 >> 0x10),param_3 + 0xbf);
        if (iVar2 != 0) {
          bVar4 = (*(byte *)0x4 & 0x83) == 1;
          if (bVar4) {
            iVar2 = ((uint)*(byte *)0x2 - (uint)*(byte *)0x1) + 1;
            *param_2 = iVar2;
            ((int *)param_2)[1] = iVar2 >> 0xf;
          }
          *param_1 = *(undefined2 *)0x3;
        }
        GLOBALDOSFREE(0x1000,uVar1);
        GLOBALDOSFREE(0x1010,uVar8);
        return bVar4;
      }
      GLOBALDOSFREE(0x1010,uVar1);
    }
  }
  return false;
}



/* VA 1000:106e */

void __stdcall16far
GETVECTORS_IF(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  FUN_1000_12c0(param_1,param_2,param_3,param_4);
  return;
}



/* VA 1000:108e */

void __stdcall16far
INITVECTORS(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  FUN_1000_1320(param_1,param_2,param_3,param_4);
  return;
}



/* VA 1000:10ae */

bool __stdcall16far INITIV(undefined2 *param_1,undefined2 *param_2,undefined1 param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_CS;
  bool bVar3;
  long lVar4;
  long lVar5;
  undefined2 uVar6;
  undefined2 uVar7;

  uVar7 = 0x1008;
  uVar6 = 0;
  lVar4 = GLOBALDOSALLOC(unaff_CS,5);
  uVar1 = (undefined2)lVar4;
  if (lVar4 != 0) {
    FUN_1000_00be(0,uVar1,0,5,uVar6,uVar7);
    *(undefined1 *)0x0 = 6;
    uVar7 = 0;
    lVar5 = GLOBALDOSALLOC(0x1000,0x1c);
    uVar6 = (undefined2)lVar5;
    if (lVar5 != 0) {
      FUN_1000_00be(0,uVar6,0,0x1c,uVar7);
      *(undefined1 *)0x0 = 0x1c;
      *(undefined1 *)0x2 = 3;
      *(undefined2 *)0xe = 0;
      *(undefined2 *)&THK_THUNKDATA16 = (int)((ulong)lVar4 >> 0x10);
      *(undefined2 *)0x12 = 5;
      bVar3 = false;
      iVar2 = FUN_1000_1258(0,(int)((ulong)lVar5 >> 0x10),param_3);
      if (iVar2 != 0) {
        bVar3 = (*(byte *)0x4 & 0x83) == 1;
        if (bVar3) {
          uVar7 = *(undefined2 *)0x3;
          *param_2 = *(undefined2 *)0x1;
          ((undefined2 *)param_2)[1] = uVar7;
        }
        *param_1 = *(undefined2 *)0x3;
      }
      GLOBALDOSFREE(0x1000,uVar1);
      GLOBALDOSFREE(0x1010,uVar6);
      return bVar3;
    }
    GLOBALDOSFREE(0x1010,uVar1);
  }
  return false;
}



/* VA 1000:11d0 */

bool __stdcall16far
FUN_1000_11d0(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             byte param_5)

{
  int iVar1;
  undefined2 unaff_SS;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  uint local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  byte local_14;
  undefined2 local_12;

  FUN_1000_13ba(&local_34,unaff_SS);
  local_18 = 0x1508;
  local_16 = 0;
  local_24 = param_1;
  local_22 = 0;
  local_12 = param_2;
  local_1c = (uint)param_5;
  local_1a = 0;
  local_20 = 1;
  local_1e = 0;
  local_30 = param_4;
  local_2e = 0;
  local_34 = param_3;
  local_32 = 0;
  iVar1 = FUN_1000_1390(&local_34,unaff_SS,0x2f);
  return iVar1 != 0 && (local_14 & 1) == 0;
}



/* VA 1000:1258 */

bool __stdcall16far FUN_1000_1258(undefined2 param_1,undefined2 param_2,byte param_3)

{
  int iVar1;
  undefined2 unaff_SS;
  undefined1 local_34 [16];
  undefined2 local_24;
  undefined2 local_22;
  uint local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  byte local_14;
  undefined2 local_12;

  FUN_1000_13ba(local_34,unaff_SS);
  local_18 = 0x1510;
  local_16 = 0;
  local_24 = param_1;
  local_22 = 0;
  local_12 = param_2;
  local_1c = (uint)param_3;
  local_1a = 0;
  iVar1 = FUN_1000_1390(local_34,unaff_SS,0x2f);
  return iVar1 != 0 && (local_14 & 1) == 0;
}



/* VA 1000:12c0 */

bool __stdcall16far FUN_1000_12c0(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 unaff_SS;
  bool bVar3;
  undefined1 local_34 [16];
  undefined1 local_24;
  undefined2 local_18;
  undefined2 local_16;
  byte local_14;

  FUN_1000_13ba(local_34,unaff_SS);
  local_18 = 0x150c;
  local_16 = 0;
  iVar2 = FUN_1000_1390(local_34,unaff_SS,0x2f);
  bVar3 = false;
  if ((iVar2 != 0) && (bVar3 = (local_14 & 1) == 0, bVar3)) {
    uVar1 = FUN_1000_0106();
    *param_2 = uVar1;
    *param_1 = local_24;
  }
  return bVar3;
}



/* VA 1000:1320 */

bool __stdcall16far
FUN_1000_1320(undefined1 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  undefined2 unaff_SS;
  bool bVar2;
  undefined1 local_34 [16];
  int local_24;
  undefined2 local_1c;
  undefined2 local_1a;
  int local_18;
  undefined2 local_16;
  byte local_14;

  *param_1 = 0;
  FUN_1000_13ba(local_34,unaff_SS);
  local_18 = 0x150b;
  local_16 = 0;
  local_1c = param_3;
  local_1a = param_4;
  iVar1 = FUN_1000_1390(local_34,unaff_SS,0x2f);
  bVar2 = false;
  if ((((iVar1 != 0) && (bVar2 = (local_14 & 1) == 0, bVar2)) && (local_18 != 0)) &&
     (local_24 == -0x5253)) {
    *param_1 = 1;
  }
  return bVar2;
}



/* VA 1000:1390 */

bool __stdcall16far FUN_1000_1390(void)

{
  code *pcVar1;
  bool bVar2;

  bVar2 = false;
  pcVar1 = (code *)swi(0x31);
  (*pcVar1)();
  return !bVar2;
}



/* VA 1000:13ba */

void __stdcall16far FUN_1000_13ba(undefined2 param_1,undefined2 param_2)

{
  FUN_1000_0170(param_1,param_2,0,0x32);
  return;
}



/* VA 1000:13d0 */

undefined2 __stdcall16far ISLOADCOMPLETE(undefined1 *param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 local_a;

  local_a = 0;
  *param_1 = 0;
  iVar1 = ALLOCSELECTOR();
  if (iVar1 != 0) {
    iVar3 = 0xf;
    iVar4 = iVar1;
    iVar2 = SETSELECTORBASE(0x1010,0xfff0,0xf);
    if (iVar2 != 0) {
      iVar3 = iVar1;
      SETSELECTORLIMIT(0x1010,0x10,0);
      if ((*(char *)0x7 != '/') && (*(char *)0xa != '/')) {
        *param_1 = 1;
      }
      local_a = 1;
    }
    FREESELECTOR(0x1010,iVar1,iVar3,iVar4);
  }
  return local_a;
}



/* VA 1010:0000 */

/* WARNING: Control flow encountered bad instruction data */

void FATALEXIT(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0004 */

/* WARNING: Control flow encountered bad instruction data */

void GETVERSION(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0008 */

/* WARNING: Control flow encountered bad instruction data */

void LOCALINIT(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:000c */

/* WARNING: Control flow encountered bad instruction data */

void GLOBALALLOC(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0010 */

/* WARNING: Control flow encountered bad instruction data */

void GLOBALREALLOC(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0014 */

/* WARNING: Control flow encountered bad instruction data */

void GLOBALFREE(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0018 */

/* WARNING: Control flow encountered bad instruction data */

void GLOBALLOCK(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:001c */

/* WARNING: Control flow encountered bad instruction data */

void GLOBALUNLOCK(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0020 */

/* WARNING: Control flow encountered bad instruction data */

void GLOBALSIZE(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0024 */

/* WARNING: Control flow encountered bad instruction data */

void LOCKSEGMENT(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0028 */

/* WARNING: Control flow encountered bad instruction data */

void GETMODULEUSAGE(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:002c */

/* WARNING: Control flow encountered bad instruction data */

void INITTASK(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0030 */

/* WARNING: Control flow encountered bad instruction data */

void DOS3CALL(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0034 */

/* WARNING: Control flow encountered bad instruction data */

void __AHINCR(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0038 */

/* WARNING: Control flow encountered bad instruction data */

void GETDOSENVIRONMENT(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:003c */

/* WARNING: Control flow encountered bad instruction data */

void FATALAPPEXIT(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0040 */

/* WARNING: Control flow encountered bad instruction data */

void ALLOCSELECTOR(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0044 */

/* WARNING: Control flow encountered bad instruction data */

void FREESELECTOR(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0048 */

/* WARNING: Control flow encountered bad instruction data */

void __WINFLAGS(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:004c */

/* WARNING: Control flow encountered bad instruction data */

void GLOBALDOSALLOC(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0050 */

/* WARNING: Control flow encountered bad instruction data */

void GLOBALDOSFREE(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0054 */

/* WARNING: Control flow encountered bad instruction data */

void SETSELECTORBASE(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:0058 */

/* WARNING: Control flow encountered bad instruction data */

void SETSELECTORLIMIT(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 1010:005c */

/* WARNING: Control flow encountered bad instruction data */

void Ordinal_651(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
