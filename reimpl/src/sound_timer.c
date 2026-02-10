#include "saturn.h"
#include "game.h"

/*
 * sound_timer_init -- sound_timer_init
 *
 * Configures SH-2 Free-Running Timer (FRT) and installs a BIOS handler.
 *
 * From disassembly (0x06003218-0x06003272):
 *   1. Call BIOS via *(0x06000310) with cmd=101 (0x65), dest=0x060072E4
 *   2. Read SH-2 TIER (0xFFFFFE10): AND with 0x0F, OR with 0x08, write back
 *   3. Read 0xFFFFFE11 (FTCSR): OR bit 0 (set), write back
 *   4. Read 0xFFFFFE14 (FRC high): AND with 0xFC, write back
 *   5. Read 0xFFFFFE15 (FRC low): AND with 0xEF, write back
 *   6. Write 0x01 to 0xFFFFFE16 (TOCR)
 *   7. Write 0x66 to 0xFFFFFE17 (OCR high)
 *   8. Write 0x00 to 0xFFFFFE14
 *   9. Write 0x00 to 0xFFFFFE15
 */

/* SH-2 FRT registers (byte-addressable) */
#define SH2_FRT_TIER    (*(volatile unsigned char *)0xFFFFFE10)
#define SH2_FRT_FTCSR   (*(volatile unsigned char *)0xFFFFFE11)
#define SH2_FRT_FRC_H   (*(volatile unsigned char *)0xFFFFFE12)
#define SH2_FRT_FRC_L   (*(volatile unsigned char *)0xFFFFFE13)
#define SH2_FRT_OCRX_H  (*(volatile unsigned char *)0xFFFFFE14)
#define SH2_FRT_OCRX_L  (*(volatile unsigned char *)0xFFFFFE15)
#define SH2_FRT_TOCR    (*(volatile unsigned char *)0xFFFFFE16)
#define SH2_FRT_OCR_H   (*(volatile unsigned char *)0xFFFFFE17)

void sound_timer_init(void)
{
    unsigned char tmp;
    void (*bios_fn)(int, int) = BIOS_FUNC_0310;

    /* Install timer handler via BIOS: cmd=101, handler=0x060072E4 */
    bios_fn(101, 0x060072E4);

    /* Configure TIER: keep low nibble, set bit 3 (output compare interrupt) */
    tmp = SH2_FRT_TIER;
    tmp = (tmp & 0x0F) | 0x08;
    SH2_FRT_TIER = tmp;

    /* Configure FTCSR: set bit 0 (clear counter) */
    tmp = SH2_FRT_FTCSR;
    tmp |= 0x01;
    SH2_FRT_FTCSR = tmp;

    /* Configure OCR: clear bits 1-0 of high byte */
    tmp = SH2_FRT_OCRX_H;
    tmp &= 0xFC;
    SH2_FRT_OCRX_H = tmp;

    /* Clear bits 4 of low byte */
    tmp = SH2_FRT_OCRX_L;
    tmp = (tmp & 0xEF);
    SH2_FRT_OCRX_L = tmp;

    /* Set TOCR and OCR values */
    SH2_FRT_TOCR = 0x01;
    SH2_FRT_OCR_H = 0x66;

    /* Reset free-running counter */
    SH2_FRT_OCRX_H = 0x00;
    SH2_FRT_OCRX_L = 0x00;
}

void FUN_06003218(void) __attribute__((alias("sound_timer_init")));
