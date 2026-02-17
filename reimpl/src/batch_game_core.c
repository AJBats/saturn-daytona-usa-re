#include "game.h"

extern int DAT_0600635e;
extern int DAT_06006360;
extern int DAT_06006362;
extern int DAT_06006662;
extern int DAT_06006666;
extern int DAT_06006668;
extern int DAT_0600666a;
extern int DAT_06006752;
extern int DAT_06006754;
extern int DAT_06006756;
extern int DAT_06006758;
extern int DAT_0600675a;
extern int DAT_06006802;
extern int DAT_06006c1e;
extern int DAT_06006cca;
extern int DAT_06006da6;
extern int DAT_06006da8;
extern int DAT_06006daa;
extern int DAT_06007412;
extern int DAT_06007414;
extern int DAT_06007416;
extern int DAT_06007418;
extern int DAT_0600741a;
extern int DAT_060076e2;
extern int DAT_0600777e;
extern int DAT_060078ca;
extern int DAT_060079ce;
extern int DAT_06007a92;
extern int DAT_06007a94;
extern int DAT_06007a96;
extern int FUN_060067c8();
extern void FUN_06007a50();
extern void FUN_06007bcc();
extern int PTR_DAT_0600644c;
extern int PTR_DAT_0600654c;
extern int PTR_DAT_06006c20;
extern int PTR_DAT_06006dac;
extern int PTR_DAT_0600741c;
extern int PTR_DAT_060079d0;
extern short DAT_06006804;

/* FUN_060061c8: L2 version in car_position_update.c */
extern void FUN_060061C8(void);
#if 0 /* FUN_060061C8 -- replaced by ASM import of original bytes */
void FUN_060061c8(void) { FUN_060061C8(); }
#endif

/* FUN_0600629c: L2 version in car_table_init.c */
extern void FUN_0600629C(void);
extern void FUN_06007590();
extern void FUN_06007540();
void FUN_0600629c(void) { FUN_0600629C(); }

/* camera_zoom_step -- Step the camera zoom level toward its target.
 * Target zoom from table 0x060446B8 indexed by camera mode (0x06063E20).
 * Current zoom at 0x06063E24; zoom level (0-4) at 0x06063E1C.
 * When zoom > target: decreases zoom and adjusts FOV/clipping at
 * 0x06063E34 (near plane), 0x06063E28 (far plane), 0x06063E2C (height),
 * 0x06063E30 (Y offset). Thresholds: 0x8000, 0x58000, 0x78000.
 * When zoom < target: increases with mirrored adjustments.
 * Computes render scale via fixed-point multiply (0x06027552).
 * Disables scene rendering (0x06059F30=0) for levels 0 and 1-below-2. */
int FUN_060064f2()
{
  int *zoom_val = (int *)0x06063E24;
  int *zoom_level = (int *)0x06063E1C;
  int *target = (int *)0x06063F4C;
  int *near_plane = (int *)0x06063E34;
  int *far_plane = (int *)0x06063E28;
  int *height = (int *)0x06063E2C;
  int *y_offset = (int *)0x06063E30;
  int scale;
  int result;

  *target = *(int *)(0x060446B8 + *(int *)(0x06063E20 << 2));

  if (((int)0x00008000 < *zoom_val) || (*(int *)0x06078654 == '\x04')) {
    (*(int(*)())0x06038BD4)(8, 0); /* CD normal speed */
  } else {
    (*(int(*)())0x06038BD4)(8, 5); /* CD reduced speed */
  }

  if (*zoom_val == *target) {
    *zoom_level = *(int *)0x06063E20;
  } else if (*target < *zoom_val) {
    /* zoom out (decrease) */
    if ((int)0x00078000 < *zoom_val) {
      *zoom_level = 4;
      *zoom_val = *zoom_val - (int)0x00010000;
      *near_plane = *near_plane - -576;
      *far_plane = *far_plane - (int)0x0003C000;
    } else if ((int)0x00058000 < *zoom_val) {
      *zoom_level = 3;
      *zoom_val = *zoom_val - (int)0x4000E000;
      *near_plane = *near_plane + 0x80;
      *far_plane = *far_plane - (int)0x0001C000;
    } else if ((int)0x00008000 < *zoom_val) {
      *zoom_level = 2;
      *zoom_val = *zoom_val - (int)0x0000A000;
      *near_plane = *near_plane + 0x40;
      *far_plane = *far_plane - (int)0x00010000;
      *y_offset = *y_offset - (int)DAT_06006666;
    } else if (*zoom_val < 1) {
      *zoom_level = 0;
    } else {
      *zoom_level = 1;
      *zoom_val = *zoom_val - (int)DAT_06006668;
      *near_plane = *near_plane - -352;
      *far_plane = *far_plane - (int)0x00058000;
      *height = *height - (int)0x000D0000;
      if (*(int *)0x06083255 != '\0') {
        *height = *height - (int)0x000A0000;
      }
    }
  } else if (*zoom_val < *target) {
    /* zoom in (increase) */
    if (*zoom_val < (int)0x00008000) {
      *zoom_level = 0;
      *zoom_val = *zoom_val + (int)DAT_06006752;
      *near_plane = *near_plane + -352;
      *far_plane = *far_plane + (int)0x00058000;
      *height = *height + (int)0x000D0000;
      if (*(int *)0x06083255 != '\0') {
        *height = *height + (int)0x000A0000;
      }
    } else if (*zoom_val < (int)0x00058000) {
      *zoom_level = 1;
      *zoom_val = *zoom_val + (int)0x0000A000;
      *near_plane = *near_plane + -0x40;
      *far_plane = *far_plane + (int)0x00010000;
      *y_offset = *y_offset + (int)DAT_06006756;
    } else if (*zoom_val < (int)0x00078000) {
      *zoom_level = 2;
      *zoom_val = *zoom_val + (int)DAT_06006758;
      *near_plane = *near_plane + -0x80;
      *far_plane = *far_plane + (int)0x0001C000;
    } else if (*zoom_val < (int)0x00178000) {
      *zoom_level = 3;
      *zoom_val = *zoom_val + (int)0x00010000;
      *near_plane = *near_plane + -576;
      *far_plane = *far_plane + (int)0x0003C000;
    } else {
      *zoom_level = 4;
    }
  }

  scale = (*(int(*)())0x06027552)(*zoom_val, (int)DAT_06006802); /* fixed-point scale */
  *(int *)0x06063F04 = scale;
  result = (*(int(*)())0x06027552)(*zoom_val, (int)DAT_06006802);
  *(int *)0x06063F08 = result;

  if ((*zoom_level == 0) ||
     ((result = *zoom_level, result == 1 && (*(unsigned int *)0x06063E20 < 2)))) {
    *(int *)0x06059F30 = 0; /* disable scene rendering */
  } else {
    *(int *)0x06059F30 = 1; /* enable scene rendering */
  }

  return result;
}

/* sound_bank_and_stereo_setup -- Initialize sound bank and stereo panning.
 * Gets sound bank index via get_sound_bank_index, applies to mixer.
 * Then sets stereo panning for L/R channels at 0x06063F48/4A based
 * on player index at 0x06078663 (0=normal, else=swapped). */
int FUN_060067c8(void)
{
    short bank;
    char player_idx;
    short pan_val;

    bank = (*(int(*)())0x0601A5F8)();  /* get_sound_bank_index */
    (*(int(*)())0x06026590)((int)(char)*(char *)0x0605D240, bank);

    pan_val = DAT_06006804;
    player_idx = *(char *)0x06078663;

    if (player_idx == 0) {
        *(short *)0x06063F48 = pan_val;
        *(short *)0x06063F4A = (short)0x8000;
    } else {
        *(short *)0x06063F48 = (short)0x8000;
        *(short *)0x06063F4A = pan_val;
    }

    return (int)player_idx;
}

/* world_to_tile_index -- Convert world X,Z coords to flat tile grid index.
 * World range: X [-0x04000000..+0x03FFFFFF], Z [0..0x03FFFFFF]
 * Grid: 64 columns. >>21 divides 64M range into 32 steps per axis.
 * Returns: row * 64 + column */
int FUN_06006838(int world_x, int world_z)
{
    unsigned int row = (unsigned int)(0x03FFFFFF - world_z) >> 21;
    unsigned int col = (unsigned int)(0x04000000 + world_x) >> 21;
    return (row << 6) + col;
}

/* scene_tile_render_near -- Render nearby scene tiles (3x3 grid around camera).
 * Converts camera world position (0x06063DF8) to tile grid coordinates,
 * then iterates a 3x3 neighborhood (clamped at grid edges 0..63).
 * For each tile, looks up layer A/B tile counts and renders via
 * course-specific renderers: course 2 uses 0x0602B328/0x0602AF3C,
 * others use 0x06029BF4/0x0602A834. After tiles, dispatches to
 * course-specific road renderer (0x06017814/0x06017CEC/0x06018166)
 * unless GAME_STATE_BIT has pause/menu flags (0x30000000). */
unsigned int scene_tile_render_near()
{
  short layer_b_count;
  int course_id_base;
  int tile_idx;
  unsigned int result;
  char *course_ptr = (char *)0x0607EAD8;               /* course select */
  char *camera_param = (char *)0x06089E96;              /* camera render param */

  *(int *)0x06063F54 = *(int *)(CAR_PTR_TARGET + 0x14); /* store car Y for depth sort */

  int layer_a_map = *(int *)(0x06062248 + *(int *)((int)(int)course_ptr << 3));
  int layer_b_map = *(int *)(0x06062248 + (*(int *)((int)(int)course_ptr << 1) + 1) << 2);
  int tile_count_a = *(int *)(0x06062260 + *(int *)((int)(int)course_ptr << 4));
  course_id_base = *(int *)((int)(int)course_ptr << 2);
  int tile_offset_a = *(int *)(0x06062260 + (course_id_base + 1) << 2);
  int tile_count_b = *(int *)(0x06062260 + (course_id_base + 2) << 2);
  int tile_offset_b = *(int *)(0x06062260 + (course_id_base + 3) << 2);

  /* Convert camera world pos to 64x64 tile grid coords */
  unsigned int grid_col = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;
  unsigned int grid_row = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;
  int center_tile = (grid_row << 6) + grid_col;

  /* Set up 3x3 neighborhood bounds, clamped at grid edges */
  int row_end = 0x40;                                   /* +1 row (64 tiles/row) */
  int col_start = -1;
  int col_end = 1;
  int row_start = -0x40;                                /* -1 row */
  if (grid_row == 0x3f) {
    row_end = 0;                                        /* at bottom edge: no row below */
  }
  else if (grid_row == 0) {
    row_start = 0;                                      /* at top edge: no row above */
  }
  if (grid_col == 0x3f) {
    col_end = 0;                                        /* at right edge */
  }
  else if (grid_col == 0) {
    col_start = 0;                                      /* at left edge */
  }

  /* Iterate 3x3 tile neighborhood */
  for (; row_start <= row_end; row_start = row_start + 0x40) {
    tile_idx = row_start + col_start + center_tile;
    int col;
    for (col = col_start; col <= col_end; col = col + 1) {
      layer_b_count = *(short *)((tile_idx << 1) + tile_count_b);
      /* Render layer A if tile has geometry */
      if (0 < *(short *)(tile_count_a + (tile_idx << 1))) {
        int mesh_base = *(int *)(0x06062230 + *(int *)((int)(int)course_ptr << 3)) +
                        *(int *)(tile_offset_a + (tile_idx << 2));
        if (*(int *)course_ptr == 2) {
          result = (*(int(*)())0x0602B328)(mesh_base, layer_a_map, (int)*(short *)camera_param);
        } else {
          result = (*(int(*)())0x06029BF4)(mesh_base, layer_a_map, (int)*(short *)camera_param);
        }
      }
      /* Render layer B if tile has geometry */
      if (0 < layer_b_count) {
        int mesh_base = *(int *)(0x06062230 + (*(int *)((int)(int)course_ptr << 1) + 1) << 2) +
                        *(int *)(tile_offset_b + (tile_idx << 2));
        if (*(int *)course_ptr == 2) {
          result = (*(int(*)())0x0602AF3C)(mesh_base, layer_b_map, (int)*(short *)camera_param, (int)layer_b_count);
        } else {
          result = (*(int(*)())0x0602A834)(mesh_base, layer_b_map, (int)*(short *)camera_param, (int)layer_b_count);
        }
      }
      tile_idx = tile_idx + 1;
    }
  }

  /* Dispatch to course-specific road/track renderer unless paused */
  if ((GAME_STATE_BIT & 0x30000000) == 0) {
    int course = *(int *)course_ptr;
    if (course == 0) {
      (*(int(*)())0x06017814)();                        /* course 0: beginner road */
    }
    else if (course == 1) {
      (*(int(*)())0x06017CEC)();                        /* course 1: advanced road */
    }
    else if (course == 2) {
      (*(int(*)())0x06018166)();                        /* course 2: expert road */
    }
    result = (*(int(*)())0x06022140)();                 /* final scene post-process */
    return result;
  }
  return result;
}

/* scene_border_tiles_render -- Render border/edge tiles of the scene grid.
 * Iterates a 5x5 grid centered on camera position, but only renders tiles
 * on the outer border (row/col == -2 or +2). Looks up tile indices from
 * course tile maps at 0x06062260, dispatches to course-specific renderers
 * (0x0602BDCC/0x0602A214 for layer A, 0x0602B9E0/0x0602ABB8 for layer B).
 * Course 2 uses alternate render paths. */
int FUN_06006a9c()
{
    char *course_id     = (char *)0x0607EAD8;   /* current course index */
    char *camera_data   = (char *)0x06089E44;   /* camera/view data base */
    char *render_budget = (char *)0x060620D4;   /* render budget ptr */

    int layer_a_map  = *(int *)(0x06062248 + *(int *)(0x0607EAD8 << 3));
    int layer_b_map  = *(int *)(0x06062248 + (*(int *)(0x0607EAD8 << 1) + 1) << 2);
    int tile_map_a   = *(int *)(0x06062260 + *(int *)(0x0607EAD8 << 4));
    int course_base  = *(int *)(0x0607EAD8 << 2);
    int tile_offs_a  = *(int *)(0x06062260 + (course_base + 1) << 2);
    int tile_map_b   = *(int *)(0x06062260 + (course_base + 2) << 2);
    course_base = (course_base + 3) << 2;
    int tile_offs_b  = *(int *)(0x06062260 + course_base);

    /* Convert camera world position to tile grid coordinates */
    unsigned int grid_x = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;
    unsigned int grid_z = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;

    /* Border iteration range: -2..+2 around camera tile, clamped to 0..63 */
    int row_start = -2;
    int col_start = -2;
    int row_end   = 2;
    int col_end   = 2;

    if (grid_z < 0x3e) {
        if (grid_z < 2) {
            row_start = -grid_z;
        }
    } else {
        row_end = 0x3f - grid_z;
    }
    if (grid_x < 0x3e) {
        if (grid_x < 2) {
            col_start = -grid_x;
        }
    } else {
        col_end = 0x3f - grid_x;
    }

    int result;
    int row, col;
    for (row = row_start << 6; col = col_start, row < row_end << 6; row = row + 0x40) {
        for (; col < col_end; col = col + 1) {
            result = row;
            /* Only render tiles on the border edges */
            if (((row == -0x80) || (row == DAT_06006c1e)) ||
                (result = col, col == -2) || (col == 2)) {

                int tile_idx = row + col + (grid_z << 6) + grid_x;
                short tile_a = *(short *)(tile_map_a + (tile_idx << 1));
                short tile_b = *(short *)((tile_idx << 1) + tile_map_b);

                /* Render layer A tile */
                if (0 < tile_a) {
                    result = *(int *)(0x06062230 + *(int *)((int)(int)course_id << 3)) +
                             *(int *)(tile_offs_a + (tile_idx << 2));
                    if ((unsigned int)0x640 <= (unsigned int)((int)tile_a + *(int *)render_budget)) {
                        tile_a = PTR_DAT_06006c20 - (short)*(int *)render_budget;
                    }
                    if (*(int *)course_id == 2) {
                        result = (*(int(*)())0x0602BDCC)(result, layer_a_map,
                                  *(short *)(camera_data + 0x52), (int)tile_a);
                    } else {
                        result = (*(int(*)())0x0602A214)(result, layer_a_map,
                                  *(short *)(camera_data + 0x52), (int)tile_a);
                    }
                }

                /* Render layer B tile */
                if (0 < tile_b) {
                    result = *(int *)(0x06062230 + (*(int *)((int)(int)course_id << 1) + 1) << 2) +
                             *(int *)(tile_offs_b + (tile_idx << 2));
                    if ((unsigned int)0x640 <= (unsigned int)((int)tile_b + *(int *)render_budget)) {
                        tile_b = DAT_06006cca - (short)*(int *)render_budget;
                    }
                    if (*(int *)course_id == 2) {
                        result = (*(int(*)())0x0602B9E0)(result, layer_b_map,
                                  *(short *)(camera_data + 0x52), (int)tile_b);
                    } else {
                        result = (*(int(*)())0x0602ABB8)(result, layer_b_map,
                                  *(short *)(camera_data + 0x52), (int)tile_b);
                    }
                }
            }
        }
    }
    return result;
}

/* scene_interior_tiles_render -- Render interior 11x11 scene tile grid.
 * Uses visibility map at 0x002F0000 indexed by frame rotation angle to
 * determine which tiles are visible. For each visible tile, dispatches
 * to course-specific renderers for both layer A and layer B.
 * Grid is 11x11 centered on camera, clamped to 0..63 tile range. */
int FUN_06006cdc()
{
    char *fog_distance  = (char *)0x06089E96;   /* fog/draw distance param */
    char *vis_map_base  = (char *)0x002F0000;   /* visibility map base */
    char *course_id     = (char *)0x0607EAD8;   /* current course index */
    char *render_budget = (char *)0x060620D4;   /* render budget ptr */

    short max_draw_dist     = DAT_06006da6;
    unsigned int draw_limit = (unsigned int)DAT_06006da6;

    /* Frame rotation angle -> visibility table row */
    unsigned int rot_angle = *(int *)0x06063EF0 + 0x800 & (unsigned int)0x0000FFFF;

    int layer_a_map = *(int *)(0x06062248 + *(int *)(0x0607EAD8 << 3));
    int layer_b_map = *(int *)(0x06062248 + (*(int *)(0x0607EAD8 << 1) + 1) << 2);
    int vis_row_stride = 0xf2;                  /* visibility row stride */
    int vis_table_base = (int)PTR_DAT_06006dac; /* visibility table offset */
    int tile_map_a  = *(int *)(0x06062260 + *(int *)(0x0607EAD8 << 4));
    int course_base = *(int *)(0x0607EAD8 << 2);
    int tile_offs_a = *(int *)(0x06062260 + (course_base + 1) << 2);
    int tile_map_b  = *(int *)(0x06062260 + (course_base + 2) << 2);
    course_base = (course_base + 3) << 2;
    int tile_offs_b = *(int *)(0x06062260 + course_base);

    /* Camera world position to tile grid coordinates */
    unsigned int grid_x = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;
    unsigned int grid_z = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;
    int grid_origin = (grid_z << 6) + grid_x;

    /* Iteration bounds: 11x11 grid, clamped to map edges */
    unsigned int col_start = 0;
    unsigned int row_start = 0;
    unsigned int col_end   = 0xb;
    unsigned int row_end   = 0xb;

    if (grid_z < 0x3b) {
        if (grid_z < 5) {
            row_start = 5 - grid_z;
        }
    } else {
        row_end = 0x45 - grid_z;
    }
    if (grid_x < 0x3b) {
        if (grid_x < 5) {
            col_start = 5 - grid_x;
        }
    } else {
        col_end = 0x45 - grid_x;
    }

    int result;
    unsigned int row, col;
    for (; row_start < row_end; row_start = row_start + 1) {
        for (col = col_start; col < col_end; col = col + 1) {
            /* Look up visibility from angle-indexed map */
            int vis_idx = (row_start * 0xb + col) << 1;
            short vis_tile = *(short *)(vis_map_base + vis_idx + vis_table_base +
                              (rot_angle >> 0xc) * vis_row_stride);

            if (vis_tile != 0) {
                int tile_idx = (vis_tile + grid_origin) << 1;
                short tile_a = *(short *)(tile_map_a + tile_idx);
                short tile_b = *(short *)(tile_idx + tile_map_b);

                /* Render layer A tile */
                if (0 < tile_a) {
                    result = *(int *)(tile_offs_a + (vis_tile + grid_origin) << 2) +
                             *(int *)(0x06062230 + *(int *)((int)(int)course_id << 3));
                    if (draw_limit <= (unsigned int)((int)tile_a + *(int *)render_budget)) {
                        tile_a = max_draw_dist - (short)*(int *)render_budget;
                    }
                    if (*(int *)course_id == 2) {
                        result = (*(int(*)())0x0602B9E0)(result, layer_a_map,
                                  *(short *)fog_distance, (int)tile_a);
                    } else {
                        result = (*(int(*)())0x0602ABB8)(result, layer_a_map,
                                  *(short *)fog_distance, (int)tile_a);
                    }
                }

                /* Render layer B tile */
                if (0 < tile_b) {
                    result = *(int *)(0x06062230 + (*(int *)((int)(int)course_id << 1) + 1) << 2) +
                             *(int *)(tile_offs_b + (vis_tile + grid_origin) << 2);
                    if (draw_limit <= (unsigned int)((int)tile_b + *(int *)render_budget)) {
                        tile_b = max_draw_dist - (short)*(int *)render_budget;
                    }
                    if (*(int *)course_id == 2) {
                        result = (*(int(*)())0x0602B9E0)(result, layer_b_map,
                                  *(short *)fog_distance, (int)tile_b);
                    } else {
                        result = (*(int(*)())0x0602ABB8)(result, layer_b_map,
                                  *(short *)fog_distance, (int)tile_b);
                    }
                }
            }
        }
    }
    return result;
}

/* vdp_scroll_setup -- Initialize VDP1 and VDP2 for in-game rendering.
 * Resets sprite count, sets VRAM allocation pointer, initializes VDP1,
 * selects TV mode 2, sets erase window, freezes FB state.
 * Then loads initial command list and sprite table data. */
void FUN_0600736c(void)
{
    *(int *)0x0606A4F4 = 0;
    *(int *)0x0606A4EC = (int)DAT_06007412;
    (*(int(*)())0x06039250)(0x06063F5C);
    (*(int(*)())0x0603931C)(0, 2);
    (*(int(*)())0x060393FC)(0, 0, 0, (int)DAT_06007416, (int)DAT_06007414);
    (*(int(*)())0x06038E54)(0x0000FFFF);
    (*(int(*)())0x06012E00)();
    (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)0x06063F5C, 0x002A0000, 0x3c0);
    if ((*(unsigned int *)0x0607EAB8 & 1) != 0) {
        (*(int(*)())0x0602761E)(*(int *)(0x06059FFC << 3) + *(int *)0x06063F5C + 0x300,
                                0x06059F78, 0x80);
    }
    (*(int(*)())0x0602766C)(*(int *)0x06063F5C, 0x0605A018, 0x60);
    VDP1_CMD_BASE_PTR = 3;
    *(short *)(*(int *)0x06063F5C + 0x60) = (short)0x00008000;
    (*(int(*)())0x0602382C)();
    (*(int(*)())0x06028654)(0x002A3457, 0x0606B178);
    (*(int(*)())0x06026CE0)();
}



/* vdp1_char_register -- Register a VDP1 character (sprite) command entry.
 * Writes VRAM offset, character size, and pattern into sorted command table
 * (0x06063F64). For types 0xD-0xF (scaled sprites), applies size transform
 * via 0x06034FE0. Type 10 records sky layer base offset. Advances VRAM
 * allocation by (width * height) / 2 bytes. */
void FUN_06007658(unsigned short param_1, unsigned short param_2, short param_3, int param_4)
{
  int *cmd_count = (int *)0x0606A4F4;      /* sprite command count */
  int *vram_off  = (int *)0x0606A4EC;       /* current VRAM write offset */
  char *cmd_tbl  = (char *)0x06063F64;      /* sprite command table base */
  unsigned short uVar4, uVar5, uVar6;

  if (param_1 == 10) {
    *(int *)0x06063F60 = *(int *)(0x0606A4EC << 3) + *(int *)0x06063F5C;
  }

  uVar5 = DAT_060076e2;
  uVar4 = param_2 & DAT_060076e2;
  *(short *)(0x060684EC + (unsigned int)(param_1 << 1)) = (short)*cmd_count;
  *(int *)(cmd_tbl + *((int *)cmd_count) * 8) = *vram_off;

  if (((param_1 == 0xd) || (param_1 == 0xe)) || (param_1 == 0xf)) {
    /* Scaled sprite: transform character size */
    uVar6 = DAT_0600777e & param_2;
    uVar5 = (*(int(*)())0x06034FE0)(param_2, param_2 & uVar5);
    *(unsigned short *)(cmd_tbl + *((int *)cmd_count) * 8 + 4) = uVar5 | uVar6;
    *(int *)0x0606A4F0 = *vram_off;
  } else {
    *(unsigned short *)(cmd_tbl + *((int *)cmd_count) * 8 + 4) = param_2;
  }

  *(short *)(cmd_tbl + *((int *)cmd_count) * 8 + 6) = param_3;
  (*(int(*)())0x06028654)(param_4, *((int *)vram_off) * 8 + *(int *)0x06063F5C);
  *cmd_count = *cmd_count + 1;
  *vram_off = *vram_off + ((int)((unsigned int)(param_2 >> 8 & 0x3f) * (unsigned int)uVar4) >> 1);
}

/* vdp1_char_register_ptr -- Register VDP1 character from descriptor pointer.
 * Like vdp1_char_register but reads type/size/pattern from param_1 array.
 * param_1[0]=type, param_1[1]=char_size, param_1[2]=pattern_base,
 * param_1[4..5]=VRAM address offset. For types 0xD-0xF applies scaled
 * sprite transform. Advances VRAM by (width * height) / 2 bytes. */
void FUN_06007790(unsigned short *param_1, short param_2, int param_3)
{
  int *cmd_count = (int *)0x0606A4F4;      /* sprite command count */
  int *vram_off  = (int *)0x0606A4EC;       /* current VRAM write offset */
  char *cmd_tbl  = (char *)0x06063F64;      /* sprite command table base */
  unsigned short uVar1, uVar5, uVar6;

  if (*param_1 == 10) {
    *(int *)0x06063F60 = *vram_off * 8 + *(int *)0x06063F5C;
  }

  uVar1 = param_1[1];
  *(short *)(0x060684EC + ((unsigned int)(*param_1) << 1)) = (short)*cmd_count;
  *(int *)(cmd_tbl + *cmd_count * 8) = *vram_off;
  uVar5 = *param_1;

  if (((uVar5 == 0xd) || (uVar5 == 0xe)) || (uVar5 == 0xf)) {
    /* Scaled sprite: transform character size */
    uVar6 = uVar1 & DAT_060078ca;
    uVar5 = (*(int(*)())0x06034FE0)();
    *(unsigned short *)(cmd_tbl + *cmd_count * 8 + 4) = uVar5 | uVar6;
    *(int *)0x0606A4F0 = *vram_off;
  } else {
    *(unsigned short *)(cmd_tbl + *cmd_count * 8 + 4) = uVar1;
  }

  *(unsigned short *)(cmd_tbl + *cmd_count * 8 + 6) = param_1[2] + (param_2 << 2);
  (*(int(*)())0x06028654)(*(int *)(param_1 + 4) + param_3, *vram_off * 8 + *(int *)0x06063F5C);
  *cmd_count = *cmd_count + 1;
  *vram_off = *vram_off + ((int)((unsigned int)(uVar1 >> 8 & 0x3f) * (unsigned int)(uVar1 & 0xff)) >> 1);
}

/* vdp1_render_flush -- Flush accumulated VDP1 commands to framebuffer.
 * Sorts pending commands (0x0602C494), copies VDP1 command table header
 * (0x0602766C), dispatches all commands via FUN_06007bcc, then waits for
 * VBL (0x060394C2). Writes end-of-list marker (0x8000) and resets counters.
 * Sets INPUT_STATE render-complete bits, DEMO_MODE_FLAG gate. */
void FUN_060078dc(void)
{
  int *render_count   = (int *)0x060620D0;  /* accumulated render commands */
  int *render_budget  = (int *)0x060620D4;  /* remaining budget this frame */
  int *frame_counter  = (int *)0x0605A008;  /* VDP1 frame index */
  char *sort_buf      = (char *)0x0606A4F8; /* sort key buffer */
  unsigned int budget = (unsigned int)DAT_060079ce;

  *render_budget = *render_budget - budget;

  if ((unsigned int)*render_count < budget) {
    /* Copy overflow commands to secondary buffer */
    (*(int(*)())0x06027630)(0x0608AC20 + (((unsigned int)*render_count & 0xffff) * 0x18 & 0xffff),
               0x0608E460, *render_budget * 0x18);
    (*(int(*)())0x0602761E)(sort_buf + *render_count * 2, sort_buf + PTR_DAT_060079d0,
               *render_budget * 2);
  }

  *render_count = *render_count + *render_budget;
  *render_budget = budget;

  /* Sort and prepare command list */
  (*(int(*)())0x0602C494)(*render_count, sort_buf);
  (*(int(*)())0x0602766C)(*(int *)0x06063F5C, 0x0605A018 + *(short *)(0x0605A016 << 5), 0x20);
  *(char **)0x060785FC = (char *)0x0606BDFC;
  *frame_counter = *frame_counter + 1;

  /* Dispatch all VDP1 draw commands */
  FUN_06007bcc();

  VBL_DISABLE_FLAG = 1;
  (*(int(*)())0x060394C2)();              /* wait for VBL sync */
  (*(int(*)())0x0602766C)(*(int *)0x06063F5C + 0x20, 0x0606BDFC, (*frame_counter + -1) << 5);

  /* Write end-of-list marker */
  *(short *)(*frame_counter * 32 + *(int *)0x06063F5C) = (short)0x00008000;

  INPUT_STATE = INPUT_STATE | (unsigned int)0x20000000 | 4;
  if (DEMO_MODE_FLAG == 0) {
    *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x08000000;
  }

  VBL_DISABLE_FLAG = 0;
  (*(int(*)())0x06026CE0)();              /* post-render cleanup */
  *render_count = 0;
  *frame_counter = 0;
  *(int *)0x0606BDF8 = VBLANK_OUT_COUNTER;
  *(int *)0x06059F44 = 0;
}

/* vdp1_shadow_polygon -- Generate car shadow polygon for VDP1.
 * Computes 4 screen-space vertices from car height (CAR_PTR_TARGET) and
 * sun angle. Uses fixed-point multiply (0x06027552) and sincos (0x06027358)
 * to project shadow corners onto ground plane. Vertices written to shadow
 * command buffer at 0x06078604. Color = 0xA3FF (shadow mesh). */
void FUN_06007a50(void)
{
  int (*fpmul)(int, int) = (int (*)(int, int))0x06027552;
  short (*fp2scr)(int) = (short (*)(int))0x0602754C;
  short *shadow = (short *)0x06078604;     /* shadow polygon vertex buffer */
  short sVar7, sVar9;
  int iVar6, iVar8;
  int local_24;         /* sin component */
  int auStack_20[2];    /* cos component */

  /* Clamp shadow height to car Y position */
  iVar8 = (int)DAT_06007a92;
  if (*(int *)(CAR_PTR_TARGET + (int)DAT_06007a94) <= iVar8) {
    iVar8 = *(int *)(CAR_PTR_TARGET + (int)DAT_06007a94);
  }
  iVar8 = fpmul(iVar8, 0x0000D1B7);        /* scale factor */

  /* Y offset: normal=0x34, alternate=0x24 */
  sVar9 = (*(int *)0x06085FF4 == '\0') ? 0x34 : 0x24;

  /* Get sin/cos of shadow angle */
  (*(int(*)())0x06027358)(DAT_06007a96 + iVar8, &local_24, auStack_20);

  /* Vertex A: top-left */
  iVar8 = fpmul(0x00970000, local_24);
  sVar7 = fp2scr(-iVar8);
  shadow[4] = sVar7 + 8;
  iVar8 = fpmul(0x00970000, auStack_20[0]);
  sVar7 = fp2scr(iVar8);
  shadow[5] = sVar7 + sVar9;

  /* Vertex B: top-right */
  iVar8 = fpmul(0x00020000, auStack_20[0]);
  iVar6 = fpmul(0x00900000, local_24);
  sVar7 = fp2scr(iVar8 - iVar6);
  shadow[6] = sVar7 + 8;
  iVar8 = fpmul(0x00020000, local_24);
  iVar6 = fpmul(0x00900000, auStack_20[0]);
  sVar7 = fp2scr(iVar8 + iVar6);
  shadow[7] = sVar7 + sVar9;

  /* Vertex C: bottom-right */
  iVar8 = fpmul(0x00890000, local_24);
  sVar7 = fp2scr(-iVar8);
  shadow[8] = sVar7 + 8;
  iVar8 = fpmul(0x00890000, auStack_20[0]);
  sVar7 = fp2scr(iVar8);
  shadow[9] = sVar7 + sVar9;

  /* Vertex D: bottom-left */
  iVar8 = fpmul(0xFFFE0000, auStack_20[0]);
  iVar6 = fpmul(0x00900000, local_24);
  sVar7 = fp2scr(iVar8 - iVar6);
  shadow[10] = sVar7 + 8;
  iVar8 = fpmul(0xFFFE0000, local_24);
  iVar6 = fpmul(0x00900000, auStack_20[0]);
  sVar7 = fp2scr(iVar8 + iVar6);
  shadow[11] = sVar7 + sVar9;

  shadow[3] = (short)0x0000A3FF;            /* shadow mesh color */

  /* Write shadow polygon to VDP1 command list */
  (*(int(*)())0x060280C4)(shadow, *(int *)0x060785FC);
  VDP1_CMD_BASE_PTR = VDP1_CMD_BASE_PTR + 1;
  *(int *)0x060785FC = *(int *)0x060785FC + 0x20;
}

/* vdp1_command_dispatch -- Iterate sorted render list and emit VDP1 draw commands.
 * Loops over render_count entries in sort buffer (0x0606A4F8), looks up each
 * command in the 24-byte command array (0x0608AC20). Type 9 uses scaled sprite
 * writer (0x060281B8), others use normal writer (0x060280F8). Advances VDP1
 * write pointer by 0x20 per command. After dispatch, optionally draws shadow
 * polygon (FUN_06007a50) if GAME_STATE_BIT has overlay bits set. */
void FUN_06007bcc(void)
{
  int *vdp1_write  = (int *)0x060785FC;    /* VDP1 command write pointer */
  char *cmd_array  = (char *)0x0608AC20;   /* 24-byte command descriptors */
  int *render_count = (int *)0x060620D0;   /* number of commands to dispatch */
  void (*cmd_write)(char *, int) = (void (*)(char *, int))0x060280F8;
  unsigned int i, idx;

  *(int *)0x06078620 = 0;

  /* Check if interlace mode is active */
  if ((*(unsigned short *)0x06063DA0 & 8) == 0) {
    *(int *)0x0607861C = 0;
  } else {
    *(int *)0x0607861C = 1;
  }

  for (i = 0; i < (unsigned int)*render_count; i++) {
    idx = (unsigned int)*(unsigned short *)(0x0606A4F8 + (i << 1));
    if (*(short *)(cmd_array + (idx * 0x18 & 0xffff) + 6) == 9) {
      /* Scaled sprite command */
      (*(int(*)())0x060281B8)(cmd_array + (idx * 0x18 & 0xffff), *vdp1_write, (int)0x00008000);
    } else {
      cmd_write(cmd_array + (idx * 0x18 & 0xffff), *vdp1_write);
    }
    *vdp1_write = *vdp1_write + 0x20;
  }

  VDP1_CMD_BASE_PTR = VDP1_CMD_BASE_PTR + *render_count;

  /* Draw shadow polygon overlay if game state requires it */
  if ((GAME_STATE_BIT & (unsigned int)0x20228000) != 0) {
    (*(int(*)())0x060333D8)();
    FUN_06007a50();
  }

  (*(int(*)())0x06011DC0)();                /* post-command processing */
  (*(int(*)())0x060171AC)();                /* frame finalize */
}

/* --- FUN_06006868 (L1 import from src/FUN_06006868.c) --- */

unsigned int FUN_06006868()
{

  short sVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int uVar5;

  int iVar6;

  int iVar7;

  int uVar8;

  int iVar9;

  unsigned int uVar10;

  int iVar11;

  unsigned int uVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int local_4c;

  int iStack_40;

  int iStack_28;

  int iStack_24;

  puVar2 = (char *)0x0607EAD8;

  *(int *)0x06063F54 = *(int *)(*(int *)0x0607E944 + 0x14);

  puVar3 = (char *)0x06089E96;

  uVar8 = *(int *)(0x06062248 + *(int *)((int)(int)puVar2 << 3));

  uVar5 = *(int *)(0x06062248 + (*(int *)((int)(int)puVar2 << 1) + 1) << 2);

  iVar4 = *(int *)(0x06062260 + *(int *)((int)(int)puVar2 << 4));

  iVar11 = *(int *)((int)(int)puVar2 << 2);

  iVar9 = *(int *)(0x06062260 + (iVar11 + 1) << 2);

  iVar6 = *(int *)(0x06062260 + (iVar11 + 2) << 2);

  iVar11 = *(int *)(0x06062260 + (iVar11 + 3) << 2);

  uVar10 = (unsigned int)(0x04000000 + *(int *)0x06063DF8) >> 0x15;

  uVar12 = (unsigned int)(0x04000000 + (-1 - *(int *)(0x06063DF8 + 8))) >> 0x15;

  iVar7 = (uVar12 << 6) + uVar10;

  iStack_28 = 0x40;

  iStack_24 = -1;

  iStack_40 = 1;

  local_4c = -0x40;

  if (uVar12 == 0x3f) {

    iStack_28 = 0;

  }

  else if (uVar12 == 0) {

    local_4c = 0;

  }

  if (uVar10 == 0x3f) {

    iStack_40 = 0;

  }

  else if (uVar10 == 0) {

    iStack_24 = 0;

  }

  for (; local_4c <= iStack_28; local_4c = local_4c + 0x40) {

    iVar14 = local_4c + iStack_24 + iVar7;

    for (iVar15 = iStack_24; iVar15 <= iStack_40; iVar15 = iVar15 + 1) {

      sVar1 = *(short *)((iVar14 << 1) + iVar6);

      if (0 < *(short *)(iVar4 + (iVar14 << 1))) {

        iVar13 = *(int *)(0x06062230 + *(int *)((int)(int)puVar2 << 3)) + *(int *)(iVar9 + (iVar14 << 2));

        if (*(int *)puVar2 == 2) {

          uVar10 = (*(int(*)())0x0602B328)(iVar13,uVar8,(int)*(short *)puVar3);

        }

        else {

          uVar10 = (*(int(*)())0x06029BF4)(iVar13,uVar8,(int)*(short *)puVar3);

        }

      }

      if (0 < sVar1) {

        iVar13 = *(int *)(0x06062230 + (*(int *)((int)(int)puVar2 << 1) + 1) << 2) +

                 *(int *)(iVar11 + (iVar14 << 2));

        if (*(int *)puVar2 == 2) {

          uVar10 = (*(int(*)())0x0602AF3C)(iVar13,uVar5,(int)*(short *)puVar3,(int)sVar1);

        }

        else {

          uVar10 = (*(int(*)())0x0602A834)(iVar13,uVar5,(int)*(short *)puVar3,(int)sVar1);

        }

      }

      iVar14 = iVar14 + 1;

    }

  }

  if ((*(unsigned int *)0x0607EBC4 & 0x30000000) == 0) {

    iVar4 = *(int *)puVar2;

    if (iVar4 == 0) {

      (*(int(*)())0x06017814)();

    }

    else if (iVar4 == 1) {

      (*(int(*)())0x06017CEC)();

    }

    else if (iVar4 == 2) {

      (*(int(*)())0x06018166)();

    }

    uVar10 = (*(int(*)())0x06022140)();

    return uVar10;

  }

  return uVar10;

}

/* FUN_06006F3C -- original binary (812 bytes) */
__asm__(
    ".section .text.FUN_06006F3C, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06006F3C\n"
    ".type _FUN_06006F3C, @function\n"
    "_FUN_06006F3C:\n"
    ".byte 0x2F, 0xE6, 0xE2, 0x01, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x2F, 0xA6, 0x2F, 0x96, 0x2F, 0x86\n"  /* 0x06006F3C */
    ".byte 0x4F, 0x22, 0xD8, 0x23, 0xD9, 0x23, 0xDA, 0x24, 0xDB, 0x24, 0xDD, 0x25, 0xDE, 0x25, 0xD4, 0x26\n"  /* 0x06006F4C */
    ".byte 0x63, 0x42, 0x73, 0x01, 0x24, 0x32, 0xD3, 0x25, 0x23, 0x22, 0xD0, 0x25, 0x60, 0x01, 0x60, 0x0D\n"  /* 0x06006F5C */
    ".byte 0x20, 0x08, 0x8D, 0x02, 0xEC, 0x00, 0xA1, 0x3D, 0x00, 0x09, 0xD3, 0x22, 0x23, 0xC2, 0xD4, 0x22\n"  /* 0x06006F6C */
    ".byte 0x60, 0x41, 0x60, 0x0D, 0x88, 0x02, 0x8B, 0x09, 0x60, 0xB2, 0x20, 0x08, 0x89, 0x66, 0x4A, 0x0B\n"  /* 0x06006F7C */
    ".byte 0x00, 0x09, 0xE3, 0x02, 0xD2, 0x1B, 0x22, 0x32, 0xA0, 0x60, 0x00, 0x09, 0xD6, 0x1B, 0xD5, 0x1C\n"  /* 0x06006F8C */
    ".byte 0x60, 0x41, 0x60, 0x0D, 0x88, 0x03, 0x8B, 0x12, 0x60, 0xB2, 0x20, 0x08, 0x89, 0x56, 0xD0, 0x19\n"  /* 0x06006F9C */
    ".byte 0xD3, 0x19, 0x60, 0x01, 0x60, 0x0D, 0xCB, 0x08, 0x23, 0x01, 0x60, 0x51, 0x60, 0x0D, 0xCB, 0x03\n"  /* 0x06006FAC */
    ".byte 0x4A, 0x0B, 0x26, 0x01, 0xE3, 0x03, 0xD2, 0x0F, 0x22, 0x32, 0xA0, 0x47, 0x00, 0x09, 0x62, 0x41\n"  /* 0x06006FBC */
    ".byte 0x62, 0x2D, 0x22, 0x28, 0x8B, 0x22, 0x4A, 0x0B, 0x00, 0x09, 0xA0, 0x3F, 0x2B, 0xC2, 0xFF, 0xFF\n"  /* 0x06006FCC */
    ".byte 0x06, 0x01, 0x48, 0x84, 0x06, 0x01, 0x48, 0x68, 0x06, 0x03, 0x89, 0xA6, 0x06, 0x06, 0x35, 0xC4\n"  /* 0x06006FDC */
    ".byte 0x06, 0x06, 0x35, 0xC0, 0x06, 0x05, 0xB6, 0xD8, 0x06, 0x07, 0x86, 0x4C, 0x06, 0x05, 0x9F, 0x54\n"  /* 0x06006FEC */
    ".byte 0x06, 0x05, 0xA0, 0x0C, 0x06, 0x06, 0x3F, 0x58, 0x06, 0x06, 0x35, 0xB4, 0x25, 0xD0, 0x00, 0x02\n"  /* 0x06006FFC */
    ".byte 0x06, 0x0A, 0x4C, 0x92, 0x06, 0x0A, 0x4C, 0x90, 0x25, 0xD0, 0x00, 0x00, 0x62, 0xD2, 0x72, 0x01\n"  /* 0x0600700C */
    ".byte 0x2D, 0x22, 0xD0, 0x34, 0x60, 0x02, 0x88, 0x01, 0x8B, 0x0A, 0xD2, 0x33, 0x63, 0xD2, 0x62, 0x22\n"  /* 0x0600701C */
    ".byte 0x72, 0xFF, 0x32, 0x37, 0x89, 0x04, 0x60, 0x51, 0x60, 0x0D, 0xCB, 0x02, 0x60, 0x0D, 0x26, 0x01\n"  /* 0x0600702C */
    ".byte 0xD3, 0x2D, 0x62, 0xD2, 0x63, 0x32, 0x33, 0x27, 0x89, 0x08, 0x60, 0xB2, 0x20, 0x08, 0x89, 0x04\n"  /* 0x0600703C */
    ".byte 0x4A, 0x0B, 0x00, 0x09, 0xE3, 0x01, 0xD2, 0x29, 0x22, 0x32, 0x2D, 0xC2, 0xD3, 0x28, 0xD1, 0x29\n"  /* 0x0600704C */
    ".byte 0x63, 0x32, 0x61, 0x12, 0x43, 0x09, 0x41, 0x01, 0x62, 0x33, 0x43, 0x08, 0x42, 0x08, 0x43, 0x08\n"  /* 0x0600705C */
    ".byte 0x42, 0x08, 0x42, 0x08, 0x33, 0x2C, 0x33, 0x1C, 0xD2, 0x23, 0x33, 0x2C, 0xD2, 0x23, 0x22, 0x32\n"  /* 0x0600706C */
    ".byte 0x61, 0xE2, 0xD2, 0x23, 0x21, 0x29, 0x21, 0x18, 0x89, 0x06, 0x96, 0x30, 0xD5, 0x1F, 0xD4, 0x21\n"  /* 0x0600707C */
    ".byte 0xD3, 0x21, 0x65, 0x52, 0x43, 0x0B, 0x64, 0x42, 0x60, 0xE2, 0xC8, 0x04, 0x89, 0x06, 0x96, 0x27\n"  /* 0x0600708C */
    ".byte 0xD5, 0x1E, 0xD4, 0x1F, 0xD3, 0x1C, 0x65, 0x52, 0x43, 0x0B, 0x64, 0x42, 0x60, 0xE2, 0xC8, 0x10\n"  /* 0x0600709C */
    ".byte 0x89, 0x05, 0xD6, 0x1C, 0xD5, 0x1C, 0x66, 0x62, 0x65, 0x52, 0x48, 0x0B, 0xE4, 0x04, 0x60, 0xE2\n"  /* 0x060070AC */
    ".byte 0xC8, 0x20, 0x89, 0x05, 0xD6, 0x19, 0xD5, 0x1A, 0x66, 0x62, 0x65, 0x52, 0x48, 0x0B, 0xE4, 0x08\n"  /* 0x060070BC */
    ".byte 0x60, 0xE2, 0xC8, 0x40, 0x89, 0x05, 0xD6, 0x17, 0xD5, 0x17, 0x66, 0x62, 0x65, 0x52, 0x48, 0x0B\n"  /* 0x060070CC */
    ".byte 0xE4, 0x10, 0x60, 0xE2, 0xC8, 0x80, 0x89, 0x30, 0xD6, 0x14, 0xA0, 0x29, 0x00, 0x09, 0x06, 0x40\n"  /* 0x060070DC */
    ".byte 0x0E, 0x00, 0xFF, 0xFF, 0x06, 0x06, 0x35, 0xB8, 0x06, 0x06, 0x35, 0xBC, 0x06, 0x06, 0x3F, 0x58\n"  /* 0x060070EC */
    ".byte 0x06, 0x05, 0x9F, 0x3C, 0x06, 0x05, 0x9F, 0x38, 0x06, 0x06, 0xB1, 0x78, 0x06, 0x05, 0x9F, 0x34\n"  /* 0x060070FC */
    ".byte 0x20, 0x00, 0x00, 0x00, 0x06, 0x06, 0x3F, 0x60, 0x06, 0x02, 0x76, 0x6C, 0x06, 0x06, 0x12, 0x9C\n"  /* 0x0600710C */
    ".byte 0x06, 0x06, 0x12, 0xB4, 0x06, 0x05, 0xB7, 0x00, 0x06, 0x05, 0xB6, 0xFC, 0x06, 0x05, 0xB7, 0x08\n"  /* 0x0600711C */
    ".byte 0x06, 0x05, 0xB7, 0x04, 0x06, 0x05, 0xB7, 0x10, 0x06, 0x05, 0xB7, 0x0C, 0x06, 0x05, 0xB7, 0x18\n"  /* 0x0600712C */
    ".byte 0x66, 0x62, 0xD5, 0x32, 0x65, 0x52, 0x48, 0x0B, 0xE4, 0x20, 0x63, 0xE2, 0xD2, 0x30, 0x23, 0x29\n"  /* 0x0600713C */
    ".byte 0x23, 0x38, 0x89, 0x05, 0xD6, 0x2F, 0xD5, 0x30, 0x66, 0x62, 0x65, 0x52, 0x49, 0x0B, 0xE4, 0x04\n"  /* 0x0600714C */
    ".byte 0x63, 0xE2, 0xD2, 0x2E, 0x23, 0x29, 0x23, 0x38, 0x89, 0x05, 0xD6, 0x2D, 0xD5, 0x2D, 0x66, 0x62\n"  /* 0x0600715C */
    ".byte 0x65, 0x52, 0x49, 0x0B, 0xE4, 0x08, 0x63, 0xE2, 0xD2, 0x2B, 0x23, 0x29, 0x23, 0x38, 0x89, 0x05\n"  /* 0x0600716C */
    ".byte 0xD6, 0x2A, 0xD5, 0x2B, 0x66, 0x62, 0x65, 0x52, 0x49, 0x0B, 0xE4, 0x10, 0x63, 0xE2, 0xD2, 0x29\n"  /* 0x0600717C */
    ".byte 0x23, 0x29, 0x23, 0x38, 0x89, 0x05, 0xD6, 0x28, 0xD5, 0x28, 0x66, 0x62, 0x65, 0x52, 0x49, 0x0B\n"  /* 0x0600718C */
    ".byte 0xE4, 0x20, 0x63, 0xE2, 0xD2, 0x26, 0x23, 0x29, 0x23, 0x38, 0x89, 0x02, 0xD3, 0x25, 0x43, 0x0B\n"  /* 0x0600719C */
    ".byte 0x00, 0x09, 0x62, 0xE2, 0xD3, 0x24, 0x22, 0x39, 0x22, 0x28, 0x89, 0x02, 0xD3, 0x23, 0x43, 0x0B\n"  /* 0x060071AC */
    ".byte 0x00, 0x09, 0x62, 0xE2, 0xD3, 0x22, 0x22, 0x39, 0x22, 0x28, 0x89, 0x02, 0xD3, 0x21, 0x43, 0x0B\n"  /* 0x060071BC */
    ".byte 0x00, 0x09, 0x62, 0xE2, 0xD3, 0x20, 0x22, 0x39, 0x22, 0x28, 0x89, 0x02, 0xD3, 0x1F, 0x43, 0x0B\n"  /* 0x060071CC */
    ".byte 0x00, 0x09, 0x62, 0xE2, 0xD3, 0x1E, 0x22, 0x39, 0x22, 0x28, 0x89, 0x02, 0xD3, 0x1D, 0x43, 0x0B\n"  /* 0x060071DC */
    ".byte 0x00, 0x09, 0x2E, 0xC2, 0xE2, 0x02, 0xD3, 0x1C, 0x23, 0x22, 0x4F, 0x26, 0x68, 0xF6, 0x69, 0xF6\n"  /* 0x060071EC */
    ".byte 0x6A, 0xF6, 0x6B, 0xF6, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x06, 0x05, 0xB7, 0x14\n"  /* 0x060071FC */
    ".byte 0x00, 0x01, 0x00, 0x00, 0x06, 0x05, 0xB6, 0xE0, 0x06, 0x05, 0xB6, 0xDC, 0x00, 0x02, 0x00, 0x00\n"  /* 0x0600720C */
    ".byte 0x06, 0x05, 0xB6, 0xE8, 0x06, 0x05, 0xB6, 0xE4, 0x00, 0x04, 0x00, 0x00, 0x06, 0x05, 0xB6, 0xF0\n"  /* 0x0600721C */
    ".byte 0x06, 0x05, 0xB6, 0xEC, 0x00, 0x08, 0x00, 0x00, 0x06, 0x05, 0xB6, 0xF8, 0x06, 0x05, 0xB6, 0xF4\n"  /* 0x0600722C */
    ".byte 0x80, 0x00, 0x00, 0x00, 0x06, 0x01, 0x49, 0xE0, 0x40, 0x00, 0x00, 0x00, 0x06, 0x01, 0x49, 0xCC\n"  /* 0x0600723C */
    ".byte 0x00, 0x10, 0x00, 0x00, 0x06, 0x01, 0x48, 0xA2, 0x04, 0x00, 0x00, 0x00, 0x06, 0x02, 0x0C, 0x3C\n"  /* 0x0600724C */
    ".byte 0x08, 0x00, 0x00, 0x00, 0x06, 0x03, 0x33, 0x54, 0x06, 0x05, 0x9F, 0x54\n"  /* 0x0600725C */
);


/* FUN_06007268 -- original binary (126 bytes) */
__asm__(
    ".section .text.FUN_06007268, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_06007268\n"
    ".type _FUN_06007268, @function\n"
    "_FUN_06007268:\n"
    ".byte 0x4F, 0x22, 0xD3, 0x15, 0xD2, 0x14, 0x63, 0x32, 0x73, 0x01, 0x22, 0x32, 0xE3, 0x03, 0xD2, 0x13\n"  /* 0x06007268 */
    ".byte 0x22, 0x32, 0xD3, 0x13, 0x43, 0x0B, 0x00, 0x09, 0xD2, 0x12, 0xD3, 0x13, 0xD1, 0x0E, 0x62, 0x22\n"  /* 0x06007278 */
    ".byte 0x61, 0x12, 0x32, 0x3C, 0x62, 0x20, 0x62, 0x2C, 0x31, 0x23, 0x89, 0x01, 0xA0, 0x0F, 0x00, 0x09\n"  /* 0x06007288 */
    ".byte 0xD5, 0x0E, 0x60, 0x52, 0x20, 0x08, 0x89, 0x0A, 0xD0, 0x0D, 0x60, 0x01, 0x60, 0x0D, 0xCB, 0x03\n"  /* 0x06007298 */
    ".byte 0x60, 0x0D, 0xD3, 0x0C, 0x23, 0x01, 0xE4, 0x00, 0xD3, 0x0B, 0x23, 0x42, 0x25, 0x42, 0xE2, 0x04\n"  /* 0x060072A8 */
    ".byte 0xD3, 0x02, 0x4F, 0x26, 0x00, 0x0B, 0x23, 0x22, 0x06, 0x05, 0x9F, 0x44, 0x06, 0x05, 0x9F, 0x54\n"  /* 0x060072B8 */
    ".byte 0x06, 0x00, 0x51, 0x98, 0x06, 0x05, 0xAD, 0x10, 0x06, 0x05, 0x9F, 0x58, 0x06, 0x06, 0x3F, 0x58\n"  /* 0x060072C8 */
    ".byte 0x06, 0x0A, 0x4C, 0x92, 0x25, 0xD0, 0x00, 0x02, 0x06, 0x06, 0x35, 0xC4, 0x2F, 0xF6\n"  /* 0x060072D8 */
);
