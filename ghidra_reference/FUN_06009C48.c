/* FUN_06009C48  0x06009C48 */


void FUN_06009c48(void)

{
  (*(code *)PTR_FUN_06009cb8)();
  if ((*(int *)PTR_DAT_06009cbc != 0) &&
     ((*(code *)PTR_FUN_06009cc0)(), *(int *)PTR_DAT_06009cc4 != 0)) {
    (*(code *)PTR_FUN_06009cc8)();
  }
  (*(code *)PTR_FUN_06009ccc)();
  (*(code *)PTR_FUN_06009cd0)();
  (*(code *)PTR_FUN_06009cd4)();
  (*(code *)PTR_FUN_06009ce4)(PTR_DAT_06009ce0,PTR_DAT_06009cdc,*(undefined4 *)PTR_DAT_06009cd8);
  (*(code *)PTR_FUN_06009ce8)();
  if (*(short *)PTR_DAT_06009cec != 0) {
    (*(code *)PTR_FUN_06009cf0)();
  }
  if (0 < *(int *)(*(int *)PTR_DAT_06009cf4 + (int)DAT_06009cb6)) {
    FUN_0600a084();
  }
  (*(code *)PTR_FUN_06009cf8)();
  return;
}

