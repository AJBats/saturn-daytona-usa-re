/* FUN_06033240  0x06033240 */


undefined8 FUN_06033240(undefined *param_1,uint param_2,int param_3,int param_4)

{
  int extraout_r1;
  char *extraout_r3;
  
  do {
    FUN_06033278(param_1,param_2);
    param_4 = param_4 + -1;
    if (param_4 < 1) {
      param_3 = param_3 + -1;
      if (param_3 < 1) {
        return CONCAT44(PTR_DAT_06033270 + DAT_06033274 + extraout_r1,PTR_DAT_06033270);
      }
      param_4 = 4;
    }
    param_2 = FUN_06033278(PTR_DAT_06033270,(uint)(int)*extraout_r3 >> 4);
    param_2 = param_2 & 0xf;
    param_1 = PTR_DAT_06033270;
  } while( true );
}

