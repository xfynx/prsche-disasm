/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 b8387146e44ca186a4a84752ed2ae79c054f8d054924d17ca9b99810c67780d7 */

/* VA 008f0950 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x008f095d) overlaps instruction at (ram,0x008f095c)
    */
/* WARNING: Unable to track spacebase fully for stack */

int __fastcall FUN_008f0950(undefined4 param_1,int param_2)

{
  uint *puVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  code *pcVar6;
  undefined6 uVar7;
  char cVar8;
  undefined4 in_EAX;
  int iVar11;
  int extraout_ECX;
  int unaff_EBP;
  char *unaff_ESI;
  char *unaff_EDI;
  undefined2 in_CS;
  byte in_CF;
  bool bVar12;
  byte in_AF;
  bool bVar13;
  undefined1 auStack_5 [5];
  byte bVar9;
  undefined6 *puVar10;

  uVar3 = (uint)in_CF;
  bVar12 = &stack0x00000000 < *(undefined1 **)(param_2 * 9);
  uVar4 = (int)&stack0x00000000 - *(uint *)(param_2 * 9);
  iVar11 = -uVar3;
  bVar9 = (byte)in_EAX;
  bVar13 = 0x99 < bVar9 || (bVar12 || uVar4 < uVar3);
  cVar8 = bVar9 + (9 < (bVar9 & 0xf) | in_AF) * '\x06' + bVar13 * '`';
  puVar10 = (undefined6 *)CONCAT31((int3)((uint)in_EAX >> 8),cVar8);
  if ((0x99 >= bVar9 && (!bVar12 && uVar4 >= uVar3)) && cVar8 != '\0') {
    uVar7 = *puVar10;
    cVar8 = (char)uVar7 * *(char *)(unaff_EBP + -0x727f0867);
    out((short)param_2,cVar8);
    *(char **)(uVar4 + iVar11 + -5) = unaff_ESI;
    *unaff_EDI = cVar8;
    in((short)param_2);
    *unaff_ESI = *unaff_ESI + (char)((uint)param_1 >> 8);
    *(short *)(uVar4 + iVar11 + -2) = (short)((uint6)uVar7 >> 0x20);
    pcVar6 = (code *)swi(1);
    iVar11 = (*pcVar6)();
    return iVar11;
  }
  if (bVar13 || cVar8 == '\0') {
    puVar2 = (ushort *)(param_2 + 0x33833eff + (int)puVar10);
    sVar5 = ((ushort)unaff_ESI & 3) - (*puVar2 & 3);
    *puVar2 = *puVar2 + (ushort)(0 < sVar5) * sVar5;
    if (0 < sVar5) {
      bVar13 = ((int)(short)puVar10 & 0x8a68c178U) == 0;
      *(undefined2 *)(uVar4 + iVar11 + -1) = in_CS;
      *(undefined4 *)(uVar4 + iVar11 + -5) = 0x8f09a2;
      iVar11 = func_0xfe66edf0();
      if (!bVar13) {
        pcVar6 = (code *)swi(3);
        iVar11 = (*pcVar6)();
        return iVar11;
      }
      if (iVar11 < -0x33c4c4c0) {
        if (extraout_ECX != 1) {
          return *(int *)(CONCAT22((short)((uint)iVar11 >> 0x10),
                                   (ushort)(byte)((char)iVar11 + (char)((uint)iVar11 >> 8) * '\r'))
                         + 0x49c41c46) * -0x4a4cb5ed;
        }
        return iVar11;
      }
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  puVar1 = (uint *)(unaff_EDI + -0x1db8e1ce);
  *puVar1 = *puVar1 >> 1 | (uint)((*puVar1 & 1) != 0) << 0x1f;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* VA 008f1000 */

/* WARNING: Instruction at (ram,0x008f1641) overlaps instruction at (ram,0x008f1640)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008f1388) */
/* WARNING: Removing unreachable block (ram,0x008f138c) */
/* WARNING: Removing unreachable block (ram,0x008f1503) */
/* WARNING: Removing unreachable block (ram,0x008f1507) */
/* WARNING: Removing unreachable block (ram,0x008f1669) */
/* WARNING: Removing unreachable block (ram,0x008f166d) */
/* WARNING: Removing unreachable block (ram,0x008f174e) */
/* WARNING: Removing unreachable block (ram,0x008f1752) */
/* WARNING: Removing unreachable block (ram,0x008f17d5) */
/* WARNING: Removing unreachable block (ram,0x008f183c) */
/* WARNING: Removing unreachable block (ram,0x008f16af) */
/* WARNING: Removing unreachable block (ram,0x008f13a0) */
/* WARNING: Removing unreachable block (ram,0x008f13a4) */
/* WARNING: Removing unreachable block (ram,0x008f13ac) */
/* WARNING: Removing unreachable block (ram,0x008f13b0) */
/* WARNING: Removing unreachable block (ram,0x008f1394) */
/* WARNING: Removing unreachable block (ram,0x008f150f) */
/* WARNING: Removing unreachable block (ram,0x008f1513) */
/* WARNING: Removing unreachable block (ram,0x008f1813) */
/* WARNING: Removing unreachable block (ram,0x008f172e) */
/* WARNING: Removing unreachable block (ram,0x008f1734) */
/* WARNING: Removing unreachable block (ram,0x008f16e6) */
/* WARNING: Removing unreachable block (ram,0x008f17f4) */
/* WARNING: Removing unreachable block (ram,0x008f185a) */
/* WARNING: Removing unreachable block (ram,0x008f1791) */
/* WARNING: Removing unreachable block (ram,0x008f163f) */
/* WARNING: Removing unreachable block (ram,0x008f168f) */
/* WARNING: Removing unreachable block (ram,0x008f1692) */
/* WARNING: Removing unreachable block (ram,0x008f16d6) */
/* WARNING: Removing unreachable block (ram,0x008f16e2) */
/* WARNING: Removing unreachable block (ram,0x008f16dd) */
/* WARNING: Removing unreachable block (ram,0x008f16a4) */
/* WARNING: Removing unreachable block (ram,0x008f16ab) */
/* WARNING: Removing unreachable block (ram,0x008f16a6) */
/* WARNING: Removing unreachable block (ram,0x008f16d4) */
/* WARNING: Removing unreachable block (ram,0x008f16e7) */
/* WARNING: Removing unreachable block (ram,0x008f170b) */
/* WARNING: Removing unreachable block (ram,0x008f16ec) */
/* WARNING: Removing unreachable block (ram,0x008f16f3) */
/* WARNING: Removing unreachable block (ram,0x008f16ee) */
/* WARNING: Removing unreachable block (ram,0x008f16ff) */
/* WARNING: Removing unreachable block (ram,0x008f1703) */
/* WARNING: Removing unreachable block (ram,0x008f16f7) */
/* WARNING: Removing unreachable block (ram,0x008f16fa) */
/* WARNING: Removing unreachable block (ram,0x008f170a) */
/* WARNING: Removing unreachable block (ram,0x008f160f) */
/* WARNING: Removing unreachable block (ram,0x008f15f7) */
/* WARNING: Removing unreachable block (ram,0x008f15eb) */
/* WARNING: Removing unreachable block (ram,0x008f15d3) */
/* WARNING: Removing unreachable block (ram,0x008f15bb) */
/* WARNING: Removing unreachable block (ram,0x008f157f) */
/* WARNING: Removing unreachable block (ram,0x008f1567) */
/* WARNING: Removing unreachable block (ram,0x008f154f) */
/* WARNING: Removing unreachable block (ram,0x008f1537) */
/* WARNING: Removing unreachable block (ram,0x008f151b) */
/* WARNING: Removing unreachable block (ram,0x008f151f) */
/* WARNING: Removing unreachable block (ram,0x008f14b8) */
/* WARNING: Removing unreachable block (ram,0x008f144c) */
/* WARNING: Removing unreachable block (ram,0x008f1434) */
/* WARNING: Removing unreachable block (ram,0x008f141c) */
/* WARNING: Removing unreachable block (ram,0x008f13f8) */
/* WARNING: Removing unreachable block (ram,0x008f13e0) */
/* WARNING: Removing unreachable block (ram,0x008f13bc) */
/* WARNING: Removing unreachable block (ram,0x008f13b8) */
/* WARNING: Removing unreachable block (ram,0x008f131f) */
/* WARNING: Removing unreachable block (ram,0x008f1307) */
/* WARNING: Removing unreachable block (ram,0x008f12ef) */
/* WARNING: Removing unreachable block (ram,0x008f12d7) */
/* WARNING: Removing unreachable block (ram,0x008f12bf) */
/* WARNING: Removing unreachable block (ram,0x008f12a7) */
/* WARNING: Removing unreachable block (ram,0x008f129b) */
/* WARNING: Removing unreachable block (ram,0x008f1283) */
/* WARNING: Removing unreachable block (ram,0x008f126b) */
/* WARNING: Removing unreachable block (ram,0x008f122f) */
/* WARNING: Removing unreachable block (ram,0x008f1217) */
/* WARNING: Removing unreachable block (ram,0x008f11f3) */
/* WARNING: Removing unreachable block (ram,0x008f11e7) */
/* WARNING: Removing unreachable block (ram,0x008f11c3) */
/* WARNING: Removing unreachable block (ram,0x008f11a6) */
/* WARNING: Removing unreachable block (ram,0x008f118e) */
/* WARNING: Removing unreachable block (ram,0x008f116a) */
/* WARNING: Removing unreachable block (ram,0x008f1152) */
/* WARNING: Removing unreachable block (ram,0x008f113a) */
/* WARNING: Removing unreachable block (ram,0x008f1122) */
/* WARNING: Removing unreachable block (ram,0x008f10fe) */
/* WARNING: Removing unreachable block (ram,0x008f10e6) */
/* WARNING: Removing unreachable block (ram,0x008f1092) */
/* WARNING: Removing unreachable block (ram,0x008f106e) */
/* WARNING: Removing unreachable block (ram,0x008f1056) */
/* WARNING: Removing unreachable block (ram,0x008f103e) */
/* WARNING: Removing unreachable block (ram,0x008f1026) */
/* WARNING: Removing unreachable block (ram,0x008f100e) */
/* WARNING: Removing unreachable block (ram,0x008f101a) */
/* WARNING: Removing unreachable block (ram,0x008f1032) */
/* WARNING: Removing unreachable block (ram,0x008f104a) */
/* WARNING: Removing unreachable block (ram,0x008f1062) */
/* WARNING: Removing unreachable block (ram,0x008f107a) */
/* WARNING: Removing unreachable block (ram,0x008f109e) */
/* WARNING: Removing unreachable block (ram,0x008f10c2) */
/* WARNING: Removing unreachable block (ram,0x008f10da) */
/* WARNING: Removing unreachable block (ram,0x008f10f2) */
/* WARNING: Removing unreachable block (ram,0x008f1116) */
/* WARNING: Removing unreachable block (ram,0x008f112e) */
/* WARNING: Removing unreachable block (ram,0x008f1146) */
/* WARNING: Removing unreachable block (ram,0x008f115e) */
/* WARNING: Removing unreachable block (ram,0x008f1182) */
/* WARNING: Removing unreachable block (ram,0x008f119a) */
/* WARNING: Removing unreachable block (ram,0x008f11b2) */
/* WARNING: Removing unreachable block (ram,0x008f11db) */
/* WARNING: Removing unreachable block (ram,0x008f1223) */
/* WARNING: Removing unreachable block (ram,0x008f123b) */
/* WARNING: Removing unreachable block (ram,0x008f1247) */
/* WARNING: Removing unreachable block (ram,0x008f125f) */
/* WARNING: Removing unreachable block (ram,0x008f1277) */
/* WARNING: Removing unreachable block (ram,0x008f128f) */
/* WARNING: Removing unreachable block (ram,0x008f12cb) */
/* WARNING: Removing unreachable block (ram,0x008f12e3) */
/* WARNING: Removing unreachable block (ram,0x008f12fb) */
/* WARNING: Removing unreachable block (ram,0x008f1313) */
/* WARNING: Removing unreachable block (ram,0x008f132b) */
/* WARNING: Removing unreachable block (ram,0x008f1343) */
/* WARNING: Removing unreachable block (ram,0x008f13c4) */
/* WARNING: Removing unreachable block (ram,0x008f13c8) */
/* WARNING: Removing unreachable block (ram,0x008f13ec) */
/* WARNING: Removing unreachable block (ram,0x008f1404) */
/* WARNING: Removing unreachable block (ram,0x008f1428) */
/* WARNING: Removing unreachable block (ram,0x008f1440) */
/* WARNING: Removing unreachable block (ram,0x008f1458) */
/* WARNING: Removing unreachable block (ram,0x008f1488) */
/* WARNING: Removing unreachable block (ram,0x008f14c4) */
/* WARNING: Removing unreachable block (ram,0x008f152b) */
/* WARNING: Removing unreachable block (ram,0x008f1543) */
/* WARNING: Removing unreachable block (ram,0x008f155b) */
/* WARNING: Removing unreachable block (ram,0x008f1573) */
/* WARNING: Removing unreachable block (ram,0x008f158b) */
/* WARNING: Removing unreachable block (ram,0x008f1597) */
/* WARNING: Removing unreachable block (ram,0x008f15af) */
/* WARNING: Removing unreachable block (ram,0x008f15c7) */
/* WARNING: Removing unreachable block (ram,0x008f15df) */
/* WARNING: Removing unreachable block (ram,0x008f161b) */
/* WARNING: Removing unreachable block (ram,0x008f1627) */
/* WARNING: Removing unreachable block (ram,0x008f1771) */
/* WARNING: Removing unreachable block (ram,0x008f17e8) */
/* WARNING: Removing unreachable block (ram,0x008f177d) */
/* WARNING: Removing unreachable block (ram,0x008f17a9) */
/* WARNING: Removing unreachable block (ram,0x008f17af) */
/* WARNING: Removing unreachable block (ram,0x008f17b3) */
/* WARNING: Removing unreachable block (ram,0x008f17d1) */
/* WARNING: Removing unreachable block (ram,0x008f17cc) */
/* WARNING: Removing unreachable block (ram,0x008f17e4) */
/* WARNING: Removing unreachable block (ram,0x008f17df) */
/* WARNING: Removing unreachable block (ram,0x008f17f0) */
/* WARNING: Removing unreachable block (ram,0x008f17eb) */
/* WARNING: Removing unreachable block (ram,0x008f17fc) */
/* WARNING: Removing unreachable block (ram,0x008f17f7) */
/* WARNING: Removing unreachable block (ram,0x008f1800) */
/* WARNING: Removing unreachable block (ram,0x008f1801) */
/* WARNING: Removing unreachable block (ram,0x008f180f) */
/* WARNING: Removing unreachable block (ram,0x008f180a) */
/* WARNING: Removing unreachable block (ram,0x008f1819) */
/* WARNING: Removing unreachable block (ram,0x008f1838) */
/* WARNING: Removing unreachable block (ram,0x008f1833) */
/* WARNING: Removing unreachable block (ram,0x008f1847) */
/* WARNING: Removing unreachable block (ram,0x008f1842) */
/* WARNING: Removing unreachable block (ram,0x008f1856) */
/* WARNING: Removing unreachable block (ram,0x008f184b) */
/* WARNING: Removing unreachable block (ram,0x008f1851) */
/* WARNING: Removing unreachable block (ram,0x008f1860) */
/* WARNING: Removing unreachable block (ram,0x008f1710) */
/* WARNING: Removing unreachable block (ram,0x008f1866) */
/* WARNING: Removing unreachable block (ram,0x008f1716) */
/* WARNING: Removing unreachable block (ram,0x008f171e) */
/* WARNING: Removing unreachable block (ram,0x008f1723) */
/* WARNING: Removing unreachable block (ram,0x008f172a) */
/* WARNING: Removing unreachable block (ram,0x008f1725) */
/* WARNING: Removing unreachable block (ram,0x008f1761) */
/* WARNING: Removing unreachable block (ram,0x008f175c) */
/* WARNING: Removing unreachable block (ram,0x008f176d) */
/* WARNING: Removing unreachable block (ram,0x008f1765) */
/* WARNING: Removing unreachable block (ram,0x008f1768) */
/* WARNING: Removing unreachable block (ram,0x008f1779) */
/* WARNING: Removing unreachable block (ram,0x008f1774) */
/* WARNING: Removing unreachable block (ram,0x008f178d) */
/* WARNING: Removing unreachable block (ram,0x008f1788) */
/* WARNING: Removing unreachable block (ram,0x008f178a) */
/* WARNING: Removing unreachable block (ram,0x008f1799) */
/* WARNING: Removing unreachable block (ram,0x008f179d) */
/* WARNING: Removing unreachable block (ram,0x008f1794) */
/* WARNING: Removing unreachable block (ram,0x008f17a5) */
/* WARNING: Removing unreachable block (ram,0x008f17a0) */
/* WARNING: Removing unreachable block (ram,0x008f140c) */
/* WARNING: Removing unreachable block (ram,0x008f1410) */
/* WARNING: Removing unreachable block (ram,0x008f160b) */
/* WARNING: Removing unreachable block (ram,0x008f15e7) */
/* WARNING: Removing unreachable block (ram,0x008f15db) */
/* WARNING: Removing unreachable block (ram,0x008f15ab) */
/* WARNING: Removing unreachable block (ram,0x008f159f) */
/* WARNING: Removing unreachable block (ram,0x008f15a3) */
/* WARNING: Removing unreachable block (ram,0x008f157b) */
/* WARNING: Removing unreachable block (ram,0x008f156f) */
/* WARNING: Removing unreachable block (ram,0x008f154b) */
/* WARNING: Removing unreachable block (ram,0x008f153f) */
/* WARNING: Removing unreachable block (ram,0x008f14d0) */
/* WARNING: Removing unreachable block (ram,0x008f14db) */
/* WARNING: Removing unreachable block (ram,0x008f1460) */
/* WARNING: Removing unreachable block (ram,0x008f1464) */
/* WARNING: Removing unreachable block (ram,0x008f143c) */
/* WARNING: Removing unreachable block (ram,0x008f1448) */
/* WARNING: Removing unreachable block (ram,0x008f1454) */
/* WARNING: Removing unreachable block (ram,0x008f1527) */
/* WARNING: Removing unreachable block (ram,0x008f1533) */
/* WARNING: Removing unreachable block (ram,0x008f1557) */
/* WARNING: Removing unreachable block (ram,0x008f1563) */
/* WARNING: Removing unreachable block (ram,0x008f1587) */
/* WARNING: Removing unreachable block (ram,0x008f1593) */
/* WARNING: Removing unreachable block (ram,0x008f15c3) */
/* WARNING: Removing unreachable block (ram,0x008f15cf) */
/* WARNING: Removing unreachable block (ram,0x008f15f3) */
/* WARNING: Removing unreachable block (ram,0x008f15ff) */
/* WARNING: Removing unreachable block (ram,0x008f1603) */
/* WARNING: Removing unreachable block (ram,0x008f13d0) */
/* WARNING: Removing unreachable block (ram,0x008f13d4) */
/* WARNING: Removing unreachable block (ram,0x008f1337) */
/* WARNING: Removing unreachable block (ram,0x008f163b) */
/* WARNING: Removing unreachable block (ram,0x008f1617) */
/* WARNING: Removing unreachable block (ram,0x008f146c) */
/* WARNING: Removing unreachable block (ram,0x008f1470) */
/* WARNING: Removing unreachable block (ram,0x008f13dc) */
/* WARNING: Removing unreachable block (ram,0x008f1253) */
/* WARNING: Removing unreachable block (ram,0x008f11cf) */
/* WARNING: Removing unreachable block (ram,0x008f10ce) */
/* WARNING: Removing unreachable block (ram,0x008f1086) */
/* WARNING: Removing unreachable block (ram,0x008f10aa) */
/* WARNING: Removing unreachable block (ram,0x008f110a) */
/* WARNING: Removing unreachable block (ram,0x008f12b3) */
/* WARNING: Removing unreachable block (ram,0x008f134f) */
/* WARNING: Removing unreachable block (ram,0x008f1418) */
/* WARNING: Removing unreachable block (ram,0x008f1478) */
/* WARNING: Removing unreachable block (ram,0x008f147c) */
/* WARNING: Removing unreachable block (ram,0x008f162f) */
/* WARNING: Removing unreachable block (ram,0x008f1633) */
/* WARNING: Removing unreachable block (ram,0x008f11ff) */
/* WARNING: Removing unreachable block (ram,0x008f1176) */
/* WARNING: Removing unreachable block (ram,0x008f14b4) */
/* WARNING: Removing unreachable block (ram,0x008f1484) */
/* WARNING: Removing unreachable block (ram,0x008f14a8) */
/* WARNING: Removing unreachable block (ram,0x008f14ac) */
/* WARNING: Removing unreachable block (ram,0x008f1490) */
/* WARNING: Removing unreachable block (ram,0x008f1494) */
/* WARNING: Removing unreachable block (ram,0x008f120b) */
/* WARNING: Removing unreachable block (ram,0x008f14c0) */
/* WARNING: Removing unreachable block (ram,0x008f135b) */
/* WARNING: Removing unreachable block (ram,0x008f149c) */
/* WARNING: Removing unreachable block (ram,0x008f10b6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall Ox77F052CC(void *this)

{
  undefined1 in_PF;

                    /* 0x11000  2  Ox77F052CC */
  func_0x008f1d70();
  if ((!(bool)in_PF) && ((bool)in_PF)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x008e5ec0();
  func_0x008f2040();
  FUN_008f1650();
  return 0;
}



/* VA 008f1650 */

/* WARNING: Instruction at (ram,0x008f1708) overlaps instruction at (ram,0x008f1707)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008f1669) */
/* WARNING: Removing unreachable block (ram,0x008f166d) */
/* WARNING: Removing unreachable block (ram,0x008f174e) */
/* WARNING: Removing unreachable block (ram,0x008f1752) */
/* WARNING: Removing unreachable block (ram,0x008f17d5) */
/* WARNING: Removing unreachable block (ram,0x008f183c) */
/* WARNING: Removing unreachable block (ram,0x008f16af) */
/* WARNING: Removing unreachable block (ram,0x008f1813) */
/* WARNING: Removing unreachable block (ram,0x008f172e) */
/* WARNING: Removing unreachable block (ram,0x008f1734) */
/* WARNING: Removing unreachable block (ram,0x008f16e6) */
/* WARNING: Removing unreachable block (ram,0x008f17f4) */
/* WARNING: Removing unreachable block (ram,0x008f185a) */
/* WARNING: Removing unreachable block (ram,0x008f1791) */
/* WARNING: Removing unreachable block (ram,0x008f1771) */
/* WARNING: Removing unreachable block (ram,0x008f17e8) */
/* WARNING: Removing unreachable block (ram,0x008f177d) */
/* WARNING: Removing unreachable block (ram,0x008f17a9) */
/* WARNING: Removing unreachable block (ram,0x008f1765) */
/* WARNING: Removing unreachable block (ram,0x008f1800) */
/* WARNING: Removing unreachable block (ram,0x008f179d) */
/* WARNING: Removing unreachable block (ram,0x008f184b) */
/* WARNING: Removing unreachable block (ram,0x008f16f3) */
/* WARNING: Removing unreachable block (ram,0x008f16f7) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff4 : 0x008f172f */
/* WARNING: Removing unreachable block (ram,0x008f16ff) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_008f1650(void)

{
  byte *pbVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  uint uVar6;
  uint unaff_EBX;
  uint uVar7;
  bool bVar8;
  byte *in_stack_00000010;
  byte abStackY_1011 [4073];
  uint in_stack_fffffff4;

  FUN_008f5470();
  bVar8 = false;
  iVar4 = FUN_008fe750((undefined4 *)&stack0x00000004,1,0,(undefined4 *)&stack0xfffffff0,
                       (uint *)&stack0xfffffff8,(uint *)&stack0xfffffff4);
  pbVar1 = in_stack_00000010;
  iVar5 = 0;
  if (iVar4 != 0) {
    do {
      bVar2 = FUN_008fea50((undefined4 *)&stack0x00000004,iVar4,pbVar1);
      iVar5 = CONCAT31(extraout_var,bVar2);
      if (iVar5 != 0) {
        bVar8 = true;
        goto LAB_008f16e7;
      }
      iVar4 = FUN_008fe750((undefined4 *)&stack0x00000004,1,iVar4 + 0x28,
                           (undefined4 *)&stack0xfffffff0,(uint *)&stack0xfffffff8,
                           (uint *)&stack0xfffffff4);
    } while (iVar4 != 0);
    iVar5 = 0;
  }
LAB_008f16e7:
                    /* WARNING: Bad instruction - Truncating control flow here */
  if (bVar8) {
    for (; unaff_EBX != 0; unaff_EBX = unaff_EBX - uVar7) {
      uVar7 = unaff_EBX;
      if (0xfff < unaff_EBX) {
        uVar7 = 0x1000;
      }
      FUN_008f18f0((int)&stack0x00000004,in_stack_fffffff4,uVar7,(undefined4 *)(abStackY_1011 + 1));
      bVar3 = abStackY_1011[1];
      abStackY_1011[1] = abStackY_1011[1] ^ 0x43;
      bVar3 = bVar3 ^ 0x56;
      uVar6 = 1;
      bVar8 = 1 < uVar7;
      while (bVar8) {
        abStackY_1011[uVar6 + 1] = abStackY_1011[uVar6 + 1] ^ abStackY_1011[uVar6];
        abStackY_1011[uVar6 + 1] = abStackY_1011[uVar6 + 1] + bVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
        bVar3 = bVar3 + abStackY_1011[uVar6 + 1];
        uVar6 = uVar6 + 1;
        bVar8 = uVar6 < uVar7;
      }
      iVar5 = FUN_008f1870(in_stack_fffffff4,(byte)&stack0x00000004,(int)&stack0x00000004,
                           in_stack_fffffff4,uVar7,(undefined4 *)(abStackY_1011 + 1));
      in_stack_fffffff4 = in_stack_fffffff4 + uVar7;
    }
    return iVar5;
  }
  return iVar5;
}



/* VA 008f1870 */

/* WARNING: Instruction at (ram,0x008f18c8) overlaps instruction at (ram,0x008f18c6)
    */
/* WARNING: Removing unreachable block (ram,0x008f188b) */
/* WARNING: Removing unreachable block (ram,0x008f18c2) */

void __fastcall
FUN_008f1870(undefined4 param_1,byte param_2,int param_3,uint param_4,uint param_5,
            undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;

  puVar3 = (undefined4 *)(*(int *)(param_3 + 4) + param_4);
  iVar1 = (*DAT_0090b0f0)(puVar3);
  if (iVar1 != 0) {
    puVar4 = puVar3;
    for (uVar2 = param_5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *param_6;
      param_6 = param_6 + 1;
      puVar4 = puVar4 + 1;
    }
    uVar2 = param_5 & 3;
    bVar5 = (POPCOUNT(uVar2) & 1U) == 0;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_6;
      param_6 = (undefined4 *)((int)param_6 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    (*DAT_0090b0f0)(puVar3,param_5,param_3);
    if ((!bVar5) && (bVar5)) {
      *(uint *)((int)puVar4 + 0x5e) = *(uint *)((int)puVar4 + 0x5e) & (uint)puVar3;
    }
  }
  return;
}



/* VA 008f18f0 */

/* WARNING: Instruction at (ram,0x008f1911) overlaps instruction at (ram,0x008f190f)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008f192b) */
/* WARNING: Removing unreachable block (ram,0x008f190b) */

void FUN_008f18f0(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 *puVar2;

  puVar2 = (undefined4 *)(*(int *)(param_1 + 4) + param_2);
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_4 = *puVar2;
    puVar2 = puVar2 + 1;
    param_4 = param_4 + 1;
  }
  for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)param_4 = *(undefined1 *)puVar2;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    param_4 = (undefined4 *)((int)param_4 + 1);
  }
  return;
}



/* VA 008f1930 */

/* WARNING: Instruction at (ram,0x008f1c45) overlaps instruction at (ram,0x008f1c43)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008f1bdc) */
/* WARNING: Removing unreachable block (ram,0x008f1be0) */
/* WARNING: Removing unreachable block (ram,0x008f1c52) */
/* WARNING: Removing unreachable block (ram,0x008f1c56) */
/* WARNING: Removing unreachable block (ram,0x008f1bf4) */
/* WARNING: Removing unreachable block (ram,0x008f1bf8) */
/* WARNING: Removing unreachable block (ram,0x008f194d) */
/* WARNING: Removing unreachable block (ram,0x008f1951) */
/* WARNING: Removing unreachable block (ram,0x008f1be8) */
/* WARNING: Removing unreachable block (ram,0x008f1c92) */
/* WARNING: Removing unreachable block (ram,0x008f1c7a) */
/* WARNING: Removing unreachable block (ram,0x008f1c62) */
/* WARNING: Removing unreachable block (ram,0x008f1c34) */
/* WARNING: Removing unreachable block (ram,0x008f1c1c) */
/* WARNING: Removing unreachable block (ram,0x008f1c04) */
/* WARNING: Removing unreachable block (ram,0x008f1c00) */
/* WARNING: Removing unreachable block (ram,0x008f1b6c) */
/* WARNING: Removing unreachable block (ram,0x008f1b48) */
/* WARNING: Removing unreachable block (ram,0x008f1b24) */
/* WARNING: Removing unreachable block (ram,0x008f1afd) */
/* WARNING: Removing unreachable block (ram,0x008f1ae5) */
/* WARNING: Removing unreachable block (ram,0x008f1ac1) */
/* WARNING: Removing unreachable block (ram,0x008f1a9d) */
/* WARNING: Removing unreachable block (ram,0x008f1a85) */
/* WARNING: Removing unreachable block (ram,0x008f1a6d) */
/* WARNING: Removing unreachable block (ram,0x008f1a61) */
/* WARNING: Removing unreachable block (ram,0x008f1a49) */
/* WARNING: Removing unreachable block (ram,0x008f1a1d) */
/* WARNING: Removing unreachable block (ram,0x008f19f9) */
/* WARNING: Removing unreachable block (ram,0x008f19c9) */
/* WARNING: Removing unreachable block (ram,0x008f19b1) */
/* WARNING: Removing unreachable block (ram,0x008f1999) */
/* WARNING: Removing unreachable block (ram,0x008f1981) */
/* WARNING: Removing unreachable block (ram,0x008f1969) */
/* WARNING: Removing unreachable block (ram,0x008f1959) */
/* WARNING: Removing unreachable block (ram,0x008f1975) */
/* WARNING: Removing unreachable block (ram,0x008f198d) */
/* WARNING: Removing unreachable block (ram,0x008f19a5) */
/* WARNING: Removing unreachable block (ram,0x008f19bd) */
/* WARNING: Removing unreachable block (ram,0x008f19ed) */
/* WARNING: Removing unreachable block (ram,0x008f1a11) */
/* WARNING: Removing unreachable block (ram,0x008f1a3d) */
/* WARNING: Removing unreachable block (ram,0x008f1a55) */
/* WARNING: Removing unreachable block (ram,0x008f1a91) */
/* WARNING: Removing unreachable block (ram,0x008f1aa9) */
/* WARNING: Removing unreachable block (ram,0x008f1acd) */
/* WARNING: Removing unreachable block (ram,0x008f1af1) */
/* WARNING: Removing unreachable block (ram,0x008f1b09) */
/* WARNING: Removing unreachable block (ram,0x008f1b30) */
/* WARNING: Removing unreachable block (ram,0x008f1b54) */
/* WARNING: Removing unreachable block (ram,0x008f1b78) */
/* WARNING: Removing unreachable block (ram,0x008f1b84) */
/* WARNING: Removing unreachable block (ram,0x008f1c0c) */
/* WARNING: Removing unreachable block (ram,0x008f1c10) */
/* WARNING: Removing unreachable block (ram,0x008f1c28) */
/* WARNING: Removing unreachable block (ram,0x008f1c40) */
/* WARNING: Removing unreachable block (ram,0x008f1c46) */
/* WARNING: Removing unreachable block (ram,0x008f1c47) */
/* WARNING: Removing unreachable block (ram,0x008f1c6e) */
/* WARNING: Removing unreachable block (ram,0x008f1c86) */
/* WARNING: Removing unreachable block (ram,0x008f1c9e) */
/* WARNING: Removing unreachable block (ram,0x008f1caa) */
/* WARNING: Removing unreachable block (ram,0x008f1cb2) */
/* WARNING: Removing unreachable block (ram,0x008f1cb6) */
/* WARNING: Removing unreachable block (ram,0x008f1c9a) */
/* WARNING: Removing unreachable block (ram,0x008f1c82) */
/* WARNING: Removing unreachable block (ram,0x008f1c3c) */
/* WARNING: Removing unreachable block (ram,0x008f1c24) */
/* WARNING: Removing unreachable block (ram,0x008f1a0d) */
/* WARNING: Removing unreachable block (ram,0x008f19e9) */
/* WARNING: Removing unreachable block (ram,0x008f19b9) */
/* WARNING: Removing unreachable block (ram,0x008f19a1) */
/* WARNING: Removing unreachable block (ram,0x008f1989) */
/* WARNING: Removing unreachable block (ram,0x008f1971) */
/* WARNING: Removing unreachable block (ram,0x008f1965) */
/* WARNING: Removing unreachable block (ram,0x008f197d) */
/* WARNING: Removing unreachable block (ram,0x008f1995) */
/* WARNING: Removing unreachable block (ram,0x008f19ad) */
/* WARNING: Removing unreachable block (ram,0x008f19c5) */
/* WARNING: Removing unreachable block (ram,0x008f1a01) */
/* WARNING: Removing unreachable block (ram,0x008f1a05) */
/* WARNING: Removing unreachable block (ram,0x008f1c18) */
/* WARNING: Removing unreachable block (ram,0x008f1c30) */
/* WARNING: Removing unreachable block (ram,0x008f1c5e) */
/* WARNING: Removing unreachable block (ram,0x008f1c8e) */
/* WARNING: Removing unreachable block (ram,0x008f1ca6) */
/* WARNING: Removing unreachable block (ram,0x008f19d1) */
/* WARNING: Removing unreachable block (ram,0x008f19d5) */
/* WARNING: Removing unreachable block (ram,0x008f1b60) */
/* WARNING: Removing unreachable block (ram,0x008f1ad9) */
/* WARNING: Removing unreachable block (ram,0x008f1a79) */
/* WARNING: Removing unreachable block (ram,0x008f1ab5) */
/* WARNING: Removing unreachable block (ram,0x008f1b3c) */
/* WARNING: Removing unreachable block (ram,0x008f19dd) */
/* WARNING: Removing unreachable block (ram,0x008f1a39) */

uint _DllMain_12(undefined4 param_1,int param_2)

{
  char *pcVar1;

                    /* 0x11930  1  _DllMain@12 */
  if ((param_2 != 0) && (param_2 == 1)) {
    FUN_008fef0b();
    pcVar1 = (char *)0x67;
    FUN_008f2450(0x90b860,0x67);
    FUN_0090102c(0,pcVar1);
    pvRam0090b860 = GetCurrentProcess();
    uRam0090b864 = FUN_008feb72((char *)0x907030);
    func_0x008f1f80();
    func_0x008eeffa();
    func_0x008effef();
                    /* WARNING: Bad instruction - Truncating control flow here */
  }
  return 1;
}



/* VA 008f20b0 */

short __cdecl FUN_008f20b0(char *param_1)

{
  short *psVar1;

  psVar1 = FUN_008f23d0(param_1);
  if (psVar1 != (short *)0x0) {
    return psVar1[8];
  }
  return 0;
}



/* VA 008f20d0 */

void __cdecl FUN_008f20d0(char *param_1,uint param_2,int param_3,uint param_4)

{
  int *piVar1;
  short *psVar2;
  undefined4 uVar3;

  psVar2 = FUN_008f23d0(param_1);
  if (psVar2 != (short *)0x0) {
    piVar1 = *(int **)(psVar2 + param_4 * 2 + 10);
    FUN_008f3c60(piVar1,param_2);
    uVar3 = FUN_008f3540(piVar1,param_2,param_3,param_4);
    if ((short)uVar3 == 0) {
      uVar3 = FUN_008f3570(piVar1,param_2,param_3,param_4);
      if ((short)uVar3 == 0) {
        FUN_008f35d0(piVar1,param_2,param_3,param_4);
      }
    }
  }
  return;
}



/* VA 008f2140 */

uint __cdecl FUN_008f2140(char *param_1,uint *param_2,uint *param_3,uint param_4,short param_5)

{
  uint uVar1;
  uint in_EAX;
  short *psVar2;
  uint uVar3;

  if (((param_2 != (uint *)0x0) && (param_3 != (uint *)0x0)) &&
     (in_EAX = *param_2, in_EAX < *param_3)) {
    psVar2 = FUN_008f23d0(param_1);
    in_EAX = 0;
    if (psVar2 != (short *)0x0) {
      uVar3 = *param_2;
      uVar1 = *param_3;
      if ((uVar3 != 0) && ((uVar3 & 0xfff) == 0)) {
        uVar3 = uVar3 - 1;
      }
      if (((uVar3 < *(uint *)(psVar2 + 0x1a)) || (*(uint *)(psVar2 + 0x1c) < uVar1)) ||
         (((uVar3 ^ *(uint *)(psVar2 + 0x1a)) & 0xfffff000) != 0)) {
        if (DAT_0090b0d4 != 0) {
          if (param_5 == 0) {
            FUN_008f3db0((char *)(psVar2 + 2));
          }
          else {
            FUN_008f3dc0((char *)(psVar2 + 2),uVar3,uVar1);
          }
          DAT_0090b0d4 = 0;
        }
        if (param_5 != 0) {
          FUN_008f3ca0((char *)(psVar2 + 2),*(uint *)(psVar2 + 0x36),*(undefined4 **)(psVar2 + 0x38)
                       ,uVar3,uVar1,1);
          DAT_0090b0d4 = 1;
        }
        *(uint *)(psVar2 + 0x1a) = uVar3;
        *(uint *)(psVar2 + 0x1c) = uVar1;
      }
      uVar3 = FUN_008f3bc0((undefined4 *)(psVar2 + 10),param_2,param_3,param_4);
      return uVar3;
    }
  }
  return in_EAX & 0xffff0000;
}



/* VA 008f2240 */

void __cdecl FUN_008f2240(char *param_1,int param_2)

{
  short *psVar1;

  psVar1 = FUN_008f23d0(param_1);
  if (psVar1 != (short *)0x0) {
    FUN_008f3830(*(int **)(psVar1 + param_2 * 2 + 10));
  }
  return;
}



/* VA 008f2270 */

void __cdecl FUN_008f2270(char *param_1,int param_2,uint param_3,uint param_4)

{
  short *psVar1;

  psVar1 = FUN_008f23d0(param_1);
  if (psVar1 != (short *)0x0) {
    FUN_008f38a0(*(int **)(psVar1 + param_2 * 2 + 10),param_3,param_4);
  }
  return;
}



/* VA 008f22a0 */

undefined4 __cdecl FUN_008f22a0(char *param_1)

{
  short *psVar1;

  psVar1 = FUN_008f23d0(param_1);
  if (psVar1 != (short *)0x0) {
    return *(undefined4 *)(psVar1 + 0x62);
  }
  return 0;
}



/* VA 008f22c0 */

undefined4 __cdecl FUN_008f22c0(char *param_1,undefined4 param_2)

{
  short *psVar1;

  psVar1 = FUN_008f23d0(param_1);
  if (psVar1 != (short *)0x0) {
    *(undefined4 *)(psVar1 + 0x62) = param_2;
    return CONCAT22((short)((uint)psVar1 >> 0x10),1);
  }
  return 0;
}



/* VA 008f22f0 */

undefined4 __cdecl FUN_008f22f0(char *param_1)

{
  short *psVar1;

  psVar1 = FUN_008f23d0(param_1);
  if (psVar1 != (short *)0x0) {
    return *(undefined4 *)(psVar1 + 100);
  }
  return 0;
}



/* VA 008f2310 */

undefined4 __cdecl FUN_008f2310(char *param_1,undefined4 param_2)

{
  short *psVar1;

  psVar1 = FUN_008f23d0(param_1);
  if (psVar1 != (short *)0x0) {
    *(undefined4 *)(psVar1 + 100) = param_2;
    return CONCAT22((short)((uint)psVar1 >> 0x10),1);
  }
  return 0;
}



/* VA 008f23d0 */

short * __cdecl FUN_008f23d0(char *param_1)

{
  short *psVar1;
  int iVar2;
  short *psVar3;
  char *pcVar4;
  bool bVar5;

  psVar1 = &DAT_0090acd8;
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
    if (&DAT_0090b0d4 <= psVar1) {
      return (short *)0x0;
    }
  } while( true );
}



/* VA 008f2450 */

void __cdecl FUN_008f2450(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}



/* VA 008f2460 */

undefined4 __cdecl FUN_008f2460(undefined4 *param_1,LONG param_2,undefined4 *param_3,LPVOID param_4)

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



/* VA 008f2520 */

uint __cdecl FUN_008f2520(undefined4 *param_1,int param_2,uint param_3,undefined4 *param_4)

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
  iVar1 = (*DAT_0090b0e0)(*param_1,param_1[1] + param_2,param_4,param_3,&param_3);
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



/* VA 008f2690 */

uint __cdecl FUN_008f2690(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  ushort uVar1;
  uint in_EAX;
  undefined2 extraout_var;
  undefined4 uVar2;

  if (param_1[2] == 100) {
    return in_EAX & 0xffff0000;
  }
  if (DAT_0090b0e4 != 1) {
    uVar1 = FUN_008f26f0();
    if (uVar1 == 0) {
      return CONCAT22(extraout_var,uVar1);
    }
  }
  if (param_1[2] != 0x65) {
    uVar2 = FUN_008f2520(param_1,param_2,(uint)param_3,param_4);
    return uVar2;
  }
  uVar2 = FUN_008f2460(param_1,param_2,param_3,param_4);
  return uVar2;
}



/* VA 008f26f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_008f26f0(void)

{
  HMODULE pHVar1;
  ushort uVar2;

  if (DAT_0090b0e4 == 1) {
    return 1;
  }
  pHVar1 = FUN_008f2770(&DAT_00907228);
  if (pHVar1 != (HMODULE)0x0) {
    DAT_0090b0e0 = FUN_008f2830(pHVar1,&DAT_00907238);
    uVar2 = (ushort)(DAT_0090b0e0 != (FARPROC)0x0);
    _DAT_0090b0dc = FUN_008f2830(pHVar1,&DAT_00907250);
    if (_DAT_0090b0dc == (FARPROC)0x0) {
      uVar2 = 0;
    }
    _DAT_0090b0d8 = FUN_008f2830(pHVar1,&DAT_00907268);
    if (_DAT_0090b0d8 != (FARPROC)0x0) {
      DAT_0090b0e4 = uVar2;
      return uVar2;
    }
  }
  DAT_0090b0e4 = 0;
  return 0;
}



/* VA 008f2770 */

HMODULE __cdecl FUN_008f2770(char *param_1)

{
  char *lpLibFileName;
  HMODULE pHVar1;

  pHVar1 = (HMODULE)0x0;
  if (param_1 != (char *)0x0) {
    lpLibFileName = FUN_008f27b0(param_1);
    if (lpLibFileName != (char *)0x0) {
      pHVar1 = LoadLibraryA(lpLibFileName);
      FUN_008f5650(lpLibFileName);
    }
  }
  return pHVar1;
}



/* VA 008f27b0 */

char * __cdecl FUN_008f27b0(char *param_1)

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
  pcVar2 = (char *)FUN_008f56c0(~uVar3);
  if (pcVar2 != (char *)0x0) {
    FUN_008f27f0(pcVar2,param_1);
  }
  return pcVar2;
}



/* VA 008f27f0 */

char * __cdecl FUN_008f27f0(char *param_1,char *param_2)

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



/* VA 008f2830 */

FARPROC __cdecl FUN_008f2830(HMODULE param_1,char *param_2)

{
  char *lpProcName;
  FARPROC pFVar1;

  pFVar1 = (FARPROC)0x0;
  if (param_1 != (HMODULE)0x0) {
    lpProcName = FUN_008f27b0(param_2);
    if (lpProcName != (char *)0x0) {
      pFVar1 = GetProcAddress(param_1,lpProcName);
      FUN_008f5650(lpProcName);
    }
  }
  return pFVar1;
}



/* VA 008f34d0 */

int * __cdecl FUN_008f34d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)FUN_008f56c0(0xc);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = 0;
    piVar1[2] = 0;
    iVar2 = FUN_008f3f90(param_1,param_2,param_3);
    if (iVar2 != 0) {
      *piVar1 = iVar2;
      return piVar1;
    }
    FUN_008f5650((undefined *)piVar1);
  }
  return (int *)0x0;
}



/* VA 008f3520 */

void __cdecl FUN_008f3520(undefined4 *param_1)

{
  FUN_008f3fc0((undefined *)*param_1);
  FUN_008f5650((undefined *)param_1);
  return;
}



/* VA 008f3540 */

undefined4 __cdecl FUN_008f3540(int *param_1,uint param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;

  puVar1 = FUN_008f37c0(param_1,param_2,param_3,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    param_1[2] = (int)puVar1;
    return CONCAT22((short)((uint)puVar1 >> 0x10),1);
  }
  return 0;
}



/* VA 008f3570 */

undefined4 __cdecl FUN_008f3570(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined2 extraout_var;

  puVar1 = (undefined4 *)param_1[2];
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
  }
  puVar1 = FUN_008f3930(puVar1,param_2,param_3,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_008f3fd0((uint *)*puVar1,param_2,param_3);
    FUN_008f36c0((int)param_1,puVar1);
    param_1[2] = puVar1;
    return CONCAT22(extraout_var,1);
  }
  return 0;
}



/* VA 008f35d0 */

undefined4 __cdecl
FUN_008f35d0(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined2 extraout_var;

  puVar1 = (undefined4 *)param_1[2];
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
  }
  puVar1 = FUN_008f38f0(puVar1,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    piVar2 = FUN_008f34d0(param_2,param_3,param_4);
    FUN_008f3630((int)puVar1,piVar2);
    param_1[2] = puVar1[2];
    return CONCAT22(extraout_var,1);
  }
  return 0;
}



/* VA 008f3630 */

bool __cdecl FUN_008f3630(int param_1,undefined4 *param_2)

{
  int iVar1;

  if (param_2 != (undefined4 *)0x0) {
    param_2[1] = param_1;
    iVar1 = *(int *)(param_1 + 8);
    param_2[2] = iVar1;
    *(undefined4 **)(iVar1 + 4) = param_2;
    *(undefined4 **)(param_1 + 8) = param_2;
    FUN_008f3670(param_2);
  }
  return param_2 != (undefined4 *)0x0;
}



/* VA 008f3670 */

undefined4 __cdecl FUN_008f3670(undefined4 *param_1)

{
  short sVar1;
  undefined4 uVar2;

  uVar2 = 0;
  if (param_1 != (undefined4 *)0x0) {
    sVar1 = FUN_008f4210((uint *)*param_1,*(uint **)param_1[2]);
    if (sVar1 == 0) {
      sVar1 = FUN_008f4210((uint *)*param_1,*(uint **)param_1[1]);
      if (sVar1 == 0) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 008f36c0 */

void __cdecl FUN_008f36c0(int param_1,undefined4 *param_2)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;

  do {
    bVar1 = false;
    uVar3 = FUN_008f41d0((int *)*param_2,*(int **)param_2[2]);
    if ((short)uVar3 == 0) {
      sVar2 = FUN_008f4210((uint *)*param_2,*(uint **)param_2[2]);
      if (sVar2 != 0) goto LAB_008f36f9;
    }
    else {
LAB_008f36f9:
      FUN_008f3ff0((uint *)*param_2,*(uint **)param_2[2]);
      FUN_008f3780(param_1,(undefined4 *)param_2[2]);
      bVar1 = true;
    }
    uVar3 = FUN_008f41d0((int *)*param_2,*(int **)param_2[1]);
    if ((short)uVar3 == 0) {
      sVar2 = FUN_008f4210((uint *)*param_2,*(uint **)param_2[1]);
      if (sVar2 != 0) goto LAB_008f3748;
    }
    else {
LAB_008f3748:
      FUN_008f3ff0((uint *)*param_2,*(uint **)param_2[1]);
      FUN_008f3780(param_1,(undefined4 *)param_2[1]);
      bVar1 = true;
    }
    if (!bVar1) {
      return;
    }
  } while( true );
}



/* VA 008f3780 */

void __cdecl FUN_008f3780(int param_1,undefined4 *param_2)

{
  if (param_2 == *(undefined4 **)(param_1 + 8)) {
    *(undefined4 *)(param_1 + 8) = (*(undefined4 **)(param_1 + 8))[2];
  }
  if (param_2 == *(undefined4 **)(param_1 + 0xc)) {
    *(undefined4 *)(param_1 + 0xc) = (*(undefined4 **)(param_1 + 0xc))[2];
  }
  *(undefined4 *)(param_2[2] + 4) = param_2[1];
  *(undefined4 *)(param_2[1] + 8) = param_2[2];
  FUN_008f3520(param_2);
  return;
}



/* VA 008f37c0 */

undefined4 * __cdecl FUN_008f37c0(int *param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined4 *puVar3;

  puVar3 = (undefined4 *)param_1[2];
  if ((puVar3 != (undefined4 *)0x0) ||
     (puVar3 = (undefined4 *)*param_1, puVar3 != (undefined4 *)0x0)) {
    while (bVar1 = FUN_008f40b0((uint *)*puVar3,param_2), (short)CONCAT31(extraout_var,bVar1) == 0)
    {
      uVar2 = FUN_008f4030((uint *)*puVar3,param_2,param_3,param_4);
      if ((short)uVar2 != 0) {
        FUN_008f36c0((int)param_1,puVar3);
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



/* VA 008f3830 */

void __cdecl FUN_008f3830(int *param_1)

{
  int iVar1;

  iVar1 = *(int *)(*param_1 + 4);
  if (iVar1 != param_1[1]) {
    do {
      iVar1 = *(int *)(iVar1 + 4);
      FUN_008f3780((int)param_1,*(undefined4 **)(iVar1 + 8));
    } while (iVar1 != param_1[1]);
  }
  return;
}



/* VA 008f38a0 */

void __cdecl FUN_008f38a0(int *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;

  puVar2 = *(undefined4 **)(*param_1 + 4);
  while (puVar2 != (undefined4 *)0x0) {
    if ((puVar2 == (undefined4 *)param_1[1]) ||
       (uVar3 = FUN_008f4230((uint *)*puVar2,param_2,param_3), (short)uVar3 != 0)) {
      puVar2 = (undefined4 *)puVar2[1];
    }
    else {
      puVar1 = (undefined4 *)puVar2[1];
      FUN_008f3780((int)param_1,puVar2);
      puVar2 = puVar1;
    }
  }
  return;
}



/* VA 008f38f0 */

undefined4 * __cdecl FUN_008f38f0(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;

  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    bVar1 = FUN_008f40b0((uint *)*param_1,param_2);
    if ((short)CONCAT31(extraout_var,bVar1) != 0) {
      return param_1;
    }
    param_1 = (undefined4 *)param_1[1];
  } while (param_1 != (undefined4 *)0x0);
  return (undefined4 *)0x0;
}



/* VA 008f3930 */

undefined4 * __cdecl FUN_008f3930(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;

  if (param_1 != (undefined4 *)0x0) {
    while( true ) {
      uVar2 = FUN_008f4190((int *)*param_1,param_2,param_3,param_4);
      if ((short)uVar2 != 0) {
        return param_1;
      }
      bVar1 = FUN_008f40b0((uint *)*param_1,param_2);
      if ((short)CONCAT31(extraout_var,bVar1) != 0) break;
      param_1 = (undefined4 *)param_1[1];
      if (param_1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
    }
  }
  return (undefined4 *)0x0;
}



/* VA 008f3990 */

uint __cdecl FUN_008f3990(undefined4 *param_1,uint *param_2,uint *param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;

  puVar2 = param_2;
  puVar1 = param_1;
  puVar4 = FUN_008f3a00(param_1,*param_2);
  puVar4 = FUN_008f38f0(puVar4,*puVar2);
  puVar3 = param_3;
  if (puVar4 == (undefined4 *)0x0) {
    return 0;
  }
  param_2 = (uint *)*puVar2;
  param_1 = (undefined4 *)*param_3;
  uVar5 = FUN_008f3a40(puVar4,(uint *)&param_2,(uint *)&param_1);
  if ((short)uVar5 == 1) {
    *puVar2 = (uint)param_2;
    *puVar3 = (uint)param_1;
    puVar1[3] = puVar4;
  }
  return uVar5;
}



/* VA 008f3a00 */

undefined4 * __cdecl FUN_008f3a00(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;

  puVar2 = (undefined4 *)param_1[3];
  if ((param_2 == 0) || (puVar2 == (undefined4 *)0x0)) {
    puVar2 = (undefined4 *)*param_1;
  }
  else {
    while( true ) {
      uVar1 = FUN_008f4090((uint *)*puVar2,param_2);
      if ((short)uVar1 != 0) break;
      puVar2 = (undefined4 *)puVar2[2];
      if (puVar2 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
    }
  }
  return puVar2;
}



/* VA 008f3a40 */

uint __cdecl FUN_008f3a40(undefined4 *param_1,uint *param_2,uint *param_3)

{
  short sVar1;
  uint in_EAX;
  uint uVar2;

  if (param_1 != (undefined4 *)0x0) {
    uVar2 = FUN_008f4150(*(int **)param_1[2],*param_2);
    *param_2 = uVar2;
    uVar2 = FUN_008f40c0((uint *)*param_1,uVar2);
    sVar1 = (short)uVar2;
    while (sVar1 != 0) {
      uVar2 = FUN_008f4100((int *)*param_1);
      *param_2 = uVar2;
      param_1 = (undefined4 *)param_1[1];
      uVar2 = FUN_008f40c0((uint *)*param_1,uVar2);
      sVar1 = (short)uVar2;
    }
    uVar2 = FUN_008f4170((int *)*param_1,*param_3);
    *param_3 = uVar2;
    return (uint)(*param_2 <= uVar2);
  }
  return in_EAX & 0xffff0000;
}



/* VA 008f3ac0 */

undefined4 __cdecl FUN_008f3ac0(undefined4 *param_1,uint *param_2,uint *param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;

  piVar1 = FUN_008f3a00(param_1,*param_2);
  piVar1 = FUN_008f3b50(piVar1,*param_2,*param_3,param_4);
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = FUN_008f4230((uint *)*piVar1,*param_2,*param_3);
    if ((short)uVar2 != 0) {
      uVar2 = FUN_008f4110((uint *)*piVar1,*param_2);
      *param_2 = uVar2;
      uVar2 = FUN_008f4130((int *)*piVar1,*param_3);
      *param_3 = uVar2;
      param_1[3] = piVar1;
      return CONCAT22((short)(uVar2 >> 0x10),1);
    }
  }
  *param_2 = *param_3 - 1;
  return uVar2 & 0xffff0000;
}



/* VA 008f3b50 */

int * __cdecl FUN_008f3b50(int *param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined3 extraout_var;

  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  do {
    uVar2 = FUN_008f4230((uint *)*param_1,param_2,param_3);
    if ((short)uVar2 == 0) {
      bVar1 = FUN_008f40b0((uint *)*param_1,param_3);
      if ((short)CONCAT31(extraout_var,bVar1) != 0) {
        return (int *)0x0;
      }
    }
    else {
      uVar3 = FUN_008f40e0(*param_1,param_4);
      if ((short)uVar3 != 0) {
        return param_1;
      }
    }
    param_1 = (int *)param_1[1];
  } while (param_1 != (int *)0x0);
  return (int *)0x0;
}



/* VA 008f3bc0 */

void __cdecl FUN_008f3bc0(undefined4 *param_1,uint *param_2,uint *param_3,uint param_4)

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
  uVar3 = FUN_008f3ac0((undefined4 *)local_20[param_4],(uint *)&param_2,&local_24,param_4);
  if (((short)uVar3 != 0) && (uVar2 != 3)) {
    uVar6 = 0;
    puVar7 = local_20;
    do {
      if (uVar2 != uVar6) {
        uVar4 = FUN_008f3990((undefined4 *)*puVar7,(uint *)&param_2,&local_24);
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



/* VA 008f3c60 */

void __cdecl FUN_008f3c60(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;

  if (param_1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)param_1[2];
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*param_1;
    }
    else {
      while (uVar1 = FUN_008f4090((uint *)*puVar2,param_2), (short)uVar1 == 0) {
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



/* VA 008f3ca0 */

void __cdecl
FUN_008f3ca0(char *param_1,uint param_2,undefined4 *param_3,uint param_4,uint param_5,
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
  uVar3 = FUN_008f4260(param_2,iVar6 + -1 + param_2,param_4,param_5);
  pcVar1 = param_1;
  if ((short)uVar3 != 0) {
    FUN_008f20d0(param_1,uVar7,iVar6,3);
  }
  iVar4 = FUN_008f22a0(pcVar1);
  if (iVar4 == 0) {
    FUN_008fe780((undefined4 *)pcVar1,8,&local_4,(uint *)&param_3,(uint *)&param_1);
    puVar5 = (undefined4 *)FUN_008f56c0((uint)param_3);
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
    sVar2 = FUN_008f20b0(pcVar1);
    if (sVar2 != 0) {
      local_4 = param_1;
    }
    FUN_008f2690((undefined4 *)pcVar1,(int)local_4,param_3,puVar5);
    iVar4 = (int)puVar5 - (int)param_1;
    FUN_008f22c0(pcVar1,puVar5);
    FUN_008f2310(pcVar1,iVar4);
    uVar7 = param_2;
    if (puVar5 == (undefined4 *)0x0) {
      return;
    }
  }
  iVar4 = FUN_008f22f0(pcVar1);
  FUN_008f3de0(pcVar1,uVar7,iVar4,iVar6,param_4,param_5,(short)param_6);
  return;
}



/* VA 008f3db0 */

void __cdecl FUN_008f3db0(char *param_1)

{
  FUN_008f2240(param_1,3);
  return;
}



/* VA 008f3dc0 */

void __cdecl FUN_008f3dc0(char *param_1,uint param_2,uint param_3)

{
  FUN_008f2270(param_1,3,param_2,param_3);
  return;
}



/* VA 008f3de0 */

void __cdecl
FUN_008f3de0(char *param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6,
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
    uVar3 = FUN_008f4260(*puVar4,*puVar4 + 0xfff,param_5,param_6);
    if ((short)uVar3 != 0) {
      FUN_008f3e80(param_1,(ushort *)(puVar4 + 2),uVar2 - 8 >> 1,*puVar4,param_5,param_6);
      local_4 = local_4 + 1;
      if ((param_7 != 0) && (1 < local_4)) {
        return;
      }
    }
    puVar4 = (uint *)((int)puVar4 + puVar4[1]);
  } while( true );
}



/* VA 008f3e80 */

void __cdecl
FUN_008f3e80(char *param_1,ushort *param_2,int param_3,int param_4,uint param_5,uint param_6)

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
      uVar2 = FUN_008f4260(uVar1,uVar1 + uVar3,param_5,param_6);
      if ((short)uVar2 != 0) {
        FUN_008f20d0(param_1,uVar1,(uint)uVar3,3);
      }
    }
    param_2 = param_2 + 1;
  }
  return;
}



/* VA 008f3f90 */

void __cdecl FUN_008f3f90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)FUN_008f56c0(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
  }
  return;
}



/* VA 008f3fc0 */

void __cdecl FUN_008f3fc0(undefined *param_1)

{
  FUN_008f5650(param_1);
  return;
}



/* VA 008f3fd0 */

void __cdecl FUN_008f3fd0(uint *param_1,uint param_2,int param_3)

{
  if (param_2 < *param_1) {
    *param_1 = param_2;
  }
  param_1[1] = param_1[1] + param_3;
  return;
}



/* VA 008f3ff0 */

void __cdecl FUN_008f3ff0(uint *param_1,uint *param_2)

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



/* VA 008f4030 */

uint __cdecl FUN_008f4030(uint *param_1,uint param_2,int param_3,uint param_4)

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



/* VA 008f4090 */

uint __cdecl FUN_008f4090(uint *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = 0;
  if ((param_1 != (uint *)0x0) && (uVar1 = *param_1, uVar1 <= param_2)) {
    return CONCAT22((short)(uVar1 >> 0x10),1);
  }
  return uVar1 & 0xffff0000;
}



/* VA 008f40b0 */

bool __cdecl FUN_008f40b0(uint *param_1,uint param_2)

{
  return param_2 < *param_1;
}



/* VA 008f40c0 */

uint __cdecl FUN_008f40c0(uint *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = 0;
  if ((param_1 != (uint *)0x0) && (uVar1 = *param_1, uVar1 == param_2)) {
    return CONCAT22((short)(uVar1 >> 0x10),1);
  }
  return uVar1 & 0xffff0000;
}



/* VA 008f40e0 */

uint __cdecl FUN_008f40e0(int param_1,uint param_2)

{
  uint uVar1;

  uVar1 = 0;
  if ((param_1 != 0) && (uVar1 = *(uint *)(param_1 + 8), uVar1 == param_2)) {
    return CONCAT22((short)(uVar1 >> 0x10),1);
  }
  return uVar1 & 0xffff0000;
}



/* VA 008f4100 */

int __cdecl FUN_008f4100(int *param_1)

{
  return param_1[1] + *param_1;
}



/* VA 008f4110 */

uint __cdecl FUN_008f4110(uint *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = *param_1;
  if (*param_1 <= param_2) {
    uVar1 = param_2;
  }
  return uVar1;
}



/* VA 008f4130 */

uint __cdecl FUN_008f4130(int *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = param_1[1] + -1 + *param_1;
  if (param_2 < uVar1) {
    uVar1 = param_2;
  }
  return uVar1;
}



/* VA 008f4150 */

uint __cdecl FUN_008f4150(int *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = param_1[1] + *param_1;
  if ((uint)(param_1[1] + *param_1) <= param_2) {
    uVar1 = param_2;
  }
  return uVar1;
}



/* VA 008f4170 */

uint __cdecl FUN_008f4170(int *param_1,uint param_2)

{
  uint uVar1;

  uVar1 = *param_1 - 1U;
  if (param_2 < *param_1 - 1U) {
    uVar1 = param_2;
  }
  return uVar1;
}



/* VA 008f4190 */

undefined4 __cdecl FUN_008f4190(int *param_1,int param_2,int param_3,int param_4)

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



/* VA 008f41d0 */

undefined4 __cdecl FUN_008f41d0(int *param_1,int *param_2)

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



/* VA 008f4210 */

void __cdecl FUN_008f4210(uint *param_1,uint *param_2)

{
  FUN_008f4230(param_1,*param_2,param_2[1] + *param_2);
  return;
}



/* VA 008f4230 */

undefined4 __cdecl FUN_008f4230(uint *param_1,uint param_2,uint param_3)

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



/* VA 008f4260 */

undefined4 __cdecl FUN_008f4260(uint param_1,uint param_2,uint param_3,uint param_4)

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



/* VA 008f42a0 */

void __fastcall FUN_008f42a0(int param_1)

{
  char *pcVar1;
  int in_EAX;

  pcVar1 = (char *)(param_1 + -0x6ce42b5e + in_EAX * 8);
  *pcVar1 = *pcVar1 << 1;
  *(char *)(param_1 + -9) = *(char *)(param_1 + -9) << 1;
  return;
}



/* VA 008f42cf */

/* WARNING: Instruction at (ram,0x008f4382) overlaps instruction at (ram,0x008f4380)
    */
/* WARNING: Removing unreachable block (ram,0x008f4335) */
/* WARNING: Removing unreachable block (ram,0x008f431d) */
/* WARNING: Removing unreachable block (ram,0x008f4305) */
/* WARNING: Removing unreachable block (ram,0x008f42e1) */
/* WARNING: Removing unreachable block (ram,0x008f42ed) */
/* WARNING: Removing unreachable block (ram,0x008f4311) */
/* WARNING: Removing unreachable block (ram,0x008f4329) */
/* WARNING: Removing unreachable block (ram,0x008f4341) */
/* WARNING: Removing unreachable block (ram,0x008f4367) */
/* WARNING: Removing unreachable block (ram,0x008f42f9) */
/* WARNING: Removing unreachable block (ram,0x008f4373) */
/* WARNING: Removing unreachable block (ram,0x008f437f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff8 : 0x008f4380 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined2 __thiscall FUN_008f42cf(byte param_1)

{
  undefined4 in_stack_00000010;
  undefined2 local_8;

  FUN_008f45ca(in_stack_00000010,(short)&stack0x00000004,(undefined4 *)&stack0x00000004,
               (byte *)in_stack_00000010);
  return local_8;
}



/* VA 008f4390 */

/* WARNING: Instruction at (ram,0x008f44dd) overlaps instruction at (ram,0x008f44db)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008f454d) */
/* WARNING: Removing unreachable block (ram,0x008f4559) */
/* WARNING: Removing unreachable block (ram,0x008f44aa) */
/* WARNING: Removing unreachable block (ram,0x008f449e) */
/* WARNING: Removing unreachable block (ram,0x008f44da) */
/* WARNING: Removing unreachable block (ram,0x008f447a) */
/* WARNING: Removing unreachable block (ram,0x008f4437) */
/* WARNING: Removing unreachable block (ram,0x008f441f) */
/* WARNING: Removing unreachable block (ram,0x008f4407) */
/* WARNING: Removing unreachable block (ram,0x008f43da) */
/* WARNING: Removing unreachable block (ram,0x008f43a4) */
/* WARNING: Removing unreachable block (ram,0x008f43b0) */
/* WARNING: Removing unreachable block (ram,0x008f43bc) */
/* WARNING: Removing unreachable block (ram,0x008f43ce) */
/* WARNING: Removing unreachable block (ram,0x008f442b) */
/* WARNING: Removing unreachable block (ram,0x008f4443) */
/* WARNING: Removing unreachable block (ram,0x008f4492) */
/* WARNING: Removing unreachable block (ram,0x008f4530) */
/* WARNING: Removing unreachable block (ram,0x008f4592) */
/* WARNING: Removing unreachable block (ram,0x008f4586) */
/* WARNING: Removing unreachable block (ram,0x008f45b2) */
/* WARNING: Removing unreachable block (ram,0x008f4486) */
/* WARNING: Removing unreachable block (ram,0x008f459e) */
/* WARNING: Removing unreachable block (ram,0x008f45be) */
/* WARNING: Removing unreachable block (ram,0x008f44c2) */
/* WARNING: Removing unreachable block (ram,0x008f4413) */
/* WARNING: Removing unreachable block (ram,0x008f4518) */
/* WARNING: Removing unreachable block (ram,0x008f44b6) */
/* WARNING: Removing unreachable block (ram,0x008f44ce) */
/* WARNING: Removing unreachable block (ram,0x008f4524) */
/* WARNING: Removing unreachable block (ram,0x008f43e6) */
/* WARNING: Removing unreachable block (ram,0x008f43e9) */
/* WARNING: Removing unreachable block (ram,0x008f4514) */
/* WARNING: Removing unreachable block (ram,0x008f452c) */

int * __fastcall FUN_008f4390(undefined4 param_1,undefined2 param_2)

{
  int *piVar1;
  undefined8 uVar2;
  undefined4 *in_stack_00000004;
  int *in_stack_00000008;
  undefined4 uStack_20;
  int iStack_1c;
  uint uStack_18;
  int iStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;

  uStack_c = uStack_c & 0xffff0000;
  uStack_10 = 0;
  iStack_14 = 0;
  iStack_1c = 0;
  while( true ) {
    uStack_10 = FUN_008fe750(in_stack_00000004,1,uStack_10,&uStack_20,&uStack_18,&uStack_8);
    if (uStack_10 == 0) {
      piVar1 = (int *)0x0;
      if (((uStack_c & 0xffff) != 0) && (in_stack_00000008 != (int *)0x0)) {
        *in_stack_00000008 = iStack_14;
        piVar1 = in_stack_00000008;
      }
      return (int *)CONCAT22((short)((uint)piVar1 >> 0x10),1);
    }
    uVar2 = FUN_008f47a8();
    uStack_c = CONCAT22(uStack_c._2_2_,(short)uVar2);
    if ((short)uVar2 == 0) break;
    iStack_14 = iStack_14 + iStack_1c;
    uStack_10 = uStack_10 + 0x28;
  }
  return (int *)((uint)uVar2 & 0xffff0000);
}



/* VA 008f45ca */

/* WARNING: Instruction at (ram,0x008f46e2) overlaps instruction at (ram,0x008f46e0)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008f466c) */
/* WARNING: Removing unreachable block (ram,0x008f4678) */
/* WARNING: Removing unreachable block (ram,0x008f4684) */
/* WARNING: Removing unreachable block (ram,0x008f469f) */
/* WARNING: Removing unreachable block (ram,0x008f46a3) */
/* WARNING: Removing unreachable block (ram,0x008f46b7) */
/* WARNING: Removing unreachable block (ram,0x008f46bb) */
/* WARNING: Removing unreachable block (ram,0x008f4790) */
/* WARNING: Removing unreachable block (ram,0x008f4753) */
/* WARNING: Removing unreachable block (ram,0x008f4723) */
/* WARNING: Removing unreachable block (ram,0x008f470b) */
/* WARNING: Removing unreachable block (ram,0x008f46ab) */
/* WARNING: Removing unreachable block (ram,0x008f46af) */
/* WARNING: Removing unreachable block (ram,0x008f46f3) */
/* WARNING: Removing unreachable block (ram,0x008f45fd) */
/* WARNING: Removing unreachable block (ram,0x008f45e5) */
/* WARNING: Removing unreachable block (ram,0x008f45f1) */
/* WARNING: Removing unreachable block (ram,0x008f4609) */
/* WARNING: Removing unreachable block (ram,0x008f4615) */
/* WARNING: Removing unreachable block (ram,0x008f46ff) */
/* WARNING: Removing unreachable block (ram,0x008f4717) */
/* WARNING: Removing unreachable block (ram,0x008f4747) */
/* WARNING: Removing unreachable block (ram,0x008f4784) */
/* WARNING: Removing unreachable block (ram,0x008f46d3) */
/* WARNING: Removing unreachable block (ram,0x008f46c3) */
/* WARNING: Removing unreachable block (ram,0x008f46c7) */
/* WARNING: Removing unreachable block (ram,0x008f479c) */
/* WARNING: Removing unreachable block (ram,0x008f4621) */
/* WARNING: Removing unreachable block (ram,0x008f46cf) */
/* WARNING: Removing unreachable block (ram,0x008f46db) */
/* WARNING: Removing unreachable block (ram,0x008f46df) */
/* WARNING: Removing unreachable block (ram,0x008f472f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * __fastcall
FUN_008f45ca(undefined4 param_1,undefined2 param_2,undefined4 *param_3,byte *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  uint local_8;
  uint uVar2;

  local_10 = 0;
  while( true ) {
    local_10 = FUN_008fe750(param_3,1,local_10,&local_18,&local_14,&local_8);
    uVar2 = 0;
    if (local_10 == 0) break;
    bVar1 = FUN_008fea50(param_3,local_10,param_4);
    uVar2 = CONCAT31(extraout_var,bVar1);
    if (uVar2 != 0) break;
    local_10 = local_10 + 0x28;
  }
  bVar1 = (POPCOUNT(local_10 & 0xff) & 1U) == 0;
  if (local_10 == 0) {
    puVar3 = (undefined1 *)(uVar2 & 0xffff0000);
  }
  else {
    if ((!bVar1) && (bVar1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar4 = FUN_008f47a8();
    puVar3 = (undefined1 *)uVar4;
  }
  return puVar3;
}



/* VA 008f47a8 */

/* WARNING: Instruction at (ram,0x008f4bda) overlaps instruction at (ram,0x008f4bd9)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x008f4c09) */
/* WARNING: Removing unreachable block (ram,0x008f4c0d) */
/* WARNING: Removing unreachable block (ram,0x008f4c5a) */
/* WARNING: Removing unreachable block (ram,0x008f4c6c) */
/* WARNING: Removing unreachable block (ram,0x008f4c2d) */
/* WARNING: Removing unreachable block (ram,0x008f4c31) */
/* WARNING: Removing unreachable block (ram,0x008f4ba8) */
/* WARNING: Removing unreachable block (ram,0x008f4ab8) */
/* WARNING: Removing unreachable block (ram,0x008f4bb4) */
/* WARNING: Removing unreachable block (ram,0x008f4b9c) */
/* WARNING: Removing unreachable block (ram,0x008f4a2d) */
/* WARNING: Removing unreachable block (ram,0x008f4973) */
/* WARNING: Removing unreachable block (ram,0x008f4905) */
/* WARNING: Removing unreachable block (ram,0x008f48ed) */
/* WARNING: Removing unreachable block (ram,0x008f48d5) */
/* WARNING: Removing unreachable block (ram,0x008f48bd) */
/* WARNING: Removing unreachable block (ram,0x008f48a5) */
/* WARNING: Removing unreachable block (ram,0x008f488d) */
/* WARNING: Removing unreachable block (ram,0x008f4875) */
/* WARNING: Removing unreachable block (ram,0x008f485d) */
/* WARNING: Removing unreachable block (ram,0x008f4845) */
/* WARNING: Removing unreachable block (ram,0x008f482d) */
/* WARNING: Removing unreachable block (ram,0x008f4821) */
/* WARNING: Removing unreachable block (ram,0x008f4809) */
/* WARNING: Removing unreachable block (ram,0x008f47cd) */
/* WARNING: Removing unreachable block (ram,0x008f47d9) */
/* WARNING: Removing unreachable block (ram,0x008f47e5) */
/* WARNING: Removing unreachable block (ram,0x008f47fd) */
/* WARNING: Removing unreachable block (ram,0x008f4815) */
/* WARNING: Removing unreachable block (ram,0x008f4851) */
/* WARNING: Removing unreachable block (ram,0x008f4869) */
/* WARNING: Removing unreachable block (ram,0x008f4881) */
/* WARNING: Removing unreachable block (ram,0x008f4899) */
/* WARNING: Removing unreachable block (ram,0x008f48b1) */
/* WARNING: Removing unreachable block (ram,0x008f48c9) */
/* WARNING: Removing unreachable block (ram,0x008f48e1) */
/* WARNING: Removing unreachable block (ram,0x008f48f9) */
/* WARNING: Removing unreachable block (ram,0x008f4911) */
/* WARNING: Removing unreachable block (ram,0x008f491d) */
/* WARNING: Removing unreachable block (ram,0x008f49af) */
/* WARNING: Removing unreachable block (ram,0x008f4ae8) */
/* WARNING: Removing unreachable block (ram,0x008f4af4) */
/* WARNING: Removing unreachable block (ram,0x008f4b0c) */
/* WARNING: Removing unreachable block (ram,0x008f4bc0) */
/* WARNING: Removing unreachable block (ram,0x008f497f) */
/* WARNING: Removing unreachable block (ram,0x008f4c25) */
/* WARNING: Removing unreachable block (ram,0x008f4c39) */
/* WARNING: Removing unreachable block (ram,0x008f4c3d) */
/* WARNING: Removing unreachable block (ram,0x008f4c15) */
/* WARNING: Removing unreachable block (ram,0x008f4c19) */
/* WARNING: Removing unreachable block (ram,0x008f4c78) */
/* WARNING: Removing unreachable block (ram,0x008f4a09) */
/* WARNING: Removing unreachable block (ram,0x008f4b72) */
/* WARNING: Removing unreachable block (ram,0x008f4b66) */
/* WARNING: Removing unreachable block (ram,0x008f4a45) */
/* WARNING: Removing unreachable block (ram,0x008f4997) */
/* WARNING: Removing unreachable block (ram,0x008f4a21) */
/* WARNING: Removing unreachable block (ram,0x008f4b42) */
/* WARNING: Removing unreachable block (ram,0x008f4b4e) */
/* WARNING: Removing unreachable block (ram,0x008f49a3) */
/* WARNING: Removing unreachable block (ram,0x008f4c21) */
/* WARNING: Removing unreachable block (ram,0x008f498b) */
/* WARNING: Removing unreachable block (ram,0x008f4ac4) */
/* WARNING: Removing unreachable block (ram,0x008f4b00) */
/* WARNING: Removing unreachable block (ram,0x008f4929) */
/* WARNING: Removing unreachable block (ram,0x008f47f1) */
/* WARNING: Removing unreachable block (ram,0x008f4a15) */
/* WARNING: Removing unreachable block (ram,0x008f4b5a) */
/* WARNING: Removing unreachable block (ram,0x008f4839) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff4 : 0x008f49b7 */
/* WARNING: Removing unreachable block (ram,0x008f4bcc) */
/* WARNING: Removing unreachable block (ram,0x008f4b7e) */
/* WARNING: Removing unreachable block (ram,0x008f4a39) */
/* WARNING: Removing unreachable block (ram,0x008f4bd8) */
/* WARNING: Removing unreachable block (ram,0x008f4b18) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_008f47a8(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  undefined4 *extraout_EDX;
  undefined4 *puVar5;
  bool bVar6;
  int unaff_retaddr;
  char *in_stack_00000004;
  int in_stack_00000008;
  undefined4 *in_stack_0000000c;
  uint in_stack_00000010;
  undefined4 *in_stack_00000014;
  short in_stack_00000018;
  undefined4 *puStackY_1020;
  uint uStackY_101c;
  uint uStackY_1018;
  int iStackY_1014;
  uint uStackY_1010;
  undefined4 auStackY_100c [1018];

  FUN_008f5470();
  _DAT_0090acd0 = 0;
  puVar5 = extraout_EDX;
  do {
    uVar2 = _DAT_0090acd0;
    if (in_stack_0000000c == (undefined4 *)0x0) {
      uVar4 = *(undefined4 *)(&stack0xfffffff0 + (unaff_retaddr >> 0x1f) * -0x10);
      if (in_stack_00000014 != (undefined4 *)0x0) {
        *in_stack_00000014 = _DAT_0090acd0;
        uVar4 = uVar2;
        puVar5 = in_stack_00000014;
      }
      return CONCAT44(puVar5,CONCAT22((short)((uint)uVar4 >> 0x10),1));
    }
    if (in_stack_0000000c < (undefined4 *)0x1000) {
      puStackY_1020 = in_stack_0000000c;
    }
    else {
      puStackY_1020 = (undefined4 *)0x1000;
    }
    if (in_stack_00000018 == 0) {
      FUN_008f2690((undefined4 *)in_stack_00000004,in_stack_00000008,puStackY_1020,auStackY_100c);
    }
    else {
      FUN_008f2690((undefined4 *)in_stack_00000004,in_stack_00000010,puStackY_1020,auStackY_100c);
    }
    uStackY_1010 = in_stack_00000010;
    uVar1 = (in_stack_00000010 - 1) + (int)puStackY_1020;
    while ((uStackY_1010 < uVar1 &&
           (uStackY_101c = uVar1,
           uVar3 = FUN_008f2140(in_stack_00000004,&uStackY_1010,&uStackY_101c,4,1),
           (uVar3 & 0xffff) != 0))) {
      iStackY_1014 = uStackY_1010 - in_stack_00000010;
      uStackY_1018 = (uStackY_101c - uStackY_1010) + 1;
      bVar6 = (POPCOUNT(uStackY_1018 & 0xff) & 1U) == 0;
      if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if ((!bVar6) && (bVar6)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      FUN_008f4c8e(CONCAT22(extraout_var,(undefined2)uStackY_1018),iStackY_1014);
      uStackY_1010 = uStackY_1010 + uStackY_1018;
                    /* WARNING: Bad instruction - Truncating control flow here */
    }
    puVar5 = (undefined4 *)((int)in_stack_0000000c - (int)puStackY_1020);
    in_stack_00000008 = in_stack_00000008 + (int)puStackY_1020;
    in_stack_00000010 = in_stack_00000010 + (int)puStackY_1020;
    in_stack_0000000c = puVar5;
  } while( true );
}



/* VA 008f4c8e */

/* WARNING: Instruction at (ram,0x008f4eed) overlaps instruction at (ram,0x008f4eec)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x008f4eeb) */
/* WARNING: Removing unreachable block (ram,0x008f4f61) */
/* WARNING: Removing unreachable block (ram,0x008f4f49) */
/* WARNING: Removing unreachable block (ram,0x008f4f20) */
/* WARNING: Removing unreachable block (ram,0x008f4efc) */
/* WARNING: Removing unreachable block (ram,0x008f4e7e) */
/* WARNING: Removing unreachable block (ram,0x008f4e33) */
/* WARNING: Removing unreachable block (ram,0x008f4e1b) */
/* WARNING: Removing unreachable block (ram,0x008f4e03) */
/* WARNING: Removing unreachable block (ram,0x008f4deb) */
/* WARNING: Removing unreachable block (ram,0x008f4dc7) */
/* WARNING: Removing unreachable block (ram,0x008f4daf) */
/* WARNING: Removing unreachable block (ram,0x008f4d97) */
/* WARNING: Removing unreachable block (ram,0x008f4d8b) */
/* WARNING: Removing unreachable block (ram,0x008f4d73) */
/* WARNING: Removing unreachable block (ram,0x008f4d5b) */
/* WARNING: Removing unreachable block (ram,0x008f4d43) */
/* WARNING: Removing unreachable block (ram,0x008f4d2b) */
/* WARNING: Removing unreachable block (ram,0x008f4d13) */
/* WARNING: Removing unreachable block (ram,0x008f4cfb) */
/* WARNING: Removing unreachable block (ram,0x008f4cbf) */
/* WARNING: Removing unreachable block (ram,0x008f4ca7) */
/* WARNING: Removing unreachable block (ram,0x008f4cb3) */
/* WARNING: Removing unreachable block (ram,0x008f4ccb) */
/* WARNING: Removing unreachable block (ram,0x008f4cd7) */
/* WARNING: Removing unreachable block (ram,0x008f4cef) */
/* WARNING: Removing unreachable block (ram,0x008f4d07) */
/* WARNING: Removing unreachable block (ram,0x008f4d1f) */
/* WARNING: Removing unreachable block (ram,0x008f4d37) */
/* WARNING: Removing unreachable block (ram,0x008f4d4f) */
/* WARNING: Removing unreachable block (ram,0x008f4d67) */
/* WARNING: Removing unreachable block (ram,0x008f4d7f) */
/* WARNING: Removing unreachable block (ram,0x008f4dbb) */
/* WARNING: Removing unreachable block (ram,0x008f4dd3) */
/* WARNING: Removing unreachable block (ram,0x008f4df7) */
/* WARNING: Removing unreachable block (ram,0x008f4e0f) */
/* WARNING: Removing unreachable block (ram,0x008f4e27) */
/* WARNING: Removing unreachable block (ram,0x008f4e3f) */
/* WARNING: Removing unreachable block (ram,0x008f4e96) */
/* WARNING: Removing unreachable block (ram,0x008f4f08) */
/* WARNING: Removing unreachable block (ram,0x008f4f2c) */
/* WARNING: Removing unreachable block (ram,0x008f4f55) */
/* WARNING: Removing unreachable block (ram,0x008f4f6d) */
/* WARNING: Removing unreachable block (ram,0x008f4f79) */
/* WARNING: Removing unreachable block (ram,0x008f4eab) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000000 : 0x008f4f33 */
/* WARNING: Removing unreachable block (ram,0x008f4e4b) */
/* WARNING: Removing unreachable block (ram,0x008f4f85) */
/* WARNING: Removing unreachable block (ram,0x008f4e8a) */
/* WARNING: Removing unreachable block (ram,0x008f4da3) */
/* WARNING: Removing unreachable block (ram,0x008f4eb7) */
/* WARNING: Removing unreachable block (ram,0x008f4f14) */
/* WARNING: Removing unreachable block (ram,0x008f4ddf) */
/* WARNING: Removing unreachable block (ram,0x008f4ce3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_008f4c8e(uint param_1,int param_2)

{
  int unaff_retaddr;
  byte *in_stack_00000004;
  ushort in_stack_00000008;
  int local_8;

                    /* WARNING: Bad instruction - Truncating control flow here */
  while (in_stack_00000008 != 0) {
    _DAT_0090acd0 = _DAT_0090acd0 + (uint)*in_stack_00000004 * local_8;
    in_stack_00000004 = in_stack_00000004 + 1;
    in_stack_00000008 = in_stack_00000008 - 1;
    param_2 = local_8 * -0x588acc6c + 0x3bc62bb2 + (uint)in_stack_00000008;
    local_8 = param_2;
  }
  return CONCAT44(param_2,*(undefined4 *)(&stack0x00000000 + (unaff_retaddr >> 0x1f) * -0x10));
}



/* VA 008f4f90 */

/* WARNING: Removing unreachable block (ram,0x008f4fc8) */

int __cdecl FUN_008f4f90(int *param_1)

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



/* VA 008f4fd3 */

bool FUN_008f4fd3(void)

{
  HANDLE hObject;

  hObject = FUN_008f4ffc();
  if (hObject != (HANDLE)0xffffffff) {
    CloseHandle(hObject);
  }
  return hObject != (HANDLE)0xffffffff;
}



/* VA 008f4ffc */

HANDLE FUN_008f4ffc(void)

{
  HANDLE pvVar1;
  CHAR local_108 [260];

  wsprintfA(local_108,s______s_00907464,s_Secdrv_0090745c);
  pvVar1 = CreateFileA(local_108,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  return pvVar1;
}



/* VA 008f5048 */

bool FUN_008f5048(void)

{
  BOOL BVar1;
  bool bVar2;
  DWORD local_c;
  HANDLE local_8;

  local_8 = FUN_008f4ffc();
  if (local_8 == (HANDLE)0xffffffff) {
    bVar2 = false;
  }
  else {
    BVar1 = DeviceIoControl(local_8,0xef002407,DAT_0090b320,0x514,
                            (LPVOID)((int)DAT_0090b320 + 0x514),0x610,&local_c,(LPOVERLAPPED)0x0);
    bVar2 = BVar1 != 0;
    if (local_8 != (HANDLE)0x0) {
      CloseHandle(local_8);
    }
  }
  return bVar2;
}



/* VA 008f50bc */

undefined4 FUN_008f50bc(void)

{
  undefined4 *in_EAX;

  if (DAT_0090b320 == (undefined4 *)0x0) {
    DAT_0090b320 = (undefined4 *)FUN_008f56c0(0xb24);
    if (DAT_0090b320 == (undefined4 *)0x0) {
      return 0;
    }
    _memset(DAT_0090b320,0,0xb24);
    *DAT_0090b320 = 1;
    DAT_0090b320[1] = 3;
    in_EAX = DAT_0090b320;
    DAT_0090b320[2] = 0;
  }
  return CONCAT22((short)((uint)in_EAX >> 0x10),1);
}



/* VA 008f5128 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_008f5128(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,_DAT_7ffe0000);
}



/* VA 008f5145 */

undefined4 __fastcall
FUN_008f5145(undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;

  local_8 = 0xf367ac7f;
  uVar2 = FUN_008f5128(param_1,param_2);
  FUN_008f52f0((byte)&local_8,(int)((ulonglong)uVar2 >> 0x20),&local_8,&local_10);
  *param_3 = (uint)uVar2;
  for (local_c = 3; local_c != 0; local_c = local_c + -1) {
    uVar1 = FUN_008f5341(&local_10,&local_10);
    param_3[local_c] = uVar1;
    *param_3 = *param_3 ^ param_3[local_c];
  }
  *param_4 = (uint)uVar2;
  return CONCAT22((short)((ulonglong)uVar2 >> 0x10),1);
}



/* VA 008f51c2 */

int __cdecl FUN_008f51c2(uint *param_1,int *param_2)

{
  ushort uVar2;
  int iVar1;
  uint uVar3;
  undefined8 uVar4;

  uVar3 = *param_1 ^ param_1[1] ^ param_1[2];
  uVar4 = FUN_008f5128(uVar3 ^ param_1[3],uVar3);
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



/* VA 008f521a */

undefined4 __cdecl FUN_008f521a(undefined4 param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 *puVar2;

  iVar1 = DAT_0090b320;
  *(undefined4 *)(DAT_0090b320 + 0xc) = param_1;
  FUN_008f5145(iVar1 + 0x10,param_1,(uint *)(iVar1 + 0x10),param_4);
  *(uint *)(iVar1 + 0x410) = param_3;
  puVar2 = FUN_008f5b50((undefined4 *)(iVar1 + 0x414),param_2,param_3);
  return CONCAT22((short)((uint)puVar2 >> 0x10),1);
}



/* VA 008f526f */

undefined4 __cdecl FUN_008f526f(undefined4 *param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;

  iVar1 = DAT_0090b320;
  uVar2 = FUN_008f4f90((int *)(DAT_0090b320 + 0x514));
  if ((uVar2 & 0xffff) == 0) {
    uVar3 = 0x6f;
  }
  else {
    uVar2 = FUN_008f51c2((uint *)(iVar1 + 0x520),param_3);
    if ((uVar2 & 0xffff) == 0) {
      uVar3 = 0x70;
    }
    else {
      FUN_008f5b50(param_1,(undefined4 *)(iVar1 + 0x924),param_2);
      uVar3 = 0x6e;
    }
  }
  return uVar3;
}



/* VA 008f52f0 */

/* WARNING: Instruction at (ram,0x008f531e) overlaps instruction at (ram,0x008f531d)
    */
/* WARNING: Removing unreachable block (ram,0x008f5301) */
/* WARNING: Removing unreachable block (ram,0x008f530d) */
/* WARNING: Removing unreachable block (ram,0x008f5319) */
/* WARNING: Removing unreachable block (ram,0x008f532f) */
/* WARNING: Removing unreachable block (ram,0x008f533b) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_008f52f0(byte param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;

  uVar1 = *param_3;
  *param_4 = uVar1;
  return CONCAT44(uVar1,param_4);
}



/* VA 008f5341 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x008f53f0) overlaps instruction at (ram,0x008f53ef)
    */
/* WARNING: Removing unreachable block (ram,0x008f5440) */
/* WARNING: Removing unreachable block (ram,0x008f541c) */
/* WARNING: Removing unreachable block (ram,0x008f5404) */
/* WARNING: Removing unreachable block (ram,0x008f53e0) */
/* WARNING: Removing unreachable block (ram,0x008f53b2) */
/* WARNING: Removing unreachable block (ram,0x008f539a) */
/* WARNING: Removing unreachable block (ram,0x008f5382) */
/* WARNING: Removing unreachable block (ram,0x008f536a) */
/* WARNING: Removing unreachable block (ram,0x008f5352) */
/* WARNING: Removing unreachable block (ram,0x008f535e) */
/* WARNING: Removing unreachable block (ram,0x008f5376) */
/* WARNING: Removing unreachable block (ram,0x008f538e) */
/* WARNING: Removing unreachable block (ram,0x008f53a6) */
/* WARNING: Removing unreachable block (ram,0x008f53be) */
/* WARNING: Removing unreachable block (ram,0x008f53ec) */
/* WARNING: Removing unreachable block (ram,0x008f5410) */
/* WARNING: Removing unreachable block (ram,0x008f5428) */
/* WARNING: Removing unreachable block (ram,0x008f544c) */
/* WARNING: Removing unreachable block (ram,0x008f5458) */
/* WARNING: Removing unreachable block (ram,0x008f5464) */
/* WARNING: Removing unreachable block (ram,0x008f53f8) */
/* WARNING: Removing unreachable block (ram,0x008f5434) */

void __thiscall FUN_008f5341(void *this,uint *param_1)

{
  *param_1 = *param_1 * -0xd5acb1b + 0x361962e9;
  return;
}



/* VA 008f5470 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_008f5470(void)

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



/* VA 008f54b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_008f54b0(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  _SYSTEMTIME local_cc;
  _SYSTEMTIME local_bc;
  _TIME_ZONE_INFORMATION local_ac;

  GetLocalTime(&local_bc);
  GetSystemTime(&local_cc);
  if (local_cc.wMinute == DAT_0090b33a) {
    if (local_cc.wHour == DAT_0090b338) {
      if (local_cc.wDay == DAT_0090b336) {
        if (local_cc.wMonth == DAT_0090b332) {
          if (local_cc.wYear == DAT_0090b330) goto LAB_008f557f;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_ac);
  if (DVar1 == 0xffffffff) {
    DAT_0090b328 = -1;
  }
  else if (((DVar1 == 2) && (local_ac.DaylightDate.wMonth != 0)) && (local_ac.DaylightBias != 0)) {
    DAT_0090b328 = 1;
  }
  else {
    DAT_0090b328 = 0;
  }
  DAT_0090b330 = local_cc.wYear;
  DAT_0090b332 = local_cc.wMonth;
  _DAT_0090b334 = local_cc.wDayOfWeek;
  DAT_0090b336 = local_cc.wDay;
  DAT_0090b338 = local_cc.wHour;
  DAT_0090b33a = local_cc.wMinute;
  _DAT_0090b33c = local_cc.wSecond;
  DAT_0090b33c_2 = local_cc.wMilliseconds;
LAB_008f557f:
  iVar2 = FUN_008f66a0((uint)local_bc.wYear,(uint)local_bc.wMonth,(uint)local_bc.wDay,
                       (uint)local_bc.wHour,(uint)local_bc.wMinute,(uint)local_bc.wSecond,
                       DAT_0090b328);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return;
}



/* VA 008f5650 */

void __cdecl FUN_008f5650(undefined *param_1)

{
  undefined *lpMem;
  byte *pbVar1;
  int local_4;

  lpMem = param_1;
  if (param_1 != (undefined *)0x0) {
    FUN_008f74b0(9);
    pbVar1 = (byte *)FUN_008f78d0(lpMem,&local_4,(uint *)&param_1);
    if (pbVar1 != (byte *)0x0) {
      FUN_008f7930(local_4,(int)param_1,pbVar1);
      FUN_008f7530(9);
      return;
    }
    FUN_008f7530(9);
    HeapFree(DAT_0090cae4,0,lpMem);
  }
  return;
}



/* VA 008f56c0 */

void __cdecl FUN_008f56c0(uint param_1)

{
  FUN_008f56e0(param_1,DAT_0090b3fc);
  return;
}



/* VA 008f56e0 */

int * __cdecl FUN_008f56e0(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;

  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      if (param_1 < 0xffffffe1) {
        piVar1 = FUN_008f5730(param_1);
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
      iVar2 = FUN_008f7e20(param_1);
    } while (iVar2 != 0);
  }
  return (int *)0x0;
}



/* VA 008f5730 */

int * __cdecl FUN_008f5730(int param_1)

{
  int *piVar1;
  uint dwBytes;

  dwBytes = param_1 + 0xfU & 0xfffffff0;
  if (dwBytes <= DAT_00909584) {
    FUN_008f74b0(9);
    piVar1 = FUN_008f7990(param_1 + 0xfU >> 4);
    FUN_008f7530(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  piVar1 = HeapAlloc(DAT_0090cae4,0,dwBytes);
  return piVar1;
}



/* VA 008f5790 */

void FUN_008f5790(void)

{
  if (DAT_0090caf8 != (code *)0x0) {
    (*DAT_0090caf8)();
  }
  FUN_008f58d0((undefined4 *)&DAT_00907008,(undefined4 *)&DAT_00907010);
  FUN_008f58d0((undefined4 *)&DAT_00907000,(undefined4 *)&DAT_00907004);
  return;
}



/* VA 008f57c0 */

/* Library Function - Single Match
    __exit

   Library: Visual Studio 1998 Release */

void __cdecl __exit(int _Code)

{
  FUN_008f57f0(_Code,1,0);
  return;
}



/* VA 008f57e0 */

void FUN_008f57e0(void)

{
  FUN_008f57f0(0,0,1);
  return;
}



/* VA 008f57f0 */

void __cdecl FUN_008f57f0(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  undefined4 *puVar2;
  UINT uExitCode;

  FUN_008f58b0();
  if (DAT_0090b380 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_0090b37c = 1;
  DAT_0090b378 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0090caf4 != (undefined4 *)0x0) &&
       (puVar2 = (undefined4 *)(DAT_0090caf0 + -4), puVar1 = DAT_0090caf4, DAT_0090caf4 <= puVar2))
    {
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          puVar1 = DAT_0090caf4;
        }
        puVar2 = puVar2 + -1;
      } while (puVar1 <= puVar2);
    }
    FUN_008f58d0((undefined4 *)&DAT_00907014,(undefined4 *)&DAT_0090701c);
  }
  FUN_008f58d0((undefined4 *)&DAT_00907020,(undefined4 *)&DAT_00907024);
  if (param_3 != 0) {
    FUN_008f58c0();
    return;
  }
  DAT_0090b380 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



/* VA 008f58b0 */

void FUN_008f58b0(void)

{
  FUN_008f74b0(0xd);
  return;
}



/* VA 008f58c0 */

void FUN_008f58c0(void)

{
  FUN_008f7530(0xd);
  return;
}



/* VA 008f58d0 */

void __cdecl FUN_008f58d0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* VA 008f58f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008f58f0(undefined4 param_1,int param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;

  if (param_2 != 1) {
    if (param_2 != 0) {
      if (param_2 == 3) {
        FUN_008f6600((undefined *)0x0);
      }
      return 1;
    }
    if (0 < DAT_0090b384) {
      DAT_0090b384 = DAT_0090b384 + -1;
      if (DAT_0090b37c == 0) {
        FUN_008f57e0();
      }
      FUN_008f8050();
      FUN_008f6530();
      FUN_008f73c0();
      return 1;
    }
    return 0;
  }
  DAT_0090b344 = GetVersion();
  if (DAT_0090b394 == 0) {
    if (((char)DAT_0090b344 == '\x03') && ((DAT_0090b344 & 0x80000000) != 0)) {
      FUN_008f88c0(2);
    }
    hModule = GetModuleHandleA("kernel32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"IsTNT");
      if (pFVar1 != (FARPROC)0x0) {
        FUN_008f88c0(1);
      }
    }
  }
  iVar2 = FUN_008f7380();
  if (iVar2 == 0) {
    return 0;
  }
  _DAT_0090b350 = DAT_0090b344 >> 8 & 0xff;
  _DAT_0090b34c = DAT_0090b344 & 0xff;
  _DAT_0090b348 = _DAT_0090b34c * 0x100 + _DAT_0090b350;
  DAT_0090b344 = DAT_0090b344 >> 0x10;
  iVar2 = FUN_008f64d0();
  if (iVar2 == 0) {
    FUN_008f73c0();
    return 0;
  }
  DAT_0090cae8 = GetCommandLineA();
  DAT_0090b388 = FUN_008f8760();
  if ((DAT_0090cae8 != (LPSTR)0x0) && (DAT_0090b388 != (LPSTR)0x0)) {
    FUN_008f7e40();
    FUN_008f8750();
    FUN_008f81a0();
    FUN_008f80b0();
    FUN_008f5790();
    DAT_0090b384 = DAT_0090b384 + 1;
    return 1;
  }
  FUN_008f6530();
  FUN_008f73c0();
  return 0;
}



/* VA 008f5a60 */

uint entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;

  iVar1 = 1;
  if ((param_2 == 0) && (DAT_0090b384 == 0)) {
    return 0;
  }
  if ((param_2 != 1) && (param_2 != 2)) {
LAB_008f5abe:
    uVar2 = _DllMain_12(param_1,param_2);
    if ((param_2 == 1) && (uVar2 == 0)) {
      FUN_008f58f0(param_1,0);
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      iVar1 = FUN_008f58f0(param_1,param_2);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      if ((uVar2 != 0) && (DAT_0090caec != (code *)0x0)) {
        uVar2 = (*DAT_0090caec)(param_1,param_2,param_3);
      }
    }
    return uVar2;
  }
  if (DAT_0090caec != (code *)0x0) {
    iVar1 = (*DAT_0090caec)(param_1,param_2,param_3);
  }
  if (iVar1 != 0) {
    iVar1 = FUN_008f58f0(param_1,param_2);
    if (iVar1 != 0) goto LAB_008f5abe;
  }
  return 0;
}



/* VA 008f5b10 */

/* Library Function - Single Match
    __amsg_exit

   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_0090b390 == 1) || ((DAT_0090b390 == 0 && (DAT_0090b394 == 1)))) {
    FUN_008f88d0();
  }
  FUN_008f8910(param_1);
  (*(code *)PTR___exit_00907470)(0xff);
  return;
}



/* VA 008f5b50 */

undefined4 * __cdecl FUN_008f5b50(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_008f5d07_caseD_2;
        case 3:
          goto switchD_008f5d07_caseD_3;
        }
        goto switchD_008f5d07_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_008f5d07_caseD_0;
      case 1:
        goto switchD_008f5d07_caseD_1;
      case 2:
        goto switchD_008f5d07_caseD_2;
      case 3:
        goto switchD_008f5d07_caseD_3;
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
              goto switchD_008f5d07_caseD_2;
            case 3:
              goto switchD_008f5d07_caseD_3;
            }
            goto switchD_008f5d07_caseD_1;
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
              goto switchD_008f5d07_caseD_2;
            case 3:
              goto switchD_008f5d07_caseD_3;
            }
            goto switchD_008f5d07_caseD_1;
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
              goto switchD_008f5d07_caseD_2;
            case 3:
              goto switchD_008f5d07_caseD_3;
            }
            goto switchD_008f5d07_caseD_1;
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
switchD_008f5d07_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_008f5d07_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_008f5d07_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_008f5d07_caseD_0:
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
        goto switchD_008f5b85_caseD_2;
      case 3:
        goto switchD_008f5b85_caseD_3;
      }
      goto switchD_008f5b85_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_008f5b85_caseD_0;
    case 1:
      goto switchD_008f5b85_caseD_1;
    case 2:
      goto switchD_008f5b85_caseD_2;
    case 3:
      goto switchD_008f5b85_caseD_3;
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
            goto switchD_008f5b85_caseD_2;
          case 3:
            goto switchD_008f5b85_caseD_3;
          }
          goto switchD_008f5b85_caseD_1;
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
            goto switchD_008f5b85_caseD_2;
          case 3:
            goto switchD_008f5b85_caseD_3;
          }
          goto switchD_008f5b85_caseD_1;
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
            goto switchD_008f5b85_caseD_2;
          case 3:
            goto switchD_008f5b85_caseD_3;
          }
          goto switchD_008f5b85_caseD_1;
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
switchD_008f5b85_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_008f5b85_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_008f5b85_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_008f5b85_caseD_0:
  return param_1;
}



/* VA 008f5e90 */

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



/* VA 008f5ef0 */

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
    if (((uint)puVar2 & 3) == 0) goto LAB_008f5f10;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_008f5f43:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_008f5f10:
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
  goto LAB_008f5f43;
}



/* VA 008f5f70 */

uint * __cdecl FUN_008f5f70(uint *param_1,char *param_2)

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



/* VA 008f5ff0 */

uint __cdecl FUN_008f5ff0(uint param_1)

{
  bool bVar1;

  if (DAT_0090b650 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_0090c9c8);
    bVar1 = DAT_0090c9c4 != 0;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_0090c9c8);
      FUN_008f74b0(0x13);
    }
    param_1 = FUN_008f6080(param_1);
    if (bVar1) {
      FUN_008f7530(0x13);
      return param_1;
    }
    InterlockedDecrement((LONG *)&DAT_0090c9c8);
  }
  return param_1;
}



/* VA 008f6080 */

uint __cdecl FUN_008f6080(uint param_1)

{
  uint uVar1;
  uint uVar2;
  LPCWSTR pWVar3;
  int iVar4;
  uint local_8 [2];

  uVar1 = param_1;
  if (DAT_0090b650 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (DAT_00909aac < 2) {
        uVar2 = (byte)PTR_DAT_009098a0[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_008f8de0(param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    uVar2 = param_1;
    if ((PTR_DAT_009098a0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar1;
      pWVar3 = (LPCWSTR)0x1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar1,(char)(uVar1 >> 8));
      param_1._3_1_ = SUB41(uVar2,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      pWVar3 = (LPCWSTR)0x2;
    }
    iVar4 = FUN_008f8bc0(DAT_0090b650,0x100,(char *)&param_1,pWVar3,(LPWSTR)local_8,3,0);
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



/* VA 008f6180 */

void __cdecl FUN_008f6180(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

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
      FUN_008f8e80(param_2,param_1,2);
      param_2[2] = 0;
    }
    param_1 = param_1 + 2;
  }
  bVar2 = *param_1;
  param_2 = (byte *)0x0;
  pbVar5 = param_1;
  while (bVar2 != 0) {
    bVar2 = *pbVar5;
    if ((*(byte *)((int)&DAT_0090b510 + bVar2 + 1) & 4) == 0) {
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
    FUN_008f8e80(param_3,param_1,uVar3);
    param_3[uVar3] = 0;
  }
  if ((local_4 == (byte *)0x0) || (local_4 < param_2)) {
    if (param_4 != (byte *)0x0) {
      uVar3 = (int)pbVar5 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      FUN_008f8e80(param_4,param_2,uVar3);
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
      FUN_008f8e80(param_4,param_2,uVar3);
      param_4[uVar3] = 0;
    }
    if (param_5 != (byte *)0x0) {
      uVar3 = (int)pbVar5 - (int)local_4;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      FUN_008f8e80(param_5,local_4,uVar3);
      param_5[uVar3] = 0;
      return;
    }
  }
  return;
}



/* VA 008f6300 */

/* Library Function - Single Match
    __global_unwind2

   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x8f6318,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



/* VA 008f6342 */

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
  puStack_18 = &LAB_008f6320;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_008f63d6();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}



/* VA 008f63d6 */

void FUN_008f63d6(void)

{
  undefined4 in_EAX;
  int unaff_EBP;

  DAT_00907488 = *(undefined4 *)(unaff_EBP + 8);
  DAT_00907484 = in_EAX;
  DAT_0090748c = unaff_EBP;
  return;
}



/* VA 008f64b5 */

void FUN_008f64b5(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



/* VA 008f64d0 */

undefined4 FUN_008f64d0(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  FUN_008f7400();
  DAT_00907490 = TlsAlloc();
  if (DAT_00907490 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_008f8f30(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00907490,lpTlsValue);
      if (BVar1 != 0) {
        FUN_008f6560((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        return 1;
      }
    }
  }
  return 0;
}



/* VA 008f6530 */

void FUN_008f6530(void)

{
  FUN_008f7430();
  if (DAT_00907490 != 0xffffffff) {
    TlsFree(DAT_00907490);
    DAT_00907490 = 0xffffffff;
  }
  return;
}



/* VA 008f6560 */

void __cdecl FUN_008f6560(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_00909ab8;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



/* VA 008f6580 */

DWORD * FUN_008f6580(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_00907490);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_008f8f30(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00907490,lpTlsValue);
      if (BVar1 != 0) {
        FUN_008f6560((int)lpTlsValue);
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



/* VA 008f6600 */

void __cdecl FUN_008f6600(undefined *param_1)

{
  if (DAT_00907490 != 0xffffffff) {
    if ((param_1 != (undefined *)0x0) ||
       (param_1 = TlsGetValue(DAT_00907490), param_1 != (undefined *)0x0)) {
      if (*(undefined **)(param_1 + 0x24) != (undefined *)0x0) {
        FUN_008f5650(*(undefined **)(param_1 + 0x24));
      }
      if (*(undefined **)(param_1 + 0x28) != (undefined *)0x0) {
        FUN_008f5650(*(undefined **)(param_1 + 0x28));
      }
      if (*(undefined **)(param_1 + 0x30) != (undefined *)0x0) {
        FUN_008f5650(*(undefined **)(param_1 + 0x30));
      }
      if (*(undefined **)(param_1 + 0x38) != (undefined *)0x0) {
        FUN_008f5650(*(undefined **)(param_1 + 0x38));
      }
      if (*(undefined **)(param_1 + 0x40) != (undefined *)0x0) {
        FUN_008f5650(*(undefined **)(param_1 + 0x40));
      }
      if (*(undefined **)(param_1 + 0x44) != (undefined *)0x0) {
        FUN_008f5650(*(undefined **)(param_1 + 0x44));
      }
      FUN_008f5650(param_1);
    }
    TlsSetValue(DAT_00907490,(LPVOID)0x0);
    return;
  }
  return;
}



/* VA 008f66a0 */

int __cdecl
FUN_008f66a0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  tm local_24;

  uVar2 = param_1 - 0x76c;
  if (((int)uVar2 < 0x46) || (0x8a < (int)uVar2)) {
    return -1;
  }
  iVar3 = *(int *)(&DAT_00909c2c + param_2 * 4) + param_3;
  if (((uVar2 & 3) == 0) && (2 < param_2)) {
    iVar3 = iVar3 + 1;
  }
  FUN_008f8fe0();
  local_24.tm_hour = param_4;
  local_24.tm_mon = param_2 + -1;
  iVar1 = param_6 + (param_5 +
                    (param_4 + ((param_1 + -0x76d >> 2) + uVar2 * 0x16d + iVar3) * 0x18) * 0x3c) *
                    0x3c + 0x7c558180 + DAT_00909b40;
  if (param_7 != 1) {
    if (param_7 != -1) {
      return iVar1;
    }
    if (DAT_00909b44 == 0) {
      return iVar1;
    }
    local_24.tm_year = uVar2;
    local_24.tm_yday = iVar3;
    iVar3 = __isindst(&local_24);
    if (iVar3 == 0) {
      return iVar1;
    }
  }
  return iVar1 + DAT_00909b48;
}



/* VA 008f6790 */

uint __cdecl FUN_008f6790(uint param_1,int *param_2)

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
LAB_008f68b3:
    param_2[3] = uVar7 | 0x20;
    return 0xffffffff;
  }
  uVar6 = 0;
  if ((uVar7 & 1) != 0) {
    param_2[1] = 0;
    if ((uVar7 & 0x10) == 0) goto LAB_008f68b3;
    *param_2 = param_2[2];
    param_2[3] = uVar7 & 0xfffffffe;
  }
  uVar7 = param_2[3];
  param_2[1] = 0;
  param_2[3] = uVar7 & 0xffffffef | 2;
  if ((uVar7 & 0x10c) == 0) {
    if ((param_2 == (int *)&DAT_00909c88) || (param_2 == (int *)&DAT_00909ca8)) {
      bVar4 = FUN_008f9b30(uVar1);
      if (CONCAT31(extraout_var,bVar4) != 0) goto LAB_008f6803;
    }
    FUN_008f9ad0(piVar3);
  }
LAB_008f6803:
  if ((piVar3[3] & 0x108U) == 0) {
    uVar7 = 1;
    uVar6 = FUN_008f9840(uVar1,(char *)&param_1,1);
  }
  else {
    pcVar2 = (char *)piVar3[2];
    uVar7 = *piVar3 - (int)pcVar2;
    *piVar3 = (int)(pcVar2 + 1);
    piVar3[1] = piVar3[6] + -1;
    if ((int)uVar7 < 1) {
      if (uVar1 == 0xffffffff) {
        puVar5 = &DAT_00909588;
      }
      else {
        puVar5 = (undefined *)((&DAT_0090c9e0)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 0x24);
      }
      if ((puVar5[4] & 0x20) != 0) {
        FUN_008f9740(uVar1,0,2);
      }
      *(undefined1 *)piVar3[2] = (undefined1)param_1;
    }
    else {
      uVar6 = FUN_008f9840(uVar1,pcVar2,uVar7);
      *(undefined1 *)piVar3[2] = (undefined1)param_1;
    }
  }
  if (uVar6 != uVar7) {
    piVar3[3] = piVar3[3] | 0x20;
    return 0xffffffff;
  }
  return param_1 & 0xff;
}



/* VA 008f7250 */

void __cdecl FUN_008f7250(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;

  iVar1 = param_2[1];
  param_2[1] = iVar1 + -1;
  if (iVar1 + -1 < 0) {
    uVar2 = FUN_008f6790(param_1,param_2);
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



/* VA 008f72a0 */

void __cdecl FUN_008f72a0(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_008f7250(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 008f72e0 */

void __cdecl FUN_008f72e0(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;

  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_008f7250((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 008f7320 */

undefined4 __cdecl FUN_008f7320(int *param_1)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



/* VA 008f7340 */

undefined8 __cdecl FUN_008f7340(int *param_1)

{
  undefined8 *puVar1;

  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



/* VA 008f7360 */

undefined4 __cdecl FUN_008f7360(undefined4 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;

  puVar1 = (undefined2 *)*param_1;
  puVar2 = puVar1 + 2;
  *param_1 = puVar2;
  return CONCAT22((short)((uint)puVar2 >> 0x10),*puVar1);
}



/* VA 008f7380 */

undefined4 FUN_008f7380(void)

{
  undefined **ppuVar1;

  DAT_0090cae4 = HeapCreate(0,0x1000,0);
  if (DAT_0090cae4 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = FUN_008f7630();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_0090cae4);
    return 0;
  }
  return 1;
}



/* VA 008f73c0 */

void FUN_008f73c0(void)

{
  undefined **ppuVar1;

  ppuVar1 = &PTR_LOOP_00907560;
  do {
    if (ppuVar1[4] != (undefined *)0x0) {
      VirtualFree(ppuVar1[4],0,0x8000);
    }
    ppuVar1 = (undefined **)*ppuVar1;
  } while (ppuVar1 != &PTR_LOOP_00907560);
  HeapDestroy(DAT_0090cae4);
  return;
}



/* VA 008f7400 */

void FUN_008f7400(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_009074e4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_009074d4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_009074c4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_009074a4);
  return;
}



/* VA 008f7430 */

void FUN_008f7430(void)

{
  undefined **ppuVar1;

  ppuVar1 = (undefined **)&DAT_009074a0;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_009074e4)) && (ppuVar1 != &PTR_DAT_009074d4)) &&
       ((ppuVar1 != &PTR_DAT_009074c4 && (ppuVar1 != &PTR_DAT_009074a4)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_008f5650(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x907560);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_009074c4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_009074d4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_009074e4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_009074a4);
  return;
}



/* VA 008f74b0 */

void __cdecl FUN_008f74b0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;

  if ((&DAT_009074a0)[param_1] == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_008f56c0(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_008f74b0(0x11);
    if ((&DAT_009074a0)[param_1] == 0) {
      InitializeCriticalSection(lpCriticalSection);
      (&DAT_009074a0)[param_1] = lpCriticalSection;
    }
    else {
      FUN_008f5650((undefined *)lpCriticalSection);
    }
    FUN_008f7530(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_009074a0)[param_1]);
  return;
}



/* VA 008f7530 */

void __cdecl FUN_008f7530(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_009074a0)[param_1]);
  return;
}



/* VA 008f7550 */

void __cdecl FUN_008f7550(uint param_1)

{
  if ((0x909c67 < param_1) && (param_1 < 0x909ec9)) {
    FUN_008f74b0(((int)(param_1 - 0x909c68) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 008f7590 */

void __cdecl FUN_008f7590(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_008f74b0(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 008f75c0 */

void __cdecl FUN_008f75c0(uint param_1)

{
  if ((0x909c67 < param_1) && (param_1 < 0x909ec9)) {
    FUN_008f7530(((int)(param_1 - 0x909c68) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 008f7600 */

void __cdecl FUN_008f7600(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_008f7530(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 008f7630 */

undefined ** FUN_008f7630(void)

{
  bool bVar1;
  undefined4 *lpAddress;
  LPVOID pvVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **lpMem;
  undefined4 *puVar5;

  if (DAT_00907570 == -1) {
    lpMem = &PTR_LOOP_00907560;
  }
  else {
    lpMem = HeapAlloc(DAT_0090cae4,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar2 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00907560) {
        if (PTR_LOOP_00907560 == (undefined *)0x0) {
          PTR_LOOP_00907560 = (undefined *)&PTR_LOOP_00907560;
        }
        if (PTR_LOOP_00907564 == (undefined *)0x0) {
          PTR_LOOP_00907564 = (undefined *)&PTR_LOOP_00907560;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00907560;
        lpMem[1] = PTR_LOOP_00907564;
        PTR_LOOP_00907564 = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00907560) {
    HeapFree(DAT_0090cae4,0,lpMem);
  }
  return (undefined **)0x0;
}



/* VA 008f77a0 */

void __cdecl FUN_008f77a0(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_00909580 == param_1) {
    PTR_LOOP_00909580 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00907560) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0090cae4,0,param_1);
    return;
  }
  DAT_00907570 = 0xffffffff;
  return;
}



/* VA 008f7800 */

void __cdecl FUN_008f7800(int param_1)

{
  BOOL BVar1;
  undefined **ppuVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;

  ppuVar6 = (undefined **)PTR_LOOP_00907564;
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
            DAT_0090b3f8 = DAT_0090b3f8 + -1;
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
          FUN_008f77a0(ppuVar6);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_00907564) || (ppuVar6 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}



/* VA 008f78d0 */

int __cdecl FUN_008f78d0(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined **ppuVar1;
  uint uVar2;

  ppuVar1 = &PTR_LOOP_00907560;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &PTR_LOOP_00907560) {
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



/* VA 008f7930 */

void __cdecl FUN_008f7930(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  int iVar2;

  iVar2 = param_2 - *(int *)(param_1 + 0x10) >> 0xc;
  piVar1 = (int *)(param_1 + 0x18 + iVar2 * 8);
  *piVar1 = *(int *)(param_1 + 0x18 + iVar2 * 8) + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_0090b3f8 = DAT_0090b3f8 + 1, DAT_0090b3f8 == 0x20)) {
    FUN_008f7800(0x10);
  }
  return;
}



/* VA 008f7990 */

int * __cdecl FUN_008f7990(uint param_1)

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

  piVar11 = (int *)PTR_LOOP_00909580;
  do {
    if (piVar11[4] != -1) {
      puVar10 = (uint *)piVar11[2];
      piVar8 = (int *)(((int)puVar10 + (-0x18 - (int)piVar11) >> 3) * 0x1000 + piVar11[4]);
      for (; puVar10 < piVar11 + 0x806; puVar10 = puVar10 + 2) {
        if (((int)param_1 <= (int)*puVar10) && (param_1 < puVar10[1])) {
          piVar5 = (int *)FUN_008f7bd0(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_00909580 = (undefined *)piVar11;
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
          piVar5 = (int *)FUN_008f7bd0(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_00909580 = (undefined *)piVar11;
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
  } while (piVar11 != (int *)PTR_LOOP_00909580);
  ppuVar7 = &PTR_LOOP_00907560;
  while ((ppuVar7[4] == (undefined *)0xffffffff || (ppuVar7[3] == (undefined *)0x0))) {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &PTR_LOOP_00907560) {
      ppuVar7 = FUN_008f7630();
      if (ppuVar7 == (undefined **)0x0) {
        return (int *)0x0;
      }
      piVar11 = (int *)ppuVar7[4];
      *(char *)(piVar11 + 2) = (char)param_1;
      PTR_LOOP_00909580 = (undefined *)ppuVar7;
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
  PTR_LOOP_00909580 = (undefined *)ppuVar7;
  ppuVar7[3] = (undefined *)(-(uint)bVar12 & (uint)ppuVar6);
  *(char *)(piVar11 + 2) = (char)param_1;
  ppuVar7[2] = (undefined *)ppuVar3;
  *ppuVar3 = *ppuVar3 + -param_1;
  piVar11[1] = piVar11[1] - param_1;
  *piVar11 = (int)piVar11 + param_1 + 8;
  return piVar11 + 0x40;
}



/* VA 008f7bd0 */

int __cdecl FUN_008f7bd0(int *param_1,uint param_2,uint param_3)

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
            goto LAB_008f7d1f;
          }
          *param_1 = (int)(pbVar6 + param_3);
          param_1[1] = uVar5 - param_3;
          goto LAB_008f7d26;
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
LAB_008f7d1f:
            param_1[1] = 0;
          }
LAB_008f7d26:
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



/* VA 008f7d50 */

undefined4 __cdecl FUN_008f7d50(int param_1,int *param_2,byte *param_3,uint param_4)

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



/* VA 008f7e20 */

undefined4 __cdecl FUN_008f7e20(undefined4 param_1)

{
  int iVar1;

  if (DAT_0090b400 != (code *)0x0) {
    iVar1 = (*DAT_0090b400)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* VA 008f7e40 */

void FUN_008f7e40(void)

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

  puVar2 = (undefined4 *)FUN_008f56c0(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_0090cae0 = 0x20;
  DAT_0090c9e0 = puVar2;
  if (puVar2 < puVar2 + 0x120) {
    do {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar2[2] = 0;
      puVar2 = puVar2 + 9;
    } while (puVar2 < DAT_0090c9e0 + 0x120);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    local_48 = *(UINT *)local_44.lpReserved2;
    pUVar8 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar4 = (byte *)((int)pUVar8 + local_48);
    if (0x7ff < (int)local_48) {
      local_48 = 0x800;
    }
    if ((int)DAT_0090cae0 < (int)local_48) {
      piVar6 = &DAT_0090c9e4;
      do {
        puVar2 = (undefined4 *)FUN_008f56c0(0x480);
        if (puVar2 == (undefined4 *)0x0) {
          local_48 = DAT_0090cae0;
          break;
        }
        *piVar6 = (int)puVar2;
        DAT_0090cae0 = DAT_0090cae0 + 0x20;
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
      } while ((int)DAT_0090cae0 < (int)local_48);
    }
    uVar7 = 0;
    if (0 < (int)local_48) {
      do {
        if (((*(HANDLE *)pbVar4 != (HANDLE)0xffffffff) && ((*pUVar8 & 1) != 0)) &&
           (((*pUVar8 & 8) != 0 || (DVar3 = GetFileType(*(HANDLE *)pbVar4), DVar3 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_0090c9e0)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
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
    puVar2 = DAT_0090c9e0 + iVar5 * 9;
    if (DAT_0090c9e0[iVar5 * 9] == -1) {
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
        goto LAB_008f802e;
      }
      *puVar2 = hFile;
      if ((DVar3 & 0xff) == 2) {
        bVar1 = *(byte *)(puVar2 + 1) | 0x40;
        goto LAB_008f802e;
      }
      if ((DVar3 & 0xff) == 3) {
        bVar1 = *(byte *)(puVar2 + 1) | 8;
        goto LAB_008f802e;
      }
    }
    else {
      bVar1 = *(byte *)(puVar2 + 1) | 0x80;
LAB_008f802e:
      *(byte *)(puVar2 + 1) = bVar1;
    }
    iVar5 = iVar5 + 1;
    if (2 < iVar5) {
      SetHandleCount(DAT_0090cae0);
      return;
    }
  } while( true );
}



/* VA 008f8050 */

void FUN_008f8050(void)

{
  uint *puVar1;
  uint uVar2;
  LPCRITICAL_SECTION lpCriticalSection;

  puVar1 = &DAT_0090c9e0;
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
      FUN_008f5650((undefined *)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x90cae0);
  return;
}



/* VA 008f80b0 */

void FUN_008f80b0(void)

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
  cVar2 = *DAT_0090b388;
  pcVar7 = DAT_0090b388;
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
  piVar3 = (int *)FUN_008f56c0(iVar8 * 4 + 4);
  DAT_0090b360 = piVar3;
  if (piVar3 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar2 = *DAT_0090b388;
  local_4 = piVar3;
  pcVar7 = DAT_0090b388;
  do {
    if (cVar2 == '\0') {
      FUN_008f5650(DAT_0090b388);
      DAT_0090b388 = (char *)0x0;
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
      iVar8 = FUN_008f56c0(uVar4);
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



/* VA 008f81a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f81a0(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;

  GetModuleFileNameA((HMODULE)0x0,&DAT_0090b408,0x104);
  _DAT_0090b370 = &DAT_0090b408;
  pbVar2 = DAT_0090cae8;
  if (*DAT_0090cae8 == 0) {
    pbVar2 = &DAT_0090b408;
  }
  FUN_008f8240(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = (undefined4 *)FUN_008f56c0(local_4 + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_008f8240(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_0090b358 = puVar1;
  _DAT_0090b354 = local_8 + -1;
  return;
}



/* VA 008f8240 */

void __cdecl FUN_008f8240(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

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
      if (((*(byte *)((int)&DAT_0090b510 + bVar2 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)param_5 + 0x90b511) & 4) != 0) {
        *piVar6 = *piVar6 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar7;
          param_3 = param_3 + 1;
        }
        pbVar7 = param_1 + 2;
      }
      if (bVar2 == 0x20) break;
      if (bVar2 == 0) goto LAB_008f8319;
      param_1 = pbVar7;
    } while (bVar2 != 9);
    if (bVar2 == 0) {
LAB_008f8319:
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
          if ((*(byte *)((int)&DAT_0090b510 + bVar2 + 1) & 4) != 0) {
            pbVar7 = pbVar7 + 1;
            *piVar6 = *piVar6 + 1;
          }
          *piVar6 = *piVar6 + 1;
          goto LAB_008f8415;
        }
        if ((*(byte *)((int)&DAT_0090b510 + bVar2 + 1) & 4) != 0) {
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
LAB_008f8415:
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



/* VA 008f8450 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_008f8450(int param_1)

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

  FUN_008f74b0(0x19);
  CodePage = FUN_008f8670(param_1);
  if (CodePage == DAT_0090b614) {
    FUN_008f7530(0x19);
    return 0;
  }
  if (CodePage != 0) {
    iVar10 = 0;
    pUVar5 = &DAT_009095b8;
    do {
      if (*pUVar5 == CodePage) {
        puVar14 = &DAT_0090b510;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar14 = 0;
          puVar14 = puVar14 + 1;
        }
        *(undefined1 *)puVar14 = 0;
        uVar7 = 0;
        iVar10 = iVar10 * 0x30;
        pbVar12 = (byte *)(iVar10 + 0x9095c8);
        do {
          bVar3 = *pbVar12;
          for (pbVar13 = pbVar12; (bVar3 != 0 && (bVar3 = pbVar13[1], bVar3 != 0));
              pbVar13 = pbVar13 + 2) {
            uVar8 = (uint)*pbVar13;
            if (uVar8 <= bVar3) {
              bVar4 = (&DAT_009095b0)[uVar7];
              do {
                pbVar2 = (byte *)((int)&DAT_0090b510 + uVar8 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar8 = uVar8 + 1;
              } while (uVar8 <= bVar3);
            }
            bVar3 = pbVar13[2];
          }
          uVar7 = uVar7 + 1;
          pbVar12 = pbVar12 + 8;
        } while (uVar7 < 4);
        DAT_0090b614 = CodePage;
        DAT_0090b618 = FUN_008f86c0(CodePage);
        _DAT_0090b620 = *(undefined4 *)(iVar10 + 0x9095bc);
        _DAT_0090b624 = *(undefined4 *)(iVar10 + 0x9095c0);
        _DAT_0090b628 = *(undefined4 *)(iVar10 + 0x9095c4);
        FUN_008f7530(0x19);
        return 0;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar10 = iVar10 + 1;
    } while (pUVar5 < &DAT_009096a8);
    BVar6 = GetCPInfo(CodePage,&local_14);
    if (BVar6 == 1) {
      puVar14 = &DAT_0090b510;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      *(undefined1 *)puVar14 = 0;
      if (local_14.MaxCharSize < 2) {
        DAT_0090b614 = 0;
        DAT_0090b618 = 0;
      }
      else {
        if (local_14.LeadByte[0] != '\0') {
          pBVar11 = local_14.LeadByte + 1;
          do {
            bVar3 = *pBVar11;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar11[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              *(byte *)((int)&DAT_0090b510 + uVar7 + 1) =
                   *(byte *)((int)&DAT_0090b510 + uVar7 + 1) | 4;
            }
            pBVar1 = pBVar11 + 1;
            pBVar11 = pBVar11 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          *(byte *)((int)&DAT_0090b510 + uVar7 + 1) = *(byte *)((int)&DAT_0090b510 + uVar7 + 1) | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_0090b614 = CodePage;
        DAT_0090b618 = FUN_008f86c0(CodePage);
      }
      _DAT_0090b620 = 0;
      _DAT_0090b624 = 0;
      _DAT_0090b628 = 0;
      FUN_008f7530(0x19);
      return 0;
    }
    if (DAT_0090b62c == 0) {
      FUN_008f7530(0x19);
      return 0xffffffff;
    }
  }
  FUN_008f8720();
  FUN_008f7530(0x19);
  return 0;
}



/* VA 008f8670 */

int __cdecl FUN_008f8670(int param_1)

{
  int iVar1;
  bool bVar2;

  if (param_1 == -2) {
    DAT_0090b62c = 1;
                    /* WARNING: Could not recover jumptable at 0x008f868d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_0090b62c = 1;
                    /* WARNING: Could not recover jumptable at 0x008f86a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_0090b660;
  }
  DAT_0090b62c = (uint)bVar2;
  return param_1;
}



/* VA 008f86c0 */

undefined4 __cdecl FUN_008f86c0(undefined4 param_1)

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



/* VA 008f8720 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f8720(void)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = &DAT_0090b510;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_0090b614 = 0;
  DAT_0090b618 = 0;
  _DAT_0090b620 = 0;
  _DAT_0090b624 = 0;
  _DAT_0090b628 = 0;
  return;
}



/* VA 008f8750 */

void FUN_008f8750(void)

{
  FUN_008f8450(-3);
  return;
}



/* VA 008f8760 */

LPSTR FUN_008f8760(void)

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
  if (DAT_0090b634 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar10 = GetEnvironmentStrings();
      if (pCVar10 == (LPCH)0x0) {
        return (LPSTR)0x0;
      }
      DAT_0090b634 = 2;
    }
    else {
      DAT_0090b634 = 1;
    }
  }
  if (DAT_0090b634 == 1) {
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
      if ((uVar6 != 0) && (pCVar7 = (LPSTR)FUN_008f56c0(uVar6), pCVar7 != (LPSTR)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar7,uVar6,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar5 == 0) {
          FUN_008f5650(pCVar7);
          pCVar7 = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(lpWideCharStr);
        return pCVar7;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return (LPSTR)0x0;
    }
  }
  else if ((DAT_0090b634 == 2) &&
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
    pCVar7 = (LPSTR)FUN_008f56c0((uint)pCVar9);
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



/* VA 008f88c0 */

void __cdecl FUN_008f88c0(undefined4 param_1)

{
  DAT_0090b394 = param_1;
  return;
}



/* VA 008f88d0 */

void FUN_008f88d0(void)

{
  if ((DAT_0090b390 == 1) || ((DAT_0090b390 == 0 && (DAT_0090b394 == 1)))) {
    FUN_008f8910(0xfc);
    if (DAT_0090b638 != (code *)0x0) {
      (*DAT_0090b638)();
    }
    FUN_008f8910(0xff);
  }
  return;
}



/* VA 008f8910 */

void __cdecl FUN_008f8910(int param_1)

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

  piVar2 = &DAT_009096a8;
  iVar8 = 0;
  do {
    if (param_1 == *piVar2) break;
    piVar2 = piVar2 + 2;
    iVar8 = iVar8 + 1;
  } while (piVar2 < &DAT_00909738);
  if (param_1 == (&DAT_009096a8)[iVar8 * 2]) {
    if ((DAT_0090b390 == 1) || ((DAT_0090b390 == 0 && (DAT_0090b394 == 1)))) {
      if ((DAT_0090c9e0 == 0) ||
         (hFile = *(HANDLE *)(DAT_0090c9e0 + 0x48), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar7 = *(char **)(iVar8 * 8 + 0x9096ac);
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
      pcVar7 = *(char **)(iVar8 * 8 + 0x9096ac);
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
      FUN_008f9e40(local_1a4,"Microsoft Visual C++ Runtime Library",0x12010);
      return;
    }
  }
  return;
}



/* VA 008f8b00 */

uint * __cdecl FUN_008f8b00(uint *param_1,char param_2)

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



/* VA 008f8bc0 */

int __cdecl
FUN_008f8bc0(LCID param_1,uint param_2,char *param_3,LPCWSTR param_4,LPWSTR param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  LPCWSTR cbMultiByte;
  LPCWSTR lpWideCharStr;
  int iVar2;

  if (DAT_0090b668 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0090b668 = 1;
    }
    else {
      DAT_0090b668 = 2;
    }
  }
  cbMultiByte = param_4;
  if (0 < (int)param_4) {
    cbMultiByte = (LPCWSTR)FUN_008fc810(param_3,(int)param_4);
  }
  if (DAT_0090b668 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,(int)cbMultiByte,(LPSTR)param_5,param_6);
    return iVar1;
  }
  if (DAT_0090b668 != 1) {
    return DAT_0090b668;
  }
  param_4 = (LPCWSTR)0x0;
  if (param_7 == 0) {
    param_7 = DAT_0090b660;
  }
  iVar1 = MultiByteToWideChar(param_7,9,param_3,(int)cbMultiByte,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return 0;
  }
  lpWideCharStr = (LPCWSTR)FUN_008f56c0(iVar1 * 2);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  iVar2 = MultiByteToWideChar(param_7,1,param_3,(int)cbMultiByte,lpWideCharStr,iVar1);
  if ((iVar2 != 0) &&
     (iVar2 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,(LPWSTR)0x0,0), iVar2 != 0)) {
    if ((param_2 & 0x400) == 0) {
      param_4 = (LPCWSTR)FUN_008f56c0(iVar2 * 2);
      if ((param_4 == (LPCWSTR)0x0) ||
         (iVar1 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,param_4,iVar2), iVar1 == 0))
      goto LAB_008f8dbf;
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
      if (param_6 == 0) goto LAB_008f8d24;
      if (param_6 < iVar2) goto LAB_008f8dbf;
      iVar1 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,param_5,param_6);
    }
    if (iVar1 != 0) {
LAB_008f8d24:
      FUN_008f5650((undefined *)lpWideCharStr);
      FUN_008f5650((undefined *)param_4);
      return iVar2;
    }
  }
LAB_008f8dbf:
  FUN_008f5650((undefined *)lpWideCharStr);
  FUN_008f5650((undefined *)param_4);
  return 0;
}



/* VA 008f8de0 */

uint __cdecl FUN_008f8de0(int param_1,uint param_2)

{
  int iVar1;
  BOOL BVar2;
  uint local_4;

  iVar1 = param_1;
  if (param_1 + 1U < 0x101) {
    return *(ushort *)(PTR_DAT_009098a0 + param_1 * 2) & param_2;
  }
  if ((PTR_DAT_009098a0[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1._0_2_ = (ushort)(byte)param_1;
    iVar1 = 1;
  }
  else {
    param_1._0_2_ = CONCAT11((byte)param_1,(char)((uint)param_1 >> 8));
    param_1._3_1_ = SUB41(iVar1,3);
    param_1._0_3_ = (uint3)(ushort)param_1;
    iVar1 = 2;
  }
  BVar2 = FUN_008fb150(1,(LPCSTR)&param_1,iVar1,(LPWORD)&local_4,0,0);
  if (BVar2 == 0) {
    return 0;
  }
  return local_4 & 0xffff & param_2;
}



/* VA 008f8e80 */

byte * __cdecl FUN_008f8e80(byte *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;

  if (DAT_0090b614 == 0) {
    pbVar3 = (byte *)_strncpy((char *)param_1,(char *)param_2,param_3);
    return pbVar3;
  }
  FUN_008f74b0(0x19);
  uVar5 = 0;
  pbVar3 = param_1;
  pbVar6 = param_1;
  if (param_3 != 0) {
    do {
      bVar1 = *param_2;
      uVar5 = param_3 - 1;
      bVar2 = *(byte *)((int)&DAT_0090b510 + bVar1 + 1);
      *pbVar6 = bVar1;
      if ((bVar2 & 4) == 0) {
        pbVar3 = pbVar6 + 1;
        param_2 = param_2 + 1;
        if (bVar1 == 0) goto LAB_008f8efd;
      }
      else {
        pbVar3 = pbVar6 + 1;
        if (uVar5 == 0) {
          *pbVar6 = 0;
          goto LAB_008f8efd;
        }
        bVar1 = param_2[1];
        uVar5 = param_3 - 2;
        *pbVar3 = bVar1;
        pbVar3 = pbVar6 + 2;
        param_2 = param_2 + 2;
        if (bVar1 == 0) {
          *pbVar6 = 0;
          goto LAB_008f8efd;
        }
      }
      param_3 = uVar5;
      pbVar6 = pbVar3;
    } while (uVar5 != 0);
    uVar5 = 0;
  }
LAB_008f8efd:
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
  FUN_008f7530(0x19);
  return param_1;
}



/* VA 008f8f30 */

int * __cdecl FUN_008f8f30(int param_1,int param_2)

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
      if (DAT_00909584 < dwBytes) {
LAB_008f8fa4:
        if (piVar3 != (int *)0x0) {
          return piVar3;
        }
      }
      else {
        FUN_008f74b0(9);
        piVar3 = FUN_008f7990(dwBytes >> 4);
        FUN_008f7530(9);
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
          goto LAB_008f8fa4;
        }
      }
      piVar3 = HeapAlloc(DAT_0090cae4,8,dwBytes);
    }
    if ((piVar3 != (int *)0x0) || (DAT_0090b3fc == 0)) {
      return piVar3;
    }
    iVar1 = FUN_008f7e20(dwBytes);
    if (iVar1 == 0) {
      return (int *)0x0;
    }
  } while( true );
}



/* VA 008f8fe0 */

void FUN_008f8fe0(void)

{
  if (DAT_0090b728 == 0) {
    FUN_008f74b0(0xb);
    if (DAT_0090b728 == 0) {
      FUN_008f9020();
      DAT_0090b728 = DAT_0090b728 + 1;
    }
    FUN_008f7530(0xb);
  }
  return;
}



/* VA 008f9020 */

void FUN_008f9020(void)

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

  FUN_008f74b0(0xc);
  DAT_0090b670 = 0;
  DAT_00909be8 = 0xffffffff;
  DAT_00909bd8 = 0xffffffff;
  pbVar3 = (byte *)FUN_008fb5d0(&DAT_00906428);
  if (pbVar3 == (byte *)0x0) {
    FUN_008f7530(0xc);
    DVar4 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_0090b678);
    if (DVar4 == 0xffffffff) {
      return;
    }
    DAT_0090b670 = 1;
    DAT_00909b40 = DAT_0090b678 * 0x3c;
    if (DAT_0090b6be != 0) {
      DAT_00909b40 = DAT_00909b40 + DAT_0090b6cc * 0x3c;
    }
    if ((DAT_0090b712 == 0) || (DAT_0090b720 == 0)) {
      DAT_00909b44 = 0;
      DAT_00909b48 = 0;
    }
    else {
      DAT_00909b44 = 1;
      DAT_00909b48 = (DAT_0090b720 - DAT_0090b6cc) * 0x3c;
    }
    FUN_008fb320(PTR_DAT_00909bd0,(LPCWSTR)&DAT_0090b67c,0x40);
    FUN_008fb320(PTR_DAT_00909bd4,(LPCWSTR)&DAT_0090b6d0,0x40);
    PTR_DAT_00909bd4[0x3f] = 0;
    PTR_DAT_00909bd0[0x3f] = 0;
    return;
  }
  if (*pbVar3 != 0) {
    pbVar8 = pbVar3;
    pbVar9 = DAT_0090b724;
    if (DAT_0090b724 != (byte *)0x0) {
      do {
        bVar1 = *pbVar8;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_008f9177:
          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_008f917c;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_008f9177;
        pbVar8 = pbVar8 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_008f917c:
      if (iVar5 == 0) goto LAB_008f92e9;
    }
    FUN_008f5650(DAT_0090b724);
    uVar6 = 0xffffffff;
    pbVar8 = pbVar3;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar1 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar1 != 0);
    DAT_0090b724 = (byte *)FUN_008f56c0(~uVar6);
    if (DAT_0090b724 != (byte *)0x0) {
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
      pbVar9 = DAT_0090b724;
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
      FUN_008f7530(0xc);
      _strncpy(PTR_DAT_00909bd0,(char *)pbVar3,3);
      pbVar8 = pbVar3 + 3;
      PTR_DAT_00909bd0[3] = 0;
      bVar1 = *pbVar8;
      if (bVar1 == 0x2d) {
        pbVar8 = pbVar3 + 4;
      }
      iVar5 = FUN_008fb280(pbVar8);
      DAT_00909b40 = iVar5 * 0xe10;
      for (; (bVar2 = *pbVar8, bVar2 == 0x2b || (('/' < (char)bVar2 && ((char)bVar2 < ':'))));
          pbVar8 = pbVar8 + 1) {
      }
      if (*pbVar8 == 0x3a) {
        pbVar8 = pbVar8 + 1;
        iVar5 = FUN_008fb280(pbVar8);
        DAT_00909b40 = DAT_00909b40 + iVar5 * 0x3c;
        bVar2 = *pbVar8;
        while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
          pbVar3 = pbVar8 + 1;
          pbVar8 = pbVar8 + 1;
          bVar2 = *pbVar3;
        }
        if (*pbVar8 == 0x3a) {
          pbVar8 = pbVar8 + 1;
          iVar5 = FUN_008fb280(pbVar8);
          DAT_00909b40 = DAT_00909b40 + iVar5;
          bVar2 = *pbVar8;
          while (('/' < (char)bVar2 && ((char)bVar2 < ':'))) {
            pbVar3 = pbVar8 + 1;
            pbVar8 = pbVar8 + 1;
            bVar2 = *pbVar3;
          }
        }
      }
      if (bVar1 == 0x2d) {
        DAT_00909b40 = -DAT_00909b40;
      }
      DAT_00909b44 = (int)(char)*pbVar8;
      if (DAT_00909b44 == 0) {
        *PTR_DAT_00909bd4 = 0;
        return;
      }
      _strncpy(PTR_DAT_00909bd4,(char *)pbVar8,3);
      PTR_DAT_00909bd4[3] = 0;
      return;
    }
  }
LAB_008f92e9:
  FUN_008f7530(0xc);
  return;
}



/* VA 008f9300 */

/* Library Function - Single Match
    __isindst

   Library: Visual Studio 1998 Release */

int __cdecl __isindst(tm *_Time)

{
  bool bVar1;
  undefined3 extraout_var;

  FUN_008f74b0(0xb);
  bVar1 = FUN_008f9330(&_Time->tm_sec);
  FUN_008f7530(0xb);
  return CONCAT31(extraout_var,bVar1);
}



/* VA 008f9330 */

bool __cdecl FUN_008f9330(int *param_1)

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

  if (DAT_00909b44 == 0) {
    return false;
  }
  uVar7 = param_1[5];
  if ((uVar7 == DAT_00909bd8) && (uVar7 == DAT_00909be8)) goto LAB_008f9504;
  if (DAT_0090b670 == 0) {
    FUN_008f95a0(1,1,uVar7,4,1,0,0,2,0,0,0);
    uVar7 = param_1[5];
    uVar11 = 0;
    uVar3 = 0;
    uVar10 = 0;
    uVar4 = 2;
    uVar1 = 0;
    uVar9 = 5;
    uVar8 = 10;
LAB_008f94f8:
    uVar5 = 0;
    iVar6 = 1;
  }
  else {
    if (DAT_0090b710 != 0) {
      uVar10 = (uint)DAT_0090b714._2_2_;
      uVar3 = 0;
      uVar1 = 0;
    }
    else {
      uVar3 = DAT_0090b714 & 0xffff;
      uVar10 = 0;
      uVar1 = (uint)DAT_0090b714._2_2_;
    }
    FUN_008f95a0(1,(uint)(DAT_0090b710 == 0),uVar7,(uint)DAT_0090b712,uVar1,uVar3,uVar10,
                 DAT_0090b718 & 0xffff,DAT_0090b718 >> 0x10,DAT_0090b71c & 0xffff,
                 DAT_0090b71c >> 0x10);
    if (DAT_0090b6bc == 0) {
      uVar11 = (uint)DAT_0090b6c8._2_2_;
      uVar3 = DAT_0090b6c8 & 0xffff;
      uVar10 = (uint)DAT_0090b6c4._2_2_;
      uVar4 = DAT_0090b6c4 & 0xffff;
      uVar1 = DAT_0090b6c0 & 0xffff;
      uVar9 = (uint)DAT_0090b6c0._2_2_;
      uVar8 = (uint)DAT_0090b6be;
      uVar7 = param_1[5];
      goto LAB_008f94f8;
    }
    uVar11 = (uint)DAT_0090b6c8._2_2_;
    uVar3 = DAT_0090b6c8 & 0xffff;
    uVar10 = (uint)DAT_0090b6c4._2_2_;
    uVar5 = (uint)DAT_0090b6c0._2_2_;
    uVar4 = DAT_0090b6c4 & 0xffff;
    uVar7 = param_1[5];
    uVar8 = (uint)DAT_0090b6be;
    uVar1 = 0;
    uVar9 = 0;
    iVar6 = 0;
  }
  FUN_008f95a0(0,iVar6,uVar7,uVar8,uVar9,uVar1,uVar5,uVar4,uVar10,uVar3,uVar11);
LAB_008f9504:
  iVar6 = param_1[7];
  if (DAT_00909bdc < DAT_00909bec) {
    if ((iVar6 < DAT_00909bdc) || (DAT_00909bec < iVar6)) {
      return false;
    }
    if ((DAT_00909bdc < iVar6) && (iVar6 < DAT_00909bec)) {
      return true;
    }
  }
  else {
    if ((iVar6 < DAT_00909bec) || (DAT_00909bdc < iVar6)) {
      return true;
    }
    if ((DAT_00909bec < iVar6) && (iVar6 < DAT_00909bdc)) {
      return false;
    }
  }
  iVar2 = (*param_1 + (param_1[1] + param_1[2] * 0x3c) * 0x3c) * 1000;
  if (iVar6 != DAT_00909bdc) {
    return iVar2 < DAT_00909bf0;
  }
  return DAT_00909be0 <= iVar2;
}



/* VA 008f95a0 */

void __cdecl
FUN_008f95a0(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;

  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_00909bf4 + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_00909c2c + param_4 * 4);
    }
    iVar2 = (int)(((int)(param_3 - 1) >> 2) + -0x63db + param_3 * 0x16d + iVar1 + 1) % 7;
    if (iVar2 < param_6) {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&DAT_00909bf8 + param_4 * 4);
      }
      else {
        iVar2 = *(int *)(&DAT_00909c30 + param_4 * 4);
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_00909bf4 + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_00909c2c + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_00909bdc = iVar1;
    DAT_00909bd8 = param_3;
    DAT_00909be0 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c) * 1000;
    return;
  }
  DAT_00909bec = iVar1;
  DAT_00909bf0 = param_11 + (param_10 + (param_9 + param_8 * 0x3c) * 0x3c + DAT_00909b48) * 1000;
  if (DAT_00909bf0 < 0) {
    DAT_00909be8 = param_3;
    DAT_00909bf0 = DAT_00909bf0 + 86399999;
    return;
  }
  if (86399999 < DAT_00909bf0) {
    DAT_00909bf0 = DAT_00909bf0 + -86399999;
  }
  DAT_00909be8 = param_3;
  return;
}



/* VA 008f9740 */

DWORD __cdecl FUN_008f9740(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_0090cae0) &&
     ((*(byte *)((&DAT_0090c9e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_008fb7f0(param_1);
    DVar1 = FUN_008f97c0(param_1,param_2,param_3);
    FUN_008fb860(param_1);
    return DVar1;
  }
  pDVar2 = FUN_008fb6e0();
  *pDVar2 = 9;
  pDVar2 = FUN_008fb6f0();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 008f97c0 */

DWORD __cdecl FUN_008f97c0(uint param_1,LONG param_2,DWORD param_3)

{
  HANDLE hFile;
  DWORD *pDVar1;
  DWORD DVar2;
  undefined *puVar3;

  hFile = (HANDLE)FUN_008fb7a0(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar1 = FUN_008fb6e0();
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
    FUN_008fb660(puVar3);
    return 0xffffffff;
  }
  *(byte *)((&DAT_0090c9e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) =
       *(byte *)((&DAT_0090c9e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0xfd;
  return DVar2;
}



/* VA 008f9840 */

int __cdecl FUN_008f9840(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_0090cae0) &&
     ((*(byte *)((&DAT_0090c9e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_008fb7f0(param_1);
    iVar1 = FUN_008f98c0(param_1,param_2,param_3);
    FUN_008fb860(param_1);
    return iVar1;
  }
  pDVar2 = FUN_008fb6e0();
  *pDVar2 = 9;
  pDVar2 = FUN_008fb6f0();
  *pDVar2 = 0;
  return -1;
}



/* VA 008f98c0 */

int __cdecl FUN_008f98c0(uint param_1,char *param_2,uint param_3)

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
  piVar1 = &DAT_0090c9e0 + ((int)param_1 >> 5);
  iVar6 = (param_1 & 0x1f) * 0x24;
  local_408 = piVar1;
  if ((*(byte *)(iVar6 + 4 + *piVar1) & 0x20) != 0) {
    FUN_008f97c0(param_1,0,2);
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
    pDVar5 = FUN_008fb6e0();
    *pDVar5 = 0x1c;
    pDVar5 = FUN_008fb6f0();
    *pDVar5 = 0;
    return -1;
  }
  if (local_414 != (undefined *)0x5) {
    FUN_008fb660(local_414);
    return -1;
  }
  pDVar5 = FUN_008fb6e0();
  *pDVar5 = 9;
  pDVar5 = FUN_008fb6f0();
  *pDVar5 = 5;
  return -1;
}



/* VA 008f9ad0 */

void __cdecl FUN_008f9ad0(int *param_1)

{
  int iVar1;

  DAT_0090b72c = DAT_0090b72c + 1;
  iVar1 = FUN_008f56c0(0x1000);
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



/* VA 008f9b30 */

byte __cdecl FUN_008f9b30(uint param_1)

{
  if (DAT_0090cae0 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_0090c9e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}



/* VA 008f9c40 */

int __cdecl FUN_008f9c40(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;

  InterlockedIncrement((LONG *)&DAT_0090c9c8);
  bVar2 = DAT_0090c9c4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_0090c9c8);
    FUN_008f74b0(0x13);
  }
  iVar1 = FUN_008f9cb0(param_1,param_2);
  if (!bVar2) {
    InterlockedDecrement((LONG *)&DAT_0090c9c8);
    return iVar1;
  }
  FUN_008f7530(0x13);
  return iVar1;
}



/* VA 008f9cb0 */

int __cdecl FUN_008f9cb0(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  DWORD *pDVar2;

  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_0090b650 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_0090b660,0x220,&param_2,1,lpMultiByteStr,DAT_00909aac,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  pDVar2 = FUN_008fb6e0();
  *pDVar2 = 0x2a;
  return -1;
}



/* VA 008f9d30 */

undefined8 FUN_008f9d30(uint param_1,uint param_2,uint param_3,uint param_4)

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



/* VA 008f9da0 */

undefined8 FUN_008f9da0(uint param_1,uint param_2,uint param_3,uint param_4)

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



/* VA 008f9e20 */

int __cdecl FUN_008f9e20(short *param_1)

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



/* VA 008f9e40 */

int __cdecl FUN_008f9e40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;

  iVar1 = 0;
  if (DAT_0090b730 != (FARPROC)0x0) {
LAB_008f9e90:
    if (DAT_0090b734 != (FARPROC)0x0) {
      iVar1 = (*DAT_0090b734)();
    }
    if ((iVar1 != 0) && (DAT_0090b738 != (FARPROC)0x0)) {
      iVar1 = (*DAT_0090b738)(iVar1);
    }
    iVar1 = (*DAT_0090b730)(iVar1,param_1,param_2,param_3);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0090b730 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0090b730 != (FARPROC)0x0) {
      DAT_0090b734 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_0090b738 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_008f9e90;
    }
  }
  return 0;
}



/* VA 008f9ed0 */

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
        goto joined_r0x008f9f0e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_008f9f4b;
        goto LAB_008f9fb9;
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
joined_r0x008f9fb5:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_008f9fb9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_008f9f4b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x008f9fb5;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x008f9fb5;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x008f9fb5;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x008f9f0e:
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
LAB_008f9f4b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* VA 008fa080 */

uint __cdecl FUN_008fa080(char *param_1)

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

  uVar40 = (uint)DAT_0090b776;
  pcVar44 = (char *)(uint)DAT_0090b778;
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  uVar1 = FUN_008fbac0(1,uVar40,0x31,param_1 + 4);
  uVar2 = FUN_008fbac0(1,uVar40,0x32,param_1 + 8);
  uVar3 = FUN_008fbac0(1,uVar40,0x33,param_1 + 0xc);
  uVar4 = FUN_008fbac0(1,uVar40,0x34,param_1 + 0x10);
  uVar5 = FUN_008fbac0(1,uVar40,0x35,param_1 + 0x14);
  uVar6 = FUN_008fbac0(1,uVar40,0x36,param_1 + 0x18);
  uVar7 = FUN_008fbac0(1,uVar40,0x37,param_1);
  uVar8 = FUN_008fbac0(1,uVar40,0x2a,param_1 + 0x20);
  uVar9 = FUN_008fbac0(1,uVar40,0x2b,param_1 + 0x24);
  uVar10 = FUN_008fbac0(1,uVar40,0x2c,param_1 + 0x28);
  uVar11 = FUN_008fbac0(1,uVar40,0x2d,param_1 + 0x2c);
  uVar12 = FUN_008fbac0(1,uVar40,0x2e,param_1 + 0x30);
  uVar13 = FUN_008fbac0(1,uVar40,0x2f,param_1 + 0x34);
  uVar14 = FUN_008fbac0(1,uVar40,0x30,param_1 + 0x1c);
  uVar15 = FUN_008fbac0(1,uVar40,0x44,param_1 + 0x38);
  uVar16 = FUN_008fbac0(1,uVar40,0x45,param_1 + 0x3c);
  uVar17 = FUN_008fbac0(1,uVar40,0x46,param_1 + 0x40);
  uVar18 = FUN_008fbac0(1,uVar40,0x47,param_1 + 0x44);
  uVar19 = FUN_008fbac0(1,uVar40,0x48,param_1 + 0x48);
  uVar20 = FUN_008fbac0(1,uVar40,0x49,param_1 + 0x4c);
  uVar21 = FUN_008fbac0(1,uVar40,0x4a,param_1 + 0x50);
  uVar22 = FUN_008fbac0(1,uVar40,0x4b,param_1 + 0x54);
  uVar23 = FUN_008fbac0(1,uVar40,0x4c,param_1 + 0x58);
  uVar24 = FUN_008fbac0(1,uVar40,0x4d,param_1 + 0x5c);
  uVar25 = FUN_008fbac0(1,uVar40,0x4e,param_1 + 0x60);
  uVar26 = FUN_008fbac0(1,uVar40,0x4f,param_1 + 100);
  uVar27 = FUN_008fbac0(1,uVar40,0x38,param_1 + 0x68);
  uVar28 = FUN_008fbac0(1,uVar40,0x39,param_1 + 0x6c);
  uVar29 = FUN_008fbac0(1,uVar40,0x3a,param_1 + 0x70);
  uVar30 = FUN_008fbac0(1,uVar40,0x3b,param_1 + 0x74);
  uVar31 = FUN_008fbac0(1,uVar40,0x3c,param_1 + 0x78);
  uVar32 = FUN_008fbac0(1,uVar40,0x3d,param_1 + 0x7c);
  uVar33 = FUN_008fbac0(1,uVar40,0x3e,param_1 + 0x80);
  uVar34 = FUN_008fbac0(1,uVar40,0x3f,param_1 + 0x84);
  uVar35 = FUN_008fbac0(1,uVar40,0x40,param_1 + 0x88);
  uVar36 = FUN_008fbac0(1,uVar40,0x41,param_1 + 0x8c);
  uVar37 = FUN_008fbac0(1,uVar40,0x42,param_1 + 0x90);
  uVar38 = FUN_008fbac0(1,uVar40,0x43,param_1 + 0x94);
  uVar39 = FUN_008fbac0(1,uVar40,0x28,param_1 + 0x98);
  uVar40 = FUN_008fbac0(1,uVar40,0x29,param_1 + 0x9c);
  uVar41 = FUN_008fbac0(1,(LCID)pcVar44,0x1f,param_1 + 0xa0);
  uVar42 = FUN_008fbac0(1,(LCID)pcVar44,0x20,param_1 + 0xa4);
  uVar43 = FUN_008fa640(pcVar44,(int)param_1);
  return uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
         uVar12 | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21 |
         uVar22 | uVar23 | uVar24 | uVar25 | uVar26 | uVar27 | uVar28 | uVar29 | uVar30 | uVar31 |
         uVar32 | uVar33 | uVar34 | uVar35 | uVar36 | uVar37 | uVar38 | uVar39 | uVar40 | uVar41 |
         uVar42 | uVar43;
}



/* VA 008fa400 */

void __cdecl FUN_008fa400(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_008f5650((undefined *)param_1[1]);
    FUN_008f5650((undefined *)param_1[2]);
    FUN_008f5650((undefined *)param_1[3]);
    FUN_008f5650((undefined *)param_1[4]);
    FUN_008f5650((undefined *)param_1[5]);
    FUN_008f5650((undefined *)param_1[6]);
    FUN_008f5650((undefined *)*param_1);
    FUN_008f5650((undefined *)param_1[8]);
    FUN_008f5650((undefined *)param_1[9]);
    FUN_008f5650((undefined *)param_1[10]);
    FUN_008f5650((undefined *)param_1[0xb]);
    FUN_008f5650((undefined *)param_1[0xc]);
    FUN_008f5650((undefined *)param_1[0xd]);
    FUN_008f5650((undefined *)param_1[7]);
    FUN_008f5650((undefined *)param_1[0xe]);
    FUN_008f5650((undefined *)param_1[0xf]);
    FUN_008f5650((undefined *)param_1[0x10]);
    FUN_008f5650((undefined *)param_1[0x11]);
    FUN_008f5650((undefined *)param_1[0x12]);
    FUN_008f5650((undefined *)param_1[0x13]);
    FUN_008f5650((undefined *)param_1[0x14]);
    FUN_008f5650((undefined *)param_1[0x15]);
    FUN_008f5650((undefined *)param_1[0x16]);
    FUN_008f5650((undefined *)param_1[0x17]);
    FUN_008f5650((undefined *)param_1[0x18]);
    FUN_008f5650((undefined *)param_1[0x19]);
    FUN_008f5650((undefined *)param_1[0x1a]);
    FUN_008f5650((undefined *)param_1[0x1b]);
    FUN_008f5650((undefined *)param_1[0x1c]);
    FUN_008f5650((undefined *)param_1[0x1d]);
    FUN_008f5650((undefined *)param_1[0x1e]);
    FUN_008f5650((undefined *)param_1[0x1f]);
    FUN_008f5650((undefined *)param_1[0x20]);
    FUN_008f5650((undefined *)param_1[0x21]);
    FUN_008f5650((undefined *)param_1[0x22]);
    FUN_008f5650((undefined *)param_1[0x23]);
    FUN_008f5650((undefined *)param_1[0x24]);
    FUN_008f5650((undefined *)param_1[0x25]);
    FUN_008f5650((undefined *)param_1[0x26]);
    FUN_008f5650((undefined *)param_1[0x27]);
    FUN_008f5650((undefined *)param_1[0x28]);
    FUN_008f5650((undefined *)param_1[0x29]);
    FUN_008f5650((undefined *)param_1[0x2a]);
  }
  return;
}



/* VA 008fa640 */

uint __cdecl FUN_008fa640(char *param_1,int param_2)

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
  uVar3 = FUN_008fbac0(0,(LCID)param_1,0x23,(char *)&local_4);
  uVar4 = FUN_008fbac0(0,(LCID)pcVar7,0x25,(char *)&local_8);
  uVar5 = FUN_008fbac0(1,(LCID)pcVar7,0x1e,(char *)&param_1);
  uVar5 = uVar3 | uVar4 | uVar5;
  if (uVar5 != 0) {
    return uVar5;
  }
  puVar6 = (undefined1 *)FUN_008f56c0(0xd);
  *(undefined1 **)(param_2 + 0xa8) = puVar6;
  if (local_4 == 0) {
    *puVar6 = 0x68;
    pcVar7 = puVar6 + 1;
    if (local_8 == 0) goto LAB_008fa6dc;
    *pcVar7 = 'h';
  }
  else {
    *puVar6 = 0x48;
    pcVar7 = puVar6 + 1;
    if (local_8 == 0) goto LAB_008fa6dc;
    *pcVar7 = 'H';
  }
  pcVar7 = puVar6 + 2;
LAB_008fa6dc:
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
  FUN_008f5650(param_1);
  return 0;
}



/* VA 008faa30 */

uint __cdecl FUN_008faa30(int param_1)

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

  uVar15 = (uint)DAT_0090b76c;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_008fbac0(1,uVar15,0x15,(char *)(param_1 + 0xc));
  uVar2 = FUN_008fbac0(1,uVar15,0x14,(char *)(param_1 + 0x10));
  uVar3 = FUN_008fbac0(1,uVar15,0x16,(char *)(param_1 + 0x14));
  uVar4 = FUN_008fbac0(1,uVar15,0x17,(char *)(param_1 + 0x18));
  uVar5 = FUN_008fbac0(1,uVar15,0x18,(char *)(param_1 + 0x1c));
  FUN_008fab80(*(char **)(param_1 + 0x1c));
  uVar6 = FUN_008fbac0(1,uVar15,0x50,(char *)(param_1 + 0x20));
  uVar7 = FUN_008fbac0(1,uVar15,0x51,(char *)(param_1 + 0x24));
  uVar8 = FUN_008fbac0(0,uVar15,0x1a,(char *)(param_1 + 0x28));
  uVar9 = FUN_008fbac0(0,uVar15,0x19,(char *)(param_1 + 0x29));
  uVar10 = FUN_008fbac0(0,uVar15,0x54,(char *)(param_1 + 0x2a));
  uVar11 = FUN_008fbac0(0,uVar15,0x55,(char *)(param_1 + 0x2b));
  uVar12 = FUN_008fbac0(0,uVar15,0x56,(char *)(param_1 + 0x2c));
  uVar13 = FUN_008fbac0(0,uVar15,0x57,(char *)(param_1 + 0x2d));
  uVar14 = FUN_008fbac0(0,uVar15,0x52,(char *)(param_1 + 0x2e));
  uVar15 = FUN_008fbac0(0,uVar15,0x53,(char *)(param_1 + 0x2f));
  return uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
         uVar12 | uVar13 | uVar14 | uVar15;
}



/* VA 008fab80 */

void __cdecl FUN_008fab80(char *param_1)

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
      if (cVar2 != ';') goto LAB_008fab96;
      do {
        *pcVar3 = pcVar3[1];
        pcVar1 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    else {
      *param_1 = cVar2 + -0x30;
LAB_008fab96:
      param_1 = param_1 + 1;
    }
    cVar2 = *param_1;
  } while( true );
}



/* VA 008fabc0 */

void __cdecl FUN_008fabc0(int param_1)

{
  if ((param_1 != 0) && (*(undefined **)(param_1 + 0xc) != &DAT_0090b798)) {
    FUN_008f5650(*(undefined **)(param_1 + 0xc));
    FUN_008f5650(*(undefined **)(param_1 + 0x10));
    FUN_008f5650(*(undefined **)(param_1 + 0x14));
    FUN_008f5650(*(undefined **)(param_1 + 0x18));
    FUN_008f5650(*(undefined **)(param_1 + 0x1c));
    FUN_008f5650(*(undefined **)(param_1 + 0x20));
    FUN_008f5650(*(undefined **)(param_1 + 0x24));
  }
  return;
}



/* VA 008faf00 */

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



/* VA 008faf40 */

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



/* VA 008faf80 */

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



/* VA 008fafc0 */

BOOL __cdecl
FUN_008fafc0(DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int cbMultiByte;
  int *lpMultiByteStr;
  int iVar2;
  LPWORD lpCharType;
  BOOL local_4;

  lpCharType = (LPWORD)0x0;
  if (DAT_0090b77c == 0) {
    BVar1 = GetStringTypeW(1,L"",1,(LPWORD)&local_4);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeA(0,1,"",1,(LPWORD)&local_4);
      if (BVar1 == 0) {
        return 0;
      }
      DAT_0090b77c = 2;
    }
    else {
      DAT_0090b77c = 1;
    }
  }
  if (DAT_0090b77c != 1) {
    local_4 = DAT_0090b77c;
    if (DAT_0090b77c == 2) {
      local_4 = 0;
      if (param_5 == 0) {
        param_5 = DAT_0090b660;
      }
      cbMultiByte = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,
                                        (LPBOOL)0x0);
      if (cbMultiByte == 0) {
        return 0;
      }
      lpMultiByteStr = FUN_008f8f30(1,cbMultiByte);
      if (lpMultiByteStr == (int *)0x0) {
        return 0;
      }
      iVar2 = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)lpMultiByteStr,cbMultiByte,
                                  (LPCSTR)0x0,(LPBOOL)0x0);
      if ((iVar2 != 0) &&
         (lpCharType = (LPWORD)FUN_008f56c0(cbMultiByte * 2 + 2), lpCharType != (LPWORD)0x0)) {
        if (param_6 == 0) {
          param_6 = DAT_0090b650;
        }
        lpCharType[param_3] = 0xffff;
        lpCharType[param_3 + -1] = 0xffff;
        local_4 = GetStringTypeA(param_6,param_1,(LPCSTR)lpMultiByteStr,cbMultiByte,lpCharType);
        if ((lpCharType[param_3 + -1] == 0xffff) || (lpCharType[param_3] != 0xffff)) {
          local_4 = 0;
        }
        else {
          FUN_008fbfb0((undefined4 *)param_4,(undefined4 *)lpCharType,param_3 * 2);
        }
      }
      FUN_008f5650((undefined *)lpMultiByteStr);
      FUN_008f5650((undefined *)lpCharType);
    }
    return local_4;
  }
  BVar1 = GetStringTypeW(param_1,param_2,param_3,param_4);
  return BVar1;
}



/* VA 008fb150 */

BOOL __cdecl
FUN_008fb150(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int iVar2;
  LPCWSTR lpWideCharStr;
  WORD local_2;

  lpWideCharStr = (LPCWSTR)0x0;
  if (DAT_0090b780 == 0) {
    BVar1 = GetStringTypeA(0,1,"",1,&local_2);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeW(1,L"",1,&local_2);
      if (BVar1 == 0) {
        return 0;
      }
      DAT_0090b780 = 1;
    }
    else {
      DAT_0090b780 = 2;
    }
  }
  if (DAT_0090b780 == 2) {
    if (param_6 == 0) {
      param_6 = DAT_0090b650;
    }
    BVar1 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    return BVar1;
  }
  param_6 = DAT_0090b780;
  if (DAT_0090b780 == 1) {
    param_6 = 0;
    if (param_5 == 0) {
      param_5 = DAT_0090b660;
    }
    iVar2 = MultiByteToWideChar(param_5,9,param_2,param_3,(LPWSTR)0x0,0);
    if (iVar2 != 0) {
      lpWideCharStr = (LPCWSTR)FUN_008f8f30(2,iVar2);
      if (lpWideCharStr != (LPCWSTR)0x0) {
        iVar2 = MultiByteToWideChar(param_5,1,param_2,param_3,lpWideCharStr,iVar2);
        if (iVar2 != 0) {
          BVar1 = GetStringTypeW(param_1,lpWideCharStr,iVar2,param_4);
          FUN_008f5650((undefined *)lpWideCharStr);
          return BVar1;
        }
      }
    }
    FUN_008f5650((undefined *)lpWideCharStr);
  }
  return param_6;
}



/* VA 008fb280 */

int __cdecl FUN_008fb280(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;

  while( true ) {
    if (DAT_00909aac < 2) {
      uVar2 = (byte)PTR_DAT_009098a0[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar2 = FUN_008f8de0((uint)*param_1,8);
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
    if (DAT_00909aac < 2) {
      uVar3 = (byte)PTR_DAT_009098a0[uVar4 * 2] & 4;
    }
    else {
      uVar3 = FUN_008f8de0(uVar4,4);
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



/* VA 008fb320 */

uint __cdecl FUN_008fb320(LPSTR param_1,LPCWSTR param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;

  InterlockedIncrement((LONG *)&DAT_0090c9c8);
  bVar2 = DAT_0090c9c4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_0090c9c8);
    FUN_008f74b0(0x13);
  }
  uVar1 = FUN_008fb3a0(param_1,param_2,param_3);
  if (!bVar2) {
    InterlockedDecrement((LONG *)&DAT_0090c9c8);
    return uVar1;
  }
  FUN_008f7530(0x13);
  return uVar1;
}



/* VA 008fb3a0 */

uint __cdecl FUN_008fb3a0(LPSTR param_1,LPCWSTR param_2,uint param_3)

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
    if (DAT_0090b650 == 0) {
      uVar4 = FUN_008f9e20(param_2);
      return uVar4;
    }
    iVar3 = WideCharToMultiByte(DAT_0090b660,0x220,param_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,&local_4);
    if ((iVar3 != 0) && (local_4 == 0)) {
      return iVar3 - 1;
    }
  }
  else if (DAT_0090b650 == 0) {
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
  else if (DAT_00909aac == 1) {
    iVar3 = 0;
    if (param_3 != 0) {
      iVar3 = FUN_008fb590(param_2,param_3);
    }
    uVar4 = WideCharToMultiByte(DAT_0090b660,0x220,pWVar7,iVar3,param_1,iVar3,(LPCSTR)0x0,&local_4);
    if ((uVar4 != 0) && (local_4 == 0)) {
      if (param_1[uVar4 - 1] != '\0') {
        return uVar4;
      }
      return uVar4 - 1;
    }
  }
  else {
    iVar3 = WideCharToMultiByte(DAT_0090b660,0x220,param_2,-1,param_1,param_3,(LPCSTR)0x0,&local_4);
    if (iVar3 == 0) {
      if ((local_4 == 0) && (DVar5 = GetLastError(), DVar5 == 0x7a)) {
        uVar2 = 0;
        if (uVar4 != 0) {
          do {
            iVar3 = WideCharToMultiByte(DAT_0090b660,0,pWVar7,1,(LPSTR)&param_2,DAT_00909aac,
                                        (LPCSTR)0x0,&local_4);
            if ((iVar3 == 0) || (local_4 != 0)) goto LAB_008fb576;
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
LAB_008fb576:
  pDVar6 = FUN_008fb6e0();
  *pDVar6 = 0x2a;
  return 0xffffffff;
}



/* VA 008fb590 */

int __cdecl FUN_008fb590(short *param_1,int param_2)

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



/* VA 008fb5d0 */

int __cdecl FUN_008fb5d0(byte *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  LPWSTR pWVar4;
  byte *pbVar5;
  int *piVar6;
  byte *pbVar7;

  if (((DAT_0090b360 != (int *)0x0) ||
      (((DAT_0090b368 == 0 || (iVar2 = FUN_008fc370(), iVar2 == 0)) && (DAT_0090b360 != (int *)0x0))
      )) && (param_1 != (byte *)0x0)) {
    uVar3 = 0xffffffff;
    pbVar5 = (byte *)*DAT_0090b360;
    pbVar7 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + 1;
    } while (bVar1 != 0);
    pWVar4 = (LPWSTR)(~uVar3 - 1);
    piVar6 = DAT_0090b360;
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
           (iVar2 = FUN_008fc330(pbVar5,param_1,pWVar4), iVar2 == 0)) {
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



/* VA 008fb660 */

void __cdecl FUN_008fb660(undefined *param_1)

{
  DWORD *pDVar1;
  undefined **ppuVar2;
  int iVar3;

  pDVar1 = FUN_008fb6f0();
  iVar3 = 0;
  *pDVar1 = (DWORD)param_1;
  ppuVar2 = (undefined **)&DAT_0090a6f8;
  do {
    if (param_1 == *ppuVar2) {
      pDVar1 = FUN_008fb6e0();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x90a6fc);
      return;
    }
    ppuVar2 = ppuVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (ppuVar2 < &PTR_DAT_0090a860);
  if (((undefined *)0x12 < param_1) && (param_1 < (undefined *)0x25)) {
    pDVar1 = FUN_008fb6e0();
    *pDVar1 = 0xd;
    return;
  }
  if (((undefined *)0xbb < param_1) && (param_1 < (undefined *)0xcb)) {
    pDVar1 = FUN_008fb6e0();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_008fb6e0();
  *pDVar1 = 0x16;
  return;
}



/* VA 008fb6e0 */

DWORD * FUN_008fb6e0(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_008f6580();
  return pDVar1 + 2;
}



/* VA 008fb6f0 */

DWORD * FUN_008fb6f0(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_008f6580();
  return pDVar1 + 3;
}



/* VA 008fb7a0 */

undefined4 __cdecl FUN_008fb7a0(uint param_1)

{
  DWORD *pDVar1;

  if ((param_1 < DAT_0090cae0) &&
     ((*(byte *)((&DAT_0090c9e0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_0090c9e0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_008fb6e0();
  *pDVar1 = 9;
  pDVar1 = FUN_008fb6f0();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* VA 008fb7f0 */

void __cdecl FUN_008fb7f0(uint param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_0090c9e0)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_008f74b0(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_008f7530(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_0090c9e0)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}



/* VA 008fb860 */

void __cdecl FUN_008fb860(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_0090c9e0)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



/* VA 008fbab0 */

void FUN_008fbab0(void)

{
  __amsg_exit(2);
  return;
}



/* VA 008fbac0 */

undefined4 __cdecl FUN_008fbac0(int param_1,LCID param_2,LCTYPE param_3,char *param_4)

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
    iVar5 = FUN_008fbc70(param_2,param_3,(LPWSTR)&DAT_0090b790,4,0);
    if (iVar5 != 0) {
      pbVar6 = &DAT_0090b790;
      *param_4 = '\0';
      while( true ) {
        bVar1 = *pbVar6;
        if (DAT_00909aac < 2) {
          uVar3 = (byte)PTR_DAT_009098a0[(uint)bVar1 * 2] & 4;
        }
        else {
          uVar3 = FUN_008f8de0((uint)bVar1,4);
        }
        if (uVar3 == 0) break;
        pbVar6 = pbVar6 + 2;
        *param_4 = *param_4 * '\n' + bVar1 + -0x30;
        if (0x90b797 < (int)pbVar6) {
          return 0;
        }
      }
      return 0;
    }
    return 0xffffffff;
  }
  _Source = local_80;
  bVar2 = false;
  uVar3 = FUN_008fbda0(param_2,param_3,local_80,0x80,0);
  if (uVar3 == 0) {
    DVar4 = GetLastError();
    if (((DVar4 != 0x7a) || (uVar3 = FUN_008fbda0(param_2,param_3,(LPSTR)0x0,0,0), uVar3 == 0)) ||
       (_Source = (LPSTR)FUN_008f56c0(uVar3), _Source == (LPSTR)0x0)) goto LAB_008fbb70;
    bVar2 = true;
    uVar3 = FUN_008fbda0(param_2,param_3,_Source,uVar3,0);
    if (uVar3 == 0) goto LAB_008fbb70;
  }
  _Dest = (char *)FUN_008f56c0(uVar3);
  *(char **)param_4 = _Dest;
  if (_Dest != (char *)0x0) {
    _strncpy(_Dest,_Source,uVar3);
    if (!bVar2) {
      return 0;
    }
    FUN_008f5650(_Source);
    return 0;
  }
LAB_008fbb70:
  if (!bVar2) {
    return 0xffffffff;
  }
  FUN_008f5650(_Source);
  return 0xffffffff;
}



/* VA 008fbc70 */

int __cdecl FUN_008fbc70(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  uint cchData;
  LPSTR lpLCData;

  if (DAT_0090b79c == 0) {
    iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0090b79c = 2;
    }
    else {
      DAT_0090b79c = 1;
    }
  }
  if (DAT_0090b79c == 1) {
    iVar1 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (DAT_0090b79c != 2) {
    return DAT_0090b79c;
  }
  if (param_5 == 0) {
    param_5 = DAT_0090b660;
  }
  cchData = GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
  if (cchData != 0) {
    lpLCData = (LPSTR)FUN_008f56c0(cchData);
    if (lpLCData == (LPSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoA(param_1,param_2,lpLCData,cchData);
    if (iVar1 != 0) {
      if (param_4 == 0) {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,(LPWSTR)0x0,0);
        if (iVar1 != 0) {
          FUN_008f5650(lpLCData);
          return iVar1;
        }
      }
      else {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,param_3,param_4);
        if (iVar1 != 0) {
          FUN_008f5650(lpLCData);
          return iVar1;
        }
      }
    }
    FUN_008f5650(lpLCData);
    return 0;
  }
  return 0;
}



/* VA 008fbda0 */

int __cdecl FUN_008fbda0(LCID param_1,LCTYPE param_2,LPSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  LPWSTR lpLCData;

  if (DAT_0090b7a0 == 0) {
    iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0090b7a0 = 1;
    }
    else {
      DAT_0090b7a0 = 2;
    }
  }
  if (DAT_0090b7a0 == 2) {
    iVar1 = GetLocaleInfoA(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (DAT_0090b7a0 != 1) {
    return DAT_0090b7a0;
  }
  if (param_5 == 0) {
    param_5 = DAT_0090b660;
  }
  iVar1 = GetLocaleInfoW(param_1,param_2,(LPWSTR)0x0,0);
  if (iVar1 != 0) {
    lpLCData = (LPWSTR)FUN_008f56c0(iVar1 * 2);
    if (lpLCData == (LPWSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoW(param_1,param_2,lpLCData,iVar1);
    if (iVar1 != 0) {
      if (param_4 == 0) {
        iVar1 = WideCharToMultiByte(param_5,0x220,lpLCData,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar1 != 0) {
          FUN_008f5650((undefined *)lpLCData);
          return iVar1;
        }
      }
      else {
        iVar1 = WideCharToMultiByte(param_5,0x220,lpLCData,-1,param_3,param_4,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        if (iVar1 != 0) {
          FUN_008f5650((undefined *)lpLCData);
          return iVar1;
        }
      }
    }
    FUN_008f5650((undefined *)lpLCData);
    return 0;
  }
  return 0;
}



/* VA 008fbee0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_008fbee0(byte *param_1,byte *param_2)

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

  iVar2 = _DAT_0090c9c8;
  if (DAT_0090b650 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_008fbf2e;
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
LAB_008fbf2e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_0090c9c8 = _DAT_0090c9c8 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_0090c9c4;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_0090c9c8 = iVar2;
      FUN_008f74b0(0x13);
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_008fbf8f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_008f6080(uVar8);
      uVar7 = FUN_008f6080(uVar7);
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_008fbf8f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_0090c9c8 = _DAT_0090c9c8 + -1;
      UNLOCK();
    }
    else {
      FUN_008f7530(0x13);
    }
  }
  return uVar7;
}



/* VA 008fbfb0 */

undefined4 * __cdecl FUN_008fbfb0(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
          goto switchD_008fc167_caseD_2;
        case 3:
          goto switchD_008fc167_caseD_3;
        }
        goto switchD_008fc167_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_008fc167_caseD_0;
      case 1:
        goto switchD_008fc167_caseD_1;
      case 2:
        goto switchD_008fc167_caseD_2;
      case 3:
        goto switchD_008fc167_caseD_3;
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
              goto switchD_008fc167_caseD_2;
            case 3:
              goto switchD_008fc167_caseD_3;
            }
            goto switchD_008fc167_caseD_1;
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
              goto switchD_008fc167_caseD_2;
            case 3:
              goto switchD_008fc167_caseD_3;
            }
            goto switchD_008fc167_caseD_1;
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
              goto switchD_008fc167_caseD_2;
            case 3:
              goto switchD_008fc167_caseD_3;
            }
            goto switchD_008fc167_caseD_1;
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
switchD_008fc167_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_008fc167_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_008fc167_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_008fc167_caseD_0:
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
        goto switchD_008fbfe5_caseD_2;
      case 3:
        goto switchD_008fbfe5_caseD_3;
      }
      goto switchD_008fbfe5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_008fbfe5_caseD_0;
    case 1:
      goto switchD_008fbfe5_caseD_1;
    case 2:
      goto switchD_008fbfe5_caseD_2;
    case 3:
      goto switchD_008fbfe5_caseD_3;
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
            goto switchD_008fbfe5_caseD_2;
          case 3:
            goto switchD_008fbfe5_caseD_3;
          }
          goto switchD_008fbfe5_caseD_1;
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
            goto switchD_008fbfe5_caseD_2;
          case 3:
            goto switchD_008fbfe5_caseD_3;
          }
          goto switchD_008fbfe5_caseD_1;
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
            goto switchD_008fbfe5_caseD_2;
          case 3:
            goto switchD_008fbfe5_caseD_3;
          }
          goto switchD_008fbfe5_caseD_1;
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
switchD_008fbfe5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_008fbfe5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_008fbfe5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_008fbfe5_caseD_0:
  return param_1;
}



/* VA 008fc330 */

int __cdecl FUN_008fc330(byte *param_1,byte *param_2,LPWSTR param_3)

{
  int iVar1;

  if (param_3 == (LPWSTR)0x0) {
    return 0;
  }
  iVar1 = FUN_008fc540(DAT_0090b618,1,param_1,param_3,param_2,(int)param_3,DAT_0090b614);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}



/* VA 008fc370 */

undefined4 FUN_008fc370(void)

{
  LPCWSTR lpWideCharStr;
  uint cbMultiByte;
  uint *lpMultiByteStr;
  int iVar1;
  int *piVar2;

  lpWideCharStr = (LPCWSTR)*DAT_0090b368;
  piVar2 = DAT_0090b368;
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  while (((cbMultiByte = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                             (LPBOOL)0x0), cbMultiByte != 0 &&
          (lpMultiByteStr = (uint *)FUN_008f56c0(cbMultiByte), lpMultiByteStr != (uint *)0x0)) &&
         (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*piVar2,-1,(LPSTR)lpMultiByteStr,cbMultiByte,
                                      (LPCSTR)0x0,(LPBOOL)0x0), iVar1 != 0))) {
    FUN_008fc840(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)piVar2[1];
    piVar2 = piVar2 + 1;
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
  }
  return 0xffffffff;
}



/* VA 008fc540 */

int __cdecl
FUN_008fc540(LCID param_1,DWORD param_2,byte *param_3,LPWSTR param_4,byte *param_5,int param_6,
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

  if (DAT_0090b7a8 == 0) {
    iVar1 = CompareStringA(0,0,"",1,"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringW(0,0,L"",1,L"",1);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_0090b7a8 = 1;
    }
    else {
      DAT_0090b7a8 = 2;
    }
  }
  cbMultiByte = param_4;
  if (0 < (int)param_4) {
    cbMultiByte = (LPWSTR)FUN_008fc810((char *)param_3,(int)param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_008fc810((char *)param_5,param_6);
  }
  if (DAT_0090b7a8 == 2) {
    iVar1 = CompareStringA(param_1,param_2,(PCNZCH)param_3,(int)cbMultiByte,(PCNZCH)param_5,param_6)
    ;
    return iVar1;
  }
  local_18 = DAT_0090b7a8;
  if (DAT_0090b7a8 == 1) {
    local_18 = 0;
    param_4 = (LPWSTR)0x0;
    if (param_7 == 0) {
      param_7 = DAT_0090b660;
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
    lpWideCharStr = (PCNZWCH)FUN_008f56c0(iVar1 * 2);
    if (lpWideCharStr == (PCNZWCH)0x0) {
      return 0;
    }
    iVar4 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,(int)cbMultiByte,lpWideCharStr,iVar1);
    if ((((iVar4 != 0) &&
         (iVar4 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0), iVar4 != 0))
        && (param_4 = (LPWSTR)FUN_008f56c0(iVar4 * 2), param_4 != (LPWSTR)0x0)) &&
       (iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,param_4,iVar4), iVar5 != 0)) {
      local_18 = CompareStringW(param_1,param_2,lpWideCharStr,iVar1,param_4,iVar4);
    }
    FUN_008f5650((undefined *)lpWideCharStr);
    FUN_008f5650((undefined *)param_4);
  }
  return local_18;
}



/* VA 008fc810 */

int __cdecl FUN_008fc810(char *param_1,int param_2)

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



/* VA 008fc840 */

undefined4 __cdecl FUN_008fc840(uint *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  LPWSTR pWVar5;
  int *piVar6;
  LPCSTR lpName;
  uint uVar7;
  uint uVar8;
  CHAR *pCVar9;
  LPCSTR pCVar10;
  bool bVar11;

  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar3 = FUN_008fce30(param_1,0x3d);
  if (puVar3 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar3) {
    return 0xffffffff;
  }
  bVar11 = *(char *)((int)puVar3 + 1) == '\0';
  if (DAT_0090b360 == DAT_0090b364) {
    DAT_0090b360 = FUN_008fcad0(DAT_0090b360);
  }
  if (DAT_0090b360 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_0090b368 == (undefined4 *)0x0)) {
      if (bVar11) {
        return 0;
      }
      DAT_0090b360 = (int *)FUN_008f56c0(4);
      if (DAT_0090b360 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_0090b360 = 0;
      if (DAT_0090b368 == (undefined4 *)0x0) {
        DAT_0090b368 = (undefined4 *)FUN_008f56c0(4);
        if (DAT_0090b368 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_0090b368 = 0;
      }
    }
    else {
      iVar4 = FUN_008fc370();
      if (iVar4 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar6 = DAT_0090b360;
  pWVar5 = (LPWSTR)((int)puVar3 - (int)param_1);
  iVar4 = FUN_008fca50((byte *)param_1,pWVar5);
  if ((iVar4 < 0) || (*piVar6 == 0)) {
    if (bVar11) {
      return 0;
    }
    if (iVar4 < 0) {
      iVar4 = -iVar4;
    }
    piVar6 = FUN_008fcc80(piVar6,iVar4 * 4 + 8);
    if (piVar6 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar6[iVar4] = (int)param_1;
    piVar6[iVar4 + 1] = 0;
    DAT_0090b360 = piVar6;
  }
  else if (bVar11) {
    FUN_008f5650((undefined *)piVar6[iVar4]);
    iVar1 = piVar6[iVar4];
    piVar2 = piVar6 + iVar4;
    while (iVar1 != 0) {
      *piVar2 = piVar2[1];
      iVar4 = iVar4 + 1;
      iVar1 = piVar2[1];
      piVar2 = piVar2 + 1;
    }
    piVar6 = FUN_008fcc80(piVar6,iVar4 * 4);
    if (piVar6 != (int *)0x0) {
      DAT_0090b360 = piVar6;
    }
  }
  else {
    piVar6[iVar4] = (int)param_1;
  }
  if (param_2 != 0) {
    uVar7 = 0xffffffff;
    puVar3 = param_1;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      uVar8 = *puVar3;
      puVar3 = (uint *)((int)puVar3 + 1);
    } while ((char)uVar8 != '\0');
    lpName = (LPCSTR)FUN_008f56c0(~uVar7 + 1);
    if (lpName != (LPCSTR)0x0) {
      uVar7 = 0xffffffff;
      do {
        puVar3 = param_1;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        puVar3 = (uint *)((int)param_1 + 1);
        uVar8 = *param_1;
        param_1 = puVar3;
      } while ((char)uVar8 != '\0');
      uVar7 = ~uVar7;
      pCVar9 = (CHAR *)((int)puVar3 - uVar7);
      pCVar10 = lpName;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pCVar10 = *(undefined4 *)pCVar9;
        pCVar9 = pCVar9 + 4;
        pCVar10 = pCVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pCVar10 = *pCVar9;
        pCVar9 = pCVar9 + 1;
        pCVar10 = pCVar10 + 1;
      }
      lpName[(int)pWVar5] = '\0';
      SetEnvironmentVariableA(lpName,(LPCSTR)(~-(uint)bVar11 & (uint)(lpName + 1 + (int)pWVar5)));
      FUN_008f5650(lpName);
      return 0;
    }
  }
  return 0;
}



/* VA 008fca50 */

int __cdecl FUN_008fca50(byte *param_1,LPWSTR param_2)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;

  pbVar1 = (byte *)*DAT_0090b360;
  piVar3 = DAT_0090b360;
  if (pbVar1 == (byte *)0x0) {
    return 0;
  }
  while ((iVar2 = FUN_008fc330(param_1,pbVar1,param_2), iVar2 != 0 ||
         ((*(char *)(*piVar3 + (int)param_2) != '=' && (*(char *)(*piVar3 + (int)param_2) != '\0')))
         )) {
    pbVar1 = (byte *)piVar3[1];
    piVar3 = piVar3 + 1;
    if (pbVar1 == (byte *)0x0) {
      return -((int)piVar3 - (int)DAT_0090b360 >> 2);
    }
  }
  return (int)piVar3 - (int)DAT_0090b360 >> 2;
}



/* VA 008fcad0 */

undefined4 * __cdecl FUN_008fcad0(int *param_1)

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
    puVar3 = (undefined4 *)FUN_008f56c0(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    pcVar4 = (char *)*param_1;
    puVar6 = puVar3;
    while (pcVar4 != (char *)0x0) {
      param_1 = param_1 + 1;
      pcVar4 = FUN_008fcf00(pcVar4);
      *puVar6 = pcVar4;
      puVar6 = puVar6 + 1;
      pcVar4 = (char *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}



/* VA 008fcc80 */

int * __cdecl FUN_008fcc80(int *param_1,uint param_2)

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
    piVar1 = (int *)FUN_008f56c0(param_2);
    return piVar1;
  }
  if (param_2 == 0) {
    FUN_008f5650((undefined *)param_1);
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
      FUN_008f74b0(9);
      pbVar2 = (byte *)FUN_008f78d0((undefined *)param_1,&local_4,(uint *)&local_8);
      if (pbVar2 == (byte *)0x0) {
        FUN_008f7530(9);
        piVar1 = HeapReAlloc(DAT_0090cae4,0,param_1,uVar4);
      }
      else {
        if (uVar4 < DAT_00909584) {
          iVar3 = FUN_008f7d50(local_4,local_8,pbVar2,uVar4 >> 4);
          piVar1 = param_1;
          if (iVar3 != 0) goto LAB_008fcd85;
          piVar1 = FUN_008f7990(uVar4 >> 4);
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
            FUN_008f7930(local_4,(int)local_8,pbVar2);
            uVar4 = param_2;
            goto LAB_008fcd85;
          }
LAB_008fcd89:
          piVar1 = HeapAlloc(DAT_0090cae4,0,uVar4);
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
            FUN_008f7930(local_4,(int)local_8,pbVar2);
            uVar4 = param_2;
          }
        }
        else {
LAB_008fcd85:
          if (piVar1 == (int *)0x0) goto LAB_008fcd89;
        }
        FUN_008f7530(9);
      }
    }
    if ((piVar1 != (int *)0x0) || (DAT_0090b3fc == 0)) {
      return piVar1;
    }
    iVar3 = FUN_008f7e20(uVar4);
    if (iVar3 == 0) {
      return (int *)0x0;
    }
  } while( true );
}



/* VA 008fce30 */

uint * __cdecl FUN_008fce30(uint *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;

  if (DAT_0090b614 == 0) {
    puVar3 = FUN_008f8b00(param_1,(char)param_2);
    return puVar3;
  }
  FUN_008f74b0(0x19);
  bVar1 = (byte)*param_1;
  while (uVar2 = (uint)bVar1, bVar1 != 0) {
    if ((*(byte *)((int)&DAT_0090b510 + uVar2 + 1) & 4) == 0) {
      puVar3 = param_1;
      if (param_2 == uVar2) break;
    }
    else {
      puVar3 = (uint *)((int)param_1 + 1);
      if (*(char *)((int)param_1 + 1) == '\0') {
        FUN_008f7530(0x19);
        return (uint *)0x0;
      }
      if (param_2 == CONCAT11(bVar1,*(char *)((int)param_1 + 1))) {
        FUN_008f7530(0x19);
        return param_1;
      }
    }
    param_1 = (uint *)((int)puVar3 + 1);
    bVar1 = *(byte *)((int)puVar3 + 1);
  }
  FUN_008f7530(0x19);
  return (uint *)((param_2 != uVar2) - 1 & (uint)param_1);
}



/* VA 008fcf00 */

char * __cdecl FUN_008fcf00(char *param_1)

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
    pcVar2 = (char *)FUN_008f56c0(~uVar3);
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



/* VA 008fcf50 */

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x008fcf50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}



/* VA 008fe000 */

/* WARNING: Instruction at (ram,0x008fe09a) overlaps instruction at (ram,0x008fe099)
    */
/* WARNING: Removing unreachable block (ram,0x008fe082) */
/* WARNING: Removing unreachable block (ram,0x008fe027) */
/* WARNING: Removing unreachable block (ram,0x008fe05c) */
/* WARNING: Removing unreachable block (ram,0x008fe094) */
/* WARNING: Removing unreachable block (ram,0x008fe0a8) */
/* WARNING: Removing unreachable block (ram,0x008fe0aa) */
/* WARNING: Removing unreachable block (ram,0x008fe0ae) */
/* WARNING: Removing unreachable block (ram,0x008fe0b9) */

uint __cdecl FUN_008fe000(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;

  uVar3 = *param_1;
  uVar2 = param_1[1];
  uVar1 = DAT_00906000 << 5;
  for (iVar4 = DAT_00906004; iVar4 != 0; iVar4 = iVar4 + -1) {
    uVar2 = uVar2 - ((uVar3 >> 5) + param_2[3] ^ uVar3 * 0x10 + param_2[2] ^ uVar1 + uVar3);
    uVar3 = uVar3 - ((uVar2 >> 5) + param_2[1] ^ uVar1 + uVar2 ^ uVar2 * 0x10 + *param_2);
    uVar1 = uVar1 - DAT_00906000;
  }
  *param_1 = uVar3;
  param_1[1] = uVar2;
  return uVar1;
}



/* VA 008fe130 */

uint __cdecl
FUN_008fe130(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 *param_4,uint *param_5,
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

  FUN_008fe890(param_1,local_40,&local_138);
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
    uVar1 = FUN_008fe940(param_1,0x20000020,0x20000020,uVar1,uVar2,local_160);
LAB_008fe32e:
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_008feae0((int)local_160);
      *param_5 = uVar2;
      return uVar1;
    }
    break;
  case 2:
    while (uVar1 = FUN_008fe940(param_1,0xc0000040,0xc0000040,uVar1,uVar2,local_160), uVar1 != 0) {
      uVar3 = FUN_008fe700(local_154,param_1);
      if ((char)uVar3 == '\0') {
        if (uVar1 == 0) {
          return 0;
        }
        *param_4 = local_14c;
        *param_6 = local_154;
        uVar2 = FUN_008feae0((int)local_160);
        *param_5 = uVar2;
        return uVar1;
      }
      uVar1 = uVar1 + 0x28;
    }
    break;
  case 3:
    uVar1 = FUN_008fe9a0(param_1,&DAT_00907220,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_008feae0((int)local_160);
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
    uVar1 = FUN_008fe8e0(param_1,local_b0,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      *param_5 = local_ac;
      return uVar1;
    }
    break;
  case 6:
    uVar1 = FUN_008fe8e0(param_1,local_b8,uVar1,uVar2,local_160);
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
    uVar1 = FUN_008fe8e0(param_1,local_c0,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_008feae0((int)local_160);
      *param_5 = uVar2;
      *param_7 = local_c0;
      return uVar1;
    }
    break;
  case 8:
    uVar1 = FUN_008fe8e0(param_1,local_98,uVar1,uVar2,local_160);
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
    uVar1 = FUN_008fe8e0(param_1,local_78,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_008feae0((int)local_160);
      *param_5 = uVar2;
      *param_7 = local_78;
      return uVar1;
    }
    break;
  case 10:
    while( true ) {
      uVar1 = FUN_008fe940(param_1,0x40000040,0xc0000060,uVar1,uVar2,local_160);
      if (uVar1 == 0) break;
      uVar3 = FUN_008fe700(local_154,param_1);
      if ((char)uVar3 == '\0') goto LAB_008fe32e;
      uVar1 = uVar1 + 0x28;
    }
    break;
  case 0xb:
    uVar1 = FUN_008fe8e0(param_1,local_60,uVar1,uVar2,local_160);
    if (uVar1 != 0) {
      *param_4 = local_14c;
      *param_6 = local_154;
      uVar2 = FUN_008feae0((int)local_160);
      *param_5 = uVar2;
      *param_7 = local_60;
      return uVar1;
    }
  }
  return 0;
}



/* VA 008fe6c0 */

void __cdecl FUN_008fe6c0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_138 [16];
  int local_f8 [30];
  undefined4 local_80 [32];

  FUN_008fe890(param_1,local_138,local_f8);
  puVar2 = local_80;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



/* VA 008fe700 */

uint __cdecl FUN_008fe700(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int local_80 [32];

  FUN_008fe6c0(param_2,local_80);
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



/* VA 008fe750 */

void __cdecl
FUN_008fe750(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 *param_4,uint *param_5,
            uint *param_6)

{
  FUN_008fe130(param_1,param_2,param_3,param_4,param_5,param_6,(uint *)&param_6);
  return;
}



/* VA 008fe780 */

void __cdecl
FUN_008fe780(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,uint *param_4,uint *param_5)

{
  FUN_008fe750(param_1,param_2,0,param_3,param_4,param_5);
  return;
}



/* VA 008fe870 */

void __cdecl FUN_008fe870(undefined4 *param_1,int *param_2)

{
  undefined4 local_40 [16];

  FUN_008fe890(param_1,local_40,param_2);
  return;
}



/* VA 008fe890 */

bool __cdecl FUN_008fe890(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  FUN_008f2690(param_1,0,(undefined4 *)0x40,param_2);
  FUN_008f2690(param_1,param_2[0xf],(undefined4 *)0xf8,param_3);
  return *param_3 == 0x4550;
}



/* VA 008fe8e0 */

uint __cdecl
FUN_008fe8e0(undefined4 *param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  int iVar1;

  if (param_4 <= param_3) {
    return 0;
  }
  while( true ) {
    FUN_008f2690(param_1,param_3,(undefined4 *)0x28,param_5);
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



/* VA 008fe940 */

uint __cdecl
FUN_008fe940(undefined4 *param_1,uint param_2,uint param_3,uint param_4,uint param_5,
            undefined4 *param_6)

{
  if (param_5 <= param_4) {
    return 0;
  }
  do {
    FUN_008f2690(param_1,param_4,(undefined4 *)0x28,param_6);
    if ((param_3 & param_6[9]) == param_2) {
      return param_4;
    }
    param_4 = param_4 + 0x28;
  } while (param_4 < param_5);
  return 0;
}



/* VA 008fe9a0 */

uint __cdecl
FUN_008fe9a0(undefined4 *param_1,byte *param_2,uint param_3,uint param_4,undefined4 *param_5)

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
    FUN_008f2690(param_1,param_3,(undefined4 *)0x28,param_5);
    local_c = *param_5;
    local_8 = param_5[1];
    local_4 = 0;
    pbVar2 = (byte *)&local_c;
    pbVar4 = param_2;
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_008fea15:
        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_008fea1a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_008fea15;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_008fea1a:
    if (iVar3 == 0) {
      return param_3;
    }
    param_3 = param_3 + 0x28;
    if (param_4 <= param_3) {
      return 0;
    }
  } while( true );
}



/* VA 008fea50 */

bool __cdecl FUN_008fea50(undefined4 *param_1,int param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;

  FUN_008f2690(param_1,param_2,(undefined4 *)0x28,&local_28);
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



/* VA 008feae0 */

uint __cdecl FUN_008feae0(int param_1)

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



/* VA 008feb00 */

/* WARNING: Instruction at (ram,0x008feb49) overlaps instruction at (ram,0x008feb48)
    */
/* WARNING: Removing unreachable block (ram,0x008feb57) */
/* WARNING: Removing unreachable block (ram,0x008feb5b) */
/* WARNING: Removing unreachable block (ram,0x008feb43) */
/* WARNING: Removing unreachable block (ram,0x008feb67) */

void __cdecl FUN_008feb00(char *param_1)

{
  LPCSTR lpLibFileName;

  if ((param_1 != (char *)0x0) &&
     (lpLibFileName = FUN_00901500(param_1), lpLibFileName != (LPCSTR)0x0)) {
    LoadLibraryA(lpLibFileName);
    FUN_008f5650(lpLibFileName);
  }
  return;
}



/* VA 008feb72 */

/* WARNING: Removing unreachable block (ram,0x008febb5) */
/* WARNING: Removing unreachable block (ram,0x008febcd) */
/* WARNING: Removing unreachable block (ram,0x008febd9) */

void __cdecl FUN_008feb72(char *param_1)

{
  LPCSTR lpModuleName;

  if ((param_1 != (char *)0x0) &&
     (lpModuleName = FUN_00901500(param_1), lpModuleName != (LPCSTR)0x0)) {
    GetModuleHandleA(lpModuleName);
    FUN_008f5650(lpModuleName);
  }
  return;
}



/* VA 008febe4 */

/* WARNING: Instruction at (ram,0x008fec53) overlaps instruction at (ram,0x008fec52)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008fec14) */
/* WARNING: Removing unreachable block (ram,0x008fec37) */
/* WARNING: Removing unreachable block (ram,0x008fec10) */
/* WARNING: Removing unreachable block (ram,0x008fec4b) */
/* WARNING: Removing unreachable block (ram,0x008fec4f) */
/* WARNING: Removing unreachable block (ram,0x008fec5b) */

void __cdecl FUN_008febe4(HMODULE param_1,char *param_2)

{
  LPCSTR lpProcName;

  if ((param_1 != (HMODULE)0x0) && (lpProcName = FUN_00901500(param_2), lpProcName != (LPCSTR)0x0))
  {
    GetProcAddress(param_1,lpProcName);
    FUN_008f5650(lpProcName);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  return;
}



/* VA 008fec66 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008feca5) */
/* WARNING: Removing unreachable block (ram,0x008feca1) */
/* WARNING: Removing unreachable block (ram,0x008fecc6) */
/* WARNING: Removing unreachable block (ram,0x008fecca) */

undefined4 __cdecl FUN_008fec66(char *param_1,char *param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 local_c;
  undefined4 local_8;

  local_8 = 0;
  local_c = (HMODULE)FUN_008feb72(param_1);
  if (local_c == (HMODULE)0x0) {
    local_c = (HMODULE)FUN_008feb00(param_1);
  }
  bVar2 = local_c != (HMODULE)0x0;
  bVar1 = (POPCOUNT((uint)local_c & 0xff) & 1U) == 0;
  if (bVar2) {
    local_8 = FUN_008febe4(local_c,param_2);
  }
  if ((!bVar2 && !bVar1) && (bVar2 || bVar1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return local_8;
}



/* VA 008fece1 */

bool FUN_008fece1(void)

{
  HMODULE pHVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool local_c;

  pHVar1 = (HMODULE)FUN_008feb00(&DAT_00907278);
  if (pHVar1 == (HMODULE)0x0) {
    local_c = false;
  }
  else {
    DAT_0090b0e8 = FUN_008febe4(pHVar1,&DAT_00907288);
    bVar2 = DAT_0090b0e8 != 0;
    DAT_0090b0ec = FUN_008febe4(pHVar1,&DAT_009072a0);
    bVar3 = DAT_0090b0ec != 0;
    DAT_0090b0f0 = FUN_008febe4(pHVar1,&DAT_009072b8);
    bVar4 = DAT_0090b0f0 != 0;
    DAT_0090b0f4 = FUN_008febe4(pHVar1,&DAT_009072c8);
    bVar5 = DAT_0090b0f4 != 0;
    DAT_0090b0f8 = FUN_008febe4(pHVar1,&DAT_009072d8);
    bVar6 = DAT_0090b0f8 != 0;
    DAT_0090b0fc = FUN_008febe4(pHVar1,&DAT_009072e8);
    bVar7 = DAT_0090b0fc != 0;
    DAT_0090b100 = FUN_008febe4(pHVar1,&DAT_009072f8);
    bVar8 = DAT_0090b100 != 0;
    DAT_0090b104 = FUN_008febe4(pHVar1,&DAT_00907308);
    bVar9 = DAT_0090b104 != 0;
    DAT_0090b108 = FUN_008febe4(pHVar1,&DAT_00907318);
    bVar10 = DAT_0090b108 != 0;
    DAT_0090b10c = FUN_008febe4(pHVar1,&DAT_00907330);
    local_c = DAT_0090b10c != 0 &&
              (bVar10 &&
              (bVar9 && (bVar8 && (bVar7 && (bVar6 && (bVar5 && (bVar4 && (bVar3 && bVar2))))))));
  }
  return local_c;
}



/* VA 008fee89 */

bool __cdecl FUN_008fee89(int *param_1)

{
  int iVar1;
  bool bVar2;

  iVar1 = FUN_008feb00(&DAT_00907338);
  *param_1 = iVar1;
  if (*param_1 == 0) {
    bVar2 = false;
  }
  else {
    DAT_0090b114 = FUN_008febe4((HMODULE)*param_1,&DAT_00907348);
    bVar2 = DAT_0090b114 != 0;
    DAT_0090b110 = FUN_008febe4((HMODULE)*param_1,&DAT_00907360);
    bVar2 = DAT_0090b110 != 0 && bVar2;
  }
  return bVar2;
}



/* VA 008fef0b */

bool FUN_008fef0b(void)

{
  bool bVar1;

  bVar1 = FUN_008fece1();
  return bVar1;
}



/* VA 008fef20 */

/* WARNING: Instruction at (ram,0x008ff058) overlaps instruction at (ram,0x008ff056)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008ff052) */
/* WARNING: Removing unreachable block (ram,0x008fefea) */
/* WARNING: Removing unreachable block (ram,0x008fef95) */
/* WARNING: Removing unreachable block (ram,0x008fef89) */
/* WARNING: Removing unreachable block (ram,0x008fef40) */
/* WARNING: Removing unreachable block (ram,0x008fef34) */
/* WARNING: Removing unreachable block (ram,0x008fef7d) */
/* WARNING: Removing unreachable block (ram,0x008fefde) */
/* WARNING: Removing unreachable block (ram,0x008feff6) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000018 : 0x008ff006 */
/* WARNING: Removing unreachable block (ram,0x008fefa1) */
/* WARNING: Removing unreachable block (ram,0x008fef4c) */
/* WARNING: Removing unreachable block (ram,0x008ff002) */
/* WARNING: Removing unreachable block (ram,0x008fef58) */
/* WARNING: Removing unreachable block (ram,0x008fef5e) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_008fef20(void)

{
  uint uVar1;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;

  local_18 = in_stack_00000018 + -1 + in_stack_00000014;
  local_8 = local_18;
  while( true ) {
    if (local_8 <= local_10) {
      return local_18;
    }
    local_18 = local_8;
    uVar1 = FUN_008f2140(&stack0x00000004,&local_10,&local_18,3,1);
    if ((uVar1 & 0xffff) == 0) break;
    local_14 = local_10 - in_stack_00000018;
                    /* WARNING: Bad instruction - Truncating control flow here */
    local_c = (local_18 - local_10) + 1;
    while (local_c != 0) {
      *(undefined1 *)(in_stack_00000010 + local_14) = (undefined1)local_14;
      local_14 = local_14 + 1;
      local_c = local_c + -1;
    }
    local_10 = local_18 + 1;
    local_18 = 0xffffffff;
    local_c = 0xffffffff;
  }
  return 0;
}



/* VA 008ff065 */

/* WARNING: Instruction at (ram,0x008ff383) overlaps instruction at (ram,0x008ff382)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008ff33c) */
/* WARNING: Removing unreachable block (ram,0x008ff348) */
/* WARNING: Removing unreachable block (ram,0x008ff23d) */
/* WARNING: Removing unreachable block (ram,0x008ff255) */
/* WARNING: Removing unreachable block (ram,0x008ff35d) */
/* WARNING: Removing unreachable block (ram,0x008ff279) */
/* WARNING: Removing unreachable block (ram,0x008ff1f5) */
/* WARNING: Removing unreachable block (ram,0x008ff13b) */
/* WARNING: Removing unreachable block (ram,0x008ff153) */
/* WARNING: Removing unreachable block (ram,0x008ff0ff) */
/* WARNING: Removing unreachable block (ram,0x008ff098) */
/* WARNING: Removing unreachable block (ram,0x008ff080) */
/* WARNING: Removing unreachable block (ram,0x008ff08c) */
/* WARNING: Removing unreachable block (ram,0x008ff0a4) */
/* WARNING: Removing unreachable block (ram,0x008ff0db) */
/* WARNING: Removing unreachable block (ram,0x008ff12f) */
/* WARNING: Removing unreachable block (ram,0x008ff0f3) */
/* WARNING: Removing unreachable block (ram,0x008ff19a) */
/* WARNING: Removing unreachable block (ram,0x008ff231) */
/* WARNING: Removing unreachable block (ram,0x008ff2d1) */
/* WARNING: Removing unreachable block (ram,0x008ff201) */
/* WARNING: Removing unreachable block (ram,0x008ff2f5) */
/* WARNING: Removing unreachable block (ram,0x008ff375) */
/* WARNING: Removing unreachable block (ram,0x008ff285) */
/* WARNING: Removing unreachable block (ram,0x008ff20d) */
/* WARNING: Removing unreachable block (ram,0x008ff10b) */
/* WARNING: Removing unreachable block (ram,0x008ff1a6) */
/* WARNING: Removing unreachable block (ram,0x008ff249) */
/* WARNING: Removing unreachable block (ram,0x008ff219) */
/* WARNING: Removing unreachable block (ram,0x008ff2dd) */
/* WARNING: Removing unreachable block (ram,0x008ff1b2) */
/* WARNING: Removing unreachable block (ram,0x008ff0e7) */
/* WARNING: Removing unreachable block (ram,0x008ff147) */
/* WARNING: Removing unreachable block (ram,0x008ff261) */
/* WARNING: Removing unreachable block (ram,0x008ff26d) */
/* WARNING: Removing unreachable block (ram,0x008ff29d) */
/* WARNING: Removing unreachable block (ram,0x008ff1be) */
/* WARNING: Removing unreachable block (ram,0x008ff291) */
/* WARNING: Removing unreachable block (ram,0x008ff117) */
/* WARNING: Removing unreachable block (ram,0x008ff15f) */
/* WARNING: Removing unreachable block (ram,0x008ff2e9) */
/* WARNING: Removing unreachable block (ram,0x008ff123) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffec : 0x008ff1cb */
/* WARNING: Removing unreachable block (ram,0x008ff225) */
/* WARNING: Removing unreachable block (ram,0x008ff369) */
/* WARNING: Removing unreachable block (ram,0x008ff381) */
/* WARNING: Removing unreachable block (ram,0x008ff2a9) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __fastcall FUN_008ff065(undefined4 param_1,undefined2 param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  byte *in_stack_00000010;
  byte *in_stack_00000014;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_14 = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  while ((local_14 = FUN_008fe750((undefined4 *)&stack0x00000004,1,local_14,&local_10,&local_18,
                                  &local_20), local_14 != 0 &&
         (bVar1 = FUN_008fea50((undefined4 *)&stack0x00000004,local_14,in_stack_00000014),
         CONCAT31(extraout_var,bVar1) == 0))) {
    local_14 = local_14 + 0x28;
  }
  local_14 = 0;
  while (local_14 = FUN_008fe750((undefined4 *)&stack0x00000004,1,local_14,&local_c,&local_1c,
                                 &local_8), local_14 != 0) {
    bVar1 = FUN_008fea50((undefined4 *)&stack0x00000004,local_14,in_stack_00000010);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      FUN_008ff38e();
    }
    local_14 = local_14 + 0x28;
  }
  return;
}



/* VA 008ff38e */

/* WARNING: Instruction at (ram,0x008ff893) overlaps instruction at (ram,0x008ff892)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x008ff6e1) */
/* WARNING: Removing unreachable block (ram,0x008ff78b) */
/* WARNING: Removing unreachable block (ram,0x008ff78f) */
/* WARNING: Removing unreachable block (ram,0x008ff860) */
/* WARNING: Removing unreachable block (ram,0x008ff864) */
/* WARNING: Removing unreachable block (ram,0x008ff576) */
/* WARNING: Removing unreachable block (ram,0x008ff478) */
/* WARNING: Removing unreachable block (ram,0x008ff47c) */
/* WARNING: Removing unreachable block (ram,0x008ff6a8) */
/* WARNING: Removing unreachable block (ram,0x008ff58e) */
/* WARNING: Removing unreachable block (ram,0x008ff582) */
/* WARNING: Removing unreachable block (ram,0x008ff6b4) */
/* WARNING: Removing unreachable block (ram,0x008ff645) */
/* WARNING: Removing unreachable block (ram,0x008ff7ce) */
/* WARNING: Removing unreachable block (ram,0x008ff510) */
/* WARNING: Removing unreachable block (ram,0x008ff7c2) */
/* WARNING: Removing unreachable block (ram,0x008ff5f1) */
/* WARNING: Removing unreachable block (ram,0x008ff490) */
/* WARNING: Removing unreachable block (ram,0x008ff494) */
/* WARNING: Removing unreachable block (ram,0x008ff7fe) */
/* WARNING: Removing unreachable block (ram,0x008ff771) */
/* WARNING: Removing unreachable block (ram,0x008ff651) */
/* WARNING: Removing unreachable block (ram,0x008ff5d9) */
/* WARNING: Removing unreachable block (ram,0x008ff484) */
/* WARNING: Removing unreachable block (ram,0x008ff488) */
/* WARNING: Removing unreachable block (ram,0x008ff438) */
/* WARNING: Removing unreachable block (ram,0x008ff3f4) */
/* WARNING: Removing unreachable block (ram,0x008ff3e8) */
/* WARNING: Removing unreachable block (ram,0x008ff450) */
/* WARNING: Removing unreachable block (ram,0x008ff504) */
/* WARNING: Removing unreachable block (ram,0x008ff639) */
/* WARNING: Removing unreachable block (ram,0x008ff7a0) */
/* WARNING: Removing unreachable block (ram,0x008ff7a4) */
/* WARNING: Removing unreachable block (ram,0x008ff822) */
/* WARNING: Removing unreachable block (ram,0x008ff51c) */
/* WARNING: Removing unreachable block (ram,0x008ff6ed) */
/* WARNING: Removing unreachable block (ram,0x008ff5e5) */
/* WARNING: Removing unreachable block (ram,0x008ff891) */
/* WARNING: Removing unreachable block (ram,0x008ff753) */
/* WARNING: Removing unreachable block (ram,0x008ff723) */
/* WARNING: Removing unreachable block (ram,0x008ff705) */
/* WARNING: Removing unreachable block (ram,0x008ff45c) */
/* WARNING: Removing unreachable block (ram,0x008ff621) */
/* WARNING: Removing unreachable block (ram,0x008ff615) */
/* WARNING: Removing unreachable block (ram,0x008ff7e6) */
/* WARNING: Removing unreachable block (ram,0x008ff609) */
/* WARNING: Removing unreachable block (ram,0x008ff400) */
/* WARNING: Removing unreachable block (ram,0x008ff5fd) */
/* WARNING: Removing unreachable block (ram,0x008ff6f9) */
/* WARNING: Removing unreachable block (ram,0x008ff83a) */
/* WARNING: Removing unreachable block (ram,0x008ff7f2) */
/* WARNING: Removing unreachable block (ram,0x008ff444) */
/* WARNING: Removing unreachable block (ram,0x008ff7da) */
/* WARNING: Removing unreachable block (ram,0x008ff816) */
/* WARNING: Removing unreachable block (ram,0x008ff62d) */
/* WARNING: Removing unreachable block (ram,0x008ff80a) */
/* WARNING: Removing unreachable block (ram,0x008ff65d) */
/* WARNING: Removing unreachable block (ram,0x008ff528) */
/* WARNING: Removing unreachable block (ram,0x008ff82e) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000014 : 0x008ff77b */
/* WARNING: Removing unreachable block (ram,0x008ff846) */
/* WARNING: Removing unreachable block (ram,0x008ff875) */
/* WARNING: Removing unreachable block (ram,0x008ff879) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_008ff38e(void)

{
  undefined1 in_PF;
  undefined4 in_stack_00000004;
  void *in_stack_00000008;
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
  undefined4 local_1008 [1014];
  undefined *puStackY_30;
  undefined *puStackY_2c;
  void *pvStackY_28;
  void *pvStackY_24;

  FUN_008f5470();
  if ((!(bool)in_PF) && ((bool)in_PF)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  _memset(local_1008,0,0x1000);
  _memset(local_201c,0,0x1000);
                    /* WARNING: Could not recover jumptable at 0x008ff462. Too many branches */
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
    pvStackY_24 = (void *)0x8ff547;
    FUN_008f2690(&stack0x00000004,local_100c,local_2028,local_1008);
    pvStackY_24 = (void *)0x8ff568;
    FUN_008f2690(&stack0x00000004,local_1014,local_101c,local_201c);
    if ((in_stack_00000028 & 0xffff) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      pvStackY_28 = (void *)in_stack_00000004;
      pvStackY_24 = in_stack_00000008;
      puStackY_2c = &UNK_008ff5cb;
      FUN_008fef20();
    }
    puStackY_2c = (undefined *)in_stack_00000004;
    pvStackY_28 = in_stack_00000008;
    puStackY_30 = &UNK_008ff69a;
    FUN_008ff89e(in_stack_00000008);
                    /* WARNING: Bad instruction - Truncating control flow here */
    func_0x008f2870();
    local_2024 = (undefined4 *)((int)local_2024 - (int)local_1018);
                    /* WARNING: Could not recover jumptable at 0x008ff729. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    local_1010 = (undefined4 *)((int)local_1010 - (int)local_101c);
    local_100c = local_100c + (int)local_1018;
    local_1014 = local_1014 + (int)local_101c;
                    /* WARNING: Bad instruction - Truncating control flow here */
    if (local_2024 == (undefined4 *)0x0) {
      local_2024 = in_stack_00000014;
      local_100c = in_stack_00000018;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* WARNING: Bad instruction - Truncating control flow here */
      local_2020 = 1;
    }
    if (local_1010 == (undefined4 *)0x0) {
      local_1010 = in_stack_00000020;
      local_1014 = in_stack_00000024;
                    /* WARNING: Bad instruction - Truncating control flow here */
    }
  }
  return;
}



/* VA 008ff89e */

/* WARNING: Instruction at (ram,0x008ffd65) overlaps instruction at (ram,0x008ffd64)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x008ffcb7) */
/* WARNING: Removing unreachable block (ram,0x008fff7d) */
/* WARNING: Removing unreachable block (ram,0x008fff65) */
/* WARNING: Removing unreachable block (ram,0x008fff4d) */
/* WARNING: Removing unreachable block (ram,0x008ffed0) */
/* WARNING: Removing unreachable block (ram,0x008ffeb8) */
/* WARNING: Removing unreachable block (ram,0x008ffeac) */
/* WARNING: Removing unreachable block (ram,0x008ffe94) */
/* WARNING: Removing unreachable block (ram,0x008ffe4c) */
/* WARNING: Removing unreachable block (ram,0x008ffe34) */
/* WARNING: Removing unreachable block (ram,0x008ffe1c) */
/* WARNING: Removing unreachable block (ram,0x008ffe04) */
/* WARNING: Removing unreachable block (ram,0x008ffdf8) */
/* WARNING: Removing unreachable block (ram,0x008ffde0) */
/* WARNING: Removing unreachable block (ram,0x008ffdc8) */
/* WARNING: Removing unreachable block (ram,0x008ffd8c) */
/* WARNING: Removing unreachable block (ram,0x008ffd74) */
/* WARNING: Removing unreachable block (ram,0x008ffae5) */
/* WARNING: Removing unreachable block (ram,0x008ffb7b) */
/* WARNING: Removing unreachable block (ram,0x008ffcdc) */
/* WARNING: Removing unreachable block (ram,0x008ffac1) */
/* WARNING: Removing unreachable block (ram,0x008ffc54) */
/* WARNING: Removing unreachable block (ram,0x008ffb2d) */
/* WARNING: Removing unreachable block (ram,0x008ffa64) */
/* WARNING: Removing unreachable block (ram,0x008ffd00) */
/* WARNING: Removing unreachable block (ram,0x008ffc30) */
/* WARNING: Removing unreachable block (ram,0x008ffb87) */
/* WARNING: Removing unreachable block (ram,0x008ffaf1) */
/* WARNING: Removing unreachable block (ram,0x008ffa91) */
/* WARNING: Removing unreachable block (ram,0x008ffa4c) */
/* WARNING: Removing unreachable block (ram,0x008ff9f7) */
/* WARNING: Removing unreachable block (ram,0x008ff9eb) */
/* WARNING: Removing unreachable block (ram,0x008ff9d3) */
/* WARNING: Removing unreachable block (ram,0x008ff98a) */
/* WARNING: Removing unreachable block (ram,0x008ff97e) */
/* WARNING: Removing unreachable block (ram,0x008ff966) */
/* WARNING: Removing unreachable block (ram,0x008ff94e) */
/* WARNING: Removing unreachable block (ram,0x008ff92a) */
/* WARNING: Removing unreachable block (ram,0x008ff912) */
/* WARNING: Removing unreachable block (ram,0x008ff8fa) */
/* WARNING: Removing unreachable block (ram,0x008ff8b2) */
/* WARNING: Removing unreachable block (ram,0x008ff8be) */
/* WARNING: Removing unreachable block (ram,0x008ff8d6) */
/* WARNING: Removing unreachable block (ram,0x008ff8ee) */
/* WARNING: Removing unreachable block (ram,0x008ff906) */
/* WARNING: Removing unreachable block (ram,0x008ff91e) */
/* WARNING: Removing unreachable block (ram,0x008ff942) */
/* WARNING: Removing unreachable block (ram,0x008ff95a) */
/* WARNING: Removing unreachable block (ram,0x008ff972) */
/* WARNING: Removing unreachable block (ram,0x008ff9a8) */
/* WARNING: Removing unreachable block (ram,0x008ff9c1) */
/* WARNING: Removing unreachable block (ram,0x008ff9df) */
/* WARNING: Removing unreachable block (ram,0x008ffa58) */
/* WARNING: Removing unreachable block (ram,0x008ffab5) */
/* WARNING: Removing unreachable block (ram,0x008ffb21) */
/* WARNING: Removing unreachable block (ram,0x008ffbf4) */
/* WARNING: Removing unreachable block (ram,0x008ffc84) */
/* WARNING: Removing unreachable block (ram,0x008ffd30) */
/* WARNING: Removing unreachable block (ram,0x008ffa9d) */
/* WARNING: Removing unreachable block (ram,0x008ffb93) */
/* WARNING: Removing unreachable block (ram,0x008ffcd0) */
/* WARNING: Removing unreachable block (ram,0x008ffb39) */
/* WARNING: Removing unreachable block (ram,0x008ffd51) */
/* WARNING: Removing unreachable block (ram,0x008ffc3c) */
/* WARNING: Removing unreachable block (ram,0x008ffbdc) */
/* WARNING: Removing unreachable block (ram,0x008ffd80) */
/* WARNING: Removing unreachable block (ram,0x008ffd98) */
/* WARNING: Removing unreachable block (ram,0x008ffda4) */
/* WARNING: Removing unreachable block (ram,0x008ffdbc) */
/* WARNING: Removing unreachable block (ram,0x008ffdd4) */
/* WARNING: Removing unreachable block (ram,0x008ffdec) */
/* WARNING: Removing unreachable block (ram,0x008ffe28) */
/* WARNING: Removing unreachable block (ram,0x008ffe40) */
/* WARNING: Removing unreachable block (ram,0x008ffe58) */
/* WARNING: Removing unreachable block (ram,0x008ffe70) */
/* WARNING: Removing unreachable block (ram,0x008ffe88) */
/* WARNING: Removing unreachable block (ram,0x008ffea0) */
/* WARNING: Removing unreachable block (ram,0x008ffedc) */
/* WARNING: Removing unreachable block (ram,0x008fff29) */
/* WARNING: Removing unreachable block (ram,0x008fff41) */
/* WARNING: Removing unreachable block (ram,0x008fff59) */
/* WARNING: Removing unreachable block (ram,0x008fffad) */
/* WARNING: Removing unreachable block (ram,0x008ffb09) */
/* WARNING: Removing unreachable block (ram,0x008ffafd) */
/* WARNING: Removing unreachable block (ram,0x008ffacd) */
/* WARNING: Removing unreachable block (ram,0x008ffad3) */
/* WARNING: Removing unreachable block (ram,0x008fff35) */
/* WARNING: Removing unreachable block (ram,0x008ffaa9) */
/* WARNING: Removing unreachable block (ram,0x008ffec4) */
/* WARNING: Removing unreachable block (ram,0x008fff71) */
/* WARNING: Removing unreachable block (ram,0x008ffe10) */
/* WARNING: Removing unreachable block (ram,0x008ffc00) */
/* WARNING: Removing unreachable block (ram,0x008ffc6c) */
/* WARNING: Removing unreachable block (ram,0x008ffb9f) */
/* WARNING: Removing unreachable block (ram,0x008ffa03) */
/* WARNING: Removing unreachable block (ram,0x008ff936) */
/* WARNING: Removing unreachable block (ram,0x008ff8e2) */
/* WARNING: Removing unreachable block (ram,0x008ffb45) */
/* WARNING: Removing unreachable block (ram,0x008ffc60) */
/* WARNING: Removing unreachable block (ram,0x008ffbe8) */
/* WARNING: Removing unreachable block (ram,0x008ffd63) */
/* WARNING: Removing unreachable block (ram,0x008ffdb0) */
/* WARNING: Removing unreachable block (ram,0x008ffe64) */
/* WARNING: Removing unreachable block (ram,0x008ffee8) */
/* WARNING: Removing unreachable block (ram,0x008ff996) */
/* WARNING: Removing unreachable block (ram,0x008ff99c) */
/* WARNING: Removing unreachable block (ram,0x008ff8ca) */
/* WARNING: Removing unreachable block (ram,0x008ffc18) */
/* WARNING: Removing unreachable block (ram,0x008ffc0c) */
/* WARNING: Removing unreachable block (ram,0x008ffcf4) */
/* WARNING: Removing unreachable block (ram,0x008ffb15) */
/* WARNING: Removing unreachable block (ram,0x008ffd0c) */
/* WARNING: Removing unreachable block (ram,0x008ffc48) */
/* WARNING: Removing unreachable block (ram,0x008fff89) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000018 : 0x008ffa68 */
/* WARNING: Removing unreachable block (ram,0x008fff95) */
/* WARNING: Removing unreachable block (ram,0x008ffc78) */
/* WARNING: Removing unreachable block (ram,0x008ffe7c) */
/* WARNING: Removing unreachable block (ram,0x008ffce8) */
/* WARNING: Removing unreachable block (ram,0x008ffc24) */
/* WARNING: Removing unreachable block (ram,0x008fffa1) */
/* WARNING: Removing unreachable block (ram,0x008ffd18) */
/* WARNING: Removing unreachable block (ram,0x008ffd24) */
/* WARNING: Removing unreachable block (ram,0x008ffd3c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint __thiscall FUN_008ff89e(void *this)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  byte bVar4;
  byte extraout_CL;
  uint extraout_EDX;
  bool bVar5;
  byte *in_stack_0000000c;
  int in_stack_00000014;
  int in_stack_00000018;
  uint in_stack_00000020;
  undefined *puStackY_44;
  uint uStack_1c;
  uint uStack_18;
  int iStack_14;
  uint uStack_10;
  int iStack_c;
  uint uStack_8;

  uStack_1c = in_stack_00000018 + -1 + in_stack_00000014;
  uStack_8 = uStack_1c;
  while (bVar4 = (byte)uStack_1c, uVar3 = uStack_10, uStack_1c = uStack_8, uStack_10 < uStack_8) {
    puStackY_44 = &UNK_008ffa31;
    uVar1 = FUN_008f2140(&stack0x00000004,&uStack_10,&uStack_1c,4,
                         (ushort)((in_stack_00000020 & 0xffff) == 0));
    uVar3 = extraout_EDX;
    bVar4 = extraout_CL;
    if ((uVar1 & 0xffff) == 0) break;
    uStack_18 = uStack_10 - in_stack_00000018;
    bVar5 = (POPCOUNT(uStack_18 & 0xff) & 1U) == 0;
    if ((!bVar5) && (bVar5)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((!bVar5) && (bVar5)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iStack_c = (uStack_1c - uStack_10) + 1;
    puStackY_44 = &UNK_008ffb6d;
    FUN_008fffb5();
    FUN_00900450(&puStackY_44,in_stack_0000000c);
    puStackY_44 = &UNK_008ffca9;
    FUN_008f42cf((byte)&stack0xffffffc0);
    _DAT_0090b1f8 = _DAT_0090b1f8 + iStack_14;
    uStack_1c = uStack_10 + iStack_c;
    uStack_10 = uStack_1c;
  }
  piVar2 = FUN_00901c41(bVar4,(short)uVar3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  uVar3 = -(uint)(((uint)piVar2 & 0xffff) != 0) & 0x4f3;
  _DAT_0090b1f8 = _DAT_0090b1f8 + uVar3;
  bVar5 = (POPCOUNT(_DAT_0090b1f8 & 0xff) & 1U) == 0;
  if ((!bVar5) && (bVar5)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return uVar3;
}



/* VA 008fffb5 */

/* WARNING: Instruction at (ram,0x009001c3) overlaps instruction at (ram,0x009001c2)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x009002ff) */
/* WARNING: Removing unreachable block (ram,0x00900339) */
/* WARNING: Removing unreachable block (ram,0x009002c2) */
/* WARNING: Removing unreachable block (ram,0x009002aa) */
/* WARNING: Removing unreachable block (ram,0x00900292) */
/* WARNING: Removing unreachable block (ram,0x0090027a) */
/* WARNING: Removing unreachable block (ram,0x00900262) */
/* WARNING: Removing unreachable block (ram,0x0090024a) */
/* WARNING: Removing unreachable block (ram,0x00900232) */
/* WARNING: Removing unreachable block (ram,0x00900226) */
/* WARNING: Removing unreachable block (ram,0x0090020e) */
/* WARNING: Removing unreachable block (ram,0x009001d2) */
/* WARNING: Removing unreachable block (ram,0x00900117) */
/* WARNING: Removing unreachable block (ram,0x0090010b) */
/* WARNING: Removing unreachable block (ram,0x00900157) */
/* WARNING: Removing unreachable block (ram,0x009000a2) */
/* WARNING: Removing unreachable block (ram,0x00900072) */
/* WARNING: Removing unreachable block (ram,0x0090005a) */
/* WARNING: Removing unreachable block (ram,0x00900042) */
/* WARNING: Removing unreachable block (ram,0x0090002a) */
/* WARNING: Removing unreachable block (ram,0x00900012) */
/* WARNING: Removing unreachable block (ram,0x008ffffa) */
/* WARNING: Removing unreachable block (ram,0x00900006) */
/* WARNING: Removing unreachable block (ram,0x0090001e) */
/* WARNING: Removing unreachable block (ram,0x00900036) */
/* WARNING: Removing unreachable block (ram,0x0090004e) */
/* WARNING: Removing unreachable block (ram,0x00900066) */
/* WARNING: Removing unreachable block (ram,0x0090007e) */
/* WARNING: Removing unreachable block (ram,0x0090008a) */
/* WARNING: Removing unreachable block (ram,0x009000ff) */
/* WARNING: Removing unreachable block (ram,0x0090019d) */
/* WARNING: Removing unreachable block (ram,0x0090017b) */
/* WARNING: Removing unreachable block (ram,0x0090018b) */
/* WARNING: Removing unreachable block (ram,0x009001de) */
/* WARNING: Removing unreachable block (ram,0x009001ea) */
/* WARNING: Removing unreachable block (ram,0x00900202) */
/* WARNING: Removing unreachable block (ram,0x0090021a) */
/* WARNING: Removing unreachable block (ram,0x00900256) */
/* WARNING: Removing unreachable block (ram,0x0090026e) */
/* WARNING: Removing unreachable block (ram,0x00900286) */
/* WARNING: Removing unreachable block (ram,0x0090029e) */
/* WARNING: Removing unreachable block (ram,0x009002b6) */
/* WARNING: Removing unreachable block (ram,0x009002ce) */
/* WARNING: Removing unreachable block (ram,0x009002da) */
/* WARNING: Removing unreachable block (ram,0x009001b5) */
/* WARNING: Removing unreachable block (ram,0x009001a9) */
/* WARNING: Removing unreachable block (ram,0x00900163) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000014 : 0x009000e8 */
/* WARNING: Removing unreachable block (ram,0x009002e6) */
/* WARNING: Removing unreachable block (ram,0x009001f6) */
/* WARNING: Removing unreachable block (ram,0x00900096) */
/* WARNING: Removing unreachable block (ram,0x0090023e) */
/* WARNING: Removing unreachable block (ram,0x0090016f) */
/* WARNING: Removing unreachable block (ram,0x00900123) */
/* WARNING: Removing unreachable block (ram,0x009000ae) */
/* WARNING: Removing unreachable block (ram,0x009001c1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_008fffb5(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *in_stack_00000010;
  short sStack00000014;

  uVar2 = FUN_008f54b0((int *)0x0);
  uVar3 = _sStack00000014 & 0xffff;
  if (7 < (_sStack00000014 & 0xffff)) {
    while ((0xf < (_sStack00000014 & 0xffff) || ((_sStack00000014 & 0xffff) == 8))) {
      FUN_00900341(in_stack_00000010,(int *)&DAT_0090b1e8);
      in_stack_00000010 = in_stack_00000010 + 2;
      _sStack00000014 = (uint)(ushort)(sStack00000014 - 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
      if ((_sStack00000014 == uVar2 % uVar3) &&
         (sVar1 = FUN_00901890((uint *)&DAT_0090b1f8), sVar1 != 0)) {
        _DAT_0090b1f8 = _DAT_0090b1f8 + _sStack00000014;
      }
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    if ((_sStack00000014 & 0xffff) != 0) {
      FUN_00900341((undefined4 *)((int)in_stack_00000010 + ((_sStack00000014 & 0xffff) - 8)),
                   (int *)&DAT_0090b1e8);
      FUN_00900341(in_stack_00000010,(int *)&DAT_0090b1e8);
    }
  }
  return;
}



/* VA 00900341 */

/* WARNING: Instruction at (ram,0x0090041c) overlaps instruction at (ram,0x0090041b)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00900427) */
/* WARNING: Removing unreachable block (ram,0x0090042b) */
/* WARNING: Removing unreachable block (ram,0x009003d9) */
/* WARNING: Removing unreachable block (ram,0x0090037b) */
/* WARNING: Removing unreachable block (ram,0x0090036f) */
/* WARNING: Removing unreachable block (ram,0x0090041a) */
/* WARNING: Removing unreachable block (ram,0x0090041e) */
/* WARNING: Removing unreachable block (ram,0x0090041d) */
/* WARNING: Removing unreachable block (ram,0x00900433) */
/* WARNING: Removing unreachable block (ram,0x00900437) */
/* WARNING: Removing unreachable block (ram,0x561b0c8a) */
/* WARNING: Removing unreachable block (ram,0x0090043d) */
/* WARNING: Removing unreachable block (ram,0x00900393) */

void FUN_00900341(undefined4 *param_1,int *param_2)

{
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;

  local_c = *param_1;
  local_10 = param_1[1];
  local_14 = DAT_0090600c;
  local_8 = DAT_00906008 << 5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  while (local_14 != 0) {
    local_10 = local_10 -
               (local_c * 0x10 + param_2[2] ^ local_c + local_8 ^ (local_c >> 5) + param_2[3]);
    local_c = local_c - (local_10 * 0x10 + *param_2 ^ local_10 + local_8 ^
                        (local_10 >> 5) + param_2[1]);
    local_8 = local_8 - DAT_00906008;
    local_14 = local_14 + -1;
  }
  *param_1 = local_c;
  param_1[1] = local_10;
  return;
}



/* VA 00900450 */

/* WARNING: Instruction at (ram,0x009004c7) overlaps instruction at (ram,0x009004c3)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x009004a4) */
/* WARNING: Removing unreachable block (ram,0x009004a8) */
/* WARNING: Removing unreachable block (ram,0x009004ae) */
/* WARNING: Removing unreachable block (ram,0x009004af) */
/* WARNING: Removing unreachable block (ram,0x0090088c) */
/* WARNING: Removing unreachable block (ram,0x00900890) */
/* WARNING: Removing unreachable block (ram,0x00900489) */
/* WARNING: Removing unreachable block (ram,0x00900464) */
/* WARNING: Removing unreachable block (ram,0x0090047d) */
/* WARNING: Removing unreachable block (ram,0x00900898) */
/* WARNING: Removing unreachable block (ram,0x0090089c) */
/* WARNING: Removing unreachable block (ram,0x009007be) */
/* WARNING: Removing unreachable block (ram,0x009009ec) */
/* WARNING: Removing unreachable block (ram,0x009008fc) */
/* WARNING: Removing unreachable block (ram,0x009008f0) */
/* WARNING: Removing unreachable block (ram,0x00900974) */
/* WARNING: Removing unreachable block (ram,0x00900a10) */
/* WARNING: Removing unreachable block (ram,0x0090072e) */
/* WARNING: Removing unreachable block (ram,0x00900852) */
/* WARNING: Removing unreachable block (ram,0x00900862) */
/* WARNING: Removing unreachable block (ram,0x009009a4) */
/* WARNING: Removing unreachable block (ram,0x00900716) */
/* WARNING: Removing unreachable block (ram,0x00900920) */
/* WARNING: Removing unreachable block (ram,0x00900722) */
/* WARNING: Removing unreachable block (ram,0x0090098c) */
/* WARNING: Removing unreachable block (ram,0x00900822) */
/* WARNING: Removing unreachable block (ram,0x009006e6) */
/* WARNING: Removing unreachable block (ram,0x009009d4) */
/* WARNING: Removing unreachable block (ram,0x0090092c) */
/* WARNING: Removing unreachable block (ram,0x009008a4) */
/* WARNING: Removing unreachable block (ram,0x009008a8) */
/* WARNING: Removing unreachable block (ram,0x009007fe) */
/* WARNING: Removing unreachable block (ram,0x0090079a) */
/* WARNING: Removing unreachable block (ram,0x0090073a) */
/* WARNING: Removing unreachable block (ram,0x009006da) */
/* WARNING: Removing unreachable block (ram,0x009005cf) */
/* WARNING: Removing unreachable block (ram,0x009005b7) */
/* WARNING: Removing unreachable block (ram,0x0090059f) */
/* WARNING: Removing unreachable block (ram,0x00900587) */
/* WARNING: Removing unreachable block (ram,0x0090056f) */
/* WARNING: Removing unreachable block (ram,0x00900557) */
/* WARNING: Removing unreachable block (ram,0x00900533) */
/* WARNING: Removing unreachable block (ram,0x009004f7) */
/* WARNING: Removing unreachable block (ram,0x009004df) */
/* WARNING: Removing unreachable block (ram,0x009004d3) */
/* WARNING: Removing unreachable block (ram,0x009004c2) */
/* WARNING: Removing unreachable block (ram,0x00900503) */
/* WARNING: Removing unreachable block (ram,0x0090053f) */
/* WARNING: Removing unreachable block (ram,0x00900563) */
/* WARNING: Removing unreachable block (ram,0x0090057b) */
/* WARNING: Removing unreachable block (ram,0x00900593) */
/* WARNING: Removing unreachable block (ram,0x009005ab) */
/* WARNING: Removing unreachable block (ram,0x009005c3) */
/* WARNING: Removing unreachable block (ram,0x009005db) */
/* WARNING: Removing unreachable block (ram,0x009006b6) */
/* WARNING: Removing unreachable block (ram,0x0090070a) */
/* WARNING: Removing unreachable block (ram,0x0090076a) */
/* WARNING: Removing unreachable block (ram,0x009007ca) */
/* WARNING: Removing unreachable block (ram,0x009007d0) */
/* WARNING: Removing unreachable block (ram,0x009007d1) */
/* WARNING: Removing unreachable block (ram,0x0090082e) */
/* WARNING: Removing unreachable block (ram,0x009008d8) */
/* WARNING: Removing unreachable block (ram,0x00900980) */
/* WARNING: Removing unreachable block (ram,0x00900a41) */
/* WARNING: Removing unreachable block (ram,0x00900776) */
/* WARNING: Removing unreachable block (ram,0x009008e4) */
/* WARNING: Removing unreachable block (ram,0x00900a4d) */
/* WARNING: Removing unreachable block (ram,0x0090080a) */
/* WARNING: Removing unreachable block (ram,0x009009e0) */
/* WARNING: Removing unreachable block (ram,0x0090083a) */
/* WARNING: Removing unreachable block (ram,0x009006f2) */
/* WARNING: Removing unreachable block (ram,0x009009c8) */
/* WARNING: Removing unreachable block (ram,0x009008cc) */
/* WARNING: Removing unreachable block (ram,0x009007a6) */
/* WARNING: Removing unreachable block (ram,0x009006fe) */
/* WARNING: Removing unreachable block (ram,0x009006c2) */
/* WARNING: Removing unreachable block (ram,0x00900746) */
/* WARNING: Removing unreachable block (ram,0x00900914) */
/* WARNING: Removing unreachable block (ram,0x00900752) */
/* WARNING: Removing unreachable block (ram,0x00900938) */
/* WARNING: Removing unreachable block (ram,0x00900950) */
/* WARNING: Removing unreachable block (ram,0x00900a1c) */
/* WARNING: Removing unreachable block (ram,0x00900816) */
/* WARNING: Removing unreachable block (ram,0x009009f8) */
/* WARNING: Removing unreachable block (ram,0x009008bc) */
/* WARNING: Removing unreachable block (ram,0x009008c0) */
/* WARNING: Removing unreachable block (ram,0x00900782) */
/* WARNING: Removing unreachable block (ram,0x009008b0) */
/* WARNING: Removing unreachable block (ram,0x009008b4) */
/* WARNING: Removing unreachable block (ram,0x009009b0) */
/* WARNING: Removing unreachable block (ram,0x0090078e) */
/* WARNING: Removing unreachable block (ram,0x009009bc) */
/* WARNING: Removing unreachable block (ram,0x009008c8) */
/* WARNING: Removing unreachable block (ram,0x009007b2) */
/* WARNING: Removing unreachable block (ram,0x009006ce) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000014 : 0x009005f0 */
/* WARNING: Removing unreachable block (ram,0x009005e7) */
/* WARNING: Removing unreachable block (ram,0x0090095c) */
/* WARNING: Removing unreachable block (ram,0x00900a28) */
/* WARNING: Removing unreachable block (ram,0x00900846) */
/* WARNING: Removing unreachable block (ram,0x009004eb) */
/* WARNING: Removing unreachable block (ram,0x0090054b) */
/* WARNING: Removing unreachable block (ram,0x009008d4) */
/* WARNING: Removing unreachable block (ram,0x00900a59) */
/* WARNING: Removing unreachable block (ram,0x0090075e) */
/* WARNING: Removing unreachable block (ram,0x0090050f) */
/* WARNING: Removing unreachable block (ram,0x00900968) */
/* WARNING: Removing unreachable block (ram,0x00900a65) */
/* WARNING: Removing unreachable block (ram,0x00900a69) */
/* WARNING: Removing unreachable block (ram,0x00900a64) */
/* WARNING: Removing unreachable block (ram,0x00900944) */
/* WARNING: Removing unreachable block (ram,0x0090051b) */
/* WARNING: Removing unreachable block (ram,0x00900998) */
/* WARNING: Removing unreachable block (ram,0x00900a04) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int * __fastcall FUN_00900450(undefined4 param_1,byte *param_2)

{
  short sVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  bool bVar7;
  byte *in_stack_00000010;
  short sStack00000014;
  byte *in_stack_00000018;
  uint uStack_8;

  uVar2 = FUN_008f54b0((int *)0x0);
  uVar6 = _sStack00000014 & 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
  piVar3 = (int *)(uVar2 / uVar6);
                    /* WARNING: Bad instruction - Truncating control flow here */
  bVar7 = (POPCOUNT((_sStack00000014 & 0xffff) - 8 & 0xff) & 1U) == 0;
  if (7 < (_sStack00000014 & 0xffff)) {
    if ((!bVar7) && (bVar7)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    while( true ) {
      uVar4 = _sStack00000014 & 0xffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
      uVar5 = sStack00000014 - 1;
      _sStack00000014 = (uint)uVar5;
      piVar3 = (int *)0x0;
      if (uVar4 == 0) break;
      *in_stack_00000010 = *in_stack_00000010 ^ DAT_0090b1f8;
      *in_stack_00000010 = *in_stack_00000010 ^ (byte)((uint)_DAT_0090b1f8 >> 8);
      *in_stack_00000010 = *in_stack_00000010 ^ (byte)((uint)_DAT_0090b1f8 >> 0x10);
      *in_stack_00000010 = *in_stack_00000010 ^ (byte)((uint)_DAT_0090b1f8 >> 0x18);
      *in_stack_00000010 = *in_stack_00000010 ^ *in_stack_00000018;
      _DAT_0090b1f8 = _DAT_0090b1f8 + (uint)*in_stack_00000010;
      in_stack_00000010 = in_stack_00000010 + 1;
      in_stack_00000018 = in_stack_00000018 + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
      if ((_sStack00000014 == uVar2 % uVar6) &&
         (sVar1 = FUN_00901890((uint *)&DAT_0090b1f8), sVar1 != 0)) {
        _DAT_0090b1f8 = _DAT_0090b1f8 + _sStack00000014;
      }
      if ((uVar5 & 0xf) == 0) {
        FUN_009019fb(&uStack_8);
        _DAT_0090b1f8 = _DAT_0090b1f8 + uStack_8;
      }
    }
  }
  return piVar3;
}



/* VA 00900a72 */

/* WARNING: Instruction at (ram,0x00900c41) overlaps instruction at (ram,0x00900c3d)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00900c30) */
/* WARNING: Removing unreachable block (ram,0x00900c18) */
/* WARNING: Removing unreachable block (ram,0x00900c0c) */
/* WARNING: Removing unreachable block (ram,0x00900b50) */
/* WARNING: Removing unreachable block (ram,0x00900b38) */
/* WARNING: Removing unreachable block (ram,0x00900b14) */
/* WARNING: Removing unreachable block (ram,0x00900afc) */
/* WARNING: Removing unreachable block (ram,0x00900ae4) */
/* WARNING: Removing unreachable block (ram,0x00900ad8) */
/* WARNING: Removing unreachable block (ram,0x00900ac0) */
/* WARNING: Removing unreachable block (ram,0x00900aa8) */
/* WARNING: Removing unreachable block (ram,0x00900a90) */
/* WARNING: Removing unreachable block (ram,0x00900a84) */
/* WARNING: Removing unreachable block (ram,0x00900a9c) */
/* WARNING: Removing unreachable block (ram,0x00900ab4) */
/* WARNING: Removing unreachable block (ram,0x00900acc) */
/* WARNING: Removing unreachable block (ram,0x00900b08) */
/* WARNING: Removing unreachable block (ram,0x00900b20) */
/* WARNING: Removing unreachable block (ram,0x00900b44) */
/* WARNING: Removing unreachable block (ram,0x00900b5c) */
/* WARNING: Removing unreachable block (ram,0x00900b9a) */
/* WARNING: Removing unreachable block (ram,0x00900ba6) */
/* WARNING: Removing unreachable block (ram,0x00900bbe) */
/* WARNING: Removing unreachable block (ram,0x00900c24) */
/* WARNING: Removing unreachable block (ram,0x00900bb2) */
/* WARNING: Removing unreachable block (ram,0x00900af0) */
/* WARNING: Removing unreachable block (ram,0x00900b68) */
/* WARNING: Removing unreachable block (ram,0x00900b2c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00900a72(undefined1 *param_1)

{
  bool bVar1;
  int iStack_18;
  uint local_8;

  local_8 = 0;
  do {
    if (0xf < local_8) {
      (*(code *)(iStack_18 + 0x5e))();
      return;
    }
    if (param_1 == (undefined1 *)0x0) {
      (&DAT_0090b1e8)[local_8] = (undefined1)local_8;
    }
    else {
      (&DAT_0090b1e8)[local_8] = *param_1;
      param_1 = param_1 + 1;
      bVar1 = (POPCOUNT((uint)param_1 & 0xff) & 1U) == 0;
      if ((!bVar1) && (bVar1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    local_8 = (uint)(ushort)((short)local_8 + 1);
  } while( true );
}



/* VA 00900c49 */

/* WARNING: Instruction at (ram,0x00900fee) overlaps instruction at (ram,0x00900fed)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00900f95) */
/* WARNING: Removing unreachable block (ram,0x00900f9a) */
/* WARNING: Removing unreachable block (ram,0x00900f2a) */
/* WARNING: Removing unreachable block (ram,0x00901018) */
/* WARNING: Removing unreachable block (ram,0x00901000) */
/* WARNING: Removing unreachable block (ram,0x00900fdc) */
/* WARNING: Removing unreachable block (ram,0x00900f73) */
/* WARNING: Removing unreachable block (ram,0x00900f5b) */
/* WARNING: Removing unreachable block (ram,0x00900f15) */
/* WARNING: Removing unreachable block (ram,0x00900f09) */
/* WARNING: Removing unreachable block (ram,0x00900ef1) */
/* WARNING: Removing unreachable block (ram,0x00900ed9) */
/* WARNING: Removing unreachable block (ram,0x00900e8f) */
/* WARNING: Removing unreachable block (ram,0x00900e75) */
/* WARNING: Removing unreachable block (ram,0x00900e45) */
/* WARNING: Removing unreachable block (ram,0x00900e2d) */
/* WARNING: Removing unreachable block (ram,0x00900df2) */
/* WARNING: Removing unreachable block (ram,0x00900db9) */
/* WARNING: Removing unreachable block (ram,0x00900da1) */
/* WARNING: Removing unreachable block (ram,0x00900d89) */
/* WARNING: Removing unreachable block (ram,0x00900d71) */
/* WARNING: Removing unreachable block (ram,0x00900d41) */
/* WARNING: Removing unreachable block (ram,0x00900d29) */
/* WARNING: Removing unreachable block (ram,0x00900d11) */
/* WARNING: Removing unreachable block (ram,0x00900cf9) */
/* WARNING: Removing unreachable block (ram,0x00900ce1) */
/* WARNING: Removing unreachable block (ram,0x00900cc9) */
/* WARNING: Removing unreachable block (ram,0x00900ca5) */
/* WARNING: Removing unreachable block (ram,0x00900c8d) */
/* WARNING: Removing unreachable block (ram,0x00900c81) */
/* WARNING: Removing unreachable block (ram,0x00900c69) */
/* WARNING: Removing unreachable block (ram,0x00900c5d) */
/* WARNING: Removing unreachable block (ram,0x00900c75) */
/* WARNING: Removing unreachable block (ram,0x00900cb1) */
/* WARNING: Removing unreachable block (ram,0x00900cd5) */
/* WARNING: Removing unreachable block (ram,0x00900ced) */
/* WARNING: Removing unreachable block (ram,0x00900d05) */
/* WARNING: Removing unreachable block (ram,0x00900d1d) */
/* WARNING: Removing unreachable block (ram,0x00900d35) */
/* WARNING: Removing unreachable block (ram,0x00900d4d) */
/* WARNING: Removing unreachable block (ram,0x00900d7d) */
/* WARNING: Removing unreachable block (ram,0x00900d95) */
/* WARNING: Removing unreachable block (ram,0x00900dad) */
/* WARNING: Removing unreachable block (ram,0x00900dc5) */
/* WARNING: Removing unreachable block (ram,0x00900dd1) */
/* WARNING: Removing unreachable block (ram,0x00900e0a) */
/* WARNING: Removing unreachable block (ram,0x00900e51) */
/* WARNING: Removing unreachable block (ram,0x00900e5d) */
/* WARNING: Removing unreachable block (ram,0x00900e9b) */
/* WARNING: Removing unreachable block (ram,0x00900eb3) */
/* WARNING: Removing unreachable block (ram,0x00900ecd) */
/* WARNING: Removing unreachable block (ram,0x00900ee5) */
/* WARNING: Removing unreachable block (ram,0x00900efd) */
/* WARNING: Removing unreachable block (ram,0x00900f67) */
/* WARNING: Removing unreachable block (ram,0x00900f7f) */
/* WARNING: Removing unreachable block (ram,0x00900fd0) */
/* WARNING: Removing unreachable block (ram,0x00900fe8) */
/* WARNING: Removing unreachable block (ram,0x0090100c) */
/* WARNING: Removing unreachable block (ram,0x00900f25) */
/* WARNING: Removing unreachable block (ram,0x00900f4f) */
/* WARNING: Removing unreachable block (ram,0x00900f37) */
/* WARNING: Removing unreachable block (ram,0x00900f21) */
/* WARNING: Removing unreachable block (ram,0x00900f43) */
/* WARNING: Removing unreachable block (ram,0x00900dfe) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff4 : 0x00900fa5 */
/* WARNING: Removing unreachable block (ram,0x00900e69) */
/* WARNING: Removing unreachable block (ram,0x00901024) */
/* WARNING: Removing unreachable block (ram,0x00900d59) */
/* WARNING: Removing unreachable block (ram,0x00900c99) */
/* WARNING: Removing unreachable block (ram,0x00900e39) */
/* WARNING: Removing unreachable block (ram,0x00900ea7) */
/* WARNING: Removing unreachable block (ram,0x00900cbd) */
/* WARNING: Removing unreachable block (ram,0x00900d65) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 __fastcall FUN_00900c49(uint param_1,int *param_2,undefined1 *param_3,undefined2 param_4)

{
  undefined4 uVar1;
  bool bVar2;
  LPCSTR unaff_retaddr;
  HMODULE pHStack_10;
  undefined4 uStack_c;
  undefined *puStack_8;

  bVar2 = (POPCOUNT((uint)&pHStack_10 & 0xff) & 1U) == 0;
  GetCurrentProcess();
  if ((!bVar2) && (bVar2)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  pHStack_10 = GetModuleHandleA(unaff_retaddr);
  if ((!bVar2) && (bVar2)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puStack_8 = &UNK_00900e81;
  FUN_008f2450((int)&pHStack_10,unaff_retaddr);
  puStack_8 = &UNK_00900ebf;
  func_0x008f1f80();
  FUN_00900a72((undefined1 *)0x0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  puStack_8 = (undefined *)0x907398;
  uStack_c = 0x907398;
  FUN_008ff065(0x907398,(short)pHStack_10);
  bVar2 = POPCOUNT((uint)&param_3 & 0xff) == '\0';
  if ((!bVar2) && (bVar2)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = func_0x008f2040();
  return uVar1;
}



/* VA 0090102c */

/* WARNING: Instruction at (ram,0x0090146b) overlaps instruction at (ram,0x0090146a)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0090148b) */
/* WARNING: Removing unreachable block (ram,0x00901445) */
/* WARNING: Removing unreachable block (ram,0x009013f6) */
/* WARNING: Removing unreachable block (ram,0x009013de) */
/* WARNING: Removing unreachable block (ram,0x009013d2) */
/* WARNING: Removing unreachable block (ram,0x00901396) */
/* WARNING: Removing unreachable block (ram,0x0090137e) */
/* WARNING: Removing unreachable block (ram,0x00901366) */
/* WARNING: Removing unreachable block (ram,0x0090134e) */
/* WARNING: Removing unreachable block (ram,0x00901338) */
/* WARNING: Removing unreachable block (ram,0x00901320) */
/* WARNING: Removing unreachable block (ram,0x00901308) */
/* WARNING: Removing unreachable block (ram,0x009012f0) */
/* WARNING: Removing unreachable block (ram,0x009012c0) */
/* WARNING: Removing unreachable block (ram,0x0090129c) */
/* WARNING: Removing unreachable block (ram,0x00901284) */
/* WARNING: Removing unreachable block (ram,0x0090122e) */
/* WARNING: Removing unreachable block (ram,0x0090120a) */
/* WARNING: Removing unreachable block (ram,0x009011f2) */
/* WARNING: Removing unreachable block (ram,0x009011da) */
/* WARNING: Removing unreachable block (ram,0x009011c2) */
/* WARNING: Removing unreachable block (ram,0x009011aa) */
/* WARNING: Removing unreachable block (ram,0x00901186) */
/* WARNING: Removing unreachable block (ram,0x0090117a) */
/* WARNING: Removing unreachable block (ram,0x00901162) */
/* WARNING: Removing unreachable block (ram,0x0090110c) */
/* WARNING: Removing unreachable block (ram,0x009010f4) */
/* WARNING: Removing unreachable block (ram,0x009010dc) */
/* WARNING: Removing unreachable block (ram,0x009010c4) */
/* WARNING: Removing unreachable block (ram,0x009010ac) */
/* WARNING: Removing unreachable block (ram,0x00901094) */
/* WARNING: Removing unreachable block (ram,0x00901070) */
/* WARNING: Removing unreachable block (ram,0x00901064) */
/* WARNING: Removing unreachable block (ram,0x0090104c) */
/* WARNING: Removing unreachable block (ram,0x00901040) */
/* WARNING: Removing unreachable block (ram,0x00901058) */
/* WARNING: Removing unreachable block (ram,0x009010a0) */
/* WARNING: Removing unreachable block (ram,0x009010b8) */
/* WARNING: Removing unreachable block (ram,0x009010d0) */
/* WARNING: Removing unreachable block (ram,0x009010e8) */
/* WARNING: Removing unreachable block (ram,0x00901100) */
/* WARNING: Removing unreachable block (ram,0x00901118) */
/* WARNING: Removing unreachable block (ram,0x00901124) */
/* WARNING: Removing unreachable block (ram,0x00901156) */
/* WARNING: Removing unreachable block (ram,0x0090116e) */
/* WARNING: Removing unreachable block (ram,0x009011b6) */
/* WARNING: Removing unreachable block (ram,0x009011ce) */
/* WARNING: Removing unreachable block (ram,0x009011e6) */
/* WARNING: Removing unreachable block (ram,0x009011fe) */
/* WARNING: Removing unreachable block (ram,0x00901216) */
/* WARNING: Removing unreachable block (ram,0x0090123a) */
/* WARNING: Removing unreachable block (ram,0x00901260) */
/* WARNING: Removing unreachable block (ram,0x00901278) */
/* WARNING: Removing unreachable block (ram,0x00901290) */
/* WARNING: Removing unreachable block (ram,0x009012b4) */
/* WARNING: Removing unreachable block (ram,0x009012e4) */
/* WARNING: Removing unreachable block (ram,0x009012fc) */
/* WARNING: Removing unreachable block (ram,0x00901314) */
/* WARNING: Removing unreachable block (ram,0x0090132c) */
/* WARNING: Removing unreachable block (ram,0x00901372) */
/* WARNING: Removing unreachable block (ram,0x0090138a) */
/* WARNING: Removing unreachable block (ram,0x009013a2) */
/* WARNING: Removing unreachable block (ram,0x009013ae) */
/* WARNING: Removing unreachable block (ram,0x009013c6) */
/* WARNING: Removing unreachable block (ram,0x00901402) */
/* WARNING: Removing unreachable block (ram,0x00901451) */
/* WARNING: Removing unreachable block (ram,0x0090145d) */
/* WARNING: Removing unreachable block (ram,0x0090135a) */
/* WARNING: Removing unreachable block (ram,0x0090126c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff0 : 0x00901421 */
/* WARNING: Removing unreachable block (ram,0x009013ba) */
/* WARNING: Removing unreachable block (ram,0x00901469) */
/* WARNING: Removing unreachable block (ram,0x009012a8) */
/* WARNING: Removing unreachable block (ram,0x0090107c) */
/* WARNING: Removing unreachable block (ram,0x00901192) */
/* WARNING: Removing unreachable block (ram,0x009012cc) */
/* WARNING: Removing unreachable block (ram,0x009013ea) */
/* WARNING: Removing unreachable block (ram,0x00901222) */
/* WARNING: Removing unreachable block (ram,0x0090119e) */
/* WARNING: Removing unreachable block (ram,0x009012d8) */
/* WARNING: Removing unreachable block (ram,0x00901088) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0090102c(undefined4 param_1,char *param_2)

{
  bool bVar1;
  HANDLE pvStackY_3c;
  undefined4 uStackY_38;
  undefined4 uStackY_30;
  undefined *puStackY_2c;
  HANDLE local_10;
  undefined4 local_c;
  undefined2 uStack_8;

  local_10 = GetCurrentProcess();
  local_c = FUN_008feb72(param_2);
  puStackY_2c = (undefined *)0x901148;
  FUN_008f2450((int)&local_10,0x67);
  func_0x008f1f80();
  bVar1 = (POPCOUNT((uint)&stack0xffffffe4 & 0xff) & 1U) == 0;
  if ((!bVar1) && (bVar1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  puStackY_2c = &UNK_00901340;
  FUN_00900a72((undefined1 *)0x0);
  _DAT_0090b1f8 = 0;
  puStackY_2c = (undefined *)0x9073a0;
  uStackY_30 = 0x9073a8;
  pvStackY_3c = local_10;
  uStackY_38 = local_c;
  FUN_008ff065(&pvStackY_3c,uStack_8);
  _DAT_0090b1f8 = 0;
  puStackY_2c = &UNK_0090147d;
  func_0x008f2040();
  return;
}



/* VA 009014a0 */

undefined1 * __cdecl FUN_009014a0(undefined1 *param_1,undefined1 *param_2)

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



/* VA 00901500 */

undefined1 * __cdecl FUN_00901500(char *param_1)

{
  size_t sVar1;
  undefined1 *puVar2;

  sVar1 = _strlen(param_1);
  puVar2 = (undefined1 *)FUN_008f56c0(sVar1 + 1);
  if (puVar2 != (undefined1 *)0x0) {
    FUN_009014a0(puVar2,param_1);
  }
  return puVar2;
}



/* VA 0090153c */

uint __cdecl FUN_0090153c(char *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined4 local_c;

  pbVar1 = FUN_00901500(param_1);
  if (pbVar1 == (byte *)0x0) {
    local_c = 2;
  }
  else {
    local_c = FUN_008fbee0(pbVar1,param_2);
    FUN_008f5650(pbVar1);
  }
  return local_c;
}



/* VA 00901586 */

undefined1 * __cdecl FUN_00901586(undefined1 *param_1,undefined1 *param_2)

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



/* VA 009015e6 */

undefined1 * __cdecl FUN_009015e6(char *param_1)

{
  size_t sVar1;
  undefined1 *puVar2;

  sVar1 = _strlen(param_1);
  puVar2 = (undefined1 *)FUN_008f56c0(sVar1 + 1);
  if (puVar2 != (undefined1 *)0x0) {
    FUN_00901586(param_1,puVar2);
  }
  return puVar2;
}



/* VA 00901622 */

uint * __cdecl FUN_00901622(uint *param_1,char *param_2)

{
  char *pcVar1;
  undefined4 local_c;

  pcVar1 = FUN_00901500(param_2);
  if (pcVar1 == (char *)0x0) {
    local_c = (uint *)0x0;
  }
  else {
    local_c = FUN_008f5f70(param_1,pcVar1);
    FUN_008f5650(pcVar1);
  }
  return local_c;
}



/* VA 0090166c */

uint __cdecl FUN_0090166c(byte *param_1,char *param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  byte *local_14;
  byte *local_10;
  byte *local_c;

  pbVar1 = FUN_00901500(param_2);
  if (pbVar1 == (byte *)0x0) {
    local_c = (byte *)0x0;
  }
  else {
    for (local_c = param_1; *local_c != 0; local_c = local_c + 1) {
      local_10 = local_c;
      for (local_14 = pbVar1; *local_14 != 0; local_14 = local_14 + 1) {
        uVar2 = FUN_008f5ff0((uint)*local_14);
        uVar3 = FUN_008f5ff0((uint)*local_10);
        if (uVar2 != uVar3) break;
        local_10 = local_10 + 1;
      }
      if (*local_14 == 0) break;
    }
    local_c = (byte *)(-(uint)(*local_c != 0) & (uint)local_c);
    FUN_008f5650(pbVar1);
  }
  return (uint)local_c;
}



/* VA 00901740 */

undefined4 __cdecl FUN_00901740(int param_1,undefined4 param_2,int *param_3)

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
    hModule = LoadLibraryExA(s_drvmgt_dll_00907414,(HANDLE)0x0,8);
    if (hModule == (HMODULE)0x0) {
      uVar2 = 0;
    }
    else {
      if ((DAT_0090b200 == (FARPROC)0x0) &&
         (DAT_0090b200 = GetProcAddress(hModule,s_Setup_00907420), DAT_0090b200 == (FARPROC)0x0)) {
        return 0;
      }
      if ((DAT_0090b204 == (FARPROC)0x0) &&
         (DAT_0090b204 = GetProcAddress(hModule,s_Remove_00907428), DAT_0090b204 == (FARPROC)0x0)) {
        return 0;
      }
      GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_108,0x104);
      FUN_008f6180(local_108,(byte *)0x0,(byte *)0x0,local_208,(byte *)0x0);
      if (param_1 == 0xfa) {
        iVar3 = (*DAT_0090b200)(local_208,param_2);
        *param_3 = iVar3;
      }
      else {
        if (param_1 != 0xfb) {
          return param_1 & 0xffff0000;
        }
        iVar3 = (*DAT_0090b204)(local_208);
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



/* VA 00901890 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009019a5) overlaps instruction at (ram,0x009019a4)
    */
/* WARNING: Removing unreachable block (ram,0x00901983) */
/* WARNING: Removing unreachable block (ram,0x00901987) */
/* WARNING: Removing unreachable block (ram,0x0090199b) */
/* WARNING: Removing unreachable block (ram,0x0090199f) */
/* WARNING: Removing unreachable block (ram,0x0090192b) */
/* WARNING: Removing unreachable block (ram,0x0090192f) */
/* WARNING: Removing unreachable block (ram,0x0090198f) */
/* WARNING: Removing unreachable block (ram,0x00901993) */
/* WARNING: Removing unreachable block (ram,0x009019df) */
/* WARNING: Removing unreachable block (ram,0x0090191a) */
/* WARNING: Removing unreachable block (ram,0x00901902) */
/* WARNING: Removing unreachable block (ram,0x009018a7) */
/* WARNING: Removing unreachable block (ram,0x009018b3) */
/* WARNING: Removing unreachable block (ram,0x009018bf) */
/* WARNING: Removing unreachable block (ram,0x009018f6) */
/* WARNING: Removing unreachable block (ram,0x0090190e) */
/* WARNING: Removing unreachable block (ram,0x009019d3) */
/* WARNING: Removing unreachable block (ram,0x009019c7) */
/* WARNING: Removing unreachable block (ram,0x00901947) */
/* WARNING: Removing unreachable block (ram,0x00901937) */
/* WARNING: Removing unreachable block (ram,0x0090193b) */
/* WARNING: Removing unreachable block (ram,0x00901953) */
/* WARNING: Removing unreachable block (ram,0x00901943) */
/* WARNING: Removing unreachable block (ram,0x009018cb) */

undefined2 __cdecl FUN_00901890(uint *param_1)

{
  BOOL BVar1;
  undefined4 extraout_ECX;
  uint *unaff_EDI;
  undefined8 uVar2;
  _OSVERSIONINFOA local_98;

  local_98.dwOSVersionInfoSize = 0x94;
                    /* WARNING: Bad instruction - Truncating control flow here */
  BVar1 = GetVersionExA(&local_98);
  if (BVar1 != 0) {
    if (local_98.dwPlatformId == 1) {
      uVar2 = FUN_0090474e(param_1,unaff_EDI);
      return (short)uVar2;
    }
    if (local_98.dwPlatformId == 2) {
      uVar2 = FUN_0090272f(extraout_ECX,(short)param_1,param_1);
      return (short)uVar2;
    }
  }
  *param_1 = *param_1 & 0xff;
  return 1;
}



/* VA 009019fb */

/* WARNING: Instruction at (ram,0x00901ae8) overlaps instruction at (ram,0x00901ae7)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00901aca) */
/* WARNING: Removing unreachable block (ram,0x00901ae2) */
/* WARNING: Removing unreachable block (ram,0x00901ad6) */
/* WARNING: Removing unreachable block (ram,0x00901b12) */
/* WARNING: Removing unreachable block (ram,0x00901b16) */
/* WARNING: Removing unreachable block (ram,0x00901c11) */
/* WARNING: Removing unreachable block (ram,0x00901bf9) */
/* WARNING: Removing unreachable block (ram,0x00901bd1) */
/* WARNING: Removing unreachable block (ram,0x00901bb9) */
/* WARNING: Removing unreachable block (ram,0x00901ba1) */
/* WARNING: Removing unreachable block (ram,0x00901b89) */
/* WARNING: Removing unreachable block (ram,0x00901b46) */
/* WARNING: Removing unreachable block (ram,0x00901b1e) */
/* WARNING: Removing unreachable block (ram,0x00901b22) */
/* WARNING: Removing unreachable block (ram,0x00901a9d) */
/* WARNING: Removing unreachable block (ram,0x00901a7c) */
/* WARNING: Removing unreachable block (ram,0x00901a42) */
/* WARNING: Removing unreachable block (ram,0x00901a2a) */
/* WARNING: Removing unreachable block (ram,0x00901a12) */
/* WARNING: Removing unreachable block (ram,0x00901a4e) */
/* WARNING: Removing unreachable block (ram,0x00901a64) */
/* WARNING: Removing unreachable block (ram,0x00901aa9) */
/* WARNING: Removing unreachable block (ram,0x00901b2a) */
/* WARNING: Removing unreachable block (ram,0x00901b2e) */
/* WARNING: Removing unreachable block (ram,0x00901b3a) */
/* WARNING: Removing unreachable block (ram,0x00901b52) */
/* WARNING: Removing unreachable block (ram,0x00901b95) */
/* WARNING: Removing unreachable block (ram,0x00901bad) */
/* WARNING: Removing unreachable block (ram,0x00901bc5) */
/* WARNING: Removing unreachable block (ram,0x00901bdd) */
/* WARNING: Removing unreachable block (ram,0x00901c05) */
/* WARNING: Removing unreachable block (ram,0x00901c1d) */
/* WARNING: Removing unreachable block (ram,0x00901c29) */
/* WARNING: Removing unreachable block (ram,0x00901a36) */
/* WARNING: Removing unreachable block (ram,0x00901b4e) */
/* WARNING: Removing unreachable block (ram,0x00901b36) */
/* WARNING: Removing unreachable block (ram,0x00901b42) */
/* WARNING: Removing unreachable block (ram,0x00901a1e) */
/* WARNING: Removing unreachable block (ram,0x00901c35) */
/* WARNING: Removing unreachable block (ram,0x00901a70) */
/* WARNING: Removing unreachable block (ram,0x00901ab5) */
/* WARNING: Removing unreachable block (ram,0x00901ac6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_009019fb(uint *param_1)

{
  BOOL BVar1;
  uint uVar2;
  void *this;
  uint extraout_EDX;
  bool bVar3;
  undefined8 uVar4;
  _OSVERSIONINFOA local_98;

  local_98.dwOSVersionInfoSize = 0x94;
  BVar1 = GetVersionExA(&local_98);
  uVar2 = 0;
  if (BVar1 != 0) {
    if (local_98.dwPlatformId == 1) {
      uVar4 = FUN_00905073((uint)param_1,extraout_EDX);
      return (uint)uVar4;
    }
    uVar2 = local_98.dwPlatformId - 2;
    if (uVar2 == 0) {
      uVar2 = FUN_00902f05(this,param_1);
      return uVar2;
    }
  }
  bVar3 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *param_1 = *param_1 & 0xff;
  return CONCAT22((short)((uint)param_1 >> 0x10),1);
}



/* VA 00901c41 */

/* WARNING: Instruction at (ram,0x00901fde) overlaps instruction at (ram,0x00901fdd)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00901f98) */
/* WARNING: Removing unreachable block (ram,0x00901f9c) */
/* WARNING: Removing unreachable block (ram,0x00901f74) */
/* WARNING: Removing unreachable block (ram,0x00901f78) */
/* WARNING: Removing unreachable block (ram,0x00901f8c) */
/* WARNING: Removing unreachable block (ram,0x00901f90) */
/* WARNING: Removing unreachable block (ram,0x00902078) */
/* WARNING: Removing unreachable block (ram,0x0090207c) */
/* WARNING: Removing unreachable block (ram,0x009021b8) */
/* WARNING: Removing unreachable block (ram,0x009021ac) */
/* WARNING: Removing unreachable block (ram,0x00902170) */
/* WARNING: Removing unreachable block (ram,0x0090217c) */
/* WARNING: Removing unreachable block (ram,0x0090213c) */
/* WARNING: Removing unreachable block (ram,0x00902118) */
/* WARNING: Removing unreachable block (ram,0x009020f4) */
/* WARNING: Removing unreachable block (ram,0x009020dc) */
/* WARNING: Removing unreachable block (ram,0x009020c4) */
/* WARNING: Removing unreachable block (ram,0x0090209c) */
/* WARNING: Removing unreachable block (ram,0x009020a0) */
/* WARNING: Removing unreachable block (ram,0x00902090) */
/* WARNING: Removing unreachable block (ram,0x00902094) */
/* WARNING: Removing unreachable block (ram,0x00902063) */
/* WARNING: Removing unreachable block (ram,0x0090204b) */
/* WARNING: Removing unreachable block (ram,0x00902033) */
/* WARNING: Removing unreachable block (ram,0x00901fd8) */
/* WARNING: Removing unreachable block (ram,0x00901fe0) */
/* WARNING: Removing unreachable block (ram,0x00901fc0) */
/* WARNING: Removing unreachable block (ram,0x00901f80) */
/* WARNING: Removing unreachable block (ram,0x00901f53) */
/* WARNING: Removing unreachable block (ram,0x00901f3b) */
/* WARNING: Removing unreachable block (ram,0x00901f23) */
/* WARNING: Removing unreachable block (ram,0x00901f17) */
/* WARNING: Removing unreachable block (ram,0x00901eff) */
/* WARNING: Removing unreachable block (ram,0x00901ee7) */
/* WARNING: Removing unreachable block (ram,0x00901ecf) */
/* WARNING: Removing unreachable block (ram,0x00901eb7) */
/* WARNING: Removing unreachable block (ram,0x00901e9f) */
/* WARNING: Removing unreachable block (ram,0x00901e72) */
/* WARNING: Removing unreachable block (ram,0x00901e1e) */
/* WARNING: Removing unreachable block (ram,0x00901e06) */
/* WARNING: Removing unreachable block (ram,0x00901dee) */
/* WARNING: Removing unreachable block (ram,0x00901dd6) */
/* WARNING: Removing unreachable block (ram,0x00901dbe) */
/* WARNING: Removing unreachable block (ram,0x00901da6) */
/* WARNING: Removing unreachable block (ram,0x00901d8e) */
/* WARNING: Removing unreachable block (ram,0x00901d76) */
/* WARNING: Removing unreachable block (ram,0x00901d5e) */
/* WARNING: Removing unreachable block (ram,0x00901d3a) */
/* WARNING: Removing unreachable block (ram,0x00901d18) */
/* WARNING: Removing unreachable block (ram,0x00901d00) */
/* WARNING: Removing unreachable block (ram,0x00901ce8) */
/* WARNING: Removing unreachable block (ram,0x00901cd0) */
/* WARNING: Removing unreachable block (ram,0x00901cb8) */
/* WARNING: Removing unreachable block (ram,0x00901ca0) */
/* WARNING: Removing unreachable block (ram,0x00901c7c) */
/* WARNING: Removing unreachable block (ram,0x00901c58) */
/* WARNING: Removing unreachable block (ram,0x00901c70) */
/* WARNING: Removing unreachable block (ram,0x00901c94) */
/* WARNING: Removing unreachable block (ram,0x00901cac) */
/* WARNING: Removing unreachable block (ram,0x00901cc4) */
/* WARNING: Removing unreachable block (ram,0x00901cdc) */
/* WARNING: Removing unreachable block (ram,0x00901cf4) */
/* WARNING: Removing unreachable block (ram,0x00901d0c) */
/* WARNING: Removing unreachable block (ram,0x00901d24) */
/* WARNING: Removing unreachable block (ram,0x00901d52) */
/* WARNING: Removing unreachable block (ram,0x00901d9a) */
/* WARNING: Removing unreachable block (ram,0x00901db2) */
/* WARNING: Removing unreachable block (ram,0x00901dca) */
/* WARNING: Removing unreachable block (ram,0x00901de2) */
/* WARNING: Removing unreachable block (ram,0x00901dfa) */
/* WARNING: Removing unreachable block (ram,0x00901e12) */
/* WARNING: Removing unreachable block (ram,0x00901e2a) */
/* WARNING: Removing unreachable block (ram,0x00901e4e) */
/* WARNING: Removing unreachable block (ram,0x00901e66) */
/* WARNING: Removing unreachable block (ram,0x00901e93) */
/* WARNING: Removing unreachable block (ram,0x00901eab) */
/* WARNING: Removing unreachable block (ram,0x00901ec3) */
/* WARNING: Removing unreachable block (ram,0x00901edb) */
/* WARNING: Removing unreachable block (ram,0x00901ef3) */
/* WARNING: Removing unreachable block (ram,0x00901f0b) */
/* WARNING: Removing unreachable block (ram,0x00901f47) */
/* WARNING: Removing unreachable block (ram,0x00901f5f) */
/* WARNING: Removing unreachable block (ram,0x00901fb4) */
/* WARNING: Removing unreachable block (ram,0x00901fcc) */
/* WARNING: Removing unreachable block (ram,0x0090200f) */
/* WARNING: Removing unreachable block (ram,0x00902003) */
/* WARNING: Removing unreachable block (ram,0x00902027) */
/* WARNING: Removing unreachable block (ram,0x0090203f) */
/* WARNING: Removing unreachable block (ram,0x00902057) */
/* WARNING: Removing unreachable block (ram,0x00902084) */
/* WARNING: Removing unreachable block (ram,0x00902088) */
/* WARNING: Removing unreachable block (ram,0x009020a8) */
/* WARNING: Removing unreachable block (ram,0x009020ac) */
/* WARNING: Removing unreachable block (ram,0x009020d0) */
/* WARNING: Removing unreachable block (ram,0x009020e8) */
/* WARNING: Removing unreachable block (ram,0x00902100) */
/* WARNING: Removing unreachable block (ram,0x00902130) */
/* WARNING: Removing unreachable block (ram,0x00902148) */
/* WARNING: Removing unreachable block (ram,0x00902188) */
/* WARNING: Removing unreachable block (ram,0x009021a0) */
/* WARNING: Removing unreachable block (ram,0x009021d0) */
/* WARNING: Removing unreachable block (ram,0x00902108) */
/* WARNING: Removing unreachable block (ram,0x0090210c) */
/* WARNING: Removing unreachable block (ram,0x00902194) */
/* WARNING: Removing unreachable block (ram,0x00901fa4) */
/* WARNING: Removing unreachable block (ram,0x00901fa8) */
/* WARNING: Removing unreachable block (ram,0x00901e5a) */
/* WARNING: Removing unreachable block (ram,0x009020b4) */
/* WARNING: Removing unreachable block (ram,0x009020b8) */
/* WARNING: Removing unreachable block (ram,0x00901c64) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff64 : 0x0090215c */
/* WARNING: Removing unreachable block (ram,0x00901fbc) */
/* WARNING: Removing unreachable block (ram,0x00902120) */
/* WARNING: Removing unreachable block (ram,0x00902124) */
/* WARNING: Removing unreachable block (ram,0x009020f0) */
/* WARNING: Removing unreachable block (ram,0x009020e4) */
/* WARNING: Removing unreachable block (ram,0x009020d8) */
/* WARNING: Removing unreachable block (ram,0x00901f2f) */
/* WARNING: Removing unreachable block (ram,0x00901d82) */
/* WARNING: Removing unreachable block (ram,0x00901c88) */
/* WARNING: Removing unreachable block (ram,0x009021c4) */
/* WARNING: Removing unreachable block (ram,0x009020c0) */
/* WARNING: Removing unreachable block (ram,0x009020fc) */
/* WARNING: Removing unreachable block (ram,0x00902114) */
/* WARNING: Removing unreachable block (ram,0x0090212c) */
/* WARNING: Removing unreachable block (ram,0x00901fb0) */
/* WARNING: Removing unreachable block (ram,0x00901e36) */
/* WARNING: Removing unreachable block (ram,0x00901d46) */
/* WARNING: Removing unreachable block (ram,0x0090201b) */
/* WARNING: Removing unreachable block (ram,0x00902138) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int * __fastcall FUN_00901c41(byte param_1,undefined2 param_2)

{
  BOOL BVar1;
  uint *puVar2;
  int *piVar3;
  byte extraout_CL;
  undefined2 extraout_DX;
  bool bVar4;
  uint in_stack_00000004;
  undefined1 local_9c [4];
  _OSVERSIONINFOA local_98;

  bVar4 = (POPCOUNT((uint)local_9c & 0xff) & 1U) == 0;
  if ((!bVar4) && (bVar4)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((!bVar4) && (bVar4)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  local_98.dwOSVersionInfoSize = 0x94;
  local_98.szCSDVersion[0x7c] = -0x80;
  local_98.szCSDVersion[0x7d] = '\x1e';
  local_98.szCSDVersion[0x7e] = -0x70;
  local_98.szCSDVersion[0x7f] = '\0';
  BVar1 = GetVersionExA(&local_98);
  if (BVar1 != 0) {
    if (local_98.dwPlatformId == 1) {
      local_98.szCSDVersion[0x7c] = -0x1e;
      local_98.szCSDVersion[0x7d] = '\x1f';
      local_98.szCSDVersion[0x7e] = -0x70;
      local_98.szCSDVersion[0x7f] = '\0';
      puVar2 = FUN_00905760(in_stack_00000004,extraout_DX);
      return (int *)puVar2;
    }
    if (local_98.dwPlatformId == 2) {
      piVar3 = (int *)FUN_00903827(extraout_CL);
      return piVar3;
    }
  }
  return (int *)CONCAT22((short)((uint)BVar1 >> 0x10),1);
}



/* VA 009021dc */

/* WARNING: Instruction at (ram,0x00902579) overlaps instruction at (ram,0x00902578)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0090250f) */
/* WARNING: Removing unreachable block (ram,0x00902513) */
/* WARNING: Removing unreachable block (ram,0x00902527) */
/* WARNING: Removing unreachable block (ram,0x0090252b) */
/* WARNING: Removing unreachable block (ram,0x0090254f) */
/* WARNING: Removing unreachable block (ram,0x00902537) */
/* WARNING: Removing unreachable block (ram,0x00902673) */
/* WARNING: Removing unreachable block (ram,0x0090265b) */
/* WARNING: Removing unreachable block (ram,0x00902643) */
/* WARNING: Removing unreachable block (ram,0x0090262b) */
/* WARNING: Removing unreachable block (ram,0x009025f2) */
/* WARNING: Removing unreachable block (ram,0x009025c2) */
/* WARNING: Removing unreachable block (ram,0x009025aa) */
/* WARNING: Removing unreachable block (ram,0x009024ee) */
/* WARNING: Removing unreachable block (ram,0x009024e2) */
/* WARNING: Removing unreachable block (ram,0x009024a6) */
/* WARNING: Removing unreachable block (ram,0x0090248e) */
/* WARNING: Removing unreachable block (ram,0x00902476) */
/* WARNING: Removing unreachable block (ram,0x0090245e) */
/* WARNING: Removing unreachable block (ram,0x00902446) */
/* WARNING: Removing unreachable block (ram,0x0090242e) */
/* WARNING: Removing unreachable block (ram,0x0090240d) */
/* WARNING: Removing unreachable block (ram,0x00902401) */
/* WARNING: Removing unreachable block (ram,0x009023e9) */
/* WARNING: Removing unreachable block (ram,0x009023c5) */
/* WARNING: Removing unreachable block (ram,0x009023ad) */
/* WARNING: Removing unreachable block (ram,0x00902395) */
/* WARNING: Removing unreachable block (ram,0x0090237d) */
/* WARNING: Removing unreachable block (ram,0x00902365) */
/* WARNING: Removing unreachable block (ram,0x00902329) */
/* WARNING: Removing unreachable block (ram,0x00902311) */
/* WARNING: Removing unreachable block (ram,0x009022f9) */
/* WARNING: Removing unreachable block (ram,0x009022d5) */
/* WARNING: Removing unreachable block (ram,0x009022b3) */
/* WARNING: Removing unreachable block (ram,0x0090229b) */
/* WARNING: Removing unreachable block (ram,0x0090228f) */
/* WARNING: Removing unreachable block (ram,0x00902277) */
/* WARNING: Removing unreachable block (ram,0x0090225f) */
/* WARNING: Removing unreachable block (ram,0x00902247) */
/* WARNING: Removing unreachable block (ram,0x0090222f) */
/* WARNING: Removing unreachable block (ram,0x00902217) */
/* WARNING: Removing unreachable block (ram,0x009021f3) */
/* WARNING: Removing unreachable block (ram,0x0090220b) */
/* WARNING: Removing unreachable block (ram,0x00902223) */
/* WARNING: Removing unreachable block (ram,0x0090223b) */
/* WARNING: Removing unreachable block (ram,0x00902253) */
/* WARNING: Removing unreachable block (ram,0x0090226b) */
/* WARNING: Removing unreachable block (ram,0x00902283) */
/* WARNING: Removing unreachable block (ram,0x009022bf) */
/* WARNING: Removing unreachable block (ram,0x009022e1) */
/* WARNING: Removing unreachable block (ram,0x00902305) */
/* WARNING: Removing unreachable block (ram,0x0090231d) */
/* WARNING: Removing unreachable block (ram,0x00902335) */
/* WARNING: Removing unreachable block (ram,0x00902341) */
/* WARNING: Removing unreachable block (ram,0x00902359) */
/* WARNING: Removing unreachable block (ram,0x00902371) */
/* WARNING: Removing unreachable block (ram,0x00902389) */
/* WARNING: Removing unreachable block (ram,0x009023a1) */
/* WARNING: Removing unreachable block (ram,0x009023b9) */
/* WARNING: Removing unreachable block (ram,0x009023dd) */
/* WARNING: Removing unreachable block (ram,0x009023f5) */
/* WARNING: Removing unreachable block (ram,0x0090243a) */
/* WARNING: Removing unreachable block (ram,0x00902452) */
/* WARNING: Removing unreachable block (ram,0x0090246a) */
/* WARNING: Removing unreachable block (ram,0x00902482) */
/* WARNING: Removing unreachable block (ram,0x0090249a) */
/* WARNING: Removing unreachable block (ram,0x009024b2) */
/* WARNING: Removing unreachable block (ram,0x009024be) */
/* WARNING: Removing unreachable block (ram,0x009024d6) */
/* WARNING: Removing unreachable block (ram,0x0090259e) */
/* WARNING: Removing unreachable block (ram,0x009025b6) */
/* WARNING: Removing unreachable block (ram,0x009025da) */
/* WARNING: Removing unreachable block (ram,0x009025fe) */
/* WARNING: Removing unreachable block (ram,0x00902637) */
/* WARNING: Removing unreachable block (ram,0x0090264f) */
/* WARNING: Removing unreachable block (ram,0x00902667) */
/* WARNING: Removing unreachable block (ram,0x0090267f) */
/* WARNING: Removing unreachable block (ram,0x0090251b) */
/* WARNING: Removing unreachable block (ram,0x0090251f) */
/* WARNING: Removing unreachable block (ram,0x0090255b) */
/* WARNING: Removing unreachable block (ram,0x00902567) */
/* WARNING: Removing unreachable block (ram,0x0090256f) */
/* WARNING: Removing unreachable block (ram,0x00902573) */
/* WARNING: Removing unreachable block (ram,0x00902557) */
/* WARNING: Removing unreachable block (ram,0x00902543) */
/* WARNING: Removing unreachable block (ram,0x00902533) */
/* WARNING: Removing unreachable block (ram,0x0090254b) */
/* WARNING: Removing unreachable block (ram,0x00902563) */
/* WARNING: Removing unreachable block (ram,0x009021ff) */
/* WARNING: Removing unreachable block (ram,0x009023d1) */
/* WARNING: Removing unreachable block (ram,0x0090268b) */
/* WARNING: Removing unreachable block (ram,0x009024fa) */
/* WARNING: Removing unreachable block (ram,0x009022a7) */
/* WARNING: Removing unreachable block (ram,0x009022ed) */
/* WARNING: Removing unreachable block (ram,0x009024ca) */
/* WARNING: Removing unreachable block (ram,0x009025ce) */
/* WARNING: Removing unreachable block (ram,0x0090234d) */
/* WARNING: Removing unreachable block (ram,0x009025e6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_009021dc(void *this,int param_1)

{
  BOOL BVar1;
  int *piVar2;
  uint uVar3;
  undefined4 extraout_ECX;
  _OSVERSIONINFOA _Stack_98;

  _Stack_98.dwOSVersionInfoSize = 0x94;
  BVar1 = GetVersionExA(&_Stack_98);
  if (BVar1 != 0) {
    if (_Stack_98.dwPlatformId == 1) {
      piVar2 = (int *)func_0x008f0f70(param_1);
      return piVar2;
    }
    if (_Stack_98.dwPlatformId == 2) {
      uVar3 = FUN_008f0950(extraout_ECX,param_1);
      return (int *)(uVar3 & 0xffff0000);
    }
  }
  return (int *)CONCAT22((short)((uint)BVar1 >> 0x10),1);
}



/* VA 009026a0 */

uint __cdecl
FUN_009026a0(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,uint param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined3 extraout_var_00;
  uint local_8;

  bVar1 = FUN_008f4fd3();
  if ((CONCAT31(extraout_var,bVar1) & 0xffff) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_008f50bc();
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_008f521a(param_1,param_2,param_3,&local_8);
      if ((uVar2 & 0xffff) == 0) {
        uVar2 = 0;
      }
      else {
        bVar1 = FUN_008f5048();
        if ((CONCAT31(extraout_var_00,bVar1) & 0xffff) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_008f526f(param_4,param_5,(int *)&local_8);
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



/* VA 0090272f */

/* WARNING: Instruction at (ram,0x00902ec6) overlaps instruction at (ram,0x00902ec4)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00902def) */
/* WARNING: Removing unreachable block (ram,0x00902dd7) */
/* WARNING: Removing unreachable block (ram,0x00902cfd) */
/* WARNING: Removing unreachable block (ram,0x00902d01) */
/* WARNING: Removing unreachable block (ram,0x009029bd) */
/* WARNING: Removing unreachable block (ram,0x009029c1) */
/* WARNING: Removing unreachable block (ram,0x00902dcb) */
/* WARNING: Removing unreachable block (ram,0x00902de3) */
/* WARNING: Removing unreachable block (ram,0x00902db0) */
/* WARNING: Removing unreachable block (ram,0x00902ed5) */
/* WARNING: Removing unreachable block (ram,0x00902eb7) */
/* WARNING: Removing unreachable block (ram,0x00902e9f) */
/* WARNING: Removing unreachable block (ram,0x00902e74) */
/* WARNING: Removing unreachable block (ram,0x00902e68) */
/* WARNING: Removing unreachable block (ram,0x00902e3e) */
/* WARNING: Removing unreachable block (ram,0x00902e26) */
/* WARNING: Removing unreachable block (ram,0x00902d70) */
/* WARNING: Removing unreachable block (ram,0x00902d46) */
/* WARNING: Removing unreachable block (ram,0x00902d25) */
/* WARNING: Removing unreachable block (ram,0x00902d09) */
/* WARNING: Removing unreachable block (ram,0x00902ce0) */
/* WARNING: Removing unreachable block (ram,0x00902ca7) */
/* WARNING: Removing unreachable block (ram,0x00902c9b) */
/* WARNING: Removing unreachable block (ram,0x00902c12) */
/* WARNING: Removing unreachable block (ram,0x00902bfa) */
/* WARNING: Removing unreachable block (ram,0x00902ba5) */
/* WARNING: Removing unreachable block (ram,0x00902baf) */
/* WARNING: Removing unreachable block (ram,0x00902b3f) */
/* WARNING: Removing unreachable block (ram,0x00902b16) */
/* WARNING: Removing unreachable block (ram,0x00902aea) */
/* WARNING: Removing unreachable block (ram,0x00902aac) */
/* WARNING: Removing unreachable block (ram,0x00902a88) */
/* WARNING: Removing unreachable block (ram,0x00902a5c) */
/* WARNING: Removing unreachable block (ram,0x00902a12) */
/* WARNING: Removing unreachable block (ram,0x00902a06) */
/* WARNING: Removing unreachable block (ram,0x009029d9) */
/* WARNING: Removing unreachable block (ram,0x009029a6) */
/* WARNING: Removing unreachable block (ram,0x0090298e) */
/* WARNING: Removing unreachable block (ram,0x00902959) */
/* WARNING: Removing unreachable block (ram,0x00902941) */
/* WARNING: Removing unreachable block (ram,0x009028de) */
/* WARNING: Removing unreachable block (ram,0x009028d2) */
/* WARNING: Removing unreachable block (ram,0x0090287b) */
/* WARNING: Removing unreachable block (ram,0x0090282f) */
/* WARNING: Removing unreachable block (ram,0x00902810) */
/* WARNING: Removing unreachable block (ram,0x009027e0) */
/* WARNING: Removing unreachable block (ram,0x009027c8) */
/* WARNING: Removing unreachable block (ram,0x009027b0) */
/* WARNING: Removing unreachable block (ram,0x00902798) */
/* WARNING: Removing unreachable block (ram,0x00902780) */
/* WARNING: Removing unreachable block (ram,0x00902768) */
/* WARNING: Removing unreachable block (ram,0x00902750) */
/* WARNING: Removing unreachable block (ram,0x0090275c) */
/* WARNING: Removing unreachable block (ram,0x00902774) */
/* WARNING: Removing unreachable block (ram,0x0090278c) */
/* WARNING: Removing unreachable block (ram,0x009027a4) */
/* WARNING: Removing unreachable block (ram,0x009027bc) */
/* WARNING: Removing unreachable block (ram,0x009027d4) */
/* WARNING: Removing unreachable block (ram,0x009027ec) */
/* WARNING: Removing unreachable block (ram,0x009027f8) */
/* WARNING: Removing unreachable block (ram,0x0090283b) */
/* WARNING: Removing unreachable block (ram,0x00902847) */
/* WARNING: Removing unreachable block (ram,0x0090289a) */
/* WARNING: Removing unreachable block (ram,0x009028c6) */
/* WARNING: Removing unreachable block (ram,0x009028f6) */
/* WARNING: Removing unreachable block (ram,0x00902935) */
/* WARNING: Removing unreachable block (ram,0x0090294d) */
/* WARNING: Removing unreachable block (ram,0x00902982) */
/* WARNING: Removing unreachable block (ram,0x0090299a) */
/* WARNING: Removing unreachable block (ram,0x009029c9) */
/* WARNING: Removing unreachable block (ram,0x009029fa) */
/* WARNING: Removing unreachable block (ram,0x00902a3d) */
/* WARNING: Removing unreachable block (ram,0x00902a94) */
/* WARNING: Removing unreachable block (ram,0x00902ab8) */
/* WARNING: Removing unreachable block (ram,0x00902ac4) */
/* WARNING: Removing unreachable block (ram,0x00902b22) */
/* WARNING: Removing unreachable block (ram,0x00902b5f) */
/* WARNING: Removing unreachable block (ram,0x00902bc9) */
/* WARNING: Removing unreachable block (ram,0x00902c1e) */
/* WARNING: Removing unreachable block (ram,0x00902c64) */
/* WARNING: Removing unreachable block (ram,0x00902c8f) */
/* WARNING: Removing unreachable block (ram,0x00902cc8) */
/* WARNING: Removing unreachable block (ram,0x00902d19) */
/* WARNING: Removing unreachable block (ram,0x00902d3a) */
/* WARNING: Removing unreachable block (ram,0x00902d52) */
/* WARNING: Removing unreachable block (ram,0x00902d7c) */
/* WARNING: Removing unreachable block (ram,0x00902d88) */
/* WARNING: Removing unreachable block (ram,0x00902e1a) */
/* WARNING: Removing unreachable block (ram,0x00902e32) */
/* WARNING: Removing unreachable block (ram,0x00902e5c) */
/* WARNING: Removing unreachable block (ram,0x00902eab) */
/* WARNING: Removing unreachable block (ram,0x00902ec3) */
/* WARNING: Removing unreachable block (ram,0x00902ee1) */
/* WARNING: Removing unreachable block (ram,0x00902eed) */
/* WARNING: Removing unreachable block (ram,0x00902cd4) */
/* WARNING: Removing unreachable block (ram,0x00902d15) */
/* WARNING: Removing unreachable block (ram,0x00902c06) */
/* WARNING: Removing unreachable block (ram,0x00902a1a) */
/* WARNING: Removing unreachable block (ram,0x00902a1e) */
/* WARNING: Removing unreachable block (ram,0x00902a0e) */
/* WARNING: Removing unreachable block (ram,0x00902b6b) */
/* WARNING: Removing unreachable block (ram,0x00902c58) */
/* WARNING: Removing unreachable block (ram,0x00902cec) */
/* WARNING: Removing unreachable block (ram,0x009029d5) */
/* WARNING: Removing unreachable block (ram,0x009029e5) */
/* WARNING: Removing unreachable block (ram,0x0090281c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000004 : 0x00902e85 */
/* WARNING: Removing unreachable block (ram,0x00902c2a) */
/* WARNING: Removing unreachable block (ram,0x00902ef9) */
/* WARNING: Removing unreachable block (ram,0x00902d36) */
/* WARNING: Removing unreachable block (ram,0x00902d5e) */
/* WARNING: Removing unreachable block (ram,0x00902b2e) */
/* WARNING: Removing unreachable block (ram,0x009029f6) */
/* WARNING: Removing unreachable block (ram,0x009028ea) */
/* WARNING: Removing unreachable block (ram,0x00902d21) */
/* WARNING: Removing unreachable block (ram,0x00902d94) */
/* WARNING: Removing unreachable block (ram,0x00902b77) */
/* WARNING: Removing unreachable block (ram,0x00902aa0) */
/* WARNING: Removing unreachable block (ram,0x00902853) */
/* WARNING: Removing unreachable block (ram,0x00902b99) */
/* WARNING: Removing unreachable block (ram,0x00902e50) */
/* WARNING: Removing unreachable block (ram,0x00902902) */
/* WARNING: Removing unreachable block (ram,0x00902c70) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_0090272f(undefined4 param_1,undefined2 param_2,uint *param_3)

{
  HANDLE pvVar1;
  BOOL BVar2;
  uint *puVar3;
  uint *puVar4;
  bool bVar5;
  undefined4 uVar6;
  int *piVar7;
  int iStack_d8;
  FARPROC pFStack_d4;
  LPCSTR local_d0;
  HANDLE local_cc;
  HMODULE local_c8;
  undefined1 *puStack_c4;
  FARPROC local_c0;
  LPCSTR local_bc;
  uint local_b8;
  LPCSTR local_b4;
  LPCSTR local_b0;
  uint local_ac;
  HMODULE local_a8;
  undefined1 *local_a4;
  _OSVERSIONINFOA local_a0;
  int local_c;
  ushort local_8;

  bVar5 = (POPCOUNT((uint)&iStack_d8 & 0xff) & 1U) == 0;
  local_cc = (HANDLE)0x0;
  if ((!bVar5) && (bVar5)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  local_c = 1;
  local_ac = CONCAT22(local_ac._2_2_,1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  local_bc = FUN_00901500(&DAT_00907430);
  local_c8 = GetModuleHandleA(local_bc);
  if (local_c8 != (HMODULE)0x0) {
    local_d0 = FUN_00901500(&DAT_00907440);
                    /* WARNING: Bad instruction - Truncating control flow here */
    pFStack_d4 = GetProcAddress(local_c8,local_d0);
    if (pFStack_d4 != (FARPROC)0x0) {
      piVar7 = &local_c;
      uVar6 = 7;
      pvVar1 = GetCurrentProcess();
      iStack_d8 = (*pFStack_d4)(pvVar1,uVar6,piVar7);
      if (local_c == 0) {
        local_ac = local_ac & 0xffff0000;
                    /* WARNING: Bad instruction - Truncating control flow here */
      }
    }
  }
  local_b4 = FUN_00901500(&DAT_009073b0);
  local_a8 = GetModuleHandleA(local_b4);
  if (local_a8 != (HMODULE)0x0) {
    local_b0 = FUN_00901500(&DAT_009073f0);
    local_c0 = GetProcAddress(local_a8,local_b0);
    if (local_c0 != (FARPROC)0x0) {
      local_a4 = FUN_00901500(&DAT_009073c0);
      local_cc = (HANDLE)(*local_c0)(local_a4,0xc0000000,3,0,3);
                    /* WARNING: Bad instruction - Truncating control flow here */
      if (local_cc == (HANDLE)0xffffffff) {
        puStack_c4 = FUN_00901500((char *)0x9073e0);
        local_cc = (HANDLE)(*local_c0)(puStack_c4,0xc0000000,3,0,3);
        bVar5 = (POPCOUNT((int)local_cc + 1U & 0xff) & 1U) == 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
        if ((((int)local_cc + 1U != 0) && (CloseHandle(local_cc), !bVar5)) && (bVar5)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      else {
        CloseHandle(local_cc);
      }
    }
  }
  local_b8 = CONCAT22(local_b8._2_2_,1);
  local_a0.dwOSVersionInfoSize = 0x94;
  BVar2 = GetVersionExA(&local_a0);
  if ((BVar2 != 0) && (local_a0.dwPlatformId == 2)) {
    local_b8 = 0;
  }
  local_8 = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  *param_3 = *param_3 & (uint)local_cc;
                    /* WARNING: Bad instruction - Truncating control flow here */
  if (local_cc != (HANDLE)0xffffffff) {
    local_8 = 1;
  }
  local_8 = (ushort)(local_cc != (HANDLE)0xffffffff);
                    /* WARNING: Could not recover jumptable at 0x00902df5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar3 = (uint *)0x0;
  puVar4 = param_3;
  if ((local_b8 & 0xffff) != 0) {
    puVar4 = (uint *)(*param_3 & 0xf3456732);
    *param_3 = (uint)puVar4;
    local_8 = 1;
    puVar3 = param_3;
  }
  if ((local_ac & 0xffff) != 0) {
    puVar3 = (uint *)(*param_3 & 0x53982fea);
    *param_3 = (uint)puVar3;
    local_8 = 1;
    puVar4 = param_3;
  }
  return CONCAT44(puVar4,CONCAT22((short)((uint)puVar3 >> 0x10),local_8));
}



/* VA 00902f05 */

/* WARNING: Instruction at (ram,0x009033db) overlaps instruction at (ram,0x009033da)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0090338e) */
/* WARNING: Removing unreachable block (ram,0x009031c0) */
/* WARNING: Removing unreachable block (ram,0x0090339a) */
/* WARNING: Removing unreachable block (ram,0x00903483) */
/* WARNING: Removing unreachable block (ram,0x00903487) */
/* WARNING: Removing unreachable block (ram,0x0090380f) */
/* WARNING: Removing unreachable block (ram,0x009037f7) */
/* WARNING: Removing unreachable block (ram,0x009037d3) */
/* WARNING: Removing unreachable block (ram,0x009037a6) */
/* WARNING: Removing unreachable block (ram,0x0090378e) */
/* WARNING: Removing unreachable block (ram,0x00903776) */
/* WARNING: Removing unreachable block (ram,0x0090375e) */
/* WARNING: Removing unreachable block (ram,0x00903746) */
/* WARNING: Removing unreachable block (ram,0x00903722) */
/* WARNING: Removing unreachable block (ram,0x0090370a) */
/* WARNING: Removing unreachable block (ram,0x009036f2) */
/* WARNING: Removing unreachable block (ram,0x009036da) */
/* WARNING: Removing unreachable block (ram,0x0090369e) */
/* WARNING: Removing unreachable block (ram,0x0090367a) */
/* WARNING: Removing unreachable block (ram,0x00903662) */
/* WARNING: Removing unreachable block (ram,0x0090364a) */
/* WARNING: Removing unreachable block (ram,0x0090363e) */
/* WARNING: Removing unreachable block (ram,0x009035f5) */
/* WARNING: Removing unreachable block (ram,0x0090356e) */
/* WARNING: Removing unreachable block (ram,0x00903526) */
/* WARNING: Removing unreachable block (ram,0x0090351a) */
/* WARNING: Removing unreachable block (ram,0x00903502) */
/* WARNING: Removing unreachable block (ram,0x009034cc) */
/* WARNING: Removing unreachable block (ram,0x0090349f) */
/* WARNING: Removing unreachable block (ram,0x00903466) */
/* WARNING: Removing unreachable block (ram,0x0090344e) */
/* WARNING: Removing unreachable block (ram,0x00903415) */
/* WARNING: Removing unreachable block (ram,0x009033c1) */
/* WARNING: Removing unreachable block (ram,0x009033cd) */
/* WARNING: Removing unreachable block (ram,0x0090334c) */
/* WARNING: Removing unreachable block (ram,0x009032c7) */
/* WARNING: Removing unreachable block (ram,0x00903277) */
/* WARNING: Removing unreachable block (ram,0x00903241) */
/* WARNING: Removing unreachable block (ram,0x00903235) */
/* WARNING: Removing unreachable block (ram,0x0090320b) */
/* WARNING: Removing unreachable block (ram,0x009031f3) */
/* WARNING: Removing unreachable block (ram,0x0090318f) */
/* WARNING: Removing unreachable block (ram,0x00903177) */
/* WARNING: Removing unreachable block (ram,0x0090313c) */
/* WARNING: Removing unreachable block (ram,0x00903130) */
/* WARNING: Removing unreachable block (ram,0x00903100) */
/* WARNING: Removing unreachable block (ram,0x009030a0) */
/* WARNING: Removing unreachable block (ram,0x00903081) */
/* WARNING: Removing unreachable block (ram,0x00903069) */
/* WARNING: Removing unreachable block (ram,0x00903051) */
/* WARNING: Removing unreachable block (ram,0x00903039) */
/* WARNING: Removing unreachable block (ram,0x00902fd4) */
/* WARNING: Removing unreachable block (ram,0x00902fbc) */
/* WARNING: Removing unreachable block (ram,0x00902fa4) */
/* WARNING: Removing unreachable block (ram,0x00902f58) */
/* WARNING: Removing unreachable block (ram,0x00902f40) */
/* WARNING: Removing unreachable block (ram,0x00902f4c) */
/* WARNING: Removing unreachable block (ram,0x00902fb0) */
/* WARNING: Removing unreachable block (ram,0x00902fc8) */
/* WARNING: Removing unreachable block (ram,0x00902fe0) */
/* WARNING: Removing unreachable block (ram,0x00903045) */
/* WARNING: Removing unreachable block (ram,0x0090305d) */
/* WARNING: Removing unreachable block (ram,0x00903075) */
/* WARNING: Removing unreachable block (ram,0x00903094) */
/* WARNING: Removing unreachable block (ram,0x009030ac) */
/* WARNING: Removing unreachable block (ram,0x009030dc) */
/* WARNING: Removing unreachable block (ram,0x009030f4) */
/* WARNING: Removing unreachable block (ram,0x00903124) */
/* WARNING: Removing unreachable block (ram,0x00903183) */
/* WARNING: Removing unreachable block (ram,0x0090319b) */
/* WARNING: Removing unreachable block (ram,0x009031cc) */
/* WARNING: Removing unreachable block (ram,0x009031e7) */
/* WARNING: Removing unreachable block (ram,0x009031ff) */
/* WARNING: Removing unreachable block (ram,0x00903229) */
/* WARNING: Removing unreachable block (ram,0x0090325f) */
/* WARNING: Removing unreachable block (ram,0x009032d3) */
/* WARNING: Removing unreachable block (ram,0x00903340) */
/* WARNING: Removing unreachable block (ram,0x009033b5) */
/* WARNING: Removing unreachable block (ram,0x00903358) */
/* WARNING: Removing unreachable block (ram,0x009033ea) */
/* WARNING: Removing unreachable block (ram,0x0090345a) */
/* WARNING: Removing unreachable block (ram,0x00903472) */
/* WARNING: Removing unreachable block (ram,0x0090348f) */
/* WARNING: Removing unreachable block (ram,0x00903493) */
/* WARNING: Removing unreachable block (ram,0x009034c0) */
/* WARNING: Removing unreachable block (ram,0x009034f6) */
/* WARNING: Removing unreachable block (ram,0x0090350e) */
/* WARNING: Removing unreachable block (ram,0x0090357a) */
/* WARNING: Removing unreachable block (ram,0x00903601) */
/* WARNING: Removing unreachable block (ram,0x0090360d) */
/* WARNING: Removing unreachable block (ram,0x00903632) */
/* WARNING: Removing unreachable block (ram,0x0090366e) */
/* WARNING: Removing unreachable block (ram,0x00903686) */
/* WARNING: Removing unreachable block (ram,0x009036aa) */
/* WARNING: Removing unreachable block (ram,0x009036b6) */
/* WARNING: Removing unreachable block (ram,0x009036ce) */
/* WARNING: Removing unreachable block (ram,0x009036e6) */
/* WARNING: Removing unreachable block (ram,0x009036fe) */
/* WARNING: Removing unreachable block (ram,0x00903716) */
/* WARNING: Removing unreachable block (ram,0x0090373a) */
/* WARNING: Removing unreachable block (ram,0x00903752) */
/* WARNING: Removing unreachable block (ram,0x0090376a) */
/* WARNING: Removing unreachable block (ram,0x00903782) */
/* WARNING: Removing unreachable block (ram,0x0090379a) */
/* WARNING: Removing unreachable block (ram,0x009037c7) */
/* WARNING: Removing unreachable block (ram,0x009037eb) */
/* WARNING: Removing unreachable block (ram,0x00903803) */
/* WARNING: Removing unreachable block (ram,0x00903283) */
/* WARNING: Removing unreachable block (ram,0x009033f6) */
/* WARNING: Removing unreachable block (ram,0x0090349b) */
/* WARNING: Removing unreachable block (ram,0x00902f64) */
/* WARNING: Removing unreachable block (ram,0x00903421) */
/* WARNING: Removing unreachable block (ram,0x009032df) */
/* WARNING: Removing unreachable block (ram,0x0090326b) */
/* WARNING: Removing unreachable block (ram,0x009030e8) */
/* WARNING: Removing unreachable block (ram,0x009033d9) */
/* WARNING: Removing unreachable block (ram,0x00903692) */
/* WARNING: Removing unreachable block (ram,0x0090381b) */
/* WARNING: Removing unreachable block (ram,0x0090381f) */
/* WARNING: Removing unreachable block (ram,0x0090372e) */
/* WARNING: Removing unreachable block (ram,0x00903619) */
/* WARNING: Removing unreachable block (ram,0x009034e0) */
/* WARNING: Removing unreachable block (ram,0x009034e4) */
/* WARNING: Removing unreachable block (ram,0x009034a7) */
/* WARNING: Removing unreachable block (ram,0x009034ab) */
/* WARNING: Removing unreachable block (ram,0x00902fec) */
/* WARNING: Removing unreachable block (ram,0x00902f7c) */
/* WARNING: Removing unreachable block (ram,0x00902f8a) */
/* WARNING: Removing unreachable block (ram,0x00902f8e) */
/* WARNING: Removing unreachable block (ram,0x0090310c) */
/* WARNING: Removing unreachable block (ram,0x009034bc) */
/* WARNING: Removing unreachable block (ram,0x009034d8) */
/* WARNING: Removing unreachable block (ram,0x009037df) */
/* WARNING: Removing unreachable block (ram,0x009036c2) */
/* WARNING: Removing unreachable block (ram,0x00903656) */
/* WARNING: Removing unreachable block (ram,0x00903532) */
/* WARNING: Removing unreachable block (ram,0x0090342d) */
/* WARNING: Removing unreachable block (ram,0x00903364) */
/* WARNING: Removing unreachable block (ram,0x00902f34) */
/* WARNING: Removing unreachable block (ram,0x00903118) */
/* WARNING: Removing unreachable block (ram,0x00902ff8) */
/* WARNING: Removing unreachable block (ram,0x00902f28) */
/* WARNING: Removing unreachable block (ram,0x00902f1c) */
/* WARNING: Removing unreachable block (ram,0x00902f70) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint __thiscall FUN_00902f05(void *this,uint *param_1)

{
  int *piVar1;
  LPCSTR pCVar2;
  HMODULE hModule;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  uint *puVar6;
  char cVar7;
  undefined4 unaff_EBX;
  undefined **unaff_EDI;
  int unaff_FS_OFFSET;
  undefined1 uVar8;
  bool bVar9;
  undefined4 in_stack_ffffff2c;
  uint uStack_c4;
  uint uStack_c0;
  uint local_bc;
  uint local_b8;
  LPCSTR local_b4;
  int *local_b0;
  int local_ac;
  _OSVERSIONINFOA local_a8;
  FARPROC local_14;
  undefined2 uStack_10;
  char *pcStack_c;
  uint local_8;

  local_b8 = CONCAT22(local_b8._2_2_,1);
  local_b4 = FUN_00901500(&DAT_009073b0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  pCVar2 = FUN_00901500(&DAT_00907400);
                    /* WARNING: Bad instruction - Truncating control flow here */
  hModule = GetModuleHandleA(local_b4);
  local_14 = GetProcAddress(hModule,pCVar2);
  uVar8 = (POPCOUNT((uint)local_14 & 0xff) & 1U) == 0;
  if (local_14 != (FARPROC)0x0) {
    iVar3 = (*local_14)();
    local_b8 = CONCAT22(local_b8._2_2_,(short)iVar3);
  }
  if ((!(bool)uVar8) && ((bool)uVar8)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  local_8 = (uint)(*(char *)(*(int *)(*(int *)(unaff_FS_OFFSET + 0x18) + 0x30) + 2) != '\0');
  if ((DAT_0090b310 == (HMODULE)0x0) || (DAT_0090b314 == (int *)0x0)) {
    pCVar2 = FUN_00901500(&DAT_009073b0);
    DAT_0090b310 = GetModuleHandleA(pCVar2);
    if (DAT_0090b310 != (HMODULE)0x0) {
      _DAT_0090b20c = DAT_0090b310;
      FUN_008f2450(0x90b208,in_stack_ffffff2c);
      FUN_008fe870((undefined4 *)&DAT_0090b208,(int *)&DAT_0090b218);
      DAT_0090b314 = (int *)((int)&DAT_0090b310->unused + _DAT_0090b290);
    }
  }
  piVar1 = DAT_0090b314;
  local_ac = 0xff;
                    /* WARNING: Bad instruction - Truncating control flow here */
  if ((DAT_0090b310 != (HMODULE)0x0) && (DAT_0090b314 != (int *)0x0)) {
    local_b0 = (int *)((int)&DAT_0090b310->unused + DAT_0090b314[7]);
    bVar9 = (POPCOUNT((uint)local_b0 & 0xff) & 1U) == 0;
    local_ac = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    if ((!bVar9) && (bVar9)) {
      *DAT_0090b314 = *DAT_0090b314 + 1;
      *(char *)piVar1 = (char)*piVar1 + (char)piVar1;
      cVar7 = (char)unaff_EBX + (char)((uint)local_b0 >> 8);
      if ((POPCOUNT(cVar7) & 1U) == 0) {
        piVar1 = (int *)(CONCAT31((int3)((uint)unaff_EBX >> 8),cVar7) + -0x6a76fe3e);
        *piVar1 = *piVar1 + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      uVar5 = VirtualFree(unaff_EDI[4],0,0x8000);
      if ((undefined **)PTR_LOOP_00909580 == unaff_EDI) {
        PTR_LOOP_00909580 = unaff_EDI[1];
      }
      if (unaff_EDI == &PTR_LOOP_00907560) {
        DAT_00907570 = 0xffffffff;
        return uVar5;
      }
      *(undefined **)unaff_EDI[1] = *unaff_EDI;
      *(undefined **)(*unaff_EDI + 4) = unaff_EDI[1];
      uVar5 = HeapFree(DAT_0090cae4,0,unaff_EDI);
      return uVar5;
    }
    for (uStack_c0 = 0; uStack_c0 < (uint)DAT_0090b314[5]; uStack_c0 = uStack_c0 + 1) {
      pcStack_c = (char *)((int)&DAT_0090b310->unused + *local_b0);
      if (*pcStack_c == -0x34) {
        local_ac = local_ac + 1;
      }
      local_b0 = local_b0 + 1;
    }
  }
  local_bc = CONCAT22(local_bc._2_2_,1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  local_a8.dwOSVersionInfoSize = 0x94;
                    /* WARNING: Bad instruction - Truncating control flow here */
  BVar4 = GetVersionExA(&local_a8);
  if ((BVar4 != 0) && (local_a8.dwPlatformId == 2)) {
    local_bc = local_bc & 0xffff0000;
                    /* WARNING: Bad instruction - Truncating control flow here */
  }
  uStack_10 = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  uVar5 = FUN_009026a0(0x3c,(undefined4 *)0x0,0,&uStack_c4,4);
  if ((uVar5 & 0xffff) == 0) {
    bVar9 = (POPCOUNT(*param_1 & 0x97) & 1U) == 0;
    *param_1 = *param_1 & 0x2d325697;
    uStack_10 = 1;
    if ((!bVar9) && (bVar9)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    *param_1 = uStack_c4;
  }
  if ((local_8 != 0) || (puVar6 = (uint *)0x0, (local_b8 & 0xffff) != 0)) {
    *param_1 = *param_1 & 0xfd356997;
    uStack_10 = 1;
    puVar6 = param_1;
  }
  if ((local_bc & 0xffff) != 0) {
    puVar6 = (uint *)(*param_1 & 0x1145373a);
    *param_1 = (uint)puVar6;
    uStack_10 = 1;
  }
  if (local_ac != 0) {
    puVar6 = (uint *)(*param_1 & 0x5185dade);
    *param_1 = (uint)puVar6;
    uStack_10 = 1;
  }
  return CONCAT22((short)((uint)puVar6 >> 0x10),uStack_10);
}



/* VA 00903827 */

/* WARNING: Instruction at (ram,0x00903cd7) overlaps instruction at (ram,0x00903cd5)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00903a57) */
/* WARNING: Removing unreachable block (ram,0x00903a5b) */
/* WARNING: Removing unreachable block (ram,0x00903a6f) */
/* WARNING: Removing unreachable block (ram,0x00903a73) */
/* WARNING: Removing unreachable block (ram,0x00903cb0) */
/* WARNING: Removing unreachable block (ram,0x00903c98) */
/* WARNING: Removing unreachable block (ram,0x00903c80) */
/* WARNING: Removing unreachable block (ram,0x00903c50) */
/* WARNING: Removing unreachable block (ram,0x00903c1f) */
/* WARNING: Removing unreachable block (ram,0x00903c07) */
/* WARNING: Removing unreachable block (ram,0x00903be9) */
/* WARNING: Removing unreachable block (ram,0x00903bd1) */
/* WARNING: Removing unreachable block (ram,0x00903ba9) */
/* WARNING: Removing unreachable block (ram,0x121b43fc) */
/* WARNING: Removing unreachable block (ram,0x00903b91) */
/* WARNING: Removing unreachable block (ram,0x00903b79) */
/* WARNING: Removing unreachable block (ram,0x00903b61) */
/* WARNING: Removing unreachable block (ram,0x00903b49) */
/* WARNING: Removing unreachable block (ram,0x00903b31) */
/* WARNING: Removing unreachable block (ram,0x00903aeb) */
/* WARNING: Removing unreachable block (ram,0x00903ad3) */
/* WARNING: Removing unreachable block (ram,0x00903ab8) */
/* WARNING: Removing unreachable block (ram,0x00903aa0) */
/* WARNING: Removing unreachable block (ram,0x00903a46) */
/* WARNING: Removing unreachable block (ram,0x00903a2e) */
/* WARNING: Removing unreachable block (ram,0x009039e9) */
/* WARNING: Removing unreachable block (ram,0x009039be) */
/* WARNING: Removing unreachable block (ram,0x009039a6) */
/* WARNING: Removing unreachable block (ram,0x0090398e) */
/* WARNING: Removing unreachable block (ram,0x00903976) */
/* WARNING: Removing unreachable block (ram,0x0090395e) */
/* WARNING: Removing unreachable block (ram,0x00903946) */
/* WARNING: Removing unreachable block (ram,0x0090392e) */
/* WARNING: Removing unreachable block (ram,0x00903916) */
/* WARNING: Removing unreachable block (ram,0x009038fe) */
/* WARNING: Removing unreachable block (ram,0x009038e6) */
/* WARNING: Removing unreachable block (ram,0x009038ce) */
/* WARNING: Removing unreachable block (ram,0x009038b6) */
/* WARNING: Removing unreachable block (ram,0x0090389e) */
/* WARNING: Removing unreachable block (ram,0x00903886) */
/* WARNING: Removing unreachable block (ram,0x0090386e) */
/* WARNING: Removing unreachable block (ram,0x00903856) */
/* WARNING: Removing unreachable block (ram,0x0090384a) */
/* WARNING: Removing unreachable block (ram,0x00903862) */
/* WARNING: Removing unreachable block (ram,0x0090387a) */
/* WARNING: Removing unreachable block (ram,0x00903892) */
/* WARNING: Removing unreachable block (ram,0x009038aa) */
/* WARNING: Removing unreachable block (ram,0x009038c2) */
/* WARNING: Removing unreachable block (ram,0x009038da) */
/* WARNING: Removing unreachable block (ram,0x009038f2) */
/* WARNING: Removing unreachable block (ram,0x0090390a) */
/* WARNING: Removing unreachable block (ram,0x00903922) */
/* WARNING: Removing unreachable block (ram,0x0090393a) */
/* WARNING: Removing unreachable block (ram,0x00903952) */
/* WARNING: Removing unreachable block (ram,0x0090396a) */
/* WARNING: Removing unreachable block (ram,0x00903982) */
/* WARNING: Removing unreachable block (ram,0x0090399a) */
/* WARNING: Removing unreachable block (ram,0x009039f5) */
/* WARNING: Removing unreachable block (ram,0x00903a01) */
/* WARNING: Removing unreachable block (ram,0x00903a22) */
/* WARNING: Removing unreachable block (ram,0x00903a63) */
/* WARNING: Removing unreachable block (ram,0x00903a94) */
/* WARNING: Removing unreachable block (ram,0x00903adf) */
/* WARNING: Removing unreachable block (ram,0x00903af7) */
/* WARNING: Removing unreachable block (ram,0x00903b03) */
/* WARNING: Removing unreachable block (ram,0x00903b25) */
/* WARNING: Removing unreachable block (ram,0x00903b3d) */
/* WARNING: Removing unreachable block (ram,0x00903b55) */
/* WARNING: Removing unreachable block (ram,0x00903b6d) */
/* WARNING: Removing unreachable block (ram,0x00903b85) */
/* WARNING: Removing unreachable block (ram,0x00903b9d) */
/* WARNING: Removing unreachable block (ram,0x00903bc5) */
/* WARNING: Removing unreachable block (ram,0x00903bdd) */
/* WARNING: Removing unreachable block (ram,0x00903bfb) */
/* WARNING: Removing unreachable block (ram,0x00903c5c) */
/* WARNING: Removing unreachable block (ram,0x00903c68) */
/* WARNING: Removing unreachable block (ram,0x00903ca4) */
/* WARNING: Removing unreachable block (ram,0x00903cbc) */
/* WARNING: Removing unreachable block (ram,0x00903cc8) */
/* WARNING: Removing unreachable block (ram,0x00903c8c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff60 : 0x00903c20 */
/* WARNING: Removing unreachable block (ram,0x00903cd4) */
/* WARNING: Removing unreachable block (ram,0x00903ab4) */
/* WARNING: Removing unreachable block (ram,0x009039b2) */
/* WARNING: Removing unreachable block (ram,0x00903a3a) */
/* WARNING: Removing unreachable block (ram,0x00903c13) */
/* WARNING: Removing unreachable block (ram,0x00903a7b) */
/* WARNING: Removing unreachable block (ram,0x00903a7f) */
/* WARNING: Removing unreachable block (ram,0x00903a90) */
/* WARNING: Removing unreachable block (ram,0x009039ca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 __fastcall FUN_00903827(byte param_1)

{
  BOOL BVar1;
  int *piVar2;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  bool bVar3;
  ulonglong uVar4;
  int *in_stack_00000004;
  uint uStack_a0;
  _OSVERSIONINFOA _Stack_9c;
  ushort uStack_8;

  bVar3 = (POPCOUNT((uint)&uStack_a0 & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  _Stack_9c.dwOSVersionInfoSize = 0x94;
  uStack_a0 = CONCAT22(uStack_a0._2_2_,1);
  BVar1 = GetVersionExA(&_Stack_9c);
  if ((BVar1 != 0) && (_Stack_9c.dwPlatformId == 2)) {
    uStack_a0 = uStack_a0 & 0xffff0000;
                    /* WARNING: Bad instruction - Truncating control flow here */
  }
  _DAT_0090b318 = 0xff;
  uVar4 = FUN_00903ce0(extraout_ECX,extraout_EDX);
  uStack_8 = 0;
  bVar3 = _DAT_0090b318 != -0x3ffffffb;
  piVar2 = (int *)uVar4;
  if (bVar3) {
    *in_stack_00000004 = *in_stack_00000004 + 0xf71;
    uStack_8 = 1;
    piVar2 = in_stack_00000004;
  }
  uStack_8 = (ushort)bVar3;
  if ((uStack_a0 & 0xffff) != 0) {
    piVar2 = (int *)(*in_stack_00000004 + 0x37a);
    bVar3 = (POPCOUNT((uint)piVar2 & 0xff) & 1U) == 0;
    *in_stack_00000004 = (int)piVar2;
    uStack_8 = 1;
    if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return CONCAT22((short)((uint)piVar2 >> 0x10),uStack_8);
}



/* VA 00903ce0 */

/* WARNING: Instruction at (ram,0x00904070) overlaps instruction at (ram,0x0090406f)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00904032) */
/* WARNING: Removing unreachable block (ram,0x0090401a) */
/* WARNING: Removing unreachable block (ram,0x00904002) */
/* WARNING: Removing unreachable block (ram,0x00903fea) */
/* WARNING: Removing unreachable block (ram,0x00903fd2) */
/* WARNING: Removing unreachable block (ram,0x00903fba) */
/* WARNING: Removing unreachable block (ram,0x00903fa2) */
/* WARNING: Removing unreachable block (ram,0x00903f8a) */
/* WARNING: Removing unreachable block (ram,0x00903f72) */
/* WARNING: Removing unreachable block (ram,0x00903f5a) */
/* WARNING: Removing unreachable block (ram,0x00903f42) */
/* WARNING: Removing unreachable block (ram,0x00903f2a) */
/* WARNING: Removing unreachable block (ram,0x00903f12) */
/* WARNING: Removing unreachable block (ram,0x00903f06) */
/* WARNING: Removing unreachable block (ram,0x00903eec) */
/* WARNING: Removing unreachable block (ram,0x00903eb0) */
/* WARNING: Removing unreachable block (ram,0x00903e98) */
/* WARNING: Removing unreachable block (ram,0x00903e80) */
/* WARNING: Removing unreachable block (ram,0x00903e68) */
/* WARNING: Removing unreachable block (ram,0x00903e44) */
/* WARNING: Removing unreachable block (ram,0x00903e20) */
/* WARNING: Removing unreachable block (ram,0x00903e08) */
/* WARNING: Removing unreachable block (ram,0x00903df0) */
/* WARNING: Removing unreachable block (ram,0x00903dd8) */
/* WARNING: Removing unreachable block (ram,0x00903dc0) */
/* WARNING: Removing unreachable block (ram,0x00903da8) */
/* WARNING: Removing unreachable block (ram,0x00903d84) */
/* WARNING: Removing unreachable block (ram,0x00903d6c) */
/* WARNING: Removing unreachable block (ram,0x00903d54) */
/* WARNING: Removing unreachable block (ram,0x00903d18) */
/* WARNING: Removing unreachable block (ram,0x00903d24) */
/* WARNING: Removing unreachable block (ram,0x00903d30) */
/* WARNING: Removing unreachable block (ram,0x00903d48) */
/* WARNING: Removing unreachable block (ram,0x00903d60) */
/* WARNING: Removing unreachable block (ram,0x00903d78) */
/* WARNING: Removing unreachable block (ram,0x00903d9c) */
/* WARNING: Removing unreachable block (ram,0x00903db4) */
/* WARNING: Removing unreachable block (ram,0x00903dcc) */
/* WARNING: Removing unreachable block (ram,0x00903de4) */
/* WARNING: Removing unreachable block (ram,0x00903dfc) */
/* WARNING: Removing unreachable block (ram,0x00903e14) */
/* WARNING: Removing unreachable block (ram,0x00903e38) */
/* WARNING: Removing unreachable block (ram,0x00903e5c) */
/* WARNING: Removing unreachable block (ram,0x00903e74) */
/* WARNING: Removing unreachable block (ram,0x00903ebc) */
/* WARNING: Removing unreachable block (ram,0x00903ec8) */
/* WARNING: Removing unreachable block (ram,0x00903ee0) */
/* WARNING: Removing unreachable block (ram,0x00903efa) */
/* WARNING: Removing unreachable block (ram,0x00903f36) */
/* WARNING: Removing unreachable block (ram,0x00903f4e) */
/* WARNING: Removing unreachable block (ram,0x00903f66) */
/* WARNING: Removing unreachable block (ram,0x00903f7e) */
/* WARNING: Removing unreachable block (ram,0x00903f96) */
/* WARNING: Removing unreachable block (ram,0x00903fae) */
/* WARNING: Removing unreachable block (ram,0x00903fc6) */
/* WARNING: Removing unreachable block (ram,0x00903fde) */
/* WARNING: Removing unreachable block (ram,0x00903ff6) */
/* WARNING: Removing unreachable block (ram,0x0090400e) */
/* WARNING: Removing unreachable block (ram,0x00904026) */
/* WARNING: Removing unreachable block (ram,0x0090403e) */
/* WARNING: Removing unreachable block (ram,0x00904062) */
/* WARNING: Removing unreachable block (ram,0x0090406e) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffec : 0x009041e2 */
/* WARNING: Removing unreachable block (ram,0x00903e50) */
/* WARNING: Removing unreachable block (ram,0x00903ed4) */
/* WARNING: Removing unreachable block (ram,0x0090404a) */
/* WARNING: Removing unreachable block (ram,0x00903d3c) */
/* WARNING: Removing unreachable block (ram,0x00903e8c) */
/* WARNING: Removing unreachable block (ram,0x00903f1e) */
/* WARNING: Removing unreachable block (ram,0x00903e2c) */
/* WARNING: Removing unreachable block (ram,0x00903d90) */
/* WARNING: Removing unreachable block (ram,0x00903ea4) */
/* WARNING: Removing unreachable block (ram,0x00904056) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ulonglong __fastcall FUN_00903ce0(uint param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *unaff_FS_OFFSET;
  ulonglong uVar2;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_00906010;
  puStack_10 = &LAB_008f63f8;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  pcVar1 = (code *)swi(1);
  uVar2 = (*pcVar1)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  *unaff_FS_OFFSET = uStack_14;
  return uVar2;
}



/* VA 009041f3 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x009044fd) overlaps instruction at (ram,0x009044fc)
    */
/* WARNING: Removing unreachable block (ram,0x009044d5) */
/* WARNING: Removing unreachable block (ram,0x009044c9) */
/* WARNING: Removing unreachable block (ram,0x009044b1) */
/* WARNING: Removing unreachable block (ram,0x0090448d) */
/* WARNING: Removing unreachable block (ram,0x00904475) */
/* WARNING: Removing unreachable block (ram,0x0090445d) */
/* WARNING: Removing unreachable block (ram,0x00904445) */
/* WARNING: Removing unreachable block (ram,0x0090442d) */
/* WARNING: Removing unreachable block (ram,0x00904415) */
/* WARNING: Removing unreachable block (ram,0x009043fd) */
/* WARNING: Removing unreachable block (ram,0x009043c0) */
/* WARNING: Removing unreachable block (ram,0x009043a8) */
/* WARNING: Removing unreachable block (ram,0x00904390) */
/* WARNING: Removing unreachable block (ram,0x00904378) */
/* WARNING: Removing unreachable block (ram,0x00904360) */
/* WARNING: Removing unreachable block (ram,0x00904348) */
/* WARNING: Removing unreachable block (ram,0x00904330) */
/* WARNING: Removing unreachable block (ram,0x00904318) */
/* WARNING: Removing unreachable block (ram,0x0090430c) */
/* WARNING: Removing unreachable block (ram,0x009042f4) */
/* WARNING: Removing unreachable block (ram,0x009042dc) */
/* WARNING: Removing unreachable block (ram,0x009042c4) */
/* WARNING: Removing unreachable block (ram,0x009042ac) */
/* WARNING: Removing unreachable block (ram,0x00904270) */
/* WARNING: Removing unreachable block (ram,0x0090424c) */
/* WARNING: Removing unreachable block (ram,0x00904234) */
/* WARNING: Removing unreachable block (ram,0x0090421c) */
/* WARNING: Removing unreachable block (ram,0x00904210) */
/* WARNING: Removing unreachable block (ram,0x00904204) */
/* WARNING: Removing unreachable block (ram,0x00904240) */
/* WARNING: Removing unreachable block (ram,0x00904258) */
/* WARNING: Removing unreachable block (ram,0x0090427c) */
/* WARNING: Removing unreachable block (ram,0x00904288) */
/* WARNING: Removing unreachable block (ram,0x009042a0) */
/* WARNING: Removing unreachable block (ram,0x009042b8) */
/* WARNING: Removing unreachable block (ram,0x009042d0) */
/* WARNING: Removing unreachable block (ram,0x009042e8) */
/* WARNING: Removing unreachable block (ram,0x00904300) */
/* WARNING: Removing unreachable block (ram,0x0090433c) */
/* WARNING: Removing unreachable block (ram,0x00904354) */
/* WARNING: Removing unreachable block (ram,0x0090436c) */
/* WARNING: Removing unreachable block (ram,0x00904384) */
/* WARNING: Removing unreachable block (ram,0x0090439c) */
/* WARNING: Removing unreachable block (ram,0x009043b4) */
/* WARNING: Removing unreachable block (ram,0x009043cc) */
/* WARNING: Removing unreachable block (ram,0x009043d8) */
/* WARNING: Removing unreachable block (ram,0x009043f1) */
/* WARNING: Removing unreachable block (ram,0x00904409) */
/* WARNING: Removing unreachable block (ram,0x00904421) */
/* WARNING: Removing unreachable block (ram,0x00904439) */
/* WARNING: Removing unreachable block (ram,0x00904451) */
/* WARNING: Removing unreachable block (ram,0x00904469) */
/* WARNING: Removing unreachable block (ram,0x00904481) */
/* WARNING: Removing unreachable block (ram,0x009044a5) */
/* WARNING: Removing unreachable block (ram,0x009044bd) */
/* WARNING: Removing unreachable block (ram,0x009044ed) */
/* WARNING: Removing unreachable block (ram,0x009044f9) */
/* WARNING: Removing unreachable block (ram,0x00904505) */
/* WARNING: Removing unreachable block (ram,0x00904499) */
/* WARNING: Removing unreachable block (ram,0x00904264) */
/* WARNING: Removing unreachable block (ram,0x00904228) */
/* WARNING: Removing unreachable block (ram,0x00904324) */
/* WARNING: Removing unreachable block (ram,0x009044e1) */
/* WARNING: Removing unreachable block (ram,0x00904294) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __thiscall FUN_009041f3(void *this,undefined4 *param_1)

{
  _DAT_0090b318 = *(undefined4 *)*param_1;
  return CONCAT44(*(undefined4 *)*param_1,1);
}



/* VA 00904510 */

/* WARNING: Instruction at (ram,0x009046a3) overlaps instruction at (ram,0x009046a2)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0090471d) */
/* WARNING: Removing unreachable block (ram,0x00904705) */
/* WARNING: Removing unreachable block (ram,0x00904695) */
/* WARNING: Removing unreachable block (ram,0x00904689) */
/* WARNING: Removing unreachable block (ram,0x00904671) */
/* WARNING: Removing unreachable block (ram,0x0090464f) */
/* WARNING: Removing unreachable block (ram,0x00904637) */
/* WARNING: Removing unreachable block (ram,0x0090461f) */
/* WARNING: Removing unreachable block (ram,0x009045fa) */
/* WARNING: Removing unreachable block (ram,0x009046ce) */
/* WARNING: Removing unreachable block (ram,0x009046da) */
/* WARNING: Removing unreachable block (ram,0x009045e2) */
/* WARNING: Removing unreachable block (ram,0x009045ca) */
/* WARNING: Removing unreachable block (ram,0x009045b2) */
/* WARNING: Removing unreachable block (ram,0x0090459a) */
/* WARNING: Removing unreachable block (ram,0x00904582) */
/* WARNING: Removing unreachable block (ram,0x0090453c) */
/* WARNING: Removing unreachable block (ram,0x00904524) */
/* WARNING: Removing unreachable block (ram,0x00904530) */
/* WARNING: Removing unreachable block (ram,0x00904548) */
/* WARNING: Removing unreachable block (ram,0x00904560) */
/* WARNING: Removing unreachable block (ram,0x00904576) */
/* WARNING: Removing unreachable block (ram,0x0090458e) */
/* WARNING: Removing unreachable block (ram,0x009045a6) */
/* WARNING: Removing unreachable block (ram,0x009045be) */
/* WARNING: Removing unreachable block (ram,0x009045d6) */
/* WARNING: Removing unreachable block (ram,0x009045ee) */
/* WARNING: Removing unreachable block (ram,0x009046b6) */
/* WARNING: Removing unreachable block (ram,0x009046e6) */
/* WARNING: Removing unreachable block (ram,0x00904613) */
/* WARNING: Removing unreachable block (ram,0x0090462b) */
/* WARNING: Removing unreachable block (ram,0x00904643) */
/* WARNING: Removing unreachable block (ram,0x00904665) */
/* WARNING: Removing unreachable block (ram,0x0090467d) */
/* WARNING: Removing unreachable block (ram,0x00904711) */
/* WARNING: Removing unreachable block (ram,0x00904729) */
/* WARNING: Removing unreachable block (ram,0x00904735) */
/* WARNING: Removing unreachable block (ram,0x009046f2) */
/* WARNING: Removing unreachable block (ram,0x009046f4) */
/* WARNING: Removing unreachable block (ram,0x009046c2) */
/* WARNING: Removing unreachable block (ram,0x00904741) */
/* WARNING: Removing unreachable block (ram,0x0090460f) */
/* WARNING: Removing unreachable block (ram,0x00904691) */
/* WARNING: Removing unreachable block (ram,0x009046a1) */
/* WARNING: Removing unreachable block (ram,0x00904554) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff4 : 0x00904742 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __thiscall FUN_00904510(void *this,byte *param_1)

{
  undefined4 local_c;

  if (**(int **)param_1 == -0x7ffffffd) {
    _DAT_0090b31c = 1;
    local_c = 0xffffffff;
                    /* WARNING: Bad instruction - Truncating control flow here */
  }
  else {
    local_c = 0;
  }
  return CONCAT44(**(int **)param_1,local_c);
}



/* VA 0090474e */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00904e35) overlaps instruction at (ram,0x00904e34)
    */
/* WARNING: Removing unreachable block (ram,0x00904ab7) */
/* WARNING: Removing unreachable block (ram,0x00904abb) */
/* WARNING: Removing unreachable block (ram,0x009048a1) */
/* WARNING: Removing unreachable block (ram,0x009048a5) */
/* WARNING: Removing unreachable block (ram,0x0090492f) */
/* WARNING: Removing unreachable block (ram,0x00904933) */
/* WARNING: Removing unreachable block (ram,0x0090493b) */
/* WARNING: Removing unreachable block (ram,0x0090493f) */
/* WARNING: Removing unreachable block (ram,0x009049ee) */
/* WARNING: Removing unreachable block (ram,0x009049f2) */
/* WARNING: Removing unreachable block (ram,0x00904840) */
/* WARNING: Removing unreachable block (ram,0x00904bd1) */
/* WARNING: Removing unreachable block (ram,0x00904bd5) */
/* WARNING: Removing unreachable block (ram,0x009048ad) */
/* WARNING: Removing unreachable block (ram,0x009048b1) */
/* WARNING: Removing unreachable block (ram,0x00904947) */
/* WARNING: Removing unreachable block (ram,0x00904856) */
/* WARNING: Removing unreachable block (ram,0x00904e19) */
/* WARNING: Removing unreachable block (ram,0x00904e01) */
/* WARNING: Removing unreachable block (ram,0x00904dd1) */
/* WARNING: Removing unreachable block (ram,0x00904da1) */
/* WARNING: Removing unreachable block (ram,0x00904d89) */
/* WARNING: Removing unreachable block (ram,0x00904d71) */
/* WARNING: Removing unreachable block (ram,0x00904d59) */
/* WARNING: Removing unreachable block (ram,0x00904d35) */
/* WARNING: Removing unreachable block (ram,0x00904d19) */
/* WARNING: Removing unreachable block (ram,0x00904d0d) */
/* WARNING: Removing unreachable block (ram,0x00904cbb) */
/* WARNING: Removing unreachable block (ram,0x00904c9a) */
/* WARNING: Removing unreachable block (ram,0x00904c82) */
/* WARNING: Removing unreachable block (ram,0x00904c55) */
/* WARNING: Removing unreachable block (ram,0x00904c33) */
/* WARNING: Removing unreachable block (ram,0x00904c1b) */
/* WARNING: Removing unreachable block (ram,0x00904c03) */
/* WARNING: Removing unreachable block (ram,0x00904bdd) */
/* WARNING: Removing unreachable block (ram,0x00904be1) */
/* WARNING: Removing unreachable block (ram,0x00904bc0) */
/* WARNING: Removing unreachable block (ram,0x00904bb4) */
/* WARNING: Removing unreachable block (ram,0x00904b9c) */
/* WARNING: Removing unreachable block (ram,0x00904b84) */
/* WARNING: Removing unreachable block (ram,0x00904b6c) */
/* WARNING: Removing unreachable block (ram,0x00904b04) */
/* WARNING: Removing unreachable block (ram,0x00904a97) */
/* WARNING: Removing unreachable block (ram,0x00904aa1) */
/* WARNING: Removing unreachable block (ram,0x00904a31) */
/* WARNING: Removing unreachable block (ram,0x00904a5d) */
/* WARNING: Removing unreachable block (ram,0x009049c2) */
/* WARNING: Removing unreachable block (ram,0x0090497c) */
/* WARNING: Removing unreachable block (ram,0x009048d5) */
/* WARNING: Removing unreachable block (ram,0x009048c5) */
/* WARNING: Removing unreachable block (ram,0x009048c9) */
/* WARNING: Removing unreachable block (ram,0x00904823) */
/* WARNING: Removing unreachable block (ram,0x00904817) */
/* WARNING: Removing unreachable block (ram,0x009047db) */
/* WARNING: Removing unreachable block (ram,0x009047b7) */
/* WARNING: Removing unreachable block (ram,0x0090479f) */
/* WARNING: Removing unreachable block (ram,0x00904787) */
/* WARNING: Removing unreachable block (ram,0x0090477b) */
/* WARNING: Removing unreachable block (ram,0x00904793) */
/* WARNING: Removing unreachable block (ram,0x009047ab) */
/* WARNING: Removing unreachable block (ram,0x009047f3) */
/* WARNING: Removing unreachable block (ram,0x009047e7) */
/* WARNING: Removing unreachable block (ram,0x009047ff) */
/* WARNING: Removing unreachable block (ram,0x009048b9) */
/* WARNING: Removing unreachable block (ram,0x00904988) */
/* WARNING: Removing unreachable block (ram,0x009049b6) */
/* WARNING: Removing unreachable block (ram,0x00904a23) */
/* WARNING: Removing unreachable block (ram,0x00904af8) */
/* WARNING: Removing unreachable block (ram,0x00904aec) */
/* WARNING: Removing unreachable block (ram,0x00904b3e) */
/* WARNING: Removing unreachable block (ram,0x00904b60) */
/* WARNING: Removing unreachable block (ram,0x00904b78) */
/* WARNING: Removing unreachable block (ram,0x00904b90) */
/* WARNING: Removing unreachable block (ram,0x00904ba8) */
/* WARNING: Removing unreachable block (ram,0x00904c0f) */
/* WARNING: Removing unreachable block (ram,0x00904c27) */
/* WARNING: Removing unreachable block (ram,0x00904c49) */
/* WARNING: Removing unreachable block (ram,0x00904c61) */
/* WARNING: Removing unreachable block (ram,0x00904c8e) */
/* WARNING: Removing unreachable block (ram,0x00904ca6) */
/* WARNING: Removing unreachable block (ram,0x00904cc7) */
/* WARNING: Removing unreachable block (ram,0x00904cd3) */
/* WARNING: Removing unreachable block (ram,0x00904d01) */
/* WARNING: Removing unreachable block (ram,0x00904d41) */
/* WARNING: Removing unreachable block (ram,0x00904d65) */
/* WARNING: Removing unreachable block (ram,0x00904d7d) */
/* WARNING: Removing unreachable block (ram,0x00904d95) */
/* WARNING: Removing unreachable block (ram,0x00904dad) */
/* WARNING: Removing unreachable block (ram,0x00904ddd) */
/* WARNING: Removing unreachable block (ram,0x00904de9) */
/* WARNING: Removing unreachable block (ram,0x00904e25) */
/* WARNING: Removing unreachable block (ram,0x00904e31) */
/* WARNING: Removing unreachable block (ram,0x00904bca) */
/* WARNING: Removing unreachable block (ram,0x00904be9) */
/* WARNING: Removing unreachable block (ram,0x00904bed) */
/* WARNING: Removing unreachable block (ram,0x00904be4) */
/* WARNING: Removing unreachable block (ram,0x00904bff) */
/* WARNING: Removing unreachable block (ram,0x00904c06) */
/* WARNING: Removing unreachable block (ram,0x00904c17) */
/* WARNING: Removing unreachable block (ram,0x00904c12) */
/* WARNING: Removing unreachable block (ram,0x00904b10) */
/* WARNING: Removing unreachable block (ram,0x00904a2f) */
/* WARNING: Removing unreachable block (ram,0x0090483b) */
/* WARNING: Removing unreachable block (ram,0x009047c3) */
/* WARNING: Removing unreachable block (ram,0x009048d1) */
/* WARNING: Removing unreachable block (ram,0x00904b4a) */
/* WARNING: Removing unreachable block (ram,0x00904a69) */
/* WARNING: Removing unreachable block (ram,0x00904994) */
/* WARNING: Removing unreachable block (ram,0x009048dd) */
/* WARNING: Removing unreachable block (ram,0x009048e1) */
/* WARNING: Removing unreachable block (ram,0x00904a3b) */
/* WARNING: Removing unreachable block (ram,0x00904b1c) */
/* WARNING: Removing unreachable block (ram,0x00904cdf) */
/* WARNING: Removing unreachable block (ram,0x00904e3d) */
/* WARNING: Removing unreachable block (ram,0x00904db9) */
/* WARNING: Removing unreachable block (ram,0x009047cf) */
/* WARNING: Removing unreachable block (ram,0x00904df5) */
/* WARNING: Removing unreachable block (ram,0x00904d4d) */
/* WARNING: Removing unreachable block (ram,0x009049ce) */
/* WARNING: Removing unreachable block (ram,0x009049d8) */
/* WARNING: Removing unreachable block (ram,0x00904968) */
/* WARNING: Removing unreachable block (ram,0x0090480b) */
/* WARNING: Removing unreachable block (ram,0x00904a8b) */
/* WARNING: Removing unreachable block (ram,0x00904cf5) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff48 : 0x00904e58 */
/* WARNING: Removing unreachable block (ram,0x00904e49) */
/* WARNING: Removing unreachable block (ram,0x0090482f) */
/* WARNING: Removing unreachable block (ram,0x00904e0d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __thiscall FUN_0090474e(void *this,uint *param_1)

{
  uint uVar1;
  BOOL BVar2;
  bool bVar3;
  HANDLE local_b8;
  undefined1 *puStackY_b4;
  FARPROC pFStackY_b0;
  LPCSTR local_ac;
  LPCSTR pCStackY_a8;
  HMODULE local_a4;
  undefined1 *puStackY_a0;
  undefined1 *puStackY_9c;
  DWORD DStackY_98;
  DWORD DStackY_88;
  undefined *puStackY_20;

  bVar3 = (POPCOUNT((uint)&local_b8 & 0xff) & 1U) == 0;
  local_b8 = (HANDLE)0x0;
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  local_ac = FUN_00901500(&DAT_009073b0);
  bVar3 = true;
                    /* WARNING: Bad instruction - Truncating control flow here */
  local_a4 = GetModuleHandleA(local_ac);
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (local_a4 != (HMODULE)0x0) {
    pCStackY_a8 = FUN_00901500(&DAT_009073f0);
    bVar3 = true;
                    /* WARNING: Bad instruction - Truncating control flow here */
    pFStackY_b0 = GetProcAddress(local_a4,pCStackY_a8);
    if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (pFStackY_b0 != (FARPROC)0x0) {
      puStackY_a0 = FUN_00901500(&DAT_009073c0);
      puStackY_20 = &UNK_0090496b;
      local_b8 = (HANDLE)(*pFStackY_b0)();
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* WARNING: Bad instruction - Truncating control flow here */
      if (local_b8 == (HANDLE)0xffffffff) {
        puStackY_9c = FUN_00901500((char *)0x9073d0);
                    /* WARNING: Bad instruction - Truncating control flow here */
        local_b8 = (HANDLE)(*pFStackY_b0)();
                    /* WARNING: Bad instruction - Truncating control flow here */
        if (local_b8 != (HANDLE)0xffffffff) {
          CloseHandle(local_b8);
        }
      }
      else {
        CloseHandle(local_b8);
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      if (local_b8 == (HANDLE)0xffffffff) {
        puStackY_b4 = FUN_00901500((char *)0x9073e0);
        local_b8 = (HANDLE)(*pFStackY_b0)();
                    /* WARNING: Bad instruction - Truncating control flow here */
        if (local_b8 != (HANDLE)0xffffffff) {
          CloseHandle(local_b8);
        }
      }
      else {
        CloseHandle(local_b8);
      }
    }
  }
  DStackY_98 = 0x94;
  _DAT_0090b31c = 1;
  BVar2 = GetVersionExA((LPOSVERSIONINFOA)&DStackY_98);
  if ((BVar2 != 0) && (DStackY_88 != 1)) {
    local_b8 = (HANDLE)0x5;
  }
  uVar1 = *param_1;
  *param_1 = uVar1 & (uint)local_b8;
  bVar3 = (POPCOUNT(uVar1 & (uint)local_b8 & 0xff) & 1U) == 0;
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((!bVar3) && (bVar3)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return CONCAT44(param_1,(uint)(local_b8 != (HANDLE)0xffffffff));
}



/* VA 00904e70 */

/* WARNING: Instruction at (ram,0x00904eb0) overlaps instruction at (ram,0x00904eaf)
    */
/* WARNING: Removing unreachable block (ram,0x00904e89) */
/* WARNING: Removing unreachable block (ram,0x00904e95) */
/* WARNING: Removing unreachable block (ram,0x00904ea1) */
/* WARNING: Removing unreachable block (ram,0x00904ead) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_00904e70(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int unaff_FS_OFFSET;
  ushort local_8;

  local_8 = (ushort)(*(int *)(*(int *)(unaff_FS_OFFSET + 0x18) + 0x20) != 0);
  return CONCAT44(param_2,CONCAT22((short)((uint)in_EAX >> 0x10),local_8));
}



/* VA 00904ecd */

/* WARNING: Instruction at (ram,0x00904fe2) overlaps instruction at (ram,0x00904fe1)
    */
/* WARNING: Removing unreachable block (ram,0x00904fdf) */
/* WARNING: Removing unreachable block (ram,0x00904fc7) */
/* WARNING: Removing unreachable block (ram,0x00904faf) */
/* WARNING: Removing unreachable block (ram,0x00904f93) */
/* WARNING: Removing unreachable block (ram,0x00904f97) */
/* WARNING: Removing unreachable block (ram,0x00904f29) */
/* WARNING: Removing unreachable block (ram,0x00904f11) */
/* WARNING: Removing unreachable block (ram,0x00904ef9) */
/* WARNING: Removing unreachable block (ram,0x00904ee1) */
/* WARNING: Removing unreachable block (ram,0x00904eed) */
/* WARNING: Removing unreachable block (ram,0x00904f05) */
/* WARNING: Removing unreachable block (ram,0x00904f1d) */
/* WARNING: Removing unreachable block (ram,0x00904f35) */
/* WARNING: Removing unreachable block (ram,0x00904f87) */
/* WARNING: Removing unreachable block (ram,0x00904f8b) */
/* WARNING: Removing unreachable block (ram,0x00904fa3) */
/* WARNING: Removing unreachable block (ram,0x00904fbb) */
/* WARNING: Removing unreachable block (ram,0x00904fd3) */
/* WARNING: Removing unreachable block (ram,0x00904fcf) */
/* WARNING: Removing unreachable block (ram,0x00904fb7) */
/* WARNING: Removing unreachable block (ram,0x00904f9f) */
/* WARNING: Removing unreachable block (ram,0x00904fab) */
/* WARNING: Removing unreachable block (ram,0x00904fc3) */
/* WARNING: Removing unreachable block (ram,0x00904fdb) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall
FUN_00904ecd(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

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
        goto LAB_0090506c;
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
LAB_0090506c:
  return CONCAT44(param_2,uVar5);
}



/* VA 00905073 */

/* WARNING: Instruction at (ram,0x00905653) overlaps instruction at (ram,0x00905651)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00905105) */
/* WARNING: Removing unreachable block (ram,0x00905109) */
/* WARNING: Removing unreachable block (ram,0x00905189) */
/* WARNING: Removing unreachable block (ram,0x0090518d) */
/* WARNING: Removing unreachable block (ram,0x009051a1) */
/* WARNING: Removing unreachable block (ram,0x009051a5) */
/* WARNING: Removing unreachable block (ram,0x00905650) */
/* WARNING: Removing unreachable block (ram,0x0090566c) */
/* WARNING: Removing unreachable block (ram,0x00905667) */
/* WARNING: Removing unreachable block (ram,0x00905678) */
/* WARNING: Removing unreachable block (ram,0x0090567c) */
/* WARNING: Removing unreachable block (ram,0x00905670) */
/* WARNING: Removing unreachable block (ram,0x00905673) */
/* WARNING: Removing unreachable block (ram,0x00905684) */
/* WARNING: Removing unreachable block (ram,0x0090567f) */
/* WARNING: Removing unreachable block (ram,0x00905690) */
/* WARNING: Removing unreachable block (ram,0x00905694) */
/* WARNING: Removing unreachable block (ram,0x00905688) */
/* WARNING: Removing unreachable block (ram,0x0090568b) */
/* WARNING: Removing unreachable block (ram,0x0090569c) */
/* WARNING: Removing unreachable block (ram,0x00905697) */
/* WARNING: Removing unreachable block (ram,0x009056a8) */
/* WARNING: Removing unreachable block (ram,0x009056ac) */
/* WARNING: Removing unreachable block (ram,0x009056a0) */
/* WARNING: Removing unreachable block (ram,0x009056a3) */
/* WARNING: Removing unreachable block (ram,0x009056b4) */
/* WARNING: Removing unreachable block (ram,0x009056af) */
/* WARNING: Removing unreachable block (ram,0x009056b8) */
/* WARNING: Removing unreachable block (ram,0x00905638) */
/* WARNING: Removing unreachable block (ram,0x00905620) */
/* WARNING: Removing unreachable block (ram,0x009055fc) */
/* WARNING: Removing unreachable block (ram,0x009055d5) */
/* WARNING: Removing unreachable block (ram,0x009055bd) */
/* WARNING: Removing unreachable block (ram,0x0090558d) */
/* WARNING: Removing unreachable block (ram,0x00905575) */
/* WARNING: Removing unreachable block (ram,0x00905551) */
/* WARNING: Removing unreachable block (ram,0x00905501) */
/* WARNING: Removing unreachable block (ram,0x009054e9) */
/* WARNING: Removing unreachable block (ram,0x009054d1) */
/* WARNING: Removing unreachable block (ram,0x009054b9) */
/* WARNING: Removing unreachable block (ram,0x00905403) */
/* WARNING: Removing unreachable block (ram,0x009053f7) */
/* WARNING: Removing unreachable block (ram,0x009053eb) */
/* WARNING: Removing unreachable block (ram,0x009053a8) */
/* WARNING: Removing unreachable block (ram,0x0090536c) */
/* WARNING: Removing unreachable block (ram,0x00905332) */
/* WARNING: Removing unreachable block (ram,0x00905311) */
/* WARNING: Removing unreachable block (ram,0x009052f9) */
/* WARNING: Removing unreachable block (ram,0x009052c0) */
/* WARNING: Removing unreachable block (ram,0x00905292) */
/* WARNING: Removing unreachable block (ram,0x0090526e) */
/* WARNING: Removing unreachable block (ram,0x00905256) */
/* WARNING: Removing unreachable block (ram,0x0090523e) */
/* WARNING: Removing unreachable block (ram,0x00905226) */
/* WARNING: Removing unreachable block (ram,0x00905202) */
/* WARNING: Removing unreachable block (ram,0x009051e1) */
/* WARNING: Removing unreachable block (ram,0x009051c9) */
/* WARNING: Removing unreachable block (ram,0x009051b1) */
/* WARNING: Removing unreachable block (ram,0x0090515d) */
/* WARNING: Removing unreachable block (ram,0x00905145) */
/* WARNING: Removing unreachable block (ram,0x00905121) */
/* WARNING: Removing unreachable block (ram,0x009050dc) */
/* WARNING: Removing unreachable block (ram,0x009050b8) */
/* WARNING: Removing unreachable block (ram,0x009050a0) */
/* WARNING: Removing unreachable block (ram,0x00905094) */
/* WARNING: Removing unreachable block (ram,0x009050ac) */
/* WARNING: Removing unreachable block (ram,0x009050d0) */
/* WARNING: Removing unreachable block (ram,0x0090512d) */
/* WARNING: Removing unreachable block (ram,0x00905151) */
/* WARNING: Removing unreachable block (ram,0x00905195) */
/* WARNING: Removing unreachable block (ram,0x009051bd) */
/* WARNING: Removing unreachable block (ram,0x009051d5) */
/* WARNING: Removing unreachable block (ram,0x009051f6) */
/* WARNING: Removing unreachable block (ram,0x0090520e) */
/* WARNING: Removing unreachable block (ram,0x00905232) */
/* WARNING: Removing unreachable block (ram,0x0090524a) */
/* WARNING: Removing unreachable block (ram,0x00905262) */
/* WARNING: Removing unreachable block (ram,0x00905286) */
/* WARNING: Removing unreachable block (ram,0x009052b4) */
/* WARNING: Removing unreachable block (ram,0x009052ed) */
/* WARNING: Removing unreachable block (ram,0x00905305) */
/* WARNING: Removing unreachable block (ram,0x00905326) */
/* WARNING: Removing unreachable block (ram,0x0090533e) */
/* WARNING: Removing unreachable block (ram,0x00905384) */
/* WARNING: Removing unreachable block (ram,0x009053df) */
/* WARNING: Removing unreachable block (ram,0x0090540f) */
/* WARNING: Removing unreachable block (ram,0x0090541b) */
/* WARNING: Removing unreachable block (ram,0x00905489) */
/* WARNING: Removing unreachable block (ram,0x009054c5) */
/* WARNING: Removing unreachable block (ram,0x009054dd) */
/* WARNING: Removing unreachable block (ram,0x009054f5) */
/* WARNING: Removing unreachable block (ram,0x00905545) */
/* WARNING: Removing unreachable block (ram,0x0090555d) */
/* WARNING: Removing unreachable block (ram,0x00905581) */
/* WARNING: Removing unreachable block (ram,0x009055b1) */
/* WARNING: Removing unreachable block (ram,0x009055c9) */
/* WARNING: Removing unreachable block (ram,0x009055e1) */
/* WARNING: Removing unreachable block (ram,0x74905e64) */
/* WARNING: Removing unreachable block (ram,0x009055e7) */
/* WARNING: Removing unreachable block (ram,0x00905614) */
/* WARNING: Removing unreachable block (ram,0x0090562c) */
/* WARNING: Removing unreachable block (ram,0x00905644) */
/* WARNING: Removing unreachable block (ram,0x00905111) */
/* WARNING: Removing unreachable block (ram,0x0090573c) */
/* WARNING: Removing unreachable block (ram,0x00905724) */
/* WARNING: Removing unreachable block (ram,0x0090570c) */
/* WARNING: Removing unreachable block (ram,0x009056f4) */
/* WARNING: Removing unreachable block (ram,0x009056dc) */
/* WARNING: Removing unreachable block (ram,0x009056c4) */
/* WARNING: Removing unreachable block (ram,0x00905458) */
/* WARNING: Removing unreachable block (ram,0x0090539c) */
/* WARNING: Removing unreachable block (ram,0x0090534a) */
/* WARNING: Removing unreachable block (ram,0x0090511d) */
/* WARNING: Removing unreachable block (ram,0x00905139) */
/* WARNING: Removing unreachable block (ram,0x00905390) */
/* WARNING: Removing unreachable block (ram,0x00905427) */
/* WARNING: Removing unreachable block (ram,0x0090542c) */
/* WARNING: Removing unreachable block (ram,0x0090542e) */
/* WARNING: Removing unreachable block (ram,0x0090542f) */
/* WARNING: Removing unreachable block (ram,0x00905495) */
/* WARNING: Removing unreachable block (ram,0x009056d0) */
/* WARNING: Removing unreachable block (ram,0x009056e8) */
/* WARNING: Removing unreachable block (ram,0x00905700) */
/* WARNING: Removing unreachable block (ram,0x00905718) */
/* WARNING: Removing unreachable block (ram,0x00905730) */
/* WARNING: Removing unreachable block (ram,0x009052cc) */
/* WARNING: Removing unreachable block (ram,0x0090529e) */
/* WARNING: Removing unreachable block (ram,0x00905464) */
/* WARNING: Removing unreachable block (ram,0x00905608) */
/* WARNING: Removing unreachable block (ram,0x00905569) */
/* WARNING: Removing unreachable block (ram,0x0090514d) */
/* WARNING: Removing unreachable block (ram,0x009050c4) */
/* WARNING: Removing unreachable block (ram,0x00905141) */
/* WARNING: Removing unreachable block (ram,0x009051ad) */
/* WARNING: Removing unreachable block (ram,0x009053b4) */
/* WARNING: Removing unreachable block (ram,0x009053b9) */
/* WARNING: Removing unreachable block (ram,0x00905349) */
/* WARNING: Removing unreachable block (ram,0x00905599) */
/* WARNING: Removing unreachable block (ram,0x009054a1) */
/* WARNING: Removing unreachable block (ram,0x0090527a) */
/* WARNING: Removing unreachable block (ram,0x00905216) */
/* WARNING: Removing unreachable block (ram,0x0090521a) */
/* WARNING: Removing unreachable block (ram,0x009053d3) */
/* WARNING: Removing unreachable block (ram,0x00905360) */
/* WARNING: Removing unreachable block (ram,0x00905222) */
/* WARNING: Removing unreachable block (ram,0x00905378) */
/* WARNING: Removing unreachable block (ram,0x00905748) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff60 : 0x00905502 */
/* WARNING: Removing unreachable block (ram,0x009055a5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_00905073(uint param_1,uint param_2)

{
  uint uVar1;
  BOOL BVar2;
  LPCSTR lpProcName;
  HMODULE hModule;
  int iVar3;
  undefined4 *puVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar6;
  bool bVar7;
  undefined8 uVar8;
  undefined4 *in_stack_00000004;
  undefined4 uStack_ac;
  LPCSTR pCStack_a4;
  int local_a0;
  _OSVERSIONINFOA _Stack_9c;
  FARPROC pFStack_8;

  bVar7 = (POPCOUNT((uint)&uStack_ac & 0xff) & 1U) == 0;
  if ((!bVar7) && (bVar7)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (DAT_0090b1fc == 0) {
    local_a0 = 0;
    FUN_00904ecd(&local_a0,param_2,(undefined4 *)0x1010,&local_a0);
    if (local_a0 == -0x4ceeba) {
      DAT_0090b1fc = 1;
    }
    _Stack_9c.dwOSVersionInfoSize = 0x94;
                    /* WARNING: Bad instruction - Truncating control flow here */
    BVar2 = GetVersionExA(&_Stack_9c);
    if ((BVar2 != 0) && (_Stack_9c.dwPlatformId != 1)) {
      local_a0 = -0x4ceeba;
    }
    pCStack_a4 = FUN_00901500(&DAT_009073b0);
    lpProcName = FUN_00901500(&DAT_00907400);
    hModule = GetModuleHandleA(pCStack_a4);
    pFStack_8 = GetProcAddress(hModule,lpProcName);
    uStack_ac = (uint)uStack_ac._2_2_ << 0x10;
                    /* WARNING: Bad instruction - Truncating control flow here */
    uVar5 = extraout_ECX;
    uVar6 = extraout_EDX;
    if (pFStack_8 != (FARPROC)0x0) {
      iVar3 = (*pFStack_8)();
      uStack_ac = CONCAT22(uStack_ac._2_2_,(short)iVar3);
      uVar5 = extraout_ECX_00;
      uVar6 = extraout_EDX_00;
    }
    uVar8 = FUN_00904e70(uVar5,uVar6);
    param_2 = (uint)((ulonglong)uVar8 >> 0x20);
                    /* WARNING: Bad instruction - Truncating control flow here */
    if (((local_a0 == -0x4ceeba) || ((short)uVar8 != 0)) ||
       (param_2 = uStack_ac & 0xffff, param_2 != 0)) {
      uVar1 = CONCAT22((short)((ulonglong)uVar8 >> 0x10),1);
    }
    else {
      puVar4 = (undefined4 *)uVar8;
      if (in_stack_00000004 != (undefined4 *)0x0) {
        *in_stack_00000004 = 0x400;
        puVar4 = in_stack_00000004;
      }
      uVar1 = (uint)puVar4 & 0xffff0000;
    }
  }
  else {
    uVar1 = 1;
  }
  return CONCAT44(param_2,uVar1);
}



/* VA 00905760 */

/* WARNING: Instruction at (ram,0x00905d3c) overlaps instruction at (ram,0x00905d39)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00905d49) */
/* WARNING: Removing unreachable block (ram,0x00905d4d) */
/* WARNING: Removing unreachable block (ram,0x00905dc5) */
/* WARNING: Removing unreachable block (ram,0x00905dad) */
/* WARNING: Removing unreachable block (ram,0x00905d95) */
/* WARNING: Removing unreachable block (ram,0x00905d59) */
/* WARNING: Removing unreachable block (ram,0x00905d20) */
/* WARNING: Removing unreachable block (ram,0x00905cf8) */
/* WARNING: Removing unreachable block (ram,0x00905cce) */
/* WARNING: Removing unreachable block (ram,0x00905caa) */
/* WARNING: Removing unreachable block (ram,0x00905c92) */
/* WARNING: Removing unreachable block (ram,0x00905c6d) */
/* WARNING: Removing unreachable block (ram,0x00905c33) */
/* WARNING: Removing unreachable block (ram,0x00905c27) */
/* WARNING: Removing unreachable block (ram,0x00905c06) */
/* WARNING: Removing unreachable block (ram,0x00905bee) */
/* WARNING: Removing unreachable block (ram,0x00905ba9) */
/* WARNING: Removing unreachable block (ram,0x00905b87) */
/* WARNING: Removing unreachable block (ram,0x00905b6f) */
/* WARNING: Removing unreachable block (ram,0x00905b57) */
/* WARNING: Removing unreachable block (ram,0x00905b3f) */
/* WARNING: Removing unreachable block (ram,0x00905b27) */
/* WARNING: Removing unreachable block (ram,0x00905b0f) */
/* WARNING: Removing unreachable block (ram,0x00905b03) */
/* WARNING: Removing unreachable block (ram,0x00905aeb) */
/* WARNING: Removing unreachable block (ram,0x00905ad3) */
/* WARNING: Removing unreachable block (ram,0x00905aa7) */
/* WARNING: Removing unreachable block (ram,0x00905a8f) */
/* WARNING: Removing unreachable block (ram,0x00905a53) */
/* WARNING: Removing unreachable block (ram,0x00905a15) */
/* WARNING: Removing unreachable block (ram,0x009059e5) */
/* WARNING: Removing unreachable block (ram,0x009059cd) */
/* WARNING: Removing unreachable block (ram,0x009059b5) */
/* WARNING: Removing unreachable block (ram,0x0090599d) */
/* WARNING: Removing unreachable block (ram,0x00905985) */
/* WARNING: Removing unreachable block (ram,0x0090596d) */
/* WARNING: Removing unreachable block (ram,0x00905955) */
/* WARNING: Removing unreachable block (ram,0x0090593d) */
/* WARNING: Removing unreachable block (ram,0x00905925) */
/* WARNING: Removing unreachable block (ram,0x0090590d) */
/* WARNING: Removing unreachable block (ram,0x009058f5) */
/* WARNING: Removing unreachable block (ram,0x009058dd) */
/* WARNING: Removing unreachable block (ram,0x009058c5) */
/* WARNING: Removing unreachable block (ram,0x009058ad) */
/* WARNING: Removing unreachable block (ram,0x00905895) */
/* WARNING: Removing unreachable block (ram,0x0090587d) */
/* WARNING: Removing unreachable block (ram,0x0090584d) */
/* WARNING: Removing unreachable block (ram,0x00905835) */
/* WARNING: Removing unreachable block (ram,0x0090581d) */
/* WARNING: Removing unreachable block (ram,0x009057f9) */
/* WARNING: Removing unreachable block (ram,0x009057c9) */
/* WARNING: Removing unreachable block (ram,0x009057b1) */
/* WARNING: Removing unreachable block (ram,0x00905799) */
/* WARNING: Removing unreachable block (ram,0x0090578d) */
/* WARNING: Removing unreachable block (ram,0x00905781) */
/* WARNING: Removing unreachable block (ram,0x009057bd) */
/* WARNING: Removing unreachable block (ram,0x009057d5) */
/* WARNING: Removing unreachable block (ram,0x00905805) */
/* WARNING: Removing unreachable block (ram,0x00905829) */
/* WARNING: Removing unreachable block (ram,0x00905841) */
/* WARNING: Removing unreachable block (ram,0x00905859) */
/* WARNING: Removing unreachable block (ram,0x00905865) */
/* WARNING: Removing unreachable block (ram,0x009058a1) */
/* WARNING: Removing unreachable block (ram,0x009058b9) */
/* WARNING: Removing unreachable block (ram,0x009058d1) */
/* WARNING: Removing unreachable block (ram,0x009058e9) */
/* WARNING: Removing unreachable block (ram,0x00905901) */
/* WARNING: Removing unreachable block (ram,0x00905919) */
/* WARNING: Removing unreachable block (ram,0x00905931) */
/* WARNING: Removing unreachable block (ram,0x00905949) */
/* WARNING: Removing unreachable block (ram,0x00905961) */
/* WARNING: Removing unreachable block (ram,0x00905979) */
/* WARNING: Removing unreachable block (ram,0x00905991) */
/* WARNING: Removing unreachable block (ram,0x009059a9) */
/* WARNING: Removing unreachable block (ram,0x009059c1) */
/* WARNING: Removing unreachable block (ram,0x009059d9) */
/* WARNING: Removing unreachable block (ram,0x009059f1) */
/* WARNING: Removing unreachable block (ram,0x009059fd) */
/* WARNING: Removing unreachable block (ram,0x00905a5f) */
/* WARNING: Removing unreachable block (ram,0x00905a6b) */
/* WARNING: Removing unreachable block (ram,0x00905a83) */
/* WARNING: Removing unreachable block (ram,0x00905a9b) */
/* WARNING: Removing unreachable block (ram,0x00905ac7) */
/* WARNING: Removing unreachable block (ram,0x00905adf) */
/* WARNING: Removing unreachable block (ram,0x00905af7) */
/* WARNING: Removing unreachable block (ram,0x00905b33) */
/* WARNING: Removing unreachable block (ram,0x00905b4b) */
/* WARNING: Removing unreachable block (ram,0x00905b63) */
/* WARNING: Removing unreachable block (ram,0x00905b7b) */
/* WARNING: Removing unreachable block (ram,0x00905b93) */
/* WARNING: Removing unreachable block (ram,0x00905bb5) */
/* WARNING: Removing unreachable block (ram,0x00905bc1) */
/* WARNING: Removing unreachable block (ram,0x00905be2) */
/* WARNING: Removing unreachable block (ram,0x00905bfa) */
/* WARNING: Removing unreachable block (ram,0x00905c1b) */
/* WARNING: Removing unreachable block (ram,0x00905c55) */
/* WARNING: Removing unreachable block (ram,0x00905c9e) */
/* WARNING: Removing unreachable block (ram,0x00905cb6) */
/* WARNING: Removing unreachable block (ram,0x00905cda) */
/* WARNING: Removing unreachable block (ram,0x00905ce6) */
/* WARNING: Removing unreachable block (ram,0x00905d65) */
/* WARNING: Removing unreachable block (ram,0x00905d2c) */
/* WARNING: Removing unreachable block (ram,0x00905d71) */
/* WARNING: Removing unreachable block (ram,0x00905d89) */
/* WARNING: Removing unreachable block (ram,0x00905da1) */
/* WARNING: Removing unreachable block (ram,0x00905db9) */
/* WARNING: Removing unreachable block (ram,0x00905d7d) */
/* WARNING: Removing unreachable block (ram,0x00905c79) */
/* WARNING: Removing unreachable block (ram,0x00905d04) */
/* WARNING: Removing unreachable block (ram,0x00905c61) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff64 : 0x00905c7a */
/* WARNING: Removing unreachable block (ram,0x00905a09) */
/* WARNING: Removing unreachable block (ram,0x00905c3f) */
/* WARNING: Removing unreachable block (ram,0x00905d38) */
/* WARNING: Removing unreachable block (ram,0x00905889) */
/* WARNING: Removing unreachable block (ram,0x00905a77) */
/* WARNING: Removing unreachable block (ram,0x00905cc2) */
/* WARNING: Removing unreachable block (ram,0x00905811) */
/* WARNING: Removing unreachable block (ram,0x009057e1) */
/* WARNING: Removing unreachable block (ram,0x00905871) */
/* WARNING: Removing unreachable block (ram,0x009057a5) */
/* WARNING: Removing unreachable block (ram,0x00905d55) */
/* WARNING: Removing unreachable block (ram,0x00905dd1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * __fastcall FUN_00905760(uint param_1,undefined2 param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined2 uVar4;
  uint *puVar3;
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
                    /* WARNING: Bad instruction - Truncating control flow here */
  uVar2 = FUN_00905ddc();
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  if ((uVar2 & 0xffff) == 0) {
    pcVar1 = (code *)swi(0x68);
    iStackY_a0 = (*pcVar1)();
    bVar5 = (POPCOUNT(iStackY_a0 - 0x4300U & 0xff) & 1U) == 0;
    if (iStackY_a0 - 0x4300U != 0) {
      local_9c = 1;
    }
  }
  else {
    iStackY_a0 = 0x4300;
    local_9c = 0;
  }
  if ((!bVar5) && (bVar5)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DStackY_98 = 0x94;
  uVar2 = GetVersionExA((LPOSVERSIONINFOA)&DStackY_98);
  if ((uVar2 != 0) && (DStackY_88 != 1)) {
    local_9c = 0xf;
                    /* WARNING: Bad instruction - Truncating control flow here */
  }
  if (local_9c == 0) {
    puVar3 = (uint *)(uVar2 & 0xffff0000);
  }
  else {
    uVar4 = (undefined2)(uVar2 >> 0x10);
    if (in_stack_00000004 != (int *)0x0) {
      *in_stack_00000004 = *in_stack_00000004 + 0x34f;
      uVar4 = (undefined2)((uint)in_stack_00000004 >> 0x10);
    }
    puVar3 = (uint *)CONCAT22(uVar4,1);
  }
  return puVar3;
}



/* VA 00905ddc */

uint FUN_00905ddc(void)

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
