! ================================================
! AUDIT: DEFINITE — SMPC controller input pipeline confirmed by hardware register addresses
! Audited: 2026-02-10
! ================================================
!
! ============================================================================
! input_smpc.s — Saturn SMPC Controller Input System
! ============================================================================
!
! This file covers the full input pipeline from hardware to game code.
! Three stages:
!   1. FUN_060030FC sends INTBACK command to SMPC
!   2. Code at 0x06039924 reads OREG response into struct at 0x060A4C9C
!   3. FUN_06006F3C reads processed input from 0x0605B6D8, tests button bits
!
! SMPC register addresses:
!   0x2010001F = COMREG  (command register, write 0x19 for INTBACK)
!   0x20100021 = OREG0   (first output register — peripheral ID/extra data)
!   0x20100031 = OREG8   (peripheral ID upper nibble)
!   0x20100033 = OREG9   (peripheral ID lower / data size)
!   0x20100035 = OREG10  (button byte 1)
!   0x20100037 = OREG11  (button byte 2)
!   0x20100039 = OREG12  (extended data byte 1)
!   0x2010003B = OREG13  (extended data byte 2)
!   0x2010003D = OREG14  (extended data byte 3)
!   0x2010003F = OREG15  (extended data byte 4)
!   0x20100061 = SR      (status register)
!   0x20100063 = SF      (status flag — bit 0 = command in progress)
!
! Raw peripheral data struct at 0x060A4C9C:
!   +0x00: byte  — OREG8  (peripheral ID upper)
!   +0x01: byte  — OREG9  (peripheral ID lower)
!   +0x02: word  — (OREG10 << 8) | OREG11   (buttons 1)
!   +0x04: long  — OREG12..15 packed         (buttons 2 + extended)
!   +0x08: byte  — OREG0  (additional peripheral data)
!
! Processed input at 0x0605B6D8 (32-bit word, active-low button bits):
!   bit 2  (0x04) = Right?   bit 4  (0x10) = Left?
!   bit 5  (0x20) = Start?   bit 6  (0x40) = A button (gas)
!   bit 7  (0x80) = B button (brake)
!   bit 29 (0x20000000) = unknown special flag
! ============================================================================


! ============================================================================
! STAGE 1: FUN_060030FC — SMPC INTBACK Command Sender
! ============================================================================
! CONFIDENCE: DEFINITE — Binary verified: mov.l r14,@-r15; mov #1,r14; r13=0x20100063 (SMPC SF);
!   writes 0x19 to 0x2010001F (COMREG). All SMPC addresses match Saturn hardware spec exactly.
! Called once during system init from the main loop setup.
! Sends the INTBACK command (0x19) to SMPC COMREG to request peripheral data.
! Polls SMPC SF register waiting for command acceptance, then completion.
! Also initializes subsystems via indirect call chain.
!
! r13 = 0x20100063 (SMPC SF register)
! r14 = 1 (used as both poll mask and INTBACK ready flag)
! r12 = 0 (used to zero out init table entries)

FUN_060030FC:                       ! System init — called once at startup
    mov.l   r14,@-r15              ! Save callee-saved registers
    mov     #1,r14                 ! r14 = 1 (poll bit mask for SF.bit0)
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov     #0,r12                 ! r12 = 0 (used to zero init entries later)
    mov.l   r10,@-r15
    sts.l   pr,@-r15               ! Save return address
    mov.l   @(0x40,PC),r10        ! r10 = 0x06059C58 (init table pointer A)
    mov.l   @(0x44,PC),r11        ! r11 = 0x06059C50 (init table pointer B)
    mov.l   @(0x44,PC),r13        ! r13 = 0x20100063 (SMPC SF register)
    mov.l   @(0x48,PC),r3         ! r3 -> indirect function pointer at 0x06000320
    mov.l   @r3,r3                 ! r3 = actual function address
    jsr     @r3                    ! Call subsystem init function
    mov     r14,r4                 ! r4 = 1 (parameter: init phase 1)

! --- Poll SMPC SF until bit 0 is SET (command accepted) ---
.poll_sf_set:
    mov.b   @r13,r2               ! Read SMPC SF register
    extu.b  r2,r2                  ! Zero-extend to 32-bit
    and     r14,r2                 ! Isolate bit 0
    cmp/eq  r14,r2                 ! Is bit 0 == 1? (SMPC accepted previous cmd)
    bt      .poll_sf_set           ! Spin until SF.bit0 = 1

! --- Write INTBACK command ---
    extu.b  r14,r2                 ! r2 = 1
    mov.b   r2,@r13               ! Write 1 to SF (acknowledge/clear)
    mov     #25,r3                 ! r3 = 0x19 = INTBACK command
    mov.l   @(0x34,PC),r2         ! r2 = 0x2010001F (SMPC COMREG)
    mov.b   r3,@r2                 ! Write INTBACK command to COMREG

! --- Poll SMPC SF until bit 0 is CLEAR (command completed) ---
.poll_sf_clear:
    mov.b   @r13,r2               ! Read SMPC SF register
    extu.b  r2,r2
    and     r14,r2                 ! Isolate bit 0
    tst     r2,r2                  ! Is bit 0 == 0? (INTBACK completed)
    bf      .poll_sf_clear         ! Spin until SF.bit0 = 0

! After INTBACK completes, OREGs contain peripheral data.
! The response handler at 0x06039924 reads them into the peripheral struct.
! (Init continues with zeroing out subsystem tables via r10/r11/r12 loop...)


! ============================================================================
! STAGE 2: INTBACK Response Handler (at 0x06039924, inside FUN_0603953C)
! ============================================================================
! CONFIDENCE: DEFINITE — Binary verified: r10=0x20100061 (SMPC SR), reads OREG8-15 at
!   0x20100031-3F, packs into struct at 0x060A4C9C. All register offsets and byte-packing
!   logic confirmed instruction-by-instruction against aprog.s.
! After INTBACK completes, this code reads SMPC Output Registers (OREGs)
! and packs them into the raw peripheral data struct at 0x060A4C9C.
! This is called from the SMPC processing path, not directly from game code.
!
! Register setup at entry:
!   r10 = 0x20100061 (SMPC SR)
!   r11 = 0x060A4CF4 (related peripheral state)
!   r12 = 0x060A4D04 (related peripheral state)
!   r13 = 1 (constant)
!   r14 = 0x060A4CEC (related peripheral state)

! --- Disable interrupts for atomic OREG read ---
.intback_response:                  ! 0x06039924
    mov.l   @(0x3C,PC),r10        ! r10 = 0x20100061 (SMPC SR)
    mov.l   @(0x40,PC),r11        ! r11 = 0x060A4CF4
    mov.l   @(0x40,PC),r12        ! r12 = 0x060A4D04
    mov     #1,r13                 ! r13 = 1 (constant used throughout)
    mov.l   @(0x40,PC),r14        ! r14 = 0x060A4CEC
    stc     sr,r0                  ! Save current SR (interrupt mask)
    shlr2   r0                     ! Extract interrupt mask bits
    shlr2   r0                     ! (shift right 4 total)
    and     #0x0F,r0               ! Keep only interrupt level (0-15)
    mov.l   r0,@r15               ! Save old interrupt level on stack
    stc     sr,r0                  ! Read SR again
    mov.w   @(0xE,PC),r3          ! r3 = 0xFF0F (mask to clear interrupt bits)
    and     r3,r0                  ! Clear interrupt level bits in SR
    or      #0xF0,r0               ! Set interrupt level to 15 (disable all)
    ldc     r0,sr                  ! Apply — interrupts now disabled

! --- Branch to main OREG reader based on peripheral state ---
    mov.l   @(0x30,PC),r0         ! r0 -> 0x060A4CAA (SMPC state byte)
    mov.b   @r0,r0                 ! Read current SMPC state
    bra     0x06039F26             ! Jump to state dispatcher
    extu.b  r0,r0                  ! (delay slot) zero-extend state byte

! --- Read OREG8/9 into struct+0/+1 (peripheral ID) ---
! This block runs when the dispatcher determines we should read controller data.
.read_oreg_id:                      ! 0x06039978
    mov.l   @(0xE0,PC),r2         ! r2 = 0x060A4C9C (peripheral struct base)
    mov.l   @(0xE4,PC),r3         ! r3 = 0x20100031 (OREG8)
    mov.b   @r3,r3                 ! Read OREG8 — peripheral type/ID upper
    mov.b   r3,@r2                 ! Store to struct+0x00

    mov.l   @(0xE0,PC),r3         ! r3 = 0x20100033 (OREG9)
    mov.b   @r3,r0                 ! Read OREG9 — peripheral type/ID lower
    mov.b   r0,@(0x1,r2)          ! Store to struct+0x01

! --- Read OREG10/11 into struct+2 (button word 1) ---
! Combines two bytes into a 16-bit button state: (OREG10 << 8) | OREG11
.read_buttons_1:                    ! 0x06039986
    mov.l   @(0xD4,PC),r3         ! r3 = 0x060A4C9C (struct base, reloaded)
    mov.l   @(0xDC,PC),r2         ! r2 = 0x20100035 (OREG10)
    mov.b   @r2,r2                 ! Read OREG10
    extu.b  r2,r2                  ! Zero-extend
    shll8   r2                     ! r2 = OREG10 << 8
    mov.l   @(0xD8,PC),r1         ! r1 = 0x20100037 (OREG11)
    mov.b   @r1,r1                 ! Read OREG11
    extu.b  r1,r1                  ! Zero-extend
    or      r1,r2                  ! r2 = (OREG10 << 8) | OREG11
    extu.w  r2,r0                  ! Truncate to 16-bit
    mov.w   r0,@(0x2,r3)          ! Store to struct+0x02 (button word 1)

! --- Read OREG12-15 into struct+4 (button long — 32 bits of extended data) ---
! Packs four bytes: (OREG12<<24) | (OREG13<<16) | (OREG14<<8) | OREG15
.read_buttons_2:                    ! 0x0603999C
    mov.l   @(0xD0,PC),r2         ! r2 = 0x20100039 (OREG12)
    mov.b   @r2,r2                 ! Read OREG12
    extu.b  r2,r2
    shll16  r2                     ! r2 = OREG12 << 16
    shll8   r2                     ! r2 = OREG12 << 24

    mov.l   @(0xCC,PC),r1         ! r1 = 0x2010003B (OREG13)
    mov.b   @r1,r1                 ! Read OREG13
    extu.b  r1,r1
    shll16  r1                     ! r1 = OREG13 << 16
    or      r1,r2                  ! r2 = (OREG12<<24) | (OREG13<<16)

    mov.l   @(0xC4,PC),r0         ! r0 = 0x2010003D (OREG14)
    mov.b   @r0,r0                 ! Read OREG14
    extu.b  r0,r0
    shll8   r0                     ! r0 = OREG14 << 8
    or      r0,r2                  ! r2 |= (OREG14 << 8)

    mov.l   @(0xC0,PC),r1         ! r1 = 0x2010003F (OREG15)
    mov.b   @r1,r1                 ! Read OREG15
    extu.b  r1,r1
    or      r1,r2                  ! r2 |= OREG15
    mov.l   r2,@(0x4,r3)          ! Store to struct+0x04 (button long)

! --- Read OREG0 into struct+8 (additional peripheral data) ---
.read_oreg0:                        ! 0x060399C4
    mov.l   @(0xB8,PC),r2         ! r2 = 0x20100021 (OREG0)
    mov.b   @r2,r0                 ! Read OREG0
    mov.b   r0,@(0x8,r3)          ! Store to struct+0x08

! --- Mark peripheral as connected ---
    mov.l   @(0xB8,PC),r2         ! r2 = 0x060A4CA8 (peripheral connected flag)
    mov.b   r13,@r2               ! Write 1 (r13 = 1) — peripheral present


! ============================================================================
! STAGE 3: FUN_06006F3C — Button Input Consumer
! ============================================================================
! CONFIDENCE: HIGH — Binary verified: r14=0x0605B6D8 (input state pointer), button bit
!   tests at 0x04/0x10/0x20/0x40/0x80 match binary exactly. All call targets confirmed.
!   Button-to-function mapping is structurally sound. Specific button labels (Right/Left/
!   Start/A/B) are reasonable but not hardware-confirmed (processed, not raw SMPC bits).
!
! AUDIT NOTE: The file header says "active-low button bits" for the processed state at
!   0x0605B6D8, but the tst+bt pattern means branch-if-zero (bit NOT set), so the handlers
!   fire when bits ARE set. This is active-HIGH, not active-low. The raw SMPC buttons
!   (OREG10/11) are active-low on Saturn hardware, but the processing stage likely inverts
!   them before storing to 0x0605B6D8.
! This function reads the PROCESSED input state (not the raw SMPC struct).
! By the time this runs, raw OREG data has been translated into a 32-bit
! button state word at 0x0605B6D8. Each bit = one button, active-low.
!
! Called from the sound/game state processing path.
! Tests individual button bits and dispatches to handlers for each.
!
! r8  = 0x06014884 (function pointer — input handler A)
! r9  = 0x06014868 (function pointer — input handler B)
! r10 = 0x060389A6 (function pointer — SMPC-related)
! r11 = 0x060635C4 (game state flag pointer)
! r13 = 0x060635C0 (frame counter pointer)
! r14 = 0x0605B6D8 (PROCESSED INPUT STATE — the key pointer)

FUN_06006F3C:                       ! Button input handler
    mov.l   r14,@-r15
    mov     #1,r2                  ! r2 = 1 (used for flag writes)
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x8C,PC),r8         ! r8 = 0x06014884
    mov.l   @(0x8C,PC),r9         ! r9 = 0x06014868
    mov.l   @(0x90,PC),r10        ! r10 = 0x060389A6
    mov.l   @(0x90,PC),r11        ! r11 = 0x060635C4
    mov.l   @(0x94,PC),r13        ! r13 = 0x060635C0
    mov.l   @(0x94,PC),r14        ! r14 = 0x0605B6D8 (input state pointer!)
    ! ... (frame counter increment, state checks, etc.)

! --- Button testing begins at 0x06007080 ---
! Each block: load input word from @r14, test one bit, branch if not pressed,
! then call a handler with specific parameters (sound channel, object pointers).

! First test: bit 29 (0x20000000) — special/modifier flag
.test_special:                      ! 0x0600707C
    mov.l   @r14,r1               ! r1 = current input state (32-bit)
    mov.l   @(0x8C,PC),r2         ! r2 = 0x20000000
    and     r2,r1                  ! Isolate bit 29
    tst     r1,r1                  ! Is it zero?
    bt      .test_right            ! If not pressed, skip to next button

    ! (calls FUN_0602766C with sound-related params when bit 29 set)

! Test: bit 2 (0x04) — likely D-pad Right
.test_right:                        ! 0x06007094
    mov.l   @r14,r0               ! Reload input state
    tst     #0x04,r0               ! Test bit 2
    bt      .test_left             ! Skip if not pressed

    ! (calls FUN_0602766C — sound trigger for menu navigation?)

! Test: bit 4 (0x10) — likely D-pad Left
.test_left:                         ! 0x060070A8
    mov.l   @r14,r0
    tst     #0x10,r0               ! Test bit 4
    bt      .test_start

    ! (loads pair of pointers from 0x0605B700/04, calls via r8)
    ! r4 = 4 (parameter — maybe sound channel or direction)

! Test: bit 5 (0x20) — likely Start button
.test_start:                        ! 0x060070BA
    mov.l   @r14,r0
    tst     #0x20,r0               ! Test bit 5
    bt      .test_a_button

    ! (loads pair from 0x0605B708/0C, calls via r8)
    ! r4 = 8

! Test: bit 6 (0x40) — A button (gas/accelerate)
.test_a_button:                     ! 0x060070CC
    mov.l   @r14,r0
    tst     #0x40,r0               ! Test bit 6 — A button
    bt      .test_b_button         ! Skip if A not pressed

    ! (loads pair from 0x0605B710/0C, calls via r8)
    ! r4 = 16 (0x10)

! Test: bit 7 (0x80) — B button (brake)
.test_b_button:                     ! 0x060070DE
    mov.l   @r14,r0
    tst     #0x80,r0               ! Test bit 7 — B button
    bt      .buttons_done          ! Skip if B not pressed

    ! (loads pointer from 0x0605B718, jumps to 0x0600713C)
    ! This is the longest handler — B button has special behavior
    ! (braking has more complex state than simple gas)
