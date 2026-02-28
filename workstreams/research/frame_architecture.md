# Frame Architecture — Primary SH-2

Two execution contexts share one CPU via hardware interrupts.

## "Game thread" — Main loop (sym_06003000)

Runs once per frame. Handles game state logic:
- `per_frame_update` — CD reads, AI section updates, timers
- State handler (varies by game state, e.g. `state_course_select_active`)

Finishes early during menus. Heavy during racing (physics, collision, AI).

## "Render thread" — Timer interrupt (framebuf_swap_ctrl)

FRT Output Compare A interrupt. Fires **334 times per frame** (~50us interval).
Preempts main loop, runs handler, returns via RTE.

Most firings are no-ops (check flag, return). A few per frame do real work:
- `vblank_out_handler` — controller input (SMPC), VBlank processing
- `master_menu_render` — rendering, animation, scene dispatch
- `button_input_read` — input → scene routing

Rendering and input happen IN the interrupt context, not from the main loop.

## Timer math

- OCRA = 0x0166 (358 cycles), set in `system_init.s`
- CPU = 28.636 MHz (NTSC), 4x prescaler = 7.159 MHz
- 358 / 7.159 MHz = ~50us per interrupt
- 16.667ms (60Hz frame) / 50us = **334.1 interrupts/frame**

## Two timing systems on one FRT

| Feature | Rate | Purpose |
|---------|------|---------|
| OCRA compare match | 334x/frame (50us) | Heartbeat — drives rendering, input, display |
| ICF input capture | 1x/frame (VBlank edge) | Frame sync — primary/secondary SH-2 handshake |

## Communication

Main loop and interrupt share state via globals (e.g. `g_pad_state`, frame counters).
No explicit synchronization — interrupt preempts main loop atomically.

## Orphan roots in call graphs

Call trace captures JSR/BSR only. `framebuf_swap_ctrl` appears as a disconnected
root because it's an interrupt handler (no JSR calls it — hardware vectors to it).
Functions reached via BRA/BT/BF (branches, tail calls) also appear as orphan roots.
