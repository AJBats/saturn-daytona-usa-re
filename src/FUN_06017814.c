extern int DAT_060178aa;

extern int DAT_060178ac;

extern int DAT_060179b6;

extern int DAT_06017bd4;

extern int DAT_06017bd6;

extern int DAT_06017bd8;

extern int PTR_DAT_060179b8;

extern int PTR_DAT_060179b8;

extern void FUN_06017bf4();
extern void FUN_06017c78();
extern void FUN_06017c9c();

void FUN_06017814()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  int in_r7;

  char *puVar8;

  char *puVar9;

  puVar7 = 0x0605BE20;

  puVar6 = 0x0605BE22;

  puVar5 = 0x0605BE26;

  puVar4 = 0x0605BE1A;

  puVar3 = 0x0605BE24;

  puVar2 = 0x0605BE18;

  (*0x06026DBC)();

  *(int *)0x06085FAC = *(int *)0x06085FAC - (int)DAT_060178aa;

  (*0x06026E2E)

            (*(int *)0x06048128,*(int *)0x0604812C,

             -*(int *)0x06048130);

  (*0x06026EDE)(*(int *)0x06085FAC);

  puVar8 = 0x00200000;

  (*0x06031D8C)(0x00200000 + (int)0x00037D88,8);

  (*0x06031A28)

            (puVar8 + (int)0x00037DE8,(int)*(short *)0x06089E98,6,in_r7,

             puVar8 + (int)0x00037DE8);

  (*0x06026DF8)();

  (*0x06026DBC)();

  if (*(short *)puVar2 == 10) {

    *(short *)puVar2 = 0;

    *(int *)0x06085FBC = *(int *)0x06085FBC - (int)DAT_060178ac;

  }

  else {

    *(int *)0x06085FBC = *(int *)0x06085FBC + (int)DAT_060179b6;

  }

  (*0x06026E2E)

            (*(int *)0x06048134,*(int *)0x06048138,

             -*(int *)0x0604813C);

  (*0x06026F2A)(*(int *)0x06085FBC);

  puVar9 = 0x00200000;

  (*0x06031D8C)(0x00200000 + (int)0x00037E78,4);

  (*0x06031A28)(puVar9 + (int)0x00037EA8,(int)*(short *)0x06089E98,1);

  (*0x06026DF8)();

  puVar8 = 0x06026DBC;

  *(short *)puVar2 = *(short *)puVar2 + 1;

  (*puVar8)();

  (*0x06031D8C)(puVar9 + (int)0x00037EC0,4);

  (*0x06031A28)

            (puVar9 + (int)0x00037EF0,

             (int)*(short *)(0x06089E44 + (((int)(*(unsigned short *)puVar2 & 4) >> 2) + 0x2a) * 2),1)

  ;

  (*0x06026DF8)();

  if (*(unsigned int *)(*(int *)0x0607E940 + (int)PTR_DAT_060179b8) <

      *(int *)0x06063F28 - 1U) {

    if (*0x06078636 == '\0') {

      *(short *)puVar4 = 1;

    }

    else {

      *(short *)puVar4 = 0;

    }

  }

  else {

    *(short *)puVar4 = 2;

  }

  (*0x06026DBC)();

  (*0x06031D8C)

            (*(int *)(0x06062290 + (unsigned int)*(unsigned short *)puVar4 * 4),

             *(int *)(0x060622B4 + (unsigned int)*(unsigned short *)puVar4 * 4));

  (*0x06031A28)

            (*(int *)(0x0606229C + (unsigned int)*(unsigned short *)puVar4 * 4),

             (int)*(short *)0x06089E98,

             *(int *)(0x060622A8 + (unsigned int)*(unsigned short *)puVar4 * 4));

  (*0x06026DF8)();

  puVar2 = 0x0605BE2A;

  if ((*(int *)0x0607EAD0 == 0) && ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x000A0000) != 0)

     ) {

    if ((*(unsigned short *)0x06063D98 & 0x40) == 0) {

      *(short *)0x0605BE2A = 0;

    }

    else if (*(short *)0x0605BE2A == 0) {

      *(short *)0x0605BE2A = 1;

      *(short *)puVar5 = *(short *)puVar5 + 1;

      *(unsigned short *)puVar5 = *(unsigned short *)puVar5 & 3;

    }

  }

  else {

    *(short *)0x0605BE28 = 0;

    *(short *)puVar5 = 0;

    *(short *)puVar2 = 0;

  }

  sVar1 = *(short *)puVar5;

  if (sVar1 == 0) {

    *(short *)puVar3 = *(short *)puVar3 + -1;

    *(short *)puVar6 = *(short *)puVar6 + -2;

  }

  else {

    if (sVar1 == 1) {

      FUN_06017c9c(0x0605BE24);

      *(short *)puVar6 = *(short *)puVar6 + -2;

      *(short *)puVar7 = *(short *)puVar7 + -3;

      goto LAB_06017b4e;

    }

    if (sVar1 != 2) {

      if ((sVar1 == 3) && (FUN_06017c9c(0x0605BE20), *(short *)0x0605BE28 == 0)) {

        FUN_06017bf4();

      }

      goto LAB_06017b4e;

    }

    FUN_06017c9c(0x0605BE22);

    if (*0x06085FCC == '\0') {

      FUN_06017c78();

    }

  }

  *(short *)puVar7 = *(short *)puVar7 + -3;

LAB_06017b4e:

  if (*(short *)puVar3 < 1) {

    *(short *)puVar3 = 0x30;

  }

  if (*(short *)puVar7 < 1) {

    *(short *)puVar7 = 0x30;

  }

  if (*(short *)puVar6 < 1) {

    *(short *)puVar6 = 0x30;

  }

  puVar5 = 0x06063F64;

  puVar4 = 0x060684EC;

  puVar2 = 0x0606A4F0;

  *(int *)(0x06063F64 + (unsigned int)*(unsigned short *)(0x060684EC + DAT_06017bd4) * 8) =

       *(short *)puVar3 * 3 + *(int *)0x0606A4F0;

  *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + DAT_06017bd6) * 8) =

       *(short *)puVar6 * 3 + *(int *)puVar2;

  *(int *)(puVar5 + (unsigned int)*(unsigned short *)(puVar4 + DAT_06017bd8) * 8) =

       *(short *)puVar7 * 3 + *(int *)puVar2;

  return;

}
