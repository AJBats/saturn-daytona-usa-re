void FUN_060039c8()
{

  int *puVar1;

  int uVar2;

  if (*(int *)0x06083255 == '\0') {

    uVar2 = 0x60;

    puVar1 = (int *)(0x0605C97C + *(int *)(0x06078868 << 2));

  }

  else {

    puVar1 = (int *)(0x0605CA4C + *(int *)(0x0607EAB8 << 2));

    uVar2 = 0x20;

  }

  (*(int(*)())0x0602766C)(0x25F00400,*puVar1,uVar2);

  return;

}
