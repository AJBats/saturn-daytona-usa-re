extern int DAT_0600e0ea;

extern int FUN_0600e71a();
extern int FUN_0600e906();

unsigned int FUN_0600e0c0()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  int iVar8;

  unsigned int uVar9;

  puVar5 = 0x00008000;

  puVar4 = 0x06078900;

  puVar3 = 0x0607EBC4;

  puVar2 = 0x06027CA4;

  puVar1 = 0x0607E940;

  iVar8 = 0x268;

  uVar7 = *(unsigned int *)0x0607EAE0;

  if (uVar7 == 0) {

    for (uVar9 = 1; puVar6 = 0x06030A06, uVar9 < *(unsigned int *)0x0607EA98; uVar9 = uVar9 + 1)

    {

      *(char **)puVar1 = puVar4 + uVar9 * iVar8;

      (*(int(*)())puVar6)();

      (*(int(*)())0x06030EE0)();

      if ((*(unsigned int *)puVar3 & (unsigned int)puVar5) == 0) {

        FUN_0600e71a();

        uVar7 = (unsigned int)*(char *)(*(int *)puVar1 + 1);

        if ((uVar7 & 0x80) != 0) {

          (*(int(*)())0x060061C8)();

          (*(int(*)())puVar2)(0x06063EB0,0);

          (*(int(*)())puVar2)(0x06063E9C,1);

          (*(int(*)())puVar2)(0x06063ED8,2);

          (*(int(*)())puVar2)(0x06063EC4,3);

          uVar7 = (*(int(*)())0x0603053C)(1);

        }

      }

      else {

        uVar7 = FUN_0600e906();

      }

    }

  }

  return uVar7;

}
