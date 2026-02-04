int FUN_06035b34()
{

  unsigned int in_stack_00000000;

  int in_stack_00000004;

  unsigned int in_stack_00000008;

  int in_stack_0000000c;

  if ((in_stack_00000008 & 0x7FF00000) == 0x7FF00000) {

    if ((in_stack_00000008 & 0x000FFFFF) != 0) {

      return 1;

    }

    if (in_stack_0000000c != 0) {

      return 1;

    }

  }

  if ((in_stack_00000000 & 0x7FF00000) == 0x7FF00000) {

    if ((in_stack_00000000 & 0x000FFFFF) != 0) {

      return 1;

    }

    if (in_stack_00000004 != 0) {

      return 1;

    }

  }

  if ((in_stack_00000008 & 0x7FF00000) == 0) {

    if ((in_stack_00000000 & 0x7FF00000) != 0) {

      return 1;

    }

    if (((in_stack_00000008 & 0x000FFFFF) == 0) && (in_stack_0000000c == 0)) {

      if ((in_stack_00000000 & 0x000FFFFF) != 0) {

        return 1;

      }

      if (in_stack_00000004 != 0) {

        return 1;

      }

      return 0;

    }

  }

  if ((in_stack_00000000 == in_stack_00000008) && (in_stack_00000004 == in_stack_0000000c)) {

    return 0;

  }

  return 1;

}
