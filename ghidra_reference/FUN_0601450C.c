extern int DAT_06014594;

void FUN_0601450c()
{

  char *puVar1;

  int iVar2;

  puVar1 = 0x06084B08;

  iVar2 = *(int *)0x06084B08;

  if ((*(unsigned int *)0x0607EBC8 & 3) == 0) {

    if ((*(unsigned short *)0x06063D98 & DAT_06014594) == 0) {

      if ((((unsigned int)*(unsigned short *)0x06063D98 & (unsigned int)0x00008000) != 0) &&

         (*(unsigned int *)0x06084B08 < 0x1c)) {

        *(int *)0x06084B08 = *(int *)0x06084B08 + 1;

      }

    }

    else if (*(int *)0x06084B08 != 0) {

      *(int *)0x06084B08 = *(int *)0x06084B08 + -1;

    }

  }

  if (2 < *(unsigned int *)0x06084B18) {

    if (*(unsigned int *)puVar1 < 0x1b) {

      *(int *)puVar1 = 0x1b;

    }

    else if (0x1c < *(unsigned int *)puVar1) {

      *(int *)puVar1 = 0x1c;

    }

  }

  *(unsigned int *)0x06084B20 =

       (unsigned int)(unsigned char)((int *)0x0605AD2C)[*(int *)puVar1];

  if (iVar2 != *(int *)puVar1) {

    (*(int(*)())0x0601D5F4)(0,0xAB111DFF);

    return;

  }

  return;

}
