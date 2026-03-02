extern int Onchip_DMA0R;

void FUN_06042a8c(param_1)
    unsigned int *param_1;
{
  register int *reg asm("r2") = &Onchip_DMA0R;
  int flags;
  int val;

  val = *reg;
  val = (val & 0xfffffff7) | *param_1;
  *reg = val;

  flags = param_1[2];

  if ((flags & 4) == 4) {
    val = (val & 0xfffffffe) | param_1[1];
    *reg = val;
  }

  if ((flags & 1) == 1) {
    val = val & 0xfffffffb;
    *reg = val;
  }

  if ((flags & 2) == 2) {
    val = val & 0xfffffffd;
    *reg = val;
  }
}
