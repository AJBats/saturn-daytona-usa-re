extern int DAT_0601a9a4;

extern int DAT_0601aa3a;

extern int DAT_0601aac2;

void FUN_0601a940()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  puVar3 = 0x0605D243;

  puVar2 = 0x0605D24C;

  puVar1 = 0x06063D98;

  if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & (unsigned int)0x00008000) == 0) {

    if ((*(unsigned short *)(0x06063D98 + 2) & DAT_0601a9a4) == 0) {

      if (((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) == 0) {

        if (((*(unsigned short *)0x06063D98 & DAT_0601a9a4) != 0) && (*(int *)0x0605D243 == '\x14')) {

          *(int *)0x0605D24C = *(int *)0x0605D24C + -1;

          *puVar3 = 0;

        }

      }

      else if (*(int *)0x0605D243 == '\x14') {

        *(int *)0x0605D24C = *(int *)0x0605D24C + '\x01';

        *puVar3 = 0;

      }

    }

    else {

      *(int *)0x0605D24C = *(int *)0x0605D24C + -1;

      *puVar3 = 0;

    }

  }

  else {

    *(int *)0x0605D24C = *(int *)0x0605D24C + '\x01';

    *puVar3 = 0;

  }

  if ('1' < (char)*puVar2) {

    *puVar2 = 0;

  }

  if ((char)*puVar2 < '\0') {

    *puVar2 = 0x31;

  }

  if ((*(unsigned short *)(puVar1 + 2) & 0xf8) != 0) {

    *puVar2 = 0;

  }

  if ((*(unsigned short *)(puVar1 + 2) & DAT_0601aa3a) != 0) {

    if (*(int *)0x06085FF6 != '\0') {

      (*(int(*)())0x06012EC4)();

      (*(int(*)())0x06012F00)();

      *(int *)0x06085FF6 = 0;

    }

    puVar1 = 0x06085FF7;

    if ((char)*puVar2 < '$') {

      if (*(int *)0x06085FF7 != '\0') {

        (*(int(*)())0x060191E0)();

        *puVar1 = 0;

      }

    }

    else if (*(int *)0x06085FF7 != '\x01') {

      (*(int(*)())0x06019248)();

      *puVar1 = 1;

    }

    (*(int(*)())0x0601D5F4)(0,0xAE0001FF);

    (*(int(*)())0x0601D5F4)(0,*(int *)(0x06049CFC + (char)(*puVar2 << 2)));

  }

  puVar1 = 0x060283E0;

  (*(int(*)())0x060283E0)(0xc,(int)DAT_0601aac2,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)0x091CFFFF,0,0x06049CDC);

  (*(int(*)())puVar1)(0xc,(int)0x091CFFFF,0x0000E000,

                    *(int *)(0x0605D35C + (char)(*puVar2 << 3)));

  (*(int(*)())puVar1)(0xc,(int)DAT_0601aac2,0x0000E000,

                    *(int *)(0x0605D35C + (char)(*puVar2 << 3) + 4));

  return;

}
