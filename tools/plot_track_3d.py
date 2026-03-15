#!/usr/bin/env python3
"""3D track visualization — interpret waypoint data as X, Y, Z + field4.

Usage:
    python tools/plot_track_3d.py [path_to_wram_high.bin]
"""

import struct
import sys
import os
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read_waypoints(data, offset=0x0C6000, stride=16, max_entries=2000):
    entries = []
    for i in range(max_entries):
        pos = offset + i * stride
        if pos + stride > len(data):
            break
        a, b, c, d = struct.unpack_from('>iiiI', data, pos)
        if a == 0 and b == 0 and c == 0 and d == 0:
            if pos + 2 * stride <= len(data):
                a2, b2, _, _ = struct.unpack_from('>iiiI', data, pos + stride)
                if a2 == 0 and b2 == 0:
                    break
        entries.append((a, b, c, d))
    return entries


def main():
    dump_path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        PROJECT, "build", "dumps", "wram_high_tt.bin"
    )

    with open(dump_path, "rb") as f:
        data = f.read()

    waypoints = read_waypoints(data)
    print(f"Waypoints: {len(waypoints)}")

    # Interpret as X, Z, Y (height), field4
    # OR as X, Y, Z, field4 — try both
    xs = np.array([w[0] for w in waypoints], dtype=float)
    f2 = np.array([w[1] for w in waypoints], dtype=float)
    f3 = np.array([w[2] for w in waypoints], dtype=float)
    f4 = np.array([w[3] for w in waypoints], dtype=float)

    # Print value range stats to help interpret
    print(f"\nField 1 (X?):  min={xs.min():.0f}  max={xs.max():.0f}  unique={len(set(xs))}")
    print(f"Field 2 (Z?):  min={f2.min():.0f}  max={f2.max():.0f}  unique={len(set(f2))}")
    print(f"Field 3 (Y/heading?): min={f3.min():.0f}  max={f3.max():.0f}  unique={len(set(f3))}")
    print(f"Field 4 (flags?): min={f4.min():.0f}  max={f4.max():.0f}  unique={len(set(f4))}")

    fig = plt.figure(figsize=(18, 8))

    # --- View 1: X, Z, Field3-as-height ---
    ax1 = fig.add_subplot(121, projection='3d')
    ax1.set_title("Interpretation A: Field3 = Height (Y)")
    ax1.plot(xs, f2, f3, 'b-', linewidth=0.5, alpha=0.5)
    sc1 = ax1.scatter(xs, f2, f3, c=np.arange(len(xs)), cmap='rainbow', s=5)
    ax1.set_xlabel("Field 1 (X)")
    ax1.set_ylabel("Field 2 (Z)")
    ax1.set_zlabel("Field 3 (Y?)")
    plt.colorbar(sc1, ax=ax1, label="Waypoint index", shrink=0.6)

    # --- View 2: X, Z, Field4-as-height ---
    ax2 = fig.add_subplot(122, projection='3d')
    ax2.set_title("Interpretation B: Field4 = Height (Y)")
    ax2.plot(xs, f2, f4, 'b-', linewidth=0.5, alpha=0.5)
    sc2 = ax2.scatter(xs, f2, f4, c=np.arange(len(xs)), cmap='rainbow', s=5)
    ax2.set_xlabel("Field 1 (X)")
    ax2.set_ylabel("Field 2 (Z)")
    ax2.set_zlabel("Field 4 (Y?)")
    plt.colorbar(sc2, ax=ax2, label="Waypoint index", shrink=0.6)

    plt.suptitle("Three Seven Speedway — 3D interpretations", fontsize=14)
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()
