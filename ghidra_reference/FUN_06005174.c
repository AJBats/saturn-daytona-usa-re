void FUN_06005174()
{
  register short *ptr asm("r5");
  register short zero asm("r4");
  unsigned short u0, u1, u2, u3;

  ptr = (short *)0x06063D98;
  zero = 0;
  ptr[0] = zero;
  u0 = (unsigned short)zero;
  ptr[1] = u0;
  u1 = (unsigned short)zero;
  ptr[2] = u1;
  u2 = (unsigned short)zero;
  ptr[3] = u2;
  ptr += 4;
  u3 = (unsigned short)zero;
  ptr[0] = zero;
  ptr[1] = u3;
  u0 = (unsigned short)zero;
  ptr[2] = u0;
  u1 = (unsigned short)zero;
  ptr[3] = u1;
}
