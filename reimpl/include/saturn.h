/* saturn.h -- Saturn hardware register definitions
 *
 * Comprehensive register map derived from annotated ASM analysis
 * (system_init.s, vdp_hardware.s, vblank_system.s, sound_driver.s,
 * frame_timing.s, math_helpers.s).
 *
 * These are named constants for readability -- no abstraction layer.
 * Only registers confirmed in use by the Daytona USA binary are defined.
 */

#ifndef SATURN_H
#define SATURN_H

/* ===================================================================
 * VDP1 -- Video Display Processor 1 (Sprites / Polygons)
 * =================================================================== */

/* VDP1 VRAM (512KB) -- command tables, character patterns, gouraud tables */
#define VDP1_VRAM_BASE      ((volatile unsigned int *)0x25C00000)
#define VDP1_VRAM           ((volatile unsigned short *)0x25C00000)
#define VDP1_VRAM_SIZE      0x80000

/* VDP1 Framebuffer (512KB) -- double-buffered 512x224 16-bit */
#define VDP1_FB_BASE        ((volatile unsigned short *)0x25C80000)
#define VDP1_FB_SIZE        0x80000
#define VDP1_FB0_OFFSET     0x00000
#define VDP1_FB1_OFFSET     0x38000

/* VDP1 I/O Registers (0x25D00000-0x25D0001F) */
#define VDP1_TVMR   (*(volatile unsigned short *)0x25D00000)  /* TV Mode Selection */
#define VDP1_FBCR   (*(volatile unsigned short *)0x25D00002)  /* Frame Buffer Change Mode */
#define VDP1_PTMR   (*(volatile unsigned short *)0x25D00004)  /* Plot Trigger Mode */
#define VDP1_EWDR   (*(volatile unsigned short *)0x25D00006)  /* Erase/Write Data */
#define VDP1_EWLR   (*(volatile unsigned short *)0x25D00008)  /* Erase/Write Upper-Left */
#define VDP1_EWRR   (*(volatile unsigned short *)0x25D0000A)  /* Erase/Write Lower-Right */
#define VDP1_ENDR   (*(volatile unsigned short *)0x25D0000C)  /* Transfer End Bit */
#define VDP1_EDSR   (*(volatile unsigned short *)0x25D00010)  /* Transfer End Status */
#define VDP1_LOPR   (*(volatile unsigned short *)0x25D00012)  /* Last Process cmd addr */
#define VDP1_COPR   (*(volatile unsigned short *)0x25D00014)  /* Current Process cmd addr */
#define VDP1_MODR   (*(volatile unsigned short *)0x25D00016)  /* Mode Status */

/* FBCR bits used by Daytona */
#define FBCR_FCM    0x01  /* Frame change mode */
#define FBCR_FCT    0x02  /* Frame change trigger */
#define FBCR_SWAP   0x03  /* FCM+FCT: trigger buffer swap */

/* TVMR bits used by Daytona */
#define TVMR_VBE    0x08  /* VBlank erase enable (set during state 3) */


/* ===================================================================
 * VDP2 -- Video Display Processor 2 (Backgrounds / Tilemaps)
 * =================================================================== */

/* VDP2 VRAM (512KB) -- tilemap and character pattern data */
#define VDP2_VRAM_BASE  ((volatile unsigned short *)0x25E00000)
#define VDP2_VRAM       ((volatile unsigned short *)0x25E00000)
#define VDP2_VRAM_SIZE  0x80000

/* VDP2 VRAM layout used by Daytona:
 *   0x25E00000-0x25E1FFFF: Tilemap bank 0 (128KB)
 *   0x25E20000-0x25E3FFFF: Tilemap bank 1 (128KB) -- cleared in init
 *   0x25E40000-0x25E4FFFF: Character pattern 1 (64KB)
 *   0x25E60000-0x25E6FFFF: Character pattern 2 (64KB)
 *   0x25E70000-0x25E7FFFF: Character pattern 3 (64KB)
 */

/* VDP2 Color RAM (4KB) -- 512 palette entries, 16-bit color */
#define VDP2_CRAM_BASE  ((volatile unsigned short *)0x25F00000)
#define VDP2_CRAM       ((volatile unsigned short *)0x25F00000)
#define VDP2_CRAM_SIZE  0x1000

/* VDP2 Control Registers (0x25F80000-0x25F8011F) */
#define VDP2_TVMD   (*(volatile unsigned short *)0x25F80000)  /* TV Screen Mode */
#define VDP2_EXTEN  (*(volatile unsigned short *)0x25F80002)  /* External Signal Enable */
#define VDP2_TVSTAT (*(volatile unsigned short *)0x25F80004)  /* Screen Status (read-only) */
#define VDP2_VRSIZE (*(volatile unsigned short *)0x25F80006)  /* VRAM Size */
#define VDP2_HCNT   (*(volatile unsigned short *)0x25F80008)  /* H-Counter (read-only) */
#define VDP2_VCNT   (*(volatile unsigned short *)0x25F8000A)  /* V-Counter (read-only) */
#define VDP2_RAMCTL (*(volatile unsigned short *)0x25F8000E)  /* RAM Control */

/* VDP2 Scroll plane registers */
#define VDP2_CYCA0L (*(volatile unsigned short *)0x25F80010)  /* VRAM Cycle Pattern A0 Lo */
#define VDP2_CYCA0U (*(volatile unsigned short *)0x25F80012)  /* VRAM Cycle Pattern A0 Hi */
#define VDP2_CYCA1L (*(volatile unsigned short *)0x25F80014)  /* VRAM Cycle Pattern A1 Lo */
#define VDP2_CYCA1U (*(volatile unsigned short *)0x25F80016)  /* VRAM Cycle Pattern A1 Hi */
#define VDP2_CYCB0L (*(volatile unsigned short *)0x25F80018)  /* VRAM Cycle Pattern B0 Lo */
#define VDP2_CYCB0U (*(volatile unsigned short *)0x25F8001A)  /* VRAM Cycle Pattern B0 Hi */
#define VDP2_CYCB1L (*(volatile unsigned short *)0x25F8001C)  /* VRAM Cycle Pattern B1 Lo */
#define VDP2_CYCB1U (*(volatile unsigned short *)0x25F8001E)  /* VRAM Cycle Pattern B1 Hi */

#define VDP2_BGON   (*(volatile unsigned short *)0x25F80020)  /* BG Control (enable/disable) */
#define VDP2_MZCTL  (*(volatile unsigned short *)0x25F80022)  /* Mosaic Control */
#define VDP2_SFSEL  (*(volatile unsigned short *)0x25F80024)  /* Special Function Select */
#define VDP2_SFCODE (*(volatile unsigned short *)0x25F80026)  /* Special Function Code */
#define VDP2_CHCTLA (*(volatile unsigned short *)0x25F80028)  /* Char Control A (NBG0/1) */
#define VDP2_CHCTLB (*(volatile unsigned short *)0x25F8002A)  /* Char Control B (NBG2/3) */

/* Bitmap/plane size */
#define VDP2_BMPNA  (*(volatile unsigned short *)0x25F8002C)  /* Bitmap Palette Num A */
#define VDP2_BMPNB  (*(volatile unsigned short *)0x25F8002E)  /* Bitmap Palette Num B */

/* Pattern name control */
#define VDP2_PNCN0  (*(volatile unsigned short *)0x25F80030)  /* Pattern Name Control NBG0 */
#define VDP2_PNCN1  (*(volatile unsigned short *)0x25F80032)  /* Pattern Name Control NBG1 */
#define VDP2_PNCN2  (*(volatile unsigned short *)0x25F80034)  /* Pattern Name Control NBG2 */
#define VDP2_PNCN3  (*(volatile unsigned short *)0x25F80036)  /* Pattern Name Control NBG3 */
#define VDP2_PNCR   (*(volatile unsigned short *)0x25F80038)  /* Pattern Name Control RBG0 */

/* Plane size */
#define VDP2_PLSZ   (*(volatile unsigned short *)0x25F8003A)  /* Plane Size */

/* Map offset registers */
#define VDP2_MPOFN  (*(volatile unsigned short *)0x25F8003C)  /* Map Offset NBG */
#define VDP2_MPOFR  (*(volatile unsigned short *)0x25F8003E)  /* Map Offset RBG */

/* Map registers (16 per scroll plane) */
#define VDP2_MPABN0 (*(volatile unsigned short *)0x25F80040)  /* Map NBG0 Plane A,B */
#define VDP2_MPCDN0 (*(volatile unsigned short *)0x25F80042)  /* Map NBG0 Plane C,D */
#define VDP2_MPABN1 (*(volatile unsigned short *)0x25F80044)  /* Map NBG1 Plane A,B */
#define VDP2_MPCDN1 (*(volatile unsigned short *)0x25F80046)  /* Map NBG1 Plane C,D */
#define VDP2_MPABN2 (*(volatile unsigned short *)0x25F80048)  /* Map NBG2 Plane A,B */
#define VDP2_MPCDN2 (*(volatile unsigned short *)0x25F8004A)  /* Map NBG2 Plane C,D */
#define VDP2_MPABN3 (*(volatile unsigned short *)0x25F8004C)  /* Map NBG3 Plane A,B */
#define VDP2_MPCDN3 (*(volatile unsigned short *)0x25F8004E)  /* Map NBG3 Plane C,D */
#define VDP2_MPABRA (*(volatile unsigned short *)0x25F80050)  /* Map RBG0 Plane A,B */
#define VDP2_MPCDRA (*(volatile unsigned short *)0x25F80052)  /* Map RBG0 Plane C,D */
#define VDP2_MPEFRA (*(volatile unsigned short *)0x25F80054)  /* Map RBG0 Plane E,F */
#define VDP2_MPGHRA (*(volatile unsigned short *)0x25F80056)  /* Map RBG0 Plane G,H */

/* Scroll coordinates */
#define VDP2_SCXIN0 (*(volatile unsigned int *)0x25F80070)    /* Scroll X Integer NBG0 */
#define VDP2_SCYIN0 (*(volatile unsigned int *)0x25F80074)    /* Scroll Y Integer NBG0 */
#define VDP2_SCXIN1 (*(volatile unsigned int *)0x25F80078)    /* Scroll X Integer NBG1 */
#define VDP2_SCYIN1 (*(volatile unsigned int *)0x25F8007C)    /* Scroll Y Integer NBG1 */
#define VDP2_SCXN2  (*(volatile unsigned short *)0x25F80080)  /* Scroll X NBG2 */
#define VDP2_SCYN2  (*(volatile unsigned short *)0x25F80082)  /* Scroll Y NBG2 */
#define VDP2_SCXN3  (*(volatile unsigned short *)0x25F80084)  /* Scroll X NBG3 */
#define VDP2_SCYN3  (*(volatile unsigned short *)0x25F80086)  /* Scroll Y NBG3 */

/* Rotation scroll */
#define VDP2_ZMXIN0 (*(volatile unsigned short *)0x25F80088)  /* Zoom X Integer NBG0 */
#define VDP2_ZMXDN0 (*(volatile unsigned short *)0x25F8008A)  /* Zoom X Decimal NBG0 */
#define VDP2_ZMYIN0 (*(volatile unsigned short *)0x25F8008C)  /* Zoom Y Integer NBG0 */
#define VDP2_ZMYDN0 (*(volatile unsigned short *)0x25F8008E)  /* Zoom Y Decimal NBG0 */
#define VDP2_ZMXIN1 (*(volatile unsigned short *)0x25F80090)  /* Zoom X Integer NBG1 */
#define VDP2_ZMXDN1 (*(volatile unsigned short *)0x25F80092)  /* Zoom X Decimal NBG1 */
#define VDP2_ZMYIN1 (*(volatile unsigned short *)0x25F80094)  /* Zoom Y Integer NBG1 */
#define VDP2_ZMYDN1 (*(volatile unsigned short *)0x25F80096)  /* Zoom Y Decimal NBG1 */

/* Screen over / line scroll */
#define VDP2_SCRCTL (*(volatile unsigned short *)0x25F80098)  /* Scroll Control */
#define VDP2_VCSTA  (*(volatile unsigned int *)0x25F8009C)    /* Vertical Cell Scroll Addr */
#define VDP2_LSTA0  (*(volatile unsigned int *)0x25F800A0)    /* Line Scroll Table Addr 0 */
#define VDP2_LSTA1  (*(volatile unsigned int *)0x25F800A4)    /* Line Scroll Table Addr 1 */
#define VDP2_LCTA   (*(volatile unsigned int *)0x25F800A8)    /* Line Color Table Addr */

/* Back screen */
#define VDP2_BKTAU  (*(volatile unsigned short *)0x25F800AC)  /* Back Screen Table Upper */
#define VDP2_BKTAL  (*(volatile unsigned short *)0x25F800AE)  /* Back Screen Table Lower */

/* Rotation parameter table */
#define VDP2_RPMD   (*(volatile unsigned short *)0x25F800B0)  /* Rotation Parameter Mode */
#define VDP2_RPRCTL (*(volatile unsigned short *)0x25F800B2)  /* Rotation Param Read Ctrl */
#define VDP2_KTCTL  (*(volatile unsigned short *)0x25F800B4)  /* Coefficient Table Control */
#define VDP2_KTAOF  (*(volatile unsigned short *)0x25F800B6)  /* Coefficient Table Offset */
#define VDP2_OVPNRA (*(volatile unsigned short *)0x25F800B8)  /* Screen Over Pattern A */
#define VDP2_OVPNRB (*(volatile unsigned short *)0x25F800BA)  /* Screen Over Pattern B */
#define VDP2_RPTAU  (*(volatile unsigned short *)0x25F800BC)  /* Rotation Param Table Upper */
#define VDP2_RPTAL  (*(volatile unsigned short *)0x25F800BE)  /* Rotation Param Table Lower */

/* Window position */
#define VDP2_WPSX0  (*(volatile unsigned short *)0x25F800C0)  /* Window X Start 0 */
#define VDP2_WPSY0  (*(volatile unsigned short *)0x25F800C2)  /* Window Y Start 0 */
#define VDP2_WPEX0  (*(volatile unsigned short *)0x25F800C4)  /* Window X End 0 */
#define VDP2_WPEY0  (*(volatile unsigned short *)0x25F800C6)  /* Window Y End 0 */
#define VDP2_WPSX1  (*(volatile unsigned short *)0x25F800C8)  /* Window X Start 1 */
#define VDP2_WPSY1  (*(volatile unsigned short *)0x25F800CA)  /* Window Y Start 1 */
#define VDP2_WPEX1  (*(volatile unsigned short *)0x25F800CC)  /* Window X End 1 */
#define VDP2_WPEY1  (*(volatile unsigned short *)0x25F800CE)  /* Window Y End 1 */

/* Window control */
#define VDP2_WCTLA  (*(volatile unsigned short *)0x25F800D0)  /* Window Control A (NBG0/1) */
#define VDP2_WCTLB  (*(volatile unsigned short *)0x25F800D2)  /* Window Control B (NBG2/3) */
#define VDP2_WCTLC  (*(volatile unsigned short *)0x25F800D4)  /* Window Control C (RBG/SPR) */
#define VDP2_WCTLD  (*(volatile unsigned short *)0x25F800D6)  /* Window Control D (CC/back) */

/* Sprite control */
#define VDP2_SPCTL  (*(volatile unsigned short *)0x25F800E0)  /* Sprite Control */
#define VDP2_SDCTL  (*(volatile unsigned short *)0x25F800E2)  /* Shadow Control */

/* Color calc / priority */
#define VDP2_CRAOFA (*(volatile unsigned short *)0x25F800E4)  /* Color RAM Offset A */
#define VDP2_CRAOFB (*(volatile unsigned short *)0x25F800E6)  /* Color RAM Offset B */

#define VDP2_LNCLEN (*(volatile unsigned short *)0x25F800E8)  /* Line Color Screen Enable */
#define VDP2_SFPRMD (*(volatile unsigned short *)0x25F800EA)  /* Special Priority Mode */

#define VDP2_CCCTL  (*(volatile unsigned short *)0x25F800EC)  /* Color Calc Control */
#define VDP2_SFCCMD (*(volatile unsigned short *)0x25F800EE)  /* Special CC Mode */

/* Priority */
#define VDP2_PRINA  (*(volatile unsigned short *)0x25F800F0)  /* Priority A (NBG0/NBG1) */
#define VDP2_PRINB  (*(volatile unsigned short *)0x25F800F2)  /* Priority B (NBG2/NBG3) */
#define VDP2_PRIR   (*(volatile unsigned short *)0x25F800F4)  /* Priority R (RBG0) */

/* Color calculation ratio */
#define VDP2_CCRSA  (*(volatile unsigned short *)0x25F800F8)  /* CC Ratio A */
#define VDP2_CCRSB  (*(volatile unsigned short *)0x25F800FA)  /* CC Ratio B */
#define VDP2_CCRSC  (*(volatile unsigned short *)0x25F800FC)  /* CC Ratio C */
#define VDP2_CCRSD  (*(volatile unsigned short *)0x25F800FE)  /* CC Ratio D */
#define VDP2_CCRNA  (*(volatile unsigned short *)0x25F80100)  /* CC Ratio NBG A */
#define VDP2_CCRNB  (*(volatile unsigned short *)0x25F80102)  /* CC Ratio NBG B */
#define VDP2_CCRR   (*(volatile unsigned short *)0x25F80104)  /* CC Ratio RBG */
#define VDP2_CCRLB  (*(volatile unsigned short *)0x25F80106)  /* CC Ratio Line/Back */

/* Color offset */
#define VDP2_CLOFEN (*(volatile unsigned short *)0x25F80110)  /* Color Offset Enable */
#define VDP2_CLOFSL (*(volatile unsigned short *)0x25F80112)  /* Color Offset Select */
#define VDP2_COAR   (*(volatile unsigned short *)0x25F80114)  /* Color Offset A Red */
#define VDP2_COAG   (*(volatile unsigned short *)0x25F80116)  /* Color Offset A Green */
#define VDP2_COAB   (*(volatile unsigned short *)0x25F80118)  /* Color Offset A Blue */
#define VDP2_COBR   (*(volatile unsigned short *)0x25F8011A)  /* Color Offset B Red */
#define VDP2_COBG   (*(volatile unsigned short *)0x25F8011C)  /* Color Offset B Green */
#define VDP2_COBB   (*(volatile unsigned short *)0x25F8011E)  /* Color Offset B Blue */


/* ===================================================================
 * SCU -- System Control Unit
 * =================================================================== */

/* SCU DMA (Level 0) registers */
#define SCU_D0R     (*(volatile unsigned int *)0x25FE0000)    /* DMA L0 Read (Source) Addr */
#define SCU_D0W     (*(volatile unsigned int *)0x25FE0004)    /* DMA L0 Write (Dest) Addr */
#define SCU_D0C     (*(volatile unsigned int *)0x25FE0008)    /* DMA L0 Byte Count */
#define SCU_D0AD    (*(volatile unsigned int *)0x25FE000C)    /* DMA L0 Add Value */
#define SCU_D0EN    (*(volatile unsigned int *)0x25FE0010)    /* DMA L0 Enable */
#define SCU_D0MD    (*(volatile unsigned int *)0x25FE0014)    /* DMA L0 Mode */

/* SCU DMA (Level 1) registers */
#define SCU_D1R     (*(volatile unsigned int *)0x25FE0020)    /* DMA L1 Read Addr */
#define SCU_D1W     (*(volatile unsigned int *)0x25FE0024)    /* DMA L1 Write Addr */
#define SCU_D1C     (*(volatile unsigned int *)0x25FE0028)    /* DMA L1 Byte Count */
#define SCU_D1AD    (*(volatile unsigned int *)0x25FE002C)    /* DMA L1 Add Value */
#define SCU_D1EN    (*(volatile unsigned int *)0x25FE0030)    /* DMA L1 Enable */
#define SCU_D1MD    (*(volatile unsigned int *)0x25FE0034)    /* DMA L1 Mode */

/* SCU DMA (Level 2) registers */
#define SCU_D2R     (*(volatile unsigned int *)0x25FE0040)    /* DMA L2 Read Addr */
#define SCU_D2W     (*(volatile unsigned int *)0x25FE0044)    /* DMA L2 Write Addr */
#define SCU_D2C     (*(volatile unsigned int *)0x25FE0048)    /* DMA L2 Byte Count */
#define SCU_D2AD    (*(volatile unsigned int *)0x25FE004C)    /* DMA L2 Add Value */
#define SCU_D2EN    (*(volatile unsigned int *)0x25FE0050)    /* DMA L2 Enable */
#define SCU_D2MD    (*(volatile unsigned int *)0x25FE0054)    /* DMA L2 Mode */

/* SCU DMA forced stop */
#define SCU_DSTP    (*(volatile unsigned int *)0x25FE0060)    /* DMA Forced Stop */
#define SCU_DSTA    (*(volatile unsigned int *)0x25FE007C)    /* DMA Status */

/* SCU DMA status mask for idle polling -- verified from ASM */
#define SCU_DMA_BUSY_MASK   0x0000272E

/* SCU DMA mode values used by Daytona */
#define SCU_DMA_MODE_WORD   0x00000101  /* Word transfer, bus hold */

/* SCU Timer registers */
#define SCU_T0C     (*(volatile unsigned int *)0x25FE0080)    /* Timer 0 Compare */
#define SCU_T1S     (*(volatile unsigned int *)0x25FE0084)    /* Timer 1 Set */
#define SCU_T1MD    (*(volatile unsigned int *)0x25FE0088)    /* Timer 1 Mode */

/* SCU Interrupt registers */
#define SCU_IMS     (*(volatile unsigned int *)0x25FE00A0)    /* Interrupt Mask Set */
#define SCU_IST     (*(volatile unsigned int *)0x25FE00A4)    /* Interrupt Status */
#define SCU_AIACK   (*(volatile unsigned int *)0x25FE00A8)    /* A-Bus Interrupt Acknowledge */
#define SCU_ASR0    (*(volatile unsigned int *)0x25FE00B0)    /* A-Bus Status 0 */
#define SCU_ASR1    (*(volatile unsigned int *)0x25FE00B4)    /* A-Bus Status 1 */
#define SCU_AREF    (*(volatile unsigned int *)0x25FE00B8)    /* A-Bus Refresh */
#define SCU_RSEL    (*(volatile unsigned int *)0x25FE00C4)    /* SDRAM Select */


/* ===================================================================
 * SMPC -- System Manager & Peripheral Control
 * =================================================================== */
#define SMPC_IREG0  (*(volatile unsigned char *)0x20100001)   /* Input Register 0 */
#define SMPC_IREG1  (*(volatile unsigned char *)0x20100003)   /* Input Register 1 */
#define SMPC_IREG2  (*(volatile unsigned char *)0x20100005)   /* Input Register 2 */
#define SMPC_IREG3  (*(volatile unsigned char *)0x20100007)   /* Input Register 3 */
#define SMPC_IREG4  (*(volatile unsigned char *)0x20100009)   /* Input Register 4 */
#define SMPC_IREG5  (*(volatile unsigned char *)0x2010000B)   /* Input Register 5 */
#define SMPC_IREG6  (*(volatile unsigned char *)0x2010000D)   /* Input Register 6 */

#define SMPC_COMREG (*(volatile unsigned char *)0x2010001F)   /* Command Register */

#define SMPC_OREG0  (*(volatile unsigned char *)0x20100021)   /* Output Register 0 */
#define SMPC_OREG1  (*(volatile unsigned char *)0x20100023)   /* Output Register 1 */
#define SMPC_OREG2  (*(volatile unsigned char *)0x20100025)   /* Output Register 2 */
#define SMPC_OREG3  (*(volatile unsigned char *)0x20100027)   /* Output Register 3 */
#define SMPC_OREG4  (*(volatile unsigned char *)0x20100029)   /* Output Register 4 */
/* ... through OREG31 at 0x2010005F */

#define SMPC_SF     (*(volatile unsigned char *)0x20100063)   /* Status Flag */
#define SMPC_PDR1   (*(volatile unsigned char *)0x20100075)   /* Peripheral Data 1 */
#define SMPC_PDR2   (*(volatile unsigned char *)0x20100077)   /* Peripheral Data 2 */
#define SMPC_DDR1   (*(volatile unsigned char *)0x20100079)   /* Peripheral Data Dir 1 */
#define SMPC_DDR2   (*(volatile unsigned char *)0x2010007B)   /* Peripheral Data Dir 2 */
#define SMPC_IOSEL  (*(volatile unsigned char *)0x2010007D)   /* I/O Select */
#define SMPC_EXLE   (*(volatile unsigned char *)0x2010007F)   /* External Latch Enable */

/* SMPC commands used by Daytona */
#define SMPC_CMD_INTBACK    0x10  /* INTBACK - peripheral data request */
#define SMPC_CMD_SETSMEM    0x17  /* Set SMEM (backup RAM area) */
#define SMPC_CMD_NMIREQ     0x18  /* NMI Request */
#define SMPC_CMD_RESENAB    0x19  /* Reset Enable */
#define SMPC_CMD_RESDIS     0x1A  /* Reset Disable */


/* ===================================================================
 * SCSP -- Saturn Custom Sound Processor
 * =================================================================== */

/* SCSP shared sound RAM (1MB, accessible from SH-2) */
#define SCSP_RAM_BASE       ((volatile unsigned int *)0x25A00000)
#define SCSP_RAM            ((volatile unsigned short *)0x25A00000)
#define SCSP_RAM_SIZE       0x100000

/* SCSP sound command mailbox (shared with 68000) */
#define SCSP_MAILBOX        (*(volatile unsigned int *)0x25A02C20)

/* SCSP control registers */
#define SCSP_MVOL   (*(volatile unsigned short *)0x25B00400)  /* Master Volume */
#define SCSP_DAC    (*(volatile unsigned short *)0x25B00402)  /* DAC control */
#define SCSP_MEM    (*(volatile unsigned short *)0x25B00404)  /* Memory address */
#define SCSP_MSLC   (*(volatile unsigned short *)0x25B00408)  /* Monitor slot */
#define SCSP_CA     (*(volatile unsigned short *)0x25B0040A)  /* Call address */
#define SCSP_SCIEB  (*(volatile unsigned short *)0x25B0041E)  /* SCI Interrupt Enable */
#define SCSP_SCIPD  (*(volatile unsigned short *)0x25B00420)  /* SCI Interrupt Pending */
#define SCSP_SCIRE  (*(volatile unsigned short *)0x25B00422)  /* SCI Interrupt Reset */
#define SCSP_MCIPD  (*(volatile unsigned short *)0x25B00424)  /* Main CPU Int Pending */
#define SCSP_MCIRE  (*(volatile unsigned short *)0x25B00426)  /* Main CPU Int Reset */

/* SCSP sound command encoding (from sound_driver.s):
 *   0xA0xxxxxx = base SCSP command
 *   0xA17000FF = channel B command template
 *   0xA27000FF = channel C command template
 *   0xA37000FF = channel D command template
 *   Sound ID is shifted into bits 8-15
 */
#define SCSP_CMD_BASE       0xA0000000
#define SCSP_CMD_CHAN_B     0xA17000FF
#define SCSP_CMD_CHAN_C     0xA27000FF
#define SCSP_CMD_CHAN_D     0xA37000FF


/* ===================================================================
 * CD Block -- CD-ROM subsystem
 * =================================================================== */
#define CD_HIRQREQ  (*(volatile unsigned short *)0x25890008)  /* HIRQ Request */
#define CD_HIRQMSK  (*(volatile unsigned short *)0x2589000C)  /* HIRQ Mask */
#define CD_CR1      (*(volatile unsigned short *)0x25890018)  /* Command Register 1 */
#define CD_CR2      (*(volatile unsigned short *)0x2589001C)  /* Command Register 2 */
#define CD_CR3      (*(volatile unsigned short *)0x25890020)  /* Command Register 3 */
#define CD_CR4      (*(volatile unsigned short *)0x25890024)  /* Command Register 4 */
#define CD_MPEGRGB  (*(volatile unsigned int *)0x25890028)    /* MPEG RGB output */

/* HIRQ bits */
#define HIRQ_CMOK   0x0001  /* Command OK */
#define HIRQ_DRDY   0x0002  /* Data Transfer Ready */
#define HIRQ_CSCT   0x0004  /* CD Sector Ready */
#define HIRQ_BFUL   0x0008  /* CD Buffer Full */
#define HIRQ_PEND   0x0010  /* CD Play End */
#define HIRQ_DCHG   0x0020  /* Disc Change */
#define HIRQ_ESEL   0x0040  /* End Select */
#define HIRQ_EHST   0x0080  /* End Host Transfer */
#define HIRQ_ECPY   0x0100  /* End Copy/Move */
#define HIRQ_EFLS   0x0200  /* End File System */
#define HIRQ_SCDQ   0x0400  /* Sub-Code Q */


/* ===================================================================
 * SH-2 On-Chip Registers
 * =================================================================== */

/* Free-Running Timer (FRT) -- used for frame timing */
#define SH2_TIER    (*(volatile unsigned char *)0xFFFFFE10)   /* Timer Interrupt Enable */
#define SH2_FTCSR   (*(volatile unsigned char *)0xFFFFFE11)   /* FRT Control/Status */
#define SH2_FRC_H   (*(volatile unsigned char *)0xFFFFFE12)   /* Free-Running Counter Hi */
#define SH2_FRC_L   (*(volatile unsigned char *)0xFFFFFE13)   /* Free-Running Counter Lo */
#define SH2_OCRA_H  (*(volatile unsigned char *)0xFFFFFE14)   /* Output Compare A Hi */
#define SH2_OCRA_L  (*(volatile unsigned char *)0xFFFFFE15)   /* Output Compare A Lo */
#define SH2_OCRB_H  (*(volatile unsigned char *)0xFFFFFE16)   /* Output Compare B Hi */
#define SH2_OCRB_L  (*(volatile unsigned char *)0xFFFFFE17)   /* Output Compare B Lo */
#define SH2_TCR     (*(volatile unsigned char *)0xFFFFFE18)   /* Timer Control */
#define SH2_TOCR    (*(volatile unsigned char *)0xFFFFFE19)   /* Timer Output Compare Ctrl */
#define SH2_FICR_H  (*(volatile unsigned char *)0xFFFFFE1A)   /* Input Capture Hi */
#define SH2_FICR_L  (*(volatile unsigned char *)0xFFFFFE1B)   /* Input Capture Lo */

/* Interrupt Controller */
#define SH2_IPRA    (*(volatile unsigned short *)0xFFFFFEE2)  /* Interrupt Priority A */
#define SH2_IPRB    (*(volatile unsigned short *)0xFFFFFE60)  /* Interrupt Priority B */

/* Watchdog Timer */
#define SH2_WTCSR   (*(volatile unsigned char *)0xFFFFFE80)   /* Watchdog Timer CSR */
#define SH2_WTCNT   (*(volatile unsigned char *)0xFFFFFE81)   /* Watchdog Timer Counter */

/* Bus State Controller */
#define SH2_BCR1    (*(volatile unsigned int *)0xFFFFFFE0)    /* Bus Control 1 */
#define SH2_BCR2    (*(volatile unsigned int *)0xFFFFFFE4)    /* Bus Control 2 */
#define SH2_WCR     (*(volatile unsigned int *)0xFFFFFFE8)    /* Wait Control */
#define SH2_MCR     (*(volatile unsigned int *)0xFFFFFFEC)    /* Memory Control */

/* Hardware Division Unit -- critical, shared resource */
#define SH2_DVSR    (*(volatile int *)0xFFFFFF00)             /* Divisor */
#define SH2_DVDNT   (*(volatile int *)0xFFFFFF04)             /* Dividend (32/32 trigger) */
#define SH2_DVCR    (*(volatile int *)0xFFFFFF08)             /* Division Control */
#define SH2_VCRDIV  (*(volatile int *)0xFFFFFF0C)             /* Div Overflow Vector */
#define SH2_DVDNTH  (*(volatile int *)0xFFFFFF10)             /* Dividend High (64/32) */
#define SH2_DVDNTL  (*(volatile int *)0xFFFFFF14)             /* Dividend Low (64/32 trig) */
#define SH2_DVDNTH_R (*(volatile int *)0xFFFFFF18)            /* Remainder (after div) */
#define SH2_DVDNTL_R (*(volatile int *)0xFFFFFF1C)            /* Quotient (after div) */


/* ===================================================================
 * BIOS Function Pointers (Low HWRAM, set up by IP.BIN)
 *
 * These are indirect function pointers at fixed addresses in work RAM.
 * IP.BIN initializes them before jumping to our code at 0x06003000.
 * =================================================================== */
#define BIOS_FUNC_0300  (*(void (**)(int, int))0x06000300)    /* Interrupt handler reg */
#define BIOS_FUNC_0310  (*(void (**)(int, int))0x06000310)    /* BIOS service call */
#define BIOS_FUNC_0320  (*(void (**)(int))0x06000320)         /* BIOS service call 2 */
#define BIOS_FUNC_0344  (*(void (**)(int, int))0x06000344)    /* Interrupt mask control */

/* BIOS vector numbers (r4 argument to BIOS_FUNC_0300) */
#define BIOS_VEC_VBLANK_IN     0x40
#define BIOS_VEC_VBLANK_OUT    0x41


#endif /* SATURN_H */
