extern int DAT_0601cb48;

extern int FUN_0601cdc0();
extern int FUN_0601cefc();
extern int FUN_0601d014();
extern int FUN_0601d074();
extern int FUN_0601d12c();

void FUN_0601caee()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  int iVar7;

  int *puVar8;

  int local_48;

  int local_44;

  char *local_40 [3];

  int local_34;

  int local_30;

  char *local_2c [3];

  char local_20 [4];

  puVar6 = 0x0608601C;

  puVar5 = 0x06086024;

  puVar4 = 0x0602766C;

  puVar3 = 0x25F00400;

  puVar2 = 0x25F00200;

  puVar1 = 0x06086020;

  *(int *)0x0608601C = *(int *)0x0608601C + -1;

  puVar8 = (int *)local_20;

  if (((*(unsigned short *)0x06063D98 & DAT_0601cb48) != 0) &&

     (puVar8 = (int *)local_20, *(int *)0x06086024 == 0)) {

    local_2c[0] = (char *)local_2c;

    (*(int(*)())0x060358EC)();

    local_30 = 0;

    local_34 = 0x40680000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 == 0) {

      local_40[0] = (char *)local_40;

      (*(int(*)())0x060358EC)();

      local_44 = 0;

      puVar8 = &local_48;

      local_48 = 0x40568000;

      iVar7 = (*(int(*)())0x06035844)();

      if (iVar7 == 0) {

        *(int *)puVar5 = 3;

      }

      else {

        *(int *)puVar5 = 2;

        puVar8 = &local_48;

      }

    }

    else {

      *(int *)puVar5 = 1;

      puVar8 = &local_34;

    }

  }

  FUN_0601d12c();

  if (*(int *)puVar5 == 0) {

    *(char **)((int)puVar8 + -0xc) = (char *)((int)puVar8 + -0xc);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x10) = 0;

    *(int *)((int)puVar8 + -0x14) = 0x40726000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) goto LAB_0601cda4;

    *(char **)((int)puVar8 + -0x20) = (char *)((int)puVar8 + -0x20);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x24) = 0;

    *(int *)((int)puVar8 + -0x28) = 0x406D4000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x34) = (char *)((int)puVar8 + -0x34);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x38) = 0;

    *(int *)((int)puVar8 + -0x3c) = 0x406D4000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    *(char **)((int)puVar8 + -0x48) = (char *)((int)puVar8 + -0x48);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x4c) = 0;

    *(int *)((int)puVar8 + -0x50) = 0x40680000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x5c) = (char *)((int)puVar8 + -0x5c);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x60) = 0;

    *(int *)((int)puVar8 + -100) = 0x40680000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      FUN_0601d014();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x70) = (char *)((int)puVar8 + -0x70);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x74) = 0;

    *(int *)((int)puVar8 + -0x78) = 0x40608000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0x84) = (char *)((int)puVar8 + -0x84);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x88) = 0;

    *(int *)((int)puVar8 + -0x8c) = 0x40608000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    *(char **)((int)puVar8 + -0x98) = (char *)((int)puVar8 + -0x98);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0x9c) = 0;

    *(int *)((int)puVar8 + -0xa0) = 0x40568000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xac) = (char *)((int)puVar8 + -0xac);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xb0) = 0;

    *(int *)((int)puVar8 + -0xb4) = 0x40568000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      FUN_0601d074();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xc0) = (char *)((int)puVar8 + -0xc0);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xc4) = 0;

    *(int *)((int)puVar8 + -200) = 0x403E0000;

    iVar7 = (*(int(*)())0x06035844)();

    if (iVar7 != 0) {

      FUN_0601cdc0();

      goto LAB_0601cda4;

    }

    *(char **)((int)puVar8 + -0xd4) = (char *)((int)puVar8 + -0xd4);

    (*(int(*)())0x060358EC)();

    *(int *)((int)puVar8 + -0xd8) = 0;

    *(int *)((int)puVar8 + -0xdc) = 0x403E0000;

    iVar7 = (*(int(*)())0x06035B34)();

    if (iVar7 == 0) {

      *(int *)puVar1 = 0;

    }

    if (0 < *(int *)puVar6) {

      FUN_0601cefc();

      goto LAB_0601cda4;

    }

  }

  else {

    if (*(int *)puVar5 == 1) {

      (*(int(*)())puVar4)(puVar2,0x0604880C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0604882C,0x20);

    }

    if (*(int *)puVar5 == 2) {

      FUN_0601d014();

      (*(int(*)())puVar4)(puVar2,0x0604884C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0604886C,0x20);

    }

    if (*(int *)puVar5 == 3) {

      (*(int(*)())puVar4)(puVar2,0x0605D17C,0x20);

      (*(int(*)())puVar4)(puVar3,0x0605D19C,0x20);

    }

  }

  *(int *)0x0605AD10 = 2;

LAB_0601cda4:

  (*(int(*)())0x06026CE0)();

  *(int *)0x06059F44 = 0;

  return;

}
