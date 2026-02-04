extern int DAT_0600b47a;

extern int DAT_0600b47c;

extern int DAT_0600b47e;

extern int DAT_0600b630;

extern int DAT_0600b632;

extern int DAT_0600b634;

extern int DAT_0600b636;

extern int PTR_DAT_0600b480;

extern int PTR_DAT_0600b480;

extern int PTR_DAT_0600b638;

extern int PTR_DAT_0600b638;

extern int FUN_0600a76c();

void FUN_0600b340()
{

  char *puVar1;

  int iVar2;

  char *unaff_r11;

  int iVar3;

  char *puVar4;

  char *unaff_r12;

  char *puVar5;

  char *puVar6;

  char *unaff_r13;

  char *puVar7;

  int iVar8;

  iVar3 = *(int *)0x0607EB8C;

  iVar8 = *(int *)0x0607E944;

  *(int *)0x0607E940 = iVar8;

  iVar2 = *(int *)0x0607EAD8;

  puVar5 = 0x06063434;

  puVar7 = 0x06063488;

  if (((iVar2 != 0) && (puVar5 = 0x06063450, puVar7 = 0x060634A4, iVar2 != 1)) &&

     (puVar5 = unaff_r12, puVar7 = unaff_r13, iVar2 == 2)) {

    puVar5 = 0x0606346C;

    puVar7 = 0x060634C0;

  }

  (*(void(*)())0x06027080)();

  (*(void(*)())0x060270F2)(*(int *)(iVar8 + 0x10),*(int *)(iVar8 + 0x14),

             *(int *)(iVar8 + 0x18));

  (*(void(*)())0x060271A2)(*(int *)(iVar8 + 0x20));

  (*(void(*)())0x060271EE)(*(int *)(iVar8 + 0x24));

  (*(void(*)())0x06027158)(*(int *)(iVar8 + 0x1c));

  (*(void(*)())0x060271A2)(*(int *)(iVar8 + DAT_0600b47a) + *(int *)(iVar8 + DAT_0600b47a + -0xc));

  if (*(int *)0x06059F30 != 0) {

    (*(void(*)())0x06032158)(*(int *)(puVar7 + 0x18),*(int *)0x06063510);

    puVar4 = 0x06089E98;

    (*(void(*)())0x06031DF4)(*(int *)(puVar5 + 0x18),*(short *)0x06089E98,

               *(int *)0x060634F4);

    (*(void(*)())0x060270F2)(0,*(int *)(iVar8 + DAT_0600b47c));

    (*(void(*)())0x060271EE)(*(int *)(iVar8 + DAT_0600b47e));

    (*(void(*)())0x06027158)(*(int *)(iVar8 + PTR_DAT_0600b480) + *(int *)0x06083258)

    ;

    iVar2 = *(int *)(iVar3 + 0xc) * 4;

    (*(void(*)())0x06032158)(*(int *)(puVar7 + iVar2),*(int *)(0x060634F8 + iVar2));

    iVar2 = *(int *)(iVar3 + 0xc) * 4;

    (*(void(*)())0x06031DF4)(*(int *)(puVar5 + iVar2),*(short *)puVar4,

               *(int *)(0x060634DC + iVar2));

    FUN_0600a76c();

  }

  *(int *)0x0608A52C = *(int *)0x0608A52C + -0x30;

  if (*(int *)0x0607867C == '\0') {

    return;

  }

  iVar3 = *(int *)0x0607EB8C;

  iVar8 = *(int *)0x0607E944;

  *(int *)0x0607E940 = iVar8;

  puVar7 = 0x06078670;

  puVar5 = 0x00008000;

  iVar2 = *(int *)0x0607EAD8;

  puVar4 = 0x06063434;

  puVar6 = 0x06063488;

  if (((iVar2 != 0) && (puVar4 = 0x06063450, puVar6 = 0x060634A4, iVar2 != 1)) &&

     (puVar4 = unaff_r11, puVar6 = unaff_r12, iVar2 == 2)) {

    puVar4 = 0x0606346C;

    puVar6 = 0x060634C0;

  }

  *(int *)0x06078670 =

       *(int *)0x06078670 +

       ((int)(0x00008000 + (*(int *)(iVar8 + 0x10) - *(int *)0x06078670) +

             ((int)(0x00008000 + (*(int *)(iVar8 + 0x10) - *(int *)0x06078670)) < 0)) >>

       1);

  iVar2 = *(int *)(iVar8 + 0x14) - *(int *)(puVar7 + 4);

  *(int *)(puVar7 + 4) = *(int *)(puVar7 + 4) + ((int)(iVar2 + (unsigned int)(iVar2 < 0)) >> 1);

  puVar1 = 0x06027080;

  iVar2 = (*(int *)(iVar8 + 0x18) - *(int *)(puVar7 + 8)) + (int)DAT_0600b630;

  *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + ((int)(iVar2 + (unsigned int)(iVar2 < 0)) >> 1);

  (*(void(*)())puVar1)();

  (*(void(*)())0x060270F2)(*(int *)puVar7,*(int *)(puVar7 + 4),*(int *)(puVar7 + 8));

  (*(void(*)())0x060271A2)(*(int *)(iVar8 + 0x20));

  (*(void(*)())0x060271EE)(*(int *)(iVar8 + 0x24));

  (*(void(*)())0x06027158)(*(int *)(iVar8 + 0x1c));

  (*(void(*)())0x060271A2)(*(int *)(iVar8 + DAT_0600b632) + *(int *)(iVar8 + DAT_0600b632 + -0xc));

  if (*(int *)0x06059F30 != 0) {

    (*(void(*)())0x06027124)(puVar5,puVar5,puVar5);

    (*(void(*)())0x06032158)(*(int *)(puVar6 + 0x18),*(int *)0x06063510);

    puVar5 = 0x06089E98;

    (*(void(*)())0x06031DF4)(*(int *)(puVar4 + 0x18),*(short *)0x06089E98,

               *(int *)0x060634F4);

    (*(void(*)())0x060270F2)(0,*(int *)(iVar8 + DAT_0600b634));

    (*(void(*)())0x060271EE)(*(int *)(iVar8 + DAT_0600b636));

    (*(void(*)())0x06027158)(*(int *)(iVar8 + PTR_DAT_0600b638) + *(int *)0x06083258)

    ;

    iVar2 = *(int *)(iVar3 + 0xc) * 4;

    (*(void(*)())0x06032158)(*(int *)(puVar6 + iVar2),*(int *)(0x060634F8 + iVar2));

    iVar2 = *(int *)(iVar3 + 0xc) * 4;

    (*(void(*)())0x06031DF4)(*(int *)(puVar4 + iVar2),*(short *)puVar5,

               *(int *)(0x060634DC + iVar2));

  }

  *(int *)0x0608A52C = *(int *)0x0608A52C + -0x30;

  return;

}
