#include "game.h"

extern int DAT_0603ee76;
extern int DAT_0603ef2a;
extern int DAT_0603ef8a;
extern int DAT_0603eff4;
extern int DAT_0603f2c2;
extern int DAT_0603f5b8;
extern int DAT_0603f682;
extern int DAT_0603f8ac;
extern int DAT_0603f8ae;
extern int DAT_0603fb22;
extern int DAT_0603fb24;
extern int DAT_0603fcb6;
extern int DAT_0603fe2e;
extern int FUN_0603f2e0();
extern int FUN_0603f342();
extern int FUN_0603f3da();
extern int FUN_0603f3f6();
extern int FUN_0603f4e0();
extern int FUN_0603f500();
extern char FUN_0603f534();
extern unsigned int FUN_0603f582();
extern void cd_parse_dir_entry();
extern int FUN_0603f92c();
extern char FUN_0603f970();
extern void cd_buf_request_read();
extern void FUN_0603fce4();
extern void FUN_0603ff9c();
extern void FUN_0603ffe6();
extern int PTR_DAT_0603f180;
extern int PTR_DAT_0603f8b0;
extern int PTR_DAT_0603fe30;

/* scroll_plane_rotate -- Apply 2D rotation to VDP2 scroll plane coefficients.
 * Selects active scroll plane (0x060635A8: 1→plane 0, 2→plane 1).
 * Computes sin/cos of param_1 via fixedpoint_sine (0x0603D9EC) and
 * fixedpoint_cosine (0x0603DA88). Rotates 3 coefficient pairs
 * (6 values total) in scroll table at 0x060A53B8 (stride 0x24 per
 * plane) using 2D rotation: x' = x*cos + y*sin, y' = y*cos - x*sin.
 * Fixed-point multiply via 0x0603C08C. Copies results to scroll
 * output buffer at 0x060A3E68 (stride 0x80 per plane). */
int FUN_0603eacc(param_1)
    int param_1;
{
  int sin_val, cos_val;
  int plane_idx;
  int orig_a, orig_b;
  int rot_a, rot_b;
  int *coeff;

  plane_idx = *(int *)0x060635A8;
  if (plane_idx == 1) {
    plane_idx = 0;
  } else if (plane_idx == 2) {
    plane_idx = 1;
  } else {
    return plane_idx;                                    /* invalid plane */
  }
  sin_val = (*(int(*)())0x0603D9EC)(param_1);            /* fixedpoint_sine */
  cos_val = (*(int(*)())0x0603DA88)(param_1);            /* fixedpoint_cosine */
  coeff = (int *)(0x060A53B8 + (char)((char)plane_idx * '$')); /* coefficient array */
  /* rotate pair 0 (coeff[0], coeff[1]) */
  orig_a = coeff[0];
  orig_b = coeff[1];
  coeff[0] = (*(int(*)())0x0603C08C)(orig_b, sin_val) +
             (*(int(*)())0x0603C08C)(orig_a, cos_val);   /* a*cos + b*sin */
  coeff[1] = (*(int(*)())0x0603C08C)(orig_b, cos_val) -
             (*(int(*)())0x0603C08C)(orig_a, sin_val);   /* b*cos - a*sin */
  /* rotate pair 1 (coeff[3], coeff[4]) */
  orig_a = coeff[3];
  orig_b = coeff[4];
  coeff[3] = (*(int(*)())0x0603C08C)(orig_b, sin_val) +
             (*(int(*)())0x0603C08C)(orig_a, cos_val);
  coeff[4] = (*(int(*)())0x0603C08C)(orig_b, cos_val) -
             (*(int(*)())0x0603C08C)(orig_a, sin_val);
  /* rotate pair 2 (coeff[6], coeff[7]) */
  orig_a = coeff[6];
  orig_b = coeff[7];
  coeff[6] = (*(int(*)())0x0603C08C)(orig_b, sin_val) +
             (*(int(*)())0x0603C08C)(orig_a, cos_val);
  rot_b = (*(int(*)())0x0603C08C)(orig_b, cos_val) -
          (*(int(*)())0x0603C08C)(orig_a, sin_val);
  coeff[7] = rot_b;
  /* copy rotated coefficients to scroll output buffer */
  *(int *)(0x060A3E68 + (unsigned int)(plane_idx << 7) + 0x1c) = coeff[0];
  *(int *)(0x060A3E68 + (unsigned int)(plane_idx << 7) + 0x20) = coeff[1];
  *(int *)(0x060A3E68 + (unsigned int)(plane_idx << 7) + 0x28) = coeff[3];
  *(int *)(0x060A3E68 + (unsigned int)(plane_idx << 7) + 0x2c) = coeff[4];
  return rot_b;
}

/* scroll_plane_angle_accumulate -- accumulate rotation angle and update scroll coefficients.
 *   param_1 = angle delta (fixed-point, wraps at 0x01680000 = 360 degrees).
 *   Selects active scroll plane via 0x060635A8 (1→plane 0, 2→plane 1).
 *   Angle stored at 0x060A4C70[plane]. If rotation is active (0x060A4C4C flags),
 *   computes sin/cos via fixedpoint_sine (0x0603D9EC) / fixedpoint_cosine (0x0603DA88).
 *   Rotates coefficient pair from 0x060A53A8/0x060A53B0 into output at 0x060A3E68
 *   (stride 0x80 per plane). Stores rotation matrix: [cos,-sin | sin,cos] at [2..6]. */
int scroll_plane_angle_accumulate(param_1)
    int param_1;
{
  char *angle_base = (char *)0x060A4C70;       /* per-plane accumulated angle */
  char *fpmul = (int *)0x0603C08C;             /* fixed-point multiply */
  int plane_sel;
  int cos_val, sin_val;
  int coeff_a, coeff_b;
  int rot_a, rot_b;
  int *coeff_src_a;
  int *coeff_src_b;
  int plane_off;
  int *out_coeffs;
  int *angle_ptr;
  plane_sel = *(int *)0x060635A8;              /* active scroll plane selector */
  if (plane_sel == 1) {
    plane_sel = 0;
  } else {
    if (plane_sel != 2) {
      return plane_sel;
    }
    plane_sel = 1;
  }
  plane_off = (plane_sel << 2);
  if ((*(int *)(0x060A4C4C + plane_off) == 0) ||
     ((*(int *)(0x060A4C60 + plane_off) == 0 && (*(int *)(0x060A4C78 + plane_off) == 0)))) {
    /* Rotation active — accumulate angle */
    param_1 = *(int *)(0x060A4C70 + (plane_sel << 2)) + param_1;
    *(int *)(0x060A4C70 + (plane_sel << 2)) = param_1;
    if ((int)0x01680000 <= param_1) {          /* wrap at 360 degrees */
      *(int *)(angle_base + (plane_sel << 2)) = *(int *)(angle_base + (plane_sel << 2)) - (int)0x01680000;
    }
    if (*(int *)(angle_base + (plane_sel << 2)) < 0) {
      *(char **)(angle_base + (plane_sel << 2)) = 0x01680000 + *(int *)(angle_base + (plane_sel << 2));
    }
    plane_off = (plane_sel << 2);
    angle_ptr = (int *)(angle_base + plane_off);
    out_coeffs = (int *)(0x060A3E68 + (plane_sel << 7));  /* output buffer (stride 0x80) */
    coeff_src_a = (int *)(0x060A53A8 + plane_off);        /* original coeff A */
    coeff_a = *coeff_src_a;
    cos_val = (*(int(*)())0x0603DA88)(*angle_ptr);         /* fixedpoint_cosine */
    rot_a = (*(int(*)())fpmul)(cos_val, coeff_a);          /* cos * A */
    coeff_src_b = (int *)(0x060A53B0 + plane_off);        /* original coeff B */
    coeff_b = *coeff_src_b;
    sin_val = (*(int(*)())0x0603D9EC)(*angle_ptr);         /* fixedpoint_sine */
    rot_b = (*(int(*)())fpmul)(-sin_val, coeff_b);        /* -sin * B */
    *out_coeffs = (coeff_a - rot_a) - rot_b;              /* rotated coeff [0] */
    coeff_b = *coeff_src_b;
    coeff_a = *coeff_src_a;
    cos_val = (*(int(*)())0x0603D9EC)(*angle_ptr);         /* sin for cross term */
    rot_a = (*(int(*)())fpmul)(cos_val, coeff_a);          /* sin * A */
    rot_b = *coeff_src_b;
    cos_val = (*(int(*)())0x0603DA88)(*angle_ptr);         /* cos for cross term */
    rot_b = (*(int(*)())fpmul)(cos_val, rot_b);            /* cos * B */
    out_coeffs[1] = (coeff_b - rot_a) - rot_b;            /* rotated coeff [1] */
    out_coeffs[2] = 0;                                    /* zero padding */
    sin_val = (*(int(*)())0x0603D9EC)(*angle_ptr);
    out_coeffs[3] = -sin_val;                             /* -sin */
    cos_val = (*(int(*)())0x0603DA88)(*angle_ptr);
    out_coeffs[4] = cos_val;                              /* cos */
    cos_val = (*(int(*)())0x0603DA88)(*angle_ptr);
    out_coeffs[5] = cos_val;                              /* cos (redundant) */
    sin_val = (*(int(*)())0x0603D9EC)(*angle_ptr);
    out_coeffs[6] = sin_val;                              /* sin */
  } else {
    /* Rotation paused — reset angle */
    plane_off = (plane_sel << 2);
    *(int *)(0x060A4C70 + plane_off) = 0;
  }
  return plane_off;
}

/* light_state_bitfield_update -- Update 8 light state bytes from bitmask.
 * For each bit in param_2 (change mask): if the corresponding bit in
 * param_1 (new state) is set, OR the target byte with param_4 (set mask);
 * otherwise AND with param_5 (clear mask). Maps 8 bit positions to
 * 8 bytes in param_3: bit 2/3→[1], bit 8/0x80→[0], bit 0x10→[3],
 * bit 0x20→[2], bit 1→[5], bit 0x100→[4], bit 0x10000→[7], bit 0x20000→[6].
 * Used for VDP2 special color calculation and priority enable registers. */
unsigned int FUN_0603edc4(param_1, param_2, param_3, param_4, param_5)
    unsigned int param_1;
    unsigned int param_2;
    unsigned char *param_3;
    unsigned char param_4;
    unsigned char param_5;
{
  unsigned int result;
  result = (unsigned int)(char)param_5;
  /* byte [1]: bits 2 and 4 */
  if (((param_2 & 4) != 0) || ((param_2 & 2) != 0)) {
    if (((param_1 & 4) == 0) && ((param_1 & 2) == 0)) {
      result = (int)(char)param_3[1] & (unsigned int)param_5;
    } else {
      result = (int)(char)param_3[1] | (unsigned int)param_4;
    }
    param_3[1] = (unsigned char)result;
  }
  /* byte [0]: bits 8 and 0x80 */
  if (((param_2 & 8) != 0) || ((0x80 & param_2) != 0)) {
    if (((param_1 & 8) == 0) && ((0x80 & param_1) == 0)) {
      *param_3 = *param_3 & param_5;
    } else {
      *param_3 = *param_3 | param_4;
    }
  }
  /* byte [3]: bit 0x10 */
  if ((param_2 & 0x10) != 0) {
    if ((param_1 & 0x10) == 0) {
      result = (int)(char)param_3[3] & (unsigned int)param_5;
    } else {
      result = (int)(char)param_3[3] | (unsigned int)param_4;
    }
    param_3[3] = (unsigned char)result;
  }
  /* byte [2]: bit 0x20 */
  if ((param_2 & 0x20) != 0) {
    if ((param_1 & 0x20) == 0) {
      result = (int)(char)param_3[2] & (unsigned int)param_5;
    } else {
      result = (int)(char)param_3[2] | (unsigned int)param_4;
    }
    param_3[2] = (unsigned char)result;
  }
  /* byte [5]: bit 1 */
  if ((param_2 & 1) != 0) {
    if ((param_1 & 1) == 0) {
      result = (int)(char)param_3[5] & (unsigned int)param_5;
    } else {
      result = (int)(char)param_3[5] | (unsigned int)param_4;
    }
    param_3[5] = (unsigned char)result;
  }
  /* byte [4]: bit 0x100 */
  if ((0x100 & param_2) != 0) {
    if ((0x100 & param_1) == 0) {
      result = (int)(char)param_3[4] & (unsigned int)param_5;
    } else {
      result = (int)(char)param_3[4] | (unsigned int)param_4;
    }
    param_3[4] = (unsigned char)result;
  }
  /* byte [7]: bit 0x10000 */
  if (((unsigned int)0x00010000 & param_2) != 0) {
    if (((unsigned int)0x00010000 & param_1) == 0) {
      result = (int)(char)param_3[7] & (unsigned int)param_5;
    } else {
      result = (int)(char)param_3[7] | (unsigned int)param_4;
    }
    param_3[7] = (unsigned char)result;
  }
  /* byte [6]: bit 0x20000 */
  if ((param_2 & (unsigned int)0x00020000) != 0) {
    if ((param_1 & (unsigned int)0x00020000) == 0) {
      result = (int)(char)param_3[6] & (unsigned int)param_5;
    } else {
      result = (int)(char)param_3[6] | (unsigned int)param_4;
    }
    param_3[6] = (unsigned char)result;
  }
  return result;
}

/* cd_calc_sectors_remaining -- Calculate number of sectors available for transfer.
 * Computes from file size (+0x10) minus current position (+0x14),
 * scaled by DAT_0603ef8a, shifted right 11. Clamps to param_2 (or
 * 0x7FFFFFFF if param_2 == 0xFFFF). If param_3 is non-null, stores
 * byte count (sectors << 11) and adjusts for CD sector alignment. */
char * FUN_0603ef64(int param_1, char *param_2, int *param_3)
{
  int iVar1;
  char *puVar2;

  if (param_2 == 0x0000FFFF) {
    param_2 = (int *)0x7FFFFFFF;
  }
  puVar2 = (char *)
           ((unsigned int)((int)DAT_0603ef8a + (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14))) >> 0xb);
  if (param_2 < puVar2) {
    puVar2 = param_2;
  }
  if ((((param_3 != (int *)0x0) &&
       (*param_3 = (int)((int)(int)puVar2 << 11),
       *(int *)(param_1 + 0x10) < *(int *)(param_1 + 0x14) + (int)((int)(int)puVar2 << 11))) &&
      (iVar1 = (*(int(*)())0x06036BE4)(), *param_3 != 0)) && (iVar1 != 0)) {
    *param_3 = *param_3 - (DAT_0603eff4 - iVar1);
  }
  return puVar2;
}

/* cd_flush_and_open -- Flush pending CD write, then open file for access.
 * If param_1 is valid: issues write request (0x0603B31C), polls until
 * complete (0x0603B424 loop).
 * Then opens file based on param_2[0]: 0 = FUN_0603f2e0 (by sector),
 * non-zero = FUN_0603f342 (by name). */
int FUN_0603f0fc(int param_1, int *param_2, int param_3)
{
  int iVar2;
  int uVar3;

  if (param_1 != 0) {
    (*(int(*)())0x0603B31C)(param_1, param_3);   /* start write */
    do {
      iVar2 = (*(int(*)())0x0603B424)(param_1);  /* poll */
    } while (iVar2 != 0);
  }

  if (*param_2 == 0) {
    uVar3 = FUN_0603f2e0(param_1, param_2[2], param_2[1]);
  } else {
    uVar3 = FUN_0603f342(param_1, param_2[2], param_2[1]);
  }
  return uVar3;
}

/* cd_directory_entry_search -- Search CD directory for matching entry.
 * Reads TOC entries via cd_read_toc (0x06036D14). First two calls
 * skip the header entries (returns 0/1). Then iterates directory
 * entries (24 bytes each) starting at param_1+0x30, reading 12 bytes
 * from CD (0x06036D94) into each entry. Checks flag byte at +0xB
 * against bit mask. Returns entry index or -1 if not found. */
int cd_directory_entry_search(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
    unsigned short flag_mask = PTR_DAT_0603f180;
    int toc_result;
    int read_result;
    int entry_idx;

    /* Read first TOC entry (volume descriptor) */
    toc_result = (*(int(*)())0x06036D14)();    /* cd_read_toc */
    if (toc_result == 0) {
        return 0;                              /* no TOC — empty disc */
    }

    /* Read second TOC entry (root directory) */
    toc_result = (*(int(*)())0x06036D14)();    /* cd_read_toc */
    if (toc_result == 0) {
        return 1;                              /* only root entry */
    }

    /* Search directory entries starting at index 2 */
    entry_idx = 2;
    param_1 = param_1 + 0x30;                 /* skip header area */
    if (2 < param_3) {
        do {
            /* Read 12 bytes of directory entry data from CD */
            read_result = (*(int(*)())0x06036D94)(param_2, param_1 + 0xc, 0xc);
            if (read_result == 0) {
                return entry_idx;              /* read failed — return last good */
            }
            /* Check if entry's flag byte matches search mask */
            if ((*(unsigned char *)(param_1 + 0xb) & flag_mask) != 0) break;
            entry_idx++;
            param_1 = param_1 + 0x18;         /* next entry (24 bytes) */
        } while (entry_idx < param_3);
    }

    return -1;                                 /* not found */
}

/* cd_init_and_read_toc -- Initialize CD drive and read table of contents.
 * Connects to CD subsystem (0x06041470) with 0x00FFFFFF timeout,
 * allocates 32KB read buffer (0x06041884), polls until ready,
 * then reads TOC (0x06036A98). Returns entry count + 2 on success,
 * or -1 on any failure (no disc, timeout, TOC read error). */
int cd_init_and_read_toc()
{
    int result;
    int entry_count;
    char toc_header[4];
    char toc_data[8];

    /* Try connecting to CD with sector from CD_STATE_A+0xC8 */
    result = (*(int(*)())0x06041470)(0x00FFFFFF, *(int *)(CD_STATE_A + 0xc8));
    if (result == -5) {
        return -1;                             /* no disc present */
    }

    /* Allocate 32KB CD read buffer */
    (*(int(*)())0x06041884)(0x00008000);       /* cd_alloc_buffer */

    /* Poll until CD is ready */
    while (result != 0) {
        result = (*(int(*)())0x06041698)();    /* cd_poll_ready */
        if (result == -0xc) {
            return -1;                         /* fatal error */
        }
        result = (*(int(*)())0x06041470)(0x00FFFFFF, *(int *)(*(int *)0x060A4D14 + 0xc8));
    }

    /* Finalize CD initialization */
    result = (*(int(*)())0x0604188C)();        /* cd_finalize_init */
    if (result != 0) {
        return -1;
    }

    /* Read table of contents */
    result = (*(int(*)())0x06036A98)(toc_header, &entry_count, toc_data);
    if (result != 0) {
        return -1;
    }

    return entry_count + 2;                    /* +2 for volume descriptor + root */
}

/* cd_dir_read_simple -- Read directory entries (simple variant).
 * Like cd_dir_read_entries but uses 0xC-byte records without
 * supplementary data validation. Marks last entry with bit 7. */
int FUN_0603f2e0(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{
  int iVar1;
  char local_44 [32];
  char auStack_24 [24];

  FUN_0603f3da(auStack_24, param_1, param_3, param_4, param_1);

  iVar1 = 0;
  while ((0 < param_3 && (FUN_0603f582(auStack_24, local_44), local_44[0] != '\0'))) {
    cd_parse_dir_entry(param_2, local_44); /* parse entry into 0xC-byte record */
    param_2 = param_2 + 0xc; /* advance to next record slot */
    param_3 = param_3 + -1;
    iVar1 = iVar1 + 1;
  }

  *(unsigned char *)(param_2 + -1) = *(unsigned char *)(param_2 + -1) | 0x80; /* mark last entry */
  return iVar1;
}

/* cd_dir_read_entries -- Read directory entries from CD filesystem.
 * Iterates through up to param_3 entries, populating 0x18-byte records
 * at param_2. First 3 entries always accepted; subsequent entries
 * validated via memcmp at 0x06036D94. Returns number of entries read. */
int FUN_0603f342(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{
  int iVar2;
  int iVar3;
  char local_4c [16];
  char auStack_3c [16];
  char auStack_2c [24];
  int (*memcmp_fn)(int, char *, int) = (int (*)(int, char *, int))0x06036D94;
  int (*memcpy_fn)(int, char *, int) = (int (*)(int, char *, int))0x06036DDC;

  FUN_0603f3da(auStack_2c, param_1, param_3, param_4, param_1);

  iVar3 = 0;
  while ((0 < param_3 && (FUN_0603f582(auStack_2c, local_4c), local_4c[0] != '\0'))) {
    if ((iVar3 < 3) ||
       (iVar2 = memcmp_fn(param_2 + -0xc, auStack_3c, 0xc), iVar2 != 0)) {
      cd_parse_dir_entry(param_2, local_4c); /* parse entry into record */
      memcpy_fn(param_2 + 0xc, auStack_3c, 0xc); /* copy 12-byte supplementary data */
    }
    param_2 = param_2 + 0x18; /* advance to next record slot */
    iVar3 = iVar3 + 1;
    param_3 = param_3 + -1;
  }

  *(unsigned char *)(param_2 + -0xd) = *(unsigned char *)(param_2 + -0xd) | 0x80; /* mark last entry */
  return iVar3;
}

/* cd_read_word -- Read 16-bit word from CD buffer via DMA double-read pattern.
 * First read primes the bus, second read gets actual data. */
int FUN_0603f4e0(int addr)
{
    short result[2];
    volatile int saved_addr;
    char dummy_buf[8];

    saved_addr = addr;
    FUN_0603f3f6(addr, dummy_buf, 2);         /* prime DMA bus */
    FUN_0603f3f6(saved_addr, result, 2);      /* actual read */
    return (int)result[0];
}

/* cd_read_long -- Read 32-bit long from CD buffer via DMA double-read pattern.
 * Same prime-then-read pattern as cd_read_word but for 4 bytes. */
int FUN_0603f500(int addr)
{
    struct { int val; int saved; char buf[8]; } frame;

    frame.saved = addr;
    FUN_0603f3f6(addr, frame.buf, 4);         /* prime DMA bus */
    FUN_0603f3f6(frame.saved, &frame.val, 4); /* actual read */
    return frame.val;
}

/* cd_buf_advance_sector -- Advance to next CD sector in buffer.
 * Reads current sector status. If empty (0) and not at end sector:
 *   requests next 0x800-byte sector read from CD (0x0603B21C),
 *   resets read offset, re-reads status.
 * Returns sector status byte (0 = empty, non-zero = data ready). */
char FUN_0603f534(int *param_1)
{
  int iVar1;
  char local_10[4];
  char acStack_c[8];

  FUN_0603f3f6(param_1, acStack_c, 1);
  if ((acStack_c[0] == '\0') &&
     (iVar1 = param_1[3], param_1[3] = iVar1 + 1, iVar1 + 1 != param_1[4])) {
    (*(int(*)())0x0603B21C)(*param_1, 1, param_1[1], 0x800);
    param_1[2] = 0;                     /* reset read offset */
    FUN_0603f3f6(param_1, local_10, 1);
    acStack_c[0] = local_10[0];
  }
  return acStack_c[0];
}

/* cd_file_header_parse -- Parse CD file header and extract metadata.
 * param_1 = file descriptor, param_2 = output buffer (>= 0x74 bytes).
 * If file descriptor is null, clears output. Otherwise reads header
 * fields into structured output: flags, sizes, offsets, timestamps.
 * Uses multi-byte extraction from CD sector buffer with byte-level
 * parsing of dates, permissions, and extent information. */
unsigned int FUN_0603f582(param_1, param_2)
    int *param_1;
    unsigned char *param_2;
{
  int bVar1;
  unsigned char *pbVar2;
  unsigned int uVar3;
  int iVar4;
  int uVar5;
  short uVar6;
  unsigned char *pbVar7;
  unsigned char local_74;
  unsigned int uStack_70;
  unsigned char abStack_6c [4];
  short auStack_68 [2];
  unsigned char abStack_64 [4];
  char acStack_60 [4];
  unsigned char abStack_5c [4];
  unsigned char abStack_58 [4];
  unsigned char abStack_54 [4];
  unsigned char abStack_50 [4];
  unsigned char abStack_4c [4];
  unsigned char bStack_48;
  char auStack_44 [4];
  char auStack_40 [4];
  char auStack_3c [4];
  char auStack_38 [4];
  char auStack_34 [4];
  char auStack_30 [4];
  char auStack_2c [4];
  char auStack_28 [4];
  unsigned char *pbStack_24;

  bVar1 = 0;
  if (*param_1 == 0) {
    *param_2 = 0;
    return 0;
  }
  uVar3 = FUN_0603f534(param_1);
  *param_2 = (unsigned char)uVar3;
  if (*param_2 == 0) {
    return uVar3;
  }
  FUN_0603f3f6(param_1,auStack_28,1);
  iVar4 = FUN_0603f500(param_1);
  *(int *)(param_2 + 4) = iVar4 + DAT_0603f682;
  uVar5 = FUN_0603f500(param_1);
  *(int *)(param_2 + 8) = uVar5;
  for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
    FUN_0603f3f6(param_1,auStack_2c,1);
  }
  FUN_0603f3f6(param_1,abStack_4c,1);
  bStack_48 = abStack_4c[0];
  FUN_0603f3f6(param_1,abStack_50,1);
  param_2[0xe] = abStack_50[0];
  FUN_0603f3f6(param_1,abStack_54,1);
  param_2[0xf] = abStack_54[0];
  FUN_0603f4e0(param_1);
  FUN_0603f3f6(param_1,abStack_58,1);
  uStack_70 = abStack_58[0] + 0x21;
  pbVar7 = param_2 + 0x10;
  iVar4 = 0;
  do {
    uVar3 = (unsigned int)abStack_58[0];
    if (8 < uVar3) {
      uVar3 = 8;
    }
    pbVar2 = pbStack_24;
    if ((int)uVar3 <= iVar4) break;
    FUN_0603f3f6(param_1,abStack_5c,1);
    local_74 = abStack_5c[0];
    iVar4 = iVar4 + 1;
    pbVar2 = pbStack_24;
    if (abStack_5c[0] == 0x3b) break;
    *pbVar7 = abStack_5c[0];
    pbVar7 = pbVar7 + 1;
    pbVar2 = pbVar7;
  } while (abStack_5c[0] != 0x2e);
  pbStack_24 = pbVar2;
  if (local_74 == 0x3b) {
    for (; iVar4 < (int)(unsigned int)abStack_58[0]; iVar4 = iVar4 + 1) {
      FUN_0603f3f6(param_1,auStack_30,1);
    }
  }
  else if (local_74 != 0x2e) {
    while (iVar4 < (int)(unsigned int)abStack_58[0]) {
      FUN_0603f3f6(param_1,acStack_60,1);
      iVar4 = iVar4 + 1;
      if (acStack_60[0] == '.') {
        pbStack_24 = pbVar7 + 1;
        *pbVar7 = 0x2e;
        pbVar7 = pbStack_24;
        break;
      }
      bVar1 = 1;
    }
  }
LAB_0603f748:
  if (iVar4 < (int)(unsigned int)abStack_58[0]) {
    FUN_0603f3f6(param_1,abStack_64,1);
    iVar4 = iVar4 + 1;
    if (abStack_64[0] == 0x3b) goto LAB_0603f716;
    if ((int)pbVar7 - (int)pbStack_24 < 4) {
      if ((int)pbVar7 - (int)(param_2 + 0x10) < 0xc) {
        *pbVar7 = abStack_64[0];
        pbVar7 = pbVar7 + 1;
      }
    }
    else {
      bVar1 = 1;
    }
    goto LAB_0603f748;
  }
LAB_0603f74e:
  if ((int)pbVar7 - (int)(param_2 + 0x10) < 0xc) {
    *pbVar7 = 0;
  }
  if ((abStack_58[0] + 1 & 1) != 0) {
    FUN_0603f3f6(param_1,auStack_38,1);
    uStack_70 = abStack_58[0] + 0x22;
  }
  if (param_2[0x10] == 0) {
    (*(int(*)())0x06035FEC)();
  }
  else if (param_2[0x10] == 1) {
    (*(int(*)())0x06035FEC)();
  }
  if (uStack_70 < *param_2) {
    FUN_0603f3f6(param_1,auStack_3c,4);
    FUN_0603f3f6(param_1,auStack_68,2);
    *(short *)(param_2 + 0xc) = auStack_68[0];
    FUN_0603f3f6(param_1,auStack_40,2);
    FUN_0603f3f6(param_1,abStack_6c,1);
    uVar3 = 0x1d;
    param_2[0x1d] = abStack_6c[0];
    for (iVar4 = uStack_70 + 9; iVar4 < (int)(unsigned int)*param_2; iVar4 = iVar4 + 1) {
      uVar3 = FUN_0603f3f6(param_1,auStack_44,1);
    }
  }
  else {
    if ((bStack_48 & 2) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = SUB42(0x00008000,0);
    }
    *(short *)(param_2 + 0xc) = uVar6;
    uVar3 = 0x1d;
    param_2[0x1d] = 0;
  }
  if (bVar1) {
    uVar3 = (int)*(short *)(param_2 + 0xc) | 0x80;
    *(short *)(param_2 + 0xc) = (short)uVar3;
  }
  return uVar3;
LAB_0603f716:
  for (; iVar4 < (int)(unsigned int)abStack_58[0]; iVar4 = iVar4 + 1) {
    FUN_0603f3f6(param_1,auStack_34,1);
  }
  goto LAB_0603f74e;
}

/* cd_parse_dir_entry -- Parse raw ISO9660 directory record into compact form.
 * Reads LBA extent (param_2+4), size (param_2+8), and flags (param_2+0xC)
 * from raw 32-byte directory record. Decomposes ISO flags into compact
 * bit field at output +0xB: bit4=directory, bit3=hidden, bit2=system,
 * bit1=read-only. Copies name length (+0xE) and interleave (+0xF). */
void cd_parse_dir_entry(param_1, param_2)
    int *param_1;
    int param_2;
{
    char dir_flag, hidden_flag, sys_flag, ro_flag;
    unsigned int iso_flags;

    /* Copy LBA extent start and data size */
    *param_1 = *(int *)(param_2 + 4);         /* extent LBA */
    param_1[1] = *(int *)(param_2 + 8);       /* data length */
    *(char *)((int)param_1 + 10) = *(char *)(param_2 + 0x1d);  /* recording date */

    /* Decompose ISO9660 file flags into compact bit field */
    iso_flags = (unsigned int)*(unsigned short *)(param_2 + 0xc);

    dir_flag   = (0x00008000 & iso_flags) ? '\x10' : '\0';  /* bit 15 → directory */
    hidden_flag = (0x800 & iso_flags)     ? '\b'   : '\0';  /* bit 11 → hidden */
    sys_flag   = ((int)DAT_0603f8ae & iso_flags) ? '\x04' : '\0';  /* system file */
    ro_flag    = ((int)PTR_DAT_0603f8b0 & iso_flags) ? '\x02' : '\0';  /* read-only */

    *(char *)((int)param_1 + 0xb) = dir_flag + hidden_flag + sys_flag + ro_flag;

    /* Copy name length and interleave gap */
    *(char *)(param_1 + 2) = *(char *)(param_2 + 0xe);    /* name length */
    *(char *)((int)param_1 + 9) = *(char *)(param_2 + 0xf);  /* interleave */
}

/* cd_buf_init -- Initialize a CD buffer descriptor to default state.
 * Clears all fields (handle, offset, position, start sector),
 * sets end sector to 1, clears flags. Sets mode to 3 (raw read),
 * marks as active (field 0xC=1), clears status byte. */
int * FUN_0603f93c(int *param_1)
{
  *param_1 = 0;           /* handle */
  param_1[1] = 0;         /* buffer offset */
  param_1[2] = 0;         /* read position */
  param_1[3] = 0;         /* start sector */
  param_1[4] = 1;         /* end sector */
  param_1[5] = 0;         /* flags A */
  param_1[6] = 0;         /* flags B */
  FUN_0603f970(param_1, 3);  /* set mode = raw read */
  param_1[0xc] = 1;       /* active flag */
  *(char *)(param_1 + 0xd) = 0;  /* status */
  return param_1;
}

/* cd_buf_set_mode -- Set buffer mode and apply configuration.
 * Saves previous mode from +0x35, stores new mode.
 * If mode is 0-3, applies configuration from 12-byte table at 0x0606364C.
 * Returns the previous mode. */
char FUN_0603f970(int param_1, int param_2)
{
    char prev = *(char *)(param_1 + 0x35);
    *(char *)(param_1 + 0x35) = (char)param_2;

    if (param_2 >= 0 && param_2 < 4) {
        FUN_0603f92c(param_1, 0, 0x0606364C + (char)((char)param_2 * '\f'));
    }

    return prev;
}

/* cd_stream_advance -- Advance CD streaming state machine one step.
 *
 * Pool verified (0x0603FB22-0x0603FCB6):
 *   DAT_0603fb22 = 0x0080 (CDSTREAM_READY_BIT)
 *   DAT_0603fb24 = 0xFF7F (CDSTREAM_STATE_MASK — clears bit 7)
 *   DAT_0603fcb6 = 0xFF7F (same mask, reused)
 *   0x0603F91C = cd_buf_release (buffer release function)
 *
 * Stream context struct (param_1):
 *   [0] = source address      [1] = read buffer handle
 *   [2] = dest address        [3] = decode buffer handle
 *   [5] = total size           [6] = bytes transferred
 *   [7] = current position    [8] = callback param
 *   [9] = decode func ptr     [0xb] = transfer func ptr
 *   [0xd] byte = status (bit7=ready, bits0-6=state 0-5)
 *
 * States: 0=request_read, 1=decode_start, 2=process, 3=transfer, 4=complete
 * Returns state number. Sets *out_complete = 1 when transfer chunk finishes. */
#define CDSTREAM_READY_BIT   0x0080
#define CDSTREAM_STATE_MASK  0xFF7F
#define cd_buf_release       ((void (*)(int, int, int))0x0603F91C)
unsigned short cd_stream_advance(ctx, out_complete)
    int *ctx;
    int *out_complete;
{
    unsigned char ready_mask;
    unsigned short state;
    int result;
    int src_addr;
    int dst_addr;
    int completed = 0;

    src_addr = *ctx;
    dst_addr = ctx[2];

    if ((int)ctx[5] < 1) {
        *out_complete = 0;
        return 5;
    }

    if ((*(unsigned char *)(ctx + 0xd) & CDSTREAM_READY_BIT) != CDSTREAM_READY_BIT) {
        *out_complete = 0;
        return *(unsigned char *)(ctx + 0xd) & CDSTREAM_STATE_MASK;
    }

    state = *(unsigned char *)(ctx + 0xd) & CDSTREAM_STATE_MASK;
    ready_mask = (unsigned char)CDSTREAM_READY_BIT;

    if (state == 0) {
        cd_buf_request_read(ctx, src_addr, dst_addr);
        if (ctx[1] == 0) goto done;
        *(unsigned char *)(ctx + 0xd) = *(unsigned char *)(ctx + 0xd) & ready_mask | 1;
state_1:
        FUN_0603fce4(ctx, src_addr, dst_addr);
        if (ctx[3] == 0) goto done;
        *(unsigned char *)(ctx + 0xd) = *(unsigned char *)(ctx + 0xd) & ready_mask | 2;
state_2:
        result = (*(int(*)())ctx[9])(ctx[8]);
        if (result == 0) goto done;
        FUN_0603ff9c(ctx);
        *(unsigned char *)(ctx + 0xd) = *(unsigned char *)(ctx + 0xd) & ready_mask | 3;
state_3:
        result = (*(int(*)())ctx[0xb])(ctx[8]);
        if (0 < result) goto done;
        completed = 1;
        *(unsigned char *)(ctx + 0xd) = *(unsigned char *)(ctx + 0xd) & ready_mask | 4;
    } else {
        if (state == 1) goto state_1;
        if (state == 2) goto state_2;
        if (state == 3) goto state_3;
        if (state != 4) goto done;
    }

    /* State 4: chunk complete — release buffers and check if more data */
    if (ctx[7] == *(int *)(ctx[1] + 8)) {
        cd_buf_release(src_addr, ctx[1], 0xffffffff);
        ctx[6] = ctx[6] + *(int *)(ctx[1] + 0xc);
        ctx[1] = 0;
    }

    cd_buf_release(dst_addr, ctx[3], 0xffffffff);
    ctx[3] = 0;

    if ((int)ctx[6] < (int)ctx[5]) {
        *(unsigned char *)(ctx + 0xd) = *(unsigned char *)(ctx + 0xd) & ready_mask;
    } else {
        *(unsigned char *)(ctx + 0xd) = *(unsigned char *)(ctx + 0xd) & ready_mask | 5;
    }

done:
    *out_complete = completed;
    return *(unsigned char *)(ctx + 0xd) & CDSTREAM_STATE_MASK;
}
#undef CDSTREAM_READY_BIT
#undef CDSTREAM_STATE_MASK
#undef cd_buf_release

/* cd_buf_request_read -- Request a CD buffer read with size negotiation.
 * Computes available = total_size(+0x14) - bytes_read(+0x18), clamped to
 * max_chunk(+0x10). If state(+0x30) >= 2 (multi-buffer), also queries
 * available space via 0x06034FFC and takes the minimum. If no active
 * buffer (+0x04 == 0), allocates one via 0x0603F900 and resets offset(+0x1C). */
void cd_buf_request_read(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  int avail;
  int buf_space;
  avail = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x18); /* remaining bytes */
  if (*(int *)(param_1 + 0x10) < avail) {
    avail = *(int *)(param_1 + 0x10);                   /* clamp to max chunk */
  }
  buf_space = avail;
  if (1 < *(int *)(param_1 + 0x30)) {                   /* multi-buffer mode */
    if (*(int *)(param_1 + 4) != 0) {
      avail = (*(int(*)())0x06034FFC)();                 /* query buffer space */
    }
    (*(int(*)())0x0603F8EE)(param_3);                    /* set buffer mode */
    buf_space = (*(int(*)())0x06034FFC)();               /* re-query after mode set */
    if (avail < buf_space) {
      buf_space = avail;                                 /* take minimum */
    }
  }
  if (*(int *)(param_1 + 4) == 0) {                     /* no active buffer */
    int buf = (*(int(*)())0x0603F900)(param_2, buf_space); /* allocate buffer */
    *(int *)(param_1 + 4) = buf;
    if (buf != 0) {
      *(int *)(param_1 + 0x1c) = 0;                     /* reset read offset */
    }
  }
  return;
}

/* cd_buf_calc_transfer_size -- Calculate transfer size for CD buffer.
 * If state (+0x30) < 2: remaining = total_size - offset, clamp to param_3 limit.
 * If state >= 2: use full buffer size.
 * Stores computed descriptor at +0x0C via FUN_0603F90E. */
void FUN_0603fce4(int param_1, int param_2, int param_3)
{
    register int size_func asm("r3") = 0x0603F8EE;
    int size, limit;

    if (*(int *)(param_1 + 0x30) < 2) {
        size = *(int *)(*(int *)(param_1 + 4) + 8) - *(int *)(param_1 + 0x1c);
        limit = (*(int(*)())size_func)(param_3);
        if (limit <= size) {
            size = (*(int(*)())size_func)(param_3);
        }
    } else {
        size = *(int *)(*(int *)(param_1 + 4) + 8);
    }

    *(int *)(param_1 + 0xc) = (*(int(*)())0x0603F90E)(param_3, size);
}

/* dma_transfer_execute -- Set up and execute a DMA block transfer.
 * Configures transfer descriptor on stack:
 *   - Direction for src (param_3): -1=decrement(2), 0=fixed(0), +1=increment(1)
 *   - Direction for dst (param_5): same mapping
 *   - Sector size from DAT_0603fe2e, stride from PTR_DAT_0603fe30
 * Calls 0x06042ACA to start transfer, polls 0x06042BEE until complete.
 * Handles byte remainder via byte_partial_copy, then clears dest via 0x0603C05C. */
void FUN_0603fd40(param_1, param_2, param_3, param_4, param_5, param_6)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
    unsigned int param_6;
{
  int poll_result;
  unsigned int word_count = param_6 >> 2;
  int iStack_58, iStack_54;
  unsigned int uStack_50;
  int uStack_4c, uStack_48;
  unsigned int uStack_44, uStack_40;
  int uStack_3c, iStack_34;
  int uStack_30, uStack_2c, uStack_28;
  (*(int(*)())0x06042BBE)(param_1);            /* prepare device */
  uStack_30 = 0;
  uStack_2c = 1;
  uStack_28 = 7;
  (*(int(*)())0x06042A8C)(&uStack_30);         /* configure channel */
  /* map source direction: -1→2(dec), 0→0(fixed), +1→1(inc) */
  if (param_3 < 1) {
    uStack_4c = (param_3 < 0) ? 2 : 0;
  } else {
    uStack_4c = 1;
  }
  /* map dest direction */
  if (param_5 < 1) {
    uStack_48 = (param_5 < 0) ? 2 : 0;
  } else {
    uStack_48 = 1;
  }
  uStack_44 = (unsigned int)DAT_0603fe2e;      /* sector size */
  uStack_40 = uStack_44 >> 2;                  /* sector word count */
  uStack_3c = 0;
  iStack_34 = (int)PTR_DAT_0603fe30;           /* stride */
  iStack_58 = param_4;                         /* dest address */
  iStack_54 = param_2;                         /* source address */
  uStack_50 = word_count;                      /* transfer word count */
  (*(int(*)())0x06042ACA)(&iStack_58, param_1);  /* start transfer */
  (*(int(*)())0x06042BAC)(param_1);            /* enable transfer */
  /* poll until transfer complete */
  do {
    poll_result = (*(int(*)())0x06042BEE)(param_1);
  } while (poll_result == 0);
  /* handle byte remainder (param_6 & 3 leftover bytes) */
  FUN_0603ffe6(param_6 & 3,
               param_3 * (word_count << 2) + param_2,
               param_5 * (word_count << 2) + param_4);
  (*(int(*)())0x0603C05C)(param_2, param_6);   /* clear dest region */
  return;
}

/* cd_buf_transfer_step -- Execute one DMA transfer step for CD buffer.
 * Reads transfer descriptor from +0x0C, computes source address from
 * base (+0x04) + stride * offset (+0x1C), calls transfer function (+0x28).
 * Advances offset by the transfer count. */
void FUN_0603ff9c(int param_1)
{
    int *desc = *(int **)(param_1 + 0xc);
    int stride = (*(int **)(param_1 + 4))[1];
    int count = desc[2];

    (*(int(*)())(*(int *)(param_1 + 0x28)))(
        *(int *)(param_1 + 0x20),    /* dest */
        *desc,                        /* src offset */
        desc[1],                      /* src param */
        stride * *(int *)(param_1 + 0x1c) + **(int **)(param_1 + 4),  /* src addr */
        stride,                       /* stride */
        count);                       /* count */

    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + count;
}

/* byte_partial_copy -- Copy partial bytes from a word source to a byte destination.
 * Reads one word from *param_3 into local storage, then copies param_1 bytes
 * from that word (low bytes first) to param_2. Used for DMA remainder
 * handling when transfer count is not word-aligned (param_1 = count & 3). */
void FUN_0603ffe6(param_1, param_2, param_3)
    int param_1;
    char *param_2;
    int *param_3;
{
  char *src;
  int idx;
  int local_word;
  if (0 < param_1) {
    local_word = *param_3;
    idx = 0;
    if (0 < param_1) {
      do {
        src = (char *)((int)&local_word + idx);
        idx = idx + 1;
        *param_2 = *src;
        param_2 = param_2 + 1;
      } while (idx < param_1);
    }
  }
  return;
}

/* --- FUN_0603F148 (L1 import from src/FUN_0603F148.c) --- */

int FUN_0603f148(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  unsigned short uVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  puVar2 = (char *)0x06036D94;

  uVar1 = PTR_DAT_0603f180;

  iVar3 = (*(int(*)())0x06036D14)();

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = (*(int(*)())0x06036D14)();

    if (iVar3 == 0) {

      iVar3 = 1;

    }

    else {

      iVar3 = 2;

      param_1 = param_1 + 0x30;

      if (2 < param_3) {

        do {

          iVar4 = (*(int(*)())puVar2)(param_2,param_1 + 0xc,0xc);

          if (iVar4 == 0) {

            return iVar3;

          }

          if ((*(unsigned char *)(param_1 + 0xb) & uVar1) != 0) break;

          iVar3 = iVar3 + 1;

          param_1 = param_1 + 0x18;

        } while (iVar3 < param_3);

      }

      iVar3 = -1;

    }

  }

  return iVar3;

}

/* --- FUN_0603FACE (L1 import from src/FUN_0603FACE.c) --- */

unsigned short FUN_0603face(param_1, param_2)
    int *param_1;
    int *param_2;
{

  unsigned char bVar1;

  unsigned short uVar3;

  int iVar2;

  int uVar4;

  int uVar5;

  int uVar6;

  uVar6 = 0;

  uVar5 = *param_1;

  uVar4 = param_1[2];

  if ((int)param_1[5] < 1) {

    *param_2 = 0;

    return 5;

  }

  if ((*(unsigned char *)(param_1 + 0xd) & DAT_0603fb22) != DAT_0603fb22) {

    *param_2 = 0;

    return *(unsigned char *)(param_1 + 0xd) & DAT_0603fb24;

  }

  uVar3 = *(unsigned char *)(param_1 + 0xd) & DAT_0603fb24;

  bVar1 = (unsigned char)DAT_0603fb22;

  if (uVar3 == 0) {

    FUN_0603fc60(param_1,uVar5,uVar4);

    if (param_1[1] == 0) goto LAB_0603fc40;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 1;

LAB_0603fb50:

    FUN_0603fce4(param_1,uVar5,uVar4);

    if (param_1[3] == 0) goto LAB_0603fc40;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 2;

LAB_0603fb74:

    iVar2 = (*(int(*)())param_1[9])(param_1[8]);

    if (iVar2 == 0) goto LAB_0603fc40;

    FUN_0603ff9c(param_1);

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 3;

LAB_0603fba0:

    iVar2 = (*(int(*)())param_1[0xb])(param_1[8]);

    if (0 < iVar2) goto LAB_0603fc40;

    uVar6 = 1;

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 4;

  }

  else {

    if (uVar3 == 1) goto LAB_0603fb50;

    if (uVar3 == 2) goto LAB_0603fb74;

    if (uVar3 == 3) goto LAB_0603fba0;

    if (uVar3 != 4) goto LAB_0603fc40;

  }

  if (param_1[7] == *(int *)(param_1[1] + 8)) {

    (*(int(*)())0x0603F91C)(uVar5,param_1[1],0xffffffff);

    param_1[6] = param_1[6] + *(int *)(param_1[1] + 0xc);

    param_1[1] = 0;

  }

  (*(int(*)())0x0603F91C)(uVar4,param_1[3],0xffffffff);

  param_1[3] = 0;

  if ((int)param_1[6] < (int)param_1[5]) {

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1;

  }

  else {

    *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & bVar1 | 5;

  }

LAB_0603fc40:

  *param_2 = uVar6;

  return *(unsigned char *)(param_1 + 0xd) & DAT_0603fcb6;

}

/* --- FUN_0603FC60 (L1 import from src/FUN_0603FC60.c) --- */

void FUN_0603fc60(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  int iVar1;

  int iVar2;

  iVar2 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x18);

  if (*(int *)(param_1 + 0x10) < iVar2) {

    iVar2 = *(int *)(param_1 + 0x10);

  }

  iVar1 = iVar2;

  if (1 < *(int *)(param_1 + 0x30)) {

    if (*(int *)(param_1 + 4) != 0) {

      iVar2 = (*(int(*)())0x06034FFC)();

    }

    (*(int(*)())0x0603F8EE)(param_3);

    iVar1 = (*(int(*)())0x06034FFC)();

    if (iVar2 < iVar1) {

      iVar1 = iVar2;

    }

  }

  if (*(int *)(param_1 + 4) == 0) {

    iVar2 = (*(int(*)())0x0603F900)(param_2,iVar1);

    *(int *)(param_1 + 4) = iVar2;

    if (iVar2 != 0) {

      *(int *)(param_1 + 0x1c) = 0;

    }

  }

  return;

}
