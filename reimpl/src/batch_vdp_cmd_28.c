extern int DAT_06028304;
extern int DAT_06028348;
extern int DAT_06028708;
extern int DAT_06029c2e;
extern int DAT_06029ea4;
extern int DAT_06029ea6;
extern int DAT_06029ed4;
extern int DAT_06029ee2;
extern int DAT_06029f2a;
extern int DAT_06029f2c;
extern int DAT_06029f2e;
extern int DAT_06029f30;
extern int DAT_06029f3e;
extern int DAT_06029f4c;
extern int DAT_06029f94;
extern int DAT_06029f96;
extern int DAT_06029f98;
extern int DAT_06029f9a;
extern int DAT_06029fa8;
extern int DAT_06029fb6;
extern int DAT_06029ffe;
extern int DAT_0602a000;
extern int DAT_0602a002;
extern int DAT_0602a004;
extern int DAT_0602a012;
extern int DAT_0602a020;
extern int DAT_0602a050;
extern char * FUN_060282c0();
extern char * FUN_06028306();
extern int PTR_DAT_060286ac;
extern int PTR_DAT_06029ea8;
extern void FUN_06029bf4();
extern void FUN_060284ae();

/* vdp1_sprite_cmd_build -- Build a VDP1 sprite draw command from object data.
 * Looks up texture index from 0x060684EC tilemap, resolves texture info
 * from 0x06063F64 table. Copies draw mode, color mode, palette,
 * and 4 vertex coordinates from the source object (param_1) into
 * the VDP1 command buffer entry (param_2). */
void FUN_060280f8(param_1, param_2)
    int param_1;
    short *param_2;
{
  unsigned short tex_idx;
  short palette_offset;
  int *tex_entry;

  tex_idx = *(unsigned short *)
           (0x060684EC +
           ((int)*(short *)(param_1 + 6) + (((unsigned int)*(unsigned char *)(param_1 + 5) << 8) >> 2)) << 1);

  palette_offset = *(short *)(0x06063F64 + (unsigned int)(tex_idx << 3) + 6);

  *param_2 = (short)*(int *)(0x06028178 + ((int)*(char *)(param_1 + 4) & 0xc)); /* draw mode */
  param_2[2] = *(short *)(0x06028174 + ((int)*(char *)(param_1 + 4) & 1U) << 1); /* color mode */
  param_2[3] = (short)*(int *)0x06059FFC + palette_offset; /* palette base + offset */

  tex_entry = (int *)(0x06063F64 + (unsigned int)(tex_idx << 3));
  param_2[4] = (short)*tex_entry; /* texture source address */
  param_2[5] = *(short *)(tex_entry + 1); /* texture size */

  /* copy 4 vertex coordinates (8 bytes each = XY pairs) */
  *(int *)(param_2 + 6) = *(int *)(param_1 + 8);
  *(int *)(param_2 + 8) = *(int *)(param_1 + 0xc);
  *(int *)(param_2 + 10) = *(int *)(param_1 + 0x10);
  *(int *)(param_2 + 0xc) = *(int *)(param_1 + 0x14);
}

/* int_to_ascii_decimal -- Convert integer to right-justified space-padded ASCII string.
 * Uses SH-2 hardware division unit (0xFFFFFF00) for digit extraction. */
char * FUN_060282c0(param_1)
    int param_1;
{
  char *buf;
  char *fill;
  int pos;
  int prev_pos;
  int *div_unit;
  char sign_char;
  fill = (int *)0x20202020;           /* ASCII space fill */
  buf = (int *)0x060620C4;            /* output buffer */
  *(char **)0x060620C4 = 0x20202020;
  *(char **)(buf + 4) = fill;
  *(char **)(buf + 8) = fill;
  buf[0xb] = 0;                       /* null terminator */
  sign_char = 0x20;                   /* ' ' default */
  if (param_1 < 0) {
    param_1 = -param_1;
    sign_char = 0x2d;                 /* '-' for negative */
  }
  div_unit = (int *)-256;             /* SH-2 DVSR at 0xFFFFFF00 */
  *div_unit = 10;                     /* divisor = 10 */
  pos = 10;
  do {
    prev_pos = pos;
    if (param_1 == 0) break;
    div_unit[1] = param_1;            /* DVDNT: trigger division */
    prev_pos = pos + -1;
    buf[pos + 1] = (char)div_unit[6]; /* remainder → digit char */
    param_1 = div_unit[7];            /* quotient → next dividend */
    pos = prev_pos;
  } while (prev_pos != 0);
  buf[prev_pos] = sign_char;
  return buf;
}

/* int_to_tile_decimal -- Convert integer to right-justified tile-index string.
 * Same as int_to_ascii_decimal but fills with tile 0x0A (blank) instead of space. */
char * FUN_06028306(param_1)
    int param_1;
{
  char *buf;
  int tile_fill;
  int pos;
  int prev_pos;
  int *div_unit;
  char sign_tile;
  tile_fill = 0x0A0A0A0A;             /* blank tile fill */
  buf = (int *)0x060620C4;            /* output buffer */
  *(int *)0x060620C4 = 0x0A0A0A0A;
  *(int *)(buf + 4) = tile_fill;
  *(int *)(buf + 8) = tile_fill;
  buf[0xb] = 0;                       /* null terminator */
  sign_tile = 10;                     /* blank tile default */
  if (param_1 < 0) {
    param_1 = -param_1;
    sign_tile = 0x2d;                 /* '-' tile for negative */
  }
  div_unit = (int *)-256;             /* SH-2 DVSR at 0xFFFFFF00 */
  *div_unit = 10;                     /* divisor = 10 */
  pos = 10;
  do {
    prev_pos = pos;
    if (param_1 == 0) break;
    div_unit[1] = param_1;            /* DVDNT: trigger division */
    prev_pos = pos + -1;
    buf[pos + 1] = (char)div_unit[6]; /* remainder → digit tile */
    param_1 = div_unit[7];            /* quotient → next dividend */
    pos = prev_pos;
  } while (prev_pos != 0);
  buf[prev_pos] = sign_tile;
  return buf;
}

/* vdp2_number_draw -- Draw a number as tiles on VDP2 scroll plane.
 * Converts param_4 (integer) to ASCII via FUN_060282c0 (int-to-string),
 * then writes 4 character tiles starting at offset +8 of the result
 * to the scroll plane at param_2 offset. Each char gets param_3 added
 * as palette offset. Returns 8 (bytes written = 4 tiles * 2 bytes). */
#if 0 /* FUN_0602834A -- replaced by ASM import */
int FUN_0602834a(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    int param_4;
{
  char ch;
  int done;
  int i;
  char *digits;

  param_2 = param_2 + **(int **)(0x06028614 + param_1);
  digits = (char *)(FUN_060282c0(param_4) + 8); /* get last 4 digits */

  i = 0;
  do {
    ch = *digits;
    digits = digits + 1;
    *(short *)(param_2 + i) = ch + param_3; /* write tile with palette offset */
    done = i != 6;
    i = i + 2;
  } while (done);

  return 8;
}
#endif

/* vdp2_string_draw -- Draw a null-terminated string as tiles on VDP2.
 * Writes characters from param_4 string to scroll plane selected by
 * param_1, at offset param_2. Each character gets param_3 added as
 * palette/priority offset. Stops at null terminator. */
char * FUN_060283e0(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    short param_3;
    char *param_4;
{
  char ch;
  short *dest;

  dest = (short *)(**(int **)(0x06028614 + param_1) + param_2);

  while (1) {
    ch = *param_4;
    param_4 = param_4 + 1;
    if (ch == '\0') break;
    *dest = ch + param_3; /* write tile with palette offset */
    dest = dest + 1;
  }

  return (char *)0x06028614;
}

/* vdp2_tilemap_write -- Write tile data to VDP2 pattern name table.
 * param_1: scroll plane index (selects base from 0x06028614 ptr table)
 * param_2: tile source (header: [width, height], then tile IDs)
 * param_3: destination offset within pattern name table
 * param_4: palette/priority offset added to each tile ID
 * Copies width*height tiles, advancing dest by 0x80 bytes per row
 * (64 tiles * 2 bytes = VDP2 page width). */
int FUN_06028400(param_1, param_2, param_3, param_4)
    int param_1;
    short *param_2;
    int param_3;
    int param_4;
{
  short tile_id;
  int col;
  int row;
  int width;
  short *dest;

  dest = (short *)(param_3 + **(int **)(0x06028614 + param_1));
  width = (int)*param_2;
  row = (int)param_2[1];
  param_2 = param_2 + 2; /* skip header */

  col = width;
  do {
    do {
      tile_id = *param_2;
      param_2 = param_2 + 1;
      *dest = (short)(tile_id + param_4); /* write tile with offset */
      col = col + -1;
      dest = dest + 1;
    } while (col != 0);
    row = row + -1;
    dest = (short *)((int)dest - ((width << 1) + -0x80)); /* advance to next row */
    col = width;
  } while (row != 0);

  return tile_id + param_4;
}

/* vdp2_number_draw_font -- Draw number using proportional font tiles on VDP2.
 * Converts param_4 to digit string via FUN_06028306 (numeric variant),
 * then renders each digit as a multi-tile glyph from font table at
 * 0x06063690 + param_3. Font entry: [base_addr, palette, glyph_w,
 * glyph_h, char_stride, num_chars, row_advance].
 * Each digit maps to a row of glyph_w tiles, rendered glyph_h rows high. */
void FUN_06028430(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{
  char glyph_w;
  char char_stride;
  short palette;
  short row_adv;
  int digits_str;
  char *digit_ptr;
  char *digit_start;
  int font_base;
  int glyph_h;
  int num_chars;
  short *dest;
  int *font_entry;
  short *glyph_src;
  int col;

  dest = (short *)(param_2 + **(int **)(0x06028614 + param_1));
  digits_str = FUN_06028306(param_4);
  font_entry = (int *)(0x06063690 + param_3);

  font_base = *font_entry;
  palette = *(short *)(font_entry + 1);
  glyph_w = *(char *)((int)font_entry + 6);
  glyph_h = (int)*(char *)((int)font_entry + 7);
  char_stride = *(char *)(font_entry + 2);
  num_chars = (int)*(char *)((int)font_entry + 9);
  row_adv = *(short *)((int)font_entry + 10);

  digit_start = (char *)(digits_str - (num_chars + -0xc));
  digit_ptr = digit_start;

  do {
    do {
      glyph_src = (short *)(font_base + ((int)char_stride & 0xffffU) * ((int)*digit_ptr & 0xffffU));
      col = (int)glyph_w;
      do {
        *dest = *glyph_src + palette;
        glyph_src = glyph_src + 1;
        col = col + -1;
        dest = dest + 1;
      } while (col != 0);
      num_chars = num_chars + -1;
      digit_ptr = digit_ptr + 1;
    } while (num_chars != 0);
    font_base = font_base + (glyph_w << 1); /* next glyph row */
    glyph_h = glyph_h + -1;
    dest = (short *)((int)dest + (int)row_adv);
    digit_ptr = digit_start;
    num_chars = (int)*(char *)((int)font_entry + 9);
  } while (glyph_h != 0);
}


/* vdp_display_list_fill -- Fill a VDP1 command list channel with a pattern.
 *
 * Pool verified (0x06028556-0x0602855E):
 *   0x06028558 = 0x06028644 (fill value table, indexed by channel*4)
 *   0x0602855C = 0x0602862C (dest pointer table, indexed by channel*4)
 *   0x06028556 = 0x0800 (2048 words per channel)
 *
 * Called with channel offsets 4, 8, 12 from race state handlers.
 * Fills 2048 words (8KB) at the destination with the channel's fill pattern. */
#define VDP1_FILL_TABLE   0x06028644
#define VDP1_DEST_TABLE   0x0602862C
#define VDP1_CHANNEL_SIZE 0x0800
int * vdp_display_list_fill(channel)
    int channel;
{
    int *dest;
    int count;
    int fill_value;

    fill_value = *(int *)(VDP1_FILL_TABLE + channel);
    dest = (int *)**(int **)(VDP1_DEST_TABLE + channel);
    count = VDP1_CHANNEL_SIZE;

    do {
        *dest = fill_value;
        count = count + -1;
        dest = dest + 1;
    } while (count != 0);

    return dest;
}
#undef VDP1_FILL_TABLE
#undef VDP1_DEST_TABLE
#undef VDP1_CHANNEL_SIZE

/* vdp2_pattern_table_clear -- Clear VDP2 pattern name table to blank tiles.
 *
 * Pool verified (0x06028572-0x06028578):
 *   0x06028574 = 0x060612C4 (pattern name table shadow buffer)
 *   0x06028578 = 0x00200020 (blank tile pattern: tile 0x20 both planes)
 *   0x06028572 = 0x0380 (896 entries)
 *
 * Fills 896 words at the shadow buffer with the blank tile pattern.
 * Called from race state and subsystem init handlers. */
#define VDP2_PNT_SHADOW   ((int *)0x060612C4)
#define VDP2_BLANK_TILE   0x00200020
#define VDP2_PNT_SIZE     0x0380
int * vdp2_pattern_table_clear()
{
    int *dest;
    int count;

    count = VDP2_PNT_SIZE;
    dest = VDP2_PNT_SHADOW;

    do {
        *dest = (char *)VDP2_BLANK_TILE;
        count = count + -1;
        dest = dest + 1;
    } while (count != 0);

    return dest;
}
#undef VDP2_PNT_SHADOW
#undef VDP2_BLANK_TILE
#undef VDP2_PNT_SIZE

long long dma_mem_transfer(param_1, param_2)
    unsigned char *param_1;
    unsigned char *param_2;
{

  unsigned char bVar1;

  unsigned char bVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int in_r0 = 0;

  int in_r1 = 0;

  int iVar6;

  unsigned int uVar7;

  unsigned int uVar8;

  int iVar9;

  unsigned int uVar10;

  uVar5 = 0x00000FFF;

  puVar4 = (char *)0x0000FF00;

  puVar3 = (char *)0x0602872C;

  uVar7 = 0;

  uVar8 = 0;

  while( 1 ) {

    while( 1 ) {

      uVar8 = uVar8 >> 1;

      if ((uVar8 & 0x100) == 0) {

        bVar1 = *param_1;

        param_1 = param_1 + 1;

        uVar8 = (unsigned int)bVar1 | (unsigned int)puVar4;

      }

      if ((uVar8 & 1) == 0) break;

      bVar1 = *param_1;

      param_1 = param_1 + 1;

      *param_2 = bVar1;

      param_2 = param_2 + 1;

      puVar3[uVar7] = bVar1;

      uVar7 = uVar7 + 1 & uVar5;

    }

    bVar1 = *param_1;

    bVar2 = param_1[1];

    param_1 = param_1 + 2;

    if (bVar2 == 0 && bVar1 == 0) break;

    uVar10 = (unsigned int)DAT_06028708;

    iVar9 = ((bVar2 | uVar10) << 8 | (unsigned int)bVar1) + uVar7;

    iVar6 = 0;

    do {

      bVar1 = puVar3[iVar9 + iVar6 & uVar5];

      *param_2 = bVar1;

      param_2 = param_2 + 1;

      puVar3[uVar7] = bVar1;

      uVar7 = uVar7 + 1 & uVar5;

      iVar6 = iVar6 + 1;

    } while (iVar6 < ((int)(bVar2 & uVar10) >> 4) + 3);

  }

  return CONCAT44(in_r1,in_r0);

}


/* FUN_0602834A -- original binary (30 bytes) */
__asm__(
    ".section .text.FUN_0602834A, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0602834A\n"
    ".type _FUN_0602834A, @function\n"
    "_FUN_0602834A:\n"
    ".byte 0x4F, 0x22, 0xD0, 0x05, 0x02, 0x4E, 0x62, 0x22, 0x35, 0x2C, 0xBF, 0xB4, 0x64, 0x73, 0x61, 0x03\n"  /* 0x0602834A */
    ".byte 0xE7, 0x06, 0x71, 0x08, 0xA0, 0x1B, 0xE0, 0x00, 0x00, 0x00, 0x06, 0x02, 0x86, 0x14\n"  /* 0x0602835A */
);
