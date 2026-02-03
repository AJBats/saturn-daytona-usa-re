int FUN_0602755c(param_1, param_2)
    int param_1;
    int param_2;
{

  int *puVar1;



  puVar1 = (int *)0xFFFFFF00;

  *puVar1 = param_2;

  puVar1[4] = (int)(short)((unsigned int)param_1 >> 0x10);

  puVar1[5] = param_1 << 0x10;

  return puVar1[7];

}
