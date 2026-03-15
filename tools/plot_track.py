#!/usr/bin/env python3
"""Visualize track data from a WRAM High dump.

Reads the surface/waypoint table and segment distance table from a
WRAM High binary dump and plots a top-down 2D track map.

Usage:
    python tools/plot_track.py [path_to_wram_high.bin]
    Default: build/dumps/wram_high_tt.bin
"""

import struct
import sys
import os
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
from matplotlib.collections import LineCollection

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read_waypoints(data, offset=0x0C6000, stride=16, max_entries=2000):
    """Read X, Z, heading, field4 from the surface/waypoint table."""
    entries = []
    for i in range(max_entries):
        pos = offset + i * stride
        if pos + stride > len(data):
            break
        x, z, h, f4 = struct.unpack_from('>iiiI', data, pos)
        # Stop at a large block of zeros
        if x == 0 and z == 0 and h == 0 and f4 == 0:
            # Check next entry too (allow single zero entries)
            if pos + 2 * stride <= len(data):
                x2, z2, _, _ = struct.unpack_from('>iiiI', data, pos + stride)
                if x2 == 0 and z2 == 0:
                    break
        entries.append((x, z, h, f4))
    return entries


def read_segment_distances(data, offset=0x0D5840, max_entries=500):
    """Read the segment distance table (4-byte entries)."""
    entries = []
    for i in range(max_entries):
        pos = offset + i * 4
        if pos + 4 > len(data):
            break
        val = struct.unpack_from('>I', data, pos)[0]
        if val == 0 and i > 0:
            break
        entries.append(val)
    return entries


def compute_heading_change(waypoints):
    """Compute per-waypoint heading delta (for curve detection)."""
    deltas = [0]
    for i in range(1, len(waypoints)):
        dh = waypoints[i][2] - waypoints[i - 1][2]
        # Wrap to signed
        if dh > 0x7FFFFFFF:
            dh -= 0x100000000
        if dh < -0x80000000:
            dh += 0x100000000
        deltas.append(dh)
    return deltas


def main():
    dump_path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        PROJECT, "build", "dumps", "wram_high_tt.bin"
    )

    if not os.path.exists(dump_path):
        print(f"File not found: {dump_path}")
        sys.exit(1)

    with open(dump_path, "rb") as f:
        data = f.read()

    print(f"Loaded {len(data)} bytes from {dump_path}")

    waypoints = read_waypoints(data)
    distances = read_segment_distances(data)
    heading_deltas = compute_heading_change(waypoints)

    print(f"Waypoints: {len(waypoints)}")
    print(f"Segment distances: {len(distances)}")

    # Extract arrays
    xs = np.array([w[0] for w in waypoints], dtype=float)
    zs = np.array([w[1] for w in waypoints], dtype=float)
    headings = np.array([w[2] for w in waypoints], dtype=float)
    field4 = np.array([w[3] for w in waypoints], dtype=float)
    hdeltas = np.array(heading_deltas, dtype=float)

    # Classify: straight (heading delta == 0) vs curve
    is_curve = np.abs(hdeltas) > 0

    # --- Plot 1: Top-down track with heading-change coloring ---
    fig, axes = plt.subplots(1, 2, figsize=(16, 8))

    ax1 = axes[0]
    ax1.set_title("Track Centerline — Colored by Heading Change")
    ax1.set_xlabel("X (world units)")
    ax1.set_ylabel("Z (world units)")
    ax1.set_aspect("equal")

    # Build line segments colored by heading delta magnitude
    points = np.column_stack([xs, zs])
    segments = np.array([[points[i], points[i + 1]] for i in range(len(points) - 1)])

    # Color by absolute heading change (log scale for visibility)
    abs_hd = np.abs(hdeltas[1:])
    # Normalize: 0 = straight (blue), max = sharpest curve (red)
    max_hd = abs_hd.max() if abs_hd.max() > 0 else 1
    norm_hd = abs_hd / max_hd

    lc = LineCollection(segments, cmap="coolwarm", linewidths=2)
    lc.set_array(norm_hd)
    ax1.add_collection(lc)
    ax1.autoscale()
    plt.colorbar(lc, ax=ax1, label="Heading change (normalized)")

    # Mark start point
    ax1.plot(xs[0], zs[0], "go", markersize=10, label="Start", zorder=5)
    # Mark curve entries
    curve_idx = np.where(is_curve)[0]
    if len(curve_idx) > 0:
        ax1.scatter(
            xs[curve_idx], zs[curve_idx],
            c="red", s=15, zorder=4, label=f"Curve points ({len(curve_idx)})"
        )
    ax1.legend()

    # --- Plot 2: Field 4 values ---
    ax2 = axes[1]
    ax2.set_title("Track Centerline — Colored by Field 4")
    ax2.set_xlabel("X (world units)")
    ax2.set_ylabel("Z (world units)")
    ax2.set_aspect("equal")

    # Color waypoints by field4 value
    f4_unique = sorted(set(int(f) for f in field4))
    print(f"Field 4 unique values: {len(f4_unique)}")
    if len(f4_unique) <= 20:
        for v in f4_unique:
            print(f"  0x{v:08X} ({v})")

    sc = ax2.scatter(xs, zs, c=field4, cmap="tab10", s=8, zorder=3)
    plt.colorbar(sc, ax=ax2, label="Field 4 value")
    ax2.plot(xs, zs, "k-", alpha=0.2, linewidth=0.5)  # faint centerline
    ax2.plot(xs[0], zs[0], "go", markersize=10, zorder=5)

    # Add segment index annotations every 50 waypoints
    for i in range(0, len(xs), 50):
        ax2.annotate(
            str(i), (xs[i], zs[i]),
            fontsize=7, color="black",
            xytext=(5, 5), textcoords="offset points"
        )

    plt.suptitle(
        f"Three Seven Speedway — {len(waypoints)} waypoints, "
        f"{len(distances)} segment markers",
        fontsize=14,
    )
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()
