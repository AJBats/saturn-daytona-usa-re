#include "game.h"

extern int DAT_0602014a;
extern int DAT_0602014c;
extern int DAT_060203be;
extern int DAT_060204a8;
extern int DAT_06020db2;
extern int DAT_06020f2e;
extern int DAT_06020f30;
extern int DAT_06020fc6;
extern int DAT_06020fc8;
extern int DAT_06020fca;
extern int DAT_06021098;
extern int DAT_0602109a;
extern int DAT_0602109c;
extern int DAT_0602109e;
extern int DAT_060212d4;
extern int DAT_060212d6;
extern int DAT_060212d8;
extern int DAT_060212da;
extern int DAT_06021414;
extern int DAT_06021416;
extern int DAT_06021418;
extern int DAT_0602141a;
extern int DAT_06021520;
extern int DAT_06021522;
extern int DAT_06021524;
extern int DAT_06021526;
extern int DAT_060218de;
extern int DAT_060218e0;
extern int DAT_060218e2;
extern int DAT_06021c2e;
extern int DAT_06021c32;
extern int DAT_06021e98;
extern int DAT_06021e9a;
extern int DAT_06021fe0;
extern int DAT_06022114;
extern int DAT_06022116;
extern int DAT_06022118;
extern int object_destruction(char, unsigned int, unsigned int, int);
extern int FUN_06020946();
extern int FUN_06020dd0();
extern int PTR_DAT_060211d8;
extern int PTR_DAT_060212dc;
extern int PTR_DAT_06021528;
extern short PTR_DAT_06020b48;

/* vdp2_render_init -- Initialize VDP2 rendering: load color tables, set up DMA,
 * configure scroll plane, clear SCU interrupt masks, init text rendering state.
 * Copies VDP2 color RAM (0x25F006C0, 0x25F00060), loads 4 tile pattern sets
 * via DMA (0x0600511E), configures sprite layer, clears render counters. */
void FUN_060200a4(void)
{
    (*(int(*)())0x0602761E)(0x25F006C0, 0x0604896C, 0x20);  /* color RAM bank 1 */
    (*(int(*)())0x0602761E)(0x25F00060, 0x0604BC14, 0x20);  /* color RAM bank 2 */

    (*(int(*)())0x0600511E)(0x25E33AD8, 0x00017700, 0, 8);  /* tile pattern 1 */
    (*(int(*)())0x0600511E)(0x25E33764, 0x00018B40, 0, 8);  /* tile pattern 2 */
    (*(int(*)())0x0600511E)(0x0605E164, 0x0001D2A0, 0, 8);  /* tile pattern 3 */
    (*(int(*)())0x0600511E)(0x25E3398C, 0x00018F20, 0, 8);  /* tile pattern 4 */

    (*(int(*)())0x06028400)(0xc, *(int *)0x06063CA0, (int)DAT_0602014c,
               *(int *)(0x06063CA0 + 4) + (int)DAT_0602014a, 0x06063CA0);

    (*(int(*)())0x06014884)(0x20, 0);   /* clear SCU interrupt mask 0x20 */
    (*(int(*)())0x06014884)(8, 0);      /* clear SCU interrupt mask 0x08 */

    FUN_06020dd0();   /* extended render init */

    /* Clear text rendering state */
    *(short *)0x0608780A = 0;
    *(short *)0x06087808 = 0;
    *(int *)0x06087814 = 0;
    *(short *)0x06087806 = 0;

    (*(int(*)())0x0601D5F4)(0, 0xAB1128FF);   /* palette init */

    *(int *)0x06087826 = 0;
    *(int *)0x06087824 = 0;
    *(int *)0x06087825 = 0xf;   /* default text attribute */
}

/* object_creation -- Create a multi-part text/sprite object from template table.
 * param_1 = object index (low byte). Looks up template chain at 0x0605F458.
 * Each template entry has: [char_count, row, font_bank]. First part uses
 * font pointer from 0x0605F478, subsequent parts use font table at 0x0604BD72.
 * Chain terminates when sentinel value DAT_060203be is encountered. */
int object_creation(unsigned int param_1)
{
    unsigned short sentinel = DAT_060203be;
    unsigned char *tmpl = *(unsigned char **)(0x0605F458 + (param_1 & 0xff) << 2);

    int result = object_destruction(
        **(short **)(0x0605F478 + (unsigned int)tmpl[2] * 4),
        *tmpl, tmpl[1],
        *(short **)(0x0605F478 + (unsigned int)tmpl[2] * 4) + 2);

    unsigned char *next;
    while (next = tmpl + 3, *next != sentinel) {
        result = object_destruction(
            *(short *)(0x0604BD72 + (unsigned int)tmpl[5] * 0x2a),
            *next, tmpl[4],
            (short *)((int)(0x0604BD72 + (unsigned int)tmpl[5] * 0x2a) + 4));
        tmpl = next;
    }

    return result;
}

/* object_destruction -- Render a text string to VDP2 scroll plane.
 * param_1 = character count, param_2 = X column, param_3 = Y row,
 * param_4 = character data pointer (16-bit per char).
 * For each character: space (0x20) maps to tile 0/0, others map to
 * (ascii - 0x40) * 2 tile pair. Writes via VDP2 command (0x06028400)
 * at cell position computed from (X + Y*64) * 2. */
int object_destruction(char param_1, unsigned int param_2, unsigned int param_3, int param_4)
{
    char *cmd_buf = (char *)0x0605F44E;
    short *tile_a = (short *)(0x0605F44E + 4);
    short *tile_b = (short *)(0x0605F44E + 6);
    unsigned int idx = 0;

    if ('\0' < param_1) {
        do {
            unsigned short ch = *(unsigned short *)(param_4 + (idx & 0xff) << 1);
            if ((char)ch == ' ') {
                *tile_a = 0;
                *tile_b = 0;
            } else {
                short tile = ((ch & 0xff) - 0x40) << 1;
                *tile_a = tile;
                *tile_b = tile + 1;
            }
            (*(int(*)())0x06028400)(8, cmd_buf,
                ((param_2 & 0xffff) + (param_3 & 0xffff) << 6) << 1, 0x3c79);
            idx++;
            param_2++;
        } while ((int)(idx & 0xff) < (int)param_1);
    }
    return 0;
}

/* vdp2_scroll_clear -- Clear VDP2 scroll plane and set initial parameters.
 * Sets VDP2 scroll control register at 0x25F800A4 and name table address,
 * then zeros 256 entries (1024 bytes) of scroll data at 0x25E5F800. */
int FUN_06020b20(void)
{
    register int base asm("r2") = 0x25E5F800;  /* VDP2 scroll plane data */
    register int zero asm("r0") = 0;
    register int idx asm("r3");
    unsigned short i;

    *(int *)0x25F800A4 = 0x12F2FC00;  /* scroll control register */
    *(short *)0x25F8009A = PTR_DAT_06020b48;  /* name table address */

    for (i = 0; i < 0x100; i++) {
        idx = (unsigned short)i << 2;
        *(int *)(base + idx) = zero;
    }
    return idx;
}

/* vdp1_display_mode_dispatch -- Select VDP1 display mode based on 0x0608780C.
 * Calls CD sector read (0x06035228) twice, then dispatches:
 * Mode 1: 0xC060 display, batch DMA, render via 0x06038044
 * Mode 2: 0xC044 display, batch DMA, render via 0x06038044
 * Mode 3: extended render (FUN_06020946)
 * Mode 4: VDP render clear slot 4 (0x0602853E)
 * Clears mode register after dispatch. */
unsigned int FUN_06020c3c(void)
{
    register int func asm("r3") = 0x06035228;
    char auStack_24[16];
    char auStack_14[20];

    (*(int(*)())func)();   /* CD sector read 1 */
    (*(int(*)())func)();   /* CD sector read 2 */

    unsigned int mode = *(unsigned short *)0x0608780C;

    if (mode == 1) {
        *(short *)0x060A3DBA = (short)0xC060;
        *(short *)0x060A3DA8 = 0xf;
        VDP1_BATCH_FLAG = 1;
        mode = (*(int(*)())0x06038044)(auStack_14);
    } else if (mode == 2) {
        *(short *)0x060A3DBA = (short)0xC044;
        *(short *)0x060A3DA8 = 0xf;
        VDP1_BATCH_FLAG = 1;
        mode = (*(int(*)())0x06038044)(auStack_24);
    } else if (mode == 3) {
        mode = FUN_06020946();
    } else if (mode == 4) {
        mode = (*(int(*)())0x0602853E)(4);
    }

    *(short *)0x0608780C = 0;
    return mode;
}

void FUN_06020cf4()
{

  short uVar1;

  char *puVar2;

  char *puVar3;

  puVar2 = (char *)0x06087C6C;

  uVar1 = DAT_06020db2;

  *(short *)(0x06087C6C + 8) = DAT_06020db2;

  *(short *)(puVar2 + 10) = uVar1;

  *(short *)(puVar2 + 0xc) = uVar1;

  *(short *)(puVar2 + 0xe) = uVar1;

  *(short *)(puVar2 + 0x10) = uVar1;

  *(short *)(puVar2 + 0x12) = uVar1;

  *(short *)(puVar2 + 0x14) = uVar1;

  *(short *)(puVar2 + 0x16) = uVar1;

  *(short *)(puVar2 + 6) = 0x17;

  puVar2[4] = 0;

  puVar2[5] = 0x3a;

  puVar3 = (char *)0x060785FC;

  (*(int(*)())0x060280F8)(puVar2,*(int *)0x060785FC);

  VDP1_CMD_BASE_PTR = VDP1_CMD_BASE_PTR + 1;

  *(int *)puVar3 = *(int *)puVar3 + 0x20;

  return;

}

void FUN_06020d46()
{

  char *puVar1;

  unsigned int uVar2;

  int auStack_38 [10];

  puVar1 = (char *)0x0608782C;

  (*(int(*)())0x06035168)();

  uVar2 = 0;

  do {

    if (puVar1[(short)(((unsigned short)uVar2 & 0xff) * 0x44)] != '\0') {

      (*(int(*)())auStack_38[(unsigned char)puVar1[(short)(((unsigned short)uVar2 & 0xff) * 0x44)] - 1])(uVar2);

    }

    uVar2 = uVar2 + 1;

  } while ((uVar2 & 0xff) < 0x10);

  return;

}

int FUN_06020e74()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  unsigned char bVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  puVar4 = (char *)0x06089595;

  puVar3 = (char *)0x06087C84;

  puVar2 = (char *)0x06078663;

  puVar1 = (char *)0x06089594;

  if (*(int *)0x06089595 != '\0') {

    *(int *)0x06089594 = 10;

    *puVar4 = 0;

  }

  if (*puVar1 != '\0') {

    *puVar1 = *puVar1 + -1;

  }

  if ((*(int *)(CAR_PTR_TARGET + (int)DAT_06020f2e) != *(int *)0x06089598) &&

     (*(int *)0x06083255 == '\0')) {

    iVar9 = 0x900;

    uVar5 = *(unsigned int *)((int)DAT_06020f2e + CAR_PTR_TARGET) & 0xcc;

    if (uVar5 == 0) {

      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + 0x48),iVar9,

                 *(int *)(0x06063750 + 0x4c));

    }

    else if (uVar5 == 0x44) {

      if (*puVar2 == '\0') {

        iVar7 = 10;

      }

      else {

        iVar7 = 0xb;

      }

      if (*puVar2 == '\0') {

        iVar8 = 10;

      }

      else {

        iVar8 = 0xb;

      }

      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + (iVar8 << 3)),iVar9,

                 *(int *)(0x06063750 + (iVar7 << 3) + 4));

    }

    else if (uVar5 == 0x88) {

      if (*puVar2 == '\0') {

        iVar7 = 0xb;

      }

      else {

        iVar7 = 10;

      }

      if (*puVar2 == '\0') {

        iVar8 = 0xb;

      }

      else {

        iVar8 = 10;

      }

      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + (iVar8 << 3)),iVar9,

                 *(int *)(0x06063750 + (iVar7 << 3) + 4));

    }

    else if (uVar5 == (int)DAT_06020fc8) {

      (*(int(*)())0x06028400)(4,*(int *)(0x06063750 + 0x60),iVar9,

                 *(int *)(0x06063750 + 100));

    }

  }

  *(int *)0x06089598 = *(int *)(CAR_PTR_TARGET + (int)DAT_06020fca);

  if (*(int *)0x06063E20 != 1) {

    return *(int *)0x06063E20;

  }

  iVar10 = 0;

  iVar7 = 0;

  iVar9 = *(int *)(CAR_PTR_TARGET + 0x60) >> 0xe;

  iVar8 = *(int *)(0x0604D3E0 + (unsigned int)(unsigned char)(*puVar1 << 2));

  if (*puVar2 != '\0') {

    iVar9 = -iVar9;

  }

  if ((iVar9 < DAT_06021098) && (DAT_0602109a < iVar9)) {

    iVar9 = 0;

  }

  *(int *)(puVar3 + DAT_0602109c) = 0;

  bVar6 = 0;

  do {

    iVar10 = iVar10 + iVar9;

    iVar7 = iVar7 - iVar9;

    uVar5 = (unsigned int)bVar6;

    *(int *)(puVar3 + (((0x15 - (unsigned int)bVar6) << 2) + (int)DAT_0602109e)) = iVar10 + iVar8;

    bVar6 = bVar6 + 1;

    *(int *)(puVar3 + (uVar5 << 2) + (int)DAT_0602109e + 0x58) = iVar7 + iVar8;

  } while (bVar6 < 0x16);

  (*(int(*)())0x0603850C)(8);

  (*(int(*)())0x06038120)(0x06087C84);

  iVar9 = (*(int(*)())0x06038520)();

  return iVar9;

}

unsigned int FUN_06021178()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int uVar9;

  puVar1 = (char *)0x0608959C;

  iVar6 = *(int *)(CAR_PTR_CURRENT + 0x10);

  iVar8 = *(int *)(CAR_PTR_CURRENT + 0x18);

  if (((((int)0x00760000 < iVar6) && (iVar6 < (int)0x014B0000)) &&

      (iVar8 < (int)0x00D00000)) && (0xFF3B0000 < iVar8)) {

    if (((0x57 < *(int *)(CAR_PTR_CURRENT + (int)PTR_DAT_060211d8)) &&

        (*(int *)(CAR_PTR_CURRENT + (int)PTR_DAT_060211d8) < 0x7a)) &&

       ((*(unsigned short *)0x0608959C & 1) == 0)) {

      *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C | 1;

      *(unsigned short *)puVar1 = *(unsigned short *)puVar1 | 2;

    }

  }

  else if ((((iVar6 < 0xFE9A0000) && (iVar8 < 0xFDCD0000)) ||

           ((iVar6 < 0xFE950000 && (iVar8 < 0xFDD30000)))) ||

          ((iVar6 < 0xFE8F0000 && (iVar8 < 0xFDD80000)))) {

    if ((*(unsigned short *)0x0608959C & 1) == 0) {

      *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C | 1;

      *(unsigned short *)puVar1 = *(unsigned short *)puVar1 | 2;

    }

  }

  else if ((*(unsigned short *)0x0608959C & 1) != 0) {

    *(unsigned short *)0x0608959C = *(unsigned short *)0x0608959C & 0xfffe;

    *(unsigned short *)puVar1 = *(unsigned short *)puVar1 | 2;

  }

  puVar4 = (char *)0x0602766C;

  puVar3 = (char *)0x06059FFC;

  puVar2 = (char *)0x06063F5C;

  uVar5 = (unsigned int)(*(unsigned short *)puVar1 >> 1);

  if ((*(unsigned short *)puVar1 >> 1 & 1) != 0) {

    iVar6 = 0xc0;

    if ((*(unsigned short *)puVar1 & 1) == 0) {

      (*(int(*)())0x060039C8)();

      (*(int(*)())puVar4)(*(int *)((int)(int)puVar3 << 3) + *(int *)puVar2,0x0604D408,0x200);

      (*(int(*)())puVar4)(*(int *)((int)(int)puVar3 << 3) + *(int *)puVar2 + 0x3c0,0x0604D808,

                        (int)DAT_06021416);

      if (*(int *)0x06083255 == '\0') {

        (*(int(*)())puVar4)(*(int *)((int)(int)puVar3 << 3) + *(int *)puVar2 + 0x40,

                          *(int *)(0x0605D05C + *(int *)(0x06078868 << 2)),iVar6);

        uVar9 = *(int *)(0x0605D05C + (unsigned int)(unsigned char)*(int *)(0x0607ED91 << 2));

        iVar8 = 0x100;

        iVar7 = *(int *)((int)(int)puVar3 << 3) + *(int *)puVar2;

      }

      else {

        iVar6 = 0x20;

        uVar9 = *(int *)(0x0605D0AC + *(int *)(0x0607EAB8 << 2));

        iVar7 = ((unsigned int)(unsigned char)((int *)0x060448B5)[CAR_COUNT] +

                (unsigned int)*(unsigned short *)0x0607886C) << 5 + *(int *)((int)(int)puVar3 << 3);

        iVar8 = *(int *)puVar2;

      }

      uVar5 = (*(int(*)())puVar4)(iVar7 + iVar8,uVar9,iVar6);

    }

    else {

      (*(int(*)())0x060039F2)();

      (*(int(*)())puVar4)(*(int *)((int)(int)puVar3 << 3) + *(int *)puVar2,0x0604D608,0x200);

      (*(int(*)())puVar4)(*(int *)((int)(int)puVar3 << 3) + *(int *)puVar2 + 0x3c0,0x0604EFC8,

                        (int)DAT_060212d8);

      if (*(int *)0x06083255 == '\0') {

        (*(int(*)())puVar4)(*(int *)((int)(int)puVar3 << 3) + *(int *)puVar2 + 0x40,

                          *(int *)(0x0605D084 + *(int *)(0x06078868 << 2)),iVar6);

        uVar9 = *(int *)(0x0605D084 + (unsigned int)(unsigned char)*(int *)(0x0607ED91 << 2));

        iVar8 = 0x100;

        iVar7 = *(int *)((int)(int)puVar3 << 3) + *(int *)puVar2;

      }

      else {

        iVar6 = 0x20;

        uVar9 = *(int *)(0x0605D0B4 + *(int *)(0x0607EAB8 << 2));

        iVar7 = ((unsigned int)(unsigned char)((int *)0x060448B5)[CAR_COUNT] +

                (unsigned int)*(unsigned short *)0x0607886C) << 5 + *(int *)((int)(int)puVar3 << 3);

        iVar8 = *(int *)puVar2;

      }

      uVar5 = (*(int(*)())puVar4)(iVar7 + iVar8,uVar9,iVar6);

    }

    *(unsigned short *)puVar1 = *(unsigned short *)puVar1 & 0xfffd;

  }

  return uVar5;

}

void track_object_placement()
{

  short uVar1;

  short uVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  int **ppuVar11;

  unsigned int uVar12;

  short uVar14;

  int uVar13;

  int *puVar15;

  int *piVar16;

  int extraout_r3 = 0;

  int extraout_r3_00;

  int extraout_r3_01;

  int *puVar17;

  int extraout_r3_02;

  int extraout_r3_03;

  int extraout_r3_04;

  int extraout_r3_05;

  int *extraout_r3_06;

  int *extraout_r3_07;

  int *extraout_r3_08;

  int *extraout_r3_09;

  int *extraout_r3_10;

  int *extraout_r3_11;

  int *extraout_r3_12;

  unsigned int uVar18;

  short uVar19;

  unsigned int uVar20;

  int iVar21;

  unsigned int *puVar22;

  char *puVar23;

  int iVar24;

  int *piVar25;

  int *piVar26;

  int *piVar27;

  int *piVar28;

  int *piVar33;

  int *local_34;

  unsigned int *puStack_30;

  unsigned int uStack_2c;

  int *puStack_28;

  int *puStack_24;

  int *piVar29;

  int *piVar30;

  int *piVar31;

  int *piVar32;

  int *piVar34;

  int *piVar35;

  puVar10 = (char *)0x00200000;

  puVar9 = (char *)0x00200000;

  puVar8 = (char *)0x00200000;

  puVar7 = (char *)0x06089D98;

  puVar23 = (char *)0x060896B8;

  puVar6 = (char *)0x060895A0;

  puVar5 = (char *)0x06089744;

  puVar4 = (char *)0x0608962C;

  puVar3 = (char *)0x060897D0;

  uVar2 = DAT_06021522;

  uVar1 = DAT_06021520;

  iVar24 = 0x140;

  uVar18 = 0;

  if (CAR_COUNT == 0) {

    *(char **)0x06089D98 = 0x00200000 + (int)0x00037F08;

    *(int *)(puVar7 + 0x1c) = 0xc;

    *(char **)(puVar7 + 0x38) = puVar8 + (int)0x00037F98;

    *(int *)(puVar7 + 0x54) = 9;

    *(char **)(puVar7 + 0x70) = 0x00010000;

    *(int *)(puVar7 + DAT_06021526) = 10;

    uStack_2c = 0;

    puStack_28 = (int *)0x060507A4;

    local_34 = (int *)puVar3;

    puStack_24 = (int *)(puVar3 + PTR_DAT_06021528);

    do {

      puStack_30 = puStack_28;

      *local_34 = *puStack_28;

      local_34[1] = puStack_28[1];

      local_34[2] = -puStack_28[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      puVar15 = local_34;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)((int)puVar15 + 0x16) = uVar14;

      *(unsigned int *)(puVar23 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar4 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar5 + uStack_2c) = uVar18;

      *(unsigned int *)(puVar6 + uStack_2c) = uVar18;

      uStack_2c = uStack_2c + 4;

      puStack_28 = puStack_28 + 4;

      local_34 = local_34 + 6;

    } while (local_34 < puStack_24);

  }

  else if (CAR_COUNT == 1) {

    *(char **)(0x06089D98 + 4) = 0x00200000 + (int)0x00089364;

    *(int *)(puVar7 + 0x20) = 0x12;

    *(char **)(puVar7 + 0x3c) = puVar9 + (int)0x0008943C;

    *(int *)(puVar7 + 0x58) = 0xb;

    *(char **)(puVar7 + 0x74) = 0x00010000;

    *(char **)(puVar7 + 8) = puVar9 + (int)0x00089124;

    *(int *)(puVar7 + 0x24) = 0x1c;

    *(char **)(puVar7 + 0x40) = puVar9 + (int)0x00089274;

    *(int *)(puVar7 + 0x5c) = 10;

    *(char **)(puVar7 + 0x78) = 0x0000CCCC;

    *(char **)(puVar7 + 0xc) = puVar9 + (int)0x00089544;

    *(int *)(puVar7 + 0x28) = 0x34;

    *(char **)(puVar7 + 0x44) = puVar9 + (int)0x000897B4;

    *(int *)(puVar7 + 0x60) = 0x1c;

    *(char **)(puVar7 + 0x7c) = 0x0000F333;

    *(int *)(puVar7 + 0x8c) = 0xf;

    uVar20 = 0;

    do {

      puVar17 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puVar15 = (int *)(0x06050844 + (char)((char)uVar20 * '\f'));

      *puVar17 = *puVar15;

      puVar17[1] = puVar15[1];

      puVar17[2] = -puVar15[2];

      puVar17[3] = 0;

      puVar17[4] = 0;

      *(short *)(puVar17 + 5) = 0;

      *(short *)((int)puVar17 + 0x16) = 0;

      iVar21 = (uVar20 << 2);

      uVar20 = uVar20 + 1;

      *(int *)(puVar23 + iVar21) = 0;

      *(int *)(puVar4 + iVar21) = 0;

      *(int *)(puVar5 + iVar21) = 0;

      *(int *)(puVar6 + iVar21) = 1;

    } while (uVar20 < 4);

    uStack_2c = 0;

    for (; uVar20 < 0xc; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050874 + ((uStack_2c & 0xff) * 0x14 & 0xff));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3 + 0x14) = uVar14;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_00 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 2;

      uStack_2c = uStack_2c + 1;

    }

    uStack_2c = uVar18;

    for (; uVar20 < 0xf; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050914 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_01 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 3;

      uStack_2c = uStack_2c + 1;

    }

  }

  else {

    *(char **)0x06089D98 = 0x00200000 + (int)0x000BE1F8;

    *(int *)(puVar7 + 0x1c) = 0xc;

    *(char **)(puVar7 + 0x38) = puVar10 + (int)0x000BE288;

    *(int *)(puVar7 + 0x54) = 9;

    *(char **)(puVar7 + 0x70) = 0x00010000;

    *(char **)(puVar7 + 8) = puVar10 + (int)0x000BE360;

    *(int *)(puVar7 + 0x24) = 0x1c;

    *(char **)(puVar7 + 0x40) = puVar10 + (int)0x000BE4B0;

    *(int *)(puVar7 + 0x5c) = 10;

    *(char **)(puVar7 + 0x78) = 0x0000CCCC;

    *(char **)(puVar7 + 0x10) = puVar10 + (int)0x000BDBF8;

    *(int *)(puVar7 + 0x2c) = 0x20;

    *(char **)(puVar7 + 0x48) = puVar10 + (int)0x000BDD78;

    *(int *)(puVar7 + 100) = 0xe;

    *(char **)(puVar7 + DAT_060218de) = 0x0000F333;

    *(char **)(puVar7 + 0x14) = puVar10 + (int)0x000BDEC8;

    *(int *)(puVar7 + 0x30) = 0xe;

    *(char **)(puVar7 + 0x4c) = puVar10 + (int)0x000BDF70;

    *(int *)(puVar7 + 0x68) = 10;

    *(char **)(puVar7 + DAT_060218e0) = 0x0000CCCC;

    *(char **)(puVar7 + 0x18) = puVar10 + (int)0x000BE060;

    *(int *)(puVar7 + 0x34) = 0xe;

    *(char **)(puVar7 + 0x50) = puVar10 + (int)0x000BE108;

    *(int *)(puVar7 + 0x6c) = 10;

    iVar21 = 0x88;

    *(char **)(puVar7 + iVar21) = 0x0000CCCC;

    *(int *)(puVar7 + iVar21 + 4) = 0x23;

    uVar20 = 0;

    do {

      puVar17 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puVar15 = (int *)(0x06050AE4 + (char)((char)uVar20 * '\f'));

      *puVar17 = *puVar15;

      puVar17[1] = puVar15[1];

      puVar17[2] = -puVar15[2];

      puVar17[3] = 0;

      puVar17[4] = 0;

      *(short *)(puVar17 + 5) = 0;

      *(short *)((int)puVar17 + 0x16) = 0;

      iVar21 = (uVar20 << 2);

      uVar20 = uVar20 + 1;

      *(int *)(puVar23 + iVar21) = 0;

      *(int *)(puVar4 + iVar21) = 0;

      *(int *)(puVar5 + iVar21) = 0;

      *(int *)(puVar6 + iVar21) = 0;

    } while (uVar20 < 9);

    uStack_2c = 0;

    for (; uVar12 = uVar18, uVar20 < 0x15; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050974 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_02 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 2;

      uStack_2c = uStack_2c + 1;

    }

    for (; uStack_2c = uVar12, uVar12 = uVar18, uVar20 < 0x18; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050944 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_03 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 4;

      uVar12 = uStack_2c + 1;

    }

    for (; uStack_2c = uVar12, uVar20 < 0x1d; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050A34 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_04 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 5;

      uVar12 = uStack_2c + 1;

    }

    uStack_2c = uVar18;

    for (; uVar20 < 0x23; uVar20 = uVar20 + 1) {

      local_34 = (int *)(puVar3 + (short)((short)uVar20 * 0x18));

      puStack_30 = (unsigned int *)(0x06050A84 + (uStack_2c << 4));

      *local_34 = *puStack_30;

      local_34[1] = puStack_30[1];

      local_34[2] = -puStack_30[2];

      local_34[3] = uVar18;

      local_34[4] = uVar18;

      *(short *)(local_34 + 5) = (short)uVar18;

      uVar14 = (*(int(*)())0x06034FE0)();

      *(short *)(extraout_r3_05 + 0x16) = uVar14;

      iVar21 = (uVar20 << 2);

      *(unsigned int *)(puVar23 + iVar21) = uVar18;

      *(unsigned int *)(puVar4 + iVar21) = uVar18;

      *(unsigned int *)(puVar5 + iVar21) = uVar18;

      *(int *)(puVar6 + iVar21) = 6;

      uStack_2c = uStack_2c + 1;

    }

  }

  puVar23 = (char *)0x06089B18;

  *(unsigned int *)0x06089B18 = uVar18;

  *(short *)(puVar23 + 4) = DAT_06021c2e;

  *(short *)(puVar23 + 6) = 0x40008000;

  *(unsigned int *)(puVar23 + 8) = uVar18;

  uVar19 = (short)uVar18;

  *(short *)(puVar23 + 0xc) = uVar19;

  uVar14 = DAT_06021c32;

  *(short *)(puVar23 + 0xe) = DAT_06021c32;

  *(unsigned int *)(puVar23 + 0x10) = uVar18;

  *(short *)(puVar23 + 0x14) = uVar19;

  *(short *)(puVar23 + 0x16) = uVar14;

  puStack_30 = (unsigned int *)(puVar23 + 0x18);

  *(unsigned int *)(puVar23 + 0x18) = uVar18;

  *(short *)(puVar23 + 0x1c) = uVar19;

  *(short *)(puVar23 + 0x1e) = uVar14;

  uVar20 = 4;

  local_34 = (int *)0x06089B18;

  ppuVar11 = &local_34;

  do {

    piVar25 = (int *)ppuVar11;

    piVar25[1] = (uVar20 << 3) + *piVar25;

    piVar25[-9] = (int)(piVar25 + -9);

    (*(int(*)())0x06035BC8)();

    piVar25[-10] = 0x33333333;

    piVar25[-0xb] = 0x4054D333;

    piVar25[-0xc] = (int)(piVar25 + -7);

    (*(int(*)())0x060359E4)();

    piVar25[-0x13] = (int)(piVar25 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x16] = (int)(piVar25 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x17] = (int)(piVar25 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar25[-0x18] = 0x9999999A;

    piVar25[-0x19] = 0x40139999;

    piVar25[-0x1a] = (int)(piVar25 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar25[-0x1b] = (int)(piVar25 + -0x16);

    (*(int(*)())0x06035460)();

    piVar25[-0x1c] = 0;

    piVar25[-0x1d] = 0x40680000;

    piVar25[-0x1e] = (int)(piVar25 + -0x19);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    iVar21 = uVar20 + 1;

    *extraout_r3_06 = uVar13;

    *(short *)(piVar25[-0x1d] + 4) = uVar1;

    *(short *)(piVar25[-0x1d] + 6) = uVar2;

    piVar25[-0x1d] = (iVar21 << 3) + piVar25[-0x1e];

    piVar25[-0x27] = (int)(piVar25 + -0x27);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x28] = 0x33333333;

    piVar25[-0x29] = 0x4054D333;

    piVar25[-0x2a] = (int)(piVar25 + -0x25);

    (*(int(*)())0x060359E4)();

    piVar25[-0x31] = (int)(piVar25 + -0x31);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x34] = (int)(piVar25 + -0x34);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x35] = (int)(piVar25 + -0x30);

    (*(int(*)())0x060359E4)();

    piVar25[-0x36] = 0x9999999A;

    piVar25[-0x37] = 0x40139999;

    piVar25[-0x38] = (int)(piVar25 + -0x33);

    (*(int(*)())0x060359E4)();

    piVar25[-0x39] = (int)(piVar25 + -0x34);

    (*(int(*)())0x06035460)();

    piVar25[-0x3a] = 0;

    piVar25[-0x3b] = 0x40680000;

    piVar25[-0x3c] = (int)(piVar25 + -0x37);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    iVar21 = iVar21 + 1;

    *extraout_r3_07 = uVar13;

    *(short *)(piVar25[-0x3b] + 4) = uVar1;

    *(short *)(piVar25[-0x3b] + 6) = uVar2;

    piVar25[-0x3b] = (iVar21 << 3) + piVar25[-0x3c];

    piVar25[-0x45] = (int)(piVar25 + -0x45);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x46] = 0x33333333;

    piVar25[-0x47] = 0x4054D333;

    piVar25[-0x48] = (int)(piVar25 + -0x43);

    (*(int(*)())0x060359E4)();

    piVar25[-0x4f] = (int)(piVar25 + -0x4f);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x52] = (int)(piVar25 + -0x52);

    (*(int(*)())0x06035BC8)();

    piVar25[-0x53] = (int)(piVar25 + -0x4e);

    (*(int(*)())0x060359E4)();

    piVar25[-0x54] = 0x9999999A;

    piVar25[-0x55] = 0x40139999;

    piVar25[-0x56] = (int)(piVar25 + -0x51);

    (*(int(*)())0x060359E4)();

    piVar25[-0x57] = (int)(piVar25 + -0x52);

    (*(int(*)())0x06035460)();

    piVar25[-0x58] = 0;

    piVar25[-0x59] = 0x40680000;

    piVar26 = piVar25 + -0x5a;

    piVar25[-0x5a] = (int)(piVar25 + -0x55);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_08 = uVar13;

    uVar20 = iVar21 + 1;

    *(short *)(piVar25[-0x59] + 4) = uVar1;

    *(short *)(piVar25[-0x59] + 6) = uVar2;

    ppuVar11 = (int **)(piVar25 + -0x5a);

  } while (uVar20 < 0x16);

  piVar25[-0x5a] = iVar21 + -0x15;

  piVar25[-0x58] = iVar21 + -0x15;

  piVar25[-0x59] = piVar25[-0x5a];

  piVar25[-0x56] = (int)0x06089B18;

  piVar31 = piVar25 + -0x5a;

  for (; uVar20 < 0x28; uVar20 = uVar20 + 1) {

    *(unsigned int *)((int)piVar31 + 0xc) = (uVar20 << 3) + *(int *)((int)piVar31 + 0x10);

    *(char **)((int)piVar31 + -0x24) = (char *)((int)piVar31 + -0x24);

    (*(int(*)())0x06035BC8)();

    *(int *)((int)piVar31 + -0x28) = 0x33333333;

    *(int *)((int)piVar31 + -0x2c) = 0x4054D333;

    *(char **)((int)piVar31 + -0x30) = (char *)((int)piVar31 + -0x1c);

    (*(int(*)())0x060359E4)();

    *(char **)((int)piVar31 + -0x4c) = (char *)((int)piVar31 + -0x4c);

    (*(int(*)())0x06035BC8)();

    *(char **)((int)piVar31 + -0x58) = (char *)((int)piVar31 + -0x58);

    (*(int(*)())0x06035BC8)();

    *(char **)((int)piVar31 + -0x5c) = (char *)((int)piVar31 + -0x48);

    (*(int(*)())0x060359E4)();

    *(int *)((int)piVar31 + -0x60) = 0x9999999A;

    *(int *)((int)piVar31 + -100) = 0x40139999;

    *(char **)((int)piVar31 + -0x68) = (char *)((int)piVar31 + -0x54);

    (*(int(*)())0x060359E4)();

    *(char **)((int)piVar31 + -0x6c) = (char *)((int)piVar31 + -0x58);

    (*(int(*)())0x06035460)();

    *(int *)((int)piVar31 + -0x70) = 0;

    *(int *)((int)piVar31 + -0x74) = 0x40580000;

    piVar26 = (int *)((int)piVar31 + -0x78);

    *(char **)((int)piVar31 + -0x78) = (char *)((int)piVar31 + -100);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_09 = uVar13;

    *(short *)(*(int *)((int)piVar31 + -0x6c) + 4) = DAT_06021e98;

    *(short *)(*(int *)((int)piVar31 + -0x6c) + 6) = DAT_06021e9a;

    *(int *)((int)piVar31 + -0x70) = *(int *)((int)piVar31 + -0x70) + 1;

    *(int *)((int)piVar31 + -0x74) = *(int *)((int)piVar31 + -0x74) + 1;

    *(int *)((int)piVar31 + -0x78) = *(int *)((int)piVar31 + -0x78) + 1;

    piVar31 = (int *)((int)piVar31 + -0x78);

  }

  *(char **)((int)piVar26 + 4) = 0x06089B18;

  uVar20 = uVar18;

  do {

    *piVar26 = (uVar20 << 3) + piVar26[1] + iVar24;

    piVar26[-9] = (int)(piVar26 + -9);

    (*(int(*)())0x06035BC8)();

    piVar26[-10] = 0x9999999A;

    piVar26[-0xb] = 0x404FD999;

    piVar26[-0xc] = (int)(piVar26 + -7);

    (*(int(*)())0x060359E4)();

    piVar26[-0x13] = (int)(piVar26 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x16] = (int)(piVar26 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x17] = (int)(piVar26 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar26[-0x18] = 0x9999999A;

    piVar26[-0x19] = 0x40139999;

    piVar26[-0x1a] = (int)(piVar26 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar26[-0x1b] = (int)(piVar26 + -0x16);

    (*(int(*)())0x06035460)();

    piVar26[-0x1c] = 0;

    piVar26[-0x1d] = 0x40700000;

    piVar26[-0x1e] = (int)(piVar26 + -0x19);

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_10 = uVar13;

    iVar21 = uVar20 + 1;

    *(short *)(piVar26[-0x1e] + 4) = DAT_06021fe0;

    *(short *)(piVar26[-0x1e] + 6) = (short)uVar18;

    piVar26[-0x1e] = (iVar21 << 3) + piVar26[-0x1d] + iVar24;

    piVar26[-0x27] = (int)(piVar26 + -0x27);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x28] = 0x9999999A;

    piVar26[-0x29] = 0x404FD999;

    piVar26[-0x2a] = (int)(piVar26 + -0x25);

    (*(int(*)())0x060359E4)();

    piVar26[-0x31] = (int)(piVar26 + -0x31);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x34] = (int)(piVar26 + -0x34);

    (*(int(*)())0x06035BC8)();

    piVar26[-0x35] = (int)(piVar26 + -0x30);

    (*(int(*)())0x060359E4)();

    piVar26[-0x36] = 0x9999999A;

    piVar26[-0x37] = 0x40139999;

    piVar26[-0x38] = (int)(piVar26 + -0x33);

    (*(int(*)())0x060359E4)();

    piVar26[-0x39] = (int)(piVar26 + -0x34);

    (*(int(*)())0x06035460)();

    piVar26[-0x3a] = 0;

    piVar27 = piVar26 + -0x3b;

    piVar26[-0x3b] = 0x40700000;

    piVar16 = piVar26 + -0x37;

    piVar28 = piVar26 + -0x3c;

    piVar29 = piVar26 + -0x3c;

    piVar30 = piVar26 + -0x3c;

    piVar31 = piVar26 + -0x3c;

    piVar32 = piVar26 + -0x3c;

    piVar26 = piVar26 + -0x3c;

    *piVar28 = (int)piVar16;

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_11 = uVar13;

    uVar20 = iVar21 + 1;

    *(short *)(*piVar29 + 4) = DAT_06022114;

    *(short *)(*piVar30 + 6) = (short)uVar18;

  } while (uVar20 < 0xe);

  *piVar27 = (int)0x06089B18;

  for (; uVar20 < 0x1c; uVar20 = uVar20 + 1) {

    *piVar31 = (uVar20 << 3) + piVar31[1] + iVar24;

    piVar31[-9] = (int)(piVar31 + -9);

    (*(int(*)())0x06035BC8)();

    piVar31[-10] = 0x9999999A;

    piVar31[-0xb] = 0x404FD999;

    piVar31[-0xc] = (int)(piVar31 + -7);

    (*(int(*)())0x060359E4)();

    piVar31[-0x13] = (int)(piVar31 + -0x13);

    (*(int(*)())0x06035BC8)();

    piVar31[-0x16] = (int)(piVar31 + -0x16);

    (*(int(*)())0x06035BC8)();

    piVar31[-0x17] = (int)(piVar31 + -0x12);

    (*(int(*)())0x060359E4)();

    piVar31[-0x18] = 0x9999999A;

    piVar31[-0x19] = 0x40139999;

    piVar31[-0x1a] = (int)(piVar31 + -0x15);

    (*(int(*)())0x060359E4)();

    piVar31[-0x1b] = (int)(piVar31 + -0x16);

    (*(int(*)())0x06035460)();

    piVar31[-0x1c] = 0;

    piVar31[-0x1d] = 0x40600000;

    piVar26 = piVar31 + -0x19;

    piVar33 = piVar31 + -0x1e;

    piVar34 = piVar31 + -0x1e;

    piVar35 = piVar31 + -0x1e;

    piVar32 = piVar31 + -0x1e;

    piVar31 = piVar31 + -0x1e;

    *piVar33 = (int)piVar26;

    (*(int(*)())0x060359E4)();

    uVar13 = (*(int(*)())0x060357B8)();

    *extraout_r3_12 = uVar13;

    *(short *)(*piVar34 + 4) = (short)uVar18;

    *(short *)(*piVar35 + 6) = (short)uVar18;

  }

  *piVar32 = (int)0x06089B18;

  puVar22 = (unsigned int *)(0x06089B18 + iVar24 + (uVar20 << 3));

  piVar32[1] = (int)(0x06089B18 + DAT_06022116);

  if (puVar22 < 0x06089B18 + DAT_06022116) {

    do {

      *piVar32 = (int)puVar22;

      *puVar22 = uVar18;

      puVar22 = puVar22 + 2;

      *(short *)(*piVar32 + 4) = DAT_06022118;

      *(short *)(*piVar32 + 6) = (short)uVar18;

    } while (puVar22 < (unsigned int *)piVar32[1]);

  }

  return;

}
