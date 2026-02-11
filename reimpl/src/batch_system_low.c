#include "game.h"

extern int DAT_0600239e;
extern int DAT_060024d6;
extern int DAT_06002554;
extern int DAT_06002556;
extern int DAT_060025c6;
extern int DAT_060026aa;
extern int DAT_060026ac;
extern int DAT_060026ae;
extern int DAT_060026b0;
extern int DAT_060026b2;
extern int DAT_06002db8;
extern int DAT_06003362;
extern int DAT_06003364;
extern int DAT_06003366;
extern int DAT_06003368;
extern int DAT_0600336c;
extern int DAT_0600336e;
extern int DAT_06003370;
extern int DAT_06003372;
extern int DAT_06003374;
extern int DAT_06003376;
extern int DAT_06003406;
extern int DAT_06003408;
extern int DAT_0600340a;
extern int DAT_0600340c;
extern int DAT_06003498;
extern int DAT_0600361e;
extern int DAT_06003620;
extern int DAT_06003622;
extern int DAT_06003624;
extern int DAT_06003626;
extern int DAT_06003628;
extern int DAT_0600362a;
extern int DAT_0600362c;
extern int DAT_0600362e;
extern int DAT_06003630;
extern int DAT_06003632;
extern int DAT_06003634;
extern int DAT_06003772;
extern int DAT_06003774;
extern int DAT_06003776;
extern int DAT_06003778;
extern int DAT_0600377a;
extern int DAT_0600377c;
extern int DAT_0600377e;
extern int DAT_06003780;
extern int DAT_06003782;
extern int DAT_06003784;
extern int DAT_06003786;
extern int DAT_06003788;
extern int DAT_0600378a;
extern int DAT_0600378c;
extern int DAT_0600378e;
extern int DAT_06003884;
extern int DAT_06003886;
extern int DAT_06003888;
extern int DAT_0600388a;
extern int DAT_0600388c;
extern int DAT_0600388e;
extern int DAT_06003adc;
extern int DAT_06003ade;
extern int DAT_06003ae0;
extern int DAT_06003ae2;
extern int DAT_06003c16;
extern int DAT_06003c18;
extern int DAT_06003c1a;
extern int DAT_06003d36;
extern int DAT_06003d38;
extern int DAT_06003d3a;
extern int DAT_06003e66;
extern int DAT_06003f88;
extern int DAT_0600409e;
extern int DAT_060040a0;
extern int DAT_060040a2;
extern int DAT_060041c2;
extern int DAT_060041c4;
extern int DAT_060042e6;
extern int DAT_060042e8;
extern int DAT_06004404;
extern int DAT_0600451a;
extern int DAT_0600460c;
extern int DAT_0600460e;
extern int DAT_06004610;
extern int DAT_06004612;
extern int FUN_060023e6();
extern int FUN_0600245c();
extern int FUN_060024d8();
extern void FUN_0600270a();
extern int PTR_DAT_060023fc;
extern int PTR_DAT_06002558;
extern int PTR_DAT_060025cc;
extern int PTR_DAT_060025d0;
extern int PTR_DAT_060025d4;
extern int PTR_DAT_060025d8;
extern int PTR_DAT_060026b4;
extern int PTR_DAT_060026b8;
extern int PTR_DAT_060026bc;
extern int PTR_DAT_060026c0;
extern int PTR_DAT_0600349a;
extern int PTR_DAT_06003790;
extern int PTR_DAT_06003ae4;
extern int PTR_PTR_06002400;
extern int PTR_VDP1_TVMR_060025c8;

/* delay_loop_6 -- Busy-wait delay loop: 6 iterations.
 * Returns the loop counter (always 6). Used for hardware settling. */
int FUN_06002280(void)
{
    short i;
    for (i = 0; i < 6; i++) { }
    return (int)i;
}

void FUN_06002348()
{

  int local_20;

  for (local_20 = 0; local_20 < (unsigned int)(int)DAT_0600239e; local_20 = local_20 + 4) {

  }

  for (local_20 = 0; local_20 < (unsigned int)(int)PTR_DAT_060023fc; local_20 = local_20 + 1) {

  }

  return;

}

/* smpc_sync_wait -- Trigger SMPC command and busy-wait for completion.
 * Writes 1 to SMPC command register, polls until hardware clears it.
 * Returns the result register value. */
int FUN_060023e6(void)
{
    *(int *)PTR_PTR_06002400 = 1;
    do { } while (*(int *)PTR_PTR_06002400 == 1);
    return *(int *)PTR_PTR_06002400;
}

void FUN_06002404(param_1, param_2, param_3)
    short *param_1;
    short *param_2;
    int param_3;
{

  int local_c;

  short *puStack_8;

  short *puStack_4;

  

  local_c = param_3;

  puStack_8 = param_2;

  puStack_4 = param_1;

  do {

    *puStack_8 = *puStack_4;

    puStack_8 = puStack_8 + 1;

    puStack_4 = puStack_4 + 1;

    local_c = local_c + -1;

  } while (local_c != 0);

  return;

}

int FUN_0600245c(param_1, param_2, param_3)
    short *param_1;
    int param_2;
    short param_3;
{

  int iStack_8;

  short *psStack_4;

  

  iStack_8 = param_2;

  psStack_4 = param_1;

  do {

    *psStack_4 = param_3;

    iStack_8 = iStack_8 + -1;

    psStack_4 = psStack_4 + 1;

  } while (iStack_8 != 0);

  return (int)param_3;

}

int FUN_06002486(param_1, param_2, param_3, param_4)
    short *param_1;
    short param_2;
    int param_3;
    int param_4;
{

  int iVar1;

  short *local_18;

  int iStack_14;

  int iStack_10;

  short local_6;

  short *psStack_4;

  iStack_10 = param_4;

  local_6 = param_2;

  psStack_4 = param_1;

  do {

    local_18 = psStack_4;

    iStack_14 = param_3;

    do {

      *local_18 = local_6;

      iVar1 = (int)local_6;

      local_6 = (short)(iVar1 + 1);

      local_18 = local_18 + 1;

      iStack_14 = iStack_14 + -1;

    } while (iStack_14 != 0);

    psStack_4 = (short *)((int)psStack_4 + (int)DAT_060024d6);

    iStack_10 = iStack_10 + -1;

  } while (iStack_10 != 0);

  return iVar1 + 1;

}

int FUN_060024d8(param_1)
    short param_1;
{

  int iVar1;

  

  iVar1 = *(int *)PTR_DAT_06002558 + (int)DAT_06002554;

  *(short *)(iVar1 + 0x14) = param_1;

  *(short *)(iVar1 + 0x16) = param_1;

  *(short *)(iVar1 + 0x18) = param_1;

  return (int)param_1;

}

int FUN_06002510(param_1)
    short param_1;
{

  int uVar1;

  short local_8;

  for (local_8 = DAT_06002554; (int)(unsigned int)local_8 < (int)DAT_06002556; local_8 = local_8 + param_1)

  {

    FUN_060024d8((int)(short)local_8);

    FUN_060023e6();

  }

  FUN_060024d8((int)DAT_06002556);

  uVar1 = FUN_060023e6();

  return uVar1;

}

void FUN_0600255c()
{

  unsigned int uStack_8;

  short *puStack_4;

  

  puStack_4 = (short *)PTR_VDP1_TVMR_060025c8;

  for (uStack_8 = 0; uStack_8 < 6; uStack_8 = uStack_8 + 1) {

    *puStack_4 = 0;

    puStack_4 = puStack_4 + 1;

  }

  *(short *)PTR_DAT_060025cc = (short)PTR_DAT_060025d0;

  return;

}

int FUN_06002594()
{

  short sVar1;

  int iVar2;

  short *local_30;

  short *puStack_2c;

  unsigned int uStack_8;

  FUN_0600245c(*(int *)PTR_DAT_060025d4,(int)DAT_060025c6,0);

  iVar2 = *(int *)PTR_DAT_060025d4;

  *(short *)(iVar2 + 0x20) = 1;

  puStack_2c = (short *)PTR_DAT_060025d8;

  local_30 = (short *)(iVar2 + 0x10);

  for (uStack_8 = 0; uStack_8 < 8; uStack_8 = uStack_8 + 1) {

    *local_30 = *puStack_2c;

    local_30 = local_30 + 1;

    puStack_2c = puStack_2c + 1;

  }

  iVar2 = *(int *)PTR_DAT_060026b4;

  *(short *)(iVar2 + 0x30) = (short)PTR_DAT_060026b8;

  *(short *)(iVar2 + 0x40) = DAT_060026aa;

  *(short *)(iVar2 + 0x42) = DAT_060026aa;

  iVar2 = *(int *)PTR_DAT_060026b4;

  *(char **)(iVar2 + 0x78) = PTR_DAT_060026bc;

  *(char **)(iVar2 + 0x7c) = PTR_DAT_060026bc;

  *(char **)(iVar2 + 0x88) = PTR_DAT_060026bc;

  *(char **)(iVar2 + 0x8c) = PTR_DAT_060026bc;

  *(int *)(iVar2 + 0xac) = (int)DAT_060026ac;

  *(short *)PTR_DAT_060026c0 = 0;

  *(short *)(*(int *)PTR_DAT_060026b4 + (int)DAT_060026ae) = 0x20;

  *(short *)(*(int *)PTR_DAT_060026b4 + (int)DAT_060026b0 + 8) = 7;

  iVar2 = *(int *)PTR_DAT_060026b4 + (int)DAT_060026b2;

  *(short *)(iVar2 + 0x10) = 1;

  sVar1 = DAT_060026b2;

  *(short *)(iVar2 + 0x18) = DAT_060026b2;

  *(short *)(iVar2 + 0x16) = sVar1;

  *(short *)(iVar2 + 0x14) = sVar1;

  return 1;

}

void FUN_060026dc(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  do {

    FUN_0600270a();

    FUN_0600270a();

    param_3 = param_3 + -1;

  } while (param_3 != 0);

  return;

}

void FUN_0600270a(param_1, param_2)
    unsigned char param_1;
    int param_2;
{

  unsigned int uVar1;

  int in_r0 = 0;

  unsigned char in_r1;

  int in_r2 = 0;

  int iVar2;

  unsigned int unaff_r8 = 0;

  unsigned char *unaff_r9;

  if (param_2 < 1) {

    if ((((in_r0 != 0xc) && (in_r0 != 0xe)) && (in_r0 != 0xd)) && (in_r0 != 0xf)) {

      if ((unaff_r8 & 1) != 1) {

        return;

      }

      *unaff_r9 = in_r1 | (unsigned char)in_r0;

      return;

    }

  }

  else if (param_2 == 1) {

    iVar2 = (in_r2 << 4) + in_r0 + 2;

    do {

      uVar1 = unaff_r8 & 1;

      unaff_r8 = unaff_r8 >> 1;

      if (uVar1 == 1) {

        in_r1 = in_r1 | param_1;

        *unaff_r9 = in_r1;

        unaff_r9 = unaff_r9 + 1;

      }

      else {

        unaff_r8 = unaff_r8 + 1;

        in_r1 = param_1 << 4;

      }

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}

/* warm_reboot -- Call BIOS reset vector, then re-enter initial_program.
 * 0x06002db8 points to the BIOS warm-start handler. */
void FUN_06002d88(void)
{
    (*(int(*)())(*(int *)0x06002db8))();
    initial_program(0, 0, 0, 0);
}

void FUN_060032d4()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  puVar3 = (int *)0x0000F000;

  puVar2 = (char *)0x060283E0;

  puVar1 = (int *)0x06059ECE;

  (*(int(*)())0x060283E0)(8,0,0x0000F000,0x06059ECE);

  (*(int(*)())puVar2)(8,0xd00,puVar3,puVar1);

  (*(int(*)())puVar2)(8,0xd80,puVar3,puVar1);

  return;

}

/* vdp_sprite_batch_setup -- Configure 3 VDP1 sprite command entries.
 * Reads src/size/offset from sprite descriptor table at 0x06063750,
 * calls VDP1 command builder (FUN_06028400) for each sprite slot. */
void FUN_0600330a(void)
{
    register int vdp_cmd_build asm("r3") = 0x06028400;
    register int sprite_table asm("r2") = 0x06063750;
    int *desc;

    desc = (int *)(sprite_table + DAT_06003366);
    (*(int(*)())vdp_cmd_build)(0xC, *desc, 0xBC8, desc[1] + (int)DAT_06003368);

    desc = (int *)(sprite_table + DAT_0600336c);
    (*(int(*)())vdp_cmd_build)(0xC, *desc, (int)DAT_06003370, desc[1] + (int)DAT_0600336e);

    desc = (int *)(sprite_table + DAT_06003372);
    (*(void(*)())vdp_cmd_build)(0xC, *desc, (int)DAT_06003376, desc[1] + (int)DAT_06003374);
}

void FUN_0600338c(param_1, param_2)
    unsigned int param_1;
    int param_2;
{

  if ((param_1 & 4) == 0) {

    (*(int(*)())0x060284AE)(0xc,((param_2 << 6) + 0xb) << 1,0x60,0x0605ACDD);

    return;

  }

  if ((*(unsigned short *)0x06063DA0 & DAT_06003406) == 0) {

    (*(int(*)())0x06028400)(0xc,*(int *)0x06063AD0,((param_2 << 6) + 0xb) << 1,

               *(int *)(0x06063AD0 + 4) + (int)DAT_06003408);

    return;

  }

  return;

}

void FUN_060033e6()
{

  if ((FRAME_COUNTER & 4) != 0) {

    (*(int(*)())0x060284AE)(8,(int)DAT_0600340c,0x90,0x06044638);

    return;

  }

  (*(int(*)())0x060284AE)(8,(int)DAT_0600340c,0x90,0x0605ACF0);

  return;

}

void FUN_06003430()
{

  if (*(int *)0x06083255 == '\0') {

    (*(int(*)())0x06028400)(4,*(int *)0x06063798,0x900,

               *(int *)(0x06063798 + 4));

    return;

  }

  (*(int(*)())0x06028400)(4,*(int *)0x06063790,0x490,((int *)0x06063790)[1]);

  return;

}

void vdp2_mega_init()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  puVar3 = (int *)0x06027630;

  puVar2 = (char *)0x0602761E;

  puVar1 = (int *)0x25E20000;

  (*(int(*)())0x0602761E)(0x25F00800,0x060481AC,0x240);

  (*(int(*)())puVar3)(0x25E00000,0x002CF108,(int)DAT_06003620);

  iVar5 = 8;

  do {

    iVar5 = iVar5 + -2;

    *(int *)puVar1 = 0;

    puVar4 = (char *)0x002A0000;

  } while (iVar5 != 0);

  (*(int(*)())puVar3)(0x25E4363C,0x00031498 + (int)0x002A0000,(int)DAT_06003622);

  (*(int(*)())puVar3)(0x25E497E4,0x00037640 + (int)puVar4,(int)DAT_06003624);

  (*(int(*)())puVar3)(0x25E4EFEC,0x0003CE44 + (int)puVar4,0x00008094);

  (*(int(*)())puVar3)(0x25E40000,0x00044ED8 + (int)puVar4,0x7f0);

  (*(int(*)())puVar3)(0x25E407F0,0x000456C8 + (int)puVar4,(int)DAT_06003628);

  (*(int(*)())puVar3)(0x25E4108C,0x00045F64 + (int)puVar4,0x998);

  (*(int(*)())puVar3)(0x25E41A24,0x000468FC + (int)puVar4,(int)DAT_0600362c);

  (*(int(*)())puVar3)(0x25E42300,0x000471D8 + (int)puVar4,0x978);

  (*(int(*)())puVar3)(0x25E42C78,0x00047B50 + (int)puVar4,(int)DAT_06003630);

  (*(int(*)())puVar3)(0x25E61CEC,0x0001F370 + (int)puVar4,0x48e8);

  (*(int(*)())puVar3)(0x25E665D4,0x00023C58 + (int)puVar4,0x43f8);

  (*(int(*)())puVar3)(0x25E6A9CC,0x00028050 + (int)puVar4,0x4ff8);

  iVar5 = (int)DAT_06003774;

  (*(int(*)())puVar3)(0x25E60000,0x0002D41C + (int)puVar4,iVar5);

  (*(int(*)())puVar3)(0x25E609A4,0x0002DDC0 + (int)puVar4,iVar5);

  (*(int(*)())puVar3)(0x25E61348,0x0002E764 + (int)puVar4,iVar5);

  (*(int(*)())puVar3)(0x25E6F9C4,puVar4 + DAT_06003778,(int)DAT_06003776);

  (*(int(*)())puVar3)(0x25E70E40,puVar4 + DAT_0600377c,(int)DAT_0600377a);

  (*(int(*)())puVar3)(0x25E72194,0x0000EAB0 + (int)puVar4,(int)DAT_0600377e);

  (*(int(*)())puVar3)(0x25E73B98,0x00017114 + (int)puVar4,0x5c0);

  (*(int(*)())puVar3)(0x25E74158,0x000176D0 + (int)puVar4,iVar5);

  (*(int(*)())puVar3)(0x25E74AFC,0x00018074 + (int)puVar4,(int)DAT_06003782);

  (*(int(*)())puVar3)(0x25E75730,0x00018B10 + (int)puVar4,(int)DAT_06003784);

  (*(int(*)())puVar2)(0x25E759EC,0x00008F84 + (int)puVar4,0x3f0);

  (*(int(*)())puVar2)(0x25E75DDC,0x00009374 + (int)puVar4,0x3f0);

  (*(int(*)())puVar3)(0x25E76174,0x00048514 + (int)puVar4,0x88);

  (*(int(*)())puVar3)(0x25E761FC,0x0004859C + (int)puVar4,0xd00);

  (*(int(*)())puVar3)(0x25E76EFC,0x0004929C + (int)puVar4,(int)DAT_0600378c);

  (*(int(*)())puVar3)(0x25E77B18,0x00049EB8 + (int)puVar4,(int)DAT_0600378e);

  iVar5 = (int)PTR_DAT_06003790;

  (*(int(*)())puVar2)(0x060EE300,0x0000AA54 + (int)puVar4,iVar5);

  (*(int(*)())puVar2)(0x060EE7D4,0x0000AF28 + (int)puVar4,iVar5);

  (*(int(*)())puVar2)(0x060EECA8,0x0000B3FC + (int)puVar4,iVar5);

  (*(int(*)())puVar2)(0x060EF17C,0x0000B8D0 + (int)puVar4,iVar5);

  (*(int(*)())puVar2)(0x060EF650,0x0000BDA4 + (int)puVar4,iVar5);

  (*(int(*)())puVar2)(0x060EFB24,0x0002D048 + (int)puVar4,(int)DAT_06003884);

  (*(int(*)())puVar3)(0x25E33AD8,0x00019BC4 + (int)puVar4,0x528);

  (*(int(*)())puVar3)(0x25E33764,0x0001A0EC + (int)puVar4,0x228);

  (*(int(*)())puVar3)(0x25E3398C,0x0004FEEC + (int)puVar4,(int)DAT_0600388a);

  (*(int(*)())puVar3)(0x25E7B168,puVar4 + DAT_0600388e,(int)DAT_0600388c);

  return;

}

void FUN_060038d4()
{
  register int func asm("r3") = 0x0602766C;

  (*(int(*)())func)(0x25F00000, 0x0604814C, 0x60);
  (*(int(*)())func)(0x25F00060, 0x0604848C, 0x40);
  (*(int(*)())func)(0x25F000A0, 0x060484CC, 0x20);
  (*(int(*)())func)(0x25F000E0, 0x060485AC, 0x20);
  (*(int(*)())func)(0x25F00100, 0x0604892C, 0x20);
  (*(int(*)())func)(0x25F00120, 0x060488EC, 0x20);
  (*(int(*)())func)(0x25F00140, 0x0604890C, 0x20);
  (*(int(*)())func)(0x25F00160, 0x0605CDBC, 0x20);
  (*(int(*)())func)(0x25F001A0, 0x060487EC, 0x20);
  (*(int(*)())func)(0x25F001C0, 0x060483EC, 0x40);
  (*(int(*)())func)(0x25F00600, 0x0604848C, 0x40);
  (*(int(*)())func)(0x25F00660, 0x0604888C, 0x60);
  (*(int(*)())func)(0x25F007A0, 0x060487EC, 0x20);
  (*(void(*)())func)(0x25F007C0, 0x060483EC, 0x40);
}

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

void FUN_060039f2()
{

  int *puVar1;

  int uVar2;

  if (*(int *)0x06083255 == '\0') {

    uVar2 = 0x60;

    puVar1 = (int *)(0x0605C97C + (*(int *)0x06078868 + 10) << 2);

  }

  else {

    puVar1 = (int *)(0x0605CA4C + (*(int *)0x0607EAB8 + 2) << 2);

    uVar2 = 0x20;

  }

  (*(int(*)())0x0602766C)(0x25F00400,*puVar1,uVar2);

  return;

}

int FUN_06003a3c()
{

  int uVar1;

  *(int *)0x06063D94 = 0;

  *(char **)0x06063D90 = 0x060F0000;

  *(int *)0x06059F10 = 0;

  *(int *)0x06059F18 = 0x80;

  *(int *)0x06059F1C = 1;

  (*(int(*)())0x06004F14)(0x06059EC8,8,0x002D0868,(int)DAT_06003ade);

  (*(int(*)())0x06004F14)(0x06059EC8,8,0x002D0108,0xa2);

  (*(int(*)())0x06004F14)(0x002BE5F0,4,0x060430CE,0x3f);

  (*(int(*)())0x06004F14)(0x06059EC8,8,0x002D11A4,0x61);

  (*(int(*)())0x06004F14)(0x002A86F8,0xc,0x002A0000,0x45);

  (*(int(*)())0x06004F14)(0x002AC382,4,0x002A7D64,0xb);

  (*(int(*)())0x06004F14)(0x002AC390,4,0);

  (*(int(*)())0x06004F14)(0x002AA0B0,0xc,0x002A3784,0x34);

  (*(int(*)())0x06004F14)(0x060EF650,9,0x002A6BCC,0xc9);

  (*(int(*)())0x06004F14)(0x060EE300,9,0x002A3910,0x2ea);

  (*(int(*)())0x06004F14)(0x060EE7D4,8,0);

  (*(int(*)())0x06004F14)(0x060EECA8,8,0);

  (*(int(*)())0x06004F14)(0x060EF17C,8,0);

  (*(int(*)())0x06004F14)(0x002B4D1C,0xc,0x002ADA4C,0x1bb);

  (*(int(*)())0x06004F14)(0x002B4D50,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4D84,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4DE4,0xc,0);

  (*(int(*)())0x06004F14)(0x002B510A,0xc,0);

  (*(int(*)())0x06004F14)(0x002B517A,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4DB8,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4EAC,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4FF8,0xc,0);

  (*(int(*)())0x06004F14)(0x002B5054,0xc,0);

  (*(int(*)())0x06004F14)(0x002B50B2,0xc,0);

  (*(int(*)())0x06004F14)(0x002B7082,4,0x002B43EC,0x14);

  (*(int(*)())0x06004F14)(0x002B709A,4,0);

  (*(int(*)())0x06004F14)(0x06059EC8,9,0x002B0910,0xdb);

  (*(int(*)())0x06004F14)(0x06059EC8,9,0x002B121C,(int)DAT_06003c1a);

  (*(int(*)())0x06004F14)(0x06059EC8,8,0x002B3550,0x19);

  (*(int(*)())0x06004F14)(0x06059EC8,9,0x002BECFC,(int)DAT_06003d36);

  (*(int(*)())0x06004F14)(0x002B625E,0xc,0x002B2300,0x16a);

  (*(int(*)())0x06004F14)(0x002B616E,0xc,0x002B04B4,0x57);

  (*(int(*)())0x06004F14)(0x002B61C2,0xc,0);

  (*(int(*)())0x06004F14)(0x002B6216,0xc,0);

  (*(int(*)())0x06004F14)(0x002B6C02,0xc,0x002B36B4,(int)DAT_06003d3a);

  (*(int(*)())0x06004F14)(0x002B6C92,0xc,0);

  (*(int(*)())0x06004F14)(0x002B6D22,0xc,0);

  (*(int(*)())0x06004F14)(0x002B6DB2,0xc,0);

  (*(int(*)())0x06004F14)(0x002B6E42,0xc,0);

  (*(int(*)())0x06004F14)(0x002B6ED2,0xc,0);

  (*(int(*)())0x06004F14)(0x002B6F62,0xc,0);

  (*(int(*)())0x06004F14)(0x002B6FF2,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE684,0xc,0x002B8EA8,0x52);

  (*(int(*)())0x06004F14)(0x002BE6E8,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE71C,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE780,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE7B4,0xc,0);

  (*(int(*)())0x06004F14)(0x002B49CC,0xc,0x002ACB58,0x220);

  (*(int(*)())0x06004F14)(0x002B4A80,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4AB4,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4AE8,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4B1C,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4B50,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4B84,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4BB8,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4BEC,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4C20,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4C54,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4C64,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4C70,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4CAC,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4CC8,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4CE4,0xc,0);

  (*(int(*)())0x06004F14)(0x002B4D00,0xc,0);

  (*(int(*)())0x06004F14)(0x06059EC8,8,0);

  (*(int(*)())0x0600508A)(0x002A8964,0xa00,4);

  (*(int(*)())0x0600508A)(0x002A8AB8,0xa00,4);

  (*(int(*)())0x0600508A)(0x002A8C74,0xa00,4);

  (*(int(*)())0x0600508A)(0x002A8DC8,0xa00,4);

  (*(int(*)())0x06004F14)(0x002B4918,0xd,0x002AC63C,0x49);

  (*(int(*)())0x06004F14)(0x002B7082,5,0x002B43EC,0x14);

  (*(int(*)())0x06004F14)(0x002B709A,4,0);

  (*(int(*)())0x06004F14)(0x002BE7DC,0xc,0x002B9194,0x10);

  (*(int(*)())0x06004F14)(0x002BE7EC,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE7FC,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE80C,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE80C,0xc,0);

  (*(int(*)())0x06004F14)(0x06059EC8,0,0);

  (*(int(*)())0x06004F14)(0x002BE672,4,0x002B8DC8,7);

  (*(int(*)())0x06004F14)(0x002BE81C,0xc,0x002B9244,0x26);

  (*(int(*)())0x06004F14)(0x002BE834,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE84C,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE864,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE87C,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE888,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE894,4,0x002B943C,0x1b);

  (*(int(*)())0x06004F14)(0x002BE8B4,4,0);

  (*(int(*)())0x06004F14)(0x002BE8D2,0xc,0x002B979C,0x17);

  (*(int(*)())0x0600508A)(0x002B51EA,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002B5B8E,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002B5F02,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002BDB00,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002BDBC4,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002BDC04,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002BDC50,(int)DAT_060040a0,4);

  (*(int(*)())0x0600508A)(0x002BE098,(int)DAT_060040a2,4);

  (*(int(*)())0x0600508A)(0x002BE10C,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE180,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE1F4,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE268,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE2DC,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE350,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE3C4,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE438,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE4AC,(int)DAT_060041c2,4);

  (*(int(*)())0x0600508A)(0x002BE520,(int)DAT_060041c4,4);

  (*(int(*)())0x0600508A)(0x002BE54C,(int)DAT_060041c4,4);

  (*(int(*)())0x0600508A)(0x002BE588,(int)DAT_060041c4,4);

  (*(int(*)())0x0600508A)(0x002BE5C4,(int)DAT_060041c4,4);

  (*(int(*)())0x06004F14)(0x002AC278,0xc,0x002A7643,0x77);

  (*(int(*)())0x06004F14)(0x002AC2EA,0xc,0);

  (*(int(*)())0x06004F14)(0x002AC2A6,0xc,0);

  (*(int(*)())0x06004F14)(0x002AC326,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE90E,0xc,0x002B98F0,0x3c);

  (*(int(*)())0x06004F14)(0x002BE944,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE97A,0xc,0);

  (*(int(*)())0x06004F14)(0x002BE9B0,0xc,0);

  (*(int(*)())0x0600508A)(0x002ED748,0xa00,4);

  (*(int(*)())0x0600508A)(0x002EE0EC,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE1B0,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE2B4,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE3B8,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE454,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE4F0,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE510,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE53C,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE56C,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE594,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE5A8,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE5C4,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE5D8,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE600,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE620,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE648,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE72C,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE738,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE744,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE770,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE79C,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE7C8,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE7F4,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE820,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE84C,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE878,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE8A4,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE8D0,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE8FC,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE928,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE954,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE980,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE9AC,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE9C8,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE9DE,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EE9F4,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEA10,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEA2C,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEA3C,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEA48,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEA6A,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEA86,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEAB2,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEAC2,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEAD6,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEAFE,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEB0E,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEB22,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEB4A,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEB60,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EEB76,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002EF51A,0xbb8,4);

  (*(int(*)())0x0600508A)(0x002BE9E6,0xbb8,4);

  (*(int(*)())0x06004F14)(0x060438CE,9,0x002BCF4C,0xa2);

  (*(int(*)())0x06004F14)(0x06044272,9,0x002BA314,0x1c8);

  (*(int(*)())0x0600508A)(0x002BEB8E,(int)DAT_06004610,4);

  (*(int(*)())0x0600508A)(0x002BEC32,(int)DAT_06004610,4);

  (*(int(*)())0x0600508A)(0x002BECEA,(int)DAT_06004610,4);

  (*(int(*)())0x06004F14)(0x002B70CA,0xc,0x002B47AC,0x1f);

  (*(int(*)())0x06004F14)(0x002B70B2,5,0x002B466C,10);

  (*(int(*)())0x06004F14)(0x0605E148,0,0x0605E0E8,3);

  (*(int(*)())0x06004F14)(0x0605E150,0,0);

  (*(int(*)())0x06004F14)(0x002EFEBE,4,0x002ED508,0x12);

  (*(int(*)())0x0600508A)(0x002AC3A0,(int)DAT_06004612,4);

  (*(int(*)())0x0600508A)(0x002AC4BC,(int)DAT_06004612,4);

  uVar1 = (*(int(*)())0x06004F14)(0x06059DF8,0,0x06059E08,6);

  return uVar1;

}
