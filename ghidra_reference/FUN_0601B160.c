extern int DAT_0601b246;

extern int DAT_0601b248;

extern int DAT_0601b24a;

extern int DAT_0601b24c;

extern int DAT_0601b24e;

extern int DAT_0601b250;

extern int DAT_0601b252;

extern int DAT_0601b254;

extern int DAT_0601b256;

extern int DAT_0601b258;

extern int DAT_0601b25a;

extern int DAT_0601b25c;

extern int DAT_0601b25e;

extern int DAT_0601b260;

extern int DAT_0601b262;

extern int DAT_0601b38a;

extern int DAT_0601b38c;

extern int DAT_0601b38e;

extern int DAT_0601b390;

extern int DAT_0601b392;

extern int PTR_DAT_0601b264;

extern int PTR_DAT_0601b264;

extern int PTR_DAT_0601b394;

extern int PTR_DAT_0601b394;

void FUN_0601b160()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  *(int *)0x0606A4F4 = 0;

  *(int *)0x0606A4EC = (int)DAT_0601b246;

  (*(int(*)())0x06039250)(0x06063F5C);

  (*(int(*)())0x060393FC)(0,0,0,(int)DAT_0601b24a,(int)DAT_0601b248);

  *(int *)0x0605A008 = 0;

  **(short **)0x06063F5C = (short)0x00008000;

  (*(int(*)())0x06012E00)();

  puVar1 = 0x002A0000;

  (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)0x06063F5C,0x002A0000,

             0x640);

  puVar2 = 0x06007658;

  iVar8 = 0x101;

  iVar10 = 0xb40;

  iVar4 = 0x4b46;

  (*(int(*)())0x06007658)(iVar8,iVar10,0x78);

  iVar9 = (int)DAT_0601b254;

  iVar5 = (int)DAT_0601b256;

  (*(int(*)())puVar2)(iVar9,iVar10,0x7c);

  iVar7 = 0x103;

  iVar6 = (int)DAT_0601b25a;

  (*(int(*)())puVar2)(iVar7,iVar10,0x80);

  puVar3 = 0x06007540;

  (*(int(*)())0x06007540)((int)DAT_0601b260,iVar8,(int)DAT_0601b25e);

  (*(int(*)())puVar3)(DAT_0601b262 + 0x7d,iVar9);

  (*(int(*)())puVar3)(PTR_DAT_0601b264 + 0x7a,iVar7);

  (*(int(*)())puVar2)(iVar8,iVar10,0x78,puVar1 + iVar4);

  (*(int(*)())puVar2)(iVar9,iVar10,0x7c,puVar1 + iVar5);

  (*(int(*)())puVar2)(iVar7,iVar10,0x80,puVar1 + iVar6);

  (*(int(*)())puVar3)((int)DAT_0601b260,iVar8,(int)DAT_0601b25e);

  (*(int(*)())puVar3)(DAT_0601b262 + 0x7d,iVar9);

  (*(int(*)())puVar3)(DAT_0601b38a + 0x7a,iVar7);

  (*(int(*)())puVar2)(iVar8,iVar10,0x78,puVar1 + iVar4);

  (*(int(*)())puVar2)(iVar9,iVar10,0x7c,puVar1 + iVar5);

  (*(int(*)())puVar2)(iVar7,iVar10,(int)DAT_0601b38c,puVar1 + iVar6);

  (*(int(*)())puVar3)((int)DAT_0601b390,iVar8,(int)DAT_0601b38e);

  (*(int(*)())puVar3)(DAT_0601b392 + 0x7d,iVar9);

  (*(int(*)())puVar3)(DAT_0601b38a + 0x7a,iVar7);

  *(short *)0x0605AAA0 = 0;

  puVar2 = 0x06026CE0;

  puVar1 = 0x0605B6D8;

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x80000000;

  (*(int(*)())puVar2)();

  (*(int(*)())0x06026CE0)();

  (*(int(*)())0x0602766C)(0x25F00540,0x0604842C,0x40);

  (*(int(*)())0x0602766C)(0x25F001A0,0x060487EC,0x20);

  (*(int(*)())0x0600511E)(0x25E6F9C4,0x00017700,0,9);

  puVar2 = 0x06094FA8;

  (*(int(*)())0x06028654)(0x25E75DDC);

  (*(int(*)())0x06028400)(4,puVar2,0,0x0000B000);

  (*(int(*)())0x06014884)(0x10,0,0);

  (*(int(*)())0x06014884)(0x20,0,0);

  puVar2 = 0x06038BD4;

  (*(int(*)())0x06038BD4)((int)PTR_DAT_0601b394,7);

  (*(int(*)())puVar2)(4,0);

  (*(int(*)())puVar2)(8,1);

  (*(int(*)())puVar2)(0x10,6);

  (*(int(*)())puVar2)(0x20,5);

  (*(int(*)())puVar2)(1,0);

  (*(int(*)())0x0602853E)(0xc);

  (*(int(*)())0x06028560)();

  *(unsigned int *)puVar1 = *(unsigned int *)puVar1 | 0x40000000;

  *(int *)0x0608600D = 0;

  *(int *)0x0608600C = 0;

  *(int *)0x0608600E = 0;

  (*(int(*)())0x06018DDC)(4,4,0xf);

  return;

}
