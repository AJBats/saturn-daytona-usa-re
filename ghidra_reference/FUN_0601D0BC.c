void FUN_0601d0bc(param_1, param_2, param_3, param_4)
    unsigned short param_1;
    unsigned short *param_2;
    unsigned short *param_3;
    unsigned short *param_4;
{

  *param_2 = param_1 & 0x1f;

  *param_3 = (unsigned short)((int)(unsigned int)param_1 >> 5) & 0x1f;

  *param_4 = (unsigned short)((int)(unsigned int)param_1 >> 10) & 0x1f;

  return;

}
