
// ===== FUN_140009070 @ 140009070 off=0x9070 =====

int FUN_140009070(longlong param_1,uint param_2)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_24 = 0x2437;
  for (uStack_28 = 0; uStack_28 < param_2; uStack_28 = uStack_28 + 1) {
    uStack_24 = uStack_24 * 0x81 + (int)*(char *)(param_1 + (ulonglong)uStack_28);
  }
  return uStack_24;
}



// ===== FUN_1400095b8 @ 1400095b8 off=0x95b8 =====

undefined4 FUN_1400095b8(undefined8 *param_1)

{
  *(uint *)*param_1 =
       *(int *)*param_1 * ((int)*(undefined8 *)param_1[1] + 0x9f8da34dU ^ 0xde4bed20) +
       ((int)*(undefined8 *)param_1[1] + 0xde4bdd19U ^ 0xde4bed20);
  return *(undefined4 *)*param_1;
}



// ===== FUN_140009114 @ 140009114 off=0x9114 =====

byte * FUN_140009114(byte *param_1,byte *param_2,uint *param_3)

{
  byte bVar1;
  byte *pbStackX_8;
  byte bStack_17;
  uint uStack_14;
  
  if (param_1 < param_2) {
    bVar1 = *param_1;
    pbStackX_8 = param_1 + 1;
    if ((bVar1 & 0x80) == 0) {
      *param_3 = (uint)bVar1;
    }
    else {
      bVar1 = bVar1 & 0x7f;
      if ((bVar1 < 5) && (pbStackX_8 + bVar1 <= param_2)) {
        uStack_14 = 0;
        for (bStack_17 = 0; bStack_17 < bVar1; bStack_17 = bStack_17 + 1) {
          uStack_14 = uStack_14 << 8 | (uint)*pbStackX_8;
          pbStackX_8 = pbStackX_8 + 1;
        }
        *param_3 = uStack_14;
      }
      else {
        pbStackX_8 = (byte *)0x0;
      }
    }
  }
  else {
    pbStackX_8 = (byte *)0x0;
  }
  return pbStackX_8;
}



// ===== FUN_14000aa44 @ 14000aa44 off=0xaa44 =====

int FUN_14000aa44(byte *param_1,byte *param_2,longlong param_3)

{
  longlong lStackX_18;
  byte *pbStack_28;
  byte *pbStack_20;
  
  lStackX_18 = param_3;
  pbStack_28 = param_1;
  pbStack_20 = param_2;
  while( true ) {
    if (lStackX_18 == 0) {
      return 0;
    }
    if (*pbStack_28 != *pbStack_20) break;
    pbStack_28 = pbStack_28 + 1;
    pbStack_20 = pbStack_20 + 1;
    lStackX_18 = lStackX_18 + -1;
  }
  return (uint)*pbStack_28 - (uint)*pbStack_20;
}


