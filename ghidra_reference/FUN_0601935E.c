/* FUN_0601935E  0x0601935E */


void FUN_0601935e(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_06019388;
  *(uint *)PTR_DAT_0601937c = *(uint *)PTR_DAT_0601937c | DAT_06019384;
  (*(code *)puVar1)();
                    /* WARNING: Could not recover jumptable at 0x06019370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_06019388)();
  return;
}

