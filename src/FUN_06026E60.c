unsigned int FUN_06026e60(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  long long lVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int *puVar4;

  puVar4 = *(unsigned int **)0x06089EDC;

  iVar3 = 3;

  do {

    *puVar4 = (int)((unsigned long long)((long long)param_1 * (long long)(int)*puVar4) >> 0x20) << 0x10 |

              (unsigned int)((long long)param_1 * (long long)(int)*puVar4) >> 0x10;

    uVar2 = puVar4[6];

    lVar1 = (long long)param_3 * (long long)(int)uVar2;

    puVar4[3] = (int)((unsigned long long)((long long)param_2 * (long long)(int)puVar4[3]) >> 0x20) << 0x10 |

                (unsigned int)((long long)param_2 * (long long)(int)puVar4[3]) >> 0x10;

    iVar3 = iVar3 + -1;

    puVar4[6] = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

    puVar4 = puVar4 + 1;

  } while (iVar3 != 0);

  return uVar2;

}
