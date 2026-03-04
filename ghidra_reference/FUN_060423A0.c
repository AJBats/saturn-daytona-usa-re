/* FUN_060423A0  0x060423A0 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_060423a0(void)

{
  undefined1 local_10 [16];
  
  (*ram0x060423f8)(local_10);
  *(undefined1 *)(*(int *)PTR_DAT_060423fc + 0x40) = local_10[0];
  return;
}

