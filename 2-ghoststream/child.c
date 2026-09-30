// ==== FUN_140001000 @ 140001000

undefined * FUN_140001000(void)

{
  return &DAT_140005680;
}


// ==== FUN_140001010 @ 140001010

void FUN_140001010(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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


// ==== FUN_140001070 @ 140001070

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_140001070(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  code *pcVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  char cVar9;
  char cVar13;
  DWORD DVar17;
  BOOL BVar18;
  int iVar19;
  HANDLE hFile;
  HMODULE hModule;
  FARPROC pFVar20;
  size_t sVar21;
  char *pcVar22;
  undefined8 uVar23;
  int iVar24;
  ulonglong uVar25;
  undefined8 uVar26;
  byte *pbVar27;
  char *pcVar28;
  ulonglong uVar29;
  byte bVar30;
  undefined8 uVar32;
  PDWORD lpflOldProtect;
  DWORD *pDVar33;
  ulonglong uVar34;
  byte *pbVar35;
  undefined8 *lpAddress;
  longlong lVar36;
  ulonglong uVar37;
  short sVar38;
  short sVar39;
  uint uVar40;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  short sVar46;
  uint uVar47;
  uint uVar50;
  uint uVar51;
  uint uVar52;
  undefined1 auStackY_418 [32];
  uint local_3b0;
  uint local_3ac;
  DWORD local_3a8 [64];
  char local_2a8 [8];
  char acStack_2a0 [8];
  char local_298 [2];
  char local_296;
  CHAR local_288 [64];
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined4 local_228;
  undefined2 local_224;
  undefined1 local_222 [218];
  byte local_148 [256];
  ulonglong local_48;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar14;
  char cVar15;
  char cVar16;
  ulonglong uVar31;
  undefined4 uVar41;
  undefined6 uVar42;
  undefined4 uVar48;
  undefined6 uVar49;
  
  local_48 = DAT_140005000 ^ (ulonglong)auStackY_418;
  FUN_140001010("[Partner] Process started.\n",param_2,param_3,param_4);
  memset(local_148,0,0x100);
  uVar25 = 0;
  uVar32 = 0;
  uVar23 = 0;
  hFile = CreateFileA("\\\\.\\pipe\\FlareChallenge",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,
                      (HANDLE)0x0);
  while (hFile == (HANDLE)0xffffffffffffffff) {
    DVar17 = GetLastError();
    if (DVar17 != 0xe7) {
      DVar17 = GetLastError();
      FUN_140001010("[Partner] Could not open pipe. Error: %lu\n",(ulonglong)DVar17,uVar23,uVar32);
      Sleep(2000);
      return 1;
    }
    uVar26 = 5000;
    BVar18 = WaitNamedPipeA("\\\\.\\pipe\\FlareChallenge",5000);
    if (BVar18 == 0) {
      FUN_140001010("[Partner] Pipe timeout.\n",uVar26,uVar23,uVar32);
      return 1;
    }
    uVar32 = 0;
    uVar23 = 0;
    hFile = CreateFileA("\\\\.\\pipe\\FlareChallenge",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,
                        (HANDLE)0x0);
  }
  hModule = GetModuleHandleA("ucrtbase.dll");
  pFVar20 = GetProcAddress(hModule,"strlen");
  BVar18 = ReadFile(hFile,local_148,0xff,&local_3ac,(LPOVERLAPPED)0x0);
  if ((BVar18 != 0) && (local_3ac != 0)) {
    if ((ulonglong)local_3ac < 0x100) {
      local_148[local_3ac] = 0;
      sVar21 = strcspn((char *)local_148,"\r\n");
      if (sVar21 < 0x100) {
        local_148[sVar21] = 0;
        goto LAB_1400011de;
      }
    }
    FUN_140001878();
    pcVar5 = (code *)swi(3);
    uVar23 = (*pcVar5)();
    return uVar23;
  }
LAB_1400011de:
  CloseHandle(hFile);
  memset(local_222,0,0xda);
  local_248 = 0x8b397ad735875c96;
  uStack_240 = 0xc85856bb286d0475;
  local_228 = 0x262c82ee;
  local_238 = 0x37a956a4e1daee35;
  uStack_230 = 0xd340a27f9561581;
  DAT_140005678 = (ulonglong)pFVar20 ^ 0xdeadbeef;
  local_224 = 0xf8a5;
  sVar21 = strlen((char *)local_148);
  if (0 < (int)sVar21) {
    pDVar33 = local_3a8 + 1;
    iVar24 = 8;
    do {
      iVar19 = iVar24 + -8;
      iVar1 = iVar24 + -4;
      iVar2 = iVar24 + 4;
      uVar40 = iVar19 + _DAT_140003420 & _DAT_140003430;
      uVar43 = iVar19 + _UNK_140003424 & _UNK_140003434;
      uVar44 = iVar19 + _UNK_140003428 & _UNK_140003438;
      uVar45 = iVar19 + _UNK_14000342c & _UNK_14000343c;
      uVar47 = iVar1 + _DAT_140003420 & _DAT_140003430;
      uVar50 = iVar1 + _UNK_140003424 & _UNK_140003434;
      uVar51 = iVar1 + _UNK_140003428 & _UNK_140003438;
      uVar52 = iVar1 + _UNK_14000342c & _UNK_14000343c;
      sVar6 = (short)uVar40;
      cVar9 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar40 - (0xff < sVar6);
      sVar6 = (short)(uVar40 >> 0x10);
      sVar38 = CONCAT11((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar40 >> 0x10) - (0xff < sVar6),
                        cVar9);
      sVar6 = (short)uVar43;
      cVar10 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar43 - (0xff < sVar6);
      sVar6 = (short)(uVar43 >> 0x10);
      uVar41 = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar43 >> 0x10) - (0xff < sVar6),
                        CONCAT12(cVar10,sVar38));
      sVar6 = (short)uVar44;
      cVar11 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar44 - (0xff < sVar6);
      sVar6 = (short)(uVar44 >> 0x10);
      uVar42 = CONCAT15((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar44 >> 0x10) - (0xff < sVar6),
                        CONCAT14(cVar11,uVar41));
      sVar6 = (short)uVar45;
      cVar12 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar45 - (0xff < sVar6);
      sVar8 = (short)(uVar45 >> 0x10);
      sVar6 = (short)uVar47;
      cVar13 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar47 - (0xff < sVar6);
      sVar6 = (short)(uVar47 >> 0x10);
      sVar46 = CONCAT11((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar47 >> 0x10) - (0xff < sVar6),
                        cVar13);
      sVar6 = (short)uVar50;
      cVar14 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar50 - (0xff < sVar6);
      sVar6 = (short)(uVar50 >> 0x10);
      uVar48 = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar50 >> 0x10) - (0xff < sVar6),
                        CONCAT12(cVar14,sVar46));
      sVar6 = (short)uVar51;
      cVar15 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar51 - (0xff < sVar6);
      sVar6 = (short)(uVar51 >> 0x10);
      uVar49 = CONCAT15((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar51 >> 0x10) - (0xff < sVar6),
                        CONCAT14(cVar15,uVar48));
      sVar6 = (short)uVar52;
      cVar16 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar52 - (0xff < sVar6);
      sVar39 = (short)(uVar52 >> 0x10);
      sVar6 = (short)((uint)uVar41 >> 0x10);
      sVar7 = (short)((uint6)uVar42 >> 0x20);
      sVar8 = (short)(CONCAT17((0 < sVar8) * (sVar8 < 0x100) * (char)(uVar45 >> 0x10) -
                               (0xff < sVar8),CONCAT16(cVar12,uVar42)) >> 0x30);
      pDVar33[-1] = CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar12 - (0xff < sVar8),
                             CONCAT12((0 < sVar7) * (sVar7 < 0x100) * cVar11 - (0xff < sVar7),
                                      CONCAT11((0 < sVar6) * (sVar6 < 0x100) * cVar10 -
                                               (0xff < sVar6),
                                               (0 < sVar38) * (sVar38 < 0x100) * cVar9 -
                                               (0xff < sVar38))));
      sVar6 = (short)((uint)uVar48 >> 0x10);
      sVar7 = (short)((uint6)uVar49 >> 0x20);
      sVar8 = (short)(CONCAT17((0 < sVar39) * (sVar39 < 0x100) * (char)(uVar52 >> 0x10) -
                               (0xff < sVar39),CONCAT16(cVar16,uVar49)) >> 0x30);
      *pDVar33 = CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar16 - (0xff < sVar8),
                          CONCAT12((0 < sVar7) * (sVar7 < 0x100) * cVar15 - (0xff < sVar7),
                                   CONCAT11((0 < sVar6) * (sVar6 < 0x100) * cVar14 - (0xff < sVar6),
                                            (0 < sVar46) * (sVar46 < 0x100) * cVar13 -
                                            (0xff < sVar46))));
      uVar40 = iVar24 + _DAT_140003420 & _DAT_140003430;
      uVar43 = iVar24 + _UNK_140003424 & _UNK_140003434;
      uVar44 = iVar24 + _UNK_140003428 & _UNK_140003438;
      uVar45 = iVar24 + _UNK_14000342c & _UNK_14000343c;
      sVar6 = (short)uVar40;
      cVar12 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar40 - (0xff < sVar6);
      sVar6 = (short)(uVar40 >> 0x10);
      sVar39 = CONCAT11((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar40 >> 0x10) - (0xff < sVar6),
                        cVar12);
      sVar6 = (short)uVar43;
      cVar11 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar43 - (0xff < sVar6);
      sVar6 = (short)(uVar43 >> 0x10);
      uVar41 = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar43 >> 0x10) - (0xff < sVar6),
                        CONCAT12(cVar11,sVar39));
      sVar6 = (short)uVar44;
      cVar10 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar44 - (0xff < sVar6);
      sVar6 = (short)(uVar44 >> 0x10);
      uVar42 = CONCAT15((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar44 >> 0x10) - (0xff < sVar6),
                        CONCAT14(cVar10,uVar41));
      sVar6 = (short)uVar45;
      cVar9 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar45 - (0xff < sVar6);
      sVar8 = (short)(uVar45 >> 0x10);
      uVar40 = iVar2 + _DAT_140003420 & _DAT_140003430;
      uVar43 = iVar2 + _UNK_140003424 & _UNK_140003434;
      uVar44 = iVar2 + _UNK_140003428 & _UNK_140003438;
      uVar47 = iVar2 + _UNK_14000342c & _UNK_14000343c;
      sVar6 = (short)((uint)uVar41 >> 0x10);
      sVar7 = (short)((uint6)uVar42 >> 0x20);
      sVar8 = (short)(CONCAT17((0 < sVar8) * (sVar8 < 0x100) * (char)(uVar45 >> 0x10) -
                               (0xff < sVar8),CONCAT16(cVar9,uVar42)) >> 0x30);
      pDVar33[1] = CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar9 - (0xff < sVar8),
                            CONCAT12((0 < sVar7) * (sVar7 < 0x100) * cVar10 - (0xff < sVar7),
                                     CONCAT11((0 < sVar6) * (sVar6 < 0x100) * cVar11 -
                                              (0xff < sVar6),
                                              (0 < sVar39) * (sVar39 < 0x100) * cVar12 -
                                              (0xff < sVar39))));
      iVar1 = iVar24 + 8;
      sVar6 = (short)uVar40;
      cVar12 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar40 - (0xff < sVar6);
      sVar6 = (short)(uVar40 >> 0x10);
      sVar39 = CONCAT11((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar40 >> 0x10) - (0xff < sVar6),
                        cVar12);
      sVar6 = (short)uVar43;
      cVar11 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar43 - (0xff < sVar6);
      sVar6 = (short)(uVar43 >> 0x10);
      uVar41 = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar43 >> 0x10) - (0xff < sVar6),
                        CONCAT12(cVar11,sVar39));
      sVar6 = (short)uVar44;
      cVar10 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar44 - (0xff < sVar6);
      sVar6 = (short)(uVar44 >> 0x10);
      uVar42 = CONCAT15((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar44 >> 0x10) - (0xff < sVar6),
                        CONCAT14(cVar10,uVar41));
      sVar6 = (short)uVar47;
      cVar9 = (0 < sVar6) * (sVar6 < 0x100) * (char)uVar47 - (0xff < sVar6);
      sVar8 = (short)(uVar47 >> 0x10);
      sVar6 = (short)((uint)uVar41 >> 0x10);
      sVar7 = (short)((uint6)uVar42 >> 0x20);
      sVar8 = (short)(CONCAT17((0 < sVar8) * (sVar8 < 0x100) * (char)(uVar47 >> 0x10) -
                               (0xff < sVar8),CONCAT16(cVar9,uVar42)) >> 0x30);
      pDVar33[2] = CONCAT13((0 < sVar8) * (sVar8 < 0x100) * cVar9 - (0xff < sVar8),
                            CONCAT12((0 < sVar7) * (sVar7 < 0x100) * cVar10 - (0xff < sVar7),
                                     CONCAT11((0 < sVar6) * (sVar6 < 0x100) * cVar11 -
                                              (0xff < sVar6),
                                              (0 < sVar39) * (sVar39 < 0x100) * cVar12 -
                                              (0xff < sVar39))));
      pDVar33 = pDVar33 + 4;
      iVar24 = iVar24 + 0x10;
    } while (iVar1 < 0x100);
    pDVar33 = local_3a8;
    uVar31 = uVar25;
    uVar34 = uVar25;
    do {
      DVar17 = *pDVar33;
      uVar40 = (int)uVar31 + (uint)local_148[(int)uVar34 % (int)sVar21] + (uint)(byte)DVar17 &
               0x800000ff;
      if ((int)uVar40 < 0) {
        uVar40 = (uVar40 - 1 | 0xffffff00) + 1;
      }
      uVar31 = (ulonglong)uVar40;
      uVar43 = (int)uVar34 + 1;
      uVar34 = (ulonglong)uVar43;
      *(byte *)pDVar33 = *(byte *)((longlong)local_3a8 + (longlong)(int)uVar40);
      pDVar33 = (DWORD *)((longlong)pDVar33 + 1);
      *(byte *)((longlong)local_3a8 + (longlong)(int)uVar40) = (byte)DVar17;
    } while ((int)uVar43 < 0x100);
  }
  lpAddress = (undefined8 *)(DAT_140005678 ^ 0xdeadbeef);
  VirtualProtect(lpAddress,0x17,0x40,&local_3b0);
  uVar23 = *lpAddress;
  uVar32 = lpAddress[1];
  uVar41 = *(undefined4 *)(lpAddress + 2);
  uVar4 = *(undefined2 *)((longlong)lpAddress + 0x14);
  uVar3 = *(undefined1 *)((longlong)lpAddress + 0x16);
  *(undefined4 *)lpAddress = 0x1304c031;
  *(undefined4 *)((longlong)lpAddress + 4) = 0x17501b2;
  *(undefined4 *)(lpAddress + 1) = 0x301100e8;
  *(undefined4 *)((longlong)lpAddress + 0xc) = 0x48c2fe01;
  *(undefined4 *)(lpAddress + 2) = 0x2138c1ff;
  *(undefined2 *)((longlong)lpAddress + 0x14) = 0xf375;
  *(undefined1 *)((longlong)lpAddress + 0x16) = 0xc3;
  local_288[0] = '\0';
  local_288[1] = '\0';
  local_288[2] = '\0';
  local_288[3] = '\0';
  local_288[4] = '\0';
  local_288[5] = '\0';
  local_288[6] = '\0';
  local_288[7] = '\0';
  local_288[8] = '\0';
  local_288[9] = '\0';
  local_288[10] = '\0';
  local_288[0xb] = '\0';
  local_288[0xc] = '\0';
  local_288[0xd] = '\0';
  local_288[0xe] = '\0';
  local_288[0xf] = '\0';
  local_288[0x10] = '\0';
  local_288[0x11] = '\0';
  local_288[0x12] = '\0';
  local_288[0x13] = '\0';
  local_288[0x14] = '\0';
  local_288[0x15] = '\0';
  local_288[0x16] = '\0';
  local_288[0x17] = '\0';
  local_288[0x18] = '\0';
  local_288[0x19] = '\0';
  local_288[0x1a] = '\0';
  local_288[0x1b] = '\0';
  local_288[0x1c] = '\0';
  local_288[0x1d] = '\0';
  local_288[0x1e] = '\0';
  local_288[0x1f] = '\0';
  local_288[0x20] = '\0';
  local_288[0x21] = '\0';
  local_288[0x22] = '\0';
  local_288[0x23] = '\0';
  local_288[0x24] = '\0';
  local_288[0x25] = '\0';
  local_288[0x26] = '\0';
  local_288[0x27] = '\0';
  local_288[0x28] = '\0';
  local_288[0x29] = '\0';
  local_288[0x2a] = '\0';
  local_288[0x2b] = '\0';
  local_288[0x2c] = '\0';
  local_288[0x2d] = '\0';
  local_288[0x2e] = '\0';
  local_288[0x2f] = '\0';
  local_288[0x30] = '\0';
  local_288[0x31] = '\0';
  local_288[0x32] = '\0';
  local_288[0x33] = '\0';
  local_288[0x34] = '\0';
  local_288[0x35] = '\0';
  local_288[0x36] = '\0';
  local_288[0x37] = '\0';
  local_288[0x38] = '\0';
  local_288[0x39] = '\0';
  local_288[0x3a] = '\0';
  local_288[0x3b] = '\0';
  local_288[0x3c] = '\0';
  local_288[0x3d] = '\0';
  local_288[0x3e] = '\0';
  local_288[0x3f] = '\0';
  GetEnvironmentVariableA("COMPUTERNAME",local_288,0x40);
  lstrlenA(local_288);
  IsDebuggerPresent();
  GetTickCount();
  local_298[0] = s_Wingardium_Leviosa_140003380[0x10];
  local_298[1] = s_Wingardium_Leviosa_140003380[0x11];
  local_296 = s_Wingardium_Leviosa_140003380[0x12];
  local_2a8[0] = s_Wingardium_Leviosa_140003380[0];
  local_2a8[1] = s_Wingardium_Leviosa_140003380[1];
  local_2a8[2] = s_Wingardium_Leviosa_140003380[2];
  local_2a8[3] = s_Wingardium_Leviosa_140003380[3];
  local_2a8[4] = s_Wingardium_Leviosa_140003380[4];
  local_2a8[5] = s_Wingardium_Leviosa_140003380[5];
  local_2a8[6] = s_Wingardium_Leviosa_140003380[6];
  local_2a8[7] = s_Wingardium_Leviosa_140003380[7];
  acStack_2a0[0] = s_Wingardium_Leviosa_140003380[8];
  acStack_2a0[1] = s_Wingardium_Leviosa_140003380[9];
  acStack_2a0[2] = s_Wingardium_Leviosa_140003380[10];
  acStack_2a0[3] = s_Wingardium_Leviosa_140003380[0xb];
  acStack_2a0[4] = s_Wingardium_Leviosa_140003380[0xc];
  acStack_2a0[5] = s_Wingardium_Leviosa_140003380[0xd];
  acStack_2a0[6] = s_Wingardium_Leviosa_140003380[0xe];
  acStack_2a0[7] = s_Wingardium_Leviosa_140003380[0xf];
  strlen(&DAT_140005078);
  sVar21 = strlen(local_2a8);
  *lpAddress = uVar23;
  lpAddress[1] = uVar32;
  *(undefined4 *)(lpAddress + 2) = uVar41;
  lpflOldProtect = &local_3b0;
  *(undefined2 *)((longlong)lpAddress + 0x14) = uVar4;
  *(undefined1 *)((longlong)lpAddress + 0x16) = uVar3;
  uVar31 = (ulonglong)local_3b0;
  VirtualProtect(lpAddress,0x17,local_3b0,lpflOldProtect);
  if (0 < (int)(uint)sVar21) {
    uVar31 = 0xffffffffffffffff;
    do {
      uVar34 = uVar31 + 1;
      pcVar22 = s_xs_bv__u_TpcnolVjN_140005079 + uVar31;
      uVar31 = uVar34;
    } while (*pcVar22 != '\0');
    uVar40 = (uint)sVar21 & 0xff;
    pbVar35 = (byte *)((longlong)&local_248 + 1);
    lVar36 = 0x13;
    uVar29 = uVar25;
    uVar37 = uVar25;
    do {
      uVar43 = uVar40 + (int)uVar37 & 0x800000ff;
      if ((int)uVar43 < 0) {
        uVar43 = (uVar43 - 1 | 0xffffff00) + 1;
      }
      pbVar27 = (byte *)((longlong)local_3a8 + (longlong)(int)uVar43);
      bVar30 = *pbVar27;
      uVar44 = (int)uVar25 + (uint)bVar30 & 0x800000ff;
      if ((int)uVar44 < 0) {
        uVar44 = (uVar44 - 1 | 0xffffff00) + 1;
      }
      *pbVar27 = *(byte *)((longlong)local_3a8 + (longlong)(int)uVar44);
      *(byte *)((longlong)local_3a8 + (longlong)(int)uVar44) = bVar30;
      pbVar35[-1] = *(byte *)((longlong)local_3a8 + (ulonglong)(byte)(*pbVar27 + bVar30)) ^
                    (&DAT_140005078)[uVar29 % uVar34] ^ (char)sVar21 + pbVar35[-1];
      uVar43 = uVar43 + uVar40 & 0x800000ff;
      if ((int)uVar43 < 0) {
        uVar43 = (uVar43 - 1 | 0xffffff00) + 1;
      }
      uVar37 = (ulonglong)(int)uVar43;
      lpflOldProtect = local_3a8;
      bVar30 = *(byte *)((longlong)lpflOldProtect + uVar37);
      uVar43 = uVar44 + bVar30 & 0x800000ff;
      if ((int)uVar43 < 0) {
        uVar43 = (uVar43 - 1 | 0xffffff00) + 1;
      }
      uVar25 = (ulonglong)uVar43;
      *(byte *)((longlong)lpflOldProtect + uVar37) =
           *(byte *)((longlong)local_3a8 + (longlong)(int)uVar43);
      uVar31 = uVar29 + 1;
      *(byte *)((longlong)local_3a8 + (longlong)(int)uVar43) = bVar30;
      uVar29 = uVar29 + 2;
      bVar30 = *(byte *)((longlong)local_3a8 +
                        (ulonglong)
                        ((uint)*(byte *)((longlong)lpflOldProtect + uVar37) + (uint)bVar30 & 0xff))
               ^ (&DAT_140005078)[uVar31 % uVar34] ^ (char)sVar21 + *pbVar35;
      uVar31 = (ulonglong)bVar30;
      *pbVar35 = bVar30;
      pbVar35 = pbVar35 + 2;
      lVar36 = lVar36 + -1;
    } while (lVar36 != 0);
    local_222[0] = 0;
  }
  pcVar28 = "@flare-on.com";
  pcVar22 = strstr((char *)&local_248,"@flare-on.com");
  if (pcVar22 == (char *)0x0) {
    FUN_140001010("\n[FAILED] Try again with better debugging\n",pcVar28,uVar31,lpflOldProtect);
  }
  else {
    FUN_140001010("\n[SUCCESS] Decrypted Flag: %s\n",&local_248,uVar31,lpflOldProtect);
  }
  system("pause");
  return 0;
}


// ==== __security_check_cookie @ 140001750

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_140005000) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_1400017a4();
  return;
}


// ==== __raise_securityfailure @ 140001770

/* Library Function - Single Match
    __raise_securityfailure
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void __raise_securityfailure(_EXCEPTION_POINTERS *param_1)

{
  HANDLE pvVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter(param_1);
  pvVar1 = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x00014000179d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(pvVar1,0xc0000409);
  return;
}


// ==== FUN_1400017a4 @ 1400017a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1400017a4(void)

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
  *(undefined8 *)(puVar3 + -8) = 0x1400017cf;
  FUN_14000199c((PCONTEXT)&DAT_140005130);
  _DAT_1400050a0 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_1400051c8 = puVar3 + 0x40;
  _DAT_1400051b0 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_140005090 = 0xc0000409;
  _DAT_140005094 = 1;
  _DAT_1400050a8 = 1;
  DAT_1400050b0 = 2;
  *(undefined8 *)(puVar3 + 0x20) = DAT_140005000;
  *(undefined8 *)(puVar3 + 0x28) = DAT_140005040;
  *(undefined8 *)(puVar3 + -8) = 0x140001871;
  DAT_140005228 = _DAT_1400050a0;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1400032c0);
  return;
}


// ==== FUN_140001878 @ 140001878

void FUN_140001878(void)

{
  FUN_14000188c(8);
  return;
}


// ==== FUN_14000188c @ 14000188c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14000188c(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar3 = auStack_28;
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar3 = auStack_20;
  }
  *(undefined8 *)(puVar3 + -8) = 0x1400018b7;
  FUN_14000192c((PCONTEXT)&DAT_140005130);
  _DAT_1400050a0 = *(undefined8 *)(puVar3 + 0x28);
  _DAT_1400051c8 = puVar3 + 0x30;
  _DAT_140005090 = 0xc0000409;
  _DAT_140005094 = 1;
  _DAT_1400050a8 = 1;
  DAT_1400050b0 = (ulonglong)*(uint *)(puVar3 + 0x30);
  *(undefined8 *)(puVar3 + -8) = 0x140001923;
  DAT_140005228 = _DAT_1400050a0;
  __raise_securityfailure((_EXCEPTION_POINTERS *)&PTR_DAT_1400032c0);
  return;
}


// ==== FUN_14000192c @ 14000192c

void FUN_14000192c(PCONTEXT param_1)

{
  DWORD64 ControlPc;
  PRUNTIME_FUNCTION FunctionEntry;
  DWORD64 local_res8;
  ulonglong local_res10;
  PVOID local_res18;
  
  RtlCaptureContext();
  ControlPc = param_1->Rip;
  FunctionEntry = RtlLookupFunctionEntry(ControlPc,&local_res8,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    RtlVirtualUnwind(0,local_res8,ControlPc,FunctionEntry,param_1,&local_res18,&local_res10,
                     (PKNONVOLATILE_CONTEXT_POINTERS)0x0);
  }
  return;
}


// ==== FUN_14000199c @ 14000199c

void FUN_14000199c(PCONTEXT param_1)

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


// ==== FUN_140001a10 @ 140001a10

void FUN_140001a10(void)

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
  uVar5 = FUN_140001f80();
  _set_fmode((int)uVar5);
  uVar5 = FUN_140001f74();
  puVar6 = (undefined4 *)__p__commode();
  *puVar6 = (int)uVar5;
  uVar5 = __scrt_initialize_onexit_tables(1);
  if ((char)uVar5 != '\0') {
    FUN_140002208();
    atexit(FUN_140002244);
    uVar7 = FUN_140001f78();
    iVar4 = _configure_narrow_argv(uVar7 & 0xffffffff);
    if (iVar4 == 0) {
      FUN_140001f88();
      bVar2 = FUN_140001fc4();
      if ((int)CONCAT71(extraout_var,bVar2) != 0) {
        __setusermatherr(FUN_140001f74);
      }
      _guard_check_icall();
      _guard_check_icall();
      uVar5 = FUN_140001f74();
      _configthreadlocale((int)uVar5);
      cVar3 = FUN_140001f98();
      if (cVar3 != '\0') {
        _initialize_narrow_environment();
      }
      FUN_140001f74();
      uVar5 = thunk_FUN_140001f74();
      if ((int)uVar5 == 0) {
        return;
      }
    }
  }
  FUN_140001fec(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_140001ac8 @ 140001ac8

undefined8 FUN_140001ac8(void)

{
  FUN_140001fa8();
  return 0;
}


// ==== FUN_140001ad8 @ 140001ad8

void FUN_140001ad8(void)

{
  ulonglong uVar1;
  
  FUN_140002194();
  uVar1 = FUN_140001f74();
  _set_new_mode(uVar1 & 0xffffffff);
  return;
}


// ==== FUN_140001af4 @ 140001af4

ulonglong FUN_140001af4(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  uint *puVar9;
  ulonglong uVar10;
  undefined8 unaff_RBX;
  undefined8 in_R9;
  
  iVar3 = (int)unaff_RBX;
  uVar4 = FUN_140001cc0(1);
  if ((char)uVar4 == '\0') {
    FUN_140001fec(7);
  }
  else {
    bVar1 = false;
    uVar4 = __scrt_acquire_startup_lock();
    iVar3 = (int)CONCAT71((int7)((ulonglong)unaff_RBX >> 8),(char)uVar4);
    if (DAT_140005600 != 1) {
      if (DAT_140005600 == 0) {
        DAT_140005600 = 1;
        iVar3 = _initterm_e(&DAT_140003278,&DAT_140003290);
        if (iVar3 != 0) {
          return 0xff;
        }
        _initterm(&DAT_140003260,&DAT_140003270);
        DAT_140005600 = 2;
      }
      else {
        bVar1 = true;
      }
      __scrt_release_startup_lock((char)uVar4);
      plVar5 = (longlong *)FUN_140001fd0();
      if ((*plVar5 != 0) && (uVar6 = FUN_140001d88((longlong)plVar5), (char)uVar6 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_140003238)(0,2);
      }
      plVar5 = (longlong *)FUN_140001fd8();
      if ((*plVar5 != 0) && (uVar6 = FUN_140001d88((longlong)plVar5), (char)uVar6 != '\0')) {
        _register_thread_local_exe_atexit_callback(*plVar5);
      }
      uVar7 = _get_initial_narrow_environment();
      puVar8 = (undefined8 *)__p___argv();
      uVar4 = *puVar8;
      puVar9 = (uint *)__p___argc();
      uVar10 = (ulonglong)*puVar9;
      uVar6 = FUN_140001070(uVar10,uVar4,uVar7,in_R9);
      iVar3 = (int)uVar6;
      bVar2 = FUN_140002140();
      if (bVar2) {
        if (!bVar1) {
          _cexit();
        }
        __scrt_uninitialize_crt(CONCAT71((int7)(uVar10 >> 8),1),'\0');
        return uVar6 & 0xffffffff;
      }
      goto LAB_140001c60;
    }
  }
  FUN_140001fec(7);
LAB_140001c60:
                    /* WARNING: Subroutine does not return */
  exit(iVar3);
}


// ==== entry @ 140001c70

void entry(void)

{
  FUN_140001ec4();
  FUN_140001af4();
  return;
}


// ==== __scrt_acquire_startup_lock @ 140001c84

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
LAB_140001cb2:
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  else {
    do {
      uVar3 = 0;
      LOCK();
      bVar2 = DAT_140005608 == 0;
      uVar1 = *(ulonglong *)((longlong)Self + 8);
      if (!bVar2) {
        uVar3 = DAT_140005608;
        uVar1 = DAT_140005608;
      }
      DAT_140005608 = uVar1;
      UNLOCK();
      if (bVar2) goto LAB_140001cb2;
    } while (*(ulonglong *)((longlong)Self + 8) != uVar3);
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}


// ==== FUN_140001cc0 @ 140001cc0

longlong FUN_140001cc0(int param_1)

{
  char cVar1;
  uint7 extraout_var;
  uint7 uVar2;
  undefined7 extraout_var_00;
  uint7 extraout_var_01;
  
  if (param_1 == 0) {
    DAT_140005610 = 1;
  }
  FUN_140002280();
  cVar1 = FUN_140001f98();
  uVar2 = extraout_var;
  if (cVar1 != '\0') {
    cVar1 = FUN_140001f98();
    if (cVar1 != '\0') {
      return CONCAT71(extraout_var_00,1);
    }
    FUN_140001f98();
    uVar2 = extraout_var_01;
  }
  return (ulonglong)uVar2 << 8;
}


// ==== __scrt_initialize_onexit_tables @ 140001cfc

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
  
  if (DAT_140005611 == '\0') {
    if (1 < param_1) {
      FUN_140001fec(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    bVar2 = __scrt_is_ucrt_dll_in_use();
    if (((int)CONCAT71(extraout_var,bVar2) == 0) || (param_1 != 0)) {
      in_RAX = 0xffffffffffffffff;
      DAT_140005618 = _DAT_1400032d0;
      uRam0000000140005620 = _UNK_1400032d8;
      _DAT_140005628 = 0xffffffffffffffff;
      _DAT_140005630 = _DAT_1400032d0;
      uRam0000000140005638 = _UNK_1400032d8;
      _DAT_140005640 = 0xffffffffffffffff;
    }
    else {
      in_RAX = _initialize_onexit_table(&DAT_140005618);
      if (((int)in_RAX != 0) ||
         (in_RAX = _initialize_onexit_table(&DAT_140005630), (int)in_RAX != 0)) {
        return in_RAX & 0xffffffffffffff00;
      }
    }
    DAT_140005611 = '\x01';
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}


// ==== FUN_140001d88 @ 140001d88

ulonglong FUN_140001d88(longlong param_1)

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
           param_1 - 0x140000000U < uVar2)) goto LAB_140001dfe;
      }
      pwVar5 = (word *)0x0;
LAB_140001dfe:
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


// ==== __scrt_release_startup_lock @ 140001e20

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
    DAT_140005608 = 0;
    UNLOCK();
  }
  return;
}


// ==== __scrt_uninitialize_crt @ 140001e44

/* Library Function - Single Match
    __scrt_uninitialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 __scrt_uninitialize_crt(undefined8 param_1,char param_2)

{
  if ((DAT_140005610 == '\0') || (param_2 == '\0')) {
    FUN_140001f98();
    FUN_140001f98();
  }
  return 1;
}


// ==== _onexit @ 140001e70

/* Library Function - Single Match
    _onexit
   
   Library: Visual Studio 2019 Release */

_onexit_t __cdecl _onexit(_onexit_t _Func)

{
  int iVar1;
  _onexit_t p_Var2;
  
  if (DAT_140005618 == -1) {
    iVar1 = _crt_atexit();
  }
  else {
    iVar1 = _register_onexit_function(&DAT_140005618);
  }
  p_Var2 = (_onexit_t)0x0;
  if (iVar1 == 0) {
    p_Var2 = _Func;
  }
  return p_Var2;
}


// ==== atexit @ 140001eac

/* Library Function - Single Match
    atexit
   
   Library: Visual Studio 2019 Release */

int __cdecl atexit(_func_5014 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = _onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}


// ==== FUN_140001ec4 @ 140001ec4

void FUN_140001ec4(void)

{
  DWORD DVar1;
  _FILETIME local_res8;
  LARGE_INTEGER local_res10;
  _FILETIME local_18 [2];
  
  if (DAT_140005000 == 0x2b992ddfa232) {
    local_res8.dwLowDateTime = 0;
    local_res8.dwHighDateTime = 0;
    GetSystemTimeAsFileTime(&local_res8);
    local_18[0] = local_res8;
    DVar1 = GetCurrentThreadId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    DVar1 = GetCurrentProcessId();
    local_18[0] = (_FILETIME)((ulonglong)local_18[0] ^ (ulonglong)DVar1);
    QueryPerformanceCounter(&local_res10);
    DAT_140005000 =
         ((ulonglong)local_res10.s.LowPart << 0x20 ^
          CONCAT44(local_res10.s.HighPart,local_res10.s.LowPart) ^ (ulonglong)local_18[0] ^
         (ulonglong)local_18) & 0xffffffffffff;
    if (DAT_140005000 == 0x2b992ddfa232) {
      DAT_140005000 = 0x2b992ddfa233;
    }
  }
  DAT_140005040 = ~DAT_140005000;
  return;
}


// ==== FUN_140001f74 @ 140001f74

undefined8 FUN_140001f74(void)

{
  return 0;
}


// ==== FUN_140001f78 @ 140001f78

undefined8 FUN_140001f78(void)

{
  return 1;
}


// ==== FUN_140001f80 @ 140001f80

undefined8 FUN_140001f80(void)

{
  return 0x4000;
}


// ==== FUN_140001f88 @ 140001f88

void FUN_140001f88(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001f8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InitializeSListHead(&DAT_140005650);
  return;
}


// ==== FUN_140001f98 @ 140001f98

undefined1 FUN_140001f98(void)

{
  return 1;
}


// ==== _guard_check_icall @ 140001f9c

void _guard_check_icall(void)

{
  return;
}


// ==== FUN_140001fa0 @ 140001fa0

undefined * FUN_140001fa0(void)

{
  return &DAT_140005660;
}


// ==== FUN_140001fa8 @ 140001fa8

void FUN_140001fa8(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)FUN_140001000();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)FUN_140001fa0();
  *puVar1 = *puVar1 | 2;
  return;
}


// ==== FUN_140001fc4 @ 140001fc4

bool FUN_140001fc4(void)

{
  return DAT_14000504c == 0;
}


// ==== FUN_140001fd0 @ 140001fd0

undefined * FUN_140001fd0(void)

{
  return &DAT_140005690;
}


// ==== FUN_140001fd8 @ 140001fd8

undefined * FUN_140001fd8(void)

{
  return &DAT_140005688;
}


// ==== FUN_140001fe0 @ 140001fe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140001fe0(void)

{
  _DAT_140005668 = 0;
  return;
}


// ==== FUN_140001fec @ 140001fec

void FUN_140001fec(undefined4 param_1)

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
  *(undefined8 *)(puVar4 + -8) = 0x140002020;
  FUN_140001fe0();
  *(undefined8 *)(puVar4 + -8) = 0x140002031;
  memset(local_4d8,0,0x4d0);
  *(undefined8 *)(puVar4 + -8) = 0x14000203b;
  RtlCaptureContext(local_4d8);
  *(undefined8 *)(puVar4 + -8) = 0x140002055;
  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);
  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {
    *(undefined8 *)(puVar4 + 0x38) = 0;
    *(undefined1 **)(puVar4 + 0x30) = local_res18;
    *(undefined1 **)(puVar4 + 0x28) = local_res20;
    *(undefined1 **)(puVar4 + 0x20) = local_4d8;
    *(undefined8 *)(puVar4 + -8) = 0x140002099;
    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),
                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),
                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));
  }
  local_440 = &stack0x00000008;
  *(undefined8 *)(puVar4 + -8) = 0x1400020cb;
  memset(puVar4 + 0x50,0,0x98);
  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar4 + 0x54) = 1;
  *(undefined8 *)(puVar4 + -8) = 0x1400020ed;
  BVar2 = IsDebuggerPresent();
  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;
  *(undefined1 **)(puVar4 + 0x48) = local_4d8;
  *(undefined8 *)(puVar4 + -8) = 0x14000210a;
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  *(undefined8 *)(puVar4 + -8) = 0x140002115;
  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));
  if ((LVar3 == 0) && (BVar2 != 1)) {
    *(undefined8 *)(puVar4 + -8) = 0x140002126;
    FUN_140001fe0();
  }
  return;
}


// ==== FUN_140002140 @ 140002140

bool FUN_140002140(void)

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


// ==== FUN_140002194 @ 140002194

void FUN_140002194(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000219b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SetUnhandledExceptionFilter(FUN_1400021a4);
  return;
}


// ==== FUN_1400021a4 @ 1400021a4

undefined8 FUN_1400021a4(undefined8 *param_1)

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


// ==== FUN_140002208 @ 140002208

void FUN_140002208(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_1400038f8; plVar1 < &DAT_1400038f8; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_140003238)();
    }
  }
  return;
}


// ==== FUN_140002244 @ 140002244

void FUN_140002244(void)

{
  longlong *plVar1;
  
  for (plVar1 = &DAT_140003908; plVar1 < &DAT_140003908; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_140003238)();
    }
  }
  return;
}


// ==== FUN_140002280 @ 140002280

/* WARNING: Removing unreachable block (ram,0x000140002371) */
/* WARNING: Removing unreachable block (ram,0x000140002361) */
/* WARNING: Removing unreachable block (ram,0x00014000233c) */
/* WARNING: Removing unreachable block (ram,0x0001400022ba) */
/* WARNING: Removing unreachable block (ram,0x000140002298) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140002280(void)

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
    _DAT_140005060 = 0x8000;
    _DAT_140005068 = 0xffffffffffffffff;
    if ((((uVar8 == 0x106c0) || (uVar8 == 0x20660)) || (uVar8 == 0x20670)) ||
       ((uVar8 - 0x30650 < 0x21 &&
        ((0x100010001U >> ((ulonglong)(uVar8 - 0x30650) & 0x3f) & 1) != 0)))) {
      DAT_140005670 = DAT_140005670 | 1;
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
      DAT_140005670 = DAT_140005670 | 2;
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
  _DAT_140005058 = 1;
  DAT_14000505c = 2;
  uVar9 = DAT_140005050 & 0xfffffffffffffffe;
  if ((uVar5 >> 0x14 & 1) != 0) {
    _DAT_140005058 = 2;
    DAT_14000505c = 6;
    uVar9 = DAT_140005050 & 0xffffffffffffffee;
  }
  DAT_140005050 = uVar9;
  if ((uVar5 >> 0x1b & 1) != 0) {
    uVar9 = xinuse(0);
    uVar9 = in_XCR0 & uVar9 & 0xffffffff;
    if (((uVar5 >> 0x1c & 1) != 0) && (bVar6 = (byte)uVar9, (bVar6 & 6) == 6)) {
      _DAT_140005058 = 3;
      uVar7 = DAT_140005050;
      uVar5 = DAT_14000505c | 8;
      if ((uVar8 & 0x20) != 0) {
        _DAT_140005058 = 5;
        uVar7 = DAT_140005050 & 0xfffffffffffffffd;
        uVar5 = DAT_14000505c | 0x28;
        if (((uVar8 & 0xd0030000) == 0xd0030000) && ((bVar6 & 0xe0) == 0xe0)) {
          DAT_14000505c = DAT_14000505c | 0x68;
          _DAT_140005058 = 6;
          uVar7 = DAT_140005050 & 0xffffffffffffffd9;
          uVar5 = DAT_14000505c;
        }
      }
      DAT_14000505c = uVar5;
      DAT_140005050 = uVar7;
      if ((uVar10 >> 0x17 & 1) != 0) {
        DAT_140005050 = DAT_140005050 & 0xfffffffffeffffff;
      }
      if (((uVar11 >> 0x13 & 1) != 0) && ((bVar6 & 0xe0) == 0xe0)) {
        _DAT_14000566c = (uint)uVar12 & 0x400ff;
        DAT_140005050 = ~((ulonglong)((uint)(uVar12 >> 0x10) & 6) | 0x1000029) & DAT_140005050;
        if (1 < (byte)_DAT_14000566c) {
          DAT_140005050 = DAT_140005050 & 0xffffffffffffffbf;
        }
      }
    }
    if (((uVar11 >> 0x15 & 1) != 0) && ((uVar9 >> 0x13 & 1) != 0)) {
      DAT_140005050 = DAT_140005050 & 0xffffffffffffff7f;
    }
  }
  return 0;
}


// ==== __scrt_is_ucrt_dll_in_use @ 140002518

/* Library Function - Single Match
    __scrt_is_ucrt_dll_in_use
   
   Library: Visual Studio 2019 Release */

bool __scrt_is_ucrt_dll_in_use(void)

{
  return DAT_140005070 != 0;
}


// ==== FUN_1400025d4 @ 1400025d4

undefined8 FUN_1400025d4(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  FUN_1400025f4(param_2,param_4);
  return 1;
}


// ==== FUN_1400025f4 @ 1400025f4

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1400025f4(undefined8 param_1,longlong param_2)

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


// ==== _guard_dispatch_icall @ 140002670

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== FUN_140002696 @ 140002696

void FUN_140002696(undefined8 *param_1)

{
  _seh_filter_exe(*(undefined4 *)*param_1,param_1);
  return;
}


// ==== FUN_1400026b4 @ 1400026b4

bool FUN_1400026b4(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}


