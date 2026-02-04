void FUN_06036cb0()
{

  char cVar1;

  char *in_r0;

  int *in_r1;

  int *puVar2;

  int *puVar3;

  int uVar4;

  int uVar5;

  uVar4 = *in_r1;

  puVar2 = in_r1 + 1;

  do {

    uVar5 = *puVar2;

    puVar3 = puVar2 + 1;

    if ((((char)uVar4 == '\0' || (char)((unsigned int)uVar4 >> 8) == '\0') ||

        (char)((unsigned int)uVar4 >> 0x10) == '\0') || (char)((unsigned int)uVar4 >> 0x18) == '\0') {

LAB_06036ce8:

      cVar1 = *(char *)(puVar3 + -2);

      *in_r0 = cVar1;

      if (cVar1 != '\0') {

        cVar1 = *(char *)((int)puVar3 + -7);

        in_r0[1] = cVar1;

        if (cVar1 != '\0') {

          cVar1 = *(char *)((int)puVar3 + -6);

          in_r0[2] = cVar1;

          if (cVar1 != '\0') {

            in_r0[3] = *(char *)((int)puVar3 + -5);

          }

        }

      }

      return;

    }

    *(int *)in_r0 = uVar4;

    uVar4 = *puVar3;

    puVar3 = puVar2 + 2;

    if ((((char)uVar5 == '\0' || (char)((unsigned int)uVar5 >> 8) == '\0') ||

        (char)((unsigned int)uVar5 >> 0x10) == '\0') || (char)((unsigned int)uVar5 >> 0x18) == '\0') {

      in_r0 = in_r0 + 4;

      goto LAB_06036ce8;

    }

    *(int *)(in_r0 + 4) = uVar5;

    uVar5 = *puVar3;

    puVar3 = puVar2 + 3;

    if ((((char)uVar4 == '\0' || (char)((unsigned int)uVar4 >> 8) == '\0') ||

        (char)((unsigned int)uVar4 >> 0x10) == '\0') || (char)((unsigned int)uVar4 >> 0x18) == '\0') {

      in_r0 = in_r0 + 8;

      goto LAB_06036ce8;

    }

    *(int *)(in_r0 + 8) = uVar4;

    uVar4 = *puVar3;

    puVar3 = puVar2 + 4;

    if ((((char)uVar5 == '\0' || (char)((unsigned int)uVar5 >> 8) == '\0') ||

        (char)((unsigned int)uVar5 >> 0x10) == '\0') || (char)((unsigned int)uVar5 >> 0x18) == '\0') {

      in_r0 = in_r0 + 0xc;

      goto LAB_06036ce8;

    }

    *(int *)(in_r0 + 0xc) = uVar5;

    in_r0 = in_r0 + 0x10;

    puVar2 = puVar3;

  } while( true );

}
