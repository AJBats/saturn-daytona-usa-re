/* FUN_0600955E  0x0600955E */


void FUN_0600955e(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0600959c;
  if ((*(ushort *)PTR_DAT_060095c8 & DAT_06009596) != 0) {
    *(undefined4 *)PTR_DAT_060095cc = 0x1d;
    *(undefined4 *)puVar1 = 0x12;
  }
  if ((*(uint *)PTR_DAT_06009598 & 1) == 0) {
    if (*(int *)PTR_DAT_06009684 == 0) {
      *(int *)PTR_DAT_06009688 = *(int *)PTR_DAT_06009688 + 1;
    }
  }
  else {
    *(uint *)PTR_DAT_06009598 = *(uint *)PTR_DAT_06009598 & 0xfffffffe;
    *(undefined4 *)puVar1 = 0x14;
  }
  if (*DAT_0600968c != '\0') {
    (*(code *)PTR_FUN_06009690)(0);
  }
  (*(code *)PTR_FUN_06009694)();
  (*(code *)PTR_FUN_06009698)();
  (*(code *)PTR_FUN_060096a8)(PTR_DAT_060096a4,PTR_DAT_060096a0,*(undefined4 *)PTR_DAT_0600969c);
  (*(code *)PTR_FUN_060096ac)();
  if (*(short *)PTR_DAT_060096b0 != 0) {
    (*(code *)PTR_FUN_060096b4)();
  }
  if (*PTR_DAT_060096b8 != '\0') {
    (*(code *)PTR_FUN_060096c4)(8,(int)DAT_0600967c,PTR_DAT_060096c0,PTR_DAT_060096bc);
  }
  if (0 < *(int *)(*(int *)PTR_DAT_060096c8 + (int)DAT_0600967e)) {
    FUN_0600a084();
  }
  (*(code *)PTR_FUN_060096cc)();
  if ((*(uint *)((int)DAT_06009680 + *(int *)PTR_DAT_060096c8) & 0xcc) == 0) {
    (*(code *)PTR_FUN_060096d4)
              (4,*(undefined4 *)PTR_DAT_060096d0,(int)DAT_06009682,
               *(undefined4 *)(PTR_DAT_060096d0 + 4),PTR_DAT_060096d0);
  }
  if (*(int *)PTR_DAT_060096d8 == 0) {
    *(undefined4 *)puVar1 = 0x11;
  }
  return;
}

