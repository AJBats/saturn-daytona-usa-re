/* FUN_0601D6FC  0x0601D6FC */


void FUN_0601d6fc(void)

{
  int unaff_r14;
  
  if (*(int *)PTR_DAT_0601d728 != unaff_r14) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d728 = unaff_r14;
    *(int *)PTR_DAT_0601d720 = unaff_r14;
    *(int *)PTR_DAT_0601d724 = unaff_r14;
  }
  return;
}

