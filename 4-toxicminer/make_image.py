# map ToxicMiner.exe at its preferred base -> image.bin (input for harness.c)
# Defender-safe (sample never touches disk):
#   7z e -so -pflare 4-ToxicMiner.7z ToxicMiner.exe | python make_image.py -
import sys, pefile
src=sys.argv[1] if len(sys.argv)>1 else 'ToxicMiner.exe'
raw=sys.stdin.buffer.read() if src=='-' else open(src,'rb').read()
img=pefile.PE(data=raw).get_memory_mapped_image(ImageBase=0x140000000)
open('image.bin','wb').write(img); print('image.bin', len(img))
