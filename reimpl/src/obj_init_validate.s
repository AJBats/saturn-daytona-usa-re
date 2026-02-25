/* obj_init_validate -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06040010 - 0x060401F8
 *
 * Gameplay event validation dispatcher and object initialization.
 * Part of the event queue / state management subsystem (0x0604xxxx).
 *
 * Contains three entry points:
 *
 *   validation_dispatch (FUN_06040010):
 *     Validates a game object against the track road segment system.
 *     Clears status bits in the game state structure (offset +0xC4),
 *     calls road_segment_check, then sets result flags at +0xC4/+0xC8.
 *     Maps the road_segment_check return code (-0xF, -0xE, -0xD, 0x0)
 *     to specific error values (-3, -2, -0x17, 0).
 *
 *   obj_init_validate (FUN_060400D6):
 *     Initializes a game object structure (output in r4) from either:
 *       - Track shadow/ground query (when source ptr r5 is NULL), or
 *       - Direct copy from an existing source struct (when r5 is non-NULL).
 *     Computes segment stride via a bit-field helper, calculates position
 *     offsets using unsigned division (input_proc_complete) and fixed-point
 *     modulo (sym_06036BE4), copies surface-type bytes to offsets +0x1C
 *     through +0x1F, and zeroes out trailing state fields.
 *
 *   sym_060401E4:
 *     Trivial setter -- stores a long at offset +24 of a structure pointer.
 *
 * Global state: sym_060A4D14 is a pointer to the game state structure
 * (dereferenced, not the struct itself).
 */

    .section .text.FUN_06040010


    .global validation_dispatch
    .type validation_dispatch, @function
validation_dispatch:
    sts.l pr, @-r15                     ! save return address
    add #-0x4, r15                      ! allocate 4 bytes on stack (local var)
    mov.l   .L_ptr_game_state, r14      ! r14 = &game_state_ptr
    mov.l r4, @r15                      ! save r4 (param) to stack local
    mov.l @r14, r3                      ! r3 = *game_state_ptr (state struct base)
    mov.w   DAT_0604009e, r0            ! r0 = 0xC4 (status flags offset)
    mov.l @(r0, r3), r1                 ! r1 = state[+0xC4] (current status flags)
    and r2, r1                          ! clear bits specified by r2 (mask param)
    mov.l r1, @(r0, r3)                 ! write back masked status flags
    mov.l @r14, r4                      ! r4 = state base
    mov.w   .L_off_road_check_base, r3  ! r3 = 0xD0 (road check data offset)
    add r3, r4                          ! r4 = &state[+0xD0] -- road check base ptr
    mov.l   .L_fn_road_seg_check, r3    ! r3 = road_segment_check
    jsr @r3                             ! call road_segment_check(r4=base+0xD0, r5=param)
    mov.l @r15, r5                      ! (delay) r5 = saved param from stack
    mov r0, r4                          ! r4 = road_segment_check result
    tst r4, r4                          ! test if result == 0
    bf      .L_check_param              ! if non-zero, skip flag-setting
    mov.l @r14, r3                      ! r3 = state base (check returned 0 = fail)
    mov.w   DAT_0604009e, r0            ! r0 = 0xC4
    mov.l @(r0, r3), r0                 ! r0 = state[+0xC4]
    or #0x1, r0                         ! set bit 0 -- mark road segment invalid
    mov.w   DAT_0604009e, r1            ! r1 = 0xC4
    add r3, r1                          ! r1 = &state[+0xC4]
    mov.l r0, @r1                       ! write back with bit 0 set
.L_check_param:
    mov.l @r15, r0                      ! r0 = saved param
    tst r0, r0                          ! test if param == 0 (NULL)
    bt/s    .L_param_null               ! if NULL, branch to set r2 = -1
    mov.l @r14, r3                      ! (delay) r3 = state base
    bra     .L_store_result             ! param non-NULL -- store 0x17
    mov #0x17, r2                       ! (delay) r2 = 0x17 (active segment index)
.L_param_null:
    mov #-0x1, r2                       ! r2 = -1 (no active segment)
.L_store_result:
    mov.w   .L_off_result_field, r0     ! r0 = 0xC8 (result field offset)
    mov.l r2, @(r0, r3)                 ! state[+0xC8] = r2 (0x17 or -1)
    bra     .L_dispatch_retcode         ! jump to return code dispatcher
    mov r4, r0                          ! (delay) r0 = road_segment_check result
.L_ret_success:
    mov #0x0, r0                        ! return 0 (success)
    add #0x4, r15                       ! free stack local
    lds.l @r15+, pr                     ! restore return address
    rts
    mov.l @r15+, r14                    ! (delay) restore r14
.L_ret_err_0x17:
    mov #-0x17, r0                      ! return -0x17 (segment type error)
    add #0x4, r15                       ! free stack local
    lds.l @r15+, pr                     ! restore return address
    rts
    mov.l @r15+, r14                    ! (delay) restore r14
.L_ret_err_2:
    mov #-0x2, r0                       ! return -2 (boundary error)
    add #0x4, r15                       ! free stack local
    lds.l @r15+, pr                     ! restore return address
    rts
    mov.l @r15+, r14                    ! (delay) restore r14
.L_ret_err_3:
    mov #-0x3, r0                       ! return -3 (shadow test error)
    add #0x4, r15                       ! free stack local
    lds.l @r15+, pr                     ! restore return address
    rts
    mov.l @r15+, r14                    ! (delay) restore r14
.L_ret_err_1:
    mov #-0x1, r0                       ! return -1 (unrecognized error)
    add #0x4, r15                       ! free stack local
    lds.l @r15+, pr                     ! restore return address
    rts
    mov.l @r15+, r14                    ! (delay) restore r14
.L_dispatch_retcode:
    cmp/eq #-0xF, r0                    ! road_segment_check returned -0xF?
    bt      .L_ret_err_3                ! yes -> return -3
    cmp/eq #-0xE, r0                    ! returned -0xE?
    bt      .L_ret_err_2                ! yes -> return -2
    cmp/eq #-0xD, r0                    ! returned -0xD?
    bt      .L_ret_err_0x17             ! yes -> return -0x17
    cmp/eq #0x0, r0                     ! returned 0?
    bt      .L_ret_success              ! yes -> return 0 (success)
    bra     .L_ret_err_1                ! anything else -> return -1
    nop

    .global DAT_0604009e
DAT_0604009e:
    .2byte  0x00C4                      /* state struct offset: status flags */
.L_off_road_check_base:
    .2byte  0x00D0                      /* state struct offset: road check base */
.L_off_result_field:
    .2byte  0x00C8                      /* state struct offset: result field */
.L_ptr_game_state:
    .4byte  sym_060A4D14                /* -> game state structure pointer */
.L_fn_road_seg_check:
    .4byte  road_segment_check          /* track road segment validator */
    .4byte  0x7F044F26
    .4byte  0x000B6EF6

! ---------------------------------------------------------------------------
! Stride helper: selects segment stride from surface type flags.
!   Input:  r4 = surface type byte (unsigned)
!   Output: r0 = stride value (0x0914 for bit 2 set, else 0x0800)
! ---------------------------------------------------------------------------
.L_stride_from_flags:
    mov #0x4, r3                        ! mask for bit 2
    and r4, r3                          ! test bit 2 of surface flags
    tst r3, r3                          ! bit 2 clear?
    bt      .L_check_bit3              ! yes -> check bit 3 instead
    mov.w   .L_stride_wide, r4          ! bit 2 set: stride = 0x0914 (wide)
    bra     .L_stride_return
    nop
.L_check_bit3:
    mov #0x8, r2                        ! mask for bit 3
    mov.w   .L_stride_default, r5       ! preload default stride = 0x0800
    and r2, r4                          ! test bit 3 of surface flags
    tst r4, r4                          ! bit 3 clear?
    bt      .L_use_default_stride       ! yes -> use default stride
    bra     .L_stride_return            ! bit 3 set: still use same value
    mov r5, r4                          ! (delay) r4 = default stride
.L_use_default_stride:
    mov r5, r4                          ! r4 = default stride (0x0800)
.L_stride_return:
    rts
    mov r4, r0                          ! (delay) return stride in r0

! ---------------------------------------------------------------------------
! obj_init_validate -- initialize game object struct from track or source data
!   r4 = output struct pointer (dest)
!   r5 = source data pointer (NULL = query from track shadow)
!   r6 = object type/flags
! ---------------------------------------------------------------------------
    .global obj_init_validate
    .type obj_init_validate, @function
obj_init_validate:
    mov.l r14, @-r15                    ! save r14
    mov.l r13, @-r15                    ! save r13
    mov r5, r13                         ! r13 = source data ptr
    mov.l r12, @-r15                    ! save r12
    mov.l r11, @-r15                    ! save r11
    sts.l pr, @-r15                     ! save return address
    mov r6, r11                         ! r11 = object type/flags
    add #-0xC, r15                      ! allocate 12 bytes on stack (local buf)
    mov.w   .L_stride_default, r12      ! r12 = 0x0800 (default stride constant)
    tst r13, r13                        ! source ptr == NULL?
    bf/s    .L_copy_from_source         ! non-NULL -> copy from source struct
    mov r4, r14                         ! (delay) r14 = output struct ptr
    ! --- NULL source: query track shadow for ground data ---
    mov r15, r5                         ! r5 = stack buf (output for shadow query)
    mov.l   .L_fp_0x4000_0000, r3       ! r3 = 0x40000000 (base type flag)
    or r11, r3                          ! combine with object type flags
    mov.l r3, @r14                      ! dest[+0] = type | 0x40000000
    mov.l   .L_fn_track_shadow_test, r3 ! r3 = track_shadow_test
    jsr @r3                             ! call track_shadow_test(r4=type, r5=buf)
    mov r11, r4                         ! (delay) r4 = object type/flags
    tst r0, r0                          ! shadow test returned 0?
    bt      .L_shadow_ok                ! yes -> shadow data valid, continue
    bra     .L_epilogue                 ! non-zero -> fail, return NULL (r0=0)
    mov #0x0, r0                        ! (delay) r0 = 0 (failure return)
.L_stride_wide:
    .2byte  0x0914                      /* wide stride (bit 2 surface type) */
.L_stride_default:
    .2byte  0x0800                      /* default stride */
.L_fp_0x4000_0000:
    .4byte  0x40000000                  /* 0.25 (2.30) or 16384.0 (16.16) */
.L_fn_track_shadow_test:
    .4byte  track_shadow_test           /* ground shadow/surface query */
.L_shadow_ok:
    ! --- shadow query succeeded: populate from stack buffer ---
    mov r15, r3                         ! r3 = stack buf base
    mov r15, r4                         ! r4 = stack buf base
    mov.l @r3, r2                       ! r2 = buf[+0] (ground position)
    mov.l r2, @(4, r14)                 ! dest[+4] = ground position
    mov.b @(11, r4), r0                 ! r0 = buf[+11] (surface type byte)
    mov r0, r4                          ! r4 = surface type
    bsr     .L_stride_from_flags        ! compute stride from surface flags
    extu.b r4, r4                       ! (delay) zero-extend byte to word
    mov.l r0, @(12, r14)               ! dest[+12] = stride
    mov r15, r1                         ! r1 = stack buf
    mov r0, r3                          ! r3 = stride
    mov.l   .L_fn_udiv, r2             ! r2 = input_proc_complete (unsigned div)
    mov.l @(4, r1), r1                  ! r1 = buf[+4] (position value)
    add r3, r1                          ! r1 = position + stride
    jsr @r2                             ! call udiv(r0=divisor, r1=dividend)
    add #-0x1, r1                       ! (delay) r1 = position + stride - 1
    mov.l r0, @(16, r14)               ! dest[+16] = quotient (segment index)
    mov r15, r4                         ! r4 = stack buf
    mov.l   .L_fn_fixed_mod, r3        ! r3 = fixed-point modulo fn
    mov.l @(4, r4), r4                  ! r4 = buf[+4] (position value)
    mov r4, r1                          ! r1 = position (dividend)
    jsr @r3                             ! call fixed_mod(r0=stride, r1=position)
    mov r12, r0                         ! (delay) r0 = 0x0800 (default stride)
    mov r12, r1                         ! r1 = 0x0800
    mov.l   .L_fn_fixed_mod, r3        ! r3 = fixed-point modulo fn
    sub r0, r1                          ! r1 = stride - remainder
    jsr @r3                             ! call fixed_mod(r0=stride, r1=stride-rem)
    mov r12, r0                         ! (delay) r0 = 0x0800
    mov.l r0, @(20, r14)               ! dest[+20] = fractional offset in segment
    ! --- copy surface type bytes from stack buf to dest ---
    mov r15, r2                         ! r2 = stack buf
    mov.b @(10, r2), r0                 ! r0 = buf[+10] (surface type A)
    mov r0, r3
    mov #0x1C, r0
    mov.b r3, @(r0, r14)               ! dest[+0x1C] = surface type A
    mov r15, r3
    mov.b @(11, r3), r0                 ! r0 = buf[+11] (surface type B)
    mov r0, r2
    mov #0x1D, r0
    mov.b r2, @(r0, r14)               ! dest[+0x1D] = surface type B
    mov r15, r3
    mov.b @(8, r3), r0                  ! r0 = buf[+8] (surface type C)
    mov r0, r2
    mov #0x1E, r0
    mov.b r2, @(r0, r14)               ! dest[+0x1E] = surface type C
    mov r15, r3
    mov.b @(9, r3), r0                  ! r0 = buf[+9] (surface type D)
    mov r0, r2
    mov #0x1F, r0
    bra     .L_zero_trailing_fields     ! continue to zero-fill
    mov.b r2, @(r0, r14)               ! (delay) dest[+0x1F] = surface type D
.L_copy_from_source:
    ! --- non-NULL source: copy fields directly ---
    mov.l r11, @r14                     ! dest[+0] = object type/flags
    mov.l @r13, r2                      ! r2 = src[+0] (ground position)
    mov.l r2, @(4, r14)                 ! dest[+4] = ground position
    mov.b @(11, r13), r0                ! r0 = src[+11] (surface type byte)
    mov r0, r4
    bsr     .L_stride_from_flags        ! compute stride from surface flags
    extu.b r4, r4                       ! (delay) zero-extend byte to word
    mov.l r0, @(12, r14)               ! dest[+12] = stride
    mov.l @(4, r13), r4                 ! r4 = src[+4] (position value)
    mov.w   DAT_060401e8, r2            ! r2 = 0x07FF (rounding mask)
    mov r4, r1                          ! r1 = position
    add r4, r2                          ! r2 = position + 0x07FF (round up)
    shlr8 r2                            ! r2 >>= 8
    shlr2 r2                            ! r2 >>= 2
    shlr r2                             ! r2 >>= 1 -- total >>= 11 (divide by 2048)
    mov.l r2, @(16, r14)               ! dest[+16] = segment index
    mov.l   .L_fn_fixed_mod, r3        ! r3 = fixed-point modulo fn
    jsr @r3                             ! call fixed_mod(r0=0x0800, r1=position)
    mov r12, r0                         ! (delay) r0 = 0x0800
    mov r12, r1                         ! r1 = 0x0800
    mov.l   .L_fn_fixed_mod, r3        ! r3 = fixed-point modulo fn
    sub r0, r1                          ! r1 = stride - remainder
    jsr @r3                             ! call fixed_mod(r0=0x0800, r1=stride-rem)
    mov r12, r0                         ! (delay) r0 = 0x0800
    mov.l r0, @(20, r14)               ! dest[+20] = fractional offset in segment
    ! --- copy surface type bytes from source struct ---
    mov.b @(10, r13), r0                ! r0 = src[+10] (surface type A)
    mov r0, r2
    mov #0x1C, r0
    mov.b r2, @(r0, r14)               ! dest[+0x1C] = surface type A
    mov.b @(11, r13), r0                ! r0 = src[+11] (surface type B)
    mov r0, r3
    mov #0x1D, r0
    mov.b r3, @(r0, r14)               ! dest[+0x1D] = surface type B
    mov.b @(8, r13), r0                 ! r0 = src[+8] (surface type C)
    mov r0, r3
    mov #0x1E, r0
    mov.b r3, @(r0, r14)               ! dest[+0x1E] = surface type C
    mov.b @(9, r13), r0                 ! r0 = src[+9] (surface type D)
    mov r0, r3
    mov #0x1F, r0
    mov.b r3, @(r0, r14)               ! dest[+0x1F] = surface type D
.L_zero_trailing_fields:
    ! --- zero-initialize remaining object fields ---
    mov #0x0, r4                        ! r4 = 0
    mov.l r4, @(24, r14)               ! dest[+24] = 0 (velocity/state)
    mov.l r4, @(36, r14)               ! dest[+36] = 0 (timer/counter)
    mov r4, r3
    mov.l r4, @(32, r14)               ! dest[+32] = 0 (flags)
    mov.l   .L_fp_max, r2              ! r2 = 0x7FFFFFFF (max 16.16 fixed-point)
    mov.l r2, @(40, r14)               ! dest[+40] = max distance (sentinel)
    mov r14, r0                         ! r0 = dest ptr (return value)
.L_epilogue:
    add #0xC, r15                       ! free stack locals
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts
    mov.l @r15+, r14                    ! (delay) restore r14

! ---------------------------------------------------------------------------
! sym_060401E4 -- trivial setter: dest[+24] = value
!   r4 = struct pointer, r5 = value to store
! ---------------------------------------------------------------------------
    .global sym_060401E4
sym_060401E4:
    rts
    mov.l r5, @(24, r4)                ! (delay) struct[+24] = r5

    .global DAT_060401e8
DAT_060401e8:
    .2byte  0x07FF                      /* rounding mask for segment division */
    .2byte  0xFFFF                      /* padding / alignment */
.L_fn_udiv:
    .4byte  input_proc_complete         /* unsigned 32-bit division */
.L_fn_fixed_mod:
    .4byte  sym_06036BE4                /* signed fixed-point modulo */
.L_fp_max:
    .4byte  0x7FFFFFFF                  /* max positive 16.16 */
