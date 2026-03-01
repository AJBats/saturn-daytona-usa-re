# DMA Trace — Test Results

Feature: E3 (Runtime DMA logging)
Commands: `dma_trace <path>`, `dma_trace_stop`

## Implementation

Hooks `StartDMATransfer()` in scu.inc. Logs level, source, dest, length, PC, cycle.

## Testing

### Boot (500 frames): PASS
```
240 DMA transfers logged
Most frequent pattern: L0 WRAM→VDP1_VRAM (sprite data uploads)
  L0 src=0x06080000 dst=0x05C20000 len=0x10000  (initial load)
  L0 src=0x060F0000 dst=0x05C00000 len=0x5520   (per-frame VDP1 cmd list)
  L0 src=0x060FC000 dst=0x05C0C000 len=0xA98    (per-frame VDP1 data)
```

### Menu (60 frames): 0 transfers
Expected — mode select menu uses CPU writes, not SCU DMA.

## Verdict: PASS
