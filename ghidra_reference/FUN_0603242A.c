/* FUN_0603242A  0x0603242A */


void FUN_0603242a(void)

{
  code *in_r0;
  int *piVar1;
  int iVar2;
  int unaff_r14;
  
  (*in_r0)();
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

