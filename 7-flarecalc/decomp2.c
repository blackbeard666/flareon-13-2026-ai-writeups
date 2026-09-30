// callers of: VirtualProtect,CreateFileW,GetModuleFileNameW,RegisterClassExW,SetWindowTextW,CreateWindowExW,SetTimer,LoadLibraryExW,GetProcAddress  -> 11 funcs

// ===== FUN_1400cc874 @ 1400cc874  size~48 =====

bool FUN_1400cc874(void)

{
  BOOL BVar1;
  DWORD local_res8 [8];
  
  local_res8[0] = 0;
  BVar1 = VirtualProtect(&DAT_1400f3000,0x100,2,local_res8);
  return BVar1 != 0;
}



// ===== FUN_1400cc4d8 @ 1400cc4d8  size~433 =====

FARPROC FUN_1400cc4d8(uint param_1,LPCSTR param_2,uint *param_3,uint *param_4)

{
  longlong lVar1;
  uint uVar2;
  wchar_t *lpLibFileName;
  DWORD DVar3;
  int iVar4;
  BOOL BVar5;
  HMODULE hLibModule;
  FARPROC pFVar6;
  FARPROC pFVar7;
  DWORD local_res18 [2];
  
  do {
    if (param_3 == param_4) {
      pFVar7 = (FARPROC)0x0;
LAB_1400cc5ca:
      __acrt_lock(0xe);
      local_res18[0] = 0;
      BVar5 = VirtualProtect(&DAT_1400f3000,0x100,4,local_res18);
      if (BVar5 != 0) {
        pFVar6 = pFVar7;
        if (pFVar7 == (FARPROC)0x0) {
          pFVar6 = (FARPROC)0xffffffffffffffff;
        }
        LOCK();
        *(FARPROC *)(&DAT_1400f3000 + (ulonglong)param_1 * 8) = pFVar6;
        UNLOCK();
        BVar5 = VirtualProtect(&DAT_1400f3000,0x100,2,local_res18);
        if (BVar5 != 0) {
          __acrt_unlock(0xe);
          return pFVar7;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_1400c8ab8();
    }
    uVar2 = *param_3;
    hLibModule = (HMODULE)(&DAT_1400e8dc0)[uVar2];
    if (hLibModule == (HMODULE)0x0) {
      lpLibFileName = (wchar_t *)(&PTR_u_api_ms_win_core_datetime_l1_1_1_1400d8680)[uVar2];
      hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0x800);
      if ((hLibModule != (HMODULE)0x0) ||
         ((((DVar3 = GetLastError(), DVar3 == 0x57 &&
            (iVar4 = wcsncmp(lpLibFileName,L"api-ms-",7), iVar4 != 0)) &&
           (iVar4 = wcsncmp(lpLibFileName,L"ext-ms-",7), iVar4 != 0)) &&
          (hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0), hLibModule != (HMODULE)0x0))))
      {
        LOCK();
        lVar1 = (&DAT_1400e8dc0)[uVar2];
        (&DAT_1400e8dc0)[uVar2] = hLibModule;
        UNLOCK();
        if (lVar1 != 0) {
          FreeLibrary(hLibModule);
        }
        goto LAB_1400cc670;
      }
      LOCK();
      (&DAT_1400e8dc0)[uVar2] = 0xffffffffffffffff;
      UNLOCK();
    }
    else if (hLibModule != (HMODULE)0xffffffffffffffff) {
LAB_1400cc670:
      pFVar7 = GetProcAddress(hLibModule,param_2);
      goto LAB_1400cc5ca;
    }
    param_3 = param_3 + 1;
  } while( true );
}



// ===== __dcrt_lowio_ensure_console_output_initialized @ 1400d2064  size~82 =====

/* Library Function - Single Match
    __dcrt_lowio_ensure_console_output_initialized
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

bool __dcrt_lowio_ensure_console_output_initialized(void)

{
  if (DAT_1400e2a70 == (HANDLE)0xfffffffffffffffe) {
    DAT_1400e2a70 = CreateFileW(L"CONOUT$",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  }
  return DAT_1400e2a70 != (HANDLE)0xffffffffffffffff;
}



// ===== __dcrt_write_console @ 1400d20d4  size~190 =====

/* Library Function - Single Match
    __dcrt_write_console
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

BOOL __dcrt_write_console(void *param_1,DWORD param_2,LPDWORD param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = WriteConsoleW(DAT_1400e2a70,param_1,param_2,param_3,(LPVOID)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 == 6) {
      if (DAT_1400e2a70 < (HANDLE)0xfffffffffffffffe) {
        CloseHandle(DAT_1400e2a70);
      }
      DAT_1400e2a70 =
           CreateFileW(L"CONOUT$",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
      BVar1 = WriteConsoleW(DAT_1400e2a70,param_1,param_2,param_3,(LPVOID)0x0);
    }
  }
  return BVar1;
}



// ===== FUN_1400c7e44 @ 1400c7e44  size~377 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1400c7e44(int param_1)

{
  longlong lVar1;
  longlong *plVar2;
  __acrt_ptd *p_Var3;
  longlong *plVar4;
  ulonglong uVar5;
  short *psVar6;
  ulonglong uVar7;
  longlong *local_res10;
  ulonglong local_res18;
  ulonglong local_res20;
  
  uVar7 = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (1 < param_1 - 1U) {
    p_Var3 = FUN_1400c9344();
    *(undefined4 *)p_Var3 = 0x16;
    FUN_1400c0f6c();
    return 0x16;
  }
  GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_1400e8430,0x104);
  _DAT_1400e8d90 = &DAT_1400e8430;
  if ((DAT_1400e8db8 == (short *)0x0) || (psVar6 = DAT_1400e8db8, *DAT_1400e8db8 == 0)) {
    psVar6 = (short *)&DAT_1400e8430;
  }
  local_res18 = 0;
  local_res20 = 0;
  FUN_1400c7c40(psVar6,(undefined8 *)0x0,(short *)0x0,(longlong *)&local_res18,
                (longlong *)&local_res20);
  uVar5 = local_res18;
  plVar4 = __acrt_allocate_buffer_for_argv(local_res18,local_res20,2);
  if (plVar4 == (longlong *)0x0) {
    p_Var3 = FUN_1400c9344();
    uVar7 = 0xc;
    *(undefined4 *)p_Var3 = 0xc;
  }
  else {
    FUN_1400c7c40(psVar6,plVar4,(short *)(plVar4 + uVar5),(longlong *)&local_res18,
                  (longlong *)&local_res20);
    if (param_1 != 1) {
      local_res10 = (longlong *)0x0;
      uVar5 = thunk_FUN_1400cb09c(plVar4,&local_res10);
      plVar2 = local_res10;
      if ((int)uVar5 != 0) {
        FUN_1400c9460(local_res10);
        local_res10 = (longlong *)0x0;
        FUN_1400c9460(plVar4);
        return uVar5 & 0xffffffff;
      }
      _DAT_1400e8d98 = 0;
      lVar1 = *local_res10;
      uVar5 = uVar7;
      while (lVar1 != 0) {
        local_res10 = local_res10 + 1;
        uVar5 = uVar5 + 1;
        _DAT_1400e8d98 = (int)uVar5;
        lVar1 = *local_res10;
      }
      local_res10 = (longlong *)0x0;
      DAT_1400e8da8 = plVar2;
      FUN_1400c9460((LPVOID)0x0);
      local_res10 = (longlong *)0x0;
      goto LAB_1400c7fa5;
    }
    _DAT_1400e8d98 = (int)local_res18 + -1;
    DAT_1400e8da8 = plVar4;
  }
  plVar4 = (longlong *)0x0;
LAB_1400c7fa5:
  FUN_1400c9460(plVar4);
  return uVar7;
}



// ===== FUN_140006be0 @ 140006be0  size~977 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140006be0(HINSTANCE param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  LPCWSTR lpIconName;
  undefined1 auStack_98 [32];
  uint local_78;
  WNDCLASSEXW local_68;
  ulonglong local_18;
  
  local_18 = DAT_1400e2040 ^ (ulonglong)auStack_98;
  uVar4 = 0;
  uVar3 = uVar4;
  do {
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0xe);
  local_78 = 0x327;
  uVar3 = uVar4;
  do {
    local_78 = local_78 ^ uVar3;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 5);
  iVar1 = (int)param_4;
  local_68.cbSize = iVar1 + 0x6a5700f0U ^ 0x6a5700a0;
  FUN_14002fee0();
  FUN_1400398c0();
  local_68.style = iVar1 + 0x52d18ec3U ^ 0x52d18ec0;
  FUN_140090ed0();
  local_78 = 0x22c;
  uVar3 = uVar4;
  do {
    local_78 = local_78 ^ uVar3;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0xc);
  FUN_140099590();
  local_68.lpfnWndProc = FUN_140003b20;
  local_78 = 0x217;
  uVar3 = uVar4;
  do {
    local_78 = local_78 ^ uVar3;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 5);
  local_68.cbClsExtra = iVar1 + 0x23c6ab00U ^ 0x23c6ab00;
  FUN_14003d530();
  local_68.cbWndExtra = iVar1 + 0xbec309c0U ^ 0xbec309c0;
  uVar3 = uVar4;
  do {
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 4);
  local_78 = 0x3ad;
  uVar3 = uVar4;
  do {
    local_78 = local_78 ^ uVar3;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 4);
  FUN_1400af540();
  local_78 = 0x16c;
  uVar3 = uVar4;
  do {
    local_78 = local_78 ^ uVar3;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 6);
  local_68.hInstance = param_1;
  FUN_1400b3410();
  lpIconName = (LPCWSTR)(param_4 + 0xc1c44016d9041f40U ^ 0xc1c44016d9046040);
  local_68.hIcon = LoadIconW((HINSTANCE)0x0,lpIconName);
  uVar3 = uVar4;
  do {
    uVar3 = uVar3 + 1;
    uVar2 = uVar4;
  } while ((int)uVar3 < 4);
  do {
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 8);
  local_78 = 0x363;
  uVar3 = uVar4;
  do {
    local_78 = local_78 ^ uVar3;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 2);
  local_68.hCursor =
       LoadCursorW((HINSTANCE)0x0,(LPCWSTR)(param_4 + 0x7efe14d5f777d4e0U ^ 0x7efe14d5f777abe0));
  uVar3 = uVar4;
  do {
    uVar3 = uVar3 + 1;
    uVar2 = uVar4;
  } while ((int)uVar3 < 0xe);
  do {
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 9);
  local_68.hbrBackground = (HBRUSH)(param_4 + 0x2df39d6bfba9a106U ^ 0x2df39d6bfba9a100);
  uVar3 = uVar4;
  do {
    uVar3 = uVar3 + 1;
    uVar2 = uVar4;
  } while ((int)uVar3 < 7);
  do {
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0xb);
  local_78 = 0x39e;
  uVar3 = uVar4;
  do {
    local_78 = local_78 ^ uVar3;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 3);
  local_68.lpszMenuName = (LPCWSTR)0x0;
  FUN_1400ae440();
  local_68.lpszClassName = L"Flare-OnCalculatorClass";
  uVar3 = uVar4;
  do {
    uVar3 = uVar3 + 1;
    uVar2 = uVar4;
  } while ((int)uVar3 < 0xe);
  do {
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0xe);
  local_78 = 0x210;
  uVar3 = uVar4;
  do {
    local_78 = local_78 ^ uVar3;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 9);
  local_68.hIconSm = LoadIconW((HINSTANCE)0x0,lpIconName);
  FUN_140087dc0();
  local_78 = 0x12f;
  do {
    local_78 = local_78 ^ uVar4;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 9);
  RegisterClassExW(&local_68);
  return;
}



// ===== FUN_140003b20 @ 140003b20  size~9414 =====

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



// ===== FUN_140005ff0 @ 140005ff0  size~626 =====

undefined8 FUN_140005ff0(ushort param_1,longlong param_2)

{
  short sVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  iVar2 = (int)param_2 + 0x1fe8;
  if (param_1 != (ushort)((ushort)iVar2 ^ 0x1fe0)) {
    return (ulonglong)(uint3)((uint3)((uint)iVar2 >> 8) ^ 0x1f) << 8;
  }
  uVar5 = 0xffffffffffffffff;
  uVar6 = 0xffffffffffffffff;
  do {
    uVar6 = uVar6 + 1;
  } while ((&DAT_1400e2a80)[uVar6] != 0);
  FUN_1400b19a0();
  iVar2 = 0;
  sVar1 = (short)param_2;
  if ((param_2 + 0xe508510bae5bae00U ^ 0xe508510bae5bae00) < uVar6) {
    (&DAT_1400e2a80)[uVar6 - (param_2 + 0x24a2dd26fbd9dd61U ^ 0x24a2dd26fbd9dd60)] =
         sVar1 + 0xdd60U ^ 0xdd60;
    FUN_14003a8a0();
    if (uVar6 == (param_2 + 0xa3d7f55d96d63c21U ^ 0xa3d7f55d96d63c20)) {
      DAT_1400e2a80 = sVar1 + 0x6bb0U ^ 0x6b80;
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0xb);
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0xc);
      DAT_1400e2a82 = sVar1 + 0x2900U ^ 0x2900;
      FUN_140073a30();
      FUN_140049ec0();
    }
  }
  do {
    uVar5 = uVar5 + 1;
  } while ((&DAT_1400e9020)[uVar5] != 0);
  if ((param_2 + 0x5f7bfa89eb424540U ^ 0x5f7bfa89eb424540) < uVar5) {
    (&DAT_1400e9020)[uVar5 - (param_2 + 0x9f1686a538c074a1U ^ 0x9f1686a538c074a0)] =
         sVar1 + 0x74a0U ^ 0x74a0;
    FUN_14002da60();
    FUN_14003e770();
  }
  if (DAT_1400e9230 != (HWND)0x0) {
    SetWindowTextW(DAT_1400e9230,(LPCWSTR)&DAT_1400e2a80);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xe);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xf);
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  uVar3 = FUN_140055f20();
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



// ===== FUN_140006340 @ 140006340  size~848 =====

HWND FUN_140006340(HINSTANCE param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,longlong param_6)

{
  ushort uVar1;
  HWND hWnd;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  tagRECT local_30;
  
  uVar1 = FUN_140006be0(param_1,param_2,param_3,param_6);
  iVar5 = 0;
  iVar4 = iVar5;
  do {
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  iVar4 = (int)param_6;
  if (uVar1 != (ushort)((ushort)(iVar4 + 0x7820) ^ 0x7820)) {
    local_30.left = iVar4 + 0xf1ffe2a0U ^ 0xf1ffe2a0;
    local_30.top = iVar4 + 0x3f7e1200U ^ 0x3f7e1200;
    local_30.right = iVar4 + 0x8cfc4078U ^ 0x8cfc4160;
    local_30.bottom = iVar4 + 0xda7a7194U ^ 0xda7a70c0;
    AdjustWindowRect(&local_30,iVar4 + 0x75bccf80U ^ 0x7576cf80,iVar4 + 0x7576cf80U ^ 0x7576cf80);
    FUN_140045700();
    FUN_140079360();
    iVar2 = iVar5;
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xd);
    iVar2 = iVar5;
    do {
      iVar2 = iVar2 + 1;
      iVar3 = iVar5;
    } while (iVar2 < 0xd);
    do {
      iVar3 = iVar3 + 1;
      iVar2 = iVar5;
    } while (iVar3 < 0xe);
    do {
      iVar2 = iVar2 + 1;
    } while (iVar2 < 9);
    iVar2 = iVar5;
    do {
      iVar2 = iVar2 + 1;
      iVar3 = iVar5;
    } while (iVar2 < 8);
    do {
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    hWnd = CreateWindowExW(iVar4 + 0xace59d80U ^ 0xace59d80,L"Flare-OnCalculatorClass",
                           L"Flare-On Calculator",iVar4 + 0x95aa2ba0U ^ 0x95602ba0,
                           iVar4 + 0x62de5b00U ^ 0xe2de5b00,iVar4 + 0xb05c8a60U ^ 0x305c8a60,
                           (local_30.right - local_30.left ^ 0x7ddab9c0U) + iVar4 ^ 0x7ddab9c0,
                           (local_30.bottom - local_30.top ^ 0xcb58e920U) + iVar4 ^ 0xcb58e920,
                           (HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0);
    if (hWnd != (HWND)0x0) {
      ShowWindow(hWnd,iVar4 + ((uint)param_2 ^ 0x8a405cc0) ^ 0x8a405cc0);
      iVar4 = iVar5;
      do {
        iVar4 = iVar4 + 1;
      } while (iVar4 < 10);
      FUN_140095b10();
      iVar4 = iVar5;
      do {
        iVar4 = iVar4 + 1;
        iVar2 = iVar5;
      } while (iVar4 < 3);
      do {
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0xe);
      FUN_14007a940();
      FUN_140012d90();
      UpdateWindow(hWnd);
      FUN_1400199c0();
      iVar4 = iVar5;
      do {
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0xe);
      FUN_14007a940();
      FUN_140012d90();
      FUN_1400b72d0();
      FUN_1400b72d0();
      do {
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0xe);
      FUN_1400a79a0();
      return hWnd;
    }
  }
  return (HWND)0x0;
}



// ===== FUN_1400c076c @ 1400c076c  size~335 =====

FARPROC FUN_1400c076c(uint param_1,LPCSTR param_2,uint *param_3,uint *param_4)

{
  longlong lVar1;
  wchar_t *lpLibFileName;
  DWORD DVar2;
  int iVar3;
  HMODULE hLibModule;
  FARPROC pFVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar6 = (ulonglong)param_1;
  pFVar4 = *(FARPROC *)(&DAT_1400e83d8 + uVar6 * 8);
  if (pFVar4 != (FARPROC)0xffffffffffffffff) {
    if (pFVar4 != (FARPROC)0x0) {
      return pFVar4;
    }
    for (; param_3 != param_4; param_3 = param_3 + 1) {
      uVar5 = (ulonglong)*param_3;
      hLibModule = *(HMODULE *)(&DAT_1400e83c0 + uVar5 * 8);
      if (hLibModule == (HMODULE)0x0) {
        lpLibFileName = (wchar_t *)(&PTR_u_api_ms_win_core_fibers_l1_1_1_1400d6438)[uVar5];
        hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0x800);
        if ((hLibModule != (HMODULE)0x0) ||
           (((DVar2 = GetLastError(), DVar2 == 0x57 &&
             (iVar3 = wcsncmp(lpLibFileName,L"api-ms-",7), iVar3 != 0)) &&
            (hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0), hLibModule != (HMODULE)0x0)))
           ) {
          LOCK();
          lVar1 = *(longlong *)(&DAT_1400e83c0 + uVar5 * 8);
          *(HMODULE *)(&DAT_1400e83c0 + uVar5 * 8) = hLibModule;
          UNLOCK();
          if (lVar1 != 0) {
            FreeLibrary(hLibModule);
          }
          goto LAB_1400c089d;
        }
        LOCK();
        *(undefined8 *)(&DAT_1400e83c0 + uVar5 * 8) = 0xffffffffffffffff;
        UNLOCK();
      }
      else if (hLibModule != (HMODULE)0xffffffffffffffff) {
LAB_1400c089d:
        pFVar4 = GetProcAddress(hLibModule,param_2);
        if (pFVar4 != (FARPROC)0x0) {
          LOCK();
          *(FARPROC *)(&DAT_1400e83d8 + uVar6 * 8) = pFVar4;
          UNLOCK();
          return pFVar4;
        }
        break;
      }
    }
    LOCK();
    *(undefined8 *)(&DAT_1400e83d8 + uVar6 * 8) = 0xffffffffffffffff;
    UNLOCK();
  }
  return (FARPROC)0x0;
}



// ===== FUN_1400c7b60 @ 1400c7b60  size~100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FUN_1400c7b60(uint param_1)

{
  BOOL BVar1;
  FARPROC pFVar2;
  HMODULE local_res10 [3];
  
  local_res10[0] = (HMODULE)0x0;
  BVar1 = GetModuleHandleExW(0,L"mscoree.dll",local_res10);
  if ((BVar1 != 0) &&
     (pFVar2 = GetProcAddress(local_res10[0],"CorExitProcess"), pFVar2 != (FARPROC)0x0)) {
    (*pFVar2)((ulonglong)param_1);
  }
  if (local_res10[0] != (HMODULE)0x0) {
    FreeLibrary(local_res10[0]);
  }
  return;
}


