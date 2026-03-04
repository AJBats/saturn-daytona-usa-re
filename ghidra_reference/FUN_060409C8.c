/* FUN_060409C8  0x060409C8 */


void FUN_060409c8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (*(code *)PTR_FUN_06040a28)(*(undefined4 *)(param_1 + 4),param_2,PTR_DAT_06040a24,param_4,param_1)
  ;
                    /* WARNING: Could not recover jumptable at 0x060409da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_06040a2c)();
  return;
}

