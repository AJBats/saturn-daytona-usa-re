extern int DAT_06019b22;

extern int DAT_06019bfc;

extern int PTR_DAT_06019b24;

extern int PTR_DAT_06019b24;

void FUN_06019a48()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  puVar2 = 0x06085FF0;

  puVar1 = 0x06085FF1;

  if (*(int *)0x06085FF3 == '\0') {

    iVar3 = (int)DAT_06019b22;

    if (((unsigned int)*(unsigned short *)(0x06063D98 + 2) & iVar3 + 0x70U) == 0) {

      if ((*(unsigned short *)(0x06063D98 + 2) & PTR_DAT_06019b24) == 0) {

        if ((*(unsigned short *)(0x06063D98 + 2) & DAT_06019bfc) != 0) {

          (*(void(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)(0x06049AFC + (char)*0x06085FF0 * 2)[1] * 0x40 +

                         (unsigned int)(unsigned char)0x06049AFC[(char)*0x06085FF0 * 2]) * 2,iVar3,

                     *(int *)0x0605D4F0);

          *puVar2 = *puVar2 + -1;

          if ((char)*puVar2 < '\0') {

            *puVar2 = 7;

          }

          *puVar1 = 1;

        }

      }

      else {

        (*(void(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)(0x06049AFC + (char)*0x06085FF0 * 2)[1] * 0x40 +

                       (unsigned int)(unsigned char)0x06049AFC[(char)*0x06085FF0 * 2]) * 2,iVar3,

                   *(int *)0x0605D4F0);

        *puVar2 = *puVar2 + '\x01';

        if ('\a' < (char)*puVar2) {

          *puVar2 = 0;

        }

        *puVar1 = 1;

      }

    }

    else {

      (*(void(*)())0x060284AE)(0xc,((unsigned int)(unsigned char)(0x06049AFC + (char)*0x06085FF0 * 2)[1] * 0x40 +

                     (unsigned int)(unsigned char)0x06049AFC[(char)*0x06085FF0 * 2]) * 2,iVar3,

                 *(int *)0x0605D4F0);

      if (*puVar2 == '\a') {

        *(int *)0x0605AD10 = 7;

      }

      else {

        *puVar2 = 7;

        *puVar1 = 1;

        *(int *)0x06059F44 = 0;

        (*(void(*)())0x06026CE0)();

      }

    }

  }

  *(int *)0x0605D243 = *(int *)0x0605D243 + '\x01';

  *(int *)0x0605D242 = *(int *)0x0605D242 + '\x01';

  (**(void **)(0x0605D260 + (char)*puVar2 * 4))();

  return;

}
