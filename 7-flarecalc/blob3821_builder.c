
// ===== FUN_140000000 @ 140000000 =====

/* WARNING: Removing unreachable block (ram,0x0001400029ff) */
/* WARNING: Removing unreachable block (ram,0x000140002a07) */
/* WARNING: Removing unreachable block (ram,0x000140002a40) */
/* WARNING: Removing unreachable block (ram,0x000140002a74) */

void FUN_140000000(ulonglong param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lStack_518;
  char cStack_510;
  undefined1 auStack_50f [7];
  longlong lStack_508;
  uint uStack_500;
  undefined4 uStack_4fc;
  longlong lStack_4f8;
  char cStack_4f0;
  char cStack_4ef;
  undefined1 uStack_4ee;
  undefined1 uStack_4ed;
  int iStack_4ec;
  longlong lStack_4e8;
  uint uStack_4e0;
  uint uStack_4dc;
  undefined8 uStack_4d8;
  longlong lStack_4d0;
  undefined2 uStack_4c8;
  int iStack_4c4;
  longlong lStack_4c0;
  byte abStack_4b8 [24];
  uint uStack_4a0;
  uint uStack_49c;
  int iStack_498;
  byte abStack_494 [12];
  byte abStack_488 [16];
  byte abStack_478 [48];
  longlong lStack_448;
  int iStack_440;
  int iStack_43c;
  undefined4 uStack_438;
  undefined4 uStack_434;
  uint uStack_430;
  longlong lStack_428;
  ulonglong uStack_420;
  undefined8 uStack_418;
  longlong lStack_410;
  uint uStack_408;
  undefined4 uStack_404;
  uint uStack_400;
  uint uStack_3fc;
  uint uStack_3f8;
  undefined4 uStack_3f4;
  int iStack_3f0;
  undefined4 uStack_3ec;
  undefined4 uStack_3e8;
  undefined8 uStack_3e0;
  longlong lStack_3d8;
  code *pcStack_3d0;
  code *pcStack_3c8;
  uint uStack_3c0;
  undefined4 uStack_3bc;
  uint uStack_3b8;
  char acStack_3b0 [32];
  undefined8 uStack_390;
  longlong lStack_388;
  longlong lStack_380;
  longlong lStack_378;
  longlong lStack_370;
  undefined8 uStack_368;
  undefined8 uStack_360;
  byte *pbStack_358;
  undefined1 auStack_350 [16];
  ulonglong uStack_340;
  int iStack_338;
  longlong lStack_330;
  undefined1 auStack_328 [16];
  undefined1 auStack_318 [256];
  undefined1 auStack_218 [16];
  undefined1 auStack_208 [256];
  undefined1 auStack_108 [264];
  
  lStack_508 = 0;
  lStack_518 = 0;
  func_0x000140002a84(&lStack_518,0);
  if (lStack_518 != 0) {
    uStack_4d8 = 0;
    *(undefined8 *)(lStack_518 + 0x1d1) = 0x4f87169f756bf4f9;
    (**(code **)(lStack_518 + 0xa9))(0);
    uStack_4d8 = *(undefined8 *)(lStack_518 + 0x9d);
    *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
    lStack_4f8 = 0;
    uStack_4fc = 0;
    iStack_4c4 = func_0x000140009a30(&lStack_4f8,&uStack_4fc);
    if (iStack_4c4 == 0) {
      uVar6 = param_1 >> ((char)lStack_508 - 0x20U & 0x3f);
      uStack_3bc = (undefined4)uVar6;
      uStack_3b8 = (uint)param_1 & ((int)lStack_508 + 0x8fdc8fdfU ^ 0x70237020);
      uStack_408 = param_2 & ((int)lStack_508 + 0x425e607fU ^ 0xbda19f80);
      uStack_500 = func_0x00014000ad44(uVar6 & 0xffffffff,uStack_3b8,uStack_408,acStack_3b0);
      iVar5 = (int)lStack_508;
      if (uStack_500 == (iVar5 + 0xf39a5d00U ^ 0xf39a5d00)) {
        if (lStack_4f8 != 0) {
          *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
          *(longlong *)(lStack_518 + 0x121) = lStack_4f8;
          *(undefined8 *)(lStack_518 + 0x1d1) = 0x91160d08d4a2c5;
          (**(code **)(lStack_518 + 0xa9))(0);
        }
      }
      else {
        uStack_49c = iVar5 + 0xad0a2357U ^ 0xad0a0760;
        uStack_3c0 = iVar5 + 0xfa8836c7U ^ 0xfa8836c0;
        for (uStack_4a0 = 0; uStack_4a0 < uStack_500; uStack_4a0 = uStack_4a0 + 1) {
          uStack_49c = (uStack_49c << ((byte)uStack_3c0 & 0x1f)) + uStack_49c +
                       (int)acStack_3b0[uStack_4a0];
        }
        *(uint *)(lStack_518 + 0xa5) = uStack_49c;
        lStack_380 = 1;
        iStack_4ec = func_0x00014000a674(iVar5 + 0x1761e6eU ^ 0x1761080,lStack_4f8,uStack_4fc,
                                         acStack_3b0,uStack_500,lStack_518,0,0,&lStack_380);
        if ((iStack_4ec == 0) && (lStack_380 == 0)) {
          (**(code **)(lStack_518 + 0xb1))(auStack_318,0,0x100);
          *(undefined1 **)(lStack_518 + 0x159) = auStack_318;
          *(undefined1 **)(lStack_518 + 0x159) = auStack_318;
          *(undefined8 *)(lStack_518 + 0x1d1) = 0x54913e9d49d078a7;
          (**(code **)(lStack_518 + 0xa9))(0);
          *(longlong *)(lStack_518 + 0x9d) = (longlong)*(int *)(lStack_518 + 0x9d);
          if (*(longlong *)(lStack_518 + 0x9d) == -1) {
            if (lStack_4f8 != 0) {
              *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
              *(longlong *)(lStack_518 + 0x121) = lStack_4f8;
              *(undefined8 *)(lStack_518 + 0x1d1) = 0x91160d08d4a2c5;
              (**(code **)(lStack_518 + 0xa9))(0);
            }
          }
          else {
            (**(code **)(lStack_518 + 0xb1))(lStack_518 + 0x4ab,0,0x30);
            *(undefined4 *)(lStack_518 + 0x4af) = 2;
            *(undefined4 *)(lStack_518 + 0x4b3) = 3;
            *(undefined1 **)(lStack_518 + 0x159) = auStack_318;
            *(undefined8 *)(lStack_518 + 0x1d1) = 0x548312252933b531;
            (**(code **)(lStack_518 + 0xa9))(0);
            *(longlong *)(lStack_518 + 0x9d) = (longlong)*(int *)(lStack_518 + 0x9d);
            if (*(longlong *)(lStack_518 + 0x9d) == 0) {
              cStack_4f0 = '\0';
              for (lStack_428 = *(longlong *)(lStack_518 + 0x301); lStack_428 != 0;
                  lStack_428 = *(longlong *)(lStack_428 + 0x28)) {
                if (*(int *)(lStack_428 + 4) == 2) {
                  puVar1 = *(undefined4 **)(lStack_428 + 0x20);
                  uVar2 = puVar1[1];
                  uVar3 = puVar1[2];
                  uVar4 = puVar1[3];
                  *(undefined4 *)(lStack_518 + 0x4db) = *puVar1;
                  *(undefined4 *)(lStack_518 + 0x4df) = uVar2;
                  *(undefined4 *)(lStack_518 + 0x4e3) = uVar3;
                  *(undefined4 *)(lStack_518 + 0x4e7) = uVar4;
                  cStack_4f0 = '\x01';
                  break;
                }
              }
              *(undefined8 *)(lStack_518 + 0x1d1) = 0x45831225293c77f1;
              (**(code **)(lStack_518 + 0xa9))(0);
              if (cStack_4f0 != '\0') {
code_r0x0001400007d5:
                do {
                  while( true ) {
                    while( true ) {
                      while( true ) {
                        while( true ) {
                          lStack_4d0 = 0xffffffffffffffff;
                          *(undefined8 *)(lStack_518 + 0x1c1) = *(undefined8 *)(lStack_518 + 0x239);
                          *(undefined8 *)(lStack_518 + 0x1c9) = *(undefined8 *)(lStack_518 + 0x241);
                          *(undefined8 *)(lStack_518 + 0x1d1) = 0x29cf872e2d4;
                          (**(code **)(lStack_518 + 0xa9))(0);
                          lStack_4d0 = *(longlong *)(lStack_518 + 0x9d);
                          *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                          if (lStack_4d0 != -1) break;
                          *(undefined8 *)(lStack_518 + 0x1d1) = 0x5399162d0;
                          (**(code **)(lStack_518 + 0xa9))(0);
                        }
                        *(undefined2 *)(lStack_518 + 0x4dd) = 0;
                        *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                        iStack_440 = 0;
                        *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                        *(undefined8 *)(lStack_518 + 0x1d1) = 0x8526744;
                        (**(code **)(lStack_518 + 0xa9))(0);
                        iStack_440 = *(int *)(lStack_518 + 0x9d);
                        if (iStack_440 != -1) break;
                        *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                        *(undefined8 *)(lStack_518 + 0x1d1) = 0x4fa7169cf872f3ba;
                        (**(code **)(lStack_518 + 0xa9))(0);
                        *(undefined8 *)(lStack_518 + 0x1d1) = 0x5399162d0;
                        (**(code **)(lStack_518 + 0xa9))(0);
                      }
                      (**(code **)(lStack_518 + 0xb1))(auStack_328,0,0x10);
                      *(undefined1 **)(lStack_518 + 0x169) = auStack_328;
                      uStack_368 = 0;
                      *(undefined8 *)(lStack_518 + 0x1d1) = 0x499d16a5f9d527d0;
                      (**(code **)(lStack_518 + 0xa9))(0);
                      uStack_368 = *(undefined8 *)(lStack_518 + 0x9d);
                      *(undefined4 *)(lStack_518 + 0x4fb) = *(undefined4 *)(lStack_518 + 0x251);
                      iStack_43c = 0;
                      *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                      *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                      *(undefined8 *)(lStack_518 + 0x1d1) = 0xaf4e0c99f0ea4c;
                      (**(code **)(lStack_518 + 0xa9))(0);
                      iStack_43c = *(int *)(lStack_518 + 0x9d);
                      if (iStack_43c != -1) break;
                      *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                      *(undefined8 *)(lStack_518 + 0x1d1) = 0x4fa7169cf872f3ba;
                      (**(code **)(lStack_518 + 0xa9))(0);
                      *(undefined8 *)(lStack_518 + 0x1d1) = 0x5399162d0;
                      (**(code **)(lStack_518 + 0xa9))(0);
                    }
                    uStack_3e8 = 0x10000;
                    lStack_448 = 0;
                    *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
                    *(undefined8 *)(lStack_518 + 0x111) = 0x10000;
                    *(undefined8 *)(lStack_518 + 0x1d1) = 0x4f8707eefdd993f6;
                    (**(code **)(lStack_518 + 0xa9))(0);
                    lStack_448 = *(longlong *)(lStack_518 + 0x9d);
                    if (lStack_448 != 0) break;
                    *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                    *(undefined8 *)(lStack_518 + 0x1d1) = 0x4fa7169cf872f3ba;
                    (**(code **)(lStack_518 + 0xa9))(0);
                    *(undefined8 *)(lStack_518 + 0x1d1) = 0x5399162d0;
                    (**(code **)(lStack_518 + 0xa9))(0);
                  }
                  uStack_438 = 0;
                  uStack_4c8 = 0;
                  cStack_4ef = '\0';
                  do {
                    do {
                      uStack_3e0 = 0;
                      iStack_4ec = func_0x00014000a674((int)lStack_508 + 0xb2b203efU ^ 0xb2b20d00,
                                                       lStack_4f8,uStack_4fc,acStack_3b0,uStack_500,
                                                       lStack_518,lStack_4d0,lStack_448,&uStack_3e0)
                      ;
                      if (iStack_4ec != 0) goto code_r0x000140000ef7;
                    } while ((int)uStack_3e0 < 1);
                    lStack_410 = 0;
                    iStack_4ec = func_0x00014000a674((int)lStack_508 + 0x6c21b990U ^ 0x6c21b760,
                                                     lStack_4f8,uStack_4fc,acStack_3b0,uStack_500,
                                                     lStack_518,lStack_448,uStack_3e0,&lStack_410);
                  } while ((iStack_4ec != 0) || (lStack_410 == 0));
                  uStack_438 = (undefined4)((ulonglong)lStack_410 >> 0x20);
                  uStack_4c8 = (undefined2)lStack_410;
                  cStack_4ef = '\x01';
code_r0x000140000ef7:
                  if (lStack_448 != 0) {
                    *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
                    *(longlong *)(lStack_518 + 0x121) = lStack_448;
                    *(undefined8 *)(lStack_518 + 0x1d1) = 0x91160d08d4a2c5;
                    (**(code **)(lStack_518 + 0xa9))(0);
                  }
                  *(longlong *)(lStack_518 + 0x139) = lStack_4d0;
                  *(undefined8 *)(lStack_518 + 0x1d1) = 0x4fa7169cf872f3ba;
                  (**(code **)(lStack_518 + 0xa9))(0);
                  if (cStack_4ef == '\0') {
                    *(undefined8 *)(lStack_518 + 0x1d1) = 0x5399162d0;
                    (**(code **)(lStack_518 + 0xa9))(0);
                    goto code_r0x0001400007d5;
                  }
                  (**(code **)(lStack_518 + 0xb1))(auStack_350,0,0x10);
                  uStack_3ec = uStack_438;
                  *(undefined4 **)(lStack_518 + 0x161) = &uStack_3ec;
                  *(undefined1 **)(lStack_518 + 0x169) = auStack_350;
                  uStack_360 = 0;
                  *(undefined8 *)(lStack_518 + 0x1d1) = 0x499d16a5f9d527d0;
                  (**(code **)(lStack_518 + 0xa9))(0);
                  uStack_360 = *(undefined8 *)(lStack_518 + 0x9d);
                  lStack_378 = 1;
                  iStack_4ec = func_0x00014000a674(lStack_508 + 0x24d9e0879f5e9eb1U ^
                                                   0x24d9e0879f5e9040,lStack_4f8,uStack_4fc,
                                                   acStack_3b0,uStack_500,lStack_518,auStack_350,
                                                   uStack_4c8,&lStack_378);
                  if ((iStack_4ec == 0) && (lStack_378 == 0)) {
                    lStack_4e8 = 0xffffffffffffffff;
                    *(undefined8 *)(lStack_518 + 0x1c1) = *(undefined8 *)(lStack_518 + 0x229);
                    *(undefined8 *)(lStack_518 + 0x1c9) = *(undefined8 *)(lStack_518 + 0x231);
                    *(undefined8 *)(lStack_518 + 0x1d1) = 0x29cf872e2d4;
                    (**(code **)(lStack_518 + 0xa9))(0);
                    lStack_4e8 = *(longlong *)(lStack_518 + 0x9d);
                    *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                    if (lStack_4e8 == -1) {
                      *(undefined8 *)(lStack_518 + 0x1d1) = 0x5399162d0;
                      (**(code **)(lStack_518 + 0xa9))(0);
                    }
                    else {
                      lStack_370 = 1;
                      iStack_4ec = func_0x00014000a674((int)lStack_508 + 0x774188b2U ^ 0x77418640,
                                                       lStack_4f8,uStack_4fc,acStack_3b0,uStack_500,
                                                       lStack_518,lStack_4e8,0,&lStack_370);
                      if ((iStack_4ec == 0) && (lStack_370 == 0)) {
                        cStack_510 = '\0';
                        while( true ) {
                          *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                          *(char **)(lStack_518 + 0x179) = &cStack_510;
                          *(undefined8 *)(lStack_518 + 0x171) = 1;
                          *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                          *(char **)(lStack_518 + 0x179) = &cStack_510;
                          *(undefined8 *)(lStack_518 + 0x171) = 1;
                          *(undefined8 *)(lStack_518 + 0x1d1) = 0xa5161d6;
                          (**(code **)(lStack_518 + 0xa9))(0);
                          *(longlong *)(lStack_518 + 0x9d) = (longlong)*(int *)(lStack_518 + 0x9d);
                          iStack_3f0 = *(int *)(lStack_518 + 0x9d);
                          if (iStack_3f0 < 1) break;
                          if (cStack_510 == '\x01') {
                            (**(code **)(lStack_518 + 0xb1))(auStack_218,0,0x210);
                            func_0x00014000a674((int)lStack_508 + 0x3e8cead3U ^ 0x3e8ce420,
                                                lStack_4f8,uStack_4fc,acStack_3b0,uStack_500,
                                                lStack_518,auStack_108,0x100,0);
                            func_0x00014000a674((int)lStack_508 + 0x8c0b1d74U ^ 0x8c0b1380,
                                                lStack_4f8,uStack_4fc,acStack_3b0,uStack_500,
                                                lStack_518,auStack_218,auStack_208,0);
                            func_0x00014000a674((int)lStack_508 + 0xd9894c15U ^ 0xd98942e0,
                                                lStack_4f8,uStack_4fc,acStack_3b0,uStack_500,
                                                lStack_518,lStack_4e8,auStack_218,0);
                          }
                          else if (cStack_510 == '\x10') {
                            *(uint *)(lStack_518 + 0x49) = (int)lStack_508 + 0xf82cb1aU ^ 0xf820060;
                            (**(code **)(lStack_518 + 0xb1))(lStack_518 + 0x29,0,0x20);
                            uStack_4ee = 0;
                            *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                            *(undefined1 **)(lStack_518 + 0x179) = &uStack_4ee;
                            *(undefined8 *)(lStack_518 + 0x171) = 1;
                            uStack_3f4 = 0;
                            *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                            *(undefined1 **)(lStack_518 + 0x179) = &uStack_4ee;
                            *(undefined8 *)(lStack_518 + 0x171) = 1;
                            *(undefined8 *)(lStack_518 + 0x1d1) = 0xa716744;
                            (**(code **)(lStack_518 + 0xa9))(0);
                            uStack_3f4 = *(undefined4 *)(lStack_518 + 0x9d);
                          }
                          else if (cStack_510 == '3') {
                            auStack_50f[0] = 0;
                            *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                            *(undefined1 **)(lStack_518 + 0x179) = auStack_50f;
                            *(undefined8 *)(lStack_518 + 0x171) = 1;
                            *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                            *(undefined1 **)(lStack_518 + 0x179) = auStack_50f;
                            *(undefined8 *)(lStack_518 + 0x171) = 1;
                            *(undefined8 *)(lStack_518 + 0x1d1) = 0xa5161d6;
                            (**(code **)(lStack_518 + 0xa9))(0);
                            *(longlong *)(lStack_518 + 0x9d) = (longlong)*(int *)(lStack_518 + 0x9d)
                            ;
                            if (*(int *)(lStack_518 + 0x9d) < 1) break;
                            if (*(int *)(lStack_518 + 0x49) == 0) {
                              *(uint *)(lStack_518 + 0x49) =
                                   (int)lStack_508 + 0xb85ad9daU ^ 0xb85a12a0;
                            }
                            uStack_390 = 0;
                            iStack_4ec = func_0x00014000a674(*(undefined4 *)(lStack_518 + 0x49),
                                                             lStack_4f8,uStack_4fc,acStack_3b0,
                                                             uStack_500,auStack_50f[0],
                                                             lStack_518 + 0x29,0,&uStack_390);
                            if (iStack_4ec == 0) {
                              *(undefined4 *)(lStack_518 + 0x49) = (undefined4)uStack_390;
                            }
                            if (*(uint *)(lStack_518 + 0x49) ==
                                ((int)lStack_508 + 0x71c9ac85U ^ 0x71c9bd00)) {
                              uStack_418 = 0;
                              iStack_498 = 0;
                              iStack_4c4 = func_0x00014000a21c((int)lStack_508 + 0xf5408ee6U ^
                                                               0xf540a9e0,lStack_4f8,uStack_4fc,
                                                               acStack_3b0,uStack_500,&uStack_418,
                                                               &iStack_498);
                              if (iStack_4c4 == 0) {
                                lStack_4c0 = 0;
                                *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
                                *(ulonglong *)(lStack_518 + 0x111) = (ulonglong)(iStack_498 + 1);
                                *(undefined8 *)(lStack_518 + 0x1d1) = 0x4f8707eefdd993f6;
                                (**(code **)(lStack_518 + 0xa9))(0);
                                lStack_4c0 = *(longlong *)(lStack_518 + 0x9d);
                                if (lStack_4c0 != 0) {
                                  uStack_420 = 0;
                                  iStack_4c4 = func_0x00014000a674(lStack_508 + 0xfece6ac4aeb045c5U
                                                                   ^ 0xfece6ac4aeb05440,lStack_4f8,
                                                                   uStack_4fc,acStack_3b0,uStack_500
                                                                   ,lStack_4c0,uStack_418,
                                                                   lStack_518 + 0x29,&uStack_420);
                                  if (iStack_4c4 == 0) {
                                    *(undefined1 *)(lStack_4c0 + uStack_420) = 0;
                                    pcStack_3d0 = (code *)0x0;
                                    pcStack_3c8 = (code *)0x0;
                                    lStack_3d8 = FUN_140006950(lStack_508 + 0xe9945d7b7bec4d99U ^
                                                               0xc048d159e26add20);
                                    if (lStack_3d8 != 0) {
                                      FUN_140006ab0(lStack_3d8,
                                                    lStack_508 + 0xaa382007ff77667bU ^
                                                    0xe4b17e4b17e49b00,&pcStack_3d0,lStack_508);
                                      FUN_140006ab0(lStack_3d8,
                                                    lStack_508 + 0xb27ec25e8a9d2dceU ^
                                                    0xf6e5d4c3b2a179f0,&pcStack_3c8,lStack_508);
                                    }
                                    if ((pcStack_3d0 != (code *)0x0) && (pcStack_3c8 != (code *)0x0)
                                       ) {
                                      abStack_494[0] = 0;
                                      abStack_494[1] = 0x89;
                                      abStack_494[2] = 0x78;
                                      abStack_494[3] = 3;
                                      abStack_494[4] = 0x2d;
                                      abStack_494[5] = 0xaf;
                                      abStack_478[0] = 0x46;
                                      abStack_478[1] = 0x89;
                                      abStack_478[2] = 0x14;
                                      abStack_478[3] = 3;
                                      abStack_478[4] = 0x4c;
                                      abStack_478[5] = 0xaf;
                                      abStack_478[6] = 0x72;
                                      abStack_478[7] = 0x89;
                                      abStack_478[8] = 0x1d;
                                      abStack_478[9] = 3;
                                      abStack_478[10] = 0;
                                      abStack_478[0xb] = 0xaf;
                                      abStack_478[0xc] = 0x4f;
                                      abStack_478[0xd] = 0x89;
                                      abStack_478[0xe] = 0x16;
                                      abStack_478[0xf] = 3;
                                      abStack_478[0x10] = 0x6e;
                                      abStack_478[0x11] = 0xaf;
                                      abStack_478[0x12] = 0x61;
                                      abStack_478[0x13] = 0x89;
                                      abStack_478[0x14] = 0x14;
                                      abStack_478[0x15] = 3;
                                      abStack_478[0x16] = 0x4e;
                                      abStack_478[0x17] = 0xaf;
                                      abStack_478[0x18] = 0x75;
                                      abStack_478[0x19] = 0x89;
                                      abStack_478[0x1a] = 0x14;
                                      abStack_478[0x1b] = 3;
                                      abStack_478[0x1c] = 0x4c;
                                      abStack_478[0x1d] = 0xaf;
                                      abStack_478[0x1e] = 0x74;
                                      abStack_478[0x1f] = 0x89;
                                      abStack_478[0x20] = 0x17;
                                      abStack_478[0x21] = 3;
                                      abStack_478[0x22] = 0x5f;
                                      abStack_478[0x23] = 0xaf;
                                      abStack_478[0x24] = 0x43;
                                      abStack_478[0x25] = 0x89;
                                      abStack_478[0x26] = 0x14;
                                      abStack_478[0x27] = 3;
                                      abStack_478[0x28] = 0x4c;
                                      abStack_478[0x29] = 0xaf;
                                      abStack_478[0x2a] = 0x73;
                                      abStack_478[0x2b] = 0x89;
                                      abStack_478[0x2c] = 0xb;
                                      abStack_478[0x2d] = 3;
                                      abStack_478[0x2e] = 0x2d;
                                      abStack_478[0x2f] = 0xaf;
                                      pbStack_358 = abStack_478;
                                      for (uStack_4e0 = 0; uStack_4e0 < 0x30;
                                          uStack_4e0 = uStack_4e0 + 1) {
                                        uStack_3f8 = (uint)abStack_478[(int)uStack_4e0];
                                        abStack_478[(int)uStack_4e0] =
                                             abStack_478[(int)uStack_4e0] ^
                                             abStack_494[(ulonglong)(longlong)(int)uStack_4e0 % 6];
                                      }
                                      lStack_388 = (*pcStack_3d0)(abStack_478,0);
                                      if (lStack_388 != 0) {
                                        uStack_340 = lStack_508 + 0x77ac44b0e27e838bU ^
                                                     0x77ac44b0218fa900;
                                        iStack_338 = (int)uStack_420 + 1;
                                        lStack_330 = lStack_4c0;
                                        (*pcStack_3c8)(lStack_388,
                                                       (int)lStack_508 + 0xa0a376aU ^ 0xa0a3720,0,
                                                       &uStack_340);
                                      }
                                    }
                                    *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                                    *(longlong *)(lStack_518 + 0x179) = lStack_4c0;
                                    *(ulonglong *)(lStack_518 + 0x171) = uStack_420 & 0xffffffff;
                                    uStack_434 = 0;
                                    *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                                    *(longlong *)(lStack_518 + 0x179) = lStack_4c0;
                                    *(ulonglong *)(lStack_518 + 0x171) = uStack_420 & 0xffffffff;
                                    *(undefined8 *)(lStack_518 + 0x1d1) = 0xa716744;
                                    (**(code **)(lStack_518 + 0xa9))(0);
                                    uStack_434 = *(undefined4 *)(lStack_518 + 0x9d);
                                    uStack_4ed = 10;
                                    *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                                    *(undefined1 **)(lStack_518 + 0x179) = &uStack_4ed;
                                    *(undefined8 *)(lStack_518 + 0x171) = 1;
                                    *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                                    *(undefined1 **)(lStack_518 + 0x179) = &uStack_4ed;
                                    *(undefined8 *)(lStack_518 + 0x171) = 1;
                                    *(undefined8 *)(lStack_518 + 0x1d1) = 0xa716744;
                                    (**(code **)(lStack_518 + 0xa9))(0);
                                    uStack_434 = *(undefined4 *)(lStack_518 + 0x9d);
                                  }
                                  (**(code **)(lStack_518 + 0xb1))(lStack_4c0,0,iStack_498 + 1);
                                  *(longlong *)(lStack_518 + 0x121) = lStack_4c0;
                                  *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
                                  *(longlong *)(lStack_518 + 0x121) = lStack_4c0;
                                  *(undefined8 *)(lStack_518 + 0x1d1) = 0x91160d08d4a2c5;
                                  (**(code **)(lStack_518 + 0xa9))(0);
                                }
                                (**(code **)(lStack_518 + 0xb1))(uStack_418,0,iStack_498);
                                uStack_3fc = 0;
                                *(undefined8 *)(lStack_518 + 0x199) = uStack_418;
                                *(undefined8 *)(lStack_518 + 0x111) = 0;
                                *(undefined8 *)(lStack_518 + 0x1c1) = 0x8000;
                                *(undefined8 *)(lStack_518 + 0x1d1) = 0x52a9560cc8d4b869;
                                (**(code **)(lStack_518 + 0xa9))(0);
                                uStack_430 = (uint)(*(longlong *)(lStack_518 + 0x9d) != 0);
                                uStack_3fc = uStack_430;
                              }
                              *(uint *)(lStack_518 + 0x49) =
                                   (int)lStack_508 + 0x4dde635aU ^ 0x4ddea820;
                              (**(code **)(lStack_518 + 0xb1))(lStack_518 + 0x29,0,0x20);
                            }
                          }
                          else {
                            *(uint *)(lStack_518 + 0x49) =
                                 (int)lStack_508 + 0xd1555e7aU ^ 0xd1559500;
                            (**(code **)(lStack_518 + 0xb1))(lStack_518 + 0x29,0,0x20);
                            abStack_488[0] = 0x47;
                            abStack_488[1] = 0x3c;
                            abStack_488[2] = 0xfc;
                            abStack_488[3] = 0x70;
                            abStack_488[4] = 0xc5;
                            abStack_488[5] = 0xfe;
                            abStack_488[6] = 0x4d;
                            abStack_488[7] = 0x1f;
                            abStack_488[8] = 0x2e;
                            abStack_488[9] = 0xdb;
                            abStack_488[10] = 0xb3;
                            abStack_488[0xb] = 0x44;
                            abStack_488[0xc] = 0x8a;
                            abStack_4b8[0] = 0x1c;
                            abStack_4b8[1] = 0x11;
                            abStack_4b8[2] = 0xa1;
                            abStack_4b8[3] = 0x50;
                            abStack_4b8[4] = 0x90;
                            abStack_4b8[5] = 0x90;
                            abStack_4b8[6] = 0x26;
                            abStack_4b8[7] = 0x71;
                            abStack_4b8[8] = 0x41;
                            abStack_4b8[9] = 0xac;
                            abStack_4b8[10] = 0xdd;
                            abStack_4b8[0xb] = 100;
                            abStack_4b8[0xc] = 0xe9;
                            abStack_4b8[0xd] = 0x28;
                            abStack_4b8[0xe] = 0x51;
                            abStack_4b8[0xf] = 0x91;
                            abStack_4b8[0x10] = 0x11;
                            abStack_4b8[0x11] = 0xab;
                            abStack_4b8[0x12] = 0x9a;
                            abStack_4b8[0x13] = 99;
                            abStack_4b8[0x14] = 0x15;
                            abStack_4b8[0x15] = 0x2e;
                            for (uStack_4dc = 0; uStack_4dc < 0x16; uStack_4dc = uStack_4dc + 1) {
                              uStack_400 = (uint)abStack_4b8[(int)uStack_4dc];
                              abStack_4b8[(int)uStack_4dc] =
                                   abStack_4b8[(int)uStack_4dc] ^
                                   abStack_488[(ulonglong)(longlong)(int)uStack_4dc % 0xd];
                            }
                            *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                            *(byte **)(lStack_518 + 0x179) = abStack_4b8;
                            iVar5 = (**(code **)(lStack_518 + 0xc1))(abStack_4b8,0x400);
                            *(longlong *)(lStack_518 + 0x171) = (longlong)iVar5;
                            uStack_404 = 0;
                            *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                            *(byte **)(lStack_518 + 0x179) = abStack_4b8;
                            iVar5 = (**(code **)(lStack_518 + 0xc1))(abStack_4b8,0x400);
                            *(longlong *)(lStack_518 + 0x171) = (longlong)iVar5;
                            *(undefined8 *)(lStack_518 + 0x1d1) = 0xa716744;
                            (**(code **)(lStack_518 + 0xa9))(0);
                            uStack_404 = *(undefined4 *)(lStack_518 + 0x9d);
                          }
                        }
                        *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                        *(undefined8 *)(lStack_518 + 0x1d1) = 0x4fa7169cf872f3ba;
                        (**(code **)(lStack_518 + 0xa9))(0);
                      }
                      else {
                        *(longlong *)(lStack_518 + 0x139) = lStack_4e8;
                        *(undefined8 *)(lStack_518 + 0x1d1) = 0x4fa7169cf872f3ba;
                        (**(code **)(lStack_518 + 0xa9))(0);
                        *(undefined8 *)(lStack_518 + 0x1d1) = 0x5399162d0;
                        (**(code **)(lStack_518 + 0xa9))(0);
                      }
                    }
                  }
                  else {
                    *(undefined8 *)(lStack_518 + 0x1d1) = 0x5399162d0;
                    (**(code **)(lStack_518 + 0xa9))(0);
                  }
                } while( true );
              }
              if (lStack_4f8 != 0) {
                *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
                *(longlong *)(lStack_518 + 0x121) = lStack_4f8;
                *(undefined8 *)(lStack_518 + 0x1d1) = 0x91160d08d4a2c5;
                (**(code **)(lStack_518 + 0xa9))(0);
              }
            }
            else if (lStack_4f8 != 0) {
              *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
              *(longlong *)(lStack_518 + 0x121) = lStack_4f8;
              *(undefined8 *)(lStack_518 + 0x1d1) = 0x91160d08d4a2c5;
              (**(code **)(lStack_518 + 0xa9))(0);
            }
          }
        }
        else if (lStack_4f8 != 0) {
          *(undefined8 *)(lStack_518 + 0x131) = uStack_4d8;
          *(longlong *)(lStack_518 + 0x121) = lStack_4f8;
          *(undefined8 *)(lStack_518 + 0x1d1) = 0x91160d08d4a2c5;
          (**(code **)(lStack_518 + 0xa9))(0);
        }
      }
    }
  }
  return;
}



// ===== FUN_140001000 @ 140001000 =====

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
             func_0x00014000a674((int)in_stack_00000060 + 0xb2b203efU ^ 0xb2b20d00,in_stack_00000070
                                 ,uStack000000000000006c,&stack0x000001b8,uStack0000000000000068);
        if (in_stack_00000078._4_4_ != 0) goto code_r0x000140000ef7;
      } while (iStack0000000000000188 < 1);
      in_stack_00000158 = 0;
      in_stack_00000078._4_4_ =
           func_0x00014000a674((int)in_stack_00000060 + 0x6c21b990U ^ 0x6c21b760,in_stack_00000070,
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
           func_0x00014000a674(in_stack_00000060 + 0x24d9e0879f5e9eb1U ^ 0x24d9e0879f5e9040,
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
               func_0x00014000a674((int)in_stack_00000060 + 0x774188b2U ^ 0x77418640,
                                   in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                   uStack0000000000000068);
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
                func_0x00014000a674((int)in_stack_00000060 + 0x3e8cead3U ^ 0x3e8ce420,
                                    in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                    uStack0000000000000068);
                func_0x00014000a674((int)in_stack_00000060 + 0x8c0b1d74U ^ 0x8c0b1380,
                                    in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                    uStack0000000000000068);
                func_0x00014000a674((int)in_stack_00000060 + 0xd9894c15U ^ 0xd98942e0,
                                    in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                    uStack0000000000000068);
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
                     func_0x00014000a674(*(undefined4 *)(in_stack_00000050 + 0x49),in_stack_00000070
                                         ,uStack000000000000006c,&stack0x000001b8,
                                         uStack0000000000000068);
                if (in_stack_00000078._4_4_ == 0) {
                  *(undefined4 *)(in_stack_00000050 + 0x49) = uStack00000000000001d8;
                }
                if (*(uint *)(in_stack_00000050 + 0x49) ==
                    ((int)in_stack_00000060 + 0x71c9ac85U ^ 0x71c9bd00)) {
                  in_stack_00000150 = 0;
                  iStack00000000000000d0 = 0;
                  iStack00000000000000a4 =
                       func_0x00014000a21c((int)in_stack_00000060 + 0xf5408ee6U ^ 0xf540a9e0,
                                           in_stack_00000070,uStack000000000000006c,&stack0x000001b8
                                           ,uStack0000000000000068);
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
                           func_0x00014000a674(in_stack_00000060 + 0xfece6ac4aeb045c5U ^
                                               0xfece6ac4aeb05440,in_stack_00000070,
                                               uStack000000000000006c,&stack0x000001b8,
                                               uStack0000000000000068);
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



// ===== FUN_140002000 @ 140002000 =====

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
                         func_0x00014000a674((int)in_stack_00000060 + 0xb2b203efU ^ 0xb2b20d00,
                                             in_stack_00000070,uStack000000000000006c,
                                             &stack0x000001b8,uStack0000000000000068);
                    if (in_stack_00000078._4_4_ != 0) goto code_r0x000140000ef7;
                  } while (iStack0000000000000188 < 1);
                  in_stack_00000158 = 0;
                  in_stack_00000078._4_4_ =
                       func_0x00014000a674((int)in_stack_00000060 + 0x6c21b990U ^ 0x6c21b760,
                                           in_stack_00000070,uStack000000000000006c,&stack0x000001b8
                                           ,uStack0000000000000068);
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
                     func_0x00014000a674(in_stack_00000060 + 0x24d9e0879f5e9eb1U ^
                                         0x24d9e0879f5e9040,in_stack_00000070,uStack000000000000006c
                                         ,&stack0x000001b8,uStack0000000000000068);
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
                     func_0x00014000a674((int)in_stack_00000060 + 0x774188b2U ^ 0x77418640,
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
                func_0x00014000a674((int)in_stack_00000060 + 0x3e8cead3U ^ 0x3e8ce420,
                                    in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                    uStack0000000000000068);
                func_0x00014000a674((int)in_stack_00000060 + 0x8c0b1d74U ^ 0x8c0b1380,
                                    in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                    uStack0000000000000068);
                func_0x00014000a674((int)in_stack_00000060 + 0xd9894c15U ^ 0xd98942e0,
                                    in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                    uStack0000000000000068);
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
                   func_0x00014000a674(*(undefined4 *)(in_stack_00000050 + 0x49),in_stack_00000070,
                                       uStack000000000000006c,&stack0x000001b8,
                                       uStack0000000000000068);
              if (in_stack_00000078._4_4_ == 0) {
                *(undefined4 *)(in_stack_00000050 + 0x49) = uStack00000000000001d8;
              }
            } while (*(uint *)(in_stack_00000050 + 0x49) !=
                     ((int)in_stack_00000060 + 0x71c9ac85U ^ 0x71c9bd00));
            in_stack_00000150 = 0;
            iStack00000000000000d0 = 0;
            iStack00000000000000a4 =
                 func_0x00014000a21c((int)in_stack_00000060 + 0xf5408ee6U ^ 0xf540a9e0,
                                     in_stack_00000070,uStack000000000000006c,&stack0x000001b8,
                                     uStack0000000000000068);
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
             func_0x00014000a674(in_stack_00000060 + 0xfece6ac4aeb045c5U ^ 0xfece6ac4aeb05440,
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



// ===== FUN_140002ca4 @ 140002ca4 =====

undefined4 FUN_140002ca4(void)

{
  undefined4 *in_RAX;
  longlong in_stack_00000028;
  longlong in_stack_00000030;
  longlong *in_stack_00000070;
  
  *in_RAX = 0x52414c46;
  *(undefined4 *)(in_stack_00000028 + 4) = 1;
  *(undefined1 *)(in_stack_00000028 + 0x28) = 0;
  FUN_14000a9e8(in_stack_00000028 + 8,0,0x20);
  FUN_14000a9e8(in_stack_00000028 + 0x29,0,0x20);
  *(undefined4 *)(in_stack_00000028 + 0x49) = 0;
  *(undefined4 *)(in_stack_00000028 + 0xa5) = 0;
  *(undefined8 *)(in_stack_00000028 + 0xa9) = 0x140006dfc;
  *(code **)(in_stack_00000028 + 0xb1) = FUN_14000a9e8;
  *(undefined8 *)(in_stack_00000028 + 0xb9) = 0x14000ab3c;
  *(code **)(in_stack_00000028 + 0xc1) = FUN_14000aad4;
  *(undefined8 *)(in_stack_00000028 + 0x1d9) = 0;
  *(ulonglong *)(in_stack_00000028 + 0x1e1) =
       in_stack_00000030 + 0x1e508510bae5bae0U ^ 0x1e508510bae5bae0;
  *(ulonglong *)(in_stack_00000028 + 0x1e9) =
       in_stack_00000030 + 0x5deb112c8863ea40U ^ 0x5deb112c0863ea40;
  *(ulonglong *)(in_stack_00000028 + 0x1f1) =
       in_stack_00000030 + 0x9d859d4755e219a1U ^ 0x9d859d4755e219a0;
  *(ulonglong *)(in_stack_00000028 + 0x1f9) =
       in_stack_00000030 + 0xdd202962a3604903U ^ 0xdd202962a3604900;
  *(ulonglong *)(in_stack_00000028 + 0x201) =
       in_stack_00000030 + 0x1cbab57df0de7964U ^ 0x1cbab57df0de7860;
  *(ulonglong *)(in_stack_00000028 + 0x209) =
       in_stack_00000030 + 0x5c5541993e5ca7c0U ^ 0x5c5541993e5ca7c0;
  *(ulonglong *)(in_stack_00000028 + 0x211) =
       in_stack_00000030 + 0x9befcdb48bdad728U ^ 0x9befcdb48bdad720;
  *(ulonglong *)(in_stack_00000028 + 0x219) =
       in_stack_00000030 + 0xdb8a59cfd9590482U ^ 0xdb8a59cfd9590680;
  *(ulonglong *)(in_stack_00000028 + 0x221) =
       in_stack_00000030 + 0x1b24e5eb26d735e2U ^ 0x1b24e5eb26d735e0;
  *(ulonglong *)(in_stack_00000028 + 0x229) =
       in_stack_00000030 + 0x5abf720674556541U ^ 0x5abf720674556540;
  *(ulonglong *)(in_stack_00000028 + 0x231) =
       in_stack_00000030 + 0x9a59fe21c1d394a6U ^ 0x9a59fe21c1d394a0;
  *(ulonglong *)(in_stack_00000028 + 0x239) =
       in_stack_00000030 + 0xd9f48a3d0f51c403U ^ 0xd9f48a3d0f51c400;
  *(ulonglong *)(in_stack_00000028 + 0x241) =
       in_stack_00000030 + 0x198f16585ccff360U ^ 0x198f16585ccff360;
  *(ulonglong *)(in_stack_00000028 + 0x249) =
       in_stack_00000030 + 0x5929a273324e22c1U ^ 0x5929a273aa4e22c0;
  *(ulonglong *)(in_stack_00000028 + 0x251) =
       in_stack_00000030 + 0x98c42e8ef7cc5221U ^ 0x98c42e8ef7cc5220;
  *(ulonglong *)(in_stack_00000028 + 0x259) =
       in_stack_00000030 + 0x27a14555c54a8182U ^ 0xd85ebaaa454a8180;
  *(ulonglong *)(in_stack_00000028 + 0x261) =
       in_stack_00000030 + 0x17f946c592cab0f9U ^ 0x17f946c592c8b0e0;
  *(ulonglong *)(in_stack_00000028 + 0x269) =
       in_stack_00000030 + 0x5793d2e0e046e000U ^ 0x5793d2e0e046e040;
  *(ulonglong *)(in_stack_00000028 + 0x271) =
       in_stack_00000030 + 0x972e5efc2dc50c48U ^ 0x972e5efc2dc50fa0;
  *(ulonglong *)(in_stack_00000028 + 0x279) =
       in_stack_00000030 + 0xd6c8eb177b433e00U ^ 0xd6c8eb177b433f00;
  *(ulonglong *)(in_stack_00000028 + 0x281) =
       in_stack_00000030 + 0x16637732c8c16e70U ^ 0x16637732c8c16e60;
  *(undefined8 *)(in_stack_00000028 + 0xc9) = 0;
  *(undefined8 *)(in_stack_00000028 + 0xd1) = 0;
  *(undefined8 *)(in_stack_00000028 + 0xd9) = 0;
  *(undefined8 *)(in_stack_00000028 + 0xe1) = 0;
  if (in_stack_00000070 != (longlong *)0x0) {
    *in_stack_00000070 = in_stack_00000028;
  }
  return 0;
}



// ===== FUN_140002500 @ 140002500 =====

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



// ===== FUN_140002800 @ 140002800 =====

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



// total funcs now: 16
