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

  (*(void(*)())0x06038BD4)((int)DAT_06014ae2,0);

  (*(void(*)())puVar2)(4,1);

  (*(void(*)())puVar2)(8,1);

  (*(void(*)())puVar2)(0x10,2);

  (*(void(*)())puVar2)(0x20,7);

  (*(void(*)())puVar2)(1,0);

  if (*(int *)0x06085F8A == '\0') {

    (*(void(*)())0x0602853E)(4);

    (*(void(*)())0x06014884)(8,0);

    (*(void(*)())puVar2)(0x10,6);

    (*(void(*)())0x06028560)();

    (*(void(*)())0x060032D4)();

  }

  else {

    (*(void(*)())0x06020CF4)();

    (*(void(*)())0x060078DC)();

  }

  (*(void(*)())puVar2)((int)DAT_06014bce,4);

  (*(void(*)())0x0602853E)(0xc);

  (*(void(*)())0x06014884)(0x10,0);

  (*(void(*)())0x06014884)(0x20,0);

  puVar2 = 0x0602761E;

  (*(void(*)())0x0602761E)(0x25F00660,0x06044A64,0x20);

  (*(void(*)())puVar2)(0x25F00680,0x06044A84,0x20);

  (*(void(*)())puVar2)(0x25F006A0,0x06044AA4,0x20);

  (*(void(*)())puVar2)(0x25F006C0,0x06044AC4,0x20);

  puVar3 = 0x25C00000;

  (*(void(*)())puVar2)(0x25C00000 + (int)DAT_06014bd0 + *(int *)0x06059FFC * 8,

                    0x06044AE4,0x20);

  (*(void(*)())puVar2)(puVar3 + (int)DAT_06014bd2 + *(int *)0x06059FFC * 8,0x06044B24,0x20)

  ;

  (*(void(*)())puVar2)(puVar3 + (int)DAT_06014bd4 + *(int *)0x06059FFC * 8,0x06044B04,0x20)

  ;

  (*(void(*)())puVar2)(puVar3 + (int)DAT_06014bd6 + *(int *)0x06059FFC * 8,0x06044B44,0x20)

  ;

  puVar2 = 0x0600511E;

  (*(void(*)())0x0600511E)(0x25E73B98,0x00017700,0,8);

  (*(void(*)())puVar2)(0x25E74158,0x000189E0,0,8);

  (*(void(*)())puVar2)(0x25E74AFC,0x0001AFA0,0,8);

  (*(void(*)())puVar2)(0x25E75730,0x0001C980,0,8);

  for (bVar7 = 0; bVar7 < 0x2c; bVar7 = bVar7 + 1) {

    puVar5 = (short *)(puVar1 + (short)((unsigned short)bVar7 * 0x36));

    *puVar5 = 1;

    puVar5[1] = 0x19;

    bVar6 = 0;

    do {

      uVar4 = (unsigned int)bVar6;

      bVar6 = bVar6 + 1;

      *(short *)(puVar1 + uVar4 * 2 + (int)(short)((unsigned short)bVar7 * 0x36) + 4) = 0x20;

    } while (bVar6 < 0x19);

  }

  (*(void(*)())0x060172BC)();

  (*(void(*)())0x060173AC)();

  *(int *)0x06085F89 = 0;

  *(short *)0x06085F90 = 0;

  *(short *)0x06085F94 = 1;

  (*(void(*)())0x060149CC)();

  if (((unsigned int)(*(short *)0x0607ED8C == 2) & *(unsigned int *)0x0607EBF4) != 0) {

    *(short *)0x06085F90 = 0x27;

    puVar1 = 0x0607E944;

    *(int *)(*(int *)0x0607E944 + (int)DAT_06014cf2) = (int)(char)*0x06078637;

    *(int *)(*(int *)puVar1 + (int)PTR_DAT_06014cf4) = *(int *)0x06078638;

    *(int *)0x060786A4 = *(int *)0x0607863C;

  }

  return;

}
