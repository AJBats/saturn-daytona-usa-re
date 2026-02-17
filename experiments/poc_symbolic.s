/* POC: FUN_0600E71A — player physics orchestrator
 * Sawyer L2: constant pool entries symbolized.
 * Instructions stay as .byte (they're already correct).
 * Pool entries use .long _SYMBOL — linker resolves the addresses. */

    .section .text
    .org 0x0

    .global _FUN_0600E71A
_FUN_0600E71A:
    .byte 0x2F, 0xE6  /* mov.l r14,@-r15 */
    .byte 0x4F, 0x22  /* sts.l pr,@-r15 */
    .byte 0x4F, 0x12  /* sts.l macl,@-r15 */
    .byte 0xDE, 0x21  /* mov.l @(0x84,PC),r14 -> pool[0] */
    .byte 0xD3, 0x22  /* mov.l @(0x88,PC),r3  -> pool[1] */
    .byte 0x43, 0x0B  /* jsr @r3 */
    .byte 0x6E, 0xE2  /* mov.l @r14,r14 */
    .byte 0xD3, 0x21  /* mov.l @(0x84,PC),r3  -> pool[2] */
    .byte 0x43, 0x0B  /* jsr @r3 */
    .byte 0x00, 0x09  /* nop */
    .byte 0xD3, 0x21  /* mov.l @(0x84,PC),r3  -> pool[3] */
    .byte 0x43, 0x0B  /* jsr @r3 */
    .byte 0x00, 0x09  /* nop */
    .byte 0xD3, 0x20  /* mov.l @(0x80,PC),r3  -> pool[4] */
    .byte 0x43, 0x0B  /* jsr @r3 */
    .byte 0x00, 0x09  /* nop */
    .byte 0xD3, 0x20  /* mov.l @(0x80,PC),r3  -> pool[5] */
    .byte 0x43, 0x0B  /* jsr @r3 */
    .byte 0x00, 0x09  /* nop */
    .byte 0x90, 0x2C  /* mov.w @(0x58,PC),r0 */
    .byte 0x02, 0xEE  /* mov.l @(r0,r14),r2 */
    .byte 0x42, 0x15  /* cmp/pl r2 */
    .byte 0x8B, 0x17  /* bf 0x78 */
    .byte 0x90, 0x28  /* mov.w @(0x50,PC),r0 */
    .byte 0x02, 0xEE  /* mov.l @(r0,r14),r2 */
    .byte 0x72, 0xFF  /* add #-1,r2 */
    .byte 0x0E, 0x26  /* mov.l r2,@(r0,r14) */
    .byte 0x22, 0x28  /* tst r2,r2 */
    .byte 0x8B, 0x11  /* bf 0x78 */
    .byte 0x90, 0x23  /* mov.w @(0x46,PC),r0 */
    .byte 0x04, 0xEE  /* mov.l @(r0,r14),r4 */
    .byte 0x63, 0x43  /* mov r4,r3 */
    .byte 0x44, 0x08  /* shll2 r4 */
    .byte 0x44, 0x00  /* shll r4 */
    .byte 0x43, 0x08  /* shll2 r3 */
    .byte 0x43, 0x08  /* shll2 r3 */
    .byte 0x34, 0x3C  /* add r3,r4 */
    .byte 0x70, 0xFC  /* add #-4,r0 */
    .byte 0x03, 0xEE  /* mov.l @(r0,r14),r3 */
    .byte 0x34, 0x3C  /* add r3,r4 */
    .byte 0x85, 0x4A  /* mov.w @(0x14,r4),r0 */
    .byte 0x63, 0x03  /* mov r0,r3 */
    .byte 0x90, 0x17  /* mov.w @(0x2E,PC),r0 */
    .byte 0x0E, 0x36  /* mov.l r3,@(r0,r14) */
    .byte 0x93, 0x16  /* mov.w @(0x2C,PC),r3 */
    .byte 0x70, 0x0C  /* add #12,r0 */
    .byte 0x0E, 0x36  /* mov.l r3,@(r0,r14) */
    .byte 0xD3, 0x11  /* mov.l @(0x44,PC),r3  -> pool[6] */
    .byte 0x43, 0x0B  /* jsr @r3 */
    .byte 0x00, 0x09  /* nop */
    .byte 0x90, 0x11  /* mov.w @(0x22,PC),r0 */
    .byte 0xD3, 0x10  /* mov.l @(0x40,PC),r3  -> pool[7] */
    .byte 0x02, 0xEE  /* mov.l @(r0,r14),r2 */
    .byte 0x63, 0x32  /* mov.l @r3,r3 */
    .byte 0x70, 0xC4  /* add #-60,r0 */
    .byte 0x02, 0x37  /* mul.l r3,r2 */
    .byte 0x03, 0xEE  /* mov.l @(r0,r14),r3 */
    .byte 0x02, 0x1A  /* sts macl,r2 */
    .byte 0x70, 0x08  /* add #8,r0 */
    .byte 0x32, 0x3C  /* add r3,r2 */
    .byte 0x0E, 0x26  /* mov.l r2,@(r0,r14) */
    .byte 0x4F, 0x16  /* lds.l @r15+,macl */
    .byte 0x4F, 0x26  /* lds.l @r15+,pr */
    .byte 0x00, 0x0B  /* rts */
    .byte 0x6E, 0xF6  /* mov.l @r15+,r14 */
/* --- inline word constants (PC-relative mov.w targets) --- */
    .byte 0x02, 0x08  /* 0x0208 */
    .byte 0x01, 0xE4  /* 0x01E4 */
    .byte 0x01, 0xF8  /* 0x01F8 */
    .byte 0x04, 0x00  /* 0x0400 */
    .byte 0x02, 0x28  /* 0x0228 */
    .byte 0xFF, 0xFF  /* 0xFFFF */
/* --- constant pool (SYMBOLIZED) --- */
/* .4byte avoids alignment check — pool is 4-byte aligned absolutely
   but not relative to section start (function starts at 0xE71A = 2 mod 4) */
/* pool[0]: */ .4byte _DAT_0607E940  /* car object pointer */
/* pool[1]: */ .4byte _FUN_06008318  /* controller input handler */
/* pool[2]: */ .4byte _FUN_06008640  /* gear/force table selection */
/* pool[3]: */ .4byte _FUN_0600D266  /* friction stub */
/* pool[4]: */ .4byte _FUN_0600C4F8  /* speed computation */
/* pool[5]: */ .4byte _FUN_0600C5D6  /* collision detection */
/* pool[6]: */ .4byte _FUN_0600CEBA  /* track segment advancement */
/* pool[7]: */ .4byte _DAT_0607EA9C  /* car count */
