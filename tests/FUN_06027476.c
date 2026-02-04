int FUN_06027476(param_1)
    unsigned int param_1;
{
  int result;
  unsigned int bit;
  unsigned int sq;

  result = 0;
  if (0 < (int)param_1) {
    bit = 0x8000;
    do {
      result = result + (int)bit;
      sq = (unsigned int)(result * result);
      if (sq == param_1) break;
      if (sq > param_1) {
        result = result - (int)bit;
      }
      bit = bit >> 1;
    } while ((int)bit > 0);
  }
  return result << 8;
}
