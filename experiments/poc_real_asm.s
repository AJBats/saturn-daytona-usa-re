/* Sawyer L2: FUN_0600E71A — Player Physics Orchestrator
 * REAL assembly source — mnemonics, labels, symbolic references.
 * This is what Sega's source would have looked like. */

    .section .text
    /* 2-byte pad so function starts at offset 2 mod 4.
       This matches original layout (0x0600E71A = 2 mod 4)
       and puts the constant pool on a 4-byte boundary. */
    .short 0x0000
    .global _FUN_0600E71A

_FUN_0600E71A:
    mov.l   r14,@-r15               /* save r14 */
    sts.l   pr,@-r15                /* save return address */
    sts.l   macl,@-r15              /* save multiply accumulator */
    mov.l   .Lpool_car_ptr,r14      /* r14 = &car_object_pointer */
    mov.l   .Lpool_input,r3         /* r3 = &FUN_06008318 */
    jsr     @r3                     /* Step 1: controller input */
    mov.l   @r14,r14                /* (delay) r14 = *car_object_pointer */

    mov.l   .Lpool_gear,r3          /* r3 = &FUN_06008640 */
    jsr     @r3                     /* Step 2: gear/force table */
    nop

    mov.l   .Lpool_friction,r3      /* r3 = &FUN_0600D266 */
    jsr     @r3                     /* Step 3: friction (stub) */
    nop

    mov.l   .Lpool_speed,r3         /* r3 = &FUN_0600C4F8 */
    jsr     @r3                     /* Step 4: speed computation */
    nop

    mov.l   .Lpool_collision,r3     /* r3 = &FUN_0600C5D6 */
    jsr     @r3                     /* Step 5: collision & position */
    nop

    /* Step 6: timer countdown and track segment check */
    mov.w   .Lword_0208,r0          /* r0 = 0x0208 (timer offset) */
    mov.l   @(r0,r14),r2            /* r2 = car[0x208] */
    cmp/pl  r2                      /* timer > 0? */
    bf      .L_after_timer          /* no → skip */

    mov.w   .Lword_01E4,r0          /* r0 = 0x01E4 (sub-timer offset) */
    mov.l   @(r0,r14),r2            /* r2 = car[0x1E4] */
    add     #-1,r2                  /* decrement */
    mov.l   r2,@(r0,r14)            /* store back */
    tst     r2,r2                   /* reached zero? */
    bf      .L_after_timer          /* no → skip */

    /* Timer hit zero: read next track segment */
    mov.w   .Lword_01F8,r0          /* r0 = 0x01F8 (segment index offset) */
    mov.l   @(r0,r14),r4            /* r4 = segment_index */
    mov     r4,r3                   /* copy for stride calc */
    shll2   r4                      /* r4 = index * 4 */
    shll    r4                      /* r4 = index * 8 */
    shll2   r3                      /* r3 = index * 4 */
    shll2   r3                      /* r3 = index * 16 */
    add     r3,r4                   /* r4 = index * 24 (stride) */
    add     #-4,r0                  /* r0 = 0x01F4 (base table ptr offset) */
    mov.l   @(r0,r14),r3            /* r3 = track_segment_table_base */
    add     r3,r4                   /* r4 = &segment_table[index] */
    mov.w   @(0x14,r4),r0           /* r0 = segment[index].word_at_0x14 */
    mov     r0,r3
    mov.w   .Lword_0228,r0          /* r0 = 0x0228 */
    mov.l   r3,@(r0,r14)            /* store segment value */
    mov.w   .Lword_FFFF,r3          /* r3 = 0xFFFF (-1) */
    add     #12,r0                  /* r0 = 0x0234 */
    mov.l   r3,@(r0,r14)            /* store -1 marker */

.L_after_timer:
    /* Step 7: track segment advancement */
    mov.l   .Lpool_track,r3         /* r3 = &FUN_0600CEBA */
    jsr     @r3
    nop

    /* Step 8: ranking computation */
    mov.w   .Lword_0228,r0          /* r0 = offset for ranking field */
    mov.l   .Lpool_car_count,r3     /* r3 = &car_count */
    mov.l   @(r0,r14),r2            /* r2 = ranking value */
    mov.l   @r3,r3                  /* r3 = *car_count */
    add     #-60,r0                 /* adjust offset */
    mul.l   r3,r2                   /* ranking × car_count */
    mov.l   @(r0,r14),r3            /* r3 = base score */
    sts     macl,r2                 /* r2 = multiply result */
    add     #8,r0                   /* adjust offset */
    add     r3,r2                   /* r2 = base + (ranking × count) */
    mov.l   r2,@(r0,r14)            /* store final score */

    /* Epilogue */
    lds.l   @r15+,macl
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14               /* (delay) restore r14 */

/* --- inline word constants (mov.w targets) --- */
.Lword_0208:    .short 0x0208
.Lword_01E4:    .short 0x01E4
.Lword_01F8:    .short 0x01F8
.Lword_0400:    .short 0x0400
.Lword_0228:    .short 0x0228
.Lword_FFFF:    .short 0xFFFF

/* --- constant pool (symbolic references) --- */
.Lpool_car_ptr:     .4byte _DAT_0607E940   /* car object pointer */
.Lpool_input:       .4byte _FUN_06008318   /* controller input handler */
.Lpool_gear:        .4byte _FUN_06008640   /* gear/force table selection */
.Lpool_friction:    .4byte _FUN_0600D266   /* friction stub */
.Lpool_speed:       .4byte _FUN_0600C4F8   /* speed computation */
.Lpool_collision:   .4byte _FUN_0600C5D6   /* collision detection */
.Lpool_track:       .4byte _FUN_0600CEBA   /* track segment advancement */
.Lpool_car_count:   .4byte _DAT_0607EA9C   /* car count */
