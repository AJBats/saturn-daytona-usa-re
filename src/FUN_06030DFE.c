extern int DAT_06030eae;

void FUN_06030dfe(int param_1,int param_2,int param_3,int param_4,int param_5
{

  short sVar1;

  long long lVar2;

  int iVar3;

  int iVar4;

  char *puVar5;

  int extraout_r3;

  int extraout_r3_00;

  char *puVar6;

  int iVar7;

  int iVar8;

  int unaff_r14;

  puVar6 = 0x00038000;

  sVar1 = *(short *)0x06030FBC;

  puVar5 = 0x00013333;

  if (param_6 != 0) {

    iVar3 = (*(void(*)())0x06027348)(*(int *)(unaff_r14 + 0x30) - param_7);

    if (iVar3 < 0) {

      iVar3 = -iVar3;

    }

    puVar5 = (char *)

             ((int)((unsigned long long)((long long)(int)puVar6 * (long long)iVar3) >> 0x20) << 0x10 |

             (unsigned int)((long long)(int)puVar6 * (long long)iVar3) >> 0x10);

    param_5 = extraout_r3;

  }

  if (param_5 < 1) {

    puVar5 = puVar5 + param_2;

  }

  else {

    puVar5 = puVar5 + -param_2;

    if ((int)puVar5 < 1) {

      return;

    }

  }

  iVar7 = *(int *)(unaff_r14 + 0x10);

  iVar8 = *(int *)(unaff_r14 + 0x18);

  *(int *)(unaff_r14 + 0x38) = iVar7;

  *(int *)(unaff_r14 + 0x3c) = iVar8;

  iVar3 = (*(void(*)())0x06027344)();

  iVar4 = (*(void(*)())0x06027348)(-(int)sVar1);

  *(unsigned int *)(unaff_r14 + 0x10) =

       iVar7 + ((int)((unsigned long long)((long long)extraout_r3_00 * (long long)iVar4) >> 0x20) << 0x10 |

               (unsigned int)((long long)extraout_r3_00 * (long long)iVar4) >> 0x10);

  *(unsigned int *)(unaff_r14 + 0x18) =

       iVar8 + ((int)((unsigned long long)((long long)(int)puVar5 * (long long)iVar3) >> 0x20) << 0x10 |

               (unsigned int)((long long)(int)puVar5 * (long long)iVar3) >> 0x10);

  puVar6 = 0x0000C000;

  if ((*(short *)(DAT_06030eae + unaff_r14) < 8) &&

     (puVar6 = 0x0000DEB8, 5 < *(short *)(DAT_06030eae + unaff_r14))) {

    puVar6 = 0x0000FAE1;

  }

  lVar2 = (long long)(int)puVar6 * (long long)*(int *)(unaff_r14 + 0xc);

  *(unsigned int *)(unaff_r14 + 0xc) = (int)((unsigned long long)lVar2 >> 0x20) << 0x10 | (unsigned int)lVar2 >> 0x10;

  return;

}
