#!/usr/bin/env python3
"""classify_pool.py -- Auto-classify and rename machine-generated pool labels.

Scans reimpl/src/*.s for .L_pool_ and .L_wpool_ labels, classifies the value,
and optionally renames them to semantic names.

Usage:
    python tools/classify_pool.py                # dry run, show stats
    python tools/classify_pool.py --detail       # show every proposed rename
    python tools/classify_pool.py --apply        # apply renames to files
    python tools/classify_pool.py --file X.s     # single file only
"""

import re, os, sys, argparse
from collections import defaultdict, Counter

# ===== Saturn Hardware Register Map =====
# Exact address -> (device, register_name, description)

HW_REGISTERS = {
    # VDP1 registers (cache-through)
    0x25D00000: ("vdp1", "tvmr", "TV mode"),
    0x25D00002: ("vdp1", "fbcr", "framebuffer change"),
    0x25D00004: ("vdp1", "ptmr", "plot trigger"),
    0x25D00006: ("vdp1", "ewdr", "erase fill color"),
    0x25D00008: ("vdp1", "ewlr", "erase upper-left"),
    0x25D0000A: ("vdp1", "ewrr", "erase lower-right"),
    0x25D0000C: ("vdp1", "endr", "force-terminate drawing"),
    0x25D00010: ("vdp1", "edsr", "end status"),
    0x25D00012: ("vdp1", "lopr", "last command addr"),
    0x25D00014: ("vdp1", "copr", "current command addr"),
    0x25D00016: ("vdp1", "modr", "mode readback"),
    # VDP1 non-cache-through
    0x05D00000: ("vdp1", "tvmr_nc", "TV mode (non-CT)"),
    0x05D00002: ("vdp1", "fbcr_nc", "framebuffer change (non-CT)"),
    0x05D00004: ("vdp1", "ptmr_nc", "plot trigger (non-CT)"),
    0x05D00006: ("vdp1", "ewdr_nc", "erase fill color (non-CT)"),
    0x05D00008: ("vdp1", "ewlr_nc", "erase upper-left (non-CT)"),
    0x05D0000A: ("vdp1", "ewrr_nc", "erase lower-right (non-CT)"),
    0x05D0000C: ("vdp1", "endr_nc", "force-terminate (non-CT)"),
    0x05D00010: ("vdp1", "edsr_nc", "end status (non-CT)"),

    # VDP2 registers (cache-through)
    0x25F80000: ("vdp2", "tvmd", "TV mode/resolution"),
    0x25F80002: ("vdp2", "exten", "external signal"),
    0x25F80004: ("vdp2", "tvstat", "TV status"),
    0x25F80006: ("vdp2", "vrsize", "VRAM size"),
    0x25F80008: ("vdp2", "hcnt", "H counter"),
    0x25F8000A: ("vdp2", "vcnt", "V counter"),
    0x25F8000E: ("vdp2", "ramctl", "RAM control"),
    0x25F80020: ("vdp2", "bgon", "BG enable"),
    0x25F80022: ("vdp2", "mzctl", "mosaic control"),
    0x25F80028: ("vdp2", "chctla", "char control A"),
    0x25F8002A: ("vdp2", "chctlb", "char control B"),
    0x25F80030: ("vdp2", "pncn0", "pattern NBG0"),
    0x25F80032: ("vdp2", "pncn1", "pattern NBG1"),
    0x25F80034: ("vdp2", "pncn2", "pattern NBG2"),
    0x25F80036: ("vdp2", "pncn3", "pattern NBG3"),
    0x25F80038: ("vdp2", "pncr", "pattern RBG0"),
    0x25F8003A: ("vdp2", "plsz", "plane size"),
    0x25F8003C: ("vdp2", "mpofn", "map offset NBG"),
    0x25F8003E: ("vdp2", "mpofr", "map offset RBG"),
    0x25F80070: ("vdp2", "scxin0", "NBG0 H scroll int"),
    0x25F80072: ("vdp2", "scxdn0", "NBG0 H scroll frac"),
    0x25F80074: ("vdp2", "scyin0", "NBG0 V scroll int"),
    0x25F80076: ("vdp2", "scydn0", "NBG0 V scroll frac"),
    0x25F80078: ("vdp2", "zmxin0", "NBG0 X zoom int"),
    0x25F8007A: ("vdp2", "zmxdn0", "NBG0 X zoom frac"),
    0x25F8007C: ("vdp2", "zmyin0", "NBG0 Y zoom int"),
    0x25F8007E: ("vdp2", "zmydn0", "NBG0 Y zoom frac"),
    0x25F80080: ("vdp2", "scxin1", "NBG1 H scroll int"),
    0x25F80082: ("vdp2", "scxdn1", "NBG1 H scroll frac"),
    0x25F80084: ("vdp2", "scyin1", "NBG1 V scroll int"),
    0x25F80086: ("vdp2", "scydn1", "NBG1 V scroll frac"),
    0x25F80088: ("vdp2", "zmxin1", "NBG1 X zoom int"),
    0x25F8008A: ("vdp2", "zmxdn1", "NBG1 X zoom frac"),
    0x25F8008C: ("vdp2", "zmyin1", "NBG1 Y zoom int"),
    0x25F8008E: ("vdp2", "zmydn1", "NBG1 Y zoom frac"),
    0x25F80090: ("vdp2", "scxn2", "NBG2 H scroll"),
    0x25F80092: ("vdp2", "scyn2", "NBG2 V scroll"),
    0x25F80094: ("vdp2", "scxn3", "NBG3 H scroll"),
    0x25F80096: ("vdp2", "scyn3", "NBG3 V scroll"),
    0x25F80098: ("vdp2", "zmctl", "zoom control"),
    0x25F8009A: ("vdp2", "scrctl", "scroll control"),
    0x25F8009C: ("vdp2", "vcstau", "vert cell scroll tbl U"),
    0x25F8009E: ("vdp2", "vcstal", "vert cell scroll tbl L"),
    0x25F800A0: ("vdp2", "lsta0u", "line scroll tbl 0 U"),
    0x25F800A2: ("vdp2", "lsta0l", "line scroll tbl 0 L"),
    0x25F800A4: ("vdp2", "lsta1u", "line scroll tbl 1 U"),
    0x25F800A6: ("vdp2", "lsta1l", "line scroll tbl 1 L"),
    0x25F800A8: ("vdp2", "lcta0u", "line color tbl 0 U"),
    0x25F800AA: ("vdp2", "lcta0l", "line color tbl 0 L"),
    0x25F800AC: ("vdp2", "lcta1u", "line color tbl 1 U"),
    0x25F800AE: ("vdp2", "lcta1l", "line color tbl 1 L"),
    0x25F800B0: ("vdp2", "rpmd", "rotation mode"),
    0x25F800B2: ("vdp2", "rprctl", "rotation param control"),
    0x25F800B4: ("vdp2", "ktctl", "coeff table control"),
    0x25F800B6: ("vdp2", "ktaof", "coeff table offset"),
    0x25F800B8: ("vdp2", "ovpnra", "over-pattern A"),
    0x25F800BA: ("vdp2", "ovpnrb", "over-pattern B"),
    0x25F800BC: ("vdp2", "rptau", "rotation table addr U"),
    0x25F800BE: ("vdp2", "rptal", "rotation table addr L"),
    0x25F800C0: ("vdp2", "wpsx0", "window 0 X start"),
    0x25F800C2: ("vdp2", "wpsy0", "window 0 Y start"),
    0x25F800C4: ("vdp2", "wpex0", "window 0 X end"),
    0x25F800C6: ("vdp2", "wpey0", "window 0 Y end"),
    0x25F800C8: ("vdp2", "wpsx1", "window 1 X start"),
    0x25F800CA: ("vdp2", "wpsy1", "window 1 Y start"),
    0x25F800CC: ("vdp2", "wpex1", "window 1 X end"),
    0x25F800CE: ("vdp2", "wpey1", "window 1 Y end"),
    0x25F800D0: ("vdp2", "wctla", "window control A"),
    0x25F800D2: ("vdp2", "wctlb", "window control B"),
    0x25F800D4: ("vdp2", "wctlc", "window control C"),
    0x25F800D6: ("vdp2", "wctld", "window control D"),
    0x25F800D8: ("vdp2", "lwta0u", "line window tbl 0 U"),
    0x25F800DA: ("vdp2", "lwta0l", "line window tbl 0 L"),
    0x25F800DC: ("vdp2", "lwta1u", "line window tbl 1 U"),
    0x25F800DE: ("vdp2", "lwta1l", "line window tbl 1 L"),
    0x25F800E0: ("vdp2", "spctl", "sprite control"),
    0x25F800E2: ("vdp2", "sdctl", "shadow control"),
    0x25F800E4: ("vdp2", "craofa", "CRAM offset A"),
    0x25F800E6: ("vdp2", "craofb", "CRAM offset B"),
    0x25F800E8: ("vdp2", "lnclen", "line color enable"),
    0x25F800EA: ("vdp2", "sfprmd", "special priority mode"),
    0x25F800EC: ("vdp2", "ccctl", "color calc control"),
    0x25F800EE: ("vdp2", "sfccmd", "special CC mode"),
    0x25F800F0: ("vdp2", "prisa", "sprite priority A"),
    0x25F800F2: ("vdp2", "prisb", "sprite priority B"),
    0x25F800F4: ("vdp2", "prisc", "sprite priority C"),
    0x25F800F6: ("vdp2", "prisd", "sprite priority D"),
    0x25F800F8: ("vdp2", "prina", "priority NBG0/1"),
    0x25F800FA: ("vdp2", "prinb", "priority NBG2/3"),
    0x25F800FC: ("vdp2", "prir", "priority RBG0"),
    0x25F80100: ("vdp2", "ccrsa", "CC ratio sprite A"),
    0x25F80102: ("vdp2", "ccrsb", "CC ratio sprite B"),
    0x25F80104: ("vdp2", "ccrna", "CC ratio NBG0/1"),
    0x25F80106: ("vdp2", "ccrnb", "CC ratio NBG2/3"),
    0x25F80108: ("vdp2", "ccrr", "CC ratio RBG0"),
    0x25F8010A: ("vdp2", "ccrlb", "CC ratio line/back"),
    0x25F80110: ("vdp2", "clofen", "color offset enable"),
    0x25F80112: ("vdp2", "clofsl", "color offset select"),
    0x25F80114: ("vdp2", "coar", "color offset A red"),
    0x25F80116: ("vdp2", "coag", "color offset A green"),
    0x25F80118: ("vdp2", "coab", "color offset A blue"),
    0x25F8011A: ("vdp2", "cobr", "color offset B red"),
    0x25F8011C: ("vdp2", "cobg", "color offset B green"),
    0x25F8011E: ("vdp2", "cobb", "color offset B blue"),

    # SCU registers (cache-through)
    0x25FE0000: ("scu", "d0r", "DMA L0 read addr"),
    0x25FE0004: ("scu", "d0w", "DMA L0 write addr"),
    0x25FE0008: ("scu", "d0c", "DMA L0 byte count"),
    0x25FE000C: ("scu", "d0ad", "DMA L0 addr add"),
    0x25FE0010: ("scu", "d0en", "DMA L0 enable"),
    0x25FE0014: ("scu", "d0md", "DMA L0 mode"),
    0x25FE0020: ("scu", "d1r", "DMA L1 read addr"),
    0x25FE0024: ("scu", "d1w", "DMA L1 write addr"),
    0x25FE0028: ("scu", "d1c", "DMA L1 byte count"),
    0x25FE002C: ("scu", "d1ad", "DMA L1 addr add"),
    0x25FE0030: ("scu", "d1en", "DMA L1 enable"),
    0x25FE0034: ("scu", "d1md", "DMA L1 mode"),
    0x25FE0040: ("scu", "d2r", "DMA L2 read addr"),
    0x25FE0044: ("scu", "d2w", "DMA L2 write addr"),
    0x25FE0048: ("scu", "d2c", "DMA L2 byte count"),
    0x25FE004C: ("scu", "d2ad", "DMA L2 addr add"),
    0x25FE0050: ("scu", "d2en", "DMA L2 enable"),
    0x25FE0054: ("scu", "d2md", "DMA L2 mode"),
    0x25FE0060: ("scu", "dstp", "DMA force stop"),
    0x25FE007C: ("scu", "dsta", "DMA status"),
    0x25FE0080: ("scu", "ppaf", "DSP program control"),
    0x25FE0084: ("scu", "ppd", "DSP program data"),
    0x25FE0088: ("scu", "pda", "DSP data addr"),
    0x25FE008C: ("scu", "pdd", "DSP data port"),
    0x25FE0090: ("scu", "t0c", "timer 0 compare"),
    0x25FE0094: ("scu", "t1s", "timer 1 set"),
    0x25FE0098: ("scu", "t1md", "timer 1 mode"),
    0x25FE00A0: ("scu", "ims", "interrupt mask"),
    0x25FE00A4: ("scu", "ist", "interrupt status"),
    0x25FE00A8: ("scu", "aiack", "A-Bus int ack"),
    0x25FE00B0: ("scu", "asr0", "A-Bus set 0"),
    0x25FE00B4: ("scu", "asr1", "A-Bus set 1"),
    0x25FE00B8: ("scu", "aref", "A-Bus refresh"),
    0x25FE00C8: ("scu", "ver", "SCU version"),

    # SMPC registers (odd bytes only, 8-bit access)
    0x20100001: ("smpc", "ireg0", "input reg 0"),
    0x20100003: ("smpc", "ireg1", "input reg 1"),
    0x20100005: ("smpc", "ireg2", "input reg 2"),
    0x20100007: ("smpc", "ireg3", "input reg 3"),
    0x20100009: ("smpc", "ireg4", "input reg 4"),
    0x2010000B: ("smpc", "ireg5", "input reg 5"),
    0x2010000D: ("smpc", "ireg6", "input reg 6"),
    0x2010001F: ("smpc", "comreg", "command register"),
    0x20100021: ("smpc", "oreg0", "output reg 0"),
    0x20100023: ("smpc", "oreg1", "output reg 1"),
    0x20100025: ("smpc", "oreg2", "output reg 2"),
    0x20100027: ("smpc", "oreg3", "output reg 3"),
    0x20100029: ("smpc", "oreg4", "output reg 4"),
    0x2010002B: ("smpc", "oreg5", "output reg 5"),
    0x2010002D: ("smpc", "oreg6", "output reg 6"),
    0x2010002F: ("smpc", "oreg7", "output reg 7"),
    0x20100031: ("smpc", "oreg8", "output reg 8"),
    0x20100033: ("smpc", "oreg9", "output reg 9"),
    0x20100035: ("smpc", "oreg10", "output reg 10"),
    0x20100037: ("smpc", "oreg11", "output reg 11"),
    0x20100039: ("smpc", "oreg12", "output reg 12"),
    0x2010003B: ("smpc", "oreg13", "output reg 13"),
    0x2010003D: ("smpc", "oreg14", "output reg 14"),
    0x2010003F: ("smpc", "oreg15", "output reg 15"),
    0x20100041: ("smpc", "oreg16", "output reg 16"),
    0x20100043: ("smpc", "oreg17", "output reg 17"),
    0x20100045: ("smpc", "oreg18", "output reg 18"),
    0x20100047: ("smpc", "oreg19", "output reg 19"),
    0x20100049: ("smpc", "oreg20", "output reg 20"),
    0x2010004B: ("smpc", "oreg21", "output reg 21"),
    0x2010004D: ("smpc", "oreg22", "output reg 22"),
    0x2010004F: ("smpc", "oreg23", "output reg 23"),
    0x20100051: ("smpc", "oreg24", "output reg 24"),
    0x20100053: ("smpc", "oreg25", "output reg 25"),
    0x20100055: ("smpc", "oreg26", "output reg 26"),
    0x20100057: ("smpc", "oreg27", "output reg 27"),
    0x20100059: ("smpc", "oreg28", "output reg 28"),
    0x2010005B: ("smpc", "oreg29", "output reg 29"),
    0x2010005D: ("smpc", "oreg30", "output reg 30"),
    0x2010005F: ("smpc", "oreg31", "output reg 31"),
    0x20100061: ("smpc", "sr", "status register"),
    0x20100063: ("smpc", "sf", "status flag"),
    0x20100075: ("smpc", "pdr1", "port data 1"),
    0x20100077: ("smpc", "pdr2", "port data 2"),
    0x20100079: ("smpc", "ddr1", "port dir 1"),
    0x2010007B: ("smpc", "ddr2", "port dir 2"),
    0x2010007D: ("smpc", "iosel", "port mode select"),

    # SH-2 on-chip peripherals
    0xFFFFFF00: ("divu", "dvsr", "divisor"),
    0xFFFFFF04: ("divu", "dvdnt", "dividend (32-bit)"),
    0xFFFFFF08: ("divu", "dvcr", "div control"),
    0xFFFFFF0C: ("divu", "vcrdiv", "div vector"),
    0xFFFFFF10: ("divu", "dvdnth", "dividend high"),
    0xFFFFFF14: ("divu", "dvdntl", "dividend low"),
    0xFFFFFF18: ("divu", "dvdnths", "dividend high shadow"),
    0xFFFFFF1C: ("divu", "dvdntls", "dividend low shadow"),
    0xFFFFFE92: ("cache", "ccr", "cache control"),
    0xFFFFFE10: ("frt", "tier", "timer int enable"),
    0xFFFFFE11: ("frt", "ftcsr", "timer control/status"),
    0xFFFFFE12: ("frt", "frch", "free-run counter H"),
    0xFFFFFE13: ("frt", "frcl", "free-run counter L"),
    0xFFFFFE14: ("frt", "ocrah", "output compare A H"),
    0xFFFFFE15: ("frt", "ocral", "output compare A L"),
    0xFFFFFE16: ("frt", "ocrbh", "output compare B H"),
    0xFFFFFE17: ("frt", "ocrbl", "output compare B L"),
    0xFFFFFE18: ("frt", "tcrh", "timer control H"),
    0xFFFFFE19: ("frt", "tcrl", "timer control L"),
    0xFFFFFEE0: ("intc", "icr", "interrupt control"),
    0xFFFFFEE2: ("intc", "ipra", "int priority A"),
    0xFFFFFEE4: ("intc", "iprb", "int priority B"),
    0xFFFFFE00: ("sci", "smr", "serial mode"),
    0xFFFFFE01: ("sci", "brr", "bit rate"),
    0xFFFFFE02: ("sci", "scr", "serial control"),
    0xFFFFFE03: ("sci", "tdr", "transmit data"),
    0xFFFFFE04: ("sci", "ssr", "serial status"),
    0xFFFFFE05: ("sci", "rdr", "receive data"),
    0xFFFFFF80: ("dmac", "sar0", "DMA ch0 src"),
    0xFFFFFF84: ("dmac", "dar0", "DMA ch0 dst"),
    0xFFFFFF88: ("dmac", "tcr0", "DMA ch0 count"),
    0xFFFFFF8C: ("dmac", "chcr0", "DMA ch0 control"),
    0xFFFFFF90: ("dmac", "sar1", "DMA ch1 src"),
    0xFFFFFF94: ("dmac", "dar1", "DMA ch1 dst"),
    0xFFFFFF98: ("dmac", "tcr1", "DMA ch1 count"),
    0xFFFFFF9C: ("dmac", "chcr1", "DMA ch1 control"),
    0xFFFFFFB0: ("dmac", "dmaor", "DMA operation"),

    # SCSP common registers
    0x25B00400: ("scsp", "mem4mb_dac", "SCSP mem/DAC config"),
    0x25B00402: ("scsp", "rbl_rbp", "ring buffer size/ptr"),
    0x25B00408: ("scsp", "mslc", "monitor slot"),
    0x25B00412: ("scsp", "dmeal", "DMA exec addr L"),
    0x25B00414: ("scsp", "dmeah", "DMA exec addr H"),
    0x25B00416: ("scsp", "drga", "DMA reg addr"),
    0x25B00418: ("scsp", "dtlg", "DMA transfer len"),
    0x25B0041A: ("scsp", "scipd", "SH-2->68K int pending"),
    0x25B0041C: ("scsp", "scire", "SH-2->68K int reset"),
    0x25B0041E: ("scsp", "scieb", "SH-2->68K int enable"),
    0x25B00420: ("scsp", "mcipd", "68K->SH-2 int pending"),
    0x25B00422: ("scsp", "mcire", "68K->SH-2 int reset"),
    0x25B00424: ("scsp", "mcieb", "68K->SH-2 int enable"),

    # MINIT/SINIT (master/slave init comm)
    0x21000000: ("sys", "minit", "master init (CT)"),
    0x01000000: ("sys", "minit_nc", "master init"),
    0x21800000: ("sys", "sinit", "slave init (CT)"),
    0x01800000: ("sys", "sinit_nc", "slave init"),
}

# Memory ranges for less-specific classification
MEMORY_RANGES = [
    (0x25C00000, 0x25C7FFFF, "vdp1_vram", "VDP1 VRAM"),
    (0x05C00000, 0x05C7FFFF, "vdp1_vram_nc", "VDP1 VRAM (non-CT)"),
    (0x25C80000, 0x25CBFFFF, "vdp1_fb", "VDP1 framebuffer"),
    (0x05C80000, 0x05CBFFFF, "vdp1_fb_nc", "VDP1 framebuffer (non-CT)"),
    (0x25E00000, 0x25E7FFFF, "vdp2_vram", "VDP2 VRAM"),
    (0x05E00000, 0x05E7FFFF, "vdp2_vram_nc", "VDP2 VRAM (non-CT)"),
    (0x25F00000, 0x25F00FFF, "vdp2_cram", "VDP2 Color RAM"),
    (0x05F00000, 0x05F00FFF, "vdp2_cram_nc", "VDP2 Color RAM (non-CT)"),
    (0x25A00000, 0x25A7FFFF, "sound_ram", "Sound RAM"),
    (0x05A00000, 0x05A7FFFF, "sound_ram_nc", "Sound RAM (non-CT)"),
    (0x25B00000, 0x25B003FF, "scsp_slot", "SCSP slot"),
    (0x05B00000, 0x05B003FF, "scsp_slot_nc", "SCSP slot (non-CT)"),
    (0x00200000, 0x002FFFFF, "wram_low", "Work RAM Low"),
    # Boot ROM (0x00000000-0x0007FFFF) excluded -- too many false positives
    # with small integer constants. Game code rarely references ROM directly.
    (0x00180000, 0x0018FFFF, "backup_ram", "Backup RAM"),
    (0x02000000, 0x03FFFFFF, "cart_cs0", "Cartridge CS0"),
    (0x04000000, 0x04FFFFFF, "cart_cs1", "Cartridge CS1"),
    (0x05800000, 0x058FFFFF, "cd_block", "CD Block"),
]

# Well-known fixed-point and math constants
KNOWN_CONSTANTS = {
    0x00010000: ("fp_one", "1.0 in 16.16 fixed-point"),
    0x00008000: ("fp_half", "0.5 in 16.16 fixed-point"),
    0x00020000: ("fp_two", "2.0 in 16.16 fixed-point"),
    0x00030000: ("fp_three", "3.0 in 16.16 fixed-point"),
    0x00040000: ("fp_four", "4.0 in 16.16 fixed-point"),
    0x00080000: ("fp_eight", "8.0 in 16.16 fixed-point"),
    0x00100000: ("fp_sixteen", "16.0 in 16.16 fixed-point"),
    0x7FFFFFFF: ("max_s32", "max signed 32-bit"),
    0x80000000: ("min_s32", "min signed 32-bit / sign bit"),
    0xFFFFFFFF: ("neg_one", "-1 (all bits set)"),
    0xFFFF0000: ("fp_neg_one", "-1.0 in 16.16 fixed-point"),
    0xFFFF8000: ("fp_neg_half", "-0.5 in 16.16 fixed-point"),
    0xFFFE0000: ("fp_neg_two", "-2.0 in 16.16 fixed-point"),
    0x00000000: ("zero", "zero"),
    0x0000FFFF: ("mask_16bit", "16-bit mask"),
    0x000000FF: ("mask_8bit", "8-bit mask"),
    0x0000FF00: ("mask_high_byte", "high byte mask"),
    0xFF000000: ("mask_top_byte", "top byte mask"),
    0x00FF0000: ("mask_byte2", "byte 2 mask"),
    0xFFFF0000: ("mask_upper_word", "upper word mask"),  # also fp_neg_one
    0x0000000F: ("mask_nibble", "nibble mask"),
    0x000F0000: ("mask_nibble_16", "nibble at bit 16"),
    0x00F00000: ("mask_nibble_20", "nibble at bit 20"),
    0x0F000000: ("mask_nibble_24", "nibble at bit 24"),
    0xF0000000: ("mask_nibble_28", "nibble at bit 28"),
    0x00004000: ("quarter_turn", "90 deg (16-bit angle)"),
    0x0000C000: ("three_quarter", "270 deg (16-bit angle)"),
    0x00003FFC: ("trig_table_mask", "4096-entry table mask"),
}

# 16-bit known constants (for .L_wpool_ entries)
KNOWN_CONSTANTS_16 = {
    0x0000: ("zero_w", "zero"),
    0x0001: ("one_w", "1"),
    0x4000: ("quarter_turn_w", "90 deg"),
    0x8000: ("half_turn_w", "180 deg / sign bit"),
    0xC000: ("three_quarter_w", "270 deg"),
    0xFFFF: ("neg_one_w", "-1 (16-bit)"),
    0x00FF: ("mask_byte_w", "byte mask"),
    0xFF00: ("mask_high_byte_w", "high byte mask"),
    0x001F: ("mask_5bit_w", "5-bit mask"),
}


def classify_value(val, is_word=False):
    """Classify a pool value. Returns (name, description, confidence) or None."""
    if is_word:
        if val in KNOWN_CONSTANTS_16:
            name, desc = KNOWN_CONSTANTS_16[val]
            return (name, desc, "HIGH")
        if val > 0 and val <= 0xFFFF:
            # Powers of 2 -- medium confidence
            if val & (val - 1) == 0:
                bit = val.bit_length() - 1
                return (f"bit_{bit}_w", f"1 << {bit} (16-bit)", "MEDIUM")
            # Known struct strides as 16-bit
            if val == 0x0268:
                return ("vehicle_stride_w", "vehicle struct stride 0x268", "MEDIUM")
            # Negative 16-bit (sign-extended: 0xF000+)
            if val >= 0xF000:
                neg = 0x10000 - val
                return (f"neg_{neg}_w", f"-{neg} (16-bit)", "MEDIUM")
            # Inverted bit masks (16-bit): e.g., 0xFEFF = ~0x0100
            if val >= 0xFE00:
                inv = (~val) & 0xFFFF
                if inv > 0 and inv & (inv - 1) == 0:
                    bit = inv.bit_length() - 1
                    return (f"not_bit_{bit}_w", f"~(1 << {bit}) (16-bit)", "MEDIUM")
            # Aligned masks (e.g., 0x0F00, 0xFF00, 0xF000)
            if val >= 0x0100 and val & 0x00FF == 0:
                return (f"mask_0x{val:04x}_w", f"mask 0x{val:X} (16-bit)", "MEDIUM")
            # All remaining: descriptive LOW names
            if val <= 0x400:
                return (f"const_0x{val:03x}_w", f"constant 0x{val:X} ({val})", "LOW")
            return (f"const_0x{val:04x}_w", f"constant 0x{val:X} ({val})", "LOW")
        return None

    # Exact hardware register match
    if val in HW_REGISTERS:
        dev, reg, desc = HW_REGISTERS[val]
        return (f"{dev}_{reg}", f"{dev.upper()} {reg.upper()} -- {desc}", "EXACT")

    # Known constants
    if val in KNOWN_CONSTANTS:
        name, desc = KNOWN_CONSTANTS[val]
        return (name, desc, "HIGH")

    # Memory range match
    for start, end, prefix, desc in MEMORY_RANGES:
        if start <= val <= end:
            offset = val - start
            return (f"{prefix}_{offset:05x}", f"{desc} + 0x{offset:X}", "MEDIUM")

    # DMA address increment patterns
    if val == 0x00000101:
        return ("dma_addr_inc_4_4", "DMA: src+4, dst+4", "HIGH")
    if val == 0x00000100:
        return ("dma_addr_inc_4_0", "DMA: src+4, dst+0", "HIGH")
    if val == 0x00000007:
        return ("dma_direct_imm", "DMA: direct mode, immediate start", "MEDIUM")

    # Cache-through mirror offset
    if val == 0x20000000:
        return ("cache_through_offset", "cache-through mirror offset", "HIGH")

    # Common game constants and masks
    if val == 0x00FFFFFF:
        return ("mask_24bit", "24-bit mask", "HIGH")
    if val == 0x000FFFFF:
        return ("mask_20bit", "20-bit mask", "HIGH")
    if val == 0x0007FFFF:
        return ("mask_19bit", "19-bit mask", "HIGH")
    if val == 0x40000000:
        return ("bit_30", "1 << 30", "MEDIUM")
    if val == 0x00000268:
        return ("vehicle_stride", "vehicle struct stride 0x268 (616 bytes)", "MEDIUM")
    if val == 0x00000228:
        return ("struct_stride_228", "struct stride 0x228 (552 bytes)", "MEDIUM")
    if val == 0x00000348:
        return ("struct_stride_348", "struct stride 0x348 (840 bytes)", "MEDIUM")

    # Inverted bitmasks (0xFFFFxxxx where low bits are ~mask)
    if 0xFFFF0000 <= val < 0xFFFFFF00 and val not in KNOWN_CONSTANTS:
        inv = (~val) & 0xFFFF
        if inv > 0 and inv & (inv - 1) == 0:
            bit = inv.bit_length() - 1
            return (f"not_bit_{bit}", f"~(1 << {bit}) bitmask", "MEDIUM")
        if inv > 0 and inv <= 0x1FFF:
            return (f"not_0x{inv:04x}", f"~0x{inv:X} bitmask", "MEDIUM")

    # Small negative integers (0xFFFFFF00 - 0xFFFFFFFE)
    if 0xFFFFFF00 <= val <= 0xFFFFFFFE:
        neg = 0x100000000 - val
        return (f"neg_{neg}", f"-{neg}", "MEDIUM")
    # Negative fixed-point: covers -1.0 to -32768.0 (0x80000000 - 0xFFFEFFFF)
    if 0x80000000 <= val <= 0xFFFEFFFF:
        neg = 0x100000000 - val
        whole = neg >> 16
        frac = neg & 0xFFFF
        if frac == 0:
            return (f"fp_neg_{whole}", f"-{whole}.0 in 16.16 FP", "MEDIUM")
        else:
            return (f"fp_neg_{whole}_{frac:04x}", f"-{whole}.{frac/65536.0:.4f} in 16.16 FP", "MEDIUM")

    # Positive fixed-point (0x0001xxxx to 0x7FFFxxxx -- values 1.0 to 32767.x)
    if 0x00010000 <= val <= 0x7FFFFFFF and val not in KNOWN_CONSTANTS:
        whole = val >> 16
        frac = val & 0xFFFF
        if frac == 0:
            return (f"fp_{whole}", f"{whole}.0 in 16.16 FP", "MEDIUM")
        else:
            return (f"fp_{whole}_{frac:04x}", f"{whole}.{frac/65536.0:.4f} in 16.16 FP", "MEDIUM")

    # Small constants that look like struct offsets (4-byte aligned, <= 0x1000)
    if 0 < val <= 0x1000 and val % 4 == 0:
        return (f"offset_0x{val:03x}", f"offset/size 0x{val:X} ({val})", "LOW")

    # Small non-aligned constants (likely byte offsets or counts)
    if 0 < val <= 0x1000 and val % 4 != 0:
        return (f"const_0x{val:03x}", f"constant 0x{val:X} ({val})", "LOW")

    # Larger constants (0x1001 - 0xFFFF) -- probably buffer sizes or counts
    if 0x1001 <= val <= 0xFFFF:
        return (f"const_0x{val:04x}", f"constant 0x{val:X} ({val})", "LOW")

    # Powers of 2 (larger)
    if val > 0 and val & (val - 1) == 0 and val <= 0x40000000:
        bit = val.bit_length() - 1
        return (f"bit_{bit}", f"1 << {bit}", "MEDIUM")

    # Multi-bit aligned masks (e.g., 0xF000, 0xE000, 0x9000)
    if 0x1000 <= val <= 0xFFFF and val & 0x0FFF == 0:
        return (f"mask_0x{val:04x}", f"mask 0x{val:X}", "MEDIUM")

    # VDP1 command word patterns (top byte 0xAE/0xAB = display list params)
    if val >= 0x80000000 and (val >> 24) in (0xAE, 0xAB, 0xAC, 0xAD):
        return (f"vdp1_cmd_{val:08x}", f"VDP1 display command word", "MEDIUM")

    # CD block (CS2) addresses
    if 0x25800000 <= val <= 0x258FFFFF:
        offset = val - 0x25800000
        return (f"cd_block_{offset:05x}", f"CD Block + 0x{offset:X}", "MEDIUM")

    # Remaining small constants — give descriptive names at LOW
    return None


def scan_file(filepath):
    """Scan a single .s file for machine-generated pool labels.
    Returns list of (line_idx, old_label, value, classification)."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    results = []
    pool_re = re.compile(r'^(\.L_(?:w)?pool_[0-9A-Fa-f]+):')

    for i, line in enumerate(lines):
        m = pool_re.match(line.strip())
        if not m:
            continue
        old_label = m.group(1)
        is_word = 'wpool' in old_label

        # Read next non-empty line for the value
        val_line = None
        for j in range(i + 1, min(i + 3, len(lines))):
            stripped = lines[j].strip()
            if stripped and not stripped.startswith('/*'):
                val_line = stripped
                break
        if not val_line:
            continue

        # Parse value
        val_match = re.search(r'\.(4byte|2byte|word|long)\s+(0x[0-9A-Fa-f]+|[0-9]+)', val_line)
        if not val_match:
            # Could be a symbol reference -- skip
            continue

        val_str = val_match.group(2)
        try:
            val = int(val_str, 0)
        except ValueError:
            continue

        classification = classify_value(val, is_word)
        results.append((i, old_label, val, classification, is_word))

    return results, lines


def apply_renames(filepath, results, lines):
    """Apply renames to a file. Handles duplicate names with _2, _3, etc.
    Results should already be filtered by caller to desired confidence level."""
    # Build rename map: old_label -> new_label
    name_counts = Counter()
    renames = {}

    for line_idx, old_label, val, classification, is_word in results:
        if classification is None:
            continue
        name, desc, confidence = classification

        # Handle duplicates within this file
        base_name = f".L_{name}"
        name_counts[base_name] += 1
        count = name_counts[base_name]
        if count == 1:
            new_label = base_name
        else:
            new_label = f"{base_name}_{count}"

        renames[old_label] = (new_label, desc)

    if not renames:
        return 0

    # Apply all renames to the file content
    content = ''.join(lines)
    for old_label, (new_label, desc) in renames.items():
        content = content.replace(old_label, new_label)

    with open(filepath, 'w', encoding='utf-8', newline='\n') as f:
        f.write(content)

    return len(renames)


def main():
    parser = argparse.ArgumentParser(description='Classify and rename pool labels')
    parser.add_argument('--apply', action='store_true', help='Apply renames')
    parser.add_argument('--detail', action='store_true', help='Show every rename')
    parser.add_argument('--file', help='Process single file')
    parser.add_argument('--min-confidence', default='MEDIUM',
                        choices=['LOW', 'MEDIUM', 'HIGH', 'EXACT'],
                        help='Minimum confidence for rename (default: MEDIUM)')
    args = parser.parse_args()

    conf_order = ['LOW', 'MEDIUM', 'HIGH', 'EXACT']
    min_conf_idx = conf_order.index(args.min_confidence)

    src_dir = os.path.join(os.path.dirname(__file__), '..', 'reimpl', 'src')
    src_dir = os.path.normpath(src_dir)

    if args.file:
        if os.path.isabs(args.file):
            files = [args.file]
        else:
            files = [os.path.join(src_dir, args.file)]
    else:
        files = sorted([os.path.join(src_dir, f)
                       for f in os.listdir(src_dir)
                       if f.endswith('.s')])

    total_labels = 0
    classified = Counter()  # confidence -> count
    unclassified = 0
    renamed_total = 0
    by_device = Counter()
    files_touched = 0
    unclass_values = Counter()  # value -> count (for analysis)

    for filepath in files:
        results, lines = scan_file(filepath)
        if not results:
            continue

        fname = os.path.basename(filepath)
        file_renamed = 0

        for line_idx, old_label, val, classification, is_word in results:
            total_labels += 1
            if classification is None:
                unclassified += 1
                unclass_values[val] += 1
                if args.detail:
                    print(f"  {fname}:{line_idx+1}  {old_label}  0x{val:08X}  UNCLASSIFIED")
            else:
                name, desc, confidence = classification
                classified[confidence] += 1
                # Track device category
                if '_' in name:
                    dev = name.split('_')[0]
                    by_device[dev] += 1

                conf_idx = conf_order.index(confidence)
                if conf_idx >= min_conf_idx:
                    file_renamed += 1
                    if args.detail:
                        print(f"  {fname}:{line_idx+1}  {old_label} -> .L_{name}  [{confidence}]  {desc}")

        if args.apply and file_renamed > 0:
            # Filter results to only include entries at or above min confidence
            filtered = [(i, ol, v, c, w) for i, ol, v, c, w in results
                       if c is not None and conf_order.index(c[2]) >= min_conf_idx]
            n = apply_renames(filepath, filtered, lines)
            renamed_total += n
            files_touched += 1
            print(f"  {fname}: {n} labels renamed")

    # Summary
    print(f"\n{'='*60}")
    print(f"Pool Label Classification Summary")
    print(f"{'='*60}")
    print(f"Total machine pool labels:  {total_labels}")
    print(f"Classified:                 {sum(classified.values())}")
    for conf in reversed(conf_order):
        if classified[conf]:
            print(f"  {conf:8s}: {classified[conf]}")
    print(f"Unclassified:               {unclassified}")
    print()
    print(f"By device/category:")
    for dev, count in by_device.most_common(20):
        print(f"  {dev:20s}: {count}")

    if args.apply:
        print(f"\nApplied: {renamed_total} renames across {files_touched} files")
    else:
        renameable = sum(v for k, v in classified.items()
                        if conf_order.index(k) >= min_conf_idx)
        print(f"\nRenameable (>= {args.min_confidence}): {renameable}")
        print(f"Run with --apply to rename them.")

    if unclass_values and not args.apply:
        print(f"\nTop 20 unclassified values:")
        for val, count in unclass_values.most_common(20):
            print(f"  0x{val:08X}  ({count} occurrences)")


if __name__ == '__main__':
    main()
