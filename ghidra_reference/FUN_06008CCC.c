/* FUN_06008CCC  0x06008CCC */


void FUN_06008ccc(void)

{
  *(undefined4 *)PTR_DAT_06008d3c = 0;
  (*(code *)PTR_FUN_06008d40)();
  (*(code *)PTR_FUN_06008d44)();
  *(undefined4 *)PTR_DAT_06008d48 = 0;
  (*(code *)PTR_FUN_06008d4c)();
  (*(code *)PTR_FUN_06008d50)();
  *(int *)PTR_DAT_06008d54 = (int)PTR_DAT_06008d38._0_2_;
  *(undefined4 *)PTR_DAT_06008d58 = 0;
  *(undefined4 *)PTR_DAT_06008d5c = 5;
  *(uint *)PTR_DAT_06008d60 = *(uint *)PTR_DAT_06008d60 | DAT_06008d64;
  (*(code *)PTR_FUN_06008d44)();
  *(undefined4 *)PTR_DAT_06008d48 = 0;
  *(undefined2 *)PTR_DAT_06008d68 = 3;
  if (*PTR_DAT_06008d6c == '\x01') {
    (*(code *)PTR_FUN_06008d70)();
    *PTR_DAT_06008d6c = 0;
  }
  return;
}

