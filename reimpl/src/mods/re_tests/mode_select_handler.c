/* mode_select_handler — C reimplementation of mode select navigation
 *
 * Original ASM: reimpl/retail/FUN_060196B0.s (section .text.FUN_060196B0)
 * Handles B (back to title), DOWN (next item), UP (prev item) on mode select.
 * A/C confirm is handled by the per-item dispatched renderers, not here.
 *
 * VERIFIED via watchpoint on sym_0605D244 (selection index):
 *   DOWN: increments index, wraps 4->0
 *   UP:   decrements index, wraps -1->3
 *   B:    writes g_game_state=4 (return to title)
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

/* --- External symbols (all resolved by linker) --- */

/* Functions */
extern void scene_dual_finalize(int);
extern void sym_06028400(int r4, u32 r5, u32 r6, u32 r7);

/* Pad state: array of u16 words. Buttons at index 1 (offset +2). */
extern u16 g_pad_state[];

/* Mode select state */
extern s8  sym_0605D244;   /* selection index (0-3) */
extern u8  sym_0605D242;   /* counter byte */
extern u8  sym_0605D243;   /* animation timer byte */
extern u32 g_game_state;
extern u8  sym_06085FF1;   /* lock/active flag */
extern u8  sym_06085FF5;   /* secondary flag */
extern u32 sym_06059F44;   /* cleared on B press */
extern u8  sym_0605B6D8;   /* another flag (sym_0601978C target) - UNUSED HERE */

/* Lookup tables (runtime-populated, in RAM) */
extern u16 sym_06049AF4[]; /* table1: indexed by selection_index */
extern u32 sym_06063750[]; /* table2: stride 2 dwords (8 bytes), field at +1 */
extern u8  sym_06049AEC[]; /* table3: 2 bytes per entry */

/* Dispatch table: 4 function pointers, one per menu item */
extern void (*sym_0605D250[])(void);

/* Button masks */
#define BTN_B    0x0100
#define BTN_DOWN 0x2000
#define BTN_UP   0x1000

__attribute__((section(".text.FUN_060196B0")))
void mode_select_handler(void)
{
    scene_dual_finalize(1);

    u16 buttons = g_pad_state[1]; /* offset +2 */

    if (buttons & BTN_B) {
        /* B pressed: complex lookup + call, then return to title */
        s8 idx = sym_0605D244;
        int idx2 = (u8)idx * 2;

        /* table1 lookup */
        u16 t1_val = sym_06049AF4[idx];
        /* table2 lookup: stride 8 bytes = 2 dwords, read dword at +4 */
        u32 t2_ptr = (&sym_06063750[0])[t1_val * 2 + 1];
        t2_ptr += 0x2000;

        /* table3 lookup */
        u8 t3_b0 = sym_06049AEC[idx2];
        u8 t3_b1 = sym_06049AEC[idx2 + 1];
        u32 arg6 = ((u32)t3_b1 << 6) + (u32)t3_b0;
        arg6 *= 2;

        u32 arg5 = *(u32 *)t2_ptr;

        sym_06028400(0xC, arg5, arg6, t2_ptr);

        if (sym_0605D244 > 1) {
            sym_0605D244 = 0;
        }
        sym_06059F44 = 0;
        sym_0605D242 = 0;
        g_game_state = 4;
        sym_06085FF1 = 1;
        sym_06085FF5 = 1;
        return;
    }

    if (buttons & BTN_DOWN) {
        sym_06085FF1 = 1;
        sym_0605D242 = 5;
        sym_0605D244++;
        if (sym_0605D244 >= 4) {
            sym_0605D244 = 0;
        }
    } else if (buttons & BTN_UP) {
        sym_06085FF1 = 1;
        sym_0605D242 = 5;
        sym_0605D244--;
        if (sym_0605D244 < 0) {
            sym_0605D244 = 3;
        }
    }

    /* Common exit: increment counters, dispatch to per-item handler */
    sym_0605D243++;
    sym_0605D242++;

    /* Tail-call dispatch: jump to handler for current selection */
    sym_0605D250[(u8)sym_0605D244]();
}
