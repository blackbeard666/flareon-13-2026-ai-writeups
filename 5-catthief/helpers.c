// ==== FUN_1400013cf size=59

undefined8 * FUN_1400013cf(byte *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong unaff_GS_OFFSET;
  
  lVar2 = *(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)_tls_index * 8);
  puVar1 = (undefined8 *)(lVar2 + 0x28);
  if (*(char *)(lVar2 + 0x38) == '\0') {
    FUN_1400c60b3(puVar1,param_1);
  }
  return puVar1;
}


// ==== FUN_1400016b6 size=262

ulonglong FUN_1400016b6(ulonglong param_1,ulonglong param_2,byte param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar3 = param_2 ^ 0x646f72616e646f6d;
  uVar2 = param_2 ^ 0x7465646279746573 ^ ((ulonglong)param_3 | 0x100000000000000);
  uVar4 = (param_1 ^ 0x736f6d6570736575) + uVar3;
  uVar1 = (param_1 ^ 0x6c7967656e657261) + uVar2;
  uVar3 = (uVar3 << 0xd | uVar3 >> 0x33) ^ uVar4;
  uVar2 = (uVar2 << 0x10 | uVar2 >> 0x30) ^ uVar1;
  uVar1 = uVar1 + uVar3;
  uVar4 = (uVar4 << 0x20 | uVar4 >> 0x20) + uVar2;
  uVar3 = (uVar3 << 0x11 | uVar3 >> 0x2f) ^ uVar1;
  uVar2 = (uVar2 << 0x15 | uVar2 >> 0x2b) ^ uVar4;
  uVar4 = (uVar4 ^ ((ulonglong)param_3 | 0x100000000000000)) + uVar3;
  uVar1 = ((uVar1 << 0x20 | uVar1 >> 0x20) ^ 0xff) + uVar2;
  uVar3 = (uVar3 << 0xd | uVar3 >> 0x33) ^ uVar4;
  uVar2 = (uVar2 << 0x10 | uVar2 >> 0x30) ^ uVar1;
  uVar1 = uVar1 + uVar3;
  uVar4 = (uVar4 << 0x20 | uVar4 >> 0x20) + uVar2;
  uVar3 = (uVar3 << 0x11 | uVar3 >> 0x2f) ^ uVar1;
  uVar2 = (uVar2 << 0x15 | uVar2 >> 0x2b) ^ uVar4;
  uVar4 = uVar4 + uVar3;
  uVar1 = (uVar1 << 0x20 | uVar1 >> 0x20) + uVar2;
  uVar3 = (uVar3 << 0xd | uVar3 >> 0x33) ^ uVar4;
  uVar2 = (uVar2 << 0x10 | uVar2 >> 0x30) ^ uVar1;
  uVar1 = uVar1 + uVar3;
  uVar4 = (uVar4 << 0x20 | uVar4 >> 0x20) + uVar2;
  uVar3 = (uVar3 << 0x11 | uVar3 >> 0x2f) ^ uVar1;
  uVar2 = (uVar2 << 0x15 | uVar2 >> 0x2b) ^ uVar4;
  uVar1 = (uVar1 << 0x20 | uVar1 >> 0x20) + uVar2;
  uVar3 = (uVar3 << 0xd | uVar3 >> 0x33) ^ uVar4 + uVar3;
  uVar2 = (uVar2 << 0x10 | uVar2 >> 0x30) ^ uVar1;
  uVar1 = uVar1 + uVar3;
  return (uVar1 << 0x20 | uVar1 >> 0x20) ^ (uVar3 << 0x11 | uVar3 >> 0x2f) ^
         (uVar2 << 0x15 | uVar2 >> 0x2b) ^ uVar1;
}


// ==== FUN_14006317e size=52

longlong FUN_14006317e(undefined *param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  
  plVar3 = (longlong *)(*(code *)param_1)(0);
  if (plVar3 != (longlong *)0x0) {
    lVar1 = *plVar3;
    *plVar3 = lVar1 + 1;
    return lVar1;
  }
  FUN_1400c6860(&PTR_s__rustc_ac68faa20c58cbccd01ee7208_1400ee918);
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


