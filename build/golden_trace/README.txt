Golden Arcade Trace — Full gameplay from boot to racing
Recorded: 2026-02-28
Trace: arcade_full.txt (62 input events, frames 174-5596)

Game flow and screenshot mapping:

  STAGE           SCREENSHOT  FRAME   NOTES
  --------------- ----------- ------- -----------------------------------
  Attract         0010        1124    Cars racing, PRESS START blinks
  Title           0011        1308    DAYTONA USA logo (PRESS START blinks)
  Mode Select     0012        1483    ARCADE MODE blinks (caught invisible)
  Circuit Select  0013        1714    BEGINNER highlighted, timer 19
  Circuit Select  0014        1893    ADVANCED (after RIGHT)
  Circuit Select  0015        2073    EXPERT (after RIGHT)
  Circuit Select  0016        2253    ADVANCED (after LEFT)
  Circuit Select  0017        2508    BEGINNER (after LEFT), timer 5
  Car Select      0018        2981    Automatic transmission, timer 29
  Car Select      0019        3235    Manual-4 (after RIGHT)
  Car Select      0020        3491    Automatic (after LEFT)
  Pre-Race        0021        3870    "GENTLEMEN START YOUR ENGINES"
  Racing          0022        4253    AUTO DRIVE, 184mph, 40/40
  Racing          0023        4653    187mph, 40/40, near start line
  Racing          0024        4811    Steering left, 192mph, 39/40
  Racing          0025        4890    In turn, 162mph, 39/40
  Racing          0026        5067    Hit wall, 48mph, 40/40
  Racing          0027        5323    Off-track (grass), 57mph, 40/40

Key inputs:
  - C button = confirm/select in all menus
  - START = skip BIOS, skip attract, enter menu (no-op on circuit/car select)
  - LEFT/RIGHT = navigate circuit select and car select
  - LEFT/RIGHT = steering during race
  - C held during race (gas? or view — HUD shows AUTO DRIVE)

Menu button mapping (for watchpoint investigation):
  - Mode Select: C confirms selection (ARCADE/SATURN/RANKING/OPTIONS)
  - Circuit Select: LEFT/RIGHT browse, C confirms
  - Car Select: LEFT/RIGHT = Automatic/Manual-4, C confirms
