int FUN_06006838(param_1, param_2)
    int param_1;
    int param_2;
{
    return (((unsigned int)(0x03FFFFFF - param_2) >> 21) << 6)
         + ((unsigned int)(param_1 + 0x04000000) >> 21);
}
