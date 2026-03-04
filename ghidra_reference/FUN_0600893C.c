/* FUN_0600893C  0x0600893C */


void FUN_0600893c(void)

{
  undefined *puVar1;
  undefined1 in_r3;
  
  *PTR_DAT_060089c4 = in_r3;
  *PTR_DAT_060089c8 = 0;
  *(undefined2 *)PTR_DAT_060089cc = 0;
  puVar1 = PTR_FUN_060089d4;
  *PTR_DAT_060089d0 = 0;
  (*(code *)puVar1)();
  (*(code *)PTR_FUN_060089d8)();
  (*(code *)PTR_FUN_060089dc)();
  (*(code *)PTR_FUN_060089e0)();
  if (*(short *)PTR_DAT_060089e4 == 0) {
    (*(code *)PTR_FUN_060089e8)();
  }
  *(undefined2 *)PTR_DAT_060089ec = 0;
  puVar1 = PTR_DAT_060089f0;
  *(int *)PTR_DAT_060089f0 = (int)DAT_060089c2;
  *(undefined4 *)PTR_DAT_060089f4 = 0;
  if (*(int *)PTR_DAT_060089f8 == 2) {
    *(int *)puVar1 = *(int *)puVar1 + -0x3c;
  }
  (*(code *)PTR_FUN_060089fc)();
  *(uint *)PTR_DAT_06008a00 = *(uint *)PTR_DAT_06008a00 | DAT_06008a04;
  *(undefined4 *)PTR_DAT_06008a08 = 3;
  (*(code *)PTR_FUN_06008a0c)();
  *(undefined4 *)PTR_DAT_06008a10 = 0;
  *(undefined2 *)PTR_DAT_06008a14 = 4;
  return;
}

