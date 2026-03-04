/* FUN_0601924C  0x0601924C */


void FUN_0601924c(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  
  puVar1 = PTR_FUN_06019290;
  *(undefined4 *)PTR_DAT_06019294 = in_r3;
  (*(code *)puVar1)(0xf,DAT_06019298);
  (*(code *)puVar1)(0xf,DAT_0601929c);
  FUN_060192e8();
  if (*(int *)PTR_DAT_06019294 == 0) {
    (*(code *)PTR_FUN_060192ac)(PTR_DAT_060192a8,PTR_DAT_060192a4,PTR_DAT_060192a0);
    *(undefined2 *)PTR_DAT_060192b0 = 0;
  }
  (*(code *)puVar1)(0xf,DAT_06019298);
  return;
}

