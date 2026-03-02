extern int DAT_0601dd30;

extern int DAT_0601dd34;

extern int DAT_0601dd38;

extern int DAT_0601dd3a;

extern int DAT_0601de24;

extern int DAT_0601de26;

extern int FUN_0601ddf6();
extern int FUN_0601e26c();

int FUN_0601dbb8()
{

  char cVar1;

  short sVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  int uVar10;

  int iVar11;

  char *puVar12;

  puVar8 = 0x06087070;

  puVar7 = 0x06087068;

  puVar6 = 0x06087074;

  puVar5 = 0x06028400;

  puVar4 = 0x0608706C;

  puVar3 = 0x00009000;

  if (*(int *)0x060786AC != 0) {

    uVar10 = FUN_0601ddf6();

    return uVar10;

  }

  if ((((unsigned int)(*(int *)0x06087068 == '\0') & *(unsigned int *)0x0607EBF4) != 0) ||

     (((unsigned int)((((int *)0x06078900)[3] & 8) == 0) &

      (unsigned int)(*(int *)0x06087068 == '\0') & *(unsigned int *)0x0607EABC) != 0)) {

    *(int *)0x06087068 = 1;

    *(short *)0x0608706A = DAT_0601dd30;

    *(int *)0x0605DFED = 0;

    *(int *)puVar8 = *(int *)0x060786A0;

    puVar12 = 0x0605DDB4;

    *(int *)puVar6 = 3;

    puVar9 = 0x0605DDD4;

    if (*(int *)0x0607EAD8 == 2) {

      *(int *)puVar6 = 6;

      puVar12 = puVar9;

    }

    iVar11 = (*(int(*)())0x060350B0)();

    *(int *)puVar4 = *(int *)(puVar12 + (iVar11 << 2));

    *(int *)0x0608707C = 9;

    if (*(unsigned int *)puVar8 < *(unsigned int *)puVar4) {

      *(int *)0x0608707C = 10;

      *(int *)puVar4 = *(int *)puVar8;

      iVar11 = (*(int(*)())0x060350B0)();

      *(int *)(puVar12 + (iVar11 << 2)) = *(int *)puVar8;

    }

  }

  if (*puVar7 == '\0') {

    uVar10 = 0;

  }

  else {

    cVar1 = *(int *)0x0605DFED;

    *(int *)0x0605DFED = cVar1 + 0x30U;

    puVar6 = 0x060639F8;

    if ((short)(unsigned short)(unsigned char)(cVar1 + 0x30U) < DAT_0601dd34) {

      iVar11 = (*(int(*)())0x060350B0)();

      (*(int(*)())puVar5)(8,0x0605E008 + iVar11 * 0xe);

      puVar12 = 0x060639E0;

      (*(int(*)())puVar5)(8,*(int *)0x060639D8,0x842,

                        *(int *)(0x060639E0 + 4) + (unsigned int)(unsigned char)*(int *)(0x0608707C << 12));

      (*(int(*)())puVar5)(8,*(int *)puVar12,0x942,puVar3 + *(int *)(puVar12 + 4));

      FUN_0601e26c(*(int *)puVar4);

      (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601de24,puVar3 + *(int *)(puVar6 + 4));

      if (*(char **)puVar8 < 0x000927BF) {

        FUN_0601e26c(*(int *)puVar8);

      }

      else {

        FUN_0601e26c(0x000927BF);

      }

      uVar10 = (*(int(*)())puVar5)(8,0x0605DFF4,(int)DAT_0601de26,

                                 puVar3 + *(int *)(0x060639F8 + 4));

    }

    else {

      uVar10 = FUN_0601ddf6();

    }

    sVar2 = *(short *)0x0608706A;

    *(short *)0x0608706A = sVar2 + -1;

    if ((short)(sVar2 + -1) == 0) {

      *puVar7 = 0;

      uVar10 = FUN_0601ddf6();

      return uVar10;

    }

  }

  return uVar10;

}
