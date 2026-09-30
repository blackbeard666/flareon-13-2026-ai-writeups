// ==== FUN_1400711e0 size=453

undefined8 FUN_1400711e0(int param_1)

{
  undefined8 in_RAX;
  ulonglong uVar1;
  undefined7 uVar2;
  
  uVar2 = (undefined7)((ulonglong)in_RAX >> 8);
  uVar1 = CONCAT71(uVar2,1);
  if (param_1 < 0x461) {
    if (param_1 < 0x150) {
      switch(param_1) {
      case 2:
      case 3:
      case 0xf:
      case 0x35:
      case 0x43:
        return 0;
      case 5:
switchD_140071213_caseD_5:
        return uVar1;
      case 8:
      case 0xe:
        return CONCAT71(uVar2,0x26);
      case 0x11:
        return CONCAT71(uVar2,0x1f);
      case 0x13:
        return CONCAT71(uVar2,0x11);
      case 0x27:
      case 0x70:
        return CONCAT71(uVar2,0x18);
      case 0x50:
      case 0xb7:
        return CONCAT71(uVar2,0xc);
      case 0x57:
switchD_140071213_caseD_57:
        return CONCAT71(uVar2,0x14);
      case 0x6d:
      case 0xe8:
        return CONCAT71(uVar2,0xb);
      case 0x78:
        return CONCAT71(uVar2,0x24);
      case 0x79:
      case 0x102:
        goto switchD_140071213_caseD_79;
      case 0x7b:
      case 0xa1:
      case 0xce:
        return CONCAT71(uVar2,0x21);
      case 0x84:
        return CONCAT71(uVar2,0x19);
      case 0x91:
        return CONCAT71(uVar2,0x10);
      case 0xaa:
        return CONCAT71(uVar2,0x1c);
      case 0xdf:
        return CONCAT71(uVar2,0x1b);
      case 0x10b:
        return CONCAT71(uVar2,0xe);
      }
    }
    else if (param_1 < 0x3e3) {
      if (param_1 == 0x150) {
        return CONCAT71(uVar2,0xf);
      }
      if (param_1 == 0x252) goto switchD_140071213_caseD_79;
    }
    else if ((param_1 == 0x3e3) || (param_1 == 0x41d)) goto switchD_140071213_caseD_79;
  }
  else if (param_1 < 0x271d) {
    if (param_1 < 0x781) {
      if (param_1 < 0x4cf) {
        if (param_1 == 0x461) goto switchD_140071213_caseD_79;
        if (param_1 == 0x46b) {
          return CONCAT71(uVar2,0x1e);
        }
        if (param_1 == 0x476) {
          return CONCAT71(uVar2,0x20);
        }
      }
      else if (param_1 < 0x50f) {
        if (param_1 == 0x4cf) goto switchD_14007123d_caseD_2743;
        if (param_1 == 0x4d0) goto switchD_14007123d_caseD_2751;
      }
      else {
        if (param_1 == 0x50f) goto switchD_14007123d_caseD_2755;
        if (param_1 == 0x5b4) goto switchD_140071213_caseD_79;
      }
    }
    else if (param_1 < 0x1b80) {
      if (param_1 == 0x781) {
        return CONCAT71(uVar2,0x12);
      }
      if ((param_1 == 0x1716) || (param_1 == 0x1b64)) goto switchD_140071213_caseD_79;
    }
    else if (param_1 < 0x2022) {
      if ((param_1 == 0x1b80) || (param_1 == 0x1f4e)) goto switchD_140071213_caseD_79;
    }
    else if ((param_1 == 0x2022) || (param_1 == 0x25e9)) goto switchD_140071213_caseD_79;
  }
  else {
    switch(param_1) {
    case 0x271d:
      goto switchD_140071213_caseD_5;
    case 0x271e:
    case 0x271f:
    case 0x2720:
    case 0x2721:
    case 0x2722:
    case 0x2723:
    case 0x2724:
    case 0x2725:
    case 0x2727:
    case 0x2728:
    case 0x2729:
    case 0x272a:
    case 0x272b:
    case 0x272c:
    case 0x272d:
    case 0x272e:
    case 0x272f:
    case 0x2730:
    case 0x2731:
    case 0x2732:
    case 0x2734:
    case 0x2735:
    case 0x2736:
    case 0x2737:
    case 0x2738:
    case 0x2739:
    case 0x273a:
    case 0x273b:
    case 0x273c:
    case 0x273d:
    case 0x273e:
    case 0x273f:
    case 0x2744:
    case 0x2747:
    case 0x2748:
    case 0x274a:
    case 0x274b:
    case 0x274e:
    case 0x274f:
    case 0x2750:
    case 0x2752:
    case 0x2753:
    case 0x2754:
      break;
    case 0x2726:
      goto switchD_140071213_caseD_57;
    case 0x2733:
      return CONCAT71(uVar2,0xd);
    case 0x2740:
      return CONCAT71(uVar2,8);
    case 0x2741:
      return CONCAT71(uVar2,9);
    case 0x2742:
      return CONCAT71(uVar2,10);
    case 0x2743:
switchD_14007123d_caseD_2743:
      return CONCAT71(uVar2,5);
    case 0x2745:
      return CONCAT71(uVar2,6);
    case 0x2746:
      return CONCAT71(uVar2,3);
    case 0x2749:
      return CONCAT71(uVar2,7);
    case 0x274c:
switchD_140071213_caseD_79:
      return CONCAT71((int7)(uVar1 >> 8),0x16);
    case 0x274d:
      return CONCAT71(uVar2,2);
    case 0x2751:
switchD_14007123d_caseD_2751:
      return CONCAT71(uVar2,4);
    case 0x2755:
switchD_14007123d_caseD_2755:
      return CONCAT71(uVar2,0x1a);
    default:
      uVar1 = (ulonglong)(param_1 - 0x3c2aU);
      if ((param_1 - 0x3c2aU < 2) || (param_1 == 0x35ed)) goto switchD_140071213_caseD_79;
    }
  }
  return CONCAT71((int7)(uVar1 >> 8),0x29);
}


// ==== FUN_14006f3a0 size=60

undefined8 FUN_14006f3a0(undefined4 param_1,undefined8 param_2)

{
  HANDLE pvVar1;
  undefined8 uVar2;
  
  pvVar1 = GetProcessHeap();
  if (pvVar1 != (HANDLE)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00014006f3cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = HeapAlloc(pvVar1,param_1,param_2);
    return uVar2;
  }
  return 0;
}


// ==== FUN_14006a600 size=117

ulonglong FUN_14006a600(undefined8 param_1,ushort *param_2,ulonglong param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 local_20;
  ulonglong local_18 [2];
  
  local_18[1] = 0xfffffffffffffffe;
  local_18[0] = 0;
  local_20 = param_1;
  uVar2 = FUN_140006460(&local_20,0x1400f5780,param_2,param_3);
  if ((char)uVar2 == '\0') {
    if (local_18[0] != 0) {
      FUN_14006a7d0(local_18);
    }
    local_18[0] = 0;
  }
  else if (local_18[0] == 0) {
    FUN_1400c3bc0("a formatting trait implementation returned an error when the underlying stream did not"
                  ,0xad,&PTR_s__rustc_ac68faa20c58cbccd01ee7208_1400f8070);
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  return local_18[0];
}


