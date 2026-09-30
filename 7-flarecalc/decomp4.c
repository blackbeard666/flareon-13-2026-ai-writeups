
// ===== [target] FUN_140003570 @ 140003570 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140003570(ushort param_1,longlong *param_2,longlong *****param_3)

{
  char cVar1;
  char cVar2;
  undefined8 *puVar3;
  longlong *******ppppppplVar4;
  code *pcVar5;
  ulonglong uVar6;
  longlong ********pppppppplVar7;
  longlong ********pppppppplVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong ********pppppppplVar11;
  longlong ********pppppppplVar12;
  ushort *puVar13;
  undefined8 uVar14;
  undefined1 auStack_2f8 [32];
  longlong *******local_2d8;
  ulonglong uStack_2d0;
  longlong local_2c8;
  ushort local_2b8 [4];
  undefined **local_2b0 [7];
  undefined ***local_278;
  undefined2 local_270;
  undefined **local_268 [7];
  undefined ***local_230;
  undefined2 local_228;
  undefined **local_220 [7];
  undefined ***local_1e8;
  undefined2 local_1e0;
  undefined **local_1d8 [7];
  undefined ***local_1a0;
  undefined2 local_198;
  undefined **local_190 [7];
  undefined ***local_158;
  undefined2 local_150;
  undefined **local_148 [7];
  undefined ***local_110;
  undefined2 local_108;
  undefined **local_100 [7];
  undefined ***local_c8;
  ushort local_c0 [4];
  longlong local_b8 [3];
  longlong *******local_a0;
  longlong lStack_98;
  longlong *******local_90;
  undefined8 uStack_88;
  longlong *local_78;
  ulonglong local_70;
  
  local_70 = DAT_1400e2040 ^ (ulonglong)auStack_2f8;
  local_2b8[0] = 0x2b;
  local_2b0[0] = &PTR_FUN_1400ddd58;
  local_278 = local_2b0;
  local_270 = 0x2d;
  local_268[0] = &PTR_LAB_1400ddd28;
  local_230 = local_268;
  local_228 = 0x2a;
  local_220[0] = &PTR_LAB_1400dddb8;
  local_1e8 = local_220;
  local_1e0 = 0x2f;
  local_1d8[0] = &PTR_LAB_1400dde90;
  local_1a0 = local_1d8;
  local_198 = 0x26;
  local_190[0] = &PTR_LAB_1400ddcf8;
  local_158 = local_190;
  local_150 = 0x7c;
  local_148[0] = &PTR_LAB_1400ddde8;
  local_110 = local_148;
  local_108 = 0x5e;
  local_100[0] = &PTR_LAB_1400dde18;
  local_c8 = local_100;
  local_a0 = (longlong *******)0x0;
  lStack_98 = 0;
  pppppppplVar8 = (longlong ********)FUN_1400bb470(0x68);
  *pppppppplVar8 = (longlong *******)pppppppplVar8;
  pppppppplVar8[1] = (longlong *******)pppppppplVar8;
  pppppppplVar8[2] = (longlong *******)pppppppplVar8;
  *(undefined2 *)(pppppppplVar8 + 3) = 0x101;
  puVar13 = local_2b8;
  local_a0 = (longlong *******)pppppppplVar8;
  do {
    plVar9 = FUN_140008600((longlong *)&local_a0,local_b8,(longlong *)pppppppplVar8,puVar13);
    ppppppplVar4 = local_a0;
    pppppppplVar11 = (longlong ********)*plVar9;
    uVar6 = plVar9[1];
    local_2c8 = plVar9[2];
    if ((char)local_2c8 == '\0') {
      if (lStack_98 == 0x276276276276276) goto LAB_1400039af;
      local_90 = (longlong *******)&local_a0;
      uStack_88 = (longlong *)0x0;
      plVar9 = (longlong *)FUN_1400bb470(0x68);
      uStack_88 = plVar9;
      *(ushort *)(plVar9 + 4) = *puVar13;
      local_78 = plVar9 + 5;
      plVar9[0xc] = 0;
      puVar3 = *(undefined8 **)(puVar13 + 0x20);
      if (puVar3 != (undefined8 *)0x0) {
        lVar10 = (**(code **)*puVar3)(puVar3,plVar9 + 5);
        plVar9[0xc] = lVar10;
      }
      *plVar9 = (longlong)ppppppplVar4;
      plVar9[1] = (longlong)ppppppplVar4;
      plVar9[2] = (longlong)ppppppplVar4;
      *(undefined2 *)(plVar9 + 3) = 0;
      uStack_88 = (longlong *)0x0;
      local_2d8 = (longlong *******)pppppppplVar11;
      uStack_2d0 = uVar6;
      FUN_140007eb0((longlong *)&local_a0,(longlong *)&local_2d8,plVar9);
    }
    puVar13 = puVar13 + 0x24;
  } while (puVar13 != local_c0);
  _eh_vector_destructor_iterator_(local_2b8,0x48,7,FUN_1400039c0);
  ppppppplVar4 = local_a0;
  pppppppplVar8 = (longlong ********)local_a0[1];
  cVar1 = *(char *)((longlong)pppppppplVar8 + 0x19);
  pppppppplVar11 = pppppppplVar8;
  pppppppplVar7 = (longlong ********)local_a0;
  cVar2 = cVar1;
  while (cVar2 == '\0') {
    pppppppplVar12 = pppppppplVar11;
    if (*(ushort *)(pppppppplVar11 + 4) < param_1) {
      pppppppplVar11 = pppppppplVar11 + 2;
      pppppppplVar12 = pppppppplVar7;
    }
    pppppppplVar11 = (longlong ********)*pppppppplVar11;
    pppppppplVar7 = pppppppplVar12;
    cVar2 = *(char *)((longlong)pppppppplVar11 + 0x19);
  }
  if (((*(char *)((longlong)pppppppplVar7 + 0x19) == '\0') &&
      (*(ushort *)(pppppppplVar7 + 4) <= param_1)) && (pppppppplVar7 != (longlong ********)local_a0)
     ) {
    uStack_88 = (longlong *)((ulonglong)uStack_88 & 0xffffffff00000000);
    local_90 = (longlong *******)pppppppplVar8;
    pppppppplVar11 = (longlong ********)local_a0;
    while (pppppppplVar7 = pppppppplVar8, cVar1 == '\0') {
      uStack_88._4_4_ = (uint)((ulonglong)uStack_88 >> 0x20);
      if (*(ushort *)(pppppppplVar7 + 4) < param_1) {
        uStack_88 = (longlong *)((ulonglong)uStack_88._4_4_ << 0x20);
        pppppppplVar8 = pppppppplVar7 + 2;
      }
      else {
        uStack_88 = (longlong *)CONCAT44(uStack_88._4_4_,1);
        pppppppplVar8 = pppppppplVar7;
        pppppppplVar11 = pppppppplVar7;
      }
      cVar1 = *(char *)((longlong)*pppppppplVar8 + 0x19);
      pppppppplVar8 = (longlong ********)*pppppppplVar8;
      local_90 = (longlong *******)pppppppplVar7;
    }
    if ((*(char *)((longlong)pppppppplVar11 + 0x19) != '\0') ||
       (param_1 < *(ushort *)(pppppppplVar11 + 4))) {
      if (lStack_98 == 0x276276276276276) goto LAB_1400039b5;
      local_2d8 = (longlong *******)&local_a0;
      uStack_2d0 = 0;
      plVar9 = (longlong *)FUN_1400bb470(0x68);
      *(ushort *)(plVar9 + 4) = param_1;
      plVar9[0xc] = 0;
      *plVar9 = (longlong)ppppppplVar4;
      plVar9[1] = (longlong)ppppppplVar4;
      plVar9[2] = (longlong)ppppppplVar4;
      *(undefined2 *)(plVar9 + 3) = 0;
      local_2d8 = local_90;
      uStack_2d0 = (ulonglong)uStack_88;
      pppppppplVar11 =
           (longlong ********)FUN_140007eb0((longlong *)&local_a0,(longlong *)&local_2d8,plVar9);
    }
    ppppppplVar4 = pppppppplVar11[0xc];
    local_90 = (longlong *******)param_3;
    local_78 = param_2;
    if (ppppppplVar4 == (longlong *******)0x0) {
      FUN_1400bb14c();
LAB_1400039af:
      FUN_1400014a0();
LAB_1400039b5:
      FUN_1400014a0();
      pcVar5 = (code *)swi(3);
      uVar14 = (*pcVar5)();
      return uVar14;
    }
    uVar14 = (*(code *)(*ppppppplVar4)[2])(ppppppplVar4,&local_78,&local_90);
  }
  else {
    uVar14 = 0;
  }
  FUN_140007480(&local_a0,&local_a0,(longlong *)local_a0[1]);
  thunk_FUN_1400c9460(local_a0);
  return uVar14;
}



// ===== [callee-of-3570] `eh_vector_destructor_iterator' @ 1400bb4ac =====

/* Library Function - Single Match
    void __cdecl `eh vector destructor iterator'(void * __ptr64,unsigned __int64,unsigned
   __int64,void (__cdecl*)(void * __ptr64))
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl
_eh_vector_destructor_iterator_
          (void *param_1,__uint64 param_2,__uint64 param_3,_func_void_void_ptr *param_4)

{
  void *pvVar1;
  
  pvVar1 = (void *)(param_2 * param_3 + (longlong)param_1);
  while( true ) {
    if (param_3 == 0) break;
    pvVar1 = (void *)((longlong)pvVar1 - param_2);
    (*(code *)PTR__guard_dispatch_icall_1400d5308)(pvVar1);
    param_3 = param_3 - 1;
  }
  return;
}



// ===== [callee-of-3570] FUN_1400bb14c @ 1400bb14c =====

void FUN_1400bb14c(void)

{
  longlong local_28 [5];
  
  FUN_1400bb074(local_28);
                    /* WARNING: Subroutine does not return */
  FUN_1400bd258(local_28,&DAT_1400e06b8);
}



// ===== [callee-of-3570] FUN_140007480 @ 140007480 =====

void FUN_140007480(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  cVar1 = *(char *)((longlong)param_3 + 0x19);
  while (cVar1 == '\0') {
    FUN_140007480(param_1,param_2,(longlong *)param_3[2]);
    plVar2 = (longlong *)*param_3;
    plVar3 = (longlong *)param_3[0xc];
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x20))(plVar3,plVar3 != param_3 + 5);
      param_3[0xc] = 0;
    }
    thunk_FUN_1400c9460(param_3);
    param_3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  return;
}



// ===== [callee-of-3570] FUN_1400014a0 @ 1400014a0 =====

void FUN_1400014a0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_1400bb16c(0x1400ddb58);
}



// ===== [callee-of-3570] __security_check_cookie @ 1400bb1b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_1400e2040) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_1400bb204();
  return;
}



// ===== [callee-of-3570] FUN_1400bb470 @ 1400bb470 =====

void FUN_1400bb470(ulonglong param_1)

{
  code *pcVar1;
  bool bVar2;
  undefined7 extraout_var;
  LPVOID pvVar3;
  
  do {
    pvVar3 = _malloc_base(param_1);
    if (pvVar3 != (LPVOID)0x0) {
      return;
    }
    bVar2 = FUN_1400c76c0(param_1);
  } while ((int)CONCAT71(extraout_var,bVar2) != 0);
  if (param_1 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_1400013e0();
  }
  FUN_1400bba54();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// ===== [callee-of-3570] FUN_140008400 @ 140008400 =====

undefined8 * FUN_140008400(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = &PTR_FUN_1400ddd58;
  return param_2;
}



// ===== [callee-of-3570] FUN_140008600 @ 140008600 =====

longlong * FUN_140008600(longlong *param_1,longlong *param_2,longlong *param_3,ushort *param_4)

{
  char cVar1;
  ushort uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  ushort uVar7;
  uint uStack_20;
  undefined4 uStack_1c;
  
  plVar3 = (longlong *)*param_1;
  if (*(char *)((longlong)param_3 + 0x19) == '\0') {
    uVar7 = *param_4;
    uVar2 = *(ushort *)(param_3 + 4);
    if (param_3 == (longlong *)*plVar3) {
      if (uVar7 < uVar2) {
        *param_2 = (longlong)param_3;
        *(undefined4 *)(param_2 + 1) = 1;
        *(undefined1 *)(param_2 + 2) = 0;
        return param_2;
      }
      goto LAB_140008795;
    }
    if (uVar7 < uVar2) {
      plVar4 = (longlong *)*param_3;
      if (*(char *)((longlong)plVar4 + 0x19) == '\0') {
        cVar1 = *(char *)(plVar4[2] + 0x19);
        plVar6 = (longlong *)plVar4[2];
        while (plVar5 = plVar6, cVar1 == '\0') {
          plVar6 = (longlong *)plVar5[2];
          cVar1 = *(char *)((longlong)plVar6 + 0x19);
          plVar4 = plVar5;
        }
      }
      else {
        cVar1 = *(char *)(param_3[1] + 0x19);
        plVar5 = (longlong *)param_3[1];
        plVar6 = param_3;
        while ((plVar4 = plVar5, cVar1 == '\0' && (plVar6 == (longlong *)*plVar4))) {
          cVar1 = *(char *)(plVar4[1] + 0x19);
          plVar5 = (longlong *)plVar4[1];
          plVar6 = plVar4;
        }
        if (*(char *)((longlong)plVar6 + 0x19) != '\0') {
          plVar4 = plVar6;
        }
      }
      if (*(ushort *)(plVar4 + 4) < uVar7) {
        cVar1 = *(char *)(plVar4[2] + 0x19);
        *(undefined1 *)(param_2 + 2) = 0;
        if (cVar1 == '\0') {
          *param_2 = (longlong)param_3;
          *(undefined4 *)(param_2 + 1) = 1;
          return param_2;
        }
        *param_2 = (longlong)plVar4;
        *(undefined4 *)(param_2 + 1) = 0;
        return param_2;
      }
      goto LAB_140008795;
    }
    if (uVar7 <= uVar2) {
      *(undefined4 *)(param_2 + 1) = 0;
      *param_2 = (longlong)param_3;
      *(undefined1 *)(param_2 + 2) = 1;
      return param_2;
    }
    plVar4 = (longlong *)param_3[2];
    if (*(char *)((longlong)plVar4 + 0x19) == '\0') {
      cVar1 = *(char *)(*plVar4 + 0x19);
      plVar6 = (longlong *)*plVar4;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*plVar6 + 0x19);
        plVar4 = plVar6;
        plVar6 = (longlong *)*plVar6;
      }
    }
    else {
      plVar6 = (longlong *)param_3[1];
      plVar5 = param_3;
      plVar4 = plVar6;
      if (*(char *)((longlong)plVar6 + 0x19) != '\0') goto LAB_14000881f;
      do {
        plVar4 = plVar6;
        if (plVar5 != (longlong *)plVar6[2]) break;
        plVar4 = (longlong *)plVar6[1];
        plVar5 = plVar6;
        plVar6 = plVar4;
      } while (*(char *)((longlong)plVar4 + 0x19) == '\0');
    }
    if ((*(char *)((longlong)plVar4 + 0x19) != '\0') || (uVar7 < *(ushort *)(plVar4 + 4))) {
LAB_14000881f:
      cVar1 = *(char *)(param_3[2] + 0x19);
      *(undefined1 *)(param_2 + 2) = 0;
      if (cVar1 == '\0') {
        *param_2 = (longlong)plVar4;
        *(undefined4 *)(param_2 + 1) = 1;
        return param_2;
      }
      *param_2 = (longlong)param_3;
      *(undefined4 *)(param_2 + 1) = 0;
      return param_2;
    }
  }
  else if ((*(char *)(plVar3[1] + 0x19) != '\0') ||
          (uVar7 = *param_4, *(ushort *)(plVar3[2] + 0x20) < uVar7)) {
    *param_2 = plVar3[2];
    *(undefined1 *)(param_2 + 2) = 0;
    *(undefined4 *)(param_2 + 1) = 0;
    return param_2;
  }
LAB_140008795:
  plVar4 = (longlong *)plVar3[1];
  uStack_20 = 0;
  cVar1 = *(char *)((longlong)plVar4 + 0x19);
  plVar6 = plVar4;
  while (plVar5 = plVar4, cVar1 == '\0') {
    plVar4 = plVar5;
    plVar6 = plVar5;
    if (uVar7 > *(ushort *)(plVar5 + 4)) {
      plVar4 = plVar5 + 2;
      plVar6 = plVar3;
    }
    uStack_20 = (uint)(uVar7 <= *(ushort *)(plVar5 + 4));
    cVar1 = *(char *)(*plVar4 + 0x19);
    plVar3 = plVar6;
    plVar4 = (longlong *)*plVar4;
    plVar6 = plVar5;
  }
  if ((*(char *)((longlong)plVar3 + 0x19) == '\0') && (*(ushort *)(plVar3 + 4) <= *param_4)) {
    *param_2 = (longlong)plVar3;
    *(undefined4 *)(param_2 + 1) = 2;
    *(undefined1 *)(param_2 + 2) = 1;
    return param_2;
  }
  *(undefined1 *)(param_2 + 2) = 0;
  *param_2 = (longlong)plVar6;
  param_2[1] = CONCAT44(uStack_1c,uStack_20);
  return param_2;
}



// ===== [callee-of-3570] thunk_FUN_1400c9460 @ 1400bb7b4 =====

void thunk_FUN_1400c9460(LPVOID param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  uint uVar3;
  __acrt_ptd *p_Var4;
  
  if ((param_1 != (LPVOID)0x0) && (BVar1 = HeapFree(DAT_1400e8e78,0,param_1), BVar1 == 0)) {
    DVar2 = GetLastError();
    uVar3 = FUN_1400c922c(DVar2);
    p_Var4 = FUN_1400c9344();
    *(uint *)p_Var4 = uVar3;
  }
  return;
}



// ===== [callee-of-3570] FUN_140007eb0 @ 140007eb0 =====

longlong * FUN_140007eb0(longlong *param_1,longlong *param_2,longlong *param_3)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  param_1[1] = param_1[1] + 1;
  plVar2 = (longlong *)*param_1;
  plVar7 = (longlong *)*param_2;
  param_3[1] = (longlong)plVar7;
  if (plVar7 == plVar2) {
    *plVar2 = (longlong)param_3;
    plVar2[1] = (longlong)param_3;
    plVar2[2] = (longlong)param_3;
    *(undefined1 *)(param_3 + 3) = 1;
    return param_3;
  }
  if ((int)param_2[1] == 0) {
    plVar7[2] = (longlong)param_3;
    if (plVar7 == (longlong *)plVar2[2]) {
      plVar2[2] = (longlong)param_3;
    }
  }
  else {
    *plVar7 = (longlong)param_3;
    if (plVar7 == (longlong *)*plVar2) {
      *plVar2 = (longlong)param_3;
    }
  }
  cVar1 = *(char *)(param_3[1] + 0x18);
  plVar7 = param_3;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(plVar2[1] + 0x18) = 1;
      return param_3;
    }
    plVar6 = (longlong *)plVar7[1];
    lVar3 = *(longlong *)plVar6[1];
    if (plVar6 == (longlong *)lVar3) {
      lVar3 = ((longlong *)plVar6[1])[2];
      if (*(char *)(lVar3 + 0x18) == '\0') {
        *(undefined1 *)(plVar6 + 3) = 1;
        *(undefined1 *)(lVar3 + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar7[1] + 8) + 0x18) = 0;
        plVar7 = *(longlong **)(plVar7[1] + 8);
      }
      else {
        plVar8 = (longlong *)plVar6[2];
        if (plVar7 == plVar8) {
          plVar6[2] = *plVar8;
          if (*(char *)(*plVar8 + 0x19) == '\0') {
            *(longlong **)(*plVar8 + 8) = plVar6;
          }
          plVar8[1] = plVar6[1];
          if (plVar6 == (longlong *)*(longlong *)(*param_1 + 8)) {
            *(longlong **)(*param_1 + 8) = plVar8;
          }
          else {
            plVar7 = (longlong *)plVar6[1];
            if (plVar6 == (longlong *)*plVar7) {
              *plVar7 = (longlong)plVar8;
            }
            else {
              plVar7[2] = (longlong)plVar8;
            }
          }
          *plVar8 = (longlong)plVar6;
          plVar6[1] = (longlong)plVar8;
          plVar7 = plVar6;
        }
        *(undefined1 *)(plVar7[1] + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar7[1] + 8) + 0x18) = 0;
        plVar6 = *(longlong **)(plVar7[1] + 8);
        plVar8 = (longlong *)*plVar6;
        *plVar6 = plVar8[2];
        if (*(char *)(plVar8[2] + 0x19) == '\0') {
          *(longlong **)(plVar8[2] + 8) = plVar6;
        }
        plVar8[1] = plVar6[1];
        if (plVar6 == *(longlong **)(*param_1 + 8)) {
          *(longlong **)(*param_1 + 8) = plVar8;
          plVar8[2] = (longlong)plVar6;
        }
        else {
          plVar4 = (longlong *)plVar6[1];
          if (plVar6 == (longlong *)plVar4[2]) {
            plVar4[2] = (longlong)plVar8;
            plVar8[2] = (longlong)plVar6;
          }
          else {
            *plVar4 = (longlong)plVar8;
            plVar8[2] = (longlong)plVar6;
          }
        }
LAB_1400080ed:
        plVar6[1] = (longlong)plVar8;
      }
    }
    else {
      if (*(char *)(lVar3 + 0x18) != '\0') {
        plVar8 = (longlong *)*plVar6;
        if (plVar7 == plVar8) {
          *plVar6 = plVar8[2];
          if (*(char *)(plVar8[2] + 0x19) == '\0') {
            *(longlong **)(plVar8[2] + 8) = plVar6;
          }
          plVar8[1] = plVar6[1];
          if (plVar6 == (longlong *)*(longlong *)(*param_1 + 8)) {
            *(longlong **)(*param_1 + 8) = plVar8;
          }
          else {
            puVar5 = (undefined8 *)plVar6[1];
            if (plVar6 == (longlong *)puVar5[2]) {
              puVar5[2] = plVar8;
            }
            else {
              *puVar5 = plVar8;
            }
          }
          plVar8[2] = (longlong)plVar6;
          plVar6[1] = (longlong)plVar8;
          plVar7 = plVar6;
        }
        *(undefined1 *)(plVar7[1] + 0x18) = 1;
        *(undefined1 *)(*(longlong *)(plVar7[1] + 8) + 0x18) = 0;
        plVar6 = *(longlong **)(plVar7[1] + 8);
        plVar8 = (longlong *)plVar6[2];
        plVar6[2] = *plVar8;
        if (*(char *)(*plVar8 + 0x19) == '\0') {
          *(longlong **)(*plVar8 + 8) = plVar6;
        }
        plVar8[1] = plVar6[1];
        if (plVar6 == *(longlong **)(*param_1 + 8)) {
          *(longlong **)(*param_1 + 8) = plVar8;
        }
        else {
          puVar5 = (undefined8 *)plVar6[1];
          if (plVar6 == (longlong *)*puVar5) {
            *puVar5 = plVar8;
          }
          else {
            puVar5[2] = plVar8;
          }
        }
        *plVar8 = (longlong)plVar6;
        goto LAB_1400080ed;
      }
      *(undefined1 *)(plVar6 + 3) = 1;
      *(undefined1 *)(lVar3 + 0x18) = 1;
      *(undefined1 *)(*(longlong *)(plVar7[1] + 8) + 0x18) = 0;
      plVar7 = *(longlong **)(plVar7[1] + 8);
    }
    cVar1 = *(char *)(plVar7[1] + 0x18);
  } while( true );
}



// ==== functions referencing RTTI 0xe5400-0xe56d0 ====

// ==== callers of interesting imports ====
//   GetModuleFileNameW <- ? (from 1400d5188)
//   GetModuleFileNameW <- FUN_1400c7e44 @ 1400c7e44 (from 1400c7e94)
//   CreateFileW <- ? (from 1400d5010)
//   CreateFileW <- __dcrt_lowio_ensure_console_output_initialized @ 1400d2064 (from 1400d209a)
//   CreateFileW <- __dcrt_write_console @ 1400d20d4 (from 1400d2154)
//   ReadFile: symbol not found
//   SetFilePointerEx <- ? (from 1400d5068)
//   SetFilePointerEx <- FUN_1400d15e8 @ 1400d15e8 (from 1400d163a)
//   SetFilePointer: symbol not found
//   GetFileSize: symbol not found
//   MapViewOfFile: symbol not found
//   CreateFileMappingW: symbol not found
//   TrySubmitThreadpoolCallback: symbol not found
//   CryptDecrypt: symbol not found
//   CryptAcquireContextW: symbol not found
//   BCryptOpenAlgorithmProvider: symbol not found
//   WinVerifyTrust: symbol not found
//   CryptDecodeObjectEx: symbol not found
//   CertCreateCertificateContext: symbol not found
//   CryptHashData: symbol not found
//   GetModuleFileNameA: symbol not found
//   LoadResource: symbol not found
//   FindResourceW: symbol not found
//   VirtualAlloc: symbol not found
