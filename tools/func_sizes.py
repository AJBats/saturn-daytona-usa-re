import re
import sys

funcs = []
with open(r'd:\Projects\SaturnReverseTest\build\aprog.s', 'r') as f:
    for line in f:
        line = line.strip()
        m = re.match(r'^(FUN_0603[0-3][0-9A-Fa-f]{3}):', line)
        if m:
            name = m.group(1)
            addr = int(name[4:], 16)
            funcs.append((addr, name))

funcs.sort()
funcs.append((0x06034036, 'FUN_06034036'))

for i in range(len(funcs)-1):
    addr, name = funcs[i]
    next_addr = funcs[i+1][0]
    size = next_addr - addr
    print(f'{name} 0x{addr:08X} {size}')
