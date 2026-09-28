
// ===== FUN_140002a84 @ 140002a84 off=0x2a84 =====

undefined4 FUN_140002a84(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 uStack_48;
  undefined4 *puStack_40;
  longlong lStack_38;
  longlong lStack_30;
  longlong lStack_28;
  code *pcStack_20;
  code *apcStack_18 [3];
  
  puStack_40 = (undefined4 *)0x0;
  lStack_30 = 0;
  lStack_28 = 0;
  pcStack_20 = (code *)0x0;
  apcStack_18[0] = (code *)0x0;
  lStack_38 = param_2;
  iVar1 = FUN_140003234(&puStack_40,param_2);
  if (iVar1 == 0) {
    if (param_1 != (undefined8 *)0x0) {
      *param_1 = puStack_40;
    }
    uStack_48 = 0;
  }
  else {
    lStack_30 = FUN_140006950(lStack_38 + 0x4daff0bce6bb0bb9U ^ 0x6af37c048d159be0,lStack_38);
    lStack_28 = FUN_140006950(lStack_38 + 0x5a7b785f0e5bdcf6U ^ 0x7d27d27d27d27ad0,lStack_38);
    if ((lStack_30 == 0) || (lStack_28 == 0)) {
      uStack_48 = 0x32;
    }
    else {
      uVar2 = FUN_140006ab0(lStack_30,lStack_38 + 0xfc43c3798d62e359U ^ 0xb3c4d5e6f80917a0,
                            &pcStack_20,lStack_38);
      if ((ulonglong)uVar2 == (lStack_38 + 0x70f0cc0d80bb0840U ^ 0x70f0cc0d80bb0840)) {
        uVar2 = FUN_140006ab0(lStack_28,lStack_38 + 0x97aa8536d05b4676U ^ 0xd82d82d82d82d580,
                              apcStack_18,lStack_38);
        if ((ulonglong)uVar2 == (lStack_38 + 0xf025e4441bb76700U ^ 0xf025e4441bb76700)) {
          uVar3 = (*pcStack_20)();
          puStack_40 = (undefined4 *)(*apcStack_18[0])(uVar3,8,0x4ff);
          if (puStack_40 == (undefined4 *)0x0) {
            uStack_48 = 8;
          }
          else {
            *puStack_40 = 0x52414c46;
            puStack_40[1] = 1;
            *(undefined1 *)(puStack_40 + 10) = 0;
            FUN_14000a9e8(puStack_40 + 2,0,0x20);
            FUN_14000a9e8((longlong)puStack_40 + 0x29,0,0x20);
            *(undefined4 *)((longlong)puStack_40 + 0x49) = 0;
            *(undefined4 *)((longlong)puStack_40 + 0xa5) = 0;
            *(undefined8 *)((longlong)puStack_40 + 0xa9) = 0x140006dfc;
            *(code **)((longlong)puStack_40 + 0xb1) = FUN_14000a9e8;
            *(undefined8 *)((longlong)puStack_40 + 0xb9) = 0x14000ab3c;
            *(code **)((longlong)puStack_40 + 0xc1) = FUN_14000aad4;
            *(undefined8 *)((longlong)puStack_40 + 0x1d9) = 0;
            *(ulonglong *)((longlong)puStack_40 + 0x1e1) =
                 lStack_38 + 0x1e508510bae5bae0U ^ 0x1e508510bae5bae0;
            *(ulonglong *)((longlong)puStack_40 + 0x1e9) =
                 lStack_38 + 0x5deb112c8863ea40U ^ 0x5deb112c0863ea40;
            *(ulonglong *)((longlong)puStack_40 + 0x1f1) =
                 lStack_38 + 0x9d859d4755e219a1U ^ 0x9d859d4755e219a0;
            *(ulonglong *)((longlong)puStack_40 + 0x1f9) =
                 lStack_38 + 0xdd202962a3604903U ^ 0xdd202962a3604900;
            *(ulonglong *)((longlong)puStack_40 + 0x201) =
                 lStack_38 + 0x1cbab57df0de7964U ^ 0x1cbab57df0de7860;
            *(ulonglong *)((longlong)puStack_40 + 0x209) =
                 lStack_38 + 0x5c5541993e5ca7c0U ^ 0x5c5541993e5ca7c0;
            *(ulonglong *)((longlong)puStack_40 + 0x211) =
                 lStack_38 + 0x9befcdb48bdad728U ^ 0x9befcdb48bdad720;
            *(ulonglong *)((longlong)puStack_40 + 0x219) =
                 lStack_38 + 0xdb8a59cfd9590482U ^ 0xdb8a59cfd9590680;
            *(ulonglong *)((longlong)puStack_40 + 0x221) =
                 lStack_38 + 0x1b24e5eb26d735e2U ^ 0x1b24e5eb26d735e0;
            *(ulonglong *)((longlong)puStack_40 + 0x229) =
                 lStack_38 + 0x5abf720674556541U ^ 0x5abf720674556540;
            *(ulonglong *)((longlong)puStack_40 + 0x231) =
                 lStack_38 + 0x9a59fe21c1d394a6U ^ 0x9a59fe21c1d394a0;
            *(ulonglong *)((longlong)puStack_40 + 0x239) =
                 lStack_38 + 0xd9f48a3d0f51c403U ^ 0xd9f48a3d0f51c400;
            *(ulonglong *)((longlong)puStack_40 + 0x241) =
                 lStack_38 + 0x198f16585ccff360U ^ 0x198f16585ccff360;
            *(ulonglong *)((longlong)puStack_40 + 0x249) =
                 lStack_38 + 0x5929a273324e22c1U ^ 0x5929a273aa4e22c0;
            *(ulonglong *)((longlong)puStack_40 + 0x251) =
                 lStack_38 + 0x98c42e8ef7cc5221U ^ 0x98c42e8ef7cc5220;
            *(ulonglong *)((longlong)puStack_40 + 0x259) =
                 lStack_38 + 0x27a14555c54a8182U ^ 0xd85ebaaa454a8180;
            *(ulonglong *)((longlong)puStack_40 + 0x261) =
                 lStack_38 + 0x17f946c592cab0f9U ^ 0x17f946c592c8b0e0;
            *(ulonglong *)((longlong)puStack_40 + 0x269) =
                 lStack_38 + 0x5793d2e0e046e000U ^ 0x5793d2e0e046e040;
            *(ulonglong *)((longlong)puStack_40 + 0x271) =
                 lStack_38 + 0x972e5efc2dc50c48U ^ 0x972e5efc2dc50fa0;
            *(ulonglong *)((longlong)puStack_40 + 0x279) =
                 lStack_38 + 0xd6c8eb177b433e00U ^ 0xd6c8eb177b433f00;
            *(ulonglong *)((longlong)puStack_40 + 0x281) =
                 lStack_38 + 0x16637732c8c16e70U ^ 0x16637732c8c16e60;
            *(undefined8 *)((longlong)puStack_40 + 0xc9) = 0;
            *(undefined8 *)((longlong)puStack_40 + 0xd1) = 0;
            *(undefined8 *)((longlong)puStack_40 + 0xd9) = 0;
            *(undefined8 *)((longlong)puStack_40 + 0xe1) = 0;
            if (param_1 != (undefined8 *)0x0) {
              *param_1 = puStack_40;
            }
            uStack_48 = 0;
          }
        }
        else {
          uStack_48 = 0x32;
        }
      }
      else {
        uStack_48 = 0x32;
      }
    }
  }
  return uStack_48;
}



// ===== FUN_140009a30 @ 140009a30 off=0x9a30 =====

undefined4 FUN_140009a30(longlong *param_1,int *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lStack_288;
  undefined4 uStack_280;
  int iStack_27c;
  longlong lStack_278;
  int *piStack_270;
  undefined8 uStack_268;
  int iStack_260;
  undefined8 uStack_258;
  longlong lStack_250;
  longlong lStack_248;
  longlong lStack_240;
  longlong lStack_238;
  undefined8 uStack_230;
  longlong lStack_228;
  undefined1 auStack_218 [528];
  
  uStack_280 = 0;
  lStack_288 = 0;
  uStack_230 = 0;
  FUN_140003234(&lStack_288,0);
  if (lStack_288 == 0) {
    uStack_280 = 0x490;
  }
  else {
    lStack_248 = 0;
    lStack_238 = 0;
    lStack_228 = 0;
    puVar2 = &uStack_268;
    for (lVar1 = 8; lVar1 != 0; lVar1 = lVar1 + -1) {
      *(undefined1 *)puVar2 = 0;
      puVar2 = (undefined8 *)((longlong)puVar2 + 1);
    }
    iStack_27c = 0;
    lStack_278 = -1;
    uStack_258 = 0;
    piStack_270 = (int *)0x0;
    lStack_250 = 0;
    lStack_240 = 0;
    iStack_260 = 0;
    *(undefined1 **)(lStack_288 + 0xe9) = auStack_218;
    *(undefined8 *)(lStack_288 + 0x1d1) = 0x6a58db63647e15f9;
    (**(code **)(lStack_288 + 0xa9))(0);
    if (*(longlong *)(lStack_288 + 0x9d) == 0) {
      *(undefined8 *)(lStack_288 + 0x1d1) = 0x4c834ea45a5d993c;
      (**(code **)(lStack_288 + 0xa9))(0);
      uStack_280 = *(undefined4 *)(lStack_288 + 0x9d);
    }
    else {
      *(undefined8 *)(lStack_288 + 0x1d1) = 0x4c8bb1238d6d1401;
      (**(code **)(lStack_288 + 0xa9))(0);
      lStack_248 = *(longlong *)(lStack_288 + 0x9d);
      lStack_228 = lStack_248 + *(int *)(lStack_248 + 0x3c);
      uStack_268 = *(ulonglong *)
                    (lStack_228 + 0x88 + (ulonglong)((int)uStack_230 + 0xecce164U ^ 0xecce160) * 8);
      lStack_240 = lStack_248;
      lStack_238 = lStack_248;
      if (((int)uStack_268 == 0) ||
         (uStack_268._4_4_ = (int)(uStack_268 >> 0x20), uStack_268._4_4_ == 0)) {
        uStack_280 = 0x490;
      }
      else {
        *(undefined1 **)(lStack_288 + 0xe9) = auStack_218;
        *(undefined8 *)(lStack_288 + 0x1d1) = 0x4583522c693333c0;
        (**(code **)(lStack_288 + 0xa9))(0);
        lStack_278 = *(longlong *)(lStack_288 + 0x9d);
        *(longlong *)(lStack_288 + 0x119) = lStack_278;
        if (lStack_278 == -1) {
          *(undefined8 *)(lStack_288 + 0x1d1) = 0x4c834ea45a5d993c;
          (**(code **)(lStack_288 + 0xa9))(0);
          uStack_280 = *(undefined4 *)(lStack_288 + 0x9d);
        }
        else {
          *(longlong *)(lStack_288 + 0x119) = lStack_278;
          *(ulonglong *)(lStack_288 + 0x109) = uStack_268 & 0xffffffff;
          *(undefined8 *)(lStack_288 + 0x1d1) = 0x4c8b427f362fb476;
          (**(code **)(lStack_288 + 0xa9))(0);
          iStack_260 = *(int *)(lStack_288 + 0x9d);
          if (iStack_260 == -1) {
            *(undefined8 *)(lStack_288 + 0x1d1) = 0x4c834ea45a5d993c;
            (**(code **)(lStack_288 + 0xa9))(0);
            uStack_280 = *(undefined4 *)(lStack_288 + 0x9d);
          }
          else {
            *(undefined8 *)(lStack_288 + 0x1d1) = 0x4f87169f756bf4f9;
            (**(code **)(lStack_288 + 0xa9))(0);
            uStack_258 = *(undefined8 *)(lStack_288 + 0x9d);
            *(undefined8 *)(lStack_288 + 0x131) = uStack_258;
            *(undefined8 *)(lStack_288 + 0x131) = uStack_258;
            *(ulonglong *)(lStack_288 + 0x111) = uStack_268 >> 0x20;
            *(undefined8 *)(lStack_288 + 0x1d1) = 0x4f8707eefdd993f6;
            (**(code **)(lStack_288 + 0xa9))(0);
            piStack_270 = *(int **)(lStack_288 + 0x9d);
            if (piStack_270 == (int *)0x0) {
              uStack_280 = 8;
            }
            else {
              *(undefined4 *)(lStack_288 + 0x2e9) = 0;
              *(longlong *)(lStack_288 + 0x119) = lStack_278;
              *(int **)(lStack_288 + 0x121) = piStack_270;
              *(ulonglong *)(lStack_288 + 0x111) = uStack_268 >> 0x20;
              *(undefined8 *)(lStack_288 + 0x1d1) = 0xa5160c48d26645;
              (**(code **)(lStack_288 + 0xa9))(0);
              if (*(longlong *)(lStack_288 + 0x9d) == 0) {
                *(undefined8 *)(lStack_288 + 0x1d1) = 0x4c834ea45a5d993c;
                (**(code **)(lStack_288 + 0xa9))(0);
                uStack_280 = *(undefined4 *)(lStack_288 + 0x9d);
              }
              else if (*(uint *)(lStack_288 + 0x2e9) < 8) {
                uStack_280 = 0xd;
              }
              else {
                iStack_27c = *piStack_270;
                *(undefined8 *)(lStack_288 + 0x131) = uStack_258;
                *(ulonglong *)(lStack_288 + 0x111) = (ulonglong)(iStack_27c - 8);
                *(undefined8 *)(lStack_288 + 0x1d1) = 0x4f8707eefdd993f6;
                (**(code **)(lStack_288 + 0xa9))(0);
                lStack_250 = *(longlong *)(lStack_288 + 0x9d);
                if (lStack_250 == 0) {
                  uStack_280 = 8;
                }
                else {
                  func_0x00014000ab3c(lStack_250,piStack_270 + 2,iStack_27c + -8);
                  *param_1 = lStack_250;
                  *param_2 = iStack_27c + -8;
                }
              }
            }
          }
        }
      }
    }
    if (lStack_278 != -1) {
      *(longlong *)(lStack_288 + 0x119) = lStack_278;
      *(undefined8 *)(lStack_288 + 0x1d1) = 0x4fa7164419d1372b;
      (**(code **)(lStack_288 + 0xa9))(0);
    }
    if (piStack_270 != (int *)0x0) {
      *(undefined8 *)(lStack_288 + 0x131) = uStack_258;
      *(int **)(lStack_288 + 0x121) = piStack_270;
      *(undefined8 *)(lStack_288 + 0x1d1) = 0x91160d08d4a2c5;
      (**(code **)(lStack_288 + 0xa9))(0);
    }
  }
  return uStack_280;
}



// ===== FUN_14000ad44 @ 14000ad44 off=0xad44 =====

uint FUN_14000ad44(undefined4 param_1,undefined4 param_2,undefined4 param_3,longlong param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = func_0x00014000ab68(param_4,param_1);
  *(undefined1 *)(param_4 + (ulonglong)uVar1) = 0x2d;
  iVar2 = func_0x00014000ab68(param_4 + (ulonglong)(uVar1 + 1),param_2);
  uVar1 = uVar1 + 1 + iVar2;
  *(undefined1 *)(param_4 + (ulonglong)uVar1) = 0x2d;
  uVar1 = uVar1 + 1;
  iVar2 = func_0x00014000ab68(param_4 + (ulonglong)uVar1,param_3);
  uVar1 = uVar1 + iVar2;
  *(undefined1 *)(param_4 + (ulonglong)uVar1) = 0;
  return uVar1;
}



// ===== FUN_14000a674 @ 14000a674 off=0xa674 =====

/* WARNING: Removing unreachable block (ram,0x00014000a77d) */

int FUN_14000a674(undefined4 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                 undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 undefined8 *param_9)

{
  int iVar1;
  longlong lStack_40;
  undefined4 auStack_38 [2];
  code *pcStack_30;
  undefined4 uStack_28;
  undefined8 uStack_20;
  code *pcStack_18;
  undefined8 uStack_10;
  
  lStack_40 = 0;
  uStack_20 = 0;
  FUN_140003234(&lStack_40,0);
  if (lStack_40 == 0) {
    iVar1 = 0x490;
  }
  else {
    pcStack_30 = (code *)0x0;
    auStack_38[0] = 0;
    iVar1 = func_0x00014000a21c(param_1,param_2,param_3,param_4,param_5,&pcStack_30,auStack_38);
    if (iVar1 == 0) {
      pcStack_18 = pcStack_30;
      uStack_10 = (*pcStack_30)(param_6,param_7,param_8);
      if (param_9 != (undefined8 *)0x0) {
        *param_9 = uStack_10;
      }
      FUN_14000a9e8(pcStack_30,0,auStack_38[0]);
      uStack_28 = 0;
      *(code **)(lStack_40 + 0x199) = pcStack_30;
      *(undefined8 *)(lStack_40 + 0x111) = 0;
      *(undefined8 *)(lStack_40 + 0x1c1) = 0x8000;
      *(undefined8 *)(lStack_40 + 0x1d1) = 0x52a9560cc8d4b869;
      (**(code **)(lStack_40 + 0xa9))(0);
    }
  }
  return iVar1;
}



// ===== FUN_14000a21c @ 14000a21c off=0xa21c =====

undefined8
FUN_14000a21c(undefined4 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
             undefined4 param_5,longlong *param_6,undefined4 *param_7)

{
  undefined8 uVar1;
  longlong lStack_68;
  uint auStack_60 [2];
  longlong lStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  longlong lStack_40;
  longlong lStack_38;
  longlong lStack_30;
  undefined8 uStack_28;
  undefined1 auStack_20 [32];
  
  lStack_68 = 0;
  uStack_28 = 0;
  FUN_140003234(&lStack_68,0);
  if (lStack_68 == 0) {
    uVar1 = 0x490;
  }
  else {
    uStack_48 = 0;
    auStack_60[0] = 0;
    uStack_50 = 0;
    lStack_38 = func_0x00014000a864(param_2,param_3,&uStack_50);
    if (lStack_38 == 0) {
      uVar1 = 0x490;
    }
    else {
      lStack_30 = func_0x000140009200(lStack_38,uStack_50,param_1,auStack_60);
      if (lStack_30 == 0) {
        uVar1 = 0x490;
      }
      else {
        *(undefined8 *)(lStack_68 + 0x1d1) = 0x4f87169f756bf4f9;
        (**(code **)(lStack_68 + 0xa9))(0);
        uStack_48 = *(undefined8 *)(lStack_68 + 0x9d);
        *(undefined8 *)(lStack_68 + 0x131) = uStack_48;
        lStack_58 = 0;
        *(undefined8 *)(lStack_68 + 0x131) = uStack_48;
        *(ulonglong *)(lStack_68 + 0x111) = (ulonglong)auStack_60[0];
        *(undefined8 *)(lStack_68 + 0x1d1) = 0x4f8707eefdd993f6;
        (**(code **)(lStack_68 + 0xa9))(0);
        lStack_58 = *(longlong *)(lStack_68 + 0x9d);
        if (lStack_58 == 0) {
          uVar1 = 8;
        }
        else {
          func_0x00014000ab3c(lStack_58,lStack_30,auStack_60[0]);
          func_0x000140009778(param_1,param_4,param_5,auStack_20);
          func_0x000140009630(auStack_20,0x10,lStack_58,auStack_60[0]);
          lStack_40 = 0;
          *(undefined8 *)(lStack_68 + 0x199) = 0;
          *(ulonglong *)(lStack_68 + 0x111) = (ulonglong)auStack_60[0];
          *(undefined8 *)(lStack_68 + 0x1c1) = 0x3000;
          *(undefined8 *)(lStack_68 + 0x1c9) = 0x40;
          *(undefined8 *)(lStack_68 + 0x1d1) = 0x54ab0664199dfa2c;
          (**(code **)(lStack_68 + 0xa9))(0);
          lStack_40 = *(longlong *)(lStack_68 + 0x9d);
          if (lStack_40 == 0) {
            FUN_14000a9e8(lStack_58,0,auStack_60[0]);
            *(undefined8 *)(lStack_68 + 0x131) = uStack_48;
            *(longlong *)(lStack_68 + 0x121) = lStack_58;
            *(undefined8 *)(lStack_68 + 0x1d1) = 0x91160d08d4a2c5;
            (**(code **)(lStack_68 + 0xa9))(0);
            uVar1 = 8;
          }
          else {
            uStack_4c = 0;
            func_0x0001400094ac(lStack_58,auStack_60[0],lStack_40,&uStack_4c,param_4,param_5);
            FUN_14000a9e8(lStack_58,0,auStack_60[0]);
            *(undefined8 *)(lStack_68 + 0x131) = uStack_48;
            *(longlong *)(lStack_68 + 0x121) = lStack_58;
            *(undefined8 *)(lStack_68 + 0x1d1) = 0x91160d08d4a2c5;
            (**(code **)(lStack_68 + 0xa9))(0);
            *param_6 = lStack_40;
            *param_7 = uStack_4c;
            uVar1 = 0;
          }
        }
      }
    }
  }
  return uVar1;
}



// ===== FUN_140006dfc @ 140006dfc off=0x6dfc =====

void FUN_140006dfc(ulonglong param_1)

{
  ulonglong uVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  longlong unaff_GS_OFFSET;
  longlong lStack_178;
  longlong lStack_170;
  ulonglong uStack_168;
  uint uStack_160;
  code *pcStack_158;
  byte bStack_150;
  ushort uStack_14c;
  uint uStack_148;
  ushort uStack_144;
  ushort uStack_140;
  uint uStack_13c;
  longlong lStack_138;
  ulonglong uStack_130;
  ulonglong uStack_128;
  ulonglong uStack_120;
  ulonglong uStack_118;
  longlong lStack_110;
  longlong lStack_108;
  longlong lStack_100;
  ulonglong uStack_f8;
  ulonglong uStack_f0;
  code *pcStack_e8;
  ulonglong uStack_e0;
  ulonglong uStack_d8;
  ulonglong uStack_d0;
  longlong lStack_c8;
  longlong lStack_c0;
  longlong lStack_b8;
  longlong *plStack_b0;
  longlong lStack_a8;
  ulonglong uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  longlong lStack_50;
  longlong lStack_48;
  undefined8 uStack_40;
  ulonglong auStack_38 [5];
  
  lStack_178 = 0;
  lStack_170 = 0;
  FUN_140003234(&lStack_178,0);
  if (lStack_178 != 0) {
    uStack_168 = lStack_170 + 0x2e8edb246cbfd6bfU ^ 0x2e8edb2417e5eaa0;
    uStack_128 = 0;
    pcStack_158 = (code *)0x0;
    while (uStack_168 != uStack_160) {
      iVar5 = (int)lStack_170;
      if (uStack_168 == (iVar5 + 0x93813affU ^ 0xe8db06e0)) {
        if (param_1 == 0) {
          uStack_128 = *(ulonglong *)(lStack_178 + 0x1d1);
        }
        else {
          lStack_c8 = *(longlong *)
                       (unaff_GS_OFFSET + (lStack_170 + 0xea32e0506c51f3a0U ^ 0xea32e0506c51f3c0));
          lStack_b8 = *(longlong *)(lStack_c8 + (ulonglong)(iVar5 + 0x74e5298U ^ 0x74e5280));
          plStack_b0 = (longlong *)(lStack_b8 + (ulonglong)(iVar5 + 0x54cc81c0U ^ 0x54cc81e0));
          lStack_108 = *(longlong *)((ulonglong)(iVar5 + 0xa24ab160U ^ 0xa24ab140) + *plStack_b0);
          lStack_110 = lStack_108 +
                       (ulonglong)
                       *(uint *)(lStack_108 + (ulonglong)(iVar5 + 0x8ac53f5cU ^ 0x8ac53f60));
          uStack_140 = *(ushort *)(lStack_110 + (ulonglong)(iVar5 + 0xd8436ec6U ^ 0xd8436ec0));
          uStack_144 = *(ushort *)(lStack_110 + (ulonglong)(iVar5 + 0x25c19e34U ^ 0x25c19e20));
          lStack_a8 = lStack_110 + (ulonglong)(iVar5 + 0x733fcd98U ^ 0x733fcd80) +
                      (ulonglong)uStack_144;
          lStack_100 = 0;
          uStack_13c = 0;
          for (uStack_14c = 0; cVar2 = (char)lStack_170, uStack_14c < uStack_140;
              uStack_14c = uStack_14c + 1) {
            lStack_138 = lStack_a8 +
                         (ulonglong)((uint)uStack_14c * (iVar5 + 0xf6b6ba48U ^ 0xf6b6ba60));
            if ((((*(byte *)(lStack_138 + (ulonglong)(iVar5 + 0x4434e9c0U ^ 0x4434e9c0)) ==
                   (byte)(cVar2 - 0x12U ^ 0xc0)) &&
                 (*(byte *)(lStack_138 + (ulonglong)(iVar5 + 0x91b31921U ^ 0x91b31920)) ==
                  (byte)(cVar2 + 0x54U ^ 0x20))) &&
                (*(byte *)(lStack_138 + (ulonglong)(iVar5 + 0xdf314882U ^ 0xdf314880)) ==
                 (byte)(cVar2 - 0x1bU ^ 0x80))) &&
               ((*(byte *)(lStack_138 + (ulonglong)(iVar5 + 0x2caf77e3U ^ 0x2caf77e0)) ==
                 (byte)(cVar2 + 0x98U ^ 0xe0) &&
                (*(byte *)(lStack_138 + (ulonglong)(iVar5 + 0x7a2da744U ^ 0x7a2da740)) ==
                 (byte)(cVar2 + 0x34U ^ 0x40))))) {
              lStack_100 = lStack_108 +
                           (ulonglong)
                           *(uint *)(lStack_138 + (ulonglong)(iVar5 + 0xc7abd6acU ^ 0xc7abd6a0));
              uStack_13c = *(uint *)(lStack_138 + (ulonglong)(iVar5 + 0x152a0610U ^ 0x152a0600));
              break;
            }
          }
          lStack_c0 = lStack_c8;
          if ((lStack_100 == 0) || (uStack_13c == 0)) {
            FUN_14000a9e8(auStack_38,iVar5 + 0xb8047a0U ^ 0xb8047a0,
                          lStack_170 + 0x185d811d0b804780U ^ 0x185d811d0b8047a0);
          }
          else {
            uStack_120 = lStack_170 + 0x1eb4bf68339d44a5U ^ 0x1eb4bf68339d51a0;
            uStack_130 = lStack_170 + 0x5e4f4b83811b8100U ^ 0x5e4f4b83811b8100;
            uStack_f8 = lStack_170 + 0x561b4b7a4abb9345U ^ 0x9de9d79ece99b060;
            uStack_118 = lStack_170 + 0xdd8463ba1c17dfc7U ^ 0xdd8463ba1c17dfc0;
            for (uStack_148 = 0; uStack_148 < uStack_13c; uStack_148 = uStack_148 + 1) {
              bStack_150 = *(byte *)(lStack_100 + (ulonglong)uStack_148);
              uStack_120 = (uStack_120 << ((cVar2 - 0x1bU ^ 0xe0) & 0x3f)) + uStack_120 +
                           (ulonglong)bStack_150;
              uStack_130 = ((ulonglong)bStack_150 + (uStack_130 << (cVar2 + 0x46U & 0x3f)) +
                           (uStack_130 << (cVar2 + 0x50U & 0x3f))) - uStack_130;
              uStack_f8 = (uStack_f8 ^ bStack_150) *
                          (lStack_170 + 0x1b8921429f8ecd13U ^ 0x1b8920429f8ecca0);
              uStack_118 = (uStack_118 << (cVar2 + 9U & 0x3f) | uStack_118 >> (cVar2 + 0x37U & 0x3f)
                           ) + (ulonglong)bStack_150;
            }
            *(ulonglong *)((longlong)auStack_38 + (ulonglong)(iVar5 + 0x88095ac0U ^ 0x88095ac0)) =
                 uStack_120;
            *(ulonglong *)((longlong)auStack_38 + (ulonglong)(iVar5 + 0xd5878a28U ^ 0xd5878a20)) =
                 uStack_130;
            *(ulonglong *)((longlong)auStack_38 + (ulonglong)(iVar5 + 0x2305b990U ^ 0x2305b980)) =
                 uStack_f8;
            *(ulonglong *)((longlong)auStack_38 + (ulonglong)(iVar5 + 0x7083e8f8U ^ 0x7083e8e0)) =
                 uStack_118;
          }
          uStack_e0 = *(ulonglong *)(param_1 + 8);
          func_0x000140009630(auStack_38,(int)lStack_170 + 0xdc7563c0U ^ 0xdc7563e0,&uStack_e0,
                              (int)lStack_170 + 0xdc7563e8U ^ 0xdc7563e0);
          uStack_128 = uStack_e0 ^ *(uint *)(param_1 + 0x10);
          *(ulonglong *)(lStack_178 + 0x1d1) = uStack_128;
        }
        uStack_168 = (ulonglong)
                     ((int)uStack_168 * ((int)lStack_170 + 0xecacce4dU ^ 0xad6a8020) +
                     ((int)lStack_170 + 0xad6ab019U ^ 0xad6a8020));
      }
      else if (uStack_168 == (iVar5 + 0x2ad1e58cU ^ 0x4866dee0)) {
        uVar1 = rdtsc();
        uStack_a0 = (uVar1 ^ param_1) % (lStack_170 + 0x120642d1e3633da3U ^ 0x120642d1e3633da0);
        for (uStack_f0 = 0; uStack_f0 < uStack_a0; uStack_f0 = uStack_f0 + 1) {
          uVar1 = rdtsc();
          if (((CONCAT44((int)(uStack_a0 >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) &
              (lStack_170 + 0x913b5b087e5f9c61U ^ 0x913b5b087e5f9c60)) == 0) {
            uStack_d8 = lStack_170 + 0x22de029f7045735cU ^ 0x6e5d4c3b2a18ea60;
          }
          else {
            uStack_d8 = lStack_170 + 0xc306accc52fa7908U ^ 0x8091a2b3c4d5c950;
          }
          uStack_d0 = uStack_d8;
          pcStack_e8 = (code *)func_0x000140005d54(uStack_d8);
          if (pcStack_e8 != (code *)0x0) {
            if (uStack_d0 == (lStack_170 + 0xfbade8b9cf51ff1cU ^ 0xb72ea61d950c6620)) {
              (*pcStack_e8)();
            }
            else {
              (*pcStack_e8)();
            }
          }
        }
        uStack_168 = (ulonglong)
                     ((int)uStack_168 * ((int)lStack_170 + 0x618f9a8dU ^ 0x2049d4e0) +
                     ((int)lStack_170 + 0x2049e4d9U ^ 0x2049d4e0));
      }
      else if (uStack_168 == (iVar5 + 0x86e15695U ^ 0xbb4633a0)) {
        pcStack_158 = (code *)func_0x000140005d54(uStack_128);
        if (pcStack_158 == (code *)0x0) {
          uStack_168 = (ulonglong)uStack_160;
        }
        else {
          uStack_168 = uStack_128;
        }
      }
      else if (uStack_168 == (lStack_170 + 0x86f0bf7cbfe921e9U ^ 0xeca8641fdb973410)) {
        uStack_98 = 0xf0;
        uVar4 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined8 *)(lStack_178 + 0xe9),
                               *(undefined4 *)(lStack_178 + 0x201));
        *(ulonglong *)(lStack_178 + 0x9d) = (ulonglong)uVar4;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x32c0a6c73c133f91U ^ 0x7e4b17e4b17e2b90)) {
        uVar6 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x1d9));
        *(undefined8 *)(lStack_178 + 0x9d) = uVar6;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xae064c9438d856f0U ^ 0xeb851eb851eb6530)) {
        uStack_90 = 0x108;
        uVar6 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0xe9),
                               *(undefined4 *)(lStack_178 + 0x1e9),
                               *(undefined4 *)(lStack_178 + 0x1f1),
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined4 *)(lStack_178 + 0x1f9),
                               *(undefined4 *)(lStack_178 + 0x1e1),
                               *(undefined8 *)(lStack_178 + 0x1d9));
        *(undefined8 *)(lStack_178 + 0x9d) = uVar6;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x89726e20a4ea6c06U ^ 0xc5f92c5f92c5d870)) {
        uVar4 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x119),
                               *(undefined4 *)(lStack_178 + 0x109),
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined4 *)(lStack_178 + 0x209));
        *(ulonglong *)(lStack_178 + 0x9d) = (ulonglong)uVar4;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x2657200276025a19U ^ 0x69d0369d0369aee0)) {
        uVar6 = (*pcStack_158)();
        *(undefined8 *)(lStack_178 + 0x9d) = uVar6;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xfd2697919384b956U ^ 0xb2a1907f6e5d2aa0)) {
        uStack_88 = 0x48;
        uVar6 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x131),
                               *(undefined4 *)(lStack_178 + 0x211),
                               *(undefined8 *)(lStack_178 + 0x111));
        *(undefined8 *)(lStack_178 + 0x9d) = uVar6;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x44e152480c964465U ^ 0x4444444444442220)) {
        uStack_80 = 0x30;
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x119),
                               *(undefined8 *)(lStack_178 + 0x121),
                               *(undefined4 *)(lStack_178 + 0x111),lStack_178 + 0x2e9,
                               *(undefined8 *)(lStack_178 + 0x1d9));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xb5e8b2be5675e0abU ^ 0xfa4fa4fa4fa4d780)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x119));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x2b0ae569aa4f881cU ^ 0x6789abcdf0121120)) {
        uVar4 = (*pcStack_158)();
        *(ulonglong *)(lStack_178 + 0x9d) = (ulonglong)uVar4;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xb0ca13bd53d12e25U ^ 0xb05b05b05b058ce0)) {
        uStack_78 = 0x48;
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x131),
                               *(undefined4 *)(lStack_178 + 0x1e1),
                               *(undefined8 *)(lStack_178 + 0x121));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x127ef7d12ab9ae9bU ^ 0x41fdb97530ec8460)) {
        iVar5 = (*pcStack_158)(*(undefined2 *)(lStack_178 + 0x219),lStack_178 + 0x313);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x8def46c39a7b05ccU ^ 0xc16c16c16c169cf0)) {
        iVar5 = (*pcStack_158)();
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xa3d723f2f78fa64U ^ 0xa3d70a3d70a18b0)) {
        uStack_70 = 0x138;
        uVar6 = (*pcStack_158)(*(undefined4 *)(lStack_178 + 0x221),
                               *(undefined4 *)(lStack_178 + 0x1c1),
                               *(undefined4 *)(lStack_178 + 0x1c9));
        *(undefined8 *)(lStack_178 + 0x9d) = uVar6;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xd27d32cd54c03262U ^ 0x9be02468acf11030)) {
        uVar4 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x141));
        *(ulonglong *)(lStack_178 + 0x9d) = (ulonglong)uVar4;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x91a2b38c7cdae83U ^ 0x91a2b3c4d5e49d0)) {
        uVar3 = (*pcStack_158)(*(undefined2 *)(lStack_178 + 0x149));
        *(ulonglong *)(lStack_178 + 0x9d) = (ulonglong)uVar3;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x76553c73041ae2a4U ^ 0x7654320fedcb8370)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x139),lStack_178 + 0x4eb,0x10);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x4851f3483bc0894aU ^ 0x7f6e5d4c3b27af0)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x139));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x26b3e2cc3c2c1e6bU ^ 0x7530eca8641fb490)) {
        iVar5 = (*pcStack_158)();
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xebabe321437e6679U ^ 0xbe02468acf133050)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x1a9),lStack_178 + 0x2ed);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x68d7b543e2011ccbU ^ 0x3d70a3d70a3d48e0)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x1b1),lStack_178 + 0x2f1);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xec543b7f253d7f58U ^ 0xbcdf012345676170)) {
        uStack_68 = 0x170;
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x259),
                               *(undefined8 *)(lStack_178 + 0x1b9),
                               *(undefined4 *)(lStack_178 + 0x1e1),
                               *(undefined4 *)(lStack_178 + 0x261),lStack_178 + 0x2f9);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x2b47caa2c5040b7aU ^ 0x72ea61d950c816d0)) {
        uStack_60 = 0xd0;
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x2f9),
                               *(undefined8 *)(lStack_178 + 0x1b9),
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined8 *)(lStack_178 + 0x121),lStack_178 + 0x2f5);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x7cad2b7ace575c5bU ^ 0x3b2a1907f6e5ab20)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x2f9));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xebf311a4017d5498U ^ 0xa8641fdb9752e4c0)) {
        uVar6 = (*pcStack_158)();
        *(undefined8 *)(lStack_178 + 0x9d) = uVar6;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xf13579be08170156U ^ 0xf13579be02466080)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x139),
                               *(undefined8 *)(lStack_178 + 0x179),
                               *(undefined4 *)(lStack_178 + 0x171),
                               *(undefined4 *)(lStack_178 + 0x1e1));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x950c83fb789b51b4U ^ 0x950c83fb72ea36f0)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x139),
                               *(undefined8 *)(lStack_178 + 0x179),
                               *(undefined4 *)(lStack_178 + 0x171),
                               *(undefined4 *)(lStack_178 + 0x1e1));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x6c48885cfa13f74cU ^ 0x38e38e38e38e0d60)) {
        uVar6 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x199),
                               *(undefined8 *)(lStack_178 + 0x111),
                               *(undefined4 *)(lStack_178 + 0x1c1),
                               *(undefined4 *)(lStack_178 + 0x1c9));
        *(undefined8 *)(lStack_178 + 0x9d) = uVar6;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x8e13ce7a9ce55bb9U ^ 0xdcba98765431e3d0)) {
        uStack_58 = 0xb0;
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x199),
                               *(undefined8 *)(lStack_178 + 0x111),
                               *(undefined4 *)(lStack_178 + 0x1c1));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x2fc40eac85336daeU ^ 0x6e5d4c3b2a18db50)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x199),
                               *(undefined8 *)(lStack_178 + 0x111),
                               *(undefined4 *)(lStack_178 + 0x269),lStack_178 + 0x30d);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x46a568e5d36cc967U ^ 0x123456789abcb1c0)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x159),
                               *(undefined4 *)(lStack_178 + 0x279));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xc521a1e1fcd57f61U ^ 0x91a2b3c4d5e6ca50)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x159),
                               *(undefined8 *)(lStack_178 + 0x1d9),lStack_178 + 0x4ab,
                               lStack_178 + 0x301);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x70faac276fb6d731U ^ 0x3579be02468aa0c0)) {
        (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x301));
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xa2b3c4d5eea5bd24U ^ 0xa2b3c4d5e6f7da60)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x139),lStack_178 + 0x4db,0x10);
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x7dcb6e3f450bf630U ^ 0x3456789abcded1e0)) {
        uVar6 = (*pcStack_158)(*(undefined4 *)(lStack_178 + 0x221),lStack_178 + 0x4df,
                               *(undefined8 *)(lStack_178 + 0x169),
                               *(undefined8 *)(lStack_178 + 0x281));
        *(undefined8 *)(lStack_178 + 0x9d) = uVar6;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xd882ccd4b472421cU ^ 0xd82d82d82d82a850)) {
        lStack_50 = lStack_178 + 0x4fb;
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x139),
                               *(undefined4 *)(lStack_178 + 0x249),lStack_50,4,
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined4 *)(lStack_178 + 0x1e1),lStack_178 + 0x309,
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined8 *)(lStack_178 + 0x1d9));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xd70a3d7449453d23U ^ 0xd70a3d70a3d6d970)) {
        uVar3 = (*pcStack_158)(*(undefined2 *)(lStack_178 + 0x149));
        *(ulonglong *)(lStack_178 + 0x9d) = (ulonglong)uVar3;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x1c0f20b6cbb4117U ^ 0x4444444444441310)) {
        iVar5 = (*pcStack_158)(lStack_178 + 0x289,*(undefined8 *)(lStack_178 + 0x299),
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined4 *)(lStack_178 + 0x1e1));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xba90c5335a4d9769U ^ 0xe81b4e81b4e7e980)) {
        lStack_48 = lStack_178 + 0x291;
        uStack_40 = 0x1a0;
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x289),lStack_48,
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined4 *)(lStack_178 + 0x1e1),
                               *(undefined8 *)(lStack_178 + 0x1d9),
                               *(undefined4 *)(lStack_178 + 0x1e1),
                               *(undefined4 *)(lStack_178 + 0x1e1));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x961e5ab669089c69U ^ 0xc28f5c28f5c25cc0)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x291),
                               *(undefined8 *)(lStack_178 + 0x2a1),
                               *(undefined4 *)(lStack_178 + 0x2a9),
                               *(undefined4 *)(lStack_178 + 0x1e1));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x2ffbcdcd78cc4ddbU ^ 0x6666666666663330)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x291),
                               *(undefined8 *)(lStack_178 + 0x2b1),
                               *(undefined4 *)(lStack_178 + 0x2b9),
                               *(undefined4 *)(lStack_178 + 0x1e1));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x59d6a16bb110f34aU ^ 0xa3d70a3d70a09a0)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x291));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0x763b4a4a4f0062b3U ^ 0x7777777777774340)) {
        iVar5 = (*pcStack_158)(*(undefined8 *)(lStack_178 + 0x289),
                               *(undefined4 *)(lStack_178 + 0x1e1));
        *(longlong *)(lStack_178 + 0x9d) = (longlong)iVar5;
        uStack_168 = (ulonglong)uStack_160;
      }
      else if (uStack_168 == (lStack_170 + 0xf6e5d4c68b303900U ^ 0xf6e5d4c3b2a15bd0)) {
        (*pcStack_158)(*(undefined4 *)(lStack_178 + 0x271));
        uStack_168 = (ulonglong)uStack_160;
      }
    }
  }
  return;
}



// ===== FUN_140001000 @ 140001000 off=0x1000 =====

/* WARNING: Removing unreachable block (ram,0x0001400029ff) */
/* WARNING: Removing unreachable block (ram,0x000140002a07) */
/* WARNING: Removing unreachable block (ram,0x000140002a40) */
/* WARNING: Removing unreachable block (ram,0x000140002a74) */
/* WARNING: Removing unreachable block (ram,0x000140002a7a) */

void FUN_140001000(undefined8 param_1)

{
  int iVar1;
  longlong in_RAX;
  longlong in_stack_00000050;
  char cStack0000000000000058;
  undefined1 uStack0000000000000059;
  longlong in_stack_00000060;
  undefined4 uStack0000000000000068;
  undefined4 uStack000000000000006c;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000078;
  longlong in_stack_00000080;
  uint uStack0000000000000088;
  uint uStack000000000000008c;
  undefined8 in_stack_00000090;
  longlong in_stack_00000098;
  undefined2 uStack00000000000000a0;
  int iStack00000000000000a4;
  longlong in_stack_000000a8;
  undefined1 uStack00000000000000b0;
  undefined1 uStack00000000000000b1;
  undefined1 uStack00000000000000b2;
  undefined1 uStack00000000000000b3;
  undefined1 uStack00000000000000b4;
  undefined1 uStack00000000000000b5;
  undefined1 uStack00000000000000b6;
  undefined1 uStack00000000000000b7;
  undefined1 uStack00000000000000b8;
  undefined1 uStack00000000000000b9;
  undefined1 uStack00000000000000ba;
  undefined1 uStack00000000000000bb;
  undefined1 uStack00000000000000bc;
  undefined1 uStack00000000000000bd;
  undefined1 uStack00000000000000be;
  undefined1 uStack00000000000000bf;
  undefined1 uStack00000000000000c0;
  undefined1 uStack00000000000000c1;
  undefined1 uStack00000000000000c2;
  undefined1 uStack00000000000000c3;
  undefined1 uStack00000000000000c4;
  undefined1 uStack00000000000000c5;
  int iStack00000000000000d0;
  undefined1 uStack00000000000000d4;
  undefined1 uStack00000000000000d5;
  undefined1 uStack00000000000000d6;
  undefined1 uStack00000000000000d7;
  undefined1 uStack00000000000000d8;
  undefined1 uStack00000000000000d9;
  undefined1 uStack00000000000000e0;
  undefined1 uStack00000000000000e1;
  undefined1 uStack00000000000000e2;
  undefined1 uStack00000000000000e3;
  undefined1 uStack00000000000000e4;
  undefined1 uStack00000000000000e5;
  undefined1 uStack00000000000000e6;
  undefined1 uStack00000000000000e7;
  undefined1 uStack00000000000000e8;
  undefined1 uStack00000000000000e9;
  undefined1 uStack00000000000000ea;
  undefined1 uStack00000000000000eb;
  undefined1 uStack00000000000000ec;
  undefined1 uStack00000000000000f0;
  undefined1 uStack00000000000000f1;
  undefined1 uStack00000000000000f2;
  undefined1 uStack00000000000000f3;
  undefined1 uStack00000000000000f4;
  undefined1 uStack00000000000000f5;
  undefined1 uStack00000000000000f6;
  undefined1 uStack00000000000000f7;
  undefined1 uStack00000000000000f8;
  undefined1 uStack00000000000000f9;
  undefined1 uStack00000000000000fa;
  undefined1 uStack00000000000000fb;
  undefined1 uStack00000000000000fc;
  undefined1 uStack00000000000000fd;
  undefined1 uStack00000000000000fe;
  undefined1 uStack00000000000000ff;
  undefined1 uStack0000000000000100;
  undefined1 uStack0000000000000101;
  undefined1 uStack0000000000000102;
  undefined1 uStack0000000000000103;
  undefined1 uStack0000000000000104;
  undefined1 uStack0000000000000105;
  undefined1 uStack0000000000000106;
  undefined1 uStack0000000000000107;
  undefined1 uStack0000000000000108;
  undefined1 uStack0000000000000109;
  undefined1 uStack000000000000010a;
  undefined1 uStack000000000000010b;
  undefined1 uStack000000000000010c;
  undefined1 uStack000000000000010d;
  undefined1 uStack000000000000010e;
  undefined1 uStack000000000000010f;
  undefined1 uStack0000000000000110;
  undefined1 uStack0000000000000111;
  undefined1 uStack0000000000000112;
  undefined1 uStack0000000000000113;
  undefined1 uStack0000000000000114;
  undefined1 uStack0000000000000115;
  undefined1 uStack0000000000000116;
  undefined1 uStack0000000000000117;
  undefined1 uStack0000000000000118;
  undefined1 uStack0000000000000119;
  undefined1 uStack000000000000011a;
  undefined1 uStack000000000000011b;
  undefined1 uStack000000000000011c;
  undefined1 uStack000000000000011d;
  undefined1 uStack000000000000011e;
  undefined1 uStack000000000000011f;
  longlong in_stack_00000120;
  int iStack0000000000000128;
  int iStack000000000000012c;
  undefined4 uStack0000000000000130;
  undefined4 uStack0000000000000134;
  uint in_stack_00000138;
  ulonglong in_stack_00000148;
  undefined8 in_stack_00000150;
  longlong in_stack_00000158;
  undefined8 in_stack_00000160;
  uint uStack0000000000000168;
  uint uStack000000000000016c;
  uint uStack0000000000000170;
  undefined4 uStack0000000000000174;
  int iStack0000000000000178;
  undefined4 uStack000000000000017c;
  undefined4 in_stack_00000180;
  int iStack0000000000000188;
  longlong in_stack_00000190;
  code *in_stack_00000198;
  code *in_stack_000001a0;
  undefined4 uStack00000000000001d8;
  longlong in_stack_000001e0;
  longlong in_stack_000001f0;
  longlong in_stack_000001f8;
  undefined8 in_stack_00000200;
  undefined8 in_stack_00000208;
  undefined8 *in_stack_00000210;
  
  do {
    (**(code **)(in_RAX + 0xa9))(param_1);
code_r0x0001400007d5:
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            in_stack_00000098 = 0xffffffffffffffff;
            *(undefined8 *)(in_stack_00000050 + 0x1c1) = *(undefined8 *)(in_stack_00000050 + 0x239);
            *(undefined8 *)(in_stack_00000050 + 0x1c9) = *(undefined8 *)(in_stack_00000050 + 0x241);
            *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x29cf872e2d4;
            (**(code **)(in_stack_00000050 + 0xa9))(0);
            in_stack_00000098 = *(longlong *)(in_stack_00000050 + 0x9d);
            *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
            if (in_stack_00000098 != -1) break;
            *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
            (**(code **)(in_stack_00000050 + 0xa9))(0);
          }
          *(undefined2 *)(in_stack_00000050 + 0x4dd) = 0;
          *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
          iStack0000000000000128 = 0;
          *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
          *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x8526744;
          (**(code **)(in_stack_00000050 + 0xa9))(0);
          iStack0000000000000128 = *(int *)(in_stack_00000050 + 0x9d);
          if (iStack0000000000000128 != -1) break;
          *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
          *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
          (**(code **)(in_stack_00000050 + 0xa9))(0);
          *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
          (**(code **)(in_stack_00000050 + 0xa9))(0);
        }
        (**(code **)(in_stack_00000050 + 0xb1))(&stack0x00000240,0,0x10);
        *(undefined1 **)(in_stack_00000050 + 0x169) = &stack0x00000240;
        in_stack_00000200 = 0;
        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x499d16a5f9d527d0;
        (**(code **)(in_stack_00000050 + 0xa9))(0);
        in_stack_00000200 = *(undefined8 *)(in_stack_00000050 + 0x9d);
        *(undefined4 *)(in_stack_00000050 + 0x4fb) = *(undefined4 *)(in_stack_00000050 + 0x251);
        iStack000000000000012c = 0;
        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xaf4e0c99f0ea4c;
        (**(code **)(in_stack_00000050 + 0xa9))(0);
        iStack000000000000012c = *(int *)(in_stack_00000050 + 0x9d);
        if (iStack000000000000012c != -1) break;
        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
        (**(code **)(in_stack_00000050 + 0xa9))(0);
        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
        (**(code **)(in_stack_00000050 + 0xa9))(0);
      }
      in_stack_00000180 = 0x10000;
      in_stack_00000120 = 0;
      *(undefined8 *)(in_stack_00000050 + 0x131) = in_stack_00000090;
      *(undefined8 *)(in_stack_00000050 + 0x111) = 0x10000;
      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4f8707eefdd993f6;
      (**(code **)(in_stack_00000050 + 0xa9))(0);
      in_stack_00000120 = *(longlong *)(in_stack_00000050 + 0x9d);
      if (in_stack_00000120 != 0) break;
      *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
      (**(code **)(in_stack_00000050 + 0xa9))(0);
      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
      (**(code **)(in_stack_00000050 + 0xa9))(0);
    }
    uStack0000000000000130 = 0;
    uStack00000000000000a0 = 0;
    in_stack_00000078._1_1_ = '\0';
    do {
      do {
        _iStack0000000000000188 = 0;
        in_stack_00000078._4_4_ =
             FUN_14000a674((int)in_stack_00000060 + 0xb2b203efU ^ 0xb2b20d00,in_stack_00000070,
                           uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
        if (in_stack_00000078._4_4_ != 0) goto code_r0x000140000ef7;
      } while (iStack0000000000000188 < 1);
      in_stack_00000158 = 0;
      in_stack_00000078._4_4_ =
           FUN_14000a674((int)in_stack_00000060 + 0x6c21b990U ^ 0x6c21b760,in_stack_00000070,
                         uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
    } while ((in_stack_00000078._4_4_ != 0) || (in_stack_00000158 == 0));
    uStack0000000000000130 = (undefined4)((ulonglong)in_stack_00000158 >> 0x20);
    uStack00000000000000a0 = (undefined2)in_stack_00000158;
    in_stack_00000078._1_1_ = '\x01';
code_r0x000140000ef7:
    if (in_stack_00000120 != 0) {
      *(undefined8 *)(in_stack_00000050 + 0x131) = in_stack_00000090;
      *(longlong *)(in_stack_00000050 + 0x121) = in_stack_00000120;
      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x91160d08d4a2c5;
      (**(code **)(in_stack_00000050 + 0xa9))(0);
    }
    *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
    *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
    (**(code **)(in_stack_00000050 + 0xa9))(0);
    if (in_stack_00000078._1_1_ != '\0') {
      (**(code **)(in_stack_00000050 + 0xb1))(&stack0x00000218,0,0x10);
      uStack000000000000017c = uStack0000000000000130;
      *(longlong *)(in_stack_00000050 + 0x161) = (longlong)&stack0x00000178 + 4;
      *(undefined1 **)(in_stack_00000050 + 0x169) = &stack0x00000218;
      in_stack_00000208 = 0;
      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x499d16a5f9d527d0;
      (**(code **)(in_stack_00000050 + 0xa9))(0);
      in_stack_00000208 = *(undefined8 *)(in_stack_00000050 + 0x9d);
      in_stack_000001f0 = 1;
      in_stack_00000078._4_4_ =
           FUN_14000a674(in_stack_00000060 + 0x24d9e0879f5e9eb1U ^ 0x24d9e0879f5e9040,
                         in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                         uStack0000000000000068);
      if ((in_stack_00000078._4_4_ == 0) && (in_stack_000001f0 == 0)) {
        in_stack_00000080 = 0xffffffffffffffff;
        *(undefined8 *)(in_stack_00000050 + 0x1c1) = *(undefined8 *)(in_stack_00000050 + 0x229);
        *(undefined8 *)(in_stack_00000050 + 0x1c9) = *(undefined8 *)(in_stack_00000050 + 0x231);
        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x29cf872e2d4;
        (**(code **)(in_stack_00000050 + 0xa9))(0);
        in_stack_00000080 = *(longlong *)(in_stack_00000050 + 0x9d);
        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
        if (in_stack_00000080 == -1) {
          *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
          (**(code **)(in_stack_00000050 + 0xa9))(0);
        }
        else {
          in_stack_000001f8 = 1;
          in_stack_00000078._4_4_ =
               FUN_14000a674((int)in_stack_00000060 + 0x774188b2U ^ 0x77418640,in_stack_00000070,
                             uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
          if ((in_stack_00000078._4_4_ == 0) && (in_stack_000001f8 == 0)) {
            cStack0000000000000058 = '\0';
            while( true ) {
              *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
              *(char **)(in_stack_00000050 + 0x179) = &stack0x00000058;
              *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
              *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
              *(char **)(in_stack_00000050 + 0x179) = &stack0x00000058;
              *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
              *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa5161d6;
              (**(code **)(in_stack_00000050 + 0xa9))(0);
              *(longlong *)(in_stack_00000050 + 0x9d) = (longlong)*(int *)(in_stack_00000050 + 0x9d)
              ;
              iStack0000000000000178 = *(int *)(in_stack_00000050 + 0x9d);
              if (iStack0000000000000178 < 1) break;
              if (cStack0000000000000058 == '\x01') {
                (**(code **)(in_stack_00000050 + 0xb1))(&stack0x00000350,0,0x210);
                FUN_14000a674((int)in_stack_00000060 + 0x3e8cead3U ^ 0x3e8ce420,in_stack_00000070,
                              uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
                FUN_14000a674((int)in_stack_00000060 + 0x8c0b1d74U ^ 0x8c0b1380,in_stack_00000070,
                              uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
                FUN_14000a674((int)in_stack_00000060 + 0xd9894c15U ^ 0xd98942e0,in_stack_00000070,
                              uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
              }
              else if (cStack0000000000000058 == '\x10') {
                *(uint *)(in_stack_00000050 + 0x49) =
                     (int)in_stack_00000060 + 0xf82cb1aU ^ 0xf820060;
                (**(code **)(in_stack_00000050 + 0xb1))(in_stack_00000050 + 0x29,0,0x20);
                in_stack_00000078._2_1_ = 0;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000078 + 2;
                *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                uStack0000000000000174 = 0;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000078 + 2;
                *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa716744;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                uStack0000000000000174 = *(undefined4 *)(in_stack_00000050 + 0x9d);
              }
              else if (cStack0000000000000058 == '3') {
                uStack0000000000000059 = 0;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000058 + 1;
                *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000058 + 1;
                *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa5161d6;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                *(longlong *)(in_stack_00000050 + 0x9d) =
                     (longlong)*(int *)(in_stack_00000050 + 0x9d);
                if (*(int *)(in_stack_00000050 + 0x9d) < 1) break;
                if (*(int *)(in_stack_00000050 + 0x49) == 0) {
                  *(uint *)(in_stack_00000050 + 0x49) =
                       (int)in_stack_00000060 + 0xb85ad9daU ^ 0xb85a12a0;
                }
                _uStack00000000000001d8 = 0;
                in_stack_00000078._4_4_ =
                     FUN_14000a674(*(undefined4 *)(in_stack_00000050 + 0x49),in_stack_00000070,
                                   uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
                if (in_stack_00000078._4_4_ == 0) {
                  *(undefined4 *)(in_stack_00000050 + 0x49) = uStack00000000000001d8;
                }
                if (*(uint *)(in_stack_00000050 + 0x49) ==
                    ((int)in_stack_00000060 + 0x71c9ac85U ^ 0x71c9bd00)) {
                  in_stack_00000150 = 0;
                  iStack00000000000000d0 = 0;
                  iStack00000000000000a4 =
                       FUN_14000a21c((int)in_stack_00000060 + 0xf5408ee6U ^ 0xf540a9e0,
                                     in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                     uStack0000000000000068);
                  if (iStack00000000000000a4 == 0) {
                    in_stack_000000a8 = 0;
                    *(undefined8 *)(in_stack_00000050 + 0x131) = in_stack_00000090;
                    *(ulonglong *)(in_stack_00000050 + 0x111) =
                         (ulonglong)(iStack00000000000000d0 + 1);
                    *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4f8707eefdd993f6;
                    (**(code **)(in_stack_00000050 + 0xa9))(0);
                    in_stack_000000a8 = *(longlong *)(in_stack_00000050 + 0x9d);
                    if (in_stack_000000a8 != 0) {
                      in_stack_00000148 = 0;
                      iStack00000000000000a4 =
                           FUN_14000a674(in_stack_00000060 + 0xfece6ac4aeb045c5U ^
                                         0xfece6ac4aeb05440,in_stack_00000070,uStack000000000000006c
                                         ,&stack0x000001b8,uStack0000000000000068);
                      if (iStack00000000000000a4 == 0) {
                        *(undefined1 *)(in_stack_000000a8 + in_stack_00000148) = 0;
                        in_stack_00000198 = (code *)0x0;
                        in_stack_000001a0 = (code *)0x0;
                        in_stack_00000190 =
                             FUN_140006950(in_stack_00000060 + 0xe9945d7b7bec4d99U ^
                                           0xc048d159e26add20);
                        if (in_stack_00000190 != 0) {
                          FUN_140006ab0(in_stack_00000190,
                                        in_stack_00000060 + 0xaa382007ff77667bU ^ 0xe4b17e4b17e49b00
                                        ,&stack0x00000198,in_stack_00000060);
                          FUN_140006ab0(in_stack_00000190,
                                        in_stack_00000060 + 0xb27ec25e8a9d2dceU ^ 0xf6e5d4c3b2a179f0
                                        ,&stack0x000001a0,in_stack_00000060);
                        }
                        if ((in_stack_00000198 != (code *)0x0) && (in_stack_000001a0 != (code *)0x0)
                           ) {
                          uStack00000000000000d4 = 0;
                          uStack00000000000000d5 = 0x89;
                          uStack00000000000000d6 = 0x78;
                          uStack00000000000000d7 = 3;
                          uStack00000000000000d8 = 0x2d;
                          uStack00000000000000d9 = 0xaf;
                          uStack00000000000000f0 = 0x46;
                          uStack00000000000000f1 = 0x89;
                          uStack00000000000000f2 = 0x14;
                          uStack00000000000000f3 = 3;
                          uStack00000000000000f4 = 0x4c;
                          uStack00000000000000f5 = 0xaf;
                          uStack00000000000000f6 = 0x72;
                          uStack00000000000000f7 = 0x89;
                          uStack00000000000000f8 = 0x1d;
                          uStack00000000000000f9 = 3;
                          uStack00000000000000fa = 0;
                          uStack00000000000000fb = 0xaf;
                          uStack00000000000000fc = 0x4f;
                          uStack00000000000000fd = 0x89;
                          uStack00000000000000fe = 0x16;
                          uStack00000000000000ff = 3;
                          uStack0000000000000100 = 0x6e;
                          uStack0000000000000101 = 0xaf;
                          uStack0000000000000102 = 0x61;
                          uStack0000000000000103 = 0x89;
                          uStack0000000000000104 = 0x14;
                          uStack0000000000000105 = 3;
                          uStack0000000000000106 = 0x4e;
                          uStack0000000000000107 = 0xaf;
                          uStack0000000000000108 = 0x75;
                          uStack0000000000000109 = 0x89;
                          uStack000000000000010a = 0x14;
                          uStack000000000000010b = 3;
                          uStack000000000000010c = 0x4c;
                          uStack000000000000010d = 0xaf;
                          uStack000000000000010e = 0x74;
                          uStack000000000000010f = 0x89;
                          uStack0000000000000110 = 0x17;
                          uStack0000000000000111 = 3;
                          uStack0000000000000112 = 0x5f;
                          uStack0000000000000113 = 0xaf;
                          uStack0000000000000114 = 0x43;
                          uStack0000000000000115 = 0x89;
                          uStack0000000000000116 = 0x14;
                          uStack0000000000000117 = 3;
                          uStack0000000000000118 = 0x4c;
                          uStack0000000000000119 = 0xaf;
                          uStack000000000000011a = 0x73;
                          uStack000000000000011b = 0x89;
                          uStack000000000000011c = 0xb;
                          uStack000000000000011d = 3;
                          uStack000000000000011e = 0x2d;
                          uStack000000000000011f = 0xaf;
                          in_stack_00000210 = (undefined8 *)&stack0x000000f0;
                          for (uStack0000000000000088 = 0; uStack0000000000000088 < 0x30;
                              uStack0000000000000088 = uStack0000000000000088 + 1) {
                            uStack0000000000000170 =
                                 (uint)*(byte *)((longlong)&stack0x000000f0 +
                                                (longlong)(int)uStack0000000000000088);
                            *(byte *)((longlong)&stack0x000000f0 +
                                     (longlong)(int)uStack0000000000000088) =
                                 *(byte *)((longlong)&stack0x000000f0 +
                                          (longlong)(int)uStack0000000000000088) ^
                                 *(byte *)((longlong)&stack0x000000d0 +
                                          (ulonglong)(longlong)(int)uStack0000000000000088 % 6 + 4);
                          }
                          in_stack_000001e0 = (*in_stack_00000198)(&stack0x000000f0,0);
                          if (in_stack_000001e0 != 0) {
                            (*in_stack_000001a0)
                                      (in_stack_000001e0,
                                       (int)in_stack_00000060 + 0xa0a376aU ^ 0xa0a3720,0,
                                       &stack0x00000228);
                          }
                        }
                        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                        *(longlong *)(in_stack_00000050 + 0x179) = in_stack_000000a8;
                        *(ulonglong *)(in_stack_00000050 + 0x171) = in_stack_00000148 & 0xffffffff;
                        uStack0000000000000134 = 0;
                        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                        *(longlong *)(in_stack_00000050 + 0x179) = in_stack_000000a8;
                        *(ulonglong *)(in_stack_00000050 + 0x171) = in_stack_00000148 & 0xffffffff;
                        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa716744;
                        (**(code **)(in_stack_00000050 + 0xa9))(0);
                        uStack0000000000000134 = *(undefined4 *)(in_stack_00000050 + 0x9d);
                        in_stack_00000078._3_1_ = 10;
                        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                        *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000078 + 3;
                        *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                        *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000078 + 3;
                        *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa716744;
                        (**(code **)(in_stack_00000050 + 0xa9))(0);
                        uStack0000000000000134 = *(undefined4 *)(in_stack_00000050 + 0x9d);
                      }
                      (**(code **)(in_stack_00000050 + 0xb1))
                                (in_stack_000000a8,0,iStack00000000000000d0 + 1);
                      *(longlong *)(in_stack_00000050 + 0x121) = in_stack_000000a8;
                      *(undefined8 *)(in_stack_00000050 + 0x131) = in_stack_00000090;
                      *(longlong *)(in_stack_00000050 + 0x121) = in_stack_000000a8;
                      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x91160d08d4a2c5;
                      (**(code **)(in_stack_00000050 + 0xa9))(0);
                    }
                    (**(code **)(in_stack_00000050 + 0xb1))
                              (in_stack_00000150,0,iStack00000000000000d0);
                    uStack000000000000016c = 0;
                    *(undefined8 *)(in_stack_00000050 + 0x199) = in_stack_00000150;
                    *(undefined8 *)(in_stack_00000050 + 0x111) = 0;
                    *(undefined8 *)(in_stack_00000050 + 0x1c1) = 0x8000;
                    *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x52a9560cc8d4b869;
                    (**(code **)(in_stack_00000050 + 0xa9))(0);
                    in_stack_00000138 = (uint)(*(longlong *)(in_stack_00000050 + 0x9d) != 0);
                    uStack000000000000016c = in_stack_00000138;
                  }
                  *(uint *)(in_stack_00000050 + 0x49) =
                       (int)in_stack_00000060 + 0x4dde635aU ^ 0x4ddea820;
                  (**(code **)(in_stack_00000050 + 0xb1))(in_stack_00000050 + 0x29,0,0x20);
                }
              }
              else {
                *(uint *)(in_stack_00000050 + 0x49) =
                     (int)in_stack_00000060 + 0xd1555e7aU ^ 0xd1559500;
                (**(code **)(in_stack_00000050 + 0xb1))(in_stack_00000050 + 0x29,0,0x20);
                uStack00000000000000e0 = 0x47;
                uStack00000000000000e1 = 0x3c;
                uStack00000000000000e2 = 0xfc;
                uStack00000000000000e3 = 0x70;
                uStack00000000000000e4 = 0xc5;
                uStack00000000000000e5 = 0xfe;
                uStack00000000000000e6 = 0x4d;
                uStack00000000000000e7 = 0x1f;
                uStack00000000000000e8 = 0x2e;
                uStack00000000000000e9 = 0xdb;
                uStack00000000000000ea = 0xb3;
                uStack00000000000000eb = 0x44;
                uStack00000000000000ec = 0x8a;
                uStack00000000000000b0 = 0x1c;
                uStack00000000000000b1 = 0x11;
                uStack00000000000000b2 = 0xa1;
                uStack00000000000000b3 = 0x50;
                uStack00000000000000b4 = 0x90;
                uStack00000000000000b5 = 0x90;
                uStack00000000000000b6 = 0x26;
                uStack00000000000000b7 = 0x71;
                uStack00000000000000b8 = 0x41;
                uStack00000000000000b9 = 0xac;
                uStack00000000000000ba = 0xdd;
                uStack00000000000000bb = 100;
                uStack00000000000000bc = 0xe9;
                uStack00000000000000bd = 0x28;
                uStack00000000000000be = 0x51;
                uStack00000000000000bf = 0x91;
                uStack00000000000000c0 = 0x11;
                uStack00000000000000c1 = 0xab;
                uStack00000000000000c2 = 0x9a;
                uStack00000000000000c3 = 99;
                uStack00000000000000c4 = 0x15;
                uStack00000000000000c5 = 0x2e;
                for (uStack000000000000008c = 0; uStack000000000000008c < 0x16;
                    uStack000000000000008c = uStack000000000000008c + 1) {
                  uStack0000000000000168 =
                       (uint)*(byte *)((longlong)&stack0x000000b0 +
                                      (longlong)(int)uStack000000000000008c);
                  *(byte *)((longlong)&stack0x000000b0 + (longlong)(int)uStack000000000000008c) =
                       *(byte *)((longlong)&stack0x000000b0 + (longlong)(int)uStack000000000000008c)
                       ^ *(byte *)((longlong)&stack0x000000e0 +
                                  (ulonglong)(longlong)(int)uStack000000000000008c % 0xd);
                }
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(undefined1 **)(in_stack_00000050 + 0x179) = &stack0x000000b0;
                iVar1 = (**(code **)(in_stack_00000050 + 0xc1))(&stack0x000000b0,0x400);
                *(longlong *)(in_stack_00000050 + 0x171) = (longlong)iVar1;
                in_stack_00000160._4_4_ = 0;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(undefined1 **)(in_stack_00000050 + 0x179) = &stack0x000000b0;
                iVar1 = (**(code **)(in_stack_00000050 + 0xc1))(&stack0x000000b0,0x400);
                *(longlong *)(in_stack_00000050 + 0x171) = (longlong)iVar1;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa716744;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                in_stack_00000160._4_4_ = *(undefined4 *)(in_stack_00000050 + 0x9d);
              }
            }
            *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
            *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
            (**(code **)(in_stack_00000050 + 0xa9))(0);
          }
          else {
            *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
            *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
            (**(code **)(in_stack_00000050 + 0xa9))(0);
            *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
            (**(code **)(in_stack_00000050 + 0xa9))(0);
          }
        }
      }
      else {
        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
        (**(code **)(in_stack_00000050 + 0xa9))(0);
      }
      goto code_r0x0001400007d5;
    }
    *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
    param_1 = 0;
    in_RAX = in_stack_00000050;
  } while( true );
}



// ===== FUN_140002000 @ 140002000 off=0x2000 =====

/* WARNING: Removing unreachable block (ram,0x0001400029ff) */
/* WARNING: Removing unreachable block (ram,0x000140002a07) */
/* WARNING: Removing unreachable block (ram,0x000140002a40) */
/* WARNING: Removing unreachable block (ram,0x000140002a74) */
/* WARNING: Removing unreachable block (ram,0x000140002a7a) */

void FUN_140002000(void)

{
  int iVar1;
  char *in_RAX;
  longlong in_stack_00000050;
  char cStack0000000000000058;
  undefined1 uStack0000000000000059;
  longlong in_stack_00000060;
  undefined4 uStack0000000000000068;
  undefined4 uStack000000000000006c;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000078;
  longlong in_stack_00000080;
  uint uStack0000000000000088;
  uint uStack000000000000008c;
  undefined8 in_stack_00000090;
  longlong in_stack_00000098;
  undefined2 uStack00000000000000a0;
  int iStack00000000000000a4;
  longlong in_stack_000000a8;
  undefined1 uStack00000000000000b0;
  undefined1 uStack00000000000000b1;
  undefined1 uStack00000000000000b2;
  undefined1 uStack00000000000000b3;
  undefined1 uStack00000000000000b4;
  undefined1 uStack00000000000000b5;
  undefined1 uStack00000000000000b6;
  undefined1 uStack00000000000000b7;
  undefined1 uStack00000000000000b8;
  undefined1 uStack00000000000000b9;
  undefined1 uStack00000000000000ba;
  undefined1 uStack00000000000000bb;
  undefined1 uStack00000000000000bc;
  undefined1 uStack00000000000000bd;
  undefined1 uStack00000000000000be;
  undefined1 uStack00000000000000bf;
  undefined1 uStack00000000000000c0;
  undefined1 uStack00000000000000c1;
  undefined1 uStack00000000000000c2;
  undefined1 uStack00000000000000c3;
  undefined1 uStack00000000000000c4;
  undefined1 uStack00000000000000c5;
  int iStack00000000000000d0;
  undefined1 uStack00000000000000d4;
  undefined1 uStack00000000000000d5;
  undefined1 uStack00000000000000d6;
  undefined1 uStack00000000000000d7;
  undefined1 uStack00000000000000d8;
  undefined1 uStack00000000000000d9;
  undefined1 uStack00000000000000e0;
  undefined1 uStack00000000000000e1;
  undefined1 uStack00000000000000e2;
  undefined1 uStack00000000000000e3;
  undefined1 uStack00000000000000e4;
  undefined1 uStack00000000000000e5;
  undefined1 uStack00000000000000e6;
  undefined1 uStack00000000000000e7;
  undefined1 uStack00000000000000e8;
  undefined1 uStack00000000000000e9;
  undefined1 uStack00000000000000ea;
  undefined1 uStack00000000000000eb;
  undefined1 uStack00000000000000ec;
  undefined1 uStack00000000000000f0;
  undefined1 uStack00000000000000f1;
  undefined1 uStack00000000000000f2;
  undefined1 uStack00000000000000f3;
  undefined1 uStack00000000000000f4;
  undefined1 uStack00000000000000f5;
  undefined1 uStack00000000000000f6;
  undefined1 uStack00000000000000f7;
  undefined1 uStack00000000000000f8;
  undefined1 uStack00000000000000f9;
  undefined1 uStack00000000000000fa;
  undefined1 uStack00000000000000fb;
  undefined1 uStack00000000000000fc;
  undefined1 uStack00000000000000fd;
  undefined1 uStack00000000000000fe;
  undefined1 uStack00000000000000ff;
  undefined1 uStack0000000000000100;
  undefined1 uStack0000000000000101;
  undefined1 uStack0000000000000102;
  undefined1 uStack0000000000000103;
  undefined1 uStack0000000000000104;
  undefined1 uStack0000000000000105;
  undefined1 uStack0000000000000106;
  undefined1 uStack0000000000000107;
  undefined1 uStack0000000000000108;
  undefined1 uStack0000000000000109;
  undefined1 uStack000000000000010a;
  undefined1 uStack000000000000010b;
  undefined1 uStack000000000000010c;
  undefined1 uStack000000000000010d;
  undefined1 uStack000000000000010e;
  undefined1 uStack000000000000010f;
  undefined1 uStack0000000000000110;
  undefined1 uStack0000000000000111;
  undefined1 uStack0000000000000112;
  undefined1 uStack0000000000000113;
  undefined1 uStack0000000000000114;
  undefined1 uStack0000000000000115;
  undefined1 uStack0000000000000116;
  undefined1 uStack0000000000000117;
  undefined1 uStack0000000000000118;
  undefined1 uStack0000000000000119;
  undefined1 uStack000000000000011a;
  undefined1 uStack000000000000011b;
  undefined1 uStack000000000000011c;
  undefined1 uStack000000000000011e;
  undefined1 uStack000000000000011f;
  longlong in_stack_00000120;
  int iStack0000000000000128;
  int iStack000000000000012c;
  undefined4 uStack0000000000000130;
  undefined4 uStack0000000000000134;
  uint in_stack_00000138;
  ulonglong in_stack_00000148;
  undefined8 in_stack_00000150;
  longlong in_stack_00000158;
  undefined8 in_stack_00000160;
  uint uStack0000000000000168;
  uint uStack000000000000016c;
  uint uStack0000000000000170;
  undefined4 uStack0000000000000174;
  int iStack0000000000000178;
  undefined4 uStack000000000000017c;
  undefined4 in_stack_00000180;
  int iStack0000000000000188;
  longlong in_stack_00000190;
  code *in_stack_00000198;
  code *in_stack_000001a0;
  undefined4 uStack00000000000001d8;
  longlong in_stack_000001e0;
  longlong in_stack_000001f0;
  longlong in_stack_000001f8;
  undefined8 in_stack_00000200;
  undefined8 in_stack_00000208;
  undefined8 *puStack0000000000000210;
  
  *in_RAX = *in_RAX + (char)in_RAX;
  do {
    *(undefined1 *)((longlong)&stack0x000000f0 + (longlong)in_RAX * 0x2d) = 3;
    uStack000000000000011e = 0x2d;
    uStack000000000000011f = 0xaf;
    puStack0000000000000210 = (undefined8 *)&stack0x000000f0;
    for (uStack0000000000000088 = 0; uStack0000000000000088 < 0x30;
        uStack0000000000000088 = uStack0000000000000088 + 1) {
      uStack0000000000000170 =
           (uint)*(byte *)((longlong)&stack0x000000f0 + (longlong)(int)uStack0000000000000088);
      *(byte *)((longlong)&stack0x000000f0 + (longlong)(int)uStack0000000000000088) =
           *(byte *)((longlong)&stack0x000000f0 + (longlong)(int)uStack0000000000000088) ^
           *(byte *)((longlong)&stack0x000000d0 +
                    (ulonglong)(longlong)(int)uStack0000000000000088 % 6 + 4);
    }
    in_stack_000001e0 = (*in_stack_00000198)(&stack0x000000f0,0);
    if (in_stack_000001e0 != 0) {
      (*in_stack_000001a0)
                (in_stack_000001e0,(int)in_stack_00000060 + 0xa0a376aU ^ 0xa0a3720,0,
                 &stack0x00000228);
    }
    do {
      *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
      *(longlong *)(in_stack_00000050 + 0x179) = in_stack_000000a8;
      *(ulonglong *)(in_stack_00000050 + 0x171) = in_stack_00000148 & 0xffffffff;
      uStack0000000000000134 = 0;
      *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
      *(longlong *)(in_stack_00000050 + 0x179) = in_stack_000000a8;
      *(ulonglong *)(in_stack_00000050 + 0x171) = in_stack_00000148 & 0xffffffff;
      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa716744;
      (**(code **)(in_stack_00000050 + 0xa9))(0);
      uStack0000000000000134 = *(undefined4 *)(in_stack_00000050 + 0x9d);
      in_stack_00000078._3_1_ = 10;
      *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
      *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000078 + 3;
      *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
      *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
      *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000078 + 3;
      *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa716744;
      (**(code **)(in_stack_00000050 + 0xa9))(0);
      uStack0000000000000134 = *(undefined4 *)(in_stack_00000050 + 0x9d);
      do {
        (**(code **)(in_stack_00000050 + 0xb1))(in_stack_000000a8,0,iStack00000000000000d0 + 1);
        *(longlong *)(in_stack_00000050 + 0x121) = in_stack_000000a8;
        *(undefined8 *)(in_stack_00000050 + 0x131) = in_stack_00000090;
        *(longlong *)(in_stack_00000050 + 0x121) = in_stack_000000a8;
        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x91160d08d4a2c5;
        (**(code **)(in_stack_00000050 + 0xa9))(0);
        do {
          (**(code **)(in_stack_00000050 + 0xb1))(in_stack_00000150,0,iStack00000000000000d0);
          uStack000000000000016c = 0;
          *(undefined8 *)(in_stack_00000050 + 0x199) = in_stack_00000150;
          *(undefined8 *)(in_stack_00000050 + 0x111) = 0;
          *(undefined8 *)(in_stack_00000050 + 0x1c1) = 0x8000;
          *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x52a9560cc8d4b869;
          (**(code **)(in_stack_00000050 + 0xa9))(0);
          in_stack_00000138 = (uint)(*(longlong *)(in_stack_00000050 + 0x9d) != 0);
          uStack000000000000016c = in_stack_00000138;
          do {
            *(uint *)(in_stack_00000050 + 0x49) = (int)in_stack_00000060 + 0x4dde635aU ^ 0x4ddea820;
            (**(code **)(in_stack_00000050 + 0xb1))(in_stack_00000050 + 0x29,0,0x20);
code_r0x0001400013f4:
            do {
              while( true ) {
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(char **)(in_stack_00000050 + 0x179) = &stack0x00000058;
                *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(char **)(in_stack_00000050 + 0x179) = &stack0x00000058;
                *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa5161d6;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                *(longlong *)(in_stack_00000050 + 0x9d) =
                     (longlong)*(int *)(in_stack_00000050 + 0x9d);
                iStack0000000000000178 = *(int *)(in_stack_00000050 + 0x9d);
                if (0 < iStack0000000000000178) break;
code_r0x0001400029a2:
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
code_r0x0001400007d5:
                while( true ) {
                  while( true ) {
                    while( true ) {
                      while( true ) {
                        in_stack_00000098 = 0xffffffffffffffff;
                        *(undefined8 *)(in_stack_00000050 + 0x1c1) =
                             *(undefined8 *)(in_stack_00000050 + 0x239);
                        *(undefined8 *)(in_stack_00000050 + 0x1c9) =
                             *(undefined8 *)(in_stack_00000050 + 0x241);
                        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x29cf872e2d4;
                        (**(code **)(in_stack_00000050 + 0xa9))(0);
                        in_stack_00000098 = *(longlong *)(in_stack_00000050 + 0x9d);
                        *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                        if (in_stack_00000098 != -1) break;
                        *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
                        (**(code **)(in_stack_00000050 + 0xa9))(0);
                      }
                      *(undefined2 *)(in_stack_00000050 + 0x4dd) = 0;
                      *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                      iStack0000000000000128 = 0;
                      *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x8526744;
                      (**(code **)(in_stack_00000050 + 0xa9))(0);
                      iStack0000000000000128 = *(int *)(in_stack_00000050 + 0x9d);
                      if (iStack0000000000000128 != -1) break;
                      *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
                      (**(code **)(in_stack_00000050 + 0xa9))(0);
                      *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
                      (**(code **)(in_stack_00000050 + 0xa9))(0);
                    }
                    (**(code **)(in_stack_00000050 + 0xb1))(&stack0x00000240,0,0x10);
                    *(undefined1 **)(in_stack_00000050 + 0x169) = &stack0x00000240;
                    in_stack_00000200 = 0;
                    *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x499d16a5f9d527d0;
                    (**(code **)(in_stack_00000050 + 0xa9))(0);
                    in_stack_00000200 = *(undefined8 *)(in_stack_00000050 + 0x9d);
                    *(undefined4 *)(in_stack_00000050 + 0x4fb) =
                         *(undefined4 *)(in_stack_00000050 + 0x251);
                    iStack000000000000012c = 0;
                    *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                    *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                    *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xaf4e0c99f0ea4c;
                    (**(code **)(in_stack_00000050 + 0xa9))(0);
                    iStack000000000000012c = *(int *)(in_stack_00000050 + 0x9d);
                    if (iStack000000000000012c != -1) break;
                    *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                    *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
                    (**(code **)(in_stack_00000050 + 0xa9))(0);
                    *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
                    (**(code **)(in_stack_00000050 + 0xa9))(0);
                  }
                  in_stack_00000180 = 0x10000;
                  in_stack_00000120 = 0;
                  *(undefined8 *)(in_stack_00000050 + 0x131) = in_stack_00000090;
                  *(undefined8 *)(in_stack_00000050 + 0x111) = 0x10000;
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4f8707eefdd993f6;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                  in_stack_00000120 = *(longlong *)(in_stack_00000050 + 0x9d);
                  if (in_stack_00000120 != 0) break;
                  *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                }
                uStack0000000000000130 = 0;
                uStack00000000000000a0 = 0;
                in_stack_00000078._1_1_ = '\0';
                do {
                  do {
                    _iStack0000000000000188 = 0;
                    in_stack_00000078._4_4_ =
                         FUN_14000a674((int)in_stack_00000060 + 0xb2b203efU ^ 0xb2b20d00,
                                       in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                       uStack0000000000000068);
                    if (in_stack_00000078._4_4_ != 0) goto code_r0x000140000ef7;
                  } while (iStack0000000000000188 < 1);
                  in_stack_00000158 = 0;
                  in_stack_00000078._4_4_ =
                       FUN_14000a674((int)in_stack_00000060 + 0x6c21b990U ^ 0x6c21b760,
                                     in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                     uStack0000000000000068);
                } while ((in_stack_00000078._4_4_ != 0) || (in_stack_00000158 == 0));
                uStack0000000000000130 = (undefined4)((ulonglong)in_stack_00000158 >> 0x20);
                uStack00000000000000a0 = (undefined2)in_stack_00000158;
                in_stack_00000078._1_1_ = '\x01';
code_r0x000140000ef7:
                if (in_stack_00000120 != 0) {
                  *(undefined8 *)(in_stack_00000050 + 0x131) = in_stack_00000090;
                  *(longlong *)(in_stack_00000050 + 0x121) = in_stack_00000120;
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x91160d08d4a2c5;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                }
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000098;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                if (in_stack_00000078._1_1_ == '\0') {
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                  goto code_r0x0001400007d5;
                }
                (**(code **)(in_stack_00000050 + 0xb1))(&stack0x00000218,0,0x10);
                uStack000000000000017c = uStack0000000000000130;
                *(longlong *)(in_stack_00000050 + 0x161) = (longlong)&stack0x00000178 + 4;
                *(undefined1 **)(in_stack_00000050 + 0x169) = &stack0x00000218;
                in_stack_00000208 = 0;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x499d16a5f9d527d0;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                in_stack_00000208 = *(undefined8 *)(in_stack_00000050 + 0x9d);
                in_stack_000001f0 = 1;
                in_stack_00000078._4_4_ =
                     FUN_14000a674(in_stack_00000060 + 0x24d9e0879f5e9eb1U ^ 0x24d9e0879f5e9040,
                                   in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                   uStack0000000000000068);
                if ((in_stack_00000078._4_4_ != 0) || (in_stack_000001f0 != 0)) {
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                  goto code_r0x0001400007d5;
                }
                in_stack_00000080 = 0xffffffffffffffff;
                *(undefined8 *)(in_stack_00000050 + 0x1c1) =
                     *(undefined8 *)(in_stack_00000050 + 0x229);
                *(undefined8 *)(in_stack_00000050 + 0x1c9) =
                     *(undefined8 *)(in_stack_00000050 + 0x231);
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x29cf872e2d4;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                in_stack_00000080 = *(longlong *)(in_stack_00000050 + 0x9d);
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                if (in_stack_00000080 == -1) {
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                  goto code_r0x0001400007d5;
                }
                in_stack_000001f8 = 1;
                in_stack_00000078._4_4_ =
                     FUN_14000a674((int)in_stack_00000060 + 0x774188b2U ^ 0x77418640,
                                   in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                   uStack0000000000000068);
                if ((in_stack_00000078._4_4_ != 0) || (in_stack_000001f8 != 0)) {
                  *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4fa7169cf872f3ba;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                  *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x5399162d0;
                  (**(code **)(in_stack_00000050 + 0xa9))(0);
                  goto code_r0x0001400007d5;
                }
                cStack0000000000000058 = '\0';
              }
              if (cStack0000000000000058 == '\x01') {
                (**(code **)(in_stack_00000050 + 0xb1))(&stack0x00000350,0,0x210);
                FUN_14000a674((int)in_stack_00000060 + 0x3e8cead3U ^ 0x3e8ce420,in_stack_00000070,
                              uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
                FUN_14000a674((int)in_stack_00000060 + 0x8c0b1d74U ^ 0x8c0b1380,in_stack_00000070,
                              uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
                FUN_14000a674((int)in_stack_00000060 + 0xd9894c15U ^ 0xd98942e0,in_stack_00000070,
                              uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
                goto code_r0x0001400013f4;
              }
              if (cStack0000000000000058 == '\x10') {
                *(uint *)(in_stack_00000050 + 0x49) =
                     (int)in_stack_00000060 + 0xf82cb1aU ^ 0xf820060;
                (**(code **)(in_stack_00000050 + 0xb1))(in_stack_00000050 + 0x29,0,0x20);
                in_stack_00000078._2_1_ = 0;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000078 + 2;
                *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                uStack0000000000000174 = 0;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000078 + 2;
                *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa716744;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                uStack0000000000000174 = *(undefined4 *)(in_stack_00000050 + 0x9d);
                goto code_r0x0001400013f4;
              }
              if (cStack0000000000000058 != '3') {
                *(uint *)(in_stack_00000050 + 0x49) =
                     (int)in_stack_00000060 + 0xd1555e7aU ^ 0xd1559500;
                (**(code **)(in_stack_00000050 + 0xb1))(in_stack_00000050 + 0x29,0,0x20);
                uStack00000000000000e0 = 0x47;
                uStack00000000000000e1 = 0x3c;
                uStack00000000000000e2 = 0xfc;
                uStack00000000000000e3 = 0x70;
                uStack00000000000000e4 = 0xc5;
                uStack00000000000000e5 = 0xfe;
                uStack00000000000000e6 = 0x4d;
                uStack00000000000000e7 = 0x1f;
                uStack00000000000000e8 = 0x2e;
                uStack00000000000000e9 = 0xdb;
                uStack00000000000000ea = 0xb3;
                uStack00000000000000eb = 0x44;
                uStack00000000000000ec = 0x8a;
                uStack00000000000000b0 = 0x1c;
                uStack00000000000000b1 = 0x11;
                uStack00000000000000b2 = 0xa1;
                uStack00000000000000b3 = 0x50;
                uStack00000000000000b4 = 0x90;
                uStack00000000000000b5 = 0x90;
                uStack00000000000000b6 = 0x26;
                uStack00000000000000b7 = 0x71;
                uStack00000000000000b8 = 0x41;
                uStack00000000000000b9 = 0xac;
                uStack00000000000000ba = 0xdd;
                uStack00000000000000bb = 100;
                uStack00000000000000bc = 0xe9;
                uStack00000000000000bd = 0x28;
                uStack00000000000000be = 0x51;
                uStack00000000000000bf = 0x91;
                uStack00000000000000c0 = 0x11;
                uStack00000000000000c1 = 0xab;
                uStack00000000000000c2 = 0x9a;
                uStack00000000000000c3 = 99;
                uStack00000000000000c4 = 0x15;
                uStack00000000000000c5 = 0x2e;
                for (uStack000000000000008c = 0; uStack000000000000008c < 0x16;
                    uStack000000000000008c = uStack000000000000008c + 1) {
                  uStack0000000000000168 =
                       (uint)*(byte *)((longlong)&stack0x000000b0 +
                                      (longlong)(int)uStack000000000000008c);
                  *(byte *)((longlong)&stack0x000000b0 + (longlong)(int)uStack000000000000008c) =
                       *(byte *)((longlong)&stack0x000000b0 + (longlong)(int)uStack000000000000008c)
                       ^ *(byte *)((longlong)&stack0x000000e0 +
                                  (ulonglong)(longlong)(int)uStack000000000000008c % 0xd);
                }
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(undefined1 **)(in_stack_00000050 + 0x179) = &stack0x000000b0;
                iVar1 = (**(code **)(in_stack_00000050 + 0xc1))(&stack0x000000b0,0x400);
                *(longlong *)(in_stack_00000050 + 0x171) = (longlong)iVar1;
                in_stack_00000160._4_4_ = 0;
                *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
                *(undefined1 **)(in_stack_00000050 + 0x179) = &stack0x000000b0;
                iVar1 = (**(code **)(in_stack_00000050 + 0xc1))(&stack0x000000b0,0x400);
                *(longlong *)(in_stack_00000050 + 0x171) = (longlong)iVar1;
                *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa716744;
                (**(code **)(in_stack_00000050 + 0xa9))(0);
                in_stack_00000160._4_4_ = *(undefined4 *)(in_stack_00000050 + 0x9d);
                goto code_r0x0001400013f4;
              }
              uStack0000000000000059 = 0;
              *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
              *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000058 + 1;
              *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
              *(longlong *)(in_stack_00000050 + 0x139) = in_stack_00000080;
              *(longlong *)(in_stack_00000050 + 0x179) = (longlong)&stack0x00000058 + 1;
              *(undefined8 *)(in_stack_00000050 + 0x171) = 1;
              *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0xa5161d6;
              (**(code **)(in_stack_00000050 + 0xa9))(0);
              *(longlong *)(in_stack_00000050 + 0x9d) = (longlong)*(int *)(in_stack_00000050 + 0x9d)
              ;
              if (*(int *)(in_stack_00000050 + 0x9d) < 1) goto code_r0x0001400029a2;
              if (*(int *)(in_stack_00000050 + 0x49) == 0) {
                *(uint *)(in_stack_00000050 + 0x49) =
                     (int)in_stack_00000060 + 0xb85ad9daU ^ 0xb85a12a0;
              }
              _uStack00000000000001d8 = 0;
              in_stack_00000078._4_4_ =
                   FUN_14000a674(*(undefined4 *)(in_stack_00000050 + 0x49),in_stack_00000070,
                                 uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
              if (in_stack_00000078._4_4_ == 0) {
                *(undefined4 *)(in_stack_00000050 + 0x49) = uStack00000000000001d8;
              }
            } while (*(uint *)(in_stack_00000050 + 0x49) !=
                     ((int)in_stack_00000060 + 0x71c9ac85U ^ 0x71c9bd00));
            in_stack_00000150 = 0;
            iStack00000000000000d0 = 0;
            iStack00000000000000a4 =
                 FUN_14000a21c((int)in_stack_00000060 + 0xf5408ee6U ^ 0xf540a9e0,in_stack_00000070,
                               uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
          } while (iStack00000000000000a4 != 0);
          in_stack_000000a8 = 0;
          *(undefined8 *)(in_stack_00000050 + 0x131) = in_stack_00000090;
          *(ulonglong *)(in_stack_00000050 + 0x111) = (ulonglong)(iStack00000000000000d0 + 1);
          *(undefined8 *)(in_stack_00000050 + 0x1d1) = 0x4f8707eefdd993f6;
          (**(code **)(in_stack_00000050 + 0xa9))(0);
          in_stack_000000a8 = *(longlong *)(in_stack_00000050 + 0x9d);
        } while (in_stack_000000a8 == 0);
        in_stack_00000148 = 0;
        iStack00000000000000a4 =
             FUN_14000a674(in_stack_00000060 + 0xfece6ac4aeb045c5U ^ 0xfece6ac4aeb05440,
                           in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                           uStack0000000000000068);
      } while (iStack00000000000000a4 != 0);
      *(undefined1 *)(in_stack_000000a8 + in_stack_00000148) = 0;
      in_stack_00000198 = (code *)0x0;
      in_stack_000001a0 = (code *)0x0;
      in_stack_00000190 =
           FUN_140006950(in_stack_00000060 + 0xe9945d7b7bec4d99U ^ 0xc048d159e26add20);
      if (in_stack_00000190 != 0) {
        FUN_140006ab0(in_stack_00000190,in_stack_00000060 + 0xaa382007ff77667bU ^ 0xe4b17e4b17e49b00
                      ,&stack0x00000198,in_stack_00000060);
        FUN_140006ab0(in_stack_00000190,in_stack_00000060 + 0xb27ec25e8a9d2dceU ^ 0xf6e5d4c3b2a179f0
                      ,&stack0x000001a0,in_stack_00000060);
      }
    } while ((in_stack_00000198 == (code *)0x0) || (in_stack_000001a0 == (code *)0x0));
    uStack00000000000000d4 = 0;
    uStack00000000000000d5 = 0x89;
    uStack00000000000000d6 = 0x78;
    uStack00000000000000d7 = 3;
    uStack00000000000000d8 = 0x2d;
    uStack00000000000000d9 = 0xaf;
    uStack00000000000000f0 = 0x46;
    uStack00000000000000f1 = 0x89;
    uStack00000000000000f2 = 0x14;
    uStack00000000000000f3 = 3;
    uStack00000000000000f4 = 0x4c;
    uStack00000000000000f5 = 0xaf;
    uStack00000000000000f6 = 0x72;
    uStack00000000000000f7 = 0x89;
    uStack00000000000000f8 = 0x1d;
    uStack00000000000000f9 = 3;
    uStack00000000000000fa = 0;
    uStack00000000000000fb = 0xaf;
    uStack00000000000000fc = 0x4f;
    uStack00000000000000fd = 0x89;
    uStack00000000000000fe = 0x16;
    uStack00000000000000ff = 3;
    uStack0000000000000100 = 0x6e;
    uStack0000000000000101 = 0xaf;
    uStack0000000000000102 = 0x61;
    uStack0000000000000103 = 0x89;
    uStack0000000000000104 = 0x14;
    uStack0000000000000105 = 3;
    uStack0000000000000106 = 0x4e;
    uStack0000000000000107 = 0xaf;
    uStack0000000000000108 = 0x75;
    uStack0000000000000109 = 0x89;
    uStack000000000000010a = 0x14;
    uStack000000000000010b = 3;
    uStack000000000000010c = 0x4c;
    uStack000000000000010d = 0xaf;
    uStack000000000000010e = 0x74;
    uStack000000000000010f = 0x89;
    uStack0000000000000110 = 0x17;
    uStack0000000000000111 = 3;
    uStack0000000000000112 = 0x5f;
    uStack0000000000000113 = 0xaf;
    uStack0000000000000114 = 0x43;
    uStack0000000000000115 = 0x89;
    uStack0000000000000116 = 0x14;
    uStack0000000000000117 = 3;
    uStack0000000000000118 = 0x4c;
    uStack0000000000000119 = 0xaf;
    uStack000000000000011a = 0x73;
    uStack000000000000011b = 0x89;
    uStack000000000000011c = 0xb;
    in_RAX = (char *)0x1;
  } while( true );
}



// ===== FUN_140002500 @ 140002500 off=0x2500 =====

/* WARNING: Control flow encountered bad instruction data */

void FUN_140002500(undefined8 param_1,undefined8 param_2)

{
  byte *pbVar1;
  int in_EAX;
  undefined4 in_register_00000004;
  char *unaff_RBX;
  longlong unaff_RBP;
  
  *(int *)CONCAT44(in_register_00000004,in_EAX) =
       *(int *)CONCAT44(in_register_00000004,in_EAX) + in_EAX;
  *unaff_RBX = *unaff_RBX + (char)((ulonglong)param_2 >> 8);
  pbVar1 = (byte *)(unaff_RBP + 0x3b850fc0);
  *pbVar1 = *pbVar1 << 7 | *pbVar1 >> 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===== FUN_140002800 @ 140002800 off=0x2800 =====

/* WARNING: Control flow encountered bad instruction data */

void FUN_140002800(longlong param_1)

{
  char *pcVar1;
  char in_AL;
  undefined1 in_AH;
  undefined6 in_register_00000002;
  
  *(char *)CONCAT62(in_register_00000002,CONCAT11(in_AH,in_AL)) =
       *(char *)CONCAT62(in_register_00000002,CONCAT11(in_AH,in_AL)) + in_AL;
  *(undefined1 *)(param_1 + 0x8c2484) = *(undefined1 *)(param_1 + 0x8c2484);
  pcVar1 = (char *)(CONCAT62(in_register_00000002,CONCAT11(in_AH,in_AL)) + 99);
  *pcVar1 = *pcVar1 + (char)param_1;
  *(char *)CONCAT62(in_register_00000002,CONCAT11(in_AH,in_AL)) =
       *(char *)CONCAT62(in_register_00000002,CONCAT11(in_AH,in_AL)) + in_AL;
  pcVar1 = (char *)(CONCAT62(in_register_00000002,CONCAT11(in_AH,in_AL)) + -0x7d);
  *pcVar1 = *pcVar1 + (char)param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ===== FUN_14000a9e8 @ 14000a9e8 off=0xa9e8 =====

undefined1 * FUN_14000a9e8(undefined1 *param_1,undefined1 param_2,longlong param_3)

{
  longlong local_res18;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_18 = param_1;
  while( true ) {
    if (local_res18 == 0) break;
    *local_18 = param_2;
    local_18 = local_18 + 1;
    local_res18 = local_res18 + -1;
  }
  return param_1;
}



// ===== FUN_14000aad4 @ 14000aad4 off=0xaad4 =====

ulonglong FUN_14000aad4(char *param_1,ulonglong param_2)

{
  char *local_res8;
  ulonglong local_18;
  
  if (param_1 == (char *)0x0) {
    local_18 = 0;
  }
  else {
    local_18 = 0;
    for (local_res8 = param_1; (local_18 < param_2 && (*local_res8 != '\0'));
        local_res8 = local_res8 + 1) {
      local_18 = local_18 + 1;
    }
  }
  return local_18;
}


