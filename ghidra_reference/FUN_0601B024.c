/* FUN_0601B024  0x0601B024 */


void FUN_0601b024(void)

{
  undefined4 in_r7;
  
  *(undefined4 *)PTR_DAT_0601b064 = 0x30;
  (*(code *)PTR_FUN_0601b068)
            (in_r7,0x30,0x30,in_r7,1,0x30,(int)PTR_DAT_0601b060._0_2_,(int)DAT_0601b05e);
  FUN_0601b0d8();
  *PTR_DAT_0601b070 = 0x14;
  *PTR_DAT_0601b06c = *PTR_DAT_0601b06c + '\x01';
  return;
}

