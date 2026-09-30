// ==== FUN_140001000 @ 140001000

undefined * FUN_140001000(void)

{
  return &DAT_140006678;
}


// ==== FUN_140001010 @ 140001010

int FUN_140001010(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 local_res20;
  
  local_res20 = param_4;
  puVar2 = (undefined8 *)FUN_140001000();
  iVar1 = __stdio_common_vswprintf_s(*puVar2,param_1,param_2,param_3,0,&local_res20);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}


// ==== FUN_140001070 @ 140001070

void FUN_140001070(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  uVar1 = __acrt_iob_func(1);
  puVar2 = (undefined8 *)FUN_140001000();
  __stdio_common_vfprintf(*puVar2,uVar1,param_1,0,&local_res10);
  return;
}


// ==== FUN_1400010d0 @ 1400010d0

int FUN_1400010d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 local_res20;
  
  local_res20 = param_4;
  puVar2 = (ulonglong *)FUN_140001000();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 2,param_1,param_2,param_3,0,&local_res20);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}


// ==== FUN_140001130 @ 140001130

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140001130(longlong param_1,ulonglong param_2,byte *param_3)

{
  uint uVar1;
  byte bVar2;
  char *pcVar3;
  ulonglong uVar4;
  byte *pbVar5;
  byte bVar6;
  char cVar7;
  char cVar9;
  char cVar10;
  undefined4 uVar8;
  char cVar11;
  char cVar12;
  char cVar14;
  char cVar15;
  undefined4 uVar13;
  char cVar16;
  char cVar17;
  char cVar19;
  char cVar20;
  undefined4 uVar18;
  char cVar21;
  char cVar22;
  char cVar24;
  char cVar25;
  undefined4 uVar23;
  char cVar26;
  undefined1 in_XMM2_Ba;
  char cVar27;
  undefined1 in_XMM2_Bb;
  char cVar28;
  undefined1 in_XMM2_Bc;
  char cVar29;
  undefined1 in_XMM2_Bd;
  char cVar30;
  undefined1 in_XMM2_Be;
  char cVar31;
  undefined1 in_XMM2_Bf;
  char cVar32;
  undefined1 in_XMM2_Bg;
  char cVar33;
  undefined1 in_XMM2_Bh;
  char cVar34;
  undefined1 in_XMM2_Bi;
  char cVar35;
  undefined1 in_XMM2_Bj;
  char cVar36;
  undefined1 in_XMM2_Bk;
  char cVar37;
  undefined1 in_XMM2_Bl;
  char cVar38;
  undefined1 in_XMM2_Bm;
  char cVar39;
  undefined1 in_XMM2_Bn;
  char cVar40;
  undefined1 in_XMM2_Bo;
  char cVar41;
  undefined1 in_XMM2_Bp;
  char cVar42;
  undefined1 auStack_158 [48];
  byte local_128 [272];
  ulonglong local_18;
  
  local_18 = DAT_140006000 ^ (ulonglong)auStack_158;
  GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_128,0x104);
  pcVar3 = strrchr((char *)local_128,0x5c);
  if (pcVar3 == (char *)0x0) {
    pbVar5 = local_128;
  }
  else {
    pbVar5 = (byte *)(pcVar3 + 1);
  }
  uVar4 = 0xffffffffffffffff;
  do {
    uVar4 = uVar4 + 1;
  } while (pbVar5[uVar4] != 0);
  cVar27 = '\0';
  bVar6 = pbVar5[uVar4 >> 1] ^ *pbVar5;
  uVar4 = 0;
  if (0x1f < param_2) {
    uVar8 = 0;
    uVar13 = 0;
    uVar18 = 0;
    uVar23 = 0;
    uVar1 = CONCAT13(in_XMM2_Bd,CONCAT12(in_XMM2_Bc,CONCAT11(in_XMM2_Bb,in_XMM2_Ba))) ^
            CONCAT13(in_XMM2_Bd,CONCAT12(in_XMM2_Bc,CONCAT11(in_XMM2_Bb,in_XMM2_Ba)));
    cVar27 = (char)uVar1;
    cVar28 = (char)(uVar1 >> 8);
    cVar29 = (char)(uVar1 >> 0x10);
    cVar30 = (char)(uVar1 >> 0x18);
    uVar1 = CONCAT13(in_XMM2_Bh,CONCAT12(in_XMM2_Bg,CONCAT11(in_XMM2_Bf,in_XMM2_Be))) ^
            CONCAT13(in_XMM2_Bh,CONCAT12(in_XMM2_Bg,CONCAT11(in_XMM2_Bf,in_XMM2_Be)));
    cVar31 = (char)uVar1;
    cVar32 = (char)(uVar1 >> 8);
    cVar33 = (char)(uVar1 >> 0x10);
    cVar34 = (char)(uVar1 >> 0x18);
    uVar1 = CONCAT13(in_XMM2_Bl,CONCAT12(in_XMM2_Bk,CONCAT11(in_XMM2_Bj,in_XMM2_Bi))) ^
            CONCAT13(in_XMM2_Bl,CONCAT12(in_XMM2_Bk,CONCAT11(in_XMM2_Bj,in_XMM2_Bi)));
    cVar35 = (char)uVar1;
    cVar36 = (char)(uVar1 >> 8);
    cVar37 = (char)(uVar1 >> 0x10);
    cVar38 = (char)(uVar1 >> 0x18);
    uVar1 = CONCAT13(in_XMM2_Bp,CONCAT12(in_XMM2_Bo,CONCAT11(in_XMM2_Bn,in_XMM2_Bm))) ^
            CONCAT13(in_XMM2_Bp,CONCAT12(in_XMM2_Bo,CONCAT11(in_XMM2_Bn,in_XMM2_Bm)));
    cVar39 = (char)uVar1;
    cVar40 = (char)(uVar1 >> 8);
    cVar41 = (char)(uVar1 >> 0x10);
    cVar42 = (char)(uVar1 >> 0x18);
    do {
      pcVar3 = (char *)(param_1 + uVar4);
      cVar7 = (char)uVar8 + *pcVar3;
      cVar9 = (char)((uint)uVar8 >> 8) + pcVar3[1];
      cVar10 = (char)((uint)uVar8 >> 0x10) + pcVar3[2];
      cVar11 = (char)((uint)uVar8 >> 0x18) + pcVar3[3];
      uVar8 = CONCAT13(cVar11,CONCAT12(cVar10,CONCAT11(cVar9,cVar7)));
      cVar12 = (char)uVar13 + pcVar3[4];
      cVar14 = (char)((uint)uVar13 >> 8) + pcVar3[5];
      cVar15 = (char)((uint)uVar13 >> 0x10) + pcVar3[6];
      cVar16 = (char)((uint)uVar13 >> 0x18) + pcVar3[7];
      uVar13 = CONCAT13(cVar16,CONCAT12(cVar15,CONCAT11(cVar14,cVar12)));
      cVar17 = (char)uVar18 + pcVar3[8];
      cVar19 = (char)((uint)uVar18 >> 8) + pcVar3[9];
      cVar20 = (char)((uint)uVar18 >> 0x10) + pcVar3[10];
      cVar21 = (char)((uint)uVar18 >> 0x18) + pcVar3[0xb];
      uVar18 = CONCAT13(cVar21,CONCAT12(cVar20,CONCAT11(cVar19,cVar17)));
      cVar22 = (char)uVar23 + pcVar3[0xc];
      cVar24 = (char)((uint)uVar23 >> 8) + pcVar3[0xd];
      cVar25 = (char)((uint)uVar23 >> 0x10) + pcVar3[0xe];
      cVar26 = (char)((uint)uVar23 >> 0x18) + pcVar3[0xf];
      uVar23 = CONCAT13(cVar26,CONCAT12(cVar25,CONCAT11(cVar24,cVar22)));
      pcVar3 = (char *)(param_1 + 0x10 + uVar4);
      uVar4 = uVar4 + 0x20;
      cVar27 = cVar27 + *pcVar3;
      cVar28 = cVar28 + pcVar3[1];
      cVar29 = cVar29 + pcVar3[2];
      cVar30 = cVar30 + pcVar3[3];
      cVar31 = cVar31 + pcVar3[4];
      cVar32 = cVar32 + pcVar3[5];
      cVar33 = cVar33 + pcVar3[6];
      cVar34 = cVar34 + pcVar3[7];
      cVar35 = cVar35 + pcVar3[8];
      cVar36 = cVar36 + pcVar3[9];
      cVar37 = cVar37 + pcVar3[10];
      cVar38 = cVar38 + pcVar3[0xb];
      cVar39 = cVar39 + pcVar3[0xc];
      cVar40 = cVar40 + pcVar3[0xd];
      cVar41 = cVar41 + pcVar3[0xe];
      cVar42 = cVar42 + pcVar3[0xf];
    } while (uVar4 < (param_2 & 0xffffffffffffffe0));
    cVar27 = cVar27 + cVar7 + cVar35 + cVar17 + cVar31 + cVar12 + cVar39 + cVar22 +
             cVar29 + cVar10 + cVar37 + cVar20 + cVar33 + cVar15 + cVar41 + cVar25 +
             cVar28 + cVar9 + cVar36 + cVar19 + cVar32 + cVar14 + cVar40 + cVar24 +
             cVar30 + cVar11 + cVar38 + cVar21 + cVar34 + cVar16 + cVar42 + cVar26;
  }
  cVar29 = '\0';
  cVar28 = '\0';
  if (param_2 <= uVar4) goto LAB_140001270;
  if (param_2 - uVar4 < 2) {
LAB_140001266:
    cVar27 = cVar27 + *(char *)(uVar4 + param_1);
  }
  else {
    do {
      cVar29 = cVar29 + *(char *)(param_1 + uVar4);
      cVar28 = cVar28 + *(char *)(param_1 + 1 + uVar4);
      uVar4 = uVar4 + 2;
    } while (uVar4 < param_2 - 1);
    if (uVar4 < param_2) goto LAB_140001266;
  }
  cVar27 = cVar27 + cVar28 + cVar29;
LAB_140001270:
  cVar28 = '\x04';
  switch(cVar27) {
  case '\x1c':
  case -0x1b:
    cVar28 = '\0';
    break;
  case '$':
  case 'b':
  case -0x1f:
    cVar28 = '\x02';
    break;
  case 'S':
  case '`':
  case 'j':
  case 't':
  case '{':
    cVar28 = '\x01';
  }
  if (param_2 != 0) {
    pbVar5 = param_3;
    do {
      bVar2 = pbVar5[param_1 - (longlong)param_3];
      if (cVar28 == '\0') {
        bVar2 = bVar2 - bVar6;
      }
      else if (cVar28 == '\x01') {
        bVar2 = bVar2 + 1 ^ bVar6;
      }
      else {
        if (cVar28 != '\x02') break;
        bVar2 = (bVar2 - 2) + bVar6;
      }
      *pbVar5 = bVar2;
      pbVar5 = pbVar5 + 1;
    } while ((ulonglong)((longlong)pbVar5 - (longlong)param_3) < param_2);
  }
  param_3[param_2] = 0;
  return;
}


// ==== FUN_140001400 @ 140001400

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_140001400(void)

{
  DWORD DVar1;
  BOOL BVar2;
  HRSRC hResInfo;
  ulonglong uVar3;
  HGLOBAL hResData;
  LPVOID lpBuffer;
  HANDLE hFile;
  undefined4 extraout_var;
  undefined8 uVar4;
  HRSRC pHVar5;
  undefined *puVar6;
  undefined8 in_R9;
  LPDWORD lpNumberOfBytesWritten;
  undefined8 uVar7;
  undefined1 auStackY_518 [32];
  _PROCESS_INFORMATION local_4c8;
  DWORD local_4b0 [2];
  _STARTUPINFOW local_4a8;
  WCHAR local_438 [264];
  WCHAR local_228 [264];
  ulonglong local_18;
  
  local_18 = DAT_140006000 ^ (ulonglong)auStackY_518;
  puVar6 = &DAT_1400043d0;
  uVar4 = 0x65;
  hResInfo = FindResourceW((HMODULE)0x0,(LPCWSTR)0x65,L"BIN");
  if (hResInfo == (HRSRC)0x0) {
    uVar3 = FUN_140001070("Failed to find resource.\n",uVar4,puVar6,in_R9);
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    pHVar5 = hResInfo;
    hResData = LoadResource((HMODULE)0x0,hResInfo);
    if (hResData == (HGLOBAL)0x0) {
      uVar3 = FUN_140001070("Failed to load resource.\n",pHVar5,puVar6,in_R9);
      uVar3 = uVar3 & 0xffffffffffffff00;
    }
    else {
      lpBuffer = LockResource(hResData);
      DVar1 = SizeofResource((HMODULE)0x0,hResInfo);
      if ((lpBuffer == (LPVOID)0x0) || (DVar1 == 0)) {
        uVar3 = FUN_140001070("Failed to lock resource or get size.\n",hResInfo,puVar6,in_R9);
        uVar3 = uVar3 & 0xffffffffffffff00;
      }
      else {
        GetTempPathW(0x104,local_228);
        FUN_140001010(local_438,0x104,L"%sPartner_CTF.exe",local_228);
        uVar4 = 0;
        hFile = CreateFileW(local_438,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
        if (hFile == (HANDLE)0xffffffffffffffff) {
          DVar1 = GetLastError();
          uVar3 = FUN_140001070("Failed to create file on disk. Error: %lu, Path: %ls\n",
                                (ulonglong)DVar1,local_438,uVar4);
        }
        else {
          lpNumberOfBytesWritten = local_4b0;
          local_4b0[0] = 0;
          uVar3 = (ulonglong)DVar1;
          WriteFile(hFile,lpBuffer,DVar1,lpNumberOfBytesWritten,(LPOVERLAPPED)0x0);
          CloseHandle(hFile);
          if (local_4b0[0] == DVar1) {
            local_4a8.cb = 0x68;
            local_4c8.dwProcessId = 0;
            local_4c8.dwThreadId = 0;
            uVar7 = 0;
            uVar4 = 0;
            local_4a8.lpReserved = (LPWSTR)0x0;
            local_4a8.lpDesktop = (LPWSTR)0x0;
            local_4a8.lpTitle = (LPWSTR)0x0;
            local_4a8.dwX = 0;
            local_4a8.dwY = 0;
            local_4a8.dwXSize = 0;
            local_4a8.dwYSize = 0;
            local_4a8.dwXCountChars = 0;
            local_4a8.dwYCountChars = 0;
            local_4a8.dwFillAttribute = 0;
            local_4a8.dwFlags = 0;
            local_4a8.wShowWindow = 0;
            local_4a8.cbReserved2 = 0;
            local_4a8._68_4_ = 0;
            local_4a8.lpReserved2 = (LPBYTE)0x0;
            local_4a8.hStdInput = (HANDLE)0x0;
            local_4a8.hStdOutput = (HANDLE)0x0;
            local_4a8.hStdError = (HANDLE)0x0;
            local_4c8.hProcess = (HANDLE)0x0;
            local_4c8.hThread = (HANDLE)0x0;
            BVar2 = CreateProcessW(local_438,(LPWSTR)0x0,(LPSECURITY_ATTRIBUTES)0x0,
                                   (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                                   &local_4a8,&local_4c8);
            if (BVar2 != 0) {
              CloseHandle(local_4c8.hProcess);
              BVar2 = CloseHandle(local_4c8.hThread);
              return CONCAT71((int7)(CONCAT44(extraout_var,BVar2) >> 8),1);
            }
            DVar1 = GetLastError();
            uVar3 = FUN_140001070("CreateProcess failed (%lu).\n",(ulonglong)DVar1,uVar4,uVar7);
          }
          else {
            uVar3 = FUN_140001070("Failed to write all bytes to disk.\n",lpBuffer,uVar3,
                                  lpNumberOfBytesWritten);
          }
        }
        uVar3 = uVar3 & 0xffffffffffffff00;
      }
    }
  }
  return uVar3;
}


// ==== FUN_140001680 @ 140001680

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

INT_PTR FUN_140001680(void)

{
  undefined1 auVar1 [16];
  HMODULE pHVar2;
  FARPROC pFVar3;
  HANDLE pvVar4;
  INT_PTR IVar5;
  undefined1 auStack_188 [32];
  undefined1 *local_168;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined2 local_144;
  undefined1 local_142;
  longlong local_140;
  longlong local_138;
  undefined1 local_130 [8];
  undefined1 local_128 [8];
  undefined1 local_120 [8];
  byte local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_140006000 ^ (ulonglong)auStack_188;
  local_158 = 0x85a99a7c;
  local_154 = 0x9a98a4a7;
  local_150 = 0x9e89a8a8;
  local_14c = CONCAT13(local_14c._3_1_,0xa89aa2);
  pHVar2 = GetModuleHandleA("kernel32.dll");
  if ((pHVar2 == (HMODULE)0x0) && (pHVar2 = LoadLibraryA("kernel32.dll"), pHVar2 == (HMODULE)0x0)) {
    return 0;
  }
  memset(local_118,0,0x100);
  FUN_140001130((longlong)&local_158,0xf,local_118);
  pFVar3 = GetProcAddress(pHVar2,(LPCSTR)local_118);
  if (pFVar3 == (FARPROC)0x0) {
    return 0;
  }
  pvVar4 = GetCurrentProcess();
  local_168 = local_130;
  IVar5 = (*pFVar3)(pvVar4,&local_138,local_120,local_128);
  if ((int)IVar5 != 0) {
    local_158 = 0x20413214;
    local_154 = 0x32414046;
    local_150 = 0x3a36213a;
    local_14c = 0x13400e32;
    local_148 = 0x21323936;
    local_144 = 0x3a36;
    local_142 = 0x32;
    pHVar2 = GetModuleHandleA("kernel32.dll");
    if ((pHVar2 != (HMODULE)0x0) || (pHVar2 = LoadLibraryA("kernel32.dll"), pHVar2 != (HMODULE)0x0))
    {
      memset(local_118,0,0x100);
      FUN_140001130((longlong)&local_158,0x17,local_118);
      pFVar3 = GetProcAddress(pHVar2,(LPCSTR)local_118);
      if (pFVar3 != (FARPROC)0x0) {
        (*pFVar3)(&local_140);
      }
    }
    auVar1._8_8_ = 0;
    auVar1._0_8_ = local_140 - local_138;
    DAT_140006670 = (ulonglong)(local_140 - local_138) / 600000000;
    return SUB168(ZEXT816(0xe5109ec205d7bea7) * auVar1,0);
  }
  return IVar5;
}


// ==== FUN_140001860 @ 140001860

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140001860(longlong *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 auVar4 [16];
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  char cVar11;
  char cVar15;
  undefined8 uVar19;
  int iVar20;
  BOOL BVar21;
  DWORD DVar22;
  int iVar23;
  ulonglong uVar24;
  uint *puVar25;
  ulonglong uVar26;
  longlong lVar27;
  ulonglong uVar28;
  undefined1 *puVar29;
  short sVar30;
  uint uVar31;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  short sVar37;
  uint uVar38;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  undefined1 auStack_218 [32];
  uint local_1f8;
  uint local_1e8;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  uint local_1c8 [4];
  byte abStack_1b8 [240];
  _union_552 local_c8 [8];
  int local_a8;
  _MEMORYSTATUSEX local_98;
  uint local_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  byte abStack_48 [48];
  ulonglong local_18;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar16;
  char cVar17;
  char cVar18;
  undefined4 uVar32;
  undefined6 uVar33;
  undefined4 uVar39;
  undefined6 uVar40;
  
  local_18 = DAT_140006000 ^ (ulonglong)auStack_218;
  local_1d8 = _DAT_140004690;
  uVar19 = local_1d8;
  uStack_1d0 = _UNK_140004698;
  local_1d8._0_4_ = (uint)_DAT_140004690;
  local_1e8 = 0xdeadbeef;
  puVar25 = local_1c8 + 1;
  iVar23 = 8;
  do {
    iVar20 = iVar23 + -8;
    iVar1 = iVar23 + -4;
    iVar44 = (int)DAT_140004660;
    iVar45 = DAT_140004660._4_4_;
    iVar46 = DAT_140004660._8_4_;
    iVar47 = DAT_140004660._12_4_;
    iVar2 = iVar23 + 4;
    uVar31 = iVar20 + iVar44 & _DAT_140004670;
    uVar34 = iVar20 + iVar45 & _UNK_140004674;
    uVar35 = iVar20 + iVar46 & _UNK_140004678;
    uVar36 = iVar20 + iVar47 & _UNK_14000467c;
    uVar38 = iVar1 + iVar44 & _DAT_140004670;
    uVar41 = iVar1 + iVar45 & _UNK_140004674;
    uVar42 = iVar1 + iVar46 & _UNK_140004678;
    uVar43 = iVar1 + iVar47 & _UNK_14000467c;
    sVar5 = (short)uVar31;
    cVar11 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar31 - (0xff < sVar5);
    sVar5 = (short)(uVar31 >> 0x10);
    sVar30 = CONCAT11((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar31 >> 0x10) - (0xff < sVar5),cVar11
                     );
    sVar5 = (short)uVar34;
    cVar12 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar34 - (0xff < sVar5);
    sVar5 = (short)(uVar34 >> 0x10);
    uVar32 = CONCAT13((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar34 >> 0x10) - (0xff < sVar5),
                      CONCAT12(cVar12,sVar30));
    sVar5 = (short)uVar35;
    cVar13 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar35 - (0xff < sVar5);
    sVar5 = (short)(uVar35 >> 0x10);
    uVar33 = CONCAT15((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar35 >> 0x10) - (0xff < sVar5),
                      CONCAT14(cVar13,uVar32));
    sVar5 = (short)uVar36;
    cVar14 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar36 - (0xff < sVar5);
    sVar6 = (short)(uVar36 >> 0x10);
    sVar5 = (short)uVar38;
    cVar15 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar38 - (0xff < sVar5);
    sVar5 = (short)(uVar38 >> 0x10);
    sVar37 = CONCAT11((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar38 >> 0x10) - (0xff < sVar5),cVar15
                     );
    sVar5 = (short)uVar41;
    cVar16 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar41 - (0xff < sVar5);
    sVar5 = (short)(uVar41 >> 0x10);
    uVar39 = CONCAT13((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar41 >> 0x10) - (0xff < sVar5),
                      CONCAT12(cVar16,sVar37));
    sVar5 = (short)uVar42;
    cVar17 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar42 - (0xff < sVar5);
    sVar5 = (short)(uVar42 >> 0x10);
    uVar40 = CONCAT15((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar42 >> 0x10) - (0xff < sVar5),
                      CONCAT14(cVar17,uVar39));
    sVar5 = (short)uVar43;
    cVar18 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar43 - (0xff < sVar5);
    sVar10 = (short)(uVar43 >> 0x10);
    sVar5 = (short)((uint)uVar32 >> 0x10);
    sVar7 = (short)((uint6)uVar33 >> 0x20);
    sVar9 = (short)(CONCAT17((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar36 >> 0x10) - (0xff < sVar6)
                             ,CONCAT16(cVar14,uVar33)) >> 0x30);
    sVar6 = (short)((uint)uVar39 >> 0x10);
    sVar8 = (short)((uint6)uVar40 >> 0x20);
    sVar10 = (short)(CONCAT17((0 < sVar10) * (sVar10 < 0x100) * (char)(uVar43 >> 0x10) -
                              (0xff < sVar10),CONCAT16(cVar18,uVar40)) >> 0x30);
    puVar25[-1] = CONCAT13((0 < sVar9) * (sVar9 < 0x100) * cVar14 - (0xff < sVar9),
                           CONCAT12((0 < sVar7) * (sVar7 < 0x100) * cVar13 - (0xff < sVar7),
                                    CONCAT11((0 < sVar5) * (sVar5 < 0x100) * cVar12 - (0xff < sVar5)
                                             ,(0 < sVar30) * (sVar30 < 0x100) * cVar11 -
                                              (0xff < sVar30)))) ^ (uint)local_1d8;
    *puVar25 = CONCAT13((0 < sVar10) * (sVar10 < 0x100) * cVar18 - (0xff < sVar10),
                        CONCAT12((0 < sVar8) * (sVar8 < 0x100) * cVar17 - (0xff < sVar8),
                                 CONCAT11((0 < sVar6) * (sVar6 < 0x100) * cVar16 - (0xff < sVar6),
                                          (0 < sVar37) * (sVar37 < 0x100) * cVar15 - (0xff < sVar37)
                                         ))) ^ (uint)local_1d8;
    uVar31 = iVar23 + iVar44 & _DAT_140004670;
    uVar34 = iVar23 + iVar45 & _UNK_140004674;
    uVar35 = iVar23 + iVar46 & _UNK_140004678;
    uVar36 = iVar23 + iVar47 & _UNK_14000467c;
    sVar5 = (short)uVar31;
    cVar11 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar31 - (0xff < sVar5);
    sVar5 = (short)(uVar31 >> 0x10);
    sVar30 = CONCAT11((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar31 >> 0x10) - (0xff < sVar5),cVar11
                     );
    sVar5 = (short)uVar34;
    cVar12 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar34 - (0xff < sVar5);
    sVar5 = (short)(uVar34 >> 0x10);
    uVar32 = CONCAT13((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar34 >> 0x10) - (0xff < sVar5),
                      CONCAT12(cVar12,sVar30));
    sVar5 = (short)uVar35;
    cVar13 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar35 - (0xff < sVar5);
    sVar5 = (short)(uVar35 >> 0x10);
    uVar33 = CONCAT15((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar35 >> 0x10) - (0xff < sVar5),
                      CONCAT14(cVar13,uVar32));
    sVar5 = (short)uVar36;
    cVar14 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar36 - (0xff < sVar5);
    sVar6 = (short)(uVar36 >> 0x10);
    uVar31 = iVar2 + iVar44 & _DAT_140004670;
    uVar34 = iVar2 + iVar45 & _UNK_140004674;
    uVar35 = iVar2 + iVar46 & _UNK_140004678;
    uVar38 = iVar2 + iVar47 & _UNK_14000467c;
    sVar5 = (short)uVar31;
    cVar15 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar31 - (0xff < sVar5);
    sVar5 = (short)(uVar31 >> 0x10);
    sVar37 = CONCAT11((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar31 >> 0x10) - (0xff < sVar5),cVar15
                     );
    sVar5 = (short)uVar34;
    cVar16 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar34 - (0xff < sVar5);
    sVar5 = (short)(uVar34 >> 0x10);
    uVar39 = CONCAT13((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar34 >> 0x10) - (0xff < sVar5),
                      CONCAT12(cVar16,sVar37));
    sVar5 = (short)uVar35;
    cVar17 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar35 - (0xff < sVar5);
    sVar5 = (short)(uVar35 >> 0x10);
    uVar40 = CONCAT15((0 < sVar5) * (sVar5 < 0x100) * (char)(uVar35 >> 0x10) - (0xff < sVar5),
                      CONCAT14(cVar17,uVar39));
    sVar5 = (short)uVar38;
    cVar18 = (0 < sVar5) * (sVar5 < 0x100) * (char)uVar38 - (0xff < sVar5);
    sVar10 = (short)(uVar38 >> 0x10);
    iVar1 = iVar23 + 8;
    sVar5 = (short)((uint)uVar32 >> 0x10);
    sVar7 = (short)((uint6)uVar33 >> 0x20);
    sVar9 = (short)(CONCAT17((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar36 >> 0x10) - (0xff < sVar6)
                             ,CONCAT16(cVar14,uVar33)) >> 0x30);
    sVar6 = (short)((uint)uVar39 >> 0x10);
    sVar8 = (short)((uint6)uVar40 >> 0x20);
    sVar10 = (short)(CONCAT17((0 < sVar10) * (sVar10 < 0x100) * (char)(uVar38 >> 0x10) -
                              (0xff < sVar10),CONCAT16(cVar18,uVar40)) >> 0x30);
    puVar25[1] = CONCAT13((0 < sVar9) * (sVar9 < 0x100) * cVar14 - (0xff < sVar9),
                          CONCAT12((0 < sVar7) * (sVar7 < 0x100) * cVar13 - (0xff < sVar7),
                                   CONCAT11((0 < sVar5) * (sVar5 < 0x100) * cVar12 - (0xff < sVar5),
                                            (0 < sVar30) * (sVar30 < 0x100) * cVar11 -
                                            (0xff < sVar30)))) ^ (uint)local_1d8;
    puVar25[2] = CONCAT13((0 < sVar10) * (sVar10 < 0x100) * cVar18 - (0xff < sVar10),
                          CONCAT12((0 < sVar8) * (sVar8 < 0x100) * cVar17 - (0xff < sVar8),
                                   CONCAT11((0 < sVar6) * (sVar6 < 0x100) * cVar16 - (0xff < sVar6),
                                            (0 < sVar37) * (sVar37 < 0x100) * cVar15 -
                                            (0xff < sVar37)))) ^ (uint)local_1d8;
    puVar25 = puVar25 + 4;
    iVar23 = iVar23 + 0x10;
  } while (iVar1 < 0x100);
  uVar28 = 0;
  uVar24 = uVar28;
  do {
    iVar23 = (int)uVar24;
    uVar31 = iVar23 * 0x1337 ^ local_1e8;
    uVar31 = uVar31 >> 0x1b | uVar31 << 5;
    local_1e8 = uVar31 % 0xff ^ local_1e8;
    uVar26 = uVar24 & 0xff;
    uVar24 = (ulonglong)(iVar23 + 1U);
    puVar29 = (undefined1 *)((longlong)local_1c8 + uVar26);
    uVar26 = (ulonglong)(uVar31 + iVar23 & 0xff);
    uVar3 = *puVar29;
    *puVar29 = *(undefined1 *)((longlong)local_1c8 + uVar26);
    *(undefined1 *)((longlong)local_1c8 + uVar26) = uVar3;
  } while ((int)(iVar23 + 1U) < 10000);
  local_1d8 = uVar19;
  GetSystemInfo((LPSYSTEM_INFO)&local_c8[0].s);
  local_1e8 = local_1e8 + local_a8 ^ (uint)(ushort)local_c8[0]._0_2_;
  local_98.dwLength = 0x40;
  BVar21 = GlobalMemoryStatusEx(&local_98);
  if (BVar21 != 0) {
    auVar4._8_8_ = 0;
    auVar4._0_8_ = local_98.ullTotalPhys;
    lVar27 = SUB168(ZEXT816(0x4f8b588e368f0847) * auVar4,8);
    local_1e8 = local_1e8 +
                (int)local_98.ullTotalPhys +
                (int)((local_98.ullTotalPhys - lVar27 >> 1) + lVar27 >> 0x10) * -100000;
  }
  DVar22 = GetTickCount();
  local_1f8 = local_1e8;
  FUN_1400010d0(&local_58,0x40,"Telemetry_%u_%x",(ulonglong)DVar22);
  if (DAT_140006668 == 1) {
    FUN_140001130(*param_1,param_1[1],(byte *)param_1[2]);
    FUN_1400010d0(param_1[3],param_1[5],param_1[2],param_1[4]);
  }
  lVar27 = 4;
  local_58 = local_1c8[0] ^ local_58;
  uStack_54 = local_1c8[1] ^ uStack_54;
  uStack_50 = local_1c8[2] ^ uStack_50;
  uStack_4c = local_1c8[3] ^ uStack_4c;
  do {
    abStack_48[uVar28] = abStack_48[uVar28] ^ abStack_1b8[uVar28];
    uVar28 = uVar28 + 1;
    lVar27 = lVar27 + -1;
  } while (lVar27 != 0);
  return 0;
}


// ==== FUN_140001b20 @ 140001b20

LRESULT FUN_140001b20(HWND param_1,UINT param_2,WPARAM param_3,LONG_PTR *param_4)

{
  byte bVar1;
  LRESULT LVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte *pbVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  if (param_2 == 0x81) {
    SetWindowLongPtrW(param_1,-0x15,*param_4);
    LVar2 = 1;
  }
  else {
    puVar3 = (undefined8 *)GetWindowLongPtrW(param_1,-0x15);
    uVar8 = 0;
    bVar1 = 0;
    if (puVar3 != (undefined8 *)0x0) {
      bVar1 = (byte)*(undefined4 *)(puVar3 + 4);
      *(UINT *)(puVar3 + 4) = param_2;
    }
    if (param_2 == 1) {
      if (puVar3 != (undefined8 *)0x0) {
        if ((ulonglong)puVar3[3] < (ulonglong)puVar3[2]) {
          pbVar6 = (byte *)*puVar3;
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (pbVar6[lVar4] != 0);
          uVar9 = uVar8;
          if (lVar4 != 0) {
            do {
              pbVar6[uVar9] = pbVar6[uVar9] ^ (byte)param_2 ^ bVar1;
              pbVar6 = (byte *)*puVar3;
              uVar7 = (int)uVar8 + 1;
              uVar8 = (ulonglong)uVar7;
              uVar5 = 0xffffffffffffffff;
              do {
                uVar5 = uVar5 + 1;
              } while (pbVar6[uVar5] != 0);
              uVar9 = uVar9 + 1;
            } while ((ulonglong)(longlong)(int)uVar7 < uVar5);
          }
          *pbVar6 = *pbVar6 ^ 0x8b;
          pbVar6[1] = pbVar6[1] ^ 0x8f;
          pbVar6[2] = pbVar6[2] ^ 0x92;
          pbVar6[3] = pbVar6[3] ^ 0x85;
          pbVar6[4] = pbVar6[4] ^ 0x88;
          pbVar6[5] = pbVar6[5] ^ 0x96;
          pbVar6[6] = pbVar6[6] ^ 0x98;
          pbVar6[7] = pbVar6[7] ^ 0x9b;
          pbVar6[8] = pbVar6[8] ^ 0x94;
          pbVar6[9] = pbVar6[9] ^ 0x8b;
          pbVar6[10] = pbVar6[10] ^ 0x95;
          pbVar6[0xb] = pbVar6[0xb] ^ 0xe6;
          pbVar6[0xc] = pbVar6[0xc] ^ 0xed;
          pbVar6[0xd] = pbVar6[0xd] ^ 0xf0;
          pbVar6[0xe] = pbVar6[0xe] ^ 0xe7;
        }
        else {
          pbVar6 = (byte *)puVar3[1];
          *pbVar6 = *pbVar6 ^ 0x8b;
          pbVar6[1] = pbVar6[1] ^ 0x8f;
          pbVar6[2] = pbVar6[2] ^ 0x92;
          pbVar6[3] = pbVar6[3] ^ 0x85;
          pbVar6[4] = pbVar6[4] ^ 0x88;
          pbVar6[5] = pbVar6[5] ^ 0x96;
          pbVar6[6] = pbVar6[6] ^ 0x98;
          pbVar6[7] = pbVar6[7] ^ 0x9b;
          pbVar6[8] = pbVar6[8] ^ 0x94;
          pbVar6[9] = pbVar6[9] ^ 0x8b;
          pbVar6[10] = pbVar6[10] ^ 0x95;
          pbVar6[0xb] = pbVar6[0xb] ^ 0xe6;
          pbVar6[0xc] = pbVar6[0xc] ^ 0xed;
          pbVar6[0xd] = pbVar6[0xd] ^ 0xf0;
          pbVar6[0xe] = pbVar6[0xe] ^ 0xe7;
          SetEnvironmentVariableA("SESSION_TOKEN_CACHE",(LPCSTR)puVar3[1]);
        }
      }
      LVar2 = -1;
    }
    else {
      LVar2 = DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
    }
  }
  return LVar2;
}


// ==== FUN_140001ca0 @ 140001ca0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140001ca0(longlong *param_1)

{
  int iVar1;
  SOCKET s;
  SOCKET s_00;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStack_2e8 [32];
  sockaddr local_2c8;
  WSADATA local_2b8;
  char local_118 [9];
  char local_10f [247];
  ulonglong local_18;
  
  local_18 = DAT_140006000 ^ (ulonglong)auStack_2e8;
  iVar1 = WSAStartup(0x202,&local_2b8);
  if (iVar1 == 0) {
    s = socket(2,1,6);
    if (s != 0xffffffffffffffff) {
      local_2c8.sa_family = 2;
      local_2c8.sa_data._0_2_ = htons(0x7a69);
      inet_pton(2,"127.0.0.1",local_2c8.sa_data + 2);
      iVar1 = bind(s,&local_2c8,0x10);
      if ((iVar1 != -1) && (iVar1 = listen(s,0x7fffffff), iVar1 != -1)) {
        s_00 = accept(s,(sockaddr *)0x0,(int *)0x0);
        if (s_00 != 0xffffffffffffffff) {
          memset(local_118,0,0x100);
          iVar1 = recv(s_00,local_118,0xff,0);
          if ((8 < iVar1) && (iVar1 = strncmp(local_118,"OVERRIDE:",9), iVar1 == 0)) {
            strncpy_s((char *)*param_1,param_1[1],local_10f,0xffffffffffffffff);
            lVar4 = *param_1;
            uVar5 = 0;
            lVar2 = -1;
            do {
              lVar2 = lVar2 + 1;
            } while (*(char *)(lVar4 + lVar2) != '\0');
            if (lVar2 != 0) {
              do {
                *(byte *)(lVar4 + uVar5) = *(byte *)(lVar4 + uVar5) ^ 0x33;
                *(char *)(*param_1 + uVar5) = *(char *)(*param_1 + uVar5) + '\x05';
                uVar3 = 0xffffffffffffffff;
                lVar4 = *param_1;
                uVar5 = uVar5 + 1;
                do {
                  uVar3 = uVar3 + 1;
                } while (*(char *)(lVar4 + uVar3) != '\0');
              } while (uVar5 < uVar3);
            }
          }
          closesocket(s_00);
        }
        closesocket(s);
        WSACleanup();
        return 0;
      }
      closesocket(s);
    }
    WSACleanup();
  }
  return 1;
}


// ==== FUN_140001ea0 @ 140001ea0

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140001ea0(void)

{
  longlong lVar1;
  DWORD DVar2;
  BOOL BVar3;
  HMODULE pHVar4;
  FARPROC pFVar5;
  char *pcVar6;
  longlong lVar7;
  longlong *lpParameter;
  HANDLE pvVar8;
  FARPROC pFVar9;
  longlong lVar10;
  INT_PTR IVar11;
  undefined *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  undefined *puVar16;
  byte *pbVar17;
  undefined8 in_R9;
  LPDWORD lpNumberOfBytesWritten;
  undefined1 auStackY_7a8 [32];
  undefined4 local_748;
  undefined4 local_744;
  undefined4 local_740;
  undefined4 local_73c;
  undefined4 local_738;
  undefined2 local_734;
  undefined1 local_732;
  char *local_730;
  undefined8 *local_728;
  undefined8 local_720;
  longlong local_718;
  undefined4 local_710;
  undefined4 *local_708;
  undefined8 local_700;
  undefined1 *local_6f8;
  CHAR *local_6f0;
  CHAR *local_6e8;
  undefined8 local_6e0;
  undefined8 local_6d8;
  code *local_6d0;
  undefined8 local_6c8;
  HMODULE pHStack_6c0;
  undefined8 local_6b8;
  undefined8 uStack_6b0;
  undefined8 local_6a8;
  undefined8 uStack_6a0;
  undefined *local_698;
  undefined8 uStack_690;
  uint local_688 [2];
  undefined4 local_680;
  undefined4 local_67c;
  undefined4 local_678;
  undefined4 local_674;
  undefined4 local_670;
  undefined4 local_66c;
  undefined4 local_668;
  undefined4 local_664;
  undefined2 local_660;
  undefined1 local_65e;
  undefined8 local_658;
  undefined8 uStack_650;
  undefined4 local_648;
  undefined2 local_644;
  undefined1 local_642;
  byte local_638 [256];
  char local_538 [256];
  CHAR local_438 [272];
  CHAR local_328 [272];
  byte local_218 [256];
  undefined1 local_118 [256];
  ulonglong local_18;
  
  local_18 = DAT_140006000 ^ (ulonglong)auStackY_7a8;
  memset(local_538,0,0x100);
  memset(local_438,0,0x104);
  memset(local_328,0,0x104);
  memset(local_118,0,0x100);
  local_680 = 0x3c1d40f2;
  local_67c = 0x42374639;
  local_678 = 0x1d323036;
  local_674 = 0x3c36413c;
  local_670 = 0x4541fb3b;
  local_66c = 0x3c190741;
  local_668 = 0x3c23313f;
  local_664 = 0x3a323139;
  local_660 = 0x3f3c;
  local_65e = 0x41;
  GetConsoleWindow();
  local_748 = 0x5a4f4479;
  local_744 = 0x445b5875;
  local_740 = 0x46535956;
  local_73c = CONCAT31(local_73c._1_3_,0x50);
  pHVar4 = GetModuleHandleA("user32.dll");
  if ((pHVar4 != (HMODULE)0x0) || (pHVar4 = LoadLibraryA("user32.dll"), pHVar4 != (HMODULE)0x0)) {
    memset(local_638,0,0x100);
    FUN_140001130((longlong)&local_748,0xd,local_638);
    pFVar5 = GetProcAddress(pHVar4,(LPCSTR)local_638);
    if (pFVar5 != (FARPROC)0x0) {
      (*pFVar5)();
    }
  }
  uVar15 = 0x104;
  DVar2 = GetModuleFileNameA((HMODULE)0x0,local_438,0x104);
  if (DVar2 == 0) {
    DVar2 = GetLastError();
    FUN_140001070("[Parent] Failed to get executable path. Error: %lu\n",(ulonglong)DVar2,uVar15,
                  in_R9);
    return 1;
  }
  pcVar6 = strrchr(local_438,0x5c);
  if (pcVar6 == (char *)0x0) {
    pcVar6 = local_438;
  }
  else {
    pcVar6 = pcVar6 + 1;
  }
  uVar13 = 0xffffffffffffffff;
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (pcVar6[lVar7] != '\0');
  pcVar6 = strrchr(local_438,0x5c);
  if (pcVar6 != (char *)0x0) {
    pcVar6[1] = '\0';
  }
  FUN_1400010d0(local_328,0x104,"%sPolyjuicePotion.txt",local_438);
  local_708 = &local_680;
  local_700 = 0x23;
  local_6f8 = local_118;
  local_6e0 = 0x104;
  local_6f0 = local_328;
  local_6e8 = local_438;
  lpParameter = malloc(0x10);
  if (lpParameter == (longlong *)0x0) {
LAB_1400026b1:
    uVar15 = 0;
  }
  else {
    lpParameter[1] = 0x100;
    pFVar5 = (FARPROC)0x0;
    *lpParameter = (longlong)local_538;
    pvVar8 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_140001ca0,lpParameter,0,(LPDWORD)0x0);
    Sleep(10000);
    if (pvVar8 != (HANDLE)0x0) {
      CloseHandle(pvVar8);
    }
    pvVar8 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_140001860,&local_708,0,(LPDWORD)0x0);
    if (pvVar8 != (HANDLE)0x0) {
      WaitForSingleObject(pvVar8,0xffffffff);
      CloseHandle(pvVar8);
    }
    pHVar4 = GetModuleHandleA("ntdll.dll");
    memset(local_638,0,0x100);
    local_748 = 0x4f65407a;
    local_744 = 0x525a7b40;
    local_740 = 0x53574659;
    local_73c = 0x5a595b40;
    local_738 = 0x4f465c60;
    local_734 = 0x5053;
    FUN_140001130((longlong)&local_748,0x16,local_638);
    if ((pHVar4 != (HMODULE)0x0) &&
       (pFVar9 = GetProcAddress(pHVar4,(LPCSTR)local_638), pFVar9 != (FARPROC)0x0)) {
      (*pFVar9)(0xfffffffffffffffe,0x11,0);
    }
    pvVar8 = CreateFileA(local_328,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar8 != (HANDLE)0xffffffffffffffff) {
      BVar3 = ReadFile(pvVar8,local_538,0xff,local_688,(LPOVERLAPPED)0x0);
      if (BVar3 != 0) {
        local_538[local_688[0]] = '\0';
        CloseHandle(pvVar8);
        local_658 = _DAT_140004680;
        uStack_650 = _UNK_140004688;
        local_648 = 0x3239392e;
        local_644 = 0x343b;
        local_642 = 0x32;
        FUN_140001680();
        local_710 = 0;
        local_6d8 = 0x50;
        local_730 = local_538;
        local_6c8 = 0;
        pHStack_6c0 = (HMODULE)0x0;
        local_728 = &local_658;
        local_6b8 = 0;
        uStack_6b0 = 0;
        local_720 = DAT_140006670;
        local_718 = (longlong)((int)lVar7 * 0x29f + 0xf);
        local_6d0 = FUN_140001b20;
        local_6a8 = 0;
        uStack_6a0 = 0;
        local_698 = (undefined *)0x0;
        uStack_690 = 0;
        pHStack_6c0 = GetModuleHandleW((LPCWSTR)0x0);
        local_748 = 0x5b514f66;
        local_698 = &DAT_1400045a0;
        local_744 = 0x464f4045;
        local_740 = 0x45535875;
        local_73c = 0x734c6f45;
        pHVar4 = GetModuleHandleA("user32.dll");
        if ((pHVar4 != (HMODULE)0x0) ||
           (pHVar4 = LoadLibraryA("user32.dll"), pFVar9 = pFVar5, pHVar4 != (HMODULE)0x0)) {
          memset(local_638,0,0x100);
          FUN_140001130((longlong)&local_748,0x10,local_638);
          pFVar9 = GetProcAddress(pHVar4,(LPCSTR)local_638);
        }
        (*pFVar9)(&local_6d8);
        local_748 = 0x969aa778;
        local_744 = 0x9e8c9aa9;
        local_740 = 0xaca499a3;
        local_73c = CONCAT13(local_73c._3_1_,0x76ad7a);
        pHVar4 = GetModuleHandleA("user32.dll");
        if ((pHVar4 != (HMODULE)0x0) ||
           (pHVar4 = LoadLibraryA("user32.dll"), pFVar9 = pFVar5, pHVar4 != (HMODULE)0x0)) {
          memset(local_638,0,0x100);
          FUN_140001130((longlong)&local_748,0xf,local_638);
          pFVar9 = GetProcAddress(pHVar4,(LPCSTR)local_638);
        }
        uVar15 = 0xcf0000;
        puVar16 = &DAT_1400045a4;
        puVar12 = &DAT_1400045a0;
        (*pFVar9)(0);
        lVar7 = -1;
        do {
          lVar10 = lVar7 + 1;
          lVar1 = lVar7 + 1;
          lVar7 = lVar10;
        } while (local_538[lVar1] != '\0');
        if ((int)lVar10 < 0x15) {
          if (local_538[0] == 'A') {
            pcVar6 = 
            "\n[*] The Polyjuice Potion is still effective, preventing the true identity from being revealed.\n"
            ;
            goto LAB_1400024a7;
          }
        }
        else {
          pcVar6 = "\n[*] Try harded to find the secrets.\n";
LAB_1400024a7:
          FUN_140001070(pcVar6,puVar12,puVar16,uVar15);
        }
        memset(local_218,0,0x100);
        local_748 = 0x29fb2929;
        local_744 = 0x323d363d;
        local_740 = 0x2e391329;
        local_73c = 0x3510323f;
        local_738 = 0x3239392e;
        local_734 = 0x343b;
        local_732 = 0x32;
        FUN_140001130((longlong)&local_748,0x17,local_218);
        local_748 = 0x534f4675;
        local_744 = 0x537a4f40;
        local_740 = 0x64504f57;
        local_73c = 0x734f445b;
        pHVar4 = GetModuleHandleA("kernel32.dll");
        if ((pHVar4 != (HMODULE)0x0) ||
           (pHVar4 = LoadLibraryA("kernel32.dll"), pHVar4 != (HMODULE)0x0)) {
          memset(local_638,0,0x100);
          FUN_140001130((longlong)&local_748,0x10,local_638);
          pFVar9 = GetProcAddress(pHVar4,(LPCSTR)local_638);
          if (pFVar9 != (FARPROC)0x0) {
            lpNumberOfBytesWritten = (LPDWORD)0x1;
            pbVar17 = (byte *)0x6;
            pvVar8 = (HANDLE)(*pFVar9)(local_218);
            if (pvVar8 == (HANDLE)0xffffffffffffffff) goto LAB_1400026ed;
            FUN_140001400();
            local_748 = 0x5a5a5975;
            local_744 = 0x7a40554f;
            local_740 = 0x504f5753;
            local_73c = 0x4f445b64;
            pHVar4 = GetModuleHandleA("kernel32.dll");
            if ((pHVar4 != (HMODULE)0x0) ||
               (pHVar4 = LoadLibraryA("kernel32.dll"), pHVar4 != (HMODULE)0x0)) {
              memset(local_638,0,0x100);
              pbVar17 = local_638;
              FUN_140001130((longlong)&local_748,0x10,pbVar17);
              pFVar5 = GetProcAddress(pHVar4,(LPCSTR)local_638);
            }
            pcVar6 = (char *)0x0;
            IVar11 = (*pFVar5)(pvVar8);
            if ((IVar11 != 0) || (DVar2 = GetLastError(), DVar2 == 0x217)) {
              do {
                uVar14 = uVar13 + 1;
                lVar7 = uVar13 + 1;
                uVar13 = uVar14;
              } while (local_538[lVar7] != '\0');
              lpNumberOfBytesWritten = local_688;
              pbVar17 = (byte *)(uVar14 & 0xffffffff);
              pcVar6 = local_538;
              WriteFile(pvVar8,pcVar6,(DWORD)uVar14,lpNumberOfBytesWritten,(LPOVERLAPPED)0x0);
            }
            CloseHandle(pvVar8);
            FUN_140001070("[+] Execution complete.\n",pcVar6,pbVar17,lpNumberOfBytesWritten);
          }
        }
        goto LAB_1400026b1;
      }
      CloseHandle(pvVar8);
    }
LAB_1400026ed:
    uVar15 = 1;
  }
  return uVar15;
}


// ==== __security_check_cookie @ 140002710

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_140006000) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_1400029d8();
  return;
}


// ==== FUN_140002730 @ 140002730

void FUN_140002730(void)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  undefined7 extraout_var;
  
  _set_app_type(1);
  uVar5 = FUN_140002e1c();
  _set_fmode((int)uVar5);
  uVar5 = FUN_140002e10();
  puVar6 = (undefined4 *)__p__commode();
  *puVar6 = (int)uVar5;
  uVar5 = __scrt_initialize_onexit_tables(1);
  if ((char)uVar5 != '\0') {
    FUN_1400030a4();
    atexit(FUN_1400030e0);
    uVar7 = FUN_140002e14();
    iVar4 = _configure_narrow_argv(uVar7 & 0xffffffff);
    if (iVar4 == 0) {
      FUN_140002e24();
      bVar2 = FUN_140002e60();
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        __setusermatherr(FUN_140002e10);
      }
      _guard_check_icall();
      _guard_check_icall();
      uVar5 = FUN_140002e10();
      _configthreadlocale((int)uVar5);
      cVar3 = FUN_140002e34();
      if (cVar3 != '\0') {
        _initialize_narrow_environment();
      }
      FUN_140002e10();
      uVar5 = thunk_FUN_140002e10();
      if ((int)uVar5 == 0) {
        return;
      }
    }
  }
  FUN_140002e88(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_1400027e8 @ 1400027e8

undefined8 FUN_1400027e8(void)

{
  FUN_140002e44();
  return 0;
}


// ==== FUN_1400027f8 @ 1400027f8

void FUN_1400027f8(void)

{
  ulonglong uVar1;
  
  FUN_140003030();
  uVar1 = FUN_140002e10();
  _set_new_mode(uVar1 & 0xffffffff);
  return;
}


// ==== FUN_140002814 @ 140002814

ulonglong FUN_140002814(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  uint *puVar7;
  ulonglong uVar8;
  undefined8 unaff_RBX;
  undefined8 in_R9;
  undefined1 uVar9;
  
  iVar3 = (int)unaff_RBX;
  uVar4 = FUN_140002b5c(1);
  if ((char)uVar4 == '\0') {
    FUN_140002e88(7);
  }
  else {
    bVar1 = false;
    uVar9 = 0;
    uVar4 = __scrt_acquire_startup_lock();
    iVar3 = (int)CONCAT71((int7)((ulonglong)unaff_RBX >> 8),(char)uVar4);
    if (DAT_1400065f0 != 1) {
      if (DAT_1400065f0 == 0) {
        DAT_1400065f0 = 1;
        iVar3 = _initterm_e(&DAT_140004360,&DAT_140004378);
        if (iVar3 != 0) {
          return 0xff;
        }
        _initterm(&DAT_140004348,&DAT_140004358);
        DAT_1400065f0 = 2;
      }
      else {
        bVar1 = true;
        uVar9 = 1;
      }
      __scrt_release_startup_lock((char)uVar4);
      plVar5 = (longlong *)FUN_140002e6c();
      if ((*plVar5 != 0) && (uVar6 = FUN_140002c24((longlong)plVar5), (char)uVar6 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_140004320)(0,2,0,in_R9,uVar9);
      }
      plVar5 = (longlong *)FUN_140002e74();
      if ((*plVar5 != 0) && (uVar6 = FUN_140002c24((longlong)plVar5), (char)uVar6 != '\0')) {
        _register_thread_local_exe_atexit_callback(*plVar5);
      }
      _get_initial_narrow_environment();
      __p___argv();
      puVar7 = (uint *)__p___argc();
      uVar8 = (ulonglong)*puVar7;
      uVar6 = FUN_140001ea0();
      iVar3 = (int)uVar6;
      bVar2 = FUN_140002fdc();
      if (bVar2) {
        if (!bVar1) {
          _cexit();
        }
        __scrt_uninitialize_crt(CONCAT71((int7)(uVar8 >> 8),1),'\0');
        return uVar6 & 0xffffffff;
      }
      goto LAB_140002980;
    }
  }
  FUN_140002e88(7);
LAB_140002980:
                    /* WARNING: Subroutine does not return */
  exit(iVar3);
}


// ==== entry @ 140002990

void entry(void)

{
  FUN_140002d60();
  FUN_140002814();
  return;
}


// ==== __raise_securityfailure @ 1400029a4

/* Library Function - Single Match
    __raise_securityfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x0001400029d1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}


// ==== FUN_1400029d8 @ 1400029d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400029d8(void)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  puVar3 = auStack_38;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x140002a03;
  FUN_140002aac((PCONTEXT)&DAT_140006120);
  _DAT_140006090 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_1400061b8 = puVar3 + 0x40;
  _DAT_1400061a0 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_140006080 = 0xc0000409;
  _DAT_140006084 = 1;
  _DAT_140006098 = 1;
  DAT_1400060a0 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_140006000;
  *(undefined8 *)(puVar3 + 0x28) = DAT_140006040;
  *(undefined8 *)(puVar3 + -8) = 0x140002aa5;
  DAT_140006218 = _DAT_140006090;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1400043a0);
  return;
}


// ==== FUN_140002aac @ 140002aac

void FUN_140002aac(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  int iVar1;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18 [2];
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  iVar1 = 0;
  do {
    FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
    if (FunctionEntry == (PRUNTIME_FUNCTION)0x0) {
      return;
    }
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}


// ==== __scrt_acquire_startup_lock @ 140002b20

/* Library Function - Single Match
    __scrt_acquire_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

ulonglong __scrt_acquire_startup_lock(void)

{
  ulonglong uVar1;
  bool bVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  
  bVar2 = __scrt_is_ucrt_dll_in_use();
  uVar3 = CONCAT71(extraout_var,bVar2);
  if ((int)uVar3 == 0) {
LAB_140002b4e:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_1400065f8 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_1400065f8;
        uVar1 = DAT_1400065f8;
      }
      DAT_1400065f8 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_140002b4e;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}


// ==== FUN_140002b5c @ 140002b5c

longlong FUN_140002b5c(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_140006600 = 1;
  }
  FUN_14000311c();
  cVar1 = FUN_140002e34();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_140002e34();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_140002e34();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}


// ==== __scrt_initialize_onexit_tables @ 140002b98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __scrt_initialize_onexit_tables
   
   Library: Visual Studio 2019 Release */

undefined8 __scrt_initialize_onexit_tables(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  ulonglong in_RAX;
  undefined7 extraout_var;
  undefined8 uVar3;
  
  if (DAT_140006601 == '\0') {
    if (1 < param_1) {
      FUN_140002e88(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_140006608 = _DAT_1400043b0;
      uRam0000000140006610 = _UNK_1400043b8;
      _DAT_140006618 = 0xffffffffffffffff;
      _DAT_140006620 = _DAT_1400043b0;
      uRam0000000140006628 = _UNK_1400043b8;
      _DAT_140006630 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_140006608);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_140006620), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_140006601 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}


// ==== FUN_140002c24 @ 140002c24

ulonglong FUN_140002c24(longlong param_1)

{
  word *pwVar1;
  ulonglong uVar2;
  uint7 uVar3;
  longlong lVar4;
  word *pwVar5;
  
  uVar2 = 0x5a4d;
  if (IMAGE_DOS_HEADER_140000000.e_magic == (char  [2])0x5a4d) {
    lVar4 = (longlong)(int)IMAGE_DOS_HEADER_140000000.e_lfanew;
    if ((*(int *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4) == 0x4550) &&
       (uVar2 = 0x20b,
       *(short *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar4 + -4) == 0x20b)) {
      pwVar5 = (word *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4 +
                       (ulonglong)
                       *(ushort *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar4 + -8) +
                       0x18);
      uVar2 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4 + 6);
      pwVar1 = pwVar5 + uVar2 * 0x14;
      for (; pwVar5 != pwVar1; pwVar5 = pwVar5 + 0x14) {
        if (((ulonglong)*(uint *)(pwVar5 + 6) <= param_1 - 0x140000000U) &&
           (uVar2 = (ulonglong)(*(int *)(pwVar5 + 4) + *(uint *)(pwVar5 + 6)),
           param_1 - 0x140000000U < uVar2)) goto LAB_140002c9a;
      }
      pwVar5 = (word *)0x0;
LAB_140002c9a:
      if (pwVar5 == (word *)0x0) {
        return uVar2 & 0xffffffffffffff00;
      }
      uVar3 = (uint7)(uVar2 >> 8);
      if (*(int *)(pwVar5 + 0x12) < 0) {
        return (ulonglong)uVar3 << 8;
      }
      return CONCAT71(uVar3,1);
    }
  }
  return uVar2 & 0xffffffffffffff00;
}


// ==== __scrt_release_startup_lock @ 140002cbc

/* Library Function - Single Match
    __scrt_release_startup_lock
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __scrt_release_startup_lock(char param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = __scrt_is_ucrt_dll_in_use();
  if ((CONCAT31(extraout_var,bVar1) != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_1400065f8 = 0;
    UNLOCK();
  }
  return;
}


// ==== __scrt_uninitialize_crt @ 140002ce0

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_140006600 == '\0') || (param_2 == '\0')) {
    FUN_140002e34();
    FUN_140002e34();
  }
  return 1;
}


// ==== _onexit @ 140002d0c

/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_140006608 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_140006608);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}


// ==== atexit @ 140002d48

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}


// ==== FUN_140002d60 @ 140002d60

void FUN_140002d60(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_140006000 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_140006000 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_140006000 == 0x2b992ddfa232) {
      DAT_140006000 = 0x2b992ddfa233;
    }
  }
  DAT_140006040 = ~DAT_140006000;
  return;
}


// ==== FUN_140002e10 @ 140002e10

undefined8 FUN_140002e10(void)

{
  return 0;
}


// ==== FUN_140002e14 @ 140002e14

undefined8 FUN_140002e14(void)

{
  return 1;
}


// ==== FUN_140002e1c @ 140002e1c

undefined8 FUN_140002e1c(void)

{
  return 0x4000;
}


// ==== FUN_140002e24 @ 140002e24

void FUN_140002e24(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002e2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_140006640);
  return;
}


// ==== FUN_140002e34 @ 140002e34

undefined1 FUN_140002e34(void)

{
  return 1;
}


// ==== _guard_check_icall @ 140002e38

void _guard_check_icall(void)

{
  return;
}


// ==== FUN_140002e3c @ 140002e3c

undefined * FUN_140002e3c(void)

{
  return &DAT_140006650;
}


// ==== FUN_140002e44 @ 140002e44

void FUN_140002e44(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_140001000();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_140002e3c();
  *puVar1 = *puVar1 | 2;
  return;
}


// ==== FUN_140002e60 @ 140002e60

bool FUN_140002e60(void)

{
  return DAT_14000604c == 0;
}


// ==== FUN_140002e6c @ 140002e6c

undefined * FUN_140002e6c(void)

{
  return &DAT_140006688;
}


// ==== FUN_140002e74 @ 140002e74

undefined * FUN_140002e74(void)

{
  return &DAT_140006680;
}


// ==== FUN_140002e7c @ 140002e7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140002e7c(void)

{
  _DAT_140006658 = 0;
  return;
}


// ==== FUN_140002e88 @ 140002e88

void FUN_140002e88(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  LONG LVar3;
  PRUNTIME_FUNCTION FunctionEntry;
  undefined1 *puVar4;
  undefined8 unaff_retaddr;
  DWORD64 local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 local_4d8 [152];
  undefined1 *local_440;
  DWORD64 local_3e0;
  
  puVar4 = auStack_5c8;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar4 = auStack_5c0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x140002ebc;
  FUN_140002e7c();
  *(undefined8 *)(puVar4 + -8) = 0x140002ecd;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x140002ed7;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x140002ef1;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x140002f35;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x140002f67;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x140002f89;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x140002fa6;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x140002fb1;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x140002fc2;
    FUN_140002e7c();
  }
  return;
}


// ==== FUN_140002fdc @ 140002fdc

bool FUN_140002fdc(void)

{
  HMODULE pHVar1;
  longlong lVar2;
  bool bVar3;
  
  pHVar1 = GetModuleHandleW((LPCWSTR)0x0);
  if ((((pHVar1 == (HMODULE)0x0) || ((short)pHVar1->unused != 0x5a4d)) ||
      (lVar2 = (longlong)pHVar1[0xf].unused, *(int *)((longlong)&pHVar1->unused + lVar2) != 0x4550))
     || ((*(short *)((longlong)&pHVar1[6].unused + lVar2) != 0x20b ||
         (*(uint *)((longlong)&pHVar1[0x21].unused + lVar2) < 0xf)))) {
    bVar3 = false;
  }
  else {
    bVar3 = *(int *)((longlong)&pHVar1[0x3e].unused + lVar2) != 0;
  }
  return bVar3;
}


// ==== FUN_140003030 @ 140003030

void FUN_140003030(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140003037. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(FUN_140003040);
  return;
}


// ==== FUN_140003040 @ 140003040

undefined8 FUN_140003040(undefined8 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  piVar2 = (int *)*param_1;
  if ((*piVar2 == -0x1f928c9d) && (piVar2[6] == 4)) {
    iVar1 = piVar2[8];
    if ((iVar1 == 0x19930520) || ((iVar1 + 0xe66cfadfU < 2 || (iVar1 == 0x1994000)))) {
      puVar4 = (undefined8 *)__current_exception();
      *puVar4 = piVar2;
      uVar3 = param_1[1];
      puVar4 = (undefined8 *)__current_exception_context();
      *puVar4 = uVar3;
                    /* WARNING: Subroutine does not return */
      terminate();
    }
  }
  return 0;
}


// ==== FUN_1400030a4 @ 1400030a4

void FUN_1400030a4(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140004b70; plVar1 < &DAT_140004b70; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_140004320)();
    }
  }
  return;
}


// ==== FUN_1400030e0 @ 1400030e0

void FUN_1400030e0(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140004b80; plVar1 < &DAT_140004b80; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_140004320)();
    }
  }
  return;
}


// ==== FUN_14000311c @ 14000311c

/* WARNING: Removing unreachable block (ram,0x00014000320d) */
/* WARNING: Removing unreachable block (ram,0x0001400031fd) */
/* WARNING: Removing unreachable block (ram,0x0001400031d8) */
/* WARNING: Removing unreachable block (ram,0x000140003156) */
/* WARNING: Removing unreachable block (ram,0x000140003134) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_14000311c(void)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  longlong lVar4;
  uint uVar5;
  byte bVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  puVar2 = (uint *)cpuid_Version_info(1);
  uVar5 = puVar2[3];
  if ((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) {
    uVar8 = *puVar2 & 0xfff3ff0;
    _DAT_140006060 = 0x8000;
    _DAT_140006068 = 0xffffffffffffffff;
    if ((((uVar8 == 0x106c0) || (uVar8 == 0x20660)) || (uVar8 == 0x20670)) ||
       ((uVar8 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar8 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_140006660 = DAT_140006660 | 1;
    }
  }
  uVar8 = 0;
  uVar10 = 0;
  uVar11 = 0;
  uVar12 = 0;
  if (6 < *piVar1) {
    piVar3 = (int *)cpuid_Extended_Feature_Enumeration_info(7);
    uVar8 = piVar3[1];
    uVar10 = piVar3[2];
    if ((uVar8 >> 9 & 1) != 0) {
      DAT_140006660 = DAT_140006660 | 2;
    }
    if (0 < *piVar3) {
      lVar4 = cpuid_Extended_Feature_Enumeration_info(7);
      uVar11 = *(uint *)(lVar4 + 8);
    }
    if (0x23 < *piVar1) {
      lVar4 = cpuid(0x24);
      uVar12 = (ulonglong)*(uint *)(lVar4 + 4);
    }
  }
  _DAT_140006058 = 1;
  DAT_14000605c = 2;
  uVar9 = DAT_140006050 & 0xfffffffffffffffe;
  if ((uVar5 >> 0x14 & 1) != 0) {
    _DAT_140006058 = 2;
    DAT_14000605c = 6;
    uVar9 = DAT_140006050 & 0xffffffffffffffee;
  }
  DAT_140006050 = uVar9;
  if ((uVar5 >> 0x1b & 1) != 0) {
    uVar9 = xinuse(0);
    uVar9 = in_XCR0 & uVar9 & 0xffffffff;
    if (((uVar5 >> 0x1c & 1) != 0) && (bVar6 = (byte)uVar9, (bVar6 & 6) == 6)) {
      _DAT_140006058 = 3;
      uVar7 = DAT_140006050;
      uVar5 = DAT_14000605c | 8;
      if ((uVar8 & 0x20) != 0) {
        _DAT_140006058 = 5;
        uVar7 = DAT_140006050 & 0xfffffffffffffffd;
        uVar5 = DAT_14000605c | 0x28;
        if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
          DAT_14000605c = DAT_14000605c | 0x68;
          _DAT_140006058 = 6;
          uVar7 = DAT_140006050 & 0xffffffffffffffd9;
          uVar5 = DAT_14000605c;
        }
      }
      DAT_14000605c = uVar5;
      DAT_140006050 = uVar7;
      if ((uVar10 >> 0x17 & 1) != 0) {
        DAT_140006050 = DAT_140006050 & 0xfffffffffeffffff;
      }
      if (((uVar11 >> 0x13 & 1) != 0) && ((bVar6 & 0xe0) == 0xe0)) {
        _DAT_14000665c = (uint)uVar12 & 0x400ff;
        DAT_140006050 = ~((ulonglong)((uint)(uVar12 >> 0x10) & 6) | 0x1000029) & DAT_140006050;
        if (1 < (byte)_DAT_14000665c) {
          DAT_140006050 = DAT_140006050 & 0xffffffffffffffbf;
        }
      }
    }
    if (((uVar11 >> 0x15 & 1) != 0) && ((uVar9 >> 0x13 & 1) != 0)) {
      DAT_140006050 = DAT_140006050 & 0xffffffffffffff7f;
    }
  }
  return 0;
}


// ==== __scrt_is_ucrt_dll_in_use @ 1400033b4

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Library: Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_140006070 != 0;
}


// ==== FUN_140003464 @ 140003464

undefined8 FUN_140003464(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  FUN_140003484(param_2,param_4);
  return 1;
}


// ==== FUN_140003484 @ 140003484

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_140003484(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  uVar1 = *(ulonglong *)(param_2 + 8);
  if ((*(byte *)(uVar2 + 3 + uVar1) & 0xf) != 0) {
    uVar1 = (ulonglong)*(byte *)(uVar2 + 3 + uVar1) & 0xfffffff0;
  }
  return uVar1;
}


// ==== _guard_dispatch_icall @ 140003500

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140003500. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== FUN_140003526 @ 140003526

void FUN_140003526(undefined8 *param_1)

{
  _seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}


// ==== FUN_140003544 @ 140003544

bool FUN_140003544(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}


