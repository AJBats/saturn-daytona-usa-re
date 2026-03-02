int FUN_06027476(param_1)
    unsigned int param_1;
{
  int result;
  int bit;
  int sq;

  result = 0;
  if ((int)param_1 > 0) {
    bit = 0x8000;
    do {
      result = result + bit;
      sq = result * result;
      if ((unsigned int)sq == param_1) break;
      if ((unsigned int)sq > param_1) {
        result = result - bit;
      }
      bit = bit >> 1;
    } while (bit > 0);
  }
  return result << 8;
}
