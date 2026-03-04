/* FUN_0602E3F4  0x0602E3F4 */


void FUN_0602e3f4(void)

{
  if (DAT_0602e418 <= *(int *)PTR_DAT_0602e414) {
    if (((int)(char)*PTR_DAT_0602e41c & DAT_0602e420) == 0) {
      (*(code *)PTR_FUN_0602e44c)();
    }
    else {
      *PTR_DAT_0602e424 = (char)DAT_0602e428;
    }
  }
  return;
}

