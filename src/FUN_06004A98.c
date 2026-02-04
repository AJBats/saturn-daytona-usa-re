extern int DAT_06004dda;

extern int DAT_06004ed0;

extern int DAT_06004ed2;

extern int PTR_DAT_06004ac8;

extern int PTR_DAT_06004ac8;

extern int PTR_DAT_06004bc0;

extern int PTR_DAT_06004bc0;

extern int PTR_DAT_06004ddc;

extern int PTR_DAT_06004ddc;

void FUN_06004a98()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned int uVar6;

  int *puVar7;

  int *puVar8;

  char local_7c;

  char uStack_7b;

  char uStack_7a;

  char uStack_79;

  char uStack_77;

  char uStack_76;

  char uStack_74;

  int uStack_70;

  int iStack_6c;

  int uStack_68;

  int iStack_64;

  char auStack_30 [8];

  char uStack_28;

  char uStack_27;

  char uStack_26;

  char uStack_25;

  char uStack_24;

  char uStack_23;

  puVar4 = 0x06087C84;

  puVar3 = 0x25FE00A4;

  puVar2 = 0x06037660;

  puVar1 = 0x06000344;

  (*(void(*)())(*(int *)0x06000344))(0xffffffff,(int)PTR_DAT_06004ac8);

  puVar8 = (int *)0x25E00000;

  for (puVar5 = 0x00020000; puVar5 != (char *)0x0; puVar5 = puVar5 + -2) {

    puVar7 = puVar8 + 1;

    *puVar8 = 0;

    puVar8 = puVar8 + 2;

    *puVar7 = 0;

  }

  (*(void(*)())0x06038300)();

  (*(void(*)())0x06036F0C)(0,0,1);

  (*(void(*)())0x06038A64)(1);

  puVar5 = 0x06086028;

  *(short *)0x06086028 = (short)0x00008000;

  (*(void(*)())0x06036E90)(0x25F00FFE,1,puVar5);

  *(int *)puVar3 = 2;

  do {

  } while ((*(unsigned int *)puVar3 & 2) != 2);

  (*(void(*)())(*(int *)0x06000300))(0x40,0x06006F3C);

  (*(void(*)())(*(int *)0x06000300))(0x41,0x06007268);

  (*(void(*)())0x0603950C)(2,2,0x10,5,0x06063DA8,0);

  (*(void(*)())0x06038E54)(1);

  puVar3 = 0x25E58000;

  *(char **)0x06061294 = 0x25E58000;

  *(char **)0x060612AC = puVar3;

  (*(void(*)())0x06037618)(&local_7c);

  local_7c = 1;

  uStack_7b = 0;

  uStack_7a = 1;

  uStack_79 = 0;

  uStack_77 = 0;

  uStack_76 = 0;

  uStack_74 = 1;

  uStack_70 = *(int *)0x060612AC;

  iStack_6c = *(int *)0x060612AC + (int)PTR_DAT_06004bc0;

  uStack_68 = *(int *)0x060612AC;

  iStack_64 = (int)PTR_DAT_06004bc0 + *(int *)0x060612AC;

  (*(void(*)())puVar2)(4,&local_7c);

  *(short *)0x060A3DB8 = (short)0x0000C024;

  (*(void(*)())0x0603850C)(4);

  (*(void(*)())0x06038794)(0x00010000);

  (*(void(*)())0x06038520)();

  puVar3 = 0x25E5C000;

  *(char **)0x06061298 = 0x25E5C000;

  *(char **)0x060612B0 = puVar3;

  (*(void(*)())0x06037618)(&local_7c);

  local_7c = 1;

  uStack_7b = 0;

  uStack_7a = 1;

  uStack_79 = 0;

  uStack_77 = 0;

  uStack_76 = 0;

  uStack_74 = 1;

  uStack_70 = *(int *)0x060612B0;

  iStack_6c = *(int *)0x060612B0;

  uStack_68 = *(int *)0x060612B0;

  iStack_64 = *(int *)0x060612B0;

  (*(void(*)())puVar2)(8,&local_7c);

  *(short *)0x060A3DBA = (short)0x0000C044;

  (*(void(*)())0x0603850C)(8);

  (*(void(*)())0x0603806C)(0x06087C84);

  (*(void(*)())0x06038520)();

  (*(void(*)())0x0603850C)(8);

  *puVar4 = 0;

  puVar4[1] = 0;

  puVar4[2] = 0;

  puVar4[3] = 1;

  puVar4[4] = 0;

  *(char **)(puVar4 + 8) = 0x25E5FE80;

  *(char **)(puVar4 + 0xc) = 0x25E5FF00;

  for (uVar6 = 0; uVar6 < (unsigned int)(int)PTR_DAT_06004ddc; uVar6 = uVar6 + 8) {

    *(int *)(puVar4 + uVar6 + (int)DAT_06004dda) = 0;

    *(int *)(puVar4 + uVar6 + 4 + (int)DAT_06004dda) = 0;

  }

  (*(void(*)())0x06038120)(0x06087C84);

  (*(void(*)())0x06038794)(0x00010000);

  (*(void(*)())0x06038520)();

  *(char **)0x0606129C = 0x060612C4;

  *(char **)0x060612B4 = 0x25E5E000;

  (*(void(*)())0x06037618)(&local_7c);

  local_7c = 1;

  uStack_7b = 0;

  uStack_7a = 1;

  uStack_79 = 0;

  uStack_77 = 0;

  uStack_76 = 0;

  uStack_74 = 1;

  uStack_70 = *(int *)0x060612B4;

  iStack_6c = *(int *)0x060612B4;

  uStack_68 = *(int *)0x060612B4;

  iStack_64 = *(int *)0x060612B4;

  (*(void(*)())puVar2)(0x10,&local_7c);

  *(short *)0x060A3DBC = (short)0x0000C000;

  puVar3 = 0x25E7E000;

  *(char **)0x060612A0 = 0x25E7E000;

  *(char **)0x060612B8 = puVar3;

  (*(void(*)())0x06037618)(&local_7c);

  local_7c = 1;

  uStack_7b = 0;

  uStack_7a = 1;

  uStack_79 = 0;

  uStack_77 = 0;

  uStack_76 = 0;

  uStack_74 = 1;

  uStack_70 = *(int *)0x060612B8;

  iStack_6c = *(int *)0x060612B8;

  uStack_68 = *(int *)0x060612B8;

  iStack_64 = *(int *)0x060612B8;

  (*(void(*)())puVar2)(0x20,&local_7c);

  *(short *)0x060A3DBE = (short)0x0000C060;

  (*(void(*)())0x060370C0)(auStack_30);

  uStack_28 = 1;

  uStack_27 = 1;

  uStack_26 = 0;

  uStack_25 = 0;

  uStack_24 = 0;

  uStack_23 = 0;

  (*(void(*)())0x060370E4)(auStack_30);

  (*(void(*)())0x06038044)(0x06059F20);

  (*(void(*)())0x060148FC)();

  (*(void(*)())0x060149E0)();

  (**(void **)puVar1)((int)DAT_06004ed0,0);

  (*(void(*)())0x06026CE0)();

  (**(void **)puVar1)(0xffffffff,(int)DAT_06004ed2);

  (*(void(*)())0x06012E62)();

  (*(void(*)())0x06003578)();

  (*(void(*)())0x06003A3C)();

  (*(void(*)())0x06004670)();

  (*(void(*)())0x0600A026)();

  *(short *)0x060A3DA8 = 0xf;

  *(short *)0x060635AC = 1;

  (**(void **)puVar1)((int)DAT_06004ed0,0);

  (*(void(*)())0x06026CE0)();

  return;

}
