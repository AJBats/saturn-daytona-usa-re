/* FUN_0601D77C  0x0601D77C */


void FUN_0601d77c(void)

{
  int unaff_r14;
  
  if (*(int *)PTR_DAT_0601d7c0 != unaff_r14) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d7c0 = unaff_r14;
    *(int *)PTR_DAT_0601d7c4 = unaff_r14;
    *(int *)PTR_DAT_0601d7c8 = unaff_r14;
  }
  return;
}

