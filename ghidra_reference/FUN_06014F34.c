void FUN_06014f34()
{

  char *puVar1;

  char *puVar2;

  unsigned short uVar3;

  char *pcVar4;

  char *puVar5;

  puVar2 = 0x06085F90;

  puVar1 = 0x06085F94;

  uVar3 = 0x23;

  if (((unsigned int)(*(int *)0x0605AD10 == 0x19) & *(unsigned int *)0x0607EBF4) == 0) {

    puVar5 = 0x0605B73A;

    if (*(int *)0x0605AD10 == 0x15) {

      uVar3 = 6;

      puVar5 = 0x0605B821;

    }

  }

  else {

    uVar3 = 0x28;

    puVar5 = 0x0605B7A6;

  }

  if ((*(unsigned short *)0x06085F90 <= uVar3 && *(unsigned short *)0x06085F90 != 100) &&

     (*(short *)0x06085F94 =

           *(short *)0x06085F94 - (short)*(int *)0x0606BDF8, *(short *)puVar1 < 1

     )) {

    do {

      uVar3 = (*(int(*)())0x06017372)(0);

      if ((uVar3 & 0xff) == 0x11) {

        return;

      }

      pcVar4 = 0x06084FC8 + (short)((uVar3 & 0xff) * 0x44);

      *pcVar4 = puVar5[(unsigned int)*(unsigned short *)puVar2 * 3];

      pcVar4[0x40] = puVar5[(unsigned int)*(unsigned short *)puVar2 * 3 + 2];

      *(unsigned short *)puVar1 = (unsigned short)(unsigned char)puVar5[(unsigned int)*(unsigned short *)puVar2 * 3 + 1];

      *(short *)puVar2 = *(short *)puVar2 + 1;

      if (*pcVar4 == '\x15') {

        *(short *)puVar2 = 100;

      }

    } while (*(short *)puVar1 == 0);

  }

  return;

}
