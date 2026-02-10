# Game RAM Address Map
# Total unique addresses: 965
# Total references: 5255

## System globals (0x06050000-0x06060000): 239 addrs, 808 refs

| Address | Refs | Types | Likely Purpose |
|---------|------|-------|----------------|
| 0x0605B6D8 |   25 | int   |  |
| 0x0605AD00 |   23 | int   |  |
| 0x0605A008 |   19 | int   |  |
| 0x06059FFC |   18 | int   |  |
| 0x06059F44 |   15 | int   |  |
| 0x0605BE36 |   15 | short |  |
| 0x0605A016 |   13 | int, short |  |
| 0x0605DE24 |   12 | int   |  |
| 0x0605DFF4 |   12 | int   |  |
| 0x06059F30 |   11 | int   |  |
| 0x0605AD10 |   11 | int   |  |
| 0x0605D05C |   11 | int   |  |
| 0x0605D242 |   11 | int   |  |
| 0x0605AAA0 |   10 | int, short |  |
| 0x0605D243 |   10 | int   |  |
| 0x06059EC8 |    9 | ?     |  |
| 0x0605BE24 |    9 | short |  |
| 0x0605D248 |    9 | int   |  |
| 0x0605D24C |    9 | int   |  |
| 0x0605E098 |    9 | int   |  |

## Frame/timing state (0x06060000-0x06065000): 247 addrs, 1151 refs

| Address | Refs | Types | Likely Purpose |
|---------|------|-------|----------------|
| 0x06063750 |   79 | int   |  |
| 0x06063D98 |   35 | int   |  |
| 0x06063E20 |   34 | int   |  |
| 0x060620D0 |   29 | int   |  |
| 0x06063D9A |   26 | int, short |  |
| 0x06062180 |   24 | int   |  |
| 0x060635AC |   24 | int, short | VDP1 batch flag |
| 0x060621D8 |   23 | int   |  |
| 0x060620D8 |   22 | int   |  |
| 0x0606212C |   22 | int, short |  |
| 0x06063F5C |   22 | int   |  |
| 0x060620D4 |   21 | int   |  |
| 0x060610BC |   20 | int, short |  |
| 0x06061238 |   19 | short |  |
| 0x06063F64 |   19 | int, short |  |
| 0x06063EC4 |   18 | int, short |  |
| 0x06063E9C |   17 | int, short |  |
| 0x06063F28 |   15 | int   |  |
| 0x06063E1C |   14 | int   |  |
| 0x06063EB0 |   14 | int, short |  |

## VDP/rendering state (0x06065000-0x06070000): 9 addrs, 44 refs

| Address | Refs | Types | Likely Purpose |
|---------|------|-------|----------------|
| 0x060684EC |   11 | short |  |
| 0x0606A4F4 |   10 | int   |  |
| 0x0606A4EC |    8 | int   |  |
| 0x0606A4F8 |    6 | int   |  |
| 0x0606A4F0 |    4 | int   |  |
| 0x0606BDFC |    2 | int   |  |
| 0x06069BB6 |    1 | ?     |  |
| 0x0606B178 |    1 | ?     |  |
| 0x0606BDF8 |    1 | int   |  |

## Car data (40 slots @ 0x268) (0x06078000-0x06080000): 127 addrs, 978 refs

| Address | Refs | Types | Likely Purpose |
|---------|------|-------|----------------|
| 0x0607E940 |   91 | int   | Current car ptr (player?) |
| 0x0607EAD8 |   85 | int   |  |
| 0x0607E944 |   77 | int, short | Current car ptr (target?) |
| 0x06078900 |   30 | int, short | Car struct base (40 slots) |
| 0x0607EADC |   27 | int   |  |
| 0x0607EAE0 |   24 | int   |  |
| 0x0607EBC4 |   23 | int   |  |
| 0x0607EA98 |   22 | int, short |  |
| 0x0607EBCC |   22 | int, short |  |
| 0x0607EAB8 |   21 | int   |  |
| 0x0607887F |   17 | int   |  |
| 0x0607EA9C |   17 | int   |  |
| 0x06078868 |   16 | int   |  |
| 0x06078635 |   15 | char, int |  |
| 0x06078644 |   15 | int   |  |
| 0x060786A4 |   15 | int   |  |
| 0x060785FC |   14 | int   |  |
| 0x060788F4 |   13 | int   |  |
| 0x0607EB88 |   13 | int   |  |
| 0x0607EBC8 |   13 | int   |  |

## Object state A (0x06080000-0x06088000): 144 addrs, 612 refs

| Address | Refs | Types | Likely Purpose |
|---------|------|-------|----------------|
| 0x0608602C |   35 | int   |  |
| 0x06086050 |   22 | int   |  |
| 0x060877D8 |   20 | int   |  |
| 0x06083255 |   19 | int   |  |
| 0x06086056 |   19 | int, short |  |
| 0x06084B08 |   17 | int   |  |
| 0x06084FC8 |   17 | char, int |  |
| 0x06085FF0 |   16 | int   |  |
| 0x06084B14 |   13 | int   |  |
| 0x06085F90 |   12 | int, short |  |
| 0x06085FF4 |   12 | int   |  |
| 0x06084B18 |   10 | int   |  |
| 0x06086020 |   10 | int   |  |
| 0x0608600E |    9 | int   |  |
| 0x06083250 |    8 | int   |  |
| 0x06085F89 |    8 | int   |  |
| 0x06085FF1 |    8 | int   |  |
| 0x06082A30 |    7 | int   |  |
| 0x06083254 |    7 | int   |  |
| 0x06083258 |    7 | int   |  |

## Object state B (0x06088000-0x06090000): 66 addrs, 523 refs

| Address | Refs | Types | Likely Purpose |
|---------|------|-------|----------------|
| 0x06089EDC |  118 | int   |  |
| 0x0608A52C |   55 | int   |  |
| 0x0608AC20 |   51 | short |  |
| 0x0608A70C |   22 | int   |  |
| 0x0608A7A0 |   22 | int   |  |
| 0x06089ED0 |   18 | int   |  |
| 0x06089E44 |   17 | int, short |  |
| 0x06089E98 |   12 | int, short |  |
| 0x06089ED6 |   12 | int, short |  |
| 0x06089B18 |   11 | ?     |  |
| 0x0608959C |   10 | ?     |  |
| 0x06089ED4 |   10 | int   |  |
| 0x06089E9C |    8 | int, short |  |
| 0x0608A4E0 |    8 | int   |  |
| 0x0608A6B0 |    8 | int   |  |
| 0x0608962C |    6 | int   |  |
| 0x06089744 |    6 | int   |  |
| 0x06089E4A |    6 | int   |  |
| 0x0608A704 |    6 | int   |  |
| 0x0608A798 |    6 | int   |  |

## Rendering pipeline (0x06090000-0x06098000): 21 addrs, 478 refs

| Address | Refs | Types | Likely Purpose |
|---------|------|-------|----------------|
| 0x06094A30 |  185 | int   |  |
| 0x06094AB0 |   87 | int   |  |
| 0x06094EF4 |   34 | int   |  |
| 0x06094A28 |   33 | int   |  |
| 0x06094A20 |   22 | int   |  |
| 0x06094A60 |   22 | ?     |  |
| 0x06094FA8 |   19 | int   |  |
| 0x06094F74 |   16 | int   |  |
| 0x06094AE0 |   12 | int   |  |
| 0x06094A90 |   11 | ?     |  |
| 0x060961A8 |    9 | int   |  |
| 0x06094EEC |    6 | int   |  |
| 0x06094EE4 |    4 | int   |  |
| 0x06094F24 |    4 | ?     |  |
| 0x06094FA4 |    3 | int   |  |
| 0x06094220 |    2 | ?     |  |
| 0x06094620 |    2 | ?     |  |
| 0x06094AE4 |    2 | ?     |  |
| 0x06094F54 |    2 | ?     |  |
| 0x06095F48 |    2 | ?     |  |

## CD/session state (0x060A0000-0x060A8000): 112 addrs, 661 refs

| Address | Refs | Types | Likely Purpose |
|---------|------|-------|----------------|
| 0x060A5400 |   99 | char, int |  |
| 0x060A4D14 |   44 | int   |  |
| 0x060A3E68 |   34 | int   |  |
| 0x060A3D88 |   27 | int   |  |
| 0x060A3DF8 |   22 | int, short |  |
| 0x060A3E38 |   20 | int, short |  |
| 0x060A4CB4 |   20 | int   |  |
| 0x060A4D84 |   18 | int   |  |
| 0x060A4CC0 |   16 | int   |  |
| 0x060A4D8C |   12 | int   |  |
| 0x060A4C70 |   11 | int   |  |
| 0x060A4C44 |   10 | int   |  |
| 0x060A4C4C |   10 | int   |  |
| 0x060A4D18 |   10 | int   |  |
| 0x060A3F68 |    9 | int   |  |
| 0x060A4C38 |    9 | int   |  |
| 0x060A4C78 |    9 | int   |  |
| 0x060A53B8 |    9 | ?     |  |
| 0x060A6000 |    9 | short |  |
| 0x060A2428 |    8 | int   |  |

