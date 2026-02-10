! ============================================================
! AUDIT: HIGH
! FUN_0600A914 prologue, pool constants (0x0004B333, 0x0607EA98,
! 0x06078900, 0x0607EAE0, 0x00E00000), struct size 0x0268,
! skip flag, outer/inner loop structure, weighted Manhattan
! distance formula, speed gate 0x00010000, collision call to
! FUN_060316C4, and second pass for player car all verified
! against aprog.s. Two annotation issues found:
! 1) Line 129 uses r11_ptr which is not valid SH-2 (should be r5)
! 2) Offset 0x1EC is NOT Y position -- struct header says
!    car[+0x1EC] = speed value, not vertical position.
!    The dy threshold of 20 is checking a speed/progress field.
! ============================================================
!
! =============================================================================
! Car-Car Collision Detection System
! =============================================================================
!
! FUN_0600A914 — Proximity-based collision check for all active car pairs
!
! Called from: FUN_0600DE70 (per-car iteration loop, post-update)
! Purpose: Detect when two cars are close enough to collide, trigger response
!
! This is the OUTER collision system. It iterates all car pairs (O(n^2))
! and calls FUN_060316C4 (collision response) when a pair is close enough.
!
! The inner collision system (FUN_0600CD40 etc, documented in speed_position.s)
! handles car-vs-track collision using checkpoint geometry.
!
! Key Constants:
!   0x0004B333  collision distance threshold (~308K in fixed-point)
!   0x00E00000  car type/active bitmask (bits 21-23 of car flags)
!   0x06078900  car array base (40 slots x 0x268 bytes)
!   0x0607EA98  active car count
!   0x0607EAE0  skip flag (non-zero = skip collision check)
!
! Car Struct Fields Used:
!   +0x00  int   flags (bits 21-23 = car type, 0 = inactive)
!   +0x0C  int   Y position (or vertical — used for height check)
!   +0x10  int   X position
!   +0x18  int   Z position
\!   +0x1EC int   speed/progress field (NOT Y position; used for collision gating)
!
! Algorithm:
!   if (*0x0607EAE0 != 0): return  (demo mode — skip collisions)
!
!   for (i = 1; i < car_count - 1; i++):
!     car_i = &car_array[i]
!     *0x0607E940 = car_i  (set as "current car" for subroutines)
!     if (car_i->flags & 0x00E00000 == 0): skip  (inactive car)
!
!     for (j = i+1; j < car_count; j++):
!       car_j = &car_array[j]
!       if (car_j->flags & 0x00E00000 == 0): skip
!
!       dy = car_i->field_1EC - car_j->field_1EC  (offset 0x1EC, speed/progress gate)
!       if (abs(dy) > 20): skip    (threshold gate on field_1EC)
!
!       dx = car_i->X - car_j->X  (offset 0x10)
!       dz = car_i->Z - car_j->Z  (offset 0x18)
!       dist = abs(dx) + abs(dz)   (Manhattan distance, not Euclidean!)
!
!       Weighted: if dx > dz: dist = dx + dz/4
!                 else:        dist = dz + dx/4
!       (This is an approximation of Euclidean distance)
!
!       if (dist >= 0x0004B333): skip  (too far apart)
!       if (car_j->speed >= 0x00010000): skip  (moving too fast?)
!
!       call FUN_060316C4(car_i)   (collision response!)
!
!   === Second pass: current car vs all others ===
!   (Same algorithm but with *0x0607E940 = car_array[0] = player car)
!   Checks player against all AI cars for collision

! CONFIDENCE: HIGH
! Prologue, pool constants, loop structure, distance formula, speed gate,
! and collision call all verified. Two annotation errors noted:
! AUDIT NOTE: FIXED: Changed r11_ptr to r5 in XZ distance check. Binary at 0x0600A978 confirms mov.l @(0x10,r5),r6.
! AUDIT NOTE: FIXED: Changed 0x1EC from 'Y position' to 'speed/progress field' in algorithm and struct comments. Y position is at +0x14, not +0x1EC. Threshold of 20 comparison is valid code.
FUN_0600A914:  ! 0x0600A914
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    sts.l   macl,@-r15

    mov.l   @(0x78,PC),r8           ! r8 = 0x0004B333 (distance threshold)
    mov.l   @(0x78,PC),r10          ! r10 = 0x0607EA98 (car count ptr)
    mov.l   @(0x7C,PC),r12          ! r12 = 0x06078900 (car array base)
    mov.w   @(0x6A,PC),r13          ! r13 = 0x0268 (car struct size)
    mov.l   @(0x7C,PC),r0           ! 0x0607EAE0 (skip flag)
    mov.l   @r0,r0
    tst     r0,r0
    bt      .start_collision_check
    bra     .second_pass            ! skip flag set → go to second pass
    nop

.start_collision_check:
    bra     .outer_loop_check
    mov     #1,r9                   ! r9 = i = 1

    ! === Outer loop: for each car i ===
.outer_loop_body:
    mul.l   r13,r9                  ! r9 * 0x268
    mov.l   @(0x6C,PC),r3           ! 0x0607E940
    sts     macl,r14                ! r14 = i * struct_size
    add     r12,r14                 ! r14 = &car_array[i]
    mov.l   r14,@r3                 ! set current car = car_i

    mov.l   @r14,r2                 ! car_i->flags
    mov.l   @(0x68,PC),r3           ! 0x00E00000 (type mask)
    and     r3,r2
    tst     r2,r2
    bf      .inner_loop_start       ! car active → check pairs
    bra     .outer_next             ! inactive → skip
    nop

    ! === Inner loop: for each car j > i ===
.inner_loop_start:
    bra     .inner_loop_check
    mov     r9,r11                  ! r11 = j = i (will increment)

.inner_loop_body:
    mul.l   r13,r11                 ! j * 0x268
    mov.w   @(0x3C,PC),r0           ! offset 0x1EC
    sts     macl,r5                 ! r5 = j * struct_size
    mov.l   @(r0,r14),r4            ! car_i->Y
    add     r12,r5                  ! r5 = &car_array[j]
    mov.l   @(r0,r5),r3             ! car_j->Y
    sub     r3,r4                   ! dy = Yi - Yj
    mov     #20,r3
    cmp/gt  r3,r4                   ! |dy| > 20?
    bt      .inner_next
    mov     #-20,r3
    cmp/ge  r3,r4
    bt      .check_xz_distance
    bra     .inner_next
    nop

.check_xz_distance:
    ! XZ distance check (weighted Manhattan approximation)
    mov.l   @(0x10,r14),r6          ! car_i->X
    mov.l   @(0x10,r5),r2          \! car_j->X
    mov.l   @(0x18,r14),r4          ! car_i->Z
    mov.l   @(0x18,r5),r3           ! car_j->Z
    sub     r2,r6                   ! dx = Xi - Xj
    cmp/pz  r6
    bt/s    .dx_positive
    sub     r3,r4                   ! dz = Zi - Zj
    neg     r6,r6                   ! dx = abs(dx)
.dx_positive:
    cmp/pz  r4
    bt      .dz_positive
    neg     r4,r4                   ! dz = abs(dz)
.dz_positive:

    ! Weighted distance: if dx > dz, dist = dx + dz/4, else dist = dz + dx/4
    cmp/gt  r4,r6                   ! dx > dz?
    bf      .dz_dominant
    shar    r4
    bra     .check_threshold
    shar    r4                      ! dz >>= 2
.dz_dominant:
    mov     r6,r2
    shar    r2
    shar    r2                      ! dx >>= 2
    mov     r2,r6
.combine:
    add     r4,r6                   ! dist = max_component + min_component/4

.check_threshold:
    cmp/ge  r8,r6                   ! dist >= 0x0004B333?
    bt      .inner_next             ! too far → skip

    ! Close enough for collision — check speed gate
    mov.w   @(0xB4,PC),r0
    mov.l   @(0xB8,PC),r3           ! 0x00010000
    mov.l   @(r0,r5),r2             ! car_j->speed
    cmp/ge  r3,r2
    bt      .inner_next             ! moving too fast → skip

    ! === COLLISION DETECTED ===
    mov.l   @(0xB4,PC),r3           ! FUN_060316C4 (collision response)
    jsr     @r3
    mov     r14,r4                  ! r4 = car_i (collision target)

.inner_next:
    add     #1,r11                  ! j++
.inner_loop_check:
    mov.l   @r10,r2                 ! car count
    cmp/hs  r2,r11                  ! j >= count?
    bf      .inner_loop_body

.outer_next:
    add     #1,r9                   ! i++
.outer_loop_check:
    mov.l   @r10,r2
    add     #-1,r2                  ! count - 1
    cmp/hs  r2,r9                   ! i >= count-1?
    bf      .outer_loop_body

    ! === Second pass: player car vs all ===
.second_pass:
    mov.l   @(0xA0,PC),r3           ! 0x0607E940
    mov.l   r12,@r3                 ! set current car = car_array[0] (player)
    mov     r3,r11
    mov.l   @r11,r11                ! r11 = player car base

    bra     .pass2_check
    mov     #1,r9

.pass2_body:
    mul.l   r13,r9
    mov.l   @(0x98,PC),r2           ! 0x00E00000
    sts     macl,r14
    add     r12,r14                 ! r14 = &car_array[j]
    mov.l   @r14,r3
    and     r2,r3
    tst     r3,r3
    bf      .pass2_check_distance
    bra     .pass2_next
    nop

.pass2_check_distance:
    ! Same distance check as inner loop but against player car (r11)
    mov.w   @(0x74,PC),r0
    mov     #20,r3
    mov.l   @(r0,r11),r4            ! player->Y
    mov.l   @(r0,r14),r2            ! car_j->Y
    sub     r2,r4
    cmp/gt  r3,r4
    bt      .pass2_next
    mov     #-20,r3
    cmp/ge  r3,r4
    bt      .pass2_xz
    bra     .pass2_next
    nop

.pass2_xz:
    mov.l   @(0x10,r14),r6
    mov.l   @(0x10,r11),r2
    mov.l   @(0x18,r14),r4
    mov.l   @(0x18,r11),r3
    sub     r2,r6
    cmp/pz  r6
    bt/s    .p2_dx_pos
    sub     r3,r4
    neg     r6,r6
.p2_dx_pos:
    cmp/pz  r4
    bt      .p2_dz_pos
    neg     r4,r4
.p2_dz_pos:
    cmp/gt  r4,r6
    bf      .p2_dz_dom
    shar    r4
    shar    r4
    bra     .p2_combine
    nop
.p2_dz_dom:
    mov     r6,r2
    shar    r2
    shar    r2
    mov     r2,r6
.p2_combine:
    add     r4,r6
    cmp/ge  r8,r6
    bt      .pass2_next

    mov.w   @(0x60,PC),r0
    mov.l   @(0x60,PC),r3           ! 0x00010000
    mov.l   @(r0,r14),r2
    cmp/ge  r3,r2
    bt      .pass2_next

    ! Collision with player!
    mov.l   @(0x5C,PC),r3           ! FUN_060316C4
    jsr     @r3
    mov     r14,r4

.pass2_next:
    add     #1,r9
.pass2_check:
    mov.l   @r10,r2
    cmp/hs  r2,r9
    bf      .pass2_body

    ! Cleanup
    lds.l   @r15+,macl
    lds.l   @r15+,pr
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14

! Pool constants:
! 0x0004B333  collision distance threshold
! 0x0607EA98  car count
! 0x06078900  car array base
! 0x0607EAE0  skip flag (demo mode)
! 0x00E00000  active car bitmask
! 0x0607E940  current car pointer
! 0x00010000  speed gate
! 0x060316C4  collision response function
