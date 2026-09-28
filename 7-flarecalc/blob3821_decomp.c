
// ===== FUN_140003234 @ 140003234 size~1101 =====

undefined4 FUN_140003234(undefined8 *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 local_a8;
  uint local_94;
  longlong local_88;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  undefined8 local_50;
  longlong local_48;
  int *local_40;
  int local_38;
  undefined8 local_18;
  
  local_88 = 0;
  local_70 = (code *)0x0;
  local_78 = (code *)0x0;
  local_68 = (code *)0x0;
  local_60 = (code *)0x0;
  local_58 = (code *)0x0;
  local_18 = 0;
  FUN_14000a9e8(&local_40,0,0x28);
  lVar4 = FUN_140006950(param_2 + 0x8c917caa5ff8ffd9U ^ 0xabcdf01234566f80,param_2);
  local_50 = FUN_140006950(param_2 + 0x995eeca8e69ae856U ^ 0xbe02468acf134e70,param_2);
  if (lVar4 == 0) {
    local_a8 = 0x32;
  }
  else {
    uVar1 = FUN_140006ab0(lVar4,param_2 + 0xadede5e371e6f8a9U ^ 0xe26af37c048d0c50,&local_70,param_2
                         );
    if ((ulonglong)uVar1 == (param_2 + 0x88ea12d31383b920U ^ 0x88ea12d31383b920)) {
      uVar1 = FUN_140006ab0(lVar4,param_2 + 0x642b66032d268f5U ^ 0x6d3a06d3a06ca30,&local_58,param_2
                           );
      if ((ulonglong)uVar1 == (param_2 + 0x81f2b09ae8017e0U ^ 0x81f2b09ae8017e0)) {
        uVar1 = FUN_140006ab0(lVar4,param_2 + 0x68b702e4da7af4eaU ^ 0x2b3c4d5e6f808810,&local_78,
                              param_2);
        if ((ulonglong)uVar1 == (param_2 + 0x87544340497c76a0U ^ 0x87544340497c76a0)) {
          uVar1 = FUN_140006ab0(local_50,param_2 + 0x23fda15923d606U ^ 0x4fa4fa4fa4fa45f0,&local_68,
                                param_2);
          if ((ulonglong)uVar1 == (param_2 + 0x6895b76e478d560U ^ 0x6895b76e478d560)) {
            uVar1 = FUN_140006ab0(lVar4,param_2 + 0x749cb14dd084659bU ^ 0x740da740da7403d0,&local_60
                                  ,param_2);
            if ((ulonglong)uVar1 == (param_2 + 0x85be73ad7f753420U ^ 0x85be73ad7f753420)) {
              uVar1 = (*local_78)(0,0);
              if (uVar1 == 0) {
                local_a8 = 8;
              }
              else {
                local_48 = (ulonglong)uVar1 << 3;
                uVar5 = (*local_70)();
                local_88 = (*local_68)(uVar5,0,local_48);
                if (local_88 == 0) {
                  local_a8 = 8;
                }
                else {
                  uVar2 = (*local_78)(uVar1,local_88);
                  if (uVar2 == 0) {
                    local_a8 = 8;
                  }
                  else if (uVar1 < uVar2) {
                    local_a8 = 0xaa;
                  }
                  else {
                    for (local_94 = 0; local_94 < uVar2; local_94 = local_94 + 1) {
                      local_40 = (int *)0x0;
                      while (iVar3 = (*local_60)(*(undefined8 *)(local_88 + (ulonglong)local_94 * 8)
                                                 ,&local_40), iVar3 != 0) {
                        if ((local_38 == 0x4ff) && (*local_40 == 0x52414c46)) {
                          *param_1 = local_40;
                          local_a8 = 0;
                          goto LAB_140003690;
                        }
                      }
                    }
                    local_a8 = 0x490;
                  }
                }
              }
            }
            else {
              local_a8 = 0x32;
            }
          }
          else {
            local_a8 = 0x32;
          }
        }
        else {
          local_a8 = 0x32;
        }
      }
      else {
        local_a8 = 0x32;
      }
    }
    else {
      local_a8 = 0x32;
    }
  }
LAB_140003690:
  if (local_88 != 0) {
    uVar5 = (*local_70)();
    (*local_58)(uVar5,0,local_88);
  }
  return local_a8;
}



// ===== FUN_140005b78 @ 140005b78 size~476 =====

ulonglong FUN_140005b78(longlong param_1,ulonglong param_2)

{
  char local_28;
  ulonglong local_20;
  ulonglong local_10;
  
  local_20 = 0;
  if (param_1 != 0) {
    for (local_10 = 0; local_10 < param_2; local_10 = local_10 + 1) {
      local_28 = *(char *)(param_1 + local_10);
      if (('`' < local_28) && (local_28 < '{')) {
        local_28 = local_28 + -0x20;
      }
      local_20 = (local_20 << 7 | local_20 >> 0x39) + (longlong)local_28;
    }
    local_20 = local_20 & 0x7fffffffffffffff;
  }
  return local_20;
}



// ===== FUN_1400068ec @ 1400068ec size~100 =====

undefined8 FUN_1400068ec(longlong param_1)

{
  longlong unaff_GS_OFFSET;
  
  return *(undefined8 *)
          (*(longlong *)(unaff_GS_OFFSET + (param_1 + 0x2cc6ee659182dcf0U ^ 0x2cc6ee659182dcc0)) +
          (ulonglong)((int)param_1 + 0xdf010c40U ^ 0xdf010c20));
}



// ===== FUN_140006950 @ 140006950 size~349 =====

undefined8 FUN_140006950(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *local_48;
  
  lVar1 = FUN_1400068ec(param_2);
  if (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + (ulonglong)((int)param_2 + 0x22d57d38U ^ 0x22d57d20));
    if ((lVar1 != 0) &&
       (puVar2 = (undefined8 *)(lVar1 + (ulonglong)((int)param_2 + 0xb500b60U ^ 0xb500b40)),
       puVar2 != (undefined8 *)0x0)) {
      for (local_48 = (undefined8 *)*puVar2; local_48 != puVar2; local_48 = (undefined8 *)*local_48)
      {
        lVar1 = FUN_140005b78(local_48[10],*(undefined2 *)(local_48 + 9));
        if (param_1 == lVar1) {
          return local_48[4];
        }
      }
    }
  }
  return 0;
}



// ===== FUN_140006ab0 @ 140006ab0 size~347 =====

uint FUN_140006ab0(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  undefined8 local_10 [2];
  
  iVar1 = (int)param_4;
  if (param_3 == 0) {
    uVar2 = iVar1 + 0xbb15f717U ^ 0xbb15f740;
  }
  else {
    uVar2 = FUN_14000b028(param_1,iVar1 + 0xf10eb4c0U ^ 0xf10eb4c0,local_10,param_4,
                          iVar1 + 0xd29b6db0U ^ 0xd29b6920);
    if (uVar2 == (iVar1 + 0x27077240U ^ 0x27077240)) {
      uVar2 = FUN_140006c14(param_1,local_10[0],param_2,param_3);
      if (uVar2 == 0) {
        uVar2 = iVar1 + 0xc8f1aac0U ^ 0xc8f1aac0;
      }
      else {
        uVar2 = (uVar2 ^ 0xe0771ca0) + iVar1 ^ 0xe0771ca0;
      }
    }
  }
  return uVar2;
}



// ===== FUN_140006c14 @ 140006c14 size~469 =====

undefined4 FUN_140006c14(longlong param_1,longlong param_2,ulonglong param_3,longlong *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint local_38;
  undefined4 local_34;
  uint local_30;
  uint *local_28;
  ushort *local_20;
  
  local_38 = 0xffffffff;
  if (*(int *)(param_2 + 0x14) == 0) {
    local_34 = 0xb;
  }
  else {
    if ((param_3 & 0x8000000000000000) == 0) {
      if (*(int *)(param_2 + 0x18) == 0) {
        return 0xb;
      }
      local_30 = 0;
      local_28 = (uint *)(param_1 + (ulonglong)*(uint *)(param_2 + 0x20));
      local_20 = (ushort *)(param_1 + (ulonglong)*(uint *)(param_2 + 0x24));
      for (; local_30 < *(uint *)(param_2 + 0x18); local_30 = local_30 + 1) {
        uVar1 = *local_28;
        uVar2 = FUN_14000aad4(param_1 + (ulonglong)uVar1,0x40);
        uVar3 = FUN_140005b78(param_1 + (ulonglong)uVar1,uVar2);
        if (param_3 == uVar3) {
          local_38 = (uint)*local_20;
          break;
        }
        local_28 = local_28 + 1;
        local_20 = local_20 + 1;
      }
    }
    else {
      if ((uint)(ushort)param_3 < *(uint *)(param_2 + 0x10)) {
        return 0xb;
      }
      local_38 = (uint)(ushort)param_3 - *(int *)(param_2 + 0x10);
    }
    if ((local_38 == 0xffffffff) || (*(uint *)(param_2 + 0x14) <= local_38)) {
      local_34 = 0x490;
    }
    else {
      *param_4 = param_1 + (ulonglong)
                           *(uint *)(param_1 + (ulonglong)*(uint *)(param_2 + 0x1c) +
                                    (ulonglong)local_38 * 4);
      local_34 = 0;
    }
  }
  return local_34;
}



// ===== FUN_14000a9e8 @ 14000a9e8 size~91 =====

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



// ===== FUN_14000aad4 @ 14000aad4 size~104 =====

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



// ===== FUN_14000ae9c @ 14000ae9c size~376 =====

uint FUN_14000ae9c(ushort *param_1,undefined8 *param_2,longlong param_3)

{
  int iVar1;
  uint local_18;
  
  iVar1 = (int)param_3;
  if (param_1 == (ushort *)0x0) {
    local_18 = iVar1 + 0x5b59e2b7U ^ 0x5b59e2e0;
  }
  else if (param_2 == (undefined8 *)0x0) {
    local_18 = iVar1 + 0xa8d81217U ^ 0xa8d81240;
  }
  else if ((ulonglong)*param_1 == (param_3 + 0xf67d228f43d42b4dU ^ 0xf67d228f43d47100)) {
    if ((ulonglong)*(uint *)((longlong)param_1 + (longlong)*(int *)(param_1 + 0x1e)) ==
        (param_3 + 0x741c6b3314c9c810U ^ 0x741c6b3314c98d40)) {
      *param_2 = (uint *)((longlong)param_1 + (longlong)*(int *)(param_1 + 0x1e));
      local_18 = iVar1 + 0xe5bea980U ^ 0xe5bea980;
    }
    else {
      local_18 = iVar1 + 0xafc5ec0bU ^ 0xafc5ec00;
    }
  }
  else {
    local_18 = iVar1 + 0xded0cfcbU ^ 0xded0cfc0;
  }
  return local_18;
}



// ===== FUN_14000b028 @ 14000b028 size~383 =====

uint FUN_14000b028(longlong param_1,uint param_2,longlong *param_3,undefined8 param_4)

{
  uint *puVar1;
  int iVar2;
  uint local_28;
  longlong local_18 [3];
  
  iVar2 = (int)param_4;
  if ((param_1 == 0) || (param_3 != (longlong *)0x0)) {
    local_28 = FUN_14000ae9c(param_1,local_18,param_4);
    if (local_28 == (iVar2 + 0x41188c60U ^ 0x41188c60)) {
      if (param_2 < *(uint *)(local_18[0] + 0x84)) {
        puVar1 = (uint *)(local_18[0] + 0x88 + (ulonglong)param_2 * 8);
        if (((puVar1 == (uint *)0x0) || (puVar1[1] == 0)) || (*puVar1 == 0)) {
          local_28 = iVar2 + 0x3080f0d0U ^ 0x3080f440;
        }
        else {
          *param_3 = param_1 + (ulonglong)*puVar1;
          local_28 = iVar2 + 0xb3f7e120U ^ 0xb3f7e120;
        }
      }
      else {
        local_28 = iVar2 + 0xc48f789aU ^ 0xc48f7940;
      }
    }
  }
  else {
    local_28 = iVar2 + 0xb1fceb7U ^ 0xb1fcee0;
  }
  return local_28;
}


