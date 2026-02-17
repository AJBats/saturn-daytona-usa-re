#include "game.h"

extern int DAT_06026336;
extern int DAT_060263c2;
extern int DAT_06026462;
extern int DAT_060264ee;
extern int DAT_06026728;
extern int DAT_0602672a;
extern int DAT_0602672c;
extern int DAT_0602672e;
extern int DAT_06026848;
extern int DAT_0602684a;
extern int DAT_060268a6;
extern int DAT_06026922;
extern int DAT_06027d26;
extern int DAT_06027de2;
extern int DAT_06027e18;
extern int DAT_06027e98;
extern int DAT_06027e9a;
extern int DAT_06027f56;
extern int DAT_0602805c;
extern unsigned int FUN_06026362();
extern unsigned int FUN_0602648e();
extern void FUN_06026ca4(int param_1, short param_2);
extern void math_sin_cos();
extern int PTR_DAT_06026668;
extern int PTR_DAT_0602684c;
extern int PTR_DAT_06026cd4;
extern int PTR_DAT_06027da0;
extern int PTR_DAT_06027fc0;
extern int PTR_DAT_06027ffc;
extern int PTR_DAT_0602802c;
extern short DAT_06026576;
extern short DAT_06026578;

/* input_peripheral_init -- Initialize SMPC peripheral data on first call.
 * On first invocation (0x06060D78==0): clears 14 input descriptor pairs
 * at 0x060610BC, then scans primary peripheral table (0x06060D7C) for
 * connected devices. If found, calls 0x06025070 for primary setup.
 * Otherwise cross-references descriptor types (0x060610BC +8) against
 * secondary table (0x06060F2C) to populate mappings. Then repeats for
 * auxiliary peripheral table. Sets init flag to prevent re-entry. */
unsigned int FUN_06026110()
{
    short sVar1;
    char *mapped_table  = (int *)0x06060D7C;    /* primary mapped input array */
    char *desc_table    = (char *)0x060610BC;    /* input descriptor array */
    char *aux_table     = (char *)0x0606107C;    /* auxiliary input array */
    char *periph_table  = (int *)0x06060F2C;     /* secondary peripheral table */
    unsigned int result;
    unsigned int i;
    unsigned short slot;

    *(int *)0x06061198 = 0;
    *(int *)0x06061199 = 0;
    result = (unsigned int)*(int *)0x06060D78;

    if (result == 0) {
        *(int *)0x06060D78 = 1;                  /* set init flag */

        /* Clear 14 input descriptor pairs */
        i = 0;
        do {
            unsigned int idx = i & 0xff;
            i = i + 1;
            slot = 0;
            **(short **)(desc_table + (idx * 0xc & 0xff)) = 0;
            **(short **)((int)(desc_table + (idx * 0xc & 0xff)) + 4) = 0;
        } while ((i & 0xffff) < 0xe);

        /* Scan primary mapped inputs for connected device */
        do {
            if (**(short **)(mapped_table + (unsigned int)(slot << 3)) != 0) break;
            slot = slot + 1;
        } while (slot < 0xe);

        if (slot < 0xe) {
            result = (*(int(*)())0x06025070)();  /* primary device found */
        } else {
            /* Cross-reference descriptors against secondary table */
            for (i = 0; (i & 0xffff) < 0xe; i = i + 1) {
                slot = 0;
                do {
                    sVar1 = *(short *)(desc_table + ((i & 0xff) * 0xc & 0xff) + 8);
                    if (*(short *)(periph_table + (unsigned int)(slot << 3) + 6) == sVar1) {
                        sVar1 = *(short *)(periph_table + (unsigned int)(slot << 3) + 4);
                        **(short **)(mapped_table + ((i & 0xffff) << 3)) = sVar1;
                    }
                    result = (unsigned int)sVar1;
                    slot = slot + 1;
                } while (slot < 10);
            }
        }

        /* Scan auxiliary mapped inputs */
        slot = 0;
        do {
            if (**(short **)(mapped_table + (unsigned int)(slot << 3) + 4) != 0) break;
            slot = slot + 1;
        } while (slot < 0xe);

        if (slot < 0xe) {
            result = (*(int(*)())0x06025148)();  /* auxiliary device found */
            return result;
        }

        /* Cross-reference descriptors against auxiliary table */
        for (i = 0; (i & 0xffff) < 0xe; i = i + 1) {
            slot = 0;
            do {
                sVar1 = *(short *)(desc_table + ((i & 0xff) * 0xc & 0xff) + 8);
                if (*(short *)(aux_table + (unsigned int)(slot << 3) + 6) == sVar1) {
                    sVar1 = *(short *)(aux_table + (unsigned int)(slot << 3) + 4);
                    **(short **)(mapped_table + (((i & 0xffff) << 3) + 4)) = sVar1;
                }
                result = (unsigned int)sVar1;
                slot = slot + 1;
            } while (slot < 8);
        }
    }
    return result;
}

/* input_peripheral_scan_exclude -- Scan peripherals excluding one slot.
 * Like input_peripheral_scan but skips the slot matching param_1.
 * Classifies devices into port A (types 0-1) and port B (types 2-3, 8-11).
 * Stores port IDs to 0x06089ED4 (port B) and 0x06089ED6 (port A). */
unsigned int FUN_060262c0(param_1)
    unsigned int param_1;
{
    unsigned short dev_desc;
    char *port_b_id = (char *)0x06089ED4;       /* port B device ID */
    char *port_a_id = (char *)0x06089ED6;       /* port A device ID */
    char *periph_table = (int *)0x06060F2C;     /* peripheral data table */
    unsigned int dev_type;
    short port_flag;
    unsigned short slot;

    *(short *)0x06089ED6 = 0;
    *(short *)port_b_id = 0;
    dev_type = 0;
    slot = 0;

    do {
        if (9 < slot) {
            return dev_type;
        }
        if ((slot == param_1) ||
            (dev_type = (unsigned int)*(unsigned short *)(periph_table + (unsigned int)(slot << 3) + 6) - 0x8a,
             0xb < dev_type))
            goto LAB_06026350;

        dev_desc = ((int *)0x06026338)[dev_type];

        switch(dev_type) {
        case 0:
        case 1:
            port_flag = 1;
            break;
        case 2:
        case 3:
            port_flag = 1;
            goto LAB_0602630a;
        default:
            port_flag = 2;
            break;
        case 8:
        case 9:
        case 10:
        case 0xb:
            port_flag = 2;
LAB_0602630a:
            *(short *)port_b_id = port_flag;
            dev_type = (int)(short)dev_desc;
            goto LAB_06026350;
        }
        *(short *)port_a_id = port_flag;
        dev_type = (int)(short)dev_desc;

LAB_06026350:
        slot = slot + 1;
    } while( 1 );
}

/* input_peripheral_detect -- Detect connected peripherals from secondary table.
 * Scans 10 slots of the secondary peripheral table (0x06060F2C) and
 * classifies by device type (offset +6, minus 0x8A). Stores device flags
 * to port A (0x06060D2A) and port B (0x06060D34). Default flag = 0x8000
 * for unrecognized types. Returns last device descriptor processed. */
#if 0 /* FUN_06026362 -- replaced by ASM import */
unsigned int FUN_06026362()
{
    unsigned short dev_desc;
    char *default_flag = (int *)0x00008000;
    char *port_b_flag  = (char *)0x06060D34;    /* port B device flag */
    char *port_a_flag  = (char *)0x06060D2A;    /* port A device flag */
    char *periph_table = (int *)0x06060F2C;     /* secondary peripheral table */
    unsigned int dev_type;
    short dev_flag;
    unsigned short slot;

    slot = 0;
    do {
        dev_type = (unsigned int)*(unsigned short *)(periph_table + (unsigned int)(slot << 3) + 6) - 0x8a;
        if (0xb < dev_type) goto LAB_060263dc;

        dev_desc = ((int *)0x060263c4)[dev_type];
        dev_flag = SUB42(default_flag, 0);

        switch(dev_type) {
        case 0:
        case 1:
            dev_flag = 0;
            break;
        case 2:
        case 3:
            dev_flag = 0;
            goto LAB_06026394;
        default:
            break;
        case 8:
        case 9:
        case 10:
        case 0xb:
LAB_06026394:
            *(short *)port_b_flag = dev_flag;
            dev_type = (int)(short)dev_desc;
            goto LAB_060263dc;
        }
        *(short *)port_a_flag = dev_flag;
        dev_type = (int)(short)dev_desc;

LAB_060263dc:
        slot = slot + 1;
        if (9 < slot) {
            return dev_type;
        }
    } while( 1 );
}
#endif

/* input_aux_peripheral_scan_exclude -- Scan auxiliary peripherals excluding one slot.
 * Like input_peripheral_scan_exclude but scans 8 auxiliary port slots (0x0606107C).
 * Classifies devices into port A (types 0-1) and port B (types 2-3, 8-11).
 * Stores port IDs to 0x06089ED4 (port B) and 0x06089ED6 (port A).
 * Returns last device descriptor processed. */
unsigned int FUN_060263ec(param_1)
    unsigned int param_1;
{
    unsigned short dev_desc;
    char *port_b_id = (char *)0x06089ED4;       /* port B device ID */
    char *port_a_id = (char *)0x06089ED6;       /* port A device ID */
    char *aux_table = (int *)0x0606107C;         /* auxiliary peripheral table */
    unsigned int dev_type;
    short port_flag;
    unsigned short slot;

    *(short *)0x06089ED6 = 0;
    *(short *)port_b_id = 0;
    dev_type = 0;
    slot = 0;

    do {
        if (7 < slot) {
            return dev_type;
        }
        if ((slot == param_1) ||
            (dev_type = (unsigned int)*(unsigned short *)(aux_table + (unsigned int)(slot << 3) + 6) - 0x8a,
             0xb < dev_type))
            goto LAB_0602647c;

        dev_desc = ((int *)0x06026464)[dev_type];

        switch(dev_type) {
        case 0:
        case 1:
            port_flag = 1;
            break;
        case 2:
        case 3:
            port_flag = 1;
            goto LAB_06026436;
        default:
            port_flag = 2;
            break;
        case 8:
        case 9:
        case 10:
        case 0xb:
            port_flag = 2;
LAB_06026436:
            *(short *)port_b_id = port_flag;
            dev_type = (int)(short)dev_desc;
            goto LAB_0602647c;
        }
        *(short *)port_a_id = port_flag;
        dev_type = (int)(short)dev_desc;

LAB_0602647c:
        slot = slot + 1;
    } while( 1 );
}

/* input_peripheral_scan -- Scan 8 SMPC peripheral slots and classify input devices.
 * Reads device type from peripheral data array (0x0606107C, stride 8, offset +6).
 * Subtracts 0x8A to map to 12 recognized types, looks up device descriptor
 * from table at 0x060264F0. Types 0-1 map to port A, types 2-3 and 8-11 map
 * to port B (0x06060D34), others to port A (0x06060D2A). */
unsigned int FUN_0602648e()
{
    unsigned short dev_desc;
    unsigned int dev_type;
    short dev_flag;
    unsigned short slot;

    slot = 0;
    do {
        dev_type = (unsigned int)*(unsigned short *)(0x0606107C + (unsigned int)(slot << 3) + 6) - 0x8a;
        if (0xb < dev_type) goto LAB_06026508;

        dev_desc = ((int *)0x060264f0)[dev_type];
        dev_flag = (short)0x8000;

        switch(dev_type) {
        case 0:
        case 1:
            dev_flag = 0;
            break;
        case 2:
        case 3:
            dev_flag = 0;
            goto LAB_060264c0;
        default:
            break;
        case 8:
        case 9:
        case 10:
        case 0xb:
LAB_060264c0:
            *(short *)0x06060D34 = dev_flag;   /* port B device flag */
            dev_type = (int)(short)dev_desc;
            goto LAB_06026508;
        }
        *(short *)0x06060D2A = dev_flag;        /* port A device flag */
        dev_type = (int)(short)dev_desc;

LAB_06026508:
        slot = slot + 1;
        if (7 < slot) {
            return dev_type;
        }
    } while( 1 );
}

/* hud_speedometer_update -- Update speedometer VDP sprites.
 * If input bit 2 set (right): use static sprite attributes.
 * Otherwise: use dynamic attributes from speed display state. */
/* FUN_06026518 -- original binary (120 bytes) */
__asm__(
    ".section .text.FUN_06026518, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06026518\n"
    ".type _FUN_06026518, @function\n"
    "_FUN_06026518:\n"
    ".byte 0x4F, 0x22, 0x60, 0x4D, 0x7F, 0xFC, 0xC8, 0x04, 0x89, 0x0D, 0xD7, 0x16, 0x96, 0x25, 0x95, 0x25\n"  /* 0x06026518 */
    ".byte 0xD3, 0x15, 0x43, 0x0B, 0xE4, 0x08, 0xD7, 0x13, 0x96, 0x1F, 0x95, 0x20, 0xE4, 0x08, 0x7F, 0x04\n"  /* 0x06026528 */
    ".byte 0xD3, 0x11, 0x43, 0x2B, 0x4F, 0x26, 0xD2, 0x11, 0x2F, 0x22, 0x67, 0x23, 0x65, 0x23, 0x93, 0x17\n"  /* 0x06026538 */
    ".byte 0x96, 0x14, 0x57, 0x71, 0x65, 0x52, 0x37, 0x3C, 0xD3, 0x0D, 0x43, 0x0B, 0xE4, 0x08, 0xD2, 0x0D\n"  /* 0x06026548 */
    ".byte 0x2F, 0x22, 0x67, 0x23, 0x57, 0x71, 0x93, 0x0B, 0x37, 0x3C, 0x96, 0x08, 0x65, 0x23, 0x65, 0x52\n"  /* 0x06026558 */
    ".byte 0xE4, 0x08, 0x7F, 0x04, 0xD3, 0x06, 0x43, 0x2B, 0x4F, 0x26, 0x00, 0x90, 0x02, 0xA0, 0x02, 0xB4\n"  /* 0x06026568 */
    ".byte 0x70, 0x00, 0xFF, 0xFF, 0x06, 0x05, 0x91, 0x28, 0x06, 0x02, 0x84, 0xAE, 0x06, 0x06, 0x3B, 0x80\n"  /* 0x06026578 */
    ".byte 0x06, 0x02, 0x84, 0x00, 0x06, 0x06, 0x3B, 0x88\n"  /* 0x06026588 */
);


/* input_descriptor_table_refresh -- Rebuild input descriptor table for given mode.
 * Clears all input descriptor pairs at 0x060610BC, re-detects connected
 * peripherals (mode 4 calls input_peripheral_detect/scan), then applies
 * bitmask OR from dispatch tables (0x06061170 for primary/10 slots,
 * 0x06061184 for secondary/8 slots). If mode 4, writes back descriptor
 * state for next frame. param_1=mode, param_2=descriptor count. */
#if 0 /* FUN_06026590 -- replaced by ASM import */
void FUN_06026590(param_1, param_2)
    char param_1;
    unsigned int param_2;
{
    short *desc_ptr;
    unsigned short *mask_ptr;
    unsigned int scan_offset;
    int *desc_base = (int *)0x060610BC;     /* input descriptor array */
    int *temp;
    int slot_offset;
    int *desc_end;
    int *cur;
    int desc_size = 0xa8;                   /* descriptor table size */
    int *dispatch;

    if ((param_2 & 0xffff) == desc_size + 1U) {
        /* Primary mode (0xA9 descriptors): clear table */
        desc_end = (int *)(0x060610BC + desc_size);
        cur = (int *)0x060610BC;
        do {
            desc_ptr = (short *)*cur;
            *(short *)cur[1] = 0;
            *desc_ptr = 0;
            desc_ptr = (short *)cur[3];
            temp = cur + 4;
            cur = cur + 6;
            *(short *)*temp = 0;
            *desc_ptr = 0;
        } while (cur < desc_end);

        if (param_1 == '\x04') {
            FUN_06026362();  /* input_peripheral_detect */
        }

        /* Apply bitmask OR from primary dispatch table (10 slots) */
        slot_offset = 0;
        dispatch = (int *)(0x06061170 + (param_1 << 2));
        for (scan_offset = 0; scan_offset < 0x50; scan_offset = scan_offset + 8) {
            if (*(int *)(*dispatch + scan_offset) != 0) {
                cur = (int *)(*dispatch + slot_offset);
                mask_ptr = (unsigned short *)*cur;
                *mask_ptr = *mask_ptr | *(unsigned short *)(cur + 1);
            }
            slot_offset = slot_offset + 8;
        }
    } else {
        /* Secondary mode: clear table */
        desc_end = (int *)(0x060610BC + desc_size);
        cur = (int *)0x060610BC;
        do {
            desc_ptr = (short *)*cur;
            *(short *)cur[1] = 0;
            *desc_ptr = 0;
            desc_ptr = (short *)cur[3];
            temp = cur + 4;
            cur = cur + 6;
            *(short *)*temp = 0;
            *desc_ptr = 0;
        } while (cur < desc_end);

        if (param_1 == '\x04') {
            FUN_0602648e();  /* input_peripheral_scan */
        }

        /* Apply bitmask OR from secondary dispatch table (8 slots) */
        slot_offset = 0;
        dispatch = (int *)(0x06061184 + (param_1 << 2));
        for (scan_offset = 0; scan_offset < 0x40; scan_offset = scan_offset + 8) {
            if (*(int *)(*dispatch + scan_offset) != 0) {
                cur = (int *)(*dispatch + slot_offset);
                mask_ptr = (unsigned short *)*cur;
                *mask_ptr = *mask_ptr | *(unsigned short *)(cur + 1);
            }
            slot_offset = slot_offset + 8;
        }
    }

    /* Mode 4: write back descriptor state for next frame */
    if (param_1 == '\x04') {
        cur = (int *)((int)desc_base + desc_size);
        do {
            temp = desc_base + 3;
            *(short *)*desc_base = *(short *)desc_base[1];
            desc_end = desc_base + 4;
            desc_base = desc_base + 6;
            *(short *)*temp = *(short *)*desc_end;
        } while (desc_base < cur);
    }
}
#endif

/* FUN_06026590 -- original binary (316 bytes) */
__asm__(
    ".section .text.FUN_06026590, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06026590\n"
    ".type _FUN_06026590, @function\n"
    "_FUN_06026590:\n"
    ".byte 0x2F, 0xE6, 0x65, 0x5D, 0x2F, 0xD6, 0xEE, 0x00, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0xEB, 0x50\n"  /* 0x06026590 */
    ".byte 0x2F, 0x96, 0xE9, 0x40, 0x2F, 0x86, 0x4F, 0x22, 0x98, 0x5E, 0xDD, 0x30, 0x63, 0x83, 0x73, 0x01\n"  /* 0x060265A0 */
    ".byte 0x35, 0x30, 0x8F, 0x34, 0x6C, 0x43, 0x64, 0xD3, 0x66, 0xD3, 0x36, 0x8C, 0x65, 0x43, 0x61, 0xED\n"  /* 0x060265B0 */
    ".byte 0x63, 0x42, 0x52, 0x51, 0x74, 0x0C, 0x22, 0xE1, 0x65, 0x43, 0x23, 0xE1, 0x63, 0x42, 0x52, 0x51\n"  /* 0x060265C0 */
    ".byte 0x74, 0x0C, 0x22, 0x11, 0x23, 0x11, 0x34, 0x62, 0x8B, 0xF0, 0x60, 0xCE, 0x88, 0x04, 0x8B, 0x01\n"  /* 0x060265D0 */
    ".byte 0xBE, 0xBF, 0x00, 0x09, 0x65, 0xE3, 0x64, 0xE3, 0x6A, 0xCE, 0x4A, 0x08, 0xD3, 0x20, 0xA0, 0x12\n"  /* 0x060265E0 */
    ".byte 0x3A, 0x3C, 0x63, 0xA2, 0x33, 0x4C, 0x60, 0x32, 0x20, 0x08, 0x8B, 0x01, 0xA0, 0x09, 0x00, 0x09\n"  /* 0x060265F0 */
    ".byte 0x66, 0xA2, 0x36, 0x5C, 0x63, 0x62, 0x85, 0x62, 0x62, 0x03, 0x62, 0x2D, 0x61, 0x31, 0x21, 0x2B\n"  /* 0x06026600 */
    ".byte 0x23, 0x11, 0x75, 0x08, 0x74, 0x08, 0x34, 0xB2, 0x8B, 0xEB, 0xA0, 0x3A, 0x00, 0x09, 0x64, 0xD3\n"  /* 0x06026610 */
    ".byte 0x66, 0xD3, 0x36, 0x8C, 0x65, 0x43, 0x61, 0xED, 0x62, 0x42, 0x53, 0x51, 0x74, 0x0C, 0x23, 0xE1\n"  /* 0x06026620 */
    ".byte 0x65, 0x43, 0x22, 0xE1, 0x63, 0x42, 0x52, 0x51, 0x74, 0x0C, 0x22, 0x11, 0x23, 0x11, 0x34, 0x62\n"  /* 0x06026630 */
    ".byte 0x8B, 0xF0, 0x60, 0xCE, 0x88, 0x04, 0x8B, 0x01, 0xBF, 0x21, 0x00, 0x09, 0x65, 0xE3, 0x64, 0xE3\n"  /* 0x06026640 */
    ".byte 0x6A, 0xCE, 0x4A, 0x08, 0xD3, 0x07, 0xA0, 0x1A, 0x3A, 0x3C, 0x63, 0xA2, 0x33, 0x4C, 0x60, 0x32\n"  /* 0x06026650 */
    ".byte 0x20, 0x08, 0x8B, 0x09, 0xA0, 0x11, 0x00, 0x09, 0x00, 0xA8, 0xFF, 0xFF, 0x06, 0x06, 0x10, 0xBC\n"  /* 0x06026660 */
    ".byte 0x06, 0x06, 0x11, 0x70, 0x06, 0x06, 0x11, 0x84, 0x66, 0xA2, 0x36, 0x5C, 0x63, 0x62, 0x85, 0x62\n"  /* 0x06026670 */
    ".byte 0x62, 0x03, 0x62, 0x2D, 0x61, 0x31, 0x21, 0x2B, 0x23, 0x11, 0x75, 0x08, 0x74, 0x08, 0x34, 0x92\n"  /* 0x06026680 */
    ".byte 0x8B, 0xE3, 0x60, 0xCE, 0x88, 0x04, 0x8B, 0x10, 0x64, 0xD3, 0x66, 0xD3, 0x36, 0x8C, 0x65, 0x43\n"  /* 0x06026690 */
    ".byte 0x62, 0x42, 0x53, 0x51, 0x74, 0x0C, 0x61, 0x31, 0x65, 0x43, 0x22, 0x11, 0x63, 0x42, 0x52, 0x51\n"  /* 0x060266A0 */
    ".byte 0x74, 0x0C, 0x61, 0x21, 0x23, 0x11, 0x34, 0x62, 0x8B, 0xF1, 0x4F, 0x26, 0x68, 0xF6, 0x69, 0xF6\n"  /* 0x060266B0 */
    ".byte 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x060266C0 */
);


/* hud_gear_selector_render -- Render gear/transmission selection HUD.
 * Draws base gear sprites via VDP1 attribute setter (0x060284AE), then
 * dispatches on controller input (0x06063D9A) to cycle through gear
 * selections (range 0x12-0x14 at 0x06089EDA). On confirm (DAT_0602672e
 * or 0x100), sets render mode 6 at 0x06061198 and draws 3 sprites.
 * On D-pad left/right (DAT_0602684a/PTR_0602684c), shifts selection ±2.
 * If display bit 4 set, uses static mode; otherwise dynamic from 0x06063B88. */
#if 0 /* FUN_060266CC -- replaced by ASM import */
int FUN_060266cc()
{
    unsigned short input_state;
    char *sprite_base = (int *)0x06059128;   /* gear sprite data base */
    char *vdp_attr_set = (char *)0x060284AE; /* VDP1 attribute setter */
    char *selection_ptr = (char *)0x06089EDA; /* current gear selection */
    char *render_mode = (int *)0x06061198;   /* render mode output */
    int result;
    int sprite_a = (int)DAT_0602672a;        /* gear sprite A dimensions */
    int sprite_b = (int)DAT_0602672c;        /* gear sprite B dimensions */
    int priority = 0x90;                     /* sprite priority */

    /* Draw base gear indicator sprites */
    (*(int(*)())0x060284AE)(8,sprite_a,priority,0x0605912C);
    (*(int(*)())vdp_attr_set)(8,sprite_b,priority,0x06059134);

    input_state = *(unsigned short *)0x06063D9A;  /* controller input */

    if (input_state != 0) {
        /* Confirm button A (DAT_0602672e bitmask) */
        if ((input_state & DAT_0602672e) != 0) {
            *(unsigned short *)0x06089ED8 = (unsigned short)(*(short *)selection_ptr == 0x12);
            *render_mode = 6;
            (*(int(*)())vdp_attr_set)(8,((unsigned int)*(unsigned short *)((int)(int)selection_ptr << 6) + 0x11) << 1,priority,sprite_base);
            (*(int(*)())vdp_attr_set)(8,sprite_a,priority,0x0605913C);
            result = (*(int(*)())vdp_attr_set)(8,sprite_b,priority,0x06059144);
            return result;
        }
        /* Confirm button B (start = 0x100) */
        if ((unsigned int)input_state == 0x100) {
            *(short *)0x06089ED8 = 0;
            *render_mode = 6;
            (*(int(*)())vdp_attr_set)(8,((unsigned int)*(unsigned short *)((int)(int)selection_ptr << 6) + 0x11) << 1,priority,sprite_base);
            (*(int(*)())vdp_attr_set)(8,sprite_a,priority,0x0605913C);
            result = (*(int(*)())vdp_attr_set)(8,sprite_b,priority,0x06059144);
            return result;
        }
        /* D-pad left: shift selection -2 */
        if ((unsigned int)input_state == (int)DAT_0602684a) {
            (*(int(*)())vdp_attr_set)(8,((unsigned int)*(unsigned short *)((int)(int)selection_ptr << 6) + 0x11) << 1,priority,sprite_base);
            *(short *)selection_ptr = *(short *)selection_ptr + -2;
        }
        /* D-pad right: shift selection +2 */
        if ((unsigned int)input_state == (int)PTR_DAT_0602684c) {
            (*(int(*)())vdp_attr_set)(8,((unsigned int)*(unsigned short *)((int)(int)selection_ptr << 6) + 0x11) << 1,priority,sprite_base);
            *(short *)selection_ptr = *(short *)selection_ptr + 2;
        }
        /* Clamp selection to valid range [0x12, 0x14] */
        if (0x14 < *(unsigned short *)selection_ptr) {
            *(short *)selection_ptr = (char *)0x12;
        }
        if (*(unsigned short *)selection_ptr < 0x12) {
            *(short *)selection_ptr = (char *)0x14;
        }
    }

    /* Static render mode (display bit 4) */
    if ((*(unsigned short *)0x06089EC6 & 4) != 0) {
        result = (*(int(*)())vdp_attr_set)(8,((unsigned int)*(unsigned short *)((int)(int)selection_ptr << 6) + 0x11) << 1,priority,sprite_base);
        return result;
    }

    /* Dynamic render mode: use speed display state */
    result = (*(int(*)())0x06028400)(8,*(int *)0x06063B88,((unsigned int)*(unsigned short *)((int)(int)selection_ptr << 6) + 0x11) << 1,
                       *(int *)(0x06063B88 + 4) + (int)DAT_060268a6);
    return result;
}
#endif

/* FUN_060266CC -- original binary (484 bytes) */
__asm__(
    ".section .text.FUN_060266CC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060266CC\n"
    ".global _FUN_060266cc\n"
    ".type _FUN_060266CC, @function\n"
    "_FUN_060266CC:\n"
    "_FUN_060266cc:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x2F, 0x96, 0x2F, 0x86, 0x4F, 0x22\n"  /* 0x060266CC */
    ".byte 0x7F, 0xFC, 0xDA, 0x14, 0xDC, 0x14, 0x9D, 0x21, 0xDE, 0x14, 0x98, 0x20, 0xD7, 0x14, 0x66, 0xD3\n"  /* 0x060266DC */
    ".byte 0x65, 0x83, 0x4C, 0x0B, 0xE4, 0x08, 0x66, 0xD3, 0x99, 0x1A, 0xD7, 0x12, 0x65, 0x93, 0x4C, 0x0B\n"  /* 0x060266EC */
    ".byte 0xE4, 0x08, 0xDB, 0x11, 0x6B, 0xB1, 0x63, 0xBD, 0x23, 0x38, 0x8B, 0x01, 0xA0, 0x8C, 0x00, 0x09\n"  /* 0x060266FC */
    ".byte 0xD6, 0x0E, 0x63, 0xBD, 0x92, 0x0D, 0xD4, 0x0E, 0x23, 0x29, 0x23, 0x38, 0x8D, 0x34, 0xE5, 0x06\n"  /* 0x0602670C */
    ".byte 0x60, 0xE1, 0x60, 0x0D, 0x88, 0x12, 0x8B, 0x15, 0xA0, 0x15, 0xE3, 0x01, 0x00, 0x90, 0x09, 0x26\n"  /* 0x0602671C */
    ".byte 0x0A, 0x26, 0x0E, 0x00, 0x06, 0x05, 0x91, 0x28, 0x06, 0x02, 0x84, 0xAE, 0x06, 0x08, 0x9E, 0xDA\n"  /* 0x0602672C */
    ".byte 0x06, 0x05, 0x91, 0x2C, 0x06, 0x05, 0x91, 0x34, 0x06, 0x06, 0x3D, 0x9A, 0x06, 0x06, 0x11, 0x98\n"  /* 0x0602673C */
    ".byte 0x06, 0x08, 0x9E, 0xD8, 0xE3, 0x00, 0x67, 0xA3, 0x24, 0x31, 0x26, 0x50, 0x66, 0xD3, 0x65, 0xE1\n"  /* 0x0602674C */
    ".byte 0x65, 0x5D, 0x45, 0x08, 0x45, 0x08, 0x45, 0x08, 0x75, 0x11, 0x45, 0x00, 0x4C, 0x0B, 0xE4, 0x08\n"  /* 0x0602675C */
    ".byte 0xD7, 0x38, 0x66, 0xD3, 0x65, 0x83, 0x4C, 0x0B, 0xE4, 0x08, 0x66, 0xD3, 0x65, 0x93, 0xD7, 0x36\n"  /* 0x0602676C */
    ".byte 0x4C, 0x0B, 0xE4, 0x08, 0xA0, 0x87, 0x00, 0x09, 0x63, 0xBD, 0x92, 0x5F, 0x33, 0x20, 0x8B, 0x19\n"  /* 0x0602677C */
    ".byte 0xE2, 0x00, 0x67, 0xA3, 0x24, 0x21, 0x26, 0x50, 0x66, 0xD3, 0x65, 0xE1, 0x65, 0x5D, 0x45, 0x08\n"  /* 0x0602678C */
    ".byte 0x45, 0x08, 0x45, 0x08, 0x75, 0x11, 0x45, 0x00, 0x4C, 0x0B, 0xE4, 0x08, 0x66, 0xD3, 0x65, 0x83\n"  /* 0x0602679C */
    ".byte 0xD7, 0x28, 0x4C, 0x0B, 0xE4, 0x08, 0xD7, 0x28, 0x66, 0xD3, 0x65, 0x93, 0x4C, 0x0B, 0xE4, 0x08\n"  /* 0x060267AC */
    ".byte 0xA0, 0x69, 0x00, 0x09, 0x63, 0xBD, 0x92, 0x42, 0x33, 0x20, 0x8B, 0x0D, 0x67, 0xA3, 0x66, 0xD3\n"  /* 0x060267BC */
    ".byte 0x65, 0xE1, 0x65, 0x5D, 0x45, 0x08, 0x45, 0x08, 0x45, 0x08, 0x75, 0x11, 0x45, 0x00, 0x4C, 0x0B\n"  /* 0x060267CC */
    ".byte 0xE4, 0x08, 0x63, 0xE1, 0x73, 0xFE, 0x2E, 0x31, 0x6B, 0xBD, 0x92, 0x31, 0x3B, 0x20, 0x8B, 0x0D\n"  /* 0x060267DC */
    ".byte 0x67, 0xA3, 0x66, 0xD3, 0x65, 0xE1, 0x65, 0x5D, 0x45, 0x08, 0x45, 0x08, 0x45, 0x08, 0x75, 0x11\n"  /* 0x060267EC */
    ".byte 0x45, 0x00, 0x4C, 0x0B, 0xE4, 0x08, 0x63, 0xE1, 0x73, 0x02, 0x2E, 0x31, 0x62, 0xE1, 0xE3, 0x14\n"  /* 0x060267FC */
    ".byte 0x62, 0x2D, 0x32, 0x37, 0x8B, 0x01, 0xE3, 0x12, 0x2E, 0x31, 0xE3, 0x12, 0x62, 0xE1, 0x62, 0x2D\n"  /* 0x0602680C */
    ".byte 0x32, 0x33, 0x89, 0x01, 0xE3, 0x14, 0x2E, 0x31, 0xD0, 0x0C, 0x60, 0x01, 0x60, 0x0D, 0xC8, 0x04\n"  /* 0x0602681C */
    ".byte 0x89, 0x16, 0x67, 0xA3, 0x66, 0xD3, 0x65, 0xE1, 0x65, 0x5D, 0x45, 0x08, 0x45, 0x08, 0x45, 0x08\n"  /* 0x0602682C */
    ".byte 0x75, 0x11, 0x45, 0x00, 0x4C, 0x0B, 0xE4, 0x08, 0xA0, 0x25, 0x00, 0x09, 0x01, 0x00, 0x10, 0x00\n"  /* 0x0602683C */
    ".byte 0x20, 0x00, 0xFF, 0xFF, 0x06, 0x05, 0x91, 0x3C, 0x06, 0x05, 0x91, 0x44, 0x06, 0x08, 0x9E, 0xC6\n"  /* 0x0602684C */
    ".byte 0xD2, 0x12, 0x2F, 0x22, 0x67, 0x23, 0x93, 0x20, 0x66, 0xE1, 0x57, 0x71, 0x66, 0x6D, 0x37, 0x3C\n"  /* 0x0602685C */
    ".byte 0x46, 0x08, 0x46, 0x08, 0x46, 0x08, 0x76, 0x11, 0x46, 0x00, 0x65, 0x23, 0x65, 0x52, 0xE4, 0x08\n"  /* 0x0602686C */
    ".byte 0x7F, 0x04, 0x4F, 0x26, 0x68, 0xF6, 0x69, 0xF6, 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6\n"  /* 0x0602687C */
    ".byte 0xD3, 0x07, 0x43, 0x2B, 0x6E, 0xF6, 0x7F, 0x04, 0x4F, 0x26, 0x68, 0xF6, 0x69, 0xF6, 0x6A, 0xF6\n"  /* 0x0602688C */
    ".byte 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x70, 0x00, 0x06, 0x06, 0x3B, 0x88\n"  /* 0x0602689C */
    ".byte 0x06, 0x02, 0x84, 0x00\n"  /* 0x060268AC */
);


/* demo_replay_sequence_update -- advance timed sprite sequence for intro/demo, per car-count variant */
#if 0 /* FUN_060268B0 -- replaced by ASM import */
void FUN_060268b0(param_1)
    short param_1;
{
  char *sprite_render;
  char *frame_counter;
  char *vblank_ref;
  char *trigger_flag;
  char *seq_position;
  int car_count;
  int priority;

  seq_position = (int *)0x06061238;   /* current sequence position */
  frame_counter = (char *)0x0606123A; /* frame within current position */
  vblank_ref = (char *)0x0607864C;    /* vblank reference timestamp */
  trigger_flag = (int *)0x0606123C;   /* new-position trigger */
  sprite_render = (int *)0x060283E0;  /* sprite_render_command function */
  priority = (int)DAT_06026922;

  if (param_1 == 0) {
    car_count = CAR_COUNT;

    if (car_count == 0) {
      /* Single player: 54 sequence positions, timing table at 0x060597B8, frame stride 0x20 */
      if (*(short *)0x06061238 < 0x36) {
        if ((unsigned int)(*(short *)(0x060597B8 + *(short *)(0x06061238 << 1)) * 3) <=
            VBLANK_COUNTER) {
          *(short *)0x06061238 = *(short *)0x06061238 + 1;
          *(short *)frame_counter = 0;
          (*(int(*)())sprite_render)(0xc,priority,0x0000F000,0x06059826); /* clear sprite */
          *(short *)trigger_flag = 1;
        }
      }
      else if ((*(short *)0x06061238 == 0x36) &&
              ((unsigned int)(*(short *)(0x060597B8 + *(short *)(0x06061238 << 1)) * 3) <=
               VBLANK_COUNTER)) {
        (*(int(*)())0x060283E0)(0xc,priority,0x0000F000,0x06059826);
        *(short *)seq_position = 0;
        *(short *)frame_counter = 0;
        *(short *)0x0606123E = 1; /* sequence_complete */
      }
      if (*(short *)trigger_flag != 0) {
        (*(int(*)())sprite_render)(0xc,priority,0x0000F000,
                          *(int *)
                           (0x060611FC + (char)((int *)0x060591BA)[*(short *)seq_position + -1] * 4));
      }
      *(short *)trigger_flag = 0;
      if (0 < *(short *)seq_position) {
        while ((((unsigned int)(((int)*(short *)(0x060597B8 + (*(short *)seq_position + -1) << 1) +
                        (int)((char *)0x060595D8)
                                   [(int)*(short *)frame_counter +
                                    (char)((int *)0x060591BA)[*(short *)seq_position + -1] * 0x20]) * 3) <=
                 *(unsigned int *)vblank_ref &&
                (((char *)0x060595D8)
                       [(int)*(short *)frame_counter + (char)((int *)0x060591BA)[*(short *)seq_position + -1] * 0x20
                       ] != -1)) && (*(short *)frame_counter < 0x20))) {
          FUN_06026ca4(*(int *)
                        (0x060611FC + (char)((int *)0x060591BA)[*(short *)seq_position + -1] * 4),
                       (int)*(short *)frame_counter);
          *(short *)frame_counter = *(short *)frame_counter + 1;
        }
      }
    }

    else if (car_count == 1) {
      /* VS mode: 58 positions, timing at 0x060591F0, frame stride 0x24 */
      if (*(short *)0x06061238 < 0x3a) {
        if ((unsigned int)(*(short *)(0x060591F0 + *(short *)(0x06061238 << 1)) * 3) <=
            VBLANK_COUNTER) {
          *(short *)0x06061238 = *(short *)0x06061238 + 1;
          *(short *)frame_counter = 0;
          (*(int(*)())sprite_render)(0xc,priority,0x0000F000,0x06059826);
          *(short *)trigger_flag = 1;
        }
      }
      else if ((*(short *)0x06061238 == 0x3a) &&
              ((unsigned int)(*(short *)(0x060591F0 + *(short *)(0x06061238 << 1)) * 3) <=
               VBLANK_COUNTER)) {
        (*(int(*)())0x060283E0)(0xc,priority,0x0000F000,0x06059826);
        *(short *)seq_position = 0;
        *(short *)frame_counter = 0;
        *(short *)0x0606123E = 1;
      }
      if (*(short *)trigger_flag != 0) {
        (*(int(*)())sprite_render)(0xc,priority,0x0000F000,
                          *(int *)
                           (0x0606119C + (char)((int *)0x0605914C)[*(short *)seq_position + -1] * 4));
      }
      *(short *)trigger_flag = 0;
      if (0 < *(short *)seq_position) {
        while ((((unsigned int)(((int)*(short *)(0x060591F0 + (*(short *)seq_position + -1) << 1) +
                        (int)((char *)0x06059266)
                                   [(int)*(short *)frame_counter +
                                    (int)(short)((char)((int *)0x0605914C)[*(short *)seq_position + -1] *
                                                0x24)]) * 3) <= *(unsigned int *)vblank_ref &&
                (((char *)0x06059266)
                       [(int)*(short *)frame_counter +
                        (int)(short)((char)((int *)0x0605914C)[*(short *)seq_position + -1] * 0x24)] != -1))
               && (*(short *)frame_counter < 0x24))) {
          FUN_06026ca4(*(int *)
                        (0x0606119C + (char)((int *)0x0605914C)[*(short *)seq_position + -1] * 4),
                       (int)*(short *)frame_counter);
          *(short *)frame_counter = *(short *)frame_counter + 1;
        }
      }
    }

    else if (car_count == 2) {
      /* Expert mode: 52 positions, timing at 0x0605956E, frame stride 0x19 */
      if (*(short *)0x06061238 < 0x34) {
        if ((unsigned int)(*(short *)(0x0605956E + *(short *)(0x06061238 << 1)) * 3) <=
            VBLANK_COUNTER) {
          *(short *)0x06061238 = *(short *)0x06061238 + 1;
          *(short *)frame_counter = 0;
          (*(int(*)())sprite_render)(0xc,priority,0x0000F000,0x06059826);
          *(short *)trigger_flag = 1;
        }
      }
      else if ((*(short *)0x06061238 == 0x34) &&
              ((unsigned int)(*(short *)(0x0605956E + *(short *)(0x06061238 << 1)) * 3) <=
               VBLANK_COUNTER)) {
        (*(int(*)())0x060283E0)(0xc,priority,0x0000F000,0x06059826);
        *(short *)seq_position = 0;
        *(short *)frame_counter = 0;
        *(short *)0x0606123E = 1;
      }
      if (*(short *)trigger_flag != 0) {
        (*(int(*)())sprite_render)(0xc,priority,0x0000F000,
                          *(int *)
                           (0x060611DC + (char)((int *)0x06059186)[*(short *)seq_position + -1] * 4));
      }
      *(short *)trigger_flag = 0;
      if (0 < *(short *)seq_position) {
        while ((((unsigned int)(((int)*(short *)(0x0605956E + (*(short *)seq_position + -1) << 1) +
                        (int)((char *)0x060594A6)
                                   [(int)*(short *)frame_counter +
                                    (((int)(char)((int *)0x06059186)[*(short *)seq_position + -1] & 0xffffU)
                                     * 0x19 & 0xff)]) * 3) <= *(unsigned int *)vblank_ref &&
                (((char *)0x060594A6)
                       [(int)*(short *)frame_counter +
                        (((int)(char)((int *)0x06059186)[*(short *)seq_position + -1] & 0xffffU) * 0x19 &
                        0xff)] != -1)) && (*(short *)frame_counter < 0x19))) {
          FUN_06026ca4(*(int *)
                        (0x060611DC + (char)((int *)0x06059186)[*(short *)seq_position + -1] * 4),
                       (int)*(short *)frame_counter);
          *(short *)frame_counter = *(short *)frame_counter + 1;
        }
      }
    }

    /* Check for sequence completion */
    if (*(short *)0x0606123E != 0) {
      *(int *)vblank_ref = 0;
      *(short *)0x0606123E = 0;
    }
  }
  else {
    /* Reset sequence state */
    *(short *)0x0606123C = 0;
    *(short *)frame_counter = 0;
    *(short *)seq_position = 0;
    *(short *)0x0606123E = 0;
    *(int *)vblank_ref = 0;
  }

  return;
}
#endif

/* hud_digit_render -- Render a single HUD digit sprite.
 * Reads digit value from (param_1 + param_2), builds 2-byte sprite data
 * with digit value and zero terminator, calls sprite command writer.
 * PTR_DAT_06026cd4 is the base command offset for digit sprites. */
#if 0 /* FUN_06026CA4 -- replaced by ASM import */
void FUN_06026ca4(int param_1, short param_2)
{
    char sprite_data[2];
    sprite_data[0] = *(char *)(param_1 + param_2);
    sprite_data[1] = 0;

    (*(int(*)())0x060283E0)(0xc, ((int)param_2 + (int)PTR_DAT_06026cd4) << 1,
                            0x0000E000, sprite_data);
}
#endif

/* FUN_06026CA4 -- original binary (496 bytes) */
__asm__(
    ".section .text.FUN_06026CA4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06026CA4\n"
    ".global _FUN_06026ca4\n"
    ".type _FUN_06026CA4, @function\n"
    "_FUN_06026CA4:\n"
    "_FUN_06026ca4:\n"
    ".byte 0x2F, 0xE6, 0x4F, 0x22, 0x7F, 0xF8, 0x6E, 0xF3, 0x2F, 0x51, 0x7E, 0x04, 0x60, 0xF1, 0x67, 0xE3\n"  /* 0x06026CA4 */
    ".byte 0x03, 0x4C, 0xE0, 0x00, 0x2E, 0x30, 0x80, 0xE1, 0xD6, 0x06, 0x65, 0xF1, 0x93, 0x08, 0x35, 0x3C\n"  /* 0x06026CB4 */
    ".byte 0x45, 0x00, 0xD3, 0x05, 0x43, 0x0B, 0xE4, 0x0C, 0x7F, 0x08, 0x4F, 0x26, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x06026CC4 */
    ".byte 0x06, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0xE0, 0x00, 0x06, 0x02, 0x83, 0xE0, 0xD1, 0x10, 0xE2, 0x01\n"  /* 0x06026CD4 */
    ".byte 0xD3, 0x10, 0xE4, 0x00, 0x21, 0x22, 0x00, 0x09, 0x60, 0x12, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09\n"  /* 0x06026CE4 */
    ".byte 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09\n"  /* 0x06026CF4 */
    ".byte 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09\n"  /* 0x06026D04 */
    ".byte 0x00, 0x09, 0x00, 0x09, 0x40, 0x10, 0x8D, 0xE7, 0x74, 0x01, 0x00, 0x0B, 0x23, 0x42, 0x00, 0x09\n"  /* 0x06026D14 */
    ".byte 0x06, 0x06, 0x35, 0xC4, 0x06, 0x05, 0xA0, 0x10, 0xD2, 0x17, 0xE0, 0x00, 0xE1, 0x01, 0x02, 0x15\n"  /* 0x06026D24 */
    ".byte 0xE0, 0x02, 0xE1, 0x00, 0x02, 0x15, 0xE0, 0x06, 0xE1, 0x00, 0x02, 0x15, 0xE0, 0x0C, 0xE1, 0x00\n"  /* 0x06026D34 */
    ".byte 0x02, 0x15, 0xE0, 0x0E, 0x91, 0x1C, 0x02, 0x15, 0xE0, 0x20, 0xE1, 0x00, 0x02, 0x15, 0xE0, 0x28\n"  /* 0x06026D44 */
    ".byte 0xE1, 0x00, 0x02, 0x15, 0xE0, 0x2A, 0x91, 0x14, 0x02, 0x15, 0xE0, 0x30, 0x91, 0x12, 0x02, 0x15\n"  /* 0x06026D54 */
    ".byte 0xE0, 0x32, 0x91, 0x0F, 0x02, 0x15, 0xE0, 0x34, 0x91, 0x0C, 0x02, 0x15, 0xE0, 0x36, 0x91, 0x09\n"  /* 0x06026D64 */
    ".byte 0x02, 0x15, 0xE0, 0x38, 0xE1, 0x00, 0x02, 0x15, 0xE0, 0x3A, 0xE1, 0x00, 0x00, 0x0B, 0x02, 0x15\n"  /* 0x06026D74 */
    ".byte 0x13, 0x63, 0x10, 0x22, 0xC0, 0x00, 0x00, 0x00, 0x25, 0xF8, 0x00, 0x00, 0xE1, 0x00, 0xD0, 0x06\n"  /* 0x06026D84 */
    ".byte 0xD2, 0x06, 0x40, 0x10, 0x8F, 0xFD, 0x22, 0x16, 0xD0, 0x05, 0xD2, 0x06, 0x40, 0x10, 0x8F, 0xFD\n"  /* 0x06026D94 */
    ".byte 0x22, 0x16, 0x00, 0x0B, 0x00, 0x09, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x25, 0xF8, 0x00, 0x00\n"  /* 0x06026DA4 */
    ".byte 0x00, 0x03, 0x00, 0x00, 0x25, 0xCC, 0x00, 0x00, 0xD3, 0xAA, 0x60, 0x32, 0xE1, 0x30, 0x31, 0x0C\n"  /* 0x06026DB4 */
    ".byte 0x23, 0x12, 0x52, 0x00, 0x53, 0x01, 0x11, 0x20, 0x11, 0x31, 0x52, 0x02, 0x53, 0x03, 0x11, 0x22\n"  /* 0x06026DC4 */
    ".byte 0x11, 0x33, 0x52, 0x04, 0x53, 0x05, 0x11, 0x24, 0x11, 0x35, 0x52, 0x06, 0x53, 0x07, 0x11, 0x26\n"  /* 0x06026DD4 */
    ".byte 0x11, 0x37, 0x52, 0x08, 0x53, 0x09, 0x11, 0x28, 0x11, 0x39, 0x52, 0x0A, 0x53, 0x0B, 0x11, 0x2A\n"  /* 0x06026DE4 */
    ".byte 0x00, 0x0B, 0x11, 0x3B, 0xD1, 0x9B, 0x60, 0x12, 0x70, 0xD0, 0x00, 0x0B, 0x21, 0x02, 0xD0, 0x9A\n"  /* 0x06026DF4 */
    ".byte 0xD1, 0x98, 0xE2, 0x00, 0xA0, 0x03, 0x21, 0x02, 0xD0, 0x96, 0xE2, 0x00, 0x60, 0x02, 0xD1, 0x9A\n"  /* 0x06026E04 */
    ".byte 0x10, 0x21, 0x10, 0x10, 0x10, 0x22, 0x10, 0x23, 0x10, 0x14, 0x10, 0x25, 0x10, 0x26, 0x10, 0x27\n"  /* 0x06026E14 */
    ".byte 0x10, 0x18, 0x10, 0x29, 0x10, 0x2A, 0x00, 0x0B, 0x10, 0x2B, 0xD0, 0x90, 0xD1, 0x8D, 0x10, 0x40\n"  /* 0x06026E24 */
    ".byte 0x10, 0x51, 0x10, 0x62, 0x64, 0x12, 0xE3, 0x03, 0x65, 0x43, 0x75, 0x24, 0x00, 0x28, 0x00, 0x4F\n"  /* 0x06026E34 */
    ".byte 0x00, 0x4F, 0x00, 0x4F, 0x66, 0x52, 0x70, 0xF4, 0x43, 0x10, 0x01, 0x0A, 0x02, 0x1A, 0x22, 0x1D\n"  /* 0x06026E44 */
    ".byte 0x32, 0x6C, 0x25, 0x22, 0x8F, 0xF2, 0x75, 0x04, 0x00, 0x0B, 0x00, 0x09, 0xD0, 0x81, 0x67, 0x02\n"  /* 0x06026E54 */
    ".byte 0xE3, 0x03, 0x50, 0x70, 0x34, 0x0D, 0x50, 0x73, 0x01, 0x0A, 0x02, 0x1A, 0x22, 0x1D, 0x35, 0x0D\n"  /* 0x06026E64 */
    ".byte 0x17, 0x20, 0x50, 0x76, 0x01, 0x0A, 0x02, 0x1A, 0x22, 0x1D, 0x36, 0x0D, 0x17, 0x23, 0x43, 0x10\n"  /* 0x06026E74 */
    ".byte 0x01, 0x0A, 0x02, 0x1A, 0x22, 0x1D, 0x17, 0x26, 0x8F, 0xEB, 0x77, 0x04, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06026E84 */
);


/* FUN_06026dbc: L2 version in transform_stack.c */
extern void FUN_06026DBC(void);
void FUN_06026dbc(void) { FUN_06026DBC(); }

/* FUN_06026e02: L2 version in transform_stack.c */
extern void FUN_06026E02(void);
void FUN_06026e02(void) { FUN_06026E02(); }

/* FUN_06026e0c: L2 version in transform_stack.c */
extern void FUN_06026E0C(void);
void FUN_06026e0c(void) { FUN_06026E0C(); }

char * FUN_06026e2e(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  unsigned int uVar1;
  int iVar2;
  unsigned int uVar3;
  int iVar4;
  unsigned int uVar5;
  unsigned int uVar6;
  char *puVar7;
  char *puVar8;
  int iVar9;
  unsigned int *puVar10;
  unsigned int *puVar11;
  unsigned int in_sr = 0;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;

  puVar8 = (char *)0x0608A4E0;
  puVar7 = (int *)0x06089EDC;
  *(int *)0x0608A4E0 = param_1;
  *(int *)(puVar8 + 4) = param_2;
  *(int *)(puVar8 + 8) = param_3;
  puVar10 = *(unsigned int **)puVar7;
  iVar9 = 3;
  puVar11 = puVar10 + 9;
  do {
    uVar5 = *(unsigned int *)puVar8;
    uVar12 = *puVar10;
    { long long _m31 = (long long)(int)uVar5 * (int)uVar12;
      uVar12 = (unsigned int)((unsigned long long)_m31 >> 32);
      uVar13 = (unsigned int)_m31; }
    uVar6 = *(unsigned int *)(puVar8 + 4);
    uVar5 = puVar10[1];
    { long long _m30 = (long long)(int)uVar6 * (int)uVar5;
      uVar5 = (unsigned int)((unsigned long long)_m30 >> 32);
      uVar14 = (unsigned int)_m30; }
    uVar14 = uVar13 + uVar14;
    uVar12 = uVar5 + (uVar14 < uVar13) + uVar12;
    uVar6 = *(unsigned int *)(puVar8 + 8);
    uVar5 = puVar10[2];
    puVar10 = puVar10 + 3;
    { long long _m29 = (long long)(int)uVar6 * (int)uVar5;
      uVar5 = (unsigned int)((unsigned long long)_m29 >> 32);
      uVar15 = (unsigned int)_m29; }
    uVar15 = uVar14 + uVar15;
    uVar12 = uVar5 + (uVar15 < uVar14) + uVar12;
    iVar9 = iVar9 + -1;
    in_sr = in_sr & 0xfffffffe;
    *puVar11 = (uVar12 << 0x10 | uVar15 >> 0x10) + *puVar11;
    puVar11 = puVar11 + 1;
  } while (iVar9 != 0);
  return puVar8;
}

/* matrix_scale_alt -- Scale the alternate matrix (0x06089EDC) by X/Y/Z factors.
 * Applies 16.16 fixed-point multiplication to each row of the 3x3 portion:
 * row[0] *= param_1 (X scale), row[1] *= param_2 (Y scale),
 * row[2] *= param_3 (Z scale). Iterates 3 columns. */
unsigned int FUN_06026e60(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
    long long lVar1;
    unsigned int uVar2;
    int col;
    unsigned int *mtx = *(unsigned int **)0x06089EDC;

    col = 3;
    do {
        *mtx = (int)((unsigned long long)((long long)param_1 * (long long)(int)*mtx) >> 0x20) << 0x10 |
               (unsigned int)((long long)param_1 * (long long)(int)*mtx) >> 0x10;
        uVar2 = mtx[6];
        lVar1 = (long long)param_3 * (long long)(int)uVar2;
        mtx[3] = (int)((unsigned long long)((long long)param_2 * (long long)(int)mtx[3]) >> 0x20) << 0x10 |
                 (unsigned int)((long long)param_2 * (long long)(int)mtx[3]) >> 0x10;
        col = col + -1;
        mtx[6] = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;
        mtx = mtx + 1;
    } while (col != 0);
    return uVar2;
}

/* matrix_rotate_x -- Apply X-axis rotation to current view matrix.
 * Computes sin/cos via math_sin_cos(), stores rotation at 0x0608A4E0.
 * Multiplies current view matrix at *(0x06089EDC) by the X rotation
 * using software 32-bit fixed-point MAC (3x3 multiply). */
#if 0 /* FUN_06026E94 -- replaced by ASM import */
unsigned int FUN_06026e94()
{
  unsigned int uVar1;
  int iVar2;
  unsigned int uVar3;
  unsigned int uVar4;
  int iVar5;
  unsigned int uVar6;
  char *puVar7;
  int iVar8;
  unsigned int *puVar9;
  int *piVar10;
  unsigned int *puVar11;
  unsigned int in_sr = 0;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;

  piVar10 = (int *)(0x0608A4E0 + 8);
  puVar11 = (unsigned int *)0x0608A4E0;
  math_sin_cos();
  puVar11[1] = -*piVar10;
  puVar7 = (int *)0x06089EDC;
  puVar11[3] = *puVar11;
  iVar8 = 3;
  puVar9 = (unsigned int *)(*(int *)puVar7 + 4);
  do {
    uVar13 = *puVar9;
    uVar12 = *puVar11;
    { long long _m28 = (long long)(int)uVar13 * (int)uVar12;
      uVar12 = (unsigned int)((unsigned long long)_m28 >> 32);
      uVar14 = (unsigned int)_m28; }
    uVar6 = puVar9[1];
    uVar13 = puVar11[1];
    { long long _m27 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m27 >> 32);
      uVar15 = (unsigned int)_m27; }
    uVar15 = uVar14 + uVar15;
    uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;
    uVar6 = *puVar9;
    uVar13 = puVar11[2];
    { long long _m26 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m26 >> 32);
      uVar16 = (unsigned int)_m26; }
    uVar1 = puVar9[1];
    uVar6 = puVar11[3];
    { long long _m25 = (long long)(int)uVar1 * (int)uVar6;
      uVar6 = (unsigned int)((unsigned long long)_m25 >> 32);
      uVar17 = (unsigned int)_m25; }
    uVar17 = uVar16 + uVar17;
    uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;
    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;
    iVar8 = iVar8 + -1;
    in_sr = in_sr & 0xfffffffe;
    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;
    puVar9 = puVar9 + 3;
  } while (iVar8 != 0);
  return uVar13;
}
#endif

/* FUN_06026ede: L2 version in heading_rotation.c */
extern void FUN_06026EDE(int heading);
#if 0 /* FUN_06026EDE -- replaced by ASM import of original bytes */
void FUN_06026ede(int heading) { FUN_06026EDE(heading); }
#endif

/* matrix_rotate_y_alt -- Apply Y-axis rotation to current view matrix (variant).
 * Same pattern as FUN_06026e94 but rotates around Y axis.
 * Sin/cos at 0x0608A4E0, negates element [1] for Y-axis rotation sign.
 * Multiplies against matrix at *(0x06089EDC). */
unsigned int FUN_06026f2a()
{
  unsigned int uVar1;
  int iVar2;
  unsigned int uVar3;
  unsigned int uVar4;
  int iVar5;
  unsigned int uVar6;
  char *puVar7;
  int iVar8;
  unsigned int *puVar9;
  int *piVar10;
  unsigned int *puVar11;
  unsigned int in_sr = 0;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;

  piVar10 = (int *)(0x0608A4E0 + 8);
  puVar11 = (unsigned int *)0x0608A4E0;
  math_sin_cos();
  puVar11[1] = -*piVar10;
  puVar7 = (int *)0x06089EDC;
  puVar11[3] = *puVar11;
  puVar9 = *(unsigned int **)puVar7;
  iVar8 = 3;
  do {
    uVar13 = *puVar9;
    uVar12 = *puVar11;
    { long long _m24 = (long long)(int)uVar13 * (int)uVar12;
      uVar12 = (unsigned int)((unsigned long long)_m24 >> 32);
      uVar14 = (unsigned int)_m24; }
    uVar6 = puVar9[1];
    uVar13 = puVar11[1];
    { long long _m23 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m23 >> 32);
      uVar15 = (unsigned int)_m23; }
    uVar15 = uVar14 + uVar15;
    uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;
    uVar6 = *puVar9;
    uVar13 = puVar11[2];
    { long long _m22 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m22 >> 32);
      uVar16 = (unsigned int)_m22; }
    uVar1 = puVar9[1];
    uVar6 = puVar11[3];
    { long long _m21 = (long long)(int)uVar1 * (int)uVar6;
      uVar6 = (unsigned int)((unsigned long long)_m21 >> 32);
      uVar17 = (unsigned int)_m21; }
    uVar17 = uVar16 + uVar17;
    uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;
    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;
    iVar8 = iVar8 + -1;
    in_sr = in_sr & 0xfffffffe;
    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;
    puVar9 = puVar9 + 3;
  } while (iVar8 != 0);
  return uVar13;
}

/* matrix_multiply_3x3 -- Multiply current view matrix by arbitrary 3x3 matrix.
 * param_1 = pointer to 3x3 matrix (9 ints). Reads current matrix from
 * *(0x06089EDC), performs row-by-column dot products using software
 * 32-bit fixed-point MAC, writes result back to same matrix location.
 * 3-iteration outer loop (iVar8=3) processes all 3 output rows. */
void FUN_06026f72(param_1)
    unsigned int *param_1;
{
  int iVar1;
  unsigned int uVar2;
  int iVar3;
  unsigned int *puVar4;
  unsigned int uVar5;
  int iVar6;
  unsigned int uVar7;
  int iVar8;
  unsigned int uVar9;
  unsigned int *puVar10;
  unsigned int uVar11;
  unsigned int *puVar12;
  unsigned int *puVar13;
  unsigned int uVar14;
  unsigned int *puVar15;
  unsigned int *puVar16;
  unsigned int in_sr = 0;
  unsigned int uVar17;
  unsigned int uVar18;
  unsigned int uVar19;

  iVar8 = 3;
  puVar4 = *(unsigned int **)0x06089EDC;
  puVar15 = (unsigned int *)0x0608A4F0;
  do {
    puVar12 = puVar4;
    iVar6 = 3;
    do {
      uVar11 = in_sr;
      puVar10 = param_1;
      uVar7 = *puVar12;
      uVar5 = *puVar10;
      { long long _m20 = (long long)(int)uVar7 * (int)uVar5;
        uVar5 = (unsigned int)((unsigned long long)_m20 >> 32);
        uVar17 = (unsigned int)_m20; }
      uVar9 = puVar12[1];
      uVar7 = puVar10[3];
      { long long _m19 = (long long)(int)uVar9 * (int)uVar7;
        uVar7 = (unsigned int)((unsigned long long)_m19 >> 32);
        uVar18 = (unsigned int)_m19; }
      uVar18 = uVar17 + uVar18;
      uVar5 = uVar7 + (uVar18 < uVar17) + uVar5;
      iVar6 = iVar6 + -1;
      in_sr = uVar11 & 0xfffffffe;
      uVar9 = puVar12[2];
      uVar7 = puVar10[6];
      { long long _m18 = (long long)(int)uVar9 * (int)uVar7;
        uVar7 = (unsigned int)((unsigned long long)_m18 >> 32);
        uVar19 = (unsigned int)_m18; }
      uVar19 = uVar18 + uVar19;
      uVar5 = uVar7 + (uVar19 < uVar18) + uVar5;
      *puVar15 = uVar5 << 0x10 | uVar19 >> 0x10;
      puVar15 = puVar15 + 1;
      param_1 = puVar10 + 1;
    } while (iVar6 != 0);
    param_1 = puVar10 + -2;
    iVar8 = iVar8 + -1;
    puVar4 = puVar12 + 3;
  } while (iVar8 != 0);
  puVar13 = puVar12 + -6;
  iVar8 = 3;
  do {
    puVar16 = puVar4;
    puVar12 = puVar15;
    uVar7 = *puVar13;
    uVar5 = puVar10[7];
    { long long _m17 = (long long)(int)uVar7 * (int)uVar5;
      uVar5 = (unsigned int)((unsigned long long)_m17 >> 32);
      uVar17 = (unsigned int)_m17; }
    uVar9 = puVar13[1];
    uVar7 = puVar10[8];
    { long long _m16 = (long long)(int)uVar9 * (int)uVar7;
      uVar7 = (unsigned int)((unsigned long long)_m16 >> 32);
      uVar18 = (unsigned int)_m16; }
    uVar18 = uVar17 + uVar18;
    uVar5 = uVar7 + (uVar18 < uVar17) + uVar5;
    iVar8 = iVar8 + -1;
    uVar9 = puVar13[2];
    puVar13 = puVar13 + 3;
    uVar7 = puVar10[9];
    { long long _m15 = (long long)(int)uVar9 * (int)uVar7;
      uVar7 = (unsigned int)((unsigned long long)_m15 >> 32);
      uVar19 = (unsigned int)_m15; }
    uVar19 = uVar18 + uVar19;
    uVar5 = uVar7 + (uVar19 < uVar18) + uVar5;
    *puVar12 = (uVar5 << 0x10 | uVar19 >> 0x10) + *puVar16;
    puVar15 = puVar12 + 1;
    puVar4 = puVar16 + 1;
  } while (iVar8 != 0);
  uVar5 = puVar12[-10];
  uVar7 = puVar12[-9];
  uVar9 = puVar12[-8];
  uVar11 = puVar12[-7];
  uVar14 = puVar12[-6];
  puVar16[-0xb] = puVar12[-0xb];
  puVar16[-10] = uVar5;
  puVar16[-9] = uVar7;
  puVar16[-8] = uVar9;
  puVar16[-7] = uVar11;
  puVar16[-6] = uVar14;
  uVar5 = puVar12[-4];
  uVar7 = puVar12[-3];
  uVar9 = puVar12[-2];
  uVar11 = puVar12[-1];
  uVar14 = *puVar12;
  puVar16[-5] = puVar12[-5];
  puVar16[-4] = uVar5;
  puVar16[-3] = uVar7;
  puVar16[-2] = uVar9;
  puVar16[-1] = uVar11;
  *puVar16 = uVar14;
  return;
}

/* FUN_06026ffc: L2 version in matrix_transform.c */
#if 0 /* FUN_06026FFC -- replaced by ASM import */
extern void FUN_06026FFC(int *input, int *output);
void FUN_06026ffc(int *input, int *output) { FUN_06026FFC(input, output); }
#endif

/* FUN_06026FFC -- original binary (348 bytes) */
__asm__(
    ".section .text.FUN_06026FFC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06026FFC\n"
    ".global _FUN_06026ffc\n"
    ".type _FUN_06026FFC, @function\n"
    "_FUN_06026FFC:\n"
    "_FUN_06026ffc:\n"
    ".byte 0x2F, 0xE6, 0xD0, 0x1A, 0xE7, 0x24, 0x66, 0x02, 0xDE, 0x1C, 0x37, 0x6C, 0xE3, 0x03, 0x00, 0x28\n"  /* 0x06026FFC */
    ".byte 0x06, 0x4F, 0x06, 0x4F, 0x62, 0x76, 0x06, 0x4F, 0x43, 0x10, 0x74, 0xF4, 0x00, 0x0A, 0x01, 0x1A\n"  /* 0x0602700C */
    ".byte 0x21, 0x0D, 0x31, 0x2C, 0x2E, 0x12, 0x8F, 0xF2, 0x7E, 0x04, 0x7E, 0xF4, 0x60, 0xE6, 0x61, 0xE6\n"  /* 0x0602701C */
    ".byte 0x62, 0xE6, 0x25, 0x02, 0x15, 0x11, 0x15, 0x22, 0x00, 0x0B, 0x6E, 0xF6, 0xD0, 0x0B, 0xD6, 0x0F\n"  /* 0x0602702C */
    ".byte 0x62, 0x02, 0xE3, 0x03, 0x00, 0x28, 0x02, 0x4F, 0x02, 0x4F, 0x02, 0x4F, 0x43, 0x10, 0x74, 0xF4\n"  /* 0x0602703C */
    ".byte 0x00, 0x0A, 0x01, 0x1A, 0x21, 0x0D, 0x26, 0x12, 0x8F, 0xF4, 0x76, 0x04, 0x76, 0xF4, 0x60, 0x62\n"  /* 0x0602704C */
    ".byte 0x51, 0x61, 0x52, 0x62, 0x25, 0x02, 0x15, 0x11, 0x00, 0x0B, 0x15, 0x22, 0x06, 0x08, 0x9E, 0xDC\n"  /* 0x0602705C */
    ".byte 0x06, 0x08, 0x9E, 0xE0, 0x06, 0x08, 0xA4, 0xE0, 0x06, 0x08, 0xA4, 0xF0, 0x06, 0x08, 0xA5, 0x20\n"  /* 0x0602706C */
    ".byte 0x00, 0x01, 0x00, 0x00, 0xD3, 0xAA, 0x60, 0x32, 0xE1, 0x30, 0x31, 0x0C, 0x23, 0x12, 0x52, 0x00\n"  /* 0x0602707C */
    ".byte 0x53, 0x01, 0x11, 0x20, 0x11, 0x31, 0x52, 0x02, 0x53, 0x03, 0x11, 0x22, 0x11, 0x33, 0x52, 0x04\n"  /* 0x0602708C */
    ".byte 0x53, 0x05, 0x11, 0x24, 0x11, 0x35, 0x52, 0x06, 0x53, 0x07, 0x11, 0x26, 0x11, 0x37, 0x52, 0x08\n"  /* 0x0602709C */
    ".byte 0x53, 0x09, 0x11, 0x28, 0x11, 0x39, 0x52, 0x0A, 0x53, 0x0B, 0x11, 0x2A, 0x00, 0x0B, 0x11, 0x3B\n"  /* 0x060270AC */
    ".byte 0xD1, 0x9B, 0x60, 0x12, 0x70, 0xD0, 0x00, 0x0B, 0x21, 0x02, 0xD0, 0x9A, 0xD1, 0x98, 0xE2, 0x00\n"  /* 0x060270BC */
    ".byte 0xA0, 0x03, 0x21, 0x02, 0xD0, 0x96, 0xE2, 0x00, 0x60, 0x02, 0xD1, 0x9A, 0x10, 0x21, 0x10, 0x10\n"  /* 0x060270CC */
    ".byte 0x10, 0x22, 0x10, 0x23, 0x10, 0x14, 0x10, 0x25, 0x10, 0x26, 0x10, 0x27, 0x10, 0x18, 0x10, 0x29\n"  /* 0x060270DC */
    ".byte 0x10, 0x2A, 0x00, 0x0B, 0x10, 0x2B, 0xD0, 0x90, 0xD1, 0x8D, 0x10, 0x40, 0x10, 0x51, 0x10, 0x62\n"  /* 0x060270EC */
    ".byte 0x64, 0x12, 0xE3, 0x03, 0x65, 0x43, 0x75, 0x24, 0x00, 0x28, 0x00, 0x4F, 0x00, 0x4F, 0x00, 0x4F\n"  /* 0x060270FC */
    ".byte 0x66, 0x52, 0x70, 0xF4, 0x43, 0x10, 0x01, 0x0A, 0x02, 0x1A, 0x22, 0x1D, 0x32, 0x6C, 0x25, 0x22\n"  /* 0x0602710C */
    ".byte 0x8F, 0xF2, 0x75, 0x04, 0x00, 0x0B, 0x00, 0x09, 0xD0, 0x81, 0x67, 0x02, 0xE3, 0x03, 0x50, 0x70\n"  /* 0x0602711C */
    ".byte 0x34, 0x0D, 0x50, 0x73, 0x01, 0x0A, 0x02, 0x1A, 0x22, 0x1D, 0x35, 0x0D, 0x17, 0x20, 0x50, 0x76\n"  /* 0x0602712C */
    ".byte 0x01, 0x0A, 0x02, 0x1A, 0x22, 0x1D, 0x36, 0x0D, 0x17, 0x23, 0x43, 0x10, 0x01, 0x0A, 0x02, 0x1A\n"  /* 0x0602713C */
    ".byte 0x22, 0x1D, 0x17, 0x26, 0x8F, 0xEB, 0x77, 0x04, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x0602714C */
);


/* matrix_stack_push -- Push current 4x3 matrix onto the matrix stack.
 * Copies 12 ints (4x3 matrix) from current stack top to next slot,
 * then advances the stack pointer at 0x0608A52C by 12 words (48 bytes). */
void FUN_06027080()
{
    int *mtx = *(int **)0x0608A52C;
    *(int **)0x0608A52C = mtx + 0xc;
    mtx[0xc] = *mtx;
    mtx[0xd] = mtx[1];
    mtx[0xe] = mtx[2];
    mtx[0xf] = mtx[3];
    mtx[0x10] = mtx[4];
    mtx[0x11] = mtx[5];
    mtx[0x12] = mtx[6];
    mtx[0x13] = mtx[7];
    mtx[0x14] = mtx[8];
    mtx[0x15] = mtx[9];
    mtx[0x16] = mtx[10];
    mtx[0x17] = mtx[0xb];
}

/* FUN_060270c6: L2 version in transform_stack.c */
extern void FUN_060270C6(void);
void FUN_060270c6(void) { FUN_060270C6(); }

/* matrix_load_identity -- Load identity matrix at current stack top.
 * Same as reset but doesn't move the stack pointer — overwrites
 * the current 4x3 matrix with identity (1.0 on diagonal). */
void FUN_060270d0()
{
    char *one = (int *)0x00010000;               /* 1.0 in 16.16 fixed-point */
    int *mtx = *(int **)0x0608A52C;
    mtx[1] = 0;
    *mtx = one;
    mtx[2] = 0;
    mtx[3] = 0;
    mtx[4] = one;
    mtx[5] = 0;
    mtx[6] = 0;
    mtx[7] = 0;
    mtx[8] = one;
    mtx[9] = 0;
    mtx[10] = 0;
    mtx[0xb] = 0;
}

/* matrix_vector_multiply_alt -- Multiply 3D vector by 3x3 matrix (alt pipeline).
 * Writes input vector (param_1, param_2, param_3) to 0x0608A6B0, then multiplies
 * by matrix at alt pipeline stack base 0x0608A52C. Uses software 16.16 fixed-point
 * MAC multiply with sign handling. Returns transformed vector components. */
char * FUN_060270f2(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
  unsigned int uVar1;
  int iVar2;
  unsigned int uVar3;
  int iVar4;
  unsigned int uVar5;
  unsigned int uVar6;
  char *puVar7;
  char *puVar8;
  int iVar9;
  unsigned int *puVar10;
  unsigned int *puVar11;
  unsigned int in_sr = 0;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;

  puVar8 = (char *)0x0608A6B0;
  puVar7 = (int *)0x0608A52C;
  *(int *)0x0608A6B0 = param_1;
  *(int *)(puVar8 + 4) = param_2;
  *(int *)(puVar8 + 8) = param_3;
  puVar10 = *(unsigned int **)puVar7;
  iVar9 = 3;
  puVar11 = puVar10 + 9;
  do {
    uVar5 = *(unsigned int *)puVar8;
    uVar12 = *puVar10;
    { long long _m14 = (long long)(int)uVar5 * (int)uVar12;
      uVar12 = (unsigned int)((unsigned long long)_m14 >> 32);
      uVar13 = (unsigned int)_m14; }
    uVar6 = *(unsigned int *)(puVar8 + 4);
    uVar5 = puVar10[1];
    { long long _m13 = (long long)(int)uVar6 * (int)uVar5;
      uVar5 = (unsigned int)((unsigned long long)_m13 >> 32);
      uVar14 = (unsigned int)_m13; }
    uVar14 = uVar13 + uVar14;
    uVar12 = uVar5 + (uVar14 < uVar13) + uVar12;
    uVar6 = *(unsigned int *)(puVar8 + 8);
    uVar5 = puVar10[2];
    puVar10 = puVar10 + 3;
    { long long _m12 = (long long)(int)uVar6 * (int)uVar5;
      uVar5 = (unsigned int)((unsigned long long)_m12 >> 32);
      uVar15 = (unsigned int)_m12; }
    uVar15 = uVar14 + uVar15;
    uVar12 = uVar5 + (uVar15 < uVar14) + uVar12;
    iVar9 = iVar9 + -1;
    in_sr = in_sr & 0xfffffffe;
    *puVar11 = (uVar12 << 0x10 | uVar15 >> 0x10) + *puVar11;
    puVar11 = puVar11 + 1;
  } while (iVar9 != 0);
  return puVar8;
}

/* matrix_scale -- Scale the current matrix stack top by X/Y/Z factors.
 * Applies 16.16 fixed-point multiplication to each row of the 3x3 portion:
 * row[0] *= param_1 (X scale), row[1] *= param_2 (Y scale),
 * row[2] *= param_3 (Z scale). Iterates 3 columns. */
unsigned int FUN_06027124(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
    long long lVar1;
    unsigned int uVar2;
    int col;
    unsigned int *mtx = *(unsigned int **)0x0608A52C;

    col = 3;
    do {
        *mtx = (int)((unsigned long long)((long long)param_1 * (long long)(int)*mtx) >> 0x20) << 0x10 |
               (unsigned int)((long long)param_1 * (long long)(int)*mtx) >> 0x10;
        uVar2 = mtx[6];
        lVar1 = (long long)param_3 * (long long)(int)uVar2;
        mtx[3] = (int)((unsigned long long)((long long)param_2 * (long long)(int)mtx[3]) >> 0x20) << 0x10 |
                 (unsigned int)((long long)param_2 * (long long)(int)mtx[3]) >> 0x10;
        col = col + -1;
        mtx[6] = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;
        mtx = mtx + 1;
    } while (col != 0);
    return uVar2;
}

/* matrix_rotate_x_alt -- Apply X-axis rotation to alternate view matrix.
 * Same algorithm as FUN_06026e94 but uses alternate matrix stack:
 * sin/cos buffer at 0x0608A6B0, matrix at *(0x0608A52C).
 * Used for the second rendering pipeline (course 2 / mirror). */
#if 0 /* FUN_06027158 -- replaced by ASM import */
unsigned int FUN_06027158()
{
  unsigned int uVar1;
  int iVar2;
  unsigned int uVar3;
  unsigned int uVar4;
  int iVar5;
  unsigned int uVar6;
  char *puVar7;
  int iVar8;
  unsigned int *puVar9;
  int *piVar10;
  unsigned int *puVar11;
  unsigned int in_sr = 0;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;

  piVar10 = (int *)(0x0608A6B0 + 8);
  puVar11 = (unsigned int *)0x0608A6B0;
  math_sin_cos();
  puVar11[1] = -*piVar10;
  puVar7 = (int *)0x0608A52C;
  puVar11[3] = *puVar11;
  iVar8 = 3;
  puVar9 = (unsigned int *)(*(int *)puVar7 + 4);
  do {
    uVar13 = *puVar9;
    uVar12 = *puVar11;
    { long long _m11 = (long long)(int)uVar13 * (int)uVar12;
      uVar12 = (unsigned int)((unsigned long long)_m11 >> 32);
      uVar14 = (unsigned int)_m11; }
    uVar6 = puVar9[1];
    uVar13 = puVar11[1];
    { long long _m10 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m10 >> 32);
      uVar15 = (unsigned int)_m10; }
    uVar15 = uVar14 + uVar15;
    uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;
    uVar6 = *puVar9;
    uVar13 = puVar11[2];
    { long long _m9 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m9 >> 32);
      uVar16 = (unsigned int)_m9; }
    uVar1 = puVar9[1];
    uVar6 = puVar11[3];
    { long long _m8 = (long long)(int)uVar1 * (int)uVar6;
      uVar6 = (unsigned int)((unsigned long long)_m8 >> 32);
      uVar17 = (unsigned int)_m8; }
    uVar17 = uVar16 + uVar17;
    uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;
    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;
    iVar8 = iVar8 + -1;
    in_sr = in_sr & 0xfffffffe;
    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;
    puVar9 = puVar9 + 3;
  } while (iVar8 != 0);
  return uVar13;
}
#endif

/* matrix_rotate_y_alt2 -- Apply Y-axis rotation to alternate view matrix.
 * Same algorithm as FUN_06026f2a but uses alternate matrix stack:
 * sin/cos buffer at 0x0608A6B0 (element [2] negated for Y rotation),
 * matrix at *(0x0608A52C). Used for second rendering pipeline. */
#if 0 /* FUN_060271A2 -- replaced by ASM import */
unsigned int FUN_060271a2()
{
  unsigned int uVar1;
  int iVar2;
  unsigned int uVar3;
  unsigned int uVar4;
  int iVar5;
  unsigned int uVar6;
  char *puVar7;
  int iVar8;
  unsigned int *puVar9;
  int *piVar10;
  unsigned int *puVar11;
  unsigned int in_sr = 0;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;

  piVar10 = (int *)(0x0608A6B0 + 4);
  puVar11 = (unsigned int *)0x0608A6B0;
  math_sin_cos();
  puVar11[2] = -*piVar10;
  puVar7 = (int *)0x0608A52C;
  puVar11[3] = *puVar11;
  puVar9 = *(unsigned int **)puVar7;
  iVar8 = 3;
  do {
    uVar13 = *puVar9;
    uVar12 = *puVar11;
    { long long _m7 = (long long)(int)uVar13 * (int)uVar12;
      uVar12 = (unsigned int)((unsigned long long)_m7 >> 32);
      uVar14 = (unsigned int)_m7; }
    uVar6 = puVar9[2];
    uVar13 = puVar11[1];
    { long long _m6 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m6 >> 32);
      uVar15 = (unsigned int)_m6; }
    uVar15 = uVar14 + uVar15;
    uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;
    uVar6 = *puVar9;
    uVar13 = puVar11[2];
    { long long _m5 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m5 >> 32);
      uVar16 = (unsigned int)_m5; }
    uVar1 = puVar9[2];
    uVar6 = puVar11[3];
    { long long _m4 = (long long)(int)uVar1 * (int)uVar6;
      uVar6 = (unsigned int)((unsigned long long)_m4 >> 32);
      uVar17 = (unsigned int)_m4; }
    uVar17 = uVar16 + uVar17;
    uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;
    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;
    iVar8 = iVar8 + -1;
    in_sr = in_sr & 0xfffffffe;
    puVar9[2] = uVar13 << 0x10 | uVar17 >> 0x10;
    puVar9 = puVar9 + 3;
  } while (iVar8 != 0);
  return uVar13;
}
#endif

/* matrix_rotate_z_alt -- Apply Z-axis rotation to alternate view matrix.
 * Same algorithm as rotate_x/y_alt but for Z axis rotation:
 * sin/cos at 0x0608A6B0 (element [1] negated for Z rotation),
 * matrix at *(0x0608A52C). Used for second rendering pipeline. */
unsigned int FUN_060271ee()
{
  unsigned int uVar1;
  int iVar2;
  unsigned int uVar3;
  unsigned int uVar4;
  int iVar5;
  unsigned int uVar6;
  char *puVar7;
  int iVar8;
  unsigned int *puVar9;
  int *piVar10;
  unsigned int *puVar11;
  unsigned int in_sr = 0;
  unsigned int uVar12;
  unsigned int uVar13;
  unsigned int uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  unsigned int uVar17;

  piVar10 = (int *)(0x0608A6B0 + 8);
  puVar11 = (unsigned int *)0x0608A6B0;
  math_sin_cos();
  puVar11[1] = -*piVar10;
  puVar7 = (int *)0x0608A52C;
  puVar11[3] = *puVar11;
  puVar9 = *(unsigned int **)puVar7;
  iVar8 = 3;
  do {
    uVar13 = *puVar9;
    uVar12 = *puVar11;
    { long long _m3 = (long long)(int)uVar13 * (int)uVar12;
      uVar12 = (unsigned int)((unsigned long long)_m3 >> 32);
      uVar14 = (unsigned int)_m3; }
    uVar6 = puVar9[1];
    uVar13 = puVar11[1];
    { long long _m2 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m2 >> 32);
      uVar15 = (unsigned int)_m2; }
    uVar15 = uVar14 + uVar15;
    uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;
    uVar6 = *puVar9;
    uVar13 = puVar11[2];
    { long long _m1 = (long long)(int)uVar6 * (int)uVar13;
      uVar13 = (unsigned int)((unsigned long long)_m1 >> 32);
      uVar16 = (unsigned int)_m1; }
    uVar1 = puVar9[1];
    uVar6 = puVar11[3];
    { long long _m0 = (long long)(int)uVar1 * (int)uVar6;
      uVar6 = (unsigned int)((unsigned long long)_m0 >> 32);
      uVar17 = (unsigned int)_m0; }
    uVar17 = uVar16 + uVar17;
    uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;
    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;
    iVar8 = iVar8 + -1;
    in_sr = in_sr & 0xfffffffe;
    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;
    puVar9 = puVar9 + 3;
  } while (iVar8 != 0);
  return uVar13;
}

void math_sin_cos(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    int *param_3;
{

  char *puVar1;

  unsigned int uVar2;

  int iVar3;

  puVar1 = (int *)0x002F2F20;

  iVar3 = 0x4000;

  uVar2 = 0x3FFC;

  *param_2 = *(int *)(0x002F2F20 + (param_1 + 8U >> 2 & uVar2));

  *param_3 = *(int *)(puVar1 + (iVar3 + param_1 + 8U >> 2 & uVar2));

  return;

}
/* end math_sin_cos */

/* track_surface_collision_query -- determine track surface type under car from grid-based polygon test */
#if 0 /* FUN_06027CA4 -- replaced by ASM import */
void FUN_06027ca4(param_1, param_2)
    unsigned int *param_1;
    int param_2;
{
  short search_id;
  unsigned int *poly_record;
  short rpm_value;
  unsigned int *grid_cell;
  short *search_ptr;
  unsigned int surface_flags;
  int half_space;
  unsigned int hit_found;
  int poly_count;
  char *poly_index_ptr;

  /* Compute grid cell from X/Z world position (21-bit quantization, 64-wide grid) */
  grid_cell = (unsigned int *)(((unsigned int)(0x04000000 + *param_1) >> 0x15) +
                   (0x03FFFFFF - param_1[2] >> 0x15) << 6);

  if (CAR_COUNT == 2) {
    /* 2-player: search override table */
    poly_count = 0;
    search_ptr = (short *)0x06061270;
    while( 1 ) {
      search_id = *search_ptr;
      search_ptr = search_ptr + 1;
      if ((unsigned int *)(int)search_id == (unsigned int *)0x0) break;
      if (grid_cell == (unsigned int *)(int)search_id) {
        if (*(int *)(CAR_PTR_CURRENT + (int)DAT_06027d26) < 0x47) {
          search_id = *(short *)(0x06061240 + (poly_count << 1));
          poly_count = (int)*(short *)((int)(0x06061240 + (poly_count << 1)) + 2);
          *(short *)0x06063F50 = search_id;
          poly_index_ptr = (char *)(int)search_id;
          goto LAB_06027d36;
        }
        break;
      }
      poly_count = poly_count + 2;
    }
    poly_count = 0;
    poly_index_ptr = (char *)0x0607EAD8;

LAB_06027d36:
    if (poly_count != 0) goto LAB_06027d50;
  }

  /* Standard lookup from collision table at 0x060C2000 */
  poly_index_ptr = (char *)(unsigned int)*(unsigned short *)(0x060C2000 + (int)((int)(int)grid_cell << 2));
  poly_count = (int)(short)*(unsigned short *)((int)(0x060C2000 + (int)((int)(int)grid_cell << 2)) + 2);

LAB_06027d50:
  /* Test each polygon's 4 half-space planes with directional sign flags */
  do {
    if (poly_count < 1) {
      /* No hit found */
      surface_flags = 0;
      hit_found = 0;

LAB_06027e6a:
      *(short *)(param_1 + 3) = (short)surface_flags; /* surface type output */

      if (hit_found == 0) {
        poly_count = CAR_PTR_CURRENT;
      }
      else {
        /* Hit found — extract surface properties */
        search_id = *(short *)(grid_cell + 0xc);
        param_1[4] = (int)search_id; /* surface_material */
        rpm_value = (*(int(*)())0x0602ECCC)(); /* get_engine_rpm */
        *(short *)((int)param_1 + 0xe) = rpm_value;
        poly_count = CAR_PTR_CURRENT;
        if (param_2 < 1) {
          *(int *)(DAT_06027e9a + poly_count) = (int)search_id; /* store primary surface */
        }
      }

      /* Write surface flags to per-car indexed offset */
      *(unsigned int *)((unsigned int)*(unsigned short *)(0x0606128A + (param_2 << 1)) + poly_count) = surface_flags;
      return;
    }

    poly_record = (unsigned int *)(0x060A6000 + *(short *)(poly_index_ptr + (int)0x060BF000) * 0x34);
    surface_flags = *poly_record;

    /* Plane 0 test */
    half_space = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)poly_record[4]) >> 0x20) << 0x10
            | (unsigned int)((long long)(int)*param_1 * (long long)(int)poly_record[4]) >> 0x10) + poly_record[5];
    if ((surface_flags & 0x1000000) == 0) {
      half_space = half_space + param_1[2];
    }

    if ((0x100 & surface_flags) == 0) {
      if (half_space < 0) {
        poly_index_ptr = poly_index_ptr + 2;
        poly_count = poly_count + -1;
        goto LAB_06027d50;
      }

LAB_06027db6:
      /* Plane 1 test */
      half_space = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)poly_record[6]) >> 0x20) <<
               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)poly_record[6]) >> 0x10) +
              poly_record[7];
      if ((surface_flags & 0x2000000) == 0) {
        half_space = half_space + param_1[2];
      }
      grid_cell = param_1;

      if ((0x200 & surface_flags) == 0) {
        if (half_space < 0) {
          poly_index_ptr = poly_index_ptr + 2;
          poly_count = poly_count + -1;
          goto LAB_06027d50;
        }
      }
      else if (0 < half_space) {
        poly_index_ptr = poly_index_ptr + 2;
        poly_count = poly_count + -1;
        goto LAB_06027d50;
      }

      /* Plane 2 test */
      half_space = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)poly_record[8]) >> 0x20) <<
               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)poly_record[8]) >> 0x10) +
              poly_record[9];
      if ((surface_flags & 0x4000000) == 0) {
        half_space = half_space + param_1[2];
      }

      if ((0x400 & surface_flags) == 0) {
        if (half_space < 0) {
          poly_index_ptr = poly_index_ptr + 2;
          poly_count = poly_count + -1;
          goto LAB_06027d50;
        }
      }
      else if (0 < half_space) {
        poly_index_ptr = poly_index_ptr + 2;
        poly_count = poly_count + -1;
        goto LAB_06027d50;
      }

      /* Plane 3 test */
      half_space = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)poly_record[10]) >> 0x20) <<
               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)poly_record[10]) >> 0x10) +
              poly_record[0xb];
      if ((surface_flags & 0x8000000) == 0) {
        half_space = half_space + param_1[2];
      }

      if ((0x00000800 & surface_flags) == 0) {
        if (half_space < 0) {
          poly_index_ptr = poly_index_ptr + 2;
          poly_count = poly_count + -1;
          goto LAB_06027d50;
        }
      }
      else if (0 < half_space) {
        poly_index_ptr = poly_index_ptr + 2;
        poly_count = poly_count + -1;
        goto LAB_06027d50;
      }

      /* All 4 planes pass — polygon hit */
      grid_cell = (unsigned int *)(0x060A6000 + *(short *)(poly_index_ptr + (int)0x060BF000) * 0x34);
      hit_found = (unsigned int)DAT_06027e98;
      surface_flags = *grid_cell & hit_found;
      goto LAB_06027e6a;
    }

    /* Plane 0 sign-inverted test */
    if (half_space < 1) goto LAB_06027db6;
    poly_index_ptr = poly_index_ptr + 2;
    poly_count = poly_count + -1;
  } while( 1 );
}
#endif

/* track_polygon_collision_test -- test point against track collision polygons, return height */
unsigned int FUN_06027ede(param_1, param_2, param_3)
    int param_1;
    int *param_2;
    short *param_3;
{
  short search_id;
  long long height_a;
  long long height_b;
  char *poly_index_table;
  char *object_table;
  unsigned int result;
  short *search_ptr;
  int half_space;
  unsigned int poly_flags;
  unsigned int *poly_record;
  int search_index;
  unsigned int poly_offset;
  int poly_count;
  int position_x;
  int position_z;

  poly_index_table = (int *)0x060BF000; /* polygon index lookup table */
  object_table = (char *)0x060C2000;    /* object collision table */
  position_x = *param_2;
  position_z = param_2[2];

  if (CAR_COUNT == 2) {
    /* 2-player mode: search special override table at 0x06061270 */
    search_index = 0;
    search_ptr = (short *)0x06061270;
    while( 1 ) {
      search_id = *search_ptr;
      search_ptr = search_ptr + 1;
      if (search_id == 0) break;
      if (param_1 == search_id) {
        /* Match found — use override if car is before checkpoint 0x47 */
        if (*(int *)(CAR_PTR_CURRENT + (int)DAT_06027f56) < 0x47) {
          poly_count = (int)*(short *)((int)(0x06061240 + (search_index << 1)) + 2);
          *(short *)0x06063F50 = *(short *)(0x06061240 + (search_index << 1));
          goto LAB_06027f66;
        }
        break;
      }
      search_index = search_index + 2;
    }
    poly_count = 0;

LAB_06027f66:
    if (poly_count == 0) {
      /* No override — use standard object table */
      poly_count = (int)*(short *)(object_table + (((param_1 << 1) + 1) << 1));
      poly_offset = (unsigned int)(int)*(short *)(object_table + (param_1 << 2)) >> 1;
    }
    else {
      poly_offset = (unsigned int)(int)*(short *)0x06063F50 >> 1;
    }
  }
  else {
    /* Single player: direct object table lookup */
    poly_count = (int)*(short *)(0x060C2000 + ((param_1 << 1) + 1) << 1);
    poly_offset = (unsigned int)(int)*(short *)(0x060C2000 + (param_1 << 2)) >> 1;
  }

  /* Test point against each polygon's 4 half-space planes */
  search_index = 0;
  do {
    /* Each polygon record is 0x34 bytes at 0x060A6000 */
    poly_record = (unsigned int *)(0x060A6000 +
                      (unsigned int)*(unsigned short *)(poly_index_table + (poly_offset << 1)) * (0x00000034 & 0xffff));
    poly_flags = *poly_record;

    /* Plane 0: normal[0] * position_x + offset[0] */
    half_space = ((int)((unsigned long long)((long long)(int)poly_record[4] * (long long)position_x) >> 0x20) << 0x10 |
            (unsigned int)((long long)(int)poly_record[4] * (long long)position_x) >> 0x10) + poly_record[5];
    if ((poly_flags & (unsigned int)0x01000000) == 0) {
      half_space = half_space + position_z; /* add Z component if flag clear */
    }
    result = (unsigned int)PTR_DAT_06027fc0;
    if ((result & poly_flags) != 0) {
      half_space = -half_space; /* negate if sign flag set */
    }

    if (-1 < half_space) {
      /* Plane 1: normal[1] * position_x + offset[1] */
      half_space = ((int)((unsigned long long)((long long)(int)poly_record[6] * (long long)position_x) >> 0x20) << 0x10 |
              (unsigned int)((long long)(int)poly_record[6] * (long long)position_x) >> 0x10) + poly_record[7];
      if (((unsigned int)0x02000000 & poly_flags) == 0) {
        half_space = half_space + position_z;
      }
      result = (unsigned int)PTR_DAT_06027ffc;
      if ((result & poly_flags) != 0) {
        half_space = -half_space;
      }

      if (-1 < half_space) {
        /* Plane 2: normal[2] * position_x + offset[2] */
        half_space = ((int)((unsigned long long)((long long)(int)poly_record[8] * (long long)position_x) >> 0x20) << 0x10 |
                (unsigned int)((long long)(int)poly_record[8] * (long long)position_x) >> 0x10) + poly_record[9];
        if (((unsigned int)0x04000000 & poly_flags) == 0) {
          half_space = half_space + position_z;
        }
        result = (unsigned int)PTR_DAT_0602802c;
        if ((result & poly_flags) != 0) {
          half_space = -half_space;
        }

        if (-1 < half_space) {
          /* Plane 3: normal[3] * position_x + offset[3] */
          half_space = ((int)((unsigned long long)((long long)(int)poly_record[10] * (long long)position_x) >> 0x20) << 0x10
                  | (unsigned int)((long long)(int)poly_record[10] * (long long)position_x) >> 0x10) + poly_record[0xb];
          if ((0x08000000 & poly_flags) == 0) {
            half_space = half_space + position_z;
          }
          result = (unsigned int)DAT_0602805c;
          if ((result & poly_flags) != 0) {
            half_space = -half_space;
          }
          if (-1 < half_space) break; /* all 4 planes pass — point is inside polygon */
        }
      }
    }

    search_index = search_index + 1;
    poly_offset = poly_offset + 1;
  } while (search_index < poly_count);

  /* If hit found and output pointer provided, compute Y height from plane equation */
  if ((param_3 != (short *)0x0) && (poly_count != search_index)) {
    height_a = (long long)*(int *)((int)poly_record + 0x00000004) * (long long)position_x;
    height_b = (long long)*(int *)((int)poly_record + 0x00000008) * (long long)position_z;
    param_2[1] = ((int)((unsigned long long)height_a >> 0x20) << 0x10 | (unsigned int)height_a >> 0x10) +
                 ((int)((unsigned long long)height_b >> 0x20) << 0x10 | (unsigned int)height_b >> 0x10) +
                 *(int *)((int)poly_record + 0x0000000C);
    result = (poly_offset << 1);
    *param_3 = *(short *)(poly_index_table + result); /* output polygon ID */
  }

  return result;
}


/* FUN_06027CA4 -- original binary (570 bytes) */
__asm__(
    ".section .text.FUN_06027CA4, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06027CA4\n"
    ".global _FUN_06027ca4\n"
    ".type _FUN_06027CA4, @function\n"
    "_FUN_06027CA4:\n"
    "_FUN_06027ca4:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x2F, 0x96, 0x2F, 0x86, 0x4F, 0x22\n"  /* 0x06027CA4 */
    ".byte 0x2F, 0x56, 0x61, 0x42, 0xD2, 0x0F, 0x31, 0x2C, 0x41, 0x29, 0x41, 0x09, 0x41, 0x09, 0x41, 0x01\n"  /* 0x06027CB4 */
    ".byte 0x52, 0x42, 0xD3, 0x0D, 0x33, 0x28, 0x43, 0x29, 0x43, 0x09, 0x43, 0x09, 0x43, 0x01, 0x43, 0x08\n"  /* 0x06027CC4 */
    ".byte 0x43, 0x08, 0x43, 0x08, 0x31, 0x3C, 0xD2, 0x09, 0x60, 0x22, 0x88, 0x02, 0x8B, 0x2E, 0x2F, 0x16\n"  /* 0x06027CD4 */
    ".byte 0x6A, 0x13, 0xD1, 0x07, 0x2C, 0xCA, 0x60, 0x15, 0x20, 0x08, 0x89, 0x21, 0x3A, 0x00, 0x89, 0x09\n"  /* 0x06027CE4 */
    ".byte 0xAF, 0xF9, 0x7C, 0x02, 0x04, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0x06, 0x07, 0xEA, 0xD8\n"  /* 0x06027CF4 */
    ".byte 0x06, 0x06, 0x12, 0x70, 0xD1, 0x07, 0x61, 0x12, 0x90, 0x0B, 0x01, 0x1E, 0xE0, 0x46, 0x31, 0x07\n"  /* 0x06027D04 */
    ".byte 0x89, 0x0E, 0x4C, 0x00, 0xD0, 0x04, 0x30, 0xCC, 0xD1, 0x04, 0x62, 0x05, 0x6C, 0x01, 0xA0, 0x08\n"  /* 0x06027D14 */
    ".byte 0x21, 0x21, 0x01, 0xEC, 0x06, 0x07, 0xE9, 0x40, 0x06, 0x06, 0x12, 0x40, 0x06, 0x06, 0x3F, 0x50\n"  /* 0x06027D24 */
    ".byte 0x2C, 0xCA, 0x61, 0xF6, 0x2C, 0xC8, 0x89, 0x01, 0xA0, 0x08, 0x6D, 0x23, 0x62, 0x13, 0x42, 0x08\n"  /* 0x06027D34 */
    ".byte 0xD0, 0x05, 0x32, 0x0C, 0x6D, 0x21, 0x6D, 0xDD, 0x85, 0x21, 0x6C, 0x03, 0x4C, 0x15, 0x89, 0x05\n"  /* 0x06027D44 */
    ".byte 0xE0, 0x00, 0x63, 0x03, 0xA0, 0x87, 0xE6, 0x00, 0x06, 0x0C, 0x20, 0x00, 0xD0, 0x10, 0x05, 0xDD\n"  /* 0x06027D54 */
    ".byte 0xE6, 0x34, 0xD0, 0x10, 0x25, 0x6F, 0x05, 0x1A, 0x30, 0x5C, 0x66, 0x02, 0x70, 0x10, 0xEE, 0x01\n"  /* 0x06027D64 */
    ".byte 0x67, 0x06, 0x4E, 0x28, 0x62, 0x42, 0x4E, 0x18, 0x32, 0x7D, 0x69, 0x06, 0x5A, 0x42, 0x02, 0x0A\n"  /* 0x06027D74 */
    ".byte 0x03, 0x1A, 0x23, 0x2D, 0x26, 0xE8, 0x33, 0x9C, 0x8B, 0x00, 0x33, 0xAC, 0x9B, 0x06, 0x26, 0xB8\n"  /* 0x06027D84 */
    ".byte 0x89, 0x0A, 0x43, 0x15, 0x8B, 0x0D, 0x7D, 0x02, 0xAF, 0xD8, 0x7C, 0xFF, 0x01, 0x00, 0x00, 0x00\n"  /* 0x06027D94 */
    ".byte 0x06, 0x0B, 0xF0, 0x00, 0x06, 0x0A, 0x60, 0x00, 0x43, 0x11, 0x89, 0x02, 0x7D, 0x02, 0xAF, 0xCD\n"  /* 0x06027DA4 */
    ".byte 0x7C, 0xFF, 0x61, 0x43, 0x67, 0x06, 0x62, 0x12, 0x4E, 0x00, 0x32, 0x7D, 0x69, 0x06, 0x5A, 0x42\n"  /* 0x06027DB4 */
    ".byte 0x02, 0x0A, 0x03, 0x1A, 0x23, 0x2D, 0x26, 0xE8, 0x33, 0x9C, 0x8B, 0x00, 0x33, 0xAC, 0x9B, 0x06\n"  /* 0x06027DC4 */
    ".byte 0x26, 0xB8, 0x89, 0x05, 0x43, 0x15, 0x8B, 0x08, 0x7D, 0x02, 0xAF, 0xB7, 0x7C, 0xFF, 0x02, 0x00\n"  /* 0x06027DD4 */
    ".byte 0x43, 0x11, 0x89, 0x02, 0x7D, 0x02, 0xAF, 0xB1, 0x7C, 0xFF, 0x67, 0x06, 0x62, 0x42, 0x4E, 0x00\n"  /* 0x06027DE4 */
    ".byte 0x32, 0x7D, 0x69, 0x06, 0x5A, 0x42, 0x02, 0x0A, 0x03, 0x1A, 0x23, 0x2D, 0x26, 0xE8, 0x33, 0x9C\n"  /* 0x06027DF4 */
    ".byte 0x8B, 0x00, 0x33, 0xAC, 0x9A, 0x06, 0x26, 0xA8, 0x89, 0x05, 0x43, 0x15, 0x8B, 0x08, 0x7D, 0x02\n"  /* 0x06027E04 */
    ".byte 0xAF, 0x9C, 0x7C, 0xFF, 0x04, 0x00, 0x43, 0x11, 0x89, 0x02, 0x7D, 0x02, 0xAF, 0x96, 0x7C, 0xFF\n"  /* 0x06027E14 */
    ".byte 0x67, 0x06, 0x62, 0x42, 0x4E, 0x00, 0x32, 0x7D, 0x69, 0x06, 0x5A, 0x42, 0x02, 0x0A, 0x03, 0x1A\n"  /* 0x06027E24 */
    ".byte 0x23, 0x2D, 0x26, 0xE8, 0x33, 0x9C, 0x8B, 0x00, 0x33, 0xAC, 0xDA, 0x04, 0x26, 0xA8, 0x89, 0x07\n"  /* 0x06027E34 */
    ".byte 0x43, 0x15, 0x8B, 0x0A, 0x7D, 0x02, 0xAF, 0x81, 0x7C, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00\n"  /* 0x06027E44 */
    ".byte 0x43, 0x11, 0x89, 0x02, 0x7D, 0x02, 0xAF, 0x79, 0x7C, 0xFF, 0xD1, 0x0F, 0x31, 0x5C, 0x63, 0x12\n"  /* 0x06027E54 */
    ".byte 0x96, 0x18, 0x23, 0x69, 0x60, 0x33, 0x81, 0x46, 0xE0, 0x00, 0x36, 0x00, 0x89, 0x1A, 0x71, 0x30\n"  /* 0x06027E64 */
    ".byte 0x60, 0x11, 0x14, 0x04, 0x68, 0x03, 0x61, 0x53, 0xE0, 0x34, 0xDC, 0x08, 0x4C, 0x0B, 0x2F, 0x36\n"  /* 0x06027E74 */
    ".byte 0x63, 0xF6, 0x81, 0x47, 0xD6, 0x06, 0x60, 0x62, 0x65, 0xF6, 0x45, 0x15, 0x89, 0x0D, 0x91, 0x02\n"  /* 0x06027E84 */
    ".byte 0xA0, 0x0B, 0x01, 0x86, 0x00, 0xFF, 0x02, 0x5C, 0x06, 0x0A, 0x60, 0x00, 0x06, 0x02, 0xEC, 0xCC\n"  /* 0x06027E94 */
    ".byte 0x06, 0x07, 0xE9, 0x40, 0xD6, 0x08, 0x60, 0x62, 0x65, 0xF6, 0x45, 0x00, 0xD2, 0x07, 0x32, 0x5C\n"  /* 0x06027EA4 */
    ".byte 0x62, 0x21, 0x62, 0x2D, 0x02, 0x36, 0x4F, 0x26, 0x68, 0xF6, 0x69, 0xF6, 0x6A, 0xF6, 0x6B, 0xF6\n"  /* 0x06027EB4 */
    ".byte 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x06, 0x07, 0xE9, 0x40, 0x06, 0x06, 0x12, 0x8A\n"  /* 0x06027EC4 */
    ".byte 0x00, 0x09, 0x36, 0x00, 0x89, 0xFC, 0xAF, 0xD5, 0x00, 0x09\n"  /* 0x06027ED4 */
);

/* FUN_06027158 -- original binary (74 bytes) */
__asm__(
    ".section .text.FUN_06027158, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06027158\n"
    ".type _FUN_06027158, @function\n"
    "_FUN_06027158:\n"
    ".byte 0x4F, 0x22, 0xD6, 0x76, 0xE5, 0x08, 0xB0, 0xFB, 0x35, 0x6C, 0x4F, 0x26, 0x61, 0x52, 0x62, 0x62\n"  /* 0x06027158 */
    ".byte 0x61, 0x1B, 0x16, 0x11, 0xD0, 0x6F, 0x16, 0x23, 0x64, 0x02, 0xE3, 0x03, 0x74, 0x04, 0x65, 0x43\n"  /* 0x06027168 */
    ".byte 0x67, 0x63, 0x00, 0x28, 0x05, 0x7F, 0x05, 0x7F, 0x75, 0xF8, 0x00, 0x0A, 0x01, 0x1A, 0x21, 0x0D\n"  /* 0x06027178 */
    ".byte 0x00, 0x28, 0x05, 0x7F, 0x05, 0x7F, 0x14, 0x10, 0x43, 0x10, 0x00, 0x0A, 0x02, 0x1A, 0x22, 0x0D\n"  /* 0x06027188 */
    ".byte 0x14, 0x21, 0x8F, 0xEC, 0x74, 0x0C, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06027198 */
);

/* FUN_06026E94 -- original binary (74 bytes) */
__asm__(
    ".section .text.FUN_06026E94, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06026E94\n"
    ".global _FUN_06026e94\n"
    ".type _FUN_06026E94, @function\n"
    "_FUN_06026E94:\n"
    "_FUN_06026e94:\n"
    ".byte 0x4F, 0x22, 0xD6, 0x76, 0xE5, 0x08, 0xB2, 0x5D, 0x35, 0x6C, 0x4F, 0x26, 0x61, 0x52, 0x62, 0x62\n"  /* 0x06026E94 */
    ".byte 0x61, 0x1B, 0x16, 0x11, 0xD0, 0x6F, 0x16, 0x23, 0x64, 0x02, 0xE3, 0x03, 0x74, 0x04, 0x65, 0x43\n"  /* 0x06026EA4 */
    ".byte 0x67, 0x63, 0x00, 0x28, 0x05, 0x7F, 0x05, 0x7F, 0x75, 0xF8, 0x00, 0x0A, 0x01, 0x1A, 0x21, 0x0D\n"  /* 0x06026EB4 */
    ".byte 0x00, 0x28, 0x05, 0x7F, 0x05, 0x7F, 0x14, 0x10, 0x43, 0x10, 0x00, 0x0A, 0x02, 0x1A, 0x22, 0x0D\n"  /* 0x06026EC4 */
    ".byte 0x14, 0x21, 0x8F, 0xEC, 0x74, 0x0C, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x06026ED4 */
);

/* FUN_060271A2 -- original binary (76 bytes) */
__asm__(
    ".section .text.FUN_060271A2, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_060271A2\n"
    ".global _FUN_060271a2\n"
    ".type _FUN_060271A2, @function\n"
    "_FUN_060271A2:\n"
    "_FUN_060271a2:\n"
    ".byte 0x4F, 0x22, 0xD6, 0x63, 0xE5, 0x04, 0xB0, 0xD6, 0x35, 0x6C, 0x4F, 0x26, 0x61, 0x52, 0x62, 0x62\n"  /* 0x060271A2 */
    ".byte 0x61, 0x1B, 0x16, 0x12, 0xD0, 0x5D, 0x16, 0x23, 0x64, 0x02, 0xE3, 0x03, 0x65, 0x43, 0x67, 0x63\n"  /* 0x060271B2 */
    ".byte 0x00, 0x28, 0x05, 0x7F, 0x75, 0x04, 0x05, 0x7F, 0x75, 0xF4, 0x00, 0x0A, 0x01, 0x1A, 0x21, 0x0D\n"  /* 0x060271C2 */
    ".byte 0x00, 0x28, 0x05, 0x7F, 0x75, 0x04, 0x05, 0x7F, 0x14, 0x10, 0x43, 0x10, 0x00, 0x0A, 0x02, 0x1A\n"  /* 0x060271D2 */
    ".byte 0x22, 0x0D, 0x14, 0x22, 0x8F, 0xEA, 0x74, 0x0C, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x060271E2 */
);

/* FUN_06026362 -- original binary (138 bytes) */
__asm__(
    ".section .text.FUN_06026362, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06026362\n"
    ".type _FUN_06026362, @function\n"
    "_FUN_06026362:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0xDC, 0x0C, 0xED, 0x0A, 0xDE, 0x0C, 0xD7, 0x0D, 0xD5, 0x0D\n"  /* 0x06026362 */
    ".byte 0xE4, 0x00, 0x66, 0x4D, 0x60, 0x6D, 0x40, 0x08, 0x40, 0x00, 0x30, 0xCC, 0x85, 0x03, 0xA0, 0x14\n"  /* 0x06026372 */
    ".byte 0x60, 0x0D, 0xA0, 0x01, 0x62, 0x4D, 0x62, 0x5D, 0xA0, 0x27, 0x2E, 0x21, 0xA0, 0x01, 0x62, 0x4D\n"  /* 0x06026382 */
    ".byte 0x62, 0x5D, 0xA0, 0x22, 0x27, 0x21, 0xA0, 0x20, 0x00, 0x09, 0x06, 0x06, 0x0F, 0x2C, 0x06, 0x06\n"  /* 0x06026392 */
    ".byte 0x0D, 0x2A, 0x06, 0x06, 0x0D, 0x34, 0x00, 0x00, 0x80, 0x00, 0x91, 0x09, 0x30, 0x18, 0xE1, 0x0C\n"  /* 0x060263A2 */
    ".byte 0x30, 0x12, 0x89, 0xF0, 0x40, 0x00, 0x61, 0x03, 0xC7, 0x02, 0x00, 0x1D, 0x00, 0x23, 0x00, 0x09\n"  /* 0x060263B2 */
    ".byte 0x00, 0x8A, 0xFF, 0xC2, 0xFF, 0xC2, 0xFF, 0xCC, 0xFF, 0xCC, 0xFF, 0xC6, 0xFF, 0xC6, 0xFF, 0xC6\n"  /* 0x060263C2 */
    ".byte 0xFF, 0xC6, 0xFF, 0xD0, 0xFF, 0xD0, 0xFF, 0xD0, 0xFF, 0xD0, 0x76, 0x01, 0x62, 0x6D, 0x32, 0xD3\n"  /* 0x060263D2 */
    ".byte 0x8B, 0xC8, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x060263E2 */
);
