#!/usr/bin/env python3
"""Automated pool label classifier for Saturn SH-2 assembly.

Scans reimpl/src/*.s files for .L_pool_ and .L_wpool_ labels with literal
.4byte/.2byte values, classifies them using Saturn hardware register maps
and pattern heuristics, renames labels to semantic names, and adds inline
comments.

Usage:
    python tools/classify_pool.py              # dry-run (show renames)
    python tools/classify_pool.py --apply      # apply renames in-place
    python tools/classify_pool.py --stats      # show classification stats
"""

import argparse
import os
import re
import sys
from collections import defaultdict
from pathlib import Path

# ---------------------------------------------------------------------------
# Saturn Hardware Register Maps
# ---------------------------------------------------------------------------

# VDP1 registers (base 0x25D00000, also accessible at 0x05D00000)
VDP1_REGS = {
    0x25D00000: ("vdp1_tvmr", "VDP1 TVMR — TV mode"),
    0x25D00002: ("vdp1_fbcr", "VDP1 FBCR — framebuffer control"),
    0x25D00004: ("vdp1_ptmr", "VDP1 PTMR — plot trigger"),
    0x25D00006: ("vdp1_ewdr", "VDP1 EWDR — erase fill color"),
    0x25D00008: ("vdp1_ewlr", "VDP1 EWLR — erase upper-left"),
    0x25D0000A: ("vdp1_ewrr", "VDP1 EWRR — erase lower-right"),
    0x25D0000C: ("vdp1_endr", "VDP1 ENDR — force draw end"),
    0x25D00010: ("vdp1_edsr", "VDP1 EDSR — draw end status"),
    0x25D00012: ("vdp1_lopr", "VDP1 LOPR — last cmd addr"),
    0x25D00014: ("vdp1_copr", "VDP1 COPR — current cmd addr"),
    0x25D00016: ("vdp1_modr", "VDP1 MODR — mode readback"),
}

# VDP2 registers (base 0x25F80000, also accessible at 0x05F80000)
VDP2_REGS = {
    0x25F80000: ("vdp2_tvmd", "VDP2 TVMD — TV mode/display enable"),
    0x25F80002: ("vdp2_exten", "VDP2 EXTEN — external signal"),
    0x25F80004: ("vdp2_tvstat", "VDP2 TVSTAT — TV status"),
    0x25F80006: ("vdp2_vrsize", "VDP2 VRSIZE — VRAM size"),
    0x25F80008: ("vdp2_hcnt", "VDP2 HCNT — H counter"),
    0x25F8000A: ("vdp2_vcnt", "VDP2 VCNT — V counter"),
    0x25F8000E: ("vdp2_ramctl", "VDP2 RAMCTL — RAM control"),
    0x25F80010: ("vdp2_cyca0l", "VDP2 CYCA0L — cycle pattern A0 lower"),
    0x25F80012: ("vdp2_cyca0u", "VDP2 CYCA0U — cycle pattern A0 upper"),
    0x25F80014: ("vdp2_cyca1l", "VDP2 CYCA1L — cycle pattern A1 lower"),
    0x25F80016: ("vdp2_cyca1u", "VDP2 CYCA1U — cycle pattern A1 upper"),
    0x25F80018: ("vdp2_cycb0l", "VDP2 CYCB0L — cycle pattern B0 lower"),
    0x25F8001A: ("vdp2_cycb0u", "VDP2 CYCB0U — cycle pattern B0 upper"),
    0x25F8001C: ("vdp2_cycb1l", "VDP2 CYCB1L — cycle pattern B1 lower"),
    0x25F8001E: ("vdp2_cycb1u", "VDP2 CYCB1U — cycle pattern B1 upper"),
    0x25F80020: ("vdp2_bgon", "VDP2 BGON — screen enable"),
    0x25F80022: ("vdp2_mzctl", "VDP2 MZCTL — mosaic control"),
    0x25F80024: ("vdp2_sfsel", "VDP2 SFSEL — special function select"),
    0x25F80026: ("vdp2_sfcode", "VDP2 SFCODE — special function code"),
    0x25F80028: ("vdp2_chctla", "VDP2 CHCTLA — char control A (NBG0/1)"),
    0x25F8002A: ("vdp2_chctlb", "VDP2 CHCTLB — char control B (NBG2/3/RBG0)"),
    0x25F8002C: ("vdp2_bmpna", "VDP2 BMPNA — bitmap palette NBG0/1"),
    0x25F8002E: ("vdp2_bmpnb", "VDP2 BMPNB — bitmap palette RBG0"),
    0x25F80030: ("vdp2_pncn0", "VDP2 PNCN0 — pattern name NBG0"),
    0x25F80032: ("vdp2_pncn1", "VDP2 PNCN1 — pattern name NBG1"),
    0x25F80034: ("vdp2_pncn2", "VDP2 PNCN2 — pattern name NBG2"),
    0x25F80036: ("vdp2_pncn3", "VDP2 PNCN3 — pattern name NBG3"),
    0x25F80038: ("vdp2_pncr", "VDP2 PNCR — pattern name RBG0"),
    0x25F8003A: ("vdp2_plsz", "VDP2 PLSZ — plane size"),
    0x25F8003C: ("vdp2_mpofn", "VDP2 MPOFN — map offset N"),
    0x25F8003E: ("vdp2_mpofr", "VDP2 MPOFR — map offset R"),
    0x25F80070: ("vdp2_scxin0", "VDP2 SCXIN0 — NBG0 H scroll int"),
    0x25F80072: ("vdp2_scxdn0", "VDP2 SCXDN0 — NBG0 H scroll frac"),
    0x25F80074: ("vdp2_scyin0", "VDP2 SCYIN0 — NBG0 V scroll int"),
    0x25F80078: ("vdp2_zmxin0", "VDP2 ZMXIN0 — NBG0 H zoom int"),
    0x25F8007A: ("vdp2_zmxdn0", "VDP2 ZMXDN0 — NBG0 H zoom frac"),
    0x25F8007C: ("vdp2_zmyin0", "VDP2 ZMYIN0 — NBG0 V zoom int"),
    0x25F8007E: ("vdp2_zmydn0", "VDP2 ZMYDN0 — NBG0 V zoom frac"),
    0x25F80080: ("vdp2_scxin1", "VDP2 SCXIN1 — NBG1 H scroll int"),
    0x25F80084: ("vdp2_scyin1", "VDP2 SCYIN1 — NBG1 V scroll int"),
    0x25F80088: ("vdp2_zmxin1", "VDP2 ZMXIN1 — NBG1 H zoom int"),
    0x25F8008C: ("vdp2_zmyin1", "VDP2 ZMYIN1 — NBG1 V zoom int"),
    0x25F80090: ("vdp2_scxn2", "VDP2 SCXN2 — NBG2 H scroll"),
    0x25F80092: ("vdp2_scyn2", "VDP2 SCYN2 — NBG2 V scroll"),
    0x25F80094: ("vdp2_scxn3", "VDP2 SCXN3 — NBG3 H scroll"),
    0x25F80096: ("vdp2_scyn3", "VDP2 SCYN3 — NBG3 V scroll"),
    0x25F80098: ("vdp2_zmctl", "VDP2 ZMCTL — zoom control"),
    0x25F8009A: ("vdp2_scrctl", "VDP2 SCRCTL — scroll control"),
    0x25F800A0: ("vdp2_vcsta", "VDP2 VCSTA — V cell scroll table addr"),
    0x25F800B0: ("vdp2_rpmd", "VDP2 RPMD — rotation parameter mode"),
    0x25F800B2: ("vdp2_rprctl", "VDP2 RPRCTL — rotation param read ctrl"),
    0x25F800B4: ("vdp2_ktctl", "VDP2 KTCTL — coeff table control"),
    0x25F800B6: ("vdp2_ktaof", "VDP2 KTAOF — coeff table addr offset"),
    0x25F800B8: ("vdp2_ovpnra", "VDP2 OVPNRA — over-pattern name A"),
    0x25F800BA: ("vdp2_ovpnrb", "VDP2 OVPNRB — over-pattern name B"),
    0x25F800BC: ("vdp2_rptau", "VDP2 RPTAU — rotation table addr upper"),
    0x25F800BE: ("vdp2_rptal", "VDP2 RPTAL — rotation table addr lower"),
    0x25F800C0: ("vdp2_wpsx0", "VDP2 WPSX0 — window 0 start X"),
    0x25F800C2: ("vdp2_wpsy0", "VDP2 WPSY0 — window 0 start Y"),
    0x25F800C4: ("vdp2_wpex0", "VDP2 WPEX0 — window 0 end X"),
    0x25F800C6: ("vdp2_wpey0", "VDP2 WPEY0 — window 0 end Y"),
    0x25F800C8: ("vdp2_wpsx1", "VDP2 WPSX1 — window 1 start X"),
    0x25F800CA: ("vdp2_wpsy1", "VDP2 WPSY1 — window 1 start Y"),
    0x25F800CC: ("vdp2_wpex1", "VDP2 WPEX1 — window 1 end X"),
    0x25F800CE: ("vdp2_wpey1", "VDP2 WPEY1 — window 1 end Y"),
    0x25F800D0: ("vdp2_wctla", "VDP2 WCTLA — window control A"),
    0x25F800D2: ("vdp2_wctlb", "VDP2 WCTLB — window control B"),
    0x25F800D4: ("vdp2_wctlc", "VDP2 WCTLC — window control C"),
    0x25F800D6: ("vdp2_wctld", "VDP2 WCTLD — window control D"),
    0x25F800D8: ("vdp2_lwta0u", "VDP2 LWTA0U — line window table 0 upper"),
    0x25F800DA: ("vdp2_lwta0l", "VDP2 LWTA0L — line window table 0 lower"),
    0x25F800DC: ("vdp2_lwta1u", "VDP2 LWTA1U — line window table 1 upper"),
    0x25F800DE: ("vdp2_lwta1l", "VDP2 LWTA1L — line window table 1 lower"),
    0x25F800E0: ("vdp2_spctl", "VDP2 SPCTL — sprite control"),
    0x25F800E2: ("vdp2_sdctl", "VDP2 SDCTL — shadow control"),
    0x25F800E4: ("vdp2_craofa", "VDP2 CRAOFA — color RAM offset A"),
    0x25F800E6: ("vdp2_craofb", "VDP2 CRAOFB — color RAM offset B"),
    0x25F800E8: ("vdp2_lnclen", "VDP2 LNCLEN — line color enable"),
    0x25F800EA: ("vdp2_sfprmd", "VDP2 SFPRMD — special priority mode"),
    0x25F800EC: ("vdp2_ccctl", "VDP2 CCCTL — color calc control"),
    0x25F800EE: ("vdp2_sfccmd", "VDP2 SFCCMD — special color calc mode"),
    0x25F800F0: ("vdp2_prisa", "VDP2 PRISA — priority S0/S1"),
    0x25F800F2: ("vdp2_prisb", "VDP2 PRISB — priority S2/S3"),
    0x25F800F4: ("vdp2_prisc", "VDP2 PRISC — priority S4/S5"),
    0x25F800F6: ("vdp2_prisd", "VDP2 PRISD — priority S6/S7"),
    0x25F800F8: ("vdp2_prina", "VDP2 PRINA — priority NBG0/NBG1"),
    0x25F800FA: ("vdp2_prinb", "VDP2 PRINB — priority NBG2/NBG3"),
    0x25F800FC: ("vdp2_prir", "VDP2 PRIR — priority RBG0"),
    0x25F80100: ("vdp2_ccrsa", "VDP2 CCRSA — color calc S0/S1"),
    0x25F80102: ("vdp2_ccrsb", "VDP2 CCRSB — color calc S2/S3"),
    0x25F80104: ("vdp2_ccrsc", "VDP2 CCRSC — color calc S4/S5"),
    0x25F80106: ("vdp2_ccrsd", "VDP2 CCRSD — color calc S6/S7"),
    0x25F80108: ("vdp2_ccrna", "VDP2 CCRNA — color calc NBG0/NBG1"),
    0x25F8010A: ("vdp2_ccrnb", "VDP2 CCRNB — color calc NBG2/NBG3"),
    0x25F8010C: ("vdp2_ccrr", "VDP2 CCRR — color calc RBG0"),
    0x25F8010E: ("vdp2_ccrlb", "VDP2 CCRLB — color calc line/back"),
    0x25F80110: ("vdp2_clofen", "VDP2 CLOFEN — color offset enable"),
    0x25F80112: ("vdp2_clofsl", "VDP2 CLOFSL — color offset select"),
    0x25F80114: ("vdp2_coar", "VDP2 COAR — color offset A red"),
    0x25F80116: ("vdp2_coag", "VDP2 COAG — color offset A green"),
    0x25F80118: ("vdp2_coab", "VDP2 COAB — color offset A blue"),
    0x25F8011A: ("vdp2_cobr", "VDP2 COBR — color offset B red"),
    0x25F8011C: ("vdp2_cobg", "VDP2 COBG — color offset B green"),
    0x25F8011E: ("vdp2_cobe", "VDP2 COBE — color offset B blue"),
}

# SCU registers (base 0x25FE0000)
SCU_REGS = {
    0x25FE0000: ("scu_d0r", "SCU D0R — DMA level 0 read addr"),
    0x25FE0004: ("scu_d0w", "SCU D0W — DMA level 0 write addr"),
    0x25FE0008: ("scu_d0c", "SCU D0C — DMA level 0 byte count"),
    0x25FE000C: ("scu_d0ad", "SCU D0AD — DMA level 0 add value"),
    0x25FE0010: ("scu_d0en", "SCU D0EN — DMA level 0 enable"),
    0x25FE0014: ("scu_d0md", "SCU D0MD — DMA level 0 mode"),
    0x25FE0020: ("scu_d1r", "SCU D1R — DMA level 1 read addr"),
    0x25FE0024: ("scu_d1w", "SCU D1W — DMA level 1 write addr"),
    0x25FE0028: ("scu_d1c", "SCU D1C — DMA level 1 byte count"),
    0x25FE002C: ("scu_d1ad", "SCU D1AD — DMA level 1 add value"),
    0x25FE0030: ("scu_d1en", "SCU D1EN — DMA level 1 enable"),
    0x25FE0034: ("scu_d1md", "SCU D1MD — DMA level 1 mode"),
    0x25FE0040: ("scu_d2r", "SCU D2R — DMA level 2 read addr"),
    0x25FE0044: ("scu_d2w", "SCU D2W — DMA level 2 write addr"),
    0x25FE0048: ("scu_d2c", "SCU D2C — DMA level 2 byte count"),
    0x25FE004C: ("scu_d2ad", "SCU D2AD — DMA level 2 add value"),
    0x25FE0050: ("scu_d2en", "SCU D2EN — DMA level 2 enable"),
    0x25FE0054: ("scu_d2md", "SCU D2MD — DMA level 2 mode"),
    0x25FE0060: ("scu_dstp", "SCU DSTP — DMA force stop"),
    0x25FE007C: ("scu_dsta", "SCU DSTA — DMA status"),
    0x25FE0080: ("scu_ppaf", "SCU PPAF — DSP program control"),
    0x25FE0084: ("scu_ppd", "SCU PPD — DSP program data"),
    0x25FE0088: ("scu_pda", "SCU PDA — DSP data addr"),
    0x25FE008C: ("scu_pdd", "SCU PDD — DSP data"),
    0x25FE0090: ("scu_t0c", "SCU T0C — timer 0 compare"),
    0x25FE0094: ("scu_t1s", "SCU T1S — timer 1 set data"),
    0x25FE0098: ("scu_t1md", "SCU T1MD — timer 1 mode"),
    0x25FE00A0: ("scu_ims", "SCU IMS — interrupt mask set"),
    0x25FE00A4: ("scu_ist", "SCU IST — interrupt status"),
    0x25FE00A8: ("scu_aiack", "SCU AIACK — A-bus int ack"),
    0x25FE00B0: ("scu_asr0", "SCU ASR0 — A-bus timing CS0"),
    0x25FE00B4: ("scu_asr1", "SCU ASR1 — A-bus timing CS1"),
    0x25FE00B8: ("scu_aref", "SCU AREF — A-bus refresh"),
    0x25FE00C4: ("scu_rsel", "SCU RSEL — SDRAM select"),
    0x25FE00C8: ("scu_ver", "SCU VER — version"),
}

# SH-2 on-chip peripheral registers
SH2_REGS = {
    0xFFFFFE00: ("sh2_smr", "SH2 SMR — serial mode"),
    0xFFFFFE01: ("sh2_brr", "SH2 BRR — bit rate"),
    0xFFFFFE02: ("sh2_scr", "SH2 SCR — serial control"),
    0xFFFFFE03: ("sh2_tdr", "SH2 TDR — transmit data"),
    0xFFFFFE04: ("sh2_ssr", "SH2 SSR — serial status"),
    0xFFFFFE05: ("sh2_rdr", "SH2 RDR — receive data"),
    0xFFFFFE10: ("sh2_tier", "SH2 TIER — timer interrupt enable"),
    0xFFFFFE11: ("sh2_ftcsr", "SH2 FTCSR — free-run timer CSR"),
    0xFFFFFE12: ("sh2_frc_h", "SH2 FRC — free-run counter (high)"),
    0xFFFFFE13: ("sh2_frc_l", "SH2 FRC — free-run counter (low)"),
    0xFFFFFE14: ("sh2_ocra_h", "SH2 OCRA — output compare A (high)"),
    0xFFFFFE18: ("sh2_tcr", "SH2 TCR — timer control"),
    0xFFFFFE1A: ("sh2_tocr", "SH2 TOCR — timer output compare ctrl"),
    0xFFFFFE1C: ("sh2_icr_h", "SH2 ICR — input capture (high)"),
    0xFFFFFE60: ("sh2_iprb", "SH2 IPRB — interrupt priority B"),
    0xFFFFFE71: ("sh2_vcra", "SH2 VCRA — vector number A"),
    0xFFFFFE72: ("sh2_vcrb", "SH2 VCRB — vector number B"),
    0xFFFFFE91: ("sh2_bcr1", "SH2 BCR1 — bus control 1"),
    0xFFFFFE92: ("sh2_ccr", "SH2 CCR — cache control"),
    0xFFFFFF00: ("sh2_dvsr", "SH2 DVSR — divisor"),
    0xFFFFFF04: ("sh2_dvdnt", "SH2 DVDNT — dividend (32-bit)"),
    0xFFFFFF08: ("sh2_dvcr", "SH2 DVCR — division control"),
    0xFFFFFF0C: ("sh2_vcrdiv", "SH2 VCRDIV — division vector"),
    0xFFFFFF10: ("sh2_dvdnth", "SH2 DVDNTH — dividend (high 32)"),
    0xFFFFFF14: ("sh2_dvdntl", "SH2 DVDNTL — dividend (low 32)"),
    0xFFFFFF18: ("sh2_dvdnth_s", "SH2 DVDNTH — dividend shadow"),
    0xFFFFFF1C: ("sh2_dvdntl_s", "SH2 DVDNTL — dividend shadow"),
    0xFFFFFF40: ("sh2_bara", "SH2 BARA — break address A"),
    0xFFFFFF44: ("sh2_bamra", "SH2 BAMRA — break mask A"),
    0xFFFFFF48: ("sh2_bbra", "SH2 BBRA — break bus cycle A"),
    0xFFFFFF60: ("sh2_barb", "SH2 BARB — break address B"),
    0xFFFFFF64: ("sh2_bamrb", "SH2 BAMRB — break mask B"),
    0xFFFFFF68: ("sh2_bbrb", "SH2 BBRB — break bus cycle B"),
    0xFFFFFF6C: ("sh2_bdrb", "SH2 BDRB — break data B"),
    0xFFFFFF70: ("sh2_bdmrb", "SH2 BDMRB — break data mask B"),
    0xFFFFFF78: ("sh2_brcr", "SH2 BRCR — break control"),
    0xFFFFFF80: ("sh2_sar0", "SH2 SAR0 — DMA source addr ch0"),
    0xFFFFFF84: ("sh2_dar0", "SH2 DAR0 — DMA dest addr ch0"),
    0xFFFFFF88: ("sh2_tcr0", "SH2 TCR0 — DMA transfer count ch0"),
    0xFFFFFF8C: ("sh2_chcr0", "SH2 CHCR0 — DMA channel control ch0"),
    0xFFFFFF90: ("sh2_sar1", "SH2 SAR1 — DMA source addr ch1"),
    0xFFFFFF94: ("sh2_dar1", "SH2 DAR1 — DMA dest addr ch1"),
    0xFFFFFF98: ("sh2_tcr1", "SH2 TCR1 — DMA transfer count ch1"),
    0xFFFFFF9C: ("sh2_chcr1", "SH2 CHCR1 — DMA channel control ch1"),
    0xFFFFFFA0: ("sh2_vcrdma0", "SH2 VCRDMA0 — DMA vector ch0"),
    0xFFFFFFA8: ("sh2_vcrdma1", "SH2 VCRDMA1 — DMA vector ch1"),
    0xFFFFFFB0: ("sh2_dmaor", "SH2 DMAOR — DMA operation"),
    0xFFFFFEE0: ("sh2_icr", "SH2 ICR — interrupt control"),
    0xFFFFFEE2: ("sh2_ipra", "SH2 IPRA — interrupt priority A"),
    0xFFFFFEE4: ("sh2_iprb_alt", "SH2 IPRB — interrupt priority B"),
}

# Merge all exact hardware register maps
HW_REGS = {}
HW_REGS.update(VDP1_REGS)
HW_REGS.update(VDP2_REGS)
HW_REGS.update(SCU_REGS)
HW_REGS.update(SH2_REGS)

# Memory region bases (for pointer classification)
MEMORY_REGIONS = {
    0x05C00000: ("vdp1_vram", "VDP1 VRAM base"),
    0x05C80000: ("vdp1_fb", "VDP1 framebuffer base"),
    0x05D00000: ("vdp1_regs", "VDP1 register base"),
    0x05E00000: ("vdp2_vram", "VDP2 VRAM base"),
    0x05F00000: ("vdp2_cram", "VDP2 color RAM base"),
    0x05F80000: ("vdp2_regs", "VDP2 register base"),
    0x25C00000: ("vdp1_vram_ct", "VDP1 VRAM (cache-through)"),
    0x25C80000: ("vdp1_fb_ct", "VDP1 framebuffer (cache-through)"),
    0x25E00000: ("vdp2_vram_ct", "VDP2 VRAM (cache-through)"),
    0x25E20000: ("vdp2_vram_a1", "VDP2 VRAM bank A1"),
    0x25E40000: ("vdp2_vram_b0", "VDP2 VRAM bank B0"),
    0x25E60000: ("vdp2_vram_b1", "VDP2 VRAM bank B1"),
    0x25F00000: ("vdp2_cram_ct", "VDP2 color RAM (cache-through)"),
    0x25A00000: ("sound_ram", "Sound RAM base"),
    0x25B00000: ("scsp_regs", "SCSP register base"),
    0x25B00400: ("scsp_common", "SCSP common registers"),
    0x20100001: ("smpc_base", "SMPC register base"),
}

# Fixed-point constant patterns (16.16 format)
FP_CONSTANTS = {
    0x00010000: ("fp_one", "1.0 (16.16 fixed-point)"),
    0x00008000: ("fp_half", "0.5 (16.16 fixed-point)"),
    0x00020000: ("fp_two", "2.0 (16.16 fixed-point)"),
    0x00040000: ("fp_four", "4.0 (16.16 fixed-point)"),
    0x00080000: ("fp_eight", "8.0 (16.16 fixed-point)"),
    0x00100000: ("fp_sixteen", "16.0 (16.16 fixed-point)"),
    0x00200000: ("fp_thirtytwo", "32.0 (16.16 fixed-point)"),
    0x00004000: ("fp_quarter", "0.25 (16.16 fixed-point)"),
    0x00002000: ("fp_eighth", "0.125 (16.16 fixed-point)"),
    0x00001000: ("fp_sixteenth", "0.0625 (16.16 fixed-point)"),
    0xFFFF0000: ("fp_neg_one", "-1.0 (16.16 fixed-point)"),
    0xFFFE0000: ("fp_neg_two", "-2.0 (16.16 fixed-point)"),
    0xFFFF8000: ("fp_neg_half", "-0.5 (16.16 fixed-point)"),
    0x7FFFFFFF: ("fp_max", "max positive 16.16"),
    0x80000000: ("fp_min", "min negative / sign bit"),
    0x40000000: ("fp_0x4000_0000", "0.25 (2.30) or 16384.0 (16.16)"),
}

# Common bit masks
MASKS = {
    0x0000FFFF: ("mask_low16", "low 16-bit mask"),
    0xFFFF0000: None,  # Could be mask or fp — skip, handle in fp
    0x0000FF00: ("mask_byte1", "byte 1 mask"),
    0x000000FF: ("mask_low8", "low 8-bit mask"),
    0x00FFFFFF: ("mask_low24", "low 24-bit mask"),
    0x0000F000: ("mask_nibble3", "nibble 3 mask"),
    0x00000F00: ("mask_nibble2", "nibble 2 mask"),
    0x000F0000: ("mask_nibble4", "nibble 4 mask"),
    0x0000C000: ("mask_0xC000", "bits 15:14 mask"),
    0x0000E000: ("mask_0xE000", "bits 15:13 mask"),
    0x00FF0000: ("mask_byte2", "byte 2 mask"),
    0xFF000000: ("mask_byte3", "byte 3 mask"),
}

# Special system addresses
SYSTEM_ADDRS = {
    0x01000000: ("minit", "MINIT — primary SH-2 init comm"),
    0x01800000: ("sinit", "SINIT — secondary SH-2 init comm"),
    0x00100001: ("smpc_ireg0", "SMPC IREG0"),
    0x0010001F: ("smpc_comreg", "SMPC COMREG"),
    0x20100001: ("smpc_ireg0_ct", "SMPC IREG0 (cache-through)"),
    0x2010001F: ("smpc_comreg_ct", "SMPC COMREG (cache-through)"),
    0x20100021: ("smpc_oreg0", "SMPC OREG0"),
    0x20100061: ("smpc_sr", "SMPC SR — status"),
    0x20100063: ("smpc_sf", "SMPC SF — status flag"),
    0x20100075: ("smpc_pdr1", "SMPC PDR1 — port data 1"),
    0x20100077: ("smpc_pdr2", "SMPC PDR2 — port data 2"),
    0x20100079: ("smpc_ddr1", "SMPC DDR1 — port direction 1"),
    0x2010007B: ("smpc_ddr2", "SMPC DDR2 — port direction 2"),
    0x2010007D: ("smpc_iosel", "SMPC IOSEL — port mode"),
    0x00180000: ("backup_ram", "Backup RAM base"),
    0x00200000: ("wram_low", "Work RAM Low base"),
    0x06000000: ("wram_high", "Work RAM High base"),
}

# SCSP slot register offsets (0x25B00000 + slot*0x20 + offset)
# We'll handle these as a range

# CD block registers (base 0x25890000 area)
CD_REGS = {
    0x25890008: ("cd_hirq", "CD HIRQ — interrupt request"),
    0x2589000C: ("cd_hirq_mask", "CD HIRQ mask"),
    0x25890018: ("cd_cr1", "CD CR1 — command register 1"),
    0x2589001C: ("cd_cr2", "CD CR2 — command register 2"),
    0x25890020: ("cd_cr3", "CD CR3 — command register 3"),
    0x25890024: ("cd_cr4", "CD CR4 — command register 4"),
    0x25890028: ("cd_mpegrgb", "CD MPEG RGB"),
}
HW_REGS.update(CD_REGS)
HW_REGS.update(SYSTEM_ADDRS)


# ---------------------------------------------------------------------------
# Classification engine
# ---------------------------------------------------------------------------

def classify_value(val):
    """Classify a 32-bit pool value. Returns (label_suffix, comment) or None."""

    # 1. Exact hardware register match
    if val in HW_REGS:
        return HW_REGS[val]

    # 2. Exact fixed-point constant
    if val in FP_CONSTANTS:
        return FP_CONSTANTS[val]

    # 3. Exact mask match (skip ones that overlap with fp)
    if val in MASKS and MASKS[val] is not None:
        return MASKS[val]

    # 4. VDP2 register range (0x25F80000-0x25F8011F)
    if 0x25F80000 <= val <= 0x25F8011F:
        off = val - 0x25F80000
        return (f"vdp2_reg_0x{off:03X}", f"VDP2 register +0x{off:03X}")

    # 5. SCU register range (0x25FE0000-0x25FE00CF)
    if 0x25FE0000 <= val <= 0x25FE00CF:
        off = val - 0x25FE0000
        return (f"scu_reg_0x{off:02X}", f"SCU register +0x{off:02X}")

    # 6. VDP1 register range
    if 0x25D00000 <= val <= 0x25D00017:
        off = val - 0x25D00000
        return (f"vdp1_reg_0x{off:02X}", f"VDP1 register +0x{off:02X}")

    # 7. SCSP common register range
    if 0x25B00400 <= val <= 0x25B00BFF:
        off = val - 0x25B00400
        return (f"scsp_reg_0x{off:03X}", f"SCSP common register +0x{off:03X}")

    # 8. SCSP slot registers (32 slots x 0x20 bytes)
    if 0x25B00000 <= val < 0x25B00400:
        slot = (val - 0x25B00000) // 0x20
        off = (val - 0x25B00000) % 0x20
        return (f"scsp_slot{slot}_0x{off:02X}", f"SCSP slot {slot} +0x{off:02X}")

    # 9. Sound RAM pointers
    if 0x25A00000 <= val < 0x25A80000:
        off = val - 0x25A00000
        if 0x700 <= off < 0x800:
            return (f"sound_cmd_0x{off:03X}", f"Sound command area +0x{off-0x700:02X}")
        return (f"sound_ram_0x{off:05X}", f"Sound RAM +0x{off:05X}")

    # 10. VDP1 VRAM pointers (cache-through)
    if 0x25C00000 <= val < 0x25C80000:
        off = val - 0x25C00000
        return (f"vdp1_vram_0x{off:05X}", f"VDP1 VRAM +0x{off:05X}")

    # 11. VDP1 framebuffer pointers
    if 0x25C80000 <= val < 0x25D00000:
        off = val - 0x25C80000
        return (f"vdp1_fb_0x{off:05X}", f"VDP1 framebuffer +0x{off:05X}")

    # 12. VDP2 VRAM pointers (cache-through)
    if 0x25E00000 <= val < 0x25F00000:
        off = val - 0x25E00000
        return (f"vdp2_vram_0x{off:05X}", f"VDP2 VRAM +0x{off:05X}")

    # 13. VDP2 color RAM pointers
    if 0x25F00000 <= val < 0x25F01000:
        off = val - 0x25F00000
        return (f"vdp2_cram_0x{off:03X}", f"VDP2 color RAM +0x{off:03X}")

    # 14. CD block registers
    if 0x25890000 <= val < 0x25898000:
        off = val - 0x25890000
        return (f"cd_reg_0x{off:04X}", f"CD block register +0x{off:04X}")

    # 15. SMPC registers (odd bytes only, 0x20100001-0x2010007F)
    if 0x20100001 <= val <= 0x2010007F and val & 1:
        off = (val - 0x20100001) // 2
        return (f"smpc_reg_{off}", f"SMPC register #{off}")

    # 16. SH-2 on-chip peripherals range
    if 0xFFFFFE00 <= val <= 0xFFFFFFFF:
        off = val - 0xFFFFFE00
        return (f"sh2_periph_0x{off:02X}", f"SH-2 peripheral +0x{off:02X}")

    # 17. Cache-through Work RAM High (0x26000000-0x260FFFFF)
    if 0x26000000 <= val < 0x26100000:
        addr = val - 0x20000000  # convert to cacheable
        return (f"wram_ct_0x{addr:08X}", f"WRAM High cache-through (0x{addr:08X})")

    # Not classified
    return None


def classify_word_value(val):
    """Classify a 16-bit word pool value. Returns (label_suffix, comment) or None."""
    # Common small constants
    if val == 0x0000:
        return ("zero", "0")
    if val == 0x0001:
        return ("one", "1")
    if val == 0xFFFF:
        return ("neg_one_w", "-1 (16-bit)")

    return None


# ---------------------------------------------------------------------------
# File processing
# ---------------------------------------------------------------------------

def process_file(filepath, apply=False):
    """Process a single .s file, classifying and optionally renaming pool labels.

    Returns dict of stats.
    """
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()

    lines = content.split('\n')
    renames = {}  # old_label -> new_label
    comments = {}  # line_idx -> comment to add
    stats = {'total': 0, 'classified': 0, 'hw_reg': 0, 'fp': 0, 'mask': 0,
             'mem_region': 0, 'unclassified': 0}

    # Track label -> line_idx for the label definition, and label -> value
    label_values = {}  # label -> (value, line_idx, is_4byte)

    # First pass: find all pool/wpool labels and their values
    for i, line in enumerate(lines):
        stripped = line.strip()

        # Match pool label definition: .L_pool_XXXXXXXX:
        m = re.match(r'^(\.L_pool_[0-9A-Fa-f]{8})\s*:', stripped)
        if m:
            label = m.group(1)
            # Look ahead for .4byte value
            for j in range(i + 1, min(i + 3, len(lines))):
                vm = re.match(r'\s*\.4byte\s+0x([0-9A-Fa-f]+)', lines[j])
                if vm:
                    val = int(vm.group(1), 16)
                    label_values[label] = (val, i, j, True)
                    break
                # Stop if we hit another label or instruction
                if lines[j].strip() and not lines[j].strip().startswith('/*'):
                    break

        # Match wpool label definition: .L_wpool_XXXXXXXX:
        m = re.match(r'^(\.L_wpool_[0-9A-Fa-f]{8})\s*:', stripped)
        if m:
            label = m.group(1)
            # Look ahead for .2byte value
            for j in range(i + 1, min(i + 3, len(lines))):
                vm = re.match(r'\s*\.2byte\s+0x([0-9A-Fa-f]+)', lines[j])
                if vm:
                    val = int(vm.group(1), 16)
                    label_values[label] = (val, i, j, False)
                    break
                if lines[j].strip() and not lines[j].strip().startswith('/*'):
                    break

    # Second pass: classify and build rename map
    # Track used names per file to handle duplicates
    used_names = set()

    for label, (val, label_line, val_line, is_4byte) in label_values.items():
        stats['total'] += 1

        if is_4byte:
            result = classify_value(val)
        else:
            result = classify_word_value(val)

        if result is None:
            stats['unclassified'] += 1
            continue

        name_suffix, comment = result
        new_label = f".L_{name_suffix}"

        # Handle duplicates — append address suffix
        if new_label in used_names:
            addr = label.split('_')[-1]
            new_label = f".L_{name_suffix}_{addr}"

        # Still duplicate? Skip rename (very rare)
        if new_label in used_names:
            stats['unclassified'] += 1
            continue

        used_names.add(new_label)
        renames[label] = new_label
        comments[val_line] = comment
        stats['classified'] += 1

        # Categorize
        if val in HW_REGS or (0x25000000 <= val <= 0x25FFFFFF) or (0xFFFFFE00 <= val):
            stats['hw_reg'] += 1
        elif val in FP_CONSTANTS:
            stats['fp'] += 1
        elif val in MASKS and MASKS[val] is not None:
            stats['mask'] += 1
        else:
            stats['mem_region'] += 1

    if not apply or not renames:
        return renames, comments, stats

    # Apply renames
    new_content = content
    for old_label, new_label in renames.items():
        # Replace all occurrences (label definitions and references)
        new_content = new_content.replace(old_label, new_label)

    # Add inline comments to .4byte/.2byte lines
    new_lines = new_content.split('\n')
    for line_idx, comment in comments.items():
        line = new_lines[line_idx]
        # Only add comment if there isn't one already
        if '/*' not in line:
            # Pad to column 40 for alignment
            pad = max(1, 40 - len(line))
            new_lines[line_idx] = line + ' ' * pad + f'/* {comment} */'

    new_content = '\n'.join(new_lines)

    with open(filepath, 'w', encoding='utf-8', newline='\n') as f:
        f.write(new_content)

    return renames, comments, stats


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(description='Classify and rename pool labels')
    parser.add_argument('--apply', action='store_true',
                        help='Apply renames in-place (default: dry-run)')
    parser.add_argument('--stats', action='store_true',
                        help='Show summary statistics only')
    parser.add_argument('--file', '-f', help='Process single file')
    parser.add_argument('--verbose', '-v', action='store_true',
                        help='Show each rename')
    args = parser.parse_args()

    src_dir = Path(__file__).resolve().parent.parent / 'reimpl' / 'src'

    if args.file:
        files = [Path(args.file)]
    else:
        files = sorted(src_dir.glob('*.s'))

    total_stats = defaultdict(int)
    total_renames = 0
    files_modified = 0

    for filepath in files:
        renames, comments, stats = process_file(filepath, apply=args.apply)

        for k, v in stats.items():
            total_stats[k] += v

        if renames:
            files_modified += 1
            total_renames += len(renames)

            if args.verbose and not args.stats:
                print(f"\n{filepath.name}: {len(renames)} renames")
                for old, new in sorted(renames.items()):
                    print(f"  {old} -> {new}")

    # Summary
    print(f"\n{'='*60}")
    print(f"POOL CLASSIFICATION SUMMARY")
    print(f"{'='*60}")
    print(f"  Files scanned:       {len(files)}")
    print(f"  Files with renames:  {files_modified}")
    print(f"  Total pool labels:   {total_stats['total']}")
    print(f"  Classified:          {total_stats['classified']} "
          f"({100*total_stats['classified']/max(1,total_stats['total']):.1f}%)")
    print(f"    HW registers:      {total_stats['hw_reg']}")
    print(f"    Fixed-point:       {total_stats['fp']}")
    print(f"    Bit masks:         {total_stats['mask']}")
    print(f"    Memory regions:    {total_stats['mem_region']}")
    print(f"  Unclassified:        {total_stats['unclassified']}")
    print(f"  Total renames:       {total_renames}")

    if not args.apply and total_renames > 0:
        print(f"\nDRY RUN — use --apply to rename in-place")


if __name__ == '__main__':
    main()
