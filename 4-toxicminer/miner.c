// ==== FUN_140100920 size=5613

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140100920(uint *param_1)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 *puVar11;
  uint *puVar12;
  int iVar13;
  HANDLE pvVar14;
  __time64_t _Var15;
  undefined8 *puVar16;
  __time64_t _Var17;
  double *pdVar18;
  int *piVar19;
  void *pvVar20;
  uint *puVar21;
  longlong lVar22;
  longlong lVar23;
  undefined *puVar24;
  DWORD_PTR dwThreadAffinityMask;
  char *pcVar25;
  size_t _Size;
  uint uVar26;
  undefined8 uVar27;
  uint uVar28;
  longlong lVar29;
  ulonglong uVar30;
  bool bVar31;
  float fVar32;
  undefined1 auStack_258 [32];
  undefined8 local_238;
  int local_230;
  ulonglong local_228;
  ulonglong *local_220;
  int local_218;
  int local_214;
  __time64_t local_210;
  uint *local_208;
  __time64_t local_200;
  undefined1 local_1f8 [8];
  undefined1 local_1f0 [8];
  uint local_1e8 [10];
  undefined1 auStack_1bd [33];
  uint uStack_19c;
  char *local_e8;
  char *local_e0;
  char *local_d8;
  void *local_c8;
  undefined1 local_b8 [16];
  undefined1 local_a8 [32];
  ulonglong local_88;
  
  local_88 = DAT_1404455c0 ^ (ulonglong)auStack_258;
  uVar3 = *param_1;
  lVar29 = (longlong)(int)uVar3;
  local_200 = 0;
  local_210 = 0;
  local_220 = (ulonglong *)0x0;
  uVar28 = (int)(0xffffffff / (ulonglong)DAT_140491ac4) * (uVar3 + 1) - 0x20;
  local_208 = param_1;
  memset(local_1e8,0,0x128);
  if ((DAT_140491aa8 == 0) && (DAT_140491aa0 == 0)) {
    uVar27 = 0x13;
  }
  else {
    uVar27 = 0;
  }
  FUN_140103760(0,0,uVar27);
  if (1 < DAT_140495d18) {
    if (DAT_140441300 == 0xffffffffffffffff) {
      if ((int)DAT_140491ac4 < 2) goto LAB_140100a87;
      if (DAT_140491aa4 != 0) {
        local_238 = (ulonglong *)
                    CONCAT44(local_238._4_4_,
                             1 << ((byte)((longlong)(int)uVar3 % (longlong)DAT_140495d18) & 0x1f));
        FUN_140117b70(4,s_Binding_thread__d_to_cpu__d__mas_1404425c8,uVar3,
                      (longlong)(int)uVar3 % (longlong)DAT_140495d18 & 0xffffffff);
      }
      dwThreadAffinityMask = (DWORD_PTR)(uint)(1 << ((byte)((int)uVar3 % DAT_140495d18) & 0x1f));
    }
    else {
      if (DAT_140491aa4 != 0) {
        FUN_140117b70(4,s_Binding_thread__d_to_cpu_mask__x_1404425f0,uVar3,DAT_140441300);
      }
      dwThreadAffinityMask = DAT_140441300 & 0xffffffff;
    }
    if (uVar3 == 0xffffffff) {
      pvVar14 = GetCurrentProcess();
      SetProcessAffinityMask(pvVar14,dwThreadAffinityMask);
    }
    else {
      pvVar14 = GetCurrentThread();
      SetThreadAffinityMask(pvVar14,dwThreadAffinityMask);
    }
  }
LAB_140100a87:
  if (DAT_140441934 == 0x24) {
    local_220 = (ulonglong *)FUN_1401374c0(DAT_140441938);
    dVar10 = DAT_1401b9d68;
    dVar9 = DAT_14022cd70;
    dVar8 = DAT_14022cd78;
    if (local_220 == (ulonglong *)0x0) {
      FUN_140117b70(0,s_scrypt_buffer_allocation_failed_140442618);
      FUN_1401b21c0(&DAT_140495d28);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
  else {
    dVar10 = DAT_1401b9d68;
    dVar9 = DAT_14022cd70;
    dVar8 = DAT_14022cd78;
    if ((DAT_140441934 == 0x21) &&
       (local_220 = malloc((longlong)(DAT_14044193c << 10)), dVar10 = DAT_1401b9d68,
       dVar9 = DAT_14022cd70, dVar8 = DAT_14022cd78, local_220 == (ulonglong *)0x0)) {
      FUN_140117b70(0,s_pluck_buffer_allocation_failed_140442638);
      FUN_1401b21c0(&DAT_140495d28);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
LAB_140100b50:
  while( true ) {
    bVar7 = false;
    bVar31 = false;
    lVar23 = 0;
    uVar26 = 0x4c;
    if ((DAT_140441934 == 0x12) || (DAT_140441934 == 0x43)) {
      lVar23 = 1;
      _Size = 0x48;
    }
    else if (DAT_140441934 == 0x10) {
      _Size = 0x8c;
      uVar26 = 0x8c;
      bVar31 = true;
    }
    else {
      bVar31 = bVar7;
      if (DAT_140441934 == 0x17) {
        _Size = 0x6c;
        uVar26 = 0x6c;
      }
      else {
        _Size = 0x4c;
        if (DAT_140441934 == 0x28) {
          _Size = 0x20;
          lVar23 = 0x30;
          uVar26 = 0x20;
        }
      }
    }
    if (DAT_140491af8 != 0) {
      _Size = 0x27;
      uVar26 = 0x27;
    }
    uVar30 = (ulonglong)uVar26;
    if (DAT_140491ab8 == 0) break;
    while ((DAT_140491af8 == 0 &&
           (_Var15 = _time64((__time64_t *)0x0), DAT_140491db8 + 0x78 <= _Var15))) {
      Sleep(1000);
    }
    while ((DAT_140495ba8 == 0.0 && (DAT_140441934 == 3))) {
      FUN_140117b70(4,s_Waiting_for_Stratum_to_set_the_j_140442658);
      Sleep(1000);
    }
    FUN_1401b21c0(&DAT_140491dc0);
    if (bVar31) {
LAB_140100cd3:
      FUN_140103c00(&DAT_1404959a0,&DAT_140491c90);
    }
    else if (uVar28 <= *(uint *)((longlong)local_1e8 + uVar30)) {
      iVar13 = memcmp(local_1e8 + lVar23,&DAT_140491c90 + lVar23 * 4,_Size);
      if ((iVar13 == 0) && (DAT_140491af8 == 0)) goto LAB_140100cd3;
      iVar13 = memcmp(auStack_1bd,&DAT_140491cbb,0x21);
      if (iVar13 == 0) {
        FUN_140103c00(&DAT_1404959a0,&DAT_140491c90);
      }
    }
LAB_140100d70:
    iVar13 = memcmp(local_1e8 + lVar23,&DAT_140491c90 + lVar23 * 4,_Size);
    if (((iVar13 == 0) && (DAT_140491af8 == 0)) ||
       (iVar13 = memcmp(auStack_1bd,&DAT_140491cbb,0x21), iVar13 == 0)) {
      *(int *)((longlong)local_1e8 + uVar30) = *(int *)((longlong)local_1e8 + uVar30) + 1;
    }
    else {
      if (local_e8 != (char *)0x0) {
        free(local_e8);
      }
      if (local_e0 != (char *)0x0) {
        free(local_e0);
      }
      if (local_d8 != (char *)0x0) {
        free(local_d8);
      }
      if (local_c8 != (void *)0x0) {
        free(local_c8);
      }
      lVar23 = 2;
      puVar11 = (undefined8 *)&DAT_140491c90;
      puVar12 = local_1e8;
      do {
        puVar21 = puVar12;
        puVar16 = puVar11;
        uVar27 = puVar16[1];
        uVar4 = puVar16[2];
        uVar5 = puVar16[3];
        *(undefined8 *)puVar21 = *puVar16;
        *(undefined8 *)(puVar21 + 2) = uVar27;
        uVar27 = puVar16[4];
        uVar6 = puVar16[5];
        *(undefined8 *)(puVar21 + 4) = uVar4;
        *(undefined8 *)(puVar21 + 6) = uVar5;
        uVar4 = puVar16[6];
        uVar5 = puVar16[7];
        *(undefined8 *)(puVar21 + 8) = uVar27;
        *(undefined8 *)(puVar21 + 10) = uVar6;
        uVar27 = puVar16[8];
        uVar6 = puVar16[9];
        *(undefined8 *)(puVar21 + 0xc) = uVar4;
        *(undefined8 *)(puVar21 + 0xe) = uVar5;
        uVar4 = puVar16[10];
        uVar5 = puVar16[0xb];
        *(undefined8 *)(puVar21 + 0x10) = uVar27;
        *(undefined8 *)(puVar21 + 0x12) = uVar6;
        uVar27 = puVar16[0xc];
        uVar6 = puVar16[0xd];
        *(undefined8 *)(puVar21 + 0x14) = uVar4;
        *(undefined8 *)(puVar21 + 0x16) = uVar5;
        uVar4 = puVar16[0xe];
        uVar5 = puVar16[0xf];
        *(undefined8 *)(puVar21 + 0x18) = uVar27;
        *(undefined8 *)(puVar21 + 0x1a) = uVar6;
        *(undefined8 *)(puVar21 + 0x1c) = uVar4;
        *(undefined8 *)(puVar21 + 0x1e) = uVar5;
        lVar23 = lVar23 + -1;
        puVar11 = puVar16 + 0x10;
        puVar12 = puVar21 + 0x20;
      } while (lVar23 != 0);
      uVar4 = puVar16[0x11];
      uVar5 = puVar16[0x12];
      uVar6 = puVar16[0x13];
      uVar27 = puVar16[0x14];
      *(undefined8 *)(puVar21 + 0x20) = puVar16[0x10];
      *(undefined8 *)(puVar21 + 0x22) = uVar4;
      *(undefined8 *)(puVar21 + 0x24) = uVar5;
      *(undefined8 *)(puVar21 + 0x26) = uVar6;
      *(undefined8 *)(puVar21 + 0x28) = uVar27;
      if (DAT_140491d90 != (char *)0x0) {
        local_e8 = _strdup(DAT_140491d90);
      }
      if (DAT_140491d98 != (char *)0x0) {
        local_e0 = _strdup(DAT_140491d98);
      }
      if (DAT_140491da0 != (char *)0x0) {
        local_d8 = _strdup(DAT_140491da0);
      }
      if (DAT_140491db0 != (void *)0x0) {
        local_c8 = malloc(DAT_140491da8);
        memcpy(local_c8,DAT_140491db0,DAT_140491da8);
      }
      *(uint *)((longlong)local_1e8 + (ulonglong)uVar26) =
           (int)(0xffffffff / (ulonglong)DAT_140491ac4) * uVar3;
      if (DAT_140491b60 != 0) {
        iVar13 = rand();
        piVar19 = (int *)((longlong)local_1e8 + (ulonglong)uVar26);
        *piVar19 = *piVar19 + (uint)(iVar13 << 2) / DAT_140491ac4;
      }
    }
    FUN_1401b27a0(&DAT_140491dc0);
    bVar31 = DAT_140441934 == 0x10;
    *(undefined1 *)(lVar29 * 0x80 + DAT_140491ac8) = 0;
    if (bVar31) goto code_r0x000140100f55;
    if (DAT_140441934 != 0x28) goto LAB_140100f83;
    if ((DAT_140491ab8 == 0) || (iVar13 = strcmp(DAT_140495b08,local_d8), iVar13 == 0)) {
      *(uint *)((longlong)local_1e8 + uVar30 + 4) =
           *(int *)((longlong)local_1e8 + uVar30 + 4) + 0x10U | uVar3;
      goto LAB_140100fa0;
    }
  }
  iVar13 = DAT_140441930;
  if (DAT_140491ab4 != 0) {
    iVar13 = 0x3c;
  }
  FUN_1401b21c0();
  if (DAT_140491ab8 == 0) {
    _Var15 = _time64((__time64_t *)0x0);
    puVar12 = local_208;
    if (((longlong)iVar13 <= _Var15 - DAT_140491db8) || (uVar28 <= uStack_19c)) {
      iVar13 = FUN_1400ff9a0(local_208,&DAT_140491c90);
      if (iVar13 == 0) {
        FUN_140117b70(0,s_work_retrieval_failed__exiting_m_140442688,*puVar12);
        FUN_1401b27a0(&DAT_140491dc0);
        goto switchD_1401012c4_default;
      }
      if (DAT_140491ab8 == 0) {
        DAT_140491db8 = _time64((__time64_t *)0x0);
      }
      else {
        DAT_140491db8 = 0;
      }
    }
    if (DAT_140491ab8 == 0) goto LAB_140100d70;
  }
  goto LAB_140101d59;
code_r0x000140100f55:
  if ((DAT_140491ab8 != 0) && (iVar13 = strcmp(DAT_140495b08,local_d8), iVar13 != 0))
  goto LAB_140100b50;
  piVar19 = (int *)((longlong)local_1e8 + uVar30 + 4);
  *piVar19 = *piVar19 + 1;
  puVar12 = (uint *)((longlong)local_1e8 + uVar30 + 8);
  *puVar12 = *puVar12 | uVar3;
LAB_140100f83:
  if (((DAT_140491ab8 != 0) && (local_1e8[0] == 0)) && (DAT_140491aa8 == 0)) {
LAB_140101194:
    Sleep(1000);
    goto LAB_140100b50;
  }
LAB_140100fa0:
  bVar31 = true;
  if (0.0 < DAT_140491bd0) {
    fVar32 = (float)FUN_140107cf0();
    if (DAT_140491bd0 < (double)fVar32) {
      if (((uVar3 == 0) && (_DAT_140491b90 == 0)) && (DAT_140491ab0 == 0)) {
        FUN_140117b70(3,s_temperature_too_high____0fC___wa_140442540,(double)fVar32);
      }
      bVar31 = false;
    }
  }
  if ((0.0 < DAT_140491bd8) && (DAT_140491bd8 < DAT_140491ae8)) {
    if ((uVar3 == 0) && ((_DAT_140491b90 == 0 && (DAT_140491ab0 == 0)))) {
      FUN_140117b70(3,s_network_diff_too_high__waiting___140442570);
    }
    bVar31 = false;
  }
  if ((0.0 < DAT_140491be0) && (DAT_140491be0 < DAT_140491af0)) {
    if ((uVar3 == 0) && ((_DAT_140491b90 == 0 && (DAT_140491ab0 == 0)))) {
      FUN_140117dd0();
      FUN_140117b70(3,s_network_hashrate_too_high__waiti_140442598,local_a8);
    }
    bVar31 = false;
  }
  if ((int)uVar3 < 0x10) {
    *(uint *)(&DAT_140491b90 + lVar29 * 4) = (uint)!bVar31;
  }
  if (!bVar31) {
    Sleep(5000);
    goto LAB_140100b50;
  }
  if (DAT_140491ab8 == 0) {
    _Var15 = _time64((__time64_t *)0x0);
    iVar13 = DAT_140441930;
    if (DAT_140491ab4 != 0) {
      iVar13 = 0x3c;
    }
    lVar23 = (iVar13 - _Var15) + DAT_140491db8;
  }
  else {
    lVar23 = 0x3c;
  }
  _Var15 = local_210;
  if ((DAT_140491bf4 != 0) && (local_210 != 0)) {
    _Var17 = _time64((__time64_t *)0x0);
    iVar13 = ((int)_Var15 + DAT_140491bf4) - (int)_Var17;
    if (iVar13 < 0) {
      if (uVar3 == 0) {
        if (DAT_140491aa8 == 0) {
          FUN_140117b70(2,s_Mining_timeout_of__ds_reached__e_1404426d0);
        }
        else {
          FUN_140117dd0((double)DAT_140491ad8,local_a8);
          FUN_140117b70(2,s_Benchmark___s_1404426b8,local_a8);
          uVar27 = __acrt_iob_func(2);
          FUN_1400fe2c0(uVar27,s__llu_1404426c8,DAT_140491ad8);
        }
                    /* WARNING: Subroutine does not return */
        FUN_140103230(0);
      }
      goto LAB_140101194;
    }
    if (iVar13 < lVar23) {
      lVar23 = (longlong)iVar13;
    }
  }
  lVar23 = lVar23 * (longlong)*(double *)(DAT_140495d10 + lVar29 * 8);
  if (lVar23 < 1) {
    switch(DAT_140441934) {
    case 3:
    case 0x24:
      if (DAT_140441938 < 0x10) {
        iVar13 = 0x3ffff;
      }
      else {
        iVar13 = (int)(0x3fffff / (longlong)DAT_140441938);
      }
      lVar23 = (longlong)iVar13;
      if (DAT_140441940 < 4) {
        if (0x10 < DAT_140441940) {
          lVar23 = 0xf;
        }
      }
      else {
        lVar23 = lVar23 >> ((char)DAT_140441940 - 3U & 0x3f);
      }
      break;
    default:
      lVar23 = 0x1fffff;
      break;
    case 5:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1f:
    case 0x20:
    case 0x2e:
    case 0x2f:
    case 0x3e:
      lVar23 = 0xffff;
      break;
    case 6:
    case 0xe:
    case 0xf:
    case 0x25:
      lVar23 = 0x40;
      break;
    case 8:
    case 9:
    case 0x10:
    case 0x31:
      lVar23 = 0x3fffff;
      break;
    case 0xc:
    case 0xd:
    case 0x11:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x1c:
    case 0x1e:
    case 0x29:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
      lVar23 = 0x3ffff;
      break;
    case 0x12:
    case 0x21:
    case 0x3f:
    case 0x40:
      lVar23 = 0x1ff;
      break;
    case 0x17:
    case 0x2c:
    case 0x30:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x43:
      lVar23 = 0x1ffff;
      break;
    case 0x2a:
    case 0x2b:
      lVar23 = 0x7ffff;
      break;
    case 0x41:
    case 0x42:
      lVar23 = 0xfff;
    }
  }
  uVar26 = uVar28;
  if ((longlong)(lVar23 + (ulonglong)*(uint *)((longlong)local_1e8 + uVar30)) <=
      (longlong)(ulonglong)uVar28) {
    uVar26 = (int)lVar23 + *(uint *)((longlong)local_1e8 + uVar30);
  }
  local_228 = 0;
  FUN_1400fa460(local_1f8,0);
  if (_Var15 == 0) {
    local_210 = _time64((__time64_t *)0x0);
  }
  switch(DAT_140441934) {
  case 0:
  case 1:
    iVar13 = FUN_140125870(uVar3,local_1e8,uVar26);
    break;
  case 2:
    iVar13 = FUN_1401254a0(uVar3,local_1e8,uVar26);
    break;
  case 3:
    local_238 = (ulonglong *)(CONCAT44(local_238._4_4_,DAT_140441940 << 8) | 0x80000020);
    iVar13 = FUN_14012cc20(uVar3,local_1e8,uVar26);
    break;
  case 4:
    iVar13 = FUN_140132540(uVar3,local_1e8,uVar26);
    break;
  case 5:
    iVar13 = FUN_14011e680(uVar3,local_1e8,uVar26);
    break;
  case 6:
    iVar13 = FUN_14011ee30(uVar3,local_1e8,uVar26);
    break;
  case 7:
    iVar13 = FUN_14011f790(uVar3,local_1e8,uVar26);
    break;
  case 8:
    iVar13 = FUN_140120440(uVar3,local_1e8,uVar26);
    break;
  case 9:
  case 0x31:
    iVar13 = FUN_140120a40(uVar3,local_1e8,uVar26);
    break;
  case 10:
    iVar13 = FUN_1401367c0(uVar3,local_1e8,uVar26);
    break;
  case 0xb:
    iVar13 = FUN_140120fc0(uVar3,local_1e8,uVar26);
    break;
  case 0xc:
    iVar13 = FUN_1401214e0(uVar3,local_1e8,uVar26);
    break;
  case 0xd:
    iVar13 = FUN_140121c20(uVar3,local_1e8,uVar26);
    break;
  case 0xe:
    iVar13 = FUN_140122840(uVar3,local_1e8,uVar26);
    break;
  case 0xf:
    iVar13 = FUN_1401231a0(uVar3,local_1e8,uVar26);
    break;
  case 0x10:
    iVar13 = FUN_140123440(uVar3,local_1e8,uVar26);
    break;
  case 0x11:
  case 0x15:
    iVar13 = FUN_140124d80(uVar3,local_1e8,uVar26);
    break;
  case 0x12:
    iVar13 = FUN_1401238d0(uVar3,local_1e8,uVar26);
    break;
  case 0x13:
    iVar13 = FUN_140123f50(uVar3,local_1e8,uVar26);
    break;
  case 0x14:
    iVar13 = FUN_140124690(uVar3,local_1e8,uVar26);
    break;
  case 0x16:
    iVar13 = FUN_1401265d0(uVar3,local_1e8,uVar26);
    break;
  case 0x17:
    iVar13 = FUN_140126c10(uVar3,local_1e8,uVar26);
    break;
  case 0x18:
    iVar13 = FUN_140127090(uVar3,local_1e8,uVar26);
    break;
  case 0x19:
    iVar13 = FUN_140127680(uVar3,local_1e8,uVar26);
    break;
  case 0x1a:
    iVar13 = FUN_140127de0(uVar3,local_1e8,uVar26);
    break;
  case 0x1b:
    iVar13 = FUN_140128550(uVar3,local_1e8,uVar26);
    break;
  case 0x1c:
    iVar13 = FUN_140128ba0(uVar3,local_1e8,uVar26);
    break;
  case 0x1d:
    iVar13 = FUN_14012d6c0(uVar3,local_1e8,uVar26);
    break;
  case 0x1e:
    iVar13 = FUN_14012dde0(uVar3,local_1e8,uVar26);
    break;
  case 0x1f:
    iVar13 = FUN_14012e540(uVar3,local_1e8,uVar26);
    break;
  case 0x20:
    iVar13 = FUN_14012ed40(uVar3,local_1e8,uVar26);
    break;
  case 0x21:
    local_230 = DAT_14044193c;
    local_238 = local_220;
    iVar13 = FUN_14012f580(uVar3,local_1e8,uVar26);
    break;
  case 0x22:
    iVar13 = FUN_140132ae0(uVar3,local_1e8,uVar26);
    break;
  case 0x23:
    iVar13 = FUN_140134060(uVar3,local_1e8,uVar26);
    break;
  case 0x24:
    local_230 = DAT_140441938;
    local_238 = local_220;
    iVar13 = FUN_140136e30(uVar3,local_1e8,uVar26);
    break;
  case 0x25:
    local_238 = &local_228;
    iVar13 = FUN_140138410(DAT_140441938,uVar3,local_1e8);
    break;
  case 0x26:
    iVar13 = FUN_140125dc0(uVar3,local_1e8,uVar26);
    break;
  case 0x27:
    iVar13 = FUN_140134f70(uVar3,local_1e8,uVar26);
    break;
  case 0x28:
    iVar13 = FUN_140136c40(uVar3,local_1e8,uVar26);
    break;
  case 0x29:
    iVar13 = FUN_1401393b0(uVar3,local_1e8,uVar26);
    break;
  case 0x2a:
    iVar13 = FUN_140139ae0(uVar3,local_1e8,uVar26);
    break;
  case 0x2b:
    iVar13 = FUN_14013a060(uVar3,local_1e8,uVar26);
    break;
  case 0x2c:
    iVar13 = FUN_14013a5d0(uVar3,local_1e8,uVar26);
    break;
  case 0x2d:
    iVar13 = FUN_140134720(uVar3,local_1e8,uVar26);
    break;
  case 0x2e:
    iVar13 = FUN_14013bc20(uVar3,local_1e8,uVar26);
    break;
  case 0x2f:
    iVar13 = FUN_14011ffb0(uVar3,local_1e8,uVar26);
    break;
  case 0x30:
    iVar13 = FUN_14013c3b0(uVar3,local_1e8,uVar26);
    break;
  case 0x32:
    iVar13 = FUN_14013ca40(uVar3,local_1e8,uVar26);
    break;
  case 0x33:
    iVar13 = FUN_14013d3d0(uVar3,local_1e8,uVar26);
    break;
  case 0x34:
    iVar13 = FUN_14013dbe0(uVar3,local_1e8,uVar26);
    break;
  case 0x35:
    iVar13 = FUN_14013e2e0(uVar3,local_1e8,uVar26);
    break;
  case 0x36:
    iVar13 = FUN_14013ea10(uVar3,local_1e8,uVar26);
    break;
  case 0x37:
    iVar13 = FUN_14013f200(uVar3,local_1e8,uVar26);
    break;
  case 0x38:
    iVar13 = FUN_14013fa20(uVar3,local_1e8,uVar26);
    break;
  case 0x39:
    iVar13 = FUN_140140310(uVar3,local_1e8,uVar26);
    break;
  case 0x3a:
    iVar13 = FUN_140140c70(uVar3,local_1e8,uVar26);
    break;
  case 0x3b:
    iVar13 = FUN_140141770(uVar3,local_1e8,uVar26);
    break;
  case 0x3c:
    iVar13 = FUN_1401420d0(uVar3,local_1e8,uVar26);
    break;
  case 0x3d:
    iVar13 = FUN_1401428e0(uVar3,local_1e8,uVar26);
    break;
  case 0x3e:
    iVar13 = FUN_140143330(uVar3,local_1e8,uVar26);
    break;
  case 0x3f:
    iVar13 = FUN_140144210(uVar3,local_1e8,uVar26);
    break;
  case 0x40:
    iVar13 = FUN_140144270(uVar3,local_1e8,uVar26);
    break;
  case 0x41:
    iVar13 = FUN_140144230(uVar3,local_1e8,uVar26);
    break;
  case 0x42:
    iVar13 = FUN_140144250(uVar3,local_1e8,uVar26);
    break;
  case 0x43:
    iVar13 = FUN_140144290(uVar3,local_1e8,uVar26);
    break;
  default:
    goto switchD_1401012c4_default;
  }
  FUN_1400fa460(local_1f0,0);
  FUN_14011e050(&local_218,local_1f0);
  if ((local_214 != 0) || (local_218 != 0)) {
    FUN_1401b21c0(&DAT_140495970);
    *(double *)(DAT_140495d10 + lVar29 * 8) =
         (double)local_228 / ((double)local_214 * _DAT_1401b9d20 + (double)local_218);
    FUN_1401b27a0();
  }
  if ((DAT_140491ab0 == 0) &&
     (_Var15 = _time64((__time64_t *)0x0), (longlong)DAT_1404412f8 < _Var15 - local_200)) {
    if ((DAT_140441934 == 6) ||
       ((((DAT_140441934 == 0xe || (DAT_140441934 == 0xf)) || (DAT_140441934 == 0x21)) ||
        (DAT_140441934 == 0x25)))) {
      FUN_140117b70(3,s_CPU___d____2f_H_s_140442700);
    }
    else {
      puVar24 = &DAT_14044271c;
      dVar1 = *(double *)(DAT_140495d10 + lVar29 * 8);
      if (dVar8 <= dVar1) {
        puVar24 = &DAT_140442714;
      }
      FUN_1400fb060(local_b8,puVar24,dVar1 / dVar9);
      FUN_140117b70(3,s_CPU___d___s_kH_s_140442728);
    }
    local_200 = _time64((__time64_t *)0x0);
  }
  if ((DAT_140491aa8 != 0) && (uVar3 == DAT_140491ac4 - 1)) {
    uVar26 = 0;
    lVar23 = 0;
    dVar1 = 0.0;
    if (3 < (int)DAT_140491ac4) {
      lVar22 = 0;
      dVar1 = 0.0;
      do {
        if (*(double *)(lVar22 + DAT_140495d10) == 0.0) goto LAB_140101bd7;
        dVar1 = dVar1 + *(double *)(lVar22 + DAT_140495d10);
        dVar2 = *(double *)(lVar22 + 8 + DAT_140495d10);
        if (dVar2 == 0.0) {
          uVar26 = uVar26 + 1;
          goto LAB_140101bd7;
        }
        dVar1 = dVar1 + dVar2;
        dVar2 = *(double *)(lVar22 + 0x10 + DAT_140495d10);
        if (dVar2 == 0.0) {
          uVar26 = uVar26 + 2;
          goto LAB_140101bd7;
        }
        dVar1 = dVar1 + dVar2;
        dVar2 = *(double *)(lVar22 + 0x18 + DAT_140495d10);
        if (dVar2 == 0.0) {
          uVar26 = uVar26 + 3;
          goto LAB_140101bd7;
        }
        lVar23 = lVar23 + 4;
        lVar22 = lVar22 + 0x20;
        dVar1 = dVar1 + dVar2;
        uVar26 = uVar26 + 4;
      } while ((int)uVar26 < (int)(DAT_140491ac4 - 3));
    }
    if ((int)uVar26 < (int)DAT_140491ac4) {
      pdVar18 = (double *)(DAT_140495d10 + lVar23 * 8);
      do {
        dVar2 = *pdVar18;
        if (dVar2 == 0.0) break;
        pdVar18 = pdVar18 + 1;
        dVar1 = dVar1 + dVar2;
        uVar26 = uVar26 + 1;
      } while ((int)uVar26 < (int)DAT_140491ac4);
    }
LAB_140101bd7:
    if (uVar26 == DAT_140491ac4) {
      if (((DAT_140441934 == 6) || (DAT_140441934 == 0xe)) ||
         ((DAT_140441934 == 0xf || (DAT_140441934 == 0x25)))) {
        pcVar25 = s_Total___s_H_s_140442748;
        puVar24 = &DAT_14044273c;
        dVar2 = dVar1;
      }
      else {
        puVar24 = &DAT_140442760;
        pcVar25 = s_Total___s_kH_s_140442768;
        dVar2 = dVar1 / dVar9;
        if (dVar8 <= dVar1) {
          puVar24 = &DAT_140442758;
        }
      }
      FUN_1400fb060(local_b8,puVar24,dVar2);
      FUN_140117b70(2,pcVar25,local_b8);
      lVar23 = 0;
      if ((dVar10 <= dVar1) && (dVar1 = dVar1 - dVar10, dVar1 < dVar10)) {
        lVar23 = -0x8000000000000000;
      }
      DAT_140491ad8 = (longlong)dVar1 + lVar23;
    }
  }
  if ((iVar13 == 0) || (DAT_140491aa8 != 0)) goto LAB_140100b50;
  piVar19 = calloc(1,0x18);
  if (piVar19 != (int *)0x0) {
    pvVar20 = malloc(0x128);
    *(void **)(piVar19 + 4) = pvVar20;
    if (pvVar20 != (void *)0x0) {
      *(uint **)(piVar19 + 2) = local_208;
      *piVar19 = 1;
      FUN_140105bf0(pvVar20,local_1e8);
      iVar13 = FUN_14011e220(*(undefined8 *)(DAT_140495d20 + 0x20 + (longlong)DAT_140495ce8 * 0x50),
                             piVar19);
      if (iVar13 != 0) {
        if ((DAT_140491ab8 == 0) && (DAT_140491ab4 == 0)) {
          FUN_1401b21c0(&DAT_140491dc0);
          DAT_140491db8 = 0;
LAB_140101d59:
          FUN_1401b27a0(&DAT_140491dc0);
        }
        goto LAB_140100b50;
      }
    }
    if (*piVar19 == 1) {
      FUN_1401061b0(*(undefined8 *)(piVar19 + 4));
      free(*(void **)(piVar19 + 4));
    }
    piVar19[0] = 0;
    piVar19[1] = 0;
    piVar19[2] = 0;
    piVar19[3] = 0;
    piVar19[4] = 0;
    piVar19[5] = 0;
    free(piVar19);
  }
switchD_1401012c4_default:
  FUN_14011e0f0(*(undefined8 *)(local_208 + 8));
  return 0;
}


