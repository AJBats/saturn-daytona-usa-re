/* FUN_06019150  0x06019150 */


void FUN_06019150(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  
  puVar1 = PTR_FUN_060191c4;
  *(undefined4 *)PTR_DAT_060191c8 = in_r3;
  (*(code *)puVar1)(0xf,DAT_060191cc);
  (*(code *)puVar1)(0xf,DAT_060191d0);
  FUN_060192e8();
  if (*(int *)PTR_DAT_060191c8 == 0) {
    (*(code *)PTR_FUN_060191d4)();
    *(undefined2 *)PTR_DAT_060191d8 = 0;
  }
  (*(code *)puVar1)(0xf,DAT_060191cc);
  return;
}

