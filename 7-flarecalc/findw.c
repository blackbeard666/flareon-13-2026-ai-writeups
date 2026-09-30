
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



// ===== FUN_140003b20 @ 140003b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_140003b20(HWND param_1,UINT param_2,WPARAM param_3,ulonglong *param_4)

{
  ushort *puVar1;
  undefined8 *puVar2;
  LRESULT LVar3;
  ulonglong uVar4;
  undefined1 (*pauVar5) [32];
  longlong lVar6;
  code *pcVar7;
  ushort *puVar8;
  undefined8 *******pppppppuVar9;
  HMODULE pHVar10;
  HFONT pHVar11;
  HWND hWnd;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ushort **ppuVar18;
  ushort uVar19;
  ulonglong uVar20;
  int iVar21;
  ulonglong uVar22;
  undefined1 *puVar23;
  undefined2 *puVar24;
  longlong lVar25;
  undefined **ppuVar26;
  double dVar27;
  longlong *****ppppplVar28;
  undefined8 uVar29;
  undefined8 in_XMM1_Qa;
  undefined1 auStackY_2b8 [32];
  undefined *local_238;
  undefined4 local_230 [2];
  undefined *local_228;
  undefined4 local_220;
  undefined *local_218;
  undefined4 local_210;
  undefined *local_208;
  undefined4 local_200;
  undefined *local_1f8;
  undefined4 local_1f0;
  undefined *local_1e8;
  undefined4 local_1e0;
  undefined *local_1d8;
  undefined4 local_1d0;
  undefined *local_1c8;
  undefined4 local_1c0;
  undefined *local_1b8;
  undefined4 local_1b0;
  undefined *local_1a8;
  undefined4 local_1a0;
  undefined *local_198;
  undefined4 local_190;
  undefined *local_188;
  undefined4 local_180;
  undefined *local_178;
  undefined4 local_170;
  undefined *local_168;
  undefined4 local_160;
  undefined *local_158;
  undefined4 local_150;
  undefined *local_148;
  undefined4 local_140;
  undefined *local_138;
  undefined4 local_130;
  undefined *local_128;
  undefined4 local_120;
  undefined *local_118;
  undefined4 local_110;
  undefined *local_108;
  undefined4 local_100;
  undefined8 *******local_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  ulonglong local_e0;
  undefined1 (*local_d8) [32];
  undefined8 uStack_d0;
  ulonglong local_c8;
  ulonglong local_c0;
  ushort *local_b8;
  ushort *puStack_b0;
  ushort *local_a8;
  ushort *local_a0;
  ushort *puStack_98;
  ushort *local_90;
  undefined4 local_88;
  short local_80 [8];
  short local_70 [8];
  ulonglong local_60;
  
  local_60 = DAT_1400e2040 ^ (ulonglong)auStackY_2b8;
  if (param_2 == ((int)DAT_1400e9228 + 0x24ac062aU ^ 0x24ac0660)) {
    iVar21 = 0;
    iVar12 = 0;
    do {
      iVar12 = iVar12 + 1;
    } while (iVar12 < 6);
    FUN_140070480();
    iVar12 = 0;
    do {
      iVar12 = iVar12 + 1;
    } while (iVar12 < 5);
    if (param_4 == (ulonglong *)0x0) {
      return 0;
    }
    uVar20 = *param_4;
    FUN_14005dc50();
    if (uVar20 != (DAT_1400e9228 + 0x2ef3157b536cabebU ^ 0x2ef3157b909d8160)) {
      return 0;
    }
    puVar2 = (undefined8 *)param_4[2];
    _DAT_1400e8f20 = _DAT_1400dded0;
    uRam00000001400e8f28 = _UNK_1400dded8;
    FUN_1400724a0();
    FUN_1400b72d0();
    lVar25 = -1;
    do {
      lVar25 = lVar25 + 1;
    } while (*(char *)((longlong)puVar2 + lVar25) != '\0');
    FUN_140098210();
    iVar12 = (int)lVar25;
    if (0x78 < iVar12) {
      iVar12 = 0x78;
    }
    uVar20 = (ulonglong)iVar12;
    FUN_1400d2fa0((undefined8 *)&DAT_1400e8f30,puVar2,uVar20);
    FUN_140045de0();
    uVar29 = _UNK_1400dded8;
    iVar13 = 0;
    do {
      iVar13 = iVar13 + 1;
    } while (iVar13 < 0xc);
    iVar13 = 0;
    do {
      iVar13 = iVar13 + 1;
    } while (iVar13 < 9);
    *(undefined8 *)(&DAT_1400e8f30 + uVar20) = _DAT_1400dded0;
    *(undefined8 *)(uVar20 + 0x1400e8f38) = uVar29;
    FUN_140052ad0();
    FUN_140052ad0();
    FUN_140063c50();
    if (uVar20 + 0x20 < 0x100) {
      *(undefined1 *)(uVar20 + 0x1400e8f40) = 0;
      FUN_14001a770();
      FUN_140031800();
      iVar13 = 0;
      do {
        iVar13 = iVar13 + 1;
      } while (iVar13 < 0xc);
      iVar13 = 0;
      do {
        iVar13 = iVar13 + 1;
      } while (iVar13 < 8);
      iVar13 = 0;
      do {
        iVar13 = iVar13 + 1;
      } while (iVar13 < 10);
      DAT_1400e8ec0 = 0;
      DAT_1400e8f10 = iVar12 + 0x20;
      FUN_1400afaf0();
      DAT_1400e8f00 = 1;
      iVar12 = 0;
      do {
        iVar12 = iVar12 + 1;
      } while (iVar12 < 3);
      SetTimer(param_1,3,0x96,(TIMERPROC)0x0);
      iVar12 = 0;
      do {
        iVar12 = iVar12 + 1;
      } while (iVar12 < 0xd);
      iVar12 = 0;
      do {
        iVar12 = iVar12 + 1;
      } while (iVar12 < 10);
      do {
        iVar21 = iVar21 + 1;
      } while (iVar21 < 0xb);
      return 1;
    }
  }
  else {
    if (param_2 == 1) {
      pHVar10 = GetModuleHandleW((LPCWSTR)0x0);
      uVar22 = 0;
      DAT_1400e9230 =
           CreateWindowExW(0x200,L"EDIT",L"0",0x50000802,10,10,0x104,0x28,param_1,(HMENU)0x64,
                           pHVar10,(LPVOID)0x0);
      uVar20 = uVar22;
      do {
        uVar14 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar14;
        uVar17 = uVar22;
      } while ((int)uVar14 < 0xd);
      do {
        uVar14 = (int)uVar17 + 1;
        uVar17 = (ulonglong)uVar14;
      } while ((int)uVar14 < 0xc);
      pHVar11 = CreateFontW(0x1c,0,0,0,0,0,0,0,0,4,0,0,0,L"Arial");
      SendMessageW(DAT_1400e9230,0x30,(WPARAM)pHVar11,1);
      uVar20 = uVar22;
      do {
        uVar14 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar14;
      } while ((int)uVar14 < 6);
      FUN_14006c4e0();
      local_238 = &DAT_1400ddbd8;
      local_230[0] = 300;
      local_228 = &DAT_1400ddbe0;
      local_220 = 0x12d;
      local_218 = &DAT_1400ddbe8;
      local_210 = 0x12e;
      local_208 = &DAT_1400ddbf0;
      local_200 = 0x12f;
      local_1f8 = &DAT_1400ddbf8;
      local_1f0 = 0xcf;
      local_1e8 = &DAT_1400ddbfc;
      local_1e0 = 0xd0;
      local_1d8 = &DAT_1400ddc00;
      local_1d0 = 0xd1;
      local_1c8 = &DAT_1400ddc04;
      local_1c0 = 0xd5;
      local_1b8 = &DAT_1400ddc08;
      local_1b0 = 0xcc;
      local_1a8 = &DAT_1400ddc0c;
      local_1a0 = 0xcd;
      local_198 = &DAT_1400ddc10;
      local_190 = 0xce;
      local_188 = &DAT_1400ddc14;
      local_180 = 0xd4;
      local_178 = &DAT_1400ddc18;
      local_170 = 0xc9;
      local_168 = &DAT_1400ddc1c;
      local_160 = 0xca;
      local_158 = &DAT_1400ddc20;
      local_150 = 0xcb;
      local_148 = &DAT_1400ddc24;
      local_140 = 0xd3;
      local_138 = &DAT_1400ddc28;
      local_130 = 0xd7;
      local_128 = &DAT_1400ddbb0;
      local_120 = 200;
      local_118 = &DAT_1400ddc2c;
      local_110 = 0xd6;
      local_108 = &DAT_1400ddc30;
      local_100 = 0xd2;
      ppuVar26 = &local_238;
      uVar20 = uVar22;
      do {
        uVar17 = uVar22;
        do {
          uVar14 = (int)uVar17 + 1;
          uVar17 = (ulonglong)uVar14;
        } while ((int)uVar14 < 4);
        uVar17 = uVar22;
        do {
          uVar14 = (int)uVar17 + 1;
          uVar17 = (ulonglong)uVar14;
        } while ((int)uVar14 < 0xf);
        uVar17 = uVar22;
        do {
          uVar14 = (int)uVar17 + 1;
          uVar17 = (ulonglong)uVar14;
        } while ((int)uVar14 < 7);
        FUN_14000fee0();
        uVar17 = uVar22;
        do {
          uVar14 = (int)uVar17 + 1;
          uVar17 = (ulonglong)uVar14;
        } while ((int)uVar14 < 8);
        FUN_140042aa0();
        FUN_14007a010();
        FUN_14002f930();
        pHVar10 = GetModuleHandleW((LPCWSTR)0x0);
        hWnd = CreateWindowExW(0,L"BUTTON",(LPCWSTR)*ppuVar26,0x50000000,
                               ((uint)uVar20 & 3) * 0x41 + 10,(int)(uVar20 >> 2) * 0x37 + 0x3c,0x3c,
                               0x32,param_1,(HMENU)(longlong)*(int *)(ppuVar26 + 1),pHVar10,
                               (LPVOID)0x0);
        uVar17 = uVar22;
        do {
          uVar14 = (int)uVar17 + 1;
          uVar17 = (ulonglong)uVar14;
        } while ((int)uVar14 < 0xe);
        pHVar11 = CreateFontW(0x10,0,0,0,700,0,0,0,0,4,0,0,0,L"Arial");
        SendMessageW(hWnd,0x30,(WPARAM)pHVar11,1);
        FUN_1400940f0();
        FUN_14006ec80();
        uVar17 = uVar22;
        do {
          uVar14 = (int)uVar17 + 1;
          uVar17 = (ulonglong)uVar14;
        } while ((int)uVar14 < 10);
        uVar14 = (uint)uVar20 + 1;
        uVar20 = (ulonglong)uVar14;
        ppuVar26 = ppuVar26 + 2;
      } while ((int)uVar14 < 0x14);
      return 0;
    }
    if (param_2 == 2) {
      PostQuitMessage(0);
      FUN_1400b41b0();
      FUN_140067500();
      FUN_14006b4e0();
      return 0;
    }
    if (param_2 != 0x111) {
      if (param_2 != 0x113) {
        LVar3 = DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
        return LVar3;
      }
      if (param_3 != 3) {
        return 0;
      }
      if (DAT_1400e8f00 == 0) {
        return 0;
      }
      uVar17 = 0;
      uVar20 = uVar17;
      uVar22 = uVar17;
      if (DAT_1400e8f10 + -0x10 < DAT_1400e8ec0) {
        DAT_1400e8ec0 = 0;
        uVar4 = uVar17;
        do {
          uVar14 = (int)uVar4 + 1;
          uVar4 = (ulonglong)uVar14;
        } while ((int)uVar14 < 0xd);
      }
      do {
        *(undefined1 *)((longlong)&local_b8 + uVar22) =
             (&DAT_1400e8f20)[DAT_1400e8ec0 + (int)uVar20];
        FUN_14005dc50();
        uVar4 = uVar17;
        do {
          uVar14 = (int)uVar4 + 1;
          uVar4 = (ulonglong)uVar14;
        } while ((int)uVar14 < 0xc);
        FUN_140052760();
        uVar22 = uVar22 + 1;
        uVar20 = (ulonglong)((int)uVar20 + 1);
      } while ((longlong)uVar22 < 0x10);
      local_a8 = (ushort *)((ulonglong)local_a8 & 0xffffffffffffff00);
      uVar20 = uVar17;
      do {
        uVar14 = (int)uVar20 + 1;
        uVar20 = (ulonglong)uVar14;
      } while ((int)uVar14 < 7);
      FUN_1400af0b0();
      do {
        uVar14 = (int)uVar17 + 1;
        uVar17 = (ulonglong)uVar14;
      } while ((int)uVar14 < 8);
      SetWindowTextA(DAT_1400e9230,(LPCSTR)&local_b8);
      FUN_14003c890();
      ppuVar18 = &local_b8;
      for (lVar25 = 0x11; lVar25 != 0; lVar25 = lVar25 + -1) {
        *(undefined1 *)ppuVar18 = 0;
        ppuVar18 = (ushort **)((longlong)ppuVar18 + 1);
      }
      DAT_1400e8ec0 = DAT_1400e8ec0 + 1;
      return 0;
    }
    uVar19 = (ushort)param_3;
    if (DAT_1400e8f00 != 0) {
      if (uVar19 != (ushort)((short)DAT_1400e9228 + 0x7dd7U ^ 32000)) {
        return 0;
      }
      iVar21 = 0;
      DAT_1400e8f00 = 0;
      FUN_14003b9c0();
      FUN_140099db0();
      KillTimer(param_1,3);
      iVar12 = 0;
      do {
        iVar12 = iVar12 + 1;
      } while (iVar12 < 9);
      SetWindowTextA(DAT_1400e9230,"0");
      FUN_140043ab0();
      FUN_1400474c0();
      puVar23 = &DAT_1400e8f20;
      for (lVar25 = 0x100; lVar25 != 0; lVar25 = lVar25 + -1) {
        *puVar23 = 0;
        puVar23 = puVar23 + 1;
      }
      FUN_14002a700();
      iVar12 = 0;
      do {
        iVar12 = iVar12 + 1;
      } while (iVar12 < 7);
      DAT_1400e8ec0 = 0;
      FUN_14005cb50();
      FUN_14007a700();
      FUN_1400abaa0();
      DAT_1400e8f10 = 0;
      do {
        iVar21 = iVar21 + 1;
      } while (iVar21 < 0xf);
      FUN_1400a1ed0();
      FUN_14004dd50();
      return 0;
    }
    FUN_140057270();
    iVar21 = 0;
    iVar12 = iVar21;
    do {
      iVar12 = iVar12 + 1;
    } while (iVar12 < 3);
    if ((ushort)(uVar19 - 200) < 10) {
      if ((DAT_1400e8ec4 != '\0') || ((DAT_1400e2a80 == 0x30 && (DAT_1400e2a82 == 0)))) {
        DAT_1400e2a80 = 0;
        FUN_14001a770();
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xd);
        DAT_1400e8ec4 = '\0';
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
          iVar13 = iVar21;
        } while (iVar12 < 3);
        do {
          iVar13 = iVar13 + 1;
        } while (iVar13 < 4);
      }
      uVar22 = 0xffffffffffffffff;
      uVar20 = 0xffffffffffffffff;
      do {
        uVar20 = uVar20 + 1;
        iVar12 = iVar21;
      } while ((&DAT_1400e2a80)[uVar20] != 0);
      do {
        iVar12 = iVar12 + 1;
      } while (iVar12 < 6);
      FUN_1400a0120();
      iVar12 = iVar21;
      do {
        iVar12 = iVar12 + 1;
      } while (iVar12 < 6);
      if (uVar20 < 0x3c) {
        (&DAT_1400e2a80)[uVar20] = uVar19 - 0x98;
        FUN_140034ef0();
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
          iVar13 = iVar21;
        } while (iVar12 < 6);
        do {
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0xc);
        if (0x7f < uVar20 * 2 + 2) goto LAB_140005fad;
        (&DAT_1400e2a82)[uVar20] = 0;
        FUN_140010a30();
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xe);
      }
      do {
        uVar22 = uVar22 + 1;
        iVar12 = iVar21;
      } while ((&DAT_1400e9020)[uVar22] != 0);
      do {
        iVar12 = iVar12 + 1;
        iVar13 = iVar21;
      } while (iVar12 < 0xb);
      do {
        iVar13 = iVar13 + 1;
        iVar12 = iVar21;
      } while (iVar13 < 3);
      do {
        iVar12 = iVar12 + 1;
      } while (iVar12 < 8);
      if (0xf9 < uVar22) {
LAB_14000434a:
        if (DAT_1400e9230 != (HWND)0x0) {
          SetWindowTextW(DAT_1400e9230,&DAT_1400e2a80);
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
            iVar13 = iVar21;
          } while (iVar12 < 0xe);
          do {
            iVar13 = iVar13 + 1;
            iVar12 = iVar21;
          } while (iVar13 < 0xf);
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 3);
        }
        do {
          iVar21 = iVar21 + 1;
        } while (iVar21 < 0xe);
        return 0;
      }
      (&DAT_1400e9020)[uVar22] = uVar19 - 0x98;
      iVar12 = iVar21;
      do {
        iVar12 = iVar12 + 1;
        iVar13 = iVar21;
      } while (iVar12 < 0xb);
      do {
        iVar13 = iVar13 + 1;
      } while (iVar13 < 3);
      FUN_140018c30();
      if (uVar22 * 2 + 2 < 0x200) {
        (&DAT_1400e9022)[uVar22] = 0;
        FUN_14005c7e0();
        FUN_140054aa0();
        goto LAB_14000434a;
      }
    }
    else {
      if (uVar19 == 0xd7) {
        DAT_1400e2a80 = 0x30;
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
          iVar13 = iVar21;
        } while (iVar12 < 0xb);
        do {
          iVar13 = iVar13 + 1;
          iVar12 = iVar21;
        } while (iVar13 < 2);
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 8);
        DAT_1400e2a82 = 0;
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xb);
        FUN_1400a79a0();
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 4);
        DAT_1400e8f08 = 0;
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
          iVar13 = iVar21;
        } while (iVar12 < 4);
        do {
          iVar13 = iVar13 + 1;
        } while (iVar13 < 3);
        DAT_1400e8f04 = 0;
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xb);
        FUN_1400adfa0();
        FUN_14003b530();
        DAT_1400e8ec4 = '\0';
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xf);
        DAT_1400e9020 = 0;
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 5);
        if (DAT_1400e9230 != (HWND)0x0) {
          SetWindowTextW(DAT_1400e9230,&DAT_1400e2a80);
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
            iVar13 = iVar21;
          } while (iVar12 < 0xe);
          do {
            iVar13 = iVar13 + 1;
          } while (iVar13 < 0xf);
          do {
            iVar21 = iVar21 + 1;
          } while (iVar21 < 3);
        }
        FUN_140028a80();
        return 0;
      }
      if ((3 < (ushort)(uVar19 - 0xd2)) && (2 < (ushort)(uVar19 - 300))) {
        if (uVar19 == 0x12f) {
          dVar27 = (double)FUN_1400c4d1c(0x1400e2a80);
          FUN_140073c90();
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 9);
          FUN_140059a60();
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 7);
          FUN_1400010d0(&DAT_1400e2a80,0x40,0x1400ddc50,~(longlong)dVar27);
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
            iVar13 = iVar21;
          } while (iVar12 < 4);
          do {
            iVar13 = iVar13 + 1;
          } while (iVar13 < 2);
          uVar20 = 0xffffffffffffffff;
          do {
            uVar20 = uVar20 + 1;
          } while ((&DAT_1400e9020)[uVar20] != 0);
          FUN_1400b0090();
          if (uVar20 < 0xfa) {
            FUN_1400c4db0(&DAT_1400e9020,0x100,0x1400ddc5c);
            FUN_14009a920();
            FUN_140064e60();
          }
          if (DAT_1400e9230 != (HWND)0x0) {
            SetWindowTextW(DAT_1400e9230,&DAT_1400e2a80);
            iVar12 = iVar21;
            do {
              iVar12 = iVar12 + 1;
              iVar13 = iVar21;
            } while (iVar12 < 0xe);
            do {
              iVar13 = iVar13 + 1;
              iVar12 = iVar21;
            } while (iVar13 < 0xf);
            do {
              iVar12 = iVar12 + 1;
            } while (iVar12 < 3);
          }
          do {
            iVar21 = iVar21 + 1;
          } while (iVar21 < 0xb);
          return 0;
        }
        if (uVar19 != 0xd6) {
          return 0;
        }
        FUN_140032a90();
        uStack_f0 = 0;
        local_e8 = 0;
        local_e0 = 7;
        local_f8 = (undefined8 *******)0x0;
        local_80[0] = 0x35;
        local_80[1] = 0x32;
        local_80[2] = 0x35;
        local_80[3] = 0x2b;
        local_80[4] = 0x31;
        local_80[5] = 0x39;
        local_80[6] = 0x33;
        local_80[7] = 0;
        local_70[0] = 0x37;
        local_70[1] = 0x34;
        local_70[2] = 0x32;
        local_70[3] = 0x2a;
        local_70[4] = 0x31;
        local_70[5] = 0x38;
        local_70[6] = 0x36;
        local_70[7] = 0;
        local_a0 = (ushort *)0x2d003100330039;
        puStack_98 = (ushort *)0x3200380034;
        local_b8 = (ushort *)0x2a003300340038;
        puStack_b0 = (ushort *)0x3200350039;
        local_d8 = (undefined1 (*) [32])0x0;
        uStack_d0 = 0;
        local_c8 = 0;
        local_c0 = 0;
        uVar22 = 0xffffffffffffffff;
        uVar20 = 0xffffffffffffffff;
        do {
          uVar17 = uVar20;
          uVar20 = uVar17 + 1;
        } while ((&DAT_1400e9020)[uVar20] != 0);
        if (0x7ffffffffffffffe < uVar20) {
          FUN_140001480();
          pcVar7 = (code *)swi(3);
          LVar3 = (*pcVar7)();
          return LVar3;
        }
        iVar12 = iVar21;
        if (uVar20 < 8) {
          local_c0 = 7;
          local_c8 = uVar20;
          FUN_1400d2fa0(&local_d8,(undefined8 *)&DAT_1400e9020,uVar20 * 2);
          *(undefined2 *)((longlong)&local_d8 + uVar20 * 2) = 0;
        }
        else {
          uVar4 = uVar20 | 7;
          if (uVar4 < 0x7fffffffffffffff) {
            if (uVar4 < 10) {
              uVar4 = 10;
            }
            uVar16 = uVar4 + 1;
            if (0x7fffffffffffffff < uVar16) goto LAB_140005fb3;
          }
          else {
            uVar16 = 0x7fffffffffffffff;
            uVar4 = 0x7ffffffffffffffe;
          }
          pauVar5 = (undefined1 (*) [32])FUN_140008140(uVar16 * 2);
          uVar17 = uVar17 * 2 + 2;
          local_d8 = pauVar5;
          local_c8 = uVar20;
          local_c0 = uVar4;
          FUN_1400d2fa0((undefined8 *)pauVar5,(undefined8 *)&DAT_1400e9020,uVar17);
          *(undefined2 *)((longlong)*pauVar5 + uVar17) = 0;
        }
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 9);
        FUN_140027290();
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 3);
        uVar20 = 0xffffffffffffffff;
        do {
          uVar20 = uVar20 + 1;
        } while (local_80[uVar20] != 0);
        pauVar5 = (undefined1 (*) [32])&local_d8;
        if (7 < local_c0) {
          pauVar5 = local_d8;
        }
        if ((local_c8 == uVar20) &&
           ((local_c8 == 0 ||
            (iVar12 = FUN_140001130(pauVar5,(undefined1 (*) [32])local_80,local_c8), iVar12 == 0))))
        {
          local_b8 = (ushort *)0x0;
          puStack_b0 = (ushort *)0x0;
          local_a0 = (ushort *)0x6c0074007e0073;
          puStack_98 = (ushort *)0x76007a0077004a;
          local_90 = (ushort *)0x63007f006a0077;
          local_88 = 0x4e0060;
          puVar8 = (ushort *)FUN_140008140(0x1c);
          puVar1 = puVar8 + 0xe;
          uVar29 = 0x1c;
          local_b8 = puVar8;
          local_a8 = puVar1;
          FUN_1400d2fa0((undefined8 *)puVar8,&local_a0,0x1c);
          puStack_b0 = puVar1;
          FUN_14006fee0();
          uVar20 = local_e8;
          if (local_e8 < 0xe) {
            uVar22 = 0xe - local_e8;
            if (local_e0 - local_e8 < uVar22) {
              FUN_140007930(&local_f8,uVar22,uVar29,uVar22);
            }
            else {
              local_e8 = 0xe;
              pppppppuVar9 = &local_f8;
              if (7 < local_e0) {
                pppppppuVar9 = local_f8;
              }
              puVar24 = (undefined2 *)((longlong)pppppppuVar9 + uVar20 * 2);
              if (uVar22 != 0) {
                for (; uVar22 != 0; uVar22 = uVar22 - 1) {
                  *puVar24 = 0;
                  puVar24 = puVar24 + 1;
                }
              }
              *(undefined2 *)((longlong)pppppppuVar9 + 0x1c) = 0;
            }
          }
          else {
            local_e8 = 0xe;
            pppppppuVar9 = &local_f8;
            if (7 < local_e0) {
              pppppppuVar9 = local_f8;
            }
            *(undefined2 *)((longlong)pppppppuVar9 + 0x1c) = 0;
          }
          pppppppuVar9 = &local_f8;
          if (7 < local_e0) {
            pppppppuVar9 = local_f8;
          }
          iVar12 = iVar21;
          if (puVar8 != puVar1) {
            lVar25 = (longlong)pppppppuVar9 - (longlong)puVar8;
            iVar13 = iVar21;
            do {
              iVar15 = iVar13 % 7;
              iVar13 = iVar13 + 1;
              pauVar5 = (undefined1 (*) [32])&local_d8;
              if (7 < local_c0) {
                pauVar5 = local_d8;
              }
              *(ushort *)(lVar25 + (longlong)puVar8) =
                   *puVar8 ^ *(ushort *)((longlong)*pauVar5 + (longlong)iVar15 * 2);
              puVar8 = puVar8 + 1;
            } while (puVar8 != puVar1);
          }
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 0xb);
          FUN_140012580();
          FUN_1400ad9e0();
          ppuVar18 = &local_b8;
LAB_14000540f:
          FUN_1400072d0((longlong *)ppuVar18);
          pppppppuVar9 = &local_f8;
          if (7 < local_e0) {
            pppppppuVar9 = local_f8;
          }
          FUN_1400c7570(&DAT_1400e2a80,0x40,(longlong)pppppppuVar9,-1);
          FUN_14006cf00();
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 10);
          FUN_140054ce0();
          DAT_1400e8f04 = 0;
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 0xc);
          FUN_1400189f0();
          DAT_1400e8ec4 = '\x01';
          FUN_1400a2d90();
          DAT_1400e9020 = 0;
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 10);
          FUN_1400618f0();
          FUN_140099910();
          if (DAT_1400e9230 != (HWND)0x0) {
            SetWindowTextW(DAT_1400e9230,&DAT_1400e2a80);
            iVar12 = iVar21;
            do {
              iVar12 = iVar12 + 1;
              iVar13 = iVar21;
            } while (iVar12 < 0xe);
            do {
              iVar13 = iVar13 + 1;
            } while (iVar13 < 0xf);
            do {
              iVar21 = iVar21 + 1;
            } while (iVar21 < 3);
          }
LAB_140005747:
          if (7 < local_c0) {
            pauVar5 = local_d8;
            if ((0xfff < local_c0 * 2 + 2) &&
               (pauVar5 = *(undefined1 (**) [32])((longlong)local_d8[-1] + 0x18),
               0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)pauVar5)))) {
LAB_140005fd4:
                    /* WARNING: Subroutine does not return */
              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
            }
            thunk_FUN_1400c9460(pauVar5);
          }
          local_d8 = (undefined1 (*) [32])((ulonglong)local_d8 & 0xffffffffffff0000);
          if (local_e0 < 8) {
            return 0;
          }
          pppppppuVar9 = local_f8;
          if (local_e0 * 2 + 2 < 0x1000) goto LAB_140004de5;
          pppppppuVar9 = (undefined8 *******)local_f8[-1];
          uVar20 = (longlong)local_f8 + (-8 - (longlong)pppppppuVar9);
        }
        else {
          uVar20 = 0xffffffffffffffff;
          do {
            uVar20 = uVar20 + 1;
          } while (local_70[uVar20] != 0);
          pauVar5 = (undefined1 (*) [32])&local_d8;
          if (7 < local_c0) {
            pauVar5 = local_d8;
          }
          if ((local_c8 == uVar20) &&
             ((local_c8 == 0 ||
              (iVar12 = FUN_140001130(pauVar5,(undefined1 (*) [32])local_70,local_c8), iVar12 == 0))
             )) {
            local_b8 = (ushort *)0x0;
            puStack_b0 = (ushort *)0x0;
            local_a0 = (ushort *)0x6f007100770076;
            puStack_98 = (ushort *)0x730016006b0062;
            local_90 = (ushort *)0x740063007c0071;
            local_88._0_2_ = 0x7c;
            puVar8 = (ushort *)FUN_140008140(0x1a);
            puVar1 = puVar8 + 0xd;
            uVar29 = 0x1a;
            local_b8 = puVar8;
            local_a8 = puVar1;
            FUN_1400d2fa0((undefined8 *)puVar8,&local_a0,0x1a);
            iVar12 = iVar21;
            do {
              iVar12 = iVar12 + 1;
              iVar13 = iVar21;
            } while (iVar12 < 10);
            do {
              iVar13 = iVar13 + 1;
            } while (iVar13 < 8);
            puStack_b0 = puVar1;
            FUN_1400ad0a0();
            uVar20 = (longlong)puVar1 - (longlong)puVar8 >> 1;
            if (local_e8 < uVar20) {
              uVar22 = uVar20 - local_e8;
              if (local_e0 - local_e8 < uVar22) {
                FUN_140007930(&local_f8,uVar22,uVar29,uVar22);
              }
              else {
                pppppppuVar9 = &local_f8;
                if (7 < local_e0) {
                  pppppppuVar9 = local_f8;
                }
                puVar24 = (undefined2 *)((longlong)pppppppuVar9 + local_e8 * 2);
                local_e8 = uVar20;
                if (uVar22 != 0) {
                  for (; uVar22 != 0; uVar22 = uVar22 - 1) {
                    *puVar24 = 0;
                    puVar24 = puVar24 + 1;
                  }
                }
                *(undefined2 *)((longlong)pppppppuVar9 + uVar20 * 2) = 0;
              }
            }
            else {
              pppppppuVar9 = &local_f8;
              if (7 < local_e0) {
                pppppppuVar9 = local_f8;
              }
              local_e8 = uVar20;
              *(undefined2 *)((longlong)pppppppuVar9 + uVar20 * 2) = 0;
            }
            FUN_1400432c0();
            iVar12 = iVar21;
            do {
              iVar12 = iVar12 + 1;
            } while (iVar12 < 0xc);
            FUN_1400aec20();
            pppppppuVar9 = &local_f8;
            if (7 < local_e0) {
              pppppppuVar9 = local_f8;
            }
            iVar12 = iVar21;
            if (puVar8 != puVar1) {
              lVar25 = (longlong)pppppppuVar9 - (longlong)puVar8;
              iVar13 = iVar21;
              do {
                iVar15 = iVar13 % 7;
                iVar13 = iVar13 + 1;
                pauVar5 = (undefined1 (*) [32])&local_d8;
                if (7 < local_c0) {
                  pauVar5 = local_d8;
                }
                *(ushort *)(lVar25 + (longlong)puVar8) =
                     *puVar8 ^ *(ushort *)((longlong)*pauVar5 + (longlong)iVar15 * 2);
                puVar8 = puVar8 + 1;
              } while (puVar8 != puVar1);
            }
            do {
              iVar12 = iVar12 + 1;
            } while (iVar12 < 8);
            FUN_14001ad20();
            FUN_1400af1d0();
            ppuVar18 = &local_b8;
            goto LAB_14000540f;
          }
          uVar20 = 0xffffffffffffffff;
          do {
            uVar20 = uVar20 + 1;
          } while (*(short *)((longlong)&local_a0 + uVar20 * 2) != 0);
          pauVar5 = (undefined1 (*) [32])&local_d8;
          if (7 < local_c0) {
            pauVar5 = local_d8;
          }
          if ((local_c8 == uVar20) &&
             ((local_c8 == 0 ||
              (iVar12 = FUN_140001130(pauVar5,(undefined1 (*) [32])&local_a0,local_c8), iVar12 == 0)
              ))) {
            local_a0 = (ushort *)0x0;
            puStack_98 = (ushort *)0x0;
            local_b8 = (ushort *)0x72006800760072;
            puStack_b0 = (ushort *)0x70006200600071;
            local_a8 = (ushort *)CONCAT26(local_a8._6_2_,0x6900740061);
            puVar8 = (ushort *)FUN_140008140(0x16);
            puVar1 = puVar8 + 0xb;
            uVar29 = 0x16;
            local_a0 = puVar8;
            local_90 = puVar1;
            FUN_1400d2fa0((undefined8 *)puVar8,&local_b8,0x16);
            uVar20 = local_e8;
            puStack_98 = puVar1;
            iVar12 = iVar21;
            do {
              iVar12 = iVar12 + 1;
            } while (iVar12 < 3);
            uVar22 = (longlong)puVar1 - (longlong)puVar8 >> 1;
            iVar12 = iVar21;
            if (local_e8 < uVar22) {
              uVar17 = uVar22 - local_e8;
              if (local_e0 - local_e8 < uVar17) {
                FUN_140007930(&local_f8,uVar17,uVar29,uVar17);
              }
              else {
                local_e8 = uVar22;
                pppppppuVar9 = &local_f8;
                if (7 < local_e0) {
                  pppppppuVar9 = local_f8;
                }
                puVar24 = (undefined2 *)((longlong)pppppppuVar9 + uVar20 * 2);
                if (uVar17 != 0) {
                  for (; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *puVar24 = 0;
                    puVar24 = puVar24 + 1;
                  }
                }
                *(undefined2 *)((longlong)pppppppuVar9 + uVar22 * 2) = 0;
              }
            }
            else {
              local_e8 = uVar22;
              pppppppuVar9 = &local_f8;
              if (7 < local_e0) {
                pppppppuVar9 = local_f8;
              }
              *(undefined2 *)((longlong)pppppppuVar9 + uVar22 * 2) = 0;
            }
            do {
              iVar12 = iVar12 + 1;
            } while (iVar12 < 0xe);
            pppppppuVar9 = &local_f8;
            if (7 < local_e0) {
              pppppppuVar9 = local_f8;
            }
            if (puVar8 != puVar1) {
              lVar25 = (longlong)pppppppuVar9 - (longlong)puVar8;
              iVar12 = iVar21;
              do {
                iVar13 = iVar12 % 7;
                iVar12 = iVar12 + 1;
                pauVar5 = (undefined1 (*) [32])&local_d8;
                if (7 < local_c0) {
                  pauVar5 = local_d8;
                }
                *(ushort *)(lVar25 + (longlong)puVar8) =
                     *puVar8 ^ *(ushort *)((longlong)*pauVar5 + (longlong)iVar13 * 2);
                puVar8 = puVar8 + 1;
              } while (puVar8 != puVar1);
            }
            FUN_140027b90();
            ppuVar18 = &local_a0;
            goto LAB_14000540f;
          }
          do {
            uVar22 = uVar22 + 1;
          } while (*(short *)((longlong)&local_b8 + uVar22 * 2) != 0);
          pauVar5 = (undefined1 (*) [32])&local_d8;
          if (7 < local_c0) {
            pauVar5 = local_d8;
          }
          if ((local_c8 != uVar22) ||
             ((iVar12 = iVar21, local_c8 != 0 &&
              (iVar13 = FUN_140001130(pauVar5,(undefined1 (*) [32])&local_b8,local_c8), iVar13 != 0)
              ))) {
            if (DAT_1400e8f04 != 0) {
              ppppplVar28 = (longlong *****)FUN_1400c4d1c(0x1400e2a80);
              iVar12 = iVar21;
              do {
                iVar12 = iVar12 + 1;
                iVar13 = iVar21;
              } while (iVar12 < 10);
              do {
                iVar13 = iVar13 + 1;
              } while (iVar13 < 0xc);
              uVar29 = FUN_1400148e0();
              uVar29 = FUN_140003a20(uVar29,in_XMM1_Qa,ppppplVar28);
              iVar12 = iVar21;
              do {
                iVar12 = iVar12 + 1;
              } while (iVar12 < 3);
              FUN_1400010d0(&DAT_1400e2a80,0x40,0x1400ddc60,uVar29);
              iVar12 = iVar21;
              do {
                iVar12 = iVar12 + 1;
              } while (iVar12 < 5);
              DAT_1400e8f04 = 0;
              FUN_1400824a0();
              DAT_1400e8ec4 = '\x01';
              iVar12 = iVar21;
              do {
                iVar12 = iVar12 + 1;
              } while (iVar12 < 9);
              DAT_1400e9020 = 0;
              iVar12 = iVar21;
              do {
                iVar12 = iVar12 + 1;
              } while (iVar12 < 9);
              FUN_1400abd00();
              iVar12 = iVar21;
              if (DAT_1400e9230 != (HWND)0x0) {
                SetWindowTextW(DAT_1400e9230,&DAT_1400e2a80);
                iVar13 = iVar21;
                do {
                  iVar13 = iVar13 + 1;
                  iVar15 = iVar21;
                } while (iVar13 < 0xe);
                do {
                  iVar15 = iVar15 + 1;
                  iVar13 = iVar21;
                } while (iVar15 < 0xf);
                do {
                  iVar13 = iVar13 + 1;
                } while (iVar13 < 3);
              }
              do {
                iVar12 = iVar12 + 1;
              } while (iVar12 < 4);
              do {
                iVar21 = iVar21 + 1;
              } while (iVar21 < 0xf);
              FUN_14006e360();
            }
            goto LAB_140005747;
          }
          do {
            lVar25 = DAT_1400e9228;
            iVar12 = iVar12 + 1;
          } while (iVar12 < 0xb);
          lVar6 = (**(code **)(*DAT_1400e9268 + 0x30))(DAT_1400e9268,DAT_1400e9228);
          FUN_1400637d0();
          FUN_140079c90();
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 2);
          iVar12 = (int)lVar25;
          iVar13 = iVar21;
          do {
            iVar13 = iVar13 + 1;
          } while (iVar13 < 3);
          iVar13 = iVar21;
          do {
            iVar13 = iVar13 + 1;
          } while (iVar13 < 4);
          lVar25 = *(longlong *)
                    (((ulonglong)(iVar12 + 0x35a41760) ^ 0x35a41740) +
                    *(longlong *)
                     **(undefined8 **)
                       (((ulonglong)(iVar12 + 0x9aa7b8a0) ^ 0x9aa7b880) +
                       *(longlong *)(((ulonglong)(iVar12 - 0x54a628) ^ 0xffab59c0) + lVar6)));
          iVar13 = iVar21;
          do {
            iVar13 = iVar13 + 1;
          } while (iVar13 < 2);
          if (lVar25 != 0) {
            FUN_140037000();
            FUN_140051760();
            iVar13 = iVar21;
            do {
              iVar13 = iVar13 + 1;
            } while (iVar13 < 0xe);
            pcVar7 = (code *)FUN_140001560(lVar25,iVar12 + 0x8c9937b7U ^ 0xa1959240);
            iVar12 = iVar21;
            do {
              iVar12 = iVar12 + 1;
            } while (iVar12 < 2);
            FUN_140098a10();
            if (pcVar7 != (code *)0x0) {
              (*pcVar7)(FUN_1400026b0,0);
            }
          }
          DAT_1400e8f04 = 0;
          FUN_140057270();
          DAT_1400e8ec4 = '\x01';
          FUN_140036380();
          DAT_1400e9020 = 0;
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 0xd);
          do {
            iVar21 = iVar21 + 1;
          } while (iVar21 < 7);
          if (7 < local_c0) {
            pauVar5 = local_d8;
            if ((0xfff < local_c0 * 2 + 2) &&
               (pauVar5 = *(undefined1 (**) [32])((longlong)local_d8[-1] + 0x18),
               0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)pauVar5))))
            goto LAB_140005fd4;
            thunk_FUN_1400c9460(pauVar5);
          }
          local_d8 = (undefined1 (*) [32])((ulonglong)local_d8 & 0xffffffffffff0000);
          if (local_e0 < 8) {
            return 0;
          }
          pppppppuVar9 = local_f8;
          if (local_e0 * 2 + 2 < 0x1000) goto LAB_140004de5;
          pppppppuVar9 = (undefined8 *******)local_f8[-1];
          uVar20 = (longlong)local_f8 + (-8 - (longlong)pppppppuVar9);
        }
        if (0x1f < uVar20) {
          local_c0 = 7;
          local_c8 = 0;
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
LAB_140004de5:
        local_c0 = 7;
        local_c8 = 0;
        thunk_FUN_1400c9460(pppppppuVar9);
        return 0;
      }
      DAT_1400e8f08 = FUN_1400c4d1c(0x1400e2a80);
      FUN_140009800();
      iVar12 = iVar21;
      do {
        iVar12 = iVar12 + 1;
        iVar13 = iVar21;
      } while (iVar12 < 2);
      do {
        iVar13 = iVar13 + 1;
      } while (iVar13 < 9);
      if (uVar19 == 0xd2) {
        DAT_1400e8f04 = 0x2b;
      }
      else if (uVar19 == 0xd3) {
        DAT_1400e8f04 = 0x2d;
      }
      else if (uVar19 == 0xd4) {
        DAT_1400e8f04 = 0x2a;
      }
      else if (uVar19 == 0xd5) {
        DAT_1400e8f04 = 0x2f;
      }
      else if (uVar19 == 300) {
        DAT_1400e8f04 = 0x26;
      }
      else {
        DAT_1400e8f04 = 0x5e;
        if (uVar19 == 0x12d) {
          DAT_1400e8f04 = 0x7c;
        }
      }
      FUN_1400706e0();
      uVar20 = 0xffffffffffffffff;
      do {
        uVar20 = uVar20 + 1;
      } while ((&DAT_1400e9020)[uVar20] != 0);
      FUN_1400b5620();
      FUN_140089ff0();
      FUN_140033a90();
      if (0xf9 < uVar20) {
LAB_14000592c:
        DAT_1400e8ec4 = '\x01';
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
          iVar13 = iVar21;
        } while (iVar12 < 4);
        do {
          iVar13 = iVar13 + 1;
          iVar12 = iVar21;
        } while (iVar13 < 0xd);
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xb);
        DAT_1400e2a80 = DAT_1400e8f04;
        FUN_1400927d0();
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
          iVar13 = iVar21;
        } while (iVar12 < 6);
        do {
          iVar13 = iVar13 + 1;
        } while (iVar13 < 0xb);
        DAT_1400e2a82 = 0;
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 7);
        FUN_140046260();
        if (DAT_1400e9230 != (HWND)0x0) {
          SetWindowTextW(DAT_1400e9230,&DAT_1400e2a80);
          iVar12 = iVar21;
          do {
            iVar12 = iVar12 + 1;
            iVar13 = iVar21;
          } while (iVar12 < 0xe);
          do {
            iVar13 = iVar13 + 1;
            iVar12 = iVar21;
          } while (iVar13 < 0xf);
          do {
            iVar12 = iVar12 + 1;
          } while (iVar12 < 3);
        }
        FUN_140094fc0();
        iVar12 = iVar21;
        do {
          iVar12 = iVar12 + 1;
        } while (iVar12 < 0xb);
        do {
          iVar21 = iVar21 + 1;
        } while (iVar21 < 0xf);
        return 0;
      }
      (&DAT_1400e9020)[uVar20] = DAT_1400e8f04;
      FUN_140034b90();
      FUN_1400495a0();
      if (uVar20 * 2 + 2 < 0x200) {
        (&DAT_1400e9022)[uVar20] = 0;
        FUN_140097b30();
        FUN_140063a10();
        goto LAB_14000592c;
      }
    }
  }
LAB_140005fad:
  FUN_1400bb2d8();
LAB_140005fb3:
                    /* WARNING: Subroutine does not return */
  FUN_1400013e0();
}



// ===== FUN_140006690 @ 140006690 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_140006690(HWND param_1,longlong param_2)

{
  ushort uVar1;
  char cVar2;
  BOOL BVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  undefined1 auStack_98 [32];
  uint local_78;
  uint local_74;
  tagMSG local_70;
  ulonglong local_40;
  
  local_40 = DAT_1400e2040 ^ (ulonglong)auStack_98;
  local_70.hwnd = (HWND)0x0;
  local_70.message = 0;
  local_70._12_4_ = 0;
  iVar9 = 0;
  local_70.wParam = 0;
  local_70.lParam = 0;
  local_70.time = 0;
  local_70.pt.x = 0;
  local_70.pt.y = 0;
  local_70._44_4_ = 0;
  do {
    iVar9 = iVar9 + 1;
  } while (iVar9 < 0xf);
  local_78 = 0x9a;
  uVar5 = 0;
  do {
    local_78 = local_78 ^ uVar5;
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 9);
  FUN_1400a6550();
  iVar9 = (int)param_2;
  uVar5 = iVar9 + 0x469c2820U ^ 0x469c2820;
  BVar3 = GetMessageW(&local_70,(HWND)0x0,uVar5,uVar5);
  if (BVar3 != 0) {
    do {
      if (local_70.message == (iVar9 + 0x941a5682U ^ 0x941a5780)) {
        uVar1 = (ushort)local_70.wParam;
        uVar6 = 0;
        local_78 = 0x3a5;
        do {
          local_78 = local_78 ^ uVar6;
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < 0xe);
        FUN_14000f6f0();
        FUN_14009def0();
        local_78 = 0x2d3;
        local_74 = iVar9 + 0x17914460U ^ 0x17914460;
        uVar6 = 0;
        do {
          local_78 = local_78 ^ uVar6;
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < 7);
        sVar8 = (short)param_2;
        if ((uVar1 < (ushort)(sVar8 - 0xeb0U ^ 0xf160)) ||
           ((ushort)(sVar8 - 0xea7U ^ 0xf160) < uVar1)) {
          if (uVar1 == (ushort)(sVar8 + 0x89abU ^ 0x8980)) {
            local_78 = 0x7a;
            uVar6 = iVar9 + 0xaa29b832U ^ 0xaa29b8e0;
            uVar7 = 0;
            do {
              local_78 = local_78 ^ uVar7;
              uVar7 = uVar7 + 1;
            } while ((int)uVar7 < 6);
            FUN_14006d150();
          }
          else {
            if (uVar1 == (ushort)(sVar8 + 0x89adU ^ 0x8980)) {
              local_78 = 0x7a;
              uVar6 = 0;
              do {
                local_78 = local_78 ^ uVar6;
                uVar6 = uVar6 + 1;
              } while ((int)uVar6 < 6);
              FUN_14006d150();
              cVar2 = '\x01';
              uVar6 = iVar9 + 0xaa29b833U ^ 0xaa29b8e0;
            }
            else if (uVar1 == (ushort)(sVar8 + 0x89aaU ^ 0x8980)) {
              local_78 = 0x7a;
              uVar6 = 0;
              do {
                local_78 = local_78 ^ uVar6;
                uVar6 = uVar6 + 1;
              } while ((int)uVar6 < 6);
              FUN_14006d150();
              cVar2 = '\x01';
              uVar6 = iVar9 + 0xaa29b834U ^ 0xaa29b8e0;
            }
            else {
              uVar4 = FUN_140008920(uVar1,&local_74,iVar9);
              cVar2 = (char)uVar4;
              uVar6 = local_74;
            }
            if (cVar2 == '\0') {
              uVar4 = FUN_140005ff0(uVar1,param_2);
              if ((char)uVar4 == '\0') goto LAB_140006987;
              goto LAB_1400069c6;
            }
          }
        }
        else {
          uVar6 = ((iVar9 + 0x99922008U ^ 0x999220c0) - (iVar9 + 0x20f0U & 0xffff ^ 0x20c0)) +
                  (uint)uVar1;
          FUN_140029820();
        }
        SendMessageW(param_1,iVar9 + 0x4d8a00f1U ^ 0x4d8a01e0,
                     ((ulonglong)(iVar9 + 0x3140U & 0xffff) ^ 0x3140) << 0x10 |
                     (ulonglong)(uVar6 & 0xffff),param_2 + 0x92680a0ee88660a0U ^ 0x92680a0ee88660a0)
        ;
        FUN_1400846e0();
      }
      else {
LAB_140006987:
        TranslateMessage(&local_70);
        uVar6 = 0;
        local_74 = 0x240;
        do {
          local_74 = local_74 ^ uVar6;
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < 0xd);
        FUN_140011210();
        DispatchMessageW(&local_70);
        FUN_140014330();
      }
LAB_1400069c6:
      BVar3 = GetMessageW(&local_70,(HWND)0x0,uVar5,uVar5);
    } while (BVar3 != 0);
  }
  return local_70.wParam & 0xffffffff;
}


