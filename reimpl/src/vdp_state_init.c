/* vdp_state_init.c -- VDP/rendering state initialization for game state 12
 *
 * Functions:
 *   FUN_0600A0C0 (0x0600A0C0) -- VDP rendering state initialization
 *
 * Called from the game state machine during state 12 entry.
 * Configures display parameters, initializes rendering buffers,
 * and clears state variables for the rendering pipeline.
 *
 * Original address: 0x0600A0C0
 */

/* External rendering subsystem functions */
extern void FUN_06038BD4(int mode, int param);    /* display mode config */
extern void FUN_06026CE0(void);                    /* rendering pipeline sync */
extern void FUN_06039250(int buf_ptr);             /* buffer initialization */
extern void FUN_060393FC(int r4, int r5, int r6, int r7, int stack_arg);  /* display region config */

/* State variables */
#define RENDER_STATE_A    (*(volatile int *)0x06059F44)
#define RENDER_STATE_B    (*(volatile int *)0x0605A008)
#define RENDER_BUF_PTR    (*(volatile int *)0x06063F5C)


/* ================================================================
 * FUN_0600A0C0 -- VDP Rendering State Init (0x0600A0C0)
 *
 * CONFIDENCE: DEFINITE (binary verified at 0x0600A0C0-0x0600A10A)
 * Pool verified:
 *   0x0600A10E = 0x0100 (display width = 256, mov.w pool)
 *   0x0600A110 = 0x00DF (display height-1 = 223, mov.w pool)
 *   0x0600A112 = 0x015F (display right edge = 351, mov.w pool)
 *   0x0600A120 = 0x06038BD4 (display mode config)
 *   0x0600A124 = 0x06026CE0 (rendering pipeline sync)
 *   0x0600A128 = 0x06059F44 (render state A)
 *   0x0600A12C = 0x06063F5C (render buffer pointer)
 *   0x0600A130 = 0x06039250 (buffer initialization)
 *   0x0600A134 = 0x060393FC (display region config)
 *   0x0600A138 = 0x0605A008 (render state B)
 *   0x0600A13C = 0x00008000 (VDP control flag)
 *
 * 36 instructions. Saves r14, PR.
 * ================================================================ */
#if 0 /* FUN_0600A0C0 -- replaced by ASM import */
void FUN_0600A0C0(void)
{
    /* Configure display mode: width=256, param=0 */
    FUN_06038BD4(0x0100, 0);

    /* Sync rendering pipeline */
    FUN_06026CE0();

    /* Clear render state */
    RENDER_STATE_A = 0;

    /* Initialize rendering buffer */
    FUN_06039250((int)0x06063F5C);

    /* Configure display region: origin=(0,0), height=223, right=351 */
    FUN_060393FC(0, 0, 0, 0x015F, 0x00DF);

    /* Clear secondary render state */
    RENDER_STATE_B = 0;

    /* Write VDP control flag to buffer's target address */
    {
        int buf_val = RENDER_BUF_PTR;
        *(volatile short *)buf_val = (short)0x8000;
    }

    /* Sync rendering pipeline again */
    FUN_06026CE0();

    /* Clear render state (ensures write ordering) */
    RENDER_STATE_A = 0;
}
#endif
