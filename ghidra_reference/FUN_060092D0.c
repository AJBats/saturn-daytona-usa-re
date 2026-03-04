/* FUN_060092D0  0x060092D0 */


void FUN_060092d0(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_06009354;
  puVar1 = PTR_DAT_06009350;
  if ((*(ushort *)PTR_DAT_06009358 & DAT_0600934c) != 0) {
    *(undefined4 *)PTR_DAT_0600935c = 0x11;
    *(undefined4 *)puVar2 = 0x12;
  }
  (*(code *)PTR_FUN_06009360)();
  if (((*PTR_DAT_06009364 == '\0') && (*(int *)PTR_DAT_06009368 == 0)) &&
     (iVar4 = *(int *)PTR_DAT_0600936c, *(int *)PTR_DAT_0600936c = iVar4 + -1, iVar4 + -1 < 1)) {
    (*(code *)PTR_FUN_06009370)();
    *(undefined4 *)PTR_DAT_06009378 = *(undefined4 *)(*(int *)PTR_DAT_06009374 + (int)DAT_0600934e);
    *(undefined4 *)puVar2 = 0x18;
  }
  puVar3 = PTR_FUN_06009370;
  if ((*(uint *)PTR_DAT_0600937c & 1) == 0) {
    if (*(int *)PTR_DAT_060093d0 == 0) {
      *(int *)PTR_DAT_060093d4 = *(int *)PTR_DAT_060093d4 + 1;
    }
  }
  else {
    *(uint *)PTR_DAT_0600937c = *(uint *)PTR_DAT_0600937c & 0xfffffffe;
    (*(code *)puVar3)();
    puVar3 = PTR_FUN_06009380;
    *(undefined4 *)puVar2 = 0x14;
    (*(code *)puVar3)();
  }
  if ((*(short *)PTR_DAT_060093d8 == 0) && (*(int *)PTR_DAT_060093dc == (int)DAT_060093ce)) {
    (*(code *)PTR_FUN_060093e4)(0,DAT_060093e0);
    *(undefined2 *)PTR_DAT_060093d8 = 0x28;
  }
  if (*PTR_DAT_060093e8 != '\0') {
    if (*(int *)puVar1 == 0) {
      (*(code *)PTR_FUN_060094a4)();
    }
    else {
      (*(code *)PTR_FUN_060093ec)();
    }
  }
  if ((*(int *)PTR_DAT_060094a8 != 0) && ((*(code *)PTR_FUN_060094ac)(), *(int *)puVar1 != 0)) {
    (*(code *)PTR_FUN_060094b0)();
  }
  if (*DAT_060094b4 != '\0') {
    (*(code *)PTR_FUN_060094b8)(0);
  }
  if (*(int *)PTR_DAT_060094bc == 1) {
    *(undefined4 *)puVar2 = 0x1c;
  }
  if (*(int *)puVar1 == 2) {
    (*(code *)PTR_FUN_060094c0)();
  }
  (*(code *)PTR_FUN_060094c4)();
  (*(code *)PTR_FUN_060094c8)();
  (*(code *)PTR_FUN_060094cc)();
  (*(code *)PTR_FUN_060094dc)(PTR_DAT_060094d8,PTR_DAT_060094d4,*(undefined4 *)PTR_DAT_060094d0);
  (*(code *)PTR_FUN_060094e0)();
  (*(code *)PTR_FUN_060094e4)();
  if (*(short *)PTR_DAT_060094e8 != 0) {
    (*(code *)PTR_FUN_060094ec)();
  }
  if (*PTR_DAT_060094f0 != '\0') {
    (*(code *)PTR_FUN_060094fc)(8,(int)DAT_060094a0,PTR_DAT_060094f8,PTR_DAT_060094f4);
  }
  if (0 < *(int *)(*(int *)PTR_DAT_06009500 + (int)DAT_060094a2)) {
    FUN_0600a084();
  }
  (*(code *)PTR_FUN_06009504)();
  return;
}

