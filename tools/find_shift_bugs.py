import re

with open('d:/Projects/SaturnReverseTest/reimpl/build/daytona.map', 'r') as f:
    for line in f:
        m = re.search(r'0x([0-9a-fA-F]+)\s+(sym_|loc_)([0-9a-fA-F]+)', line)
        if m:
            resolved_addr = int(m.group(1), 16)
            prefix = m.group(2)
            label_hex = m.group(3)
            label_addr = int(label_hex, 16)
            expected = label_addr + 4
            label_name = prefix + label_hex
            if resolved_addr != expected:
                delta = resolved_addr - label_addr
                print(f'BUG: {label_name}')
                print(f'  Resolved address: 0x{resolved_addr:08X}')
                print(f'  Label address:    0x{label_addr:08X}')
                print(f'  Expected (+4):    0x{expected:08X}')
                print(f'  Delta from label: {delta:+d} (should be +4)')
                print(f'  Delta from expected: {resolved_addr - expected:+d}')
