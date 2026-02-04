int FUN_06034168()
{

  int iVar1;

  int in_r7;

  int unaff_r14;

  int in_pr;

  iVar1 = (int)*(char *)(unaff_r14 + 0x00000001);

  if (iVar1 == 1) {

    (*0x06026DBC)();

    (*0x06026E2E)

              (*(int *)(unaff_r14 + 0x00000004),*(int *)(unaff_r14 + 0x00000008),

               *(int *)(unaff_r14 + 0x0000000C),in_r7,in_pr);

    (*0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000002));

    (*0x0600A5B2)((int)*(char *)(unaff_r14 + 0x00000011));

    iVar1 = (*0x06026DF8)();

  }

  else if (iVar1 == 2) {

    (*0x06026DBC)();

    (*0x06026E2E)

              (*(int *)(unaff_r14 + 0x00000004),*(int *)(unaff_r14 + 0x00000008),

               *(int *)(unaff_r14 + 0x0000000C),in_r7,in_pr);

    (*0x06026EDE)

              ((int)(short)(*(short *)(unaff_r14 + 0x00000002) + (short)0x00008000));

    (*0x0600A4CA)((int)*(char *)(unaff_r14 + 0x00000011));

    iVar1 = (*0x06026DF8)();

  }

  else if (iVar1 == 3) {

    (*0x06026DBC)();

    (*0x06026E2E)

              (*(int *)(unaff_r14 + 0x00000014),*(int *)(unaff_r14 + 0x00000018),

               *(int *)(unaff_r14 + 0x0000001C),in_r7,in_pr);

    (*0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000002));

    (*0x0600A4CA)((int)*(char *)(unaff_r14 + 0x00000011));

    iVar1 = (*0x06026DF8)();

  }

  else if (iVar1 == 4) {

    (*0x06026DBC)();

    (*0x06026E2E)

              (*(int *)(unaff_r14 + 0x00000004),*(int *)(unaff_r14 + 0x00000008),

               *(int *)(unaff_r14 + 0x0000000C),in_r7,in_pr);

    (*0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000002));

    (*0x0600A5B2)((int)*(char *)(unaff_r14 + 0x00000011));

    (*0x06026DF8)();

    iVar1 = 0x000004EC;

    if (0x000004EC <= *(int *)0x06083250) {

      (*0x06026DBC)();

      (*0x06026E2E)

                (*(int *)(unaff_r14 + 0x00000004) - (int)0x00280000,

                 *(int *)(unaff_r14 + 0x00000008),

                 *(int *)(unaff_r14 + 0x0000000C) - (int)0x003E0000,in_r7,in_pr);

      (*0x06026EDE)((int)*(short *)(unaff_r14 + 0x00000002));

      (*0x0600A5B2)((int)*(char *)(unaff_r14 + 0x00000011));

      (*0x06026DF8)();

      iVar1 = 0x00000627;

      if (0x00000627 <= *(int *)0x06083250) {

        (*0x06026DBC)();

        (*0x06026E2E)

                  (*(int *)(unaff_r14 + 0x00000004) - (int)0x00190000,

                   *(int *)(unaff_r14 + 0x00000008),

                   *(int *)(unaff_r14 + 0x0000000C) - (int)0x001C0000,in_r7,in_pr);

        (*0x06026EDE)(*(short *)(unaff_r14 + 0x00000002) + 0x00000002);

        (*0x0600A5B2)((int)*(char *)(unaff_r14 + 0x00000011));

        iVar1 = (*0x06026DF8)();

      }

    }

  }

  return iVar1;

}
