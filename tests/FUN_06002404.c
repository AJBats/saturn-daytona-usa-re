void FUN_06002404(param_1, param_2, param_3)
    short *param_1;
    short *param_2;
    int param_3;
{

  int local_c;

  short *puStack_8;

  short *puStack_4;

  

  local_c = param_3;

  puStack_8 = param_2;

  puStack_4 = param_1;

  do {

    *puStack_8 = *puStack_4;

    puStack_8 = puStack_8 + 1;

    puStack_4 = puStack_4 + 1;

    local_c = local_c + -1;

  } while (local_c != 0);

  return;

}
