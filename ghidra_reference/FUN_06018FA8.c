/* FUN_06018FA8  0x06018FA8 */


void FUN_06018fa8(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  
  puVar1 = PTR_FUN_06018fe0;
  *(undefined4 *)PTR_DAT_06018fe4 = in_r3;
  (*(code *)puVar1)(0xf,DAT_06018fe8);
  (*(code *)puVar1)(0xf,DAT_06018fec);
  FUN_060192e8();
  if (*(int *)PTR_DAT_06018fe4 == 0) {
    (*(code *)PTR_FUN_06018ff0)();
    *(undefined2 *)PTR_DAT_06018ff4 = 0;
  }
  (*(code *)puVar1)(0xf,DAT_06018fe8);
  return;
}

