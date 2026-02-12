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

/* vdp2_string_draw_font -- Draw string using proportional font tiles on VDP2.
 * Like vdp2_number_draw_font but takes a null-terminated string (param_4)
 * instead of an integer. First counts string length, then renders each
 * character as a multi-tile glyph from font table at 0x06063690 + param_3.
 * Character mapping: index = (char - base_char) where base_char is at +9.
 * Row advance = -(glyph_w * string_len - 0x40) to wrap to next row. */
void FUN_060284ae(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    char *param_4;
{
  char char_stride;
  char base_char;
  char ch;
  short palette;
  char *str_ptr;
  unsigned int glyph_w;
  int glyph_h;
  int font_base;
  short *dest;
  int *font_entry;
  short *glyph_src;
  unsigned int str_len;
  unsigned int remaining;
  unsigned int col;

  dest = (short *)(param_2 + **(int **)(0x06028614 + param_1));
  font_entry = (int *)(0x06063690 + param_3);
  font_base = *font_entry;
  palette = *(short *)(font_entry + 1);
  glyph_w = (unsigned int)*(char *)((int)font_entry + 6);
  glyph_h = (int)*(char *)((int)font_entry + 7);
  char_stride = *(char *)(font_entry + 2);
  base_char = *(char *)((int)font_entry + 9);

  /* count string length */
  str_len = 0xffffffff;
  str_ptr = param_4;
  do {
    ch = *str_ptr;
    str_ptr = str_ptr + 1;
    str_len = str_len + 1;
  } while (ch != '\0');

  str_ptr = param_4;
  remaining = str_len;
  do {
    do {
      glyph_src = (short *)(font_base + ((int)char_stride & 0xffffU) * ((int)*str_ptr - (int)base_char & 0xffffU));
      col = glyph_w;
      do {
        *dest = *glyph_src + palette;
        glyph_src = glyph_src + 1;
        col = col - 1;
        dest = dest + 1;
      } while (col != 0);
      remaining = remaining - 1;
      str_ptr = str_ptr + 1;
    } while (remaining != 0);
    font_base = font_base + (glyph_w << 1); /* next glyph row */
    glyph_h = glyph_h + -1;
    dest = dest + -((glyph_w & 0xffff) * (str_len & 0xffff) + -0x40); /* row wrap */
    str_ptr = param_4;
    remaining = str_len;
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

unsigned int FUN_06029bf4(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    char param_3;
    int param_4;
{

  unsigned int uVar1;

  unsigned int uVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  char *puVar6;

  unsigned int uVar7;

  int iVar8;

  int iVar9;

  int *puVar10;

  int uVar11;

  int iVar12;

  unsigned int *puVar13;

  unsigned int *puVar14;

  unsigned int *puVar15;

  unsigned int *puVar16;

  int iVar17;

  unsigned int in_sr = 0;

  unsigned int uVar18;

  unsigned int uVar19;

  unsigned int uVar20;

  unsigned int uVar21;

  unsigned int uVar22;

  unsigned int uVar23;

  unsigned int uVar24;

  unsigned int uVar25;

  unsigned int uVar26;

  iVar17 = *(int *)0x06063F08;

  puVar15 = (unsigned int *)(param_1 + param_4 * 0x18);

  do {

    puVar3 = (char *)0x0608A70C;

    puVar16 = puVar15 + -6;

    uVar19 = in_sr & 0xfffffffe;

    uVar18 = uVar19 | *(short *)0x0605BE36 == 0;

    if ((((unsigned char)uVar18 & 1) == 1) ||

       (uVar7 = (unsigned int)*(short *)((int)puVar15 + -10), uVar18 = uVar19, (int)DAT_06029c2e != uVar7))

    {

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)(puVar15 + -2) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar7 = *puVar14;

      uVar19 = *puVar13;

      uVar20 = uVar7 ^ uVar19;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar2 = (uVar19 & 0xffff) * (uVar7 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar7 & 0xffff);

      iVar8 = 0;

      uVar1 = iVar9 + (uVar19 & 0xffff) * (uVar7 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar2 + (uVar1 << 16);

      uVar19 = iVar8 + (unsigned int)(uVar21 < uVar2) + (uVar1 >> 0x10) + (uVar19 >> 0x10) * (uVar7 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar21 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar20 = puVar14[1];

      uVar7 = puVar13[1];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar26 = uVar21 + uVar26;

        uVar19 = uVar7 + (uVar26 < uVar21) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar26 = uVar21 + uVar26;

        uVar19 = uVar7 + (uVar26 < uVar21) + uVar19;

      }

      uVar20 = puVar14[2];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar26 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar23 = uVar26 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar26) + uVar19;

      }

      uVar20 = puVar14[3];

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[4];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + uVar7;

      }

      *(unsigned int *)0x0608A70C = (uVar19 << 0x10 | uVar23 >> 0x10) + puVar14[9];

      uVar20 = puVar14[5];

      uVar19 = puVar13[2];

      uVar1 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar21 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar19 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar23 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar19 + (uVar23 < uVar22) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar19 + (uVar23 < uVar22) + uVar7;

      }

      uVar20 = puVar14[6];

      uVar19 = *puVar13;

      uVar1 = uVar20 ^ uVar19;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar19 < 0) {

        uVar19 = -uVar19;

      }

      uVar21 = (uVar19 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar19 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar19 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + (uVar2 << 16);

      uVar19 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) +

               (uVar19 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar19 = ~uVar19;

        if (uVar26 == 0) {

          uVar19 = uVar19 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      uVar1 = puVar14[7];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar19 = uVar20 + (uVar22 < uVar26) + uVar19;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar7 << 0x10 | uVar23 >> 0x10) + puVar14[10];

      uVar20 = puVar14[8];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar22) + (uVar19 & 0xffff);

        if ((int)uVar19 < -0x8000) {

          uVar19 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar19) {

          uVar19 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar19 = uVar19 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar19 = uVar7 + (uVar23 < uVar22) + uVar19;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar19 << 0x10 | uVar23 >> 0x10) + puVar14[0xb];

      puVar4 = (char *)0x0608A704;

      uVar19 = uVar18 & 0xfffffffe;

      *(unsigned short *)0x0608A704 = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = (char *)0x0608A73C;

      if ((puVar15[-3] & 0x80000) == 0) {

        puVar13 = *(unsigned int **)0x06089EDC;

        uVar20 = *puVar13;

        uVar7 = *puVar16;

        uVar1 = uVar20 ^ uVar7;

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

        iVar8 = 0;

        uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar23 = uVar21 + (uVar2 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

                (uVar7 >> 0x10) * (uVar20 >> 0x10);

        if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar23 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar23 = ~uVar23 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar23 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar23 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        uVar1 = puVar13[1];

        uVar20 = puVar15[-5];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar26 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

        }

        uVar1 = puVar13[2];

        uVar20 = puVar15[-4];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        uVar1 = puVar13[3];

        uVar20 = *puVar16;

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        *(unsigned int *)0x0608A73C = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar1 = puVar13[4];

        uVar7 = puVar15[-5];

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar26 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar20 = uVar7 + (uVar26 < uVar24) + (uVar20 & 0xffff);

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar20 = uVar7 + (uVar26 < uVar24) + uVar20;

        }

        uVar1 = puVar13[5];

        uVar7 = puVar15[-4];

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + (uVar21 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar24 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar26 + uVar24;

          uVar20 = uVar7 + (uVar24 < uVar26) + (uVar20 & 0xffff);

          if ((int)uVar20 < -0x8000) {

            uVar20 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar20) {

            uVar20 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar20 = uVar20 & 0xffff;

        }

        else {

          uVar24 = uVar26 + uVar24;

          uVar20 = uVar7 + (uVar24 < uVar26) + uVar20;

        }

        uVar1 = puVar13[6];

        uVar7 = *puVar16;

        uVar2 = uVar1 ^ uVar7;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                (uVar7 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar26 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        *(unsigned int *)(puVar3 + 4) = uVar20 << 0x10 | uVar24 >> 0x10;

        uVar1 = puVar13[7];

        uVar20 = puVar15[-5];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar26 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar26) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar26 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar26) + uVar7;

        }

        uVar1 = puVar13[8];

        uVar20 = puVar15[-4];

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        *(unsigned int *)(puVar3 + 8) = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar20 = *(unsigned int *)puVar3;

        uVar7 = *(unsigned int *)0x0608A70C;

        uVar1 = uVar20 ^ uVar7;

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        if ((int)uVar7 < 0) {

          uVar7 = -uVar7;

        }

        uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

        iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

        iVar8 = 0;

        uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar23 = uVar21 + (uVar2 << 16);

        uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

                (uVar7 >> 0x10) * (uVar20 >> 0x10);

        if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

          uVar7 = ~uVar7;

          if (uVar23 == 0) {

            uVar7 = uVar7 + 1;

          }

          else {

            uVar23 = ~uVar23 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar23 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar23 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        uVar1 = *(unsigned int *)(puVar3 + 4);

        uVar20 = *(unsigned int *)(0x0608A70C + 4);

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar24 = uVar26 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar24 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar24 = ~uVar24 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar24 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar24 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar24 = uVar23 + uVar24;

          uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

        }

        uVar1 = *(unsigned int *)(puVar3 + 8);

        uVar20 = *(unsigned int *)(0x0608A70C + 8);

        uVar2 = uVar1 ^ uVar20;

        if ((int)uVar1 < 0) {

          uVar1 = -uVar1;

        }

        if ((int)uVar20 < 0) {

          uVar20 = -uVar20;

        }

        uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

        iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

        iVar8 = 0;

        uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

        if (iVar9 != 0) {

          iVar8 = 0x10000;

        }

        uVar26 = uVar23 + (uVar21 << 16);

        uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

                 (uVar20 >> 0x10) * (uVar1 >> 0x10);

        if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

          uVar20 = ~uVar20;

          if (uVar26 == 0) {

            uVar20 = uVar20 + 1;

          }

          else {

            uVar26 = ~uVar26 + 1;

          }

        }

        if (((unsigned char)(uVar18 >> 1) & 1) == 1) {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

          if ((int)uVar7 < -0x8000) {

            uVar7 = 0xffff8000;

            uVar26 = 0;

          }

          if (0x7fff < (int)uVar7) {

            uVar7 = 0x7fff;

            uVar26 = 0xffffffff;

          }

          uVar7 = uVar7 & 0xffff;

        }

        else {

          uVar26 = uVar24 + uVar26;

          uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

        }

        uVar7 = uVar7 << 0x10 | uVar26 >> 0x10;

        uVar19 = uVar19 | 0 < (int)uVar7;

        if (((unsigned char)uVar19 & 1) != 1) goto LAB_0602a1b6;

      }

      puVar3 = (char *)0x0608A718;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)((int)puVar15 + -6) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar7 = *puVar14;

      uVar18 = *puVar13;

      uVar20 = uVar7 ^ uVar18;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar2 = (uVar18 & 0xffff) * (uVar7 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar7 & 0xffff);

      iVar8 = 0;

      uVar1 = iVar9 + (uVar18 & 0xffff) * (uVar7 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar21 = uVar2 + (uVar1 << 16);

      uVar18 = iVar8 + (unsigned int)(uVar21 < uVar2) + (uVar1 >> 0x10) + (uVar18 >> 0x10) * (uVar7 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar20 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar21 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar21 = ~uVar21 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar21 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar21 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar20 = puVar14[1];

      uVar7 = puVar13[1];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar21 + uVar26;

        uVar18 = uVar7 + (uVar26 < uVar21) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar26 = uVar21 + uVar26;

        uVar18 = uVar7 + (uVar26 < uVar21) + uVar18;

      }

      uVar20 = puVar14[2];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar26 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar26) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar26 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar26) + uVar18;

      }

      uVar20 = puVar14[3];

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[4];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar7 = uVar20 + (uVar22 < uVar26) + uVar7;

      }

      *(unsigned int *)0x0608A718 = (uVar18 << 0x10 | uVar23 >> 0x10) + puVar14[9];

      uVar20 = puVar14[5];

      uVar18 = puVar13[2];

      uVar1 = uVar20 ^ uVar18;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar21 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar18 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) +

               (uVar18 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar23 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar18 + (uVar23 < uVar22) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar7 = uVar18 + (uVar23 < uVar22) + uVar7;

      }

      uVar20 = puVar14[6];

      uVar18 = *puVar13;

      uVar1 = uVar20 ^ uVar18;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar18 < 0) {

        uVar18 = -uVar18;

      }

      uVar21 = (uVar18 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar18 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar18 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar21 + (uVar2 << 16);

      uVar18 = iVar8 + (unsigned int)(uVar26 < uVar21) + (uVar2 >> 0x10) +

               (uVar18 >> 0x10) * (uVar20 >> 0x10);

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar18 = ~uVar18;

        if (uVar26 == 0) {

          uVar18 = uVar18 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      uVar1 = puVar14[7];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar24 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar22 = uVar24 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar22 < uVar24) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar22 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar22 = ~uVar22 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar22 = uVar26 + uVar22;

        uVar18 = uVar20 + (uVar22 < uVar26) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar22 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar22 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar22 = uVar26 + uVar22;

        uVar18 = uVar20 + (uVar22 < uVar26) + uVar18;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar7 << 0x10 | uVar23 >> 0x10) + puVar14[10];

      uVar20 = puVar14[8];

      uVar7 = puVar13[2];

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar23 = uVar22 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar22) + (uVar18 & 0xffff);

        if ((int)uVar18 < -0x8000) {

          uVar18 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar18) {

          uVar18 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar18 = uVar18 & 0xffff;

      }

      else {

        uVar23 = uVar22 + uVar23;

        uVar18 = uVar7 + (uVar23 < uVar22) + uVar18;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar18 << 0x10 | uVar23 >> 0x10) + puVar14[0xb];

      uVar18 = uVar19 & 0xfffffffe;

      *(unsigned short *)(puVar4 + 2) = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = (char *)0x0608A724;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)(puVar15 + -1) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar20 = *puVar14;

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[1];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar26 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

      }

      uVar1 = puVar14[2];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

      }

      uVar1 = puVar14[3];

      uVar20 = *puVar13;

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar2 = puVar14[4];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + (uVar23 << 16);

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + uVar20;

      }

      *(unsigned int *)0x0608A724 = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[9];

      uVar1 = puVar14[5];

      uVar7 = puVar13[2];

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + uVar20;

      }

      uVar1 = puVar14[6];

      uVar7 = *puVar13;

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + (uVar21 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar24 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar2 = puVar14[7];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + (uVar23 << 16);

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + uVar7;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar20 << 0x10 | uVar26 >> 0x10) + puVar14[10];

      uVar1 = puVar14[8];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + uVar7;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[0xb];

      *(unsigned short *)(puVar4 + 4) = (unsigned short)(*(int *)(puVar3 + 8) <= iVar17);

      puVar3 = (char *)0x0608A730;

      puVar13 = (unsigned int *)((unsigned int)*(unsigned short *)((int)puVar15 + -2) * 0xc + param_2);

      puVar14 = *(unsigned int **)0x06089EDC;

      uVar20 = *puVar14;

      uVar7 = *puVar13;

      uVar1 = uVar20 ^ uVar7;

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar21 = (uVar7 & 0xffff) * (uVar20 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar20 & 0xffff);

      iVar8 = 0;

      uVar2 = iVar9 + (uVar7 & 0xffff) * (uVar20 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar23 = uVar21 + (uVar2 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar23 < uVar21) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar20 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar23 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar23 = ~uVar23 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar23 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar23 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar1 = puVar14[1];

      uVar20 = puVar13[1];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar26 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar26 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar26) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar24 = uVar23 + uVar24;

        uVar7 = uVar20 + (uVar24 < uVar23) + uVar7;

      }

      uVar1 = puVar14[2];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar24 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar24) + uVar7;

      }

      uVar1 = puVar14[3];

      uVar20 = *puVar13;

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar24 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      uVar2 = puVar14[4];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + (uVar23 << 16);

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar20 = uVar1 + (uVar25 < uVar24) + uVar20;

      }

      *(unsigned int *)0x0608A730 = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[9];

      uVar1 = puVar14[5];

      uVar7 = puVar13[2];

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar26 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + (uVar20 & 0xffff);

        if ((int)uVar20 < -0x8000) {

          uVar20 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar20) {

          uVar20 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar20 = uVar20 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar20 = uVar7 + (uVar26 < uVar25) + uVar20;

      }

      uVar1 = puVar14[6];

      uVar7 = *puVar13;

      uVar2 = uVar1 ^ uVar7;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar23 = (uVar7 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar7 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar7 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar24 = uVar23 + (uVar21 << 16);

      uVar7 = iVar8 + (unsigned int)(uVar24 < uVar23) + (uVar21 >> 0x10) + (uVar7 >> 0x10) * (uVar1 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar24 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar24 = ~uVar24 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar24 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar24 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      uVar2 = puVar14[7];

      uVar1 = puVar13[1];

      uVar21 = uVar2 ^ uVar1;

      if ((int)uVar2 < 0) {

        uVar2 = -uVar2;

      }

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      uVar22 = (uVar1 & 0xffff) * (uVar2 & 0xffff);

      iVar9 = (uVar1 >> 0x10) * (uVar2 & 0xffff);

      iVar8 = 0;

      uVar23 = iVar9 + (uVar1 & 0xffff) * (uVar2 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar25 = uVar22 + (uVar23 << 16);

      uVar1 = iVar8 + (unsigned int)(uVar25 < uVar22) + (uVar23 >> 0x10) + (uVar1 >> 0x10) * (uVar2 >> 0x10)

      ;

      if ((int)-(unsigned int)((int)uVar21 < 0) < 0) {

        uVar1 = ~uVar1;

        if (uVar25 == 0) {

          uVar1 = uVar1 + 1;

        }

        else {

          uVar25 = ~uVar25 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar25 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar25 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar25 = uVar24 + uVar25;

        uVar7 = uVar1 + (uVar25 < uVar24) + uVar7;

      }

      *(unsigned int *)(puVar3 + 4) = (uVar20 << 0x10 | uVar26 >> 0x10) + puVar14[10];

      uVar1 = puVar14[8];

      uVar20 = puVar13[2];

      uVar2 = uVar1 ^ uVar20;

      if ((int)uVar1 < 0) {

        uVar1 = -uVar1;

      }

      if ((int)uVar20 < 0) {

        uVar20 = -uVar20;

      }

      uVar23 = (uVar20 & 0xffff) * (uVar1 & 0xffff);

      iVar9 = (uVar20 >> 0x10) * (uVar1 & 0xffff);

      iVar8 = 0;

      uVar21 = iVar9 + (uVar20 & 0xffff) * (uVar1 >> 0x10);

      if (iVar9 != 0) {

        iVar8 = 0x10000;

      }

      uVar26 = uVar23 + (uVar21 << 16);

      uVar20 = iVar8 + (unsigned int)(uVar26 < uVar23) + (uVar21 >> 0x10) +

               (uVar20 >> 0x10) * (uVar1 >> 0x10);

      if ((int)-(unsigned int)((int)uVar2 < 0) < 0) {

        uVar20 = ~uVar20;

        if (uVar26 == 0) {

          uVar20 = uVar20 + 1;

        }

        else {

          uVar26 = ~uVar26 + 1;

        }

      }

      if (((unsigned char)(uVar19 >> 1) & 1) == 1) {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + (uVar7 & 0xffff);

        if ((int)uVar7 < -0x8000) {

          uVar7 = 0xffff8000;

          uVar26 = 0;

        }

        if (0x7fff < (int)uVar7) {

          uVar7 = 0x7fff;

          uVar26 = 0xffffffff;

        }

        uVar7 = uVar7 & 0xffff;

      }

      else {

        uVar26 = uVar25 + uVar26;

        uVar7 = uVar20 + (uVar26 < uVar25) + uVar7;

      }

      *(unsigned int *)(puVar3 + 8) = (uVar7 << 0x10 | uVar26 >> 0x10) + puVar14[0xb];

      iVar8 = *(int *)(puVar3 + 8);

      *(unsigned short *)(puVar4 + 6) = (unsigned short)(iVar8 <= iVar17);

      iVar8 = (unsigned int)(iVar8 <= iVar17) + (int)*(short *)(puVar4 + 4) +

              (int)*(short *)(puVar4 + 2) + (int)*(short *)puVar4;

      uVar19 = uVar18 | iVar8 == 0;

      if (((unsigned char)uVar19 & 1) != 1) {

        if (iVar8 == 4) {

          uVar7 = 4;

          uVar19 = uVar18;

          goto LAB_0602a1b6;

        }

        (*(int(*)())(*(int *)(0x0602A1E0 + (iVar8 << 2))))(0x0608A70C,0x0608A704,puVar14 + 9,puVar14 + 0xc);

        uVar19 = uVar18;

      }

      puVar5 = (short *)0x0608A76C;

      puVar4 = (char *)0x0608AC20;

      puVar3 = (char *)0x0608A70C;

      iVar8 = *(int *)0x060620D0;

      puVar10 = (int *)-256;

      uVar11 = *(int *)(0x0608A70C + 8);

      puVar10[4] = 0xa0;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 4);

      iVar9 = puVar10[7];

      *(int *)puVar5 = (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)puVar3) >> 0x20);

      *(int *)(puVar5 + 4) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      puVar6 = (char *)0x0608A6FC;

      iVar9 = *(int *)puVar5;

      iVar12 = *(int *)(puVar5 + 4);

      *(short *)0x0608A6FC = 0;

      uVar19 = uVar19 & 0xfffffffe;

      if (PTR_DAT_06029ea8 < iVar9) {

        *(short *)puVar6 = 1;

      }

      else if (iVar9 < DAT_06029ed4) {

        *(short *)puVar6 = 1;

      }

      else if (DAT_06029ee2 < iVar12) {

        *(short *)puVar6 = 1;

      }

      else if (iVar12 < DAT_06029f2a) {

        *(short *)puVar6 = 1;

      }

      puVar10 = (int *)-256;

      uVar11 = *(int *)(puVar3 + 0x14);

      puVar10[4] = 0xa0;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x10);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 8) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0xc)) >> 0x20);

      *(int *)(puVar5 + 0xc) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 8);

      iVar12 = *(int *)(puVar5 + 0xc);

      *(short *)(puVar6 + 2) = 0;

      if (DAT_06029f30 < iVar9) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (iVar9 < DAT_06029f3e) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (DAT_06029f4c < iVar12) {

        *(short *)(puVar6 + 2) = 1;

      }

      else if (iVar12 < DAT_06029f94) {

        *(short *)(puVar6 + 2) = 1;

      }

      puVar10 = (int *)-256;

      uVar11 = *(int *)(puVar3 + 0x20);

      puVar10[4] = 0xa0;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x1c);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 0x10) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0x18)) >> 0x20);

      *(int *)(puVar5 + 0x14) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 0x10);

      iVar12 = *(int *)(puVar5 + 0x14);

      *(short *)(puVar6 + 4) = 0;

      if (DAT_06029f9a < iVar9) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (iVar9 < DAT_06029fa8) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (DAT_06029fb6 < iVar12) {

        *(short *)(puVar6 + 4) = 1;

      }

      else if (iVar12 < DAT_06029ffe) {

        *(short *)(puVar6 + 4) = 1;

      }

      puVar10 = (int *)-256;

      uVar11 = *(int *)(puVar3 + 0x2c);

      puVar10[4] = 0xa0;

      *puVar10 = uVar11;

      puVar10[5] = 0;

      iVar12 = *(int *)(puVar3 + 0x28);

      iVar9 = puVar10[7];

      *(int *)(puVar5 + 0x18) =

           (int)((unsigned long long)((long long)iVar9 * (long long)*(int *)(puVar3 + 0x24)) >> 0x20);

      *(int *)(puVar5 + 0x1c) = (int)((unsigned long long)((long long)iVar9 * (long long)-iVar12) >> 0x20);

      iVar9 = *(int *)(puVar5 + 0x18);

      iVar12 = *(int *)(puVar5 + 0x1c);

      *(short *)(puVar6 + 6) = 0;

      if (DAT_0602a004 < iVar9) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (iVar9 < DAT_0602a012) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (DAT_0602a020 < iVar12) {

        *(short *)(puVar6 + 6) = 1;

      }

      else if (iVar12 < DAT_0602a050) {

        *(short *)(puVar6 + 6) = 1;

      }

      if (((((int)0xFFFFFF50 <= *(int *)puVar5) ||

           ((int)0xFFFFFF50 <= *(int *)(puVar5 + 8))) ||

          ((int)0xFFFFFF50 <= *(int *)(puVar5 + 0x10))) ||

         (uVar7 = *(unsigned int *)(puVar5 + 0x18), (int)0xFFFFFF50 <= (int)uVar7)) {

        uVar18 = uVar19 | *(int *)puVar5 < 0x000000B0;

        if (((((unsigned char)uVar18 & 1) != 1) &&

            (uVar18 = uVar19 | *(int *)(puVar5 + 8) < 0x000000B0, ((unsigned char)uVar18 & 1) != 1)) &&

           (uVar18 = uVar19 | *(int *)(puVar5 + 0x10) < 0x000000B0, ((unsigned char)uVar18 & 1) != 1)) {

          uVar7 = *(unsigned int *)(puVar5 + 0x18);

          uVar18 = uVar19 | (int)uVar7 < 0x000000B0;

          uVar19 = uVar18;

          if (((unsigned char)uVar18 & 1) != 1) goto LAB_0602a1b6;

        }

        uVar18 = uVar18 & 0xfffffffe;

        if ((((int)0xFFFFFF81 <= *(int *)(puVar5 + 4)) ||

            ((int)0xFFFFFF81 <= *(int *)(puVar5 + 0xc))) ||

           (((int)0xFFFFFF81 <= *(int *)(puVar5 + 0x14) ||

            (uVar7 = *(unsigned int *)(puVar5 + 0x1c), uVar19 = uVar18, (int)0xFFFFFF81 <= (int)uVar7)

            ))) {

          uVar19 = uVar18 | *(int *)(puVar5 + 4) < 0x00000051;

          if (((((unsigned char)uVar19 & 1) != 1) &&

              (uVar19 = uVar18 | *(int *)(puVar5 + 0xc) < 0x00000051, ((unsigned char)uVar19 & 1) != 1)) &&

             (uVar19 = uVar18 | *(int *)(puVar5 + 0x14) < 0x00000051, ((unsigned char)uVar19 & 1) != 1)) {

            uVar7 = *(unsigned int *)(puVar5 + 0x1c);

            uVar19 = uVar18 | (int)uVar7 < 0x00000051;

            if (((unsigned char)uVar19 & 1) != 1) goto LAB_0602a1b6;

          }

          iVar9 = (int)*(short *)(puVar6 + 6) +

                  (int)*(short *)puVar6 + (int)*(short *)(puVar6 + 2) + (int)*(short *)(puVar6 + 4);

          if (iVar9 != 4) {

            if (iVar9 != 0) {

              (*(int(*)())(*(int *)(0x0602A1F0 + (iVar9 << 2))))(puVar5,puVar6);

            }

            *(short *)(puVar4 + iVar8 * 0x18 + 8) = (short)*(int *)puVar5;

            *(short *)(puVar4 + iVar8 * 0x18 + 10) = (short)*(int *)(puVar5 + 4);

            *(short *)(puVar4 + iVar8 * 0x18 + 0xc) = (short)*(int *)(puVar5 + 8);

            *(short *)(puVar4 + iVar8 * 0x18 + 0xe) = (short)*(int *)(puVar5 + 0xc);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x10) = (short)*(int *)(puVar5 + 0x10);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x12) = (short)*(int *)(puVar5 + 0x14);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x14) = (short)*(int *)(puVar5 + 0x18);

            *(short *)(puVar4 + iVar8 * 0x18 + 0x16) = (short)*(int *)(puVar5 + 0x1c);

            *(short *)(puVar4 + iVar8 * 0x18 + 6) = *(short *)((int)puVar15 + -10);

            puVar4[iVar8 * 0x18 + 4] = (unsigned char)((unsigned int)(int)*(short *)(puVar15 + -3) >> 4) & 0xf;

            puVar4[iVar8 * 0x18 + 5] = param_3;

            uVar19 = (*(int(*)())(*(int *)(0x0602A200 + ((int)*(short *)(puVar15 + -3) & 7U) << 2)))(*(int *)(0x0608A70C + 0x14),

                                *(int *)(0x0608A70C + 0x20),

                                *(int *)(0x0608A70C + 0x2c));

            return uVar19;

          }

          uVar7 = 4;

          uVar19 = uVar19 & 0xfffffffe;

        }

      }

    }

LAB_0602a1b6:

    param_4 = param_4 + -1;

    in_sr = uVar19 & 0xfffffffe | (unsigned int)(param_4 == 0);

    puVar15 = puVar16;

    if (((unsigned char)in_sr & 1) == 1) {

      return uVar7;

    }

  } while( 1 );

}
