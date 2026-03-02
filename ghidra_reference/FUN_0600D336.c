void FUN_0600d336()
{
  int base1;
  int base2;
  short off;

  base1 = 0x06078900;
  base2 = base1 + 0x0268;

  if ((*(unsigned int *)0x0607EBC4 & 0x00200000) == 0) {

    off = 0x01F4;
    if (*(int *)(base1 + off) < *(int *)(base2 + off)) {
      off = 0x0224;
      *(int *)(base1 + off) = 1;
      *(int *)(base2 + off) = 0;
    }
    else {
      off = 0x0224;
      *(int *)(base1 + off) = 0;
      *(int *)(base2 + off) = 1;
    }
  }
}
