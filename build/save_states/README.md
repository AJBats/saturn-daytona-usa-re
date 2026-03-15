# Save States Catalog

Reference for all save states used in reverse engineering investigations.
Each entry documents the game state, constraints, and recommended use cases.

Renaming `.mc0` files is fine when loading by explicit path (e.g., via MCP
`load_state`). The hash in the filename is only used by Mednafen's auto-discovery.

## daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0

- **Mode**: Race (40 cars, 1P)
- **Course**: Three Seven Speedway (Beginner)
- **Speed**: Rolling start (~300 km/h)
- **Position**: 40/40
- **Transmission**: AUTO
- **Build**: Vanilla (unmodified retail binary)
- **Location**: Start/finish line, race start after 3-2-1-GO
- **Known constraints**:
  TO BE DETERMINED ALONG WITH HUMAN USER.
- **Best for**: Multi-car observations (39 AI cars active), collision functions,
  per-car iteration studies, opponent rendering loops
- **Avoid for**: Clean throttle/brake speed tests (cars everywhere), manual
  transmission studies

## daytona_manual_trans.8180a74b2162ad4393a9630de58615e3.mc0

- **Mode**: Race (40 cars, 1P)
- **Course**: Three Seven Speedway (Beginner)
- **Speed**: Rolling start (~300 km/h)
- **Position**: 40/40
- **Transmission**: MANUAL
- **Build**: Vanilla (unmodified retail binary)
- **Location**: Start/finish line, race start after 3-2-1-GO
- **Known constraints**:
  TO BE DETERMINED ALONG WITH HUMAN USER.
- **Best for**: Gear shift logic, manual transmission mechanics, RPM/speed
  relationship studies
- **Avoid for**: Clean physics tests where gear shifts add noise (use auto instead)
