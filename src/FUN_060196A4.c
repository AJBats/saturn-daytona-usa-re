extern int DAT_06019762;

extern int DAT_06019864;

extern int PTR_DAT_06019764;

extern int PTR_DAT_06019764;

void FUN_060196a4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  puVar3 = 0x0605D244;

  puVar2 = 0x0605D242;

  puVar1 = 0x06085FF1;

  (*(int(*)())0x06026110)();

  if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019762) != 0) {

    (*(int(*)())0x06028400)(0xc,*(int *)

                    (0x06063750 + (unsigned int)*(unsigned short *)(0x06049AF4 + (char)*((int)(int)puVar3 << 1)) << 3)

               ,((unsigned int)(unsigned char)((char *)(0x06049AEC + (char)*((int)(int)puVar3 << 1)))[1] * 0x40 +

                (unsigned int)(unsigned char)((int *)0x06049AEC)[(char)*((int)(int)puVar3 << 1)]) << 1,

               *(int *)((int)(0x06063750 +

                             (unsigned int)*(unsigned short *)(0x06049AF4 + (char)*((int)(int)puVar3 << 1)) << 3) + 4) +

               (int)(short)PTR_DAT_06019764);

    if ('\x01' < (char)*puVar3) {

      *puVar3 = 0;

    }

    *(int *)0x06059F44 = 0;

    *puVar2 = 0;

    *(int *)0x0605AD10 = 4;

    *puVar1 = 1;

    *(int *)0x06085FF5 = 1;

    return;

  }

  if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06019764) == 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019864) != 0) {

      *puVar1 = 1;

      *puVar2 = 5;

      *puVar3 = *puVar3 + -1;

      if ((char)*puVar3 < '\0') {

        *puVar3 = 3;

      }

    }

  }

  else {

    *puVar1 = 1;

    *puVar2 = 5;

    *puVar3 = *puVar3 + '\x01';

    if ('\x03' < (char)*puVar3) {

      *puVar3 = 0;

    }

  }

  *(int *)0x0605D243 = *(int *)0x0605D243 + '\x01';

  *puVar2 = *puVar2 + '\x01';

  (*(int(*)())(*(int *)((char)*((int)(int)puVar3 << 2) + 0x0605D250)))();

  return;

}
