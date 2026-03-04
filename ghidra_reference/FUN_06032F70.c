/* FUN_06032F70  0x06032F70 */


undefined4 FUN_06032f70(void)

{
  code *in_r0;
  undefined4 uVar1;
  uint in_stack_00000000;
  
  (*in_r0)();
  (*(code *)PTR_FUN_06033010)();
  (*(code *)PTR_FUN_06033014)();
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

