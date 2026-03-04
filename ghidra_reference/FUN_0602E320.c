/* FUN_0602E320  0x0602E320 */


void FUN_0602e320(void)

{
  code *unaff_r13;
  
  (*unaff_r13)();
  (*(code *)PTR_FUN_0602e388)();
  (*(code *)PTR_FUN_0602e38c)();
  (*(code *)PTR_FUN_0602e394)(DAT_0602e390);
  (*(code *)PTR_FUN_0602e398)(DAT_0602e390);
  *(undefined4 *)((int)DAT_0602e376 + *(int *)PTR_DAT_0602e380) =
       *(undefined4 *)((int)DAT_0602e374 + *(int *)PTR_DAT_0602e380);
  FUN_0602e3f4();
  return;
}

