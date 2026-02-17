#include "game.h"

extern int DAT_0603c07a;
extern int DAT_0603c07c;
extern int DAT_0603c23c;
extern int DAT_0603c378;
extern int DAT_0603c37c;
extern int DAT_0603c37e;
extern int DAT_0603c496;
extern int DAT_0603c49a;
extern int DAT_0603c49c;
extern int DAT_0603c62e;
extern int DAT_0603c7e6;
extern int DAT_0603c7e8;
extern int DAT_0603c7ea;
extern int DAT_0603c8d0;
extern int DAT_0603c8d2;
extern int DAT_0603c8d4;
extern int DAT_0603cad8;
extern int DAT_0603cada;
extern int DAT_0603cadc;
extern int DAT_0603cade;
extern int DAT_0603cae0;
extern int DAT_0603cae2;
extern int DAT_0603cba2;
extern int DAT_0603cd4c;
extern int DAT_0603ce8e;
extern int DAT_0603ce90;
extern int DAT_0603d034;
extern int DAT_0603d1c2;
extern int DAT_0603d426;
extern int DAT_0603d500;
extern int DAT_0603d5be;
extern int DAT_0603e0b2;
extern int DAT_0603e3b6;
extern int DAT_0603e3b8;
extern int DAT_0603e3ba;
extern int DAT_0603e3bc;
extern int DAT_0603e61e;
extern int DAT_0603e93a;
extern int DAT_0603e93c;
extern int DAT_0603e93e;
extern int DAT_0603ea46;
extern int dma_channel_level_set();
extern int FUN_0603cc88();
extern void dma_register_state_clear();
extern char * FUN_0603d9ec();
extern char * FUN_0603da88();
extern int FUN_0603eacc();
extern int FUN_0603ec40();
extern int PTR_DAT_0603c7ec;
extern int PTR_DAT_0603e53c;
extern int PTR_DAT_0603e620;

/* vdp2_vram_bank_clear -- Clear VDP2 VRAM banks via cache-through writes.
 * Base address 0x60000000 (VDP2 VRAM cache-through).
 * Bank control register at -366 (0xFFFFFE92 = VDP2 RAMCTL).
 * Iterates banks (0x40 step per bank, up to DAT_0603c07a),
 * selects bank via bits 6-7, then zeros 0x40 words in 2-word steps.
 * Disables VRAM access (bit 0 clear) before, re-enables after. */
void FUN_0603c000()
{
  int *vram_base = (int *)0x60000000;     /* VDP2 VRAM cache-through */
  unsigned int bank_limit = (unsigned int)DAT_0603c07a;
  unsigned char *ramctl = (unsigned char *)-366;  /* 0xFFFFFE92 VDP2 RAMCTL */
  int *ptr;
  int count;
  unsigned int bank = 0;
  *ramctl = *ramctl & 0xfe;               /* disable VRAM access */
  do {
    *ramctl = *ramctl & 0x3f | (unsigned char)bank;  /* select bank */
    count = 0x40;
    ptr = vram_base;
    do {
      count = count + -2;
      *ptr = 0;
      ptr[4] = 0;
      ptr = ptr + 8;
    } while (count != 0);
    bank = bank + 0x40;
  } while (bank < bank_limit);
  *ramctl = *ramctl & 0xfe | 1;           /* re-enable VRAM access */
  return;
}

/* dma_region_clear -- Zero a memory region via cache-through address.
 * Converts param_1 to cache-through (mask low 29 bits, set bit 30),
 * then zeros param_2 bytes in 16-byte (4-word) steps. */
void FUN_0603c05c(unsigned int param_1, int param_2)
{
    int *ptr = (int *)(param_1 & 0x1FFFFFF0 | 0x40000000);
    int *end = (int *)((int)ptr + param_2);

    for (; ptr < end; ptr += 4) {
        *ptr = 0;
    }
}

/* sh2_mul_fixed16 -- 32x32 multiply returning 16.16 fixed-point result.
 * Performs 64-bit multiply, extracts middle 32 bits (bits 16-47)
 * to produce a 16.16 fixed-point product. */
unsigned int FUN_0603c08c(int param_1, int param_2)
{
  return (int)((unsigned long long)((long long)param_2 * (long long)param_1) >> 0x20) << 0x10 |
         (unsigned int)((long long)param_2 * (long long)param_1) >> 0x10;
}

/* sh2_div_fixed16 -- SH-2 hardware 32-bit division for 16.16 fixed-point.
 * Uses DIVU hardware at 0xFFFFFF00:
 *   DVSR (+0x00) = divisor
 *   DVDNT_H (+0x10) = sign-extended upper 16 bits
 *   DVDNT_L (+0x14) = lower bits shifted left 16
 * Returns quotient from DVDNT_L. */
int FUN_0603c0a0(int param_1, int param_2)
{
    char *div_base = (char *)0xFFFFFF00;

    SH2_DVSR = param_2;
    *(int *)(div_base + 0x10) = (int)(short)((unsigned int)param_1 >> 0x10);
    *(int *)(div_base + 0x14) = param_1 << 0x10;

    return *(int *)(div_base + 0x14);
}

/* scu_dma_subsystem_init -- Initialize SCU DMA controller and interrupt tables.
 * Calls dma_register_state_clear to reset DMA state, then initializes 5 DMA channel
 * handlers (0x0603D2CC..0x0603D5D0). Clears 8-slot interrupt dispatch
 * table at 0x060A4D60, resets DMA pending flag (0x060A4D80) and
 * interrupt acknowledge register (0x060A4DA6). */
#if 0 /* scu_dma_subsystem_init -- redirected to ASM import via linker PROVIDE */
void scu_dma_subsystem_init()
{
  unsigned int i;
  char *int_table = (int *)0x060A4D60;                  /* interrupt dispatch table */

  dma_register_state_clear();                                       /* reset DMA state */
  (*(int(*)())0x0603D2CC)();                            /* init DMA channel 0 */
  (*(int(*)())0x0603D3A8)();                            /* init DMA channel 1 */
  (*(int(*)())0x0603D438)();                            /* init DMA channel 2 */
  (*(int(*)())0x0603D514)();                            /* init DMA channel 3 */
  (*(int(*)())0x0603D5D0)();                            /* init DMA channel 4 */

  /* Clear 8-slot interrupt dispatch table */
  for (i = 0; i < 8; i++) {
    *(int *)(int_table + (i << 2)) = 0;
  }
  *(int *)0x060A4D80 = 0;                               /* DMA pending flag: clear */
  *(int *)0x060A4DA6 = 0;                               /* interrupt ack: clear */
  return;
}
#endif /* scu_dma_subsystem_init */
/* REMOVED: conflicting alias */ // void FUN_0603C104(void) __attribute__((alias("scu_dma_subsystem_init")));

/* dma_channel_level_set -- Set DMA transfer level for selected channels.
 * channel_mask: bitmask selecting which DMA channels to configure:
 *   0x100/0x200 = channel 0 (low/high byte of reg at 0x060A4D36)
 *   0x400/0x800 = channel 1 (low/high byte of reg at 0x060A4D38)
 *   DAT_0603c496/c49a = channel 2 (low/high byte of reg at 0x060A4D3A)
 *   DAT_0603c49c/0x8000 = channel 3 (low/high byte of reg at 0x060A4D3C)
 *   0x04/0x02 = alternate ch A (low byte of reg at 0x060A4D3E)
 *   0x08/0x80 = alternate ch B (high byte of reg at 0x060A4D3E)
 *   0x10 = alternate ch C (low byte of reg at 0x060A4D40)
 *   0x20 = alternate ch D (high byte of reg at 0x060A4D40)
 *   0x01 = alternate ch E (reg at 0x060A4D42)
 * level: value to write (must be < 0x20 to enable, >= 0x20 disables).
 * Each channel write is synced via 0x06034F78 and sets/clears
 * the enable bit in control reg[6] at 0x060A4D18+0xC. */
int dma_channel_level_set(channel_mask, level)
    unsigned int channel_mask;
    unsigned int level;
{
  unsigned short high_mask;
  char *ch_reg_a;
  char *mask_ffbf_ptr;
  char *ch_reg_b;
  char *mask_ff00_ptr;
  unsigned short mask_ffbf;
  char *shadow_base;
  unsigned int one;
  ch_reg_a = (char *)0x060A4D36;                            /* DMA channel 0-3 level regs */
  mask_ffbf_ptr = (char *)0x0000FFBF;
  ch_reg_b = (int *)0x060A4D3E;                             /* DMA alternate channel regs */
  mask_ff00_ptr = (char *)0x0000FF00;
  one = 1;
  shadow_base = (char *)0x060A4D18;                         /* DMA shadow register base */
  /* clear enable bits 9 and 8 in control reg[6] */
  (*(int(*)())0x06034F78)();                                 /* dma_sync */
  *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FDFF;
  (*(int(*)())0x06034F78)();
  *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FEFF;
  high_mask = (unsigned short)mask_ff00_ptr;
  mask_ffbf = (unsigned short)mask_ffbf_ptr;
  /* channel 0 low byte (bit 0x100) */
  if ((0x100 & channel_mask) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf | 0x40;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)ch_reg_a = *(unsigned short *)ch_reg_a & high_mask | (unsigned short)level & 0xff;
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf;
    }
  }
  /* channel 0 high byte (bit 0x200) */
  if ((0x200 & channel_mask) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf | 0x40;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)ch_reg_a = *(unsigned short *)ch_reg_a & 0xff | (unsigned short)((level & 0xff) << 8);
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf;
    }
  }
  /* channel 1 low byte (bit 0x400) */
  if ((0x400 & channel_mask) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf | 0x40;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_a + 2) = *(unsigned short *)(ch_reg_a + 2) & high_mask | (unsigned short)level & 0xff;
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf;
    }
  }
  /* channel 1 high byte (bit 0x800) */
  if ((0x800 & channel_mask) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf | 0x40;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_a + 2) = *(unsigned short *)(ch_reg_a + 2) & 0xff | (unsigned short)((level & 0xff) << 8);
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf;
    }
  }
  /* channel 2 low byte */
  if (((int)DAT_0603c496 & channel_mask) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf | 0x40;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_a + 4) = *(unsigned short *)(ch_reg_a + 4) & high_mask | (unsigned short)level & 0xff;
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf;
    }
  }
  /* channel 2 high byte */
  if (((int)DAT_0603c49a & channel_mask) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf | 0x40;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_a + 4) = *(unsigned short *)(ch_reg_a + 4) & 0xff | (unsigned short)((level & 0xff) << 8);
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf;
    }
  }
  /* channel 3 low byte */
  if (((int)DAT_0603c49c & channel_mask) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf | 0x40;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_a + 6) = *(unsigned short *)(ch_reg_a + 6) & high_mask | (unsigned short)level & 0xff;
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf;
    }
  }
  /* channel 3 high byte (bit 0x8000) */
  if (((unsigned int)0x00008000 & channel_mask) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf | 0x40;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_a + 6) = *(unsigned short *)(ch_reg_a + 6) & 0xff | (unsigned short)((level & 0xff) << 8);
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & mask_ffbf;
    }
  }
  /* alternate channel A: bits 4 or 2 */
  if (((channel_mask & 4) != 0) || ((channel_mask & 2) != 0)) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) =
           *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FFFE | (unsigned short)one;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)ch_reg_b = *(unsigned short *)ch_reg_b & high_mask | (unsigned short)level & 0xff;
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FFFE;
    }
  }
  /* alternate channel B: bits 8 or 0x80 */
  if (((channel_mask & 8) != 0) || ((0x80 & channel_mask) != 0)) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FFFD | 2;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)ch_reg_b = *(unsigned short *)ch_reg_b & 0xff | (unsigned short)((level & 0xff) << 8);
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FFFD;
    }
  }
  /* alternate channel C: bit 0x10 */
  if ((channel_mask & 0x10) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FFFB | 4;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_b + 2) = *(unsigned short *)(ch_reg_b + 2) & high_mask | (unsigned short)level & 0xff;
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FFFB;
    }
  }
  /* alternate channel D: bit 0x20 */
  if ((channel_mask & 0x20) != 0) {
    if ((level & 0xff) < 0x20) {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FFF7 | 8;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_b + 2) = *(unsigned short *)(ch_reg_b + 2) & 0xff | (unsigned short)((level & 0xff) << 8);
    }
    else {
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)0x0000FFF7;
    }
  }
  /* alternate channel E: bit 0x01 */
  mask_ffbf = (unsigned short)level;
  if ((channel_mask & one) != 0) {
    if ((level & 0xff) < 0x20) {
      mask_ff00_ptr = (char *)0x0000FFEF;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)mask_ff00_ptr | 0x10;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(ch_reg_b + 4) = mask_ffbf & 0xff;
    }
    else {
      mask_ff00_ptr = (char *)0x0000FFEF;
      (*(int(*)())0x06034F78)();
      *(unsigned short *)(shadow_base + 0xc) = *(unsigned short *)(shadow_base + 0xc) & (unsigned short)mask_ff00_ptr;
    }
  }
  return 0;
}

/* palette_fade_update -- Palette color transition controller.
 *
 * Manages per-frame color/brightness transitions for VDP2 palettes.
 * Three transition modes controlled by mode byte at 0x060A4DA6:
 *
 *   Mode 1 (Multi-RGB): Per-entry RGB fade toward target colors.
 *     Each component steps ±1 per frame until all entries match.
 *     Then writes packed colors to CRAM via palette_cram_write.
 *     Color packing: VDP2 mode 2 = 24-bit RGB, else = 15-bit 5-5-5.
 *
 *   Mode 2 (Brightness): Global brightness ramp ±1 toward target.
 *     Applies result to all active DMA channels (up to 15 channels).
 *
 *   Mode 3 (Vector): RGB velocity-based transition via FUN_0603cc88.
 *     Subtracts velocity from remaining distance each frame.
 *     Zeros velocity when it crosses zero (arrival detection).
 *
 * All modes use wait_counter/wait_target for frame delay.
 *
 * Color table layout at 0x060A4DA8:
 *   +0x000: Target R [entry_count]
 *   +0x100: Target G
 *   +0x200: Target B
 *   +0x300: Current R (approaches +0x000)
 *   +0x400: Current G (approaches +0x100)
 *   +0x500: Current B (approaches +0x200) */

/* Palette fade state block (0x060A4D84 - 0x060A4DA8) */
#define PFADE_CHANNEL_MASK    (*(volatile unsigned int *)0x060A4D84)
#define PFADE_WAIT_TARGET     (*(volatile unsigned int *)0x060A4D88)
#define PFADE_WAIT_COUNTER    (*(volatile unsigned int *)0x060A4D8C)
#define PFADE_PALETTE_OFFSET  (*(volatile unsigned int *)0x060A4D90)
#define PFADE_ENTRY_COUNT     (*(volatile unsigned int *)0x060A4D94)
#define PFADE_VEL_R           (*(volatile short *)0x060A4D98)
#define PFADE_VEL_G           (*(volatile short *)0x060A4D9A)
#define PFADE_VEL_B           (*(volatile short *)0x060A4D9C)
#define PFADE_REMAIN_R        (*(volatile short *)0x060A4D9E)
#define PFADE_REMAIN_G        (*(volatile short *)0x060A4DA0)
#define PFADE_REMAIN_B        (*(volatile short *)0x060A4DA2)
#define PFADE_BRIGHTNESS      (*(volatile unsigned char *)0x060A4DA4)
#define PFADE_TARGET_BRIGHT   (*(volatile unsigned char *)0x060A4DA5)
#define PFADE_MODE            (*(volatile unsigned char *)0x060A4DA6)
#define PFADE_DIRECTION       (*(volatile unsigned char *)0x060A4DA7)
#define PFADE_COLOR_TABLE     ((volatile unsigned char *)0x060A4DA8)

/* Color table channel offsets */
#define CTBL_TARGET_R    0x000
#define CTBL_TARGET_G    0x100
#define CTBL_TARGET_B    0x200
#define CTBL_CURRENT_R   0x300   /* pool 0x0603C7E8 = 0x0300 */
#define CTBL_CURRENT_G   0x400   /* pool 0x0603C7EA = 0x0400 */
#define CTBL_CURRENT_B   0x500

/* VDP2 color format selector */
#define VDP2_COLOR_MODE_REG  (*(volatile unsigned short *)0x060A3D96)
#define COLOR_MODE_MASK      0x3000   /* pool 0x0603C8D4 = 0x3000 */
#define COLOR_MODE_SHIFT     12

/* DMA channel bits from pool constants */
#define DMA_CH_12   0x1000   /* pool 0x0603CADE */
#define DMA_CH_13   0x2000   /* pool 0x0603CAE0 */
#define DMA_CH_14   0x4000   /* pool 0x0603CAE2 */

/* Palette CRAM write: (channel_mask, palette_index, count, color_data_ptr) */
#define palette_cram_write  ((unsigned int (*)(int, int, int, unsigned int *))0x060429EC)

unsigned int palette_fade_update(void)
{
    unsigned int mode = PFADE_MODE;
    unsigned int result = mode;

    if (mode == 1) {
        /* Mode 1: Per-entry RGB color fade */
        if (PFADE_WAIT_COUNTER < PFADE_WAIT_TARGET) {
            PFADE_WAIT_COUNTER++;
        } else {
            volatile unsigned char *tbl = PFADE_COLOR_TABLE;
            unsigned int i;
            PFADE_MODE = 0;  /* tentatively mark done */

            /* Step each color component toward target by ±1 */
            for (i = 0; i < PFADE_ENTRY_COUNT; i++) {
                /* Red */
                if ((unsigned char)tbl[CTBL_CURRENT_R + i] < (unsigned char)tbl[CTBL_TARGET_R + i]) {
                    tbl[CTBL_CURRENT_R + i] = tbl[CTBL_CURRENT_R + i] + 1;
                    PFADE_MODE = 1;
                } else if ((unsigned char)tbl[CTBL_TARGET_R + i] < (unsigned char)tbl[CTBL_CURRENT_R + i]) {
                    tbl[CTBL_CURRENT_R + i] = tbl[CTBL_CURRENT_R + i] - 1;
                    PFADE_MODE = 1;
                }
                /* Green */
                if ((unsigned char)tbl[CTBL_CURRENT_G + i] < (unsigned char)tbl[CTBL_TARGET_G + i]) {
                    tbl[CTBL_CURRENT_G + i] = tbl[CTBL_CURRENT_G + i] + 1;
                    PFADE_MODE = 1;
                } else if ((unsigned char)tbl[CTBL_TARGET_G + i] < (unsigned char)tbl[CTBL_CURRENT_G + i]) {
                    tbl[CTBL_CURRENT_G + i] = tbl[CTBL_CURRENT_G + i] - 1;
                    PFADE_MODE = 1;
                }
                /* Blue */
                if ((unsigned char)tbl[CTBL_CURRENT_B + i] < (unsigned char)tbl[CTBL_TARGET_B + i]) {
                    tbl[CTBL_CURRENT_B + i] = tbl[CTBL_CURRENT_B + i] + 1;
                    PFADE_MODE = 1;
                } else if ((unsigned char)tbl[CTBL_TARGET_B + i] < (unsigned char)tbl[CTBL_CURRENT_B + i]) {
                    tbl[CTBL_CURRENT_B + i] = tbl[CTBL_CURRENT_B + i] - 1;
                    PFADE_MODE = 1;
                }
            }

            PFADE_WAIT_COUNTER = 0;

            /* Pack current RGB and write to CRAM */
            {
                int color_mode = ((unsigned int)VDP2_COLOR_MODE_REG & COLOR_MODE_MASK) >> COLOR_MODE_SHIFT;
                if (color_mode == 2) {
                    /* 24-bit RGB: (R << 16) | (G << 8) | B */
                    for (i = 0; i < PFADE_ENTRY_COUNT; i++) {
                        unsigned int color = (unsigned int)(((tbl[CTBL_CURRENT_R + i] << 8) |
                                            (tbl[CTBL_CURRENT_G + i] & 0xFF)) << 8 |
                                            (tbl[CTBL_CURRENT_B + i] & 0xFF));
                        result = palette_cram_write(PFADE_CHANNEL_MASK,
                                    PFADE_PALETTE_OFFSET + i, 1, &color);
                    }
                } else {
                    /* 15-bit 5-5-5: (R << 10) | (G << 5) | B */
                    for (i = 0; i < PFADE_ENTRY_COUNT; i++) {
                        unsigned int color = (unsigned int)(unsigned char)tbl[CTBL_CURRENT_B + i] |
                                    ((unsigned int)(unsigned char)tbl[CTBL_CURRENT_G + i] |
                                     (unsigned int)(unsigned char)tbl[CTBL_CURRENT_R + i] << 5) << 5;
                        result = palette_cram_write(PFADE_CHANNEL_MASK,
                                    PFADE_PALETTE_OFFSET + i, 1, &color);
                    }
                }
            }
        }
    } else if (mode == 2) {
        /* Mode 2: Global brightness ramp */
        if (PFADE_WAIT_COUNTER < PFADE_WAIT_TARGET) {
            PFADE_WAIT_COUNTER++;
        } else {
            if (PFADE_DIRECTION == 0) {
                /* Fade down */
                PFADE_BRIGHTNESS = PFADE_BRIGHTNESS - 1;
                if ((unsigned char)PFADE_BRIGHTNESS <= (unsigned char)PFADE_TARGET_BRIGHT) {
                    PFADE_BRIGHTNESS = PFADE_TARGET_BRIGHT;
                    PFADE_MODE = 0;
                }
            } else {
                /* Fade up */
                PFADE_BRIGHTNESS = PFADE_BRIGHTNESS + 1;
                if ((unsigned char)PFADE_TARGET_BRIGHT <= (unsigned char)PFADE_BRIGHTNESS) {
                    PFADE_BRIGHTNESS = PFADE_TARGET_BRIGHT;
                    PFADE_MODE = 0;
                }
            }

            /* Apply brightness to each active DMA channel */
            {
                int level = (int)(char)PFADE_BRIGHTNESS;
                unsigned int mask = PFADE_CHANNEL_MASK;
                if (mask & 0x100)    dma_channel_level_set(0x100, level);
                if (mask & 0x200)    dma_channel_level_set(0x200, level);
                if (mask & 0x400)    dma_channel_level_set(0x400, level);
                if (mask & 0x800)    dma_channel_level_set(0x800, level);
                if (mask & DMA_CH_12) dma_channel_level_set(DMA_CH_12, level);
                if (mask & DMA_CH_13) dma_channel_level_set(DMA_CH_13, level);
                if (mask & DMA_CH_14) dma_channel_level_set(DMA_CH_14, level);
                if (mask & 0x8000)   dma_channel_level_set(0x8000, level);
                if (mask & 0x04)     dma_channel_level_set(0x04, level);
                if (mask & 0x08)     dma_channel_level_set(0x08, level);
                if (mask & 0x10)     dma_channel_level_set(0x10, level);
                if (mask & 0x20)     dma_channel_level_set(0x20, level);
                if (mask & 0x01)     dma_channel_level_set(0x01, level);
                if (mask & 0x02)     dma_channel_level_set(0x02, level);
                result = mask;
                if (mask & 0x80)
                    result = dma_channel_level_set(0x80, level);
            }
            PFADE_WAIT_COUNTER = 0;
        }
    } else if (mode == 3) {
        /* Mode 3: RGB velocity vector transition */
        if (PFADE_WAIT_COUNTER < PFADE_WAIT_TARGET) {
            PFADE_WAIT_COUNTER++;
        } else {
            short vel_r = PFADE_VEL_R;
            result = FUN_0603cc88(PFADE_CHANNEL_MASK,
                        (int)vel_r, (int)PFADE_VEL_G, (int)PFADE_VEL_B);

            /* Subtract velocity from remaining distance */
            PFADE_REMAIN_R = PFADE_REMAIN_R - vel_r;
            PFADE_REMAIN_G = PFADE_REMAIN_G - PFADE_VEL_G;
            PFADE_REMAIN_B = PFADE_REMAIN_B - PFADE_VEL_B;

            /* Zero velocity when remaining crosses zero */
            if (vel_r < 1) {
                if (-1 < PFADE_REMAIN_R)
                    PFADE_VEL_R = 0;
            } else if (PFADE_REMAIN_R < 1) {
                PFADE_VEL_R = 0;
            }
            if (PFADE_VEL_G < 1) {
                if (-1 < PFADE_REMAIN_G)
                    PFADE_VEL_G = 0;
            } else if (PFADE_REMAIN_G < 1) {
                PFADE_VEL_G = 0;
            }
            if (PFADE_VEL_B < 1) {
                if (-1 < PFADE_REMAIN_B)
                    PFADE_VEL_B = 0;
            } else if (PFADE_REMAIN_B < 1) {
                PFADE_VEL_B = 0;
            }

            /* All velocities zero = transition complete */
            if (PFADE_VEL_R == 0 && PFADE_VEL_G == 0 && PFADE_VEL_B == 0)
                PFADE_MODE = 0;

            PFADE_WAIT_COUNTER = 0;
        }
    }

    return result;
}

/* vdp2_scroll_offset_set -- Set VDP2 scroll plane X/Y/Z offsets.
 * Register block at 0x060A4D46 (shadow copy of VDP2 scroll registers).
 * param_1 == 0: sets scroll plane A offsets (regs +4, +6, +8)
 * param_1 != 0: sets scroll plane B offsets (regs +10, +12, +14)
 * Each write syncs via 0x06034F78 (VDP2 register commit).
 * Mask DAT_0603cd4c preserves high bits, adds new offset value. */
#if 0 /* FUN_0603CC88 -- replaced by ASM import */
int FUN_0603cc88(param_1, param_2, param_3, param_4)
    int param_1;
    short param_2;
    short param_3;
    short param_4;
{
  unsigned short mask = DAT_0603cd4c;
  unsigned short *regs = (unsigned short *)0x060A4D46;
  if (param_1 == 0) {
    /* scroll plane A: offsets at +4, +6, +8 */
    (*(int(*)())0x06034F78)();   /* vdp2_reg_sync */
    *(unsigned short *)((char *)regs + 4) = (*(unsigned short *)((char *)regs + 4) & mask) + param_2;
    (*(int(*)())0x06034F78)();
    *(unsigned short *)((char *)regs + 6) = (*(unsigned short *)((char *)regs + 6) & mask) + param_3;
    (*(int(*)())0x06034F78)();
    *(unsigned short *)((char *)regs + 8) = (*(unsigned short *)((char *)regs + 8) & mask) + param_4;
  } else {
    /* scroll plane B: offsets at +10, +12, +14 */
    (*(int(*)())0x06034F78)();
    *(unsigned short *)((char *)regs + 10) = (*(unsigned short *)((char *)regs + 10) & mask) + param_2;
    (*(int(*)())0x06034F78)();
    *(unsigned short *)((char *)regs + 0xc) = (*(unsigned short *)((char *)regs + 0xc) & mask) + param_3;
    (*(int(*)())0x06034F78)();
    *(unsigned short *)((char *)regs + 0xe) = (*(unsigned short *)((char *)regs + 0xe) & mask) + param_4;
  }
  return 0;
}
#endif

/* FUN_0603CC88 -- original binary (212 bytes) */
__asm__(
    ".section .text.FUN_0603CC88, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603CC88\n"
    ".global _FUN_0603cc88\n"
    ".type _FUN_0603CC88, @function\n"
    "_FUN_0603CC88:\n"
    "_FUN_0603cc88:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x4F, 0x22, 0xDB, 0x2F, 0x9D, 0x5A, 0xDE, 0x2F\n"  /* 0x0603CC88 */
    ".byte 0x24, 0x48, 0x8F, 0x29, 0xEC, 0x01, 0x60, 0xC3, 0x91, 0x55, 0xD3, 0x2D, 0x43, 0x0B, 0x62, 0xB3\n"  /* 0x0603CC98 */
    ".byte 0x85, 0xE2, 0x65, 0x5F, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9, 0x32, 0x5C, 0x60, 0x2D, 0x81, 0xE2\n"  /* 0x0603CCA8 */
    ".byte 0x60, 0xC3, 0x91, 0x48, 0xD3, 0x26, 0x43, 0x0B, 0x62, 0xB3, 0x66, 0x6F, 0x85, 0xE3, 0x62, 0x03\n"  /* 0x0603CCB8 */
    ".byte 0x62, 0x2D, 0x22, 0xD9, 0x32, 0x6C, 0x60, 0x2D, 0x81, 0xE3, 0x60, 0xC3, 0x91, 0x3B, 0xD3, 0x20\n"  /* 0x0603CCC8 */
    ".byte 0x43, 0x0B, 0x62, 0xB3, 0x85, 0xE4, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9, 0x67, 0x7F, 0x32, 0x7C\n"  /* 0x0603CCD8 */
    ".byte 0x62, 0x2D, 0x60, 0x23, 0xA0, 0x28, 0x81, 0xE4, 0x60, 0xC3, 0x91, 0x2C, 0xD3, 0x18, 0x43, 0x0B\n"  /* 0x0603CCE8 */
    ".byte 0x62, 0xB3, 0x65, 0x5F, 0x85, 0xE5, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9, 0x32, 0x5C, 0x60, 0x2D\n"  /* 0x0603CCF8 */
    ".byte 0x81, 0xE5, 0x60, 0xC3, 0x91, 0x1F, 0xD3, 0x12, 0x43, 0x0B, 0x62, 0xB3, 0x85, 0xE6, 0x66, 0x6F\n"  /* 0x0603CD08 */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9, 0x32, 0x6C, 0x60, 0x2D, 0x81, 0xE6, 0x60, 0xC3, 0x91, 0x12\n"  /* 0x0603CD18 */
    ".byte 0xD3, 0x0B, 0x43, 0x0B, 0x62, 0xB3, 0x85, 0xE7, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9, 0x67, 0x7F\n"  /* 0x0603CD28 */
    ".byte 0x32, 0x7C, 0x62, 0x2D, 0x60, 0x23, 0x81, 0xE7, 0x4F, 0x26, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6\n"  /* 0x0603CD38 */
    ".byte 0x00, 0x0B, 0x6E, 0xF6, 0x01, 0xFF, 0x05, 0x01, 0x06, 0x0A, 0x4D, 0x58, 0x06, 0x0A, 0x4D, 0x46\n"  /* 0x0603CD48 */
    ".byte 0x06, 0x03, 0x4F, 0x78\n"  /* 0x0603CD58 */
);


/* dma_register_state_clear -- Reset all DMA channel shadow registers.
 * Shadow register array at 0x060A4D18 (8 unsigned shorts):
 *   [0] = control register (mode, enable bits)
 *   [1] = interrupt enable register
 *   [2]-[3] = channel config (source/dest/transfer size)
 *   [4] = channel enable (per-channel on/off bits)
 *   [5] = priority register (per-channel priority)
 *   [6] = additional control (timing, mode flags)
 *   [7] = extended priority register
 * Each AND-mask operation clears specific bit fields while
 * preserving others. Sync function (0x06034F78) called between
 * each register write to ensure hardware handshake. */
#if 0 /* dma_register_state_clear -- redirected to ASM import via linker PROVIDE */
void dma_register_state_clear()
/* REMOVED: conflicting alias */ // void FUN_0603CD5C(void) __attribute__((alias("dma_register_state_clear")));
{
  unsigned short mask_ffef;
  unsigned short mask_fffe;
  unsigned short mask_fffd;
  unsigned short mask_fffb;
  unsigned short mask_fff0;
  unsigned short *shadow_regs;
  char *temp;
  unsigned short mask_ffdf;
  shadow_regs = (unsigned short *)0x060A4D18;               /* DMA shadow registers */
  /* initial sync with hardware */
  (*(int(*)())0x06034F78)(0x060A4D18,0x060A4D58,1);         /* dma_sync */
  /* reg[0]: set mode bits from constants */
  *shadow_regs = *shadow_regs & DAT_0603ce8e | DAT_0603ce90;
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & (unsigned short)0x0000FFBF;  /* reg[6]: clear bit 6 */
  temp = (char *)0x0000FFDF;
  (*(int(*)())0x06034F78)();
  mask_ffdf = (unsigned short)temp;
  *shadow_regs = *shadow_regs & mask_ffdf | 0x20;           /* reg[0]: set bit 5 */
  temp = (char *)0x0000FFEF;
  (*(int(*)())0x06034F78)();
  mask_ffef = (unsigned short)temp;
  *shadow_regs = *shadow_regs & mask_ffef;                   /* reg[0]: clear bit 4 */
  temp = (char *)0x0000FFF0;
  (*(int(*)())0x06034F78)();
  mask_fff0 = (unsigned short)temp;
  *shadow_regs = *shadow_regs & mask_fff0 | 7;              /* reg[0]: set low 3 bits (mode 7) */
  /* reg[2]-[3]: clear channel config fields */
  (*(int(*)())0x06034F78)();
  shadow_regs[2] = shadow_regs[2] & mask_fff0;              /* reg[2]: clear low nibble */
  temp = (char *)0x0000FF0F;
  (*(int(*)())0x06034F78)();
  mask_fffe = (unsigned short)temp;
  shadow_regs[2] = shadow_regs[2] & mask_fffe;              /* reg[2]: clear nibble 1 */
  (*(int(*)())0x06034F78)();
  shadow_regs[2] = shadow_regs[2] & (unsigned short)0x0000F0FF;  /* reg[2]: clear nibble 2 */
  (*(int(*)())0x06034F78)();
  shadow_regs[2] = shadow_regs[2] & DAT_0603ce8e;           /* reg[2]: clear high nibble */
  (*(int(*)())0x06034F78)();
  shadow_regs[3] = shadow_regs[3] & mask_fff0;              /* reg[3]: clear low nibble */
  (*(int(*)())0x06034F78)();
  shadow_regs[3] = shadow_regs[3] & mask_fffe;              /* reg[3]: clear nibble 1 */
  /* reg[2]-[3]: second pass for remaining channels */
  (*(int(*)())0x06034F78)();
  shadow_regs[2] = shadow_regs[2] & mask_fff0;
  (*(int(*)())0x06034F78)();
  shadow_regs[2] = shadow_regs[2] & mask_fffe;
  (*(int(*)())0x06034F78)();
  shadow_regs[2] = shadow_regs[2] & (unsigned short)0x0000F0FF;
  (*(int(*)())0x06034F78)();
  shadow_regs[2] = shadow_regs[2] & DAT_0603ce8e;
  (*(int(*)())0x06034F78)();
  shadow_regs[3] = shadow_regs[3] & mask_fff0;
  (*(int(*)())0x06034F78)();
  shadow_regs[3] = shadow_regs[3] & mask_fffe;
  /* reg[4]: clear per-channel enable bits */
  temp = (char *)0x0000FFFE;
  (*(int(*)())0x06034F78)();
  mask_fffe = (unsigned short)temp;
  shadow_regs[4] = shadow_regs[4] & mask_fffe;              /* clear ch0 enable */
  temp = (char *)0x0000FFFD;
  (*(int(*)())0x06034F78)();
  mask_fffd = (unsigned short)temp;
  shadow_regs[4] = shadow_regs[4] & mask_fffd;              /* clear ch1 enable */
  temp = (char *)0x0000FFFB;
  (*(int(*)())0x06034F78)();
  mask_fff0 = mask_fff0 + 7;                                /* 0xFFF7 */
  mask_fffb = (unsigned short)temp;
  shadow_regs[4] = shadow_regs[4] & mask_fffb;              /* clear ch2 enable */
  (*(int(*)())0x06034F78)();
  shadow_regs[4] = shadow_regs[4] & mask_fff0;              /* clear ch3 enable */
  (*(int(*)())0x06034F78)();
  shadow_regs[4] = shadow_regs[4] & mask_ffef;              /* clear ch4 enable */
  (*(int(*)())0x06034F78)();
  shadow_regs[4] = shadow_regs[4] & mask_ffdf;              /* clear ch5 enable */
  /* reg[5]: clear priority bits (2-bit fields for each channel) */
  (*(int(*)())0x06034F78)();
  shadow_regs[5] = shadow_regs[5] & (unsigned short)0x0000FFFC;  /* ch0 priority */
  (*(int(*)())0x06034F78)();
  shadow_regs[5] = shadow_regs[5] & (unsigned short)0x0000FFF3;  /* ch1 priority */
  (*(int(*)())0x06034F78)();
  shadow_regs[5] = shadow_regs[5] & (unsigned short)0x0000FFCF;  /* ch2 priority */
  (*(int(*)())0x06034F78)();
  shadow_regs[5] = shadow_regs[5] & (unsigned short)0x0000FF3F;  /* ch3 priority */
  (*(int(*)())0x06034F78)();
  shadow_regs[5] = shadow_regs[5] & (unsigned short)0x0000FCFF;  /* ch4 priority */
  /* reg[6]: clear control/timing flags */
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & DAT_0603d034;
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & (unsigned short)0x00008FFF;  /* clear bits 12-14 */
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & (unsigned short)0x0000FBFF;  /* clear bit 10 */
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & (unsigned short)0x0000FDFF;  /* clear bit 9 */
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & (unsigned short)0x0000FEFF | DAT_0603d1c2;  /* set timing constant */
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & (unsigned short)0x0000FFBF;  /* clear bit 6 */
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & mask_ffdf;
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & mask_ffef;
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & mask_fff0;
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & mask_fffb;
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & mask_fffd;
  (*(int(*)())0x06034F78)();
  shadow_regs[6] = shadow_regs[6] & mask_fffe;
  /* reg[7]: clear extended priority bits */
  (*(int(*)())0x06034F78)();
  shadow_regs[7] = shadow_regs[7] & (unsigned short)0x0000FFFC;
  (*(int(*)())0x06034F78)();
  shadow_regs[7] = shadow_regs[7] & (unsigned short)0x0000FFF3;
  (*(int(*)())0x06034F78)();
  shadow_regs[7] = shadow_regs[7] & (unsigned short)0x0000FFCF;
  (*(int(*)())0x06034F78)();
  shadow_regs[7] = shadow_regs[7] & (unsigned short)0x0000FF3F;
  (*(int(*)())0x06034F78)();
  shadow_regs[7] = shadow_regs[7] & (unsigned short)0x0000FCFF;
  /* reg[1]: clear interrupt enable bits */
  (*(int(*)())0x06034F78)();
  shadow_regs[1] = shadow_regs[1] & mask_fffe;
  (*(int(*)())0x06034F78)();
  shadow_regs[1] = shadow_regs[1] & mask_fffd;
  (*(int(*)())0x06034F78)();
  shadow_regs[1] = shadow_regs[1] & mask_fffb;
  (*(int(*)())0x06034F78)();
  shadow_regs[1] = shadow_regs[1] & mask_fff0;
  (*(int(*)())0x06034F78)();
  shadow_regs[1] = shadow_regs[1] & mask_ffef;
  (*(int(*)())0x06034F78)();
  shadow_regs[1] = shadow_regs[1] & mask_ffdf;
  (*(int(*)())0x06034F78)();
  shadow_regs[1] = shadow_regs[1] & (unsigned short)0x0000FEFF;  /* clear bit 8 */
  (*(int(*)())0x06034F78)();
  return;
}
#endif /* dma_register_state_clear */

/* vdp2_palette_bank_init -- Clear palette assignment bits for 4 scroll planes.
 * VDP2 palette control registers at 0x060A4D28 (shadow copy).
 * For each of 4 planes (regs [0]-[3]), clears:
 *   - bits 0-3 (mask 0xFFF0): palette number low nibble
 *   - bits 8-11 (mask 0xF0FF): palette number high nibble
 * Each register write synced via 0x06034F78. */
#if 0 /* FUN_0603D2CC -- replaced by ASM import */
void FUN_0603d2cc()
{
  unsigned short *regs = (unsigned short *)0x060A4D28;
  unsigned short mask_lo = 0xFFF0;
  unsigned short mask_hi = 0xF0FF;
  (*(int(*)())0x06034F78)(0x060A4D28, 0x060A4D58, 1);  /* vdp2_reg_init */
  regs[0] = regs[0] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & mask_hi;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & mask_hi;
  (*(int(*)())0x06034F78)();
  regs[2] = regs[2] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[2] = regs[2] & mask_hi;
  (*(int(*)())0x06034F78)();
  regs[3] = regs[3] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[3] = regs[3] & mask_hi;
  (*(int(*)())0x06034F78)();
  return;
}
#endif

/* vdp2_scroll_plane_config -- Configure VDP2 scroll plane character/pattern.
 * VDP2 character control registers at 0x060A4D30.
 * Sets plane A: char size = 3 (low byte), pattern = DAT_0603d426 (high byte).
 * Sets plane B: char size = 1 (low byte), pattern cleared (high byte).
 * Sets plane C: fixed value 4. All writes synced via 0x06034F78. */
#if 0 /* FUN_0603D3A8 -- replaced by ASM import */
int FUN_0603d3a8()
{
  int result;
  unsigned short *regs = (unsigned short *)0x060A4D30;
  (*(int(*)())0x06034F78)(0x060A4D30, 1, 0x060A4D58);  /* vdp2_reg_init */
  regs[0] = (regs[0] & 0xFF00) | 3;              /* plane A char size = 3 */
  (*(int(*)())0x06034F78)();
  regs[0] = (regs[0] & 0xff) | DAT_0603d426;     /* plane A pattern number */
  (*(int(*)())0x06034F78)();
  regs[1] = (regs[1] & 0xFF00) | 1;              /* plane B char size = 1 */
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & 0xff;                      /* plane B pattern = 0 */
  (*(int(*)())0x06034F78)();
  regs[2] = 4;                                    /* plane C = 4 */
  result = (*(int(*)())0x06034F78)();
  return result;
}
#endif

/* FUN_0603D3A8 -- original binary (144 bytes) */
__asm__(
    ".section .text.FUN_0603D3A8, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603D3A8\n"
    ".global _FUN_0603d3a8\n"
    ".type _FUN_0603D3A8, @function\n"
    "_FUN_0603D3A8:\n"
    "_FUN_0603d3a8:\n"
    ".byte 0x4F, 0x22, 0xE5, 0x01, 0xD7, 0x1E, 0xD6, 0x1F, 0xD4, 0x1F, 0x91, 0x37, 0xD3, 0x1F, 0x60, 0x53\n"  /* 0x0603D3A8 */
    ".byte 0x43, 0x0B, 0x62, 0x63, 0x60, 0x41, 0x60, 0x0D, 0x20, 0x79, 0xCB, 0x03, 0x24, 0x01, 0x60, 0x53\n"  /* 0x0603D3B8 */
    ".byte 0x91, 0x2C, 0xD3, 0x1A, 0x43, 0x0B, 0x62, 0x63, 0x60, 0x41, 0x93, 0x28, 0x60, 0x0D, 0xC9, 0xFF\n"  /* 0x0603D3C8 */
    ".byte 0x20, 0x3B, 0x24, 0x01, 0x60, 0x53, 0x91, 0x21, 0xD3, 0x14, 0x43, 0x0B, 0x62, 0x63, 0x85, 0x41\n"  /* 0x0603D3D8 */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x79, 0x22, 0x5B, 0x60, 0x2D, 0x81, 0x41, 0x60, 0x53, 0x91, 0x15\n"  /* 0x0603D3E8 */
    ".byte 0xD3, 0x0E, 0x43, 0x0B, 0x62, 0x63, 0x85, 0x41, 0x60, 0x0D, 0xC9, 0xFF, 0x81, 0x41, 0x60, 0x53\n"  /* 0x0603D3F8 */
    ".byte 0x91, 0x0C, 0xD3, 0x0A, 0x43, 0x0B, 0x62, 0x63, 0xE0, 0x04, 0x81, 0x42, 0x60, 0x53, 0x91, 0x05\n"  /* 0x0603D408 */
    ".byte 0xD3, 0x06, 0x43, 0x0B, 0x62, 0x63, 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09, 0x02, 0x01, 0x02, 0x00\n"  /* 0x0603D418 */
    ".byte 0x00, 0x00, 0xFF, 0x00, 0x06, 0x0A, 0x4D, 0x58, 0x06, 0x0A, 0x4D, 0x30, 0x06, 0x03, 0x4F, 0x78\n"  /* 0x0603D428 */
);


/* vdp2_map_offset_init -- Clear VDP2 map offset registers for 4 planes.
 * Register block at 0x060A4D36 (shadow copy of VDP2 map offset regs).
 * For each of 4 planes: clears low byte (mask 0xFF00) and high nibble
 * (mask DAT_0603d500). All writes synced via 0x06034F78. */
#if 0 /* FUN_0603D438 -- replaced by ASM import */
void FUN_0603d438()
{
  unsigned short *regs = (unsigned short *)0x060A4D36;
  unsigned short mask_lo = 0xFF00;
  unsigned short mask_hi = DAT_0603d500;
  (*(int(*)())0x06034F78)(0x060A4D36, 0x060A4D58, 1);  /* vdp2_reg_init */
  regs[0] = regs[0] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & mask_hi;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & mask_hi;
  (*(int(*)())0x06034F78)();
  regs[2] = regs[2] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[2] = regs[2] & mask_hi;
  (*(int(*)())0x06034F78)();
  regs[3] = regs[3] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[2] = regs[2] & mask_hi;  /* note: reg[2] written twice (original) */
  (*(int(*)())0x06034F78)();
  return;
}
#endif

/* vdp2_color_calc_init -- Initialize VDP2 color calculation registers.
 * Register block at 0x060A4D3E (shadow copy of VDP2 color calc regs).
 * Clears low byte (mask 0xFF00) and high bits (mask DAT_0603d5be) for
 * regs 0, 1, 3. Zeros reg 2 entirely. All writes synced via 0x06034F78. */
#if 0 /* FUN_0603D514 -- replaced by ASM import */
void FUN_0603d514()
{
  unsigned short *regs = (unsigned short *)0x060A4D3E;
  unsigned short mask_lo = 0xFF00;
  unsigned short mask_hi = DAT_0603d5be;
  (*(int(*)())0x06034F78)(0x060A4D3E, 0x060A4D58, 1);  /* vdp2_reg_init */
  regs[0] = regs[0] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & mask_hi;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & mask_hi;
  (*(int(*)())0x06034F78)();
  regs[2] = 0;                  /* color offset = 0 */
  (*(int(*)())0x06034F78)();
  regs[3] = regs[3] & mask_lo;
  (*(int(*)())0x06034F78)();
  regs[3] = regs[3] & mask_hi;
  (*(int(*)())0x06034F78)();
  return;
}
#endif

/* vdp2_special_func_init -- Initialize VDP2 special function/priority registers.
 * Register block at 0x060A4D46 (shadow copy of VDP2 special function regs).
 * Clears bits 0-6 individually on regs[0] and regs[1] (priority per plane),
 * then zeros regs[2]-[7] (special function/line color/back screen).
 * All writes synced via 0x06034F78. */
#if 0 /* FUN_0603D5D0 -- replaced by ASM import */
int FUN_0603d5d0()
{
  int result;
  unsigned short *regs = (unsigned short *)0x060A4D46;
  (*(int(*)())0x06034F78)(0x060A4D46, 0x060A4D58, 1);  /* vdp2_reg_init */
  /* clear bits 0-6 of reg[0] (plane priorities) */
  regs[0] = regs[0] & (unsigned short)0x0000FFFE;  /* bit 0 */
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & (unsigned short)0x0000FFFD;  /* bit 1 */
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & (unsigned short)0x0000FFFB;  /* bit 2 */
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & (unsigned short)0x0000FFF7;  /* bit 3 */
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & (unsigned short)0x0000FFEF;  /* bit 4 */
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & (unsigned short)0x0000FFDF;  /* bit 5 */
  (*(int(*)())0x06034F78)();
  regs[0] = regs[0] & (unsigned short)0x0000FFBF;  /* bit 6 */
  (*(int(*)())0x06034F78)();
  /* clear bits 0-6 of reg[1] */
  regs[1] = regs[1] & (unsigned short)0x0000FFFE;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & (unsigned short)0x0000FFFD;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & (unsigned short)0x0000FFFB;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & (unsigned short)0x0000FFF7;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & (unsigned short)0x0000FFEF;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & (unsigned short)0x0000FFDF;
  (*(int(*)())0x06034F78)();
  regs[1] = regs[1] & (unsigned short)0x0000FFBF;
  (*(int(*)())0x06034F78)();
  /* zero regs[2]-[7] (special function data) */
  regs[2] = 0;
  (*(int(*)())0x06034F78)();
  regs[3] = 0;
  (*(int(*)())0x06034F78)();
  regs[4] = 0;
  (*(int(*)())0x06034F78)();
  regs[5] = 0;
  (*(int(*)())0x06034F78)();
  regs[6] = 0;
  (*(int(*)())0x06034F78)();
  regs[7] = 0;
  result = (*(int(*)())0x06034F78)();
  return result;
}
#endif

/* FUN_0603D5D0 -- original binary (480 bytes) */
__asm__(
    ".section .text.FUN_0603D5D0, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603D5D0\n"
    ".global _FUN_0603d5d0\n"
    ".type _FUN_0603D5D0, @function\n"
    "_FUN_0603D5D0:\n"
    "_FUN_0603d5d0:\n"
    ".byte 0x4F, 0x22, 0xE6, 0x01, 0xD7, 0x42, 0xD5, 0x43, 0xD4, 0x43, 0x91, 0x7F, 0xD3, 0x43, 0x60, 0x63\n"  /* 0x0603D5D0 */
    ".byte 0x43, 0x0B, 0x62, 0x53, 0x62, 0x41, 0x60, 0x63, 0x62, 0x2D, 0x22, 0x79, 0x24, 0x21, 0x91, 0x75\n"  /* 0x0603D5E0 */
    ".byte 0xD3, 0x3E, 0x43, 0x0B, 0x62, 0x53, 0x60, 0x63, 0x62, 0x41, 0xD3, 0x3D, 0x62, 0x2D, 0x22, 0x39\n"  /* 0x0603D5F0 */
    ".byte 0x24, 0x21, 0x91, 0x6B, 0xD3, 0x39, 0x43, 0x0B, 0x62, 0x53, 0x60, 0x63, 0x62, 0x41, 0xD3, 0x39\n"  /* 0x0603D600 */
    ".byte 0x62, 0x2D, 0x22, 0x39, 0x24, 0x21, 0x91, 0x61, 0xD3, 0x34, 0x43, 0x0B, 0x62, 0x53, 0x60, 0x63\n"  /* 0x0603D610 */
    ".byte 0x62, 0x41, 0xD3, 0x35, 0x62, 0x2D, 0x22, 0x39, 0x24, 0x21, 0x91, 0x57, 0xD3, 0x2F, 0x43, 0x0B\n"  /* 0x0603D620 */
    ".byte 0x62, 0x53, 0x60, 0x63, 0x62, 0x41, 0xD3, 0x31, 0x62, 0x2D, 0x22, 0x39, 0x24, 0x21, 0x91, 0x4D\n"  /* 0x0603D630 */
    ".byte 0xD3, 0x2A, 0x43, 0x0B, 0x62, 0x53, 0x60, 0x63, 0x62, 0x41, 0xD3, 0x2D, 0x62, 0x2D, 0x22, 0x39\n"  /* 0x0603D640 */
    ".byte 0x24, 0x21, 0x91, 0x43, 0xD3, 0x25, 0x43, 0x0B, 0x62, 0x53, 0x60, 0x63, 0x62, 0x41, 0xD3, 0x29\n"  /* 0x0603D650 */
    ".byte 0x62, 0x2D, 0x22, 0x39, 0x24, 0x21, 0x91, 0x39, 0xD3, 0x20, 0x43, 0x0B, 0x62, 0x53, 0x85, 0x41\n"  /* 0x0603D660 */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x79, 0x60, 0x2D, 0x81, 0x41, 0x60, 0x63, 0x91, 0x2E, 0xD3, 0x1B\n"  /* 0x0603D670 */
    ".byte 0x43, 0x0B, 0x62, 0x53, 0x85, 0x41, 0xD3, 0x1A, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603D680 */
    ".byte 0x81, 0x41, 0x60, 0x63, 0x91, 0x22, 0xD3, 0x15, 0x43, 0x0B, 0x62, 0x53, 0x85, 0x41, 0xD3, 0x15\n"  /* 0x0603D690 */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x81, 0x41, 0x60, 0x63, 0x91, 0x16, 0xD3, 0x0F\n"  /* 0x0603D6A0 */
    ".byte 0x43, 0x0B, 0x62, 0x53, 0x85, 0x41, 0xD3, 0x10, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603D6B0 */
    ".byte 0x81, 0x41, 0x60, 0x63, 0x91, 0x0A, 0xD3, 0x09, 0x43, 0x0B, 0x62, 0x53, 0x85, 0x41, 0x62, 0x03\n"  /* 0x0603D6C0 */
    ".byte 0x62, 0x2D, 0xD3, 0x0A, 0x22, 0x39, 0x60, 0x2D, 0xA0, 0x16, 0x00, 0x09, 0x05, 0x01, 0xFF, 0xFF\n"  /* 0x0603D6D0 */
    ".byte 0x00, 0x00, 0xFF, 0xFE, 0x06, 0x0A, 0x4D, 0x58, 0x06, 0x0A, 0x4D, 0x46, 0x06, 0x03, 0x4F, 0x78\n"  /* 0x0603D6E0 */
    ".byte 0x00, 0x00, 0xFF, 0xFD, 0x00, 0x00, 0xFF, 0xFB, 0x00, 0x00, 0xFF, 0xF7, 0x00, 0x00, 0xFF, 0xEF\n"  /* 0x0603D6F0 */
    ".byte 0x00, 0x00, 0xFF, 0xDF, 0x00, 0x00, 0xFF, 0xBF, 0x81, 0x41, 0x60, 0x63, 0x91, 0x48, 0xD3, 0x25\n"  /* 0x0603D700 */
    ".byte 0x43, 0x0B, 0x62, 0x53, 0x85, 0x41, 0xD3, 0x24, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603D710 */
    ".byte 0x81, 0x41, 0x60, 0x63, 0x91, 0x3C, 0xD3, 0x1F, 0x43, 0x0B, 0x62, 0x53, 0x85, 0x41, 0xE7, 0x00\n"  /* 0x0603D720 */
    ".byte 0xD3, 0x1E, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x81, 0x41, 0x60, 0x63, 0x91, 0x2F\n"  /* 0x0603D730 */
    ".byte 0xD3, 0x18, 0x43, 0x0B, 0x62, 0x53, 0x60, 0x7D, 0x81, 0x42, 0x60, 0x63, 0x91, 0x28, 0xD3, 0x15\n"  /* 0x0603D740 */
    ".byte 0x43, 0x0B, 0x62, 0x53, 0x60, 0x7D, 0x81, 0x43, 0x60, 0x63, 0x91, 0x21, 0xD3, 0x11, 0x43, 0x0B\n"  /* 0x0603D750 */
    ".byte 0x62, 0x53, 0x60, 0x7D, 0x81, 0x44, 0x60, 0x63, 0x91, 0x1A, 0xD3, 0x0E, 0x43, 0x0B, 0x62, 0x53\n"  /* 0x0603D760 */
    ".byte 0x60, 0x7D, 0x81, 0x45, 0x60, 0x63, 0x91, 0x13, 0xD3, 0x0A, 0x43, 0x0B, 0x62, 0x53, 0x60, 0x7D\n"  /* 0x0603D770 */
    ".byte 0x81, 0x46, 0x60, 0x63, 0x91, 0x0C, 0xD3, 0x07, 0x43, 0x0B, 0x62, 0x53, 0x60, 0x7D, 0x81, 0x47\n"  /* 0x0603D780 */
    ".byte 0x60, 0x63, 0x91, 0x05, 0xD3, 0x03, 0x43, 0x0B, 0x62, 0x53, 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x0603D790 */
    ".byte 0x05, 0x01, 0xFF, 0xFF, 0x06, 0x03, 0x4F, 0x78, 0x00, 0x00, 0xFF, 0xDF, 0x00, 0x00, 0xFF, 0xBF\n"  /* 0x0603D7A0 */
);


/* fixedpoint_sine -- Compute fixed-point sine from angle.
 * Uses piecewise lookup via 0x060424A2 (cd_lba_to_msf_seconds).
 * Angle quadrant mapping:
 *   0..0x5A0000: direct lookup (Q1)
 *   0x5A0000..0xB40000: mirror (Q2, use 0xB40000-angle)
 *   0xB40000..0x10E0000: negate (Q3, use angle-0xB40000)
 *   >= 0x10E0000: negate mirror (Q4, use 0x1680000-angle)
 * Clamps 0xFFFF to 0x10000. Negates if sign bit set. */
char * FUN_0603d9ec(param_1)
    unsigned int param_1;
{
  int angle;
  char *result;
  param_1 = 0x80000000 & param_1;  /* save sign bit */
  angle = (*(int(*)())0x06036BE4)();
  if (angle < (int)0x010E0000) {
    if (angle < (int)0x00B40000) {
      if ((int)0x005A0000 <= angle) {
        angle = (int)0x00B40000 - angle;  /* Q2: mirror */
      }
      result = (char *)(*(int(*)())0x060424A2)(angle);
    } else {
      /* Q3: negate */
      angle = (*(int(*)())0x060424A2)(0xFF4C0000 + angle);
      result = (char *)-angle;
    }
  } else {
    /* Q4: negate mirror */
    angle = (*(int(*)())0x060424A2)((int)0x01680000 - angle);
    result = (char *)-angle;
  }
  if (result == (char *)0x0000FFFF) {
    result = (char *)0x00010000;  /* clamp to 1.0 */
  }
  if (param_1 != 0) {
    result = (char *)-(int)result;  /* apply sign */
  }
  return result;
}

/* fixedpoint_cosine -- Compute fixed-point cosine from angle.
 * Uses piecewise lookup via 0x0604249C (cd_lba_to_msf_minutes).
 * Returns 0x10000 (1.0) for angle == 0. Quadrant mapping:
 *   0..0x5A0000: direct lookup (Q1)
 *   0x5A0000..0xB40000: negate mirror (Q2)
 *   0xB40000 exactly: returns -1.0 (0xFFFF0000)
 *   0xB40000..0x10E0000: negate (Q3)
 *   >= 0x10E0000: direct (Q4, use 0x1680000-angle) */
char * FUN_0603da88()
{
  char *angle;
  char *result;
  int lookup;
  angle = (char *)(*(int(*)())0x06036BE4)();
  result = (char *)0x00010000;     /* default: cos(0) = 1.0 */
  if (angle != (char *)0x0) {
    if ((int)angle < (int)0x010E0000) {
      if ((int)0x00B40000 < (int)angle) {
        /* Q3: negate */
        lookup = (*(int(*)())0x0604249C)(angle + 0xFF4C0000);
        result = (char *)-lookup;
      } else {
        result = (char *)0xFFFF0000;  /* cos(180) = -1.0 */
        if (angle != (char *)0x00B40000) {
          if ((int)angle < (int)0x005A0000) {
            /* Q1: direct */
            result = (char *)(*(int(*)())0x0604249C)(angle);
          } else {
            /* Q2: negate mirror */
            lookup = (*(int(*)())0x0604249C)((int)0x00B40000 - (int)angle);
            result = (char *)-lookup;
          }
        }
      }
    } else {
      /* Q4: direct */
      result = (char *)(*(int(*)())0x0604249C)((int)0x01680000 - (int)angle);
    }
  }
  return result;
}

#if 0 /* FUN_0603ddfc -- replaced by ASM import below */
short * FUN_0603ddfc(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  short sVar1;

  short sVar2;

  short sVar3;

  short sVar4;

  char *puVar5;

  char *puVar6;

  char *puVar7;

  char *puVar8;

  char *puVar9;

  char *puVar10;

  char *puVar11;

  short *psVar12;

  unsigned short uVar15;

  int iVar13;

  int uVar14;

  int iVar16;

  char *puVar17;

  int *puVar18;

  int iVar19;

  int iVar20;

  unsigned int uVar21;

  int *piVar22;

  unsigned int uVar23;

  char cVar24;

  unsigned short uVar25;

  int ***pppiVar26;

  int iVar27;

  int iVar28;

  char *local_9c;

  int local_98;

  char *local_90 [2];

  char auStack_88 [8];

  short *local_80;

  int **local_7c;

  unsigned int **local_78;

  char *local_74;

  unsigned int *local_70;

  int *local_6c;

  int *piStack_68;

  unsigned int *local_64;

  int *local_60;

  int *local_5c;

  int *local_58;

  int *piStack_54;

  int iStack_50;

  int iStack_4c;

  int *piStack_48;

  int *piStack_44;

  int *piStack_40;

  int *piStack_3c;

  int *piStack_38;

  int *piStack_34;

  int *piStack_30;

  int *piStack_2c;

  int iStack_28;

  puVar7 = (char *)0x00010000;

  puVar17 = (char *)0x060A4C60;

  puVar6 = (char *)0x060A4C68;

  puVar5 = (char *)0x060A53B8;

  psVar12 = *(short **)0x060635A8;

  if (psVar12 == (short *)(void *)0x00000001) {

    uVar25 = 0;

  }

  else {

    if (psVar12 != (short *)(void *)0x00000002) {

      return psVar12;

    }

    uVar25 = 1;

  }

  cVar24 = (char)uVar25;

  puVar18 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

  *puVar18 = (int *)0x00010000;

  puVar18[1] = 0;

  puVar18[2] = 0;

  puVar18[3] = 0;

  puVar18[4] = puVar7;

  puVar18[5] = 0;

  puVar18[6] = 0;

  puVar18[7] = 0;

  puVar18[8] = puVar7;

  if (*(int *)(0x060A4C44 + (unsigned int)(uVar25 << 2)) == 0) {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = 0;

  }

  else {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) + param_1;

  }

  *(int *)(puVar6 + (unsigned int)(uVar25 << 2)) = *(int *)(puVar6 + (unsigned int)(uVar25 << 2)) + param_2;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) && (param_1 != 0)) {

    if (*(int *)0x060635A8 == 1) {

      uVar15 = *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00;

    }

    else {

      if (*(int *)0x060635A8 != 2) goto LAB_0603dedc;

      uVar15 = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

    }

    *(unsigned short *)(0x060A3E38 + 4) = uVar15;

  }

LAB_0603dedc:

  if (param_3 != 0) {

    FUN_0603ec40(param_3);

  }

  if ((*(int *)(0x060A4C4C + (unsigned int)(uVar25 << 2)) != 0) &&

     (*(int *)(0x060A4C70 + (unsigned int)(uVar25 << 2)) != 0)) {

    *(int *)(puVar17 + (unsigned int)(uVar25 << 2)) = 0;

  }

  puVar7 = (char *)0x060A3E68;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) &&

     (*(int *)(0x060A4C78 + (unsigned int)(uVar25 << 2)) == 0)) {

    if (((uVar25 == 0) && ((*(unsigned short *)0x060A3E3C & 0xff) != 0)) ||

       ((uVar25 == 1 && (((unsigned int)*(unsigned short *)0x060A3E3C & (unsigned int)0x0000FF00) != 0)))) {

      puVar18 = (int *)(puVar5 + (char)(cVar24 * '$'));

      *puVar18 = *(int *)(0x060A3E68 + (unsigned int)(uVar25 << 7) + 0x4c);

      puVar18[4] = *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

      *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x1c) =

           *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x4c);

      *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x2c) =

           *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

    }

  }

  else {

    puVar18 = (int *)(puVar5 + (char)(cVar24 * '$'));

    *puVar18 = *(int *)(0x060A3E68 + (unsigned int)(uVar25 << 7) + 0x4c);

    puVar18[4] = *(int *)(puVar7 + (unsigned int)(uVar25 << 7) + 0x50);

  }

  if (*(int *)(puVar6 + (unsigned int)(uVar25 << 2)) != 0) {

    FUN_0603eacc(*(int *)(puVar6 + (unsigned int)(uVar25 << 2)));

  }

  puVar11 = (char *)0x060A3E38;

  puVar10 = (char *)0x0603C0A0;

  puVar9 = (char *)0x00040000;

  sVar1 = DAT_0603e61e;

  puVar8 = (char *)0x060A3E38;

  puVar7 = (char *)0x0603C0A0;

  puVar6 = (char *)0x00008000;

  puVar5 = (char *)0x00040000;

  if ((*(int *)(puVar17 + (unsigned int)(uVar25 << 2)) == 0) &&

     (*(int *)(0x060A4C78 + (unsigned int)(uVar25 << 2)) == 0)) {

    return (short *)0x0;

  }

  if ((*(short *)(0x060A4C54 + (unsigned int)(uVar25 << 1)) != 0) &&

     (*(int *)(0x060A4C4C + (unsigned int)(uVar25 << 2)) == 0)) {

    iStack_50 = *(int *)(puVar17 + (unsigned int)(uVar25 << 2));

    uVar21 = (unsigned int)DAT_0603e61e;

    sVar2 = DAT_0603e61e + 1;

    psVar12 = *(short **)0x060635A8;

    if (psVar12 == (short *)(void *)0x00000001) {

      uVar15 = 0;

      *(unsigned short *)(0x060A3E38 + 4) =

           *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00;

      uVar25 = *(unsigned short *)(puVar11 + 4) | 3;

    }

    else {

      if (psVar12 != (short *)(void *)0x00000002) {

        return psVar12;

      }

      uVar15 = 1;

      *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

      uVar25 = *(unsigned short *)(puVar11 + 4) | PTR_DAT_0603e620;

    }

    *(unsigned short *)(puVar11 + 4) = uVar25;

    local_58 = (int *)FUN_0603d9ec(iStack_50);

    iStack_50 = FUN_0603da88(iStack_50);

    puVar5 = (char *)0x0603C08C;

    cVar24 = (char)uVar15;

    piVar22 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

    piStack_30 = (int *)*piVar22;

    piStack_40 = piVar22 + 2;

    piStack_48 = (int *)*piStack_40;

    piStack_38 = piVar22 + 3;

    iStack_4c = *piStack_38;

    piStack_3c = piVar22 + 5;

    piStack_2c = (int *)*piStack_3c;

    piStack_44 = piVar22 + 6;

    iStack_28 = *piStack_44;

    piStack_54 = piVar22 + 8;

    piStack_34 = (int *)*piStack_54;

    local_5c = (int *)(*(int(*)())0x0603C08C)(piStack_30,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_48,local_58);

    *piVar22 = (int)local_5c - iVar13;

    local_5c = piStack_40;

    local_60 = (int *)(*(int(*)())puVar5)(piStack_30,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_48,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    local_5c = piStack_38;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_4c,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_2c,local_58);

    *local_5c = (int)local_60 - iVar13;

    local_5c = piStack_3c;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_4c,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_2c,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    local_5c = piStack_44;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_28,iStack_50);

    iVar13 = (*(int(*)())puVar5)(piStack_34,local_58);

    *local_5c = (int)local_60 - iVar13;

    local_5c = piStack_54;

    local_60 = (int *)(*(int(*)())puVar5)(iStack_28,local_58);

    iVar13 = (*(int(*)())puVar5)(piStack_34,iStack_50);

    *local_5c = iVar13 + (int)local_60;

    puVar5 = (char *)0x060A3E68;

    *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x1c) = *piVar22;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x24) = *piStack_40;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x28) = *piStack_38;

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x2c) = piVar22[4];

    *(int *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x30) = *piStack_3c;

    sVar3 = *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x34);

    sVar4 = *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x3c);

    iVar20 = *piStack_44;

    local_58 = (int *)piVar22[7];

    iStack_50 = (int)*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x36);

    iVar27 = (int)local_58 * (iStack_50 - *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x3e));

    iVar16 = *piStack_54;

    iVar19 = (int)*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x38);

    iStack_4c = ((*(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x40)) << 16 | (iStack_4c) & 0xFFFF);

    iVar28 = iVar16 * (iVar19 - *(short *)(puVar5 + (unsigned int)(uVar15 << 7) + 0x40));

    local_6c = (int *)&local_6c;

    (*(int(*)())0x060358EC)();

    local_70 = (unsigned int *)0x0;

    local_74 = (char *)0x40F00000;

    local_78 = &local_64;

    (*(int(*)())0x060359E4)();

    iVar13 = (*(int(*)())0x060357B8)();

    puVar5 = (char *)0x005A0000;

    iVar13 = iVar20 * ((int)sVar3 - (int)sVar4) + iVar27 + iVar28 + iVar13 +

             *(int *)(0x060A4C78 + (unsigned int)(uVar15 << 2));

    local_70 = (unsigned int *)(-(iVar19 * iVar16) - (int)local_70 * (int)local_78);

    if (*(int *)(0x060A4C70 + (unsigned int)(uVar15 << 2)) == 0) {

      puVar18 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      puVar18[0x15] = *puVar18;

      uVar14 = FUN_0603da88(puVar5);

      puVar5 = (char *)0x005A0000;

      puVar18[0x16] = uVar14;

      uVar14 = FUN_0603d9ec(puVar5);

      puVar18[0x17] = uVar14;

      puVar5 = (char *)0x060A4C38;

      *(unsigned int *)(0x060A4C38 + (unsigned int)(uVar15 << 2)) = *(unsigned short *)0x060635AE - 1;

      local_64 = (unsigned int *)(puVar5 + (unsigned int)(uVar15 << 2));

      piStack_68 = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x18);

      local_6c = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      local_74 = 0x060A3F68 + (short)(uVar15 * DAT_0603ea46);

      psVar12 = (short *)0x060A3F68;

      for (uVar23 = 0; uVar23 < *local_64; uVar23 = uVar23 + 1) {

        local_78 = (unsigned int **)(*piStack_68 * (uVar23 - (int)*(short *)(local_6c + 0xd)) +

                            (int)local_70);

        iVar16 = (*(int(*)())0x06034FFC)();

        if (iVar16 == 0) {

          psVar12 = (short *)(local_74 + (uVar23 << 1));

LAB_0603ea9c:

          *psVar12 = sVar1 + 1;

        }

        else {

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          local_7c = (int **)(unsigned int)((int)puVar9 < -iVar16);

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          if (-iVar16 < 0 || local_7c != (int **)0x0) {

            psVar12 = (short *)(local_74 + (uVar23 << 1));

            goto LAB_0603ea9c;

          }

          local_7c = (int **)(local_74 + (uVar23 << 1));

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & uVar21);

          *(short *)local_7c = (short)psVar12;

        }

      }

    }

    else {

      local_74 = (char *)((unsigned int)(uVar15 << 2));

      piVar22 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      piVar22[0x15] = (int)(0x012C0000 + *piVar22);

      local_78 = (unsigned int **)(0x060A4C70 + (int)local_74);

      iVar16 = FUN_0603da88(0x005A0000 + (int)*local_78);

      piVar22[0x16] = iVar16;

      iVar16 = FUN_0603d9ec(0x005A0000 + (int)*local_78);

      piVar22[0x17] = iVar16;

      puVar5 = (char *)0x060A4C38;

      *(int *)(0x060A4C38 + (int)local_74) = (int)DAT_0603e93a;

      local_64 = (unsigned int *)(puVar5 + (unsigned int)(uVar15 << 2));

      piStack_68 = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x18);

      local_6c = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

      local_74 = 0x060A3F68 + (short)(uVar15 * DAT_0603e93c);

      psVar12 = (short *)0x060A3F68;

      for (uVar23 = 0; uVar23 < *local_64; uVar23 = uVar23 + 1) {

        local_78 = (unsigned int **)(*piStack_68 *

                             ((uVar23 - (int)*(short *)(local_6c + 0xd)) + (int)DAT_0603e93e) +

                            (int)local_70);

        iVar16 = (*(int(*)())0x06034FFC)();

        if (iVar16 == 0) {

          psVar12 = (short *)(local_74 + (uVar23 << 1));

LAB_0603e964:

          *psVar12 = sVar2;

        }

        else {

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          local_7c = (int **)(unsigned int)((int)puVar9 < -iVar16);

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          if (-iVar16 < 0 || local_7c != (int **)0x0) {

            psVar12 = (short *)(local_74 + (uVar23 << 1));

            goto LAB_0603e964;

          }

          local_7c = (int **)(local_74 + (uVar23 << 1));

          iVar16 = (*(int(*)())puVar10)(iVar13,local_78);

          psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & uVar21);

          *(short *)local_7c = (short)psVar12;

        }

      }

    }

    *(short *)(0x060A4C40 + (unsigned int)(uVar15 << 1)) = 1;

    return psVar12;

  }

  piStack_54 = *(int **)(puVar17 + (unsigned int)(uVar25 << 2));

  psVar12 = *(short **)0x060635A8;

  if (psVar12 == (short *)(void *)0x00000001) {

    uVar15 = 0;

    *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & (unsigned short)0x0000FF00

    ;

    uVar25 = *(unsigned short *)(puVar8 + 4) | 3;

  }

  else {

    if (psVar12 != (short *)(void *)0x00000002) {

      return psVar12;

    }

    uVar15 = 1;

    *(unsigned short *)(0x060A3E38 + 4) = *(unsigned short *)(0x060A3E38 + 4) & 0xff;

    uVar25 = *(unsigned short *)(puVar8 + 4) | DAT_0603e0b2;

  }

  *(unsigned short *)(puVar8 + 4) = uVar25;

  local_5c = (int *)FUN_0603d9ec(piStack_54);

  piStack_54 = (int *)FUN_0603da88(piStack_54);

  puVar17 = (char *)0x0603C08C;

  cVar24 = (char)uVar15;

  puVar18 = (int *)(0x060A53B8 + (char)(cVar24 * '$'));

  local_60 = puVar18 + 1;

  iStack_50 = *local_60;

  piStack_30 = puVar18 + 2;

  iStack_28 = *piStack_30;

  piStack_34 = puVar18 + 4;

  piStack_38 = (int *)*piStack_34;

  piStack_40 = puVar18 + 5;

  piStack_3c = (int *)*piStack_40;

  piStack_48 = puVar18 + 7;

  piStack_44 = (int *)*piStack_48;

  local_58 = puVar18 + 8;

  iStack_4c = *local_58;

  piStack_2c = local_60;

  local_64 = (unsigned int *)(*(int(*)())0x0603C08C)(iStack_50,piStack_54);

  iVar13 = (*(int(*)())puVar17)(iStack_28,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_30;

  iVar13 = (*(int(*)())puVar17)(iStack_50,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(iStack_28,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_34;

  local_64 = (unsigned int *)(*(int(*)())puVar17)(piStack_38,piStack_54);

  iVar13 = (*(int(*)())puVar17)(piStack_3c,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_40;

  iVar13 = (*(int(*)())puVar17)(piStack_38,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(piStack_3c,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  local_60 = piStack_48;

  local_64 = (unsigned int *)(*(int(*)())puVar17)(piStack_44,piStack_54);

  iVar13 = (*(int(*)())puVar17)(iStack_4c,local_5c);

  *local_60 = iVar13 + (int)local_64;

  local_60 = local_58;

  iVar13 = (*(int(*)())puVar17)(piStack_44,local_5c);

  local_64 = (unsigned int *)-iVar13;

  iVar13 = (*(int(*)())puVar17)(iStack_4c,piStack_54);

  *local_60 = iVar13 + (int)local_64;

  puVar17 = (char *)0x060A3E68;

  *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x1c) = *puVar18;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x20) = *piStack_2c;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x24) = *piStack_30;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x2c) = *piStack_34;

  *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x30) = *piStack_40;

  iVar20 = puVar18[6];

  iVar19 = (int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x34);

  iVar27 = iVar20 * (iVar19 - *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x3c));

  iVar16 = *piStack_48;

  sVar1 = *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x36);

  sVar2 = *(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x3e);

  piStack_54 = (int *)*local_58;

  local_5c = (int *)(int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x38);

  iVar28 = (int)piStack_54 * ((int)local_5c - (int)*(short *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x40))

  ;

  local_70 = (unsigned int *)&local_70;

  (*(int(*)())0x060358EC)();

  local_74 = (char *)0x0;

  local_78 = (unsigned int **)0x40F00000;

  local_7c = &piStack_68;

  pppiVar26 = &local_7c;

  (*(int(*)())0x060359E4)();

  iVar13 = (*(int(*)())0x060357B8)();

  puVar17 = (char *)0x060A3E68;

  local_70 = (unsigned int *)((unsigned int)(uVar15 << 2));

  iVar13 = iVar27 + iVar16 * ((int)sVar1 - (int)sVar2) + iVar28 + iVar13 +

           *(int *)(0x060A4C78 + (int)local_70);

  local_74 = (char *)(-((int)local_7c * (int)local_74) - iVar19 * iVar20);

  if (*(int *)(0x060A4C70 + (int)local_70) == 0) {

    if ((*(int *)(0x060A4C4C + (unsigned int)(uVar15 << 2)) == -1) ||

       (*(int *)(0x060A4C4C + (unsigned int)(uVar15 << 2)) == 0)) {

      *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x54) =

           *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 4);

    }

    else {

      puVar17 = 0x060A3E68 + (unsigned int)(uVar15 << 7);

      local_90[0] = (char *)local_90;

      (*(int(*)())0x060358EC)();

      local_98 = 0x40F00000;

      local_9c = auStack_88;

      pppiVar26 = (int ***)&local_9c;

      (*(int(*)())0x060359E4)();

      iVar16 = (*(int(*)())0x060357B8)();

      *(int *)(puVar17 + 0x54) = iVar16 + *(int *)(puVar17 + 4);

    }

    *pppiVar26 = (int **)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    ((int *)pppiVar26)[-1] = (int)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x58);

    uVar14 = FUN_0603da88(0);

    *(int *)((int *)pppiVar26)[-1] = uVar14;

    ((int *)pppiVar26)[-1] = (int)*pppiVar26 + 0x5c;

    uVar14 = FUN_0603d9ec(0);

    *(int *)((int *)pppiVar26)[-1] = uVar14;

    puVar17 = (char *)0x060A4C38;

    *(unsigned int *)(0x060A4C38 + (unsigned int)(uVar15 << 2)) = *(unsigned short *)0x060635B0 - 1;

    ((int *)pppiVar26)[4] = (int)(puVar17 + (unsigned int)(uVar15 << 2));

    ((int *)pppiVar26)[3] = (int)(0x060A53B8 + (char)(cVar24 * '$') + 0x1c);

    ((int *)pppiVar26)[5] = (int)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    ((int *)pppiVar26)[1] = (int)(0x060A3F68 + (short)(uVar15 * PTR_DAT_0603e53c));

    psVar12 = (short *)0x060A3F68;

    for (uVar21 = 0; uVar21 < *(unsigned int *)((int *)pppiVar26)[4]; uVar21 = uVar21 + 1) {

      *pppiVar26 = (int **)(*(int *)((int *)pppiVar26)[3] *

                            (uVar21 - (int)*(short *)(((int *)pppiVar26)[5] + 0x36)) +

                           ((int *)pppiVar26)[2]);

      iVar16 = (*(int(*)())0x06034FFC)();

      if (iVar16 == 0) {

        psVar12 = (short *)((uVar21 << 1) + ((int *)pppiVar26)[1]);

LAB_0603e58c:

        *psVar12 = (short)puVar6;

      }

      else {

        iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26);

        if (((int)puVar5 < -iVar16) || (iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26), -iVar16 < 0))

        {

          psVar12 = (short *)((uVar21 << 1) + ((int *)pppiVar26)[1]);

          goto LAB_0603e58c;

        }

        ((int *)pppiVar26)[-1] = (uVar21 << 1) + ((int *)pppiVar26)[1];

        iVar16 = (*(int(*)())puVar7)(iVar13,*pppiVar26);

        psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & (int)DAT_0603e61e);

        *(short *)((int *)pppiVar26)[-1] = (short)psVar12;

      }

    }

  }

  else {

    *(char **)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 0x54) =

         0x012C0000 + *(int *)(0x060A3E68 + (unsigned int)(uVar15 << 7) + 4);

    local_7c = (int **)((unsigned int)(uVar15 << 2));

    local_78 = (unsigned int **)(0x060A4C70 + (int)local_7c);

    uVar14 = FUN_0603da88(*local_78);

    *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x58) = uVar14;

    uVar14 = FUN_0603d9ec(*local_78);

    *(int *)(puVar17 + (unsigned int)(uVar15 << 7) + 0x5c) = uVar14;

    puVar17 = (char *)0x060A4C38;

    *(int *)(0x060A4C38 + (int)local_7c) = (int)DAT_0603e3b6;

    local_70 = (unsigned int *)(puVar17 + (unsigned int)(uVar15 << 2));

    local_6c = (int *)(0x060A53B8 + (char)(cVar24 * '$') + 0x1c);

    piStack_68 = (int *)(0x060A3E68 + (unsigned int)(uVar15 << 7));

    local_78 = (unsigned int **)(0x060A3F68 + (short)(uVar15 * DAT_0603e3b8));

    psVar12 = (short *)0x060A3F68;

    for (uVar21 = 0; uVar21 < *local_70; uVar21 = uVar21 + 1) {

      local_7c = (int **)(*local_6c *

                          ((uVar21 - (int)*(short *)((int)piStack_68 + 0x36)) + (int)DAT_0603e3ba) +

                         (int)local_74);

      iVar16 = (*(int(*)())0x06034FFC)();

      if (iVar16 == 0) {

        psVar12 = (short *)((int)local_78 + (uVar21 << 1));

LAB_0603e3dc:

        *psVar12 = (short)puVar6;

      }

      else {

        iVar16 = (*(int(*)())puVar7)(iVar13,local_7c);

        if (((int)puVar5 < -iVar16) || (iVar16 = (*(int(*)())puVar7)(iVar13,local_7c), -iVar16 < 0)) {

          psVar12 = (short *)((int)local_78 + (uVar21 << 1));

          goto LAB_0603e3dc;

        }

        local_80 = (short *)((int)local_78 + (uVar21 << 1));

        iVar16 = (*(int(*)())puVar7)(iVar13,local_7c);

        psVar12 = (short *)(-iVar16 >> 6 & 0xffffU & (int)DAT_0603e3bc);

        *local_80 = (short)psVar12;

      }

    }

  }

  *(short *)(0x060A4C40 + (unsigned int)(uVar15 << 1)) = 1;

  return psVar12;

}
#endif

/* --- FUN_0603C104 (L1 import from src/FUN_0603C104.c) --- */

#if 0 /* FUN_0603C104 -- replaced by ASM import */
void FUN_0603c104()
{

  char *puVar1;

  unsigned int uVar2;

  unsigned char bVar3;

  puVar1 = (char *)0x060A4D60;

  FUN_0603cd5c();

  (*(int(*)())0x0603D2CC)();

  (*(int(*)())0x0603D3A8)();

  (*(int(*)())0x0603D438)();

  (*(int(*)())0x0603D514)();

  (*(int(*)())0x0603D5D0)();

  bVar3 = 0;

  do {

    uVar2 = (unsigned int)bVar3;

    bVar3 = bVar3 + 1;

    *(int *)(puVar1 + (uVar2 << 2)) = 0;

  } while (bVar3 < 8);

  *(int *)0x060A4D80 = 0;

  *(int *)0x060A4DA6 = 0;

  return;

}
#endif

/* --- FUN_0603C1A8 (L1 import from src/FUN_0603C1A8.c) --- */

#if 0 /* FUN_0603C1A8 -- replaced by ASM import */
int FUN_0603c1a8(param_1, param_2)
    unsigned int param_1;
    unsigned int param_2;
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  unsigned short uVar6;

  char *puVar7;

  unsigned int uVar8;

  puVar4 = (char *)0x060A4D36;

  puVar3 = (char *)0x0000FFBF;

  puVar2 = (char *)0x060A4D3E;

  puVar5 = (char *)0x0000FF00;

  uVar8 = 1;

  puVar7 = (char *)0x060A4D18;

  (*(int(*)())0x06034F78)();

  *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FDFF;

  (*(int(*)())0x06034F78)();

  *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FEFF;

  uVar1 = (unsigned short)puVar5;

  uVar6 = (unsigned short)puVar3;

  if ((0x100 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if ((0x200 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)puVar4 = *(unsigned short *)puVar4 & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if ((0x400 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if ((0x800 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 2) = *(unsigned short *)(puVar4 + 2) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c496 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 4) = *(unsigned short *)(puVar4 + 4) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c49a & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 4) = *(unsigned short *)(puVar4 + 4) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((int)DAT_0603c49c & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((unsigned int)0x00008000 & param_1) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6 | 0x40;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar4 + 6) = *(unsigned short *)(puVar4 + 6) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & uVar6;

    }

  }

  if (((param_1 & 4) != 0) || ((param_1 & 2) != 0)) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) =

           *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFE | (unsigned short)uVar8;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)puVar2 = *(unsigned short *)puVar2 & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFE;

    }

  }

  if (((param_1 & 8) != 0) || ((0x80 & param_1) != 0)) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFD | 2;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)puVar2 = *(unsigned short *)puVar2 & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFD;

    }

  }

  if ((param_1 & 0x10) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFB | 4;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 2) = *(unsigned short *)(puVar2 + 2) & uVar1 | (unsigned short)param_2 & 0xff;

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFFB;

    }

  }

  if ((param_1 & 0x20) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFF7 | 8;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 2) = *(unsigned short *)(puVar2 + 2) & 0xff | (unsigned short)((param_2 & 0xff) << 8);

    }

    else {

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)0x0000FFF7;

    }

  }

  uVar6 = (unsigned short)param_2;

  if ((param_1 & uVar8) != 0) {

    if ((param_2 & 0xff) < 0x20) {

      puVar5 = (char *)0x0000FFEF;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)puVar5 | 0x10;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar2 + 4) = uVar6 & 0xff;

    }

    else {

      puVar5 = (char *)0x0000FFEF;

      (*(int(*)())0x06034F78)();

      *(unsigned short *)(puVar7 + 0xc) = *(unsigned short *)(puVar7 + 0xc) & (unsigned short)puVar5;

    }

  }

  return;

}
#endif

/* FUN_0603C1A8 -- original binary (1408 bytes) */
__asm__(
    ".section .text.FUN_0603C1A8, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603C1A8\n"
    ".global _FUN_0603c1a8\n"
    ".type _FUN_0603C1A8, @function\n"
    "_FUN_0603C1A8:\n"
    "_FUN_0603c1a8:\n"
    ".byte 0x2F, 0xE6, 0xE7, 0x01, 0x2F, 0xD6, 0x60, 0x73, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0xEB, 0x20\n"  /* 0x0603C1A8 */
    ".byte 0x2F, 0x96, 0xE9, 0x40, 0x2F, 0x86, 0x4F, 0x22, 0xD8, 0x20, 0xDA, 0x21, 0xDC, 0x21, 0xDD, 0x22\n"  /* 0x0603C1B8 */
    ".byte 0xDE, 0x22, 0xD6, 0x23, 0xD3, 0x23, 0x62, 0xE3, 0x43, 0x0B, 0x61, 0x73, 0x85, 0x66, 0xD3, 0x22\n"  /* 0x0603C1C8 */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x81, 0x66, 0x62, 0xE3, 0x60, 0x73, 0xD3, 0x1D\n"  /* 0x0603C1D8 */
    ".byte 0x43, 0x0B, 0x61, 0x73, 0x85, 0x66, 0xD3, 0x1D, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x62, 0x2D\n"  /* 0x0603C1E8 */
    ".byte 0x60, 0x23, 0x81, 0x66, 0x93, 0x1E, 0x23, 0x49, 0x23, 0x38, 0x89, 0x3D, 0x63, 0x5C, 0x33, 0xB3\n"  /* 0x0603C1F8 */
    ".byte 0x89, 0x2E, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x13, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03\n"  /* 0x0603C208 */
    ".byte 0x62, 0x2D, 0x22, 0xC9, 0x22, 0x9B, 0x60, 0x2D, 0x81, 0x66, 0x60, 0x73, 0x91, 0x0B, 0xD3, 0x0D\n"  /* 0x0603C218 */
    ".byte 0x43, 0x0B, 0x62, 0xE3, 0x62, 0xD1, 0x62, 0x2D, 0x22, 0x89, 0x63, 0x5C, 0x22, 0x3B, 0x62, 0x2D\n"  /* 0x0603C228 */
    ".byte 0xA0, 0x22, 0x2D, 0x21, 0x01, 0x00, 0x03, 0x01, 0x06, 0x0A, 0x4D, 0xA6, 0x00, 0x00, 0xFF, 0x00\n"  /* 0x0603C238 */
    ".byte 0x06, 0x0A, 0x4D, 0x3E, 0x00, 0x00, 0xFF, 0xBF, 0x06, 0x0A, 0x4D, 0x36, 0x06, 0x0A, 0x4D, 0x58\n"  /* 0x0603C248 */
    ".byte 0x06, 0x0A, 0x4D, 0x18, 0x06, 0x03, 0x4F, 0x78, 0x00, 0x00, 0xFD, 0xFF, 0x00, 0x00, 0xFE, 0xFF\n"  /* 0x0603C258 */
    ".byte 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x44, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D\n"  /* 0x0603C268 */
    ".byte 0x22, 0xC9, 0x62, 0x2D, 0x60, 0x23, 0x81, 0x66, 0x93, 0x7A, 0x23, 0x49, 0x23, 0x38, 0x89, 0x28\n"  /* 0x0603C278 */
    ".byte 0x63, 0x5C, 0x33, 0xB3, 0x89, 0x19, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x3B, 0x43, 0x0B, 0xE1, 0x01\n"  /* 0x0603C288 */
    ".byte 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x22, 0x9B, 0x60, 0x2D, 0x81, 0x66, 0x60, 0x73\n"  /* 0x0603C298 */
    ".byte 0x91, 0x67, 0xD3, 0x35, 0x43, 0x0B, 0x62, 0xE3, 0x60, 0xD1, 0x60, 0x0D, 0xC9, 0xFF, 0x63, 0x5C\n"  /* 0x0603C2A8 */
    ".byte 0x43, 0x18, 0x20, 0x3B, 0x60, 0x0D, 0xA0, 0x0C, 0x2D, 0x01, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x2E\n"  /* 0x0603C2B8 */
    ".byte 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x62, 0x2D, 0x60, 0x23\n"  /* 0x0603C2C8 */
    ".byte 0x81, 0x66, 0x93, 0x4F, 0x23, 0x49, 0x23, 0x38, 0x89, 0x29, 0x63, 0x5C, 0x33, 0xB3, 0x89, 0x1A\n"  /* 0x0603C2D8 */
    ".byte 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x24, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D\n"  /* 0x0603C2E8 */
    ".byte 0x22, 0xC9, 0x22, 0x9B, 0x60, 0x2D, 0x81, 0x66, 0x60, 0x73, 0x91, 0x3A, 0xD3, 0x1E, 0x43, 0x0B\n"  /* 0x0603C2F8 */
    ".byte 0x62, 0xE3, 0x85, 0xD1, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x89, 0x63, 0x5C, 0x22, 0x3B, 0x62, 0x2D\n"  /* 0x0603C308 */
    ".byte 0x60, 0x23, 0xA0, 0x0C, 0x81, 0xD1, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x17, 0x43, 0x0B, 0xE1, 0x01\n"  /* 0x0603C318 */
    ".byte 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x62, 0x2D, 0x60, 0x23, 0x81, 0x66, 0x93, 0x22\n"  /* 0x0603C328 */
    ".byte 0x23, 0x49, 0x23, 0x38, 0x89, 0x2E, 0x63, 0x5C, 0x33, 0xB3, 0x89, 0x1F, 0x60, 0x73, 0x62, 0xE3\n"  /* 0x0603C338 */
    ".byte 0xD3, 0x0D, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x22, 0x9B\n"  /* 0x0603C348 */
    ".byte 0x60, 0x2D, 0x81, 0x66, 0x60, 0x73, 0x91, 0x0C, 0xD3, 0x07, 0x43, 0x0B, 0x62, 0xE3, 0x85, 0xD1\n"  /* 0x0603C358 */
    ".byte 0x60, 0x0D, 0xC9, 0xFF, 0x63, 0x5C, 0x43, 0x18, 0x20, 0x3B, 0x60, 0x0D, 0xA0, 0x12, 0x81, 0xD1\n"  /* 0x0603C368 */
    ".byte 0x02, 0x00, 0x03, 0x01, 0x04, 0x00, 0x08, 0x00, 0x06, 0x03, 0x4F, 0x78, 0x60, 0x73, 0x62, 0xE3\n"  /* 0x0603C378 */
    ".byte 0xD3, 0x45, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x62, 0x2D\n"  /* 0x0603C388 */
    ".byte 0x60, 0x23, 0x81, 0x66, 0x93, 0x7B, 0x23, 0x49, 0x23, 0x38, 0x89, 0x29, 0x63, 0x5C, 0x33, 0xB3\n"  /* 0x0603C398 */
    ".byte 0x89, 0x1A, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x3C, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03\n"  /* 0x0603C3A8 */
    ".byte 0x62, 0x2D, 0x22, 0xC9, 0x22, 0x9B, 0x60, 0x2D, 0x81, 0x66, 0x60, 0x73, 0x91, 0x68, 0xD3, 0x36\n"  /* 0x0603C3B8 */
    ".byte 0x43, 0x0B, 0x62, 0xE3, 0x85, 0xD2, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x89, 0x63, 0x5C, 0x22, 0x3B\n"  /* 0x0603C3C8 */
    ".byte 0x62, 0x2D, 0x60, 0x23, 0xA0, 0x0C, 0x81, 0xD2, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x2E, 0x43, 0x0B\n"  /* 0x0603C3D8 */
    ".byte 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x62, 0x2D, 0x60, 0x23, 0x81, 0x66\n"  /* 0x0603C3E8 */
    ".byte 0x93, 0x4F, 0x23, 0x49, 0x23, 0x38, 0x89, 0x28, 0x63, 0x5C, 0x33, 0xB3, 0x89, 0x19, 0x60, 0x73\n"  /* 0x0603C3F8 */
    ".byte 0x62, 0xE3, 0xD3, 0x25, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9\n"  /* 0x0603C408 */
    ".byte 0x22, 0x9B, 0x60, 0x2D, 0x81, 0x66, 0x60, 0x73, 0x91, 0x3A, 0xD3, 0x1F, 0x43, 0x0B, 0x62, 0xE3\n"  /* 0x0603C418 */
    ".byte 0x85, 0xD2, 0x60, 0x0D, 0xC9, 0xFF, 0x63, 0x5C, 0x43, 0x18, 0x20, 0x3B, 0x60, 0x0D, 0xA0, 0x0C\n"  /* 0x0603C428 */
    ".byte 0x81, 0xD2, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x18, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03\n"  /* 0x0603C438 */
    ".byte 0x62, 0x2D, 0x22, 0xC9, 0x62, 0x2D, 0x60, 0x23, 0x81, 0x66, 0x93, 0x23, 0x23, 0x49, 0x23, 0x38\n"  /* 0x0603C448 */
    ".byte 0x89, 0x30, 0x63, 0x5C, 0x33, 0xB3, 0x89, 0x21, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x0E, 0x43, 0x0B\n"  /* 0x0603C458 */
    ".byte 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x22, 0x9B, 0x60, 0x2D, 0x81, 0x66\n"  /* 0x0603C468 */
    ".byte 0x60, 0x73, 0x91, 0x0D, 0xD3, 0x08, 0x43, 0x0B, 0x62, 0xE3, 0x85, 0xD3, 0x62, 0x03, 0x62, 0x2D\n"  /* 0x0603C478 */
    ".byte 0x22, 0x89, 0x63, 0x5C, 0x22, 0x3B, 0x62, 0x2D, 0x60, 0x23, 0xA0, 0x13, 0x81, 0xD3, 0x10, 0x00\n"  /* 0x0603C488 */
    ".byte 0x03, 0x01, 0x20, 0x00, 0x40, 0x00, 0xFF, 0xFF, 0x06, 0x03, 0x4F, 0x78, 0x60, 0x73, 0x62, 0xE3\n"  /* 0x0603C498 */
    ".byte 0xD3, 0x2E, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x62, 0x2D\n"  /* 0x0603C4A8 */
    ".byte 0x60, 0x23, 0x81, 0x66, 0xD3, 0x2A, 0x23, 0x49, 0x23, 0x38, 0x89, 0x28, 0x63, 0x5C, 0x33, 0xB3\n"  /* 0x0603C4B8 */
    ".byte 0x89, 0x19, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x25, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03\n"  /* 0x0603C4C8 */
    ".byte 0x62, 0x2D, 0x22, 0xC9, 0x22, 0x9B, 0x60, 0x2D, 0x81, 0x66, 0x60, 0x73, 0x91, 0x3C, 0xD3, 0x1F\n"  /* 0x0603C4D8 */
    ".byte 0x43, 0x0B, 0x62, 0xE3, 0x85, 0xD3, 0x60, 0x0D, 0xC9, 0xFF, 0x63, 0x5C, 0x43, 0x18, 0x20, 0x3B\n"  /* 0x0603C4E8 */
    ".byte 0x60, 0x0D, 0xA0, 0x0C, 0x81, 0xD3, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x18, 0x43, 0x0B, 0xE1, 0x01\n"  /* 0x0603C4F8 */
    ".byte 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x62, 0x2D, 0x60, 0x23, 0x81, 0x66, 0xE3, 0x04\n"  /* 0x0603C508 */
    ".byte 0x23, 0x49, 0x23, 0x38, 0x8B, 0x03, 0xE3, 0x02, 0x23, 0x49, 0x23, 0x38, 0x89, 0x31, 0x63, 0x5C\n"  /* 0x0603C518 */
    ".byte 0x33, 0xB3, 0x89, 0x21, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x0C, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66\n"  /* 0x0603C528 */
    ".byte 0xD3, 0x0C, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x22, 0x7B, 0x60, 0x2D, 0x81, 0x66, 0x60, 0x73\n"  /* 0x0603C538 */
    ".byte 0x91, 0x0B, 0xD3, 0x06, 0x43, 0x0B, 0x62, 0xE3, 0x62, 0xA1, 0x62, 0x2D, 0x22, 0x89, 0x63, 0x5C\n"  /* 0x0603C548 */
    ".byte 0x22, 0x3B, 0x62, 0x2D, 0xA0, 0x15, 0x2A, 0x21, 0x03, 0x01, 0x04, 0x01, 0x06, 0x03, 0x4F, 0x78\n"  /* 0x0603C558 */
    ".byte 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFE, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x2F, 0x43, 0x0B\n"  /* 0x0603C568 */
    ".byte 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0xD3, 0x2D, 0x22, 0x39, 0x62, 0x2D, 0x60, 0x23\n"  /* 0x0603C578 */
    ".byte 0x81, 0x66, 0xE3, 0x08, 0x23, 0x49, 0x23, 0x38, 0x8B, 0x03, 0x93, 0x4C, 0x23, 0x49, 0x23, 0x38\n"  /* 0x0603C588 */
    ".byte 0x89, 0x28, 0x63, 0x5C, 0x33, 0xB3, 0x89, 0x18, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x23, 0x43, 0x0B\n"  /* 0x0603C598 */
    ".byte 0xE1, 0x01, 0x85, 0x66, 0xD3, 0x23, 0x60, 0x0D, 0x20, 0x39, 0xCB, 0x02, 0x81, 0x66, 0x60, 0x73\n"  /* 0x0603C5A8 */
    ".byte 0x91, 0x3A, 0xD3, 0x1E, 0x43, 0x0B, 0x62, 0xE3, 0x60, 0xA1, 0x60, 0x0D, 0xC9, 0xFF, 0x63, 0x5C\n"  /* 0x0603C5B8 */
    ".byte 0x43, 0x18, 0x20, 0x3B, 0x60, 0x0D, 0xA0, 0x0D, 0x2A, 0x01, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x17\n"  /* 0x0603C5C8 */
    ".byte 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0xD3, 0x16, 0x22, 0x39, 0x62, 0x2D\n"  /* 0x0603C5D8 */
    ".byte 0x60, 0x23, 0x81, 0x66, 0xE3, 0x10, 0x23, 0x49, 0x23, 0x38, 0x89, 0x34, 0x63, 0x5C, 0x33, 0xB3\n"  /* 0x0603C5E8 */
    ".byte 0x89, 0x24, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x0D, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0xD3, 0x0E\n"  /* 0x0603C5F8 */
    ".byte 0x60, 0x0D, 0x20, 0x39, 0xCB, 0x04, 0x81, 0x66, 0x60, 0x73, 0x91, 0x0D, 0xD3, 0x07, 0x43, 0x0B\n"  /* 0x0603C608 */
    ".byte 0x62, 0xE3, 0x85, 0xA1, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x89, 0x63, 0x5C, 0x22, 0x3B, 0x62, 0x2D\n"  /* 0x0603C618 */
    ".byte 0x60, 0x23, 0xA0, 0x18, 0x81, 0xA1, 0x00, 0x80, 0x04, 0x01, 0xFF, 0xFF, 0x06, 0x03, 0x4F, 0x78\n"  /* 0x0603C628 */
    ".byte 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0xFF, 0xFD, 0x00, 0x00, 0xFF, 0xFB, 0x60, 0x73, 0x62, 0xE3\n"  /* 0x0603C638 */
    ".byte 0xD3, 0x33, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0xD3, 0x31, 0x22, 0x39\n"  /* 0x0603C648 */
    ".byte 0x62, 0x2D, 0x60, 0x23, 0x81, 0x66, 0x63, 0x43, 0x23, 0xB9, 0x23, 0x38, 0x89, 0x28, 0x63, 0x5C\n"  /* 0x0603C658 */
    ".byte 0x33, 0xB3, 0x89, 0x18, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x29, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66\n"  /* 0x0603C668 */
    ".byte 0xD3, 0x29, 0x60, 0x0D, 0x20, 0x39, 0xCB, 0x08, 0x81, 0x66, 0x60, 0x73, 0x91, 0x47, 0xD3, 0x24\n"  /* 0x0603C678 */
    ".byte 0x43, 0x0B, 0x62, 0xE3, 0x85, 0xA1, 0x60, 0x0D, 0xC9, 0xFF, 0x63, 0x5C, 0x43, 0x18, 0x20, 0x3B\n"  /* 0x0603C688 */
    ".byte 0x60, 0x0D, 0xA0, 0x0D, 0x81, 0xA1, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x1D, 0x43, 0x0B, 0xE1, 0x01\n"  /* 0x0603C698 */
    ".byte 0x85, 0x66, 0x62, 0x03, 0x62, 0x2D, 0xD3, 0x1C, 0x22, 0x39, 0x62, 0x2D, 0x60, 0x23, 0x81, 0x66\n"  /* 0x0603C6A8 */
    ".byte 0x24, 0x79, 0x24, 0x48, 0x89, 0x22, 0xD4, 0x19, 0x63, 0x5C, 0x33, 0xB3, 0x89, 0x12, 0x60, 0x73\n"  /* 0x0603C6B8 */
    ".byte 0x62, 0xE3, 0xD3, 0x13, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66, 0x60, 0x0D, 0x20, 0x49, 0xCB, 0x10\n"  /* 0x0603C6C8 */
    ".byte 0x81, 0x66, 0x60, 0x73, 0x91, 0x1B, 0xD3, 0x0E, 0x43, 0x0B, 0x62, 0xE3, 0x65, 0x5C, 0x60, 0x53\n"  /* 0x0603C6D8 */
    ".byte 0xA0, 0x0C, 0x81, 0xA2, 0x60, 0x73, 0x62, 0xE3, 0xD3, 0x09, 0x43, 0x0B, 0xE1, 0x01, 0x85, 0x66\n"  /* 0x0603C6E8 */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x49, 0x62, 0x2D, 0x60, 0x23, 0x81, 0x66, 0x4F, 0x26, 0x68, 0xF6\n"  /* 0x0603C6F8 */
    ".byte 0x69, 0xF6, 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x04, 0x01\n"  /* 0x0603C708 */
    ".byte 0x06, 0x03, 0x4F, 0x78, 0x00, 0x00, 0xFF, 0xFB, 0x00, 0x00, 0xFF, 0xF7, 0x00, 0x00, 0xFF, 0xEF\n"  /* 0x0603C718 */
);


/* --- FUN_0603C728 (L1 import from src/FUN_0603C728.c) --- */

unsigned int FUN_0603c728()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned int uVar5;

  int iVar6;

  int iVar7;

  unsigned int uVar8;

  unsigned int local_40;

  unsigned int uStack_3c;

  unsigned int local_24 [2];

  puVar4 = (char *)0x060A4DA5;

  puVar3 = (char *)0x060A4DA4;

  puVar2 = (char *)0x060A4DA6;

  iVar6 = 0x500;

  iVar7 = 0x300;

  uVar8 = (unsigned int)DAT_0603c7ea;

  uVar5 = (unsigned int)(unsigned char)*(int *)0x060A4DA6;

  if (uVar5 == 1) {

    if (*(unsigned int *)0x060A4D8C < *(unsigned int *)0x060A4D88) {

      *(int *)0x060A4D8C = *(int *)0x060A4D8C + 1;

    }

    else {

      *(int *)0x060A4DA6 = 0;

      puVar3 = (char *)0x060A4DA8;

      for (uVar5 = 0; uVar5 < *(unsigned int *)0x060A4D94; uVar5 = uVar5 + 1) {

        if ((unsigned char)(puVar3 + uVar5)[iVar7] < (unsigned char)puVar3[uVar5]) {

          puVar3[iVar7 + uVar5] = puVar3[iVar7 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[uVar5] < (unsigned char)(puVar3 + uVar5)[iVar7]) {

          puVar3[iVar7 + uVar5] = puVar3[iVar7 + uVar5] + -1;

          *puVar2 = 1;

        }

        if ((unsigned char)puVar3[uVar8 + uVar5] < (unsigned char)puVar3[0x100 + uVar5]) {

          puVar3[uVar8 + uVar5] = puVar3[uVar8 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[0x100 + uVar5] < (unsigned char)puVar3[uVar8 + uVar5]) {

          puVar3[uVar8 + uVar5] = puVar3[uVar8 + uVar5] + -1;

          *puVar2 = 1;

        }

        if ((unsigned char)puVar3[iVar6 + uVar5] < (unsigned char)puVar3[0x200 + uVar5]) {

          puVar3[iVar6 + uVar5] = puVar3[iVar6 + uVar5] + '\x01';

          *puVar2 = 1;

        }

        else if ((unsigned char)puVar3[0x200 + uVar5] < (unsigned char)puVar3[iVar6 + uVar5]) {

          puVar3[iVar6 + uVar5] = puVar3[iVar6 + uVar5] + -1;

          *puVar2 = 1;

        }

      }

      *(int *)0x060A4D8C = 0;

      puVar3 = (char *)0x060A4DA8;

      puVar2 = (char *)0x060A4DA8;

      uVar5 = (int)((unsigned int)*(unsigned short *)0x060A3D96 & (int)DAT_0603c8d4) >> 0xc;

      if (uVar5 == 2) {

        for (local_40 = 0; local_40 < *(unsigned int *)0x060A4D94; local_40 = local_40 + 1) {

          local_24[0] = (unsigned int)((((puVar2[iVar7 + local_40]) << 8 | (puVar2[uVar8 + local_40]) & 0xFF)) << 8 | (puVar2[iVar6 + local_40]) & 0xFF);

          uVar5 = (*(int(*)())0x060429EC)(*(int *)0x060A4D84,*(int *)0x060A4D90 + local_40,1,

                             local_24);

        }

      }

      else {

        for (uStack_3c = 0; uStack_3c < *(unsigned int *)0x060A4D94; uStack_3c = uStack_3c + 1) {

          local_24[0] = (unsigned int)(unsigned char)puVar3[iVar6 + uStack_3c] |

                        ((unsigned int)(unsigned char)puVar3[uVar8 + uStack_3c] |

                        (unsigned int)(unsigned char)puVar3[iVar7 + uStack_3c] << 5) << 5;

          uVar5 = (*(int(*)())0x060429EC)(*(int *)0x060A4D84,*(int *)0x060A4D90 + uStack_3c,1,

                             local_24);

        }

      }

    }

  }

  else if (uVar5 == 2) {

    if (*(unsigned int *)0x060A4D8C < *(unsigned int *)0x060A4D88) {

      *(int *)0x060A4D8C = *(int *)0x060A4D8C + 1;

    }

    else {

      if (*(int *)0x060A4DA7 == '\0') {

        *(int *)0x060A4DA4 = *(int *)0x060A4DA4 + -1;

        if ((unsigned char)*puVar3 <= (unsigned char)*puVar4) {

          *puVar3 = *puVar4;

          *puVar2 = 0;

        }

      }

      else {

        *(int *)0x060A4DA4 = *(int *)0x060A4DA4 + '\x01';

        if ((unsigned char)*puVar4 <= (unsigned char)*puVar3) {

          *puVar3 = *puVar4;

          *puVar2 = 0;

        }

      }

      if ((*(unsigned int *)0x060A4D84 & 0x100) != 0) {

        FUN_0603c1a8(0x100,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 0x200) != 0) {

        FUN_0603c1a8(0x200,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & uVar8) != 0) {

        FUN_0603c1a8(uVar8,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 0x800) != 0) {

        FUN_0603c1a8(0x800,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cade) != 0) {

        FUN_0603c1a8((int)DAT_0603cade,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cae0) != 0) {

        FUN_0603c1a8((int)DAT_0603cae0,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (int)DAT_0603cae2) != 0) {

        FUN_0603c1a8((int)DAT_0603cae2,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & (unsigned int)0x00008000) != 0) {

        FUN_0603c1a8(0x00008000,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 4) != 0) {

        FUN_0603c1a8(4,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 8) != 0) {

        FUN_0603c1a8(8,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 0x10) != 0) {

        FUN_0603c1a8(0x10,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 0x20) != 0) {

        FUN_0603c1a8(0x20,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 1) != 0) {

        FUN_0603c1a8(1,(int)(char)*puVar3);

      }

      if ((*(unsigned int *)0x060A4D84 & 2) != 0) {

        FUN_0603c1a8(2,(int)(char)*puVar3);

      }

      uVar5 = *(unsigned int *)0x060A4D84;

      if ((uVar5 & 0x80) != 0) {

        uVar5 = FUN_0603c1a8(0x80,(int)(char)*puVar3);

      }

      *(int *)0x060A4D8C = 0;

    }

  }

  else if (uVar5 == 3) {

    if (*(unsigned int *)0x060A4D8C < *(unsigned int *)0x060A4D88) {

      *(int *)0x060A4D8C = *(int *)0x060A4D8C + 1;

    }

    else {

      uVar5 = FUN_0603cc88(*(int *)0x060A4D84,(int)*(short *)0x060A4D98,

                           (int)*(short *)0x060A4D9A,(int)*(short *)0x060A4D9C);

      puVar3 = (char *)0x060A4D9E;

      sVar1 = *(short *)0x060A4D98;

      *(short *)0x060A4D9E = *(short *)0x060A4D9E - sVar1;

      *(short *)0x060A4DA0 = *(short *)0x060A4DA0 - *(short *)0x060A4D9A;

      *(short *)0x060A4DA2 = *(short *)0x060A4DA2 - *(short *)0x060A4D9C;

      if (sVar1 < 1) {

        if (-1 < *(short *)puVar3) {

          *(short *)0x060A4D98 = 0;

        }

      }

      else if (*(short *)puVar3 < 1) {

        *(short *)0x060A4D98 = 0;

      }

      if (*(short *)0x060A4D9A < 1) {

        if (-1 < *(short *)0x060A4DA0) {

          *(short *)0x060A4D9A = 0;

        }

      }

      else if (*(short *)0x060A4DA0 < 1) {

        *(short *)0x060A4D9A = 0;

      }

      if (*(short *)0x060A4D9C < 1) {

        if (-1 < *(short *)0x060A4DA2) {

          *(short *)0x060A4D9C = 0;

        }

      }

      else if (*(short *)0x060A4DA2 < 1) {

        *(short *)0x060A4D9C = 0;

      }

      if (((*(short *)0x060A4D98 == 0) && (*(short *)0x060A4D9A == 0)) &&

         (*(short *)0x060A4D9C == 0)) {

        *puVar2 = 0;

      }

      *(int *)0x060A4D8C = 0;

    }

  }

  return uVar5;

}

/* --- FUN_0603CD5C (L1 import from src/FUN_0603CD5C.c) --- */

#if 0 /* FUN_0603CD5C -- replaced by ASM import */
void FUN_0603cd5c()
{

  unsigned short uVar1;

  unsigned short uVar2;

  unsigned short uVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  unsigned short *puVar6;

  char *puVar7;

  unsigned short uVar8;

  uVar3 = DAT_0603ce8e;

  puVar6 = (unsigned short *)0x060A4D18;

  (*(int(*)())0x06034F78)(0x060A4D18,0x060A4D58,1);

  *puVar6 = *puVar6 & uVar3 | DAT_0603ce90;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FFBF;

  puVar7 = (char *)0x0000FFDF;

  (*(int(*)())0x06034F78)();

  uVar8 = (unsigned short)puVar7;

  *puVar6 = *puVar6 & uVar8 | 0x20;

  puVar7 = (char *)0x0000FFEF;

  (*(int(*)())0x06034F78)();

  uVar1 = (unsigned short)puVar7;

  *puVar6 = *puVar6 & uVar1;

  puVar7 = (char *)0x0000FFF0;

  (*(int(*)())0x06034F78)();

  uVar5 = (unsigned short)puVar7;

  *puVar6 = *puVar6 & uVar5 | 7;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar5;

  puVar7 = (char *)0x0000FF0F;

  (*(int(*)())0x06034F78)();

  uVar2 = (unsigned short)puVar7;

  puVar6[2] = puVar6[2] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & (unsigned short)0x0000F0FF;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar3;

  (*(int(*)())0x06034F78)();

  puVar6[3] = puVar6[3] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[3] = puVar6[3] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & (unsigned short)0x0000F0FF;

  (*(int(*)())0x06034F78)();

  puVar6[2] = puVar6[2] & uVar3;

  (*(int(*)())0x06034F78)();

  puVar6[3] = puVar6[3] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[3] = puVar6[3] & uVar2;

  puVar7 = (char *)0x0000FFFE;

  (*(int(*)())0x06034F78)();

  uVar2 = (unsigned short)puVar7;

  puVar6[4] = puVar6[4] & uVar2;

  puVar7 = (char *)0x0000FFFD;

  (*(int(*)())0x06034F78)();

  uVar3 = (unsigned short)puVar7;

  puVar6[4] = puVar6[4] & uVar3;

  puVar7 = (char *)0x0000FFFB;

  (*(int(*)())0x06034F78)();

  uVar5 = uVar5 + 7;

  uVar4 = (unsigned short)puVar7;

  puVar6[4] = puVar6[4] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar6[4] = puVar6[4] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[4] = puVar6[4] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar6[4] = puVar6[4] & uVar8;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FFFC;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FFF3;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FFCF;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FF3F;

  (*(int(*)())0x06034F78)();

  puVar6[5] = puVar6[5] & (unsigned short)0x0000FCFF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & DAT_0603d034;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x00008FFF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FBFF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FDFF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FEFF | DAT_0603d1c2;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & (unsigned short)0x0000FFBF;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar8;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar3;

  (*(int(*)())0x06034F78)();

  puVar6[6] = puVar6[6] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FFFC;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FFF3;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FFCF;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FF3F;

  (*(int(*)())0x06034F78)();

  puVar6[7] = puVar6[7] & (unsigned short)0x0000FCFF;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar2;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar3;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar4;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar5;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar1;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & uVar8;

  (*(int(*)())0x06034F78)();

  puVar6[1] = puVar6[1] & (unsigned short)0x0000FEFF;

  (*(int(*)())0x06034F78)();

  return;

}
#endif

/* FUN_0603CD5C -- original binary (1392 bytes) */
__asm__(
    ".section .text.FUN_0603CD5C, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603CD5C\n"
    ".global _FUN_0603cd5c\n"
    ".type _FUN_0603CD5C, @function\n"
    "_FUN_0603CD5C:\n"
    "_FUN_0603cd5c:\n"
    ".byte 0x2F, 0xE6, 0xE6, 0x01, 0x2F, 0xD6, 0x60, 0x63, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x4F, 0x22\n"  /* 0x0603CD5C */
    ".byte 0x9B, 0x8F, 0xD5, 0x49, 0xD4, 0x49, 0xD3, 0x4A, 0x62, 0x53, 0x43, 0x0B, 0x61, 0x63, 0x60, 0x63\n"  /* 0x0603CD6C */
    ".byte 0x62, 0x41, 0x93, 0x87, 0x62, 0x2D, 0x22, 0xB9, 0x22, 0x3B, 0x24, 0x21, 0x62, 0x53, 0xD3, 0x44\n"  /* 0x0603CD7C */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0xD3, 0x43, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603CD8C */
    ".byte 0x81, 0x46, 0x62, 0x53, 0xD7, 0x40, 0x60, 0x63, 0xD3, 0x3D, 0x43, 0x0B, 0x61, 0x63, 0x62, 0x53\n"  /* 0x0603CD9C */
    ".byte 0x60, 0x41, 0x60, 0x0D, 0x20, 0x79, 0xCB, 0x20, 0x24, 0x01, 0x60, 0x63, 0xD3, 0x38, 0xDE, 0x3B\n"  /* 0x0603CDAC */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x62, 0x41, 0x60, 0x63, 0x62, 0x2D, 0x22, 0xE9, 0x24, 0x21, 0x62, 0x53\n"  /* 0x0603CDBC */
    ".byte 0xD3, 0x33, 0xDD, 0x37, 0x43, 0x0B, 0x61, 0x63, 0x60, 0x41, 0x62, 0x53, 0x60, 0x0D, 0x20, 0xD9\n"  /* 0x0603CDCC */
    ".byte 0xCB, 0x07, 0x24, 0x01, 0x60, 0x63, 0xD3, 0x2E, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x42, 0x62, 0x03\n"  /* 0x0603CDDC */
    ".byte 0x62, 0x2D, 0x22, 0xD9, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x42, 0x60, 0x63, 0xD3, 0x28, 0xDC, 0x2D\n"  /* 0x0603CDEC */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x42, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x60, 0x2D, 0x62, 0x53\n"  /* 0x0603CDFC */
    ".byte 0x81, 0x42, 0x60, 0x63, 0xD3, 0x22, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x42, 0xD3, 0x26, 0x62, 0x03\n"  /* 0x0603CE0C */
    ".byte 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x42, 0x60, 0x63, 0xD3, 0x1C, 0x43, 0x0B\n"  /* 0x0603CE1C */
    ".byte 0x61, 0x63, 0x85, 0x42, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xB9, 0x60, 0x2D, 0x81, 0x42, 0x62, 0x53\n"  /* 0x0603CE2C */
    ".byte 0x60, 0x63, 0xD3, 0x17, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x43, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9\n"  /* 0x0603CE3C */
    ".byte 0x60, 0x2D, 0x62, 0x53, 0x81, 0x43, 0x60, 0x63, 0xD3, 0x11, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x43\n"  /* 0x0603CE4C */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x60, 0x2D, 0x81, 0x43, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x0C\n"  /* 0x0603CE5C */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x42, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9, 0x60, 0x2D, 0x62, 0x53\n"  /* 0x0603CE6C */
    ".byte 0x81, 0x42, 0x60, 0x63, 0xD3, 0x06, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x42, 0x62, 0x03, 0xA0, 0x15\n"  /* 0x0603CE7C */
    ".byte 0x00, 0x09, 0x0F, 0xFF, 0x30, 0x00, 0xFF, 0xFF, 0x06, 0x0A, 0x4D, 0x58, 0x06, 0x0A, 0x4D, 0x18\n"  /* 0x0603CE8C */
    ".byte 0x06, 0x03, 0x4F, 0x78, 0x00, 0x00, 0xFF, 0xBF, 0x00, 0x00, 0xFF, 0xDF, 0x00, 0x00, 0xFF, 0xEF\n"  /* 0x0603CE9C */
    ".byte 0x00, 0x00, 0xFF, 0xF0, 0x00, 0x00, 0xFF, 0x0F, 0x00, 0x00, 0xF0, 0xFF, 0x62, 0x2D, 0x22, 0xC9\n"  /* 0x0603CEAC */
    ".byte 0x60, 0x2D, 0x62, 0x53, 0x81, 0x42, 0x60, 0x63, 0xD3, 0x5C, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x42\n"  /* 0x0603CEBC */
    ".byte 0xD3, 0x5B, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x42, 0x60, 0x63\n"  /* 0x0603CECC */
    ".byte 0xD3, 0x56, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x42, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xB9, 0x60, 0x2D\n"  /* 0x0603CEDC */
    ".byte 0x81, 0x42, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x51, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x43, 0x62, 0x03\n"  /* 0x0603CEEC */
    ".byte 0x62, 0x2D, 0x22, 0xD9, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x43, 0x60, 0x63, 0xD3, 0x4B, 0x43, 0x0B\n"  /* 0x0603CEFC */
    ".byte 0x61, 0x63, 0x85, 0x43, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x60, 0x2D, 0x81, 0x43, 0x62, 0x53\n"  /* 0x0603CF0C */
    ".byte 0xDB, 0x48, 0x60, 0x63, 0xD3, 0x45, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x44, 0x62, 0x03, 0x62, 0x2D\n"  /* 0x0603CF1C */
    ".byte 0x22, 0xB9, 0x60, 0x2D, 0x81, 0x44, 0x62, 0x53, 0xDC, 0x43, 0x60, 0x63, 0xD3, 0x3F, 0x43, 0x0B\n"  /* 0x0603CF2C */
    ".byte 0x61, 0x63, 0x85, 0x44, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9, 0x60, 0x2D, 0x81, 0x44, 0x62, 0x53\n"  /* 0x0603CF3C */
    ".byte 0xDA, 0x3E, 0x60, 0x63, 0xD3, 0x39, 0x43, 0x0B, 0x61, 0x63, 0x7D, 0x07, 0x85, 0x44, 0x62, 0x03\n"  /* 0x0603CF4C */
    ".byte 0x62, 0x2D, 0x22, 0xA9, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x44, 0x60, 0x63, 0xD3, 0x33, 0x43, 0x0B\n"  /* 0x0603CF5C */
    ".byte 0x61, 0x63, 0x85, 0x44, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9, 0x60, 0x2D, 0x81, 0x44, 0x62, 0x53\n"  /* 0x0603CF6C */
    ".byte 0x60, 0x63, 0xD3, 0x2E, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x44, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xE9\n"  /* 0x0603CF7C */
    ".byte 0x60, 0x2D, 0x62, 0x53, 0x81, 0x44, 0x60, 0x63, 0xD3, 0x28, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x44\n"  /* 0x0603CF8C */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x79, 0x60, 0x2D, 0x81, 0x44, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x23\n"  /* 0x0603CF9C */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x45, 0xD3, 0x26, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603CFAC */
    ".byte 0x81, 0x45, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x1D, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x45, 0xD3, 0x21\n"  /* 0x0603CFBC */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x81, 0x45, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x17\n"  /* 0x0603CFCC */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x45, 0xD3, 0x1C, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603CFDC */
    ".byte 0x81, 0x45, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x11, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x45, 0xD3, 0x17\n"  /* 0x0603CFEC */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x81, 0x45, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x0B\n"  /* 0x0603CFFC */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x45, 0xD3, 0x12, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603D00C */
    ".byte 0x81, 0x45, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x05, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0x62, 0x03\n"  /* 0x0603D01C */
    ".byte 0x62, 0x2D, 0x93, 0x01, 0xA0, 0x16, 0x00, 0x09, 0x7F, 0xFF, 0xFF, 0xFF, 0x06, 0x03, 0x4F, 0x78\n"  /* 0x0603D02C */
    ".byte 0x00, 0x00, 0xF0, 0xFF, 0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0xFF, 0xFD, 0x00, 0x00, 0xFF, 0xFB\n"  /* 0x0603D03C */
    ".byte 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x00, 0xFF, 0xF3, 0x00, 0x00, 0xFF, 0xCF, 0x00, 0x00, 0xFF, 0x3F\n"  /* 0x0603D04C */
    ".byte 0x00, 0x00, 0xFC, 0xFF, 0x22, 0x39, 0x60, 0x2D, 0x81, 0x46, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x56\n"  /* 0x0603D05C */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0xD3, 0x55, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603D06C */
    ".byte 0x81, 0x46, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x50, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0xD3, 0x50\n"  /* 0x0603D07C */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x81, 0x46, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x4A\n"  /* 0x0603D08C */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0xD3, 0x4B, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603D09C */
    ".byte 0x81, 0x46, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x44, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0xD3, 0x46\n"  /* 0x0603D0AC */
    ".byte 0x91, 0x81, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x22, 0x1B, 0x60, 0x2D, 0x81, 0x46, 0x62, 0x53\n"  /* 0x0603D0BC */
    ".byte 0x60, 0x63, 0xD3, 0x3D, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0xD3, 0x40, 0x62, 0x03, 0x62, 0x2D\n"  /* 0x0603D0CC */
    ".byte 0x22, 0x39, 0x60, 0x2D, 0x81, 0x46, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x37, 0x43, 0x0B, 0x61, 0x63\n"  /* 0x0603D0DC */
    ".byte 0x85, 0x46, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x79, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x46, 0x60, 0x63\n"  /* 0x0603D0EC */
    ".byte 0xD3, 0x31, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xE9, 0x60, 0x2D\n"  /* 0x0603D0FC */
    ".byte 0x81, 0x46, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x2C, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0x62, 0x03\n"  /* 0x0603D10C */
    ".byte 0x62, 0x2D, 0x22, 0xD9, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x46, 0x60, 0x63, 0xD3, 0x26, 0x43, 0x0B\n"  /* 0x0603D11C */
    ".byte 0x61, 0x63, 0x85, 0x46, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xA9, 0x60, 0x2D, 0x81, 0x46, 0x62, 0x53\n"  /* 0x0603D12C */
    ".byte 0x60, 0x63, 0xD3, 0x21, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xC9\n"  /* 0x0603D13C */
    ".byte 0x60, 0x2D, 0x62, 0x53, 0x81, 0x46, 0x60, 0x63, 0xD3, 0x1B, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x46\n"  /* 0x0603D14C */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0xB9, 0x60, 0x2D, 0x81, 0x46, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x16\n"  /* 0x0603D15C */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x47, 0xD3, 0x1A, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603D16C */
    ".byte 0x81, 0x47, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x10, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x47, 0xD3, 0x15\n"  /* 0x0603D17C */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x81, 0x47, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x0A\n"  /* 0x0603D18C */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x47, 0xD3, 0x10, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D\n"  /* 0x0603D19C */
    ".byte 0x81, 0x47, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x04, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x47, 0x62, 0x03\n"  /* 0x0603D1AC */
    ".byte 0x62, 0x2D, 0xA0, 0x13, 0x00, 0x09, 0x01, 0x00, 0x06, 0x03, 0x4F, 0x78, 0x00, 0x00, 0x8F, 0xFF\n"  /* 0x0603D1BC */
    ".byte 0x00, 0x00, 0xFB, 0xFF, 0x00, 0x00, 0xFD, 0xFF, 0x00, 0x00, 0xFE, 0xFF, 0x00, 0x00, 0xFF, 0xBF\n"  /* 0x0603D1CC */
    ".byte 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x00, 0xFF, 0xF3, 0x00, 0x00, 0xFF, 0xCF, 0xD3, 0x34, 0x22, 0x39\n"  /* 0x0603D1DC */
    ".byte 0x60, 0x2D, 0x62, 0x53, 0x81, 0x47, 0x60, 0x63, 0xD3, 0x32, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x47\n"  /* 0x0603D1EC */
    ".byte 0xD3, 0x31, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x47, 0x60, 0x63\n"  /* 0x0603D1FC */
    ".byte 0xD3, 0x2C, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x41, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xB9, 0x60, 0x2D\n"  /* 0x0603D20C */
    ".byte 0x81, 0x41, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x27, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x41, 0x62, 0x03\n"  /* 0x0603D21C */
    ".byte 0x62, 0x2D, 0x22, 0xC9, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x41, 0x60, 0x63, 0xD3, 0x21, 0x43, 0x0B\n"  /* 0x0603D22C */
    ".byte 0x61, 0x63, 0x85, 0x41, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xA9, 0x60, 0x2D, 0x81, 0x41, 0x62, 0x53\n"  /* 0x0603D23C */
    ".byte 0x60, 0x63, 0xD3, 0x1C, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x41, 0x62, 0x03, 0x62, 0x2D, 0x22, 0xD9\n"  /* 0x0603D24C */
    ".byte 0x60, 0x2D, 0x62, 0x53, 0x81, 0x41, 0x60, 0x63, 0xD3, 0x16, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x41\n"  /* 0x0603D25C */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x22, 0xE9, 0x60, 0x2D, 0x81, 0x41, 0x62, 0x53, 0x60, 0x63, 0xD3, 0x11\n"  /* 0x0603D26C */
    ".byte 0x43, 0x0B, 0x61, 0x63, 0x85, 0x41, 0x62, 0x03, 0x62, 0x2D, 0x22, 0x79, 0x60, 0x2D, 0x62, 0x53\n"  /* 0x0603D27C */
    ".byte 0x81, 0x41, 0x60, 0x63, 0xD3, 0x0B, 0x43, 0x0B, 0x61, 0x63, 0x85, 0x41, 0xD3, 0x0B, 0x62, 0x03\n"  /* 0x0603D28C */
    ".byte 0x62, 0x2D, 0x22, 0x39, 0x60, 0x2D, 0x62, 0x53, 0x81, 0x41, 0x60, 0x63, 0xD3, 0x05, 0x43, 0x0B\n"  /* 0x0603D29C */
    ".byte 0x61, 0x63, 0x4F, 0x26, 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0603D2AC */
    ".byte 0x00, 0x00, 0xFF, 0x3F, 0x06, 0x03, 0x4F, 0x78, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0xFE, 0xFF\n"  /* 0x0603D2BC */
);


/* FUN_0603DDFC -- original binary (596 bytes) */
__asm__(
    ".section .text.FUN_0603DDFC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603DDFC\n"
    ".global _FUN_0603ddfc\n"
    ".type _FUN_0603DDFC, @function\n"
    "_FUN_0603DDFC:\n"
    "_FUN_0603ddfc:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x4F, 0x22, 0x7F, 0xFC, 0xDA, 0x2A\n"  /* 0x0603DDFC */
    ".byte 0xDB, 0x2A, 0xDC, 0x2B, 0xED, 0x00, 0x2F, 0x62, 0xD0, 0x2A, 0xA0, 0x06, 0x60, 0x02, 0xA0, 0x0A\n"  /* 0x0603DE0C */
    ".byte 0x6E, 0xDD, 0xA0, 0x08, 0xEE, 0x01, 0xA1, 0x02, 0x00, 0x09, 0x88, 0x01, 0x89, 0xF7, 0x88, 0x02\n"  /* 0x0603DE1C */
    ".byte 0x89, 0xF7, 0xAF, 0xF8, 0x00, 0x09, 0x66, 0xEE, 0x62, 0xED, 0xD7, 0x23, 0x63, 0x63, 0x42, 0x08\n"  /* 0x0603DE2C */
    ".byte 0x46, 0x08, 0x43, 0x08, 0x43, 0x08, 0x43, 0x00, 0x36, 0x3C, 0x66, 0x6E, 0x36, 0xAC, 0x26, 0x72\n"  /* 0x0603DE3C */
    ".byte 0x16, 0xD1, 0x16, 0xD2, 0x16, 0xD3, 0x16, 0x74, 0x16, 0xD5, 0x16, 0xD6, 0x16, 0xD7, 0x16, 0x78\n"  /* 0x0603DE4C */
    ".byte 0xD3, 0x1A, 0x32, 0x3C, 0x60, 0x22, 0x20, 0x08, 0x89, 0x06, 0x60, 0xED, 0x40, 0x08, 0x03, 0xCE\n"  /* 0x0603DE5C */
    ".byte 0x33, 0x4C, 0x0C, 0x36, 0xA0, 0x03, 0x00, 0x09, 0x60, 0xED, 0x40, 0x08, 0x0C, 0xD6, 0x66, 0xED\n"  /* 0x0603DE6C */
    ".byte 0x46, 0x08, 0x63, 0x63, 0x33, 0xBC, 0x36, 0xCC, 0x62, 0x32, 0x32, 0x5C, 0x23, 0x22, 0x60, 0x62\n"  /* 0x0603DE7C */
    ".byte 0x20, 0x08, 0x8B, 0x25, 0x24, 0x48, 0x89, 0x23, 0xD4, 0x0D, 0xD0, 0x0A, 0xA0, 0x1C, 0x60, 0x02\n"  /* 0x0603DE8C */
    ".byte 0xD2, 0x0C, 0x85, 0x42, 0x63, 0x03, 0x23, 0x29, 0x60, 0x33, 0xA0, 0x02, 0x00, 0x09, 0x85, 0x42\n"  /* 0x0603DE9C */
    ".byte 0xC9, 0xFF, 0xA0, 0x15, 0x81, 0x42, 0xFF, 0xFF, 0x06, 0x0A, 0x53, 0xB8, 0x06, 0x0A, 0x4C, 0x68\n"  /* 0x0603DEAC */
    ".byte 0x06, 0x0A, 0x4C, 0x60, 0x06, 0x06, 0x35, 0xA8, 0x00, 0x01, 0x00, 0x00, 0x06, 0x0A, 0x4C, 0x44\n"  /* 0x0603DEBC */
    ".byte 0x06, 0x0A, 0x3E, 0x38, 0x00, 0x00, 0xFF, 0x00, 0x88, 0x01, 0x89, 0xE1, 0x88, 0x02, 0x89, 0xE6\n"  /* 0x0603DECC */
    ".byte 0x60, 0xF2, 0x20, 0x08, 0x89, 0x01, 0xB6, 0xAD, 0x64, 0xF2, 0x64, 0xED, 0xD3, 0x18, 0x44, 0x08\n"  /* 0x0603DEDC */
    ".byte 0x33, 0x4C, 0x60, 0x32, 0x20, 0x08, 0x89, 0x07, 0xD3, 0x16, 0x33, 0x4C, 0x60, 0x32, 0x20, 0x08\n"  /* 0x0603DEEC */
    ".byte 0x89, 0x02, 0x60, 0xED, 0x40, 0x08, 0x0C, 0xD6, 0xD5, 0x13, 0x64, 0xED, 0x44, 0x08, 0x63, 0x43\n"  /* 0x0603DEFC */
    ".byte 0x33, 0xCC, 0x60, 0x32, 0x20, 0x08, 0x8B, 0x04, 0xD3, 0x10, 0x33, 0x4C, 0x60, 0x32, 0x20, 0x08\n"  /* 0x0603DF0C */
    ".byte 0x89, 0x1E, 0x66, 0xEE, 0x64, 0xED, 0x63, 0x63, 0x44, 0x08, 0x46, 0x08, 0x43, 0x08, 0x44, 0x08\n"  /* 0x0603DF1C */
    ".byte 0x43, 0x08, 0x44, 0x08, 0x43, 0x00, 0x36, 0x3C, 0x66, 0x6E, 0x36, 0xAC, 0x44, 0x00, 0x34, 0x5C\n"  /* 0x0603DF2C */
    ".byte 0xE0, 0x4C, 0x03, 0x4E, 0x26, 0x32, 0xE0, 0x50, 0x03, 0x4E, 0x16, 0x34, 0xA0, 0x35, 0x00, 0x09\n"  /* 0x0603DF3C */
    ".byte 0x06, 0x0A, 0x4C, 0x4C, 0x06, 0x0A, 0x4C, 0x70, 0x06, 0x0A, 0x3E, 0x68, 0x06, 0x0A, 0x4C, 0x78\n"  /* 0x0603DF4C */
    ".byte 0x64, 0xED, 0x24, 0x48, 0x8B, 0x04, 0xD0, 0x36, 0x60, 0x01, 0x60, 0x0D, 0xC8, 0xFF, 0x8B, 0x09\n"  /* 0x0603DF5C */
    ".byte 0x60, 0x43, 0x88, 0x01, 0x8B, 0x21, 0xD2, 0x32, 0xD3, 0x32, 0x62, 0x21, 0x62, 0x2D, 0x22, 0x39\n"  /* 0x0603DF6C */
    ".byte 0x22, 0x28, 0x89, 0x1A, 0x66, 0xEE, 0x64, 0xED, 0x63, 0x63, 0x44, 0x08, 0x46, 0x08, 0x43, 0x08\n"  /* 0x0603DF7C */
    ".byte 0x44, 0x08, 0x43, 0x08, 0x44, 0x08, 0x43, 0x00, 0x36, 0x3C, 0x66, 0x6E, 0x36, 0xAC, 0x44, 0x00\n"  /* 0x0603DF8C */
    ".byte 0x34, 0x5C, 0xE0, 0x4C, 0x03, 0x4E, 0x26, 0x32, 0xE0, 0x50, 0x03, 0x4E, 0x16, 0x34, 0xE0, 0x4C\n"  /* 0x0603DF9C */
    ".byte 0x03, 0x4E, 0x14, 0x37, 0xE0, 0x50, 0x03, 0x4E, 0x14, 0x3B, 0x60, 0xED, 0x40, 0x08, 0x03, 0xBE\n"  /* 0x0603DFAC */
    ".byte 0x23, 0x38, 0x89, 0x03, 0x60, 0xED, 0x40, 0x08, 0xB5, 0x82, 0x04, 0xBE, 0x64, 0xED, 0x44, 0x08\n"  /* 0x0603DFBC */
    ".byte 0x63, 0x43, 0x33, 0xCC, 0x60, 0x32, 0x20, 0x08, 0x8B, 0x04, 0xD3, 0x1B, 0x33, 0x4C, 0x60, 0x32\n"  /* 0x0603DFCC */
    ".byte 0x20, 0x08, 0x89, 0x24, 0x63, 0xED, 0xD2, 0x19, 0x43, 0x00, 0x33, 0x2C, 0x63, 0x31, 0x63, 0x3D\n"  /* 0x0603DFDC */
    ".byte 0x23, 0x38, 0x89, 0x06, 0x63, 0xED, 0xD2, 0x16, 0x43, 0x08, 0x33, 0x2C, 0x60, 0x32, 0x20, 0x08\n"  /* 0x0603DFEC */
    ".byte 0x89, 0x0A, 0x60, 0xED, 0x40, 0x08, 0x04, 0xCE, 0x7F, 0x04, 0x4F, 0x26, 0x6A, 0xF6, 0x6B, 0xF6\n"  /* 0x0603DFFC */
    ".byte 0x6C, 0xF6, 0x6D, 0xF6, 0xA0, 0x1E, 0x6E, 0xF6, 0x60, 0xED, 0x40, 0x08, 0x04, 0xCE, 0x7F, 0x04\n"  /* 0x0603E00C */
    ".byte 0x4F, 0x26, 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0xA2, 0xC9, 0x6E, 0xF6, 0x7F, 0x04\n"  /* 0x0603E01C */
    ".byte 0x4F, 0x26, 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0xFF, 0xFF\n"  /* 0x0603E02C */
    ".byte 0x06, 0x0A, 0x3E, 0x3C, 0x00, 0x00, 0xFF, 0x00, 0x06, 0x0A, 0x4C, 0x78, 0x06, 0x0A, 0x4C, 0x54\n"  /* 0x0603E03C */
    ".byte 0x06, 0x0A, 0x4C, 0x4C\n"  /* 0x0603E04C */
);

/* FUN_0603D438 -- original binary (4 bytes) */
__asm__(
    ".section .text.FUN_0603D438, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603D438\n"
    ".global _FUN_0603d438\n"
    ".type _FUN_0603D438, @function\n"
    "_FUN_0603D438:\n"
    "_FUN_0603d438:\n"
    ".byte 0x2F, 0xE6, 0xE6, 0x01\n"  /* 0x0603D438 */
);

/* FUN_0603D2CC -- original binary (4 bytes) */
__asm__(
    ".section .text.FUN_0603D2CC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603D2CC\n"
    ".global _FUN_0603d2cc\n"
    ".type _FUN_0603D2CC, @function\n"
    "_FUN_0603D2CC:\n"
    "_FUN_0603d2cc:\n"
    ".byte 0x2F, 0xE6, 0xE6, 0x01\n"  /* 0x0603D2CC */
);

/* FUN_0603D514 -- original binary (4 bytes) */
__asm__(
    ".section .text.FUN_0603D514, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603D514\n"
    ".global _FUN_0603d514\n"
    ".type _FUN_0603D514, @function\n"
    "_FUN_0603D514:\n"
    "_FUN_0603d514:\n"
    ".byte 0x2F, 0xE6, 0xE6, 0x01\n"  /* 0x0603D514 */
);

/* FUN_0603C104 -- original binary (8 bytes) */
__asm__(
    ".section .text.FUN_0603C104, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0603C104\n"
    ".global _FUN_0603c104\n"
    ".type _FUN_0603C104, @function\n"
    "_FUN_0603C104:\n"
    "_FUN_0603c104:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0xED, 0x08\n"  /* 0x0603C104 */
);
