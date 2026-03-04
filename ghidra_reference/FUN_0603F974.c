/* FUN_0603F974  0x0603F974 */


undefined1 FUN_0603f974(int param_1,int param_2)

{
  undefined1 uVar1;
  int in_r0;
  
  uVar1 = *(undefined1 *)(param_1 + in_r0);
  *(char *)(param_1 + 0x35) = (char)param_2;
  if ((-1 < param_2) && (param_2 < 4)) {
    FUN_0603f92c(param_1,0,PTR_PTR_0603f9b4 + (char)((char)param_2 * '\f'));
  }
  return uVar1;
}

