# Investigation: Absolute Truth

Only verified facts go here. Each entry is user-confirmed.

---

1. At unified trace line 901,454 and 901,455, both free and padded retail are byte-identical.
2. Padded retail boots to attract mode.
3. Free does not boot to attract mode.
4. At trace line 932959, D312's literal pool read costs +7 cycles in free vs retail (mem_ts 19127 vs 19120) because the +4 code shift pushes its EA from 0x0600315C to 0x06003160, crossing a 16-byte cache line boundary — verified by EA arithmetic, raw mem_ts delta, and CCR=0x01 confirming cache enabled.
