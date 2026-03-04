/* FUN_06008E00  0x06008E00 */


void FUN_06008e00(void)

{
  (*(code *)PTR_FUN_06008e84)();
  (*(code *)PTR_FUN_06008e88)();
  *(undefined4 *)PTR_DAT_06008e8c = 0xd;
  (*(code *)PTR_FUN_06008e90)();
  (*(code *)PTR_FUN_06008e94)();
  *(uint *)PTR_DAT_06008e98 = *(uint *)PTR_DAT_06008e98 | DAT_06008e9c;
  (*(code *)PTR_FUN_06008ea0)();
  *(undefined4 *)PTR_DAT_06008ea4 = 0;
  *(undefined2 *)PTR_DAT_06008ea8 = 3;
  (*(code *)PTR_FUN_06008eac)(5,5,0xf);
  return;
}

