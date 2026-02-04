extern int DAT_06014ae2;

extern int DAT_06014bce;

extern int DAT_06014bd0;

extern int DAT_06014bd2;

extern int DAT_06014bd4;

extern int DAT_06014bd6;

extern int DAT_06014cf2;

extern int PTR_DAT_06014cf4;

extern int PTR_DAT_06014cf4;

void FUN_06014a74()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  unsigned int uVar4;

  short *puVar5;

  unsigned char bVar6;

  unsigned char bVar7;

  puVar2 = 0x06038BD4;

  puVar1 = 0x06085640;

  (*(int(*)())0x06038BD4)(0x100,0);

  (*(int(*)())puVar2)(4,1);

  (*(int(*)())puVar2)(8,1);

  (*(int(*)())puVar2)(0x10,2);

  (*(int(*)())puVar2)(0x20,7);

  (*(int(*)())puVar2)(1,0);

  if (*(int *)0x06085F8A == '\0') {

    (*(int(*)())0x0602853E)(4);

    (*(int(*)())0x06014884)(8,0);

    (*(int(*)())puVar2)(0x10,6);

    (*(int(*)())0x06028560)();

    (*(int(*)())0x060032D4)();

  }

  else {

    (*(int(*)())0x06020CF4)();

    (*(int(*)())0x060078DC)();

  }

  (*(int(*)())puVar2)(0x100,4);

  (*(int(*)())0x0602853E)(0xc);

  (*(int(*)())0x06014884)(0x10,0);

  (*(int(*)())0x06014884)(0x20,0);

  puVar2 = 0x0602761E;

  (*(int(*)())0x0602761E)(0x25F00660,0x06044A64,0x20);

  (*(int(*)())puVar2)(0x25F00680,0x06044A84,0x20);

  (*(int(*)())puVar2)(0x25F006A0,0x06044AA4,0x20);

  (*(int(*)())puVar2)(0x25F006C0,0x06044AC4,0x20);

  puVar3 = 0x25C00000;

  (*(int(*)())puVar2)(0x25C00000 + 0x260 + *(int *)(0x06059FFC << 3),

                    0x06044AE4,0x20);

  (*(int(*)())puVar2)(puVar3 + 0x280 + *(int *)(0x06059FFC << 3),0x06044B24,0x20)

  ;

  (*(int(*)())puVar2)(puVar3 + 0x220 + *(int *)(0x06059FFC << 3),0x06044B04,0x20)

  ;

  (*(int(*)())puVar2)(puVar3 + 0x240 + *(int *)(0x06059FFC << 3),0x06044B44,0x20)

  ;

  puVar2 = 0x0600511E;

  (*(int(*)())0x0600511E)(0x25E73B98,0x00017700,0,8);

  (*(int(*)())puVar2)(0x25E74158,0x000189E0,0,8);

  (*(int(*)())puVar2)(0x25E74AFC,0x0001AFA0,0,8);

  (*(int(*)())puVar2)(0x25E75730,0x0001C980,0,8);

  for (bVar7 = 0; bVar7 < 0x2c; bVar7 = bVar7 + 1) {

    puVar5 = (short *)(puVar1 + (short)((unsigned short)bVar7 * 0x36));

    *puVar5 = 1;

    puVar5[1] = 0x19;

    bVar6 = 0;

    do {

      uVar4 = (unsigned int)bVar6;

      bVar6 = bVar6 + 1;

      *(short *)(puVar1 + (uVar4 << 1) + (int)(short)((unsigned short)bVar7 * 0x36) + 4) = 0x20;

    } while (bVar6 < 0x19);

  }

  (*(int(*)())0x060172BC)();

  (*(int(*)())0x060173AC)();

  *(int *)0x06085F89 = 0;

  *(short *)0x06085F90 = 0;

  *(short *)0x06085F94 = 1;

  (*(int(*)())0x060149CC)();

  if (((unsigned int)(*(short *)0x0607ED8C == 2) & *(unsigned int *)0x0607EBF4) != 0) {

    *(short *)0x06085F90 = 0x27;

    puVar1 = 0x0607E944;

    *(int *)(*(int *)0x0607E944 + (int)DAT_06014cf2) = (int)(char)*(int *)0x06078637;

    *(int *)(*(int *)puVar1 + 0x240) = *(int *)0x06078638;

    *(int *)0x060786A4 = *(int *)0x0607863C;

  }

  return;

}
