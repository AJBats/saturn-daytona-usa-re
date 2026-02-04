extern int DAT_0601e444;

extern int FUN_0601e488();
extern int FUN_0601e6a4();

void FUN_0601e37c()
{

  short uVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned int uVar5;

  puVar2 = 0x06087094;

  uVar1 = DAT_0601e444;

  uVar5 = 0;

  uVar4 = 0;

  do {

    if (2 < uVar4) {

      *(short *)0x06087084 = (short)uVar5;

      return;

    }

    if (*(short *)(0x06087086 + (unsigned int)uVar4 * 4) != 0) {

      *(unsigned short *)(puVar2 + (uVar5 & 0xffff) * 0x20 + 0x1c) = uVar4;

      iVar3 = FUN_0601e488(uVar5);

      if (iVar3 != 0) {

        if (iVar3 == 1) goto LAB_0601e46a;

        if (iVar3 == 2) {

          iVar3 = FUN_0601e6a4(*(short *)(puVar2 + (uVar5 & 0xffff) * 0x20 + 0x1c));

          if (iVar3 == 0) {

            puVar2[(uVar5 & 0xffff) * 0x20 + 0x1f] = 1;

          }

          else {

            puVar2[(uVar5 & 0xffff) * 0x20 + 0x1f] = (char)uVar1;

          }

        }

      }

      if (*(unsigned int *)(puVar2 + (uVar5 & 0xffff) * 0x20 + 0xc) <

          *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)*0x060877D8 * 4) + 0x20U) {

        puVar2[(uVar5 & 0xffff) * 0x20 + 0x1e] = 0;

      }

      else {

        puVar2[(uVar5 & 0xffff) * 0x20 + 0x1e] = 1;

      }

      uVar5 = uVar5 + 1;

    }

LAB_0601e46a:

    uVar4 = uVar4 + 1;

  } while( 1 );

}
