/* FUN_060190F8  0x060190F8 */


void FUN_060190f8(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  
  puVar1 = PTR_FUN_06019130;
  *(undefined4 *)PTR_DAT_06019134 = in_r3;
  (*(code *)puVar1)(0xf,DAT_06019138);
  (*(code *)puVar1)(0xf,DAT_0601913c);
  FUN_060192e8();
  if (*(int *)PTR_DAT_06019134 == 0) {
    (*(code *)PTR_FUN_06019148)();
    *(undefined2 *)PTR_DAT_06019144 = 0;
  }
  (*(code *)puVar1)(0xf,DAT_06019138);
  return;
}

