
// ===== FUN_140009778 @ 140009778 off=0x9778 =====

void FUN_140009778(undefined4 param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  longlong lStack_138;
  ulonglong uStack_130;
  undefined2 uStack_128;
  undefined2 uStack_126;
  undefined2 uStack_124;
  undefined2 uStack_122;
  uint uStack_120;
  undefined8 uStack_118;
  undefined4 auStack_108 [66];
  
  lStack_138 = 0;
  uStack_118 = 0;
  FUN_140003234(&lStack_138,0);
  if (lStack_138 != 0) {
    uStack_130 = (ulonglong)param_3;
    if (0x80 < uStack_130) {
      uStack_130 = 0x80;
    }
    func_0x00014000ab3c(auStack_108,param_2,uStack_130);
    *(undefined4 *)((longlong)auStack_108 + uStack_130) = param_1;
    uStack_120 = (int)uStack_130 + 4;
    uStack_128 = 0x4d;
    uStack_126 = 0x44;
    uStack_124 = 0x35;
    uStack_122 = 0;
    *(undefined2 **)(lStack_138 + 0x299) = &uStack_128;
    *(undefined4 **)(lStack_138 + 0x2a1) = auStack_108;
    *(ulonglong *)(lStack_138 + 0x2a9) = (ulonglong)uStack_120;
    *(undefined8 *)(lStack_138 + 0x2b1) = param_4;
    *(undefined8 *)(lStack_138 + 0x2b9) = 0x10;
    *(undefined8 *)(lStack_138 + 0x1d1) = 0x4584b64f28ff5207;
    (**(code **)(lStack_138 + 0xa9))(0);
    *(undefined8 *)(lStack_138 + 0x1d1) = 0x528b8bb2eeaa7ee9;
    (**(code **)(lStack_138 + 0xa9))(0);
    *(undefined8 *)(lStack_138 + 0x1d1) = 0x5491069e9ccac0a9;
    (**(code **)(lStack_138 + 0xa9))(0);
    *(undefined8 *)(lStack_138 + 0x1d1) = 0x499dabab1eaa7eeb;
    (**(code **)(lStack_138 + 0xa9))(0);
    *(undefined8 *)(lStack_138 + 0x1d1) = 0x53ebd1c8661afaea;
    (**(code **)(lStack_138 + 0xa9))(0);
    *(undefined8 *)(lStack_138 + 0x1d1) = 0x14c3d3d387721f3;
    (**(code **)(lStack_138 + 0xa9))(0);
  }
  return;
}



// ===== FUN_140009630 @ 140009630 off=0x9630 =====

void FUN_140009630(longlong param_1,uint param_2,longlong param_3,uint param_4)

{
  byte bVar1;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  bVar1 = 0;
  for (uStack_24 = 0; uStack_24 < param_2; uStack_24 = uStack_24 + 1) {
    bVar1 = bVar1 * '\x1f' + *(char *)(param_1 + (ulonglong)uStack_24);
  }
  for (uStack_28 = 0; uStack_28 < param_4; uStack_28 = uStack_28 + 1) {
    bVar1 = bVar1 * 'm' + 0x39;
    *(byte *)(param_3 + (ulonglong)uStack_28) = *(byte *)(param_3 + (ulonglong)uStack_28) ^ bVar1;
  }
  return;
}



// ===== FUN_140009200 @ 140009200 off=0x9200 =====

longlong FUN_140009200(byte *param_1,uint param_2,uint param_3,uint *param_4)

{
  byte *pbVar1;
  longlong lVar2;
  byte *pbStack_48;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  byte *pbStack_28;
  byte *pbStack_20;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  
  pbStack_28 = param_1 + param_2;
  if (param_1 < pbStack_28) {
    uStack_18 = (uint)*param_1;
    if (uStack_18 == 0x30) {
      uStack_40 = 0;
      pbStack_48 = (byte *)func_0x000140009114(param_1 + 1,pbStack_28,&uStack_40);
      if ((pbStack_48 == (byte *)0x0) || (pbStack_28 < pbStack_48 + uStack_40)) {
        return 0;
      }
      pbStack_28 = pbStack_48 + uStack_40;
      while( true ) {
        if (pbStack_28 <= pbStack_48) {
          return 0;
        }
        uStack_14 = (uint)*pbStack_48;
        if (uStack_14 != 0x30) {
          return 0;
        }
        uStack_3c = 0;
        pbVar1 = (byte *)func_0x000140009114(pbStack_48 + 1,pbStack_28,&uStack_3c);
        if ((pbVar1 == (byte *)0x0) || (pbStack_28 < pbVar1 + uStack_3c)) {
          return 0;
        }
        pbStack_20 = pbVar1 + uStack_3c;
        uStack_10 = (uint)*pbVar1;
        if (uStack_10 != 2) {
          return 0;
        }
        uStack_38 = 0;
        pbStack_48 = (byte *)func_0x000140009114(pbVar1 + 1,pbStack_20,&uStack_38);
        if ((pbStack_48 == (byte *)0x0) || (pbStack_20 < pbStack_48 + uStack_38)) break;
        uStack_30 = 0;
        for (uStack_34 = 0; uStack_34 < uStack_38; uStack_34 = uStack_34 + 1) {
          uStack_30 = uStack_30 << 8 | (uint)*pbStack_48;
          pbStack_48 = pbStack_48 + 1;
        }
        uStack_c = (uint)*pbStack_48;
        if (uStack_c != 4) {
          return 0;
        }
        uStack_2c = 0;
        lVar2 = func_0x000140009114(pbStack_48 + 1,pbStack_20,&uStack_2c);
        if ((lVar2 == 0) || (pbStack_20 < (byte *)(lVar2 + (ulonglong)uStack_2c))) {
          return 0;
        }
        if (uStack_30 == param_3) {
          *param_4 = uStack_2c;
          return lVar2;
        }
        pbStack_48 = pbStack_20;
      }
      return 0;
    }
  }
  return 0;
}



// ===== FUN_14000a864 @ 14000a864 off=0xa864 =====

longlong FUN_14000a864(byte *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  longlong lVar2;
  uint uStack_38;
  uint uStack_34;
  byte *pbStack_30;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  byte *pbStack_20;
  byte *pbStack_18;
  byte *pbStack_10;
  
  uStack_28 = 0x2b;
  uStack_27 = 6;
  uStack_26 = 1;
  uStack_25 = 4;
  uStack_24 = 1;
  uStack_23 = 0x8a;
  uStack_22 = 0x39;
  uStack_21 = 1;
  pbStack_18 = param_1 + param_2;
  pbStack_10 = (byte *)0x0;
  pbStack_30 = param_1;
  pbStack_20 = param_1;
  do {
    if (pbStack_18 + -8 < pbStack_20) {
LAB_14000a915:
      if ((pbStack_10 != (byte *)0x0) && (pbStack_30 = pbStack_10 + 8, pbStack_30 < pbStack_18)) {
        if (*pbStack_30 == 1) {
          pbStack_30 = pbStack_10 + 0xb;
        }
        if (pbStack_30 < pbStack_18) {
          uStack_34 = (uint)*pbStack_30;
          pbStack_30 = pbStack_30 + 1;
          if (uStack_34 == 4) {
            uStack_38 = 0;
            lVar2 = func_0x000140009114(pbStack_30,pbStack_18,&uStack_38);
            if ((lVar2 != 0) && ((byte *)(lVar2 + (ulonglong)uStack_38) <= pbStack_18)) {
              *param_3 = uStack_38;
              return lVar2;
            }
            return 0;
          }
        }
      }
      return 0;
    }
    iVar1 = func_0x00014000aa44(pbStack_20,&uStack_28,8);
    if (iVar1 == 0) {
      pbStack_10 = pbStack_20;
      goto LAB_14000a915;
    }
    pbStack_20 = pbStack_20 + 1;
  } while( true );
}



// ===== FUN_1400094ac @ 1400094ac off=0x94ac =====

void FUN_1400094ac(longlong param_1,uint param_2,longlong param_3,uint *param_4,undefined8 param_5,
                  undefined4 param_6)

{
  uint uVar1;
  ulonglong uVar2;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_24;
  undefined8 uStack_20;
  undefined4 *puStack_18;
  undefined8 *puStack_10;
  
  uStack_20 = 0;
  uStack_24 = func_0x000140009070(param_5,param_6);
  puStack_18 = &uStack_24;
  puStack_10 = &uStack_20;
  uStack_34 = 0;
  for (uStack_38 = 0; uStack_38 < param_2; uStack_38 = uStack_38 + 1 + uVar1) {
    *(undefined1 *)(param_3 + (ulonglong)uStack_34) =
         *(undefined1 *)(param_1 + (ulonglong)uStack_38);
    uStack_34 = uStack_34 + 1;
    uVar2 = func_0x0001400095b8(&puStack_18);
    uVar1 = (int)((uVar2 & 0xffffffff) % 3) + 1;
    for (uStack_30 = 0; uStack_30 < uVar1; uStack_30 = uStack_30 + 1) {
      func_0x0001400095b8(&puStack_18);
    }
  }
  *param_4 = uStack_34;
  return;
}



// ===== FUN_14000ab68 @ 14000ab68 off=0xab68 =====

uint FUN_14000ab68(longlong param_1,uint param_2)

{
  uint uStackX_10;
  uint uStack_38;
  uint uStack_34;
  char acStack_18 [24];
  
  uStack_38 = 0;
  uStackX_10 = param_2;
  if (param_2 == 0) {
    acStack_18[0] = '0';
    uStack_38 = 1;
  }
  else {
    for (; uStackX_10 != 0; uStackX_10 = uStackX_10 / 10) {
      acStack_18[uStack_38] = (char)(uStackX_10 % 10) + '0';
      uStack_38 = uStack_38 + 1;
    }
  }
  for (uStack_34 = 0; uStack_34 < uStack_38; uStack_34 = uStack_34 + 1) {
    *(char *)(param_1 + (ulonglong)uStack_34) = acStack_18[(uStack_38 - 1) - uStack_34];
  }
  return uStack_38;
}



// ===== FUN_140005d54 @ 140005d54 off=0x5d54 =====

undefined8 FUN_140005d54(undefined8 param_1)

{
  uint uVar1;
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  uint uStack_104;
  undefined8 uStack_100;
  byte abStack_f8 [16];
  byte abStack_e8 [16];
  byte abStack_d8 [16];
  byte abStack_c8 [16];
  byte abStack_b8 [24];
  byte abStack_a0 [16];
  byte abStack_90 [16];
  code *pcStack_80;
  longlong lStack_78;
  longlong lStack_70;
  longlong lStack_68;
  longlong lStack_60;
  longlong lStack_58;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  longlong lStack_40;
  ulonglong uStack_38;
  ulonglong uStack_30;
  ulonglong uStack_28;
  ulonglong uStack_20;
  ulonglong uStack_18;
  ulonglong uStack_10;
  
  lStack_78 = FUN_140006950(0x275c8cb86bae9059,0);
  lStack_40 = FUN_140006950(0x275caa222989a626);
  uStack_100 = 0;
  if (lStack_78 != 0) {
    uStack_38 = 0;
    uVar1 = FUN_140006ab0(lStack_78,param_1,&uStack_100,0);
    if (uStack_38 == uVar1) {
      return uStack_100;
    }
  }
  if (lStack_40 != 0) {
    uStack_30 = 0;
    uVar1 = FUN_140006ab0(lStack_40,param_1,&uStack_100,0);
    if (uStack_30 == uVar1) {
      return uStack_100;
    }
  }
  pcStack_80 = (code *)0x0;
  if (lStack_78 != 0) {
    FUN_140006ab0(lStack_78,0x44992615283e40a1,&pcStack_80,0);
  }
  if (pcStack_80 != (code *)0x0) {
    abStack_b8[0] = 4;
    abStack_b8[1] = 0x92;
    abStack_b8[2] = 0xa1;
    abStack_b8[3] = 0x46;
    abStack_b8[4] = 0xad;
    abStack_b8[5] = 0x48;
    abStack_b8[6] = 0x92;
    abStack_b8[7] = 0xdc;
    abStack_f8[0] = 0x69;
    abStack_f8[1] = 0xe1;
    abStack_f8[2] = 0xd7;
    abStack_f8[3] = 0x25;
    abStack_f8[4] = 0xdf;
    abStack_f8[5] = 0x3c;
    abStack_f8[6] = 0xbc;
    abStack_f8[7] = 0xb8;
    abStack_f8[8] = 0x68;
    abStack_f8[9] = 0xfe;
    abStack_f8[10] = 0xa1;
    for (uStack_110 = 0; uStack_110 < 0xb; uStack_110 = uStack_110 + 1) {
      uStack_50 = (uint)abStack_f8[(int)uStack_110];
      abStack_f8[(int)uStack_110] =
           abStack_f8[(int)uStack_110] ^ abStack_b8[(ulonglong)(longlong)(int)uStack_110 % 8];
    }
    abStack_a0[0] = 0x53;
    abStack_a0[1] = 0x6e;
    abStack_a0[2] = 0x7f;
    abStack_a0[3] = 0x78;
    abStack_a0[4] = 0x47;
    abStack_a0[5] = 0x72;
    abStack_a0[6] = 0x4b;
    abStack_a0[7] = 0xf5;
    abStack_a0[8] = 0x86;
    abStack_a0[9] = 0xd1;
    abStack_a0[10] = 0xfc;
    abStack_c8[0] = 0x32;
    abStack_c8[1] = 10;
    abStack_c8[2] = 9;
    abStack_c8[3] = 0x19;
    abStack_c8[4] = 0x37;
    abStack_c8[5] = 0x1b;
    abStack_c8[6] = 0x78;
    abStack_c8[7] = 199;
    abStack_c8[8] = 0xa8;
    abStack_c8[9] = 0xb5;
    abStack_c8[10] = 0x90;
    abStack_c8[0xb] = 0x3f;
    abStack_c8[0xc] = 0x6e;
    for (uStack_10c = 0; uStack_10c < 0xd; uStack_10c = uStack_10c + 1) {
      uStack_4c = (uint)abStack_c8[(int)uStack_10c];
      abStack_c8[(int)uStack_10c] =
           abStack_c8[(int)uStack_10c] ^ abStack_a0[(ulonglong)(longlong)(int)uStack_10c % 0xb];
    }
    abStack_90[0] = 0xbf;
    abStack_90[1] = 0xb8;
    abStack_90[2] = 0x3f;
    abStack_90[3] = 0x34;
    abStack_90[4] = 0x9b;
    abStack_90[5] = 0xa8;
    abStack_90[6] = 0x27;
    abStack_90[7] = 0xdd;
    abStack_90[8] = 0xf3;
    abStack_90[9] = 0xe5;
    abStack_90[10] = 0x80;
    abStack_90[0xb] = 200;
    abStack_90[0xc] = 0x94;
    abStack_90[0xd] = 0xad;
    abStack_e8[0] = 200;
    abStack_e8[1] = 0xcb;
    abStack_e8[2] = 0xd;
    abStack_e8[3] = 0x6b;
    abStack_e8[4] = 0xa8;
    abStack_e8[5] = 0x9a;
    abStack_e8[6] = 9;
    abStack_e8[7] = 0xb9;
    abStack_e8[8] = 0x9f;
    abStack_e8[9] = 0x89;
    abStack_e8[10] = 0x80;
    for (uStack_108 = 0; uStack_108 < 0xb; uStack_108 = uStack_108 + 1) {
      uStack_48 = (uint)abStack_e8[(int)uStack_108];
      abStack_e8[(int)uStack_108] =
           abStack_e8[(int)uStack_108] ^ abStack_90[(ulonglong)(longlong)(int)uStack_108 % 0xe];
    }
    abStack_b8[8] = 0x69;
    abStack_b8[9] = 0x5f;
    abStack_b8[10] = 0xb4;
    abStack_b8[0xb] = 3;
    abStack_b8[0xc] = 0xa3;
    abStack_b8[0xd] = 0xeb;
    abStack_b8[0xe] = 0x48;
    abStack_b8[0xf] = 6;
    abStack_b8[0x10] = 0xab;
    abStack_d8[0] = 0xb;
    abStack_d8[1] = 0x3c;
    abStack_d8[2] = 0xc6;
    abStack_d8[3] = 0x7a;
    abStack_d8[4] = 0xd3;
    abStack_d8[5] = 0x9f;
    abStack_d8[6] = 0x66;
    abStack_d8[7] = 0x62;
    abStack_d8[8] = 199;
    abStack_d8[9] = 5;
    abStack_d8[10] = 0x5f;
    for (uStack_104 = 0; uStack_104 < 0xb; uStack_104 = uStack_104 + 1) {
      uStack_44 = (uint)abStack_d8[(int)uStack_104];
      abStack_d8[(int)uStack_104] =
           abStack_d8[(int)uStack_104] ^ abStack_b8[(ulonglong)(longlong)(int)uStack_104 % 9 + 8];
    }
    lStack_70 = FUN_140006950(0x29dcae22218a6fca,0);
    if (lStack_70 == 0) {
      lStack_70 = (*pcStack_80)(abStack_f8);
    }
    if (lStack_70 != 0) {
      uStack_28 = 0;
      uVar1 = FUN_140006ab0(lStack_70,param_1,&uStack_100,0);
      if (uStack_28 == uVar1) {
        return uStack_100;
      }
    }
    lStack_68 = FUN_140006950(0x20dca2a453a690d9,0);
    if (lStack_68 == 0) {
      lStack_68 = (*pcStack_80)(abStack_c8);
    }
    if (lStack_68 != 0) {
      uStack_20 = 0;
      uVar1 = FUN_140006ab0(lStack_68,param_1,&uStack_100,0);
      if (uStack_20 == uVar1) {
        return uStack_100;
      }
    }
    lStack_60 = FUN_140006950(0x29dc6623018690f9,0);
    if (lStack_60 == 0) {
      lStack_60 = (*pcStack_80)(abStack_e8);
    }
    if (lStack_60 != 0) {
      uStack_18 = 0;
      uVar1 = FUN_140006ab0(lStack_60,param_1,&uStack_100,0);
      if (uStack_18 == uVar1) {
        return uStack_100;
      }
    }
    lStack_58 = FUN_140006950(0x21dca622d18a2e6a,0);
    if (lStack_58 == 0) {
      lStack_58 = (*pcStack_80)(abStack_d8);
    }
    if (lStack_58 != 0) {
      uStack_10 = 0;
      uVar1 = FUN_140006ab0(lStack_58,param_1,&uStack_100,0);
      if (uStack_10 == uVar1) {
        return uStack_100;
      }
    }
  }
  return 0;
}



// ===== FUN_14000ab3c @ 14000ab3c off=0xab3c =====

undefined1 * FUN_14000ab3c(undefined1 *param_1,undefined1 *param_2,longlong param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
    puVar1 = puVar1 + 1;
  }
  return param_1;
}


