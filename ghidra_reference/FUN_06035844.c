int FUN_06035844()
{

  int bVar1;

  unsigned int in_stack_00000000;

  unsigned int in_stack_00000004;

  unsigned int in_stack_00000008;

  unsigned int in_stack_0000000c;

  if ((((in_stack_00000008 & 0x7FF00000) == 0x7FF00000) &&

      (((in_stack_00000008 & 0x000FFFFF) != 0 || (in_stack_0000000c != 0)))) ||

     (((in_stack_00000000 & 0x7FF00000) == 0x7FF00000 &&

      (((in_stack_00000000 & 0x000FFFFF) != 0 || (in_stack_00000004 != 0)))))) {

    bVar1 = 0;

  }

  else if (((((in_stack_00000008 & 0x7FF00000) == 0) && ((in_stack_00000000 & 0x7FF00000) == 0))

           && ((in_stack_00000008 & 0x000FFFFF) == 0)) &&

          (((in_stack_0000000c == 0 && ((in_stack_00000000 & 0x000FFFFF) == 0)) &&

           (in_stack_00000004 == 0)))) {

    bVar1 = 0;

  }

  else if ((int)in_stack_00000008 < 0 == (int)in_stack_00000000 < 0) {

    if (-1 < (int)in_stack_00000008) {

      in_stack_00000008 = in_stack_00000000 - in_stack_00000008;

      bVar1 = in_stack_00000000 < in_stack_00000008 ||

              in_stack_00000008 <

              in_stack_00000008 - (in_stack_00000004 < in_stack_00000004 - in_stack_0000000c);

    }

    else {

      in_stack_00000004 = in_stack_0000000c - in_stack_00000004;

      in_stack_00000000 = in_stack_00000008 - in_stack_00000000;

      bVar1 = in_stack_00000008 < in_stack_00000000 ||

              in_stack_00000000 <

              in_stack_00000000 -

              (in_stack_0000000c < in_stack_00000004 ||

              in_stack_00000004 < in_stack_00000004 - (-1 < (int)in_stack_00000008));

    }

  }

  else {

    bVar1 = -1 < (int)in_stack_00000008;

  }

  return bVar1;

}
