void FUN_06035168()
{

  unsigned int in_r0;

  int *in_r1;

  int *in_r2;

  int *puVar1;

  int *puVar2;

  if (in_r0 < 0x41) {

    (*(void(*)())(*(int *)(0x060351C4 + in_r0)))();

    return;

  }

  puVar2 = (int *)((int)in_r2 + in_r0);

  while( 1 ) {

    puVar1 = in_r2 + 1;

    if (puVar2 < puVar1) {

      return;

    }

    *in_r1 = *in_r2;

    in_r2 = in_r2 + 2;

    if (puVar2 < in_r2) break;

    in_r1[1] = *puVar1;

    in_r1 = in_r1 + 2;

  }

  return;

}
