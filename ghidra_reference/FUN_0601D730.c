/* FUN_0601D730  0x0601D730 */


void FUN_0601d730(void)

{
  int unaff_r14;
  
  if (*(int *)PTR_DAT_0601d76c != unaff_r14) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d76c = unaff_r14;
    *(int *)PTR_DAT_0601d770 = unaff_r14;
    *(int *)PTR_DAT_0601d774 = unaff_r14;
  }
  return;
}

