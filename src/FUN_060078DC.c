extern int DAT_060079ce;

extern int PTR_DAT_060079d0;

extern int PTR_DAT_060079d0;

extern void FUN_06007bcc();

void FUN_060078dc()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  puVar4 = 0x060620D0;

  puVar3 = 0x060620D4;

  puVar2 = 0x0605A008;

  puVar1 = 0x0606A4F8;

  uVar5 = (unsigned int)DAT_060079ce;

  *(unsigned int *)0x060620D4 = *(int *)0x060620D4 - uVar5;

  if (*(unsigned int *)puVar4 < uVar5) {

    (*0x06027630)

              (0x0608AC20 + ((*(unsigned int *)puVar4 & 0xffff) * 0x18 & 0xffff),0x0608E460,

               *(int *)puVar3 * 0x18);

    (*0x0602761E)

              (puVar1 + *(int *)puVar4 * 2,puVar1 + PTR_DAT_060079d0,*(int *)puVar3 << 1);

  }

  *(int *)puVar4 = *(int *)puVar4 + *(int *)puVar3;

  *(unsigned int *)puVar3 = uVar5;

  (*0x0602C494)(*(int *)puVar4,puVar1);

  puVar1 = 0x06063F5C;

  (*0x0602766C)

            (*(int *)0x06063F5C,0x0605A018 + *(short *)0x0605A016 * 0x20,

             0x20);

  *(char **)0x060785FC = 0x0606BDFC;

  *(int *)puVar2 = *(int *)puVar2 + 1;

  FUN_06007bcc();

  *(int *)0x0605A00C = 1;

  (*0x060394C2)();

  (*0x0602766C)(*(int *)puVar1 + 0x20,0x0606BDFC,(*(int *)puVar2 + -1) * 0x20);

  *(short *)(*(int *)puVar2 * 0x20 + *(int *)puVar1) = (short)0x00008000;

  puVar1 = 0x0605B6D8;

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | (unsigned int)0x20000000 | 4;

  if (*(int *)0x0607EAE0 == 0) {

    *(unsigned int *)puVar1 = *(unsigned int *)puVar1 | 0x08000000;

  }

  *(int *)0x0605A00C = 0;

  (*0x06026CE0)();

  *(int *)puVar4 = 0;

  *(int *)puVar2 = 0;

  puVar1 = 0x06059F44;

  *(int *)0x0606BDF8 = *(int *)0x06059F44;

  *(int *)puVar1 = 0;

  return;

}
