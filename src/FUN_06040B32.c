char * FUN_06040b32(param_1, param_2)
    int *param_1;
    int param_2;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  int local_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  int iStack_14;

  int uStack_10;

  if (((int *)0x0606367C)[0x10] == '\0') {

    uStack_10 = param_2;

    iVar2 = (*(void(*)())0x060411A0)(param_1[1],param_1[4],param_2,&local_24,&iStack_20);

    if (iVar2 == 0) {

      iVar2 = (*(void(*)())0x0604188C)();

      if (iVar2 == 0) {

        if (iStack_20 < 1) {

          puVar1 = (char *)0x0;

        }

        else {

          (*(void(*)())0x06040220)(*param_1,0,0,&iStack_18,&iStack_14,&iStack_1c,0,0);

          puVar1 = 0x0606367C;

          if (((iStack_14 <= param_1[2] + param_1[4] + local_24) && (iStack_1c != 0)) &&

             (0 < local_24)) {

            iStack_20 = iStack_20 - (iStack_18 - iStack_1c);

          }

          uVar3 = (*(void(*)())0x06035C48)();

          *(int *)puVar1 = uVar3;

          *(int *)(puVar1 + 4) = 0;

          *(int *)(puVar1 + 8) = iStack_20;

          *(int *)(puVar1 + 0xc) = local_24;

          puVar1[0x10] = 1;

        }

      }

      else {

        puVar1 = (char *)0x0;

      }

    }

    else {

      puVar1 = (char *)0x0;

    }

  }

  else {

    puVar1 = (char *)0x0;

  }

  return puVar1;

}
