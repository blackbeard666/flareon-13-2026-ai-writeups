// ==== FUN_140134f70 size=684

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140134f70(int param_1,longlong param_2,uint param_3,ulonglong *param_4)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  longlong lVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  undefined1 auStackY_208 [32];
  undefined1 local_1c8 [4];
  int local_1c4;
  longlong local_1c0;
  ulonglong *local_1b8;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined4 local_188;
  uint local_184;
  undefined4 local_180;
  undefined8 local_17c;
  undefined8 local_174;
  undefined8 local_16c;
  undefined8 local_164;
  undefined8 local_15c;
  undefined8 local_154;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined1 local_128 [8];
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined8 local_e4;
  undefined8 local_dc;
  undefined8 local_d4;
  undefined4 local_cc;
  undefined1 local_c8 [128];
  ulonglong local_48;
  
  local_48 = DAT_1404455c0 ^ (ulonglong)auStackY_208;
  iVar8 = *(int *)(param_2 + 0x4c);
  uVar7 = iVar8 - 1;
  local_1c4 = iVar8;
  local_1c0 = param_2;
  local_1b8 = param_4;
  if (DAT_140492b4c == 0) {
    GetVolumeInformationA
              ((LPCSTR)0x0,(LPSTR)0x0,0,&DAT_140492b48,(LPDWORD)0x0,(LPDWORD)0x0,(LPSTR)0x0,0);
    DAT_140492b4c = 1;
  }
  pcVar4 = DAT_140495cf8;
  bVar1 = false;
  if ((DAT_140495cf8 != (char *)0x0) &&
     (sVar3 = strlen(DAT_140495cf8), bVar1 = false, sVar3 == 0x40)) {
    puVar6 = local_128;
    lVar5 = 0;
    lVar9 = 0x20;
    do {
      FUN_1401077b0(pcVar4 + lVar5,&DAT_1401bd3e4,local_1c8);
      lVar5 = lVar5 + 2;
      *puVar6 = local_1c8[0];
      puVar6 = puVar6 + 1;
      lVar9 = lVar9 + -1;
      pcVar4 = DAT_140495cf8;
    } while (lVar9 != 0);
    bVar1 = true;
    iVar8 = local_1c4;
    param_2 = local_1c0;
  }
  do {
    uVar7 = uVar7 + 1;
    local_17c = 0;
    local_174 = 0;
    local_16c = 0;
    local_1a8 = CONCAT44(_UNK_1401bd254,_DAT_1401bd250);
    uStack_1a0 = CONCAT44(_UNK_1401bd25c,_UNK_1401bd258);
    local_164 = 0;
    local_198 = CONCAT44(_UNK_1401bd264,_DAT_1401bd260);
    uStack_190 = CONCAT44(_UNK_1401bd26c,_UNK_1401bd268);
    local_15c = 0;
    local_154 = 0;
    local_188 = DAT_140492b48;
    local_180 = 0x80000000;
    local_14c = 0x40;
    local_184 = uVar7;
    FUN_140135240(&local_1a8,&local_188,0);
    local_e4 = 0;
    local_108 = local_1a8;
    uStack_100 = uStack_1a0;
    local_dc = 0;
    local_f8 = local_198;
    uStack_f0 = uStack_190;
    local_d4 = 0;
    local_148 = _DAT_1401bd250;
    uStack_144 = _UNK_1401bd254;
    uStack_140 = _UNK_1401bd258;
    uStack_13c = _UNK_1401bd25c;
    local_e8 = 0x80000000;
    local_138 = _DAT_1401bd260;
    uStack_134 = _UNK_1401bd264;
    uStack_130 = _UNK_1401bd268;
    uStack_12c = _UNK_1401bd26c;
    local_cc = 0x100;
    FUN_140135240(&local_148,&local_108);
    if (bVar1) {
      local_1a8 = CONCAT44(uStack_144,local_148);
      uStack_1a0 = CONCAT44(uStack_13c,uStack_140);
      local_198 = CONCAT44(uStack_134,local_138);
      uStack_190 = CONCAT44(uStack_12c,uStack_130);
      iVar2 = memcmp(&local_1a8,local_128,0x20);
      if (iVar2 == 0) {
        FUN_140134ca0(DAT_140492b48,0xb501e7e,local_128);
        uStack_1b0 = uStack_120;
        uStack_1ac = uStack_11c;
        FUN_140134d70(&local_1b8,0x10,&DAT_1401bd3b0,0x33);
        FUN_140117b70(2,"Accepted: %s",local_c8);
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
    }
  } while ((uVar7 < param_3) && (*(char *)((longlong)param_1 * 0x80 + DAT_140491ac8) == '\0'));
  *local_1b8 = (ulonglong)((uVar7 - iVar8) + 1);
  *(uint *)(param_2 + 0x4c) = uVar7;
  return 0;
}


// ==== FUN_140107cf0 size=4

undefined8 FUN_140107cf0(void)

{
  return 0;
}


