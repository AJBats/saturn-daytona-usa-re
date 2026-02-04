extern short DAT_06018ed6;
extern volatile char REG_25B00217;
extern volatile char REG_25B00237;

void FUN_06018ec8()
{
  REG_25B00217 = (unsigned char)DAT_06018ed6;
  REG_25B00237 = (char)DAT_06018ed6;
  return;
}
