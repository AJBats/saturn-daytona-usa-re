/* FUN_06032F9A  0x06032F9A */


undefined4 FUN_06032f9a(void)

{
  code *in_r0;
  undefined4 uVar1;
  undefined4 in_r7;
  undefined4 in_pr;
  
  (*in_r0)();
  (*(code *)PTR_FUN_06032ff8)
            (*(undefined4 *)(PTR_DAT_06033008 + 0x20),*(undefined4 *)(PTR_DAT_06033008 + 0x24),
             *(undefined4 *)(PTR_DAT_06033008 + 0x28),in_r7,in_pr);
  (*(code *)PTR_FUN_0603301c)(DAT_06032fec);
  (*(code *)PTR_FUN_06033014)();
  uVar1 = (*(code *)PTR_FUN_06033014)();
  return uVar1;
}

