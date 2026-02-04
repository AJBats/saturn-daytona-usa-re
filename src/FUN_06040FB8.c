int FUN_06040fb8()
{

  int *piVar1;

  piVar1 = 0x060A5400;

  if (*(int *)(*0x060A5400 + 0x30) == 1) {

    return 0xfffffffb;

  }

  *(int *)(*0x060A5400 + 0x30) = 1;

  *(int *)(*piVar1 + 0x38) = *(int *)(*piVar1 + 0x38) + 1;

  if (*(int *)(*piVar1 + 0x38) < 0) {

    *(int *)(*piVar1 + 0x38) = 0;

  }

  return *(int *)(*piVar1 + 0x38);

}
