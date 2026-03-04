/* FUN_0601D7A0  0x0601D7A0 */


void FUN_0601d7a0(void)

{
  int unaff_r14;
  
  if (*(int *)PTR_DAT_0601d7cc != unaff_r14) {
    FUN_0601db84();
    *(int *)PTR_DAT_0601d7cc = unaff_r14;
    *(int *)PTR_DAT_0601d7c4 = unaff_r14;
    *(int *)PTR_DAT_0601d7c8 = unaff_r14;
  }
  return;
}

