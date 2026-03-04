/* FUN_060191E4  0x060191E4 */


void FUN_060191e4(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  
  puVar1 = PTR_FUN_06019224;
  *(undefined4 *)PTR_DAT_06019228 = in_r3;
  (*(code *)puVar1)(0xf,DAT_0601922c);
  (*(code *)puVar1)(0xf,DAT_06019230);
  FUN_060192e8();
  if (*(int *)PTR_DAT_06019228 == 0) {
    (*(code *)PTR_FUN_06019240)(PTR_DAT_0601923c,PTR_DAT_06019238,PTR_DAT_06019234);
    *(undefined2 *)PTR_DAT_06019244 = 0;
  }
  (*(code *)puVar1)(0xf,DAT_0601922c);
  return;
}

