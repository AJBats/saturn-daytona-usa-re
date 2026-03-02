char * FUN_0603da88()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  puVar1 = (char *)(*(int(*)())0x06036BE4)();

  puVar2 = 0x00010000;

  if (puVar1 != (char *)0x0) {

    if ((int)puVar1 < (int)0x010E0000) {

      if ((int)0x00B40000 < (int)puVar1) {

        iVar3 = (*(int(*)())0x0604249C)(puVar1 + 0xFF4C0000);

        puVar2 = (char *)-iVar3;

      }

      else {

        puVar2 = 0xFFFF0000;

        if (puVar1 != 0x00B40000) {

          if ((int)puVar1 < (int)0x005A0000) {

            puVar2 = (char *)(*(int(*)())0x0604249C)(puVar1);

          }

          else {

            iVar3 = (*(int(*)())0x0604249C)((int)0x00B40000 - (int)puVar1);

            puVar2 = (char *)-iVar3;

          }

        }

      }

    }

    else {

      puVar2 = (char *)(*(int(*)())0x0604249C)((int)0x01680000 - (int)puVar1);

    }

  }

  return puVar2;

}
