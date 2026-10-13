# rebuild run/ for sniff.py: parent with its two checks NOPed (jne @0xe93, jz @0xfae) + the potion and its ADS
# prereq: 7z x -sns -oextracted GhostStream.wim
import os
src='extracted/GhostStream/'
os.makedirs('run/tmp', exist_ok=True)
d=bytearray(open(src+'GhostStream.exe','rb').read())
assert d[0xe93:0xe95]==b'\x75\x2b' and d[0xfae:0xfb4]==bytes.fromhex('0f8680000000')
d[0xe93:0xe95]=b'\x90'*2; d[0xfae:0xfb4]=b'\x90'*6
open('run/GhostStream.exe','wb').write(d)
open('run/PolyjuicePotion.txt','wb').write(open(src+'PolyjuicePotion.txt','rb').read())
open('run/PolyjuicePotion.txt:LordVoldemort','wb').write(open(src+'PolyjuicePotion.txt:LordVoldemort','rb').read())
print('run/ ready; python sniff.py prints the pipe key')
