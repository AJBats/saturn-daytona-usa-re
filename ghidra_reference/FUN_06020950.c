/* FUN_06020950  0x06020950 */


void FUN_06020950(void)

{
  undefined *puVar1;
  int unaff_r11;
  uint uVar2;
  undefined1 auStack_60 [96];
  
  puVar1 = PTR_FUN_060209a0;
  (*(code *)PTR_FUN_060209a8)();
  uVar2 = 0;
  do {
    (*(code *)puVar1)(4,auStack_60,(uVar2 & 0xff) << 7,0);
    (*(code *)puVar1)(4,auStack_60,((uVar2 & 0xff) * 0x40 + 0x2c) * 2,0);
    uVar2 = uVar2 + 1;
  } while ((int)(uVar2 & 0xff) < unaff_r11);
  return;
}

