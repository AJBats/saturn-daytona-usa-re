int FUN_060408b0(param_1, param_2, param_3)
    int *param_1;
    int param_2;
    int *param_3;
{

  int iVar1;

  int local_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  int uStack_14;

  uStack_14 = param_2;

  iVar1 = (*0x060411A0)(param_1[1],param_1[4],param_2,&local_24,param_3);

  if (iVar1 == 0) {

    iVar1 = (*0x0604188C)();

    if (iVar1 == 0) {

      if ((((param_3 != (int *)0x0) &&

           ((*0x06040220)(*param_1,0,0,&iStack_1c,&iStack_18,&iStack_20,0,0),

           iStack_18 <= param_1[2] + param_1[4] + local_24)) && (iStack_20 != 0)) && (0 < local_24))

      {

        *param_3 = *param_3 - (iStack_1c - iStack_20);

      }

    }

    else {

      local_24 = 0;

    }

  }

  else {

    local_24 = 0;

  }

  return local_24;

}
