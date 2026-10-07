/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 1eefad7315ab3fc6546bfc8625dd9c9492764867898b73f6c6346c5f11d684a3 */

/* VA 60001000 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60001000(void)

{
  DAT_6001d8e8 = (HMODULE)FUN_60010398();
  if (DAT_6001d8e8 != (HMODULE)0x0) {
    DAT_6001f140 = GetProcAddress(DAT_6001d8e8,"_grGlideInit@0");
    DAT_6001f144 = GetProcAddress(DAT_6001d8e8,"_grGlideShutdown@0");
    DAT_6001f148 = GetProcAddress(DAT_6001d8e8,"_grSstSelect@4");
    DAT_6001f14c = GetProcAddress(DAT_6001d8e8,"_grSstWinOpen@28");
    DAT_6001f150 = GetProcAddress(DAT_6001d8e8,"_grSstWinClose@4");
    DAT_6001f154 = GetProcAddress(DAT_6001d8e8,"_grAlphaTestReferenceValue@4");
    DAT_6001f158 = GetProcAddress(DAT_6001d8e8,"_grTexDownloadTable@8");
    DAT_6001f15c = GetProcAddress(DAT_6001d8e8,"_grRenderBuffer@4");
    DAT_6001f160 = GetProcAddress(DAT_6001d8e8,"_grBufferClear@12");
    DAT_6001f164 = GetProcAddress(DAT_6001d8e8,"_grBufferSwap@4");
    DAT_6001f168 = GetProcAddress(DAT_6001d8e8,"_grFinish@0");
    DAT_6001f16c = GetProcAddress(DAT_6001d8e8,"_grClipWindow@16");
    DAT_6001f170 = GetProcAddress(DAT_6001d8e8,"_grColorCombine@20");
    DAT_6001f174 = GetProcAddress(DAT_6001d8e8,"_grAlphaCombine@20");
    DAT_6001f178 = GetProcAddress(DAT_6001d8e8,"_grAlphaBlendFunction@16");
    DAT_6001f17c = GetProcAddress(DAT_6001d8e8,"_grCullMode@4");
    DAT_6001f180 = GetProcAddress(DAT_6001d8e8,"_grTexFilterMode@12");
    DAT_6001f184 = GetProcAddress(DAT_6001d8e8,"_grDitherMode@4");
    DAT_6001f188 = GetProcAddress(DAT_6001d8e8,"_grChromakeyMode@4");
    DAT_6001f18c = GetProcAddress(DAT_6001d8e8,"_grAlphaTestFunction@4");
    DAT_6001f190 = GetProcAddress(DAT_6001d8e8,"_grDepthBufferMode@4");
    DAT_6001f194 = GetProcAddress(DAT_6001d8e8,"_grDepthBufferFunction@4");
    DAT_6001f198 = GetProcAddress(DAT_6001d8e8,"_grDepthMask@4");
    DAT_6001f19c = GetProcAddress(DAT_6001d8e8,"_grFogColorValue@4");
    DAT_6001f1a0 = GetProcAddress(DAT_6001d8e8,"_grFogMode@4");
    DAT_6001f1a4 = GetProcAddress(DAT_6001d8e8,"_grFogTable@4");
    DAT_6001f1a8 = GetProcAddress(DAT_6001d8e8,"_grLfbLock@24");
    DAT_6001f1ac = GetProcAddress(DAT_6001d8e8,"_grLfbUnlock@8");
    DAT_6001f1b0 = GetProcAddress(DAT_6001d8e8,"_grLfbWriteRegion@36");
    DAT_6001f1b4 = GetProcAddress(DAT_6001d8e8,"_grLfbReadRegion@28");
    DAT_6001f1b8 = GetProcAddress(DAT_6001d8e8,"_grDrawTriangle@12");
    DAT_6001f1bc = GetProcAddress(DAT_6001d8e8,"_grDrawLine@8");
    DAT_6001f1c0 = GetProcAddress(DAT_6001d8e8,"_grDrawPoint@4");
    DAT_6001f1c4 = GetProcAddress(DAT_6001d8e8,"_guGammaCorrectionRGB@12");
    DAT_6001f1c8 = GetProcAddress(DAT_6001d8e8,"_grDepthBiasLevel@4");
    DAT_6001f1cc = GetProcAddress(DAT_6001d8e8,"_grTexMipMapMode@12");
    DAT_6001f1d0 = GetProcAddress(DAT_6001d8e8,"_grTexCombine@28");
    DAT_6001f1d4 = GetProcAddress(DAT_6001d8e8,"_grTexCalcMemRequired@16");
    DAT_6001f1d8 = GetProcAddress(DAT_6001d8e8,"_grTexDownloadMipMap@16");
    DAT_6001f1dc = GetProcAddress(DAT_6001d8e8,"_grTexMinAddress@4");
    DAT_6001f1e0 = GetProcAddress(DAT_6001d8e8,"_grTexMaxAddress@4");
    DAT_6001f1e4 = GetProcAddress(DAT_6001d8e8,"_grTexSource@16");
    DAT_6001f1e8 = GetProcAddress(DAT_6001d8e8,"_grTexClampMode@12");
    DAT_6001f1ec = GetProcAddress(DAT_6001d8e8,"_grTexLodBiasValue@8");
    DAT_6001f1f0 = GetProcAddress(DAT_6001d8e8,"_grGet@12");
    DAT_6001f1f4 = GetProcAddress(DAT_6001d8e8,"_grGetString@4");
    DAT_6001f1f8 = GetProcAddress(DAT_6001d8e8,"_grAADrawTriangle@24");
    DAT_6001f1fc = GetProcAddress(DAT_6001d8e8,"_grChromakeyValue@4");
    DAT_6001f200 = GetProcAddress(DAT_6001d8e8,"_grEnable@4");
    DAT_6001f204 = GetProcAddress(DAT_6001d8e8,"_grDisable@4");
    DAT_6001f208 = GetProcAddress(DAT_6001d8e8,"_grErrorSetCallback@4");
    _DAT_6001f20c = GetProcAddress(DAT_6001d8e8,"_grTexDownloadMipMapLevelPartial@40");
    DAT_6001f210 = GetProcAddress(DAT_6001d8e8,"_grQueryResolutions@8");
    DAT_6001f214 = GetProcAddress(DAT_6001d8e8,"_grCoordinateSpace@4");
    DAT_6001f218 = GetProcAddress(DAT_6001d8e8,"_grVertexLayout@12");
    DAT_6001f21c = GetProcAddress(DAT_6001d8e8,"_grColorMask@8");
    DAT_6001ed2c = DAT_6001f1b8;
    DAT_6001ed24 = DAT_6001f1b8;
    DAT_6001ed30 = &LAB_60003e10;
    return 1;
  }
  return 0;
}



/* VA 60001460 */

void FUN_60001460(void)

{
  if (DAT_6001d8e8 != (HMODULE)0x0) {
    FreeLibrary(DAT_6001d8e8);
  }
  DAT_6001d8e8 = (HMODULE)0x0;
  return;
}



/* VA 60001480 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60001480(int param_1,float param_2,float param_3)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;

  iVar1 = param_1;
  uVar2 = 0;
  do {
    fVar3 = FUN_60001510(uVar2);
    if ((float10)_DAT_600125a4 < fVar3) {
      fVar3 = (float10)_DAT_600125a4;
    }
    fVar3 = (fVar3 - (float10)param_2) / (float10)(param_3 - param_2);
    if (fVar3 <= (float10)_DAT_600125a0) {
      if (fVar3 < (float10)_DAT_6001259c) {
        fVar3 = (float10)_DAT_6001259c;
      }
    }
    else {
      fVar3 = (float10)_DAT_600125a0;
    }
    param_1._0_1_ = (undefined1)(int)ROUND((float)(fVar3 * (float10)_DAT_60012598));
    *(undefined1 *)(uVar2 + iVar1) = (undefined1)param_1;
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x40);
  return;
}



/* VA 60001510 */

float10 __cdecl FUN_60001510(uint param_1)

{
  float10 fVar1;

  fVar1 = (float10)FUN_60006d40();
  return fVar1 / (float10)(int)(8 - (param_1 & 3));
}



/* VA 60001570 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall _THRASH_about_0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_4;

                    /* 0x1570  1  _THRASH_about@0 */
  local_4 = param_1;
  if (DAT_6001d8f0 == 0) {
    puVar2 = &DAT_6001d8f0;
    for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    _DAT_6001d8f8 = DAT_60014510;
    _DAT_6001d904 = 0x100;
    _DAT_6001d910 = 0x100;
    _DAT_6001d900 = 1;
    DAT_6001d8fc = (uint)(DAT_60014044 < 2) << 7 | DAT_6001d8fc & 0xffffff4f | 0x4f;
    _DAT_6001d968 = PTR_s_AUTHOR__Daniel_Kennett__Wednesda_6001450c;
    _DAT_6001d908 = 1;
    _DAT_6001d90c = 1;
    _DAT_6001d914 = 1;
    _DAT_6001d918 = 1;
    DAT_6001d944 = s_3Dfx_Voodoo_2_600125c0[8];
    DAT_6001d944_1._0_1_ = s_3Dfx_Voodoo_2_600125c0[9];
    DAT_6001d944_1._1_1_ = s_3Dfx_Voodoo_2_600125c0[10];
    DAT_6001d944_1._2_1_ = s_3Dfx_Voodoo_2_600125c0[0xb];
    DAT_6001d93c = s_3Dfx_Voodoo_2_600125c0[0];
    DAT_6001d93c_1._0_1_ = s_3Dfx_Voodoo_2_600125c0[1];
    DAT_6001d93c_1._1_1_ = s_3Dfx_Voodoo_2_600125c0[2];
    DAT_6001d93c_1._2_1_ = s_3Dfx_Voodoo_2_600125c0[3];
    DAT_6001d8f0 = 0x33444632;
    DAT_6001d8f4 = 0xd0;
    _DAT_6001d96c = 5;
    _DAT_6001d91c = 0xb;
    _DAT_6001d920 = &DAT_6001407c;
    _DAT_6001d924 = 4;
    _DAT_6001d928 = &DAT_600140b0;
    _DAT_6001d92c = 0x13;
    _DAT_6001d930 = &DAT_600140c8;
    DAT_6001d940 = s_3Dfx_Voodoo_2_600125c0[4];
    DAT_6001d940_1._0_1_ = s_3Dfx_Voodoo_2_600125c0[5];
    DAT_6001d940_1._1_1_ = s_3Dfx_Voodoo_2_600125c0[6];
    DAT_6001d940_1._2_1_ = s_3Dfx_Voodoo_2_600125c0[7];
    DAT_6001d948 = s_3Dfx_Voodoo_2_600125c0[0xc];
    DAT_6001d948_1 = s_3Dfx_Voodoo_2_600125c0[0xd];
    DAT_6001d95c = 0;
    if (DAT_6001d84c == 0) {
      iVar1 = FUN_60001000();
      if (iVar1 != 0) {
        if (((DAT_6001f140 != (code *)0x0) && (DAT_6001f1f0 != (code *)0x0)) && (DAT_6001f1f4 != 0))
        {
          local_4 = 0;
          iVar1 = (*DAT_6001f1f0)(0xf,4,&local_4);
          if ((iVar1 != 0) && (0 < local_4)) {
            (*DAT_6001f140)();
            (*DAT_6001f208)(&LAB_60001550);
            (*DAT_6001f204)(4);
            FUN_60001740();
            (*DAT_6001f144)();
          }
        }
        FUN_60001460();
      }
    }
    else {
      FUN_60001740();
    }
  }
  FUN_60005ea0(&DAT_6001d8f0);
  return &DAT_6001d8f0;
}



/* VA 60001740 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60001740(void)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  void *this;
  char *pcVar13;
  byte *pbVar14;
  int *piVar15;
  bool bVar16;
  int unaff_retaddr;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puVar17;

  pbVar3 = (byte *)(*DAT_6001f1f4)();
  pcVar13 = "Voodoo Graphics";
  pbVar9 = pbVar3;
  do {
    bVar1 = *pbVar9;
    bVar16 = bVar1 < (byte)*pcVar13;
    if (bVar1 != *pcVar13) {
LAB_6000178d:
      iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
      goto LAB_60001792;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar9[1];
    bVar16 = bVar1 < (byte)pcVar13[1];
    if (bVar1 != pcVar13[1]) goto LAB_6000178d;
    pbVar9 = pbVar9 + 2;
    pcVar13 = pcVar13 + 2;
  } while (bVar1 != 0);
  iVar10 = 0;
LAB_60001792:
  if (iVar10 == 0) {
    DAT_60014030 = 0;
    *(undefined4 *)(unaff_retaddr + 0x6c) = 0;
  }
  else {
    pcVar13 = "Voodoo Rush";
    pbVar9 = pbVar3;
    do {
      bVar1 = *pbVar9;
      bVar16 = bVar1 < (byte)*pcVar13;
      if (bVar1 != *pcVar13) {
LAB_600017d3:
        iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
        goto LAB_600017d8;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar9[1];
      bVar16 = bVar1 < (byte)pcVar13[1];
      if (bVar1 != pcVar13[1]) goto LAB_600017d3;
      pbVar9 = pbVar9 + 2;
      pcVar13 = pcVar13 + 2;
    } while (bVar1 != 0);
    iVar10 = 0;
LAB_600017d8:
    if (iVar10 == 0) {
      *(undefined4 *)(unaff_retaddr + 0x6c) = 1;
    }
    else {
      pbVar14 = &DAT_60012620;
      pbVar9 = pbVar3;
      do {
        bVar1 = *pbVar9;
        bVar16 = bVar1 < *pbVar14;
        if (bVar1 != *pbVar14) {
LAB_6000181b:
          iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
          goto LAB_60001820;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar9[1];
        bVar16 = bVar1 < pbVar14[1];
        if (bVar1 != pbVar14[1]) goto LAB_6000181b;
        pbVar9 = pbVar9 + 2;
        pbVar14 = pbVar14 + 2;
      } while (bVar1 != 0);
      iVar10 = 0;
LAB_60001820:
      if (iVar10 == 0) {
        DAT_60014030 = 0;
        *(undefined4 *)(unaff_retaddr + 0x6c) = 2;
        goto LAB_600018c8;
      }
      pcVar13 = "Voodoo Banshee";
      pbVar9 = pbVar3;
      do {
        bVar1 = *pbVar9;
        bVar16 = bVar1 < (byte)*pcVar13;
        if (bVar1 != *pcVar13) {
LAB_60001865:
          iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
          goto LAB_6000186a;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar9[1];
        bVar16 = bVar1 < (byte)pcVar13[1];
        if (bVar1 != pcVar13[1]) goto LAB_60001865;
        pbVar9 = pbVar9 + 2;
        pcVar13 = pcVar13 + 2;
      } while (bVar1 != 0);
      iVar10 = 0;
LAB_6000186a:
      if (iVar10 == 0) {
        *(undefined4 *)(unaff_retaddr + 0x6c) = 3;
      }
      else {
        pbVar14 = &DAT_60012600;
        pbVar9 = pbVar3;
        do {
          bVar1 = *pbVar9;
          bVar16 = bVar1 < *pbVar14;
          if (bVar1 != *pbVar14) {
LAB_600018aa:
            iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
            goto LAB_600018af;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar9[1];
          bVar16 = bVar1 < pbVar14[1];
          if (bVar1 != pbVar14[1]) goto LAB_600018aa;
          pbVar9 = pbVar9 + 2;
          pbVar14 = pbVar14 + 2;
        } while (bVar1 != 0);
        iVar10 = 0;
LAB_600018af:
        if (iVar10 == 0) {
          *(undefined4 *)(unaff_retaddr + 0x6c) = 4;
        }
        else {
          *(undefined4 *)(unaff_retaddr + 0x6c) = 0;
        }
      }
    }
    DAT_60014030 = 1;
  }
LAB_600018c8:
  DAT_6001d850 = (uint)(DAT_60014030 == 0);
  if (0x69 < DAT_60014510) {
    uVar11 = 0xffffffff;
    do {
      pbVar9 = pbVar3;
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      pbVar9 = pbVar3 + 1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar9;
    } while (bVar1 != 0);
    uVar11 = ~uVar11;
    pbVar9 = pbVar9 + -uVar11;
    pbVar3 = (byte *)(unaff_retaddr + 0x80);
    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pbVar3 = *(undefined4 *)pbVar9;
      pbVar9 = pbVar9 + 4;
      pbVar3 = pbVar3 + 4;
    }
    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *pbVar3 = *pbVar9;
      pbVar9 = pbVar9 + 1;
      pbVar3 = pbVar3 + 1;
    }
  }
  pcVar13 = (char *)(*DAT_6001f1f4)();
  iVar10 = 0;
  cVar2 = *pcVar13;
  while (cVar2 != '\0') {
    if (DAT_6001c7dc < 2) {
      uVar11 = (byte)PTR_DAT_6001c5d0[(uint)(byte)pcVar13[iVar10] * 2] & 4;
    }
    else {
      uStack_2c = 0x60001936;
      uVar11 = FUN_60007114((void *)(uint)(byte)pcVar13[iVar10],(int)(uint)(byte)pcVar13[iVar10],4);
    }
    if (uVar11 != 0) {
      pbVar3 = &DAT_600125f8;
      pbVar9 = (byte *)(pcVar13 + iVar10);
      goto LAB_60001962;
    }
    iVar4 = iVar10 + 1;
    iVar10 = iVar10 + 1;
    cVar2 = pcVar13[iVar4];
  }
LAB_6000199a:
  puVar17 = &stack0xfffffff0;
  uStack_2c = 0x11;
  puStack_30 = (undefined1 *)0x600019a9;
  iVar10 = (*DAT_6001f1f0)();
  puStack_30 = &stack0xffffffe8;
  uStack_34 = 4;
  iVar4 = (*DAT_6001f1f0)(0xe);
  if ((iVar4 == 0) || (DAT_60014030 == 0)) {
    iVar4 = (*DAT_6001f1f0)(0xc,4,&stack0xffffffdc);
    if ((iVar4 != 0) && (iVar10 != 0)) {
      puVar17 = (undefined1 *)((int)puVar17 * 2);
    }
    *(undefined4 *)(unaff_retaddr + 0x74) = 1;
  }
  else {
    *(undefined4 *)(unaff_retaddr + 0x74) = 3;
  }
  piVar15 = &DAT_60014104;
  iVar10 = 1;
  do {
    *piVar15 = (int)puVar17 / ((piVar15[-3] >> 3) * piVar15[-5] * piVar15[-4]);
    if (piVar15[-1] == 0) {
      piVar15[1] = 0;
      *piVar15 = 0;
    }
    else {
      iVar4 = FUN_60001b90(iVar10,0);
      *piVar15 = iVar4;
      iVar4 = FUN_60001b90(iVar10,1);
      piVar15[1] = iVar4;
    }
    iVar4 = *piVar15;
    if (3 < iVar4) {
      iVar4 = 3;
    }
    *piVar15 = iVar4;
    iVar4 = piVar15[1];
    if (3 < iVar4) {
      iVar4 = 3;
    }
    piVar15[1] = iVar4;
    iVar10 = iVar10 + 1;
    piVar15 = piVar15 + 10;
  } while (iVar10 < 0x14);
  iVar4 = (*DAT_6001f1dc)(0);
  iVar10 = 0;
  iVar5 = (*DAT_6001f1e0)();
  iVar6 = (*DAT_6001f1dc)(0);
  iVar6 = (iVar5 - iVar4) - iVar6;
  *(int *)(unaff_retaddr + 0x70) = iVar6;
  if (0 < iVar6) {
    *(uint *)(unaff_retaddr + 0x70) = iVar6 + 0xfU & 0xfffffff0;
  }
  DAT_60014044 = 1;
  iVar4 = (*DAT_6001f1f0)(0x13,4,&uStack_34);
  DAT_60014044 = iVar10;
  if (((iVar4 == 0) || (DAT_60014044 < 1)) || (0x10 < DAT_60014044)) {
    DAT_60014044 = 1;
    *(undefined4 *)(unaff_retaddr + 0x44) = 0;
  }
  else {
    *(int *)(unaff_retaddr + 0x44) = DAT_60014044;
  }
  pbVar9 = (byte *)FUN_60007076((uchar *)"VOODOO2_NUMTMU");
  if (pbVar9 != (byte *)0x0) {
    DAT_60014044 = FUN_6000706b(this,pbVar9);
  }
  puVar7 = (uint *)(*DAT_6001f1f4)(0xa0);
  DAT_60014058 = 2;
  _DAT_600140c0 = 5;
  DAT_6001d89c = 0;
  if (puVar7 != (uint *)0x0) {
    puVar8 = FUN_60006f60(puVar7,"PALETTE6666");
    if (puVar8 != (uint *)0x0) {
      DAT_60014058 = 3;
      _DAT_600140c0 = 1;
    }
    puVar7 = FUN_60006f60(puVar7,"TEXMIRROR");
    if (puVar7 != (uint *)0x0) {
      DAT_6001d89c = 1;
    }
  }
  return;
  while( true ) {
    bVar1 = pbVar9[1];
    bVar16 = bVar1 < pbVar3[1];
    if (bVar1 != pbVar3[1]) goto LAB_60001987;
    pbVar9 = pbVar9 + 2;
    pbVar3 = pbVar3 + 2;
    if (bVar1 == 0) break;
LAB_60001962:
    bVar1 = *pbVar9;
    bVar16 = bVar1 < *pbVar3;
    if (bVar1 != *pbVar3) {
LAB_60001987:
      iVar10 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
      goto LAB_6000198c;
    }
    if (bVar1 == 0) break;
  }
  iVar10 = 0;
LAB_6000198c:
  if (iVar10 < 0) {
    DAT_6001d8a8 = 1;
  }
  goto LAB_6000199a;
}



/* VA 60001b90 */

int __cdecl FUN_60001b90(int param_1,undefined4 param_2)

{
  size_t sVar1;
  LPVOID pvVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;

  local_10 = *(undefined4 *)(&DAT_60014410 + param_1 * 4);
  iVar4 = 0;
  local_c = 0xffffffff;
  local_8 = 0xffffffff;
  local_4 = param_2;
  sVar1 = (*DAT_6001f210)(&local_10,0);
  if (sVar1 != 0) {
    pvVar2 = (LPVOID)FUN_600060d0(sVar1);
    if (pvVar2 != (LPVOID)0x0) {
      (*DAT_6001f210)(&stack0xffffffe8,pvVar2);
      if (0 < (int)sVar1) {
        piVar3 = (int *)((int)pvVar2 + 8);
        do {
          if (iVar4 < *piVar3) {
            iVar4 = *piVar3;
          }
          piVar3 = piVar3 + 4;
        } while ((-8 - (int)pvVar2) + (int)piVar3 < (int)sVar1);
      }
      FUN_60006100(pvVar2);
    }
  }
  return iVar4;
}



/* VA 60001c20 */

int _THRASH_is_0(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  void *this;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this_00;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  int iStack_4;

                    /* 0x1c20  25  _THRASH_is@0 */
  pbVar2 = (byte *)FUN_60007076((uchar *)"VOODOO2_IS");
  if (pbVar2 != (byte *)0x0) {
    iVar3 = FUN_6000706b(this,pbVar2);
    return iVar3;
  }
  FUN_600066d0();
  iVar3 = FUN_60001000();
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = 0;
  if (((DAT_6001f1f0 != (code *)0x0) && (DAT_6001f140 != 0)) && (DAT_6001f1f4 != (code *)0x0)) {
    pcVar4 = (char *)(*DAT_6001f1f4)(0xa4);
    iVar6 = 0;
    this_00 = extraout_ECX;
    if (*pcVar4 != '\0') {
      while( true ) {
        if (DAT_6001c7dc < 2) {
          this_00 = (void *)(uint)(byte)pcVar4[iVar6];
          uVar5 = (byte)PTR_DAT_6001c5d0[(int)this_00 * 2] & 4;
        }
        else {
          uVar5 = FUN_60007114(this_00,(uint)(byte)pcVar4[iVar6],4);
          this_00 = extraout_ECX_00;
        }
        if (uVar5 != 0) break;
        iVar3 = iVar6 + 1;
        iVar6 = iVar6 + 1;
        if (pcVar4[iVar3] == '\0') {
          FUN_60001460();
          return 0;
        }
      }
      pbVar8 = (byte *)(pcVar4 + iVar6);
      pbVar7 = &DAT_6001264c;
      pbVar2 = pbVar8;
      do {
        bVar1 = *pbVar2;
        bVar9 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_60001d08:
          iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_60001d0d;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar9 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_60001d08;
        pbVar2 = pbVar2 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_60001d0d:
      if (-1 < iVar3) {
        pbVar2 = &DAT_60012644;
        do {
          bVar1 = *pbVar8;
          bVar9 = bVar1 < *pbVar2;
          if (bVar1 != *pbVar2) {
LAB_60001d40:
            iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_60001d45;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar8[1];
          bVar9 = bVar1 < pbVar2[1];
          if (bVar1 != pbVar2[1]) goto LAB_60001d40;
          pbVar8 = pbVar8 + 2;
          pbVar2 = pbVar2 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_60001d45:
        iStack_4 = 0;
        iVar3 = ((iVar3 < 1) - 1 & 0xfffffffb) + 100;
        iVar6 = (*DAT_6001f1f0)(0xf,4,&iStack_4);
        if ((iVar6 != 0) && (iStack_4 != 0)) goto LAB_60001d78;
      }
      iVar3 = 0;
    }
  }
LAB_60001d78:
  FUN_60001460();
  return iVar3;
}



/* VA 60001d90 */

undefined4 _THRASH_selectdisplay_4(int param_1)

{
                    /* 0x1d90  30  _THRASH_selectdisplay@4 */
  if (param_1 != DAT_6001d854) {
    (*DAT_6001f148)(param_1);
    DAT_6001d854 = param_1;
  }
  return 1;
}



/* VA 60001dc0 */

undefined4 _THRASH_init_0(void)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  byte *pbVar5;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  int iVar6;
  int local_4;

                    /* 0x1dc0  24  _THRASH_init@0 */
  iVar6 = 0;
  if (DAT_6001d84c != 0) {
    return DAT_6001d9c0;
  }
  local_4 = 0;
  pfVar2 = (float *)&DAT_6001ed40;
  do {
    fVar1 = (float)local_4;
    pfVar3 = pfVar2 + 1;
    local_4 = local_4 + 1;
    *pfVar2 = fVar1;
    pfVar2 = pfVar3;
  } while ((int)pfVar3 < 0x6001f140);
  if (DAT_6001d8cc == (HANDLE)0x0) {
    DAT_6001d8cc = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  }
  iVar4 = FUN_60001000();
  if (iVar4 != 0) {
    (*DAT_6001f140)();
    (*DAT_6001f208)(&LAB_60001550);
    iVar4 = (*DAT_6001f1f0)(0xf,4,&DAT_6001d9c0);
    if (iVar4 == 0) {
      DAT_6001d9c0 = 0;
    }
    pbVar5 = (byte *)FUN_60007076((uchar *)"VOODOO2_DISPLAY");
    this = extraout_ECX;
    if ((pbVar5 != (byte *)0x0) ||
       (pbVar5 = (byte *)FUN_60007076((uchar *)"THRASH_DISPLAY"), this = extraout_ECX_00,
       pbVar5 != (byte *)0x0)) {
      iVar6 = FUN_6000706b(this,pbVar5);
    }
    iVar6 = _THRASH_selectdisplay_4(iVar6);
    if (iVar6 != 0) {
      FUN_60001740();
      FUN_60007207(0x60001ed0);
    }
    _THRASH_setstate_8(0x2e,(undefined4 *)0x3f800000);
    FUN_60005dd0();
    DAT_6001d84c = 1;
    return DAT_6001d9c0;
  }
  return DAT_6001d9c0;
}



/* VA 60001ee0 */

undefined4 _THRASH_restore_0(void)

{
  int *piVar1;
  int iVar2;

                    /* 0x1ee0  29  _THRASH_restore@0 */
  iVar2 = 0;
  piVar1 = &DAT_6001d858;
  do {
    if (*piVar1 != 0) {
      _THRASH_selectdisplay_4(iVar2);
      _THRASH_setvideomode_12(0,0,0);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x6001d898);
  FUN_60001f60();
  if (DAT_6001da0c != 0) {
    DAT_6001da0c = 0;
  }
  if (DAT_6001d8cc != (HANDLE)0x0) {
    CloseHandle(DAT_6001d8cc);
    DAT_6001d8cc = (HANDLE)0x0;
  }
  if (DAT_6001d84c != 0) {
    (*DAT_6001f144)();
  }
  FUN_60001460();
  PTR_FUN_60014508 = (undefined *)0x0;
  DAT_6001d84c = 0;
  return 1;
}



/* VA 60001f60 */

undefined4 FUN_60001f60(void)

{
  if (DAT_6001d8d0 != (int *)0x0) {
    (**(code **)(*DAT_6001d8d0 + 8))(DAT_6001d8d0);
    DAT_6001d8d0 = (int *)0x0;
  }
  return 1;
}



/* VA 60001f80 */

undefined4 FUN_60001f80(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  uint uStack_24;

  uStack_24 = 0x60001f8e;
  FUN_60002230();
  if (param_2 != 0) {
    if (DAT_6001d84c == 0) {
      uStack_24 = 0x60001fa9;
      (*DAT_6001f140)();
      DAT_6001d84c = 2;
    }
    if ((param_3 != 0) && (*(int *)(&DAT_600140e0 + param_1 * 0x28) < param_2)) {
      param_3 = 0;
    }
    uStack_24 = (uint)(param_3 != 0);
    iStack_28 = param_2;
    uStack_2c = 0;
    uStack_30 = 0;
    iVar1 = (*DAT_6001f14c)(DAT_6001d9f4,*(undefined4 *)(&DAT_60014410 + param_1 * 4));
    (&DAT_6001d858)[DAT_6001d854] = iVar1;
    if (iVar1 != 0) {
      (*DAT_6001f208)(&LAB_60001550);
      _THRASH_setstate_8(0x2e,(undefined4 *)0x3f800000);
      FUN_600021c0();
      iVar1 = (*DAT_6001f1f0)(0x26,0x10,&uStack_30);
      if (iVar1 == 0) {
        DAT_60014050 = *(undefined4 *)(&DAT_600140c8 + param_1 * 0x28);
        DAT_60014054 = *(undefined4 *)(&DAT_600140cc + param_1 * 0x28);
      }
      else {
        DAT_60014050 = 0;
        DAT_60014054 = uStack_30;
      }
      FUN_60001740();
      _THRASH_treset_0();
      (*DAT_6001f1d0)(0,1,0,1,0,0,0);
      if (1 < DAT_60014044) {
        (*DAT_6001f1d0)(1,1,0,1,0,0,0);
      }
      (*DAT_6001f200)(2);
      (*DAT_6001f214)(0);
      (*DAT_6001f218)(3,0,0);
      (*DAT_6001f218)(5,0,0);
      (*DAT_6001f218)(0x10,0,0);
      (*DAT_6001f218)(0x20,0,0);
      (*DAT_6001f218)(0x41,0,0);
      (*DAT_6001f218)(0x42,0,0);
      (*DAT_6001f218)(0x50,0,0);
      (*DAT_6001f218)(0x51,0,0);
      (*DAT_6001f218)(0x52,0,0);
      (*DAT_6001f218)(1,0,1);
      (*DAT_6001f218)(2,8,1);
      (*DAT_6001f218)(4,0xc,1);
      (*DAT_6001f218)(0x30,0x10,1);
      (*DAT_6001f218)(0x40,0x18,1);
      (*DAT_6001f17c)(0);
      (*DAT_6001f1f0)(4,4,&DAT_6001d8c8);
      FUN_60006330(param_1,param_2,param_3);
      DAT_6001d8c4 = 0;
      return 1;
    }
  }
  return 0;
}



/* VA 600021c0 */

undefined4 FUN_600021c0(void)

{
  int iVar1;

  if ((DAT_6001d8d0 == (int *)0x0) && (DAT_6001d850 != 0)) {
    iVar1 = DirectDrawCreate(0,&DAT_6001d8d0,0);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*DAT_6001d8d0 + 0x50))
                        (DAT_6001d8d0,DAT_6001d9f4,(-(uint)(DAT_6001da10 != 0) & 0xfffffff7) + 0x411
                        );
      if (iVar1 == 0) {
        return 1;
      }
      (**(code **)(*DAT_6001d8d0 + 8))(DAT_6001d8d0);
      DAT_6001d8d0 = (int *)0x0;
    }
  }
  return 0;
}



/* VA 60002230 */

void FUN_60002230(void)

{
  if (DAT_6001d84c != 0) {
    if ((&DAT_6001d858)[DAT_6001d854] != 0) {
      (*DAT_6001f150)((&DAT_6001d858)[DAT_6001d854]);
      if (DAT_6001d8a8 != 0) {
        (*DAT_6001f144)();
        DAT_6001d84c = 0;
      }
    }
    (&DAT_6001d858)[DAT_6001d854] = 0;
  }
  return;
}



/* VA 60002280 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _THRASH_setvideomode_12(WPARAM param_1,int param_2,int param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  uint uVar3;
  int *piVar4;

                    /* 0x2280  33  _THRASH_setvideomode@12 */
  if (DAT_6001d84c == 1) {
    (*DAT_6001f144)();
    DAT_6001d84c = 0;
  }
  if (DAT_6001da04 != (code *)0x0) {
    DAT_6001d9f4 = (HWND)(*DAT_6001da04)();
  }
  if (DAT_6001d9f4 == (HWND)0x0) {
LAB_600022db:
    if (((DAT_6001da0c != (code *)0x0) && (DAT_6001d9f4 != (HWND)0x0)) &&
       (DAT_6001d8cc != (HANDLE)0x0)) {
      (*DAT_6001da0c)(0x465,&LAB_60002420);
      DAT_6001d9c4 = 1;
      PostMessageA(DAT_6001d9f4,0x465,param_1,param_3 * 0x100 + param_2);
      DVar1 = WaitForSingleObject(DAT_6001d8cc,30000);
      DAT_6001d9c4 = 0;
      uVar3 = ~-(uint)(DVar1 != 0) & DAT_6001d8b4;
      goto LAB_60002367;
    }
  }
  else {
    SetForegroundWindow(DAT_6001d9f4);
    DVar1 = GetWindowThreadProcessId(DAT_6001d9f4,(LPDWORD)0x0);
    DVar2 = GetCurrentThreadId();
    if (DVar2 != DVar1) goto LAB_600022db;
  }
  uVar3 = FUN_60001f80(param_1,param_2,param_3);
LAB_60002367:
  FUN_60006130(0x3e,(undefined *)(DAT_6001d9fc + 1));
  if (param_1 == 0) {
    _DAT_6001d83c = 0;
    _DAT_6001d840 = 0;
    _DAT_6001d844 = 0;
    _DAT_6001d848 = 0;
  }
  else {
    _DAT_6001d838 = 0;
    _DAT_6001d83c = 0;
    _DAT_6001d840 = 0;
    _DAT_6001d844 = 0;
    _DAT_6001d848 = 0;
    _THRASH_window_4(1);
    piVar4 = _THRASH_lockwindow_0();
    _THRASH_unlockwindow_4(piVar4);
    _THRASH_window_4(0);
    _DAT_6001d83c = piVar4[1];
    _DAT_6001d840 = piVar4[2];
    _DAT_6001d844 = piVar4[3];
    _DAT_6001d848 = piVar4[4];
  }
  _DAT_6001d838 = 0;
  FUN_60005d20(0x1d,&DAT_6001d838);
  return uVar3;
}



/* VA 60002470 */

int _THRASH_talloc_20(int param_1,int param_2,uint param_3,undefined4 param_4,uint param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  uint uVar5;
  uint uVar6;
  int unaff_EDI;
  uint uVar7;

                    /* 0x2470  35  _THRASH_talloc@20 */
  iVar2 = ((int)(float)param_1 >> 0x17) + -0x7f;
  iVar4 = ((int)(float)param_2 >> 0x17) + -0x7f;
  iVar3 = iVar2;
  if (iVar2 <= iVar4) {
    iVar3 = iVar4;
  }
  uVar5 = iVar3 - (param_5 & 0xffff);
  cVar1 = (&DAT_60014460)[((int)uVar5 < 0) - 1 & uVar5];
  iVar3 = (*DAT_6001f1d4)((int)cVar1,(int)(char)(&DAT_60014460)[iVar3],
                          (int)(char)(&DAT_6001446f)[iVar2 - iVar4],(&DAT_60014474)[param_3]);
  uVar5 = param_5 & 0xffff0000;
  if (uVar5 == 0) {
    iVar2 = (*DAT_6001f1dc)(0);
    uVar7 = DAT_6001ed34 - iVar2;
    iVar2 = (*DAT_6001f1dc)(0);
    uVar6 = ((DAT_6001ed34 + iVar3) - iVar2) - 1U & 0xffe00000;
    if (uVar6 != (uVar7 & 0xffe00000)) {
      iVar2 = (*DAT_6001f1dc)(0);
      DAT_6001ed34 = iVar2 + uVar6;
    }
    iVar2 = (*DAT_6001f1e0)(0);
    param_3 = 0;
    unaff_EDI = (iVar2 + 0xfU & 0xfffffff0) - DAT_6001ed34;
  }
  else if (uVar5 == 0x10000) {
    iVar2 = (*DAT_6001f1dc)(1);
    uVar7 = DAT_6001ed38 - iVar2;
    iVar2 = (*DAT_6001f1dc)(1);
    uVar6 = ((DAT_6001ed38 + iVar3) - iVar2) - 1U & 0xffe00000;
    if (uVar6 != (uVar7 & 0xffe00000)) {
      iVar2 = (*DAT_6001f1dc)(1);
      DAT_6001ed38 = iVar2 + uVar6;
    }
    iVar2 = (*DAT_6001f1e0)(1);
    param_3 = 0;
    unaff_EDI = (iVar2 + 0xfU & 0xfffffff0) - DAT_6001ed38;
  }
  if (unaff_EDI < iVar3) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_600060d0(0x3c);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1c) = unaff_EBP;
      *(undefined4 *)(iVar2 + 0x20) = unaff_EBX;
      *(int *)(iVar2 + 0x24) = (int)cVar1;
      *(uint *)(iVar2 + 0x28) = (uint)(byte)(&DAT_60014474)[param_3 & 0xff];
      *(undefined4 *)(iVar2 + 0x2c) = 0;
      *(undefined4 *)(iVar2 + 0x34) = 3;
      *(int *)(iVar2 + 0x18) = DAT_6001da28;
      *(undefined4 *)(iVar2 + 0x38) = 0;
      DAT_6001da28 = iVar2;
      if (uVar5 == 0) {
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(int *)(iVar2 + 0x30) = DAT_6001ed34;
        DAT_6001ed34 = DAT_6001ed34 + iVar3;
        return iVar2;
      }
      if (uVar5 == 0x10000) {
        *(int *)(iVar2 + 0x30) = DAT_6001ed38;
        *(undefined4 *)(iVar2 + 0x14) = 1;
        DAT_6001ed38 = DAT_6001ed38 + iVar3;
        return iVar2;
      }
    }
  }
  return iVar2;
}



/* VA 60002690 */

undefined4 _THRASH_tfree_4(LPVOID param_1)

{
  int *piVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  undefined4 *puVar4;

                    /* 0x2690  36  _THRASH_tfree@4 */
  uVar2 = 0;
  puVar4 = &DAT_6001da28;
  pvVar3 = DAT_6001da28;
  if (DAT_6001da28 != (LPVOID)0x0) {
    while (pvVar3 != param_1) {
      puVar4 = (undefined4 *)((int)pvVar3 + 0x18);
      piVar1 = (int *)((int)pvVar3 + 0x18);
      pvVar3 = (LPVOID)*piVar1;
      if ((LPVOID)*piVar1 == (LPVOID)0x0) {
        return uVar2;
      }
    }
    *puVar4 = *(undefined4 *)((int)pvVar3 + 0x18);
    pvVar3 = DAT_6001da28;
    if (*(LPVOID *)((int)DAT_6001da28 + 0x38) != (LPVOID)0x0) {
      FUN_60006100(*(LPVOID *)((int)DAT_6001da28 + 0x38));
      pvVar3 = DAT_6001da28;
      *(undefined4 *)((int)DAT_6001da28 + 0x38) = 0;
    }
    FUN_60006100(pvVar3);
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 600026f0 */

int _THRASH_tupdate_12(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;

                    /* 0x26f0  38  _THRASH_tupdate@12 */
  iVar2 = DAT_60014044;
  if (param_2 != 0) {
    *(int *)(param_1 + 0x2c) = param_2;
    if (iVar2 < 2) {
      uVar1 = *(undefined4 *)(param_1 + 0x30);
      uVar4 = 0;
      uVar5 = DAT_60014034;
    }
    else {
      if (*(int *)(param_1 + 0x14) == 0) {
        (*DAT_6001f1d8)(0,*(undefined4 *)(param_1 + 0x30),DAT_60014034,param_1 + 0x1c);
      }
      if (*(int *)(param_1 + 0x14) != 1) goto LAB_6000275a;
      uVar1 = *(undefined4 *)(param_1 + 0x30);
      uVar4 = 1;
      uVar5 = DAT_60014038;
    }
    (*DAT_6001f1d8)(uVar4,uVar1,uVar5,param_1 + 0x1c);
  }
LAB_6000275a:
  if (param_3 != (undefined4 *)0x0) {
    if (param_2 != 0) {
      if (*(int *)(param_1 + 0x38) == 0) {
        uVar1 = FUN_600060d0(0x400);
        *(undefined4 *)(param_1 + 0x38) = uVar1;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x38);
      for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *param_3;
        param_3 = param_3 + 1;
        puVar3 = puVar3 + 1;
      }
      return param_1;
    }
    (*DAT_6001f158)(DAT_60014058,param_3);
  }
  return param_1;
}



/* VA 600027b0 */

undefined4 _THRASH_treset_0(void)

{
  LPVOID pvVar1;
  LPVOID pvVar2;

                    /* 0x27b0  37  _THRASH_treset@0 */
  DAT_6001ed34 = (*DAT_6001f1dc)(0);
  DAT_6001ed38 = (*DAT_6001f1dc)(1);
  if (DAT_6001da28 != (LPVOID)0x0) {
    do {
      pvVar2 = DAT_6001da28;
      if (*(LPVOID *)((int)DAT_6001da28 + 0x38) != (LPVOID)0x0) {
        FUN_60006100(*(LPVOID *)((int)DAT_6001da28 + 0x38));
        pvVar2 = DAT_6001da28;
        *(undefined4 *)((int)DAT_6001da28 + 0x38) = 0;
      }
      pvVar1 = *(LPVOID *)((int)pvVar2 + 0x18);
      FUN_60006100(pvVar2);
      DAT_6001da28 = pvVar1;
    } while (pvVar1 != (LPVOID)0x0);
    DAT_6001da28 = (LPVOID)0x0;
  }
  FUN_60006a20();
  return 1;
}



/* VA 60002810 */

int _THRASH_settexture_4(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;

                    /* 0x2810  32  _THRASH_settexture@4 */
  iVar1 = 1;
  if ((param_1 == 0) || (param_1 < 0x11)) {
    if (DAT_600144c8 == 0) goto LAB_6000297d;
    DAT_600144c8 = 0;
    iVar1 = FUN_60002990(DAT_6001405c,0);
    DAT_6001d8dc = 0;
    if (param_1 == 1) {
      (*DAT_6001f1d0)(0,3,8,3,8,0,0);
      if (1 < DAT_60014044) {
        uVar4 = 0;
        uVar5 = 1;
        uVar3 = 0;
        uVar2 = 1;
LAB_60002958:
        (*DAT_6001f1d0)(1,uVar2,uVar3,uVar5,uVar4,0,0);
      }
LAB_6000295f:
      (*DAT_6001f174)(3,8,1,1,0);
      (*DAT_6001f170)(3,8,0,1,0);
    }
    else if (param_1 == 2) {
      (*DAT_6001f1d0)(0,1,0,1,0,0,0);
      if (1 < DAT_60014044) {
        uVar4 = 8;
        uVar5 = 3;
        uVar3 = 8;
        uVar2 = 3;
        goto LAB_60002958;
      }
      goto LAB_6000295f;
    }
  }
  else {
    if (DAT_60014044 < 2) {
      uVar2 = *(undefined4 *)(param_1 + 0x30);
      uVar5 = 0;
      uVar3 = DAT_60014034;
LAB_600028a8:
      (*DAT_6001f1e4)(uVar5,uVar2,uVar3,param_1 + 0x1c);
    }
    else {
      if (*(int *)(param_1 + 0x14) == 0) {
        DAT_6001d8dc = 0;
        (*DAT_6001f1e4)(0,*(undefined4 *)(param_1 + 0x30),DAT_60014034,param_1 + 0x1c);
      }
      if (*(int *)(param_1 + 0x14) == 1) {
        DAT_6001d8dc = 1;
        if (DAT_6001d8e0 != 0) {
          _THRASH_setstate_8(0x10029,DAT_6001d8e4);
          DAT_6001d8e0 = 0;
        }
        uVar2 = *(undefined4 *)(param_1 + 0x30);
        uVar5 = 1;
        uVar3 = DAT_60014038;
        goto LAB_600028a8;
      }
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      (*DAT_6001f158)(DAT_60014058,*(int *)(param_1 + 0x38));
    }
    if (DAT_600144c8 == 1) goto LAB_6000297d;
    DAT_600144c8 = 1;
    iVar1 = FUN_60002990(DAT_6001405c,1);
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_6000297d:
  FUN_60005d20(1,param_1);
  return iVar1;
}



/* VA 60002990 */

undefined4 FUN_60002990(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;

  bVar3 = param_1 == 0;
  if (param_2 != 0) {
    if (param_1 == 3) {
      uVar1 = 5;
      uVar2 = 8;
    }
    else {
      uVar1 = 3;
      uVar2 = 1;
    }
    (*DAT_6001f170)(uVar1,1,bVar3,1,0);
    (*DAT_6001f174)(3,uVar2,bVar3,1,0);
    return 1;
  }
  (*DAT_6001f170)(1,0,bVar3,2,0);
  (*DAT_6001f174)(1,0,bVar3,2,0);
  return 1;
}



/* VA 60002a10 */

undefined4 _THRASH_window_4(int param_1)

{
                    /* 0x2a10  40  _THRASH_window@4 */
  FUN_60005d20(0x3b,param_1);
  if (param_1 == 0) {
    param_1 = 1;
  }
  DAT_6001d8b0 = param_1 + -1;
  if (param_1 == 3) {
    DAT_6001d9c8 = 1;
    DAT_6001d8b0 = 1;
    (*DAT_6001f15c)(1);
    return 1;
  }
  DAT_6001d9c8 = 0;
  (*DAT_6001f15c)(DAT_6001d8b0);
  return 1;
}



/* VA 60002a80 */

void _THRASH_clearwindow_0(void)

{
                    /* 0x2a80  2  _THRASH_clearwindow@0 */
  if (DAT_6001d9c8 == 0) {
    (*DAT_6001f160)(DAT_6001d8ac,0,DAT_60014048);
    return;
  }
  (*DAT_6001f21c)(0,0);
  (*DAT_6001f160)(DAT_6001d8ac,0,DAT_60014048);
  (*DAT_6001f21c)(1,1);
  return;
}



/* VA 60002ad0 */

void _THRASH_flushwindow_0(void)

{
                    /* 0x2ad0  21  _THRASH_flushwindow@0
                       0x2ad0  23  _THRASH_idle@0 */
  return;
}



/* VA 60002ae0 */

void _THRASH_pageflip_0(void)

{
  int iVar1;
  int iVar2;
  int local_4;

                    /* 0x2ae0  27  _THRASH_pageflip@0 */
  iVar2 = 4000000;
  _THRASH_flushwindow_0();
  do {
    iVar1 = (*DAT_6001f1f0)(0x14,4,&local_4);
    if ((iVar1 == 0) || (local_4 <= DAT_6001d8c0)) break;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (*DAT_6001f164)(DAT_6001404c);
  DAT_6001d8c4 = DAT_6001d8c4 + 1;
  return;
}



/* VA 60002b30 */

int _THRASH_sync_4(undefined4 param_1)

{
  int iVar1;
  int unaff_ESI;
  int iVar2;
  int local_c;
  undefined1 local_8 [8];

                    /* 0x2b30  34  _THRASH_sync@4 */
  local_c = 0;
  iVar2 = 0;
  switch(param_1) {
  case 0:
    (*DAT_6001f168)();
    iVar2 = local_c;
    break;
  case 1:
    iVar1 = (*DAT_6001f1f0)(8,4,&local_c);
    iVar2 = local_c;
    if (iVar1 == 0) {
      return 0;
    }
    break;
  case 2:
    iVar2 = 4000000;
    do {
      iVar1 = (*DAT_6001f1f0)(0x25,4,&local_c);
      if ((iVar1 == 0) || (local_c == 0)) break;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = 4000000;
    while( true ) {
      iVar1 = (*DAT_6001f1f0)(0x25,4,&local_c);
      if (iVar1 == 0) {
        return 0;
      }
      if (local_c != 0) break;
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        return 0;
      }
    }
    return 0;
  case 3:
    iVar1 = (*DAT_6001f1f0)(3,8,local_8);
    iVar2 = 0xffff - unaff_ESI;
    if (iVar1 == 0) {
      return 0;
    }
  }
  return iVar2;
}



/* VA 60002c10 */

undefined4
_THRASH_clip_16(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
                    /* 0x2c10  3  _THRASH_clip@16 */
  (*DAT_6001f16c)(param_1,param_2,param_3,param_4);
  return 1;
}



/* VA 60002c40 */

undefined4 __cdecl FUN_60002c40(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_EBX;
  int iVar3;
  int iVar4;
  undefined1 local_400 [1024];

  if (0x40 < DAT_6001d8c8) {
    iVar4 = DAT_6001d8c8;
    if (0x400 < DAT_6001d8c8) {
      iVar4 = 0x400;
    }
    if (0 < iVar4) {
      iVar1 = 0;
      iVar3 = 0x20;
      do {
        iVar2 = iVar1 + 1;
        local_400[iVar1] = *(undefined1 *)(((int)(iVar3 + (iVar3 >> 0x1f & 0x3fU)) >> 6) + param_1);
        iVar1 = iVar2;
        iVar3 = iVar3 + DAT_6001d8c8;
      } while (iVar2 < iVar4);
    }
    (*DAT_6001f1a4)(local_400);
    return unaff_EBX;
  }
  (*DAT_6001f1a4)(param_1);
  return 1;
}



/* VA 60002ce0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _THRASH_setstate_8(uint param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  void *this;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  bool bVar9;
  longlong lVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined1 local_50 [16];
  undefined1 local_40 [64];

                    /* 0x2ce0  31  _THRASH_setstate@8 */
  puVar2 = param_2;
  puVar6 = (undefined4 *)0x0;
  bVar9 = false;
  if ((param_1 & 0xffff0000) == 0) {
    bVar9 = false;
  }
  else if ((param_1 & 0xffff0000) == 0x10000) {
    bVar9 = true;
  }
  switch(param_1 & 0xffff) {
  case 1:
    puVar6 = (undefined4 *)_THRASH_settexture_4((uint)param_2);
    goto LAB_6000389b;
  default:
    uVar15 = CONCAT44(param_2,param_1) & 0xffffffff0000ffff;
    puVar6 = (undefined4 *)FUN_60006130((uint)uVar15,(undefined *)(uVar15 >> 0x20));
    goto LAB_6000389b;
  case 3:
    DAT_6001d8ac = param_2;
    puVar6 = (undefined4 *)0x1;
    break;
  case 4:
    if (param_2 != (undefined4 *)0x0) {
      if (param_2 == (undefined4 *)0x1) {
        uVar5 = 1;
        (*DAT_6001f190)();
        uVar14 = CONCAT44(uVar5,DAT_6001406c);
      }
      else {
        if (param_2 != (undefined4 *)0x2) {
          return (undefined4 *)0x0;
        }
        uVar5 = 2;
        (*DAT_6001f190)();
        uVar14 = CONCAT44(uVar5,DAT_6001406c);
      }
      (*DAT_6001f194)(uVar14);
      (*DAT_6001f198)(1);
      goto LAB_60003176;
    }
    (*DAT_6001f194)();
    (*DAT_6001f198)(0);
    puVar6 = (undefined4 *)0x1;
    break;
  case 5:
    if (param_2 == (undefined4 *)0x0) {
      (*DAT_6001f184)();
      puVar6 = (undefined4 *)0x1;
    }
    else {
      (*DAT_6001f184)();
      puVar6 = (undefined4 *)0x1;
    }
    break;
  case 6:
    DAT_6001405c = param_2;
    puVar6 = (undefined4 *)FUN_60002990((int)param_2,DAT_600144c8);
    goto LAB_6000389b;
  case 7:
    if (bVar9) {
      if ((!bVar9) || ((int)DAT_60014044 < 2)) goto LAB_60003176;
      (*DAT_6001f180)(1,param_2);
      puVar6 = (undefined4 *)0x1;
    }
    else {
      (*DAT_6001f180)(0,param_2);
      puVar6 = (undefined4 *)0x1;
    }
    break;
  case 8:
    (*DAT_6001f1ec)(0);
    if (1 < (int)DAT_60014044) {
      (*DAT_6001f1ec)(1);
    }
    puVar6 = (undefined4 *)0x1;
    break;
  case 9:
    if (param_2 == (undefined4 *)0x0) {
LAB_6000375d:
      puVar6 = (undefined4 *)0x0;
    }
    else if (param_2 == (undefined4 *)0x1) {
      (*DAT_6001f200)();
      puVar6 = (undefined4 *)0x1;
    }
    else if (param_2 == (undefined4 *)0x2) goto LAB_6000375d;
    DAT_6001d8b8 = param_2;
    FUN_60004010(DAT_6001d8bc,(int)param_2);
    goto LAB_6000389b;
  case 10:
    if (param_2 == (undefined4 *)0x0) {
      (*DAT_6001f188)();
      (*DAT_6001f18c)(7);
      puVar6 = (undefined4 *)0x1;
    }
    else {
      if (param_2 == (undefined4 *)0x1) {
        (*DAT_6001f188)();
        goto LAB_600030db;
      }
      if (param_2 == (undefined4 *)0x2) {
        (*DAT_6001f188)();
        (*DAT_6001f18c)(4);
        puVar6 = (undefined4 *)0x1;
      }
      else {
        if (param_2 != (undefined4 *)0x3) {
          return (undefined4 *)0x0;
        }
        (*DAT_6001f188)();
        (*DAT_6001f18c)(4);
        puVar6 = (undefined4 *)0x1;
      }
    }
    break;
  case 0xb:
    _THRASH_getstate_4(1);
    switch(param_2) {
    case (undefined4 *)0x0:
      FUN_60004010(DAT_6001d8bc,(int)DAT_6001d8b8);
      (*DAT_6001f1cc)(0,0);
      (*DAT_6001f1cc)(1,0,0);
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x1:
      FUN_60004010(DAT_6001d8bc,(int)DAT_6001d8b8);
      (*DAT_6001f1cc)(0,1);
      (*DAT_6001f1cc)(1,1,0);
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x2:
      FUN_60004010(DAT_6001d8bc,(int)DAT_6001d8b8);
      (*DAT_6001f1cc)(0,2);
      (*DAT_6001f1cc)(1,2,0);
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x3:
switchD_600036e5_default:
      return (undefined4 *)0x0;
    default:
      goto switchD_60002ef0_caseD_2;
    }
    break;
  case 0xc:
    (*DAT_6001f1fc)();
    puVar6 = (undefined4 *)0x1;
    break;
  case 0xd:
    if (param_2 == (undefined4 *)0x0) {
      DAT_60014064 = 1;
      DAT_60014060 = 1;
    }
    else if (param_2 == (undefined4 *)0x1) {
      DAT_60014060 = 0;
      DAT_60014064 = 0;
    }
    else {
      if (param_2 != (undefined4 *)0x2) {
        return (undefined4 *)0x0;
      }
      if (DAT_6001d89c == 0) {
        return (undefined4 *)0x0;
      }
      DAT_60014064 = 2;
      DAT_60014060 = 2;
    }
    puVar6 = (undefined4 *)0x1;
    if (bVar9) {
      if ((bVar9) && (1 < (int)DAT_60014044)) {
        (*DAT_6001f1e8)(1,DAT_60014060);
      }
    }
    else {
      (*DAT_6001f1e8)(0,DAT_60014060);
    }
    break;
  case 0xe:
    if ((param_2 != (undefined4 *)0x0) && (((uint)param_2 & 0xfffff000) == 0)) {
      param_2 = (undefined4 *)(_DAT_600125a0 / (float)(int)param_2);
    }
    if (DAT_6001d8a4 == (undefined4 *)0x2) {
      FUN_60001480((int)local_40,DAT_6001d8d8,DAT_60014070);
    }
    else if (DAT_6001d8a4 == (undefined4 *)0x8) {
      FUN_60003b10((int)local_40,(float)param_2);
    }
    else {
      FUN_60003a50((int)local_40,(float)param_2);
    }
    puVar6 = (undefined4 *)FUN_60002c40((int)local_40);
    goto LAB_6000389b;
  case 0xf:
    (*DAT_6001f19c)();
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x10:
    puVar6 = (undefined4 *)0x1;
    _DAT_60014068 = (float)(int)param_2 * _DAT_60012680;
    break;
  case 0x14:
  case 0x69:
    puVar6 = (undefined4 *)0x1;
    if (param_2 != (undefined4 *)0x0) {
      puVar6 = (undefined4 *)FUN_60002c40((int)param_2);
      goto LAB_6000389b;
    }
    break;
  case 0x15:
    switch(param_2) {
    case (undefined4 *)0x0:
      DAT_6001d8a0 = 0;
      (*DAT_6001f1a0)();
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x1:
      DAT_6001d8a0 = 2;
      (*DAT_6001f1a0)();
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x2:
    case (undefined4 *)0x4:
    case (undefined4 *)0x8:
      DAT_6001d8a4 = param_2;
      puVar6 = (undefined4 *)0x1;
      break;
    default:
      goto switchD_60002ef0_caseD_2;
    }
    break;
  case 0x16:
    DAT_6001d8d8 = (float)(int)param_2 * _DAT_600126f8;
    FUN_60001480((int)local_40,DAT_6001d8d8,DAT_60014070);
    puVar6 = (undefined4 *)FUN_60002c40((int)local_40);
    goto LAB_6000389b;
  case 0x17:
    DAT_60014070 = (float)(int)param_2 * _DAT_600126f8;
    FUN_60001480((int)local_40,DAT_6001d8d8,DAT_60014070);
    puVar6 = (undefined4 *)FUN_60002c40((int)local_40);
LAB_6000389b:
    if (puVar6 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    break;
  case 0x18:
  case 0x66:
    (*DAT_6001f1c8)();
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x24:
    if (param_2 == (undefined4 *)0x0) {
LAB_600030db:
      (*DAT_6001f18c)();
      puVar6 = (undefined4 *)0x1;
    }
    else {
      (*DAT_6001f18c)();
      (*DAT_6001f154)(param_2);
      puVar6 = (undefined4 *)0x1;
    }
    break;
  case 0x28:
    switch(param_2) {
    case (undefined4 *)0x0:
      DAT_6001406c = 0;
      (*DAT_6001f194)();
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x1:
      puVar6 = (undefined4 *)0x1;
      DAT_6001406c = 1;
      (*DAT_6001f194)();
      break;
    case (undefined4 *)0x2:
      DAT_6001406c = 2;
      (*DAT_6001f194)();
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x3:
      DAT_6001406c = 3;
      (*DAT_6001f194)();
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x4:
      DAT_6001406c = 4;
      (*DAT_6001f194)();
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x5:
      DAT_6001406c = 5;
      (*DAT_6001f194)();
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x6:
      DAT_6001406c = 6;
      (*DAT_6001f194)();
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x7:
      DAT_6001406c = 7;
      (*DAT_6001f194)();
      puVar6 = (undefined4 *)0x1;
      break;
    default:
      goto switchD_600036e5_default;
    }
    break;
  case 0x29:
    switch(param_2) {
    case (undefined4 *)0x0:
      if (bVar9) {
        if ((bVar9) && (1 < (int)DAT_60014044)) {
          uVar5 = 1;
          goto LAB_60002f28;
        }
      }
      else {
        uVar5 = 0;
LAB_60002f28:
        (*DAT_6001f1d0)(uVar5,1,0,1,0,0);
      }
      FUN_60002990((int)DAT_6001405c,DAT_600144c8);
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x1:
      if (DAT_6001d8dc == 0) {
        DAT_6001d8e0 = 1;
        DAT_6001d8e4 = 1;
        puVar6 = (undefined4 *)0x1;
      }
      else {
        (*DAT_6001f1d0)(1,1,0,1,8,0);
        uVar13 = 8;
        uVar12 = 4;
        uVar11 = 8;
        uVar5 = 4;
LAB_60002fb5:
        (*DAT_6001f1d0)(0,uVar5,uVar11,uVar12,uVar13,0,0);
        (*DAT_6001f170)(3,8,1,1,0);
        puVar6 = (undefined4 *)0x1;
      }
      break;
    default:
      goto switchD_60002ef0_caseD_2;
    case (undefined4 *)0x3:
      if (DAT_6001d8dc != 0) {
        (*DAT_6001f1d0)(1,1,0,1,8,0);
        uVar13 = 1;
        uVar12 = 3;
        uVar11 = 1;
        uVar5 = 3;
        goto LAB_60002fb5;
      }
      DAT_6001d8e0 = 1;
      DAT_6001d8e4 = 3;
      puVar6 = (undefined4 *)0x1;
      break;
    case (undefined4 *)0x4:
    case (undefined4 *)0x5:
    case (undefined4 *)0x6:
    case (undefined4 *)0x7:
      goto switchD_600036e5_default;
    }
    break;
  case 0x2a:
    if (param_2 == (undefined4 *)0x0) {
      _THRASH_setstate_8(0x1e,(undefined4 *)0x20);
      DAT_6001d898 = 0;
      (*DAT_6001f218)(0x40,0x18);
      if ((int)DAT_60014044 < 2) goto LAB_60003176;
      (*DAT_6001f218)(0x41,0x18);
      puVar6 = (undefined4 *)0x1;
    }
    else if (param_2 == (undefined4 *)0x1) {
      _THRASH_setstate_8(0x1e,(undefined4 *)0x28);
      DAT_6001d898 = 1;
      (*DAT_6001f218)(0x41,0x20);
      puVar6 = (undefined4 *)0x1;
    }
    else {
LAB_60003176:
      puVar6 = (undefined4 *)0x1;
    }
    break;
  case 0x2c:
    (*DAT_6001f158)(DAT_60014058);
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x2e:
  case 0x65:
    FUN_60007248(local_50,&DAT_600126f0);
    FUN_60006a40();
    FUN_60006a40();
    FUN_60006a40();
    FUN_60006a40();
    FUN_60006a40();
    FUN_60006a40();
    FUN_60006a40();
    FUN_60006a40();
    if ((&DAT_6001d858)[DAT_6001d854] != 0) {
      (*DAT_6001f1c4)(param_2,param_2);
    }
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x38:
  case 0x68:
    puVar6 = (undefined4 *)0x1;
    switch(param_2) {
    case (undefined4 *)0x0:
      uVar5 = 1;
      DAT_60014040 = 5;
      DAT_6001403c = 1;
      break;
    case (undefined4 *)0x1:
      uVar5 = 1;
      DAT_60014040 = 4;
      DAT_6001403c = 1;
      break;
    case (undefined4 *)0x2:
      uVar5 = 0;
      DAT_60014040 = 5;
      DAT_6001403c = 0;
      break;
    case (undefined4 *)0x3:
      uVar5 = 2;
      DAT_60014040 = 0;
      DAT_6001403c = 2;
      break;
    default:
      goto switchD_600036e5_default;
    }
    (*DAT_6001f178)(uVar5,DAT_60014040,4);
    break;
  case 0x39:
  case 0x6a:
    (*DAT_6001f198)();
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x3c:
  case 0x67:
    DAT_6001404c = param_2;
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x3f:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0xc4ffe000;
      param_2[1] = 0x44ffe000;
      param_2[2] = 0xc4ffe000;
      param_2[3] = 0x44ffe000;
      return param_2;
    }
    return (undefined4 *)0x0;
  case 0x41:
    if (param_2 == (undefined4 *)0x0) {
      DAT_60014060 = 1;
    }
    else if (param_2 == (undefined4 *)0x1) {
      DAT_60014060 = 0;
    }
    else {
      if (param_2 != (undefined4 *)0x2) {
        return (undefined4 *)0x0;
      }
      if (DAT_6001d89c == 0) {
        return (undefined4 *)0x0;
      }
      DAT_60014060 = 2;
    }
    puVar6 = (undefined4 *)0x1;
    if (bVar9) {
      if ((bVar9) && (1 < (int)DAT_60014044)) {
        (*DAT_6001f1e8)(1,DAT_60014060);
      }
    }
    else {
      (*DAT_6001f1e8)(0,DAT_60014060);
    }
    break;
  case 0x42:
    if (param_2 == (undefined4 *)0x0) {
      DAT_60014064 = 1;
    }
    else if (param_2 == (undefined4 *)0x1) {
      DAT_60014064 = 0;
    }
    else {
      if (param_2 != (undefined4 *)0x2) {
        return (undefined4 *)0x0;
      }
      if (DAT_6001d89c == 0) {
        return (undefined4 *)0x0;
      }
      DAT_60014064 = 2;
    }
    puVar6 = (undefined4 *)0x1;
    if (bVar9) {
      if ((bVar9) && (1 < (int)DAT_60014044)) {
        (*DAT_6001f1e8)(1,DAT_60014060);
      }
    }
    else {
      (*DAT_6001f1e8)(0,DAT_60014060);
    }
    break;
  case 0x43:
    lVar10 = __ftol();
    DAT_60014048 = (undefined4)lVar10;
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x6b:
    if (DAT_60014030 != 0) {
      return (undefined4 *)0x0;
    }
    DAT_6001d850 = param_2;
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x6c:
    if (DAT_60014030 != 0) {
      return (undefined4 *)0x0;
    }
    puVar6 = (undefined4 *)0x1;
    if (param_2 == (undefined4 *)0x0) {
      (*DAT_6001f200)();
    }
    else {
      (*DAT_6001f204)();
    }
    break;
  case 0x6d:
    DAT_6001d8c0 = param_2;
    puVar6 = (undefined4 *)0x1;
    break;
  case 0x6e:
    if (param_2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar6 = (undefined4 *)0x1;
    *param_2 = DAT_6001d8e8;
    break;
  case 0x6f:
    puVar8 = (undefined4 *)0x1;
    iVar4 = (*DAT_6001f1f0)(0x13,4);
    if (((iVar4 != 0) && (0 < (int)param_2)) && ((int)param_2 < 0x11)) {
      puVar8 = param_2;
    }
    pbVar3 = (byte *)FUN_60007076((uchar *)"VOODOO2_NUMTMU");
    if (pbVar3 != (byte *)0x0) {
      puVar8 = (undefined4 *)FUN_6000706b(this,pbVar3);
    }
    puVar6 = (undefined4 *)0x1;
    if (param_2 != (undefined4 *)0x0) {
      if ((int)puVar8 < (int)param_2) {
        return (undefined4 *)0x0;
      }
      DAT_60014044 = param_2;
    }
    break;
  case 0x70:
    pbVar3 = (byte *)(*DAT_6001f1f4)();
    pcVar7 = "Voodoo Banshee";
    do {
      bVar1 = *pbVar3;
      bVar9 = bVar1 < (byte)*pcVar7;
      if (bVar1 != *pcVar7) {
LAB_60002d65:
        iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_60002d6a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar9 = bVar1 < (byte)pcVar7[1];
      if (bVar1 != pcVar7[1]) goto LAB_60002d65;
      pbVar3 = pbVar3 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_60002d6a:
    if (iVar4 != 0) {
      return (undefined4 *)0x0;
    }
    FUN_60002230();
    puVar6 = (undefined4 *)0x1;
  }
  FUN_60005d20(param_1,puVar2);
switchD_60002ef0_caseD_2:
  return puVar6;
}



/* VA 60003a50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60003a50(int param_1,float param_2)

{
  uint uVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  undefined1 local_8;

  fVar2 = FUN_60001510(0x3f);
  uVar1 = 0;
  fVar5 = (float10)1.4426950408889634 * -(fVar2 * (float10)param_2);
  fVar2 = ROUND(fVar5);
  fVar5 = (float10)f2xm1(fVar5 - fVar2);
  fVar3 = (float10)fscale((float10)1 + fVar5,fVar2);
  fVar5 = (float10)_DAT_600125a0;
  fVar2 = (float10)_DAT_600125a0;
  do {
    fVar4 = FUN_60001510(uVar1);
    fVar6 = (float10)1.4426950408889634 * -(fVar4 * (float10)param_2);
    fVar4 = ROUND(fVar6);
    fVar6 = (float10)f2xm1(fVar6 - fVar4);
    fVar4 = (float10)fscale((float10)1 + fVar6,fVar4);
    fVar4 = ((float10)_DAT_600125a0 - fVar4) * (float10)(float)(fVar2 / (fVar5 - fVar3));
    if (fVar4 <= (float10)_DAT_600125a0) {
      if (fVar4 < (float10)_DAT_6001259c) {
        fVar4 = (float10)_DAT_6001259c;
      }
    }
    else {
      fVar4 = (float10)_DAT_600125a0;
    }
    local_8 = (undefined1)(int)ROUND((float)(fVar4 * (float10)_DAT_60012598));
    *(undefined1 *)(uVar1 + param_1) = local_8;
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x40);
  return;
}



/* VA 60003b10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60003b10(int param_1,float param_2)

{
  uint uVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  undefined1 local_8;

  fVar2 = FUN_60001510(0x3f);
  uVar1 = 0;
  fVar5 = (float10)1.4426950408889634 * -(fVar2 * (float10)param_2 * fVar2 * (float10)param_2);
  fVar2 = ROUND(fVar5);
  fVar5 = (float10)f2xm1(fVar5 - fVar2);
  fVar3 = (float10)fscale((float10)1 + fVar5,fVar2);
  fVar5 = (float10)_DAT_600125a0;
  fVar2 = (float10)_DAT_600125a0;
  do {
    fVar4 = FUN_60001510(uVar1);
    fVar6 = (float10)1.4426950408889634 * -(fVar4 * (float10)param_2 * fVar4 * (float10)param_2);
    fVar4 = ROUND(fVar6);
    fVar6 = (float10)f2xm1(fVar6 - fVar4);
    fVar4 = (float10)fscale((float10)1 + fVar6,fVar4);
    fVar4 = ((float10)_DAT_600125a0 - fVar4) * (float10)(float)(fVar2 / (fVar5 - fVar3));
    if (fVar4 <= (float10)_DAT_600125a0) {
      if (fVar4 < (float10)_DAT_6001259c) {
        fVar4 = (float10)_DAT_6001259c;
      }
    }
    else {
      fVar4 = (float10)_DAT_600125a0;
    }
    local_8 = (undefined1)(int)ROUND((float)(fVar4 * (float10)_DAT_60012598));
    *(undefined1 *)(uVar1 + param_1) = local_8;
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x40);
  return;
}



/* VA 60003be0 */

int * _THRASH_lockwindow_0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int unaff_EDI;
  uint uVar5;
  int iVar6;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;

                    /* 0x3be0  26  _THRASH_lockwindow@0 */
  puStack_28 = (undefined4 *)0x60003bf5;
  (*DAT_6001f168)();
  if (DAT_6001da08 != (code *)0x0) {
    puStack_28 = (undefined4 *)0x1;
    uStack_2c = 0x60003c02;
    (*DAT_6001da08)();
  }
  puStack_28 = &uStack_14;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_14 = 0x14;
  uStack_8 = 0;
  uStack_2c = 0;
  iVar6 = 0;
  uStack_4 = 0;
  iVar1 = (*DAT_6001f1a8)(0,DAT_6001d8b0,0xff,0);
  puVar3 = (undefined4 *)0x0;
  iVar4 = 0;
  if (iVar1 != 0) {
    puVar3 = puStack_28;
    iVar4 = unaff_EDI;
  }
  uVar5 = (uint)(iVar1 != 0);
  puStack_28 = (undefined4 *)0x0;
  uStack_2c = 0x14;
  iVar1 = (*DAT_6001f1a8)(1,DAT_6001d8b0,0xff,0,0);
  if (iVar1 != 0) {
    if ((uVar5 == 0) || (DAT_6001d95c == 2)) {
      puVar3 = &uStack_2c;
      iVar4 = iVar6;
    }
    uVar5 = uVar5 | 2;
  }
  if (uVar5 != 0) {
    piVar2 = (int *)FUN_600060d0(0x1c);
    iVar6 = DAT_6001d8b0;
    iVar1 = DAT_60014054;
    if (piVar2 != (int *)0x0) {
      piVar2[3] = DAT_60014050;
      piVar2[6] = uVar5;
      *piVar2 = (int)puVar3;
      piVar2[1] = iVar4;
      piVar2[2] = 4;
      piVar2[4] = iVar1;
      piVar2[5] = iVar6;
      return piVar2;
    }
  }
  if (DAT_6001da08 != (code *)0x0) {
    (*DAT_6001da08)(0);
  }
  return (int *)0x0;
}



/* VA 60003d00 */

undefined4 _THRASH_unlockwindow_4(LPVOID param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;

                    /* 0x3d00  39  _THRASH_unlockwindow@4 */
  uVar3 = 1;
  if (param_1 != (LPVOID)0x0) {
    uVar1 = *(uint *)((int)param_1 + 0x18);
    uVar2 = *(undefined4 *)((int)param_1 + 0x14);
    if ((uVar1 & 2) != 0) {
      uVar3 = (*DAT_6001f1ac)(1,uVar2);
    }
    if ((uVar1 & 1) != 0) {
      uVar3 = (*DAT_6001f1ac)(0,uVar2);
    }
    FUN_60006100(param_1);
    if (DAT_6001da08 != (code *)0x0) {
      (*DAT_6001da08)(0);
    }
  }
  return uVar3;
}



/* VA 60003d60 */

undefined4
_THRASH_readrect_20(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                   undefined4 param_5)

{
  undefined4 uVar1;

                    /* 0x3d60  28  _THRASH_readrect@20 */
  if (DAT_6001da08 != (code *)0x0) {
    (*DAT_6001da08)(1);
  }
  uVar1 = (*DAT_6001f1b4)(DAT_6001d8b0,param_1,param_2,param_3,param_4,param_3 * 2,param_5);
  if (DAT_6001da08 != (code *)0x0) {
    (*DAT_6001da08)(0);
  }
  return uVar1;
}



/* VA 60003db0 */

undefined4
_THRASH_writerect_20
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;

                    /* 0x3db0  41  _THRASH_writerect@20 */
  if (DAT_6001da08 != (code *)0x0) {
    (*DAT_6001da08)(1);
  }
  uVar1 = (*DAT_6001f1b0)(DAT_6001d8b0,param_1,param_2,0,param_3,param_4,0,param_3 * 2,param_5);
  if (DAT_6001da08 != (code *)0x0) {
    (*DAT_6001da08)(0);
  }
  return uVar1;
}



/* VA 60004010 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60004010(int param_1,int param_2)

{
  if (param_2 == 0) {
    DAT_6001ed20 = DAT_6001f1b8;
    DAT_6001ed28 = DAT_6001f1b8;
  }
  else {
    DAT_6001ed20 = &LAB_600041a0;
    DAT_6001ed28 = &LAB_600041c0;
  }
  _DAT_6001f220 = DAT_6001f1bc;
  if ((param_1 != 0) && (DAT_60014044 == 1)) {
    DAT_6001ed2c = FUN_60004080;
    DAT_6001ed24 = FUN_60004110;
    return;
  }
  DAT_6001ed2c = (code *)DAT_6001ed20;
  DAT_6001ed24 = (code *)DAT_6001ed28;
  return;
}



/* VA 60004080 */

void FUN_60004080(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;

  uVar3 = 0;
  uVar2 = 0;
  uVar1 = 0;
  (*DAT_6001f1d0)(0,9,5,1,0,0,0);
  (*DAT_6001ed20)(uVar1,uVar2,uVar3);
  (*DAT_6001f178)(DAT_6001403c,4,4,0);
  (*DAT_6001f1d0)(0,9,0xd,1,0,0,0);
  (*DAT_6001f1a0)(0);
  (*DAT_6001ed20)(uVar1,uVar2,uVar3);
  (*DAT_6001f1a0)(DAT_6001d8a0);
  (*DAT_6001f178)(DAT_6001403c,DAT_60014040,4,0);
  return;
}



/* VA 60004110 */

void FUN_60004110(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;

  uVar3 = 0;
  uVar2 = 0;
  uVar1 = 0;
  (*DAT_6001f1d0)(0,9,5,1,0,0,0);
  (*DAT_6001ed28)(uVar1,uVar2,uVar3);
  (*DAT_6001f178)(DAT_6001403c,4,4,0);
  (*DAT_6001f1d0)(0,9,0xd,1,0,0,0);
  (*DAT_6001f1a0)(0);
  (*DAT_6001ed28)(uVar1,uVar2,uVar3);
  (*DAT_6001f1a0)(DAT_6001d8a0);
  (*DAT_6001f178)(DAT_6001403c,DAT_60014040,4,0);
  return;
}



/* VA 600041e0 */

void _THRASH_drawquad_16(float *param_1,float *param_2,float *param_3,undefined4 *param_4)

{
  float fVar1;
  float local_a0;
  float local_9c;
  int local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  int local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x41e0  11  _THRASH_drawquad@16 */
  if ((DAT_6001da20 == 1) ||
     (((uint)((*param_2 - *param_1) * (param_3[1] - param_1[1]) -
             (*param_3 - *param_1) * (param_2[1] - param_1[1])) & 0x80000000) != DAT_6001da20)) {
    local_a0 = *param_1;
    local_9c = param_1[1];
    local_98 = (int)param_1[2] + 0x8000000;
    local_94 = param_1[3];
    fVar1 = (float)((int)local_94 + 0x4000000);
    local_90 = param_1[4];
    local_88 = fVar1 * param_1[6];
    local_8c = param_1[5];
    local_84 = fVar1 * param_1[7];
    if (DAT_6001d898 == 1) {
      local_80 = fVar1 * param_1[8];
      local_7c = fVar1 * param_1[9];
    }
    local_78 = *param_2;
    local_74 = param_2[1];
    local_70 = (int)param_2[2] + 0x8000000;
    local_6c = param_2[3];
    fVar1 = (float)((int)local_6c + 0x4000000);
    local_68 = param_2[4];
    local_60 = fVar1 * param_2[6];
    local_64 = param_2[5];
    local_5c = fVar1 * param_2[7];
    if (DAT_6001d898 == 1) {
      local_58 = fVar1 * param_2[8];
      local_54 = fVar1 * param_2[9];
    }
    local_50 = *param_3;
    local_4c = param_3[1];
    local_44 = param_3[3];
    local_48 = (int)param_3[2] + 0x8000000;
    fVar1 = (float)((int)local_44 + 0x4000000);
    local_40 = param_3[4];
    local_3c = param_3[5];
    local_38 = fVar1 * param_3[6];
    local_34 = fVar1 * param_3[7];
    if (DAT_6001d898 == 1) {
      local_30 = fVar1 * param_3[8];
      local_2c = fVar1 * param_3[9];
    }
    local_28 = *param_4;
    local_24 = param_4[1];
    local_1c = param_4[3];
    local_20 = param_4[2] + 0x8000000;
    fVar1 = (float)(local_1c + 0x4000000);
    local_18 = param_4[4];
    local_14 = param_4[5];
    local_10 = fVar1 * (float)param_4[6];
    local_c = fVar1 * (float)param_4[7];
    if (DAT_6001d898 == 1) {
      local_8 = fVar1 * (float)param_4[8];
      local_4 = fVar1 * (float)param_4[9];
    }
    (*DAT_6001ed24)(&local_a0,&local_78,&local_50);
    (*DAT_6001ed24)(&local_5c,&local_34,&stack0xffffff54);
  }
  return;
}



/* VA 60004450 */

void _THRASH_drawquadmesh_12(int param_1,int param_2,int *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  undefined4 *puVar6;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  int local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  int local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x4450  12  _THRASH_drawquadmesh@12 */
  iVar5 = DAT_60014514;
  if (0 < param_1) {
    do {
      pfVar1 = (float *)(*param_3 * iVar5 + param_2);
      pfVar2 = (float *)(param_3[1] * iVar5 + param_2);
      pfVar4 = (float *)(param_3[2] * iVar5 + param_2);
      puVar6 = (undefined4 *)(param_3[3] * iVar5 + param_2);
      if ((DAT_6001da20 == 1) ||
         (local_a4 = (*pfVar2 - *pfVar1) * (pfVar4[1] - pfVar1[1]) -
                     (*pfVar4 - *pfVar1) * (pfVar2[1] - pfVar1[1]),
         ((uint)local_a4 & 0x80000000) != DAT_6001da20)) {
        local_a0 = *pfVar1;
        local_9c = pfVar1[1];
        local_98 = (int)pfVar1[2] + 0x8000000;
        local_94 = pfVar1[3];
        local_a8 = (float)((int)local_94 + 0x4000000);
        local_90 = pfVar1[4];
        local_88 = local_a8 * pfVar1[6];
        local_8c = pfVar1[5];
        local_84 = local_a8 * pfVar1[7];
        if (DAT_6001d898 == 1) {
          local_80 = local_a8 * pfVar1[8];
          local_7c = local_a8 * pfVar1[9];
        }
        local_78 = *pfVar2;
        local_74 = pfVar2[1];
        local_70 = (int)pfVar2[2] + 0x8000000;
        local_6c = pfVar2[3];
        local_ac = (float)((int)local_6c + 0x4000000);
        local_68 = pfVar2[4];
        local_60 = local_ac * pfVar2[6];
        local_64 = pfVar2[5];
        local_5c = local_ac * pfVar2[7];
        if (DAT_6001d898 == 1) {
          local_58 = local_ac * pfVar2[8];
          local_54 = local_ac * pfVar2[9];
        }
        local_50 = *pfVar4;
        local_4c = pfVar4[1];
        local_44 = pfVar4[3];
        local_48 = (int)pfVar4[2] + 0x8000000;
        fVar3 = (float)((int)local_44 + 0x4000000);
        local_40 = pfVar4[4];
        local_3c = pfVar4[5];
        local_38 = fVar3 * pfVar4[6];
        local_34 = fVar3 * pfVar4[7];
        if (DAT_6001d898 == 1) {
          local_30 = fVar3 * pfVar4[8];
          local_2c = fVar3 * pfVar4[9];
        }
        local_28 = *puVar6;
        local_24 = puVar6[1];
        local_1c = puVar6[3];
        fVar3 = (float)(local_1c + 0x4000000);
        local_20 = puVar6[2] + 0x8000000;
        local_10 = fVar3 * (float)puVar6[6];
        local_18 = puVar6[4];
        local_14 = puVar6[5];
        local_c = fVar3 * (float)puVar6[7];
        if (DAT_6001d898 == 1) {
          local_8 = fVar3 * (float)puVar6[8];
          local_4 = fVar3 * (float)puVar6[9];
        }
        (*DAT_6001ed24)(&local_a0,&local_78,&local_50);
        (*DAT_6001ed24)(&local_5c,&local_34,&local_ac);
        iVar5 = DAT_60014514;
      }
      param_3 = param_3 + 4;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60004720 */

void _THRASH_drawtri_12(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float local_78;
  float local_74;
  int local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x4720  15  _THRASH_drawtri@12 */
  if ((DAT_6001da20 == 1) ||
     (((uint)((*param_2 - *param_1) * (param_3[1] - param_1[1]) -
             (*param_3 - *param_1) * (param_2[1] - param_1[1])) & 0x80000000) != DAT_6001da20)) {
    local_78 = *param_1;
    local_74 = param_1[1];
    local_70 = (int)param_1[2] + 0x8000000;
    local_6c = param_1[3];
    fVar1 = (float)((int)local_6c + 0x4000000);
    local_68 = param_1[4];
    local_60 = fVar1 * param_1[6];
    local_64 = param_1[5];
    local_5c = fVar1 * param_1[7];
    if (DAT_6001d898 == 1) {
      local_58 = fVar1 * param_1[8];
      local_54 = fVar1 * param_1[9];
    }
    local_50 = *param_2;
    local_4c = param_2[1];
    local_48 = (int)param_2[2] + 0x8000000;
    local_44 = param_2[3];
    fVar1 = (float)((int)local_44 + 0x4000000);
    local_40 = param_2[4];
    local_38 = fVar1 * param_2[6];
    local_3c = param_2[5];
    local_34 = fVar1 * param_2[7];
    if (DAT_6001d898 == 1) {
      local_30 = fVar1 * param_2[8];
      local_2c = fVar1 * param_2[9];
    }
    local_28 = *param_3;
    local_24 = param_3[1];
    local_1c = param_3[3];
    local_20 = (int)param_3[2] + 0x8000000;
    fVar1 = (float)((int)local_1c + 0x4000000);
    local_18 = param_3[4];
    local_14 = param_3[5];
    local_10 = fVar1 * param_3[6];
    local_c = fVar1 * param_3[7];
    if (DAT_6001d898 == 1) {
      local_8 = fVar1 * param_3[8];
      local_4 = fVar1 * param_3[9];
    }
    (*DAT_6001ed2c)(&local_78,&local_50,&local_28);
  }
  return;
}



/* VA 600048e0 */

void _THRASH_drawtrimesh_12(int param_1,int param_2,int *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  float local_78;
  float local_74;
  int local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x48e0  18  _THRASH_drawtrimesh@12 */
  iVar5 = DAT_60014514;
  if (0 < param_1) {
    do {
      pfVar1 = (float *)(*param_3 * iVar5 + param_2);
      pfVar2 = (float *)(param_3[1] * iVar5 + param_2);
      pfVar3 = (float *)(param_3[2] * iVar5 + param_2);
      if ((DAT_6001da20 == 1) ||
         (((uint)((*pfVar2 - *pfVar1) * (pfVar3[1] - pfVar1[1]) -
                 (*pfVar3 - *pfVar1) * (pfVar2[1] - pfVar1[1])) & 0x80000000) != DAT_6001da20)) {
        local_78 = *pfVar1;
        local_74 = pfVar1[1];
        local_70 = (int)pfVar1[2] + 0x8000000;
        local_6c = pfVar1[3];
        fVar4 = (float)((int)local_6c + 0x4000000);
        local_68 = pfVar1[4];
        local_60 = fVar4 * pfVar1[6];
        local_64 = pfVar1[5];
        local_5c = fVar4 * pfVar1[7];
        if (DAT_6001d898 == 1) {
          local_58 = fVar4 * pfVar1[8];
          local_54 = fVar4 * pfVar1[9];
        }
        local_50 = *pfVar2;
        local_4c = pfVar2[1];
        local_48 = (int)pfVar2[2] + 0x8000000;
        local_44 = pfVar2[3];
        fVar4 = (float)((int)local_44 + 0x4000000);
        local_40 = pfVar2[4];
        local_38 = fVar4 * pfVar2[6];
        local_3c = pfVar2[5];
        local_34 = fVar4 * pfVar2[7];
        if (DAT_6001d898 == 1) {
          local_30 = fVar4 * pfVar2[8];
          local_2c = fVar4 * pfVar2[9];
        }
        local_28 = *pfVar3;
        local_24 = pfVar3[1];
        local_1c = pfVar3[3];
        local_20 = (int)pfVar3[2] + 0x8000000;
        fVar4 = (float)((int)local_1c + 0x4000000);
        local_18 = pfVar3[4];
        local_14 = pfVar3[5];
        local_10 = fVar4 * pfVar3[6];
        local_c = fVar4 * pfVar3[7];
        if (DAT_6001d898 == 1) {
          local_8 = fVar4 * pfVar3[8];
          local_4 = fVar4 * pfVar3[9];
        }
        (*DAT_6001ed2c)(&local_78,&local_50,&local_28);
        iVar5 = DAT_60014514;
      }
      param_3 = param_3 + 3;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60004b00 */

void _THRASH_drawtristrip_12(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  float local_78;
  float local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x4b00  19  _THRASH_drawtristrip@12 */
  if (0 < param_1) {
    local_78 = *(float *)(*param_3 * DAT_60014514 + param_2);
    iVar1 = *param_3 * DAT_60014514 + param_2;
    local_74 = *(float *)(iVar1 + 4);
    local_70 = *(int *)(iVar1 + 8) + 0x8000000;
    local_6c = *(undefined4 *)(iVar1 + 0xc);
    fVar3 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
    local_68 = *(undefined4 *)(iVar1 + 0x10);
    local_64 = *(undefined4 *)(iVar1 + 0x14);
    local_60 = fVar3 * *(float *)(iVar1 + 0x18);
    local_5c = fVar3 * *(float *)(iVar1 + 0x1c);
    if (DAT_6001d898 == 1) {
      local_58 = fVar3 * *(float *)(iVar1 + 0x20);
      local_54 = fVar3 * *(float *)(iVar1 + 0x24);
    }
    local_50 = *(float *)(param_3[1] * DAT_60014514 + param_2);
    iVar1 = param_3[1] * DAT_60014514 + param_2;
    local_4c = *(float *)(iVar1 + 4);
    local_48 = *(int *)(iVar1 + 8) + 0x8000000;
    local_44 = *(undefined4 *)(iVar1 + 0xc);
    fVar3 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
    local_40 = *(undefined4 *)(iVar1 + 0x10);
    local_3c = *(undefined4 *)(iVar1 + 0x14);
    local_38 = fVar3 * *(float *)(iVar1 + 0x18);
    local_34 = fVar3 * *(float *)(iVar1 + 0x1c);
    if (DAT_6001d898 == 1) {
      local_30 = fVar3 * *(float *)(iVar1 + 0x20);
      local_2c = fVar3 * *(float *)(iVar1 + 0x24);
    }
    piVar6 = param_3 + 3;
    iVar1 = DAT_60014514;
    iVar4 = DAT_6001d898;
    uVar5 = DAT_6001da20;
    do {
      local_28 = *(float *)(piVar6[-1] * iVar1 + param_2);
      iVar2 = piVar6[-1] * iVar1 + param_2;
      local_24 = *(float *)(iVar2 + 4);
      local_20 = *(int *)(iVar2 + 8) + 0x8000000;
      local_1c = *(undefined4 *)(iVar2 + 0xc);
      fVar3 = (float)(*(int *)(iVar2 + 0xc) + 0x4000000);
      local_18 = *(undefined4 *)(iVar2 + 0x10);
      local_14 = *(undefined4 *)(iVar2 + 0x14);
      local_10 = fVar3 * *(float *)(iVar2 + 0x18);
      local_c = fVar3 * *(float *)(iVar2 + 0x1c);
      if (iVar4 == 1) {
        local_8 = fVar3 * *(float *)(iVar2 + 0x20);
        local_4 = fVar3 * *(float *)(iVar2 + 0x24);
      }
      if ((uVar5 == 1) ||
         (((uint)((local_24 - local_74) * (local_50 - local_78) -
                 (local_28 - local_78) * (local_4c - local_74)) & 0x80000000) != uVar5)) {
        (*DAT_6001ed2c)(&local_78,&local_50,&local_28);
        iVar1 = DAT_60014514;
        iVar4 = DAT_6001d898;
        uVar5 = DAT_6001da20;
      }
      if (param_1 < 2) {
        return;
      }
      local_78 = *(float *)(*piVar6 * iVar1 + param_2);
      iVar2 = *piVar6 * iVar1 + param_2;
      local_74 = *(float *)(iVar2 + 4);
      local_70 = *(int *)(iVar2 + 8) + 0x8000000;
      local_6c = *(undefined4 *)(iVar2 + 0xc);
      fVar3 = (float)(*(int *)(iVar2 + 0xc) + 0x4000000);
      local_68 = *(undefined4 *)(iVar2 + 0x10);
      local_64 = *(undefined4 *)(iVar2 + 0x14);
      local_60 = fVar3 * *(float *)(iVar2 + 0x18);
      local_5c = fVar3 * *(float *)(iVar2 + 0x1c);
      if (iVar4 == 1) {
        local_58 = fVar3 * *(float *)(iVar2 + 0x20);
        local_54 = fVar3 * *(float *)(iVar2 + 0x24);
      }
      if ((uVar5 == 1) ||
         (((uint)((local_24 - local_4c) * (local_78 - local_50) -
                 (local_28 - local_50) * (local_74 - local_4c)) & 0x80000000) != uVar5)) {
        (*DAT_6001ed2c)(&local_50,&local_78,&local_28);
        iVar1 = DAT_60014514;
        iVar4 = DAT_6001d898;
        uVar5 = DAT_6001da20;
      }
      if (param_1 < 3) {
        return;
      }
      local_50 = *(float *)(piVar6[1] * iVar1 + param_2);
      iVar2 = piVar6[1] * iVar1 + param_2;
      local_4c = *(float *)(iVar2 + 4);
      local_48 = *(int *)(iVar2 + 8) + 0x8000000;
      local_44 = *(undefined4 *)(iVar2 + 0xc);
      fVar3 = (float)(*(int *)(iVar2 + 0xc) + 0x4000000);
      local_40 = *(undefined4 *)(iVar2 + 0x10);
      local_3c = *(undefined4 *)(iVar2 + 0x14);
      local_38 = fVar3 * *(float *)(iVar2 + 0x18);
      local_34 = fVar3 * *(float *)(iVar2 + 0x1c);
      if (iVar4 == 1) {
        local_30 = fVar3 * *(float *)(iVar2 + 0x20);
        local_2c = fVar3 * *(float *)(iVar2 + 0x24);
      }
      if ((uVar5 == 1) ||
         (((uint)((local_78 - local_28) * (local_4c - local_24) -
                 (local_74 - local_24) * (local_50 - local_28)) & 0x80000000) != uVar5)) {
        (*DAT_6001ed2c)(&local_28,&local_78,&local_50);
        iVar1 = DAT_60014514;
        iVar4 = DAT_6001d898;
        uVar5 = DAT_6001da20;
      }
      if (param_1 < 4) {
        return;
      }
      local_28 = *(float *)(piVar6[2] * iVar1 + param_2);
      iVar2 = piVar6[2] * iVar1 + param_2;
      local_24 = *(float *)(iVar2 + 4);
      local_20 = *(int *)(iVar2 + 8) + 0x8000000;
      local_1c = *(undefined4 *)(iVar2 + 0xc);
      fVar3 = (float)(*(int *)(iVar2 + 0xc) + 0x4000000);
      local_18 = *(undefined4 *)(iVar2 + 0x10);
      local_14 = *(undefined4 *)(iVar2 + 0x14);
      local_10 = fVar3 * *(float *)(iVar2 + 0x18);
      local_c = fVar3 * *(float *)(iVar2 + 0x1c);
      if (iVar4 == 1) {
        local_8 = fVar3 * *(float *)(iVar2 + 0x20);
        local_4 = fVar3 * *(float *)(iVar2 + 0x24);
      }
      if ((uVar5 == 1) ||
         (((uint)((local_28 - local_78) * (local_4c - local_74) -
                 (local_24 - local_74) * (local_50 - local_78)) & 0x80000000) != uVar5)) {
        (*DAT_6001ed2c)(&local_78,&local_28,&local_50);
        iVar1 = DAT_60014514;
        iVar4 = DAT_6001d898;
        uVar5 = DAT_6001da20;
      }
      if (param_1 < 5) {
        return;
      }
      local_78 = *(float *)(piVar6[3] * iVar1 + param_2);
      iVar2 = piVar6[3] * iVar1 + param_2;
      local_74 = *(float *)(iVar2 + 4);
      local_70 = *(int *)(iVar2 + 8) + 0x8000000;
      local_6c = *(undefined4 *)(iVar2 + 0xc);
      fVar3 = (float)(*(int *)(iVar2 + 0xc) + 0x4000000);
      local_68 = *(undefined4 *)(iVar2 + 0x10);
      local_64 = *(undefined4 *)(iVar2 + 0x14);
      local_60 = fVar3 * *(float *)(iVar2 + 0x18);
      local_5c = fVar3 * *(float *)(iVar2 + 0x1c);
      if (iVar4 == 1) {
        local_58 = fVar3 * *(float *)(iVar2 + 0x20);
        local_54 = fVar3 * *(float *)(iVar2 + 0x24);
      }
      if ((uVar5 == 1) ||
         (((uint)((local_28 - local_50) * (local_74 - local_4c) -
                 (local_24 - local_4c) * (local_78 - local_50)) & 0x80000000) != uVar5)) {
        (*DAT_6001ed2c)(&local_50,&local_28,&local_78);
        iVar1 = DAT_60014514;
        iVar4 = DAT_6001d898;
        uVar5 = DAT_6001da20;
      }
      if (param_1 < 6) {
        return;
      }
      local_50 = *(float *)(piVar6[4] * iVar1 + param_2);
      iVar2 = piVar6[4] * iVar1 + param_2;
      local_4c = *(float *)(iVar2 + 4);
      local_48 = *(int *)(iVar2 + 8) + 0x8000000;
      local_44 = *(undefined4 *)(iVar2 + 0xc);
      fVar3 = (float)(*(int *)(iVar2 + 0xc) + 0x4000000);
      local_40 = *(undefined4 *)(iVar2 + 0x10);
      local_3c = *(undefined4 *)(iVar2 + 0x14);
      local_38 = fVar3 * *(float *)(iVar2 + 0x18);
      local_34 = fVar3 * *(float *)(iVar2 + 0x1c);
      if (iVar4 == 1) {
        local_30 = fVar3 * *(float *)(iVar2 + 0x20);
        local_2c = fVar3 * *(float *)(iVar2 + 0x24);
      }
      if ((uVar5 == 1) ||
         (((uint)((local_74 - local_24) * (local_50 - local_28) -
                 (local_78 - local_28) * (local_4c - local_24)) & 0x80000000) != uVar5)) {
        (*DAT_6001ed2c)(&local_28,&local_50,&local_78);
        iVar1 = DAT_60014514;
        iVar4 = DAT_6001d898;
        uVar5 = DAT_6001da20;
      }
      piVar6 = piVar6 + 6;
      param_1 = param_1 + -6;
    } while (0 < param_1);
  }
  return;
}



/* VA 60005210 */

void _THRASH_drawtrifan_12(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  float local_78;
  float local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x5210  16  _THRASH_drawtrifan@12 */
  if (0 < param_1) {
    local_78 = *(float *)(*param_3 * DAT_60014514 + param_2);
    iVar1 = *param_3 * DAT_60014514 + param_2;
    local_74 = *(float *)(iVar1 + 4);
    local_70 = *(int *)(iVar1 + 8) + 0x8000000;
    local_6c = *(undefined4 *)(iVar1 + 0xc);
    fVar3 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
    local_68 = *(undefined4 *)(iVar1 + 0x10);
    local_64 = *(undefined4 *)(iVar1 + 0x14);
    local_60 = fVar3 * *(float *)(iVar1 + 0x18);
    local_5c = fVar3 * *(float *)(iVar1 + 0x1c);
    if (DAT_6001d898 == 1) {
      local_58 = fVar3 * *(float *)(iVar1 + 0x20);
      local_54 = fVar3 * *(float *)(iVar1 + 0x24);
    }
    local_50 = *(float *)(param_3[1] * DAT_60014514 + param_2);
    iVar1 = param_3[1] * DAT_60014514 + param_2;
    local_4c = *(float *)(iVar1 + 4);
    local_48 = *(int *)(iVar1 + 8) + 0x8000000;
    local_44 = *(undefined4 *)(iVar1 + 0xc);
    fVar3 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
    local_40 = *(undefined4 *)(iVar1 + 0x10);
    local_3c = *(undefined4 *)(iVar1 + 0x14);
    local_38 = fVar3 * *(float *)(iVar1 + 0x18);
    local_34 = fVar3 * *(float *)(iVar1 + 0x1c);
    if (DAT_6001d898 == 1) {
      local_30 = fVar3 * *(float *)(iVar1 + 0x20);
      local_2c = fVar3 * *(float *)(iVar1 + 0x24);
    }
    piVar6 = param_3 + 3;
    iVar1 = DAT_60014514;
    iVar4 = DAT_6001d898;
    uVar5 = DAT_6001da20;
    do {
      local_28 = *(float *)(piVar6[-1] * iVar1 + param_2);
      iVar2 = piVar6[-1] * iVar1 + param_2;
      local_24 = *(float *)(iVar2 + 4);
      local_20 = *(int *)(iVar2 + 8) + 0x8000000;
      local_1c = *(undefined4 *)(iVar2 + 0xc);
      fVar3 = (float)(*(int *)(iVar2 + 0xc) + 0x4000000);
      local_18 = *(undefined4 *)(iVar2 + 0x10);
      local_14 = *(undefined4 *)(iVar2 + 0x14);
      local_10 = fVar3 * *(float *)(iVar2 + 0x18);
      local_c = fVar3 * *(float *)(iVar2 + 0x1c);
      if (iVar4 == 1) {
        local_8 = fVar3 * *(float *)(iVar2 + 0x20);
        local_4 = fVar3 * *(float *)(iVar2 + 0x24);
      }
      if ((uVar5 == 1) ||
         (((uint)((local_50 - local_78) * (local_24 - local_74) -
                 (local_28 - local_78) * (local_4c - local_74)) & 0x80000000) != uVar5)) {
        (*DAT_6001ed2c)(&local_78,&local_50,&local_28);
        iVar1 = DAT_60014514;
        iVar4 = DAT_6001d898;
        uVar5 = DAT_6001da20;
      }
      if (param_1 < 2) {
        return;
      }
      local_50 = *(float *)(*piVar6 * iVar1 + param_2);
      iVar2 = *piVar6 * iVar1 + param_2;
      local_4c = *(float *)(iVar2 + 4);
      local_48 = *(int *)(iVar2 + 8) + 0x8000000;
      local_44 = *(undefined4 *)(iVar2 + 0xc);
      fVar3 = (float)(*(int *)(iVar2 + 0xc) + 0x4000000);
      local_40 = *(undefined4 *)(iVar2 + 0x10);
      local_3c = *(undefined4 *)(iVar2 + 0x14);
      local_38 = fVar3 * *(float *)(iVar2 + 0x18);
      local_34 = fVar3 * *(float *)(iVar2 + 0x1c);
      if (iVar4 == 1) {
        local_30 = fVar3 * *(float *)(iVar2 + 0x20);
        local_2c = fVar3 * *(float *)(iVar2 + 0x24);
      }
      if ((uVar5 == 1) ||
         (((uint)((local_28 - local_78) * (local_4c - local_74) -
                 (local_50 - local_78) * (local_24 - local_74)) & 0x80000000) != uVar5)) {
        (*DAT_6001ed2c)(&local_78,&local_28,&local_50);
        iVar1 = DAT_60014514;
        iVar4 = DAT_6001d898;
        uVar5 = DAT_6001da20;
      }
      piVar6 = piVar6 + 2;
      param_1 = param_1 + -2;
    } while (0 < param_1);
  }
  return;
}



/* VA 60005530 */

void _THRASH_drawline_8(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x5530  4  _THRASH_drawline@8 */
  local_28 = *param_2;
  local_24 = param_2[1];
  local_1c = param_2[3];
  local_20 = param_2[2] + 0x8000000;
  fVar1 = (float)(local_1c + 0x4000000);
  local_18 = param_2[4];
  local_14 = param_2[5];
  local_10 = fVar1 * (float)param_2[6];
  local_c = fVar1 * (float)param_2[7];
  if (DAT_6001d898 == 1) {
    local_8 = fVar1 * (float)param_2[8];
    local_4 = fVar1 * (float)param_2[9];
  }
  local_50 = *param_1;
  local_4c = param_1[1];
  local_48 = param_1[2] + 0x8000000;
  local_44 = param_1[3];
  fVar1 = (float)(local_44 + 0x4000000);
  local_40 = param_1[4];
  local_38 = fVar1 * (float)param_1[6];
  local_3c = param_1[5];
  local_34 = fVar1 * (float)param_1[7];
  if (DAT_6001d898 == 1) {
    local_30 = fVar1 * (float)param_1[8];
    local_2c = fVar1 * (float)param_1[9];
  }
  (*DAT_6001ed30)(&local_50,&local_28);
  return;
}



/* VA 60005630 */

void _THRASH_drawlinemesh_12(int param_1,int param_2,int *param_3)

{
  int iVar1;
  float fVar2;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x5630  5  _THRASH_drawlinemesh@12 */
  if (0 < param_1) {
    do {
      local_50 = *(undefined4 *)(*param_3 * DAT_60014514 + param_2);
      iVar1 = *param_3 * DAT_60014514 + param_2;
      local_4c = *(undefined4 *)(iVar1 + 4);
      local_48 = *(int *)(iVar1 + 8) + 0x8000000;
      local_44 = *(undefined4 *)(iVar1 + 0xc);
      fVar2 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
      local_40 = *(undefined4 *)(iVar1 + 0x10);
      local_3c = *(undefined4 *)(iVar1 + 0x14);
      local_38 = fVar2 * *(float *)(iVar1 + 0x18);
      local_34 = fVar2 * *(float *)(iVar1 + 0x1c);
      if (DAT_6001d898 == 1) {
        local_30 = fVar2 * *(float *)(iVar1 + 0x20);
        local_2c = fVar2 * *(float *)(iVar1 + 0x24);
      }
      local_28 = *(undefined4 *)(param_3[1] * DAT_60014514 + param_2);
      iVar1 = param_3[1] * DAT_60014514 + param_2;
      local_24 = *(undefined4 *)(iVar1 + 4);
      local_20 = *(int *)(iVar1 + 8) + 0x8000000;
      local_1c = *(undefined4 *)(iVar1 + 0xc);
      fVar2 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
      local_18 = *(undefined4 *)(iVar1 + 0x10);
      local_14 = *(undefined4 *)(iVar1 + 0x14);
      local_10 = fVar2 * *(float *)(iVar1 + 0x18);
      local_c = fVar2 * *(float *)(iVar1 + 0x1c);
      if (DAT_6001d898 == 1) {
        local_8 = fVar2 * *(float *)(iVar1 + 0x20);
        local_4 = fVar2 * *(float *)(iVar1 + 0x24);
      }
      (*DAT_6001ed30)(&local_50,&local_28);
      param_3 = param_3 + 2;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60005770 */

void _THRASH_drawlinestrip_12(int param_1,int param_2,int *param_3)

{
  int iVar1;
  float fVar2;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x5770  6  _THRASH_drawlinestrip@12 */
  if (0 < param_1) {
    local_50 = *(int *)(*param_3 * DAT_60014514 + param_2);
    iVar1 = *param_3 * DAT_60014514 + param_2;
    local_4c = *(undefined4 *)(iVar1 + 4);
    local_48 = *(int *)(iVar1 + 8) + 0x8000000;
    local_44 = *(undefined4 *)(iVar1 + 0xc);
    fVar2 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
    local_40 = *(float *)(iVar1 + 0x10);
    local_3c = *(float *)(iVar1 + 0x14);
    local_38 = fVar2 * *(float *)(iVar1 + 0x18);
    local_34 = fVar2 * *(float *)(iVar1 + 0x1c);
    if (DAT_6001d898 == 1) {
      local_30 = fVar2 * *(float *)(iVar1 + 0x20);
      local_2c = fVar2 * *(float *)(iVar1 + 0x24);
    }
    do {
      local_28 = *(undefined4 *)(param_3[1] * DAT_60014514 + param_2);
      iVar1 = param_3[1] * DAT_60014514 + param_2;
      local_24 = *(undefined4 *)(iVar1 + 4);
      local_20 = *(int *)(iVar1 + 8) + 0x8000000;
      local_1c = *(undefined4 *)(iVar1 + 0xc);
      local_18 = *(undefined4 *)(iVar1 + 0x10);
      fVar2 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
      local_14 = *(undefined4 *)(iVar1 + 0x14);
      local_10 = fVar2 * *(float *)(iVar1 + 0x18);
      local_c = fVar2 * *(float *)(iVar1 + 0x1c);
      if (DAT_6001d898 == 1) {
        local_8 = fVar2 * *(float *)(iVar1 + 0x20);
        local_4 = fVar2 * *(float *)(iVar1 + 0x24);
      }
      (*DAT_6001ed30)(&local_50,&local_28);
      if (param_1 < 2) {
        return;
      }
      iVar1 = param_3[2] * DAT_60014514 + param_2;
      local_50 = *(int *)(iVar1 + 8) + 0x8000000;
      local_4c = *(undefined4 *)(iVar1 + 0xc);
      local_48 = *(int *)(iVar1 + 0x10);
      fVar2 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
      local_44 = *(undefined4 *)(iVar1 + 0x14);
      local_40 = fVar2 * *(float *)(iVar1 + 0x18);
      local_3c = fVar2 * *(float *)(iVar1 + 0x1c);
      if (DAT_6001d898 == 1) {
        local_38 = fVar2 * *(float *)(iVar1 + 0x20);
        local_34 = fVar2 * *(float *)(iVar1 + 0x24);
      }
      (*DAT_6001ed30)(&local_30,&stack0xffffffa8);
      param_1 = param_1 + -2;
      param_3 = param_3 + 2;
    } while (0 < param_1);
  }
  return;
}



/* VA 60005950 */

void _THRASH_drawpoint_4(undefined4 *param_1)

{
  float fVar1;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x5950  8  _THRASH_drawpoint@4 */
  local_28 = *param_1;
  local_24 = param_1[1];
  local_1c = param_1[3];
  local_20 = param_1[2] + 0x8000000;
  fVar1 = (float)(local_1c + 0x4000000);
  local_18 = param_1[4];
  local_14 = param_1[5];
  local_10 = fVar1 * (float)param_1[6];
  local_c = fVar1 * (float)param_1[7];
  if (DAT_6001d898 == 1) {
    local_8 = fVar1 * (float)param_1[8];
    local_4 = fVar1 * (float)param_1[9];
  }
  (*DAT_6001f1c0)(&local_28);
  return;
}



/* VA 600059e0 */

void _THRASH_drawpointmesh_12(int param_1,int param_2,int *param_3)

{
  int iVar1;
  float fVar2;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

                    /* 0x59e0  9  _THRASH_drawpointmesh@12 */
  if (0 < param_1) {
    do {
      local_28 = *(undefined4 *)(*param_3 * DAT_60014514 + param_2);
      iVar1 = *param_3 * DAT_60014514 + param_2;
      local_24 = *(undefined4 *)(iVar1 + 4);
      local_20 = *(int *)(iVar1 + 8) + 0x8000000;
      local_1c = *(undefined4 *)(iVar1 + 0xc);
      local_18 = *(undefined4 *)(iVar1 + 0x10);
      fVar2 = (float)(*(int *)(iVar1 + 0xc) + 0x4000000);
      local_14 = *(undefined4 *)(iVar1 + 0x14);
      local_10 = fVar2 * *(float *)(iVar1 + 0x18);
      local_c = fVar2 * *(float *)(iVar1 + 0x1c);
      if (DAT_6001d898 == 1) {
        local_8 = fVar2 * *(float *)(iVar1 + 0x20);
        local_4 = fVar2 * *(float *)(iVar1 + 0x24);
      }
      (*DAT_6001f1c0)(&local_28);
      param_3 = param_3 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60005aa0 */

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
                    /* 0x5aa0  13  _THRASH_drawsprite@8 */
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



/* VA 60005b00 */

void _THRASH_drawspritemesh_12(int param_1,int param_2,int *param_3)

{
                    /* 0x5b00  14  _THRASH_drawspritemesh@12 */
  if (0 < param_1) {
    do {
      _THRASH_drawsprite_8
                ((float *)(*param_3 * DAT_60014514 + param_2),
                 (float *)(param_3[1] * DAT_60014514 + param_2));
      param_3 = param_3 + 2;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60005b40 */

void _THRASH_drawtristrip_8(int param_1,float *param_2)

{
  float *pfVar1;

                    /* 0x5b40  20  _THRASH_drawtristrip@8 */
  if (0 < param_1) {
    _THRASH_drawtri_12(param_2,param_2 + 8,param_2 + 0x10);
    pfVar1 = param_2 + 0x10;
    while (1 < param_1) {
      _THRASH_drawtri_12(pfVar1 + -8,pfVar1 + 8,pfVar1);
      param_1 = param_1 + -2;
      param_2 = param_2 + 0x10;
      if (param_1 < 1) {
        return;
      }
      _THRASH_drawtri_12(param_2,pfVar1 + 8,pfVar1 + 0x10);
      pfVar1 = pfVar1 + 0x10;
    }
  }
  return;
}



/* VA 60005ba0 */

void _THRASH_drawtrifan_8(int param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;

  if (0 < param_1) {
    pfVar1 = param_2 + 0x10;
    pfVar2 = param_2;
    do {
      pfVar2 = pfVar2 + 8;
      _THRASH_drawtri_12(param_2,pfVar2,pfVar1);
      pfVar1 = pfVar1 + 8;
      param_1 = param_1 + -1;
    } while (0 < param_1);
  }
  return;
}



/* VA 60005be0 */

void _THRASH_drawlinestrip_8(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;

  puVar1 = param_2;
  for (; 0 < param_1; param_1 = param_1 + -1) {
    puVar1 = puVar1 + 8;
    _THRASH_drawline_8(param_2,puVar1);
    param_2 = param_2 + 8;
  }
  return;
}



/* VA 60005c10 */

void _THRASH_drawpointstrip_8(int param_1,undefined4 *param_2)

{
                    /* 0x5c10  10  _THRASH_drawpointstrip@8 */
  if (0 < param_1) {
    do {
      _THRASH_drawpoint_4(param_2);
      param_2 = param_2 + 8;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* VA 60005c30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _THRASH_getstate_4(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;

                    /* 0x5c30  22  _THRASH_getstate@4 */
  uVar1 = DAT_600144d0 & param_1;
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
  iVar2 = FUN_60005cd0(param_1 & _DAT_600144d4);
  if (-1 < iVar2) {
    iVar2 = *(int *)(&DAT_6001de20 + (iVar3 + iVar2 * 8) * 4);
  }
  return iVar2;
}



/* VA 60005cd0 */

int __cdecl FUN_60005cd0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;

  iVar4 = 0;
  iVar5 = 0;
  piVar3 = &DAT_600144d8;
  while ((iVar2 = *piVar3, param_1 < iVar2 || (piVar3[1] < param_1))) {
    piVar1 = piVar3 + 1;
    piVar3 = piVar3 + 2;
    iVar4 = iVar4 + (*piVar1 - iVar2);
    iVar5 = iVar5 + 1;
    if ((int *)0x60014507 < piVar3) {
      return -1;
    }
  }
  return (iVar4 - (&DAT_600144d8)[iVar5 * 2]) + param_1;
}



/* VA 60005d20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_60005d20(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;

  uVar1 = DAT_600144d0 & param_1;
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
  uVar1 = param_1 & _DAT_600144d4;
  iVar2 = FUN_60005cd0(uVar1);
  if (-1 < iVar2) {
    *(undefined4 *)(&DAT_6001de20 + (iVar3 + iVar2 * 8) * 4) = param_2;
  }
  if (DAT_6001da14 != (code *)0x0) {
    (*DAT_6001da14)(uVar1,param_2);
  }
  return;
}



/* VA 60005dd0 */

void FUN_60005dd0(void)

{
  FUN_60006a80((undefined8 *)&DAT_6001de20,0,0xf00);
  return;
}



/* VA 60005df0 */

void FUN_60005df0(int param_1,LPCSTR param_2)

{
  FUN_600073f2(&DAT_6001270c);
  if (param_1 == 0) {
    MessageBoxA((HWND)0x0,param_2,"Abort Message",0x11011);
    FUN_600072f0(10);
  }
  return;
}



/* VA 60005e30 */

undefined4 __cdecl FUN_60005e30(undefined4 param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  uchar local_50 [80];

  FUN_60007248(local_50,(byte *)"%s_%s");
  pbVar1 = (byte *)FUN_60007076(local_50);
  this = extraout_ECX;
  if (pbVar1 == (byte *)0x0) {
    FUN_60007248(local_50,(byte *)"THRASH_%s");
    pbVar1 = (byte *)FUN_60007076(local_50);
    this = extraout_ECX_00;
    if (pbVar1 == (byte *)0x0) {
      return param_1;
    }
  }
  uVar2 = FUN_6000706b(this,pbVar1);
  return uVar2;
}



/* VA 60005ea0 */

void __cdecl FUN_60005ea0(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;

  uVar1 = FUN_60005e30(*param_1);
  *param_1 = uVar1;
  uVar1 = FUN_60005e30(param_1[2]);
  param_1[2] = uVar1;
  uVar2 = FUN_60005e30(param_1[3] & 1);
  uVar3 = param_1[3];
  uVar9 = (uVar3 ^ uVar2) & 1 ^ uVar3;
  param_1[3] = uVar9;
  uVar3 = FUN_60005e30(uVar3 >> 1 & 1);
  uVar3 = (uVar3 & 1) << 1;
  param_1[3] = uVar3 | uVar9 & 0xfffffffd;
  uVar2 = FUN_60005e30((uVar9 & 4) >> 2);
  uVar2 = (uVar2 & 1) << 2;
  param_1[3] = uVar2 | uVar3 | uVar9 & 0xfffffff9;
  uVar4 = FUN_60005e30((uVar9 & 8) >> 3);
  uVar4 = (uVar4 & 1) << 3;
  param_1[3] = uVar4 | uVar2 | uVar3 | uVar9 & 0xfffffff1;
  uVar5 = FUN_60005e30((uVar9 & 0x10) >> 4);
  uVar5 = (uVar5 & 1) << 4;
  param_1[3] = uVar5 | uVar4 | uVar2 | uVar3 | uVar9 & 0xffffffe1;
  uVar6 = FUN_60005e30((uVar9 & 0x20) >> 5);
  uVar6 = (uVar6 & 1) << 5;
  param_1[3] = uVar6 | uVar5 | uVar4 | uVar2 | uVar3 | uVar9 & 0xffffffc1;
  uVar7 = FUN_60005e30((uVar9 & 0x40) >> 6);
  uVar7 = (uVar7 & 1) << 6;
  param_1[3] = uVar7 | uVar6 | uVar5 | uVar4 | uVar2 | uVar3 | uVar9 & 0xffffff81;
  uVar8 = FUN_60005e30((uVar9 & 0x80) >> 7);
  param_1[3] = (uVar8 & 1) << 7 | uVar7 | uVar6 | uVar5 | uVar4 | uVar2 | uVar3 | uVar9 & 0xffffff01
  ;
  uVar1 = FUN_60005e30(param_1[4]);
  param_1[4] = uVar1;
  uVar1 = FUN_60005e30(param_1[5]);
  param_1[5] = uVar1;
  uVar1 = FUN_60005e30(param_1[6]);
  param_1[6] = uVar1;
  uVar1 = FUN_60005e30(param_1[7]);
  param_1[7] = uVar1;
  uVar1 = FUN_60005e30(param_1[8]);
  param_1[8] = uVar1;
  uVar1 = FUN_60005e30(param_1[9]);
  param_1[9] = uVar1;
  uVar1 = FUN_60005e30(param_1[10]);
  param_1[10] = uVar1;
  uVar1 = FUN_60005e30(param_1[0x11]);
  param_1[0x11] = uVar1;
  uVar1 = FUN_60005e30(param_1[0x1b]);
  param_1[0x1b] = uVar1;
  uVar1 = FUN_60005e30(param_1[0x1c]);
  param_1[0x1c] = uVar1;
  uVar1 = FUN_60005e30(param_1[0x1d]);
  param_1[0x1d] = uVar1;
  uVar1 = FUN_60005e30(param_1[0x1f]);
  param_1[0x1f] = uVar1;
  return;
}



/* VA 600060d0 */

void FUN_600060d0(size_t param_1)

{
  if (DAT_6001da18 != (code *)0x0) {
    (*DAT_6001da18)(param_1);
    return;
  }
  _malloc(param_1);
  return;
}



/* VA 60006100 */

undefined4 FUN_60006100(LPVOID param_1)

{
  undefined4 uVar1;

  if (DAT_6001da1c != (code *)0x0) {
    uVar1 = (*DAT_6001da1c)(param_1);
    return uVar1;
  }
  FUN_600074bf(param_1);
  return 1;
}



/* VA 60006130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60006130(uint param_1,undefined *param_2)

{
  switch(param_1) {
  case 2:
    if (param_2 == (undefined *)0x0) {
      DAT_6001da20 = 1;
      FUN_60005d20(param_1,0);
      return 1;
    }
    if (param_2 == (undefined *)0x2) {
      DAT_6001da20 = 0;
      FUN_60005d20(param_1,2);
      return 1;
    }
    if (param_2 == (undefined *)0x1) {
      DAT_6001da20 = 0x80000000;
      FUN_60005d20(param_1,1);
      return 1;
    }
  default:
    return 0;
  case 0x12:
    DAT_6001da10 = param_2;
    break;
  case 0x13:
    if (param_2 == (undefined *)0x0) {
      DAT_6001da04 = 0;
      DAT_6001da0c = (undefined *)0x0;
      PTR_FUN_60014508 = (undefined *)0x0;
      DAT_6001da08 = (undefined *)0x0;
    }
    else {
      DAT_6001da04 = *(undefined4 *)(param_2 + 4);
      DAT_6001da0c = *(undefined **)(param_2 + 8);
      PTR_FUN_60014508 = *(undefined **)(param_2 + 0x18);
      DAT_6001da08 = *(undefined **)(param_2 + 0x14);
    }
    break;
  case 0x19:
    DAT_6001d9f4 = param_2;
    break;
  case 0x1a:
    PTR_FUN_60014508 = param_2;
    break;
  case 0x1b:
    DAT_6001da0c = param_2;
    break;
  case 0x1c:
    DAT_6001da08 = param_2;
    break;
  case 0x1e:
    DAT_60014514 = param_2;
    break;
  case 0x1f:
    if (((int)param_2 < 0x68) || (DAT_60014510 = param_2, 0x6b < (int)param_2)) {
      DAT_60014510 = (undefined *)0x6b;
    }
    break;
  case 0x20:
    DAT_6001da18 = param_2;
    break;
  case 0x21:
    DAT_6001da1c = param_2;
    break;
  case 0x27:
    DAT_6001da14 = param_2;
    break;
  case 0x37:
    DAT_6001d9f8 = param_2;
    break;
  case 0x3a:
    _DAT_6001da00 = param_2;
    break;
  case 0x3b:
    break;
  case 0x3d:
    _DAT_6001da24 = param_2;
    break;
  case 0x3e:
    DAT_6001d9fc = param_2;
  }
  FUN_60005d20(param_1,param_2);
  return 1;
}



/* VA 60006330 */

void __cdecl FUN_60006330(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  FUN_600066d0();
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0x130,puVar1);
  _THRASH_setstate_8(1,(undefined4 *)0x0);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(2,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(7,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(6,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(2);
  _THRASH_setstate_8(10,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0x10);
  _THRASH_setstate_8(0x24,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(0xb,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(3,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0xc,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(5,puVar1);
  _THRASH_setstate_8(0x14,(undefined4 *)0x0);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0x15,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0xe,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0x16,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0x3f800000);
  _THRASH_setstate_8(0x17,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0xffffffff);
  _THRASH_setstate_8(0xf,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0x38,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0xd,puVar1);
  _THRASH_setstate_8(0x2e,(undefined4 *)0x3f800000);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0x18,puVar1);
  _THRASH_setstate_8(8,(undefined4 *)0x0);
  puVar1 = (undefined4 *)FUN_60005e30(param_2 - 2U & ((int)(param_2 - 2U) < 0) - 1);
  _THRASH_setstate_8(0x6d,puVar1);
  _THRASH_setstate_8(0x2a,(undefined4 *)0x0);
  _THRASH_setstate_8(0x29,(undefined4 *)0x0);
  _THRASH_setstate_8(0x10029,(undefined4 *)0x0);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(0x2b,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(0x11,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(0x10,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0x2f,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(param_1);
  _THRASH_setstate_8(0x3a,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0x131,puVar1);
  _THRASH_setstate_8(0x3b,(undefined4 *)0x0);
  _THRASH_setstate_8(0x43,(undefined4 *)0x3f800000);
  puVar1 = (undefined4 *)FUN_60005e30(1);
  _THRASH_setstate_8(0x3c,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30(0);
  _THRASH_setstate_8(0x3d,puVar1);
  puVar1 = (undefined4 *)FUN_60005e30((param_3 < 1) - 1 & 2);
  puVar2 = _THRASH_setstate_8(4,puVar1);
  if ((puVar2 == (undefined4 *)0x0) && (puVar1 == (undefined4 *)0x2)) {
    _THRASH_setstate_8(4,(undefined4 *)0x1);
  }
  puVar1 = (undefined4 *)FUN_60005e30(3);
  _THRASH_setstate_8(0x28,puVar1);
  return;
}



/* VA 600066d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_600066d0(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 extraout_ECX;
  void *this;
  void *this_00;
  void *this_01;
  undefined4 extraout_EDX;
  char *pcVar5;
  bool bVar6;
  undefined8 uVar7;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  _OSVERSIONINFOA local_94;

  _DAT_6001de0c = 0;
  _DAT_6001ddc8 = 0;
  _DAT_6001ddd8 = 0;
  _DAT_6001de10 = 0;
  _DAT_6001de08 = 0;
  DAT_6001de04 = 0;
  _DAT_6001ddc0 = 0;
  DAT_6001ddc4 = 0;
  DAT_6001ddec = 0;
  DAT_6001ddd4 = 0;
  _DAT_6001ddbc = 0;
  _DAT_6001ddcc = 0;
  _DAT_6001ddf0 = _DAT_6001ddf0 & 0xffffff00;
  uVar2 = FUN_60006ad0();
  if (uVar2 == 0) {
    uVar7 = FUN_60006b0f(extraout_ECX,extraout_EDX);
    _DAT_6001ddbc = (undefined4)uVar7;
  }
  else {
    local_98 = 0;
    FUN_60006aed(&local_a8,0);
    uVar2 = local_a8;
    _DAT_6001ddf0 = local_a4;
    _DAT_6001ddf4 = local_a0;
    _DAT_6001ddf8 = local_9c;
    DAT_6001ddfc = 0;
    if (0 < (int)local_a8) {
      pcVar5 = "GenuineIntel";
      pbVar3 = &DAT_6001ddf0;
      do {
        bVar1 = *pbVar3;
        bVar6 = bVar1 < (byte)*pcVar5;
        if (bVar1 != *pcVar5) {
LAB_600067a9:
          iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_600067ae;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar6 = bVar1 < (byte)pcVar5[1];
        if (bVar1 != pcVar5[1]) goto LAB_600067a9;
        pbVar3 = pbVar3 + 2;
        pcVar5 = pcVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_600067ae:
      if (iVar4 == 0) {
        _DAT_6001ddcc = 1;
      }
      else {
        pcVar5 = "AuthenticAMD";
        pbVar3 = &DAT_6001ddf0;
        do {
          bVar1 = *pbVar3;
          bVar6 = bVar1 < (byte)*pcVar5;
          if (bVar1 != *pcVar5) {
LAB_600067f0:
            iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_600067f5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar6 = bVar1 < (byte)pcVar5[1];
          if (bVar1 != pcVar5[1]) goto LAB_600067f0;
          pbVar3 = pbVar3 + 2;
          pcVar5 = pcVar5 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_600067f5:
        if (iVar4 == 0) {
          DAT_6001ddd4 = 1;
        }
        else {
          pcVar5 = "CyrixInstead";
          pbVar3 = &DAT_6001ddf0;
          do {
            bVar1 = *pbVar3;
            bVar6 = bVar1 < (byte)*pcVar5;
            if (bVar1 != *pcVar5) {
LAB_6000682f:
              iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
              goto LAB_60006834;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar6 = bVar1 < (byte)pcVar5[1];
            if (bVar1 != pcVar5[1]) goto LAB_6000682f;
            pbVar3 = pbVar3 + 2;
            pcVar5 = pcVar5 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
LAB_60006834:
          if (iVar4 == 0) {
            _DAT_6001ddbc = 1;
          }
          else {
            pcVar5 = "CentaurHauls";
            pbVar3 = &DAT_6001ddf0;
            do {
              bVar1 = *pbVar3;
              bVar6 = bVar1 < (byte)*pcVar5;
              if (bVar1 != *pcVar5) {
LAB_6000686e:
                iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
                goto LAB_60006873;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar3[1];
              bVar6 = bVar1 < (byte)pcVar5[1];
              if (bVar1 != pcVar5[1]) goto LAB_6000686e;
              pbVar3 = pbVar3 + 2;
              pcVar5 = pcVar5 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_60006873:
            if (iVar4 == 0) {
              DAT_6001ddec = 1;
            }
          }
        }
      }
      FUN_60006aed(&local_a8,1);
      _DAT_6001ddd8 = (int)local_a8 >> 8 & 0xf;
      _DAT_6001ddc8 = (int)local_a8 >> 4 & 0xf;
      _DAT_6001de0c = local_a8 & 0xf;
      if (4 < _DAT_6001ddd8) {
        DAT_6001ddc4 = 1;
      }
      if (5 < _DAT_6001ddd8) {
        _DAT_6001ddc0 = 1;
      }
      if (((DAT_6001ddd4 != 0) || (DAT_6001ddec != 0)) && (DAT_6001ddc4 != 0)) {
        FUN_60006aed(&local_a8,-0x7fffffff);
      }
      DAT_6001de00 = local_a0 >> 0x19 & 1;
      _DAT_6001ddd0 = local_a0 >> 0x1f;
      DAT_6001de04 = local_a0 >> 0x17 & 1;
      _DAT_6001de08 = local_a0 >> 4 & 1;
      _DAT_6001de10 = local_a0 >> 0xf & 1;
      pbVar3 = (byte *)FUN_60007076((uchar *)"ISMMX");
      if (pbVar3 != (byte *)0x0) {
        DAT_6001de04 = FUN_6000706b(this,pbVar3);
      }
      pbVar3 = (byte *)FUN_60007076((uchar *)"ISK3D");
      if (pbVar3 != (byte *)0x0) {
        _DAT_6001ddd0 = FUN_6000706b(this_00,pbVar3);
      }
      local_94.dwOSVersionInfoSize = 0x94;
      GetVersionExA(&local_94);
      if ((local_94.dwPlatformId == 1) && (local_94.dwMinorVersion == 0)) {
        DAT_6001de00 = 0;
      }
      pbVar3 = (byte *)FUN_60007076((uchar *)"ISKNI");
      if (pbVar3 != (byte *)0x0) {
        DAT_6001de00 = FUN_6000706b(this_01,pbVar3);
      }
      if (1 < (int)uVar2) {
        FUN_60006aed(&local_a8,2);
      }
      if (2 < (int)uVar2) {
        FUN_60006aed(&local_a8,3);
        _DAT_6001dde0 = local_9c;
        _DAT_6001dde4 = local_a0;
        _DAT_6001dde8 = local_a4;
        return;
      }
    }
  }
  return;
}



/* VA 60006a20 */

void FUN_60006a20(void)

{
  FUN_60006130(0x37,(undefined *)(DAT_6001d9f8 + 1));
  _THRASH_setstate_8(1,(undefined4 *)0x0);
  return;
}



/* VA 60006a40 */

undefined4 FUN_60006a40(void)

{
  uint local_200 [128];

  FUN_60007248((undefined1 *)local_200,(byte *)"%s=%s");
  FUN_60007507(local_200);
  return 0;
}



/* VA 60006a80 */

void __cdecl FUN_60006a80(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  if (DAT_6001de00 != 0) {
    FUN_60011180(param_1,param_2,param_3);
    return;
  }
  if (DAT_6001de04 != 0) {
    FUN_600110c0(param_1,param_2,param_3);
    return;
  }
  FUN_60011000((undefined4 *)param_1,param_2,param_3);
  return;
}



/* VA 60006ad0 */

uint FUN_60006ad0(void)

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



/* VA 60006aed */

void __cdecl FUN_60006aed(undefined4 *param_1,int param_2)

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



/* VA 60006b0f */

undefined8 __fastcall FUN_60006b0f(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,1);
}



/* VA 60006b40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60006b40(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;

  if (param_2 == 1) {
    DAT_6001da58 = GetVersion();
    iVar1 = FUN_60007d90(1);
    if (iVar1 != 0) {
      _DAT_6001da64 = DAT_6001da58 >> 8 & 0xff;
      _DAT_6001da60 = DAT_6001da58 & 0xff;
      DAT_6001da58 = DAT_6001da58 >> 0x10;
      _DAT_6001da5c = _DAT_6001da60 * 0x100 + _DAT_6001da64;
      iVar1 = FUN_600075bc();
      if (iVar1 != 0) {
        DAT_600205b4 = GetCommandLineA();
        DAT_6001da3c = FUN_60007c5e();
        FUN_60007748();
        FUN_60007a11();
        FUN_60007958();
        FUN_600072c3();
        DAT_6001da38 = DAT_6001da38 + 1;
        goto LAB_60006c13;
      }
      FUN_60007dcc();
    }
LAB_60006ba0:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_6001da38 < 1) goto LAB_60006ba0;
      DAT_6001da38 = DAT_6001da38 + -1;
      if (DAT_6001da90 == 0) {
        FUN_60007312();
      }
      FUN_60007904();
      FUN_60007610();
      FUN_60007dcc();
    }
    else if (param_2 == 3) {
      FUN_600076a8((LPVOID)0x0);
    }
LAB_60006c13:
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 60006c19 */

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = param_2;
  iVar2 = DAT_6001da38;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_60006c61;
    if ((DAT_600205b8 != (code *)0x0) &&
       (iVar2 = (*DAT_600205b8)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_60006b40(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_60006c61:
  iVar2 = FUN_60010388(param_1);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_60006b40(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_60006b40(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_600205b8 != (code *)0x0) {
      iVar2 = (*DAT_600205b8)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}



/* VA 60006cb6 */

/* Library Function - Single Match
    __amsg_exit

   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_6001da44 == 1) || ((DAT_6001da44 == 0 && (DAT_6001da48 == 1)))) {
    FUN_60007e47();
  }
  FUN_60007e80(param_1);
  (*(code *)PTR___exit_6001c5a0)(0xff);
  return;
}



/* VA 60006ce9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60006ce9(void)

{
  void *extraout_ECX;

  FUN_60006d01();
  _DAT_6001da50 = FUN_60008023();
  FUN_60007fd3(extraout_ECX);
  return;
}



/* VA 60006d01 */

void FUN_60006d01(void)

{
  PTR___fptrap_6001c8ac = &LAB_600080a6;
  PTR___fptrap_6001c8a8 = __cfltcvt;
  PTR___fptrap_6001c8b0 = __fassign;
  PTR___fptrap_6001c8b4 = FUN_6000804c;
  PTR___fptrap_6001c8b8 = &LAB_600080f4;
  PTR___fptrap_6001c8bc = __cfltcvt;
  return;
}



/* VA 60006d40 */

void FUN_60006d40(void)

{
  float10 in_ST0;
  float10 in_ST1;

  FUN_60006d62(SUB84((double)in_ST1,0),(uint)((ulonglong)(double)in_ST1 >> 0x20),
               SUB84((double)in_ST0,0),(uint)((ulonglong)(double)in_ST0 >> 0x20));
  return;
}



/* VA 60006f35 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60006f35(void)

{
  float10 in_ST0;

  if (ROUND(in_ST0) == in_ST0) {
    return;
  }
  return;
}



/* VA 60006f60 */

uint * __cdecl FUN_60006f60(uint *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint *puVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint *puVar10;

  cVar3 = *param_2;
  if (cVar3 == '\0') {
    return param_1;
  }
  if (param_2[1] == '\0') {
    while (((uint)param_1 & 3) != 0) {
      uVar5 = *param_1;
      if ((char)uVar5 == cVar3) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if ((char)uVar5 == '\0') {
        return (uint *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar5 = *param_1;
        uVar9 = uVar5 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar7 = uVar5 ^ 0xffffffff ^ uVar5 + 0x7efefeff;
        puVar10 = param_1 + 1;
        if (((uVar9 ^ 0xffffffff ^ uVar9 + 0x7efefeff) & 0x81010100) != 0) break;
        param_1 = puVar10;
        if ((uVar7 & 0x81010100) != 0) {
          if ((uVar7 & 0x1010100) != 0) {
            return (uint *)0x0;
          }
          if ((uVar5 + 0x7efefeff & 0x80000000) == 0) {
            return (uint *)0x0;
          }
        }
      }
      uVar5 = *param_1;
      if ((char)uVar5 == cVar3) {
        return param_1;
      }
      if ((char)uVar5 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar5 >> 8);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 1);
      }
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
      cVar6 = (char)(uVar5 >> 0x10);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 2);
      }
      if (cVar6 == '\0') break;
      cVar6 = (char)(uVar5 >> 0x18);
      if (cVar6 == cVar3) {
        return (uint *)((int)param_1 + 3);
      }
      param_1 = puVar10;
      if (cVar6 == '\0') {
        return (uint *)0x0;
      }
    }
    return (uint *)0x0;
  }
  do {
    cVar6 = (char)*param_1;
    do {
      while (puVar10 = param_1, param_1 = (uint *)((int)puVar10 + 1), cVar6 != cVar3) {
        if (cVar6 == '\0') {
          return (uint *)0x0;
        }
        cVar6 = *(char *)param_1;
      }
      cVar6 = *(char *)param_1;
      pcVar8 = param_2;
      puVar4 = puVar10;
    } while (cVar6 != param_2[1]);
    do {
      if (pcVar8[2] == '\0') {
        return puVar10;
      }
      if (*(char *)((int)puVar4 + 2) != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') {
        return puVar10;
      }
      pcVar2 = (char *)((int)puVar4 + 3);
      pcVar8 = pcVar8 + 2;
      puVar4 = (uint *)((int)puVar4 + 2);
    } while (*pcVar1 == *pcVar2);
  } while( true );
}



/* VA 60006fe0 */

int __thiscall FUN_60006fe0(void *this,byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;

  while( true ) {
    if (DAT_6001c7dc < 2) {
      uVar1 = (byte)PTR_DAT_6001c5d0[(uint)*param_1 * 2] & 8;
      this = PTR_DAT_6001c5d0;
    }
    else {
      puVar6 = (undefined *)0x8;
      uVar1 = FUN_60007114(this,(uint)*param_1,8);
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
    if (DAT_6001c7dc < 2) {
      uVar2 = (byte)PTR_DAT_6001c5d0[uVar4 * 2] & 4;
    }
    else {
      puVar6 = (undefined *)0x4;
      uVar2 = FUN_60007114(this,uVar4,4);
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



/* VA 6000706b */

void __thiscall FUN_6000706b(void *this,byte *param_1)

{
  FUN_60006fe0(this,param_1);
  return;
}



/* VA 60007076 */

int __cdecl FUN_60007076(uchar *param_1)

{
  int iVar1;

  FUN_60008d89(0xc);
  iVar1 = FUN_60007097(param_1);
  FUN_60008dea(0xc);
  return iVar1;
}



/* VA 60007097 */

int __cdecl FUN_60007097(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;

  if (((DAT_600205a4 != 0) &&
      ((DAT_6001da74 != (int *)0x0 ||
       (((DAT_6001da7c != 0 && (iVar1 = FUN_60008ebb(), iVar1 == 0)) && (DAT_6001da74 != (int *)0x0)
        ))))) && (piVar3 = DAT_6001da74, param_1 != (uchar *)0x0)) {
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



/* VA 60007114 */

uint __thiscall FUN_60007114(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;

  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_6001c5d0 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_6001c5d0[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_60008f29(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}



/* VA 60007189 */

int __cdecl FUN_60007189(int param_1)

{
  SIZE_T SVar1;
  int *piVar2;

  FUN_600073c6();
  SVar1 = FUN_600091aa(DAT_600205b0);
  if (SVar1 < (uint)((int)DAT_600205ac + (4 - (int)DAT_600205b0))) {
    SVar1 = FUN_600091aa(DAT_600205b0);
    piVar2 = FUN_60009072(DAT_600205b0,(uint *)(SVar1 + 0x10));
    if (piVar2 == (int *)0x0) {
      param_1 = 0;
      goto LAB_600071fe;
    }
    DAT_600205ac = piVar2 + ((int)DAT_600205ac - (int)DAT_600205b0 >> 2);
    DAT_600205b0 = piVar2;
  }
  *DAT_600205ac = param_1;
  DAT_600205ac = DAT_600205ac + 1;
LAB_600071fe:
  FUN_600073cf();
  return param_1;
}



/* VA 60007207 */

int __cdecl FUN_60007207(int param_1)

{
  int iVar1;

  iVar1 = FUN_60007189(param_1);
  return (iVar1 != 0) - 1;
}



/* VA 60007248 */

int __cdecl FUN_60007248(undefined1 *param_1,byte *param_2)

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
  iVar1 = FUN_60009307((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_600091ef(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}



/* VA 6000729c */

/* Library Function - Single Match
    __ftol

   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;

  return (longlong)ROUND(in_ST0);
}



/* VA 600072c3 */

void FUN_600072c3(void)

{
  if (PTR_FUN_6001c5ac != (undefined *)0x0) {
    (*(code *)PTR_FUN_6001c5ac)();
  }
  FUN_600073d8((undefined4 *)&DAT_60014008,(undefined4 *)&DAT_60014018);
  FUN_600073d8((undefined4 *)&DAT_60014000,(undefined4 *)&DAT_60014004);
  return;
}



/* VA 600072f0 */

void __cdecl FUN_600072f0(UINT param_1)

{
  FUN_60007321(param_1,0,0);
  return;
}



/* VA 60007301 */

/* Library Function - Single Match
    __exit

   Library: Visual Studio 2003 Release */

void __cdecl __exit(int _Code)

{
  FUN_60007321(_Code,1,0);
  return;
}



/* VA 60007312 */

void FUN_60007312(void)

{
  FUN_60007321(0,0,1);
  return;
}



/* VA 60007321 */

void __cdecl FUN_60007321(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;

  FUN_600073c6();
  if (DAT_6001da94 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_6001da90 = 1;
  DAT_6001da8c = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_600205b0 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_600205ac - 4), DAT_600205b0 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_600205b0 <= puVar1);
    }
    FUN_600073d8((undefined4 *)&DAT_6001401c,(undefined4 *)&DAT_60014024);
  }
  FUN_600073d8((undefined4 *)&DAT_60014028,(undefined4 *)&DAT_6001402c);
  if (param_3 == 0) {
    DAT_6001da94 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_600073cf();
  return;
}



/* VA 600073c6 */

void FUN_600073c6(void)

{
  FUN_60008d89(0xd);
  return;
}



/* VA 600073cf */

void FUN_600073cf(void)

{
  FUN_60008dea(0xd);
  return;
}



/* VA 600073d8 */

void __cdecl FUN_600073d8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* VA 600073f2 */

int __cdecl FUN_600073f2(byte *param_1)

{
  int iVar1;
  int iVar2;

  FUN_60009bfc(1,0x6001ca38);
  iVar1 = FUN_60009c71((undefined4 *)&DAT_6001ca38);
  iVar2 = FUN_60009307((int *)&DAT_6001ca38,param_1,(undefined4 *)&stack0x00000008);
  FUN_60009cfe(iVar1,(int *)&DAT_6001ca38);
  FUN_60009c4e(1,0x6001ca38);
  return iVar2;
}



/* VA 60007433 */

/* Library Function - Single Match
    _malloc

   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;

  pvVar1 = __nh_malloc(_Size,DAT_6001dc18);
  return pvVar1;
}



/* VA 60007445 */

/* Library Function - Single Match
    __nh_malloc

   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  int *piVar1;
  int iVar2;

  if (_Size < 0xffffffe1) {
    do {
      piVar1 = FUN_60007471((uint *)_Size);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_60009d28(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}



/* VA 60007471 */

int * __cdecl FUN_60007471(uint *param_1)

{
  int *piVar1;

  if (param_1 <= DAT_6001cc98) {
    FUN_60008d89(9);
    piVar1 = FUN_6000a0d7(param_1);
    FUN_60008dea(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  piVar1 = HeapAlloc(DAT_60020484,0,(int)param_1 + 0xfU & 0xfffffff0);
  return piVar1;
}



/* VA 600074bf */

void __cdecl FUN_600074bf(LPVOID param_1)

{
  uint *puVar1;

  if (param_1 != (LPVOID)0x0) {
    FUN_60008d89(9);
    puVar1 = (uint *)FUN_60009d81((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_60009dac(puVar1,(uint)param_1);
      FUN_60008dea(9);
      return;
    }
    FUN_60008dea(9);
    HeapFree(DAT_60020484,0,param_1);
  }
  return;
}



/* VA 60007507 */

undefined4 __cdecl FUN_60007507(uint *param_1)

{
  undefined4 uVar1;

  FUN_60008d89(0xc);
  uVar1 = FUN_60007528(param_1);
  FUN_60008dea(0xc);
  return uVar1;
}



/* VA 60007528 */

undefined4 __cdecl FUN_60007528(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;
  int iVar3;
  PCNZWCH lpWideCharStr;

  if (DAT_600205a4 != 0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = _malloc(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      FUN_6000ad20(puVar2,param_1);
      iVar3 = FUN_6000aad8(puVar2,1);
      if ((iVar3 == 0) &&
         ((DAT_6001da7c == 0 ||
          ((((iVar3 = MultiByteToWideChar(1,0,(LPCSTR)param_1,-1,(LPWSTR)0x0,0), iVar3 != 0 &&
             (lpWideCharStr = _malloc(iVar3 * 2), lpWideCharStr != (PCNZWCH)0x0)) &&
            (iVar3 = MultiByteToWideChar(1,0,(LPCSTR)param_1,-1,lpWideCharStr,iVar3), iVar3 != 0))
           && (iVar3 = FUN_6000a882(lpWideCharStr,0), iVar3 == 0)))))) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}



/* VA 600075bc */

undefined4 FUN_600075bc(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  FUN_60008cf4();
  DAT_6001c7e8 = TlsAlloc();
  if (DAT_6001c7e8 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_6000ae10(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_6001c7e8,lpTlsValue);
      if (BVar1 != 0) {
        FUN_6000762e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}



/* VA 60007610 */

void FUN_60007610(void)

{
  FUN_60008d1d();
  if (DAT_6001c7e8 != 0xffffffff) {
    TlsFree(DAT_6001c7e8);
    DAT_6001c7e8 = 0xffffffff;
  }
  return;
}



/* VA 6000762e */

void __cdecl FUN_6000762e(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_6001cca0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



/* VA 60007641 */

DWORD * FUN_60007641(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_6001c7e8);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_6000ae10(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_6001c7e8,lpTlsValue);
      if (BVar1 != 0) {
        FUN_6000762e((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_6000769c;
      }
    }
    __amsg_exit(0x10);
  }
LAB_6000769c:
  SetLastError(dwErrCode);
  return lpTlsValue;
}



/* VA 600076a8 */

void __cdecl FUN_600076a8(LPVOID param_1)

{
  if (DAT_6001c7e8 != 0xffffffff) {
    if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_6001c7e8), param_1 != (LPVOID)0x0)) {
      if (*(LPVOID *)((int)param_1 + 0x24) != (LPVOID)0x0) {
        FUN_600074bf(*(LPVOID *)((int)param_1 + 0x24));
      }
      if (*(LPVOID *)((int)param_1 + 0x28) != (LPVOID)0x0) {
        FUN_600074bf(*(LPVOID *)((int)param_1 + 0x28));
      }
      if (*(LPVOID *)((int)param_1 + 0x30) != (LPVOID)0x0) {
        FUN_600074bf(*(LPVOID *)((int)param_1 + 0x30));
      }
      if (*(LPVOID *)((int)param_1 + 0x38) != (LPVOID)0x0) {
        FUN_600074bf(*(LPVOID *)((int)param_1 + 0x38));
      }
      if (*(LPVOID *)((int)param_1 + 0x40) != (LPVOID)0x0) {
        FUN_600074bf(*(LPVOID *)((int)param_1 + 0x40));
      }
      if (*(LPVOID *)((int)param_1 + 0x44) != (LPVOID)0x0) {
        FUN_600074bf(*(LPVOID *)((int)param_1 + 0x44));
      }
      if (*(undefined **)((int)param_1 + 0x50) != &DAT_6001cca0) {
        FUN_600074bf(*(undefined **)((int)param_1 + 0x50));
      }
      FUN_600074bf(param_1);
    }
    TlsSetValue(DAT_6001c7e8,(LPVOID)0x0);
    return;
  }
  return;
}



/* VA 60007748 */

void FUN_60007748(void)

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
  DAT_600205a0 = 0x20;
  DAT_600204a0 = puVar2;
  for (; puVar2 < DAT_600204a0 + 0x120; puVar2 = puVar2 + 9) {
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
    if ((int)DAT_600205a0 < (int)UVar8) {
      puVar2 = &DAT_600204a4;
      do {
        puVar3 = _malloc(0x480);
        UVar9 = DAT_600205a0;
        if (puVar3 == (undefined4 *)0x0) break;
        DAT_600205a0 = DAT_600205a0 + 0x20;
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
      } while ((int)DAT_600205a0 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar9) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_600204a0)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
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
    puVar2 = DAT_600204a0 + iVar6 * 9;
    if (DAT_600204a0[iVar6 * 9] == -1) {
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
          goto LAB_600078ed;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_600078ed:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_600205a0);
      return;
    }
  } while( true );
}



/* VA 60007904 */

void FUN_60007904(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;

  puVar1 = &DAT_600204a0;
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
      FUN_600074bf((LPVOID)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x600205a0);
  return;
}



/* VA 60007958 */

void FUN_60007958(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;

  if (DAT_600205a8 == 0) {
    FUN_6000b275();
  }
  iVar5 = 0;
  for (puVar6 = DAT_6001da3c; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  DAT_6001da74 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_6001da3c;
  puVar6 = DAT_6001da3c;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_6000ad20((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_600074bf(DAT_6001da3c);
  DAT_6001da3c = (uint *)0x0;
  *puVar3 = 0;
  DAT_600205a4 = 1;
  return;
}



/* VA 60007a11 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60007a11(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;

  if (DAT_600205a8 == 0) {
    FUN_6000b275();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_6001da98,0x104);
  _DAT_6001da84 = &DAT_6001da98;
  pbVar2 = &DAT_6001da98;
  if (*DAT_600205b4 != 0) {
    pbVar2 = DAT_600205b4;
  }
  FUN_60007aaa(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_60007aaa(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_6001da6c = puVar1;
  _DAT_6001da68 = local_8 + -1;
  return;
}



/* VA 60007aaa */

void __cdecl FUN_60007aaa(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

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
      if (((*(byte *)((int)&DAT_6001f340 + bVar1 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)&DAT_6001f340 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_60007b55;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_60007b55:
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
          if ((*(byte *)((int)&DAT_6001f340 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_6001f340 + bVar1 + 1) & 4) != 0) {
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



/* VA 60007c5e */

LPSTR FUN_60007c5e(void)

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
  if (DAT_6001db9c == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_6001db9c = 1;
LAB_60007cb5:
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
        FUN_600074bf(pCVar6);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_6001db9c = 2;
  }
  else {
    if (DAT_6001db9c == 1) goto LAB_60007cb5;
    if (DAT_6001db9c != 2) {
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
    FUN_6000b2a0((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}



/* VA 60007d90 */

undefined4 __cdecl FUN_60007d90(int param_1)

{
  int iVar1;

  DAT_60020484 = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_60020484 != (HANDLE)0x0) {
    iVar1 = FUN_60009d43();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_60020484);
  }
  return 0;
}



/* VA 60007dcc */

void FUN_60007dcc(void)

{
  int iVar1;
  undefined4 *puVar2;

  iVar1 = 0;
  if (0 < DAT_6001f458) {
    puVar2 = (undefined4 *)((int)DAT_6001f45c + 0xc);
    do {
      VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
      VirtualFree((LPVOID)*puVar2,0,0x8000);
      HeapFree(DAT_60020484,0,(LPVOID)puVar2[1]);
      puVar2 = puVar2 + 5;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_6001f458);
  }
  HeapFree(DAT_60020484,0,DAT_6001f45c);
  HeapDestroy(DAT_60020484);
  return;
}



/* VA 60007e47 */

void FUN_60007e47(void)

{
  if ((DAT_6001da44 == 1) || ((DAT_6001da44 == 0 && (DAT_6001da48 == 1)))) {
    FUN_60007e80(0xfc);
    if (DAT_6001dba0 != (code *)0x0) {
      (*DAT_6001dba0)();
    }
    FUN_60007e80(0xff);
  }
  return;
}



/* VA 60007e80 */

void __cdecl FUN_60007e80(DWORD param_1)

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
  pDVar2 = &DAT_6001c818;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x6001c8a8);
  if (param_1 == (&DAT_6001c818)[iVar5 * 2]) {
    if ((DAT_6001da44 == 1) || ((DAT_6001da44 == 0 && (DAT_6001da48 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x6001c81c);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_6000ad20(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_6000ad20(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_6000ad30(local_a4,_Dest);
      FUN_6000ad30(local_a4,(uint *)&DAT_60012d24);
      FUN_6000ad30(local_a4,*(uint **)(iVar5 * 8 + 0x6001c81c));
      auStackY_1e3._3_4_ = 0x60007fa4;
      FUN_6000b5d5(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}



/* VA 60007fd3 */

void __fastcall FUN_60007fd3(void *param_1)

{
  FUN_6000b793(param_1,0x10000,0x30000);
  return;
}



/* VA 60007fe5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60007fe5(void)

{
  if (_DAT_60012d60 < _DAT_60012d68 - (_DAT_60012d68 / _DAT_60012d70) * _DAT_60012d70) {
    return 1;
  }
  return 0;
}



/* VA 60008023 */

void FUN_60008023(void)

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
  FUN_60007fe5();
  return;
}



/* VA 6000804c */

void __cdecl FUN_6000804c(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *this;
  uint uVar3;
  undefined *puVar4;

  this = (undefined *)(int)*param_1;
  uVar3 = FUN_6000b8c4((uint)this);
  if (uVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_6001c7dc < 2) {
        uVar3 = (byte)PTR_DAT_6001c5d0[*param_1 * 2] & 4;
        this = PTR_DAT_6001c5d0;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = FUN_60007114(this,(int)*param_1,4);
        this = puVar4;
      }
    } while (uVar3 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_6001c7e0;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}



/* VA 6000810c */

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
    FUN_6000bd90(in_ECX,(uint *)&local_c,(byte *)number);
    *(void **)argument = local_c;
    *(void **)(argument + 4) = local_8;
    return;
  }
  FUN_6000bdbd(in_ECX,(uint *)&number,(byte *)number);
  *(char **)argument = number;
  return;
}



/* VA 6000814a */

undefined1 * __cdecl FUN_6000814a(undefined8 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint local_2c [6];
  int local_14 [4];

  FUN_6000be61((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),local_14,local_2c);
  FUN_6000bdea(param_2 + (uint)(0 < param_3) + (uint)(local_14[0] == 0x2d),param_3 + 1,(int)local_14
              );
  FUN_600081ab(param_2,param_3,param_4,local_14,'\0');
  return param_2;
}



/* VA 600081ab */

undefined1 * __cdecl
FUN_600081ab(undefined1 *param_1,int param_2,int param_3,int *param_4,char param_5)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint *puVar3;
  int iVar4;

  if (param_5 != '\0') {
    FUN_6000844d(param_1 + (*param_4 == 0x2d),(uint)(0 < param_2));
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
    *puVar2 = DAT_6001c7e0;
  }
  puVar3 = FUN_6000ad20((uint *)(puVar2 + param_2 + (uint)(param_5 == '\0')),(uint *)"e+000");
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



/* VA 6000826d */

char * __cdecl FUN_6000826d(undefined8 *param_1,char *param_2,size_t param_3)

{
  uint local_2c [6];
  int local_14;
  int local_10;

  FUN_6000be61((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  FUN_6000bdea(param_2 + (local_14 == 0x2d),local_10 + param_3,(int)&local_14);
  FUN_600082c2(param_2,param_3,&local_14,'\0');
  return param_2;
}



/* VA 600082c2 */

char * __cdecl FUN_600082c2(char *param_1,size_t param_2,int *param_3,char param_4)

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
    FUN_6000844d(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + param_3[1];
  }
  if (0 < (int)param_2) {
    FUN_6000844d(pcVar3,1);
    *pcVar3 = DAT_6001c7e0;
    iVar1 = param_3[1];
    if (iVar1 < 0) {
      if ((param_4 != '\0') || (-iVar1 <= (int)param_2)) {
        param_2 = -iVar1;
      }
      FUN_6000844d(pcVar3 + 1,param_2);
      _memset(pcVar3 + 1,0x30,param_2);
    }
  }
  return param_1;
}



/* VA 60008369 */

void __cdecl FUN_60008369(undefined8 *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint local_2c [6];
  int local_14;
  int local_10;

  FUN_6000be61((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  iVar1 = local_10 + -1;
  FUN_6000bdea(param_2 + (local_14 == 0x2d),param_3,(int)&local_14);
  local_10 = local_10 + -1;
  if ((local_10 < -4) || ((int)param_3 <= local_10)) {
    FUN_600081ab(param_2,param_3,param_4,&local_14,'\x01');
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
    FUN_600082c2(param_2,param_3,&local_14,'\x01');
  }
  return;
}



/* VA 600083fc */

/* Library Function - Single Match
    __cfltcvt

   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *pcVar1;
  undefined1 *puVar2;

  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    puVar2 = FUN_6000814a(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      pcVar1 = FUN_6000826d(arg,buffer,format);
      return (errno_t)pcVar1;
    }
    puVar2 = (undefined1 *)FUN_60008369(arg,buffer,format,precision);
  }
  return (errno_t)puVar2;
}



/* VA 6000844d */

void __cdecl FUN_6000844d(char *param_1,int param_2)

{
  size_t sVar1;

  if (param_2 != 0) {
    sVar1 = _strlen(param_1);
    FUN_6000bfe0((undefined4 *)(param_1 + param_2),(undefined4 *)param_1,sVar1 + 1);
  }
  return;
}



/* VA 60008860 */

float10 __fastcall
FUN_60008860(undefined4 param_1,uint param_2,undefined2 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

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
  FUN_6000d0ab(param_2,&local_24,&param_3);
  return (float10)dStack_c;
}



/* VA 60008877 */

/* Library Function - Single Match
    __startOneArgErrorHandling

   Library: Visual Studio */

float10 __fastcall
__startOneArgErrorHandling
          (undefined4 param_1,uint param_2,ushort param_3,undefined4 param_4,undefined4 param_5,
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
  FUN_6000d0ab(param_2,&local_24,&param_3);
  return (float10)local_c;
}



/* VA 600088c0 */

undefined1  [10] FUN_600088c0(void)

{
  float10 in_ST0;
  float10 fVar1;
  undefined1 auVar2 [10];

  fVar1 = (float10)f2xm1(-(ROUND(in_ST0) - in_ST0));
  auVar2 = (undefined1  [10])fscale((float10)1 + fVar1,ROUND(in_ST0));
  return auVar2;
}



/* VA 600088d5 */

void FUN_600088d5(void)

{
  return;
}



/* VA 60008905 */

/* Library Function - Single Match
    __fload_withFB

   Library: Visual Studio */

uint __fastcall __fload_withFB(undefined4 param_1,int param_2)

{
  uint uVar1;

  uVar1 = *(uint *)(param_2 + 4) & 0x7ff00000;
  if (uVar1 != 0x7ff00000) {
    return uVar1;
  }
  return *(uint *)(param_2 + 4);
}



/* VA 6000895e */

void FUN_6000895e(void)

{
  return;
}



/* VA 600089a9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_600089a9(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  ushort unaff_retaddr;
  uint uStack_4;

  uStack_4 = (uint)((ulonglong)(double)in_ST0 >> 0x20);
  if (((ulonglong)(double)in_ST0 & 0x7ff0000000000000) == 0) {
    fscale(in_ST0,(float10)_DAT_60012ddc);
  }
  else if ((uStack_4 & 0x7ff00000) == 0x7ff00000) {
    fscale(in_ST0,(float10)_DAT_60012dd4);
  }
  else if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) != 0)) ||
          ((in_FPUStatusWord & 0x20) == 0)) {
    return;
  }
  if (param_2 == 0x1d) {
    FUN_60008860(param_1,0x1d,unaff_retaddr,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  __startOneArgErrorHandling(param_1,param_2,unaff_retaddr,param_3,param_4,param_5);
  return;
}



/* VA 60008a4c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_60008a4c(int param_1,int param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;

  dVar1 = (double)CONCAT44(param_2,param_1);
  if ((double)CONCAT44(param_2,param_1) < _DAT_60012da0) {
    dVar1 = -dVar1;
  }
  dVar2 = _DAT_6001cfb0;
  if (param_3._4_4_ == 0x7ff00000) {
    if (param_3._0_4_ != 0) {
LAB_60008ad7:
      if (param_2 == 0x7ff00000) {
        if (param_1 != 0) {
          return 0;
        }
        if (_DAT_60012da0 < param_3) goto LAB_60008b72;
        if (param_3 < _DAT_60012da0) goto LAB_60008b09;
      }
      else {
        if (param_2 != -0x100000) {
          return 0;
        }
        if (param_1 != 0) {
          return 0;
        }
        iVar3 = FUN_60008b7c(param_3);
        if (_DAT_60012da0 < param_3) {
          dVar2 = _DAT_6001cfb0;
          if (iVar3 == 1) {
            dVar2 = -_DAT_6001cfb0;
          }
          goto LAB_60008b72;
        }
        if (param_3 < _DAT_60012da0) {
          dVar2 = _DAT_6001cfd0;
          if (iVar3 != 1) {
            dVar2 = 0.0;
          }
          goto LAB_60008b72;
        }
      }
      dVar2 = 1.0;
      goto LAB_60008b72;
    }
    if (_DAT_60012d60 < dVar1) goto LAB_60008b72;
    if (_DAT_60012d60 <= dVar1) {
LAB_60008a9c:
      *param_4 = _DAT_6001cfb8;
      return 1;
    }
  }
  else {
    if (param_3 != -INFINITY) goto LAB_60008ad7;
    if (dVar1 <= _DAT_60012d60) {
      if (_DAT_60012d60 <= dVar1) goto LAB_60008a9c;
      goto LAB_60008b72;
    }
  }
LAB_60008b09:
  dVar2 = 0.0;
LAB_60008b72:
  *param_4 = dVar2;
  return 0;
}



/* VA 60008b7c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_60008b7c(double param_1)

{
  double dVar1;
  uint uVar2;
  float10 fVar3;
  undefined4 uVar4;

  uVar2 = FUN_6000d2d1(SUB84(param_1,0),(uint)((ulonglong)param_1 >> 0x20));
  if ((uVar2 & 0x90) == 0) {
    fVar3 = __frnd(param_1);
    if ((double)fVar3 == param_1) {
      dVar1 = param_1 / _DAT_600125b0;
      fVar3 = __frnd(dVar1);
      if (fVar3 == (float10)dVar1) {
        uVar4 = 2;
      }
      else {
        uVar4 = 1;
      }
      return uVar4;
    }
  }
  return 0;
}



/* VA 60008c00 */

uint * __cdecl FUN_60008c00(uint *param_1,char param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;

  while (((uint)param_1 & 3) != 0) {
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    param_1 = (uint *)((int)param_1 + 1);
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *param_1;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = param_1 + 1;
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      param_1 = puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (uint *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (uint *)0x0;
        }
      }
    }
    uVar1 = *param_1;
    if ((char)uVar1 == param_2) {
      return param_1;
    }
    if ((char)uVar1 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 1);
    }
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == param_2) {
      return (uint *)((int)param_1 + 3);
    }
    param_1 = puVar5;
    if (cVar2 == '\0') {
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}



/* VA 60008cf4 */

void FUN_60008cf4(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6001c994);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6001c984);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6001c974);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6001c954);
  return;
}



/* VA 60008d1d */

void FUN_60008d1d(void)

{
  undefined **ppuVar1;

  ppuVar1 = (undefined **)&DAT_6001c950;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_6001c994)) && (ppuVar1 != &PTR_DAT_6001c984)) &&
       ((ppuVar1 != &PTR_DAT_6001c974 && (ppuVar1 != &PTR_DAT_6001c954)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_600074bf(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x6001ca10);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6001c974);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6001c984);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6001c994);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_6001c954);
  return;
}



/* VA 60008d89 */

void __cdecl FUN_60008d89(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;

  piVar1 = &DAT_6001c950 + param_1;
  if ((&DAT_6001c950)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_60008d89(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_600074bf(lpCriticalSection);
    }
    FUN_60008dea(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}



/* VA 60008dea */

void __cdecl FUN_60008dea(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_6001c950)[param_1]);
  return;
}



/* VA 60008dff */

/* Library Function - Single Match
    __mbsnbicoll

   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;

  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = FUN_6000d363(DAT_6001f444,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_6001f22c);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}



/* VA 60008e40 */

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
    if (((uint)puVar2 & 3) == 0) goto LAB_60008e60;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_60008e93:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_60008e60:
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
  goto LAB_60008e93;
}



/* VA 60008ebb */

undefined4 FUN_60008ebb(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  uint *lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;

  lpWideCharStr = (LPCWSTR)*DAT_6001da7c;
  puVar2 = DAT_6001da7c;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (uint *)0x0)) ||
       (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*puVar2,-1,(LPSTR)lpMultiByteStr,_Size,(LPCSTR)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_6000aad8(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}



/* VA 60008f29 */

BOOL __cdecl
FUN_60008f29(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
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
  puStack_c = &DAT_60012e00;
  puStack_10 = &LAB_6000d704;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_6001dc08;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_6001dc08 == 0) {
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
  DAT_6001dc08 = iVar3;
  if (DAT_6001dc08 != 2) {
    if (DAT_6001dc08 == 1) {
      if (param_5 == 0) {
        param_5 = DAT_6001dc4c;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        FUN_6000d7e0();
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
    param_6 = DAT_6001dc3c;
  }
  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}



/* VA 60009072 */

int * __cdecl FUN_60009072(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;

  if (param_1 == (int *)0x0) {
    piVar1 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      FUN_600074bf(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          FUN_60008d89(9);
          puVar2 = (uint *)FUN_60009d81((int)param_1);
          if (puVar2 == (uint *)0x0) {
            FUN_60008dea(9);
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_60020484,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (DAT_6001cc98 < param_2) {
LAB_60009111:
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              piVar1 = HeapAlloc(DAT_60020484,0,(SIZE_T)param_2);
              if (piVar1 != (int *)0x0) {
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_6000b2a0(piVar1,param_1,(uint)puVar4);
                FUN_60009dac(puVar2,(uint)param_1);
              }
            }
            else {
              iVar3 = FUN_6000a58c(puVar2,(int)param_1,(int)param_2);
              piVar1 = param_1;
              if (iVar3 == 0) {
                piVar1 = FUN_6000a0d7(param_2);
                if (piVar1 == (int *)0x0) goto LAB_60009111;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_6000b2a0(piVar1,param_1,(uint)puVar4);
                FUN_60009dac(puVar2,(uint)param_1);
              }
              if (piVar1 == (int *)0x0) goto LAB_60009111;
            }
            FUN_60008dea(9);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
        if (DAT_6001dc18 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_60009d28(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



/* VA 600091aa */

SIZE_T __cdecl FUN_600091aa(LPCVOID param_1)

{
  uint uVar1;
  SIZE_T SVar2;

  FUN_60008d89(9);
  uVar1 = FUN_60009d81((int)param_1);
  if (uVar1 == 0) {
    FUN_60008dea(9);
    SVar2 = HeapSize(DAT_60020484,0,param_1);
  }
  else {
    SVar2 = *(int *)((int)param_1 + -4) - 9;
    FUN_60008dea(9);
  }
  return SVar2;
}



/* VA 600091ef */

uint __cdecl FUN_600091ef(uint param_1,int *param_2)

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
LAB_600092fb:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_600092fb;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_6001ca38 && (piVar4 != (int *)&DAT_6001ca58)) ||
        (bVar5 = FUN_6000db1b(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_6000dad7(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_6000d8e7(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_6001c7f0;
        }
        else {
          puVar6 = (undefined *)((&DAT_600204a0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_6000d80f(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_6000d8e7(uVar2,pcVar3,(uint)piVar7);
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



/* VA 60009307 */

int __cdecl FUN_60009307(int *param_1,byte *param_2,undefined4 *param_3)

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
      uVar2 = (byte)(&DAT_60012dec)[(char)bVar9] & 0xf;
    }
    local_34 = (int)(char)(&DAT_60012e0c)[uVar2 * 8 + local_34] >> 4;
    switch(local_34) {
    case 0:
switchD_60009375_caseD_0:
      local_28 = 0;
      if ((PTR_DAT_6001c5d0[(uint)bVar9 * 2 + 1] & 0x80) != 0) {
        FUN_60009a48((int)(char)bVar9,param_1,&local_18);
        bVar9 = *param_2;
        param_2 = pbVar1 + 2;
      }
      FUN_60009a48((int)(char)bVar9,param_1,&local_18);
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
        local_24 = FUN_60009ae6((int *)&param_3);
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
        local_14 = FUN_60009ae6((int *)&param_3);
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
          goto switchD_60009375_caseD_0;
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
LAB_60009786:
              local_30 = 7;
LAB_6000978d:
              local_10 = (undefined1 *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_600097f7;
            }
            if (bVar9 != 0x43) {
              if ((bVar9 != 0x45) && (bVar9 != 0x47)) {
                if (bVar9 == 0x53) {
                  if ((local_8 & 0x830) == 0) {
                    local_8 = local_8 | 0x800;
                  }
                  goto LAB_60009534;
                }
                goto LAB_60009911;
              }
              local_38 = 1;
              bVar9 = bVar9 + 0x20;
              goto LAB_60009595;
            }
            if ((local_8 & 0x830) == 0) {
              local_8 = local_8 | 0x800;
            }
LAB_600095c2:
            if ((local_8 & 0x810) == 0) {
              uVar5 = FUN_60009ae6((int *)&param_3);
              local_24c[0] = (char)uVar5;
              local_10 = (undefined1 *)0x1;
            }
            else {
              uVar5 = FUN_60009b03((int *)&param_3);
              local_10 = (undefined1 *)FUN_6000db44(local_24c,(WCHAR)uVar5);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar4 = (WCHAR *)local_24c;
          }
          else if (bVar9 == 0x5a) {
            psVar6 = (short *)FUN_60009ae6((int *)&param_3);
            if ((psVar6 == (short *)0x0) ||
               (pWVar4 = *(WCHAR **)(psVar6 + 2), pWVar4 == (WCHAR *)0x0)) {
              local_c = (WCHAR *)PTR_DAT_6001ca10;
              pWVar4 = (WCHAR *)PTR_DAT_6001ca10;
              goto LAB_60009707;
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
            if (bVar9 == 99) goto LAB_600095c2;
            if (bVar9 == 100) goto LAB_600097ec;
          }
        }
        else {
LAB_60009595:
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
          (*(code *)PTR___fptrap_6001c8a8)(&local_4c,local_24c,(int)(char)bVar9,local_14,local_38);
          uVar2 = local_8 & 0x80;
          if ((uVar2 != 0) && (local_14 == 0)) {
            (*(code *)PTR___fptrap_6001c8b4)(local_24c);
          }
          if ((bVar9 == 0x67) && (uVar2 == 0)) {
            (*(code *)PTR___fptrap_6001c8ac)(local_24c);
          }
          if (local_24c[0] == '-') {
            local_8 = local_8 | 0x100;
            pWVar4 = (WCHAR *)(local_24c + 1);
            local_c = pWVar4;
          }
LAB_60009707:
          local_10 = (undefined1 *)_strlen((char *)pWVar4);
          pWVar4 = local_c;
        }
      }
      else {
        if (bVar9 == 0x69) {
LAB_600097ec:
          local_8 = local_8 | 0x40;
        }
        else {
          if (bVar9 == 0x6e) {
            piVar7 = (int *)FUN_60009ae6((int *)&param_3);
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
            goto LAB_600097f7;
          }
          if (bVar9 == 0x70) {
            local_14 = 8;
            goto LAB_60009786;
          }
          if (bVar9 == 0x73) {
LAB_60009534:
            iVar10 = local_14;
            if (local_14 == -1) {
              iVar10 = 0x7fffffff;
            }
            pWVar3 = (WCHAR *)FUN_60009ae6((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              pWVar4 = pWVar3;
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_6001ca10;
                pWVar4 = (WCHAR *)PTR_DAT_6001ca10;
              }
              for (; (iVar10 != 0 && ((char)*pWVar3 != '\0')); pWVar3 = (WCHAR *)((int)pWVar3 + 1))
              {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar3 - (int)pWVar4);
            }
            else {
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_6001ca14;
              }
              local_28 = 1;
              for (pWVar4 = pWVar3; (iVar10 != 0 && (*pWVar4 != L'\0')); pWVar4 = pWVar4 + 1) {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar4 - (int)pWVar3 >> 1);
              pWVar4 = pWVar3;
            }
            goto LAB_60009911;
          }
          if (bVar9 != 0x75) {
            if (bVar9 != 0x78) goto LAB_60009911;
            local_30 = 0x27;
            goto LAB_6000978d;
          }
        }
        local_10 = (undefined1 *)0xa;
LAB_600097f7:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar2 = FUN_60009ae6((int *)&param_3);
              uVar13 = (ulonglong)uVar2;
              goto LAB_6000984a;
            }
            uVar2 = FUN_60009ae6((int *)&param_3);
          }
          else if ((local_8 & 0x40) == 0) {
            uVar2 = FUN_60009ae6((int *)&param_3);
            uVar2 = uVar2 & 0xffff;
          }
          else {
            uVar5 = FUN_60009ae6((int *)&param_3);
            uVar2 = (uint)(short)uVar5;
          }
          uVar13 = (ulonglong)(int)uVar2;
        }
        else {
          uVar13 = FUN_60009af3((int *)&param_3);
        }
LAB_6000984a:
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
LAB_60009911:
      local_c = pWVar4;
      uVar2 = local_8;
      if (local_2c == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) == 0) goto LAB_60009949;
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
LAB_60009949:
        iVar10 = (local_24 - local_20) - (int)local_10;
        if ((local_8 & 0xc) == 0) {
          FUN_60009a7d(0x20,iVar10,param_1,&local_18);
        }
        FUN_60009aae(&local_1a,local_20,param_1,&local_18);
        if (((uVar2 & 8) != 0) && ((uVar2 & 4) == 0)) {
          FUN_60009a7d(0x30,iVar10,param_1,&local_18);
        }
        if ((local_28 == 0) || (puVar12 = local_10, pWVar4 = local_c, (int)local_10 < 1)) {
          FUN_60009aae((char *)local_c,(int)local_10,param_1,&local_18);
        }
        else {
          do {
            puVar12 = puVar12 + -1;
            iVar8 = FUN_6000db44(local_3c,*pWVar4);
            if (iVar8 < 1) break;
            FUN_60009aae(local_3c,iVar8,param_1,&local_18);
            pWVar4 = pWVar4 + 1;
          } while (puVar12 != (undefined1 *)0x0);
        }
        if ((local_8 & 4) != 0) {
          FUN_60009a7d(0x20,iVar10,param_1,&local_18);
        }
      }
    }
    bVar9 = *param_2;
    pbVar1 = param_2;
  } while( true );
}



/* VA 60009a48 */

void __cdecl FUN_60009a48(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;

  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_600091ef(param_1,param_2);
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



/* VA 60009a7d */

void __cdecl FUN_60009a7d(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_60009a48(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 60009aae */

void __cdecl FUN_60009aae(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;

  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_60009a48((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 60009ae6 */

undefined4 __cdecl FUN_60009ae6(int *param_1)

{
  *param_1 = *param_1 + 4;
  return *(undefined4 *)(*param_1 + -4);
}



/* VA 60009af3 */

undefined8 __cdecl FUN_60009af3(int *param_1)

{
  *param_1 = *param_1 + 8;
  return *(undefined8 *)(*param_1 + -8);
}



/* VA 60009b03 */

undefined4 __cdecl FUN_60009b03(int *param_1)

{
  *param_1 = *param_1 + 4;
  return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + -4));
}



/* VA 60009bcd */

void __cdecl FUN_60009bcd(uint param_1)

{
  if ((0x6001ca17 < param_1) && (param_1 < 0x6001cc79)) {
    FUN_60008d89(((int)(param_1 + 0x9ffe35e8) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 60009bfc */

void __cdecl FUN_60009bfc(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_60008d89(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 60009c1f */

void __cdecl FUN_60009c1f(uint param_1)

{
  if ((0x6001ca17 < param_1) && (param_1 < 0x6001cc79)) {
    FUN_60008dea(((int)(param_1 + 0x9ffe35e8) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 60009c4e */

void __cdecl FUN_60009c4e(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_60008dea(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 60009c71 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_60009c71(undefined4 *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  void *pvVar4;

  bVar2 = FUN_6000db1b(param_1[4]);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  if (param_1 == (undefined4 *)&DAT_6001ca38) {
    iVar3 = 0;
  }
  else {
    if (param_1 != (undefined4 *)&DAT_6001ca58) {
      return 0;
    }
    iVar3 = 1;
  }
  _DAT_6001dc0c = _DAT_6001dc0c + 1;
  if ((*(ushort *)(param_1 + 3) & 0x10c) != 0) {
    return 0;
  }
  if ((&DAT_6001dc10)[iVar3] == 0) {
    pvVar4 = _malloc(0x1000);
    (&DAT_6001dc10)[iVar3] = pvVar4;
    if (pvVar4 == (void *)0x0) {
      param_1[2] = param_1 + 5;
      *param_1 = param_1 + 5;
      param_1[6] = 2;
      param_1[1] = 2;
      goto LAB_60009ced;
    }
  }
  uVar1 = (&DAT_6001dc10)[iVar3];
  param_1[6] = 0x1000;
  param_1[2] = uVar1;
  *param_1 = uVar1;
  param_1[1] = 0x1000;
LAB_60009ced:
  *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x1102;
  return 1;
}



/* VA 60009cfe */

void __cdecl FUN_60009cfe(int param_1,int *param_2)

{
  if ((param_1 != 0) && ((*(byte *)((int)param_2 + 0xd) & 0x10) != 0)) {
    FUN_6000dda4(param_2);
    *(byte *)((int)param_2 + 0xd) = *(byte *)((int)param_2 + 0xd) & 0xee;
    param_2[6] = 0;
    *param_2 = 0;
    param_2[2] = 0;
  }
  return;
}



/* VA 60009d28 */

undefined4 __cdecl FUN_60009d28(undefined4 param_1)

{
  int iVar1;

  if (DAT_6001dc1c != (code *)0x0) {
    iVar1 = (*DAT_6001dc1c)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* VA 60009d43 */

undefined4 FUN_60009d43(void)

{
  DAT_6001f45c = HeapAlloc(DAT_60020484,0,0x140);
  if (DAT_6001f45c == (LPVOID)0x0) {
    return 0;
  }
  DAT_6001f454 = 0;
  DAT_6001f458 = 0;
  DAT_6001f450 = DAT_6001f45c;
  DAT_6001f448 = 0x10;
  return 1;
}



/* VA 60009d81 */

uint __cdecl FUN_60009d81(int param_1)

{
  uint uVar1;

  uVar1 = DAT_6001f45c;
  while( true ) {
    if (DAT_6001f45c + DAT_6001f458 * 0x14 <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}



/* VA 60009dac */

void __cdecl FUN_60009dac(uint *param_1,uint param_2)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_10;

  uVar5 = param_1[4];
  iVar6 = *(int *)(param_2 - 4);
  piVar9 = (int *)(param_2 - 4);
  uVar10 = param_2 - param_1[3] >> 0xf;
  uVar7 = *(uint *)(param_2 - 8);
  local_10 = iVar6 + -1;
  piVar3 = (int *)(uVar10 * 0x204 + 0x144 + uVar5);
  uVar12 = *(uint *)(local_10 + (int)piVar9);
  if ((uVar12 & 1) == 0) {
    param_2 = ((int)uVar12 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    if (*(int *)(iVar6 + 3 + (int)piVar9) == *(int *)(iVar6 + 7 + (int)piVar9)) {
      if (param_2 < 0x20) {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 7 + (int)piVar9) + 4) =
         *(undefined4 *)(iVar6 + 3 + (int)piVar9);
    local_10 = local_10 + uVar12;
    *(undefined4 *)(*(int *)(iVar6 + 3 + (int)piVar9) + 8) =
         *(undefined4 *)(iVar6 + 7 + (int)piVar9);
  }
  uVar12 = (local_10 >> 4) - 1;
  if (0x3f < uVar12) {
    uVar12 = 0x3f;
  }
  if ((uVar7 & 1) == 0) {
    piVar9 = (int *)((int)piVar9 - uVar7);
    param_2 = ((int)uVar7 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    local_10 = local_10 + uVar7;
    uVar12 = (local_10 >> 4) - 1;
    if (0x3f < uVar12) {
      uVar12 = 0x3f;
    }
    if (param_2 != uVar12) {
      if (piVar9[1] == piVar9[2]) {
        if (param_2 < 0x20) {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar11;
          }
        }
      }
      *(int *)(piVar9[2] + 4) = piVar9[1];
      *(int *)(piVar9[1] + 8) = piVar9[2];
    }
  }
  if (((uVar7 & 1) != 0) || (param_2 != uVar12)) {
    piVar9[1] = piVar3[uVar12 * 2 + 1];
    piVar9[2] = (int)(piVar3 + uVar12 * 2);
    (piVar3 + uVar12 * 2)[1] = (int)piVar9;
    *(int **)(piVar9[1] + 8) = piVar9;
    if (piVar9[1] == piVar9[2]) {
      cVar4 = *(char *)(uVar12 + 4 + uVar5);
      *(char *)(uVar12 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar12;
      if (uVar12 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  *piVar9 = local_10;
  *(int *)(local_10 + -4 + (int)piVar9) = local_10;
  *piVar3 = *piVar3 + -1;
  uVar5 = DAT_6001f44c;
  puVar2 = DAT_6001f454;
  if ((*piVar3 == 0) && (uVar5 = uVar10, puVar2 = param_1, DAT_6001f454 != (uint *)0x0)) {
    VirtualFree((LPVOID)(DAT_6001f44c * 0x8000 + DAT_6001f454[3]),0x8000,0x4000);
    DAT_6001f454[2] = DAT_6001f454[2] | 0x80000000U >> ((byte)DAT_6001f44c & 0x1f);
    *(undefined4 *)(DAT_6001f454[4] + 0xc4 + DAT_6001f44c * 4) = 0;
    *(char *)(DAT_6001f454[4] + 0x43) = *(char *)(DAT_6001f454[4] + 0x43) + -1;
    if (*(char *)(DAT_6001f454[4] + 0x43) == '\0') {
      DAT_6001f454[1] = DAT_6001f454[1] & 0xfffffffe;
    }
    puVar2 = param_1;
    if (DAT_6001f454[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_6001f454[3],0,0x8000);
      HeapFree(DAT_60020484,0,(LPVOID)DAT_6001f454[4]);
      FUN_6000bfe0(DAT_6001f454,DAT_6001f454 + 5,
                   (DAT_6001f458 * 0x14 - (int)DAT_6001f454) + -0x14 + DAT_6001f45c);
      DAT_6001f458 = DAT_6001f458 + -1;
      if (DAT_6001f454 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_6001f450 = DAT_6001f45c;
      puVar2 = param_1;
    }
  }
  DAT_6001f454 = puVar2;
  DAT_6001f44c = uVar5;
  return;
}



/* VA 6000a0d7 */

int * __cdecl FUN_6000a0d7(uint *param_1)

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

  puVar8 = DAT_6001f45c + DAT_6001f458 * 5;
  uVar6 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar7 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  bVar5 = (byte)iVar7;
  param_1 = DAT_6001f450;
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
  puVar11 = DAT_6001f45c;
  if (param_1 == puVar8) {
    for (; (puVar11 < DAT_6001f450 && ((puVar11[1] & local_c) == 0 && (*puVar11 & local_10) == 0));
        puVar11 = puVar11 + 5) {
    }
    param_1 = puVar11;
    if (puVar11 == DAT_6001f450) {
      for (; (puVar11 < puVar8 && (puVar11[2] == 0)); puVar11 = puVar11 + 5) {
      }
      puVar12 = DAT_6001f45c;
      param_1 = puVar11;
      if (puVar11 == puVar8) {
        for (; (puVar12 < DAT_6001f450 && (puVar12[2] == 0)); puVar12 = puVar12 + 5) {
        }
        param_1 = puVar12;
        if ((puVar12 == DAT_6001f450) && (param_1 = FUN_6000a3e0(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar7 = FUN_6000a491((int)param_1);
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
  DAT_6001f450 = param_1;
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
    if (iVar9 == 0) goto LAB_6000a39d;
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
LAB_6000a39d:
  piVar10 = (int *)((int)piVar10 + iVar9);
  *piVar10 = uVar6 + 1;
  *(uint *)((int)piVar10 + (uVar6 - 4)) = uVar6 + 1;
  iVar7 = *piVar2;
  *piVar2 = iVar7 + 1;
  if (((iVar7 == 0) && (param_1 == DAT_6001f454)) && (local_8 == DAT_6001f44c)) {
    DAT_6001f454 = (uint *)0x0;
  }
  *piVar4 = local_8;
  return piVar10 + 1;
}



/* VA 6000a3e0 */

undefined4 * FUN_6000a3e0(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;

  if (DAT_6001f458 == DAT_6001f448) {
    pvVar2 = HeapReAlloc(DAT_60020484,0,DAT_6001f45c,(DAT_6001f448 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_6001f448 = DAT_6001f448 + 0x10;
    DAT_6001f45c = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_6001f45c + DAT_6001f458 * 0x14);
  pvVar2 = HeapAlloc(DAT_60020484,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_6001f458 = DAT_6001f458 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_60020484,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}



/* VA 6000a491 */

int __cdecl FUN_6000a491(int param_1)

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



/* VA 6000a58c */

undefined4 __cdecl FUN_6000a58c(uint *param_1,int param_2,int param_3)

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



/* VA 6000a882 */

undefined4 __cdecl FUN_6000a882(PCNZWCH param_1,int param_2)

{
  PCNZWCH pWVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  LPCWSTR lpName;
  int iVar5;
  int *piVar6;
  bool bVar7;

  if (((param_1 == (PCNZWCH)0x0) ||
      (pWVar1 = (PCNZWCH)FUN_6000df57(param_1,0x3d), pWVar1 == (PCNZWCH)0x0)) || (param_1 == pWVar1)
     ) goto LAB_6000a8e5;
  bVar7 = pWVar1[1] == L'\0';
  if (DAT_6001da7c == DAT_6001da80) {
    DAT_6001da7c = FUN_6000aa71(DAT_6001da7c);
  }
  if (DAT_6001da7c == (int *)0x0) {
    if ((param_2 == 0) || (DAT_6001da74 == (undefined4 *)0x0)) {
      if (bVar7) goto LAB_6000aa0e;
      if (DAT_6001da74 == (undefined4 *)0x0) {
        DAT_6001da74 = _malloc(4);
        if (DAT_6001da74 == (undefined4 *)0x0) goto LAB_6000a8e5;
        *DAT_6001da74 = 0;
        if (DAT_6001da7c != (int *)0x0) goto LAB_6000a927;
      }
      DAT_6001da7c = _malloc(4);
      if (DAT_6001da7c != (int *)0x0) {
        *DAT_6001da7c = 0;
        goto LAB_6000a927;
      }
    }
    else {
      iVar2 = FUN_6000deef();
      if (iVar2 == 0) goto LAB_6000a927;
    }
LAB_6000a8e5:
    uVar3 = 0xffffffff;
  }
  else {
LAB_6000a927:
    piVar4 = DAT_6001da7c;
    iVar5 = (int)pWVar1 - (int)param_1 >> 1;
    iVar2 = FUN_6000aa15(param_1,iVar5);
    if ((iVar2 < 0) || (*piVar4 == 0)) {
      if (!bVar7) {
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        piVar4 = FUN_60009072(piVar4,(uint *)(iVar2 * 4 + 8));
        if (piVar4 != (int *)0x0) {
          piVar4[iVar2] = (int)param_1;
          piVar4[iVar2 + 1] = 0;
          goto LAB_6000a9b9;
        }
        goto LAB_6000a8e5;
      }
    }
    else {
      if (bVar7) {
        piVar6 = piVar4 + iVar2;
        FUN_600074bf((LPVOID)piVar4[iVar2]);
        for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
          iVar2 = iVar2 + 1;
          *piVar6 = piVar6[1];
        }
        piVar4 = FUN_60009072(piVar4,(uint *)(iVar2 << 2));
        if (piVar4 != (int *)0x0) {
LAB_6000a9b9:
          DAT_6001da7c = piVar4;
        }
      }
      else {
        piVar4[iVar2] = (int)param_1;
      }
      if (param_2 != 0) {
        iVar2 = FUN_6000ded2(param_1);
        lpName = _malloc(iVar2 * 2 + 4);
        if (lpName != (LPCWSTR)0x0) {
          FUN_6000dead(lpName,param_1);
          lpName[iVar5] = L'\0';
          SetEnvironmentVariableW(lpName,(LPCWSTR)(~-(uint)bVar7 & (uint)(lpName + iVar5 + 1)));
          FUN_600074bf(lpName);
        }
      }
    }
LAB_6000aa0e:
    uVar3 = 0;
  }
  return uVar3;
}



/* VA 6000aa15 */

int __cdecl FUN_6000aa15(PCNZWCH param_1,int param_2)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  int *piVar4;

  pWVar2 = (LPCWSTR)*DAT_6001da7c;
  piVar4 = DAT_6001da7c;
  while( true ) {
    if (pWVar2 == (LPCWSTR)0x0) {
      return -((int)piVar4 - (int)DAT_6001da7c >> 2);
    }
    iVar3 = FUN_6000df80(param_1,pWVar2,param_2);
    if ((iVar3 == 0) && ((sVar1 = *(short *)(*piVar4 + param_2 * 2), sVar1 == 0x3d || (sVar1 == 0)))
       ) break;
    pWVar2 = (LPCWSTR)piVar4[1];
    piVar4 = piVar4 + 1;
  }
  return (int)piVar4 - (int)DAT_6001da7c >> 2;
}



/* VA 6000aa71 */

undefined4 * __cdecl FUN_6000aa71(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  short *psVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;

  iVar6 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar6 = iVar6 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = _malloc(iVar6 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    psVar4 = (short *)*param_1;
    puVar7 = puVar3;
    while (psVar4 != (short *)0x0) {
      param_1 = param_1 + 1;
      uVar5 = FUN_6000e061(psVar4);
      *puVar7 = uVar5;
      puVar7 = puVar7 + 1;
      psVar4 = (short *)*param_1;
    }
    *puVar7 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}



/* VA 6000aad8 */

undefined4 __cdecl FUN_6000aad8(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  undefined1 *puVar5;
  int *piVar6;
  bool bVar7;

  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar1 = FUN_6000e08f(param_1,0x3d);
  if (puVar1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = *(char *)((int)puVar1 + 1) == '\0';
  if (DAT_6001da74 == DAT_6001da78) {
    DAT_6001da74 = FUN_6000acb7(DAT_6001da74);
  }
  if (DAT_6001da74 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_6001da7c == (undefined4 *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_6001da74 = _malloc(4);
      if (DAT_6001da74 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_6001da74 = 0;
      if (DAT_6001da7c == (undefined4 *)0x0) {
        DAT_6001da7c = _malloc(4);
        if (DAT_6001da7c == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_6001da7c = 0;
      }
    }
    else {
      iVar2 = FUN_60008ebb();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_6001da74;
  iVar2 = FUN_6000ac5f((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = FUN_60009072(piVar3,(uint *)(iVar2 * 4 + 8));
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar7) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_6000ac0c;
    }
    piVar6 = piVar3 + iVar2;
    FUN_600074bf((LPVOID)piVar3[iVar2]);
    for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
      iVar2 = iVar2 + 1;
      *piVar6 = piVar6[1];
    }
    piVar3 = FUN_60009072(piVar3,(uint *)(iVar2 << 2));
    if (piVar3 == (int *)0x0) goto LAB_6000ac0c;
  }
  DAT_6001da74 = piVar3;
LAB_6000ac0c:
  if (param_2 != 0) {
    sVar4 = _strlen((char *)param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (uint *)0x0) {
      FUN_6000ad20(lpName,param_1);
      puVar5 = (undefined1 *)(((int)lpName - (int)param_1) + (int)puVar1);
      *puVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar7 & (uint)(puVar5 + 1)));
      FUN_600074bf(lpName);
    }
  }
  return 0;
}



/* VA 6000ac5f */

int __cdecl FUN_6000ac5f(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;

  _Str2 = (uchar *)*DAT_6001da74;
  piVar2 = DAT_6001da74;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_6001da74 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    _Str2 = (uchar *)piVar2[1];
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_6001da74 >> 2;
}



/* VA 6000acb7 */

undefined4 * __cdecl FUN_6000acb7(int *param_1)

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
      puVar4 = FUN_6000e126(puVar4);
      *puVar6 = puVar4;
      puVar6 = puVar6 + 1;
      puVar4 = (uint *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}



/* VA 6000ad20 */

uint * __cdecl FUN_6000ad20(uint *param_1,uint *param_2)

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
    if (bVar1 == 0) goto LAB_6000ae08;
    *(byte *)puVar4 = bVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  do {
    uVar2 = *param_2;
    uVar3 = *param_2;
    param_2 = param_2 + 1;
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar3 == '\0') {
LAB_6000ae08:
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



/* VA 6000ad30 */

uint * __cdecl FUN_6000ad30(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;

  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_6000ad4c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_6000ad7f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x6000ad9b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_6000ad4c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x6000ad9b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x6000ad9b;
    }
  }
LAB_6000ad7f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x6000ad9b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_6000ae08:
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
    if (bVar1 == 0) goto LAB_6000ae08;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}



/* VA 6000ae10 */

int * __cdecl FUN_6000ae10(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint *_Size;
  uint *puVar3;

  _Size = (uint *)(param_1 * param_2);
  puVar3 = _Size;
  if (_Size < (uint *)0xffffffe1) {
    if (_Size == (uint *)0x0) {
      puVar3 = (uint *)0x1;
    }
    puVar3 = (uint *)((int)puVar3 + 0xfU & 0xfffffff0);
  }
  do {
    if (puVar3 < (uint *)0xffffffe1) {
      if (_Size < DAT_6001cc98 || (int)_Size - (int)DAT_6001cc98 == 0) {
        FUN_60008d89(9);
        piVar1 = FUN_6000a0d7(_Size);
        FUN_60008dea(9);
        if (piVar1 != (int *)0x0) {
          _memset(piVar1,0,(size_t)_Size);
          return piVar1;
        }
      }
      piVar1 = HeapAlloc(DAT_60020484,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_6001dc18 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_60009d28(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}



/* VA 6000ae9d */

undefined4 __cdecl FUN_6000ae9d(int param_1)

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

  FUN_60008d89(0x19);
  CodePage = FUN_6000b04a(param_1);
  if (CodePage != DAT_6001f22c) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_6001cd30;
LAB_6000aeda:
      if (*pUVar5 != CodePage) goto code_r0x6000aede;
      local_8 = 0;
      puVar15 = &DAT_6001f340;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x6001cd40);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_6001cd28)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_6001f340 + uVar8 + 1);
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
      DAT_6001f23c = 1;
      DAT_6001f22c = CodePage;
      DAT_6001f444 = FUN_6000b094(CodePage);
      DAT_6001f230 = *(undefined4 *)(iVar12 + 0x6001cd34);
      DAT_6001f234 = *(undefined4 *)(iVar12 + 0x6001cd38);
      DAT_6001f238 = *(undefined4 *)(iVar12 + 0x6001cd3c);
      goto LAB_6000b02e;
    }
    goto LAB_6000b029;
  }
  goto LAB_6000aec4;
code_r0x6000aede:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x6001ce1f < (int)pUVar5) goto code_r0x6000aee9;
  goto LAB_6000aeda;
code_r0x6000aee9:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_6001f444 = 0;
    puVar15 = &DAT_6001f340;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_6001f23c = 0;
      DAT_6001f22c = CodePage;
    }
    else {
      DAT_6001f22c = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_6001f340 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_6001f340 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_6001f444 = FUN_6000b094(CodePage);
      DAT_6001f23c = 1;
    }
    DAT_6001f230 = 0;
    DAT_6001f234 = 0;
    DAT_6001f238 = 0;
  }
  else {
    if (DAT_6001dc20 == 0) {
      uVar14 = 0xffffffff;
      goto LAB_6000b03b;
    }
LAB_6000b029:
    FUN_6000b0c7();
  }
LAB_6000b02e:
  FUN_6000b0f0();
LAB_6000aec4:
  uVar14 = 0;
LAB_6000b03b:
  FUN_60008dea(0x19);
  return uVar14;
}



/* VA 6000b04a */

int __cdecl FUN_6000b04a(int param_1)

{
  int iVar1;
  bool bVar2;

  if (param_1 == -2) {
    DAT_6001dc20 = 1;
                    /* WARNING: Could not recover jumptable at 0x6000b064. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_6001dc20 = 1;
                    /* WARNING: Could not recover jumptable at 0x6000b079. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_6001dc4c;
  }
  DAT_6001dc20 = (uint)bVar2;
  return param_1;
}



/* VA 6000b094 */

undefined4 __cdecl FUN_6000b094(int param_1)

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



/* VA 6000b0c7 */

void FUN_6000b0c7(void)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = &DAT_6001f340;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_6001f22c = 0;
  DAT_6001f23c = 0;
  DAT_6001f444 = 0;
  DAT_6001f230 = 0;
  DAT_6001f234 = 0;
  DAT_6001f238 = 0;
  return;
}



/* VA 6000b0f0 */

void FUN_6000b0f0(void)

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

  BVar2 = GetCPInfo(DAT_6001f22c,&local_18);
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
    FUN_60008f29(1,local_118,0x100,local_518,DAT_6001f22c,DAT_6001f444,0);
    FUN_6000e151(DAT_6001f444,0x100,local_118,0x100,local_218,0x100,DAT_6001f22c,0);
    FUN_6000e151(DAT_6001f444,0x200,local_118,0x100,local_318,0x100,DAT_6001f22c,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_6001f340 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_6000b1fc;
        }
        (&DAT_6001f240)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_6001f340 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_6000b1fc:
        (&DAT_6001f240)[uVar3] = uVar8;
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
          pbVar1 = (byte *)((int)&DAT_6001f340 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_6000b246;
        }
        (&DAT_6001f240)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_6001f340 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_6000b246:
        (&DAT_6001f240)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}



/* VA 6000b275 */

void FUN_6000b275(void)

{
  if (DAT_600205a8 == 0) {
    FUN_6000ae9d(-3);
    DAT_600205a8 = 1;
  }
  return;
}



/* VA 6000b2a0 */

undefined4 * __cdecl FUN_6000b2a0(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_6000b457_caseD_2;
        case 3:
          goto switchD_6000b457_caseD_3;
        }
        goto switchD_6000b457_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_6000b457_caseD_0;
      case 1:
        goto switchD_6000b457_caseD_1;
      case 2:
        goto switchD_6000b457_caseD_2;
      case 3:
        goto switchD_6000b457_caseD_3;
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
              goto switchD_6000b457_caseD_2;
            case 3:
              goto switchD_6000b457_caseD_3;
            }
            goto switchD_6000b457_caseD_1;
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
              goto switchD_6000b457_caseD_2;
            case 3:
              goto switchD_6000b457_caseD_3;
            }
            goto switchD_6000b457_caseD_1;
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
              goto switchD_6000b457_caseD_2;
            case 3:
              goto switchD_6000b457_caseD_3;
            }
            goto switchD_6000b457_caseD_1;
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
switchD_6000b457_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_6000b457_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_6000b457_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_6000b457_caseD_0:
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
        goto switchD_6000b2d5_caseD_2;
      case 3:
        goto switchD_6000b2d5_caseD_3;
      }
      goto switchD_6000b2d5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_6000b2d5_caseD_0;
    case 1:
      goto switchD_6000b2d5_caseD_1;
    case 2:
      goto switchD_6000b2d5_caseD_2;
    case 3:
      goto switchD_6000b2d5_caseD_3;
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
            goto switchD_6000b2d5_caseD_2;
          case 3:
            goto switchD_6000b2d5_caseD_3;
          }
          goto switchD_6000b2d5_caseD_1;
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
            goto switchD_6000b2d5_caseD_2;
          case 3:
            goto switchD_6000b2d5_caseD_3;
          }
          goto switchD_6000b2d5_caseD_1;
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
            goto switchD_6000b2d5_caseD_2;
          case 3:
            goto switchD_6000b2d5_caseD_3;
          }
          goto switchD_6000b2d5_caseD_1;
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
switchD_6000b2d5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_6000b2d5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_6000b2d5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_6000b2d5_caseD_0:
  return param_1;
}



/* VA 6000b5d5 */

int __cdecl FUN_6000b5d5(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;

  iVar1 = 0;
  if (DAT_6001dc24 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_6001dc24 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_6001dc24 != (FARPROC)0x0) {
        DAT_6001dc28 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_6001dc2c = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_6000b624;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_6000b624:
    if (DAT_6001dc28 != (FARPROC)0x0) {
      iVar1 = (*DAT_6001dc28)();
      if ((iVar1 != 0) && (DAT_6001dc2c != (FARPROC)0x0)) {
        iVar1 = (*DAT_6001dc2c)(iVar1);
      }
    }
    iVar1 = (*DAT_6001dc24)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}



/* VA 6000b660 */

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
        goto joined_r0x6000b69e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_6000b6db;
        goto LAB_6000b749;
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
joined_r0x6000b745:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_6000b749:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_6000b6db;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x6000b745;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x6000b745;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x6000b745;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x6000b69e:
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
LAB_6000b6db:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* VA 6000b75e */

uint __thiscall FUN_6000b75e(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;

  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_6000b7a9(local_8);
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_6000b83b(uVar1);
  return uVar1;
}



/* VA 6000b793 */

void __thiscall FUN_6000b793(void *this,uint param_1,uint param_2)

{
  FUN_6000b75e(this,param_1,param_2 & 0xfff7ffff);
  return;
}



/* VA 6000b7a9 */

uint __cdecl FUN_6000b7a9(uint param_1)

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



/* VA 6000b83b */

uint __cdecl FUN_6000b83b(uint param_1)

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



/* VA 6000b8c4 */

uint __cdecl FUN_6000b8c4(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;

  if (DAT_6001dc3c == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_6001f228);
    bVar1 = DAT_6001f224 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_6001f228);
      this = (void *)0x13;
      FUN_60008d89(0x13);
    }
    param_1 = FUN_6000b933(this,param_1);
    if (bVar1) {
      FUN_60008dea(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_6001f228);
    }
  }
  return param_1;
}



/* VA 6000b933 */

uint __thiscall FUN_6000b933(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;

  uVar1 = param_1;
  if (DAT_6001dc3c == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      uVar1 = param_1 + 0x20;
    }
  }
  else {
    iVar3 = 1;
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_6001c7dc < 2) {
        uVar2 = (byte)PTR_DAT_6001c5d0[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_60007114(this,param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_6001c5d0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_6000e151(DAT_6001dc3c,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
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



/* VA 6000b9fe */

undefined4 __cdecl FUN_6000b9fe(int param_1,int param_2)

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



/* VA 6000ba47 */

void __cdecl FUN_6000ba47(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;

  puVar3 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = FUN_6000e375(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_6000e375(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}



/* VA 6000ba9d */

undefined4 __cdecl FUN_6000ba9d(int param_1,int param_2)

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
     (iVar2 = FUN_6000b9fe(param_1,param_2 + 1), iVar2 == 0)) {
    local_8 = FUN_6000ba47(param_1,param_2 + -1);
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



/* VA 6000bb29 */

void __cdecl FUN_6000bb29(int param_1,undefined4 *param_2)

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



/* VA 6000bb44 */

void __cdecl FUN_6000bb44(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



/* VA 6000bb50 */

undefined4 __cdecl FUN_6000bb50(int *param_1)

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



/* VA 6000bb6b */

void __cdecl FUN_6000bb6b(uint *param_1,uint param_2)

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



/* VA 6000bbf8 */

undefined4 __cdecl FUN_6000bbf8(ushort *param_1,uint *param_2,int *param_3)

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
    iVar2 = FUN_6000bb50((int *)&local_10);
    if (iVar2 != 0) {
LAB_6000bd24:
      uVar5 = 0;
      goto LAB_6000bd26;
    }
    FUN_6000bb44(&local_10);
  }
  else {
    FUN_6000bb29((int)local_1c,&local_10);
    iVar2 = FUN_6000ba9d((int)&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar4 = uVar3 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar4 < iVar2 - param_3[2]) {
      FUN_6000bb44(&local_10);
    }
    else {
      if (iVar2 < iVar4) {
        if (*param_3 <= iVar4) {
          FUN_6000bb44(&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_6000bb6b(&local_10,param_3[3]);
          iVar4 = param_3[5] + *param_3;
          uVar5 = 1;
          goto LAB_6000bd26;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar4 = param_3[5] + iVar4;
        FUN_6000bb6b(&local_10,param_3[3]);
        goto LAB_6000bd24;
      }
      FUN_6000bb29((int)&local_10,local_1c);
      FUN_6000bb6b(&local_10,iVar2 - iVar4);
      FUN_6000ba9d((int)&local_10,param_3[2]);
      FUN_6000bb6b(&local_10,param_3[3] + 1);
    }
  }
  iVar4 = 0;
  uVar5 = 2;
LAB_6000bd26:
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



/* VA 6000bd64 */

void __cdecl FUN_6000bd64(ushort *param_1,uint *param_2)

{
  FUN_6000bbf8(param_1,param_2,(int *)&DAT_6001ce20);
  return;
}



/* VA 6000bd7a */

void __cdecl FUN_6000bd7a(ushort *param_1,uint *param_2)

{
  FUN_6000bbf8(param_1,param_2,(int *)&DAT_6001ce38);
  return;
}



/* VA 6000bd90 */

void __thiscall FUN_6000bd90(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];

  FUN_6000e516(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_6000bd64(local_10,param_1);
  return;
}



/* VA 6000bdbd */

void __thiscall FUN_6000bdbd(void *this,uint *param_1,byte *param_2)

{
  ushort local_10 [6];

  FUN_6000e516(this,local_10,(int *)&param_2,param_2,0,0,0,0);
  FUN_6000bd7a(local_10,param_1);
  return;
}



/* VA 6000bdea */

void __cdecl FUN_6000bdea(char *param_1,int param_2,int param_3)

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
    FUN_6000bfe0((undefined4 *)pcVar1,(undefined4 *)_Str,sVar3 + 1);
  }
  return;
}



/* VA 6000be61 */

int * __cdecl FUN_6000be61(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

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
  FUN_6000bebd(&local_10,&param_1);
  iVar3 = FUN_6000e9e7(local_10,uStack_c,CONCAT22(uVar4,uStack_8),0x11,0,&local_2c);
  puVar2 = param_4;
  piVar1 = param_3;
  param_3[2] = iVar3;
  *param_3 = (int)local_2a;
  param_3[1] = (int)local_2c;
  FUN_6000ad20(param_4,local_28);
  piVar1[3] = (int)puVar2;
  return piVar1;
}



/* VA 6000bebd */

void __cdecl FUN_6000bebd(uint *param_1,uint *param_2)

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



/* VA 6000bf80 */

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



/* VA 6000bfe0 */

undefined4 * __cdecl FUN_6000bfe0(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_6000c197_caseD_2;
        case 3:
          goto switchD_6000c197_caseD_3;
        }
        goto switchD_6000c197_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_6000c197_caseD_0;
      case 1:
        goto switchD_6000c197_caseD_1;
      case 2:
        goto switchD_6000c197_caseD_2;
      case 3:
        goto switchD_6000c197_caseD_3;
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
              goto switchD_6000c197_caseD_2;
            case 3:
              goto switchD_6000c197_caseD_3;
            }
            goto switchD_6000c197_caseD_1;
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
              goto switchD_6000c197_caseD_2;
            case 3:
              goto switchD_6000c197_caseD_3;
            }
            goto switchD_6000c197_caseD_1;
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
              goto switchD_6000c197_caseD_2;
            case 3:
              goto switchD_6000c197_caseD_3;
            }
            goto switchD_6000c197_caseD_1;
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
switchD_6000c197_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_6000c197_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_6000c197_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_6000c197_caseD_0:
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
        goto switchD_6000c015_caseD_2;
      case 3:
        goto switchD_6000c015_caseD_3;
      }
      goto switchD_6000c015_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_6000c015_caseD_0;
    case 1:
      goto switchD_6000c015_caseD_1;
    case 2:
      goto switchD_6000c015_caseD_2;
    case 3:
      goto switchD_6000c015_caseD_3;
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
            goto switchD_6000c015_caseD_2;
          case 3:
            goto switchD_6000c015_caseD_3;
          }
          goto switchD_6000c015_caseD_1;
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
            goto switchD_6000c015_caseD_2;
          case 3:
            goto switchD_6000c015_caseD_3;
          }
          goto switchD_6000c015_caseD_1;
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
            goto switchD_6000c015_caseD_2;
          case 3:
            goto switchD_6000c015_caseD_3;
          }
          goto switchD_6000c015_caseD_1;
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
switchD_6000c015_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_6000c015_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_6000c015_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_6000c015_caseD_0:
  return param_1;
}



/* VA 6000c315 */

/* Library Function - Single Match
    __fptrap

   Library: Visual Studio 2003 Release */

void __cdecl __fptrap(void)

{
  __amsg_exit(2);
  return;
}



/* VA 6000d0ab */

void __cdecl FUN_6000d0ab(uint param_1,int *param_2,ushort *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  uint local_5c [10];
  undefined8 local_34;
  uint local_24;

  param_3 = (ushort *)(uint)*param_3;
  iVar2 = *param_2;
  if (iVar2 == 1) {
LAB_6000d0f0:
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
    if (iVar2 == 5) goto LAB_6000d0f0;
    if (iVar2 == 7) {
      *param_2 = 1;
      goto LAB_6000d146;
    }
    if (iVar2 != 8) goto LAB_6000d146;
    uVar3 = 0x10;
  }
  bVar1 = FUN_6000ef2d(uVar3,(double *)(param_2 + 6),(uint)param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_34 = *(undefined8 *)(param_2 + 4);
      local_24 = local_24 & 0xffffffe3 | 3;
    }
    else {
      local_24 = local_24 & 0xfffffffe;
    }
    FUN_6000ec7a(local_5c,(uint *)&param_3,uVar3,param_1,(undefined8 *)(param_2 + 2),
                 (undefined8 *)(param_2 + 6));
  }
LAB_6000d146:
  FUN_6000f18c();
  if (((*param_2 != 8) && (DAT_6001d1d8 == 0)) && (iVar2 = FUN_6000f16c(), iVar2 != 0)) {
    return;
  }
  FUN_6000f144(*param_2);
  return;
}



/* VA 6000d17b */

float10 __cdecl FUN_6000d17b(undefined8 param_1,short param_2)

{
  undefined8 local_c;

  local_c = (double)CONCAT26((param_2 + 0x3fe) * 0x10 | param_1._6_2_ & 0x800f,(int6)param_1);
  return (float10)local_c;
}



/* VA 6000d1a4 */

undefined4 __cdecl FUN_6000d1a4(int param_1,uint param_2)

{
  undefined4 uStack_8;

  if (param_2 == 0x7ff00000) {
    if (param_1 == 0) {
      return 1;
    }
  }
  else if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    uStack_8 = 3;
  }
  else {
    if (((param_2._2_2_ & 0x7ff8) != 0x7ff0) || (((param_2 & 0x7ffff) == 0 && (param_1 == 0)))) {
      return 0;
    }
    uStack_8 = 4;
  }
  return uStack_8;
}



/* VA 6000d1fe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_6000d1fe(uint param_1,uint param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  float10 fVar5;
  undefined8 local_c;

  if ((double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))) ==
      _DAT_60012da0) {
    iVar4 = 0;
    local_c = 0.0;
  }
  else if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    iVar4 = -0x3fd;
    if (_DAT_60012da0 <=
        (double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1)))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    while ((param_2._2_1_ & 0x10) == 0) {
      iVar2 = CONCAT13(param_2._3_1_,CONCAT12(param_2._2_1_,(ushort)param_2)) << 1;
      param_2._0_2_ = (ushort)iVar2;
      param_2._2_1_ = (byte)((uint)iVar2 >> 0x10);
      param_2._3_1_ = (byte)((uint)iVar2 >> 0x18);
      if ((param_1 & 0x80000000) != 0) {
        param_2._0_2_ = (ushort)param_2 | 1;
      }
      param_1 = param_1 << 1;
      iVar4 = iVar4 + -1;
    }
    uVar1 = CONCAT11(param_2._3_1_,param_2._2_1_) & 0xffef;
    param_2._2_1_ = (byte)uVar1;
    param_2._3_1_ = (byte)(uVar1 >> 8);
    if (bVar3) {
      param_2._3_1_ = param_2._3_1_ | 0x80;
    }
    fVar5 = FUN_6000d17b(CONCAT17(param_2._3_1_,
                                  CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))),0);
    local_c = (double)fVar5;
  }
  else {
    fVar5 = FUN_6000d17b(CONCAT17(param_2._3_1_,
                                  CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))),0);
    local_c = (double)fVar5;
    iVar4 = (short)((ushort)(param_2 >> 0x14) & 0x7ff) + -0x3fe;
  }
  *param_3 = iVar4;
  return (float10)local_c;
}



/* VA 6000d2bf */

/* Library Function - Single Match
    __frnd

   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2019 Release */

float10 __cdecl __frnd(double param_1)

{
  return (float10)ROUND(param_1);
}



/* VA 6000d2d1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_6000d2d1(int param_1,uint param_2)

{
  int iVar1;

  if ((param_2._2_2_ & 0x7ff0) == 0x7ff0) {
    iVar1 = FUN_6000d1a4(param_1,(uint)(CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)
                                                ) >> 0x20));
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        iVar1 = 4;
      }
      else if (iVar1 == 3) {
        iVar1 = 2;
      }
      else {
        iVar1 = 1;
      }
      return iVar1;
    }
    return 0x200;
  }
  if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffff90) + 0x80;
  }
  if ((double)CONCAT26(param_2._2_2_,CONCAT24((undefined2)param_2,param_1)) == _DAT_60012da0) {
    return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffffe0) + 0x40;
  }
  return (-(uint)((param_2 & 0x80000000) != 0) & 0xffffff08) + 0x100;
}



/* VA 6000d363 */

int __cdecl
FUN_6000d363(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
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
  puStack_c = &DAT_60012ec0;
  puStack_10 = &LAB_6000d704;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffb0;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffb0;
  if (DAT_6001dc30 == 0) {
    ExceptionList = &local_14;
    iVar2 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar2 == 0) {
      iVar2 = CompareStringA(0,0,"",1,"",1);
      if (iVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_6001dc30 = 2;
      puVar1 = local_1c;
    }
    else {
      DAT_6001dc30 = 1;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  if (0 < param_4) {
    param_4 = FUN_6000d5e0((char *)param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_6000d5e0((char *)param_5,param_6);
  }
  if (DAT_6001dc30 == 2) {
    iVar2 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
    ExceptionList = local_14;
    return iVar2;
  }
  if (DAT_6001dc30 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_6001dc4c;
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
      FUN_6000d7e0();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x50) &&
         (local_28 = (PCNZWCH)&stack0xffffffb0, local_1c = &stack0xffffffb0,
         iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,(LPWSTR)&stack0xffffffb0,
                                     local_20), iVar2 != 0)) {
        iVar2 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          local_8 = 1;
          local_24 = iVar2;
          FUN_6000d7e0();
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



/* VA 6000d5e0 */

int __cdecl FUN_6000d5e0(char *param_1,int param_2)

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



/* VA 6000d60c */

/* Library Function - Single Match
    __global_unwind2

   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x6000d624,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



/* VA 6000d64e */

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
  puStack_18 = &LAB_6000d62c;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_6000d6e2();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}



/* VA 6000d6e2 */

void FUN_6000d6e2(void)

{
  undefined4 in_EAX;
  int unaff_EBP;

  DAT_6001cfe0 = *(undefined4 *)(unaff_EBP + 8);
  DAT_6001cfdc = in_EAX;
  DAT_6001cfe4 = unaff_EBP;
  return;
}



/* VA 6000d7c1 */

void FUN_6000d7c1(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



/* VA 6000d7e0 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_6000d7e0(void)

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



/* VA 6000d80f */

DWORD __cdecl FUN_6000d80f(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_600205a0) &&
     ((*(byte *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_6000f34b(param_1);
    DVar1 = FUN_6000d874(param_1,param_2,param_3);
    FUN_6000f3aa(param_1);
    return DVar1;
  }
  pDVar2 = FUN_6000f278();
  *pDVar2 = 9;
  pDVar2 = FUN_6000f281();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 6000d874 */

DWORD __cdecl FUN_6000d874(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;

  hFile = (HANDLE)FUN_6000f309(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_6000f278();
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
      pbVar1 = (byte *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_6000f205(uVar4);
  }
  return 0xffffffff;
}



/* VA 6000d8e7 */

int __cdecl FUN_6000d8e7(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_600205a0) &&
     ((*(byte *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_6000f34b(param_1);
    iVar1 = FUN_6000d94c(param_1,param_2,param_3);
    FUN_6000f3aa(param_1);
    return iVar1;
  }
  pDVar2 = FUN_6000f278();
  *pDVar2 = 9;
  pDVar2 = FUN_6000f281();
  *pDVar2 = 0;
  return -1;
}



/* VA 6000d94c */

int __cdecl FUN_6000d94c(DWORD param_1,char *param_2,uint param_3)

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
LAB_6000d965:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_600204a0 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_6000d874(param_1,0,2);
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
LAB_6000da34:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_6000daa6;
      if (param_1 == 5) {
        pDVar7 = FUN_6000f278();
        *pDVar7 = 9;
        pDVar7 = FUN_6000f281();
        *pDVar7 = 5;
      }
      else {
        FUN_6000f205(param_1);
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
            goto LAB_6000da34;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_6000da34;
        } while( true );
      }
LAB_6000daa6:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_6000d965;
      pDVar7 = FUN_6000f278();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_6000f281();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}



/* VA 6000dad7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_6000dad7(undefined4 *param_1)

{
  void *pvVar1;

  _DAT_6001dc0c = _DAT_6001dc0c + 1;
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



/* VA 6000db1b */

byte __cdecl FUN_6000db1b(uint param_1)

{
  if (DAT_600205a0 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}



/* VA 6000db44 */

int __cdecl FUN_6000db44(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;

  InterlockedIncrement((LONG *)&DAT_6001f228);
  bVar2 = DAT_6001f224 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_6001f228);
    FUN_60008d89(0x13);
  }
  iVar1 = FUN_6000db9d(param_1,param_2);
  if (bVar2) {
    FUN_60008dea(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_6001f228);
  }
  return iVar1;
}



/* VA 6000db9d */

int __cdecl FUN_6000db9d(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  DWORD *pDVar2;

  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_6001dc3c == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_6001dc4c,0x220,&param_2,1,lpMultiByteStr,DAT_6001c7dc,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  pDVar2 = FUN_6000f278();
  *pDVar2 = 0x2a;
  return -1;
}



/* VA 6000dc10 */

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



/* VA 6000dc80 */

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



/* VA 6000dd76 */

int __cdecl FUN_6000dd76(int *param_1)

{
  int iVar1;

  iVar1 = FUN_6000dda4(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_6000f449(param_1[4]);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}



/* VA 6000dda4 */

undefined4 __cdecl FUN_6000dda4(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;

  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    if (0 < (int)uVar3) {
      uVar1 = FUN_6000d8e7(param_1[4],(char *)param_1[2],uVar3);
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



/* VA 6000de09 */

int __cdecl FUN_6000de09(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;

  iVar3 = 0;
  iVar5 = 0;
  FUN_60008d89(2);
  iVar4 = 0;
  if (0 < DAT_60020480) {
    do {
      iVar2 = *(int *)(DAT_6001f460 + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_60009bfc(iVar4,iVar2);
        piVar1 = *(int **)(DAT_6001f460 + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_6000dd76(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_6000dd76(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_60009c4e(iVar4,*(int *)(DAT_6001f460 + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_60020480);
  }
  FUN_60008dea(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}



/* VA 6000dead */

void __cdecl FUN_6000dead(short *param_1,short *param_2)

{
  short sVar1;

  sVar1 = *param_2;
  *param_1 = sVar1;
  while( true ) {
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    if (sVar1 == 0) break;
    sVar1 = *param_2;
    *param_1 = sVar1;
  }
  return;
}



/* VA 6000ded2 */

int __cdecl FUN_6000ded2(short *param_1)

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



/* VA 6000deef */

undefined4 FUN_6000deef(void)

{
  LPCSTR lpMultiByteStr;
  int iVar1;
  PCNZWCH lpWideCharStr;
  undefined4 *puVar2;

  lpMultiByteStr = (LPCSTR)*DAT_6001da74;
  puVar2 = DAT_6001da74;
  while( true ) {
    if (lpMultiByteStr == (LPCSTR)0x0) {
      return 0;
    }
    iVar1 = MultiByteToWideChar(1,0,lpMultiByteStr,-1,(LPWSTR)0x0,0);
    if (((iVar1 == 0) || (lpWideCharStr = _malloc(iVar1 * 2), lpWideCharStr == (PCNZWCH)0x0)) ||
       (iVar1 = MultiByteToWideChar(1,0,(LPCSTR)*puVar2,-1,lpWideCharStr,iVar1), iVar1 == 0)) break;
    FUN_6000a882(lpWideCharStr,0);
    lpMultiByteStr = (LPCSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}



/* VA 6000df57 */

uint __cdecl FUN_6000df57(short *param_1,short param_2)

{
  while( true ) {
    if ((*param_1 == 0) || (*param_1 == param_2)) break;
    param_1 = param_1 + 1;
  }
  return (uint)param_1 & ~-(uint)(*param_1 != param_2);
}



/* VA 6000df80 */

int __cdecl FUN_6000df80(PCNZWCH param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  DWORD *pDVar2;
  bool bVar3;

  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    if (DAT_6001dc38 != 0) {
      InterlockedIncrement((LONG *)&DAT_6001f228);
      bVar3 = DAT_6001f224 == 0;
      if (!bVar3) {
        InterlockedDecrement((LONG *)&DAT_6001f228);
        FUN_60008d89(0x13);
      }
      if (DAT_6001dc38 != 0) {
        iVar1 = FUN_6000f4dc(DAT_6001dc38,0x1001,param_1,param_3,param_2,param_3,DAT_6001dc50);
        if (iVar1 == 0) {
          if (bVar3) {
            InterlockedDecrement((LONG *)&DAT_6001f228);
          }
          else {
            FUN_60008dea(0x13);
          }
          pDVar2 = FUN_6000f278();
          *pDVar2 = 0x16;
          return 0x7fffffff;
        }
        if (bVar3) {
          InterlockedDecrement((LONG *)&DAT_6001f228);
        }
        else {
          FUN_60008dea(0x13);
        }
        return iVar1 + -2;
      }
      if (bVar3) {
        InterlockedDecrement((LONG *)&DAT_6001f228);
      }
      else {
        FUN_60008dea(0x13);
      }
    }
    iVar1 = FUN_6000f727((ushort *)param_1,(ushort *)param_2,param_3);
  }
  return iVar1;
}



/* VA 6000e061 */

undefined4 __cdecl FUN_6000e061(short *param_1)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;

  if (param_1 != (short *)0x0) {
    iVar1 = FUN_6000ded2(param_1);
    psVar2 = _malloc(iVar1 * 2 + 2);
    if (psVar2 != (short *)0x0) {
      uVar3 = FUN_6000dead(psVar2,param_1);
      return uVar3;
    }
  }
  return 0;
}



/* VA 6000e08f */

uint * __cdecl FUN_6000e08f(uint *param_1,uint param_2)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;

  if (DAT_6001f23c == 0) {
    puVar2 = FUN_60008c00(param_1,(char)param_2);
  }
  else {
    FUN_60008d89(0x19);
    while( true ) {
      bVar1 = (byte)*param_1;
      uVar3 = (uint)bVar1;
      if (bVar1 == 0) break;
      if ((*(byte *)((int)&DAT_6001f340 + uVar3 + 1) & 4) == 0) {
        puVar2 = param_1;
        if (param_2 == uVar3) break;
      }
      else {
        puVar2 = (uint *)((int)param_1 + 1);
        if (*(byte *)((int)param_1 + 1) == 0) {
          FUN_60008dea(0x19);
          return (uint *)0x0;
        }
        if (param_2 == CONCAT11(bVar1,*(byte *)((int)param_1 + 1))) {
          FUN_60008dea(0x19);
          return param_1;
        }
      }
      param_1 = (uint *)((int)puVar2 + 1);
    }
    FUN_60008dea(0x19);
    puVar2 = (uint *)(~-(uint)(param_2 != uVar3) & (uint)param_1);
  }
  return puVar2;
}



/* VA 6000e126 */

uint * __cdecl FUN_6000e126(uint *param_1)

{
  size_t sVar1;
  uint *puVar2;

  if (param_1 != (uint *)0x0) {
    sVar1 = _strlen((char *)param_1);
    puVar2 = _malloc(sVar1 + 1);
    if (puVar2 != (uint *)0x0) {
      puVar2 = FUN_6000ad20(puVar2,param_1);
      return puVar2;
    }
  }
  return (uint *)0x0;
}



/* VA 6000e151 */

int __cdecl
FUN_6000e151(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_60012ed8;
  puStack_10 = &LAB_6000d704;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_6001dc54 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_6001dc54 = 2;
    }
    else {
      DAT_6001dc54 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_6000d5e0(param_3,param_4);
  }
  if (DAT_6001dc54 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_6001dc54 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_6001dc4c;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_6000d7e0();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((param_2 & 0x400) == 0) {
            local_8 = 1;
            FUN_6000d7e0();
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



/* VA 6000e375 */

undefined4 __cdecl FUN_6000e375(uint param_1,uint param_2,uint *param_3)

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



/* VA 6000e396 */

/* Library Function - Single Match
    ___add_12

   Library: Visual Studio 2003 Release */

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;

  iVar1 = FUN_6000e375(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_6000e375(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_6000e375(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_6000e375(param_1[2],param_2[2],param_1 + 2);
  return;
}



/* VA 6000e3f4 */

void __cdecl FUN_6000e3f4(uint *param_1)

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



/* VA 6000e422 */

void __cdecl FUN_6000e422(uint *param_1)

{
  uint uVar1;

  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}



/* VA 6000e44f */

void __cdecl FUN_6000e44f(char *param_1,int param_2,uint *param_3)

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
      FUN_6000e3f4(puVar1);
      FUN_6000e3f4(puVar1);
      ___add_12(puVar1,&local_14);
      FUN_6000e3f4(puVar1);
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
    FUN_6000e3f4(puVar1);
    local_8 = local_8 + 0xffff;
  }
  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_8;
  return;
}



/* VA 6000e516 */

undefined4 __thiscall
FUN_6000e516(void *this,ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,
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
LAB_6000e56d:
  local_14 = iVar5;
  pbVar7 = pbVar8;
  iVar5 = 1;
  bVar6 = *pbVar7;
  pbVar8 = pbVar7 + 1;
  iVar2 = local_14;
  switch(iVar9) {
  case 0:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_6000e58a:
      local_14 = iVar2;
      iVar9 = 3;
      goto LAB_6000e7af;
    }
    if (bVar6 == DAT_6001c7e0) goto LAB_6000e599;
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
      if (bVar6 != 0x30) goto LAB_6000e889;
    }
    goto LAB_6000e56d;
  case 1:
    local_14 = 1;
    if (('0' < (char)bVar6) && (iVar2 = iVar5, (char)bVar6 < ':')) goto LAB_6000e58a;
    iVar9 = iVar1;
    if (bVar6 != DAT_6001c7e0) {
      iVar9 = iVar5;
      if ((bVar6 == 0x2b) || (iVar9 = local_14, bVar6 == 0x2d)) goto LAB_6000e61e;
      iVar9 = iVar5;
      local_14 = iVar5;
      if (bVar6 != 0x30) goto LAB_6000e5f7;
    }
    goto LAB_6000e56d;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_6000e58a;
    if (bVar6 == DAT_6001c7e0) {
LAB_6000e599:
      iVar9 = 5;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      pbVar7 = param_3;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_6000e88e;
    }
    goto LAB_6000e56d;
  case 3:
    local_14 = iVar5;
    while( true ) {
      if (DAT_6001c7dc < 2) {
        uVar3 = (byte)PTR_DAT_6001c5d0[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_6001c5d0;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_60007114(this,(uint)bVar6,4);
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
    if (bVar6 != DAT_6001c7e0) goto LAB_6000e70b;
    goto LAB_6000e56d;
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
      if (DAT_6001c7dc < 2) {
        uVar3 = (byte)PTR_DAT_6001c5d0[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_6001c5d0;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_60007114(this,(uint)bVar6,4);
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
LAB_6000e70b:
    iVar9 = local_14;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {
LAB_6000e61e:
      local_14 = iVar9;
      iVar9 = 0xb;
      pbVar8 = pbVar8 + -1;
      iVar5 = local_14;
    }
    else {
LAB_6000e5f7:
      if (((char)bVar6 < 'D') ||
         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_6000e889;
      iVar9 = 6;
      iVar5 = local_14;
    }
    goto LAB_6000e56d;
  case 5:
    local_28 = iVar5;
    if (DAT_6001c7dc < 2) {
      uVar3 = (byte)PTR_DAT_6001c5d0[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_6001c5d0;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_60007114(this,(uint)bVar6,4);
      this = pbVar7;
    }
    iVar9 = iVar1;
    pbVar7 = param_3;
    if (uVar3 != 0) goto LAB_6000e7af;
    goto LAB_6000e88e;
  case 6:
    pbVar7 = pbVar7 + -1;
    this = pbVar7;
    param_3 = pbVar7;
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == 0x2b) goto LAB_6000e7e4;
      if (bVar6 == 0x2d) goto LAB_6000e7d8;
      if (bVar6 != 0x30) goto LAB_6000e88e;
LAB_6000e77d:
      iVar9 = 8;
      iVar5 = local_14;
      goto LAB_6000e56d;
    }
    break;
  case 7:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      pbVar7 = param_3;
      if (bVar6 == 0x30) goto LAB_6000e77d;
      goto LAB_6000e88e;
    }
    break;
  case 8:
    local_24 = 1;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_6000e889;
    break;
  case 9:
    local_24 = 1;
    pbVar7 = (byte *)0x0;
    goto LAB_6000e80f;
  default:
    goto switchD_6000e579_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      if (bVar6 == 0x2b) {
LAB_6000e7e4:
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      else {
        param_3 = pbVar7;
        if (bVar6 != 0x2d) goto LAB_6000e88e;
LAB_6000e7d8:
        local_1c = -1;
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      goto LAB_6000e56d;
    }
    iVar9 = 10;
    pbVar8 = pbVar7;
switchD_6000e579_caseD_a:
    pbVar7 = pbVar8;
    iVar5 = local_14;
    if (iVar9 != 10) goto LAB_6000e56d;
    goto LAB_6000e88e;
  }
  iVar9 = 9;
LAB_6000e7af:
  pbVar8 = pbVar8 + -1;
  iVar5 = local_14;
  goto LAB_6000e56d;
LAB_6000e80f:
  if (DAT_6001c7dc < 2) {
    uVar3 = (byte)PTR_DAT_6001c5d0[(uint)bVar6 * 2] & 4;
    this = PTR_DAT_6001c5d0;
  }
  else {
    pbVar10 = (byte *)0x4;
    uVar3 = FUN_60007114(this,(uint)bVar6,4);
    this = pbVar10;
  }
  if (uVar3 == 0) goto LAB_6000e859;
  this = (void *)(int)(char)bVar6;
  pbVar7 = (byte *)((int)this + (int)pbVar7 * 10 + -0x30);
  if (0x1450 < (int)pbVar7) goto LAB_6000e851;
  bVar6 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  goto LAB_6000e80f;
LAB_6000e851:
  pbVar7 = (byte *)0x1451;
LAB_6000e859:
  while( true ) {
    local_20 = pbVar7;
    if (DAT_6001c7dc < 2) {
      uVar3 = (byte)PTR_DAT_6001c5d0[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_6001c5d0;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_60007114(this,(uint)bVar6,4);
      this = pbVar7;
    }
    if (uVar3 == 0) break;
    bVar6 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar7 = local_20;
  }
LAB_6000e889:
  pbVar7 = pbVar8 + -1;
LAB_6000e88e:
  *param_2 = (int)pbVar7;
  if (local_14 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
    local_18 = 4;
    goto LAB_6000e99c;
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
    FUN_6000e44f(local_60,local_8,(uint *)&local_44);
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
        FUN_6000fb8a((int *)&local_44,(uint)pbVar8,param_4);
        param_3 = (byte *)CONCAT22(uStack_40,uStack_42);
        goto LAB_6000e921;
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
LAB_6000e921:
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
LAB_6000e99c:
  *(byte **)(param_1 + 3) = local_3e;
  *(byte **)(param_1 + 1) = param_3;
  param_1[5] = local_3a | (ushort)local_2c;
  *param_1 = local_44;
  return local_18;
}



/* VA 6000e9e7 */

undefined4 __cdecl
FUN_6000e9e7(uint param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

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
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_6000eadc;
          pcVar11 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_6000eadc:
            pcVar11 = "1#QNAN";
            goto LAB_6000eae1;
          }
          pcVar11 = "1#IND";
        }
        FUN_6000ad20((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 5;
      }
      else {
        pcVar11 = "1#SNAN";
LAB_6000eae1:
        FUN_6000ad20((uint *)(param_6 + 2),(uint *)pcVar11);
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
    FUN_6000fb8a((int *)&local_14,-(int)sVar8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar8 = sVar8 + 1;
      FUN_6000f96a((int *)&local_14,(int *)&local_20);
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
        FUN_6000e3f4((uint *)&local_14);
        param_6 = (short *)((int)param_6 + -1);
      } while (param_6 != (short *)0x0);
      if (iVar9 < 0) {
        param_6 = (short *)0x0;
        for (uVar5 = -iVar9 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
          FUN_6000e422((uint *)&local_14);
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
          FUN_6000e3f4((uint *)&local_14);
          FUN_6000e3f4((uint *)&local_14);
          ___add_12((uint *)&local_14,&param_1);
          FUN_6000e3f4((uint *)&local_14);
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
            if (psVar1 <= psVar7) goto LAB_6000ec39;
            break;
          }
          *(char *)psVar7 = '0';
        }
        psVar7 = (short *)((int)psVar7 + 1);
        *psVar3 = *psVar3 + 1;
LAB_6000ec39:
        *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_6000ec3b:
        cVar4 = ((char)psVar7 - (char)psVar3) + -3;
        *(char *)((int)psVar3 + 3) = cVar4;
        *(undefined1 *)(cVar4 + 4 + (int)psVar3) = 0;
        return local_8;
      }
      for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
        if ((char)*psVar7 != '0') {
          if (psVar1 <= psVar7) goto LAB_6000ec3b;
          break;
        }
      }
      *psVar3 = 0;
      *(undefined1 *)(psVar3 + 1) = 0x20;
      *(undefined1 *)((int)psVar3 + 3) = 1;
      *(char *)psVar1 = '0';
      goto LAB_6000ec71;
    }
  }
  *psVar3 = 0;
  *(undefined1 *)(psVar3 + 1) = 0x20;
  *(undefined1 *)((int)psVar3 + 3) = 1;
  *(undefined1 *)(psVar3 + 2) = 0x30;
LAB_6000ec71:
  *(undefined1 *)((int)psVar3 + 5) = 0;
  return 1;
}



/* VA 6000ec7a */

void __cdecl
FUN_6000ec7a(uint *param_1,uint *param_2,uint param_3,uint param_4,undefined8 *param_5,
            undefined8 *param_6)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;

  uVar3 = param_3;
  puVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 & 0x10) != 0) {
    param_3 = 0xc000008f;
    param_1[1] = param_1[1] | 1;
  }
  if ((uVar3 & 2) != 0) {
    param_3 = 0xc0000093;
    param_1[1] = param_1[1] | 2;
  }
  if ((uVar3 & 1) != 0) {
    param_3 = 0xc0000091;
    param_1[1] = param_1[1] | 4;
  }
  if ((uVar3 & 4) != 0) {
    param_3 = 0xc000008e;
    param_1[1] = param_1[1] | 8;
  }
  if ((uVar3 & 8) != 0) {
    param_3 = 0xc0000090;
    param_1[1] = param_1[1] | 0x10;
  }
  param_1[2] = (~*param_2 & 1) << 4 | param_1[2] & 0xffffffef;
  param_1[2] = (~*param_2 & 4) << 1 | param_1[2] & 0xfffffff7;
  param_1[2] = ~*param_2 >> 1 & 4 | param_1[2] & 0xfffffffb;
  param_1[2] = ~*param_2 >> 3 & 2 | param_1[2] & 0xfffffffd;
  param_1[2] = ~*param_2 >> 5 & 1 | param_1[2] & 0xfffffffe;
  uVar3 = FUN_6000f16f();
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
        goto LAB_6000edef;
      }
      uVar3 = *param_1 & 0xfffffffe | 2;
    }
    *param_1 = uVar3;
  }
LAB_6000edef:
  uVar3 = *puVar1 & 0x300;
  if (uVar3 == 0) {
    uVar3 = *param_1 & 0xffffffeb | 8;
LAB_6000ee25:
    *param_1 = uVar3;
  }
  else {
    if (uVar3 == 0x200) {
      uVar3 = *param_1 & 0xffffffe7 | 4;
      goto LAB_6000ee25;
    }
    if (uVar3 == 0x300) {
      *param_1 = *param_1 & 0xffffffe3;
    }
  }
  *param_1 = (param_4 & 0xfff) << 5 | *param_1 & 0xfffe001f;
  param_1[8] = param_1[8] | 1;
  param_1[8] = param_1[8] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 4) = *param_5;
  param_1[0x14] = param_1[0x14] | 1;
  param_1[0x14] = param_1[0x14] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 0x10) = *param_6;
  FUN_6000f17d();
  RaiseException(param_3,0,1,(ULONG_PTR *)&param_1);
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
          *(byte *)((int)puVar1 + 1) = *(byte *)((int)puVar1 + 1) | 0xc;
        }
        goto LAB_6000eefa;
      }
      uVar3 = *puVar1 & 0xfffffbff | 0x800;
    }
    *puVar1 = uVar3;
  }
LAB_6000eefa:
  uVar3 = *param_1 >> 2 & 7;
  if (uVar3 == 0) {
    uVar3 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else {
    if (uVar3 != 1) {
      if (uVar3 == 2) {
        *puVar1 = *puVar1 & 0xfffff3ff;
      }
      goto LAB_6000ef23;
    }
    uVar3 = *puVar1 & 0xfffff3ff | 0x200;
  }
  *puVar1 = uVar3;
LAB_6000ef23:
  *puVar2 = *(undefined8 *)(param_1 + 0x10);
  return;
}



/* VA 6000ef2d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl FUN_6000ef2d(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  float10 fVar5;
  undefined8 local_10;
  int local_8;

  uVar3 = param_1 & 0x1f;
  bVar2 = true;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_6000f1af();
    uVar3 = param_1 & 0x17;
    goto LAB_6000f122;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_6000f1af();
    uVar3 = param_1 & 0x1b;
    goto LAB_6000f122;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar4 = (param_1 & 0x10) != 0;
      dVar1 = *param_2;
      if (dVar1 != _DAT_60012da0) {
        fVar5 = FUN_6000d1fe(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20),&local_8);
        local_8 = local_8 + -0x600;
        if (local_8 < -0x432) {
          local_10 = 0.0;
          bVar4 = bVar2;
        }
        else {
          local_10 = (double)(ulonglong)
                             (SUB87((double)fVar5,0) & 0xfffffffffffff | 0x10000000000000);
          if (local_8 < -0x3fd) {
            local_8 = -0x3fd - local_8;
            do {
              if ((((ulonglong)local_10 & 1) != 0) && (!bVar4)) {
                bVar4 = bVar2;
              }
              uVar3 = (uint)local_10 >> 1;
              if (((ulonglong)local_10 & 0x100000000) != 0) {
                local_10._3_1_ = (byte)((ulonglong)local_10 >> 0x18) >> 1;
                local_10._0_3_ = (undefined3)uVar3;
                local_10._0_4_ = CONCAT13(local_10._3_1_,(undefined3)local_10) | 0x80000000;
                uVar3 = (uint)local_10;
              }
              local_10._0_4_ = uVar3;
              local_10 = (double)CONCAT44(local_10._4_4_ >> 1,(uint)local_10);
              local_8 = local_8 + -1;
            } while (local_8 != 0);
          }
          if ((double)fVar5 < _DAT_60012da0) {
            local_10 = -local_10;
          }
        }
        *param_2 = local_10;
        bVar2 = bVar4;
      }
      if (bVar2) {
        FUN_6000f1af();
      }
      uVar3 = param_1 & 0x1d;
    }
    goto LAB_6000f122;
  }
  FUN_6000f1af();
  uVar3 = param_3 & 0xc00;
  dVar1 = _DAT_6001cfb0;
  if (uVar3 == 0) {
    if (*param_2 <= _DAT_60012da0) {
      dVar1 = -_DAT_6001cfb0;
    }
LAB_6000f042:
    *param_2 = dVar1;
  }
  else {
    if (uVar3 == 0x400) {
      dVar1 = _DAT_6001cfc0;
      if (*param_2 <= _DAT_60012da0) {
        dVar1 = -_DAT_6001cfb0;
      }
      goto LAB_6000f042;
    }
    if (uVar3 == 0x800) {
      if (*param_2 <= _DAT_60012da0) {
        dVar1 = -_DAT_6001cfc0;
      }
      goto LAB_6000f042;
    }
    if (uVar3 == 0xc00) {
      dVar1 = _DAT_6001cfc0;
      if (*param_2 <= _DAT_60012da0) {
        dVar1 = -_DAT_6001cfc0;
      }
      goto LAB_6000f042;
    }
  }
  uVar3 = param_1 & 0x1e;
LAB_6000f122:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_6000f1af();
    uVar3 = uVar3 & 0xffffffef;
  }
  return uVar3 == 0;
}



/* VA 6000f144 */

void __cdecl FUN_6000f144(int param_1)

{
  DWORD *pDVar1;

  if (param_1 == 1) {
    pDVar1 = FUN_6000f278();
    *pDVar1 = 0x21;
  }
  else if ((1 < param_1) && (param_1 < 4)) {
    pDVar1 = FUN_6000f278();
    *pDVar1 = 0x22;
    return;
  }
  return;
}



/* VA 6000f16c */

undefined4 FUN_6000f16c(void)

{
  return 0;
}



/* VA 6000f16f */

int FUN_6000f16f(void)

{
  short in_FPUStatusWord;

  return (int)in_FPUStatusWord;
}



/* VA 6000f17d */

int FUN_6000f17d(void)

{
  short in_FPUStatusWord;

  return (int)in_FPUStatusWord;
}



/* VA 6000f18c */

int FUN_6000f18c(void)

{
  short in_FPUControlWord;

  return (int)in_FPUControlWord;
}



/* VA 6000f1af */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6000f1af(void)

{
  return;
}



/* VA 6000f205 */

void __cdecl FUN_6000f205(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;

  pDVar1 = FUN_6000f281();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_6001d1f8;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_6000f278();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x6001d1fc);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x6001d360);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_6000f278();
    *pDVar1 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    pDVar1 = FUN_6000f278();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_6000f278();
  *pDVar1 = 0x16;
  return;
}



/* VA 6000f278 */

DWORD * FUN_6000f278(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_60007641();
  return pDVar1 + 2;
}



/* VA 6000f281 */

DWORD * FUN_6000f281(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_60007641();
  return pDVar1 + 3;
}



/* VA 6000f28a */

undefined4 __cdecl FUN_6000f28a(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;

  if (param_1 < DAT_600205a0) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_600204a0)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_6001da48 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_6000f2e6;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_6000f2e6:
      *(undefined4 *)((&DAT_600204a0)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_6000f278();
  *pDVar2 = 9;
  pDVar2 = FUN_6000f281();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 6000f309 */

undefined4 __cdecl FUN_6000f309(uint param_1)

{
  DWORD *pDVar1;

  if ((param_1 < DAT_600205a0) &&
     ((*(byte *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_600204a0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_6000f278();
  *pDVar1 = 9;
  pDVar1 = FUN_6000f281();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* VA 6000f34b */

void __cdecl FUN_6000f34b(uint param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_600204a0)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_60008d89(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_60008dea(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_600204a0)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}



/* VA 6000f3aa */

void __cdecl FUN_6000f3aa(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_600204a0)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



/* VA 6000f3cc */

undefined4 __cdecl FUN_6000f3cc(FILE *param_1)

{
  undefined4 uVar1;

  uVar1 = 0xffffffff;
  if ((param_1->_flag & 0x40) == 0) {
    FUN_60009bcd((uint)param_1);
    uVar1 = __fclose_lk(param_1);
    FUN_60009c1f((uint)param_1);
  }
  else {
    param_1->_flag = 0;
  }
  return uVar1;
}



/* VA 6000f3fd */

/* Library Function - Single Match
    __fclose_lk

   Library: Visual Studio 2003 Release */

undefined4 __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;

  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_6000dda4((int *)param_1);
    __freebuf(param_1);
    iVar1 = FUN_6000fc06(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      FUN_600074bf(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}



/* VA 6000f449 */

undefined4 __cdecl FUN_6000f449(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;

  if (DAT_600205a0 <= param_1) {
LAB_6000f4ca:
    pDVar3 = FUN_6000f278();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_6000f4ca;
  FUN_6000f34b(param_1);
  if ((*(byte *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_6000f309(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_6000f4bf;
    pDVar3 = FUN_6000f281();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_6000f278();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_6000f4bf:
  FUN_6000f3aa(param_1);
  return uVar5;
}



/* VA 6000f4dc */

int __cdecl
FUN_6000f4dc(LCID param_1,DWORD param_2,PCNZWCH param_3,int param_4,LPCWSTR param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_60012fc8;
  puStack_10 = &LAB_6000d704;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_6001dc78 == 0) {
    ExceptionList = &local_14;
    iVar1 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringA(0,0,"",1,"",1);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_6001dc78 = 2;
    }
    else {
      DAT_6001dc78 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_6000f6f7(param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_6000f6f7(param_5,param_6);
  }
  if ((param_4 != 0) && (param_6 != 0)) {
    if (DAT_6001dc78 == 1) {
      iVar1 = CompareStringW(param_1,param_2,param_3,param_4,param_5,param_6);
      ExceptionList = local_14;
      return iVar1;
    }
    if (DAT_6001dc78 == 2) {
      if (param_7 == 0) {
        param_7 = DAT_6001dc4c;
      }
      iVar1 = WideCharToMultiByte(param_7,0x220,param_3,param_4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                 );
      if (iVar1 != 0) {
        local_8 = 0;
        FUN_6000d7e0();
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (iVar2 = WideCharToMultiByte(param_7,0x220,param_3,param_4,&stack0xffffffc8,iVar1,
                                        (LPCSTR)0x0,(LPBOOL)0x0), iVar2 != 0)) {
          iVar2 = WideCharToMultiByte(param_7,0x220,param_5,param_6,(LPSTR)0x0,0,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
          if (iVar2 != 0) {
            local_8 = 1;
            FUN_6000d7e0();
            local_8 = 0xffffffff;
            if ((&stack0x00000000 != (undefined1 *)0x38) &&
               (iVar3 = WideCharToMultiByte(param_7,0x220,param_5,param_6,&stack0xffffffc8,iVar2,
                                            (LPCSTR)0x0,(LPBOOL)0x0), iVar3 != 0)) {
              iVar1 = CompareStringA(param_1,param_2,&stack0xffffffc8,iVar1,&stack0xffffffc8,iVar2);
              ExceptionList = local_14;
              return iVar1;
            }
          }
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_4 != param_6) {
    ExceptionList = local_14;
    return ((-1 < param_4 - param_6) - 1 & 0xfffffffe) + 3;
  }
  ExceptionList = local_14;
  return 2;
}



/* VA 6000f6f7 */

int __cdecl FUN_6000f6f7(short *param_1,int param_2)

{
  short *psVar1;
  int iVar2;

  iVar2 = param_2;
  for (psVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *psVar1 != 0)); psVar1 = psVar1 + 1) {
  }
  if (*psVar1 != 0) {
    return param_2;
  }
  return (int)psVar1 - (int)param_1 >> 1;
}



/* VA 6000f727 */

int __cdecl FUN_6000f727(ushort *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  bool bVar6;
  bool bVar7;

  iVar2 = 0;
  if (param_3 != 0) {
    if (DAT_6001dc3c == 0) {
      do {
        uVar1 = *param_1;
        puVar4 = (ushort *)(uint)uVar1;
        if ((uVar1 < 0x5b) && (0x40 < uVar1)) {
          puVar4 = puVar4 + 0x10;
        }
        uVar1 = *param_2;
        puVar3 = (ushort *)(uint)uVar1;
        if ((uVar1 < 0x5b) && (0x40 < uVar1)) {
          puVar3 = puVar3 + 0x10;
        }
        puVar5 = param_1 + 1;
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (((param_3 != 0) && ((short)puVar4 != 0)) &&
              (param_1._0_2_ = (short)puVar3, bVar6 = (short)puVar4 == (short)param_1,
              param_1 = puVar5, bVar6));
    }
    else {
      puVar3 = (ushort *)InterlockedIncrement((LONG *)&DAT_6001f228);
      bVar6 = DAT_6001f224 == 0;
      if (!bVar6) {
        InterlockedDecrement((LONG *)&DAT_6001f228);
        puVar3 = (ushort *)FUN_60008d89(0x13);
      }
      do {
        uVar1 = *param_1;
        param_1 = param_1 + 1;
        puVar4 = (ushort *)FUN_6000fd11(CONCAT22((short)((uint)puVar3 >> 0x10),uVar1));
        puVar5 = param_2 + 1;
        puVar3 = (ushort *)FUN_6000fd11(CONCAT22((short)((uint)puVar4 >> 0x10),*param_2));
        param_3 = param_3 + -1;
        if ((param_3 == 0) || (param_2._0_2_ = (short)puVar4, (short)param_2 == 0)) break;
        bVar7 = (short)param_2 == (short)puVar3;
        param_2 = puVar5;
      } while (bVar7);
      if (bVar6) {
        InterlockedDecrement((LONG *)&DAT_6001f228);
      }
      else {
        FUN_60008dea(0x13);
      }
    }
    param_2 = puVar4;
    param_1 = puVar3;
    iVar2 = ((uint)param_2 & 0xffff) - ((uint)param_1 & 0xffff);
  }
  return iVar2;
}



/* VA 6000f8b0 */

int __cdecl FUN_6000f8b0(byte *param_1,byte *param_2)

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



/* VA 6000f8f0 */

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



/* VA 6000f930 */

byte * __cdecl FUN_6000f930(byte *param_1,byte *param_2)

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



/* VA 6000f96a */

void __cdecl FUN_6000f96a(int *param_1,int *param_2)

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
LAB_6000fa0d:
      piVar4[2] = 0;
      piVar4[1] = 0;
      *piVar4 = 0;
      return;
    }
    if (((uVar6 != 0) || (piVar1 = (int *)((int)piVar1 + 1), (param_1[2] & 0x7fffffffU) != 0)) ||
       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {
      param_1 = piVar1;
      if (((uVar9 == 0) && (param_1 = (int *)((int)param_1 + 1), (param_2[2] & 0x7fffffffU) == 0))
         && ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_6000fa0d;
      local_14 = 0;
      local_8 = &local_24;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_c = (ushort *)(local_14 * 2 + (int)piVar4);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = param_2;
          do {
            iVar8 = FUN_6000e375(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
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
LAB_6000fac1:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          iVar8 = -(int)(short)(ushort)param_1;
          param_1._0_2_ = (ushort)param_1 + (short)iVar8;
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_6000e422((uint *)&local_28);
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
          FUN_6000e3f4((uint *)&local_28);
          param_1 = (int *)((int)param_1 + 0xffff);
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_6000fac1;
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
      if (0x7ffe < (ushort)param_1) goto LAB_6000fb6a;
      uVar6 = (ushort)param_1 | uVar11;
      *(undefined2 *)piVar4 = uStack_26;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_6000fb6a:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}



/* VA 6000fb8a */

void __cdecl FUN_6000fb8a(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 uStack_a;
  undefined *puStack_8;

  ppuVar3 = &PTR_DAT_6001d400;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      ppuVar3 = (undefined **)0x6001d560;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      ppuVar3 = ppuVar3 + 0x15;
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar1;
      if (uVar2 != 0) {
        ppuVar4 = ppuVar3 + uVar2 * 3;
        if (0x7fff < *(ushort *)(ppuVar3 + uVar2 * 3)) {
          local_10 = SUB42(*ppuVar4,0);
          local_e._0_2_ = (undefined2)((uint)*ppuVar4 >> 0x10);
          local_e._2_2_ = SUB42(ppuVar4[1],0);
          uStack_a = (undefined2)((uint)ppuVar4[1] >> 0x10);
          puStack_8 = ppuVar4[2];
          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;
          ppuVar4 = (undefined **)&local_10;
        }
        FUN_6000f96a(param_1,(int *)ppuVar4);
      }
    }
  }
  return;
}



/* VA 6000fc06 */

undefined4 __cdecl FUN_6000fc06(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_600205a0) &&
     ((*(byte *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_6000f34b(param_1);
    uVar1 = FUN_6000fc63(param_1);
    FUN_6000f3aa(param_1);
    return uVar1;
  }
  pDVar2 = FUN_6000f278();
  *pDVar2 = 9;
  pDVar2 = FUN_6000f281();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 6000fc63 */

undefined4 __cdecl FUN_6000fc63(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;

  iVar1 = FUN_6000f309(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_6000f309(2);
      iVar2 = FUN_6000f309(1);
      if (iVar2 == iVar1) goto LAB_6000fcb1;
    }
    hObject = (HANDLE)FUN_6000f309(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_6000fcb3;
    }
  }
LAB_6000fcb1:
  DVar4 = 0;
LAB_6000fcb3:
  FUN_6000f28a(param_1);
  *(undefined1 *)((&DAT_600204a0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_6000f205(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



/* VA 6000fce6 */

/* Library Function - Single Match
    __freebuf

   Library: Visual Studio 2003 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_600074bf(_File->_base);
    *(ushort *)&_File->_flag = (ushort)_File->_flag & 0xfbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}



/* VA 6000fd11 */

uint __cdecl FUN_6000fd11(uint param_1)

{
  WCHAR WVar1;
  uint uVar2;
  size_t sVar3;
  undefined2 uVar4;
  WCHAR local_6;

  WVar1 = (WCHAR)param_1;
  if (WVar1 == L'\xffff') {
    return param_1;
  }
  if (DAT_6001dc3c == 0) {
    if ((0x40 < (ushort)WVar1) && ((ushort)WVar1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    if ((ushort)WVar1 < 0x100) {
      uVar2 = FUN_6001032a(WVar1,1);
      if (uVar2 == 0) {
        return param_1 & 0xffff;
      }
    }
    sVar3 = FUN_60010121(DAT_6001dc3c,0x100,(LPCWSTR)&param_1,1,&local_6,1,0);
    uVar4 = (undefined2)(sVar3 >> 0x10);
    param_1 = CONCAT22(uVar4,(undefined2)param_1);
    if (sVar3 != 0) {
      param_1 = CONCAT22(uVar4,local_6);
    }
  }
  return param_1;
}



/* VA 6000fd86 */

BOOL __cdecl
FUN_6000fd86(DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  undefined1 *puVar1;
  BOOL BVar2;
  size_t _Size;
  int iVar3;
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_60013108;
  puStack_10 = &LAB_6000d704;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc4;
  iVar3 = DAT_6001dcec;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc4;
  if (DAT_6001dcec == 0) {
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
  DAT_6001dcec = iVar3;
  if (DAT_6001dcec != 1) {
    if (DAT_6001dcec == 2) {
      if (param_5 == 0) {
        param_5 = DAT_6001dc4c;
      }
      _Size = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                 );
      if (_Size != 0) {
        local_8 = 0;
        FUN_6000d7e0();
        local_1c = &stack0xffffffc4;
        _memset(&stack0xffffffc4,0,_Size);
        local_8 = 0xffffffff;
        if (&stack0x00000000 != (undefined1 *)0x3c) {
          iVar3 = WideCharToMultiByte(param_5,0x220,param_2,param_3,&stack0xffffffc4,_Size,
                                      (LPCSTR)0x0,(LPBOOL)0x0);
          if (iVar3 != 0) {
            local_8 = 1;
            FUN_6000d7e0();
            local_8 = 0xffffffff;
            if (&stack0x00000000 != (undefined1 *)0x3c) {
              if (param_6 == 0) {
                param_6 = DAT_6001dc3c;
              }
              local_1c = &stack0xffffffc4;
              *(short *)(&stack0xffffffc4 + param_3 * 2) = -1;
              local_20[param_3 + -0xf] = 0xffff;
              BVar2 = GetStringTypeA(param_6,param_1,&stack0xffffffc4,_Size,(LPWORD)&stack0xffffffc4
                                    );
              if ((local_20[param_3 + -0xf] != 0xffff) &&
                 (*(short *)(&stack0xffffffc4 + param_3 * 2) == -1)) {
                FUN_6000bfe0((undefined4 *)param_4,(undefined4 *)&stack0xffffffc4,param_3 * 2);
                ExceptionList = local_14;
                return BVar2;
              }
            }
          }
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  BVar2 = GetStringTypeW(param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}



/* VA 6000ff50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_6000ff50(void *this,byte *param_1,byte *param_2)

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

  iVar2 = _DAT_6001f228;
  if (DAT_6001dc3c == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_6000ff9e;
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
LAB_6000ff9e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_6001f228 = _DAT_6001f228 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_6001f224;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_6001f228 = iVar2;
      FUN_60008d89(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_6000ffff;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_6000b933(this,uVar8);
      uVar7 = FUN_6000b933(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_6000ffff:
    if (uVar9 == 0) {
      LOCK();
      _DAT_6001f228 = _DAT_6001f228 + -1;
      UNLOCK();
    }
    else {
      FUN_60008dea(0x13);
    }
  }
  return uVar7;
}



/* VA 60010020 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_60010020(byte *param_1,char *param_2,void *param_3)

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

  iVar2 = _DAT_6001f228;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_6001dc3c == 0) {
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
        if (bVar3 != (byte)uVar4) goto LAB_6001007f;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_6001007f:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_6001f228 = _DAT_6001f228 + 1;
      UNLOCK();
      bVar8 = 0 < DAT_6001f224;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_6001f228 = iVar2;
        FUN_60008d89(0x13);
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
        uVar7 = FUN_6000b933(param_3,uVar7);
        uVar5 = FUN_6000b933(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_600100f5;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_600100f5:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_6001f228 = _DAT_6001f228 + -1;
        UNLOCK();
      }
      else {
        FUN_60008dea(0x13);
      }
    }
  }
  return uVar6;
}



/* VA 60010121 */

size_t __cdecl
FUN_60010121(LCID param_1,uint param_2,LPCWSTR param_3,int param_4,LPWSTR param_5,size_t param_6,
            UINT param_7)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_60013120;
  puStack_10 = &LAB_6000d704;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_6001dcf0 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_6001dcf0 = 2;
    }
    else {
      DAT_6001dcf0 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_6000f6f7(param_3,param_4);
  }
  if (DAT_6001dcf0 == 1) {
    sVar2 = LCMapStringW(param_1,param_2,param_3,param_4,param_5,param_6);
    ExceptionList = local_14;
    return sVar2;
  }
  if (DAT_6001dcf0 == 2) {
    if (param_7 == 0) {
      param_7 = DAT_6001dc4c;
    }
    iVar1 = WideCharToMultiByte(param_7,0x220,param_3,param_4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_6000d7e0();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar3 = WideCharToMultiByte(param_7,0x220,param_3,param_4,&stack0xffffffc4,iVar1,
                                      (LPCSTR)0x0,(LPBOOL)0x0), iVar3 != 0)) {
        sVar2 = LCMapStringA(param_1,param_2,&stack0xffffffc4,iVar1,(LPSTR)0x0,0);
        if (sVar2 != 0) {
          local_8 = 1;
          FUN_6000d7e0();
          local_8 = 0xffffffff;
          if ((&stack0x00000000 != (undefined1 *)0x3c) &&
             (iVar1 = LCMapStringA(param_1,param_2,&stack0xffffffc4,iVar1,&stack0xffffffc4,sVar2),
             iVar1 != 0)) {
            if ((param_2 & 0x400) != 0) {
              if (param_6 != 0) {
                if ((int)sVar2 <= (int)param_6) {
                  param_6 = sVar2;
                }
                _strncpy((char *)param_5,&stack0xffffffc4,param_6);
                ExceptionList = local_14;
                return sVar2;
              }
              ExceptionList = local_14;
              return sVar2;
            }
            if (param_6 == 0) {
              param_6 = 0;
              param_5 = (LPWSTR)0x0;
            }
            sVar2 = MultiByteToWideChar(param_7,1,&stack0xffffffc4,sVar2,param_5,param_6);
            if (sVar2 != 0) {
              ExceptionList = local_14;
              return sVar2;
            }
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* VA 6001032a */

uint __cdecl FUN_6001032a(WCHAR param_1,ushort param_2)

{
  BOOL BVar1;
  uint local_8;

  if (param_1 == L'\xffff') {
    return 0;
  }
  if ((ushort)param_1 < 0x100) {
    local_8 = (uint)*(ushort *)(PTR_DAT_6001c5d4 + (uint)(ushort)param_1 * 2);
  }
  else {
    BVar1 = FUN_6000fd86(1,&param_1,1,(LPWORD)&local_8,0,0);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return local_8 & 0xffff & (uint)param_2;
}



/* VA 6001037c */

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x6001037c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}



/* VA 60010382 */

void DirectDrawCreate(void)

{
                    /* WARNING: Could not recover jumptable at 0x60010382. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DirectDrawCreate();
  return;
}



/* VA 60010388 */

undefined4 FUN_60010388(undefined4 param_1)

{
  DAT_600205bc = param_1;
  return 1;
}



/* VA 60010398 */

void FUN_60010398(void)

{
  DWORD DVar1;
  undefined1 *puVar2;
  HMODULE pHVar3;
  uint auStack_104 [65];

  DVar1 = GetModuleFileNameA(DAT_600205bc,(LPSTR)auStack_104,0x104);
  for (puVar2 = (undefined1 *)((int)auStack_104 + DVar1);
      (((uint)puVar2 & (uint)auStack_104) != 0 && (puVar2[-1] != '\\')); puVar2 = puVar2 + -1) {
  }
  *puVar2 = 0;
  FUN_6000ad30(auStack_104,(uint *)"glide3x.dll");
  pHVar3 = LoadLibraryA((LPCSTR)auStack_104);
  if (pHVar3 == (HMODULE)0x0) {
    LoadLibraryA("glide3x.dll");
  }
  return;
}



/* VA 60011000 */

undefined4 * __cdecl FUN_60011000(undefined4 *param_1,undefined4 param_2,uint param_3)

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



/* VA 600110c0 */

undefined8 * __cdecl FUN_600110c0(undefined8 *param_1,undefined4 param_2,uint param_3)

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



/* VA 60011180 */

undefined8 * __cdecl FUN_60011180(undefined8 *param_1,undefined4 param_2,uint param_3)

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
