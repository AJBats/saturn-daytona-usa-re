extern int DAT_0602f1ba;

extern int DAT_0602f1bc;

extern int DAT_0602f1be;

extern int DAT_0602f1f2;

extern int DAT_0602f24c;

extern int DAT_0602f24e;

extern int PTR_DAT_0602f250;

extern int PTR_DAT_0602f250;

extern int PTR_DAT_0602f26e;

extern int PTR_DAT_0602f26e;

void FUN_0602f17c()
{

  short sVar1;

  int in_r0;

  unsigned int uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  iVar5 = (int)DAT_0602f1ba;

  iVar3 = *(int *)(iVar5 + in_r0);

  iVar4 = 0;

  if (iVar3 != 0) {

    if (-1 < iVar3) {

      iVar3 = iVar3 + -2;

    }

    iVar4 = iVar3 + 1;

  }

  *(int *)(iVar5 + in_r0) = iVar4;

  iVar3 = (int)DAT_0602f1bc;

  iVar4 = *(short *)(iVar3 + in_r0) * 4;

  if ((*(int *)(in_r0 + 8) == 0) ||

     (*(int *)(DAT_0602f1be + in_r0) <= *(int *)(0x060477AC + iVar4))) {

    if (*(int *)(DAT_0602f1be + in_r0) <= *(int *)(0x0604779C + iVar4)) {

      *(int *)(iVar5 + in_r0) = 0xfffffffb;

      iVar4 = *(short *)(iVar3 + in_r0) + -1;

      *(short *)(iVar3 + in_r0) = (short)iVar4;

      iVar5 = (int)DAT_0602f24c;

      uVar2 = (*(void(*)())0x0602755C)(*(int *)(iVar5 + in_r0) << 0x10,

                         *(int *)(0x060477CC + iVar4 * 4));

      *(unsigned int *)(iVar5 + in_r0) = uVar2 >> 0x10;

    }

  }

  else {

    *(int *)(iVar5 + in_r0) = 5;

    sVar1 = *(short *)(iVar3 + in_r0);

    *(short *)(iVar3 + in_r0) = sVar1 + 1;

    *(unsigned int *)(DAT_0602f1f2 + in_r0) =

         (unsigned int)((unsigned long long)

                ((long long)(*(int *)(DAT_0602f1f2 + in_r0) << 0x10) *

                (long long)*(int *)(0x060477CC + sVar1 * 4)) >> 0x20) & 0xffff;

  }

  iVar5 = (*(int *)(DAT_0602f24c + in_r0) + *(int *)(PTR_DAT_0602f250 + in_r0)) -

          *(int *)(DAT_0602f24e + in_r0);

  iVar4 = *(int *)(0x0602F3CC + *(short *)(iVar3 + in_r0) * 8);

  iVar3 = *(int *)((int)(0x0602F3CC + *(short *)(iVar3 + in_r0) * 8) + 4);

  if ((iVar4 < iVar5) && (iVar4 = iVar5, iVar3 < iVar5)) {

    iVar4 = iVar3;

  }

  *(int *)(PTR_DAT_0602f26e + in_r0) = *(int *)(DAT_0602f24e + in_r0) + iVar4;

  return;

}
