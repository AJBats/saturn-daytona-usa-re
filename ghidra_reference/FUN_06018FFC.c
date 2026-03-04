/* FUN_06018FFC  0x06018FFC */


void FUN_06018ffc(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  
  puVar1 = PTR_FUN_0601903c;
  *(undefined4 *)PTR_DAT_06019040 = in_r3;
  (*(code *)puVar1)(0xf,DAT_06019044);
  (*(code *)puVar1)(0xf,DAT_06019048);
  FUN_060192e8();
  if (*(int *)PTR_DAT_06019040 == 0) {
    (*(code *)PTR_FUN_0601904c)();
    *(undefined2 *)PTR_DAT_06019050 = 0;
  }
  (*(code *)puVar1)(0xf,DAT_06019054);
  (*(code *)puVar1)(0xf,DAT_06019044);
  return;
}

