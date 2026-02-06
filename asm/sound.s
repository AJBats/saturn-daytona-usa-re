! === Daytona USA Saturn — Sound System ===
!
! Architecture: SH-2 (master CPU) communicates with 68EC000 (sound CPU)
! through shared sound RAM (0x25A00000-0x25A7FFFF, 512KB).
!
! The 68000 runs a sound driver that reads commands from a mailbox
! and drives the SCSP (Saturn Custom Sound Processor) directly.
!
! There is NO direct SCSP register manipulation from SH-2 during gameplay.
! All sound triggers go through the mailbox → 68000 driver → SCSP path.
!
! === Memory Map ===
!
! 0x25A00000  Sound RAM base (512KB, shared SH-2 ↔ 68000)
! 0x25A02C20  COMMAND MAILBOX — SH-2 writes, 68000 reads and clears to 0
! 0x25A02DBC  INIT HANDSHAKE — 68000 writes marker during boot
! 0x25A02DBE  DRIVER READY — 68000 sets to 0xFFFF when sound driver is up
! 0x25A02D97  CONTROL BYTE — written 0 during init (mute/reset flag?)
! 0x25A03000  Sound driver code area (DMA'd from main RAM during init)
! 0x25A10000  Sound sample data area (DMA'd from CD/main RAM)
!
! 0x25B00000  SCSP slot registers (32 slots × 0x20 bytes)
! 0x25B00217  Slot 16, offset 0x17 — EFSDL/EFPAN (effect send level/pan)
! 0x25B00237  Slot 17, offset 0x17 — EFSDL/EFPAN
! 0x25B00400  SCSP common control registers
!
! 0x0608604C  Local mirror of last command sent (work RAM)
! 0x06086050  Timeout error flag (non-zero = handshake failed)
! 0x06086054  Sound timer (used by periodic SFX triggers)
!
! === Communication Protocol ===
!
! 1. SH-2 calls FUN_0601DB84 (busy-wait) — polls [0x25A02C20] until 0
! 2. SH-2 writes 32-bit command to [0x25A02C20]
! 3. 68000 reads command, processes it, clears [0x25A02C20] to 0
! 4. SH-2 also mirrors command to [0x0608604C] for local tracking
!
! Timeout: 100,000 iterations (0x186A0). If exceeded, sets [0x06086050] = 1.
!
! === Sound Command Format ===
!
! Commands are 32-bit values: 0xAAGGIIFF
!   AA = Command prefix (0xAE for sound triggers)
!   GG = Sound group
!   II = Sound ID within group
!   FF = Suffix (always 0xFF for play-now)
!
! Known sound groups:
!   00 = System/control (0xAE0001FF = stop, 0xAE0007FF = init)
!   05 = System variant (0xAE0005FF)
!   06 = Background music (0xAE0600FF = start BGM)
!   11 = Gameplay SFX:
!        0xAE1114FF = engine/periodic SFX (triggered on 120-frame timer)
!        0xAE111BFF = button-triggered SFX (bit 0x10)
!        0xAE1138FF = race countdown/lap SFX (every 64 frames)
!        0xAE1139FF = race SFX variant (course 1 specific)
!
! Channel commands (used with FUN_0601D5F4 dispatch):
!   r4=0: Direct command — write r5 to mailbox
!   r4=1: Channel 1 volume — 0xA07000FF + (r5 << 8)
!   r4=2: Channel 2 config — 0xA17000FF + (r5 << 8)
!   r4=3: Channel 3 config — 0xA27000FF + (r5 << 8)
!   r4=4: Raw pass-through — write r5 directly
!   r4=5: Channel 5 config — 0xA37000FF + (r5 << 8)
!   r4=15: Same as r4=0 (alternate entry for direct command)
!
! ===========================================================================


! === FUN_0601D5F4 — Sound Command Dispatcher (MAIN API) ===
!
! Entry: r4 = command type (0-5, 15), r5 = parameter (sound ID or volume)
! Called from 30+ locations across the entire game.
! This is THE primary sound interface used by all gameplay code.
!
! Dispatches on r4 to different command handlers:
!   0  → write r5 to mailbox (play sound)
!   1  → channel 1 volume control
!   2  → channel 2 config
!   3  → channel 3 config
!   4  → raw pass-through
!   5  → channel 5 config
!   15 → same as 0
!
! All paths check [0x06086050] for timeout errors first.
! If error flag is non-zero, returns immediately (sound system dead).

FUN_0601D5F4:                           ! 0x0601D5F4
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x74,PC),r0               ! r0 = [0x06086050] (error flag)
    mov.l   @r0,r0
    tst     r0,r0
    bf/s    .snd_exit                   ! If error, skip everything
    mov     r5,r14                      ! r14 = command parameter
    mov.l   @(0x70,PC),r5               ! r5 = 0xA0000000 (direct cmd mask)
    bra     .snd_dispatch
    mov     r4,r0                       ! r0 = command type

! --- Case 0: Direct command (play sound) ---
.snd_case0:
    mov     r14,r2
    and     r5,r2                       ! r2 = r14 & 0xA0000000
    cmp/eq  r5,r2                       ! Is it a direct sound command?
    bf      .snd_exit                   ! No → ignore
    bsr     FUN_0601DB84                ! Wait for mailbox clear
    nop
    mov.l   @(0x60,PC),r3               ! r3 = 0x25A02C20 (mailbox)
    mov.l   r14,@r3                     ! Write command to mailbox
    mov.l   @(0x60,PC),r3               ! r3 = 0x0608604C (local mirror)
    mov.l   r14,@r3                     ! Copy to local mirror
    bra     .snd_exit
    nop

! --- Case 1: Channel 1 volume ---
.snd_case1:
    shll8   r14                         ! r14 = volume << 8
    mov.l   @(0x5C,PC),r4               ! r4 = 0xA07000FF (ch1 base)
    add     r14,r4                      ! r4 = 0xA070VVFF (V=volume)
    lds.l   @r15+,pr
    bra     FUN_0601D6D4                ! → write to mailbox
    mov.l   @r15+,r14

! --- Case 2-5: Similar channel configs ---
! (Each uses a different base: 0xA17000FF, 0xA27000FF, 0xA37000FF)

! --- Dispatch table ---
.snd_dispatch:
    cmp/eq  #0,r0
    bt      .snd_case0
    cmp/eq  #1,r0
    bt      .snd_case1
    cmp/eq  #2,r0
    bt      .snd_case2
    cmp/eq  #3,r0
    bt      .snd_case3
    cmp/eq  #4,r0
    bt      .snd_case4
    cmp/eq  #5,r0
    bt      .snd_case5
    cmp/eq  #15,r0
    bt      .snd_case15                 ! Case 15 = same as case 0

.snd_exit:
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! === FUN_0601DB84 — Mailbox Busy Wait ===
!
! Polls [0x25A02C20] (command mailbox) until it reads 0,
! meaning the 68000 has consumed the previous command.
! Timeout: 100,000 iterations. Sets [0x06086050] = 1 on timeout.
!
! Called before every command write to prevent overwriting
! an unprocessed command.

FUN_0601DB84:                           ! 0x0601DB84
    mov.l   @(0x18,PC),r7               ! r7 = 0x06086050 (error flag addr)
    mov.l   @(0x1C,PC),r6               ! r6 = 0x25A02C20 (mailbox addr)
    mov     #1,r5                       ! r5 = 1 (error code)
    mov.l   @(0x1C,PC),r4               ! r4 = 100000 (0x186A0) timeout
.busywait_loop:
    dt      r4                          ! r4--; if (r4==0) T=1
    bf      .busywait_check             ! Not timed out yet
    bra     .busywait_done              ! TIMEOUT — set error
    mov.l   r5,@r7                      ! [0x06086050] = 1
.busywait_check:
    mov.l   @r6,r0                      ! r0 = [0x25A02C20]
    tst     r0,r0                       ! Is mailbox clear?
    bf      .busywait_loop              ! No → keep waiting
.busywait_done:
    rts
    nop


! === FUN_0601D6B2 — Direct Sound Command Write ===
!
! Simpler alternative to FUN_0601D5F4.
! Entry: r4 = raw 32-bit sound command
! Waits for mailbox, writes r4 directly to both
! [0x25A02C20] (sound RAM) and [0x0608604C] (local mirror).

FUN_0601D6B2:                           ! 0x0601D6B2
    sts.l   pr,@-r15
    add     #-4,r15
    bsr     FUN_0601DB84                ! Wait for mailbox clear
    mov.l   r4,@r15                     ! Save command on stack
    mov.l   @r15,r2                     ! Reload command
    mov.l   @(0xC,PC),r3                ! r3 = 0x25A02C20
    mov.l   r2,@r3                      ! [mailbox] = command
    mov.l   @r15,r2                     ! Reload command
    mov.l   @(0xC,PC),r3                ! r3 = 0x0608604C
    add     #4,r15
    lds.l   @r15+,pr
    rts
    mov.l   r2,@r3                      ! [mirror] = command


! === FUN_06018EE4 — Sound System Initialization ===
!
! Called during game startup. Full sequence:
! 1. SMPC SNDOFF (cmd 7) — halt 68000 sound CPU
! 2. Clear 512KB sound RAM (FUN_060192B4)
! 3. Write SCSP common register at 0x25B00400
! 4. DMA sound driver code to 0x25A00000 (via FUN_06012E84)
! 5. DMA sound driver data to 0x25A03000 (via FUN_06012EBC)
! 6. SMPC SNDON (cmd 6) — restart 68000 sound CPU
! 7. Wait for driver ready: poll [0x25A02DBC] == expected marker
! 8. Call FUN_0601D5F4 to configure initial SCSP slot settings
! 9. Tail-call FUN_06018EC8 to set master volume
!
! The SMPC commands are:
!   COMREG (0x2010001F) = 7 → SNDOFF (halt sound CPU)
!   COMREG (0x2010001F) = 6 → SNDON  (start sound CPU)
!   SF (0x20100063) = status flag, bit 0 = busy
!
! SMPC handshake: wait for SF bit 0 clear → set SF=1 → write COMREG → wait for SF clear

FUN_06018EE4:                           ! 0x06018EE4
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x88,PC),r11               ! r11 = 0x25A02DBC (init handshake)
    mov.w   @(0x80,PC),r12               ! r12 = expected ready marker
    mov.l   @(0x88,PC),r13               ! r13 = 0x20100063 (SMPC SF)
    mov     #1,r14                       ! r14 = 1
! --- Wait for SMPC idle ---
.snd_init_wait1:
    mov.b   @r13,r2                      ! Read SF
    extu.b  r2,r2
    and     r14,r2                       ! Mask bit 0
    cmp/eq  r14,r2
    bt      .snd_init_wait1              ! Loop while busy
! --- Send SNDOFF ---
    extu.b  r14,r2
    mov.b   r2,@r13                      ! SF = 1 (claim bus)
    mov     #7,r3                        ! SNDOFF command
    mov.l   @(0x78,PC),r2                ! r2 = 0x2010001F (COMREG)
    mov.b   r3,@r2                       ! COMREG = 7 (SNDOFF)
! --- Wait for SNDOFF completion ---
.snd_init_wait2:
    mov.b   @r13,r2
    extu.b  r2,r2
    and     r14,r2
    tst     r2,r2
    bf      .snd_init_wait2              ! Loop while SF busy
! --- Clear sound RAM + DMA driver ---
    bsr     FUN_060192B4                 ! Clear 512KB sound RAM
    nop
    mov.w   @(0x5A,PC),r2               ! SCSP config value
    mov.l   @(0x68,PC),r3                ! r3 = 0x25B00400
    mov.w   r2,@r3                       ! Write SCSP common register
    mov.l   @(0x68,PC),r3                ! r3 = FUN_06012E84
    jsr     @r3                          ! DMA driver code → 0x25A00000
    nop
    mov.l   @(0x64,PC),r3                ! r3 = FUN_06012EBC
    jsr     @r3                          ! DMA driver data → 0x25A03000
    nop
! --- Send SNDON ---
! (Second SMPC handshake: wait idle → set SF → COMREG=6 → wait clear)
! --- Wait for sound driver ready ---
.snd_init_poll:
    mov.w   @r11,r3                      ! Read [0x25A02DBC]
    extu.w  r3,r3
    cmp/eq  r12,r3                       ! Match expected marker?
    bf      .snd_init_poll               ! Loop until ready
! --- Configure SCSP slots ---
    ! FUN_0601D5F4(15, 0xAE0600FF) — play init sound?
    ! FUN_0601D5F4(15, 0xAE0007FF) — system init sound
    ! Clear [0x06086038] = 0
! --- Tail call: set master volume ---
    ! jmp FUN_06018EC8


! === FUN_060192B4 — Clear Sound RAM ===
!
! Zeros the entire 512KB sound RAM area (0x25A00000-0x25A7FFFF).
! Byte-by-byte write of 0. Called during sound system init before
! DMA'ing the sound driver.

FUN_060192B4:                           ! 0x060192B4
    mov     #0,r5                       ! Fill value = 0
    mov.l   @(0x44,PC),r6               ! r6 = 0x25A00000 (sound RAM base)
    mov.l   @(0x44,PC),r4               ! r4 = 0x0007FFFF (512K-1 bytes)
.clr_loop:
    mov     r6,r3
    exts.b  r5,r2                       ! r2 = 0
    add     #1,r6
    dt      r4
    bf/s    .clr_loop
    mov.b   r2,@r3                      ! Write 0 to each byte
    rts
    nop


! === FUN_060192E8 — Wait for Sound Driver Ready ===
!
! Polls [0x25A02DBE] waiting for 0xFFFF (driver-ready signal).
! 100,000 iteration timeout. On timeout, sets [0x06086050] = 1.
!
! Called during sound init after SNDON to wait for 68000 driver boot.

FUN_060192E8:                           ! 0x060192E8
    mov.l   @(0x1C,PC),r1               ! r1 = 0x06086050 (error flag)
    mov.l   @(0x20,PC),r7               ! r7 = 0x25A02DBE (ready flag)
    mov.l   @(0x20,PC),r6               ! r6 = 0x0000FFFF (expected value)
    mov     #1,r5                       ! r5 = 1 (error code)
    mov.l   @(0x20,PC),r4               ! r4 = 100000 (timeout)
.ready_loop:
    dt      r4
    bf      .ready_check
    bra     .ready_timeout
    mov.l   r5,@r1                      ! [error_flag] = 1 (TIMEOUT)
.ready_check:
    ! (reads [0x25A02DBE], compares with 0xFFFF, loops)


! === FUN_060192CC — Reset Sound Channels ===
!
! Sends stop command (r5=0) to channels 1, 3, and 2 via FUN_0601D5F4.
! Used during state transitions to silence all sound.

FUN_060192CC:                           ! 0x060192CC
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x30,PC),r14               ! r14 = FUN_0601D5F4
    jsr     @r14
    mov     #1,r4                        ! Stop channel 1
    mov     #0,r5
    jsr     @r14
    mov     #3,r4                        ! Stop channel 3
    mov     #0,r5
    jsr     @r14
    mov     #2,r4                        ! Stop channel 2
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! === FUN_06018EC8 — Set SCSP Master Volume ===
!
! Writes 0xE0 to SCSP slot 16 and slot 17 EFSDL/EFPAN registers.
! Sets the effect send level for the main output channels.
!
! SCSP slot layout: base + slot*0x20 + offset
!   Slot 16: 0x25B00200, offset 0x17 = 0x25B00217
!   Slot 17: 0x25B00220, offset 0x17 = 0x25B00237

FUN_06018EC8:                           ! 0x06018EC8
    mov.w   @(0xA,PC),r4                ! r4 = 0x00E0 (volume level)
    mov.l   @(0x10,PC),r2               ! r2 = 0x25B00217 (slot 16)
    extu.b  r4,r3                       ! r3 = 0xE0
    mov.b   r3,@r2                      ! [slot 16 EFSDL] = 0xE0
    mov.l   @(0xC,PC),r3                ! r3 = 0x25B00237 (slot 17)
    rts
    mov.b   r4,@r3                      ! [slot 17 EFSDL] = 0xE0


! === FUN_0602766C — SCU DMA Level 0 Transfer (NOT sound-specific!) ===
!
! Generic DMA transfer function. Often confused with sound dispatch
! because it's called from many places, but it transfers arbitrary data.
!
! Entry: r5 = source address, r4 = destination address, r6 = byte count
!
! SCU DMA Level 0 registers:
!   0x25FE0000 = D0R  (source address)      ← r5
!   0x25FE0004 = D0W  (destination address)  ← r4
!   0x25FE0008 = D0C  (byte count)           ← r6
!   0x25FE000C = D0AD (address increment)    ← 0x0101 (src+1, dst+1)
!   0x25FE0010 = D0EN (enable)               ← 0x0101
!   0x25FE0014 = D0MD (mode/start)           ← 7
!   0x25FE007C = DSTA (DMA status)           — polled with mask 0x272E
!
! Used for: VDP2 palette uploads, sound data transfers, general memcpy.

FUN_0602766C:                           ! 0x0602766C
    mov.l   @(0x1C,PC),r0               ! r0 = 0x25FE007C (DSTA)
    mov.l   @r0,r0                      ! Read DMA status
    mov.l   @(0x1C,PC),r1               ! r1 = 0x0000272E (busy mask)
    tst     r1,r0                       ! All channels idle?
    bf      FUN_0602766C                ! No → keep polling
    mov.l   @(0x1C,PC),r1               ! r1 = 0x25FE0000 (DMA base)
    mov.w   @(0xE,PC),r2                ! r2 = 0x0101 (addr increment)
    mov.l   r4,@(0x4,r1)                ! D0W = r4 (destination)
    mov.l   r5,@(0x0,r1)                ! D0R = r5 (source)
    mov.l   r6,@(0x8,r1)                ! D0C = r6 (byte count)
    mov.l   r2,@(0xC,r1)                ! D0AD = 0x0101
    mov     #7,r0
    mov.l   r0,@(0x14,r1)               ! D0MD = 7 (start transfer)
    rts
    mov.l   r2,@(0x10,r1)               ! D0EN = 0x0101


! === Gameplay Sound Trigger Examples ===
!
! FUN_0600A000 (0x0600A000) — Sound State Transition
!   Called during game state changes. Sequence:
!   1. FUN_0601D5F4(1, r5)  — set channel 1 (r5 from caller: 0 or config)
!   2. FUN_0601D5F4(3, 0)   — stop channel 3
!   3. FUN_0601D5F4(2, 0)   — stop channel 2
!   4. FUN_0601D5F4(0, 0xAE0001FF) — play system sound
!   5. FUN_0601D5F4(0, 0xAE0600FF) — start background music
!
! FUN_06005BFA area — Engine/Periodic SFX
!   Triggered when a frame counter reaches 120 (2 seconds at 60fps).
!   Plays 0xAE1114FF via FUN_0601D5F4(0, 0xAE1114FF).
!   Adjusts a volume/rate parameter by >>3 each frame.
!
! FUN_060082A0 area — Button-Triggered SFX
!   When controller bit 0x10 is pressed AND a flag is set:
!   Plays 0xAE111BFF via FUN_0601D5F4(0, 0xAE111BFF).
!
! FUN_0600DC3A area — Race Countdown/Event SFX
!   Triggers every 64 frames (timer & 0x3F == 0).
!   Counter < 7: play 0xAE1138FF (standard countdown beep)
!   Counter >= 7 AND course == 1: play 0xAE1139FF (course-specific variant)
!   Counter >= 7 AND course != 1: play 0xAE1138FF
!   Resets timer to 40, clears counter.
!
! FUN_06009742 area — State handler sound (attract mode / demo)
! FUN_06009866 area — State handler sound (mode select)
! FUN_0600F668 area — Race event sounds
! FUN_0600FD58 area — Race result sounds

! === Memory Copy Utility Functions (near sound code) ===
!
! These are grouped at 0x0602760C-0x0602766C:
!   FUN_0602760C: byte copy (mov.b), r4=dst, r5=src, r6=count
!   FUN_0602761E: word copy (mov.w), r4=dst, r5=src, r6=count
!   FUN_06027630: long copy (mov.l), r4=dst, r5=src, r6=count
!   FUN_06027642: block copy (8 longs × dt loop), r4=dst, r5=src, r6=blocks
!   FUN_0602766C: SCU DMA transfer (documented above)
