extern int DAT_0602f786;

extern int DAT_0602f788;

extern int DAT_0602f78a;

void FUN_0602f71c()
{

  short sVar1;

  int in_r0;

  unsigned int *puVar2;

  unsigned int uVar3;

  unsigned char bVar4;

  uVar3 = (unsigned int)DAT_0602f786;

  puVar2 = (unsigned int *)(DAT_0602f788 + in_r0);

  bVar4 = (uVar3 & *puVar2) != 0;

  if ((uVar3 & puVar2[1]) != 0) {

    bVar4 = bVar4 + 1;

  }

  if ((uVar3 & puVar2[2]) != 0) {

    bVar4 = bVar4 + 1;

  }

  if ((uVar3 & puVar2[3]) != 0) {

    bVar4 = bVar4 + 1;

  }

  if (bVar4 == 0) {

    return;

  }

  if ((((*puVar2 | puVar2[1] | puVar2[2] | puVar2[3]) & 0x10) == 0) &&

     (sVar1 = *(short *)(DAT_0602f78a + in_r0), sVar1 < 10)) {

    if (7 < sVar1) {

      return;

    }

    if ((sVar1 != 4) && (sVar1 != 5)) {

      if (bVar4 < 3) {

        return;

      }

      return;

    }

  }

  return;

}
