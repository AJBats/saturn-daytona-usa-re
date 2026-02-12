#include "game.h"

extern int DAT_0601e162;
extern int DAT_0601e164;
extern int DAT_0601e166;
extern int DAT_0601e238;
extern int DAT_0601e23a;
extern int DAT_0601e23c;
extern int DAT_0601e23e;
extern int DAT_0601e240;
extern int DAT_0601e242;
extern int DAT_0601e244;
extern int DAT_0601e246;
extern int DAT_0601e248;
extern int DAT_0601e24a;
extern int DAT_0601e24c;
extern int DAT_0601e24e;
extern int DAT_0601e444;
extern int DAT_0601efda;
extern int DAT_0601f5c6;
extern int DAT_0601f6ba;
extern int DAT_0601f804;
extern int DAT_0601f806;
extern int DAT_0601f962;
extern int DAT_0601f964;
extern int DAT_0601fa26;
extern int DAT_0601fac4;
extern int DAT_0601fac6;
extern int DAT_0601fac8;
extern int DAT_0601faca;
extern int DAT_0601facc;
extern int DAT_0601face;
extern int DAT_0601fba6;
extern int DAT_0601fba8;
extern int DAT_0601fbaa;
extern int DAT_0601fbac;
extern int DAT_0601fbae;
extern int DAT_0601fbb0;
extern int DAT_0601fbb2;
extern int DAT_0601fbb4;
extern int DAT_0601fbb6;
extern int DAT_0601fbb8;
extern int DAT_0601fbba;
extern int DAT_0601fbbc;
extern int DAT_0601fbbe;
extern int DAT_0601fbc0;
extern int DAT_0601fbc2;
extern int DAT_0601fbc4;
extern int DAT_0601fbc6;
extern int DAT_0601fbc8;
extern int DAT_0601fc8e;
extern int DAT_0601fc90;
extern int DAT_0601fc92;
extern int DAT_0601fc94;
extern int DAT_0601fc96;
extern int DAT_0601fc98;
extern int DAT_0601fc9a;
extern int DAT_0601fc9c;
extern int DAT_0601fc9e;
extern int DAT_0601fca0;
extern int DAT_0601fca2;
extern int DAT_0601fca4;
extern int DAT_0601fca6;
extern int DAT_0601fca8;
extern int DAT_0601fe96;
extern int DAT_0601ff8a;
extern int DAT_0601ff8c;
extern int DAT_0601ff8e;
extern int DAT_0601ff90;
extern int DAT_0601ff92;
extern void FUN_0601e26c();
extern void FUN_0601e2b4();
extern void FUN_0601e37c();
extern int FUN_0601e488(unsigned short slot);
extern unsigned int FUN_0601e4d4();
extern int FUN_0601e6a4();
extern int FUN_0601e764();
extern int FUN_0601e810();
extern unsigned int FUN_0601eb70();
extern char * FUN_0601ebda();
extern char * FUN_0601efc4();
extern int FUN_0601f40c();
extern void FUN_0601f4b4();
extern int FUN_0601f5e0();
extern void FUN_0601f87a(unsigned char);
extern void FUN_0601f9cc();
extern void FUN_0601fd20();
extern void FUN_0601fec0();
extern int vdp1_texture_palette_init();
extern int PTR_DAT_0601e168;
extern int PTR_DAT_0601ebf0;
extern int PTR_DAT_0601f808;
extern int PTR_DAT_0601fa28;
extern int PTR_DAT_0601fd48;

/* nop_e0de -- Placeholder / stripped function (no-op). */
void FUN_0601e0de(void)
{
    return;
}

/* menu_vdp_palette_setup -- Load VDP2 palettes for menu/save screen.
 * Normal mode: loads single palette from 0x0604892C to VDP2 CRAM 0x25F00100,
 *   then submits one VDP1 command from table at 0x06063750.
 * Demo mode: loads palette from 0x0605DFCC, course-specific selection
 *   (0x06078644==1 uses alt offset), submits 4 VDP1 commands for
 *   multi-layer display, calls FUN_0601AB8C and FUN_0601e26c for
 *   dynamic palette animation. Clears state at 0x06087068/0x0605DFF0. */
void FUN_0601e100()
{
    short tile_off;
    char *vdp_base = (char *)0x00008000;           /* VDP2 VRAM base */
    char *vdp_submit = (char *)0x06028400;         /* VDP1 command submit */
    char *gfx_table = (char *)0x06063750;

    if (DEMO_MODE_FLAG == 0) {
        /* Normal mode: single palette + sprite */
        (*(int(*)())0x0602761E)(0x25F00100, 0x0604892C, 0x20);
        (*(int(*)())vdp_submit)(8, *(int *)(gfx_table + 0x10), (int)DAT_0601e162,
                              vdp_base + *(int *)(gfx_table + 0x14));
        vdp_base = vdp_base + *(int *)((int)(gfx_table + DAT_0601e164) + 4);
        gfx_table = *(char **)(gfx_table + DAT_0601e164);
        tile_off = DAT_0601e166;
    } else {
        /* Demo mode: multi-layer palette + sprites */
        (*(int(*)())0x0602761E)(0x25F00100, 0x0605DFCC, 0x20);
        tile_off = DAT_0601e238;
        if (*(int *)0x06078644 == 1) {
            tile_off = PTR_DAT_0601e168;           /* alternate course */
        }
        (*(int(*)())vdp_submit)(8, *(int *)(gfx_table + tile_off), (int)DAT_0601e23a,
                              vdp_base + *(int *)((int)(gfx_table + tile_off) + 4));
        vdp_base = (char *)0x00009000;
        (*(int(*)())vdp_submit)(8, *(int *)(gfx_table + DAT_0601e23c), 0x3c2,
                              0x00009000 + *(int *)((int)(gfx_table + DAT_0601e23c) + 4));
        (*(int(*)())vdp_submit)(8, *(int *)(gfx_table + DAT_0601e240), 0x4c2,
                              vdp_base + *(int *)((int)(gfx_table + DAT_0601e240) + 4));
        (*(int(*)())vdp_submit)(8, *(int *)(gfx_table + DAT_0601e244), 0x5c2,
                              vdp_base + *(int *)((int)(gfx_table + DAT_0601e244) + 4));
        (*(int(*)())0x0601AB8C)();                 /* animation handler */
        FUN_0601e26c(*(int *)0x06086008);
        tile_off = DAT_0601e248;
        (*(int(*)())vdp_submit)(8, 0x0605DFF4, (int)DAT_0601e24a,
                              vdp_base + *(int *)(gfx_table + DAT_0601e248 + 4));
        FUN_0601e26c(*(int *)0x06086004);
        (*(int(*)())vdp_submit)(8, 0x0605DFF4, (int)DAT_0601e24c,
                              vdp_base + *(int *)(gfx_table + tile_off + 4));
        FUN_0601e26c(0);
        vdp_base = vdp_base + *(int *)(gfx_table + tile_off + 4);
        gfx_table = (char *)0x0605DFF4;
        tile_off = DAT_0601e24e;
    }

    (*(int(*)())vdp_submit)(8, gfx_table, (int)tile_off, vdp_base);
    *(int *)0x06087068 = 0;
    *(int *)0x0605DFF0 = 0;
}

/* input_state_copy -- Read 8-byte input buffer from peripheral handler.
 * Calls get_peripheral_data (0x06005DD4), stores base pointer at 0x06087064,
 * then copies 8 bytes into input state array at 0x0605DFF8 (as unsigned short). */
void FUN_0601e26c(void)
{
  int *periph_ptr = (int *)0x06087064;
  unsigned short *input_arr = (unsigned short *)(0x0605DFF4 + 4);
  unsigned char i;

  *periph_ptr = (*(int(*)())0x06005DD4)();

  i = 0;
  do {
    input_arr[i] = (unsigned short)*(unsigned char *)(*periph_ptr + i);
    i++;
  } while (i < 8);
}

/* backup_mem_format -- Format backup memory partition.
 * If not already formatted (0x06087080 == 0), zeroes out the partition
 * buffer at 0x0605E068 for the size specified at 0x0604A5C0 indexed
 * by current channel. Acquires SMPC bus, calls BIOS format routine
 * via vector at 0x06000358, then calls FUN_0601e37c for post-format
 * setup. Releases SMPC bus when done. */
void FUN_0601e2b4()
{
    char *smpc_status = (char *)0x20100063;     /* SMPC SF register */
    char *buf_ptr     = (char *)0x0605E068;     /* partition buffer pointer */
    char *size_table  = (char *)0x0604A5C0;     /* partition size table */
    char *channel_ptr = (char *)0x060877D8;     /* current channel */
    unsigned int i;

    /* Clear partition buffer if not yet formatted */
    if (*(int *)0x06087080 == '\0') {
        for (i = 0; i < *(unsigned int *)(size_table + (unsigned int)(unsigned char)(*channel_ptr << 2)); i = i + 1) {
            *(char *)(*(int *)buf_ptr + i) = 0;
        }
    }

    /* Acquire SMPC bus */
    do { } while ((*smpc_status & 1) == 1);
    *smpc_status = 1;
    SMPC_COMREG = 0x1a;
    do { } while ((*smpc_status & 1) != 0);

    /* Call BIOS format function */
    (*(int(*)())(*(int *)0x06000358))(*(int *)0x0605E060, *(int *)0x0605E064, 0x06087086);
    FUN_0601e37c();

    /* Release SMPC bus */
    do { } while ((*smpc_status & 1) == 1);
    *smpc_status = 1;
    SMPC_COMREG = 0x19;
    do { } while ((*smpc_status & 1) != 0);
}

/* backup_device_enumerate -- Enumerate backup memory devices (max 3).
 * Scans device status array at 0x06087086 (stride 4). For each active
 * device, stores device ID into descriptor array at 0x06087094 (stride 32,
 * offset +0x1C). Calls FUN_0601e488 to open the device; if result==2,
 * calls FUN_0601e6a4 to verify and sets write-protect flag (+0x1F).
 * Checks available space against required size (+0x20 threshold) for
 * capacity flag (+0x1E). Stores final device count at 0x06087084. */
void FUN_0601e37c()
{
    char *desc_base = (char *)0x06087094;       /* device descriptor array */
    short default_wp = DAT_0601e444;            /* default write-protect flag */
    unsigned int dev_count = 0;
    unsigned short dev_idx = 0;

    do {
        if (2 < dev_idx) {
            *(short *)0x06087084 = (short)dev_count;
            return;
        }
        if (*(short *)(0x06087086 + (unsigned int)(dev_idx << 2)) != 0) {
            /* Store device ID in descriptor */
            *(unsigned short *)(desc_base + (((dev_count & 0xffff) << 5) + 0x1c)) = dev_idx;
            int status = FUN_0601e488(dev_count);

            if (status != 0) {
                if (status == 1) goto LAB_0601e46a;
                if (status == 2) {
                    /* Verify device and set write-protect */
                    int verify = FUN_0601e6a4(*(short *)(desc_base + (((dev_count & 0xffff) << 5) + 0x1c)));
                    if (verify == 0) {
                        desc_base[(dev_count & 0xffff) << 5 + 0x1f] = 1;
                    } else {
                        desc_base[(dev_count & 0xffff) << 5 + 0x1f] = (char)default_wp;
                    }
                }
            }

            /* Check capacity: compare available space vs required */
            if (*(unsigned int *)(desc_base + (((dev_count & 0xffff) << 5) + 0xc)) <
                *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)*(int *)(0x060877D8 << 2)) + 0x20U) {
                desc_base[(dev_count & 0xffff) << 5 + 0x1e] = 0;   /* insufficient */
            } else {
                desc_base[(dev_count & 0xffff) << 5 + 0x1e] = 1;   /* sufficient */
            }
            dev_count = dev_count + 1;
        }
LAB_0601e46a:
        dev_idx = dev_idx + 1;
    } while( 1 );
}

/* sound_slot_play -- Start sound playback for a slot.
 * Computes slot descriptor at 0x06087094 + (slot * 32),
 * calls BIOS sound open then play via vtable at 0x06000354. */
int FUN_0601e488(unsigned short slot)
{
    char *desc = (char *)(0x06087094 + (unsigned int)(slot << 5));
    short sound_id = *(short *)(desc + 0x1C);

    /* BIOS sound open (vtable[1]) */
    (*(int(*)())(*(int *)(*(int *)0x06000354 + 4)))(sound_id, 0);
    /* BIOS sound play (vtable[3]) */
    (*(int(*)())(*(int *)(*(int *)0x06000354 + 0xC)))(sound_id,
        *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)*(int *)(0x060877D8 << 2)), desc);

    return 0;
}

/* backup_mem_write_all -- Write save data to all available backup devices.
 * Iterates up to device_count (0x06087084) backup devices in array at
 * 0x06087094 (stride 0x20, channel at +0x1C). For each: acquires SMPC
 * bus (cmd 0x1A), calls BIOS device init (vector +4), writes via
 * FUN_0601e764 using save descriptor from 0x0604A57C. Releases SMPC
 * bus (cmd 0x19). Returns first successful device index (0-2) if any
 * write succeeded, or first fallback device index (3+) if write-protect
 * flag set at +0x1E, or 8 if all failed. */
unsigned int FUN_0601e4d4()
{
    char *smpc_cmd = (char *)0x2010001F;           /* SMPC command register */
    unsigned char *smpc_sf = (unsigned char *)(0x2010001F + 0x44); /* SMPC SF */
    char write_protect[4];
    char write_ok[8];

    write_protect[0] = '\0';
    write_ok[0] = '\0';
    write_protect[1] = 0;
    write_ok[1] = 0;
    write_protect[2] = 0;
    write_ok[2] = 0;

    char *dev_array;
    int dev;
    for (dev = 0;
         dev_array = (char *)0x06087094,
         dev < (int)(unsigned int)*(unsigned short *)0x06087084;
         dev = dev + 1) {
        /* Acquire SMPC bus */
        do { } while ((*smpc_sf & 1) == 1);
        *smpc_sf = 1;
        *smpc_cmd = (char *)0x1a;                  /* NETLINK OFF / bus acquire */
        do { } while ((*smpc_sf & 1) != 0);

        /* Init device and write save */
        (*(int(*)())(*(int *)(*(int *)0x06000354 + 4)))(
            *(short *)(dev_array + (dev << 5) + 0x1c), 0);
        int result = FUN_0601e764(
            (int)*(short *)(dev_array + (dev << 5) + 0x1c),
            0x0604A57C + (unsigned int)(unsigned char)*(int *)0x060877D8 * 0xc,
            *(int *)0x0605E098);

        /* Release SMPC bus */
        do { } while ((*smpc_sf & 1) == 1);
        *smpc_sf = 1;
        *smpc_cmd = (char *)0x19;                  /* NETLINK ON / bus release */
        do { } while ((*smpc_sf & 1) != 0);

        if (result == 0) {
            write_ok[dev] = '\x01';
        }
        if (dev_array[(dev << 5) + 0x1e] != '\0') {
            write_protect[dev] = '\x01';
        }
    }

    /* Return first successful device */
    unsigned int idx = 0;
    do {
        if (write_ok[idx] != '\0') {
            return idx & 0xff;
        }
        idx = idx + 1;
    } while ((int)idx < 3);

    /* Fallback: return first write-protected device */
    char *scan = write_protect;
    idx = 3;
    while (1) {
        if (write_protect + 3 <= scan) {
            return 8;                              /* all failed */
        }
        if (*scan != '\0') break;
        scan = scan + 1;
        idx = idx + 1;
    }

    return idx & 0xff;
}

/* bios_sound_poll -- Poll BIOS sound handler up to 10 times.
 * Reads function pointer from BIOS vector table (0x06000354 → vtable+8),
 * calls it with param_1. Returns 0 on first success, or last error
 * code if all 10 attempts fail. */
int FUN_0601e6a4(int param_1)
{
  int *bios_vec = (int *)0x06000354;       /* BIOS vector table pointer */
  int result;
  int attempt = 0;

  do {
    result = (*(int(*)())(*(int *)(*bios_vec + 8)))(param_1);
    if (result == 0) return 0;
    attempt++;
  } while (attempt < 10);

  return result;
}

/* backup_mem_write -- Write data to backup memory device via BIOS.
 * Truncates data to 11 bytes if longer. Acquires SMPC bus (cmd 0x1A),
 * calls BIOS save function via vector table at 0x06000354 (+0x14),
 * using device channel from 0x06087094 array (stride 0x20, offset +0x1C).
 * Releases SMPC bus (cmd 0x19) when done. */
int FUN_0601e764(param_1, param_2, param_3)
    unsigned short param_1;
    int param_2;
    int param_3;
{
    char *smpc_status = (char *)0x20100063;     /* SMPC SF register */
    int len;
    int result;

    len = (*(int(*)())0x06035C1C)(param_2);     /* strlen */
    if (0xb < len) {
        *(char *)(param_2 + 0xb) = 0;           /* truncate to 11 chars */
    }

    /* Acquire SMPC bus */
    do { } while ((*smpc_status & 1) == 1);
    *smpc_status = 1;
    SMPC_COMREG = 0x1a;                         /* NETLINK OFF / bus acquire */
    do { } while ((*smpc_status & 1) != 0);

    /* Call BIOS backup write */
    result = (*(int(*)())(*(int *)(*(int *)0x06000354 + 0x14)))(
                 *(short *)(0x06087094 + (unsigned int)(param_1 << 5) + 0x1c),
                 param_2, param_3);

    /* Release SMPC bus */
    do { } while ((*smpc_status & 1) == 1);
    *smpc_status = 1;
    SMPC_COMREG = 0x19;                         /* NETLINK ON / bus release */
    do { } while ((*smpc_status & 1) != 0);

    return result;
}

/* backup_mem_read -- Read save data from backup memory via BIOS.
 * Truncates filename (param_2) to 11 chars if longer. Also truncates
 * the channel-specific label at 0x0605E06C to 10 chars. Builds a
 * save descriptor at 0x060877B4 with filename and label copies, then
 * acquires SMPC bus and calls BIOS read function (vector +0x10). */
int FUN_0601e810(param_1, param_2, param_3)
    unsigned short param_1;
    int param_2;
    int param_3;
{
    char *smpc_status = (char *)0x20100063;     /* SMPC SF register */
    char *channel_ptr = (char *)0x060877D8;     /* current channel */
    char *label_base  = (char *)0x0605E06C;     /* channel label array */
    int len;
    int result;

    /* Truncate filename to 11 chars */
    len = (*(int(*)())0x06035C1C)(param_2);     /* strlen */
    if (0xb < len) {
        *(char *)(param_2 + 0xb) = 0;
    }

    /* Truncate channel label to 10 chars */
    len = (*(int(*)())0x06035C1C)(label_base + (unsigned int)(unsigned char)*channel_ptr * 0xb);
    if (10 < len) {
        label_base[(unsigned int)(unsigned char)*channel_ptr * 0xb + 10] = 0;
    }

    /* Build save descriptor */
    FUN_0601f4b4(0x060877E8);
    char *desc = (char *)0x060877B4;
    (*(int(*)())0x06035C08)(0x060877B4, param_2);       /* strcpy filename */
    (*(int(*)())0x06035C08)(desc + 0xc,
                 label_base + (unsigned int)(unsigned char)*channel_ptr * 0xb);  /* strcpy label */
    desc[0x17] = 0;

    /* Get save data size from BIOS */
    result = (*(int(*)())(*(int *)(*(int *)0x06000354 + 0x28)))(0x060877E8);
    *(int *)(desc + 0x18) = result;
    *(int *)(desc + 0x1c) = *(int *)(0x0604A5C0 + (unsigned int)(unsigned char)(*channel_ptr << 2));

    /* Acquire SMPC bus */
    do { } while ((*smpc_status & 1) == 1);
    *smpc_status = 1;
    SMPC_COMREG = 0x1a;
    do { } while ((*smpc_status & 1) != 0);

    /* Call BIOS read function */
    result = (*(int(*)())(*(int *)(*(int *)0x06000354 + 0x10)))(
                 *(short *)(0x06087094 + (unsigned int)(param_1 << 5) + 0x1c),
                 0x060877B4, param_3, 0);

    /* Release SMPC bus */
    do { } while ((*smpc_status & 1) == 1);
    *smpc_status = 1;
    SMPC_COMREG = 0x19;
    do { } while ((*smpc_status & 1) != 0);

    return result;
}

/* save_data_load_or_create -- Load save data, creating new save if needed.
 * Reads state byte from 0x0605E05D. If state==0: formats backup memory,
 * validates CD track, and attempts to read save data. If read succeeds
 * and data matches reference pattern (0x0604A5AC, 16 bytes), calls
 * FUN_0601ebda to finalize. On mismatch or failure, sets error state (8)
 * and calls error handler at 0x0601F8BC. If track invalid, marks channel
 * inactive and sets state 4. Otherwise resets state to 0. */
int FUN_0601e958()
{
    char *state_ptr     = (char *)0x0605E05C;   /* save operation state */
    char *error_handler = (char *)0x0601F8BC;   /* error recovery function */
    char *playback_ptr  = (char *)0x0605E098;   /* playback data pointer */
    int result;

    result = (int)(char)*(int *)0x0605E05D;     /* current state byte */

    if (result == 0) {
        FUN_0601e2b4();                          /* format backup memory */

        char *channel_ptr = (char *)0x060877D8;
        unsigned char ch = (unsigned char)*(int *)0x060877D8;
        unsigned char track_status = FUN_0601e4d4(0x0604A57C + (unsigned int)ch * 0xc);

        if (track_status < 7) {
            ((int *)0x060877DD)[ch] = 1;         /* mark channel active */

            if (2 < track_status) {
                /* Deferred track: load and validate */
                ((int *)0x060877D9)[ch] = track_status - 3;
                FUN_0601eb70();
                result = FUN_0601f40c();
                return result;
            }

            /* Immediate track: attempt save read */
            ((int *)0x060877D9)[ch] = track_status;
            result = FUN_0601e764(((int *)0x060877D9)[ch],
                                  0x0604A57C + (unsigned int)(unsigned char)*channel_ptr * 0xc,
                                  *(int *)playback_ptr);

            if (result == 0) {
                result = 0;
                if (*(int *)0x06087080 == '\0') {
                    /* Verify save data matches reference pattern */
                    result = 0;
                    while (*(char *)(*(int *)playback_ptr + result) == ((int *)0x0604A5AC)[result]) {
                        result = result + 1;
                        if (0xf < result) {
                            result = FUN_0601ebda();
                            return result;
                        }
                    }
                    /* Mismatch: error state */
                    *state_ptr = 8;
                    result = (*(int(*)())error_handler)();
                }
            } else {
                /* Read failed: error state */
                *state_ptr = 8;
                result = (*(int(*)())error_handler)();
            }
        } else {
            /* Track invalid: mark inactive */
            FUN_0601eb70();
            ((int *)0x060877DD)[ch] = 0;
            *state_ptr = 4;
            result = (*(int(*)())error_handler)();
        }
    } else {
        /* Non-zero state: reset */
        *(int *)0x0605E05C = 0;
    }
    return result;
}

/* cd_track_validate -- Validate current CD audio track and set play state.
 * Reads channel from 0x060877D8, calls FUN_0601e4d4 with track descriptor
 * (0x0604A57C + channel * 0xC). If result < 7, marks channel active and
 * stores track ID (shifted by -3 if >= 3). Returns 1 if track ID < 3
 * (immediate play), 0 otherwise. */
int FUN_0601eaa0()
{
    char *channel_ptr = (char *)0x060877D8;
    int result = 0;
    unsigned char ch = (unsigned char)*(int *)0x060877D8;

    unsigned char track_status = FUN_0601e4d4(0x0604A57C + (unsigned int)ch * 0xc);

    if (track_status < 7) {
        ((int *)0x060877DD)[ch] = 1;            /* mark channel active */
        if (track_status < 3) {
            ((int *)0x060877D9)[ch] = track_status;
            result = 1;                          /* immediate play */
        } else {
            ((int *)0x060877D9)[ch] = track_status - 3;
        }
    } else {
        ((int *)0x060877DD)[ch] = 0;            /* mark channel inactive */
    }
    return result;
}

/* cd_track_play_if_active -- Play CD audio track if channel is marked active.
 * Checks active-flag array at 0x060877DD indexed by current channel (0x060877D8).
 * If active, calls track player with channel-ID, track descriptor, and playback state. */
void FUN_0601eb1c(void)
{
    unsigned char ch = (unsigned char)*(int *)0x060877D8;
    if (((int *)0x060877DD)[ch] != '\0') {
        FUN_0601e810(((int *)0x060877D9)[ch],
                     0x0604A57C + (unsigned int)ch * 0xC,
                     *(int *)0x0605E098);
    }
}

/* save_data_template_init -- Initialize save data buffer from template.
 * When save state (0x06087080) is 0: clears the save buffer at
 * 0x0605E098 (length from table at 0x0604A5C0 indexed by device ID
 * at 0x060877D8), then copies 16-byte template from 0x0604A5AC to
 * the output buffer at 0x0605E09C. Returns device index. */
unsigned int FUN_0601eb70()
{
    char *out_buf = (char *)0x0605E09C;
    char *template = (char *)0x0604A5AC;
    char *save_buf = (char *)0x0605E098;
    char *device_id = (char *)0x060877D8;
    char *size_table = (char *)0x0604A5C0;
    unsigned int dev_idx = (unsigned int)(unsigned char)*(int *)0x06087080;

    if (dev_idx == 0) {
        /* Clear save buffer */
        unsigned int i;
        for (i = 0;
             dev_idx = (unsigned int)(unsigned char)(*device_id << 2),
             i < *(unsigned int *)(size_table + dev_idx);
             i = i + 1) {
            *(char *)(*(int *)save_buf + i) = 0;
        }

        /* Copy 16-byte template */
        int j = 0;
        do {
            *(char *)(*(int *)out_buf + j) = template[j];
            *(char *)(*(int *)out_buf + j + 1) = template[j + 1];
            j = j + 2;
        } while (j < 0x10);
    }

    return dev_idx;
}

/* save_state_load -- deserialize save data from backup RAM into game state */
char * FUN_0601ebda()
{
  char *settings_ptr;
  char *result;
  char *src;
  char *src_end;
  int block_size;
  char *dst_next;
  int *table_end;
  char *dst;
  int *table_ptr;
  char *dst_block;

  block_size = 0xf0;
  result = (char *)(unsigned int)(unsigned char)*(int *)0x06087080; /* save_error_flag */

  if (result == (char *)0x0) {
    src = (char *)(*(int *)0x0605E098 + 0x10); /* save_buffer + header_size */

    /* Block 1: copy 0xF0 bytes per entry from 9 pointer table entries at 0x0605DD6C */
    table_end = (int *)(0x0605DD6C + 0x48);
    table_ptr = (int *)0x0605DD6C;
    do {
      dst_block = (char *)*table_ptr;
      result = dst_block;
      do {
        *result = *src;
        result[1] = src[1];
        result[2] = src[2];
        result[3] = src[3];
        result[4] = src[4];
        result[5] = src[5];
        result[6] = src[6];
        result[7] = src[7];
        result[8] = src[8];
        dst_next = result + 0xc;
        result[9] = src[9];
        src_end = src + 0xb;
        result[10] = src[10];
        src = src + 0xc;
        result[0xb] = *src_end;
        result = dst_next;
      } while (dst_next < dst_block + block_size);
      table_ptr = table_ptr + 2;
    } while (table_ptr < table_end);

    /* Block 2: copy 8 bytes per entry from 6 pointer table entries at 0x0605DE24 */
    table_end = (int *)(0x0605DE24 + 0x18);
    table_ptr = (int *)0x0605DE24;
    do {
      result = (char *)*table_ptr;
      table_ptr = table_ptr + 1;
      *result = *src;
      result[1] = src[1];
      result[2] = src[2];
      result[3] = src[3];
      result[4] = src[4];
      result[5] = src[5];
      dst_block = src + 7;
      result[6] = src[6];
      src = src + 8;
      result[7] = *dst_block;
    } while (table_ptr < table_end);

    /* Block 3: copy 0x20 bytes to 0x0605DDB4 (leaderboard times A) */
    dst_block = 0x0605DDB4 + 0x20;
    dst = (char *)0x0605DDB4;
    do {
      *dst = *src;
      dst[1] = src[1];
      dst[2] = src[2];
      dst[3] = src[3];
      dst_next = dst + 8;
      dst[4] = src[4];
      dst[5] = src[5];
      src_end = src + 7;
      dst[6] = src[6];
      src = src + 8;
      dst[7] = *src_end;
      dst = dst_next;
    } while (dst_next < dst_block);

    /* Block 4: copy 0x20 bytes to 0x0605DDD4 (leaderboard times B) */
    dst_block = 0x0605DDD4 + 0x20;
    dst = (char *)0x0605DDD4;
    do {
      *dst = *src;
      dst[1] = src[1];
      dst[2] = src[2];
      dst[3] = src[3];
      dst_next = dst + 8;
      dst[4] = src[4];
      dst[5] = src[5];
      src_end = src + 7;
      dst[6] = src[6];
      src = src + 8;
      dst[7] = *src_end;
      dst = dst_next;
    } while (dst_next < dst_block);

    /* Block 5: copy 0x24 bytes to 0x0605DE40 (race records) */
    dst_block = 0x0605DE40 + 0x24;
    dst = (char *)0x0605DE40;
    do {
      src_end = src;
      *dst = *src_end;
      dst[1] = src_end[1];
      dst[2] = src_end[2];
      dst[3] = src_end[3];
      dst[4] = src_end[4];
      dst[5] = src_end[5];
      dst[6] = src_end[6];
      dst[7] = src_end[7];
      dst[8] = src_end[8];
      dst[9] = src_end[9];
      dst_next = dst + 0xc;
      dst[10] = src_end[10];
      dst[0xb] = src_end[0xb];
      settings_ptr = (char *)0x0605AD00;
      src = src_end + 0xc;
      dst = dst_next;
    } while (dst_next < dst_block);

    /* Deserialize game settings from save buffer */
    COURSE_SELECT = src_end[0xc];          /* 0x0605AD00 */
    settings_ptr[1] = src_end[0xd];
    settings_ptr[2] = src_end[0xe];
    settings_ptr[3] = src_end[0xf];
    dst = (char *)0x0605AD04;
    *(int *)0x0605AD04 = src_end[0x10];    /* difficulty */
    dst[1] = src_end[0x11];
    dst[2] = src_end[0x12];
    dst[3] = src_end[0x13];
    dst = (char *)0x0605AD0C;
    *(int *)0x0605AD0C = src_end[0x14];    /* laps */
    dst[1] = src_end[0x15];
    dst[2] = src_end[0x16];
    dst[3] = src_end[0x17];
    *(int *)0x0605AB16 = src_end[0x18];    /* game_mode */
    *(int *)0x0605AB17 = src_end[0x19];    /* sub_mode */
    *(int *)0x0605D240 = src_end[0x1a];    /* option_a */
    *(int *)0x0605D241 = src_end[0x1b];    /* option_b */
    /* Leaderboard names and records: 0x06060D40-0x06060D74 (20 two-byte fields + 3 four-byte fields) */
    dst = (char *)0x06060D44;
    *(int *)0x06060D44 = src_end[0x1c];
    dst[1] = src_end[0x1d];
    dst = (char *)0x06060D46;
    *(int *)0x06060D46 = src_end[0x1e];
    dst[1] = src_end[0x1f];
    dst = (char *)0x06060D40;
    *(int *)0x06060D40 = src_end[0x20];
    dst[1] = src_end[0x21];
    dst = (char *)0x06060D42;
    *(int *)0x06060D42 = src_end[0x22];
    dst[1] = src_end[0x23];
    dst = (char *)0x06060D48;
    *(int *)0x06060D48 = src_end[0x24];
    dst[1] = src_end[0x25];
    dst = (char *)0x06060D4A;
    *(int *)0x06060D4A = src_end[0x26];
    dst[1] = src_end[0x27];
    dst = (char *)0x06060D4C;
    *(int *)0x06060D4C = src_end[0x28];
    dst[1] = src_end[0x29];
    dst = (char *)0x06060D4E;
    *(int *)0x06060D4E = src_end[0x2a];
    dst[1] = src_end[0x2b];
    dst = (char *)0x06060D54;
    *(int *)0x06060D54 = src_end[0x2c];
    dst[1] = src_end[0x2d];
    dst[2] = src_end[0x2e];
    dst[3] = src_end[0x2f];
    dst = (char *)0x06060D58;
    *(int *)0x06060D58 = src_end[0x30];
    dst[1] = src_end[0x31];
    dst[2] = src_end[0x32];
    dst[3] = src_end[0x33];
    dst = (char *)0x06060D50;
    *(int *)0x06060D50 = src_end[0x34];
    dst[1] = src_end[0x35];
    dst[2] = src_end[0x36];
    dst[3] = src_end[0x37];
    dst = (char *)0x06060D60;
    *(int *)0x06060D60 = src_end[0x38];
    dst[1] = src_end[0x39];
    dst = (char *)0x06060D62;
    *(int *)0x06060D62 = src_end[0x3a];
    dst[1] = src_end[0x3b];
    src = 0x06060D5C + 1;
    *(int *)0x06060D5C = src_end[0x3c];
    *src = src_end[0x3d];
    dst = (char *)0x06060D5E;
    *(int *)0x06060D5E = src_end[0x3e];
    dst[1] = src_end[0x3f];
    dst = (char *)0x06060D64;
    *(int *)0x06060D64 = src_end[0x40];
    dst[1] = src_end[0x41];
    dst = (char *)0x06060D66;
    *(int *)0x06060D66 = src_end[0x42];
    dst[1] = src_end[0x43];
    dst = (char *)0x06060D68;
    *(int *)0x06060D68 = src_end[0x44];
    dst[1] = src_end[0x45];
    dst = (char *)0x06060D6A;
    *(int *)0x06060D6A = src_end[0x46];
    dst[1] = src_end[0x47];
    dst = (char *)0x06060D70;
    *(int *)0x06060D70 = src_end[0x48];
    dst[1] = src_end[0x49];
    dst[2] = src_end[0x4a];
    dst[3] = src_end[0x4b];
    dst = (char *)0x06060D74;
    *(int *)0x06060D74 = src_end[0x4c];
    dst[1] = src_end[0x4d];
    dst[2] = src_end[0x4e];
    dst[3] = src_end[0x4f];
    dst = (char *)0x06060D6C;
    *(int *)0x06060D6C = src_end[0x50];
    dst[1] = src_end[0x51];
    dst[2] = src_end[0x52];
    dst[3] = src_end[0x53];
  }

  return result;
}

/* save_state_store -- serialize game state into backup RAM save buffer */
char * FUN_0601efc4()
{
  char *settings_ptr;
  char *result;
  char *dst;
  int block_size;
  char *src_next;
  int *table_end;
  char *src;
  int *table_ptr;
  char *src_block;

  block_size = 0xf0;
  result = (char *)(unsigned int)(unsigned char)*(int *)0x06087080; /* save_error_flag */

  if (result == (char *)0x0) {
    dst = (char *)(*(int *)0x0605E098 + 0x10); /* save_buffer + header_size */

    /* Block 1: serialize 0xF0 bytes per entry from 9 pointer table entries at 0x0605DD6C */
    table_end = (int *)(0x0605DD6C + 0x48);
    table_ptr = (int *)0x0605DD6C;
    do {
      src_block = (char *)*table_ptr;
      result = src_block;
      do {
        *dst = *result;
        dst[1] = result[1];
        dst[2] = result[2];
        dst[3] = result[3];
        dst[4] = result[4];
        dst[5] = result[5];
        dst[6] = result[6];
        dst[7] = result[7];
        src_next = result + 0xc;
        dst[8] = result[8];
        dst[9] = result[9];
        dst[10] = result[10];
        dst[0xb] = result[0xb];
        dst = dst + 0xc;
        result = src_next;
      } while (src_next < src_block + block_size);
      table_ptr = table_ptr + 2;
    } while (table_ptr < table_end);

    /* Block 2: serialize 8 bytes per entry from 6 pointer table entries at 0x0605DE24 */
    table_end = (int *)(0x0605DE24 + 0x18);
    table_ptr = (int *)0x0605DE24;
    do {
      result = (char *)*table_ptr;
      table_ptr = table_ptr + 1;
      *dst = *result;
      dst[1] = result[1];
      dst[2] = result[2];
      dst[3] = result[3];
      dst[4] = result[4];
      dst[5] = result[5];
      dst[6] = result[6];
      dst[7] = result[7];
      dst = dst + 8;
    } while (table_ptr < table_end);

    /* Block 3: serialize 0x20 bytes from 0x0605DDB4 (leaderboard times A) */
    src_block = 0x0605DDB4 + 0x20;
    src = (int *)0x0605DDB4;
    do {
      *dst = *src;
      dst[1] = src[1];
      dst[2] = src[2];
      dst[3] = src[3];
      src_next = src + 8;
      dst[4] = src[4];
      dst[5] = src[5];
      dst[6] = src[6];
      dst[7] = src[7];
      dst = dst + 8;
      src = src_next;
    } while (src_next < src_block);

    /* Block 4: serialize 0x20 bytes from 0x0605DDD4 (leaderboard times B) */
    src_block = 0x0605DDD4 + 0x20;
    src = (int *)0x0605DDD4;
    do {
      *dst = *src;
      dst[1] = src[1];
      dst[2] = src[2];
      dst[3] = src[3];
      src_next = src + 8;
      dst[4] = src[4];
      dst[5] = src[5];
      dst[6] = src[6];
      dst[7] = src[7];
      dst = dst + 8;
      src = src_next;
    } while (src_next < src_block);

    /* Block 5: serialize 0x24 bytes from 0x0605DE40 (race records) */
    src_block = 0x0605DE40 + 0x24;
    src = (int *)0x0605DE40;
    do {
      src_next = dst;
      *src_next = *src;
      src_next[1] = src[1];
      src_next[2] = src[2];
      src_next[3] = src[3];
      src_next[4] = src[4];
      src_next[5] = src[5];
      src_next[6] = src[6];
      src_next[7] = src[7];
      src_next[8] = src[8];
      src_next[9] = src[9];
      src = src + 0xc;
      src_next[10] = src[10];
      src_next[0xb] = src[0xb];
      settings_ptr = (char *)0x0605AD00;
      dst = src_next + 0xc;
      src = src;
    } while (src < src_block);

    /* Serialize game settings to save buffer */
    dst = 0x0605AD00 + 1;
    src_next[0xc] = COURSE_SELECT;
    src_next[0xd] = *dst;
    src_next[0xe] = settings_ptr[2];
    src_next[0xf] = settings_ptr[3];
    src = (int *)0x0605AD04;
    dst = 0x0605AD04 + 1;
    src_next[0x10] = *(int *)0x0605AD04;
    src_next[0x11] = *dst;
    src_next[0x12] = src[2];
    src_next[0x13] = src[3];
    src = (int *)0x0605AD0C;
    dst = 0x0605AD0C + 1;
    src_next[0x14] = *(int *)0x0605AD0C;
    src_next[0x15] = *dst;
    src_next[0x16] = src[2];
    src_next[0x17] = src[3];
    src_next[0x18] = *(int *)0x0605AB16;
    src_next[0x19] = *(int *)0x0605AB17;
    src_next[0x1a] = *(int *)0x0605D240;
    src_next[0x1b] = *(int *)0x0605D241;
    /* Leaderboard names and records: 0x06060D40-0x06060D74 */
    dst = 0x06060D44 + 1;
    src_next[0x1c] = *(int *)0x06060D44;
    src_next[0x1d] = *dst;
    dst = 0x06060D46 + 1;
    src_next[0x1e] = *(int *)0x06060D46;
    src_next[0x1f] = *dst;
    dst = 0x06060D40 + 1;
    src_next[0x20] = *(int *)0x06060D40;
    src_next[0x21] = *dst;
    dst = 0x06060D42 + 1;
    src_next[0x22] = *(int *)0x06060D42;
    src_next[0x23] = *dst;
    dst = 0x06060D48 + 1;
    src_next[0x24] = *(int *)0x06060D48;
    src_next[0x25] = *dst;
    dst = 0x06060D4A + 1;
    src_next[0x26] = *(int *)0x06060D4A;
    src_next[0x27] = *dst;
    dst = 0x06060D4C + 1;
    src_next[0x28] = *(int *)0x06060D4C;
    src_next[0x29] = *dst;
    dst = 0x06060D4E + 1;
    src_next[0x2a] = *(int *)0x06060D4E;
    src_next[0x2b] = *dst;
    src = (int *)0x06060D54;
    dst = 0x06060D54 + 1;
    src_next[0x2c] = *(int *)0x06060D54;
    src_next[0x2d] = *dst;
    src_next[0x2e] = src[2];
    src_next[0x2f] = src[3];
    src = (int *)0x06060D58;
    dst = 0x06060D58 + 1;
    src_next[0x30] = *(int *)0x06060D58;
    src_next[0x31] = *dst;
    src_next[0x32] = src[2];
    src_next[0x33] = src[3];
    src = (int *)0x06060D50;
    dst = 0x06060D50 + 1;
    src_next[0x34] = *(int *)0x06060D50;
    src_next[0x35] = *dst;
    src_next[0x36] = src[2];
    src_next[0x37] = src[3];
    dst = 0x06060D60 + 1;
    src_next[0x38] = *(int *)0x06060D60;
    src_next[0x39] = *dst;
    dst = 0x06060D62 + 1;
    src_next[0x3a] = *(int *)0x06060D62;
    src_next[0x3b] = *dst;
    dst = 0x06060D5C + 1;
    src_next[0x3c] = *(int *)0x06060D5C;
    src_next[0x3d] = *dst;
    dst = 0x06060D5E + 1;
    src_next[0x3e] = *(int *)0x06060D5E;
    src_next[0x3f] = *dst;
    dst = 0x06060D64 + 1;
    src_next[0x40] = *(int *)0x06060D64;
    src_next[0x41] = *dst;
    dst = 0x06060D66 + 1;
    src_next[0x42] = *(int *)0x06060D66;
    src_next[0x43] = *dst;
    dst = 0x06060D68 + 1;
    src_next[0x44] = *(int *)0x06060D68;
    src_next[0x45] = *dst;
    dst = 0x06060D6A + 1;
    src_next[0x46] = *(int *)0x06060D6A;
    src_next[0x47] = *dst;
    src = (int *)0x06060D70;
    dst = 0x06060D70 + 1;
    src_next[0x48] = *(int *)0x06060D70;
    src_next[0x49] = *dst;
    src_next[0x4a] = src[2];
    src_next[0x4b] = src[3];
    src = (int *)0x06060D74;
    dst = 0x06060D74 + 1;
    src_next[0x4c] = *(int *)0x06060D74;
    src_next[0x4d] = *dst;
    src_next[0x4e] = src[2];
    src_next[0x4f] = src[3];
    src = (int *)0x06060D6C;
    dst = 0x06060D6C + 1;
    src_next[0x50] = *(int *)0x06060D6C;
    src_next[0x51] = *dst;
    src_next[0x52] = src[2];
    src_next[0x53] = src[3];
  }

  return result;
}

/* cdda_replay_check -- Check if CD audio track needs replay.
 * Reads current track index from 0x060877D8, checks enable flag in
 * table at 0x060877DD. If enabled, stops current playback (FUN_0601efc4),
 * starts new session via FUN_0601e810 with track descriptor from table
 * at 0x0604A57C (12 bytes per entry). On failure, sets error state 0xC. */
int FUN_0601f40c(void)
{
  char *track_idx = (char *)0x060877D8;

  if (((int *)0x060877DD)[(unsigned char)*track_idx] != '\0') {
    FUN_0601efc4();
    int result = FUN_0601e810(((int *)0x060877D9)[(unsigned char)*track_idx],
                              0x0604A57C + (unsigned int)(unsigned char)*track_idx * 0xc,
                              *(int *)0x0605E098);
    if (result != 0) {
      *(int *)0x0605E05C = 0xc;            /* set CD error state */
      (*(int(*)())0x0601F8BC)();
      return 0;
    }
  }
  return 0;
}

/* bcd_timestamp_decode -- Decode BCD-encoded CD-ROM timestamp to binary.
 * Reads 7-byte BCD timestamp from CD status block (0x060A4C98) and converts
 * to binary output: param_1[0]=year, [1]=day_lo, [2]=hour, [3]=minute,
 * [4]=second, [5]=day_hi. Each BCD byte split into high*10+low nibbles. */
void FUN_0601f4b4(char *param_1)
{
  int base = *(int *)0x060A4C98;
  *(int *)0x060877E4 = base;                /* cache timestamp pointer */

  unsigned char sec = *(unsigned char *)(base + 1);
  unsigned char min = *(unsigned char *)(base + 2);
  unsigned char hour = *(unsigned char *)(base + 3);
  unsigned char day = *(unsigned char *)(base + 4);

  /* Year: BCD decode of bytes 5 and 6 with century offset */
  *param_1 = (char)DAT_0601f5c6 +
             (char)((int)(unsigned int)*(unsigned char *)(base + 5) >> 4) * '\n' +
             (*(unsigned char *)(base + 5) & 0xf) +
             (char)((int)(unsigned int)*(unsigned char *)(base + 6) >> 4) * (char)0x03E8F844 +
             (*(unsigned char *)(base + 6) & 0xf) * 'd';

  param_1[1] = day & 0xf;                          /* day low nibble */
  param_1[5] = (char)((int)(unsigned int)day >> 4); /* day high nibble */
  param_1[2] = (hour & 0xf) + (char)((int)(unsigned int)hour >> 4) * '\n';
  param_1[3] = (min & 0xf) + (char)((int)(unsigned int)min >> 4) * '\n';
  param_1[4] = (sec & 0xf) + (char)((int)(unsigned int)sec >> 4) * '\n';
}

/* save_score_check_update -- Check and update high score in save data.
 * Copies current score from save buffer, compares against best score at 0x060786A4.
 * On new high score: writes score, fills table with 0x40/0x80 pairs, writes player initials
 * (defaults to "DAY" if no name entry), reformats and validates save data. */
int FUN_0601f5e0()
{
  char *save_data;
  char *temp_score;
  int result;
  char *name_ptr;
  unsigned int slot;
  unsigned int table_end;
  save_data = (char *)0x0607ED90;
  table_end = (unsigned int)DAT_0601f6ba;
  FUN_0601f87a(0);
  (*(int(*)())0x0601E2B4)();            /* format save buffer */
  (*(int(*)())0x0601EB70)();            /* validate track data */
  (*(int(*)())0x0601F40C)();            /* checksum update */
  temp_score = (char *)0x060877F0;
  if (*(int *)0x06078635 == '\0') {
    result = 0;
  }
  else {
    /* Copy saved score to temp buffer */
    *(int *)0x060877F0 = save_data[4];
    temp_score[1] = save_data[5];
    temp_score[2] = save_data[6];
    temp_score[3] = save_data[7];
    /* Check if current score beats saved best */
    if ((*(unsigned int *)0x060786A4 < *(unsigned int *)0x060877F0) ||
       (result = *(int *)0x060877F0, result == 0)) {
      /* New high score — update save data */
      *(int *)0x0605E0A1 = 1;
      *(int *)0x0605E0A0 = (char)CAR_COUNT;
      temp_score = (char *)0x060786A4;
      name_ptr = 0x060786A4 + 1;
      save_data[4] = *(int *)0x060786A4;
      save_data[5] = *name_ptr;
      save_data[6] = temp_score[2];
      save_data[7] = temp_score[3];
      /* Fill score table entries */
      for (slot = *(unsigned int *)0x0607ED88; slot < table_end; slot = slot + 2) {
        save_data[slot] = 0x40;
        save_data[slot + 1] = 0x80;
      }
      FUN_0601f87a(CAR_COUNT + 1U & 0xff);
      /* Write player initials (3 chars at 11-byte entry stride) */
      temp_score = (char *)0x060877D8;
      save_data = (char *)0x0605E06C;
      name_ptr = (char *)0x0;
      if (*(int *)0x06085FFC != 0) {
        name_ptr = *(char **)0x06085FFC;
      }
      if (*(int *)0x06086000 != 0) {
        name_ptr = *(char **)0x06086000;
      }
      if (name_ptr == (char *)0x0) {
        /* Default initials "DAY" */
        ((int *)0x0605E06C)[(char)(*(int *)0x060877D8 * '\v') + 7] = 0x44;
        save_data[(char)(*temp_score * '\v') + 8] = 0x41;
        save_data[(char)(*temp_score * '\v') + 9] = 0x59;
      }
      else {
        /* Copy initials from name entry */
        ((int *)0x0605E06C)[(char)(*(int *)0x060877D8 * '\v') + 7] = *name_ptr;
        save_data[(char)(*temp_score * '\v') + 8] = name_ptr[1];
        save_data[(char)(*temp_score * '\v') + 9] = name_ptr[2];
      }
      (*(int(*)())0x0601E2B4)();        /* reformat buffer */
      result = (*(int(*)())0x0601EB1C)();  /* validate and commit */
      return result;
    }
  }
  return result;
}

/* save_data_write_validate -- Write and validate save data to backup device.
 * Only active when game mode byte (0x06078635) is set. Prepares car count
 * via FUN_0601f87a, formats backup (0x0601E2B4), validates CD track
 * (0x0601EAA0). If validation passes and save state allows, writes data
 * via FUN_06027630 using course-specific size (0x0607EAD8 selects course).
 * Fills unused buffer bytes with 0x40/0x80 pattern, clears dirty flag. */
unsigned int FUN_0601f784()
{
    int *course_sel = (int *)0x0607EAD8;
    char *save_buf = (char *)0x0607ED90;
    unsigned int buf_size = (unsigned int)DAT_0601f804;
    unsigned int result = 0;

    if (*(int *)0x06078635 != '\0') {
        FUN_0601f87a(CAR_COUNT + 1U & 0xff);
        (*(int(*)())0x0601E2B4)();                 /* backup_mem_format */
        result = (*(int(*)())0x0601EAA0)();        /* cd_track_validate */
        result = result & 0xff;

        if ((result == 0) &&
           ((*(int *)0x0605E0A1 == '\0' ||
            ((unsigned int)(unsigned char)*(int *)0x0605E0A0 != CAR_COUNT)))) {
            /* Write save data, course-specific size */
            if (*course_sel == 0) {
                result = (*(int(*)())0x06027630)(save_buf, 0x002F8000, (int)DAT_0601f806);
            } else if (*course_sel == 1) {
                result = (*(int(*)())0x06027630)(save_buf, 0x002F8000, (int)PTR_DAT_0601f808);
            } else {
                result = *(unsigned int *)course_sel;
                if (result == 2) {
                    result = (*(int(*)())0x06027630)(save_buf, 0x002F8000, buf_size);
                }
            }
        }

        /* Fill unused buffer tail with 0x40/0x80 pattern */
        unsigned int pos;
        for (pos = *(unsigned int *)(0x0604A5C0 + (unsigned int)(unsigned char)*(int *)(0x060877D8 << 2));
             pos < buf_size; pos = pos + 2) {
            result = pos + 1;
            save_buf[pos] = 0x40;
            save_buf[result] = 0x80;
        }

        *(int *)0x0605E0A1 = 0;                    /* clear dirty flag */
    }

    return result;
}

/* cdda_buffer_select -- Select CD audio buffer bank (A or B).
 * param_1=0: use buffer A at 0x060A0FA8, param_1!=0: use buffer B at 0x0607ED90.
 * Stores selection at 0x060877D8 and sets active buffer pointer at 0x0605E098. */
void FUN_0601f87a(unsigned char param_1)
{
  *(unsigned char *)0x060877D8 = param_1;

  if (param_1 == '\0') {
    *(char **)0x0605E098 = (char *)0x060A0FA8;
    *(char *)0x06087080 = 0;
  } else {
    *(char **)0x0605E098 = (char *)0x0607ED90;
    *(char *)0x06087080 = 1;
  }
}

/* nop_f8bc -- Placeholder / stripped function (no-op). */
void FUN_0601f8bc(void)
{
    return;
}

/* FUN_0601f8c0: L2 version in mode_transition.c */
extern int FUN_0601F8C0(void);
int FUN_0601f8c0(void) { return FUN_0601F8C0(); }

/* FUN_0601f900: L2 version in mode_transition.c */
extern int FUN_0601F900(void);
int FUN_0601f900(void) { return FUN_0601F900(); }

/* standings_screen_render -- render race results/standings with layout variant per game mode */
void FUN_0601f9cc()
{
  short final_y;
  char layout_mode;
  char *sprite_cmd;
  char *layout_base;
  char *position_render;
  char *position_table;
  int base_y;
  int header_cmd;
  int header_data;
  int header_y;
  int *standings_entry;
  int row_height;
  int *entry_ptr;
  short vdp2_priority[4];

  vdp2_priority[0] = DAT_0601fa26;

  (*(int(*)())0x0602853E)(0xc);  /* sprite_priority_set(12) */
  (*(int(*)())0x06028560)();     /* sprite_layer_clear */

  sprite_cmd = (char *)0x06028400;  /* sprite_render_full */
  layout_base = (char *)0x06063750; /* standings layout data */

  if (*(int *)0x06078644 == 1) {
    /* Single-player mode: compact layout */
    (*(int(*)())0x0600511E)(0x25E72194,0x00017700,0,8); /* vdp2_register_write */
    (*(int(*)())0x0602761E)(0x25F00600,0x0604894C,0x20); /* dma_copy palette */

    layout_mode = *(int *)0x0605E05C;
    if (layout_mode == '\x04') {
      /* Layout 4: top standings */
      entry_ptr = (int *)(layout_base + PTR_DAT_0601fa28);
      header_data = entry_ptr[1];
      base_y = 0;
    }
    else {
      if (layout_mode != '\b') {
        if (layout_mode == '\f') {
          /* Layout 12: minimal standings */
          (*(int(*)())sprite_cmd)(0xc,*(int *)(layout_base + DAT_0601fac8),0x400,
                            *(int *)((int)(layout_base + DAT_0601fac8) + 4));
        }
        goto LAB_0601fcd4;
      }
      /* Layout 8: mid standings */
      entry_ptr = (int *)(layout_base + DAT_0601fac4);
      header_data = entry_ptr[1];
      base_y = 0x380;
    }
    (*(int(*)())sprite_cmd)(0xc,*entry_ptr,base_y,header_data);
  }
  else {
    /* Multi-player mode: full standings with position rows */
    (*(int(*)())0x0602761E)(0x25F00600,0x0605CD9C,0x20); /* dma_copy palette */

    position_table = (int *)0x0605E0A4; /* position name sprites */
    position_render = (char *)0x060284AE; /* position_sprite_render */
    base_y = 0x590;
    header_y = base_y + 8;
    row_height = 0x90;

    layout_mode = *(int *)0x0605E05C;
    if (layout_mode == '\x04') {
      /* Layout 4: full 13-row leaderboard */
      (*(int(*)())0x060284AE)(0xc,0x80,row_height,*(int *)0x0605E0A4);
      (*(int(*)())sprite_cmd)(0xc,*(int *)(layout_base + header_y),0x98,
                        *(int *)((int)(layout_base + header_y) + 4));
      (*(int(*)())position_render)(0xc,0x180,row_height,*(int *)(position_table + 4));
      (*(int(*)())position_render)(0xc,0x280,row_height,*(int *)(position_table + 8));
      standings_entry = (int *)(layout_base + base_y);
      (*(int(*)())sprite_cmd)(0xc,*standings_entry,(int)DAT_0601fbae,standings_entry[1]);
      (*(int(*)())position_render)(0xc,0x400,row_height,*(int *)(position_table + 0xc));
      (*(int(*)())position_render)(0xc,0x500,row_height,*(int *)(position_table + 0x10));
      (*(int(*)())sprite_cmd)(0xc,*standings_entry,(int)DAT_0601fbb4,standings_entry[1]);
      (*(int(*)())position_render)(0xc,0x600,row_height,*(int *)(position_table + 0x14));
      (*(int(*)())position_render)(0xc,0x700,row_height,*(int *)(position_table + 0x18));
      (*(int(*)())sprite_cmd)(0xc,*standings_entry,0x730,standings_entry[1]);
      (*(int(*)())position_render)(0xc,0x800,row_height,*(int *)(position_table + 0x1c));
      (*(int(*)())position_render)(0xc,0x900,row_height,*(int *)(position_table + 0x20));
      (*(int(*)())position_render)(0xc,0xa00,row_height,*(int *)(position_table + 0x24));
      (*(int(*)())position_render)(0xc,0xb00,row_height,*(int *)(position_table + 0x28));
      (*(int(*)())sprite_cmd)(0xc,*standings_entry,(int)DAT_0601fbc4,standings_entry[1]);
      (*(int(*)())position_render)(0xc,0xc80,row_height,*(int *)0x0605E0E4);
      header_data = standings_entry[1];
      header_cmd = *standings_entry;
      final_y = DAT_0601fbc8;
    }
    else {
      if (layout_mode != '\b') {
        if (layout_mode == '\f') {
          /* Layout 12: compact 3-row results */
          (*(int(*)())0x060284AE)(0xc,0x480,row_height,*(int *)0x0605E0DC);
          (*(int(*)())sprite_cmd)(0xc,*(int *)(layout_base + header_y),0x498,
                            *(int *)((int)(layout_base + header_y) + 4));
          (*(int(*)())position_render)(0xc,0x600,row_height,*(int *)0x0605E0E0);
          standings_entry = (int *)(layout_base + base_y);
          (*(int(*)())sprite_cmd)(0xc,*standings_entry,0x620,standings_entry[1]);
          (*(int(*)())position_render)(0xc,0x800,row_height,*(int *)0x0605E0E4);
          (*(int(*)())sprite_cmd)(0xc,*standings_entry,0x852,standings_entry[1]);
        }
        goto LAB_0601fcd4;
      }
      /* Layout 8: mid 5-row results */
      (*(int(*)())0x060284AE)(0xc,0x380,row_height,*(int *)0x0605E0D0);
      (*(int(*)())sprite_cmd)(0xc,*(int *)(layout_base + header_y),0x398,
                        *(int *)((int)(layout_base + header_y) + 4));
      (*(int(*)())position_render)(0xc,0x500,row_height,*(int *)0x0605E0D4);
      standings_entry = (int *)(layout_base + base_y);
      (*(int(*)())sprite_cmd)(0xc,*standings_entry,(int)DAT_0601fc94,standings_entry[1]);
      (*(int(*)())position_render)(0xc,0x680,row_height,*(int *)0x0605E0D8);
      (*(int(*)())sprite_cmd)(0xc,*standings_entry,0x6b2,standings_entry[1]);
      (*(int(*)())position_render)(0xc,0x880,row_height,*(int *)0x0605E0E4);
      header_data = standings_entry[1];
      header_cmd = *standings_entry;
      final_y = DAT_0601fc9c;
    }
    (*(int(*)())sprite_cmd)(0xc,header_cmd,(int)final_y,header_data);
  }

LAB_0601fcd4:
  /* Reset all matrix transforms and write VDP2 CRAM priority marker */
  layout_base = (char *)0x06038BD4; /* matrix_set function */
  (*(int(*)())0x06038BD4)(0x100,0);
  (*(int(*)())layout_base)(4,0);
  (*(int(*)())layout_base)(8,0);
  (*(int(*)())layout_base)(0x10,0);
  (*(int(*)())layout_base)(0x20,7);
  (*(int(*)())layout_base)(1,0);
  (*(int(*)())0x06036E90)(0x25E7FFFE,1,vdp2_priority); /* vdp2_cram_write */
  (*(int(*)())layout_base)(0x20,7);

  return;
}

/* mode_transition_vdp_reset -- Reset VDP state for mode transition.
 * Forces right-direction input, reinits VDP1 textures/palette,
 * clears render state and command buffer. */
void FUN_0601fd20(void)
{
    INPUT_STATE |= 4;
    vdp1_texture_palette_init();
    *(int *)0x060620D0 = 0;
    *(int *)0x0605A000 = 0;
    *(int *)0x0605A004 = 0;
    VDP1_CMD_BASE_PTR = 0;
    VBLANK_OUT_COUNTER = 0;
}

/* FUN_0601fd74: L2 version in mode_dispatch.c */
extern void FUN_0601FD74(void);
void FUN_0601fd74(void) { FUN_0601FD74(); }

/* replay_car_state_load -- Load car state data from replay descriptor.
 * Reads replay header from pointer at 0x060877F4: [0]=car_count-1,
 * [1]=frame_count, [2]=course_id, [3]=data_start. Iterates each car,
 * assigning car struct pointers (stride 0x268 at 0x06078900) into
 * 0x0607E940, then calls FUN_0601fec0 to load per-car replay data. */
void FUN_0601fe20()
{
    char *car_count_ptr = (char *)0x0607EA98;   /* replay car count */
    char *car_base      = (char *)0x06078900;   /* car struct array */
    char *car_ptr_slot  = (char *)0x0607E940;   /* current car pointer */
    int car_stride = 0x268;
    int *replay_hdr = *(int **)0x060877F4;      /* replay data header */
    unsigned int car_idx;

    *(int *)0x060877FC = replay_hdr[1];         /* store frame count */
    *(int *)car_count_ptr = *replay_hdr + -1;   /* car count (0-based) */
    (*(int(*)())0x060054EA)(replay_hdr[2]);     /* set course */

    int data_ptr = replay_hdr[3];               /* per-car data start */
    *(short *)0x06087800 = 0;
    *(short *)0x06087802 = 0;

    for (car_idx = 0; car_idx <= *(unsigned int *)car_count_ptr; car_idx = car_idx + 1) {
        *(char **)car_ptr_slot = car_base + car_idx * car_stride;
        FUN_0601fec0(data_ptr);
        data_ptr = data_ptr + 8;
    }

    (*(int(*)())0x0600D280)();                  /* post-load finalize */
    *(short *)0x06087804 = 2;                   /* set replay state = active */
}

/* car_replay_state_init -- Initialize car from replay data record.
 * Reads speed (param_1[0] >> 1), heading (param_1[1]), and steering
 * (param_1[2]) from replay record. Sets car speed at multiple physics
 * offsets around DAT_0601ff8a. Computes heading angle via FUN_06027552.
 * Samples track spline via FUN_0600CB90 to get XYZ position (+0x10..+0x18)
 * and rotation (+0x1C..+0x24). Copies rotation to physics state at
 * +0x1A4..+0x1B0. Increments lap counter at +0x1EC, wraps if needed. */
void FUN_0601fec0(param_1)
    unsigned short *param_1;
{
    char *spline_buf = (char *)0x06078680;
    int speed_off = (int)DAT_0601ff8a;
    int car = CAR_PTR_CURRENT;
    int half_speed = (int)(unsigned int)*param_1 >> 1;

    /* Set speed at 4 adjacent offsets */
    *(int *)(car + speed_off) = half_speed;
    *(int *)(car + speed_off + 4) = half_speed;
    *(int *)(car + speed_off + -4) = half_speed;
    *(int *)(car + speed_off + -8) = half_speed;

    /* Compute heading angle */
    unsigned short heading = param_1[1];
    *(unsigned int *)(car + 8) = (unsigned int)heading;
    int angle = (*(int(*)())0x06027552)(0x35a, (unsigned int)heading << 0x10);
    *(int *)(car + 0xc) = angle;
    *(int *)(car + DAT_0601ff8e) = angle;

    /* Set steering at two adjacent offsets */
    unsigned short steering = param_1[2];
    int steer_off = (int)DAT_0601ff90;
    *(unsigned int *)(car + steer_off) = (unsigned int)steering;
    *(unsigned int *)(car + steer_off + -4) = (unsigned int)steering;

    /* Sample track spline for position/rotation */
    (*(int(*)())0x0600CB90)(spline_buf, *param_1);
    *(int *)(car + 0x10) = *(int *)spline_buf;                /* X */
    *(int *)(car + 0x14) = *(int *)(spline_buf + 4);          /* Y */
    *(int *)(car + 0x18) = *(int *)(spline_buf + 8);          /* Z */
    *(int *)(car + 0x1c) = (int)*(short *)(spline_buf + 0xc); /* rot X */
    *(int *)(car + 0x20) = (int)*(short *)(spline_buf + 0xe); /* rot Y */
    *(int *)(car + 0x24) = (int)*(short *)(spline_buf + 0x10);/* rot Z */

    /* Copy rotation to physics state */
    *(int *)(car + 0x30) = *(int *)(car + 0x20);
    *(int *)(car + 0x28) = *(int *)(car + 0x20);
    int phys_off = 0x1b0;
    *(int *)(car + phys_off) = *(int *)(car + 0x20);
    *(int *)(car + phys_off + -0xc) = *(int *)(car + 0x1c);
    *(int *)(car + phys_off + -8) = *(int *)(car + 0x20);
    *(int *)(car + phys_off + -4) = *(int *)(car + 0x24);

    /* Increment lap counter, wrap if exceeds total */
    int lap_off = phys_off + 0x3c;
    *(int *)(car + lap_off) = *(int *)(car + lap_off) + 1;
    if (*(int *)0x0607EA9C < *(int *)(car + lap_off)) {
        *(int *)(car + DAT_0601ff8a) = *(int *)(car + DAT_0601ff8a) - *(int *)0x0607EA9C;
    }
    *(int *)(car + DAT_0601ff8a + -8) = *(int *)(car + DAT_0601ff8a);
}
