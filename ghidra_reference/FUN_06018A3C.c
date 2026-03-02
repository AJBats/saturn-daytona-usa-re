extern int DAT_06018b8e;

extern int DAT_06018cc6;

void FUN_06018a3c()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int uVar6;

  int local_30;

  char uStack_2c;

  char uStack_2b;

  int uStack_28;

  char uStack_24;

  char uStack_23;

  char uStack_20;

  puVar1 = 0x0607EAD8;

  if (*(int *)0x06078868 < 10) {

    *(int *)0x0607867C = 0;

    *(int *)0x06083255 = 0;

  }

  else {

    if (*(int *)0x06078868 < 0xc) {

      *(int *)0x0607867C = 0;

    }

    else {

      *(int *)0x0607867C = 1;

    }

    *(int *)0x06083255 = 1;

  }

  if (*(int *)0x0605AD08 == 0) {

    (*(int(*)())0x0600736C)();

    (*(int(*)())0x06012DB4)(*(int *)puVar1);

    (*(int(*)())(*(int *)(0x0605D1BC + *(int *)((int)(int)puVar1 << 2))))();

    (*(int(*)())0x06012D7C)(*(int *)puVar1);

    if (*(int *)0x06078635 == '\0') {

      (*(int(*)())0x06012E7C)();

    }

    if (*(short *)0x0607ED8C == 0) {

      (*(int(*)())0x06018FF8)();

    }

  }

  if (*(short *)0x0607ED8C != 0) {

    (*(int(*)())0x06018FF8)();

  }

  if ((*(unsigned int *)0x0607EBC4 & (int)DAT_06018b8e) == 0) {

    uVar6 = 0;

    iVar5 = 3;

  }

  else {

    if (*(int *)0x0605AB18 == '\0') {

      if (*(int *)0x0605AD00 == 2) {

        (*(int(*)())0x06018E1E)((unsigned char)*(int *)0x06078648 + 6);

        local_30 = 2;

        uStack_2c = 6;

        uStack_2b = 1;

        uStack_28 = 2;

        uStack_24 = 9;

        uStack_23 = 99;

        uStack_20 = 0x8f;

        (*(int(*)())0x06034D1C)(&local_30);

      }

      else {

        (*(int(*)())0x06018DDC)((unsigned char)*(int *)0x06078648 + 6,(unsigned char)*(int *)0x06078648 + 6,0xf);

      }

      goto LAB_06018bd8;

    }

    uVar6 = 0xf;

    iVar5 = (int)(char)((int *)0x0605D23C)[(unsigned char)*(int *)0x06078648];

  }

  (*(int(*)())0x06018DDC)(iVar5,iVar5,uVar6);

LAB_06018bd8:

  *(int *)0x0607EBE4 = 0;

  iVar4 = *(int *)((int)(int)puVar1 << 1);

  *(unsigned int *)0x0607EA9C = (unsigned int)*(unsigned short *)(0x0604806C + iVar4);

  *(char **)0x0607EB84 = 0x060D5840;

  *(char **)0x0607EB88 = 0x060C6000;

  *(char **)0x06063F3C = 0x0604800C + *(int *)((int)(int)puVar1 << 3);

  iVar5 = (*(int(*)())0x06035280)();

  *(int *)0x06063F18 = iVar5 + -1;

  *(int *)0x060786AC = 0;

  *(int *)0x06063F1C = 1;

  *(int *)0x06063F20 = 0;

  *(int *)0x06063F24 = 0;

  *(int *)0x06086034 = 0;

  puVar2 = 0x06063F28;

  iVar5 = (int)(char)((char)*(int *)0x0605AD00 * '\x06');

  *(unsigned int *)0x06063F28 = (unsigned int)*(unsigned short *)(0x0604805A + iVar4 + iVar5);

  *(unsigned int *)0x0607EA98 = (unsigned int)*(unsigned short *)(0x06048072 + iVar4);

  *(unsigned int *)0x0607EAA0 = (unsigned int)*(unsigned short *)(0x06048024 + iVar4);

  puVar3 = 0x0607EAAC;

  *(unsigned int *)0x0607EAAC = (unsigned int)*(unsigned short *)(0x0604802A + iVar4 + iVar5);

  *(unsigned int *)puVar3 =

       *(int *)puVar3 +

       (unsigned int)*(unsigned short *)

              (0x0604803C + iVar4 + (char)((char)*(int *)0x0605AD0C * '\x06')) *

       *(int *)puVar2;

  (*(int(*)())0x0602761E)(0x25C00220 + *(int *)(0x06059FFC << 3),0x0605CDDC,0xa0);

  (*(int(*)())0x060149E0)();

  (*(int(*)())0x060148FC)();

  (*(int(*)())0x06026CE0)();

  *(int *)0x06059F44 = 0;

  (*(int(*)())0x0600A026)();

  *(int *)0x0605AD08 = 0;

  *(char **)0x0607E944 = 0x06078900;

  (*(int(*)())0x06010994)();

  (*(int(*)())0x060038D4)();

  (*(int(*)())0x060039C8)();

  (*(int(*)())(*(int *)(0x0605D1CC + *(int *)((int)(int)puVar1 << 2))))();

  (*(int(*)())0x060032D4)();

  (*(int(*)())0x06003430)();

  (*(int(*)())0x06014994)();

  (*(int(*)())0x06021128)();

  return;

}
