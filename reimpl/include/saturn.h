/* saturn.h -- Saturn hardware register definitions
 *
 * Derived from annotated ASM (system_init.s, vdp_hardware.s, vblank_system.s).
 * These are just named constants for readability -- no abstraction layer.
 */

#ifndef SATURN_H
#define SATURN_H

/* --- VDP2 Registers (0x25F80000-0x25F8011F) --- */
#define VDP2_TVMD   (*(volatile unsigned short *)0x25F80000)  /* TV Mode */
#define VDP2_EXTEN  (*(volatile unsigned short *)0x25F80002)  /* External Signal Enable */
#define VDP2_TVSTAT (*(volatile unsigned short *)0x25F80004)  /* TV Status (read-only) */
#define VDP2_VRSIZE (*(volatile unsigned short *)0x25F80006)  /* VRAM Size */
#define VDP2_RAMCTL (*(volatile unsigned short *)0x25F8000E)  /* RAM Control */
#define VDP2_BKTAU  (*(volatile unsigned short *)0x25F800AC)  /* Back Screen Table Addr (upper) */
#define VDP2_BKTAL  (*(volatile unsigned short *)0x25F800AE)  /* Back Screen Table Addr (lower) */
#define VDP2_PRINA  (*(volatile unsigned short *)0x25F800F0)  /* Priority Number A (NBG0/NBG1) */
#define VDP2_PRINB  (*(volatile unsigned short *)0x25F800F2)  /* Priority Number B (NBG2/NBG3) */

/* --- VDP2 VRAM (0x25E00000-0x25E7FFFF, 512KB) --- */
#define VDP2_VRAM   ((volatile unsigned short *)0x25E00000)

/* --- VDP1 Registers (0x25D00000-0x25D0001F) --- */
#define VDP1_TVMR   (*(volatile unsigned short *)0x25D00000)  /* TV Mode Selection */
#define VDP1_FBCR   (*(volatile unsigned short *)0x25D00002)  /* Frame Buffer Change Mode */
#define VDP1_PTMR   (*(volatile unsigned short *)0x25D00004)  /* Plot Trigger */
#define VDP1_EWDR   (*(volatile unsigned short *)0x25D00006)  /* Erase/Write Data */
#define VDP1_EWLR   (*(volatile unsigned short *)0x25D00008)  /* Erase/Write Upper Left */
#define VDP1_EWRR   (*(volatile unsigned short *)0x25D0000A)  /* Erase/Write Lower Right */
#define VDP1_EDSR   (*(volatile unsigned short *)0x25D00010)  /* Transfer End Status */

/* --- SCU Registers (0x25FE0000+) --- */
#define SCU_IMS     (*(volatile unsigned int *)0x25FE00A0)    /* Interrupt Mask */
#define SCU_IST     (*(volatile unsigned int *)0x25FE00A4)    /* Interrupt Status */

/* --- SH-2 On-Chip Registers --- */
#define SH2_TIER    (*(volatile unsigned char *)0xFFFFFE10)   /* Timer Interrupt Enable */
#define SH2_FTCSR   (*(volatile unsigned char *)0xFFFFFE11)   /* FRT Control/Status */
#define SH2_IPRA    (*(volatile unsigned short *)0xFFFFFEE2)  /* Interrupt Priority A */

/* --- SMPC (System Manager & Peripheral Control) --- */
#define SMPC_SF     (*(volatile unsigned char *)0x20100063)   /* Status Flag */
#define SMPC_IREG0  (*(volatile unsigned char *)0x20100001)   /* Input Register 0 */
#define SMPC_COMREG (*(volatile unsigned char *)0x2010001F)   /* Command Register */
#define SMPC_OREG0  (*(volatile unsigned char *)0x20100021)   /* Output Register 0 */

/* --- Sound (SCSP / 68000) --- */
#define SCSP_MVOL   (*(volatile unsigned short *)0x25B00400)  /* Master Volume */

/* --- CD Block --- */
#define CD_HIRQREQ  (*(volatile unsigned short *)0x25890008)  /* HIRQ Request */
#define CD_HIRQMSK  (*(volatile unsigned short *)0x2589000C)  /* HIRQ Mask */

#endif /* SATURN_H */
