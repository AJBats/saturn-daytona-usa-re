extern int PTR_DAT_06019a24;

extern int PTR_DAT_06019a24;

extern int FUN_06019bc8();
extern int FUN_06019db8();
extern int FUN_06019fb2();
extern int FUN_0601a65e();

void FUN_06019928()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  unsigned char bVar6;

  puVar3 = 0x060284AE;

  puVar2 = 0x06049AFC;

  puVar1 = 0x0605D294;

  iVar5 = 0x90;

  if (*(int *)0x06085FF1 == '\x01') {

    *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 4;

    bVar6 = 0;

    do {

      (*(int(*)())puVar3)(8,((unsigned int)(unsigned char)(puVar2 + (unsigned int)(bVar6 << 1))[1] * 0x40 +

                          (unsigned int)(unsigned char)puVar2[(unsigned int)(bVar6 << 1)]) << 1,iVar5,

                        *(int *)(puVar1 + (unsigned int)(bVar6 << 2)));

      puVar4 = 0x06085FF0;

      bVar6 = bVar6 + 1;

    } while (bVar6 < 8);

    (*(int(*)())puVar3)(0xc,((unsigned int)(unsigned char)(puVar2 + (char)*(int *)(0x06085FF0 << 1))[1] * 0x40 +

                          (unsigned int)(unsigned char)puVar2[(char)*(int *)(0x06085FF0 << 1)]) << 1,iVar5,

                      *(int *)(puVar1 + (char)*(int *)(0x06085FF0 << 2)));

    (*(int(*)())puVar3)(0xc,((unsigned int)(unsigned char)puVar2[(char)(*puVar4 << 1) + 1] * 0x40 + 1) << 1,iVar5,

                      0x06049E44);

    if (*puVar4 != '\x06') {

      (*(int(*)())puVar3)(0xc,((unsigned int)(unsigned char)puVar2[0xd] * 0x40 + (unsigned int)(unsigned char)puVar2[0xc] + 0xd) << 1,

                        iVar5,*(int *)0x0605D4F0,puVar2);

    }

    FUN_06019bc8();

    FUN_06019db8();

    FUN_06019fb2();

    FUN_0601a65e();

    *(int *)0x06085FF1 = 0;

  }

  return;

}
