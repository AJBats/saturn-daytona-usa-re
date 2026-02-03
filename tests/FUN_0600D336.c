void FUN_0600d336()
{

  int iVar1;

  int iVar2;



  iVar2 = 0x06078900 + 0x0268;

  if ((*(unsigned int *)0x0607EBC4 & (unsigned int)0x00200000) == 0) {

    if (*(int *)(0x06078900 + 0x01F4) < *(int *)(iVar2 + 0x01F4)) {

      iVar1 = 0x0224;

      *(int *)(0x06078900 + iVar1) = 1;

      *(int *)(iVar2 + iVar1) = 0;

    }

    else {

      iVar1 = 0x0224;

      *(int *)(0x06078900 + iVar1) = 0;

      *(int *)(iVar2 + iVar1) = 1;

    }

  }

  return;

}
