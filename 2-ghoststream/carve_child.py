# carve the dropped child (Partner_CTF.exe) out of the parent's PE resources -> child.exe
# prereq: 7z x -sns -oextracted GhostStream.wim
import pefile
pe=pefile.PE('extracted/GhostStream/GhostStream.exe')
for e in pe.DIRECTORY_ENTRY_RESOURCE.entries:
  for n in e.directory.entries:
    for l in n.directory.entries:
      off=pe.get_offset_from_rva(l.data.struct.OffsetToData); sz=l.data.struct.Size
      if pe.__data__[off:off+2]==b'MZ':
        open('child.exe','wb').write(pe.__data__[off:off+sz]); print('child.exe', hex(off), sz)
