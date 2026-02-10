#include "game.h"

extern int DAT_0604009e;
extern int DAT_060400a0;
extern int DAT_060400a2;
extern int DAT_060401e8;
extern int DAT_0604089c;
extern int DAT_06040d2c;
extern int DAT_06040dc0;
extern int DAT_06040dc2;
extern int DAT_06040e72;
extern int DAT_06041174;
extern int DAT_060411f6;
extern int DAT_0604128e;
extern int DAT_0604155c;
extern int DAT_0604155e;
extern int DAT_060415ec;
extern int DAT_060415ee;
extern int DAT_060417d8;
extern int DAT_060417da;
extern int DAT_060417dc;
extern int DAT_060417de;
extern int DAT_060417e0;
extern int DAT_060417e2;
extern int DAT_0604185e;
extern int DAT_06041b0a;
extern int DAT_06041bc6;
extern int DAT_06041bc8;
extern int DAT_06041bca;
extern int DAT_06041bcc;
extern int DAT_06041bce;
extern int DAT_06041bd0;
extern int DAT_06041bd2;
extern int DAT_06041ca8;
extern int DAT_06041caa;
extern int DAT_06041d58;
extern int DAT_06041d5a;
extern int DAT_06041dec;
extern int DAT_06041dee;
extern int DAT_06041df0;
extern int DAT_06041df2;
extern int DAT_06041eb4;
extern int DAT_06041eb6;
extern int DAT_06041f90;
extern int DAT_06041f92;
extern int DAT_06041f94;
extern int DAT_06041f96;
extern int DAT_0604207a;
extern int DAT_0604207c;
extern int DAT_0604207e;
extern int FUN_06034984();
extern int cd_register_double_read();
extern int FUN_06035C4E();
extern int FUN_060400b4();
extern int FUN_060405b8();
extern int FUN_060412b2();
extern int FUN_06041310();
extern int FUN_06041698();
extern int FUN_060417a8();
extern int FUN_06041826();
extern int FUN_060418be();
extern int FUN_06041aa0();
extern int FUN_06041b3c();
extern int FUN_06041cc8();
extern int FUN_06041d6c();
extern int FUN_06041ee8();
extern int FUN_06042088();
extern int FUN_06042134();
extern int FUN_0604231e();
extern int PTR_DAT_06040dc4;
extern int PTR_DAT_06041176;
extern int PTR_DAT_060411f8;
extern int PTR_DAT_06041306;
extern int PTR_DAT_060414c4;
extern int PTR_DAT_060415f0;
extern int PTR_DAT_0604172a;
extern int PTR_DAT_06041b0c;
extern int PTR_DAT_06041cac;
extern int PTR_DAT_06041eb8;

int FUN_0604000c(param_1)
    int param_1;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  puVar1 = (char *)0x060A4D14;

  *(unsigned int *)(CD_STATE_A + (int)DAT_0604009e) =

       *(unsigned int *)(CD_STATE_A + (int)DAT_0604009e) & 0xfffffffe;

  iVar2 = (*(int(*)())0x06040C98)(*(int *)puVar1 + 0xd0,param_1);

  if (iVar2 == 0) {

    *(unsigned int *)((int)DAT_0604009e + *(int *)puVar1) =

         *(unsigned int *)(*(int *)puVar1 + (int)DAT_0604009e) | 1;

  }

  if (param_1 == 0) {

    uVar3 = 0xffffffff;

  }

  else {

    uVar3 = 0x17;

  }

  *(int *)(*(int *)puVar1 + 0xc8) = uVar3;

  if (iVar2 == -0xf) {

    return 0xfffffffd;

  }

  if (iVar2 == -0xe) {

    return 0xfffffffe;

  }

  if (iVar2 != -0xd) {

    if (iVar2 != 0) {

      return 0xffffffff;

    }

    return 0;

  }

  return 0xffffffe9;

}

int FUN_060400b4(param_1)
    unsigned int param_1;
{

  short sVar1;

  sVar1 = 0x0800;

  if ((param_1 & 4) != 0) {

    sVar1 = 0x0914;

  }

  return (int)sVar1;

}

unsigned int * FUN_060400d6(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int param_3;
{

  int iVar1;

  unsigned int uVar2;

  unsigned int local_20;

  int uStack_1c;

  char uStack_18;

  char uStack_17;

  char uStack_16;

  char uStack_15;

  if (param_2 == (unsigned int *)0x0) {

    *param_1 = 0x40000000 | param_3;

    iVar1 = (*(int(*)())0x060415C8)(param_3,&local_20);

    if (iVar1 != 0) {

      return (unsigned int *)0x0;

    }

    param_1[1] = local_20;

    uVar2 = FUN_060400b4(uStack_15);

    param_1[3] = uVar2;

    uVar2 = (*(int(*)())0x06035F44)();

    param_1[4] = uVar2;

    (*(int(*)())0x06036BE4)(uStack_1c);

    uVar2 = (*(int(*)())0x06036BE4)();

    param_1[5] = uVar2;

    *(char *)(param_1 + 7) = uStack_16;

    *(char *)((int)param_1 + 0x1d) = uStack_15;

    *(char *)((int)param_1 + 0x1e) = uStack_18;

    *(char *)((int)param_1 + 0x1f) = uStack_17;

  }

  else {

    *param_1 = param_3;

    param_1[1] = *param_2;

    uVar2 = FUN_060400b4(*(char *)((int)param_2 + 0xb));

    param_1[3] = uVar2;

    param_1[4] = (int)DAT_060401e8 + param_2[1] >> 0xb;

    (*(int(*)())0x06036BE4)();

    uVar2 = (*(int(*)())0x06036BE4)();

    param_1[5] = uVar2;

    *(char *)(param_1 + 7) = *(char *)((int)param_2 + 10);

    *(char *)((int)param_1 + 0x1d) = *(char *)((int)param_2 + 0xb);

    *(char *)((int)param_1 + 0x1e) = *(char *)(param_2 + 2);

    *(char *)((int)param_1 + 0x1f) = *(char *)((int)param_2 + 9);

  }

  param_1[6] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[10] = 0x7FFFFFFF;

  return param_1;

}

void FUN_060401f8(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  *(int *)(param_1 + 0x20) = param_2;

  iVar1 = (*(int(*)())0x060408B0)(*(int *)(param_1 + 0x18),0x7FFFFFFF,0);

  if (iVar1 < 0) {

    iVar1 = 0;

  }

  *(int *)(param_1 + 0x24) = iVar1 - *(int *)(*(int *)(param_1 + 0x18) + 0x10);

  return;

}

int FUN_06040220(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int *param_3;
    unsigned int *param_4;
    unsigned int *param_5;
    int *param_6;
    unsigned int *param_7;
    unsigned int *param_8;
{

  int uVar1;

  if (param_2 != (unsigned int *)0x0) {

    if ((*param_1 & 0x40000000) == 0) {

      *param_2 = *param_1;

    }

    else {

      *param_2 = *param_1 & 0x3FFFFFFF;

    }

  }

  if (param_3 != (unsigned int *)0x0) {

    *param_3 = param_1[1];

  }

  if (param_7 != (unsigned int *)0x0) {

    *param_7 = (unsigned int)*(unsigned char *)(param_1 + 7);

  }

  if (param_4 != (unsigned int *)0x0) {

    *param_4 = param_1[3];

  }

  if (param_5 != (unsigned int *)0x0) {

    *param_5 = param_1[4];

  }

  uVar1 = 0;

  if (param_8 != (unsigned int *)0x0) {

    uVar1 = 0x1d;

    *param_8 = (unsigned int)*(unsigned char *)((int)param_1 + 0x1d);

  }

  if (param_6 != (int *)0x0) {

    if (((*(unsigned char *)((int)param_1 + 0x1d) & 8) == 0) ||

       (uVar1 = 0x1d, (*(unsigned char *)((int)param_1 + 0x1d) & 4) == 0)) {

      uVar1 = 0x1d;

      *param_6 = param_1[3] - param_1[5];

    }

    else {

      *param_6 = 0;

    }

  }

  return uVar1;

}

int FUN_060405b8(param_1, param_2)
    int *param_1;
    short *param_2;
{

  short uVar1;

  unsigned char local_10 [8];

  int uStack_8;

  uVar1 = (*(int(*)())0x06041330)(local_10);

  if (param_2 != (short *)0x0) {

    *param_2 = uVar1;

  }

  if (param_1 != (int *)0x0) {

    *param_1 = uStack_8;

  }

  switch(local_10[0] & 0xf) {

  case 0:

    return 2;

  case 1:

  case 2:

    return 0;

  case 3:

  case 8:

    return 1;

  case 4:

    return 2;

  case 5:

    return 1;

  case 6:

    return 3;

  case 7:

    return 4;

  default:

    return 5;

  }

}

int FUN_06040680()
{

  int iVar1;

  

  iVar1 = FUN_060405b8(0);

  if (iVar1 == 4) {

    return 0;

  }

  return 1;

}

int FUN_06040722(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  int extraout_r3 = 0;

  if (*(char *)(param_1 + 0x1e) == '\0') {

    return param_2;

  }

  (*(int(*)())0x06034FFC)(param_1,param_2,*(char *)(param_1 + 0x1e));

  iVar1 = (*(int(*)())0x06036BE4)();

  return iVar1 + extraout_r3;

}

int * FUN_0604077c(param_1, param_2, param_3, param_4, param_5)
    int *param_1;
    int param_2;
    int param_3;
    char param_4;
    int param_5;
{

  int iVar1;

  int local_1c;

  int uStack_18;

  char local_14;

  char uStack_13;

  char uStack_12;

  char uStack_11;

  char uStack_10;

  char uStack_f;

  *param_1 = param_2;

  param_1[2] = 0;

  *(char *)(param_1 + 6) = param_4;

  param_1[3] = param_3;

  param_1[4] = 0;

  param_1[8] = 1;

  *(char *)((int)param_1 + 0x19) = 0;

  *(char *)((int)param_1 + 0x1a) = 0;

  *(char *)((int)param_1 + 0x1b) = 0;

  param_1[9] = (unsigned int)param_5;

  local_14 = *(char *)(param_1 + 6);

  uStack_13 = *(char *)((int)param_1 + 0x19);

  uStack_12 = 0;

  uStack_11 = 0;

  uStack_10 = 0;

  uStack_f = 0;

  (*(int(*)())0x06035228)();

  param_1[10] = 0xffffffff;

  iVar1 = (*(int(*)())0x06040EEC)(&uStack_18);

  if (iVar1 == 0) {

    param_1[1] = uStack_18;

    iVar1 = (*(int(*)())0x06040E88)(&local_1c);

    if (iVar1 == 0) {

      param_1[5] = local_1c;

      iVar1 = (*(int(*)())0x06041034)(local_1c,param_1[8],&local_14,0,0);

      if (iVar1 == 0) {

        iVar1 = (*(int(*)())0x060414D0)(local_1c,uStack_18,(int)DAT_0604089c);

        if (iVar1 == 0) {

          iVar1 = (*(int(*)())0x0604188C)();

          if (iVar1 != 0) {

            param_1 = (int *)0x0;

          }

        }

        else {

          param_1 = (int *)0x0;

        }

      }

      else {

        param_1 = (int *)0x0;

      }

    }

    else {

      (*(int(*)())0x06040F16)(uStack_18);

      param_1 = (int *)0x0;

    }

  }

  else {

    param_1 = (int *)0x0;

  }

  return param_1;

}

int FUN_060408b0(param_1, param_2, param_3)
    int *param_1;
    int param_2;
    int *param_3;
{

  int iVar1;

  int local_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  int uStack_14;

  uStack_14 = param_2;

  iVar1 = (*(int(*)())0x060411A0)(param_1[1],param_1[4],param_2,&local_24,param_3);

  if (iVar1 == 0) {

    iVar1 = (*(int(*)())0x0604188C)();

    if (iVar1 == 0) {

      if ((((param_3 != (int *)0x0) &&

           ((*(int(*)())0x06040220)(*param_1,0,0,&iStack_1c,&iStack_18,&iStack_20,0,0),

           iStack_18 <= param_1[2] + param_1[4] + local_24)) && (iStack_20 != 0)) && (0 < local_24))

      {

        *param_3 = *param_3 - (iStack_1c - iStack_20);

      }

    }

    else {

      local_24 = 0;

    }

  }

  else {

    local_24 = 0;

  }

  return local_24;

}

int FUN_060409e6(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  int local_1c;

  int iStack_18;

  puVar1 = (char *)0x0604188C;

  if (param_2 < 0) {

    param_2 = 0;

  }

  if (param_3 == 1) {

    iVar2 = *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) + param_2;

    local_1c = param_2;

  }

  else {

    if (*(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) == param_2) {

      return param_2;

    }

    iVar2 = (*(int(*)())0x060411A0)(*(int *)(param_1 + 4),0,0x0000FFFF,&local_1c,0)

    ;

    if (iVar2 != 0) {

      return -1;

    }

    iVar2 = (*(int(*)())puVar1)();

    if (iVar2 != 0) {

      return -1;

    }

    iVar2 = param_2;

    if (local_1c < 0) {

      local_1c = 0;

    }

  }

  if (*(int *)(param_1 + 0x24) == 0) {

    if ((*(int *)(param_1 + 8) <= iVar2) &&

       (iVar2 < *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8))) {

      local_1c = iVar2 - *(int *)(param_1 + 8);

    }

    if (0 < local_1c) {

      (*(int(*)())0x060412B2)(*(int *)(param_1 + 4),0,local_1c);

      iVar3 = (*(int(*)())puVar1)();

      if (iVar3 != 0) {

        return -1;

      }

    }

    *(int *)(param_1 + 8) = iVar2;

    *(int *)(param_1 + 0x10) = 0;

  }

  else if (*(int *)(param_1 + 0x24) == 1) {

    if ((iVar2 < *(int *)(param_1 + 8)) ||

       (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 8) + 1 < iVar2)) {

      iStack_18 = param_1;

      (*(int(*)())0x060412B2)(*(int *)(param_1 + 4),0,0x0000FFFF);

      iVar3 = (*(int(*)())puVar1)();

      if (iVar3 == 0) {

        return -1;

      }

      *(int *)(param_1 + 8) = iVar2;

    }

    *(int *)(param_1 + 0x10) = iVar2 - *(int *)(param_1 + 8);

  }

  return *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10);

}

char * FUN_06040b32(param_1, param_2)
    int *param_1;
    int param_2;
{

  char *puVar1;

  int iVar2;

  int uVar3;

  int local_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  int iStack_14;

  int uStack_10;

  if (((int *)0x0606367C)[0x10] == '\0') {

    uStack_10 = param_2;

    iVar2 = (*(int(*)())0x060411A0)(param_1[1],param_1[4],param_2,&local_24,&iStack_20);

    if (iVar2 == 0) {

      iVar2 = (*(int(*)())0x0604188C)();

      if (iVar2 == 0) {

        if (iStack_20 < 1) {

          puVar1 = (char *)0x0;

        }

        else {

          (*(int(*)())0x06040220)(*param_1,0,0,&iStack_18,&iStack_14,&iStack_1c,0,0);

          puVar1 = (char *)0x0606367C;

          if (((iStack_14 <= param_1[2] + param_1[4] + local_24) && (iStack_1c != 0)) &&

             (0 < local_24)) {

            iStack_20 = iStack_20 - (iStack_18 - iStack_1c);

          }

          uVar3 = (*(int(*)())0x06035C48)();

          *(int *)puVar1 = uVar3;

          *(int *)(puVar1 + 4) = 0;

          *(int *)(puVar1 + 8) = iStack_20;

          *(int *)(puVar1 + 0xc) = local_24;

          puVar1[0x10] = 1;

        }

      }

      else {

        puVar1 = (char *)0x0;

      }

    }

    else {

      puVar1 = (char *)0x0;

    }

  }

  else {

    puVar1 = (char *)0x0;

  }

  return puVar1;

}

int FUN_06040c10(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  iVar1 = (*(int(*)())0x06041204)(*(int *)(param_2 + 4),*(int *)(param_2 + 0x10),

                     *(int *)(param_1 + 0xc));

  if (iVar1 != 0) {

    return 0;

  }

  iVar1 = (*(int(*)())0x0604188C)();

  if (iVar1 != 0) {

    return 0;

  }

  return 1;

}

int FUN_06040c98(param_1, param_2)
    int param_1;
    int param_2;
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned char bVar8;

  int iVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  int iVar9;

  int iVar10;

  int iVar11;

  unsigned char local_30 [4];

  unsigned char local_2c [16];

  puVar4 = (char *)0x0604231E;

  puVar3 = (char *)0x060A5400;

  puVar2 = (char *)0x06034984;

  iVar11 = (int)DAT_06040d2c;

  CD_SESSION_BASE = param_1;

  (*(int(*)())puVar4)();

  if (param_2 == 0) {

    *(char *)(*(int *)puVar3 + 0x17) = 0;

    *(char *)(*(int *)puVar3 + 0x2f) = 0;

  }

  else {

    *(char *)(*(int *)puVar3 + 0x17) = 1;

    *(char *)(*(int *)puVar3 + 0x2f) = 1;

  }

  (*(int(*)())puVar2)(local_2c);

  bVar8 = local_2c[0] & 0xf;

  if (bVar8 == 6) {

    return 0xfffffff3;

  }

  if (bVar8 == 7) {

    return 0xfffffff2;

  }

  if ((bVar8 != 9) && (bVar8 != 10)) {

    iVar5 = (*(int(*)())0x06034B9A)(iVar11,0x0000FFFF,iVar11,iVar11);

    if (iVar5 != 0) {

      return 0xfffffffe;

    }

    iVar5 = 0;

    bVar1 = 0;

    while (uVar7 = DAT_06040dc0, !bVar1) {

      uVar6 = (*(int(*)())0x06035C4E)();

      if ((uVar6 & uVar7) != 0) {

        (*(int(*)())0x06035C54)(0x0000FBFF);

        iVar5 = iVar5 + 1;

        if (DAT_06040dc2 < iVar5) {

          return 0xfffffffe;

        }

        (*(int(*)())puVar2)(local_2c);

        bVar8 = local_2c[0] & 0xf;

        if ((bVar8 == 1) || (bVar8 == 2)) {

          bVar1 = 1;

        }

        else if ((bVar8 == 9) || (bVar8 == 10)) {

          return 0xfffffff6;

        }

      }

    }

    iVar9 = (int)PTR_DAT_06040dc4;

    iVar10 = CD_STATE_A;

    iVar5 = (*(int(*)())0x06034AEE)(iVar10 + iVar9);

    if (iVar5 != 0) {

      return 0xfffffffe;

    }

    (*(int(*)())0x06034B54)(0,local_30);

    (*(int(*)())0x06034B54)(local_30[0],local_30);

    if ((*(unsigned int *)(iVar10 + iVar9 + (local_30[0] - 1) << 2) & 0x40000000) == 0) {

      return 0xfffffff1;

    }

    (*(int(*)())0x060364D4)((int)DAT_06040e72,iVar11);

    *(char **)(*(int *)puVar3 + 0x3c) = 0x00008000;

    do {

      uVar7 = (*(int(*)())0x06035C4E)();

      if ((uVar7 & 0x40) != 0) {

        *(int *)(*(int *)puVar3 + 0x3c) = 0;

        (*(int(*)())puVar2)(*(int *)puVar3 + 0x40);

        return 0;

      }

      iVar11 = *(int *)(*(int *)puVar3 + 0x3c) + -1;

      *(int *)(*(int *)puVar3 + 0x3c) = iVar11;

    } while (iVar11 != 0);

    return 0xfffffffe;

  }

  return 0xfffffff6;

}

int FUN_06040f16(param_1)
    int param_1;
{

  char *puVar1;

  int uVar2;

  int iVar3;

  puVar1 = (char *)0x060A5400;

  if ((param_1 < 0) || (0x17 < param_1)) {

    uVar2 = 0xfffffffa;

  }

  else if (*(char *)(param_1 + CD_SESSION_BASE) == '\x01') {

    FUN_060412b2(param_1,0,0x0000FFFF);

    *(char **)(*(int *)puVar1 + 0x3c) = 0x00008000;

    do {

      iVar3 = FUN_06041698();

      if (iVar3 == 3) {

        return 0xfffffff4;

      }

      iVar3 = FUN_06041310(param_1);

    } while (iVar3 != 1);

    *(int *)(*(int *)puVar1 + 0x3c) = 0;

    *(char *)(param_1 + *(int *)puVar1) = 0;

    uVar2 = 0;

  }

  else {

    uVar2 = 0xfffffff9;

  }

  return uVar2;

}

int FUN_06040fb8()
{

  int *piVar1;

  piVar1 = (int *)0x060A5400;

  if (*(int *)(CD_SESSION_BASE + 0x30) == 1) {

    return 0xfffffffb;

  }

  *(int *)(CD_SESSION_BASE + 0x30) = 1;

  *(int *)(*piVar1 + 0x38) = *(int *)(*piVar1 + 0x38) + 1;

  if (*(int *)(*piVar1 + 0x38) < 0) {

    *(int *)(*piVar1 + 0x38) = 0;

  }

  return *(int *)(*piVar1 + 0x38);

}

int FUN_06040fea(param_1)
    int param_1;
{

  if (*(int *)(CD_SESSION_BASE + 0x30) == 0) {

    return 0xfffffff9;

  }

  if (*(int *)(CD_SESSION_BASE + 0x38) != param_1) {

    return 0xfffffff7;

  }

  *(int *)(CD_SESSION_BASE + 0x30) = 0;

  return 0;

}

int FUN_06041034(param_1, param_2, param_3, param_4, param_5)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
{

  char *puVar1;

  int uVar2;

  int iVar3;

  char auStack_10 [8];

  puVar1 = (char *)0x060A5400;

  iVar3 = *(int *)(CD_SESSION_BASE + 0x54);

  if (*(char *)(param_1 + CD_SESSION_BASE + 0x18) == '\x01') {

    if (iVar3 < 0x18) {

      if (*(int *)(CD_SESSION_BASE + 0x58) == 0) {

        *(int *)(CD_SESSION_BASE + 0x58) = 1;

      }

      iVar3 = (iVar3 << 4);

      *(char *)(*(int *)puVar1 + 0x5c + iVar3) = (char)param_1;

      *(char *)(*(int *)puVar1 + iVar3 + 0x5d) = param_2;

      (*(int(*)())0x06035228)();

      *(int *)(*(int *)puVar1 + iVar3 + 100) = param_4;

      *(int *)(iVar3 + *(int *)puVar1 + 0x68) = param_5;

      *(int *)(*(int *)puVar1 + 0x54) = *(int *)(*(int *)puVar1 + 0x54) + 1;

      FUN_060418be(auStack_10);

      uVar2 = 0;

    }

    else {

      uVar2 = 0xfffffff8;

    }

  }

  else {

    uVar2 = 0xfffffff9;

  }

  return uVar2;

}

int FUN_06041128(param_1, param_2)
    int param_1;
    int param_2;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = (char *)0x060A5400;

  if ((param_1 != DAT_06041174) && (*(char *)(param_1 + CD_SESSION_BASE + 0x18) != '\x01'))

  {

    return 0xfffffff9;

  }

  if (*(int *)(CD_SESSION_BASE + 0x38) != param_2) {

    return 0xfffffff7;

  }

  iVar2 = (int)PTR_DAT_06041176;

  *(int *)(CD_SESSION_BASE + iVar2) = 1;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

  FUN_06041aa0(auStack_8);

  return 0;

}

int FUN_060411a0(param_1, param_2, param_3, param_4, param_5)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = (char *)0x060A5400;

  if (*(int *)(CD_SESSION_BASE + (int)DAT_060411f6) != 0) {

    return 0xffffffff;

  }

  iVar2 = (int)DAT_060411f6;

  *(int *)(CD_SESSION_BASE + iVar2) = 1;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

  *(int *)(*(int *)puVar1 + iVar2 + 8) = param_2;

  *(int *)(*(int *)puVar1 + iVar2 + 0xc) = param_3;

  *(int *)(*(int *)puVar1 + iVar2 + 0x10) = 0;

  *(int *)(*(int *)puVar1 + iVar2 + 0x14) = param_4;

  *(int *)(*(int *)puVar1 + (int)PTR_DAT_060411f8) = param_5;

  FUN_06041b3c(auStack_8);

  return 0;

}

int FUN_06041204(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = (char *)0x060A5400;

  if (*(int *)(CD_SESSION_BASE + 0x328) != 0) {

    return 0xffffffff;

  }

  if (*(int *)(CD_SESSION_BASE + 0x34) == 1) {

    return 0xfffffffb;

  }

  *(int *)(CD_SESSION_BASE + 0x34) = 1;

  iVar2 = 0x328;

  *(int *)(*(int *)puVar1 + iVar2) = 1;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

  *(int *)(*(int *)puVar1 + iVar2 + 8) = param_2;

  *(int *)(*(int *)puVar1 + iVar2 + 0xc) = param_3;

  FUN_06041cc8(auStack_8);

  return 0;

}

int FUN_06041258()
{

  char *puVar1;

  int iVar2;

  char local_14 [16];

  puVar1 = (char *)0x060A5400;

  if (*(int *)(CD_SESSION_BASE + 0x34) == 0) {

    return 0xfffffff9;

  }

  iVar2 = (*(int(*)())0x06034CC8)();

  *(int *)(*(int *)puVar1 + 0x34) = 0;

  if (iVar2 != 0) {

    return 0xfffffff6;

  }

  (*(int(*)())*(int *)0x06041308)(local_14);

  *(char *)(*(int *)puVar1 + 0x40) = local_14[0];

  return 0;

}

int FUN_060412b2(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = (char *)0x060A5400;

  if (*(int *)(CD_SESSION_BASE + 0x338) != 0) {

    return 0xffffffff;

  }

  if (*(int *)(CD_SESSION_BASE + 0x34) == 1) {

    return 0xfffffffb;

  }

  *(int *)(CD_SESSION_BASE + 0x34) = 1;

  iVar2 = 0x338;

  *(int *)(*(int *)puVar1 + iVar2) = 1;

  *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

  *(int *)(*(int *)puVar1 + iVar2 + 8) = param_2;

  *(int *)(*(int *)puVar1 + iVar2 + 0xc) = param_3;

  FUN_06041d6c(auStack_8);

  return 0;

}

void FUN_06041330(param_1)
    int param_1;
{

  if (cd_register_double_read(param_1) != 0) {
    FUN_06034984(param_1);
  }

  FUN_06035C4E();

  return;

}

int FUN_0604134e(param_1, param_2)
    int param_1;
    int param_2;
{

  if (*(int *)(CD_SESSION_BASE + 0x38) != param_2) {

    return 0xfffffff7;

  }

  (*(int(*)())0x06034DEA)();

  return 0;

}

int FUN_06041470(param_1, param_2)
    int param_1;
    int param_2;
{

  char *puVar1;

  int iVar2;

  char auStack_8 [8];

  puVar1 = (char *)0x060A5400;

  if ((*(char *)(param_2 + CD_SESSION_BASE + 0x18) == '\x01') &&

     (*(char *)(param_2 + CD_SESSION_BASE) == '\x01')) {

    if (*(int *)(CD_SESSION_BASE + 0x360) != 0) {

      return 0xffffffff;

    }

    iVar2 = 0x360;

    *(int *)(CD_SESSION_BASE + iVar2) = 1;

    *(int *)(*(int *)puVar1 + iVar2 + 4) = param_1;

    *(int *)(*(int *)puVar1 + iVar2 + 8) = param_2;

    FUN_06042088(auStack_8);

    return 0;

  }

  return 0xfffffffb;

}

int FUN_060414d0(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char auStack_c [8];

  puVar1 = (char *)0x060A5400;

  iVar3 = (int)DAT_0604155e;

  iVar2 = *(int *)(CD_SESSION_BASE + (int)DAT_0604155c);

  if ((((param_1 != iVar3) && (param_1 != -2)) && ((param_1 < 0 || (0x17 < param_1)))) ||

     (((param_2 < 0 || (0x17 < param_2)) ||

      ((param_3 != iVar3 && ((param_3 != -2 && ((param_3 < 0 || (0x17 < param_3)))))))))) {

    return 0xfffffffa;

  }

  if (((param_1 == iVar3) ||

      ((param_1 == -2 || (*(char *)(param_1 + CD_SESSION_BASE + 0x18) == '\x01')))) &&

     (((param_3 == iVar3 ||

       ((param_3 == -2 || (*(char *)(param_3 + CD_SESSION_BASE + 0x18) == '\x01')))) &&

      (*(char *)(param_2 + CD_SESSION_BASE) == '\x01')))) {

    if (0x17 < iVar2) {

      return 0xfffffff8;

    }

    if (*(int *)(CD_SESSION_BASE + 0x1e0) == 0) {

      *(int *)(CD_SESSION_BASE + 0x1e0) = 1;

    }

    iVar3 = (int)(short)((short)iVar2 * 0xc);

    iVar2 = (int)DAT_060415ee;

    *(int *)(*(int *)puVar1 + iVar2 + iVar3) = param_1;

    *(int *)(iVar2 + *(int *)puVar1 + iVar3 + 4) = param_2;

    *(int *)(iVar3 + (int)DAT_060415ee + *(int *)puVar1 + 8) = param_3;

    *(int *)(*(int *)puVar1 + (int)PTR_DAT_060415f0) =

         *(int *)(*(int *)puVar1 + (int)PTR_DAT_060415f0) + 1;

    FUN_06042134(auStack_c);

    return 0;

  }

  return 0xfffffff9;

}

int FUN_060415c8(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  int local_24;

  int iStack_20;

  int iStack_1c;

  char auStack_18 [4];

  int uStack_14;

  char local_10 [16];

  iStack_1c = param_1;

  uStack_14 = param_2;

  iVar1 = (*(int(*)())0x06036A98)(&local_24,&iStack_20,auStack_18);

  if (iVar1 != 0) {

    return 0xfffffff5;

  }

  if ((local_24 == 2) && (iStack_1c < iStack_20 + 2)) {

    iVar1 = (*(int(*)())0x06036AF2)(iStack_1c,uStack_14);

    if (iVar1 != 0) {

      return 0xfffffff5;

    }

    (*(int(*)())0x060349B6)(local_10);

    *(char *)(CD_SESSION_BASE + 0x40) = local_10[0];

    return 0;

  }

  return 0xfffffff5;

}

int FUN_06041698()
{

  char *puVar1;

  int uVar2;

  short sVar4;

  int iVar3;

  int iVar5;

  int iVar6;

  int local_30;

  unsigned int uStack_2c;

  char auStack_28 [16];

  puVar1 = (char *)0x060A5400;

  local_30 = 0;

  iVar6 = 0;

  if ((*(int *)(CD_SESSION_BASE + 0x3c) == 0) ||

     (iVar5 = *(int *)(CD_SESSION_BASE + 0x3c) + -1,

     *(int *)(CD_SESSION_BASE + 0x3c) = iVar5, 0 < iVar5)) {

    uStack_2c = (unsigned int)PTR_DAT_0604172a;

    sVar4 = (*(int(*)())0x06035C4E)();

    if (((int)sVar4 & uStack_2c) == 0) {

      iVar5 = (*(int(*)())0x060349C4)(auStack_28);

      if (iVar5 == 0) {

        (*(int(*)())0x06035168)();

      }

    }

    else {

      (*(int(*)())0x06035C54)(0x0000FBFF);

      (*(int(*)())0x06034984)(auStack_28);

      (*(int(*)())0x06035168)();

      if (*(int *)(*(int *)puVar1 + 0x4c) != 0) {

        iVar5 = *(int *)puVar1;

        (*(int(*)())(*(int *)(iVar5 + 0x4c)))(*(int *)(iVar5 + 0x50));

      }

    }

    for (iVar5 = 0; iVar5 < 8; iVar5 = iVar5 + 1) {

      iVar3 = FUN_060417a8(iVar5);

      if (iVar3 == 0) {

        iVar3 = FUN_06041826(iVar5,&local_30);

        iVar6 = iVar6 + iVar3;

        if (0x1e < local_30) {

          return 1;

        }

      }

    }

    if (iVar6 < 1) {

      uVar2 = 0;

    }

    else {

      uVar2 = 1;

    }

  }

  else {

    FUN_0604231e();

    uVar2 = 3;

  }

  return uVar2;

}

int FUN_060417a8(param_1)
    int param_1;
{

  int iVar1;

  int iVar2;

  if (param_1 == 0) {

    iVar2 = CD_SESSION_BASE;

    iVar1 = 0x58;

  }

  else if (param_1 == 1) {

    iVar1 = (int)DAT_060417d8;

    iVar2 = CD_SESSION_BASE;

  }

  else if (param_1 == 2) {

    iVar1 = (int)DAT_060417da;

    iVar2 = CD_SESSION_BASE;

  }

  else if (param_1 == 3) {

    iVar1 = 0x328;

    iVar2 = CD_SESSION_BASE;

  }

  else if (param_1 == 4) {

    iVar1 = 0x338;

    iVar2 = CD_SESSION_BASE;

  }

  else if (param_1 == 5) {

    iVar1 = 0x348;

    iVar2 = CD_SESSION_BASE;

  }

  else if (param_1 == 6) {

    iVar1 = 0x1e0;

    iVar2 = CD_SESSION_BASE;

  }

  else {

    if (param_1 != 7) goto LAB_06041818;

    iVar2 = CD_SESSION_BASE;

    iVar1 = 0x360;

  }

  param_1 = *(int *)(iVar2 + iVar1);

LAB_06041818:

  return param_1 == 0;

}

int FUN_06041826(param_1, param_2)
    int param_1;
    int param_2;
{

  if (param_1 == 0) {

    FUN_060418be(param_2);

    return 0;

  }

  if (param_1 == 1) {

    FUN_06041aa0(param_2);

    return 0;

  }

  if (param_1 == 2) {

    FUN_06041b3c(param_2);

    return 0;

  }

  if (param_1 == 3) {

    FUN_06041cc8(param_2);

    return 0;

  }

  if (param_1 == 4) {

    FUN_06041d6c(param_2);

    return 0;

  }

  if (param_1 == 5) {

    FUN_06041ee8(param_2);

    return 0;

  }

  if (param_1 == 6) {

    FUN_06042134(param_2);

    return 0;

  }

  if (param_1 != 7) {

    return 0;

  }

  FUN_06042088(param_2);

  return 0;

}

int FUN_0604188c()
{

  int iVar1;

  

  *(char **)(CD_SESSION_BASE + 0x3c) = 0x00008000;

  do {

    iVar1 = FUN_06041698();

  } while (iVar1 == 1);

  *(int *)(CD_SESSION_BASE + 0x3c) = 0;

  return iVar1;

}

int FUN_060418be(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  char *pcVar5;

  int iVar6;

  char local_2c [16];

  puVar2 = (char *)0x060349B6;

  puVar1 = (char *)0x060A5400;

  for (iVar6 = 0; iVar6 < *(int *)(*(int *)puVar1 + 0x54); iVar6 = iVar6 + 1) {

    if (*(int *)(*(int *)puVar1 + 0x58) == 1) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + (iVar6 << 4));

      iVar3 = (*(int(*)())0x06036380)((int)*pcVar5,(int)pcVar5[1]);

      if (iVar3 != 0) break;

      (*(int(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar1 + 0x58) = 2;

    }

    if (*(int *)(*(int *)puVar1 + 0x58) == 2) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + (iVar6 << 4));

      iVar3 = (*(int(*)())0x060362A8)((int)*pcVar5,pcVar5 + 2);

      if (iVar3 != 0) break;

      (*(int(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      if (*(int *)((iVar6 << 4) + *(int *)puVar1 + 0x68) == 0) {

        *(int *)(*(int *)puVar1 + 0x58) = 1;

      }

      else {

        *(int *)(*(int *)puVar1 + 0x58) = 3;

      }

    }

    if (*(int *)(*(int *)puVar1 + 0x58) == 3) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + (iVar6 << 4));

      iVar3 = (*(int(*)())0x060361FC)((int)*pcVar5,*(int *)(pcVar5 + 8),*(int *)(pcVar5 + 0xc));

      if (iVar3 != 0) break;

      (*(int(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar1 + 0x58) = 1;

    }

  }

  if (iVar6 < *(int *)(*(int *)puVar1 + 0x54)) {

    iVar3 = 0;

    for (; iVar6 < *(int *)(*(int *)puVar1 + 0x54); iVar6 = iVar6 + 1) {

      (*(int(*)())0x06035168)(iVar3,*(int *)puVar1 + 0x5c);

      iVar3 = iVar3 + 1;

    }

    *(int *)(*(int *)puVar1 + 0x54) = iVar3;

  }

  else {

    *(int *)(*(int *)puVar1 + 0x54) = 0;

  }

  uVar4 = (*(int(*)())0x06035C4E)();

  if (((uVar4 & 0x40) != 0) && (*(int *)(*(int *)puVar1 + 0x54) == 0)) {

    *(int *)(*(int *)puVar1 + 0x58) = 0;

  }

  return *(int *)(*(int *)puVar1 + 0x54);

}

int FUN_06041aa0(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  unsigned short uVar3;

  char local_14 [16];

  puVar1 = (char *)0x060A5400;

  if (*(int *)((int)DAT_06041b0a + CD_SESSION_BASE) == 1) {

    iVar2 = (*(int(*)())0x06036144)(*(int *)(CD_SESSION_BASE + 0x308));

    *param_1 = *param_1 + 1;

    if (iVar2 == 0) {

      *(int *)(*(int *)puVar1 + (int)DAT_06041b0a) = 2;

    }

    (*(int(*)())0x060349B6)(local_14);

    *(char *)(*(int *)puVar1 + 0x40) = local_14[0];

  }

  if ((*(int *)((int)DAT_06041b0a + *(int *)puVar1) == 2) &&

     (uVar3 = (*(int(*)())0x06035C4E)(), (uVar3 & 0x40) != 0)) {

    *(int *)(*(int *)puVar1 + (int)DAT_06041bc6) = 0;

  }

  return *(int *)((int)DAT_06041bc6 + *(int *)puVar1);

}

int FUN_06041b3c(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int uVar3;

  int iVar4;

  int local_28;

  int iStack_24;

  char local_20 [16];

  puVar2 = (char *)0x060A5400;

  puVar1 = (char *)0x060349B6;

  if (*(int *)((int)DAT_06041bc8 + CD_SESSION_BASE) == 1) {

    (*(int(*)())0x06036572)(*(int *)(CD_SESSION_BASE + 0x310),&local_28);

    (*(int(*)())puVar1)(local_20);

    *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

    *param_1 = *param_1 + 1;

    iVar4 = local_28 - *(int *)(*(int *)puVar2 + (int)DAT_06041bcc);

    local_28 = *(int *)(*(int *)puVar2 + 0x318);

    if (iVar4 < local_28) {

      local_28 = iVar4;

    }

    **(int **)(*(int *)puVar2 + 0x320) = local_28;

    if (local_28 < 1) {

      iVar4 = (int)DAT_06041bc8;

      *(int *)(*(int *)puVar2 + iVar4) = 0;

      if (*(int *)(*(int *)puVar2 + iVar4 + 0x18) != 0) {

        **(int **)(*(int *)puVar2 + (int)DAT_06041bd2) = 0;

      }

      return 0;

    }

    if (*(int *)(*(int *)puVar2 + (int)DAT_06041ca8) == 0) {

      *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 0;

      return 0;

    }

    *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 2;

  }

  if (*(int *)((int)DAT_06041caa + *(int *)puVar2) == 2) {

    if (*(int *)(*(int *)puVar2 + 0x34) == 1) {

      return 2;

    }

    *(int *)(*(int *)puVar2 + 0x34) = 1;

    iVar4 = 0x320;

    iVar4 = (*(int(*)())0x060365C4)(*(int *)(*(int *)puVar2 + iVar4 + -0x10),

                       *(int *)(*(int *)puVar2 + iVar4 + -0xc),

                       **(int **)(*(int *)puVar2 + iVar4));

    if (iVar4 != 0) {

      return 2;

    }

    (*(int(*)())puVar1)(local_20);

    *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 3;

  }

  if (*(int *)((int)DAT_06041caa + *(int *)puVar2) == 3) {

    iVar4 = (*(int(*)())0x0603660E)(&iStack_24);

    if (iVar4 == 0) {

      (*(int(*)())puVar1)(local_20);

      *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

      *param_1 = *param_1 + 1;

      iVar4 = (int)DAT_06041caa;

      *(int *)(*(int *)puVar2 + iVar4) = 0;

      **(int **)(*(int *)puVar2 + iVar4 + 0x18) = iStack_24 << 1;

      *(int *)(*(int *)puVar2 + 0x34) = 0;

      uVar3 = 0;

    }

    else {

      uVar3 = 1;

    }

  }

  else {

    uVar3 = 1;

  }

  return uVar3;

}

int FUN_06041cc8(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  char local_14 [16];

  puVar1 = (char *)0x060A5400;

  if (*(int *)(0x328 + CD_SESSION_BASE) == 1) {

    iVar2 = (int)DAT_06041d5a;

    iVar2 = (*(int(*)())0x060367E8)(*(int *)(CD_SESSION_BASE + iVar2 + -8),

                       *(int *)(CD_SESSION_BASE + iVar2 + -4),

                       *(int *)(CD_SESSION_BASE + iVar2));

    if (iVar2 != 0) {

      return 1;

    }

    (*(int(*)())0x060349B6)(local_14);

    *(char *)(*(int *)puVar1 + 0x40) = local_14[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar1 + 0x328) = 2;

  }

  if ((*(int *)(0x328 + *(int *)puVar1) == 2) &&

     (iVar2 = (*(int(*)())0x06034C68)(0), iVar2 == 0)) {

    *(int *)(*(int *)puVar1 + 0x328) = 0;

    return 0;

  }

  return 1;

}

int FUN_06041d6c(param_1)
    int *param_1;
{

  int bVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  char local_1c [16];

  puVar2 = (char *)0x060A5400;

  bVar1 = 1;

  if (*(int *)(CD_SESSION_BASE + 0x338) == 1) {

    if ((*(int *)(CD_SESSION_BASE + 0x340) == 0) &&

       (*(char **)(CD_SESSION_BASE + (int)DAT_06041df0) == 0x0000FFFF)) {

      iVar3 = (*(int(*)())0x060364D4)(0,*(int *)(CD_SESSION_BASE + (int)DAT_06041df2));

      if (iVar3 != 0) {

        return 1;

      }

      (*(int(*)())0x060349B6)(local_1c);

      *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar2 + 0x338) = 4;

    }

    else if (*(int *)(CD_SESSION_BASE + (int)DAT_06041df0) == 0) {

      bVar1 = 0;

    }

    else {

      *(int *)(CD_SESSION_BASE + 0x338) = 2;

    }

  }

  if (*(int *)(0x338 + *(int *)puVar2) == 2) {

    iVar3 = (int)DAT_06041eb6;

    iVar3 = (*(int(*)())0x0603683C)(*(int *)(*(int *)puVar2 + iVar3 + -8),

                       *(int *)(*(int *)puVar2 + iVar3 + -4),

                       *(int *)(*(int *)puVar2 + iVar3));

    *param_1 = *param_1 + 1;

    if (iVar3 == 0) {

      *(int *)(*(int *)puVar2 + 0x338) = 3;

      (*(int(*)())0x060349B6)(local_1c);

      *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    }

  }

  uVar5 = PTR_DAT_06041eb8;

  if ((*(int *)(0x338 + *(int *)puVar2) == 3) &&

     (uVar4 = (*(int(*)())0x06035C4E)(), (uVar4 & uVar5) != 0)) {

    bVar1 = 0;

  }

  if ((*(int *)(0x338 + *(int *)puVar2) == 4) &&

     (uVar5 = (*(int(*)())0x06035C4E)(), (uVar5 & 0x40) != 0)) {

    bVar1 = 0;

  }

  if (!bVar1) {

    (*(int(*)())0x06035C54)(0x0000FFF7);

    *(int *)(*(int *)puVar2 + (int)DAT_06041f90) = 0;

    *(int *)(*(int *)puVar2 + 0x34) = 0;

  }

  return bVar1;

}

int FUN_06041ee8(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  char local_1c [16];

  puVar2 = (char *)0x060A5400;

  puVar1 = (char *)0x060349B6;

  if (*(int *)(0x348 + CD_SESSION_BASE) == 1) {

    (*(int(*)())0x060363BC)(*(int *)(CD_SESSION_BASE + (int)DAT_06041f96),

               CD_SESSION_BASE + (int)DAT_06041f94);

    *param_1 = *param_1 + 1;

    (*(int(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    iVar3 = (*(int(*)())0x06036380)(*(int *)(*(int *)puVar2 + (int)DAT_06041f96),0);

    if (iVar3 != 0) {

      return 1;

    }

    (*(int(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + 0x348) = 2;

  }

  if (*(int *)(0x348 + *(int *)puVar2) == 2) {

    iVar3 = (int)DAT_06041f96;

    iVar3 = (*(int(*)())0x0603697C)(*(int *)(*(int *)puVar2 + iVar3 + 4),

                       *(int *)(*(int *)puVar2 + iVar3 + 8),

                       *(int *)(*(int *)puVar2 + iVar3 + 0xc),

                       *(int *)(*(int *)puVar2 + iVar3));

    if (iVar3 != 0) {

      return 1;

    }

    (*(int(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + 0x348) = 3;

  }

  uVar5 = DAT_0604207c;

  if ((*(int *)(0x348 + *(int *)puVar2) == 3) &&

     (uVar4 = (*(int(*)())0x06035C4E)(), (uVar4 & uVar5) != 0)) {

    *(int *)(*(int *)puVar2 + 0x348) = 4;

  }

  if (*(int *)(0x348 + *(int *)puVar2) == 4) {

    iVar3 = (*(int(*)())0x06036380)(*(int *)(*(int *)puVar2 + DAT_0604207e + -0x10),

                       *(int *)(*(int *)puVar2 + (int)DAT_0604207e));

    if (iVar3 != 0) {

      return 1;

    }

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + 0x348) = 5;

  }

  if ((*(int *)(0x348 + *(int *)puVar2) == 5) &&

     (uVar5 = (*(int(*)())0x06035C4E)(), (uVar5 & 0x40) != 0)) {

    *(int *)(*(int *)puVar2 + 0x348) = 0;

  }

  return *(int *)(0x348 + *(int *)puVar2);

}
