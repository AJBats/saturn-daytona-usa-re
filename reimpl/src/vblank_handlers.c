#include "saturn.h"
#include "game.h"

extern void vdp2_scroll_update(int cmd, int param1, int param2);
extern void vdp2_scroll_setup(int cmd, int param1, int param2);
extern void smpc_intback_trigger(void);
extern void display_list_process(void);
extern void scu_dma_transfer(int dest, int src, int size);
extern void vdp_system_init_b(void);
extern void FUN_060149CC(void);
extern void FUN_060148A2(void);
extern void FUN_06020C3C(void);
extern void FUN_06033354(void);

#define INPUT_ADDR_06063F60 (*(volatile int *)0x06063F60)
#define INPUT_ADDR_060612B4 (*(volatile int *)0x060612B4)
#define INPUT_ADDR_0606129C (*(volatile int *)0x0606129C)
#define INPUT_ADDR_0605B6FC (*(volatile int *)0x0605B6FC)
#define INPUT_ADDR_0605B700 (*(volatile int *)0x0605B700)
#define INPUT_ADDR_0605B704 (*(volatile int *)0x0605B704)
#define INPUT_ADDR_0605B708 (*(volatile int *)0x0605B708)
#define INPUT_ADDR_0605B70C (*(volatile int *)0x0605B70C)
#define INPUT_ADDR_0605B710 (*(volatile int *)0x0605B710)
#define INPUT_ADDR_0605B714 (*(volatile int *)0x0605B714)
#define INPUT_ADDR_0605B718 (*(volatile int *)0x0605B718)
#define INPUT_ADDR_0605B6DC (*(volatile int *)0x0605B6DC)
#define INPUT_ADDR_0605B6E0 (*(volatile int *)0x0605B6E0)
#define INPUT_ADDR_0605B6E4 (*(volatile int *)0x0605B6E4)
#define INPUT_ADDR_0605B6E8 (*(volatile int *)0x0605B6E8)
#define INPUT_ADDR_0605B6EC (*(volatile int *)0x0605B6EC)
#define INPUT_ADDR_0605B6F0 (*(volatile int *)0x0605B6F0)
#define INPUT_ADDR_0605B6F4 (*(volatile int *)0x0605B6F4)
#define INPUT_ADDR_0605B6F8 (*(volatile int *)0x0605B6F8)

#if 0 /* vblank_in_handler -- redirected to ASM import via linker PROVIDE */
void vblank_in_handler(void)
{
    int input;
    unsigned int a;

    VBLANK_COUNTER++;

    VBLANK_PHASE = 1;

    if (VBL_DISABLE_FLAG != 0)
        goto epilogue;

    FB_STATE_VAR = 0;

    {
        unsigned short fb_state = FB_STATE;

        if (fb_state == 2) {
            if (FRAME_READY_FLAG == 0)
                goto timing_compute;
            smpc_intback_trigger();
            FB_STATE_VAR = 2;
            goto timing_compute;
        }

        if (fb_state == 3) {
            if (FRAME_READY_FLAG == 0)
                goto timing_compute;
            {
                unsigned short tvmr_val = TVMR_SHADOW;
                tvmr_val |= 0x08;
                VDP1_TVMR = tvmr_val;
            }
            {
                unsigned short fbcr_val = FBCR_SHADOW;
                fbcr_val |= 0x03;
                VDP1_FBCR = fbcr_val;
            }
            smpc_intback_trigger();
            FB_STATE_VAR = 3;
            goto timing_compute;
        }

        if (fb_state == 0) {
            smpc_intback_trigger();
            FRAME_READY_FLAG = 0;
            goto timing_compute;
        }
    }

    FRAME_SEC_COUNTER++;

    if (FBCR_SWAP_MODE == 1) {
        if (FRAME_SEC_COUNTER >= FBCR_SWAP_THRESHOLD - 1) {
            unsigned short fbcr_val = FBCR_SHADOW;
            fbcr_val |= 0x02;
            VDP1_FBCR = fbcr_val;
        }
    }

    if (FRAME_SEC_COUNTER >= FBCR_SWAP_THRESHOLD) {
        if (FRAME_READY_FLAG != 0) {
            smpc_intback_trigger();
            FB_STATE_VAR = 1;
        }
        FRAME_SEC_COUNTER = 0;
    }

timing_compute:
    a = (unsigned int)TIMING_VAL_3C >> 2;
    TIMING_RESULT = (int)(a * 16 + a * 64 + ((unsigned int)TIMING_VAL_38 >> 1) + TIMING_BASE_ADDR);

    input = INPUT_STATE;

    if (input & 0x20000000)
        scu_dma_transfer(INPUT_ADDR_06063F60, TIMING_RESULT, 0x0640);

    if (input & 0x04)
        scu_dma_transfer(INPUT_ADDR_060612B4, INPUT_ADDR_0606129C, 0x0E00);

    if (input & 0x10)
        vdp2_scroll_update(4, INPUT_ADDR_0605B6FC, INPUT_ADDR_0605B700);

    if (input & 0x20)
        vdp2_scroll_update(8, INPUT_ADDR_0605B704, INPUT_ADDR_0605B708);

    if (input & 0x40)
        vdp2_scroll_update(16, INPUT_ADDR_0605B70C, INPUT_ADDR_0605B710);

    if (input & 0x80)
        vdp2_scroll_update(32, INPUT_ADDR_0605B714, INPUT_ADDR_0605B718);

    if (input & 0x00010000)
        vdp2_scroll_setup(4, INPUT_ADDR_0605B6DC, INPUT_ADDR_0605B6E0);

    if (input & 0x00020000)
        vdp2_scroll_setup(8, INPUT_ADDR_0605B6E4, INPUT_ADDR_0605B6E8);

    if (input & 0x00040000)
        vdp2_scroll_setup(16, INPUT_ADDR_0605B6EC, INPUT_ADDR_0605B6F0);

    if (input & 0x00080000)
        vdp2_scroll_setup(32, INPUT_ADDR_0605B6F4, INPUT_ADDR_0605B6F8);

    if (input & 0x80000000u)
        vdp_system_init_b();

    if (input & 0x40000000)
        FUN_060149CC();

    if (input & 0x00100000)
        FUN_060148A2();

    if (input & 0x04000000)
        FUN_06020C3C();

    if (input & 0x08000000)
        FUN_06033354();

    INPUT_STATE = 0;

epilogue:
    VBLANK_PHASE = 2;
}
#endif /* vblank_in_handler */


void vblank_out_handler(void)
{
    VBLANK_OUT_COUNTER++;

    VBLANK_PHASE = 3;

    display_list_process();

    {
        int state = GAME_STATE;
        int out_count = VBLANK_OUT_COUNTER;
        unsigned char target = FRAME_TIMING_TABLE[state];

        if (out_count >= (int)(unsigned int)target) {
            if (FB_STATE_VAR != 0) {
                unsigned short fbcr_val = FBCR_SHADOW;
                fbcr_val |= 0x03;
                VDP1_FBCR = fbcr_val;
                FRAME_READY_FLAG = 0;
                FB_STATE_VAR = 0;
            }
        }
    }

    VBLANK_PHASE = 4;
}
