extern int DAT_06003406;

extern int DAT_06003408;

void FUN_0600338c(param_1, param_2)
    unsigned int param_1;
    int param_2;
{

  if ((param_1 & 4) == 0) {

    (*(int(*)())0x060284AE)(0xc,((param_2 << 6) + 0xb) << 1,0x60,0x0605ACDD);

    return;

  }

  if ((*(unsigned short *)0x06063DA0 & DAT_06003406) == 0) {

    (*(int(*)())0x06028400)(0xc,*(int *)0x06063AD0,((param_2 << 6) + 0xb) << 1,

               *(int *)(0x06063AD0 + 4) + (int)DAT_06003408);

    return;

  }

  return;

}
