import sys
script_content = open(sys.argv[1], 'r').read()
with open(sys.argv[2], 'w', newline=chr(10)) as f:
    f.write(script_content)
print('Written successfully')
