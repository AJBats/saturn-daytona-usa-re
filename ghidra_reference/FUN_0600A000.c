/* FUN_0600A000  0x0600A000 */


void FUN_0600a000(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_0600a06c;
  (*(code *)PTR_FUN_0600a06c)(1);
  (*(code *)puVar1)(3,0);
  (*(code *)puVar1)(2,0);
  (*(code *)puVar1)(0,DAT_0600a070);
  (*(code *)puVar1)(0,DAT_0600a074);
  return;
}

