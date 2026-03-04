/* FUN_0601A578  0x0601A578 */


void FUN_0601a578(void)

{
  undefined4 unaff_r14;
  undefined1 uVar1;
  
  *(undefined4 *)PTR_DAT_0601a60c = unaff_r14;
  *(uint *)PTR_DAT_0601a610 = *(uint *)PTR_DAT_0601a610 | DAT_0601a614;
  (*(code *)PTR_FUN_0601a618)();
  (*(code *)PTR_FUN_0601a618)();
  (*(code *)PTR_FUN_0601a624)(PTR_DAT_0601a620,PTR_DAT_0601a61c);
  (*(code *)PTR_FUN_0601a624)(PTR_DAT_0601a62c,PTR_DAT_0601a628);
  (*(code *)PTR_FUN_0601a638)(4,*(undefined4 *)PTR_DAT_0601a630);
  *PTR_DAT_0601a63c = 1;
  FUN_06019928();
  FUN_0601a65e();
  FUN_0601a80c();
  FUN_0601a940();
  uVar1 = (undefined1)unaff_r14;
  *PTR_DAT_0601a640 = uVar1;
  *PTR_DAT_0601a644 = uVar1;
  *PTR_DAT_0601a648 = uVar1;
  (*(code *)PTR_FUN_0601a64c)();
  (*(code *)PTR_FUN_0601a650)();
  return;
}

