
// ===== _get_wide_winmain_command_line @ 1400c8834 =====

/* Library Function - Single Match
    _get_wide_winmain_command_line
   
   Library: Visual Studio 2019 Release */

ushort * _get_wide_winmain_command_line(void)

{
  bool bVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = &DAT_1400e86a0;
  bVar1 = false;
  if (DAT_1400e8db8 != (ushort *)0x0) {
    puVar3 = DAT_1400e8db8;
    bVar1 = false;
  }
  do {
    uVar2 = *puVar3;
    if (uVar2 < 0x21) {
      if (uVar2 == 0) {
        return puVar3;
      }
      if (!bVar1) {
        do {
          if (0x20 < uVar2) {
            return puVar3;
          }
          puVar3 = puVar3 + 1;
          uVar2 = *puVar3;
        } while (uVar2 != 0);
        return puVar3;
      }
    }
    if (uVar2 == 0x22) {
      bVar1 = !bVar1;
    }
    puVar3 = puVar3 + 1;
  } while( true );
}


