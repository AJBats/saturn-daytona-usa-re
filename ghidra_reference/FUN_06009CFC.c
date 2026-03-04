/* FUN_06009CFC  0x06009CFC */


void FUN_06009cfc(void)

{
  *(undefined2 *)PTR_DAT_06009d7c = 3;
  (*(code *)PTR_FUN_06009d80)();
  (*(code *)PTR_FUN_06009d84)();
  FUN_0600a1b8();
  *(undefined4 *)PTR_DAT_06009d88 = 0x19;
  *PTR_DAT_06009d8c = 6;
  (*(code *)PTR_FUN_06009d90)();
  (*(code *)PTR_FUN_06009d94)();
  *(undefined4 *)(*(int *)PTR_DAT_06009d98 + 8) = 0;
  *(uint *)PTR_DAT_06009d9c = *(uint *)PTR_DAT_06009d9c | DAT_06009da0;
  (*(code *)PTR_FUN_06009da4)();
  *(undefined4 *)PTR_DAT_06009da8 = 0;
  return;
}

