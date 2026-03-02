unsigned int FUN_06032ea4()
{

  unsigned int uVar1;

  int in_r7;

  int unaff_r14;

  int in_pr;

  if ((0x0000001C & (int)*(short *)(unaff_r14 + 0x0000000E)) == 0) {

    return 0x0000001C;

  }

  (*(int(*)())0x06026DBC)();

  (*(int(*)())0x06026E2E)(*(int *)(unaff_r14 + 0x00000000),*(int *)(unaff_r14 + 0x00000004),

             *(int *)(unaff_r14 + 0x00000008),in_r7,in_pr);

  (*(int(*)())0x06026EDE)((int)*(short *)(unaff_r14 + 0x0000000C));

  uVar1 = (unsigned int)*(short *)(unaff_r14 + 0x0000000E);

  if ((0x00000004 & uVar1) != 0) {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)0x060624C8,*(int *)(0x060624C8 + 4),

               *(int *)(0x060624C8 + 8),in_r7,in_pr);

    (*(int(*)())0x06026F2A)(*(int *)(0x060624C8 + 0xc));

    (*(int(*)())0x0600A4AA)();

    (*(int(*)())0x06026DF8)();

  }

  if ((0x00000008 & uVar1) != 0) {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)(0x060624C8 + 0x10),*(int *)(0x060624C8 + 0x14),

               *(int *)(0x060624C8 + 0x18),in_r7,in_pr);

    (*(int(*)())0x06026F2A)(*(int *)(0x060624C8 + 0x1c));

    (*(int(*)())0x0600A4AA)();

    (*(int(*)())0x06026DF8)();

  }

  if ((0x00000010 & uVar1) != 0) {

    (*(int(*)())0x06026DBC)();

    (*(int(*)())0x06026E2E)(*(int *)(0x060624C8 + 0x20),*(int *)(0x060624C8 + 0x24),

               *(int *)(0x060624C8 + 0x28),in_r7,in_pr);

    (*(int(*)())0x0600A474)(0x00000000);

    (*(int(*)())0x06026DF8)();

  }

  uVar1 = (*(int(*)())0x06026DF8)();

  return uVar1;

}
