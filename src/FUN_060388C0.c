extern int DAT_06038932;

extern int DAT_060389f2;

extern int PTR_DAT_06038934;

extern int PTR_DAT_06038934;

extern int FUN_06038a48();

void FUN_060388c0()
{

  char *puVar1;

  puVar1 = 0x060A4C40;

  if ((*(short *)0x060A4C40 != 0) && (*(int *)0x060A4C44 != 0)) {

    FUN_06038a48(*(int *)0x060A4C44,0x060A3F68,*(int *)0x060A4C38 << 1);

    *(short *)puVar1 = 0;

  }

  if ((*(short *)(puVar1 + 2) != 0) && (*(int *)0x060A4C48 != 0)) {

    FUN_06038a48(*(int *)0x060A4C48,0x060A45D0,*(int *)0x060A4C3C << 1);

    *(short *)(puVar1 + 2) = 0;

  }

  if (*(int *)0x060635B2 == 1) {

    FUN_06038a48(*(int *)0x060A4C5C,0x060A3E68,0x80);

  }

  else if (*(int *)0x060635B2 == 2) {

    FUN_06038a48(*(int *)0x060A4C5C,0x060A3E68,0x100);

  }

  puVar1 = 0x060A3D84;

  FUN_06038a48(*(int *)0x060A3D84,0x060A3D88,0x28);

  FUN_06038a48(*(int *)puVar1 + 0x28,0x060A3DB0,0x48);

  FUN_06038a48(*(int *)puVar1 + 0x70,0x060A3DF8,0x40);

  FUN_06038a48(*(int *)puVar1 + (int)0x00B000C0,0x060A3E38,0x10);

  FUN_06038a48(*(int *)puVar1 + 0xc0,0x060A3E48,0x20);

  return;

}
