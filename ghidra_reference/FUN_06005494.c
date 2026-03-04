/* FUN_06005494  0x06005494 */


void FUN_06005494(int *param_1,int *param_2)

{
  if (*PTR_DAT_06005504 != '\0') {
    (*(code *)PTR_FUN_06005510)(DAT_0600550c,PTR_DAT_06005508);
  }
  (*(code *)PTR_FUN_06005514)(-param_2[2]);
  (*(code *)PTR_FUN_06005518)(-*param_2);
  (*(code *)PTR_FUN_0600551c)(-param_2[1]);
  (*(code *)PTR_FUN_06005520)(-*param_1,-param_1[1],-param_1[2]);
  (*(code *)PTR_FUN_06005528)();
  return;
}

