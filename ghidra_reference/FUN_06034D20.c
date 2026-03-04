/* FUN_06034D20  0x06034D20 */


void FUN_06034d20(void)

{
  int unaff_r14;
  undefined1 local_c [4];
  undefined1 uStack_8;
  undefined1 auStack_7 [7];
  
  (*(code *)PTR_FUN_06034dbc)(local_c);
  local_c[0] = 0x10;
  FUN_06034d5e();
  uStack_8 = *(undefined1 *)(unaff_r14 + 0x10);
  FUN_06034d5e(unaff_r14 + 8,auStack_7);
  (*(code *)PTR_FUN_06034dc0)(0,local_c);
  return;
}

