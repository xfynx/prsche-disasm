/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 9e4b48c6e29191d71f9791e089f9f624c7f5cd90cc3b3728ad11e0be64b82fe6 */

/* VA 60001000 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * _THRASH_about_0(void)

{
  uint uVar1;

                    /* 0x1000  1  _THRASH_about@0 */
  _DAT_600fc7c0 = 0x44334437;
  _DAT_600fc7c4 = 0xd0;
  _DAT_600fc7c8 = DAT_60017128;
  if (DAT_6005ab64 == 0) {
    _DAT_600fc7d0 = 8;
    _DAT_600fc7dc = 8;
    _DAT_600fc7d4 = 0x100;
    _DAT_600fc7e0 = 0x100;
    _DAT_600fc7d8 = 1;
    _DAT_600fc7e4 = 1;
    _DAT_600fc804 = 1;
    uVar1 = DAT_600fc7cc | 0xe;
  }
  else {
    _DAT_600fc7d0 = DAT_6005ab60;
    if (DAT_6005ab60 < 4) {
      _DAT_600fc7d0 = 4;
    }
    _DAT_600fc7dc = DAT_6005ab68;
    if (DAT_6005ab68 < 4) {
      _DAT_600fc7dc = 4;
    }
    _DAT_600fc7d4 = DAT_6005ab64;
    _DAT_600fc7e0 = DAT_6005ab6c;
    _DAT_600fc7d8 = DAT_6005ab70;
    _DAT_600fc7e4 = DAT_6005ab78;
    _DAT_600fc804 = DAT_6005ab80;
    uVar1 = DAT_600fc7cc ^ (DAT_6005ab74 << 2 ^ DAT_600fc7cc) & 4;
    uVar1 = uVar1 ^ (DAT_6005ab7c << 3 ^ uVar1) & 8;
    uVar1 = uVar1 ^ (DAT_6005ab84 * 2 ^ uVar1) & 2;
  }
  DAT_600fc7cc = (uVar1 ^ (DAT_60058d6c << 4 ^ uVar1) & 0x10) & 0xffffff3f | 0x21;
  _DAT_600fc7e8 = 0;
  _DAT_600fc83c = 7;
  _DAT_600fc7ec = 0x14;
  _DAT_600fc7f0 = &DAT_60017010;
  _DAT_600fc7f4 = 4;
  _DAT_600fc7f8 = &DAT_60017068;
  DAT_600fc800 = &DAT_60017250;
  DAT_600fc80c = DAT_600150e4;
  DAT_600fc810 = DAT_600150e8;
  DAT_600fc814 = DAT_600150ec;
  _DAT_600fc838 = "Daniel Kennett, Thursday 04:50PM Jan 18, 2001";
  FUN_60002060();
  FUN_600092c0((int *)&DAT_600fc7c0,&DAT_600150b0);
  return &DAT_600fc7c0;
}



/* VA 600011a0 */

bool _THRASH_window_4(int param_1)

{
  uint uVar1;
  char *pcVar2;

                    /* 0x11a0  44  _THRASH_window@4 */
  FUN_60001e70(0x3b,param_1);
  if (param_1 < 9) {
    if (DAT_600186d0 < 9) goto LAB_6000125b;
    if (DAT_600186a8 == 0) {
      uVar1 = (**(code **)(*DAT_60058d9c + 0x20))(DAT_60058d9c,DAT_600186a4,0);
    }
    else {
      uVar1 = (**(code **)(*DAT_60058d9c + 0x20))(DAT_60058d9c,DAT_600186a8);
    }
    if (-1 < (int)uVar1) goto LAB_6000125b;
    DAT_60058e28 = "dx7\\dx7wind.c";
    DAT_60058e24 = 0x42;
    FUN_60003a20(uVar1);
    pcVar2 = "Could not attach itself to PRIMARY window!\n%s";
  }
  else {
    DAT_600186cc = *(undefined4 *)(*(int *)(&DAT_6007c7c0 + param_1 * 8) + 0x34);
    DAT_600186d0 = param_1;
    uVar1 = (**(code **)(*DAT_60058d9c + 0x20))(DAT_60058d9c,DAT_600186cc,0);
    if (-1 < (int)uVar1) goto LAB_6000125b;
    DAT_60058e28 = "dx7\\dx7wind.c";
    DAT_60058e24 = 0x36;
    FUN_60003a20(uVar1);
    pcVar2 = "Could not attach itself to user render window!\n%s";
  }
  FUN_6000ba10(pcVar2);
LAB_6000125b:
  DAT_600186cc = DAT_60058d94;
  if ((param_1 != 3) && (param_1 != 5)) {
    if ((param_1 == 2) && (DAT_600186b4 == 0)) {
      DAT_600186cc = DAT_600186b0;
      DAT_600186d0 = 1;
      return DAT_600186b0 != 0;
    }
    DAT_600186cc = *(int *)(&DAT_600186ac + param_1 * 4);
    if (param_1 == 0) {
      DAT_600186d0 = 0;
      DAT_600186cc = 0;
      return false;
    }
  }
  DAT_600186d0 = param_1;
  return DAT_600186cc != 0;
}



/* VA 600012e0 */

void _THRASH_clearwindow_0(void)

{
                    /* 0x12e0  2  _THRASH_clearwindow@0 */
  FUN_60008dc0(DAT_60018238,DAT_6001823c,DAT_60018240 + DAT_60018238,DAT_6001823c + DAT_60018244,
               (uint)(DAT_600186cc == DAT_60058d94));
  return;
}



/* VA 60001320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool _THRASH_flushwindow_0(void)

{
  int iVar1;

                    /* 0x1320  23  _THRASH_flushwindow@0 */
  if (0 < DAT_60058874) {
    FUN_60006f20();
  }
  if (DAT_6001822c != 0) {
    _DAT_6001885c = 0;
    iVar1 = (**(code **)(*DAT_60058d9c + 0x18))(DAT_60058d9c);
    DAT_6001822c = 0;
    return iVar1 == 0;
  }
  return true;
}



/* VA 60001330 */

void _THRASH_pageflip_0(void)

{
                    /* 0x1330  30  _THRASH_pageflip@0 */
  _THRASH_idle_0();
  FUN_60008860();
  if (DAT_60018230 != 0) {
    DAT_60058e28 = "dx7\\dx7wind.c";
    DAT_60058e24 = 0xa9;
    FUN_6000ba10("D3D pageflip called in while locked\n");
  }
  FUN_60008a50();
  return;
}



/* VA 60001370 */

void _THRASH_idle_0(void)

{
                    /* 0x1370  26  _THRASH_idle@0 */
  return;
}



/* VA 60001380 */

undefined4 _THRASH_sync_4(int param_1)

{
                    /* 0x1380  37  _THRASH_sync@4 */
  if (param_1 == 0) {
    FUN_60001650(2);
    _THRASH_unlockwindow_4();
  }
  else if (param_1 == 2) {
    (**(code **)(*DAT_60058d80 + 0x58))(DAT_60058d80,1,0);
    return 0;
  }
  return 0;
}



/* VA 600013c0 */

undefined4 _THRASH_clip_16(int param_1,int param_2,int param_3,int param_4)

{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;

                    /* 0x13c0  3  _THRASH_clip@16 */
  DAT_60018238 = param_1;
  DAT_6001823c = param_2;
  DAT_60018240 = param_3 - param_1;
  DAT_60018244 = param_4 - param_2;
  FUN_6000bad0((undefined8 *)&local_18,0,0x18);
  local_18 = param_1;
  local_14 = param_2;
  local_8 = 0;
  local_4 = 0x3f800000;
  local_10 = param_3 - param_1;
  local_c = param_4 - param_2;
  FUN_60006f10();
  if (DAT_6001822c != 0) {
    FUN_60008860();
  }
  (**(code **)(*DAT_60058d9c + 0x34))(DAT_60058d9c,&local_18);
  return 1;
}



/* VA 60001460 */

void FUN_60001460(void)

{
  DAT_60018238 = 0;
  DAT_6001823c = 0;
  DAT_60018240 = 0;
  DAT_60018244 = 0;
  return;
}



/* VA 60001480 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * _THRASH_lockwindow_0(void)

{
  int iVar1;
  undefined4 *puVar2;
  tagPOINT tStack_ac;
  LONG LStack_a4;
  LONG LStack_a0;
  int iStack_84;
  undefined4 auStack_80 [4];
  int iStack_70;
  int iStack_40;
  int iStack_38;

                    /* 0x1480  29  _THRASH_lockwindow@0 */
  if (DAT_600186cc != (int *)0x0) {
    if (DAT_60018230 != 0) {
      DAT_60058e28 = "dx7\\dx7wind.c";
      DAT_60058e24 = 0x127;
      LStack_a0 = 0x600014bc;
      FUN_6000ba10("D3D lock called while locked\n");
    }
    LStack_a0 = 0x600014ca;
    iVar1 = (**(code **)(*DAT_600186cc + 0x60))();
    if (-1 < iVar1) {
      if (DAT_6001822c != 0) {
        LStack_a0 = 0x600014dc;
        FUN_60008860();
      }
      if (DAT_6007b874 != (code *)0x0) {
        LStack_a0 = 1;
        LStack_a4 = 0x600014e9;
        (*DAT_6007b874)();
      }
      LStack_a0 = 0;
      puVar2 = auStack_80;
      for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      LStack_a4 = 0x801;
      tStack_ac.y = (LONG)auStack_80;
      tStack_ac.x = 0;
      auStack_80[0] = 0x7c;
      DAT_60018234 = DAT_600186cc;
      DAT_60018680 = (**(code **)(*DAT_600186cc + 100))(DAT_600186cc);
      if (-1 < DAT_60018680) {
        if (iStack_40 == 0x10) {
          _DAT_60018220 = ((iStack_38 == 0x7e0) - 1 & 7) + 4;
        }
        else if (iStack_40 == 0x20) {
          _DAT_60018220 = 6;
        }
        else if (iStack_40 == 0x18) {
          _DAT_60018220 = 5;
        }
        if (DAT_60018688 != 0) {
          GetClientRect(DAT_6007b880,(LPRECT)&LStack_a4);
          tStack_ac.x = 0;
          tStack_ac.y = 0;
          ClientToScreen(DAT_6007b880,&tStack_ac);
          OffsetRect((LPRECT)&LStack_a4,tStack_ac.x,tStack_ac.y);
          if (DAT_600186cc == DAT_600186b0) {
            iStack_70 = iStack_84 * LStack_a0 + iStack_70 +
                        ((int)(iStack_40 + (iStack_40 >> 0x1f & 7U)) >> 3) * LStack_a4;
          }
        }
        _DAT_60018218 = iStack_70;
        _DAT_6001821c = iStack_84;
        _DAT_60018224 = DAT_6005aac0;
        _DAT_60018228 = DAT_6005a934;
        DAT_60018230 = 1;
        return &DAT_60018218;
      }
      if (DAT_6007b874 != (code *)0x0) {
        (*DAT_6007b874)(0);
      }
    }
  }
  return (undefined *)0x0;
}



/* VA 60001650 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * __cdecl FUN_60001650(int param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  undefined4 *puVar3;
  tagPOINT tStack_a8;
  int iVar4;
  int iStack_80;
  undefined4 local_7c [4];
  int iStack_6c;
  int iStack_3c;
  int iStack_34;

  uVar2 = 0;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else if (param_1 == 1) {
    uVar2 = 0x10;
  }
  else if (param_1 == 2) {
    uVar2 = 0x20;
  }
  if (DAT_600186cc != (int *)0x0) {
    if (DAT_60018230 != 0) {
      DAT_60058e28 = "dx7\\dx7wind.c";
      DAT_60058e24 = 0x1af;
      tStack_a8.y = 0x600016ac;
      FUN_6000ba10("D3D lock called while locked\n");
    }
    if (DAT_6001822c != 0) {
      FUN_60008860();
    }
    if (DAT_6007b874 != (code *)0x0) {
      tStack_a8.y = 0x600016ca;
      (*DAT_6007b874)();
    }
    iVar4 = 0;
    tStack_a8.y = uVar2 | 0x801;
    tStack_a8.x = (LONG)local_7c;
    puVar3 = local_7c;
    for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    local_7c[0] = 0x7c;
    DAT_60018234 = DAT_600186cc;
    DAT_60018680 = (**(code **)(*DAT_600186cc + 100))(DAT_600186cc,0);
    if (DAT_60018680 != 0) {
      if (DAT_6007b874 != (code *)0x0) {
        (*DAT_6007b874)(0);
      }
      return (undefined *)0x0;
    }
    if (iStack_3c == 0x10) {
      _DAT_60018220 = ((iStack_34 == 0x7e0) - 1 & 7) + 4;
    }
    else if (iStack_3c == 0x20) {
      _DAT_60018220 = 6;
    }
    else if (iStack_3c == 0x18) {
      _DAT_60018220 = 5;
    }
    if (DAT_60018688 != 0) {
      GetClientRect(DAT_6007b880,(LPRECT)&stack0xffffff60);
      tStack_a8.x = 0;
      tStack_a8.y = 0;
      ClientToScreen(DAT_6007b880,&tStack_a8);
      OffsetRect((LPRECT)&stack0xffffff60,tStack_a8.x,tStack_a8.y);
      if (DAT_600186cc == DAT_600186b0) {
        iStack_6c = iStack_80 * unaff_EDI + iStack_6c +
                    ((int)(iStack_3c + (iStack_3c >> 0x1f & 7U)) >> 3) * iVar4;
      }
    }
    _DAT_6001821c = iStack_80;
    _DAT_60018224 = DAT_6005aac0;
    _DAT_60018228 = DAT_6005a934;
    DAT_60018230 = 1;
    _DAT_60018218 = iStack_6c;
  }
  return &DAT_60018218;
}



/* VA 60001830 */

undefined4 _THRASH_unlockwindow_4(void)

{
  int iVar1;

                    /* 0x1830  43  _THRASH_unlockwindow@4 */
  if ((DAT_60018230 != 0) && (DAT_60018234 != (int *)0x0)) {
    iVar1 = (**(code **)(*DAT_60018234 + 0x80))(DAT_60018234,0);
    if (iVar1 < 0) {
      return 0;
    }
    DAT_60018234 = (int *)0x0;
    DAT_60018230 = 0;
    if (DAT_6007b874 != (code *)0x0) {
      (*DAT_6007b874)(0);
    }
  }
  return 1;
}



/* VA 60001880 */

int _THRASH_createwindow_16(undefined4 param_1,undefined4 param_2,uint param_3)

{
  void *pvVar1;

                    /* 0x1880  4  _THRASH_createwindow@16 */
  if ((DAT_6005ab5c != 0) && (((param_3 == 3 || (param_3 == 4)) || (param_3 == 6)))) {
    DAT_6001824c = DAT_6001824c + 1;
    pvVar1 = FUN_60009080(param_1,param_2,param_3,0,0);
    *(void **)(&DAT_6007c800 + DAT_6001824c * 8) = pvVar1;
    FUN_6000a130();
    if (*(int *)(&DAT_6007c800 + DAT_6001824c * 8) != 0) {
      return DAT_6001824c + 8;
    }
  }
  return 0;
}



/* VA 60001910 */

undefined4 _THRASH_destroywindow_4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;

                    /* 0x1910  5  _THRASH_destroywindow@4 */
  if (((param_1 < 0xffff) && (*(int *)(&DAT_6007c7c0 + param_1 * 8) != 0)) && (8 < param_1)) {
    piVar1 = *(int **)(&DAT_6007c7c4 + param_1 * 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(int *)(&DAT_6007c7c4 + param_1 * 8) = 0;
    }
    uVar2 = _THRASH_tfree_4(*(int *)(&DAT_6007c7c0 + param_1 * 8));
    return uVar2;
  }
  return 0;
}



/* VA 60001960 */

undefined4 _THRASH_getwindowtexture_4(int param_1)

{
                    /* 0x1960  25  _THRASH_getwindowtexture@4 */
  if (param_1 < 0xffff) {
    return *(undefined4 *)(&DAT_6007c7c0 + param_1 * 8);
  }
  return 0;
}



/* VA 60001980 */

void FUN_60001980(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;

  iVar3 = 0;
  iVar2 = DAT_6001824c;
  if (-1 < DAT_6001824c + 8) {
    do {
      piVar1 = *(int **)(&DAT_6007c804 + iVar2 * 8);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        iVar2 = DAT_6001824c;
        *(undefined4 *)(&DAT_6007c804 + DAT_6001824c * 8) = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar2 + 8);
  }
  DAT_6001824c = 0;
  return;
}



/* VA 600019d0 */

void _THRASH_drawtri_12(float *param_1,float *param_2,float *param_3)

{
                    /* 0x19d0  17  _THRASH_drawtri@12 */
  if ((DAT_60058e1c == 1) ||
     (((uint)((*param_2 - *param_1) * (param_3[1] - param_1[1]) -
             (*param_3 - *param_1) * (param_2[1] - param_1[1])) & 0x80000000) != DAT_60058e1c)) {
    FUN_60006fe0(param_1,param_2,param_3);
  }
  return;
}



/* VA 60001a30 */

void _THRASH_drawtrimesh_12(int param_1,int param_2,ushort *param_3)

{
                    /* 0x1a30  20  _THRASH_drawtrimesh@12 */
  FUN_600072a0(param_2,param_3,param_1);
  return;
}



/* VA 60001a50 */

void _THRASH_drawtristrip_12(int param_1,int param_2,ushort *param_3)

{
                    /* 0x1a50  21  _THRASH_drawtristrip@12 */
  FUN_60007e60(param_2,param_1 + 2,param_1,param_3);
  return;
}



/* VA 60001a70 */

void _THRASH_drawtrifan_12(int param_1,float *param_2,int param_3)

{
                    /* 0x1a70  18  _THRASH_drawtrifan@12 */
  FUN_60008270(param_2,param_1 + 2,param_1,param_3);
  return;
}



/* VA 60001a90 */

void _THRASH_drawquad_16(float *param_1,float *param_2,float *param_3,undefined4 *param_4)

{
                    /* 0x1a90  13  _THRASH_drawquad@16 */
  if ((DAT_60058e1c == 1) ||
     (((uint)((*param_2 - *param_1) * (param_3[1] - param_1[1]) -
             (*param_3 - *param_1) * (param_2[1] - param_1[1])) & 0x80000000) != DAT_60058e1c)) {
    FUN_60007af0(param_1,param_2,param_3,param_4);
  }
  return;
}



/* VA 60001af0 */

void _THRASH_drawquadmesh_12(int param_1,int param_2,ushort *param_3)

{
                    /* 0x1af0  14  _THRASH_drawquadmesh@12 */
  FUN_60007650(param_2,param_3,param_1);
  return;
}



/* VA 60001b10 */

void _THRASH_drawline_8(undefined4 *param_1,undefined4 *param_2)

{
                    /* 0x1b10  6  _THRASH_drawline@8 */
  FUN_600082f0(param_1,param_2);
  return;
}



/* VA 60001b30 */

void _THRASH_drawlinemesh_12(int param_1,int param_2,ushort *param_3)

{
                    /* 0x1b30  7  _THRASH_drawlinemesh@12 */
  FUN_600084e0(param_2,param_3,param_1);
  return;
}



/* VA 60001b50 */

void _THRASH_drawlinestrip_12(int param_1,int param_2,int param_3)

{
  int iVar1;

                    /* 0x1b50  8  _THRASH_drawlinestrip@12 */
  iVar1 = 0;
  if (0 < param_1) {
    do {
      _THRASH_drawline_8((undefined4 *)(*(int *)(param_3 + iVar1 * 4) * 0x20 + param_2),
                         (undefined4 *)(*(int *)(param_3 + 4 + iVar1 * 4) * 0x20 + param_2));
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1);
  }
  return;
}



/* VA 60001b90 */

void _THRASH_drawpoint_4(float *param_1)

{
                    /* 0x1b90  10  _THRASH_drawpoint@4 */
  FUN_60008730(param_1,1);
  return;
}



/* VA 60001bb0 */

void _THRASH_drawpointmesh_12(int param_1,int param_2,ushort *param_3)

{
                    /* 0x1bb0  11  _THRASH_drawpointmesh@12 */
  if (0 < param_1) {
    do {
      _THRASH_drawpoint_4((float *)((uint)*param_3 * 0x20 + param_2));
      param_3 = (ushort *)((int)param_3 + DAT_60017130);
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60001bf0 */

void _THRASH_drawsprite_8(float *param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float local_40 [6];
  float local_28;
  float local_20 [7];
  float local_4;

  pfVar2 = param_2;
  pfVar3 = local_40;
                    /* 0x1bf0  15  _THRASH_drawsprite@8 */
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar2 = param_2;
  pfVar3 = local_20;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_20[1] = param_1[1];
  local_4 = param_1[7];
  local_40[0] = *param_1;
  local_28 = param_1[6];
  _THRASH_drawquad_16(param_1,local_20,param_2,local_40);
  return;
}



/* VA 60001c50 */

void _THRASH_drawspritemesh_12(int param_1,int param_2,ushort *param_3)

{
                    /* 0x1c50  16  _THRASH_drawspritemesh@12 */
  if (0 < param_1) {
    do {
      _THRASH_drawsprite_8
                ((float *)((uint)*param_3 * DAT_6001712c + param_2),
                 (float *)((uint)*(ushort *)(DAT_60017130 + (int)param_3) * DAT_6001712c + param_2))
      ;
      param_3 = (ushort *)((int)param_3 + DAT_60017130);
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60001ca0 */

void _THRASH_drawtristrip_8(int param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;

  pfVar1 = param_2;
  while( true ) {
    if (param_1 < 1) {
      return;
    }
    pfVar2 = pfVar1 + 0x10;
    _THRASH_drawtri_12(param_2,pfVar1 + 8,pfVar2);
    if (param_1 < 2) break;
    _THRASH_drawtri_12(pfVar1 + 8,pfVar1 + 0x18,pfVar2);
    param_1 = param_1 + -2;
    param_2 = param_2 + 0x10;
    pfVar1 = pfVar2;
  }
  return;
}



/* VA 60001cf0 */

void _THRASH_drawtrifan_8(int param_1,float *param_2)

{
  float *pfVar1;

                    /* 0x1cf0  19  _THRASH_drawtrifan@8 */
  pfVar1 = param_2 + 8;
  for (; 0 < param_1; param_1 = param_1 + -1) {
    _THRASH_drawtri_12(param_2,pfVar1,pfVar1 + 8);
    pfVar1 = pfVar1 + 8;
  }
  return;
}



/* VA 60001d20 */

void _THRASH_drawlinestrip_8(int param_1,undefined4 *param_2)

{
  for (; 0 < param_1; param_1 = param_1 + -1) {
    _THRASH_drawline_8(param_2,param_2 + 8);
    param_2 = param_2 + 8;
  }
  return;
}



/* VA 60001d50 */

void _THRASH_drawpointstrip_8(int param_1,float *param_2)

{
                    /* 0x1d50  12  _THRASH_drawpointstrip@8 */
  if (0 < param_1) {
    do {
      _THRASH_drawpoint_4(param_2);
      param_2 = param_2 + 8;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60001d80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _THRASH_getstate_4(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;

                    /* 0x1d80  24  _THRASH_getstate@4 */
  uVar1 = DAT_60017080 & param_1;
  iVar3 = 0;
  if ((int)uVar1 < 0x40001) {
    if (uVar1 == 0x40000) {
      iVar3 = 4;
    }
    else if ((int)uVar1 < 0x20001) {
      if (uVar1 == 0x20000) {
        iVar3 = 2;
      }
      else if (uVar1 == 0) {
        iVar3 = 0;
      }
      else if (uVar1 == 0x10000) {
        iVar3 = 1;
      }
    }
    else if (uVar1 == 0x30000) {
      iVar3 = 3;
    }
  }
  else if (uVar1 == 0x50000) {
    iVar3 = 5;
  }
  else if (uVar1 == 0x60000) {
    iVar3 = 6;
  }
  else if (uVar1 == 0x70000) {
    iVar3 = 7;
  }
  iVar2 = FUN_60001e20(param_1 & _DAT_60017084);
  if (-1 < iVar2) {
    iVar2 = *(int *)(&DAT_6007b8a0 + (iVar3 + iVar2 * 8) * 4);
  }
  return iVar2;
}



/* VA 60001e20 */

int __cdecl FUN_60001e20(int param_1)

{
  uint uVar1;
  int iVar2;

  iVar2 = 0;
  uVar1 = 0;
  while ((param_1 < (int)(&DAT_60017088)[uVar1 * 2] || ((int)(&DAT_6001708c)[uVar1 * 2] < param_1)))
  {
    iVar2 = iVar2 + ((&DAT_6001708c)[uVar1 * 2] - (&DAT_60017088)[uVar1 * 2]);
    uVar1 = uVar1 + 1;
    if (5 < uVar1) {
      return -1;
    }
  }
  return (iVar2 - (&DAT_60017088)[uVar1 * 2]) + param_1;
}



/* VA 60001e70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60001e70(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;

  uVar1 = DAT_60017080 & param_1;
  iVar3 = 0;
  if ((int)uVar1 < 0x40001) {
    if (uVar1 == 0x40000) {
      iVar3 = 4;
    }
    else if ((int)uVar1 < 0x20001) {
      if (uVar1 == 0x20000) {
        iVar3 = 2;
      }
      else if (uVar1 == 0) {
        iVar3 = 0;
      }
      else if (uVar1 == 0x10000) {
        iVar3 = 1;
      }
    }
    else if (uVar1 == 0x30000) {
      iVar3 = 3;
    }
  }
  else if (uVar1 == 0x50000) {
    iVar3 = 5;
  }
  else if (uVar1 == 0x60000) {
    iVar3 = 6;
  }
  else if (uVar1 == 0x70000) {
    iVar3 = 7;
  }
  uVar1 = param_1 & _DAT_60017084;
  iVar2 = FUN_60001e20(uVar1);
  if (-1 < iVar2) {
    *(undefined4 *)(&DAT_6007b8a0 + (iVar3 + iVar2 * 8) * 4) = param_2;
  }
  if (DAT_60058e10 != (code *)0x0) {
    (*DAT_60058e10)(uVar1,param_2);
  }
  return;
}



/* VA 60001f20 */

void FUN_60001f20(void)

{
  FUN_6000bad0((undefined8 *)&DAT_6007b8a0,0,0xf00);
  return;
}



/* VA 60001f40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_60001f40(void)

{
  undefined4 uVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  char *_Dest;
  int *unaff_ESI;
  int iVar5;
  undefined4 *puVar6;
  int *local_460;
  int *local_45c;
  undefined4 local_458 [7];
  undefined4 auStack_43c [131];
  char acStack_230 [560];

  iVar5 = 0;
  local_460 = (int *)0x0;
  DAT_600186e0 = 0;
  _DAT_600186e4 = 0;
  DAT_600186d8 = 0;
  DAT_600186e0 = FUN_6000bb10(local_458,(undefined4 *)0x0,&DAT_600150b0);
  iVar4 = 0;
  if (0 < DAT_600186e0) {
    _Dest = &DAT_60018340;
    do {
      bVar2 = FUN_6000bd60(iVar4);
      if (CONCAT31(extraout_var,bVar2) != 0) {
        uVar1 = local_458[iVar4];
        (&DAT_60018250)[iVar5] = uVar1;
        DirectDrawCreate(uVar1,&local_460,0);
        (**(code **)*local_460)(local_460,&DAT_60015c38,&local_45c);
        puVar6 = auStack_43c;
        for (iVar3 = 0x10c; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        (**(code **)(*unaff_ESI + 0x6c))(unaff_ESI,auStack_43c,1);
        strncpy(_Dest,acStack_230,0x50);
        if (local_460 != (int *)0x0) {
          (**(code **)(*local_460 + 8))(local_460);
          local_460 = (int *)0x0;
        }
        if (local_45c != (int *)0x0) {
          (**(code **)(*local_45c + 8))(local_45c);
          local_45c = (int *)0x0;
        }
        iVar5 = iVar5 + 1;
        _Dest = _Dest + 0x50;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_600186e0);
  }
  DAT_600186d8 = DAT_60018250;
  DAT_600186e0 = iVar5;
  return iVar5;
}



/* VA 60002060 */

void FUN_60002060(void)

{
  char *_Str;
  int iVar1;

  if ((DAT_600170bc < 0) && ((DAT_6007b864 != 0 || (DAT_6007b880 != 0)))) {
    _Str = getenv("THRASH_DISPLAY");
    iVar1 = 0;
    if (_Str != (char *)0x0) {
      iVar1 = atoi(_Str);
    }
    _THRASH_selectdisplay_4(iVar1);
  }
  return;
}



/* VA 600020c0 */

undefined4 _THRASH_selectdisplay_4(int param_1)

{
  char cVar1;
  char *pcVar2;
  DWORD DVar3;
  DWORD DVar4;
  int iVar5;

                    /* 0x20c0  33  _THRASH_selectdisplay@4 */
  DAT_600186d8 = 0;
  if (DAT_600186a0 != 0) {
    _THRASH_restore_0();
  }
  if ((param_1 < 0) || (DAT_600186e0 <= param_1)) {
    DAT_600186d8 = DAT_60018250;
    DAT_600170bc = 0;
    FUN_6000bad0((undefined8 *)&DAT_600fc840,0,0x50);
    DAT_600fc890._0_1_ = 10;
    iVar5 = 0;
    do {
      pcVar2 = &DAT_60018340 + iVar5;
      (&DAT_600fc840)[iVar5] = *pcVar2;
      iVar5 = iVar5 + 1;
    } while (*pcVar2 != '\0');
  }
  else {
    DAT_600186d8 = (&DAT_60018250)[param_1];
    DAT_600170bc = param_1;
    FUN_6000bad0((undefined8 *)&DAT_600fc840,0,0x50);
    pcVar2 = &DAT_60018340 + param_1 * 0x50;
    DAT_600fc890._0_1_ = 10;
    iVar5 = (int)&DAT_600fc840 - (int)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[iVar5] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_6007b868 != (code *)0x0) {
    (*DAT_6007b868)(0x464,&LAB_600021f0);
    (*DAT_6007b868)(0x468,&LAB_60002d00);
    (*DAT_6007b868)(0x465,FUN_60002850);
    if (DAT_6007b868 != (code *)0x0) {
      DVar3 = GetWindowThreadProcessId(DAT_60058df0,(LPDWORD)0x0);
      DVar4 = GetCurrentThreadId();
      if (DVar4 != DVar3) {
        FUN_600034c0();
        return 1;
      }
    }
  }
  FUN_600030b0();
  return 1;
}



/* VA 60002578 */

void FUN_60002578(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_c;

  local_c = (int *)0x0;
  (**(code **)*DAT_600186a0)(DAT_600186a0,&DAT_60015bf8,&local_c);
  (**(code **)(*local_c + 0xc))(local_c,&LAB_60002e90,0);
  (**(code **)(*local_c + 8))(local_c);
  puVar2 = DAT_600fc800;
  for (iVar1 = 1000; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_600fc7fc = 0;
  (**(code **)(*DAT_600186a0 + 0x20))(DAT_600186a0,0,0,0,FUN_600025ec);
  DAT_600fc7fc = DAT_600fc7fc + 1;
  return;
}



/* VA 600025ec */

undefined4 FUN_600025ec(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;

  iVar1 = FUN_60003960(param_1 + 0x48);
  if (iVar1 != 0) {
    uVar2 = *(uint *)(param_1 + 0x54);
    if ((0x27f < *(uint *)(param_1 + 0xc)) && (0x1df < *(uint *)(param_1 + 8))) {
      if (uVar2 == 0x10) {
        uVar3 = 0x400;
      }
      else {
        if (uVar2 != 0x20) {
          return 1;
        }
        uVar3 = 0x100;
      }
      if ((DAT_6005aaec & uVar3) != 0) {
        if (iVar1 == 3) {
          uVar2 = 0xf;
        }
        uVar3 = uVar2 >> 3;
        if (uVar2 < 0x10) {
          uVar3 = 2;
        }
        FUN_600026d4(uVar2,DAT_60018690 %
                           (uVar3 * *(uint *)(param_1 + 0xc) * *(uint *)(param_1 + 8)));
      }
    }
  }
  return 1;
}



/* VA 600026d4 */

undefined8 __fastcall FUN_600026d4(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint *in_EAX;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  bool bVar12;

  uVar1 = DAT_600fc7fc;
  uVar6 = 0;
  uVar2 = DAT_600fc7fc;
  while (uVar5 = uVar2, uVar2 = uVar5, uVar6 < uVar5) {
    uVar2 = (uVar5 - uVar6 >> 1) + uVar6;
    bVar11 = 0x9ffe8d87 < uVar2 * 0x28;
    bVar12 = (uint *)(&DAT_60017278 + uVar2 * 0x28) == (uint *)0x0;
    iVar4 = 3;
    puVar7 = in_EAX;
    puVar9 = (uint *)(&DAT_60017278 + uVar2 * 0x28);
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar11 = *puVar7 < *puVar9;
      bVar12 = *puVar7 == *puVar9;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    } while (bVar12);
    if (bVar12) goto LAB_6000274b;
    if (!bVar11) {
      uVar6 = uVar2 + 1;
      uVar2 = uVar5;
    }
  }
  if (DAT_600fc7fc < 99) {
    DAT_600fc7fc = DAT_600fc7fc + 1;
    if (uVar1 != uVar5) {
      puVar8 = (undefined4 *)(&DAT_60017274 + uVar1 * 0x28);
      puVar10 = (undefined4 *)(&DAT_6001729c + uVar1 * 0x28);
      for (iVar4 = (uVar1 - uVar5) * 10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + -1;
        puVar10 = puVar10 + -1;
      }
      for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + -1;
      }
    }
LAB_6000274b:
    puVar7 = (uint *)(&DAT_60017278 + uVar2 * 0x28);
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar7 = puVar7 + 1;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}



/* VA 60002850 */

undefined4 FUN_60002850(undefined4 param_1,HWND param_2,undefined4 param_3,int param_4,int param_5)

{
  HDC hdc;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 *puVar5;
  uint local_94;
  undefined8 uStack_8c;
  uint uStack_84;
  uint local_80;
  uint local_7c [22];
  uint uStack_24;
  undefined4 local_14;
  uint *puStack_4;

  puVar4 = (uint *)(DAT_600fc800 + param_4 * 0x28);
  local_94 = puVar4[2];
  uVar3 = param_5 - 1;
  local_80 = uVar3;
  FUN_60009500();
  FUN_60003610();
  if ((DAT_60018688 == 0) || (DAT_60018860 == 0)) {
    DAT_6005aac0 = *puVar4;
    DAT_6005a934 = puVar4[1];
  }
  else {
    hdc = GetDC(param_2);
    DAT_6005aac0 = GetDeviceCaps(hdc,8);
    DAT_6005a934 = GetDeviceCaps(hdc,10);
    ReleaseDC(param_2,hdc);
    uVar3 = local_80;
  }
  if (local_94 == 0xf) {
    local_94 = 0x10;
  }
  DAT_60018680 = 0;
  if (DAT_60018688 == 0) {
    DAT_60018680 = (**(code **)(*DAT_600186a0 + 0x54))(DAT_600186a0,*puVar4,puVar4[1],local_94,0,0);
    if (DAT_60018680 != 0) goto LAB_60002c93;
    puVar5 = &uStack_8c;
    for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined4 *)puVar5 = 0;
      puVar5 = (undefined8 *)((int)puVar5 + 4);
    }
    uStack_8c._0_4_ = 0x7c;
    if (uVar3 == 0) {
      uStack_24 = 0x2200;
      DAT_60058d90 = 0;
      DAT_60058d88 = 0;
      DAT_600186b4 = (int *)0x0;
    }
    else {
      uStack_8c._4_4_ = 0x21;
      uStack_24 = 0x2218;
      local_7c[1] = uVar3;
    }
    if (DAT_6005aae0 == 0) {
      uStack_24 = uStack_24 | 0x800;
    }
    else {
      uStack_24 = uStack_24 | 0x4000;
    }
    DAT_60018680 = (**(code **)(*DAT_600186a0 + 0x18))(DAT_600186a0,&uStack_8c,&DAT_600186a4,0);
    while ((DAT_60018680 == 0x8876017c && (1 < local_7c[1]))) {
      local_7c[1] = local_7c[1] - 1;
      uVar3 = uVar3 - 1;
      DAT_60018680 = (**(code **)(*DAT_600186a0 + 0x18))(DAT_600186a0,&uStack_8c,&DAT_600186a4,0);
    }
    if (DAT_600186a4 != (int *)0x0) {
      if ((DAT_600186a8 == (undefined4 *)0x0) && (uVar3 != 0)) {
        DAT_60018680 = (**(code **)(*DAT_600186a4 + 0x30))
                                 (DAT_600186a4,&stack0xffffff60,&DAT_600186a8);
      }
      if (DAT_600186a4 != (int *)0x0) {
        DAT_60018680 = (**(code **)*DAT_600186a4)(DAT_600186a4,&DAT_60015c28,&DAT_600186b0);
      }
    }
    if (DAT_600186a8 != (undefined4 *)0x0) {
      DAT_60018680 = (**(code **)*DAT_600186a8)(DAT_600186a8,&DAT_60015c28,&DAT_600186b4);
    }
    if (DAT_600186b4 == (int *)0x0) goto LAB_60002c93;
  }
  else {
    puVar4 = local_7c;
    for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    local_7c[0] = 0x7c;
    local_7c[1] = 1;
    local_14 = 0x200;
    DAT_60018680 = (**(code **)(*DAT_600186a0 + 0x18))(DAT_600186a0,local_7c,&DAT_600186a4);
    if (DAT_60018680 != 0) {
      if ((DAT_60018680 != 0x8007000e) && (DAT_60018680 != 0x8876017c)) {
        FUN_60003a20(DAT_60018680);
        FUN_6000b9e0("CreateSurface for window front buffer failed %s.\n");
      }
      goto LAB_60002c93;
    }
    uVar1 = 0;
    if (DAT_60018688 != 0) {
      DAT_60018680 = (**(code **)(*DAT_600186a0 + 0x10))(DAT_600186a0,0,&DAT_60018698,0);
      DAT_60018680 = (**(code **)(*DAT_600186a4 + 0x70))(DAT_600186a4,DAT_60018698);
      uVar1 = (**(code **)(*DAT_60018698 + 0x20))(DAT_60018698,0,DAT_6007b880);
    }
    DAT_60018680 = uVar1;
    if (DAT_600186a4 != (int *)0x0) {
      DAT_60018680 = (**(code **)*DAT_600186a4)(DAT_600186a4,&DAT_60015c28,&DAT_600186b0);
    }
    uStack_24 = (-(uint)(DAT_60058d70 != 0) & 0xffffc800) + 0x6040;
    local_80 = DAT_6005aac0;
    uStack_8c._4_4_ = 7;
    uStack_84 = DAT_6005a934;
    DAT_60018680 = (**(code **)(*DAT_600186a0 + 0x18))(DAT_600186a0,&uStack_8c,&DAT_600186a8,0);
    if (DAT_60018680 != 0) {
      if ((DAT_60018680 == 0x8007000e) || (DAT_60018680 == 0x8876017c)) {
        FUN_6000b9e0(
                    "There was not enough video memory to create the rendering surface.\nTo run this program in a window of this size, please adjust your display settings for a smaller desktop area or a lower palette size and restart the program.\n"
                    );
      }
      else {
        FUN_60003a20(DAT_60018680);
        FUN_6000b9e0("CreateSurface for window back buffer failed %s.\n");
      }
      goto LAB_60002c93;
    }
    DAT_60018680 = (**(code **)*DAT_600186a8)(DAT_600186a8,&DAT_60015c28,&DAT_600186b4);
  }
  FUN_6000bad0(&uStack_8c,0,0x7c);
  uStack_8c._0_4_ = 0x7c;
  DAT_60018680 = (**(code **)(*DAT_600186b4 + 0x58))(DAT_600186b4,&uStack_8c);
  DAT_6005aafc = uStack_24 >> 0xe & 1;
LAB_60002c93:
  FUN_60009680();
  iVar2 = (**(code **)(*DAT_6001869c + 0xc))(DAT_6001869c,0,&DAT_6007b240);
  if ((iVar2 != 0) && (DAT_6001869c != (int *)0x0)) {
    (**(code **)(*DAT_6001869c + 8))(DAT_6001869c);
    DAT_6001869c = (int *)0x0;
  }
  if (puStack_4 != (uint *)0x0) {
    SetEvent(DAT_600186d4);
    *puStack_4 = DAT_60018680;
  }
  return 1;
}



/* VA 60002eb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_60002eb0(void)

{
  bool bVar1;
  HWND hWnd;
  HDC hdc;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *unaff_EBP;
  uint unaff_EDI;
  undefined4 *puVar5;
  int *piStack_320;
  int **ppiStack_31c;
  undefined4 uStack_318;
  int *local_300 [91];
  undefined4 auStack_194 [101];

  uStack_318 = 0;
  ppiStack_31c = local_300;
  piStack_320 = DAT_600186d8;
  DAT_60018680 = DirectDrawCreate();
  uStack_318 = DAT_60018684;
  ppiStack_31c = (int **)DAT_6007b880;
  piStack_320 = local_300[0];
  DAT_60018680 = (**(code **)(*local_300[0] + 0x50))();
  DAT_60018680 = (**(code **)*unaff_EBP)();
  puVar5 = (undefined4 *)&stack0xfffffcf0;
  for (iVar4 = 0x5f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = auStack_194;
  for (iVar4 = 0x5f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  auStack_194[0] = 0x17c;
  (**(code **)((int)*ppiStack_31c + 0x2c))(ppiStack_31c,&stack0xfffffcf0,auStack_194);
  if ((unaff_EDI & 0x80000) == 0) {
    DAT_60018688 = 0;
  }
  hWnd = GetDesktopWindow();
  hdc = GetWindowDC(hWnd);
  iVar4 = GetDeviceCaps(hdc,0xc);
  ReleaseDC(hWnd,hdc);
  if (iVar4 < 9) {
    DAT_60018688 = 0;
  }
  if (iVar4 == 0x18) {
    DAT_60018688 = 0;
  }
  else if (iVar4 == 0x20) {
    piStack_320 = (int *)0x0;
    bVar1 = false;
    uVar2 = (*pcRam0000017c)(&stack0xfffffcf0,&DAT_60015c08,&piStack_320);
    if (uVar2 != 0) {
      DAT_60058e28 = "dx7\\dx7init.c";
      DAT_60058e24 = 0x57a;
      FUN_60003a20(uVar2);
      FUN_6000ba10("SetDesktopMode Test failed! %s\n");
    }
    uVar2 = (**(code **)(*unaff_EBP + 0x28))(unaff_EBP,&DAT_60015bc8,&LAB_60003080,0);
    if (uVar2 != 0) {
      DAT_60058e28 = "dx7\\dx7init.c";
      DAT_60058e24 = 0x580;
      FUN_60003a20(uVar2);
      FUN_6000ba10("DX7_SetDesktopModeIfNotWin: %s\n");
    }
    piVar3 = &DAT_6007b840;
    do {
      if (*piVar3 == 0x20) {
        bVar1 = true;
      }
      piVar3 = piVar3 + 1;
    } while ((int)piVar3 < 0x6007b858);
    if (!bVar1) {
      DAT_60018688 = 0;
    }
    if (piStack_320 != (int *)0x0) {
      (**(code **)(*piStack_320 + 8))(piStack_320);
    }
  }
  (**(code **)(_DAT_60015c38 + 8))(&DAT_60015c38);
  return;
}



/* VA 600030b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_600030b0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  int *piStack_814;
  undefined4 *puStack_810;
  undefined4 uStack_80c;
  int *piStack_808;
  undefined1 *puStack_804;
  undefined4 *puStack_800;
  undefined1 *puStack_7ec;
  undefined4 uStack_7e8;
  undefined1 auStack_7c0 [4];
  int iStack_7bc;
  int aiStack_7b4 [3];
  int *local_7a8;
  uint uStack_790;
  undefined4 auStack_788 [15];
  undefined4 uStack_74c;
  undefined4 auStack_60c [106];
  undefined4 auStack_464 [255];
  int iStack_68;
  uint uStack_64;

  if (DAT_6007b880 != 0) {
    DAT_60018684 = (int *)((uint)DAT_60018684 & 0xffffffee | 0x408);
    FUN_60002eb0();
    if (DAT_60018688 == 0) {
      DAT_60018684 = (int *)((uint)DAT_60018684 | 0x411);
    }
    else {
      DAT_60018684 = (int *)((uint)DAT_60018684 | 0x408);
    }
    DAT_60018680 = DirectDrawCreate();
    if (DAT_60018680 == 0) {
      DAT_60018680 = DirectDrawCreateEx();
      (**(code **)(*local_7a8 + 8))();
      piVar7 = DAT_60018684;
      aiStack_7b4[2] = 0;
      if (DAT_60018680 == 0) {
        DAT_60018680 = (**(code **)(*DAT_600186a0 + 0x50))();
        if (DAT_60018680 == 0) {
          piVar4 = aiStack_7b4;
          for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
            *piVar4 = 0;
            piVar4 = piVar4 + 1;
          }
          uStack_7e8 = 0;
          puStack_7ec = auStack_7c0;
          aiStack_7b4[0] = 0x7c;
          aiStack_7b4[1] = 1;
          uStack_74c = 0x200;
          DAT_60018680 = (**(code **)(*DAT_600186a0 + 0x18))();
          if (DAT_60018680 == 0) {
            puStack_800 = (undefined4 *)0x600031e3;
            (**(code **)(*piVar7 + 0x58))();
            iVar2 = iStack_7bc;
            iVar3 = aiStack_7b4[0];
          }
          else {
            puStack_800 = (undefined4 *)0x600031cf;
            FUN_6000b9e0("*** FAILURE in creating primary surface (error code: %8x)***\n");
            iVar2 = 0;
            iVar3 = 0;
          }
          (**(code **)(*piVar7 + 8))();
          puStack_800 = &uStack_7e8;
          puStack_804 = &stack0xfffff81c;
          piStack_808 = DAT_600186a0;
          uStack_80c = 0x6000322d;
          iVar1 = (**(code **)(*DAT_600186a0 + 0x5c))();
          if (iVar1 < 0) {
            DAT_60018690 = (int *)0x200000;
            DAT_600fc830 = (int *)0x0;
            _DAT_600fc834 = 0;
          }
          else {
            DAT_60018690 = piVar7;
            DAT_600fc830 = piVar7;
            _DAT_600fc834 = 3;
          }
          uStack_80c = 0;
          puVar5 = auStack_464;
          for (iVar1 = 0x10c; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          puStack_810 = auStack_464;
          piStack_814 = DAT_600186a0;
          (**(code **)(*DAT_600186a0 + 0x6c))();
          uVar6 = iStack_68 << 0x10 ^ uStack_64;
          puStack_800 = (undefined4 *)0x10004000;
          piVar7 = DAT_600186a0;
          (**(code **)(*DAT_600186a0 + 0x5c))(DAT_600186a0,&puStack_800,&puStack_804,&puStack_7ec);
          if ((uVar6 == 0x121a0001) || (uVar6 == 0x121a0002)) {
            iVar2 = -(int)DAT_60018690;
          }
          else {
            iVar2 = iVar2 * iVar3;
          }
          DAT_60018690 = (int *)(iVar2 + (int)piStack_814);
          uStack_80c = 0;
          piStack_808 = (int *)0x0;
          puStack_804 = (undefined1 *)0x0;
          puStack_810 = (undefined4 *)0x20005000;
          iVar2 = (**(code **)(*DAT_600186a0 + 0x5c))
                            (DAT_600186a0,&puStack_810,&piStack_814,&stack0xfffff804);
          if ((iVar2 == 0) && (piVar7 != (int *)0x0)) {
            _DAT_600fc834 = _DAT_600fc834 | 0x8000;
          }
          auStack_788[0] = 0x17c;
          auStack_60c[0] = 0x17c;
          puStack_804 = (undefined1 *)0x7c;
          iVar2 = (**(code **)(*DAT_600186a0 + 0x2c))(DAT_600186a0,auStack_788,auStack_60c);
          if (iVar2 == 0) {
            DAT_6005aae0 = uStack_790 & 1;
          }
          FUN_60002578();
          return 1;
        }
      }
    }
  }
  return 0;
}



/* VA 600034c0 */

undefined4 FUN_600034c0(void)

{
  if (DAT_600186d4 == (HANDLE)0x0) {
    DAT_600186d4 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  }
  DAT_6007b880 = (HWND)(*DAT_6007b864)();
  if (DAT_6007b880 != (HWND)0x0) {
    DAT_60018684 = DAT_60018684 & 0xffffffee | 0x408;
    FUN_60002eb0();
    if (DAT_60018688 == 0) {
      DAT_60018684 = DAT_60018684 | 0x411;
    }
    else {
      DAT_60018684 = DAT_60018684 | 0x408;
    }
    SetForegroundWindow(DAT_6007b880);
    PostMessageA(DAT_6007b880,0x464,0,0);
    WaitForSingleObject(DAT_600186d4,0xffffffff);
    return DAT_60018680;
  }
  DAT_60018680 = 0x578;
  return 0x578;
}



/* VA 60003570 */

undefined4 FUN_60003570(void)

{
  if (DAT_600186a0 != 0) {
    SetForegroundWindow(DAT_6007b880);
    PostMessageA(DAT_6007b880,0x468,0,0);
    WaitForSingleObject(DAT_600186d4,0xffffffff);
    CloseHandle(DAT_600186d4);
    DAT_600186d4 = (HANDLE)0x0;
    DAT_6007b880 = (HWND)0x0;
    return DAT_60018680;
  }
  return 0;
}



/* VA 600035e0 */

undefined4 FUN_600035e0(void)

{
  FUN_60003610();
  if (DAT_600186a0 != (int *)0x0) {
    (**(code **)(*DAT_600186a0 + 8))(DAT_600186a0);
    DAT_600186a0 = (int *)0x0;
  }
  return 1;
}



/* VA 60003610 */

void FUN_60003610(void)

{
  int *piVar1;
  undefined4 *puVar2;

  puVar2 = &DAT_600186cc;
  do {
    piVar1 = (int *)puVar2[-1];
    puVar2 = puVar2 + -1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *puVar2 = 0;
    }
  } while (puVar2 != (undefined4 *)&DAT_600186ac);
  if (DAT_600186a8 != (int *)0x0) {
    (**(code **)(*DAT_600186a8 + 8))(DAT_600186a8);
    DAT_600186a8 = (int *)0x0;
  }
  if (DAT_600186a4 != (int *)0x0) {
    (**(code **)(*DAT_600186a4 + 8))(DAT_600186a4);
    DAT_600186a4 = (int *)0x0;
  }
  return;
}



/* VA 60003670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _THRASH_init_0(void)

{
                    /* 0x3670  27  _THRASH_init@0 */
  DAT_600170b8 = 0;
  FUN_60001f40();
  FUN_60001f20();
  _DAT_60018694 = 1;
  FUN_6000d4ec((_onexit_t)&LAB_600036b0);
  return DAT_600186e0;
}



/* VA 600036c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _THRASH_restore_0(void)

{
  DWORD DVar1;
  DWORD DVar2;

                    /* 0x36c0  32  _THRASH_restore@0 */
  if (DAT_600170b8 == 0) {
    DAT_600170b8 = 1;
    if (DAT_60018230 != 0) {
      _THRASH_unlockwindow_4();
    }
    FUN_60009500();
    _DAT_600170c0 = 0xffffffff;
    DAT_600170bc = 0xffffffff;
    if (DAT_6007b868 != 0) {
      DVar1 = GetWindowThreadProcessId(DAT_60058df0,(LPDWORD)0x0);
      DVar2 = GetCurrentThreadId();
      if (DVar2 != DVar1) {
        FUN_60003570();
        PTR_FUN_6001713c = (undefined *)0x0;
        return 1;
      }
    }
    FUN_600035e0();
    PTR_FUN_6001713c = (undefined *)0x0;
  }
  return 1;
}



/* VA 60003750 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool _THRASH_setvideomode_12(WPARAM param_1,int param_2,uint param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  undefined *puVar4;
  bool bVar5;
  undefined4 local_7c [31];

                    /* 0x3750  36  _THRASH_setvideomode@12 */
  DAT_60058d7c = param_3;
  if (param_3 == 1) {
    DAT_60058d7c = 0x10;
  }
  else if (param_3 == 2) {
    DAT_60058d7c = 0x20;
  }
  if (DAT_6001822c != 0) {
    FUN_6000b9e0("D3D Setting videomode in 3d scene !!!!\n");
  }
  FUN_60002060();
  if (*(uint *)(DAT_600fc800 + 8 + param_1 * 0x28) < DAT_60058d7c) {
    DAT_60058d7c = 0x10;
  }
  if (DAT_600186a0 == 0) {
    bVar5 = false;
    goto LAB_600038b4;
  }
  if (DAT_6007b868 == 0) {
LAB_6000382b:
    FUN_60002850(0,DAT_6007b880,0x465,param_1,param_2);
  }
  else {
    DVar1 = GetWindowThreadProcessId(DAT_60058df0,(LPDWORD)0x0);
    DVar2 = GetCurrentThreadId();
    if (DVar2 == DVar1) goto LAB_6000382b;
    SetForegroundWindow(DAT_6007b880);
    PostMessageA(DAT_6007b880,0x465,param_1,param_2);
    WaitForSingleObject(DAT_600186d4,0xffffffff);
  }
  if (DAT_60018680 == 0) {
    local_7c[0] = 0x7c;
    iVar3 = (**(code **)(*DAT_600186b0 + 0x58))(DAT_600186b0,local_7c);
    if (iVar3 < 0) {
      FUN_6000b9e0("DX7_setvideomode:  Error getting Surface Description %8x\n");
      bVar5 = DAT_60018680 == 0;
      goto LAB_600038b4;
    }
  }
  else {
    DAT_60058e28 = "dx7\\dx7init.c";
    DAT_60058e24 = 0x7e9;
    FUN_6000ba10("DX7_setdisplay - error\n");
  }
  bVar5 = DAT_60018680 == 0;
LAB_600038b4:
  FUN_6000b590(param_1,param_2,param_3,&DAT_600150b0);
  FUN_6000b2c0(0x3e,(undefined *)(DAT_60058df8 + 1));
  _DAT_6007c7a0 = 0;
  _DAT_6007c7a4 = 0;
  _DAT_6007c7a8 = 0;
  _DAT_6007c7ac = 0;
  _DAT_6007c7b0 = 0;
  _THRASH_window_4(1);
  puVar4 = _THRASH_lockwindow_0();
  _THRASH_unlockwindow_4();
  _THRASH_window_4(0);
  if (puVar4 != (undefined *)0x0) {
    _DAT_6007c7a4 = *(undefined4 *)(puVar4 + 4);
    _DAT_6007c7a8 = *(undefined4 *)(puVar4 + 8);
    _DAT_6007c7ac = *(undefined4 *)(puVar4 + 0xc);
    _DAT_6007c7b0 = *(undefined4 *)(puVar4 + 0x10);
    _DAT_6007c7a0 = 0;
    FUN_60001e70(0x1d,&DAT_6007c7a0);
  }
  _THRASH_treset_0();
  DAT_600170b8 = 0;
  return bVar5;
}



/* VA 60003960 */

undefined4 __cdecl FUN_60003960(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x10);
  iVar3 = *(int *)(param_1 + 0x14);
  iVar4 = *(int *)(param_1 + 0x18);
  if (iVar1 == 0x10) {
    if (iVar2 == 0x7c00) {
      if ((iVar3 == 0x3e0) && (iVar4 == 0x1f)) {
        return 3;
      }
    }
    else if (iVar2 == 0xf800) {
      if ((iVar3 == 0x7e0) && (iVar4 == 0x1f)) {
        return 4;
      }
    }
    else if (((iVar2 == 0xf00) && (iVar3 == 0xf0)) &&
            ((iVar4 == 0xf && (*(int *)(param_1 + 0x1c) == 0xf000)))) {
      return 7;
    }
  }
  else if (((iVar2 == 0xff0000) && (iVar3 == 0xff00)) && (iVar4 == 0xff)) {
    if (iVar1 == 0x18) {
      return 5;
    }
    if (iVar1 == 0x20) {
      return 6;
    }
  }
  return 0;
}



/* VA 60003a20 */

undefined * __cdecl FUN_60003a20(uint param_1)

{
  undefined *puVar1;

  puVar1 = FUN_6000b970(param_1);
  sprintf(&DAT_600186f0,"DX7 Error Code: %s (%8x)",puVar1,param_1);
  return &DAT_600186f0;
}



/* VA 60003a50 */

undefined4 _THRASH_is_0(void)

{
  HWND hWnd;
  HDC hdc;
  int iVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  int *local_184;
  int *local_180;
  undefined4 local_17c;
  byte bStack_178;

                    /* 0x3a50  28  _THRASH_is@0 */
  local_184 = (int *)0x0;
  local_180 = (int *)0x0;
  FUN_6000be00();
  hWnd = GetDesktopWindow();
  hdc = GetWindowDC(hWnd);
  iVar1 = GetDeviceCaps(hdc,0xc);
  if (iVar1 < 8) {
    ReleaseDC(hWnd,hdc);
    return 0;
  }
  ReleaseDC(hWnd,hdc);
  iVar1 = DirectDrawCreateEx(0,&local_184,&DAT_60015c38,0);
  if (-1 < iVar1) {
    puVar2 = &local_17c;
    for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    local_17c = 0x17c;
    iVar1 = (**(code **)(*local_184 + 0x2c))(local_184,&local_17c,0);
    if (((bStack_178 & 1) != 0) && (-1 < iVar1)) {
      ppiVar3 = &local_180;
      iVar1 = (**(code **)*local_184)(local_184,&DAT_60015bf8);
      (*(code *)(*ppiVar3)[2])(ppiVar3);
      if ((-1 < iVar1) && (local_180 != (int *)0x0)) {
        (**(code **)(*local_180 + 8))(local_180);
        return 0x55;
      }
    }
  }
  if (local_184 != (int *)0x0) {
    (**(code **)(*local_184 + 8))(local_184);
  }
  if (local_180 != (int *)0x0) {
    (**(code **)(*local_180 + 8))(local_180);
  }
  return 0;
}



/* VA 60003b60 */

undefined4 _THRASH_readrect_20(int param_1,int param_2,int param_3,int param_4,longlong *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  longlong *plVar5;
  longlong *plVar6;

                    /* 0x3b60  31  _THRASH_readrect@20 */
  plVar5 = param_5;
  piVar2 = (int *)FUN_60001650(1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  if (piVar2[2] == 6) {
    iVar3 = 4;
  }
  else {
    iVar3 = (piVar2[2] == 5) + 2;
  }
  iVar1 = piVar2[1];
  plVar6 = (longlong *)(iVar1 * param_2 + iVar3 * param_1 + *piVar2);
  if (param_4 != 0) {
    param_5 = (longlong *)param_4;
    do {
      FUN_6000c0c0(plVar5,plVar6,iVar3 * param_3);
      plVar6 = (longlong *)((int)plVar6 + iVar1);
      plVar5 = (longlong *)((int)plVar5 + iVar3 * param_3);
      param_5 = (longlong *)((int)param_5 + -1);
    } while (param_5 != (longlong *)0x0);
  }
  uVar4 = _THRASH_unlockwindow_4();
  return uVar4;
}



/* VA 60003c00 */

undefined4 _THRASH_writerect_20(int param_1,int param_2,int param_3,int param_4,longlong *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  longlong *plVar5;
  longlong *plVar6;

                    /* 0x3c00  45  _THRASH_writerect@20 */
  plVar5 = param_5;
  piVar2 = (int *)FUN_60001650(2);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  if (piVar2[2] == 6) {
    iVar3 = 4;
  }
  else {
    iVar3 = (piVar2[2] == 5) + 2;
  }
  iVar1 = piVar2[1];
  plVar6 = (longlong *)(iVar1 * param_2 + iVar3 * param_1 + *piVar2);
  if (param_4 != 0) {
    param_5 = (longlong *)param_4;
    do {
      FUN_6000c0c0(plVar6,plVar5,iVar3 * param_3);
      plVar6 = (longlong *)((int)plVar6 + iVar1);
      plVar5 = (longlong *)((int)plVar5 + iVar3 * param_3);
      param_5 = (longlong *)((int)param_5 + -1);
    } while (param_5 != (longlong *)0x0);
  }
  uVar4 = _THRASH_unlockwindow_4();
  return uVar4;
}



/* VA 60003ca0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * _THRASH_setstate_8(uint param_1,float *param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  uint uVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  float fVar14;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  uint local_f0;
  undefined4 local_ec [15];
  undefined4 local_b0;

  fVar3 = DAT_6005abc8;
  fVar2 = DAT_6005abc4;
  fVar14 = DAT_6005aae4;
                    /* 0x3ca0  34  _THRASH_setstate@8 */
  piVar1 = DAT_6001869c;
  uVar5 = param_1 & 0xffff0000;
  pfVar10 = (float *)0x0;
  iVar9 = 0;
  if ((int)uVar5 < 0x40001) {
    if (uVar5 == 0x40000) {
      iVar9 = 4;
    }
    else if ((int)uVar5 < 0x20001) {
      if (uVar5 == 0x20000) {
        iVar9 = 2;
      }
      else if (uVar5 == 0) {
        iVar9 = 0;
      }
      else if (uVar5 == 0x10000) {
        iVar9 = 1;
      }
    }
    else if (uVar5 == 0x30000) {
      iVar9 = 3;
    }
  }
  else if (uVar5 == 0x50000) {
    iVar9 = 5;
  }
  else if (uVar5 == 0x60000) {
    iVar9 = 6;
  }
  else if (uVar5 == 0x70000) {
    iVar9 = 7;
  }
  local_f0 = param_1;
  uVar5 = param_1 & 0xffff;
  if (400 < uVar5) {
    switch(uVar5) {
    case 0x191:
      _DAT_600170c4 = param_2;
      pfVar10 = (float *)0x1;
      break;
    default:
switchD_60003d5d_caseD_1a:
      pfVar10 = (float *)FUN_6000b2c0(uVar5,(undefined *)param_2);
      goto LAB_60006a10;
    case 0x193:
      if (param_2 != (float *)0x0) {
        *param_2 = DAT_6005aae0;
        fVar2 = DAT_6005aae8;
        param_2[1] = fVar14;
        fVar14 = DAT_6005aaec;
        param_2[2] = fVar2;
        fVar2 = DAT_6005aaf0;
        param_2[3] = fVar14;
        fVar14 = DAT_6005aaf4;
        param_2[4] = fVar2;
        fVar2 = DAT_6005aaf8;
        param_2[5] = fVar14;
        fVar14 = DAT_6005aafc;
        param_2[6] = fVar2;
        pfVar10 = DAT_6005ab00;
        param_2[7] = fVar14;
        fVar14 = DAT_6005ab04;
        param_2[8] = (float)pfVar10;
        fVar2 = DAT_6005ab08;
        param_2[9] = fVar14;
        fVar14 = DAT_6005ab0c;
        param_2[10] = fVar2;
        fVar2 = DAT_6005ab10;
        param_2[0xb] = fVar14;
        fVar14 = DAT_6005ab14;
        param_2[0xc] = fVar2;
        fVar2 = DAT_6005ab18;
        param_2[0xd] = fVar14;
        fVar14 = DAT_6005ab1c;
        param_2[0xe] = fVar2;
        fVar2 = DAT_6005ab20;
        param_2[0xf] = fVar14;
        fVar14 = DAT_6005ab24;
        param_2[0x10] = fVar2;
        fVar2 = DAT_6005ab28;
        param_2[0x11] = fVar14;
        pfVar10 = DAT_6005ab2c;
        param_2[0x12] = fVar2;
        fVar14 = DAT_6005ab30;
        param_2[0x13] = (float)pfVar10;
        fVar2 = DAT_6005ab34;
        param_2[0x14] = fVar14;
        fVar14 = DAT_6005ab38;
        param_2[0x15] = fVar2;
        fVar2 = DAT_6005ab3c;
        param_2[0x16] = fVar14;
        fVar14 = DAT_6005ab40;
        param_2[0x17] = fVar2;
        fVar2 = DAT_6005ab44;
        param_2[0x18] = fVar14;
        fVar14 = DAT_6005ab48;
        param_2[0x19] = fVar2;
        fVar2 = DAT_6005ab4c;
        param_2[0x1a] = fVar14;
        fVar14 = DAT_6005ab50;
        param_2[0x1b] = fVar2;
        fVar2 = DAT_6005ab54;
        param_2[0x1c] = fVar14;
        pfVar10 = DAT_6005ab58;
        param_2[0x1d] = fVar2;
        fVar14 = DAT_6005ab60;
        param_2[0x1e] = (float)pfVar10;
        fVar2 = DAT_6005ab64;
        param_2[0x20] = fVar14;
        fVar14 = DAT_6005ab68;
        param_2[0x21] = fVar2;
        fVar2 = DAT_6005ab6c;
        param_2[0x22] = fVar14;
        fVar14 = DAT_6005ab70;
        param_2[0x23] = fVar2;
        fVar2 = DAT_6005ab74;
        param_2[0x24] = fVar14;
        fVar14 = DAT_6005ab78;
        param_2[0x25] = fVar2;
        fVar2 = DAT_6005ab7c;
        param_2[0x26] = fVar14;
        fVar14 = DAT_6005ab80;
        param_2[0x27] = fVar2;
        fVar2 = DAT_6005ab84;
        param_2[0x28] = fVar14;
        fVar14 = DAT_6005ab88;
        param_2[0x29] = fVar2;
        fVar2 = DAT_6005ab8c;
        param_2[0x2a] = fVar14;
        fVar14 = DAT_6005ab90;
        param_2[0x2b] = fVar2;
        fVar2 = DAT_6005ab94;
        param_2[0x2c] = fVar14;
        fVar14 = DAT_6005ab98;
        param_2[0x2d] = fVar2;
        fVar2 = DAT_6005ab9c;
        param_2[0x2e] = fVar14;
        param_2[0x2f] = fVar2;
        return param_2;
      }
      return (float *)0x0;
    case 0x194:
      switch(param_2) {
      case (float *)0x0:
        FUN_60008a10(0x13,2);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x1:
        FUN_60008a10(0x13,1);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x2:
        FUN_60008a10(0x13,5);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x3:
        FUN_60008a10(0x13,6);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x4:
        FUN_60008a10(0x13,7);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x5:
        FUN_60008a10(0x13,8);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x6:
        FUN_60008a10(0x13,3);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x7:
        FUN_60008a10(0x13,9);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x8:
        FUN_60008a10(0x13,4);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x9:
        FUN_60008a10(0x13,10);
        pfVar10 = (float *)0x1;
        break;
      default:
        goto switchD_60004207_default;
      }
      break;
    case 0x195:
      switch(param_2) {
      case (float *)0x0:
        FUN_60008a10(0x14,2);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x1:
        FUN_60008a10(0x14,1);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x2:
        FUN_60008a10(0x14,5);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x3:
        FUN_60008a10(0x14,6);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x4:
        FUN_60008a10(0x14,7);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x5:
        FUN_60008a10(0x14,8);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x6:
        FUN_60008a10(0x14,3);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x7:
        FUN_60008a10(0x14,9);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x8:
        FUN_60008a10(0x14,4);
        pfVar10 = (float *)0x1;
        break;
      case (float *)0x9:
        FUN_60008a10(0x14,10);
      default:
switchD_60004207_default:
        pfVar10 = (float *)0x1;
      }
      break;
    case 0x197:
      if (param_2 == (float *)0x0) {
        DAT_600170f4 = 0;
LAB_60005d21:
        pfVar10 = (float *)0x1;
      }
      else if (param_2 == (float *)0x1) {
        DAT_600170f4 = 1;
        pfVar10 = (float *)0x1;
      }
      else {
        if (param_2 != (float *)0x2) goto LAB_60005d21;
        DAT_600170f4 = 2;
        pfVar10 = (float *)0x1;
      }
      break;
    case 0x198:
switchD_60003d5d_caseD_45:
      DAT_60018860 = (uint)(param_2 != (float *)0x0);
      pfVar10 = (float *)0x1;
      break;
    case 0x199:
      if (DAT_6005ab88 == 0.0) {
        return (float *)0x0;
      }
      pfVar10 = (float *)0x1;
      if (param_2 == (float *)0x1) {
        FUN_60008a10(0x28,1);
        FUN_60008a10(8,2);
      }
      else {
        FUN_60008a10(0x28,0);
        FUN_60008a10(8,3);
      }
      break;
    case 0x19a:
      FUN_60008a10(0x3c,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x19c:
      if (param_2 == (float *)0x0) {
        return (float *)0x0;
      }
      *param_2 = DAT_60058d8c;
      pfVar10 = (float *)0x1;
      break;
    case 0x19d:
      if (param_2 == (float *)0x0) {
        return (float *)0x0;
      }
      *param_2 = DAT_60058d90;
      pfVar10 = (float *)0x1;
      break;
    case 0x19f:
      FUN_600089d0(iVar9,7,*param_2);
      FUN_600089d0(iVar9,8,param_2[1]);
      FUN_600089d0(iVar9,9,param_2[2]);
      FUN_600089d0(iVar9,10,param_2[3]);
      pfVar10 = (float *)0x1;
      break;
    case 0x1a0:
      FUN_600089d0(iVar9,0x16,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1a1:
      FUN_600089d0(iVar9,0x17,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1a2:
      if (param_2 == (float *)0x0) {
        DAT_60018864 = 0;
        pfVar10 = (float *)0x1;
      }
      else {
        DAT_600fc890 = param_2;
        DAT_60018864 = 1;
        pfVar10 = (float *)0x1;
      }
      break;
    case 0x1a3:
      if ((DAT_60058d80 != (int *)0x0) &&
         (iVar9 = (**(code **)(*DAT_60058d80 + 0x68))(DAT_60058d80), iVar9 < 0)) {
        if (iVar9 == -0x7789fdb5) {
          return (float *)0x0;
        }
        if (iVar9 != -0x7789fdbb) {
          if (iVar9 != -0x7789ff1f) {
            return (float *)0x0;
          }
          return (float *)0x0;
        }
        return (float *)0x0;
      }
switchD_60003d5d_caseD_16:
      pfVar10 = (float *)0x1;
      break;
    case 0x1a4:
      DAT_60018844 = param_2;
      pfVar10 = (float *)0x1;
      break;
    case 0x1a5:
      switch(iVar9) {
      case 0:
        (**(code **)(*DAT_60058d9c + 0x2c))(DAT_60058d9c,1,param_2);
        pfVar10 = (float *)0x1;
        break;
      case 1:
        uVar13 = 4;
        goto LAB_60006697;
      case 2:
        (**(code **)(*DAT_60058d9c + 0x2c))(DAT_60058d9c,5,param_2);
        pfVar10 = (float *)0x1;
        break;
      case 3:
        uVar13 = 6;
LAB_60006697:
        (**(code **)(*DAT_60058d9c + 0x2c))(DAT_60058d9c,uVar13,param_2);
switchD_60006658_default:
        pfVar10 = (float *)0x1;
        break;
      default:
        goto switchD_60006658_default;
      }
      break;
    case 0x1a6:
      (**(code **)(*DAT_60058d9c + 0x2c))(DAT_60058d9c,2,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1a7:
      (**(code **)(*DAT_60058d9c + 0x2c))(DAT_60058d9c,3,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1a8:
      switch(iVar9) {
      case 0:
        (**(code **)(*DAT_60058d9c + 0x38))(DAT_60058d9c,1,param_2);
        pfVar10 = (float *)0x1;
        break;
      case 1:
        uVar13 = 4;
        goto LAB_60006735;
      case 2:
        (**(code **)(*DAT_60058d9c + 0x38))(DAT_60058d9c,5,param_2);
        pfVar10 = (float *)0x1;
        break;
      case 3:
        uVar13 = 6;
LAB_60006735:
        (**(code **)(*DAT_60058d9c + 0x38))(DAT_60058d9c,uVar13,param_2);
switchD_600066f6_default:
        pfVar10 = (float *)0x1;
        break;
      default:
        goto switchD_600066f6_default;
      }
      break;
    case 0x1a9:
      (**(code **)(*DAT_60058d9c + 0x38))(DAT_60058d9c,2,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1aa:
      (**(code **)(*DAT_60058d9c + 0x38))(DAT_60058d9c,3,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1ab:
      switch(iVar9) {
      case 0:
        (**(code **)(*DAT_60058d9c + 0x30))(DAT_60058d9c,1,param_2);
        pfVar10 = (float *)0x1;
        break;
      case 1:
        uVar13 = 4;
        goto LAB_600067d3;
      case 2:
        (**(code **)(*DAT_60058d9c + 0x30))(DAT_60058d9c,5,param_2);
        pfVar10 = (float *)0x1;
        break;
      case 3:
        uVar13 = 6;
LAB_600067d3:
        (**(code **)(*DAT_60058d9c + 0x30))(DAT_60058d9c,uVar13,param_2);
switchD_60006794_default:
        pfVar10 = (float *)0x1;
        break;
      default:
        goto switchD_60006794_default;
      }
      break;
    case 0x1ac:
      (**(code **)(*DAT_60058d9c + 0x30))(DAT_60058d9c,2,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1ad:
      (**(code **)(*DAT_60058d9c + 0x30))(DAT_60058d9c,3,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1ae:
      local_158 = *param_2;
      local_148 = (float)*(byte *)((int)param_2 + 7) * _DAT_60015438;
      local_154 = (float)*(byte *)((int)param_2 + 6) * _DAT_60015438;
      local_150 = (float)*(byte *)((int)param_2 + 5) * _DAT_60015438;
      local_14c = (float)((uint)param_2[1] & 0xff) * _DAT_60015438;
      local_138 = (float)*(byte *)((int)param_2 + 0xb) * _DAT_60015438;
      local_144 = (float)*(byte *)((int)param_2 + 10) * _DAT_60015438;
      local_140 = (float)*(byte *)((int)param_2 + 9) * _DAT_60015438;
      local_13c = (float)((uint)param_2[2] & 0xff) * _DAT_60015438;
      local_128 = (float)*(byte *)((int)param_2 + 0xf) * _DAT_60015438;
      local_134 = (float)*(byte *)((int)param_2 + 0xe) * _DAT_60015438;
      local_130 = (float)*(byte *)((int)param_2 + 0xd) * _DAT_60015438;
      local_12c = (float)((uint)param_2[3] & 0xff) * _DAT_60015438;
      local_124 = param_2[4];
      local_120 = param_2[5];
      local_11c = param_2[6];
      local_118 = param_2[7];
      local_10c = param_2[10];
      local_114 = param_2[8];
      local_100 = param_2[0xd];
      local_110 = param_2[9];
      local_108 = param_2[0xb];
      local_f4 = param_2[0x10];
      local_104 = param_2[0xc];
      local_fc = param_2[0xe];
      local_f8 = param_2[0xf];
      (**(code **)(*DAT_60058d9c + 0x48))(DAT_60058d9c,iVar9,&local_158);
      pfVar10 = (float *)0x1;
      break;
    case 0x1af:
      (**(code **)(*DAT_60058d9c + 0x4c))(DAT_60058d9c,iVar9,&local_158);
      *param_2 = local_158;
      iVar9 = ftol();
      uVar5 = ftol();
      uVar7 = ftol();
      uVar8 = ftol();
      param_2[1] = (float)(((iVar9 << 8 | uVar5) << 8 | uVar7) << 8 | uVar8);
      iVar9 = ftol();
      uVar5 = ftol();
      uVar7 = ftol();
      uVar8 = ftol();
      param_2[2] = (float)(((iVar9 << 8 | uVar5) << 8 | uVar7) << 8 | uVar8);
      iVar9 = ftol();
      uVar5 = ftol();
      uVar7 = ftol();
      uVar8 = ftol();
      param_2[4] = local_124;
      param_2[5] = local_120;
      param_2[6] = local_11c;
      param_2[3] = (float)(((iVar9 << 8 | uVar5) << 8 | uVar7) << 8 | uVar8);
      param_2[7] = local_118;
      param_2[8] = local_114;
      param_2[9] = local_110;
      param_2[10] = local_10c;
      param_2[0xb] = local_108;
      param_2[0xc] = local_104;
      param_2[0xd] = local_100;
      param_2[0xe] = local_fc;
      param_2[0xf] = local_f8;
      param_2[0x10] = local_f4;
      pfVar10 = (float *)0x1;
      break;
    case 0x1b0:
      (**(code **)(*DAT_60058d9c + 0xb0))(DAT_60058d9c,iVar9,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1b1:
      local_14c = (float)*(byte *)((int)param_2 + 3) * _DAT_60015438;
      local_158 = (float)*(byte *)((int)param_2 + 2) * _DAT_60015438;
      local_154 = (float)*(byte *)((int)param_2 + 1) * _DAT_60015438;
      local_150 = (float)((uint)*param_2 & 0xff) * _DAT_60015438;
      local_13c = (float)*(byte *)((int)param_2 + 7) * _DAT_60015438;
      local_148 = (float)*(byte *)((int)param_2 + 6) * _DAT_60015438;
      local_144 = (float)*(byte *)((int)param_2 + 5) * _DAT_60015438;
      local_140 = (float)((uint)param_2[1] >> 9 & 0xff) * _DAT_60015438;
      local_12c = (float)*(byte *)((int)param_2 + 0xb) * _DAT_60015438;
      local_138 = (float)*(byte *)((int)param_2 + 10) * _DAT_60015438;
      local_134 = (float)*(byte *)((int)param_2 + 9) * _DAT_60015438;
      local_130 = (float)((uint)param_2[2] & 0xff) * _DAT_60015438;
      local_118 = param_2[4];
      local_11c = (float)*(byte *)((int)param_2 + 0xf) * _DAT_60015438;
      local_128 = (float)*(byte *)((int)param_2 + 0xe) * _DAT_60015438;
      local_124 = (float)*(byte *)((int)param_2 + 0xd) * _DAT_60015438;
      local_120 = (float)((uint)param_2[3] & 0xff) * _DAT_60015438;
      (**(code **)(*DAT_60058d9c + 0x40))(DAT_60058d9c,&local_158);
      pfVar10 = (float *)0x1;
      break;
    case 0x1b2:
      (**(code **)(*DAT_60058d9c + 0x44))(DAT_60058d9c,&local_158);
      iVar9 = ftol();
      uVar5 = ftol();
      uVar7 = ftol();
      uVar8 = ftol();
      *param_2 = (float)(((iVar9 << 8 | uVar5) << 8 | uVar7) << 8 | uVar8);
      iVar9 = ftol();
      uVar5 = ftol();
      uVar7 = ftol();
      uVar8 = ftol();
      param_2[1] = (float)(((iVar9 << 8 | uVar5) << 8 | uVar7) << 8 | uVar8);
      iVar9 = ftol();
      uVar5 = ftol();
      uVar7 = ftol();
      uVar8 = ftol();
      param_2[2] = (float)(((iVar9 << 8 | uVar5) << 8 | uVar7) << 8 | uVar8);
      iVar9 = ftol();
      uVar5 = ftol();
      uVar7 = ftol();
      uVar8 = ftol();
      param_2[3] = (float)(((iVar9 << 8 | uVar5) << 8 | uVar7) << 8 | uVar8);
      param_2[4] = local_118;
      pfVar10 = (float *)0x1;
      break;
    case 0x1b3:
      if (DAT_6001822c == 0) {
        FUN_60008810();
        DAT_6001822c = 1;
      }
      FUN_60006f10();
      if ((*(short *)(param_2 + 5) == 0) || (param_2[4] == 0.0)) {
        iVar9 = (**(code **)(*DAT_60058d9c + 100))
                          (DAT_60058d9c,*param_2,param_2[1],param_2[2],*(undefined2 *)(param_2 + 3),
                           0);
      }
      else {
        iVar9 = (**(code **)(*DAT_60058d9c + 0x68))
                          (DAT_60058d9c,*param_2,param_2[1],param_2[2],*(undefined2 *)(param_2 + 3),
                           param_2[4],*(short *)(param_2 + 5),0);
      }
      if (iVar9 < 0) {
        return (float *)0x0;
      }
      goto LAB_60006942;
    case 0x1b4:
      if (param_2 != (float *)0x0) {
        *param_2 = DAT_6005abc0;
        fVar14 = DAT_6005abcc;
        param_2[1] = fVar2;
        fVar2 = DAT_6005abd0;
        param_2[2] = fVar3;
        fVar3 = DAT_6005abd4;
        param_2[3] = fVar14;
        fVar14 = DAT_6005abd8;
        param_2[4] = fVar2;
        param_2[5] = fVar3;
        param_2[6] = fVar14;
      }
LAB_60006942:
      pfVar10 = (float *)0x1;
      break;
    case 0x1b5:
      (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0x8b,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1b6:
      FUN_60006f10();
      (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0x88,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1b7:
      if (param_2 == (float *)0x0) {
        (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0x89,0);
        pfVar10 = (float *)0x1;
      }
      else {
        (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0x89,1);
        pfVar10 = (float *)0x1;
      }
      break;
    case 0x1b8:
      puVar12 = local_ec;
      for (iVar9 = 0x3b; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      local_ec[1] = 0x38;
      local_b0 = 0x38;
      (**(code **)(*DAT_60058d9c + 0xc))(DAT_60058d9c,local_ec);
      (**(code **)(*DAT_60058d98 + 0x14))(DAT_60058d98,&stack0xfffffe90,param_2,0);
      pfVar10 = (float *)0x1;
      break;
    case 0x1b9:
      (**(code **)(*(int *)*param_2 + 0xc))((int *)*param_2,param_2[4],param_2 + 8,0);
      pfVar10 = (float *)0x1;
      break;
    case 0x1ba:
      (**(code **)(*(int *)*param_2 + 0x10))((int *)*param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1bb:
      if (DAT_6001822c == 0) {
        FUN_60008810();
        DAT_6001822c = 1;
      }
      if ((*(short *)(param_2 + 7) == 0) || (param_2[6] == 0.0)) {
        (**(code **)(*DAT_60058d9c + 0x7c))
                  (DAT_60058d9c,param_2[1],*param_2,0,*(undefined2 *)(param_2 + 5),0);
        pfVar10 = (float *)0x1;
      }
      else {
        (**(code **)(*DAT_60058d9c + 0x80))
                  (DAT_60058d9c,param_2[1],*param_2,0,*(undefined2 *)(param_2 + 5),param_2[6],
                   *(short *)(param_2 + 7),0);
        pfVar10 = (float *)0x1;
      }
      break;
    case 0x1bc:
      (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,DAT_60058d9c,0);
      pfVar10 = (float *)0x1;
      break;
    case 0x1bd:
      if (param_2 != (float *)0x0) {
        (**(code **)(*DAT_60058d9c + 0xb8))(DAT_60058d9c,iVar9,param_2);
      }
      pfVar10 = (float *)0x1;
      break;
    case 0x1be:
      goto switchD_60003d5d_caseD_c;
    case 0x1bf:
      if (param_2 == (float *)0x0) {
        DAT_60018848 = DAT_60018848 ^ 1 << (sbyte)iVar9;
      }
      else {
        DAT_60018848 = DAT_60018848 | 1 << (sbyte)iVar9;
      }
      (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0x98,DAT_60018848);
      pfVar10 = (float *)0x1;
      break;
    case 0x1c0:
      (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0x97,param_2);
      pfVar10 = (float *)0x1;
      break;
    case 0x1c1:
      if ((DAT_600170f0 & 0x100) != 0) {
        FUN_600089d0(0,0xb,0);
        FUN_600089d0(1,0xb,0);
      }
      if ((DAT_600170f0 & 0x200) != 0) {
        FUN_600089d0(0,0xb,0);
        FUN_600089d0(1,0xb,1);
      }
      if ((DAT_600170f0 & 0x300) != 0) {
        FUN_600089d0(0,0xb,0);
        FUN_600089d0(1,0xb,1);
        FUN_600089d0(2,0xb,2);
      }
      if ((DAT_600170f0 & 0x400) == 0) {
        return (float *)0x0;
      }
      FUN_600089d0(0,0xb,0);
      FUN_600089d0(1,0xb,1);
      FUN_600089d0(2,0xb,2);
      FUN_600089d0(3,0xb,3);
      return (float *)0x0;
    case 0x1c3:
      pfVar10 = DAT_6005ab2c;
      goto LAB_60006a10;
    }
    goto LAB_60006a14;
  }
  if (uVar5 == 400) {
    FUN_600094f0(param_2);
    pfVar10 = (float *)0x1;
    goto LAB_60006a14;
  }
  switch(uVar5) {
  case 0:
    goto switchD_60003d5d_caseD_0;
  case 1:
    _THRASH_settexture_4((uint)param_2);
    pfVar10 = (float *)0x1;
    break;
  case 2:
    if (param_2 == (float *)0x0) {
      FUN_60008a10(0x16,1);
      DAT_60058e1c = 1;
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x2) {
      FUN_60008a10(0x16,2);
      DAT_60058e1c = 0;
      pfVar10 = (float *)0x1;
    }
    else {
      if (param_2 != (float *)0x1) {
        return (float *)0x0;
      }
      FUN_60008a10(0x16,3);
      DAT_60058e1c = 0x80000000;
      pfVar10 = param_2;
    }
    break;
  case 3:
    FUN_60008d00((uint)param_2);
    pfVar10 = (float *)0x1;
    break;
  case 4:
    if (DAT_6005aaf4 == 0.0) {
      return (float *)0x0;
    }
    if (param_2 == (float *)0x0) {
      FUN_60008a10(0xe,0);
      if (DAT_60058d78 != 0xd) {
        FUN_60008a10(7,0);
      }
LAB_60005176:
      FUN_60008a10(0x17,8);
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x1) {
      FUN_60008a10(0xe,1);
      FUN_60008a10(7,1);
      FUN_60008a10(0x17,DAT_600170d4);
      pfVar10 = (float *)0x1;
    }
    else {
      if (param_2 != (float *)0x2) {
        return (float *)0x0;
      }
      if (DAT_6005ab08 == 0.0) {
        FUN_60008a10(0xe,1);
        FUN_60008a10(7,1);
        FUN_60008a10(0x17,DAT_600170d4);
        return (float *)0x0;
      }
      FUN_60008a10(7,1);
      FUN_60008a10(0xe,1);
      FUN_60008a10(0x17,DAT_600170d4);
      FUN_60008a10(7,2);
      pfVar10 = (float *)0x1;
    }
    break;
  case 5:
    FUN_60008a10(0x1a,(uint)(param_2 != (float *)0x0));
    pfVar10 = DAT_6005ab00;
    goto LAB_60006a10;
  case 6:
    switch(param_2) {
    case (float *)0x0:
      FUN_60008a10(9,1);
      FUN_60008a10(0x1d,0);
      DAT_600170ec = 0;
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x1:
      FUN_60008a10(9,2);
      FUN_60008a10(0x1d,0);
      pfVar10 = (float *)0x1;
      DAT_600170ec = 1;
      break;
    case (float *)0x2:
      if (DAT_6005ab44 == 0.0) {
        return (float *)0x0;
      }
      FUN_60008a10(9,2);
      pfVar10 = (float *)0x1;
      FUN_60008a10(0x1d,1);
      DAT_600170ec = 1;
      break;
    case (float *)0x3:
      goto switchD_60003d5d_caseD_c;
    default:
      goto switchD_60003d5d_caseD_0;
    }
    break;
  case 7:
    if (param_2 == (float *)0x0) {
      FUN_600089d0(iVar9,0x10,1);
      FUN_600089d0(iVar9,0x11,1);
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x1) {
      FUN_600089d0(iVar9,0x10,2);
      FUN_600089d0(iVar9,0x11,2);
      pfVar10 = param_2;
    }
    else {
      if (param_2 != (float *)0x2) {
        return (float *)0x0;
      }
      if (DAT_6005ab3c == 0.0) {
        return (float *)0x0;
      }
      FUN_600089d0(iVar9,0x10,5);
      FUN_600089d0(iVar9,0x11,3);
      FUN_600089d0(iVar9,0x15,DAT_6005aba4);
      pfVar10 = (float *)0x1;
    }
    break;
  case 8:
    pfVar10 = DAT_6005ab58;
    if (DAT_6005ab58 != (float *)0x0) {
      FUN_600089d0(iVar9,0x13,param_2);
      pfVar10 = DAT_6005ab58;
    }
    goto LAB_60006a10;
  case 9:
    if ((int)param_2 < 0) {
      return (float *)0x0;
    }
    if ((int)param_2 < 2) {
      fVar14 = 0.0;
    }
    else {
      if (param_2 != (float *)0x2) {
        return (float *)0x0;
      }
      fVar14 = DAT_6005ab34;
      if (1 < (int)DAT_6005ab34) {
        fVar14 = 2.8026e-45;
      }
    }
    bVar4 = FUN_60008a10(2,fVar14);
    if (CONCAT31(extraout_var,bVar4) == 0) {
      return (float *)0x0;
    }
    if ((param_2 != (float *)0x0) && (DAT_6005ab34 == 0.0)) {
      return (float *)0x0;
    }
    goto LAB_60006942;
  case 10:
    if (param_2 == (float *)0x0) {
      FUN_60008a10(0x1b,0);
      pfVar10 = (float *)0x1;
    }
    else {
      if (param_2 != (float *)0x2) {
        if (param_2 == (float *)0x1) {
          return (float *)0x0;
        }
        if (param_2 != (float *)0x3) {
          return (float *)0x0;
        }
        return (float *)0x0;
      }
      FUN_60008a10(0x1b,1);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0xb:
    switch(param_2) {
    case (float *)0x0:
      FUN_600089d0(iVar9,0x12,1);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x1:
      FUN_600089d0(iVar9,0x12,2);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x2:
      goto switchD_60003d5d_caseD_c;
    case (float *)0x3:
      if (DAT_6005ab14 == 0.0) {
        return (float *)0x0;
      }
      FUN_600089d0(iVar9,0x12,3);
      pfVar10 = (float *)0x1;
      break;
    default:
      goto switchD_60003d5d_caseD_0;
    }
    break;
  case 0xc:
  case 0x10:
  case 0x11:
  case 0x31:
  case 0x32:
  case 0x33:
switchD_60003d5d_caseD_c:
    return (float *)0x0;
  case 0xd:
    if (param_2 == (float *)0x0) {
      FUN_600089d0(iVar9,0xc,3);
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x1) {
      FUN_600089d0(iVar9,0xc,1);
      pfVar10 = param_2;
    }
    else {
      if (param_2 != (float *)0x2) {
        return (float *)0x0;
      }
      FUN_600089d0(iVar9,0xc,2);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0xe:
    if ((param_2 == (float *)0x0) || (((uint)param_2 & 0xfffff000) != 0)) {
      DAT_600170e8 = param_2;
      FUN_60008a10(0x26,param_2);
      pfVar10 = (float *)0x1;
    }
    else {
      DAT_600170e8 = (float *)(_DAT_60015448 / (float)(int)param_2);
      FUN_60008a10(0x26,DAT_600170e8);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0xf:
    DAT_600170e4 = (uint)param_2 & 0xffffff;
    FUN_60008a10(0x22,DAT_600170e4);
    pfVar10 = (float *)0x1;
    break;
  case 0x12:
    DAT_60018688 = param_2;
    pfVar10 = (float *)0x1;
    break;
  case 0x13:
    if (param_2 == (float *)0x0) {
      DAT_6007b860 = 0;
      DAT_6007b864 = 0;
      DAT_6007b868 = 0;
      _DAT_6007b86c = 0;
      DAT_6007b870 = 0;
      DAT_6007b874 = 0;
      _DAT_6007b878 = 0;
      _DAT_6007b87c = 0;
      pfVar10 = (float *)0x1;
    }
    else {
      PTR_FUN_6001713c = (undefined *)param_2[6];
      pfVar10 = param_2;
      pfVar11 = (float *)&DAT_6007b860;
      for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
        *pfVar11 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        pfVar11 = pfVar11 + 1;
      }
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x14:
  case 0x69:
    if (param_2 == (float *)0x0) goto switchD_60004207_default;
    FUN_60006e50((int)param_2,0x60018740);
    FUN_60008a10(0x23,0);
    DAT_60018854 = 1;
    DAT_60018850 = (float *)0x10;
    pfVar10 = (float *)0x1;
    break;
  case 0x15:
    if (param_2 == (float *)0x4) {
      if (DAT_6005ab0c == 0.0) {
        return (float *)0x0;
      }
      DAT_60018850 = param_2;
      DAT_60018854 = 0;
      FUN_60008a10(0x23,1);
      FUN_60008a10(0x8c,0);
      FUN_60008a10(0x22,DAT_600170e4);
      FUN_60008a10(0x26,DAT_600170e8);
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x8) {
      if (DAT_6005ab0c == 0.0) {
        return (float *)0x0;
      }
      DAT_60018850 = param_2;
      DAT_60018854 = 0;
      FUN_60008a10(0x23,2);
      FUN_60008a10(0x8c,0);
      FUN_60008a10(0x22,DAT_600170e4);
      FUN_60008a10(0x26,DAT_600170e8);
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x2) {
      if (DAT_6005ab0c == 0.0) {
        return (float *)0x0;
      }
      DAT_60018850 = param_2;
      DAT_60018854 = 0;
      FUN_60008a10(0x23,3);
      FUN_60008a10(0x8c,0);
      FUN_60008a10(0x22,DAT_600170e4);
      FUN_60008a10(0x26,DAT_600170e8);
      FUN_60008a10(0x24,DAT_6001884c);
      FUN_60008a10(0x25,DAT_600170dc);
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x0) {
      FUN_60008a10(0x1c,0);
      DAT_60018854 = 0;
      pfVar10 = (float *)0x1;
    }
    else {
      if (param_2 != (float *)0x1) {
        return (float *)0x0;
      }
      if (((DAT_6005ab0c == 0.0) && (DAT_60018850 != (float *)0x10)) ||
         (FUN_60008a10(0x1c,1), DAT_60018850 != (float *)0x10)) goto switchD_60004207_default;
      DAT_60018854 = 1;
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x16:
  case 0x17:
    goto switchD_60003d5d_caseD_16;
  case 0x18:
  case 0x66:
    if (_DAT_6001885c == (float)(int)param_2) {
      pfVar10 = (float *)0x1;
    }
    else {
      _DAT_6001885c = (float)(int)param_2 * _DAT_60015444;
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x19:
    DAT_6007b880 = param_2;
    if ((DAT_60018698 != (int *)0x0) && (DAT_60018688 != (float *)0x0)) {
      (**(code **)(*DAT_60018698 + 0x20))(DAT_60018698,0,param_2);
    }
    FUN_6000b2c0(0x19,(undefined *)param_2);
    pfVar10 = (float *)0x1;
    break;
  default:
    goto switchD_60003d5d_caseD_1a;
  case 0x23:
    bVar4 = FUN_60008c80();
    pfVar10 = (float *)CONCAT31(extraout_var_00,bVar4);
    goto LAB_60006a10;
  case 0x24:
    if (DAT_6005aba0 == 0) {
      return (float *)0x0;
    }
    if (param_2 == (float *)0x0) {
      FUN_60008a10(0xf,0);
      FUN_60008a10(0x19,8);
      pfVar10 = (float *)0x1;
    }
    else {
      FUN_60008a10(0xf,1);
      FUN_60008a10(0x19,DAT_600170d8);
      FUN_60008a10(0x18,param_2);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x26:
    if (param_2 == (float *)0x0) {
      return (float *)0x0;
    }
    *param_2 = (float)DAT_60058d80;
    pfVar10 = (float *)0x1;
    break;
  case 0x28:
    if (*(int *)(&DAT_6005abe0 + (int)param_2 * 4) == 0) {
      return (float *)0x0;
    }
    switch(param_2) {
    case (float *)0x0:
      DAT_600170d4 = 1;
      FUN_60008a10(0x17,1);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x1:
      DAT_600170d4 = 2;
      FUN_60008a10(0x17,2);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x2:
      DAT_600170d4 = 3;
      FUN_60008a10(0x17,3);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x3:
      DAT_600170d4 = 4;
      FUN_60008a10(0x17,4);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x4:
      DAT_600170d4 = 5;
      FUN_60008a10(0x17,5);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x5:
      DAT_600170d4 = 6;
      FUN_60008a10(0x17,6);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x6:
      DAT_600170d4 = 7;
      FUN_60008a10(0x17,7);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x7:
      DAT_600170d4 = 8;
      goto LAB_60005176;
    default:
      goto switchD_60004207_default;
    }
    break;
  case 0x29:
    switch(param_2) {
    case (float *)0x0:
      if (iVar9 == 0) {
        if (DAT_6005ab2c == (float *)0x0) {
          FUN_600089d0(0,1,4);
          FUN_600089d0(0,2,2);
          FUN_600089d0(0,3,0);
          FUN_600089d0(0,4,2);
          FUN_600089d0(0,5,2);
          pfVar10 = (float *)0x1;
        }
        else {
          FUN_600089d0(0,1,4);
          FUN_600089d0(0,2,2);
          FUN_600089d0(0,3,0);
          FUN_600089d0(0,4,4);
          FUN_600089d0(0,5,2);
          FUN_600089d0(0,6,0);
          pfVar10 = (float *)0x1;
        }
      }
      else if ((int)DAT_6005ab80 < 2) {
        FUN_600089d0(iVar9,1,1);
        FUN_600089d0(iVar9,2,2);
        FUN_600089d0(iVar9,3,1);
        FUN_600089d0(iVar9,4,1);
        FUN_600089d0(iVar9,5,2);
        FUN_600089d0(iVar9,6,1);
        pfVar10 = (float *)0x1;
      }
      else {
        FUN_600089d0(iVar9,1,2);
        FUN_600089d0(iVar9,2,2);
        FUN_600089d0(iVar9,3,1);
        FUN_600089d0(iVar9,4,2);
        FUN_600089d0(iVar9,5,2);
        FUN_600089d0(iVar9,6,1);
        pfVar10 = (float *)0x1;
      }
      goto LAB_60006a14;
    case (float *)0x1:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,1,7);
      FUN_600089d0(iVar9,4,7);
      FUN_600089d0(iVar9,5,2);
      iVar6 = iVar9;
      if (iVar9 == 0) {
        iVar6 = 0;
      }
      FUN_600089d0(iVar6,6,(uint)(iVar9 != 0));
      pfVar10 = (float *)(&DAT_6005a940)[iVar9 * 0xc];
      break;
    case (float *)0x2:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,5,2);
      FUN_600089d0(iVar9,6,1);
      FUN_600089d0(iVar9,1,1);
      FUN_600089d0(iVar9,4,1);
      pfVar10 = (float *)0x1;
      goto LAB_60006a14;
    case (float *)0x3:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,1,4);
      FUN_600089d0(iVar9,4,4);
      FUN_600089d0(iVar9,5,2);
      iVar6 = iVar9;
      if (iVar9 == 0) {
        iVar6 = 0;
      }
      FUN_600089d0(iVar6,6,(uint)(iVar9 != 0));
      pfVar10 = (float *)(&DAT_6005a948)[iVar9 * 0xc];
      break;
    case (float *)0x4:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,1,10);
      FUN_600089d0(iVar9,4,2);
      pfVar10 = (float *)(&DAT_6005a944)[iVar9 * 0xc];
      break;
    case (float *)0x5:
      FUN_600089d0(iVar9,1,3);
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,4,8);
      FUN_600089d0(iVar9,5,0x12);
      FUN_600089d0(iVar9,6,1);
      pfVar10 = *(float **)(iVar9 * 0x30 + 0x6005a958);
      break;
    case (float *)0x6:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,1,5);
      FUN_600089d0(iVar9,4,4);
      FUN_600089d0(iVar9,5,2);
      iVar6 = iVar9;
      if (iVar9 == 0) {
        iVar6 = 0;
      }
      FUN_600089d0(iVar6,6,(uint)(iVar9 != 0));
      pfVar10 = (float *)(&DAT_6005a94c)[iVar9 * 0xc];
      break;
    case (float *)0x7:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,1,6);
      FUN_600089d0(iVar9,4,4);
      FUN_600089d0(iVar9,5,2);
      iVar6 = iVar9;
      if (iVar9 == 0) {
        iVar6 = 0;
      }
      FUN_600089d0(iVar6,6,(uint)(iVar9 != 0));
      pfVar10 = (float *)(&DAT_6005a950)[iVar9 * 0xc];
      break;
    case (float *)0x8:
      if (iVar9 == 0) {
        if (DAT_6005ab2c == (float *)0x0) {
          FUN_600089d0(0,1,4);
          FUN_600089d0(0,2,2);
          FUN_600089d0(0,3,0);
          FUN_600089d0(0,4,2);
          FUN_600089d0(0,5,2);
          pfVar10 = DAT_6005a960;
        }
        else {
          FUN_600089d0(0,1,4);
          FUN_600089d0(0,2,2);
          FUN_600089d0(0,3,0);
          FUN_600089d0(0,4,4);
          FUN_600089d0(0,5,2);
          FUN_600089d0(0,6,0);
          pfVar10 = DAT_6005a960;
        }
      }
      else {
        FUN_600089d0(iVar9,2,2);
        FUN_600089d0(iVar9,3,1);
        FUN_600089d0(iVar9,5,2);
        FUN_600089d0(iVar9,6,1);
        FUN_600089d0(iVar9,1,0xd);
        FUN_600089d0(iVar9,4,1);
        pfVar10 = (&DAT_6005a960)[iVar9 * 0xc];
      }
      break;
    case (float *)0x9:
    case (float *)0x60:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,1,8);
      FUN_600089d0(iVar9,4,8);
      FUN_600089d0(iVar9,5,2);
      iVar6 = iVar9;
      if (iVar9 == 0) {
        iVar6 = 0;
      }
      FUN_600089d0(iVar6,6,(uint)(iVar9 != 0));
      pfVar10 = (float *)(&DAT_6005a95c)[iVar9 * 0xc];
      break;
    case (float *)0xa:
      if (iVar9 == 0) {
        FUN_600089d0(0,2,2);
        FUN_600089d0(0,3,3);
        FUN_600089d0(0,1,0x18);
        FUN_600089d0(0,4,2);
        uVar13 = 2;
        iVar6 = 0;
      }
      else {
        FUN_600089d0(iVar9,2,0);
        FUN_600089d0(iVar9,3,1);
        FUN_600089d0(iVar9,1,4);
        FUN_600089d0(iVar9,4,2);
        uVar13 = 1;
        iVar6 = iVar9;
      }
      FUN_600089d0(iVar6,5,uVar13);
      pfVar10 = (float *)(&DAT_6005a964)[iVar9 * 0xc];
      break;
    case (float *)0xb:
      FUN_600089d0(iVar9,1,0x16);
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,(uint)(iVar9 != 0));
      FUN_600089d0(iVar9,4,1);
      pfVar10 = (float *)(&DAT_6005a968)[iVar9 * 0xc];
      break;
    case (float *)0xc:
      FUN_600089d0(iVar9,1,0x17);
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,(uint)(iVar9 != 0));
      FUN_600089d0(iVar9,4,1);
      pfVar10 = (float *)(&DAT_6005a96c)[iVar9 * 0xc];
      break;
    default:
      return (float *)0x0;
    case (float *)0x62:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,1,7);
      FUN_600089d0(iVar9,4,0xe);
      FUN_600089d0(iVar9,5,2);
      FUN_600089d0(iVar9,6,3);
      pfVar10 = (float *)0x1;
      goto LAB_60006a14;
    case (float *)0x63:
      FUN_600089d0(iVar9,2,2);
      FUN_600089d0(iVar9,3,1);
      FUN_600089d0(iVar9,5,2);
      FUN_600089d0(iVar9,6,1);
      FUN_600089d0(iVar9,1,0xe);
      FUN_600089d0(iVar9,4,2);
      pfVar10 = (float *)0x1;
      goto LAB_60006a14;
    }
LAB_60006a10:
    if (pfVar10 == (float *)0x0) {
      return (float *)0x0;
    }
    break;
  case 0x2a:
    if (param_2 == (float *)0x0) {
      DAT_600170fc = 0x20;
      FUN_60006fa0(1);
      DAT_600170f0 = 0x1c4;
      _THRASH_setstate_8(0x44,(float *)0x0);
      _THRASH_setstate_8(0x10044,(float *)0x0);
      pfVar10 = (float *)0x1;
    }
    else {
      if (param_2 != (float *)0x1) goto switchD_60004207_default;
      DAT_600170fc = 0x28;
      FUN_60006fa0(0);
      DAT_600170f0 = 0x2c4;
      _THRASH_setstate_8(0x44,(float *)0x0);
      _THRASH_setstate_8(0x10044,(float *)0x1);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x2e:
  case 0x65:
    if (DAT_6005ab40 == 0.0) {
      return (float *)0x0;
    }
    if (DAT_6001869c == (int *)0x0) {
      return (float *)0x0;
    }
    if ((float)param_2 < _DAT_60015440 == ((float)param_2 == _DAT_60015440)) {
      if (_DAT_6001543c <= (float)param_2) {
        param_2 = (float *)0x40800000;
      }
    }
    else {
      param_2 = (float *)0x0;
    }
    iVar9 = 0;
    do {
      iVar6 = ftol();
      if (0xffff < iVar6) {
        iVar6 = 0xffff;
      }
      *(short *)((int)&DAT_6007ac40 + iVar9) = (short)iVar6;
      iVar6 = ftol();
      if (0xffff < iVar6) {
        iVar6 = 0xffff;
      }
      *(short *)((int)&DAT_6007ae40 + iVar9) = (short)iVar6;
      iVar6 = ftol();
      if (0xffff < iVar6) {
        iVar6 = 0xffff;
      }
      *(short *)((int)&DAT_6007b040 + iVar9) = (short)iVar6;
      iVar9 = iVar9 + 2;
    } while (iVar9 < 0x200);
    (**(code **)(*piVar1 + 0x10))(piVar1,0,&DAT_6007ac40);
    pfVar10 = (float *)0x1;
    break;
  case 0x2f:
    if (DAT_6005ab48 == 0.0) {
      return (float *)0x0;
    }
    if (param_2 == (float *)0x0) {
      FUN_60008a10(0x34,0);
      pfVar10 = (float *)0x1;
    }
    else {
      if (param_2 != (float *)0x1) goto switchD_60004207_default;
      FUN_60008a10(0x34,1);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x30:
    if (DAT_6005ab48 == 0.0) {
      return (float *)0x0;
    }
    switch(param_2) {
    case (float *)0x0:
      FUN_60008a10(0x38,1);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x1:
      FUN_60008a10(0x38,2);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x2:
      FUN_60008a10(0x38,3);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x3:
      FUN_60008a10(0x38,4);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x4:
      FUN_60008a10(0x38,5);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x5:
      FUN_60008a10(0x38,6);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x6:
      FUN_60008a10(0x38,7);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x7:
      FUN_60008a10(0x38,8);
      pfVar10 = (float *)0x1;
      break;
    default:
      goto switchD_60004207_default;
    }
    break;
  case 0x34:
    if (DAT_6005ab48 == 0.0) {
      return (float *)0x0;
    }
    switch(param_2) {
    case (float *)0x0:
      FUN_60008a10(0x35,1);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x1:
      FUN_60008a10(0x35,2);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x2:
      FUN_60008a10(0x35,3);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x3:
      FUN_60008a10(0x35,4);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x4:
      FUN_60008a10(0x35,5);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x5:
      FUN_60008a10(0x35,6);
      pfVar10 = (float *)0x1;
      break;
    default:
      goto switchD_60004207_default;
    case (float *)0x7:
      FUN_60008a10(0x35,7);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x8:
      FUN_60008a10(0x35,8);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x35:
    if (DAT_6005ab48 == 0.0) {
      return (float *)0x0;
    }
    switch(param_2) {
    case (float *)0x0:
      FUN_60008a10(0x36,1);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x1:
      FUN_60008a10(0x36,2);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x2:
      FUN_60008a10(0x36,3);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x3:
      FUN_60008a10(0x36,4);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x4:
      FUN_60008a10(0x36,5);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x5:
      FUN_60008a10(0x36,6);
      pfVar10 = (float *)0x1;
      break;
    default:
      goto switchD_60004207_default;
    case (float *)0x7:
      FUN_60008a10(0x36,7);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x8:
      FUN_60008a10(0x36,8);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x36:
    if (DAT_6005ab48 == 0.0) {
      return (float *)0x0;
    }
    switch(param_2) {
    case (float *)0x0:
      FUN_60008a10(0x37,1);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x1:
      FUN_60008a10(0x37,2);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x2:
      FUN_60008a10(0x37,3);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x3:
      FUN_60008a10(0x37,4);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x4:
      FUN_60008a10(0x37,5);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x5:
      FUN_60008a10(0x37,6);
      pfVar10 = (float *)0x1;
      break;
    default:
      goto switchD_60004207_default;
    case (float *)0x7:
      FUN_60008a10(0x37,7);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x8:
      FUN_60008a10(0x37,8);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x38:
  case 0x68:
    switch(param_2) {
    case (float *)0x0:
      uVar13 = 5;
      goto LAB_60004aab;
    case (float *)0x1:
      if ((DAT_60058d78 == 1) || (DAT_60058d78 == 3)) {
        FUN_60008a10(0x13,2);
        FUN_60008a10(0x14,2);
        pfVar10 = (float *)0x1;
      }
      else {
        FUN_60008a10(0x13,5);
        FUN_60008a10(0x14,2);
        pfVar10 = (float *)0x1;
      }
      break;
    case (float *)0x2:
      uVar13 = 1;
LAB_60004aab:
      FUN_60008a10(0x13,uVar13);
      FUN_60008a10(0x14,6);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x3:
      FUN_60008a10(0x13,9);
      FUN_60008a10(0x14,1);
      pfVar10 = (float *)0x1;
      break;
    default:
      goto switchD_60003d5d_caseD_0;
    }
    break;
  case 0x39:
  case 0x6a:
    if (param_2 == (float *)0x0) {
      FUN_60008a10(0xe,0);
      pfVar10 = (float *)0x1;
    }
    else {
      FUN_60008a10(0xe,1);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x3c:
  case 0x67:
    if (DAT_6005ab04 == 0.0) {
      return (float *)0x0;
    }
    DAT_600170d0 = 0x1000000;
    DAT_600170cc = 1;
    if (param_2 != (float *)0x0) goto switchD_60004207_default;
    DAT_600170cc = 9;
    pfVar10 = (float *)0x1;
    break;
  case 0x3f:
    iVar9 = ftol();
    if ((((iVar9 != 0) && (iVar9 = ftol(), iVar9 != 0)) && (iVar9 = ftol(), iVar9 != 0)) &&
       ((iVar9 = ftol(), fVar14 = DAT_6005ab90, iVar9 != 0 && (param_2 != (float *)0x0)))) {
      *param_2 = DAT_6005ab8c;
      fVar2 = DAT_6005ab94;
      param_2[1] = fVar14;
      fVar14 = DAT_6005ab98;
      param_2[2] = fVar2;
      param_2[3] = fVar14;
      return (float *)0x1;
    }
    return (float *)0x0;
  case 0x40:
    if (*(int *)(&DAT_6005abe0 + (int)param_2 * 4) == 0) {
      return (float *)0x0;
    }
    switch(param_2) {
    case (float *)0x0:
      DAT_600170d8 = 1;
      FUN_60008a10(0x19,1);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x1:
      DAT_600170d8 = 2;
      FUN_60008a10(0x19,2);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x2:
      DAT_600170d8 = 3;
      FUN_60008a10(0x19,3);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x3:
      DAT_600170d8 = 4;
      FUN_60008a10(0x19,4);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x4:
      DAT_600170d8 = 5;
      FUN_60008a10(0x19,5);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x5:
      DAT_600170d8 = 6;
      FUN_60008a10(0x19,6);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x6:
      DAT_600170d8 = 7;
      FUN_60008a10(0x19,7);
      pfVar10 = (float *)0x1;
      break;
    case (float *)0x7:
      DAT_600170d8 = 8;
      FUN_60008a10(0x19,8);
      pfVar10 = (float *)0x1;
      break;
    default:
      goto switchD_60004207_default;
    }
    break;
  case 0x41:
    if (DAT_6005ab54 == 0.0) {
      return (float *)0x0;
    }
    if (param_2 == (float *)0x0) {
      FUN_600089d0(iVar9,0xd,3);
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x1) {
      FUN_600089d0(iVar9,0xd,1);
      pfVar10 = param_2;
    }
    else {
      if (param_2 != (float *)0x2) {
        return (float *)0x0;
      }
      FUN_600089d0(iVar9,0xd,2);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x42:
    if (DAT_6005ab54 == 0.0) {
      return (float *)0x0;
    }
    if (param_2 == (float *)0x0) {
      FUN_600089d0(iVar9,0xe,3);
      pfVar10 = (float *)0x1;
    }
    else if (param_2 == (float *)0x1) {
      FUN_600089d0(iVar9,0xe,1);
      pfVar10 = param_2;
    }
    else {
      if (param_2 != (float *)0x2) {
        return (float *)0x0;
      }
      FUN_600089d0(iVar9,0xe,2);
      pfVar10 = (float *)0x1;
    }
    break;
  case 0x43:
    DAT_600170e0 = param_2;
    pfVar10 = (float *)0x1;
    break;
  case 0x44:
    FUN_600089d0(iVar9,0xb,param_2);
    return (float *)0x0;
  case 0x45:
    goto switchD_60003d5d_caseD_45;
  }
LAB_60006a14:
  FUN_60001e70(local_f0,param_2);
switchD_60003d5d_caseD_0:
  return pfVar10;
}



/* VA 60006e50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60006e50(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  undefined4 local_8;
  undefined1 local_4;

  if (param_1 != 0) {
    local_8 = 0;
    do {
      fVar2 = (float)local_8 * _DAT_60015438 * _DAT_60015458;
      iVar1 = (int)ROUND(fVar2);
      fVar2 = fVar2 - (float)iVar1;
      if (fVar2 <= (float)_DAT_60015450) {
        local_4 = *(char *)(iVar1 + param_1);
      }
      else {
        local_4 = (char)(int)ROUND((float)*(byte *)(iVar1 + param_1) +
                                   (float)(int)((uint)*(byte *)(iVar1 + 1 + param_1) -
                                               (uint)*(byte *)(iVar1 + param_1)) * fVar2);
      }
      *(char *)(local_8 + param_2) = -1 - local_4;
      local_8 = local_8 + 1;
    } while (local_8 < 0x100);
  }
  return;
}



/* VA 60006f10 */

void FUN_60006f10(void)

{
  if (0 < DAT_60058874) {
    FUN_60006f20();
    return;
  }
  return;
}



/* VA 60006f20 */

void FUN_60006f20(void)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;

  if ((DAT_60058874 != 0) && (DAT_60058878 != 0)) {
    if (DAT_6001822c == 0) {
      FUN_60008810();
    }
    puVar1 = PTR_DAT_60017108;
    iVar2 = DAT_60058874;
    puVar3 = PTR_DAT_60017114;
    iVar4 = DAT_60058878;
    uVar5 = DAT_60058870;
    FUN_6000d580((float *)PTR_DAT_60017108,DAT_60058874);
    (**(code **)(*DAT_60058d9c + 0x68))
              (DAT_60058d9c,DAT_60017104,DAT_600170f0,puVar1,iVar2,puVar3,iVar4,uVar5);
    DAT_60058874 = 0;
    DAT_60058878 = 0;
  }
  return;
}



/* VA 60006fa0 */

void __cdecl FUN_60006fa0(int param_1)

{
  FUN_60006f10();
  DAT_60017100 = (int)(0x8000 / (longlong)DAT_600170fc);
  if (param_1 != 0) {
    PTR_DAT_60017108 = PTR_DAT_6001710c;
    return;
  }
  PTR_DAT_60017108 = PTR_DAT_60017110;
  return;
}



/* VA 60006fe0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60006fe0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;

  if (DAT_60017104 != 4) {
    FUN_60006f20();
  }
  DAT_60017104 = 4;
  if (DAT_60017100 + -3 < DAT_60058874) {
    FUN_60006f20();
  }
  iVar5 = DAT_60058874;
  uVar6 = DAT_600170fc;
  fVar1 = (float)param_1[2];
  puVar4 = (undefined4 *)(PTR_DAT_60017108 + DAT_600170fc * DAT_60058874);
  uVar2 = *param_1;
  puVar4[2] = fVar1;
  *puVar4 = uVar2;
  puVar4[1] = param_1[1];
  puVar4[3] = param_1[3];
  puVar4[4] = param_1[4];
  puVar4[5] = param_1[5];
  puVar4[6] = param_1[6];
  puVar4[7] = param_1[7];
  if (0x20 < uVar6) {
    uVar2 = param_1[9];
    puVar4[8] = param_1[8];
    puVar4[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  puVar4[2] = fVar1;
  if (DAT_600170ec == 0) {
    puVar4[4] = 0xffffffff;
  }
  uVar3 = DAT_600170fc;
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar4[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
    iVar5 = DAT_60058874;
    uVar6 = uVar3;
  }
  *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar5;
  DAT_60058878 = DAT_60058878 + 1;
  iVar5 = iVar5 + 1;
  puVar4 = (undefined4 *)(PTR_DAT_60017108 + uVar6 * iVar5);
  *puVar4 = *param_2;
  fVar1 = (float)param_2[2];
  puVar4[1] = param_2[1];
  puVar4[2] = fVar1;
  puVar4[3] = param_2[3];
  puVar4[4] = param_2[4];
  puVar4[5] = param_2[5];
  puVar4[6] = param_2[6];
  DAT_60058874 = iVar5;
  puVar4[7] = param_2[7];
  if (0x20 < uVar6) {
    uVar2 = param_2[9];
    puVar4[8] = param_2[8];
    puVar4[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  puVar4[2] = fVar1;
  if (DAT_600170ec == 0) {
    puVar4[4] = 0xffffffff;
  }
  uVar3 = DAT_600170fc;
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar4[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
    iVar5 = DAT_60058874;
    uVar6 = uVar3;
  }
  *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar5;
  DAT_60058878 = DAT_60058878 + 1;
  iVar5 = iVar5 + 1;
  puVar4 = (undefined4 *)(PTR_DAT_60017108 + uVar6 * iVar5);
  *puVar4 = *param_3;
  fVar1 = (float)param_3[2];
  puVar4[1] = param_3[1];
  puVar4[2] = fVar1;
  puVar4[3] = param_3[3];
  puVar4[4] = param_3[4];
  puVar4[5] = param_3[5];
  puVar4[6] = param_3[6];
  DAT_60058874 = iVar5;
  puVar4[7] = param_3[7];
  if (0x20 < uVar6) {
    uVar2 = param_3[9];
    puVar4[8] = param_3[8];
    puVar4[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  puVar4[2] = fVar1;
  if (DAT_600170ec == 0) {
    puVar4[4] = 0xffffffff;
  }
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar4[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
    iVar5 = DAT_60058874;
  }
  *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar5;
  DAT_60058878 = DAT_60058878 + 1;
  DAT_60058874 = iVar5 + 1;
  return;
}



/* VA 600072a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_600072a0(int param_1,ushort *param_2,int param_3)

{
  float fVar1;
  float *pfVar2;
  undefined4 *puVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  int local_10;

  if (DAT_60017104 != 4) {
    FUN_60006f20();
  }
  DAT_60017104 = 4;
  if (0 < param_3) {
    local_10 = param_3;
    uVar8 = DAT_600170fc;
    iVar9 = DAT_60017130;
    iVar11 = DAT_60058874;
    do {
      if (DAT_60017100 + -3 < iVar11) {
        FUN_60006f20();
        uVar8 = DAT_600170fc;
        iVar9 = DAT_60017130;
        iVar11 = DAT_60058874;
      }
      pfVar2 = (float *)(param_2[iVar9] * uVar8 + param_1);
      pfVar10 = (float *)(*(ushort *)(iVar9 + (int)param_2) * uVar8 + param_1);
      pfVar4 = (float *)(*param_2 * uVar8 + param_1);
      if ((DAT_60058e1c == 1) ||
         (((uint)((*pfVar10 - *pfVar4) * (pfVar2[1] - pfVar4[1]) -
                 (*pfVar2 - *pfVar4) * (pfVar10[1] - pfVar4[1])) & 0x80000000) != DAT_60058e1c)) {
        pfVar2 = (float *)(PTR_DAT_60017108 + uVar8 * iVar11);
        *pfVar2 = *pfVar4;
        pfVar2[1] = pfVar4[1];
        pfVar2[2] = pfVar4[2];
        pfVar2[3] = pfVar4[3];
        pfVar2[4] = pfVar4[4];
        pfVar2[5] = pfVar4[5];
        pfVar2[6] = pfVar4[6];
        pfVar2[7] = pfVar4[7];
        if (0x20 < uVar8) {
          pfVar2[8] = pfVar4[8];
          pfVar2[9] = pfVar4[9];
        }
        fVar1 = _DAT_6001885c + pfVar2[2];
        pfVar2[2] = fVar1;
        if (DAT_600170ec == 0) {
          pfVar2[4] = -NAN;
        }
        iVar5 = DAT_60017130;
        if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
          pfVar2[5] = (float)((uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] <<
                             0x18);
          uVar8 = DAT_600170fc;
          iVar9 = iVar5;
          iVar11 = DAT_60058874;
        }
        *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar11;
        DAT_60058878 = DAT_60058878 + 1;
        iVar11 = iVar11 + 1;
        puVar3 = (undefined4 *)(PTR_DAT_60017108 + uVar8 * iVar11);
        iVar5 = *(ushort *)(iVar9 + (int)param_2) * uVar8;
        iVar6 = iVar5 + param_1;
        DAT_60058874 = iVar11;
        *puVar3 = *(undefined4 *)(iVar5 + param_1);
        puVar3[1] = *(undefined4 *)(iVar6 + 4);
        puVar3[2] = *(undefined4 *)(iVar6 + 8);
        puVar3[3] = *(undefined4 *)(iVar6 + 0xc);
        puVar3[4] = *(undefined4 *)(iVar6 + 0x10);
        puVar3[5] = *(undefined4 *)(iVar6 + 0x14);
        puVar3[6] = *(undefined4 *)(iVar6 + 0x18);
        puVar3[7] = *(undefined4 *)(iVar6 + 0x1c);
        if (0x20 < uVar8) {
          puVar3[8] = *(undefined4 *)(iVar6 + 0x20);
          puVar3[9] = *(undefined4 *)(iVar6 + 0x24);
        }
        fVar1 = _DAT_6001885c + (float)puVar3[2];
        puVar3[2] = fVar1;
        if (DAT_600170ec == 0) {
          puVar3[4] = 0xffffffff;
        }
        iVar5 = DAT_60017130;
        if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
          puVar3[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
          uVar8 = DAT_600170fc;
          iVar9 = iVar5;
          iVar11 = DAT_60058874;
        }
        *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar11;
        DAT_60058878 = DAT_60058878 + 1;
        iVar11 = iVar11 + 1;
        puVar3 = (undefined4 *)(PTR_DAT_60017108 + uVar8 * iVar11);
        puVar7 = (undefined4 *)(param_2[iVar9] * uVar8 + param_1);
        DAT_60058874 = iVar11;
        *puVar3 = *puVar7;
        puVar3[1] = puVar7[1];
        puVar3[2] = puVar7[2];
        puVar3[3] = puVar7[3];
        puVar3[4] = puVar7[4];
        puVar3[5] = puVar7[5];
        puVar3[6] = puVar7[6];
        puVar3[7] = puVar7[7];
        if (0x20 < uVar8) {
          puVar3[8] = puVar7[8];
          puVar3[9] = puVar7[9];
        }
        fVar1 = _DAT_6001885c + (float)puVar3[2];
        puVar3[2] = fVar1;
        if (DAT_600170ec == 0) {
          puVar3[4] = 0xffffffff;
        }
        iVar5 = DAT_60017130;
        if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
          puVar3[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
          uVar8 = DAT_600170fc;
          iVar9 = iVar5;
          iVar11 = DAT_60058874;
        }
        *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar11;
        DAT_60058878 = DAT_60058878 + 1;
        iVar11 = iVar11 + 1;
        DAT_60058874 = iVar11;
      }
      param_2 = (ushort *)(iVar9 * 3 + (int)param_2);
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  return;
}



/* VA 60007650 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60007650(int param_1,ushort *param_2,int param_3)

{
  float fVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  short sVar7;
  float *pfVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_18;

  if (DAT_60017104 != 4) {
    FUN_60006f20();
  }
  DAT_60017104 = 4;
  if (0 < param_3) {
    local_18 = param_3;
    uVar10 = DAT_600170fc;
    iVar11 = DAT_60017130;
    iVar15 = DAT_60058874;
    do {
      if (DAT_60017100 + -4 < iVar15) {
        FUN_60006f20();
        uVar10 = DAT_600170fc;
        iVar11 = DAT_60017130;
        iVar15 = DAT_60058874;
      }
      pfVar5 = (float *)(param_2[iVar11] * uVar10 + param_1);
      pfVar12 = (float *)(*(ushort *)(iVar11 + (int)param_2) * uVar10 + param_1);
      pfVar8 = (float *)(*param_2 * uVar10 + param_1);
      if ((DAT_60058e1c == 1) ||
         (((uint)((*pfVar12 - *pfVar8) * (pfVar5[1] - pfVar8[1]) -
                 (*pfVar5 - *pfVar8) * (pfVar12[1] - pfVar8[1])) & 0x80000000) != DAT_60058e1c)) {
        pfVar5 = (float *)(PTR_DAT_60017108 + uVar10 * iVar15);
        *pfVar5 = *pfVar8;
        pfVar5[1] = pfVar8[1];
        pfVar5[2] = pfVar8[2];
        pfVar5[3] = pfVar8[3];
        pfVar5[4] = pfVar8[4];
        pfVar5[5] = pfVar8[5];
        pfVar5[6] = pfVar8[6];
        pfVar5[7] = pfVar8[7];
        if (0x20 < uVar10) {
          pfVar5[8] = pfVar8[8];
          pfVar5[9] = pfVar8[9];
        }
        fVar1 = _DAT_6001885c + pfVar5[2];
        pfVar5[2] = fVar1;
        if (DAT_600170ec == 0) {
          pfVar5[4] = -NAN;
        }
        iVar13 = DAT_60017130;
        iVar14 = iVar15;
        if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
          pfVar5[5] = (float)((uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] <<
                             0x18);
          uVar10 = DAT_600170fc;
          iVar11 = iVar13;
          iVar14 = DAT_60058874;
        }
        iVar13 = DAT_60058878;
        iVar14 = iVar14 + 1;
        puVar6 = (undefined4 *)(PTR_DAT_60017108 + uVar10 * iVar14);
        puVar9 = (undefined4 *)(*(ushort *)(iVar11 + (int)param_2) * uVar10 + param_1);
        DAT_60058874 = iVar14;
        *puVar6 = *puVar9;
        puVar6[1] = puVar9[1];
        puVar6[2] = puVar9[2];
        puVar6[3] = puVar9[3];
        puVar6[4] = puVar9[4];
        puVar6[5] = puVar9[5];
        puVar6[6] = puVar9[6];
        puVar6[7] = puVar9[7];
        if (0x20 < uVar10) {
          puVar6[8] = puVar9[8];
          puVar6[9] = puVar9[9];
        }
        fVar1 = _DAT_6001885c + (float)puVar6[2];
        puVar6[2] = fVar1;
        if (DAT_600170ec == 0) {
          puVar6[4] = 0xffffffff;
        }
        iVar4 = DAT_60058878;
        iVar3 = DAT_60017130;
        if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
          puVar6[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
          uVar10 = DAT_600170fc;
          iVar11 = iVar3;
          iVar13 = iVar4;
          iVar14 = DAT_60058874;
        }
        iVar14 = iVar14 + 1;
        puVar6 = (undefined4 *)(PTR_DAT_60017108 + uVar10 * iVar14);
        puVar9 = (undefined4 *)(param_2[iVar11] * uVar10 + param_1);
        DAT_60058874 = iVar14;
        *puVar6 = *puVar9;
        puVar6[1] = puVar9[1];
        puVar6[2] = puVar9[2];
        puVar6[3] = puVar9[3];
        puVar6[4] = puVar9[4];
        puVar6[5] = puVar9[5];
        puVar6[6] = puVar9[6];
        puVar6[7] = puVar9[7];
        if (0x20 < uVar10) {
          puVar6[8] = puVar9[8];
          puVar6[9] = puVar9[9];
        }
        fVar1 = _DAT_6001885c + (float)puVar6[2];
        puVar6[2] = fVar1;
        if (DAT_600170ec == 0) {
          puVar6[4] = 0xffffffff;
        }
        iVar4 = DAT_60058878;
        iVar3 = DAT_60017130;
        if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
          puVar6[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
          uVar10 = DAT_600170fc;
          iVar11 = iVar3;
          iVar13 = iVar4;
          iVar14 = DAT_60058874;
        }
        iVar14 = iVar14 + 1;
        puVar6 = (undefined4 *)(PTR_DAT_60017108 + uVar10 * iVar14);
        puVar9 = (undefined4 *)(*(ushort *)((int)param_2 + iVar11 * 3) * uVar10 + param_1);
        DAT_60058874 = iVar14;
        *puVar6 = *puVar9;
        puVar6[1] = puVar9[1];
        puVar6[2] = puVar9[2];
        puVar6[3] = puVar9[3];
        puVar6[4] = puVar9[4];
        puVar6[5] = puVar9[5];
        puVar6[6] = puVar9[6];
        puVar6[7] = puVar9[7];
        if (0x20 < uVar10) {
          puVar6[8] = puVar9[8];
          puVar6[9] = puVar9[9];
        }
        fVar1 = _DAT_6001885c + (float)puVar6[2];
        puVar6[2] = fVar1;
        if (DAT_600170ec == 0) {
          puVar6[4] = 0xffffffff;
        }
        iVar3 = DAT_60017130;
        if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
          puVar6[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
          uVar10 = DAT_600170fc;
          iVar11 = iVar3;
          iVar13 = DAT_60058878;
          iVar14 = DAT_60058874;
        }
        puVar2 = PTR_DAT_60017114;
        sVar7 = (short)iVar15;
        *(short *)(PTR_DAT_60017114 + iVar13 * 2) = sVar7;
        iVar15 = iVar14 + 1;
        *(short *)(puVar2 + (iVar13 + 1) * 2) = sVar7 + 1;
        *(short *)(puVar2 + (iVar13 + 2) * 2) = sVar7 + 2;
        *(short *)(puVar2 + (iVar13 + 3) * 2) = sVar7;
        *(short *)(puVar2 + (iVar13 + 4) * 2) = sVar7 + 2;
        *(short *)(puVar2 + (iVar13 + 5) * 2) = sVar7 + 3;
        DAT_60058878 = iVar13 + 6;
        DAT_60058874 = iVar15;
      }
      param_2 = param_2 + iVar11 * 2;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
  }
  return;
}



/* VA 60007af0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_60007af0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  float fVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  short sVar8;
  bool bVar9;

  if (DAT_60017104 != 4) {
    FUN_60006f20();
  }
  DAT_60017104 = 4;
  if (DAT_60017100 + -4 < DAT_60058874) {
    FUN_60006f20();
  }
  iVar4 = DAT_60058874;
  puVar3 = PTR_DAT_60017108;
  uVar7 = DAT_600170fc;
  fVar1 = (float)param_1[2];
  uVar2 = *param_1;
  iVar5 = DAT_600170fc * DAT_60058874;
  *(float *)(PTR_DAT_60017108 + iVar5 + 8) = fVar1;
  puVar6 = (undefined4 *)(puVar3 + iVar5);
  *puVar6 = uVar2;
  puVar6[1] = param_1[1];
  puVar6[3] = param_1[3];
  puVar6[4] = param_1[4];
  puVar6[5] = param_1[5];
  puVar6[6] = param_1[6];
  puVar6[7] = param_1[7];
  if (0x20 < uVar7) {
    uVar2 = param_1[9];
    puVar6[8] = param_1[8];
    puVar6[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  puVar6[2] = fVar1;
  if (DAT_600170ec == 0) {
    puVar6[4] = 0xffffffff;
  }
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar6[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
    uVar7 = DAT_600170fc;
  }
  DAT_60058874 = DAT_60058874 + 1;
  puVar6 = (undefined4 *)(PTR_DAT_60017108 + uVar7 * DAT_60058874);
  *puVar6 = *param_2;
  fVar1 = (float)param_2[2];
  puVar6[1] = param_2[1];
  puVar6[2] = fVar1;
  puVar6[3] = param_2[3];
  puVar6[4] = param_2[4];
  puVar6[5] = param_2[5];
  puVar6[6] = param_2[6];
  puVar6[7] = param_2[7];
  if (0x20 < uVar7) {
    uVar2 = param_2[9];
    puVar6[8] = param_2[8];
    puVar6[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  puVar6[2] = fVar1;
  if (DAT_600170ec == 0) {
    puVar6[4] = 0xffffffff;
  }
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar6[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
    uVar7 = DAT_600170fc;
  }
  DAT_60058874 = DAT_60058874 + 1;
  puVar6 = (undefined4 *)(PTR_DAT_60017108 + uVar7 * DAT_60058874);
  *puVar6 = *param_3;
  fVar1 = (float)param_3[2];
  puVar6[1] = param_3[1];
  puVar6[2] = fVar1;
  puVar6[3] = param_3[3];
  puVar6[4] = param_3[4];
  puVar6[5] = param_3[5];
  puVar6[6] = param_3[6];
  puVar6[7] = param_3[7];
  if (0x20 < uVar7) {
    uVar2 = param_3[9];
    puVar6[8] = param_3[8];
    puVar6[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  puVar6[2] = fVar1;
  if (DAT_600170ec == 0) {
    puVar6[4] = 0xffffffff;
  }
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar6[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
    uVar7 = DAT_600170fc;
  }
  DAT_60058874 = DAT_60058874 + 1;
  puVar6 = (undefined4 *)(PTR_DAT_60017108 + uVar7 * DAT_60058874);
  *puVar6 = *param_4;
  fVar1 = (float)param_4[2];
  puVar6[1] = param_4[1];
  puVar6[2] = fVar1;
  puVar6[3] = param_4[3];
  puVar6[4] = param_4[4];
  puVar6[5] = param_4[5];
  puVar6[6] = param_4[6];
  puVar6[7] = param_4[7];
  if (0x20 < uVar7) {
    uVar2 = param_4[9];
    puVar6[8] = param_4[8];
    puVar6[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  bVar9 = DAT_600170ec == 0;
  puVar6[2] = fVar1;
  if (bVar9) {
    puVar6[4] = 0xffffffff;
  }
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar6[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
  }
  puVar3 = PTR_DAT_60017114;
  sVar8 = (short)iVar4;
  *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = sVar8;
  DAT_60058874 = DAT_60058874 + 1;
  *(short *)(puVar3 + (DAT_60058878 + 1) * 2) = sVar8 + 1;
  *(short *)(puVar3 + (DAT_60058878 + 2) * 2) = sVar8 + 2;
  *(short *)(puVar3 + (DAT_60058878 + 2) * 2 + 2) = sVar8;
  *(short *)(puVar3 + (DAT_60058878 + 4) * 2) = sVar8 + 2;
  *(short *)(puVar3 + (DAT_60058878 + 5) * 2) = sVar8 + 3;
  DAT_60058878 = DAT_60058878 + 6;
  return;
}



/* VA 60007e60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_60007e60(int param_1,int param_2,undefined4 param_3,ushort *param_4)

{
  float fVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;

  if (DAT_60017104 != 5) {
    FUN_60006f20();
  }
  DAT_60017104 = 5;
  if ((DAT_60017100 - param_2) + 3 < (int)DAT_60058874) {
    FUN_60006f20();
  }
  uVar7 = DAT_60058874;
  uVar8 = DAT_600170fc;
  if (0 < (int)DAT_60058874) {
    puVar3 = (undefined4 *)(PTR_DAT_60017108 + DAT_600170fc * DAT_60058874);
    puVar4 = (undefined4 *)(PTR_DAT_60017108 + (DAT_60058874 - 1) * DAT_600170fc);
    *puVar3 = *puVar4;
    puVar3[1] = puVar4[1];
    puVar3[2] = puVar4[2];
    puVar3[3] = puVar4[3];
    puVar3[4] = puVar4[4];
    puVar3[5] = puVar4[5];
    puVar3[6] = puVar4[6];
    puVar3[7] = puVar4[7];
    if (0x20 < uVar8) {
      puVar3[8] = puVar4[8];
      puVar3[9] = puVar4[9];
    }
    fVar1 = _DAT_6001885c + (float)puVar3[2];
    puVar3[2] = fVar1;
    if (DAT_600170ec == 0) {
      puVar3[4] = 0xffffffff;
    }
    uVar2 = DAT_600170fc;
    if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
      puVar3[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
      uVar7 = DAT_60058874;
      uVar8 = uVar2;
    }
    *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)uVar7;
    DAT_60058878 = DAT_60058878 + 1;
    iVar6 = uVar7 + 1;
    puVar3 = (undefined4 *)(PTR_DAT_60017108 + uVar8 * iVar6);
    iVar5 = *param_4 * uVar8 + param_1;
    DAT_60058874 = iVar6;
    *puVar3 = *(undefined4 *)(*param_4 * uVar8 + param_1);
    puVar3[1] = *(undefined4 *)(iVar5 + 4);
    puVar3[2] = *(undefined4 *)(iVar5 + 8);
    puVar3[3] = *(undefined4 *)(iVar5 + 0xc);
    puVar3[4] = *(undefined4 *)(iVar5 + 0x10);
    puVar3[5] = *(undefined4 *)(iVar5 + 0x14);
    puVar3[6] = *(undefined4 *)(iVar5 + 0x18);
    puVar3[7] = *(undefined4 *)(iVar5 + 0x1c);
    if (0x20 < uVar8) {
      puVar3[8] = *(undefined4 *)(iVar5 + 0x20);
      puVar3[9] = *(undefined4 *)(iVar5 + 0x24);
    }
    fVar1 = _DAT_6001885c + (float)puVar3[2];
    puVar3[2] = fVar1;
    if (DAT_600170ec == 0) {
      puVar3[4] = 0xffffffff;
    }
    uVar7 = DAT_600170fc;
    if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
      puVar3[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
      iVar6 = DAT_60058874;
      uVar8 = uVar7;
    }
    *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar6;
    DAT_60058878 = DAT_60058878 + 1;
    uVar7 = iVar6 + 1;
    DAT_60058874 = uVar7;
    if ((uVar7 & 1) != 0) {
      puVar3 = (undefined4 *)(PTR_DAT_60017108 + uVar8 * uVar7);
      iVar6 = *param_4 * uVar8 + param_1;
      *puVar3 = *(undefined4 *)(*param_4 * uVar8 + param_1);
      puVar3[1] = *(undefined4 *)(iVar6 + 4);
      puVar3[2] = *(undefined4 *)(iVar6 + 8);
      puVar3[3] = *(undefined4 *)(iVar6 + 0xc);
      puVar3[4] = *(undefined4 *)(iVar6 + 0x10);
      puVar3[5] = *(undefined4 *)(iVar6 + 0x14);
      puVar3[6] = *(undefined4 *)(iVar6 + 0x18);
      puVar3[7] = *(undefined4 *)(iVar6 + 0x1c);
      if (0x20 < uVar8) {
        puVar3[8] = *(undefined4 *)(iVar6 + 0x20);
        puVar3[9] = *(undefined4 *)(iVar6 + 0x24);
      }
      fVar1 = _DAT_6001885c + (float)puVar3[2];
      puVar3[2] = fVar1;
      if (DAT_600170ec == 0) {
        puVar3[4] = 0xffffffff;
      }
      uVar2 = DAT_600170fc;
      if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
        puVar3[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
        uVar7 = DAT_60058874;
        uVar8 = uVar2;
      }
      *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)uVar7;
      DAT_60058878 = DAT_60058878 + 1;
      DAT_60058874 = uVar7 + 1;
    }
  }
  if (0 < param_2) {
    do {
      uVar7 = DAT_60058874;
      puVar3 = (undefined4 *)(PTR_DAT_60017108 + uVar8 * DAT_60058874);
      puVar4 = (undefined4 *)(*param_4 * uVar8 + param_1);
      *puVar3 = *puVar4;
      puVar3[1] = puVar4[1];
      puVar3[2] = puVar4[2];
      puVar3[3] = puVar4[3];
      puVar3[4] = puVar4[4];
      puVar3[5] = puVar4[5];
      puVar3[6] = puVar4[6];
      puVar3[7] = puVar4[7];
      if (0x20 < uVar8) {
        puVar3[8] = puVar4[8];
        puVar3[9] = puVar4[9];
      }
      fVar1 = _DAT_6001885c + (float)puVar3[2];
      puVar3[2] = fVar1;
      if (DAT_600170ec == 0) {
        puVar3[4] = 0xffffffff;
      }
      uVar2 = DAT_600170fc;
      if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
        puVar3[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
        uVar7 = DAT_60058874;
        uVar8 = uVar2;
      }
      *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)uVar7;
      DAT_60058878 = DAT_60058878 + 1;
      DAT_60058874 = uVar7 + 1;
      param_4 = (ushort *)((int)param_4 + DAT_60017130);
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 1;
}



/* VA 60008270 */

bool __cdecl FUN_60008270(float *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 uVar6;

  iVar4 = 0;
  FUN_60006f10();
  iVar3 = param_3 + 2;
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      (&DAT_6005ac40)[iVar2] = *(undefined2 *)(param_4 + iVar2 * 4);
      iVar1 = *(int *)(param_4 + iVar2 * 4);
      if (iVar4 < iVar1) {
        iVar4 = iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  if (DAT_6001822c == 0) {
    FUN_60008810();
  }
  puVar5 = &DAT_6005ac40;
  iVar4 = iVar4 + 1;
  uVar6 = DAT_60058870;
  FUN_6000d580(param_1,iVar4);
  iVar3 = (**(code **)(*DAT_60058d9c + 0x68))
                    (DAT_60058d9c,6,DAT_600170f0,param_1,iVar4,puVar5,iVar3,uVar6);
  return (bool)('\x01' - (iVar3 != 0));
}



/* VA 600082f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_600082f0(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;

  if (DAT_60017104 != 2) {
    FUN_60006f20();
  }
  DAT_60017104 = 2;
  if (DAT_60017100 + -2 < DAT_60058874) {
    FUN_60006f20();
  }
  iVar5 = DAT_60058874;
  uVar6 = DAT_600170fc;
  fVar1 = (float)param_1[2];
  puVar4 = (undefined4 *)(PTR_DAT_60017108 + DAT_600170fc * DAT_60058874);
  uVar2 = *param_1;
  puVar4[2] = fVar1;
  *puVar4 = uVar2;
  puVar4[1] = param_1[1];
  puVar4[3] = param_1[3];
  puVar4[4] = param_1[4];
  puVar4[5] = param_1[5];
  puVar4[6] = param_1[6];
  puVar4[7] = param_1[7];
  if (0x20 < uVar6) {
    uVar2 = param_1[9];
    puVar4[8] = param_1[8];
    puVar4[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  puVar4[2] = fVar1;
  if (DAT_600170ec == 0) {
    puVar4[4] = 0xffffffff;
  }
  uVar3 = DAT_600170fc;
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar4[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
    iVar5 = DAT_60058874;
    uVar6 = uVar3;
  }
  *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar5;
  DAT_60058878 = DAT_60058878 + 1;
  iVar5 = iVar5 + 1;
  puVar4 = (undefined4 *)(PTR_DAT_60017108 + uVar6 * iVar5);
  *puVar4 = *param_2;
  fVar1 = (float)param_2[2];
  puVar4[1] = param_2[1];
  puVar4[2] = fVar1;
  puVar4[3] = param_2[3];
  puVar4[4] = param_2[4];
  puVar4[5] = param_2[5];
  puVar4[6] = param_2[6];
  DAT_60058874 = iVar5;
  puVar4[7] = param_2[7];
  if (0x20 < uVar6) {
    uVar2 = param_2[9];
    puVar4[8] = param_2[8];
    puVar4[9] = uVar2;
  }
  fVar1 = fVar1 + _DAT_6001885c;
  puVar4[2] = fVar1;
  if (DAT_600170ec == 0) {
    puVar4[4] = 0xffffffff;
  }
  if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
    puVar4[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
    iVar5 = DAT_60058874;
  }
  *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar5;
  DAT_60058878 = DAT_60058878 + 1;
  DAT_60058874 = iVar5 + 1;
  return;
}



/* VA 600084e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_600084e0(int param_1,ushort *param_2,int param_3)

{
  float fVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int local_4;

  if (DAT_60017104 != 2) {
    FUN_60006f20();
  }
  DAT_60017104 = 2;
  if (0 < param_3) {
    local_4 = param_3;
    uVar7 = DAT_600170fc;
    do {
      if (DAT_60017100 + -2 < DAT_60058874) {
        FUN_60006f20();
        uVar7 = DAT_600170fc;
      }
      iVar6 = DAT_60058874;
      puVar3 = (undefined4 *)(PTR_DAT_60017108 + uVar7 * DAT_60058874);
      iVar4 = *param_2 * uVar7 + param_1;
      *puVar3 = *(undefined4 *)(*param_2 * uVar7 + param_1);
      puVar3[1] = *(undefined4 *)(iVar4 + 4);
      puVar3[2] = *(undefined4 *)(iVar4 + 8);
      puVar3[3] = *(undefined4 *)(iVar4 + 0xc);
      puVar3[4] = *(undefined4 *)(iVar4 + 0x10);
      puVar3[5] = *(undefined4 *)(iVar4 + 0x14);
      puVar3[6] = *(undefined4 *)(iVar4 + 0x18);
      puVar3[7] = *(undefined4 *)(iVar4 + 0x1c);
      if (0x20 < uVar7) {
        puVar3[8] = *(undefined4 *)(iVar4 + 0x20);
        puVar3[9] = *(undefined4 *)(iVar4 + 0x24);
      }
      fVar1 = _DAT_6001885c + (float)puVar3[2];
      puVar3[2] = fVar1;
      if (DAT_600170ec == 0) {
        puVar3[4] = 0xffffffff;
      }
      uVar2 = DAT_600170fc;
      if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
        puVar3[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
        iVar6 = DAT_60058874;
        uVar7 = uVar2;
      }
      iVar4 = DAT_60017130;
      *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar6;
      DAT_60058878 = DAT_60058878 + 1;
      iVar6 = iVar6 + 1;
      puVar3 = (undefined4 *)(PTR_DAT_60017108 + uVar7 * iVar6);
      iVar4 = *(ushort *)((int)param_2 + iVar4) * uVar7;
      iVar5 = iVar4 + param_1;
      DAT_60058874 = iVar6;
      *puVar3 = *(undefined4 *)(iVar4 + param_1);
      puVar3[1] = *(undefined4 *)(iVar5 + 4);
      puVar3[2] = *(undefined4 *)(iVar5 + 8);
      puVar3[3] = *(undefined4 *)(iVar5 + 0xc);
      puVar3[4] = *(undefined4 *)(iVar5 + 0x10);
      puVar3[5] = *(undefined4 *)(iVar5 + 0x14);
      puVar3[6] = *(undefined4 *)(iVar5 + 0x18);
      puVar3[7] = *(undefined4 *)(iVar5 + 0x1c);
      if (0x20 < uVar7) {
        puVar3[8] = *(undefined4 *)(iVar5 + 0x20);
        puVar3[9] = *(undefined4 *)(iVar5 + 0x24);
      }
      fVar1 = _DAT_6001885c + (float)puVar3[2];
      puVar3[2] = fVar1;
      if (DAT_600170ec == 0) {
        puVar3[4] = 0xffffffff;
      }
      uVar2 = DAT_600170fc;
      if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
        puVar3[5] = (uint)(byte)PTR_DAT_600170f8[(int)ROUND(fVar1 * _DAT_60015434)] << 0x18;
        iVar6 = DAT_60058874;
        uVar7 = uVar2;
      }
      *(short *)(PTR_DAT_60017114 + DAT_60058878 * 2) = (short)iVar6;
      DAT_60058878 = DAT_60058878 + 1;
      param_2 = param_2 + DAT_60017130;
      DAT_60058874 = iVar6 + 1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}



/* VA 60008730 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl FUN_60008730(float *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;

  if (DAT_6001822c == 0) {
    FUN_60008810();
  }
  FUN_60006f10();
  iVar2 = 0;
  iVar3 = DAT_600170fc;
  if (0 < param_2) {
    do {
      if (DAT_600170ec == 0) {
        *(undefined4 *)(iVar3 * iVar2 + 0x10 + (int)param_1) = 0xffffffff;
      }
      iVar1 = DAT_600170fc;
      if ((DAT_60018854 == 1) && (DAT_60018850 == 0x10)) {
        *(uint *)(DAT_600170fc * iVar2 + 0x14 + (int)param_1) =
             (uint)(byte)PTR_DAT_600170f8
                         [(int)ROUND(*(float *)(iVar3 * iVar2 + 8 + (int)param_1) * _DAT_60015434)]
             << 0x18;
        iVar3 = iVar1;
      }
      *(float *)(iVar3 * iVar2 + 8 + (int)param_1) =
           _DAT_6001885c + *(float *)(iVar3 * iVar2 + 8 + (int)param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  uVar4 = DAT_60058870;
  FUN_6000d580(param_1,param_2);
  iVar3 = (**(code **)(*DAT_60058d9c + 100))(DAT_60058d9c,1,DAT_600170f0,param_1,param_2,uVar4);
  return (bool)('\x01' - (iVar3 != 0));
}



/* VA 60008810 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60008810(void)

{
  int iVar1;

  _DAT_6005887c = 0xffffffff;
  _DAT_60058880 = 0;
  if (DAT_60018230 != 0) {
    _THRASH_unlockwindow_4();
  }
  iVar1 = (**(code **)(*DAT_60058d9c + 0x14))(DAT_60058d9c);
  DAT_6001822c = 1;
  if (iVar1 == 0) {
    return 1;
  }
  DAT_6001822c = 0;
  return 0;
}



/* VA 60008860 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_60008860(void)

{
  int iVar1;

  if (0 < DAT_60058874) {
    FUN_60006f20();
  }
  if (DAT_6001822c != 0) {
    _DAT_6001885c = 0;
    iVar1 = (**(code **)(*DAT_60058d9c + 0x18))(DAT_60058d9c);
    DAT_6001822c = 0;
    return iVar1 == 0;
  }
  return true;
}



/* VA 600088b0 */

bool __cdecl FUN_600088b0(uint param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  if (DAT_6001822c == 0) {
    FUN_60008810();
  }
  if (0 < DAT_60058874) {
    FUN_60006f20();
  }
  if (param_1 < 0x10) {
    if (param_1 == 0) {
      iVar1 = 0;
      if (0 < DAT_6005ab80) {
        do {
          iVar2 = (**(code **)(*DAT_60058d9c + 0x8c))(DAT_60058d9c,iVar1,0);
          iVar1 = iVar1 + 1;
        } while (iVar1 < DAT_6005ab80);
        return iVar2 == 0;
      }
    }
    else {
      if (param_1 == 1) {
        iVar2 = (**(code **)(*DAT_60058d9c + 0x8c))(DAT_60058d9c,0,0);
        return iVar2 == 0;
      }
      if (param_1 == 2) {
        iVar2 = (**(code **)(*DAT_60058d9c + 0x8c))(DAT_60058d9c,1,0);
        return iVar2 == 0;
      }
    }
  }
  else {
    iVar2 = (**(code **)(*DAT_60058d9c + 0x8c))
                      (DAT_60058d9c,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x34))
    ;
  }
  return iVar2 == 0;
}



/* VA 60008980 */

int _THRASH_settexture_4(uint param_1)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  int iVar3;

                    /* 0x8980  35  _THRASH_settexture@4 */
  uVar2 = _THRASH_getstate_4(1);
  if (DAT_60058d9c == 0) {
    return 0;
  }
  if (uVar2 == param_1) {
    iVar3 = 1;
  }
  else {
    bVar1 = FUN_600088b0(param_1);
    iVar3 = 0;
    if (CONCAT31(extraout_var,bVar1) != 0) {
      FUN_60001e70(1,param_1);
      return CONCAT31(extraout_var,bVar1);
    }
  }
  return iVar3;
}



/* VA 600089d0 */

bool __cdecl FUN_600089d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;

  if (DAT_6001822c == 0) {
    FUN_60008810();
  }
  if (0 < DAT_60058874) {
    FUN_60006f20();
  }
  iVar1 = (**(code **)(*DAT_60058d9c + 0x94))(DAT_60058d9c,param_1,param_2,param_3);
  return (bool)('\x01' - (iVar1 != 0));
}



/* VA 60008a10 */

bool __cdecl FUN_60008a10(undefined4 param_1,undefined4 param_2)

{
  int iVar1;

  if (DAT_6001822c == 0) {
    FUN_60008810();
  }
  if (0 < DAT_60058874) {
    FUN_60006f20();
  }
  iVar1 = (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,param_1,param_2);
  return (bool)('\x01' - (iVar1 != 0));
}



/* VA 60008a50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60008a50(void)

{
  int iVar1;
  WPARAM WVar2;
  int iVar3;
  tagRECT tStack_28;
  tagRECT tStack_18;

  if (DAT_60018230 != 0) {
    _THRASH_unlockwindow_4();
  }
  if (DAT_60018688 == 0) {
    if (DAT_60058d88 != 0) {
      iVar1 = (**(code **)(*DAT_60058d84 + 0x2c))(DAT_60058d84,0,DAT_600170cc);
      if (iVar1 < 0) {
        if (iVar1 != -0x7789fe3e) {
          return 0;
        }
        WVar2 = _THRASH_getstate_4(0x3a);
        if (DAT_60018864 == 0) {
          return 0;
        }
        (*DAT_600fc890)(0);
        while( true ) {
          while (iVar1 = (**(code **)(*DAT_60058d80 + 0x68))(DAT_60058d80), -1 < iVar1) {
            _THRASH_treset_0();
            iVar1 = (**(code **)(*DAT_60058d80 + 100))(DAT_60058d80);
            if (-1 < iVar1) goto LAB_60008b32;
            Sleep(1);
          }
          if (iVar1 == -0x7789fdb5) break;
          if ((iVar1 == -0x7789fdbb) || (iVar1 == -0x7789ff1f)) {
            Sleep(1);
          }
          Sleep(1);
        }
        _THRASH_setvideomode_12(WVar2,2,1);
LAB_60008b32:
        (*DAT_600fc890)(1);
        return 1;
      }
      _DAT_6001711c = 1;
    }
  }
  else {
    iVar1 = (**(code **)(*DAT_60058d84 + 0x34))(DAT_60058d84,2);
    for (iVar3 = 1000000; ((iVar1 == -0x7789fde4 || (iVar1 == -0x7789fe52)) && (iVar3 != 0));
        iVar3 = iVar3 + -1) {
      iVar1 = (**(code **)(*DAT_60058d84 + 0x34))(DAT_60058d84,2);
    }
    if (DAT_60018688 == 0) {
      GetClientRect(DAT_6007b880,&tStack_28);
      ClientToScreen(DAT_6007b880,(LPPOINT)&stack0xffffffd0);
      OffsetRect(&tStack_28,0,0);
      SetRect(&tStack_18,0,0,DAT_6005aac0,DAT_6005a934);
    }
    else {
      ClientToScreen(DAT_6007b880,(LPPOINT)&stack0xffffffd0);
      SetRect(&tStack_28,0,0,DAT_6005aac0,DAT_6005a934);
      SetRect(&tStack_18,0,0,DAT_6005aac0,DAT_6005a934);
    }
    iVar1 = (**(code **)(*DAT_60058d8c + 0x14))
                      (DAT_60058d8c,&tStack_28,DAT_60058d90,&tStack_18,DAT_600170d0,0);
    if (iVar1 == -0x7789fe3e) {
      return 0;
    }
    if (iVar1 < 0) {
      return 0;
    }
  }
  return 1;
}



/* VA 60008c80 */

bool FUN_60008c80(void)

{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  do {
    iVar1 = (**(code **)(*DAT_60058d80 + 0x68))(DAT_60058d80);
    if (iVar1 != 0) {
      Sleep(100);
    }
    iVar2 = iVar2 + 1;
    if (5000 < iVar2) {
      DAT_60058e28 = "dx7\\dx7wrap.c";
      DAT_60058e24 = 0x5c5;
      FUN_6000ba10(
                  "WARNING! STATE_RESTORESURFACES failed.  Focus/Mode not regained before timeout.\n"
                  );
    }
  } while (iVar1 != 0);
  if (iVar2 < 0x1389) {
    iVar2 = 0;
    if (DAT_60058d80 != (int *)0x0) {
      iVar2 = (**(code **)(*DAT_60058d80 + 100))(DAT_60058d80);
    }
    return -1 < iVar2;
  }
  return false;
}



/* VA 60008d00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60008d00(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_44;
  float local_40;
  float local_3c;
  float local_34;
  float local_30;
  float local_2c;

  fVar1 = (float)(param_1 >> 0x10 & 0xff) * _DAT_60015438;
  fVar2 = (float)(param_1 >> 8 & 0xff) * _DAT_60015438;
  fVar3 = (float)(param_1 & 0xff) * _DAT_60015438;
  FUN_6000bad0((undefined8 *)&local_44,0,0x44);
  DAT_60017118 = param_1;
  local_44 = fVar1;
  local_40 = fVar2;
  local_3c = fVar3;
  local_34 = fVar1;
  local_30 = fVar2;
  local_2c = fVar3;
  (**(code **)(*DAT_60058d9c + 0x40))(DAT_60058d9c,&local_44);
  return;
}



/* VA 60008dc0 */

bool __cdecl FUN_60008dc0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  byte bVar2;
  int local_10;
  int local_c;
  int local_8;
  undefined4 local_4;

  FUN_60006f10();
  bVar2 = param_5 == 0;
  if ((DAT_6005aaf4 != 0) && (DAT_60058d7c != 0)) {
    bVar2 = bVar2 | 2;
  }
  if (DAT_6005ab48 != 0) {
    bVar2 = bVar2 | 4;
  }
  if (param_3 == 0) {
    local_c = param_3;
    local_10 = param_3;
    local_4 = DAT_6005a934;
    local_8 = DAT_6005aac0;
  }
  else {
    local_10 = param_1;
    local_c = param_2;
    local_4 = param_4;
    local_8 = param_3;
  }
  iVar1 = (**(code **)(*DAT_60058d9c + 0x28))
                    (DAT_60058d9c,1,&local_10,bVar2,DAT_60017118,DAT_600170e0,0);
  return (bool)('\x01' - (iVar1 != 0));
}



/* VA 60008e70 */

void * _THRASH_talloc_20(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 unaff_retaddr;

                    /* 0x8e70  38  _THRASH_talloc@20 */
  if (DAT_60058d80 != (int *)0x0) {
    iVar1 = (**(code **)(*DAT_60058d80 + 0x68))(DAT_60058d80);
    if (-1 < iVar1) {
      pvVar2 = FUN_60009080(unaff_retaddr,param_1,param_2,param_3,param_4);
      return pvVar2;
    }
  }
  return (void *)0x0;
}



/* VA 60008eb0 */

undefined4 _THRASH_tfree_4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;

                    /* 0x8eb0  39  _THRASH_tfree@4 */
  uVar1 = 0;
  piVar3 = &DAT_60018858;
  iVar2 = DAT_60018858;
  if (DAT_60018858 != 0) {
    while (iVar2 != param_1) {
      piVar3 = (int *)(iVar2 + 0x1c);
      iVar2 = *piVar3;
      if (*piVar3 == 0) {
        return uVar1;
      }
    }
    *piVar3 = *(int *)(iVar2 + 0x1c);
    piVar3 = *(int **)(DAT_60018858 + 0x38);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    piVar3 = *(int **)(DAT_60018858 + 0x30);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    piVar3 = *(int **)(DAT_60018858 + 0x34);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* VA 60008f20 */

uint _THRASH_tupdate_12(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint unaff_retaddr;

                    /* 0x8f20  41  _THRASH_tupdate@12 */
  if (DAT_60058d80 != (int *)0x0) {
    iVar1 = (**(code **)(*DAT_60058d80 + 0x68))(DAT_60058d80);
    if ((-1 < iVar1) && (unaff_retaddr != 0)) {
      iVar1 = FUN_6000cf50(unaff_retaddr,param_1,param_2);
      return -(uint)(iVar1 != 0) & unaff_retaddr;
    }
  }
  return 0;
}



/* VA 60008f60 */

uint _THRASH_tupdaterect_36
               (longlong *param_1,longlong *param_2,undefined4 *param_3,int param_4,int param_5,
               int param_6,int param_7,uint param_8)

{
  int iVar1;

                    /* 0x8f60  42  _THRASH_tupdaterect@36 */
  if ((((param_1 != (longlong *)0x0) && (param_2 != (longlong *)0x0)) && (0 < param_6)) &&
     (0 < param_7)) {
    iVar1 = FUN_6000cd50(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    return -(uint)(iVar1 != 0) & (uint)param_1;
  }
  return 0;
}



/* VA 60008fc0 */

undefined4 _THRASH_treset_0(void)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;

                    /* 0x8fc0  40  _THRASH_treset@0 */
  DAT_60018858 = 0;
  DAT_60058884 = 0;
  if (DAT_60058d98 != 0) {
    FUN_600088b0(0);
    uVar3 = 0;
    pvVar2 = DAT_60058e2c;
    if (DAT_6001822c != 0) {
      _THRASH_flushwindow_0();
      _THRASH_sync_4(0);
      _THRASH_idle_0();
      DAT_6001822c = 0;
      uVar3 = DAT_6001822c;
      pvVar2 = DAT_60058e2c;
    }
    while (DAT_6001822c = uVar3, pvVar2 != (void *)0x0) {
      DAT_60058e2c = *(void **)((int)pvVar2 + 0x1c);
      piVar1 = *(int **)((int)pvVar2 + 0x38);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar1 = *(int **)((int)pvVar2 + 0x30);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar1 = *(int **)((int)pvVar2 + 0x34);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      FUN_60009070(pvVar2);
      uVar3 = DAT_6001822c;
      pvVar2 = DAT_60058e2c;
    }
    DAT_60058888 = 0;
    DAT_6005ac20 = 0;
    DAT_60058e2c = pvVar2;
    FUN_6000bab0();
    return 1;
  }
  return 0;
}



/* VA 60009070 */

void __cdecl FUN_60009070(void *param_1)

{
  if (param_1 != (void *)0x0) {
    FUN_6000b290(param_1);
  }
  return;
}



/* VA 60009080 */

void * __cdecl
FUN_60009080(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint param_5)

{
  undefined4 uVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;

  if (DAT_60058d80 == 0) {
    return (void *)0x0;
  }
  if (DAT_60058888 != 0) {
    return (void *)0x0;
  }
  pvVar2 = (void *)FUN_60009210();
  *(undefined4 *)((int)pvVar2 + 4) = param_1;
  uVar1 = *(undefined4 *)(&DAT_600171c8 + param_3 * 4);
  *(undefined4 *)((int)pvVar2 + 8) = param_2;
  *(undefined4 *)((int)pvVar2 + 0x24) = *(undefined4 *)(&DAT_6005a860 + param_3 * 4);
  *(undefined4 *)((int)pvVar2 + 0x20) = uVar1;
  uVar5 = param_3 & 0xff;
  *(undefined4 *)((int)pvVar2 + 0x18) = 0;
  *(uint *)((int)pvVar2 + 0xc) = uVar5;
  if (0 < (int)param_5) {
    uVar3 = param_5 & 0xffff0000;
    if ((int)uVar3 < 0x40001) {
      if (uVar3 == 0x40000) {
        *(undefined4 *)((int)pvVar2 + 0x18) = 4;
      }
      else if ((int)uVar3 < 0x20001) {
        if (uVar3 == 0x20000) {
          *(undefined4 *)((int)pvVar2 + 0x18) = 2;
        }
        else if (uVar3 == 0) {
          *(undefined4 *)((int)pvVar2 + 0x18) = 0;
        }
        else if (uVar3 == 0x10000) {
          *(undefined4 *)((int)pvVar2 + 0x18) = 1;
        }
      }
      else if (uVar3 == 0x30000) {
        *(undefined4 *)((int)pvVar2 + 0x18) = 3;
      }
    }
    else if (uVar3 == 0x50000) {
      *(undefined4 *)((int)pvVar2 + 0x18) = 5;
    }
    else if (uVar3 == 0x60000) {
      *(undefined4 *)((int)pvVar2 + 0x18) = 6;
    }
    else if (uVar3 == 0x70000) {
      *(undefined4 *)((int)pvVar2 + 0x18) = 7;
    }
    if ((param_5 & 0xffff) != 0) {
      *(uint *)((int)pvVar2 + 0x14) = (param_5 & 0xffff) + 1;
      goto LAB_60009179;
    }
  }
  *(undefined4 *)((int)pvVar2 + 0x14) = 0;
LAB_60009179:
  if ((uVar5 == 3) || (uVar5 == 7)) {
    *(undefined4 *)((int)pvVar2 + 0x2c) = 1;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
  }
  *(undefined4 *)((int)pvVar2 + 0x10) = param_4;
  *(undefined4 *)((int)pvVar2 + 0x28) = 0;
  *(undefined4 *)((int)pvVar2 + 0x30) = 0;
  *(undefined4 *)((int)pvVar2 + 0x34) = 0;
  *(undefined4 *)((int)pvVar2 + 0x38) = 0;
  *(undefined4 *)((int)pvVar2 + 0xb8) = 0;
  iVar4 = FUN_6000c790((int)pvVar2);
  if (iVar4 < 1) {
    FUN_60009070(pvVar2);
    if (iVar4 != -1) {
      DAT_60058888 = 1;
    }
    return (void *)0x0;
  }
  DAT_60058884 = DAT_60058884 + 1;
  bVar6 = DAT_6005ac20 == (void *)0x0;
  *(void **)((int)pvVar2 + 0x1c) = DAT_60058e2c;
  DAT_60058e2c = pvVar2;
  if ((bVar6) && (*(int *)((int)pvVar2 + 0x2c) == 0)) {
    DAT_6005ac20 = pvVar2;
  }
  return pvVar2;
}



/* VA 60009210 */

int FUN_60009210(void)

{
  int iVar1;

  iVar1 = FUN_6000b270(0xbc);
  if (iVar1 == 0) {
    DAT_60058e28 = "dx7\\dx7tex.c";
    DAT_60058e24 = 0x3b;
    FUN_6000ba10("D3D texture allocation ran out of memory\n");
  }
  return iVar1;
}



/* VA 60009250 */

int __cdecl FUN_60009250(int param_1,undefined4 param_2,undefined4 param_3)

{
  char *_Str;
  int iVar1;
  char local_50 [80];

  sprintf(local_50,"%s_%s",param_2,param_3);
  _Str = getenv(local_50);
  if (_Str == (char *)0x0) {
    sprintf(local_50,"THRASH_%s",param_3);
    _Str = getenv(local_50);
    if (_Str == (char *)0x0) {
      return param_1;
    }
  }
  iVar1 = atoi(_Str);
  return iVar1;
}



/* VA 600092c0 */

void __cdecl FUN_600092c0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;

  iVar2 = FUN_60009250(*param_1,param_2,"signature");
  *param_1 = iVar2;
  iVar2 = FUN_60009250(param_1[2],param_2,"version");
  param_1[2] = iVar2;
  uVar3 = FUN_60009250(param_1[3] & 1,param_2,"linewidth");
  uVar1 = param_1[3];
  uVar3 = (uVar1 ^ uVar3) & 1 ^ uVar1;
  param_1[3] = uVar3;
  iVar2 = FUN_60009250(uVar1 >> 1 & 1,param_2,"texturesquare");
  uVar3 = (iVar2 * 2 ^ uVar3) & 2 ^ uVar3;
  param_1[3] = uVar3;
  iVar2 = FUN_60009250(uVar1 >> 2 & 1,param_2,"texturewidthpowerof2");
  uVar3 = (iVar2 * 4 ^ uVar3) & 4 ^ uVar3;
  param_1[3] = uVar3;
  iVar2 = FUN_60009250(uVar1 >> 3 & 1,param_2,"textureheightpowerof2");
  uVar3 = (iVar2 * 8 ^ uVar3) & 8 ^ uVar3;
  param_1[3] = uVar3;
  iVar2 = FUN_60009250(uVar1 >> 4 & 1,param_2,"software");
  uVar3 = (iVar2 << 4 ^ uVar3) & 0x10 ^ uVar3;
  param_1[3] = uVar3;
  iVar2 = FUN_60009250(uVar1 >> 5 & 1,param_2,"windowed");
  uVar3 = (iVar2 << 5 ^ uVar3) & 0x20 ^ uVar3;
  param_1[3] = uVar3;
  iVar2 = FUN_60009250(uVar1 >> 6 & 1,param_2,"globalclut");
  uVar3 = (iVar2 << 6 ^ uVar3) & 0x40 ^ uVar3;
  param_1[3] = uVar3;
  iVar2 = FUN_60009250(uVar1 >> 7 & 1,param_2,"trilinear2pass");
  param_1[3] = (iVar2 << 7 ^ uVar3) & 0x80 ^ uVar3;
  iVar2 = FUN_60009250(param_1[4],param_2,"texturewidthmin");
  param_1[4] = iVar2;
  iVar2 = FUN_60009250(param_1[5],param_2,"texturewidthmax");
  param_1[5] = iVar2;
  iVar2 = FUN_60009250(param_1[6],param_2,"texturewidthmultiple");
  param_1[6] = iVar2;
  iVar2 = FUN_60009250(param_1[7],param_2,"textureheightmin");
  param_1[7] = iVar2;
  iVar2 = FUN_60009250(param_1[8],param_2,"textureheightmax");
  param_1[8] = iVar2;
  iVar2 = FUN_60009250(param_1[9],param_2,"textureheightmultiple");
  param_1[9] = iVar2;
  iVar2 = FUN_60009250(param_1[10],param_2,"clipalign");
  param_1[10] = iVar2;
  iVar2 = FUN_60009250(param_1[0x11],param_2,"numstages");
  param_1[0x11] = iVar2;
  iVar2 = FUN_60009250(param_1[0x1b],param_2,"subtype");
  param_1[0x1b] = iVar2;
  iVar2 = FUN_60009250(param_1[0x1c],param_2,"textureramsize");
  param_1[0x1c] = iVar2;
  iVar2 = FUN_60009250(param_1[0x1d],param_2,"textureramtype");
  param_1[0x1d] = iVar2;
  iVar2 = FUN_60009250(param_1[0x1f],param_2,"dxversion");
  param_1[0x1f] = iVar2;
  return;
}



/* VA 600094f0 */

void __cdecl FUN_600094f0(undefined4 param_1)

{
  DAT_60058d70 = param_1;
  return;
}



/* VA 60009500 */

void FUN_60009500(void)

{
  int iVar1;

  iVar1 = FUN_60009670();
  if ((iVar1 != 0) && (DAT_6001822c != 0)) {
    _THRASH_flushwindow_0();
    _THRASH_sync_4(0);
    _THRASH_idle_0();
    DAT_6001822c = 0;
  }
  if (DAT_60018698 != (int *)0x0) {
    (**(code **)(*DAT_60018698 + 8))(DAT_60018698);
    DAT_60018698 = (int *)0x0;
  }
  if (DAT_6001869c != (int *)0x0) {
    _THRASH_setstate_8(0x2e,(float *)0x3f800000);
    if (DAT_6001869c != (int *)0x0) {
      (**(code **)(*DAT_6001869c + 8))(DAT_6001869c);
      DAT_6001869c = (int *)0x0;
    }
  }
  if (DAT_60058868 != (int *)0x0) {
    (**(code **)(*DAT_60058868 + 0x10))(DAT_60058868);
    if (DAT_60058868 != (int *)0x0) {
      (**(code **)(*DAT_60058868 + 8))(DAT_60058868);
      DAT_60058868 = (int *)0x0;
    }
  }
  DAT_60058d80 = 0;
  DAT_60058d84 = 0;
  DAT_60058d88 = 0;
  DAT_60058d8c = 0;
  DAT_60058d90 = 0;
  DAT_600186cc = 0;
  DAT_600186d0 = 0;
  _THRASH_treset_0();
  if (DAT_60058d94 != (int *)0x0) {
    (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,7,0);
    (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0xe,0);
    if (DAT_60058d94 != (int *)0x0) {
      (**(code **)(*DAT_60058d94 + 8))(DAT_60058d94);
      DAT_60058d94 = (int *)0x0;
    }
  }
  if (DAT_60058da4 != (int *)0x0) {
    (**(code **)(*DAT_60058da4 + 8))(DAT_60058da4);
    DAT_60058da4 = (int *)0x0;
  }
  if (DAT_60058da0 != (int *)0x0) {
    (**(code **)(*DAT_60058da0 + 8))(DAT_60058da0);
    DAT_60058da0 = (int *)0x0;
  }
  if (DAT_60058d9c != (int *)0x0) {
    (**(code **)(*DAT_60058d9c + 8))(DAT_60058d9c);
    DAT_60058d9c = (int *)0x0;
  }
  if (DAT_60058d98 != (int *)0x0) {
    (**(code **)(*DAT_60058d98 + 8))(DAT_60058d98);
    DAT_60058d98 = (int *)0x0;
  }
  DAT_60058d74 = 0;
  DAT_6001822c = 0;
  FUN_60001980();
  return;
}



/* VA 60009670 */

undefined4 FUN_60009670(void)

{
  return DAT_60058d74;
}



/* VA 60009680 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60009680(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uStack_104;
  undefined4 uStack_fc;
  int iStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  CHAR aCStack_b4 [180];

  DAT_60058d80 = DAT_600186a0;
  DAT_60058d88 = DAT_600186a8;
  DAT_60058d8c = DAT_600186b0;
  DAT_60058d84 = DAT_600186a4;
  DAT_60058d90 = DAT_600186b4;
  (**(code **)*DAT_600186a4)();
  uVar1 = (**(code **)*DAT_60058d80)();
  if (uVar1 != 0) {
    DAT_60058e28 = "dx7\\dx7dev.c";
    DAT_60058e24 = 0x1d0;
    FUN_60003a20(uVar1);
    FUN_6000ba10(
                "DX7DEV.C DX7_createD3D() Creation of IDirect3D7 failed.\nCheck DX7 installed.\n (%s)\n"
                );
  }
  FUN_60009f50();
  puVar6 = &DAT_60058b00;
  for (iVar4 = 0x3b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar2 = &DAT_60058890;
  for (iVar4 = 0x3b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  iVar4 = (**(code **)(*DAT_60058d9c + 0xc))(DAT_60058d9c);
  if (iVar4 != 0) {
    DAT_60058e28 = "dx7\\dx7dev.c";
    DAT_60058e24 = 0x1de;
    FUN_6000ba10("D3DDEV.C DX7_createD3D() GetCaps of IDirect3D3 Failed\n");
  }
  DAT_6005aae0 = (uint)((DAT_60058b00 & 0x80000) != 0);
  if ((DAT_60058b00 & 0x4000) != 0) {
    DAT_600fc830 = DAT_600fc830 / (int)(uint)DAT_60058bba;
  }
  DAT_6005abd4 = (uint)((DAT_60058b00 & 0x40) != 0);
  DAT_6005abd8 = (uint)((char)DAT_60058b00 < '\0');
  DAT_6005abc4 = DAT_60058bbc;
  DAT_6005abd0 = DAT_60058bd4 >> 0x10;
  DAT_6005abcc = DAT_60058bd4 & 0xffff;
  DAT_6005ab9c = (float)DAT_60058b8c;
  if ((float)DAT_60058b8c == _DAT_60015440) {
    DAT_6005ab9c = 65535.0;
  }
  DAT_6005ab64 = DAT_60058b84;
  DAT_6005ab60 = DAT_60058b7c;
  DAT_6005ab68 = DAT_60058b80;
  DAT_6005ab6c = DAT_60058b88;
  DAT_6005ab84 = (uint)((_DAT_60058b5c & 0x20) != 0);
  bVar9 = (_DAT_60058b5c & 2) != 0;
  DAT_6005ab70 = 1;
  DAT_6005ab78 = 1;
  DAT_6005ab7c = (uint)bVar9;
  DAT_6005ab74 = (uint)bVar9;
  DAT_6005ab54 = (uint)((DAT_60058b68 & 0x10) != 0);
  _DAT_6005abe0 = (uint)((DAT_60058b48 & 1) != 0);
  _DAT_6005abe4 = (uint)((DAT_60058b48 & 2) != 0);
  _DAT_6005abe8 = (uint)((DAT_60058b48 & 4) != 0);
  _DAT_6005abec = (uint)((DAT_60058b48 & 8) != 0);
  _DAT_6005abf0 = (uint)((DAT_60058b48 & 0x10) != 0);
  _DAT_6005abf8 = (uint)((DAT_60058b48 & 0x40) != 0);
  _DAT_6005abf4 = (uint)((DAT_60058b48 & 0x20) != 0);
  _DAT_6005abfc = (uint)((char)DAT_60058b48 < '\0');
  DAT_6005aba0 = 1;
  if ((DAT_60058b54 == 0x80) || (DAT_60058b54 == 1)) {
    DAT_6005aba0 = 0;
  }
  _DAT_6005ac00 = (uint)((DAT_60058b54 & 1) != 0);
  _DAT_6005ac04 = (uint)((DAT_60058b54 & 2) != 0);
  _DAT_6005ac08 = (uint)((DAT_60058b54 & 4) != 0);
  _DAT_6005ac0c = (uint)((DAT_60058b54 & 8) != 0);
  _DAT_6005ac10 = (uint)((DAT_60058b54 & 0x10) != 0);
  _DAT_6005ac18 = (uint)((DAT_60058b54 & 0x40) != 0);
  _DAT_6005ac14 = (uint)((DAT_60058b54 & 0x20) != 0);
  _DAT_6005ac1c = (uint)((char)DAT_60058b54 < '\0');
  puVar7 = &uStack_104;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)puVar7 = 0;
    puVar7 = (undefined8 *)((int)puVar7 + 4);
  }
  uStack_104._0_4_ = 0x20;
  (**(code **)(*DAT_60058d8c + 0x54))(DAT_60058d8c,&uStack_104);
  uVar1 = DAT_60058b74;
  DAT_6005aaf8 = (uint)(iStack_f8 == 0x7e0);
  DAT_6005aae8 = DAT_60058b74;
  DAT_6005aae4 = DAT_60058b78;
  DAT_6005ab34 = (uint)((DAT_60058b44 & 0x400) != 0);
  if ((DAT_60058b44 & 0x800) != 0) {
    DAT_6005ab34 = DAT_6005ab34 | 2;
  }
  DAT_6005ab88 = (uint)((DAT_60058b44 & 0x1000) != 0);
  bVar9 = (DAT_60058b44 & 0x20000) != 0;
  if (bVar9) {
    DAT_6005aba4 = DAT_60058b94;
  }
  DAT_6005ab3c = (uint)bVar9;
  DAT_6005ab58 = (uint)((DAT_60058b44 & 0x2000) != 0);
  DAT_6005ab08 = (uint)((DAT_60058b44 & 0x40000) != 0);
  DAT_6005ab0c = (uint)((DAT_60058b44 & 0x100000) != 0);
  DAT_6005ab00 = (uint)((DAT_60058b44 & 1) != 0);
  DAT_6005ab28 = _DAT_60058b5c >> 2 & 1;
  DAT_6005ab1c = _DAT_60058b5c & 1;
  if (((DAT_60058b58 & 0x10000) != 0) || (DAT_6005ab20 = 0, (DAT_60058b58 & 0x5000) != 0)) {
    DAT_6005ab20 = 1;
  }
  DAT_6005ab44 = (uint)((DAT_60058b58 & 0x200) != 0);
  if (((DAT_60058b58 & 0x10000) != 0) || (DAT_6005ab24 = 0, (DAT_60058b58 & 0x4000) != 0)) {
    DAT_6005ab24 = 1;
  }
  DAT_6005ab2c = DAT_60058b64 >> 3 & 1;
  if (((DAT_60058b4c & 0x10) == 0) || (DAT_6005ab30 = 1, (DAT_60058b50 & 2) == 0)) {
    DAT_6005ab30 = 0;
  }
  bVar9 = (DAT_60058b58 & 0x28) != 0;
  DAT_6005ab38 = (uint)bVar9;
  if (((DAT_60058b58 & 0x200) != 0) || (DAT_6005ab4c = 0, (DAT_60058b58 & 0x800) != 0)) {
    DAT_6005ab4c = 1;
  }
  if (!bVar9) {
    DAT_6005ab30 = 0;
  }
  if (DAT_60058b98 == _DAT_60015440) {
    DAT_6005ab98 = 0;
    DAT_6005ab94 = 0;
    DAT_6005ab90 = 0;
    DAT_6005ab8c = 0.0;
  }
  else {
    DAT_6005ab8c = DAT_60058b98;
    DAT_6005ab90 = DAT_60058ba0;
    DAT_6005ab94 = DAT_60058b9c;
    DAT_6005ab98 = DAT_60058ba4;
  }
  if ((DAT_60058d7c == 0x20) && ((DAT_60058b78 & 0x300) == 0)) {
    DAT_60058d7c = 0x10;
  }
  if (0 < DAT_600fc7fc) {
    puVar2 = (undefined4 *)(DAT_600fc800 + 8);
    iVar4 = DAT_600fc7fc;
    do {
      switch(*puVar2) {
      case 8:
        bVar9 = (uVar1 & 0x800) == 0;
        break;
      default:
        goto switchD_60009c28_caseD_9;
      case 0x10:
        bVar9 = (uVar1 & 0x400) == 0;
        break;
      case 0x18:
        bVar9 = (uVar1 & 0x200) == 0;
        break;
      case 0x20:
        bVar9 = (uVar1 & 0x100) == 0;
      }
      if (bVar9) {
        puVar2[-2] = 0;
        puVar2[-1] = 0;
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
        puVar2[2] = 0;
      }
switchD_60009c28_caseD_9:
      puVar2 = puVar2 + 10;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  DAT_6005ab80 = (uint)DAT_60058bba;
  DAT_6005ab50 = 0;
  DAT_6005ab5c = 1;
  DAT_60058d78 = FUN_6000ad60();
  puVar2 = &DAT_60058bf0;
  _DAT_600fc82c = DAT_60058d78;
  for (iVar4 = 0x5f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_60058980;
  for (iVar4 = 0x5f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_60058bf0 = 0x17c;
  DAT_60058980 = 0x17c;
  uVar1 = (**(code **)(*DAT_60058d80 + 0x2c))(DAT_60058d80,&DAT_60058bf0,&DAT_60058980);
  if (uVar1 != 0) {
    puVar3 = FUN_60003a20(uVar1);
    wsprintfA(aCStack_b4,"D3DDEV.C DX7_createD3D() GetCaps of IDirectDraw7 Failed %s\n",puVar3);
    DAT_60058e28 = "dx7\\dx7dev.c";
    DAT_60058e24 = 0x3fb;
    FUN_6000ba10(aCStack_b4);
  }
  DAT_6005ab10 = (uint)((DAT_60058bf8 & 0x80000) != 0);
  DAT_6005ab04 = 0;
  if (((DAT_60058bf8 & 0x400000) != 0) &&
     (((DAT_6005ab04 = 1, DAT_60058d78 == 0xd || (DAT_60058d78 == 0x13)) || (DAT_60058d78 == 4)))) {
    DAT_6005ab04 = 0;
  }
  DAT_6005ab40 = (uint)((DAT_60058bf8 & 0x20000) != 0);
  DAT_6005ab14 = 0;
  uVar1 = FUN_6000aa60();
  if (uVar1 != 0) {
    DAT_6005ab14 = 1;
  }
  DAT_6005ab18 = 0;
  uVar1 = FUN_6000aab0();
  if (uVar1 != 0) {
    DAT_6005ab18 = 0;
  }
  if ((DAT_6005aae4 & 0x100) == 0) {
    if ((DAT_6005aae4 & 0x200) == 0) {
      if ((DAT_6005aae4 & 0x400) == 0) {
        DAT_6005aae4 = DAT_6005aae4 >> 8 & 8;
      }
      else {
        DAT_6005aae4 = 0x10;
      }
    }
    else {
      DAT_6005aae4 = 0x18;
    }
  }
  else {
    DAT_6005aae4 = 0x20;
  }
  DAT_6005aaf4 = 0;
  if ((DAT_60058d7c != 0) && (iVar4 = FUN_6000a130(), iVar4 != 0)) {
    DAT_6005aaf4 = 1;
  }
  (**(code **)(*DAT_60058d9c + 8))(DAT_60058d9c);
  DAT_60058d9c = (int *)0x0;
  FUN_60009f50();
  FUN_6000c110();
  FUN_6000bad0((undefined8 *)&stack0xfffffecc,0,0x18);
  (**(code **)(*DAT_60058d9c + 0x34))(DAT_60058d9c,&stack0xfffffecc);
  FUN_6000bad0(&uStack_104,0,0x44);
  uStack_104._0_4_ = 0;
  uStack_104._4_4_ = 0;
  uStack_fc = 0;
  uStack_f4 = 0;
  uStack_f0 = 0;
  uStack_ec = 0;
  (**(code **)(*DAT_60058d9c + 0x40))(DAT_60058d9c,&uStack_104);
  FUN_6000a490();
  if (0 < (int)DAT_6005ab80) {
    uVar5 = DAT_60058bb4 & 0x16;
    uVar8 = DAT_60058bb4 & 0x17;
    puVar2 = &DAT_6005a96c;
    uVar1 = DAT_6005ab80;
    do {
      puVar2[-1] = 0;
      *puVar2 = 0;
      if (uVar5 != 0) {
        puVar2[-1] = 1;
      }
      if (uVar8 != 0) {
        *puVar2 = 1;
      }
      puVar2 = puVar2 + 0xc;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  FUN_60001460();
  DAT_60058d74 = 1;
  return 1;
}



/* VA 60009f50 */

void FUN_60009f50(void)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;

  pcVar1 = getenv("THRASH_D3DDEVICETYPE");
  if (pcVar1 != (char *)0x0) {
    DAT_60058d70 = atoi(pcVar1);
  }
  iVar5 = DAT_60058d88;
  switch(DAT_60058d70) {
  default:
    DAT_60058e28 = "dx7\\dx7dev.c";
    DAT_60058e24 = 0x197;
    FUN_6000ba10("D3D device type not recognised\n");
    return;
  case 2:
    iVar3 = *DAT_60058d98;
    DAT_60058d6c = 1;
    puVar4 = &DAT_60015bd8;
    break;
  case 3:
    iVar3 = *DAT_60058d98;
    DAT_60058d6c = 1;
    puVar4 = &DAT_60015ba8;
    break;
  case 4:
    iVar3 = *DAT_60058d98;
    DAT_60058d6c = 1;
    puVar4 = &DAT_60015be8;
    break;
  case 5:
    iVar3 = *DAT_60058d98;
    DAT_60058d6c = 1;
    puVar4 = &DAT_60015bb8;
    break;
  case -1:
  case 0:
    DAT_60058d6c = 0;
    DAT_6005abc0 = 0;
    if (DAT_60058d88 == 0) {
      iVar3 = *DAT_60058d98;
      iVar5 = DAT_60058d84;
      if (DAT_60018844 != 0) {
        iVar3 = (**(code **)(iVar3 + 0x10))(DAT_60058d98,&DAT_60015b98,DAT_60058d84);
        iVar5 = DAT_60058d84;
        goto joined_r0x6000a0aa;
      }
    }
    else {
      if (DAT_60018844 == 0) {
        uVar2 = (**(code **)(*DAT_60058d98 + 0x10))
                          (DAT_60058d98,&DAT_60015bc8,DAT_60058d88,&DAT_60058d9c);
        goto LAB_60009fb0;
      }
      iVar3 = (**(code **)(*DAT_60058d98 + 0x10))(DAT_60058d98,&DAT_60015b98);
      iVar5 = DAT_60058d88;
joined_r0x6000a0aa:
      if (iVar3 == 0) {
        uVar2 = 0;
        DAT_6005abc0 = 1;
        goto LAB_60009fb0;
      }
      iVar3 = *DAT_60058d98;
    }
    puVar4 = &DAT_60015bc8;
  }
  uVar2 = (**(code **)(iVar3 + 0x10))(DAT_60058d98,puVar4,iVar5,&DAT_60058d9c);
LAB_60009fb0:
  if (uVar2 != 0) {
    DAT_60058e28 = "dx7\\dx7dev.c";
    DAT_60058e24 = 0x19d;
    pcVar1 = FUN_60003a20(uVar2);
    FUN_6000ba10(pcVar1);
  }
  return;
}



/* VA 6000a130 */

undefined4 FUN_6000a130(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint unaff_ESI;
  uint *puVar4;
  int unaff_EDI;
  int *piVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int *in_stack_00000010;
  int *piVar8;
  undefined4 *puStack_b0;
  undefined4 local_9c [4];
  int aiStack_8c [18];
  uint auStack_44 [8];
  int iStack_24;
  undefined4 uStack_c;
  undefined4 uStack_8;

  if (DAT_6005ab18 != 0) {
    return 1;
  }
  puVar7 = local_9c;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  puStack_b0 = local_9c;
  local_9c[0] = 0x20;
  iVar3 = (**(code **)(*DAT_60058d98 + 0x18))(DAT_60058d98,&DAT_60015bc8,FUN_6000a450);
  if (iVar3 != 0) {
    DAT_60058e28 = "dx7\\dx7dev.c";
    DAT_60058e24 = 0x503;
    FUN_6000ba10("DX7_createzbuffer,  EnumZBufferFormats failure! %8x\n");
  }
  if (unaff_EDI == 0x20) {
    piVar5 = aiStack_8c;
    for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    }
    aiStack_8c[2] = uStack_8;
    aiStack_8c[0] = 0x7c;
    aiStack_8c[1] = 0x1007;
    aiStack_8c[3] = uStack_c;
    puVar4 = (uint *)&stack0xffffff54;
    puVar6 = auStack_44;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    DAT_6005ab48 = (uint)((unaff_ESI & 0x4000) != 0);
    iStack_24 = (-(uint)(DAT_6005aae0 != 0) & 0x3800) + 0x20800;
    piVar5 = aiStack_8c;
    uVar1 = (**(code **)(*DAT_60058d80 + 0x18))(DAT_60058d80,piVar5,&puStack_b0);
    if (uVar1 != 0) {
      DAT_60058e28 = "dx7\\dx7dev.c";
      DAT_60058e24 = 0x536;
      FUN_60003a20(uVar1);
      FUN_6000ba10("DX7_createzbuffer,  CreateSurface failure! %s\n");
      if ((uVar1 != 0x8007000e) && (uVar1 != 0x8876017c)) {
        FUN_60003a20(uVar1);
        FUN_6000b9e0("CreateSurface for Z-buffer failed %s.\n");
        return 0;
      }
      FUN_6000b9e0(
                  "There was not enough video memory to create the Z-buffer surface.\nPlease restart the program and try another fullscreen mode with less resolution or lower bit depth.\n"
                  );
      return 0;
    }
    if (in_stack_00000010 == (int *)0x0) {
      piVar8 = (int *)0x0;
      piVar2 = DAT_60058d88;
      if (DAT_60058d88 == (int *)0x0) {
        piVar2 = DAT_60058d84;
      }
      iVar3 = (**(code **)(*piVar2 + 0xc))(piVar2);
    }
    else {
      piVar8 = (int *)0x0;
      iVar3 = (**(code **)(*in_stack_00000010 + 0xc))();
    }
    if (iVar3 == 0) {
      puVar7 = (undefined4 *)&stack0xffffff5c;
      for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      iVar3 = (**(code **)(*piVar5 + 0x58))(piVar5,&stack0xffffff5c);
      if (iVar3 != 0) {
        FUN_6000b9e0("Failed to get surface description of Z buffer %d.\n");
        piVar5 = DAT_60058d9c;
        (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,7,0);
        (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0xe,0);
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 8))(piVar5);
        }
        return 0;
      }
      DAT_6005aaf0 = auStack_44[0] >> 0xe & 1;
      if ((DAT_6005aae0 == 0) || (DAT_6005aaf0 != 0)) {
        if (piVar8 == (int *)0x0) {
          return 1;
        }
        (**(code **)(*piVar8 + 8))(piVar8);
        return 1;
      }
      FUN_6000b9e0("Could not fit the Z-buffer in video memory for this hardware device.\n");
      piVar5 = DAT_60058d9c;
      (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,7,0);
      (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0xe,0);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 8))(piVar5);
        return 0;
      }
    }
    else {
      FUN_6000b9e0("AddAttachedBuffer failed for Z-Buffer %d.\n");
      piVar5 = DAT_60058d9c;
      (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,7,0);
      (**(code **)(*DAT_60058d9c + 0x50))(DAT_60058d9c,0xe,0);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 8))(piVar5);
      }
    }
    return 0;
  }
  return 0;
}



/* VA 6000a450 */

undefined4 FUN_6000a450(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;

  if (((param_1[1] & 0x400) != 0) && (param_1[3] == DAT_60058d7c)) {
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    return 0;
  }
  return 1;
}



/* VA 6000a490 */

void FUN_6000a490(void)

{
  int *piVar1;
  char *_Str;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  float *pfVar7;
  int iStack_1cc;

  (**(code **)(*DAT_60058d9c + 0x14))();
  FUN_6000ab00(DAT_60017120,DAT_60017124);
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  if (DAT_6005aaf4 == 0) {
    (**(code **)(*DAT_60058d9c + 0x50))();
  }
  else {
    (**(code **)(*DAT_60058d9c + 0x50))();
    (**(code **)(*DAT_60058d9c + 0x50))();
  }
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x94))();
  (**(code **)(*DAT_60058d9c + 0x94))();
  if (DAT_6005ab2c == 0) {
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
  }
  else {
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
    (**(code **)(*DAT_60058d9c + 0x94))();
  }
  (**(code **)(*DAT_60058d9c + 0x94))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  _Str = getenv("DX7_WIREFRAME");
  if ((_Str == (char *)0x0) || (iVar2 = atoi(_Str), iVar2 == 0)) {
    (**(code **)(*DAT_60058d9c + 0x50))();
  }
  else {
    (**(code **)(*DAT_60058d9c + 0x50))();
  }
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  (**(code **)(*DAT_60058d9c + 0x50))();
  puVar5 = &DAT_6005a940;
  for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  DAT_6001822c = 1;
  _THRASH_setstate_8(7,(float *)0x1);
  _THRASH_setstate_8(0xb,(float *)0x3);
  iVar2 = DAT_6005ab80;
  iStack_1cc = 0;
  if (0 < DAT_6005ab80) {
    do {
      uVar4 = 0;
      switch(iStack_1cc) {
      case 0:
        uVar4 = 0;
        break;
      case 1:
        uVar4 = 0x10000;
        break;
      case 2:
        uVar4 = 0x20000;
        break;
      case 3:
        uVar4 = 0x30000;
        break;
      case 4:
        uVar4 = 0x40000;
        break;
      case 5:
        uVar4 = 0x50000;
        break;
      case 6:
        uVar4 = 0x60000;
        break;
      case 7:
        uVar4 = 0x70000;
      }
      uVar6 = uVar4 | 0x29;
      _THRASH_setstate_8(uVar6,(float *)0x8);
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a960)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))();
      if (iVar3 == 0) {
        (&DAT_6005a960)[iStack_1cc * 0xc] = 1;
      }
      _THRASH_setstate_8(uVar6,(float *)0x1);
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a940)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))();
      if (iVar3 == 0) {
        (&DAT_6005a940)[iStack_1cc * 0xc] = 1;
      }
      _THRASH_setstate_8(uVar6,(float *)0x9);
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a95c)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))();
      if (iVar3 == 0) {
        (&DAT_6005a95c)[iStack_1cc * 0xc] = 1;
      }
      _THRASH_setstate_8(uVar6,(float *)0x3);
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a948)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))();
      if (iVar3 == 0) {
        (&DAT_6005a948)[iStack_1cc * 0xc] = 1;
      }
      _THRASH_setstate_8(uVar6,(float *)0x4);
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a944)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))();
      if (iVar3 == 0) {
        (&DAT_6005a944)[iStack_1cc * 0xc] = 1;
      }
      _THRASH_setstate_8(uVar6,(float *)0x6);
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a94c)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))();
      if (iVar3 == 0) {
        (&DAT_6005a94c)[iStack_1cc * 0xc] = 1;
      }
      if ((((DAT_60058d78 == 0x16) || (DAT_60058d78 == 0xb)) || (DAT_60058d78 == 10)) ||
         (((DAT_60058d78 == 9 || (DAT_60058d78 == 2)) || (DAT_60058d78 == 0x17)))) {
        (&DAT_6005a94c)[iStack_1cc * 0xc] = 0;
      }
      _THRASH_setstate_8(uVar6,(float *)0x7);
      piVar1 = DAT_60058d9c;
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a950)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))(piVar1,&stack0xfffffe00);
      if (iVar3 == 0) {
        (&DAT_6005a950)[iStack_1cc * 0xc] = 1;
      }
      _THRASH_setstate_8(uVar6,(float *)0x9);
      piVar1 = DAT_60058d9c;
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a95c)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))(piVar1,&stack0xfffffdf8);
      if (iVar3 == 0) {
        (&DAT_6005a95c)[iStack_1cc * 0xc] = 1;
      }
      _THRASH_setstate_8(uVar6,(float *)0xa);
      piVar1 = DAT_60058d9c;
      iVar3 = *DAT_60058d9c;
      (&DAT_6005a964)[iStack_1cc * 0xc] = 0;
      iVar3 = (**(code **)(iVar3 + 0x98))(piVar1,&stack0xfffffdf0);
      if (iVar3 == 0) {
        (&DAT_6005a964)[iStack_1cc * 0xc] = 1;
      }
      if (uVar4 < 0x10001) {
        pfVar7 = (float *)0x0;
      }
      else {
        pfVar7 = (float *)0x2;
      }
      _THRASH_setstate_8(uVar6,pfVar7);
      iStack_1cc = iStack_1cc + 1;
    } while (iStack_1cc < iVar2);
  }
  _THRASH_setstate_8(0xb,(float *)0x1);
  (**(code **)(*DAT_60058d9c + 0x18))();
  DAT_6001822c = iVar2;
  return;
}



/* VA 6000aa60 */

uint FUN_6000aa60(void)

{
  undefined8 local_1d8 [11];
  uint uStack_180;
  undefined8 local_ec [29];

  FUN_6000bad0(local_1d8,0,0xec);
  FUN_6000bad0(local_ec,0,0xec);
  (**(code **)(*DAT_60058d9c + 0xc))(DAT_60058d9c,local_1d8);
  return uStack_180 >> 5 & 1;
}



/* VA 6000aab0 */

uint FUN_6000aab0(void)

{
  undefined8 local_1d8 [7];
  uint uStack_19c;
  undefined8 local_ec [29];

  FUN_6000bad0(local_1d8,0,0xec);
  FUN_6000bad0(local_ec,0,0xec);
  (**(code **)(*DAT_60058d9c + 0xc))(DAT_60058d9c,local_1d8);
  return uStack_19c & 0x8000;
}



/* VA 6000ab00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_6000ab00(float param_1,float param_2)

{
  int iVar1;
  int *piStack_d8;
  undefined4 uStack_d4;
  undefined4 *puStack_d0;
  int *piStack_cc;
  undefined4 uStack_c8;
  undefined4 *puStack_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  float local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  int local_a0;
  float local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_44 = 0x3f800000;
  local_58 = 0x3f800000;
  local_6c = 0x3f800000;
  local_80 = 0x3f800000;
  local_50 = 0;
  local_74 = 0;
  local_78 = 0;
  local_7c = 0;
  local_4c = 0;
  local_64 = 0;
  local_68 = 0;
  local_70 = 0;
  local_48 = 0;
  local_54 = 0;
  local_5c = 0;
  local_60 = 0;
  local_4 = 0x3f800000;
  local_18 = 0x3f800000;
  local_2c = 0x3f800000;
  local_40 = 0x3f800000;
  local_10 = 0.0;
  local_34 = 0;
  local_38 = 0;
  local_3c = 0;
  local_c = 0;
  local_24 = 0;
  local_28 = 0;
  local_30 = 0;
  local_8 = 0;
  local_14 = 0.0;
  local_1c = 0;
  local_20 = 0;
  local_84 = 0x3f800000;
  local_98 = 0x3f800000;
  local_ac = 0x3f800000;
  local_c0 = 0x3f800000;
  local_90 = 0;
  local_b4 = 0;
  local_b8 = 0;
  local_bc = 0;
  local_8c = 0;
  local_a4 = 0;
  local_a8 = 0;
  local_b0 = 0.0;
  local_88 = 0;
  local_94 = 0;
  local_9c = 0.0;
  local_a0 = 0;
  if (param_2 < param_1 != (param_2 == param_1)) {
    return 1;
  }
  puStack_c4 = &local_80;
  uStack_c8 = 1;
  piStack_cc = DAT_60058d9c;
  puStack_d0 = (undefined4 *)0x6000ace9;
  iVar1 = (**(code **)(*DAT_60058d9c + 0x2c))();
  if (iVar1 == 0) {
    puStack_d0 = &local_4c;
    uStack_d4 = 2;
    piStack_d8 = DAT_60058d9c;
    iVar1 = (**(code **)(*DAT_60058d9c + 0x2c))();
    if (iVar1 == 0) {
      local_9c = local_14;
      local_ac = 0x3f800000;
      local_b0 = local_14 / (local_10 - local_14) + _DAT_60015448;
      local_a0 = iVar1;
      iVar1 = (**(code **)(*DAT_60058d9c + 0x2c))(DAT_60058d9c,3,&piStack_d8);
    }
  }
  return iVar1;
}



/* VA 6000ad60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6000ad60(void)

{
  undefined1 local_430 [1020];
  int iStack_34;
  uint uStack_30;

  (**(code **)(*DAT_60058d80 + 0x6c))(DAT_60058d80,local_430,0);
  uStack_30 = iStack_34 << 0x10 ^ uStack_30;
  if ((int)uStack_30 < 0x10de0112) {
    if (0x10de010f < (int)uStack_30) {
      return 0x18;
    }
    if ((int)uStack_30 < 0x10024c4a) {
      if (uStack_30 == 0x10024c49) {
        DAT_6005ab0c = 0;
        DAT_6005ab80 = 1;
        _DAT_600fc804 = 1;
        return 0xe;
      }
      if ((int)uStack_30 < 0x1002474a) {
        if (uStack_30 == 0x10024749) {
          DAT_6005ab0c = 0;
          DAT_6005ab80 = 1;
          _DAT_600fc804 = 1;
          return 0xe;
        }
        if ((int)uStack_30 < 0x10024743) {
          if (uStack_30 == 0x10024742) {
            DAT_6005ab0c = 0;
            DAT_6005ab80 = 1;
            _DAT_600fc804 = 1;
            return 0xe;
          }
          if ((uStack_30 == 0x80867800) || (uStack_30 == 0x3d00d1)) {
            DAT_6005ab80 = 1;
            _DAT_600fc804 = 1;
            return 0x14;
          }
        }
        else if (uStack_30 == 0x10024744) {
          DAT_6005ab0c = 0;
          DAT_6005ab80 = 1;
          _DAT_600fc804 = 1;
          return 0xe;
        }
      }
      else {
        if (uStack_30 == 0x10024c42) {
          DAT_6005ab0c = 0;
          DAT_6005ab80 = 1;
          _DAT_600fc804 = 1;
          return 0xe;
        }
        if (uStack_30 == 0x10024c44) {
          DAT_6005ab0c = 0;
          DAT_6005ab80 = 1;
          _DAT_600fc804 = 1;
          return 0xe;
        }
        if (uStack_30 == 0x10024c47) {
          DAT_6005ab0c = 0;
          DAT_6005ab80 = 1;
          _DAT_600fc804 = 1;
          return 0xe;
        }
      }
    }
    else if ((int)uStack_30 < 0x104c3d08) {
      if (uStack_30 == 0x104c3d07) {
        DAT_6005ab0c = 0;
        _DAT_600fc804 = 1;
        DAT_6005ab80 = 1;
        return 1;
      }
      if ((int)uStack_30 < 0x10330047) {
        if (uStack_30 == 0x10330046) {
          _DAT_600fc804 = 1;
          DAT_6005ab80 = 1;
          return 0xc;
        }
        if (0x102b051f < (int)uStack_30) {
          if ((int)uStack_30 < 0x102b0522) {
            return 2;
          }
          if (uStack_30 == 0x1033002a) {
            DAT_6005ab80 = 1;
            _DAT_600fc804 = 1;
            return 0xc;
          }
        }
      }
      else if (uStack_30 == 0x10396326) {
        return 8;
      }
    }
    else {
      switch(uStack_30) {
      case 0x10de0020:
        DAT_6005ab5c = 0;
        return 4;
      case 0x10de0028:
      case 0x10de0029:
      case 0x10de002a:
      case 0x10de002b:
      case 0x10de002c:
      case 0x10de002d:
      case 0x10de002e:
      case 0x10de002f:
        DAT_6005ab5c = 0;
        return 0x10;
      case 0x10de0100:
      case 0x10de0101:
      case 0x10de0102:
      case 0x10de0103:
        return 0x12;
      }
    }
  }
  else if ((int)uStack_30 < 0x121a0006) {
    if (0x121a0003 < (int)uStack_30) {
      return 0x16;
    }
    if ((int)uStack_30 < 0x11632001) {
      if (uStack_30 == 0x11632000) {
        _DAT_6005ac18 = 0;
        return 0x17;
      }
      if ((int)uStack_30 < 0x10de0201) {
        if (uStack_30 == 0x10de0200) {
          return 0x19;
        }
        if (uStack_30 == 0x10de0113) {
          return 0x18;
        }
        if ((0x10de014f < (int)uStack_30) && ((int)uStack_30 < 0x10de0154)) {
          return 0x18;
        }
      }
      else if (uStack_30 == 0x110b0004) {
        DAT_6005ab80 = 1;
        _DAT_600fc804 = 1;
        return 0x13;
      }
    }
    else {
      if (uStack_30 == 0x121a0001) {
        DAT_6005ab5c = 0;
        _DAT_600fc804 = 1;
        DAT_6005ab80 = 1;
        return 9;
      }
      if (uStack_30 == 0x121a0002) {
        DAT_6005ab5c = 0;
        return 10;
      }
      if (uStack_30 == 0x121a0003) {
        return 0xb;
      }
    }
  }
  else if ((int)uStack_30 < 0x53338a02) {
    if (uStack_30 == 0x53338a01) {
      DAT_6005ab80 = 1;
      _DAT_600fc804 = 1;
      return 6;
    }
    if ((int)uStack_30 < 0x53335632) {
      if (uStack_30 == 0x53335631) {
        DAT_6005ab80 = 1;
        _DAT_600fc804 = 1;
        return 7;
      }
      if (0x12d20017 < (int)uStack_30) {
        if ((int)uStack_30 < 0x12d2001a) {
          DAT_6005ab0c = 0;
          DAT_6005ab80 = 1;
          _DAT_600fc804 = 1;
          return 3;
        }
        if (uStack_30 == 0x3d3d0009) {
          DAT_6005ab0c = 0;
          DAT_6005ab80 = 1;
          _DAT_600fc804 = 1;
          return 1;
        }
      }
    }
    else if (uStack_30 == 0x5333883d) {
      DAT_6005ab80 = 1;
      _DAT_600fc804 = 1;
      return 5;
    }
  }
  else if ((int)uStack_30 < 0x53338a23) {
    if (uStack_30 == 0x53338a22) {
      DAT_6005ab50 = 1;
      return 0x11;
    }
    if ((0x53338a1f < (int)uStack_30) && ((int)uStack_30 < 0x53338a22)) {
      DAT_6005ab04 = 0;
      DAT_6005ab50 = 1;
      return 0xd;
    }
  }
  else if (uStack_30 == 0x53339102) {
    DAT_6005ab8c = 0;
    DAT_6005ab90 = 0;
    DAT_6005ab94 = 0;
    DAT_6005ab98 = 0;
    DAT_6005ab50 = 1;
    return 0x15;
  }
  if (((((int)uStack_30 < 0x10025041) || (0x100250fe < (int)uStack_30)) &&
      (((int)uStack_30 < 0x10025241 || (0x100252fe < (int)uStack_30)))) &&
     (((int)uStack_30 < 0x10025341 || (0x100253fe < (int)uStack_30)))) {
    if ((((int)uStack_30 < 0x1002474d) || (0x10024751 < (int)uStack_30)) &&
       (((int)uStack_30 < 0x10024c49 || (0x10024c53 < (int)uStack_30)))) {
      return 0;
    }
    DAT_6005ab0c = 0;
    _DAT_600fc804 = 1;
    DAT_6005ab80 = 1;
    return 0xe;
  }
  DAT_6005ab0c = 0;
  return 0xf;
}



/* VA 6000b270 */

void FUN_6000b270(size_t param_1)

{
  if (DAT_60058e14 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x6000b279. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_60058e14)();
    return;
  }
  malloc(param_1);
  return;
}



/* VA 6000b290 */

undefined4 FUN_6000b290(void *param_1)

{
  undefined4 uVar1;

  if (DAT_60058e18 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x6000b2a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*DAT_60058e18)();
    return uVar1;
  }
  free(param_1);
  return 1;
}



/* VA 6000b2c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6000b2c0(uint param_1,undefined *param_2)

{
  switch(param_1) {
  case 2:
    if (param_2 == (undefined *)0x0) {
      DAT_60058e1c = 1;
      FUN_60001e70(param_1,0);
      return 1;
    }
    if (param_2 == (undefined *)0x2) {
      DAT_60058e1c = 0;
      FUN_60001e70(param_1,2);
      return 1;
    }
    if (param_2 == (undefined *)0x1) {
      DAT_60058e1c = 0x80000000;
      FUN_60001e70(param_1,1);
      return 1;
    }
  default:
switchD_6000b2dd_caseD_3:
    return 0;
  case 0x12:
    _DAT_60058e0c = param_2;
    break;
  case 0x13:
    if (param_2 == (undefined *)0x0) {
      _DAT_60058e00 = 0;
      _DAT_60058e08 = (undefined *)0x0;
      PTR_FUN_6001713c = (undefined *)0x0;
      _DAT_60058e04 = (undefined *)0x0;
    }
    else {
      _DAT_60058e00 = *(undefined4 *)(param_2 + 4);
      _DAT_60058e08 = *(undefined **)(param_2 + 8);
      PTR_FUN_6001713c = *(undefined **)(param_2 + 0x18);
      _DAT_60058e04 = *(undefined **)(param_2 + 0x14);
    }
    break;
  case 0x19:
    DAT_60058df0 = param_2;
    break;
  case 0x1a:
    PTR_FUN_6001713c = param_2;
    break;
  case 0x1b:
    _DAT_60058e08 = param_2;
    break;
  case 0x1c:
    _DAT_60058e04 = param_2;
    break;
  case 0x1e:
    DAT_6001712c = param_2;
    break;
  case 0x1f:
    if (((int)param_2 < 0x68) || (DAT_60017128 = param_2, 0x6b < (int)param_2)) {
      DAT_60017128 = (undefined *)0x6b;
    }
    break;
  case 0x20:
    DAT_60058e14 = param_2;
    break;
  case 0x21:
    DAT_60058e18 = param_2;
    break;
  case 0x27:
    DAT_60058e10 = param_2;
    break;
  case 0x37:
    DAT_60058df4 = param_2;
    break;
  case 0x3a:
    _DAT_60058dfc = param_2;
    break;
  case 0x3b:
    break;
  case 0x3d:
    _DAT_60058e20 = param_2;
    break;
  case 0x3e:
    DAT_60058df8 = param_2;
    break;
  case 0x46:
    switch(param_2) {
    case (undefined *)0x1:
      DAT_60017130 = 1;
      _DAT_60017134 = 0;
      FUN_60001e70(param_1,param_2);
      return 1;
    case (undefined *)0x2:
      DAT_60017130 = 2;
      _DAT_60017134 = 1;
      FUN_60001e70(param_1,param_2);
      return 1;
    default:
      goto switchD_6000b2dd_caseD_3;
    case (undefined *)0x4:
      DAT_60017130 = 4;
      _DAT_60017134 = 2;
      break;
    case (undefined *)0x8:
      DAT_60017130 = 8;
      _DAT_60017134 = 4;
    }
    break;
  case 0x47:
    DAT_60017138 = param_2;
  }
  FUN_60001e70(param_1,param_2);
  return 1;
}



/* VA 6000b590 */

void __cdecl FUN_6000b590(int param_1,int param_2,int param_3,undefined4 param_4)

{
  float *pfVar1;
  float *pfVar2;

  FUN_6000be00();
  pfVar1 = (float *)FUN_60009250(0,param_4,&DAT_60015ae0);
  _THRASH_setstate_8(0x130,pfVar1);
  _THRASH_setstate_8(1,(float *)0x0);
  pfVar1 = (float *)FUN_60009250(1,param_4,&DAT_60015ad8);
  _THRASH_setstate_8(2,pfVar1);
  pfVar1 = (float *)FUN_60009250(1,param_4,"FILTER");
  _THRASH_setstate_8(7,pfVar1);
  pfVar1 = (float *)FUN_60009250(1,param_4,"SHADE");
  _THRASH_setstate_8(6,pfVar1);
  pfVar1 = (float *)FUN_60009250(2,param_4,"TRANSPARENCY");
  _THRASH_setstate_8(10,pfVar1);
  pfVar1 = (float *)FUN_60009250(0x10,param_4,"ALPHATEST");
  _THRASH_setstate_8(0x24,pfVar1);
  pfVar1 = (float *)FUN_60009250(4,param_4,"ALPHACMP");
  _THRASH_setstate_8(0x40,pfVar1);
  pfVar1 = (float *)FUN_60009250(1,param_4,"MIPMAP");
  _THRASH_setstate_8(0xb,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"BACKGROUNDCOLOUR");
  _THRASH_setstate_8(3,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"CHROMACOLOUR");
  _THRASH_setstate_8(0xc,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"DITHER");
  _THRASH_setstate_8(5,pfVar1);
  _THRASH_setstate_8(0x14,(float *)0x0);
  pfVar1 = (float *)FUN_60009250(0,param_4,"FOGMODE");
  _THRASH_setstate_8(0x15,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"FOGDENSITY");
  _THRASH_setstate_8(0xe,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"STATE_FOGZNEAR");
  _THRASH_setstate_8(0x16,pfVar1);
  pfVar1 = (float *)FUN_60009250(0x3f800000,param_4,"FOGZFAR");
  _THRASH_setstate_8(0x17,pfVar1);
  pfVar1 = (float *)FUN_60009250(-1,param_4,"FOGCOLOUR");
  _THRASH_setstate_8(0xf,pfVar1);
  pfVar1 = (float *)FUN_60009250(4,param_4,"INDEXSIZE");
  _THRASH_setstate_8(0x46,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"ALPHA");
  _THRASH_setstate_8(0x38,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"TEXTURECLAMP");
  _THRASH_setstate_8(0xd,pfVar1);
  _THRASH_setstate_8(0x2e,(float *)0x3f800000);
  pfVar1 = (float *)FUN_60009250(0,param_4,"DEPTHBIAS");
  _THRASH_setstate_8(0x18,pfVar1);
  _THRASH_setstate_8(8,(float *)0x0);
  _THRASH_setstate_8(0x2a,(float *)0x0);
  _THRASH_setstate_8(0x29,(float *)0x0);
  _THRASH_setstate_8(0x10029,(float *)0x2);
  pfVar1 = (float *)FUN_60009250(param_2 - 2U & ((int)(param_2 - 2U) < 0) - 1,param_4,"MAXPENDING");
  _THRASH_setstate_8(0x6d,pfVar1);
  pfVar1 = (float *)FUN_60009250(1,param_4,"BACKBUFFERTYPE");
  _THRASH_setstate_8(0x2b,pfVar1);
  pfVar1 = (float *)FUN_60009250(1,param_4,"FLATFANS");
  _THRASH_setstate_8(0x11,pfVar1);
  pfVar1 = (float *)FUN_60009250(1,param_4,"LINEWIDTH");
  _THRASH_setstate_8(0x10,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"STENCILBUFFER");
  _THRASH_setstate_8(0x2f,pfVar1);
  pfVar1 = (float *)FUN_60009250(param_1,param_4,"DISPLAYMODE");
  _THRASH_setstate_8(0x3a,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"LINEDOUBLE");
  _THRASH_setstate_8(0x131,pfVar1);
  _THRASH_setstate_8(0x3b,(float *)0x0);
  _THRASH_setstate_8(0x43,(float *)0x3f800000);
  pfVar1 = (float *)FUN_60009250(1,param_4,"FLIPRATE");
  _THRASH_setstate_8(0x3c,pfVar1);
  pfVar1 = (float *)FUN_60009250(0,param_4,"SHAMELESSPLUG");
  _THRASH_setstate_8(0x3d,pfVar1);
  pfVar1 = (float *)FUN_60009250((param_3 < 1) - 1 & 2,param_4,"DEPTHBUFFER");
  pfVar2 = _THRASH_setstate_8(4,pfVar1);
  if ((pfVar2 == (float *)0x0) && (pfVar1 == (float *)0x2)) {
    _THRASH_setstate_8(4,(float *)0x1);
  }
  pfVar1 = (float *)FUN_60009250(3,param_4,"DEPTHCMP");
  _THRASH_setstate_8(0x28,pfVar1);
  pfVar1 = (float *)FUN_60009250(1,param_4,&DAT_60015970);
  _THRASH_setstate_8(0x47,pfVar1);
  return;
}



/* VA 6000b970 */

undefined * __cdecl FUN_6000b970(uint param_1)

{
  sprintf(&DAT_60058db0,"Direct draw error code (0x%lx, %d)",param_1,param_1 & 0xffff);
  return &DAT_60058db0;
}



/* VA 6000b9a0 */

void FUN_6000b9a0(int param_1,LPCSTR param_2)

{
  if (DAT_60017138 != 0) {
    printf("%s",param_2);
  }
  if (param_1 == 0) {
    MessageBoxA((HWND)0x0,param_2,"Abort Message",0x11011);
  }
  return;
}



/* VA 6000b9e0 */

void __cdecl FUN_6000b9e0(char *param_1)

{
  char local_200 [512];

  vsprintf(local_200,param_1,&stack0x00000008);
  return;
}



/* VA 6000ba10 */

void __cdecl FUN_6000ba10(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char local_400 [512];
  char local_200 [512];

  vsprintf(local_400,param_1,&stack0x00000008);
  if (DAT_60058e28 != 0) {
    sprintf(local_200," FILE %s, LINE %d\n",DAT_60058e28,DAT_60058e24);
    uVar2 = 0xffffffff;
    pcVar5 = local_200;
    do {
      pcVar7 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar7 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar7;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    iVar3 = -1;
    pcVar5 = local_400;
    do {
      pcVar6 = pcVar5;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    pcVar5 = pcVar7 + -uVar2;
    pcVar7 = pcVar6 + -1;
    for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  if (PTR_FUN_6001713c != (undefined *)0x0) {
    (*(code *)PTR_FUN_6001713c)(0,local_400);
  }
  return;
}



/* VA 6000bab0 */

void FUN_6000bab0(void)

{
  FUN_6000b2c0(0x37,(undefined *)(DAT_60058df4 + 1));
  _THRASH_setstate_8(1,(float *)0x0);
  return;
}



/* VA 6000bad0 */

void __cdecl FUN_6000bad0(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  if (DAT_6005a920 != 0) {
    FUN_60010000(param_1,param_2,param_3);
    return;
  }
  if (DAT_6005a924 != 0) {
    FUN_6000f000(param_1,param_2,param_3);
    return;
  }
  FUN_6000e000((undefined4 *)param_1,param_2,param_3);
  return;
}



/* VA 6000bb10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_6000bb10(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  char *_Str;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;

  DAT_60059000 = 0;
  DAT_60059004 = 0;
  _DAT_60059008 = 0;
  _Str = getenv("THRASH_DISPLAY");
  if (_Str == (char *)0x0) {
LAB_6000bb47:
    iVar1 = _THRASH_getstate_4(0x12);
    if (iVar1 == 0) {
      DirectDrawEnumerateExA(&LAB_6000bbd0,0,1);
      DirectDrawEnumerateExA(&LAB_6000bbd0,0,4);
      goto LAB_6000bb88;
    }
  }
  else {
    iVar1 = atoi(_Str);
    if (iVar1 != 0) goto LAB_6000bb47;
  }
  DAT_60059000 = 1;
  DAT_60059004 = 1;
  _DAT_60059008 = 0;
LAB_6000bb88:
  iVar1 = DAT_60059000;
  if (param_1 != (undefined4 *)0x0) {
    puVar3 = &DAT_60058e40;
    for (iVar2 = DAT_60059000; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_1 = *puVar3;
      puVar3 = puVar3 + 1;
      param_1 = param_1 + 1;
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    puVar3 = &DAT_60058f80;
    for (iVar2 = iVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
  }
  DAT_60059000 = FUN_60009250(iVar1,param_3,"displays");
  return;
}



/* VA 6000bd60 */

bool __cdecl FUN_6000bd60(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *local_184;
  int local_180 [96];

  DirectDrawCreate((&DAT_60058e40)[param_1],&local_184,0);
  piVar5 = local_180;
  iVar1 = (**(code **)*local_184)(local_184,&DAT_60015c48);
  piVar6 = piVar5;
  (**(code **)(*piVar5 + 8))();
  bVar3 = false;
  uVar4 = 0;
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)&stack0xfffffe74;
    for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    (**(code **)(*piVar6 + 0x2c))(piVar6,&stack0xfffffe74,0);
    bVar3 = (uVar4 & 1) != 0;
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  return bVar3;
}



/* VA 6000be00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6000be00(void)

{
  uint uVar1;
  char *pcVar2;
  undefined4 extraout_ECX;
  int iVar3;
  undefined4 extraout_EDX;
  char *pcVar4;
  bool bVar5;
  undefined8 uVar6;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98;
  _OSVERSIONINFOA local_94;

  _DAT_6005a92c = 0;
  _DAT_6005a8ec = 0;
  _DAT_6005a8fc = 0;
  _DAT_6005a930 = 0;
  _DAT_6005a928 = 0;
  DAT_6005a924 = 0;
  _DAT_6005a8e4 = 0;
  DAT_6005a8e8 = 0;
  DAT_6005a90c = 0;
  DAT_6005a8f8 = 0;
  _DAT_6005a8e0 = 0;
  DAT_6005a8f0 = 0;
  _DAT_6005a910 = _DAT_6005a910 & 0xffffff00;
  uVar1 = FUN_6000d300();
  if (uVar1 == 0) {
    uVar6 = FUN_6000d33f(extraout_ECX,extraout_EDX);
    _DAT_6005a8e0 = (undefined4)uVar6;
  }
  else {
    local_9c = 0;
    FUN_6000d31d(&local_ac,0);
    _DAT_6005a910 = local_a8;
    local_98 = local_ac;
    _DAT_6005a914 = local_a4;
    _DAT_6005a918 = local_a0;
    DAT_6005a91c = 0;
    if (0 < (int)local_ac) {
      iVar3 = 0xd;
      bVar5 = true;
      pcVar2 = &DAT_6005a910;
      pcVar4 = "GenuineIntel";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar5 = *pcVar2 == *pcVar4;
        pcVar2 = pcVar2 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        DAT_6005a8f0 = 1;
      }
      else {
        iVar3 = 0xd;
        bVar5 = true;
        pcVar2 = &DAT_6005a910;
        pcVar4 = "AuthenticAMD";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar5 = *pcVar2 == *pcVar4;
          pcVar2 = pcVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          DAT_6005a8f8 = 1;
        }
        else {
          iVar3 = 0xd;
          bVar5 = true;
          pcVar2 = &DAT_6005a910;
          pcVar4 = "CyrixInstead";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar5 = *pcVar2 == *pcVar4;
            pcVar2 = pcVar2 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            _DAT_6005a8e0 = 1;
          }
          else {
            iVar3 = 0xd;
            bVar5 = true;
            pcVar2 = &DAT_6005a910;
            pcVar4 = "CentaurHauls";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar5 = *pcVar2 == *pcVar4;
              pcVar2 = pcVar2 + 1;
              pcVar4 = pcVar4 + 1;
            } while (bVar5);
            if (bVar5) {
              DAT_6005a90c = 1;
            }
          }
        }
      }
      FUN_6000d31d(&local_ac,1);
      _DAT_6005a8fc = (int)local_ac >> 8 & 0xf;
      _DAT_6005a8ec = (int)local_ac >> 4 & 0xf;
      _DAT_6005a92c = local_ac & 0xf;
      if (4 < _DAT_6005a8fc) {
        DAT_6005a8e8 = 1;
      }
      if (5 < _DAT_6005a8fc) {
        _DAT_6005a8e4 = 1;
      }
      if (((DAT_6005a8f8 != 0) || (DAT_6005a90c != 0)) && (DAT_6005a8e8 != 0)) {
        FUN_6000d31d(&local_ac,-0x7fffffff);
      }
      DAT_6005a920 = local_a4 >> 0x19 & 1;
      _DAT_6005a8f4 = local_a4 >> 0x1f;
      DAT_6005a924 = local_a4 >> 0x17 & 1;
      _DAT_6005a928 = local_a4 >> 4 & 1;
      _DAT_6005a930 = local_a4 >> 0xf & 1;
      pcVar2 = getenv("ISMMX");
      if (pcVar2 != (char *)0x0) {
        DAT_6005a924 = atoi(pcVar2);
      }
      pcVar2 = getenv("ISK3D");
      if (pcVar2 != (char *)0x0) {
        _DAT_6005a8f4 = atoi(pcVar2);
      }
      local_94.dwOSVersionInfoSize = 0x94;
      GetVersionExA(&local_94);
      if ((local_94.dwPlatformId == 1) && (local_94.dwMinorVersion == 0)) {
        DAT_6005a920 = 0;
      }
      pcVar2 = getenv("ISKNI");
      if (pcVar2 != (char *)0x0) {
        DAT_6005a920 = atoi(pcVar2);
      }
      uVar1 = local_98;
      if (1 < (int)local_98) {
        FUN_6000d31d(&local_ac,2);
      }
      if (2 < (int)uVar1) {
        FUN_6000d31d(&local_ac,3);
        _DAT_6005a900 = local_a0;
        _DAT_6005a904 = local_a4;
        _DAT_6005a908 = local_a8;
        return;
      }
    }
  }
  return;
}



/* VA 6000c0c0 */

undefined8 __cdecl FUN_6000c0c0(longlong *param_1,longlong *param_2,uint param_3)

{
  undefined8 uVar1;

  if (DAT_6005a920 != 0) {
    uVar1 = FUN_60014000(param_1,param_2,param_3);
    return uVar1;
  }
  if (DAT_6005a924 != 0) {
    uVar1 = FUN_60013000(param_1,param_2,param_3);
    return uVar1;
  }
  if ((DAT_6005a8e8 != 0) && (DAT_6005a8f0 != 0)) {
    uVar1 = FUN_60012000(param_1,param_2,param_3);
    return uVar1;
  }
  uVar1 = FUN_60011000((undefined4 *)param_1,(undefined4 *)param_2,param_3);
  return uVar1;
}



/* VA 6000c110 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6000c110(void)

{
  undefined4 local_4;

  local_4 = 0xffffffff;
  DAT_6005a840 = 0;
  (**(code **)(*DAT_60058d9c + 0x10))(DAT_60058d9c,&LAB_6000c450,&local_4);
  _DAT_6005a860 = 0xffffffff;
  DAT_6005a864 = FUN_6000c3c0(4,0,0,0,0,0,0);
  DAT_6005a868 = FUN_6000c3c0(8,0,0,0,0,0,0);
  DAT_6005a86c = FUN_6000c3c0(0,1,5,5,5,0,0);
  DAT_6005a870 = FUN_6000c3c0(0,0,5,6,5,0,0);
  DAT_6005a874 = -1;
  DAT_6005a878 = FUN_6000c3c0(0,8,8,8,8,0,0);
  DAT_6005a87c = FUN_6000c3c0(0,4,4,4,4,0,0);
  DAT_6005a890 = FUN_6000c3c0(0,0,0,0,0,1,0);
  DAT_6005a894 = FUN_6000c3c0(0,0,0,0,0,3,0);
  DAT_6005a898 = -1;
  DAT_6005a89c = -1;
  DAT_6005a8a0 = -1;
  DAT_6005a8a4 = -1;
  DAT_6005a8a8 = FUN_6000c3c0(0,0,8,8,0,0,1);
  DAT_6005a8ac = FUN_6000c3c0(0,0,8,8,8,0,2);
  _DAT_6005a8b0 = FUN_6000c3c0(0,0,5,5,6,0,3);
  _DAT_60017014 = (uint)(DAT_6005a864 != -1);
  _DAT_60017010 = 0;
  _DAT_60017018 = (uint)(DAT_6005a868 != -1);
  _DAT_60017020 = (uint)(DAT_6005a870 != -1);
  _DAT_60017024 = (uint)(DAT_6005a874 != -1);
  _DAT_60017028 = (uint)(DAT_6005a878 != -1);
  _DAT_6001702c = (uint)(DAT_6005a87c != -1);
  _DAT_60017040 = (uint)(DAT_6005a890 != -1);
  _DAT_60017044 = (uint)(DAT_6005a894 != -1);
  _DAT_60017048 = (uint)(DAT_6005a898 != -1);
  _DAT_6001704c = (uint)(DAT_6005a89c != -1);
  _DAT_60017050 = (uint)(DAT_6005a8a0 != -1);
  _DAT_60017054 = (uint)(DAT_6005a8a4 != -1);
  _DAT_60017058 = (uint)(DAT_6005a8a8 != -1);
  _DAT_6001705c = (uint)(DAT_6005a8ac != -1);
  _DAT_60017060 = (uint)(_DAT_6005a8b0 != -1);
  if (DAT_6005a86c == -1) {
    DAT_6005a86c = FUN_6000c3c0(0,0,5,5,5,0,0);
    _DAT_6001701c = (DAT_6005a86c == -1) - 1 & 5;
    return;
  }
  _DAT_6001701c = 1;
  return;
}



/* VA 6000c3c0 */

int __cdecl
FUN_6000c3c0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;

  piVar3 = &DAT_600594c8;
  iVar2 = 0;
  do {
    iVar4 = iVar2;
    if (((piVar3[-2] == param_3) && (*piVar3 == param_4)) && (piVar3[-1] == param_5)) {
      if (piVar3[1] != param_1) goto LAB_6000c422;
      if (((piVar3[2] != param_2) || (piVar3[3] != param_6)) || (piVar3[4] != param_7))
      goto LAB_6000c412;
LAB_6000c41b:
      bVar1 = true;
    }
    else {
LAB_6000c412:
      if ((piVar3[1] == param_1) && (param_1 != 0)) goto LAB_6000c41b;
LAB_6000c422:
      bVar1 = false;
    }
    piVar3 = piVar3 + 0x28;
    if (DAT_6005a840 <= iVar4 + 1) {
      if (bVar1) {
        return iVar4;
      }
      return -1;
    }
    iVar2 = iVar4 + 1;
    if (bVar1) {
      return iVar4;
    }
  } while( true );
}



/* VA 6000c790 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int __cdecl FUN_6000c790(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  int *piVar9;
  undefined1 *puVar10;
  int *piStack_4a8;
  int *piVar11;
  undefined8 local_47c;
  undefined4 uStack_474;
  undefined4 uStack_470;
  int iStack_464;
  byte bStack_458;
  uint auStack_44c [9];
  undefined8 uStack_428;
  undefined4 uStack_420;
  undefined4 uStack_41c;
  undefined4 uStack_414;
  undefined4 uStack_410;
  int iStack_24;
  int iStack_14;
  int iStack_10;

  if (*(int **)(param_1 + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x34) + 8))();
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  puVar6 = &local_47c;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)puVar6 = 0;
    puVar6 = (undefined8 *)((int)puVar6 + 4);
  }
  piStack_4a8 = (int *)0x6000c7e8;
  FUN_6000c0c0(&local_47c,(longlong *)(&DAT_60059440 + *(int *)(param_1 + 0x24) * 0xa0),0x7c);
  local_47c._0_4_ = 0x7c;
  if (*(int *)(param_1 + 0x14) == 0) {
    local_47c._4_4_ = 0x1007;
    uStack_414 = 0x1800;
  }
  else {
    local_47c._4_4_ = 0x21007;
    uStack_414 = 0x401808;
    iStack_464 = *(int *)(param_1 + 0x14);
  }
  iVar2 = 8;
  if (DAT_600170f4 == 1) {
    uStack_410 = 4;
  }
  else if (DAT_600170f4 == 2) {
    uStack_410 = 8;
  }
  uStack_474 = *(undefined4 *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0xc);
  uStack_470 = *(undefined4 *)(param_1 + 4);
  if ((iVar1 == 0xc) || (iVar1 == 0xd)) {
    puVar8 = auStack_44c + 6;
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    auStack_44c[6] = 0x20;
    auStack_44c[7] = 4;
    if (iVar1 == 0xc) {
      auStack_44c[8] = 0x31545844;
    }
    else if (iVar1 == 0xd) {
      auStack_44c[8] = 0x33545844;
    }
  }
  if (iVar1 == 0x12) {
    puVar8 = auStack_44c + 6;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    auStack_44c[6] = 0x20;
    auStack_44c[7] = 0x80000;
    uStack_428._0_4_ = 0x10;
    uStack_428._4_4_ = 0xff;
    uStack_420 = 0xff00;
    uStack_41c = 0;
  }
  if (iVar1 == 0x14) {
    puVar8 = auStack_44c + 6;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    auStack_44c[6] = 0x20;
    auStack_44c[7] = 0x80000;
    uStack_428._0_4_ = 0x10;
    uStack_428._4_4_ = 0x1f;
    uStack_420 = 0x3e0;
    uStack_41c = 0xfc00;
  }
  if (iVar1 == 0x13) {
    puVar8 = auStack_44c + 6;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    auStack_44c[6] = 0x20;
    auStack_44c[7] = 0x80000;
    uStack_428._0_4_ = 0x18;
    uStack_428._4_4_ = 0xff;
    uStack_420 = 0xff00;
    uStack_41c = 0xff0000;
  }
  piVar11 = (int *)0x0;
  piStack_4a8 = DAT_60058d80;
  iVar2 = (**(code **)(*DAT_60058d80 + 0x18))();
  if (iVar2 != 0) {
    return (iVar2 != -0x7789ff6f) - 1;
  }
  puVar4 = (undefined4 *)&stack0xfffffb74;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  iVar2 = *unaff_ESI;
  *(int **)(param_1 + 0x30) = unaff_ESI;
  iVar2 = (**(code **)(iVar2 + 0x58))();
  if (iVar2 != 0) {
    if (piVar11 == (int *)0x0) {
      return 0;
    }
    (**(code **)(*piVar11 + 8))(piVar11);
    return 0;
  }
  iVar2 = *(int *)(iStack_14 + 0x14);
  puVar4 = (undefined4 *)&stack0xfffffb6c;
  puVar7 = (undefined4 *)(iStack_14 + 0x3c);
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  if (iVar2 == 0) {
    auStack_44c[8] = 0x1000;
  }
  else {
    auStack_44c[8] = 0x401008;
    local_47c._0_4_ = iVar2;
  }
  if (DAT_600170f4 == 1) {
    uStack_428._0_4_ = 4;
  }
  else if (DAT_600170f4 == 2) {
    uStack_428._0_4_ = 8;
  }
  if (iStack_10 != 0) {
    auStack_44c[8] = auStack_44c[8] | 0x2000;
  }
  if ((iVar1 == 0xc) || (iVar1 == 0xd)) {
    puVar8 = auStack_44c;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    auStack_44c[0] = 0x20;
    auStack_44c[1] = 4;
    if (iVar1 == 0xc) {
      auStack_44c[2] = 0x31545844;
    }
    else if (iVar1 == 0xd) {
      auStack_44c[2] = 0x33545844;
    }
  }
  if (iVar1 == 0x12) {
    puVar8 = auStack_44c;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    auStack_44c[0] = 0x20;
    auStack_44c[1] = 0x80000;
    auStack_44c[3] = 0x10;
    auStack_44c[4] = 0xff;
    auStack_44c[5] = 0xff00;
    auStack_44c[6] = 0;
  }
  if (iVar1 == 0x14) {
    puVar8 = auStack_44c;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    auStack_44c[0] = 0x20;
    auStack_44c[1] = 0x80000;
    auStack_44c[3] = 0x10;
    auStack_44c[4] = 0x1f;
    auStack_44c[5] = 0x3e0;
    auStack_44c[6] = 0xfc00;
  }
  if (iVar1 == 0x13) {
    puVar8 = auStack_44c;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    auStack_44c[0] = 0x20;
    auStack_44c[1] = 0x80000;
    auStack_44c[3] = 0x18;
    auStack_44c[4] = 0xff;
    auStack_44c[5] = 0xff00;
    auStack_44c[6] = 0xff0000;
  }
  if (DAT_6005aae0 == 0) {
    auStack_44c[8] = auStack_44c[8] | 0x800;
  }
  else {
    auStack_44c[8] = auStack_44c[8] | 0x4000;
  }
  puVar10 = &stack0xfffffb6c;
  piVar11 = DAT_60058d80;
  iVar2 = (**(code **)(*DAT_60058d80 + 0x18))(DAT_60058d80,puVar10,&stack0xfffffb60,0);
  if (iVar2 < 0) {
    if (&stack0xfffffb74 != (undefined1 *)0x0) {
      (*pcRam00000084)(&stack0xfffffb74);
    }
    return (iVar2 != -0x7789ff6f) - 1;
  }
  if ((bStack_458 & 0x20) == 0) {
    if ((bStack_458 & 8) != 0) {
      uVar5 = 1;
      *(undefined4 *)(iStack_24 + 0xb8) = 0x10;
      goto LAB_6000cbb2;
    }
    *(undefined4 *)(iStack_24 + 0xb8) = 0;
    *(undefined4 *)(iStack_24 + 0x38) = 0;
  }
  else {
    uVar5 = 0x44;
    *(undefined4 *)(iStack_24 + 0xb8) = 0x100;
LAB_6000cbb2:
    FUN_6000bad0(&uStack_428,0xff0000,0x400);
    piVar9 = (int *)0x0;
    iVar2 = (**(code **)(*DAT_60058d80 + 0x14))(DAT_60058d80,uVar5,&uStack_428,&piStack_4a8);
    if (iVar2 != 0) {
      if (piVar9 != (int *)0x0) {
        (**(code **)(*piVar9 + 8))(piVar9);
      }
      if (piVar11 == (int *)0x0) {
        return 0;
      }
      (**(code **)(*piVar11 + 8))(piVar11);
      return 0;
    }
    iVar2 = (**(code **)(*piVar9 + 0x7c))(piVar9,puVar10);
    if (iVar2 != 0) goto LAB_6000ccc3;
    *(int **)(iStack_24 + 0x38) = piStack_4a8;
  }
  iVar2 = (**(code **)(*unaff_ESI + 0x14))(unaff_ESI,0,&stack0xfffffb74,0,0x1000000,0);
  if (-1 < iVar2) {
    FUN_6000bad0((undefined8 *)&stack0xfffffb5c,0,0x7c);
    iVar2 = (**(code **)(*unaff_ESI + 0x58))(unaff_ESI,&stack0xfffffb5c);
    if (iVar2 == 0) {
      if ((auStack_44c[4] & 0x4000) == 0) {
        if ((auStack_44c[4] & 0x800) == 0) {
          *(undefined4 *)(iStack_24 + 0x28) = 0;
        }
        else {
          *(undefined4 *)(iStack_24 + 0x28) = 2;
        }
      }
      else if ((auStack_44c[4] & 0x10000000) == 0) {
        if ((auStack_44c[4] & 0x20000000) != 0) {
          *(undefined4 *)(iStack_24 + 0x28) = 2;
        }
      }
      else {
        *(undefined4 *)(iStack_24 + 0x28) = 1;
      }
      *(int **)(iStack_24 + 0x34) = unaff_ESI;
      return 1;
    }
  }
LAB_6000ccc3:
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
  }
  if (&stack0xfffffb74 != (undefined1 *)0x0) {
    (*pcRam00000084)(&stack0xfffffb74);
  }
  if (piStack_4a8 != (int *)0x0) {
    (**(code **)(*piStack_4a8 + 8))(piStack_4a8);
  }
  return 0;
}



/* VA 6000cd50 */

undefined4 __cdecl
FUN_6000cd50(longlong *param_1,longlong *param_2,undefined4 *param_3,int param_4,int param_5,
            int param_6,int param_7,uint param_8)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  longlong *plVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 local_424 [1024];
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  plVar5 = param_1;
  plVar7 = (longlong *)&stack0xfffffbd0;
  if (param_2 != (longlong *)0x0) {
    local_24 = 0;
    local_20 = 0;
    local_14 = param_4;
    local_c = param_4 + param_6;
    local_1c = param_6;
    local_10 = param_5;
    local_8 = param_5 + param_7;
    local_18 = param_7;
    *(undefined4 *)(param_1 + 8) = 0x800;
    if ((*(int *)((int)param_1 + 0xc) == 0xc) ||
       (plVar8 = param_2, *(int *)((int)param_1 + 0xc) == 0xd)) {
      plVar8 = param_2 + 1;
    }
    *(longlong **)(param_1 + 0xc) = plVar8;
    uVar1 = *(uint *)((int)param_1 + 0x4c);
    if (param_8 != uVar1) {
      FUN_6000d510();
      FUN_6000bad0((undefined8 *)&stack0xfffffbd0,0xffffffff,uVar1 * param_7);
      param_1 = param_2;
      if ((*(int *)((int)plVar5 + 0xc) == 0xc) || (*(int *)((int)plVar5 + 0xc) == 0xd)) {
        *(undefined1 **)(plVar5 + 0xc) = &stack0xfffffbd8;
      }
      else {
        *(undefined1 **)(plVar5 + 0xc) = &stack0xfffffbd0;
      }
      if (0 < param_7) {
        do {
          FUN_6000c0c0(plVar7,param_1,param_8);
          param_1 = (longlong *)((int)param_1 + param_8);
          plVar7 = (longlong *)((int)plVar7 + *(int *)((int)plVar5 + 0x4c));
          param_7 = param_7 + -1;
        } while (param_7 != 0);
      }
    }
    iVar6 = (**(code **)(**(int **)(plVar5 + 6) + 0x9c))(*(int **)(plVar5 + 6),(int)plVar5 + 0x3c,0)
    ;
    if (iVar6 < 0) {
      return 0;
    }
    if (DAT_6001822c != 0) {
      FUN_60006f10();
      FUN_60008860();
    }
    (**(code **)(**(int **)((int)plVar5 + 0x34) + 0x14))
              (*(int **)((int)plVar5 + 0x34),&local_14,(int)plVar5[6],&local_24,0x1000000,0);
  }
  if ((param_3 != (undefined4 *)0x0) && ((int)plVar5[2] != 0)) {
    iVar6 = -(int)param_3;
    iVar3 = 2 - (int)param_3;
    iVar4 = 3 - (int)param_3;
    param_7 = 0x100;
    do {
      (local_424 + iVar6)[(int)param_3] = *(undefined1 *)((int)param_3 + 2);
      (local_424 + iVar6 + 1)[(int)param_3] = (char)((uint)*param_3 >> 8);
      (local_424 + iVar3)[(int)param_3] = *(undefined1 *)param_3;
      (local_424 + iVar4)[(int)param_3] = 0;
      param_3 = param_3 + 1;
      param_7 = param_7 + -1;
    } while (param_7 != 0);
    piVar2 = *(int **)(plVar5 + 7);
    iVar6 = (**(code **)(*piVar2 + 0x18))(piVar2,0,0,(int)plVar5[0x17],local_424);
    if (iVar6 < 0) {
      return 0;
    }
    iVar6 = (**(code **)(**(int **)((int)plVar5 + 0x34) + 0x7c))
                      (*(int **)((int)plVar5 + 0x34),piVar2);
    if (iVar6 < 0) {
      return 0;
    }
  }
  if (0 < *(int *)((int)plVar5 + 0x14)) {
    FUN_6000d0c0((int)plVar5,(int)param_2);
  }
  return 1;
}



/* VA 6000cf50 */

undefined4 __cdecl FUN_6000cf50(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_400 [1024];

  if (param_2 == 0) {
    if (param_3 == (undefined4 *)0x0) {
      return 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x40) = 0x800;
    if ((*(int *)(param_1 + 0xc) == 0xc) || (*(int *)(param_1 + 0xc) == 0xd)) {
      *(int *)(param_1 + 0x60) = param_2 + 8;
    }
    else {
      *(int *)(param_1 + 0x60) = param_2;
    }
    iVar4 = (**(code **)(**(int **)(param_1 + 0x30) + 0x9c))
                      (*(int **)(param_1 + 0x30),param_1 + 0x3c,0);
    if (iVar4 < 0) {
      return 0;
    }
    if (DAT_6001822c != 0) {
      FUN_60006f10();
      FUN_60008860();
    }
    iVar4 = (**(code **)(**(int **)(param_1 + 0x34) + 0x14))
                      (*(int **)(param_1 + 0x34),0,*(undefined4 *)(param_1 + 0x30),0,0x1000000,0);
    if (iVar4 < 0) {
      return 0;
    }
    if (param_3 == (undefined4 *)0x0) goto LAB_6000d09f;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar4 = -(int)param_3;
    iVar2 = 2 - (int)param_3;
    iVar3 = 3 - (int)param_3;
    iVar5 = 0x100;
    do {
      (auStack_400 + iVar4)[(int)param_3] = *(undefined1 *)((int)param_3 + 2);
      (auStack_400 + iVar4 + 1)[(int)param_3] = (char)((uint)*param_3 >> 8);
      (auStack_400 + iVar2)[(int)param_3] = *(undefined1 *)param_3;
      *(undefined1 *)((int)param_3 + (int)(auStack_400 + iVar3)) = 0;
      param_3 = param_3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    piVar1 = *(int **)(param_1 + 0x38);
    iVar4 = (**(code **)(*piVar1 + 0x18))(piVar1,0,0,*(undefined4 *)(param_1 + 0xb8),auStack_400);
    if (iVar4 < 0) {
      return 0;
    }
    iVar4 = (**(code **)(**(int **)(param_1 + 0x34) + 0x7c))(*(int **)(param_1 + 0x34),piVar1);
    if (iVar4 < 0) {
      return 0;
    }
  }
LAB_6000d09f:
  if (0 < *(int *)(param_1 + 0x14)) {
    FUN_6000d0c0(param_1,param_2);
  }
  return 1;
}



/* VA 6000d0c0 */

undefined4 __cdecl FUN_6000d0c0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  int *piStack_f0;
  int iStack_ec;
  int *piStack_e8;
  int *piStack_e4;
  undefined4 *puStack_e0;
  int **ppiStack_dc;
  int *piStack_d8;
  int *piStack_d4;
  undefined4 *puStack_d0;
  int **ppiStack_cc;
  int *piStack_c8;
  uint *puStack_c4;
  int *piStack_c0;
  int *piStack_bc;
  uint local_ac [4];
  uint local_9c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  int local_10;
  longlong *local_c;
  longlong *local_8;

  local_1c = (int *)0x0;
  local_14 = (int *)0x0;
  local_10 = 0;
  local_8 = (longlong *)0x0;
  local_c = (longlong *)0x0;
  local_30 = 0;
  piVar3 = *(int **)(param_1 + 0x30);
  local_2c = 0;
  local_28 = 0;
  puVar4 = local_ac;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_24 = 0;
  local_ac[0] = 0x7c;
  piStack_c0 = (int *)0x6000d10c;
  piStack_bc = piVar3;
  (**(code **)(*piVar3 + 4))();
  piVar6 = *(int **)(param_1 + 0x34);
  puStack_c4 = (uint *)0x6000d115;
  piStack_c0 = piVar6;
  (**(code **)(*piVar6 + 4))();
  if ((*(int *)(param_1 + 0xc) == 0xc) || (*(int *)(param_1 + 0xc) == 0xd)) {
    local_10 = 8;
  }
  local_18 = 0;
  if (*(int *)(param_1 + 0x14) != 1 && -1 < *(int *)(param_1 + 0x14) + -1) {
    do {
      if (param_2 != 0) {
        puStack_c4 = local_ac;
        ppiStack_cc = (int **)0x6000d158;
        piStack_c8 = piVar3;
        (**(code **)(*piVar3 + 0x58))();
        if (*(int *)(param_1 + 0xc) == 0xc) {
          local_9c = local_9c / local_ac[2];
        }
        if (*(int *)(param_1 + 0xc) == 0xd) {
          local_9c = local_9c / local_ac[2];
        }
        local_10 = local_10 + local_ac[2] * local_9c;
        ppiStack_cc = &local_1c;
        puStack_d0 = &local_30;
        local_30 = 0x401000;
        piStack_d8 = (int *)0x6000d1a6;
        piStack_d4 = piVar3;
        (**(code **)(*piVar3 + 0x30))();
        ppiStack_dc = (int **)0x6000d1ac;
        piStack_d8 = piVar3;
        (**(code **)(*piVar3 + 8))();
        piVar3 = local_1c;
        ppiStack_dc = &local_14;
        puStack_e0 = &local_30;
        piStack_e8 = (int *)0x6000d1bd;
        piStack_e4 = piVar6;
        (**(code **)(*piVar6 + 0x30))();
        iStack_ec = 0x6000d1c3;
        piStack_e8 = piVar6;
        (**(code **)(*piVar6 + 8))();
        iStack_ec = param_1 + 0x3c;
        piStack_f0 = piVar3;
        local_20 = local_14;
        (**(code **)(*piVar3 + 0x58))();
        uVar5 = *(int *)(param_1 + 0x90) * *(int *)(param_1 + 0x48) + 7U >> 3;
        *(undefined4 *)(param_1 + 0x40) = 0x800;
        if ((*(int *)(param_1 + 0xc) == 0xc) || (*(int *)(param_1 + 0xc) == 0xd)) {
          uVar5 = *(uint *)(param_1 + 0x4c);
        }
        if (uVar5 == *(uint *)(param_1 + 0x4c)) {
          *(int *)(param_1 + 0x60) = local_10 + param_2;
        }
        else {
          if (local_8 == (longlong *)0x0) {
            uVar1 = local_ac[2] * local_9c;
            FUN_6000d510();
            local_8 = (longlong *)&piStack_f0;
            FUN_6000bad0((undefined8 *)&piStack_f0,0xffffffff,uVar1);
          }
          if (local_c == (longlong *)0x0) {
            local_c = (longlong *)(local_10 + param_2);
          }
          iVar2 = *(int *)(param_1 + 0x44);
          *(longlong **)(param_1 + 0x60) = local_8;
          for (; iVar2 != 0; iVar2 = iVar2 + -1) {
            FUN_6000c0c0(local_8,local_c,uVar5);
            local_8 = (longlong *)((int)local_8 + *(int *)(param_1 + 0x4c));
            local_c = (longlong *)((int)local_c + uVar5);
          }
        }
        (**(code **)(*piVar3 + 0x9c))(piVar3,param_1 + 0x3c,0);
        (**(code **)(*local_20 + 0x14))(local_20,0,piVar3,0,0x1000000,0);
        piVar6 = local_20;
      }
      piStack_c8 = (int *)0x6000d2c7;
      puStack_c4 = (uint *)piVar3;
      (**(code **)(*piVar3 + 8))();
      ppiStack_cc = (int **)0x6000d2cd;
      piStack_c8 = piVar6;
      (**(code **)(*piVar6 + 8))();
      local_18 = local_18 + 1;
    } while (local_18 < *(int *)(param_1 + 0x14) + -1);
  }
  return 1;
}



/* VA 6000d300 */

uint FUN_6000d300(void)

{
  uint uVar1;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar2;
  undefined1 auStack_2c [32];

  uVar2 = (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffff4,0x20) * 0x800 |
          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)auStack_2c < 0) * 0x80
          | (uint)(&stack0x00000000 == (undefined1 *)0x2c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT((uint)auStack_2c & 0xff) & 1U) == 0) * 4 |
          (uint)(&stack0xfffffff4 < (undefined1 *)0x20) | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar1 = uVar2 ^ 0x200000;
  return ((uint)((uVar1 & 0x4000) != 0) * 0x4000 | (uint)((uVar1 & 0x800) != 0) * 0x800 |
          (uint)((uVar1 & 0x200) != 0) * 0x200 | (uint)((uVar1 & 0x100) != 0) * 0x100 |
          (uint)((uVar1 & 0x80) != 0) * 0x80 | (uint)((uVar1 & 0x40) != 0) * 0x40 |
          (uint)((uVar1 & 0x10) != 0) * 0x10 | (uint)((uVar1 & 4) != 0) * 4 |
          (uint)((uVar1 & 1) != 0) | (uint)((uVar1 & 0x200000) != 0) * 0x200000 |
         (uint)((uVar1 & 0x40000) != 0) * 0x40000) ^ uVar2;
}



/* VA 6000d31d */

void __cdecl FUN_6000d31d(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;

  if (param_2 == 0) {
    puVar1 = (undefined4 *)cpuid_basic_info(0);
  }
  else if (param_2 == 1) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
  }
  else if (param_2 == 2) {
    puVar1 = (undefined4 *)cpuid_cache_tlb_info(2);
  }
  else if (param_2 == 3) {
    puVar1 = (undefined4 *)cpuid_serial_info(3);
  }
  else if (param_2 == 4) {
    puVar1 = (undefined4 *)cpuid_Deterministic_Cache_Parameters_info(4);
  }
  else if (param_2 == 5) {
    puVar1 = (undefined4 *)cpuid_MONITOR_MWAIT_Features_info(5);
  }
  else if (param_2 == 6) {
    puVar1 = (undefined4 *)cpuid_Thermal_Power_Management_info(6);
  }
  else if (param_2 == 7) {
    puVar1 = (undefined4 *)cpuid_Extended_Feature_Enumeration_info(7);
  }
  else if (param_2 == 9) {
    puVar1 = (undefined4 *)cpuid_Direct_Cache_Access_info(9);
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)cpuid_Architectural_Performance_Monitoring_info(10);
  }
  else if (param_2 == 0xb) {
    puVar1 = (undefined4 *)cpuid_Extended_Topology_info(0xb);
  }
  else if (param_2 == 0xd) {
    puVar1 = (undefined4 *)cpuid_Processor_Extended_States_info(0xd);
  }
  else if (param_2 == 0xf) {
    puVar1 = (undefined4 *)cpuid_Quality_of_Service_info(0xf);
  }
  else if (param_2 == -0x7ffffffe) {
    puVar1 = (undefined4 *)cpuid_brand_part1_info(0x80000002);
  }
  else if (param_2 == -0x7ffffffd) {
    puVar1 = (undefined4 *)cpuid_brand_part2_info(0x80000003);
  }
  else if (param_2 == -0x7ffffffc) {
    puVar1 = (undefined4 *)cpuid_brand_part3_info(0x80000004);
  }
  else {
    puVar1 = (undefined4 *)cpuid(param_2);
  }
  uVar4 = puVar1[1];
  uVar3 = puVar1[2];
  uVar2 = puVar1[3];
  *param_1 = *puVar1;
  param_1[1] = uVar4;
  param_1[2] = uVar3;
  param_1[3] = uVar2;
  return;
}



/* VA 6000d33f */

undefined8 __fastcall FUN_6000d33f(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,1);
}



/* VA 6000d370 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6000d370(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *_Memory;
  undefined4 *puVar2;

  if (param_2 == 0) {
    if (0 < DAT_6005a848) {
      DAT_6005a848 = DAT_6005a848 + -1;
      goto LAB_6000d386;
    }
LAB_6000d3ae:
    uVar1 = 0;
  }
  else {
LAB_6000d386:
    _DAT_600fc894 = *(undefined4 *)_adjust_fdiv_exref;
    if (param_2 == 1) {
      DAT_600fc89c = malloc(0x80);
      if (DAT_600fc89c == (undefined4 *)0x0) goto LAB_6000d3ae;
      *DAT_600fc89c = 0;
      DAT_600fc898 = DAT_600fc89c;
      initterm(&DAT_60017000,&DAT_60017004);
      DAT_6005a848 = DAT_6005a848 + 1;
    }
    else if ((param_2 == 0) &&
            (_Memory = DAT_600fc89c, puVar2 = DAT_600fc898, DAT_600fc89c != (undefined4 *)0x0)) {
      while (puVar2 = puVar2 + -1, _Memory <= puVar2) {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          _Memory = DAT_600fc89c;
        }
      }
      free(_Memory);
      DAT_600fc89c = (undefined4 *)0x0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* VA 6000d41b */

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = param_2;
  iVar2 = DAT_6005a848;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_6000d463;
    if ((DAT_600fc8a0 != (code *)0x0) &&
       (iVar2 = (*DAT_600fc8a0)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_6000d370(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_6000d463:
  iVar2 = FUN_6000d546(param_1,param_2);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_6000d370(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_6000d370(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_600fc8a0 != (code *)0x0) {
      iVar2 = (*DAT_600fc8a0)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}



/* VA 6000d4c0 */

void __cdecl FUN_6000d4c0(_onexit_t param_1)

{
  if (DAT_600fc89c == -1) {
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_600fc89c,&DAT_600fc898);
  return;
}



/* VA 6000d4ec */

int __cdecl FUN_6000d4ec(_onexit_t param_1)

{
  int iVar1;

  iVar1 = FUN_6000d4c0(param_1);
  return (iVar1 != 0) - 1;
}



/* VA 6000d4fe */

void __cdecl ftol(void)

{
                    /* WARNING: Could not recover jumptable at 0x6000d4fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ftol();
  return;
}



/* VA 6000d510 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_6000d510(void)

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



/* VA 6000d540 */

void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x6000d540. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}



/* VA 6000d546 */

undefined4 FUN_6000d546(HMODULE param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_600fc8a0 == 0)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* VA 6000d566 */

void __dllonexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x6000d566. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __dllonexit();
  return;
}



/* VA 6000d56c */

void DirectDrawCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x6000d56c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawCreate();
  return;
}



/* VA 6000d572 */

void DirectDrawCreateEx(void)

{
                    /* WARNING: Could not recover jumptable at 0x6000d572. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawCreateEx();
  return;
}



/* VA 6000d578 */

void DirectDrawEnumerateExA(void)

{
                    /* WARNING: Could not recover jumptable at 0x6000d578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawEnumerateExA();
  return;
}



/* VA 6000d580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_6000d580(float *param_1,int param_2)

{
  float fVar1;

  fVar1 = _DAT_6001544c;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    *param_1 = *param_1 - fVar1;
    param_1[1] = param_1[1] - fVar1;
    param_1 = param_1 + 8;
  }
  return;
}



/* VA 6000e000 */

undefined4 * __cdecl FUN_6000e000(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  if (((uint)param_1 & 3) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      *(char *)param_1 = (char)param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      *(short *)param_1 = (short)param_2;
      param_1 = (undefined4 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      *param_1 = param_2;
      param_1 = param_1 + 1;
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    *param_1 = param_2;
    param_1[1] = param_2;
    param_1[2] = param_2;
    param_1[3] = param_2;
    param_1[4] = param_2;
    param_1[5] = param_2;
    param_1[6] = param_2;
    param_1[7] = param_2;
    param_1 = param_1 + 8;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = param_2;
    param_1[1] = param_2;
    param_1 = param_1 + 2;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return param_1;
  }
  if (3 < param_3) {
    *param_1 = param_2;
    param_1 = param_1 + 1;
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    *(short *)param_1 = (short)param_2;
    param_1 = (undefined4 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    *(char *)param_1 = (char)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return param_1;
}



/* VA 6000f000 */

undefined8 * __cdecl FUN_6000f000(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  undefined8 uVar1;

  if (((uint)param_1 & 3) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      *(char *)param_1 = (char)param_2;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      *(short *)param_1 = (short)param_2;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      *(undefined4 *)param_1 = param_2;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
  }
  uVar1 = CONCAT44(param_2,param_2);
  while (-1 < (int)(param_3 - 0x20)) {
    *param_1 = uVar1;
    param_1[1] = uVar1;
    param_1[2] = uVar1;
    param_1[3] = uVar1;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = uVar1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return param_1;
  }
  if (3 < param_3) {
    *(undefined4 *)param_1 = param_2;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    *(short *)param_1 = (short)param_2;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    *(char *)param_1 = (char)param_2;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return param_1;
}



/* VA 60010000 */

undefined8 * __cdecl FUN_60010000(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  if (((uint)param_1 & 0x1f) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      *(char *)param_1 = (char)param_2;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      *(short *)param_1 = (short)param_2;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      *(undefined4 *)param_1 = param_2;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
    if ((((uint)param_1 & 8) != 0) && (7 < (int)param_3)) {
      *param_1 = CONCAT44(param_2,param_2);
      param_1 = param_1 + 1;
      param_3 = param_3 - 8;
    }
    if ((((uint)param_1 & 0x10) != 0) && (0xf < (int)param_3)) {
      *(undefined4 *)param_1 = param_2;
      *(undefined4 *)((int)param_1 + 4) = param_2;
      *(undefined4 *)(param_1 + 1) = param_2;
      *(undefined4 *)((int)param_1 + 0xc) = param_2;
      param_1 = param_1 + 2;
      param_3 = param_3 - 0x10;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    *(undefined4 *)param_1 = param_2;
    *(undefined4 *)((int)param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 1) = param_2;
    *(undefined4 *)((int)param_1 + 0xc) = param_2;
    *(undefined4 *)(param_1 + 2) = param_2;
    *(undefined4 *)((int)param_1 + 0x14) = param_2;
    *(undefined4 *)(param_1 + 3) = param_2;
    *(undefined4 *)((int)param_1 + 0x1c) = param_2;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = CONCAT44(param_2,param_2);
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return param_1;
  }
  if (3 < param_3) {
    *(undefined4 *)param_1 = param_2;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    *(short *)param_1 = (short)param_2;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    *(char *)param_1 = (char)param_2;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return param_1;
}



/* VA 60011000 */

undefined8 __cdecl FUN_60011000(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;

  if (((uint)param_1 & 3) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      uVar1 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      *(undefined1 *)param_1 = uVar1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      uVar2 = *(undefined2 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 2);
      *(undefined2 *)param_1 = uVar2;
      param_1 = (undefined4 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar3;
      param_1 = param_1 + 1;
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    param_1[6] = param_2[6];
    param_1[7] = param_2[7];
    param_2 = param_2 + 8;
    param_1 = param_1 + 8;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_2 = param_2 + 2;
    param_1 = param_1 + 2;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar3;
    param_1 = param_1 + 1;
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    uVar2 = *(undefined2 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 2);
    *(undefined2 *)param_1 = uVar2;
    param_1 = (undefined4 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    uVar1 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = uVar1;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}



/* VA 60012000 */

undefined8 __cdecl FUN_60012000(longlong *param_1,longlong *param_2,uint param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;

  if (((uint)param_1 & 7) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      lVar6 = *param_2;
      param_2 = (longlong *)((int)param_2 + 1);
      *(char *)param_1 = (char)lVar6;
      param_1 = (longlong *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      lVar6 = *param_2;
      param_2 = (longlong *)((int)param_2 + 2);
      *(short *)param_1 = (short)lVar6;
      param_1 = (longlong *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      lVar6 = *param_2;
      param_2 = (longlong *)((int)param_2 + 4);
      *(int *)param_1 = (int)lVar6;
      param_1 = (longlong *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x80)) {
    lVar6 = param_2[4];
    lVar1 = param_2[8];
    lVar2 = param_2[0xc];
    lVar3 = param_2[2];
    lVar4 = param_2[1];
    lVar5 = param_2[3];
    *param_1 = (longlong)ROUND((float10)*param_2);
    param_1[1] = (longlong)ROUND((float10)lVar4);
    param_1[2] = (longlong)ROUND((float10)lVar3);
    param_1[3] = (longlong)ROUND((float10)lVar5);
    lVar3 = param_2[6];
    lVar4 = param_2[5];
    lVar5 = param_2[7];
    param_1[4] = (longlong)ROUND((float10)lVar6);
    param_1[5] = (longlong)ROUND((float10)lVar4);
    param_1[6] = (longlong)ROUND((float10)lVar3);
    param_1[7] = (longlong)ROUND((float10)lVar5);
    lVar6 = param_2[10];
    lVar3 = param_2[9];
    lVar4 = param_2[0xb];
    param_1[8] = (longlong)ROUND((float10)lVar1);
    param_1[9] = (longlong)ROUND((float10)lVar3);
    param_1[10] = (longlong)ROUND((float10)lVar6);
    param_1[0xb] = (longlong)ROUND((float10)lVar4);
    lVar6 = param_2[0xe];
    lVar1 = param_2[0xd];
    lVar3 = param_2[0xf];
    param_1[0xc] = (longlong)ROUND((float10)lVar2);
    param_1[0xd] = (longlong)ROUND((float10)lVar1);
    param_1[0xe] = (longlong)ROUND((float10)lVar6);
    param_1[0xf] = (longlong)ROUND((float10)lVar3);
    param_2 = param_2 + 0x10;
    param_1 = param_1 + 0x10;
    param_3 = param_3 - 0x80;
  }
  while (-1 < (int)(param_3 - 0x20)) {
    lVar6 = param_2[1];
    *param_1 = (longlong)ROUND((float10)*param_2);
    param_1[1] = (longlong)ROUND((float10)lVar6);
    lVar6 = param_2[3];
    param_1[2] = (longlong)ROUND((float10)param_2[2]);
    param_1[3] = (longlong)ROUND((float10)lVar6);
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = (longlong)ROUND((float10)*param_2);
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    lVar6 = *param_2;
    param_2 = (longlong *)((int)param_2 + 4);
    *(int *)param_1 = (int)lVar6;
    param_1 = (longlong *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    lVar6 = *param_2;
    param_2 = (longlong *)((int)param_2 + 2);
    *(short *)param_1 = (short)lVar6;
    param_1 = (longlong *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    lVar6 = *param_2;
    param_2 = (longlong *)((int)param_2 + 1);
    *(char *)param_1 = (char)lVar6;
    param_1 = (longlong *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}



/* VA 60013000 */

undefined8 __cdecl FUN_60013000(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;

  if (((uint)param_1 & 7) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      uVar7 = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 1);
      *(undefined1 *)param_1 = uVar7;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      uVar8 = *(undefined2 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 2);
      *(undefined2 *)param_1 = uVar8;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      uVar9 = *(undefined4 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = uVar9;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
  }
  while (-1 < (int)(param_3 - 0x80)) {
    uVar4 = param_2[4];
    uVar5 = param_2[8];
    uVar6 = param_2[0xc];
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    uVar1 = param_2[5];
    uVar2 = param_2[6];
    uVar3 = param_2[7];
    param_1[4] = uVar4;
    param_1[5] = uVar1;
    param_1[6] = uVar2;
    param_1[7] = uVar3;
    uVar4 = param_2[9];
    uVar1 = param_2[10];
    uVar2 = param_2[0xb];
    param_1[8] = uVar5;
    param_1[9] = uVar4;
    param_1[10] = uVar1;
    param_1[0xb] = uVar2;
    uVar4 = param_2[0xd];
    uVar5 = param_2[0xe];
    uVar1 = param_2[0xf];
    param_1[0xc] = uVar6;
    param_1[0xd] = uVar4;
    param_1[0xe] = uVar5;
    param_1[0xf] = uVar1;
    param_2 = param_2 + 0x10;
    param_1 = param_1 + 0x10;
    param_3 = param_3 - 0x80;
  }
  while (-1 < (int)(param_3 - 0x20)) {
    uVar4 = param_2[1];
    uVar5 = param_2[2];
    uVar6 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar4;
    param_1[2] = uVar5;
    param_1[3] = uVar6;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    uVar9 = *(undefined4 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 4);
    *(undefined4 *)param_1 = uVar9;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    uVar8 = *(undefined2 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 2);
    *(undefined2 *)param_1 = uVar8;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    uVar7 = *(undefined1 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = uVar7;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}



/* VA 60014000 */

undefined8 __cdecl FUN_60014000(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;

  if (((uint)param_1 & 0x1f) != 0) {
    if ((((uint)param_1 & 1) != 0) && (0 < (int)param_3)) {
      uVar2 = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 1);
      *(undefined1 *)param_1 = uVar2;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_3 = param_3 - 1;
    }
    if ((((uint)param_1 & 2) != 0) && (1 < (int)param_3)) {
      uVar3 = *(undefined2 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 2);
      *(undefined2 *)param_1 = uVar3;
      param_1 = (undefined8 *)((int)param_1 + 2);
      param_3 = param_3 - 2;
    }
    if ((((uint)param_1 & 4) != 0) && (3 < (int)param_3)) {
      uVar4 = *(undefined4 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = uVar4;
      param_1 = (undefined8 *)((int)param_1 + 4);
      param_3 = param_3 - 4;
    }
    if ((((uint)param_1 & 8) != 0) && (7 < (int)param_3)) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
      param_3 = param_3 - 8;
    }
    if ((((uint)param_1 & 0x10) != 0) && (0xf < (int)param_3)) {
      uVar4 = *(undefined4 *)param_2;
      uVar5 = *(undefined4 *)((int)param_2 + 4);
      uVar6 = *(undefined4 *)(param_2 + 1);
      uVar7 = *(undefined4 *)((int)param_2 + 0xc);
      param_2 = param_2 + 2;
      *(undefined4 *)param_1 = uVar4;
      *(undefined4 *)((int)param_1 + 4) = uVar5;
      *(undefined4 *)(param_1 + 1) = uVar6;
      *(undefined4 *)((int)param_1 + 0xc) = uVar7;
      param_1 = param_1 + 2;
      param_3 = param_3 - 0x10;
    }
  }
  while (-1 < (int)(param_3 - 0x20)) {
    uVar4 = *(undefined4 *)((int)param_2 + 4);
    uVar5 = *(undefined4 *)(param_2 + 1);
    uVar6 = *(undefined4 *)((int)param_2 + 0xc);
    uVar7 = *(undefined4 *)(param_2 + 2);
    uVar8 = *(undefined4 *)((int)param_2 + 0x14);
    uVar9 = *(undefined4 *)(param_2 + 3);
    uVar10 = *(undefined4 *)((int)param_2 + 0x1c);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined4 *)((int)param_1 + 4) = uVar4;
    *(undefined4 *)(param_1 + 1) = uVar5;
    *(undefined4 *)((int)param_1 + 0xc) = uVar6;
    *(undefined4 *)(param_1 + 2) = uVar7;
    *(undefined4 *)((int)param_1 + 0x14) = uVar8;
    *(undefined4 *)(param_1 + 3) = uVar9;
    *(undefined4 *)((int)param_1 + 0x1c) = uVar10;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    param_3 = param_3 - 0x20;
  }
  while (-1 < (int)(param_3 - 8)) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    param_3 = param_3 - 8;
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (3 < param_3) {
    uVar4 = *(undefined4 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 4);
    *(undefined4 *)param_1 = uVar4;
    param_1 = (undefined8 *)((int)param_1 + 4);
    param_3 = param_3 - 4;
  }
  if (1 < param_3) {
    uVar3 = *(undefined2 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 2);
    *(undefined2 *)param_1 = uVar3;
    param_1 = (undefined8 *)((int)param_1 + 2);
    param_3 = param_3 - 2;
  }
  if (param_3 != 0) {
    uVar2 = *(undefined1 *)param_2;
    param_2 = (undefined8 *)((int)param_2 + 1);
    *(undefined1 *)param_1 = uVar2;
    param_1 = (undefined8 *)((int)param_1 + 1);
  }
  return CONCAT44(param_2,param_1);
}
