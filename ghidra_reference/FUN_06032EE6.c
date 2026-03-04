/* FUN_06032EE6  0x06032EE6 */


undefined4 FUN_06032ee6(void)

{
  code *in_r0;
  undefined4 uVar1;
  uint uVar2;
  undefined4 in_r7;
  int unaff_r14;
  undefined4 in_pr;
  
  (*in_r0)();
  uVar2 = (uint)*(short *)(unaff_r14 + DAT_06033004);
  if ((DAT_06032ff0 & uVar2) != 0) {
    (*(code *)PTR_FUN_06032fe4)();
    (*(code *)PTR_FUN_06032ff8)
              (*(undefined4 *)PTR_DAT_06033008,*(undefined4 *)(PTR_DAT_06033008 + 4),
               *(undefined4 *)(PTR_DAT_06033008 + 8),in_r7,in_pr);
    (*(code *)PTR_FUN_0603300c)(*(undefined4 *)(PTR_DAT_06033008 + 0xc));
    (*(code *)PTR_FUN_06033010)();
    (*(code *)PTR_FUN_06033014)();
  }
  if ((DAT_06032ff4 & uVar2) != 0) {
    (*(code *)PTR_FUN_06032fe4)();
    (*(code *)PTR_FUN_06032ff8)
              (*(undefined4 *)(PTR_DAT_06033008 + 0x10),*(undefined4 *)(PTR_DAT_06033008 + 0x14),
               *(undefined4 *)(PTR_DAT_06033008 + 0x18),in_r7,in_pr);
    (*(code *)PTR_FUN_0603300c)(*(undefined4 *)(PTR_DAT_06033008 + 0x1c));
    (*(code *)PTR_FUN_06033010)();
    (*(code *)PTR_FUN_06033014)();
  }
  if ((DAT_06033018 & uVar2) != 0) {
    (*(code *)PTR_FUN_06032fe4)();
    (*(code *)PTR_FUN_06032ff8)
              (*(undefined4 *)(PTR_DAT_06033008 + 0x20),*(undefined4 *)(PTR_DAT_06033008 + 0x24),
               *(undefined4 *)(PTR_DAT_06033008 + 0x28),in_r7,in_pr);
    (*(code *)PTR_FUN_0603301c)(DAT_06032fec);
    (*(code *)PTR_FUN_06033014)();
  }
  uVar1 = (*(code *)PTR_FUN_06033014)();
  return uVar1;
}

