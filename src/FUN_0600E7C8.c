extern int DAT_0600e86c;

extern int DAT_0600e86e;

extern int DAT_0600e870;

extern int DAT_0600e872;

extern int DAT_0600e91e;

extern int DAT_0600e920;

extern int DAT_0600e922;

extern int PTR_DAT_0600e874;

extern int PTR_DAT_0600e874;

extern int PTR_DAT_0600e924;

extern int PTR_DAT_0600e924;

void FUN_0600e7c8()
{

  short extraout_var;

  int iVar1;

  int iVar2;

  int iVar3;

  iVar3 = *(int *)0x0607E940;

  (*(void(*)())0x06008318)();

  (*(void(*)())0x06008640)();

  (*(void(*)())0x0600D266)();

  (*(void(*)())0x0600C4F8)();

  (*(void(*)())0x0602D88E)();

  if (*(int *)0x06083261 == '\x01') {

    iVar1 = (int)(short)((short)((*(int *)(iVar3 + DAT_0600e86c) - *(int *)(iVar3 + 0x28)) * 0x10000

                                >> 0x12) + (short)*(int *)(iVar3 + 0x28));

    *(int *)(iVar3 + 0x30) = iVar1;

    *(int *)(iVar3 + 0x28) = iVar1;

  }

  else if (*(int *)0x06083261 == '\x02') {

    iVar1 = (int)DAT_0600e86c;

    iVar2 = (int)(short)((short)((int)(0x00008000 +

                                      (*(int *)(iVar3 + iVar1) - *(int *)(iVar3 + 0x28))) * 0x10000

                                >> 0x11) + (short)*(int *)(iVar3 + 0x28));

    *(int *)(iVar3 + 0x30) = iVar2;

    *(int *)(iVar3 + 0x28) = iVar2;

    if ((*(int *)(iVar3 + iVar1 + -0x54) != 0) &&

       (iVar1 = *(int *)(iVar3 + DAT_0600e86e) + -1, *(int *)(iVar3 + DAT_0600e86e) = iVar1,

       iVar1 == 0)) {

      iVar1 = (int)DAT_0600e872;

      *(int *)(iVar3 + iVar1) =

           (int)*(short *)(*(int *)(iVar3 + DAT_0600e870) * 0x18 +

                           *(int *)(iVar3 + DAT_0600e870 + -4) + 0x14);

      *(int *)(iVar3 + iVar1 + 0xc) = (int)PTR_DAT_0600e874;

    }

  }

  (*(void(*)())0x0600CEBA)();

  iVar1 = (int)DAT_0600e91e;

  *(int *)(iVar3 + iVar1 + -0x34) =

       *(int *)(iVar3 + iVar1) * *(int *)0x0607EA9C + *(int *)(iVar3 + iVar1 + -0x3c);

  *(int *)(iVar3 + DAT_0600e920) =

       (int)*(short *)(*(int *)(iVar3 + iVar1 + -0x44) * 0x18 + *(int *)(iVar3 + iVar1 + -0x48) +

                      0x14);

  if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00200000) != 0) {

    (*(void(*)())0x06027552)(*(int *)(iVar3 + 0xc),0x066505B3);

    *(int *)(DAT_0600e922 + iVar3) = (int)extraout_var;

    *(int *)(PTR_DAT_0600e924 + iVar3) = (int)extraout_var;

  }

  return;

}
