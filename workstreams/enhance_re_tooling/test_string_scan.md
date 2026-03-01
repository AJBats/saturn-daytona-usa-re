# String Scan — Test Results

Tool: `tools/string_scan.py`
Binary: `reimpl/build/APROG.BIN` (394,884 bytes)
Run: `python tools/string_scan.py reimpl/build/APROG.BIN --strict --refs --map reimpl/build/daytona.map`

## Results

249 strings found in strict mode (NUL-terminated, >=50% letters, >=1 word of 3+ chars).
21 strings have pool references (code that loads their address).

## String Categories Discovered

### CD File Names (0x06045880-0x06045A04)
APROG.BIN, COURSE0-2.BIN, CS0-2POLY.BIN, CS0-2_LINE.BIN, TEX_PL/C0-2.BIN,
SCROLL.BIN, TABLE.BIN, POLYGON.BIN, PIT.BIN, SOUNDS.BIN, GAMED.BIN, GAME0-1.BIN,
SLCTD.BIN, SLCT0.BIN, OVERD.BIN, OVER0.BIN, NAMD.BIN, NAM0.BIN, MUSICD/2D/3D.BIN

These anchor the CD loading functions.

### Menu/UI Text (0x0604AE00-0x0604AE78)
PRESS NEXT, GAME MODE, DIFFICULTY, ENEMY LEVEL, SOUND MODE, MUSIC TEST,
SOUND TEST, KEY ASSIGN

### Sound Effect Names (0x0604B030-0x0604B29C)
Traffic sign crash, Pylon crash, Big crash, Car crash (Right/Left/Center),
Pass slow (Right/Left), Wall rub short (Right/Left), Tire skid & rev (Low/Mid/High),
Air drill, Tool drop, Cheers, Signal spin, Signal leave, 777, Countdown, Accelerate

### Announcer Voice Lines (0x0604B1B4-0x0604B3EC)
"And they're under way.", "The white flag is out.", "Three!", "Two!", "One!",
"Time extension.", "Please select a race course.", "Manual.", "Automatic.",
"Beginner.", "Advanced.", "Expert.", "Gentlemen, start your engines."

### Music Track Names (0x0604AEA8-0x0604B01C)
Let's Go Away, Start Your Engines, The King Of Speed, Sky High,
Pounding Pavement, Breakdown, Raggin', Check It Out!, Rolling Start,
The Dream Of Daytona, Can You Fly?, David Goes To Victory Lane,
plus KARAOKE variants

### Song Lyrics (0x0605A828-0x0605ABC0)
Full karaoke lyrics for "Let's Go Away" and "Sky High"

### Save Data Messages (0x0604B534-0x0604B758)
SEGA-SATURN DAYTONA, save slot names (DAYTONA__00-03),
memory manager instructions, error messages

### Game Config (0x06059F4C-0x0605A0EC)
TYPE A/B/C/D, EDIT, PRESS A OR C TO DECIDE, CANCEL

### Error Handlers (0x0605AC14-0x0605AC44)
Illegal Instruction!, Illegal Slot!, Address Error! (CPU)

### Misc
REPLAY, FASTEST LAP, MIRROR MODE, ACCELERATION,
SET DAYTONA DISC!, DAYTONA UMA/UMA2, SEGA LOGO

## Pool References (code anchors)

| String | Referenced From |
|--------|----------------|
| "a race course." | loc_0604C538, sym_0604D808 |
| "PLEASE DELETE..." | loc_0604C6A8, sym_0604D808 |
| "SAVED CORRECTLY" | loc_0604C7C0, sym_0604D808 |
| "Blue blue skies I see" | DAT_06010c4e, hud_main_draw |
| "I wanna fly sky high" | sym_0605BB74 |
| "Let's go together" | sym_0605BB74 |
| Song lyrics | position_vel_limiter, file_data_parse, file_format_parse |

## Verdict: PASS

The scanner correctly identifies game strings and filters opcode noise.
Pool reference resolution with symbol map works. Song lyrics referenced from
hud_main_draw confirms karaoke display code.
