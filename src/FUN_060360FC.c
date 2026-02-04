char * FUN_060360fc(param_1, param_2, param_3)
    char *param_1;
    char *param_2;
    unsigned int param_3;
{

  char uVar1;

  unsigned int uVar2;

  char *puVar3;

  if (param_1 != param_2) {

    if (param_1 < param_2) {

      uVar2 = 0;

      puVar3 = param_1;

      if (param_3 != 0) {

        do {

          uVar1 = *param_2;

          param_2 = param_2 + 1;

          uVar2 = uVar2 + 1;

          *puVar3 = uVar1;

          puVar3 = puVar3 + 1;

        } while (uVar2 < param_3);

      }

    }

    else {

      puVar3 = param_1 + param_3;

      param_2 = param_2 + param_3;

      uVar2 = 0;

      if (param_3 != 0) {

        do {

          param_2 = param_2 + -1;

          uVar2 = uVar2 + 1;

          puVar3 = puVar3 + -1;

          *puVar3 = *param_2;

        } while (uVar2 < param_3);

      }

    }

  }

  return param_1;

}
