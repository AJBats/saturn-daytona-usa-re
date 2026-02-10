! ================================================
! AUDIT: HIGH — 3D matrix/vector pipeline verified against binary. All 24
!   function addresses confirmed in aprog.s. Instruction patterns match for
!   push/pop, identity, xform, scale, rotation, fullmul, and vec transforms.
!   Two stacks (A at 0x06089EDC, B at 0x0608A52C) confirmed via pool constants.
!   Rotation function names are SWAPPED (see AUDIT NOTEs on rotXZ/rotXY/rotYZ).
!   Scale function description has minor inaccuracy (see AUDIT NOTE).
!   Sin/cos table described as 256 entries — should be 4096 (mask 0x3FFC).
! Audited: 2026-02-10
! ================================================
!
! =============================================================================
! 3D Math / Transform Foundation Layer
! =============================================================================
!
! Address range: 0x06026DBC - 0x060274F0
! ~50 functions implementing the complete 3D transform pipeline
!
! This is THE mathematical foundation of the entire game. Every rendering
! function, every physics calculation, every camera operation flows through
! these matrix/vector operations.
!
! Architecture: TWO independent matrix stacks (A and B)
!   Stack A: 0x06089EDC (pointer), buffers 0x0608A4E0/A4F0/A520
!   Stack B: 0x0608A52C (pointer), buffers 0x0608A6B0/A6C0/A6F0
!
! Matrix format: 48 bytes per entry
!   [0x00] 3x3 rotation matrix (9 x int32 = 36 bytes, row-major)
!   [0x24] translation vector (3 x int32 = 12 bytes)
!
! All values are 16.16 FIXED POINT:
!   0x00010000 = 1.0
!   0x00008000 = 0.5
!   Multiply: dmuls.l a,b → mach:macl → xtrct mach,macl = (a*b) >> 16
!
! The xtrct instruction (opcode 0x__0D) takes bits 15:0 of mach and
! bits 31:16 of macl, concatenating them into a 32-bit result.
! This implements: result = (int64)(a * b) >> 16  (fixed-point multiply)
!
! Rotation uses sin/cos lookup table at 0x002F2F20 (in cartridge ROM space)
!
! =============================================================================
! FUNCTION CATALOG
! =============================================================================
!
! --- Stack A (matrix ptr at 0x06089EDC) ---
!
! 0x06026DBC  mat_push_A        Push matrix (copy current, advance +48)
! 0x06026DF8  mat_pop_A         Pop matrix (retreat -48)
! 0x06026E02  mat_identity_A2   Set matrix at 0x06089EE0 to identity, set ptr
! 0x06026E0C  mat_identity_A    Set current top matrix to identity
! 0x06026E2E  mat_xform_trans_A Transform vector (r4,r5,r6) by matrix+translation
!                                 Result → 0x0608A4E0 buffer, then to matrix+36
! 0x06026E60  mat_scale_A       Scale matrix columns by (r4,r5,r6) using dmuls
! FUN_06026E94 mat_rotXZ_A      Rotate in XZ plane (columns 1,2 of matrix)
! FUN_06026EDE mat_rotXY_A      Rotate in XY plane (columns 0,2 of matrix)
! FUN_06026F2A mat_rotYZ_A      Rotate in YZ plane (columns 0,1 of matrix)
! 0x06026F72  mat_fullmul_A     Full 3x3 multiply: M = M * input (3x3 transpose)
!                                 Uses 0x0608A4F0 temp buffer
!                                 After multiply, copies translation back
! FUN_06026FFC mat_vec_trans_A   Matrix * vector + translation → 0x0608A520 → r5
!                                 r4 = input vec, r5 = output vec
! 0x06027038  mat_vec_notrans_A Matrix * vector (no translation) → 0x0608A520 → r5
!
! --- Stack B (matrix ptr at 0x0608A52C) ---
!
! 0x06027080  mat_push_B        Push matrix (+48)
! 0x060270BC  mat_pop_B         Pop matrix (-48)
! 0x060270C6  mat_identity_B2   Set matrix at 0x0608A530 to identity, set ptr
! 0x060270D0  mat_identity_B    Set current top matrix to identity
! 0x060270F2  mat_xform_trans_B Transform vector by matrix+translation
! 0x06027124  mat_scale_B       Scale matrix columns by (r4,r5,r6)
! FUN_06027158 mat_rotXZ_B      Rotate in XZ plane
! FUN_060271A2 mat_rotXY_B      Rotate in XY plane
! FUN_060271EE mat_rotYZ_B      Rotate in YZ plane
! 0x06027236  mat_fullmul_B     Full 3x3 multiply + translation copy
! FUN_060272C0 mat_vec_trans_B   Matrix * vector + translation → 0x0608A6F0 → r5
! 0x060272FC  mat_vec_notrans_B Matrix * vector (no translation)
!
! --- Trig / Lookup ---
!
! 0x06027344  trig_lookup_single Single value lookup from sin/cos table
! FUN_06027358 sincos_lookup     Sin/Cos pair lookup: r4=angle → @r5=sin, @r6=cos
! 0x06027378  trig_interp       Piecewise polynomial trig (atan2? advanced trig)
!
! =============================================================================
! POOL CONSTANTS
! =============================================================================
!
!   0x06089EDC  → matrix stack A pointer (current top of stack A)
!   0x06089EE0  → matrix stack A alternate base
!   0x0608A4E0  → vector buffer A0 (12 bytes, used by rotation helpers)
!   0x0608A4F0  → vector buffer A1 (12 bytes, used by full multiply)
!   0x0608A520  → vector buffer A2 (12 bytes, transform output)
!   0x0608A52C  → matrix stack B pointer (current top of stack B)
!   0x0608A530  → matrix stack B alternate base
!   0x0608A6B0  → vector buffer B0 (12 bytes)
!   0x0608A6C0  → vector buffer B1 (12 bytes)
!   0x0608A6F0  → vector buffer B2 (12 bytes, transform output)
!   0x00010000  → fixed-point 1.0
!   0x002F2F20  → sin/cos lookup table base (ROM space)
!
! Why TWO stacks?
!   Stack A = world/camera transform pipeline
!   Stack B = object/model transform pipeline
!   The renderer needs to compose model→world→camera transforms.
!   Having two stacks avoids save/restore overhead when switching between
!   world-space and model-space calculations.


! =============================================================================
! Matrix Push — Stack A
! =============================================================================
! CONFIDENCE: DEFINITE — Verified at 0x06026DBC. Binary loads 0x06089EDC,
!   mov #48, 12-longword unrolled copy. Textbook matrix stack push.
!
! Copies 48 bytes from current top to new slot, advances pointer +48
!
! The matrix is stored row-major:
!   [m00 m01 m02]   at offsets +0x00 +0x04 +0x08
!   [m10 m11 m12]   at offsets +0x0C +0x10 +0x14
!   [m20 m21 m22]   at offsets +0x18 +0x1C +0x20
!   [tx  ty  tz ]   at offsets +0x24 +0x28 +0x2C

mat_push_A:  ! 0x06026DBC
    mov.l   @(PC),r3                ! r3 = &mat_stack_A_ptr (0x06089EDC)
    mov.l   @r3,r0                  ! r0 = current top
    mov     #48,r1
    add     r0,r1                   ! r1 = new top = old + 48
    mov.l   r1,@r3                  ! advance pointer
    ! Copy 48 bytes from r0 to r1 (12 longwords, unrolled)
    mov.l   @(0x00,r0),r2
    mov.l   @(0x04,r0),r3
    mov.l   r2,@(0x00,r1)
    mov.l   r3,@(0x04,r1)
    mov.l   @(0x08,r0),r2
    mov.l   @(0x0C,r0),r3
    mov.l   r2,@(0x08,r1)
    mov.l   r3,@(0x0C,r1)
    mov.l   @(0x10,r0),r2
    mov.l   @(0x14,r0),r3
    mov.l   r2,@(0x10,r1)
    mov.l   r3,@(0x14,r1)
    mov.l   @(0x18,r0),r2
    mov.l   @(0x1C,r0),r3
    mov.l   r2,@(0x18,r1)
    mov.l   r3,@(0x1C,r1)
    mov.l   @(0x20,r0),r2
    mov.l   @(0x24,r0),r3
    mov.l   r2,@(0x20,r1)
    mov.l   r3,@(0x24,r1)
    mov.l   @(0x28,r0),r2
    mov.l   @(0x2C,r0),r3
    mov.l   r2,@(0x28,r1)
    rts
    mov.l   r3,@(0x2C,r1)


! =============================================================================
! Matrix Pop — Stack A
! =============================================================================
! CONFIDENCE: DEFINITE — Verified at 0x06026DF8. Loads ptr, add #-48, stores.
!   4 instructions total. Trivially correct.

mat_pop_A:  ! 0x06026DF8
    mov.l   @(PC),r1                ! r1 = &mat_stack_A_ptr (0x06089EDC)
    mov.l   @r1,r0                  ! r0 = current top
    add     #-48,r0                 ! retreat by 48 bytes
    rts
    mov.l   r0,@r1                  ! store new pointer


! =============================================================================
! Matrix Identity — Stack A (via alternate base)
! =============================================================================
! CONFIDENCE: DEFINITE — Both entries verified (0x06026E02, 0x06026E0C).
!   Loads 0x00010000 (1.0), stores identity pattern: 1,0,0 / 0,1,0 / 0,0,1
!   plus zero translation. Pool constant 0x00010000 confirmed at 0x0602707C.
!
! Two entry points:
!   0x06026E02: set 0x06089EE0 as new pointer, then identity
!   0x06026E0C: identity on current top

mat_identity_A2:  ! 0x06026E02
    mov.l   @(PC),r0                ! r0 = 0x06089EE0
    mov.l   @(PC),r1                ! r1 = &mat_stack_A_ptr (0x06089EDC)
    mov     #0,r2
    bra     .identity_common_A
    mov.l   r0,@r1                  ! set new pointer

mat_identity_A:  ! 0x06026E0C
    mov.l   @(PC),r0                ! r0 = &mat_stack_A_ptr
    mov     #0,r2
    mov.l   @r0,r0                  ! r0 = current matrix top

.identity_common_A:
    ! 3x3 identity matrix in 16.16 fixed point
    mov.l   @(PC),r1                ! r1 = 0x00010000 (= 1.0)
    mov.l   r2,@(0x04,r0)           ! m01 = 0
    mov.l   r1,@(0x00,r0)           ! m00 = 1.0
    mov.l   r2,@(0x08,r0)           ! m02 = 0
    mov.l   r2,@(0x0C,r0)           ! m10 = 0
    mov.l   r1,@(0x10,r0)           ! m11 = 1.0
    mov.l   r2,@(0x14,r0)           ! m12 = 0
    mov.l   r2,@(0x18,r0)           ! m13 = 0
    mov.l   r2,@(0x1C,r0)           ! m21 = 0
    mov.l   r1,@(0x20,r0)           ! m22 = 1.0
    mov.l   r2,@(0x24,r0)           ! tx = 0
    mov.l   r2,@(0x28,r0)           ! ty = 0
    rts
    mov.l   r2,@(0x2C,r0)           ! tz = 0


! =============================================================================
! Matrix * Vector + Translation — Stack A
! =============================================================================
! CONFIDENCE: DEFINITE — Verified at 0x06026E2E. Stores vector to 0x0608A4E0,
!   loads matrix from 0x06089EDC, 3-iteration loop with clrmac + 3x mac.l +
!   xtrct + add translation + store back. Classic matrix*vec+trans.
!
! Input:  r4,r5,r6 = vector (X,Y,Z) in 16.16 fixed point
! Output: result stored to buffer 0x0608A4E0, and back into matrix translation
!
! Algorithm:
!   Store input vector to 0x0608A4E0
!   mat = *0x06089EDC (current matrix)
!   r5 = mat + 36 (translation row)
!   for each row i (3 iterations):
!     clrmac
!     mac.l @vec+, @mat_row+   (3 terms)
!     result[i] = xtrct(mach, macl) + translation[i]
!     translation[i] = result[i]   (overwrite translation!)

mat_xform_trans_A:  ! 0x06026E2E
    mov.l   @(PC),r0                ! r0 = 0x0608A4E0 (vector buffer)
    mov.l   @(PC),r1                ! r1 = &mat_stack_A_ptr (0x06089EDC)
    mov.l   r4,@(0x00,r0)           ! buf[0] = X
    mov.l   r5,@(0x04,r0)           ! buf[1] = Y
    mov.l   r6,@(0x08,r0)           ! buf[2] = Z
    mov.l   @r1,r4                  ! r4 = matrix base
    mov     #3,r3                   ! 3 rows
    mov     r4,r5
    add     #36,r5                  ! r5 = &translation (matrix + 36)
.xform_loop_A:
    clrmac
    mac.l   @r4+,@r0+              ! row[0] * vec[0]
    mac.l   @r4+,@r0+              ! row[1] * vec[1]
    mac.l   @r4+,@r0+              ! row[2] * vec[2]
    mov.l   @r5,r6                  ! r6 = translation[i]
    add     #-12,r0                 ! reset vector pointer
    dt      r3
    sts     mach,r1
    sts     macl,r2
    xtrct   r1,r2                   ! r2 = (mach:macl) >> 16 = fixed-point result
    add     r6,r2                   ! r2 += translation
    mov.l   r2,@r5                  ! store back to translation
    bf/s    .xform_loop_A
    add     #4,r5                   ! next translation element
    rts
    nop


! =============================================================================
! Matrix Scale — Stack A
! =============================================================================
! CONFIDENCE: DEFINITE — Verified at 0x06026E60. Loads from 0x06089EDC,
!   3-iteration outer loop (add #4,r7), inner reads at +0x00/+0x0C/+0x18
!   with dmuls.l by r4/r5/r6 respectively. xtrct and store back.
!
! AUDIT NOTE: The description below says "Scales each column" and shows
!   mat[row][0]*=r4 for all rows. This is misleading. The actual code:
!   - Outer loop iterates over COLUMNS (3 iterations, r7 += 4 each time)
!   - Inner: mat[0][col]*=r4, mat[1][col]*=r5, mat[2][col]*=r6
!   So each ROW gets its own scale factor, not each column.
!   Equivalent to pre-multiplying by diag(r4,r5,r6): row i scaled by factor i.
!
! Scales each ROW of the 3x3 matrix by scalar factors.
! Input: r4 = scaleRow0, r5 = scaleRow1, r6 = scaleRow2
!
! For each column j (3 iterations):
!   mat[0][j] = fixmul(mat[0][j], r4)
!   mat[1][j] = fixmul(mat[1][j], r5)
!   mat[2][j] = fixmul(mat[2][j], r6)
!
! Uses dmuls.l for full 64-bit multiply, then xtrct for 16.16 narrowing.

mat_scale_A:  ! 0x06026E60
    mov.l   @(PC),r0                ! 0x06089EDC
    mov.l   @r0,r7                  ! r7 = matrix base
    mov     #3,r3                   ! 3 rows
.scale_loop_A:
    ! Column 0: mat[row][0] *= r4
    mov.l   @(0x00,r7),r0
    dmuls.l r0,r4
    mov.l   @(0x0C,r7),r0           ! prefetch column 1
    sts     mach,r1
    sts     macl,r2
    xtrct   r1,r2                   ! = fixmul(mat[0], scaleX)
    ! Column 1: mat[row][1] *= r5
    dmuls.l r0,r5
    mov.l   r2,@(0x00,r7)           ! store column 0
    mov.l   @(0x18,r7),r0           ! prefetch column 2
    sts     mach,r1
    sts     macl,r2
    xtrct   r1,r2                   ! = fixmul(mat[1], scaleY)
    ! Column 2: mat[row][2] *= r6
    dmuls.l r0,r6
    mov.l   r2,@(0x0C,r7)           ! store column 1
    dt      r3
    sts     mach,r1
    sts     macl,r2
    xtrct   r1,r2                   ! = fixmul(mat[2], scaleZ)
    mov.l   r2,@(0x18,r7)           ! store column 2
    bf/s    .scale_loop_A
    add     #4,r7                   ! next row
    rts
    nop


! =============================================================================
! Matrix Rotation XZ — Stack A (FUN_06026E94)
! =============================================================================
! CONFIDENCE: HIGH — Verified at 0x06026E94 (labeled in aprog.s). Binary:
!   sts.l pr, loads 0x0608A4E0, mov #8 r5, bsr 0x06027358 (sincos),
!   neg for -sin, MAC loop on columns 1 and 2. Structure is correct.
!
! AUDIT NOTE: Name "rotXZ" is MISLEADING. This function modifies columns 1
!   and 2 (Y and Z basis vectors), which is rotation in the YZ plane
!   (around the X axis). A true XZ rotation would modify columns 0 and 2.
!   The naming convention in this file has all three rotation names swapped:
!     "rotXZ" (FUN_06026E94) = actually rotYZ (columns 1,2, around X)
!     "rotXY" (FUN_06026EDE) = actually rotXZ (columns 0,2, around Y)
!     "rotYZ" (FUN_06026F2A) = actually rotXY (columns 0,1, around Z)
!
! Rotates columns 1 and 2 of the matrix (YZ plane, around X axis)
! Input: r4 = angle (used to look up sin/cos via FUN_06027358)
!
! Algorithm:
!   Call sincos_lookup(r4) → sin @ r5, cos @ r6
!   buf = 0x0608A4E0
!   neg sin → buf[1]     (= -sin)
!   cos → buf[3]         (= cos)
!   mat = (*0x06089EDC) + 4  (column 1 start)
!
!   For each of 3 rows:
!     new_col1 = fixmul(buf[0], mat_col1) + fixmul(buf[1], mat_col2)
!     new_col2 = fixmul(buf[2], mat_col1) + fixmul(buf[3], mat_col2)
!     mat_col1 = new_col1
!     mat_col2 = new_col2
!
! This is a 2D rotation applied to the XZ columns of the matrix:
!   [cos  -sin]   applied to columns 1 and 2 of each row
!   [sin   cos]

FUN_06026E94:  ! 0x06026E94
    sts.l   pr,@-r15
    mov.l   @(PC),r6                ! r6 = 0x0608A4E0
    mov     #8,r5
    bsr     FUN_06027358            ! sincos_lookup(r4)
    add     r6,r5                   ! r5 = &buf[2]
    lds.l   @r15+,pr
    ! Now: @r5 = sin(angle), @r6 = cos(angle)
    mov.l   @r5,r1                  ! r1 = sin
    mov.l   @r6,r2                  ! r2 = cos
    neg     r1,r1                   ! -sin
    mov.l   r1,@(0x04,r6)           ! buf[1] = -sin
    ! buf[0] already has cos from sincos_lookup
    mov.l   @(PC),r0                ! r0 = &mat_stack_A_ptr
    mov.l   r2,@(0x0C,r6)           ! buf[3] = cos
    mov.l   @r0,r4                  ! r4 = matrix base
    mov     #3,r3                   ! 3 rows
    add     #4,r4                   ! r4 points to column 1
    ! 2-component rotation per row using MAC
.rotXZ_loop_A:
    mov     r4,r5
    mov     r6,r7
    clrmac
    mac.l   @r7+,@r5+              ! buf[0] * col1
    mac.l   @r7+,@r5+              ! buf[1] * col2
    add     #-8,r5                  ! reset r5 to col1
    sts     mach,r0
    sts     macl,r1
    xtrct   r0,r1                   ! new_col1
    clrmac
    mac.l   @r7+,@r5+              ! buf[2] * col1
    mac.l   @r7+,@r5+              ! buf[3] * col2
    mov.l   r1,@(0x00,r4)           ! store new_col1
    dt      r3
    sts     mach,r0
    sts     macl,r2
    xtrct   r0,r2                   ! new_col2
    mov.l   r2,@(0x04,r4)           ! store new_col2
    bf/s    .rotXZ_loop_A
    add     #12,r4                  ! next row
    rts
    nop


! =============================================================================
! Matrix Rotation XY — Stack A (FUN_06026EDE)
! =============================================================================
! CONFIDENCE: HIGH — Verified at 0x06026EDE (labeled in aprog.s). Binary:
!   sts.l pr, loads 0x0608A4E0, mov #4 r5, bsr 0x06027358,
!   MAC loop on columns 0 and 2 (with skip stride of 4).
!
! AUDIT NOTE: Name "rotXY" is misleading. Operates on columns 0 and 2
!   (X and Z basis vectors) = rotation in XZ plane around Y axis.
!   See AUDIT NOTE on FUN_06026E94 for full naming discussion.
!
! Rotates columns 0 and 2 of the matrix (XZ plane, around Y axis)
! Same structure as rotXZ but operates on columns 0 and 2

FUN_06026EDE:  ! 0x06026EDE
    sts.l   pr,@-r15
    mov.l   @(PC),r6                ! r6 = 0x0608A4E0
    mov     #4,r5                   ! offset into buffer (different from XZ)
    bsr     FUN_06027358
    add     r6,r5
    lds.l   @r15+,pr
    mov.l   @r5,r1                  ! sin
    mov.l   @r6,r2                  ! cos
    neg     r1,r1
    mov.l   r1,@(0x08,r6)           ! buf[2] = -sin
    mov.l   @(PC),r0
    mov.l   r2,@(0x0C,r6)           ! buf[3] = cos
    mov.l   @r0,r4
    mov     #3,r3
    ! Rotation applied to columns 0 and 2 (skip stride of 4)
.rotXY_loop_A:
    mov     r4,r5
    mov     r6,r7
    clrmac
    mac.l   @r7+,@r5+              ! buf[0] * col0
    add     #4,r5                   ! skip col1
    mac.l   @r7+,@r5+              ! buf[1] * col2
    add     #-12,r5
    sts     mach,r0
    sts     macl,r1
    xtrct   r0,r1
    clrmac
    mac.l   @r7+,@r5+
    add     #4,r5
    mac.l   @r7+,@r5+
    mov.l   r1,@(0x00,r4)           ! new_col0
    dt      r3
    sts     mach,r0
    sts     macl,r2
    xtrct   r0,r2
    mov.l   r2,@(0x08,r4)           ! new_col2
    bf/s    .rotXY_loop_A
    add     #12,r4
    rts
    nop


! =============================================================================
! Matrix Rotation YZ — Stack A (FUN_06026F2A)
! =============================================================================
! CONFIDENCE: HIGH — Verified at 0x06026F2A (labeled in aprog.s). Binary:
!   sts.l pr, loads 0x0608A4E0, mov #8 r5, bsr 0x06027358,
!   MAC loop on columns 0 and 1.
!
! AUDIT NOTE: Name "rotYZ" is misleading. Operates on columns 0 and 1
!   (X and Y basis vectors) = rotation in XY plane around Z axis.
!   See AUDIT NOTE on FUN_06026E94 for full naming discussion.
!
! Rotates columns 0 and 1 of the matrix (XY plane, around Z axis)
! Operates on columns 0 and 1

FUN_06026F2A:  ! 0x06026F2A
    sts.l   pr,@-r15
    mov.l   @(PC),r6                ! 0x0608A4E0
    mov     #8,r5
    bsr     FUN_06027358
    add     r6,r5
    lds.l   @r15+,pr
    mov.l   @r5,r1                  ! sin
    mov.l   @r6,r2                  ! cos
    neg     r1,r1
    mov.l   r1,@(0x04,r6)           ! buf[1] = -sin
    mov.l   @(PC),r0
    mov.l   r2,@(0x0C,r6)           ! buf[3] = cos
    mov.l   @r0,r4
    mov     #3,r3
    ! Rotation applied to columns 0 and 1
.rotYZ_loop_A:
    mov     r4,r5
    mov     r6,r7
    clrmac
    mac.l   @r7+,@r5+              ! buf[0] * col0
    mac.l   @r7+,@r5+              ! buf[1] * col1
    mov     r4,r5                   ! reset to col0
    sts     mach,r0
    sts     macl,r1
    xtrct   r0,r1
    clrmac
    mac.l   @r7+,@r5+
    mac.l   @r7+,@r5+
    mov.l   r1,@(0x00,r4)           ! new_col0
    dt      r3
    sts     mach,r0
    sts     macl,r2
    xtrct   r0,r2
    mov.l   r2,@(0x04,r4)           ! new_col1
    bf/s    .rotYZ_loop_A
    add     #12,r4
    rts
    nop


! =============================================================================
! Full 3x3 Matrix Multiply — Stack A
! =============================================================================
! CONFIDENCE: HIGH — Verified at 0x06026F72. Loads 0x06089EDC and 0x0608A4F0
!   (temp buffer), nested 3x3 loop with clrmac/mac.l (strided access for
!   column reads), then translation update phase and 48-byte copy back.
!   Complex function but structure is consistent with 3x3 multiply.
!
! Computes: M = M_current * M_input (transposed access pattern)
! Uses 0x0608A4F0 as temporary buffer
!
! Phase 1: Transpose multiply
!   For each column c of input (3 cols):
!     For each row r of M_current (3 rows):
!       result[r][c] = dot(M_current_row[r], M_input_col[c])
!   Store to 0x0608A4F0
!
! Phase 2: Translation update
!   For each component (3):
!     new_trans[i] = dot(input_row, M_current_trans) + M_current_trans[i]
!
! Phase 3: Copy 48 bytes from temp buffer back to matrix stack

mat_fullmul_A:  ! 0x06026F72
    mov.l   @(PC),r0                ! &mat_stack_A_ptr
    mov.l   @(PC),r6                ! 0x0608A4F0 (temp buffer)
    mov.l   @r0,r5                  ! r5 = matrix base
    mov     #3,r3                   ! outer loop: 3 columns
.fullmul_outer_A:
    mov     #3,r2                   ! inner loop: 3 rows
.fullmul_inner_A:
    clrmac
    ! Strided access: read every 12th byte (column access)
    mac.l   @r4+,@r5+
    add     #8,r4                   ! skip to next column element
    mac.l   @r4+,@r5+
    add     #8,r4
    dt      r2
    mac.l   @r4+,@r5+
    add     #-24,r4                 ! reset input pointer
    add     #-12,r5                 ! reset row pointer
    sts     mach,r0
    sts     macl,r1
    xtrct   r0,r1
    mov.l   r1,@r6                  ! store result element
    bf/s    .fullmul_inner_A
    add     #4,r6
    add     #-12,r4                 ! back to column start
    dt      r3
    bf/s    .fullmul_outer_A
    add     #12,r5                  ! advance to next row

    ! Phase 2: Translation = M * old_translation + old_translation
    mov     r5,r7                   ! r7 = translation pointer
    add     #-36,r5                 ! back to matrix start
    add     #36,r4                  ! r4 = input translation
    mov     #3,r3
.trans_update_A:
    clrmac
    mac.l   @r4+,@r5+
    mac.l   @r4+,@r5+
    dt      r3
    mac.l   @r4+,@r5+
    add     #-12,r4
    sts     mach,r0
    sts     macl,r1
    xtrct   r0,r1
    mov.l   @r7+,r0                 ! old translation
    add     r0,r1                   ! new = rotated + old
    mov.l   r1,@r6
    bf/s    .trans_update_A
    add     #4,r6

    ! Phase 3: Copy 48 bytes from buffer back to matrix
    add     #-48,r6                 ! back to buffer start
    add     #-48,r7                 ! back to matrix start
    ! Unrolled 48-byte copy (12 longwords)
    mov.l   @(0x00,r6),r0
    mov.l   @(0x04,r6),r1
    ! ... (full 48-byte copy) ...
    rts
    mov.l   r5,@(0x2C,r7)


! =============================================================================
! Matrix * Vector + Translation — Stack A (FUN_06026FFC)
! =============================================================================
! CONFIDENCE: DEFINITE — Labeled in aprog.s (FUN_06026FFC). Binary: push r14,
!   loads 0x06089EDC and 0x0608A520, mov #36 for translation offset,
!   3-iteration loop with clrmac/3x mac.l/xtrct/add translation/store.
!   Then copies 12 bytes from buffer to output. Classic M*v+t.
!
! Input: r4 = input vector ptr (3 ints), r5 = output vector ptr
! Output: result = M * vec + translation, stored to r5 AND 0x0608A520
!
! This is THE KEY transform function. Every object position goes through this.
! Called from FUN_06005ECC (segment tracking) and FUN_060061C8 (pre-render).

FUN_06026FFC:  ! 0x06026FFC
    mov.l   r14,@-r15
    mov.l   @(PC),r0                ! &mat_stack_A_ptr (0x06089EDC)
    mov     #36,r7                  ! translation offset
    mov.l   @r0,r6                  ! r6 = matrix base
    mov.l   @(PC),r14               ! r14 = 0x0608A520 (output buffer)
    add     r6,r7                   ! r7 = &matrix[translation]
    mov     #3,r3                   ! 3 rows
.vec_trans_loop_A:
    clrmac
    mac.l   @r4+,@r6+              ! row[0] * vec[0]
    mac.l   @r4+,@r6+              ! row[1] * vec[1]
    mov.l   @r7+,r2                 ! r2 = translation[i]
    mac.l   @r4+,@r6+              ! row[2] * vec[2]
    dt      r3
    add     #-12,r4                 ! reset input vector
    sts     mach,r0
    sts     macl,r1
    xtrct   r0,r1                   ! r1 = dot product (fixed-point)
    add     r2,r1                   ! + translation
    mov.l   r1,@r14                 ! store to buffer
    bf/s    .vec_trans_loop_A
    add     #4,r14
    ! Copy result from buffer to output (r5)
    add     #-12,r14
    mov.l   @r14+,r0
    mov.l   @r14+,r1
    mov.l   @r14+,r2
    mov.l   r0,@r5
    mov.l   r1,@(0x04,r5)
    mov.l   r2,@(0x08,r5)
    rts
    mov.l   @r15+,r14


! =============================================================================
! Matrix * Vector (no translation) — Stack A
! =============================================================================
! CONFIDENCE: DEFINITE — Verified at 0x06027038. Loads 0x06089EDC and
!   0x0608A520, 3-iteration loop with clrmac/3x mac.l/xtrct/store.
!   No translation add. Pure rotation transform.
!
! Same as above but WITHOUT adding translation. Pure rotation.

mat_vec_notrans_A:  ! 0x06027038
    mov.l   @(PC),r0                ! &mat_stack_A_ptr
    mov.l   @(PC),r6                ! 0x0608A520
    mov.l   @r0,r2                  ! matrix base
    mov     #3,r3
.vec_notrans_loop_A:
    clrmac
    mac.l   @r4+,@r2+
    mac.l   @r4+,@r2+
    mac.l   @r4+,@r2+
    dt      r3
    add     #-12,r4
    sts     mach,r0
    sts     macl,r1
    xtrct   r0,r1
    mov.l   r1,@r6
    bf/s    .vec_notrans_loop_A
    add     #4,r6
    ! Copy to output
    add     #-12,r6
    mov.l   @r6,r0
    mov.l   @(0x04,r6),r1
    mov.l   @(0x08,r6),r2
    mov.l   r0,@r5
    mov.l   r1,@(0x04,r5)
    rts
    mov.l   r2,@(0x08,r5)


! =============================================================================
! Sin/Cos Lookup (FUN_06027358)
! =============================================================================
! CONFIDENCE: DEFINITE — This is the same function documented in
!   math_helpers.s at 0x06027358. Verified byte-for-byte. See math_helpers.s
!   for full audit details.
!
! Input: r4 = angle (integer, units = 1/65536 of full rotation)
! Output: sin value stored at @r5, cos value stored at @r6
!
! The lookup table at 0x002F2F20 contains pre-computed sin values.
! Cos is obtained by looking up sin(angle + 90°), achieved by adding
! 8 to the table index before computing cos.
!
! Table entry size: 4 bytes (int32, 16.16 fixed point)
! AUDIT NOTE: Table has 4096 entries (mask 0x3FFC), not 256.
! Table has 4096 entries covering 0-360 degrees
!
! Algorithm:
!   r3 = r4 + (word constant)     (phase shift for cos)
!   r4 += 8                       (fine adjustment)
!   mask = (word constant)
!   table = 0x002F2F20
!   sin_idx = (r4 >> 2) & mask
!   cos_idx = (r3 >> 2) & mask
!   *r5 = table[sin_idx]
!   *r6 = table[cos_idx]

FUN_06027358:  ! 0x06027358
    mov.w   @(PC),r3                ! phase constant (cos offset)
    add     #8,r4                   ! fine adjust
    mov.w   @(PC),r1                ! index mask
    add     r4,r3                   ! r3 = angle + cos_phase
    mov.l   @(PC),r0                ! r0 = 0x002F2F20 (table base)
    shlr2   r4                      ! / 4
    and     r1,r4                   ! mask
    shlr2   r3                      ! / 4
    mov.l   @(r0,r4),r2             ! sin lookup
    and     r1,r3                   ! mask
    mov.l   r2,@r5                  ! store sin
    nop
    mov.l   @(r0,r3),r1             ! cos lookup
    rts
    mov.l   r1,@r6                  ! store cos


! =============================================================================
! Trig Table Lookup — Single Value
! =============================================================================
! CONFIDENCE: DEFINITE — Same as cos_lookup at 0x06027344 in math_helpers.s.
!   Verified byte-for-byte. See math_helpers.s for full audit.
!
! Input: r4 = angle
! Output: r0 = table value
! Simpler version for when only one trig value is needed.

trig_lookup_single:  ! 0x06027344
    mov.w   @(PC),r0                ! constant
    add     r0,r4
    mov.w   @(PC),r0                ! mask
    shlr2   r4
    add     #2,r4
    and     r0,r4
    mov.l   @(PC),r0                ! 0x002F2F20 table base
    rts
    mov.l   @(r0,r4),r0             ! return table[index]


! =============================================================================
! Advanced Trig — Piecewise Interpolation
! =============================================================================
! CONFIDENCE: HIGH — Same as atan_piecewise at 0x06027378 in math_helpers.s.
!   Verified first 4 instructions. See math_helpers.s for full audit.
!   The "likely used for ATAN2" note below is confirmed by the call chain:
!   FUN_0602745C (atan2_full) calls this function via bsr 0x06027378.
!
! 0x06027378
! Much larger function (~200 bytes) that implements high-precision
! trigonometry using piecewise polynomial interpolation.
!
! Takes angle in r4, returns result in r0.
! Uses multiple threshold checks to select the appropriate polynomial
! segment, then does fixed-point multiply/add for interpolation.
!
! The thresholds divide the angle space into 8+ segments, each with
! different coefficients stored in the constant pool:
!   0x00000AC0, 0x00001581, 0x000047AE, 0x0000B333
!   0x00018000, 0x0002F333
!   100, 70, 50 (integer thresholds for segment selection)
!
! This is likely used for ATAN2 computation (inverse tangent),
! needed for:
!   - AI steering angle calculation
!   - Camera rotation targeting
!   - Heading computation from velocity vectors


! =============================================================================
! Stack B Functions (0x06027080 - 0x060272FA)
! =============================================================================
! CONFIDENCE: HIGH — All 12 Stack B addresses verified in aprog.s:
!   0x06027080 (push), 0x060270BC (pop), 0x060270C6 (identity2),
!   0x060270D0 (identity), 0x060270F2 (xform), 0x06027124 (scale),
!   FUN_06027158 (labeled, rotXZ), FUN_060271A2 (labeled, rotXY),
!   FUN_060271EE (labeled, rotYZ), 0x06027236 (fullmul),
!   FUN_060272C0 (labeled, vec_trans), 0x060272FC (vec_notrans).
!   Pool constants confirmed: 0x0608A52C (stack ptr), 0x0608A530 (alt base),
!   0x0608A6B0/A6C0/A6F0 (vector buffers). Code is structurally identical
!   to Stack A except for address constants.
!
! AUDIT NOTE: The same rotation naming issue from Stack A applies here:
!   rotXZ_B actually rotates YZ (columns 1,2), rotXY_B rotates XZ (columns
!   0,2), rotYZ_B rotates XY (columns 0,1).
!
! Exact mirrors of Stack A functions, operating on:
!   Matrix pointer: 0x0608A52C
!   Alternate base: 0x0608A530
!   Vector buffer 0: 0x0608A6B0
!   Vector buffer 1: 0x0608A6C0
!   Vector buffer 2: 0x0608A6F0
!
! Function mapping:
!   mat_push_B      = 0x06027080  (identical to 0x06026DBC for stack B)
!   mat_pop_B       = 0x060270BC
!   mat_identity_B2 = 0x060270C6
!   mat_identity_B  = 0x060270D0
!   mat_xform_trans_B = 0x060270F2
!   mat_scale_B     = 0x06027124
!   mat_rotXZ_B     = FUN_06027158
!   mat_rotXY_B     = FUN_060271A2
!   mat_rotYZ_B     = FUN_060271EE
!   mat_fullmul_B   = 0x06027236
!   mat_vec_trans_B = FUN_060272C0
!   mat_vec_notrans_B = 0x060272FC
!
! The code is byte-for-byte identical except for pool constant references
! (pointing to stack B addresses instead of stack A).


! =============================================================================
! CALL GRAPH — Who uses these functions
! =============================================================================
!
! FUN_06026E94 (rotXZ_A):
!   Called from FUN_06005ECC (segment tracking — 6 calls!)
!   Called from FUN_060061C8 (pre-render transform setup)
!
! FUN_06026EDE (rotXY_A):
!   Called from FUN_06005ECC, FUN_060061C8
!
! FUN_06026FFC (mat_vec_trans_A):
!   Called from FUN_06005ECC (applies to 5 objects per frame)
!   Called from FUN_060061C8
!
! FUN_06027358 (sincos_lookup):
!   Called from ALL rotation functions (6 callers in stack A, 6 in stack B)
!   Called from trig_interp function
!
! mat_push/pop/identity:
!   Called from 3D renderer (FUN_06027CA4) — push before object, pop after
!   Called from scene setup code
!
! Stack B specifically used by:
!   The 3D scene renderer pipeline (FUN_06027CA4 and children)
!   Handles model→world transforms while stack A does camera


! =============================================================================
! SIGNIFICANCE
! =============================================================================
!
! This layer answers the question: "How does the game do 3D?"
!
! The Saturn has NO 3D hardware. Everything is done in software:
! 1. Build rotation matrix from Euler angles (rotXY, rotXZ, rotYZ)
! 2. Push/pop matrix stack for hierarchical transforms (like OpenGL)
! 3. Transform vertices: world_pos = M * model_pos + translation
! 4. The VDP1 (sprite chip) renders the 2D projected results
!
! Two stacks because the renderer needs:
!   Stack A: Camera transform (world → screen)
!   Stack B: Object transform (model → world)
!   Final: screen_pos = stack_A * (stack_B * vertex + obj_pos) + cam_pos
!
! The xtrct instruction is the key insight — it implements 16.16 fixed-point
! multiplication in a SINGLE instruction, using the 64-bit result from dmuls.l.
! This is why the SH-2 was chosen for 3D: MAC + xtrct = fast fixed-point math.
