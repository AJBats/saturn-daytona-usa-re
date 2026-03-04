/* FUN_0601A574  0x0601A574 */


void FUN_0601a574(void)

{
  *(undefined4 *)PTR_DAT_0601a60c = 0;
  *(uint *)PTR_DAT_0601a610 = *(uint *)PTR_DAT_0601a610 | DAT_0601a614;
  (*(code *)PTR_FUN_0601a618)();
  (*(code *)PTR_FUN_0601a618)();
  (*(code *)PTR_FUN_0601a624)(PTR_DAT_0601a620,PTR_DAT_0601a61c,0,9);
  (*(code *)PTR_FUN_0601a624)(PTR_DAT_0601a62c,PTR_DAT_0601a628,0,8);
  (*(code *)PTR_FUN_0601a638)
            (4,*(undefined4 *)PTR_DAT_0601a630,0,PTR_DAT_0601a634 + *(int *)(PTR_DAT_0601a630 + 4),
             PTR_DAT_0601a630);
  *PTR_DAT_0601a63c = 1;
  FUN_06019928();
  FUN_0601a65e();
  FUN_0601a80c();
  FUN_0601a940();
  *PTR_DAT_0601a640 = 0;
  *PTR_DAT_0601a644 = 0;
  *PTR_DAT_0601a648 = 0;
  (*(code *)PTR_FUN_0601a64c)();
  (*(code *)PTR_FUN_0601a650)();
  return;
}

