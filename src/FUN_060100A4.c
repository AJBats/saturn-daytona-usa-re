extern int DAT_060100f6;

extern int DAT_060100f8;

extern int DAT_060101b2;

extern int PTR_DAT_06010274;

extern int PTR_DAT_06010274;

int FUN_060100a4(param_1)
    unsigned char param_1;
{

  short sVar1;

  unsigned short uVar2;

  char *puVar3;

  int iVar4;

  char *puVar5;

  int iVar6;

  char *puVar7;

  int iVar8;

  puVar7 = 0x00010000;

  sVar1 = (unsigned short)param_1 + DAT_060100f6;

  iVar6 = (int)DAT_060100f8;

  iVar4 = *(int *)(0x060447C8 + (unsigned int)param_1 * 0x10);

  puVar5 = *(char **)((int)(0x060447C8 + (unsigned int)param_1 * 0x10) + 4);

  if ((unsigned int)param_1 == *(unsigned int *)0x0607EAD8) {

    puVar3 = 0x0605D0BC + (unsigned int)param_1 * 0x20;

  }

  else {

    puVar3 = 0x0605D0BC + (param_1 + 3) * 0x20;

  }

  (*(void(*)())0x0602766C)(*(int *)(0x06078888 + (unsigned int)param_1 * 4),puVar3,0x20);

  if (4 < (unsigned char)*0x0607887F) {

    if ((unsigned int)param_1 == *(unsigned int *)0x0607EAD8) {

      if (*(unsigned short *)(0x06078870 + (unsigned int)param_1 * 2) < 0x1e) {

        uVar2 = *(short *)(0x06078870 + (unsigned int)param_1 * 2) + 1;

        *(unsigned short *)(0x06078870 + (unsigned int)param_1 * 2) = uVar2;

      }

      else {

        *(short *)(0x06078870 + (unsigned int)param_1 * 2) = 0x20;

        uVar2 = 0x20;

      }

      iVar4 = iVar4 + *(int *)(0x060447F8 + (char)(param_1 * '\f')) * (unsigned int)uVar2;

      puVar5 = puVar5 + *(int *)((int)(0x060447F8 + (char)(param_1 * '\f')) + 4) * (unsigned int)uVar2

      ;

      iVar8 = (unsigned int)uVar2 * (int)DAT_060101b2;

    }

    else {

      if (0x1d < *(unsigned short *)(0x06078870 + (unsigned int)param_1 * 2)) {

        return (unsigned int)param_1 * 2;

      }

      uVar2 = *(short *)(0x06078870 + (unsigned int)param_1 * 2) + 1;

      *(unsigned short *)(0x06078870 + (unsigned int)param_1 * 2) = uVar2;

      iVar8 = (unsigned int)uVar2 * (int)PTR_DAT_06010274;

    }

    iVar6 = iVar6 + (unsigned int)uVar2 * -0x800;

    puVar7 = puVar7 + -iVar8;

  }

  if (0xb < (unsigned char)*0x0607887F) {

    puVar5 = 0x00960000;

  }

  iVar4 = (*(void(*)())0x06011AF4)(iVar4,puVar5,

                     (*(unsigned int *)(0x06044844 + *(int *)0x0605AA98 * 4) >> 1) << 0x10,

                     0x00200000,iVar6,puVar7,(int)sVar1);

  return iVar4;

}
