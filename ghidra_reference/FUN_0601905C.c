/* FUN_0601905C  0x0601905C */


void FUN_0601905c(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  
  puVar1 = PTR_FUN_0601909c;
  *(undefined4 *)PTR_DAT_060190a0 = in_r3;
  (*(code *)puVar1)(0xf,DAT_060190a4);
  (*(code *)puVar1)(0xf,DAT_060190a8);
  FUN_060192e8();
  if (*(int *)PTR_DAT_060190a0 == 0) {
    (*(code *)PTR_FUN_060190ac)();
    *(undefined2 *)PTR_DAT_060190b0 = 0;
  }
  (*(code *)puVar1)(0xf,DAT_060190a4);
  (*(code *)puVar1)(0xf,DAT_060190b4);
  return;
}

