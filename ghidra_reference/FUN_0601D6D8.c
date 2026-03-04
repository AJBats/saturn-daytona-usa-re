/* FUN_0601D6D8  0x0601D6D8 */


void FUN_0601d6d8(void)

{
  int unaff_r14;
  
  if (*(int *)PTR_DAT_0601d71c != unaff_r14) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d71c = unaff_r14;
    *(int *)PTR_DAT_0601d720 = unaff_r14;
    *(int *)PTR_DAT_0601d724 = unaff_r14;
  }
  return;
}

