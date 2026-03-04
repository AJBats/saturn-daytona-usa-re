/* FUN_06009D4E  0x06009D4E */


void FUN_06009d4e(void)

{
  (*(code *)PTR_FUN_06009dac)();
  if (*PTR_DAT_06009db0 == '\0') {
    (*(code *)PTR_FUN_06009db4)();
    (*(code *)PTR_FUN_06009dc4)(PTR_DAT_06009dc0,PTR_DAT_06009dbc,*(undefined4 *)PTR_DAT_06009db8);
    (*(code *)PTR_FUN_06009dc8)();
  }
  (*(code *)PTR_FUN_06009dcc)();
  return;
}

