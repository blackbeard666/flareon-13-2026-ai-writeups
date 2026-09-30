// ==== FUN_14002d9ae size=85

void FUN_14002d9ae(undefined1 *param_1,longlong *param_2)

{
  undefined1 uVar1;
  ushort *puVar2;
  longlong lVar3;
  
  lVar3 = 2;
  puVar2 = (ushort *)FUN_14002da6c(param_2,2);
  if (puVar2 == (ushort *)0x0 || lVar3 != 2) {
    *(undefined **)(param_1 + 8) = &DAT_1400eece0;
    *(undefined8 *)(param_1 + 0x10) = 3;
    uVar1 = 0xc;
  }
  else {
    *(ushort *)(param_1 + 2) = *puVar2 << 8 | *puVar2 >> 8;
    uVar1 = 0x1c;
  }
  *param_1 = uVar1;
  return;
}


// ==== FUN_14002f705 size=81

void FUN_14002f705(undefined1 *param_1,longlong *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  uint *puVar3;
  longlong lVar4;
  
  lVar4 = 4;
  puVar3 = (uint *)FUN_14002da6c(param_2,4);
  if (puVar3 == (uint *)0x0 || lVar4 != 4) {
    *(undefined **)(param_1 + 8) = &DAT_1400eece3;
    *(undefined8 *)(param_1 + 0x10) = 3;
    uVar2 = 0xc;
  }
  else {
    uVar1 = *puVar3;
    *(uint *)(param_1 + 4) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar2 = 0x1c;
  }
  *param_1 = uVar2;
  return;
}


