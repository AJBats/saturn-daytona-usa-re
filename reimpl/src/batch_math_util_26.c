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
void FUN_06026518(unsigned int input_flags)
{
    register int vdp_attr_set asm("r3") = 0x060284AE;
    register int vdp_cmd_build asm("r2") = 0x06028400;

    if ((input_flags & 4) != 0) {
        /* Static mode: fixed tile IDs at fixed position */
        (*(int(*)())vdp_attr_set)(8, 0x2A0, 0x90, 0x06059128);
        (*(void(*)())vdp_attr_set)(8, (int)DAT_06026576, 0x90, 0x06059128);
        return;
    }
    /* Dynamic mode: read tile/offset from speed display state */
    (*(int(*)())vdp_cmd_build)(8, *(int *)0x06063B80, 0x2A0,
        *(int *)0x06063B84 + (int)DAT_06026578, 0x06063B80);
    (*(void(*)())vdp_cmd_build)(8, *(int *)0x06063B88, (int)DAT_06026576,
        *(int *)0x06063B8C + (int)DAT_06026578);
}

/* input_descriptor_table_refresh -- Rebuild input descriptor table for given mode.
 * Clears all input descriptor pairs at 0x060610BC, re-detects connected
 * peripherals (mode 4 calls input_peripheral_detect/scan), then applies
 * bitmask OR from dispatch tables (0x06061170 for primary/10 slots,
 * 0x06061184 for secondary/8 slots). If mode 4, writes back descriptor
 * state for next frame. param_1=mode, param_2=descriptor count. */
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

/* hud_gear_selector_render -- Render gear/transmission selection HUD.
 * Draws base gear sprites via VDP1 attribute setter (0x060284AE), then
 * dispatches on controller input (0x06063D9A) to cycle through gear
 * selections (range 0x12-0x14 at 0x06089EDA). On confirm (DAT_0602672e
 * or 0x100), sets render mode 6 at 0x06061198 and draws 3 sprites.
 * On D-pad left/right (DAT_0602684a/PTR_0602684c), shifts selection ±2.
 * If display bit 4 set, uses static mode; otherwise dynamic from 0x06063B88. */
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

void FUN_060268b0(param_1)
    short param_1;
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  char *puVar5;

  int iVar6;

  int iVar7;

  puVar5 = (int *)0x06061238;

  puVar4 = (char *)0x0606123A;

  puVar3 = (char *)0x0607864C;

  puVar2 = (int *)0x0606123C;

  puVar1 = (int *)0x060283E0;

  iVar7 = (int)DAT_06026922;

  if (param_1 == 0) {

    iVar6 = CAR_COUNT;

    if (iVar6 == 0) {

      if (*(short *)0x06061238 < 0x36) {

        if ((unsigned int)(*(short *)(0x060597B8 + *(short *)(0x06061238 << 1)) * 3) <=

            VBLANK_COUNTER) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x36) &&

              ((unsigned int)(*(short *)(0x060597B8 + *(short *)(0x06061238 << 1)) * 3) <=

               VBLANK_COUNTER)) {

        (*(int(*)())0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x060611FC + (char)((int *)0x060591BA)[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x060597B8 + (*(short *)puVar5 + -1) << 1) +

                        (int)((char *)0x060595D8)

                                   [(int)*(short *)puVar4 +

                                    (char)((int *)0x060591BA)[*(short *)puVar5 + -1] * 0x20]) * 3) <=

                 *(unsigned int *)puVar3 &&

                (((char *)0x060595D8)

                       [(int)*(short *)puVar4 + (char)((int *)0x060591BA)[*(short *)puVar5 + -1] * 0x20

                       ] != -1)) && (*(short *)puVar4 < 0x20))) {

          FUN_06026ca4(*(int *)

                        (0x060611FC + (char)((int *)0x060591BA)[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    else if (iVar6 == 1) {

      if (*(short *)0x06061238 < 0x3a) {

        if ((unsigned int)(*(short *)(0x060591F0 + *(short *)(0x06061238 << 1)) * 3) <=

            VBLANK_COUNTER) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x3a) &&

              ((unsigned int)(*(short *)(0x060591F0 + *(short *)(0x06061238 << 1)) * 3) <=

               VBLANK_COUNTER)) {

        (*(int(*)())0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x0606119C + (char)((int *)0x0605914C)[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x060591F0 + (*(short *)puVar5 + -1) << 1) +

                        (int)((char *)0x06059266)

                                   [(int)*(short *)puVar4 +

                                    (int)(short)((char)((int *)0x0605914C)[*(short *)puVar5 + -1] *

                                                0x24)]) * 3) <= *(unsigned int *)puVar3 &&

                (((char *)0x06059266)

                       [(int)*(short *)puVar4 +

                        (int)(short)((char)((int *)0x0605914C)[*(short *)puVar5 + -1] * 0x24)] != -1))

               && (*(short *)puVar4 < 0x24))) {

          FUN_06026ca4(*(int *)

                        (0x0606119C + (char)((int *)0x0605914C)[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    else if (iVar6 == 2) {

      if (*(short *)0x06061238 < 0x34) {

        if ((unsigned int)(*(short *)(0x0605956E + *(short *)(0x06061238 << 1)) * 3) <=

            VBLANK_COUNTER) {

          *(short *)0x06061238 = *(short *)0x06061238 + 1;

          *(short *)puVar4 = 0;

          (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,0x06059826);

          *(short *)puVar2 = 1;

        }

      }

      else if ((*(short *)0x06061238 == 0x34) &&

              ((unsigned int)(*(short *)(0x0605956E + *(short *)(0x06061238 << 1)) * 3) <=

               VBLANK_COUNTER)) {

        (*(int(*)())0x060283E0)(0xc,iVar7,0x0000F000,0x06059826);

        *(short *)puVar5 = 0;

        *(short *)puVar4 = 0;

        *(short *)0x0606123E = 1;

      }

      if (*(short *)puVar2 != 0) {

        (*(int(*)())puVar1)(0xc,iVar7,0x0000F000,

                          *(int *)

                           (0x060611DC + (char)((int *)0x06059186)[*(short *)puVar5 + -1] * 4));

      }

      *(short *)puVar2 = 0;

      if (0 < *(short *)puVar5) {

        while ((((unsigned int)(((int)*(short *)(0x0605956E + (*(short *)puVar5 + -1) << 1) +

                        (int)((char *)0x060594A6)

                                   [(int)*(short *)puVar4 +

                                    (((int)(char)((int *)0x06059186)[*(short *)puVar5 + -1] & 0xffffU)

                                     * 0x19 & 0xff)]) * 3) <= *(unsigned int *)puVar3 &&

                (((char *)0x060594A6)

                       [(int)*(short *)puVar4 +

                        (((int)(char)((int *)0x06059186)[*(short *)puVar5 + -1] & 0xffffU) * 0x19 &

                        0xff)] != -1)) && (*(short *)puVar4 < 0x19))) {

          FUN_06026ca4(*(int *)

                        (0x060611DC + (char)((int *)0x06059186)[*(short *)puVar5 + -1] * 4),

                       (int)*(short *)puVar4);

          *(short *)puVar4 = *(short *)puVar4 + 1;

        }

      }

    }

    if (*(short *)0x0606123E != 0) {

      *(int *)puVar3 = 0;

      *(short *)0x0606123E = 0;

    }

  }

  else {

    *(short *)0x0606123C = 0;

    *(short *)puVar4 = 0;

    *(short *)puVar5 = 0;

    *(short *)0x0606123E = 0;

    *(int *)puVar3 = 0;

  }

  return;

}

/* hud_digit_render -- Render a single HUD digit sprite.
 * Reads digit value from (param_1 + param_2), builds 2-byte sprite data
 * with digit value and zero terminator, calls sprite command writer.
 * PTR_DAT_06026cd4 is the base command offset for digit sprites. */
void FUN_06026ca4(int param_1, short param_2)
{
    char sprite_data[2];
    sprite_data[0] = *(char *)(param_1 + param_2);
    sprite_data[1] = 0;

    (*(int(*)())0x060283E0)(0xc, ((int)param_2 + (int)PTR_DAT_06026cd4) << 1,
                            0x0000E000, sprite_data);
}

/* matrix_push -- Push current 3x4 matrix onto stack.
 * Copies 12 ints (3x4 matrix) from current stack top to next slot,
 * then advances stack pointer at 0x06089EDC by 12 ints (48 bytes). */
void FUN_06026dbc(void)
{
  int *mtx = *(int **)0x06089EDC;          /* current matrix stack top */
  *(int **)0x06089EDC = mtx + 0xc;         /* advance stack pointer */

  /* Copy all 12 elements to new top */
  mtx[0xc] = mtx[0];  mtx[0xd] = mtx[1];  mtx[0xe] = mtx[2];
  mtx[0xf] = mtx[3];  mtx[0x10] = mtx[4]; mtx[0x11] = mtx[5];
  mtx[0x12] = mtx[6]; mtx[0x13] = mtx[7]; mtx[0x14] = mtx[8];
  mtx[0x15] = mtx[9]; mtx[0x16] = mtx[10]; mtx[0x17] = mtx[0xb];
}

/* matrix_reset -- Reset matrix stack and load identity matrix.
 * Sets stack pointer (0x06089EDC) to base (0x06089EE0), then writes
 * 3x4 identity matrix: diagonal = 0x10000 (1.0 in 16.16 fixed-point),
 * all other elements = 0. Translation column (elements 9-11) = 0. */
void FUN_06026e02(void)
{
  int *mtx = (int *)0x06089EE0;            /* matrix stack base */
  *(int **)0x06089EDC = mtx;               /* reset stack pointer */

  /* 3x3 identity (16.16 fixed-point) + zero translation */
  mtx[0] = 0x00010000;  mtx[1] = 0;          mtx[2] = 0;
  mtx[3] = 0;           mtx[4] = 0x00010000;  mtx[5] = 0;
  mtx[6] = 0;           mtx[7] = 0;           mtx[8] = 0x00010000;
  mtx[9] = 0;           mtx[10] = 0;          mtx[0xb] = 0;
}

/* matrix_set_identity -- Set current matrix stack entry to identity.
 * Reads matrix pointer from 0x06089EDC (current matrix stack top).
 * Sets 4x3 matrix: diagonal = 0x10000 (1.0 in 16.16 fixed-point),
 * all other entries = 0. Used to reset transformations. */
void FUN_06026e0c(void)
{
    int identity = 0x00010000;  /* 1.0 in 16.16 fixed-point */
    int *mtx = *(int **)0x06089EDC;  /* current matrix stack entry */

    mtx[0]  = identity;  mtx[1]  = 0;  mtx[2]  = 0;
    mtx[3]  = 0;         mtx[4]  = identity;  mtx[5]  = 0;
    mtx[6]  = 0;         mtx[7]  = 0;  mtx[8]  = identity;
    mtx[9]  = 0;         mtx[10] = 0;  mtx[0xb] = 0;
}

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

    uVar6 = uVar5 ^ uVar12;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar5 & 0xffff);

    iVar4 = (uVar12 >> 0x10) * (uVar5 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar4 + (uVar12 & 0xffff) * (uVar5 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar13 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar13 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = *(unsigned int *)(puVar8 + 4);

    uVar5 = puVar10[1];

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar15 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar15 + (uVar3 << 16);

    uVar5 = iVar2 + (unsigned int)(uVar14 < uVar15) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar14 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + uVar12;

    }

    uVar6 = *(unsigned int *)(puVar8 + 8);

    uVar5 = puVar10[2];

    puVar10 = puVar10 + 3;

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar13 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar13 + (uVar3 << 16);

    uVar5 = iVar2 + (unsigned int)(uVar15 < uVar13) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar15 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + uVar12;

    }

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

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[1];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[1];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

unsigned int FUN_06026ede()
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

  piVar10 = (int *)(0x0608A4E0 + 4);

  puVar11 = (unsigned int *)0x0608A4E0;

  math_sin_cos();

  puVar11[2] = -*piVar10;

  puVar7 = (int *)0x06089EDC;

  puVar11[3] = *puVar11;

  puVar9 = *(unsigned int **)puVar7;

  iVar8 = 3;

  do {

    uVar13 = *puVar9;

    uVar12 = *puVar11;

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[2];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[2];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[2] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

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

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[1];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[1];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

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

      uVar9 = uVar7 ^ uVar5;

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      if ((int)uVar5 < 0) {

        uVar5 = -uVar5;

      }

      uVar2 = (uVar5 & 0xffff) * (uVar7 & 0xffff);

      iVar3 = (uVar5 >> 0x10) * (uVar7 & 0xffff);

      iVar1 = 0;

      uVar14 = iVar3 + (uVar5 & 0xffff) * (uVar7 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar17 = uVar2 + (uVar14 << 16);

      uVar5 = iVar1 + (unsigned int)(uVar17 < uVar2) + (uVar14 >> 0x10) + (uVar5 >> 0x10) * (uVar7 >> 0x10);

      if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

        uVar5 = ~uVar5;

        if (uVar17 == 0) {

          uVar5 = uVar5 + 1;

        }

        else {

          uVar17 = ~uVar17 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar17 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar17 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      uVar9 = puVar12[1];

      uVar7 = puVar10[3];

      uVar14 = uVar9 ^ uVar7;

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar19 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

      iVar3 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

      iVar1 = 0;

      uVar2 = iVar3 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar18 = uVar19 + (uVar2 << 16);

      uVar7 = iVar1 + (unsigned int)(uVar18 < uVar19) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

      if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar18 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar18 = ~uVar18 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar18 = uVar17 + uVar18;

        uVar5 = uVar7 + (uVar18 < uVar17) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar18 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar18 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar18 = uVar17 + uVar18;

        uVar5 = uVar7 + (uVar18 < uVar17) + uVar5;

      }

      iVar6 = iVar6 + -1;

      in_sr = uVar11 & 0xfffffffe;

      uVar9 = puVar12[2];

      uVar7 = puVar10[6];

      uVar14 = uVar9 ^ uVar7;

      if ((int)uVar9 < 0) {

        uVar9 = -uVar9;

      }

      if ((int)uVar7 < 0) {

        uVar7 = -uVar7;

      }

      uVar17 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

      iVar3 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

      iVar1 = 0;

      uVar2 = iVar3 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

      if (iVar3 != 0) {

        iVar1 = 0x10000;

      }

      uVar19 = uVar17 + (uVar2 << 16);

      uVar7 = iVar1 + (unsigned int)(uVar19 < uVar17) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

      if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

        uVar7 = ~uVar7;

        if (uVar19 == 0) {

          uVar7 = uVar7 + 1;

        }

        else {

          uVar19 = ~uVar19 + 1;

        }

      }

      if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

        uVar19 = uVar18 + uVar19;

        uVar5 = uVar7 + (uVar19 < uVar18) + (uVar5 & 0xffff);

        if ((int)uVar5 < -0x8000) {

          uVar5 = 0xffff8000;

          uVar19 = 0;

        }

        if (0x7fff < (int)uVar5) {

          uVar5 = 0x7fff;

          uVar19 = 0xffffffff;

        }

        uVar5 = uVar5 & 0xffff;

      }

      else {

        uVar19 = uVar18 + uVar19;

        uVar5 = uVar7 + (uVar19 < uVar18) + uVar5;

      }

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

    uVar9 = uVar7 ^ uVar5;

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar2 = (uVar5 & 0xffff) * (uVar7 & 0xffff);

    iVar1 = (uVar5 >> 0x10) * (uVar7 & 0xffff);

    iVar6 = 0;

    uVar14 = iVar1 + (uVar5 & 0xffff) * (uVar7 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar17 = uVar2 + (uVar14 << 16);

    uVar5 = iVar6 + (unsigned int)(uVar17 < uVar2) + (uVar14 >> 0x10) + (uVar5 >> 0x10) * (uVar7 >> 0x10);

    if ((int)-(unsigned int)((int)uVar9 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar17 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    uVar9 = puVar13[1];

    uVar7 = puVar10[8];

    uVar14 = uVar9 ^ uVar7;

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    uVar19 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

    iVar1 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

    iVar6 = 0;

    uVar2 = iVar1 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar18 = uVar19 + (uVar2 << 16);

    uVar7 = iVar6 + (unsigned int)(uVar18 < uVar19) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

    if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

      uVar7 = ~uVar7;

      if (uVar18 == 0) {

        uVar7 = uVar7 + 1;

      }

      else {

        uVar18 = ~uVar18 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      uVar18 = uVar17 + uVar18;

      uVar5 = uVar7 + (uVar18 < uVar17) + (uVar5 & 0xffff);

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar18 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar18 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    else {

      uVar18 = uVar17 + uVar18;

      uVar5 = uVar7 + (uVar18 < uVar17) + uVar5;

    }

    iVar8 = iVar8 + -1;

    uVar9 = puVar13[2];

    puVar13 = puVar13 + 3;

    uVar7 = puVar10[9];

    uVar14 = uVar9 ^ uVar7;

    if ((int)uVar9 < 0) {

      uVar9 = -uVar9;

    }

    if ((int)uVar7 < 0) {

      uVar7 = -uVar7;

    }

    uVar17 = (uVar7 & 0xffff) * (uVar9 & 0xffff);

    iVar1 = (uVar7 >> 0x10) * (uVar9 & 0xffff);

    iVar6 = 0;

    uVar2 = iVar1 + (uVar7 & 0xffff) * (uVar9 >> 0x10);

    if (iVar1 != 0) {

      iVar6 = 0x10000;

    }

    uVar19 = uVar17 + (uVar2 << 16);

    uVar7 = iVar6 + (unsigned int)(uVar19 < uVar17) + (uVar2 >> 0x10) + (uVar7 >> 0x10) * (uVar9 >> 0x10);

    if ((int)-(unsigned int)((int)uVar14 < 0) < 0) {

      uVar7 = ~uVar7;

      if (uVar19 == 0) {

        uVar7 = uVar7 + 1;

      }

      else {

        uVar19 = ~uVar19 + 1;

      }

    }

    if (((unsigned char)(uVar11 >> 1) & 1) == 1) {

      uVar19 = uVar18 + uVar19;

      uVar5 = uVar7 + (uVar19 < uVar18) + (uVar5 & 0xffff);

      if ((int)uVar5 < -0x8000) {

        uVar5 = 0xffff8000;

        uVar19 = 0;

      }

      if (0x7fff < (int)uVar5) {

        uVar5 = 0x7fff;

        uVar19 = 0xffffffff;

      }

      uVar5 = uVar5 & 0xffff;

    }

    else {

      uVar19 = uVar18 + uVar19;

      uVar5 = uVar7 + (uVar19 < uVar18) + uVar5;

    }

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

void FUN_06026ffc(param_1, param_2)
    unsigned int *param_1;
    int *param_2;
{

  unsigned int uVar1;

  unsigned int uVar2;

  int iVar3;

  unsigned int uVar4;

  unsigned int uVar5;

  int *piVar6;

  unsigned int uVar7;

  int iVar8;

  int iVar9;

  unsigned int *puVar10;

  unsigned int *puVar11;

  int *piVar12;

  unsigned int in_sr = 0;

  unsigned int uVar13;

  unsigned int uVar14;

  unsigned int uVar15;

  unsigned int uVar16;

  puVar10 = *(unsigned int **)0x06089EDC;

  puVar11 = puVar10 + 9;

  iVar9 = 3;

  piVar6 = (int *)0x0608A520;

  do {

    piVar12 = piVar6;

    uVar4 = *puVar10;

    uVar13 = *param_1;

    uVar5 = uVar4 ^ uVar13;

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar7 = (uVar13 & 0xffff) * (uVar4 & 0xffff);

    iVar3 = (uVar13 >> 0x10) * (uVar4 & 0xffff);

    iVar8 = 0;

    uVar1 = iVar3 + (uVar13 & 0xffff) * (uVar4 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar14 = uVar7 + (uVar1 << 16);

    uVar13 = iVar8 + (unsigned int)(uVar14 < uVar7) + (uVar1 >> 0x10) + (uVar13 >> 0x10) * (uVar4 >> 0x10);

    if ((int)-(unsigned int)((int)uVar5 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar14 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar5 = puVar10[1];

    uVar4 = param_1[1];

    uVar1 = uVar5 ^ uVar4;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    uVar2 = (uVar4 & 0xffff) * (uVar5 & 0xffff);

    iVar3 = (uVar4 >> 0x10) * (uVar5 & 0xffff);

    iVar8 = 0;

    uVar7 = iVar3 + (uVar4 & 0xffff) * (uVar5 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar15 = uVar2 + (uVar7 << 16);

    uVar4 = iVar8 + (unsigned int)(uVar15 < uVar2) + (uVar7 >> 0x10) + (uVar4 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar4 = ~uVar4;

      if (uVar15 == 0) {

        uVar4 = uVar4 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar13 = uVar4 + (uVar15 < uVar14) + (uVar13 & 0xffff);

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar13 = uVar4 + (uVar15 < uVar14) + uVar13;

    }

    uVar7 = *puVar11;

    puVar11 = puVar11 + 1;

    uVar5 = puVar10[2];

    puVar10 = puVar10 + 3;

    uVar4 = param_1[2];

    uVar1 = uVar5 ^ uVar4;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar4 < 0) {

      uVar4 = -uVar4;

    }

    uVar2 = (uVar4 & 0xffff) * (uVar5 & 0xffff);

    iVar3 = (uVar4 >> 0x10) * (uVar5 & 0xffff);

    iVar8 = 0;

    uVar14 = iVar3 + (uVar4 & 0xffff) * (uVar5 >> 0x10);

    if (iVar3 != 0) {

      iVar8 = 0x10000;

    }

    uVar16 = uVar2 + (uVar14 << 16);

    uVar4 = iVar8 + (unsigned int)(uVar16 < uVar2) + (uVar14 >> 0x10) + (uVar4 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar4 = ~uVar4;

      if (uVar16 == 0) {

        uVar4 = uVar4 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar16 = uVar15 + uVar16;

      uVar13 = uVar4 + (uVar16 < uVar15) + (uVar13 & 0xffff);

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    else {

      uVar16 = uVar15 + uVar16;

      uVar13 = uVar4 + (uVar16 < uVar15) + uVar13;

    }

    iVar9 = iVar9 + -1;

    in_sr = in_sr & 0xfffffffe;

    *piVar12 = (uVar13 << 0x10 | uVar16 >> 0x10) + uVar7;

    piVar6 = piVar12 + 1;

  } while (iVar9 != 0);

  iVar9 = piVar12[-1];

  iVar8 = *piVar12;

  *param_2 = piVar12[-2];

  param_2[1] = iVar9;

  param_2[2] = iVar8;

  return;

}

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

/* matrix_stack_reset_identity -- Reset matrix stack and load identity matrix.
 * Sets stack pointer to base (0x0608A530), fills 4x3 matrix with identity:
 * diagonal = 0x10000 (1.0 in 16.16 fixed-point), rest = 0. */
void FUN_060270c6()
{
    int *mtx = (int *)0x0608A530;
    *(int **)0x0608A52C = (int *)0x0608A530;    /* reset stack pointer to base */
    char *one = (int *)0x00010000;               /* 1.0 in 16.16 fixed-point */
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

    uVar6 = uVar5 ^ uVar12;

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar5 & 0xffff);

    iVar4 = (uVar12 >> 0x10) * (uVar5 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar4 + (uVar12 & 0xffff) * (uVar5 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar13 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar13 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar5 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar13 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar13 = ~uVar13 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar13 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar13 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = *(unsigned int *)(puVar8 + 4);

    uVar5 = puVar10[1];

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar15 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar15 + (uVar3 << 16);

    uVar5 = iVar2 + (unsigned int)(uVar14 < uVar15) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar14 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar14 = uVar13 + uVar14;

      uVar12 = uVar5 + (uVar14 < uVar13) + uVar12;

    }

    uVar6 = *(unsigned int *)(puVar8 + 8);

    uVar5 = puVar10[2];

    puVar10 = puVar10 + 3;

    uVar1 = uVar6 ^ uVar5;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar5 < 0) {

      uVar5 = -uVar5;

    }

    uVar13 = (uVar5 & 0xffff) * (uVar6 & 0xffff);

    iVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar4 + (uVar5 & 0xffff) * (uVar6 >> 0x10);

    if (iVar4 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar13 + (uVar3 << 16);

    uVar5 = iVar2 + (unsigned int)(uVar15 < uVar13) + (uVar3 >> 0x10) + (uVar5 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar5 = ~uVar5;

      if (uVar15 == 0) {

        uVar5 = uVar5 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar5 + (uVar15 < uVar14) + uVar12;

    }

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

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[1];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[1];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[1] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

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

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[2];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[2];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

    *puVar9 = uVar12 << 0x10 | uVar15 >> 0x10;

    iVar8 = iVar8 + -1;

    in_sr = in_sr & 0xfffffffe;

    puVar9[2] = uVar13 << 0x10 | uVar17 >> 0x10;

    puVar9 = puVar9 + 3;

  } while (iVar8 != 0);

  return uVar13;

}

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

    uVar6 = uVar13 ^ uVar12;

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    if ((int)uVar12 < 0) {

      uVar12 = -uVar12;

    }

    uVar3 = (uVar12 & 0xffff) * (uVar13 & 0xffff);

    iVar5 = (uVar12 >> 0x10) * (uVar13 & 0xffff);

    iVar2 = 0;

    uVar1 = iVar5 + (uVar12 & 0xffff) * (uVar13 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar14 = uVar3 + (uVar1 << 16);

    uVar12 = iVar2 + (unsigned int)(uVar14 < uVar3) + (uVar1 >> 0x10) + (uVar12 >> 0x10) * (uVar13 >> 0x10);

    if ((int)-(unsigned int)((int)uVar6 < 0) < 0) {

      uVar12 = ~uVar12;

      if (uVar14 == 0) {

        uVar12 = uVar12 + 1;

      }

      else {

        uVar14 = ~uVar14 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar14 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar14 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    uVar6 = puVar9[1];

    uVar13 = puVar11[1];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar16 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar15 = uVar16 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar15 < uVar16) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar15 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar15 = ~uVar15 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + (uVar12 & 0xffff);

      if ((int)uVar12 < -0x8000) {

        uVar12 = 0xffff8000;

        uVar15 = 0;

      }

      if (0x7fff < (int)uVar12) {

        uVar12 = 0x7fff;

        uVar15 = 0xffffffff;

      }

      uVar12 = uVar12 & 0xffff;

    }

    else {

      uVar15 = uVar14 + uVar15;

      uVar12 = uVar13 + (uVar15 < uVar14) + uVar12;

    }

    uVar6 = *puVar9;

    uVar13 = puVar11[2];

    uVar1 = uVar6 ^ uVar13;

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    if ((int)uVar13 < 0) {

      uVar13 = -uVar13;

    }

    uVar14 = (uVar13 & 0xffff) * (uVar6 & 0xffff);

    iVar5 = (uVar13 >> 0x10) * (uVar6 & 0xffff);

    iVar2 = 0;

    uVar3 = iVar5 + (uVar13 & 0xffff) * (uVar6 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar16 = uVar14 + (uVar3 << 16);

    uVar13 = iVar2 + (unsigned int)(uVar16 < uVar14) + (uVar3 >> 0x10) + (uVar13 >> 0x10) * (uVar6 >> 0x10);

    if ((int)-(unsigned int)((int)uVar1 < 0) < 0) {

      uVar13 = ~uVar13;

      if (uVar16 == 0) {

        uVar13 = uVar13 + 1;

      }

      else {

        uVar16 = ~uVar16 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      if ((int)uVar13 < -0x8000) {

        uVar13 = 0xffff8000;

        uVar16 = 0;

      }

      if (0x7fff < (int)uVar13) {

        uVar13 = 0x7fff;

        uVar16 = 0xffffffff;

      }

      uVar13 = uVar13 & 0xffff;

    }

    uVar1 = puVar9[1];

    uVar6 = puVar11[3];

    uVar3 = uVar1 ^ uVar6;

    if ((int)uVar1 < 0) {

      uVar1 = -uVar1;

    }

    if ((int)uVar6 < 0) {

      uVar6 = -uVar6;

    }

    uVar4 = (uVar6 & 0xffff) * (uVar1 & 0xffff);

    iVar5 = (uVar6 >> 0x10) * (uVar1 & 0xffff);

    iVar2 = 0;

    uVar14 = iVar5 + (uVar6 & 0xffff) * (uVar1 >> 0x10);

    if (iVar5 != 0) {

      iVar2 = 0x10000;

    }

    uVar17 = uVar4 + (uVar14 << 16);

    uVar6 = iVar2 + (unsigned int)(uVar17 < uVar4) + (uVar14 >> 0x10) + (uVar6 >> 0x10) * (uVar1 >> 0x10);

    if ((int)-(unsigned int)((int)uVar3 < 0) < 0) {

      uVar6 = ~uVar6;

      if (uVar17 == 0) {

        uVar6 = uVar6 + 1;

      }

      else {

        uVar17 = ~uVar17 + 1;

      }

    }

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {

      uVar17 = uVar16 + uVar17;

      uVar6 = uVar6 + (uVar17 < uVar16) + (uVar13 & 0xffff);

      if ((int)uVar6 < -0x8000) {

        uVar6 = 0xffff8000;

        uVar17 = 0;

      }

      if (0x7fff < (int)uVar6) {

        uVar6 = 0x7fff;

        uVar17 = 0xffffffff;

      }

      uVar13 = uVar6 & 0xffff | uVar13 & 0xffff0000;

    }

    else {

      uVar17 = uVar16 + uVar17;

      uVar13 = uVar6 + (uVar17 < uVar16) + uVar13;

    }

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

void FUN_06027ca4(param_1, param_2)
    unsigned int *param_1;
    int param_2;
{

  short sVar1;

  unsigned int *puVar2;

  short uVar3;

  unsigned int *puVar4;

  short *psVar5;

  unsigned int uVar6;

  int iVar7;

  unsigned int uVar8;

  int iVar9;

  char *puVar10;

  puVar4 = (unsigned int *)(((unsigned int)(0x04000000 + *param_1) >> 0x15) +

                   (0x03FFFFFF - param_1[2] >> 0x15) << 6);

  if (CAR_COUNT == 2) {

    iVar9 = 0;

    psVar5 = (short *)0x06061270;

    while( 1 ) {

      sVar1 = *psVar5;

      psVar5 = psVar5 + 1;

      if ((unsigned int *)(int)sVar1 == (unsigned int *)0x0) break;

      if (puVar4 == (unsigned int *)(int)sVar1) {

        if (*(int *)(CAR_PTR_CURRENT + (int)DAT_06027d26) < 0x47) {

          sVar1 = *(short *)(0x06061240 + (iVar9 << 1));

          iVar9 = (int)*(short *)((int)(0x06061240 + (iVar9 << 1)) + 2);

          *(short *)0x06063F50 = sVar1;

          puVar10 = (char *)(int)sVar1;

          goto LAB_06027d36;

        }

        break;

      }

      iVar9 = iVar9 + 2;

    }

    iVar9 = 0;

    puVar10 = (char *)0x0607EAD8;

LAB_06027d36:

    if (iVar9 != 0) goto LAB_06027d50;

  }

  puVar10 = (char *)(unsigned int)*(unsigned short *)(0x060C2000 + (int)((int)(int)puVar4 << 2));

  iVar9 = (int)(short)*(unsigned short *)((int)(0x060C2000 + (int)((int)(int)puVar4 << 2)) + 2);

LAB_06027d50:

  do {

    if (iVar9 < 1) {

      uVar6 = 0;

      uVar8 = 0;

LAB_06027e6a:

      *(short *)(param_1 + 3) = (short)uVar6;

      if (uVar8 == 0) {

        iVar9 = CAR_PTR_CURRENT;

      }

      else {

        sVar1 = *(short *)(puVar4 + 0xc);

        param_1[4] = (int)sVar1;

        uVar3 = (*(int(*)())0x0602ECCC)();

        *(short *)((int)param_1 + 0xe) = uVar3;

        iVar9 = CAR_PTR_CURRENT;

        if (param_2 < 1) {

          *(int *)(DAT_06027e9a + iVar9) = (int)sVar1;

        }

      }

      *(unsigned int *)((unsigned int)*(unsigned short *)(0x0606128A + (param_2 << 1)) + iVar9) = uVar6;

      return;

    }

    puVar2 = (unsigned int *)(0x060A6000 + *(short *)(puVar10 + (int)0x060BF000) * 0x34);

    uVar6 = *puVar2;

    iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[4]) >> 0x20) << 0x10

            | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[4]) >> 0x10) + puVar2[5];

    if ((uVar6 & 0x1000000) == 0) {

      iVar7 = iVar7 + param_1[2];

    }

    if ((0x100 & uVar6) == 0) {

      if (iVar7 < 0) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

LAB_06027db6:

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[6]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[6]) >> 0x10) +

              puVar2[7];

      if ((uVar6 & 0x2000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      puVar4 = param_1;

      if ((0x200 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[8]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[8]) >> 0x10) +

              puVar2[9];

      if ((uVar6 & 0x4000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      if ((0x400 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      iVar7 = ((int)((unsigned long long)((long long)(int)*param_1 * (long long)(int)puVar2[10]) >> 0x20) <<

               0x10 | (unsigned int)((long long)(int)*param_1 * (long long)(int)puVar2[10]) >> 0x10) +

              puVar2[0xb];

      if ((uVar6 & 0x8000000) == 0) {

        iVar7 = iVar7 + param_1[2];

      }

      if ((0x00000800 & uVar6) == 0) {

        if (iVar7 < 0) {

          puVar10 = puVar10 + 2;

          iVar9 = iVar9 + -1;

          goto LAB_06027d50;

        }

      }

      else if (0 < iVar7) {

        puVar10 = puVar10 + 2;

        iVar9 = iVar9 + -1;

        goto LAB_06027d50;

      }

      puVar4 = (unsigned int *)(0x060A6000 + *(short *)(puVar10 + (int)0x060BF000) * 0x34);

      uVar8 = (unsigned int)DAT_06027e98;

      uVar6 = *puVar4 & uVar8;

      goto LAB_06027e6a;

    }

    if (iVar7 < 1) goto LAB_06027db6;

    puVar10 = puVar10 + 2;

    iVar9 = iVar9 + -1;

  } while( 1 );

}

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
