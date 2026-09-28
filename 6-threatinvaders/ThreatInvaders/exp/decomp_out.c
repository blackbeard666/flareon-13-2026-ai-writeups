
// ===== tls_callback_0 @ 1405d3f30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tls_callback_0(undefined8 param_1,int param_2)

{
  longlong lVar1;
  undefined **ppuVar2;
  
  if ((param_2 == 2) &&
     (lVar1 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)__tls_index * 8),
     *(char *)(lVar1 + 0x10) != '\x01')) {
    *(undefined1 *)(lVar1 + 0x10) = 1;
    ppuVar2 = &PTR_FUN_140680f40;
    do {
      if (*ppuVar2 != (undefined *)0x0) {
        (*(code *)PTR__guard_dispatch_icall_140680e30)();
      }
      ppuVar2 = ppuVar2 + 1;
    } while (ppuVar2 != (undefined **)&DAT_140680f50);
  }
  return;
}



// ===== tls_callback_1 @ 1405d40e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tls_callback_1(undefined8 param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined8 *puVar3;
  uint *_Memory;
  
  if ((param_2 == 3) || (param_2 == 0)) {
    puVar3 = (undefined8 *)
             (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)__tls_index * 8) + 0x20
             );
    _Memory = (uint *)*puVar3;
    if (_Memory != (uint *)0x0) {
      while( true ) {
        uVar1 = *_Memory;
        while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
          if (*(longlong *)(_Memory + (ulonglong)uVar1 * 2 + 4) != 0) {
            (*(code *)PTR__guard_dispatch_icall_140680e30)();
          }
        }
        puVar2 = *(uint **)(_Memory + 2);
        if (puVar2 == (uint *)0x0) break;
        free(_Memory);
        *puVar3 = puVar2;
        _Memory = puVar2;
      }
      *puVar3 = 0;
    }
  }
  return;
}



// ===== entry @ 1405d49a0 =====

void entry(void)

{
  FUN_1405d4fc0();
  FUN_1405d4820();
  return;
}


