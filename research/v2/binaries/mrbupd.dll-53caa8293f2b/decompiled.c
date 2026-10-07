/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 53caa8293f2bcac23f1f80b6f2a605f6b9cf801554fd92c09a068d2220235722 */

/* VA 10001000 */

void __cdecl FUN_10001000(char *param_1)

{
  size_t sVar1;

  sVar1 = strlen(param_1);
  FUN_10001017((int)param_1,sVar1);
  return;
}



/* VA 10001017 */

void * __cdecl FUN_10001017(int param_1,int param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 local_14;

  iVar3 = 0;
  local_14 = 0;
  piVar1 = FUN_100029c1();
  if (2 < param_2) {
    iVar4 = param_1 + 1;
    do {
      FUN_10002d3c((int)piVar1);
      FUN_10002d3c((int)piVar1);
      FUN_10002d3c((int)piVar1);
      FUN_10002d3c((int)piVar1);
      iVar3 = local_14 + 3;
      iVar4 = iVar4 + 3;
      local_14 = iVar3;
    } while ((1 - param_1) + iVar4 < param_2);
  }
  if (param_2 - iVar3 == 1) {
    FUN_10002d3c((int)piVar1);
    FUN_10002d3c((int)piVar1);
  }
  else {
    if (param_2 - iVar3 != 2) goto LAB_1000119b;
    FUN_10002d3c((int)piVar1);
    FUN_10002d3c((int)piVar1);
  }
  FUN_10002d3c((int)piVar1);
  FUN_10002d3c((int)piVar1);
LAB_1000119b:
  pvVar2 = FUN_10002bf2((int)piVar1);
  FUN_10002a4e(piVar1);
  return pvVar2;
}



/* VA 100011b2 */

void FUN_100011b2(void)

{
  malloc(0x10);
  return;
}



/* VA 100011bc */

undefined4 __cdecl FUN_100011bc(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_1 != 0 || param_2 != 0) && (param_3 != 0 || param_4 != 0)) {
    return 1;
  }
  return 0;
}



/* VA 100011d7 */

undefined4 __cdecl
FUN_100011d7(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  if ((((param_1 == param_5) && (param_2 == param_6)) && (param_3 == param_7)) &&
     (param_4 == param_8)) {
    return 1;
  }
  return 0;
}



/* VA 10001203 */

void * __cdecl FUN_10001203(uint param_1,uint param_2,ulonglong param_3)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  ulonglong uVar4;
  uint local_8;

  local_8 = param_2;
  pvVar2 = malloc(0x1c);
  *(undefined1 *)((int)pvVar2 + 0x1b) = 0;
  iVar3 = 0xc;
  do {
    *(undefined *)((int)pvVar2 + iVar3) = (&DAT_10016000)[param_1 & 0x1f];
    uVar4 = __aullshr(5,local_8);
    local_8 = (uint)(uVar4 >> 0x20);
    param_1 = (uint)uVar4;
    bVar1 = 0 < iVar3;
    iVar3 = iVar3 + -1;
  } while (bVar1);
  *(undefined1 *)((int)pvVar2 + 0xd) = 0x78;
  iVar3 = 0x1a;
  do {
    *(undefined *)((int)pvVar2 + iVar3) = (&DAT_10016000)[(uint)param_3 & 0x1f];
    param_3 = __aullshr(5,(uint)(param_3 >> 0x20));
    bVar1 = 0xe < iVar3;
    iVar3 = iVar3 + -1;
  } while (bVar1);
  return pvVar2;
}



/* VA 1000127f */

void * __cdecl FUN_1000127f(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  undefined1 *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint local_c;

  local_c = param_2;
  pvVar1 = malloc(0x21);
  *(undefined1 *)((int)pvVar1 + 0x20) = 0;
  puVar2 = (undefined1 *)((int)pvVar1 + 1);
  do {
    uVar3 = __aullshr(4,local_c);
    puVar2[-1] = (&DAT_10016000)[(uint)uVar3 & 0xf];
    *puVar2 = (&DAT_10016000)[param_1 & 0xf];
    puVar2 = puVar2 + 2;
    uVar3 = __aullshr(8,local_c);
    local_c = (uint)(uVar3 >> 0x20);
    param_1 = (uint)uVar3;
  } while ((int)(puVar2 + (-1 - (int)pvVar1)) < 0x10);
  uVar3 = CONCAT44(param_4,param_3);
  puVar2 = (undefined1 *)((int)pvVar1 + 0x11);
  do {
    local_c = (uint)(uVar3 >> 0x20);
    uVar4 = __aullshr(4,local_c);
    puVar2[-1] = (&DAT_10016000)[(uint)uVar4 & 0xf];
    *puVar2 = (&DAT_10016000)[(uint)uVar3 & 0xf];
    puVar2 = puVar2 + 2;
    uVar3 = __aullshr(8,local_c);
  } while ((int)(puVar2 + (-1 - (int)pvVar1)) < 0x20);
  return pvVar1;
}



/* VA 10001344 */

void __cdecl FUN_10001344(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  void *_Memory;
  void *_Memory_00;
  char local_84 [128];

  piVar1 = FUN_100029c1();
  FUN_10002c79((int)piVar1,param_1,param_2);
  FUN_10002c79((int)piVar1,param_3,param_4);
  _Memory = FUN_10002bcc((int)piVar1);
  FUN_10002a4e(piVar1);
  _Memory_00 = FUN_10001017((int)_Memory,0x10);
  free(_Memory);
  sprintf(local_84,s_urn_md5__s_10017058,_Memory_00);
  free(_Memory_00);
  _strdup(local_84);
  return;
}



/* VA 100013c2 */

int __cdecl FUN_100013c2(int *param_1,uint *param_2)

{
  int iVar1;

  iVar1 = FUN_1000c42a(param_1,param_2);
  if (iVar1 < 0) {
    return -1;
  }
  iVar1 = FUN_1000c42a(param_1,param_2 + 2);
  return (-1 < iVar1) - 1;
}



/* VA 100013f7 */

int __cdecl FUN_100013f7(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;

  iVar1 = FUN_1000c2c6(param_1,param_2,param_3);
  if (iVar1 < 0) {
    return -1;
  }
  iVar1 = FUN_1000c2c6(param_1,param_4,param_5);
  return (-1 < iVar1) - 1;
}



/* VA 10001431 */

void __cdecl FUN_10001431(int param_1,int param_2,uint param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint local_5c;
  int local_50;
  uint local_10;
  uint local_c;
  uint local_8;

  local_50 = *param_4;
  local_8 = param_4[1];
  local_c = param_4[2];
  local_10 = param_4[3];
  if (0x3f < (int)param_3) {
    piVar18 = (int *)(param_2 + param_1);
    local_5c = param_3 >> 6;
    do {
      iVar2 = *piVar18;
      iVar16 = piVar18[1];
      iVar17 = piVar18[2];
      iVar3 = piVar18[3];
      iVar4 = piVar18[4];
      iVar5 = piVar18[5];
      iVar6 = piVar18[6];
      iVar7 = piVar18[7];
      iVar8 = piVar18[8];
      iVar9 = piVar18[9];
      iVar10 = piVar18[10];
      iVar11 = piVar18[0xb];
      iVar12 = piVar18[0xc];
      iVar13 = piVar18[0xd];
      iVar14 = piVar18[0xe];
      iVar15 = piVar18[0xf];
      piVar18 = piVar18 + 0x10;
      uVar1 = (local_c & local_8 | ~local_8 & local_10) + iVar2 + -0x28955b88 + local_50;
      uVar19 = (uVar1 * 0x80 | uVar1 >> 0x19) + local_8;
      uVar1 = (uVar19 & local_8 | ~uVar19 & local_c) + iVar16 + -0x173848aa + local_10;
      uVar20 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar19;
      uVar1 = (uVar20 & uVar19 | ~uVar20 & local_8) + iVar17 + 0x242070db + local_c;
      uVar21 = (uVar1 * 0x20000 | uVar1 >> 0xf) + uVar20;
      uVar1 = (uVar20 & uVar21 | ~uVar21 & uVar19) + iVar3 + -0x3e423112 + local_8;
      uVar22 = (uVar1 * 0x400000 | uVar1 >> 10) + uVar21;
      uVar1 = uVar19 + 0xf57c0faf + (uVar21 & uVar22 | ~uVar22 & uVar20) + iVar4;
      uVar23 = (uVar1 * 0x80 | uVar1 >> 0x19) + uVar22;
      uVar1 = uVar20 + 0x4787c62a + (uVar22 & uVar23 | ~uVar23 & uVar21) + iVar5;
      uVar19 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar23;
      uVar1 = uVar21 + 0xa8304613 + (uVar19 & uVar23 | ~uVar19 & uVar22) + iVar6;
      uVar20 = (uVar1 * 0x20000 | uVar1 >> 0xf) + uVar19;
      uVar1 = uVar22 + 0xfd469501 + (uVar19 & uVar20 | ~uVar20 & uVar23) + iVar7;
      uVar21 = (uVar1 * 0x400000 | uVar1 >> 10) + uVar20;
      uVar1 = uVar23 + 0x698098d8 + (uVar20 & uVar21 | ~uVar21 & uVar19) + iVar8;
      uVar22 = (uVar1 * 0x80 | uVar1 >> 0x19) + uVar21;
      uVar1 = uVar19 + 0x8b44f7af + (uVar21 & uVar22 | ~uVar22 & uVar20) + iVar9;
      uVar23 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar22;
      uVar1 = (uVar20 - 0xa44f) + (uVar23 & uVar22 | ~uVar23 & uVar21) + iVar10;
      uVar24 = (uVar1 * 0x20000 | uVar1 >> 0xf) + uVar23;
      uVar1 = uVar21 + 0x895cd7be + (uVar23 & uVar24 | ~uVar24 & uVar22) + iVar11;
      uVar19 = (uVar1 * 0x400000 | uVar1 >> 10) + uVar24;
      uVar1 = uVar22 + 0x6b901122 + (uVar24 & uVar19 | ~uVar19 & uVar23) + iVar12;
      uVar20 = (uVar1 * 0x80 | uVar1 >> 0x19) + uVar19;
      uVar1 = uVar23 + 0xfd987193 + (uVar19 & uVar20 | ~uVar20 & uVar24) + iVar13;
      uVar21 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar20;
      uVar1 = uVar24 + 0xa679438e + (uVar19 & ~uVar21 | uVar21 & uVar20) + iVar14;
      uVar22 = (uVar1 * 0x20000 | uVar1 >> 0xf) + uVar21;
      uVar1 = uVar19 + 0x49b40821 + (uVar20 & ~uVar22 | uVar21 & uVar22) + iVar15;
      uVar23 = (uVar1 * 0x400000 | uVar1 >> 10) + uVar22;
      uVar1 = uVar20 + 0xf61e2562 + (uVar22 & ~uVar21 | uVar21 & uVar23) + iVar16;
      uVar24 = (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar23;
      uVar1 = uVar21 + 0xc040b340 + (uVar23 & ~uVar22 | uVar22 & uVar24) + iVar6;
      uVar19 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar24;
      uVar1 = uVar22 + 0x265e5a51 + (uVar19 & uVar23 | ~uVar23 & uVar24) + iVar11;
      uVar20 = (uVar1 * 0x4000 | uVar1 >> 0x12) + uVar19;
      uVar1 = uVar23 + 0xe9b6c7aa + (uVar20 & uVar24 | ~uVar24 & uVar19) + iVar2;
      uVar23 = (uVar1 * 0x100000 | uVar1 >> 0xc) + uVar20;
      uVar1 = uVar24 + 0xd62f105d + (uVar19 & uVar23 | ~uVar19 & uVar20) + iVar5;
      uVar21 = (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar23;
      uVar1 = uVar19 + 0x2441453 + (uVar20 & uVar21 | ~uVar20 & uVar23) + iVar10;
      uVar22 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar21;
      uVar1 = uVar20 + 0xd8a1e681 + (uVar22 & uVar23 | ~uVar23 & uVar21) + iVar15;
      uVar19 = (uVar1 * 0x4000 | uVar1 >> 0x12) + uVar22;
      uVar1 = uVar23 + 0xe7d3fbc8 + (uVar19 & uVar21 | ~uVar21 & uVar22) + iVar4;
      uVar20 = (uVar1 * 0x100000 | uVar1 >> 0xc) + uVar19;
      uVar1 = uVar21 + 0x21e1cde6 + (uVar22 & uVar20 | ~uVar22 & uVar19) + iVar9;
      uVar21 = (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar20;
      uVar1 = uVar22 + 0xc33707d6 + (uVar19 & uVar21 | ~uVar19 & uVar20) + iVar14;
      uVar23 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar21;
      uVar1 = uVar19 + 0xf4d50d87 + (uVar23 & uVar20 | ~uVar20 & uVar21) + iVar3;
      uVar22 = (uVar1 * 0x4000 | uVar1 >> 0x12) + uVar23;
      uVar1 = uVar20 + 0x455a14ed + (uVar22 & uVar21 | ~uVar21 & uVar23) + iVar8;
      uVar19 = (uVar1 * 0x100000 | uVar1 >> 0xc) + uVar22;
      uVar1 = uVar21 + 0xa9e3e905 + (uVar23 & uVar19 | ~uVar23 & uVar22) + iVar13;
      uVar20 = (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar19;
      uVar1 = uVar23 + 0xfcefa3f8 + (uVar22 & uVar20 | ~uVar22 & uVar19) + iVar17;
      uVar21 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar20;
      uVar1 = uVar22 + 0x676f02d9 + (uVar21 & uVar19 | ~uVar19 & uVar20) + iVar7;
      uVar24 = (uVar1 * 0x4000 | uVar1 >> 0x12) + uVar21;
      uVar1 = uVar19 + 0x8d2a4c8a + (uVar24 & uVar20 | ~uVar20 & uVar21) + iVar12;
      uVar23 = (uVar1 * 0x100000 | uVar1 >> 0xc) + uVar24;
      uVar1 = (uVar20 - 0x5c6be) + (uVar21 ^ uVar24 ^ uVar23) + iVar5;
      uVar19 = (uVar1 * 0x10 | uVar1 >> 0x1c) + uVar23;
      uVar1 = uVar21 + 0x8771f681 + (uVar24 ^ uVar23 ^ uVar19) + iVar8;
      uVar22 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar19;
      uVar1 = uVar24 + 0x6d9d6122 + (uVar22 ^ uVar23 ^ uVar19) + iVar11;
      uVar20 = (uVar1 * 0x10000 | uVar1 >> 0x10) + uVar22;
      uVar1 = uVar23 + 0xfde5380c + (uVar19 ^ uVar22 ^ uVar20) + iVar14;
      uVar21 = (uVar1 * 0x800000 | uVar1 >> 9) + uVar20;
      uVar1 = uVar19 + 0xa4beea44 + (uVar21 ^ uVar22 ^ uVar20) + iVar16;
      uVar19 = (uVar1 * 0x10 | uVar1 >> 0x1c) + uVar21;
      uVar1 = uVar22 + 0x4bdecfa9 + (uVar20 ^ uVar21 ^ uVar19) + iVar4;
      uVar23 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar19;
      uVar1 = uVar20 + 0xf6bb4b60 + (uVar23 ^ uVar21 ^ uVar19) + iVar7;
      uVar22 = (uVar1 * 0x10000 | uVar1 >> 0x10) + uVar23;
      uVar1 = uVar21 + 0xbebfbc70 + (uVar19 ^ uVar23 ^ uVar22) + iVar10;
      uVar20 = (uVar1 * 0x800000 | uVar1 >> 9) + uVar22;
      uVar1 = uVar19 + 0x289b7ec6 + (uVar20 ^ uVar23 ^ uVar22) + iVar13;
      uVar19 = (uVar1 * 0x10 | uVar1 >> 0x1c) + uVar20;
      uVar1 = uVar23 + 0xeaa127fa + (uVar22 ^ uVar20 ^ uVar19) + iVar2;
      uVar21 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar19;
      uVar1 = uVar22 + 0xd4ef3085 + (uVar21 ^ uVar20 ^ uVar19) + iVar3;
      uVar23 = (uVar1 * 0x10000 | uVar1 >> 0x10) + uVar21;
      uVar1 = uVar20 + 0x4881d05 + (uVar19 ^ uVar21 ^ uVar23) + iVar6;
      uVar20 = (uVar1 * 0x800000 | uVar1 >> 9) + uVar23;
      uVar1 = uVar19 + 0xd9d4d039 + (uVar20 ^ uVar21 ^ uVar23) + iVar9;
      uVar19 = (uVar1 * 0x10 | uVar1 >> 0x1c) + uVar20;
      uVar1 = uVar21 + 0xe6db99e5 + (uVar23 ^ uVar20 ^ uVar19) + iVar12;
      uVar22 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar19;
      uVar1 = uVar23 + 0x1fa27cf8 + (uVar22 ^ uVar20 ^ uVar19) + iVar15;
      uVar23 = (uVar1 * 0x10000 | uVar1 >> 0x10) + uVar22;
      uVar1 = uVar20 + 0xc4ac5665 + (uVar22 ^ uVar23 ^ uVar19) + iVar17;
      uVar21 = (uVar1 * 0x800000 | uVar1 >> 9) + uVar23;
      uVar1 = uVar19 + 0xf4292244 + ((~uVar22 | uVar21) ^ uVar23) + iVar2;
      uVar20 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar21;
      uVar1 = uVar22 + 0x432aff97 + ((~uVar23 | uVar20) ^ uVar21) + iVar7;
      uVar19 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar20;
      uVar1 = uVar23 + 0xab9423a7 + ((~uVar21 | uVar19) ^ uVar20) + iVar14;
      uVar22 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar19;
      uVar1 = uVar21 + 0xfc93a039 + ((~uVar20 | uVar22) ^ uVar19) + iVar5;
      uVar23 = (uVar1 * 0x200000 | uVar1 >> 0xb) + uVar22;
      uVar1 = uVar20 + 0x655b59c3 + ((~uVar19 | uVar23) ^ uVar22) + iVar12;
      uVar20 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar23;
      uVar1 = uVar19 + 0x8f0ccc92 + ((~uVar22 | uVar20) ^ uVar23) + iVar3;
      uVar19 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar20;
      uVar1 = (uVar22 - 0x100b83) + ((~uVar23 | uVar19) ^ uVar20) + iVar10;
      uVar21 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar19;
      uVar1 = uVar23 + 0x85845dd1 + ((~uVar20 | uVar21) ^ uVar19) + iVar16;
      uVar23 = (uVar1 * 0x200000 | uVar1 >> 0xb) + uVar21;
      uVar1 = uVar20 + 0x6fa87e4f + ((~uVar19 | uVar23) ^ uVar21) + iVar8;
      uVar20 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar23;
      uVar1 = uVar19 + 0xfe2ce6e0 + ((~uVar21 | uVar20) ^ uVar23) + iVar15;
      uVar19 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar20;
      uVar1 = uVar21 + 0xa3014314 + ((~uVar23 | uVar19) ^ uVar20) + iVar6;
      uVar22 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar19;
      uVar1 = uVar23 + 0x4e0811a1 + ((~uVar20 | uVar22) ^ uVar19) + iVar13;
      uVar23 = (uVar1 * 0x200000 | uVar1 >> 0xb) + uVar22;
      uVar1 = uVar20 + 0xf7537e82 + ((~uVar19 | uVar23) ^ uVar22) + iVar4;
      uVar21 = (uVar1 * 0x40 | uVar1 >> 0x1a) + uVar23;
      local_50 = local_50 + uVar21;
      uVar1 = uVar19 + 0xbd3af235 + ((~uVar22 | uVar21) ^ uVar23) + iVar11;
      uVar20 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar21;
      local_10 = local_10 + uVar20;
      uVar1 = uVar22 + 0x2ad7d2bb + ((~uVar23 | uVar20) ^ uVar21) + iVar17;
      uVar19 = (uVar1 * 0x8000 | uVar1 >> 0x11) + uVar20;
      local_c = local_c + uVar19;
      uVar1 = uVar23 + 0xeb86d391 + ((~uVar21 | uVar19) ^ uVar20) + iVar9;
      local_8 = local_8 + (uVar1 * 0x200000 | uVar1 >> 0xb) + uVar19;
      local_5c = local_5c - 1;
    } while (local_5c != 0);
  }
  *param_4 = local_50;
  param_4[1] = local_8;
  param_4[2] = local_c;
  param_4[3] = local_10;
  return;
}



/* VA 10001f03 */

void __cdecl
FUN_10001f03(uint *param_1,int param_2,int param_3,size_t param_4,uint param_5,int param_6,
            uint *param_7)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 local_94 [120];
  undefined1 auStack_1c [8];
  uint local_14;
  uint local_10;

  memcpy(local_94,(void *)(param_3 + param_2),param_4);
  local_94[param_4] = 0x80;
  memset(local_94 + param_4 + 1,0,0x80 - (param_4 + 1));
  uVar1 = (0x37 < (int)(param_4 + 1)) - 1 & 0xffffffc0;
  lVar3 = __allmul(param_5,param_6,8,0);
  uVar2 = (uint)((ulonglong)lVar3 >> 0x20);
  auStack_1c[uVar1] = (char)lVar3;
  uVar4 = __aullshr(8,uVar2);
  auStack_1c[uVar1 + 1] = (char)uVar4;
  uVar4 = __aullshr(0x10,uVar2);
  auStack_1c[uVar1 + 2] = (char)uVar4;
  uVar4 = __aullshr(0x18,uVar2);
  auStack_1c[uVar1 + 3] = (char)uVar4;
  uVar4 = __aullshr(0x20,uVar2);
  auStack_1c[uVar1 + 4] = (char)uVar4;
  uVar4 = __aullshr(0x28,uVar2);
  auStack_1c[uVar1 + 5] = (char)uVar4;
  uVar4 = __aullshr(0x30,uVar2);
  auStack_1c[uVar1 + 6] = (char)uVar4;
  uVar4 = __aullshr(0x38,uVar2);
  auStack_1c[uVar1 + 7] = (char)uVar4;
  FUN_10001431((int)local_94,0,0x40,(int *)param_7);
  if (0x40 < (int)(uVar1 + 0x80)) {
    FUN_10001431((int)local_94,0x40,0x40,(int *)param_7);
  }
  lVar3 = __allshl(0x20,(int)param_7[1] >> 0x1f);
  local_10 = (uint)((ulonglong)lVar3 >> 0x20);
  local_14 = (uint)lVar3 | *param_7;
  lVar3 = __allshl(0x20,(int)param_7[3] >> 0x1f);
  uVar1 = param_7[2];
  *param_1 = local_14;
  param_1[1] = local_10;
  param_1[2] = (uint)lVar3 | uVar1;
  param_1[3] = (uint)((ulonglong)lVar3 >> 0x20);
  return;
}



/* VA 10002074 */

void FUN_10002074(void)

{
  undefined4 *puVar1;

  puVar1 = calloc(4,4);
  *puVar1 = 0x67452301;
  puVar1[1] = 0xefcdab89;
  puVar1[2] = 0x98badcfe;
  puVar1[3] = 0x10325476;
  return;
}



/* VA 1000209c */

void __cdecl FUN_1000209c(int *param_1,int *param_2)

{
  FUN_100011d7(*param_1,param_1[1],param_1[2],param_1[3],*param_2,param_2[1],param_2[2],param_2[3]);
  return;
}



/* VA 100020c3 */

uint __cdecl FUN_100020c3(uint *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;

  uVar1 = __allshr(0x20,param_1[1]);
  uVar2 = __allshr(0x20,param_1[3]);
  return (uint)uVar1 ^ (uint)uVar2 ^ *param_1 ^ param_1[2];
}



/* VA 100020f2 */

int __cdecl FUN_100020f2(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  size_t sVar6;
  undefined4 unaff_EBX;
  int iVar7;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  undefined1 local_1014 [4076];
  undefined4 uStackY_28;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ushort uVar10;

  FUN_10014d20();
  puVar2 = param_3;
  piVar1 = param_2;
  iVar7 = 0;
  while (iVar3 = FUN_10003015(piVar1,&param_2), -1 < iVar3) {
    puVar4 = (undefined4 *)((uint)param_2 & 0xff);
    if (puVar4 < (undefined4 *)0xf3) {
      if (puVar4 != (undefined4 *)0xf2) {
        if (puVar4 == (undefined4 *)0xffffffff) {
          return -1;
        }
        goto switchD_10002193_caseD_fa;
      }
      sVar6 = FUN_10003065(piVar1,(undefined4 *)&stack0xfffffff4);
      puVar4 = unaff_ESI;
      if (-1 < (int)sVar6) goto LAB_10002130;
      break;
    }
    uVar10 = (ushort)((uint)unaff_EBX >> 0x10);
    puVar8 = unaff_ESI;
    puVar9 = unaff_ESI;
    switch(puVar4) {
    case (undefined4 *)0xf3:
      iVar3 = FUN_10003028(piVar1,(undefined2 *)&stack0xfffffffa);
      if (iVar3 < 0) {
        puVar5 = (uint *)FUN_10002fe7((int)piVar1);
        FUN_1000c245(puVar5);
        return -1;
      }
      puVar4 = (undefined4 *)(uint)uVar10;
      goto LAB_10002130;
    case (undefined4 *)0xf4:
      sVar6 = FUN_10003065(piVar1,(undefined4 *)&stack0xfffffff4);
      if (((int)sVar6 < 0) ||
         (sVar6 = FUN_10003065(piVar1,(undefined4 *)&stack0xffffffec), puVar9 = puVar2,
         (int)sVar6 < 0)) goto LAB_10002148;
      break;
    case (undefined4 *)0xf5:
      sVar6 = FUN_10003065(piVar1,(undefined4 *)&stack0xfffffff4);
      if (((int)sVar6 < 0) ||
         (iVar3 = FUN_10003028(piVar1,(undefined2 *)&stack0xfffffffa), iVar3 < 0))
      goto LAB_10002148;
      puVar9 = (undefined4 *)(uint)uVar10;
      break;
    case (undefined4 *)0xf6:
      sVar6 = FUN_10003065(piVar1,(undefined4 *)&stack0xfffffff4);
      if (((int)sVar6 < 0) || (iVar3 = FUN_10003015(piVar1,&param_3), iVar3 < 0)) goto LAB_10002148;
      puVar9 = (undefined4 *)((uint)param_3 & 0xff);
      break;
    case (undefined4 *)0xf7:
      iVar3 = FUN_10003028(piVar1,(undefined2 *)&stack0xfffffffa);
      if ((-1 < iVar3) &&
         (sVar6 = FUN_10003065(piVar1,(undefined4 *)&stack0xfffffff4), -1 < (int)sVar6))
      goto LAB_100022b1;
      goto LAB_10002148;
    case (undefined4 *)0xf8:
      iVar3 = FUN_10003028(piVar1,(undefined2 *)&stack0xfffffffa);
      if ((-1 < iVar3) && (iVar3 = FUN_10003028(piVar1,(undefined2 *)&stack0xfffffff0), -1 < iVar3))
      {
        puVar9 = (undefined4 *)(unaff_EDI & 0xffff);
        goto LAB_100022b1;
      }
      goto LAB_10002148;
    case (undefined4 *)0xf9:
      iVar3 = FUN_10003028(piVar1,(undefined2 *)&stack0xfffffffa);
      if ((iVar3 < 0) || (iVar3 = FUN_10003015(piVar1,&param_3), iVar3 < 0)) goto LAB_10002148;
      puVar9 = (undefined4 *)((uint)param_3 & 0xff);
LAB_100022b1:
      puVar8 = (undefined4 *)(uint)uVar10;
      break;
    default:
switchD_10002193_caseD_fa:
LAB_10002130:
      iVar3 = FUN_10002432(local_1014,piVar1,(size_t)puVar4,puVar2);
      goto LAB_10002140;
    case (undefined4 *)0xfc:
      iVar3 = FUN_10003015(piVar1,&param_3);
      if ((-1 < iVar3) &&
         (sVar6 = FUN_10003065(piVar1,(undefined4 *)&stack0xfffffff4), -1 < (int)sVar6))
      goto LAB_1000221d;
      goto LAB_10002148;
    case (undefined4 *)0xfd:
      iVar3 = FUN_10003015(piVar1,&param_3);
      if ((-1 < iVar3) && (iVar3 = FUN_10003028(piVar1,(undefined2 *)&stack0xfffffffa), -1 < iVar3))
      {
        puVar9 = (undefined4 *)(uint)uVar10;
        goto LAB_1000221d;
      }
      goto LAB_10002148;
    case (undefined4 *)0xfe:
      iVar3 = FUN_10003015(piVar1,&param_3);
      if ((iVar3 < 0) || (iVar3 = FUN_10003015(piVar1,&stack0xfffffff3), iVar3 < 0))
      goto LAB_10002148;
      puVar9 = (undefined4 *)(unaff_EDI >> 0x18);
LAB_1000221d:
      puVar8 = (undefined4 *)((uint)param_3 & 0xff);
      break;
    case (undefined4 *)0xff:
      return iVar7;
    }
    uStackY_28 = 0x10002358;
    iVar3 = FUN_100023b2(local_1014,param_1,(long)puVar8,(size_t)puVar9,puVar2);
LAB_10002140:
    iVar7 = iVar7 + iVar3;
  }
LAB_10002148:
  puVar5 = (uint *)FUN_10002fe7((int)piVar1);
  FUN_1000c245(puVar5);
  return -1;
}



/* VA 100023b2 */

undefined4 __cdecl
FUN_100023b2(void *param_1,int *param_2,long param_3,size_t param_4,undefined4 *param_5)

{
  size_t sVar1;
  int iVar2;
  int iVar3;

  FUN_10002fcc((int)param_2,param_3);
  while( true ) {
    if ((int)param_4 < 1) {
      return 0;
    }
    sVar1 = 0x1000;
    if ((int)param_4 < 0x1001) {
      sVar1 = param_4;
    }
    sVar1 = FUN_10002d96(param_2,param_1,sVar1);
    if ((int)sVar1 < 0) break;
    for (iVar2 = FUN_1000627c(param_5,param_1,sVar1); iVar2 < (int)sVar1; iVar2 = iVar2 + iVar3) {
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      iVar3 = FUN_1000627c(param_5,(void *)(iVar2 + (int)param_1),sVar1 - iVar2);
    }
    param_4 = param_4 - sVar1;
  }
  return 0xffffffff;
}



/* VA 10002432 */

undefined4 __cdecl FUN_10002432(void *param_1,int *param_2,size_t param_3,undefined4 *param_4)

{
  size_t sVar1;
  int iVar2;
  int iVar3;

  while( true ) {
    if ((int)param_3 < 1) {
      return 0;
    }
    sVar1 = 0x1000;
    if ((int)param_3 < 0x1001) {
      sVar1 = param_3;
    }
    sVar1 = FUN_10002d96(param_2,param_1,sVar1);
    if ((int)sVar1 < 0) break;
    for (iVar2 = FUN_1000627c(param_4,param_1,sVar1); iVar2 < (int)sVar1; iVar2 = iVar2 + iVar3) {
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      iVar3 = FUN_1000627c(param_4,(void *)(iVar2 + (int)param_1),sVar1 - iVar2);
    }
    param_3 = param_3 - sVar1;
  }
  return 0xffffffff;
}



/* VA 100024a5 */

void __cdecl FUN_100024a5(undefined4 param_1)

{
  FUN_10003563(param_1);
  return;
}



/* VA 100024b0 */

int __cdecl FUN_100024b0(char *param_1)

{
  int iVar1;

  iVar1 = FUN_100024a5(param_1);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = _mkdir(param_1);
  return iVar1;
}



/* VA 100024cd */

int __cdecl FUN_100024cd(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char local_20c [260];
  char local_108 [260];

  iVar1 = FUN_100024a5(param_1);
  if (iVar1 != 0) {
    strcpy(local_20c,param_2);
    pcVar2 = local_20c;
    while (local_20c[0] != '\0') {
      if (*pcVar2 == '/') {
        *pcVar2 = '\\';
      }
      pcVar2 = pcVar2 + 1;
      local_20c[0] = *pcVar2;
    }
    strcpy(local_108,param_1);
    strcat(local_108,&DAT_10017064);
    pcVar2 = strchr(local_20c,0x5c);
    if (pcVar2 == (char *)0x0) {
      strcat(local_108,local_20c);
      iVar1 = FUN_100024a5(local_108);
      if (iVar1 == 0) {
        iVar1 = FUN_100024b0(local_108);
        return iVar1;
      }
      return 0;
    }
    strncat(local_108,local_20c,(int)pcVar2 - (int)local_20c);
    iVar1 = FUN_100024a5(local_108);
    if ((iVar1 != 0) || (iVar1 = FUN_100024b0(local_108), iVar1 == 0)) {
      for (; *pcVar2 == '\\'; pcVar2 = pcVar2 + 1) {
      }
      iVar1 = FUN_100024cd(local_108,pcVar2);
      return iVar1;
    }
  }
  return -1;
}



/* VA 100025ea */

undefined4 __cdecl FUN_100025ea(char *param_1)

{
  char *_Source;
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  char local_110 [260];
  undefined4 *local_c;
  uint local_8;

  _Source = param_1;
  iVar4 = 0;
  local_8 = 0;
  puVar1 = FUN_10002699(param_1,(size_t *)&param_1);
  local_c = puVar1;
  if (param_1 == (char *)0xffffffff) {
    uVar2 = FUN_1000341d(_Source);
  }
  else {
    if (0 < (int)param_1) {
      do {
        strcpy(local_110,_Source);
        strcat(local_110,&DAT_10017064);
        strcat(local_110,(char *)*puVar1);
        uVar3 = FUN_100025ea(local_110);
        local_8 = local_8 & uVar3;
        iVar4 = iVar4 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar4 < (int)param_1);
    }
    FUN_10002809(local_c,(int)param_1);
    iVar4 = _rmdir(_Source);
    if ((iVar4 == 0) || (local_8 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* VA 10002699 */

void * __cdecl FUN_10002699(char *param_1,size_t *param_2)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  HANDLE hFindFile;
  BOOL BVar4;
  _WIN32_FIND_DATAA local_158;
  void *local_18;
  char *local_14;
  size_t local_10;
  size_t local_c;
  void *local_8;

  local_c = 0;
  local_10 = 10;
  iVar1 = FUN_100024a5(param_1);
  if (iVar1 == 0) {
    if (param_2 != (size_t *)0x0) {
      *param_2 = 0xffffffff;
    }
    local_8 = (void *)0x0;
  }
  else {
    local_8 = calloc(10,4);
    sVar2 = strlen(param_1);
    pcVar3 = malloc(sVar2 + 3);
    local_14 = pcVar3;
    strcpy(pcVar3,param_1);
    strcat(pcVar3,&DAT_10017070);
    hFindFile = FindFirstFileA(pcVar3,&local_158);
    if (hFindFile == (HANDLE)0xffffffff) {
      local_c = 0xffffffff;
    }
    else {
      sVar2 = local_c << 2;
      do {
        if (local_c == local_10) {
          local_10 = local_10 + 0x14;
          local_18 = calloc(local_10,4);
          memcpy(local_18,local_8,sVar2);
          free(local_8);
          local_8 = local_18;
        }
        iVar1 = strcmp(local_158.cFileName,&DAT_1001706c);
        if ((iVar1 != 0) && (iVar1 = strcmp(local_158.cFileName,&DAT_10017068), iVar1 != 0)) {
          pcVar3 = _strdup(local_158.cFileName);
          local_c = local_c + 1;
          *(char **)((int)local_8 + sVar2) = pcVar3;
          sVar2 = sVar2 + 4;
        }
        BVar4 = FindNextFileA(hFindFile,&local_158);
      } while ((char)BVar4 != '\0');
    }
    free(local_14);
    if (hFindFile != (HANDLE)0xffffffff) {
      FindClose(hFindFile);
    }
    sVar2 = local_c;
    if ((int)local_c < 0) {
      free(local_8);
      local_8 = (void *)0x0;
    }
    if (param_2 != (size_t *)0x0) {
      *param_2 = sVar2;
    }
  }
  return local_8;
}



/* VA 10002809 */

void __cdecl FUN_10002809(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;

  puVar1 = param_1;
  if (0 < param_2) {
    do {
      free((void *)*puVar1);
      param_2 = param_2 + -1;
      puVar1 = puVar1 + 1;
    } while (param_2 != 0);
  }
  free(param_1);
  return;
}



/* VA 10002834 */

void __cdecl FUN_10002834(int *param_1)

{
  if (0 < param_1[1]) {
    FUN_10002d3c(*param_1);
    param_1[1] = 0;
  }
  FUN_10002b90(*param_1);
  return;
}



/* VA 10002866 */

undefined4 * __cdecl FUN_10002866(undefined4 param_1)

{
  undefined4 *puVar1;
  void *pvVar2;

  puVar1 = malloc(0x14);
  puVar1[1] = 0;
  puVar1[2] = 0;
  *puVar1 = param_1;
  puVar1[3] = 0x1000;
  pvVar2 = malloc(0x1000);
  puVar1[4] = pvVar2;
  return puVar1;
}



/* VA 10002897 */

void __cdecl FUN_10002897(int *param_1)

{
  FUN_10002834(param_1);
  FUN_10002a4e((int *)*param_1);
  free((void *)param_1[4]);
  free(param_1);
  return;
}



/* VA 100028bf */

int __cdecl FUN_100028bf(int *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  int local_8;

  piVar3 = param_1;
  sVar4 = 0;
  iVar2 = param_1[4];
  iVar6 = param_1[1];
  uVar5 = param_1[2];
  local_8 = 0;
  if (0 < param_3) {
    param_1 = (int *)param_3;
    do {
      bVar1 = *param_2;
      iVar6 = iVar6 + 8;
      param_2 = param_2 + 1;
      uVar5 = uVar5 << 8 | (uint)bVar1;
      while (5 < iVar6) {
        iVar6 = iVar6 + -6;
        *(byte *)(sVar4 + iVar2) = ((byte)((int)uVar5 >> ((byte)iVar6 & 0x1f)) & 0x3f) + 0x20;
        sVar4 = sVar4 + 1;
        if (sVar4 == piVar3[3]) {
          sVar4 = FUN_10002ae4(*piVar3,iVar2,sVar4);
          local_8 = local_8 + sVar4;
          sVar4 = 0;
        }
      }
      param_1 = (int *)((int)param_1 + -1);
    } while (param_1 != (int *)0x0);
  }
  piVar3[1] = iVar6;
  piVar3[2] = uVar5;
  if (0 < (int)sVar4) {
    sVar4 = FUN_10002ae4(*piVar3,iVar2,sVar4);
    local_8 = local_8 + sVar4;
  }
  return local_8;
}



/* VA 10002958 */

void * __cdecl FUN_10002958(byte *param_1,int param_2,size_t *param_3)

{
  size_t _Size;
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;

  _Size = (param_2 * 8 + 5) / 6;
  pvVar1 = malloc(_Size);
  uVar2 = FUN_100029f5(pvVar1,_Size);
  piVar3 = FUN_10002866(uVar2);
  FUN_100028bf(piVar3,param_1,param_2);
  FUN_10002897(piVar3);
  *param_3 = _Size;
  return pvVar1;
}



/* VA 100029af */

int __cdecl FUN_100029af(int param_1)

{
  return (param_1 * 8 + 5) / 6;
}



/* VA 100029c1 */

undefined4 * FUN_100029c1(void)

{
  undefined4 *puVar1;
  void *pvVar2;

  puVar1 = malloc(0x14);
  *puVar1 = 1;
  pvVar2 = malloc(0x1000);
  puVar1[2] = 0;
  puVar1[4] = 0;
  puVar1[1] = pvVar2;
  puVar1[3] = 0x1000;
  return puVar1;
}



/* VA 100029f5 */

void __cdecl FUN_100029f5(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;

  puVar1 = malloc(0x14);
  puVar1[1] = param_1;
  puVar1[3] = param_2;
  *puVar1 = 0;
  puVar1[2] = 0;
  puVar1[4] = 0;
  return;
}



/* VA 10002a17 */

undefined4 * __cdecl FUN_10002a17(undefined4 param_1)

{
  undefined4 *puVar1;
  void *pvVar2;

  puVar1 = malloc(0x14);
  *puVar1 = 1;
  pvVar2 = malloc(0x1000);
  puVar1[2] = 0;
  puVar1[1] = pvVar2;
  puVar1[4] = param_1;
  puVar1[3] = 0x1000;
  return puVar1;
}



/* VA 10002a4e */

void __cdecl FUN_10002a4e(int *param_1)

{
  if (param_1[4] != 0) {
    FUN_10002a79((int)param_1);
  }
  if (*param_1 != 0) {
    free((void *)param_1[1]);
  }
  free(param_1);
  return;
}



/* VA 10002a79 */

undefined4 __cdecl FUN_10002a79(int param_1)

{
  size_t _Size;
  void *_Dst;
  int iVar1;
  int iVar2;

  iVar2 = 0;
  if (*(int *)(param_1 + 0x10) == 0) {
    _Size = *(int *)(param_1 + 0xc) << 1;
    *(size_t *)(param_1 + 0xc) = _Size;
    _Dst = malloc(_Size);
    memcpy(_Dst,*(void **)(param_1 + 4),*(size_t *)(param_1 + 8));
    free(*(void **)(param_1 + 4));
    *(void **)(param_1 + 4) = _Dst;
  }
  else {
    while (0 < *(int *)(param_1 + 8)) {
      iVar1 = FUN_1000c0c5(*(int **)(param_1 + 0x10),(char *)(iVar2 + *(int *)(param_1 + 4)),
                           *(uint *)(param_1 + 8));
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      iVar2 = iVar2 + iVar1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - iVar1;
    }
  }
  return 0;
}



/* VA 10002ae4 */

size_t __cdecl FUN_10002ae4(int param_1,int param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  size_t _Size;
  undefined4 local_8;

  iVar2 = 0;
  local_8 = 0;
  while( true ) {
    _Size = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8);
    if ((int)param_3 <= (int)_Size) break;
    memcpy((void *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8)),(void *)(param_2 + iVar2),_Size);
    param_3 = param_3 - _Size;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + _Size;
    iVar2 = iVar2 + _Size;
    iVar1 = FUN_10002a79(param_1);
    local_8 = local_8 + iVar1;
  }
  if (0 < (int)param_3) {
    memcpy((void *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8)),(void *)(iVar2 + param_2),param_3
          );
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3;
  }
  if (local_8 != 0) {
    param_3 = 0xffffffff;
  }
  return param_3;
}



/* VA 10002b60 */

int __cdecl FUN_10002b60(int param_1,char *param_2)

{
  size_t sVar1;

  if (param_2 == (char *)0x0) {
    param_2 = &DAT_10017074;
  }
  sVar1 = strlen(param_2);
  sVar1 = FUN_10002ae4(param_1,(int)param_2,sVar1);
  return (sVar1 != 0xffffffff) - 1;
}



/* VA 10002b90 */

int __cdecl FUN_10002b90(int param_1)

{
  int iVar1;

  if (*(int *)(param_1 + 0x10) == 0) {
    return 0;
  }
  iVar1 = FUN_10002a79(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  iVar1 = FUN_1000c13e(*(int **)(param_1 + 0x10));
  return iVar1;
}



/* VA 10002bba */

undefined4 __cdecl FUN_10002bba(int param_1)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    return *(undefined4 *)(param_1 + 8);
  }
  return 0xffffffff;
}



/* VA 10002bcc */

void * __cdecl FUN_10002bcc(int param_1)

{
  void *_Dst;

  _Dst = malloc(*(size_t *)(param_1 + 8));
  memcpy(_Dst,*(void **)(param_1 + 4),*(size_t *)(param_1 + 8));
  return _Dst;
}



/* VA 10002bf2 */

void * __cdecl FUN_10002bf2(int param_1)

{
  void *_Dst;

  _Dst = malloc(*(int *)(param_1 + 8) + 1);
  memcpy(_Dst,*(void **)(param_1 + 4),*(size_t *)(param_1 + 8));
  *(undefined1 *)((int)_Dst + *(int *)(param_1 + 8)) = 0;
  return _Dst;
}



/* VA 10002c21 */

void __cdecl FUN_10002c21(int param_1,undefined4 param_2)

{
  param_2 = CONCAT31(CONCAT21(param_2._2_2_,(char)param_2),(char)((uint)param_2 >> 8));
  FUN_10002ae4(param_1,(int)&param_2,2);
  return;
}



/* VA 10002c45 */

void __cdecl FUN_10002c45(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;

  uVar3 = param_2;
  uVar1 = (uint)param_2 >> 0x18;
  uVar2 = (uint)param_2 >> 0x10;
  param_2._3_1_ = (undefined1)uVar3;
  param_2._0_3_ = CONCAT12((char)((uint)uVar3 >> 8),CONCAT11((char)uVar2,(char)uVar1));
  FUN_10002ae4(param_1,(int)&param_2,4);
  return;
}



/* VA 10002c79 */

void __cdecl FUN_10002c79(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;

  iVar2 = param_3;
  uVar1 = param_2;
  uVar3 = __allshr(0x38,param_3);
  param_2 = CONCAT31(param_2._1_3_,(char)uVar3);
  uVar3 = __allshr(0x30,iVar2);
  param_2._0_2_ = CONCAT11((char)uVar3,(undefined1)param_2);
  uVar3 = __allshr(0x28,iVar2);
  param_2._0_3_ = CONCAT12((char)uVar3,(undefined2)param_2);
  uVar3 = __allshr(0x20,iVar2);
  param_2 = CONCAT13((char)uVar3,(undefined3)param_2);
  uVar3 = __allshr(0x18,iVar2);
  param_3 = CONCAT31(param_3._1_3_,(char)uVar3);
  uVar3 = __allshr(0x10,iVar2);
  param_3._0_2_ = CONCAT11((char)uVar3,(undefined1)param_3);
  uVar3 = __allshr(8,iVar2);
  param_3 = CONCAT13((char)uVar1,CONCAT12((char)uVar3,(undefined2)param_3));
  FUN_10002ae4(param_1,(int)&param_2,8);
  return;
}



/* VA 10002d05 */

int __cdecl FUN_10002d05(int param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;

  sVar1 = strlen(param_2);
  iVar2 = FUN_10002c21(param_1,sVar1);
  sVar1 = FUN_10002ae4(param_1,(int)param_2,(int)(short)sVar1);
  return iVar2 + sVar1;
}



/* VA 10002d3c */

void __cdecl FUN_10002d3c(int param_1)

{
  FUN_10002ae4(param_1,(int)&stack0x00000008,1);
  return;
}



/* VA 10002d50 */

undefined4 * __cdecl FUN_10002d50(undefined4 param_1)

{
  undefined4 *puVar1;
  void *pvVar2;

  puVar1 = malloc(0x2c);
  pvVar2 = malloc(0x1000);
  *puVar1 = pvVar2;
  puVar1[7] = 0xffffffff;
  puVar1[4] = param_1;
  puVar1[9] = puVar1 + 10;
  puVar1[10] = 0;
  puVar1[3] = 0x1000;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  return puVar1;
}



/* VA 10002d96 */

size_t __cdecl FUN_10002d96(int *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  undefined3 extraout_var_00;
  size_t sVar6;
  int iVar7;

  piVar1 = param_1;
  if (param_1[5] == 0) {
    sVar6 = FUN_10002f1c(param_1,param_2,param_3);
  }
  else {
    piVar3 = (int *)mrb_inflateTotalIn(param_1[6]);
    bVar2 = mrb_inflateNeedsInput(param_1[6]);
    if (CONCAT31(extraout_var,bVar2) == 0) goto LAB_10002e17;
    do {
      iVar7 = param_1[1] - param_1[2];
      if ((0x200 < iVar7) || (uVar4 = FUN_1000c1d1((uint *)param_1[4]), uVar4 != 0)) {
        do {
          param_1 = piVar3;
          iVar5 = piVar1[7] - (int)param_1;
          if (iVar7 < piVar1[7] - (int)param_1) {
            iVar5 = iVar7;
          }
          mrb_inflateSetInput((undefined4 *)piVar1[6],*piVar1,piVar1[2],iVar5);
          piVar3 = (int *)mrb_inflateTotalIn(piVar1[6]);
LAB_10002e17:
          do {
            param_1 = piVar3;
            sVar6 = mrb_inflate((int *)piVar1[6],(int)param_2,0,param_3);
            if ((sVar6 != 0) || (iVar7 = mrb_inflateFinished(piVar1[6]), iVar7 != 0)) {
              if (-1 < (int)sVar6) {
                iVar7 = mrb_inflateTotalIn(piVar1[6]);
                piVar1[8] = iVar7;
                iVar7 = mrb_inflateTotalIn(piVar1[6]);
                piVar1[2] = piVar1[2] + (iVar7 - (int)param_1);
                iVar7 = mrb_inflateFinished(piVar1[6]);
                if (iVar7 == 0) {
                  return sVar6;
                }
                FUN_1000331b((int)piVar1);
                return sVar6;
              }
              goto LAB_10002e72;
            }
            bVar2 = mrb_inflateNeedsInput(piVar1[6]);
            piVar3 = param_1;
          } while (CONCAT31(extraout_var_00,bVar2) == 0);
          while ((iVar7 = piVar1[1] - piVar1[2], iVar7 < 0x201 &&
                 (uVar4 = FUN_1000c1d1((uint *)piVar1[4]), uVar4 == 0))) {
            iVar7 = FUN_10002ebe(piVar1);
            if (iVar7 < 0) goto LAB_10002e72;
          }
        } while( true );
      }
      iVar7 = FUN_10002ebe(param_1);
    } while (-1 < iVar7);
LAB_10002e72:
    sVar6 = 0xffffffff;
  }
  return sVar6;
}



/* VA 10002ebe */

int __cdecl FUN_10002ebe(int *param_1)

{
  int iVar1;

  iVar1 = param_1[2];
  if (iVar1 < param_1[1]) {
    memmove((void *)*param_1,(void *)(*param_1 + iVar1),param_1[1] - iVar1);
  }
  iVar1 = param_1[2];
  param_1[2] = 0;
  param_1[1] = param_1[1] - iVar1;
  iVar1 = param_1[1];
  if (iVar1 < 0x1000) {
    iVar1 = FUN_1000c048((int *)param_1[4],(char *)(*param_1 + iVar1),0x1000 - iVar1);
    if (-1 < iVar1) {
      param_1[1] = param_1[1] + iVar1;
      *(int *)param_1[9] = *(int *)param_1[9] + iVar1;
      return iVar1;
    }
  }
  return -1;
}



/* VA 10002f1c */

size_t __cdecl FUN_10002f1c(int *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;

  iVar2 = param_1[2];
  sVar1 = param_1[1] - iVar2;
  if ((int)sVar1 < 1) {
    iVar2 = FUN_10002ebe(param_1);
    if (-1 < iVar2) {
      iVar2 = param_1[2];
      sVar1 = param_1[1] - iVar2;
      if (-1 < (int)sVar1) goto LAB_10002f48;
    }
    param_3 = 0xffffffff;
  }
  else {
LAB_10002f48:
    if ((int)sVar1 < (int)param_3) {
      param_3 = sVar1;
    }
    memcpy(param_2,(void *)(*param_1 + iVar2),param_3);
    param_1[2] = param_1[2] + param_3;
  }
  return param_3;
}



/* VA 10002f6c */

size_t __cdecl FUN_10002f6c(int *param_1,size_t param_2)

{
  void *_Memory;
  size_t sVar1;
  int iVar2;

  iVar2 = 0;
  _Memory = malloc(param_2);
  if (_Memory == (void *)0x0) {
    param_2 = 0xffffffff;
  }
  else {
    if (0 < (int)param_2) {
      do {
        sVar1 = FUN_10002d96(param_1,(void *)((int)_Memory + iVar2),param_2 - iVar2);
        if ((int)sVar1 < 0) {
          free(_Memory);
          return sVar1;
        }
        iVar2 = iVar2 + sVar1;
      } while (iVar2 < (int)param_2);
    }
    free(_Memory);
  }
  return param_2;
}



/* VA 10002fcc */

void __cdecl FUN_10002fcc(int param_1,long param_2)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_1000c120(*(int **)(param_1 + 0x10),param_2);
  return;
}



/* VA 10002fe7 */

undefined4 __cdecl FUN_10002fe7(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* VA 10002fef */

void __cdecl FUN_10002fef(undefined4 *param_1)

{
  free((void *)*param_1);
  if ((void *)param_1[6] != (void *)0x0) {
    mrb_inflateTerm((void *)param_1[6]);
  }
  free(param_1);
  return;
}



/* VA 10003015 */

void __cdecl FUN_10003015(int *param_1,void *param_2)

{
  FUN_10002d96(param_1,param_2,1);
  return;
}



/* VA 10003028 */

void __cdecl FUN_10003028(int *param_1,undefined2 *param_2)

{
  size_t sVar1;
  int iVar2;
  undefined2 local_6;

  iVar2 = 0;
  do {
    sVar1 = FUN_10002d96(param_1,(void *)((int)&local_6 + iVar2),2 - iVar2);
    if ((int)sVar1 < 0) {
      return;
    }
    iVar2 = iVar2 + sVar1;
  } while (iVar2 < 2);
  *param_2 = CONCAT11((undefined1)local_6,local_6._1_1_);
  return;
}



/* VA 10003065 */

size_t __cdecl FUN_10003065(int *param_1,undefined4 *param_2)

{
  size_t sVar1;
  size_t sVar2;
  undefined4 local_8;

  sVar2 = 0;
  do {
    sVar1 = FUN_10002d96(param_1,(void *)((int)&local_8 + sVar2),4 - sVar2);
    if ((int)sVar1 < 0) {
      return sVar1;
    }
    sVar2 = sVar2 + sVar1;
  } while ((int)sVar2 < 4);
  *param_2 = CONCAT31(CONCAT21(CONCAT11((undefined1)local_8,local_8._1_1_),local_8._2_1_),
                      local_8._3_1_);
  return sVar2;
}



/* VA 100030b4 */

size_t __cdecl FUN_100030b4(int *param_1,uint *param_2)

{
  size_t sVar1;
  int iVar2;
  longlong lVar3;
  undefined1 local_10 [7];
  byte local_9;
  int local_8;

  iVar2 = 0;
  do {
    sVar1 = FUN_10002d96(param_1,local_10 + iVar2,8 - iVar2);
    if ((int)sVar1 < 0) {
      return sVar1;
    }
    iVar2 = iVar2 + sVar1;
  } while (iVar2 < 8);
  lVar3 = __allshl(8,0);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  *param_2 = (uint)lVar3 | (uint)local_9;
  param_2[1] = (uint)((ulonglong)lVar3 >> 0x20);
  return 0;
}



/* VA 100031e5 */

size_t __cdecl FUN_100031e5(int *param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  size_t sVar4;
  undefined4 uStack_8;

  sVar4 = 0;
  iVar1 = FUN_10003028(param_1,(undefined2 *)((int)&uStack_8 + 2));
  if (iVar1 < 0) {
    sVar4 = 0xffffffff;
  }
  else {
    pvVar2 = malloc((int)uStack_8._2_2_ + 1);
    *param_2 = (int)pvVar2;
    *(undefined1 *)((int)uStack_8._2_2_ + (int)pvVar2) = 0;
    iVar1 = (int)uStack_8._2_2_;
    if (0 < iVar1) {
      do {
        sVar3 = FUN_10002d96(param_1,(void *)(*param_2 + sVar4),iVar1 - sVar4);
        if ((int)sVar3 < 0) {
          free((void *)*param_2);
          return sVar3;
        }
        iVar1 = (int)uStack_8._2_2_;
        sVar4 = sVar4 + sVar3;
      } while ((int)sVar4 < iVar1);
    }
  }
  return sVar4;
}



/* VA 1000325e */

int __cdecl FUN_1000325e(int *param_1,undefined4 *param_2)

{
  char *_Src;
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uStack_8;

  iVar3 = 0;
  _Src = malloc(0x400);
  while( true ) {
    iVar1 = FUN_10003015(param_1,(void *)((int)&uStack_8 + 3));
    if (iVar1 != 1) break;
    if (uStack_8._3_1_ == '\r') {
      iVar1 = FUN_10003015(param_1,(void *)((int)&uStack_8 + 3));
      if (iVar1 != 1) break;
      if (uStack_8._3_1_ == '\n') goto LAB_100032c9;
      _Src[iVar3] = '\r';
      iVar3 = iVar3 + 1;
    }
    _Src[iVar3] = uStack_8._3_1_;
    iVar3 = iVar3 + 1;
  }
  if (iVar3 < 1) {
    free(_Src);
  }
  else {
LAB_100032c9:
    _Src[iVar3] = '\0';
    pcVar2 = _strdup(_Src);
    *param_2 = pcVar2;
    free(_Src);
    iVar1 = 0;
  }
  return iVar1;
}



/* VA 100032e9 */

undefined4 __cdecl FUN_100032e9(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;

  if (*(int *)(param_1 + 0x18) == 0) {
    puVar1 = mrb_inflateInit();
    *(undefined4 **)(param_1 + 0x18) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return 0;
}



/* VA 1000331b */

void __cdecl FUN_1000331b(int param_1)

{
  int iVar1;
  int iVar2;
  size_t sVar3;

  if (*(int *)(param_1 + 0x14) != 0) {
    iVar2 = mrb_inflateTotalIn(*(int *)(param_1 + 0x18));
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
    sVar3 = iVar1 - iVar2;
    mrb_inflateReset(*(int *)(param_1 + 0x18));
    if (0 < (int)sVar3) {
      FUN_10002f6c(param_1,sVar3);
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + sVar3;
    }
  }
  return;
}



/* VA 10003359 */

undefined4 __cdecl FUN_10003359(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



/* VA 10003361 */

void __cdecl FUN_10003361(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_2 = param_1 + 0x28;
  }
  *(int *)(param_1 + 0x24) = param_2;
  return;
}



/* VA 10003374 */

void __cdecl FUN_10003374(char *param_1)

{
  _open(param_1,0x8000,0);
  return;
}



/* VA 10003389 */

void __cdecl FUN_10003389(char *param_1)

{
  _open(param_1,0x8301,0x80);
  return;
}



/* VA 100033a1 */

void __cdecl FUN_100033a1(char *param_1)

{
  _open(param_1,0x8102,0x80);
  return;
}



/* VA 100033b9 */

void __cdecl FUN_100033b9(int param_1)

{
  _close(param_1);
  return;
}



/* VA 100033c5 */

void __cdecl FUN_100033c5(int param_1)

{
  _tell(param_1);
  return;
}



/* VA 100033d1 */

void __cdecl FUN_100033d1(int param_1,long param_2)

{
  _lseek(param_1,param_2,0);
  return;
}



/* VA 100033e5 */

void __cdecl FUN_100033e5(int param_1)

{
  _filelength(param_1);
  return;
}



/* VA 100033f1 */

undefined4 __cdecl FUN_100033f1(char *param_1)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_10003374(param_1);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  uVar2 = FUN_100033e5(iVar1);
  FUN_100033b9(iVar1);
  return uVar2;
}



/* VA 1000341d */

void __cdecl FUN_1000341d(char *param_1)

{
  _unlink(param_1);
  return;
}



/* VA 10003429 */

int __cdecl FUN_10003429(char *param_1,char *param_2)

{
  int iVar1;
  BOOL BVar2;
  char *_FullPath;
  char local_20c [260];
  char local_108 [260];

  _FullPath = param_1;
  iVar1 = _stricmp(param_1,param_2);
  if (iVar1 == 0) {
    _splitpath(_FullPath,(char *)&param_1,local_20c,(char *)0x0,(char *)0x0);
    sprintf(local_108,s__s_s_mrb__1001707c,&param_1,local_20c);
    BVar2 = MoveFileA(_FullPath,local_108);
    if (BVar2 == 0) {
      return -1;
    }
    _FullPath = local_108;
  }
  BVar2 = MoveFileA(_FullPath,param_2);
  return (BVar2 != 0) - 1;
}



/* VA 100034b0 */

bool __cdecl FUN_100034b0(undefined4 param_1)

{
  int iVar1;
  undefined1 local_28 [36];

  iVar1 = stat(param_1,local_28);
  return (bool)('\x01' - (iVar1 != 0));
}



/* VA 100034cc */

bool __cdecl FUN_100034cc(LPCSTR param_1)

{
  HANDLE hFindFile;
  DWORD DVar1;
  int iVar2;
  CHAR local_24c [260];
  _WIN32_FIND_DATAA local_148;
  char *local_8;

  hFindFile = FindFirstFileA(param_1,&local_148);
  if (hFindFile != (HANDLE)0xffffffff) {
    FindClose(hFindFile);
    DVar1 = GetFullPathNameA(param_1,0x104,local_24c,&local_8);
    if (DVar1 != 0) {
      iVar2 = strcmp(local_8,local_148.cFileName);
      return (bool)('\x01' - (iVar2 != 0));
    }
  }
  return false;
}



/* VA 1000352a */

char * __cdecl FUN_1000352a(LPCSTR param_1)

{
  HANDLE hFindFile;
  char *pcVar1;
  _WIN32_FIND_DATAA local_144;

  hFindFile = FindFirstFileA(param_1,&local_144);
  if (hFindFile == (HANDLE)0xffffffff) {
    return (char *)0x0;
  }
  FindClose(hFindFile);
  pcVar1 = _strdup(local_144.cFileName);
  return pcVar1;
}



/* VA 10003563 */

undefined4 __cdecl FUN_10003563(undefined4 param_1)

{
  int iVar1;
  undefined1 local_28 [7];
  byte local_21;

  iVar1 = stat(param_1,local_28);
  if ((iVar1 == 0) && ((local_21 & 0x40) != 0)) {
    return 1;
  }
  return 0;
}



/* VA 1000358b */

undefined4 __cdecl FUN_1000358b(undefined4 param_1)

{
  int iVar1;
  undefined1 local_28 [6];
  byte local_22;

  iVar1 = stat(param_1,local_28);
  if ((iVar1 == 0) && ((local_22 & 0x80) != 0)) {
    return 1;
  }
  return 0;
}



/* VA 100035b3 */

undefined4 __cdecl FUN_100035b3(undefined4 param_1)

{
  int iVar1;
  undefined1 local_28 [7];
  byte local_21;

  iVar1 = stat(param_1,local_28);
  if ((iVar1 == 0) && ((local_21 & 1) != 0)) {
    return 1;
  }
  return 0;
}



/* VA 100035db */

void __cdecl FUN_100035db(char *param_1)

{
  _chmod(param_1,0x180);
  return;
}



/* VA 100035ed */

void __cdecl FUN_100035ed(char *param_1)

{
  _chmod(param_1,0x100);
  return;
}



/* VA 100035ff */

void * __cdecl FUN_100035ff(char *param_1,size_t *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int _FileHandle;
  size_t _Size;
  int iVar2;
  void *_Memory;
  int iVar3;

  _Memory = (void *)0x0;
  bVar1 = FUN_100034b0(param_1);
  if ((CONCAT31(extraout_var,bVar1) == 0) ||
     (_FileHandle = FUN_10003374(param_1), _FileHandle == -1)) {
    return (void *)0x0;
  }
  _Size = FUN_100033e5(_FileHandle);
  if (_Size != 0xffffffff) {
    *param_2 = _Size;
    _Memory = malloc(_Size);
    if (_Memory != (void *)0x0) {
      iVar3 = 0;
      for (; 0 < (int)_Size; _Size = _Size - iVar2) {
        iVar2 = _read(_FileHandle,(void *)(iVar3 + (int)_Memory),_Size);
        if (iVar2 < 0) {
          free(_Memory);
          _Memory = (void *)0x0;
          break;
        }
        iVar3 = iVar3 + iVar2;
      }
    }
  }
  FUN_100033b9(_FileHandle);
  return _Memory;
}



/* VA 10003685 */

undefined4 __cdecl FUN_10003685(LPCSTR param_1,ushort *param_2)

{
  DWORD DVar1;
  ushort uVar2;

  uVar2 = 1;
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    return 0xffffffff;
  }
  if ((DVar1 & 1) == 0) {
    uVar2 = 3;
  }
  if ((DVar1 & 0x20) != 0) {
    uVar2 = uVar2 | 0x10;
  }
  if ((DVar1 & 2) != 0) {
    uVar2 = uVar2 | 8;
  }
  *param_2 = uVar2;
  return 0;
}



/* VA 100036bc */

int __cdecl FUN_100036bc(LPCSTR param_1,byte param_2)

{
  DWORD dwFileAttributes;
  BOOL BVar1;

  dwFileAttributes = (DWORD)((param_2 & 2) == 0);
  if ((param_2 & 0x10) != 0) {
    dwFileAttributes = dwFileAttributes | 0x20;
  }
  if ((param_2 & 8) != 0) {
    dwFileAttributes = dwFileAttributes | 2;
  }
  if (dwFileAttributes == 0) {
    dwFileAttributes = 0x80;
  }
  BVar1 = SetFileAttributesA(param_1,dwFileAttributes);
  return (BVar1 != 0) - 1;
}



/* VA 100036f6 */

undefined4 * __cdecl FUN_100036f6(size_t param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;

  if (param_3 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = malloc(0x34);
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 7));
    pvVar2 = calloc(param_1,4);
    puVar1[1] = 0;
    *puVar1 = pvVar2;
    puVar1[2] = param_1;
    puVar1[4] = param_2;
    uVar3 = ftol();
    puVar1[3] = uVar3;
    puVar1[6] = param_4;
    puVar1[5] = param_3;
  }
  return puVar1;
}



/* VA 10003757 */

void __cdecl FUN_10003757(int *param_1)

{
  FUN_10003a4e(param_1);
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  free(param_1);
  return;
}



/* VA 10003785 */

undefined4 __cdecl FUN_10003785(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



/* VA 1000378d */

uint __cdecl FUN_1000378d(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;

  FUN_10003b95((int)param_1);
  if ((code *)param_1[6] == (code *)0x0) {
    uVar1 = FUN_10003b90(param_2);
  }
  else {
    uVar1 = (*(code *)param_1[6])();
  }
  puVar3 = *(uint **)(*param_1 +
                     (int)((longlong)(ulonglong)(uVar1 & 0x7fffffff) % (longlong)param_1[2]) * 4);
  while( true ) {
    if (puVar3 == (uint *)0x0) {
      FUN_10003ba4((int)param_1);
      return 0;
    }
    if ((*puVar3 == uVar1) && (iVar2 = (*(code *)param_1[5])(puVar3[1],param_2), iVar2 != 0)) break;
    puVar3 = (uint *)puVar3[5];
  }
  FUN_10003ba4((int)param_1);
  return puVar3[2];
}



/* VA 100037f6 */

void __cdecl FUN_100037f6(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



/* VA 1000381b */

undefined4 __cdecl FUN_1000381b(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;

  piVar1 = (int *)*param_1;
  FUN_10003b95((int)piVar1);
  iVar2 = param_1[1];
  if (iVar2 != piVar1[2]) {
    iVar3 = 0;
    if (param_1[2] != 0) {
      iVar3 = param_1[2];
    }
    if (iVar3 != 0) {
LAB_10003861:
      if (*(int *)(iVar3 + 0x14) == 0) {
        param_1[1] = param_1[1] + 1;
        param_1[2] = 0;
      }
      else {
        param_1[2] = *(int *)(iVar3 + 0x14);
      }
      FUN_10003ba4((int)piVar1);
      return *(undefined4 *)(iVar3 + 4);
    }
    do {
      iVar3 = *(int *)(*piVar1 + iVar2 * 4);
      if (iVar3 != 0) goto LAB_10003861;
      param_1[1] = param_1[1] + 1;
      iVar2 = param_1[1];
    } while (iVar2 != piVar1[2]);
  }
  FUN_10003ba4((int)piVar1);
  return 0;
}



/* VA 10003881 */

void __cdecl FUN_10003881(int *param_1,uint param_2,uint param_3)

{
  FUN_1000389a(param_1,param_2,1,param_3,1);
  return;
}



/* VA 1000389a */

void __cdecl FUN_1000389a(int *param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;

  FUN_10003b95((int)param_1);
  if (param_4 != 0) {
    if ((code *)param_1[6] == (code *)0x0) {
      uVar1 = FUN_10003b90(param_2);
    }
    else {
      uVar1 = (*(code *)param_1[6])();
    }
    iVar4 = (int)((longlong)(ulonglong)(uVar1 & 0x7fffffff) % (longlong)param_1[2]) * 4;
    for (puVar3 = *(uint **)(*param_1 + iVar4); puVar3 != (uint *)0x0; puVar3 = (uint *)puVar3[5]) {
      if (*puVar3 == uVar1) {
        iVar2 = (*(code *)param_1[5])(puVar3[1],param_2);
        if (iVar2 != 0) {
          if (puVar3[4] != 0) {
            free((void *)puVar3[2]);
          }
          if (puVar3[3] != 0) {
            free((void *)puVar3[1]);
          }
          puVar3[1] = param_2;
          puVar3[3] = param_3;
          puVar3[2] = param_4;
          puVar3[4] = param_5;
          goto LAB_10003991;
        }
      }
    }
    if (param_1[1] < param_1[3]) {
      puVar3 = malloc(0x18);
      *puVar3 = uVar1;
      puVar3[1] = param_2;
      puVar3[3] = param_3;
      puVar3[2] = param_4;
      puVar3[4] = param_5;
      puVar3[5] = *(uint *)(*param_1 + iVar4);
      *(uint **)(*param_1 + iVar4) = puVar3;
      param_1[1] = param_1[1] + 1;
    }
    else {
      FUN_10003a91(param_1);
      FUN_1000389a(param_1,param_2,param_3,param_4,param_5);
    }
  }
LAB_10003991:
  FUN_10003ba4((int)param_1);
  return;
}



/* VA 1000399d */

uint __cdecl FUN_1000399d(int *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *_Memory;
  uint *local_8;

  local_8 = (uint *)0x0;
  FUN_10003b95((int)param_1);
  if ((code *)param_1[6] == (code *)0x0) {
    uVar2 = FUN_10003b90(param_2);
  }
  else {
    uVar2 = (*(code *)param_1[6])();
  }
  iVar4 = (int)((longlong)(ulonglong)(uVar2 & 0x7fffffff) % (longlong)param_1[2]) * 4;
  puVar1 = *(uint **)(*param_1 + iVar4);
  while( true ) {
    _Memory = puVar1;
    if (_Memory == (uint *)0x0) {
      FUN_10003ba4((int)param_1);
      return 0;
    }
    if ((*_Memory == uVar2) && (iVar3 = (*(code *)param_1[5])(_Memory[1],param_2), iVar3 != 0))
    break;
    puVar1 = (uint *)_Memory[5];
    local_8 = _Memory;
  }
  uVar2 = _Memory[2];
  if (local_8 == (uint *)0x0) {
    *(uint *)(*param_1 + iVar4) = _Memory[5];
  }
  else {
    local_8[5] = _Memory[5];
  }
  param_1[1] = param_1[1] + -1;
  if (_Memory[3] != 0) {
    free((void *)_Memory[1]);
  }
  free(_Memory);
  FUN_10003ba4((int)param_1);
  return uVar2;
}



/* VA 10003a4e */

void __cdecl FUN_10003a4e(int *param_1)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;

  FUN_10003b95((int)param_1);
  iVar2 = 0;
  if (0 < param_1[2]) {
    do {
      pvVar3 = *(void **)(*param_1 + iVar2 * 4);
      while (pvVar3 != (void *)0x0) {
        pvVar1 = *(void **)((int)pvVar3 + 0x14);
        FUN_10003bb3(pvVar3);
        pvVar3 = pvVar1;
      }
      *(undefined4 *)(*param_1 + iVar2 * 4) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  FUN_10003ba4((int)param_1);
  return;
}



/* VA 10003a91 */

void __cdecl FUN_10003a91(undefined4 *param_1)

{
  uint *puVar1;
  size_t _Count;
  undefined4 *puVar2;
  void *_Memory;
  uint *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 *puVar7;

  puVar2 = (undefined4 *)param_1[2];
  _Memory = (void *)*param_1;
  _Count = (int)puVar2 * 2 + 1;
  pvVar4 = calloc(_Count,4);
  uVar5 = ftol();
  param_1[3] = uVar5;
  *param_1 = pvVar4;
  param_1[2] = _Count;
  if (0 < (int)puVar2) {
    puVar7 = (undefined4 *)((int)_Memory + (int)puVar2 * 4 + -4);
    param_1 = puVar2;
    do {
      puVar6 = (uint *)*puVar7;
      while (puVar6 != (uint *)0x0) {
        puVar3 = (uint *)puVar6[5];
        puVar1 = (uint *)((int)pvVar4 +
                         (int)((longlong)(ulonglong)(*puVar6 & 0x7fffffff) % (longlong)(int)_Count)
                         * 4);
        puVar6[5] = *puVar1;
        *puVar1 = (uint)puVar6;
        puVar6 = puVar3;
      }
      param_1 = (undefined4 *)((int)param_1 + -1);
      puVar7 = puVar7 + -1;
    } while (param_1 != (undefined4 *)0x0);
  }
  free(_Memory);
  return;
}



/* VA 10003b1f */

int __cdecl FUN_10003b1f(char *param_1)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  int local_8;

  iVar3 = 0;
  local_8 = 0;
  sVar1 = strlen(param_1);
  if ((int)sVar1 < 0x10) {
    if (0 < (int)sVar1) {
      do {
        local_8 = local_8 * 0x25 + (int)*param_1;
        param_1 = param_1 + 1;
        sVar1 = sVar1 - 1;
      } while (sVar1 != 0);
    }
  }
  else {
    iVar2 = (int)sVar1 / 8;
    for (; 0 < (int)sVar1; sVar1 = sVar1 - iVar2) {
      local_8 = (int)param_1[iVar3] + local_8 * 0x27;
      iVar3 = iVar3 + iVar2;
    }
  }
  return local_8;
}



/* VA 10003b90 */

undefined4 __cdecl FUN_10003b90(undefined4 param_1)

{
  return param_1;
}



/* VA 10003b95 */

void __cdecl FUN_10003b95(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return;
}



/* VA 10003ba4 */

void __cdecl FUN_10003ba4(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return;
}



/* VA 10003bb3 */

void __cdecl FUN_10003bb3(void *param_1)

{
  if ((*(int *)((int)param_1 + 0xc) != 0) && (*(void **)((int)param_1 + 4) != (void *)0x0)) {
    free(*(void **)((int)param_1 + 4));
  }
  if ((*(int *)((int)param_1 + 0x10) != 0) && (*(void **)((int)param_1 + 8) != (void *)0x0)) {
    free(*(void **)((int)param_1 + 8));
  }
  free(param_1);
  return;
}



/* VA 10003be8 */

undefined4 * __cdecl
FUN_10003be8(char *param_1,char *param_2,undefined4 param_3,char *param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *_Dest;

  iVar1 = FUN_10003cb7();
  if (iVar1 != 0) {
    return (undefined4 *)0x0;
  }
  puVar2 = malloc(0x20);
  puVar2[7] = 0;
  if (param_1 == (char *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = _strdup(param_1);
  }
  *puVar2 = pcVar3;
  if (param_2 == (char *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = _strdup(param_2);
  }
  puVar2[1] = pcVar3;
  puVar2[5] = param_5;
  puVar2[3] = 0;
  puVar2[2] = param_3;
  puVar2[4] = 0x438;
  puVar2[6] = param_6;
  if (param_4 != (char *)0x0) {
    pcVar3 = strchr(param_4,0x3a);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = _strdup(param_4);
      puVar2[3] = pcVar3;
    }
    else {
      iVar1 = atoi(pcVar3 + 1);
      puVar2[4] = iVar1;
      _Dest = malloc(((int)pcVar3 - (int)param_4) + 1);
      puVar2[3] = _Dest;
      strncpy(_Dest,param_4,(int)pcVar3 - (int)param_4);
      pcVar3[puVar2[3] - (int)param_4] = '\0';
    }
  }
  return puVar2;
}



/* VA 10003cb7 */

undefined4 FUN_10003cb7(void)

{
  int iVar1;
  WSADATA local_194;

  iVar1 = WSAStartup(0x101,&local_194);
  if (iVar1 == 0) {
    if (((char)local_194.wVersion == '\x01') && (local_194.wVersion._1_1_ == '\x01')) {
      return 0;
    }
    WSACleanup();
  }
  return 0xffffffff;
}



/* VA 10003cf6 */

void __cdecl FUN_10003cf6(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;

  pvVar2 = (void *)param_1[7];
  while (pvVar2 != (void *)0x0) {
    pvVar1 = *(void **)((int)pvVar2 + 0x2c);
    FUN_10004c67(pvVar2);
    pvVar2 = pvVar1;
  }
  WSACleanup();
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
  }
  if ((void *)param_1[3] != (void *)0x0) {
    free((void *)param_1[3]);
  }
  free(param_1);
  return;
}



/* VA 10003d45 */

int WSACleanup(void)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSACleanup();
  return iVar1;
}



/* VA 10003d4a */

void __cdecl FUN_10003d4a(int param_1,longlong *param_2)

{
  longlong lVar1;

  if (*(int *)((int)param_2 + 0x24) == 0) {
    *(undefined4 *)((int)param_2 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
    lVar1 = FUN_100086a2();
    *param_2 = lVar1;
    *(longlong **)(param_1 + 0x1c) = param_2;
  }
  return;
}



/* VA 10003d70 */

undefined4 * __cdecl
FUN_10003d70(int param_1,char *param_2,int param_3,int param_4,hostent *param_5)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined3 extraout_var;

  if (param_4 == 0) {
    puVar4 = (undefined4 *)0x0;
    for (puVar1 = *(undefined4 **)(param_1 + 0x1c); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[0xb]) {
      iVar3 = _stricmp((char *)puVar1[2],param_2);
      if ((iVar3 == 0) && (puVar1[3] == param_3)) {
        if (puVar4 == (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 0x1c) = puVar1[0xb];
        }
        else {
          puVar4[0xb] = puVar1[0xb];
        }
        bVar2 = FUN_10004cbd((u_long)puVar1);
        if (CONCAT31(extraout_var,bVar2) == 0) {
          return puVar1;
        }
        puVar4 = FUN_10003d70(param_1,param_2,param_3,0,param_5);
        return puVar4;
      }
      puVar4 = puVar1;
    }
  }
  puVar4 = FUN_10004901(param_2,param_3,*(char **)(param_1 + 0xc),
                        (u_short)*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0x14),param_4,
                        param_5);
  return puVar4;
}



/* VA 10003e00 */

int * __cdecl FUN_10003e00(int param_1,char *param_2,int param_3,char *param_4)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  char *_Dest;
  char local_104 [256];

  cVar1 = *param_4;
  while (cVar1 == '/') {
    param_4 = param_4 + 1;
    cVar1 = *param_4;
  }
  if (param_3 == 0x50) {
    sprintf(local_104,s_http____s__s_10017098,param_2);
  }
  else {
    sprintf(local_104,s_http____s__d__s_10017088,param_2,param_3,param_4);
  }
  piVar2 = malloc(0x34);
  *piVar2 = param_1;
  pcVar3 = _strdup(local_104);
  piVar2[1] = (int)pcVar3;
  pcVar3 = _strdup(param_2);
  piVar2[2] = (int)pcVar3;
  piVar2[3] = param_3;
  pcVar3 = _strdup(param_4);
  piVar2[4] = (int)pcVar3;
  pcVar3 = _strdup(param_2);
  piVar2[5] = (int)pcVar3;
  piVar2[10] = 0;
  piVar2[6] = param_3;
  piVar2[7] = 0;
  puVar4 = FUN_1000c87d((undefined *)0x0,(undefined1 *)0x0);
  piVar2[0xb] = (int)puVar4;
  puVar4 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
  piVar2[0xc] = (int)puVar4;
  piVar2[8] = 0;
  pcVar3 = *(char **)(param_1 + 4);
  if (pcVar3 != (char *)0x0) {
    piVar2[7] = 1;
    free((void *)piVar2[5]);
    pcVar5 = strchr(pcVar3,0x3a);
    if (pcVar5 == (char *)0x0) {
      pcVar3 = _strdup(pcVar3);
      piVar2[5] = (int)pcVar3;
    }
    else {
      iVar6 = atoi(pcVar5 + 1);
      piVar2[6] = iVar6;
      _Dest = malloc(((int)pcVar5 - (int)pcVar3) + 1);
      piVar2[5] = (int)_Dest;
      strncpy(_Dest,pcVar3,(int)pcVar5 - (int)pcVar3);
      pcVar5[piVar2[5] - (int)pcVar3] = '\0';
    }
  }
  return piVar2;
}



/* VA 10003f49 */

int * __cdecl FUN_10003f49(int *param_1,char **param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;

  piVar2 = param_1;
  if ((void *)param_1[8] != (void *)0x0) {
    FUN_10004c67((void *)param_1[8]);
  }
  puVar3 = FUN_10003d70(*piVar2,(char *)piVar2[5],piVar2[6],(int)param_2,(hostent *)&param_1);
  piVar2[8] = (int)puVar3;
  if ((puVar3 != (undefined4 *)0x0) && (FUN_10003361(puVar3[7],param_3), param_2 != (char **)0x0)) {
    if ((piVar2[7] == 0) || (param_1 = (int *)FUN_1000477e(piVar2), param_1 == (int *)0x0)) {
      puVar1 = puVar3 + 10;
      iVar4 = FUN_1000bd6f((int)param_2,puVar1,FUN_1000c6bf,FUN_1000c67c);
      if (iVar4 == 0) {
        FUN_1000c78b((int *)puVar3[5],param_2,*puVar1);
        FUN_1000c78b((int *)puVar3[6],param_2,*puVar1);
        iVar4 = FUN_1000bdb3((int)param_2,*puVar1,(int *)puVar3[6],(char *)piVar2[2]);
        if (iVar4 == 0) {
          param_1 = (int *)0x0;
        }
        else {
          iVar4 = FUN_1000c808((int *)puVar3[6]);
          FUN_10004c67(puVar3);
          piVar2[8] = 0;
          param_1 = (int *)((-(uint)(iVar4 != 0) & 7) - 10);
        }
      }
      else {
        FUN_10004c67(puVar3);
        piVar2[8] = 0;
        param_1 = (int *)0xfffffffd;
      }
    }
    else {
      FUN_10004c67(puVar3);
      piVar2[8] = 0;
    }
  }
  return param_1;
}



/* VA 1000404b */

undefined4 __cdecl FUN_1000404b(int *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  char local_a4 [128];
  char local_24 [32];

  piVar2 = param_1;
  puVar1 = (undefined4 *)*param_1;
  piVar3 = FUN_10002a17(*(undefined4 *)(param_1[8] + 0x14));
  FUN_10002b60((int)piVar3,s_POST_1001714c);
  if (piVar2[7] == 0) {
    iVar4 = FUN_10002b60((int)piVar3,&DAT_10017148);
    if (iVar4 < 0) goto LAB_100042cc;
    iVar4 = FUN_10002b60((int)piVar3,(char *)piVar2[4]);
  }
  else {
    iVar4 = FUN_10002b60((int)piVar3,(char *)piVar2[1]);
  }
  if (((iVar4 < 0) || (iVar4 = FUN_10002b60((int)piVar3,s_HTTP_1_0_1001713c), iVar4 < 0)) ||
     ((uVar7 = FUN_100043fe((int)piVar2,s_user_agent_10017130), uVar7 == 0 &&
      (((iVar4 = FUN_10002b60((int)piVar3,s_User_Agent__10017120), iVar4 < 0 ||
        (iVar4 = FUN_10002b60((int)piVar3,(char *)*puVar1), iVar4 < 0)) ||
       (iVar4 = FUN_10002b60((int)piVar3,&DAT_1001711c), iVar4 < 0)))))) goto LAB_100042cc;
  if (param_3 == 0) {
    if (piVar2[7] == 0) {
      iVar4 = FUN_10002b60((int)piVar3,s_Connection__Keep_Alive_100170e0);
    }
    else {
      iVar4 = FUN_10002b60((int)piVar3,s_Proxy_Connection__Keep_Alive_100170fc);
    }
    if (iVar4 < 0) goto LAB_100042cc;
  }
  if (-1 < param_2) {
    iVar4 = FUN_10002b60((int)piVar3,s_Content_length__100170cc);
    if (iVar4 < 0) goto LAB_100042cc;
    sprintf(local_24,&DAT_100170c8,param_2);
    iVar4 = FUN_10002b60((int)piVar3,local_24);
    if ((iVar4 < 0) || (iVar4 = FUN_10002b60((int)piVar3,&DAT_1001711c), iVar4 < 0))
    goto LAB_100042cc;
  }
  if (((piVar2[7] != 0) && ((param_3 == 0 && ((code *)puVar1[2] != (code *)0x0)))) &&
     (iVar4 = (*(code *)puVar1[2])(puVar1[6],local_a4), iVar4 == 0)) {
    pcVar5 = (char *)FUN_10001000(local_a4);
    iVar4 = FUN_10002b60((int)piVar3,s_Proxy_Authorization__Basic_100170ac);
    if (((iVar4 < 0) || (iVar4 = FUN_10002b60((int)piVar3,pcVar5), iVar4 < 0)) ||
       (iVar4 = FUN_10002b60((int)piVar3,&DAT_1001711c), iVar4 < 0)) goto LAB_100042cc;
    free(pcVar5);
  }
  param_1 = (int *)FUN_10004433();
  while (pcVar5 = (char *)FUN_1000c9f9((int *)piVar2[0xb],(int *)&param_1), pcVar5 != (char *)0x0) {
    iVar4 = FUN_10002b60((int)piVar3,pcVar5);
    if ((iVar4 < 0) || (iVar4 = FUN_10002b60((int)piVar3,&DAT_100170a8), iVar4 < 0))
    goto LAB_100042cc;
    pcVar5 = (char *)FUN_100043fe((int)piVar2,pcVar5);
    iVar4 = FUN_10002b60((int)piVar3,pcVar5);
    if ((iVar4 < 0) || (iVar4 = FUN_10002b60((int)piVar3,&DAT_1001711c), iVar4 < 0))
    goto LAB_100042cc;
  }
  iVar4 = FUN_10002b60((int)piVar3,&DAT_1001711c);
  if ((-1 < iVar4) && (iVar4 = FUN_10002b90((int)piVar3), -1 < iVar4)) {
    FUN_10002a4e(piVar3);
    return 0;
  }
LAB_100042cc:
  puVar6 = (uint *)FUN_10002fe7((int)piVar3);
  uVar7 = FUN_1000c245(puVar6);
  if (uVar7 == 0) {
    FUN_10002a4e(piVar3);
    uVar8 = 0xfffffff7;
  }
  else {
    FUN_10002a4e(piVar3);
    uVar8 = 0xfffffff8;
  }
  return uVar8;
}



/* VA 10004301 */

void __cdecl FUN_10004301(int *param_1)

{
  char *_Str2;
  int iVar1;

  if (param_1[8] == 0) goto LAB_1000435f;
  _Str2 = (char *)FUN_100043fe((int)param_1,s_connection_10017160);
  if (_Str2 == (char *)0x0) {
LAB_10004352:
    FUN_10004c67((void *)param_1[8]);
  }
  else {
    iVar1 = _stricmp(s_Keep_Alive_10017154,_Str2);
    if (iVar1 != 0) goto LAB_10004352;
    FUN_10004d50(param_1[8]);
    FUN_10004cf9(param_1[8],0xffffffff);
    FUN_10003d4a(*param_1,(longlong *)param_1[8]);
  }
  param_1[8] = 0;
LAB_1000435f:
  free((void *)param_1[1]);
  free((void *)param_1[2]);
  free((void *)param_1[4]);
  free((void *)param_1[5]);
  if ((void *)param_1[10] != (void *)0x0) {
    free((void *)param_1[10]);
  }
  FUN_1000c8de((int *)param_1[0xb]);
  FUN_10003757((int *)param_1[0xc]);
  free(param_1);
  return;
}



/* VA 100043a1 */

void __cdecl FUN_100043a1(int param_1)

{
  if (*(void **)(param_1 + 0x20) != (void *)0x0) {
    FUN_10004c67(*(void **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}



/* VA 100043ba */

void __cdecl FUN_100043ba(int param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  char *pcVar2;

  pcVar1 = _strdup(param_2);
  FUN_1000c907(*(int **)(param_1 + 0x2c),pcVar1);
  pcVar1 = _strdup(param_3);
  pcVar2 = _strdup(param_2);
  pcVar2 = _strlwr(pcVar2);
  FUN_10003881(*(int **)(param_1 + 0x30),(uint)pcVar2,(uint)pcVar1);
  return;
}



/* VA 100043fe */

uint __cdecl FUN_100043fe(int param_1,char *param_2)

{
  char *pcVar1;
  uint uVar2;

  pcVar1 = _strdup(param_2);
  pcVar1 = _strlwr(pcVar1);
  uVar2 = FUN_1000378d(*(int **)(param_1 + 0x30),pcVar1);
  free(pcVar1);
  return uVar2;
}



/* VA 10004433 */

void FUN_10004433(void)

{
  FUN_1000c9f6();
  return;
}



/* VA 10004441 */

int __cdecl FUN_10004441(char *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  size_t sVar9;
  long lVar10;
  char local_2c [32];
  char *local_c;
  int *local_8;

  pcVar3 = param_1;
  piVar1 = *(int **)(param_1 + 0x20);
  piVar2 = (int *)piVar1[7];
  local_8 = piVar2;
  iVar4 = FUN_1000325e(piVar2,&param_1);
  if (iVar4 == 0) {
    pcVar7 = strchr(param_1,0x20);
    if ((pcVar7 != (char *)0x0) && (pcVar8 = strchr(pcVar7 + 1,0x20), pcVar8 != (char *)0x0)) {
      strncpy(local_2c,pcVar7 + 1,(size_t)(pcVar8 + (-1 - (int)pcVar7)));
      pcVar8[(int)(local_2c + (-1 - (int)pcVar7))] = '\0';
      iVar4 = atoi(local_2c);
      *(int *)(pcVar3 + 0x24) = iVar4;
      if (iVar4 != 0) {
        if (*(void **)(pcVar3 + 0x28) != (void *)0x0) {
          free(*(void **)(pcVar3 + 0x28));
        }
        pcVar7 = FUN_1000461f(pcVar8 + 1);
        *(char **)(pcVar3 + 0x28) = pcVar7;
        FUN_1000ca3d(*(int **)(pcVar3 + 0x2c));
        FUN_10003a4e(*(int **)(pcVar3 + 0x30));
        while( true ) {
          free(param_1);
          iVar4 = FUN_1000325e(local_8,&param_1);
          if (param_1 == (char *)0x0) break;
          sVar9 = strlen(param_1);
          if (sVar9 == 0) {
            if (param_1 != (char *)0x0) {
              free(param_1);
            }
            break;
          }
          if (iVar4 == -1) {
            puVar5 = (uint *)FUN_10002fe7((int)local_8);
            uVar6 = FUN_1000c245(puVar5);
            if (uVar6 != 0) {
              return -8;
            }
            if (*(int *)(pcVar3 + 0x24) == 200) {
              return -5;
            }
            *param_3 = *(int *)(pcVar3 + 0x24);
            goto LAB_10004609;
          }
          if ((param_2 == 0) && (pcVar7 = strchr(param_1,0x3a), pcVar7 != (char *)0x0)) {
            *pcVar7 = '\0';
            local_c = FUN_1000461f(param_1);
            pcVar7 = FUN_1000461f(pcVar7 + 1);
            FUN_100043ba((int)pcVar3,local_c,pcVar7);
            free(local_c);
            free(pcVar7);
          }
        }
        lVar10 = FUN_1000469d((int)pcVar3);
        if (-1 < lVar10) {
          FUN_10004cf9(*(int *)(pcVar3 + 0x20),lVar10);
        }
        *param_3 = *(int *)(pcVar3 + 0x24);
        goto LAB_10004609;
      }
    }
    free(param_1);
    iVar4 = -6;
  }
  else {
    if (*piVar1 == 0 && piVar1[1] == 0) {
      puVar5 = (uint *)FUN_10002fe7((int)piVar2);
      uVar6 = FUN_1000c245(puVar5);
      return (-(uint)(uVar6 != 0) & 0xfffffffd) - 5;
    }
    FUN_100043a1((int)pcVar3);
    *param_3 = -1;
LAB_10004609:
    iVar4 = 0;
  }
  return iVar4;
}



/* VA 1000461f */

char * __cdecl FUN_1000461f(char *param_1)

{
  size_t sVar1;
  char *_Dest;
  char *pcVar2;

  sVar1 = strlen(param_1);
  _Dest = malloc(sVar1 + 1);
  sVar1 = strlen(param_1);
  pcVar2 = param_1 + (sVar1 - 1);
  for (; *param_1 < '!'; param_1 = param_1 + 1) {
    if (pcVar2 <= param_1) goto LAB_1000465b;
  }
  for (; (param_1 < pcVar2 && (*pcVar2 < '!')); pcVar2 = pcVar2 + -1) {
  }
LAB_1000465b:
  strncpy(_Dest,param_1,(size_t)(pcVar2 + (1 - (int)param_1)));
  (_Dest + (int)pcVar2)[1 - (int)param_1] = '\0';
  pcVar2 = _strdup(_Dest);
  free(_Dest);
  return pcVar2;
}



/* VA 1000468d */

undefined4 __cdecl FUN_1000468d(int param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}



/* VA 10004695 */

undefined4 __cdecl FUN_10004695(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



/* VA 1000469d */

long __cdecl FUN_1000469d(int param_1)

{
  char *_Str;
  size_t sVar1;
  int *piVar2;
  uint uVar3;
  long lVar4;
  int iVar5;

  _Str = (char *)FUN_100043fe(param_1,s_content_length_1001716c);
  if ((_Str == (char *)0x0) || (sVar1 = strlen(_Str), sVar1 == 0)) {
    return -1;
  }
  sVar1 = strlen(_Str);
  iVar5 = 0;
  if (0 < (int)sVar1) {
    do {
      piVar2 = (int *)__p___mb_cur_max();
      if (*piVar2 < 2) {
        piVar2 = (int *)__p__pctype();
        uVar3 = *(byte *)(*piVar2 + _Str[iVar5] * 2) & 4;
      }
      else {
        uVar3 = _isctype((int)_Str[iVar5],4);
      }
      if (uVar3 == 0) {
        return -1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)sVar1);
  }
  lVar4 = atol(_Str);
  return lVar4;
}



/* VA 10004718 */

void __cdecl FUN_10004718(int param_1)

{
  char local_84 [128];

  sprintf(local_84,s__s__d_1001717c,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18))
  ;
  _strdup(local_84);
  return;
}



/* VA 10004749 */

void __cdecl FUN_10004749(int param_1)

{
  FUN_10004cad(*(int *)(param_1 + 0x20));
  return;
}



/* VA 10004757 */

void __cdecl FUN_10004757(int param_1)

{
  FUN_10004cb5(*(int *)(param_1 + 0x20));
  return;
}



/* VA 10004765 */

void __cdecl FUN_10004765(int param_1)

{
  FUN_1000ca3d(*(int **)(param_1 + 0x2c));
  FUN_10003a4e(*(int **)(param_1 + 0x30));
  return;
}



/* VA 1000477e */

int __cdecl FUN_1000477e(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  size_t sVar4;
  char local_190 [128];
  char local_110 [256];
  int local_10;
  int local_c;
  void *local_8;

  piVar1 = (int *)*param_1;
  piVar2 = (int *)FUN_10004749((int)param_1);
  local_8 = (void *)0x0;
  local_10 = 0;
  if (((code *)piVar1[2] != (code *)0x0) &&
     (iVar3 = (*(code *)piVar1[2])(piVar1[6],local_190), iVar3 == 0)) {
    local_8 = (void *)FUN_10001000(local_190);
    local_10 = 1;
  }
  sprintf(local_110,s_CONNECT__s__d_HTTP_1_0_100171b8,param_1[2],param_1[3]);
  sVar4 = strlen(local_110);
  iVar3 = FUN_1000c0c5(piVar2,local_110,sVar4);
  if (-1 < iVar3) {
    if (local_10 != 0) {
      sprintf(local_110,s_Proxy_Authorization__Basic__s_10017198,local_8);
      free(local_8);
      sVar4 = strlen(local_110);
      iVar3 = FUN_1000c0c5(piVar2,local_110,sVar4);
      if (iVar3 < 0) {
        return -1;
      }
    }
    if (*piVar1 != 0) {
      sprintf(local_110,s_User_Agent___s_10017184,*piVar1);
      sVar4 = strlen(local_110);
      iVar3 = FUN_1000c0c5(piVar2,local_110,sVar4);
      if (iVar3 < 0) {
        return -1;
      }
    }
    iVar3 = FUN_1000c0c5(piVar2,&DAT_1001711c,2);
    if ((-1 < iVar3) && (iVar3 = FUN_1000c13e(piVar2), -1 < iVar3)) {
      iVar3 = FUN_10004441((char *)param_1,1,&local_c);
      if (iVar3 != 0) {
        return -3;
      }
      if (local_c == 200) {
        return 0;
      }
      return ((local_c == 0x197) - 1 & 0xfffffe66) + 0x197;
    }
  }
  return -1;
}



/* VA 10004901 */

undefined4 * __cdecl
FUN_10004901(char *param_1,undefined4 param_2,char *param_3,u_short param_4,int param_5,
            undefined4 param_6,hostent *param_7)

{
  undefined4 *_Memory;
  char *pcVar1;
  SOCKET SVar2;
  undefined4 uVar3;
  undefined4 *puVar4;

  _Memory = malloc(0x30);
  *_Memory = 0;
  _Memory[1] = 0;
  pcVar1 = _strdup(param_1);
  _Memory[8] = 0xffffffff;
  _Memory[2] = pcVar1;
  _Memory[3] = param_2;
  _Memory[0xb] = 0;
  if (param_3 == (char *)0x0) {
    SVar2 = FUN_100049a8(param_1,(u_short)param_2,param_7);
  }
  else {
    SVar2 = FUN_10004aaa(param_1,param_2,param_3,param_4,param_5,param_7);
  }
  _Memory[4] = SVar2;
  if (SVar2 == 0xffffffff) {
    free(_Memory);
    _Memory = (undefined4 *)0x0;
  }
  else {
    uVar3 = FUN_1000bfcb(SVar2,param_5);
    _Memory[5] = uVar3;
    uVar3 = FUN_1000bfcb(_Memory[4],param_5);
    _Memory[6] = uVar3;
    puVar4 = FUN_10002d50(uVar3);
    _Memory[7] = puVar4;
    _Memory[9] = param_6;
    _Memory[10] = 0;
  }
  return _Memory;
}



/* VA 100049a8 */

/* WARNING: Type propagation algorithm not settling */

SOCKET __cdecl FUN_100049a8(char *param_1,u_short param_2,hostent *param_3)

{
  SOCKET s;
  hostent *phVar1;
  int iVar2;
  size_t _Size;
  ulong *_Src;
  sockaddr local_18;
  ulong local_8;

  s = socket(2,1,0);
  if (s == 0xffffffff) {
    param_3->h_name = (char *)0xfffffffd;
    return 0xffffffff;
  }
  local_8 = inet_addr(param_1);
  phVar1 = param_3;
  if ((local_8 == 0xffffffff) && (phVar1 = gethostbyname(param_1), phVar1 == (hostent *)0x0)) {
    iVar2 = WSAGetLastError();
    if (iVar2 == 0x2714) {
LAB_10004a8a:
      param_3->h_name = (char *)0xfffffff8;
      goto LAB_10004a93;
    }
    if ((11000 < iVar2) && (iVar2 < 0x2afd)) {
      param_3->h_name = (char *)0xfffffffe;
      goto LAB_10004a93;
    }
  }
  else {
    local_18.sa_family = 2;
    local_18.sa_data._0_2_ = htons(param_2);
    if (local_8 == 0xffffffff) {
      _Size = (size_t)phVar1->h_length;
      _Src = (ulong *)*phVar1->h_addr_list;
    }
    else {
      _Src = &local_8;
      _Size = 4;
    }
    memcpy(local_18.sa_data + 2,_Src,_Size);
    iVar2 = connect(s,&local_18,0x10);
    if (iVar2 != -1) {
      param_3->h_name = (char *)0x0;
      return s;
    }
    iVar2 = WSAGetLastError();
    if (iVar2 == 0x2714) goto LAB_10004a8a;
    if (iVar2 == 0x274c) {
      param_3->h_name = (char *)0xfffffffc;
      goto LAB_10004a93;
    }
  }
  param_3->h_name = (char *)0xfffffffd;
LAB_10004a93:
  closesocket(s);
  return 0xffffffff;
}



/* VA 10004aaa */

SOCKET __cdecl
FUN_10004aaa(char *param_1,undefined4 param_2,char *param_3,u_short param_4,int param_5,
            hostent *param_6)

{
  hostent *phVar1;
  int iVar2;
  void *_Memory;
  SOCKET s;
  int iVar3;
  char local_14;
  char local_13;
  int local_c;
  ulong local_8;

  local_8 = inet_addr(param_1);
  if (local_8 == 0xffffffff) {
    phVar1 = gethostbyname(param_1);
    if (phVar1 == (hostent *)0x0) {
      iVar2 = WSAGetLastError();
      if (iVar2 == 0x2714) {
        param_6->h_name = (char *)0xfffffff8;
        return 0xffffffff;
      }
      if ((11000 < iVar2) && (iVar2 < 0x2afd)) {
        param_6->h_name = (char *)0xfffffffe;
        return 0xffffffff;
      }
      goto LAB_10004b31;
    }
    memcpy(&local_8,*phVar1->h_addr_list,(int)phVar1->h_length);
  }
  _Memory = FUN_10004bd1(1,local_8,param_2,&local_c);
  if (_Memory == (void *)0x0) {
LAB_10004b31:
    param_6->h_name = (char *)0xfffffffd;
    return 0xffffffff;
  }
  s = FUN_100049a8(param_3,param_4,param_6);
  if (s != 0xffffffff) {
    iVar2 = 0;
    if (0 < local_c) {
      do {
        iVar3 = send(s,(char *)(iVar2 + (int)_Memory),local_c - iVar2,0);
        if (iVar3 == -1) goto LAB_10004bb0;
        iVar2 = iVar2 + iVar3;
      } while (iVar2 < local_c);
    }
    iVar2 = FUN_1000c81e(s,param_5);
    if ((((iVar2 != -1) && (iVar2 != 0)) && (iVar2 = recv(s,&local_14,8,0), iVar2 != -1)) &&
       ((iVar2 == 8 && (local_13 == 'Z')))) goto LAB_10004bc2;
LAB_10004bb0:
    param_6->h_name = (char *)0xfffffffd;
  }
  closesocket(s);
  s = 0xffffffff;
LAB_10004bc2:
  free(_Memory);
  return s;
}



/* VA 10004bd1 */

void * __cdecl
FUN_10004bd1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  CHAR local_48 [64];
  DWORD local_8;

  local_48[0] = '\0';
  local_8 = 0x40;
  GetUserNameA(local_48,&local_8);
  piVar1 = FUN_100029c1();
  pvVar2 = (void *)0x0;
  if (piVar1 != (int *)0x0) {
    FUN_10002d3c((int)piVar1);
    FUN_10002d3c((int)piVar1);
    FUN_10002c21((int)piVar1,param_3);
    FUN_10002ae4((int)piVar1,(int)&param_2,4);
    FUN_10002ae4((int)piVar1,(int)local_48,local_8);
    FUN_10002d3c((int)piVar1);
    pvVar2 = FUN_10002bcc((int)piVar1);
    uVar3 = FUN_10002bba((int)piVar1);
    *param_4 = uVar3;
    FUN_10002a4e(piVar1);
  }
  return pvVar2;
}



/* VA 10004c67 */

void __cdecl FUN_10004c67(void *param_1)

{
  FUN_1000c00c(*(int **)((int)param_1 + 0x14));
  FUN_10002fef(*(undefined4 **)((int)param_1 + 0x1c));
  FUN_1000c00c(*(int **)((int)param_1 + 0x18));
  if (*(int *)((int)param_1 + 0x28) != 0) {
    FUN_1000bd97(*(int *)((int)param_1 + 0x24));
  }
  free(*(void **)((int)param_1 + 8));
  free(param_1);
  return;
}



/* VA 10004cad */

undefined4 __cdecl FUN_10004cad(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



/* VA 10004cb5 */

undefined4 __cdecl FUN_10004cb5(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}



/* VA 10004cbd */

bool __cdecl FUN_10004cbd(u_long param_1)

{
  int iVar1;

  iVar1 = ioctlsocket(*(SOCKET *)(param_1 + 0x10),0x4004667f,&param_1);
  return iVar1 != 0;
}



/* VA 10004cdc */

u_long __cdecl FUN_10004cdc(int param_1)

{
  u_long uVar1;
  u_long uVar2;

  uVar2 = FUN_1000c16f(*(int **)(param_1 + 0x1c));
  uVar1 = *(u_long *)(param_1 + 0x20);
  if ((-1 < (int)uVar1) && ((int)uVar1 < (int)uVar2)) {
    uVar2 = uVar1;
  }
  return uVar2;
}



/* VA 10004cf9 */

void __cdecl FUN_10004cf9(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}



/* VA 10004d05 */

size_t __cdecl FUN_10004d05(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;

  sVar1 = *(size_t *)(param_1 + 0x20);
  if ((int)sVar1 < 0) {
    sVar1 = FUN_10002d96(*(int **)(param_1 + 0x1c),param_2,param_3);
  }
  else if (sVar1 == 0) {
    sVar1 = 0xffffffff;
  }
  else {
    if ((int)sVar1 < (int)param_3) {
      param_3 = sVar1;
    }
    sVar1 = FUN_10002d96(*(int **)(param_1 + 0x1c),param_2,param_3);
    if (0 < (int)sVar1) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - sVar1;
    }
  }
  return sVar1;
}



/* VA 10004d50 */

undefined4 __cdecl FUN_10004d50(int param_1)

{
  u_long uVar1;
  void *_Memory;
  u_long uVar2;
  size_t sVar3;
  size_t _Size;

  uVar1 = FUN_10004cdc(param_1);
  if (0 < (int)uVar1) {
    _Size = 0x1000;
    if ((int)uVar1 < 0x1001) {
      _Size = uVar1;
    }
    _Memory = malloc(_Size);
    do {
      uVar2 = uVar1;
      if ((int)_Size <= (int)uVar1) {
        uVar2 = _Size;
      }
      sVar3 = FUN_10004d05(param_1,_Memory,uVar2);
    } while ((0 < (int)sVar3) && (uVar1 = uVar1 - sVar3, 0 < (int)uVar1));
    free(_Memory);
  }
  return 0;
}



/* VA 10004da8 */

undefined4 __cdecl
FUN_10004da8(char *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  char local_114 [256];
  char *local_14;
  char *local_10;
  char *local_c;
  char *local_8;

  sVar4 = strlen(param_1);
  cVar1 = *param_1;
  pcVar6 = param_1 + (sVar4 - 1);
  local_8 = param_1;
  while ((cVar1 < '!' && (local_8 <= pcVar6))) {
    local_8 = local_8 + 1;
    cVar1 = *local_8;
  }
  pcVar5 = strchr(local_8,0x3a);
  if ((((pcVar5 == (char *)0x0) || (pcVar6 < pcVar5 + 3)) || (pcVar5[1] != '/')) ||
     (pcVar5[2] != '/')) {
    uVar7 = 0xffffffff;
  }
  else {
    local_10 = pcVar5 + 3;
    local_c = strchr(local_10,0x2f);
    if (local_c == (char *)0x0) {
      uVar7 = 0xfffffffe;
    }
    else {
      local_14 = local_c + -1;
      for (; (local_c <= pcVar6 && (*pcVar6 < '!')); pcVar6 = pcVar6 + -1) {
      }
      if (param_2 != (undefined4 *)0x0) {
        iVar2 = -(int)local_8;
        strncpy(local_114,local_8,(size_t)(pcVar5 + iVar2));
        pcVar5[(int)(local_114 + iVar2)] = '\0';
        pcVar5 = _strdup(local_114);
        *param_2 = pcVar5;
      }
      pcVar3 = local_10;
      pcVar5 = local_14;
      if (param_3 != (undefined4 *)0x0) {
        strncpy(local_114,local_10,(size_t)(local_14 + (1 - (int)local_10)));
        pcVar5[(int)(local_114 + (1 - (int)pcVar3))] = '\0';
        pcVar5 = _strdup(local_114);
        *param_3 = pcVar5;
      }
      pcVar5 = local_c;
      if (param_4 != (undefined4 *)0x0) {
        strncpy(local_114,local_c,(size_t)(pcVar6 + (1 - (int)local_c)));
        pcVar6[(int)(local_114 + (1 - (int)pcVar5))] = '\0';
        pcVar6 = _strdup(local_114);
        *param_4 = pcVar6;
      }
      uVar7 = 0;
    }
  }
  return uVar7;
}



/* VA 10004efe */

undefined4 * __cdecl FUN_10004efe(size_t param_1)

{
  undefined4 *puVar1;
  void *pvVar2;

  puVar1 = malloc(0x30);
  pvVar2 = (void *)0x0;
  puVar1[8] = 0xffffffff;
  puVar1[9] = 0xffffffff;
  puVar1[10] = 0xffffffff;
  puVar1[4] = 0;
  puVar1[6] = 0;
  *puVar1 = 0;
  puVar1[3] = 0;
  *(short *)((int)puVar1 + 6) = (short)param_1;
  puVar1[5] = 0;
  puVar1[7] = 0;
  *(undefined2 *)(puVar1 + 1) = 0;
  *(undefined2 *)(puVar1 + 0xb) = 7;
  if (0 < (int)param_1) {
    pvVar2 = calloc(param_1,4);
  }
  puVar1[2] = pvVar2;
  return puVar1;
}



/* VA 10004f51 */

undefined4 * __cdecl FUN_10004f51(char *param_1,size_t param_2)

{
  undefined4 *puVar1;
  char *pcVar2;

  puVar1 = FUN_10004efe(param_2);
  if (param_1 == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = _strdup(param_1);
  }
  puVar1[4] = 0;
  puVar1[6] = 0;
  *puVar1 = pcVar2;
  puVar1[5] = 0;
  puVar1[7] = 0;
  return puVar1;
}



/* VA 10004f89 */

undefined4 * __cdecl
FUN_10004f89(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined2 param_5,
            undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined4 *puVar1;
  char *_Memory;

  puVar1 = FUN_10004efe(0);
  if (param_8 == 0) {
    _Memory = (char *)FUN_10001344(param_1,param_2,param_3,param_4);
    param_8 = FUN_10003b1f(_Memory);
    free(_Memory);
  }
  *(undefined2 *)(puVar1 + 1) = 0xffff;
  *(undefined2 *)(puVar1 + 0xb) = param_5;
  puVar1[8] = param_6;
  puVar1[9] = param_7;
  puVar1[4] = param_1;
  puVar1[2] = 0;
  puVar1[5] = param_2;
  puVar1[10] = param_8;
  puVar1[6] = param_3;
  puVar1[7] = param_4;
  return puVar1;
}



/* VA 10005006 */

undefined4 * __cdecl FUN_10005006(undefined4 *param_1,size_t param_2)

{
  int iVar1;
  size_t sVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;

  sVar2 = (int)*(short *)(param_1 + 1);
  if ((int)*(short *)(param_1 + 1) <= (int)param_2) {
    sVar2 = param_2;
  }
  puVar3 = FUN_10004efe(sVar2);
  *(undefined2 *)(puVar3 + 0xb) = *(undefined2 *)(param_1 + 0xb);
  if ((char *)*param_1 == (char *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = _strdup((char *)*param_1);
  }
  *puVar3 = pcVar4;
  puVar3[8] = param_1[8];
  puVar3[9] = param_1[9];
  puVar3[4] = param_1[4];
  puVar3[5] = param_1[5];
  puVar3[6] = param_1[6];
  puVar3[7] = param_1[7];
  *(undefined2 *)(puVar3 + 1) = *(undefined2 *)(param_1 + 1);
  if ((0 < *(short *)(param_1 + 1)) && (iVar6 = 0, 0 < *(short *)(param_1 + 1))) {
    do {
      puVar5 = *(undefined4 **)(param_1[2] + iVar6 * 4);
      puVar5 = FUN_10005006(puVar5,(int)*(short *)(puVar5 + 1));
      *(undefined4 **)(puVar3[2] + iVar6 * 4) = puVar5;
      iVar1 = iVar6 * 4;
      iVar6 = iVar6 + 1;
      *(undefined4 **)(*(int *)(puVar3[2] + iVar1) + 0xc) = puVar3;
    } while (iVar6 < *(short *)(param_1 + 1));
  }
  return puVar3;
}



/* VA 100050a3 */

void __cdecl FUN_100050a3(undefined4 *param_1)

{
  int iVar1;

  iVar1 = 0;
  if (0 < *(short *)(param_1 + 1)) {
    do {
      FUN_100050a3(*(undefined4 **)(param_1[2] + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(short *)(param_1 + 1));
  }
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  free(param_1);
  return;
}



/* VA 100050e8 */

bool __cdecl FUN_100050e8(int param_1)

{
  return -1 < *(short *)(param_1 + 4);
}



/* VA 100050f6 */

uint __cdecl FUN_100050f6(int param_1)

{
  return (*(byte *)(param_1 + 0x2c) & 0x20) >> 5;
}



/* VA 10005104 */

undefined2 __cdecl FUN_10005104(int param_1)

{
  return *(undefined2 *)(param_1 + 0x2c);
}



/* VA 1000510d */

char __cdecl FUN_1000510d(int param_1)

{
  return (-(*(int *)(param_1 + 8) != 0) & 4U) + 3;
}



/* VA 1000511f */

void __cdecl FUN_1000511f(int param_1)

{
  longlong *plVar1;
  ushort uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined3 extraout_var;
  uint uVar11;
  longlong lVar12;
  int local_8;

  iVar6 = param_1;
  plVar1 = (longlong *)(param_1 + 0x10);
  lVar4 = 0;
  lVar5 = 0;
  iVar9 = FUN_100011bc(*(int *)plVar1,*(int *)(param_1 + 0x14),*(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x1c));
  if (iVar9 == 0) {
    iVar9 = (int)*(short *)(param_1 + 4);
    if (iVar9 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 0xdeadbeef;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(int *)plVar1 = -0x21524111;
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    else {
      local_8 = 0;
      param_1 = 0;
      lVar12 = 0;
      lVar7 = 0;
      if (0 < iVar9) {
        do {
          lVar5 = lVar7;
          lVar4 = lVar12;
          puVar3 = *(undefined4 **)(*(int *)(iVar6 + 8) + local_8 * 4);
          FUN_1000511f((int)puVar3);
          uVar2 = *(ushort *)(puVar3 + 0xb);
          if ((uVar2 & 0x20) == 0) {
            iVar10 = FUN_10003b1f((char *)*puVar3);
            uVar11 = iVar10 * *(int *)(&DAT_10016028 + (param_1 % DAT_10016020) * 4);
            if (DAT_10016020 < param_1) {
              uVar11 = uVar11 * *(int *)(&DAT_10016028 + (param_1 / DAT_10016020) * 4);
            }
            cVar8 = FUN_1000510d((int)puVar3);
            iVar10 = (int)(short)((ushort)CONCAT31(extraout_var,cVar8) ^ uVar2);
            if (iVar10 != 0) {
              uVar11 = uVar11 ^ *(int *)(&DAT_10016028 + ((param_1 + 1) % DAT_10016020) * 4) *
                                iVar10;
            }
            lVar12 = __allmul(puVar3[4],puVar3[5],uVar11,(int)uVar11 >> 0x1f);
            lVar4 = lVar12 + lVar4;
            lVar12 = __allmul(puVar3[6],puVar3[7],uVar11,(int)uVar11 >> 0x1f);
            lVar5 = lVar12 + lVar5;
            param_1 = param_1 + 1;
          }
          local_8 = local_8 + 1;
          lVar12 = lVar4;
          lVar7 = lVar5;
        } while (local_8 < iVar9);
      }
      *plVar1 = lVar4;
      *(longlong *)(iVar6 + 0x18) = lVar5;
    }
  }
  return;
}



/* VA 10005266 */

void __cdecl FUN_10005266(undefined4 *param_1,char *param_2)

{
  FUN_10005279(param_1,param_2,0);
  return;
}



/* VA 10005279 */

undefined4 * __cdecl FUN_10005279(undefined4 *param_1,char *param_2,int param_3)

{
  undefined4 *puVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_c;
  char *local_8;

LAB_10005282:
  sVar2 = strlen(param_2);
  iVar6 = 0;
  do {
    while( true ) {
      if ((int)sVar2 <= iVar6) {
        return param_1;
      }
      iVar3 = FUN_100083b4((int)param_2,'/',iVar6);
      if (iVar3 != iVar6) break;
      iVar6 = iVar6 + 1;
    }
    if (iVar3 < 0) {
      local_8 = param_2 + iVar6;
    }
    else {
      local_8 = FUN_100053c2((int)param_2,iVar6,iVar3);
    }
    local_c = 0;
    iVar6 = (int)*(short *)(param_1 + 1);
    if (0 < *(short *)(param_1 + 1)) {
      do {
        iVar7 = (local_c + iVar6) / 2;
        puVar1 = *(undefined4 **)(param_1[2] + iVar7 * 4);
        iVar4 = strcmp((char *)*puVar1,local_8);
        iVar5 = _stricmp((char *)*puVar1,local_8);
        if (iVar4 == 0) {
LAB_10005381:
          if (iVar3 < 0) {
            return puVar1;
          }
          free(local_8);
          param_2 = param_2 + iVar3 + 1;
          param_1 = puVar1;
          goto LAB_10005282;
        }
        if (param_3 == 0) {
LAB_10005327:
          if (iVar4 < 0) {
            local_c = iVar7 + 1;
            iVar7 = iVar6;
          }
        }
        else {
          if (iVar5 == 0) goto LAB_10005381;
          if (param_3 == 0) goto LAB_10005327;
          local_c = local_c + 1;
          iVar7 = iVar6;
        }
        iVar6 = iVar7;
      } while (local_c < iVar7);
    }
    iVar6 = strcmp(local_8,&DAT_1001706c);
    if ((iVar6 != 0) &&
       ((iVar6 = strcmp(local_8,&DAT_10017068), iVar6 != 0 ||
        (param_1 = (undefined4 *)param_1[3], param_1 == (undefined4 *)0x0)))) {
      if (-1 < iVar3) {
        free(local_8);
      }
      return (undefined4 *)0x0;
    }
    iVar6 = iVar3 + 1;
    free(local_8);
  } while( true );
}



/* VA 100053c2 */

char * __cdecl FUN_100053c2(int param_1,int param_2,int param_3)

{
  char *_Dest;
  size_t _Count;

  _Count = param_3 - param_2;
  _Dest = malloc(_Count + 1);
  strncpy(_Dest,(char *)(param_2 + param_1),_Count);
  _Dest[_Count] = '\0';
  return _Dest;
}



/* VA 100053f8 */

void __cdecl FUN_100053f8(undefined4 *param_1,char *param_2)

{
  FUN_10005279(param_1,param_2,1);
  return;
}



/* VA 1000540b */

undefined4 * __cdecl FUN_1000540b(undefined4 *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  void *pvVar8;
  char *pcVar9;
  undefined3 extraout_var;
  int local_14;
  int local_c;
  char *local_8;

  local_c = 0;
  local_14 = (int)*(short *)(param_1 + 1);
  cVar1 = *param_2;
  while (cVar1 == '/') {
    param_2 = param_2 + 1;
    cVar1 = *param_2;
  }
  iVar4 = FUN_100083b4((int)param_2,'/',0);
  local_8 = param_2;
  if (-1 < iVar4) {
    local_8 = FUN_100053c2((int)param_2,0,iVar4);
  }
  iVar5 = FUN_100011bc(param_1[4],param_1[5],param_1[6],param_1[7]);
  if (iVar5 != 0) {
    puVar6 = (undefined4 *)FUN_100056a5(param_1,(int)*(short *)(param_1 + 1) + 2);
    FUN_100050a3(param_1);
    param_1 = puVar6;
  }
  if (0 < local_14) {
    do {
      iVar5 = (local_c + local_14) / 2;
      puVar6 = *(undefined4 **)(param_1[2] + iVar5 * 4);
      iVar7 = strcmp((char *)*puVar6,local_8);
      if (iVar7 == 0) {
        if (iVar4 < 0) {
          if ((void *)*param_3 != (void *)0x0) {
            free((void *)*param_3);
          }
          pcVar9 = _strdup(local_8);
          *param_3 = pcVar9;
          FUN_100050a3(puVar6);
        }
        else {
          bVar3 = FUN_100050e8((int)puVar6);
          if (CONCAT31(extraout_var,bVar3) == 0) {
            puVar6 = FUN_10004f51(local_8,4);
            param_3 = FUN_1000540b(puVar6,param_2 + iVar4 + 1,param_3);
            free(local_8);
          }
          else {
            free(local_8);
            param_3 = FUN_1000540b(puVar6,param_2 + iVar4 + 1,param_3);
          }
        }
        *(undefined4 **)(param_1[2] + iVar5 * 4) = param_3;
        param_3[3] = param_1;
        return param_1;
      }
      if (iVar7 < 0) {
        local_c = iVar5 + 1;
        iVar5 = local_14;
      }
      local_14 = iVar5;
    } while (local_c < local_14);
  }
  if (*(short *)((int)param_1 + 6) == *(short *)(param_1 + 1)) {
    iVar5 = *(short *)(param_1 + 1) * 2;
    if (iVar5 < 4) {
      iVar5 = 4;
    }
    *(short *)((int)param_1 + 6) = (short)iVar5;
    pvVar8 = calloc((int)(short)iVar5,4);
    FUN_1000564a(param_1[2],0,(int)pvVar8,0,(int)*(short *)(param_1 + 1));
    if (param_1[2] != 0) {
      free((void *)param_1[2]);
    }
    param_1[2] = pvVar8;
  }
  sVar2 = *(short *)(param_1 + 1);
  *(short *)(param_1 + 1) = sVar2 + 1;
  FUN_1000564a(param_1[2],local_c,param_1[2],local_c + 1,sVar2 - local_c);
  if (iVar4 < 0) {
    if ((void *)*param_3 != (void *)0x0) {
      free((void *)*param_3);
    }
    pcVar9 = _strdup(local_8);
    *param_3 = pcVar9;
  }
  else {
    puVar6 = FUN_10004f51(local_8,4);
    param_3 = FUN_1000540b(puVar6,param_2 + iVar4 + 1,param_3);
    free(local_8);
  }
  *(undefined4 **)(param_1[2] + local_c * 4) = param_3;
  param_3[3] = param_1;
  return param_1;
}



/* VA 1000564a */

void __cdecl FUN_1000564a(int param_1,int param_2,int param_3,int param_4,size_t param_5)

{
  undefined4 uVar1;
  undefined4 *_Memory;
  undefined4 *puVar2;
  undefined4 *puVar3;
  size_t sVar4;

  _Memory = calloc(param_5,4);
  if (0 < (int)param_5) {
    puVar2 = (undefined4 *)(param_1 + param_2 * 4);
    puVar3 = _Memory;
    sVar4 = param_5;
    do {
      uVar1 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      sVar4 = sVar4 - 1;
    } while (sVar4 != 0);
    if (0 < (int)param_5) {
      puVar2 = (undefined4 *)(param_3 + param_4 * 4);
      puVar3 = _Memory;
      do {
        uVar1 = *puVar3;
        puVar3 = puVar3 + 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
        param_5 = param_5 - 1;
      } while (param_5 != 0);
    }
  }
  free(_Memory);
  return;
}



/* VA 100056a5 */

void __cdecl FUN_100056a5(undefined4 *param_1,size_t param_2)

{
  size_t sVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;

  sVar1 = (int)*(short *)(param_1 + 1);
  if ((int)*(short *)(param_1 + 1) <= (int)param_2) {
    sVar1 = param_2;
  }
  puVar2 = FUN_10004efe(sVar1);
  *(undefined2 *)(puVar2 + 0xb) = *(undefined2 *)(param_1 + 0xb);
  if ((char *)*param_1 == (char *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = _strdup((char *)*param_1);
  }
  *puVar2 = pcVar3;
  puVar2[8] = param_1[8];
  puVar2[9] = param_1[9];
  puVar2[4] = param_1[4];
  puVar2[5] = param_1[5];
  puVar2[6] = param_1[6];
  puVar2[7] = param_1[7];
  *(undefined2 *)(puVar2 + 1) = *(undefined2 *)(param_1 + 1);
  if (0 < *(short *)(param_1 + 1)) {
    iVar5 = 0;
    if (0 < *(short *)(param_1 + 1)) {
      do {
        iVar4 = iVar5 * 4;
        *(undefined4 *)(puVar2[2] + iVar4) = *(undefined4 *)(param_1[2] + iVar4);
        *(undefined4 **)(*(int *)(puVar2[2] + iVar4) + 0xc) = puVar2;
        *(undefined4 *)(param_1[2] + iVar4) = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(short *)(param_1 + 1));
    }
    *(undefined2 *)(param_1 + 1) = 0;
  }
  return;
}



/* VA 10005747 */

int __cdecl FUN_10005747(int param_1,char *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  char *local_8;

  iVar3 = param_1;
  cVar1 = *param_2;
  while (cVar1 == '/') {
    param_2 = param_2 + 1;
    cVar1 = *param_2;
  }
  iVar4 = FUN_100083b4((int)param_2,'/',0);
  local_8 = param_2;
  if (-1 < iVar4) {
    local_8 = FUN_100053c2((int)param_2,0,iVar4);
  }
  local_c = 0;
  param_1 = (int)*(short *)(param_1 + 4);
  if (0 < param_1) {
    do {
      iVar6 = (param_1 + local_c) / 2;
      puVar2 = *(undefined4 **)(*(int *)(iVar3 + 8) + iVar6 * 4);
      iVar5 = strcmp((char *)*puVar2,local_8);
      if (iVar5 == 0) {
        if (iVar4 < 0) {
          *(short *)(iVar3 + 4) = *(short *)(iVar3 + 4) + -1;
          FUN_1000564a(*(int *)(iVar3 + 8),iVar6 + 1,*(int *)(iVar3 + 8),iVar6,
                       *(short *)(iVar3 + 4) - iVar6);
          *(undefined4 *)(*(int *)(iVar3 + 8) + *(short *)(iVar3 + 4) * 4) = 0;
          FUN_100050a3(puVar2);
          return iVar3;
        }
        iVar4 = FUN_10005747((int)puVar2,param_2 + iVar4 + 1);
        *(int *)(*(int *)(iVar3 + 8) + iVar6 * 4) = iVar4;
        *(int *)(iVar4 + 0xc) = iVar3;
        goto LAB_100057da;
      }
      if (iVar5 < 0) {
        local_c = iVar6 + 1;
        iVar6 = param_1;
      }
      param_1 = iVar6;
    } while (local_c < param_1);
  }
  if (-1 < iVar4) {
LAB_100057da:
    free(local_8);
  }
  return iVar3;
}



/* VA 1000583e */

void __cdecl FUN_1000583e(int *param_1)

{
  int *piVar1;
  char *pcVar2;
  char local_204 [512];

  local_204[0] = '\0';
  piVar1 = (int *)param_1[3];
  if (piVar1 == (int *)0x0) {
    pcVar2 = (char *)*param_1;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = &DAT_1001706c;
    }
    strcpy(local_204,pcVar2);
  }
  else {
    if (piVar1[3] != 0) {
      pcVar2 = (char *)FUN_1000583e(piVar1);
      strcpy(local_204,pcVar2);
      strcat(local_204,&DAT_10017148);
      free(pcVar2);
    }
    pcVar2 = (char *)*param_1;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = &DAT_1001706c;
    }
    strcat(local_204,pcVar2);
  }
  _strdup(local_204);
  return;
}



/* VA 100058db */

void __cdecl FUN_100058db(int *param_1,char *param_2)

{
  int *piVar1;
  char *pcVar2;
  char local_204 [512];

  local_204[0] = '\0';
  piVar1 = (int *)param_1[3];
  if (piVar1 == (int *)0x0) {
    pcVar2 = &DAT_1001706c;
    if (*param_1 != 0) {
      pcVar2 = param_2;
    }
    strcpy(local_204,pcVar2);
  }
  else {
    if (piVar1[3] != 0) {
      pcVar2 = (char *)FUN_1000583e(piVar1);
      strcpy(local_204,pcVar2);
      strcat(local_204,&DAT_10017148);
      free(pcVar2);
    }
    pcVar2 = &DAT_1001706c;
    if (*param_1 != 0) {
      pcVar2 = param_2;
    }
    strcat(local_204,pcVar2);
  }
  _strdup(local_204);
  return;
}



/* VA 1000597c */

void __cdecl FUN_1000597c(int param_1,int *param_2)

{
  char *_Memory;

  _Memory = (char *)FUN_10001344(*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0x14),
                                 *(undefined4 *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  FUN_1000c292(param_2,0xcafebeef);
  FUN_1000c292(param_2,0xb);
  FUN_1000c366(param_2,_Memory);
  FUN_1000c292(param_2,0xffffffff);
  FUN_1000c2c6(param_2,0xffffffff,-1);
  free(_Memory);
  FUN_100059e9(param_1,param_2);
  return;
}



/* VA 100059e9 */

undefined4 __cdecl FUN_100059e9(int param_1,int *param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;

  bVar2 = FUN_100050e8(param_1);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    iVar3 = FUN_1000c352(param_2);
    if (((((-1 < iVar3) &&
          (iVar3 = FUN_1000c26e(param_2,CONCAT22((short)((uint)iVar3 >> 0x10),
                                                 *(undefined2 *)(param_1 + 0x2c))), -1 < iVar3)) &&
         (iVar3 = FUN_1000c2c6(param_2,*(undefined4 *)(param_1 + 0x20),*(int *)(param_1 + 0x24)),
         -1 < iVar3)) &&
        ((iVar3 = FUN_1000c292(param_2,*(undefined4 *)(param_1 + 0x28)), -1 < iVar3 &&
         (iVar3 = FUN_1000c352(param_2), -1 < iVar3)))) &&
       (iVar3 = FUN_100013f7(param_2,*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0x14),
                             *(undefined4 *)(param_1 + 0x18),*(int *)(param_1 + 0x1c)), -1 < iVar3))
    {
      return 0;
    }
  }
  else {
    iVar4 = 0;
    iVar3 = FUN_1000c352(param_2);
    if (((-1 < iVar3) &&
        (iVar3 = FUN_1000c26e(param_2,CONCAT22((short)((uint)iVar3 >> 0x10),
                                               *(undefined2 *)(param_1 + 0x2c))), -1 < iVar3)) &&
       (iVar3 = FUN_1000c26e(param_2,CONCAT22((short)((uint)iVar3 >> 0x10),
                                              *(undefined2 *)(param_1 + 4))), -1 < iVar3)) {
      if (0 < *(short *)(param_1 + 4)) {
        do {
          puVar1 = *(undefined4 **)(*(int *)(param_1 + 8) + iVar4 * 4);
          iVar3 = FUN_100059e9((int)puVar1,param_2);
          if (iVar3 < 0) {
            return 0xffffffff;
          }
          iVar3 = FUN_1000c366(param_2,(char *)*puVar1);
          if (iVar3 < 0) {
            return 0xffffffff;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(short *)(param_1 + 4));
      }
      return 0;
    }
  }
  return 0xffffffff;
}



/* VA 10005af3 */

undefined4 * __cdecl FUN_10005af3(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint local_18 [2];
  undefined4 local_10;
  void *local_c;
  int local_8;

  piVar1 = param_1;
  iVar2 = FUN_1000c3db(param_1,&local_8);
  if (((-1 < iVar2) && (local_8 == -0x35014111)) &&
     (iVar2 = FUN_1000c3db(piVar1,&param_1), -1 < iVar2)) {
    if (param_1 == (int *)0x4) {
      puVar3 = FUN_10005cb0(piVar1);
      return puVar3;
    }
    if (((param_1 == (int *)0xb) && (iVar2 = FUN_1000c577(piVar1,(int *)&local_c), -1 < iVar2)) &&
       ((iVar2 = FUN_1000c3db(piVar1,&local_10), -1 < iVar2 &&
        (iVar2 = FUN_1000c42a(piVar1,local_18), -1 < iVar2)))) {
      puVar3 = FUN_10005b87(piVar1);
      free(local_c);
      return puVar3;
    }
  }
  return (undefined4 *)0x0;
}



/* VA 10005b87 */

undefined4 * __cdecl FUN_10005b87(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint local_28;
  int iStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  uint local_18;
  undefined4 local_14;
  int local_10;
  undefined2 local_c [2];
  short local_8;
  char local_6;
  char local_5;

  iVar1 = FUN_1000c55b(param_1,&local_5);
  if (-1 < iVar1) {
    iVar1 = 0;
    if (local_5 == '\0') {
      iVar3 = FUN_1000c39e(param_1,local_c);
      if ((-1 < iVar3) && (iVar3 = FUN_1000c39e(param_1,&local_8), -1 < iVar3)) {
        puVar2 = FUN_10004f51((char *)0x0,(int)local_8);
        if (0 < local_8) {
          do {
            piVar4 = FUN_10005b87(param_1);
            iVar3 = FUN_1000c577(param_1,piVar4);
            if (iVar3 < 0) {
              return (undefined4 *)0x0;
            }
            *(int **)(puVar2[2] + iVar1 * 4) = piVar4;
            piVar4[3] = (int)puVar2;
            iVar1 = iVar1 + 1;
          } while (iVar1 < local_8);
        }
        *(short *)(puVar2 + 1) = local_8;
        return puVar2;
      }
    }
    else if ((((local_5 == '\x01') && (iVar1 = FUN_1000c39e(param_1,local_c), -1 < iVar1)) &&
             (iVar1 = FUN_1000c42a(param_1,&local_18), -1 < iVar1)) &&
            ((iVar1 = FUN_1000c3db(param_1,&local_10), -1 < iVar1 &&
             (iVar1 = FUN_1000c55b(param_1,&local_6), -1 < iVar1)))) {
      if (local_6 == '\x01') {
        iVar1 = FUN_100013c2(param_1,&local_28);
        if (-1 < iVar1) goto LAB_10005c21;
      }
      else if (local_6 != '\x02') {
LAB_10005c21:
        puVar2 = FUN_10004f89(local_28,iStack_24,uStack_20,iStack_1c,local_c[0],local_18,local_14,
                              local_10);
        return puVar2;
      }
    }
  }
  return (undefined4 *)0x0;
}



/* VA 10005cb0 */

undefined4 * __cdecl FUN_10005cb0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint local_1c;
  int iStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int local_c;
  int local_8;

  piVar1 = param_1;
  iVar2 = FUN_1000c39e(param_1,(undefined2 *)&local_8);
  if (-1 < iVar2) {
    if ((short)local_8 < 0) {
      iVar2 = FUN_100013c2(piVar1,&local_1c);
      if ((-1 < iVar2) && (iVar2 = FUN_1000c55b(piVar1,(char *)&param_1), -1 < iVar2)) {
        puVar3 = FUN_10004f89(local_1c,iStack_18,uStack_14,iStack_10,
                              (-(ushort)((char)param_1 != '\0') & 0x20) + 3,0,0,0);
        return puVar3;
      }
    }
    else {
      puVar3 = FUN_10004f51((char *)0x0,(int)(short)local_8);
      while( true ) {
        if ((short)local_8 < 1) {
          return puVar3;
        }
        local_8 = local_8 + -1;
        iVar2 = FUN_1000c577(piVar1,&local_c);
        if ((iVar2 < 0) || (piVar4 = FUN_10005cb0(piVar1), piVar4 == (int *)0x0)) break;
        *(int **)(puVar3[2] + *(short *)(puVar3 + 1) * 4) = piVar4;
        *(short *)(puVar3 + 1) = *(short *)(puVar3 + 1) + 1;
        *piVar4 = local_c;
        piVar4[3] = (int)puVar3;
      }
    }
  }
  return (undefined4 *)0x0;
}



/* VA 10005d7c */

void __cdecl FUN_10005d7c(uint param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;

  if (*(short *)(param_1 + 4) < 0) {
    puVar1 = (undefined4 *)FUN_100011b2();
    *puVar1 = *(undefined4 *)(param_1 + 0x10);
    puVar1[1] = *(undefined4 *)(param_1 + 0x14);
    puVar1[2] = *(undefined4 *)(param_1 + 0x18);
    puVar1[3] = *(undefined4 *)(param_1 + 0x1c);
    FUN_1000389a(param_2,(uint)puVar1,1,param_1,0);
  }
  else {
    iVar2 = (int)*(short *)(param_1 + 4);
    while (0 < iVar2) {
      FUN_10005d7c(*(uint *)(*(int *)(param_1 + 8) + (iVar2 + -1) * 4),param_2);
      iVar2 = iVar2 + -1;
    }
  }
  return;
}



/* VA 10005dd9 */

int * __cdecl FUN_10005dd9(uint param_1)

{
  int *piVar1;
  int *piVar2;

  piVar1 = FUN_100036f6(10,0x3f800000,0x10005e7c,FUN_10005eb6);
  piVar2 = FUN_100036f6(10,0x3f800000,0x10005e7c,FUN_10005eb6);
  FUN_10005e29(param_1,piVar1,piVar2);
  FUN_10003757(piVar1);
  return piVar2;
}



/* VA 10005e29 */

void __cdecl FUN_10005e29(uint param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;

  uVar1 = FUN_1000378d(param_2,param_1);
  piVar2 = param_2;
  if (uVar1 != 0) {
    piVar2 = param_3;
  }
  iVar3 = 0;
  FUN_1000389a(piVar2,param_1,0,param_1,0);
  if (0 < *(short *)(param_1 + 4)) {
    do {
      FUN_10005e29(*(uint *)(*(int *)(param_1 + 8) + iVar3 * 4),param_2,param_3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(short *)(param_1 + 4));
  }
  return;
}



/* VA 10005e7c */

undefined4 __cdecl FUN_10005e7c(int param_1,int param_2)

{
  undefined4 uVar1;

  if (*(short *)(param_1 + 4) != *(short *)(param_2 + 4)) {
    return 0;
  }
  uVar1 = FUN_100011d7(*(int *)(param_1 + 0x10),*(int *)(param_1 + 0x14),*(int *)(param_1 + 0x18),
                       *(int *)(param_1 + 0x1c),*(int *)(param_2 + 0x10),*(int *)(param_2 + 0x14),
                       *(int *)(param_2 + 0x18),*(int *)(param_2 + 0x1c));
  return uVar1;
}



/* VA 10005eb6 */

uint __cdecl FUN_10005eb6(int param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;

  uVar1 = __allshr(0x20,*(int *)(param_1 + 0x14));
  uVar2 = __allshr(0x20,*(int *)(param_1 + 0x1c));
  return (uint)uVar1 ^ (uint)uVar2 ^ *(uint *)(param_1 + 0x18) ^ *(uint *)(param_1 + 0x10);
}



/* VA 10005ee7 */

void __cdecl FUN_10005ee7(undefined4 *param_1,int param_2)

{
  bool bVar1;
  size_t sVar2;
  undefined3 extraout_var;
  char *pcVar3;
  undefined3 extraout_var_00;
  void *_Memory;
  int iVar4;
  char *_Format;

  if (param_1 == (undefined4 *)0x0) {
    printf(s_NULL_index_10017200);
  }
  else {
    FUN_1000511f((int)param_1);
    iVar4 = param_2;
    if (0 < param_2) {
      do {
        printf(&DAT_100171fc);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar4 = param_2;
    if ((char *)*param_1 != (char *)0x0) {
      printf((char *)*param_1);
      sVar2 = strlen((char *)*param_1);
      iVar4 = sVar2 + param_2;
    }
    bVar1 = FUN_100050e8((int)param_1);
    pcVar3 = &DAT_10017148;
    if (CONCAT31(extraout_var,bVar1) == 0) {
      pcVar3 = &DAT_100171fc;
    }
    printf(pcVar3);
    if (iVar4 + 1 < 0x1f) {
      iVar4 = 0x1f - (iVar4 + 1);
      do {
        printf(&DAT_1001706c);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    printf(&DAT_100171fc);
    _Format = &DAT_100171f8;
    pcVar3 = &DAT_100171f4;
    if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
      pcVar3 = &DAT_100171f8;
    }
    printf(pcVar3);
    pcVar3 = &DAT_100171f0;
    if ((*(byte *)(param_1 + 0xb) & 2) == 0) {
      pcVar3 = &DAT_100171f8;
    }
    printf(pcVar3);
    pcVar3 = &DAT_100171ec;
    if ((*(byte *)(param_1 + 0xb) & 4) == 0) {
      pcVar3 = &DAT_100171f8;
    }
    printf(pcVar3);
    pcVar3 = &DAT_100171e8;
    if ((*(byte *)(param_1 + 0xb) & 8) == 0) {
      pcVar3 = &DAT_100171f8;
    }
    printf(pcVar3);
    pcVar3 = &DAT_100171e4;
    if ((*(byte *)(param_1 + 0xb) & 0x10) == 0) {
      pcVar3 = &DAT_100171f8;
    }
    printf(pcVar3);
    if ((*(byte *)(param_1 + 0xb) & 0x20) != 0) {
      _Format = &DAT_100171e0;
    }
    printf(_Format);
    bVar1 = FUN_100050e8((int)param_1);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      _Memory = (void *)FUN_10001344(param_1[4],param_1[5],param_1[6],param_1[7]);
      printf(s__s__d_100171d4,_Memory,param_1[8],param_1[9]);
      free(_Memory);
    }
    else {
      printf(&DAT_100171dc);
      iVar4 = 0;
      if (0 < *(short *)(param_1 + 1)) {
        do {
          FUN_10005ee7(*(undefined4 **)(param_1[2] + iVar4 * 4),param_2 + 1);
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(short *)(param_1 + 1));
      }
    }
  }
  return;
}



/* VA 1000604b */

undefined * FUN_1000604b(void)

{
  int iVar1;
  undefined **ppuVar2;
  CHAR local_88 [128];
  int local_8;

  iVar1 = GetLocaleInfoA(0x400,0x1001,local_88,0x80);
  if (iVar1 != 0) {
    local_8 = 0;
    iVar1 = strcmp(PTR_s_arabic_10017210,&DAT_10018c80);
    if (iVar1 != 0) {
      ppuVar2 = &PTR_s_arabic_10017210;
      do {
        iVar1 = _strcmpi(local_88,*ppuVar2);
        if (iVar1 == 0) {
          return (&PTR_DAT_10017214)[local_8];
        }
        local_8 = local_8 + 2;
        ppuVar2 = ppuVar2 + 2;
        iVar1 = strcmp(*ppuVar2,&DAT_10018c80);
      } while (iVar1 != 0);
    }
  }
  return &DAT_10017e84;
}



/* VA 100060dd */

undefined * FUN_100060dd(void)

{
  int iVar1;
  undefined **ppuVar2;
  CHAR local_88 [128];
  int local_8;

  iVar1 = GetLocaleInfoA(0x400,0x1002,local_88,0x80);
  if (iVar1 != 0) {
    local_8 = 0;
    iVar1 = strcmp(PTR_s_austria_10017568,&DAT_10018c80);
    if (iVar1 != 0) {
      ppuVar2 = &PTR_s_austria_10017568;
      do {
        iVar1 = _strcmpi(local_88,*ppuVar2);
        if (iVar1 == 0) {
          return (&PTR_DAT_1001756c)[local_8];
        }
        local_8 = local_8 + 2;
        ppuVar2 = ppuVar2 + 2;
        iVar1 = strcmp(*ppuVar2,&DAT_10018c80);
      } while (iVar1 != 0);
    }
  }
  return &DAT_1001783c;
}



/* VA 1000616f */

undefined4 * __cdecl FUN_1000616f(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvVar3;

  puVar1 = malloc(0x18);
  *puVar1 = param_1;
  uVar2 = FUN_10002074();
  puVar1[1] = uVar2;
  pvVar3 = malloc(0x40);
  puVar1[5] = pvVar3;
  puVar1[3] = 0;
  puVar1[2] = 0;
  puVar1[4] = 0;
  return puVar1;
}



/* VA 100061a4 */

undefined4 * __cdecl FUN_100061a4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  void *pvVar2;

  puVar1 = malloc(0x18);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  pvVar2 = malloc(0x40);
  puVar1[2] = 0;
  puVar1[4] = 0;
  puVar1[5] = pvVar2;
  puVar1[3] = param_3;
  return puVar1;
}



/* VA 100061dc */

void __cdecl FUN_100061dc(undefined4 *param_1)

{
  FUN_1000c0c5((int *)*param_1,(char *)param_1[5],param_1[2]);
  FUN_1000c00c((int *)*param_1);
  free((void *)param_1[1]);
  free((void *)param_1[5]);
  free(param_1);
  return;
}



/* VA 10006213 */

void __cdecl FUN_10006213(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;

  puVar1 = calloc(4,4);
  piVar2 = (int *)(param_1 + 4);
  *puVar1 = *(undefined4 *)*piVar2;
  puVar1[1] = *(undefined4 *)(*piVar2 + 4);
  puVar1[2] = *(undefined4 *)(*piVar2 + 8);
  puVar1[3] = *(undefined4 *)(*piVar2 + 0xc);
  return;
}



/* VA 10006245 */

void __cdecl FUN_10006245(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  uint local_14 [4];

  puVar1 = (undefined4 *)
           FUN_10001f03(local_14,*(int *)(param_2 + 0x14),0,*(size_t *)(param_2 + 8),
                        *(uint *)(param_2 + 0xc),(int)*(uint *)(param_2 + 0xc) >> 0x1f,
                        *(uint **)(param_2 + 4));
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  param_1[3] = puVar1[3];
  return;
}



/* VA 1000627c */

int __cdecl FUN_1000627c(undefined4 *param_1,void *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  size_t _Size;
  uint uVar3;
  int local_c;
  size_t local_8;

  local_8 = 0;
  local_c = 0;
  iVar1 = param_1[2];
  param_1[3] = param_1[3] + param_3;
  if ((iVar1 < 1) || (param_3 + iVar1 < 0x40)) {
LAB_100062f1:
    uVar3 = (param_3 / 0x40) * 0x40;
    FUN_10001431((int)param_2,local_8,uVar3,(int *)param_1[1]);
    iVar1 = local_8 + uVar3;
    _Size = param_3 % 0x40;
    if ((int)local_8 < iVar1) {
      iVar2 = FUN_1000c0c5((int *)*param_1,(char *)(local_8 + (int)param_2),iVar1 - local_8);
      if (iVar2 < 0) goto LAB_10006369;
      local_c = local_c + iVar2;
    }
    if (0 < (int)_Size) {
      memcpy((void *)(param_1[5] + param_1[2]),(void *)(iVar1 + (int)param_2),_Size);
      param_1[2] = param_1[2] + _Size;
      local_c = local_c + _Size;
    }
  }
  else {
    local_8 = 0x40 - iVar1;
    memcpy((void *)(iVar1 + param_1[5]),param_2,local_8);
    param_3 = param_3 - local_8;
    FUN_10001431(param_1[5],0,0x40,(int *)param_1[1]);
    local_c = FUN_1000c0c5((int *)*param_1,(char *)param_1[5],0x40);
    if (local_c != -1) {
      local_c = local_c - param_1[2];
      param_1[2] = 0;
      goto LAB_100062f1;
    }
LAB_10006369:
    local_c = -1;
  }
  return local_c;
}



/* VA 1000636e */

uint __cdecl FUN_1000636e(undefined4 *param_1,char *param_2,uint param_3)

{
  int iVar1;
  uint _Size;
  uint uVar2;
  size_t sVar3;
  uint uVar4;
  size_t local_8;

  local_8 = 0;
  if ((int)param_1[4] < (int)param_1[2]) {
    sVar3 = param_1[2] - param_1[4];
    _Size = param_3;
    if ((int)sVar3 <= (int)param_3) {
      _Size = sVar3;
    }
    memcpy(param_2,(void *)param_1[5],_Size);
    param_1[4] = param_1[4] + _Size;
  }
  else {
    _Size = FUN_1000c048((int *)*param_1,param_2,param_3);
    if ((_Size == 0) && (uVar2 = FUN_1000c1d1((uint *)*param_1), uVar2 != 0)) {
      _Size = ((int)param_3 < 1) - 1;
    }
    else if ((int)_Size < 0) {
      _Size = 0xffffffff;
    }
    else {
      iVar1 = param_1[2];
      param_1[3] = param_1[3] + _Size;
      uVar2 = _Size;
      if ((0 < iVar1) && (iVar1 < 0x40)) {
        local_8 = 0x40U - iVar1;
        if ((int)_Size <= (int)(0x40U - iVar1)) {
          local_8 = _Size;
        }
        memcpy((void *)(iVar1 + param_1[5]),param_2,local_8);
        param_1[2] = param_1[2] + local_8;
        param_1[4] = param_1[4] + local_8;
        uVar2 = _Size - local_8;
        if (param_1[2] != 0x40) {
          return _Size;
        }
        FUN_10001431(param_1[5],0,0x40,(int *)param_1[1]);
        param_1[4] = 0;
        param_1[2] = 0;
      }
      uVar4 = ((int)uVar2 / 0x40) * 0x40;
      FUN_10001431((int)param_2,local_8,uVar4,(int *)param_1[1]);
      sVar3 = (int)uVar2 % 0x40;
      memcpy((void *)(param_1[5] + param_1[2]),param_2 + local_8 + uVar4,sVar3);
      param_1[4] = param_1[4] + sVar3;
      param_1[2] = param_1[2] + sVar3;
    }
  }
  return _Size;
}



/* VA 10006488 */

undefined4 __cdecl FUN_10006488(int *param_1,int *param_2)

{
  char cVar1;
  char *_Str;
  bool bVar2;
  int iVar3;
  int *piVar4;
  size_t sVar5;
  int *piVar6;
  undefined4 local_30 [3];
  int local_24;
  int iStack_20;
  int iStack_1c;
  size_t local_18;
  undefined4 local_14;
  char *local_10;
  size_t local_c;
  int *local_8;

  iVar3 = FUN_10003389((char *)param_2);
  if (iVar3 != -1) {
    piVar4 = (int *)FUN_1000bfed(iVar3);
    if (piVar4 != (int *)0x0) {
      sVar5 = FUN_10003785((int)param_1);
      local_8 = calloc(sVar5,4);
      piVar6 = (int *)FUN_100037f6(local_30,param_1);
      local_24 = *piVar6;
      iStack_20 = piVar6[1];
      iStack_1c = piVar6[2];
      iVar3 = FUN_1000381b(&local_24);
      piVar6 = local_8;
      param_2 = local_8;
      while (local_8 = param_2, iVar3 != 0) {
        *piVar6 = iVar3;
        piVar6 = piVar6 + 1;
        iVar3 = FUN_1000381b(&local_24);
        param_2 = local_8;
      }
      qsort(param_2,sVar5,4,(_PtFuncCompare *)&LAB_100066a9);
      if (0 < (int)sVar5) {
        do {
          local_c = sVar5;
          _Str = (char *)*param_2;
          sVar5 = strlen(_Str);
          FUN_1000c0c5(piVar4,_Str,sVar5);
          FUN_1000c352(piVar4);
          local_10 = (char *)FUN_1000378d(param_1,_Str);
          local_18 = strlen(local_10);
          iVar3 = 0;
          bVar2 = true;
          if (0 < (int)local_18) {
            do {
              cVar1 = local_10[iVar3];
              local_14 = CONCAT31(local_14._1_3_,cVar1);
              if (cVar1 == '\t') {
                FUN_1000c352(piVar4);
              }
              else if (cVar1 == '\n') {
                FUN_1000c352(piVar4);
              }
              else if (cVar1 == '\r') {
                FUN_1000c352(piVar4);
              }
              else if (cVar1 == '\\') {
                FUN_1000c352(piVar4);
              }
              else if (((cVar1 < ' ') || ('~' < cVar1)) || ((bVar2 && (cVar1 == ' ')))) {
                FUN_1000c352(piVar4);
                FUN_1000c352(piVar4);
                FUN_1000c352(piVar4);
                FUN_1000c352(piVar4);
                FUN_1000c352(piVar4);
              }
              FUN_1000c352(piVar4);
              bVar2 = false;
              iVar3 = iVar3 + 1;
            } while (iVar3 < (int)local_18);
          }
          FUN_1000c352(piVar4);
          FUN_1000c352(piVar4);
          param_2 = param_2 + 1;
          local_c = local_c - 1;
          sVar5 = local_c;
        } while (local_c != 0);
      }
      free(local_8);
      FUN_1000c00c(piVar4);
      return 0;
    }
    FUN_100033b9(iVar3);
  }
  return 0xffffffff;
}



/* VA 100066bd */

int __cdecl FUN_100066bd(int *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char local_108c [4096];
  char local_8c [108];
  undefined4 uStackY_20;

  FUN_10014d20();
  iVar2 = FUN_10003374(param_2);
  if (iVar2 != -1) {
    puVar3 = (uint *)FUN_1000bfed(iVar2);
    if (puVar3 != (uint *)0x0) {
      FUN_10003a4e(param_1);
      iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
      if ((iVar2 < 0) && (uVar4 = FUN_1000c1d1(puVar3), uVar4 != 0)) {
        return 0;
      }
LAB_10006729:
      do {
        if ((iVar2 != 1) || (uVar4 = FUN_1000c1d1(puVar3), uVar4 != 0)) {
LAB_10006a06:
          FUN_1000c00c((int *)puVar3);
          return (-1 < iVar2) - 1;
        }
        local_108c[0] = '\0';
        local_8c[0] = '\0';
        if (((char)param_2 != '\n') && ((char)param_2 != '\r')) {
          if ((char)param_2 != '#') {
            while (iVar2 == 1) {
              if (((char)param_2 != ' ') && ((char)param_2 != '\t')) goto LAB_10006794;
              iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
            }
            goto LAB_100067fe;
          }
          while( true ) {
            if (iVar2 != 1) goto LAB_10006a06;
            if (((char)param_2 == '\n') || ((char)param_2 == '\r')) break;
            iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
          }
          goto LAB_10006729;
        }
        iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
      } while( true );
    }
    FUN_100033b9(iVar2);
  }
  return -1;
LAB_10006794:
  if (iVar2 != 1) goto LAB_100067fe;
  if ((((char)param_2 == ' ') || ((char)param_2 == '\t')) || ((char)param_2 == '='))
  goto LAB_100067d2;
  uStackY_20 = 0x100067bd;
  strncat(local_8c,(char *)&param_2,1);
  iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
  goto LAB_10006794;
LAB_100067d2:
  while ((iVar2 == 1 &&
         ((((char)param_2 == ' ' || ((char)param_2 == '\t')) || ((char)param_2 == '='))))) {
    iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
  }
LAB_100067fe:
  do {
    if (((iVar2 != 1) || ((char)param_2 == '\n')) || ((char)param_2 == '\r')) goto LAB_10006985;
    if ((char)param_2 != '\\') goto LAB_1000690f;
    iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
    if (iVar2 != 1) goto LAB_10006985;
    if ((char)param_2 == '\n') goto LAB_1000696f;
    if ((char)param_2 != '\r') break;
    iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
    if (iVar2 != 1) goto LAB_10006985;
    if ((char)param_2 == '\n') goto LAB_1000696f;
    while (((char)param_2 == ' ' || ((char)param_2 == '\t'))) {
LAB_1000696f:
      iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
      if (iVar2 != 1) goto LAB_10006985;
    }
  } while( true );
  if ((char)param_2 == 'n') {
    param_2 = (char *)CONCAT31(param_2._1_3_,10);
  }
  else if ((char)param_2 == 'r') {
    param_2 = (char *)CONCAT31(param_2._1_3_,0xd);
  }
  else if ((char)param_2 == 't') {
    param_2 = (char *)CONCAT31(param_2._1_3_,9);
  }
  else if ((char)param_2 == 'u') {
    do {
      iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
      cVar1 = (char)param_2;
      if (iVar2 != 1) break;
    } while ((char)param_2 == 'u');
    do {
      iVar8 = 0;
      while( true ) {
        if ((iVar2 != 1) || (3 < iVar8)) {
          uStackY_20 = 0x10006903;
          strncat(local_108c,&stack0xfffffff7,1);
          goto LAB_100067fe;
        }
        if ((cVar1 < '0') ||
           (('9' < cVar1 && ((cVar1 < 'A' || (('F' < cVar1 && ((cVar1 < 'a' || ('f' < cVar1)))))))))
           ) break;
        iVar8 = iVar8 + 1;
        iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
        cVar1 = (char)param_2;
      }
    } while( true );
  }
LAB_1000690f:
  uStackY_20 = 0x10006921;
  strncat(local_108c,(char *)&param_2,1);
  iVar2 = FUN_1000c55b((int *)puVar3,(char *)&param_2);
  goto LAB_100067fe;
LAB_10006985:
  sVar5 = strlen(local_108c);
  if (sVar5 != 0) {
    pcVar6 = _strdup(local_108c);
    pcVar7 = _strdup(local_8c);
    uStackY_20 = 0x100069be;
    FUN_10006a1c(param_1,(uint)pcVar7,(uint)pcVar6);
  }
  goto LAB_10006729;
}



/* VA 10006a1c */

void __cdecl FUN_10006a1c(int *param_1,uint param_2,uint param_3)

{
  FUN_10003881(param_1,param_2,param_3);
  return;
}



/* VA 10006a31 */

uint __cdecl FUN_10006a31(int *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;

  uVar1 = FUN_1000378d(param_1,param_2);
  if (uVar1 == 0) {
    uVar1 = param_3;
  }
  return uVar1;
}



/* VA 10006a49 */

undefined8 __cdecl FUN_10006a49(int *param_1,undefined4 param_2,undefined8 param_3)

{
  char *_Src;
  undefined4 local_c;
  undefined4 local_8;

  _Src = (char *)FUN_1000378d(param_1,param_2);
  if (_Src == (char *)0x0) {
    return param_3;
  }
  sscanf(_Src,s_0123456789ABCDEF_I64d_10017f40 + 0x10,&local_c);
  return CONCAT44(local_8,local_c);
}



/* VA 10006a82 */

void __cdecl FUN_10006a82(int *param_1,undefined4 param_2)

{
  FUN_1000399d(param_1,param_2);
  return;
}



/* VA 10006a92 */

undefined4 __cdecl FUN_10006a92(byte *param_1)

{
  short *psVar1;
  undefined4 uVar2;

  psVar1 = FUN_1000a67b(0xd);
  if (psVar1 == (short *)0x0) {
    sprintf(&stack0xffffff7c,&DAT_100170c8,0xd);
    FUN_1000f4e8((int)param_1,0x3ec,&stack0xffffff7c);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_10006af5(psVar1,param_1,(int *)0x1);
    FUN_1000af21(psVar1);
  }
  return uVar2;
}



/* VA 10006af5 */

undefined4 FUN_10006af5(short *param_1,byte *param_2,int *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  void *_Memory;
  uint *puVar6;
  int iVar7;
  char *pcVar8;
  size_t sVar9;
  undefined4 *puVar10;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  char *extraout_EAX;
  short *psVar11;
  uint uVar12;
  code *pcVar13;
  byte *pbVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined *puVar17;
  char local_640 [260];
  char local_53c [128];
  char local_4bc [128];
  char local_43c [260];
  char local_338 [260];
  char local_234 [260];
  char local_130 [24];
  char local_118 [128];
  char local_98 [4];
  int local_94;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  undefined2 local_82;
  char *local_80;
  char *local_7c;
  int local_78;
  undefined1 local_71;
  uint local_70;
  uint uStack_6c;
  uint local_68;
  uint uStack_64;
  char *local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  char *local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  byte *local_44;
  int *local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int *local_30;
  char *local_2c;
  int *local_28;
  byte *local_24;
  char *local_20;
  int *local_1c;
  int *local_18;
  char *local_14;
  char *local_10;
  char local_9;
  char **local_8;

  local_38 = 0xffffffff;
  local_48 = (undefined4 *)0x0;
  local_4c = (undefined4 *)0x0;
  local_20 = (char *)0x0;
  local_10 = (char *)0x0;
  local_18 = (int *)0x0;
  local_1c = (int *)0x0;
  local_50 = (char *)0x0;
  FUN_100084d6();
  pbVar1 = param_2;
  pbVar1[0xa8] = 0;
  pbVar1[0xa9] = 0;
  pbVar1[0xaa] = 0;
  pbVar1[0xab] = 0;
  pbVar1[0xac] = 0;
  pbVar1[0xad] = 0;
  pbVar1[0xae] = 0;
  pbVar1[0xaf] = 0;
  piVar4 = FUN_100029c1();
  if ((pbVar1[0x8c] & 0x10) == 0) {
    (**(code **)(param_1 + 6))(param_1,pbVar1,piVar4,param_3);
  }
  else {
    FUN_100086da(param_1,(int)pbVar1,(int)piVar4);
  }
  local_58 = FUN_10002bba((int)piVar4);
  local_24 = FUN_10002bcc((int)piVar4);
  FUN_10002a4e(piVar4);
  if (*param_1 < 0xd) {
    pcVar8 = *(char **)(pbVar1 + 0x44);
  }
  else {
    pcVar8 = *(char **)(pbVar1 + 0x48);
  }
  param_2 = (byte *)FUN_10003e00(*(int *)(pbVar1 + 0x28),*(char **)(pbVar1 + 0x4c),
                                 *(int *)(pbVar1 + 0x50),pcVar8);
  if (param_2 == (byte *)0x0) {
    free(local_24);
    FUN_1000f4e8((int)pbVar1,0x3ea,*(undefined4 *)(pbVar1 + 0x4c));
    return 0xffffffff;
  }
  iVar5 = FUN_10004cb5((int)param_2);
  pcVar13 = free_exref;
  if (iVar5 != 0) {
    local_44 = FUN_10002958(local_24,local_58,&local_58);
    free(local_24);
    local_24 = local_44;
  }
  local_14 = (char *)FUN_10004718((int)param_2);
  iVar5 = mrbGetProperty((int)pbVar1,&DAT_10018084,0);
  if (iVar5 == 0) {
    local_8 = (char **)0x0;
  }
  else {
    local_8 = *(char ***)(pbVar1 + 0xd0);
  }
  do {
    iVar5 = FUN_1000f4e8((int)pbVar1,100,local_14);
    psVar11 = param_1;
    if ((iVar5 != 0) || (*(int *)(pbVar1 + 0x9c) != 0)) goto LAB_100082de;
    FUN_10004765((int)param_2);
    local_28 = FUN_10003f49((int *)param_2,local_8,(int)(pbVar1 + 0xf4));
    if (local_28 == (int *)0xfffffff6) {
      local_8 = (char **)0x0;
      local_34 = -1;
      local_50 = (char *)0x1;
    }
    else {
      if (local_28 == (int *)0xfffffff8) goto LAB_100082de;
      if (local_28 == (int *)0xfffffff9) {
        pcVar8 = (char *)0x0;
        uVar15 = 0x41b;
        goto LAB_100082d3;
      }
      if (-5 < (int)local_28) {
        if (-2 < (int)local_28) {
          if (local_28 != (int *)0x197) goto LAB_10006ca1;
          iVar5 = 0x197;
          goto LAB_100071f5;
        }
        if ((*(int *)(pbVar1 + 0x5c) != 0) &&
           ((iVar5 = FUN_100116ea((int)pbVar1,*(int *)(pbVar1 + 0x4c),*(char **)(pbVar1 + 0x50)),
            iVar5 != 0 || (iVar5 = FUN_10008a6b(psVar11,(undefined4 *)pbVar1), iVar5 != 0)))) {
          FUN_10004301((int *)param_2);
          free(local_14);
          piVar4 = param_3;
          goto LAB_10008129;
        }
        if (local_28 == (int *)0xfffffffe) {
          uVar15 = 0x3e9;
          pcVar8 = local_14;
        }
        else {
LAB_10007169:
          uVar15 = 0x3ea;
          pcVar8 = local_14;
        }
        goto LAB_100082d3;
      }
LAB_10006ca1:
      iVar5 = mrbGetProperty((int)pbVar1,&DAT_10018084,0);
      if ((iVar5 != 0) && (pcVar8 = local_14, local_8 == (char **)0x0)) {
LAB_10007176:
        uVar15 = 0x413;
        goto LAB_100082d3;
      }
      iVar5 = FUN_10004cb5((int)param_2);
      if (iVar5 != 0) {
        FUN_100043ba((int)param_2,s_Content_Encoding_10018068,&DAT_1001807c);
      }
      FUN_100043ba((int)param_2,s_Pragma_10018054,s_no_cache_1001805c);
      FUN_100043ba((int)param_2,s_Content_type_10018030,s_application_marimba_10018040);
      sprintf(local_130,s_update__d_10018024,(int)*psVar11);
      FUN_100043ba((int)param_2,s_Request_type_10018014,local_130);
      if (0 < *(int *)(pbVar1 + 0xd4)) {
        _ltoa(*(int *)(pbVar1 + 0xd4),local_98,10);
        FUN_100043ba((int)param_2,s_transfer_rate_10018004,local_98);
      }
      if (local_10 == (char *)0x0) {
        local_18 = (int *)_strdup(s_Basic_10017ffc);
        if (*psVar11 < 0xd) {
          pcVar8 = *(char **)(pbVar1 + 0x44);
        }
        else {
          pcVar8 = *(char **)(pbVar1 + 0x48);
        }
        local_1c = (int *)_strdup(pcVar8);
        if ((*(code **)(pbVar1 + 0xc0) != (code *)0x0) &&
           (iVar5 = (**(code **)(pbVar1 + 0xc0))
                              (*(undefined4 *)(pbVar1 + 0x80),local_18,local_1c,local_53c),
           iVar5 == 0)) {
          _Memory = (void *)FUN_10001000(local_53c);
          sprintf(local_118,s__s__s_10017ff4,local_18,_Memory);
          local_10 = _strdup(local_118);
          free(_Memory);
        }
        if (local_10 != (char *)0x0) goto LAB_10006e0a;
      }
      else {
LAB_10006e0a:
        FUN_100043ba((int)param_2,s_Authorization_10017fe4,local_10);
      }
      iVar5 = FUN_1000f4e8((int)pbVar1,0x65,local_14);
      pbVar2 = param_2;
      if (((iVar5 != 0) || (*(int *)(pbVar1 + 0x9c) != 0)) ||
         (iVar5 = FUN_1000404b((int *)param_2,local_58,(int)local_8), iVar5 == -8))
      goto LAB_100082de;
      if (iVar5 != 0) {
        pcVar8 = s_POST_header_10017fa8;
        goto LAB_10007211;
      }
      pbVar14 = local_24;
      uVar12 = local_58;
      puVar6 = (uint *)FUN_10004749((int)pbVar2);
      iVar5 = FUN_100085b2((int)pbVar1,puVar6,(int)pbVar14,uVar12);
      if (iVar5 != 0) {
        puVar6 = (uint *)FUN_10004749((int)pbVar2);
        uVar12 = FUN_1000c245(puVar6);
        if (uVar12 != 0) goto LAB_100082de;
        pcVar8 = s_POST_data_10017f9c;
        goto LAB_10007211;
      }
      iVar5 = FUN_1000f4e8((int)pbVar1,0x66,local_14);
      if (((iVar5 != 0) || (*(int *)(pbVar1 + 0x9c) != 0)) ||
         (iVar5 = FUN_10004441((char *)pbVar2,0,&local_34), iVar5 == -8)) goto LAB_100082de;
      if (iVar5 == -6) {
        pcVar8 = s_bad_reply_10017f90;
        goto LAB_10007211;
      }
      if (iVar5 == -5) {
        uVar15 = 0x3ef;
        pcVar8 = local_14;
        goto LAB_100082d3;
      }
      if (local_34 == 0x191) {
        local_20 = (char *)FUN_100043fe((int)pbVar2,s_WWW_Authenticate_10017fd0);
        iVar5 = FUN_100083b4((int)local_20,' ',0);
        piVar4 = (int *)FUN_100053c2((int)local_20,0,iVar5);
        iVar5 = FUN_10008394((int)local_20,'\"',0);
        iVar7 = FUN_100083b4((int)local_20,'\"',0);
        local_30 = (int *)FUN_100053c2((int)local_20,iVar7 + 1,iVar5);
        iVar5 = _stricmp((char *)local_18,(char *)piVar4);
        if ((iVar5 == 0) && (iVar5 = _stricmp((char *)local_1c,(char *)local_30), iVar5 == 0))
        goto LAB_10007000;
        sprintf(local_118,s__s__s_10017fc8,piVar4,local_30);
        free(local_18);
        free(local_1c);
        free(local_10);
        local_10 = (char *)0x0;
        local_1c = local_30;
        local_18 = piVar4;
        if ((*(code **)(pbVar1 + 0xc0) != (code *)0x0) &&
           (iVar5 = (**(code **)(pbVar1 + 0xc0))
                              (*(undefined4 *)(pbVar1 + 0x80),piVar4,local_30,local_4bc), iVar5 == 0
           )) {
          local_44 = (byte *)FUN_10001000(local_4bc);
          sprintf(local_118,s__s__s_10017ff4,piVar4,local_44);
          local_10 = _strdup(local_118);
          free(local_44);
        }
        if (local_10 == (char *)0x0) goto LAB_10007000;
      }
      else {
LAB_10007000:
        if (local_18 != (int *)0x0) {
          free(local_18);
          local_18 = (int *)0x0;
        }
        if (local_1c != (int *)0x0) {
          free(local_1c);
          local_1c = (int *)0x0;
        }
        if (local_10 != (char *)0x0) {
          free(local_10);
          local_10 = (char *)0x0;
        }
        if (((local_34 != 500) ||
            (pcVar8 = (char *)FUN_10004695((int)param_2), pcVar8 == (char *)0x0)) ||
           (iVar5 = strcmp(pcVar8,s_SSL_Enabled_Host_10017fb4), iVar5 != 0)) {
          if ((((local_34 != 0x1f6) && (local_34 != 0x1f7)) && (local_34 != 0x1f8)) ||
             ((*(int *)(pbVar1 + 0x5c) == 0 ||
              (iVar5 = FUN_100116ea((int)pbVar1,*(int *)(pbVar1 + 0x4c),*(char **)(pbVar1 + 0x50)),
              iVar5 == 0)))) goto LAB_100070ce;
          FUN_10004301((int *)param_2);
          free(local_14);
          psVar11 = param_1;
          piVar4 = param_3;
          goto LAB_10008129;
        }
        if (local_50 != (char *)0x0) goto LAB_10007169;
        if (*(char ***)(pbVar1 + 0xd0) == (char **)0x0) {
          pcVar8 = *(char **)(pbVar1 + 0x4c);
          goto LAB_10007176;
        }
        local_8 = *(char ***)(pbVar1 + 0xd0);
        mrbSetProperty((int)pbVar1,&DAT_10018084,&DAT_1001807c);
      }
      local_34 = -1;
    }
LAB_100070ce:
  } while (local_34 == -1);
  iVar5 = FUN_1000468d((int)param_2);
  if (iVar5 == 200) {
    if (local_8 == (char **)0x0) {
      iVar5 = mrbGetProperty((int)pbVar1,&DAT_10018084,0);
      if (iVar5 == 0) goto LAB_10007277;
      iVar5 = FUN_1000f4e8((int)pbVar1,0x1fa,*(undefined4 *)(pbVar1 + 0x4c));
      if ((iVar5 == 0) && (*(int *)(pbVar1 + 0x9c) == 0)) {
        mrbRemoveProperty((int)pbVar1,&DAT_10018084);
        goto LAB_10007277;
      }
    }
    else {
      FUN_1000f4e8((int)pbVar1,0x1f9,*(undefined4 *)(pbVar1 + 0x4c));
LAB_10007277:
      iVar5 = FUN_1000f4e8((int)pbVar1,0x67,local_14);
      if ((iVar5 == 0) && (*(int *)(pbVar1 + 0x9c) == 0)) {
        piVar4 = (int *)FUN_10004757((int)param_2);
        local_18 = piVar4;
        sVar9 = FUN_10003065(piVar4,&local_78);
        if (-1 < (int)sVar9) {
          if (local_78 != -0x35014111) {
            sprintf(local_118,&DAT_10017f7c,local_78);
            pcVar8 = local_118;
            uVar15 = 0x3eb;
            goto LAB_100082d3;
          }
          iVar5 = FUN_10003028(piVar4,&local_82);
          if (-1 < iVar5) {
            sVar9 = FUN_10003065(piVar4,&local_3c);
            while (-1 < (int)sVar9) {
              if (local_3c < 1) {
                local_3c = local_3c + -1;
                iVar5 = FUN_10003015(piVar4,&local_9);
                if (iVar5 < 0) break;
                iVar5 = (int)local_9;
                switch(iVar5) {
                case 1:
                  iVar5 = FUN_10003028(piVar4,(undefined2 *)&param_1);
                  if (-1 < iVar5) {
                    if ((((pbVar1[0x8c] & 0x10) == 0) || (0xd < (short)param_1)) &&
                       (psVar11 = FUN_1000a67b((int)(short)param_1), psVar11 != (short *)0x0)) {
                      free(local_14);
                      free(local_24);
                      FUN_10004301((int *)param_2);
                      piVar4 = (int *)0x1;
LAB_10008129:
                      uVar15 = FUN_10006af5(psVar11,pbVar1,piVar4);
                      return uVar15;
                    }
                    sprintf(local_118,&DAT_100170c8,(int)(short)param_1);
                    pcVar8 = local_118;
                    uVar15 = 0x3ec;
                    goto LAB_100082d3;
                  }
                  goto LAB_1000820a;
                case 2:
                  local_338[0] = '\0';
                  local_1c = (int *)0x0;
                  if (*(int *)(pbVar1 + 0x88) == 0) {
                    if ((*(int *)(pbVar1 + 0xa0) == 0) &&
                       (iVar5 = FUN_100024b0(*(char **)(pbVar1 + 0x20)), iVar5 != 0)) {
                      pcVar8 = *(char **)(pbVar1 + 0x20);
                      uVar15 = 0x3fe;
                      goto LAB_10007c56;
                    }
                    local_28 = FUN_100036f6(10,0x3f800000,0x1000209c,FUN_100020c3);
                    FUN_10005d7c(*(uint *)(pbVar1 + 0x30),local_28);
                    local_30 = FUN_100036f6(10,0x3f800000,0x1000209c,FUN_100020c3);
                    local_40 = FUN_1000c87d(FUN_1000840b,&LAB_10008423);
                    FUN_1000511f(*(int *)(pbVar1 + 0x30));
                    param_3 = FUN_10005006(*(undefined4 **)(pbVar1 + 0x30),
                                           (int)*(short *)(*(undefined4 **)(pbVar1 + 0x30) + 1));
                    piVar4 = local_18;
                  }
                  if (*(int *)(pbVar1 + 0x88) != 0) {
                    param_3 = FUN_10004efe(0);
                  }
                  sVar9 = FUN_10003065(piVar4,&local_44);
                  if ((int)sVar9 < 0) goto LAB_10007c1a;
                  if (((*(int *)(pbVar1 + 0xa0) == 0) && (*(int *)(pbVar1 + 0x88) == 0)) &&
                     (iVar5 = FUN_100107af((int)pbVar1,(uint)local_44), iVar5 != 0))
                  goto LAB_10007f92;
                  sVar9 = FUN_10003065(piVar4,&local_5c);
                  if (-1 < (int)sVar9) goto LAB_100074a3;
                  goto LAB_10007c1a;
                case 3:
                  free(local_14);
                  free(local_24);
                  FUN_10004301((int *)param_2);
                  if (*(int *)(pbVar1 + 0x88) == 0) {
                    FUN_1000f4e8((int)pbVar1,0x6c,0);
                    FUN_1000f4e8((int)pbVar1,0x6e,0);
                  }
                  return 0;
                case 4:
                  if (*(int *)(pbVar1 + 0x5c) == 0) {
                    pcVar8 = *(char **)(pbVar1 + 0x40);
                    uVar15 = 0x3ee;
                    goto LAB_100082d3;
                  }
                  break;
                case 5:
                  free(local_14);
                  free(local_24);
                  FUN_10004301((int *)param_2);
                  psVar11 = param_1;
                  piVar4 = (int *)0x0;
                  goto LAB_10008129;
                case 6:
                  iVar5 = FUN_10003028(piVar4,(undefined2 *)&param_1);
                  if (iVar5 < 0) goto LAB_1000820a;
                  if (*(int *)(pbVar1 + 0x5c) == 0) {
                    sprintf(local_118,&DAT_100170c8,(int)(short)param_1);
                    pcVar8 = local_118;
                    uVar15 = 0x3ed;
                    goto LAB_100082d3;
                  }
                  break;
                case 7:
                  iVar5 = FUN_10003028(piVar4,(undefined2 *)&param_3);
                  if ((-1 < iVar5) &&
                     (iVar5 = FUN_10003028(piVar4,(undefined2 *)&param_1), -1 < iVar5)) {
                    local_48 = malloc((int)(short)param_1 << 2);
                    local_4c = malloc((int)(short)param_1 << 2);
                    local_28 = (int *)0x0;
                    if (0 < (short)param_1) goto LAB_1000805e;
                    goto LAB_1000809a;
                  }
                  goto LAB_1000820a;
                default:
                  sprintf(local_118,&DAT_100170c8,iVar5);
                  pcVar8 = local_118;
                  uVar15 = 0x3f0;
                  goto LAB_100082d3;
                case 9:
                  sprintf(local_118,&DAT_100170c8,iVar5);
                  pcVar8 = local_118;
                  uVar15 = 0x3f5;
                  goto LAB_100082d3;
                case 10:
                  sVar9 = FUN_10003065(piVar4,&param_3);
                  if ((-1 < (int)sVar9) &&
                     (sVar9 = FUN_100031e5(piVar4,(int *)&param_1), -1 < (int)sVar9)) {
                    sprintf(local_118,s__d___s__10017f60,param_3,param_1);
                    FUN_1000f4e8((int)pbVar1,0x3f1,local_118);
                    free(param_1);
                    goto LAB_100082f6;
                  }
                  goto LAB_1000820a;
                case 0xc:
                  sprintf(local_118,&DAT_10017f5c,*(undefined4 *)(pbVar1 + 0x40));
                  pcVar8 = local_118;
                  uVar15 = 0x419;
                  goto LAB_100082d3;
                }
                FUN_100116ea((int)pbVar1,*(int *)(pbVar1 + 0x4c),*(char **)(pbVar1 + 0x50));
                free(local_14);
                free(local_24);
                goto LAB_100081ca;
              }
              local_3c = local_3c + -1;
              sVar9 = FUN_10003015(piVar4,&local_71);
            }
          }
        }
LAB_1000820a:
        puVar6 = (uint *)FUN_10002fe7((int)piVar4);
        uVar12 = FUN_1000c245(puVar6);
        if (uVar12 == 0) {
          uVar15 = 0x3f4;
          pcVar8 = local_14;
          goto LAB_100082d3;
        }
      }
    }
LAB_100082de:
    FUN_1000f4e8((int)pbVar1,0x6f,local_14);
    pbVar1[0x9c] = 1;
    pbVar1[0x9d] = 0;
    pbVar1[0x9e] = 0;
    pbVar1[0x9f] = 0;
  }
  else {
    if (iVar5 == 0x191) {
      uVar15 = 0x403;
      pcVar8 = local_20;
    }
    else {
      if (iVar5 == 0x197) {
        mrbRemoveProperty((int)pbVar1,s_http_password_10017f80);
      }
LAB_100071f5:
      sprintf(local_118,&DAT_100170c8,iVar5);
      pcVar8 = local_118;
LAB_10007211:
      uVar15 = 1000;
    }
LAB_100082d3:
    FUN_1000f4e8((int)pbVar1,uVar15,pcVar8);
  }
  goto LAB_100082f6;
LAB_1000805e:
  iVar5 = (int)(short)local_28;
  sVar9 = FUN_100031e5(local_18,local_48 + iVar5);
  piVar4 = local_18;
  if (((int)sVar9 < 0) ||
     (sVar9 = FUN_10003065(local_18,local_4c + iVar5), piVar4 = local_18, (int)sVar9 < 0))
  goto LAB_1000820a;
  local_28 = (int *)((int)local_28 + 1);
  if ((short)param_1 <= (short)local_28) {
LAB_1000809a:
    FUN_10011575((undefined4 *)pbVar1,local_48,local_4c,(int)(short)param_1,(int)(short)param_3);
    free(local_14);
    free(local_24);
    free(local_48);
    free(local_4c);
LAB_100081ca:
    FUN_10004301((int *)param_2);
    uVar15 = FUN_10006a92(pbVar1);
    return uVar15;
  }
  goto LAB_1000805e;
LAB_100074a3:
  if (local_5c < 1) goto LAB_10007c96;
  iVar5 = FUN_10003015(piVar4,&local_9);
  if (iVar5 < 0) goto LAB_10007c1a;
  if (local_9 == '\x01') {
    local_1c = (int *)((int)local_1c + 1);
LAB_10007658:
    sVar9 = FUN_100031e5(piVar4,(int *)&local_60);
    if ((((int)sVar9 < 0) || (sVar9 = FUN_100030b4(piVar4,&local_70), (int)sVar9 < 0)) ||
       ((sVar9 = FUN_100030b4(piVar4,&local_68), (int)sVar9 < 0 ||
        ((sVar9 = FUN_10003065(piVar4,&local_10), (int)sVar9 < 0 ||
         (iVar5 = (**(code **)(param_1 + 2))(piVar4,pbVar1,&local_54), iVar5 < 0))))))
    goto LAB_10007c1a;
    uVar12 = FUN_10008a35(local_54);
    local_8 = (char **)(uVar12 & 0x3f);
    strcpy(local_234,local_338);
    strcat(local_234,local_60);
    (*pcVar13)(local_60);
    local_2c = (char *)0x0;
    if (*(int *)(pbVar1 + 0x88) == 0) {
      if (((((pbVar1[0x8c] & 4) != 0) || (local_9 != '\x03')) ||
          (iVar5 = FUN_10005266(*(undefined4 **)(pbVar1 + 0x30),local_234), iVar5 == 0)) ||
         (((char **)(int)*(short *)(iVar5 + 0x2c) == (char **)(uVar12 & 0x3f) ||
          (iVar5 = FUN_100011d7(*(int *)(iVar5 + 0x10),*(int *)(iVar5 + 0x14),*(int *)(iVar5 + 0x18)
                                ,*(int *)(iVar5 + 0x1c),local_70,uStack_6c,local_68,uStack_64),
          pcVar13 = free_exref, iVar5 == 0)))) {
        iVar5 = (local_9 != '\x01') + 200;
        goto LAB_10007792;
      }
      local_2c = (char *)0x1;
    }
    else {
      iVar5 = 0xcc;
LAB_10007792:
      iVar5 = FUN_1000f4e8((int)pbVar1,iVar5,local_234);
      if (iVar5 != 0) goto LAB_10007f92;
    }
    piVar4 = local_18;
    if ((*(int *)(pbVar1 + 0xa0) == 0) || (0xc < *param_1)) {
      if (*(int *)(pbVar1 + 0x88) == 0) {
        if (local_2c == (char *)0x0) {
          local_1c = (int *)((int)local_1c + 1);
          puVar10 = FUN_10004f89(local_70,uStack_6c,local_68,uStack_64,(short)local_8,local_10,
                                 (int)local_10 >> 0x1f,0);
          param_3 = FUN_1000540b(param_3,local_234,puVar10);
          piVar4 = local_18;
          if ((local_54 & 0xc000) == 0) {
            uVar12 = FUN_1000378d(local_28,&local_70);
            if (uVar12 == 0) {
              uVar12 = FUN_1000378d(local_30,&local_70);
              if (uVar12 == 0) {
                local_8 = (char **)FUN_100083d0(local_234,local_70,uStack_6c,local_68,uStack_64,
                                                local_10);
                local_2c = (char *)FUN_1000f916((int)pbVar1,local_70,uStack_6c,local_68,uStack_64);
                bVar3 = FUN_100034b0(local_2c);
                if (CONCAT31(extraout_var_02,bVar3) == 0) {
                  pcVar8 = (char *)FUN_10005266(*(undefined4 **)(pbVar1 + 0x30),local_234);
                  local_8[7] = pcVar8;
                }
                else {
                  iVar5 = FUN_10003374(local_2c);
                  pcVar8 = (char *)FUN_100033e5(iVar5);
                  FUN_100033b9(iVar5);
                  if (pcVar8 == local_10) {
                    free(local_2c);
                    goto LAB_10007ba5;
                  }
                  local_8[8] = (char *)((uint)pcVar8 & 0xffffffbe);
                }
                puVar6 = (uint *)FUN_100011b2();
                *puVar6 = local_70;
                puVar6[1] = uStack_6c;
                puVar6[2] = local_68;
                puVar6[3] = uStack_64;
                FUN_10003881(local_30,(uint)puVar6,(uint)local_8);
                puVar10 = FUN_1000843c(local_8);
                FUN_1000c907(local_40,puVar10);
                pcVar8 = local_2c;
                goto LAB_10007c02;
              }
            }
            else {
              piVar4 = (int *)FUN_1000378d(local_28,&local_70);
              local_2c = (char *)FUN_1000583e(piVar4);
              pcVar8 = (char *)mrbGetLocation((int)pbVar1,local_2c);
              if (pcVar8 == (char *)0x0) {
                local_8 = (char **)FUN_1000f7fd((undefined4 *)pbVar1,piVar4);
              }
              else {
                local_8 = (char **)_strdup(pcVar8);
              }
              local_20 = (char *)FUN_1000f916((int)pbVar1,local_70,uStack_6c,local_68,uStack_64);
              bVar3 = FUN_100034b0(local_20);
              if ((CONCAT31(extraout_var,bVar3) != 0) &&
                 (bVar3 = FUN_100034b0(local_8), CONCAT31(extraout_var_00,bVar3) != 0)) {
                iVar5 = FUN_100033f1(local_20);
                iVar7 = FUN_100033f1((char *)local_8);
                if (iVar5 == iVar7) {
                  free(local_8);
                  free(local_20);
                  free(local_2c);
                  goto LAB_10007c09;
                }
              }
              iVar5 = FUN_1000f517((char *)local_8,&local_94);
              if ((iVar5 == 0) &&
                 (iVar5 = FUN_100011d7(local_70,uStack_6c,local_68,uStack_64,local_94,iStack_90,
                                       iStack_8c,iStack_88), iVar5 != 0)) {
                iVar5 = strcmp(local_234,local_2c);
                if (((iVar5 != 0) && (*(int *)(pbVar1 + 0xa0) == 0)) &&
                   (iVar5 = FUN_1000fa80((int)pbVar1,(char *)local_8,local_20), iVar5 != 0)) {
                  FUN_1000f4e8((int)pbVar1,0x3fc,local_234);
                  free(local_8);
                  free(local_20);
                  free(local_2c);
                  pcVar13 = free_exref;
                  goto LAB_10007fb0;
                }
              }
              else {
                free(local_2c);
                local_8 = (char **)FUN_100083d0(local_234,local_70,uStack_6c,local_68,uStack_64,
                                                local_10);
                bVar3 = FUN_100034b0(local_20);
                if (CONCAT31(extraout_var_01,bVar3) == 0) {
                  pcVar8 = (char *)FUN_10005266(*(undefined4 **)(pbVar1 + 0x30),local_234);
                  local_8[7] = pcVar8;
                }
                else {
                  iVar5 = FUN_10003374(local_20);
                  pcVar8 = (char *)FUN_100033e5(iVar5);
                  FUN_100033b9(iVar5);
                  if (pcVar8 == local_10) {
                    free(local_20);
LAB_10007ba5:
                    FUN_1000840b(local_8);
                    goto LAB_10007c09;
                  }
                  local_8[8] = (char *)((uint)pcVar8 & 0xffffffbe);
                }
                puVar6 = (uint *)FUN_100011b2();
                *puVar6 = local_70;
                puVar6[1] = uStack_6c;
                puVar6[2] = local_68;
                puVar6[3] = uStack_64;
                FUN_10003881(local_30,(uint)puVar6,(uint)local_8);
                puVar10 = FUN_1000843c(local_8);
                FUN_1000c907(local_40,puVar10);
                pcVar8 = local_20;
LAB_10007c02:
                free(pcVar8);
              }
            }
          }
          else {
            sVar9 = FUN_10003065(local_18,&local_10);
            if ((int)sVar9 < 0) {
LAB_10007c32:
              puVar6 = (uint *)FUN_10002fe7((int)piVar4);
              uVar12 = FUN_1000c245(puVar6);
              pcVar13 = free_exref;
              pcVar8 = local_14;
              goto joined_r0x10007c42;
            }
            if (*(int *)(pbVar1 + 0xa0) == 0) {
              iVar5 = FUN_1000a4f0((int)pbVar1,local_18,(size_t)local_10,local_70,uStack_6c,local_68
                                   ,uStack_64,local_234);
              pcVar13 = free_exref;
              if (iVar5 != 0) goto LAB_10007fb0;
            }
            else {
              sVar9 = FUN_10002f6c(piVar4,(size_t)local_10);
              if ((int)sVar9 < 0) goto LAB_10007c32;
            }
            *(char **)(pbVar1 + 0xac) = local_10 + *(int *)(pbVar1 + 0xac);
            *(char **)(pbVar1 + 0xa8) = local_10 + *(int *)(pbVar1 + 0xa8);
          }
        }
        else if (((local_54 & 0xc000) != 0) &&
                ((sVar9 = FUN_10003065(local_18,&local_10), (int)sVar9 < 0 ||
                 (sVar9 = FUN_10002f6c(piVar4,(size_t)local_10), (int)sVar9 < 0))))
        goto LAB_10007c1a;
      }
      else {
        puVar10 = FUN_10004f89(local_70,uStack_6c,local_68,uStack_64,(short)local_8,local_10,
                               (int)local_10 >> 0x1f,0);
        param_3 = FUN_1000540b(param_3,local_234,puVar10);
        piVar4 = local_18;
        if (((local_54 & 0xc000) != 0) &&
           ((sVar9 = FUN_10003065(local_18,&local_10), (int)sVar9 < 0 ||
            (sVar9 = FUN_10002f6c(piVar4,(size_t)local_10), (int)sVar9 < 0)))) goto LAB_10007c32;
      }
    }
    else {
      *(char **)(pbVar1 + 0xa4) = local_10 + *(int *)(pbVar1 + 0xa4);
    }
  }
  else if (local_9 == '\x02') {
    local_1c = (int *)((int)local_1c + 1);
    sVar9 = FUN_100031e5(piVar4,(int *)&local_80);
    if ((int)sVar9 < 0) goto LAB_10007c1a;
    strcpy(local_43c,local_338);
    strcat(local_43c,local_80);
    (*pcVar13)(local_80);
    if (*(int *)(pbVar1 + 0x88) == 0) {
      uVar15 = 0xca;
    }
    else {
      uVar15 = 0xcc;
    }
    iVar5 = FUN_1000f4e8((int)pbVar1,uVar15,local_43c);
    if (iVar5 != 0) goto LAB_10007f92;
    if (*(int *)(pbVar1 + 0xa0) == 0) {
      puVar10 = FUN_10004efe(4);
      param_3 = FUN_1000540b(param_3,local_43c,puVar10);
    }
  }
  else {
    if (local_9 == '\x03') goto LAB_10007658;
    if (local_9 == '\x04') {
      local_1c = (int *)((int)local_1c + 1);
      sVar9 = FUN_100031e5(piVar4,(int *)&local_7c);
      if ((int)sVar9 < 0) goto LAB_10007c1a;
      strcpy(local_640,local_338);
      strcat(local_640,local_7c);
      (*pcVar13)(local_7c);
      iVar5 = FUN_1000f4e8((int)pbVar1,0xcb,local_640);
      if (iVar5 != 0) goto LAB_10007f92;
      if (*(int *)(pbVar1 + 0xa0) == 0) {
        param_3 = (int *)FUN_10005747((int)param_3,local_640);
      }
    }
    else if (local_9 == '\x05') {
      sVar9 = FUN_100031e5(piVar4,(int *)&local_50);
      if ((int)sVar9 < 0) goto LAB_10007c1a;
      strcpy(local_338,local_50);
      sVar9 = strlen(local_50);
      if (sVar9 != 0) {
        strcat(local_338,&DAT_10017148);
      }
      (*pcVar13)(local_50);
      goto LAB_100074a3;
    }
  }
LAB_10007c09:
  local_5c = local_5c + -1;
  pcVar13 = free_exref;
  piVar4 = local_18;
  goto LAB_100074a3;
LAB_10007c96:
  if ((*(int *)(pbVar1 + 0xa0) == 0) || (0xc < *param_1)) {
    if (*(int *)(pbVar1 + 0x88) == 0) {
      FUN_10004301((int *)param_2);
      param_2 = (byte *)0x0;
      if ((*(int *)(pbVar1 + 0xa0) == 0) && (*(int *)(pbVar1 + 0x88) == 0)) {
        FUN_1001081a((int)pbVar1,(int)local_44);
        FUN_1001089b((int)pbVar1);
      }
      iVar5 = FUN_1000ca60((int)local_40);
      if (iVar5 == 0) {
        if ((*(int *)(pbVar1 + 0xa0) == 0) || (*(int *)(pbVar1 + 0xa8) == 0)) {
          if (((pbVar1[0x8c] & 4) != 0) || (local_1c != (int *)0x0)) goto LAB_10007d8d;
          FUN_1000f4e8((int)pbVar1,0x6c,0);
          FUN_1000f4e8((int)pbVar1,0x6e,0);
          FUN_100050a3(param_3);
        }
        else {
          sprintf(local_118,s__d__d_10017f74,*(undefined4 *)(pbVar1 + 0xac),*(int *)(pbVar1 + 0xa8))
          ;
          FUN_1000f4e8((int)pbVar1,0x6d,local_118);
          *(undefined4 *)(pbVar1 + 0xa4) = *(undefined4 *)(pbVar1 + 0xa8);
        }
LAB_10007dc1:
        local_38 = 0;
        goto LAB_10007fb0;
      }
LAB_10007d8d:
      iVar5 = FUN_1000ca60((int)local_40);
      if ((iVar5 < 1) ||
         (iVar5 = FUN_1000903e(param_1,pbVar1,local_40,local_30,local_28,1), iVar5 == 0)) {
        if (*(int *)(pbVar1 + 0xa0) != 0) goto LAB_10007dc1;
        bVar3 = FUN_1000ba31(*(undefined4 **)(pbVar1 + 0x30));
        local_60 = (char *)CONCAT31(extraout_var_03,bVar3);
        bVar3 = FUN_1000ba31(param_3);
        param_1 = (short *)CONCAT31(extraout_var_04,bVar3);
        if (*(int *)(pbVar1 + 0xd0) != 0) {
          if (local_60 == (char *)0x0) {
            if (param_1 != (short *)0x0) goto LAB_10007e53;
            iVar5 = FUN_1000f4e8((int)pbVar1,0x1f7,*(undefined4 *)(pbVar1 + 0x40));
            if (iVar5 == 0) goto LAB_10007e4e;
          }
          else {
            if (param_1 == (short *)0x0) {
              iVar5 = FUN_1000f4e8((int)pbVar1,0x1f8,*(undefined4 *)(pbVar1 + 0x40));
              if (iVar5 != 0) goto LAB_10007f89;
              mrbRemoveProperty((int)pbVar1,s_signed_cert_10017f68);
LAB_10007e4e:
              if (param_1 == (short *)0x0) goto LAB_10007eaf;
            }
LAB_10007e53:
            pcVar8 = FUN_1000b6c1((char *)pbVar1,param_3);
            if (extraout_EAX == (char *)0xfffffffc) {
              uVar15 = *(undefined4 *)(pbVar1 + 0x40);
              uVar16 = 0x416;
            }
            else if (extraout_EAX == (char *)0xfffffffd) {
              uVar15 = *(undefined4 *)(pbVar1 + 0x40);
              uVar16 = 0x415;
            }
            else {
              if (extraout_EAX != (char *)0xfffffffe) {
                if (extraout_EAX == pcVar8) {
                  uVar15 = *(undefined4 *)(pbVar1 + 0x40);
                  uVar16 = 500;
                }
                else {
                  uVar15 = *(undefined4 *)(pbVar1 + 0x40);
                  if (extraout_EAX != (char *)0x1) {
                    uVar16 = 0x412;
                    goto LAB_10008356;
                  }
                  uVar16 = 0x1f6;
                }
LAB_10007e9e:
                iVar5 = FUN_1000f4e8((int)pbVar1,uVar16,uVar15);
                if (iVar5 == 0) goto LAB_10007eaf;
                goto LAB_10007f89;
              }
              uVar15 = *(undefined4 *)(pbVar1 + 0x40);
              uVar16 = 0x414;
            }
LAB_10008356:
            FUN_1000f4e8((int)pbVar1,uVar16,uVar15);
          }
LAB_10007f89:
          FUN_100050a3(param_3);
          goto LAB_10007f92;
        }
        if (param_1 != (short *)0x0) {
          uVar15 = *(undefined4 *)(pbVar1 + 0x40);
          uVar16 = 0x1f5;
          goto LAB_10007e9e;
        }
LAB_10007eaf:
        param_1 = (short *)FUN_10003389(*(char **)(pbVar1 + 0x14));
        if (param_1 == (short *)0xffffffff) {
          FUN_1000f4e8((int)pbVar1,0x3f3,*(undefined4 *)(pbVar1 + 0x14));
        }
        else {
          piVar4 = (int *)FUN_1000bfed(param_1);
          if (piVar4 == (int *)0x0) {
            FUN_1000f4e8((int)pbVar1,0x3f3,*(undefined4 *)(pbVar1 + 0x14));
            FUN_100033b9((int)param_1);
          }
          else {
            iVar5 = FUN_1000597c((int)param_3,piVar4);
            if (iVar5 == 0) {
              FUN_1000c00c(piVar4);
              uVar15 = FUN_1000847e(*(int *)(pbVar1 + 0xac),*(uint *)(pbVar1 + 0xa8));
              iVar5 = FUN_1000f4e8((int)pbVar1,0x69,uVar15);
              if (iVar5 != 0) {
                (*pcVar13)(uVar15);
                goto LAB_10007f89;
              }
              (*pcVar13)(uVar15);
              iVar5 = FUN_1000fbbe((undefined4 *)pbVar1,(uint)param_3);
              if (iVar5 == 0) {
                puVar17 = (undefined *)0x0;
                uVar15 = 0x6e;
                goto LAB_10007f77;
              }
            }
            else {
              FUN_1000f4e8((int)pbVar1,0x3f8,*(undefined4 *)(pbVar1 + 0x14));
              FUN_1000c00c(piVar4);
            }
          }
        }
      }
      FUN_100050a3(param_3);
      goto LAB_10007fb0;
    }
    FUN_100050a3(*(undefined4 **)(pbVar1 + 0x30));
    *(int **)(pbVar1 + 0x30) = param_3;
  }
  else {
    puVar17 = &DAT_10018c80;
    uVar15 = 0x6d;
LAB_10007f77:
    FUN_1000f4e8((int)pbVar1,uVar15,puVar17);
  }
  local_38 = 0;
  goto LAB_10007fb0;
LAB_10007c1a:
  puVar6 = (uint *)FUN_10002fe7((int)piVar4);
  uVar12 = FUN_1000c245(puVar6);
  pcVar8 = local_14;
joined_r0x10007c42:
  local_14 = pcVar8;
  if (uVar12 == 0) {
    uVar15 = 0x3f4;
LAB_10007c56:
    FUN_1000f4e8((int)pbVar1,uVar15,pcVar8);
  }
  else {
LAB_10007f92:
    FUN_1000f4e8((int)pbVar1,0x6f,local_14);
    pbVar1[0x9c] = 1;
    pbVar1[0x9d] = 0;
    pbVar1[0x9e] = 0;
    pbVar1[0x9f] = 0;
    pcVar13 = free_exref;
  }
LAB_10007fb0:
  if ((*(int *)(pbVar1 + 0xa0) == 0) && (*(int *)(pbVar1 + 0x88) == 0)) {
    FUN_10003757(local_28);
    FUN_10003757(local_30);
    FUN_1000c8de(local_40);
  }
LAB_100082f6:
  if (local_24 != (byte *)0x0) {
    (*pcVar13)(local_24);
  }
  if (local_14 != (char *)0x0) {
    (*pcVar13)(local_14);
  }
  if (local_48 != (undefined4 *)0x0) {
    (*pcVar13)(local_48);
  }
  if (local_4c != (undefined4 *)0x0) {
    (*pcVar13)(local_4c);
  }
  if (param_2 != (byte *)0x0) {
    FUN_10004301((int *)param_2);
  }
  return local_38;
}



/* VA 10008394 */

int __cdecl FUN_10008394(int param_1,char param_2,int param_3)

{
  int iVar1;

  iVar1 = -1;
  for (; *(char *)(param_3 + param_1) != '\0'; param_3 = param_3 + 1) {
    if (*(char *)(param_3 + param_1) == param_2) {
      iVar1 = param_3;
    }
  }
  return iVar1;
}



/* VA 100083b4 */

int __cdecl FUN_100083b4(int param_1,char param_2,int param_3)

{
  while( true ) {
    if (*(char *)(param_3 + param_1) == '\0') {
      return -1;
    }
    if (*(char *)(param_3 + param_1) == param_2) break;
    param_3 = param_3 + 1;
  }
  return param_3;
}



/* VA 100083d0 */

undefined4 * __cdecl
FUN_100083d0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x28);
  pcVar2 = _strdup(param_1);
  puVar1[2] = param_2;
  puVar1[3] = param_3;
  puVar1[4] = param_4;
  puVar1[7] = 0;
  puVar1[8] = 0;
  *puVar1 = pcVar2;
  puVar1[5] = param_5;
  puVar1[6] = param_6;
  return puVar1;
}



/* VA 1000840b */

void __cdecl FUN_1000840b(undefined4 *param_1)

{
  free((void *)*param_1);
  free(param_1);
  return;
}



/* VA 1000843c */

undefined4 * __cdecl FUN_1000843c(undefined4 *param_1)

{
  undefined4 *puVar1;
  char *pcVar2;

  puVar1 = malloc(0x28);
  pcVar2 = _strdup((char *)*param_1);
  *puVar1 = pcVar2;
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  puVar1[4] = param_1[4];
  puVar1[5] = param_1[5];
  puVar1[6] = param_1[6];
  puVar1[7] = param_1[7];
  puVar1[8] = param_1[8];
  return puVar1;
}



/* VA 1000847e */

void __cdecl FUN_1000847e(int param_1,uint param_2)

{
  char local_84 [128];

  if (param_2 == 0) {
    sprintf(local_84,s_0_0_100___10018094);
  }
  else {
    sprintf(local_84,s__d__d__d___10018088,param_1,param_2,
            (param_2 * 100 + param_1 * -100) / param_2);
  }
  _strdup(local_84);
  return;
}



/* VA 100084d6 */

void FUN_100084d6(void)

{
  undefined *puVar1;
  undefined *puVar2;
  char *_Source;
  _OSVERSIONINFOA local_a4;
  undefined1 local_10 [8];
  short sStack_8;

  if (DAT_10018d50 == 0) {
    local_a4.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_a4);
    sprintf(&DAT_10018d40,&DAT_100180e8);
    sprintf(&DAT_10018ca8,s__d__d_100180e0,local_a4.dwMajorVersion,local_a4.dwMinorVersion);
    if (local_a4.dwPlatformId == 0) {
      _Source = s_Win32s_on_Windows_3_1_100180a8;
    }
    else if (local_a4.dwPlatformId == 1) {
      _Source = s_Windows_95_100180c0;
    }
    else if (local_a4.dwPlatformId == 2) {
      _Source = s_Windows_NT_100180cc;
    }
    else {
      _Source = s_Win32_100180d8;
    }
    strcpy(&DAT_10018c88,_Source);
    ftime(local_10);
    DAT_10018cb8._0_2_ = (-(ushort)(sStack_8 != 0) & 0x3c) - (short)stack0xfffffff6;
    puVar1 = FUN_100060dd();
    puVar2 = FUN_1000604b();
    sprintf(&DAT_10018cc0,s__s__s_100180a0,puVar2,puVar1);
    DAT_10018d50 = 1;
  }
  return;
}



/* VA 100085b2 */

/* WARNING: Removing unreachable block (ram,0x1000861d) */

undefined4 __cdecl FUN_100085b2(int param_1,uint *param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;

  iVar4 = 0;
  lVar6 = 0;
  iVar1 = FUN_100107af(param_1,param_4);
  if (iVar1 == 0) {
    if (0 < (int)param_4) {
      do {
        uVar3 = 0x1000;
        if ((int)(param_4 - iVar4) < 0x1001) {
          uVar3 = param_4 - iVar4;
        }
        if (0 < *(int *)(param_1 + 0xd8)) {
          if (0 < iVar4) {
            lVar5 = FUN_100086a2();
            if (lVar5 < lVar6 + 1000) {
              Sleep(((int)lVar6 + 1000) - (int)lVar5);
            }
          }
          lVar6 = FUN_100086a2();
          if ((int)*(uint *)(param_1 + 0xd8) <= (int)uVar3) {
            uVar3 = *(uint *)(param_1 + 0xd8);
          }
        }
        iVar1 = FUN_1000c0c5((int *)param_2,(char *)(param_3 + iVar4),uVar3);
        if (iVar1 == -1) {
          return 0xffffffff;
        }
        FUN_1000c13e((int *)param_2);
        iVar4 = iVar4 + iVar1;
        iVar1 = FUN_1001081a(param_1,iVar1);
        if (iVar1 != 0) goto LAB_10008696;
      } while (iVar4 < (int)param_4);
    }
    FUN_1001089b(param_1);
    uVar2 = 0;
  }
  else {
LAB_10008696:
    FUN_1000c219(param_2,4);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* VA 100086a2 */

longlong FUN_100086a2(void)

{
  longlong lVar1;
  uint local_10;
  ushort local_c;

  ftime(&local_10);
  lVar1 = __allmul(local_10,(int)local_10 >> 0x1f,1000,0);
  return lVar1 + (int)(uint)local_c;
}



/* VA 100086da */

int __cdecl FUN_100086da(undefined2 *param_1,int param_2,int param_3)

{
  undefined2 extraout_var;
  int iVar1;

  FUN_10002c45(param_3,0xcafebeef);
  FUN_10002c21(param_3,CONCAT22(extraout_var,*param_1));
  FUN_10002c79(param_3,*(undefined4 *)(param_2 + 0x70),*(int *)(param_2 + 0x74));
  FUN_10002d05(param_3,*(char **)(param_2 + 0x38));
  FUN_10002c45(param_3,*(undefined4 *)(param_2 + 0x3c));
  FUN_10002c21(param_3,3);
  FUN_1000876e(param_2,param_3);
  FUN_10002d3c(param_3);
  FUN_10002d05(param_3,*(char **)(param_2 + 0x48));
  FUN_10002c21(param_3,0);
  iVar1 = FUN_10008955((int)param_1,param_3,*(int **)(param_2 + 0x30));
  return -(uint)(iVar1 != 0);
}



/* VA 1000876e */

undefined4 __cdecl FUN_1000876e(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  size_t sVar5;
  void *_Memory;
  char *pcVar6;
  undefined4 local_1c [3];
  int local_10;
  int iStack_c;
  int iStack_8;

  if (*(int *)(param_1 + 0x5c) == 0) {
    pcVar6 = s_false_10018110;
  }
  else {
    pcVar6 = &DAT_1001807c;
  }
  pcVar6 = _strdup(pcVar6);
  pcVar1 = _strdup(s_toRepeater_10018104);
  FUN_10003881(*(int **)(param_1 + 0x84),(uint)pcVar1,(uint)pcVar6);
  if (*(int *)(param_1 + 0x68) == 0) {
    FUN_1000399d(*(int **)(param_1 + 0x84),s_clientIP_100180ec);
  }
  else {
    pcVar6 = FUN_100088f5();
    if (pcVar6 != (char *)0x0) {
      iVar2 = strcmp(pcVar6,s_127_0_0_1_100180f8);
      if (iVar2 == 0) {
        free(pcVar6);
      }
      else {
        pcVar1 = _strdup(s_clientIP_100180ec);
        FUN_10003881(*(int **)(param_1 + 0x84),(uint)pcVar1,(uint)pcVar6);
      }
    }
  }
  iVar2 = FUN_10003785(*(int *)(param_1 + 0x84));
  if ((iVar2 == 0) || (0xff < iVar2)) {
    FUN_10002c45(param_2,0);
  }
  else {
    piVar3 = FUN_100029c1();
    FUN_10002d3c((int)piVar3);
    piVar4 = (int *)FUN_100037f6(local_1c,*(undefined4 *)(param_1 + 0x84));
    local_10 = *piVar4;
    iStack_c = piVar4[1];
    iStack_8 = piVar4[2];
    while (pcVar6 = (char *)FUN_1000381b(&local_10), pcVar6 != (char *)0x0) {
      pcVar1 = (char *)FUN_1000378d(*(int **)(param_1 + 0x84),pcVar6);
      FUN_10002d05((int)piVar3,pcVar6);
      sVar5 = strlen(pcVar1);
      FUN_10002c45((int)piVar3,sVar5);
      sVar5 = strlen(pcVar1);
      FUN_10002ae4((int)piVar3,(int)pcVar1,sVar5);
    }
    sVar5 = FUN_10002bba((int)piVar3);
    _Memory = FUN_10002bcc((int)piVar3);
    FUN_10002c45(param_2,sVar5);
    FUN_10002ae4(param_2,(int)_Memory,sVar5);
    free(_Memory);
    FUN_10002a4e(piVar3);
  }
  return 0;
}



/* VA 100088f5 */

char * FUN_100088f5(void)

{
  int iVar1;
  hostent *phVar2;
  char *pcVar3;
  char local_108 [256];
  _union_1226 local_8;

  iVar1 = gethostname(local_108,0x100);
  if (iVar1 != -1) {
    phVar2 = gethostbyname(local_108);
    if (phVar2 != (hostent *)0x0) {
      memcpy(&local_8,*phVar2->h_addr_list,(int)phVar2->h_length);
      pcVar3 = inet_ntoa((in_addr)local_8);
      pcVar3 = _strdup(pcVar3);
      return pcVar3;
    }
    WSAGetLastError();
  }
  return (char *)0x0;
}



/* VA 10008955 */

undefined4 __cdecl FUN_10008955(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int local_8;

  piVar1 = param_3;
  bVar2 = FUN_100050e8((int)param_3);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    uVar6 = (**(code **)(param_1 + 8))(param_2,param_3);
  }
  else {
    iVar8 = (int)(short)param_3[1];
    puVar7 = (undefined4 *)param_3[2];
    if (-1 < iVar8 + -1) {
      param_3 = puVar7 + iVar8 + -1;
      local_8 = iVar8;
      do {
        uVar3 = FUN_100050f6(*param_3);
        if (uVar3 != 0) {
          iVar8 = iVar8 + -1;
        }
        param_3 = param_3 + -1;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
    iVar8 = FUN_10002c21(param_2,iVar8);
    if (iVar8 < 0) {
      puVar4 = (uint *)FUN_10002fe7(param_2);
      FUN_1000c245(puVar4);
LAB_10008a1f:
      uVar6 = 0xffffffff;
    }
    else {
      iVar8 = piVar1[1];
      param_3 = (int *)0x0;
      if (0 < (short)iVar8) {
        do {
          piVar1 = (int *)*puVar7;
          uVar3 = FUN_100050f6((int)piVar1);
          if (uVar3 == 0) {
            iVar5 = FUN_10002d05(param_2,(char *)*piVar1);
            if (iVar5 < 0) {
              puVar4 = (uint *)FUN_10002fe7(param_2);
              FUN_1000c245(puVar4);
              goto LAB_10008a1f;
            }
            iVar5 = FUN_10008955(param_1,param_2,piVar1);
            if (iVar5 != 0) goto LAB_10008a1f;
          }
          param_3 = (int *)((int)param_3 + 1);
          puVar7 = puVar7 + 1;
        } while ((int)param_3 < (int)(short)iVar8);
      }
      uVar6 = 0;
    }
  }
  return uVar6;
}



/* VA 10008a35 */

uint __cdecl FUN_10008a35(uint param_1)

{
  uint uVar1;

  uVar1 = param_1;
  if (DAT_10017f58 == 0) {
    uVar1 = param_1 & 1;
    if ((param_1 & 2) != 0) {
      uVar1 = (uint)(byte)((byte)uVar1 | 2);
    }
    if ((param_1 & 4) != 0) {
      uVar1 = uVar1 | 4;
    }
    if ((param_1 & 8) != 0) {
      uVar1 = uVar1 | 8;
    }
    if ((param_1 & 0x10) != 0) {
      uVar1 = uVar1 | 0x10;
    }
  }
  if ((param_1 & 0x8000) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  return uVar1;
}



/* VA 10008a6b */

undefined4 __cdecl FUN_10008a6b(short *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  int *piVar5;
  uint *puVar6;
  size_t sVar7;
  uint uVar8;
  char *pcVar9;
  code *pcVar10;
  undefined4 uVar11;
  char local_d0 [128];
  char local_50 [26];
  undefined2 local_36;
  int local_34;
  int local_30;
  char **local_2c;
  short local_28;
  undefined1 local_25;
  int *local_24;
  uint local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  byte *local_10;
  short local_a;
  char *local_8;

  puVar1 = param_2;
  local_14 = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  param_2[0x17] = 0;
  iVar2 = FUN_1000ca60(param_2[0x16]);
  if (iVar2 == 0) {
    return 0;
  }
  piVar3 = FUN_100029c1();
  (**(code **)(param_1 + 8))(param_1,puVar1,piVar3);
  local_20 = FUN_10002bba((int)piVar3);
  local_10 = FUN_10002bcc((int)piVar3);
  FUN_10002a4e(piVar3);
  if (*param_1 < 0xd) {
    pcVar9 = (char *)puVar1[0x11];
  }
  else {
    pcVar9 = (char *)puVar1[0x12];
  }
  piVar3 = FUN_10003e00(puVar1[10],(char *)puVar1[0x13],puVar1[0x14],pcVar9);
  local_24 = piVar3;
  if (piVar3 == (int *)0x0) {
    free(local_10);
    FUN_1000f4e8((int)puVar1,0x3ea,puVar1[0x13]);
    return 0;
  }
  iVar2 = FUN_10004cb5((int)piVar3);
  if (iVar2 != 0) {
    pbVar4 = FUN_10002958(local_10,local_20,&local_20);
    free(local_10);
    local_10 = pbVar4;
  }
  local_8 = (char *)FUN_10004718((int)piVar3);
  iVar2 = mrbGetProperty((int)puVar1,&DAT_10018084,0);
  if (iVar2 == 0) {
    local_2c = (char **)0x0;
  }
  else {
    local_2c = (char **)puVar1[0x34];
  }
  iVar2 = FUN_1000f4e8((int)puVar1,100,local_8);
  if (iVar2 == 0) {
    while (puVar1[0x27] == 0) {
      piVar5 = FUN_10003f49(piVar3,local_2c,(int)(puVar1 + 0x3d));
      if (piVar5 == (int *)0xfffffff6) {
LAB_10009028:
        uVar11 = 0x3ea;
        pcVar9 = local_8;
        goto LAB_10009030;
      }
      if (piVar5 == (int *)0xfffffff8) break;
      if (piVar5 == (int *)0xfffffff9) {
        pcVar9 = (char *)0x0;
        uVar11 = 0x41b;
        goto LAB_10009030;
      }
      if (-5 < (int)piVar5) {
        if ((int)piVar5 < -2) goto LAB_10009028;
        if (piVar5 == (int *)0xfffffffe) {
          uVar11 = 0x3e9;
          pcVar9 = local_8;
        }
        else {
          if (piVar5 != (int *)0x197) goto LAB_10008bdf;
          iVar2 = 0x197;
LAB_10008dea:
          sprintf(local_d0,&DAT_100170c8,iVar2);
          pcVar9 = local_d0;
LAB_10009018:
          uVar11 = 1000;
        }
        goto LAB_10009030;
      }
LAB_10008bdf:
      iVar2 = FUN_10004cb5((int)piVar3);
      if (iVar2 != 0) {
        FUN_100043ba((int)piVar3,s_Content_Encoding_10018068,&DAT_1001807c);
      }
      FUN_100043ba((int)piVar3,s_Pragma_10018054,s_no_cache_1001805c);
      FUN_100043ba((int)piVar3,s_Content_type_10018030,s_application_marimba_10018040);
      sprintf(local_50,s_redirect__d_10018118,(int)*param_1);
      FUN_100043ba((int)piVar3,s_Request_type_10018014,local_50);
      iVar2 = FUN_1000f4e8((int)puVar1,0x65,local_8);
      if (((iVar2 != 0) || (puVar1[0x27] != 0)) ||
         (iVar2 = FUN_1000404b(piVar3,local_20,(int)local_2c), iVar2 == -8)) break;
      if (iVar2 != 0) {
        pcVar9 = s_POST_header_10017fa8;
        goto LAB_10009018;
      }
      pbVar4 = local_10;
      uVar8 = local_20;
      puVar6 = (uint *)FUN_10004749((int)piVar3);
      iVar2 = FUN_100085b2((int)puVar1,puVar6,(int)pbVar4,uVar8);
      if (iVar2 != 0) {
        puVar6 = (uint *)FUN_10004749((int)piVar3);
        uVar8 = FUN_1000c245(puVar6);
        if (uVar8 == 0) {
          pcVar9 = s_POST_data_10017f9c;
          goto LAB_10009018;
        }
        break;
      }
      iVar2 = FUN_1000f4e8((int)puVar1,0x66,local_8);
      if (((iVar2 != 0) || (puVar1[0x27] != 0)) ||
         (iVar2 = FUN_10004441((char *)piVar3,0,&local_34), iVar2 == -8)) break;
      if (iVar2 == -6) {
LAB_10009013:
        pcVar9 = s_bad_reply_10017f90;
        goto LAB_10009018;
      }
      if (iVar2 == -5) {
        uVar11 = 0x3ef;
        pcVar9 = local_8;
        goto LAB_10009030;
      }
      if (iVar2 == 0x191) goto LAB_10009013;
      if (iVar2 == 500) goto LAB_10009028;
      if (local_34 != -1) {
        iVar2 = FUN_1000468d((int)piVar3);
        if (iVar2 != 200) {
          if (iVar2 == 0x197) {
            mrbRemoveProperty((int)puVar1,s_http_password_10017f80);
          }
          goto LAB_10008dea;
        }
        iVar2 = FUN_1000f4e8((int)puVar1,0x67,local_8);
        if ((iVar2 == 0) && (puVar1[0x27] == 0)) {
          piVar3 = (int *)FUN_10004757((int)local_24);
          sVar7 = FUN_10003065(piVar3,&local_30);
          if ((int)sVar7 < 0) goto LAB_10008fa9;
          if (local_30 != -0x35014111) {
            sprintf(local_d0,&DAT_10017f7c,local_30);
            uVar11 = 0x3eb;
            pcVar9 = local_d0;
            goto LAB_10009030;
          }
          iVar2 = FUN_10003028(piVar3,&local_36);
          if (iVar2 < 0) goto LAB_10008fa9;
          sVar7 = FUN_10003065(piVar3,&local_1c);
          goto LAB_10008e94;
        }
        break;
      }
      iVar2 = FUN_1000f4e8((int)puVar1,100,local_8);
      if (iVar2 != 0) break;
    }
  }
LAB_10008d21:
  FUN_1000f4e8((int)puVar1,0x6f,local_8);
  puVar1[0x27] = 1;
LAB_10008d39:
  if (local_10 != (byte *)0x0) {
    free(local_10);
  }
  if (local_8 != (char *)0x0) {
    free(local_8);
  }
  if (local_14 != (undefined4 *)0x0) {
    free(local_14);
  }
  if (local_18 != (undefined4 *)0x0) {
    free(local_18);
  }
  FUN_10004301(local_24);
  return 0;
LAB_10008e94:
  if ((int)sVar7 < 0) goto LAB_10008fa9;
  if (local_1c < 1) {
    local_1c = local_1c + -1;
    iVar2 = FUN_10003015(piVar3,&param_2);
    if (-1 < iVar2) {
      if ((char)param_2 != '\a') goto LAB_10008d39;
      FUN_1000ca3d((int *)puVar1[0x15]);
      FUN_1000ca3d((int *)puVar1[0x16]);
      iVar2 = FUN_10003028(piVar3,&local_28);
      if ((-1 < iVar2) && (iVar2 = FUN_10003028(piVar3,&local_a), -1 < iVar2)) {
        if (local_a < 1) {
          free((void *)puVar1[0x13]);
          pcVar9 = _strdup((char *)puVar1[0xe]);
          puVar1[0x13] = pcVar9;
          puVar1[0x14] = puVar1[0xf];
          pcVar10 = free_exref;
          goto LAB_10008fec;
        }
        local_14 = malloc((int)local_a << 2);
        local_18 = malloc((int)local_a << 2);
        param_1 = (short *)0x0;
        if (local_a < 1) goto LAB_10008f7c;
        while( true ) {
          sVar7 = FUN_100031e5(piVar3,local_14 + (short)param_1);
          if (((int)sVar7 < 0) ||
             (sVar7 = FUN_10003065(piVar3,local_18 + (short)param_1), (int)sVar7 < 0)) break;
          param_1 = (short *)((int)param_1 + 1);
          if (local_a <= (short)param_1) {
LAB_10008f7c:
            FUN_10011575(puVar1,local_14,local_18,(int)local_a,(int)local_28);
            pcVar10 = free_exref;
            free(local_14);
            free(local_18);
LAB_10008fec:
            (*pcVar10)(local_8);
            (*pcVar10)(local_10);
            FUN_10004301(local_24);
            return 1;
          }
        }
      }
    }
    goto LAB_10008fa9;
  }
  local_1c = local_1c + -1;
  sVar7 = FUN_10003015(piVar3,&local_25);
  goto LAB_10008e94;
LAB_10008fa9:
  puVar6 = (uint *)FUN_10002fe7((int)piVar3);
  uVar8 = FUN_1000c245(puVar6);
  if (uVar8 == 0) {
    uVar11 = 0x3f4;
    pcVar9 = local_8;
LAB_10009030:
    FUN_1000f4e8((int)puVar1,uVar11,pcVar9);
    goto LAB_10008d39;
  }
  goto LAB_10008d21;
}



/* VA 1000903e */

undefined4 __cdecl
FUN_1000903e(short *param_1,byte *param_2,int *param_3,int *param_4,int *param_5,uint param_6)

{
  short *psVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  size_t sVar7;
  int *piVar8;
  undefined3 extraout_var;
  undefined4 *puVar9;
  uint uVar10;
  void *_Memory;
  code *pcVar11;
  byte *pbVar12;
  undefined4 uVar13;
  byte *pbVar14;
  undefined4 uVar15;
  char *pcVar16;
  char local_20c [128];
  char local_18c [128];
  char local_10c [24];
  char local_f4 [128];
  uint local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  char local_64 [4];
  uint local_60;
  uint uStack_5c;
  uint local_58;
  int iStack_54;
  byte *local_50;
  char **local_4c;
  int local_48;
  uint local_44;
  undefined1 local_3d;
  int local_3c;
  uint local_38;
  int local_34;
  undefined4 *local_30;
  byte *local_2c;
  char **local_28;
  int *local_24;
  byte *local_20;
  byte *local_1c;
  char local_15;
  int *local_14;
  char *local_10;
  int *local_c;
  int *local_8;

  local_30 = (undefined4 *)0x0;
  local_2c = (byte *)0x0;
  local_8 = (int *)0x0;
  local_1c = (byte *)0x0;
  local_24 = (int *)0x0;
  iVar3 = FUN_1000ca60((int)param_3);
  if (iVar3 == 0) {
    uVar15 = 0;
    uVar13 = 0x6c;
    pbVar12 = param_2;
LAB_100090e5:
    FUN_1000f4e8((int)pbVar12,uVar13,uVar15);
    return 0xffffffff;
  }
  piVar4 = FUN_100029c1();
  pbVar12 = param_2;
  psVar1 = param_1;
  FUN_10009e2f(param_1,(int)param_2,(int)piVar4,param_3,param_6);
  local_38 = FUN_10002bba((int)piVar4);
  local_20 = FUN_10002bcc((int)piVar4);
  FUN_10002a4e(piVar4);
  if (*psVar1 < 0xd) {
    pcVar16 = *(char **)(pbVar12 + 0x44);
  }
  else {
    pcVar16 = *(char **)(pbVar12 + 0x48);
  }
  piVar4 = FUN_10003e00(*(int *)(pbVar12 + 0x28),*(char **)(pbVar12 + 0x4c),*(int *)(pbVar12 + 0x50)
                        ,pcVar16);
  local_c = piVar4;
  if (piVar4 == (int *)0x0) {
    free(local_20);
    uVar15 = *(undefined4 *)(pbVar12 + 0x4c);
    uVar13 = 0x3ea;
    goto LAB_100090e5;
  }
  iVar3 = FUN_10004cb5((int)piVar4);
  pcVar11 = free_exref;
  if (iVar3 != 0) {
    param_2 = FUN_10002958(local_20,local_38,&local_38);
    free(local_20);
    local_20 = param_2;
  }
  local_10 = (char *)FUN_10004718((int)piVar4);
  iVar3 = mrbGetProperty((int)pbVar12,&DAT_10018084,0);
  if (iVar3 == 0) {
    local_28 = (char **)0x0;
  }
  else {
    local_28 = *(char ***)(pbVar12 + 0xd0);
  }
  iVar3 = FUN_1000f4e8((int)pbVar12,100,local_10);
  if (iVar3 == 0) {
    while (*(int *)(pbVar12 + 0x9c) == 0) {
      FUN_10004765((int)local_c);
      param_2 = (byte *)FUN_10003f49(local_c,local_28,(int)(pbVar12 + 0xf4));
      if (param_2 == (byte *)0xfffffff6) {
LAB_10009d02:
        if (*(int *)(pbVar12 + 0x5c) != 0) {
          iVar3 = FUN_100116ea((int)pbVar12,*(int *)(pbVar12 + 0x4c),*(char **)(pbVar12 + 0x50));
          if (iVar3 != 0) {
            FUN_10004301(local_c);
            free(local_10);
            uVar10 = param_6;
            goto LAB_10009d6a;
          }
          iVar3 = FUN_10008a6b(param_1,(undefined4 *)pbVar12);
          if (iVar3 != 0) {
            FUN_10004301(local_c);
            free(local_10);
            uVar10 = param_6;
            goto LAB_10009d6a;
          }
        }
        if (param_2 == (byte *)0xfffffffe) {
          uVar15 = 0x3e9;
          pcVar16 = local_10;
        }
        else {
LAB_10009608:
          uVar15 = 0x3ea;
          pcVar16 = local_10;
        }
        goto LAB_1000960d;
      }
      if (param_2 == (byte *)0xfffffff8) break;
      if (param_2 == (byte *)0xfffffff9) {
        pcVar16 = (char *)0x0;
        uVar15 = 0x41b;
        goto LAB_1000960d;
      }
      if (-5 < (int)param_2) {
        if ((int)param_2 < -1) goto LAB_10009d02;
        if (param_2 != (byte *)0x197) goto LAB_100091cf;
        pbVar14 = (byte *)0x197;
LAB_10009645:
        sprintf(local_f4,&DAT_100170c8,pbVar14);
        pcVar16 = local_f4;
LAB_10009cec:
        uVar15 = 1000;
        goto LAB_1000960d;
      }
LAB_100091cf:
      iVar3 = FUN_10004cb5((int)local_c);
      if (iVar3 != 0) {
        FUN_100043ba((int)local_c,s_Content_Encoding_10018068,&DAT_1001807c);
      }
      FUN_100043ba((int)local_c,s_Pragma_10018054,s_no_cache_1001805c);
      FUN_100043ba((int)local_c,s_Content_type_10018030,s_application_marimba_10018040);
      sprintf(local_10c,s_getfiles__d_10018128,3);
      FUN_100043ba((int)local_c,s_Request_type_10018014,local_10c);
      if (0 < *(int *)(pbVar12 + 0xd4)) {
        _ltoa(*(int *)(pbVar12 + 0xd4),local_64,10);
        FUN_100043ba((int)local_c,s_transfer_rate_10018004,local_64);
      }
      if (local_8 == (int *)0x0) {
        local_1c = (byte *)_strdup(s_Basic_10017ffc);
        if (*param_1 < 0xd) {
          pcVar16 = *(char **)(pbVar12 + 0x44);
        }
        else {
          pcVar16 = *(char **)(pbVar12 + 0x48);
        }
        local_24 = (int *)_strdup(pcVar16);
        if ((*(code **)(pbVar12 + 0xc0) != (code *)0x0) &&
           (iVar3 = (**(code **)(pbVar12 + 0xc0))
                              (*(undefined4 *)(pbVar12 + 0x80),local_1c,local_24,local_18c),
           iVar3 == 0)) {
          param_2 = (byte *)FUN_10001000(local_18c);
          sprintf(local_f4,s__s__s_10017ff4,local_1c,param_2);
          local_8 = (int *)_strdup(local_f4);
          free(param_2);
        }
        if (local_8 != (int *)0x0) goto LAB_10009310;
      }
      else {
LAB_10009310:
        FUN_100043ba((int)local_c,s_Authorization_10017fe4,(char *)local_8);
      }
      iVar3 = FUN_1000f4e8((int)pbVar12,0x65,local_10);
      if (((iVar3 != 0) || (*(int *)(pbVar12 + 0x9c) != 0)) ||
         (iVar3 = FUN_1000404b(local_c,local_38,(int)local_28), iVar3 == -8)) break;
      if (iVar3 != 0) {
        pcVar16 = s_POST_header_10017fa8;
        goto LAB_10009cec;
      }
      pbVar14 = local_20;
      uVar10 = local_38;
      puVar5 = (uint *)FUN_10004749((int)local_c);
      iVar3 = FUN_100085b2((int)pbVar12,puVar5,(int)pbVar14,uVar10);
      if (iVar3 != 0) {
        puVar5 = (uint *)FUN_10004749((int)local_c);
        uVar10 = FUN_1000c245(puVar5);
        if (uVar10 == 0) {
          pcVar16 = s_POST_data_10017f9c;
          goto LAB_10009cec;
        }
        break;
      }
      iVar3 = FUN_1000f4e8((int)pbVar12,0x66,local_10);
      if (((iVar3 != 0) || (*(int *)(pbVar12 + 0x9c) != 0)) ||
         (iVar3 = FUN_10004441((char *)local_c,0,&local_3c), iVar3 == -8)) break;
      if (iVar3 == -6) {
        pcVar16 = s_bad_reply_10017f90;
        goto LAB_10009cec;
      }
      if (iVar3 == -5) {
        uVar15 = 0x3ef;
        pcVar16 = local_10;
        goto LAB_1000960d;
      }
      if (local_3c == 0x191) {
        local_14 = (int *)FUN_100043fe((int)local_c,s_WWW_Authenticate_10017fd0);
        iVar3 = FUN_100083b4((int)local_14,' ',0);
        param_2 = (byte *)FUN_100053c2((int)local_14,0,iVar3);
        iVar3 = FUN_10008394((int)local_14,'\"',0);
        iVar6 = FUN_100083b4((int)local_14,'\"',0);
        local_14 = (int *)FUN_100053c2((int)local_14,iVar6 + 1,iVar3);
        iVar3 = _stricmp((char *)local_1c,(char *)param_2);
        if ((iVar3 == 0) && (iVar3 = _stricmp((char *)local_24,(char *)local_14), iVar3 == 0))
        goto LAB_10009511;
        sprintf(local_f4,s__s__s_10017fc8,param_2,local_14);
        free(local_1c);
        free(local_24);
        free(local_8);
        local_8 = (int *)0x0;
        local_1c = param_2;
        local_24 = local_14;
        if ((*(code **)(pbVar12 + 0xc0) != (code *)0x0) &&
           (iVar3 = (**(code **)(pbVar12 + 0xc0))
                              (*(undefined4 *)(pbVar12 + 0x80),param_2,local_14,local_20c),
           iVar3 == 0)) {
          local_14 = (int *)FUN_10001000(local_20c);
          sprintf(local_f4,s__s__s_10017ff4,param_2,local_14);
          local_8 = (int *)_strdup(local_f4);
          free(local_14);
        }
        if (local_8 == (int *)0x0) goto LAB_10009511;
        local_3c = -1;
      }
      else {
LAB_10009511:
        if (local_1c != (byte *)0x0) {
          free(local_1c);
          local_1c = (byte *)0x0;
        }
        if (local_24 != (int *)0x0) {
          free(local_24);
          local_24 = (int *)0x0;
        }
        if (local_8 != (int *)0x0) {
          free(local_8);
          local_8 = (int *)0x0;
        }
        if (local_3c == 500) goto LAB_10009608;
      }
      if (local_3c != -1) {
        param_2 = (byte *)FUN_1000468d((int)local_c);
        if (param_2 != (byte *)0xc8) {
          pbVar14 = param_2;
          if (param_2 == (byte *)0x197) {
            mrbRemoveProperty((int)pbVar12,s_http_password_10017f80);
            pbVar14 = param_2;
          }
          goto LAB_10009645;
        }
        iVar3 = FUN_1000f4e8((int)pbVar12,0x67,local_10);
        if ((iVar3 == 0) && (*(int *)(pbVar12 + 0x9c) == 0)) {
          local_8 = (int *)FUN_10004757((int)local_c);
          sVar7 = FUN_10003065(local_8,&local_48);
          piVar4 = local_8;
          if ((int)sVar7 < 0) goto LAB_10009c3b;
          if (local_48 != -0x35014111) {
            sprintf(local_f4,&DAT_10017f7c,local_48);
            uVar15 = 0x3eb;
            pcVar16 = local_f4;
            goto LAB_1000960d;
          }
          iVar3 = FUN_10003028(local_8,(undefined2 *)&local_44);
          piVar4 = local_8;
          if (iVar3 < 0) goto LAB_10009c3b;
          sVar7 = FUN_10003065(local_8,&local_34);
          goto LAB_100096f4;
        }
        break;
      }
      iVar3 = FUN_1000f4e8((int)pbVar12,100,local_10);
      if (iVar3 != 0) break;
    }
  }
  goto LAB_1000956e;
LAB_100096f4:
  piVar4 = local_8;
  if (-1 < (int)sVar7) {
    if (0 < local_34) goto code_r0x10009708;
    local_34 = local_34 + -1;
    iVar3 = FUN_10003015(local_8,&local_15);
    piVar4 = local_8;
    if (iVar3 < 0) goto LAB_10009c3b;
    iVar3 = (int)local_15;
    switch(iVar3) {
    case 1:
      iVar3 = FUN_10003028(local_8,(undefined2 *)&param_3);
      piVar4 = local_8;
      if (-1 < iVar3) {
        sprintf(local_f4,&DAT_100170c8,(int)(short)param_3);
        pcVar16 = local_f4;
        uVar15 = 0x3ec;
        goto LAB_1000960d;
      }
      goto LAB_10009c3b;
    case 2:
    case 3:
    case 5:
      sprintf(local_f4,&DAT_10018124,iVar3);
      pcVar16 = local_f4;
      uVar15 = 0x3f5;
      goto LAB_1000960d;
    case 4:
      if (*(int *)(pbVar12 + 0x5c) == 0) {
        pcVar16 = *(char **)(pbVar12 + 0x40);
        uVar15 = 0x3ee;
        goto LAB_1000960d;
      }
      break;
    case 6:
      iVar3 = FUN_10003028(local_8,(undefined2 *)&param_2);
      piVar4 = local_8;
      if (iVar3 < 0) goto LAB_10009c3b;
      if (*(int *)(pbVar12 + 0x5c) == 0) {
        sprintf(local_f4,&DAT_100170c8,(int)(short)param_2);
        pcVar16 = local_f4;
        uVar15 = 0x3ed;
        goto LAB_1000960d;
      }
      break;
    case 7:
      iVar3 = FUN_10003028(local_8,(undefined2 *)&local_1c);
      if ((-1 < iVar3) && (iVar3 = FUN_10003028(piVar4,(undefined2 *)&param_2), -1 < iVar3)) {
        local_30 = malloc((int)(short)param_2 << 2);
        local_2c = malloc((int)(short)param_2 << 2);
        local_14 = (int *)0x0;
        if (0 < (short)param_2) goto LAB_10009ae2;
        goto LAB_10009b26;
      }
      goto LAB_10009c3b;
    default:
      sprintf(local_f4,&DAT_10018124,iVar3);
      uVar15 = 0x3f0;
      pcVar16 = local_f4;
      goto LAB_1000960d;
    case 9:
      goto switchD_1000973c_caseD_9;
    case 10:
      sVar7 = FUN_10003065(local_8,&param_1);
      piVar4 = local_8;
      if ((-1 < (int)sVar7) &&
         (sVar7 = FUN_100031e5(local_8,(int *)&param_3), piVar4 = local_8, -1 < (int)sVar7)) {
        sprintf(local_f4,s__d___s__10017f60,param_1,param_3);
        FUN_1000f4e8((int)pbVar12,0x3f1,local_f4);
        free(param_3);
        goto LAB_10009593;
      }
      goto LAB_10009c3b;
    case 0xb:
      if (*(int *)(pbVar12 + 0xa0) == 0) {
switchD_1000973c_caseD_9:
        sVar7 = FUN_10003065(local_8,&local_4c);
        if ((-1 < (int)sVar7) && (sVar7 = FUN_10003065(piVar4,&param_6), -1 < (int)sVar7)) {
          iVar3 = FUN_100024b0(*(char **)(pbVar12 + 0x20));
          if (iVar3 == 0) {
            if ((int)param_6 < 0) {
              param_6 = 0;
              param_2 = (byte *)FUN_1000c9f6();
              while (iVar3 = FUN_1000c9f9(param_3,(int *)&param_2), iVar3 != 0) {
                param_6 = param_6 + (*(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x20));
              }
            }
            iVar3 = FUN_100107af((int)pbVar12,param_6);
            piVar4 = local_8;
            if (iVar3 != 0) goto LAB_1000956e;
            do {
              local_28 = (char **)((int)local_4c + -1);
              local_8 = piVar4;
              if ((int)local_4c < 1) {
                FUN_1001089b((int)pbVar12);
                (*pcVar11)(local_10);
                (*pcVar11)(local_20);
                FUN_10004301(local_c);
                iVar3 = FUN_1000ca60((int)param_3);
                if (iVar3 < 1) {
                  return 0;
                }
                uVar10 = 0;
                goto LAB_10009d6a;
              }
              local_14 = (int *)0x0;
              iVar3 = FUN_10003015(piVar4,&local_15);
              if ((iVar3 < 0) || (iVar3 = FUN_10003028(piVar4,(undefined2 *)&local_44), iVar3 < 0))
              {
LAB_10009de3:
                puVar5 = (uint *)FUN_10002fe7((int)piVar4);
                uVar10 = FUN_1000c245(puVar5);
                pcVar11 = free_exref;
                if (uVar10 != 0) goto LAB_1000956e;
                goto LAB_10009c50;
              }
              local_1c = (byte *)(local_44 & 1);
              sVar7 = FUN_100030b4(piVar4,&local_60);
              if (((int)sVar7 < 0) || (sVar7 = FUN_100030b4(piVar4,&local_58), (int)sVar7 < 0))
              goto LAB_10009de3;
              iVar3 = FUN_100011bc(local_60,uStack_5c,local_58,iStack_54);
              if (iVar3 == 0) {
                FUN_1000f4e8((int)pbVar12,0x3ef,local_10);
LAB_10009da2:
                pbVar12[0x90] = 0;
                pbVar12[0x91] = 0;
                pbVar12[0x92] = 0;
                pbVar12[0x93] = 0;
                pcVar11 = free_exref;
                goto LAB_10009593;
              }
              piVar8 = (int *)FUN_1000378d(param_4,&local_60);
              local_24 = piVar8;
              if (piVar8 == (int *)0x0) {
                _Memory = FUN_10001203(local_60,uStack_5c,CONCAT44(iStack_54,local_58));
                FUN_1000f4e8((int)pbVar12,0x3f9,_Memory);
                free(_Memory);
                pcVar11 = free_exref;
                goto LAB_10009593;
              }
              if (local_15 != '\x01') {
                if ((local_15 != '\x02') ||
                   ((sVar7 = FUN_100030b4(local_8,&local_74), piVar4 = local_8, -1 < (int)sVar7 &&
                    (sVar7 = FUN_100030b4(local_8,&local_6c), piVar4 = local_8, -1 < (int)sVar7))))
                goto LAB_10009952;
                goto LAB_10009de3;
              }
              sVar7 = FUN_10003065(local_8,&local_14);
              piVar4 = local_8;
              if ((int)sVar7 < 0) goto LAB_10009de3;
              local_74 = 0;
              local_70 = 0;
              local_6c = 0;
              local_68 = 0;
LAB_10009952:
              sVar7 = FUN_10003065(local_8,&param_2);
              piVar4 = local_8;
              if ((int)sVar7 < 0) goto LAB_10009de3;
              local_50 = param_2;
              if (local_1c != (byte *)0x0) {
                FUN_100032e9((int)local_8,param_2);
                param_2 = (byte *)piVar8[6];
              }
              iVar3 = FUN_1000f4e8((int)pbVar12,0x68,*piVar8);
              if ((iVar3 != 0) || (*(int *)(pbVar12 + 0x9c) != 0)) goto LAB_1000956e;
              cVar2 = FUN_10009fd2((undefined4 *)pbVar12,local_8,local_24,(byte)local_44,local_60,
                                   uStack_5c,local_58,iStack_54,local_74,local_70,local_6c,local_68,
                                   (uint)local_14,(size_t)param_2,param_5);
              iVar3 = CONCAT31(extraout_var,cVar2);
              if (iVar3 == 0) {
                *(byte **)(pbVar12 + 0xac) = local_50 + *(int *)(pbVar12 + 0xac);
                *(int *)(pbVar12 + 0xa8) = *(int *)(pbVar12 + 0xa8) + local_24[6];
                puVar9 = (undefined4 *)FUN_1000c98a(param_3,local_24);
                FUN_1000840b(puVar9);
                puVar9 = (undefined4 *)FUN_1000399d(param_4,&local_60);
                FUN_1000840b(puVar9);
              }
              else {
                if (iVar3 == 1) goto LAB_10009da2;
                if (iVar3 == 3) goto LAB_1000956e;
              }
              pcVar11 = free_exref;
              piVar4 = local_8;
              local_4c = local_28;
              if (local_1c != (byte *)0x0) {
                FUN_1000331b((int)local_8);
                pcVar11 = free_exref;
                piVar4 = local_8;
                local_4c = local_28;
              }
            } while( true );
          }
          pcVar16 = *(char **)(pbVar12 + 0x20);
          uVar15 = 0x3fe;
          goto LAB_1000960d;
        }
      }
      else {
        sVar7 = FUN_10003065(local_8,&param_3);
        piVar4 = local_8;
        if ((-1 < (int)sVar7) &&
           (sVar7 = FUN_10003065(local_8,(undefined4 *)(pbVar12 + 0xa4)), piVar4 = local_8,
           -1 < (int)sVar7)) {
          sprintf(local_f4,s__d__d_10017f74,*(undefined4 *)(pbVar12 + 0xa4),param_3);
          FUN_1000f4e8((int)pbVar12,0x6d,local_f4);
          free(local_10);
          free(local_20);
          FUN_10004301(local_c);
          return 0;
        }
      }
      goto LAB_10009c3b;
    }
    FUN_100116ea((int)pbVar12,*(int *)(pbVar12 + 0x4c),*(char **)(pbVar12 + 0x50));
    free(local_10);
    pbVar14 = local_20;
    goto LAB_10009bf7;
  }
  goto LAB_10009c3b;
code_r0x10009708:
  local_34 = local_34 + -1;
  sVar7 = FUN_10003015(local_8,&local_3d);
  goto LAB_100096f4;
LAB_10009ae2:
  iVar3 = (int)(short)local_14;
  sVar7 = FUN_100031e5(local_8,local_30 + iVar3);
  piVar4 = local_8;
  if (((int)sVar7 < 0) ||
     (sVar7 = FUN_10003065(local_8,(undefined4 *)(local_2c + iVar3 * 4)), piVar4 = local_8,
     (int)sVar7 < 0)) goto LAB_10009c3b;
  local_14 = (int *)((int)local_14 + 1);
  if ((short)param_2 <= (short)local_14) {
LAB_10009b26:
    FUN_10011575((undefined4 *)pbVar12,local_30,(undefined4 *)local_2c,(int)(short)param_2,
                 (int)(short)local_1c);
    free(local_10);
    free(local_20);
    free(local_30);
    pbVar14 = local_2c;
LAB_10009bf7:
    free(pbVar14);
    FUN_10004301(local_c);
    uVar10 = param_6;
LAB_10009d6a:
    uVar15 = FUN_1000903e(param_1,pbVar12,param_3,param_4,param_5,uVar10);
    return uVar15;
  }
  goto LAB_10009ae2;
LAB_10009c3b:
  puVar5 = (uint *)FUN_10002fe7((int)piVar4);
  uVar10 = FUN_1000c245(puVar5);
  if (uVar10 == 0) {
LAB_10009c50:
    uVar15 = 0x3f4;
    pcVar16 = local_10;
LAB_1000960d:
    FUN_1000f4e8((int)pbVar12,uVar15,pcVar16);
    goto LAB_10009593;
  }
LAB_1000956e:
  FUN_1000f4e8((int)pbVar12,0x6f,local_10);
  pbVar12[0x90] = 0;
  pbVar12[0x91] = 0;
  pbVar12[0x92] = 0;
  pbVar12[0x93] = 0;
  pbVar12[0x9c] = 1;
  pbVar12[0x9d] = 0;
  pbVar12[0x9e] = 0;
  pbVar12[0x9f] = 0;
  pcVar11 = free_exref;
LAB_10009593:
  if (local_20 != (byte *)0x0) {
    (*pcVar11)(local_20);
  }
  if (local_10 != (char *)0x0) {
    (*pcVar11)(local_10);
  }
  if (local_30 != (undefined4 *)0x0) {
    (*pcVar11)(local_30);
  }
  if (local_2c != (byte *)0x0) {
    (*pcVar11)(local_2c);
  }
  FUN_10004301(local_c);
  return 0xffffffff;
}



/* VA 10009e2f */

undefined4 __cdecl FUN_10009e2f(short *param_1,int param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;

  iVar1 = param_3;
  FUN_10002c45(param_3,0xcafebeef);
  FUN_10002c21(iVar1,CONCAT22(extraout_var,*param_1));
  FUN_10002c79(iVar1,*(undefined4 *)(param_2 + 0x70),*(int *)(param_2 + 0x74));
  FUN_10002d05(iVar1,*(char **)(param_2 + 0x38));
  FUN_10002c45(iVar1,*(undefined4 *)(param_2 + 0x3c));
  FUN_10002c21(iVar1,(-(uint)(*(int *)(param_2 + 0xa0) != 0) & 4) + 3);
  FUN_10002c45(iVar1,0);
  FUN_10002d3c(iVar1);
  if (*param_1 < 0xd) {
    pcVar4 = *(char **)(param_2 + 0x44);
  }
  else {
    pcVar4 = *(char **)(param_2 + 0x48);
  }
  FUN_10002d05(iVar1,pcVar4);
  uVar2 = FUN_1000ca60((int)param_4);
  FUN_10002c45(iVar1,uVar2);
  param_3 = FUN_1000c9f6();
  iVar3 = FUN_1000c9f9(param_4,&param_3);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    if (param_5 == 0) {
      FUN_10002d3c(iVar1);
      FUN_10002c79(iVar1,*(undefined4 *)(iVar3 + 8),*(int *)(iVar3 + 0xc));
      FUN_10002c79(iVar1,*(undefined4 *)(iVar3 + 0x10),*(int *)(iVar3 + 0x14));
      uVar2 = 0;
LAB_10009fae:
      FUN_10002c45(iVar1,uVar2);
    }
    else {
      if ((*(int *)(iVar3 + 0x20) != 0) || (*(int *)(iVar3 + 0x1c) == 0)) {
        FUN_10002d3c(iVar1);
        FUN_10002c79(iVar1,*(undefined4 *)(iVar3 + 8),*(int *)(iVar3 + 0xc));
        FUN_10002c79(iVar1,*(undefined4 *)(iVar3 + 0x10),*(int *)(iVar3 + 0x14));
        uVar2 = *(undefined4 *)(iVar3 + 0x20);
        goto LAB_10009fae;
      }
      FUN_10002d3c(iVar1);
      FUN_10002c79(iVar1,*(undefined4 *)(iVar3 + 8),*(int *)(iVar3 + 0xc));
      FUN_10002c79(iVar1,*(undefined4 *)(iVar3 + 0x10),*(int *)(iVar3 + 0x14));
      FUN_10002c79(iVar1,*(undefined4 *)(*(int *)(iVar3 + 0x1c) + 0x10),
                   *(int *)(*(int *)(iVar3 + 0x1c) + 0x14));
      FUN_10002c79(iVar1,*(undefined4 *)(*(int *)(iVar3 + 0x1c) + 0x18),
                   *(int *)(*(int *)(iVar3 + 0x1c) + 0x1c));
    }
    iVar3 = FUN_1000c9f9(param_4,&param_3);
  } while( true );
}



/* VA 10009fd2 */

char __cdecl
FUN_10009fd2(undefined4 *param_1,int *param_2,int *param_3,byte param_4,uint param_5,uint param_6,
            uint param_7,int param_8,uint param_9,uint param_10,int param_11,int param_12,
            uint param_13,size_t param_14,int *param_15)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  void *_Memory;
  char *pcVar7;
  int *piVar8;
  uint *puVar9;
  uint uVar10;
  size_t sVar11;
  int iVar12;
  undefined4 unaff_ESI;
  undefined1 local_1130 [4096];
  char local_130 [252];
  undefined4 uStackY_34;
  undefined4 uVar13;
  int iVar14;

  FUN_10014d20();
  pcVar2 = (char *)FUN_1000f916((int)param_1,param_5,param_6,param_7,param_8);
  strcpy(local_130,pcVar2);
  free(pcVar2);
  iVar3 = FUN_100033a1(local_130);
  if (iVar3 < 0) {
    pcVar2 = local_130;
    uVar13 = 0x3f3;
LAB_1000a2cb:
    FUN_1000f4e8((int)param_1,uVar13,pcVar2);
LAB_1000a2d3:
    cVar1 = '\x01';
  }
  else {
    piVar4 = (int *)FUN_1000bfed(iVar3);
    uVar10 = param_13;
    if ((int)param_13 < 1) {
      puVar6 = FUN_1000616f(piVar4);
LAB_1000a0af:
      iVar3 = FUN_100011bc(param_9,param_10,param_11,param_12);
      if (iVar3 != 0) {
        param_15 = (int *)FUN_1000378d(param_15,&param_9);
        if (param_15 != (int *)0x0) {
          pcVar2 = (char *)FUN_1000f7fd(param_1,param_15);
          iVar3 = FUN_10003374(pcVar2);
          free(pcVar2);
          if (iVar3 < 0) {
            pcVar2 = (char *)FUN_1000583e(param_15);
            pcVar7 = (char *)mrbGetLocation((int)param_1,pcVar2);
            free(pcVar2);
            if ((pcVar7 == (char *)0x0) || (iVar3 = FUN_10003374(pcVar7), iVar3 < 0)) {
              FUN_100061dc(puVar6);
              goto LAB_1000a16d;
            }
          }
          piVar4 = (int *)FUN_1000bfed(iVar3);
          piVar8 = FUN_10002d50(piVar4);
          iVar3 = FUN_100020f2(piVar8,param_2,puVar6);
          if (iVar3 != 0) {
            FUN_10002fef(piVar8);
            FUN_1000c00c(piVar4);
            FUN_100061dc(puVar6);
            puVar9 = (uint *)FUN_10002fe7((int)param_2);
            uVar10 = FUN_1000c245(puVar9);
            return (uVar10 != 0) + '\x02';
          }
          if ((*(byte *)(param_1 + 0x23) & 0x40) != 0) {
            sprintf(&stack0xffffffe4,&DAT_100170c8);
            iVar3 = FUN_1000f4e8((int)param_1,0x139c,&stack0xffffffe4);
            if (iVar3 != 0) goto LAB_1000a2da;
          }
          iVar3 = FUN_1001081a((int)param_1,param_3[6]);
          if ((iVar3 != 0) || (param_1[0x27] != 0)) {
LAB_1000a2da:
            FUN_10002fef(piVar8);
            FUN_1000c00c(piVar4);
LAB_1000a463:
            FUN_100061dc(puVar6);
            return '\x03';
          }
          FUN_10002fef(piVar8);
          FUN_1000c00c(piVar4);
          goto LAB_1000a241;
        }
        _Memory = FUN_10001203(param_9,param_10,CONCAT44(param_12,param_11));
        FUN_1000f4e8((int)param_1,0x3fa,_Memory);
        free(_Memory);
        FUN_100061dc(puVar6);
        goto LAB_1000a2d3;
      }
      param_15 = (int *)0x0;
      for (; 0 < (int)param_14; param_14 = param_14 - sVar11) {
        sVar11 = 0x1000;
        if ((int)param_14 < 0x1000) {
          sVar11 = param_14;
        }
        sVar11 = FUN_10002d96(param_2,local_1130,sVar11);
        if ((int)sVar11 < 0) {
          FUN_100061dc(puVar6);
          puVar9 = (uint *)FUN_10002fe7((int)param_2);
          uVar10 = FUN_1000c1d1(puVar9);
          if (uVar10 == 1) {
            pcVar2 = (char *)*param_3;
            uVar13 = 0x3ef;
          }
          else {
            puVar9 = (uint *)FUN_10002fe7((int)param_2);
            uVar10 = FUN_1000c245(puVar9);
            if (uVar10 != 0) {
              return '\x03';
            }
            pcVar2 = (char *)*param_3;
            uVar13 = 0x3f7;
          }
          goto LAB_1000a2cb;
        }
        for (iVar3 = FUN_1000627c(puVar6,local_1130,sVar11); iVar3 < (int)sVar11;
            iVar3 = iVar3 + iVar12) {
          if (iVar3 < 0) {
            FUN_100061dc(puVar6);
            piVar4 = _errno();
            pcVar2 = local_130;
            if (*piVar4 == 0x1c) {
              uVar13 = 0x3f2;
            }
            else {
              uVar13 = 0x3f8;
            }
            goto LAB_1000a2cb;
          }
          iVar12 = FUN_1000627c(puVar6,local_1130 + iVar3,sVar11 - iVar3);
        }
        if ((*(byte *)(param_1 + 0x23) & 0x40) != 0) {
          if ((param_4 & 1) == 0) {
            param_15 = (int *)((int)param_15 + sVar11);
          }
          else {
            FUN_10003359((int)param_2);
          }
          sprintf(&stack0xffffffe4,&DAT_100170c8);
          iVar3 = FUN_1000f4e8((int)param_1,0x139c,&stack0xffffffe4);
          if (iVar3 != 0) goto LAB_1000a463;
        }
        iVar3 = FUN_1001081a((int)param_1,sVar11);
        if ((iVar3 != 0) || (param_1[0x27] != 0)) goto LAB_1000a463;
      }
LAB_1000a241:
      piVar4 = (int *)FUN_10006245((undefined4 *)&stack0xffffffd4,(int)puVar6);
      iVar3 = *piVar4;
      iVar12 = piVar4[3];
      iVar14 = 0x1000a260;
      FUN_100061dc(puVar6);
      uStackY_34 = 0x1000a27e;
      iVar3 = FUN_100011d7(param_5,param_6,param_7,param_8,iVar3,iVar14,(int)puVar6,iVar12);
      if (iVar3 != 0) {
        return '\0';
      }
      FUN_1000341d(local_130);
      if ((param_13 == 0) && (iVar3 = FUN_100011bc(param_9,param_10,param_11,param_12), iVar3 == 0))
      {
        pcVar2 = local_130;
        uVar13 = 0x3f6;
        goto LAB_1000a2cb;
      }
    }
    else {
      iVar3 = FUN_1000a470(local_130,param_13,(undefined4 *)&stack0xfffffff4);
      if (iVar3 == 0) {
        uVar5 = FUN_1000c120(piVar4,uVar10);
        if ((uVar5 != uVar10) ||
           (puVar6 = FUN_100061a4(piVar4,unaff_ESI,uVar10), puVar6 == (undefined4 *)0x0)) {
          FUN_1000c00c(piVar4);
          pcVar2 = local_130;
          uVar13 = 0x3f3;
          goto LAB_1000a2cb;
        }
        goto LAB_1000a0af;
      }
      FUN_1000c00c(piVar4);
    }
LAB_1000a16d:
    cVar1 = '\x02';
  }
  return cVar1;
}



/* VA 1000a470 */

undefined4 __cdecl FUN_1000a470(char *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  char local_1004 [4072];
  undefined4 uStackY_1c;

  FUN_10014d20();
  iVar1 = FUN_10003374(param_1);
  if (iVar1 < 0) {
LAB_1000a4d2:
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_1000bfed(iVar1);
    puVar3 = FUN_1000616f(uVar2);
    for (; 0 < (int)param_2; param_2 = param_2 - uVar4) {
      uVar4 = param_2;
      if (0xfff < (int)param_2) {
        uVar4 = 0x1000;
      }
      uStackY_1c = 0x1000a4c0;
      uVar4 = FUN_1000636e(puVar3,local_1004,uVar4);
      if ((int)uVar4 < 0) {
        FUN_100061dc(puVar3);
        goto LAB_1000a4d2;
      }
    }
    uVar2 = FUN_10006213((int)puVar3);
    *param_3 = uVar2;
    FUN_100061dc(puVar3);
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 1000a4f0 */

undefined4 __cdecl
FUN_1000a4f0(int param_1,int *param_2,size_t param_3,uint param_4,uint param_5,uint param_6,
            undefined4 param_7,char *param_8)

{
  char *_Memory;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  size_t sVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int *piVar8;
  char local_1018 [4084];
  undefined4 uStackY_24;

  FUN_10014d20();
  uStackY_24 = 0x1000a518;
  _Memory = (char *)FUN_1000f916(param_1,param_4,param_5,param_6,param_7);
  iVar1 = FUN_10003389(_Memory);
  if (iVar1 < 0) {
    FUN_1000f4e8(param_1,0x3f3,_Memory);
    free(_Memory);
    uVar2 = 0xffffffff;
  }
  else {
    piVar3 = (int *)FUN_1000bfed(iVar1);
    for (; 0 < (int)param_3; param_3 = param_3 - iVar1) {
      sVar4 = 0x1000;
      if ((int)param_3 < 0x1000) {
        sVar4 = param_3;
      }
      sVar4 = FUN_10002d96(param_2,local_1018,sVar4);
      if ((int)sVar4 < 0) {
        puVar6 = (uint *)FUN_10002fe7((int)param_2);
        uVar7 = FUN_1000c1d1(puVar6);
        if (uVar7 == 1) {
          uVar2 = 0x3ef;
        }
        else {
          puVar6 = (uint *)FUN_10002fe7((int)param_2);
          uVar7 = FUN_1000c245(puVar6);
          if (uVar7 == 0) {
            uVar2 = 0x3f7;
          }
          else {
LAB_1000a64d:
            uVar2 = 0x6f;
            param_8 = (char *)0x0;
          }
        }
LAB_1000a651:
        FUN_1000f4e8(param_1,uVar2,param_8);
LAB_1000a65a:
        uVar2 = 0xffffffff;
        goto LAB_1000a661;
      }
      iVar1 = FUN_1000c0c5(piVar3,local_1018,sVar4);
      if (iVar1 < 0) {
        piVar8 = _errno();
        param_8 = _Memory;
        if (*piVar8 == 0x1c) {
          uVar2 = 0x3f2;
        }
        else {
          uVar2 = 0x3f8;
        }
        goto LAB_1000a651;
      }
      if ((*(byte *)(param_1 + 0x8c) & 0x40) != 0) {
        sprintf(&stack0xffffffe8,&DAT_100170c8);
        iVar5 = FUN_1000f4e8(param_1,0x139c,&stack0xffffffe8);
        if (iVar5 == 0) goto LAB_1000a5dd;
        goto LAB_1000a65a;
      }
LAB_1000a5dd:
      iVar5 = FUN_1001081a(param_1,iVar1);
      if (iVar5 != 0) goto LAB_1000a64d;
    }
    uVar2 = 0;
LAB_1000a661:
    free(_Memory);
    FUN_1000c00c(piVar3);
  }
  return uVar2;
}



/* VA 1000a67b */

undefined2 * __cdecl FUN_1000a67b(int param_1)

{
  undefined2 *puVar1;

  if ((param_1 == 0xd) || (param_1 == 0xc)) {
    puVar1 = malloc(0x14);
    if (puVar1 != (undefined2 *)0x0) {
      if (param_1 == 0xc) {
        *puVar1 = 0xc;
        *(code **)(puVar1 + 2) = FUN_1000ab88;
        *(undefined1 **)(puVar1 + 4) = &LAB_1000a6eb;
        *(code **)(puVar1 + 6) = FUN_1000a7d7;
        *(code **)(puVar1 + 8) = FUN_1000ac43;
      }
      else if (param_1 == 0xd) {
        *puVar1 = 0xd;
        *(code **)(puVar1 + 2) = FUN_1000abd7;
        *(undefined1 **)(puVar1 + 4) = &LAB_1000a755;
        *(code **)(puVar1 + 6) = FUN_1000a9a6;
        *(code **)(puVar1 + 8) = FUN_1000adac;
        return puVar1;
      }
      return puVar1;
    }
  }
  return (undefined2 *)0x0;
}



/* VA 1000a7d7 */

undefined4 __cdecl FUN_1000a7d7(undefined2 *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 extraout_var;
  undefined4 uVar4;
  int iVar5;

  iVar1 = param_3;
  FUN_10002c45(param_3,0xcafebeef);
  FUN_10002c21(iVar1,CONCAT22((short)((uint)param_1 >> 0x10),*param_1));
  FUN_10002c79(iVar1,*(undefined4 *)(param_2 + 0x70),*(int *)(param_2 + 0x74));
  FUN_10002d05(iVar1,*(char **)(param_2 + 0x38));
  FUN_10002c45(iVar1,*(undefined4 *)(param_2 + 0x3c));
  FUN_10002c21(iVar1,3);
  FUN_1000876e(param_2,iVar1);
  iVar5 = 0;
  FUN_10002d3c(iVar1);
  FUN_10002d05(iVar1,&DAT_10018c88);
  FUN_10002d05(iVar1,&DAT_10018d40);
  FUN_10002d05(iVar1,&DAT_10018ca8);
  FUN_10002c21(iVar1,-DAT_10018cb8);
  FUN_10002d05(iVar1,*(char **)(param_2 + 0x44));
  if ((*(int *)(param_2 + 0x88) == 0) && (iVar2 = FUN_1000ca60(*(int *)(param_2 + 100)), iVar2 != 0)
     ) {
    param_3 = FUN_1000c9f6();
    while (iVar2 = FUN_1000c9f9(*(int **)(param_2 + 100),&param_3), iVar2 != 0) {
      iVar5 = iVar5 + 10 + (int)*(short *)(iVar2 + 8);
    }
    FUN_10002c45(iVar1,iVar5);
    param_3 = FUN_1000c9f6();
    while (puVar3 = (undefined4 *)FUN_1000c9f9(*(int **)(param_2 + 100),&param_3),
          puVar3 != (undefined4 *)0x0) {
      FUN_10002c79(iVar1,*puVar3,puVar3[1]);
      FUN_10002c21(iVar1,CONCAT22(extraout_var,*(undefined2 *)(puVar3 + 2)));
      FUN_10002ae4(iVar1,puVar3[3],(int)*(short *)(puVar3 + 2));
    }
  }
  else {
    FUN_10002c45(iVar1,0);
  }
  if (*(int *)(param_2 + 0x68) == 0) {
    FUN_10002c45(iVar1,0);
  }
  else {
    FUN_10002c45(iVar1,*(undefined4 *)(param_2 + 0x6c));
    FUN_10002ae4(iVar1,*(int *)(param_2 + 0x68),*(size_t *)(param_2 + 0x6c));
  }
  if (param_4 == 0) {
    FUN_10002c21(iVar1,0);
    uVar4 = FUN_10008955((int)param_1,iVar1,*(int **)(param_2 + 0x30));
  }
  else {
    FUN_10002c79(iVar1,*(undefined4 *)(*(int *)(param_2 + 0x30) + 0x10),
                 *(int *)(*(int *)(param_2 + 0x30) + 0x14));
    FUN_10002c79(iVar1,*(undefined4 *)(*(int *)(param_2 + 0x30) + 0x18),
                 *(int *)(*(int *)(param_2 + 0x30) + 0x1c));
    uVar4 = 0;
  }
  return uVar4;
}



/* VA 1000a9a6 */

undefined4 __cdecl FUN_1000a9a6(undefined2 *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 extraout_var;
  int iVar4;

  iVar1 = param_3;
  FUN_10002c45(param_3,0xcafebeef);
  FUN_10002c21(iVar1,CONCAT22((short)((uint)param_1 >> 0x10),*param_1));
  FUN_10002c79(iVar1,*(undefined4 *)(param_2 + 0x70),*(int *)(param_2 + 0x74));
  FUN_10002d05(iVar1,*(char **)(param_2 + 0x38));
  FUN_10002c45(iVar1,*(undefined4 *)(param_2 + 0x3c));
  FUN_10002c21(iVar1,3);
  FUN_1000876e(param_2,iVar1);
  iVar4 = 0;
  FUN_10002d3c(iVar1);
  FUN_10002d05(iVar1,&DAT_10018c88);
  FUN_10002d05(iVar1,&DAT_10018d40);
  FUN_10002d05(iVar1,&DAT_10018ca8);
  iVar2 = FUN_10002d05(iVar1,&DAT_10018cc0);
  FUN_10002c21(iVar1,CONCAT22((short)((uint)iVar2 >> 0x10),(undefined2)DAT_10018cb8));
  FUN_10002d05(iVar1,*(char **)(param_2 + 0x48));
  if ((*(int *)(param_2 + 0x88) == 0) && (iVar2 = FUN_1000ca60(*(int *)(param_2 + 100)), iVar2 != 0)
     ) {
    param_3 = FUN_1000c9f6();
    while (iVar2 = FUN_1000c9f9(*(int **)(param_2 + 100),&param_3), iVar2 != 0) {
      iVar4 = iVar4 + 10 + (int)*(short *)(iVar2 + 8);
    }
    FUN_10002c45(iVar1,iVar4);
    param_3 = FUN_1000c9f6();
    while (puVar3 = (undefined4 *)FUN_1000c9f9(*(int **)(param_2 + 100),&param_3),
          puVar3 != (undefined4 *)0x0) {
      FUN_10002c79(iVar1,*puVar3,puVar3[1]);
      FUN_10002c21(iVar1,CONCAT22(extraout_var,*(undefined2 *)(puVar3 + 2)));
      FUN_10002ae4(iVar1,puVar3[3],(int)*(short *)(puVar3 + 2));
    }
  }
  else {
    FUN_10002c45(iVar1,0);
  }
  if (*(int *)(param_2 + 0x68) == 0) {
    FUN_10002c45(iVar1,0);
  }
  else {
    FUN_10002c45(iVar1,*(undefined4 *)(param_2 + 0x6c));
    FUN_10002ae4(iVar1,*(int *)(param_2 + 0x68),*(size_t *)(param_2 + 0x6c));
  }
  if (param_4 == 0) {
    FUN_10002c21(iVar1,0);
    iVar4 = FUN_10008955((int)param_1,iVar1,*(int **)(param_2 + 0x30));
    if (iVar4 != 0) {
      return 0xffffffff;
    }
  }
  else {
    FUN_10002c79(iVar1,*(undefined4 *)(*(int *)(param_2 + 0x30) + 0x10),
                 *(int *)(*(int *)(param_2 + 0x30) + 0x14));
    FUN_10002c79(iVar1,*(undefined4 *)(*(int *)(param_2 + 0x30) + 0x18),
                 *(int *)(*(int *)(param_2 + 0x30) + 0x1c));
  }
  return 0;
}



/* VA 1000ab88 */

undefined4 __cdecl FUN_1000ab88(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  char local_5;

  uVar3 = 3;
  iVar1 = FUN_10003015(param_1,&local_5);
  if (iVar1 < 0) {
    puVar2 = (uint *)FUN_10002fe7((int)param_1);
    FUN_1000c245(puVar2);
    uVar3 = 0xffffffff;
  }
  else {
    if (local_5 == '\x01') {
      uVar3 = 0x4003;
    }
    else if (local_5 == '\x02') {
      uVar3 = 0x8003;
    }
    *param_3 = uVar3;
    uVar3 = 0;
  }
  return uVar3;
}



/* VA 1000abd7 */

undefined4 __cdecl FUN_1000abd7(int *param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  ushort local_6;

  iVar1 = FUN_10003028(param_1,&local_6);
  if (iVar1 < 0) {
    puVar2 = (uint *)FUN_10002fe7((int)param_1);
    FUN_1000c245(puVar2);
    return 0xffffffff;
  }
  *param_3 = (uint)local_6;
  return 0;
}



/* VA 1000ac0f */

uint __cdecl FUN_1000ac0f(uint param_1)

{
  uint uVar1;

  if (DAT_10017f58 != 0) {
    return param_1;
  }
  uVar1 = param_1 & 1;
  if ((param_1 & 2) != 0) {
    uVar1 = (uint)(byte)((byte)uVar1 | 2);
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  return uVar1;
}



/* VA 1000ac43 */

undefined4 __cdecl FUN_1000ac43(undefined2 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char local_84 [128];

  iVar2 = param_3;
  iVar1 = param_2;
  FUN_10002c45(param_3,0xcafebeef);
  FUN_10002c21(param_3,CONCAT22((short)((uint)param_1 >> 0x10),*param_1));
  FUN_10002c79(param_3,*(undefined4 *)(param_2 + 0x70),*(int *)(param_2 + 0x74));
  FUN_10002d05(param_3,*(char **)(param_2 + 0x38));
  FUN_10002c45(param_3,*(undefined4 *)(param_2 + 0x3c));
  FUN_10002c21(param_3,3);
  FUN_1000876e(param_2,param_3);
  FUN_10002d3c(param_3);
  FUN_10002d05(param_3,&DAT_10018c88);
  FUN_10002d05(param_3,&DAT_10018d40);
  FUN_10002d05(param_3,&DAT_10018ca8);
  FUN_10002c21(param_3,-DAT_10018cb8);
  FUN_10002d05(param_3,*(char **)(param_2 + 0x44));
  if (*(int *)(param_2 + 0x68) == 0) {
    FUN_10002c45(param_3,0);
  }
  else {
    FUN_10002c45(param_3,*(undefined4 *)(param_2 + 0x6c));
    FUN_10002ae4(param_3,*(int *)(param_2 + 0x68),*(size_t *)(param_2 + 0x6c));
  }
  iVar3 = FUN_1000ca60(*(int *)(param_2 + 0x58));
  FUN_10002c21(param_3,iVar3);
  param_3 = 0;
  if (0 < iVar3) {
    do {
      pcVar4 = (char *)FUN_1000ca26(*(int **)(iVar1 + 0x58),param_3);
      strcpy(local_84,pcVar4);
      param_2 = 0x50;
      pcVar4 = strchr(local_84,0x3a);
      if (pcVar4 != (char *)0x0) {
        param_2 = atoi(pcVar4 + 1);
        *pcVar4 = '\0';
      }
      FUN_10002d05(iVar2,local_84);
      FUN_10002c21(iVar2,param_2);
      param_3 = param_3 + 1;
    } while (param_3 < iVar3);
  }
  return 0;
}



/* VA 1000adac */

undefined4 __cdecl FUN_1000adac(undefined2 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char local_84 [128];

  iVar2 = param_3;
  iVar1 = param_2;
  FUN_10002c45(param_3,0xcafebeef);
  FUN_10002c21(param_3,CONCAT22((short)((uint)param_1 >> 0x10),*param_1));
  FUN_10002c79(param_3,*(undefined4 *)(param_2 + 0x70),*(int *)(param_2 + 0x74));
  FUN_10002d05(param_3,*(char **)(param_2 + 0x38));
  FUN_10002c45(param_3,*(undefined4 *)(param_2 + 0x3c));
  FUN_10002c21(param_3,3);
  FUN_1000876e(param_2,param_3);
  FUN_10002d3c(param_3);
  FUN_10002d05(param_3,&DAT_10018c88);
  FUN_10002d05(param_3,&DAT_10018d40);
  FUN_10002d05(param_3,&DAT_10018ca8);
  iVar3 = FUN_10002d05(param_3,&DAT_10018cc0);
  FUN_10002c21(param_3,CONCAT22((short)((uint)iVar3 >> 0x10),(undefined2)DAT_10018cb8));
  FUN_10002d05(param_3,*(char **)(param_2 + 0x48));
  if (*(int *)(param_2 + 0x68) == 0) {
    FUN_10002c45(param_3,0);
  }
  else {
    FUN_10002c45(param_3,*(undefined4 *)(param_2 + 0x6c));
    FUN_10002ae4(param_3,*(int *)(param_2 + 0x68),*(size_t *)(param_2 + 0x6c));
  }
  iVar3 = FUN_1000ca60(*(int *)(param_2 + 0x58));
  FUN_10002c21(param_3,iVar3);
  param_3 = 0;
  if (0 < iVar3) {
    do {
      pcVar4 = (char *)FUN_1000ca26(*(int **)(iVar1 + 0x58),param_3);
      strcpy(local_84,pcVar4);
      param_2 = 0x50;
      pcVar4 = strchr(local_84,0x3a);
      if (pcVar4 != (char *)0x0) {
        param_2 = atoi(pcVar4 + 1);
        *pcVar4 = '\0';
      }
      FUN_10002d05(iVar2,local_84);
      FUN_10002c21(iVar2,param_2);
      param_3 = param_3 + 1;
    } while (param_3 < iVar3);
  }
  return 0;
}



/* VA 1000af21 */

void __cdecl FUN_1000af21(void *param_1)

{
  free(param_1);
  return;
}



/* VA 1000af2d */

undefined4 * FUN_1000af2d(void)

{
  undefined4 *_Memory;
  HMODULE pHVar1;
  FARPROC pFVar2;
  undefined4 *puVar3;
  CHAR *lpFilename;
  DWORD nSize;
  CHAR local_104 [260];

  _Memory = malloc(0xc4);
  if (_Memory != (undefined4 *)0x0) {
    lpFilename = local_104;
    nSize = 0x104;
    pHVar1 = GetModuleHandleA(s_mrbupd_dll_10018348);
    GetModuleFileNameA(pHVar1,lpFilename,nSize);
    strcat(local_104,s_____mrbsslc_dll_10018338);
    pHVar1 = LoadLibraryA(local_104);
    *_Memory = pHVar1;
    if (pHVar1 != (HMODULE)0x0) {
      pFVar2 = GetProcAddress(pHVar1,s_mrb_verifyInit_10018328);
      _Memory[0x18] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_verifyUpdate_10018314);
      _Memory[0x19] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_verifyFinal_10018304);
      _Memory[0x1a] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_destroySignature_100182ec);
      _Memory[0x1b] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_B64Decode_100182dc);
      _Memory[0x1c] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_B64Encode_100182cc);
      _Memory[0x1d] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_decodeCertificate_100182b4);
      _Memory[0x1e] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_verifySignature_100182a0);
      _Memory[0x1f] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getVersion_10018290);
      _Memory[0x20] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getStartDate_1001827c);
      _Memory[0x21] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getEndDate_1001826c);
      _Memory[0x22] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getSerialNumber_10018258);
      _Memory[0x23] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getFingerPrint_10018244);
      _Memory[0x24] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getIssuerNameAVACount_10018228);
      _Memory[0x25] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getIssuerNameAVA_10018210);
      _Memory[0x26] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getSubjectNameAVACount_100181f4);
      _Memory[0x27] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getSubjectNameAVA_100181dc);
      _Memory[0x28] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_getCertEncoding_100181c8);
      _Memory[0x29] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_acceptTestCerts_100181b4);
      _Memory[0x2a] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_native_SSLInit_100181a0);
      _Memory[0x2b] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_native_SSLTerm_1001818c);
      _Memory[0x2c] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_native_DoSSLHandShake_10018170);
      _Memory[0x2d] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_native_SSLRead_1001815c);
      _Memory[0x2e] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_native_SSLWrite_10018148);
      _Memory[0x2f] = pFVar2;
      pFVar2 = GetProcAddress((HMODULE)*_Memory,s_mrb_native_SSLFlush_10018134);
      _Memory[0x30] = pFVar2;
      if ((((((((_Memory[0x18] != 0) && (_Memory[0x19] != 0)) && (_Memory[0x1a] != 0)) &&
             (((_Memory[0x1b] != 0 && (_Memory[0x1c] != 0)) &&
              ((_Memory[0x1d] != 0 && ((_Memory[0x1f] != 0 && (_Memory[0x2a] != 0)))))))) &&
            (_Memory[0x1e] != 0)) &&
           (((((_Memory[0x20] != 0 && (_Memory[0x21] != 0)) && (_Memory[0x22] != 0)) &&
             ((_Memory[0x23] != 0 && (_Memory[0x24] != 0)))) &&
            ((_Memory[0x25] != 0 && ((_Memory[0x26] != 0 && (_Memory[0x27] != 0)))))))) &&
          ((_Memory[0x28] != 0 &&
           (((_Memory[0x29] != 0 && (_Memory[0x2b] != 0)) && (_Memory[0x2c] != 0)))))) &&
         (((_Memory[0x2d] != 0 && (_Memory[0x2e] != 0)) &&
          ((_Memory[0x2f] != 0 && (pFVar2 != (FARPROC)0x0)))))) {
        puVar3 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
        _Memory[0x14] = puVar3;
        puVar3 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
        _Memory[0x15] = puVar3;
        _Memory[0x16] = 0;
        _Memory[0x17] = 0;
        return _Memory;
      }
      FreeLibrary((HMODULE)*_Memory);
    }
    free(_Memory);
  }
  return (undefined4 *)0x0;
}



/* VA 1000b23c */

void __cdecl FUN_1000b23c(undefined4 *param_1)

{
  if ((HMODULE)*param_1 != (HMODULE)0x0) {
    FreeLibrary((HMODULE)*param_1);
  }
  if ((int *)param_1[0x14] != (int *)0x0) {
    FUN_10003757((int *)param_1[0x14]);
  }
  if ((int *)param_1[0x15] != (int *)0x0) {
    FUN_10003757((int *)param_1[0x15]);
  }
  free(param_1);
  return;
}



/* VA 1000b274 */

void __cdecl FUN_1000b274(int param_1,int param_2,int param_3)

{
  FUN_1000b294(param_1,param_2,param_3,param_1 + 4,*(int **)(param_1 + 0x54),
               *(int **)(param_1 + 0x50));
  return;
}



/* VA 1000b294 */

undefined4 __cdecl
FUN_1000b294(int param_1,int param_2,int param_3,undefined4 param_4,int *param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_608 [1024];
  char local_208 [256];
  char local_108 [256];
  int local_8;

  iVar1 = param_1;
  iVar2 = (**(code **)(param_1 + 0x78))(param_4,param_2,param_3,2,1);
  if (iVar2 == 0) {
    FUN_10003a4e(param_5);
    FUN_10003a4e(param_6);
    local_8 = FUN_1000baa0(iVar1,param_4,2);
    param_3 = 0;
    if (0 < local_8) {
      do {
        param_1 = 0x100;
        param_2 = 0x100;
        iVar2 = FUN_1000bb21(iVar1,param_4,2,param_3,(int)local_108,&param_1,(int)local_208,&param_2
                            );
        if (iVar2 == 0) {
          uVar4 = FUN_1000378d(param_5,local_108);
          if (uVar4 == 0) {
            pcVar5 = local_208;
          }
          else {
            sprintf(local_608,s__s__s_10018354,uVar4,local_208);
            pcVar5 = local_608;
          }
          pcVar5 = _strdup(pcVar5);
          pcVar6 = _strdup(local_108);
          FUN_10003881(param_5,(uint)pcVar6,(uint)pcVar5);
        }
        param_3 = param_3 + 1;
      } while (param_3 < local_8);
    }
    local_8 = FUN_1000baa0(iVar1,param_4,1);
    param_3 = 0;
    if (0 < local_8) {
      do {
        param_1 = 0x100;
        param_2 = 0x100;
        iVar2 = FUN_1000bb21(iVar1,param_4,1,param_3,(int)local_108,&param_1,(int)local_208,&param_2
                            );
        if (iVar2 == 0) {
          uVar4 = FUN_1000378d(param_6,local_108);
          if (uVar4 == 0) {
            pcVar5 = local_208;
          }
          else {
            sprintf(local_608,s__s__s_10018354,uVar4,local_208);
            pcVar5 = local_608;
          }
          pcVar5 = _strdup(pcVar5);
          pcVar6 = _strdup(local_108);
          FUN_10003881(param_6,(uint)pcVar6,(uint)pcVar5);
        }
        param_3 = param_3 + 1;
      } while (param_3 < local_8);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* VA 1000b456 */

undefined4 __cdecl
FUN_1000b456(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            char *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;

  uVar3 = 0;
  iVar1 = (**(code **)(param_1 + 0x60))
                    (param_3,param_4,*(undefined4 *)(param_5 + 0x24),*(undefined4 *)(param_5 + 0x28)
                    );
  if (iVar1 != 0) {
    iVar2 = FUN_1000b4b2(param_1,param_2,iVar1,0,param_6);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(param_1 + 0x68))(iVar1);
      if (iVar2 != 0) {
        uVar3 = 0xffffffff;
      }
      (**(code **)(param_1 + 0x6c))(iVar1);
      return uVar3;
    }
    (**(code **)(param_1 + 0x6c))();
  }
  return 0xffffffff;
}



/* VA 1000b4b2 */

undefined4 __cdecl
FUN_1000b4b2(int param_1,int *param_2,undefined4 param_3,int param_4,char *param_5)

{
  bool bVar1;
  int iVar2;
  char *_Str;
  size_t sVar3;
  undefined4 uVar4;
  undefined3 extraout_var;
  int iVar5;
  int iVar6;
  char local_108 [260];

  if (param_4 == 0) {
    if (*param_2 == 0) {
      strcpy(local_108,&DAT_10018c80);
    }
    else {
      sprintf(local_108,&DAT_10018380,*param_2);
    }
    if ((param_5 == (char *)0x0) || (iVar2 = strcmp(param_5,&DAT_10017148), iVar2 == 0))
    goto LAB_1000b5c8;
    iVar2 = FUN_10005266(param_2,s__properties_txt_10018370);
    if (iVar2 != 0) {
      _Str = FUN_1000127f(*(uint *)(iVar2 + 0x10),*(uint *)(iVar2 + 0x14),
                          *(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c));
      sVar3 = strlen(s__properties_txt_10018370);
      iVar2 = (**(code **)(param_1 + 100))(param_3,s__properties_txt_10018370,sVar3);
      if (iVar2 == 0) {
        sVar3 = strlen(_Str);
        iVar2 = (**(code **)(param_1 + 100))(param_3,_Str,sVar3);
        if (iVar2 == 0) {
          free(_Str);
          param_2 = (int *)FUN_10005266(param_2,param_5);
          if (param_2 != (int *)0x0) goto LAB_1000b5c8;
          goto LAB_1000b598;
        }
      }
      goto LAB_1000b63d;
    }
LAB_1000b598:
    uVar4 = 0xffffffff;
  }
  else {
    sprintf(local_108,s__s__s_10018368,param_4,*param_2);
LAB_1000b5c8:
    iVar2 = (int)(short)param_2[1];
    if (iVar2 < 0) {
      bVar1 = FUN_1000b688(local_108,s_channel_sig_1001835c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        _Str = FUN_1000127f(param_2[4],param_2[5],param_2[6],param_2[7]);
        sVar3 = strlen(local_108);
        iVar2 = (**(code **)(param_1 + 100))(param_3,local_108,sVar3);
        if (iVar2 == 0) {
          sVar3 = strlen(_Str);
          iVar2 = (**(code **)(param_1 + 100))(param_3,_Str,sVar3);
          if (iVar2 == 0) {
            free(_Str);
            goto LAB_1000b681;
          }
        }
LAB_1000b63d:
        free(_Str);
        goto LAB_1000b598;
      }
    }
    else {
      iVar6 = 0;
      if (0 < iVar2) {
        do {
          iVar5 = FUN_1000b4b2(param_1,*(int **)(param_2[2] + iVar6 * 4),param_3,(int)local_108,
                               (char *)0x0);
          if (iVar5 != 0) goto LAB_1000b598;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar2);
      }
    }
LAB_1000b681:
    uVar4 = 0;
  }
  return uVar4;
}



/* VA 1000b688 */

bool __cdecl FUN_1000b688(char *param_1,char *param_2)

{
  char cVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;

  sVar2 = strlen(param_2);
  sVar3 = strlen(param_1);
  if ((int)sVar3 < (int)sVar2) {
    cVar1 = '\0';
  }
  else {
    iVar4 = strcmp(param_1 + (sVar3 - sVar2),param_2);
    cVar1 = '\x01' - (iVar4 != 0);
  }
  return (bool)cVar1;
}



/* VA 1000b6c1 */

char * __cdecl FUN_1000b6c1(char *param_1,int *param_2)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  void *pvVar5;
  char local_1230 [4096];
  char local_230 [260];
  char local_12c [252];
  undefined4 uStackY_30;
  undefined4 uVar6;
  char *pcVar7;
  char *_Memory;
  char *pcVar8;
  void *_Memory_00;
  void *_Memory_01;

  pcVar2 = param_1;
  FUN_10014d20();
  iVar1 = *(int *)(param_1 + 0xd0);
  param_1 = &DAT_10017148;
  _Memory_01 = (void *)0x0;
  _Memory_00 = (void *)0x0;
  pcVar8 = (char *)0x0;
  iVar4 = FUN_10005266(param_2,(char *)0x0);
  if (iVar4 == 0) {
    iVar4 = FUN_10005266(param_2,s_signed_channel_sig_100183b8);
    if (iVar4 == 0) {
      *(undefined4 *)(iVar1 + 0x58) = 0;
      mrbRemoveProperty((int)pcVar2,s_signed_cert_10017f68);
      return (char *)0x0;
    }
    param_1 = s_signed__100183b0;
  }
  sprintf(local_12c,&DAT_10018398);
  iVar4 = FUN_10005266(param_2,local_12c);
  if (iVar4 != 0) {
    iVar4 = FUN_1000ef1e((int)pcVar2,param_2,local_12c,0x104);
    if (iVar4 == -1) {
      sprintf(local_12c,s__s__s_s_10018390);
      bVar3 = FUN_100034b0(local_12c);
      if (CONCAT31(extraout_var,bVar3) == 0) goto LAB_1000b87f;
    }
    sprintf(local_230,&DAT_10018398);
    iVar4 = FUN_1000ef1e((int)pcVar2,param_2,local_230,0x104);
    if (iVar4 == -1) {
      sprintf(local_230,s__s__s_s_10018390);
      bVar3 = FUN_100034b0(local_230);
      if (CONCAT31(extraout_var_00,bVar3) == 0) goto LAB_1000b87f;
    }
    pcVar7 = (char *)0x1000b82a;
    _Memory_01 = FUN_100035ff(local_230,(size_t *)&stack0xffffffe4);
    if (_Memory_01 != (void *)0x0) {
      _Memory = pcVar7;
      _Memory_00 = malloc((size_t)pcVar7);
      if ((_Memory_00 == (void *)0x0) ||
         (iVar4 = (**(code **)(iVar1 + 0x70))(), _Memory = pcVar7, iVar4 != 0)) goto LAB_1000b9c6;
      _Memory = local_12c;
      pvVar5 = FUN_100035ff(_Memory,(size_t *)&stack0xffffffe8);
      if (pvVar5 != (void *)0x0) {
        uVar6 = 0x1000b895;
        iVar4 = FUN_1000b274(*(int *)(pcVar2 + 0xd0),(int)pvVar5,(int)_Memory);
        if ((iVar4 == 0) &&
           (_Memory = param_1,
           iVar4 = FUN_1000b456(*(int *)(pcVar2 + 0xd0),param_2,_Memory_00,uVar6,iVar1 + 4,param_1),
           iVar4 == 0)) {
          FUN_1000378d(*(int **)(iVar1 + 0x54),&DAT_1001838c);
          FUN_1000378d(*(int **)(iVar1 + 0x54),&DAT_10018388);
          uStackY_30 = 0x1000b8f9;
          FUN_1000378d(*(int **)(iVar1 + 0x54),&DAT_10018384);
          uStackY_30 = 0x1000b903;
          iVar4 = (**(code **)(iVar1 + 0x7c))();
          if (iVar4 == 0) {
            FUN_1000b9f7(iVar1);
            _Memory = &stack0xffffffe8;
            iVar4 = (**(code **)(iVar1 + 0xa4))();
            if (iVar4 == 0) {
              pcVar7 = (char *)mrbGetProperty((int)pcVar2,s_signed_cert_10017f68,0);
              iVar4 = 0x1000b95d;
              (**(code **)(iVar1 + 0x74))();
              local_1230[iVar4] = '\0';
              if ((pcVar7 == (char *)0x0) || (iVar4 = strcmp(pcVar7,local_1230), iVar4 != 0)) {
                pcVar8 = (char *)0x1;
              }
              mrbSetProperty((int)pcVar2,s_signed_cert_10017f68,local_1230);
              _Memory = &DAT_10017148;
              iVar4 = strcmp(param_1,&DAT_10017148);
              if (iVar4 == 0) {
                *(undefined4 *)(iVar1 + 0x58) = 0;
              }
              else {
                *(char **)(iVar1 + 0x58) = param_1;
              }
            }
          }
          else {
            _Memory = (char *)0xfffffffd;
          }
        }
        goto LAB_1000b9c6;
      }
    }
  }
LAB_1000b87f:
  _Memory = (char *)0xfffffffc;
LAB_1000b9c6:
  if (_Memory != (char *)0x0) {
    free(_Memory);
  }
  if (_Memory_01 != (void *)0x0) {
    free(_Memory_01);
  }
  if (_Memory_00 != (void *)0x0) {
    free(_Memory_00);
  }
  return pcVar8;
}



/* VA 1000b9f7 */

undefined4 __cdecl FUN_1000b9f7(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  time_t tVar4;

  iVar1 = (**(code **)(param_1 + 0x84))(param_1 + 4);
  iVar2 = (**(code **)(param_1 + 0x88))(param_1 + 4);
  tVar4 = time((time_t *)0x0);
  if (((int)tVar4 < iVar1) || (iVar2 < (int)tVar4)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* VA 1000ba31 */

bool __cdecl FUN_1000ba31(undefined4 *param_1)

{
  int iVar1;
  char *pcVar2;
  char local_108 [260];

  pcVar2 = &DAT_10017148;
  iVar1 = FUN_10005266(param_1,s_channel_sig_1001835c);
  if (iVar1 == 0) {
    iVar1 = FUN_10005266(param_1,s_signed_channel_sig_100183b8);
    if (iVar1 == 0) {
      return false;
    }
    pcVar2 = s_signed__100183b0;
  }
  sprintf(local_108,&DAT_10018398,pcVar2,s_channel_cert_100183a0);
  iVar1 = FUN_10005266(param_1,local_108);
  return iVar1 != 0;
}



/* VA 1000baa0 */

undefined4 __cdecl FUN_1000baa0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;

  if (param_3 == 1) {
    iVar1 = (**(code **)(param_1 + 0x9c))(param_2,&param_2);
  }
  else {
    if (param_3 != 2) {
      return 0xffffffff;
    }
    iVar1 = (**(code **)(param_1 + 0x94))(param_2,&param_2);
  }
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return param_2;
}



/* VA 1000bade */

void __cdecl FUN_1000bade(int param_1,int param_2)

{
  FUN_1000baa0(param_1,param_1 + 4,param_2);
  return;
}



/* VA 1000baf4 */

uint __cdecl FUN_1000baf4(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int *piVar2;

  if (param_2 == 1) {
    piVar2 = *(int **)(param_1 + 0x50);
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    piVar2 = *(int **)(param_1 + 0x54);
  }
  uVar1 = FUN_1000378d(piVar2,param_3);
  return uVar1;
}



/* VA 1000bb21 */

undefined4 __cdecl
FUN_1000bb21(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,int *param_6,
            int param_7,int *param_8)

{
  int iVar1;

  if (param_3 == 1) {
    iVar1 = (**(code **)(param_1 + 0xa0))
                      (param_2,param_4,param_5,param_6,*param_6,param_7,param_8,*param_8);
  }
  else {
    if (param_3 != 2) {
      return 0xffffffff;
    }
    iVar1 = (**(code **)(param_1 + 0x98))
                      (param_2,param_4,param_5,param_6,*param_6,param_7,param_8,*param_8);
  }
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *(undefined1 *)(param_5 + *param_6) = 0;
  *(undefined1 *)(param_7 + *param_8) = 0;
  return 0;
}



/* VA 1000bb92 */

void __cdecl
FUN_1000bb92(int param_1,int param_2,undefined4 param_3,int param_4,int *param_5,int param_6,
            int *param_7)

{
  FUN_1000bb21(param_1,param_1 + 4,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* VA 1000bbb9 */

undefined4 __cdecl FUN_1000bbb9(int param_1,char *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char local_84 [128];

  uVar1 = *param_3;
  iVar2 = (**(code **)(param_1 + 0x8c))(param_1 + 4,local_84,param_3,0x80);
  if (iVar2 == 0) {
    local_84[*param_3] = '\0';
    FUN_1000bc09(local_84,param_2,uVar1);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* VA 1000bc09 */

void __cdecl FUN_1000bc09(char *param_1,char *param_2,uint param_3)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  char *_Str;
  char local_14 [16];

  sVar1 = strlen(param_1);
  iVar3 = 0;
  *param_2 = '\0';
  if (0 < (int)sVar1) {
    do {
      sVar2 = strlen(param_2);
      if (param_3 < sVar2 + 3) {
        return;
      }
      sprintf(local_14,&DAT_100183d0,(int)param_1[iVar3]);
      sVar2 = strlen(local_14);
      _Str = local_14;
      if (2 < sVar2) {
        sVar2 = strlen(_Str);
        _Str = &stack0xffffffea + sVar2;
      }
      strcat(param_2,_Str);
      if (iVar3 < (int)(sVar1 - 1)) {
        strcat(param_2,&DAT_100183cc);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)sVar1);
  }
  return;
}



/* VA 1000bc99 */

undefined4 __cdecl FUN_1000bc99(int param_1,char *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char local_84 [128];

  uVar1 = *param_3;
  iVar2 = (**(code **)(param_1 + 0x90))(param_1 + 4,local_84,param_3,0x80);
  if (iVar2 == 0) {
    local_84[*param_3] = '\0';
    FUN_1000bc09(local_84,param_2,uVar1);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* VA 1000bce9 */

undefined4 __cdecl FUN_1000bce9(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;

  uVar1 = (**(code **)(param_1 + 0x84))(param_1 + 4);
  *param_2 = uVar1;
  uVar1 = (**(code **)(param_1 + 0x88))(param_1 + 4);
  *param_3 = uVar1;
  return 0;
}



/* VA 1000bd13 */

undefined4 __cdecl FUN_1000bd13(int param_1,char *param_2,size_t *param_3)

{
  size_t sVar1;
  size_t sVar2;
  char *_Str;

  _Str = *(char **)(param_1 + 0x58);
  if (_Str == (char *)0x0) {
    _Str = &DAT_10017148;
  }
  sVar2 = *param_3 - 1;
  sVar1 = strlen(_Str);
  if ((int)sVar2 < (int)sVar1) {
    *param_3 = sVar2;
    strncpy(param_2,_Str,sVar2);
    param_2[*param_3] = '\0';
  }
  else {
    sVar2 = strlen(_Str);
    *param_3 = sVar2;
    strcpy(param_2,_Str);
  }
  return 0;
}



/* VA 1000bd6f */

void __cdecl FUN_1000bd6f(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;

  local_18 = param_2;
  local_14 = param_3;
  local_10 = param_4;
  (**(code **)(param_1 + 0xac))(&local_18);
  return;
}



/* VA 1000bd97 */

void __cdecl FUN_1000bd97(int param_1)

{
  undefined1 *local_18 [5];

  local_18[0] = &stack0x00000008;
  (**(code **)(param_1 + 0xb0))(local_18);
  return;
}



/* VA 1000bdb3 */

int __cdecl FUN_1000bdb3(int param_1,undefined4 param_2,int *param_3,char *param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  size_t sVar8;
  undefined3 extraout_var;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 local_868 [2048];
  undefined1 local_68 [76];
  undefined4 *local_1c [3];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_1c[0] = &param_2;
  iVar2 = (**(code **)(param_1 + 0xb4))(local_1c,param_3);
  if (iVar2 != 0) {
    return -1;
  }
  param_3 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
  piVar3 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
  (**(code **)(param_1 + 0x74))(local_c,local_10,local_868,&local_8,0x800);
  iVar2 = FUN_1000b294(param_1,(int)local_868,local_8,local_68,piVar3,param_3);
  if (iVar2 != 0) {
    return -1;
  }
  uVar12 = 0x800;
  uVar11 = 0;
  uVar10 = 0;
  uVar4 = FUN_1000378d(piVar3,&DAT_1001838c);
  uVar5 = FUN_1000378d(piVar3,&DAT_10018388);
  uVar6 = FUN_1000378d(piVar3,&DAT_10018384);
  iVar2 = (**(code **)(param_1 + 0x7c))(local_68,uVar6,uVar5,uVar4,uVar10,uVar11,uVar12);
  if ((iVar2 == 0) && (pcVar7 = (char *)FUN_1000378d(param_3,&DAT_10018384), pcVar7 != (char *)0x0))
  {
    if (*pcVar7 == '*') {
      pcVar7 = _strdup(pcVar7);
      pcVar7 = pcVar7 + 1;
      sVar8 = strlen(pcVar7);
      iVar9 = 0;
      iVar2 = 0;
      if (0 < (int)(sVar8 - 1)) {
        do {
          if ((*pcVar7 == '.') && (iVar2 = iVar2 + 1, 1 < iVar2)) goto LAB_1000bede;
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(sVar8 - 1));
      }
      if (iVar2 < 2) goto LAB_1000bed9;
LAB_1000bede:
      bVar1 = FUN_1000b688(param_4,pcVar7);
      iVar2 = CONCAT31(extraout_var,bVar1) + -1;
    }
    else {
      iVar2 = strcmp(pcVar7,param_4);
    }
    iVar2 = -(uint)(iVar2 != 0);
  }
  else {
LAB_1000bed9:
    iVar2 = -1;
  }
  if (param_3 != (int *)0x0) {
    FUN_10003757(param_3);
  }
  if (piVar3 != (int *)0x0) {
    FUN_10003757(piVar3);
    return iVar2;
  }
  return iVar2;
}



/* VA 1000bf24 */

undefined4 __cdecl
FUN_1000bf24(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 *local_8;

  local_10 = param_2;
  local_c = param_3;
  local_8 = &param_4;
  iVar1 = (**(code **)(param_1 + 0xbc))(&local_10);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return param_4;
}



/* VA 1000bf5e */

undefined4 __cdecl
FUN_1000bf5e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 *local_8;

  local_10 = param_2;
  local_c = param_3;
  local_8 = &param_4;
  iVar1 = (**(code **)(param_1 + 0xb8))(&local_10);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return param_4;
}



/* VA 1000bf98 */

void __cdecl FUN_1000bf98(int param_1,undefined4 param_2)

{
  undefined4 local_10 [3];

  local_10[0] = param_2;
  (**(code **)(param_1 + 0xc0))(local_10);
  return;
}



/* VA 1000bfb4 */

void __cdecl FUN_1000bfb4(int param_1)

{
  (**(code **)(param_1 + 0xa8))(1);
  *(undefined4 *)(param_1 + 0x5c) = 1;
  return;
}



/* VA 1000bfcb */

void __cdecl FUN_1000bfcb(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;

  puVar1 = malloc(0x10);
  puVar1[3] = 0;
  *puVar1 = 2;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  return;
}



/* VA 1000bfed */

void __cdecl FUN_1000bfed(undefined4 param_1)

{
  undefined4 *puVar1;

  puVar1 = malloc(0x10);
  puVar1[3] = 0;
  puVar1[2] = 0;
  *puVar1 = 1;
  puVar1[1] = param_1;
  return;
}



/* VA 1000c00c */

void __cdecl FUN_1000c00c(int *param_1)

{
  int iVar1;

  FUN_1000c13e(param_1);
  iVar1 = *param_1;
  if (iVar1 == 1) {
    _close(param_1[1]);
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 != 3) goto LAB_1000c03e;
      FUN_1000c7d6(param_1);
    }
    closesocket(param_1[1]);
  }
LAB_1000c03e:
  free(param_1);
  return;
}



/* VA 1000c048 */

int __cdecl FUN_1000c048(int *param_1,char *param_2,uint param_3)

{
  int iVar1;
  bool bVar2;

  iVar1 = *param_1;
  if (iVar1 == 1) {
    iVar1 = _read(param_1[1],param_2,param_3);
    bVar2 = iVar1 == 0;
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        iVar1 = FUN_1000bf5e(*(int *)param_1[3],((int *)param_1[3])[1],param_2,param_3);
        return iVar1;
      }
      return -3;
    }
    FUN_1000c16f(param_1);
    iVar1 = FUN_1000c81e(param_1[1],param_1[2]);
    if (iVar1 == 1) {
      iVar1 = recv(param_1[1],param_2,param_3,0);
    }
    if (iVar1 == 0) {
      return -1;
    }
    bVar2 = iVar1 == -1;
  }
  if (bVar2) {
    return -1;
  }
  return iVar1;
}



/* VA 1000c0c5 */

int __cdecl FUN_1000c0c5(int *param_1,char *param_2,uint param_3)

{
  int iVar1;

  iVar1 = *param_1;
  if (iVar1 == 1) {
    iVar1 = _write(param_1[1],param_2,param_3);
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 != 3) {
        return -3;
      }
      iVar1 = FUN_1000bf24(*(int *)param_1[3],((int *)param_1[3])[1],param_2,param_3);
      return iVar1;
    }
    iVar1 = send(param_1[1],param_2,param_3,0);
    if (iVar1 == -1) {
      return -1;
    }
  }
  return iVar1;
}



/* VA 1000c120 */

undefined4 __cdecl FUN_1000c120(int *param_1,long param_2)

{
  undefined4 uVar1;

  if (*param_1 != 1) {
    return 0xfffffffd;
  }
  uVar1 = FUN_100033d1(param_1[1],param_2);
  return uVar1;
}



/* VA 1000c13e */

int __cdecl FUN_1000c13e(int *param_1)

{
  int iVar1;

  iVar1 = *param_1;
  if (iVar1 == 1) {
    iVar1 = _commit(param_1[1]);
    return iVar1;
  }
  if (iVar1 != 2) {
    if (iVar1 != 3) {
      return -3;
    }
    iVar1 = FUN_1000bf98(*(int *)param_1[3],((int *)param_1[3])[1]);
    return iVar1;
  }
  return 0;
}



/* VA 1000c16f */

u_long __cdecl FUN_1000c16f(int *param_1)

{
  int iVar1;
  int iVar2;
  u_long uVar3;
  u_long local_8;

  local_8 = 0;
  if (*param_1 == 1) {
    iVar1 = FUN_100033c5(param_1[1]);
    iVar2 = FUN_100033e5(param_1[1]);
    uVar3 = 0xffffffff;
    if ((iVar1 != -1) && (iVar2 != -1)) {
      uVar3 = iVar2 - iVar1;
    }
  }
  else if (*param_1 == 2) {
    iVar1 = ioctlsocket(param_1[1],0x4004667f,&local_8);
    uVar3 = 0xffffffff;
    if (iVar1 != -1) {
      uVar3 = local_8;
    }
  }
  else {
    uVar3 = 0xfffffffd;
  }
  return uVar3;
}



/* VA 1000c1d1 */

uint __cdecl FUN_1000c1d1(uint *param_1)

{
  int iVar1;
  uint uVar2;

  uVar2 = *param_1;
  if (uVar2 == 1) {
    uVar2 = _eof(param_1[1]);
    if (uVar2 != 0xffffffff) {
      return uVar2;
    }
  }
  else if (((1 < uVar2) && (uVar2 < 4)) &&
          (iVar1 = recv(param_1[1],(char *)&param_1,1,2), iVar1 != -1)) {
    return (uint)(iVar1 == 0);
  }
  return 0xfffffffd;
}



/* VA 1000c219 */

void __cdecl FUN_1000c219(uint *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;

  uVar1 = *param_1;
  if (uVar1 == 1) {
    piVar2 = _errno();
    *piVar2 = param_2;
  }
  else {
    if (uVar1 < 2) {
      return;
    }
    if (3 < uVar1) {
      return;
    }
  }
  WSASetLastError(param_2);
  return;
}



/* VA 1000c245 */

uint __cdecl FUN_1000c245(uint *param_1)

{
  uint uVar1;
  int iVar2;

  uVar1 = *param_1;
  if (uVar1 == 1) {
    return 0;
  }
  if ((1 < uVar1) && (uVar1 < 4)) {
    iVar2 = WSAGetLastError();
    return (uint)(iVar2 == 0x2714);
  }
  return 0xfffffffd;
}



/* VA 1000c26e */

void __cdecl FUN_1000c26e(int *param_1,undefined4 param_2)

{
  param_2 = CONCAT31(CONCAT21(param_2._2_2_,(char)param_2),(char)((uint)param_2 >> 8));
  FUN_1000c0c5(param_1,(char *)&param_2,2);
  return;
}



/* VA 1000c292 */

void __cdecl FUN_1000c292(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;

  uVar3 = param_2;
  uVar1 = (uint)param_2 >> 0x18;
  uVar2 = (uint)param_2 >> 0x10;
  param_2._3_1_ = (undefined1)uVar3;
  param_2._0_3_ = CONCAT12((char)((uint)uVar3 >> 8),CONCAT11((char)uVar2,(char)uVar1));
  FUN_1000c0c5(param_1,(char *)&param_2,4);
  return;
}



/* VA 1000c2c6 */

void __cdecl FUN_1000c2c6(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;

  iVar2 = param_3;
  uVar1 = param_2;
  uVar3 = __allshr(0x38,param_3);
  param_2 = CONCAT31(param_2._1_3_,(char)uVar3);
  uVar3 = __allshr(0x30,iVar2);
  param_2._0_2_ = CONCAT11((char)uVar3,(undefined1)param_2);
  uVar3 = __allshr(0x28,iVar2);
  param_2._0_3_ = CONCAT12((char)uVar3,(undefined2)param_2);
  uVar3 = __allshr(0x20,iVar2);
  param_2 = CONCAT13((char)uVar3,(undefined3)param_2);
  uVar3 = __allshr(0x18,iVar2);
  param_3 = CONCAT31(param_3._1_3_,(char)uVar3);
  uVar3 = __allshr(0x10,iVar2);
  param_3._0_2_ = CONCAT11((char)uVar3,(undefined1)param_3);
  uVar3 = __allshr(8,iVar2);
  param_3 = CONCAT13((char)uVar1,CONCAT12((char)uVar3,(undefined2)param_3));
  FUN_1000c0c5(param_1,(char *)&param_2,8);
  return;
}



/* VA 1000c352 */

void __cdecl FUN_1000c352(int *param_1)

{
  FUN_1000c0c5(param_1,&stack0x00000008,1);
  return;
}



/* VA 1000c366 */

int __cdecl FUN_1000c366(int *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;

  sVar1 = strlen(param_2);
  iVar2 = FUN_1000c26e(param_1,sVar1);
  if (iVar2 < 0) {
    return -1;
  }
  iVar2 = FUN_1000c0c5(param_1,param_2,(int)(short)sVar1);
  return iVar2;
}



/* VA 1000c39e */

void __cdecl FUN_1000c39e(int *param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  undefined2 local_6;

  iVar2 = 0;
  do {
    iVar1 = FUN_1000c048(param_1,(char *)((int)&local_6 + iVar2),2 - iVar2);
    if (iVar1 < 0) {
      return;
    }
    iVar2 = iVar2 + iVar1;
  } while (iVar2 < 2);
  *param_2 = CONCAT11((undefined1)local_6,local_6._1_1_);
  return;
}



/* VA 1000c3db */

int __cdecl FUN_1000c3db(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;

  iVar2 = 0;
  do {
    iVar1 = FUN_1000c048(param_1,(char *)((int)&local_8 + iVar2),4 - iVar2);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar2 = iVar2 + iVar1;
  } while (iVar2 < 4);
  *param_2 = CONCAT31(CONCAT21(CONCAT11((undefined1)local_8,local_8._1_1_),local_8._2_1_),
                      local_8._3_1_);
  return iVar2;
}



/* VA 1000c42a */

int __cdecl FUN_1000c42a(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  char local_10 [7];
  byte local_9;
  int local_8;

  iVar2 = 0;
  do {
    iVar1 = FUN_1000c048(param_1,local_10 + iVar2,8 - iVar2);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar2 = iVar2 + iVar1;
  } while (iVar2 < 8);
  lVar3 = __allshl(8,0);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  local_8 = (int)((ulonglong)lVar3 >> 0x20);
  lVar3 = __allshl(8,local_8);
  *param_2 = (uint)lVar3 | (uint)local_9;
  param_2[1] = (uint)((ulonglong)lVar3 >> 0x20);
  return 0;
}



/* VA 1000c55b */

void __cdecl FUN_1000c55b(int *param_1,char *param_2)

{
  int iVar1;

  do {
    iVar1 = FUN_1000c048(param_1,param_2,1);
    if (iVar1 < 0) {
      return;
    }
  } while (iVar1 != 1);
  return;
}



/* VA 1000c577 */

int __cdecl FUN_1000c577(int *param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_8;

  iVar4 = 0;
  iVar1 = FUN_1000c39e(param_1,(undefined2 *)((int)&uStack_8 + 2));
  if (iVar1 < 0) {
    iVar4 = -1;
  }
  else {
    pvVar2 = malloc((int)uStack_8._2_2_ + 1);
    *param_2 = (int)pvVar2;
    iVar1 = (int)uStack_8._2_2_;
    if (0 < iVar1) {
      do {
        iVar3 = FUN_1000c048(param_1,(char *)(*param_2 + iVar4),iVar1 - iVar4);
        if (iVar3 < 0) {
          free(param_2);
          return iVar3;
        }
        iVar1 = (int)uStack_8._2_2_;
        iVar4 = iVar4 + iVar3;
      } while (iVar4 < iVar1);
    }
    *(undefined1 *)(*param_2 + (int)uStack_8._2_2_) = 0;
  }
  return iVar4;
}



/* VA 1000c5f1 */

int __cdecl FUN_1000c5f1(int *param_1,undefined4 *param_2)

{
  char *_Src;
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uStack_8;

  iVar3 = 0;
  _Src = malloc(0x400);
  while( true ) {
    iVar1 = FUN_1000c55b(param_1,(char *)((int)&uStack_8 + 3));
    if (iVar1 != 1) break;
    if (uStack_8._3_1_ == '\r') {
      iVar1 = FUN_1000c55b(param_1,(char *)((int)&uStack_8 + 3));
      if (iVar1 != 1) break;
      if (uStack_8._3_1_ == '\n') goto LAB_1000c65c;
      _Src[iVar3] = '\r';
      iVar3 = iVar3 + 1;
    }
    _Src[iVar3] = uStack_8._3_1_;
    iVar3 = iVar3 + 1;
  }
  if (iVar3 < 1) {
    free(_Src);
  }
  else {
LAB_1000c65c:
    _Src[iVar3] = '\0';
    pcVar2 = _strdup(_Src);
    *param_2 = pcVar2;
    free(_Src);
    iVar1 = 0;
  }
  return iVar1;
}



/* VA 1000c67c */

uint __cdecl FUN_1000c67c(uint param_1,int param_2,uint *param_3,int param_4)

{
  int iVar1;
  uint uVar2;

  uVar2 = 0;
  *param_3 = 0;
  do {
    iVar1 = send(*(SOCKET *)(param_4 + 4),(char *)(param_2 + uVar2),param_1 - uVar2,0);
    if (iVar1 < 1) break;
    uVar2 = uVar2 + iVar1;
  } while (uVar2 < param_1);
  *param_3 = uVar2;
  return -(uint)(uVar2 != param_1) & 0xffffe4b0;
}



/* VA 1000c6bf */

undefined4 __cdecl FUN_1000c6bf(uint param_1,char *param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;

  piVar1 = param_4;
  uVar5 = 0;
  *param_3 = 0;
  if (*(int *)(param_4[3] + 8) == 0) {
LAB_1000c760:
    do {
      iVar2 = recv(piVar1[1],param_2 + uVar5,param_1 - uVar5,0);
      if (iVar2 < 1) break;
      uVar5 = uVar5 + iVar2;
    } while (uVar5 < param_1);
    *param_3 = uVar5;
    uVar4 = 0;
  }
  else {
    *(undefined4 *)(param_4[3] + 8) = 0;
    iVar2 = recv(param_4[1],param_2,1,2);
    if (iVar2 == 1) {
      if (*param_2 != 'H') goto LAB_1000c760;
      *piVar1 = 2;
      iVar2 = FUN_1000c5f1(piVar1,&param_3);
      *piVar1 = 3;
      if (iVar2 == 0) {
        pcVar3 = strchr((char *)param_3,0x20);
        if ((pcVar3 != (char *)0x0) &&
           (iVar2 = strcmp(pcVar3 + 1,s_500_Non_SSL_Enabled_Host_100183d8), iVar2 == 0)) {
          FUN_1000c7d6(piVar1);
          free(param_3);
          return 0xffffe4ad;
        }
        free(param_3);
      }
    }
    uVar4 = 0xffffe4b0;
  }
  return uVar4;
}



/* VA 1000c78b */

undefined4 __cdecl FUN_1000c78b(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;

  iVar1 = *param_1;
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      puVar2 = malloc(0xc);
      param_1[3] = (int)puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = param_2;
        *(undefined4 *)(param_1[3] + 4) = param_3;
        *(undefined4 *)(param_1[3] + 8) = 1;
        *param_1 = 3;
        return 0;
      }
    }
    else if (iVar1 == 3) {
      return 0;
    }
  }
  return 0xffffffff;
}



/* VA 1000c7d6 */

undefined4 __cdecl FUN_1000c7d6(int *param_1)

{
  int iVar1;

  iVar1 = *param_1;
  if ((iVar1 != 1) && (iVar1 != 2)) {
    if (iVar1 != 3) {
      return 0xffffffff;
    }
    if ((void *)param_1[3] != (void *)0x0) {
      free((void *)param_1[3]);
      param_1[3] = 0;
    }
    *param_1 = 2;
  }
  return 0;
}



/* VA 1000c808 */

undefined4 __cdecl FUN_1000c808(int *param_1)

{
  int iVar1;

  iVar1 = *param_1;
  if (((iVar1 != 1) && (iVar1 != 2)) && (iVar1 == 3)) {
    return 1;
  }
  return 0;
}



/* VA 1000c81e */

int __cdecl FUN_1000c81e(SOCKET param_1,int param_2)

{
  int iVar1;
  fd_set local_110;
  timeval local_c;

  if (param_2 < 1) {
    return 1;
  }
  local_c.tv_sec = param_2 / 1000;
  local_110.fd_count = 1;
  local_110.fd_array[0] = param_1;
  local_c.tv_usec = (param_2 % 1000) * 1000;
  iVar1 = select(param_1,&local_110,(fd_set *)0x0,(fd_set *)0x0,&local_c);
  return iVar1;
}



/* VA 1000c87d */

undefined4 * __cdecl FUN_1000c87d(undefined *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  void *pvVar2;

  puVar1 = malloc(0x2c);
  pvVar2 = calloc(10,4);
  puVar1[2] = 0;
  *puVar1 = pvVar2;
  puVar1[1] = 10;
  if (param_1 == (undefined *)0x0) {
    param_1 = free_exref;
  }
  puVar1[3] = param_1;
  if (param_2 == (undefined1 *)0x0) {
    param_2 = &LAB_1000c8d0;
  }
  puVar1[4] = param_2;
  InitializeCriticalSection((LPCRITICAL_SECTION)(puVar1 + 5));
  return puVar1;
}



/* VA 1000c8de */

void __cdecl FUN_1000c8de(int *param_1)

{
  FUN_1000ca3d(param_1);
  free((void *)*param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  free(param_1);
  return;
}



/* VA 1000c907 */

void __cdecl FUN_1000c907(int *param_1,undefined4 param_2)

{
  FUN_1000c938((int)param_1);
  FUN_1000c956(param_1,param_1[2] + 1);
  *(undefined4 *)(*param_1 + param_1[2] * 4) = param_2;
  param_1[2] = param_1[2] + 1;
  FUN_1000c947((int)param_1);
  return;
}



/* VA 1000c938 */

void __cdecl FUN_1000c938(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  return;
}



/* VA 1000c947 */

void __cdecl FUN_1000c947(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  return;
}



/* VA 1000c956 */

void __cdecl FUN_1000c956(undefined4 *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;

  FUN_1000c938((int)param_1);
  if ((int)param_1[1] < param_2) {
    iVar1 = param_1[1] + 10;
    param_1[1] = iVar1;
    pvVar2 = realloc((void *)*param_1,iVar1 * 4);
    *param_1 = pvVar2;
  }
  FUN_1000c947((int)param_1);
  return;
}



/* VA 1000c98a */

undefined4 __cdecl FUN_1000c98a(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;

  FUN_1000c938((int)param_1);
  iVar3 = 0;
  if (0 < param_1[2]) {
    do {
      iVar2 = (*(code *)param_1[4])(param_2,*(undefined4 *)(*param_1 + iVar3 * 4));
      if (iVar2 != 0) {
        iVar2 = *param_1;
        uVar1 = *(undefined4 *)(iVar2 + iVar3 * 4);
        if (0 < param_1[2] - iVar3) {
          memmove((void *)(iVar2 + iVar3 * 4),(void *)(iVar2 + 4 + iVar3 * 4),
                  (param_1[2] - iVar3) * 4);
        }
        param_1[2] = param_1[2] + -1;
        FUN_1000c947((int)param_1);
        return uVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[2]);
  }
  FUN_1000c947((int)param_1);
  return 0;
}



/* VA 1000c9f6 */

undefined4 FUN_1000c9f6(void)

{
  return 0;
}



/* VA 1000c9f9 */

undefined4 __cdecl FUN_1000c9f9(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = *param_2;
  if (iVar1 == param_1[2]) {
    return 0;
  }
  uVar2 = *(undefined4 *)(*param_1 + iVar1 * 4);
  *param_2 = iVar1 + 1;
  return uVar2;
}



/* VA 1000ca14 */

undefined4 __cdecl FUN_1000ca14(undefined4 *param_1)

{
  if (0 < (int)param_1[2]) {
    return *(undefined4 *)*param_1;
  }
  return 0;
}



/* VA 1000ca26 */

undefined4 __cdecl FUN_1000ca26(int *param_1,int param_2)

{
  if (0 < param_1[2]) {
    return *(undefined4 *)(*param_1 + param_2 * 4);
  }
  return 0;
}



/* VA 1000ca3d */

void __cdecl FUN_1000ca3d(int *param_1)

{
  int iVar1;

  iVar1 = 0;
  if (0 < param_1[2]) {
    do {
      (*(code *)param_1[3])(*(undefined4 *)(*param_1 + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[2]);
  }
  param_1[2] = 0;
  return;
}



/* VA 1000ca60 */

undefined4 __cdecl FUN_1000ca60(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



/* VA 1000ca68 */

void __cdecl mrbSetProperty(int param_1,char *param_2,char *param_3)

{
  void *_Memory;
  char *pcVar1;
  char *pcVar2;

                    /* 0xca68  52  mrbSetProperty */
  if (param_3 == (char *)0x0) {
    _Memory = (void *)mrbRemoveProperty(param_1,param_2);
    if (_Memory != (void *)0x0) {
      free(_Memory);
    }
  }
  else {
    pcVar1 = _strdup(param_3);
    pcVar2 = _strdup(param_2);
    FUN_10006a1c(*(int **)(param_1 + 0x2c),(uint)pcVar2,(uint)pcVar1);
    *(undefined4 *)(param_1 + 200) = 1;
  }
  return;
}



/* VA 1000cabc */

void __cdecl mrbGetProperty(int param_1,undefined4 param_2,uint param_3)

{
                    /* 0xcabc  29  mrbGetProperty */
  FUN_10006a31(*(int **)(param_1 + 0x2c),param_2,param_3);
  return;
}



/* VA 1000cad4 */

void __cdecl mrbRemoveProperty(int param_1,undefined4 param_2)

{
  int iVar1;

                    /* 0xcad4  45  mrbRemoveProperty */
  iVar1 = FUN_10006a82(*(int **)(param_1 + 0x2c),param_2);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 200) = 1;
  }
  return;
}



/* VA 1000caf7 */

uint __cdecl mrbGetPublishedProperty(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  char local_108 [260];

                    /* 0xcaf7  30  mrbGetPublishedProperty */
  if (param_1[0x3c] == 0) {
    if ((*(byte *)(param_1 + 0x23) & 8) == 0) {
      uVar1 = *param_1;
    }
    else {
      uVar1 = param_1[0x3a];
    }
    sprintf(local_108,s_0123456789abcdef0123456789ABCDEF_10018400 + 100,uVar1);
    piVar2 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
    param_1[0x3c] = piVar2;
    iVar3 = FUN_100066bd(piVar2,local_108);
    if (iVar3 != 0) {
      FUN_10003757((int *)param_1[0x3c]);
      param_1[0x3c] = 0;
      return param_3;
    }
  }
  uVar4 = FUN_10006a31((int *)param_1[0x3c],param_2,param_3);
  return uVar4;
}



/* VA 1000cb98 */

undefined4 __cdecl FUN_1000cb98(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  undefined4 uVar3;

  bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0xc));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = FUN_100066bd(*(int **)(param_1 + 0x2c),*(char **)(param_1 + 0xc));
    if (iVar2 != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0xc);
      goto LAB_1000cbf2;
    }
  }
  if (*(int *)(param_1 + 0xdc) != 0) {
    bVar1 = FUN_100034b0(*(int *)(param_1 + 0xdc));
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      iVar2 = FUN_100066bd(*(int **)(param_1 + 0xe0),*(char **)(param_1 + 0xdc));
      if (iVar2 != 0) {
        uVar3 = *(undefined4 *)(param_1 + 0xdc);
LAB_1000cbf2:
        FUN_1000f4e8(param_1,0x3f4,uVar3);
        return 0xffffffff;
      }
    }
  }
  return 0;
}



/* VA 1000cc09 */

bool __cdecl mrbIsRepairNeeded(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;

                    /* 0xcc09  36  mrbIsRepairNeeded */
  bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0x18));
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0x10));
    if (CONCAT31(extraout_var_01,bVar1) != 0) {
      bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0x14));
      if (CONCAT31(extraout_var_02,bVar1) == 0) {
        return bVar1;
      }
    }
    return true;
  }
  bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0x10));
  if (CONCAT31(extraout_var_00,bVar1) != 0) {
    return false;
  }
  iVar2 = FUN_10003429(*(char **)(param_1 + 0x14),*(char **)(param_1 + 0x10));
  return iVar2 != 0;
}



/* VA 1000cc62 */

undefined4 __cdecl mrbRepair(undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 uVar3;

                    /* 0xcc62  46  mrbRepair */
  bVar1 = mrbIsRepairNeeded((int)param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
LAB_1000ccb7:
    uVar3 = 0;
  }
  else {
    if (param_1[0xc] == 0) {
      puVar2 = FUN_1000ccbc((int)param_1,(char *)param_1[4]);
      param_1[0xc] = puVar2;
      if (puVar2 != (undefined4 *)0x0) goto LAB_1000cc8b;
    }
    else {
LAB_1000cc8b:
      puVar2 = FUN_1000ccbc((int)param_1,(char *)param_1[5]);
      if (puVar2 != (undefined4 *)0x0) {
        FUN_1000f4e8((int)param_1,0x6b,0);
        FUN_1000fbbe(param_1,(uint)puVar2);
        goto LAB_1000ccb7;
      }
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* VA 1000ccbc */

undefined4 * __cdecl FUN_1000ccbc(int param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;

  iVar1 = FUN_10003374(param_2);
  if (iVar1 == -1) {
    uVar4 = 0x400;
  }
  else {
    piVar2 = (int *)FUN_1000bfed(iVar1);
    if (piVar2 != (int *)0x0) {
      puVar3 = FUN_10005af3(piVar2);
      FUN_1000c00c(piVar2);
      return puVar3;
    }
    FUN_100033b9(iVar1);
    uVar4 = 0x3f4;
  }
  FUN_1000f4e8(param_1,uVar4,param_2);
  return (undefined4 *)0x0;
}



/* VA 1000cd1c */

undefined4 __cdecl mrbClean(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  undefined4 uVar3;

                    /* 0xcd1c  16  mrbClean */
  bVar1 = mrbIsRepairNeeded(param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_100024a5(*(undefined4 *)(param_1 + 0x20));
  if ((iVar2 == 0) || (iVar2 = FUN_100025ea(*(char **)(param_1 + 0x20)), iVar2 == 0)) {
    bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0x18));
    if ((CONCAT31(extraout_var_00,bVar1) == 0) ||
       (iVar2 = FUN_1000341d(*(char **)(param_1 + 0x18)), iVar2 == 0)) {
      iVar2 = FUN_100024a5(*(undefined4 *)(param_1 + 0x1c));
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = FUN_100025ea(*(char **)(param_1 + 0x1c));
      if (iVar2 == 0) {
        return 0;
      }
      uVar3 = *(undefined4 *)(param_1 + 0x1c);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x18);
    }
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x20);
  }
  FUN_1000f4e8(param_1,0x3ff,uVar3);
  return 0xffffffff;
}



/* VA 1000cd9e */

void __cdecl mrbVerify(undefined4 *param_1)

{
                    /* 0xcd9e  57  mrbVerify */
  mrbVerifyEx(param_1,2);
  return;
}



/* VA 1000cdac */

uint __cdecl mrbVerifyEx(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;

                    /* 0xcdac  58  mrbVerifyEx */
  if (param_1[0xc] == 0) {
    puVar1 = FUN_1000ccbc((int)param_1,(char *)param_1[4]);
    param_1[0xc] = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
  }
  if (param_2 == 1) {
    uVar2 = FUN_1000cec5(param_1,(int *)param_1[0xc],1);
    return uVar2;
  }
  puVar1 = FUN_10005006((undefined4 *)param_1[0xc],(int)*(short *)((undefined4 *)param_1[0xc] + 1));
  uVar2 = FUN_1000cec5(param_1,(int *)param_1[0xc],param_2);
  if (uVar2 != 0) {
    FUN_100050a3((undefined4 *)param_1[0xc]);
    param_1[0xc] = puVar1;
    return uVar2;
  }
  FUN_100050a3(puVar1);
  iVar3 = FUN_1000ce3b((int)param_1,param_1[0xc],(char *)param_1[4]);
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  return 0;
}



/* VA 1000ce3b */

undefined4 __cdecl FUN_1000ce3b(int param_1,int param_2,char *param_3)

{
  int iVar1;
  int *piVar2;

  iVar1 = FUN_10003389(param_3);
  if (iVar1 == -1) {
    FUN_1000f4e8(param_1,0x3f3,param_3);
  }
  else {
    piVar2 = (int *)FUN_1000bfed(iVar1);
    if (piVar2 == (int *)0x0) {
      FUN_1000f4e8(param_1,0x3f3,param_3);
      FUN_100033b9(iVar1);
    }
    else {
      iVar1 = FUN_1000597c(param_2,piVar2);
      if (iVar1 == 0) {
        FUN_1000c00c(piVar2);
        return 0;
      }
      FUN_1000f4e8(param_1,0x3f8,param_3);
      FUN_1000c00c(piVar2);
    }
  }
  return 0xffffffff;
}



/* VA 1000cec5 */

uint __cdecl FUN_1000cec5(undefined4 *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  bool bVar5;
  short sVar6;
  undefined2 uVar7;
  char *pcVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  int *piVar14;
  undefined4 uVar15;
  char local_224 [260];
  char local_120 [260];
  int local_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  char *local_c;
  uint local_8;

  local_8 = 0;
  iVar9 = 1;
  pcVar8 = (char *)FUN_1000583e(param_2);
  puVar4 = param_1;
  sprintf(local_120,s__s__s_10018478,*param_1,pcVar8);
  strcpy(local_224,pcVar8);
  free(pcVar8);
  pcVar8 = local_120;
  while (pcVar8 = strchr(pcVar8,0x2f), pcVar8 != (char *)0x0) {
    *pcVar8 = '\\';
    pcVar8 = pcVar8 + 1;
  }
  local_c = (char *)mrbGetLocation((int)puVar4,local_224);
  if (local_c != (char *)0x0) {
    bVar5 = FUN_100034b0(local_c);
    if (CONCAT31(extraout_var,bVar5) == 0) {
      FUN_1000f4e8((int)puVar4,300,local_c);
      mrbSetLocation((int)puVar4,local_224,(char *)0x0);
      bVar5 = FUN_100034b0(local_120);
      iVar9 = CONCAT31(extraout_var_00,bVar5);
      if (iVar9 == 0) {
        if ((param_3 == 2) || (param_3 == 3)) goto LAB_1000d32b;
        local_8 = 0xffffffff;
      }
      else {
        local_c = (char *)0x0;
      }
    }
    else {
      iVar9 = 0;
    }
  }
  if (iVar9 == 0) goto LAB_1000d13d;
  bVar5 = FUN_100034b0(local_120);
  if (CONCAT31(extraout_var_01,bVar5) == 0) {
    if (local_c == (char *)0x0) {
      FUN_1000f4e8((int)puVar4,300,local_120);
    }
    if ((param_3 == 2) || (param_3 == 3)) goto LAB_1000d32b;
LAB_1000d139:
    local_8 = 0xffffffff;
  }
  else {
    if (((*(byte *)(puVar4 + 0x23) & 4) == 0) || (iVar9 = FUN_10003563(local_120), iVar9 != 0)) {
      iVar9 = FUN_100035b3(local_120);
      if (iVar9 == 0) {
        FUN_1000f4e8((int)puVar4,0x12d,local_120);
        if (param_3 == 2) {
LAB_1000d10f:
          FUN_10005747(puVar4[0xc],local_224);
          goto LAB_1000d13d;
        }
        if (param_3 == 3) {
          iVar9 = FUN_100035ed(local_120);
LAB_1000d134:
          if (iVar9 == 0) goto LAB_1000d13d;
        }
      }
      else {
        iVar9 = FUN_1000358b(local_120);
        if (iVar9 != 0) goto LAB_1000d13d;
        FUN_1000f4e8((int)puVar4,0x12e,local_120);
        if (param_3 == 2) goto LAB_1000d10f;
        if (param_3 == 3) {
          iVar9 = FUN_100035db(local_120);
          goto LAB_1000d134;
        }
      }
      goto LAB_1000d139;
    }
    iVar9 = FUN_10003685(local_120,(ushort *)&param_1);
    if (iVar9 == -1) {
      uVar15 = 0x3f7;
LAB_1000d09c:
      FUN_1000f4e8((int)puVar4,uVar15,local_120);
      goto LAB_1000d139;
    }
    sVar6 = FUN_10005104((int)param_2);
    if (((short)param_1 != sVar6) && (FUN_1000f4e8((int)puVar4,0x133,local_120), param_3 != 1)) {
      uVar7 = FUN_10005104((int)param_2);
      iVar9 = FUN_100036bc(local_120,(byte)uVar7);
      if (iVar9 != 0) {
        uVar15 = 0x418;
        goto LAB_1000d09c;
      }
    }
  }
LAB_1000d13d:
  bVar5 = FUN_100050e8((int)param_2);
  pcVar8 = local_c;
  if (CONCAT31(extraout_var_02,bVar5) == 0) {
    if (local_8 == 0xffffffff) {
      return 0xffffffff;
    }
    pcVar13 = local_c;
    if (local_c == (char *)0x0) {
      pcVar13 = local_120;
    }
    iVar9 = FUN_10003563(pcVar13);
    if (iVar9 == 0) {
      pcVar13 = pcVar8;
      if (pcVar8 == (char *)0x0) {
        pcVar13 = local_120;
      }
      iVar9 = FUN_1000f517(pcVar13,&local_1c);
      if (iVar9 == -1) {
        if (pcVar8 == (char *)0x0) {
          pcVar8 = local_120;
        }
        FUN_1000f4e8((int)puVar4,0x131,pcVar8);
        return 0xffffffff;
      }
      piVar14 = param_2 + 4;
      piVar1 = param_2 + 5;
      piVar2 = param_2 + 6;
      piVar3 = param_2 + 7;
      param_2 = piVar14;
      iVar9 = FUN_100011d7(*piVar14,*piVar1,*piVar2,*piVar3,local_1c,iStack_18,iStack_14,iStack_10);
      if (iVar9 != 0) {
        return local_8;
      }
      pcVar8 = local_c;
      if (local_c == (char *)0x0) {
        pcVar8 = local_120;
      }
      FUN_1000f4e8((int)puVar4,0x132,pcVar8);
      if (param_3 != 2) {
        if (param_3 != 3) {
          return 0xffffffff;
        }
        *param_2 = local_1c;
        param_2[1] = iStack_18;
        param_2[2] = iStack_14;
        param_2[3] = iStack_10;
        return local_8;
      }
      FUN_10005747(puVar4[0xc],local_224);
      return local_8;
    }
    pcVar13 = pcVar8;
    if (pcVar8 == (char *)0x0) {
      pcVar13 = local_120;
    }
    FUN_1000f4e8((int)puVar4,0x130,pcVar13);
    if (param_3 != 2) {
      if (param_3 != 3) {
        return 0xffffffff;
      }
      if (pcVar8 != (char *)0x0) {
        mrbSetLocation((int)puVar4,local_224,(char *)0x0);
      }
      FUN_10005747(puVar4[0xc],local_224);
      if (pcVar8 != (char *)0x0) {
        return 0;
      }
      puVar10 = FUN_1000d46c(puVar4,local_120,&DAT_10018c80);
      if (puVar10 == (undefined4 *)0x0) {
        return 0;
      }
      puVar10 = FUN_1000540b((undefined4 *)puVar4[0xc],local_224,puVar10);
      puVar4[0xc] = puVar10;
      return 0;
    }
    if (pcVar8 != (char *)0x0) {
      mrbSetLocation((int)puVar4,local_224,(char *)0x0);
    }
LAB_1000d32b:
    FUN_10005747(puVar4[0xc],local_224);
    return 0;
  }
  if (local_8 == 0) {
    pcVar13 = local_c;
    if (local_c == (char *)0x0) {
      pcVar13 = local_120;
    }
    iVar9 = FUN_10003563(pcVar13);
    if (iVar9 == 0) {
      pcVar13 = pcVar8;
      if (pcVar8 == (char *)0x0) {
        pcVar13 = local_120;
      }
      FUN_1000f4e8((int)puVar4,0x12f,pcVar13);
      if (param_3 == 2) {
        if (pcVar8 != (char *)0x0) {
          mrbSetLocation((int)puVar4,local_224,(char *)0x0);
        }
        FUN_10005747(puVar4[0xc],local_224);
      }
      else {
        if (param_3 == 3) {
          if (pcVar8 != (char *)0x0) {
            mrbSetLocation((int)puVar4,local_224,(char *)0x0);
          }
          FUN_10005747(puVar4[0xc],local_224);
          if (pcVar8 != (char *)0x0) goto LAB_1000d25c;
          local_8 = FUN_1000f517(local_120,&local_1c);
          if (local_8 == 0) {
            puVar10 = FUN_10004f89(local_1c,iStack_18,iStack_14,iStack_10,0x13,0,0,0);
            puVar10 = FUN_1000540b((undefined4 *)puVar4[0xc],local_224,puVar10);
            puVar4[0xc] = puVar10;
            goto LAB_1000d25c;
          }
          FUN_1000f4e8((int)puVar4,0x12d,local_120);
        }
        local_8 = 0xffffffff;
      }
    }
  }
LAB_1000d25c:
  iVar9 = 0;
  if (0 < (short)param_2[1]) {
    do {
      pcVar8 = _strdup((char *)**(undefined4 **)(param_2[2] + iVar9 * 4));
      uVar11 = FUN_1000cec5(puVar4,*(int **)(param_2[2] + iVar9 * 4),param_3);
      local_8 = local_8 | uVar11;
      puVar10 = *(undefined4 **)(param_2[2] + iVar9 * 4);
      if ((puVar10 != (undefined4 *)0x0) && (iVar12 = strcmp((char *)*puVar10,pcVar8), iVar12 == 0))
      {
        iVar9 = iVar9 + 1;
      }
      free(pcVar8);
    } while (iVar9 < (short)param_2[1]);
  }
  return local_8;
}



/* VA 1000d46c */

undefined4 * __cdecl FUN_1000d46c(undefined4 *param_1,char *param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  char local_220 [260];
  char local_11c [260];
  undefined4 local_18;
  int iStack_14;
  undefined4 uStack_10;
  int iStack_c;
  undefined4 *local_8;

  pcVar3 = param_3;
  iVar1 = FUN_1000d6d3(param_1,param_2,param_3);
  if (iVar1 != 0) {
    strcpy(local_11c,param_2);
    strcpy(local_220,param_2);
    sVar2 = strlen(pcVar3);
    if (sVar2 != 0) {
      strcat(local_220,&DAT_10017148);
      strcat(local_220,pcVar3);
      strcat(local_11c,&DAT_10017064);
      strcat(local_11c,pcVar3);
    }
    pcVar3 = strchr(local_11c,0x2f);
    while (pcVar3 != (char *)0x0) {
      *pcVar3 = '\\';
      pcVar3 = strchr(local_11c,0x2f);
    }
    while (pcVar3 = strchr(local_220,0x5c), pcVar3 != (char *)0x0) {
      *pcVar3 = '/';
    }
    strcat(local_220,&DAT_10017148);
    FUN_1000f4e8((int)param_1,0xcc,local_220);
    puVar4 = FUN_10002699(local_11c,(size_t *)&param_3);
    local_8 = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      qsort(puVar4,(size_t)param_3,4,(_PtFuncCompare *)&LAB_100066a9);
      puVar7 = FUN_10004f51((char *)0x0,(size_t)param_3);
      param_2 = (char *)0x0;
      if (0 < (int)param_3) {
        do {
          puVar8 = FUN_1000d46c(param_1,local_11c,(char *)*puVar4);
          if (puVar8 != (undefined4 *)0x0) {
            *(undefined4 **)(puVar7[2] + *(short *)(puVar7 + 1) * 4) = puVar8;
            *(short *)(puVar7 + 1) = *(short *)(puVar7 + 1) + 1;
            pcVar3 = _strdup((char *)*puVar4);
            *puVar8 = pcVar3;
            puVar8[3] = puVar7;
          }
          param_2 = param_2 + 1;
          puVar4 = puVar4 + 1;
        } while ((int)param_2 < (int)param_3);
      }
      FUN_10002809(local_8,(int)param_3);
      return puVar7;
    }
    iVar1 = FUN_1000f517(local_11c,&local_18);
    if (iVar1 != -1) {
      uVar5 = FUN_100033f1(local_11c);
      uVar9 = (int)uVar5 >> 0x1f;
      if (((uVar5 & uVar9) != 0xffffffff) &&
         (iVar1 = FUN_10003685(local_11c,(ushort *)&param_2), iVar1 != -1)) {
        iVar1 = 0;
        uVar6 = FUN_1000d69f((uint)param_2);
        puVar4 = FUN_10004f89(local_18,iStack_14,uStack_10,iStack_c,(short)uVar6,uVar5,uVar9,iVar1);
        return puVar4;
      }
    }
    FUN_1000f4e8((int)param_1,0x3f7,local_11c);
  }
  return (undefined4 *)0x0;
}



/* VA 1000d69f */

uint __cdecl FUN_1000d69f(uint param_1)

{
  uint uVar1;

  if (DAT_100183f8 != 0) {
    return param_1;
  }
  uVar1 = param_1 & 1;
  if ((param_1 & 2) != 0) {
    uVar1 = (uint)(byte)((byte)uVar1 | 2);
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  return uVar1;
}



/* VA 1000d6d3 */

undefined4 __cdecl FUN_1000d6d3(undefined4 *param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;

  sVar1 = strlen((char *)*param_1);
  param_2 = param_2 + sVar1;
  if (*param_2 == '\\') {
    param_2 = param_2 + 1;
  }
  iVar2 = _stricmp(param_3,s__castanet_10018488);
  if (iVar2 != 0) {
    sVar1 = strlen(s__castanet_10018488);
    iVar2 = _strnicmp(param_3,s__castanet_10018488,sVar1);
    if (((iVar2 != 0) || (sVar1 = strlen(s__castanet_10018488), param_3[sVar1] != '.')) &&
       (iVar2 = _stricmp(param_3,s_plugin_10018480), iVar2 != 0)) {
      if ((code *)param_1[0x39] != (code *)0x0) {
        uVar3 = (*(code *)param_1[0x39])(param_1[0x20],param_2,param_3);
        return uVar3;
      }
      return 1;
    }
  }
  return 0;
}



/* VA 1000d766 */

uint __cdecl mrbIsUpdateAvailable(byte *param_1,undefined4 *param_2)

{
  uint uVar1;

                    /* 0xd766  37  mrbIsUpdateAvailable */
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  param_1[0xa0] = 1;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  uVar1 = mrbUpdate(param_1,0,0);
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  if (uVar1 == 0) {
    *param_2 = *(undefined4 *)(param_1 + 0xa4);
    uVar1 = (uint)(*(int *)(param_1 + 0xa4) != 0);
  }
  return uVar1;
}



/* VA 1000d7ae */

int __cdecl mrbUpdate(byte *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  HANDLE hEvent;
  byte *pbVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  undefined4 uVar9;
  undefined4 uVar10;

                    /* 0xd7ae  56  mrbUpdate */
  pbVar2 = param_1;
  iVar4 = *(int *)(param_1 + 0x88);
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  if (iVar4 == 0) {
    bVar3 = mrbIsPrepareNeeded((int)param_1);
    if (CONCAT31(extraout_var,bVar3) != 0) {
      return -1;
    }
    bVar3 = mrbIsRepairNeeded((int)param_1);
    if ((CONCAT31(extraout_var_00,bVar3) != 0) &&
       (iVar4 = mrbRepair((undefined4 *)param_1), iVar4 == -1)) {
      return -1;
    }
  }
  iVar4 = FUN_1000daff((char *)param_1);
  if (iVar4 != 0) {
    return -1;
  }
  *(int *)(param_1 + 0x68) = param_2;
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x6c) = param_3;
  }
  if (*(undefined4 **)(param_1 + 0x28) != (undefined4 *)0x0) {
    FUN_10003cf6(*(undefined4 **)(param_1 + 0x28));
  }
  pcVar5 = (char *)FUN_10006a31(*(int **)(param_1 + 0x2c),s_http_proxy_100184b0,0);
  pcVar6 = (char *)FUN_10006a31(*(int **)(param_1 + 0x2c),s_socks_proxy_100184a4,0);
  puVar7 = FUN_10003be8(*(char **)(param_1 + 0x60),pcVar5,*(undefined4 *)(param_1 + 0xc4),pcVar6,
                        *(undefined4 *)(param_1 + 0x94),*(undefined4 *)(param_1 + 0x80));
  *(undefined4 **)(param_1 + 0x28) = puVar7;
  if (puVar7 == (undefined4 *)0x0) {
    uVar10 = 0;
    uVar9 = 0x41b;
    goto LAB_1000d9a5;
  }
  if (*(int *)(param_1 + 0x88) == 0) {
    if (*(undefined4 **)(param_1 + 0x30) != (undefined4 *)0x0) {
      FUN_100050a3(*(undefined4 **)(param_1 + 0x30));
    }
    puVar7 = FUN_1000ccbc((int)param_1,*(char **)(param_1 + 0x10));
    *(undefined4 **)(param_1 + 0x30) = puVar7;
    if (puVar7 == (undefined4 *)0x0) {
      return -1;
    }
    FUN_1000511f((int)puVar7);
    if (*(undefined4 **)(param_1 + 0xb0) != (undefined4 *)0x0) {
      FUN_100050a3(*(undefined4 **)(param_1 + 0xb0));
      param_1[0xb0] = 0;
      param_1[0xb1] = 0;
      param_1[0xb2] = 0;
      param_1[0xb3] = 0;
    }
  }
  if ((*(int *)(param_1 + 0xa0) == 0) && (*(int *)(param_1 + 0x88) == 0)) {
    pcVar5 = (char *)FUN_1000da35();
    mrbSetProperty((int)param_1,s_request_time_10018494,pcVar5);
    free(pcVar5);
  }
  FUN_1000da13((int)param_1);
  param_1[0xf4] = 0;
  param_1[0xf5] = 0;
  param_1[0xf6] = 0;
  param_1[0xf7] = 0;
  param_1[0x98] = 1;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  WSASetBlockingHook((FARPROC)&LAB_1000da6d);
  TlsSetValue(DAT_10018d54,param_1 + 0x9c);
  FUN_1000da24((int)param_1);
  pbVar8 = (byte *)FUN_10006a92(param_1);
  if (pbVar8 == (byte *)0x0) {
    piVar1 = *(int **)(param_1 + 0xf0);
    param_1[0x90] = 1;
    param_1[0x91] = 0;
    param_1[0x92] = 0;
    param_1[0x93] = 0;
    if (piVar1 != (int *)0x0) {
      FUN_10003757(piVar1);
      param_1[0xf0] = 0;
      param_1[0xf1] = 0;
      param_1[0xf2] = 0;
      param_1[0xf3] = 0;
    }
  }
  if (*(int *)(param_1 + 0xa0) == 0) {
    if (*(int *)(param_1 + 0x88) != 0) goto LAB_1000d9cf;
    iVar4 = FUN_100024a5(*(undefined4 *)(param_1 + 0x20));
    if (((iVar4 != 0) && (*(int *)(param_1 + 0x90) != 0)) &&
       (iVar4 = FUN_100025ea(*(char **)(param_1 + 0x20)), iVar4 == -1)) {
      uVar10 = *(undefined4 *)(param_1 + 0x20);
      uVar9 = 0x3ff;
LAB_1000d9a5:
      FUN_1000f4e8((int)param_1,uVar9,uVar10);
      return -1;
    }
    iVar4 = FUN_1000da86((int)param_1);
    if (iVar4 == -1) {
      uVar10 = *(undefined4 *)(param_1 + 0xc);
      uVar9 = 0x3f8;
      goto LAB_1000d9a5;
    }
    param_1[200] = 0;
    param_1[0xc9] = 0;
    param_1[0xca] = 0;
    param_1[0xcb] = 0;
  }
  if ((*(int *)(param_1 + 0x88) == 0) && (pbVar8 == (byte *)0x0)) {
    FUN_1000ca3d(*(int **)(param_1 + 100));
  }
LAB_1000d9cf:
  FUN_1000da13((int)param_1);
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  WSAUnhookBlockingHook();
  if (*(int *)(param_1 + 0x9c) != 0) {
    hEvent = *(HANDLE *)(param_1 + 0x110);
    param_1[0x9c] = 0;
    param_1[0x9d] = 0;
    param_1[0x9e] = 0;
    param_1[0x9f] = 0;
    SetEvent(hEvent);
    param_1 = (byte *)0xfffffffe;
    pbVar8 = param_1;
  }
  param_1 = pbVar8;
  FUN_1000da24((int)pbVar2);
  return (int)param_1;
}



/* VA 1000da13 */

void __cdecl FUN_1000da13(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return;
}



/* VA 1000da24 */

void __cdecl FUN_1000da24(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return;
}



/* VA 1000da35 */

void FUN_1000da35(void)

{
  char local_30 [32];
  undefined4 local_10;
  ushort local_c;

  ftime(&local_10);
  sprintf(local_30,s__d_03d_100184bc,local_10,(uint)local_c);
  _strdup(local_30);
  return;
}



/* VA 1000da86 */

undefined4 __cdecl FUN_1000da86(int param_1)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_10006488(*(int **)(param_1 + 0x2c),*(int **)(param_1 + 0xc));
  if (iVar1 == 0) {
    if ((*(int **)(param_1 + 0xdc) == (int *)0x0) ||
       (iVar1 = FUN_10006488(*(int **)(param_1 + 0xe0),*(int **)(param_1 + 0xdc)), iVar1 == 0)) {
      if (*(int *)(param_1 + 0xec) != 0) {
        iVar1 = FUN_1000ce3b(param_1,*(int *)(param_1 + 0x30),*(char **)(param_1 + 0x10));
        if (iVar1 != 0) {
          return 0xffffffff;
        }
        *(undefined4 *)(param_1 + 0xec) = 0;
      }
      return 0;
    }
    uVar2 = *(undefined4 *)(param_1 + 0xdc);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  FUN_1000f4e8(param_1,0x3f3,uVar2);
  return 0xffffffff;
}



/* VA 1000daff */

/* WARNING: Removing unreachable block (ram,0x1000ddbb) */

undefined4 __cdecl FUN_1000daff(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  size_t sVar5;
  long lVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined4 uVar9;
  char local_54 [64];
  undefined8 local_14;
  char *local_c;
  char *local_8;

  pcVar1 = param_1;
  uVar7 = FUN_10006a49(*(int **)(param_1 + 0xe0),&DAT_10018508,0);
  *(undefined8 *)(pcVar1 + 0x70) = uVar7;
  if (*(int *)(pcVar1 + 0x70) == 0 && (int)((ulonglong)uVar7 >> 0x20) == 0) {
    uVar7 = FUN_1000df38(*(char **)(pcVar1 + 8));
    *(undefined8 *)(pcVar1 + 0x70) = uVar7;
    sprintf(local_54,s_0123456789ABCDEF_I64d_10017f40 + 0x10,*(undefined4 *)(pcVar1 + 0x70),
            (int)((ulonglong)uVar7 >> 0x20));
    pcVar2 = _strdup(local_54);
    pcVar3 = _strdup(&DAT_10018508);
    FUN_10006a1c(*(int **)(pcVar1 + 0xe0),(uint)pcVar3,(uint)pcVar2);
  }
  local_14._4_4_ = (char *)FUN_10006a31(*(int **)(pcVar1 + 0x2c),&DAT_10018504,0);
  if (local_14._4_4_ == (char *)0x0) {
    local_8 = (char *)FUN_10006a31(*(int **)(pcVar1 + 0x2c),s_transmitter_100184f8,0);
    local_14._4_4_ = (char *)FUN_10006a31(*(int **)(pcVar1 + 0x2c),s_channel_100184f0,0);
    if (local_8 != (char *)0x0) {
      if (*(void **)(pcVar1 + 0x34) != (void *)0x0) {
        free(*(void **)(pcVar1 + 0x34));
      }
      pcVar2 = _strdup(local_8);
      *(char **)(pcVar1 + 0x34) = pcVar2;
    }
    if (local_14._4_4_ != (char *)0x0) {
      if (*(void **)(pcVar1 + 0x40) != (void *)0x0) {
        free(*(void **)(pcVar1 + 0x40));
      }
      pcVar2 = _strdup(local_14._4_4_);
      *(char **)(pcVar1 + 0x40) = pcVar2;
    }
LAB_1000dce3:
    if (*(int *)(pcVar1 + 0x34) != 0) {
      if ((*(char **)(pcVar1 + 0x40) != (char *)0x0) &&
         (sVar5 = strlen(*(char **)(pcVar1 + 0x40)), sVar5 != 0)) {
        pcVar2 = _strdup(*(char **)(pcVar1 + 0x34));
        *(char **)(pcVar1 + 0x38) = pcVar2;
        pcVar1[0x3c] = 'P';
        pcVar1[0x3d] = '\0';
        pcVar1[0x3e] = '\0';
        pcVar1[0x3f] = '\0';
        param_1 = strchr(*(char **)(pcVar1 + 0x34),0x3a);
        if (param_1 != (char *)0x0) {
          lVar6 = atol(param_1 + 1);
          *(long *)(pcVar1 + 0x3c) = lVar6;
          free(*(void **)(pcVar1 + 0x38));
          pcVar2 = malloc((size_t)(param_1 + (1 - *(int *)(pcVar1 + 0x34))));
          *(char **)(pcVar1 + 0x38) = pcVar2;
          strncpy(pcVar2,*(char **)(pcVar1 + 0x34),(int)param_1 - (int)*(char **)(pcVar1 + 0x34));
          param_1[*(int *)(pcVar1 + 0x38) - *(int *)(pcVar1 + 0x34)] = '\0';
        }
        local_14 = FUN_10006a49(*(int **)(pcVar1 + 0x2c),s_repeater_expiry_100184d0,0);
        local_8 = (char *)FUN_1000ca14(*(undefined4 **)(pcVar1 + 0x54));
        if (local_8 != (char *)0x0) {
          lVar8 = FUN_100086a2();
          if (lVar8 <= local_14) {
            pcVar1[0x50] = 'P';
            pcVar1[0x51] = '\0';
            pcVar1[0x52] = '\0';
            pcVar1[0x53] = '\0';
            param_1 = strchr(local_8,0x3a);
            if (param_1 == (char *)0x0) {
              if (*(void **)(pcVar1 + 0x4c) != (void *)0x0) {
                free(*(void **)(pcVar1 + 0x4c));
              }
              pcVar2 = _strdup(local_8);
              *(char **)(pcVar1 + 0x4c) = pcVar2;
            }
            else {
              lVar6 = atol(param_1 + 1);
              *(long *)(pcVar1 + 0x50) = lVar6;
              if (lVar6 == 0) {
                uVar9 = 0x3e9;
                pcVar2 = local_8;
                goto LAB_1000df27;
              }
              pcVar2 = malloc((size_t)(param_1 + (1 - (int)local_8)));
              *(char **)(pcVar1 + 0x4c) = pcVar2;
              strncpy(pcVar2,local_8,(int)param_1 - (int)local_8);
              param_1[*(int *)(pcVar1 + 0x4c) - (int)local_8] = '\0';
            }
            pcVar1[0x5c] = '\x01';
            pcVar1[0x5d] = '\0';
            pcVar1[0x5e] = '\0';
            pcVar1[0x5f] = '\0';
            goto LAB_1000de90;
          }
        }
        if (*(void **)(pcVar1 + 0x4c) != (void *)0x0) {
          free(*(void **)(pcVar1 + 0x4c));
        }
        pcVar2 = _strdup(*(char **)(pcVar1 + 0x38));
        *(char **)(pcVar1 + 0x4c) = pcVar2;
        *(undefined4 *)(pcVar1 + 0x50) = *(undefined4 *)(pcVar1 + 0x3c);
        mrbSetProperty((int)pcVar1,s_repeaters_100184c4,(char *)0x0);
        mrbSetProperty((int)pcVar1,s_repeater_expiry_100184d0,(char *)0x0);
        pcVar1[0x5c] = '\0';
        pcVar1[0x5d] = '\0';
        pcVar1[0x5e] = '\0';
        pcVar1[0x5f] = '\0';
LAB_1000de90:
        uVar9 = FUN_1000e17f(*(char **)(pcVar1 + 0x40));
        *(undefined4 *)(pcVar1 + 0x44) = uVar9;
        sVar5 = strlen(*(char **)(pcVar1 + 0x40));
        pcVar2 = malloc(sVar5 * 3);
        *pcVar2 = '\0';
        param_1 = _strdup(*(char **)(pcVar1 + 0x40));
        local_8 = param_1;
        while( true ) {
          pcVar3 = strchr(param_1,0x2f);
          if (pcVar3 != (char *)0x0) {
            *pcVar3 = '\0';
          }
          local_14._4_4_ = pcVar3;
          pcVar3 = (char *)FUN_1000e1fd(param_1);
          strcat(pcVar2,pcVar3);
          if (local_14._4_4_ == (char *)0x0) break;
          strcat(pcVar2,&DAT_10017148);
          param_1 = local_14._4_4_ + 1;
        }
        pcVar3 = _strdup(pcVar2);
        *(char **)(pcVar1 + 0x48) = pcVar3;
        free(pcVar2);
        free(local_8);
        return 0;
      }
      pcVar2 = s_channel_100184f0;
LAB_1000df22:
      uVar9 = 0x402;
      goto LAB_1000df27;
    }
    pcVar2 = s_transmitter_100184f8;
  }
  else {
    iVar4 = FUN_10004da8(local_14._4_4_,&local_c,(undefined4 *)(pcVar1 + 0x34),&param_1);
    pcVar2 = local_14._4_4_;
    if (iVar4 == -3) goto LAB_1000df22;
    if ((iVar4 < -2) || (-1 < iVar4)) {
      iVar4 = strcmp(local_c,&DAT_100184e8);
      if ((iVar4 != 0) && (iVar4 = strcmp(local_c,s_https_100184e0), iVar4 != 0)) {
        FUN_1000f4e8((int)pcVar1,0x3ec,local_c);
        free(local_c);
        return 0xffffffff;
      }
      pcVar2 = _strdup(param_1 + 1);
      *(char **)(pcVar1 + 0x40) = pcVar2;
      free(param_1);
      mrbSetProperty((int)pcVar1,s_transmitter_100184f8,*(char **)(pcVar1 + 0x34));
      mrbSetProperty((int)pcVar1,s_channel_100184f0,*(char **)(pcVar1 + 0x40));
      iVar4 = strcmp(local_c,s_https_100184e0);
      if (iVar4 == 0) {
        pcVar2 = &DAT_1001807c;
      }
      else {
        pcVar2 = (char *)0x0;
      }
      mrbSetProperty((int)pcVar1,&DAT_10018084,pcVar2);
      free(local_c);
      goto LAB_1000dce3;
    }
  }
  uVar9 = 0x401;
LAB_1000df27:
  FUN_1000f4e8((int)pcVar1,uVar9,pcVar2);
  return 0xffffffff;
}



/* VA 1000df38 */

undefined8 __cdecl FUN_1000df38(char *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  time_t tVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  _OSVERSIONINFOA local_1e0;
  char local_14c [260];
  _union_530 local_48 [9];
  undefined8 local_24;
  uint local_18;
  uint local_14;
  uint local_10;
  undefined4 local_c;
  DWORD local_8;

  local_8 = 0x40;
  tVar12 = time((time_t *)0x0);
  srand((uint)tVar12);
  iVar3 = rand();
  iVar4 = rand();
  local_18 = (uint)((ulonglong)((longlong)iVar3 * (longlong)iVar4) >> 0x20);
  strcpy(local_14c,s_default_10018528);
  GetUserNameA(local_14c,&local_8);
  uVar5 = FUN_10003b1f(local_14c);
  lVar13 = __allmul(uVar5,(int)uVar5 >> 0x1f,0x1fb5,0);
  local_18 = local_18 ^ (uint)((ulonglong)lVar13 >> 0x20);
  GetWindowsDirectoryA(local_14c,0x104);
  local_c = 8;
  uVar5 = FUN_10003b1f(local_14c);
  lVar14 = __allmul(uVar5,(int)uVar5 >> 0x1f,0xda3,0);
  local_14 = (uint)lVar14;
  local_10 = (uint)((ulonglong)lVar14 >> 0x20);
  bVar1 = (byte)local_c & 0x1f;
  local_10 = local_10 << bVar1 | local_14 >> 0x20 - bVar1;
  local_14 = local_14 << ((byte)local_c & 0x1f);
  GetCurrentDirectoryA(0x104,local_14c);
  local_c = 0x10;
  uVar5 = FUN_10003b1f(local_14c);
  lVar14 = __allmul(uVar5,(int)uVar5 >> 0x1f,0xb51,0);
  local_24._0_4_ = (uint)lVar14;
  local_24._4_4_ = (int)((ulonglong)lVar14 >> 0x20);
  bVar1 = (byte)local_c & 0x1f;
  uVar5 = (uint)local_24 << ((byte)local_c & 0x1f) ^ local_14;
  local_1e0.dwOSVersionInfoSize = 0x94;
  uVar10 = local_18 ^ (local_24._4_4_ << bVar1 | (uint)local_24 >> 0x20 - bVar1) ^ local_10;
  local_24 = lVar14;
  GetVersionExA(&local_1e0);
  pcVar6 = s_Windows_95_100180c0;
  if (local_1e0.dwPlatformId != 1) {
    pcVar6 = s_Windows_NT_100180cc;
  }
  strcpy(local_14c,pcVar6);
  local_c = 0x18;
  uVar7 = FUN_10003b1f(local_14c);
  lVar14 = __allmul(uVar7,(int)uVar7 >> 0x1f,0x14e7,0);
  local_24._0_4_ = (uint)lVar14;
  local_24._4_4_ = (int)((ulonglong)lVar14 >> 0x20);
  bVar1 = (byte)local_c & 0x1f;
  uVar7 = local_24._4_4_ << bVar1;
  uVar2 = (uint)local_24 >> 0x20 - bVar1;
  uVar8 = (uint)local_24 << ((byte)local_c & 0x1f);
  local_24 = lVar14;
  GetSystemInfo((LPSYSTEM_INFO)&local_48[0].s);
  if (local_48[0].s.wProcessorArchitecture == 0) {
    pcVar6 = &DAT_100180e8;
  }
  else if (local_48[0].s.wProcessorArchitecture == 1) {
    pcVar6 = &DAT_1001850c;
  }
  else if (local_48[0].s.wProcessorArchitecture == 2) {
    pcVar6 = s_alpha_10018514;
  }
  else if (local_48[0].s.wProcessorArchitecture == 3) {
    pcVar6 = &DAT_1001851c;
  }
  else {
    pcVar6 = s_unknown_10018520;
  }
  strcpy(local_14c,pcVar6);
  uVar9 = FUN_10003b1f(local_14c);
  lVar14 = __allmul(uVar9,(int)uVar9 >> 0x1f,0,0x16eb);
  uVar9 = FUN_10003b1f(param_1);
  lVar15 = __allmul(uVar9,(int)uVar9 >> 0x1f,0,0x1ca30000);
  lVar16 = FUN_100086a2();
  lVar16 = __allmul((uint)lVar16,(int)((ulonglong)lVar16 >> 0x20),0x1f91,0);
  uVar5 = (uint)((longlong)iVar3 * (longlong)iVar4) ^ (uint)lVar13 ^ uVar5 ^ uVar8 ^ (uint)lVar14 ^
          (uint)lVar15 ^ (uint)lVar16;
  uVar10 = uVar10 ^ (uVar7 | uVar2) ^ (uint)((ulonglong)lVar14 >> 0x20) ^
           (uint)((ulonglong)lVar15 >> 0x20) ^ (uint)((ulonglong)lVar16 >> 0x20);
  if (((int)uVar10 < 1) && ((int)uVar10 < 0)) {
    bVar11 = uVar5 != 0;
    uVar5 = -uVar5;
    uVar10 = -(uVar10 + bVar11);
  }
  return CONCAT44(uVar10,uVar5);
}



/* VA 1000e17f */

void __cdecl FUN_1000e17f(char *param_1)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  size_t sVar4;

  sVar2 = strlen(param_1);
  do {
    sVar4 = sVar2 - 1;
    if ((int)sVar2 < 1) {
      _strdup(param_1);
      return;
    }
    cVar1 = param_1[sVar4];
    sVar2 = sVar4;
  } while (((('`' < cVar1) && (cVar1 < '{')) || (('@' < cVar1 && (cVar1 < '[')))) ||
          ((('/' < cVar1 && (cVar1 < ':')) || (cVar1 == '_'))));
  pcVar3 = _strdup(param_1);
  do {
    pcVar3[sVar4] = '_';
    sVar2 = sVar4;
    do {
      sVar4 = sVar2 - 1;
      if ((int)sVar2 < 1) {
        return;
      }
      cVar1 = pcVar3[sVar4];
      sVar2 = sVar4;
    } while (((('`' < cVar1) && (cVar1 < '{')) || (('@' < cVar1 && (cVar1 < '[')))) ||
            ((('/' < cVar1 && (cVar1 < ':')) || (cVar1 == '_'))));
  } while( true );
}



/* VA 1000e1fd */

void __cdecl FUN_1000e1fd(char *param_1)

{
  char cVar1;
  size_t sVar2;
  void *pvVar3;
  int iVar4;
  uint extraout_EDX;
  uint uVar5;
  int iVar7;
  undefined3 uVar6;

  sVar2 = strlen(param_1);
  pvVar3 = malloc(sVar2 * 3);
  iVar7 = 0;
  iVar4 = 0;
  uVar5 = extraout_EDX;
  if (0 < (int)sVar2) {
    do {
      cVar1 = param_1[iVar7];
      uVar6 = (undefined3)(uVar5 >> 8);
      uVar5 = CONCAT31(uVar6,cVar1);
      if ((((cVar1 < 'A') || ('Z' < cVar1)) && ((cVar1 < 'a' || ('z' < cVar1)))) &&
         ((cVar1 < '0' || ('9' < cVar1)))) {
        if (cVar1 != ' ') {
          if ((((cVar1 != '-') && (cVar1 != '_')) && (cVar1 != '.')) && (cVar1 != '*')) {
            *(undefined1 *)((int)pvVar3 + iVar4) = 0x25;
            *(char *)((int)pvVar3 + iVar4 + 1) =
                 s_0123456789abcdef0123456789ABCDEF_10018400
                 [CONCAT31(uVar6,param_1[iVar7]) >> 4 & 0xf];
            iVar4 = iVar4 + 2;
            uVar5 = (uint)(byte)s_0123456789abcdef0123456789ABCDEF_10018400
                                [(byte)param_1[iVar7] & 0xf];
          }
          goto LAB_1000e289;
        }
        *(undefined1 *)((int)pvVar3 + iVar4) = 0x2b;
      }
      else {
LAB_1000e289:
        *(char *)((int)pvVar3 + iVar4) = (char)uVar5;
      }
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)sVar2);
  }
  *(undefined1 *)((int)pvVar3 + iVar4) = 0;
  return;
}



/* VA 1000e29a */

bool __cdecl mrbIsPrepareNeeded(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;

                    /* 0xe29a  35  mrbIsPrepareNeeded */
  bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0x10));
  return (bool)('\x01' - (CONCAT31(extraout_var,bVar1) != 0));
}



/* VA 1000e2ad */

void __cdecl mrbPrepare(byte *param_1)

{
                    /* 0xe2ad  41  mrbPrepare */
  mrbPrepareEx(param_1,1,0,0);
  return;
}



/* VA 1000e2c0 */

int __cdecl mrbPrepareEx(byte *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  void *pvVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char local_148 [260];
  char local_44 [64];

                    /* 0xe2c0  42  mrbPrepareEx */
  iVar2 = FUN_100025ea(*(char **)(param_1 + 8));
  if ((iVar2 == -1) && (piVar3 = _errno(), *piVar3 != 2)) {
    uVar11 = *(undefined4 *)param_1;
    uVar10 = 0x3ff;
    goto LAB_1000e353;
  }
  if ((((param_1[0x8c] & 8) == 0) ||
      (iVar2 = FUN_100024a5(*(undefined4 *)(param_1 + 4)), iVar2 != 0)) ||
     (iVar2 = FUN_100024b0(*(char **)(param_1 + 4)), iVar2 != -1)) {
    iVar2 = FUN_100024b0(*(char **)(param_1 + 8));
    if (iVar2 != -1) {
      if ((param_1[0x8c] & 8) != 0) {
        iVar2 = FUN_100024b0(*(char **)(param_1 + 0xe8));
        if (iVar2 == -1) {
          uVar11 = *(undefined4 *)(param_1 + 0xe8);
          goto LAB_1000e34e;
        }
      }
      pcVar4 = (char *)FUN_1000da35();
      mrbSetProperty((int)param_1,s_prepare_time_10018570,pcVar4);
      free(pcVar4);
      pvVar5 = (void *)FUN_10006a82(*(int **)(param_1 + 0x2c),s_request_time_10018494);
      if (pvVar5 != (void *)0x0) {
        free(pvVar5);
      }
      pvVar5 = (void *)FUN_10006a82(*(int **)(param_1 + 0x2c),s_update_time_10018564);
      if (pvVar5 != (void *)0x0) {
        free(pvVar5);
      }
      uVar6 = FUN_10006a31(*(int **)(param_1 + 0xe0),&DAT_10018508,0);
      if (uVar6 == 0) {
        uVar9 = FUN_1000df38(*(char **)(param_1 + 8));
        sprintf(local_44,s_0123456789ABCDEF_I64d_10017f40 + 0x10,uVar9);
        pcVar4 = _strdup(local_44);
        pcVar7 = _strdup(&DAT_10018508);
        FUN_10006a1c(*(int **)(param_1 + 0xe0),(uint)pcVar7,(uint)pcVar4);
      }
      puVar1 = *(undefined4 **)(param_1 + 0x30);
      if (param_2 == 1) {
        puVar8 = FUN_10004efe(0);
      }
      else {
        if (param_2 != 2) {
          if (param_2 != 3) {
            return -1;
          }
          param_1[0x88] = 1;
          param_1[0x89] = 0;
          param_1[0x8a] = 0;
          param_1[0x8b] = 0;
          puVar8 = FUN_10004efe(0);
          *(undefined4 **)(param_1 + 0x30) = puVar8;
          iVar2 = mrbUpdate(param_1,param_3,param_4);
          param_1[0x88] = 0;
          param_1[0x89] = 0;
          param_1[0x8a] = 0;
          param_1[0x8b] = 0;
          if (iVar2 != 0) {
            *(undefined4 **)(param_1 + 0x30) = puVar1;
            return -1;
          }
          if ((param_1[0x8c] & 8) != 0) {
            sprintf(local_148,s_0123456789abcdef0123456789ABCDEF_10018400 + 100);
            mrbSetLocation((int)param_1,s_properties_txt_10018554,local_148);
            sprintf(local_148,s__s_parameters_txt_10018540);
            mrbSetLocation((int)param_1,s_parameters_txt_10018530,local_148);
          }
          goto LAB_1000e4e1;
        }
        puVar8 = FUN_1000d46c((undefined4 *)param_1,*(char **)param_1,&DAT_10018c80);
      }
      *(undefined4 **)(param_1 + 0x30) = puVar8;
LAB_1000e4e1:
      iVar2 = FUN_1000da86((int)param_1);
      if (iVar2 == -1) {
        FUN_1000f4e8((int)param_1,0x3f8,*(undefined4 *)(param_1 + 0xc));
        return -1;
      }
      if (puVar1 != (undefined4 *)0x0) {
        FUN_100050a3(puVar1);
      }
      iVar2 = FUN_1000ce3b((int)param_1,*(int *)(param_1 + 0x30),*(char **)(param_1 + 0x10));
      return -(uint)(iVar2 != 0);
    }
    uVar11 = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar11 = *(undefined4 *)(param_1 + 4);
  }
LAB_1000e34e:
  uVar10 = 0x3fe;
LAB_1000e353:
  FUN_1000f4e8((int)param_1,uVar10,uVar11);
  return -1;
}



/* VA 1000e526 */

undefined4 * __cdecl mrbInitUpdate(undefined4 *param_1)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  HANDLE pvVar7;
  undefined4 uVar8;
  char local_118 [260];
  char *local_14;
  size_t local_10;
  char *local_c;
  char *local_8;

                    /* 0xe526  33  mrbInitUpdate */
  if (param_1[1] == 0) {
    return (undefined4 *)0x0;
  }
  if ((char *)*param_1 == (char *)0x0) {
    return (undefined4 *)0x0;
  }
  strcpy(local_118,(char *)*param_1);
  sVar1 = strlen(local_118);
  for (pcVar2 = local_118 + (sVar1 - 1); *pcVar2 == '\\'; pcVar2 = pcVar2 + -1) {
    *pcVar2 = '\0';
  }
  iVar3 = FUN_100024a5(local_118);
  if (iVar3 == 0) {
    uVar8 = param_1[5];
    pcVar2 = s_directory_does_not_exist_10018670;
LAB_1000e59d:
    (*(code *)param_1[1])(0x41a,pcVar2,uVar8);
    return (undefined4 *)0x0;
  }
  if (((*(byte *)(param_1 + 6) & 8) != 0) && (param_1[7] == 0)) {
    uVar8 = param_1[5];
    pcVar2 = s_url_required_for_MULTI_CHANNEL_u_10018648;
    goto LAB_1000e59d;
  }
  puVar4 = malloc(0x118);
  pcVar2 = _strdup(local_118);
  *puVar4 = pcVar2;
  puVar4[9] = param_1[1];
  if ((char *)param_1[4] == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = _strdup((char *)param_1[4]);
  }
  puVar4[0x18] = pcVar2;
  puVar4[0x20] = param_1[5];
  puVar5 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
  puVar4[0xb] = puVar5;
  puVar5 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
  puVar4[0x21] = puVar5;
  puVar5 = FUN_1000c87d(&LAB_1000ed1f,(undefined1 *)0x0);
  puVar4[0x19] = puVar5;
  puVar4[10] = 0;
  puVar4[0x11] = 0;
  puVar4[0x12] = 0;
  puVar4[0xc] = 0;
  puVar4[0x2c] = 0;
  puVar4[0x1e] = 0;
  puVar4[0x1a] = 0;
  puVar4[0x1b] = 0;
  puVar4[0x28] = 0;
  puVar4[0x22] = 0;
  puVar4[0x39] = 0;
  puVar4[0x26] = 0;
  puVar4[0x27] = 0;
  puVar4[0xd] = 0;
  puVar4[0x10] = 0;
  puVar4[0xe] = 0;
  puVar4[0x13] = 0;
  puVar5 = FUN_1000c87d((undefined *)0x0,&LAB_10003b7b);
  puVar4[0x15] = puVar5;
  puVar5 = FUN_1000c87d((undefined *)0x0,&LAB_10003b7b);
  puVar4[0x16] = puVar5;
  puVar4[0x30] = param_1[3];
  puVar4[0x31] = param_1[2];
  puVar4[0x32] = 0;
  uVar8 = param_1[6];
  puVar4[0x35] = 0;
  puVar4[0x23] = uVar8;
  puVar4[0x36] = 0;
  uVar8 = param_1[8];
  puVar4[0x3d] = 0;
  puVar4[0x25] = uVar8;
  puVar4[0x34] = 0;
  puVar4[0x38] = 0;
  puVar4[0x3c] = 0;
  puVar4[0x17] = 0;
  puVar4[0x3b] = 0;
  puVar4[0x44] = 0;
  puVar4[2] = 0;
  puVar4[0x3a] = 0;
  puVar4[1] = 0;
  puVar4[3] = 0;
  puVar4[0x37] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[6] = 0;
  puVar4[7] = 0;
  puVar4[8] = 0;
  if ((char *)param_1[7] != (char *)0x0) {
    iVar3 = FUN_10004da8((char *)param_1[7],&local_8,puVar4 + 0xd,&local_c);
    if (iVar3 == -3) {
      pcVar2 = (char *)param_1[7];
      uVar8 = 0x402;
      goto LAB_1000ebe3;
    }
    if ((-3 < iVar3) && (iVar3 < 0)) {
      pcVar2 = (char *)param_1[7];
      uVar8 = 0x401;
      goto LAB_1000ebe3;
    }
    iVar3 = strcmp(local_8,&DAT_100184e8);
    if ((iVar3 != 0) && (iVar3 = strcmp(local_8,s_https_100184e0), iVar3 != 0)) {
      FUN_1000f4e8((int)puVar4,0x3ec,local_8);
      mrbTermUpdate(puVar4);
      free(local_8);
      return (undefined4 *)0x0;
    }
    pcVar2 = _strdup(local_c + 1);
    puVar4[0x10] = pcVar2;
    free(local_c);
    free(local_8);
  }
  strcpy(local_118,(char *)*param_1);
  strcat(local_118,&DAT_10017064);
  strcat(local_118,s__castanet_10018488);
  pcVar2 = _strdup(local_118);
  puVar4[1] = pcVar2;
  if ((*(byte *)(puVar4 + 0x23) & 8) == 0) {
    pcVar2 = _strdup(local_118);
    puVar4[2] = pcVar2;
    puVar4[0x3a] = 0;
  }
  else {
    local_8 = (char *)FUN_1000e17f((char *)puVar4[0x10]);
    local_c = _strdup((char *)puVar4[0xd]);
    pcVar2 = strchr(local_c,0x3a);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '@';
    }
    strcat(local_118,&DAT_10017064);
    strcat(local_118,local_c);
    strcat(local_118,&DAT_10018644);
    strcat(local_118,local_8);
    free(local_c);
    free(local_8);
    pcVar2 = _strdup(local_118);
    puVar4[2] = pcVar2;
    strcpy(local_118,pcVar2);
    strcat(local_118,s__root_1001863c);
    pcVar2 = _strdup(local_118);
    puVar4[0x3a] = pcVar2;
    strcpy(local_118,(char *)puVar4[1]);
    strcat(local_118,&DAT_10017064);
    strcat(local_118,s_properties_txt_10018554);
    pcVar2 = _strdup(local_118);
    puVar4[0x37] = pcVar2;
    puVar5 = FUN_100036f6(10,0x3f800000,0x10003b7b,FUN_10003b1f);
    puVar4[0x38] = puVar5;
  }
  strcpy(local_118,(char *)puVar4[2]);
  strcat(local_118,&DAT_10017064);
  strcat(local_118,s_properties_txt_10018554);
  pcVar2 = _strdup(local_118);
  puVar4[3] = pcVar2;
  strcpy(local_118,(char *)puVar4[2]);
  strcat(local_118,&DAT_10017064);
  strcat(local_118,s_index_mrb_10018630);
  pcVar2 = _strdup(local_118);
  puVar4[4] = pcVar2;
  strcpy(local_118,(char *)puVar4[2]);
  strcat(local_118,&DAT_10017064);
  strcat(local_118,s_holding_mrb_10018624);
  pcVar2 = _strdup(local_118);
  puVar4[5] = pcVar2;
  strcpy(local_118,(char *)puVar4[2]);
  strcat(local_118,&DAT_10017064);
  strcat(local_118,s_undo_mrb_10018618);
  pcVar2 = _strdup(local_118);
  puVar4[6] = pcVar2;
  strcpy(local_118,(char *)puVar4[2]);
  strcat(local_118,s__undo_10018610);
  pcVar2 = _strdup(local_118);
  puVar4[7] = pcVar2;
  strcpy(local_118,(char *)puVar4[2]);
  strcat(local_118,s__cache_10018608);
  pcVar2 = _strdup(local_118);
  puVar4[8] = pcVar2;
  iVar3 = FUN_1000cb98((int)puVar4);
  if (iVar3 == 0) {
    if ((*(byte *)(puVar4 + 0x23) & 8) == 0) {
      puVar4[0x38] = puVar4[0xb];
    }
    else {
      iVar3 = FUN_100024a5(puVar4[2]);
      if (((iVar3 != 0) && (iVar3 = FUN_100024a5(puVar4[0x3a]), iVar3 == 0)) &&
         (iVar3 = FUN_100024b0((char *)puVar4[0x3a]), iVar3 != 0)) {
        pcVar2 = s_failed_to_create__multi_root_dir_100185c0;
        goto LAB_1000ebde;
      }
    }
    pcVar2 = FUN_1000604b();
    pcVar2 = _strdup(pcVar2);
    pcVar6 = _strdup(&DAT_100185bc);
    FUN_10003881((int *)puVar4[0x21],(uint)pcVar6,(uint)pcVar2);
    pcVar2 = FUN_100060dd();
    pcVar2 = _strdup(pcVar2);
    pcVar6 = _strdup(&DAT_100185b8);
    FUN_10003881((int *)puVar4[0x21],(uint)pcVar6,(uint)pcVar2);
    pcVar2 = _strdup(&DAT_100185b4);
    pcVar6 = _strdup(s_update_sdk_100185a8);
    FUN_10003881((int *)puVar4[0x21],(uint)pcVar6,(uint)pcVar2);
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar4 + 0x3e));
    pvVar7 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,s_marimba_update_10018598);
    puVar4[0x44] = pvVar7;
    if (pvVar7 != (HANDLE)0x0) {
      if (DAT_10018d54 == 0) {
        DAT_10018d54 = TlsAlloc();
      }
      puVar5 = FUN_1000af2d();
      puVar4[0x34] = puVar5;
      if ((puVar5 != (undefined4 *)0x0) &&
         (local_c = (char *)mrbGetProperty((int)puVar4,s_signed_cert_10017f68,0),
         local_c != (char *)0x0)) {
        sVar1 = strlen(local_c);
        FUN_1000b274(puVar4[0x34],(int)local_c,sVar1);
      }
      local_8 = (char *)mrbGetProperty((int)puVar4,s_repeaters_100184c4,0);
      if (local_8 != (char *)0x0) {
        while (local_c = strchr(local_8,0x7c), local_c != (char *)0x0) {
          local_10 = (int)local_c - (int)local_8;
          local_14 = malloc(local_10 + 1);
          strncpy(local_14,local_8,local_10);
          iVar3 = -(int)local_8;
          local_8 = local_c + 1;
          (local_14 + (int)local_c)[iVar3] = '\0';
          FUN_1000c907((int *)puVar4[0x15],local_14);
        }
        if (*local_8 != '\0') {
          pcVar2 = _strdup(local_8);
          FUN_1000c907((int *)puVar4[0x15],pcVar2);
        }
      }
      if ((char *)param_1[7] != (char *)0x0) {
        mrbSetProperty((int)puVar4,&DAT_10018504,(char *)param_1[7]);
        mrbSetProperty((int)puVar4,s_transmitter_100184f8,(char *)puVar4[0xd]);
        mrbSetProperty((int)puVar4,s_channel_100184f0,(char *)puVar4[0x10]);
        return puVar4;
      }
      return puVar4;
    }
    pcVar2 = s_init_synchronization_10018580;
  }
  else {
    pcVar2 = s_failed_to_load_channel_propertie_100185e4;
  }
LAB_1000ebde:
  uVar8 = 0x41a;
LAB_1000ebe3:
  FUN_1000f4e8((int)puVar4,uVar8,pcVar2);
  mrbTermUpdate(puVar4);
  return (undefined4 *)0x0;
}



/* VA 1000ed38 */

void __cdecl mrbTermUpdate(undefined4 *param_1)

{
  int iVar1;

                    /* 0xed38  54  mrbTermUpdate */
  if ((param_1[0x32] != 0) || (param_1[0x3b] != 0)) {
    iVar1 = FUN_1000da86((int)param_1);
    if (iVar1 == -1) {
      FUN_1000f4e8((int)param_1,0x3f8,param_1[3]);
    }
  }
  if ((undefined4 *)param_1[0x34] != (undefined4 *)0x0) {
    FUN_1000b23c((undefined4 *)param_1[0x34]);
  }
  if ((*(byte *)(param_1 + 0x23) & 8) != 0) {
    FUN_10003757((int *)param_1[0x38]);
  }
  if ((HANDLE)param_1[0x44] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x44]);
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x3e));
  }
  FUN_10003757((int *)param_1[0xb]);
  FUN_10003757((int *)param_1[0x21]);
  FUN_1000c8de((int *)param_1[0x19]);
  FUN_1000c8de((int *)param_1[0x15]);
  FUN_1000c8de((int *)param_1[0x16]);
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
  }
  if ((void *)param_1[0x3a] != (void *)0x0) {
    free((void *)param_1[0x3a]);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
  }
  if ((void *)param_1[3] != (void *)0x0) {
    free((void *)param_1[3]);
  }
  if ((void *)param_1[0x37] != (void *)0x0) {
    free((void *)param_1[0x37]);
  }
  if ((void *)param_1[4] != (void *)0x0) {
    free((void *)param_1[4]);
  }
  if ((void *)param_1[6] != (void *)0x0) {
    free((void *)param_1[6]);
  }
  if ((void *)param_1[5] != (void *)0x0) {
    free((void *)param_1[5]);
  }
  if ((void *)param_1[7] != (void *)0x0) {
    free((void *)param_1[7]);
  }
  if ((void *)param_1[8] != (void *)0x0) {
    free((void *)param_1[8]);
  }
  if ((void *)param_1[0xd] != (void *)0x0) {
    free((void *)param_1[0xd]);
  }
  if ((void *)param_1[0x10] != (void *)0x0) {
    free((void *)param_1[0x10]);
  }
  if ((void *)param_1[0xe] != (void *)0x0) {
    free((void *)param_1[0xe]);
  }
  if ((void *)param_1[0x13] != (void *)0x0) {
    free((void *)param_1[0x13]);
  }
  if ((void *)param_1[0x18] != (void *)0x0) {
    free((void *)param_1[0x18]);
  }
  if ((undefined4 *)param_1[10] != (undefined4 *)0x0) {
    FUN_10003cf6((undefined4 *)param_1[10]);
  }
  if ((void *)param_1[0x11] != (void *)0x0) {
    free((void *)param_1[0x11]);
  }
  if ((void *)param_1[0x12] != (void *)0x0) {
    free((void *)param_1[0x12]);
  }
  if ((undefined4 *)param_1[0x2c] != (undefined4 *)0x0) {
    FUN_100050a3((undefined4 *)param_1[0x2c]);
  }
  if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
    FUN_100050a3((undefined4 *)param_1[0xc]);
  }
  if ((int *)param_1[0x3c] != (int *)0x0) {
    FUN_10003757((int *)param_1[0x3c]);
  }
  free(param_1);
  return;
}



/* VA 1000eef7 */

void __cdecl mrbPrintIndex(int param_1)

{
  undefined4 *puVar1;

                    /* 0xeef7  43  mrbPrintIndex */
  if (*(int *)(param_1 + 0x30) == 0) {
    puVar1 = FUN_1000ccbc(param_1,*(char **)(param_1 + 0x10));
    *(undefined4 **)(param_1 + 0x30) = puVar1;
  }
  FUN_10005ee7(*(undefined4 **)(param_1 + 0x30),0);
  return;
}



/* VA 1000ef1e */

undefined4 __cdecl FUN_1000ef1e(int param_1,undefined4 *param_2,char *param_3,int param_4)

{
  int iVar1;
  char *_Filename;
  size_t sVar2;

  iVar1 = FUN_10005266(param_2,param_3);
  if (iVar1 != 0) {
    _Filename = (char *)FUN_1000f916(param_1,*(uint *)(iVar1 + 0x10),*(uint *)(iVar1 + 0x14),
                                     *(uint *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x1c));
    iVar1 = _access(_Filename,0);
    if (iVar1 == 0) {
      sVar2 = strlen(_Filename);
      if (param_4 < (int)sVar2) {
        strncpy(param_3,_Filename,param_4 - 1);
        param_3[param_4 + -1] = '\0';
      }
      else {
        strcpy(param_3,_Filename);
      }
      free(_Filename);
      return 0;
    }
    free(_Filename);
  }
  return 0xffffffff;
}



/* VA 1000efa6 */

undefined4 __cdecl mrbLookupHoldingAreaFile(int param_1,char *param_2,int param_3)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  char local_108 [260];

                    /* 0xefa6  38  mrbLookupHoldingAreaFile */
  sVar1 = strlen(param_2);
  if (sVar1 < 0x104) {
    strcpy(local_108,param_2);
    pcVar2 = local_108;
    while (pcVar2 = strchr(pcVar2,0x5c), pcVar2 != (char *)0x0) {
      *pcVar2 = '/';
      pcVar2 = pcVar2 + 1;
    }
    iVar3 = FUN_1000f06c(param_1);
    if ((iVar3 == 0) &&
       (iVar3 = FUN_1000ef1e(param_1,*(undefined4 **)(param_1 + 0xb0),local_108,0x104), iVar3 == 0))
    {
      sVar1 = strlen(local_108);
      if (param_3 < (int)sVar1) {
        strncpy(param_2,local_108,param_3 - 1);
        param_2[param_3 + -1] = '\0';
      }
      else {
        strcpy(param_2,local_108);
      }
      return 0;
    }
  }
  return 0xffffffff;
}



/* VA 1000f06c */

undefined4 __cdecl FUN_1000f06c(int param_1)

{
  undefined4 *puVar1;

  if (*(int *)(param_1 + 0xb0) == 0) {
    puVar1 = FUN_1000ccbc(param_1,*(char **)(param_1 + 0x14));
    *(undefined4 **)(param_1 + 0xb0) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
  }
  return 0;
}



/* VA 1000f09a */

undefined4 __cdecl mrbBrowseHoldingAreaDir(int param_1,char *param_2,undefined4 *param_3)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  undefined3 extraout_var;
  char local_108 [260];

                    /* 0xf09a  13  mrbBrowseHoldingAreaDir */
  iVar2 = FUN_1000f06c(param_1);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  *(undefined2 *)(param_3 + 3) = 0xffff;
  *param_3 = 0xcafebeef;
  param_3[1] = param_1;
  if (*param_2 == '\0') {
    param_3[2] = *(undefined4 *)(param_1 + 0xb0);
  }
  else {
    strcpy(local_108,param_2);
    pcVar3 = local_108;
    while (pcVar3 = strchr(pcVar3,0x5c), pcVar3 != (char *)0x0) {
      *pcVar3 = '/';
      pcVar3 = pcVar3 + 1;
    }
    iVar2 = FUN_10005266(*(undefined4 **)(param_1 + 0xb0),local_108);
    param_3[2] = iVar2;
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    bVar1 = FUN_100050e8(iVar2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0xffffffff;
    }
  }
  return 0;
}



/* VA 1000f139 */

undefined4 __cdecl mrbNextHoldingAreaFile(int *param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  undefined3 extraout_var;

                    /* 0xf139  39  mrbNextHoldingAreaFile */
  if ((((*param_1 == -0x35014111) && (iVar1 = param_1[2], iVar1 != 0)) &&
      (iVar5 = FUN_1000f06c(param_1[1]), iVar5 == 0)) &&
     ((short)param_1[3] + 1 < (int)*(short *)(iVar1 + 4))) {
    sVar4 = (short)param_1[3] + 1;
    *(short *)(param_1 + 3) = sVar4;
    puVar2 = *(undefined4 **)(*(int *)(iVar1 + 8) + sVar4 * 4);
    bVar3 = FUN_100050e8((int)puVar2);
    *param_2 = (short)CONCAT31(extraout_var,bVar3);
    strcpy((char *)(param_2 + 1),(char *)*puVar2);
    return 0;
  }
  return 0xffffffff;
}



/* VA 1000f19f */

undefined4 __cdecl mrbCancelUpdate(int param_1,DWORD param_2)

{
  int iVar1;
  DWORD DVar2;
  BOOL BVar3;
  tagMSG local_1c;

                    /* 0xf19f  15  mrbCancelUpdate */
  FUN_1000da13(param_1);
  iVar1 = *(int *)(param_1 + 0x98);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x9c) = 1;
  }
  FUN_1000da24(param_1);
  if (iVar1 != 0) {
    while( true ) {
      DVar2 = param_2;
      if (param_2 == 0) {
        DVar2 = 0xffffffff;
      }
      DVar2 = MsgWaitForMultipleObjects(1,(HANDLE *)(param_1 + 0x110),0,DVar2,0xff);
      if (DVar2 != 1) break;
      while (BVar3 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1), BVar3 != 0) {
        DispatchMessageA(&local_1c);
      }
    }
    if (DVar2 == 0) {
      ResetEvent(*(HANDLE *)(param_1 + 0x110));
      return 0;
    }
    if (DVar2 != 0x80) {
      if (DVar2 != 0x102) {
        return 0xffffffff;
      }
      FUN_1000da13(param_1);
      *(undefined4 *)(param_1 + 0x9c) = 0;
      FUN_1000da24(param_1);
      return 1;
    }
    FUN_1000da13(param_1);
    *(undefined4 *)(param_1 + 0x9c) = 0;
    FUN_1000da24(param_1);
  }
  return 2;
}



/* VA 1000f280 */

undefined4 __cdecl mrbAppendLog(int param_1,uint param_2,void *param_3,size_t param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  void *_Dst;
  longlong lVar3;

                    /* 0xf280  12  mrbAppendLog */
  puVar1 = malloc(0x10);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (param_2 == 0xffffffff) {
      lVar3 = FUN_100086a2();
    }
    else {
      *puVar1 = param_2;
      puVar1[1] = (int)param_2 >> 0x1f;
      lVar3 = __allmul(*puVar1,(int)param_2 >> 0x1f,1000,0);
    }
    *(longlong *)puVar1 = lVar3;
    *(short *)(puVar1 + 2) = (short)param_4;
    _Dst = malloc(param_4);
    puVar1[3] = (uint)_Dst;
    memcpy(_Dst,param_3,param_4);
    FUN_1000c907(*(int **)(param_1 + 100),puVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 1000f2f5 */

undefined4 __cdecl mrbSetLocation(int param_1,char *param_2,char *param_3)

{
  bool bVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined4 uVar5;
  void *_Memory;
  char local_310 [520];
  char local_108 [260];

                    /* 0xf2f5  48  mrbSetLocation */
  strcpy(local_108,param_2);
  pcVar2 = local_108;
  while (local_108[0] != '\0') {
    if (*pcVar2 == '\\') {
      *pcVar2 = '/';
    }
    pcVar2 = pcVar2 + 1;
    local_108[0] = *pcVar2;
  }
  if (param_3 == (char *)0x0) {
LAB_1000f372:
    FUN_1000f3cc(local_108,local_310);
    if (param_3 == (char *)0x0) {
      _Memory = (void *)mrbRemoveProperty(param_1,local_310);
      if (_Memory != (void *)0x0) {
        free(_Memory);
      }
    }
    else {
      mrbSetProperty(param_1,local_310,param_3);
    }
    *(undefined4 *)(param_1 + 200) = 1;
    uVar5 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x30) == 0) {
      puVar3 = FUN_1000ccbc(param_1,*(char **)(param_1 + 0x10));
      *(undefined4 **)(param_1 + 0x30) = puVar3;
      if (puVar3 != (undefined4 *)0x0) goto LAB_1000f34d;
    }
    else {
LAB_1000f34d:
      iVar4 = FUN_10005266(*(undefined4 **)(param_1 + 0x30),local_108);
      if ((iVar4 != 0) && (bVar1 = FUN_100050e8(iVar4), CONCAT31(extraout_var,bVar1) == 0))
      goto LAB_1000f372;
    }
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



/* VA 1000f3cc */

void __cdecl FUN_1000f3cc(undefined4 param_1,char *param_2)

{
  char cVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;

  sprintf(param_2,s__s__s_10017fc8,s_reloc_1001868c,param_1);
  sVar2 = strlen(s_reloc_1001868c);
  sVar3 = strlen(param_2);
  iVar4 = sVar3 - 1;
  while (iVar5 = iVar4 + -1, (int)sVar2 < iVar4) {
    cVar1 = param_2[iVar5];
    iVar4 = iVar5;
    if (cVar1 == ' ') {
      param_2[iVar5] = '?';
    }
    else if ((cVar1 == '/') || (cVar1 == '\\')) {
      param_2[iVar5] = '|';
    }
  }
  return;
}



/* VA 1000f424 */

void __cdecl mrbGetLocation(int param_1,char *param_2)

{
  char *pcVar1;
  char local_310 [520];
  char local_108 [260];

                    /* 0xf424  25  mrbGetLocation */
  strcpy(local_108,param_2);
  pcVar1 = local_108;
  while (local_108[0] != '\0') {
    if (*pcVar1 == '\\') {
      *pcVar1 = '/';
    }
    pcVar1 = pcVar1 + 1;
    local_108[0] = *pcVar1;
  }
  FUN_1000f3cc(local_108,local_310);
  mrbGetProperty(param_1,local_310,0);
  return;
}



/* VA 1000f486 */

size_t __cdecl mrbGetMessageText(int param_1,char *param_2,int param_3)

{
  size_t sVar1;

                    /* 0xf486  26  mrbGetMessageText */
  if (*(char **)(param_1 + 0xcc) == (char *)0x0) {
    *param_2 = '\0';
    sVar1 = 0;
  }
  else {
    sVar1 = strlen(*(char **)(param_1 + 0xcc));
    if ((int)sVar1 < param_3) {
      strcpy(param_2,*(char **)(param_1 + 0xcc));
    }
    else {
      strncpy(param_2,*(char **)(param_1 + 0xcc),param_3 - 1);
      param_2[param_3 + -1] = '\0';
    }
  }
  return sVar1;
}



/* VA 1000f4e8 */

undefined4 __cdecl FUN_1000f4e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;

  uVar1 = 0;
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    *(undefined4 *)(param_1 + 0xcc) = param_3;
    uVar1 = (**(code **)(param_1 + 0x24))(param_2,param_3,*(undefined4 *)(param_1 + 0x80));
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  return uVar1;
}



/* VA 1000f517 */

undefined4 __cdecl FUN_1000f517(char *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char local_214 [512];
  undefined4 local_14 [4];

  iVar1 = FUN_10003374(param_1);
  if ((iVar1 != -1) && (iVar2 = FUN_1000bfed(iVar1), iVar2 != 0)) {
    puVar3 = FUN_1000616f(iVar2);
    if (puVar3 != (undefined4 *)0x0) {
      uVar4 = FUN_100033e5(iVar1);
      while( true ) {
        if ((int)uVar4 < 1) {
          puVar6 = (undefined4 *)FUN_10006245(local_14,(int)puVar3);
          *param_2 = *puVar6;
          param_2[1] = puVar6[1];
          param_2[2] = puVar6[2];
          param_2[3] = puVar6[3];
          FUN_100061dc(puVar3);
          return 0;
        }
        uVar5 = 0x200;
        if ((int)uVar4 < 0x201) {
          uVar5 = uVar4;
        }
        uVar5 = FUN_1000636e(puVar3,local_214,uVar5);
        if ((int)uVar5 < 0) break;
        uVar4 = uVar4 - uVar5;
      }
      FUN_100061dc(puVar3);
      return 0xffffffff;
    }
    FUN_100033b9(iVar1);
  }
  return 0xffffffff;
}



/* VA 1000f5bb */

void __cdecl FUN_1000f5bb(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  size_t sVar3;
  char local_70c [256];
  char local_60c [256];
  char local_50c [256];
  char local_40c [260];
  char local_308 [256];
  char local_208 [256];
  char local_108 [260];

  local_108[0] = '\0';
  local_308[0] = '\0';
  _splitpath(param_2,(char *)&param_2,local_70c,local_50c,local_60c);
  while( true ) {
    do {
      strcat(local_308,&DAT_10018694);
      sprintf(local_208,s__s_s_s_10018698,local_308,local_50c,local_60c);
      iVar2 = FUN_10005266(param_3,local_208);
    } while (iVar2 != 0);
    sprintf(local_40c,s__s_s_s_10018698,&param_2,local_70c,local_208);
    bVar1 = FUN_100034b0(local_40c);
    if (CONCAT31(extraout_var,bVar1) == 0) break;
    strcpy(local_108,local_40c);
  }
  sVar3 = strlen(local_108);
  if (sVar3 != 0) {
    _strdup(local_108);
  }
  return;
}



/* VA 1000f6bb */

void __cdecl FUN_1000f6bb(int param_1,char *param_2,undefined4 *param_3)

{
  char *_Memory;
  int iVar1;

  _Memory = (char *)FUN_1000f5bb(param_1,param_2,param_3);
  if (_Memory != (char *)0x0) {
    iVar1 = FUN_10003429(_Memory,param_2);
    if (iVar1 != 0) {
      FUN_1000f4e8(param_1,0x3fd,param_2);
    }
    free(_Memory);
  }
  return;
}



/* VA 1000f703 */

void __cdecl FUN_1000f703(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  bool bVar1;
  char *_Memory;
  int iVar2;
  undefined3 extraout_var;
  char local_50c [256];
  char local_40c [256];
  char local_30c [256];
  char local_20c [260];
  char local_108 [256];
  char local_8 [4];

  _splitpath(param_2,local_8,local_40c,local_50c,local_30c);
  _Memory = FUN_1000352a(param_2);
  if (_Memory == (char *)0x0) {
    sprintf(local_108,s___s_s_100186a4,local_50c,local_30c);
  }
  else {
    sprintf(local_108,&DAT_100186a0,_Memory);
  }
  sprintf(local_20c,s__s_s_s_10018698,local_8,local_40c,local_108);
  if (_Memory != (char *)0x0) {
    free(_Memory);
  }
  iVar2 = FUN_10005266(param_3,local_108);
  if ((iVar2 == 0) && (bVar1 = FUN_100034b0(local_20c), CONCAT31(extraout_var,bVar1) == 0)) {
    _strdup(local_20c);
    return;
  }
  FUN_1000f703(param_1,local_20c,param_3);
  return;
}



/* VA 1000f7fd */

void __cdecl FUN_1000f7fd(undefined4 *param_1,int *param_2)

{
  void *_Memory;
  char *pcVar1;
  char local_108 [260];

  _Memory = (void *)FUN_1000583e(param_2);
  sprintf(local_108,s__s__s_10018478,*param_1,_Memory);
  free(_Memory);
  pcVar1 = local_108;
  while (local_108[0] != '\0') {
    if (*pcVar1 == '/') {
      *pcVar1 = '\\';
    }
    pcVar1 = pcVar1 + 1;
    local_108[0] = *pcVar1;
  }
  _strdup(local_108);
  return;
}



/* VA 1000f863 */

void __cdecl FUN_1000f863(undefined4 *param_1,int param_2,char *param_3)

{
  char *_Str;
  size_t sVar1;
  char local_108 [260];

  if (*(int **)(param_2 + 0xc) == (int *)0x0) {
    sprintf(local_108,s__s__s_10018478,*param_1,param_3);
  }
  else {
    _Str = (char *)FUN_1000f7fd(param_1,*(int **)(param_2 + 0xc));
    sVar1 = strlen(_Str);
    if ((((int)sVar1 < 2) || (_Str[sVar1 - 2] != '\\')) || (_Str[sVar1 - 1] != '.')) {
      sprintf(local_108,s__s__s_10018478,_Str,param_3);
    }
    else {
      strcpy(local_108,_Str);
      strcpy(local_108 + (sVar1 - 1),param_3);
    }
    free(_Str);
  }
  _strdup(local_108);
  return;
}



/* VA 1000f916 */

void __cdecl FUN_1000f916(int param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5)

{
  char *_Source;
  char local_10c [260];
  char local_8;
  char local_7;
  undefined1 local_6;

  local_6 = 0;
  local_8 = s_0123456789abcdef0123456789ABCDEF_10018400[(param_2 & 0xf) + 0x10];
  local_7 = s_0123456789abcdef0123456789ABCDEF_10018400[(param_4 & 0xf) + 0x10];
  strcpy(local_10c,*(char **)(param_1 + 0x20));
  strcat(local_10c,&DAT_10017064);
  strcat(local_10c,&local_8);
  FUN_100024b0(local_10c);
  _Source = FUN_10001203(param_2,param_3,CONCAT44(param_5,param_4));
  strcat(local_10c,&DAT_10017064);
  strcat(local_10c,_Source);
  free(_Source);
  _strdup(local_10c);
  return;
}



/* VA 1000f9da */

void __cdecl FUN_1000f9da(int param_1,int param_2)

{
  size_t sVar1;
  char *_Format;
  char local_10c [260];
  char local_8;
  char local_7;
  undefined1 local_6;

  local_6 = 0;
  local_8 = s_0123456789abcdef0123456789ABCDEF_10018400[(param_2 >> 6 & 7U) + 0x20];
  local_7 = s_0123456789abcdef0123456789ABCDEF_10018400[(param_2 >> 9 & 7U) + 0x20];
  sprintf(local_10c,s__s__s_10018478,*(undefined4 *)(param_1 + 0x1c),&local_8);
  FUN_100024b0(local_10c);
  strcat(local_10c,&DAT_10017064);
  _Format = &DAT_100170c8;
  sVar1 = strlen(local_10c);
  sprintf(local_10c + sVar1,_Format,param_2);
  _strdup(local_10c);
  return;
}



/* VA 1000fa80 */

undefined4 __cdecl FUN_1000fa80(int param_1,char *param_2,char *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  char local_20c [512];
  int *local_c;
  uint *local_8;

  bVar1 = FUN_100034b0(param_2);
  if ((CONCAT31(extraout_var,bVar1) == 0) || (iVar2 = FUN_10003374(param_2), iVar2 < 0)) {
    FUN_1000f4e8(param_1,0x3f4,param_2);
  }
  else {
    uVar3 = FUN_100033e5(iVar2);
    if ((int)uVar3 < 0) {
      uVar7 = 0x3f4;
    }
    else {
      iVar4 = FUN_10003389(param_3);
      if (-1 < iVar4) {
        local_8 = (uint *)FUN_1000bfed(iVar2);
        local_c = (int *)FUN_1000bfed(iVar4);
        do {
          if ((int)uVar3 < 1) {
            uVar7 = 0;
LAB_1000fb5c:
            FUN_1000c00c((int *)local_8);
            FUN_1000c00c(local_c);
            return uVar7;
          }
          uVar5 = uVar3;
          if (0x1ff < (int)uVar3) {
            uVar5 = 0x200;
          }
          uVar5 = FUN_1000c048((int *)local_8,local_20c,uVar5);
          if ((int)uVar5 < 0) {
            uVar3 = FUN_1000c1d1(local_8);
            param_3 = param_2;
            if (uVar3 == 1) {
              uVar7 = 0x3ef;
            }
            else {
              uVar7 = 0x3f7;
            }
LAB_1000fbae:
            FUN_1000f4e8(param_1,uVar7,param_3);
            uVar7 = 0xffffffff;
            goto LAB_1000fb5c;
          }
          iVar2 = FUN_1000c0c5(local_c,local_20c,uVar5);
          if (iVar2 < (int)uVar5) {
            piVar6 = _errno();
            if (*piVar6 == 0x1c) {
              uVar7 = 0x3f8;
            }
            else {
              uVar7 = 0x3f2;
            }
            goto LAB_1000fbae;
          }
          uVar3 = uVar3 - uVar5;
        } while( true );
      }
      uVar7 = 0x3f3;
    }
    FUN_1000f4e8(param_1,uVar7,param_3);
    FUN_100033b9(iVar2);
  }
  return 0xffffffff;
}



/* VA 1000fbbe */

undefined4 __cdecl FUN_1000fbbe(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  char *pcVar5;
  char local_108 [260];

  bVar1 = FUN_100034b0(param_1[6]);
  if ((CONCAT31(extraout_var,bVar1) == 0) || (iVar2 = FUN_1000341d((char *)param_1[6]), iVar2 == 0))
  {
    iVar2 = FUN_100024a5(param_1[7]);
    if ((iVar2 == 0) || (iVar2 = FUN_100025ea((char *)param_1[7]), iVar2 != -1)) {
      iVar2 = FUN_100024a5(param_1[7]);
      if ((iVar2 == 0) && (iVar2 = FUN_100024b0((char *)param_1[7]), iVar2 != 0)) {
        pcVar5 = (char *)param_1[7];
        uVar4 = 0x3fe;
      }
      else {
        param_1[0x1e] = 0;
        piVar3 = FUN_10005dd9(param_2);
        param_1[0x2c] = param_2;
        iVar2 = FUN_1000fdd1(param_1,param_1[0xc],param_2,piVar3);
        if (iVar2 != 0) {
          FUN_1000f4e8((int)param_1,0x3fb,0);
          FUN_10003757(piVar3);
          param_1[0x1f] = param_1[0x1e];
          param_1[0x1e] = 0;
          param_1[0x2d] = param_1[0xc];
          iVar2 = FUN_100108d3(param_1,param_2,param_1[0xc]);
          if (iVar2 != 0) {
            FUN_1000f4e8((int)param_1,0x411,0);
          }
          FUN_1000341d((char *)param_1[5]);
          FUN_100025ea((char *)param_1[7]);
          param_1[0x24] = 0;
          return 0xffffffff;
        }
        param_1[0x2c] = 0;
        FUN_10003757(piVar3);
        iVar2 = FUN_10003429((char *)param_1[4],(char *)param_1[6]);
        pcVar5 = (char *)param_1[4];
        if (iVar2 == 0) {
          iVar2 = FUN_10003429((char *)param_1[5],pcVar5);
          if (iVar2 == 0) {
            FUN_100050a3((undefined4 *)param_1[0xc]);
            param_1[0xc] = param_2;
            param_1[0x1e] = 0;
            if ((*(byte *)(param_1 + 0x23) & 8) != 0) {
              iVar2 = mrbGetLocation((int)param_1,s_properties_txt_10018554);
              if (iVar2 == 0) {
                sprintf(local_108,s_0123456789abcdef0123456789ABCDEF_10018400 + 100,param_1[0x3a]);
                mrbSetLocation((int)param_1,s_properties_txt_10018554,local_108);
              }
              iVar2 = mrbGetLocation((int)param_1,s_parameters_txt_10018530);
              if (iVar2 == 0) {
                sprintf(local_108,s__s_parameters_txt_10018540,param_1[0x3a]);
                mrbSetLocation((int)param_1,s_parameters_txt_10018530,local_108);
              }
            }
            pcVar5 = (char *)FUN_1000da35();
            mrbSetProperty((int)param_1,s_update_time_10018564,pcVar5);
            free(pcVar5);
            FUN_1000da86((int)param_1);
            return 0;
          }
          pcVar5 = (char *)param_1[5];
        }
        uVar4 = 0x3fd;
      }
      goto LAB_1000fd02;
    }
    pcVar5 = (char *)param_1[7];
  }
  else {
    pcVar5 = s_undo_mrb_10018618;
  }
  uVar4 = 0x3ff;
LAB_1000fd02:
  FUN_1000f4e8((int)param_1,uVar4,pcVar5);
  return 0xffffffff;
}



/* VA 1000fdd1 */

undefined4 __cdecl FUN_1000fdd1(undefined4 *param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  short sVar4;
  short sVar5;
  undefined2 uVar6;
  int iVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  LPCSTR _Memory;
  LPCSTR _Memory_00;
  char *pcVar8;
  undefined3 extraout_var_02;
  int local_c;
  int local_8;

  local_c = 0;
  local_8 = 0;
  if (0 < *(short *)(param_2 + 4)) {
    do {
      if (*(short *)(param_3 + 4) <= local_8) break;
      piVar1 = *(int **)(*(int *)(param_2 + 8) + local_c * 4);
      piVar2 = *(int **)(*(int *)(param_3 + 8) + local_8 * 4);
      iVar7 = strcmp((char *)*piVar1,(char *)*piVar2);
      if (iVar7 == 0) {
        bVar3 = FUN_100050e8((int)piVar1);
        if (CONCAT31(extraout_var,bVar3) == 0) {
          bVar3 = FUN_100050e8((int)piVar2);
          if ((CONCAT31(extraout_var_01,bVar3) != 0) ||
             (iVar7 = FUN_10005e7c((int)piVar1,(int)piVar2), iVar7 == 0)) goto LAB_1000fe63;
          if ((*(byte *)(param_1 + 0x23) & 4) != 0) {
            sVar4 = FUN_10005104((int)piVar2);
            sVar5 = FUN_10005104((int)piVar1);
            if (sVar5 != sVar4) {
              _Memory = (LPCSTR)FUN_1000f7fd(param_1,piVar2);
              _Memory_00 = (LPCSTR)FUN_1000583e(piVar2);
              pcVar8 = (char *)mrbGetLocation((int)param_1,_Memory_00);
              if (((pcVar8 != (char *)0x0) &&
                  (bVar3 = FUN_100034b0(_Memory), CONCAT31(extraout_var_02,bVar3) == 0)) &&
                 (iVar7 = FUN_1000fa80((int)param_1,pcVar8,_Memory), iVar7 == -1)) {
LAB_1000ffcd:
                free(_Memory_00);
                return 0xffffffff;
              }
              free(_Memory_00);
              uVar6 = FUN_10005104((int)piVar2);
              iVar7 = FUN_100036bc(_Memory,(byte)uVar6);
              if (iVar7 != 0) {
                FUN_1000f4e8((int)param_1,0x418,_Memory);
                _Memory_00 = _Memory;
                goto LAB_1000ffcd;
              }
              free(_Memory);
            }
          }
        }
        else {
          bVar3 = FUN_100050e8((int)piVar2);
          if (CONCAT31(extraout_var_00,bVar3) == 0) {
LAB_1000fe63:
            iVar7 = FUN_100101b1(param_1,piVar2,param_4);
          }
          else {
            iVar7 = FUN_1000fdd1(param_1,(int)piVar1,(int)piVar2,param_4);
          }
          if (iVar7 != 0) {
            return 0xffffffff;
          }
        }
        local_c = local_c + 1;
LAB_1000ff4d:
        local_8 = local_8 + 1;
      }
      else {
        if (-1 < iVar7) {
          iVar7 = FUN_100101b1(param_1,piVar2,param_4);
          if (iVar7 != 0) {
            return 0xffffffff;
          }
          goto LAB_1000ff4d;
        }
        iVar7 = FUN_1000ffd6(param_1,piVar1);
        if (iVar7 != 0) {
          return 0xffffffff;
        }
        local_c = local_c + 1;
      }
    } while (local_c < *(short *)(param_2 + 4));
  }
  while( true ) {
    if (*(short *)(param_2 + 4) <= local_c) {
      while( true ) {
        if (*(short *)(param_3 + 4) <= local_8) {
          return 0;
        }
        iVar7 = FUN_100101b1(param_1,*(int **)(*(int *)(param_3 + 8) + local_8 * 4),param_4);
        if (iVar7 != 0) break;
        local_8 = local_8 + 1;
      }
      return 0xffffffff;
    }
    iVar7 = FUN_1000ffd6(param_1,*(int **)(*(int *)(param_2 + 8) + local_c * 4));
    if (iVar7 != 0) break;
    local_c = local_c + 1;
  }
  return 0xffffffff;
}



/* VA 1000ffd6 */

undefined4 __cdecl FUN_1000ffd6(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  char *pcVar2;
  LPCSTR pCVar3;
  char *_Str1;
  int iVar4;
  char *_Memory;
  undefined3 extraout_var;
  code *pcVar5;
  undefined4 local_4;

  local_4 = 0;
  param_1[0x1e] = param_1[0x1e] + 1;
  pcVar2 = (char *)FUN_1000583e(param_2);
  mrbSetLocation((int)param_1,pcVar2,(char *)0x0);
  pCVar3 = (LPCSTR)FUN_1000f7fd(param_1,param_2);
  _Str1 = FUN_1000352a(pCVar3);
  pcVar5 = free_exref;
  if ((_Str1 != (char *)0x0) &&
     (iVar4 = strcmp(_Str1,(char *)*param_2), pcVar5 = free_exref, iVar4 != 0)) {
    _Memory = (char *)FUN_100058db(param_2,_Str1);
    iVar4 = FUN_10005266((undefined4 *)param_1[0x2c],_Memory);
    pcVar5 = free_exref;
    if (iVar4 != 0) {
      free(_Str1);
      free(_Memory);
      return 0;
    }
    free(_Memory);
  }
  bVar1 = FUN_100034b0(pCVar3);
  if ((CONCAT31(extraout_var,bVar1) != 0) &&
     (iVar4 = FUN_100100ad((int)param_1,pcVar2,pCVar3,param_1[0x1e],1), iVar4 != 0)) {
    local_4 = 0xffffffff;
  }
  if (_Str1 != (char *)0x0) {
    (*pcVar5)(_Str1);
  }
  (*pcVar5)(pCVar3);
  (*pcVar5)(pcVar2);
  return local_4;
}



/* VA 100100ad */

undefined4 __cdecl FUN_100100ad(int param_1,char *param_2,char *param_3,int param_4,int param_5)

{
  bool bVar1;
  char *_Memory;
  char *pcVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 uVar4;

  uVar4 = 0;
  _Memory = (char *)FUN_1000f9da(param_1,param_4);
  pcVar2 = (char *)mrbGetLocation(param_1,param_2);
  if (pcVar2 != (char *)0x0) {
    pcVar2 = _strdup(pcVar2);
    mrbSetLocation(param_1,param_2,(char *)0x0);
    bVar1 = FUN_100034b0(pcVar2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      iVar3 = FUN_1000fa80(param_1,pcVar2,_Memory);
      if (iVar3 != 0) {
        FUN_1000f4e8(param_1,0x3fc,pcVar2);
        uVar4 = 0xffffffff;
      }
      free(_Memory);
      free(pcVar2);
      return uVar4;
    }
    free(pcVar2);
  }
  if (param_5 == 0) {
    bVar1 = FUN_100034b0(param_3);
    if (CONCAT31(extraout_var_00,bVar1) == 0) goto LAB_100101a0;
    iVar3 = FUN_10003429(param_3,_Memory);
joined_r0x10010177:
    if (iVar3 == 0) goto LAB_100101a0;
    uVar4 = 0x3fd;
  }
  else {
    bVar1 = FUN_100034cc(param_3);
    if (CONCAT31(extraout_var_01,bVar1) != 0) {
      iVar3 = FUN_10003429(param_3,_Memory);
      goto joined_r0x10010177;
    }
    iVar3 = FUN_1000fa80(param_1,param_3,_Memory);
    if (iVar3 == 0) goto LAB_100101a0;
    uVar4 = 0x3fc;
  }
  FUN_1000f4e8(param_1,uVar4,param_3);
  uVar4 = 0xffffffff;
LAB_100101a0:
  free(_Memory);
  return uVar4;
}



/* VA 100101b1 */

int __cdecl FUN_100101b1(undefined4 *param_1,int *param_2,int *param_3)

{
  bool bVar1;
  undefined2 uVar2;
  undefined3 extraout_var;
  int iVar3;
  LPCSTR _Memory;
  char *pcVar4;
  undefined3 extraout_var_00;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  char local_118 [260];
  char *local_14;
  char *local_10;
  char *local_c;
  int local_8;

  iVar7 = 0;
  local_8 = 0;
  bVar1 = FUN_100050e8((int)param_2);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar3 = FUN_1001052f(param_1,param_2);
    if (iVar3 == 0) {
      if ((short)param_2[1] < 1) {
        return local_8;
      }
      while (iVar3 = FUN_100101b1(param_1,*(int **)(param_2[2] + iVar7 * 4),param_3), iVar3 == 0) {
        iVar7 = iVar7 + 1;
        if ((short)param_2[1] <= iVar7) {
          return local_8;
        }
      }
    }
    return -1;
  }
  local_c = (char *)FUN_1000583e(param_2);
  FUN_1000f4e8((int)param_1,0x6a,local_c);
  local_14 = (char *)FUN_1000f916((int)param_1,param_2[4],param_2[5],param_2[6],param_2[7]);
  if (((*(byte *)(param_1 + 0x23) & 8) == 0) ||
     ((iVar7 = strcmp(s_properties_txt_10018554,local_c), iVar7 != 0 &&
      (iVar7 = strcmp(s_parameters_txt_10018530,local_c), iVar7 != 0)))) {
    _Memory = (LPCSTR)FUN_1000f7fd(param_1,param_2);
  }
  else {
    sprintf(local_118,s__s__s_10018478,param_1[0x3a],local_c);
    _Memory = _strdup(local_118);
  }
  local_10 = FUN_1000352a(_Memory);
  if ((local_10 == (char *)0x0) || (iVar7 = strcmp((char *)*param_2,local_10), iVar7 == 0)) {
    bVar1 = FUN_100034b0(_Memory);
    if ((CONCAT31(extraout_var_00,bVar1) == 0) ||
       ((iVar7 = FUN_10005266((undefined4 *)param_1[0xc],local_c), iVar7 != 0 ||
        ((*(byte *)(param_1 + 0x23) & 1) != 0)))) goto LAB_1001036f;
    pcVar4 = (char *)FUN_1000f703(param_1,_Memory,(undefined4 *)param_2[3]);
    iVar7 = FUN_10003429(_Memory,pcVar4);
    if (iVar7 != 0) {
      FUN_1000f4e8((int)param_1,0x3fd,_Memory);
      goto LAB_10010367;
    }
  }
  else {
    pcVar4 = (char *)FUN_100058db(param_2,local_10);
    iVar7 = FUN_10005266((undefined4 *)param_1[0xc],pcVar4);
    if ((iVar7 != 0) &&
       (iVar7 = FUN_100100ad((int)param_1,pcVar4,_Memory,param_1[0x1e] + 1,0), iVar7 != 0)) {
LAB_10010367:
      local_8 = -1;
    }
  }
  free(pcVar4);
LAB_1001036f:
  if (local_8 == 0) {
    pcVar4 = _strdup(local_c);
    pcVar5 = strrchr(pcVar4,0x2f);
    if (pcVar5 != (char *)0x0) {
      *pcVar5 = '\0';
      iVar7 = FUN_100024cd((char *)*param_1,pcVar4);
      if (iVar7 != 0) {
        FUN_1000f4e8((int)param_1,0x3fe,pcVar4);
        local_8 = -1;
      }
    }
    free(pcVar4);
    if (local_8 == 0) {
      uVar6 = FUN_1000378d(param_3,param_2);
      if (uVar6 == 0) {
        iVar7 = FUN_100104c2((int)param_1,local_c,local_14,_Memory);
      }
      else {
        iVar7 = FUN_10010456((int)param_1,local_c,local_14,_Memory);
      }
      if (iVar7 != 0) {
        local_8 = -1;
      }
      if ((local_8 == 0) && ((*(byte *)(param_1 + 0x23) & 4) != 0)) {
        uVar2 = FUN_10005104((int)param_2);
        iVar7 = FUN_100036bc(_Memory,(byte)uVar2);
        if (iVar7 != 0) {
          FUN_1000f4e8((int)param_1,0x418,_Memory);
          local_8 = -1;
        }
      }
    }
  }
  if (local_10 != (char *)0x0) {
    free(local_10);
  }
  free(local_14);
  free(_Memory);
  free(local_c);
  return local_8;
}



/* VA 10010456 */

undefined4 __cdecl FUN_10010456(int param_1,char *param_2,char *param_3,char *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;

  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;
  bVar1 = FUN_100034b0(param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_100034b0(param_4);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      return 0;
    }
  }
  else {
    iVar2 = FUN_100100ad(param_1,param_2,param_4,*(int *)(param_1 + 0x78),0);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iVar2 = FUN_1000fa80(param_1,param_3,param_4);
    if (iVar2 == 0) {
      return 0;
    }
  }
  FUN_1000f4e8(param_1,0x3fc,param_4);
  return 0xffffffff;
}



/* VA 100104c2 */

undefined4 __cdecl FUN_100104c2(int param_1,char *param_2,char *param_3,char *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;

  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;
  bVar1 = FUN_100034b0(param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_100034b0(param_4);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      return 0;
    }
  }
  else {
    iVar2 = FUN_100100ad(param_1,param_2,param_4,*(int *)(param_1 + 0x78),0);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    iVar2 = FUN_10003429(param_3,param_4);
    param_4 = param_3;
    if (iVar2 == 0) {
      return 0;
    }
  }
  FUN_1000f4e8(param_1,0x3fd,param_4);
  return 0xffffffff;
}



/* VA 1001052f */

undefined4 __cdecl FUN_1001052f(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  LPCSTR _Memory;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined3 extraout_var;
  code *pcVar6;

  puVar1 = param_1;
  param_1[0x1e] = param_1[0x1e] + 1;
  _Memory = (LPCSTR)FUN_1000f7fd(param_1,param_2);
  iVar3 = FUN_10003563(_Memory);
  if (iVar3 != 0) {
    param_1 = (undefined4 *)0x0;
    pcVar4 = FUN_1000352a(_Memory);
    if (pcVar4 != (char *)0x0) {
      iVar3 = strcmp(pcVar4,(char *)*param_2);
      if (iVar3 != 0) {
        pcVar5 = (char *)FUN_1000f863(puVar1,(int)param_2,pcVar4);
        iVar3 = FUN_10003429(pcVar5,_Memory);
        if (iVar3 != 0) {
          FUN_1000f4e8((int)puVar1,0x3fd,pcVar5);
          param_1 = (undefined4 *)0xffffffff;
        }
        free(pcVar5);
      }
      if (pcVar4 != (char *)0x0) {
        free(pcVar4);
      }
    }
    free(_Memory);
    return param_1;
  }
  bVar2 = FUN_100034b0(_Memory);
  if (CONCAT31(extraout_var,bVar2) == 0) {
LAB_10010647:
    iVar3 = FUN_100024b0(_Memory);
    if (iVar3 == 0) {
      free(_Memory);
      return 0;
    }
    FUN_1000f4e8((int)param_1,0x3fe,_Memory);
    free(_Memory);
  }
  else {
    pcVar4 = (char *)FUN_1000583e(param_2);
    iVar3 = FUN_10005266((undefined4 *)param_1[0xc],pcVar4);
    if ((iVar3 == 0) && ((*(byte *)(param_1 + 0x23) & 1) == 0)) {
      pcVar5 = (char *)FUN_1000f703(param_1,_Memory,(undefined4 *)param_2[3]);
      iVar3 = FUN_10003429(_Memory,pcVar5);
      if (iVar3 == 0) {
        free(pcVar5);
LAB_1001063f:
        free(pcVar4);
        goto LAB_10010647;
      }
      FUN_1000f4e8((int)param_1,0x3fd,_Memory);
      pcVar6 = free_exref;
      free(_Memory);
      free(pcVar4);
      pcVar4 = pcVar5;
    }
    else {
      iVar3 = FUN_100100ad((int)param_1,pcVar4,_Memory,param_1[0x1e],0);
      pcVar6 = free_exref;
      if (iVar3 == 0) goto LAB_1001063f;
      free(_Memory);
    }
    (*pcVar6)(pcVar4);
  }
  return 0xffffffff;
}



/* VA 1001069f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * __cdecl FUN_1001069f(int param_1,char *param_2)

{
  uint uVar1;
  char *pcVar2;
  char local_14 [8];
  uint local_c;
  undefined4 uStack_8;

  uVar1 = *(uint *)(param_1 + 0xb8);
  if (uVar1 < 0x1f4001) {
    if (0xfa000 < uVar1) {
      local_c = uVar1 / 0x19000;
      pcVar2 = s___1fMb_100186d4;
LAB_1001072e:
      uStack_8 = 0;
      sprintf(local_14,pcVar2,(double)local_c * _DAT_10016340);
      goto LAB_10010750;
    }
    if (uVar1 < 0x801) {
      if (0x400 < uVar1) {
        local_c = uVar1 * 10 >> 10;
        pcVar2 = s___1fKb_100186c4;
        goto LAB_1001072e;
      }
      pcVar2 = s__d_bytes_100186b8;
    }
    else {
      pcVar2 = &DAT_100186cc;
    }
  }
  else {
    pcVar2 = &DAT_100186dc;
  }
  sprintf(local_14,pcVar2);
LAB_10010750:
  if (*(uint *)(param_1 + 0xb8) == 0) {
    uVar1 = 100;
  }
  else {
    uVar1 = (uint)(*(int *)(param_1 + 0xbc) * 100) / *(uint *)(param_1 + 0xb8);
  }
  sprintf(param_2,s__d___of__s_100186ac,uVar1,local_14);
  return param_2;
}



/* VA 10010788 */

char * __cdecl FUN_10010788(int param_1,char *param_2)

{
  sprintf(param_2,s__d__d_10017f74,*(undefined4 *)(param_1 + 0xbc),*(undefined4 *)(param_1 + 0xb8));
  return param_2;
}



/* VA 100107af */

int __cdecl FUN_100107af(int param_1,uint param_2)

{
  char *pcVar1;
  int iVar2;
  char local_44 [64];

  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(uint *)(param_1 + 0xb8) = param_2;
  if (0x7ff < param_2) {
    pcVar1 = FUN_1001069f(param_1,local_44);
    iVar2 = FUN_1000f4e8(param_1,0x1391,pcVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if ((*(byte *)(param_1 + 0x8c) & 0x20) == 0) {
    iVar2 = 0;
  }
  else {
    pcVar1 = FUN_10010788(param_1,local_44);
    iVar2 = FUN_1000f4e8(param_1,0x1392,pcVar1);
  }
  return iVar2;
}



/* VA 1001081a */

int __cdecl FUN_1001081a(int param_1,int param_2)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  char local_24 [32];

  if (param_2 != 0) {
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + param_2;
    uVar1 = *(uint *)(param_1 + 0xb8);
    if (uVar1 < *(uint *)(param_1 + 0xbc)) {
      *(uint *)(param_1 + 0xbc) = uVar1;
    }
    if (0x7ff < uVar1) {
      pcVar2 = FUN_1001069f(param_1,local_24);
      iVar3 = FUN_1000f4e8(param_1,0x1393,pcVar2);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((*(byte *)(param_1 + 0x8c) & 0x20) != 0) {
      pcVar2 = FUN_10010788(param_1,local_24);
      iVar3 = FUN_1000f4e8(param_1,0x1392,pcVar2);
      return iVar3;
    }
  }
  return 0;
}



/* VA 1001089b */

undefined4 __cdecl FUN_1001089b(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  char local_24 [32];

  if (*(uint *)(param_1 + 0xb8) < 0x800) {
    uVar2 = 0;
  }
  else {
    pcVar1 = FUN_1001069f(param_1,local_24);
    uVar2 = FUN_1000f4e8(param_1,0x1394,pcVar1);
  }
  return uVar2;
}



/* VA 100108d3 */

undefined4 __cdecl FUN_100108d3(undefined4 *param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  short sVar4;
  short sVar5;
  undefined2 uVar6;
  int iVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  LPCSTR _Memory;
  int local_c;
  int local_8;

  local_c = 0;
  local_8 = 0;
  if (0 < *(short *)(param_3 + 4)) {
    do {
      if (*(short *)(param_2 + 4) <= local_8) break;
      piVar1 = *(int **)(*(int *)(param_3 + 8) + local_c * 4);
      piVar2 = *(int **)(*(int *)(param_2 + 8) + local_8 * 4);
      iVar7 = strcmp((char *)*piVar2,(char *)*piVar1);
      if (iVar7 == 0) {
        bVar3 = FUN_100050e8((int)piVar1);
        if (CONCAT31(extraout_var,bVar3) == 0) {
          bVar3 = FUN_100050e8((int)piVar2);
          if ((CONCAT31(extraout_var_01,bVar3) != 0) ||
             (iVar7 = FUN_10005e7c((int)piVar1,(int)piVar2), iVar7 == 0)) goto LAB_1001095e;
          if ((*(byte *)(param_1 + 0x23) & 4) != 0) {
            sVar4 = FUN_10005104((int)piVar2);
            sVar5 = FUN_10005104((int)piVar1);
            if (sVar5 != sVar4) {
              _Memory = (LPCSTR)FUN_1000f7fd(param_1,piVar1);
              uVar6 = FUN_10005104((int)piVar1);
              iVar7 = FUN_100036bc(_Memory,(byte)uVar6);
              free(_Memory);
              if (iVar7 != 0) {
                FUN_1000f4e8((int)param_1,0x418,_Memory);
                return 0xffffffff;
              }
            }
          }
        }
        else {
          bVar3 = FUN_100050e8((int)piVar2);
          if (CONCAT31(extraout_var_00,bVar3) == 0) {
LAB_1001095e:
            iVar7 = FUN_10010d7d(param_1,piVar1);
          }
          else {
            iVar7 = FUN_100108d3(param_1,(int)piVar2,(int)piVar1);
          }
          if (iVar7 != 0) {
            return 0xffffffff;
          }
        }
        local_c = local_c + 1;
LAB_100109d9:
        local_8 = local_8 + 1;
      }
      else {
        if (iVar7 < 0) {
          iVar7 = FUN_10010a66(param_1,piVar2);
          if (iVar7 != 0) {
            return 0xffffffff;
          }
          goto LAB_100109d9;
        }
        iVar7 = FUN_10010d7d(param_1,piVar1);
        if (iVar7 != 0) {
          return 0xffffffff;
        }
        local_c = local_c + 1;
      }
    } while (local_c < *(short *)(param_3 + 4));
  }
  while( true ) {
    if (*(short *)(param_3 + 4) <= local_c) {
      while( true ) {
        if (*(short *)(param_2 + 4) <= local_8) {
          return 0;
        }
        iVar7 = FUN_10010a66(param_1,*(int **)(*(int *)(param_2 + 8) + local_8 * 4));
        if (iVar7 != 0) break;
        local_8 = local_8 + 1;
      }
      return 0xffffffff;
    }
    iVar7 = FUN_10010d7d(param_1,*(int **)(*(int *)(param_3 + 8) + local_c * 4));
    if (iVar7 != 0) break;
    local_c = local_c + 1;
  }
  return 0xffffffff;
}



/* VA 10010a66 */

undefined4 __cdecl FUN_10010a66(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  char *_Memory;
  char *pcVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 *puVar4;
  undefined3 extraout_var_02;
  int *piVar5;
  void *_Memory_00;
  char local_214 [260];
  char local_110 [260];
  size_t local_c;
  int *local_8;

  local_c = 0;
  if ((0 < (int)param_1[0x1f]) && (param_1[0x1e] == param_1[0x1f])) {
    return 0;
  }
  param_1[0x1e] = param_1[0x1e] + 1;
  _Memory = (char *)FUN_1000583e(param_2);
  FUN_1000f4e8((int)param_1,0x193,_Memory);
  sprintf(local_110,s__s__s_10018478,*param_1,_Memory);
  pcVar2 = local_110;
  while (pcVar2 = strchr(pcVar2,0x2f), pcVar2 != (char *)0x0) {
    *pcVar2 = '\\';
    pcVar2 = pcVar2 + 1;
  }
  bVar1 = FUN_100034b0(local_110);
  if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_10010c6a;
  local_8 = (int *)FUN_1000352a(local_110);
  iVar3 = strcmp((char *)local_8,(char *)*param_2);
  if (iVar3 != 0) {
    free(_Memory);
    return 0;
  }
  free(local_8);
  iVar3 = FUN_10003563(local_110);
  if (((iVar3 != 0) &&
      (local_8 = (int *)FUN_100053f8((undefined4 *)param_1[0x2d],_Memory), local_8 != (int *)0x0))
     && (bVar1 = FUN_100050e8((int)local_8), CONCAT31(extraout_var_00,bVar1) != 0)) {
    local_8 = (int *)FUN_1000f7fd(param_1,local_8);
    iVar3 = FUN_10003429(local_110,(char *)local_8);
    if (iVar3 != 0) {
      FUN_1000f4e8((int)param_1,0x3fd,local_110);
      free(local_8);
      goto LAB_10010cf2;
    }
    free(local_8);
    local_c = 1;
  }
  bVar1 = FUN_100050e8((int)param_2);
  if ((CONCAT31(extraout_var_01,bVar1) != 0) && (local_8 = (int *)0x0, 0 < (short)param_2[1])) {
    do {
      FUN_10010a66(param_1,*(int **)(param_2[2] + (int)local_8 * 4));
      local_8 = (int *)((int)local_8 + 1);
    } while ((int)local_8 < (int)(short)param_2[1]);
  }
  if (local_c != 0) goto LAB_10010d27;
  iVar3 = FUN_10003563(local_110);
  if (iVar3 == 0) {
    bVar1 = FUN_100034cc(local_110);
    if (CONCAT31(extraout_var_02,bVar1) != 0) {
      iVar3 = FUN_1000341d(local_110);
      goto LAB_10010c48;
    }
  }
  else {
    puVar4 = FUN_10002699(local_110,&local_c);
    FUN_10002809(puVar4,local_c);
    if (local_c == 0) {
      iVar3 = FUN_100025ea(local_110);
LAB_10010c48:
      if (iVar3 != 0) {
        FUN_1000f4e8((int)param_1,0x3ff,local_110);
        goto LAB_10010cf2;
      }
    }
  }
LAB_10010c6a:
  pcVar2 = _Memory;
  piVar5 = (int *)FUN_100053f8((undefined4 *)param_1[0x2d],_Memory);
  if (piVar5 == (int *)0x0) {
    if ((*(byte *)(param_1 + 0x23) & 1) == 0) {
      FUN_1000f6bb((int)param_1,local_110,(undefined4 *)param_2[3]);
    }
  }
  else {
    FUN_10010d31(pcVar2,(int)param_1,param_1[0x1e],local_214);
    pcVar2 = (char *)FUN_1000f7fd(param_1,piVar5);
    _Memory_00 = (void *)FUN_1000583e(piVar5);
    FUN_1000f4e8((int)param_1,400,_Memory_00);
    free(_Memory_00);
    iVar3 = FUN_10003429(local_214,pcVar2);
    if (iVar3 != 0) {
      FUN_1000f4e8((int)param_1,0x3fd,local_214);
      free(_Memory);
      _Memory = pcVar2;
LAB_10010cf2:
      free(_Memory);
      return 0xffffffff;
    }
    free(_Memory);
    _Memory = pcVar2;
  }
LAB_10010d27:
  free(_Memory);
  return 0;
}



/* VA 10010d31 */

void __thiscall FUN_10010d31(void *this,int param_1,int param_2,char *param_3)

{
  undefined4 local_8;

  local_8._0_2_ =
       CONCAT11(s_0123456789abcdef0123456789ABCDEF_10018400[(param_2 >> 9 & 7U) + 0x30],
                s_0123456789abcdef0123456789ABCDEF_10018400[(param_2 >> 6 & 7U) + 0x30]);
  local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
  sprintf(param_3,s__s__s__d_100186e4,*(undefined4 *)(param_1 + 0x1c),&local_8,param_2);
  return;
}



/* VA 10010d7d */

undefined4 __cdecl FUN_10010d7d(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  undefined2 uVar2;
  char *pcVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  undefined4 uVar5;
  void *this;
  char local_310 [260];
  char local_20c [260];
  char local_108 [260];

  if (((int)param_1[0x1f] < 1) || (param_1[0x1e] != param_1[0x1f])) {
    param_1[0x1e] = param_1[0x1e] + 1;
    pcVar3 = (char *)FUN_1000583e(param_2);
    strcpy(local_20c,pcVar3);
    free(pcVar3);
    sprintf(local_108,s__s__s_10018478,*param_1,local_20c);
    pcVar3 = local_108;
    while( true ) {
      this = (void *)0x2f;
      pcVar3 = strchr(pcVar3,0x2f);
      if (pcVar3 == (char *)0x0) break;
      *pcVar3 = '\\';
      pcVar3 = pcVar3 + 1;
    }
    FUN_10010d31(this,(int)param_1,param_1[0x1e],local_310);
    bVar1 = FUN_100034b0(local_310);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0;
    }
    bVar1 = FUN_100034b0(local_108);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      iVar4 = FUN_10003563(local_310);
      if (iVar4 == 0) {
        uVar5 = 400;
      }
      else {
        uVar5 = 0x192;
      }
      FUN_1000f4e8((int)param_1,uVar5,local_20c);
    }
    else {
      FUN_1000f4e8((int)param_1,0x191,local_108);
      iVar4 = FUN_10003563(local_108);
      if (iVar4 == 0) {
        iVar4 = FUN_1000341d(local_108);
      }
      else {
        iVar4 = FUN_100025ea(local_108);
      }
      if (iVar4 != 0) {
        uVar5 = 0x3ff;
        goto LAB_10010f0b;
      }
    }
    iVar4 = FUN_10003429(local_310,local_108);
    if (iVar4 != 0) {
      uVar5 = 0x3fd;
LAB_10010f0b:
      FUN_1000f4e8((int)param_1,uVar5,local_108);
      return 0xffffffff;
    }
    if ((*(byte *)(param_1 + 0x23) & 4) != 0) {
      uVar2 = FUN_10005104((int)param_2);
      iVar4 = FUN_100036bc(local_108,(byte)uVar2);
      if (iVar4 != 0) {
        uVar5 = 0x418;
        goto LAB_10010f0b;
      }
    }
  }
  return 0;
}



/* VA 10010f1f */

undefined4 __cdecl mrbCanUndo(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;

                    /* 0x10f1f  14  mrbCanUndo */
  iVar2 = FUN_100024a5(*(undefined4 *)(param_1 + 0x1c));
  if (iVar2 != 0) {
    bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0x18));
    if (CONCAT31(extraout_var,bVar1) != 0) {
      return 1;
    }
  }
  return 0;
}



/* VA 10010f47 */

undefined4 __cdecl mrbUndo(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;

                    /* 0x10f47  55  mrbUndo */
  iVar1 = mrbCanUndo((int)param_1);
  if (iVar1 == 0) {
    uVar3 = 0x410;
    pcVar4 = (char *)0x0;
  }
  else {
    if (param_1[0xc] == 0) {
      puVar2 = FUN_1000ccbc((int)param_1,(char *)param_1[4]);
      param_1[0xc] = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        return 0xffffffff;
      }
    }
    puVar2 = FUN_1000ccbc((int)param_1,(char *)param_1[6]);
    if (puVar2 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    param_1[0x2d] = puVar2;
    iVar1 = FUN_100108d3(param_1,param_1[0xc],(int)puVar2);
    if (iVar1 == 0) {
      FUN_100050a3(puVar2);
      param_1[0x2d] = 0;
      iVar1 = FUN_1000341d((char *)param_1[4]);
      pcVar4 = (char *)param_1[4];
      if (iVar1 == 0) {
        iVar1 = FUN_10003429((char *)param_1[6],pcVar4);
        if (iVar1 == 0) {
          FUN_100025ea((char *)param_1[7]);
          return 0;
        }
        pcVar4 = (char *)param_1[6];
        uVar3 = 0x3fd;
      }
      else {
        uVar3 = 0x3ff;
      }
    }
    else {
      FUN_100050a3(puVar2);
      param_1[0x2d] = 0;
      pcVar4 = (char *)0x0;
      uVar3 = 0x411;
    }
  }
  FUN_1000f4e8((int)param_1,uVar3,pcVar4);
  return 0xffffffff;
}



/* VA 1001101a */

undefined4 mrbVersion(void)

{
                    /* 0x1101a  59  mrbVersion */
  return 0x40000;
}



/* VA 10011020 */

bool __cdecl mrbIsChannelSigned(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;

                    /* 0x11020  34  mrbIsChannelSigned */
  if (*(int *)(param_1 + 0xd0) != 0) {
    if (*(int *)(param_1 + 0x30) != 0) {
LAB_10011057:
      bVar1 = FUN_1000ba31(*(undefined4 **)(param_1 + 0x30));
      return bVar1;
    }
    bVar1 = FUN_100034b0(*(undefined4 *)(param_1 + 0x10));
    if (CONCAT31(extraout_var,bVar1) != 0) {
      puVar2 = FUN_1000ccbc(param_1,*(char **)(param_1 + 0x10));
      *(undefined4 **)(param_1 + 0x30) = puVar2;
      if (puVar2 != (undefined4 *)0x0) goto LAB_10011057;
    }
  }
  return false;
}



/* VA 10011062 */

undefined4 __cdecl mrbGetSigningScope(int param_1,char *param_2,size_t *param_3)

{
  undefined4 uVar1;

                    /* 0x11062  31  mrbGetSigningScope */
  if (*(int *)(param_1 + 0xd0) == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_1000bd13(*(int *)(param_1 + 0xd0),param_2,param_3);
  return uVar1;
}



/* VA 10011086 */

undefined4 __cdecl mrbGetCertFieldCount(int param_1,int param_2)

{
  undefined4 uVar1;

                    /* 0x11086  21  mrbGetCertFieldCount */
  if (*(int *)(param_1 + 0xd0) == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_1000bade(*(int *)(param_1 + 0xd0),param_2);
  return uVar1;
}



/* VA 100110a5 */

void __cdecl mrbGetCertField(int param_1,int param_2,undefined4 param_3)

{
                    /* 0x110a5  19  mrbGetCertField */
  if (*(int *)(param_1 + 0xd0) == 0) {
    return;
  }
  FUN_1000baf4(*(int *)(param_1 + 0xd0),param_2,param_3);
  return;
}



/* VA 100110c6 */

undefined4 __cdecl
mrbGetCertFieldByIndex
          (int param_1,int param_2,undefined4 param_3,int param_4,int *param_5,int param_6,
          int *param_7)

{
  undefined4 uVar1;

                    /* 0x110c6  20  mrbGetCertFieldByIndex */
  if (*(int *)(param_1 + 0xd0) == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_1000bb92(*(int *)(param_1 + 0xd0),param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar1;
}



/* VA 100110f8 */

undefined4 __cdecl mrbGetCertFingerPrint(int param_1,char *param_2,uint *param_3)

{
  undefined4 uVar1;

                    /* 0x110f8  22  mrbGetCertFingerPrint */
  if (*(int *)(param_1 + 0xd0) == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_1000bc99(*(int *)(param_1 + 0xd0),param_2,param_3);
  return uVar1;
}



/* VA 1001111c */

undefined4 __cdecl mrbGetCertSerialNo(int param_1,char *param_2,uint *param_3)

{
  undefined4 uVar1;

                    /* 0x1111c  24  mrbGetCertSerialNo */
  if (*(int *)(param_1 + 0xd0) == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_1000bbb9(*(int *)(param_1 + 0xd0),param_2,param_3);
  return uVar1;
}



/* VA 10011140 */

undefined4 __cdecl mrbGetCertDates(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;

                    /* 0x11140  18  mrbGetCertDates */
  if (*(int *)(param_1 + 0xd0) == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_1000bce9(*(int *)(param_1 + 0xd0),param_2,param_3);
  return uVar1;
}



/* VA 10011164 */

void __cdecl mrbAcceptTestCertificates(int param_1)

{
                    /* 0x11164  9  mrbAcceptTestCertificates */
  if (*(int *)(param_1 + 0xd0) != 0) {
    FUN_1000bfb4(*(int *)(param_1 + 0xd0));
  }
  return;
}



/* VA 1001117a */

undefined4 __cdecl mrbAddLocalFile(undefined4 *param_1,char *param_2,char *param_3)

{
  undefined2 uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar6;
  undefined4 *puVar7;
  char local_21c [260];
  char local_118 [260];
  undefined4 local_14;
  int iStack_10;
  undefined4 uStack_c;
  int iStack_8;
  uint uVar5;

                    /* 0x1117a  10  mrbAddLocalFile */
  if ((param_2 == (char *)0x0) || (param_3 == (char *)0x0)) {
LAB_10011302:
    uVar6 = 0xffffffff;
  }
  else {
    strcpy(local_118,param_3);
    pcVar2 = local_118;
    while (local_118[0] != '\0') {
      if (*pcVar2 == '\\') {
        *pcVar2 = '/';
      }
      pcVar2 = pcVar2 + 1;
      local_118[0] = *pcVar2;
    }
    if (param_1[0xc] == 0) {
      puVar3 = FUN_1000ccbc((int)param_1,(char *)param_1[4]);
      param_1[0xc] = puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        return 0x400;
      }
    }
    iVar4 = FUN_10005266((undefined4 *)param_1[0xc],local_118);
    if ((iVar4 != 0) && (iVar4 = mrbSetLocation((int)param_1,local_118,param_2), iVar4 != 0)) {
      return 0x3f9;
    }
    iVar4 = FUN_1000f517(param_2,&local_14);
    if (iVar4 != -1) {
      strcpy(local_21c,local_118);
      pcVar2 = strrchr(local_21c,0x2f);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
        iVar4 = FUN_100024cd((char *)*param_1,local_21c);
        if (iVar4 != 0) {
          return 0x3fe;
        }
      }
      uVar1 = 0x13;
      if ((*(byte *)(param_1 + 0x23) & 4) != 0) {
        iVar4 = FUN_10003685(param_2,(ushort *)&param_3);
        if (iVar4 == -1) goto LAB_100112bb;
        uVar5 = FUN_1000d69f((uint)param_3);
        uVar1 = (undefined2)uVar5;
      }
      uVar5 = FUN_100033f1(param_2);
      if ((uVar5 & (int)uVar5 >> 0x1f) != 0xffffffff) {
        puVar3 = FUN_10004f89(local_14,iStack_10,uStack_c,iStack_8,uVar1,uVar5,(int)uVar5 >> 0x1f,0)
        ;
        if (puVar3 != (undefined4 *)0x0) {
          puVar7 = FUN_1000540b((undefined4 *)param_1[0xc],local_118,puVar3);
          param_1[0xc] = puVar7;
          if (puVar7 != (undefined4 *)0x0) {
            param_1[0x3b] = 1;
            uVar6 = mrbSetLocation((int)param_1,local_118,param_2);
            return uVar6;
          }
          FUN_100050a3(puVar3);
        }
        goto LAB_10011302;
      }
    }
LAB_100112bb:
    uVar6 = 0x3f7;
  }
  return uVar6;
}



/* VA 10011329 */

undefined4 __cdecl mrbSetCastanetDirSuffix(undefined4 *param_1,char *param_2)

{
  char *pcVar1;
  char local_108 [260];

                    /* 0x11329  47  mrbSetCastanetDirSuffix */
  if (((param_2 != (char *)0x0) && (pcVar1 = strchr(param_2,0x5c), pcVar1 == (char *)0x0)) &&
     (pcVar1 = strchr(param_2,0x2f), pcVar1 == (char *)0x0)) {
    sprintf(local_108,s__s__s__s_100186f0,*param_1,s__castanet_10018488,param_2);
    free((void *)param_1[2]);
    pcVar1 = _strdup(local_108);
    param_1[2] = pcVar1;
    strcpy(local_108,pcVar1);
    strcat(local_108,&DAT_10017064);
    strcat(local_108,s_properties_txt_10018554);
    free((void *)param_1[3]);
    pcVar1 = _strdup(local_108);
    param_1[3] = pcVar1;
    strcpy(local_108,(char *)param_1[2]);
    strcat(local_108,&DAT_10017064);
    strcat(local_108,s_index_mrb_10018630);
    free((void *)param_1[4]);
    pcVar1 = _strdup(local_108);
    param_1[4] = pcVar1;
    strcpy(local_108,(char *)param_1[2]);
    strcat(local_108,&DAT_10017064);
    strcat(local_108,s_holding_mrb_10018624);
    free((void *)param_1[5]);
    pcVar1 = _strdup(local_108);
    param_1[5] = pcVar1;
    strcpy(local_108,(char *)param_1[2]);
    strcat(local_108,&DAT_10017064);
    strcat(local_108,s_undo_mrb_10018618);
    free((void *)param_1[6]);
    pcVar1 = _strdup(local_108);
    param_1[6] = pcVar1;
    strcpy(local_108,(char *)param_1[2]);
    strcat(local_108,s__undo_10018610);
    free((void *)param_1[7]);
    pcVar1 = _strdup(local_108);
    param_1[7] = pcVar1;
    strcpy(local_108,(char *)param_1[2]);
    strcat(local_108,s__cache_10018608);
    free((void *)param_1[8]);
    pcVar1 = _strdup(local_108);
    param_1[8] = pcVar1;
    return 0;
  }
  return 0xffffffff;
}



/* VA 10011543 */

undefined4 __cdecl mrbSetMaxReceiveRate(int param_1,int param_2)

{
                    /* 0x11543  49  mrbSetMaxReceiveRate */
  if (param_2 < 0) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0xd4) = param_2;
  return 0;
}



/* VA 1001155c */

undefined4 __cdecl mrbSetMaxTransmitRate(int param_1,int param_2)

{
                    /* 0x1155c  50  mrbSetMaxTransmitRate */
  if (param_2 < 0) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 0xd8) = param_2;
  return 0;
}



/* VA 10011575 */

void __cdecl
FUN_10011575(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  char *pcVar6;
  longlong lVar7;
  longlong lVar8;
  char local_110 [260];
  undefined4 local_c;
  int local_8;

  puVar2 = param_1;
  local_8 = 0;
  FUN_1000ca3d((int *)param_1[0x15]);
  free((void *)param_1[0x13]);
  pcVar3 = _strdup((char *)*param_2);
  param_1[0x13] = pcVar3;
  uVar1 = *param_3;
  param_1[0x17] = 1;
  param_1[0x14] = uVar1;
  lVar7 = FUN_100086a2();
  lVar8 = __allmul(param_5,(int)param_5 >> 0x1f,60000,0);
  local_c = (undefined4)((ulonglong)(lVar8 + lVar7) >> 0x20);
  if (0 < param_4) {
    param_5 = param_4;
    param_1 = param_2;
    do {
      sVar4 = strlen((char *)*param_1);
      local_8 = local_8 + sVar4;
      param_1 = param_1 + 1;
      param_5 = param_5 - 1;
    } while (param_5 != 0);
  }
  pcVar3 = malloc((local_8 + param_4) * 2);
  *pcVar3 = '\0';
  param_1 = (undefined4 *)0x0;
  if (0 < param_4) {
    iVar5 = (int)param_3 - (int)param_2;
    do {
      sprintf(local_110,s__s__d_1001717c,*param_2,*(undefined4 *)(iVar5 + (int)param_2));
      strcat(pcVar3,local_110);
      if ((int)param_1 < param_4 + -1) {
        strcat(pcVar3,&DAT_100186fc);
      }
      pcVar6 = _strdup(local_110);
      FUN_1000c907((int *)puVar2[0x15],pcVar6);
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = param_2 + 1;
    } while ((int)param_1 < param_4);
  }
  sprintf(local_110,s_0123456789ABCDEF_I64d_10017f40 + 0x10,(int)(lVar8 + lVar7),local_c);
  mrbSetProperty((int)puVar2,s_repeaters_100184c4,pcVar3);
  mrbSetProperty((int)puVar2,s_repeater_expiry_100184d0,local_110);
  free(pcVar3);
  return;
}



/* VA 100116ea */

undefined4 __cdecl FUN_100116ea(int param_1,int param_2,char *param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  undefined4 uVar5;
  size_t sVar6;
  int iVar7;
  char local_104 [256];

  sprintf(local_104,s__s__d_1001717c,param_2,param_3);
  FUN_1000c98a(*(int **)(param_1 + 0x54),local_104);
  pcVar1 = _strdup(local_104);
  FUN_1000c907(*(int **)(param_1 + 0x58),pcVar1);
  do {
    iVar2 = FUN_1000ca60(*(int *)(param_1 + 0x54));
    if (iVar2 < 1) {
      free(*(void **)(param_1 + 0x4c));
      pcVar1 = _strdup(*(char **)(param_1 + 0x38));
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(char **)(param_1 + 0x4c) = pcVar1;
      *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x3c);
LAB_10011804:
      iVar2 = FUN_1000ca60(*(int *)(param_1 + 0x54));
      iVar7 = 0;
      if (iVar2 < 1) {
        mrbSetProperty(param_1,s_repeaters_100184c4,(char *)0x0);
        mrbSetProperty(param_1,s_repeater_expiry_100184d0,(char *)0x0);
        uVar5 = 0;
      }
      else {
        param_2 = FUN_1000c9f6();
        while( true ) {
          pcVar1 = (char *)FUN_1000c9f9(*(int **)(param_1 + 0x54),&param_2);
          if (pcVar1 == (char *)0x0) break;
          sVar6 = strlen(pcVar1);
          iVar7 = iVar7 + sVar6;
        }
        pcVar1 = malloc(iVar7 + iVar2);
        *pcVar1 = '\0';
        param_2 = FUN_1000c9f6();
        param_3 = (char *)0x0;
        if (0 < iVar2) {
          do {
            pcVar4 = (char *)FUN_1000ca26(*(int **)(param_1 + 0x54),(int)param_3);
            strcat(pcVar1,pcVar4);
            if ((int)param_3 < iVar2 + -1) {
              strcat(pcVar1,&DAT_100186fc);
            }
            param_3 = param_3 + 1;
          } while ((int)param_3 < iVar2);
        }
        mrbSetProperty(param_1,s_repeaters_100184c4,pcVar1);
        uVar5 = 1;
      }
      return uVar5;
    }
    param_3 = (char *)FUN_1000ca14(*(undefined4 **)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x50) = 0x50;
    pcVar1 = strchr(param_3,0x3a);
    if (pcVar1 == (char *)0x0) {
      free(*(void **)(param_1 + 0x4c));
      pcVar1 = _strdup(param_3);
      *(char **)(param_1 + 0x4c) = pcVar1;
LAB_100117de:
      *(undefined4 *)(param_1 + 0x5c) = 1;
      goto LAB_10011804;
    }
    lVar3 = atol(pcVar1 + 1);
    *(long *)(param_1 + 0x50) = lVar3;
    if (lVar3 != 0) {
      free(*(void **)(param_1 + 0x4c));
      sVar6 = (int)pcVar1 - (int)param_3;
      pcVar4 = malloc(sVar6 + 1);
      *(char **)(param_1 + 0x4c) = pcVar4;
      strncpy(pcVar4,param_3,sVar6);
      pcVar1[*(int *)(param_1 + 0x4c) - (int)param_3] = '\0';
      goto LAB_100117de;
    }
    FUN_1000c98a(*(int **)(param_1 + 0x54),param_3);
  } while( true );
}



/* VA 100118d1 */

void __cdecl mrbSetPrepareFilter(int param_1,undefined4 param_2)

{
                    /* 0x118d1  51  mrbSetPrepareFilter */
  *(undefined4 *)(param_1 + 0xe4) = param_2;
  return;
}



/* VA 100118e0 */

undefined4 * __cdecl mrbInitPluginConnection(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char local_104 [256];

                    /* 0x118e0  32  mrbInitPluginConnection */
  iVar1 = FUN_1000daff(param_1);
  if (iVar1 != 0) {
    return (undefined4 *)0x0;
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    pcVar2 = (char *)FUN_10006a31(*(int **)(param_1 + 0x2c),s_http_proxy_100184b0,0);
    pcVar3 = (char *)FUN_10006a31(*(int **)(param_1 + 0x2c),s_socks_proxy_100184a4,0);
    puVar4 = FUN_10003be8(*(char **)(param_1 + 0x60),pcVar2,*(undefined4 *)(param_1 + 0xc4),pcVar3,
                          *(undefined4 *)(param_1 + 0x94),*(undefined4 *)(param_1 + 0x80));
    *(undefined4 **)(param_1 + 0x28) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      uVar7 = 0;
      uVar6 = 0x41b;
      goto LAB_10011996;
    }
  }
  sprintf(local_104,s__s_plugin_10018700,*(undefined4 *)(param_1 + 0x48));
  piVar5 = FUN_10003e00(*(int *)(param_1 + 0x28),*(char **)(param_1 + 0x4c),*(int *)(param_1 + 0x50)
                        ,local_104);
  if (piVar5 != (int *)0x0) {
    puVar4 = malloc(0x14);
    *puVar4 = param_1;
    puVar4[1] = piVar5;
    iVar1 = mrbGetProperty((int)param_1,&DAT_10018084,0);
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[2] = (uint)(iVar1 != 0);
    return puVar4;
  }
  uVar7 = *(undefined4 *)(param_1 + 0x4c);
  uVar6 = 0x3ea;
LAB_10011996:
  FUN_1000f4e8((int)param_1,uVar6,uVar7);
  return (undefined4 *)0x0;
}



/* VA 100119db */

void __cdecl mrbTermPluginConnection(void *param_1)

{
                    /* 0x119db  53  mrbTermPluginConnection */
  if (*(int **)((int)param_1 + 0xc) != (int *)0x0) {
    FUN_10002897(*(int **)((int)param_1 + 0xc));
  }
  if (*(undefined4 **)((int)param_1 + 0x10) != (undefined4 *)0x0) {
    FUN_10002fef(*(undefined4 **)((int)param_1 + 0x10));
  }
  FUN_10004301(*(int **)((int)param_1 + 4));
  free(param_1);
  return;
}



/* VA 10011a0f */

undefined4 __cdecl mrbOpenPC(char **param_1,int param_2)

{
  char *pcVar1;
  char **ppcVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  char local_188 [128];
  char local_108 [256];
  char *local_8;

                    /* 0x11a0f  40  mrbOpenPC */
  ppcVar2 = param_1;
  pcVar1 = *param_1;
  if (param_1[2] == (char *)0x0) {
    param_1 = (char **)0x0;
  }
  else {
    param_1 = *(char ***)(pcVar1 + 0xd0);
  }
  piVar3 = FUN_10003f49((int *)ppcVar2[1],param_1,0);
  if (piVar3 == (int *)0xfffffff6) {
LAB_10011c4f:
    pcVar7 = *(char **)(pcVar1 + 0x4c);
    uVar6 = 0x3ea;
    goto LAB_10011c57;
  }
  if (piVar3 == (int *)0xfffffff8) {
    pcVar7 = *(char **)(pcVar1 + 0x4c);
LAB_10011c4b:
    uVar6 = 0x6f;
  }
  else {
    if (piVar3 == (int *)0xfffffff9) {
      pcVar7 = (char *)0x0;
      uVar6 = 0x41b;
      goto LAB_10011c57;
    }
    if ((int)piVar3 < -4) {
LAB_10011aaa:
      sprintf(local_108,s__s__d_1001717c,*(undefined4 *)(pcVar1 + 0x4c),
              *(undefined4 *)(pcVar1 + 0x50));
      FUN_100043ba((int)ppcVar2[1],&DAT_10018734,local_108);
      FUN_100043ba((int)ppcVar2[1],s_Content_type_10018030,s_application_marimba_10018040);
      local_8 = (char *)mrbGetPublishedProperty((undefined4 *)pcVar1,s_platform_10018728,0);
      uVar4 = mrbGetPublishedProperty((undefined4 *)pcVar1,s_locale_10018720,0);
      if ((local_8 != (char *)0x0) && (uVar4 != 0)) {
        sprintf(local_108,s__s__s_10018368,local_8,uVar4);
        FUN_100043ba((int)ppcVar2[1],s_Segment_10018718,local_108);
      }
      local_8 = (char *)FUN_10011c68(*(uint *)(pcVar1 + 0x70),*(int *)(pcVar1 + 0x74),0x24);
      FUN_100043ba((int)ppcVar2[1],s_Tuner_id_1001870c,local_8);
      free(local_8);
      if ((*(code **)(pcVar1 + 0xc0) != (code *)0x0) &&
         (iVar5 = (**(code **)(pcVar1 + 0xc0))
                            (*(undefined4 *)(pcVar1 + 0x80),s_Basic_10017ffc,
                             *(undefined4 *)(pcVar1 + 0x48),local_188), iVar5 == 0)) {
        uVar6 = FUN_10001000(local_188);
        sprintf(local_108,s__s__s_10017ff4,s_Basic_10017ffc,uVar6);
        FUN_100043ba((int)ppcVar2[1],s_Authorization_10017fe4,local_108);
      }
      iVar5 = FUN_10004cb5((int)ppcVar2[1]);
      if ((iVar5 != 0) &&
         (FUN_100043ba((int)ppcVar2[1],s_Content_Encoding_10018068,&DAT_1001807c), 0 < param_2)) {
        param_2 = FUN_100029af(param_2);
      }
      iVar5 = FUN_1000404b((int *)ppcVar2[1],param_2,(int)param_1);
      if (iVar5 == -8) {
        pcVar7 = *(char **)(pcVar1 + 0x4c);
        goto LAB_10011c4b;
      }
      if (iVar5 == 0) {
        return 0;
      }
      pcVar7 = s_POST_header_10017fa8;
    }
    else {
      if ((int)piVar3 < -2) goto LAB_10011c4f;
      if (piVar3 == (int *)0xfffffffe) {
        pcVar7 = *(char **)(pcVar1 + 0x4c);
        uVar6 = 0x3e9;
        goto LAB_10011c57;
      }
      if (piVar3 != (int *)0x197) goto LAB_10011aaa;
      sprintf(local_108,&DAT_100170c8,0x197);
      pcVar7 = local_108;
    }
    uVar6 = 1000;
  }
LAB_10011c57:
  FUN_1000f4e8((int)pcVar1,uVar6,pcVar7);
  return 0xffffffff;
}



/* VA 10011c68 */

/* WARNING: Removing unreachable block (ram,0x10011cc2) */

void __cdecl FUN_10011c68(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  char acStack_50 [64];
  undefined1 local_10;
  uint local_c;
  uint local_8;

  local_10 = 0;
  local_8 = (int)param_3 >> 0x1f;
  iVar1 = 0x3f;
  local_c = param_3;
  if (((int)local_8 <= param_2) &&
     ((lVar3 = CONCAT44(param_2,param_1), (int)local_8 < param_2 ||
      (lVar3 = CONCAT44(param_2,param_1), param_3 <= param_1)))) {
    do {
      uVar4 = (uint)((ulonglong)lVar3 >> 0x20);
      uVar2 = __allrem((uint)lVar3,uVar4,local_c,local_8);
      acStack_50[iVar1] = s_0123456789abcdef0123456789ABCDEF_10018400[(int)uVar2 + 0x40];
      iVar1 = iVar1 + -1;
      lVar3 = __alldiv((uint)lVar3,uVar4,local_c,local_8);
      param_1 = (uint)lVar3;
    } while (CONCAT44(local_8,local_c) <= lVar3);
  }
  acStack_50[iVar1] = s_0123456789abcdef0123456789ABCDEF_10018400[param_1 + 0x40];
  _strdup(acStack_50 + iVar1);
  return;
}



/* VA 10011ce0 */

void __cdecl mrbAddPCField(int param_1,char *param_2,char *param_3)

{
                    /* 0x11ce0  11  mrbAddPCField */
  FUN_100043ba(*(int *)(param_1 + 4),param_2,param_3);
  return;
}



/* VA 10011cf8 */

void __cdecl mrbGetPCField(int param_1,char *param_2)

{
                    /* 0x11cf8  27  mrbGetPCField */
  FUN_100043fe(*(int *)(param_1 + 4),param_2);
  return;
}



/* VA 10011d0b */

void __cdecl mrbWriteToPC(int param_1,byte *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;

                    /* 0x11d0b  60  mrbWriteToPC */
  piVar1 = (int *)FUN_10004749(*(int *)(param_1 + 4));
  iVar2 = FUN_10004cb5(*(int *)(param_1 + 4));
  if (iVar2 == 0) {
    FUN_1000c0c5(piVar1,(char *)param_2,param_3);
  }
  else {
    if (*(int *)(param_1 + 0xc) == 0) {
      puVar3 = FUN_10002a17(piVar1);
      puVar3 = FUN_10002866(puVar3);
      *(undefined4 **)(param_1 + 0xc) = puVar3;
    }
    FUN_100028bf(*(int **)(param_1 + 0xc),param_2,param_3);
  }
  return;
}



/* VA 10011d65 */

void __cdecl mrbReadFromPC(int param_1,void *param_2,size_t param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;

                    /* 0x11d65  44  mrbReadFromPC */
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar1 = FUN_10004757(*(int *)(param_1 + 4));
    puVar2 = FUN_10002d50(uVar1);
    *(undefined4 **)(param_1 + 0x10) = puVar2;
  }
  FUN_10002d96(*(int **)(param_1 + 0x10),param_2,param_3);
  return;
}



/* VA 10011d98 */

int __cdecl mrbGetPCReply(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;

                    /* 0x11d98  28  mrbGetPCReply */
  iVar1 = FUN_10004cb5(*(int *)(param_1 + 4));
  if (iVar1 != 0) {
    FUN_10002897(*(int **)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  piVar2 = (int *)FUN_10004749(*(int *)(param_1 + 4));
  FUN_1000c13e(piVar2);
  iVar1 = FUN_10004441(*(char **)(param_1 + 4),0,param_2);
  return -(uint)(iVar1 != 0);
}



/* VA 10011dde */

ulonglong __cdecl mrbGetCertIsExpired(int param_1)

{
  undefined4 in_EDX;
  time_t tVar1;
  undefined4 local_8;

                    /* 0x11dde  23  mrbGetCertIsExpired */
  if (*(int *)(param_1 + 0xd0) == 0) {
    return CONCAT44(in_EDX,0xffffffff);
  }
  FUN_1000bce9(*(int *)(param_1 + 0xd0),&local_8,&param_1);
  tVar1 = time((time_t *)0x0);
  return CONCAT44((int)((ulonglong)tVar1 >> 0x20),(uint)(param_1 < (int)tVar1));
}



/* VA 10011e1a */

undefined4 __cdecl mrbGetBytesReceived(int param_1)

{
                    /* 0x11e1a  17  mrbGetBytesReceived */
  return *(undefined4 *)(param_1 + 0xf4);
}



/* VA 10011e30 */

void __cdecl FUN_10011e30(int *param_1,int param_2,int *param_3)

{
  int iVar1;

  if (param_1[0xd] != 0) {
    *param_3 = param_1[0xe];
  }
  if ((*param_1 == 4) || (*param_1 == 5)) {
    (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1[3]);
  }
  if (*param_1 == 6) {
    FUN_100134a0(param_1[3],param_2);
    FUN_10013fd0(param_1[2],param_2);
    FUN_10013fd0(param_1[1],param_2);
  }
  *param_1 = 0;
  param_1[0xc] = param_1[9];
  param_1[0xb] = param_1[9];
  param_1[7] = 0;
  param_1[8] = 0;
  if ((code *)param_1[0xd] != (code *)0x0) {
    iVar1 = (*(code *)param_1[0xd])(0,0,0);
    param_1[0xe] = iVar1;
    *(int *)(param_2 + 0x30) = iVar1;
  }
  return;
}



/* VA 10011ed0 */

int * __cdecl FUN_10011ed0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)(**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x3c);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar2 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,param_3);
  piVar1[9] = iVar2;
  if (iVar2 == 0) {
    (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),piVar1);
    return (int *)0x0;
  }
  piVar1[10] = param_3 + iVar2;
  piVar1[0xd] = param_2;
  *piVar1 = 0;
  FUN_10011e30(piVar1,param_1,piVar1 + 0xe);
  return piVar1;
}



/* VA 10011f40 */

void __cdecl FUN_10011f40(uint *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint local_30;
  uint *local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  uint local_4;

  puVar3 = param_1;
  local_2c = *(uint **)param_2;
  local_30 = *(uint *)(param_2 + 4);
  local_28 = param_1[8];
  uVar7 = param_1[7];
  puVar10 = (uint *)param_1[0xc];
  if (puVar10 < (uint *)param_1[0xb]) {
    local_24 = (int)param_1[0xb] + (-1 - (int)puVar10);
    param_1 = puVar10;
  }
  else {
    local_24 = param_1[10] - (int)puVar10;
    param_1 = puVar10;
  }
switchD_10011ff1_default:
  uVar8 = local_28;
  puVar10 = local_2c;
  switch(*puVar3) {
  case 0:
    for (; local_2c = puVar10, local_28 = uVar8, uVar7 < 3; uVar7 = uVar7 + 8) {
      if (local_30 == 0) {
        puVar3[8] = uVar8;
        puVar3[7] = uVar7;
        iVar5 = *(int *)param_2;
        iVar2 = *(int *)(param_2 + 8);
        param_2[4] = 0;
        param_2[5] = 0;
        param_2[6] = 0;
        param_2[7] = 0;
        *(byte **)(param_2 + 8) = (byte *)((int)puVar10 + (iVar2 - iVar5));
        *(uint **)param_2 = puVar10;
        puVar3[0xc] = (uint)param_1;
        FUN_10014010((int)puVar3,(int)param_2,param_3);
        return;
      }
      local_30 = local_30 - 1;
      param_3 = 0;
      uVar8 = uVar8 | (uint)(byte)*puVar10 << ((byte)uVar7 & 0x1f);
      puVar10 = (uint *)((int)puVar10 + 1);
    }
    goto LAB_10011fdd;
  case 1:
    for (; uVar7 < 0x20; uVar7 = uVar7 + 8) {
      if (local_30 == 0) {
        puVar3[8] = uVar8;
        puVar3[7] = uVar7;
        iVar5 = *(int *)param_2;
        iVar2 = *(int *)(param_2 + 8);
        param_2[4] = 0;
        param_2[5] = 0;
        param_2[6] = 0;
        param_2[7] = 0;
        *(uint **)param_2 = local_2c;
        *(byte **)(param_2 + 8) = (byte *)((int)local_2c + (iVar2 - iVar5));
        puVar3[0xc] = (uint)param_1;
        FUN_10014010((int)puVar3,(int)param_2,param_3);
        return;
      }
      param_3 = 0;
      local_30 = local_30 - 1;
      uVar8 = uVar8 | (uint)(byte)*local_2c << ((byte)uVar7 & 0x1f);
      local_2c = (uint *)((int)local_2c + 1);
    }
    uVar4 = uVar8 & 0xffff;
    if (~uVar8 >> 0x10 != uVar4) {
      *puVar3 = 9;
      *(char **)(param_2 + 0x18) = s_invalid_stored_block_lengths_100187cc;
      puVar3[8] = uVar8;
      puVar3[7] = uVar7;
      iVar5 = *(int *)param_2;
      *(uint **)param_2 = local_2c;
      *(uint *)(param_2 + 4) = local_30;
      *(byte **)(param_2 + 8) = (byte *)((int)local_2c + (*(int *)(param_2 + 8) - iVar5));
      puVar3[0xc] = (uint)param_1;
      FUN_10014010((int)puVar3,(int)param_2,-3);
      return;
    }
    uVar7 = 0;
    puVar3[1] = uVar4;
    local_28 = 0;
    if (uVar4 != 0) {
      *puVar3 = 2;
      goto switchD_10011ff1_default;
    }
    break;
  case 2:
    if (local_30 == 0) {
      puVar3[8] = local_28;
      puVar3[7] = uVar7;
      iVar5 = *(int *)param_2;
      iVar2 = *(int *)(param_2 + 8);
      *(uint **)param_2 = local_2c;
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
      *(byte **)(param_2 + 8) = (byte *)((int)local_2c + (iVar2 - iVar5));
      puVar3[0xc] = (uint)param_1;
      FUN_10014010((int)puVar3,(int)param_2,param_3);
      return;
    }
    if (local_24 == 0) {
      if (param_1 == (uint *)puVar3[10]) {
        puVar10 = (uint *)puVar3[0xb];
        puVar9 = (uint *)puVar3[9];
        if (puVar10 != puVar9) {
          param_1 = puVar9;
          if (puVar9 < puVar10) {
            local_24 = (int)puVar10 + (-1 - (int)puVar9);
          }
          else {
            local_24 = (int)puVar3[10] - (int)puVar9;
          }
        }
      }
      if (local_24 == 0) {
        puVar3[0xc] = (uint)param_1;
        iVar5 = FUN_10014010((int)puVar3,(int)param_2,param_3);
        param_1 = (uint *)puVar3[0xc];
        puVar10 = (uint *)puVar3[0xb];
        if (param_1 < puVar10) {
          local_24 = (int)puVar10 + (-1 - (int)param_1);
        }
        else {
          local_24 = puVar3[10] - (int)param_1;
        }
        if ((param_1 == (uint *)puVar3[10]) && (puVar9 = (uint *)puVar3[9], puVar10 != puVar9)) {
          param_1 = puVar9;
          if (puVar9 < puVar10) {
            local_24 = (int)puVar10 + (-1 - (int)puVar9);
          }
          else {
            local_24 = (int)puVar3[10] - (int)puVar9;
          }
        }
        if (local_24 == 0) {
          puVar3[8] = local_28;
          puVar3[7] = uVar7;
          iVar2 = *(int *)param_2;
          *(uint *)(param_2 + 4) = local_30;
          *(uint **)param_2 = local_2c;
          *(byte **)(param_2 + 8) = (byte *)((int)local_2c + (*(int *)(param_2 + 8) - iVar2));
          puVar3[0xc] = (uint)param_1;
          FUN_10014010((int)puVar3,(int)param_2,iVar5);
          return;
        }
      }
    }
    param_3 = 0;
    uVar8 = puVar3[1];
    if (local_30 < puVar3[1]) {
      uVar8 = local_30;
    }
    if (local_24 < uVar8) {
      uVar8 = local_24;
    }
    puVar10 = local_2c;
    puVar9 = param_1;
    for (uVar4 = uVar8 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar9 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar9 = puVar9 + 1;
    }
    local_24 = local_24 - uVar8;
    for (uVar4 = uVar8 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(byte *)puVar9 = (byte)*puVar10;
      puVar10 = (uint *)((int)puVar10 + 1);
      puVar9 = (uint *)((int)puVar9 + 1);
    }
    local_2c = (uint *)((int)local_2c + uVar8);
    uVar4 = puVar3[1];
    local_30 = local_30 - uVar8;
    param_1 = (uint *)((int)param_1 + uVar8);
    puVar3[1] = uVar4 - uVar8;
    if (uVar4 - uVar8 != 0) goto switchD_10011ff1_default;
    break;
  case 3:
    puVar9 = local_2c;
    for (; local_2c = puVar9, uVar7 < 0xe; uVar7 = uVar7 + 8) {
      if (local_30 == 0) {
LAB_1001293b:
        puVar3[8] = uVar8;
        puVar3[7] = uVar7;
        iVar5 = *(int *)param_2;
        iVar2 = *(int *)(param_2 + 8);
        param_2[4] = 0;
        param_2[5] = 0;
        param_2[6] = 0;
        param_2[7] = 0;
        *(byte **)(param_2 + 8) = (byte *)((int)puVar9 + (iVar2 - iVar5));
        *(uint **)param_2 = puVar9;
        puVar3[0xc] = (uint)param_1;
        FUN_10014010((int)puVar3,(int)param_2,param_3);
        return;
      }
      local_30 = local_30 - 1;
      param_3 = 0;
      uVar8 = uVar8 | (uint)(byte)*puVar9 << ((byte)uVar7 & 0x1f);
      puVar9 = (uint *)((int)puVar9 + 1);
    }
    puVar3[1] = uVar8 & 0x3fff;
    if ((0x1d < (uVar8 & 0x1f)) || (0x3a0 < (uVar8 & 0x3e0))) {
      *puVar3 = 9;
      *(char **)(param_2 + 0x18) = s_too_many_length_or_distance_symb_100187a8;
LAB_100129ae:
      puVar3[8] = uVar8;
      puVar3[7] = uVar7;
      *(uint *)(param_2 + 4) = local_30;
      *(byte **)(param_2 + 8) = (byte *)((int)puVar9 + (*(int *)(param_2 + 8) - *(int *)param_2));
      *(uint **)param_2 = puVar9;
      puVar3[0xc] = (uint)param_1;
      FUN_10014010((int)puVar3,(int)param_2,-3);
      return;
    }
    uVar4 = ((uVar8 & 0x3fff) >> 5 & 0x1f) + 0x102 + (uVar8 & 0x1f);
    if (uVar4 < 0x13) {
      uVar4 = 0x13;
    }
    uVar4 = (**(code **)(param_2 + 0x20))(*(undefined4 *)(param_2 + 0x28),uVar4,4);
    puVar3[3] = uVar4;
    if (uVar4 == 0) {
      puVar3[8] = uVar8;
      puVar3[7] = uVar7;
      *(uint *)(param_2 + 4) = local_30;
      *(byte **)(param_2 + 8) = (byte *)((int)puVar9 + (*(int *)(param_2 + 8) - *(int *)param_2));
      *(uint **)param_2 = puVar9;
      puVar3[0xc] = (uint)param_1;
      FUN_10014010((int)puVar3,(int)param_2,-4);
      return;
    }
    uVar8 = uVar8 >> 0xe;
    uVar7 = uVar7 - 0xe;
    puVar3[2] = 0;
    *puVar3 = 4;
    puVar10 = puVar9;
    goto LAB_100122eb;
  case 4:
LAB_100122eb:
    if (puVar3[2] < (puVar3[1] >> 10) + 4) {
      do {
        for (; uVar7 < 3; uVar7 = uVar7 + 8) {
          if (local_30 == 0) {
LAB_100128fc:
            puVar3[8] = uVar8;
            puVar3[7] = uVar7;
            iVar5 = *(int *)param_2;
            iVar2 = *(int *)(param_2 + 8);
            param_2[4] = 0;
            param_2[5] = 0;
            param_2[6] = 0;
            param_2[7] = 0;
            *(byte **)(param_2 + 8) = (byte *)((int)puVar10 + (iVar2 - iVar5));
            *(uint **)param_2 = puVar10;
            puVar3[0xc] = (uint)param_1;
            FUN_10014010((int)puVar3,(int)param_2,param_3);
            return;
          }
          local_30 = local_30 - 1;
          param_3 = 0;
          uVar8 = uVar8 | (uint)(byte)*puVar10 << ((byte)uVar7 & 0x1f);
          puVar10 = (uint *)((int)puVar10 + 1);
          local_2c = puVar10;
        }
        uVar4 = uVar8 & 7;
        uVar7 = uVar7 - 3;
        uVar8 = uVar8 >> 3;
        *(uint *)(puVar3[3] + *(int *)(&DAT_10018740 + puVar3[2] * 4) * 4) = uVar4;
        uVar4 = puVar3[2];
        puVar3[2] = uVar4 + 1;
      } while (uVar4 + 1 < (puVar3[1] >> 10) + 4);
    }
    uVar4 = puVar3[2];
    while (uVar4 < 0x13) {
      *(undefined4 *)(puVar3[3] + *(int *)(&DAT_10018740 + puVar3[2] * 4) * 4) = 0;
      uVar4 = puVar3[2] + 1;
      puVar3[2] = uVar4;
    }
    puVar3[4] = 7;
    local_28 = FUN_10013800((int *)puVar3[3],puVar3 + 4,puVar3 + 5,(int)param_2);
    if (local_28 != 0) {
      (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),puVar3[3]);
LAB_100129eb:
      if (local_28 == 0xfffffffd) {
        *puVar3 = 9;
      }
      puVar3[8] = uVar8;
      puVar3[7] = uVar7;
      *(uint *)(param_2 + 4) = local_30;
      *(byte **)(param_2 + 8) = (byte *)((int)puVar10 + (*(int *)(param_2 + 8) - *(int *)param_2));
      *(uint **)param_2 = puVar10;
      puVar3[0xc] = (uint)param_1;
      FUN_10014010((int)puVar3,(int)param_2,local_28);
      return;
    }
    puVar3[2] = 0;
    *puVar3 = 5;
    local_28 = 0;
LAB_100123ce:
    if (puVar3[2] < (puVar3[1] >> 5 & 0x1f) + 0x102 + (puVar3[1] & 0x1f)) {
      do {
        for (; uVar7 < puVar3[4]; uVar7 = uVar7 + 8) {
          if (local_30 == 0) goto LAB_100128fc;
          local_30 = local_30 - 1;
          param_3 = 0;
          uVar8 = uVar8 | (uint)(byte)*puVar10 << ((byte)uVar7 & 0x1f);
          puVar10 = (uint *)((int)puVar10 + 1);
          local_2c = puVar10;
        }
        bVar1 = *(byte *)(puVar3[5] + 1 + (*(uint *)(&DAT_10018b28 + puVar3[4] * 4) & uVar8) * 8);
        local_28 = (uint)bVar1;
        local_4 = *(uint *)(puVar3[5] + (*(uint *)(&DAT_10018b28 + puVar3[4] * 4) & uVar8) * 8 + 4);
        if (local_4 < 0x10) {
          uVar7 = uVar7 - local_28;
          uVar8 = uVar8 >> (bVar1 & 0x1f);
          *(uint *)(puVar3[3] + puVar3[2] * 4) = local_4;
          puVar3[2] = puVar3[2] + 1;
        }
        else {
          local_24 = 7;
          if (local_4 != 0x12) {
            local_24 = local_4 - 0xe;
          }
          local_8 = local_24 + local_28;
          puVar9 = puVar10;
          puVar10 = local_2c;
          for (; local_2c = puVar10, uVar7 < local_8; uVar7 = uVar7 + 8) {
            if (local_30 == 0) goto LAB_1001293b;
            local_30 = local_30 - 1;
            param_3 = 0;
            uVar8 = uVar8 | (uint)(byte)*puVar9 << ((byte)uVar7 & 0x1f);
            puVar9 = (uint *)((int)puVar9 + 1);
            puVar10 = puVar9;
          }
          uVar8 = uVar8 >> (bVar1 & 0x1f);
          iVar5 = (-(uint)(local_4 != 0x12) & 0xfffffff8) + 0xb +
                  (*(uint *)(&DAT_10018b28 + local_24 * 4) & uVar8);
          uVar8 = uVar8 >> ((byte)local_24 & 0x1f);
          uVar7 = uVar7 - (local_24 + local_28);
          local_24 = puVar3[2];
          if (((puVar3[1] >> 5 & 0x1f) + 0x102 + (puVar3[1] & 0x1f) < local_24 + iVar5) ||
             ((local_4 == 0x10 && (local_24 == 0)))) {
            FUN_10013fd0(puVar3[5],(int)param_2);
            (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),puVar3[3]);
            *puVar3 = 9;
            *(char **)(param_2 + 0x18) = s_invalid_bit_length_repeat_1001878c;
            goto LAB_100129ae;
          }
          uVar4 = local_24;
          if (local_4 == 0x10) {
            uVar6 = *(undefined4 *)((puVar3[3] - 4) + local_24 * 4);
          }
          else {
            uVar6 = 0;
          }
          do {
            uVar4 = uVar4 + 1;
            iVar5 = iVar5 + -1;
            *(undefined4 *)((puVar3[3] - 4) + uVar4 * 4) = uVar6;
          } while (iVar5 != 0);
          puVar3[2] = uVar4;
        }
      } while (puVar3[2] < (puVar3[1] >> 5 & 0x1f) + 0x102 + (puVar3[1] & 0x1f));
    }
    FUN_10013fd0(puVar3[5],(int)param_2);
    puVar3[5] = 0;
    local_2c = (uint *)0x9;
    local_24 = 6;
    local_28 = FUN_10013d40((puVar3[1] & 0x1f) + 0x101,(puVar3[1] >> 5 & 0x1f) + 1,(int *)puVar3[3],
                            (uint *)&local_2c,&local_24,&local_1c,&local_20,(int)param_2);
    (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),puVar3[3]);
    if (local_28 != 0) goto LAB_100129eb;
    uVar4 = FUN_10012cb0((char)local_2c,(char)local_24,local_1c,local_20,(int)param_2);
    if (uVar4 == 0) {
      FUN_10013fd0(local_20,(int)param_2);
      FUN_10013fd0(local_1c,(int)param_2);
      goto LAB_10012a56;
    }
    puVar3[3] = uVar4;
    puVar3[1] = local_1c;
    puVar3[2] = local_20;
    *puVar3 = 6;
LAB_10012638:
    puVar3[8] = uVar8;
    puVar3[7] = uVar7;
    iVar5 = *(int *)param_2;
    *(uint *)(param_2 + 4) = local_30;
    *(uint **)param_2 = puVar10;
    *(byte **)(param_2 + 8) = (byte *)((int)puVar10 + (*(int *)(param_2 + 8) - iVar5));
    puVar3[0xc] = (uint)param_1;
    iVar5 = FUN_10012cf0((uint)puVar3,param_2,param_3);
    if (iVar5 != 1) {
      FUN_10014010((int)puVar3,(int)param_2,iVar5);
      return;
    }
    param_3 = 0;
    FUN_100134a0(puVar3[3],(int)param_2);
    FUN_10013fd0(puVar3[2],(int)param_2);
    FUN_10013fd0(puVar3[1],(int)param_2);
    local_30 = *(uint *)(param_2 + 4);
    local_28 = puVar3[8];
    local_2c = *(uint **)param_2;
    uVar7 = puVar3[7];
    param_1 = (uint *)puVar3[0xc];
    if (param_1 < (uint *)puVar3[0xb]) {
      local_24 = (int)puVar3[0xb] + (-1 - (int)param_1);
    }
    else {
      local_24 = puVar3[10] - (int)param_1;
    }
    if (puVar3[6] != 0) {
      puVar10 = local_2c;
      if (7 < uVar7) {
        uVar7 = uVar7 - 8;
        local_30 = local_30 + 1;
        puVar10 = (uint *)((int)local_2c + -1);
      }
      *puVar3 = 7;
LAB_10012acf:
      puVar3[0xc] = (uint)param_1;
      iVar5 = FUN_10014010((int)puVar3,(int)param_2,param_3);
      param_1 = (uint *)puVar3[0xc];
      if ((uint *)puVar3[0xb] != param_1) {
        puVar3[7] = uVar7;
        puVar3[8] = local_28;
        *(uint *)(param_2 + 4) = local_30;
        *(byte **)(param_2 + 8) = (byte *)((int)puVar10 + (*(int *)(param_2 + 8) - *(int *)param_2))
        ;
        *(uint **)param_2 = puVar10;
        puVar3[0xc] = (uint)param_1;
        FUN_10014010((int)puVar3,(int)param_2,iVar5);
        return;
      }
      *puVar3 = 8;
LAB_10012b36:
      puVar3[8] = local_28;
      puVar3[7] = uVar7;
      *(uint *)(param_2 + 4) = local_30;
      *(byte **)(param_2 + 8) = (byte *)((int)puVar10 + (*(int *)(param_2 + 8) - *(int *)param_2));
      *(uint **)param_2 = puVar10;
      puVar3[0xc] = (uint)param_1;
      FUN_10014010((int)puVar3,(int)param_2,1);
      return;
    }
    *puVar3 = 0;
    goto switchD_10011ff1_default;
  case 5:
    goto LAB_100123ce;
  case 6:
    goto LAB_10012638;
  case 7:
    goto LAB_10012acf;
  case 8:
    goto LAB_10012b36;
  case 9:
    puVar3[8] = local_28;
    puVar3[7] = uVar7;
    iVar5 = *(int *)param_2;
    *(uint *)(param_2 + 4) = local_30;
    *(uint **)param_2 = local_2c;
    *(byte **)(param_2 + 8) = (byte *)((int)local_2c + (*(int *)(param_2 + 8) - iVar5));
    puVar3[0xc] = (uint)param_1;
    FUN_10014010((int)puVar3,(int)param_2,-3);
    return;
  default:
    puVar3[8] = local_28;
    puVar3[7] = uVar7;
    iVar5 = *(int *)param_2;
    *(uint *)(param_2 + 4) = local_30;
    *(uint **)param_2 = local_2c;
    *(byte **)(param_2 + 8) = (byte *)((int)local_2c + (*(int *)(param_2 + 8) - iVar5));
    puVar3[0xc] = (uint)param_1;
    FUN_10014010((int)puVar3,(int)param_2,-2);
    return;
  }
  *puVar3 = -(uint)(puVar3[6] != 0) & 7;
  goto switchD_10011ff1_default;
LAB_10011fdd:
  puVar3[6] = uVar8 & 1;
  switch((uVar8 & 7) >> 1) {
  case 0:
    *puVar3 = 1;
    uVar4 = uVar7 - 3 & 7;
    local_28 = (uVar8 >> 3) >> (sbyte)uVar4;
    uVar7 = (uVar7 - 3) - uVar4;
    break;
  case 1:
    FUN_10013e60(&local_c,&local_10,&local_14,&local_18);
    uVar4 = FUN_10012cb0((char)local_c,(char)local_10,local_14,local_18,(int)param_2);
    puVar3[3] = uVar4;
    if (uVar4 == 0) {
LAB_10012a56:
      puVar3[8] = uVar8;
      puVar3[7] = uVar7;
      *(uint *)(param_2 + 4) = local_30;
      *(byte **)(param_2 + 8) = (byte *)((int)puVar10 + (*(int *)(param_2 + 8) - *(int *)param_2));
      *(uint **)param_2 = puVar10;
      puVar3[0xc] = (uint)param_1;
      FUN_10014010((int)puVar3,(int)param_2,-4);
      return;
    }
    *puVar3 = 6;
    local_28 = uVar8 >> 3;
    puVar3[1] = 0;
    puVar3[2] = 0;
    uVar7 = uVar7 - 3;
    break;
  case 2:
    local_28 = uVar8 >> 3;
    uVar7 = uVar7 - 3;
    *puVar3 = 3;
    break;
  case 3:
    *puVar3 = 9;
    *(char **)(param_2 + 0x18) = s_invalid_block_type_100187ec;
    puVar3[8] = uVar8 >> 3;
    puVar3[7] = uVar7 - 3;
    *(uint *)(param_2 + 4) = local_30;
    *(byte **)(param_2 + 8) = (byte *)((int)puVar10 + (*(int *)(param_2 + 8) - *(int *)param_2));
    *(uint **)param_2 = puVar10;
    puVar3[0xc] = (uint)param_1;
    FUN_10014010((int)puVar3,(int)param_2,-3);
    return;
  }
  goto switchD_10011ff1_default;
}



/* VA 10012c30 */

undefined4 __cdecl FUN_10012c30(int *param_1,int param_2,int *param_3)

{
  FUN_10011e30(param_1,param_2,param_3);
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1[9]);
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return 0;
}



/* VA 10012c70 */

void __cdecl FUN_10012c70(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;

  puVar3 = *(undefined4 **)(param_1 + 0x24);
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  iVar2 = *(int *)(param_1 + 0x24) + param_3;
  *(int *)(param_1 + 0x30) = iVar2;
  *(int *)(param_1 + 0x2c) = iVar2;
  return;
}



/* VA 10012cb0 */

void __cdecl
FUN_10012cb0(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)(**(code **)(param_5 + 0x20))(*(undefined4 *)(param_5 + 0x28),1,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 4) = param_1;
    *(undefined1 *)((int)puVar1 + 0x11) = param_2;
    *puVar1 = 0;
    puVar1[5] = param_3;
    puVar1[6] = param_4;
  }
  return;
}



/* VA 10012cf0 */

void __cdecl FUN_10012cf0(uint param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte bVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint local_14;
  undefined1 *local_10;
  undefined1 *local_8;

  pbVar5 = param_2;
  uVar6 = param_1;
  local_14 = *(uint *)(param_2 + 4);
  piVar2 = *(int **)(param_1 + 0xc);
  puVar11 = *(undefined1 **)(param_1 + 0x30);
  uVar12 = *(uint *)(param_1 + 0x1c);
  if (puVar11 < *(undefined1 **)(param_1 + 0x2c)) {
    local_10 = *(undefined1 **)(param_1 + 0x2c) + (-1 - (int)puVar11);
    param_1 = *(uint *)(param_1 + 0x20);
    param_2 = *(byte **)param_2;
  }
  else {
    local_10 = (undefined1 *)(*(int *)(param_1 + 0x28) - (int)puVar11);
    param_1 = *(uint *)(param_1 + 0x20);
    param_2 = *(byte **)param_2;
  }
  do {
    switch(*piVar2) {
    case 0:
      if (((undefined1 *)0x101 < local_10) && (9 < local_14)) {
        *(uint *)(uVar6 + 0x20) = param_1;
        *(uint *)(uVar6 + 0x1c) = uVar12;
        iVar8 = *(int *)pbVar5;
        *(uint *)(pbVar5 + 4) = local_14;
        *(byte **)pbVar5 = param_2;
        *(byte **)(pbVar5 + 8) = param_2 + (*(int *)(pbVar5 + 8) - iVar8);
        *(undefined1 **)(uVar6 + 0x30) = puVar11;
        param_3 = FUN_100134c0((uint)*(byte *)(piVar2 + 4),(uint)*(byte *)((int)piVar2 + 0x11),
                               piVar2[5],piVar2[6],uVar6,(int *)pbVar5);
        local_14 = *(uint *)(pbVar5 + 4);
        param_2 = *(byte **)pbVar5;
        uVar12 = *(uint *)(uVar6 + 0x1c);
        param_1 = *(uint *)(uVar6 + 0x20);
        puVar11 = *(undefined1 **)(uVar6 + 0x30);
        if (puVar11 < *(undefined1 **)(uVar6 + 0x2c)) {
          local_10 = *(undefined1 **)(uVar6 + 0x2c) + (-1 - (int)puVar11);
        }
        else {
          local_10 = (undefined1 *)(*(int *)(uVar6 + 0x28) - (int)puVar11);
        }
        if (param_3 != 0) {
          *piVar2 = (-(uint)(param_3 != 1) & 2) + 7;
          break;
        }
      }
      piVar2[2] = piVar2[5];
      piVar2[3] = (uint)*(byte *)(piVar2 + 4);
      *piVar2 = 1;
    case 1:
      uVar7 = piVar2[3];
      if (uVar12 < uVar7) {
        do {
          if (local_14 == 0) {
            *(uint *)(uVar6 + 0x1c) = uVar12;
            *(uint *)(uVar6 + 0x20) = param_1;
            iVar8 = *(int *)pbVar5;
            iVar4 = *(int *)(pbVar5 + 8);
            pbVar5[4] = 0;
            pbVar5[5] = 0;
            pbVar5[6] = 0;
            pbVar5[7] = 0;
            *(byte **)pbVar5 = param_2;
            *(byte **)(pbVar5 + 8) = param_2 + (iVar4 - iVar8);
            *(undefined1 **)(uVar6 + 0x30) = puVar11;
            FUN_10014010(uVar6,(int)pbVar5,param_3);
            return;
          }
          local_14 = local_14 - 1;
          param_3 = 0;
          bVar9 = (byte)uVar12;
          uVar12 = uVar12 + 8;
          param_1 = param_1 | (uint)*param_2 << (bVar9 & 0x1f);
          uVar7 = piVar2[3];
          param_2 = param_2 + 1;
        } while (uVar12 < uVar7);
      }
      pbVar1 = (byte *)(piVar2[2] + (*(uint *)(&DAT_10018b28 + uVar7 * 4) & param_1) * 8);
      param_1 = param_1 >> (pbVar1[1] & 0x1f);
      uVar12 = uVar12 - pbVar1[1];
      bVar9 = *pbVar1;
      if (bVar9 == 0) {
        piVar2[2] = *(int *)(pbVar1 + 4);
        *piVar2 = 6;
      }
      else if ((bVar9 & 0x10) == 0) {
        if ((bVar9 & 0x40) == 0) {
          piVar2[3] = (uint)bVar9;
          piVar2[2] = *(int *)(pbVar1 + 4);
        }
        else {
          if ((bVar9 & 0x20) == 0) {
            *piVar2 = 9;
            *(char **)(pbVar5 + 0x18) = s_invalid_literal_length_code_10018818;
switchD_10012d3d_caseD_9:
            *(uint *)(uVar6 + 0x20) = param_1;
            *(uint *)(uVar6 + 0x1c) = uVar12;
            iVar8 = *(int *)pbVar5;
            *(uint *)(pbVar5 + 4) = local_14;
            *(byte **)pbVar5 = param_2;
            *(byte **)(pbVar5 + 8) = param_2 + (*(int *)(pbVar5 + 8) - iVar8);
            *(undefined1 **)(uVar6 + 0x30) = puVar11;
            FUN_10014010(uVar6,(int)pbVar5,-3);
            return;
          }
          *piVar2 = 7;
        }
      }
      else {
        piVar2[2] = bVar9 & 0xf;
        piVar2[1] = *(int *)(pbVar1 + 4);
        *piVar2 = 2;
      }
      break;
    case 2:
      uVar7 = piVar2[2];
      if (uVar12 < uVar7) {
        do {
          if (local_14 == 0) goto LAB_10013316;
          local_14 = local_14 - 1;
          bVar9 = (byte)uVar12;
          uVar12 = uVar12 + 8;
          param_3 = 0;
          param_1 = param_1 | (uint)*param_2 << (bVar9 & 0x1f);
          uVar7 = piVar2[2];
          param_2 = param_2 + 1;
        } while (uVar12 < uVar7);
      }
      piVar2[1] = piVar2[1] + (*(uint *)(&DAT_10018b28 + uVar7 * 4) & param_1);
      param_1 = param_1 >> ((byte)piVar2[2] & 0x1f);
      *piVar2 = 3;
      uVar12 = uVar12 - piVar2[2];
      piVar2[2] = piVar2[6];
      piVar2[3] = (uint)*(byte *)((int)piVar2 + 0x11);
    case 3:
      uVar7 = piVar2[3];
      if (uVar12 < uVar7) {
        do {
          if (local_14 == 0) {
LAB_10013316:
            *(uint *)(uVar6 + 0x1c) = uVar12;
            *(uint *)(uVar6 + 0x20) = param_1;
            iVar8 = *(int *)pbVar5;
            iVar4 = *(int *)(pbVar5 + 8);
            pbVar5[4] = 0;
            pbVar5[5] = 0;
            pbVar5[6] = 0;
            pbVar5[7] = 0;
            *(byte **)pbVar5 = param_2;
            *(byte **)(pbVar5 + 8) = param_2 + (iVar4 - iVar8);
            *(undefined1 **)(uVar6 + 0x30) = puVar11;
            FUN_10014010(uVar6,(int)pbVar5,param_3);
            return;
          }
          local_14 = local_14 - 1;
          param_3 = 0;
          bVar9 = (byte)uVar12;
          uVar12 = uVar12 + 8;
          param_1 = param_1 | (uint)*param_2 << (bVar9 & 0x1f);
          uVar7 = piVar2[3];
          param_2 = param_2 + 1;
        } while (uVar12 < uVar7);
      }
      pbVar1 = (byte *)(piVar2[2] + (*(uint *)(&DAT_10018b28 + uVar7 * 4) & param_1) * 8);
      param_1 = param_1 >> (pbVar1[1] & 0x1f);
      uVar12 = uVar12 - pbVar1[1];
      bVar9 = *pbVar1;
      if ((bVar9 & 0x10) == 0) {
        if ((bVar9 & 0x40) != 0) {
          *piVar2 = 9;
          *(char **)(pbVar5 + 0x18) = s_invalid_distance_code_10018800;
          goto switchD_10012d3d_caseD_9;
        }
        piVar2[3] = (uint)bVar9;
        piVar2[2] = *(int *)(pbVar1 + 4);
      }
      else {
        piVar2[2] = bVar9 & 0xf;
        piVar2[3] = *(int *)(pbVar1 + 4);
        *piVar2 = 4;
      }
      break;
    case 4:
      uVar7 = piVar2[2];
      if (uVar12 < uVar7) {
        do {
          if (local_14 == 0) goto LAB_10013316;
          local_14 = local_14 - 1;
          param_3 = 0;
          bVar9 = (byte)uVar12;
          uVar12 = uVar12 + 8;
          param_1 = param_1 | (uint)*param_2 << (bVar9 & 0x1f);
          uVar7 = piVar2[2];
          param_2 = param_2 + 1;
        } while (uVar12 < uVar7);
      }
      piVar2[3] = piVar2[3] + (*(uint *)(&DAT_10018b28 + uVar7 * 4) & param_1);
      param_1 = param_1 >> ((byte)piVar2[2] & 0x1f);
      *piVar2 = 5;
      uVar12 = uVar12 - piVar2[2];
    case 5:
      if ((uint)((int)puVar11 - *(int *)(uVar6 + 0x24)) < (uint)piVar2[3]) {
        iVar8 = (*(int *)(uVar6 + 0x28) - *(int *)(uVar6 + 0x24)) - piVar2[3];
      }
      else {
        iVar8 = -piVar2[3];
      }
      local_8 = puVar11 + iVar8;
      if (piVar2[1] == 0) {
LAB_10013271:
        *piVar2 = 0;
      }
      else {
        do {
          if (local_10 == (undefined1 *)0x0) {
            if (puVar11 == *(undefined1 **)(uVar6 + 0x28)) {
              puVar10 = *(undefined1 **)(uVar6 + 0x2c);
              puVar3 = *(undefined1 **)(uVar6 + 0x24);
              if (puVar10 != puVar3) {
                puVar11 = puVar3;
                if (puVar3 < puVar10) {
                  local_10 = puVar10 + (-1 - (int)puVar3);
                }
                else {
                  local_10 = *(undefined1 **)(uVar6 + 0x28) + -(int)puVar3;
                }
              }
            }
            if (local_10 == (undefined1 *)0x0) {
              *(undefined1 **)(uVar6 + 0x30) = puVar11;
              param_3 = FUN_10014010(uVar6,(int)pbVar5,param_3);
              puVar11 = *(undefined1 **)(uVar6 + 0x30);
              puVar10 = *(undefined1 **)(uVar6 + 0x2c);
              if (puVar11 < puVar10) {
                local_10 = puVar10 + (-1 - (int)puVar11);
              }
              else {
                local_10 = (undefined1 *)(*(int *)(uVar6 + 0x28) - (int)puVar11);
              }
              if ((puVar11 == *(undefined1 **)(uVar6 + 0x28)) &&
                 (puVar3 = *(undefined1 **)(uVar6 + 0x24), puVar10 != puVar3)) {
                puVar11 = puVar3;
                if (puVar3 < puVar10) {
                  local_10 = puVar10 + (-1 - (int)puVar3);
                }
                else {
                  local_10 = *(undefined1 **)(uVar6 + 0x28) + -(int)puVar3;
                }
              }
              if (local_10 == (undefined1 *)0x0) goto LAB_10013355;
            }
          }
          puVar10 = puVar11 + 1;
          param_3 = 0;
          *puVar11 = *local_8;
          local_8 = local_8 + 1;
          local_10 = local_10 + -1;
          if (local_8 == *(undefined1 **)(uVar6 + 0x28)) {
            local_8 = *(undefined1 **)(uVar6 + 0x24);
          }
          iVar8 = piVar2[1];
          piVar2[1] = iVar8 + -1;
          puVar11 = puVar10;
        } while (iVar8 + -1 != 0);
        *piVar2 = 0;
      }
      break;
    case 6:
      if (local_10 == (undefined1 *)0x0) {
        if (puVar11 == *(undefined1 **)(uVar6 + 0x28)) {
          puVar10 = *(undefined1 **)(uVar6 + 0x2c);
          puVar3 = *(undefined1 **)(uVar6 + 0x24);
          if (puVar10 != puVar3) {
            puVar11 = puVar3;
            if (puVar3 < puVar10) {
              local_10 = puVar10 + (-1 - (int)puVar3);
            }
            else {
              local_10 = *(undefined1 **)(uVar6 + 0x28) + -(int)puVar3;
            }
          }
        }
        if (local_10 == (undefined1 *)0x0) {
          *(undefined1 **)(uVar6 + 0x30) = puVar11;
          param_3 = FUN_10014010(uVar6,(int)pbVar5,param_3);
          puVar11 = *(undefined1 **)(uVar6 + 0x30);
          puVar10 = *(undefined1 **)(uVar6 + 0x2c);
          if (puVar11 < puVar10) {
            local_10 = puVar10 + (-1 - (int)puVar11);
          }
          else {
            local_10 = (undefined1 *)(*(int *)(uVar6 + 0x28) - (int)puVar11);
          }
          if ((puVar11 == *(undefined1 **)(uVar6 + 0x28)) &&
             (puVar3 = *(undefined1 **)(uVar6 + 0x24), puVar10 != puVar3)) {
            puVar11 = puVar3;
            if (puVar3 < puVar10) {
              local_10 = puVar10 + (-1 - (int)puVar3);
            }
            else {
              local_10 = *(undefined1 **)(uVar6 + 0x28) + -(int)puVar3;
            }
          }
          if (local_10 == (undefined1 *)0x0) {
LAB_10013355:
            *(uint *)(uVar6 + 0x20) = param_1;
            *(uint *)(uVar6 + 0x1c) = uVar12;
            iVar8 = *(int *)pbVar5;
            *(uint *)(pbVar5 + 4) = local_14;
            *(byte **)pbVar5 = param_2;
            *(byte **)(pbVar5 + 8) = param_2 + (*(int *)(pbVar5 + 8) - iVar8);
            *(undefined1 **)(uVar6 + 0x30) = puVar11;
            FUN_10014010(uVar6,(int)pbVar5,param_3);
            return;
          }
        }
      }
      param_3 = 0;
      *puVar11 = (char)piVar2[2];
      puVar11 = puVar11 + 1;
      local_10 = local_10 + -1;
      goto LAB_10013271;
    case 7:
      *(undefined1 **)(uVar6 + 0x30) = puVar11;
      iVar8 = FUN_10014010(uVar6,(int)pbVar5,param_3);
      puVar11 = *(undefined1 **)(uVar6 + 0x30);
      if (*(undefined1 **)(uVar6 + 0x2c) != puVar11) {
        *(uint *)(uVar6 + 0x1c) = uVar12;
        *(uint *)(uVar6 + 0x20) = param_1;
        iVar4 = *(int *)pbVar5;
        *(uint *)(pbVar5 + 4) = local_14;
        *(byte **)pbVar5 = param_2;
        *(byte **)(pbVar5 + 8) = param_2 + (*(int *)(pbVar5 + 8) - iVar4);
        *(undefined1 **)(uVar6 + 0x30) = puVar11;
        FUN_10014010(uVar6,(int)pbVar5,iVar8);
        return;
      }
      *piVar2 = 8;
    case 8:
      goto switchD_10012d3d_caseD_8;
    case 9:
      goto switchD_10012d3d_caseD_9;
    default:
      *(uint *)(uVar6 + 0x20) = param_1;
      *(uint *)(uVar6 + 0x1c) = uVar12;
      iVar8 = *(int *)pbVar5;
      *(uint *)(pbVar5 + 4) = local_14;
      *(byte **)pbVar5 = param_2;
      *(byte **)(pbVar5 + 8) = param_2 + (*(int *)(pbVar5 + 8) - iVar8);
      *(undefined1 **)(uVar6 + 0x30) = puVar11;
      FUN_10014010(uVar6,(int)pbVar5,-2);
      return;
    }
  } while( true );
switchD_10012d3d_caseD_8:
  *(uint *)(uVar6 + 0x20) = param_1;
  *(uint *)(uVar6 + 0x1c) = uVar12;
  iVar8 = *(int *)pbVar5;
  *(uint *)(pbVar5 + 4) = local_14;
  *(byte **)pbVar5 = param_2;
  *(byte **)(pbVar5 + 8) = param_2 + (*(int *)(pbVar5 + 8) - iVar8);
  *(undefined1 **)(uVar6 + 0x30) = puVar11;
  FUN_10014010(uVar6,(int)pbVar5,1);
  return;
}



/* VA 100134a0 */

void __cdecl FUN_100134a0(undefined4 param_1,int param_2)

{
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return;
}



/* VA 100134c0 */

undefined4 __cdecl
FUN_100134c0(int param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int iVar14;
  byte *pbVar15;
  int iVar16;
  uint local_14;
  undefined1 *local_10;
  byte *local_c;

  puVar11 = *(undefined1 **)(param_5 + 0x30);
  uVar8 = *(uint *)(param_5 + 0x20);
  pbVar15 = (byte *)*param_6;
  local_14 = param_6[1];
  uVar5 = *(uint *)(param_5 + 0x1c);
  if (puVar11 < *(undefined1 **)(param_5 + 0x2c)) {
    local_10 = *(undefined1 **)(param_5 + 0x2c) + (-1 - (int)puVar11);
  }
  else {
    local_10 = (undefined1 *)(*(int *)(param_5 + 0x28) - (int)puVar11);
  }
  uVar3 = *(uint *)(&DAT_10018b28 + param_1 * 4);
  uVar4 = *(uint *)(&DAT_10018b28 + param_2 * 4);
  local_c = pbVar15;
  do {
    for (; uVar5 < 0x14; uVar5 = uVar5 + 8) {
      local_14 = local_14 - 1;
      uVar8 = uVar8 | (uint)*pbVar15 << ((byte)uVar5 & 0x1f);
      pbVar15 = pbVar15 + 1;
      local_c = pbVar15;
    }
    bVar2 = *(byte *)(param_3 + (uVar3 & uVar8) * 8);
    uVar10 = (uint)bVar2;
    iVar14 = param_3 + (uVar3 & uVar8) * 8;
    if (uVar10 == 0) {
LAB_100136e7:
      uVar8 = uVar8 >> (*(byte *)(iVar14 + 1) & 0x1f);
      uVar5 = uVar5 - *(byte *)(iVar14 + 1);
      *puVar11 = *(undefined1 *)(iVar14 + 4);
      puVar11 = puVar11 + 1;
      local_10 = local_10 + -1;
    }
    else {
      uVar8 = uVar8 >> (*(byte *)(iVar14 + 1) & 0x1f);
      uVar5 = uVar5 - *(byte *)(iVar14 + 1);
      while ((bVar2 & 0x10) == 0) {
        if ((uVar10 & 0x40) != 0) {
          if ((uVar10 & 0x20) != 0) {
            *(uint *)(param_5 + 0x20) = uVar8;
            *(uint *)(param_5 + 0x1c) = uVar5 & 7;
            iVar16 = (int)pbVar15 - (uVar5 >> 3);
            iVar14 = *param_6;
            param_6[1] = (uVar5 >> 3) + local_14;
            *param_6 = iVar16;
            param_6[2] = param_6[2] + (iVar16 - iVar14);
            *(undefined1 **)(param_5 + 0x30) = puVar11;
            return 1;
          }
          param_6[6] = (int)s_invalid_literal_length_code_10018818;
          goto LAB_100137b5;
        }
        iVar16 = uVar10 * 4;
        bVar2 = *(byte *)(*(int *)(iVar14 + 4) + (*(uint *)(&DAT_10018b28 + iVar16) & uVar8) * 8);
        uVar10 = (uint)bVar2;
        iVar14 = *(int *)(iVar14 + 4) + (*(uint *)(&DAT_10018b28 + iVar16) & uVar8) * 8;
        if (uVar10 == 0) goto LAB_100136e7;
        uVar8 = uVar8 >> (*(byte *)(iVar14 + 1) & 0x1f);
        uVar5 = uVar5 - *(byte *)(iVar14 + 1);
      }
      uVar10 = uVar10 & 0xf;
      uVar6 = (*(uint *)(&DAT_10018b28 + uVar10 * 4) & uVar8) + *(int *)(iVar14 + 4);
      uVar9 = uVar8 >> (sbyte)uVar10;
      for (uVar5 = uVar5 - uVar10; uVar5 < 0xf; uVar5 = uVar5 + 8) {
        local_14 = local_14 - 1;
        uVar9 = uVar9 | (uint)*pbVar15 << ((byte)uVar5 & 0x1f);
        pbVar15 = pbVar15 + 1;
        local_c = pbVar15;
      }
      iVar14 = param_4 + (uVar4 & uVar9) * 8;
      uVar8 = uVar9 >> (*(byte *)(iVar14 + 1) & 0x1f);
      uVar5 = uVar5 - *(byte *)(iVar14 + 1);
      bVar2 = *(byte *)(param_4 + (uVar4 & uVar9) * 8);
      while ((bVar2 & 0x10) == 0) {
        if ((bVar2 & 0x40) != 0) {
          param_6[6] = (int)s_invalid_distance_code_10018800;
LAB_100137b5:
          *(uint *)(param_5 + 0x20) = uVar8;
          iVar16 = (int)pbVar15 - (uVar5 >> 3);
          *(uint *)(param_5 + 0x1c) = uVar5 & 7;
          param_6[1] = (uVar5 >> 3) + local_14;
          iVar14 = *param_6;
          *param_6 = iVar16;
          param_6[2] = param_6[2] + (iVar16 - iVar14);
          *(undefined1 **)(param_5 + 0x30) = puVar11;
          return 0xfffffffd;
        }
        piVar1 = (int *)(iVar14 + 4);
        uVar10 = *(uint *)(&DAT_10018b28 + (uint)bVar2 * 4) & uVar8;
        iVar14 = *piVar1 + uVar10 * 8;
        uVar8 = uVar8 >> (*(byte *)(iVar14 + 1) & 0x1f);
        uVar5 = uVar5 - *(byte *)(iVar14 + 1);
        bVar2 = *(byte *)(*piVar1 + uVar10 * 8);
      }
      uVar10 = bVar2 & 0xf;
      pbVar7 = pbVar15;
      pbVar15 = local_c;
      for (; uVar5 < uVar10; uVar5 = uVar5 + 8) {
        local_14 = local_14 - 1;
        uVar8 = uVar8 | (uint)*pbVar7 << ((byte)uVar5 & 0x1f);
        pbVar7 = pbVar15 + 1;
        pbVar15 = pbVar7;
      }
      uVar5 = uVar5 - uVar10;
      uVar9 = (*(uint *)(&DAT_10018b28 + uVar10 * 4) & uVar8) + *(int *)(iVar14 + 4);
      uVar8 = uVar8 >> (sbyte)uVar10;
      local_10 = local_10 + -uVar6;
      if ((uint)((int)puVar11 - *(int *)(param_5 + 0x24)) < uVar9) {
        uVar10 = (uVar9 + *(int *)(param_5 + 0x24)) - (int)puVar11;
        puVar13 = (undefined1 *)(*(int *)(param_5 + 0x28) - uVar10);
        if (uVar10 < uVar6) {
          uVar6 = uVar6 - uVar10;
          do {
            *puVar11 = *puVar13;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
          puVar13 = *(undefined1 **)(param_5 + 0x24);
        }
      }
      else {
        puVar12 = puVar11 + -uVar9;
        *puVar11 = *puVar12;
        puVar13 = puVar12 + 2;
        puVar11[1] = puVar12[1];
        uVar6 = uVar6 - 2;
        puVar11 = puVar11 + 2;
      }
      do {
        *puVar11 = *puVar13;
        puVar11 = puVar11 + 1;
        puVar13 = puVar13 + 1;
        uVar6 = uVar6 - 1;
        local_c = pbVar15;
      } while (uVar6 != 0);
    }
    if ((local_10 < (undefined1 *)0x102) || (local_14 < 10)) {
      *(uint *)(param_5 + 0x20) = uVar8;
      *(uint *)(param_5 + 0x1c) = uVar5 & 7;
      iVar16 = (int)pbVar15 - (uVar5 >> 3);
      iVar14 = *param_6;
      param_6[1] = (uVar5 >> 3) + local_14;
      *param_6 = iVar16;
      param_6[2] = param_6[2] + (iVar16 - iVar14);
      *(undefined1 **)(param_5 + 0x30) = puVar11;
      return 0;
    }
  } while( true );
}



/* VA 10013800 */

int __cdecl FUN_10013800(int *param_1,uint *param_2,uint *param_3,int param_4)

{
  int iVar1;

  iVar1 = FUN_10013860(param_1,0x13,0x13,0,0,param_3,param_2,param_4);
  if (iVar1 == -3) {
    *(char **)(param_4 + 0x18) = s_oversubscribed_dynamic_bit_lengt_10018a7c;
    return -3;
  }
  if ((iVar1 == -5) || (*param_2 == 0)) {
    FUN_10013fd0(*param_3,param_4);
    *(char **)(param_4 + 0x18) = s_incomplete_dynamic_bit_lengths_t_10018a58;
    iVar1 = -3;
  }
  return iVar1;
}



/* VA 10013860 */

undefined4 __cdecl
FUN_10013860(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,
            uint *param_7,int param_8)

{
  uint *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint local_578;
  uint local_574;
  int local_570;
  uint *local_56c;
  undefined4 uStack_568;
  uint uStack_564;
  uint local_560;
  uint *local_558;
  uint local_548;
  uint local_53c [32];
  int local_4bc;
  uint local_480 [288];

  local_53c[0] = 0;
  local_53c[1] = 0;
  local_53c[2] = 0;
  local_53c[3] = 0;
  local_53c[4] = 0;
  local_53c[5] = 0;
  local_53c[6] = 0;
  local_53c[7] = 0;
  local_53c[8] = 0;
  local_53c[9] = 0;
  local_53c[10] = 0;
  local_53c[0xb] = 0;
  local_53c[0xc] = 0;
  local_53c[0xd] = 0;
  local_53c[0xe] = 0;
  local_53c[0xf] = 0;
  piVar8 = param_1;
  uVar14 = param_2;
  do {
    iVar19 = *piVar8;
    piVar8 = piVar8 + 1;
    uVar14 = uVar14 - 1;
    local_53c[iVar19] = local_53c[iVar19] + 1;
  } while (uVar14 != 0);
  if (local_53c[0] == param_2) {
    *param_6 = 0;
    *param_7 = 0;
    return 0;
  }
  local_578 = 1;
  puVar16 = local_53c;
  do {
    puVar16 = puVar16 + 1;
    if (*puVar16 != 0) break;
    local_578 = local_578 + 1;
  } while (local_578 < 0x10);
  local_574 = *param_7;
  if (*param_7 < local_578) {
    local_574 = local_578;
  }
  uVar14 = 0xf;
  puVar16 = local_53c + 0xf;
  do {
    if (*puVar16 != 0) break;
    uVar14 = uVar14 - 1;
    puVar16 = puVar16 + -1;
  } while (uVar14 != 0);
  if (uVar14 < local_574) {
    local_574 = uVar14;
  }
  *param_7 = local_574;
  iVar19 = 1 << ((byte)local_578 & 0x1f);
  if (local_578 < uVar14) {
    puVar16 = local_53c + local_578;
    uVar9 = local_578;
    do {
      uVar17 = *puVar16;
      if ((int)(iVar19 - uVar17) < 0) {
        return 0xfffffffd;
      }
      uVar9 = uVar9 + 1;
      puVar16 = puVar16 + 1;
      iVar19 = (iVar19 - uVar17) * 2;
    } while (uVar9 < uVar14);
  }
  iVar19 = iVar19 - local_53c[uVar14];
  if (iVar19 < 0) {
    return 0xfffffffd;
  }
  local_53c[0x11] = 0;
  local_53c[uVar14] = local_53c[uVar14] + iVar19;
  iVar10 = 0;
  iVar5 = uVar14 - 1;
  if (iVar5 != 0) {
    iVar12 = 0;
    do {
      iVar10 = iVar10 + *(int *)((int)local_53c + iVar12 + 4);
      iVar5 = iVar5 + -1;
      *(int *)((int)local_53c + iVar12 + 0x48) = iVar10;
      iVar12 = iVar12 + 4;
    } while (iVar5 != 0);
  }
  uVar9 = 0;
  do {
    iVar5 = *param_1;
    param_1 = param_1 + 1;
    if (iVar5 != 0) {
      uVar17 = local_53c[iVar5 + 0x10];
      local_480[uVar17] = uVar9;
      local_53c[iVar5 + 0x10] = uVar17 + 1;
    }
    uVar9 = uVar9 + 1;
  } while (uVar9 < param_2);
  uVar9 = local_53c[uVar14 + 0x10];
  local_56c = local_480;
  uVar17 = 0;
  uVar20 = 0;
  local_560 = 0;
  iVar5 = -local_574;
  local_53c[0x10] = 0;
  local_570 = -1;
  local_4bc = 0;
  local_548 = 0;
  if ((int)local_578 <= (int)uVar14) {
    local_558 = local_53c + local_578;
    do {
      uVar15 = *local_558;
      uVar3 = uStack_568;
      while (uVar15 != 0) {
        uStack_568._2_2_ = (undefined2)((uint)uVar3 >> 0x10);
        uVar11 = uVar15 - 1;
        uVar2 = uStack_568._2_2_;
        iVar10 = iVar5;
        while (uStack_568 = uVar3, iVar10 = iVar10 + local_574, iVar10 < (int)local_578) {
          iVar5 = iVar5 + local_574;
          iVar12 = local_570 + 1;
          uVar17 = uVar14 - iVar5;
          if (local_574 < uVar14 - iVar5) {
            uVar17 = local_574;
          }
          uVar18 = local_578 - iVar5;
          uVar20 = 1 << ((byte)uVar18 & 0x1f);
          if ((uVar15 < uVar20) &&
             (iVar6 = uVar20 + (-1 - uVar11), puVar16 = local_558, uVar18 < uVar17)) {
            while (uVar18 = uVar18 + 1, uVar18 < uVar17) {
              uVar20 = puVar16[1];
              uVar7 = iVar6 * 2;
              if (uVar7 < uVar20 || uVar7 - uVar20 == 0) break;
              iVar6 = uVar7 - uVar20;
              puVar16 = puVar16 + 1;
            }
          }
          uVar20 = 1 << ((byte)uVar18 & 0x1f);
          iVar6 = (**(code **)(param_8 + 0x20))(*(undefined4 *)(param_8 + 0x28),uVar20 + 1,8);
          if (iVar6 == 0) {
            if (iVar12 != 0) {
              FUN_10013fd0(local_4bc,param_8);
            }
            return 0xfffffffc;
          }
          local_548 = iVar6 + 8;
          *param_6 = local_548;
          *(uint *)(iVar6 + 4) = 0;
          local_53c[local_570 + 0x21] = local_548;
          if (iVar12 != 0) {
            local_53c[local_570 + 0x11] = local_560;
            uVar17 = local_53c[local_570 + 0x20];
            uStack_568._2_2_ = (undefined2)((uint)uStack_568 >> 0x10);
            uVar7 = local_560 >> ((char)iVar5 - (char)local_574 & 0x1fU);
            uStack_568 = CONCAT31(CONCAT21(uStack_568._2_2_,(char)local_574),(byte)uVar18);
            *(undefined4 *)(uVar17 + uVar7 * 8) = uStack_568;
            *(uint *)(uVar17 + 4 + uVar7 * 8) = local_548;
            uStack_564 = local_548;
          }
          uVar17 = local_560;
          param_6 = (uint *)(iVar6 + 4);
          local_570 = iVar12;
          uVar3 = uStack_568;
          uVar2 = uStack_568._2_2_;
        }
        bVar4 = (byte)iVar5;
        if (local_56c < local_480 + uVar9) {
          uStack_564 = *local_56c;
          if (uStack_564 < param_3) {
            uStack_568._0_1_ = (-(uStack_564 < 0x100) & 0xa0U) + 0x60;
          }
          else {
            iVar10 = (uStack_564 - param_3) * 4;
            uStack_568._0_1_ = *(char *)(iVar10 + param_5) + 'P';
            uStack_564 = *(uint *)(iVar10 + param_4);
          }
          local_56c = local_56c + 1;
        }
        else {
          uStack_568._0_1_ = -0x40;
        }
        uStack_568 = CONCAT31(CONCAT21(uVar2,(char)local_578 - bVar4),(char)uStack_568);
        iVar10 = 1 << ((char)local_578 - bVar4 & 0x1f);
        uVar15 = uVar17 >> (bVar4 & 0x1f);
        if (uVar15 < uVar20) {
          puVar13 = (undefined4 *)(local_548 + uVar15 * 8);
          do {
            uVar15 = uVar15 + iVar10;
            *puVar13 = uStack_568;
            puVar13[1] = uStack_564;
            puVar13 = puVar13 + iVar10 * 2;
            uVar17 = local_560;
          } while (uVar15 < uVar20);
        }
        uVar18 = 1 << ((char)local_578 - 1U & 0x1f);
        uVar15 = uVar17 & uVar18;
        while (uVar15 != 0) {
          uVar17 = uVar17 ^ uVar18;
          uVar18 = uVar18 >> 1;
          uVar15 = uVar17 & uVar18;
        }
        uVar17 = uVar17 ^ uVar18;
        puVar16 = local_53c + local_570 + 0x10;
        uVar15 = uVar11;
        uVar3 = uStack_568;
        local_560 = uVar17;
        if (((1 << (bVar4 & 0x1f)) - 1U & uVar17) != *puVar16) {
          do {
            iVar5 = iVar5 - local_574;
            local_570 = local_570 + -1;
            puVar1 = puVar16 + -1;
            puVar16 = puVar16 + -1;
          } while (((1 << ((byte)iVar5 & 0x1f)) - 1U & uVar17) != *puVar1);
        }
      }
      local_578 = local_578 + 1;
      local_558 = local_558 + 1;
      uStack_568 = uVar3;
    } while ((int)local_578 <= (int)uVar14);
  }
  if ((iVar19 != 0) && (uVar14 != 1)) {
    return 0xfffffffb;
  }
  return 0;
}



/* VA 10013d40 */

int __cdecl
FUN_10013d40(uint param_1,uint param_2,int *param_3,uint *param_4,uint *param_5,uint *param_6,
            uint *param_7,int param_8)

{
  int iVar1;

  iVar1 = FUN_10013860(param_3,param_1,0x101,0x10018868,0x100188e8,param_6,param_4,param_8);
  if ((iVar1 != 0) || (*param_4 == 0)) {
    if (iVar1 == -3) {
      *(char **)(param_8 + 0x18) = s_oversubscribed_literal_length_tr_10018b04;
      return -3;
    }
    if (iVar1 != -4) {
      FUN_10013fd0(*param_6,param_8);
      *(char **)(param_8 + 0x18) = s_incomplete_literal_length_tree_10018aa4;
      iVar1 = -3;
    }
    return iVar1;
  }
  iVar1 = FUN_10013860(param_3 + param_1,param_2,0,0x10018968,0x100189e0,param_7,param_5,param_8);
  if ((iVar1 == 0) && ((*param_5 != 0 || (param_1 < 0x102)))) {
    return 0;
  }
  if (iVar1 == -3) {
    *(char **)(param_8 + 0x18) = s_oversubscribed_literal_length_tr_10018b04;
  }
  else if (iVar1 == -5) {
    FUN_10013fd0(*param_7,param_8);
    *(char **)(param_8 + 0x18) = s_incomplete_distance_tree_10018ae8;
    iVar1 = -3;
  }
  else if (iVar1 != -4) {
    *(char **)(param_8 + 0x18) = s_empty_distance_tree_with_lengths_10018ac4;
    param_8 = -3;
  }
  FUN_10013fd0(*param_6,param_8);
  return iVar1;
}



/* VA 10013e60 */

undefined4 __cdecl
FUN_10013e60(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 local_4bc;
  undefined1 local_4b8 [32];
  undefined1 *local_498;
  undefined4 local_494;
  undefined1 *local_490;
  int local_480 [144];
  undefined4 local_240 [112];
  undefined4 local_80 [24];
  undefined4 local_20 [8];

  local_490 = (undefined1 *)&local_4bc;
  if (DAT_10019df8 == 0) {
    piVar3 = local_480;
    for (iVar1 = 0x90; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = 8;
      piVar3 = piVar3 + 1;
    }
    puVar2 = local_240;
    for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 9;
      puVar2 = puVar2 + 1;
    }
    local_4bc = 0x212;
    puVar2 = local_80;
    for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 7;
      puVar2 = puVar2 + 1;
    }
    local_498 = &LAB_10013fb0;
    puVar2 = local_20;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 8;
      puVar2 = puVar2 + 1;
    }
    local_494 = 0;
    DAT_10019df4 = 7;
    FUN_10013860(local_480,0x120,0x101,0x10018868,0x100188e8,&DAT_10018d5c,&DAT_10019df4,
                 (int)local_4b8);
    piVar3 = local_480;
    for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = 5;
      piVar3 = piVar3 + 1;
    }
    DAT_10019df0 = 5;
    FUN_10013860(local_480,0x1e,0,0x10018968,0x100189e0,&DAT_10018d58,&DAT_10019df0,(int)local_4b8);
    DAT_10019df8 = 1;
  }
  *param_1 = DAT_10019df4;
  *param_2 = DAT_10019df0;
  *param_3 = DAT_10018d5c;
  *param_4 = DAT_10018d58;
  return 0;
}



/* VA 10013fd0 */

undefined4 __cdecl FUN_10013fd0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  while (param_1 != 0) {
    iVar1 = *(int *)(param_1 + -4);
    *(int *)(param_1 + -4) = iVar2;
    iVar2 = param_1;
    param_1 = iVar1;
  }
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + -4);
    (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),iVar2 + -8);
    iVar2 = iVar1;
  }
  return 0;
}



/* VA 10014010 */

int __cdecl FUN_10014010(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_4;

  puVar4 = *(undefined4 **)(param_1 + 0x30);
  puVar6 = *(undefined4 **)(param_1 + 0x2c);
  local_4 = *(undefined4 **)(param_2 + 0xc);
  if (puVar4 < puVar6) {
    puVar4 = *(undefined4 **)(param_1 + 0x28);
  }
  uVar3 = *(uint *)(param_2 + 0x10);
  uVar5 = (int)puVar4 - (int)puVar6;
  if (uVar3 < (uint)((int)puVar4 - (int)puVar6)) {
    uVar5 = uVar3;
  }
  if ((uVar5 != 0) && (param_3 == -5)) {
    param_3 = 0;
  }
  *(uint *)(param_2 + 0x10) = uVar3 - uVar5;
  *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar5;
  if (*(code **)(param_1 + 0x34) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x38),puVar6,uVar5);
    *(undefined4 *)(param_1 + 0x38) = uVar1;
    *(undefined4 *)(param_2 + 0x30) = uVar1;
  }
  puVar4 = puVar6;
  puVar7 = local_4;
  for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar7 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar7 = puVar7 + 1;
  }
  puVar2 = (undefined1 *)((int)puVar6 + uVar5);
  for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  local_4 = (undefined4 *)((int)local_4 + uVar5);
  if (puVar2 == *(undefined1 **)(param_1 + 0x28)) {
    puVar4 = *(undefined4 **)(param_1 + 0x24);
    if (*(undefined1 **)(param_1 + 0x30) == *(undefined1 **)(param_1 + 0x28)) {
      *(undefined4 **)(param_1 + 0x30) = puVar4;
    }
    uVar5 = *(int *)(param_1 + 0x30) - (int)puVar4;
    uVar3 = *(uint *)(param_2 + 0x10);
    if (uVar3 < uVar5) {
      uVar5 = uVar3;
    }
    if ((uVar5 != 0) && (param_3 == -5)) {
      param_3 = 0;
    }
    *(uint *)(param_2 + 0x10) = uVar3 - uVar5;
    *(uint *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar5;
    if (*(code **)(param_1 + 0x34) != (code *)0x0) {
      uVar1 = (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x38),puVar4,uVar5);
      *(undefined4 *)(param_1 + 0x38) = uVar1;
      *(undefined4 *)(param_2 + 0x30) = uVar1;
    }
    puVar6 = puVar4;
    puVar7 = local_4;
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    local_4 = (undefined4 *)((int)local_4 + uVar5);
    puVar2 = (undefined1 *)((int)puVar4 + uVar5);
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
  }
  *(undefined4 **)(param_2 + 0xc) = local_4;
  *(undefined1 **)(param_1 + 0x2c) = puVar2;
  return param_3;
}



/* VA 10014150 */

undefined4 * mrb_inflateInit(void)

{
  undefined4 *_Memory;
  int iVar1;

                    /* 0x14150  63  mrb_inflateInit */
  _Memory = calloc(1,0x48);
  iVar1 = inflateInit2_((int)(_Memory + 4),-0xf,s_1_0_4_10018b6c,0x38);
  if (iVar1 == 0) {
    *_Memory = &DAT_10018c80;
    return _Memory;
  }
  free(_Memory);
  return (undefined4 *)0x0;
}



/* VA 10014190 */

void __cdecl mrb_inflateTerm(void *param_1)

{
                    /* 0x14190  68  mrb_inflateTerm */
  inflateEnd((int)param_1 + 0x10);
  free(param_1);
  return;
}



/* VA 100141b0 */

int __cdecl mrb_inflate(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;

                    /* 0x141b0  61  mrb_inflate */
  param_1[4] = param_1[1] + *param_1;
  param_1[7] = param_3 + param_2;
  param_1[5] = param_1[2];
  param_1[8] = param_4;
  iVar1 = inflate((byte *)(param_1 + 4),1);
  switch(iVar1) {
  case 0:
    break;
  case 1:
    param_1[3] = 1;
    break;
  case -5:
    return 0;
  default:
    return -1;
  }
  iVar1 = param_1[2];
  param_1[2] = param_1[5];
  param_1[1] = param_1[1] + (iVar1 - param_1[5]);
  return param_4 - param_1[8];
}



/* VA 10014250 */

undefined4 __cdecl mrb_inflateTotalIn(int param_1)

{
                    /* 0x14250  69  mrb_inflateTotalIn */
  return *(undefined4 *)(param_1 + 0x18);
}



/* VA 10014260 */

undefined4 __cdecl mrb_inflateTotalOut(int param_1)

{
                    /* 0x14260  70  mrb_inflateTotalOut */
  return *(undefined4 *)(param_1 + 0x24);
}



/* VA 10014270 */

undefined4 __cdecl mrb_inflateRemaining(int param_1)

{
                    /* 0x14270  65  mrb_inflateRemaining */
  return *(undefined4 *)(param_1 + 8);
}



/* VA 10014280 */

bool __cdecl mrb_inflateNeedsInput(int param_1)

{
                    /* 0x14280  64  mrb_inflateNeedsInput */
  return *(int *)(param_1 + 8) < 1;
}



/* VA 10014290 */

void __cdecl
mrb_inflateSetInput(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
                    /* 0x14290  67  mrb_inflateSetInput */
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  return;
}



/* VA 100142b0 */

int __cdecl mrb_inflateReset(int param_1)

{
  int iVar1;

                    /* 0x142b0  66  mrb_inflateReset */
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  iVar1 = inflateReset(param_1 + 0x10);
  return -(uint)(iVar1 != 0);
}



/* VA 100142d0 */

undefined4 __cdecl mrb_inflateFinished(int param_1)

{
                    /* 0x142d0  62  mrb_inflateFinished */
  return *(undefined4 *)(param_1 + 0xc);
}



/* VA 100142e0 */

char * zlibVersion(void)

{
                    /* 0x142e0  71  zlibVersion */
  return s_1_0_4_10018b6c;
}



/* VA 100142f0 */

void __cdecl FUN_100142f0(undefined4 param_1,size_t param_2,size_t param_3)

{
  calloc(param_2,param_3);
  return;
}



/* VA 10014320 */

uint __cdecl adler32(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  byte *pbVar19;
  uint uVar20;

                    /* 0x14320  1  adler32 */
  uVar2 = param_1 & 0xffff;
  uVar20 = param_1 >> 0x10;
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  while (param_3 != 0) {
    uVar1 = param_3;
    if (0x15af < param_3) {
      uVar1 = 0x15b0;
    }
    param_3 = param_3 - uVar1;
    if (0xf < (int)uVar1) {
      uVar18 = uVar1 >> 4;
      pbVar19 = param_2;
      do {
        uVar1 = uVar1 - 0x10;
        param_2 = pbVar19 + 0x10;
        iVar3 = uVar2 + *pbVar19;
        iVar4 = iVar3 + (uint)pbVar19[1];
        iVar5 = iVar4 + (uint)pbVar19[2];
        iVar6 = iVar5 + (uint)pbVar19[3];
        iVar7 = iVar6 + (uint)pbVar19[4];
        iVar8 = iVar7 + (uint)pbVar19[5];
        iVar9 = iVar8 + (uint)pbVar19[6];
        iVar10 = iVar9 + (uint)pbVar19[7];
        iVar11 = iVar10 + (uint)pbVar19[8];
        iVar12 = iVar11 + (uint)pbVar19[9];
        iVar13 = iVar12 + (uint)pbVar19[10];
        iVar14 = iVar13 + (uint)pbVar19[0xb];
        iVar15 = iVar14 + (uint)pbVar19[0xc];
        iVar16 = iVar15 + (uint)pbVar19[0xd];
        iVar17 = iVar16 + (uint)pbVar19[0xe];
        uVar2 = iVar17 + (uint)pbVar19[0xf];
        uVar20 = uVar20 + iVar3 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 +
                 iVar12 + iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + uVar2;
        uVar18 = uVar18 - 1;
        pbVar19 = param_2;
      } while (uVar18 != 0);
    }
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      uVar2 = uVar2 + *param_2;
      param_2 = param_2 + 1;
      uVar20 = uVar20 + uVar2;
    }
    uVar2 = uVar2 % 0xfff1;
    uVar20 = uVar20 % 0xfff1;
  }
  return uVar20 << 0x10 | uVar2;
}



/* VA 10014450 */

undefined4 __cdecl inflateReset(int param_1)

{
  uint *puVar1;

                    /* 0x14450  6  inflateReset */
  if ((param_1 != 0) && (puVar1 = *(uint **)(param_1 + 0x1c), puVar1 != (uint *)0x0)) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *puVar1 = -(uint)(puVar1[3] != 0) & 7;
    FUN_10011e30(*(int **)(*(int *)(param_1 + 0x1c) + 0x14),param_1,&param_1);
    return 0;
  }
  return 0xfffffffe;
}



/* VA 100144a0 */

undefined4 __cdecl inflateEnd(int param_1)

{
  int *piVar1;
  int iVar2;

                    /* 0x144a0  3  inflateEnd */
  iVar2 = param_1;
  if (((param_1 != 0) && (*(int *)(param_1 + 0x1c) != 0)) && (*(int *)(param_1 + 0x24) != 0)) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14);
    if (piVar1 != (int *)0x0) {
      FUN_10012c30(piVar1,param_1,&param_1);
    }
    (**(code **)(iVar2 + 0x24))(*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x1c));
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    return 0;
  }
  return 0xfffffffe;
}



/* VA 100144f0 */

undefined4 __cdecl inflateInit2_(int param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  int *piVar2;

                    /* 0x144f0  4  inflateInit2_ */
  if (((param_3 == (char *)0x0) || (*param_3 != s_1_0_4_10018b6c[0])) || (param_4 != 0x38)) {
    return 0xfffffffa;
  }
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (*(int *)(param_1 + 0x20) == 0) {
    *(code **)(param_1 + 0x20) = FUN_100142f0;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    *(undefined1 **)(param_1 + 0x24) = &LAB_10014310;
  }
  iVar1 = (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0x28),1,0x18);
  *(int *)(param_1 + 0x1c) = iVar1;
  if (iVar1 == 0) {
    return 0xfffffffc;
  }
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 0;
  if (param_2 < 0) {
    param_2 = -param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0xc) = 1;
  }
  if ((7 < param_2) && (param_2 < 0x10)) {
    *(int *)(*(int *)(param_1 + 0x1c) + 0x10) = param_2;
    piVar2 = FUN_10011ed0(param_1,~-(uint)(*(int *)(*(int *)(param_1 + 0x1c) + 0xc) != 0) &
                                  0x10014320,1 << ((byte)param_2 & 0x1f));
    *(int **)(*(int *)(param_1 + 0x1c) + 0x14) = piVar2;
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x14) == 0) {
      inflateEnd(param_1);
      return 0xfffffffc;
    }
    inflateReset(param_1);
    return 0;
  }
  inflateEnd(param_1);
  return 0xfffffffe;
}



/* VA 10014600 */

void __cdecl inflateInit_(int param_1,char *param_2,int param_3)

{
                    /* 0x14600  5  inflateInit_ */
  inflateInit2_(param_1,0xf,param_2,param_3);
  return;
}



/* VA 10014620 */

int __cdecl inflate(byte *param_1,int param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;

                    /* 0x14620  2  inflate */
  if ((((param_1 == (byte *)0x0) || (*(int *)(param_1 + 0x1c) == 0)) || (*(int *)param_1 == 0)) ||
     (param_2 < 0)) {
switchD_10014668_default:
    return -2;
  }
  iVar4 = -5;
  do {
    puVar2 = *(undefined4 **)(param_1 + 0x1c);
    switch(*puVar2) {
    case 0:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      puVar2[1] = (uint)**(byte **)param_1;
      puVar2 = *(undefined4 **)(param_1 + 0x1c);
      uVar3 = puVar2[1];
      *(int *)param_1 = *(int *)param_1 + 1;
      if (((byte)uVar3 & 0xf) != 8) {
        *puVar2 = 0xd;
        *(char **)(param_1 + 0x18) = s_unknown_compression_method_10018c64;
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4) = 5;
        break;
      }
      if ((uint)puVar2[4] < ((uint)puVar2[1] >> 4) + 8) {
        *puVar2 = 0xd;
        *(char **)(param_1 + 0x18) = s_invalid_window_size_10018c50;
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4) = 5;
        break;
      }
      *puVar2 = 1;
    case 1:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      puVar2 = *(undefined4 **)(param_1 + 0x1c);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      bVar1 = **(byte **)param_1;
      *(byte **)param_1 = *(byte **)param_1 + 1;
      if ((puVar2[1] * 0x100 + (uint)bVar1) % 0x1f == 0) {
        if ((bVar1 & 0x20) != 0) {
          **(undefined4 **)(param_1 + 0x1c) = 2;
          goto switchD_10014668_caseD_2;
        }
        *puVar2 = 7;
      }
      else {
        *puVar2 = 0xd;
        *(char **)(param_1 + 0x18) = s_incorrect_header_check_10018c38;
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4) = 5;
      }
      break;
    case 2:
switchD_10014668_caseD_2:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(uint *)(*(int *)(param_1 + 0x1c) + 8) = (uint)**(byte **)param_1 << 0x18;
      *(int *)param_1 = *(int *)param_1 + 1;
      **(undefined4 **)(param_1 + 0x1c) = 3;
switchD_10014668_caseD_3:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(uint *)(*(int *)(param_1 + 0x1c) + 8) =
           *(int *)(*(int *)(param_1 + 0x1c) + 8) + (uint)**(byte **)param_1 * 0x10000;
      *(int *)param_1 = *(int *)param_1 + 1;
      **(undefined4 **)(param_1 + 0x1c) = 4;
switchD_10014668_caseD_4:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(uint *)(*(int *)(param_1 + 0x1c) + 8) =
           *(int *)(*(int *)(param_1 + 0x1c) + 8) + (uint)**(byte **)param_1 * 0x100;
      *(int *)param_1 = *(int *)param_1 + 1;
      **(undefined4 **)(param_1 + 0x1c) = 5;
switchD_10014668_caseD_5:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(uint *)(*(int *)(param_1 + 0x1c) + 8) =
           *(int *)(*(int *)(param_1 + 0x1c) + 8) + (uint)**(byte **)param_1;
      *(int *)param_1 = *(int *)param_1 + 1;
      *(undefined4 *)(param_1 + 0x30) = (*(undefined4 **)(param_1 + 0x1c))[2];
      **(undefined4 **)(param_1 + 0x1c) = 6;
      return 2;
    case 3:
      goto switchD_10014668_caseD_3;
    case 4:
      goto switchD_10014668_caseD_4;
    case 5:
      goto switchD_10014668_caseD_5;
    case 6:
      **(undefined4 **)(param_1 + 0x1c) = 0xd;
      *(char **)(param_1 + 0x18) = s_need_dictionary_10018c10;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4) = 0;
      return -2;
    case 7:
      iVar4 = FUN_10011f40((uint *)puVar2[5],param_1,iVar4);
      if (iVar4 == -3) {
        **(undefined4 **)(param_1 + 0x1c) = 0xd;
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4) = 0;
        iVar4 = -3;
      }
      else {
        if (iVar4 != 1) {
          return iVar4;
        }
        iVar4 = 0;
        FUN_10011e30(*(int **)(*(int *)(param_1 + 0x1c) + 0x14),(int)param_1,
                     (int *)(*(int *)(param_1 + 0x1c) + 4));
        puVar2 = *(undefined4 **)(param_1 + 0x1c);
        if (puVar2[3] == 0) {
          *puVar2 = 8;
          goto switchD_10014668_caseD_8;
        }
        *puVar2 = 0xc;
      }
      break;
    case 8:
switchD_10014668_caseD_8:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(uint *)(*(int *)(param_1 + 0x1c) + 8) = (uint)**(byte **)param_1 << 0x18;
      *(int *)param_1 = *(int *)param_1 + 1;
      **(undefined4 **)(param_1 + 0x1c) = 9;
switchD_10014668_caseD_9:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(uint *)(*(int *)(param_1 + 0x1c) + 8) =
           *(int *)(*(int *)(param_1 + 0x1c) + 8) + (uint)**(byte **)param_1 * 0x10000;
      *(int *)param_1 = *(int *)param_1 + 1;
      **(undefined4 **)(param_1 + 0x1c) = 10;
switchD_10014668_caseD_a:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(uint *)(*(int *)(param_1 + 0x1c) + 8) =
           *(int *)(*(int *)(param_1 + 0x1c) + 8) + (uint)**(byte **)param_1 * 0x100;
      *(int *)param_1 = *(int *)param_1 + 1;
      **(undefined4 **)(param_1 + 0x1c) = 0xb;
switchD_10014668_caseD_b:
      if (*(int *)(param_1 + 4) == 0) {
        return iVar4;
      }
      iVar4 = 0;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      *(uint *)(*(int *)(param_1 + 0x1c) + 8) =
           *(int *)(*(int *)(param_1 + 0x1c) + 8) + (uint)**(byte **)param_1;
      puVar2 = *(undefined4 **)(param_1 + 0x1c);
      *(int *)param_1 = *(int *)param_1 + 1;
      if (puVar2[1] == puVar2[2]) {
        **(undefined4 **)(param_1 + 0x1c) = 0xc;
switchD_10014668_caseD_c:
        return 1;
      }
      *puVar2 = 0xd;
      *(char **)(param_1 + 0x18) = s_incorrect_data_check_10018c20;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4) = 5;
      break;
    case 9:
      goto switchD_10014668_caseD_9;
    case 10:
      goto switchD_10014668_caseD_a;
    case 0xb:
      goto switchD_10014668_caseD_b;
    case 0xc:
      goto switchD_10014668_caseD_c;
    case 0xd:
      return -3;
    default:
      goto switchD_10014668_default;
    }
  } while( true );
}



/* VA 10014a50 */

undefined4 __cdecl inflateSetDictionary(int param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;

                    /* 0x14a50  7  inflateSetDictionary */
  if (((param_1 != 0) && (*(int **)(param_1 + 0x1c) != (int *)0x0)) &&
     (**(int **)(param_1 + 0x1c) == 6)) {
    uVar1 = adler32(1,param_2,param_3);
    if (uVar1 != *(uint *)(param_1 + 0x30)) {
      return 0xfffffffd;
    }
    *(undefined4 *)(param_1 + 0x30) = 1;
    uVar2 = 1 << ((byte)*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x10) & 0x1f);
    uVar1 = param_3;
    if (uVar2 <= param_3) {
      uVar1 = uVar2 - 1;
      param_2 = param_2 + (param_3 - uVar1);
    }
    FUN_10012c70(*(int *)(*(int *)(param_1 + 0x1c) + 0x14),(undefined4 *)param_2,uVar1);
    **(undefined4 **)(param_1 + 0x1c) = 7;
    return 0;
  }
  return 0xfffffffe;
}



/* VA 10014ae0 */

undefined4 __cdecl inflateSync(undefined4 *param_1)

{
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;

                    /* 0x14ae0  8  inflateSync */
  if ((param_1 == (undefined4 *)0x0) || (piVar1 = (int *)param_1[7], piVar1 == (int *)0x0)) {
    return 0xfffffffe;
  }
  if (*piVar1 != 0xd) {
    *piVar1 = 0xd;
    *(undefined4 *)(param_1[7] + 4) = 0;
  }
  iVar6 = param_1[1];
  if (iVar6 == 0) {
    return 0xfffffffb;
  }
  pcVar2 = (char *)*param_1;
  uVar5 = *(uint *)(param_1[7] + 4);
  pcVar7 = pcVar2;
  do {
    if (3 < uVar5) break;
    if (*pcVar7 == (byte)((-(uVar5 < 2) & 1U) - 1)) {
      uVar5 = uVar5 + 1;
    }
    else if (*pcVar7 == '\0') {
      uVar5 = 4 - uVar5;
    }
    else {
      uVar5 = 0;
    }
    pcVar7 = pcVar7 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *param_1 = pcVar7;
  param_1[2] = pcVar7 + (param_1[2] - (int)pcVar2);
  param_1[1] = iVar6;
  *(uint *)(param_1[7] + 4) = uVar5;
  if (uVar5 != 4) {
    return 0xfffffffd;
  }
  uVar3 = param_1[2];
  uVar4 = param_1[5];
  inflateReset((int)param_1);
  param_1[2] = uVar3;
  param_1[5] = uVar4;
  *(undefined4 *)param_1[7] = 7;
  return 0;
}



/* VA 10014bc0 */

int WSACleanup(void)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSACleanup();
  return iVar1;
}



/* VA 10014bc6 */

int WSAStartup(WORD wVersionRequired,LPWSADATA lpWSAData)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSAStartup(wVersionRequired,lpWSAData);
  return iVar1;
}



/* VA 10014bcc */

int closesocket(SOCKET s)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = closesocket(s);
  return iVar1;
}



/* VA 10014bd2 */

int connect(SOCKET s,sockaddr *name,int namelen)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = connect(s,name,namelen);
  return iVar1;
}



/* VA 10014bd8 */

u_short htons(u_short hostshort)

{
  u_short uVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = htons(hostshort);
  return uVar1;
}



/* VA 10014bde */

int WSAGetLastError(void)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSAGetLastError();
  return iVar1;
}



/* VA 10014be4 */

hostent * gethostbyname(char *name)

{
  hostent *phVar1;

                    /* WARNING: Could not recover jumptable at 0x10014be4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  phVar1 = gethostbyname(name);
  return phVar1;
}



/* VA 10014bea */

ulong inet_addr(char *cp)

{
  ulong uVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = inet_addr(cp);
  return uVar1;
}



/* VA 10014bf0 */

SOCKET socket(int af,int type,int protocol)

{
  SOCKET SVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SVar1 = socket(af,type,protocol);
  return SVar1;
}



/* VA 10014bf6 */

int recv(SOCKET s,char *buf,int len,int flags)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bf6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = recv(s,buf,len,flags);
  return iVar1;
}



/* VA 10014bfc */

int send(SOCKET s,char *buf,int len,int flags)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014bfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = send(s,buf,len,flags);
  return iVar1;
}



/* VA 10014c02 */

int ioctlsocket(SOCKET s,long cmd,u_long *argp)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014c02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = ioctlsocket(s,cmd,argp);
  return iVar1;
}



/* VA 10014c08 */

char * inet_ntoa(in_addr in)

{
  char *pcVar1;

                    /* WARNING: Could not recover jumptable at 0x10014c08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = inet_ntoa(in);
  return pcVar1;
}



/* VA 10014c0e */

int gethostname(char *name,int namelen)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014c0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = gethostname(name,namelen);
  return iVar1;
}



/* VA 10014c14 */

void WSASetLastError(int iError)

{
                    /* WARNING: Could not recover jumptable at 0x10014c14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  WSASetLastError(iError);
  return;
}



/* VA 10014c1a */

int select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,timeval *timeout)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014c1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = select(nfds,readfds,writefds,exceptfds,timeout);
  return iVar1;
}



/* VA 10014c20 */

int WSAUnhookBlockingHook(void)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014c20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSAUnhookBlockingHook();
  return iVar1;
}



/* VA 10014c26 */

FARPROC WSASetBlockingHook(FARPROC lpBlockFunc)

{
  FARPROC pFVar1;

                    /* WARNING: Could not recover jumptable at 0x10014c26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = WSASetBlockingHook(lpBlockFunc);
  return pFVar1;
}



/* VA 10014c2c */

int WSACancelBlockingCall(void)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = WSACancelBlockingCall();
  return iVar1;
}



/* VA 10014c32 */

size_t __cdecl strlen(char *_Str)

{
  size_t sVar1;

                    /* WARNING: Could not recover jumptable at 0x10014c32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = strlen(_Str);
  return sVar1;
}



/* VA 10014c40 */

/* Library Function - Single Match
    __allmul

   Library: Visual Studio */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



/* VA 10014c80 */

/* Library Function - Single Match
    __aullshr

   Library: Visual Studio */

ulonglong __fastcall __aullshr(byte param_1,uint param_2)

{
  uint in_EAX;

  if (0x3f < param_1) {
    return 0;
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 >> (param_1 & 0x1f),
                    in_EAX >> (param_1 & 0x1f) | param_2 << 0x20 - (param_1 & 0x1f));
  }
  return (ulonglong)(param_2 >> (param_1 & 0x1f));
}



/* VA 10014ca0 */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x10014ca0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}



/* VA 10014ca6 */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x10014ca6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



/* VA 10014cac */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x10014cac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



/* VA 10014cc0 */

/* Library Function - Single Match
    __allshl

   Library: Visual Studio */

longlong __fastcall __allshl(byte param_1,int param_2)

{
  uint in_EAX;

  if (0x3f < param_1) {
    return 0;
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 << (param_1 & 0x1f) | in_EAX >> 0x20 - (param_1 & 0x1f),
                    in_EAX << (param_1 & 0x1f));
  }
  return (ulonglong)(in_EAX << (param_1 & 0x1f)) << 0x20;
}



/* VA 10014ce0 */

void * __cdecl calloc(size_t _Count,size_t _Size)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x10014ce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = calloc(_Count,_Size);
  return pvVar1;
}



/* VA 10014cf0 */

/* Library Function - Single Match
    __allshr

   Library: Visual Studio */

undefined8 __fastcall __allshr(byte param_1,int param_2)

{
  uint in_EAX;
  int iVar1;

  iVar1 = param_2 >> 0x1f;
  if (0x3f < param_1) {
    return CONCAT44(iVar1,iVar1);
  }
  if (param_1 < 0x20) {
    return CONCAT44(param_2 >> (param_1 & 0x1f),
                    in_EAX >> (param_1 & 0x1f) | param_2 << 0x20 - (param_1 & 0x1f));
  }
  return CONCAT44(iVar1,param_2 >> (param_1 & 0x1f));
}



/* VA 10014d20 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10014d20(void)

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



/* VA 10014d50 */

char * __cdecl strcat(char *_Dest,char *_Source)

{
  char *pcVar1;

                    /* WARNING: Could not recover jumptable at 0x10014d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strcat(_Dest,_Source);
  return pcVar1;
}



/* VA 10014d56 */

char * __cdecl strcpy(char *_Dest,char *_Source)

{
  char *pcVar1;

                    /* WARNING: Could not recover jumptable at 0x10014d56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strcpy(_Dest,_Source);
  return pcVar1;
}



/* VA 10014d5c */

int __cdecl strcmp(char *_Str1,char *_Str2)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x10014d5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = strcmp(_Str1,_Str2);
  return iVar1;
}



/* VA 10014d70 */

void __cdecl ftol(void)

{
                    /* WARNING: Could not recover jumptable at 0x10014d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ftol();
  return;
}



/* VA 10014d80 */

/* Library Function - Single Match
    __alldiv

   Library: Visual Studio */

undefined8 __alldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;

  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar7 = param_1;
  uVar3 = param_3;
  uVar5 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar6 = uVar5 >> 1;
      uVar7 = (uint)(CONCAT14((uVar5 & 1) != 0,uVar7) >> 1);
      uVar5 = uVar6;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar6,uVar7) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar7 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar7)) ||
       ((param_2 <= uVar7 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}



/* VA 10014e30 */

/* Library Function - Single Match
    __allrem

   Library: Visual Studio */

undefined8 __allrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;

  bVar13 = (int)param_2 < 0;
  if (bVar13) {
    bVar12 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar12 - param_2;
  }
  uVar11 = (uint)bVar13;
  if ((int)param_4 < 0) {
    bVar13 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar13 - param_4;
  }
  uVar4 = param_1;
  uVar3 = param_3;
  uVar8 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    iVar5 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar6 = 0;
    if ((int)(uVar11 - 1) < 0) goto LAB_10014edd;
  }
  else {
    do {
      uVar10 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar7 = uVar8 >> 1;
      uVar4 = (uint)(CONCAT14((uVar8 & 1) != 0,uVar4) >> 1);
      uVar8 = uVar7;
      uVar9 = uVar10;
    } while (uVar10 != 0);
    uVar1 = CONCAT44(uVar7,uVar4) / (ulonglong)uVar3;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar8 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar9 = uVar8 + uVar3;
    if (((CARRY4(uVar8,uVar3)) || (param_2 < uVar9)) || ((param_2 <= uVar9 && (param_1 < uVar4)))) {
      bVar13 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar9 = (uVar9 - param_4) - (uint)bVar13;
    }
    iVar5 = uVar4 - param_1;
    iVar6 = (uVar9 - param_2) - (uint)(uVar4 < param_1);
    if (-1 < (int)(uVar11 - 1)) goto LAB_10014edd;
  }
  bVar13 = iVar5 != 0;
  iVar5 = -iVar5;
  iVar6 = -(uint)bVar13 - iVar6;
LAB_10014edd:
  return CONCAT44(iVar6,iVar5);
}



/* VA 10014ef0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10014ef0(undefined4 param_1,int param_2)

{
  undefined4 *_Memory;
  undefined4 *puVar1;

  if (param_2 == 0) {
    if (DAT_10019dfc < 1) {
      return 0;
    }
    DAT_10019dfc = DAT_10019dfc + -1;
  }
  _DAT_10019e00 = *(undefined4 *)_adjust_fdiv_exref;
  if (param_2 == 1) {
    DAT_10019e08 = malloc(0x80);
    if (DAT_10019e08 == (undefined4 *)0x0) {
      return 0;
    }
    *DAT_10019e08 = 0;
    DAT_10019e04 = DAT_10019e08;
    initterm(&DAT_10017000,&DAT_10017004);
    DAT_10019dfc = DAT_10019dfc + 1;
    return 1;
  }
  if ((param_2 == 0) && (DAT_10019e08 != (undefined4 *)0x0)) {
    puVar1 = DAT_10019e04 + -1;
    _Memory = DAT_10019e08;
    if (DAT_10019e08 <= puVar1) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
          _Memory = DAT_10019e08;
        }
        puVar1 = puVar1 + -1;
      } while (_Memory <= puVar1);
    }
    free(_Memory);
    DAT_10019e08 = (undefined4 *)0x0;
  }
  return 1;
}



/* VA 10014fc0 */

int entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;

  iVar1 = 1;
  if ((param_2 == 0) && (DAT_10019dfc == 0)) {
    return 0;
  }
  if ((param_2 != 1) && (param_2 != 2)) {
LAB_1001501e:
    iVar1 = FUN_10015080(param_1,param_2);
    if ((param_2 == 1) && (iVar1 == 0)) {
      FUN_10014ef0(param_1,0);
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      iVar2 = FUN_10014ef0(param_1,param_2);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      if ((iVar1 != 0) && (DAT_10019e0c != (code *)0x0)) {
        iVar1 = (*DAT_10019e0c)(param_1,param_2,param_3);
      }
    }
    return iVar1;
  }
  if (DAT_10019e0c != (code *)0x0) {
    iVar1 = (*DAT_10019e0c)(param_1,param_2,param_3);
  }
  if (iVar1 != 0) {
    iVar1 = FUN_10014ef0(param_1,param_2);
    if (iVar1 != 0) goto LAB_1001501e;
  }
  return 0;
}



/* VA 10015070 */

void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x10015070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}



/* VA 10015080 */

undefined4 FUN_10015080(HMODULE param_1,int param_2)

{
  if ((param_2 == 1) && (DAT_10019e0c == 0)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}
