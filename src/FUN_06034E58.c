extern int PTR_DAT_06034ee8;

extern int PTR_DAT_06034ee8;

unsigned char FUN_06034e58()
{

  short uStack_2;

  *(int *)0x06063578 = 0;

  do {

  } while ((**(unsigned char **)0x0606358C & 1) == 1);

  **(char **)0x0606358C = 1;

  **(char **)0x06063584 = *0x06059CAD;

  do {

  } while ((**(unsigned char **)0x0606358C & 1) == 1);

  for (uStack_2 = 0; (int)(unsigned int)uStack_2 < (int)PTR_DAT_06034ee8; uStack_2 = uStack_2 + 1) {

  }

  **(int **)0x06063580 = 0x06034F08;

  **(char **)0x0606358C = 1;

  **(char **)0x06063584 = *0x06059CAC;

  do {

  } while ((**(unsigned char **)0x0606358C & 1) == 1);

  return **(unsigned char **)0x0606358C & 1;

}
