extern int DAT_0601ae3e;

char * FUN_0601adb0()
{

  char *puVar1;

  char *puVar2;

  puVar1 = 0x0607EAD8;

  puVar2 = (char *)0x0;

  if (*(int *)0x0607EAE0 != 0) {

    if ((*(int *)0x06078638 <

         *(int *)(*(int *)(0x0605DE24 +

                          (*(int *)0x0607EAD8 * 2 + *(int *)0x0607EAE0) * 4) + 4)) &&

       (0 < *(int *)0x06078638)) {

      *(int *)

       (*(int *)(0x0605DE24 + (*(int *)0x0607EAD8 * 2 + *(int *)0x0607EAE0) * 4) +

       4) = *(int *)(0x06078900 + DAT_0601ae3e);

    }

    puVar2 = 0x0605DE40 + (char)((char)*(int *)puVar1 * '\f');

    if ((*(unsigned int *)0x060786A4 < *(unsigned int *)(puVar2 + *(int *)0x0605AD00 * 4)) &&

       (puVar2 = (char *)0x0, *(int *)0x0607EBF4 != 0)) {

      puVar2 = 0x0605DE40 + (char)((char)*(int *)puVar1 * '\f');

      *(int *)(puVar2 + *(int *)0x0605AD00 * 4) = *(int *)0x060786A4;

    }

  }

  return puVar2;

}
