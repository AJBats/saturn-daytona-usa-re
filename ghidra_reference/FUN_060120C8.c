extern int DAT_0601214e;

extern int FUN_0601228a();

void FUN_060120c8()
{

  char *puVar1;

  char *puVar2;

  *(int *)0x06078636 = 1;

  *(int *)0x060788F8 = 0;

  (*(int(*)())0x06014884)(0x20,0,0);

  puVar1 = 0x060788B4;

  *(int *)0x060788B4 = 0;

  puVar2 = 0x00080000;

  *(char **)(puVar1 + 4) = 0x00080000;

  *(char **)(puVar1 + 8) = 0x000F3333;

  puVar1 = 0x060788C0;

  *(int *)0x060788C0 = 0;

  *(unsigned int *)(puVar1 + 4) = (unsigned int)puVar2 >> 2;

  *(char **)(puVar1 + 8) = 0x00053333;

  (*(int(*)())0x06035168)();

  (*(int(*)())0x06035168)();

  (*(int(*)())0x06035168)();

  *(short *)0x060788B0 = DAT_0601214e;

  *(short *)0x060788B2 = 0;

  *(int *)0x060788F0 = 0;

  puVar1 = 0x060788F4;

  if (*(int *)0x0607EAD8 == 0) {

    *(int *)0x060788AC = 0x3c;

    *(int *)puVar1 = 0;

    return;

  }

  *(int *)0x060788AC = 1;

  *(int *)puVar1 = 0x14;

  FUN_0601228a();

  return;

}
