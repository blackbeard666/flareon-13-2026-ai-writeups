// ==== FUN_14000f30a size=130

void FUN_14000f30a(undefined8 *param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_4;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_2;
  uVar3 = SUB168(auVar1 * auVar2,0);
  if (0x8000000000000000 - param_3 < uVar3 || SUB168(auVar1 * auVar2,8) != 0) {
    param_1[1] = 0;
LAB_14000f341:
    uVar4 = 1;
  }
  else {
    if (uVar3 == 0) {
      param_1[1] = 0;
      param_1[2] = param_3;
    }
    else {
      lVar5 = FUN_14000f38c(param_3,uVar3);
      if (lVar5 == 0) {
        param_1[1] = param_3;
        param_1[2] = uVar3;
        goto LAB_14000f341;
      }
      param_1[1] = param_2;
      param_1[2] = lVar5;
    }
    uVar4 = 0;
  }
  *param_1 = uVar4;
  return;
}


// ==== FUN_14000f38c size=36

void FUN_14000f38c(ulonglong param_1,longlong param_2)

{
  if (param_2 != 0) {
    FUN_140005715(param_2,param_1);
  }
  return;
}


// ==== FUN_14000f578 size=252

ulonglong FUN_14000f578(ulonglong *param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4,
                       ulonglong param_5)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  ulonglong uVar3;
  void *pvVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  bool bVar9;
  ulonglong local_40;
  ulonglong local_38;
  ulonglong local_30;
  ulonglong local_28;
  
  if (CARRY8(param_2,param_3)) {
    local_40 = 0;
  }
  else {
    uVar7 = *param_1;
    uVar8 = uVar7 * 2;
    if (uVar7 * 2 < param_2 + param_3) {
      uVar8 = param_2 + param_3;
    }
    uVar3 = (ulonglong)(param_5 == 1) * 4 + 4;
    if (uVar8 <= uVar3) {
      uVar8 = uVar3;
    }
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_5;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar8;
    uVar3 = SUB168(auVar1 * auVar2,0);
    bVar9 = SUB168(auVar1 * auVar2,8) != 0;
    uVar6 = 0x8000000000000000 - param_4;
    pvVar4 = (void *)CONCAT71((int7)(uVar6 >> 8),uVar6 < uVar3 || bVar9);
    if (uVar6 < uVar3 || bVar9) {
      puVar5 = &local_40;
      uVar3 = 0;
    }
    else {
      if (uVar7 == 0) {
        puVar5 = &local_38;
        uVar7 = 0;
      }
      else {
        pvVar4 = (void *)param_1[1];
        uVar7 = uVar7 * param_5;
        puVar5 = &local_28;
        local_38 = param_4;
      }
      *puVar5 = uVar7;
      if ((local_38 == 0) || (local_28 == 0)) {
        pvVar4 = (void *)FUN_14000f38c(param_4,uVar3);
      }
      else {
        pvVar4 = FUN_140005793(pvVar4,local_28,param_4,uVar3);
      }
      if (pvVar4 != (void *)0x0) {
        param_1[1] = (ulonglong)pvVar4;
        *param_1 = uVar8;
        return 0x8000000000000001;
      }
      puVar5 = &local_30;
      local_40 = param_4;
    }
    *puVar5 = uVar3;
  }
  return local_40;
}


// ==== FUN_1400054ce size=199

void FUN_1400054ce(undefined8 *param_1,ulonglong param_2,ulonglong param_3)

{
  longlong lVar1;
  code *pcVar2;
  ulonglong uVar3;
  void *local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  if (param_3 < 0xf) {
    uVar3 = 4;
    if (3 < param_3) {
      uVar3 = (ulonglong)((uint)param_3 & 8) + 8;
    }
  }
  else {
    if (param_3 >> 0x3d != 0) {
      FUN_1400c3fe0();
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    uVar3 = (param_3 << 3) / 7 - 1;
    lVar1 = 0x3f;
    if (uVar3 != 0) {
      for (; uVar3 >> lVar1 == 0; lVar1 = lVar1 + -1) {
      }
    }
    uVar3 = (0xffffffffffffffffU >> (~(byte)lVar1 & 0x3f)) + 1;
  }
  FUN_14004534c((longlong *)&local_48,param_2,uVar3);
  if (local_48 == (void *)0x0) {
    param_1[1] = local_40;
    param_1[2] = local_38;
    *param_1 = 0;
  }
  else {
    memset(local_48,(int)CONCAT71((int7)(param_2 >> 8),0xff),local_40 + 0x11);
    *param_1 = local_48;
    param_1[1] = local_40;
    param_1[2] = local_38;
    param_1[3] = local_30;
  }
  return;
}


// ==== FUN_1400053ab size=83

void FUN_1400053ab(longlong *param_1,uint param_2,longlong param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)param_2;
  while( true ) {
    if ((longlong *)*param_1 == (longlong *)0x0) break;
    uVar3 = CONCAT71((int7)(uVar3 >> 8),(char)uVar3 + '\x01');
    FUN_1400053ab((longlong *)*param_1,(uint)uVar3,param_3);
    param_1 = (longlong *)param_1[1];
  }
  uVar2 = (ulonglong)*(byte *)(param_1 + 1);
  if (uVar2 < *(ulonglong *)(param_3 + 0x10)) {
    *(char *)(*(longlong *)(param_3 + 8) + uVar2) = (char)uVar3;
    return;
  }
  FUN_1400c3d29(uVar2,*(ulonglong *)(param_3 + 0x10),&DAT_1400c91a0);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ==== FUN_140005fa0 size=376

void FUN_140005fa0(ulonglong *param_1,ushort *param_2,ulonglong param_3)

{
  code *pcVar1;
  byte bVar2;
  undefined8 uVar3;
  ushort *puVar4;
  byte bVar5;
  ulonglong uVar6;
  ulonglong local_50;
  ulonglong uStack_48;
  ulonglong local_40;
  undefined1 local_31;
  undefined8 local_30;
  
  local_30 = 0xfffffffffffffffe;
  if ((param_3 & 1) == 0) {
    bVar5 = (byte)*param_2;
    if (bVar5 != 0) {
      bVar2 = 0;
      uVar6 = 0;
      puVar4 = param_2;
      do {
        puVar4 = (ushort *)((longlong)puVar4 + 1);
        if ((char)bVar5 < '\0') {
          if (SBORROW1('\0',bVar5)) {
            uVar6 = uVar6 + *puVar4;
            puVar4 = (ushort *)((longlong)puVar4 + (ulonglong)*puVar4 + 2);
          }
          else {
            bVar2 = bVar2 | uVar6 == 0;
            puVar4 = (ushort *)
                     ((longlong)puVar4 +
                     (ulonglong)((byte)((bVar5 & 2) << 5 | bVar5 << 7) >> 5) +
                     (ulonglong)(bVar5 >> 2 & 2) + (ulonglong)(bVar5 >> 1 & 2));
          }
        }
        else {
          uVar6 = uVar6 + bVar5;
          puVar4 = (ushort *)((longlong)puVar4 + (ulonglong)bVar5);
        }
        bVar5 = (byte)*puVar4;
      } while (bVar5 != 0);
      if ((bool)(bVar2 & uVar6 < 0x10)) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 * 2;
        if ((longlong)uVar6 < 0) {
          FUN_1400c39e0();
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
      }
      goto LAB_140006080;
    }
  }
  else {
    uVar6 = param_3 >> 1;
LAB_140006080:
    if (uVar6 != 0) {
      uStack_48 = FUN_14006f3a0(0,uVar6);
      if (uStack_48 == 0) {
        FUN_1400c389e(1,uVar6);
                    /* WARNING: Does not return */
        pcVar1 = (code *)invalidInstructionException();
        (*pcVar1)();
      }
      goto LAB_1400060ab;
    }
  }
  uStack_48 = 1;
  uVar6 = 0;
LAB_1400060ab:
  local_40 = 0;
  local_50 = uVar6;
  uVar3 = FUN_140006460(&local_50,0x1400c9290,param_2,param_3);
  if ((char)uVar3 == '\0') {
    param_1[2] = local_40;
    *param_1 = local_50;
    param_1[1] = uStack_48;
    return;
  }
  FUN_1400c3e10("a formatting trait implementation returned an error when the underlying stream did not"
                ,0x56,&local_31,&DAT_1400c91c0,&PTR_s__rustc_ac68faa20c58cbccd01ee7208_1400c9310);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


