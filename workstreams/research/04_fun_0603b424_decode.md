# FUN_0603B424: Complete State Machine Decode

## Overview

`FUN_0603B424` is the CD sector-reading state machine. It's called in a
retry loop by `FUN_0603B21C`. Each call:
1. Reads state from `arg0[0x12]` (the context struct's state byte)
2. Issues the CD command for that state
3. Reads response status byte from CR1[15:8]
4. Dispatches to a status handler
5. Updates state and returns (0=done, non-zero=retry)

## Byte Listing

```
reimpl/src/FUN_0603B424.s  (production address: 0x0603B424)
```

## Function Prologue

```
2F E6  mov.l R14, @-R15    ; push R14
E0 12  mov #0x12, R0       ; R0 = 0x12
2F D6  mov.l R13, @-R15    ; push R13
6E 43  mov R4, R14         ; R14 = arg0 (context struct pointer)
2F 86  mov.l R8, @-R15     ; push R8
4F 22  sts.l PR, @-R15     ; push PR
03 EC  mov.b @(R0,R14), R3 ; R3 = arg0[0x12] (state byte)
63 3C  extu.b R3, R3       ; zero-extend
23 38  tst R3, R3           ; test state == 0?
8B 01  bt +1 → (far forward) ; if state==0: jump to exit_path
A0 75  bra exit_retry       ; if state!=0: jump way forward (return 1)
00 09  nop (delay slot)
```

If state == 0 at entry: `goto exit_path` (skip everything, return immediately).
If state != 0 at entry: falls through to... actually wait, the bt goes forward
and the bra goes forward. Let me re-read.

`8B 01` = bt +1: if T=1 (state==0), branch to +1*2+4=6 ahead = offset +0x18
`A0 75` = bra: if T=0 (state!=0), branch to +0x75*2+4=238+4 = way ahead

So:
- state == 0: falls through to offset +0x18 (the BSR call)
- state != 0: bra far forward (return retry path with R4=-1?)

Wait, that seems backwards. Actually `tst R3, R3` sets T=1 when R3==0 (state==0).
`bt +1` branches when T=1, i.e., when state==0. So state==0 → bt taken → skip bra.
state!=0 → bt not taken → execute bra.

Actually re-reading more carefully: `bt +1` at offset 0x12 branches to 0x12+6=0x18.
So when state==0: continue to offset 0x18 = a BSR call.
When state!=0: execute `A0 75` = bra to +234+4=+238 bytes ahead.

At offset +0xEE (= 238 bytes ahead): this is likely a "retry" return path that
calls FUN_0603B93C with some error code and returns.

## BSR at offset 0x18

`B4 6E` = BSR to some external function (Get Sector Number-related command).
`64 E3` = delay slot: R4 = R14 (passes context as arg).

This BSR issues the CD command appropriate to the current state. After return,
it processes the response status byte.

## The Status Dispatch Table (offset ~0xAC in function body)

After the CD command is issued and response received, the drive status byte
(in R0) is checked:

```
88 00  cmp/eq #0, R0    ; BUSY?
89 E8  bt -24           ; → offset +0x082

88 01  cmp/eq #1, R0    ; PAUSE?
89 D9  bt -39           ; → offset +0x068

88 03  cmp/eq #3, R0    ; PLAY?
89 BC  bt -68           ; → offset +0x032

88 04  cmp/eq #4, R0    ; SEEK?
89 C3  bt -61           ; → offset +0x044

88 05  cmp/eq #5, R0    ; SCAN?
89 CA  bt -54           ; → offset +0x056

88 06  cmp/eq #6, R0    ; OPEN?
89 AD  bt -83           ; → offset +0x020
```

If no match → falls through to DEFAULT PATH at offset ~0xC4+rest.

## Handler Descriptions

### OPEN handler (+0x020)
```
92 3F  mov.w @(pool), R3    ; state = 0xFF
E0 12  mov #0x12, R0
0E 24  mov.b R3, @(R0,R14)  ; arg0[0x12] = 0xFF
E4 FF  mov #-1, R4           ; return code = -1
4F 26  lds.l @R15+, PR
...epilogue...
```
State → 0xFF, return -1 (error).

### SEEK handler (+0x044) — example for other state-update handlers
Updates state to 0x2F, returns R4=0xFE (retry/wait).

### PLAY handler (+0x032)
Updates state to 0x37, returns R4=0xE9. Retry. The outer loop calls B424
again with state=0x37, which will advance to Calculate path.

### PAUSE handler (+0x068) — THE CRITICAL ONE
```
B5 65  BSR → FUN_0603BF22+0x38 (GetBufSize command)
64 E3  delay: R4 = R14 (context)
88 01  cmp/eq #1, R0          ; GetBufSize retval == 1?
8B 29  bt +41                 ; if retval==1: jump to +0x0C4 (CALCULATE PATH!)

93 1B  mov.w @(pool:0xE8), R3 ; else: state = 0xE8
E0 12  mov #0x12, R0
0E 34  mov.b R3, @(R0,R13)    ; arg0[0x12] = 0xE8
E4 E8  mov #-24, R4            ; return -24 (retry)
...epilogue return...
```

**The bug**: `GetBufSize retval == 1` means "buffer empty/ready for Calculate".
When 14 sectors are pre-buffered (play-end-pause), retval != 1 → retries forever.

### BUSY handler (+0x082)
```
E0 11  mov #0x11, R0
00 EC  mov.b @(R0,R14), R0    ; R0 = arg0[0x11] (sub-status byte)
60 00  (extu.b R0, R0)         ; zero-extend
88 02  cmp/eq #2, R0           ; sub-status == 2?
8B 1B  bt +27                  ; if sub-status==2: reset path
...
```
If sub-status == 2: full reset (state=0, various cleanup calls).
Otherwise: fall through to default path.

## Calculate Path (+0x0C4)

```
B4 60  BSR → some function
64 E3  delay: R4 = R14
64 03  R4 = R3 (result)
60 D3  R0 = R13 (saved_status from dispatch)
88 02  cmp/eq #2, R0      ; saved_status == 2 (STANDBY)?
8B 18  bt +24             ; if yes: skip ahead to Calculate command
60 43  R0 = R4            ; else: check function return value
88 05  cmp/eq #5, R0      ; FUN_0603BDAC result == 5?
8B 15  bt +21             ; if yes: issue Calculate commands
```

If saved_status==2 AND FUN_0603BDAC==5: → Calculate Actual Size → Get Actual Size → etc.
If saved_status==anything else: → return without Calculate.

## Pool Data (at function tail)

```
DAT_0603b4c6: 0x00FF  (state for OPEN)
DAT_0603b4c8: 0x00E9  (state for PLAY)
DAT_0603b4ca: 0x00FE  (state for SEEK)
DAT_0603b4cc: 0x00EC  (state for SCAN)
DAT_0603b4ce: 0x00E8  (state for PAUSE fall-through retry)
```

## FUN_0603B21C: The Retry Loop

```
2F E6  push R14
6E 43  R14 = arg0
2F D6  push R13
4F 22  push PR
7F F4  add #-12, R15          ; stack frame
D3 13  mov.l @(pool:0x7FFFFFFF), R3  ; R3 = 0x7FFFFFFF
1F 32  mov.l R3, @(8, R15)    ; local var [SP+8] = 0x7FFFFFFF
64 E2  R4 = R14                ; arg0 → R4 for FUN_0603B424 call
5D 4A  mov.l @(40, R4), R13   ; R13 = arg0[40] (save old value)
14 3A  mov.l R3, @(40, R4)    ; arg0[40] = 0x7FFFFFFF (reset counter)
[loop]
B0 2D  BSR → FUN_0603B424 call site
64 E3  delay: R4 = R14
24 48  tst R4, R4              ; result == 0?
89 04  bt +4 (8+4=done) → if 0 (done): exit
...
44 11  cmp/pz R4               ; R4 >= 0?
89 04  bt +4: if >=0: loop back
...retry decrement logic...
```

The retry loop calls FUN_0603B424 until it returns 0 (success) or timeout.

## External Functions Referenced

| Address | Role |
|---------|------|
| FUN_0603BD1C | Issues Get Sector Number command |
| FUN_0603BDAC | Query function; returns 5 when sectors ready for Calculate |
| FUN_0603BF22+0x38 | GetBufSize command |
| FUN_0603B93C | State notification/callback; takes int error code |
| FUN_0603B8B4 | Cleanup step after Calculate |
| FUN_0603B9D6 | Cleanup step |
| FUN_0603AFD0 | Takes (ctx, size_diff, flag); likely notifies caller of transfer size |
| sym_0603F9F2 | Calculate Actual Size sub-label |
| sym_0603F9F6 | Get Actual Size sub-label |
