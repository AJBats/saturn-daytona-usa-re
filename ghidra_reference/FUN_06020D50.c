/* FUN_06020D50  0x06020D50 */


void FUN_06020d50(void)

{
  undefined *puVar1;
  int unaff_r11;
  uint uVar2;
  undefined4 auStack_28 [10];
  
  puVar1 = PTR_DAT_06020dc4;
  (*(code *)PTR_FUN_06020dcc)();
  uVar2 = 0;
  do {
    if (puVar1[(short)(((ushort)uVar2 & 0xff) * 0x44)] != '\0') {
      (*(code *)auStack_28[(byte)puVar1[(short)(((ushort)uVar2 & 0xff) * 0x44)] - 1])(uVar2);
    }
    uVar2 = uVar2 + 1;
  } while ((int)(uVar2 & 0xff) < unaff_r11);
  return;
}

