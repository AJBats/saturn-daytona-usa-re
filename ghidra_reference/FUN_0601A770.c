/* FUN_0601A770  0x0601A770 */


void FUN_0601a770(void)

{
  if (*PTR_DAT_0601a7e4 != '\0') {
    (*(code *)PTR_FUN_0601a7e8)();
    (*(code *)PTR_FUN_0601a7ec)();
    *PTR_DAT_0601a7e4 = 0;
  }
  if (*PTR_DAT_0601a7f0 != '\0') {
    (*(code *)PTR_FUN_0601a7f4)();
    *PTR_DAT_0601a7f0 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0601a7a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_0601a7fc)(0,DAT_0601a7f8);
  return;
}

