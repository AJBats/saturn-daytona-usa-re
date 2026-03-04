/* FUN_060323B2  0x060323B2 */


void FUN_060323b2(void)

{
  int *piVar1;
  int iVar2;
  int unaff_r14;
  
  FUN_06032e18();
  piVar1 = *(int **)(unaff_r14 + DAT_06032328);
  iVar2 = piVar1[1];
  if (*piVar1 == *(int *)PTR_DAT_0603232c) {
    *(int **)(unaff_r14 + DAT_06032328) = piVar1 + 3;
                    /* WARNING: Could not recover jumptable at 0x06032370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_LAB_06032374 + iVar2 * 4))();
    return;
  }
  FUN_060324d4();
  return;
}

