
//===== refs TO 140003380 =====
//  from 1400ea0e4 DATA
//  from 1400decb4 DATA
//  from 1400dece8 DATA
//  from 1400032a8 in FUN_140002a90 UNCONDITIONAL_CALL

// --- caller FUN_140002a90 ---

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140002a90(undefined8 *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  longlong lVar4;
  ulonglong *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ulonglong uVar13;
  ulonglong *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined1 auStackY_138 [32];
  longlong **local_100;
  ulonglong *local_f8;
  ulonglong *puStack_f0;
  ulonglong *local_e8;
  longlong *local_e0;
  undefined1 *puStack_d8;
  longlong local_d0;
  undefined1 local_c8 [16];
  longlong *local_b8;
  ulonglong uStack_b0;
  longlong lStack_a8;
  longlong local_a0;
  longlong lStack_98;
  longlong *local_88;
  longlong lStack_80;
  longlong local_78;
  ulonglong uStack_70;
  ulonglong local_68;
  ulonglong local_60;
  
  local_60 = DAT_1400e2040 ^ (ulonglong)auStackY_138;
  if (*(int *)*param_1 == -0x3fffff72) {
    iVar12 = 0;
    iVar9 = iVar12;
    if (param_1[1] != 0) {
      *(undefined8 *)(param_1[1] + 0x1a0) = 0;
      iVar8 = iVar12;
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0xc);
      *(undefined8 *)(param_1[1] + 0x1a8) = 0;
      FUN_140025870();
      FUN_140034830();
      *(undefined2 *)(param_1[1] + 0x102) = 0;
      FUN_14001b770();
      FUN_14008cb80();
    }
    do {
      lVar4 = DAT_1400e9228;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    FUN_140023980();
    uVar13 = DAT_1400e9250;
    iVar9 = iVar12;
    do {
      iVar9 = iVar9 + 1;
    } while (iVar9 < 3);
    local_88 = (longlong *)0x0;
    lStack_80 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    uVar15 = DAT_1400e9258 + DAT_1400e9250;
    puStack_d8 = local_c8;
    local_e0 = (longlong *)FUN_1400bb470(0x10);
    *local_e0 = (longlong)&local_88;
    local_e0[1] = 0;
    local_100 = &local_88;
    local_88 = local_e0;
    for (; uVar13 != uVar15; uVar13 = uVar13 + 1) {
      FUN_140007690((longlong)&local_88,
                    (undefined8 *)
                    (*(longlong *)(DAT_1400e9240 + (uVar13 >> 1 & DAT_1400e9248 - 1U) * 8) +
                    (ulonglong)((uint)uVar13 & 1) * 8));
    }
    iVar9 = (int)lVar4;
    uVar13 = (ulonglong)(iVar9 + 0x50cac920U ^ 0x50cac920);
    iVar8 = iVar12;
    do {
      iVar8 = iVar8 + 1;
    } while (iVar8 < 7);
    uVar17 = (ulonglong)(iVar9 + 0xebc727e0U ^ 0xebc727e0);
    FUN_14001b8a0();
    FUN_140008d50();
    uVar16 = (ulonglong)(iVar9 + 0xd441b600U ^ 0xd441b600);
    FUN_140086c80();
    uVar15 = uStack_70;
    if ((lVar4 + 0xadf610866f3e14c3U ^ 0xadf610866f3e14c0) <= local_68) {
      uStack_b0 = 0;
      lStack_a8 = 0;
      local_a0 = 0;
      lStack_98 = 0;
      uVar13 = local_68 + uStack_70;
      puStack_d8 = local_c8;
      local_e0 = (longlong *)FUN_1400bb470(0x10);
      *local_e0 = (longlong)&local_b8;
      local_e0[1] = 0;
      local_100 = &local_b8;
      local_b8 = local_e0;
      for (; iVar8 = iVar12, uVar15 != uVar13; uVar15 = uVar15 + 1) {
        FUN_140007690((longlong)&local_b8,
                      (undefined8 *)
                      (*(longlong *)(lStack_80 + (uVar15 >> 1 & local_78 - 1U) * 8) +
                      (ulonglong)((uint)uVar15 & 1) * 8));
      }
      do {
        iVar8 = iVar8 + 1;
        iVar10 = iVar12;
      } while (iVar8 < 0xc);
      do {
        iVar10 = iVar10 + 1;
        iVar8 = iVar12;
      } while (iVar10 < 0xb);
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < 6);
      uVar13 = local_a0 + -1 + lStack_98;
      dVar1 = *(double *)
               (*(longlong *)(uStack_b0 + (uVar13 >> 1 & lStack_a8 - 1U) * 8) +
               (ulonglong)((uint)uVar13 & 1) * 8);
      if (lStack_98 == 1) {
        local_a0 = 0;
      }
      lStack_98 = lStack_98 + -1;
      FUN_140079dc0();
      uVar13 = local_a0 + -1 + lStack_98;
      dVar2 = *(double *)
               (*(longlong *)(uStack_b0 + (uVar13 >> 1 & lStack_a8 - 1U) * 8) +
               (ulonglong)((uint)uVar13 & 1) * 8);
      if (lStack_98 == 1) {
        local_a0 = 0;
      }
      lStack_98 = lStack_98 + -1;
      FUN_1400673e0();
      uVar13 = local_a0 + -1 + lStack_98;
      dVar3 = *(double *)
               (*(longlong *)(uStack_b0 + (uVar13 >> 1 & lStack_a8 - 1U) * 8) +
               (ulonglong)((uint)uVar13 & 1) * 8);
      iVar8 = iVar12;
      if (lStack_98 == 1) {
        local_a0 = 0;
      }
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0xb);
      lStack_98 = lStack_98 + -1;
      FUN_1400846e0();
      iVar8 = iVar12;
      do {
        iVar8 = iVar8 + 1;
      } while (iVar8 < 4);
      uVar13 = (ulonglong)((double)(lVar4 + 0xe8cf2de95ea67ca1U ^ 0xe8cf2de95ea67ca0) * dVar1);
      FUN_1400947e0();
      FUN_140047940();
      uVar17 = (ulonglong)((double)(lVar4 + 0xa79ed23b47210ac1U ^ 0xa79ed23b47210ac0) * dVar2);
      FUN_140048250();
      FUN_140044180();
      uVar16 = (ulonglong)((double)(lVar4 + 0x666e768d2f030e60U ^ 0x666e768d2f9b98e0) * dVar3);
      iVar8 = iVar12;
      do {
        iVar8 = iVar8 + 1;
        iVar10 = iVar12;
      } while (iVar8 < 9);
      do {
        iVar10 = iVar10 + 1;
      } while (iVar10 < 10);
      FUN_140007340((longlong)&local_b8);
      plVar6 = local_b8;
      local_b8 = (longlong *)0x0;
      thunk_FUN_1400c9460(plVar6);
    }
    iVar8 = iVar12;
    if (local_68 == 0) {
      local_100 = (longlong **)(lVar4 + 0x82f70edf9be1ba1fU ^ 0x82f70edf641e45e0);
    }
    else {
      uVar15 = (uStack_70 - 1) + local_68;
      dVar1 = *(double *)
               (*(longlong *)(lStack_80 + (uVar15 >> 1 & local_78 - 1U) * 8) +
               (ulonglong)((uint)uVar15 & 1) * 8);
      iVar10 = iVar12;
      do {
        iVar10 = iVar10 + 1;
        iVar11 = iVar12;
      } while (iVar10 < 5);
      do {
        iVar11 = iVar11 + 1;
        iVar10 = iVar12;
      } while (iVar11 < 9);
      do {
        iVar10 = iVar10 + 1;
      } while (iVar10 < 0xd);
      if (local_68 == 1) {
        uStack_70 = 0;
      }
      local_68 = local_68 - 1;
      FUN_14007f390();
      FUN_1400a5b20();
      iVar10 = iVar12;
      do {
        iVar10 = iVar10 + 1;
      } while (iVar10 < 9);
      iVar10 = iVar12;
      do {
        iVar10 = iVar10 + 1;
      } while (iVar10 < 4);
      FUN_140081830();
      FUN_140044060();
      uVar15 = FUN_140006fc0((longlong)&local_88,lVar4);
      local_100 = (longlong **)
                  (uVar15 | (longlong)
                            (int)((int)((double)(lVar4 + 0xbf65fbd51d8df041U ^ 0xbf65fbd51d8df040) *
                                       dVar1) - (iVar9 + 0x1d09afadU ^ 0x1d8df040)));
    }
    do {
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0xd);
    FUN_140086910();
    local_f8 = (ulonglong *)0x0;
    puStack_f0 = (ulonglong *)0x0;
    local_e8 = (ulonglong *)0x0;
    FUN_140007510((longlong *)&local_f8,(undefined8 *)0x0,&local_100);
    FUN_14004d0d0();
    local_100 = (longlong **)(lVar4 + 0x49e5de3a04e7141fU ^ 0x49e5de3afb18ebe0);
    if (puStack_f0 == local_e8) {
      FUN_140007510((longlong *)&local_f8,puStack_f0,&local_100);
    }
    else {
      *puStack_f0 = (ulonglong)local_100;
      puStack_f0 = puStack_f0 + 1;
    }
    local_d0 = lVar4;
    FUN_14006a870();
    iVar9 = iVar12;
    do {
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    local_e0 = (longlong *)
               ((uVar13 & 0xffffffff) << ((char)lVar4 + 0xa0U & 0x3f) | uVar17 & 0xffffffff);
    FUN_140015330();
    iVar9 = iVar12;
    do {
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0xf);
    do {
      iVar12 = iVar12 + 1;
    } while (iVar12 < 6);
    puStack_d8 = (undefined1 *)(uVar16 & 0xffffffff);
    FUN_140057010();
    puVar5 = puStack_f0;
    local_b8 = local_e0;
    uStack_b0 = (ulonglong)puStack_d8;
    lStack_a8 = local_d0;
    puVar14 = local_f8;
    while ((puVar14 != puVar5 && (uVar7 = FUN_140003380(&local_b8,*puVar14), (char)uVar7 == '\0')))
    {
      puVar14 = puVar14 + 1;
    }
    if (local_f8 != (ulonglong *)0x0) {
      puVar14 = local_f8;
      if ((0xfff < ((longlong)local_e8 - (longlong)local_f8 & 0xfffffffffffffff8U)) &&
         (puVar14 = (ulonglong *)local_f8[-1],
         0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)puVar14)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      thunk_FUN_1400c9460(puVar14);
      local_f8 = (ulonglong *)0x0;
      puStack_f0 = (ulonglong *)0x0;
      local_e8 = (ulonglong *)0x0;
    }
    FUN_140007340((longlong)&local_88);
    plVar6 = local_88;
    local_88 = (longlong *)0x0;
    thunk_FUN_1400c9460(plVar6);
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}



//===== refs TO 1400034ce =====
//  from 1400ea0fc DATA
//  from 1400deccc DATA
//  from 1400decdc DATA

//===== refs TO 140002000 =====
//  from 1400ea09c DATA
//  from 14000351d in FUN_140003380 DATA

//===== refs TO 1400019d0 =====
//  from 1400ea090 DATA
//  from 140007d70 in FUN_140007d50 DATA
//  from 140007d77 in FUN_140007d50 DATA

// ===== FUN_140003380 @ 140003380 =====

undefined8 FUN_140003380(undefined8 *param_1,ulonglong param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint local_res8;
  
  uVar2 = param_1[2] + 0x59bff9f6df6184e0 ^ 0x59bff9f6df6184e0;
  if (param_2 != uVar2) {
    return uVar2 & 0xffffffffffffff00;
  }
  lVar3 = (**(code **)(*DAT_1400e9268 + 0x30))(DAT_1400e9268,param_1[2]);
  FUN_14007b280();
  uVar8 = 0;
  iVar7 = 0;
  do {
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xf);
  iVar7 = 0;
  do {
    iVar7 = iVar7 + 1;
  } while (iVar7 < 8);
  FUN_1400b4d10();
  lVar3 = *(longlong *)(((ulonglong)(*(int *)(param_1 + 2) + 0xfdd4d098) ^ 0xfdd4d080) + lVar3);
  iVar7 = 0;
  do {
    iVar7 = iVar7 + 1;
  } while (iVar7 < 10);
  iVar7 = *(int *)(param_1 + 2);
  iVar6 = 0;
  do {
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xd);
  FUN_14000db70();
  iVar6 = 0;
  do {
    iVar6 = iVar6 + 1;
  } while (iVar6 < 9);
  lVar3 = *(longlong *)
           (((ulonglong)(*(int *)(param_1 + 2) + 0xcec9ece0) ^ 0xcec9ecc0) +
           *(longlong *)**(undefined8 **)(((ulonglong)(iVar7 + 0x98d12f60) ^ 0x98d12f40) + lVar3));
  FUN_1400ae7a0();
  uVar2 = FUN_14003ee30();
  if (lVar3 != 0) {
    FUN_14009a5b0();
    FUN_1400a82a0();
    FUN_14007f4c0();
    pcVar4 = (code *)FUN_140001560(lVar3,*(int *)(param_1 + 2) + 0xa53532d7U ^ 0x88399720);
    uVar2 = 0;
    if (pcVar4 != (code *)0x0) {
      puVar5 = (undefined8 *)FUN_1400bb470(0x10);
      uVar1 = param_1[1];
      *puVar5 = *param_1;
      puVar5[1] = uVar1;
      FUN_14003ebf0();
      (*pcVar4)(FUN_140002000,puVar5,0);
      local_res8 = 0x175;
      do {
        local_res8 = local_res8 ^ uVar8;
        uVar2 = (ulonglong)local_res8;
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < 5);
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}


