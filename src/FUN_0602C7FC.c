extern int DAT_0602c898;

extern int DAT_0602c89c;

extern int DAT_0602c8a0;

extern int DAT_0602c8a4;

extern int DAT_0602c8a8;

void FUN_0602c7fc(param_1)
    unsigned int param_1;
{

  int in_r0;

  unsigned int uVar1;

  unsigned int uVar2;

  char cVar3;

  if (*(int *)(in_r0 + 8) < 0xb) {

    return;

  }

  cVar3 = ((int)DAT_0602c898 & param_1) != 0;

  param_1 = param_1 & ~(int)DAT_0602c898;

  uVar1 = param_1 & ~(int)DAT_0602c89c;

  if (((int)DAT_0602c89c & param_1) != 0) {

    cVar3 = cVar3 + '\x01';

  }

  uVar2 = uVar1 & ~(int)DAT_0602c8a0;

  if (((int)DAT_0602c8a0 & uVar1) != 0) {

    cVar3 = cVar3 + '\x01';

  }

  uVar1 = uVar2 & ~(int)DAT_0602c8a4;

  if (((int)DAT_0602c8a4 & uVar2) != 0) {

    cVar3 = cVar3 + '\x01';

  }

  if (((int)DAT_0602c8a8 & uVar1) != 0) {

    cVar3 = cVar3 + '\x01';

  }

  if ((uVar1 & ~(int)DAT_0602c8a8) != 0) {

    cVar3 = cVar3 + '\x01';

  }

  if (cVar3 != '\0') {

    if (cVar3 == '\x01') {

      return;

    }

    if (cVar3 == '\x02') {

      return;

    }

    if (cVar3 == '\x04') {

      return;

    }

    (*0x0602ECCC)();

  }

  return;

}
