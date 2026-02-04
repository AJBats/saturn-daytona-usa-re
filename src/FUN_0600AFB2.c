extern int DAT_0600b100;

extern int DAT_0600b102;

extern int DAT_0600b104;

extern int DAT_0600b106;

extern int FUN_0600ac44();

void FUN_0600afb2()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  puVar2 = 0x06027158;

  puVar1 = 0x06063F46;

  iVar4 = *(int *)0x0607E944;

  *(int *)0x0607E940 = iVar4;

  (*(void(*)())0x06027080)();

  (*(void(*)())0x060270F2)(*(int *)(iVar4 + 0x10),*(int *)(iVar4 + 0x14),

             *(int *)(iVar4 + 0x18));

  (*(void(*)())0x060271A2)(0x00008000 + *(int *)(iVar4 + 0x20));

  (*(void(*)())0x060271EE)(-*(int *)(iVar4 + 0x24));

  if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00800008) == 0) {

    iVar3 = (*(int *)0x06078668 - *(int *)(iVar4 + 0x1c)) +

            *(int *)(0x0605BDCC + (unsigned int)*(unsigned short *)puVar1 * 4);

  }

  else {

    iVar3 = *(int *)(0x0605BDCC + (unsigned int)*(unsigned short *)puVar1 * 4) - *(int *)(iVar4 + 0x1c);

  }

  (*(void(*)())puVar2)(iVar3);

  (*(void(*)())0x060271A2)(*(int *)(iVar4 + DAT_0600b100) + *(int *)(iVar4 + DAT_0600b100 + -0xc));

  if (*(int *)0x06059F30 != 0) {

    (*(void(*)())0x06032158)(*(int *)0x0606213C,*(int *)0x060621E8);

    (*(void(*)())0x06031DF4)(*(int *)0x060620E8,*(short *)0x06089E44,

               *(int *)0x06062190);

    (*(void(*)())0x060270F2)(0,*(int *)(iVar4 + DAT_0600b102));

    (*(void(*)())0x060271EE)(*(int *)(iVar4 + DAT_0600b104));

    (*(void(*)())puVar2)(*(int *)(iVar4 + DAT_0600b106));

    if ((*(int *)0x06082A25 & 2) == 0) {

      FUN_0600ac44(iVar4,0);

    }

    iVar3 = 0;

    if ((*(unsigned char *)(iVar4 + 1) & 1) == 0) {

      iVar4 = *(int *)0x06083258;

    }

    else {

      iVar3 = 0xd;

      iVar4 = (int)(char)0x06044740[*(unsigned short *)puVar1] + *(int *)0x06083258;

    }

    (*(void(*)())puVar2)(iVar4);

    iVar3 = iVar3 * 4;

    (*(void(*)())0x06032158)(*(int *)(0x0606212C + iVar3),*(int *)(0x060621D8 + iVar3));

    (*(void(*)())0x06031DF4)(*(int *)(0x060620D8 + iVar3),*(short *)0x06089E44,

               *(int *)(0x06062180 + iVar3));

  }

  if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x20020000) != 0) {

    (*(void(*)())0x0601C3E4)();

  }

  *(int *)0x0608A52C = *(int *)0x0608A52C + -0x30;

  return;

}
