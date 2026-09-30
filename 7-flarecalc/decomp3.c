
// ===== [target] FUN_140001560 @ 140001560 =====

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



// ===== [target] FUN_1400026b0 @ 1400026b0 =====

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



// ===== [target] FUN_140001480 @ 140001480 =====

void FUN_140001480(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_1400bb16c(0x1400ddb48);
}



// ===== [target] FUN_140003a20 @ 140003a20 =====

undefined8 FUN_140003a20(undefined8 param_1,undefined8 param_2,longlong *****param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_res10 [3];
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xd);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xe);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  local_res10[0] = param_2;
  uVar3 = FUN_140003570(DAT_1400e8f04,DAT_1400e8f08,param_3);
  local_res10[0] = uVar3;
  FUN_140007690(0x1400e9238,local_res10);
  FUN_1400b9d10();
  FUN_14002b150();
  for (; iVar2 < 0xd; iVar2 = iVar2 + 1) {
  }
  return uVar3;
}



// ===== [target] FUN_1400148e0 @ 1400148e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1400148e0(void)

{
  undefined8 *puVar1;
  int *piVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined1 auStack_98 [32];
  undefined1 local_78 [8];
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined8 local_58 [2];
  undefined8 local_48 [2];
  longlong local_38 [3];
  ulonglong local_20;
  
  local_20 = DAT_1400e2040 ^ (ulonglong)auStack_98;
  plVar4 = local_38;
  for (lVar3 = 0x18; lVar3 != 0; lVar3 = lVar3 + -1) {
    *(undefined1 *)plVar4 = 0;
    plVar4 = (longlong *)((longlong)plVar4 + 1);
  }
  local_70 = 0x3a;
  local_6c = 0x2e;
  puVar1 = FUN_1400baf40(local_48,&local_70,local_68);
  puVar5 = local_58;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar1;
    puVar1 = (undefined8 *)((longlong)puVar1 + 1);
    puVar5 = (undefined8 *)((longlong)puVar5 + 1);
  }
  FUN_1400bb010(local_78);
  FUN_1400baf70(local_38,local_58);
  piVar2 = (int *)FUN_1400baf50(local_38,0);
  DAT_1400e2b00 = (DAT_1400e2b00 ^ (longlong)*piVar2 + 0xb4cdb87aU) + 0xc2b03de5;
  if (DAT_1400e2b00 % 3 == 0) {
    FUN_1400094a0();
  }
  if (DAT_1400e2b00 % 7 == 0) {
    FUN_140010a30();
  }
  thunk_FUN_140007410(local_38);
  return;
}



// ===== [target] FUN_140001130 @ 140001130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_140001130(undefined1 (*param_1) [32],undefined1 (*param_2) [32],ulonglong param_3)

{
  ushort uVar1;
  undefined1 auVar2 [32];
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort *puVar7;
  uint uVar8;
  undefined1 (*pauVar9) [32];
  undefined1 (*pauVar10) [32];
  undefined1 auVar11 [16];
  
  uVar3 = 0;
  pauVar9 = param_1;
  pauVar10 = param_2;
  uVar4 = uVar3;
  if ((DAT_1400e9270 != 0) && (0xf < param_3)) {
    uVar6 = 0x10;
    do {
      auVar2 = vpcmpeqw_avx2(*pauVar9,*pauVar10);
      uVar8 = (uint)(SUB321(auVar2 >> 7,0) & 1) | (uint)(SUB321(auVar2 >> 0xf,0) & 1) << 1 |
              (uint)(SUB321(auVar2 >> 0x17,0) & 1) << 2 | (uint)(SUB321(auVar2 >> 0x1f,0) & 1) << 3
              | (uint)(SUB321(auVar2 >> 0x27,0) & 1) << 4 |
              (uint)(SUB321(auVar2 >> 0x2f,0) & 1) << 5 | (uint)(SUB321(auVar2 >> 0x37,0) & 1) << 6
              | (uint)(SUB321(auVar2 >> 0x3f,0) & 1) << 7 |
              (uint)(SUB321(auVar2 >> 0x47,0) & 1) << 8 | (uint)(SUB321(auVar2 >> 0x4f,0) & 1) << 9
              | (uint)(SUB321(auVar2 >> 0x57,0) & 1) << 10 |
              (uint)(SUB321(auVar2 >> 0x5f,0) & 1) << 0xb |
              (uint)(SUB321(auVar2 >> 0x67,0) & 1) << 0xc |
              (uint)(SUB321(auVar2 >> 0x6f,0) & 1) << 0xd |
              (uint)(SUB321(auVar2 >> 0x77,0) & 1) << 0xe | (uint)SUB321(auVar2 >> 0x7f,0) << 0xf |
              (uint)(SUB321(auVar2 >> 0x87,0) & 1) << 0x10 |
              (uint)(SUB321(auVar2 >> 0x8f,0) & 1) << 0x11 |
              (uint)(SUB321(auVar2 >> 0x97,0) & 1) << 0x12 |
              (uint)(SUB321(auVar2 >> 0x9f,0) & 1) << 0x13 |
              (uint)(SUB321(auVar2 >> 0xa7,0) & 1) << 0x14 |
              (uint)(SUB321(auVar2 >> 0xaf,0) & 1) << 0x15 |
              (uint)(SUB321(auVar2 >> 0xb7,0) & 1) << 0x16 | (uint)SUB321(auVar2 >> 0xbf,0) << 0x17
              | (uint)(SUB321(auVar2 >> 199,0) & 1) << 0x18 |
              (uint)(SUB321(auVar2 >> 0xcf,0) & 1) << 0x19 |
              (uint)(SUB321(auVar2 >> 0xd7,0) & 1) << 0x1a |
              (uint)(SUB321(auVar2 >> 0xdf,0) & 1) << 0x1b |
              (uint)(SUB321(auVar2 >> 0xe7,0) & 1) << 0x1c |
              (uint)(SUB321(auVar2 >> 0xef,0) & 1) << 0x1d |
              (uint)(SUB321(auVar2 >> 0xf7,0) & 1) << 0x1e | (uint)(byte)(auVar2[0x1f] >> 7) << 0x1f
      ;
      if (uVar8 != 0xffffffff) {
        uVar8 = ~uVar8;
        uVar5 = 0;
        if (uVar8 != 0) {
          for (; (uVar8 >> uVar5 & 1) == 0; uVar5 = uVar5 + 1) {
          }
        }
        if (*(ushort *)(*param_2 + ((uVar5 >> 1) + uVar3) * 2) <=
            *(ushort *)(*param_1 + ((uVar5 >> 1) + uVar3) * 2)) {
          return 1;
        }
        return 0xffffffff;
      }
      uVar3 = uVar3 + 0x10;
      uVar6 = uVar6 + 0x10;
      pauVar9 = pauVar9 + 1;
      pauVar10 = pauVar10 + 1;
      uVar4 = uVar3;
    } while (uVar6 <= param_3);
  }
  while (uVar4 + 8 <= param_3) {
    auVar11._0_2_ = -(ushort)(*(short *)*pauVar9 == *(short *)*pauVar10);
    auVar11._2_2_ = -(ushort)(*(short *)(*pauVar9 + 2) == *(short *)(*pauVar10 + 2));
    auVar11._4_2_ = -(ushort)(*(short *)(*pauVar9 + 4) == *(short *)(*pauVar10 + 4));
    auVar11._6_2_ = -(ushort)(*(short *)(*pauVar9 + 6) == *(short *)(*pauVar10 + 6));
    auVar11._8_2_ = -(ushort)(*(short *)(*pauVar9 + 8) == *(short *)(*pauVar10 + 8));
    auVar11._10_2_ = -(ushort)(*(short *)(*pauVar9 + 10) == *(short *)(*pauVar10 + 10));
    auVar11._12_2_ = -(ushort)(*(short *)(*pauVar9 + 0xc) == *(short *)(*pauVar10 + 0xc));
    auVar11._14_2_ = -(ushort)(*(short *)(*pauVar9 + 0xe) == *(short *)(*pauVar10 + 0xe));
    uVar1 = (ushort)(SUB161(auVar11 >> 7,0) & 1) | (ushort)(SUB161(auVar11 >> 0xf,0) & 1) << 1 |
            (ushort)(SUB161(auVar11 >> 0x17,0) & 1) << 2 |
            (ushort)(SUB161(auVar11 >> 0x1f,0) & 1) << 3 |
            (ushort)(SUB161(auVar11 >> 0x27,0) & 1) << 4 |
            (ushort)(SUB161(auVar11 >> 0x2f,0) & 1) << 5 |
            (ushort)(SUB161(auVar11 >> 0x37,0) & 1) << 6 |
            (ushort)(SUB161(auVar11 >> 0x3f,0) & 1) << 7 |
            (ushort)(SUB161(auVar11 >> 0x47,0) & 1) << 8 |
            (ushort)(SUB161(auVar11 >> 0x4f,0) & 1) << 9 |
            (ushort)(SUB161(auVar11 >> 0x57,0) & 1) << 10 |
            (ushort)(SUB161(auVar11 >> 0x5f,0) & 1) << 0xb |
            (ushort)(SUB161(auVar11 >> 0x67,0) & 1) << 0xc |
            (ushort)(SUB161(auVar11 >> 0x6f,0) & 1) << 0xd |
            (ushort)((byte)(auVar11._14_2_ >> 7) & 1) << 0xe | auVar11._14_2_ & 0x8000;
    if (uVar1 != 0xffff) {
      uVar5 = ~(uint)uVar1;
      uVar8 = 0;
      if (uVar5 != 0) {
        for (; (uVar5 >> uVar8 & 1) == 0; uVar8 = uVar8 + 1) {
        }
      }
      if (*(ushort *)(*param_2 + ((uVar8 >> 1) + uVar3) * 2) <=
          *(ushort *)(*param_1 + ((uVar8 >> 1) + uVar3) * 2)) {
        return 1;
      }
      return 0xffffffff;
    }
    uVar3 = uVar3 + 8;
    pauVar9 = (undefined1 (*) [32])(*pauVar9 + 0x10);
    pauVar10 = (undefined1 (*) [32])(*pauVar10 + 0x10);
    uVar4 = uVar4 + 8;
  }
  uVar4 = uVar3;
  if (uVar3 + 4 <= param_3) {
    uVar4 = uVar3 + 4;
    if (*(ulonglong *)*pauVar9 != *(ulonglong *)*pauVar10) {
      uVar6 = *(ulonglong *)*pauVar10 ^ *(ulonglong *)*pauVar9;
      uVar4 = 0;
      if (uVar6 != 0) {
        for (; (uVar6 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
        }
      }
      if (*(ushort *)(*param_2 + ((uVar4 >> 4) + uVar3) * 2) <=
          *(ushort *)(*param_1 + ((uVar4 >> 4) + uVar3) * 2)) {
        return 1;
      }
      return 0xffffffff;
    }
  }
  if (uVar4 < param_3) {
    puVar7 = (ushort *)(*param_1 + uVar4 * 2);
    do {
      uVar1 = *(ushort *)(((longlong)param_2 - (longlong)param_1) + (longlong)puVar7);
      if (*puVar7 != uVar1) {
        if (uVar1 <= *puVar7) {
          return 1;
        }
        return 0xffffffff;
      }
      uVar4 = uVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar4 < param_3);
  }
  return 0;
}



// ===== [target] FUN_1400013e0 @ 1400013e0 =====

void FUN_1400013e0(void)

{
  longlong local_28 [5];
  
  FUN_1400013b0(local_28);
                    /* WARNING: Subroutine does not return */
  FUN_1400bd258(local_28,&DAT_1400e0810);
}



// ==== functions referencing RTTI 0xe5400-0xe56d0 ====

// ==== callers of interesting imports ====
//   GetModuleFileNameW <- ? (from 1400d5188)
//   GetModuleFileNameW <- FUN_1400c7e44 @ 1400c7e44 (from 1400c7e94)
//   CreateFileW <- ? (from 1400d5010)
//   CreateFileW <- __dcrt_lowio_ensure_console_output_initialized @ 1400d2064 (from 1400d209a)
//   CreateFileW <- __dcrt_write_console @ 1400d20d4 (from 1400d2154)
//   ReadFile: symbol not found
//   SetFilePointerEx <- ? (from 1400d5068)
//   SetFilePointerEx <- FUN_1400d15e8 @ 1400d15e8 (from 1400d163a)
//   SetFilePointer: symbol not found
//   GetFileSize: symbol not found
//   MapViewOfFile: symbol not found
//   CreateFileMappingW: symbol not found
//   TrySubmitThreadpoolCallback: symbol not found
//   CryptDecrypt: symbol not found
//   CryptAcquireContextW: symbol not found
//   BCryptOpenAlgorithmProvider: symbol not found
//   WinVerifyTrust: symbol not found
//   CryptDecodeObjectEx: symbol not found
//   CertCreateCertificateContext: symbol not found
//   CryptHashData: symbol not found
//   GetModuleFileNameA: symbol not found
//   LoadResource: symbol not found
//   FindResourceW: symbol not found
//   VirtualAlloc: symbol not found
