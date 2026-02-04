void FUN_06042a8c(param_1)
    unsigned int *param_1;
{

  Onchip_DMA0R = Onchip_DMA0R & 0xfffffff7 | *param_1;

  if ((param_1[2] & 4) == 4) {

    Onchip_DMA0R = Onchip_DMA0R & 0xfffffffe | param_1[1];

  }

  if ((param_1[2] & 1) == 1) {

    Onchip_DMA0R = Onchip_DMA0R & 0xfffffffb;

  }

  if ((param_1[2] & 2) == 2) {

    Onchip_DMA0R = Onchip_DMA0R & 0xfffffffd;

  }

  return;

}
