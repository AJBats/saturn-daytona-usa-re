/* FUN_06032F34  0x06032F34 */


undefined4 FUN_06032f34(void)

{
  code *in_r0;
  undefined4 uVar1;
  undefined4 in_r7;
  undefined4 in_pr;
  uint in_stack_00000000;
  
  (*in_r0)();
  if ((DAT_06032ff4 & in_stack_00000000) != 0) {
    (*(code *)PTR_FUN_06032fe4)();
    (*(code *)PTR_FUN_06032ff8)
              (*(undefined4 *)(PTR_DAT_06033008 + 0x10),*(undefined4 *)(PTR_DAT_06033008 + 0x14),
               *(undefined4 *)(PTR_DAT_06033008 + 0x18),in_r7,in_pr);
    (*(code *)PTR_FUN_0603300c)(*(undefined4 *)(PTR_DAT_06033008 + 0x1c));
    (*(code *)PTR_FUN_06033010)();
    (*(code *)PTR_FUN_06033014)();
  }
  if ((DAT_06033018 & in_stack_00000000) != 0) {
    (*(code *)PTR_FUN_06032fe4)();
    (*(code *)PTR_FUN_06032ff8)
              (*(undefined4 *)(PTR_DAT_06033008 + 0x20),*(undefined4 *)(PTR_DAT_06033008 + 0x24),
               *(undefined4 *)(PTR_DAT_06033008 + 0x28));
    (*(code *)PTR_FUN_0603301c)(DAT_06032fec);
    (*(code *)PTR_FUN_06033014)();
  }
  uVar1 = (*(code *)PTR_FUN_06033014)();
  return uVar1;
}

