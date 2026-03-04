/* FUN_06008CD0  0x06008CD0 */


void FUN_06008cd0(void)

{
  undefined4 unaff_r14;
  
  *(undefined4 *)PTR_DAT_06008d3c = unaff_r14;
  (*(code *)PTR_FUN_06008d40)();
  (*(code *)PTR_FUN_06008d44)();
  *(undefined4 *)PTR_DAT_06008d48 = unaff_r14;
  (*(code *)PTR_FUN_06008d4c)();
  (*(code *)PTR_FUN_06008d50)();
  *(int *)PTR_DAT_06008d54 = (int)PTR_DAT_06008d38._0_2_;
  *(undefined4 *)PTR_DAT_06008d58 = unaff_r14;
  *(undefined4 *)PTR_DAT_06008d5c = 5;
  *(uint *)PTR_DAT_06008d60 = *(uint *)PTR_DAT_06008d60 | DAT_06008d64;
  (*(code *)PTR_FUN_06008d44)();
  *(undefined4 *)PTR_DAT_06008d48 = unaff_r14;
  *(undefined2 *)PTR_DAT_06008d68 = 3;
  if (*PTR_DAT_06008d6c == '\x01') {
    (*(code *)PTR_FUN_06008d70)();
    *PTR_DAT_06008d6c = (char)unaff_r14;
  }
  return;
}

