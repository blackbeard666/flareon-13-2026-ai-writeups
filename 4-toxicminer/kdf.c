// ==== FUN_140134ca0 size=207

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140134ca0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined8 local_24;
  undefined8 local_1c;
  undefined8 local_14;
  undefined4 local_c;
  
  local_48 = CONCAT44(param_2,param_1);
  uStack_3c = 0;
  uStack_38 = 0;
  local_68 = _DAT_1401bd250;
  uStack_64 = _UNK_1401bd254;
  uStack_60 = _UNK_1401bd258;
  uStack_5c = _UNK_1401bd25c;
  uStack_34 = 0;
  uStack_30 = 0;
  local_58 = _DAT_1401bd260;
  uStack_54 = _UNK_1401bd264;
  uStack_50 = _UNK_1401bd268;
  uStack_4c = _UNK_1401bd26c;
  uStack_2c = 0;
  uStack_28 = 0;
  local_24 = 0;
  local_1c = 0;
  local_14 = 0;
  uStack_40 = 0x80000000;
  local_c = 0x40;
  FUN_140135240(&local_68,&local_48,0);
  uVar3 = _UNK_1401bd25c;
  uVar2 = _UNK_1401bd258;
  uVar1 = _UNK_1401bd254;
  local_48 = CONCAT44(uStack_64,local_68);
  local_24 = 0;
  uStack_40 = uStack_60;
  uStack_3c = uStack_5c;
  local_1c = 0;
  uStack_38 = local_58;
  uStack_34 = uStack_54;
  uStack_30 = uStack_50;
  uStack_2c = uStack_4c;
  *param_3 = _DAT_1401bd250;
  param_3[1] = uVar1;
  param_3[2] = uVar2;
  param_3[3] = uVar3;
  uVar3 = _UNK_1401bd26c;
  uVar2 = _UNK_1401bd268;
  uVar1 = _UNK_1401bd264;
  local_14 = 0;
  uStack_28 = 0x80000000;
  local_c = 0x100;
  param_3[4] = _DAT_1401bd260;
  param_3[5] = uVar1;
  param_3[6] = uVar2;
  param_3[7] = uVar3;
  FUN_140135240(param_3,&local_48,0);
  return;
}


// ==== FUN_140134d70 size=500

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140134d70(longlong param_1,ulonglong param_2,longlong param_3,longlong param_4,
                  byte *param_5)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  char cVar7;
  char cVar11;
  int iVar15;
  ulonglong uVar16;
  int iVar17;
  byte *pbVar18;
  undefined4 *puVar19;
  longlong lVar20;
  byte *pbVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  short sVar24;
  short sVar25;
  uint uVar26;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  short sVar32;
  uint uVar33;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  byte local_148 [4];
  undefined4 local_144 [63];
  ulonglong local_48;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar12;
  char cVar13;
  char cVar14;
  undefined4 uVar27;
  undefined6 uVar28;
  undefined4 uVar34;
  undefined6 uVar35;
  
  pbVar21 = local_148;
  local_48 = DAT_1404455c0 ^ (ulonglong)local_148;
  lVar20 = 0x100;
  puVar19 = local_144;
  iVar17 = 8;
  do {
    iVar15 = iVar17 + -8;
    iVar1 = iVar17 + -4;
    iVar2 = iVar17 + 4;
    uVar26 = iVar15 + _DAT_14022cdb0 & (uint)PTR_DAT_14022cdc0;
    uVar29 = iVar15 + _UNK_14022cdb4 & PTR_DAT_14022cdc0._4_4_;
    uVar30 = iVar15 + _UNK_14022cdb8 & (uint)PTR_DAT_14022cdc8;
    uVar31 = iVar15 + _UNK_14022cdbc & PTR_DAT_14022cdc8._4_4_;
    uVar33 = iVar1 + _DAT_14022cdb0 & (uint)PTR_DAT_14022cdc0;
    uVar36 = iVar1 + _UNK_14022cdb4 & PTR_DAT_14022cdc0._4_4_;
    uVar37 = iVar1 + _UNK_14022cdb8 & (uint)PTR_DAT_14022cdc8;
    uVar38 = iVar1 + _UNK_14022cdbc & PTR_DAT_14022cdc8._4_4_;
    sVar4 = (short)uVar26;
    cVar7 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar26 - (0xff < sVar4);
    sVar4 = (short)(uVar26 >> 0x10);
    sVar24 = CONCAT11((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar26 >> 0x10) - (0xff < sVar4),cVar7)
    ;
    sVar4 = (short)uVar29;
    cVar8 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar29 - (0xff < sVar4);
    sVar4 = (short)(uVar29 >> 0x10);
    uVar27 = CONCAT13((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar29 >> 0x10) - (0xff < sVar4),
                      CONCAT12(cVar8,sVar24));
    sVar4 = (short)uVar30;
    cVar9 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar30 - (0xff < sVar4);
    sVar4 = (short)(uVar30 >> 0x10);
    uVar28 = CONCAT15((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar30 >> 0x10) - (0xff < sVar4),
                      CONCAT14(cVar9,uVar27));
    sVar4 = (short)uVar31;
    cVar10 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar31 - (0xff < sVar4);
    sVar6 = (short)(uVar31 >> 0x10);
    sVar4 = (short)uVar33;
    cVar11 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar33 - (0xff < sVar4);
    sVar4 = (short)(uVar33 >> 0x10);
    sVar32 = CONCAT11((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar33 >> 0x10) - (0xff < sVar4),cVar11
                     );
    sVar4 = (short)uVar36;
    cVar12 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar36 - (0xff < sVar4);
    sVar4 = (short)(uVar36 >> 0x10);
    uVar34 = CONCAT13((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar36 >> 0x10) - (0xff < sVar4),
                      CONCAT12(cVar12,sVar32));
    sVar4 = (short)uVar37;
    cVar13 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar37 - (0xff < sVar4);
    sVar4 = (short)(uVar37 >> 0x10);
    uVar35 = CONCAT15((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar37 >> 0x10) - (0xff < sVar4),
                      CONCAT14(cVar13,uVar34));
    sVar4 = (short)uVar38;
    cVar14 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar38 - (0xff < sVar4);
    sVar25 = (short)(uVar38 >> 0x10);
    sVar4 = (short)((uint)uVar27 >> 0x10);
    sVar5 = (short)((uint6)uVar28 >> 0x20);
    sVar6 = (short)(CONCAT17((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar31 >> 0x10) - (0xff < sVar6)
                             ,CONCAT16(cVar10,uVar28)) >> 0x30);
    puVar19[-1] = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * cVar10 - (0xff < sVar6),
                           CONCAT12((0 < sVar5) * (sVar5 < 0x100) * cVar9 - (0xff < sVar5),
                                    CONCAT11((0 < sVar4) * (sVar4 < 0x100) * cVar8 - (0xff < sVar4),
                                             (0 < sVar24) * (sVar24 < 0x100) * cVar7 -
                                             (0xff < sVar24))));
    sVar4 = (short)((uint)uVar34 >> 0x10);
    sVar5 = (short)((uint6)uVar35 >> 0x20);
    sVar6 = (short)(CONCAT17((0 < sVar25) * (sVar25 < 0x100) * (char)(uVar38 >> 0x10) -
                             (0xff < sVar25),CONCAT16(cVar14,uVar35)) >> 0x30);
    *puVar19 = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * cVar14 - (0xff < sVar6),
                        CONCAT12((0 < sVar5) * (sVar5 < 0x100) * cVar13 - (0xff < sVar5),
                                 CONCAT11((0 < sVar4) * (sVar4 < 0x100) * cVar12 - (0xff < sVar4),
                                          (0 < sVar32) * (sVar32 < 0x100) * cVar11 - (0xff < sVar32)
                                         )));
    uVar26 = iVar17 + _DAT_14022cdb0 & (uint)PTR_DAT_14022cdc0;
    uVar29 = iVar17 + _UNK_14022cdb4 & PTR_DAT_14022cdc0._4_4_;
    uVar30 = iVar17 + _UNK_14022cdb8 & (uint)PTR_DAT_14022cdc8;
    uVar31 = iVar17 + _UNK_14022cdbc & PTR_DAT_14022cdc8._4_4_;
    sVar4 = (short)uVar26;
    cVar7 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar26 - (0xff < sVar4);
    sVar4 = (short)(uVar26 >> 0x10);
    sVar25 = CONCAT11((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar26 >> 0x10) - (0xff < sVar4),cVar7)
    ;
    sVar4 = (short)uVar29;
    cVar8 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar29 - (0xff < sVar4);
    sVar4 = (short)(uVar29 >> 0x10);
    uVar27 = CONCAT13((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar29 >> 0x10) - (0xff < sVar4),
                      CONCAT12(cVar8,sVar25));
    sVar4 = (short)uVar30;
    cVar9 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar30 - (0xff < sVar4);
    sVar4 = (short)(uVar30 >> 0x10);
    uVar28 = CONCAT15((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar30 >> 0x10) - (0xff < sVar4),
                      CONCAT14(cVar9,uVar27));
    sVar4 = (short)uVar31;
    cVar10 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar31 - (0xff < sVar4);
    sVar6 = (short)(uVar31 >> 0x10);
    uVar26 = iVar2 + _DAT_14022cdb0 & (uint)PTR_DAT_14022cdc0;
    uVar29 = iVar2 + _UNK_14022cdb4 & PTR_DAT_14022cdc0._4_4_;
    uVar30 = iVar2 + _UNK_14022cdb8 & (uint)PTR_DAT_14022cdc8;
    uVar33 = iVar2 + _UNK_14022cdbc & PTR_DAT_14022cdc8._4_4_;
    sVar4 = (short)((uint)uVar27 >> 0x10);
    sVar5 = (short)((uint6)uVar28 >> 0x20);
    sVar6 = (short)(CONCAT17((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar31 >> 0x10) - (0xff < sVar6)
                             ,CONCAT16(cVar10,uVar28)) >> 0x30);
    puVar19[1] = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * cVar10 - (0xff < sVar6),
                          CONCAT12((0 < sVar5) * (sVar5 < 0x100) * cVar9 - (0xff < sVar5),
                                   CONCAT11((0 < sVar4) * (sVar4 < 0x100) * cVar8 - (0xff < sVar4),
                                            (0 < sVar25) * (sVar25 < 0x100) * cVar7 -
                                            (0xff < sVar25))));
    iVar1 = iVar17 + 8;
    sVar4 = (short)uVar26;
    cVar7 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar26 - (0xff < sVar4);
    sVar4 = (short)(uVar26 >> 0x10);
    sVar25 = CONCAT11((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar26 >> 0x10) - (0xff < sVar4),cVar7)
    ;
    sVar4 = (short)uVar29;
    cVar8 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar29 - (0xff < sVar4);
    sVar4 = (short)(uVar29 >> 0x10);
    uVar27 = CONCAT13((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar29 >> 0x10) - (0xff < sVar4),
                      CONCAT12(cVar8,sVar25));
    sVar4 = (short)uVar30;
    cVar9 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar30 - (0xff < sVar4);
    sVar4 = (short)(uVar30 >> 0x10);
    uVar28 = CONCAT15((0 < sVar4) * (sVar4 < 0x100) * (char)(uVar30 >> 0x10) - (0xff < sVar4),
                      CONCAT14(cVar9,uVar27));
    sVar4 = (short)uVar33;
    cVar10 = (0 < sVar4) * (sVar4 < 0x100) * (char)uVar33 - (0xff < sVar4);
    sVar6 = (short)(uVar33 >> 0x10);
    sVar4 = (short)((uint)uVar27 >> 0x10);
    sVar5 = (short)((uint6)uVar28 >> 0x20);
    sVar6 = (short)(CONCAT17((0 < sVar6) * (sVar6 < 0x100) * (char)(uVar33 >> 0x10) - (0xff < sVar6)
                             ,CONCAT16(cVar10,uVar28)) >> 0x30);
    puVar19[2] = CONCAT13((0 < sVar6) * (sVar6 < 0x100) * cVar10 - (0xff < sVar6),
                          CONCAT12((0 < sVar5) * (sVar5 < 0x100) * cVar9 - (0xff < sVar5),
                                   CONCAT11((0 < sVar4) * (sVar4 < 0x100) * cVar8 - (0xff < sVar4),
                                            (0 < sVar25) * (sVar25 < 0x100) * cVar7 -
                                            (0xff < sVar25))));
    puVar19 = puVar19 + 4;
    iVar17 = iVar17 + 0x10;
  } while (iVar1 < 0x100);
  uVar16 = 0;
  uVar22 = uVar16;
  uVar23 = uVar16;
  do {
    bVar3 = *pbVar21;
    uVar26 = (int)uVar22 + (uint)*(byte *)(uVar23 % param_2 + param_1) + (uint)bVar3 & 0x800000ff;
    if ((int)uVar26 < 0) {
      uVar26 = (uVar26 - 1 | 0xffffff00) + 1;
    }
    uVar22 = (ulonglong)uVar26;
    pbVar18 = (byte *)((longlong)local_144 + (longlong)(int)uVar26 + -4);
    uVar23 = uVar23 + 1;
    *pbVar21 = *pbVar18;
    pbVar21 = pbVar21 + 1;
    *pbVar18 = bVar3;
    lVar20 = lVar20 + -1;
  } while (lVar20 != 0);
  if (param_4 == 0) {
    *param_5 = 0;
  }
  else {
    lVar20 = param_4;
    pbVar21 = param_5;
    uVar22 = uVar16;
    do {
      uVar26 = (int)uVar22 + 1U & 0x800000ff;
      if ((int)uVar26 < 0) {
        uVar26 = (uVar26 - 1 | 0xffffff00) + 1;
      }
      uVar22 = (ulonglong)(int)uVar26;
      bVar3 = *(byte *)((longlong)local_144 + (uVar22 - 4));
      uVar26 = (int)uVar16 + (uint)bVar3 & 0x800000ff;
      if ((int)uVar26 < 0) {
        uVar26 = (uVar26 - 1 | 0xffffff00) + 1;
      }
      uVar16 = (ulonglong)uVar26;
      pbVar18 = (byte *)((longlong)local_144 + (longlong)(int)uVar26 + -4);
      *(byte *)((longlong)local_144 + (uVar22 - 4)) = *pbVar18;
      *pbVar18 = bVar3;
      *pbVar21 = *(byte *)((longlong)local_144 +
                          (((ulonglong)*(byte *)((longlong)local_144 + (uVar22 - 4)) +
                            (ulonglong)bVar3 & 0xff) - 4)) ^ pbVar21[param_3 - (longlong)param_5];
      pbVar21 = pbVar21 + 1;
      lVar20 = lVar20 + -1;
    } while (lVar20 != 0);
    param_5[param_4] = 0;
  }
  return;
}


// ==== FUN_1401077b0 size=81

void FUN_1401077b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  puVar1 = (undefined8 *)FUN_140106b60();
  __stdio_common_vsscanf(*puVar1,param_1,0xffffffffffffffff,param_2,0,&local_res18);
  return;
}


