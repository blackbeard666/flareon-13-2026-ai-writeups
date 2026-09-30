// funcs touching DAT_1400e9268/DAT_1400e9228: 9
  FUN_140001040 @ 140001040 size~59
  FUN_140001560 @ 140001560 size~1126
  FUN_1400019d0 @ 1400019d0 size~1584
  FUN_140002000 @ 140002000 size~1558
  FUN_140003380 @ 140003380 size~481
  FUN_140003b20 @ 140003b20 size~9414
  FUN_140006270 @ 140006270 size~203
  FUN_1400026b0 @ 1400026b0 size~977
  FUN_140002a90 @ 140002a90 size~2278

// ===== FUN_140001040 @ 140001040 =====

void FUN_140001040(void)

{
  int iVar1;
  
  DAT_1400e9268 = &PTR_PTR_1400e7930;
  FUN_140020970();
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 7);
  FUN_1400a1ff0();
  return;
}



// ===== FUN_140001560 @ 140001560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_140001560(longlong param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 (*pauVar8) [32];
  int iVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 (*pauVar13) [32];
  int iVar14;
  uint uVar15;
  uint uVar16;
  undefined1 (*pauVar17) [32];
  char *pcVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  int iVar22;
  undefined1 auStack_98 [32];
  uint local_78;
  longlong local_70;
  longlong local_68;
  undefined1 (*local_50) [32];
  undefined1 (*pauStack_48) [32];
  undefined1 (*local_40) [32];
  ulonglong local_38;
  
  local_38 = DAT_1400e2040 ^ (ulonglong)auStack_98;
  uVar10 = (**(code **)*DAT_1400e9268)(DAT_1400e9268,param_1,DAT_1400e9228);
  FUN_14003b8a0();
  uVar19 = 0;
  local_78 = 0x36c;
  uVar20 = uVar19;
  do {
    local_78 = local_78 ^ (uint)uVar20;
    uVar15 = (uint)uVar20 + 1;
    uVar20 = (ulonglong)uVar15;
  } while ((int)uVar15 < 2);
  lVar11 = (**(code **)(*DAT_1400e9268 + 8))(DAT_1400e9268,param_1,uVar10,DAT_1400e9228);
  FUN_140020730();
  local_78 = 0x262;
  uVar20 = uVar19;
  do {
    local_78 = local_78 ^ (uint)uVar20;
    uVar15 = (uint)uVar20 + 1;
    uVar20 = (ulonglong)uVar15;
  } while ((int)uVar15 < 6);
  lVar12 = (**(code **)(*DAT_1400e9268 + 0x18))(DAT_1400e9268,param_1,lVar11);
  local_78 = 0x187;
  uVar20 = uVar19;
  do {
    local_78 = local_78 ^ (uint)uVar20;
    uVar15 = (uint)uVar20 + 1;
    uVar20 = (ulonglong)uVar15;
  } while ((int)uVar15 < 4);
  FUN_140071db0();
  local_78 = 0x27;
  uVar20 = uVar19;
  do {
    local_78 = local_78 ^ (uint)uVar20;
    uVar15 = (uint)uVar20 + 1;
    uVar20 = (ulonglong)uVar15;
  } while ((int)uVar15 < 2);
  local_68 = (**(code **)(*DAT_1400e9268 + 0x20))(DAT_1400e9268,param_1,lVar11);
  local_78 = 0x328;
  uVar20 = uVar19;
  do {
    local_78 = local_78 ^ (uint)uVar20;
    uVar15 = (uint)uVar20 + 1;
    uVar20 = (ulonglong)uVar15;
  } while ((int)uVar15 < 5);
  local_70 = (**(code **)(*DAT_1400e9268 + 0x28))(DAT_1400e9268,param_1,lVar11);
  FUN_14007ca50();
  local_78 = 0x38e;
  uVar20 = uVar19;
  do {
    local_78 = local_78 ^ (uint)uVar20;
    uVar15 = (uint)uVar20 + 1;
    uVar20 = (ulonglong)uVar15;
  } while ((int)uVar15 < 7);
  local_40 = (undefined1 (*) [32])0x0;
  local_50 = (undefined1 (*) [32])0x0;
  pauStack_48 = (undefined1 (*) [32])0x0;
  if (*(uint *)(lVar11 + 0x18) == 0) {
    pauVar13 = (undefined1 (*) [32])0x0;
  }
  else {
    uVar20 = (ulonglong)*(uint *)(lVar11 + 0x18) * 4;
    pauVar13 = (undefined1 (*) [32])FUN_140008140(uVar20);
    local_50 = pauVar13;
    local_40 = (undefined1 (*) [32])(*pauVar13 + uVar20);
    FUN_1400d2be0(pauVar13,0,uVar20);
    pauStack_48 = (undefined1 (*) [32])(*pauVar13 + uVar20);
  }
  pauVar8 = pauStack_48;
  FUN_140033bc0();
  iVar7 = _UNK_1400ddecc;
  iVar6 = _UNK_1400ddec8;
  iVar5 = _UNK_1400ddec4;
  iVar4 = _DAT_1400ddec0;
  uVar20 = uVar19;
  do {
    uVar15 = (int)uVar20 + 1;
    uVar20 = (ulonglong)uVar15;
  } while ((int)uVar15 < 10);
  local_78 = 0x2eb;
  uVar20 = uVar19;
  do {
    local_78 = local_78 ^ (uint)uVar20;
    uVar15 = (uint)uVar20 + 1;
    uVar20 = (ulonglong)uVar15;
  } while ((int)uVar15 < 0xe);
  uVar21 = (longlong)pauVar8 - (longlong)pauVar13 >> 2;
  uVar20 = uVar19;
  pauVar17 = pauVar13;
  if (uVar21 < 0x80000000) {
    uVar15 = (uint)uVar21;
    if ((uVar15 != 0) && (uVar20 = 0, 0xf < uVar15)) {
      uVar16 = uVar15 & 0x8000000f;
      if ((int)uVar16 < 0) {
        uVar16 = (uVar16 - 1 | 0xfffffff0) + 1;
      }
      uVar20 = uVar19;
      pauVar17 = pauVar13 + 1;
      iVar22 = 8;
      do {
        iVar9 = iVar22 + -4;
        iVar14 = (int)uVar20;
        *(int *)pauVar17[-1] = iVar14 + iVar4;
        *(int *)(pauVar17[-1] + 4) = iVar14 + iVar5;
        *(int *)(pauVar17[-1] + 8) = iVar14 + iVar6;
        *(int *)(pauVar17[-1] + 0xc) = iVar14 + iVar7;
        iVar1 = iVar22 + 4;
        uVar20 = (ulonglong)(iVar14 + 0x10U);
        *(int *)(pauVar17[-1] + 0x10) = iVar9 + iVar4;
        *(int *)(pauVar17[-1] + 0x14) = iVar9 + iVar5;
        *(int *)(pauVar17[-1] + 0x18) = iVar9 + iVar6;
        *(int *)(pauVar17[-1] + 0x1c) = iVar9 + iVar7;
        *(int *)*pauVar17 = iVar22 + iVar4;
        *(int *)(*pauVar17 + 4) = iVar22 + iVar5;
        *(int *)(*pauVar17 + 8) = iVar22 + iVar6;
        *(int *)(*pauVar17 + 0xc) = iVar22 + iVar7;
        *(int *)(*pauVar17 + 0x10) = iVar1 + iVar4;
        *(int *)(*pauVar17 + 0x14) = iVar1 + iVar5;
        *(int *)(*pauVar17 + 0x18) = iVar1 + iVar6;
        *(int *)(*pauVar17 + 0x1c) = iVar1 + iVar7;
        pauVar17 = pauVar17 + 2;
        iVar22 = iVar22 + 0x10;
      } while (iVar14 + 0x10U != uVar15 - uVar16);
    }
    for (lVar11 = (longlong)(int)uVar20; lVar11 != (int)uVar15; lVar11 = lVar11 + 1) {
      *(int *)(*pauVar13 + lVar11 * 4) = (int)uVar20;
      uVar20 = (ulonglong)((int)uVar20 + 1);
    }
  }
  else {
    for (; pauVar17 != pauVar8; pauVar17 = (undefined1 (*) [32])(*pauVar17 + 4)) {
      *(int *)*pauVar17 = (int)uVar20;
      uVar20 = (ulonglong)((int)uVar20 + 1);
    }
  }
  FUN_140023740();
  if (pauVar13 != pauVar8) {
    do {
      pcVar18 = (char *)((ulonglong)*(uint *)(lVar12 + (ulonglong)*(uint *)*pauVar13 * 4) + param_1)
      ;
      FUN_14002f140();
      FUN_140014570();
      uVar20 = uVar19;
      do {
        uVar15 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar15;
      } while ((int)uVar15 < 10);
      local_78 = 0x179;
      uVar20 = uVar19;
      do {
        local_78 = local_78 ^ (uint)uVar20;
        uVar15 = (uint)uVar20 + 1;
        uVar20 = (ulonglong)uVar15;
      } while ((int)uVar15 < 3);
      FUN_1400295e0();
      local_78 = 0x278;
      uVar20 = uVar19;
      do {
        local_78 = local_78 ^ (uint)uVar20;
        uVar15 = (uint)uVar20 + 1;
        uVar20 = (ulonglong)uVar15;
      } while ((int)uVar15 < 5);
      cVar3 = *pcVar18;
      uVar20 = uVar19;
      while (cVar3 != '\0') {
        uVar20 = uVar20 + 1;
        cVar3 = pcVar18[uVar20];
      }
      pcVar2 = pcVar18 + uVar20;
      uVar15 = (int)DAT_1400e9228 + 0xeb66ba25U ^ 0xeb66af20;
      for (; pcVar18 != pcVar2; pcVar18 = pcVar18 + 1) {
        uVar15 = uVar15 * 0x21 + (int)*pcVar18;
      }
    } while ((uVar15 != param_2) &&
            (pauVar13 = (undefined1 (*) [32])(*pauVar13 + 4), pauVar13 != pauVar8));
    if (pauVar13 != pauVar8) {
      uVar19 = (ulonglong)
               *(uint *)(local_68 +
                        (ulonglong)*(ushort *)(local_70 + (ulonglong)*(uint *)*pauVar13 * 2) * 4) +
               param_1;
    }
  }
  FUN_140007410((longlong *)&local_50);
  return uVar19;
}



// ===== FUN_1400019d0 @ 1400019d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1400019d0(undefined8 param_1,ulonglong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined1 auStack_288 [32];
  undefined8 local_268;
  uint local_260;
  undefined8 local_258;
  uint local_248;
  uint local_244 [3];
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = DAT_1400e2040 ^ (ulonglong)auStack_288;
  uVar11 = DAT_1400e9228 + 0xfb70ae735e4603e0U ^ 0xfb70ae735e4603e0;
  uVar10 = 0;
  uVar6 = uVar10;
  do {
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 0xb);
  local_248 = 0x6d;
  uVar9 = DAT_1400e9228 + 0x7aa5c6a9f94262a0U ^ 0x7aa5c6a9f94262a0;
  uVar6 = uVar10;
  do {
    local_248 = local_248 ^ uVar6;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 8);
  uVar6 = uVar10;
  if (param_2 != (ulonglong *)0x0) {
    do {
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 2);
    uVar11 = *param_2;
    local_248 = 0x98;
    uVar6 = uVar10;
    do {
      local_248 = local_248 ^ uVar6;
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 8);
    uVar9 = param_2[1];
    FUN_14008f6f0();
    FUN_140043cf0();
    FUN_1400375b0();
    thunk_FUN_1400c9460(param_2);
  }
  (**(code **)(&DAT_1400e8ec8 +
              ((longlong)((int)DAT_1400e9228 + -0x2edaa760) ^ 0xffffffffd12558a0U) * 8))
            (0,local_238,(int)DAT_1400e9228 + 0xd12559a4U ^ 0xd12558a0);
  FUN_140080050();
  FUN_14009def0();
  FUN_140072000();
  FUN_1400b92e0();
  local_248 = 0x298;
  uVar6 = uVar10;
  do {
    local_248 = local_248 ^ uVar6;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 3);
  FUN_14004d310();
  lVar1 = (**(code **)(*DAT_1400e9268 + 0x30))(DAT_1400e9268,DAT_1400e9228);
  uVar6 = uVar10;
  do {
    uVar6 = uVar6 + 1;
    uVar7 = uVar10;
  } while ((int)uVar6 < 7);
  do {
    uVar7 = uVar7 + 1;
    uVar6 = uVar10;
  } while ((int)uVar7 < 0xe);
  do {
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 0xb);
  lVar1 = *(longlong *)(((ulonglong)((int)DAT_1400e9228 + 0x5b8a1f58) ^ 0x5b8a1f40) + lVar1);
  local_248 = 0x3cb;
  uVar6 = uVar10;
  do {
    local_248 = local_248 ^ uVar6;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 5);
  FUN_14004c7a0();
  iVar8 = (int)DAT_1400e9228;
  FUN_1400442a0();
  lVar1 = *(longlong *)(lVar1 + ((ulonglong)(iVar8 + 0x4404ad40) ^ 0x4404ad60));
  FUN_14003bc00();
  FUN_140024190();
  uVar2 = *(undefined8 *)(lVar1 + 0x20);
  FUN_140026ce0();
  local_248 = 0x3cc;
  uVar6 = uVar10;
  do {
    local_248 = local_248 ^ uVar6;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 4);
  uVar2 = (**(code **)*DAT_1400e9268)(DAT_1400e9268,uVar2,DAT_1400e9228);
  FUN_14006c3b0();
  local_248 = 0xd4;
  uVar6 = uVar10;
  do {
    local_248 = local_248 ^ uVar6;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 7);
  FUN_140064c20();
  puVar3 = (undefined4 *)(**(code **)(*DAT_1400e9268 + 0x10))(DAT_1400e9268,uVar2,DAT_1400e9228);
  uVar6 = uVar10;
  do {
    uVar6 = uVar6 + 1;
    uVar7 = uVar10;
  } while ((int)uVar6 < 0xe);
  do {
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 0xf);
  local_248 = 0x296;
  uVar6 = uVar10;
  do {
    local_248 = local_248 ^ uVar6;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 8);
  iVar8 = (int)DAT_1400e9228;
  local_260 = iVar8 + 0x22d57da0U ^ 0x22d57d20;
  local_258 = 0;
  local_268 = CONCAT44(local_268._4_4_,iVar8 + -0x2aa8b23d) ^ 0xd5574dc0;
  lVar1 = (**(code **)(&DAT_1400e8ec8 + ((longlong)(iVar8 + 0x51e060e1) ^ 0x51e060e0U) * 8))
                    (local_238,iVar8 + 0x6cdcbfa0U ^ 0xecdcbfa0,iVar8 + 0x3a5aef01U ^ 0x3a5aef00,0);
  if (lVar1 != -1) {
    (**(code **)(&DAT_1400e8ec8 +
                ((longlong)((int)DAT_1400e9228 + -0x59b395fe) ^ 0xffffffffa64c6a00U) * 8))
              (lVar1,*puVar3,0,(int)DAT_1400e9228 + 0xa64c6a00U ^ 0xa64c6a00);
    FUN_14003c890();
    uVar6 = uVar10;
    do {
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 5);
    local_248 = 0x38d;
    uVar6 = uVar10;
    do {
      local_248 = local_248 ^ uVar6;
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 0xf);
    iVar8 = (int)DAT_1400e9228;
    lVar4 = (**(code **)(&DAT_1400e8ec8 + ((longlong)(iVar8 + 0x77418644) ^ 0x77418640U) * 8))
                      (0,DAT_1400dde5c,iVar8 + 0x5fbc2460U ^ 0x5fbc1460,
                       iVar8 + 0xad3a4380U ^ 0xad3a43c0);
    FUN_14006c960();
    local_248 = 0xe8;
    uVar6 = uVar10;
    do {
      local_248 = local_248 ^ uVar6;
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 10);
    if (lVar4 == 0) {
      (**(code **)(&DAT_1400e8ec8 + ((longlong)((int)DAT_1400e9228 + 0x56125605) ^ 0x56125600U) * 8)
      )(lVar1);
      FUN_14001be50();
    }
    else {
      local_244[0] = (int)DAT_1400e9228 + 0x7e2f6000U ^ 0x7e2f6000;
      FUN_14008c800();
      local_268 = 0;
      (**(code **)(&DAT_1400e8ec8 + ((longlong)((int)DAT_1400e9228 + 0x192bbec3) ^ 0x192bbec0U) * 8)
      )(lVar1,lVar4,DAT_1400dde5c,local_244);
      FUN_14001f280();
      FUN_14005fa10();
      (**(code **)(&DAT_1400e8ec8 + ((longlong)((int)DAT_1400e9228 + 0x1a64ce5) ^ 0x1a64ce0U) * 8))
                (lVar1);
      local_248 = 0x12e;
      uVar6 = uVar10;
      do {
        local_248 = local_248 ^ uVar6;
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 10);
      FUN_14008bfe0();
      uVar5 = (ulonglong)DAT_1400dde58;
      FUN_14005a5c0();
      (*(code *)(lVar4 + uVar5))(uVar11,uVar9);
      FUN_140084130();
      local_248 = 0x27f;
      do {
        local_248 = local_248 ^ uVar10;
        uVar10 = uVar10 + 1;
      } while ((int)uVar10 < 9);
      FUN_140034830();
    }
  }
  return;
}



// ===== FUN_140002000 @ 140002000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140002000(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  uint uVar6;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 auStackY_148 [32];
  longlong local_108 [7];
  longlong *local_d0;
  longlong local_c8;
  longlong local_b8 [7];
  longlong *local_80;
  longlong *local_78;
  longlong *plStack_70;
  longlong *local_68;
  undefined **local_58;
  longlong local_50;
  undefined ***local_20;
  ulonglong local_18;
  ulonglong uVar7;
  
  local_18 = DAT_1400e2040 ^ (ulonglong)auStackY_148;
  uVar9 = 0;
  FUN_1400444e0();
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 10);
  FUN_140034710();
  lVar4 = (**(code **)(*DAT_1400e9268 + 0x30))(DAT_1400e9268,0);
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 8);
  FUN_14002ddd0();
  FUN_140079b70();
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 10);
  FUN_14001a0a0();
  FUN_14007b020();
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    uVar8 = uVar9;
  } while ((int)uVar6 < 4);
  do {
    uVar6 = (int)uVar8 + 1;
    uVar7 = uVar9;
    uVar8 = (ulonglong)uVar6;
  } while ((int)uVar6 < 6);
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0xe);
  puVar1 = *(undefined8 **)(*(longlong *)(lVar4 + 0x18) + 0x20);
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 5);
  FUN_1400a1340();
  FUN_14000d4a0();
  plVar5 = (longlong *)*puVar1;
  FUN_1400a0b50();
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    uVar8 = uVar9;
  } while ((int)uVar6 < 0xf);
  do {
    uVar6 = (int)uVar8 + 1;
    uVar8 = (ulonglong)uVar6;
  } while ((int)uVar6 < 5);
  DAT_1400e9260 = *(longlong *)(*plVar5 + 0x20);
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    uVar8 = uVar9;
  } while ((int)uVar6 < 7);
  do {
    uVar6 = (int)uVar8 + 1;
    uVar8 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0xe);
  FUN_14006d5d0();
  lVar4 = DAT_1400e9260;
  if (DAT_1400e9260 == 0) {
    return;
  }
  _DAT_1400e8ec8 = FUN_140001560(DAT_1400e9260,0x13b8a163);
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0xd);
  _DAT_1400e8ed0 = FUN_140001560(lVar4,0xeb96c610);
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0xd);
  FUN_140007aa0(lVar4,uVar7,0);
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0xd);
  FUN_1400423b0();
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0xd);
  FUN_1400423b0();
  FUN_140052f60();
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0xf);
  FUN_14008e4a0();
  FUN_1400a8980();
  uVar7 = uVar9;
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 0xe);
  FUN_140080050();
  local_20 = (undefined ***)0x0;
  uVar7 = uVar9;
  if (_DAT_1400e8ef8 != 0) {
    local_58 = &PTR_FUN_1400ddd88;
    local_20 = &local_58;
    local_50 = _DAT_1400e8ef8;
  }
  do {
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
  } while ((int)uVar6 < 6);
  FUN_1400a5d60();
  if (local_20 == (undefined ***)0x0) goto LAB_1400025be;
  local_78 = (longlong *)0x0;
  plStack_70 = (longlong *)0x0;
  local_68 = (longlong *)0x0;
  local_d0 = (longlong *)0x0;
  local_d0 = (longlong *)(*(code *)**local_20)(local_20,local_108);
  local_80 = (longlong *)0x0;
  local_c8 = param_2;
  plVar5 = (longlong *)FUN_1400bb470(0x50);
  *plVar5 = (longlong)&PTR_FUN_1400dde60;
  plVar5[8] = 0;
  if (local_d0 != (longlong *)0x0) {
    if (local_d0 == local_108) {
      lVar4 = (**(code **)(*local_d0 + 8))(local_d0,plVar5 + 1);
      plVar5[8] = lVar4;
      if (local_d0 == (longlong *)0x0) goto LAB_140002488;
      (**(code **)(*local_d0 + 0x20))(local_d0,local_d0 != local_108);
    }
    else {
      plVar5[8] = (longlong)local_d0;
    }
    local_d0 = (longlong *)0x0;
  }
LAB_140002488:
  plVar5[9] = local_c8;
  local_80 = plVar5;
  if (plStack_70 == local_68) {
    FUN_140007750((ulonglong *)&local_78,plStack_70,local_b8);
  }
  else {
    FUN_1400088a0((longlong)plStack_70,local_b8);
    plStack_70 = plStack_70 + 8;
  }
  if (local_80 != (longlong *)0x0) {
    (**(code **)(*local_80 + 0x20))();
  }
  if (local_d0 != (longlong *)0x0) {
    (**(code **)(*local_d0 + 0x20))();
    local_d0 = (longlong *)0x0;
  }
  do {
    plVar2 = plStack_70;
    uVar6 = (int)uVar9 + 1;
    uVar9 = (ulonglong)uVar6;
    plVar5 = plStack_70;
    plVar3 = local_78;
  } while ((int)uVar6 < 0xf);
  for (; plStack_70 = plVar5, plVar3 != plVar2; plVar3 = plVar3 + 8) {
    if ((longlong *)plVar3[7] == (longlong *)0x0) {
      FUN_1400bb14c();
      goto LAB_140002602;
    }
    (**(code **)(*(longlong *)plVar3[7] + 0x10))();
    plVar5 = plStack_70;
  }
  plVar3 = local_78;
  if (local_78 != (longlong *)0x0) {
    for (; plVar3 != plVar5; plVar3 = plVar3 + 8) {
      plVar2 = (longlong *)plVar3[7];
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != plVar3);
        plVar3[7] = 0;
      }
    }
    plVar5 = local_78;
    if ((0xfff < ((longlong)local_68 - (longlong)local_78 & 0xffffffffffffffc0U)) &&
       (plVar5 = (longlong *)local_78[-1],
       0x1f < (ulonglong)((longlong)local_78 + (-8 - (longlong)plVar5)))) {
LAB_140002602:
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_1400c9460(plVar5);
  }
LAB_1400025be:
  if (local_20 != (undefined ***)0x0) {
    (*(code *)(*local_20)[4])(local_20,local_20 != &local_58);
  }
  return;
}



// ===== FUN_140003380 @ 140003380 =====

undefined8 FUN_140003380(undefined8 *param_1,ulonglong param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint local_res8;
  
  uVar2 = param_1[2] + 0x59bff9f6df6184e0 ^ 0x59bff9f6df6184e0;
  if (param_2 != uVar2) {
    return uVar2 & 0xffffffffffffff00;
  }
  lVar3 = (**(code **)(*DAT_1400e9268 + 0x30))(DAT_1400e9268,param_1[2]);
  FUN_14007b280();
  uVar8 = 0;
  iVar7 = 0;
  do {
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xf);
  iVar7 = 0;
  do {
    iVar7 = iVar7 + 1;
  } while (iVar7 < 8);
  FUN_1400b4d10();
  lVar3 = *(longlong *)(((ulonglong)(*(int *)(param_1 + 2) + 0xfdd4d098) ^ 0xfdd4d080) + lVar3);
  iVar7 = 0;
  do {
    iVar7 = iVar7 + 1;
  } while (iVar7 < 10);
  iVar7 = *(int *)(param_1 + 2);
  iVar6 = 0;
  do {
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xd);
  FUN_14000db70();
  iVar6 = 0;
  do {
    iVar6 = iVar6 + 1;
  } while (iVar6 < 9);
  lVar3 = *(longlong *)
           (((ulonglong)(*(int *)(param_1 + 2) + 0xcec9ece0) ^ 0xcec9ecc0) +
           *(longlong *)**(undefined8 **)(((ulonglong)(iVar7 + 0x98d12f60) ^ 0x98d12f40) + lVar3));
  FUN_1400ae7a0();
  uVar2 = FUN_14003ee30();
  if (lVar3 != 0) {
    FUN_14009a5b0();
    FUN_1400a82a0();
    FUN_14007f4c0();
    pcVar4 = (code *)FUN_140001560(lVar3,*(int *)(param_1 + 2) + 0xa53532d7U ^ 0x88399720);
    uVar2 = 0;
    if (pcVar4 != (code *)0x0) {
      puVar5 = (undefined8 *)FUN_1400bb470(0x10);
      uVar1 = param_1[1];
      *puVar5 = *param_1;
      puVar5[1] = uVar1;
      FUN_14003ebf0();
      (*pcVar4)(FUN_140002000,puVar5,0);
      local_res8 = 0x175;
      do {
        local_res8 = local_res8 ^ uVar8;
        uVar2 = (ulonglong)local_res8;
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < 5);
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



// ===== FUN_140006270 @ 140006270 =====

ulonglong FUN_140006270(HINSTANCE param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  int iVar1;
  HWND pHVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar3 = param_4 & 0xffffffff;
  DAT_1400e9220 = (longlong)&PTR_FUN_1400e2b10 + DAT_1400e9220;
  FUN_140036a50();
  iVar1 = 0;
  uVar5 = 0;
  do {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulonglong)uVar4;
  } while ((int)uVar4 < 7);
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xf);
  FUN_14001d630();
  FUN_14005fa10();
  pHVar2 = FUN_140006340(param_1,uVar3,uVar5,param_4,in_stack_ffffffffffffffd8,DAT_1400e9228);
  if (pHVar2 != (HWND)0x0) {
    uVar3 = FUN_140006690(pHVar2,DAT_1400e9228);
    return uVar3;
  }
  return (ulonglong)((int)DAT_1400e9228 + 0x95906800U ^ 0x95906800);
}



// ===== FUN_1400026b0 @ 1400026b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1400026b0(void)

{
  HWND hWnd;
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStack_258 [32];
  uint local_238;
  ushort local_228 [88];
  ushort local_178 [88];
  undefined2 local_c8;
  ulonglong local_b8;
  undefined4 local_b0;
  undefined1 *local_a8;
  undefined1 local_98 [96];
  ulonglong local_38;
  
  local_38 = DAT_1400e2040 ^ (ulonglong)auStack_258;
  FUN_1400d2be0((undefined1 (*) [32])local_178,0,0xb2);
  uVar3 = 0;
  local_238 = 0x386;
  uVar7 = uVar3;
  do {
    local_238 = local_238 ^ (uint)uVar7;
    uVar1 = (uint)uVar7 + 1;
    uVar7 = (ulonglong)uVar1;
  } while ((int)uVar1 < 10);
  FUN_140044960();
  FUN_14005dfb0();
  local_228[0] = 0x76;
  local_228[1] = 0x51;
  local_228[2] = 0x45;
  local_228[3] = 0x4f;
  local_228[4] = 0x4b;
  local_228[5] = 0x15;
  local_228[6] = 0x55;
  local_228[7] = 0x57;
  local_228[8] = 0x5a;
  local_228[9] = 0x5d;
  local_228[10] = 0x4b;
  local_228[0xb] = 0x19;
  local_228[0xc] = 0x52;
  local_228[0xd] = 0x5b;
  local_228[0xe] = 0x4e;
  local_228[0xf] = 0x51;
  local_228[0x10] = 0x13;
  local_228[0x11] = 0x53;
  local_228[0x12] = 0x56;
  local_228[0x13] = 0x40;
  local_228[0x14] = 0x12;
  local_228[0x15] = 0x4d;
  local_228[0x16] = 0x44;
  local_228[0x17] = 0x1f;
  local_228[0x18] = 10;
  local_228[0x19] = 0x77;
  local_228[0x1a] = 0x50;
  local_228[0x1b] = 0x44;
  local_228[0x1c] = 0x5d;
  local_228[0x1d] = 0x46;
  local_228[0x1e] = 0x13;
  local_228[0x1f] = 0x4d;
  local_228[0x20] = 0x56;
  local_228[0x21] = 0x5b;
  local_228[0x22] = 0x5c;
  local_228[0x23] = 0x59;
  local_228[0x24] = 0x14;
  local_228[0x25] = 0x5f;
  local_228[0x26] = 0x4f;
  local_228[0x27] = 0x4d;
  local_228[0x28] = 0x15;
  local_228[0x29] = 0x4b;
  local_228[0x2a] = 0x57;
  local_228[0x2b] = 0x41;
  local_228[0x2c] = 0x13;
  local_228[0x2d] = 0x4e;
  local_228[0x2e] = 0x56;
  local_228[0x2f] = 0x42;
  local_228[0x30] = 0x5c;
  local_228[0x31] = 0x14;
  local_228[0x32] = 0x14;
  local_228[0x33] = 0x7d;
  local_228[0x34] = 0x4f;
  local_228[0x35] = 0x4f;
  local_228[0x36] = 0x50;
  local_228[0x37] = 0x40;
  local_228[0x38] = 0x18;
  local_228[0x39] = 0x53;
  local_228[0x3a] = 0x5c;
  local_228[0x3b] = 0x44;
  local_228[0x3c] = 0x57;
  local_228[0x3d] = 0x54;
  local_228[0x3e] = 0x12;
  local_228[0x3f] = 0x4a;
  local_228[0x40] = 0x41;
  local_228[0x41] = 0x5d;
  local_228[0x42] = 10;
  local_228[0x43] = 0x58;
  local_228[0x44] = 0x47;
  local_228[0x45] = 0x5d;
  local_228[0x46] = 0x4d;
  local_228[0x47] = 0x5a;
  local_228[0x48] = 0x57;
  local_228[0x49] = 10;
  local_228[0x4a] = 0x58;
  local_228[0x4b] = 0x5b;
  local_228[0x4c] = 0x56;
  local_228[0x4d] = 0x18;
  local_228[0x4e] = 0x50;
  local_228[0x4f] = 0x56;
  local_228[0x50] = 0x59;
  local_228[0x51] = 0x5c;
  local_228[0x52] = 0x47;
  local_228[0x53] = 0x46;
  local_228[0x54] = 0x18;
  local_228[0x55] = 0x4d;
  local_228[0x56] = 0x5c;
  local_228[0x57] = 0x5f;
  FUN_1400a9f40();
  local_238 = 999;
  uVar7 = uVar3;
  do {
    local_238 = local_238 ^ (uint)uVar7;
    uVar1 = (uint)uVar7 + 1;
    uVar7 = (ulonglong)uVar1;
    uVar4 = uVar3;
    uVar6 = uVar3;
  } while ((int)uVar1 < 6);
  do {
    iVar5 = (int)uVar6;
    iVar2 = (int)(uVar6 * 0x24924925 >> 0x20);
    *(wchar_t *)((longlong)local_178 + uVar4) =
         L"843*952"[(int)(iVar5 + (((uint)(iVar5 - iVar2) >> 1) + iVar2 >> 2) * -7)] ^
         *(ushort *)((longlong)local_228 + uVar4);
    FUN_14001ebc0();
    FUN_1400ab3e0();
    uVar4 = uVar4 + 2;
    uVar6 = (ulonglong)(iVar5 + 1U);
  } while ((int)(iVar5 + 1U) < 0x58);
  local_c8 = 0;
  FUN_14007c5d0();
  FUN_140048b80();
  uVar7 = uVar3;
  do {
    local_98[uVar7] = (char)local_178[uVar7];
    FUN_140014330();
    FUN_140077c90();
    uVar7 = uVar7 + 1;
  } while ((longlong)uVar7 < 0x59);
  local_98[0x58] = 0;
  FUN_140061690();
  hWnd = FindWindowW(L"Flare-OnCalculatorClass",(LPCWSTR)0x0);
  FUN_140082020();
  if (hWnd != (HWND)0x0) {
    local_b8 = DAT_1400e9228 + 0x4e752fc75f23c28bU ^ 0x4e752fc79cd2e800;
    local_238 = 0x252;
    uVar7 = uVar3;
    do {
      local_238 = local_238 ^ (uint)uVar7;
      uVar1 = (uint)uVar7 + 1;
      uVar7 = (ulonglong)uVar1;
    } while ((int)uVar1 < 2);
    FUN_1400465e0();
    local_b0 = 0x59;
    local_238 = 0x49;
    uVar7 = uVar3;
    do {
      local_238 = local_238 ^ (uint)uVar7;
      uVar1 = (uint)uVar7 + 1;
      uVar7 = (ulonglong)uVar1;
    } while ((int)uVar1 < 10);
    FUN_14006e360();
    FUN_140083370();
    local_a8 = local_98;
    FUN_140032cd0();
    local_238 = 0x16d;
    uVar7 = uVar3;
    do {
      local_238 = local_238 ^ (uint)uVar7;
      uVar1 = (uint)uVar7 + 1;
      uVar7 = (ulonglong)uVar1;
    } while ((int)uVar1 < 0xb);
    SendMessageW(hWnd,(int)DAT_1400e9228 + 0xa3c0c18aU ^ 0xa3c0c1c0,0,(LPARAM)&local_b8);
    FUN_14008c220();
    FUN_140057ca0();
    do {
      uVar1 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar1;
    } while ((int)uVar1 < 0xd);
  }
  return;
}



// ===== FUN_140002a90 @ 140002a90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140002a90(undefined8 *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  longlong lVar4;
  ulonglong *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  ulonglong *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined1 auStackY_138 [32];
  longlong **local_100;
  ulonglong *local_f8;
  ulonglong *puStack_f0;
  ulonglong *local_e8;
  longlong *local_e0;
  undefined1 *puStack_d8;
  longlong local_d0;
  undefined1 local_c8 [16];
  longlong *local_b8;
  ulonglong uStack_b0;
  longlong lStack_a8;
  longlong local_a0;
  longlong lStack_98;
  longlong *local_88;
  longlong lStack_80;
  longlong local_78;
  ulonglong uStack_70;
  ulonglong local_68;
  ulonglong local_60;
  
  local_60 = DAT_1400e2040 ^ (ulonglong)auStackY_138;
  if (*(int *)*param_1 == -0x3fffff72) {
    iVar12 = 0;
    iVar9 = iVar12;
    if (param_1[1] != 0) {
      *(undefined8 *)(param_1[1] + 0x1a0) = 0;
      iVar8 = iVar12;
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0xc);
      *(undefined8 *)(param_1[1] + 0x1a8) = 0;
      FUN_140025870();
      FUN_140034830();
      *(undefined2 *)(param_1[1] + 0x102) = 0;
      FUN_14001b770();
      FUN_14008cb80();
    }
    do {
      lVar4 = DAT_1400e9228;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    FUN_140023980();
    uVar13 = DAT_1400e9250;
    iVar9 = iVar12;
    do {
      iVar9 = iVar9 + 1;
    } while (iVar9 < 3);
    local_88 = (longlong *)0x0;
    lStack_80 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    uVar15 = DAT_1400e9258 + DAT_1400e9250;
    puStack_d8 = local_c8;
    local_e0 = (longlong *)FUN_1400bb470(0x10);
    *local_e0 = (longlong)&local_88;
    local_e0[1] = 0;
    local_100 = &local_88;
    local_88 = local_e0;
    for (; uVar13 != uVar15; uVar13 = uVar13 + 1) {
      FUN_140007690((longlong)&local_88,
                    (undefined8 *)
                    (*(longlong *)(DAT_1400e9240 + (uVar13 >> 1 & DAT_1400e9248 - 1U) * 8) +
                    (ulonglong)((uint)uVar13 & 1) * 8));
    }
    iVar9 = (int)lVar4;
    uVar13 = (ulonglong)(iVar9 + 0x50cac920U ^ 0x50cac920);
    iVar8 = iVar12;
    do {
      iVar8 = iVar8 + 1;
    } while (iVar8 < 7);
    uVar17 = (ulonglong)(iVar9 + 0xebc727e0U ^ 0xebc727e0);
    FUN_14001b8a0();
    FUN_140008d50();
    uVar16 = (ulonglong)(iVar9 + 0xd441b600U ^ 0xd441b600);
    FUN_140086c80();
    uVar15 = uStack_70;
    if ((lVar4 + 0xadf610866f3e14c3U ^ 0xadf610866f3e14c0) <= local_68) {
      uStack_b0 = 0;
      lStack_a8 = 0;
      local_a0 = 0;
      lStack_98 = 0;
      uVar13 = local_68 + uStack_70;
      puStack_d8 = local_c8;
      local_e0 = (longlong *)FUN_1400bb470(0x10);
      *local_e0 = (longlong)&local_b8;
      local_e0[1] = 0;
      local_100 = &local_b8;
      local_b8 = local_e0;
      for (; iVar8 = iVar12, uVar15 != uVar13; uVar15 = uVar15 + 1) {
        FUN_140007690((longlong)&local_b8,
                      (undefined8 *)
                      (*(longlong *)(lStack_80 + (uVar15 >> 1 & local_78 - 1U) * 8) +
                      (ulonglong)((uint)uVar15 & 1) * 8));
      }
      do {
        iVar8 = iVar8 + 1;
        iVar10 = iVar12;
      } while (iVar8 < 0xc);
      do {
        iVar10 = iVar10 + 1;
        iVar8 = iVar12;
      } while (iVar10 < 0xb);
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < 6);
      uVar13 = local_a0 + -1 + lStack_98;
      dVar1 = *(double *)
               (*(longlong *)(uStack_b0 + (uVar13 >> 1 & lStack_a8 - 1U) * 8) +
               (ulonglong)((uint)uVar13 & 1) * 8);
      if (lStack_98 == 1) {
        local_a0 = 0;
      }
      lStack_98 = lStack_98 + -1;
      FUN_140079dc0();
      uVar13 = local_a0 + -1 + lStack_98;
      dVar2 = *(double *)
               (*(longlong *)(uStack_b0 + (uVar13 >> 1 & lStack_a8 - 1U) * 8) +
               (ulonglong)((uint)uVar13 & 1) * 8);
      if (lStack_98 == 1) {
        local_a0 = 0;
      }
      lStack_98 = lStack_98 + -1;
      FUN_1400673e0();
      uVar13 = local_a0 + -1 + lStack_98;
      dVar3 = *(double *)
               (*(longlong *)(uStack_b0 + (uVar13 >> 1 & lStack_a8 - 1U) * 8) +
               (ulonglong)((uint)uVar13 & 1) * 8);
      iVar8 = iVar12;
      if (lStack_98 == 1) {
        local_a0 = 0;
      }
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0xb);
      lStack_98 = lStack_98 + -1;
      FUN_1400846e0();
      iVar8 = iVar12;
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < 4);
      uVar13 = (ulonglong)((double)(lVar4 + 0xe8cf2de95ea67ca1U ^ 0xe8cf2de95ea67ca0) * dVar1);
      FUN_1400947e0();
      FUN_140047940();
      uVar17 = (ulonglong)((double)(lVar4 + 0xa79ed23b47210ac1U ^ 0xa79ed23b47210ac0) * dVar2);
      FUN_140048250();
      FUN_140044180();
      uVar16 = (ulonglong)((double)(lVar4 + 0x666e768d2f030e60U ^ 0x666e768d2f9b98e0) * dVar3);
      iVar8 = iVar12;
      do {
        iVar8 = iVar8 + 1;
        iVar10 = iVar12;
      } while (iVar8 < 9);
      do {
        iVar10 = iVar10 + 1;
      } while (iVar10 < 10);
      FUN_140007340((longlong)&local_b8);
      plVar6 = local_b8;
      local_b8 = (longlong *)0x0;
      thunk_FUN_1400c9460(plVar6);
    }
    iVar8 = iVar12;
    if (local_68 == 0) {
      local_100 = (longlong **)(lVar4 + 0x82f70edf9be1ba1fU ^ 0x82f70edf641e45e0);
    }
    else {
      uVar15 = (uStack_70 - 1) + local_68;
      dVar1 = *(double *)
               (*(longlong *)(lStack_80 + (uVar15 >> 1 & local_78 - 1U) * 8) +
               (ulonglong)((uint)uVar15 & 1) * 8);
      iVar10 = iVar12;
      do {
        iVar10 = iVar10 + 1;
        iVar11 = iVar12;
      } while (iVar10 < 5);
      do {
        iVar11 = iVar11 + 1;
        iVar10 = iVar12;
      } while (iVar11 < 9);
      do {
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0xd);
      if (local_68 == 1) {
        uStack_70 = 0;
      }
      local_68 = local_68 - 1;
      FUN_14007f390();
      FUN_1400a5b20();
      iVar10 = iVar12;
      do {
        iVar10 = iVar10 + 1;
      } while (iVar10 < 9);
      iVar10 = iVar12;
      do {
        iVar10 = iVar10 + 1;
      } while (iVar10 < 4);
      FUN_140081830();
      FUN_140044060();
      uVar15 = FUN_140006fc0((longlong)&local_88,lVar4);
      local_100 = (longlong **)
                  (uVar15 | (longlong)
                            (int)((int)((double)(lVar4 + 0xbf65fbd51d8df041U ^ 0xbf65fbd51d8df040) *
                                       dVar1) - (iVar9 + 0x1d09afadU ^ 0x1d8df040)));
    }
    do {
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0xd);
    FUN_140086910();
    local_f8 = (ulonglong *)0x0;
    puStack_f0 = (ulonglong *)0x0;
    local_e8 = (ulonglong *)0x0;
    FUN_140007510((longlong *)&local_f8,(undefined8 *)0x0,&local_100);
    FUN_14004d0d0();
    local_100 = (longlong **)(lVar4 + 0x49e5de3a04e7141fU ^ 0x49e5de3afb18ebe0);
    if (puStack_f0 == local_e8) {
      FUN_140007510((longlong *)&local_f8,puStack_f0,&local_100);
    }
    else {
      *puStack_f0 = (ulonglong)local_100;
      puStack_f0 = puStack_f0 + 1;
    }
    local_d0 = lVar4;
    FUN_14006a870();
    iVar9 = iVar12;
    do {
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    local_e0 = (longlong *)
               ((uVar13 & 0xffffffff) << ((char)lVar4 + 0xa0U & 0x3f) | uVar17 & 0xffffffff);
    FUN_140015330();
    iVar9 = iVar12;
    do {
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0xf);
    do {
      iVar12 = iVar12 + 1;
    } while (iVar12 < 6);
    puStack_d8 = (undefined1 *)(uVar16 & 0xffffffff);
    FUN_140057010();
    puVar5 = puStack_f0;
    local_b8 = local_e0;
    uStack_b0 = (ulonglong)puStack_d8;
    lStack_a8 = local_d0;
    puVar14 = local_f8;
    while ((puVar14 != puVar5 && (uVar7 = FUN_140003380(&local_b8,*puVar14), (char)uVar7 == '\0')))
    {
      puVar14 = puVar14 + 1;
    }
    if (local_f8 != (ulonglong *)0x0) {
      puVar14 = local_f8;
      if ((0xfff < ((longlong)local_e8 - (longlong)local_f8 & 0xfffffffffffffff8U)) &&
         (puVar14 = (ulonglong *)local_f8[-1],
         0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)puVar14)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      thunk_FUN_1400c9460(puVar14);
      local_f8 = (ulonglong *)0x0;
      puStack_f0 = (ulonglong *)0x0;
      local_e8 = (ulonglong *)0x0;
    }
    FUN_140007340((longlong)&local_88);
    plVar6 = local_88;
    local_88 = (longlong *)0x0;
    thunk_FUN_1400c9460(plVar6);
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}


